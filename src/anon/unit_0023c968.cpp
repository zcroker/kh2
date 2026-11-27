// Linked unit 0x0023c968-0x0023d260: YI::LAYOUT tail, YI::VIBRATION, menu state (gap functions written here).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../ishi/sequence.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_obj.hpp"
#include "../tozawa/layout.hpp"
#include "../tozawa/laymsg.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/mcard.hpp"

// 0023c968 (was gap)
namespace n0023c968 {
u32 func_0023c968(u8* p) asm("func_0023c968");
u32 func_0023c968(u8* p) { return (u32)(*(s32*)(p + 56) - 2) < 2; }
}  // namespace n0023c968

// 0023c978 (was src/anon/auto80_199_queue.cpp)
namespace n0023c978 {
/*TARGET 0023c978*/
u32 func_0023c978(void* a0) asm("_Z13func_0023c978Pv");
u32 func_0023c978(void* a0) {
    u8* s2;
    u8* s1;
    u8* s0;
    s32 s3;

    s2 = (u8*)a0;
    s3 = 0;

    s1 = (u8*)(*(u32*)(s2 + 0x14) + (*(u32*)(s2 + 0x4c) * 20u));
    s0 = (u8*)(*(u32*)(s2 + 0x10) + ((u32)*(u16*)(s1 + 0) * 24u));

    if (*(u16*)(s1 + 2) != 0) {
        for (;;) {
            u32 idx;
            u32 v0;

            idx = *(u32*)(s0 + 4);
            v0 = func_00239d30((void*)(*(u32*)(s2 + 0x2c) + (idx * 344u)), *(u32*)(s0 + 8));
            s0 += 24;
            if (v0 != 0) {
                return 1;
            }
            s3 += 1;
            if (s3 < (s32)*(u16*)(s1 + 2)) {
                continue;
            }
            break;
        }
    }

    return 0;
}
}  // namespace n0023c978

// 0023ca30 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023ca30 {
/*TARGET 0023ca30*/
u32 func_0023ca30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023ca30jjjjjjjj");
u32 func_0023ca30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 n = *(u32*)(a0 + 76);
    u32 scale = 20;
    u32 base = *(u32*)(a0 + 20);
    a1 <<= 2;
    n *= scale;
    n += base;
    a1 += n;
    return *(u32*)(a1 + 8);
}
}  // namespace n0023ca30

// 0023ca58 (was gap)
namespace n0023ca58 {
void func_0023ca58(u8* p, s32* x, s32* y) asm("func_0023ca58");
void func_0023ca58(u8* p, s32* x, s32* y) {
    *x = *(s32*)(p + 84);
    *y = *(s32*)(p + 88);
}
}  // namespace n0023ca58

// 0023ca70 (was src/anon/tiny.cpp)
namespace n0023ca70 {
/*TARGET 0023ca70*/
// 0x00237238: definition moved into src/anon/unit_00237068.cpp

void func_0023ca70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023ca70jjjj");
// 0x00237238: definition moved into src/anon/unit_00237068.cpp

void func_0023ca70(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a3;
    *(u32*)((u32)a0 + (84)) = a1;
    *(u32*)((u32)a0 + (88)) = a2;
}
}  // namespace n0023ca70

// 0023ca80 (was src/anon/batch_w283.cpp)
namespace n0023ca80 {
struct W283_WT {
    u8 pad0[12];
    void (*cb)(void);
    u8* tbl24;
    u8* tbl20;
    u8 pad24[24];
    u8* arr;
    s32 count;
    s32 state;
    f32 t0;
    f32 t1;
    f32 max;
    f32 speed;
    s32 idx;
    u8 noLoop;
};
// 0x001ee0a0: definition moved into src/anon/unit_001ec098.cpp

extern f32 D_00349e14 asm("D_00349e14");
void func_0023c598(void*) asm("_Z13func_0023c598Pv");
void func_0023acd8(void*) asm("func_0023acd8");
s32 W283_GetPlayMode(void*) asm("_ZN2YI8SEQUENCE11GetPlayModeEv");
void wtarget_0023ca80(W283_WT* p, u32, u32, u32) asm("_Z16wtarget_0023ca80jjjj");
/*TARGET 0023ca80*/
void wtarget_0023ca80(W283_WT* p, u32, u32, u32) asm("_Z16wtarget_0023ca80jjjj");
void wtarget_0023ca80(W283_WT* p, u32, u32, u32) {
    *(f32*)((u8*)p + 60) += D_00349e14 * p->speed;
    switch (p->state) {
    case 1:
        p->state = 2;
        func_0023c598(p);
        break;
    case 2:
        p->t1 += D_00349e14 * p->speed;
        if (p->max <= p->t1 && p->noLoop == 0) {
            p->state = 3;
            p->t1 = p->max - 1.0f;
            if (p->cb) p->cb();
        }
        break;
    case 0:
        return;
    default:
        return;
    }
    u16* ent = (u16*)(p->tbl20 + p->idx * 20);
    u8* e = p->tbl24 + *ent * 24;
    s32 busy = 0;
    for (s32 i = 0; i < p->count; i++, e += 24) {
        u8* o = p->arr + i * 344;
        if ((f32)*(s32*)(e + 12) <= p->t1) {
            func_0023acd8(o);
            if (W283_GetPlayMode(o)) busy = 1;
        } else {
            busy = 1;
        }
    }
    if (!busy) p->state = 3;
}
}  // namespace n0023ca80

