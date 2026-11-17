#include "../common/types.h"
struct E { u8 type; u8 v[31]; };
struct Tbl { s32 pad; s32 n; E e[1]; };
extern Tbl* D_01d49510;
struct C { u8 p[8]; u32 f; };
struct Y { u8 p[0xc]; C* c; u8 q[0x160-0x10]; u32 fl; };
struct Z { u8 p[0x588]; u32 f; };
struct X { u8 p[0x10]; Z* a; u8 q[4]; u32 fl; u8 r[0x26-0x1c]; u8 o; u8 idx; };
extern "C" s32 func_0019c090(void*);
static inline bool chk2(Y* y) { bool r = false; if ((y->c->f & 2) || (y->fl & 0x40)) r = true; return r; }
static inline bool chk(Y* y) { bool r = false; if (func_0019c090(y) || chk2(y)) r = true; return r; }
static inline bool nchk(Y* y) { return !chk(y); }
extern "C" {
void func_00281f70(u8*, s32, s32);
void func_00282858(u8*, s32, s32);
void func_00282b00(u8*, s32, s32);

// Runs 00281f70, then one of two handlers depending on the flag at +4104.
// Register pins only (no asm): this in s2 and the call arguments set up before the branch,
// as the original does.
void func_002827f0(u8* a, s32 b, s32 c);  // 0x002827f0: definition moved into src/anon/unit_00282620.cpp

// Applies table entries whose type bit is in mask: entry types 7/8/2 are gated by checks on y and x->a,
// then entry byte [x->idx] (if not 255) is stored to x->o.
// 001c20e8: moved to src/anon/unit_001c0638.cpp
void func_001c20e8(u32 mask, X* x, Y* y);

}
