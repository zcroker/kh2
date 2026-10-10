#include "../common/types.h"

extern "C" {
extern u32 D_0034f240;
void* func_0010c778(void*); void func_00135aa0(void*); u8* func_00111e38(s32);
void func_001c0e60(void*); void func_00198970(void*); void func_0013e4b8(void*);
void func_0014ebd8(void); void func_001ad990(void*, f32, f32, f32); void func_00190128(void*);
void func_0019cc20(void*); void func_0016bd60(void*, s32);
void func_0011b250(u8* p) {
    u8* c;
    func_00135aa0(func_0010c778((void*)*(u32*)(p + 4)));
    c = func_00111e38(0);
    *(u32*)(c + 264) &= ~0x100;
    *(u32*)(c + 268) &= ~0x4000;
    *(u32*)((u8*)*(u32*)(p + 4) + 264) &= ~0x100;
    func_001c0e60((void*)*(u32*)(p + 4));
    func_00198970((void*)*(u32*)(p + 4));
    if (*(void**)(p + 48)) {
        func_0013e4b8(*(void**)(p + 48));
        *(void**)(p + 48) = 0;
    }
    D_0034f240 &= ~0x4000;
    func_0014ebd8();
    func_001ad990(c + 2100, 0.0f, 1.0f, 0.0f);
    func_001ad990((u8*)*(u32*)(p + 4) + 2100, 0.0f, 1.0f, 0.0f);
    *(u32*)(p + 32) &= ~1;
    func_00190128((u8*)*(u32*)(p + 4) + 2548);
    if (*(void**)(c + 2880)) func_0019cc20(*(void**)(c + 2880));
    if ((*(s32*)(*(u8**)(c + 12) + 4) ^ 0x3f) == 0) {
        func_0016bd60(c, 0);
        u8* o = *(u8**)(c + 12);
        (*(void (**)(void*, void*, f32))(*(u8**)o + 12))(o, c, 0.0f);
    } else func_0016bd60(c, 0);
}

u8* func_0023ee30(s32); void func_0031a838(void*); void func_002369a0(void*); void func_0023c008(void*);
void func_0028d7f0(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0026e1e0(void); s32 func_00287bc0(void); void func_0026df30(void);
void* func_0023f1b0(void*); void* func_0023c3e0(void*, s32, s32);
s32 func_00139d78(void*); void func_0028dd28(void*, void*);
s32 func_002892f8(void*); void* func_002891b8(void*, s32);
void func_0026e3b0(void); void func_0028af28(void*, s32); void func_00287cc0(s32);
extern u8* D_0035f100; extern u8* D_0035f104; extern void* D_0035f10c; extern u8* D_0035f118;
extern u8 D_00347f98[]; extern u8 D_0035eb98[];
void PauseTaskBegin_impl(void) asm("_ZN2Tz14PauseTaskBeginEv");
void PauseTaskBegin_impl(void) {
    u8* t = func_0023ee30(160);
    void* seq;
    s32 i;
    s32 off;
    s32 n;
    *(u32*)t = (u32)D_00347f98;
    func_0031a838(t + 12);
    *(u32*)t = (u32)D_0035eb98;
    func_002369a0(t + 24);
    func_0023c008(t + 48);
    D_0035f100 = t;
    func_0028d7f0(t, 30002, 0, 0, 0, -1, 0, 0, 0);
    func_0026e1e0();
    if (!func_00287bc0()) func_0026df30();
    seq = func_0023c3e0(func_0023f1b0(D_0035f100), 10, 0);
    for (i = 0, off = 0; i < 3; i++, off += 436) {
        if (func_00139d78(D_0035f104 + off)) func_0028dd28(D_0035f104 + off, seq);
    }
    n = func_002892f8(D_0035f10c);
    for (i = 0; i < n; i++) func_0028dd28(func_002891b8(D_0035f10c, i), seq);
    func_0026e3b0();
    {
        u32 t = !(D_0035f118[37] & 1);
        s32 m = 32;
        if (t == 0) m = 96;
        func_0028af28(D_0035f10c, m);
    }
    func_00287cc0(1);
}
}
