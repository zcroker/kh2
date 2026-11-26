// File 0x188848-0x189d38: party/form RAM helpers, the event-table setup and its two command
// callbacks (0x1892d8, 0x189740). Functions marked "gap" were never written before.
// One namespace per old source function.
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../yasui/libys/npc.hpp"

// ---- 00188848 gap: C2 copy of the constructor body at 0x1888c8 (same code, never written before)
namespace n00188848 {
void func_00114580(u8*) asm("func_00114580");
void func_00188848(u8* p) asm("func_00188848");
void func_00188848(u8* p) {
    p[4] = 100;
    p[5] = 100;
    p[6] = 100;
    p[7] = 100;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 1;
    p[16] = 1;
    p[17] = 1;
    p[18] = 0;
    u16* h = (u16*)(p + 84);
    for (s32 i = 79; i != -1; i--) *h++ = 0;
    func_00114580(p + 244);
}
}  // namespace n00188848

// ---- 001888c8 from src/anon/batch_w58.cpp
namespace n001888c8 {
void func_00114580(u8*) asm("func_00114580");
void func_001888c8(u8* p) asm("func_001888c8");
void func_001888c8(u8* p) {
    p[4] = 100;
    p[5] = 100;
    p[6] = 100;
    p[7] = 100;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 1;
    p[16] = 1;
    p[17] = 1;
    p[18] = 0;
    u16* h = (u16*)(p + 84);
    for (s32 i = 79; i != -1; i--) *h++ = 0;
    func_00114580(p + 244);
}
}  // namespace n001888c8

// ---- 00188948 from src/anon/tiny_leaf.cpp
namespace n00188948 {
void func_00188948(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00188948jjjj");
void func_00188948(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(u16*)((u32)r4 + (s32)(0)) = (u16)r5;
    *(u16*)((u32)r4 + (s32)(2)) = (u16)r6;
}
}  // namespace n00188948

// ---- 00188958 from src/anon/batch_w89.cpp
namespace n00188958 {
struct O9 { u8 pad[18]; u8 count; u8 pad2[33]; u16 a[8]; u16 b[8]; };
void func_001a3188(u32, u32, u32) asm("func_001a3188");
void func_00188958(O9* o, s32 n) asm("func_00188958");
void func_00188958(O9* o, s32 n) {
    s32 i;
    if (o->count < n) {
        for (i = o->count; i < n; i++) {
            o->a[i] = 0;
            o->b[i] = 0;
        }
    } else {
        for (i = n; i < o->count; i++) {
            if (o->a[i]) {
                func_001a3188(o->a[i], 100, 0);
                o->a[i] = 0;
            }
        }
    }
    o->count = n;
}
}  // namespace n00188958

// ---- 00188a28 from src/anon/batch_w58.cpp
namespace n00188a28 {
struct S188 { u8 pad[18]; u8 n; u8 pad2[33]; u16 a[8]; u16 b[8]; };
void func_00188a28(S188* p, u32 v) asm("func_00188a28");
void func_00188a28(S188* p, u32 v) {
    s32 i, j;
    for (i = 0; i < p->n; i++) {
        if (p->a[i] == 0) {
            if (p->b[i] == v) { p->a[i] = v; return; }
            if (p->b[i] == 0) {
                for (j = 0; j < p->n; j++) {
                    if (p->b[j] == v) { p->b[i] = v; break; }
                }
                p->a[i] = v;
                return;
            }
        }
    }
}
}  // namespace n00188a28

// ---- 00188ac8 from src/anon/batch_w59.cpp
namespace n00188ac8 {
s32 func_001a3570(u16) asm("func_001a3570");
void func_001a34e0(u16, u32) asm("func_001a34e0");
struct S188 { u8 pad[18]; bool n; };
void func_00188ac8(S188* p) asm("func_00188ac8");
void func_00188ac8(S188* p) {
    s32 i;
    for (i = 0; i < p->n; i++) {
        u16* e = (u16*)((u8*)p + i * 2);
        if (e[34] && !e[26]) {
            if (func_001a3570(e[34]) <= 0) continue;
            func_001a34e0(e[34], 1);
            e[26] = e[34];
        }
    }
}
}  // namespace n00188ac8

// ---- 00188b68 from src/anon/batch_w35.cpp
namespace n00188b68 {
struct AbilitySlot { u16 id : 15; u16 on : 1; };
void partram_add_ability(u8* self, s32 id, u8 on) asm("_ZN2YS7PARTRAM11add_abilityEib");
void partram_add_ability(u8* self, s32 id, u8 on) {
    AbilitySlot* a = (AbilitySlot*)(self + 80);
    for (s32 i = 0; i < 80; i++) {
        if (a[i + 2].id == 0) {
            AbilitySlot x;
            x.id = id;
            x.on = on != 0;
            a[i + 2] = x;
            return;
        }
    }
}
}  // namespace n00188b68

// ---- 00188bb0 from src/anon/batch_w58.cpp
namespace n00188bb0 {
u32* func_001b6fb0(u32, u32) asm("func_001b6fb0");
extern u32 D_0032f210 asm("D_0032f210");
s32 func_00188bb0(u8* p, u32 a) asm("func_00188bb0");
s32 func_00188bb0(u8* p, u32 a) {
    u8 n = p[15];
    if (n >= 99) return 0;
    return *func_001b6fb0(a, n) - D_0032f210;
}
}  // namespace n00188bb0

// ---- 00188bf8 from src/anon/tiny_auto80_fptr4.cpp
namespace n00188bf8 {
void func_00188bf8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00188bf8jjjj");
void func_00188bf8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r14 = (u32)(*(u16*)((u32)r4 + (s32)(0)));
    r15 = (u32)(0x0033u << 16);
    *(u16*)((u32)r15 + (s32)(-1254)) = (u16)r14;
    *(u16*)((u32)r4 + (s32)(0)) = (u16)r5;
}
}  // namespace n00188bf8

