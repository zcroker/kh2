#include "../common/types.h"
struct Prm { u16 a0; u16 flags; u8 c[4]; u64 z8; void* p10; s32 v14; u8 b18; u8 pad19[3]; void* p1c; u8 pad20[0x10]; };
struct Ent { s32 a; s32 b; };
struct Tbl { u8 pad[0x14]; Ent* ents; };
struct Rec { u8 pad[0x10]; s16 off; };
struct Node { u8 pad[4]; u16 idx; u8 pad6[2]; u8 c[4]; };
struct Arg1 { u8 pad[4]; s32 id; u8 pad8[4]; u8 bc, bd, be, bf, b10; };
struct Arg2 { u8 pad[0xc]; s32* offs; };
extern Tbl* D_01d9e6e4;
extern u8* D_01d9e6e8;
extern s32 D_01d9eaa4;
extern "C" s32 func_0021d048(u8*, Prm*, s32);
extern "C" {
void func_001fe798(u8* base, Arg1* a, Arg2* b);  // 0x001fe798: definition moved into src/anon/unit_001fe158.cpp
}
