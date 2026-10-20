#include "../common/types.h"

extern "C" {

/* 001c0410 */
struct w1736_S1 { u8 pad[0x1c]; s32 x1c; };
struct w1736_S2 { u8 pad[0x26]; union { u16 h26; u8 b; }; };
struct w1736_E { s32 x30; f32 f34; };
struct w1736_S0 { u8 pad[0x30]; w1736_E e[4]; };

void func_001c0410(w1736_S0* a, w1736_S1* b, w1736_S2* c) {
    for (s32 i = 0; i < 4; i++) {
        if (a->e[i].x30 == 0) {
            a->e[i].x30 = b->x1c;
            a->e[i].f34 = c->h26;
            return;
        }
    }
}

/* 0026ff30 */
s32 w1736_GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void w1736_SetState(s32) asm("_ZN2Tz8Selector8SetStateEi");
void func_00257388(s32, s32);
void func_002571e0(s32);
struct w1736_B { u8 b; };
extern w1736_B D_0035f128;
extern w1736_B D_0035f130;

void func_0026ff30(void) {
    D_0035f130.b = w1736_GetMode();
    D_0035f128.b = 0;
    func_00257388(0x846a, 0);
    func_002571e0(1);
    w1736_SetState(0);
}

/* 002d5bd8 */
struct w1736_In { u8 p[4]; s32 kind; };
struct w1736_Ob { u8 p[0xc]; w1736_In* in; };
u8 func_00179b68(w1736_Ob*);

s32 func_002d5bd8(w1736_Ob* o) {
    u32 k = o->in->kind;
    if ((k ^ 0x38) == 0 || (k ^ 0x37) == 0) return 1;
    return func_00179b68(o);
}

}
