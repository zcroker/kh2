#include "../common/types.h"
// C, not C++ (C++ adds an extra andi 0xff on the flags & 1 test), built with
// -fno-strict-aliasing (_nsa rule).
// Partial inline asm: two empty non-volatile asm ties (no code) that keep the
// row offset live past the add, so local-alloc does not put the multiply in a2.
// No register pins, no hand-written instructions.
extern s32 D_0035f3d4;
extern void* D_00361c0c;
extern s32 D_01e2bd10;
extern u8 D_003755a0[];
extern u8 D_003755a8[];
extern u8 D_003755c0[];
extern u8 D_003755c8[];
extern u8 D_003755e0[];
extern u8 D_003755e8[];
extern u8 D_003755f0[];
extern u8 D_00375598[];
extern s32 D_0037558c;
extern s32 D_00375590;
void func_002c4390(void);
void* func_00288be8(s32);
void func_002889f0(void*, s32, s32);
s32 func_002f1898(void);
u32 func_002c3268(u8*);
void func_0028b300(u8*, s32, s32, s32, u8*, u32, u8*, s32, s32);
void func_00139660(u8*);
void func_00139688(u8*);
s32 func_0023aa78(u8*);
s32 func_0023aa98(u8*);
s32 func_0023aa18(s32);
s32 func_0023aa38(s32);
void func_00138c68(u8*, s32, s32);
void func_002362b0(u8*, s32);
void func_002367c8(u8*);
u8* func_0028c2c8(s32, s32, s32, s32, s32);
void func_001396b0(u8*);
void func_0031ac78(u8*, s32);
void func_0031a260(u8*, s32);
void func_00288ce0(void*, u8*, s32, u8*, u8*);
void func_00139548(u8*);
void func_002891f0(void*, s32, s32, s32, s32);
void func_0028b078(void*, s32, s32);
void func_0028af90(void*, s32);
void func_00288f48(void*, s32, s32, s32, s32);
void func_0028d068(s32, s32);
void func_0028d1c0(u8*, s32, s32, s32, u8*, u8*, s32);
s32 func_002891d0(void*);
void func_0028d660(u8*, s32);
s32 func_002c2550(s32);
s32 func_0023f1b0(u8*);
s32 func_0023c4b8(s32, s32);
s32 func_00192048(s32);
void func_00138d60(u8*, s32, s32, s32, s32, s32, s32);
void func_001395e8(u8*);
void func_001395f8(u8*);
void func_00139620(u8*);
void func_0028bae0(u8*, s32, s32, s32, u8*, s32, s32, u8*, s32);
void func_00138c10(u8*, s32);
s32 func_002c2598(s32, s32);
u8 func_002c2688(s32, s32);
void func_001386e0(u8*, s32, s32, s32, s32, s32);


