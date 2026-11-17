// 00240e50: memory card file scan (w3680). Built with -fno-strict-aliasing.
// Rebuilds the save slot table from the card's directory entries.
#include "../common/types.h"
struct McName { char c[8]; };
struct McSlot {
    union { s32 v; u8 b; } used;
    u8 pad4[0x14];
    McName name;
};
struct McTable {
    s8 port;
    u8 dirty;
    u8 pad2[3];
    s8 hasSystem;
    u8 pad6[2];
    McSlot slot[99];
};
struct McDirEnt {
    u8 pad0[8];
    McName name;
    u8 pad10[4];
    u16 attr;
    u8 pad16[0xa];
    char fname[0x20];
};
extern "C" {
extern McTable* D_0035ec94;
extern McDirEnt* D_0035ec9c;
extern char D_003716d8[];
s32 YI_MCARD_GetFileTableMax(s32, s32) asm("_ZN2YI5MCARD15GetFileTableMaxEii");
void func_002fde18(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
s32 strcmp(const char*, const char*);
s32 strlen(const char*);

static inline s32 num2(u8 a, u8 b) { return (a - '0') * 10 + (b - '0'); }
s32 func_00240e50(void);  // 0x00240e50: definition moved into src/anon/unit_0023f5b8.cpp
}
