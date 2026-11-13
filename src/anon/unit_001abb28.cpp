// YS windows (0x1abb28-0x1ad990): the small window parts (text line, cursor, page arrow, icon,
// position helpers), the window base (YS::WINDOW: ctor C2/C1, dtor D2/D0, on a priority-sorted
// list at 0x1c6ced0), YS::WINDOW_OBJ2D, the menu/tutorial windows built on them, and the list's
// static init. Each matched function keeps the struct view it was matched with (one namespace per
// view); every symbol is bound by asm label. The vtables stay retail data.
#include "../common/types.h"

struct WList { void* head; void* tail; WList() { tail = 0; head = 0; } };
static WList D_01c6ced0 asm("D_01c6ced0");  // all windows, sorted by priority (+120), link at +124

namespace c {  // common callees
void func_00239700(void*) asm("func_00239700");
u32 func_001ab810(void) asm("func_001ab810");
u32 func_001ab800(void) asm("func_001ab800");
void func_00239988(void*, u32, u32) asm("func_00239988");
void func_00239bf8(void*, u32) asm("func_00239bf8");
s32 func_00239d10(void*) asm("func_00239d10");
void func_0023acd8(void*) asm("func_0023acd8");
void func_0023ade0(void*) asm("func_0023ade0");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
}

namespace w24 {
void func_00239700(u32*) asm("func_00239700");
s32 func_001ab810(void) asm("func_001ab810");
s32 func_001ab800(void) asm("func_001ab800");
void func_00239988(u32*, s32, s32) asm("func_00239988");
void func_001abb28(u32* p) asm("func_001abb28");
void func_001abb28(u32* p) {
    p[0] = 0;
    func_00239700(p + 5);
    s32 a = func_001ab810();
    s32 b = func_001ab800();
    func_00239988(p + 5, a, b);
}
}

namespace tw1 {
u32 func_00239bf8(u32, u32, u32, u32) asm("func_00239bf8");
u32 func_001abb78(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001abb78");
u32 func_001abb78(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 4u) = (u32)(0x00000000u);
    *(u32*)((u32)(a0) + 0u) = (u32)(0x00000001u);
    return func_00239bf8(((u32)(a0) + 20u), 0x00000001u, a2, a3);
}
}

namespace w1745 {
struct Inner_1abba8 { u8 pad[0x148]; s32 a; s32 b; };
struct A_1abba8 { u32 pad[3]; s32 c; s32 d; Inner_1abba8 in; };
void func_0023acd8(void*) asm("func_0023acd8");
void func_0023ade0(void*) asm("func_0023ade0");
void func_001abba8(A_1abba8* a) asm("func_001abba8");
void func_001abba8(A_1abba8* a) {
    Inner_1abba8* s = &a->in;
    func_0023acd8(s);
    s32 c = a->c;
    s32 d = a->d;
    s->a = c;
    s->b = d;
    func_0023ade0(s);
}
}

namespace w99 {
struct S1abb { s32 state; s32 cur; u32 w8; u8 pad[8]; u8 sub[4]; };
struct Pad1abb { u64 d0; u64 trig; };
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
void func_00239bf8(u8*, s32) asm("func_00239bf8");
s32 func_00239d10(u8*) asm("func_00239d10");
void func_001991a8(u32, s32) asm("func_001991a8");
void func_001ac728(u8*) asm("func_001ac728");
void func_001abbf0(S1abb* s, u8* q, Pad1abb* pad) asm("func_001abbf0");
void func_001abbf0(S1abb* s, u8* q, Pad1abb* pad)
{
    switch (s->state) {
    case 1: {
        u64 t = pad->trig;
        if (t & 4) {
            func_002ba2e8(2, 0);
            func_00239bf8(s->sub, 0);
            s->state = 2;
        } else if ((t & 0x10) && s->cur > 0) {
            func_002ba2e8(1, 0);
            s->cur--;
        } else if ((t & 0x20) && s->cur + 1 < *(s32*)(q + 44)) {
            func_002ba2e8(1, 0);
            s->cur++;
        }
        break;
    }
    case 2:
        if (!func_00239d10(s->sub)) {
            func_001991a8(s->w8, 0);
            func_001ac728(q);
            s->state = 0;
        }
        break;
    }
}
}

namespace gap1 {
// The part is on.
s32 func_001abd00(u32* p) asm("func_001abd00");
s32 func_001abd00(u32* p) { return p[0] != 0; }
}

namespace taq1 {
void func_001abd10(u32* p, u32 id, u32 a, u32 b, u32 c) asm("_Z16wtarget_001abd10jjjj");
void func_001abd10(u32* p, u32 id, u32 a, u32 b, u32 c) {
    if (p[1] == id) {
        p[2] = a;
        p[3] = b;
        p[4] = c;
    }
}
}

namespace w49 {
void func_00239700(u8*) asm("func_00239700");
void func_001abb28(u8*) asm("func_001abb28");
u32 func_001ab810(void) asm("func_001ab810");
u32 func_001ab800(void) asm("func_001ab800");
void func_00239988(u8*, u32, u32) asm("func_00239988");
void func_001abd30(u8* p) asm("func_001abd30");
void func_001abd30(u8* p) {
    *(u32*)p = 0;
    func_00239700(p + 4);
    func_001abb28(p + 348);
    u32 a = func_001ab810();
    func_00239988(p + 4, a, func_001ab800());
}
void func_001abd90(u8* p) asm("func_001abd90");
void func_001abd90(u8* p) {
    *(u32*)p = 0;
    func_00239700(p + 4);
    func_001abb28(p + 348);
    u32 x = func_001ab810();
    func_00239988(p + 4, x, func_001ab800());
}
}

namespace w32 {
void func_00239bf8(s32*, s32) asm("func_00239bf8");
void func_001abb78(u8*, s32) asm("func_001abb78");
void func_001abdf0(s32* p, s32 t) asm("func_001abdf0");
void func_001abdf0(s32* p, s32 t) {
    p[0] = t;
    switch (t) {
    case 0: break;
    case 1: func_00239bf8(p + 1, 65); break;
    case 2: func_001abb78((u8*)p + 348, 65); break;
    }
}
}

