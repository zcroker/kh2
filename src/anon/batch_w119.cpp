#include "../common/types.h"
extern "C" {
extern u32 D_0035f634;
extern u32 D_0035f14c;
extern u32 D_0035f148;
extern u32 D_0035f210;
extern u8* D_0035f638;
extern u8 D_00374ce8[];
u16* func_002b23e0(s32);
u8* func_001a80c8(u32);
void func_00281cf0(u32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
void func_00139688(u8*);
u32 func_00192048(u32);
u32 func_001a37e8(u32, s32);
void func_00192c90(u32, u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_0028dcc0(u8*, u8*);
void func_00138c68(u8*, s32, s32);
void func_002817d8(s32, u32, u32, u32, s32, s32, u8*);
void func_00281e70(u8*);
void func_00281e20(void);
void func_00242618(s32, s32);
void func_00287cc0(s32);
// Sets up a menu screen: title/background layouts, the selected entry's name and icon.
void func_002b12a0(void)
{
    u16 id = *func_002b23e0(-1);
    u8* info = func_001a80c8(id);
    func_00281cf0(*(u16*)(info + 20));
    func_0028d8c0((u8*)D_0035f634 + 21624, 30061, D_0035f14c, D_0035f148, D_0035f210, 125, 126, 0);
    u8* o = (u8*)D_0035f634 + 23776;
    func_0028d980(o, 30061, D_0035f14c, D_0035f148, D_0035f210, 122, 123, -1, 0);
    func_00139620(o);
    *(u32*)(o + 432) = 2;
    *(u32*)(o + 408) = func_00192048(20689);
    o = (u8*)D_0035f634 + 22904;
    u8* sub = o + 24;
    func_0028d980(o, 30061, D_0035f14c, D_0035f148, D_0035f210, 128, 129, -1, 0);
    *(u32*)(o + 432) = 2;
    func_00139620(o);
    func_001395f8(o);
    func_00192c90(func_001a37e8(id, -1), D_0035f638 + 56);
    *(u8**)(o + 408) = D_0035f638 + 56;
    s32 x = func_0023aa18(sub);
    s32 y = func_0023aa38(sub);
    o = (u8*)D_0035f634 + 23340;
    func_0028d980(o, 30061, D_0035f14c, D_0035f148, D_0035f210, 3, -1, -1, 0);
    func_0028dcc0(o, (u8*)D_0035f634 + 22904);
    *(u32*)(o + 432) = 2;
    func_00139620(o);
    func_00138c68(o, x, y);
    func_00139688(o);
    *(u32*)(o + 408) = func_00192048(*(u16*)(info + 10));
    func_002817d8(30062, D_0035f14c, D_0035f148, D_0035f210, 0, 0, D_00374ce8);
    func_00281e70((u8*)D_0035f634 + 21624);
    func_00281e20();
    func_00242618(19, 1);
    func_00287cc0(0);
}

struct Gauge {
    u8* lay;
    u8* link;
    u16 tbl[3][4];
    s32 maxv;
    s32 cur;
    s32 f40;
    s32 w0;
    s32 w1;
};
void func_0028be58(Gauge*);
void func_0028e0d8(u8*, s32, s32, s32, u16*, s32, s32);
void func_0028e5e0(u8*, u16*, s32);
u8* func_0028e798(u8*, s32);
s32 func_0023aa58(u8*);
double func_00313b80(f32);
s32 func_003142e0(double, double);
void func_0028e748(u8*, s32, u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_0028e710(u8*, u8*);
void func_0028e870(u8*, s32, s32);
void func_00139660(u8*);
void func_00139688(u8*);
void func_0028eb88(u8*, s32, f32, f32);
void func_0028e8b8(u8*, s32, s32, s32);
// Gauge layout setup: copies the frame table, links the bar and scales it by cur/total (clamped to 1).
void func_0028bae0(Gauge* g, s32 a, s32 b, s32 c, u16 (*src)[4], s32 total, s32 cur, u8* link)
{
    func_0028be58(g);
    for (s32 i = 0; i < 3; i++)
        for (s32 j = 0; j < 4; j++)
            g->tbl[i][j] = src[i][j];
    func_0028e0d8(g->lay, a, b, c, g->tbl[0], 4, 0);
    func_0028e5e0(g->lay, g->tbl[2], 4);
    g->link = link;
    g->f40 = 0;
    g->cur = cur;
    g->maxv = total < cur ? cur : total;
    if (!link)
        g->w0 = func_0023aa58(func_0028e798(g->lay, 0));
    else
        g->w0 = func_0023aa58(link + 24);
    s32 w1 = func_0023aa58(func_0028e798(g->lay, 2));
    g->w1 = w1;
    f32 r = (f32)cur / (f32)total;
    if (func_003142e0(1.0, func_00313b80(r)) <= 0)
        r = 1.0f;
    f32 sc = (f32)g->w0 / (f32)w1 * r;
    if (g->link == 0) {
        u8* p = func_0028e798(g->lay, 0);
        func_0028e748(g->lay, 1, p);
        func_0028e748(g->lay, 2, p);
        func_0028e748(g->lay, 3, p);
    } else {
        s32 x = func_0023aa18(g->link + 24);
        s32 y = func_0023aa38(g->link + 24);
        func_0028e710(g->lay, g->link);
        func_0028e870(g->lay, x, y);
        func_00139660(g->lay);
        func_00139688(g->lay);
    }
    func_0028eb88(g->lay, 2, 1.0f, sc);
    func_0028e8b8(g->lay, 3, 0, (s32)((f32)g->w1 * sc));
}
}