typedef struct Item44b8 Item44b8;
struct Item44b8 { u8 pad0[24]; u8 box[376]; s32 tex; u8 pad404[28]; };
typedef struct Ent44b8 Ent44b8;
struct Ent44b8 { u8 pad0[8]; s32 has; u8 pad12[4]; u8 obj[416]; u32 flags; u8 pad436[12]; };
typedef struct EntAt44b8 EntAt44b8;
// The same list entry seen from p (p + idx * 448): the original addresses it this way.
struct EntAt44b8 { u8 pad[8280]; s32 has; u8 pad2[420]; u32 flags; };
typedef struct Btn44b8 Btn44b8;
struct Btn44b8 { u8 pad[408]; };
typedef struct P44b8 P44b8;
struct P44b8 {
    u8 pad0[28];
    u8 lay[844];
    void* grid;
    u8 rec[444];
    Item44b8 items[8];
    Item44b8 items2[8];
    u8 pad8232[4];
    s32 f8236;
    u8 pad8240[8];
    s32 count;
    s32 n1;
    s32 n2;
    u8 pad8260[12];
    Ent44b8 ents[8];
    u8 pad11856x[11856 - 8272 - 8 * 448];
    s32 n;
    u8 pad11860[12];
    u8 pg[24];
    u8 pgb[412];
    u8 pad12308[52];
    void* lst;
    s32 pages;
    s32 shown;
    u8* slots[3];
    Btn44b8 btns[3];
    u8 pad13608[36];
    s32 f13644;
};
// Menu setup: lays out the item entries two per row (with optional second
// panel entries), then the record line, the page tabs and their buttons.
void func_002c44b8(P44b8* p)
{
    void* g;
    s32 h;
    s32 rows;
    s32 last;
    s32 sel;
    s32 vis;
    s32 first;
    s32 row;
    u8* lay;
    s32 hh;
    D_0035f3d4 = 30020;
    s32 idx = 0;
    g = func_00288be8(56);
    row = 0;
    func_002889f0(g, 8, 1);
    p->grid = g;
    h = func_002f1898();
    s32 n = p->n;
    p->n1 = 0;
    p->n2 = 0;
    last = p->count - 1;
    rows = (n + 1) / 2;
    first = n - 1;
    if (rows > 0) {
        lay = p->lay;
        do {
            s32 col = 0;
            do {
                EntAt44b8* e = (EntAt44b8*)((u8*)p + idx * 448);
                if (e->flags & 2) first = idx < first ? idx : first;
                if (e->has) {
                    sel = idx;
                    vis = 1;
                } else {
                    vis = 0;
                    sel = last;
                }
                func_0028b300((u8*)&p->items[p->n1], 30010, 1, 1, lay, func_002c3268((u8*)p), D_003755a0, 55, 0);
                Item44b8* it = &p->items[p->n1];
                s32 tex = it->tex;
                func_00139660((u8*)it);
                func_00139688((u8*)&p->items[p->n1]);
                u8* box = p->items[p->n1].box;
                hh = func_0023aa78(box);
                s32 x = col * func_0023aa98(box);
                x += func_0023aa18(tex);
                s32 y = func_0023aa38(tex);
                {
                    s32 off = row * hh;
                    s32 yy = off + y;
                    asm("" : "+r"(yy) : "r"(off));
                    func_00138c68((u8*)&p->items[p->n1], x, yy);
                }
                p->n1++;
                Ent44b8* e2 = &p->ents[idx];
                if (e2->flags & 1) {
                    func_0028b300((u8*)&p->items2[p->n2], 30030, 1, 1, lay, func_002c3268((u8*)p), D_003755a8, 56, 0);
                    Item44b8* it2 = &p->items[p->n2];
                    s32 tex2 = it2->tex;  // the original reads the first list here
                    func_00139660((u8*)&p->items2[p->n2]);
                    func_00139688((u8*)&p->items2[p->n2]);
                    u8* box2 = p->items2[p->n2].box;
                    hh = func_0023aa78(box2);
                    s32 x2 = col * func_0023aa98(box2);
                    x2 += func_0023aa18(tex2);
                    s32 y2 = func_0023aa38(tex2);
                    {
                        s32 off2 = row * hh;
                        s32 yy2 = off2 + y2;
                        asm("" : "+r"(yy2) : "r"(off2));
                        func_00138c68((u8*)&p->items2[p->n2], x2, yy2);
                    }
                    p->n2++;
                }
                u8* o = e2->obj;
                func_002362b0(o, p->ents[sel].has);
                func_002367c8(o);
                o[400] = 1;
                u8* v = func_0028c2c8(h, (s32)o, 11, -1, 0);
                *(u8**)(v + 400) = box;
                *(s32*)(v + 392) = 11;
                func_001396b0(v);
                if (*(s32*)(v + 400)) {
                    *(s32*)(v + 396) = 0;
                    func_001396b0(v);
                    if (*(s32*)(v + 396)) func_0031ac78(v, 0);
                }
                func_00139660(v);
                func_00139688(v);
                func_00288ce0(g, v, idx, D_003755c0, D_003755c8);
                if (!vis) func_00139548(v);
                idx++;
                if (idx == p->n) goto done;
                col++;
            } while (col < 2);
            row++;
        } while (row < rows);
    } else {
        lay = p->lay;
    }
done:
    func_002891f0(g, first, 1, 0, 2);
    u8* rec = p->rec;
    u8* pg = p->pg;
    u8* pgb = p->pgb;
    func_0028b078(g, 2, rows);
    func_0028af90(g, p->n);
    func_00288f48(g, 16, 32, 64, 128);
    func_0028d068(30040, -1);
    func_0028d1c0(rec, 30050, 1, 1, lay, D_00375598, 0);
    func_0028d660(rec, func_002891d0(g));
    func_001396b0(rec);
    func_00138c68(rec, func_0023aa98(p->items[0].box), 0);
    s32 k = func_002c2550(p->f8236);
    p->pages = k;
    p->shown = k < 4 ? k : 3;
    s32 res = func_0023c4b8(func_0023f1b0(lay), 1);
    func_00138d60(pg, 30032, res, p->f13644, 94, func_00192048(19478), 0);
    func_001395e8(pg);
    func_001395f8(pg);
    *(s32*)(pg + 432) = 2;
    func_00139620(pg);
    *(s32*)(pg + 424) = func_0023aa98(pgb) ? func_0023aa98(pgb) : 15;
    func_0028bae0((u8*)p + 12308, 30034, res, p->f13644, D_003755f0, p->pages, p->shown, pg, 0);
    func_00138c10(pg, 1);
    D_0035f3d4 = 30036;
    if (p->shown == 0) return;
    void* g2 = func_00288be8(56);
    func_002889f0(g2, p->shown, 1);
    p->lst = g2;
    D_00361c0c = g2;
    D_01e2bd10 = p->f8236;
    void* lst = p->lst;
    s32 i;
    for (i = 0; i < p->shown; i++) {
        s32 kind = 52;
        u8* v = func_0028c2c8(res, p->f13644, kind, -1, 0);
        p->slots[i] = v;
        *(s32*)(v + 392) = kind;
        *(u8**)(v + 396) = pg;
        func_001396b0(v);
        if (*(s32*)(v + 396)) {
            *(s32*)(v + 400) = 0;
            func_001396b0(v);
            if (*(s32*)(v + 400)) func_0031a260(v, 0);
        }
        func_00139660(v);
        func_001395f8(v);
        func_00139620(v);
        func_00138c68(v, 0, i * func_0023aa98(v + 24));
        *(s32*)(v + 408) = func_002c2598(p->f8236, i);
        *(void (**)(void))(v + 436) = func_002c4390;
        func_00288ce0(lst, v, i, D_003755e0, D_003755e8);
        s32 tex = func_002c2688(p->f8236, i) ? D_0037558c : D_00375590;
        u8* b = p->btns[i].pad;
        func_001386e0(b, 30038, res, p->f13644, tex, 0);
        *(u8**)(b + 396) = v;
        func_001396b0(b);
        if (*(s32*)(b + 396)) {
            *(s32*)(b + 400) = 0;
            func_001396b0(b);
            if (*(s32*)(b + 400)) func_0031a260(b, 0);
        }
        func_001396b0(p->btns[i].pad);
    }
    func_002891f0(lst, 0, 1, 0, 2);
    if (p->pages < 4) func_0028af90(lst, p->pages);
    else func_0028af90(lst, p->pages - 2);
    func_00288f48(lst, 16, 32, 64, 128);
}

