#include "../common/types.h"
extern "C" {

struct E14 { u8 a; u8 b; u8 pad[12]; };
struct Tbl { s32 x; s32 n; E14 e[1]; };
extern Tbl* D_01c940b4;
E14* func_001aff90(s32 a, s32 b)
{
    E14* e = D_01c940b4->e;
    for (s32 i = 0; i < D_01c940b4->n; i++, e++) {
        if (e->a == a && e->b == b) return e;
    }
    return 0;
}

struct M2D { u8 pad[0x1c]; s32 m1c; u8 pad2[0x18]; s32 m38; };
void check_warning(M2D* self, s32 v) asm("_ZN2YS9MISSION2D13check_warningEi");
void func_001d2248(M2D* o, s32 v)
{
    if (o->m38 < v) {
        o->m38 = v;
        check_warning(o, v);
        if (o->m1c != 0 && o->m1c < o->m38) o->m1c = o->m38;
    }
}

extern s16 D_0035f4e0;
struct E4 { u16 id; u16 x; };
extern E4* D_0035f4dc;
s32 func_00292af0(s32 id)
{
    s32 r = 0;
    for (s32 i = 0; i < D_0035f4e0; i++) {
        if (D_0035f4dc[i].id == id) { r = 1; break; }
    }
    return r;
}

struct O2da { u8 pad[0xbf4]; s32 p; };
s32 func_0016c028(s32);
void func_002bc188(s32, s32);
void func_002daa00(O2da* o, u32 a)
{
    if (o->p) {
        a += 0x56ab8;
        func_002bc188(a, func_0016c028(o->p));
    }
}

}
