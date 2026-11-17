// Linked unit 0x002090c0-0x00209328 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
typedef f32 FMTX65b[4][4] __attribute__((aligned(16)));
typedef f32 FMTX206[4][4] __attribute__((aligned(16)));
typedef f32 FMTX208[4][4] __attribute__((aligned(16)));

// 002090c0 (was gap, written for the unit)
namespace n002090c0 {
typedef unsigned int u128g __attribute__((mode(TI)));
struct EmH { u128g v; u8* parts; u8* p20; u8* p24; s32 count; u16 h32; u16 h34; };
void func_002090c0(u8* base, u8* c) asm("func_002090c0");
void func_002090c0(u8* base, u8* c) {
    u8* b = base + (*(s32**)(c + 12))[2];
    *(u128g*)(b + 160) = 0;
    EmH* e = (EmH*)(b + 160);
    e->parts = 0;
    e->p20 = 0;
    e->p24 = 0;
    e->count = 0;
    e->h32 = 0;
    e->h34 = 0;
}
}  // namespace n002090c0

// 002090f8 (was src/anon/auto80_199_queue.cpp)
namespace n002090f8 {
/*TARGET 002090f8*/
void func_002090f8(u32 a0, u32 a1) asm("_Z13func_002090f8jj");
void func_002090f8(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6 + 160;

    u32 p0 = *(u32*)(s0 + 16);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 16) = 0;
    }

    u32 p1 = *(u32*)(s0 + 20);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s0 + 20) = 0;
    }

    u32 p2 = *(u32*)(s0 + 24);
    if (p2 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p2);
        *(u32*)(s0 + 24) = 0;
    }
}
}  // namespace n002090f8

// 00209178 (was src/anon/batch_w274.cpp)
namespace n00209178 {
struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
static inline V4 operator*(const M4& m, const V4& v) {
    V4 r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)" : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
/*TARGET 00209178*/
void func_00209178(u8* a0, f32* m) asm("func_00209178");
void func_00209178(u8* a0, f32* m) {
    f32 w, h, b;
    switch (a0[49]) { case 1: w = 0.48999998f; break; case 2: w = 0.24f; break; case 0: default: w = 0.98999995f; break; }
    switch (a0[50]) { case 1: h = 0.48999998f; break; case 2: h = 0.24f; break; case 0: default: h = 0.98999995f; break; }
    switch (a0[51]) { case 1: b = 0.25f; break; case 2: b = 0.5f; break; case 3: b = 0.75f; break; case 0: default: b = 0.0f; break; }
    f32 x1 = b + w;
    f32 y0 = 0.01f;
    f32 x0 = b + y0;
    f32 z = 1.0f;
    m[0] = m[4] = m[24] = m[28] = x0;
    m[8] = m[12] = m[16] = m[20] = x1;
    m[5] = m[13] = m[21] = m[29] = h;
    m[1] = m[9] = m[17] = m[25] = y0;
    m[2] = m[6] = m[10] = m[14] = m[18] = m[22] = m[26] = m[30] = z;
}
}  // namespace n00209178

// 002092e0 (was src/anon/batch_w35.cpp)
namespace n002092e0 {
// 0x001e2c00: definition moved into src/anon/unit_001e0cb8.cpp

u8 func_00209178(void*, void*) asm("func_00209178");
/*TARGET 002092e0*/
void func_002092e0(u8* a, u32* b, u8* c) asm("func_002092e0");
void func_002092e0(u8* a, u32* b, u8* c) {
    u8* t = a + *(s32*)(*(u8**)(c + 12) + 8) + 160;
    if (*b == *(u32*)(a + 12)) {
        struct NoTail { ~NoTail() {} } g; // keeps the call a jal
        func_00209178(b, t);
    }
}
}  // namespace n002092e0

