// Linked unit (see linked_units.tsv).
#include "../common/types.h"
#include <stdarg.h>

// 002af748 (was src/anon/batch_wcx2.cpp)
namespace n002af748 {
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
// 0x0029ba88: definition moved into src/anon/unit_0029ba88.cpp

// ---- 002af748
struct Win2af { u8 pad[486]; u16 flags; };
extern void* D_0035f200 asm("D_0035f200");
Win2af* func_002a9d68(void) asm("func_002a9d68");
s32 func_00289380(void* s) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287c10(void) asm("func_00287c10");
s32 func_00276368(void) asm("func_00276368");
s32 func_0028acc8_f748(void* s) asm("func_0028acc8");
s32 func_00276888(void) asm("func_00276888");
void func_00287f90(s32 a) asm("func_00287f90");
void func_002aecf0(s32 a) asm("func_002aecf0");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18_f748(void* s, u32 a) asm("func_0028af18");
s32 func_00276358(void) asm("func_00276358");
void func_00276220(s32 a, s32 b) asm("func_00276220");
void func_002aed60(void) asm("func_002aed60");
void func_002afaf0(void) asm("func_002afaf0");
void func_002b01d8(void) asm("func_002b01d8");
s32 func_00289310_f748(void* s) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
// state_is_150
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32 a) asm("func_00287c90");
void func_002b3b78_x5147(void) asm("func_002b3b78");
s32 func_00287df0_f748(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a) asm("func_00242848");
void func_0028f6f0(s32 a) asm("func_0028f6f0");
// record884_refresh_by_index
void func_002aece8(void) asm("func_002aece8");
void func_00276dc0(void) asm("func_00276dc0");
void func_00287c00(s32 m) asm("func_00287c00");
void func_00287cc0(s32 s) asm("func_00287cc0");
s32 func_002891e8_f748(void* s) asm("func_002891e8");
s32 func_0028b038(void* s) asm("func_0028b038");
void func_002765e8(s32 a, s32 b, s32 c) asm("func_002765e8");
void func_00287da0(void) asm("func_00287da0");
s32 func_002b2338(s32 a) asm("func_002b2338");
void func_002b2428(s32 a) asm("func_002b2428");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 002af748*/
// global_zero_4dwords

void func_002af748(void) asm("func_002af748");
// global_zero_4dwords

