/* Built with -fno-strict-aliasing (_nsa).
   Static GS/DMA packet setup: GIF tags and GS register blocks, two DMA tags with a VIF DIRECT code.
   D_00352bf4 is read through a local pointer: the load then counts as possibly aliasing the stack
   slot of vif, which gives sched2 the original lw/lui order. */
#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q128;

typedef struct { u16 qwc; u8 mark; u8 id; u32 next; u32 p[2]; } DmaTag;

extern u64 D_0032afc0[8];
extern u64 D_0032b000[6];
extern u64 D_0032b040[6];
extern u64 D_0032b080[6];
extern DmaTag D_0032b0d0;
extern u64 D_0032b7c0[8];
extern u64 D_0032b800[6];
extern u64 D_0032b840[6];
extern u64 D_0032b880[6];
extern f32 D_0032b8c0[4];
extern DmaTag D_0032b8e0;
extern f32 D_00359110[4];
extern s32 D_00352bf4;
extern u64 D_01da9010[];
extern u64 D_01daa930[];
Q128* func_0021c810(Q128* p, s32 a, s32 b);
Q128* func_0021c8c8(Q128* p, s32 a, s32 b);
void func_003058a0(s32);


void func_0021c9b0(void);  // 0x0021c9b0: definition moved into src/anon/unit_0021aee8.cpp
