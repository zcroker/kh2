#include "../common/types.h"

/* 0019c590: summon availability test. The callee is a member function that
   uses this == a0 unchanged, so it is declared (void): passing s would make
   gcc copy a0 into a pseudo after the prologue and stop the load hoisting. */
typedef struct Sum { u8 pad[0x588]; u32 w; } Sum;
s32 Sum_GetMode0(void) asm("_ZN2YS6SUMMON7GetModeEv");
s32 func_0019c590(Sum* s) {
    u32 w = s->w;
    if (w & 4) return 0;
    if (w & 0x40) return 0;
    return Sum_GetMode0() == 1;
}

/* 001a1950: forward to the object's virtual method, else to the 3-argument
   entry12_add_clamped (func_001a1910 reads only a0..a2). */
typedef struct VT_1a1950 { void* f[30]; s32 (*m)(void*, s32, s32, u8); } VT_1a1950;
typedef struct Obj_1a1950 { VT_1a1950* vt; } Obj_1a1950;
s32 func_001a1910(void*, s32, s32);
s32 func_001a1950(void* a0, s32 a1, s32 a2, u8 a3) {
    Obj_1a1950* o = *(Obj_1a1950**)((u8*)a0 + 0x25c);
    if (o == 0) return func_001a1910(a0, a1, a2);
    return o->vt->m(o, a1, a2, a3);
}
