// func_002945e8: menu page setup (fill the u16 attribute table, build 18 row pairs, then one row per
// eligible entry). Built with -fno-strict-aliasing -fmove-all-movables (_nsamam).
#include "../common/types.h"
extern "C" {
void func_00138c10(u8*, s32);
void func_00139620(u8*);
void func_00275a80(void);
void func_00275f68(s32, s32);
void func_00276088(s32, s32*, s32*);
u8* func_00276348(void);
s8* func_00276568(void);
void func_00276588(s32);
u8* func_002766d0(void);
s32 func_00276c18(void);
s32 func_00287bc0(void);
void func_00287cc0(s32);
void func_00288d80(s32, s32, s32, s32, s32, s32, u16*, u16*);
void func_00288e88(s32);
u8* func_002891b8(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
s32 func_0028af88(s32);
void func_0028af18(s32, s32);
void func_0028af90(s32, s32);
void func_0028b078(s32, s32, s32);
void func_0028b200(s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
struct T294 { u8 pad[8]; s32 n; };
T294* func_00294000(s32);
s32 func_002941a8(s8*);
void func_00294998(void);
void func_00294e48(void);
void func_00294f78(s32);
s32 func_002952f8(s32);
void func_002955a8(void);
s32 func_002ac9b0(s32);
s32 func_002acb20(s32);
s32 func_002ae908(s32);
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f150;
extern u16 D150h asm("D_0035f150");
extern s32 D_0035f200;
extern s32 D_0035f210;
extern s32 D_0035f3d4;
extern s32 D_003746b4;
extern s32 D_003746b8;

struct Sub208 { u8 pad[184]; s32 flags; };
struct E408 { u8 pad[24]; Sub208 sub; u8 pad2[408 - 212]; };
struct B408 { u8 pad[30360]; E408 e[64]; };
void func_002945e8(void)
{
    u16 arr[2][4];
    s32 a, b;
    s32 i = 0;
    T294* t;
    s8* ents;
    u8* w = func_00276348();
    u8* base = func_002766d0();
    func_00276588(0);
    func_00288e88(D_0035f200);
    func_00294e48();
    func_00275a80();
    func_00276088(func_00287bc0(), &a, &b);
    func_00275f68(a, b);
    t = func_00294000(0);
    ents = (s8*)t + 16;
    do {
        u16* p = (u16*)(i * 8 + (u32)arr);
        s32 j = 3;
        do {
            *p = D150h;
            j--;
            p++;
        } while (j >= 0);
        i++;
    } while (i < 2);
    u8* q = base;
    i = 0;
    s32 v2 = D_0035f3d4 + 2;
    s32 v3 = D_0035f3d4 + 3;
    do {
        func_00288d80(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, arr[0], arr[1]);
        u8* o = func_002891b8(D_0035f200, i++);
        func_00139620(o);
        func_0028dcc0(o, w);
        u8* e = q + 30360;
        func_0028d8c0(e, v2, D_0035f14c, D_0035f148, D_0035f210, D_0035f150, -1, 0);
        func_0028dcc0(e, o);
        ((Sub208*)(q + 30360 + 24))->flags |= 8;
        e = q + 0xa998;
        q += 408;
        func_0028d8c0(e, v3, D_0035f14c, D_0035f148, D_0035f210, D_0035f150, -1, 0);
        func_0028dcc0(e, o);
        { Sub208* s = (Sub208*)(e + 24); s->flags |= 8; }
    } while (i < 18);
    B408* bb = (B408*)base;
    s32 cnt = 0;
    s32 n = t->n;
    if (n > 0) {
        i = n;
        s8* e = ents;
        do {
            if (*e < 16) {
                s32 r = func_002941a8(e);
                s32 c = *e;
                if (r || func_00276c18()) {
                    func_00138c10(func_002891b8(D_0035f200, cnt), 173);
                    *(s32*)(func_002891b8(D_0035f200, cnt) + 392) = -1;
                    if (r) {
                        if (func_002ac9b0(c)) func_00138c10((u8*)&bb->e[cnt + 32], func_002acb20(c) ? D_003746b8 : D_003746b4);
                        if (func_002ae908(c)) func_00138c10((u8*)&bb->e[cnt], 176);
                    }
                    cnt++;
                }
            }
            e += 16;
        } while (--i);
    }
    func_00294f78(0);
    s32 c = *func_00276568();
    if (c < 0) c = 15;
    func_002891f0(D_0035f200, func_002952f8(c), 0, -1, -1);
    func_0028b078(D_0035f200, 6, 3);
    func_0028b200(D_0035f200, 1);
    func_0028af90(D_0035f200, cnt);
    func_0028af18(D_0035f200, func_0028af88(D_0035f200) | 0x3000);
    func_00294998();
    func_002955a8();
    func_00287cc0(0);
}
}
