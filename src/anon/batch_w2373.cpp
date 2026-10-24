#include "../common/types.h"

struct P2db968 { u8 pad[0x48]; f32 x; f32 y; };

static inline u8 ca88_anyFlag(u32 fl) {
    u8 r = 0;
    if (fl & 4) goto set;
    if (fl & 8) goto set;
    if (!(fl & 0x10)) goto out;
set:
    r = 1;
out:
    return r;
}

extern "C" {
P2db968* func_002d73f0(s32);
void func_002e7340(f32, f32, s32, s32, s32, void*);
extern s32 D_00361f60;
extern u8 D_003628e8[];
extern u8 D_003628f8[];

/* 0017ca88: true when p has state flag 4/8/0x10, is not blocked (1416&2 && 2040&4), and the height at +208
   exceeds 15 (or the reference at +212 plus 6 when that is set). */
s32 func_0017ca88(void* self, u8* p)
{
    u8 m = ca88_anyFlag(*(u32*)(p + 352));
    if (!m) return 0;
    if ((*(u32*)(p + 1416) & 2) && (*(u32*)(p + 2040) & 4)) return 0;
    f32 h = *(f32*)(p + 212);
    if (h == 0.0f) return 15.0f < *(f32*)(p + 208);
    return h + 6.0f < *(f32*)(p + 208);
}

/* The always_inline helper (argument b = a + 0xba0 passed in) reproduces the original's saved-but-unused s4. */
static inline __attribute__((always_inline)) void db968_draw(s32 b, s32 a, s32 mode, void* tex, s32 g) {
    P2db968* p = func_002d73f0(g);
    P2db968* q = func_002d73f0(g);
    func_002e7340(p->x, q->y, b, a, mode, tex);
}

/* 002db968: draw element a (style 3 or 6) at the current target's x/y. */
void func_002db968(s32 a, u8 f) {
    s32 g = D_00361f60;
    if (f) db968_draw(a + 0xba0, a, 3, D_003628f8, g);
    else db968_draw(a + 0xba0, a, 6, D_003628e8, g);
}
}
