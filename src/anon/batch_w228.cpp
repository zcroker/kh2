#include "../common/types.h"

namespace w228 {
struct V4 {
    f32 x, y, z, w;
    V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
};
struct Obj { void** vt; };
struct Hold { u32 pad[5]; Obj* o; };

extern "C" {
// externs
void* func_001b8680(u32, void*);
void func_002edf68(void*);
void func_002c20f8(void*);
void func_002c2168(void*);
extern char D_002be408[];
extern u32 D_003617fc;
extern char D_0034a568[], D_00347e60[], D_00347f98[];
extern Hold* D_00347f80;
void func_00239870(void*);
void func_0031a840(void*);
s32 func_001805a8(u8*, s32);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
void func_0016bd60(u8*, s32);
void func_00290740(u8*);
void func_002362b0(u8*, u32);
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void func_001386e0(u8*, u32, u32, u8*, u32, u32);
void func_002b740c(u32, u32, u32, u32);

void func_002bd8f8(u32* p, u32 a1);  // 0x002bd8f8: definition moved into src/anon/unit_002bc978.cpp

void func_0031c2c8(u32* p);  // 0x0031c2c8: definition moved into src/anon/unit_0031b9e0.cpp

// 001843d8: moved to src/anon/unit_00183088.cpp

void Selector_CreateHelpGra(u8* t, u32 a1, u32 a2, u32 a3) asm("_ZN2Tz8Selector13CreateHelpGraEz");
// 00290668: moved to src/anon/unit_0028f1e0.cpp

s32 func_002bb8b0(u8* p);  // 0x002bb8b0: definition moved into src/anon/unit_002bb8b0.cpp
}
}
