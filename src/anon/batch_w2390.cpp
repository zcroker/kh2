#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Key { QWord h; QWord s; QWord r; QWord t; };
struct Src;
struct SrcVT { u8 pad[0x20]; Key* (*get)(Src*); };
struct Src { SrcVT* vt; };
struct Pose { u8 pad[0x14]; Src* src; u8 pad2[4]; QWord* s; QWord* r; QWord* t; };
struct Chan { u16 bone; u16 ch; f32 val; };
struct Hdr { u8 pad[0x10]; u16 n; u8 pad2[0x24 - 0x12]; s32 off; s32 cnt; };
struct Self { u8 pad[4]; Hdr* hdr; };
// Element j of bone b's channel vector, addressed as bytes.
static inline void set(QWord* a, u16 b, s32 j, f32 v) { *(f32*)((u32)a + (b << 4) + (j << 2)) = v; }
extern "C" {
// 00128480: copies the pose keys (scale/rotation/translation per bone) from the source, then applies
// per-channel overrides (channel 0-2 scale, 3-5 rotation, 6-8 translation xyz).
void func_00128480(Self* self, Pose* p) {
    Hdr* h = self->hdr;
    s32 n = h->n;
    Key* k = p->src->vt->get(p->src);
    s32 i;
    for (i = 0; i < n; i++, k++) {
        p->s[i] = k->s;
        p->r[i] = k->r;
        p->t[i] = k->t;
    }
    n = h->cnt;
    if (n == 0) return;
    Chan* c = (Chan*)((u8*)h + h->off);
    for (i = 0; i < n; i++, c++) {
        switch (c->ch) {
        case 0: case 1: case 2:
            set(p->s, c->bone, c->ch, c->val);
            break;
        case 3: case 4: case 5:
            set(p->r, c->bone, c->ch - 3, c->val);
            break;
        case 6: case 7: case 8:
            set(p->t, c->bone, c->ch - 6, c->val);
            break;
        }
    }
}
}
