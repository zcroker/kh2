#include "../common/types.h"
// Built with -fno-strict-aliasing (see Makefile *_nsa rule).
typedef unsigned int u128 __attribute__((mode(TI)));
struct W1764ObjB { s32 a, b, c; };
struct W1764Arg { void* a; u32 b; void* c; f32 d; s16 x, y; void* e; };
struct W1764Pkt { u32 a, b; u128* p; };

extern "C" {
void* W1764_AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void func_001ad0f8(void*, s32, s32);
extern u8 D_01d9e8c0[];
void func_0021fbd8(W1764Arg*, s32);
void func_001b7e68(W1764Pkt*, s32);
void func_001b80d8(W1764Pkt*);
void func_001b7f30(W1764Pkt*);

void func_001ad158(u8* a0, s32 a1, s32 a2, s32 a3) {
    W1764ObjB* o = (W1764ObjB*)W1764_AREA_Alloc(0xb6c);
    func_001ad0f8(o, a3, 0);
    *(W1764ObjB**)(a0 + 0x4a8) = o;
    o->b = a1;
    o->c = a2;
}

void func_001fb8b8(u8* o) {
    W1764Arg s;
    s.a = o;
    s.b = *(u32*)(o + 36);
    s.c = D_01d9e8c0;
    s.d = *(f32*)(o + 32);
    s.x = (s16)*(f32*)(o + 40);
    s.y = (s16)*(f32*)(o + 44);
    s.e = o + 16;
    func_0021fbd8(&s, 0);
}

void func_0014b9a8(u128* src) {
    W1764Pkt pk;
    s32 i;
    pk.p = 0; pk.b = 0; pk.a = 0;
    func_001b7e68(&pk, 32);
    W1764Pkt* q = &pk;
    for (i = 1; i >= 0; i--) {
        *q->p = *src++;
        q->p++;
    }
    func_001b80d8(&pk);
    func_001b7f30(&pk);
}
}
