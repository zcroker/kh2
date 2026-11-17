#include "../common/types.h"

extern "C" {

extern u32 D_0034f240;
void w191ee0(u32, u32, u32, u32) asm("_Z16wtarget_00191ee0jjjj");
// 00191ee0: static initialiser, now made by gcc in src/yasui/libys/status.cpp

extern u32 D_01d49970;
// 0x1c8d40: moved to src/yasui/libys/summon.cpp

extern u32 D_003638d0;
void w2ef890(u32, u32, u32, u32) asm("_Z16wtarget_002ef890jjjj");
// 002ef890: moved to src/anon/unit_002ef6b0.cpp

struct W2 { u32 a; u32 b; };

extern W2 D_01c6cba0;
void w1a8570(u32, u32, u32, u32) asm("_Z16wtarget_001a8570jjjj");
// 001a8570: static initialiser, now made by gcc in src/anon/unit_001a82f0.cpp

extern W2 D_01d48de0;
void w1ba798(u32, u32, u32, u32) asm("_Z16wtarget_001ba798jjjj");
// 001ba798: static initialiser, now made by gcc in src/yasui/libys/itemeffect.cpp

extern W2 D_01d5ba20;
void w1d3bc0(u32, u32, u32, u32) asm("_Z16wtarget_001d3bc0jjjj");
// 001d3bc0 (static init): moved to src/anon/unit_001d35e0.cpp

extern u32 D_003511b8;
extern u32 D_01d48cb8;
void w1b8290(u32, u32, u32, u32) asm("_Z16wtarget_001b8290jjjj");
void w1b8290(u32 a, u32 b, u32, u32);  // 0x001b8290: definition moved into src/anon/unit_001b6a50.cpp

extern f32 D_00349e14;
void func_00239230(u8* p);  // 0x00239230: definition moved into src/anon/unit_002384f8.cpp

void dkMap_setVisibleGroup(u32) asm("_ZN2dk3Map15setVisibleGroupEj");
void func_0015f6e8(void);
void func_0015e018(void);
void func_001e2a78(void);  // 0x001e2a78: definition moved into src/anon/unit_001e0cb8.cpp

extern u32 D_00363540;
void func_002eb778(void*, u32, u32);
// 002eb868: moved to src/anon/unit_002eaf38.cpp

struct S8 { u32 a, b; void (*fn)(u32, void*); };
void func_00319190(S8* p);  // 0x00319190: definition moved into src/libgcc/unwind-dw2.c

// 00102ff0: moved to src/common/title.cpp

/* the original has three nops in the loop body (hand-placed delay padding) */
// 001879f0: moved to src/anon/unit_00185d10.cpp
void func_001879f0(u32* p);

void func_001bf118(u8* p, s32 b);  // 0x001bf118: definition moved into src/anon/unit_001bc568.cpp

void func_001e0dc8(void*);
void func_001e1698(u8* p);  // 0x001e1698: definition moved into src/anon/unit_001e0cb8.cpp

}
