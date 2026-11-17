#include "../common/types.h"
struct V { f32 x, y, z; u32 w; };
struct E { E* next; u32 idx; u32 mask; u32 z12; u32 z16; };
struct O { u8 pad[76]; E** tbl; };
extern "C" {
extern V D_003a99d0;
extern V D_003a99e0;
void func_wt119b10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00119b10jjjj");
void func_wt119b10(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00119b10: definition moved into src/anon/unit_001195a8.cpp
void* func_00304fb0(void*, u32, u32);
E* f303b70(O* o, u32 idx) asm("_Z7_Ballocjjjj");
E* f303b70(O* o, u32 idx);  // 0x00303b70: definition moved into src/newlib/libc/mprec.c
}
