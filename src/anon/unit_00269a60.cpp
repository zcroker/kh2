// Linked unit 0x00269a60-0x0026a5a0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>

// 00269a60 (was src/anon/batch_w2427.cpp)
namespace n00269a60 {
s32 func_00257070(s32) asm("func_00257070");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00257130(void) asm("func_00257130");
u8* func_00257770(void) asm("func_00257770");
void func_00263a58(s32, s32) asm("func_00263a58");
s32 func_00269508(s32) asm("func_00269508");
s32 func_002695a0(s32) asm("func_002695a0");
u16* func_0026a178(s32, s32) asm("func_0026a178");
s32 func_002811b0(s32, s32) asm("func_002811b0");
void func_002817b8(void) asm("func_002817b8");
void func_00281cf0(u16) asm("func_00281cf0");
s32 func_00281f18(s32) asm("func_00281f18");
u8* func_00281f20(s32) asm("func_00281f20");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
void func_00291068(s32, s32, u16, u8*, s32, s32) asm("func_00291068");
void func_00291110(s32, s32, s32, u16, u8*, s32, s32) asm("func_00291110");
void func_00291358(s32) asm("func_00291358");
extern s32 D_0035f010 asm("D_0035f010");
extern s32 D_0035f018 asm("D_0035f018");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f0ec asm("D_0035f0ec");
/*TARGET 00269a60*/
void func_00269a60(void) asm("func_00269a60");
void func_00269a60(void)
{
    s32 none = 0;
    u8* buf = func_00257770();
    s32 mode = func_00287bc0();
    s32 idx = func_0028b040(D_0035f01c);
    s32 msg;
    if (mode == 2) goto A;
    if (mode == 5 || mode == 6) {
        if (!func_00281f18(D_0035f0ec)) { none = 1; goto B; }
    A:
        if (!func_0026a178(idx, -1) || !*func_0026a178(idx, -1)) none = 1;
    } else if (!idx || !func_0026a178(idx - 1, -1) || !*func_0026a178(idx - 1, -1)) {
        none = 1;
    }
B:
    if (mode == 2) {
        if (none) msg = -1;
        else msg = (u16)(func_0026a178(idx, -1)[5] | 0x8000);
    } else if (mode == 5 || mode == 6) {
        if (func_00281f18(D_0035f0ec)) msg = (u16)(func_0026a178(idx, -1)[5] | 0x8000);
        else msg = 0x844a;
    } else if (!idx) {
        if (mode == 7) msg = 0xcb8d;
        else msg = mode == 8 ? 0xcb8e : 0x8469;
    } else {
        msg = (u16)(func_0026a178(idx - 1, -1)[5] | 0x8000);
    }
    func_00263a58(msg, 1);
    s32 s4 = func_002811b0(D_0035f010, func_00257070(1));
    s32 v;
    if (mode == 2) v = func_0028b040(D_0035f01c);
    else v = func_00257070(2);
    s32 s3;
    if (func_00269508(v) == 1) s3 = func_002695a0(v); else s3 = 0;
    if (none) {
        func_002817b8();
        if (mode == 2) {
            func_00291358(D_0035f018);
            return;
        }
        v = *(u16*)(func_00281f20(func_00257130()) + func_002570a0(2) * 6);
        if ((mode == 5 || mode == 6)) func_00291110(D_0035f018, 3, v, 0, buf + 0xb350, s4, s3);
        else func_00291110(D_0035f018, 2, v, 0, buf + 0xb350, s4, s3);
        return;
    }
    idx -= (u32)(mode - 7) < 3;
    func_00281cf0(func_0026a178(idx, -1)[10]);
    if (mode == 2) {
        func_00291068(D_0035f018, 1, *func_0026a178(idx, -1), buf + 0xb350, s4, s3);
        return;
    }
    v = *(u16*)(func_00281f20(func_00257130()) + func_002570a0(2) * 6);
    if ((mode == 5 || mode == 6)) func_00291110(D_0035f018, 3, v, *func_0026a178(idx, -1), buf + 0xb350, s4, s3);
    else func_00291110(D_0035f018, 2, v, *func_0026a178(idx, -1), buf + 0xb350, s4, s3);
}
}  // namespace n00269a60

// 00269e20 (was src/anon/batch_w3714_g.cpp)
namespace n00269e20 {
u32 func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_002570a0(s32, s32) asm("func_002570a0");
s32 func_00269508(s32) asm("func_00269508");
void func_0028dac8(u32, s32) asm("func_0028dac8");
s32 func_0028be58(u32) asm("func_0028be58");
void func_0028bdb8(u32) asm("func_0028bdb8");
struct E6 { s16 a; s16 b; s16 c; };
extern E6 D_00373798[] asm("D_00373798");
extern E6 D_003737c8[] asm("D_003737c8");
extern u32 D_0035f04c asm("D_0035f04c");
/*TARGET 00269e20*/
void func_00269e20(void) asm("func_00269e20");
void func_00269e20(void) {
    u32 p = func_00257770();
    s32 m = func_00287bc0();
    u32 t = m - 5;
    register s32 a0 asm("$4");
    asm volatile("li %0,2" : "=r"(a0));
    u32 c = t < 5;
    register s32 k asm("$5") = 0xe5;
    if (c) {
        s32 i = func_00269508(func_002570a0(a0, k));
        func_0028dac8(p, D_00373798[i].b);
        func_0028dac8(p + 0xb350, D_003737c8[i].b);
    } else {
        func_0028dac8(p, k);
        func_0028dac8(p + 0xb350, 0x121);
    }
    if (func_0028be58(D_0035f04c)) {
        func_0028bdb8(D_0035f04c);
    }
}
}  // namespace n00269e20

