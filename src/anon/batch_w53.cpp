#include "../common/types.h"

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// Local with a non-trivial destructor: keeps the final call a jal instead of a sibcall.
struct NoTail { ~NoTail() {} };

struct Slot88 { u32 f0; u32 key; u32 pad8[2]; u32 f16; u8 pad20[60]; u32 f80; u32 f84; };
struct Node12 { u32 pad[3]; Node12* next; };
struct Pair { u32 a; u32 b; };
struct S349 { u8 pad[736]; u8 a[16]; u8 b[480]; u8 c; };
struct E16 { u32 a; u32 b; u32 c; u8* obj; };

typedef void (*Fn0)(u8*);
typedef void (*Fn1)(void*, void*);
typedef void (*Fn3)(u32, u32, u32);
typedef u32 (*Fn8)(u8*, u32, u32, u32, u32, u32, u8, u32);
typedef void* (*AllocFn)(void*, u32, u32);
typedef void (*VFn)(u8*);
typedef void (*VFn0)(void);
struct Blk { Blk* next; s32 n; VFn0 fns[1]; };

extern "C" {
void wtarget_0011e9a8(u32, u32, u32, u32, f32) asm("_Z16wtarget_0011e9a8jjjj");
void func_0014e1f0(s32, s32) asm("_Z13func_0014e1f0ii");
void ctarget0_00187b90(u8*) asm("_Z17ctarget0_00187b90v");

extern u32 D_0033cc60;
extern u32 D_0033cc68;
extern Slot88* D_0033cc6c;
extern s32 D_00348704;
extern S349 D_00349f00;
extern f32 D_00349e10;
extern u32 D_0034f240;
extern u32 D_01c61960;
extern f32 D_01c6195c;
extern f32 D_01c61964;
extern u8* D_01c6cb20;
extern u32 D_01d49328[];
extern s32 D_01d49348;
extern volatile u32 D_01dae6a0;
extern u32 D_0035ecac;
extern u32 D_0035ecb0;
extern u32 D_0035ecb4;
extern u32 D_0035ee58;
extern u32 D_0035ee7c;
struct E6 { s16 a; s16 b; s16 c; };
extern E6 D_00372650[];
extern s8 D_00372958[];
extern u8* D_00361e00;
extern u8* D_00347f80;
extern u32 D_00361f60;
extern u8 D_00362908[];
extern f32 D_00363440;
extern u8* D_00365c48;

void func_0011e350(u8*, u32);
void func_0011c438(u8*);
void* func_0011e7e0(u32, void*, u32, u32, u32);
void func_00132370(void*, f32);
u8* func_00124748(u32, u32);  // list_nth_node_rel
void func_00239988(u8*);
void func_00138c10(u8*, u32);
void func_0013f230(void);
void func_0015d540(void);
void func_0013f378(void);
void func_0013f498(void);
void func_0014df88(void);
void func_0014e0d8(void);
u8* func_0014aba8(void);
void func_0014aa58(u8*, u32, u32);
void func_00102448(u8*, u32);
u8* func_00103070(void);
void func_00166930(u8*);
void func_0014dc08(u8*);
void func_0014dd10(u8*);
u32 func_001050c8(void);
u32 func_00190140(u8*);
void func_00190f80(u8*, u8*, f32);
void func_0019ca90(u32, u32, u8*);
void func_0019d358(u32);
void func_00184540(Q16*, u8*);
f32 func_0017c930(u8*, u8*);
u32 func_00187ab8(u32);
void func_0031cc28(u32*);
void func_00191938(u32);
void func_00191bf0(f32);
u32 func_0019ba60(u8*);
void func_0016bd60(u8*, u32);
void func_0017f540(u8*, u32, f32, f32);
void func_001c39d0(u8*, u8*);
void func_001c6320(void);
void func_00224828(s32);
void func_0022afe8(s32);
s32 func_001319d8(s32, f32);
s32 func_00105c30(void);
u32 func_002891e8(u32);
s32 func_00252110(u32);
void func_0028dac8(u32, s32);
s32 func_00287bc0(void);
u32 func_00139d78(u8*);
void func_00239bf8(u32, u32);
u32 func_001708f8(u32, s32);
void func_00290960(u8*, u32, u32);
u32 func_002cab58(u32);
void func_002c9f20(u8*);
void func_002c90c8(void*, u32);
u8* func_00102c80(void);
u8* func_00102788(u32, u32, u32, u32);
void func_002cfeb0(u8*, u32, u32, u32);  // obj_init_field1416_bit800
void func_002e7308(u8*);
void func_002def70(u8*);
u8* func_002dc7c8(u32);
void func_002deac0(u8*, f32, f32);  // set_float24_scaled
void func_002deba0(u8*, u32, f32, f32);
void func_001002a0(s32) __attribute__((noreturn));

// Find the first free slot whose key matches the current key and clear it.
Slot88* func_00109c30(void) {
    u32 i;
    Slot88* r = 0;
    for (i = 0; i < D_0033cc68; i++) {
        if (D_0033cc6c[i].f0 == 0 && D_0033cc6c[i].key == D_0033cc60) break;
    }
    if (i < D_0033cc68) {
        r = &D_0033cc6c[i];
        r->f0 = 0;
        r->key = 0;
        r->f16 = 0;
        r->f80 = 0;
        r->f84 = 0;
    }
    return r;
}

// Release the pending entry and every node of the list through the owner's vtable slot 1.
void func_0011c3b0(u8* p) {
    NoTail g;
    if (*(void**)(p + 40)) {
        u8* o = *(u8**)(p + 16);
        (*(Fn1*)(*(u8**)o + 4))(o, *(void**)(p + 40));
        *(u32*)(p + 40) = 0;
    }
    for (Node12* n = *(Node12**)(p + 292); n;) {
        u8* o = *(u8**)(p + 16);
        Node12* next = n->next;
        (*(Fn1*)(*(u8**)o + 4))(o, n);
        n = next;
    }
    func_0011e350(p, *(u32*)(p + 56));
    func_0011c438(p);
}

void wtarget_0011e9a8(u32 a, u32 b, u32 c, u32 d, f32 x) {
    void* p = 0;
    while ((p = func_0011e7e0(a, p, b, c, d)) != 0) func_00132370(p, x);
}

u32 func_00124578(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u8 t2, u32 t3) {
    u8* o = func_00124748(a0, 0);  // list_nth_node_rel
    return (*(Fn8*)(*(u8**)o + 76))(o, a1, a2, a3, t0, t1, t2, t3);
}

void func_001387f8(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00239988(p + 24);
    func_00138c10(p, a3);
    *(s32*)(p + 392) = -1;
}

void func_0013f050(s32 a) {
    if (a < 0) {
        D_00348704 = a & 0x7fffffff;
        return;
    }
    D_00348704 = a;
    a &= 0x3fffffff;
    if (a == 1) goto L1;
    if (a == 0) goto L0;
    if (a == 2) goto L2;
    if (a != 3) return;
    func_0013f498();
    return;
L2:
    func_0013f378();
    return;
L0:
    func_0015d540();
    return;
L1:
    func_0013f230();
}

static inline bool ready_14a0a0() { return *(u32*)(func_0014aba8() + 252) == 4; }
void func_0014a0a0(u8* p) {
    if (*(u8*)(p + 4) == 0) {
        func_0014df88();
        func_0014e0d8();
        func_0014aa58(func_0014aba8(), 15, 0);
        while (!ready_14a0a0()) func_00102448(p, 0);
    }
    u8* o = func_00103070();
    (**(Fn0**)o)(o);
}

void func_0014e1f0(s32 a, s32 b) {
    NoTail g;
    if (b == 0xffff && a == 1) {
        S349* s = &D_00349f00;
        func_00166930(s->a);
        func_0014dc08(s->b);
        s->c = 0x80;
    }
    if (b == 0xffff && a == 0) {
        S349* s = &D_00349f00;
        func_0014dd10(s->b);
    }
}

// Split a gauge into segments: *outB = size per segment, *outA = fill of the current one.
u8 func_001560a8(u8* o, s32* outA, s32* outB) {
    u8* x = *(u8**)(*(u8**)(o + 52) + 1164);
    u8 n = x[435];
    s32 per = (s32)(*(f32*)(x + 440) / n);
    s32 cur = (s32)*(f32*)(x + 436);
    *outB = per;
    if (per == 0) {
        *outA = 0;
        return 0;
    }
    s32 q = cur / per;
    if (q == n) {
        *outA = per;
        q--;
    } else {
        *outA = cur % per;
    }
    return q;
}

void func_0016c358(u8* p) {
    if (*(u32*)(p + 2224)) {
        u32 v = func_001050c8();
        u32 o = *(u32*)(p + 2224);
        (*(Fn3*)(**(u8***)(p + 2224) + 40))(o, v, *(u32*)(p + 1648));
        *(u32*)(p + 2224) = 0;
    }
}

void func_0017a600(u8* p) {
    u8* s = p + 2548;
    if (!func_00190140(s)) {
        func_00190f80(s, p, 0.0f);
        if (func_00190140(s)) {
            func_0019ca90(*(u32*)(p + 2880), 1, s);
            func_0019d358(*(u32*)(p + 2880));
        }
    }
}

Q16* func_0017c870(Q16* ret, u8* a1, u8* a2) {
    union UF { u32 u; f32 f; };
    ((UF*)(a2 + 208))->f += D_00349e10;
    ((UF*)(a2 + 20))->u = 0;
    Q16 t;
    func_00184540(&t, a2);
    if (ret != &t) QCOPY(ret, &t);
    *(f32*)&ret->w[1] = func_0017c930(a1, a2);
    return ret;
}

// Push a new entry onto the 16-slot ring buffer at +8.
void func_001882a8(u8* p) {
    u32 v = func_00187ab8(*(u32*)(p + 140));
    if (v) {
        ctarget0_00187b90(p);
        Pair t;
        t.a = v;
        t.b = 0;
        *(s32*)(p + 4) = (*(s32*)(p + 4) + 15) % 16;
        Pair* e = (Pair*)(p + 8) + *(s32*)(p + 4);
        func_0031cc28(&t.b);
        *e = t;
        *(u32*)(p + 152) = 0;
    }
}

void func_00191758(void) {
    D_0034f240 = 0;
    func_00191938(0);
    f32 a = 1.0f;
    D_01c61960 = 0;
    D_01c6195c = 30.0f;
    D_01c61964 = a;
    func_00191bf0(a);
}

// Add d to a 0..99 sub-counter at +432, carrying into the level at +433 (capped by +434).
void func_001a1aa0(u8* p, s32 d) {  // ring_buffer_index
    s32 v = p[432] + d;
    if (d >= 0) {
        while (v >= 100) {
            if (p[433] < p[434]) p[433]++;
            if (p[433] >= p[434]) {
                v = 100;
                break;
            }
            v -= 100;
        }
    } else if (v < 0) {
        if (p[433] != 0) {
            p[433]--;
            v += 100;
        } else {
            v = 0;
        }
    }
    p[432] = v;
}

u32 func_001a6850(void) {
    for (u8** n = (u8**)D_01c6cb20; n; n = (u8**)n[3]) {
        u8* o = n[0];
        if (*(u32*)(o + 28) & 4) continue;
        u8* a = *(u8**)(o + 56);
        if (!func_0019ba60(a)) continue;
        u32 fl = *(u32*)(a + 1416);
        if (!(fl & 0x4000)) continue;
        if (!(fl & 0x400000)) return 1;
    }
    return 0;
}

// Allocate an id 1..255 from a 256-bit bitmap, round-robin.
u32 func_001bffd8(void) {
    for (s32 i = 0; i < 256; i++) {
        s32 c = (D_01d49348 + 1) % 255;
        D_01d49348 = c;
        u32 id = c + 1;
        u32* w = &D_01d49328[id >> 5];
        u32 m = 1 << (id & 31);
        if (!(*w & m)) {
            *w |= m;
            return id;
        }
    }
    return 0;
}

void func_001c3aa0(u8* a, u8* b) {
    if (0.0f < *(f32*)(b + 28)) {
        func_0016bd60(b, 18);
        return;
    }
    func_0017f540(b + 320, 208, 16.0f, 0.0f);
    func_001c39d0(a, b);
}

// VU0 vector scale (v * 30) into p+64.
void func_001c6400(u8* p, Q16* v) {
    Q16 t;
    f32 s = 30.0f;
    Q16* d = (Q16*)(p + 64);
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&t), "r"(v), "f"(s) : "$8", "memory");
    if (d != &t) QCOPY(d, &t);
    *(f32*)(p + 76) = 12.0f;
    *(void**)(p + 84) = (void*)func_001c6320;
}

