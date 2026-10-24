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
void func_002dc850(HoneyGame2386* p)
{
    Box2386* d = &p->box;
    V4_2386 a;
    V4_2386 b;
    Box2386 r;
    a.x = 900.0f;
    a.y = 200.0f;
    a.z = 2000.0f;
    b.x = -900.0f;
    b.y = -6000.0f;
    b.z = -2000.0f;
    f32 z = 0.0f;
    b.w = a.w = z;
    Aabbox_2386(&r, &b, &a);
    *d = r;
    p->f8090 = 0;
    setHideGroup_2386(2);
    p->fd4 = z;
    p->f8068 = z;
    p->fd8 = -1.0f;
    p->f8c = 0;
    p->f88 = 0;
    p->f90 = 0;
    p->f806c = 0;
    p->f8074 = 0;
    p->f8070 = 0;
    func_002e4af8(p->rope);
}
}
