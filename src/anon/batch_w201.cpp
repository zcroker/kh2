#include "../common/types.h"

extern "C" {
void wtarget_00159728(u32, u32, u32, u32) asm("_Z16wtarget_00159728jjjj");
void wtarget_002ead48(u32, u32, u32, u32) asm("_Z16wtarget_002ead48jjjj");
void wtarget_002dce80(u32, u32, u32, u32) asm("_Z16wtarget_002dce80jjjj");
extern f32 D_004f35b0;
extern f32 D_00363448;
extern void func_002e5350(void*, s32, f32);

void wtarget_00159728(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_004f35b0 = 1.04719746f; }
void wtarget_002ead48(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_00363448 = 0.392699063f; }
void wtarget_002dce80(u32 a, u32, u32, u32) { func_002e5350((u8*)a + 256, 20, 0.0199999996f); }
void func_002d8d40(u8* a, f32* b, f32* c) { *b = *(f32*)(a + 472) + 30.0f; *c = *(f32*)(a + 468) - 30.0f; }
}
