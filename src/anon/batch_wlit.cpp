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

// 00159f90: moved to src/harata/libdk/targetcamera.cpp

void func_0028d188(u8* p);  // 0028d188: moved to src/anon/unit_0028c878.cpp

void func_001375f0(u8* p, u32 a, u32 b);  // 0x001375f0: definition moved into src/anon/unit_001374c8.cpp

// 0017c8f0: moved to src/anon/unit_0017c400.cpp

u8* func_002c1a18(u8* p, u32 a, u32 b);  // 0x002c1a18: definition moved into src/anon/unit_002c10e0.cpp

// Constructor-like init: vtable/type pointer at +0, scale 1.0 at +24.
void func_00132270(u32* p, u32 a);  // 0x00132270: definition moved into src/anon/unit_00131418.cpp

// 00134d10: moved to src/anon/unit_00134668.cpp

// 001bbfd0: moved to src/yasui/libys/mission.cpp

// Vector (0, 0, 0, 1).
void func_002e3f58(u32* p) { p[0] = 0; p[1] = 0; p[2] = 0; ((f32*)p)[3] = 1.0f; }
void func_002e3f78(f32* v) { v[0] = v[1] = v[2] = 0.0f; v[3] = 1.0f; }
}

// 001c73e0: moved to src/anon/unit_001c7148.cpp (linked unit)
// 001a5b08: moved to src/anon/unit_001a4db0.cpp  // 30 degrees
// 0017e808: moved to src/yasui/libys/friend.cpp
