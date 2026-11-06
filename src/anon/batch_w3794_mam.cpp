#include "../common/types.h"
// Built with -fmove-all-movables (_mam rule).
extern "C" {
extern s32 D_0035ef68;
extern s32 D_0035ef64;
extern s32 D_0035f03c;
extern s32 D_0035ef6c;
u8* func_00257770(void);
void func_00139d78(u8*);
s32 func_00257140(s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
s32 func_0023aa98(u8*);
s32 func_0023aa78(u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00139620(u8*);
void func_00139688(u8*);
void func_001395f8(u8*);
void func_00138c68(u8*, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_00138c10(u8*, s32);

// Builds the 18 menu tiles: a base sprite plus two overlays per tile, laid out
// two per row.
void func_00271900(void) {
    s32 i;
    u8* g = func_00257770();
    u8* e;
    func_00139d78(g);
    func_0028d8c0(g, 30013, D_0035ef68, D_0035ef64, D_0035f03c, 140, 141, 100);
    i = 0;
    e = g;
    do {
        u8* p = e + 13840;
        u8* b = e + 13864;
        u8* q = e + 24304;
        u8* r = e + 3376;
        s32 w, h, x, y, id;
        func_0028d980(p, 30014, D_0035ef68, D_0035ef64, D_0035f03c, 150, -1, -1, 100);
        w = func_0023aa98(b);
        h = func_0023aa78(b);
        x = func_0023aa18(b);
        y = func_0023aa38(b);
        func_00138c10(p, D_0035ef6c);
        func_00138c68(p, (i % 2) * w, (i++ / 2) * h);
        func_0028dcc0(p, g);
        func_00139688(p);
        func_00139620(p);
        id = func_00257140(0);
        func_0028d980(q, 30015, D_0035ef68, D_0035ef64, D_0035f03c, id, -1, -1, 100);
        func_0028dcc0(q, p);
        func_00139620(q);
        func_001395f8(q);
        func_0028d980(r, 30015, D_0035ef68, D_0035ef64, D_0035f03c, id, -1, -1, 100);
        func_0028dcc0(r, p);
        func_00138c68(r, x, y);
        func_00139620(r);
        func_001395f8(r);
        *(s32*)(e + 3808) = 1;
        e += 436;
    } while (i < 18);
}
}
