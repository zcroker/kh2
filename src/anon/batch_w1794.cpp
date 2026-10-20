#include "../common/types.h"
struct W1794_S0 { u8 pad0[0x8C]; s32 a; s32 b; u8 pad1[0xD4-0x94]; s32 c; f32 d; u8 pad2[0x8090-0xDC]; s8 e; };
extern "C" {
s32 func_0016a060(void *);
s32 func_0019c768(void *);
void *func_001b9bc8(void *);
void func_002cf280(void *, s32, s32);

void func_002dd530(W1794_S0 *arg0, s32 arg1) {
    u8 *p;
    arg0->a = arg1;
    arg0->b = 0;
    arg0->c = 0;
    arg0->e = 1;
    p = 0;
    arg0->d = -1.0f;
    while ((p = (u8*)func_001b9bc8(p)) != 0) {
        if ((*(s32*)(p + 0x588) & 0x08000000) && func_0019c768(p) == 0 && func_0016a060(p) == 0x16) {
            func_002cf280(p + 0xAF0, 4, 0);
        }
    }
}
}
