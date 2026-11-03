// w3724 (from zl90 w2421): built with -fno-strict-aliasing. Plain C, no asm.
#include "../common/types.h"
namespace n002ae320 {
struct Ent { u8 a; u8 b; };
struct Bits {
    u32 w[2];
    s32 Test(u32 b) { return w[b >> 5] & (1 << (b & 31)); }
    void Set(u32 b) { u32* p = &w[b >> 5]; *p |= 1 << (b & 31); }
};
struct HBits {
    u16 h[1];
    s32 Test(u32 b) { return h[b >> 4] & (1 << (b & 15)); }
    void Set(u32 b) { u16* p = &h[b >> 4]; *p |= 1 << (b & 15); }
};
struct Flags { u8 pad[0x144]; Bits x[10]; Bits y[10]; u8 pad2[484 - 0x144 - 160]; HBits hb; };
struct Rec { u8 a; u8 b; u8 pad[14]; };
struct Tbl { u8 pad[8]; s32 n; u8 pad2[4]; Rec r[1]; };
extern "C" {
extern Flags* D_0035f620;
extern Bits* D_0035f624;
extern s32 D_0035f628;
extern s32 D_0035f62c;
Tbl* func_00294000(s32);
Flags* func_002a9d68(void);
Ent* func_001d9e30(Ent*);
s32 func_001d9d48(Ent*);
s32 func_002b3ac8(s32);
}
static inline s32 T1(u8 a, u8 b) { return D_0035f624[a].Test(b); }
static inline void S1(u8 a, u8 b) { D_0035f624[a].Set(b); }
static inline s32 TY(u8 a, u8 b) { return D_0035f620->y[a].Test(b); }
static inline void SY(u8 a, u8 b) { D_0035f620->y[a].Set(b); }
extern "C" {
// Rebuilds the seen/collected bit tables and their counters (D_0035f628 total, D_0035f62c set).
// The unused i++ in the second loop gives it one latch, which matches the original block frequencies.
void func_002ae320(void) {
    Ent* e = 0;
    s32 i = 0;
    Tbl* t = func_00294000(9);
    Rec* r = t->r;
    Flags* f = func_002a9d68();
    while (i < 10) {
        Bits* b = &D_0035f624[i];
        b->w[0] = 0;
        b->w[1] = 0;
        i++;
    }
    for (;; i++) {
        e = func_001d9e30(e);
        if (e == 0) break;
        if (!T1(e->a, e->b)) D_0035f628++;
        S1(e->a, e->b);
        if (func_001d9d48(e)) {
            D_0035f620->x[e->a].Set(e->b);
            if (!TY(e->a, e->b)) D_0035f62c++;
            SY(e->a, e->b);
        }
    }
    for (i = 0; i < t->n; i++, r++) {
        s32 n = func_002b3ac8((s8)(r->b & 15));
        D_0035f628 += n;
        for (s32 j = 0; j < n; j++) {
            if (D_0035f620->x[i].Test(j)) D_0035f62c++;
        }
    }
    for (i = 0; i < t->n; i++) {
        D_0035f628++;
        if (f->hb.Test(i)) {
            D_0035f620->hb.Set(i);
            D_0035f62c++;
        }
    }
}
}
}
