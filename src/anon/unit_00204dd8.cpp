// Linked unit 0x00204dd8-0x00205178 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 00204dd8 (was gap, written for the unit)
namespace n00204dd8 {
struct EmG { f32 m[4][4]; f32 v[4]; u8* parts; u8* p84; u8* p88; s32 count; };
struct CtxG { u8 pad0[12]; s32* off; };
extern u8* D_01d9e6e4 asm("D_01d9e6e4");
extern f32 D_00354be0[3] asm("D_00354be0");
extern f32 D_01d9e720[4] asm("D_01d9e720");
extern f32 D_01d9e6f0[4][4] asm("D_01d9e6f0");
u8* func_001e7698(u8*, s32) asm("func_001e7698");
void func_001e7188(void*, s32, s32) asm("func_001e7188");
void sceVu0Normalize(f32*, f32*) asm("sceVu0Normalize");
void sceVu0UnitMatrix(f32 (*)[4]) asm("sceVu0UnitMatrix");
void func_002f4870(f32, f32*, f32*) asm("func_002f4870");
void sceVu0CopyVector(f32*, f32*) asm("sceVu0CopyVector");
void sceVu0CopyMatrix(f32 (*)[4], f32 (*)[4]) asm("sceVu0CopyMatrix");
s32 func_00203ae8(EmG*, u8*) asm("func_00203ae8");
void func_00204bd0(u8*, EmG*, u8*, u8*) asm("func_00204bd0");
void func_00204dd8(u8* base, u8* d, CtxG* c) asm("func_00204dd8");
void func_00204dd8(u8* base, u8* d, CtxG* c) {
    EmG* e = (EmG*)(base + c->off[2] + 160);
    u8* w = base + c->off[1] + 160;
    if (e->parts == 0) {
        e->count = *(u16*)(d + 28);
        if ((e->parts = func_001e7698(D_01d9e6e4, e->count * 96)) != 0)
            func_001e7188(e->parts, 0, e->count * 24);
        if ((u32)(d[204] - 1) < 3) {
            if ((e->p84 = func_001e7698(D_01d9e6e4, e->count << 6)) != 0)
                func_001e7188(e->p84, 0, e->count << 4);
        }
        if (d[201]) {
            if ((e->p88 = func_001e7698(D_01d9e6e4, e->count << 5)) != 0)
                func_001e7188(e->p88, 0, e->count << 3);
        }
        e->v[0] = *(f32*)(d + 152);
        e->v[1] = *(f32*)(d + 156);
        e->v[2] = *(f32*)(d + 160);
        *(s32*)&e->v[3] = 0;
        sceVu0Normalize(e->v, e->v);
    }
    if (func_00203ae8(e, d)) {
        switch (d[38]) {
        case 1: case 3: case 5: case 7: case 9:
            sceVu0UnitMatrix(e->m);
            func_002f4870(D_00354be0[0], e->m[0], e->m[0]);
            func_002f4870(D_00354be0[1], e->m[1], e->m[1]);
            func_002f4870(D_00354be0[2], e->m[2], e->m[2]);
            sceVu0CopyVector(e->m[3], D_01d9e720);
            e->m[3][3] = 1.0f;
            break;
        case 0: case 2: case 4: case 6: case 8:
        default:
            sceVu0CopyMatrix(e->m, D_01d9e6f0);
            break;
        }
        void (*f)(u8*, EmG*, u8*, u8*) = func_00204bd0;
        f(base, e, d, w);
    }
}
}  // namespace n00204dd8

// 00204fe0 (was src/anon/auto80_199_queue.cpp)
namespace n00204fe0 {
/*TARGET 00204fe0*/
void func_00204fe0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00204fe0jjjj");
void func_00204fe0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t6 = a2;
    u32 s0 = a1;
    if (*(u8*)(t6 + 204) != 0) {
        return;
    }
    sceVu0MulMatrix(a1, a3, a1 + 256);
    sceVu0MulMatrix(s0 + 64, s0 + 128, s0);
}
}  // namespace n00204fe0

// 00205040 (was src/anon/batch_w93.cpp)
namespace n00205040 {
// 0x001dd920: definition moved into src/anon/unit_001dd920.cpp

union W93IF { s32 i; f32 f; };
/*TARGET 00205040*/
// Quicksort (descending by key), permuting the index array alongside the keys.
void func_00205040(W93IF* idx, f32* key, s32 lo, s32 hi) asm("func_00205040");
// Quicksort (descending by key), permuting the index array alongside the keys.
void func_00205040(W93IF* idx, f32* key, s32 lo, s32 hi)
{
    s32 i = lo;
    s32 j = hi;
    f32 p = key[(lo + hi) / 2];
    for (;;) {
        while (p < key[i]) i++;
        while (key[j] < p) j--;
        if (i >= j) break;
        f32 tf = key[i]; key[i] = key[j]; key[j] = tf;
        s32 ti = idx[i].i; idx[i].i = idx[j].i; idx[j].i = ti;
        i++;
        j--;
    }
    if (lo < i - 1) func_00205040(idx, key, lo, i - 1);
    if (j + 1 < hi) func_00205040(idx, key, j + 1, hi);
}
}  // namespace n00205040

