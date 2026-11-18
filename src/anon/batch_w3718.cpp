#include "../common/types.h"
extern "C" {
void func_001ddd10(void*);
void func_00320400(void*);
void func_001d1678(void*, s32);
void func_001d1fa8(void*);
void func_001d4d28(void*);
extern u8 D_003525c8[];
extern u8 D_003525a8[];
extern u8 D_00352588[];
extern u8 D_00352560[];
extern u8 D_00352858[];
static inline void c320528_B(u8* p) { *(u32*)(p + 4) = 0; *(u32*)(p + 8) = 0; *(void**)p = D_003525c8; func_00320400(p + 0xc); func_001d1678(p, -1); }
static inline void c320528_B2(u8* p) { *(u32*)(p + 4) = 0; *(void**)p = D_003525c8; func_00320400(p + 0xc); func_001d1678(p, -1); }
static inline void c320528_P(u8* p) { *(u32*)(p + 0) = 0; *(u32*)(p + 4) = 0; }
// Constructor: zeroes fields, builds the embedded sub-objects at +0xbc, +0xe8 (x3), +0x190 (x3), +0x22c and +0x260.
// The +0x5c/+0x78/+0x94/+0xb0 and +0x22c members are pointer-typed (their alias set fixes the store order).
void func_00320528(u8* p);  // 0x00320528: definition moved into src/anon/unit_00320528.cpp
}
