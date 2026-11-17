// Linked unit 0x00209d68-0x0020a090 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 00209d68 (was gap, written for the unit)
namespace n00209d68 {
typedef unsigned int u128g __attribute__((mode(TI)));
void func_00209d68(u8* base, u8* c) asm("func_00209d68");
void func_00209d68(u8* base, u8* c) {
    u128g* p = (u128g*)(base + (*(s32**)(c + 12))[2] + 160);
    s32 i;
    for (i = 0; i < 8; i++) *p++ = 0;
}
void func_00209da8(void) asm("func_00209da8");
void func_00209da8(void) {}
void func_00209db0(void) asm("func_00209db0");
void func_00209db0(void) {}
void func_00209db8(void) asm("func_00209db8");
void func_00209db8(void) {}
}  // namespace n00209d68

// 00209dc0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00209dc0 {
u32 sceVu0CopyMatrix(u32, u32, u32, u32) asm("_Z16sceVu0CopyMatrixjjjj");
extern u8 D_01d9e6f0 asm("D_01d9e6f0");
/*TARGET 00209dc0*/
u32 func_00209dc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00209dc0jjjj");
u32 func_00209dc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = *(u32*)((u32)r5 + (s32)(12));
    r14 = *(u32*)((u32)r15 + (s32)(4));
    r5 = (u32)&D_01d9e6f0;
    r4 = (u32)(r4 + r14);
    r4 = (u32)((s32)r4 + (224));
    u32 (*fp_call4_002f3f98)(u32, u32, u32, u32) = sceVu0CopyMatrix;
    r2 = fp_call4_002f3f98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00209dc0

// 00209df0 (was src/anon/batch_w64.cpp)
namespace n00209df0 {
// Disables sibling calls (empty destructor keeps a cleanup pending).
struct NoTail { ~NoTail() {} };
// ---------------------------------------------------------------------------
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern char D_01d9e730[] asm("D_01d9e730");
extern char D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
void sceVu0CopyMatrix(void*, void*) asm("sceVu0CopyMatrix");
/*TARGET 00209df0*/
void func_00209df0(u8* p, u32 a1, u8* r) asm("func_00209df0");
void func_00209df0(u8* p, u32 a1, u8* r) {
    NoTail nt;
    u8* b = p + *(s32*)(*(u8**)(r + 12) + 4);
    sceVu0MulMatrix(D_01d9e6e8 + 80, b + 224, D_01d9e6e8 + 16);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e730, D_01d9e6e8 + 80);
    sceVu0CopyMatrix(b + 160, D_01d9e6e8 + 80);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
}  // namespace n00209df0

// 00209e80 (was src/anon/batch_w27.cpp)
namespace n00209e80 {
// An empty-destructor local keeps a cleanup pending, which stops gcc from
// turning the final call into a sibling call (as in the game's destructors).
struct NoTail { ~NoTail() {} };
void sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
// memcpy16
extern u32 D_00354bc0 asm("D_00354bc0");
extern u32 D_00354be0 asm("D_00354be0");
/*TARGET 00209e80*/
void func_00209e80(u8* a, u8* b) asm("func_00209e80");
void func_00209e80(u8* a, u8* b) {
    NoTail g;
    u8* s = a + *(s32*)(*(u8**)(b + 12) + 4);
    sceVu0CopyVector(s + 224, &D_00354bc0);  // memcpy16
    sceVu0CopyVector(s + 240, &D_00354be0);  // memcpy16
}
}  // namespace n00209e80

// 00209ed0 (was src/anon/batch_w84.cpp)
namespace n00209ed0 {
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_01d9e730[] asm("D_01d9e730");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0UnitMatrix(void*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0ApplyMatrix(void*, void*, void*) asm("sceVu0ApplyMatrix");
void sceVu0CopyMatrix(void*, void*) asm("sceVu0CopyMatrix");
/*TARGET 00209ed0*/
void func_00209ed0(u8* a, u32, u8* c) asm("func_00209ed0");
void func_00209ed0(u8* a, u32, u8* c) {
    f32 m[16] __attribute__((aligned(16)));
    u8* s = a + *(u32*)(*(u8**)(c + 12) + 4);
    sceVu0UnitMatrix(m);  // vu_store_w_splat
    f32* v = (f32*)(s + 160);
    m[12] = v[16];
    m[13] = v[17];
    m[14] = v[18];
    sceVu0MulMatrix(m, D_01d9e730, m);
    sceVu0ScaleVector(D_01d9e6e8 + 80, D_01d9e6e8 + 16, v[20]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8 + 96, D_01d9e6e8 + 32, v[21]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8 + 112, D_01d9e6e8 + 48, v[22]);  // vec_scale_by_f12
    sceVu0ApplyMatrix(D_01d9e6e8 + 128, m, D_01d9e6e8 + 64);
    sceVu0CopyMatrix(v, D_01d9e6e8 + 80);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
}  // namespace n00209ed0

// 00209fb8 (was src/anon/batch_w50.cpp)
namespace n00209fb8 {
union FU { u32 u; f32 f; };
/*TARGET 00209fb8*/
// VU0 random float: reseed/step R five times. Hand-written VU0 assembly.
f32 func_00209fb8(void) asm("func_00209fb8");
// VU0 random float: reseed/step R five times. Hand-written VU0 assembly.
f32 func_00209fb8(void) {  // vu_const_5f_c
    register u32 x asm("$15");
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\t"
        "qmfc2 %0, $vf1" : "=r"(x) : : "$8");
    FU u;
    u.u = x;
    return u.f;
}
}  // namespace n00209fb8

// 0020a000 (was src/anon/auto80_199_queue.cpp)
namespace n0020a000 {
/*TARGET 0020a000*/
s32 func_0020a000(u32 a0) asm("_Z13func_0020a000j");
s32 func_0020a000(u32 a0) {
    u32 s0 = a0 & 0xff;
    f32 f20 = (f32)(s32)(s0 << 1);
    f32 f0 = func_00209fb8(a0);  // vu_const_5f_c
    f20 = f20 * f0;
    f0 = (f32)(s32)(s0 >> 1);
    f20 = f20 - f0;
    s32 v0 = (s32)f20;
    return (s8)v0;
}
}  // namespace n0020a000

// 0020a060 (was src/anon/tiny_auto80_queue.cpp)
namespace n0020a060 {
/*TARGET 0020a060*/
s32 func_0020a060(u8* a0, u8* a1) asm("_Z13func_0020a060PhS_");
s32 func_0020a060(u8* a0, u8* a1) {
    if (*(u32*)(a0 + 0) == 0) {
        return 0;
    }
    if (*(u8*)(a1 + 182) == 0 || *(u32*)(a0 + 4) != 0) {
        return 1;
    }
    return 0;
}
}  // namespace n0020a060

