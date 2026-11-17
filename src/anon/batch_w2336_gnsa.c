#include "../common/types.h"

/* Plain C (partMng.c), built with -g and without strict aliasing (-g makes no difference here). */
typedef struct { u8 pad0[16]; u32 tex0lo; u32 tex0hi; } PartRec1e3040;
typedef struct { s16 off; u8 pad[6]; } PartEnt1e3040;
typedef struct { u8 pad0[6]; s16 count; u8 pad8[8]; PartEnt1e3040 ent[1]; } PartHdr1e3040;
typedef struct { u8 pad0[2]; s16 texp; s16 clutp; } PartCur1e3040;
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
static inline void ryj001e3040(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap: hand-written break */
}
#define ASSERT1e3040(c, s, line) if (!(c)) ryj001e3040(s, D_0036e9d0, line)
void func_001e3040(PartHdr1e3040* h, PartCur1e3040* cur, s16 shTexpNew, s16 shClutpNew);  // 0x001e3040: definition moved into src/anon/unit_001e0cb8.cpp
