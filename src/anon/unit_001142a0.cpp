// Linked unit 0x001142a0-0x001149a0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../naka/libkn/friend_personality.hpp"
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
#include "../tozawa/help_gra.hpp"
#include "../naka/libkn/ability_info.hpp"

// 001142a0 (was src/anon/tiny.cpp)
namespace n001142a0 {
/*TARGET 001142a0*/
// 0x00112c38: definition moved into src/anon/unit_001117d8.cpp

f32 func_001142a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001142a0jjjj");
// 0x00112c38: definition moved into src/anon/unit_001117d8.cpp

f32 func_001142a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 p = *(u32*)((u32)a0 + (8));
    return *(f32*)((u32)p + (96));
}
}  // namespace n001142a0

// 001142b0 (was src/anon/tiny.cpp)
namespace n001142b0 {
/*TARGET 001142b0*/
f32 func_001142b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001142b0jjjj");
f32 func_001142b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 p = *(u32*)((u32)a0 + (8));
    return *(f32*)((u32)p + (100));
}
}  // namespace n001142b0

// 001142c0 (was src/anon/tiny.cpp)
namespace n001142c0 {
/*TARGET 001142c0*/
f32 func_001142c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001142c0jjjj");
f32 func_001142c0(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_float_104
    (void)a1;
    (void)a2;
    (void)a3;
    u32 p = *(u32*)((u32)a0 + (8));
    return *(f32*)((u32)p + (104));
}
}  // namespace n001142c0

// 001142d0 (was src/anon/tiny.cpp)
namespace n001142d0 {
/*TARGET 001142d0*/
f32 func_001142d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001142d0jjjj");
f32 func_001142d0(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_float_at_ptr108
    (void)a1;
    (void)a2;
    (void)a3;
    u32 p = *(u32*)((u32)a0 + (8));
    return *(f32*)((u32)p + (108));
}
}  // namespace n001142d0

// 001142e0 (was src/anon/batch_w35.cpp)
namespace n001142e0 {
/*TARGET 001142e0*/
// Allocates a heap of `size` bytes and installs it.
// 00105370: moved to src/common/area.cpp

f32 func_001142e0(u8* p, s32 i, u8 a, u8 b) asm("func_001142e0");
// Allocates a heap of `size` bytes and installs it.
// 00105370: moved to src/common/area.cpp

f32 func_001142e0(u8* p, s32 i, u8 a, u8 b) {  // entry8_float_by_flags
    if (a) {
        if (b) return *(f32*)(*(u8**)(p + 8) + i * 8 + 32);
        return *(f32*)(*(u8**)(p + 8) + i * 8 + 64);
    }
    return *(f32*)(*(u8**)(p + 8) + i * 8);
}
}  // namespace n001142e0

// 00114328 (was src/anon/batch_w50.cpp)
namespace n00114328 {
struct E8 { u32 a; f32 v; };
struct Tbl { u32 f0; u32 f4; E8* e; };
/*TARGET 00114328*/
// 00108398: moved to src/anon/unit_00108068.cpp

f32 func_00114328(Tbl* t, s32 i, u8 a, u8 b) asm("func_00114328");
// 00108398: moved to src/anon/unit_00108068.cpp

f32 func_00114328(Tbl* t, s32 i, u8 a, u8 b) {
    if (a) {
        if (b) return t->e[i + 4].v;
        return t->e[i + 8].v;
    }
    return t->e[i].v;
}
}  // namespace n00114328

// 00114370 (was src/naka/libkn/friend_personality.cpp)
namespace kn { // method 00114370
/*TARGET 00114370*/
f32 FriendPersonality::getBattleCancelDistance() const {
    u32 p = *(u32*)((u32)this + 8);
    return *(f32*)((u32)p + 128);
}
}  // kn

