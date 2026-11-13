#include "../common/types.h"

extern "C" {
struct W1752Key { u8 a, b, c, d; u16 e, f, g; };
void func_00104f58(W1752Key*, u32, s32, s32, s32);

void func_00172fb0(u8* p) {
    W1752Key s;
    u16 v = 0xffff;
    s.a = v; s.e = v; s.f = v; s.g = v;
    s.b = p[0]; s.c = p[4];
    func_00104f58(&s, *(u32*)(p + 8), 0, 0, 0);
}

struct W1752Ent { u32 a; f32 x; f32 y; s32 z; u32 w; };
struct W1752Ring { s32 idx; u32 pad; W1752Ent e[4]; };
struct W1752Q { u8 pad[0x3c]; W1752Ring r; };
// 0017f3d8: moved to src/yasui/libys/motion.cpp

struct W1752C0 { u8 pad[0x88]; u32 v88; u8 pad2[4]; u8* p90; u32 p94; };
void func_00188398(W1752C0*, u32, u32*, s32);
void func_0016ced0(u32);
void w1752_ct0_00187b90(W1752C0* c) asm("_Z17ctarget0_00187b90v");
// 00187b90: moved to src/anon/unit_00185d10.cpp
}
