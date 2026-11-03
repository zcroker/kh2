// 00165db8: registers pinned for the +16 copy destination only (gcc ties the c.obj load to it otherwise).
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
struct Ctx { u16 id; QWord* obj; s32 found; };
union PU { s32* p; u16 h; };
union HU { u16 h; s32* p; };
extern "C" {
s32* func_00165ef0(s32*);
s32 func_00142b70(s32);
void func_00141c18(s32, s32, s32, u32, s32);
s32 func_00141ff0(s32, QWord*, QWord*, Ctx*, s32);

s32 func_00165db8(QWord* a0, QWord* out, u16* outId, s32 a3, s32 t0, u8 t1, s32** outP, s32 t3, s32 skip) {
    QWord tmp;
    Ctx c;
    s32* p = 0;
    *(s32* volatile*)outP = 0;
    *(volatile u16*)outId = 0xffff;
    c.id = 0xffff;
    *(QWord* volatile*)&c.obj = a0;
    *(volatile s32*)&c.found = 0;
    while ((p = func_00165ef0(p)) != 0) {
        if (p[0] == skip) continue;
        if (func_00142b70(p[1])) continue;
        func_00141c18(p[1], a3, t0, t1, 0);
        if (func_00141ff0(p[1], c.obj, &tmp, &c, t3)) {
            c.found = 1;
            *out = tmp;
            { register QWord* o asm("$14") = c.obj; register QWord* o1 asm("$15") = o + 1; if (o1 != out) QCOPY(o1, out); }
            ((PU*)outP)->p = p;
            *outId = c.id;
        }
    }
    return c.found;
}
}
