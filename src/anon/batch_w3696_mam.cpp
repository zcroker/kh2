// 0026bc10: built with -fmove-all-movables (*_mam.cpp). The D_0035f0f4 / D_0035f010 reads in the third loop go through
// u8 unions so they are reloaded after the f1b0 store, like the original.
#include "../common/types.h"
extern "C" {
struct B4 { u8 b[4]; };
struct Elem { u8 pad0[0x18]; u8 f18[0x198 - 0x18]; s32 f198; u8 pad1[0x1b0 - 0x19c]; s32 f1b0; };
union HU { s16 h; u8 c; };
struct Big { u8 pad0[0x7f8]; Elem e[4]; HU arr[4][4]; };
extern B4* D_0035f0fc;
extern Big* D_0035f0f4;
union BigU { Big* p; u8 c; };
extern BigU D_f0f4u asm("D_0035f0f4");
union U32U { u32 v; u8 c; };
extern U32U D_f010u asm("D_0035f010");
extern u32 D_0035f01c;
extern u32 D_0035f024;
extern u32 D_0035f010;
extern u32 D_0035f03c;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern s32 D_0035f3d4;
extern s32 D_0037382c;
extern s32 D_00373830;
B4* func_00293bc0(void);
void func_002937c0(void);
void func_00288f48(u32, s32, s32, s32, s32);
void func_0028f4d8(s32, s32, s32);
s32 func_00256b68(s32);
void func_0028d8c0(s32, s32, u32, u32, u32, s32, s32, s32);
s32 func_00281100(u32);
s32 func_00281180(u32, s32);
s32 func_00281140(u32, s32);
void func_00288d80(u32, s32, u32, u32, u32, s32, HU*, HU*);
u8* func_002891b8(u32, s32);
void func_00138c10(u8*, s32);
void func_00288e08(u32, s32, s32, s32);
void func_0028dcc0(void*, s32);
s32 func_001a8c78(B4*, s32);
void func_0028d980(Elem*, s32, u32, u32, u32, s32, s32, s32, s32);
s32 func_0023aa98(void*);
void func_00138c68(Elem*, s32, s32);
void func_0028b1b0(u32, s32);
void func_002891f0(u32, s32, s32, s32, s32);
s32 func_0028af88(u32);
void func_0028af18(u32, s32);
void func_00257708(s32);
void func_00287cc0(s32);
void func_0026c140(void);
s32 func_00287bc0(void);
void func_0026c048(void);
void func_0026cb38(void);

void func_0026bc10(void)
{
    s32 i;
    s32 n;
    s32 saved;
    s32 cnt;
    s32 mask;
    s32 sel;
    B4* st = func_00293bc0();
    *D_0035f0fc = *st;
    func_002937c0();
    func_00288f48(D_0035f01c, 64, 128, 0, 0);
    func_00288f48(D_0035f024, 64, 128, 0, 0);
    func_0028f4d8(0, -1, 0);
    s32 h = func_00256b68(1);
    func_0028d8c0(h, 0x753d, D_0035ef68, D_0035ef64, D_0035f03c, 312, 313, 0);
    for (i = 0; i < func_00281100(D_0035f010); i++) {
        for (s32 k = 0; k < 4; k++) (*(Big* volatile*)&D_0035f0f4)->arr[i][k].h = (i != 3) ? 315 : 316;
    }
    n = 0;
    saved = D_0035f3d4;
    D_0035f3d4 = 0x753e;
    for (i = 0; i < 4; i++) {
        if (func_00281180(D_0035f010, i)) {
            func_00288d80(D_0035f01c, n, D_0035ef68, D_0035ef64, D_0035f03c, -1, D_0035f0f4->arr[n], D_0035f0f4->arr[n]);
            func_00138c10(func_002891b8(D_0035f01c, n), D_0035f0f4->arr[n][2].h);
            *(s32*)(func_002891b8(D_0035f01c, n) + 0x188) = -1;
            func_00288e08(D_0035f01c, n, -1, 0);
            func_0028dcc0(func_002891b8(D_0035f01c, n), h);
            n++;
        }
    }
    for (i = 0; i < n; i++) {
        func_0028d980(&D_f0f4u.p->e[i], 0x753e, D_0035ef68, D_0035ef64, D_0035f03c,
                      (i == 0 || func_001a8c78(st, i)) ? D_0037382c : D_00373830, -1, -1, 0);
        func_00138c68(&D_f0f4u.p->e[i], func_0023aa98(D_f0f4u.p->e[i].f18) * i, 0);
        func_0028dcc0(&D_f0f4u.p->e[i], h);
        Elem* e = &D_f0f4u.p->e[i];
        e->f1b0 = 2;
        e = &D_f0f4u.p->e[i];
        e->f198 = func_00281140(D_f010u.v, i);
    }
    cnt = 0;
    sel = n >= 2;
    D_0035f3d4 = saved;
    /* the multi-player branch is the cold path */
    if (__builtin_expect(sel, 0)) {
        mask = 1;
        for (i = 1; i < n; i++) {
            if (func_001a8c78(st, i)) {
                mask |= 1 << i;
                cnt++;
            } else if (func_001a8c78(st, sel)) {
                sel = i;
            }
        }
        func_0028b1b0(D_0035f01c, mask);
    }
    func_002891f0(D_0035f01c, sel, 0, -1, -1);
    if (n < 3 || n - cnt < 3) {
        mask = func_0028af88(D_0035f01c) & ~0x13;
        func_0028af18(D_0035f01c, mask);
        func_00257708(1);
    }
    func_00287cc0(0);
    func_0026c140();
    if (func_00287bc0() == 20) func_0026c048();
    func_0026cb38();
}

}
