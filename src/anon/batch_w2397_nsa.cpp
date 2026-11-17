#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa).

struct W2397Sub { s32 a; s32 b; u8 c8; u8 c9; u8 ca; u8 cb; u8 cc; void set9(u8 v) { c9 = v; } void setb(u8 v) { cb = v; } };
struct W2397Ent { s32 x0, x4; u32 fl; s32 xc; W2397Sub s; };
struct W2397Bits64 { u64 lo : 40; u64 hi : 24; };
struct W2397Obj {
    char p0[0xc]; u8 c0c; u8 c0d; char p1[0x2440 - 0xe];
    s32 v2440; s32 v2444; char p2[0x2498 - 0x2448]; u8 c2498; u32 : 0; u32 b249c : 1; u32 : 31;
    char p4[0x24f0 - 0x24a0]; char t24f0[0x4198 - 0x24f0]; u32 w4198; u8 c419c;
};
struct W2397Rec { char p[0xf]; u8 cf; };

extern "C" {
s32 func_001058d8(W2397Obj*);
W2397Rec* func_00188fe0(void*, s32);
s32 func_0019f880(u8, u8);
extern W2397Obj* D_0035ec90;
extern W2397Ent* D_0035ec94;

// Entry address written index-first (the original adds i*32 before the table base here).
#define W2397_ENT(i) ((W2397Ent*)(((i) << 5) + (u32)D_0035ec94))

// Copies state flags and properties of object o (default D_0035ec90) into entry i of the D_0035ec94 table.
void func_00240c08(s32 i, W2397Obj* o, u32 fl);  // 0x00240c08: definition moved into src/anon/unit_0023f5b8.cpp
}