// ---- 00188c10 from src/anon/tiny_auto80_solver.cpp
namespace n00188c10 {
extern u8 D_0032bb30 asm("D_0032bb30");
void func_00188c10(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00188c10jjjjjjjj");
void func_00188c10(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r13, r14, r15;
    r13 = (u32)&D_0032bb30;
    r14 = (u32)((s32)0u + (41));    r15 = (u32)(*(u16*)((u32)r13 + (s32)(16362)));
    if (r15 == 0u) r15 = r14;
    *(u16*)((u32)r4 + (s32)(0)) = (u16)r15;
    *(u16*)((u32)r13 + (s32)(16362)) = (u16)0u;
}
}  // namespace n00188c10

// ---- 00188c30 from src/anon/batch_w293.cpp
namespace n00188c30 {
inline void* operator new[](unsigned int, void* p) { return p; }
inline void* operator new(unsigned int, void* p) { return p; }
void func_001888c8(void*) asm("func_001888c8");
void func_00189170(void*) asm("func_00189170");
void func_001a8bb8(void*) asm("func_001a8bb8");
void func_001d9768(void*) asm("func_001d9768");
struct A276 { u8 d[276]; A276() { func_001888c8(this); } };
struct A56 { u8 d[56]; A56() { func_00189170(this); } };
struct A4 { u8 d[4]; A4() { func_001a8bb8(this); } };
struct Z4 { u32 v; Z4() { v = 0; } };
struct Z8 { u8 a; u32 b; Z8() { a = 0; b = 0; } };
struct E { Z8 e[64]; u32 x[4]; E() __attribute__((always_inline)); };
inline E::E() { for (s32 i = 0; i < 4; i++) x[i] = 0; }
void func_00188c30(u8* p) asm("func_00188c30");
void func_00188c30(u8* p)
{
    new (p) A276[13];
    new (p + 3588) A56[10];
    p[4148] = 0;
    p[4149] = 0;
    p[4150] = 1;
    p[4152] = 100;
    p[4153] = 3;
    p[4154] = 3;
    new (p + 4164) A4[19];
    for (s32 i = 0; i < 8; i++) ((u32*)(p + 4560))[i] = 0;
    *(u32*)(p + 4592) = 0;
    for (s32 i = 0; i < 8; i++) ((u32*)(p + 4628))[i] = 0;
    for (s32 i = 0; i < 8; i++) ((u32*)(p + 4660))[i] = 0;
    *(u32*)(p + 4692) = 0;
    for (s32 i = 0; i < 10; i++) ((u32*)(p + 6296))[i] = 0;
    new (p + 6340) E;
    func_001d9768(p + 6878);
    *(s16*)(p + 6906) = 0;
    for (s32 i = 0; i < 4; i++) ((s16*)(p + 4616))[i] = 0;
}
}  // namespace n00188c30

// ---- 00188e08 from src/anon/batch_w111.cpp
namespace n00188e08 {
struct E18a { u8 b[276]; };
struct E18b { u8 b[56]; };
struct E18c { u8 b[4]; };
struct E18d { u8 on; u8 pad[3]; s32 v; };
struct Obj18 {
    E18a a[13]; u8 pad0[0]; E18b b[10]; u8 pad1[0];
    u8 c4148, c4149, c4150, c4151, c4152, c4153, c4154; u8 pad2[9];
    E18c c[19]; u8 pad3[320]; s32 w4560[8]; s32 w4592; u8 pad4[20]; s16 h4616[4]; u8 pad5[4];
    s32 w4628[8]; s32 w4660[8]; s32 w4692; u8 pad6[1600]; s32 w6296[10]; u8 pad7[4];
    E18d d[64]; u8 sub6852[26]; u8 sub6878[28]; s16 h6906;
};
void func_001888c8(E18a*) asm("func_001888c8");
void func_00189170(E18b*) asm("func_00189170");
void func_001a8bb8(E18c*) asm("func_001a8bb8");
void func_00319d30(void*) asm("func_00319d30");
void func_001d9768(void*) asm("func_001d9768");
void func_00188e08(Obj18* o) asm("func_00188e08");
void func_00188e08(Obj18* o)
{
    {
        E18a* p = o->a;
        s32 n = 12;
        do { func_001888c8(p); p++; } while (--n != -1);
    }
    {
        E18b* p = o->b;
        s32 n = 9;
        do { func_00189170(p); p++; } while (--n != -1);
    }
    o->c4148 = 0;
    o->c4150 = 1;
    o->c4152 = 100;
    o->c4149 = 0;
    o->c4153 = 3;
    o->c4154 = 3;
    {
        E18c* p = o->c;
        s32 n = 18;
        do { func_001a8bb8(p); p++; } while (--n != -1);
    }
    s32 i;
    for (i = 0; i < 8; i++) o->w4560[i] = 0;
    o->w4592 = 0;
    for (i = 0; i < 8; i++) o->w4628[i] = 0;
    for (i = 0; i < 8; i++) o->w4660[i] = 0;
    o->w4692 = 0;
    for (i = 0; i < 10; i++) o->w6296[i] = 0;
    E18d* d = o->d;
    {
        E18d* p = d;
        s32 n = 63;
        do { p->on = 0; p->v = 0; p++; } while (--n != -1);
    }
    func_00319d30(d + 64);
    func_001d9768(o->sub6878);
    o->h6906 = 0;
    for (i = 0; i < 4; i++) o->h4616[i] = 0;
}
}  // namespace n00188e08

// ---- 00188fc0 from src/anon/tiny_auto80.cpp
namespace n00188fc0 {
u32 func_001c2eb8(u32, u32, u32, u32) asm("_Z13func_001c2eb8jjjj");
u32 func_001b87b0() asm("_Z13func_001b87b0v");
u32 func_00188fc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00188fc0jjjj");
u32 func_00188fc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = 0u;
    r2 = func_001c2eb8(r4, r5, r6, r7);
    return func_001b87b0();
}
}  // namespace n00188fc0

