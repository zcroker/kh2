// Linked unit 0x002086e0-0x00208a30 (one namespace per old matched source; class methods in their own namespace).
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

// 002086e0 (was src/anon/batch_w98.cpp)
namespace n002086e0 {
// 00228ab0: moved to src/anon/unit_00228618.cpp (linked unit)

struct O208 { u8 pad[16]; u8* items; u8* b; u8* c; s32 n; u16 f32; };
struct A208 { u8 pad[30]; u16 max; u16 delay; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_00208298(O208*, A208*, u8*, u32, u8*) asm("func_00208298");
void func_00207350(O208*, A208*, u32, u8*, u8*, u8*) asm("func_00207350");
/*TARGET 002086e0*/
// Updates spawn slots: live ones tick, free ones spawn after the delay (up to max per call).
void func_002086e0(O208* o, A208* a, u32 arg) asm("func_002086e0");
// Updates spawn slots: live ones tick, free ones spawn after the delay (up to max per call).
void func_002086e0(O208* o, A208* a, u32 arg) {
    s32 cnt = 0;
    u8* it = o->items;
    u8* b = o->b;
    u8* c = o->c;
    s32 n = o->n;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    o->f32++;
    for (s32 i = 0; i < n; i++) {
        if (*(u16*)(it + 64)) {
            func_00208298(o, a, it, arg, c);
        } else if (a->delay <= o->f32 && cnt < a->max) {
            func_00207350(o, a, arg, it, b, c);
            cnt++;
        }
        if (b) b += 64;
        if (c) c += 32;
        it += 176;
    }
    if (cnt > 0) o->f32 = 0;
}
}  // namespace n002086e0

// 00208828 (was gap, written for the unit)
namespace n00208828 {
struct EmH { f32 v[4]; u8* parts; u8* p20; u8* p24; s32 count; };
struct CtxG { u8 pad0[12]; s32* off; };
extern u8* D_01d9e6e4 asm("D_01d9e6e4");
u8* func_001e7698(u8*, s32) asm("func_001e7698");
void wtarget_002fde18(u8*, s32, s32) asm("_Z16wtarget_002fde18jjjj");
void sceVu0Normalize(EmH*, EmH*) asm("sceVu0Normalize");
s32 func_00207308(EmH*, u8*) asm("func_00207308");
void func_002086e0(EmH*, u8*, u8*) asm("func_002086e0");
void func_00208828(u8* base, u8* d, CtxG* c) asm("func_00208828");
void func_00208828(u8* base, u8* d, CtxG* c) {
    EmH* e = (EmH*)(base + c->off[2] + 160);
    u8* w = base + c->off[1] + 160;
    if (e->parts == 0) {
        e->count = *(u16*)(d + 28);
        if ((e->parts = func_001e7698(D_01d9e6e4, e->count * 176)) != 0)
            wtarget_002fde18(e->parts, 0, e->count * 176);
        if (d[262]) {
            if ((e->p20 = func_001e7698(D_01d9e6e4, e->count << 6)) != 0)
                wtarget_002fde18(e->p20, 0, e->count << 6);
        }
        if (d[257]) {
            if ((e->p24 = func_001e7698(D_01d9e6e4, e->count << 5)) != 0)
                wtarget_002fde18(e->p24, 0, e->count << 5);
        }
        e->v[0] = *(f32*)(d + 208);
        e->v[1] = *(f32*)(d + 212);
        e->v[2] = *(f32*)(d + 216);
        *(s32*)&e->v[3] = 0;
        sceVu0Normalize(e, e);
    }
    if (func_00207308(e, d)) { void (*f)(EmH*, u8*, u8*) = func_002086e0; f(e, d, w); }
}
}  // namespace n00208828

// 00208978 (was src/anon/batch_wcx2.cpp)
namespace n00208978 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// 0x001e2298: definition moved into src/anon/unit_001e0cb8.cpp

// --------------------
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
void func_002f4000_x8625(void*, u8*, u8*) asm("sceVu0UnitMatrix");
void func_002f3d08_x8626(void*, u8*, u8*) asm("sceVu0MulMatrix");
/*TARGET 00208978*/
void func_00208978(void* a, u8* b, u8* c) asm("func_00208978");
void func_00208978(void* a, u8* b, u8* c) {
    s32 n = *(s32*)(c + 20);
    func_002f4000_x8625(a, b, c);
    switch (b[38]) {
    case 0: case 2: case 4: case 6: case 8:
    default:
        if (n == 0) func_002f3d08_x8626(a, D_01d9e840, D_01d9e6e8 + 16);
        break;
    case 1: case 3: case 5: case 7: case 9:
        func_002f3d08_x8626(a, D_01d9e840, D_01d9e6e8 + 16);
        break;
    }
}
}  // namespace n00208978