namespace taq2 {
void func_00239bf8(u32, u32) asm("func_00239bf8");
void func_001abe48(u32* a0) asm("_Z16ctarget_001abe48jjjj");
void func_001abe48(u32* a0) {
    if (a0[0] == 1u) {
        func_00239bf8((u32)(a0 + 1), 66);
    }
}
}

namespace w63 {
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
void func_001ac728(u32) asm("func_001ac728");
void func_001abbf0(u8*) asm("func_001abbf0");
void func_001abe80(s32* a0, u32 a1, u8* a2) asm("func_001abe80");
void func_001abe80(s32* a0, u32 a1, u8* a2) {
    switch (*a0) {
    case 0:
        break;
    case 1:
        if (*(u64*)(a2 + 8) & 0x40c) {
            func_002ba2e8(24, 0);
            func_001ac728(a1);
        }
        break;
    case 2:
        func_001abbf0((u8*)a0 + 348);
        break;
    }
}
}

namespace w19 {
u8 func_00239d10(void*) asm("func_00239d10");
u32 func_001abf00(s32* p) asm("func_001abf00");
u32 func_001abf00(s32* p) {
    if (*p == 1) return func_00239d10(p + 1);
    return 0;
}
}

namespace wcx1 {
void func_0023acd8(u8*) asm("func_0023acd8");
void func_0023ade0(u8*) asm("func_0023ade0");
void func_001abba8(u8*, u32, u32) asm("func_001abba8");
void func_001abf38(s32* p, u32 a, u32 b) asm("func_001abf38");
void func_001abf38(s32* p, u32 a, u32 b)
{
    u8* q = (u8*)p + 4;
    switch (p[0]) {
    case 0:
        break;
    case 1:
        func_0023acd8(q);
        *(u32*)(q + 328) = a;
        *(u32*)(q + 332) = b;
        func_0023ade0(q);
        break;
    case 2:
        func_001abba8((u8*)p + 348, a, b);
        break;
    }
}
}

namespace w25 {
void func_00239700(void*) asm("func_00239700");
u32 func_001ab810(void) asm("func_001ab810");
u32 func_001ab800(void) asm("func_001ab800");
void func_00239988(void*, u32, u32) asm("func_00239988");
void func_001abfd8(u8* o) asm("func_001abfd8");
void func_001abfd8(u8* o) {
    o[0] = 0;
    func_00239700(o + 4);
    u32 x = func_001ab810();
    u32 y = func_001ab800();
    func_00239988(o + 4, x, y);
}
}

namespace w26 {
void func_00239700(void*) asm("func_00239700");
void* func_001ab810(void) asm("func_001ab810");
void* font_get_image(void) asm("_ZN2YS4FONT8GetImageEv");
void func_00239988(void*, void*, void*) asm("func_00239988");
void func_001ac028(u8* p) asm("func_001ac028");
void func_001ac028(u8* p) {
    p[0] = 0;
    func_00239700(p + 4);
    void* a = func_001ab810();
    func_00239988(p + 4, a, font_get_image());
}
}

