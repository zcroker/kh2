// Linked unit 0x002793b0-0x00279ec8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 002793b0 (was src/anon/batch_w3780_gnsamam.c)
namespace n002793b0 {
u8* func_002859a0(void) asm("func_002859a0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
s32 func_001058e8(void) asm("func_001058e8");
u8* func_00189200(s32, s32) asm("func_00189200");
u8* func_001a80c8(u16) asm("func_001a80c8");
extern s32 D_0035f01c asm("D_0035f01c");
typedef struct Ent { u16 id; s8 on; s8 slot; s8 col; s8 x11; s8 x12; s8 kind; } Ent;
typedef struct Tbl { s16 mask; u8 pad[5]; s8 n; u8 pad2[4]; Ent e[1]; } Tbl;
extern Tbl* D_0035f230 asm("D_0035f230");
typedef struct Rows { u8 pad[0x5F0]; u16 r[1][48]; } Rows;
/*TARGET 002793b0*/
void func_002793b0(void) asm("func_002793b0");
void func_002793b0(void) {
    u8* base = func_002859a0();
    s32 h;
    if (func_00287bc0() == 15) h = func_0028b040(D_0035f01c);
    else h = func_002570a0(15);
    s32 r0, r1;
    func_0027aed8(h, &r0, &r1);
    if (r0 != 1) return;
    s32 sel = -1;
    s32 c = 0;
    s32 i;
    s16 mask = D_0035f230->mask;
    for (i = 0; i < 16; i++) {
        u8 b = (mask >> i) & 1;
        if (b) {
            if (r1 == c) { sel = i; break; }
            c++;
        }
    }
    u8* p = func_00189200(func_001058e8() + 0x24F0, sel);
    s32 idx = sel - 1;
    if (sel != 7) idx = sel;
    s32 row = idx - 1;
    c = D_0035f230->n;
    for (i = 0; i < 24; i++) {
        if (((u16*)(p + 8))[i] & 0x7FFF) {
            D_0035f230->e[c].id = ((u16*)(p + 8))[i] & 0x7FFF;
            D_0035f230->e[c].on = ((u16*)(p + 8))[i] >> 15;
            D_0035f230->e[c].slot = i;
            switch (func_001a80c8(D_0035f230->e[c].id)[6]) {
            case 0: D_0035f230->e[c].col = 2; break;
            case 1: case 2: D_0035f230->e[c].col = 0; break;
            case 3: D_0035f230->e[c].col = 1; break;
            }
            D_0035f230->e[c].x11 = 0;
            Tbl* q = D_0035f230; register u32 h asm("$14"); asm("lui %0,0x36" : "=r"(h) : "r"(q));
            q->e[c].x12 = -1;
            register Tbl* t asm("$15") = *(Tbl**)(h - 3536);
            s32 k;
            for (k = 0; k < 48; k++) {
                if (((Rows*)base)->r[row][k] == t->e[c].id) break;
            }
            {register s32 m asm("$15"); t->e[c].kind = k < 48 ? (m = -128, m = k | m, m) : -1;}
            c++;
        }
    }
    D_0035f230->n = c;
}
}  // namespace n002793b0

// 00279620 (was src/anon/batch_w2500.cpp)
namespace n00279620 {
struct Ent { u16 id; u8 a; s8 b; u8 c; u8 d; u8 e; s8 f; };
struct Tbl { s16 mask; u8 p2[5]; s8 count; u8 p8[4]; Ent ent[1]; };
struct Item { u16 x; u16 next; };
struct Sub { u16 id; };
union TblP { Tbl* p; s16 h; };
struct Obj { u8 pad[580]; Sub* sub; };
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
Obj* func_00281180(s32, s32) asm("func_00281180");
s32 func_001a80c8(s32) asm("func_001a80c8");
Item* func_001a8190(s32) asm("func_001a8190");
s32 func_00281388(s32) asm("func_00281388");
s32 func_002814b0(s32) asm("func_002814b0");
extern s32 D_0035f010 asm("D_0035f010");
extern s32 D_0035f01c asm("D_0035f01c");
extern TblP D_0035f230 asm("D_0035f230");
static inline void addEnt(s32 n, s32 id) {
    D_0035f230.p->ent[n].id = id;
    D_0035f230.p->ent[n].a = 1;
    D_0035f230.p->ent[n].b = -1;
    D_0035f230.p->ent[n].c = 3;
    D_0035f230.p->ent[n].d = 0;
    D_0035f230.p->ent[n].f = -1;
}
/*TARGET 00279620*/
void func_00279620(void) asm("func_00279620");
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
}  // namespace n00279620

// 00279860 (was src/anon/batch_w8018.c)
namespace n00279860 {
extern u8* D_0035f230 asm("D_0035f230");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f010 asm("D_0035f010");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
u8* func_00281180(s32, s32) asm("func_00281180");
u8* func_001a80c8(u16) asm("func_001a80c8");
s32 func_001145b0(u16) asm("func_001145b0");
/*TARGET 00279860*/
void func_00279860(void) asm("func_00279860");
void func_00279860(void) {
    s32 i;
    s32 v;
    s32 a, b;
    s32 k;
    s32 r;
    for (i = 0; i < (s8)D_0035f230[7]; i++) {
        D_0035f230[i * 8 + 0x12] = 0xff;
    }
    if (func_00287bc0() == 15) {
        v = func_0028b040(D_0035f01c);
    } else {
        v = func_002570a0(15);
    }
    func_0027aed8(v, &a, &b);
    k = 0;
    if (a == 0) k = b;
    if (k != 0) {
        s32 base = *(s32*)(func_00281180(D_0035f010, k) + 0x244);
        for (i = 0; i < (s8)D_0035f230[7]; i++) {
            if (func_001a80c8(*(u16*)(D_0035f230 + i * 8 + 0xc))[6] == 2) {
                v = func_001145b0(*(u16*)(D_0035f230 + i * 8 + 0xc));
                D_0035f230[i * 8 + 0x12] = *(u8*)(v + base + 0xf5);
            }
        }
    }
}
}  // namespace n00279860

// 002799b0 (was src/anon/batch_w1589.cpp)
namespace n002799b0 {
struct W1589En { u8 x[2]; s8 a; u8 y[2]; s8 b; u8 z[2]; };
struct W1589S { u8 pad[4]; u16 h4; u8 pad6; s8 n; u8 p8[4]; W1589En e[1]; };
/* union with a u16 member: the original reloads the pointer after each u16 store */
union W1589G { W1589S* p; void* v; u16 h; s8 c; };
extern W1589G D_0035f230 asm("D_0035f230");
/*TARGET 002799b0*/
void func_002799b0(void) asm("func_002799b0");
void func_002799b0(void)
{
    s32 i;
    D_0035f230.p->h4 = 0;
    for (i = 0; i < D_0035f230.p->n; i++) {
        W1589S* p = D_0035f230.p;
        if (p->e[i].a) p->h4 += p->e[i].b;
    }
}
}  // namespace n002799b0

// 00279a10 (was src/anon/batch_wcx2.cpp)
namespace n00279a10 {
// 0x001169e8: definition moved into src/anon/unit_00114a90.cpp

// --------------------
// Sort the slot list by kind, then by the order the ids appear in the 0x13-type entry list.
struct Item279a10 { u16 id; u8 b2; u8 b3; s8 kind; u8 pad[3]; };
struct Mgr279a10 { u8 pad[7]; s8 count; u8 pad2[4]; Item279a10 items[1]; };
struct Ent279a10 { u16 id; u8 type; };
union MgrP279a10 { Mgr279a10* p; u32 u; u8 c; };
extern MgrP279a10 D_0035f230 asm("D_0035f230");
Ent279a10* func_001a8110_x13535(Ent279a10* p) asm("func_001a8110");
/*TARGET 00279a10*/
void func_00279a10(void) asm("func_00279a10");
void func_00279a10(void)
{
    s16 order[80];
    Item279a10 t;
    Ent279a10* p;
    s32 i, j, n;
    s16 o;

    p = 0;
    if (D_0035f230.p->count == 0) return;
    for (i = 0; i < D_0035f230.p->count; i++) order[i] = -1;
    for (i = 0; i < D_0035f230.p->count; i++) {
        for (j = i + 1; j < D_0035f230.p->count; j++) {
            if (D_0035f230.p->items[i].kind > D_0035f230.p->items[j].kind) {
                t = D_0035f230.p->items[i];
                D_0035f230.p->items[i] = D_0035f230.p->items[j];
                D_0035f230.p->items[j] = t;
            }
        }
    }
    n = 0;
    for (;;) {
        p = func_001a8110_x13535(p);
        if (p == 0) break;
        if (p->type == 19) {
            for (i = 0; i < D_0035f230.p->count; i++) {
                if (D_0035f230.p->items[i].id == p->id) order[i] = n;
            }
        }
        n++;
    }
    for (i = 0; i < D_0035f230.p->count; i++) {
        if (D_0035f230.p->items[i].kind == 3) continue;
        for (j = i + 1; j < D_0035f230.p->count; j++) {
            if (D_0035f230.p->items[i].kind != D_0035f230.p->items[j].kind) break;
            if (order[i] > order[j]) {
                t = D_0035f230.p->items[i];
                D_0035f230.p->items[i] = D_0035f230.p->items[j];
                D_0035f230.p->items[j] = t;
                o = order[i];
                order[i] = order[j];
                order[j] = o;
            }
        }
    }
}
}  // namespace n00279a10

// 00279cd8 (was src/anon/perm_00279cd8.cpp)
namespace n00279cd8 {
typedef unsigned char u8;
typedef signed int s32;
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_0035f03c asm("D_0035f03c");
u8 *func_00257770(void) asm("func_00257770");
void func_00139d78(void *) asm("func_00139d78");
void func_0028d8c0(void *, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(void *, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
s32 func_0023aa98(void *) asm("func_0023aa98");
s32 func_0023aa78(void *) asm("func_0023aa78");
s32 func_0023aa18(void *) asm("func_0023aa18");
s32 func_0023aa38(void *) asm("func_0023aa38");
void func_00138c10(void *, s32) asm("func_00138c10");
void func_00138c68(void *, s32, s32) asm("func_00138c68");
void func_0028dcc0(void *, void *) asm("func_0028dcc0");
void func_00139688(void *) asm("func_00139688");
void func_00139620(void *) asm("func_00139620");
void func_001395f8(void *) asm("func_001395f8");
s32 func_00257140(s32) asm("func_00257140");
void func_001398d0(s32) asm("func_001398d0");
/*TARGET 00279cd8*/
void func_00279cd8(void) asm("func_00279cd8");
void func_00279cd8(void)
{
  int new_var;
  s32 i = 0;
  u8 *base = func_00257770();
  func_00139d78(base);
  u8 *p = base;
  func_0028d8c0(base, 30013, D_0035ef68, D_0035ef64, D_0035f03c, 140, 141, 100);
  do
  {
    u8 *a = p + 13840;
    u8 *q = p + 13864;
    u8 *b = p + 3376;
    new_var = 1;
    func_0028d980(a, 30014, D_0035ef68, D_0035ef64, D_0035f03c, 150, -new_var, -new_var, 100);
    s32 w = func_0023aa98(q);
    s32 h = func_0023aa78(q);
    s32 x = func_0023aa18(q);
    s32 y = func_0023aa38(q);
    func_00138c10(a, D_0035ef6c);
    func_00138c68(a, (i % 2) * w, (i / 2) * h);
    i++;
    func_0028dcc0(a, base);
    func_00139688(a);
    func_00139620(a);
    func_0028d980(b, 30015, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -new_var, -new_var, 100);
    func_0028dcc0(b, a);
    func_00138c68(b, x, y);
    func_00139620(b);
    func_001395f8(b);
    *((s32 *) (p + 3808)) = new_var;
    p += 436;
  }
  while (i < 20);
  if (p || D_0035f03c)
  {
    func_001398d0(100);
  }
  else
  {
    func_001398d0(100);
  }
}
}  // namespace n00279cd8