// 0023cc18 (was src/anon/batch_w265.cpp)
namespace n0023cc18 {
// 0x0029ac00: definition moved into src/anon/unit_00299920.cpp
struct I265 { s32 id; s32 b; s32 c; s32 n; s32 x; s32 y; };
struct O265 { u8 pad[64]; s32 h; u8 pad2[260]; s32 x; s32 y; u8 pad3[8]; };
struct P265 { u8 pad[16]; u8* tbl; u8* recs; u8 pad2[24]; O265* objs; s32 cnt; s32 st; u8 padx[4]; f32 lim; u8 pad3[8]; s32 sel; u8 pad4[4]; s32 dx; s32 dy; };
void func_00236d60(void) asm("func_00236d60");
// clear_64_entries_24
void func_00236830(s32) asm("func_00236830");
void func_0023ade0(O265*) asm("func_0023ade0");
void func_002367a0(void) asm("func_002367a0");
/*TARGET 0023cc18*/
void func_0023cc18(P265* p) asm("func_0023cc18");
void func_0023cc18(P265* p) {
    I265* it;
    s32 last;
    s32 off;
    s32 i;
    if (p->st < 0) return;
    if (p->st < 2) return;
    if (p->st >= 4) return;
    { s32 k = p->sel * 20; u8* r = p->recs; it = (I265*)(p->tbl + *(u16*)(r + k) * 24); }
    func_00236d60();  // clear_64_entries_24
    last = -1;
    for (i = 0; i < p->cnt; i++, it++) {
        O265* o = &p->objs[i];
        if ((f32)it->n <= p->lim) {
            if (last != it->id) {
                last = it->id;
                func_00236830(o->h);
            }
            s32 nx = it->x + p->dx;
            s32 ny = it->y + p->dy;
            o->x = nx;
            o->y = ny;
            func_0023ade0(o);
        }
    }
    func_002367a0();
}
}  // namespace n0023cc18

// 0023cd58 (was gap)
namespace n0023cd58 {
extern u32 D_0035eb40 asm("D_0035eb40");
void func_0023cd58(u32 a0) asm("func_0023cd58");
void func_0023cd58(u32 a0) {
    *(u32*)((u32)a0 + (0)) = (u32)&D_0035eb40;
}
}  // namespace n0023cd58

// 0023cd68 (was src/anon/tiny.cpp)
namespace n0023cd68 {
extern u32 D_0035eb40 asm("D_0035eb40");
/*TARGET 0023cd68*/
void func_0023cd68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023cd68jjjj");
void func_0023cd68(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_0035eb40;
}
}  // namespace n0023cd68

// 0023cd78 (was gap)
namespace n0023cd78 {
extern u32 D_0035eb40 asm("D_0035eb40");
void func_0023cd78(u32 a0) asm("func_0023cd78");
void func_0023cd78(u32 a0) {
    *(u32*)((u32)a0 + (0)) = (u32)&D_0035eb40;
}
}  // namespace n0023cd78

// 0023cd88 (was gap)
namespace n0023cd88 {
extern u32 D_0035eb40 asm("D_0035eb40");
void func_0023cd88(u32 a0) asm("func_0023cd88");
void func_0023cd88(u32 a0) {
    *(u32*)((u32)a0 + (0)) = (u32)&D_0035eb40;
}
}  // namespace n0023cd88

// 0023cd98 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0023cd98 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_0035eb40 asm("D_0035eb40");
/*TARGET 0023cd98*/
// 0x00237258: definition moved into src/anon/unit_00237068.cpp

u32 func_0023cd98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023cd98jjjjjjjj");
// 0x00237258: definition moved into src/anon/unit_00237068.cpp

u32 func_0023cd98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0035eb40;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0023cd98

