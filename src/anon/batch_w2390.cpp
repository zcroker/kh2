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
void func_00128480(Self* self, Pose* p);  // 0x00128480: definition moved into src/anon/unit_00128480.cpp
}