// 00269ef8 (was src/anon/batch_w44.cpp)
namespace n00269ef8 {
void func_002579e0(void) asm("func_002579e0");
s32 func_0028be58(void*) asm("func_0028be58");
void func_0028be18(void*) asm("func_0028be18");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028abe0(void*) asm("func_0028abe0");
extern void* D_0035f04c asm("D_0035f04c");
extern void* D_0035f01c asm("D_0035f01c");
/*TARGET 00269ef8*/
void func_00269ef8(void) asm("func_00269ef8");
void func_00269ef8(void) {
    func_002579e0();
    if (func_0028be58(D_0035f04c)) func_0028be18(D_0035f04c);
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
}
}  // namespace n00269ef8

// 00269f58 (was src/anon/batch_w43.cpp)
namespace n00269f58 {
s32 func_00257780(void) asm("func_00257780");
extern void* D_0035f04c asm("D_0035f04c");
extern void* D_0035f01c asm("D_0035f01c");
s32 func_0028be58(void*) asm("func_0028be58");
s32 func_0028acc8(void*) asm("func_0028acc8");
/*TARGET 00269f58*/
s32 func_00269f58(void) asm("func_00269f58");
s32 func_00269f58(void) {
    s32 r = func_00257780();
    if (r) return r;
    if (D_0035f04c) r = func_0028be58(D_0035f04c) != 0;
    if (r) return r;
    if (D_0035f01c) r = func_0028acc8(D_0035f01c) != 0;
    return r;
}
}  // namespace n00269f58

// 00269fc0 (was src/anon/batch_wcx.cpp)
namespace n00269fc0 {
struct E6 { s16 a, b, c; };
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
extern E6 D_00373798[] asm("D_00373798");
u8* func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00269508(s32) asm("func_00269508");
/*TARGET 00269fc0*/
s32 func_00269fc0(void) asm("func_00269fc0");
s32 func_00269fc0(void)
{
    s32 r = 0;
    u8* o = func_00257770();
    s32 k = func_00287bc0();
    if (o && u_call4_00139d78(o)) {
        s32 v = 228;
        if (k != 2) v = D_00373798[func_00269508(func_002570a0(2))].c;
        r = *(s32*)(o + 388) == v;
    }
    return r;
}
}  // namespace n00269fc0

// 0026a060 (was src/anon/batch_w1582_g.cpp)
namespace n0026a060 {
u8* func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00269508(s32) asm("func_00269508");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_0028be58(u32) asm("func_0028be58");
void func_0028bd60(u32) asm("func_0028bd60");
struct E6 { s16 a; s16 b; s16 c; };
extern E6 D_00373798[] asm("D_00373798");
extern E6 D_003737c8[] asm("D_003737c8");
extern u32 D_0035f04c asm("D_0035f04c");
static inline void set_0026a060(u8* q, s32 v) {
    if (func_00139d78(q) && *(s32*)(q + 0x184) != v) func_00138c10(q, v);
}
/*TARGET 0026a060*/
void func_0026a060(void) asm("func_0026a060");
void func_0026a060(void) {
    u8* p = func_00257770();
    s32 a, b;
    if (func_00287bc0() == 2) {
        a = 0xe4; b = 0x120;
    } else {
        s32 i = func_00269508(func_002570a0(2));
        a = D_00373798[i].c;
        b = D_003737c8[i].c;
    }
    if (p) set_0026a060(p, a);
    if (p) set_0026a060(p + 0xb350, b);
    if (func_0028be58(D_0035f04c)) {
        func_0028bd60(D_0035f04c);
    }
}
}  // namespace n0026a060

// 0026a178 (was src/anon/batch_w82.cpp)
namespace n0026a178 {
s32 func_00287bc0(void) asm("func_00287bc0");
extern u32 D_0035f0ec asm("D_0035f0ec");
u32 func_00257130(void) asm("func_00257130");
u8* func_00281f20(u32) asm("func_00281f20");
u8* func_001a80c8(u32) asm("func_001a80c8");
// table24_find_by_id
s32 func_00281f18(u32) asm("func_00281f18");
/*TARGET 0026a178*/
// Looks up entry idx of the current table (mode 2 = active slot) and returns its item record.
u8* func_0026a178(s32 idx, s32 mode) asm("func_0026a178");
// Looks up entry idx of the current table (mode 2 = active slot) and returns its item record.
u8* func_0026a178(s32 idx, s32 mode)
{
    u8* tbl;
    s32 ok;
    if (mode < 0) mode = func_00287bc0();
    if (mode == 2) {
        tbl = func_00281f20(func_00257130());
        ok = func_00281f18(func_00257130());
    } else {
        tbl = func_00281f20(D_0035f0ec);
        ok = func_00281f18(D_0035f0ec);
    }
    if (ok) {
        u16 id = *(u16*)(tbl + idx * 6);
        if (id) return func_001a80c8(id);  // table24_find_by_id
    }
    return 0;
}
}  // namespace n0026a178