void func_002af748(void) {
    Win2af* w = func_002a9d68();
    s32 cur = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        s32 next = func_00287c10();
        if (func_00276368() || func_0028acc8_f748(D_0035f200) || func_00276888()) {
            if (cur == -1) return;
            func_00287f90(0);
            func_002aecf0(next != 29);
            return;
        }
        func_002aecf0(next != 29);
        func_00287c30();
        s32 mode = func_00287bc0();
        func_0028af18_f748(D_0035f200, 115);
        func_00276220(func_00276358(), 0);
        switch (mode) {
        case 27: func_002aed60(); break;
        case 29: func_002afaf0(); break;
        case 30: func_002b01d8(); break;
        }
        return;
    }
    if (cur != -1 || func_00289310_f748(D_0035f200)) {
        if (!func_00276398()) {  // state_is_150
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (!func_00242848(func_00287df0_f748(cur, func_00289310_f748(D_0035f200), 1, func_002b3b78_x5147, 1))) {
        switch (cur) {
        case -2: {
            func_0028f6f0(1);  // record884_refresh_by_index
            func_002aece8();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(27);
            func_00287cc0(2);
            s32 m = func_00287bc0();
            s32 a = func_002891e8_f748(D_0035f200);
            func_002765e8(m, a, func_0028b038(D_0035f200));
            break;
        }
        case -4: {
            s32 m = func_00287bc0();
            s32 a = func_002891e8_f748(D_0035f200);
            func_002765e8(m, a, func_0028b038(D_0035f200));
            func_00287da0();
            break;
        }
        case -1:
            break;
        default: {
            func_002aece8();
            func_00276dc0();
            func_00276220(0, 1);
            func_00287cc0(2);
            s32 m = func_00287bc0();
            s32 a = func_002891e8_f748(D_0035f200);
            func_002765e8(m, a, func_0028b038(D_0035f200));
            if (w->flags & 1) {
                func_00287c00(29);
                func_002b2428(func_002b2338(func_002891e8_f748(D_0035f200)));
            } else {
                func_00287c00(30);
            }
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002af748

// 002afaf0 (was src/anon/batch_w3694_gnsa.cpp)
namespace n002afaf0 {
struct S638 { u8 pad[28]; s16 a[2]; s16 b[2]; s16 c; s16 d; u8 pad2[4]; s32 f44; s32 f48; u32 flags; };
struct Obj { union { u32 w; s16 h; }; u8 sub[4]; };
union U638 { S638* p; s16 h; u32 w; u8 c; };
s32 func_00276348(void) asm("func_00276348");
s32 func_002766d0(void) asm("func_002766d0");
Obj* func_002b23e0(s32) asm("func_002b23e0");
void func_002b3420(s32) asm("func_002b3420");
void func_00276e78(void) asm("func_00276e78");
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(s32, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(s32) asm("func_00139620");
void func_0028dcc0(s32, s32) asm("func_0028dcc0");
s32 func_0023aa98(s32) asm("func_0023aa98");
void func_00138c68(s32, s32, s32) asm("func_00138c68");
void func_001395f8(s32) asm("func_001395f8");
s32 func_002b1aa0(void) asm("func_002b1aa0");
s32 func_00192048(s32) asm("func_00192048");
void func_002b1af0(void) asm("func_002b1af0");
void func_002b24c8(void) asm("func_002b24c8");
void func_002b1a00(void) asm("func_002b1a00");
void func_002766b0(s32) asm("func_002766b0");
void func_00287cc0(s32) asm("func_00287cc0");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern U638 D_0035f638 asm("D_0035f638");
extern s32 D_0035f634 asm("D_0035f634");
extern s8 D_00374cd0[2][4] asm("D_00374cd0");
extern s16 D_00374cc0[2] asm("D_00374cc0");
/*TARGET 002afaf0*/
void func_002afaf0(void) asm("func_002afaf0");
void func_002afaf0(void) {
    s32 a, b, i, n, n1, q, attr;
    Obj* o;
    a = func_00276348();
    b = func_002766d0();
    o = func_002b23e0(-1);
    func_002b3420(-1);
    for (i = 0; i < 2; i++) {
        D_0035f638.p->a[i] = 0;
        D_0035f638.p->b[i] = 0;
    }
    D_0035f638.p->c = D_00374cd0[(o->w >> 27) & 1][0];
    attr = 0x60000008;
    D_0035f638.p->d = D_00374cd0[(o->w >> 27) & 1][1];
    D_0035f638.p->flags &= ~0x400;
    D_0035f638.p->flags &= ~0x800;
    D_0035f638.p->flags &= ~0x3000;
    { S638* p = D_0035f638.p; p->f44 = 0; p->f48 = 0; }
    n = D_0035f3d4;
    func_00276e78();
    n1 = n - 1;
    func_0028d8c0(b, n1, D_0035f14c, D_0035f148, D_0035f210, 112, -1, 0);
    n1 = n + 1;
    func_00139620(b);
    func_0028dcc0(b, a);
    q = D_0035f634;
    q += 21216;
    { register s32 r5 asm("$5") = n1; register s32 r4 asm("$4") = q; func_0028d8c0(r4, r5, D_0035f14c, D_0035f148, D_0035f210, D_00374cc0[(o->w >> 27) & 1], -1, 0); }
    func_00139620(q);
    func_0028dcc0(q, a);
    q = D_0035f634 + 22032;
    func_0028d980(q, n1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, -1, 0);
    func_00139620(q);
    func_0028dcc0(q, b);
    *(s32*)(q + 0x1ac) = 3;
    *(s32*)(q + 0x1a4) = attr;
    func_001395f8(q);
    *(s32*)(q + 0x198) = (s32)o->sub;
    q = D_0035f634 + 22468;
    func_0028d980(q, n1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, -1, 0);
    func_00139620(q);
    func_0028dcc0(q, b);
    func_00138c68(q, 0, func_0023aa98(b + 24));
    *(s32*)(q + 0x1ac) = 3;
    *(s32*)(q + 0x1a4) = attr;
    func_001395f8(q);
    *(s32*)(q + 0x198) = func_00192048(func_002b1aa0());
    if (o->w & 0x4000000) func_002b1af0();
    func_002b24c8();
    func_002b1a00();
    func_002766b0(1);
    func_00287cc0(0);
}
}  // namespace n002afaf0

// 002afe18 (was src/anon/batch_w1586_g.cpp)
namespace n002afe18 {
void func_00287cc0(s32) asm("func_00287cc0");
extern s32 D_0035f200 asm("D_0035f200");
// 0x002acc98: definition moved into src/anon/unit_002a99c8.cpp
s32 func_00242848(s32) asm("func_00242848");
s32 func_00275b60() asm("func_00275b60");
s32 func_00276220(s32, s32) asm("func_00276220");
s32 func_00276358() asm("func_00276358");
s32 func_00276368() asm("func_00276368");
s32 func_00276398() asm("func_00276398");
s32 func_002765e8(s32, s32, s32) asm("func_002765e8");
s32 func_00276608(s32) asm("func_00276608");
s32 func_00276888() asm("func_00276888");
s32 func_00276dc0() asm("func_00276dc0");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_00287bd0(s32, s32) asm("func_00287bd0");
s32 func_00287c00(s32) asm("func_00287c00");
s32 func_00287c30() asm("func_00287c30");
s32 func_00287c90(s32) asm("func_00287c90");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00287da0() asm("func_00287da0");
s32 func_00287f90(s32) asm("func_00287f90");
s32 func_00288018() asm("func_00288018");
s32 func_00288040() asm("func_00288040");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_0028b038(s32) asm("func_0028b038");
s32 func_002aece8() asm("func_002aece8");
s32 func_002aecf0(s32) asm("func_002aecf0");
void func_002af418(void) asm("func_002af418");
s32 func_002afaf0() asm("func_002afaf0");
s32 func_002b01d8() asm("func_002b01d8");
s32 func_002b0950() asm("func_002b0950");
s32 func_002b0de0(s32) asm("func_002b0de0");
s32 func_002b0e78(s32) asm("func_002b0e78");
s32 func_002b0fc8(s32) asm("func_002b0fc8");
s32 func_002b1208(s32) asm("func_002b1208");
s32 func_002b12a0() asm("func_002b12a0");
s32 func_002b2220() asm("func_002b2220");
s32 func_002b2338(s32) asm("func_002b2338");
s32 func_002b2428(s32) asm("func_002b2428");
s32 func_002b24c8() asm("func_002b24c8");
s32 func_002b2840() asm("func_002b2840");
s32 func_002b2c80() asm("func_002b2c80");
s32 func_002b2d48() asm("func_002b2d48");
s32 func_002b3050(s32) asm("func_002b3050");
s32 func_002b3318() asm("func_002b3318");
extern u8* D_0035f638 asm("D_0035f638");
/*TARGET 002afe18*/
void func_002afe18(void) asm("func_002afe18");
void func_002afe18(void) {
    s32 f = func_002b0950();
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_002b2220() || func_00276888()) {
            if (f) {
                func_00287f90(0);
                func_002aecf0(1);
            }
            return;
        }
        func_002aecf0(1);
        func_00287c30();
        s32 m = func_00287bc0();
        func_002b2840();
        func_00276220(func_00276358(), 0);
        switch (m) {
        case 28: func_002af418(); return;
        case 30: func_002b01d8(); return;
        case 29:
            func_002b2428(func_002b2338(func_00276608(28)));
            func_002afaf0();
            return;
        }
        return;
    }
    func_002b24c8();
    if (f && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);
    if (!func_002b2d48()) f = 0;
    if (!func_00242848(func_002b0de0(f))) {
        if (f & 0xf0) {
            func_002b3050(0);
        } else if (f & 0xc0000) {
            func_002b0e78(f);
        } else if (f & 0x100) {
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            func_002b2c80();
            func_00287da0();
        } else {
            s32 e = f & 8;
            if (f & 0x30008) {
                if (e && (*(u32*)(D_0035f638 + 0x34) & 0x800)) goto l48;
                func_002aece8();
                func_002b2c80();
                if (e) {
                    func_00276dc0();
                    func_00276220(1, 1);
                    func_00287c00(28);
                    func_00287cc0(2);
                } else {
                    func_002b1208(f);
                    func_00276220(((f >> 16) ^ 1) & 1, 1);
                    func_00287c00(func_00287bc0());
                    func_00287cc0(2);
                }
                goto l49;
            }
            if (f & 0x2000) {
                func_002aece8();
                func_002b2c80();
                func_00276dc0();
                func_00276220(0, 1);
                func_00287c00(30);
                func_00287cc0(2);
            } else if (f & 4) {
            l48:
                func_002b0fc8(f);
            }
        }
    l49:
        if ((f & 0xc0004) && func_002b3318()) {
            func_00287bd0(32, 0);
            func_002b12a0();
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002afe18

