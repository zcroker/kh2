#include "../common/types.h"

/* 00147140 */
struct E30 { u8 pad[0x30]; };
struct H147 { u32 x0; struct E30* tab; };
struct O147 { u8 pad[0xd0]; u8 m[0x48]; u16 a; u16 b; };
s32 func_00144d90(void*, void*);
u16 func_00147050(struct H147*, u16, struct O147*, u16, s32*);
void func_00147140(struct H147* h, struct O147* o);  // 0x00147140: definition moved into src/anon/unit_00147140.cpp
