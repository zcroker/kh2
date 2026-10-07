#include "../common/types.h"

// Functions that load float constants from the compiler's literal pool
// (lui; addiu; lwc1 0(reg)). Write the literal (1.0f etc.); the build retargets
// the pool reference to the original address (tools/build_elf.py,
// retarget_local_data_refs) after checking the original holds the same value.

extern "C" {
extern f32 D_00349e0c;
extern f32 D_0034aa44;
extern f32 D_01c6cb18;
extern f32 D_004f3588;
extern f32 D_01c60520;
extern u32 D_00347c00;
u8 func_001c71f8(u32 p, f32 f);
u8 func_001c7440(u32 p, u32 z);
void func_001374c8(u8* p, s32 n, u32 a, u32 b, f32 f);
void func_0017c870(u8* p, f32 a, f32 b);
void func_00184540(u8* p, u32 a, f32 x, f32 y);
s32 func_001bb4a0(void);
u8* func_001bbcb0(void);

void func_0014ce60(void) { D_00349e0c = 1.0f; }

s32 func_00159f90(u32 a0, u32 flags) {
    D_0034aa44 = 0.0f;
    if (flags & 4) D_0034aa44 = 0.34906584f;        // 20 degrees
    else if (flags & 8) D_0034aa44 = -0.34906584f;
    return 1;
}

void func_0028d188(u8* p) {
    p[412] = 0;
    p[413] = 0;
    *(f32*)(p + 416) = 30.0f;
    *(u32*)(p + 420) = 0;
    *(u32*)(p + 424) = 0;
    *(u32*)(p + 428) = 0;
    *(u32*)(p + 432) = 0;
    *(u32*)(p + 436) = 0;
    *(u32*)(p + 440) = 0;
}

void func_001375f0(u8* p, u32 a, u32 b) {
    func_001374c8(p, 79, a, b, 60.0f);
    *(u32*)(p + 1304) = 0;
}

u8* func_0017c8f0(u8* p) { func_0017c870(p, 0.9f, 0.95f); return p; }

u8* func_002c1a18(u8* p, u32 a, u32 b) { f32 f = 0.95f; func_00184540(p, b, f, f); return p; }

// Constructor-like init: vtable/type pointer at +0, scale 1.0 at +24.
void func_00132270(u32* p, u32 a) {
    p[1] = a;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[0] = (u32)&D_00347c00;
    p[5] = 0;
    p[7] = 0;
    p[8] = 0;
    ((f32*)p)[6] = 1.0f;
}

void func_00134d10(f32* p) {
    p[0] = 0;
    p[1] = -1e7f;
    p[2] = 0;
    p[3] = 1.0f;
    p[4] = 1.0f;
    p[5] = 1.0f;
    p[6] = 1.0f;
    p[7] = 1.0f;
}

f32 func_001bbfd0(void) {
    if (func_001bb4a0()) return *(f32*)(func_001bbcb0() + 1328);
    return 1.0f;
}

// Vector (0, 0, 0, 1).
void func_002e3f58(u32* p) { p[0] = 0; p[1] = 0; p[2] = 0; ((f32*)p)[3] = 1.0f; }
void func_002e3f78(f32* v) { v[0] = v[1] = v[2] = 0.0f; v[3] = 1.0f; }
}

u32 u_call4_001c73e0(u32 p, u32, u32, u32) { func_001c71f8(p, -0.8f); return func_001c7440(p, 0); }
void wtarget_001a5b08(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_01c6cb18 = 0.52359873f; }  // 30 degrees
void wtarget_00158000(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_004f3588 = 0.07853981f; }
void wtarget_0017e808(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_01c60520 = 0.34906584f; }
