#include "../common/types.h"

// 128-bit copy through $t0.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte value whose copy is a single lq/sq.
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {
extern s16 D_00369d98[];
extern s32 D_00348820;
extern u8 D_00348830[][80];
extern s32 D_0034a400;
extern s32 D_0034a408[];
extern char D_0036b248[];
extern u32 D_0034aa08;
extern u32 D_0034f240;
extern u32 D_0032d7c0[][8];
extern u8* D_0034e948;
extern void* D_01d49530[8];
extern s32 D_01d49550;
extern u8* D_00352668;
extern u8* D_01d9e6e4;
extern u32 D_0035f010;
extern u8 D_0035f4f8;
extern u8 D_0035f4f9;
extern u8 D_0035f4fa;
extern u8* D_0035f658;
extern void* D_0035f64c;
extern void* D_0035f678;
extern u8* D_01e2aa80;
extern u32 D_0032b96c;
extern f32 D_00363450;
extern u8* D_00365c48;
extern u8 D_01e3c780[];
extern u64 D_01e4c780;
extern s32 D_01e3c770;

void func_0016adc8(void*, void*);
void func_00176a60(void*, f32);
void func_001169e8(void*);
void func_0017f540(void*, s32, f32, f32);
void* func_001144e8(void*, u64);
void func_0010eed8(void*, void*, s32);
u32 func_00112740(void*);
void func_00112730(void*, u32);
s32 func_001dc5f0(s32);
void func_0013f608(void*);
s32 func_001466b0(void*);
s32 func_00146cb0(void*, void*);
void func_002bc358(s32, s32);
void* func_00192cc0(void*, const char*, u32);
void func_001a98e8(void*, s32, void*, u32, s32);
void func_001a9ae8(void*, void*, void*, void*);
s32 func_00162098(void);
void func_00162058(f32);
void func_00144908(void*, void*);
void* func_0016b0d0(void);
f32* func_0016c028(void*);
void func_00167658(void*, s32);
u64 func_00167cd0(void*);
void func_001676b0(void*, u64);
void func_001b2210(void*, void*, f32, f32);
void func_0017f488(void*, s32, f32, f32);
s32 func_00187920(void*);
s32 func_00197e40(void);
void* func_001a3a78(void);
s32 func_001de168(void*, s32, s32, s32, s32, void*);
s32 func_0019ba60(void*);
void func_0019d358(void*);
s32 func_00187300(void*, void*, f32);
s32 func_0018d940(void*, void*, s32, void*);
void* func_001c0320(void*, void*, void*);
u8* func_0018da18(void*, void*, void*, void*);
void func_001903d0(void*, void*);
void func_0016ed50(s32, s32, s32);
void func_0016bda8(void*, void*);
void func_0016f000(s32, void*, f32);
void func_001991a8(s32, s32);
void func_001dc978(void*, f32);
void* func_0017df58(s32);
void* func_0016a070(void*);
s32 func_001c9958(void*, void*);
void func_001c9780(void*, f32);
u8* func_001c16f0(void*, void*);
void func_001c79a0(void*, void*, s32);
s32 func_001d5868(void*);
s32 func_001d58f0(void*);
void func_001d5800(void*);
void func_001a3188(u16, s32, s32);
f32 func_002f3d70(void*);
void func_002f3d98(void*, void*);
void func_0021fe08(void*, u32);
s32 func_00257070(s32);
u8* func_00281180(u32, s32);
u8* func_002859a0(void);
s32 func_002938f0(void);
void func_00170320(s32);
u8* func_00103eb0(void);
void func_00102818(u32, s32, u32, void (*)(), s32);
void func_00293848();
s32 func_00139d78(void*);
s32 func_0028acc8(void*);
void func_0028abe0(void*);
s32 func_0028be58(void*);
void func_0028be18(void*);
void func_002b5af0(void);
void func_002bbf68(void*, s32);
u8* func_00102788(u32, s32, u32, void (*)());
void func_002c53c8();
void func_0017c030(void*, void*, void*, u8);
void func_0017c4c8(void*, void*);
u32 func_0023a918(void*);
s32 func_0030edb0(void);
void func_0030ee00(void);
void func_002fd408(void*);

// Is `id` in the -1-terminated id table?
s32 func_00103428(s32 id) {
    s32 i;
    s32 r = 0;
    for (i = 0; D_00369d98[i] >= 0; i++) {
        if (id == D_00369d98[i]) {
            r = 1;
            break;
        }
    }
    return r;
}

void func_00111060(u8* p, void* v) {
    u32 tmp[4] __attribute__((aligned(16)));
    QCOPY(tmp, v);
    func_0016adc8(p, tmp);
    *(u32*)(p + 2940) |= 1;
    u8* o = *(u8**)(p + 2912);
    (*(void (**)(void*))(*(u32*)o + 48))(o);
    func_00176a60(p, 30.0f);
    *(u32*)(p + 3296) += 1;
    *(f32*)(p + 3292) = 480.0f;
    *(u32*)(p + 3288) = 0;
}

// 8-byte constant (a member-function pointer) passed by value.
struct Pmf8 { u64 v; } __attribute__((packed));
extern const Pmf8 D_0036a840;
void func_00118d10(u8* p) {
    func_001169e8(p);
    func_0017f540(*(u8**)(p + 4) + 320, 161, 4.0f, 0.0f);
    void* r = func_001144e8(p, D_0036a840.v);
    if (r) {
        func_0010eed8(*(void**)(p + 4), r, 0);
        func_00112730(*(void**)(p + 4), func_00112740(*(void**)(p + 4)) | 4);
    }
}

// Follows redirect nodes (type -1) and returns the entry of a type-0 node.
u8* func_00132018(u8* p) {
    if (p) {
        s16 t = *(s16*)p;
        if (t != -1) {
            if (t == 0) return p + (*(s32*)(p + 32) + *(s32*)(p + 4) * 4);
            return 0;
        }
        return func_00132018(p + ((s32*)(p + 4))[*(s32*)(p + 4)]);
    }
    return 0;
}

struct KeyPair { s32 key; s32 val; };
struct KeyTable { u8 pad[12]; s32 n; KeyPair e[1]; };
s32 func_001362a0(KeyTable* p, s32 key) {
    s32 i;
    for (i = 0; i < p->n; i++) {
        if (p->e[i].key == key && p->e[i].val == func_001dc5f0(key)) return i;
    }
    return -1;
}

void func_0013f648(QWord* p) {
    func_0013f608(p);
    p[1] = p[7] = p[6];
    p[0] = p[9] = p[8];
    p[2] = p[11] = p[10];
}

s32 func_00143fc8(void* a, void* b) {
    s32 i;
    if (!func_001466b0(a)) return 1;
    for (i = 0; i < D_00348820; i++) {
        if (func_00146cb0(D_00348830[i], b)) return 1;
    }
    return 0;
}

void func_0014eda8(void) {
    s32 i;
    for (i = 0; i < D_0034a400; i++) {
        s32 v = D_0034a408[i];
        if (v != -1) func_002bc358(v, 1);
    }
}

void func_00152688(u8* a, void* b, void* c, void* d) {
    char name[16];
    u8 obj[96];
    void* r = func_00192cc0(name, D_0036b248, *(u32*)(a + 444));
    func_001a98e8(obj, 1, r, *(u32*)(a + 424), 0);
    func_001a9ae8(obj, b, c, d);
}

void func_00159308(u8* p) {
    if (*(u64*)(p + 8) & 0x400000) {
        if (!func_00162098()) {
            D_0034aa08 ^= 1;
            func_00162058(12.0f);
        }
    }
}

void func_001608c0(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    func_00144908(p + 656, tmp);
    if (p + 640 != (u8*)tmp) QCOPY(p + 640, tmp);
    void* r = func_0016b0d0();
    if (r) {
        f32 y = func_0016c028(r)[1];
        if (*(f32*)(p + 660) <= y && y <= *(f32*)(p + 672)) *(f32*)(p + 644) = y;
    }
}

struct Flags167 { u32 a : 1; u32 b : 1; };
static inline bool flagA167(u8* p) { return ((Flags167*)(p + 72))->a; }
void func_00167d68(u8* p) {
    if (flagA167(p)) {
        func_00167658(p, 0);
    } else {
        u64 v = func_00167cd0(p);
        if (*(u32*)(p + 72) & 2) *(u64*)p = v;
        func_001676b0(p, v);
        if (*(s32*)(*(u8**)(p + 68) + 72) == 1) {
            *(u32*)(p + 72) &= ~2;
            return;
        }
    }
    *(u32*)(p + 72) |= 2;
}

struct Args172 { u8** a; void* pos; f32 c; f32 d; s32 e; f32 f; s32 g; };
void func_00172260(Args172* s) {
    u8* o = *(u8**)(*(u8**)s + 4);
    u32 tmp[4] __attribute__((aligned(16)));
    QCOPY(tmp, s->pos);
    func_001b2210(o, tmp, s->c, s->d);
    func_0017f488(o + 320, s->e, s->f, 0.0f);
    if (s->g) {
        s32 e = s->e;
        *(s32*)(o + 256) = e + 1;
        *(s32*)(o + 260) = e + 2;
    }
}

s32 func_00176a90(u8* p) {
    s32 r = 0;
    if (func_00187920(p) || (*(u32*)(p + 268) & 0x10000) || 0.0f < *(f32*)(p + 2816) || (D_0034f240 & 2) || func_00197e40()) r = 1;
    return r;
}

void func_00176be0(u8* p, f32 v) {
    if (*(s32*)(p + 2788) == 0 && !(*(u32*)(p + 352) & 0x4000)) {
        s32 h = func_001de168(func_001a3a78(), 6, 0, 1, 10004, p);
        *(s32*)(p + 2788) = h;
        *(f32*)(p + 2792) = v;
    } else if (*(f32*)(p + 2792) < v) {
        *(f32*)(p + 2792) = v;
    }
}

// Clears flag bit `id` (1024 bits per row).
void func_001814b8(s32 id) {
    u32* r = (u32*)((u8*)D_0032d7c0 + (id >> 10) * 32);
    id &= 0x3ff;
    r += (u32)id >> 5;
    *r &= ~(1 << (id & 31));
}

s32 func_001874a0(void* a, f32 f) {
    u8* o = D_0034e948;
    s32 r;
    if (!func_0019ba60(o) || !*(void**)(o + 2880)) {
        r = 0;
    } else {
        func_0019d358(*(void**)(o + 2880));
        r = func_00187300(a, *(u8**)(o + 2880) + 4, f);
    }
    return r;
}

u8* func_0018db38(void* a, u8* b, s32 c, void* d) {
    u8 flag[16];
    if (!func_0018d940(a, b, c, d)) return 0;
    u8* r = func_0018da18(a, b, func_001c0320(b + 2640, a, flag), d);
    r[36] = c;
    if (!flag[0]) *(u32*)(r + 24) |= 3;
    return r;
}

struct Out1904 { u32 a[3]; u32 z; QWord q; };
QWord func_001904a8(void* x) {
    Out1904 l;
    l.z = 0;
    func_001903d0(x, &l);
    return l.q;
}

void func_001bfbd8(void) {
    func_0016ed50(952, -1, 30);
    func_0016ed50(953, -1, 30);
    func_0016ed50(954, -1, 30);
    func_0016ed50(955, -1, 30);
}

void func_001bfcc8(u8* p, s32 n) {
    u8 buf[16];
    s32 i;
    if (!n) return;
    func_0016bda8(buf, p);
    if (*(s32*)(p + 2764) < n) n = *(s32*)(p + 2764);
    for (i = 0; i < n; i++) func_0016f000(2179, buf, 0.0f);
    *(s32*)(p + 2764) -= n;
    if (*(u32*)(p + 1416) & 0x80) func_001991a8(80, n);
}

// 8-entry ring: releases the oldest entry and stores x in its slot.
void func_001c2c00(void* x) {
    void* o = D_01d49530[D_01d49550];
    if (o) func_001dc978(o, 4.0f);
    D_01d49530[D_01d49550] = x;
    D_01d49550 = (D_01d49550 + 1) % 8;
}

void func_001c9860(void* p) {
    s32 i;
    for (i = 0; i < 2; i++) {
        void* o = func_0017df58(i);
        if (func_0019ba60(o) && func_001c9958(p, func_0016a070(o))) func_001c9780(o, 15.0f);
    }
}

void PrizeTrGetAll(void* o) asm("_ZN2YS8PRIZE_TR6GetAllEPNS_6BTLOBJE");
void PrizeTrGetAll(void* o) {
    if (!D_00352668) return;
    u8* n = 0;
    while ((n = func_001c16f0(*(void**)(D_00352668 + 2548), n))) {
        if (*(s32*)(n + 72) == 0) func_001c79a0(n, o, 0);
    }
}

void func_001d5960(void* p) {
    if (!func_001d5868(p) && func_001d58f0(p)) func_001d5800(p);
}

void func_001d9630(u16* p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        if (p[i]) {
            func_001a3188(p[i], 100, 0);
            p[i] = 0;
        }
    }
}

