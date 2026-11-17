#include "../common/types.h"
extern "C" {

struct Uc4Tgt { u8 pad[0x154]; s32 state; u8 pad2[0xa4c - 0x158]; u32 id; };
struct Uc4 { s32 kind; u8 pad4[8]; Uc4Tgt* tgt; u8 pad10[0x20]; u8 on; u8 pad31[0x1f]; f32 time; };
s32 func_0018bd50(u32, s32);
s32 func_0019ba60(Uc4Tgt*);
u32 u_call4_0018c598(u32 a, u32 b, u32 c, u32 d) asm("_Z16u_call4_0018c598jjjj");
u32 u_call4_0018c598(u32 a, u32 b, u32 c, u32 d);  // 0x0018c598: definition moved into src/yasui/libys/npc.cpp

void func_0017f540(void*, s32, f32, f32);
struct Ch {
    u8 pad0[0x10];
    f32 f10, f14, f18, f1c;
    u8 pad20[0x110 - 0x20];
    f32 f110, f114;
    u8 pad118[0x140 - 0x118];
    u8 snd[0x20];
    u32 flags;
};
void func_001d22e0(void* a, Ch* c);  // 0x001d22e0: definition moved into src/anon/unit_001d14e0.cpp

void puts(const char*);
void func_002fd348(s32) __attribute__((noreturn));
extern char D_00370720[];
void sceGsSetDefLoadImage(void*, s32, s32, s32, s32, s32, s32, s32);
void sceGsSyncPath(s32, s32);
void func_003058a0(s32);
void sceGsExecLoadImage(void*, u32);
struct Tex {
    u16 w : 14;
    u16 pad0 : 2;
    u8 pad2[6];
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad11;
    s16 h12;
    s16 h14;
    u8 pad16[4];
    u32 data;
    u8 b24;
};
void func_0020e490(Tex* t, u32 flag);  // 0x0020e490: definition moved into src/anon/unit_0020e490.cpp

}