void func_0022afa0(s32 a) {
    func_00224828(a);
    func_0022afe8((s32)((f32)a * 1.5f));
}

void func_002368e8(u8* p, f32 x) {
    if (**(s8**)(p + 408) == 0 && *(u32*)(p + 48) == 0) {
        s32 n = *(s32*)(p + 36) * *(s32*)(p + 40);
        s32* a = *(s32**)(p + 60);
        for (; n > 0; n--) {
            *a = func_001319d8(*a, x);
            a++;
        }
        **(s8**)(p + 408) = 1;
    }
}

u32 func_002402e0(void) {
    switch (func_00105c30()) {
    case 1:
    case 8:
        D_01dae6a0 = D_0035ecac;
        break;
    case 2:
        D_01dae6a0 = D_0035ecb0;
        break;
    default:
        D_01dae6a0 = D_0035ecb4;
        break;
    }
    return D_01dae6a0;
}

void func_00252618(void) {
    s32 i = func_00252110(func_002891e8(D_0035ee58));
    func_0028dac8(D_0035ee7c, D_00372650[i].b);
}

// Look the current id up in a -1 terminated table.
void func_00258080(s32* a, s32* b) {
    s32 v = func_00287bc0();
    bool found = false;
    for (s32 i = 0; D_00372958[i] >= 0; i++) {
        if (v == D_00372958[i]) {
            found = true;
            break;
        }
    }
    if (!found) {
        *a = 25;
        *b = 23;
    } else {
        *a = 22;
        *b = 21;
    }
}

