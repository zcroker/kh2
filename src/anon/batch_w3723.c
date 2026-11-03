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
void func_001e2c90(u8* base, PartCur1e2c90* cur, s16 shTexpNew, s16 shClutpNew)
{
    s16 shTexpDif = 0;
    s16 shClutpDif = 0;
    s32 first = 0;
    PartRec1e2c90* p = (PartRec1e2c90*)(base + *(s32*)(base + 4));
    if (cur->texp == 0) {
        first = 1;
        cur->texp = 11264;
        cur->clutp = 15744;
    }
    if (!(shTexpNew || shClutpNew || first)) return;
    if (shTexpNew) shTexpDif = shTexpNew - cur->texp;
    if (shClutpNew) shClutpDif = shClutpNew - cur->clutp;
    if (!shTexpDif && !shClutpDif && !first) return;
    while (p->type != -1) {
        s16 shTexpOld;
        s32 tex = 1;
        s32 sz = 0;
        switch (p->type) {
        case 0:
            sz = 20;
            tex = 0;
            break;
        case 1:
            sz = 28;
            tex = 0;
            break;
        case 2:
            sz = 32;
            break;
        case 4:
            sz = 24;
            tex = 0;
            break;
        case 5:
            sz = 32;
            tex = 0;
            break;
        case 3:
        case 6:
            sz = 40;
            break;
        case 7:
            sz = 48;
            break;
        default:
            func_001e2ad8(D_0036ea98, D_0036e9d0, 464, D_0036eaa0);
            break;
        }
        if (tex) {
            if (first) {
                shTexpOld = p->tex0lo & 0x3fff;
                if (shTexpOld >= 12288) p->tex0lo = (p->tex0lo & ~0x3fff) + (shTexpOld - 1024);
                else p->tex0lo = (p->tex0lo & ~0x3fff) + (shTexpOld - 512);
                s16 shClutpOld = (p->tex0hi >> 5) & 0x3fff;
                if (shClutpOld >= 15872) p->tex0hi = (p->tex0hi & 0xfff8001f) + ((shClutpOld - 128) << 5);
                else p->tex0hi = (p->tex0hi & 0xfff8001f) + ((shClutpOld + 3840) << 5);
            }
            if (shTexpNew && shTexpDif) {
                shTexpOld = p->tex0lo & 0x3fff;
                if (shTexpOld >= 11264) {
                    s32 n = shTexpOld + shTexpDif;
                    ASSERT1e2c90(11264 <= n, D_0036e9e0, 495);
                    ASSERT1e2c90(n < 15616, D_0036ea10, 496);
                    p->tex0lo = (p->tex0lo & ~0x3fff) + n;
                }
            }
            if (shClutpNew && shClutpDif) {
                s16 shClutpOld = (p->tex0hi >> 5) & 0x3fff;
                if (shClutpOld >= 15744) {
                    s32 n = shClutpOld + shClutpDif;
                    ASSERT1e2c90(15744 <= n, D_0036ea40, 506);
                    ASSERT1e2c90(n < 16384, D_0036ea70, 507);
                    p->tex0hi = (p->tex0hi & 0xfff8001f) + (n << 5);
                }
            }
        }
        p = (PartRec1e2c90*)((u8*)p + sz * p->count);
        p++;
    }
}