union U16Any { u16 h; s32 i; };
struct Reader1da { u8* base; s32 idx; u32 a; u32 pad; u32 b; };
u32 func_001da4d8(Reader1da* s, u16 k) {
    u32 v = ((U16Any*)(s->base + 16 + s->idx * 2))->h;
    s->idx++;
    u32 r;
    switch (k >> 6) {
    case 0: r = s->a; break;
    case 1: r = s->b; break;
    case 2: r = *(u32*)s->a; break;
    case 3: r = (u32)s->base + 16; v *= 2; break;
    default: r = 0; break;
    }
    return r + v;
}

struct Adj1e0 { s32 off; s32 add; };
struct AdjTbl1e0 { Adj1e0 e[10]; };
extern const AdjTbl1e0 D_0036e860;
void func_001e08c8(u8* p) {
    AdjTbl1e0 t = D_0036e860;
    s32 i;
    for (i = 0; t.e[i].off; i++) {
        s32 a = t.e[i].add;
        u8* b = p + 3456;
        b[t.e[i].off] += a;
    }
}

void func_001e2660(u8* p, u8* v) {
    s32 i;
    for (i = 0; i < 10; i++, p += 16) {
        if (p[172] == 0) {
            if (p + 160 != v) QCOPY(p + 160, v);
            p[174] = 0;
            p[175] = 30;
            p[172] = 0x80;
            p[173] = 0;
            return;
        }
    }
}

