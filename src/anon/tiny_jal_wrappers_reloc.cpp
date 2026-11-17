#include "../common/types.h"

u32 func_001041a0(u32, u32, u32, u32);
u32 func_00113628(u32, u32, u32, u32);
u32 func_00124bb8(u32, u32, u32, u32);  // obj_ctor_347b88
u32 func_00138c10(u32, u32, u32, u32);
u32 func_0013e8c0(u32, u32, u32, u32);
u32 func_0014b290(u32, u32, u32, u32);
u32 func_00185b00(u32, u32, u32, u32);
u32 func_00188fe0(u32, u32, u32, u32);
u32 func_00189200(u32, u32, u32, u32);
u32 func_001a3788(u32, u32, u32, u32);
u32 func_001a4db0(u32, u32, u32, u32);
u32 func_001ae9a0(u32, u32, u32, u32);
u32 func_001b1d20(u32, u32, u32, u32);
u32 func_001baa58(u32, u32, u32, u32);
u32 func_001c10f8(u32, u32, u32, u32);  // request_pool_block64
u32 func_001c8db8(u32, u32, u32, u32);
u32 func_001d3350(u32, u32, u32, u32);
u32 func_001db8f8(u32, u32, u32, u32);
u32 func_002361d0(u32, u32, u32, u32);
u32 func_00239870(u32, u32, u32, u32);
u32 func_0028e350(u32, u32, u32, u32);
u32 func_002cf3f8(u32, u32, u32, u32);
u32 func_002cfeb0(u32, u32, u32, u32);  // obj_init_field1416_bit800
u32 func_002d0ea8(u32, u32, u32, u32);
u32 func_002db4b0(u32, u32, u32, u32);
u32 func_002f5d18(u32, u32, u32, u32);
u32 func_003080d0(u32, u32, u32, u32);

extern u8 D_0032e020;
extern u8 D_00347848;
extern u8 D_00347bd8;
extern u8 D_00347e60;
extern u8 D_00347e80;
extern u8 D_00347f98;
extern u8 D_003486d8;
extern u8 D_00349dc0;
extern u8 D_00349dd8;
extern u8 D_0034d7b0;
extern u8 D_00350d68;
extern u8 D_00350e98;
extern u8 D_00351580;
extern u8 D_00351cd8;
extern u8 D_00351da8;
extern u8 D_00351ec8;
extern u8 D_00351f78;
extern u8 D_00351ff0;
extern u8 D_00352060;
extern u8 D_003520d0;
extern u8 D_00352678;
extern u8 D_003527f0;
extern u8 D_00352970;
extern u8 D_0035f440;
extern u8 D_00361f70;
extern u8 D_00362398;
extern u8 D_003626a8;
extern u8 D_00362a20;
extern u8 D_00362ad8;
extern u8 D_0036a070;
extern u8 D_003757e0;
extern u8 D_00376da0;
extern u8 D_01c6cac0;
extern u8 D_01d48de8;
extern u8 D_01d49388;
extern u8 D_01d5ba10;

// 00105f98: moved to src/common/world.cpp

