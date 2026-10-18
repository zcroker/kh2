#include "../common/types.h"
extern "C" {
struct Tbl { u8 p0[16]; u8 n0; u8 n1; u8 p12[2]; u16 a[8]; u16 b[8]; };
struct Obj { u8 p0[424]; u8 r[156]; Tbl* t; };
struct Rec { u8 p0[2]; u8 kind; };
u8* func_002924d0(u8*, u32);
Rec* func_001a80c8(u32);
void func_00292520(u8*, s32, s32);
void func_002922e0(u8* p, s32* out, u32 id, u32 alt, u32 k, Obj* o)
{
    s32 found = 0;
    func_002924d0(p, id);
    func_002924d0(p, alt);
    s32 base = 100 - o->r[k];
    u32 q = id ? id : alt;
    s32 kind;
    if (q) kind = func_001a80c8(q)->kind;
    else kind = -1;
    s32 v = 100;
    s32 i;
    for (i = 0; i < o->t->n0; i++) {
        u32 a = o->t->a[i];
        if (!found && kind == 14 && a == id) { a = alt; found = 1; }
        if (a) v = (v * func_002924d0(p, a)[k + 8] + 99) / 100;
    }
    for (i = 0; i < o->t->n1; i++) {
        u32 a = o->t->b[i];
        if (!found && kind == 15 && a == id) { a = alt; found = 1; }
        if (a) v = (v * func_002924d0(p, a)[k + 8] + 99) / 100;
    }
    *out = 100 - v;
    func_00292520(p, base, 100 - v);
}
}
