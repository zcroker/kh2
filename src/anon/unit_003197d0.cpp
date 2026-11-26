// Linked unit 0x003197d0: linkonce (template) copies of game code that the linker gathered after the
// toolchain libraries. One namespace per old matched source.
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
#include "../global/misc.hpp"


// 003197d0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n003197d0 {
/*TARGET 003197d0*/
// 0x00316868: definition moved into src/libsupc++/eh_exception.cpp

u32 func_003197d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_003197d0jjjj");
// 0x00316868: definition moved into src/libsupc++/eh_exception.cpp

u32 func_003197d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r4 = *(u32*)((u32)r4 + (s32)(4));
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r2 = *(u32*)((u32)r15 + (s32)(0));
    r2 = ((u32 (*)(u32, u32, u32, u32))(u32)r2)(r4, r5, r6, r7);
    return r2;
}
}  // namespace n003197d0

// 003197f8 (was src/anon/batch_w9.cpp)
namespace n003197f8 {
/*TARGET 003197f8*/
// 0x00314480: definition moved into src/libgcc/_make_df.c

void func_003197f8(u8* p) asm("func_003197f8");
// 0x00314480: definition moved into src/libgcc/_make_df.c

void func_003197f8(u8* p) {
    void* o = *(void**)(p + 4);
    (*(void (**)(void*))(*(u8**)o + 4))(o);
}
}  // namespace n003197f8