u32 func_0011a460(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0011a460: definition moved into src/anon/unit_0011a260.cpp

u32 func_0011a490(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0011a490: definition moved into src/anon/unit_0011a260.cpp

u32 func_001316c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00124bb8(r4, r5, r6, r7);  // obj_ctor_347b88
    r15 = (u32)&D_00347bd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_001316f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00124bb8(r4, r5, r6, r7);  // obj_ctor_347b88
    r15 = (u32)&D_00347bd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0013ee58(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013ee58: definition moved into src/anon/unit_0013dfb8.cpp

u32 func_0013ee88(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013ee88: definition moved into src/anon/unit_0013dfb8.cpp

u32 func_0014b638(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0014b290(r4, r5, r6, r7);
    r15 = (u32)&D_00349dd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0014b668(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0014b290(r4, r5, r6, r7);
    r15 = (u32)&D_00349dd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0014b7a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0014b290(r4, r5, r6, r7);
    r15 = (u32)&D_00349dc0;
    r13 = (u32)((s32)r16 + (256));
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r14 = (u32)((s32)r16 + (32));
    r15 = (u32)((s32)0u + (13));
    *(u32*)((u32)r13 + (s32)(4)) = r14;
    *(u16*)((u32)r16 + (s32)(256)) = (u16)r15;
    *(u8*)((u32)r13 + (s32)(3)) = (u8)0u;
    return r2;
}

u32 func_0014b7f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0014b290(r4, r5, r6, r7);
    r15 = (u32)&D_00349dc0;
    r13 = (u32)((s32)r16 + (256));
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r14 = (u32)((s32)r16 + (32));
    r15 = (u32)((s32)0u + (13));
    *(u32*)((u32)r13 + (s32)(4)) = r14;
    *(u16*)((u32)r16 + (s32)(256)) = (u16)r15;
    *(u8*)((u32)r13 + (s32)(3)) = (u8)0u;
    return r2;
}

// 00167728: moved to src/anon/unit_00167358.cpp

// 0016e090: moved to src/anon/unit_0016d2e0.cpp

u32 func_001a00f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001a00f0: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a11b0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001a11b0: definition moved into src/anon/unit_0019fb70.cpp

// 001a37e8: moved to src/anon/unit_001a2a50.cpp

u32 func_001aeb00(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001aeb00: definition moved into src/anon/unit_001ada38.cpp

u32 func_001aeb40(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001aeb40: definition moved into src/anon/unit_001ada38.cpp

// 001b1d20: moved to src/anon/unit_001b1d20.cpp

// 001b1d60: moved to src/anon/unit_001b1d20.cpp

// 001bb288: moved to src/yasui/libys/mission.cpp

// 001c11a8: moved to src/anon/unit_001c0638.cpp
u32 func_001c11a8(u32 a0, u32 a1, u32 a2, u32 a3);

u32 func_001c4120(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c4120: definition moved into src/anon/unit_001c4120.cpp

u32 func_001c51a0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c51a0: definition moved into src/anon/unit_001c5168.cpp

// 0x1c7bc8: moved to src/anon/unit_001c7bc8.cpp

u32 func_001ca678(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001ca678: definition moved into src/anon/unit_001ca638.cpp

u32 func_001cbb18(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001cbb18: definition moved into src/anon/unit_001ca8e0.cpp

u32 func_001cbb58(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001cbb58: definition moved into src/anon/unit_001ca8e0.cpp

// 001cc048: moved to src/anon/unit_001cc048.cpp

// 001ccdf8: moved to src/anon/unit_001cc868.cpp

// 001cce38: moved to src/anon/unit_001cc868.cpp

u32 func_001d2810(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d2810: definition moved into src/anon/unit_001d2810.cpp

u32 func_001d2850(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d2850: definition moved into src/anon/unit_001d2810.cpp

// 001d33e0: moved to src/anon/unit_001d30b0.cpp

u32 func_001d7458(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d7458: definition moved into src/anon/unit_001d7458.cpp

u32 func_001da1d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00352970;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(10592)) = r16;
    return r2;
}

u32 func_0028e000(u32 a0, u32 a1, u32 a2, u32 a3);  // 0028e000: moved to src/anon/unit_0028c878.cpp

u32 func_0028e040(u32 a0, u32 a1, u32 a2, u32 a3);  // 0028e040: moved to src/anon/unit_0028c878.cpp

u32 func_002c9ed8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x2c9ed8: moved to src/anon/unit_002c9998.cpp


u32 func_002cea28(u32 a0, u32 a1, u32 a2, u32 a3);  // 002cea28: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002cea68(u32 a0, u32 a1, u32 a2, u32 a3);  // 002cea68: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002d6990(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d6990: definition moved into src/anon/unit_002d62d0.cpp

u32 func_002d69c8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d69c8: definition moved into src/anon/unit_002d62d0.cpp

u32 func_002db680(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_002db4b0(r4, r5, r6, r7);
    r15 = (u32)&D_003626a8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_002db6b0(u32 a0, u32 a1, u32 a2, u32 a3) {  // obj_ctor_basic
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_002db4b0(r4, r5, r6, r7);
    r15 = (u32)&D_003626a8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_002dd6d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_002d0ea8(r4, r5, r6, r7);
    r15 = (u32)&D_00362a20;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_002dd700(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_002d0ea8(r4, r5, r6, r7);
    r15 = (u32)&D_00362a20;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_002de750(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r7 = r6;
    r6 = 0u;
    r16 = r4;
    r2 = func_002cfeb0(r4, r5, r6, r7);  // obj_init_field1416_bit800
    r15 = (u32)&D_00362ad8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_002de788(u32 a0, u32 a1, u32 a2, u32 a3) {  // obj_ctor_arg
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r7 = r6;
    r6 = 0u;
    r16 = r4;
    r2 = func_002cfeb0(r4, r5, r6, r7);  // obj_init_field1416_bit800
    r15 = (u32)&D_00362ad8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 sceCdChgSys(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = (u32)&D_00376da0;
    r2 = func_003080d0(r4, r5, r6, r7);
    r2 = (u32)((s32)0u + (2));
    return r2;
}

u32 func_0031a2b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0031ab38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e80;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (32));
    r2 = func_002361d0(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0031abd8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0031acc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0031ad60(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0031af68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0031c028(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0031cd50(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0031d6c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_0031d800(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_00321da8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_003228c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_00323b50(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_00323bf0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_00323c90(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

u32 func_00323d30(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
