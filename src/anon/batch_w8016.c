#include "../common/types.h"

/* 0019c590: summon availability test. The callee is a member function that
   uses this == a0 unchanged, so it is declared (void): passing s would make
   gcc copy a0 into a pseudo after the prologue and stop the load hoisting. */
typedef struct Sum { u8 pad[0x588]; u32 w; } Sum;
s32 Sum_GetMode0(void) asm("_ZN2YS6SUMMON7GetModeEv");
s32 func_0019c590(Sum* s);  // 0x0019c590: definition moved into src/anon/unit_0019ba60.cpp

/* 001a1950: forward to the object's virtual method, else to the 3-argument
   entry12_add_clamped (func_001a1910 reads only a0..a2). */
typedef struct VT_1a1950 { void* f[30]; s32 (*m)(void*, s32, s32, u8); } VT_1a1950;
typedef struct Obj_1a1950 { VT_1a1950* vt; } Obj_1a1950;
s32 func_001a1910(void*, s32, s32);
s32 func_001a1950(void* a0, s32 a1, s32 a2, u8 a3);  // 0x001a1950: definition moved into src/anon/unit_0019fb70.cpp