namespace w33 {
void func_00239bf8(u8*, u32) asm("func_00239bf8");
void wtarget_001ac078(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_001ac078jjjj");
void wtarget_001ac078(u32 a, u32 b, u32 c, u32 d) {
    u8* p = (u8*)a;
    p[0] = b;
    p[1] = c;
    p[2] = d;
    if (!b) return;
    u32 n = (b * 4 + c) * 2;
    n = (s32)d >= 4 ? n + 33 : n + 37;
    func_00239bf8(p + 4, n);
}
}

namespace taq3 {
void func_00239bf8(u32, u32) asm("func_00239bf8");
void func_001ac0d0(u8* a0) asm("func_001ac0d0");
void func_001ac0d0(u8* a0) {
    u8* p = a0 + 4;
    if (a0[0] != 0u) {
        func_00239bf8((u32)p, *(u32*)(p + 0x114) + 1u);
    }
}
}

namespace w89 {
struct W108 { u8 on; u8 b1; u8 mode : 8; };
extern f32 D_00350a58[4] asm("D_00350a58");
void func_0023acd8(u8*) asm("func_0023acd8");
void func_0023ade0(u8*) asm("func_0023ade0");
// Positions a child widget relative to (x, y) using the alignment mode.
void func_001ac108(W108* o, s32 x, s32 y, s32 w, s32 h) asm("func_001ac108");
void func_001ac108(W108* o, s32 x, s32 y, s32 w, s32 h) {
    if (!o->on) return;
    if (o->mode < 4) y -= h / 2;
    else y += h / 2;
    x += (s32)(w * D_00350a58[o->mode & 3]);
    u8* p = (u8*)o + 4;
    func_0023acd8(p);
    *(s32*)(p + 328) = x;
    *(s32*)(p + 332) = y;
    func_0023ade0(p);
}
}

namespace w20 {
s32 func_00239d10(u8*) asm("func_00239d10");
u32 func_001ac1d0(u8* p) asm("func_001ac1d0");
u32 func_001ac1d0(u8* p) {
    if (!p[0]) return 0;
    return func_00239d10(p + 4) != 0;
}
}

namespace w27 {
void func_00239700(void*) asm("func_00239700");
u32 func_001ab810(void) asm("func_001ab810");
u32 func_001ab800(void) asm("func_001ab800");
void func_00239988(void*, u32, u32) asm("func_00239988");
void func_001ac208(u32* p) asm("func_001ac208");
void func_001ac208(u32* p) {
    p[0] = 0;
    func_00239700(p + 3);
    u32 a = func_001ab810();
    u32 b = func_001ab800();
    func_00239988(p + 3, a, b);
}
}

namespace w28 {
void func_00239700(u8*) asm("func_00239700");
u32 func_001ab810(void) asm("func_001ab810");
u32 func_001ab800(void) asm("func_001ab800");
void func_00239988(u8*, u32, u32) asm("func_00239988");
void func_001ac258(u8* p) asm("func_001ac258");
void func_001ac258(u8* p) {
    *(u32*)p = 0;
    func_00239700(p + 12);
    u32 a = func_001ab810();
    func_00239988(p + 12, a, func_001ab800());
}
}

namespace w44a {
void func_00239bf8(u32*, u32) asm("func_00239bf8");
void wtarget_001ac2a8(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_001ac2a8jjjj");
void wtarget_001ac2a8(u32 a, u32 b, u32 c, u32 d) {
    u32* p = (u32*)a;
    if (b) func_00239bf8(p + 3, b + 1);
    p[0] = b;
    p[1] = c;
    p[2] = d;
}
}

namespace w48 {
void func_0023acd8(u8*) asm("func_0023acd8");
void func_0023ade0(u8*) asm("func_0023ade0");
void func_001ac310(u8* o) asm("func_001ac310");
void func_001ac310(u8* o) {
    if (*(u32*)o == 0) return;
    u8* s = o + 12;
    func_0023acd8(s);
    u32 a = *(u32*)(o + 4);
    u32 b = *(u32*)(o + 8);
    *(u32*)(s + 328) = a;
    *(u32*)(s + 332) = b;
    func_0023ade0(s);
}
}

// ---- YS::WINDOW base: ctor C2 0x1ac378 (list insert inlined), C1 0x1ac4c0 (calls the list's
// out-of-line insert 0x31fdb0), dtor D2 0x1ac5b8 (unlink inlined), D1 0x1ac630, D0 0x1ac660.
namespace w1879 {
struct Node { void* vt; s32 f4; s32 f8; u8 sub[0x58]; s32 f64; s32 pad68; s32 f6c; s32 f70; s32 f74; s32 f78; Node* next; s32 f80; };
struct List { Node* head; Node* tail; };
extern u8 D_00350c50[] asm("D_00350c50");
extern List D_01c6ced0 asm("D_01c6ced0");
s32 func_00192048(s32) asm("func_00192048");
void func_001a98e8(void*, s32, s32, s32, s32) asm("func_001a98e8");
s32 func_001a9808(s32, s32) asm("func_001a9808");
void func_0031fdb0(List*, Node*, Node*) asm("func_0031fdb0");
static inline Node* nextOf(Node* p) { return p ? p->next : D_01c6ced0.head; }
void func_001ac378(Node* self, s32 a1, s32 a2, s32 a3, s32 pri, s32 b4, s32 b8) asm("func_001ac378");
void func_001ac378(Node* self, s32 a1, s32 a2, s32 a3, s32 pri, s32 b4, s32 b8) {
    self->f4 = b4;
    self->f8 = b8;
    self->vt = D_00350c50;
    func_001a98e8(self->sub, a1, func_00192048(a3), 0, 0);
    self->f6c = func_001a9808(a2, -1);
    self->f64 = 3;
    self->f80 = a3;
    self->f70 = 0;
    self->f74 = 0;
    self->f78 = pri;
    Node* p = 0;
    Node* prev = 0;
    for (; (p = nextOf(p)) != 0; prev = p) {
        if (pri < p->f78) break;
    }
    if (prev == 0) {
        if (D_01c6ced0.head == 0) {
            D_01c6ced0.tail = self;
            D_01c6ced0.head = self;
            self->next = 0;
        } else {
            self->next = D_01c6ced0.head;
            D_01c6ced0.head = self;
        }
    } else if (prev == D_01c6ced0.tail) {
        prev->next = self;
        self->next = 0;
        D_01c6ced0.tail = self;
    } else {
        self->next = prev->next;
        prev->next = self;
    }
}
void func_001ac4c0(Node* self, s32 a1, s32 a2, s32 a3, s32 pri, s32 b4, s32 b8) asm("func_001ac4c0");
void func_001ac4c0(Node* self, s32 a1, s32 a2, s32 a3, s32 pri, s32 b4, s32 b8) {
    self->f4 = b4;
    self->f8 = b8;
    self->vt = D_00350c50;
    func_001a98e8(self->sub, a1, func_00192048(a3), 0, 0);
    self->f6c = func_001a9808(a2, -1);
    self->f64 = 3;
    self->f80 = a3;
    self->f70 = 0;
    self->f74 = 0;
    self->f78 = pri;
    Node* p = 0;
    Node* prev = 0;
    for (; (p = nextOf(p)) != 0; prev = p) {
        if (pri < p->f78) break;
    }
    func_0031fdb0(&D_01c6ced0, prev, self);
}
}

namespace w1521 {
struct W1521Node { void* vt; u8 pad[0x78]; W1521Node* next; };
struct W1521NodeList { W1521Node* first; W1521Node* cur; };
extern W1521NodeList D_01c6ced0 asm("D_01c6ced0");
extern u8 D_00350c50 asm("D_00350c50");
void func_001ac5b8(W1521Node* p) asm("func_001ac5b8");
void func_001ac5b8(W1521Node* p) {
    W1521Node* prev;
    p->vt = &D_00350c50;
    if (p == D_01c6ced0.first) {
        prev = 0;
        D_01c6ced0.first = p->next;
    } else {
        W1521Node* q; W1521Node* n;
        prev = D_01c6ced0.first;
        q = prev->next;
        if (q != p) {
            do { n = q->next; prev = q; q = n; } while (n != p);
        }
        prev->next = p->next;
    }
    if (p == D_01c6ced0.cur) D_01c6ced0.cur = prev;
    p->next = 0;
}
}

namespace w17 {
extern u32 D_00350c50 asm("D_00350c50");
extern u8 D_01c6ced0 asm("D_01c6ced0");
void func_0031fe00(void*, void*) asm("func_0031fe00");
void func_00105110(void*) asm("_ZN4AREA4FreeEPv");
void func_001ac630(void** p) asm("func_001ac630");
struct NoTail { ~NoTail() {} };
void func_001ac630(void** p) {
    NoTail keep_frame;
    *p = &D_00350c50;
    func_0031fe00(&D_01c6ced0, p);
}
void func_001ac660(void** p) asm("func_001ac660");
void func_001ac660(void** p) {
    *p = &D_00350c50;
    func_0031fe00(&D_01c6ced0, p);
    func_00105110(p);
}
}

namespace ta80 {
typedef void (*VF)(u32, u32, u32, u32);
void func_001ac6a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001ac6a0");
void func_001ac6a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a0 != 0u) {
        (*(VF*)(*(u32*)a0 + 8))(a0, a1, a2, a3);
    }
}
}