void func_0028e438(u8* p, s32 i, u32 v, u32 w) {
    func_00139d78(p);
    u32 off = i * 380;
    u32 e = off + *(u32*)(p + 56);
    if (*(u32*)(e + 344) != v) {
        *(u32*)(e + 344) = v;
        func_00239bf8(*(u32*)(p + 56) + off, v);
    }
    *(u32*)(off + *(u32*)(p + 56) + 348) = w;
    *(u8*)(off + *(u32*)(p + 56) + 352) = 0;
}

void func_00290a10(u8* p, u32 a, u32 b) {
    func_00290960(p, func_001708f8(a, -1), b);
    p[16] = 1;
}

void func_002ca010(u32 a) {
    if (func_002cab58(a)) return;
    u8* c = D_00361e00;
    if (c) {
        if (*(u32*)(c + 9608) == a) return;
        func_002c9f20(c);
        D_00361e00 = 0;
    }
    u8* al = *(u8**)(D_00347f80 + 20);
    void* m = (**(AllocFn**)al)(al, 9616, 0);
    func_002c90c8(m, a);
}

void func_002cedd0(s32 n, E16* e) {
    for (s32 i = 0; i < n; i++, e++) {
        u8* o = func_00102788(*(u32*)(func_00102c80() + 4), 1, e->a, e->b);
        *(E16**)(o + 8) = e;
        *(u32*)(o + 4) = D_00361f60;
        e->obj = o;
        if (e->c) *(u32*)(o + 48) = e->c;
    }
}

