#include "../common/types.h"
extern "C" {
void func_0021f5d8(void*);
extern u8 D_003590b0;
struct S1 { u8 pad[0x8c]; u8 b8c; u8 b8d; u8 p2[0x9c-0x8e]; s32 w9c; u8 p3[8]; s32 wa8; u8 p4[0xc0-0xac]; u8 bc0; u8 bc1; };
void func_001fb478(char* a0, s32** a1);
void func_001fb479(char* a0, s32** a1);
struct Arg2 { void* a; s32 b; void* c; f32 d; s16 e; u16 f; void* g; };
extern u8 D_01d9e8c0;
void func_0021fe40(Arg2*, s32);
struct T2 { u8 pad[0x20]; f32 f20; s32 w24; f32 f28; u16 h2c; };
void func_001fbab8(T2* a0) {
    Arg2 s;
    s.b = a0->w24;
    s.d = a0->f20;
    s.e = (s32)a0->f28;
    s.f = a0->h2c;
    s.c = &D_01d9e8c0;
    s.g = (char*)a0 + 16;
    s.a = a0;
    func_0021fe40(&s, 0);
}
void func_001fbab9(T2* a0);
char* GetImage(void* t, s32 i) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
struct Sub { u8 pad[0x28]; void* img; };
struct T3 { u8 pad[0x28]; s32 n; u8 p2[4]; Sub sub; };
void func_0023ef50(T3* a0);
}
