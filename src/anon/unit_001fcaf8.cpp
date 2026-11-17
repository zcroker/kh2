// Linked unit 0x001fcaf8-0x001fcd70 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>

// 001fcaf8 (was gap)
namespace n001fcaf8 {
void func_001fcaf8(u8* a0, u8* t) asm("func_001fcaf8");
void func_001fcaf8(u8* a0, u8* t) {
    struct S { s32 a, b, c; };
    u8* b = a0 + **(s32**)(t + 12);
    S* s = (S*)(b + 160);
    s->a = 0;
    s->b = 0;
    s->c = 0;
}
}  // namespace n001fcaf8

// 001fcb18 (was src/anon/batch_w46.cpp)
namespace n001fcb18 {
// 001e0750: static initialiser, now made by gcc in src/anon/unit_001e0398.cpp

// ---- 001fcb18
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0MulMatrix(u8*, u8*, u8*) asm("sceVu0MulMatrix");
void sceVu0CopyMatrix(u8*, u8*) asm("sceVu0CopyMatrix");
/*TARGET 001fcb18*/
void func_001fcb18(u8* p, u32, u8* const q) asm("func_001fcb18");
void func_001fcb18(u8* p, u32, u8* const q) {
    u8* s = p + *(u32*)(*(u8**)(q + 12) + 4) + 160;
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e840, D_01d9e6e8 + 16);
    sceVu0CopyMatrix(s, D_01d9e6e8 + 80);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
}  // namespace n001fcb18

// 001fcb90 (was src/anon/batch_w82.cpp)
namespace n001fcb90 {
extern f32 D_00354be0[3] asm("D_00354be0");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
void sceVu0ScaleVector(u8*, u8*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0ApplyMatrix(u8*, u8*, u8*) asm("sceVu0ApplyMatrix");
void sceVu0CopyMatrix(u8*, u8*) asm("sceVu0CopyMatrix");
void sceVu0MulMatrix(u8*, u8*, u8*) asm("sceVu0MulMatrix");
/*TARGET 001fcb90*/
void func_001fcb90(u8* a0, u32, u8* a2) asm("func_001fcb90");
void func_001fcb90(u8* a0, u32, u8* a2)
{
    u8* p = a0 + *(u32*)(*(u8**)(a2 + 12) + 4) + 160;
    sceVu0ScaleVector(D_01d9e6e8 + 80, D_01d9e6e8 + 16, D_00354be0[0]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8 + 96, D_01d9e6e8 + 32, D_00354be0[1]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8 + 112, D_01d9e6e8 + 48, D_00354be0[2]);  // vec_scale_by_f12
    sceVu0ApplyMatrix(D_01d9e6e8 + 128, D_01d9e840, D_01d9e6e8 + 64);
    sceVu0CopyMatrix(p, D_01d9e6e8 + 80);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
}  // namespace n001fcb90


// 001fcc58 (gap, written for the unit)
namespace n001fcc58 {
extern f32* D_01d9e6e8 asm("D_01d9e6e8");
extern f32 D_01dad8d0[] asm("D_01dad8d0");
void func_0021edb0(f32*, u8*) asm("func_0021edb0");
void sceVu0UnitMatrix(f32*) asm("sceVu0UnitMatrix");
void sceVu0CopyVector(f32*, f32*) asm("sceVu0CopyVector");
static inline void ScaleRow(f32* row, f32 s) {
    asm volatile("qmtc2 %2, $vf9\n\tlqc2 $vf10, 0(%1)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(row), "r"(s) : "memory");
}
void func_001fcc58(u8* o, u8* a1, u8* t) asm("func_001fcc58");
void func_001fcc58(u8* o, u8* a1, u8* t) {
    u32* d = *(u32**)(t + 12);
    f32* m = D_01dad8d0;
    u8* p0 = o + d[0];
    u8* p1 = o + d[1];
    u8* p2 = o + d[2];
    f32* tt = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_0021edb0(m, p1 + 160);
    ScaleRow(m, s[0]);
    ScaleRow(m + 4, s[1]);
    ScaleRow(m + 8, s[2]);
    D_01dad8d0[12] = tt[0];
    D_01dad8d0[13] = tt[1];
    D_01dad8d0[14] = tt[2];
    sceVu0UnitMatrix(D_01d9e6e8 + 4);
    D_01d9e6e8[4] = s[0];
    D_01d9e6e8[9] = s[1];
    D_01d9e6e8[14] = s[2];
    sceVu0CopyVector(D_01d9e6e8 + 16, &D_01dad8d0[12]);
}
}  // namespace n001fcc58
