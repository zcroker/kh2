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

void func_00291ba8(u8* w, s32 mode, s32 a2, s32 a3, s32 a4, s32 mask) {
    if (__builtin_expect(mode == 0,0)) return;
    if (mode == 4) return;
    u8* r = func_001a1728(a3, a4);
    s32 base;
    if (__builtin_expect(mode == 2,0)) base = *(s16*)(w + 11062);
    else base = func_00291370(w, 2);
    s32 n = 0;
    u8* q = w + 28;
    s32 i = 0;
    func_0023aa78(q);
    s32 x = func_0023aa98(q);
    func_0023aa18(q);
    func_0023aa38(q);
    for (; __builtin_expect(i < 9, 1); i++) {
        bool off = !((mask >> i) & 1);
        if ((u8)off) continue;
        if (i == 8) continue;
        s32 k = n + 5;
        s32 v = mode == 1 ? x : 0;
        u8* o = w + k * 436 + 4364;
        func_00138c10(o, base);
        func_00138c68(o, v, 0);
        s32 val = -1;
        switch (i) {
        case 0: val = *(u16*)(r + 398); break;
        case 1: val = *(u16*)(r + 392); break;
        case 2: val = *(u16*)(r + 394); break;
        case 3: val = *(u16*)(r + 396); break;
        case 4: val = r[425]; break;
        case 5: val = r[426]; break;
        case 6: val = r[427]; break;
        case 7: val = r[428]; break;
        case 8: break;
        }
        if ((u32)(i - 4) < 4) func_00192cc0((char*)(w + k * 8 + 10904), D_00374498, 100 - val);
        else func_00192cc0((char*)(w + k * 8 + 10904), D_003744a0, val);
        n++;
        *(u8**)(o + 408) = w + k * 8 + 10904;
    }
    func_001a17c8(r);
}
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
