#include "../common/types.h"

// YS::ITEM (0x1a2a50-0x1a3a50): item use, counts and the item command list. Each function keeps
// the declarations of the source it was matched in (namespace iN); every external symbol is bound
// by asm label. Its data: two form/item u16 tables in .rodata (0x36d458) and the 32-byte command
// message buffer in .bss (0x1c6cac0).

static const u16 D_0036d458[8] = { 0x0000, 0x001a, 0x001b, 0x0233, 0x001f, 0x001d, 0x001e, 0x0000 };
static const u16 D_0036d468[6] = { 0x0015, 0x0016, 0x0017, 0x0018, 0x0057, 0x0058 };
static u8 D_01c6cac0[32];

// 001a2a50
namespace i0 {
void func_001a2b50(void*, s32, s32, s32) asm("func_001a2b50");
s32 func_001a3888(s32) asm("func_001a3888");
void* func_001a80c8(s32) asm("func_001a80c8");
void* func_001a8bd0(s32) asm("func_001a8bd0");
s32 func_001a8c10(void*, s32) asm("func_001a8c10");
s32 func_001a2a50(s32 id, s32 a, s32 b, s32 c) asm("func_001a2a50");
s32 func_001a2a50(s32 id, s32 a, s32 b, s32 c)
{
    s32 r = 0;
    void* w = func_001a80c8(id);  // table24_find_by_id
    if (!func_001a3888(id)) {  // id_in_range_5_7_131
        func_001a2b50(w, a, b, c);
        if (a != b) r = 1;
    } else {
        void* g = func_001a8bd0(-1);
        for (s32 i = 0; i < 4; i++) {
            a = func_001a8c10(g, i);
            if (a) {
                func_001a2b50(w, a, b, c);
                if (a != b) r = 1;
            }
        }
    }
    return r;
}
}  // namespace i0

// 001a2b50
namespace i1 {
struct W2040Req { u16 type; u16 pad; u16 val; };
struct W2040Unit { s32 f0; s32 f4; u8 pad[0x184 - 8]; s32 f184; };
W2040Unit* func_001a1658(s32, s32) asm("func_001a1658");
void func_001a17c8(W2040Unit*) asm("func_001a17c8");
void func_001a1950(W2040Unit*, s32, s32, s32) asm("func_001a1950");
void func_001a1a20(W2040Unit*, s32, s32) asm("func_001a1a20");
void func_001a1aa0(W2040Unit*, s32, s32) asm("func_001a1aa0");
void func_001a2578(W2040Unit*, s32, s32) asm("func_001a2578");
void func_001a25c8(W2040Unit*, s32, s32) asm("func_001a25c8");
void func_001a2618(W2040Unit*, s32, s32) asm("func_001a2618");
void func_001a2668(W2040Unit*, s32, s32) asm("func_001a2668");
void func_001a2b50(W2040Req* r, s32 id, s32 other, s32 pct) asm("func_001a2b50");
void func_001a2b50(W2040Req* r, s32 id, s32 other, s32 pct) {
    W2040Unit* o = func_001a1658(id, -1);
    s32 flag;
    s32 val;
    s32 a, b;
    if (o == 0) return;
    flag = 0;
    if (other != 0) flag = other != id;
    val = r->val;
    a = (o->f4 * val * pct + 9999) / 10000;
    b = (o->f184 * val * pct + 9999) / 10000;
    switch (r->type) {
    case 1: case 2: case 5:
        func_001a1950(o, a, 0, flag);
        break;
    case 3: case 6:
        func_001a1a20(o, b, flag);
        break;
    case 4: case 7:
        func_001a1950(o, a, 0, flag);
        func_001a1a20(o, b, 0);
        break;
    case 131:
        func_001a1950(o, o->f4, 0, flag);
        func_001a1a20(o, b, 0);
        break;
    case 274: case 275:
        func_001a1aa0(o, r->val * 100, flag);
        break;
    case 276:
        func_001a2578(o, val, flag);
        break;
    case 277:
        func_001a25c8(o, val, flag);
        break;
    case 278:
        func_001a2618(o, val, flag);
        break;
    case 279:
        func_001a2668(o, val, flag);
        break;
    }
    func_001a17c8(o);
}
}  // namespace i1

