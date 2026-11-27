#include "../common/types.h"

// Empty-destructor local: keeps the last call a jal (no sibling call), as in the original.
struct NoTail_w3727 { ~NoTail_w3727() {} };
struct WHdr_w3727 { u8 pad[12]; s32 count; };

extern "C" {
void sceGsSetDefLoadImage(void*, s16, s16, s16, s16, s16, s16, s16);
void func_003058a0(s32);
void sceGsExecLoadImage(void*, void*);
void func_001e50a8(u32, s32);
extern u8 D_01d9e3f0;

// Draws an entry: the first value is shifted by d and rebased (12288 or 10752) before the call.
void func_001e5220(s16* p, s16 d);  // 0x001e5220: definition moved into src/anon/unit_001e0cb8.cpp

void wtarget_001dc140(u32* a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001dc140jjjj");
// Relocates a loaded data block by (a0 - a1): patches the non-null offsets in its 32-byte entries,
// then hands each listed offset (made absolute) to 001e50a8.
// Register pins and empty asm: the original keeps the block base in t4 (copied first), the header
// in t3 for the first loop, and the first loop's cursor in t5.
void wtarget_001dc140(u32* a0, u32 a1, u32 a2, u32 a3);  // 0x001dc140: definition moved into src/anon/unit_001dbfd8.cpp

struct O_w3727 { u8 pad[0x48c]; s32 x; };
extern O_w3727* D_0034e948;
extern u8 D_00351eb8;
bool YS__OBJ__is_exist(O_w3727*);
bool func_001b58a8();
s32 func_001c8ab0();
bool func_001c8db8(void*, s32);
bool func_001410c8();
bool func_001917c0();
s32 YS__SHEET__is_mpdrive(s32);

// Chain of checks on the current object. All exits go through one return label placed before the
// body (goto form): gcc then merges the epilogue there, as in the original layout.
s32 func_001d4420();  // 0x001d4420: definition moved into src/anon/unit_001d3c08.cpp
}
