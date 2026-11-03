// 002afaf0 (w3694): built with -g -fno-strict-aliasing (_gnsa).
// Partial asm: register pins on a0/a1 of the 2nd func_0028d8c0 call only, to set the a1-before-a0 move order (sched1 tie). No code emitted.
#include "../common/types.h"
struct S638 { u8 pad[28]; s16 a[2]; s16 b[2]; s16 c; s16 d; u8 pad2[4]; s32 f44; s32 f48; u32 flags; };
struct Obj { union { u32 w; s16 h; }; u8 sub[4]; };
union U638 { S638* p; s16 h; u32 w; u8 c; };
extern "C" {
s32 func_00276348(void);
s32 func_002766d0(void);
Obj* func_002b23e0(s32);
void func_002b3420(s32);
void func_00276e78(void);
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(s32);
void func_0028dcc0(s32, s32);
s32 func_0023aa98(s32);
void func_00138c68(s32, s32, s32);
void func_001395f8(s32);
s32 func_002b1aa0(void);
s32 func_00192048(s32);
void func_002b1af0(void);
void func_002b24c8(void);
void func_002b1a00(void);
void func_002766b0(s32);
void func_00287cc0(s32);
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern U638 D_0035f638;
extern s32 D_0035f634;
extern s8 D_00374cd0[2][4];
extern s16 D_00374cc0[2];
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


}
