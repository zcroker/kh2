// w3902 (zl90). Built with -fno-strict-aliasing (_nsa).
#include "../common/types.h"

extern "C" {

struct Ent26b { s32 a; s32 b; s32 c; };
struct Obj26b { u8 p0[0x12]; u8 n; u8 p13[0x34 - 0x13]; u16 x[8]; u16 y[8]; };
extern s32 D_0035f010;
s32 func_00257070(s32);
u8* func_00281180(s32, s32);
void func_002fde18(void*, s32, s32);
u16* func_001a8110(u16*);


// Sorts the object's (x, y) id pairs by the order in which the ids appear in
// the func_001a8110 list. Reusing v for the func_00257070 result gives v the
// v0 preference; the explicit goto reproduces the original's jump threading.
void func_0026b5a0(s32 arg)
{
    Ent26b e[8];
    s32 ids[8];
    u16* it = 0;
    s32 i, j, cnt, ord;
    s32 v;
    Obj26b* o;
    v = func_00257070(arg < 0 ? 1 : arg);
    o = *(Obj26b**)(func_00281180(D_0035f010, v) + 0x244);
    u8 n = o->n;
    func_002fde18(e, 0, sizeof(e));
    for (i = 0; i < n; i++) {
        Ent26b* p = &e[i];
        p->a = o->x[i];
        p->b = o->y[i];
        p->c = 999;
    }
    cnt = 0;
    for (i = 0; i < n; i++) {
        { s32 t = e[i].a; if (t) { v = t; goto have; } }
        v = e[i].b;
        if (v == 0) continue;
    have:
        for (j = 0; j < cnt; j++)
            if (v == ids[j]) break;
        if (j < cnt) continue;
        ids[cnt++] = v;
    }
    ord = 0;
    for (;;) {
        it = func_001a8110(it);
        if (!it) break;
        if (((u8*)it)[2]) continue;
        for (i = 0; i < cnt; i++) {
            if (it[0] != ids[i]) continue;
            for (j = 0; j < n; j++) {
                if (e[j].a == ids[i] || e[j].b == ids[i]) e[j].c = ord + (e[j].a == 0);
            }
            ord += 2;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (e[j].c < e[i].c) {
                Ent26b t = e[i];
                e[i] = e[j];
                e[j] = t;
            }
        }
    }
    for (i = 0; i < n; i++) {
        o->x[i] = e[i].a;
        o->y[i] = e[i].b;
    }
}

}
