// Partial asm in func_00198290: three small asm statements only fix sched2 order of the member re-init (same as twin func_001980d0).
// Partial asm in func_002c8680: one hand-written li of the loop constant fixes preheader order; rest is plain C.
#include "../common/types.h"
extern "C" {
void func_00169398(void*, u32, void*, s32, s32, f32);
void* func_00168b38(s32, s32, s32);
s32 func_00170d18(s32);
void func_0017ebe8(void*, s32);
void func_00195858(void*, u32);
void func_001b2f38(void*, s32, u32);
void func_001d56f0(void*);
void func_001dddd0(void*, s32);
extern u8 D_003503e0[];
extern u8 D_00350e48[];

// 00198290: moved to src/anon/unit_00197fe0.cpp
}
struct Sub { u8 pad[0x18c]; void* p18c; s32 x190; u8 pad2[4]; };
struct Cnt { u8 pad[0x19c]; s32 x19c; s32 x1a0; };
struct Self {
    u8 pad0[0xc4];
    Cnt cnt;          // 0xc4 .. 0x264
    u8 pad1[0x278 - 0x268];
    Sub subs[1];      // 0x278 (overlaps 0x290)
};
extern "C" {
s32 func_002c22f0(s32);
s32 func_002c2358(s32);
void func_001386e0(Sub*, s32, s32, s32, s32, s32);
void func_001396b0(Sub*);
void func_0031a260(Sub*, s32);
void func_00139660(Sub*);
void func_00139688(Sub*);
s32 func_0023aa18(void*);
s32 func_0023aa58(void*);
void func_00138c68(Sub*, s32, s32);
void func_002c8680(Self* self, s32 arg);  // 0x2c8680: moved to src/anon/unit_002c7e68.cpp

}
