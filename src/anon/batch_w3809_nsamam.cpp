// Menu/list setup: builds 9 rows (labels, boxes, icons) then positions the cursor/top of the list.
// Partial inline asm: an s3 placeholder register (ph) live across loop 2 and a pinned move to $4 for one call argument.
#include "../common/types.h"
struct Node { u8 pad[392]; s32 f392; u8 pad2[40]; void (*cb)(void); };
struct Cfg { u8 pad[4]; s8 count; };
extern "C" {
extern u8 D_0035f128;
extern s8 D_0035f129;
extern u32 D_0035ef64, D_0035ef68, D_0035ef6c, D_0035f03c;
extern s32 D_0035f3d4;
extern u16 D_01e21ec0[2][4];
extern void* D_0035f01c;
extern void* D_0035f04c;
extern Cfg* D_0035f12c;
u8* func_00257770(void);
void func_0028d068(s32, s32);
void func_0028f4d8(s32, s32, s32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32);
void func_00288d80(void*, s32, u32, u32, u32, s32, u16*, u16*);
Node* func_002891b8(void*, s32);
void func_00138c10(void*, u32);
s32 func_0023aa78(void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_00288e08(void*, s32, s32, s32);
void func_00139620(void*);
void func_0028dcc0(void*, void*);
s32 func_00257140(s32);
void func_001395f8(void*);
void func_00138c68(void*, s32, s32);
void func_00272f48(void);
s32 func_00257070(s32);
s32 func_00257088(s32);
void* func_0023f1b0(u32);
s32 func_0023c4b8(void*, u32);
s32 func_00236ca8(u32, u32);
s32 func_002570f0(void);
void func_0028bae0(void*, s32, s32, s32, s32, s32, s32, u8*, s32);
void func_0028af90(void*, s32);
s32 func_002892f8(void*);
void func_002891f0(void*, s32, s32, s32, s32);
void func_0028afd0(void*, s32);
void func_0028b218(void*, s32);
void func_0028b248(void*, s32);
s32 func_0028b040(void*);
s32 func_00272b60(s32);
void func_0028af40(void*, s32);
u32 func_0028af88(void*);
void func_0028af18(void*, u32);
void func_002713c8(void);
void func_00272ae0(void);
void func_00271ee8(void);
s32 func_00283ab8(s32);
void func_00256cc0(s32, s32, s32);
void func_00287cc0(s32);

void func_0026f388(void) {
    s32 id;
    s32 h;
    u8* w = func_00257770();
    s32 i, j;
    D_0035f128 = 0;
    D_0035f129 = -1;
    func_0028d068(30021, 0);
    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++) D_01e21ec0[i][j] = D_0035ef6c;
    func_0028f4d8(1, -1, 0);
    u32 va = D_0035ef68;
    u32 vb = D_0035ef64;
    u32 vc = D_0035f03c;
    id = D_0035f3d4;
    func_0028d8c0(w, id++, va, vb, vc, 227, 228, 0);
    u8* box = w + 34768;
    s32 id1 = id + 1;
    s32 id2 = id + 2;
    u8* lab = w + 24304;
    for (i = 0; i < 9;) {
        u32 lb = D_0035ef64;
        asm("" : "+r"(lb));
        func_00288d80(D_0035f01c, i, D_0035ef68, lb, D_0035f03c, -1, D_01e21ec0[0], D_01e21ec0[1]);
        Node* n = func_002891b8(D_0035f01c, i);
        func_00138c10(n, 264);
        h = func_0023aa78((u8*)n + 24);
        asm("" : "+r"(h));
        s32 x = func_0023aa18((u8*)n + 24);
        s32 y = func_0023aa38((u8*)n + 24);
        func_00288e08(D_0035f01c, i, 0, h);
        i++;
        func_00139620(n);
        func_00138c10(n, D_0035ef6c);
        n->f392 = -1;
        n->cb = func_00272f48;
        func_0028dcc0(n, w);
        func_0028d980(lab, id1, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -1, -1, 0);
        func_0028dcc0(lab, n);
        func_00139620(lab);
        func_001395f8(lab);
        lab += 436;
        { u32 c3c = D_0035f03c; u32 c64 = D_0035ef64; asm volatile(""); u32 c6c = D_0035ef6c;
register u8* ra0 asm("$4"); asm volatile("move %0,%1" : "=r"(ra0) : "r"(box));
        func_0028d8c0(ra0, id2, D_0035ef68, c64, c3c, c6c, -1, 0);
        }
        func_0028dcc0(box, n);
        func_00138c68(box, x, y);
        box += 408;
    }
    u8* p = w;
    register s32 ph asm("$19"); asm("" : "=r"(ph));
    for (i = 0; i < 9;) {
        u8* e = p + 3376;
        func_0028d980(e, id, D_0035ef68, D_0035ef64, D_0035f03c, 282, -1, -1, 0);
        func_00138c68(e, 0, func_0023aa78(p + 3400) * i);
        func_00138c10(e, D_0035ef6c);
        func_001395f8(e);
        func_0028dcc0(e, w);
        *(s32*)(p + 3808) = 2;
        i++;
        p += 436;
    }
    s32 cnt = D_0035f12c->count;
    if (func_00257070(25)) cnt++;
    s32 a = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    s32 b = func_00236ca8(*(u32*)((u8*)func_0023f1b0(D_0035f03c) + 40), D_0035ef64);
    s32 vis = cnt < 10 ? cnt : 9;
    func_0028bae0(D_0035f04c, id, a, b, func_002570f0(), cnt, vis, w, 0);
    func_0028af90(D_0035f01c, cnt);
    s32 cur = func_00257070(26);
    s32 top = func_00257088(26);
    s32 rows = func_002892f8(D_0035f01c);
    s32 abs = cur + top;
        asm("" :: "r"(ph));
    if (abs >= cnt || cnt < top + rows) {
        while (top > 0) {
            if (cnt >= top + rows) break;
            top--;
        }
        cur = abs - top;
        if (cur < 0) cur = 0;
        if (cur >= rows) cur = rows - 1;
        if (cur + top >= cnt) {
            top = 0;
            cur = 0;
        }
    }
    func_002891f0(D_0035f01c, cur, 0, -1, -1);
    func_0028afd0(D_0035f01c, top);
    func_0028b218(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 9);
    s32 k = func_00272b60(func_0028b040(D_0035f01c));
    if (k) func_0028af40(D_0035f01c, 512);
    h = -1;
    { register u32 f asm("$2") = func_0028af88(D_0035f01c) | 0xc000; asm("" : "+r"(f)); func_0028af18(D_0035f01c, f); }
    func_002713c8();
    func_00272ae0();
    func_00271ee8();
    if ((k == 2 && func_00283ab8(0)) || (k == 1 && func_00283ab8(1))) {
        h = 0xcbdd;
        { register u32 f asm("$2") = func_0028af88(D_0035f01c) | 0x400; asm("" : "+r"(f)); func_0028af18(D_0035f01c, f); }
    }
    func_00256cc0(0xb61a, h, -1);
    func_00287cc0(0);
}
}