// 00114380 (was src/anon/tiny.cpp)
namespace n00114380 {
/*TARGET 00114380*/
f32 func_00114380(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114380jjjj");
f32 func_00114380(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 p = *(u32*)((u32)a0 + (8));
    return *(f32*)((u32)p + (132));
}
}  // namespace n00114380

// 00114390 (was src/anon/tiny.cpp)
namespace n00114390 {
/*TARGET 00114390*/
f32 func_00114390(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114390jjjj");
f32 func_00114390(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 p = *(u32*)((u32)a0 + (8));
    return *(f32*)((u32)p + (136));
}
}  // namespace n00114390

// 001143a0 (gap function, not written before)
namespace g001143a0 {
void func_001143a0(void) asm("func_001143a0");
void func_001143a0(void) {}
}  // namespace g001143a0

// 001143a8 (gap function, not written before)
namespace g001143a8 {
void func_001143a8(void) asm("func_001143a8");
void func_001143a8(void) {}
}  // namespace g001143a8

// 001143b0 (gap function, not written before)
namespace g001143b0 {
void func_001143b0(void) asm("func_001143b0");
void func_001143b0(void) {}
}  // namespace g001143b0

// 001143b8 (gap function, not written before)
namespace g001143b8 {
void func_001143b8(void) asm("func_001143b8");
void func_001143b8(void) {}
}  // namespace g001143b8

// 001143c0 (gap function, not written before)
namespace g001143c0 {
void func_001143c0(void) asm("func_001143c0");
void func_001143c0(void) {}
}  // namespace g001143c0

// 001143c8 (gap function, not written before)
namespace g001143c8 {
void func_001143c8(void) asm("func_001143c8");
void func_001143c8(void) {}
}  // namespace g001143c8

// 001143d0 (gap function, not written before)
namespace g001143d0 {
void func_001143d0(void) asm("func_001143d0");
void func_001143d0(void) {}
}  // namespace g001143d0

// 001143d8 (was src/naka/libkn/friend_personality.cpp)
namespace kn { // method 001143d8
u32 func_0010eed8(...) asm("func_0010eed8");
u32 func_001c0cd8(...) asm("func_001c0cd8");
u32 func_001c0e60(...) asm("func_001c0e60");
/*TARGET 001143d8*/
void FriendPersonality::start_limit() {
    u32 s0 = (u32)this;
    func_0010eed8(*(volatile u32*)((u32)this + (s32)(4)), 0u, 0u);
    u32 v0 = func_001c0cd8(*(volatile u32*)((u32)s0 + (s32)(4)));
    if (v0 != 0u) {
        func_001c0e60(*(volatile u32*)((u32)s0 + (s32)(4)));
    }
}
}  // kn

// 00114428 (gap function, not written before)
namespace g00114428 {
void func_00114428(void) asm("func_00114428");
void func_00114428(void) {}
}  // namespace g00114428

// 00114430 (gap function, not written before)
namespace g00114430 {
void func_00114430(void) asm("func_00114430");
void func_00114430(void) {}
}  // namespace g00114430

// 00114438 (was src/anon/batch_w2364.cpp)
namespace n00114438 {
// 128-byte entries in a table that sits behind a header (count + byte offset pairs).
struct Ent2364 { s32 id; u8 pad[124]; };
struct Tbl2364 {
    u8 pad[0xa0];
    s32 n;       // 0xa0: entry count, first list
    s32 off;     // 0xa4: byte offset of the first list
    u8 pad2[8];
    s32 n2;      // 0xb0: entry count, second list
    s32 off2;    // 0xb4: byte offset of the second list
};
struct Own2364 { u8 pad[8]; Tbl2364* t; };
/*TARGET 00114438*/
// Finds the entry with this id in the first list (0 if none).
Ent2364* func_00114438(Own2364* o, s32 id) asm("func_00114438");
// Finds the entry with this id in the first list (0 if none).
Ent2364* func_00114438(Own2364* o, s32 id) {
    Ent2364* r = 0;
    Tbl2364* t = o->t;
    if (t) {
        Ent2364* e = (Ent2364*)((u8*)t + t->off);
        for (s32 i = 0; i < o->t->n; i++) {
            if (e[i].id == id) { r = &e[i]; break; }
        }
    }
    return r;
}
}  // namespace n00114438

// 00114490 (was src/anon/batch_w2364.cpp)
namespace n00114490 {
// 128-byte entries in a table that sits behind a header (count + byte offset pairs).
struct Ent2364 { s32 id; u8 pad[124]; };
struct Tbl2364 {
    u8 pad[0xa0];
    s32 n;       // 0xa0: entry count, first list
    s32 off;     // 0xa4: byte offset of the first list
    u8 pad2[8];
    s32 n2;      // 0xb0: entry count, second list
    s32 off2;    // 0xb4: byte offset of the second list
};
struct Own2364 { u8 pad[8]; Tbl2364* t; };
/*TARGET 00114490*/
// Finds the entry with this id in the second list (0 if none).
Ent2364* func_00114490(Own2364* o, s32 id) asm("func_00114490");
// Finds the entry with this id in the second list (0 if none).
Ent2364* func_00114490(Own2364* o, s32 id) {
    Ent2364* r = 0;
    Tbl2364* t = o->t;
    if (t) {
        Ent2364* e = (Ent2364*)((u8*)t + t->off2);
        for (s32 i = 0; i < o->t->n2; i++) {
            if (e[i].id == id) { r = &e[i]; break; }
        }
    }
    return r;
}
}  // namespace n00114490

// 001144e8 (was src/anon/batch_w1762_nsa.cpp)
namespace n001144e8 {
typedef struct Key1762 { s32 a; s32 b; } Key1762;
typedef struct E1762 { s32 x; s32 a; s32 b; u8 pad[24]; } E1762;
typedef struct T1762 { u8 pad[12]; s32 n; E1762* e; } T1762;
/*TARGET 001144e8*/
E1762* func_001144e8(T1762* p, Key1762 k) asm("func_001144e8");
E1762* func_001144e8(T1762* p, Key1762 k) {
    s32 i;
    if (p->e == 0) return 0;
    for (i = 0; i < p->n; i++) {
        E1762* e = &p->e[i];
        if (e->a == k.a && (e->b == k.b || e->a == 0)) return e;
    }
    return 0;
}
}  // namespace n001144e8

// 00114550 (gap function, not written before)
namespace g00114550 {
// Clears a 32-byte name buffer.
void func_00114550(u8* p) asm("func_00114550");
void func_00114550(u8* p) {
    p[0] = 0;
    for (s32 i = 0; i < 31; i++) p[1 + i] = 0;
}
}  // namespace g00114550

// 00114580 (was src/anon/tiny_auto80_queue.cpp)
namespace n00114580 {
/*TARGET 00114580*/
void func_00114580(u32 a0) asm("_Z13func_00114580j");
void func_00114580(u32 a0) {
    *(volatile u8*)((u32)a0 + (s32)(0)) = (u8)0u;
    u32 i = 0u;
    do {
        *(volatile u8*)((u32)a0 + (s32)(i + 1u)) = (u8)0u;
        i = (u32)(i + 1u);
    } while ((s32)i < 31);
}
}  // namespace n00114580

// 001145b0 (was src/anon/batch_w65.cpp)
namespace n001145b0 {
// Index of x in the 7-entry table, else 7 + secondary lookup.
extern s16 D_00345d30[] asm("D_00345d30");
s32 func_00114738(s32) asm("func_00114738");
/*TARGET 001145b0*/
s32 func_001145b0(s32 x) asm("func_001145b0");
s32 func_001145b0(s32 x) {
    s32 i;
    for (i = 0; i < 7; i++)
        if (D_00345d30[i] == x) return i;
    return func_00114738(x) + 7;
}
}  // namespace n001145b0

// 00114600 (was src/anon/tiny_jal_wrappers.cpp)
namespace n00114600 {
u32 func_00114690(u32, u32, u32, u32) asm("_Z13func_00114690jjjj");
/*TARGET 00114600*/
// 0x001125b8: definition moved into src/anon/unit_001117d8.cpp

u32 func_00114600(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114600jjjj");
// 0x001125b8: definition moved into src/anon/unit_001117d8.cpp

u32 func_00114600(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00114690(r4, r5, r6, r7);
    r2 = (u32)((s32)r2 + (7));
    return r2;
}
}  // namespace n00114600

// 00114620 (was src/naka/libkn/ability.cpp)
namespace kn { // method 00114620
extern u8 D_00345d40 asm("D_00345d40");
/*TARGET 00114620*/
u32 AbilityInfo::ability2item(s32 a0) {
    u32 t6 = 0;
    u8* v2 = &D_00345d40;
    while (1) {
        u32 t7 = *(u32*)(v2 + 0);
        if (t7 == (u32)a0) {
            return *(u32*)(v2 + 4);
        }
        t6 += 1;
        if ((s32)t6 < 29) {
            v2 += 16;
            continue;
        }
        return 0;
    }
}
}  // kn

// 00114658 (gap function, not written before)
namespace g00114658 {
extern u8 D_00345d40 asm("D_00345d40");
/*TARGET 00114690*/
s32 func_00114658(u32 a0) asm("func_00114658");
s32 func_00114658(u32 a0) {
    u32 t6 = 0;
    u8* v2 = &D_00345d40;
    while (1) {
        u32 t7 = *(u32*)(v2 + 0);
        if (t7 == a0) {
            return *(s32*)(v2 + 8);
        }
        t6 += 1;
        if ((s32)t6 < 29) {
            v2 += 16;
            continue;
        }
        return -1;
    }
}
}  // namespace g00114658

// 00114690 (was src/anon/tiny_auto80_queue.cpp)
namespace n00114690 {
extern u8 D_00345d40 asm("D_00345d40");
/*TARGET 00114690*/
s32 func_00114690(u32 a0) asm("_Z13func_00114690j");
s32 func_00114690(u32 a0) {
    u32 t6 = 0;
    u8* v2 = &D_00345d40;
    while (1) {
        u32 t7 = *(u32*)(v2 + 0);
        if (t7 == a0) {
            return *(s32*)(v2 + 12);
        }
        t6 += 1;
        if ((s32)t6 < 29) {
            v2 += 16;
            continue;
        }
        return -1;
    }
}
}  // namespace n00114690

// 001146c8 (gap function, not written before)
namespace g001146c8 {
extern u8 D_00345d40 asm("D_00345d40");
/*TARGET 00114690*/
s32 func_001146c8(u32 a0) asm("func_001146c8");
s32 func_001146c8(u32 a0) {
    u32 t6 = 0;
    u8* v2 = &D_00345d40;
    while (1) {
        u32 t7 = *(u32*)(v2 + 4);
        if (t7 == a0) {
            return *(s32*)(v2 + 0);
        }
        t6 += 1;
        if ((s32)t6 < 29) {
            v2 += 16;
            continue;
        }
        return 0;
    }
}
}  // namespace g001146c8

// 00114700 (gap function, not written before)
namespace g00114700 {
extern u8 D_00345d40 asm("D_00345d40");
/*TARGET 00114690*/
s32 func_00114700(u32 a0) asm("func_00114700");
s32 func_00114700(u32 a0) {
    u32 t6 = 0;
    u8* v2 = &D_00345d40;
    while (1) {
        u32 t7 = *(u32*)(v2 + 4);
        if (t7 == a0) {
            return *(s32*)(v2 + 8);
        }
        t6 += 1;
        if ((s32)t6 < 29) {
            v2 += 16;
            continue;
        }
        return -1;
    }
}
}  // namespace g00114700

// 00114738 (was src/naka/libkn/ability.cpp)
namespace kn { // method 00114738
extern u8 D_00345d40 asm("D_00345d40");
/*TARGET 00114738*/
s32 AbilityInfo::item2index(s32 a0) {
    u32 t6 = 0;
    u8* v2 = &D_00345d40;
    while (1) {
        u32 t7 = *(u32*)(v2 + 4);
        if (t7 == (u32)a0) {
            return *(s32*)(v2 + 12);
        }
        t6 += 1;
        if ((s32)t6 < 29) {
            v2 += 16;
            continue;
        }
        return -1;
    }
}
}  // kn

// 00114770 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114770 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00345f10 asm("D_00345f10");
extern u8 D_003461e8 asm("D_003461e8");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114770*/
u32 func_00114770(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114770jjjjjjjj");
u32 func_00114770(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00345f10;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003461e8;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 20;
    return r2;
}
}  // namespace n00114770

// 001147b8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001147b8 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00345f10 asm("D_00345f10");
extern u8 D_003461e8 asm("D_003461e8");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 001147b8*/
u32 func_001147b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001147b8jjjjjjjj");
u32 func_001147b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00345f10;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003461e8;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 20;
    return r2;
}
}  // namespace n001147b8

// 00114800 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114800 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003461e8 asm("D_003461e8");
/*TARGET 00114800*/
// 0x00112780: definition moved into src/anon/unit_001117d8.cpp

u32 func_00114800(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114800jjjj");
// 0x00112780: definition moved into src/anon/unit_001117d8.cpp

u32 func_00114800(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003461e8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114800

// 00114828 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114828 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003461e8 asm("D_003461e8");
/*TARGET 00114828*/
u32 func_00114828(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114828jjjj");
u32 func_00114828(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003461e8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114828

// 00114850 (was src/anon/batch_w23.cpp)
namespace n00114850 {
// 001053c0: moved to src/common/area.cpp

extern u32 D_003461e8 asm("D_003461e8");
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
/*TARGET 00114850*/
void func_00114850(void** p) asm("func_00114850");
void func_00114850(void** p) {
    *p = &D_003461e8;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00114850

// 00114888 (gap function, not written before)
namespace g00114888 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346220 asm("D_00346220");
extern u8 D_003464b0 asm("D_003464b0");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 001148d0*/
u32 func_00114888(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00114888");
u32 func_00114888(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346220;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003464b0;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 18;
    return r2;
}
}  // namespace g00114888

// 001148d0 (was src/anon/tiny_auto80_solver.cpp)
namespace n001148d0 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346220 asm("D_00346220");
extern u8 D_003464b0 asm("D_003464b0");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 001148d0*/
u32 func_001148d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001148d0jjjjjjjj");
u32 func_001148d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346220;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003464b0;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 18;
    return r2;
}
}  // namespace n001148d0

// 00114918 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114918 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003464b0 asm("D_003464b0");
/*TARGET 00114918*/
u32 func_00114918(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114918jjjj");
u32 func_00114918(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003464b0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114918

// 00114940 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114940 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003464b0 asm("D_003464b0");
/*TARGET 00114940*/
u32 func_00114940(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114940jjjj");
u32 func_00114940(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003464b0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114940

// 00114968 (was src/anon/batch_w11.cpp)
namespace n00114968 {
// 0x0010f6b8: definition moved into src/anon/unit_0010f338.cpp

extern u32 D_003464b0 asm("D_003464b0");
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
/*TARGET 00114968*/
void func_00114968(void** p) asm("func_00114968");
void func_00114968(void** p) {
    *p = &D_003464b0;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00114968

