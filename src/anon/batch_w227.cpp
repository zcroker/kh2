#include "../common/types.h"

extern "C" {

extern void* func_001b8680(u32, const void*);
extern void func_002edf68(void*);
extern void func_002c20f8(f32*);
extern void func_002c2168(f32*);
extern const char D_002be408[];
extern void* D_003617fc;

struct U_002bd998 { u32 a; void* b; u8 p0[0x34]; u32 c; u8 p1[0x28]; u32 f; };

void func_002bd998(U_002bd998* t, u32 a1);  // 0x002bd998: definition moved into src/anon/unit_002bc978.cpp

extern void func_002361a0(void*);
extern void func_00239700(void*);
extern void func_00239870(void*);
extern void func_002361d0(void*);
extern u8 D_0034a5d0[];
extern u8 D_00347e80[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];

void func_0031bcf8(u32* t) {
    t[0] = (u32)D_0034a5d0;
    t[12] = (u32)D_00347e80;
    t[3] = 0;
    t[15] = 0;
    func_002361a0((u8*)t + 80);
    func_00239700((u8*)t + 496);
    u32* s = (u32*)((u8*)t + 840);
    for (int i = 4; i != -1; i--) {
        s[3] = 0;
        s[0] = (u32)D_00347e60;
        func_00239700((u8*)s + 24);
        s = (u32*)((u8*)s + 408);
    }
}

void func_0031c5d0(u32* t) {
    t[0] = (u32)D_0034a5d0;
    if (t != (u32*)-840) {
        u8* p = (u8*)t + 2880;
        u8* q = (u8*)t + 840;
    top:
        if (q == p) goto out;
        p -= 408;
        ((void(*)(void*))(*(u32**)p)[3])(p);
        goto top;
    }
out:
    func_00239870((u8*)t + 496);
    t[12] = (u32)D_00347e80;
    func_002361d0((u8*)t + 80);
    t[12] = (u32)D_00347f98;
    t[0] = (u32)D_00347f98;
}

}
