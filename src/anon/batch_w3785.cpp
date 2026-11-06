#include "../common/types.h"
extern "C" {
struct VObj { void (**vt)(VObj*); };
s32 func_00287db0(void);
s32 func_00139d78(VObj*);
s32 func_0028acc8(u32);
void func_0028abe0(u32);
s32 func_00289310(u32);
void func_002890e0(u32, s32, s32, s32, s32);
u32 func_002891e8(u32);
void func_00289038(u32, u32, s32, s32, s32, s32, s32);
void func_0027fcc0(void);
extern VObj* D_0035f250;
extern VObj* D_0035f258;
extern u32 D_0035f254;

void func_0027fba0(void) {
    if (func_00287db0()) {
        /* empty barrier: keeps reorg from filling the beqz slot from the if body (orig: beqzl stealing lui s1) */
        asm volatile("");
        if (func_00139d78(D_0035f250)) D_0035f250->vt[5](D_0035f250);
        if (func_00139d78(D_0035f258)) D_0035f258->vt[5](D_0035f258);
        if (func_0028acc8(D_0035f254)) func_0028abe0(D_0035f254);
        s32 i = 0; s32 c;
        do {
            i++;
            c = i < 9;
            __asm__("nop"); /* hand-written delay nops */
            __asm__("nop");
            __asm__("nop");
            __asm__("nop");
        } while (c);
    }
    if (!func_00289310(D_0035f254)) return;
    u32 r = func_002891e8(D_0035f254);
    func_002890e0(D_0035f254, 1, 2, 0, -1);
    func_00289038(D_0035f254, r, 1, 1, 2, 0, -1);
    func_0027fcc0();
}
}
