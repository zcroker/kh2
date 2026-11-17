#include "../common/types.h"

union W248Cam { u8* p; f32 f; };
extern "C" {
extern W248Cam D_01d9e6e8;
void func_0021eb50(void*, void*);
void func_0021ebe8(void*, void*);
void func_0021ec80(void*, void*);
}
static inline void W248Scale(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
struct W248V4 {
    f32 x, y, z, w;
    W248V4() {}
    W248V4(const W248V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W248Mv { u8 pad[16]; f32 f10, f14; u8 pad2[4]; f32 f1c; u8 pad3[0xb90 - 0x20]; f32 kx, limx, ky, limy; };
static inline f32 W248Clamp(f32 v, f32 lim) {
    f32 lo = -lim;
    if (v < lo) return lo;
    if (lim < v) return lim;
    return v;
}
struct W248Tbl { u8 pad[18]; u8 n; u8 pad2[33]; u16 a[16]; u16 b[80]; };

extern "C" {
void func_001eaa58(u8* o, u32 a1, u8* x);  // 0x001eaa58: definition moved into src/anon/unit_001e8ac8.cpp
void func_001eab40(u8* o, u32 a1, u8* x);  // 0x001eab40: definition moved into src/anon/unit_001e8ac8.cpp
void func_001f0dc0(u8* o, u32 a1, u8* x);  // 0x001f0dc0: definition moved into src/anon/unit_001f0cd8.cpp
void func_001f0ea8(u8* o, u32 a1, u8* x);  // 0x001f0ea8: definition moved into src/anon/unit_001f0cd8.cpp

extern u8 D_0032e020[];
W248Tbl* func_00188fe0(void*);
u8* func_001a80c8(u32);  // table24_find_by_id
s32 func_001a3570(u32);
// 001a35f8: moved to src/anon/unit_001a2a50.cpp

extern f32 D_00349e10;
W248V4* func_0016b0a0(W248Mv*);
void func_0016b070(W248Mv*, W248V4*);
void func_001cfaf0(void* self, W248Mv* m);  // 0x001cfaf0: definition moved into src/anon/unit_001cf0b0.cpp
}
