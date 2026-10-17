#include "../common/types.h"
extern "C" {
extern u8 D_0035f4f0;
extern u32 D_0035f230;
extern u32 D_0035f4ec;
extern s32 D_0035ece0;
extern u32 D_0035f234;
void func_00277020(void);
u32 func_002933d8(u32 a0, u32 a1, u32 a2, u32 a3);
u32 func_00243190(s32);
void func_00243020(u32 a0);
void func_00299290(void);
u8* func_0014aba8(void);
void func_0014aa58(void*, s32, s32);
void func_00287cc0(s32);
u32 func_00103570(void);
u8* func_001063f0(u32, u32);

void func_002936d8(void) { D_0035f4f0 = 1; }

void func_00276fe8(void) { D_0035f230 = 0; func_00277020(); }

void func_00293500(u32 a0, u32 a1, u32 a2) { func_002933d8(a0, a1, a2, D_0035f4ec); }

void Tz_SubMenu_Start(s32 a) asm("_ZN2Tz7SubMenu5StartEi");
void Tz_SubMenu_Start(s32 a) {
    D_0035ece0 = a;
    func_00243020(func_00243190(a));
}

void func_00298e20(u32 a0, s32 a1) {
    if (a1 == 4) func_00299290();
}

void func_0025ee58(void) {
    func_0014aa58(func_0014aba8(), 15, 0);
    func_00287cc0(0);
}

void func_0027c4d8(void) { D_0035f234 = (u32)func_001063f0(10, func_00103570()); }

struct W1587_S { u32 a; u8* b; };
void func_00242088(void*);
u8* func_001063f0_n(u32) asm("func_001063f0");
void func_00241fd0(W1587_S* p, u32 a1) {
    W1587_S* s;
    asm("" : "=r"(s) : "0"(p));  /* keeps p in its own pseudo, as the original stores via s0 */
    s->a = a1;
    s->b = func_001063f0_n(0x400);
    func_00242088(s);
}
}
