// zl90 w3912: matched under -fmove-all-movables (_mam). Keys: n+1 and n+2 written inline in the loop
// calls (loop.c hoists them, so n keeps few refs and lands in s8), the third argument of
// func_00138c68 written as i * h (a loop.c giv whose zero init sorts after the pointer giv init).
#include "../common/types.h"
namespace n002995e8 {
struct E { u8 pad[408]; };
struct Obj { u8 pad[30360]; E a[32]; E b[12]; };
extern "C" {
extern void* D_0035f200;
extern s32 D_0035f3d4;
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f210;
void* func_00276348(void);
Obj* func_002766d0(void);
void func_00276588(s32);
void func_00288e88(void*);
void func_0029fbf0(void);
void func_0029a2a0(void);
void func_00275a80(void);
s32 func_00287bc0(void);
void func_00276088(s32, s32*, s32*);
void func_00275f68(s32, s32);
s32 func_00295430(s32, s32);
void func_00275e68(s32);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(void*);
void func_0028dcc0(void*, void*);
s32 func_0023aa78(void*);
void func_00288d80(void*, s32, s32, s32, s32, s32, s16*, s16*);
u8* func_002891b8(void*, s32);
void func_00138c68(void*, s32, s32);
void func_0029a3e0(s32);
s32 func_00276608(s32);
void func_002891f0(void*, s32, s32, s32, s32);
void func_002765e8(s32, s32, s32);
void func_00299920(void);
s32 func_0028af88(void*);
void func_0028af18(void*, s32);
void func_0029a740(void);
void func_00287cc0(s32);

void func_002995e8(void) {
    s16 a[2][4];
    s32 x, y;
    s32 i, j;
    s32 n;
    s32 h;
    i = 0;
    void* c = func_00276348();
    Obj* o = func_002766d0();
    func_00276588(2);
    func_00288e88(D_0035f200);
    func_0029fbf0();
    func_0029a2a0();
    func_00275a80();
    func_00276088(func_00287bc0(), &x, &y);
    func_00275f68(x, y);
    func_00275e68(func_00295430(15, 0));
    for (; i < 2; i++) {
        for (j = 0; j < 4; j++) a[i][j] = 3;
    }
    n = D_0035f3d4 - 1;
    func_0028d8c0(o, n, D_0035f14c, D_0035f148, D_0035f210, 155, -1, 0);
    func_00139620(o);
    func_0028dcc0(o, c);
    u8* o2 = (u8*)o + 816;
    func_0028d8c0(o2, n, D_0035f14c, D_0035f148, D_0035f210, 165, -1, 0);
    func_00139620(o2);
    func_0028dcc0(o2, c);
    h = func_0023aa78((u8*)o + 24);
    n = D_0035f3d4;
    for (i = 0; i < 12; i++) {
        func_00288d80(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, a[0], a[1]);
        u8* p = func_002891b8(D_0035f200, i);
        func_00139620(p);
        func_0028dcc0(p, o);
        func_00138c68(p, 0, i * h);
        E* e = &o->a[i];
        func_0028d8c0(e, n + 1, D_0035f14c, D_0035f148, D_0035f210, 3, -1, 0);
        func_0028dcc0(e, p);
        e = &o->b[i];
        func_0028d8c0(e, n + 2, D_0035f14c, D_0035f148, D_0035f210, 3, -1, 0);
        func_0028dcc0(e, p);
    }
    func_0029a3e0(0);
    func_002891f0(D_0035f200, func_00276608(func_00287bc0()), 0, -1, -1);
    func_002765e8(func_00287bc0(), 0, 0);
    func_00299920();
    func_0028af18(D_0035f200, func_0028af88(D_0035f200) | 0x3000);
    func_0029a740();
    func_00287cc0(0);
}
}
}
