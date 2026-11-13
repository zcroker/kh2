#include "../common/types.h"

struct O171 { char p[0x7f8]; u32 fl; char q[0x30]; };
struct A171 { O171* o; f32 f; };

extern "C" {
void func_001ad990(void* a, f32 b, f32 c, f32 d) asm("_Z13func_001ad990jfff");
u32 func_002bc608(u32);
void func_002b6f28(u32, u32, u32);
void func_002eb9d8(u32, u32, u32, f32);
extern u32 D_00363540;
extern u32 D_00373970[];
u32 u_tail4_00192048(u32) asm("_Z16u_tail4_00192048jjjj");
u32 CopyMessage(u32, u32) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");

void func_00171268(A171* a) {
    O171* o = a->o;
    f32 f = a->f;
    if (!(o->fl & 0x10)) func_001ad990((char*)o + 2092, 1.0f, 0.0f, f);
}

void func_001712b0(A171* a) {
    O171* o = a->o;
    f32 f = a->f;
    if (!(o->fl & 0x10)) func_001ad990((char*)o + 2092, 0.0f, 1.0f, f);
}

// 00178570: moved to src/yasui/libys/player.cpp

u32 func_00271828(u32 i, u32 b) {
    u32 s = b;
    CopyMessage(s, u_tail4_00192048(D_00373970[i]));
    return s;
}

void func_002ba140(u32 a, u32 b, u32 c) {
    func_002bc608(a);
    func_002b6f28(a, b, c);
}

// 002eba30: moved to src/anon/unit_002eaf38.cpp
}