// 0023cdb8 (was src/anon/batch_w1.cpp)
namespace n0023cdb8 {
extern s32 D_0035eb34 asm("D_0035eb34");
extern s32 D_0035eb28 asm("D_0035eb28");
extern s32 D_01dae680 asm("D_01dae680");
/*TARGET 0023cdb8*/
// 0x002282d8: definition moved into src/anon/unit_00224780.cpp

void func_0023cdb8(void) asm("func_0023cdb8");
// 0x002282d8: definition moved into src/anon/unit_00224780.cpp

void func_0023cdb8(void) {
    D_0035eb34 = 1;
    D_0035eb28 = 0;
    D_01dae680 = 0;
}
}  // namespace n0023cdb8

// 0023cdd8 (was gap)
namespace n0023cdd8 {
extern s32 D_01dae680 asm("D_01dae680");
void func_0023cdd8(void) asm("func_0023cdd8");
void func_0023cdd8(void) { D_01dae680 = 0; }
}  // namespace n0023cdd8

// 0023cde8 (was src/anon/batch_wcx2.cpp)
namespace n0023cde8 {
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
// 0022bc08: moved to src/sasa/event_movie.cpp (linked unit)

struct Hdr49 { u8 pad[8]; s32 n0; s32 o0; s32 n1; s32 o1; };
struct Thr49 { u8 pad[48]; void* fn; };
struct Th49 { u32 pad; u32 id; };
union U49 { Hdr49* p; u8 c; };
extern U49 D_0035eb10 asm("D_0035eb10");
extern s32 D_0035eb20[2] asm("D_0035eb20");
extern s32 D_0035eb18[2] asm("D_0035eb18");
extern s32 D_0035eb28 asm("D_0035eb28");
extern s32 D_0035eb2c asm("D_0035eb2c");
extern s32 D_0035eb30 asm("D_0035eb30");
extern s32 D_01dae680 asm("D_01dae680");
s32 func_00102c80(void) asm("func_00102c80");
Th49* func_00104190(void) asm("func_00104190");
void func_00102180(s32*) asm("func_00102180");
Thr49* func_00102c18__79184(s32, s32, void*) asm("func_00102c18");
Thr49* func_00102788(u32, s32, s32, void*) asm("func_00102788");
void func_0023cf60(void) asm("func_0023cf60");
void func_0023cdd8(void) asm("func_0023cdd8");
/*TARGET 0023cde8*/
s32 func_0023cde8(Hdr49* h) asm("func_0023cde8");
s32 func_0023cde8(Hdr49* h)
{
    D_0035eb10.p = h;
    D_0035eb20[0] = (s32)h + h->o0;
    D_0035eb20[1] = (s32)h + h->o1;
    D_0035eb18[0] = h->n0;
    D_0035eb18[1] = h->n1;
    D_0035eb28 = 1;
    D_0035eb2c = 0;
    D_0035eb30 = 0;
    for (s32 i = 0; i < 2; i++) {
        s32* p = (s32*)D_0035eb20[i];
        for (s32 n = D_0035eb18[i]; n > 0; n--, p += 2) {
            if (D_0035eb30 < *p) D_0035eb30 = *p;
        }
    }
    if (D_01dae680) return 1;
    Thr49* t = 0;
    s32 cur[4];
    s32 a = func_00102c80();
    Th49* b = func_00104190();
    D_01dae680 = 1;
    func_00102180(cur);
    if (cur[0] == a) t = func_00102c18__79184(0, 15000, (void*)func_0023cf60);
    else if (cur[0] == (s32)b) t = func_00102788(b->id, 0, 15000, (void*)func_0023cf60);
    t->fn = (void*)func_0023cdd8;
    return 1;
}
}  // namespace n0023cde8

// 0023cf60 (was gap)
namespace n0023cf60 {
extern s32 D_01dae680 asm("D_01dae680");
extern s32 D_0035eb28 asm("D_0035eb28");
void func_0023cfb8(void*) asm("func_0023cfb8");
void func_001024a8(void*) asm("func_001024a8");
void func_0023cf60(void* p) asm("func_0023cf60");
void func_0023cf60(void* p) {
    func_0023cfb8(p);
    if (D_01dae680 == 2 || D_0035eb28 == 0) func_001024a8(p);
}
}  // namespace n0023cf60