// 001a2d78
namespace i2 {
s32 func_001a2e50(void*, s32) asm("func_001a2e50");
s32 func_001a3888(s32) asm("func_001a3888");
void* func_001a80c8(s32) asm("func_001a80c8");
void* func_001a8bd0(s32) asm("func_001a8bd0");
s32 func_001a8c10(void*, s32) asm("func_001a8c10");
s32 func_001a2d78(s32 id, s32 a) asm("func_001a2d78");
s32 func_001a2d78(s32 id, s32 a)
{
    s32 r = 0;
    void* w = func_001a80c8(id);  // table24_find_by_id
    if (!func_001a3888(id)) {  // id_in_range_5_7_131
        r = func_001a2e50(w, a);
    } else {
        void* g = func_001a8bd0(-1);
        for (s32 i = 0; i < 4; i++) {
            a = func_001a8c10(g, i);
            if (a) r = r || func_001a2e50(w, a);
        }
    }
    return r;
}
}  // namespace i2

// 001a2e50
namespace i3 {
bool func_001a1de0(u8*) asm("_Z16u_call4_001a1de0jjjj");
static inline bool IsFullA(u8* p) { return *(s32*)(p + 0) >= *(s32*)(p + 4); }
static inline bool HasC(u8* p) { return p[433] < p[434]; }
static inline bool IsFullB(u8* p) { return !func_001a1de0(p) && *(s32*)(p + 384) >= *(s32*)(p + 388); }
u8* func_001a1658(s32, s32) asm("func_001a1658");
void func_001a17c8(u8*) asm("func_001a17c8");
bool func_001a2758(u8*) asm("func_001a2758");
bool func_001a2778(u8*) asm("func_001a2778");
bool func_001a2798(u8*) asm("func_001a2798");
bool func_001a27b8(u8*) asm("func_001a27b8");
bool func_001a2e50(u16* req, s32 id) asm("func_001a2e50");
bool func_001a2e50(u16* req, s32 id) {
    bool r = false;
    u8* p = func_001a1658(id, -1);  // state_dispatch_0_1_14
    if (!p) return false;
    switch (*req) {
    case 1: case 2: case 5:
        r = !IsFullA(p);
        break;
    case 3: case 6:
        r = !IsFullB(p);
        break;
    case 4: case 7: case 131:
        r = !(IsFullA(p) && IsFullB(p));
        break;
    case 274: case 275:
        r = HasC(p);
        break;
    case 276: r = !func_001a2758(p); break;
    case 277: r = !func_001a2778(p); break;
    case 278: r = !func_001a2798(p); break;
    case 279: r = !func_001a27b8(p); break;
    }
    func_001a17c8(p);
    return r;
}
}  // namespace i3

// 001a3018 (matched as C)
namespace i4 {
typedef struct { u8 pad[0x1090]; u8 tbl[0x140]; u32 bits[8]; } G3018;
typedef struct { u8 f0, f1, kind, flags; u8 pad[14]; u16 id; } P3018;
typedef struct { u8 pad[0x12]; u8 n; u8 pad2[0x21]; u16 a[8]; u16 b[8]; } Q3018;
extern G3018 D_0032e020 asm("D_0032e020");
Q3018* ctarget_00188fe0(G3018*, u32) asm("_Z16ctarget_00188fe0jjjj");
P3018* func_001a80c8(void) asm("func_001a80c8");
s32 ctarget_001a3018(u32 arg0, u32 arg1, u32 arg2, u32 arg3) asm("_Z16ctarget_001a3018jjjj");
s32 ctarget_001a3018(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
    P3018* p = func_001a80c8();
    G3018* g = &D_0032e020;
    u32 flags = p->flags;
    if ((flags & 1) == 1) {  // C++: a plain 'flags & 1' test keeps an extra andi 0xff
        u16 id = p->id;
        u32* bs = g->bits;
        if (bs[id >> 5] & (1 << (id & 31))) goto zero;
        if (arg2 == 1) return 100;
        goto zero;
    }
    if (arg1 != 100 && arg2 == 1) {
        Q3018* q = ctarget_00188fe0(g, arg1);
        if (q) {
            u8 t = p->kind;
            if (t != 0) {
                if (t == 19) return arg1;
            } else {
                s32 i;
                for (i = 0; i < q->n; i++) {
                    if (q->a[i] == 0) {
                        if (q->b[i] == arg0 || q->b[i] == 0) return arg1;
                    }
                }
            }
        }
    }
    if ((s32)(g->tbl[p->id] + arg2) < 100) return 100;
zero:
    return 0;
}
}  // namespace i4

