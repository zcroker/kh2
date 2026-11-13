#include "../common/types.h"

/* 001a3018: target check. Returns 100 when the target is allowed, arg1 when a
   matching entry is found in the target's list, otherwise 0. */
typedef struct { u8 pad[0x1090]; u8 tbl[0x140]; u32 bits[8]; } G3018;
typedef struct { u8 f0, f1, kind, flags; u8 pad[14]; u16 id; } P3018;
typedef struct { u8 pad[0x12]; u8 n; u8 pad2[0x21]; u16 a[8]; u16 b[8]; } Q3018;
extern G3018 D_0032e020;
P3018* func_001a80c8(void);
Q3018* ctarget_00188fe0(G3018*, u32) asm("_Z16ctarget_00188fe0jjjj");
s32 ctarget_001a3018(u32 arg0, u32 arg1, u32 arg2, u32 arg3) asm("_Z16ctarget_001a3018jjjj");

// 001a3018: moved to src/anon/unit_001a2a50.cpp