namespace tw2 {
u32 func_001a9ae8(u32, u32, u32, u32) asm("func_001a9ae8");
u32 func_001ac6d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001ac6d0");
u32 func_001ac6d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001a9ae8(((u32)(a0) + 12u), ((u32)(*(u32*)((u32)(a0) + 4u))), ((u32)(*(u32*)((u32)(a0) + 8u))), ((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 108u)))) + 0u))));
}
}

namespace w11 {
void func_001991a8(s32, u32) asm("func_001991a8");
struct P1ac { u8 pad[112]; s32 st; u8 pad2[12]; u32 id; };
void func_001ac700(P1ac* p) asm("func_001ac700");
void func_001ac700(P1ac* p) {
    p->st = 4;
    func_001991a8(34, p->id);
}
}

namespace taq4 {
u32 func_001aa688(u32) asm("func_001aa688");
// YS::MESSAGEDRAW::next_page
void func_001ac728(u32 a0) asm("func_001ac728");
void func_001ac728(u32 a0) {
    u32* p = (u32*)a0;
    if (func_001aa688((u32)(p + 3)) != 0u) {
        p[0x1C] = 1;
        return;
    }
    ((void (*)(u32))(*(u32*)p[0]))(a0);
}
}

namespace w1 {
void func_001ac778(void) asm("func_001ac778");
void func_001ac778(void) {
    D_01c6ced0.tail = 0;
    D_01c6ced0.head = 0;
}
}

// ---- YS::WINDOW_OBJ2D ctor C2 0x1ac790 / C1 0x1ac7c8
namespace obj2d {
u32 func_001391c8(u32, u32, u32, u32) asm("func_001391c8");
extern u8 D_00350c30 asm("D_00350c30");
u32 func_001ac790(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001ac790");
u32 func_001ac790(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 24u) = (u32)(a1);
    *(u32*)((u32)(a0) + 12u) = (u32)(0x00000000u);
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00350c30);
    return func_001391c8(a0, ((u32)(((u32)(*(u32*)((u32)(a1) + 120u)))) + 25000u), 0x00000000u, a3);
}
u32 func_001ac7c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS12WINDOW_OBJ2DC1EPNS_6WINDOWE");
u32 func_001ac7c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 24u) = (u32)(a1);
    *(u32*)((u32)(a0) + 12u) = (u32)(0x00000000u);
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00350c30);
    return func_001391c8(a0, ((u32)(((u32)(*(u32*)((u32)(a1) + 120u)))) + 25000u), 0x00000000u, a3);
}
// Run the window's step, then its own step once the window reached state 7.
struct W;
struct WVt { void* f[5]; void (*step)(W*); };
struct W { WVt* vt; u8 pad[108]; s32 state; };
struct O { WVt* vt; u8 pad[20]; W* win; };
void func_001ac800(O* o) asm("func_001ac800");
void func_001ac800(O* o) {
    o->win->vt->step(o->win);
    bool done = o->win->state == 7;
    if (done) o->vt->step((W*)o);
}
}

namespace w34 {
void func_001ac378(u8*, u32, u32, u32, u32, u32, u32) asm("func_001ac378");
void func_001aa668(u8*, u8*) asm("func_001aa668");
extern u8 D_00350bf0[] asm("D_00350bf0");
void func_001ac858(u8* p, u32 a) asm("func_001ac858");
void func_001ac858(u8* p, u32 a) {
    func_001ac378(p, 4, 3, a, 0, 256, 365);
    *(u32*)(p + 100) = 4;
    *(void**)p = D_00350bf0;
    func_001aa668(p + 12, p);
}
}

namespace w35 {
void func_001ac378(void*, u32, u32, u32, u32, u32, u32) asm("func_001ac378");
void func_001aa668(void*, void*) asm("func_001aa668");
extern u8 D_00350bf0[] asm("D_00350bf0");
void func_001ac8b0(u8* p, u32 a1) asm("func_001ac8b0");
void func_001ac8b0(u8* p, u32 a1) {
    func_001ac378(p, 4, 3, a1, 0, 256, 365);
    *(u32*)(p + 100) = 4;
    *(void**)p = D_00350bf0;
    func_001aa668(p + 12, p);
}
}

namespace a80 {
void func_001ac728(u32) asm("func_001ac728");
void func_001ac908(u32* a0) asm("func_001ac908");
void func_001ac908(u32* a0) {
    s32 t6 = (s32)a0[28];
    if (t6 == 1) goto L_state1;
    if (t6 < 2) {
        if (t6 == 0) {
            a0[28] = 1;
        }
        return;
    }
    if (t6 == 4) {
        a0[28] = 7;
    }
    return;

L_state1:
    u32 t7 = a0[3];
    t7 = t7 & 1;
    t7 = (u8)t7;
    if (t7 == 0) {
        return;
    }
    func_001ac728((u32)a0);
}
}

