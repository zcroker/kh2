#include "../common/types.h"

// func_002f1fb8 is now C in src/sdk/sdk_w3687.c. func_001e7470 is now C in batch_owner1021_g.cpp.

extern "C" {
extern u8 D_0022b108[];
void* func_00102c18(int, void*, void*);
void* func_0022a368(void*);
void func_00224f08();
void func_00224f38(void* a0, u32* a1, u32* a2, void* a3) {
  u32* r = (u32*)func_00102c18(1, a0, D_0022b108);
  *a1 = (u32)r;
  r[12] = (u32)func_00224f08;
  *a2 = (u32)func_0022a368(a3);
}
union U { u8 c; u16 h; s16 sh; u32 w; float f; };
void func_00232ea0(U* a0, U* a1, U* a2, u32 a3) {
  a0[0].w = a2[0].w; a0[1].w = a2[1].w; a0[2].w = a2[2].w;
  a0[5].f = (float)a1[2].h * 2.0f;
  a0[6].h = ((U*)((u8*)a1+10))->h;
  ((U*)((u8*)a0+26))->h = ((U*)((u8*)a1+12))->h;
  float f0 = (float)(s32)(a1[2].h - ((U*)((u8*)a1+16))->sh) * 2.0f;
  a0[12].c = 1;
  a0[3].w = a3;
  a0[4].f = f0;
}
}