// 0023cfb8 (was src/anon/batch_w1985_nsa.cpp)
namespace n0023cfb8 {
typedef struct { s32 t; s32 v; } W1985Key;
typedef struct { u8 pad[0x40]; } W1985Obj;
typedef struct { u8 pad[4]; u8 y; } W1985Byte;
extern s32 D_0035eb18[2] asm("D_0035eb18");
extern W1985Key* D_0035eb20[2] asm("D_0035eb20");
extern s32 D_0035eb28 asm("D_0035eb28");
extern f32 D_0035eb2c asm("D_0035eb2c");
extern s32 D_0035eb30 asm("D_0035eb30");
extern s32 D_0035eb34 asm("D_0035eb34");
extern f32 D_00349e14 asm("D_00349e14");
W1985Obj* func_00167bf0(s32) asm("func_00167bf0");
/*TARGET 0023cfb8*/
// Steps a two-track key animation and writes the interpolated values to bytes 0x44/0x45.
void func_0023cfb8(void) asm("func_0023cfb8");
// Steps a two-track key animation and writes the interpolated values to bytes 0x44/0x45.
void func_0023cfb8(void) {
    s32 i;
    switch (D_0035eb28) {
    case 1: D_0035eb28 = 2; D_0035eb2c = 0.0f; break;
    case 2: D_0035eb2c += D_00349e14 * 0.5f; break;
    case 0: default: return;
    }
    if ((f32)D_0035eb30 <= D_0035eb2c) { D_0035eb28 = 0; D_0035eb2c = (f32)(D_0035eb30 - 1); }
    if (D_0035eb34 == 0) return;
    for (i = 0; i < 2; i++) {
        W1985Key* k = D_0035eb20[i] + 1;
        s32 j;
        if (D_0035eb2c < (f32)k[-1].t) continue;
        for (j = D_0035eb18[i] - 1; j > 0; j--, k++) {
            if (D_0035eb2c <= (f32)k[0].t) {
                f32 t1 = (f32)k[0].t;
                f32 t0 = (f32)k[-1].t;
                f32 d = t1 - t0;
                f32 r;
                if (d != 0.0f) r = (D_0035eb2c - (f32)k[-1].t) / d; else r = 1.0f;
                {
                    s32 a = k[-1].v;
                    s32 b = k[0].v;
                    ((W1985Byte*)((u32)func_00167bf0(0) + (i + 0x40)))->y = a + (s32)((f32)(b - a) * r);
                }
                break;
            }
        }
    }
}
}  // namespace n0023cfb8

// 0023d1b0 (was gap)
namespace n0023d1b0 {
extern s32 D_0035eb28 asm("D_0035eb28");
void func_0023d1b0(void) asm("func_0023d1b0");
void func_0023d1b0(void) { if (D_0035eb28 == 2) D_0035eb28 = 1; }
}  // namespace n0023d1b0

// 0023d1d0 (was src/anon/tiny.cpp)
namespace n0023d1d0 {
extern u32 D_0035eb34 asm("D_0035eb34");
/*TARGET 0023d1d0*/
// 0x002373a8: definition moved into src/anon/unit_00237068.cpp

void func_0023d1d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023d1d0jjjj");
// 0x002373a8: definition moved into src/anon/unit_00237068.cpp

void func_0023d1d0(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_global_word1
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    D_0035eb34 = (u32)((s32)1);
}
}  // namespace n0023d1d0

// 0023d1e0 (was src/anon/tiny.cpp)
namespace n0023d1e0 {
/*TARGET 0023d1e0*/
// 0x00237ad8: definition moved into src/anon/unit_00237068.cpp

void func_0023d1e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023d1e0jjjj");
// 0x00237ad8: definition moved into src/anon/unit_00237068.cpp

void func_0023d1e0(u32 a0, u32 a1, u32 a2, u32 a3) {  // zero_global_d
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-5324)) = (u32)0;
}
}  // namespace n0023d1e0

// 0023d1f0 (was gap)
namespace n0023d1f0 {
extern s32 D_0035eb28 asm("D_0035eb28");
void func_0023d1f0(void) asm("func_0023d1f0");
void func_0023d1f0(void) { if (D_0035eb28 != 0) D_0035eb28 = 3; }
void func_0023d210(void) asm("func_0023d210");
void func_0023d210(void) { if (D_0035eb28 != 0) D_0035eb28 = 2; }
}  // namespace n0023d1f0

// 0023d230 (was src/anon/tiny.cpp)
namespace n0023d230 {
/*TARGET 0023d230*/
void func_0023d230(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023d230jjjj");
void func_0023d230(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-5336)) = (u32)0;
}
}  // namespace n0023d230

// 0023d240 (was src/anon/tiny.cpp)
namespace n0023d240 {
extern u32 D_0035eb28 asm("D_0035eb28");
/*TARGET 0023d240*/
u32 func_0023d240(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023d240jjjj");
u32 func_0023d240(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_0035eb28 != 0);
}
}  // namespace n0023d240

// 0023d250 (was gap)
namespace n0023d250 {
extern s32 D_0035eb30 asm("D_0035eb30");
s32 func_0023d250(void) asm("func_0023d250");
s32 func_0023d250(void) { return D_0035eb30; }
}  // namespace n0023d250

