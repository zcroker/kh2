#include "../common/types.h"
extern "C" {
struct Tbl { u8 p0[16]; u8 n0; u8 n1; u8 p12[2]; u16 a[8]; u16 b[8]; };
struct Obj { u8 p0[424]; u8 r[156]; Tbl* t; };
struct Rec { u8 p0[2]; u8 kind; };
u8* func_002924d0(u8*, u32);
Rec* func_001a80c8(u32);
void func_00292520(u8*, s32, s32);
void func_002922e0(u8* p, s32* out, u32 id, u32 alt, u32 k, Obj* o);  // 002922e0: moved to src/anon/unit_00290f78.cpp
}
