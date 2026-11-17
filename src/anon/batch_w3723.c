// w3723 2026-11-04: 001e2c90 (partMng.c texture/clut relocation) from best/001e2c90_inlineassert.c.
// Fixes: an extra early "no new texp/clutp and not first" return (gives the original jump threading and
// the out-of-line shTexpNew block), and one shTexpOld variable shared by the first-time and texp-shift blocks.
// Only asm: the assert trap "break" (one instruction).
#include "../common/types.h"
typedef struct { u8 pad0; s8 type; s16 count; u8 pad4[4]; u32 tex0lo; u32 tex0hi; } PartRec1e2c90;
typedef struct { u8 pad0[2]; s16 texp; s16 clutp; } PartCur1e2c90;
extern char D_0036e978[];
extern char D_0036e998[];
extern char D_0036e9d0[];
extern char D_0036e9e0[];
extern char D_0036ea10[];
extern char D_0036ea40[];
extern char D_0036ea70[];
extern char D_0036ea98[];
extern char D_0036eaa0[];
void func_002fdfc8(const char*, ...);
void func_001e2ad8(const char*, const char*, s32, const char*);
static inline void ryj001e2c90(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap: hand-written break */
}
#define ASSERT1e2c90(c, s, line) if (!(c)) ryj001e2c90(s, D_0036e9d0, line)
void func_001e2c90(u8* base, PartCur1e2c90* cur, s16 shTexpNew, s16 shClutpNew);  // 0x001e2c90: definition moved into src/anon/unit_001e0cb8.cpp
