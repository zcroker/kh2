#include "../common/types.h"
#include "../yasui/libys/commandmenu.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"

// ---- 001bff88 from src/anon/batch_w212.cpp
namespace n001bff88 {
struct W212P { u32 a, b; void clr() { this->a = 0; this->b = 0; } };
extern u32 D_01d49328[8] asm("D_01d49328");
extern u32 D_01d49348 asm("D_01d49348");
extern u32 D_01d4934c asm("D_01d4934c");
extern W212P D_01d49350 asm("D_01d49350");
void func_001bff88() asm("func_001bff88");
void func_001bff88() {
    for (s32 i = 7; i >= 0; i--) D_01d49328[7 - i] = 0;
    D_01d4934c = 256;
    D_01d49348 = 0;
    D_01d49350.clr();
}
}  // namespace n001bff88

// ---- 001bffd8 from src/anon/batch_w53.cpp
namespace n001bffd8 {
extern u32 D_01d49328[] asm("D_01d49328");
extern s32 D_01d49348 asm("D_01d49348");
u32 func_001bffd8(void) asm("func_001bffd8");
u32 func_001bffd8(void) {
    for (s32 i = 0; i < 256; i++) {
        s32 c = (D_01d49348 + 1) % 255;
        D_01d49348 = c;
        u32 id = c + 1;
        u32* w = &D_01d49328[id >> 5];
        u32 m = 1 << (id & 31);
        if (!(*w & m)) {
            *w |= m;
            return id;
        }
    }
    return 0;
}
}  // namespace n001bffd8

// ---- 001c0058 from src/anon/tiny_auto80_solver.cpp
namespace n001c0058 {
extern u8 D_01d49328 asm("D_01d49328");
void func_001c0058(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001c0058jjjjjjjj");
void func_001c0058(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = a0 >> 5;
    u32 base = (u32)&D_01d49328;
    idx <<= 2;
    idx += base;
    a0 &= 31;
    u32 mask = 1;
    u32 val = *(u32*)idx;
    mask <<= a0;
    mask = ~mask;
    val &= mask;
    *(u32*)idx = val;
}
}  // namespace n001c0058

// ---- 001c0090 from src/anon/batch_w7.cpp
namespace n001c0090 {
extern s32 D_01d4934c asm("D_01d4934c");
s32 new_combo_group(void) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");
s32 new_combo_group(void) {
    if (++D_01d4934c > 0x10000000) D_01d4934c = 256;
    return D_01d4934c;
}
}  // namespace n001c0090

// ---- 001c00c0 gap
namespace n001c00c0 {
struct L_001c00c0 { u8* head; u8* tail; };
extern L_001c00c0 D_01d49350 asm("D_01d49350");
void func_001c00c0(u8* p, u32 a1) asm("func_001c00c0");
void func_001c00c0(u8* p, u32 a1) {
    *(u32*)p = a1;
    for (s32 i = 0; i < 8; i++) ((u32*)(p + 4))[i] = 0;
    *(u32*)(p + 36) = 0;
    *(u32*)(p + 40) = 0;
    *(u32*)(p + 44) = 0;
    u8* q = p + 48;
    for (s32 n = 3; n != -1; n--) { *(u32*)q = 0; q += 8; }
    L_001c00c0* l = &D_01d49350;
    if (!l->tail) {
        l->tail = p;
        l->head = p;
        *(u8**)(p + 80) = 0;
    } else {
        *(u8**)(l->tail + 80) = p;
        *(u8**)(p + 80) = 0;
        l->tail = p;
    }
}
}  // namespace n001c00c0

// ---- 001c0150 from src/anon/batch_wcx2.cpp
namespace n001c0150 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
struct L_001c0150 { u8* head; u8* tail; };
extern L_001c0150 D_01d49350 asm("D_01d49350");
void func_001c0150(u8* p, u32 a1) asm("func_001c0150");
void func_001c0150(u8* p, u32 a1) {
    *(u32*)p = a1;
    for (s32 i = 0; i < 8; i++) ((u32*)(p + 4))[i] = 0;
    *(u32*)(p + 36) = 0;
    *(u32*)(p + 40) = 0;
    *(u32*)(p + 44) = 0;
    u8* q = p + 48;
    for (s32 n = 3; n != -1; n--) { *(u32*)q = 0; q += 8; }
    L_001c0150* l = &D_01d49350;
    if (!l->tail) {
        l->tail = p;
        l->head = p;
        *(u8**)(p + 80) = 0;
    } else {
        *(u8**)(l->tail + 80) = p;
        *(u8**)(p + 80) = 0;
        l->tail = p;
    }
}
}  // namespace n001c0150

