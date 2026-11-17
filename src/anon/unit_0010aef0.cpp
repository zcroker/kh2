#include "../common/types.h"

// Static initialiser 0x10aef0 (partial asm, moved as is) and its _GLOBAL__I_ stub 0x10b418 as plain functions. 0x10b438 belongs to the next file.
// Each function keeps the declarations of the source it was matched in (namespace nADDR); every symbol
// is bound by asm label.
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 0010aef0 (from src/anon/batch_w3955.cpp)
namespace n0010aef0 {
void func_001081c8(void*) asm("func_001081c8");
void func_00108990(void*) asm("func_00108990");
extern u8 D_003a8cd0[] asm("D_003a8cd0");
extern u8 D_003a8db0[] asm("D_003a8db0");
extern u8 D_00340ed8[] asm("D_00340ed8");
extern u8 D_00325c00[] asm("D_00325c00"); extern u8 D_003273a0[] asm("D_003273a0"); extern u8 D_00327400[] asm("D_00327400"); extern u8 D_00329790[] asm("D_00329790");
extern u8 D_00329800[] asm("D_00329800"); extern u8 D_00329b40[] asm("D_00329b40"); extern u8 D_00329b80[] asm("D_00329b80"); extern u8 D_0032a720[] asm("D_0032a720");
extern u32 D_003a8e90 asm("D_003a8e90"); extern u32 D_003a8e94 asm("D_003a8e94"); extern u32 D_003a8e98 asm("D_003a8e98"); extern u32 D_003a8e9c asm("D_003a8e9c");
extern u32 D_00341690 asm("D_00341690"); extern u32 D_00341694 asm("D_00341694");
extern u32 D_003a8ec8 asm("D_003a8ec8"); extern u32 D_003a8ecc asm("D_003a8ecc");
extern u64 D_003a8ed0[46] asm("D_003a8ed0");
#define GSXYZ_aef0(x,y,z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
#define GSXYOFS_aef0(x,y) ((u64)(x) | ((u64)(y) << 32))
#define GSSCIS_aef0(x0,x1,y0,y1) ((u64)(x0) | ((u64)(x1) << 16) | ((u64)(y0) << 32) | ((u64)(y1) << 48))
#define GSFRAME_aef0(a,b,c,d) ((u64)(a) | ((u64)(b) << 16) | ((u64)(c) << 24) | ((u64)(d) << 32))
#define GSCLAMP_aef0(a,b,c,d,e,f) ((u64)(a) | ((u64)(b) << 2) | ((u64)(c) << 4) | ((u64)(d) << 14) | ((u64)(e) << 24) | ((u64)(f) << 34))
#define GSTEX0_aef0(tbp,tbw,psm,tw,th,tcc,tfx) ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35))
// g++ static init (priority 0xffff) of a TU: table sizes, GS register packet.
void func_0010aef0(int a0, int a1) asm("_Z13func_0010aef0ii");
void func_0010aef0(int a0, int a1) asm("func_0010aef0");
void func_0010aef0(int a0, int a1) {
    if (a1 == 0xffff && a0 == 1) func_001081c8(D_003a8cd0);
    if (a1 == 0xffff && a0 == 1) func_001081c8(D_003a8db0);
    if (a1 == 0xffff && a0 == 1) D_003a8e90 = (u32)(D_003273a0 - D_00325c00) >> 4;
    if (a1 == 0xffff && a0 == 1) D_003a8e94 = (u32)(D_00329790 - D_00327400) >> 4;
    if (a1 == 0xffff && a0 == 1) D_003a8e98 = (u32)(D_00329b40 - D_00329800) >> 4;
    if (a1 == 0xffff && a0 == 1) D_003a8e9c = (u32)(D_0032a720 - D_00329b80) >> 4;
    if (a1 == 0xffff && a0 == 1) {
        // Table {0, {start, count} x4}. Inline asm: gcc 3.2 hoists all four count
        // loads; the original interleaves them with the stores (likely an aggregate
        // initializer expanded by store_constructor).
        asm volatile(
            "lui $15, %%hi(D_003a8e90)\n\t"
            "lui $13, %%hi(D_003a8ea0)\n\t"
            "lw $14, %%lo(D_003a8e90)($15)\n\t"
            "sd $0, %%lo(D_003a8ea0)($13)\n\t"
            "lui $15, %%hi(D_003a8e94)\n\t"
            "lw $12, %%lo(D_003a8e94)($15)\n\t"
            "addiu $13, $13, %%lo(D_003a8ea0)\n\t"
            "sw $14, 12($13)\n\t"
            "lui $15, %%hi(D_003a8e98)\n\t"
            "sw $12, 20($13)\n\t"
            "lw $11, %%lo(D_003a8e98)($15)\n\t"
            "lui $15, %%hi(D_003a8e9c)\n\t"
            "sw $11, 28($13)\n\t"
            "lw $14, %%lo(D_003a8e9c)($15)\n\t"
            "sw $14, 36($13)\n\t"
            "lui $15, %%hi(D_00325c00)\n\t"
            "addiu $15, $15, %%lo(D_00325c00)\n\t"
            "lui $14, %%hi(D_00327400)\n\t"
            "sw $15, 8($13)\n\t"
            "addiu $14, $14, %%lo(D_00327400)\n\t"
            "sw $14, 16($13)\n\t"
            "lui $15, %%hi(D_00329800)\n\t"
            "addiu $15, $15, %%lo(D_00329800)\n\t"
            "lui $14, %%hi(D_00329b80)\n\t"
            "sw $15, 24($13)\n\t"
            "addiu $14, $14, %%lo(D_00329b80)\n\t"
            "sw $14, 32($13)"
            : : : "$11", "$12", "$13", "$14", "$15", "memory");
    }
    if (a1 == 0xffff && a0 == 1) func_00108990(D_00340ed8);
    if (a1 == 0xffff && a0 == 1) D_003a8ec8 = 1 << D_00341690;
    if (a1 == 0xffff && a0 == 1) D_003a8ecc = 1 << D_00341694;
    if (a1 == 0xffff && a0 == 1) {
        u32 w = D_003a8ec8, h = D_003a8ecc;
        u64* q = D_003a8ed0;
        q[0] = 0x9000000000000001ULL; q[1] = 0xeeeeeeeeeULL;
        q[2] = GSFRAME_aef0(0x140, w >> 6, 0, 0); q[3] = 0x4c;
        q[4] = 0x6800080000aULL; q[5] = 8;
        q[6] = GSSCIS_aef0(0, w - 1, 0, h - 1); q[7] = 0x40;
        q[8] = GSXYOFS_aef0((2048 - w / 2) << 4, (2048 - h / 2) << 4); q[9] = 0x18;
        q[10] = 0x664021b00ULL; q[11] = 6;
        q[12] = 0x60; q[13] = 0x14;
        q[14] = 0x30000; q[15] = 0x47;
        q[16] = 0x44; q[17] = 0x42;
        q[18] = 0x131000070ULL; q[19] = 0x4e;
        q[20] = 0x6400000000000001ULL; q[21] = 0x535310;
        q[22] = 0x116; q[23] = 0x3f80000080808080ULL;
        q[24] = 0x80008; q[25] = GSXYZ_aef0((2048 - w / 2) << 4, (2048 - h / 2) << 4, 0xfffffffe);
        q[26] = 0x19f81ff8; q[27] = GSXYZ_aef0((2048 + w / 2) << 4, (2048 + h / 2) << 4, 0xfffffffe);
        q[28] = 0x8000000000008001ULL; q[29] = 0xeeeeeeeeULL;
        q[30] = 0; q[31] = 0x3f;
        q[32] = 0x730000007000ULL; q[33] = 0x18;
        q[34] = GSCLAMP_aef0(2, 2, 1, w - 1, 1, h - 1); q[35] = 8;
        q[36] = 0x19f000001ff0000ULL; q[37] = 0x40;
        q[38] = GSTEX0_aef0(0x2800, w >> 6, 0, D_00341690, D_00341694, 1, 0); q[39] = 6;
        q[40] = 0x50002; q[41] = 0x47;
        q[42] = 0x131000070ULL; q[43] = 0x4e;
        q[44] = 0x800d8; q[45] = 0x4c;
    }
}
}  // namespace n0010aef0

// 0010b418 (from src/anon/tiny.cpp)
namespace n0010b418 {
void func_0010aef0(s32, s32) asm("func_0010aef0");
// 00108028: moved to src/naka/libkn/camera.cpp
void func_0010b418(BD_VALUE* bd) asm("func_0010b418");
void func_0010b418(BD_VALUE* bd) { func_0010aef0(1, 0xffff); }
}  // namespace n0010b418