namespace w96 {
void func_001ac378(u32, u32, u32, u32, u32, u32, u32) asm("func_001ac378");
void func_002395b8(u32) asm("func_002395b8");
void func_001abd90(u32) asm("func_001abd90");
void func_001ac028(u32) asm("func_001ac028");
void func_00239700(u32) asm("func_00239700");
u32 func_001ab810(void) asm("func_001ab810");
u32 func_001ab800(void) asm("func_001ab800");
void func_00239988(u32, u32, u32) asm("func_00239988");
void func_00239bf8(u32, u32) asm("func_00239bf8");
void func_001aa668(u32, u32) asm("func_001aa668");
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
struct Rgb_w96 { u8 c[3]; };
extern Rgb_w96 D_00350a38[] asm("D_00350a38");
// Constructor: base init, vtables, four child panels, colour from a kind table.
void func_001ac970(u32 self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 kind) asm("func_001ac970");
void func_001ac970(u32 self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 kind) {
    u32 p;
    func_001ac378(self, a1, a2, a3, a4, a5, a6);
    *(u32*)self = (u32)D_00350bb0;
    func_002395b8(self + 132);
    *(u32*)(self + 476) = kind;
    *(u32*)(self + 132) = (u32)D_0034e8a8;
    func_001abd90(self + 480);
    *(u32*)(self + 1192) = 0;
    func_001ac028(self + 1196);
    p = self + 1544;
    for (s32 k = 3; k != -1; k--) {
        func_00239700(p);
        p += 344;
    }
    *(u32*)(self + 2920) = 0;
    {
        u32 a = func_001ab810();
        func_00239988(self + 132, a, func_001ab800());
    }
    func_00239bf8(self + 132, D_00350a38[*(u32*)(self + 476)].c[0]);
    for (s32 i = 0; i < 4; i++) {
        u32 a = func_001ab810();
        func_00239988(self + 1544 + i * 344, a, func_001ab800());
    }
    func_001aa668(self + 12, self);
}
}

namespace w97 {
void func_001ac378(u8*, u32, u32, u32, s32, u32, u32) asm("func_001ac378");
void func_002395b8(u8*) asm("func_002395b8");
void func_001abd90(u8*) asm("func_001abd90");
void func_001ac028(u8*) asm("func_001ac028");
void func_00239700(u8*) asm("func_00239700");
u32 func_001ab810(void) asm("func_001ab810");
u32 func_001ab800(void) asm("func_001ab800");
void func_00239988(u8*, u32, u32) asm("func_00239988");
void func_00239bf8(u8*, u8) asm("func_00239bf8");
void func_001aa668(u8*, u8*) asm("func_001aa668");
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
extern u8 D_00350a38[][3] asm("D_00350a38");
void func_001aca98(u8* p, u32 a1, u32 a2, u32 a3, s32 a4, u32 a5, u32 a6, u32 kind) asm("func_001aca98");
void func_001aca98(u8* p, u32 a1, u32 a2, u32 a3, s32 a4, u32 a5, u32 a6, u32 kind) {
    func_001ac378(p, a1, a2, a3, a4, a5, a6);
    *(u32*)p = (u32)D_00350bb0;
    func_002395b8(p + 132);
    *(u32*)(p + 476) = kind;
    *(u32*)(p + 132) = (u32)D_0034e8a8;
    func_001abd90(p + 480);
    *(u32*)(p + 1192) = 0;
    func_001ac028(p + 1196);
    {
        u8* e = p + 1544;
        s32 i = 3;
        do { func_00239700(e); i--; e += 344; } while (i != -1);
    }
    *(u32*)(p + 2920) = 0;
    {
        u32 x = func_001ab810();
        func_00239988(p + 132, x, func_001ab800());
    }
    func_00239bf8(p + 132, D_00350a38[*(u32*)(p + 476)][0]);
    for (s32 i = 0; i < 4; i++) {
        u32 x = func_001ab810();
        func_00239988(p + 1544 + i * 344, x, func_001ab800());
    }
    func_001aa668(p + 12, p);
}
}

namespace perm {
struct Sub;
struct SubVt { u8 pad[32]; void (*fn)(Sub*); };
struct Sub { SubVt* vt; u8 pad[108]; s32 state; };
struct Ent3 { u8 b0; u8 b1; u8 b2; };
struct Sub12 { u32 bit : 1; u8 pad[28]; s32 f32; };
struct T {
    u8 pad0[12];
    Sub12 s12;
    u8 pad1[(112 - 12) - (sizeof(Sub12))];
    s32 state;
    u8 pad2[132 - 116];
    u8 s132[476 - 132];
    s32 f476;
    u8 s480[1192 - 480];
    Sub* f1192;
    u8 s1196[4];
};
extern Ent3 D_00350a38[] asm("D_00350a38");
s32 func_00167f18(s32) asm("func_00167f18");
s32 func_00239d10(void*) asm("func_00239d10");
void func_00239bf8(void*, u32) asm("func_00239bf8");
void func_001aa558(void*) asm("func_001aa558");
void func_001abdf0(void*, s32) asm("func_001abdf0");
void func_001abe80(void*, T*, s32) asm("func_001abe80");
void func_001ac728(T*) asm("func_001ac728");
void func_001ac0d0(void*) asm("func_001ac0d0");
s32 func_001ac1d0(void*) asm("func_001ac1d0");
inline static u8 isEnd(Sub* s) { return s->state == 3; }
void func_001acbc0(T* t) asm("func_001acbc0");
void func_001acbc0(T* t)
{
    s32 r = func_00167f18(0);
    int new_var;
    switch (t->state)
    {
    case 0:
        if (func_00239d10(t->s132)) return;
        func_00239bf8(t->s132, D_00350a38[t->f476].b1);
        t->state = 1;
        break;
    case 1:
    {
        Sub12* q = &t->s12;
        if (!((u8)q->bit)) return;
        func_001aa558(q);
        if (t->f1192) func_001abdf0(t->s480, 0);
        else if (q->f32 > 0) func_001abdf0(t->s480, 2);
        else func_001abdf0(t->s480, 1);
        t->state = 2;
        break;
    }
    case 2:
    {
        Sub* s = t->f1192;
        new_var = 0 == s;
        if (new_var) {
            func_001abe80(t->s480, t, r);
            return;
        }
        if (isEnd(s)) {
            s->vt->fn(s);
            func_001ac728(t);
        }
        return;
    }
    case 3:
        return;
    case 4:
        func_001ac0d0(t->s1196);
        t->state = 5;
        break;
    case 5:
        if (func_001ac1d0(t->s1196)) return;
        func_00239bf8(t->s132, D_00350a38[t->f476].b2);
        t->state = 6;
        break;
    case 6:
        if (func_00239d10(t->s132)) return;
        t->state = 7;
        break;
    }
}
}

