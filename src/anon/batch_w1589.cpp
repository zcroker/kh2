#include "../common/types.h"

extern "C" {

s32 func_00103570(void);
void* func_001063c0(s32, s32);
void func_002fde18(void*, s32, s32);
void func_0029dfc0(void);
void func_0029e4c8(s32);
void func_00276690(s32);
u32 func_0028af88(s32);
void func_0028af18(s32, u32);
void func_00287cc0(s32);
extern s32 D_0035f200;
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_002570a0(s32);
u8* func_00273140(s32);
s32 func_001a6598(u16);
void func_00273760(s32, s32);
extern s32 D_0035f01c;

struct W1589En { u8 x[2]; s8 a; u8 y[2]; s8 b; u8 z[2]; };
struct W1589S { u8 pad[4]; u16 h4; u8 pad6; s8 n; u8 p8[4]; W1589En e[1]; };
/* union with a u16 member: the original reloads the pointer after each u16 store */
union W1589G { W1589S* p; void* v; u16 h; s8 c; };
extern W1589G D_0035f230;

void func_00277020(void)
{
    if (D_0035f230.v == 0) {
        D_0035f230.v = func_001063c0(668, func_00103570());
    }
    func_002fde18(D_0035f230.v, 0, 668);
}

void func_002799b0(void)
{
    s32 i;
    D_0035f230.p->h4 = 0;
    for (i = 0; i < D_0035f230.p->n; i++) {
        W1589S* p = D_0035f230.p;
        if (p->e[i].a) p->h4 += p->e[i].b;
    }
}

void func_0029c568(void)
{
    func_0029dfc0();
    func_0029e4c8(1);
    func_00276690(1);
    func_0028af18(D_0035f200, ((func_0028af88(D_0035f200) & ~0x50) | 0x30000) & ~3);
    func_00287cc0(0);
}

void func_002736f8(void)
{
    s32 s;
    if (func_00287bc0() == 26) s = func_0028b040(D_0035f01c);
    else s = func_002570a0(26);
    func_00273760(s, func_001a6598(*(u16*)(func_00273140(s) + 4)) == 0);
}

}
