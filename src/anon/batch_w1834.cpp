#include "../common/types.h"

extern "C" {

struct W1834Sub { u8 pad[0x14]; s32 st; };
struct W1834Bits { u32 b0 : 1; };
struct W1834Obj {
    u8 p0[0x1c]; f32 v;
    u8 p1[0x110 - 0x20]; f32 a; f32 b;
    u8 p2[0x140 - 0x118]; W1834Sub sub;
    u8 p3[0x164 - 0x158]; W1834Bits bits;
    u8 p4[0x588 - 0x168]; u32 flags;
};
s32 func_0016a070(W1834Obj*);
void func_0016c168(W1834Obj*, s32);
void func_0017c108(void*, W1834Obj*, s32);
void func_001b3748(W1834Obj*, s32);

// 0017c160: moved to src/anon/unit_0017bf40.cpp

}