namespace flex {
u32 func_001abe48(u32, u32, u32, u32) asm("_Z16ctarget_001abe48jjjj");
u32 func_001acd78(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001acd78");
u32 func_001acd78(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r = func_001abe48(a0 + 480, a1, a2, a3);
    *(u32*)(a0 + 112) = 3;
    return r;
}
}

namespace tiny {
union BD_VALUE { s32 i; f32 f; void* p; u32 u; };
void func_001ac700(BD_VALUE*) asm("func_001ac700");
void func_001acda8(BD_VALUE* bd) asm("func_001acda8");
void func_001acda8(BD_VALUE* bd) { func_001ac700(bd); }
}

namespace wcx2 {
struct Obj41 { u8 pad[92]; u32 p92; u32 p96; u8 pad2[12]; s32 n112; u8 pad3[2920 - 116]; s32 n2920; };
u32 func_001ab800(void) asm("func_001ab800");
void func_00236788(u32) asm("func_00236788");
void func_002367a0(void) asm("func_002367a0");
void func_0023bc58(u8*, u32, u32) asm("func_0023bc58");
void func_0023acd8(u8*) asm("func_0023acd8");
void func_0023ade0(u8*) asm("func_0023ade0");
void func_001ac108(u8*, u32, u32, u32, u32) asm("func_001ac108");
void func_001ac6d0(Obj41*) asm("func_001ac6d0");
void func_001abf38(u8*, u32, u32) asm("func_001abf38");
void func_00239bf8(u8*, s32) asm("func_00239bf8");
void func_001acdc0(Obj41* o, u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_001acdc0");
void func_001acdc0(Obj41* o, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    func_00236788(func_001ab800());
    if (!e) e = o->p92;
    u8* s = (u8*)o + 132;
    func_0023bc58(s, e, o->p96);
    func_0023acd8(s);
    *(u32*)(s + 328) = a;
    *(u32*)(s + 332) = b;
    func_0023ade0(s);
    if (o->n112 > 0) func_001ac108((u8*)o + 1196, a, b, o->p92, o->p96);
    if ((u32)(o->n112 - 1) < 5) {
        func_001ac6d0(o);
        if (o->n112 >= 2) func_001abf38((u8*)o + 480, c, d);
        s32 i;
        for (i = 0; i < o->n2920; i++) {
            func_0023acd8((u8*)o + 1544 + i * 344);
            func_0023ade0((u8*)o + 1544 + i * 344);
        }
        for (i = o->n2920; i < 4; i++) func_00239bf8((u8*)o + 1544 + i * 344, 0);
        o->n2920 = 0;
    }
    func_001ab800();
    func_002367a0();
}
}

namespace w41 {
struct W41Rect { u32 f0, x, y; u8 pad[0x50]; u32 w, h, mode; };
void func_001acdc0(W41Rect*, u32, u32, u32, u32, u32) asm("func_001acdc0");
void func_001acf38(W41Rect* r) asm("func_001acf38");
void func_001acf38(W41Rect* r) {
    u32 dummy;  // dead store after the second call keeps it from being a tail call
    if (r->mode == 2) {
        func_001acdc0(r, r->x, r->y + r->h / 2, r->x + r->w / 2, r->y + r->h, 0);
        return;
    }
    func_001acdc0(r, r->x, r->y, r->x + r->w / 2, r->y + r->h / 2, 0);
    dummy = 0;
}
}

namespace w44b {
s32 func_00239bf8(void*, u32) asm("func_00239bf8");
struct B3 { u8 a, b, c; };
extern B3 D_00350a38[] asm("D_00350a38");
// Only the first arm is a tail call: the function falls off the end otherwise.
s32 func_001acfb0(u8* o, s32 n) asm("func_001acfb0");
s32 func_001acfb0(u8* o, s32 n) {
    if (n == *(s32*)(o + 476)) return;
    *(s32*)(o + 476) = n;
    if (*(u32*)(o + 112) == 0) return func_00239bf8(o + 132, D_00350a38[n].a);
    func_00239bf8(o + 132, D_00350a38[n].b);
}
}

namespace w42 {
void wtarget_00239bf8(void*, s32) asm("_Z16wtarget_00239bf8jjjj");
// Append an entry at a 4.4 fixed-point position.
struct E344 { u8 pad[328]; s32 x; s32 y; u8 pad2[8]; };
void func_001ad020(u8* p, s32 x, s32 y, s32 a3) asm("func_001ad020");
void func_001ad020(u8* p, s32 x, s32 y, s32 a3)
{
    E344* e = &((E344*)(p + 1544))[(*(s32*)(p + 2920))++];
    wtarget_00239bf8(e, a3 + 10);
    e->x = (x - 0x7000) >> 4;
    e->y = (y - 0x7300) >> 4;
}
}

namespace w217 {
extern u32 D_00350b70 asm("D_00350b70");
void func_001ac970(u32*, u32, u32, u32, u32, u32, u32, u32) asm("func_001ac970");
void func_001ad098(u32* t, u32 a1, u32 a2) asm("func_001ad098");
void func_001ad098(u32* t, u32 a1, u32 a2) {
    func_001ac970(t, 3, 5, a1, a2, 128, 104, 0);
    *(u32*)t = (u32)&D_00350b70;
    ((f32*)t)[26] = 1.0f;
}
void func_001ad0f8(u32* t, u32 a1, u32 a2) asm("func_001ad0f8");
void func_001ad0f8(u32* t, u32 a1, u32 a2) {
    func_001ac970(t, 3, 5, a1, a2, 128, 104, 0);
    *(u32*)t = (u32)&D_00350b70;
    ((f32*)t)[26] = 1.0f;
}
}

namespace w1764 {
struct W1764ObjB { s32 a, b, c; };
void* W1764_AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void func_001ad0f8(void*, s32, s32) asm("func_001ad0f8");
void func_001ad158(u8* a0, s32 a1, s32 a2, s32 a3) asm("func_001ad158");
void func_001ad158(u8* a0, s32 a1, s32 a2, s32 a3) {
    W1764ObjB* o = (W1764ObjB*)W1764_AREA_Alloc(0xb6c);
    func_001ad0f8(o, a3, 0);
    *(W1764ObjB**)(a0 + 0x4a8) = o;
    o->b = a1;
    o->c = a2;
}
}

namespace w54 {
void func_001ac970(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_001ac970");
extern u8 D_00350af0[] asm("D_00350af0");
void func_001ad1d0(u8* p, s32 a1) asm("func_001ad1d0");
void func_001ad1d0(u8* p, s32 a1) {
    func_001ac970(p, 3, 4, a1, 0, 256, 32, 3);
    *(s32*)(p + 104) = 0;
    *(s32*)(p + 100) = 2;
    *(void**)p = D_00350af0;
}
}

namespace w55 {
void func_001ac970(u8*, u32, u32, u32, u32, u32, u32, u32) asm("func_001ac970");
extern u8 D_00350af0[] asm("D_00350af0");
void func_001ad228(u8* p, u32 b) asm("func_001ad228");
void func_001ad228(u8* p, u32 b) {
    func_001ac970(p, 3, 4, b, 0, 256, 32, 3);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 100) = 2;
    *(u32*)p = (u32)D_00350af0;
}
}

namespace wcx3 {
extern u8 D_00350ab0[] asm("D_00350ab0");
void func_001ac970(u8*, s32, s32, u32, s32, s32, s32, s32) asm("func_001ac970");
void func_001ac258(u8*) asm("func_001ac258");
void func_00239700(u8*) asm("func_00239700");
void func_001a9970(u8*, s32) asm("func_001a9970");
void func_001ad280(u8* p, u32 a) asm("func_001ad280");
void func_001ad280(u8* p, u32 a)
{
    func_001ac970(p, 0, 6, a, 0, 256, 52, 4);
    *(void**)p = D_00350ab0;
    func_001ac258(p + 2924);
    u8* q = p + 3280;
    for (s32 k = 3; k != -1; k--) { func_00239700(q); q += 344; }
    func_001a9970(p + 12, 16);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 8) += *(u32*)(p + 96) >> 1;
}
void func_001ad330(u8* p, u32 a) asm("func_001ad330");
void func_001ad330(u8* p, u32 a)
{
    func_001ac970(p, 0, 6, a, 0, 256, 52, 4);
    *(void**)p = D_00350ab0;
    func_001ac258(p + 2924);
    u8* q = p + 3280;
    for (s32 k = 3; k != -1; k--) { func_00239700(q); q += 344; }
    func_001a9970(p + 12, 16);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 8) += *(u32*)(p + 96) >> 1;
}
}