// ---- 00188fe0 from src/anon/batch_w61.cpp
namespace n00188fe0 {
u32 ctarget_00188fe0(u32, u32, u32, u32) asm("_Z16ctarget_00188fe0jjjj");
u32 func_001b7818(u32) asm("func_001b7818");
u32 ctarget_00188fe0(u32 a0, u32 a1, u32, u32) {
    u32 v = func_001b7818(a1);
    if (v) return a0 + v * 276 - 276;
    return 0;
}
}  // namespace n00188fe0

// ---- 00189028 from src/anon/batch_w14.cpp
namespace n00189028 {
void* func_00188fe0(void*, void*) asm("func_00188fe0");
void func_00188948(void*, void*, void*) asm("func_00188948");
void func_00189028(void* a, void* b, void* c, void* d) asm("func_00189028");
void func_00189028(void* a, void* b, void* c, void* d) {
    func_00188948(func_00188fe0(a, b), c, d);
}
}  // namespace n00189028

// ---- 00189068 from src/anon/tiny_auto80_queue.cpp
namespace n00189068 {
u32 func_00189068(u32 a0, u32 a1) asm("_Z13func_00189068jj");
u32 func_00189068(u32 a0, u32 a1) {
    u32 t5 = (u32)((s32)a1 + (-3000));
    a1 = (u32)((s32)a1 + (-1000));
    register u32 t6 asm("$14") = (u32)((u32)t5 < 12u);
    register u32 t7 asm("$15") = (u32)(a1 << 2);
    t7 = (u32)(a0 + t7);
    a1 = (u32)((u32)a1 < 72u);
    if (a1 != 0u) goto Lret1;
    if (t6 == 0u) goto Lret0;
    t7 = (u32)(t5 << 2);
    t7 = (u32)(a0 + t7);
    return (u32)((s32)t7 + (5080));
Lret0:
    return 0u;
Lret1:
    return (u32)((s32)t7 + (4696));
}
}  // namespace n00189068