// 00319820 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00319820 {
/*TARGET 00319820*/
u32 func_00319820(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00319820jjjj");
u32 func_00319820(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r4 = *(u32*)((u32)r4 + (s32)(4));
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r2 = *(u32*)((u32)r15 + (s32)(8));
    r2 = ((u32 (*)(u32, u32, u32, u32))(u32)r2)(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00319820

// 00319848 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00319848 {
/*TARGET 00319848*/
u32 func_00319848(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00319848jjjj");
u32 func_00319848(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r4 = *(u32*)((u32)r4 + (s32)(4));
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r2 = *(u32*)((u32)r15 + (s32)(12));
    r2 = ((u32 (*)(u32, u32, u32, u32))(u32)r2)(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00319848

// 00319870 (was src/anon/batch_w80.cpp)
namespace n00319870 {
void func_00319d30(u8*) asm("func_00319d30");
/*TARGET 00319870*/
// 0x002ed350: definition moved into src/anon/unit_002ecdb0.cpp


void func_00319870(u8* p) asm("func_00319870");
// 0x002ed350: definition moved into src/anon/unit_002ecdb0.cpp


void func_00319870(u8* p) {  // init_18x4_entries
    s32 i;
    u8* q;
    u8* s;
    u32* w;
    for (i = 18, q = p; i != -1; i--, q += 4) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
    }
    s = p + 76;
    w = (u32*)s;
    for (i = 0; i < 8; i++) w[i] = 0;
    s[287] = 0;
    q = p + 364;
    for (i = 31; i != -1; i--) *q++ = 0;
    p += 396;
    w = (u32*)p;
    for (i = 0; i < 4; i++) w[i] = 0;
    func_00319d30(p + 16);
}
}  // namespace n00319870

// 00319930 (was src/anon/auto80_199_queue.cpp)
namespace n00319930 {
/*TARGET 00319930*/
// 0x003166f0: definition moved into src/libsupc++/eh_catch.cpp

void func_00319930(u32 a0) asm("_Z13func_00319930j");
// 0x003166f0: definition moved into src/libsupc++/eh_catch.cpp

void func_00319930(u32 a0) {
    s32 t14 = 19;
    u32 t15 = a0;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 80u;
    t14 = 2;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 92u;
    t14 = 17;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 164u;
    t14 = 8;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    *(volatile u32*)(a0 + 204u) = 0u;
    *(volatile u32*)(a0 + 200u) = 0u;
}
}  // namespace n00319930

// 003199d0 (was src/anon/auto80_199_queue.cpp)
namespace n003199d0 {
/*TARGET 003199d0*/
void func_003199d0(u32 a0) asm("_Z13func_003199d0j");
void func_003199d0(u32 a0) {
    *(u32*)(a0 + 0u) = 0u;
    s32 t14 = 2;
    *(u32*)(a0 + 4u) = 0u;
    u32 t15 = a0 + 16u;
    *(u32*)(a0 + 8u) = 0u;
    *(u32*)(a0 + 12u) = 0u;

    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 28u;
    t14 = 2;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 40u;
    t14 = 2;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    *(volatile u8*)(a0 + 577u) = 0u;
    *(volatile u32*)(a0 + 52u) = 0u;
    *(volatile u32*)(a0 + 56u) = 0u;
}
}  // namespace n003199d0

// 00319a60 (was src/anon/batch_wcx2.cpp)
namespace n00319a60 {
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
// 002e20d8: moved to src/anon/unit_002e1908.cpp

struct Pr84 { s32 x, y; };
struct St84 {
    s32 a[16]; s32 f64; s32 b[16]; s32 f132; s32 c[3]; s32 d[6]; s32 e[16]; s32 f[16]; s32 g[4];
    s32 f316, f320; Pr84 h[10]; Pr84 k[10]; s16 f484, f486;
};
/*TARGET 00319a60*/
void func_00319a60(St84* s) asm("func_00319a60");
void func_00319a60(St84* s)
{
    s32 i;
    for (i = 0; i < 16; i++) s->a[i] = 0;
    s->f64 = 0;
    { s32* p = s->b; i = 16; while (i--) *p++ = 0; }
    s->f132 = 0;
    for (i = 0; i < 3; i++) s->c[i] = 0;
    for (i = 0; i < 6; i++) s->d[i] = 0;
    { s32* p = s->e; i = 16; while (i--) *p++ = 0; }
    for (i = 0; i < 16; i++) s->f[i] = 0;
    for (i = 0; i < 4; i++) s->g[i] = 0;
    s->f316 = 0;
    s->f320 = 0;
    { Pr84* p = s->h; i = 10; while (i--) { p->x = 0; p->y = 0; p++; } }
    { Pr84* p = s->k; i = 10; while (i--) { p->x = 0; p->y = 0; p++; } }
    s->f484 = 0;
    s->f486 = 0;
}
}  // namespace n00319a60

// 00319bd0 (was src/anon/batch_w92.cpp)
namespace n00319bd0 {
void func_00319bd0(void*) asm("func_00319bd0");
struct C319 { u16 a, b, c; };
struct G319 { C319 c[64]; };
struct R319 { u32 w[8]; };
struct P319 { u32 a, b; };
struct S319 {
    u32 f0;
    G319 grid[19];
    R319 rows[19];
    u32 f7908;
    u32 f7912;
    u8 pad[1024];
    P319 pairs[19];
    u32 w9092[7];
    u32 w9120[16];
    u32 pad1[5];
    u32 w9204[16];
    u32 pad2[23];
    u32 f9360;
    P319 tail[10];
};
/*TARGET 00319bd0*/
// constructs the per-map table block (all slots cleared)
void func_00319bd0(void* sp) asm("func_00319bd0");
// constructs the per-map table block (all slots cleared)
void func_00319bd0(void* sp) {  // clear_18x64_entries
    S319* s = (S319*)sp;
    G319* g = s->grid;
    for (s32 n = 18; n != -1; n--) {
        C319* c = g->c;
        for (s32 k = 63; k != -1; k--) {
            c->a = 0;
            c->b = 0;
            c->c = 0;
            c++;
        }
        g++;
    }
    R319* r = s->rows;
    for (s32 n = 18; n != -1; n--) {
        for (s32 i = 0; i < 8; i++) r->w[i] = 0;
        r++;
    }
    s->f7908 = 0;
    s->f7912 = 0;
    P319* p = s->pairs;
    for (s32 n = 18; n != -1; n--) {
        p->a = 0;
        p->b = 0;
        p++;
    }
    for (s32 i = 0; i < 7; i++) s->w9092[i] = 0;
    for (s32 i = 0; i < 16; i++) s->w9120[i] = 0;
    for (s32 i = 0; i < 16; i++) s->w9204[i] = 0;
    s->f9360 = 0;
    P319* q = s->tail;
    for (s32 n = 9; n != -1; n--) {
        q->a = 0;
        q->b = 0;
        q++;
    }
}
}  // namespace n00319bd0

// 00319d20 (was src/anon/tiny_auto80.cpp)
namespace n00319d20 {
/*TARGET 00319d20*/
// 002e9fa8: moved to src/anon/unit_002e9a00.cpp

// 002eeee8: moved to src/anon/unit_002ee8a8.cpp

// 002eefa8: moved to src/anon/unit_002ee8a8.cpp

void func_00319d20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00319d20jjjj");
// 002e9fa8: moved to src/anon/unit_002e9a00.cpp

// 002eeee8: moved to src/anon/unit_002ee8a8.cpp

// 002eefa8: moved to src/anon/unit_002ee8a8.cpp

void func_00319d20(u32 a0, u32 a1, u32 a2, u32 a3) {  // zero_two_words
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u32*)((u32)r4 + (s32)(4)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(0)) = 0u;
}
}  // namespace n00319d20

// 00319d30 (was src/anon/tiny_auto80_queue.cpp)
namespace n00319d30 {
/*TARGET 00319d30*/
void func_00319d30(u32* a0) asm("_Z13func_00319d30Pj");
void func_00319d30(u32* a0) {
    s32 t7 = 3;
    do {
        *a0 = 0;
        t7 -= 1;
        a0 += 1;
    } while (t7 >= 0);
}
}  // namespace n00319d30

// 00319d58 (was src/anon/tiny_leaf.cpp)
namespace n00319d58 {
/*TARGET 00319d58*/
// 0x002f1ac8: definition moved into src/anon/unit_002f1a68.cpp

void func_00319d58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00319d58jjjj");
// 0x002f1ac8: definition moved into src/anon/unit_002f1a68.cpp

void func_00319d58(u32 a0, u32 a1, u32 a2, u32 a3) {  // store_zero_byte
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(u8*)((u32)r4 + (s32)(0)) = (u8)0u;
}
}  // namespace n00319d58

// 00319d60 (gap)
namespace n00319d60 {
/*TARGET 00319d60*/
void func_00319d60(u8* p) asm("func_00319d60");
void func_00319d60(u8* p) { *(u32*)(p + 16) = 0; }
}  // namespace n00319d60

// 00319d68 (was src/anon/batch_w57.cpp)
namespace n00319d68 {
extern void (**D_0032b914)() asm("D_0032b914");
struct E16 { u8 d[16]; ~E16() {} };
// 0x002bd788: definition moved into src/anon/unit_002bc978.cpp

// Destructor: tear down the layered members and chain to the base.
void func_00319f88(void*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
// big_obj_dtor
extern u8 D_00345c08 asm("D_00345c08");
extern u8 D_0034e8b8 asm("D_0034e8b8");
extern u8 D_0034ee08 asm("D_0034ee08");
struct G0 { u8* t; ~G0() { func_00319fb0(t); } };
struct G1 { u8* t; ~G1() { *(void**)t = &D_0034ee08; YS__OBJ_ATTACK__clear(t + 2568); func_001c0248(t + 2640); } };
struct G2 { u8* t; ~G2() { *(void**)t = &D_0034e8b8; func_00319f88(t + 2824); } };
struct B319 {
    void* vt;
    ~B319() {
        G0 g0 = { (u8*)this };
        G1 g1 = { (u8*)this };
        G2 g2 = { (u8*)this };
    }
};
struct C319 : B319 {
    u8 p[3184 - 4];
    E16 arr[6];
    ~C319() { vt = &D_00345c08; }
};
/*TARGET 00319d68*/
void func_00319d68(C319* t) asm("func_00319d68");
void func_00319d68(C319* t) { t->~C319(); }
}  // namespace n00319d68

// 00319df8 (was src/anon/batch_w1566.cpp)
namespace n00319df8 {
struct W1566E16 { u32 w[4]; };
extern u8 D_00345c08[] asm("D_00345c08");
extern u8 D_0034e8b8[] asm("D_0034e8b8");
extern u8 D_0034ee08[] asm("D_0034ee08");
void func_00319f88(void*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
void func_00105110(void*) asm("func_00105110");
/*TARGET 00319df8*/
// 002e98f0: static initialiser, now made by gcc in src/sugi/flare.cpp

// deleting destructor: three vtable levels, member array of 16-byte objects, then operator delete
void func_00319df8(u8* p) asm("func_00319df8");
// 002e98f0: static initialiser, now made by gcc in src/sugi/flare.cpp

// deleting destructor: three vtable levels, member array of 16-byte objects, then operator delete
void func_00319df8(u8* p) {
    *(void**)p = D_00345c08;
    if ((W1566E16*)(p + 3184)) {
        W1566E16* e = (W1566E16*)(p + 3280);
        for (;;) { if ((W1566E16*)(p + 3184) == e) break; e--; }
    }
    *(void**)p = D_0034e8b8;
    func_00319f88(p + 2824);
    *(void**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);
    func_001c0248(p + 2640);
    func_00319fb0(p);
    func_00105110(p);
}
}  // namespace n00319df8

// 00319e90 (was src/anon/batch_w2372_nsa.cpp)
namespace n00319e90 {
// 128-bit block copied with lq/sq (EE quadword move).
struct Q_w2372 {
    u32 w[4];
    Q_w2372& operator=(const Q_w2372& o) {
        asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Rec96_w2372 { u16 h0, h1, h2, h3; f32 f0, f1; };
struct Rec120_w2372 { u32 a, b; f32 c; };
struct Rec_w2372 {
    Q_w2372 q0, q1, q2, q3, q4, q5;
    Rec96_w2372 r96;
    u32 x, y;
    Rec120_w2372 r120;
};
#define R96(p) ((Rec96_w2372*)((u8*)(p) + 96))
#define R120(p) ((Rec120_w2372*)((u8*)(p) + 120))
/*TARGET 00319e90*/
// Copies one 132-byte record: six quadwords, then the scalar tail group by group.
void func_00319e90(Rec_w2372* d, Rec_w2372* s) asm("func_00319e90");
// Copies one 132-byte record: six quadwords, then the scalar tail group by group.
void func_00319e90(Rec_w2372* d, Rec_w2372* s) {
    d->q0 = s->q0; d->q1 = s->q1; d->q2 = s->q2; d->q3 = s->q3; d->q4 = s->q4; d->q5 = s->q5;
    {
        u16 h0 = R96(s)->h0, h1 = R96(s)->h1, h2 = R96(s)->h2, h3 = R96(s)->h3;
        f32 f0 = R96(s)->f0, f1 = R96(s)->f1;
        R96(d)->f0 = f0; R96(d)->h0 = h0; R96(d)->h1 = h1; R96(d)->h2 = h2; R96(d)->h3 = h3; R96(d)->f1 = f1;
    }
    *(u32*)((u8*)d + 112) = *(u32*)((u8*)s + 112);
    *(u32*)((u8*)d + 116) = *(u32*)((u8*)s + 116);
    R120(d)->a = R120(s)->a; R120(d)->b = R120(s)->b; R120(d)->c = R120(s)->c;
}
}  // namespace n00319e90

// 00319f48 (gap; copy of 0x00105a10, was src/common/unit_00319f48.cpp)
namespace n00319f48 {
/*TARGET 00319f48*/
void func_00319f48(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00319f48");
void func_00319f48(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00319f48

// 00319f50 (gap; copy of 0x0010f908, was src/anon/unit_0010f338.cpp)
namespace n00319f50 {
/*TARGET 00319f50*/
// 00292540: moved to src/anon/unit_00290f78.cpp
void func_00319f50(u8* p) asm("func_00319f50");
/*TARGET 00319f50*/
// 00292540: moved to src/anon/unit_00290f78.cpp
void func_00319f50(u8* p) asm("func_00319f50");
// 00292540: moved to src/anon/unit_00290f78.cpp
void func_00319f50(u8* p) { *(u32*)(p + 268) |= 0x300; }
}  // namespace n00319f50

// 00319f60 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00319f60 {
u32 func_00194468(u32, u32, u32, u32) asm("_Z13func_00194468jjjj");
/*TARGET 00319f60*/
u32 func_00319f60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00319f60jjjj");
u32 func_00319f60(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r13, r14;
    r13 = (u32)((s32)0u + (-257));
    r14 = *(u32*)((u32)r4 + (s32)(268));
    r14 = (u32)(r14 & r13);
    *(u32*)((u32)r4 + (s32)(268)) = r14;
    return func_00194468(r4, r5, r6, r7);
}
}  // namespace n00319f60

// 00319f88 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00319f88 {
extern u8 D_00350e60 asm("D_00350e60");
// 0x001a9798: definition moved into src/anon/unit_001a9130.cpp

u32 func_001b0188(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b0188jjjj");
/*TARGET 00319f88*/
u32 func_00319f88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00319f88jjjj");
u32 func_00319f88(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00350e60;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001b0188)(u32, u32, u32, u32) = func_001b0188;
    r2 = fp_call4_001b0188(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00319f88

// 00319fb0 (was src/anon/auto200_999.cpp)
namespace n00319fb0 {
void func_001b0188(u32) asm("_Z13func_001b0188j");
void func_001d5718(u32) asm("_Z13func_001d5718j");
void func_0016a358(u32) asm("_Z13func_0016a358j");
extern u32 D_003503e0 asm("D_003503e0");
extern u32 D_00350e48 asm("D_00350e48");
static inline u32 addr_D_003503e0() { return (u32)&D_003503e0; }
static inline u32 addr_D_00350e48() { return (u32)&D_00350e48; }
/*TARGET 00319fb0*/
void func_00319fb0(u32 self) asm("_Z13func_00319fb0j");
void func_00319fb0(u32 self) {  // big_obj_dtor
    u32 s18 = self;
    *(u32 *)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32 *)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}
}  // namespace n00319fb0

// 0031a030 (was src/anon/tiny_wrappers_more.cpp)
namespace n0031a030 {
u32 func_0019fa58(u32, u32, u32, u32) asm("_Z13func_0019fa58jjjj");
/*TARGET 0031a030*/
// 0x002f8b18: definition moved into src/newlib/libm/wf_log.c

u32 func_0031a030(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031a030jjjj");
// 0x002f8b18: definition moved into src/newlib/libm/wf_log.c

u32 func_0031a030(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0019fa58(((u32)(a0) + 2568u), a1, a2, a3);
}
}  // namespace n0031a030

// 0031a048 (was src/anon/tiny_wrappers_more.cpp)
namespace n0031a048 {
u32 func_0019fb48(u32, u32, u32, u32) asm("_Z13func_0019fb48jjjj");
/*TARGET 0031a048*/
u32 func_0031a048(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031a048jjjj");
u32 func_0031a048(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0019fb48(((u32)(a0) + 2568u), a1, a2, a3);
}
}  // namespace n0031a048

// 0031a060 (was src/anon/misc_3.cpp)
namespace n0031a060 {
/*TARGET 0031a060*/
// 0x003191e8: definition moved into src/libgcc/unwind-dw2.c

void func_0031a060(void* self) asm("_Z13func_0031a060Pv");
// 0x003191e8: definition moved into src/libgcc/unwind-dw2.c

void func_0031a060(void* self) {}
}  // namespace n0031a060

// 0031a068 (was src/anon/batch_w264.cpp)
namespace n0031a068 {
typedef unsigned int w264_u128 __attribute__((mode(TI)));
struct W264A52 { u32 w[13]; };
struct W264V192 { w264_u128 q[12]; };
struct W264D144 { u64 d[18]; } __attribute__((aligned(16)));
struct W264Blk {
    u32 vt;
    W264A52 a;
    u32 b;
    u32 c;
    W264V192 m;
    W264D144 n;
    u8 e;
    u32 f;
    u32 g;
};
/*TARGET 0031a068*/
// Colour/offset animation steps: four channel values from one curve, then per-channel deltas
// added onto the target (or a scratch sink). The memory barriers and pre-loaded next arguments
// reproduce the original's non-strict-aliasing ordering.

// Member-wise copy (skips the word at 0); the 16-byte rows copy as alias-set-0 block moves.
W264Blk* func_0031a068(W264Blk* d, W264Blk* s) asm("func_0031a068");
// Colour/offset animation steps: four channel values from one curve, then per-channel deltas
// added onto the target (or a scratch sink). The memory barriers and pre-loaded next arguments
// reproduce the original's non-strict-aliasing ordering.

// Member-wise copy (skips the word at 0); the 16-byte rows copy as alias-set-0 block moves.
W264Blk* func_0031a068(W264Blk* d, W264Blk* s)
{
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    __builtin_memcpy(&d->m.q[0], &s->m.q[0], 16);
    __builtin_memcpy(&d->m.q[1], &s->m.q[1], 16);
    __builtin_memcpy(&d->m.q[2], &s->m.q[2], 16);
    __builtin_memcpy(&d->m.q[3], &s->m.q[3], 16);
    __builtin_memcpy(&d->m.q[4], &s->m.q[4], 16);
    __builtin_memcpy(&d->m.q[5], &s->m.q[5], 16);
    __builtin_memcpy(&d->m.q[6], &s->m.q[6], 16);
    __builtin_memcpy(&d->m.q[7], &s->m.q[7], 16);
    __builtin_memcpy(&d->m.q[8], &s->m.q[8], 16);
    __builtin_memcpy(&d->m.q[9], &s->m.q[9], 16);
    __builtin_memcpy(&d->m.q[10], &s->m.q[10], 16);
    __builtin_memcpy(&d->m.q[11], &s->m.q[11], 16);
    d->n = s->n;
    d->e = s->e;
    d->f = s->f;
    d->g = s->g;
    return d;
}
}  // namespace n0031a068

// 0031a1a0 (was src/anon/batch_w81.cpp)
namespace n0031a1a0 {
// 0x002f1670: definition moved into src/anon/unit_002f12b0.cpp

// --- 0031a1a0: assignment operator (base fields, member at 24 via its operator=, tail fields)
struct Pr31a { u32 x, y; };
struct Obj31a {
    u32 vt;
    u32 a, b, c;
    Pr31a d;
    u8 sub[344];
    u32 f, g, h, i;
    f32 j;
    u32 k, l, m, n;
    u8 p, q;
};
void func_0031a850(u8*, u8*) asm("func_0031a850");
/*TARGET 0031a1a0*/
Obj31a* func_0031a1a0(Obj31a* d, Obj31a* s) asm("func_0031a1a0");
Obj31a* func_0031a1a0(Obj31a* d, Obj31a* s) {
    *(u32*)((u8*)d + 4) = *(u32*)((u8*)s + 4);
    *(u32*)((u8*)d + 8) = *(u32*)((u8*)s + 8);
    *(u32*)((u8*)d + 12) = *(u32*)((u8*)s + 12);
    d->d.x = s->d.x;
    d->d.y = s->d.y;
    func_0031a850(d->sub, s->sub);
    d->f = s->f;
    d->g = s->g;
    d->h = s->h;
    d->i = s->i;
    d->j = s->j;
    d->k = s->k;
    d->l = s->l;
    d->m = s->m;
    d->n = s->n;
    d->p = s->p;
    d->q = s->q;
    return d;
}
}  // namespace n0031a1a0

// 0031a260 (was src/anon/tiny_auto80_queue.cpp)
namespace n0031a260 {
void func_001396b0(...) asm("func_001396b0");
/*TARGET 0031a260*/
void func_0031a260(u8* s0, u32 a1) asm("func_0031a260");
void func_0031a260(u8* s0, u32 a1) {
    while (1) {
        *(u32*)(s0 + 0x18c) = a1;
        func_001396b0((u32)s0);
        if (*(u32*)(s0 + 0x18c) == 0) {
            break;
        }
        *(u32*)(s0 + 0x190) = 0;
        func_001396b0((u32)s0);
        if (*(u32*)(s0 + 0x190) == 0) {
            break;
        }
        a1 = 0;
    }
}
}  // namespace n0031a260

// 0031a2b0 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031a2b0 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031a2b0*/
// 0x002f7fe8: definition moved into src/sdk/libcdvd_002f77b0.c

u32 func_0031a2b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031a2b0jjjj");
// 0x002f7fe8: definition moved into src/sdk/libcdvd_002f77b0.c

u32 func_0031a2b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031a2b0

// 0031a2f0 (was src/anon/auto200_999.cpp)
namespace n0031a2f0 {
void func_00239870(u32) asm("_Z13func_00239870j");
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
/*TARGET 0031a2f0*/
// 0x002d0ef0: definition moved into src/anon/unit_002cf260.cpp

void func_0031a2f0(u32 self) asm("_Z13func_0031a2f0j");
// 0x002d0ef0: definition moved into src/anon/unit_002cf260.cpp

void func_0031a2f0(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}
}  // namespace n0031a2f0

// 0031a350 (was src/anon/batch_w65.cpp)
namespace n0031a350 {
void func_0031a838(void*) asm("func_0031a838");
// 002e9610: moved to src/sugi/flare.cpp

// 002ee730: moved to src/menu/tutorial_widget.cpp

extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347dd0[] asm("D_00347dd0");
extern u8 D_00347e80[] asm("D_00347e80");
void func_00239700(void*) asm("func_00239700");
void func_002361a0(void*) asm("func_002361a0");
/*TARGET 0031a350*/
void func_0031a350(u32* p) asm("func_0031a350");
void func_0031a350(u32* p) {
    p[0] = (u32)D_00347f98;
    func_0031a838(p + 3);
    p[0] = (u32)D_00347e60;
    func_00239700(p + 6);
    p[102] = 0;
    p[115] = 0;
    p[0] = (u32)D_00347dd0;
    p[112] = (u32)D_00347e80;
    func_002361a0(p + 120);
    p[224] = (u32)D_00347e60;
    p[227] = 0;
    func_00239700(p + 230);
}
}  // namespace n0031a350

// 0031a3d8 (was src/anon/batch_w56.cpp)
namespace n0031a3d8 {
// Local type whose non-trivial destructor keeps gcc from emitting a sibling call.
struct NoTail { ~NoTail() {} };
// 0x00313f40: definition moved into src/libgcc/_mul_df.c

// 0031a3d8 / 0031c248: destructor bodies (vtable resets, member and base teardown)
extern u8 D_00347dd0[] asm("D_00347dd0");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e80[] asm("D_00347e80");
void func_00239870(void*) asm("func_00239870");
void func_002361d0(void*) asm("func_002361d0");
void func_0031a840(void*) asm("func_0031a840");
/*TARGET 0031a3d8*/
void func_0031a3d8(u8* p) asm("func_0031a3d8");
void func_0031a3d8(u8* p)
{
    NoTail g;
    *(void**)p = D_00347dd0;
    *(void**)(p + 896) = D_00347e60;
    func_00239870(p + 920);
    *(void**)(p + 896) = D_00347f98;
    *(void**)(p + 448) = D_00347e80;
    func_002361d0(p + 480);
    *(void**)(p + 448) = D_00347f98;
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
}
}  // namespace n0031a3d8

// 0031a460 (was src/anon/batch_wcx.cpp)
namespace n0031a460 {
extern u8 D_00347dd0[] asm("D_00347dd0");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u32 D_00347f80 asm("D_00347f80");
void func_00239870(u8*) asm("func_00239870");
void func_002361d0(u8*) asm("func_002361d0");
void func_0031a840(u8*) asm("func_0031a840");
typedef void (*FreeFn)(u8*, u8*);
/*TARGET 0031a460*/
void func_0031a460(u8* p) asm("func_0031a460");
void func_0031a460(u8* p)
{
    *(void**)p = D_00347dd0;
    *(void**)(p + 896) = D_00347e60;
    func_00239870(p + 920);
    *(void**)(p + 896) = D_00347f98;
    *(void**)(p + 448) = D_00347e80;
    func_002361d0(p + 480);
    *(void**)(p + 448) = D_00347f98;
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
}  // namespace n0031a460

// 0031a508 (was src/anon/batch_w11.cpp)
namespace n0031a508 {
// 0x002f1a80: definition moved into src/anon/unit_002f1a68.cpp

extern u32 D_00347e60 asm("D_00347e60");
void func_00239870(void*) asm("func_00239870");
u8 func_0031a840(void*) asm("func_0031a840");
/*TARGET 0031a508*/
s32 func_0031a508(u8* p) asm("func_0031a508");
s32 func_0031a508(u8* p) {
    *(void**)p = &D_00347e60;
    func_00239870(p + 24);
    return func_0031a840(p);
}
}  // namespace n0031a508

// 0031a548 (was src/anon/batch_w24.cpp)
namespace n0031a548 {
// 0x00316d18: definition moved into src/newlib/libc/fputs.c

struct VObj { void** vt; };
struct Mgr20 { u8 _0[20]; VObj* o; };
extern Mgr20* D_00347f80m asm("D_00347f80");
extern void* D_00347e60[] asm("D_00347e60");
void func_00239870(u8*) asm("func_00239870");
void func_0031a840(u8*) asm("func_0031a840");
/*TARGET 0031a548*/
void func_0031a548(u8* p) asm("func_0031a548");
void func_0031a548(u8* p) {
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    VObj* o = D_00347f80m->o;
    ((void (*)(VObj*, u8*))o->vt[1])(o, p);
}
}  // namespace n0031a548

// 0031a5a0 (was src/anon/batch_w57.cpp)
namespace n0031a5a0 {
struct NoTail { ~NoTail() {} };
extern void (**D_0032b914)() asm("D_0032b914");
void func_00239870(void*) asm("func_00239870");
void func_002361d0(void*) asm("func_002361d0");
void func_0031a840(void*) asm("func_0031a840");
extern u8 D_00347d90 asm("D_00347d90");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
extern u8 D_00347e80 asm("D_00347e80");
/*TARGET 0031a5a0*/
void func_0031a5a0(u8* t) asm("func_0031a5a0");
void func_0031a5a0(u8* t) {
    NoTail g;
    *(void**)t = &D_00347d90;
    *(void**)(t + 896) = &D_00347e60;
    func_00239870(t + 920);
    *(void**)(t + 896) = &D_00347f98;
    *(void**)(t + 448) = &D_00347e80;
    func_002361d0(t + 480);
    *(void**)(t + 448) = &D_00347f98;
    *(void**)t = &D_00347e60;
    func_00239870(t + 24);
    func_0031a840(t);
}
}  // namespace n0031a5a0

// 0031a628 (was src/anon/batch_wcx.cpp)
namespace n0031a628 {
typedef void (*FreeFn)(u8*, u8*);
extern u8 D_00347d90[] asm("D_00347d90");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u32 D_00347f80 asm("D_00347f80");
void func_00239870(u8*) asm("func_00239870");
void func_002361d0(u8*) asm("func_002361d0");
void func_0031a840(u8*) asm("func_0031a840");
/*TARGET 0031a628*/
void func_0031a628(u8* p) asm("func_0031a628");
void func_0031a628(u8* p)
{
    *(void**)p = D_00347d90;
    *(void**)(p + 896) = D_00347e60;
    func_00239870(p + 920);
    *(void**)(p + 896) = D_00347f98;
    *(void**)(p + 448) = D_00347e80;
    func_002361d0(p + 480);
    *(void**)(p + 448) = D_00347f98;
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
}  // namespace n0031a628

// 0031a6d0 (was src/anon/batch_wcx2.cpp)
namespace n0031a6d0 {
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
// 0x00131e80: definition moved into src/anon/unit_00131418.cpp

// --------------------
struct A31a6d0 { u8 b[476]; };
struct B31a6d0 { u8 b[1328]; };
void func_0031a508(A31a6d0*) asm("func_0031a508");
void func_0031a3d8(B31a6d0*) asm("func_0031a3d8");
struct SB31a6d0 { u8 pad[16]; B31a6d0 b[8]; };
struct SA31a6d0 { u8 pad[8]; A31a6d0 a[16]; };
struct O31a6d0 { u32 vt; u8 pad[44]; SB31a6d0 sb; u8 pad2[4]; SA31a6d0 sa; };
static inline __attribute__((always_inline)) void DelA31a6d0(SA31a6d0* s)
{
    if (s->a != 0) {
        A31a6d0* p = s->a + 16;
        A31a6d0* b = s->a;
        for (;;) {
            if (b == p) break;
            --p;
            func_0031a508(p);
        }
    }
}
static inline __attribute__((always_inline)) void DelB31a6d0(SB31a6d0* s)
{
    if (s->b != 0) {
        B31a6d0* p = s->b + 8;
        B31a6d0* b = s->b;
        for (;;) {
            if (b == p) break;
            --p;
            func_0031a3d8(p);
        }
    }
}
struct AL31a6d0;
struct ALV31a6d0 { void* f0; void (*free)(AL31a6d0*, void*); };
struct AL31a6d0 { ALV31a6d0* vt; };
union G31a6d0 { u8* p; u32 u; };
extern G31a6d0 D_00347f80_31a6d0 asm("D_00347f80");
extern u8 D_00347d70_31a6d0[] asm("D_00347d70");
extern u8 D_00347f98_31a6d0[] asm("D_00347f98");
/*TARGET 0031a6d0*/
void func_0031a6d0(O31a6d0* o) asm("func_0031a6d0");
void func_0031a6d0(O31a6d0* o)
{
    o->vt = (u32)D_00347d70_31a6d0;
    DelA31a6d0(&o->sa);
    DelB31a6d0(&o->sb);
    o->vt = (u32)D_00347f98_31a6d0;
    AL31a6d0* al = *(AL31a6d0**)(D_00347f80_31a6d0.p + 20);
    al->vt->free(al, o);
}
}  // namespace n0031a6d0

// 0031a790 (was src/anon/batch_w230.cpp)
namespace n0031a790 {
/* 0031a790 */
extern char D_00347d70[] asm("D_00347d70");
extern char D_00347f98[] asm("D_00347f98");
void func_0031a508(void*) asm("func_0031a508");
void func_0031a3d8(void*) asm("func_0031a3d8");
/*TARGET 0031a790*/
void func_0031a790(char* t) asm("func_0031a790");
void func_0031a790(char* t) {
  *(char**)t = D_00347d70;
  if ((u32)(t + 10692) != 0xfffffff8u) {
    char* s0 = t + 18316;
    char* s1 = t + 10700;
    l1: if (s1 == s0) goto o1;
    s0 -= 476; func_0031a508(s0); goto l1;
  }
  o1:
  if ((u32)(t + 48) != 0xfffffff0u) {
    char* s0 = t + 10688;
    char* s1 = t + 64;
    l2: if (s1 == s0) goto o2;
    s0 -= 1328; func_0031a3d8(s0); goto l2;
  }
  o2:
  *(char**)t = D_00347f98;
}
}  // namespace n0031a790

// 0031a830 (was src/anon/misc_3.cpp)
namespace n0031a830 {
/*TARGET 0031a830*/
void func_0031a830(void* self) asm("_Z13func_0031a830Pv");
void func_0031a830(void* self) { *(s32*)((char*)self + 0) = 0; }
}  // namespace n0031a830

// 0031a838 (was src/global/misc.cpp)
namespace n0031a838 {
/*TARGET 0031a838*/
// 0x001e6af8: definition moved into src/anon/unit_001e0cb8.cpp

void ErrorRaise(void* self) asm("_Z10ErrorRaisePv");
// 0x001e6af8: definition moved into src/anon/unit_001e0cb8.cpp

void ErrorRaise(void* self) { reinterpret_cast<IntSlot*>(self)->value = 0; }
}  // namespace n0031a838

// 0031a840 (was src/anon/tiny.cpp)
namespace n0031a840 {
extern u32 D_00347f98 asm("D_00347f98");
/*TARGET 0031a840*/
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031a840(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031a840jjjj");
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031a840(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347f98;
}
}  // namespace n0031a840

// 0031a850 (was src/anon/batch_w1378.cpp)
namespace n0031a850 {
// 0031a850: assignment operator of a 0x158-byte object (base part via its own operator=,
// then the derived members). The 13 words at 0xb8 are copied through raw word pointers,
// which keeps their loads/stores in order (the two fields on each side are not).
struct Obj31a850Base {
    u8 base[0xb0];
};
struct Obj31a850 : Obj31a850Base {
    s32 mb0;
    s32 mb4;
    s32 work[13];
    s32 mec;
    s32 mf0;
    s32 mf4;
    s32 mf8;
    s32 mfc;
    f32 m100;
    f32 m104;
    f32 m108;
    s32 m10c;
    s32 m110;
    s32 m114;
    f32 m118;
    f32 m11c;
    f32 m120;
    f32 m124;
    f32 m128;
    f32 m12c;
    f32 m130;
    f32 m134;
    f32 m138;
    f32 m13c;
    s32 m140;
    s32 m144;
    s32 m148;
    s32 m14c;
    s32 m150;
    s32 m154;
};
void func_0031a9d8(Obj31a850*, Obj31a850*) asm("func_0031a9d8");
/*TARGET 0031a850*/
Obj31a850* func_0031a850(Obj31a850* d, Obj31a850* s) asm("func_0031a850");
Obj31a850* func_0031a850(Obj31a850* d, Obj31a850* s) {
    func_0031a9d8(d, s);
    d->mb0 = s->mb0;
    d->mb4 = s->mb4;
    ((s32*)d)[0x2e] = ((s32*)s)[0x2e];
    ((s32*)d)[0x2f] = ((s32*)s)[0x2f];
    ((s32*)d)[0x30] = ((s32*)s)[0x30];
    ((s32*)d)[0x31] = ((s32*)s)[0x31];
    ((s32*)d)[0x32] = ((s32*)s)[0x32];
    ((s32*)d)[0x33] = ((s32*)s)[0x33];
    ((s32*)d)[0x34] = ((s32*)s)[0x34];
    ((s32*)d)[0x35] = ((s32*)s)[0x35];
    ((s32*)d)[0x36] = ((s32*)s)[0x36];
    ((s32*)d)[0x37] = ((s32*)s)[0x37];
    ((s32*)d)[0x38] = ((s32*)s)[0x38];
    ((s32*)d)[0x39] = ((s32*)s)[0x39];
    ((s32*)d)[0x3a] = ((s32*)s)[0x3a];
    d->mec = s->mec;
    d->mf0 = s->mf0;
    d->mf4 = s->mf4;
    d->mf8 = s->mf8;
    d->mfc = s->mfc;
    d->m100 = s->m100;
    d->m104 = s->m104;
    d->m108 = s->m108;
    d->m10c = s->m10c;
    d->m110 = s->m110;
    d->m114 = s->m114;
    d->m118 = s->m118;
    d->m11c = s->m11c;
    d->m120 = s->m120;
    d->m124 = s->m124;
    d->m128 = s->m128;
    d->m12c = s->m12c;
    d->m130 = s->m130;
    d->m134 = s->m134;
    d->m138 = s->m138;
    d->m13c = s->m13c;
    d->m140 = s->m140;
    d->m144 = s->m144;
    d->m148 = s->m148;
    d->m14c = s->m14c;
    d->m150 = s->m150;
    d->m154 = s->m154;
    return d;
}
}  // namespace n0031a850

// 0031a9d8 (was src/anon/batch_w3739_nsa.cpp)
namespace n0031a9d8 {
// Built with -fno-strict-aliasing (_nsa).

/* 0031a9d8: out-of-line implicit operator= of a polymorphic 0xb0-byte class (vptr skipped).
   Levels up to 0x88 are copied by the inherited operator=; the last level copies a0/a8 first,
   then the rest. The empty asm with "m" inputs keeps the last group's loads after the a0/a8
   stores (no code emitted). */
struct P3 { s32 a, b, c; };
struct P6 { s32 v[6]; };
struct L1 { virtual void f(); s32 a04, a08, a0c; };
struct L2 : L1 { P3 p10, p1c, p28_; };
struct L3 : L2 { s32 b34, b38, b3c, b40; };
struct L4 : L3 { f32 c44, c48, c4c; };
struct L5 : L4 { P6 p50; };
struct M4_0 : L5 { s32 f68; f32 f6c; f32 f70; f32 f74; f32 f78; f32 f7c; f32 f80; f32 f84; s32 f88; };
struct C0031a9d8 : M4_0 { s32 f8c; s32 f90; s32 f94; s32 f98; s32 f9c; s32 fa0; s32 fa4; s32 fa8; s32 fac; };
/*TARGET 0031a9d8*/
C0031a9d8* func_0031a9d8(C0031a9d8* d, C0031a9d8* s) asm("func_0031a9d8");
C0031a9d8* func_0031a9d8(C0031a9d8* d, C0031a9d8* s) {
    *(M4_0*)d = *(M4_0*)s;
    s32 a0 = s->fa0, a8 = s->fa8; d->fa0 = a0; d->fa8 = a8;
    C0031a9d8* q; asm("" : "=r"(q) : "0"(s), "m"(d->fa0), "m"(d->fa8));
    s32 xac = q->fac, x90 = q->f90, x94 = q->f94, x98 = q->f98, x9c = q->f9c, xa4 = q->fa4, x8c = q->f8c;
    d->f8c = x8c; d->f90 = x90; d->f94 = x94; d->f98 = x98; d->f9c = x9c; d->fa4 = xa4; d->fac = xac;
    return d; }
}  // namespace n0031a9d8

// 0031ab38 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031ab38 {
u32 func_002361d0(u32, u32, u32, u32) asm("_Z13func_002361d0jjjj");
extern u8 D_00347e80 asm("D_00347e80");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031ab38*/
u32 func_0031ab38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031ab38jjjj");
u32 func_0031ab38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e80;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (32));
    r2 = func_002361d0(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031ab38

// 0031ab78 (was src/anon/batch_w41.cpp)
namespace n0031ab78 {
// 0x002dd2d8: definition moved into src/anon/unit_002da040.cpp

extern void* D_00347e80[] asm("D_00347e80");
extern void* D_00347f98[] asm("D_00347f98");
struct W41VS { void (**vt)(W41VS*, u8*); };
struct W41SysS { u8 pad[0x14]; W41VS* s; };
extern void* D_00347f80 asm("D_00347f80");
void func_002361d0(u8*) asm("func_002361d0");
/*TARGET 0031ab78*/
void func_0031ab78(u8* p) asm("func_0031ab78");
void func_0031ab78(u8* p) {
    *(void**)p = D_00347e80;
    func_002361d0(p + 32);
    *(void**)p = D_00347f98;
    W41VS* s = ((W41SysS*)D_00347f80)->s;
    s->vt[1](s, p);
}
}  // namespace n0031ab78

// 0031abd8 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031abd8 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031abd8*/
u32 func_0031abd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031abd8jjjj");
u32 func_0031abd8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031abd8

// 0031ac18 (was src/anon/auto200_999.cpp)
namespace n0031ac18 {
void func_00239870(u32) asm("_Z13func_00239870j");
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
/*TARGET 0031ac18*/
void func_0031ac18(u32 self) asm("_Z13func_0031ac18j");
void func_0031ac18(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}
}  // namespace n0031ac18

// 0031ac78 (was src/anon/tiny_auto80_queue.cpp)
namespace n0031ac78 {
void func_001396b0(...) asm("func_001396b0");
void func_0031a260(...) asm("func_0031a260");
/*TARGET 0031ac78*/
void func_0031ac78(u8* a0, u32 a1) asm("_Z13func_0031ac78Phj");
void func_0031ac78(u8* a0, u32 a1) {
    *(u32*)(a0 + 0x190) = a1;
    func_001396b0((u32)a0);
    if (*(u32*)(a0 + 0x190) != 0) {
        func_0031a260((u32)a0, 0);
    }
}
}  // namespace n0031ac78

// 0031acc0 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031acc0 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031acc0*/
u32 func_0031acc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031acc0jjjj");
u32 func_0031acc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031acc0

// 0031ad00 (was src/anon/auto200_999.cpp)
namespace n0031ad00 {
void func_00239870(u32) asm("_Z13func_00239870j");
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
/*TARGET 0031ad00*/
void func_0031ad00(u32 self) asm("_Z13func_0031ad00j");
void func_0031ad00(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}
}  // namespace n0031ad00

// 0031ad60 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031ad60 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031ad60*/
u32 func_0031ad60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031ad60jjjj");
u32 func_0031ad60(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031ad60

// 0031ada0 (was src/anon/auto200_999.cpp)
namespace n0031ada0 {
void func_00239870(u32) asm("_Z13func_00239870j");
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
/*TARGET 0031ada0*/
void func_0031ada0(u32 self) asm("_Z13func_0031ada0j");
void func_0031ada0(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}
}  // namespace n0031ada0

// 0031ae00 (was src/anon/tiny.cpp)
namespace n0031ae00 {
/*TARGET 0031ae00*/
// 0x003191f0: definition moved into src/libgcc/unwind-dw2.c

void func_0031ae00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031ae00jjjj");
// 0x003191f0: definition moved into src/libgcc/unwind-dw2.c

void func_0031ae00(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031ae00

// 0031ae08 (gap; copy of 0x0031a840, was src/anon/tiny.cpp)
namespace n0031ae08 {
extern u32 D_00347f98 asm("D_00347f98");
/*TARGET 0031ae08*/
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031ae08(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031ae08");
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031ae08(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347f98;
}
}  // namespace n0031ae08

// 0031ae18 (was src/anon/batch_w30.cpp)
namespace n0031ae18 {
extern void* D_00347f98[] asm("D_00347f98");
extern void** D_00347f80 asm("D_00347f80");
/*TARGET 0031ae18*/
// 0x003144b0: definition moved into src/libgcc/_df_to_sf.c

void func_0031ae18(void** p) asm("func_0031ae18");
// 0x003144b0: definition moved into src/libgcc/_df_to_sf.c

void func_0031ae18(void** p) {
    *p = D_00347f98;
    void** o = (void**)D_00347f80[5];
    (*(void (**)(void*, void*))((u8*)*o + 4))(o, p);
}
}  // namespace n0031ae18

// 0031ae58 (was src/anon/batch_wcx.cpp)
namespace n0031ae58 {
s32 func_00168aa0(u32, s32) asm("func_00168aa0");
u8* func_00168b38(u32, s32, s32) asm("func_00168b38");
/*TARGET 0031ae58*/
// entry_array_find_nth
void func_0031ae58(u32* p, u32 a) asm("func_0031ae58");
// entry_array_find_nth
void func_0031ae58(u32* p, u32 a)
{
    p[0] = a;
    s32 n = func_00168aa0(a, 25);
    p[1] = n;
    for (s32 i = 0; i < (s32)p[1]; i++) {
        u32* e = p + i * 2;
        e[3] = *(u32*)(func_00168b38(p[0], 25, i) + 8);  // entry_array_find_nth
        if (func_00168b38(p[0], 24, 0)) e[2] = *(u32*)(func_00168b38(p[0], 24, i) + 8);  // entry_array_find_nth
        else e[2] = 0;
    }
}
}  // namespace n0031ae58

// 0031af08 (gap; copy of 0x0031a2f0, was src/anon/auto200_999.cpp)
namespace n0031af08 {
void func_00239870(u32) asm("_Z13func_00239870j");
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
/*TARGET 0031af08*/
// 0x002d0ef0: definition moved into src/anon/unit_002cf260.cpp

void func_0031af08(u32 self) asm("func_0031af08");
// 0x002d0ef0: definition moved into src/anon/unit_002cf260.cpp

void func_0031af08(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}
}  // namespace n0031af08

// 0031af68 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0031af68 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 0031af68*/
u32 func_0031af68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031af68jjjj");
u32 func_0031af68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0031af68

// 0031afa8 (was src/anon/batch_w34.cpp)
namespace n0031afa8 {
void func_00239870(void*) asm("func_00239870");
extern void* D_003485b0[] asm("D_003485b0");
extern void* D_00347e60[] asm("D_00347e60");
extern void* D_00347f98[] asm("D_00347f98");
/*TARGET 0031afa8*/
// 0x002ed508: definition moved into src/anon/unit_002ecdb0.cpp

// 002ef708: moved to src/anon/unit_002ef6b0.cpp

// Region code: 'US', 'JP' or 'EU'.
// 002efbb8: moved to src/anon/unit_002efbb8.cpp

void func_0031afa8(void** p) asm("func_0031afa8");
// 0x002ed508: definition moved into src/anon/unit_002ecdb0.cpp

// 002ef708: moved to src/anon/unit_002ef6b0.cpp

// Region code: 'US', 'JP' or 'EU'.
// 002efbb8: moved to src/anon/unit_002efbb8.cpp

void func_0031afa8(void** p) {
    *p = D_003485b0;
    func_00239870((u8*)p + 436);
    *p = D_00347e60;
    func_00239870((u8*)p + 24);
    *p = D_00347f98;
}
}  // namespace n0031afa8

// 0031b000 (was src/anon/batch_w37.cpp)
namespace n0031b000 {
// 0x00316110: definition moved into src/libsupc++/tinfo.cpp

void func_00239870(void*) asm("func_00239870");
extern u8 D_003485b0[] asm("D_003485b0");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8* D_00347f80_p asm("D_00347f80");
typedef void (*VFn2)(void*, void*);
/*TARGET 0031b000*/
void func_0031b000(u8* p) asm("func_0031b000");
void func_0031b000(u8* p) {
    *(void**)p = D_003485b0;
    func_00239870(p + 436);
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    *(u8**)p = (u8*)D_00347f98;
    u8* o = *(u8**)(D_00347f80_p + 20);
    (*(VFn2*)(*(u8**)o + 4))(o, p);
}
}  // namespace n0031b000

// 0031b070 (was src/anon/batch_w24.cpp)
namespace n0031b070 {
extern void* D_00347e60[] asm("D_00347e60");
void func_00239870(u8*) asm("func_00239870");
extern void* D_00348590[] asm("D_00348590");
extern void* D_00347f98[] asm("D_00347f98");
/*TARGET 0031b070*/
void func_0031b070(u8* p) asm("func_0031b070");
void func_0031b070(u8* p) {
    *(void**)p = D_00348590;
    *(void**)(p + 260) = D_00347e60;
    func_00239870(p + 284);
    *(void**)(p + 260) = D_00347f98;
    *(void**)p = D_00347f98;
}
}  // namespace n0031b070

// 0031b0c0 (was src/anon/batch_w44.cpp)
namespace n0031b0c0 {
void func_00239870(void*) asm("func_00239870");
// 0x002eda90: definition moved into src/anon/unit_002ecdb0.cpp

// Constructor: primary and secondary vtables, then registers with the manager.
extern u8 D_00348590[] asm("D_00348590");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern void* D_00347f80 asm("D_00347f80");
/*TARGET 0031b0c0*/
void func_0031b0c0(u8* o) asm("func_0031b0c0");
void func_0031b0c0(u8* o) {
    *(void**)o = D_00348590;
    *(void**)(o + 260) = D_00347e60;
    func_00239870(o + 284);
    *(void**)(o + 260) = D_00347f98;
    *(void**)o = D_00347f98;
    void** m = *(void***)((u8*)D_00347f80 + 20);
    (*(void (**)(void*, void*))(*(u8**)m + 4))(m, o);
}
}  // namespace n0031b0c0

// 0031b130 (was src/anon/batch_w3715.cpp)
namespace n0031b130 {
// --------------------
// 0031b130: constructor of a big object (0x3cf0 bytes) built from many embedded
// sub-objects and arrays. Each element constructor is written out inline; vtables
// are stored as plain words (the classes' vtables live in the original binary).
//   Elem408 (vt 00347e60): word at +12 cleared, sub-object at +24 (func_00239700)
//   Elem848 : 00347f98 base (func_0031a838 at +12) -> 00347e60 -> 0034a800, YI::IMAGE at +416
//   Elem412 : same chain ending in vt 0034a958
//   Elem592 : 00347f98 base -> vt 00348658, sub-objects at +32 (func_0013ee88), +320 (func_0014b668)
void func_00239700(void*) asm("func_00239700");
void func_002361a0(void*) asm("func_002361a0");
void func_0031a838(void*) asm("func_0031a838");
void func_0013ee88(void*) asm("func_0013ee88");
void func_0014b668(void*) asm("func_0014b668");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00348608[] asm("D_00348608");
extern u8 D_0034a800[] asm("D_0034a800");
extern u8 D_0034a920[] asm("D_0034a920");
extern u8 D_0034a958[] asm("D_0034a958");
extern u8 D_00348678[] asm("D_00348678");
extern u8 D_00348658[] asm("D_00348658");
/*TARGET 0031b130*/
void dk__INFORMATION__openHiTimer(u8* t) asm("dk__INFORMATION__openHiTimer");
void dk__INFORMATION__openHiTimer(u8* t)
{
    *(u32*)(t + 64) = (u32)D_00347f98;
    *(u32*)t = (u32)D_00348608;
    *(u32*)(t + 12) = 0;
    func_0031a838(t + 76);
    *(u32*)(t + 64) = (u32)D_00347e60;
    func_00239700(t + 88);
    *(u32*)(t + 64) = (u32)D_0034a800;
    func_002361a0(t + 480);
    *(u32*)(t + 928) = 0;
    *(u32*)(t + 916) = (u32)D_00347e60;
    *(u32*)t = (u32)D_0034a920;
    func_00239700(t + 940);
    *(u32*)(t + 1336) = 0;
    *(u32*)(t + 1324) = (u32)D_00347e60;
    func_00239700(t + 1348);
    {
        u8* e = t + 1732;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 2548;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 3364;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 4180;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 5008;
        s32 i = 1;
        for (; i != -1; i--, e += 848) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_0034a800; func_002361a0(e + 416);
        }
    }
    {
        u8* e = t + 6704;
        s32 i = 14;
        for (; i != -1; i--, e += 412) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_0034a958;
        }
    }
    *(u32*)(t + 12908) = 0;
    *(u32*)(t + 12896) = (u32)D_00348678;
    {
        u8* e = t + 13232;
        s32 i = 3;
        func_0013ee88(t + 12928);
        // The original loads the loop bound right after this call, ahead of the vtable addresses.
        s32 n; asm volatile("li %0,-1" : "=r"(n));
        do {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00348658; func_0013ee88(e + 32);
            func_0014b668(e + 320);
            i--; e += 592;
        } while (i != n);
    }
}
}  // namespace n0031b130

// 0031b3b8 (was src/anon/batch_w92.cpp)
namespace n0031b3b8 {
void func_0031a838(u8*) asm("func_0031a838");
void func_00239700(u8*) asm("func_00239700");
void func_002361a0(u8*) asm("func_002361a0");
void func_0013ee88(u8*) asm("func_0013ee88");
void func_0014b668(u8*) asm("func_0014b668");
extern u8 D_00348608[] asm("D_00348608");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0034a800[] asm("D_0034a800");
extern u8 D_0034a848[] asm("D_0034a848");
extern u8 D_0034a958[] asm("D_0034a958");
extern u8 D_00348658[] asm("D_00348658");
/*TARGET 0031b3b8*/
void func_0031b3b8(u8* s) asm("func_0031b3b8");
void func_0031b3b8(u8* s) {
    *(u32*)(s + 12) = 0;
    *(u32*)s = (u32)D_00348608;
    *(u32*)(s + 64) = (u32)D_00347f98;
    func_0031a838(s + 76);
    *(u32*)(s + 64) = (u32)D_00347e60;
    func_00239700(s + 88);
    *(u32*)(s + 64) = (u32)D_0034a800;
    func_002361a0(s + 480);
    *(u32*)s = (u32)D_0034a848;
    u8* e = s + 916;
    for (s32 n = 3; n != -1; n--) {
        *(u32*)e = (u32)D_00347f98;
        func_0031a838(e + 12);
        *(u32*)e = (u32)D_00347e60;
        func_00239700(e + 24);
        *(u32*)e = (u32)D_0034a958;
        e += 412;
    }
    e = s + 2576;
    for (s32 n = 4; n != -1; n--) {
        *(u32*)e = (u32)D_00347f98;
        func_0031a838(e + 12);
        *(u32*)e = (u32)D_00348658;
        func_0013ee88(e + 32);
        func_0014b668(e + 320);
        e += 592;
    }
}
}  // namespace n0031b3b8

// 0031b4f0 (was src/anon/batch_w87.cpp)
namespace n0031b4f0 {
// 001ad638: moved to src/anon/unit_001abb28.cpp

// ---- 0x31b4f0: constructor (member arrays of 408-byte objects) ----
extern u8 D_0034a820[] asm("D_0034a820");
extern u8 D_00347e60[] asm("D_00347e60");
void func_00239700(void*) asm("func_00239700");
struct E408b { void* vt; u32 f4, f8, f12; u8 pad[8]; u8 sub[384]; };
/*TARGET 0031b4f0*/
void func_0031b4f0(u8* p) asm("func_0031b4f0");
void func_0031b4f0(u8* p) {
    *(u32*)(p + 12) = 0;
    *(void**)p = D_0034a820;
    E408b* e = (E408b*)(p + 48);
    for (s32 n = 5; n != -1; n--) {
        e->f12 = 0;
        e->vt = D_00347e60;
        func_00239700(e->sub);
        e++;
    }
    u8* row = p + 2496;
    for (s32 r = 15; r != -1; r--) {
        E408b* q = (E408b*)row;
        for (s32 n = 1; n != -1; n--) {
            q->f12 = 0;
            q->vt = D_00347e60;
            func_00239700(q->sub);
            q++;
        }
        row += 816;
    }
}
}  // namespace n0031b4f0

// 0031b5c8 (was src/anon/batch_w55.cpp)
namespace n0031b5c8 {
extern u8 D_0034a800[] asm("D_0034a800");
extern u8 D_00348608[] asm("D_00348608");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u32 D_00347f80 asm("D_00347f80");
void func_002361d0(u8*) asm("func_002361d0");
void func_00239870(u8*) asm("func_00239870");
/*TARGET 0031b5c8*/
// 0x00313e80: definition moved into src/libgcc/_addsub_df.c

void func_0031b5c8(u8* p) asm("func_0031b5c8");
// 0x00313e80: definition moved into src/libgcc/_addsub_df.c

void func_0031b5c8(u8* p) {
    *(u32*)p = (u32)D_00348608;
    *(u32*)(p + 64) = (u32)D_0034a800;
    func_002361d0(p + 480);
    *(u32*)(p + 64) = (u32)D_00347e60;
    func_00239870(p + 88);
    *(u32*)(p + 64) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    u8* o = *(u8**)(D_00347f80 + 20);
    (*(void (**)(void*, u8*))(*(u8**)o + 4))(o, p);
}
}  // namespace n0031b5c8

// 0031b648 (was src/anon/batch_w37.cpp)
namespace n0031b648 {
// 0x00316110: definition moved into src/libsupc++/tinfo.cpp

void func_00239870(void*) asm("func_00239870");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
void func_002361d0(void*) asm("func_002361d0");
extern u8 D_0034a800[] asm("D_0034a800");
extern u8 D_00348608[] asm("D_00348608");
/*TARGET 0031b648*/
void func_0031b648(u8* p) asm("func_0031b648");
void func_0031b648(u8* p) {
    *(void**)p = D_00348608;
    *(void**)(p + 64) = D_0034a800;
    func_002361d0(p + 480);
    *(void**)(p + 64) = D_00347e60;
    func_00239870(p + 88);
    *(void**)(p + 64) = D_00347f98;
    *(void**)p = D_00347f98;
}
}  // namespace n0031b648

// 0031b6b0 (gap; copy of 0x00105a10, was src/common/unit_0031b6b0.cpp)
namespace n0031b6b0 {
/*TARGET 0031b6b0*/
void func_0031b6b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031b6b0");
void func_0031b6b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031b6b0

// 0031b6b8 (gap; copy of 0x00105a10, was src/common/unit_0031b6b8.cpp)
namespace n0031b6b8 {
/*TARGET 0031b6b8*/
void func_0031b6b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031b6b8");
void func_0031b6b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031b6b8

// 0031b6c0 (gap; copy of 0x00105a10, was src/common/unit_0031b6c0.cpp)
namespace n0031b6c0 {
/*TARGET 0031b6c0*/
void func_0031b6c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031b6c0");
void func_0031b6c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031b6c0

// 0031b6c8 (gap; copy of 0x00105a10, was src/common/unit_0031b6c8.cpp)
namespace n0031b6c8 {
/*TARGET 0031b6c8*/
void func_0031b6c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031b6c8");
void func_0031b6c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031b6c8

// 0031b6d0 (gap; copy of 0x00105a10, was src/common/unit_0031b6d0.cpp)
namespace n0031b6d0 {
/*TARGET 0031b6d0*/
void func_0031b6d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031b6d0");
void func_0031b6d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031b6d0

// 0031b6d8 (gap)
namespace n0031b6d8 {
extern u8 D_00348698[] asm("D_00348698");
extern u8 D_00347f98[] asm("D_00347f98");
/*TARGET 0031b6d8*/
// Destructor: the member at +32 falls back to its base vtable, then the base vtable.
void func_0031b6d8(u8* p) asm("func_0031b6d8");
void func_0031b6d8(u8* p) {
    *(u8**)(p + 32) = D_00348698;
    *(u8**)p = D_00347f98;
}
}  // namespace n0031b6d8

// 0031b6f8 (gap)
namespace n0031b6f8 {
struct AVt { void* alloc; void (*free)(void* self, void* p); };
struct AO { AVt* vt; };
struct H { u8 pad[20]; AO* al; };
union HU { H* h; u32 u; };
extern HU D_00347f80 asm("D_00347f80");
extern u8 D_00348698[] asm("D_00348698");
extern u8 D_00347f98[] asm("D_00347f98");
/*TARGET 0031b6f8*/
// Deleting destructor of 0x31b6d8's class (frees through the allocator).
void func_0031b6f8(u8* p) asm("func_0031b6f8");
void func_0031b6f8(u8* p) {
    *(u8**)(p + 32) = D_00348698;
    *(u8**)p = D_00347f98;
    AO* al = D_00347f80.h->al;
    al->vt->free(al, p);
}
}  // namespace n0031b6f8

// 0031b748 (gap)
namespace n0031b748 {
extern u8 D_00348698[] asm("D_00348698");
extern u8 D_00347f98[] asm("D_00347f98");
/*TARGET 0031b748*/
void func_0031b748(u8* p) asm("func_0031b748");
void func_0031b748(u8* p) {
    *(u8**)(p + 320) = D_00348698;
    *(u8**)(p + 32) = D_00348698;
    *(u8**)p = D_00347f98;
}
}  // namespace n0031b748

// 0031b768 (gap)
namespace n0031b768 {
struct AVt { void* alloc; void (*free)(void* self, void* p); };
struct AO { AVt* vt; };
struct H { u8 pad[20]; AO* al; };
union HU { H* h; u32 u; };
extern HU D_00347f80 asm("D_00347f80");
extern u8 D_00348698[] asm("D_00348698");
extern u8 D_00347f98[] asm("D_00347f98");
/*TARGET 0031b768*/
void func_0031b768(u8* p) asm("func_0031b768");
void func_0031b768(u8* p) {
    *(u8**)(p + 320) = D_00348698;
    *(u8**)(p + 32) = D_00348698;
    *(u8**)p = D_00347f98;
    AO* al = D_00347f80.h->al;
    al->vt->free(al, p);
}
}  // namespace n0031b768

// 0031b7b8 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n0031b7b8 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031b7b8*/
void func_0031b7b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031b7b8");
void func_0031b7b8(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031b7b8

// 0031b7c8 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031b7c8 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031b7c8*/
// 0x00315608: definition moved into src/libsupc++/tinfo.cpp

u32 func_0031b7c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031b7c8jjjjjjjj");
// 0x00315608: definition moved into src/libsupc++/tinfo.cpp

u32 func_0031b7c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031b7c8

// 0031b7e8 (was src/anon/batch_w45.cpp)
namespace n0031b7e8 {
extern void* D_003486b0[] asm("D_003486b0");
extern void* D_00347e60[] asm("D_00347e60");
extern void* D_00347f98[] asm("D_00347f98");
void func_00239870(u8*) asm("func_00239870");
/*TARGET 0031b7e8*/
// 002eec58: moved to src/anon/unit_002ee8a8.cpp

// 002f0640: moved to src/anon/unit_002efd68.cpp

// destructor chain: three vtables, two embedded members
void func_0031b7e8(u8* a0) asm("func_0031b7e8");
// 002eec58: moved to src/anon/unit_002ee8a8.cpp

// 002f0640: moved to src/anon/unit_002efd68.cpp

// destructor chain: three vtables, two embedded members
void func_0031b7e8(u8* a0) {
    *(void**)a0 = D_003486b0;
    *(void**)(a0 + 448) = D_00347e60;
    func_00239870(a0 + 472);
    *(void**)a0 = D_00347e60;
    *(void**)(a0 + 448) = D_00347f98;
    func_00239870(a0 + 24);
    *(void**)a0 = D_00347f98;
}
}  // namespace n0031b7e8

// 0031b858 (was src/anon/batch_w58.cpp)
namespace n0031b858 {
struct VObj { void** vt; };
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
void func_00239870(void*) asm("func_00239870");
// 0x002ed4b8: definition moved into src/anon/unit_002ecdb0.cpp

// Destructor chain: own vtable, members, base parts, then unregister.
struct Mgr { u8 pad[20]; VObj* f20; };
extern u8 D_003486b0[] asm("D_003486b0");
extern union { Mgr* p; u8 c; } D_00347f80 asm("D_00347f80");
/*TARGET 0031b858*/
void func_0031b858(u8* p) asm("func_0031b858");
void func_0031b858(u8* p) {
    *(void**)p = D_003486b0;
    *(void**)(p + 448) = D_00347e60;
    func_00239870(p + 472);
    *(void**)p = D_00347e60;
    *(void**)(p + 448) = D_00347f98;
    func_00239870(p + 24);
    *(void**)p = D_00347f98;
    VObj* o = D_00347f80.p->f20;
    ((void (*)(void*, void*))o->vt[1])(o, p);
}
}  // namespace n0031b858

// 0031b8e0 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n0031b8e0 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031b8e0*/
void func_0031b8e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031b8e0");
void func_0031b8e0(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031b8e0

// 0031b8f0 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031b8f0 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031b8f0*/
u32 func_0031b8f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031b8f0jjjjjjjj");
u32 func_0031b8f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031b8f0

// 0031b910 (was src/anon/tiny.cpp)
namespace n0031b910 {
extern u32 D_00348698 asm("D_00348698");
/*TARGET 0031b910*/
void func_0031b910(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031b910jjjj");
void func_0031b910(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00348698;
}
}  // namespace n0031b910

// 0031b920 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0031b920 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00348698 asm("D_00348698");
/*TARGET 0031b920*/
u32 func_0031b920(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0031b920jjjjjjjj");
u32 func_0031b920(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00348698;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0031b920
