// 002e5fb8: empty asm uses (no code) keep s and the type byte live so registers come out as in the original.
#include "../common/types.h"
struct H18 { u8 pad[8]; u32 sz8; u16 sz12; u8 pad2[5]; u8 f13; };
struct P18 { u8 pad[5]; u8 type; };
struct W18 { u8 pad[0x90]; u64 a[16]; u8 pad2[0x1a0 - 0x110]; u64 b[16]; u8 pad3[0x220 - 0x220]; P18* src; H18* hdr; u8* p2; u8* p3; };
static inline u32 al18(u32 x, u32 a) { u32 m = x % a; return m ? x + (a - m) : x; }
extern "C" {
void func_002e5fb8(W18* w, P18* s);  // 0x002e5fb8: definition moved into src/anon/unit_002e5f70.cpp
}
