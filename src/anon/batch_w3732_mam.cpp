// 002823b0: fills the entry table (id/a/b/c per slot) from five item lists; list 0 picks the k-th set bit of a mask.
// Built with -fmove-all-movables (_mam). Partial asm: one empty asm("" : "+r"(a)) (no code) adds refs to 'a' so
// global alloc gives it s0 before the items+2j giv (otherwise s0/s2 swap). 'total' read through a union so its
// store keeps the original's dependence on the stack spills (the original looks like -fno-strict-aliasing here).
#include "../common/types.h"
struct Ent2823 { u16 id; u8 a; u8 b; s16 c; };
struct Obj2823 { u8 pad[580]; u16* items; };
union Tot2823 { s32 i; u8 c; };
struct Self2823 { Tot2823 total; Ent2823 ent[682]; u8 pad[4]; s32 f1004; s32 f1008; s32 f100c; s32 cnt[5]; };
extern "C" {
s32 func_002811f8(s32, s32);
Obj2823* func_00281180(s32, s32);
s32 func_002826f8(Self2823*, s32, s32);
s32 func_00281480(s32, s32);
s32 func_002813b8(void);
s32 func_00281420(void);
u16 func_002814b0(s32);
void func_002823b0(Self2823* self, s32 b, s32 r);  // 0x002823b0: definition moved into src/anon/unit_002823b0.cpp
}
