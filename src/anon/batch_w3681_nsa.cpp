// 00224358 (nsa): the empty asm reading sys gives the D_01d9e6e4 load one more dependent, so sched2 puts it before the mult.
#include "../common/types.h"
struct Prm224358 {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s64 d16;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; s32 w68; s32 w72; s32 w76; s32 pad80[4];
};
struct Hdr224358 { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; u8 pad4[18]; u16 h22; };
struct Slot224358 { u8 pad[28]; Hdr224358* h; s32 w32; };
struct Sys224358 { u8 pad[16]; Slot224358* slots; };
struct Sys2224358 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Mtx224358 { f32 m[15]; f32 w; } __attribute__((aligned(16)));
extern Sys224358* D_01d9e6e4;
extern Sys2224358* D_01d9e6e8;
extern s32 D_01d9eaa4;
extern u8 D_01d9eac0[];
extern Mtx224358 D_01d9ea00;
extern Mtx224358* D_00354688;
extern s32 D_0035468c;
extern "C" {
s32 func_0020f1e0(Hdr224358*, Prm224358*, s32);
void func_00224358(u32 idx, u8* rgba, u8 b2, u8 b3);  // 0x00224358: definition moved into src/anon/unit_00222aa8.cpp
}