namespace w29 {
void func_001acdc0(u32*, u32, u32, u32, u32, u32) asm("func_001acdc0");
void func_001ac310(u8*) asm("func_001ac310");
void func_001ad3e0(u32* p) asm("func_001ad3e0");
void func_001ad3e0(u32* p) {
    func_001acdc0(p, p[1], p[2], p[1] + (p[23] >> 1), p[2] + (p[24] >> 1), 432);
    func_001ac310((u8*)p + 2924);
}
}

namespace w43 {
void func_001ac970(u8*, u32, u32, u32, u32, u32, u32, u32) asm("func_001ac970");
extern void* D_00350b30[] asm("D_00350b30");
void func_001ac078(void*, s32, s32, s32) asm("_Z16wtarget_001ac078jjjj");
void func_001aa388(void*, u32) asm("func_001aa388");
void func_001ad430(u8* p, u32 a) asm("func_001ad430");
void func_001ad430(u8* p, u32 a) {
    func_001ac970(p, 3, 5, a, 0, 256, 336, 0);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 100) = 3;
    *(void***)p = D_00350b30;
    func_001ac078(p + 1196, 1, 1, 0);
    u8* q = p + 12;
    func_001aa388(q, *(u32*)(q + 12));
}
}

namespace w44c {
void func_001ac970(u8*, u32, u32, u32, u32, u32, u32, u32) asm("func_001ac970");
extern u8 D_00350b30[] asm("D_00350b30");
void func_001ac078(void*, s32, s32, s32) asm("_Z16wtarget_001ac078jjjj");
void func_001aa388(void*, u32) asm("func_001aa388");
void func_001ad4a8(u8* o, u32 a) asm("func_001ad4a8");
void func_001ad4a8(u8* o, u32 a) {
    func_001ac970(o, 3, 5, a, 0, 256, 336, 0);
    *(u32*)(o + 104) = 0;
    *(u32*)(o + 100) = 3;
    *(void**)o = D_00350b30;
    func_001ac078(o + 1196, 1, 1, 0);
    u8* b = o + 12;
    func_001aa388(b, *(u32*)(b + 12));
}
}

namespace w1769 {
void* func_001050d8(u32) asm("_ZN4AREA5AllocEj");
void func_001ad0f8(void*, s32, s32) asm("func_001ad0f8");
void func_001ac7c8(void*, void*) asm("_ZN2YS12WINDOW_OBJ2DC1EPNS_6WINDOWE");
void func_001ad520(u8* p, s32 a1, s32 a2, s32 a3) asm("func_001ad520");
void func_001ad520(u8* p, s32 a1, s32 a2, s32 a3) {
    u8* o = (u8*)func_001050d8(0xB6C);
    func_001ad0f8(o, a3, 0);
    func_001ac7c8(func_001050d8(0x1C), o);
    *(u8**)(p + 0x4A8) = o;
    *(s32*)(o + 4) = a1;
    *(s32*)(o + 8) = a2;
}
}

namespace w31 {
void func_001ad280(void*) asm("func_001ad280");
extern void* D_00350a70[] asm("D_00350a70");
extern u8 D_00350a56 asm("D_00350a56");
void func_001c1130(int) asm("func_001c1130");
void func_0014c9d8(int) asm("func_0014c9d8");
void func_001ad5a8(void** p) asm("func_001ad5a8");
void func_001ad5a8(void** p) {
    func_001ad280(p);
    *p = D_00350a70;
    D_00350a56 = 1;
    func_001c1130(12);
    func_0014c9d8(8);
}
}