// Normalised direction (xyz) and length (w); +z when the length is zero.
void func_001e7d20(f32* out, void* v) {
    f32 l = func_002f3d70(v);
    if (0.0f < l) {
        f32 s = __builtin_sqrtf(l);
        func_002f3d98(out, v);
        out[3] = s;
    } else {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[3] = 0.0f;
        out[2] = 1.0f;
    }
}

void func_001fab48(u8* a, u32* b, u8* c) asm("_Z13func_001fab48Pv");
void func_001fab48(u8* a, u32* b, u8* c) {
    u32* offs = *(u32**)(c + 12);
    u8* t = a + offs[0];
    u8* q = t + 160;
    if (b[0] != *(u32*)(a + 12)) return;
    *(u32*)(t + 160) = (u32)(a + offs[1] + 160);
    if (b[1] == 0xffff) {
        *(u32*)(q + 4) = 0;
        return;
    }
    u32 x = *(u32*)(D_01d9e6e4 + 20) + b[1] * 8;
    if (x != *(u32*)(q + 4)) func_0021fe08(q, x);
}

// Packs the non-zero entries to the front.
struct Slots26b { u8 pad[16]; u8 n; u8 pad2[3]; u16 a[1]; };
void func_0026b470(void) {
    Slots26b* t = *(Slots26b**)(func_00281180(D_0035f010, func_00257070(1)) + 580);
    u8 n = t->n;
    s32 i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (t->a[i] == 0 && t->a[j] != 0) {
                t->a[i] = t->a[j];
                t->a[j] = 0;
            }
        }
    }
}