// 0026a238 (was src/anon/batch_wcx2.cpp)
namespace n0026a238 {
// 0x0025adf0: definition moved into src/anon/unit_002588e8.cpp

void func_00281b30(u32) asm("func_00281b30");
s32 func_00289358(u32) asm("func_00289358");
void func_00269658(void) asm("func_00269658");
void func_0026a5a0(void) asm("func_0026a5a0");
void func_0026a900(void) asm("func_0026a900");
void func_00269a60(void) asm("func_00269a60");
u32 func_0028b040(u32) asm("func_0028b040");
s32 func_00269508(u32) asm("func_00269508");
u32 func_0028af88(u32) asm("func_0028af88");
s32 func_00283ab8(s32) asm("func_00283ab8");
s32 func_00258068(s32) asm("func_00258068");
// get_global_bit
void func_00256cc0(s32, s32, s32) asm("func_00256cc0");
void func_0028af18(u32, u32) asm("func_0028af18");
/*TARGET 0026a238*/
void func_0026a238(u32 p, s32 k) asm("func_0026a238");
void func_0026a238(u32 p, s32 k)
{
    func_00281b30(p);
    if (func_00289358(p)) {
        if (k == 2) {
            func_00269658();
        } else if ((u32)(k - 5) < 5) {
            func_0026a5a0();
            func_0026a900();
        }
    } else if ((u32)(k - 5) < 5) {
        func_0026a900();
    }
    func_00269a60();
    if (k != 2) return;
    s32 st = func_00269508(func_0028b040(p));
    u32 f = func_0028af88(p);
    if (st == 4) f |= 0x200;
    else f &= ~0x200;
    s32 snd = -1;
    if ((st == 4 && func_00283ab8(0)) || (st == 1 && func_00283ab8(3))) {
        f |= 0x400;
        snd = 0xcbdd;
    } else {
        f &= ~0x400;
    }
    if (func_00258068(1)) func_00256cc0(0xb619, 0xb61a, snd);  // get_global_bit
    else if (snd >= 0) func_00256cc0(snd, -1, -1);
    func_0028af18(p, f);
}
}  // namespace n0026a238

// 0026a3b8 (was src/anon/batch_w108.cpp)
namespace n0026a3b8 {
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035f03c asm("D_0035f03c");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f01c asm("D_0035f01c");
extern s16 D_003737e8[] asm("D_003737e8");
u8* func_00257770(void) asm("func_00257770");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028d008(void*) asm("func_0028d008");
void func_00139510(void*) asm("func_00139510");
void func_00256c40(void) asm("func_00256c40");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00269508(s32) asm("func_00269508");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
u8* func_0028d0e0(void*) asm("func_0028d0e0");
void func_00138c78(u32, s32*, s32*) asm("func_00138c78");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
s32 func_0028b040(u32) asm("func_0028b040");
void func_00256bb0(u8*) asm("func_00256bb0");
/*TARGET 0026a3b8*/
void func_0026a3b8(void* target, u8 follow) asm("func_0026a3b8");
void func_0026a3b8(void* target, u8 follow)
{
    u8* work = func_00257770();
    u8* obj = work + 816;
    s32 active = func_00139d78(obj);
    s32 mode = func_00287bc0();
    s32 kind;
    s32 x;
    s32 y;

    if (func_0028d008(target)) {
        if (!active) {
            s32 id = 249;
            s32 n = D_0035f3d4 + 2;
            if (mode != 2) {
                kind = func_00269508(func_002570a0(2));
                id = D_003737e8[kind + 5];
            }
            func_0028d8c0(obj, n, D_0035ef68, D_0035ef64, D_0035f03c, id, -1, 0);
            func_0028dcc0(obj, work);
            func_00138c78(*(u32*)(func_0028d0e0(target) + 396), &x, &y);
            func_00138c68(obj, x, y);
        }
        if (follow) {
            func_00138c78(*(u32*)(func_0028d0e0(target) + 396), &x, &y);
            func_00138c68(obj, x, y);
        }
        if (func_00139d78(work + 2504) && !follow) return;
        if (mode == 2) {
            kind = func_00269508(func_0028b040(D_0035f01c));
        } else {
            kind = func_00269508(func_002570a0(2));
        }
        if (mode == 2 && kind == 4) {
            func_00256bb0(func_0028d0e0(target));
            return;
        }
    } else {
        if (active) {
            func_00139510(obj);
            return;
        }
    }
    if ((u32)(mode - 5) < 2) return;
    func_00256c40();
}
}  // namespace n0026a3b8

