#include "../common/types.h"
extern "C" {
u8* func_001a1728(s32, s32);
void func_001a17c8(u8*);
s32 func_00291370(u8*, s32);
s32 func_0023aa78(u8*);
s32 func_0023aa98(u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00138c10(u8*, s32);
void func_00138c68(u8*, s32, s32);
void func_00192cc0(char*, const char*, ...);
extern char D_00374498[];
extern char D_003744a0[];

void func_00291ba8(u8* w, s32 mode, s32 a2, s32 a3, s32 a4, s32 mask);  // 00291ba8: moved to src/anon/unit_00290f78.cpp
}
namespace w1606n {
struct Ent { u16 id; u8 a; s8 b; u8 c; u8 d; u8 e; s8 f; };
struct Tbl { s16 mask; u8 p2[5]; s8 count; u8 p8[4]; Ent ent[1]; };
struct Item { u16 x; u16 next; };
struct Sub { u16 id; };
union TblP { Tbl* p; s16 h; };
struct Obj { u8 pad[580]; Sub* sub; };
}
using namespace w1606n;
extern "C" {
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
Obj* func_00281180(s32, s32);
s32 func_001a80c8(s32);
Item* func_001a8190(s32);
s32 func_00281388(s32);
s32 func_002814b0(s32);
extern s32 D_0035f010;
extern s32 D_0035f01c;
extern TblP D_0035f230;

static inline void addEnt(s32 n, s32 id) {
    D_0035f230.p->ent[n].id = id;
    D_0035f230.p->ent[n].a = 1;
    D_0035f230.p->ent[n].b = -1;
    D_0035f230.p->ent[n].c = 3;
    D_0035f230.p->ent[n].d = 0;
    D_0035f230.p->ent[n].f = -1;
}

void func_00279620(void) {
    s32 kind;
    s32 idx;
    s32 h;
    s32 c;
    if ((c = func_00287bc0()) == 15) h = func_0028b040(D_0035f01c);
    else h = func_002570a0(15);
    func_0027aed8(h, &kind, &idx);
    Obj* o = func_00281180(D_0035f010, kind ? 0 : idx);
    s32 n = D_0035f230.p->count;
    s32 it = func_001a80c8(o->sub->id);
    if (func_001a8190(it)->next) {
        it = func_001a8190(it)->next;
        func_001a80c8(it);
        addEnt(n, it);
        n++;
    }
    if (kind == 1) {
        s32 sel = -1;
        c = 0;
        s32 j;
        for (j = 0; j < 16; j++) {
            bool off = !((D_0035f230.p->mask >> j) & 1);
            if ((u8)off) continue;
            if (c == idx) { sel = j; break; }
            c++;
        }
        if (func_00281388(sel)) {
            it = func_001a80c8(func_002814b0(sel));
            if (func_001a8190(it)->next) {
                it = func_001a8190(it)->next;
                func_001a80c8(it);
                addEnt(n, it);
                n++;
            }
        }
    }
    D_0035f230.p->count = n;
}
}