namespace w32b {
void func_001ad280(void*) asm("func_001ad280");
void func_001c1130(s32) asm("func_001c1130");
void func_0014c9d8(s32) asm("func_0014c9d8");
extern u8 D_00350a70[] asm("D_00350a70");
extern u8 D_00350a56 asm("D_00350a56");
void func_001ad5f0(void** p) asm("func_001ad5f0");
void func_001ad5f0(void** p) {
    func_001ad280(p);
    p[0] = D_00350a70;
    D_00350a56 = 1;
    func_001c1130(12);
    func_0014c9d8(8);
}
}

namespace w87 {
typedef void (*VFn)(void*);
extern u8 D_00350a70[] asm("D_00350a70");
extern u8 D_00350ab0[] asm("D_00350ab0");
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_00350a56 asm("D_00350a56");
void func_001c11a8(s32) asm("func_001c11a8");
void func_0014c9f0(s32) asm("func_0014c9f0");
void func_00239870(void*) asm("func_00239870");
void func_0031e668(void*) asm("func_0031e668");
void func_001ac5b8(void*) asm("func_001ac5b8");
struct NoTail { ~NoTail() {} };
void func_001ad638(u8* p) asm("func_001ad638");
void func_001ad638(u8* p) {
    NoTail keep_frame;
    *(void**)p = D_00350a70;
    D_00350a56 = 0;
    func_001c11a8(12);
    func_0014c9f0(8);
    *(void**)p = D_00350ab0;
    if (p + 3280) {
        u8* e = p + 4656;
        u8* b = p + 3280;
        for (;;) {
            if (b == e) break;
            e -= 344;
            (**(VFn**)e)(e);
        }
    }
    func_00239870(p + 2936);
    *(void**)p = D_00350bb0;
    if (p + 1544) {
        u8* e = p + 2920;
        u8* b = p + 1544;
        for (;;) {
            if (b == e) break;
            e -= 344;
            (**(VFn**)e)(e);
        }
    }
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    func_0031e668(p + 132);
    func_001ac5b8(p);
}
}

namespace w88 {
typedef void (*Dtor)(u8*);
extern u8 D_00350a70[] asm("D_00350a70");
extern u8 D_00350ab0[] asm("D_00350ab0");
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_00350a56 asm("D_00350a56");
void func_001c11a8(s32) asm("func_001c11a8");
void func_0014c9f0(s32) asm("func_0014c9f0");
void func_00239870(void*) asm("func_00239870");
void func_0031e668(void*) asm("func_0031e668");
void func_001ac5b8(void*) asm("func_001ac5b8");
struct NoTail { ~NoTail() {} };
void func_001ad738(u8* o) asm("func_001ad738");
void func_001ad738(u8* o) {
    NoTail g;
    *(u32*)o = (u32)D_00350a70;
    D_00350a56 = 0;
    func_001c11a8(12);
    func_0014c9f0(8);
    *(u32*)o = (u32)D_00350ab0;
    if (o + 3280 != 0) {
        u8* e = o + 4656;
    l1:
        if (o + 3280 != e) { e -= 344; (**(Dtor**)e)(e); goto l1; }
    }
    func_00239870(o + 2936);
    *(u32*)o = (u32)D_00350bb0;
    if (o + 1544 != 0) {
        u8* e = o + 2920;
    l2:
        if (o + 1544 != e) { e -= 344; (**(Dtor**)e)(e); goto l2; }
    }
    func_00239870(o + 1200);
    func_00239870(o + 848);
    func_00239870(o + 484);
    func_0031e668(o + 132);
    func_001ac5b8(o);
}
}

namespace w80 {
struct U21_DObj;
struct U21_DObjVt { void (*dtor)(U21_DObj*); };
struct U21_DObj { U21_DObjVt* vt; u8 pad[340]; };
extern u8 D_00350ab0[] asm("D_00350ab0");
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_00350a70[] asm("D_00350a70");
extern u8 D_00350a56 asm("D_00350a56");
void func_00105110(void*) asm("_ZN4AREA4FreeEPv");
void func_00239870(u8*) asm("func_00239870");
void func_0031e668(u8*) asm("func_0031e668");
void func_001ac5b8(u8*) asm("func_001ac5b8");
void func_001c11a8(u32) asm("func_001c11a8");
void func_0014c9f0(u32) asm("func_0014c9f0");
#define U21_W80_DTOR_ARR(base, off, n) \
    if ((u32)(base) != (u32)-(off)) { \
        U21_DObj* e_ = (U21_DObj*)((base) + (off)) + (n); \
        U21_DObj* b_ = (U21_DObj*)((base) + (off)); \
        for (;;) { \
            if (b_ == e_) break; \
            e_--; \
            e_->vt->dtor(e_); \
        } \
    }
void func_001ad838(u8* o) asm("func_001ad838");
void func_001ad838(u8* o) {
    *(u8**)o = D_00350a70;
    D_00350a56 = 0;
    func_001c11a8(12);
    func_0014c9f0(8);
    *(u8**)o = D_00350ab0;
    U21_W80_DTOR_ARR(o, 3280, 4)
    func_00239870(o + 2936);
    *(u8**)o = D_00350bb0;
    U21_W80_DTOR_ARR(o, 1544, 4)
    func_00239870(o + 1200);
    func_00239870(o + 848);
    func_00239870(o + 484);
    func_0031e668(o + 132);
    func_001ac5b8(o);
    func_00105110(o);
}
}

namespace tiny2 {
extern u8 D_00350a56 asm("D_00350a56");
// YS::WINDOW_SYSTEM_TUTORIAL::IsOpen
u32 func_001ad938(void) asm("_ZN2YS22WINDOW_SYSTEM_TUTORIAL6IsOpenEv");
u32 func_001ad938(void) { return D_00350a56; }
}
