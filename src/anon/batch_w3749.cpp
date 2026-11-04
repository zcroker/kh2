// 0013a240: static init/destroy of Obj[2]; second loop pointer q = p + 96 written out by hand.
#include "../common/types.h"
struct Obj { s32 a0; s32 a4; s32 a8; s32 ac; s32 b0; s32 b4; u8 pad[8]; u8 sub[0x40]; s32 c0; u8 pad2[0xc]; ~Obj() {} };
extern Obj D_00347ea0[2];
extern "C" {
void func_0031ae00(void*);
void func_0013a240(int a, int b) asm("_Z13func_0013a240ii");
void func_0013a240(int a, int b) {
    if (b == 0xffff && a == 1) {
        Obj* p = D_00347ea0; s32 n = 1; s32* q = (s32*)((u8*)p + 96);
        do {
            q[-22] = 0; q[-23] = 0; q[-20] = 0; q[-21] = 0;
            void* s = p->sub; p++; n--;
            func_0031ae00(s);
            q[-19] = 0; q[0] = 0;
            q += 28;
        } while (n != -1);
    }
    if (b == 0xffff && a == 0) { if (D_00347ea0) { Obj* e = D_00347ea0 + 2; for (;;) { e->~Obj(); if (e == D_00347ea0) break; --e; } } }
}
}