// 001a3168: YS::ITEM::CanGet
namespace i5 {
u32 func_001a3018(u32, u32, u32, u32) asm("_Z16ctarget_001a3018jjjj");
u32 func_001a3168(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS4ITEM6CanGetEiii");
u32 func_001a3168(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001a3018(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace i5

// 001a3188
namespace i6 {
struct R3188 { u8 b0, b1, b2, b3; u8 pad[14]; u16 id; };
struct Bits3188 { u32 w[1]; void set(u32 i) { w[i >> 5] |= 1 << (i & 31); } };
struct S3188 { u8 pad[0x1898]; Bits3188 bits; };
extern S3188 D_0032e020 asm("D_0032e020");
void func_00188a28(void*, void*) asm("func_00188a28");
void func_00188b68(void*, void*, u8) asm("func_00188b68");
void* func_00188fe0(void*, s32) asm("func_00188fe0");
s32 func_001a3018(void*, s32, s32) asm("_Z16ctarget_001a3018jjjj");
void func_001a32c8(void*, s32) asm("func_001a32c8");
void func_001a39c8(void*) asm("func_001a39c8");
R3188* func_001a80c8(void*, s32) asm("func_001a80c8");
s32 func_001a3188(void* a0, s32 a1, u8 a2) asm("func_001a3188");
s32 func_001a3188(void* a0, s32 a1, u8 a2) {
    R3188* r = func_001a80c8(a0, a1);  // table24_find_by_id
    S3188* g = &D_0032e020;
    s32 n = func_001a3018(a0, a1, 1);
    u32 one = 1;
    if (n == 0) return 0;
    if (r->b3 & one) goto A;
    if (n == 100) {
A:
        func_001a32c8(a0, 1);
    } else {
        void* v = func_00188fe0(g, n);
        switch (r->b2) {
        case 0:
            func_00188a28(v, a0);
            if (n == 1 || n == 14) func_001a39c8(a0);
            break;
        case 19:
            func_00188b68(v, a0, a2);
            break;
        }
    }
    if (r->b3 & one) return 1;
    g->bits.set(r->id);
    return 1;
}
}  // namespace i6

// 001a32c8
namespace i7 {
typedef struct W1925_G1 { u8 pad[0x1090]; u8 cnt[0x140]; u32 bits[1]; } W1925_G1;
typedef struct W1925_G2s { u8 pad[8]; u16 slot[3]; } W1925_G2s;
typedef struct W1925_G2 { u8 pad[0x36f0]; W1925_G2s s; } W1925_G2;
typedef struct W1925_It { u8 pad[2]; u8 type; u8 flags; u8 pad2[0xc]; u16 v; u16 id; } W1925_It;
extern W1925_G2 D_0032bb30 asm("D_0032bb30");
extern W1925_G1 D_0032e020 asm("D_0032e020");
static inline bool W1925_isf(W1925_It* it) { return it->flags & 1; }
void func_001815d0(s32) asm("func_001815d0");
void func_00181670(void) asm("func_00181670");
void func_001a3168(s32, s32, s32) asm("_ZN2YS4ITEM6CanGetEiii");
void func_001a38b8(W1925_It*) asm("func_001a38b8");
void func_001a39c8(s32) asm("func_001a39c8");
W1925_It* func_001a80c8(s32) asm("func_001a80c8");
void func_001a32c8(s32 id, s32 n) asm("func_001a32c8");
void func_001a32c8(s32 id, s32 n)
{
    s32 had = 0;
    W1925_It* it = func_001a80c8(id);
    func_001a3168(id, 100, n);
    W1925_G1* g = &D_0032e020;
    if (W1925_isf(it)) {
        u16 k = it->id;
        u32* bits = g->bits;
        bits[k >> 5] |= 1 << (k & 0x1f);
    } else {
        had = g->cnt[it->id];
        g->cnt[it->id] += n;
    }
    if (id == 32) func_001815d0(-1);
    switch (it->type) {
    case 0: func_001a39c8(id); return;
    case 21: func_001a38b8(it); return;
    case 18:
        if (had == 0) {
            W1925_G2* g2 = &D_0032bb30;
            W1925_G2s* s = &g2->s;
            for (s32 i = 0; i < 3; i++) {
                if (s->slot[i] == 0) { s->slot[i] = it->v; break; }
            }
        }
        func_00181670();
        return;
    }
}
}  // namespace i7

// 001a3458: YS::ITEM::Reduce
namespace i8 {
void func_001a34e0(s32, s32) asm("func_001a34e0");
u8* func_00188fe0(void*) asm("func_00188fe0");
extern u8 D_0032e020[] asm("D_0032e020");
s32 YS_ITEM_Reduce(s32 a, s32 b) asm("_ZN2YS4ITEM6ReduceEii");
s32 YS_ITEM_Reduce(s32 a, s32 b) {
    if (b == 100) { func_001a34e0(a, 1); return 1; }
    u8* t = func_00188fe0(D_0032e020);
    s32 i;
    for (i = t[18] - 1; i >= 0; i--) {
        if (*(u16*)(t + 52 + i * 2) == a) { *(u16*)(t + 52 + i * 2) = 0; return 1; }
    }
    return 0;
}
}  // namespace i8

// 001a34e0
namespace i9 {
struct C34e0 { u8 v:8; };
typedef struct E34e0 { u8 b0, b1, b2, b3; u8 pad[0xe]; u16 h12; } E34e0;
extern u8 D_0032e020[] asm("D_0032e020");
E34e0* func_001a80c8(s32) asm("func_001a80c8");
void func_001a34e0(s32 a0, s32 a1) asm("func_001a34e0");
void func_001a34e0(s32 a0, s32 a1) {
    E34e0* e = func_001a80c8(a0);
    u8* base = D_0032e020;
    u32* bits = (u32*)(base + 0x11d0);
    s32 m = 1;
    if (e->b3 & m) {
        u32 i = e->h12;
        bits[i >> 5] &= ~(1 << (i & 31));
    } else {
        C34e0* c = (C34e0*)(base + e->h12 + 0x1090);
        if (a1 < c->v) c->v -= a1; else c->v = 0;
    }
}
}  // namespace i9

// 001a3570
namespace i10 {
extern u8 D_0032f1f0 asm("D_0032f1f0");
extern u8 D_0032bb30 asm("D_0032bb30");
u32 func_001a80c8(...) asm("func_001a80c8");
u32 func_001a3570(u32 a0) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
u32 func_001a3570(u32 a0) {
    u8* p = (u8*)func_001a80c8(a0);  // table24_find_by_id
    u32 out = 0;
    u32 f = p[3];
    f = f & 1;
    if (f != 0) {
        u32 idx = *(u16*)(p + 18);
        u32 bit = 1u << (idx & 31);
        u32 w = idx >> 5;
        u32 v = *(u32*)((&D_0032f1f0) + (w << 2));
        out = ((v & bit) != 0);
        return out;
    }

    u32 t = p[2];
    if (t == 19) {
        return out;
    }
    u32 idx = *(u16*)(p + 18);
    u8* b = (&D_0032bb30) + idx;
    out = b[13696];
    return out;
}
}  // namespace i10

// 001a35f8
namespace i11 {
struct W248Tbl { u8 pad[18]; u8 n; u8 pad2[33]; u16 a[16]; u16 b[80]; };
extern u8 D_0032e020[] asm("D_0032e020");
W248Tbl* func_00188fe0(void*) asm("func_00188fe0");
s32 func_001a3570(u32) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
u8* func_001a80c8(u32) asm("func_001a80c8");
s32 func_001a35f8(u32 id, s32 mode) asm("func_001a35f8");
s32 func_001a35f8(u32 id, s32 mode) {
    s32 cnt = 0;
    if (mode == 100) {
        cnt = func_001a3570(id);
    } else {
        W248Tbl* t = func_00188fe0(D_0032e020);
        switch (func_001a80c8(id)[2]) {  // table24_find_by_id
        case 0: {
            s32 i;
            for (i = 0; i < t->n; i++) {
                if (t->a[i] == id) cnt++;
            }
            break;
        }
        case 19: {
            s32 i;
            for (i = 0; i < 80; i++) {
                if ((t->b[i] & 0x7fff) == id) cnt++;
            }
            break;
        }
        default:
            cnt = func_001a3570(id);
            break;
        }
    }
    return cnt;
}
}  // namespace i11

// 001a36e0, 001a36f8
namespace i12 {
u32 func_001a36e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS4ITEM10FormToItemEi");
u32 func_001a36e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return D_0036d458[a0];
}

u32 func_001a36f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a36f8");
u32 func_001a36f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return D_0036d468[a0];
}
}  // namespace i12

// 001a3710 .. 001a3788
namespace i14 {
extern u8 D_0032e020 asm("D_0032e020");
u32 func_001a8bd0(...) asm("func_001a8bd0");
u32 func_001a8c10(...) asm("func_001a8c10");
u32 func_00188fe0(u32 a0, u32 a1) asm("func_00188fe0");
void func_00188ac8(u32 a0) asm("func_00188ac8");
u8* func_001a80c8(u32) asm("func_001a80c8");
u32 func_00192048(...) asm("func_00192048");
u32 func_00192c90(u32 a0, u32 a1) asm("func_00192c90");

void func_001a3710() asm("_ZN2YS4ITEM8RechargeEv");
void func_001a3710() {
    s32 s0 = 0;
    u32 s1 = func_001a8bd0(0xffffffff);
    do {
        u32 v = func_001a8c10(s1, s0);
        s0 = s0 + 1;
        u32 p = func_00188fe0((u32)&D_0032e020, v);
        if (p) {
            func_00188ac8(p);
        }
    } while (s0 < 4);
}

u32 func_001a3788(u8* a0, u32 a1, s32 a2) asm("_Z16ctarget_001a3788jjjj");
u32 func_001a3788(u8* a0, u32 a1, s32 a2) {
    u8* s1 = a0;
    s32 s0 = a2;
    u8* p = func_001a80c8(a1);  // table24_find_by_id
    if (s0 < 0) {
        s0 = p[23];
    }
    s1[1] = (u8)s0;
    s1[0] = 9;
    u32 r = func_00192048(*(u16*)(p + 8));
    u32 r2 = func_00192c90(r, (u32)(s1 + 2));
    return r2 + 2;
}
}  // namespace i14

// 001a37e8
namespace i16 {
u32 func_001a3788(u32, u32, u32, u32) asm("_Z16ctarget_001a3788jjjj");
u32 func_001a37e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a37e8");
u32 func_001a37e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r6 = r5;
    r5 = r4;
    r16 = (u32)&D_01c6cac0;
    r4 = r16;
    r2 = func_001a3788(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace i16

// 001a3820
namespace i17 {
u8* func_001a80c8(void) asm("func_001a80c8");  // table24_find_by_id
s32 func_001a67b0(u32) asm("func_001a67b0");
s32 func_001a3820(void) asm("func_001a3820");
s32 func_001a3820(void) {
    u8* r = func_001a80c8();  // table24_find_by_id
    switch (r[2]) {
    case 0: return *(u16*)(r + 16);
    case 18: return func_001a67b0(*(u16*)(r + 4));
    }
    return 0;
}
}  // namespace i17

// 001a3868: YS::ITEM::GetCommandElem
namespace i18 {
u8* func_001a80c8(s32) asm("func_001a80c8");  // table24_find_by_id
void func_001b8e88(u32) asm("func_001b8e88");
void GetCommandElem(s32 id) asm("_ZN2YS4ITEM14GetCommandElemEi");
void GetCommandElem(s32 id) {
    func_001b8e88(*(u16*)(func_001a80c8(id) + 16));
}
}  // namespace i18

// 001a3888
namespace i19 {
u32 func_001a3888(s32 a0) asm("func_001a3888");
u32 func_001a3888(s32 a0) {  // id_in_range_5_7_131
    if (a0 < 5) {
        goto L_zero;
    }
    if (a0 < 8) {
        goto L_one;
    }
    if (a0 != 131) {
        goto L_zero;
    }
L_one:
    return 1;
L_zero:
    return 0;
}
}  // namespace i19

// 001a38b8
namespace i20 {
struct W2368Ent { u16 v; u16 pad; s32 f4; };
struct W2368Info { u8 pad[4]; s16 kind; };
struct W2368Arg { u8 pad[0x10]; u16 id; };
extern u8 D_0032e020 asm("D_0032e020");
W2368Ent* func_00189200(void*, s32) asm("func_00189200");
W2368Info* func_001b8e88(u16) asm("func_001b8e88");
u16 func_001a3958(s32) asm("func_001a3958");
void func_001a38b8(W2368Arg* a) asm("func_001a38b8");
void func_001a38b8(W2368Arg* a) {
    W2368Ent* e = func_00189200(&D_0032e020, 6);
    e->f4 = 0;
    s16 k = func_001b8e88(a->id)->kind;
    switch (k) {
    case 1: case 4: case 5:
        e = func_00189200(&D_0032e020, k);
        if (e->v == 0) e->v = func_001a3958(2);
        break;
    }
}
}  // namespace i20

// 001a3958
namespace i21 {
s32 has_ansem_entry(u32) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
u8* item_each(void*) asm("_ZN2YS10ITEM_TABLE4EachEPKS0_");
void func_001a34e0(u32, s32) asm("func_001a34e0");
u32 func_001a3958(u32 kind) asm("func_001a3958");
u32 func_001a3958(u32 kind)
{
    u8* it = 0;
    while ((it = item_each(it)) != 0) {
        if (it[2] == kind && has_ansem_entry(*(u16*)it) > 0) {
            func_001a34e0(*(u16*)it, 1);
            return *(u16*)it;
        }
    }
    return 0;
}
}  // namespace i21

// 001a39c8
namespace i22 {
typedef struct SS
{
  u8 p[8];
  u16 a[8];
  u8 q[6];
  u16 z;
} SS;
typedef struct SA
{
  u8 pad[0x11f0];
  SS s;
} SA;
extern SA D_0032e020 asm("D_0032e020");
u16 func_001a3820(void) asm("func_001a3820");
void func_001a39c8(s32 v) asm("func_001a39c8");
void func_001a39c8(s32 v)
{
  SA *d = &D_0032e020;
  u16 *p;
  SS *new_var;
  s32 i;
  if ((d->s.a[0] == 0) && (d->s.z == 0))
  {
    d->s.z = func_001a3820();
  }
  new_var = &d->s;
  if (p)
  {
    p = (u16 *) (&d->s);
  }
  else
  {
    p = (u16 *) new_var;
  }
  for (i = 0; i < 8; i++, p++)
  {
    u16 x = p[4];
    if (x == 0)
    {
      p[4] = v;
      return;
    }
    if (x == v)
    {
      return;
    }
  }

}
}  // namespace i22
