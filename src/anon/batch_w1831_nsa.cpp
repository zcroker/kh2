#include "../common/types.h"

// 00168d08: relocates a block's entry pointers after a move and recurses into sub-blocks.
struct W1831Ent { u8 hdr[16]; u16 type; u16 flags; u32 pad; u8* ptr; u32 size; };
struct W1831Blk { u32 f0; s32 count; W1831Blk* base; u32 fc; };

extern "C" {
void func_0011f3e0(u8*);
void func_00131f48(u8*);
void func_0013a8b8(u8*);
void func_001dc140(u8*);
void func_00127dc8(u8*);
void func_001de770(u8*);
void func_002bc708(u8*);

// The second argument is the entry's old pointer; the code never reads it but passes it on.
void func_00168d08(W1831Blk* b, u8* x);  // 0x00168d08: definition moved into src/anon/unit_00168aa0.cpp
}
