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
void func_001e3040(PartHdr1e3040* h, PartCur1e3040* cur, s16 shTexpNew, s16 shClutpNew)
{
    s16 shTexpDif = 0;
    s16 shClutpDif = 0;
    s32 first = 0;
    s32 n;
    s16 shTexpOld, shClutpOld;
    PartEnt1e3040* e;
    if (cur->texp == 0) {
        first = 1;
        cur->texp = 11264;
        cur->clutp = 15744;
    }
    if (!shTexpNew && !shClutpNew && !first) return;
    if (shTexpNew) shTexpDif = shTexpNew - cur->texp;
    if (shClutpNew) shClutpDif = shClutpNew - cur->clutp;
    e = h->ent;
    for (n = h->count; n > 0; n--, e++) {
        PartRec1e3040* p = (PartRec1e3040*)((u8*)h + e->off);
        if (first) {
            shTexpOld = p->tex0lo & 0x3fff;
            if (shTexpOld >= 12288) p->tex0lo = (p->tex0lo & ~0x3fff) + shTexpOld - 1024;
            else p->tex0lo = (p->tex0lo & ~0x3fff) + shTexpOld - 512;
            shClutpOld = (p->tex0hi >> 5) & 0x3fff;
            if (shClutpOld >= 15872) p->tex0hi = (p->tex0hi & 0xfff8001f) + ((shClutpOld - 128) << 5);
            else p->tex0hi = (p->tex0hi & 0xfff8001f) + ((shClutpOld + 3840) << 5);
        }
        if (shTexpNew && shTexpDif) {
            shTexpOld = p->tex0lo & 0x3fff;
            if (shTexpOld >= 11264) {
                s32 v = shTexpOld + shTexpDif;
                ASSERT1e3040(11264 <= v, D_0036e9e0, 576);
                ASSERT1e3040(v < 15616, D_0036ea10, 577);
                p->tex0lo = (p->tex0lo & ~0x3fff) + v;
            }
        }
        if (shClutpNew && shClutpDif) {
            shClutpOld = (p->tex0hi >> 5) & 0x3fff;
            if (shClutpOld >= 15744) {
                s32 v = shClutpOld + shClutpDif;
                ASSERT1e3040(15744 <= v, D_0036ea40, 587);
                ASSERT1e3040(v < 16384, D_0036ea70, 588);
                p->tex0hi = (p->tex0hi & 0xfff8001f) + (v << 5);
            }
        }
    }
}
