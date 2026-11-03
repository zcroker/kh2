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
void func_002827f0(u8* a, s32 b, s32 c) {
    func_00281f70(a, b, c);
    register u8* p asm("$18") = a;
    s32 t = *(s32*)(p + 4104);
    register u8* r4 asm("$4") = p;
    register s32 r5 asm("$5") = b;
    register s32 r6 asm("$6") = c;
    if (t == 0) { func_00282858(r4, r5, r6); return; }
    func_00282b00(r4, r5, r6);
}

// Applies table entries whose type bit is in mask: entry types 7/8/2 are gated by checks on y and x->a,
// then entry byte [x->idx] (if not 255) is stored to x->o.
void func_001c20e8(u32 mask, X* x, Y* y) {
    if (x->fl & 4) return;
    E* e = D_01d49510->e;
    for (s32 i = 0; i < D_01d49510->n; i++, e++) {
        // Constants held in locals: loop.c then keeps 1/7/8 in s5/s7/s8 like the original.
        s32 one = 1, seven = 7, eight = 8;
        s32 t = e->type;
        if (!(mask & (one << t))) continue;
        if (t == seven) goto c7;
        if (t >= 8) goto g8;
        if (t == 2) goto c2;
    ap: {
        u8 v = e->v[x->idx];
        if (v != 255) x->o = v;
        continue;
        }
    c2:
        if (!x->a) continue;
        if (!(x->a->f & 0x4000)) continue;
        goto ap;
    g8:
        if (t != eight) goto ap;
        if (nchk(y) == false) goto ap;
        continue;
    c7:
        if (chk(y)) continue;
        goto ap;
    }
}

}