void func_00287430(s32 a, s32 b) {
    u32* bits = (u32*)(func_002859a0() + 164);
    if (a == 7) a--;
    a--;
    u32 bit = a * 48 + b;
    u32 m = 1 << (bit & 31);
    if (!(bits[bit >> 5] & m)) bits[bit >> 5] |= m;
}

void func_002937c0(void) {
    if (func_002938f0()) {
        D_0035f4f9 = 0;
        asm volatile("" ::: "memory");
    }
    if (D_0035f4f9 == 0) {
        D_0035f4f9 = 1;
        D_0035f4f8 = 0;
        D_0035f4fa = 0;
        func_00170320(5100);
        func_00102818(*(u32*)(func_00103eb0() + 4), 0, 0x222e0, func_00293848, 4096);
    }
}

void func_002b5658(void) {
    if (D_0035f658 && func_00139d78(D_0035f658)) {
        u8* o = D_0035f658;
        (*(void (**)(void*))(*(u8**)o + 20))(o);
    }
    if (D_0035f64c && func_0028acc8(D_0035f64c)) func_0028abe0(D_0035f64c);
    if (func_0028be58(D_0035f678)) func_0028be18(D_0035f678);
    func_002b5af0();
}

static inline u8* nextNode2bc(u8* n) {
    if (!n) return D_01e2aa80;
    return *(u8**)(n + 28);
}
void func_002bc708(s32 id) {
    u8* n = 0;
    while ((n = nextNode2bc(n))) {
        if (*(s32*)(n + 24) == id && n[49] == 6) func_002bbf68(n, 1);
    }
}

