#include "types.h"

// Boot reset (0x105a10-0x105af8): two empty functions, then the reset of the sound, graphics,
// pad and memory systems. The SAVERAM file before it ends at its _GLOBAL__D_ stub (0x1059f0);
// region.cpp follows.

extern "C" {
void func_002bd260(u32);
void func_002bd310(u32);
void func_002ba220(u32, u32, u32, u32, u32, u32);
void func_00106048(void);
void func_00105fc8(void);
void func_002bd788(u32);
void func_002bd730(u32, u32, u32, u32);
void func_002bd760(u32);
void func_002bd7d8(void);
void func_002f8aa0(f32);
void cosf_v(f32) asm("cosf");
void func_0016f448(u32);
void func_002fd3d0(u32, u32);
u32 func_00170b30(u32);
void func_00170c00(u32);
void func_00170320(u32);
void func_00102f70(void);
void func_00102f80(void);

void func_00105a10(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}

// 0x105a18 (not in the layout): another empty function.
void func_00105a18(void) {
}

void func_00105a20(void) {
    volatile u8 pad[64];

    func_002bd260(0);

    f32 f20 = 0.0f;
    func_002bd310(0);

    func_002ba220(0, 12288, 12288, 0, 0, 0);

    func_00106048();
    func_00105fc8();

    func_002bd788(0);
    func_002bd730(0, 0, 0, 0);
    func_002bd760(720);
    func_002bd7d8();

    func_002f8aa0(f20);
    cosf_v(f20);

    func_0016f448(0);
    func_002fd3d0(0, 0);

    func_00170b30(0);  // alloc_align128
    func_00170c00(0);
    func_00170320(0);

    func_00102f70();
    func_00102f80();
}
}
