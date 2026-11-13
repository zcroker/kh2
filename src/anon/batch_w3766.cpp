#include "../common/types.h"
struct CEnt { u32 a, b; s32 x8; s32 xc; };
struct CArr { u32 a; s32 n; };
struct CHdr { u8 pad[0x28]; s32 x28; u8 pad2[4]; s32 x30; s32 x34; };
struct CObj {
    u8 state; u8 next; u8 pad[0x26];
    s32 x28;
    u8 pad2c[4];
    CArr* arr;
    u8 pad34[4];
    union { u32* ids; struct { s16 id; s16 res; } s; } u;
};
static inline int ge10k(s32 v) { return v >= 10000; }
extern "C" {
CEnt* func_00168b38(CArr*, s32, s32);
void func_00168be8(s32);
CHdr* func_0016fac8(s32);
void cbh_ctor_0016fba0(CHdr*, u32, s32, s32) asm("_ZN2YS10CACHE_BUFF6HEADERC1EPKcij");
void* cbh_find_00170240(u32, s32) asm("_Z16ctarget_00170240jjjj");
void func_001700e8(void*, s32);
void func_00170188(CHdr*);
void func_00170178(void);
s16 func_002ba3b8(s16, s32, s32, s32, s32, void (*)(void), CObj*);

// Cache-buffer loader state step: state 1 starts the two streams, state 2 builds one header per entry, then goes to state 3.
// Partial asm (w3766): the sz/new-header s0 sharing needs h pinned to s0; three one-instruction asms keep the
// original order move a3,s0 / move s0,v0 / move a0,v0 / li a2 (gcc otherwise emits move a0,v0 first).
void func_0016fda8(CObj* o);  // 0x0016fda8: definition moved into src/anon/unit_0016e8f8.cpp
}