// ---- 001890a8 from src/anon/batch_w40.cpp
namespace n001890a8 {
s32 func_00181a70(u32, u32) asm("func_00181a70");
u32* func_00189068(u32, u32) asm("func_00189068");
void func_001890a8(u32 a, u32 b) asm("func_001890a8");
void func_001890a8(u32 a, u32 b) {
    if (func_00181a70(a, b)) {
        u32* c = func_00189068(a, b);
        if (c && *c < 9999) (*c)++;
    }
}
}  // namespace n001890a8

// ---- 00189108 from src/anon/tiny_jal_wrappers.cpp
namespace n00189108 {
u32 func_00189068(u32, u32, u32, u32) asm("_Z13func_00189068jjjj");
u32 func_00189108(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00189108jjjj");
u32 func_00189108(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00189068(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(0));
    return r2;
}
}  // namespace n00189108

// ---- 00189128 gap: C2 copy of 0x189170 (never written before)
namespace n00189128 {
void func_00189128(u32 a0) asm("func_00189128");
void func_00189128(u32 a0) {
    u32 t7 = (u32)1;
    *(u16*)((u32)a0 + (s32)(0)) = (u16)0u;
    *(volatile u8*)((u32)a0 + (s32)(3)) = (u8)t7;
    register u32 t6 asm("$14") = (u32)((s32)a0 + (8));
    *(u8*)((u32)a0 + (s32)(2)) = (u8)t7;
    register u32 t5 asm("$13") = (u32)23;
    *(volatile u32*)((u32)a0 + (s32)(4)) = 0u;
    t7 = (u32)-1;
    do {
        *(u16*)((u32)t6 + (s32)(0)) = (u16)0u;
        t5 = (u32)((s32)t5 + (-1));
        if (t5 == t7) {
            break;
        }
        t6 = (u32)((s32)t6 + (2));
    } while (1);
}
}  // namespace n00189128

// ---- 00189170 from src/anon/tiny_auto80_queue.cpp
namespace n00189170 {
void func_00189170(u32 a0) asm("_Z13func_00189170j");
void func_00189170(u32 a0) {
    u32 t7 = (u32)1;
    *(u16*)((u32)a0 + (s32)(0)) = (u16)0u;
    *(volatile u8*)((u32)a0 + (s32)(3)) = (u8)t7;
    register u32 t6 asm("$14") = (u32)((s32)a0 + (8));
    *(u8*)((u32)a0 + (s32)(2)) = (u8)t7;
    register u32 t5 asm("$13") = (u32)23;
    *(volatile u32*)((u32)a0 + (s32)(4)) = 0u;
    t7 = (u32)-1;
    do {
        *(u16*)((u32)t6 + (s32)(0)) = (u16)0u;
        t5 = (u32)((s32)t5 + (-1));
        if (t5 == t7) {
            break;
        }
        t6 = (u32)((s32)t6 + (2));
    } while (1);
}
}  // namespace n00189170

// ---- 001891b8 from src/anon/batch_w24.cpp
namespace n001891b8 {
struct FormRam { u8 _0[8]; u16 ab[24]; };
void formram_set_ability(FormRam*, int) asm("_ZN2YS7FORMRAM11set_abilityEi");
void formram_set_ability(FormRam* self, int id) {
    id &= 0x7fff;
    for (s32 i = 0; i < 24; i++) {
        u16 v = self->ab[i];
        if ((v & 0x7fff) == 0) {
            self->ab[i] = (v & 0x8000) | id | 0x8000;
            return;
        }
    }
}
}  // namespace n001891b8

// ---- 00189200 from src/anon/auto200_999.cpp
namespace n00189200 {
u32 ctarget_00189200(u32 a0, u32 a1, u32, u32) asm("_Z16ctarget_00189200jjjj");
u32 ctarget_00189200(u32 a0, u32 a1, u32, u32) {
    if (a1 - 1 < 10) {
        return a0 + a1 * 56 + 3532;
    }
    return 0;
}
}  // namespace n00189200

// ---- 00189228 from src/anon/batch_w8.cpp
namespace n00189228 {
void func_00189228(u8* p, u32 i) asm("func_00189228");
void func_00189228(u8* p, u32 i) {
    u8* q = (u8*)(i * 2) + (u32)p;
    q += 0x1450;
    if (*(u16*)(q + 8) < 999) *(u16*)(q + 8) += 1;
}
}  // namespace n00189228

// ---- 00189258 from src/anon/auto80_199_queue.cpp
namespace n00189258 {
extern "C" void RECOM_FLAG_clear_0019f578(u32) asm("_ZN2YS10RECOM_FLAG5clearEv");
void func_00189258(u32 a0) asm("_Z13func_00189258j");
void func_00189258(u32 a0) {
    u32 s0 = a0;
    func_001805e8(a0);
    u32 t = *(u32*)(s0 + 8);
    func_0019f480(t + 1140);
    t = *(u32*)(s0 + 8);
    RECOM_FLAG_clear_0019f578(t + 948);
    u32 t6 = *(u32*)(s0 + 8);
    *(u8*)(s0 + 248) = 0;
    u32 t7 = *(u32*)(t6 + 1416);
    if ((t7 & 2) != 0) {
        u32 t5 = t6 + 2748;
        *(u32*)(t5 + 4) = 0;
        *(u32*)(t5 + 8) = 0;
    }
}
}  // namespace n00189258

// ---- 001892b8 from src/anon/tiny_auto80_solver.cpp
namespace n001892b8 {
u32 func_00189f20(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00189f20jjjjjjjj");
extern u8 D_001892d8 asm("D_001892d8");
u32 func_001892b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001892b8jjjjjjjj");
u32 func_001892b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7;
    r6 = r5;
    r5 = (u32)&D_001892d8;
    return ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00189f20)(r4, r5, r6, r7, r8, r9, r10, r11);
}
}  // namespace n001892b8