// ---- 001c01e0 gap
namespace n001c01e0 {
struct L_001c01e0 { u8* head; u8* tail; };
extern L_001c01e0 D_01d49350 asm("D_01d49350");
#define NX(o) (*(u8**)((o) + 80))
void func_001c01e0(u8* p) asm("func_001c01e0");
void func_001c01e0(u8* p) {
    u8* prev;
    if (p == D_01d49350.head) {
        D_01d49350.head = NX(p);
        prev = 0;
    } else {
        prev = D_01d49350.head;
        while (NX(prev) != p) prev = NX(prev);
        NX(prev) = NX(p);
    }
    if (p == D_01d49350.tail) D_01d49350.tail = prev;
    NX(p) = 0;
}
#undef NX
}  // namespace n001c01e0

// ---- 001c0248 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n001c0248 {
u32 func_00320828(u32, u32, u32, u32) asm("_Z13func_00320828jjjj");
extern u8 D_01d49350 asm("D_01d49350");
u32 func_001c0248(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c0248jjjj");
u32 func_001c0248(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00320828((u32)&D_01d49350, a0, a2, a3);
}
}  // namespace n001c0248

// ---- 001c0268 from src/anon/batch_w8.cpp
namespace n001c0268 {
u32 func_001c0268(u32* bits, u8* o) asm("func_001c0268");
u32 func_001c0268(u32* bits, u8* o) {
    u32 b = *(u32*)(o + 28);
    bits += b >> 5;
    return (bits[1] & (1 << (b & 31))) == 0;
}
}  // namespace n001c0268

// ---- 001c0298 from src/anon/batch_w56.cpp
namespace n001c0298 {
inline bool is_kind_5_or_6(u8 v) { return (u8)(v - 5) < 2; }
s32 func_001c0298(u8* a, u8* b) asm("func_001c0298");
s32 func_001c0298(u8* a, u8* b)
{
    if (is_kind_5_or_6(*(*(u8**)(b + 40) + 4))) return 1;
    u32 k = *(u32*)(b + 28);
    u32* bits = (u32*)(a + 4);
    if (bits[k >> 5] & (1 << (k & 31))) return 0;
    s32 c = *(s32*)(b + 32);
    if (c == *(s32*)(a + 36) || c == 255) return 1;
    if (0.0f < *(f32*)(a + 44)) return 0;
    return 1;
}
}  // namespace n001c0298

// ---- 001c0320 from src/anon/batch_w84.cpp
namespace n001c0320 {
u8 func_001c0298(u8*, u8*, u8*) asm("func_001c0298");
u8* func_0019fee8(u32, u32) asm("func_0019fee8");
void func_001c0410(u8*, u8*, u8*) asm("func_001c0410");
static inline void SetBit(u32* bits, u32 k) {
    u32* w = bits + (k >> 5);
    *w |= 1 << (k & 31);
}
u8* YS__ATTACK_CHECK__hit(u8* a, u8* b, u8* out) asm("YS__ATTACK_CHECK__hit");
u8* YS__ATTACK_CHECK__hit(u8* a, u8* b, u8* out) {
    u8 r = func_001c0298(a, b, out);
    *out = r;
    if (r) {
        if (*(u32*)(b + 32) != *(u32*)(a + 36)) {
            *(u32*)(a + 36) = *(u32*)(b + 32);
            *(u32*)(a + 40) = 0;
        } else {
            (*(u32*)(a + 40))++;
        }
        if (*(u8**)a && (*(u32*)(*(u8**)a + 1416) & 4)) *(f32*)(a + 44) = 30.0f;
    }
    u8* v = func_0019fee8(*(u32*)(b + 40), *(u32*)(a + 40));
    if (*(u16*)(v + 38)) func_001c0410(a, b, v);
    SetBit((u32*)(a + 4), *(u32*)(b + 28));
    return v;
}
}  // namespace n001c0320

