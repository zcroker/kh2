#include "../common/types.h"

#define QCOPY298(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV298 {
    f32 x, y, z, w;
    QV298() {}
    QV298(const QV298& o) { QCOPY298(this, &o); }
    QV298& operator=(const QV298& o) { if (this != &o) QCOPY298(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Act5cf8 { void** vt; };
struct O5cf8 { s32 f0; u8* p4; s32 f8; };
static inline QV298 operator-(const QV298& a, const QV298& b) {
    QV298 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vlen298(const QV298* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct Rng8cb { u8 pad[12]; s16 lo; s16 hi; };
struct O8cb { u8 pad[20]; u8* p20; u8 pad2[4]; u8* p28; Rng8cb* p32; u8 pad3[2]; u8 b38; u8 b39; };
extern u8* D_00352130;
extern u32 D_003638d0;
void func_0018cd28(struct O8cb*, f32*, f32*);
extern "C" {
f32 func_0017ce10(f32);
s32 func_0022a3d0(s32 n, f32 x, s32* a, s32* b, s32* c, s32* d, s32* e, s32* f, s32* g, s32* h, f32* out);  // 0022a3d0: moved to src/sasa/musical_input.cpp (linked unit)

s32 func_0016a070(u8*);
QV298* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_001703a8(s32);
void func_001afb80(void*, s32, s32, s32);
void func_0016ed50(s32, s32, s32);
void func_00170888(void*);
void func_001c9e50(void*);
s32 func_0017e4f8(s32, QV298*, f32, f32, f32);
void func_001617d8(void);
void func_001ad990(u8*, f32, f32, f32);
s32 func_001ba028(u8*);  // list_contains_ptr
void func_00102448(void*, s32);
s32 func_001b5cf8(O5cf8* o, void* a1);  // 0x001b5cf8: definition moved into src/anon/unit_001b2780.cpp

s32 func_0018ca48(u8);
QV298* func_0016c028(u8*);  // obj_get_attach_or_alt
}
