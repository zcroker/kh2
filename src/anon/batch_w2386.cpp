#include "../common/types.h"

struct V4_2386 {
    f32 x, y, z, w;
};
struct Box2386 {
    s32 w[6];
};
// Pooh honey minigame object: only the fields touched by func_002dc850.
struct HoneyGame2386 {
    u8 pad0[0x88];
    s32 f88;
    s32 f8c;
    s32 f90;
    u8 pad94[0xd4 - 0x94];
    f32 fd4;
    f32 fd8;
    u8 paddc[0x100 - 0xdc];
    u8 rope[0x8068 - 0x100];  // passed to func_002e4af8
    f32 f8068;
    u8 f806c;
    s32 f8070;
    s32 f8074;
    Box2386 box;
    u8 f8090;
};

extern "C" {
void Aabbox_2386(Box2386*, const V4_2386*, const V4_2386*) asm("_ZN2dk6AabboxC1ERKN2kn7FVectorES4_");
void setHideGroup_2386(u32 g) asm("_ZN2dk3Map12setHideGroupEj");
void func_002e4af8(void*);

// 002dc850: reset the honey minigame state: rebuild the area box, hide map group 2, clear the counters.
void func_002dc850(HoneyGame2386* p);  // 0x002dc850: definition moved into src/anon/unit_002da040.cpp
}
