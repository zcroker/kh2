/* helper w3917 2026-11-10: func_001ebe40 in plain C, built with -fno-strict-aliasing (_nsa). */
#include "../common/types.h"

typedef struct { f32 x, y, z; } SpV1ebe40;
typedef struct { u8 pad0[4]; f32 rad; f32 speed; s32 obj; s32 posOff; u8 pad1[4]; s32 velOff; u8 wait; } Spawn1ebe40;
typedef struct { u8 pad0[1]; u8 wait; } SpSt1ebe40;
typedef struct { u8 pad0[12]; s32* off; } SpCtx1ebe40;
typedef struct { u8 pad0[128]; u8* objs; u8 pad1[168 - 132]; u64 b168 : 8, stopA : 8, b170 : 8, dead : 8, stopB : 8, b173 : 24; } Part1ebe40;
typedef struct { u8 pad0[4]; u8* base; } SpObj1ebe40;

extern s32 D_01d9ea9c;
extern Part1ebe40* D_01d9e6e0;
extern f32 D_00359a20[]; /* sine table, 4096 entries for a 65536 turn */
SpObj1ebe40* func_001e7a98(Part1ebe40*, u8*);

#define SIN1ebe40(a) D_00359a20[((u32)(a) >> 4) & 0xfff]
#define COS1ebe40(a) D_00359a20[((u32)(a) + 16384 >> 4) & 0xfff]

/* VU0 random number in [1,2) - 1 (hand-written VU0 macro code in the original) */
#define RAND1ebe40(r) asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(r) : : "$8")

/* Particle emitter step: when the wait counter runs out, spawn one object at a random
   point on a sphere of radius e->rad around pos, moving outwards at e->speed. */
void func_001ebe40(u8* base, Spawn1ebe40* e, SpCtx1ebe40* c);  // 0x001ebe40: definition moved into src/anon/unit_001e8ac8.cpp
