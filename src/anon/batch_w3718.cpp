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
void func_00320528(u8* p) {
    *(u32*)(p + 4) = 0;
    func_001ddd10(p + 0xc);
    *(u32*)(p + 0x58) = 0;
    *(u32*)(p + 0x74) = 0;
    *(u32*)(p + 0x90) = 0;
    *(u32*)(p + 0xac) = 0;
    { u8* q = p + 0xbc;
    *(void**)(p + 0x5c) = 0;
    *(u32*)(q + 4) = 0;
    *(void**)(p + 0x78) = 0;
    *(u32*)q = (u32)D_003525c8;
    *(void**)(p + 0x94) = 0;
    *(void**)(p + 0xb0) = 0;
    *(u32*)(p + 0xc4) = 0;
    func_00320400(q + 0xc); func_001d1678(q, -1); }
    *(void**)(p + 0xbc) = D_003525a8;
    { u8* q = p + 0xe8; s32 i = 2; do { c320528_B(q); *(void**)q = D_00352588; *(u32*)(q + 0x30) = 0; i--; q += 0x38; } while (i != -1); }
    { u8* q = p + 0x190; s32 i = 2; do { c320528_B(q); *(void**)q = D_00352560; *(u32*)(q + 0x30) = 0; i--; q += 0x34; } while (i != -1); }
    u8* q;
    q = p + 0x22c;
    *(u32*)(p + 0x234) = 0; *(void**)(q + 4) = 0; *(void**)q = D_003525c8; func_00320400(q + 0xc); func_001d1678(q, -1); *(void**)(p + 0x22c) = D_00352858;
    q = p + 0x260;
    func_001d1fa8(q);
    *(u32*)(p + 0x2d0) = 0;
    *(u32*)(p + 0x2d4) = 0;
    func_001d4d28(p + 0x2e4);
}
}