// ---- 001c0410 from src/anon/batch_w1736.cpp
namespace n001c0410 {
struct w1736_S1 { u8 pad[0x1c]; s32 x1c; };
struct w1736_S2 { u8 pad[0x26]; union { u16 h26; u8 b; }; };
struct w1736_E { s32 x30; f32 f34; };
struct w1736_S0 { u8 pad[0x30]; w1736_E e[4]; };
void func_001c0410(w1736_S0* a, w1736_S1* b, w1736_S2* c) asm("func_001c0410");
void func_001c0410(w1736_S0* a, w1736_S1* b, w1736_S2* c) {
    for (s32 i = 0; i < 4; i++) {
        if (a->e[i].x30 == 0) {
            a->e[i].x30 = b->x1c;
            a->e[i].f34 = c->h26;
            return;
        }
    }
}
}  // namespace n001c0410

// ---- 001c0458 from src/anon/batch_w22.cpp
namespace n001c0458 {
void func_001c0458(u8* bits, u8* o) asm("func_001c0458");
void func_001c0458(u8* bits, u8* o) {
    u32 i = *(u32*)(o + 28);
    u32* w = (u32*)(bits + 4);
    w += i >> 5;
    *w &= ~(1 << (i & 31));
}
}  // namespace n001c0458

// ---- 001c0490 from src/anon/batch_w80.cpp
namespace n001c0490 {
struct U3_Tmr { u32 id; f32 t; };
struct U3_TmrSet { u32 f0; u32 bits[10]; f32 f44; U3_Tmr tm[4]; };
extern union { f32 f; u32 u; } U3_D_00349e10_u asm("D_00349e10");
extern f32 D_00349e10 asm("D_00349e10");
s32 YS__BTLOBJ__is_damage_motion(u32) asm("YS__BTLOBJ__is_damage_motion");
void func_001c0490(U3_TmrSet* s) asm("func_001c0490");
void func_001c0490(U3_TmrSet* s) {
    s32 i;
    if (s->f44 > 0.0f) {
        if (!s->f0 || !YS__BTLOBJ__is_damage_motion(s->f0)) s->f44 -= D_00349e10;
    }
    U3_Tmr* t = s->tm;
    u32* bits = s->bits;
    for (i = 0; i < 4; i++, t++) {
        if (t->id) {
            t->t -= U3_D_00349e10_u.f;
            if (t->t <= 0.0f) {
                u32* w = &bits[t->id >> 5];
                *w &= ~(1 << (t->id & 31));
                t->id = 0;
            }
        }
    }
}
}  // namespace n001c0490

// ---- 001c0560 from src/anon/batch_w24.cpp
namespace n001c0560 {
struct N80 { u8 _0[80]; N80* next; };
extern N80* D_01d49350 asm("D_01d49350");
void func_001c0490(N80*) asm("func_001c0490");
void func_001c0560(void) asm("func_001c0560");
void func_001c0560(void) {
    N80* n = 0;
    while ((n = !n ? *(N80* volatile*)&D_01d49350 : n->next) != 0) func_001c0490(n);
}
}  // namespace n001c0560

// ---- 001c05b0 from src/anon/batch_w49.cpp
namespace n001c05b0 {
void wtarget_001c05b0(u32, u32, u32, u32) asm("_Z16wtarget_001c05b0jjjj");
extern u32 D_01d49328[8] asm("D_01d49328");
struct S1d49350 { u32 a, b; };
extern S1d49350 D_01d49350 asm("D_01d49350");
void wtarget_001c05b0(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        u32* p = D_01d49328;
        for (s32 i = 7; i >= 0; i--) *p++ = 0;
    }
    if (b == 0xffff && a == 1) {
        D_01d49350.a = 0;
        D_01d49350.b = 0;
    }
}
}  // namespace n001c05b0

// ---- 001c0618 from src/anon/tiny_wrappers_more.cpp
namespace n001c0618 {
u32 func_001c05b0(u32, u32, u32, u32) asm("_Z13func_001c05b0jjjj");
u32 func_001c0618(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c0618jjjj");
u32 func_001c0618(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c05b0(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001c0618

