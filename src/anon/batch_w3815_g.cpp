// func_00296588: builds a menu page (two 816-byte items, two pairs of 436-byte sprites, one list row).
// Built with -g (_g). Register pin: one variable in s0 holds the second item, then the constant 1.
#include "../common/types.h"
extern "C" {
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f200;
extern s32 D_0035f210;
extern s32 D_0035f3d4;
void func_001395f8(u8*);
void func_00139620(u8*);
u8* func_00276348();
void func_00276690(s32);
u8* func_002766d0();
void func_00287cc0(s32);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
void func_00288e88(s32);
u8* func_002891b8(s32, s32);
void func_0028af28(s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_002960d0();
void func_002969e0();
void func_00296b80(s32);
struct Sub { u8 pad[0xb8]; u32 fl; };
void func_00296588(void)
{
    u8 *cam, *w; s32 base, id; u8 *cur, *par, *par2; Sub* s;
    s16 tab[4];
    // One s0 variable: first the second 816-byte item, then the constant 1 stored to the 0x195 flags.
    register u32 one asm("$16");
    cam = func_00276348();
    w = func_002766d0();
    func_00288e88(D_0035f200);
    func_002969e0();
    for (s32 i = 0; i < 4; i++) tab[i] = 3;
    base = D_0035f3d4;
    id = base - 1;
    func_0028d8c0(w, id, D_0035f14c, D_0035f148, D_0035f210, 163, -1, 0);
    one = (u32)w + 0x330; asm("" : "+r"(one));
    func_00139620(w);
    func_0028dcc0(w, cam);
    func_0028d8c0((u8*)one, id, D_0035f14c, D_0035f148, D_0035f210, 166, -1, 0);
    id = base + 3;
    func_00139620((u8*)one);
    func_0028dcc0((u8*)one, cam);
    one = 1;
    cur = w + 0x660;
    func_0028d980(cur, id, D_0035f14c, D_0035f148, D_0035f210, 170, -1, -1, 0);
    func_001395f8(cur);
    func_0028dcc0(cur, cam);
    par = cur;
    cur = w + 0x814;
    s = (Sub*)(w + 0x678); s->fl |= 8;
    par[0x195] = one;
    func_0028d980(cur, id, D_0035f14c, D_0035f148, D_0035f210, 3, -1, -1, 0);
    func_00139620(cur);
    func_0028dcc0(cur, par);
    *(s32*)(cur + 0x1B0) = 2;
    s = (Sub*)(w + 0x82C); s->fl |= 8;
    cur[0x195] = one;
    cur = w + 0x9C8;
    func_0028d980(cur, id, D_0035f14c, D_0035f148, D_0035f210, 171, -1, -1, 0);
    func_001395f8(cur);
    func_0028dcc0(cur, cam);
    par2 = cur;
    cur = w + 0xB7C;
    s = (Sub*)(w + 0x9E0); s->fl |= 8;
    par2[0x195] = one;
    func_0028d980(cur, id, D_0035f14c, D_0035f148, D_0035f210, 3, -1, -1, 0);
    func_00139620(cur);
    func_0028dcc0(cur, par2);
    *(s32*)(cur + 0x1B0) = 2;
    s = (Sub*)(w + 0xB94); s->fl |= 8;
    cur[0x195] = one;
    func_00288d80(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, tab, tab);
    func_00139620(func_002891b8(D_0035f200, 0));
    func_0028dcc0(func_002891b8(D_0035f200, 0), w);
    func_00296b80(0);
    func_002960d0();
    func_00276690(1);
    func_0028af28(D_0035f200, 16);
    func_00287cc0(0);
}
}
