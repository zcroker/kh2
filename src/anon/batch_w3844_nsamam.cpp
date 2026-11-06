#include "../common/types.h"
extern "C" {
u8* func_002766d0(void);
void func_002fde18(void*, s32, s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_0023aa78(u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00139620(u8*);
void func_00138c68(u8*, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_00138c10(u8*, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
extern u8* D_0035f604;
extern s32 D_0035f3d4;
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f210;

/* 002a7f58: sets up 10 rows of three sprites (two 436-byte items in D_0035f604's table at 872 bytes per row,
   plus one 408-byte item at w+0xa998), each placed from its parent and given draw flags 0x60000008. */
void func_002a7f58(void) {
    s32 i = 0;
    s32 off = 0;
    u8* w = func_002766d0();
    u32 flags = 0x60000000; /* top bits 29-30 = 3 */
    func_002fde18(D_0035f604 + 8720, 0, 320);
    s32 base = D_0035f3d4;
    u8* q = w + 0xa998;
    u8* a;
    for (; i < 10; i++) {
        a = D_0035f604 + off;
        func_0028d980(a, base, D_0035f14c, D_0035f148, D_0035f210, 108, -1, -1, 0);
        s32 x = func_0023aa78(a + 24);
        s32 y = func_0023aa18(a + 24);
        s32 z = func_0023aa38(a + 24);
        func_00139620(a);
        func_00138c68(a, 0, x * i);
        func_0028dcc0(a, w);
        *(s32*)(a + 428) = 3;
        u32 f = flags | 8; /* loop-invariant: hoisted after base+1/base+2 like the original */
        *(u32*)(a + 420) = f;
        func_00138c10(a, 2);
        a = D_0035f604 + off + 436;
        func_0028d980(a, base + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, -1, 0);
        func_00139620(a);
        func_00138c68(a, y, z);
        func_0028dcc0(a, D_0035f604 + off);
        off += 872;
        *(s32*)(a + 428) = 3;
        *(u32*)(a + 420) = f;
        *(s32*)(a + 432) = 1;
        *(u8**)(a + 408) = D_0035f604 + i * 32 + 8720;
        func_0028d8c0(q, base + 2, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        func_0028dcc0(q, a);
        q += 408;
    }
}
}