void func_002c5418(u32 x) {
    *(u32*)(func_00102788(D_0032b96c, 0, 0x493e0, func_002c53c8) + 4) = x;
}

void func_002eabe8(void* self, u8* o, u8 c) {
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    s32 k;
    func_0017c030(v, o, &k, c);
    v[3] *= D_00363450;
    QCOPY(w, v);
    func_0017c4c8(o, w);
    o[1300] = 7;
    func_0017f488(o + 320, k, 0.0f, 0.0f);
    *(s32*)(o + 256) = 4;
    *(s32*)(o + 260) = 5;
}

// Unpacks a 32-bit RGBA value into bytes.
u8* func_002ef660(u8* out, u8* p) {
    u32 v = func_0023a918(p + 468);
    out[0] = v;
    out[1] = v >> 8;
    out[2] = v >> 16;
    out[3] = v >> 24;
    return out;
}

struct Blk2fd { Blk2fd* next; s32 n; u32 items[32]; };
Blk2fd* func_002fd3e8(u32);
// Appends x to a chain of 32-entry blocks.
s32 func_002fd188(u32 x) {
    Blk2fd* b = *(Blk2fd**)(D_00365c48 + 328);
    if (!b) {
        b = (Blk2fd*)(D_00365c48 + 332);
        *(Blk2fd**)(D_00365c48 + 328) = b;
    }
    s32 n = b->n;
    if (n >= 32) {
        b = func_002fd3e8(136);
        if (!b) return -1;
        b->n = 0;
        b->next = *(Blk2fd**)(D_00365c48 + 328);
        *(Blk2fd**)(D_00365c48 + 328) = b;
        n = 0;
    }
    b->n = n + 1;
    b->items[n] = x;
    return 0;
}

// Frees a block: 1 KB pool blocks clear their used bit, others go to the heap.
void func_00316658(u8* p) {
    if (p >= D_01e3c780 && p < D_01e3c780 + 0x10000) {
        u32 i = (u32)(p - D_01e3c780) >> 10;
        s32 r = func_0030edb0();
        D_01e4c780 &= ~(1ull << i);
        D_01e3c770 = r;
        if (r) {
            func_0030ee00();
            asm volatile(""); // keeps the call from becoming a tail call
        }
        return;
    }
    func_002fd408(p - 80);
}
}