// Wrap an angle into [-pi, pi].
f32 func_002d48b8(f32 x) {
    if (0.0f < x) {
        while (3.1415927f < x) x -= 6.2831855f;
    } else {
        while (x < -3.1415927f) x += 6.2831855f;
    }
    return x;
}

void func_002db808(u8* p, u32 a, u32 b) {
    NoTail g;
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(s32*)(p + 2836) = -1;
    *(u8**)p = D_00362908;
    func_002e7308(p + 2976);
}

void func_002df7d8(u8* p, u32 b) {
    func_002def70(p);
    u32 s = D_00361f60;
    u8* x1 = func_002dc7c8(s);
    u8* y1 = func_002dc7c8(s);
    func_002deac0(p, *(f32*)(x1 + 244), *(f32*)(y1 + 248));  // set_float24_scaled
    u8* x2 = func_002dc7c8(s);
    u8* y2 = func_002dc7c8(s);
    func_002deba0(p, b, *(f32*)(x2 + 252), *(f32*)(y2 + 256));
}

// Returns (o+16) scaled by D_00363440 (VU0).
Q16* func_002eaba8(Q16* ret, u32, u8* o) {
    Q16 t;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&t), "r"(o + 16), "f"(D_00363440) : "$8", "memory");
    if (ret != &t) QCOPY(ret, &t);
    return ret;
}

// Run all registered exit handlers (newest first), then the final hook, then exit.
void func_002fd348(s32 code) {
    for (Blk* b = *(Blk**)(D_00365c48 + 328); b; b = b->next) {
        s32 i = b->n;
        while (--i >= 0) b->fns[i]();
    }
    VFn f = *(VFn*)(D_00365c48 + 60);
    if (f) f(D_00365c48);
    func_001002a0(code);
}
}
