#include "../common/types.h"
// func_002f1fb8 is whole-body asm that links elsewhere: C++ linkage makes the call bind to
// the absolute alias _Z13func_002f1fb8v.
void func_002f1fb8();
extern "C" {

// --- 002d5588: true when the linked object's id is 0x38 or 0x37
struct I_w1731 { u8 pad[4]; s32 id; };
struct P_w1731 { u8 pad[12]; I_w1731* i; };
s32 func_002d5588(P_w1731* p) {
    s32 t = p->i->id;
    s32 r = 0;
    if ((t ^ 0x38) == 0 || (t ^ 0x37) == 0) r = 1;
    return r;
}

// --- 002ef340: by-value struct params (spilled, unused), call member at +0x40 then a global update
struct A_w1731 { u32 x, y; };
struct B_w1731 { u16 z, w; };
void func_0023cc18(void*);
void func_002ef618();
void func_002ef340(u8* t, A_w1731 a, B_w1731 b) {
    func_0023cc18(t + 0x40);
    func_002ef618();
}

// --- 0014d680
void func_002f1e18(s32, s32, s32, s32);
void func_0014d6b0();
void u_call0_0014d680(void) asm("_Z16u_call0_0014d680v");
void u_call0_0014d680(void) {
    func_002f1fb8();
    func_002f1e18(0, 1, 2, 0);
    func_0014d6b0();
}

}
