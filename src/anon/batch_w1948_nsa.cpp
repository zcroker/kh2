#include "../common/types.h"
extern "C" {
u8* func_00257770(void);
s32 func_0028b038(s32);
void func_0028be78(s32, s32);
s32 func_002570a0(s32);
s32 func_00257140(s32);
void func_00138c10(void*, s32);
u8* func_0027bba0(s32);
s32 func_00192048(u16);
s32 func_00192cc0(void*, void*, s32);
void func_0027aed8(s32, s32*, s32*);
s32 func_0027af58(void);
s32 func_0027c3b8(s32);
struct S436 { u8 p[408]; s32 v; u8 q[24]; };
struct E27aaa0 { s8 a; s8 b; u8 pad[6]; };
extern s32 D_0035f01c;
extern s32 D_0035f04c;
extern u8* D_0035f230;
extern u8 D_00373de0;
extern u16 D_00373e60[];
void func_0027aaa0(void) {
    s32 a, b;
    u8* w = func_00257770();
    u8* o = w + 24304;
    func_0028be78(D_0035f04c, func_0028b038(D_0035f01c));
    s32 k = func_002570a0(16);
    func_00138c10(o, func_00257140(0));
    *(s32*)(o + 408) = func_00192048(*(u16*)(func_0027bba0(k) + 8));
    o = w + 2068;
    *(s32*)(o + 408) = func_00192cc0(w + 0xb170, &D_00373de0, ((E27aaa0*)(D_0035f230 + 16))[k].b);
    func_0027aed8(func_002570a0(15), &a, &b);
    s32 f = func_0027af58();
    s32 m = func_002570a0(16);
    s8 t = ((E27aaa0*)(D_0035f230 + 16))[m].a;
    s32 n;
    if (a != 0) goto two;
    n = 2;
    if (b == 0) goto go;
    if (f != 0) goto go;
    if (t != 0) goto go;
    n = 4;
    if (func_0027c3b8(m) == 0) goto go;
two:
    n = 2;
go:
    for (k = 0; k < n; k++) {
        func_00138c10(&((S436*)(w + 24740))[k], func_00257140(0));
        ((S436*)(w + 24740))[k].v = func_00192048(D_00373e60[k != 0]);
    }
}
}
