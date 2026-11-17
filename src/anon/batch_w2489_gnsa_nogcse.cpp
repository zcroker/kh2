// 00263ee0: needs -g -fno-strict-aliasing -fno-gcse (_gnsa_nogcse rule).
#include "../common/types.h"
extern "C" {
struct E24 { s16 id; s16 k; u16 v[5]; u16 f14; u16 n; u16 pad18; u32 off; };
struct H16 { u8 pad0[6]; s16 count; u8 pad8[8]; E24 e[1]; };
struct Sub8 { s16 a; u16 b; u32 off; };
struct Out14 { u16 v[5]; s16 z; u8 fl; u8 en; };
H16* func_00263ea8(void);
void func_00263eb8(H16*);
u32 func_001a6d08(s32);
void func_001a6c90(s32);
void func_002641c8(Out14*, u8*, u32, u32);
void func_002640a8(s32 a0, u16 a1, Out14* a2);
void func_00263ee0(s32 a0, Out14* o);  // 0x00263ee0: definition moved into src/anon/unit_00263ee0.cpp
}