// ---- 001892d8 from src/anon/batch_w1645.cpp
namespace n001892d8 {
struct W1645Masks {
    u32 m0;
    u32 m1;
    u32 m2;
    void set1(s32 i) { m1 |= 1 << i; }
    void set2(s32 i) { m2 |= 1 << i; }
};
struct W1645Obj {
    u8 pad0[0xf0];
    f32 ff0;                         
    u8 padF4[0x3b4 - 0xf4];
    u8 sub3b4[0x474 - 0x3b4];         
    u8 sub474[0x50c - 0x474];         
    s32 x50c;                         
    u8 pad510[0x588 - 0x510];
    u32 flags588;                     
    u8 pad58C[0xabc - 0x58c];
    W1645Masks masks;                 
} __attribute__((aligned(16)));
struct W1645Cmd {
    u8 pad0[4];
    u8 op;           
    u8 argc;         
    union {
        u16 a;       
        u8 a_b[2];
    };
    u16 b;           
    u16 c;            
};
struct W1645Ctx {
    u8 pad0[8];
    W1645Obj* obj;       
    u8 padC[0x14 - 0xc];
    s32 x14;                
    u8 pad18[0x20 - 0x18];
    u32 f20;                
    u32 f24;                
    u32 f28;                
    u8 pad2c[0xf8 - 0x2c];
    u8 bf8;                 
};
void func_0019f490(void*, u16) asm("func_0019f490");
void func_0019f4b8(void*, u16) asm("func_0019f4b8");
void func_0019f610(void*, u16, u16) asm("func_0019f610");
void W1645_Ctarget(void*, u32, u32) asm("_Z16ctarget_0019f670jjjj");
void func_00198ae0(W1645Obj*, u16, u16, u16) asm("func_00198ae0");
void func_00189e18(W1645Obj*, u16, u16) asm("func_00189e18");
s32 func_00187400(W1645Obj*, f32) asm("func_00187400");
s32 func_001874a0(W1645Obj*, f32) asm("func_001874a0");
void func_001940a0(W1645Obj*, u16) asm("func_001940a0");
void func_00198aa8(W1645Obj*, u16, u16, u16) asm("func_00198aa8");
static inline u32 W1645_F588(W1645Obj* o) { return o->flags588 & 1; }
static inline bool W1645_Flag588b0(W1645Obj* o) { return (u8)W1645_F588(o); }
void func_001892d8(W1645Cmd* cmd, W1645Ctx* ctx) asm("func_001892d8");
void func_001892d8(W1645Cmd* cmd, W1645Ctx* ctx)
{
    W1645Obj* obj = ctx->obj;
    switch (cmd->op) {
    case 0: ctx->f20 |= 0x4; break;
    case 1: ctx->f20 |= 0x8; break;
    case 2: ctx->f20 |= 0x10; break;
    case 3: ctx->f20 |= 0x20; break;
    case 4: func_0019f490(obj->sub474, cmd->a); break;
    case 5: func_0019f4b8(obj->sub474, cmd->a); break;
    case 6: func_0019f610(obj->sub3b4, cmd->a, cmd->b); break;
    case 7: W1645_Ctarget(obj->sub3b4, cmd->a, cmd->b); break;
    case 9: ctx->f20 |= 0x200; break;
    case 10: if (W1645_Flag588b0(obj)) func_00198ae0(obj, cmd->a, cmd->b, 0); break;
    case 11: ctx->f20 |= 0x400; break;
    case 12: ctx->f20 |= 0x800; break;
    case 13: ctx->f20 |= 0x8000; break;
    case 14: ctx->f20 |= 0x80000; break;
    case 15: ctx->f20 |= 0x10000; break;
    case 16: ctx->bf8 |= 0x1; break;
    case 17: ctx->bf8 |= 0x2; break;
    case 18: ctx->bf8 |= 0x4; break;
    case 19: ctx->bf8 |= 0x8; break;
    case 20: {
        func_00189e18(obj, cmd->a, (cmd->argc < 2) ? 0 : cmd->b);
        break;
    }
    case 21: ctx->f20 |= 0x40000; break;
    case 22:
        if (obj->flags588 & 2) {
            if (func_00187400(obj, cmd->a * 0.017453292f)) ctx->f28 |= 0x8;
        }
        break;
    case 23: func_001940a0(obj, cmd->a); break;
    case 24:
        ctx->f20 |= 0x40;
        obj->ff0 = cmd->a * 0.01f;
        break;
    case 25:
        ctx->f20 |= 0x100000;
        obj->x50c = cmd->a;
        break;
    case 26:
        ctx->f20 |= 0x200000;
        obj->x50c = cmd->a;
        break;
    case 27: ctx->f20 |= 0x400000; break;
    case 28:
        if (obj->flags588 & 2) {
            if (func_001874a0(obj, cmd->a * 0.017453292f)) ctx->f28 |= 0x8;
        }
        break;
    case 29: ctx->f20 |= 0x800000; break;
    case 30: ctx->f20 |= 0x1000000; break;
    case 31: ctx->f20 |= 0x2000000; break;
    case 32: ctx->f20 |= 0x4000000; break;
    case 33: if (W1645_Flag588b0(obj)) func_00198ae0(obj, cmd->a, cmd->b, cmd->c); break;
    case 34: ctx->f20 |= 0x8000000; break;
    case 35: if (cmd->a == ctx->x14) ctx->f20 |= 0x400; break;
    case 36: if (obj->flags588 & 2) obj->masks.set1(cmd->a); break;
    case 37: if (obj->flags588 & 2) obj->masks.set2(cmd->a); break;
    case 38: ctx->f20 |= 0x10000000; break;
    case 39: ctx->f20 |= 0x20000000; break;
    case 40: ctx->f20 |= 0x40000000; break;
    case 41: ctx->f20 |= 0x80000000; break;
    case 42: ctx->f24 |= 0x1; break;
    case 44: ctx->f24 |= 0x2; break;
    case 45: ctx->f28 |= 0x1; break;
    case 46: ctx->f28 |= 0x2; break;
    case 47: ctx->f28 |= 0x4; break;
    case 49: ctx->f28 |= 0x10; break;
    case 50: ctx->f28 |= 0x20; break;
    case 51: {
        u16 c = 0;
        if (cmd->argc >= 3) c = cmd->c;
        func_00198aa8(obj, cmd->a, cmd->b, c);
        break;
    }
    case 52: ctx->f28 |= 0x40; break;
    case 53: ctx->f28 |= 0x80; break;
    }
}
}  // namespace n001892d8

// ---- 00189740 gap: event command callback, passed by 0x189d18 to the key walker 0x18a008 (never written before)
namespace n00189740 {
struct Cmd { u8 pad[2]; u8 op; u8 argc; u16 a; u16 b; u16 c; u16 d; };
struct Ctx { u8 pad0[8]; u8* obj; u8 pad1[8]; s32 x14; u8 pad2[16]; u32 f28; u8 pad3[249 - 44]; u8 bf9; };
struct VO;
struct VT { void* f[19]; void (*f19)(VO*); void* g; void (*f21)(VO*, u16, u16); };
struct VO { VT* vt; };
struct Msg { u8* o; s32 a; s32 b; };
void func_00189d38(Ctx*, Cmd*) asm("func_00189d38");
void func_0016c168(u8*, u16) asm("func_0016c168");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_00194070(u8*, u16) asm("func_00194070");
void func_00194088(u8*, u16) asm("func_00194088");
void func_001ba650(u8*) asm("func_001ba650");
void func_0016cce8(s32, s32, Msg*, s32, s32) asm("func_0016cce8");
void func_001b5970(Msg*, s32) asm("func_001b5970");
void func_00180b10(Ctx*, s32) asm("func_00180b10");
s32 func_001872e0(u8*, f32) asm("func_001872e0");
s32 func_00187420(u8*, f32) asm("func_00187420");
void func_001a6440(s32) asm("func_001a6440");
void func_001b3748(u8*, u16) asm("func_001b3748");
void func_00177540(u8*) asm("func_00177540");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");
void func_001945a0(u8*, s32, u32, f32) asm("func_001945a0");
void func_00194610(u8*, s32, f32) asm("func_00194610");
void func_00188120(u8*, const char*) asm("func_00188120");
void func_001775a8(u8*) asm("func_001775a8");
void func_001b5a60(u16, u16, u8*) asm("func_001b5a60");
void func_001d5068(u16) asm("func_001d5068");
void func_001791e8(u8*, u8*) asm("func_001791e8");
s32 func_0019c090(u8*) asm("func_0019c090");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
#define W(o, n) (*(u32*)((o) + (n)))
#define F(o, n) (*(f32*)((o) + (n)))
static inline u32 F1416(u8* o) { return W(o, 1416) & 1; }
static inline bool Flag1416b0(u8* o) { return (u8)F1416(o); }
static inline s32 Id(u8* p) { return p ? *(s16*)(p + 2) : -1; }
static inline bool Busy2(u8* o) {
    bool r = 0;
    if ((W(*(u8**)(o + 12), 8) & 2) || (W(o, 352) & 0x40)) r = 1;
    return r;
}
static inline bool ShouldTurn(u8* o) { bool r = 0; if (func_0019c090(o) || Busy2(o)) r = 1; return r; }
static inline bool Ge(u8* o) { return F(o, 2800) >= F(o, 2804); }
void func_00189740(Cmd* cmd, Ctx* ctx) asm("func_00189740");
void func_00189740(Cmd* cmd, Ctx* ctx)
{
    u8* obj = ctx->obj;
    switch (cmd->op) {
    case 0:
        switch (obj[1300]) {
        case 1: func_0016bd60(obj, 1); break;
        case 2: func_0016bd60(obj, 9); break;
        case 3: func_0016bd60(obj, 11); break;
        case 4: func_0016bd60(obj, 20); break;
        case 5: func_0016bd60(obj, 26); break;
        case 6: func_0016bd60(obj, 40); break;
        case 7: func_0016bd60(obj, 44); break;
        case 8: func_0016bd60(obj, 49); break;
        case 9: func_0016bd60(obj, 63); break;
        }
        obj[1300] = 0;
        break;
    case 1: func_00189d38(ctx, cmd); break;
    case 2: func_0016c168(obj, cmd->a); break;
    case 3: func_0016bd60(obj, 7); break;
    case 4: func_00194070(obj, cmd->a); break;
    case 5: func_00194088(obj, cmd->a); break;
    case 6: func_001ba650(obj); break;
    case 7: {
        Msg m;
        m.o = obj;
        m.a = cmd->a;
        m.b = cmd->b;
        if (W(obj, 1156)) func_0016cce8(W(obj, 1156), 17, &m, 3, 0);
        func_001b5970(&m, 3);
        break;
    }
    case 8:
        if (Flag1416b0(obj)) {
            if (cmd->argc < 4 || cmd->d == 0 || cmd->a == Id(*(u8**)(obj + 2484)))
                func_00180b10(ctx, cmd->a * 1000 + cmd->b);
        }
        break;
    case 9: ctx->bf9 |= 1; break;
    case 10: ctx->bf9 |= 2; break;
    case 11: ctx->bf9 |= 4; break;
    case 12: ctx->bf9 |= 8; break;
    case 13:
    case 14:
        if (Flag1416b0(obj)) {
            u16 b = 0;
            if (cmd->argc >= 2) b = cmd->b;
            ((VO*)obj)->vt->f21((VO*)obj, cmd->a, b);
        }
        break;
    case 15:
        if (W(obj, 1416) & 2) {
            if (func_001872e0(obj, cmd->a * 0.017453292f)) ctx->f28 |= 8;
        }
        break;
    case 16: F(obj, 2480) = cmd->a; break;
    case 17:
        if (cmd->argc != 0) { s32 x = ctx->x14; if (x != cmd->a) break; }
        if (W(obj, 2856)) func_001a6440(W(obj, 2856));
        break;
    case 19: func_001b3748(obj, cmd->a); break;
    case 21:
        if (W(obj, 1416) & 2) {
            if (func_00187420(obj, cmd->a * 0.017453292f)) ctx->f28 |= 8;
        }
        break;
    case 22: if (W(obj, 1416) & 4) func_00177540(obj); break;
    case 23: { f32 v = cmd->a; if (!(W(obj, 2040) & 0x10)) func_001ad990(obj + 2092, 1.0f, 0.0f, v); break; }
    case 24: { f32 v = cmd->a; if (!(W(obj, 2040) & 0x10)) func_001ad990(obj + 2092, 0.0f, 1.0f, v); break; }
    case 25:
        if (Flag1416b0(obj)) {
            void** vt = *(void***)obj;
            ((void (*)(u8*))vt[19])(obj);
        }
        break;
    case 26: func_001945a0(obj, 1 << cmd->a, 0x808080, cmd->b); break;
    case 27: func_00194610(obj, 1 << cmd->a, cmd->b); break;
    case 28: if (W(obj, 1416) & 0x10) { if (Ge(obj)) func_00188120(obj + 768, "revenge"); } break;
    case 29: if (W(obj, 1416) & 4) func_001775a8(obj); break;
    case 30: { u16 b = 0; if (cmd->argc >= 2) b = cmd->b; func_001b5a60(cmd->a, b, obj); break; }
    case 31: func_001d5068(cmd->a); break;
    case 34: if (W(*(u8**)(obj + 2884), 8) & 4) func_001791e8(obj, obj + 1360); break;
    case 35: {
        if (ShouldTurn(obj)) func_0017f488(obj + 320, 4, 16.0f, 0.0f);
        break;
    }
    }
}
#undef W
#undef F
}  // namespace n00189740

// ---- 00189d18 from src/anon/tiny_auto80_solver.cpp
namespace n00189d18 {
u32 func_0018a008(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0018a008jjjjjjjj");
extern u8 D_00189740 asm("D_00189740");
u32 func_00189d18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00189d18jjjjjjjj");
u32 func_00189d18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7;
    r6 = r5;
    r5 = (u32)&D_00189740;
    return ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0018a008)(r4, r5, r6, r7, r8, r9, r10, r11);
}
}  // namespace n00189d18
