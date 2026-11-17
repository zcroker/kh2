#include "../common/types.h"

// ---- 0010cef0
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V10ce {
    f32 x, y, z, w;
    V10ce& operator=(const V10ce& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

static inline V10ce operator-(const V10ce& a, const V10ce& b)
{
    V10ce r;
    asm(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

static inline f32 Dot10ce(const V10ce& a, const V10ce& b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
                 "vaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}

extern "C" {
extern u8* D_00341708;
V10ce func_00190388(u8*);  // vec4_from_arg
V10ce* func_0016c028(u8*);  // obj_get_attach_or_alt
f32 func_001142d0(u32);  // get_float_at_ptr108
f32 func_00114380(u32);
f32 func_00114390(u32);

s32 func_0010cef0(u8* o);  // 0x0010cef0: definition moved into src/anon/unit_0010ce78.cpp
}

// ---- 001136b8
extern "C" {
struct R1136 { u32 id; u8 pad[124]; };
struct E1136 { u8 pad[12]; u32 id; u32 res; u32 a; u32 b; u32 c; u32 pad2; };
struct D1136 { u8 pad[160]; s32 count; u32 off; };
struct S1136 { u32 pad[2]; u32 data; s32 count; u32 ents; };
u32 func_00114620(u32);
u32 func_001145b0(u32);

#define DATA ((D1136*)s->data)
#define ENTS ((E1136*)s->ents)

// Links each entry to the resource record with the same id and resolves its handles.
void func_001136b8(S1136* s);  // 0x001136b8: definition moved into src/anon/unit_00113628.cpp
#undef DATA
#undef ENTS
}

// ---- 001382e0
extern "C" {
struct Alloc1382 { struct VT { u8* (*alloc)(void*, u32, u32); }* vt; };
struct Mgr1382 { u8 pad[20]; Alloc1382* heap; };
extern Mgr1382* D_00347f80;
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_00347d90[];
extern u8* D_00347d5c;
extern u8* D_00347d60;
u8** func_001a84b0(void);
void func_001b1e80(u8*);
void func_002361a0(u8*);
u32 func_0013a7d0(s32);
void func_00138650(u8*, s32, u32, s32);
void func_0031a838(u8*);
void func_00239700(u8*);
void func_00137890(u8*, u8*, u8*, u8*);
void func_002ba2e8(s32, s32);

static inline u8* Alloc1382n(u32 n) { Alloc1382* h = D_00347f80->heap; return h->vt->alloc(h, n, 0); }

void func_001382e0(void);  // 0x001382e0: definition moved into src/anon/unit_001374c8.cpp
}

// ---- 0013f6e8
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V13f6 {
    f32 x, y, z, w;
    V13f6() {}
    V13f6(const V13f6& o) { QCOPY(this, &o); }
    V13f6& operator=(const V13f6& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
    V13f6& operator*=(f32 s)
    {
        asm("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V13f6& operator+=(const V13f6& o)
    {
        asm("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

static inline V13f6 operator-(const V13f6& a, const V13f6& b)
{
    V13f6 r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

static inline V13f6 operator*(const V13f6& v, f32 s)
{
    V13f6 r;
    asm(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}

static inline f32 Length13f6(const V13f6& v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\t"
        "vsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}

static inline f32 Dot13f6(const V13f6& a, const V13f6& b)
{
    register f32 r asm("$f0");
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
        "vaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}

static inline f32 Normalize13f6(V13f6& v)
{
    register f32 len asm("$f2");
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}

extern "C" {
// Damped spring step: pulls *pos toward *anchor (rest length `rest`), returns the new position.
V13f6 func_0013f6e8(V13f6* pos, V13f6* anchor, V13f6* vel, f32 dt, f32 k, f32 c, f32 rest);  // 0x0013f6e8: definition moved into src/anon/unit_0013ef70.cpp
}

// ---- 0015a158
extern "C" {
struct P15a1 { u64 f0; u64 f8; u8 pad[28]; f32 speed; };
struct O15a1 { u8 pad[68]; u32 w68; f32 f72; f32 f76; f32 f80; };
extern f32 D_00349e10;
extern f32 D_004f3604;
extern f32 D_0034aa84;
void* func_001584f8(P15a1*);
s32 func_00158548(P15a1*);
f32 func_0017ce10(f32);
void* func_0019c4d0(u32);
void func_00159fd0(O15a1*, P15a1*, f32);
f32 func_0015a098(void);
void func_0013fd90(O15a1*);

// 0015a158: moved to src/harata/libdk/targetcamera.cpp
}

// ---- 001791e8
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V1791 {
    f32 x, y, z, w;
    V1791& operator=(const V1791& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

static inline V1791 operator*(const V1791& v, f32 s)
{
    V1791 r;
    asm("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}

extern "C" {
union W1791 { f32 f; u32 u; };
struct D1791 { u8 pad[12]; f32 f12; f32 scale; f32 f20; f32 f24; f32 f28; };
u32 func_00177860(u8*);
s32 func_001c3618(u32, s32);
D1791* func_001ce300(s32);  // to_1ce2a0_index_minus1
void func_0016aef0(u8*, V1791*);
void func_0017f488(u8*, s32, f32, f32);
void func_0016ac38(u8*, s32, s32, s32, s32);
void func_0016bd60(u8*, s32);
void func_00176a60(u8*, f32);

// 001791e8: moved to src/yasui/libys/player.cpp
}

// ---- 0017da90
extern "C" {
extern u8 D_0034ebc8[];
extern u32 D_01c60528[];
extern f32 D_01c60520;
void func_00175670(u8*, u32, s32, u32);
u32 func_0016a070(u8*);
u8* func_001a1540(u32);
u32 func_0016f6a0(u32, s32);
void func_00176168(u8*, u32, s32);

// 0017da90: moved to src/yasui/libys/friend.cpp
}

// ---- 00180058
extern "C" {
u8* func_00168b88(u32, s32, s32, s32);  // find_entry16_by_half_word
void func_0017efa0(u8*, u32, f32, f32);
void func_00180800(u8*, s32);

// 00180058: moved to src/yasui/libys/motion.cpp
}

// ---- 00185770
extern "C" {
struct Info1857 { s32 id; u8 pad[68]; u16 bits; };
struct Obj1857;
struct VT1857 { u8 pad[72]; void (*f72)(Obj1857*); };
struct Obj1857 { VT1857* vt; u32 pad; Info1857* info; u8 pad2[256]; u32 flags; u8 pad3[2276]; u32 w2548; };
void func_0016ac38_185770(Obj1857*, s32, s32, s32, s32) asm("func_0016ac38");
void func_001940b8(Obj1857*, s32, s32, s32, f32, f32);  // obj_set_bytes_and_lerp
s32 func_0019c650(u32);
void func_00177638(u32);

static inline bool Flag1857(Obj1857* o) { return (o->info->bits >> 7) & 1; }

// 00185770: moved to src/anon/unit_001855e0.cpp
}

// ---- 001abbf0
extern "C" {
struct S1abb { s32 state; s32 cur; u32 w8; u8 pad[8]; u8 sub[4]; };
struct Pad1abb { u64 d0; u64 trig; };
void func_002ba2e8(s32, s32);
void func_00239bf8(u8*, s32);
s32 func_00239d10(u8*);
void func_001991a8(u32, s32);
void func_001ac728(u8*);

// 001abbf0: moved to src/anon/unit_001abb28.cpp
}

// ---- 001b72c0
extern "C" {
struct Buf1b72 { u8 b[80]; };
void func_001b74b8(Buf1b72*);
void func_001b7508(Buf1b72*, s32, s32);
s32 func_001b73e8(u8*, u32);  // compute_avg_state
void func_001a3188(u16, u32, s32);
void func_001b7538(Buf1b72*, u16);
u32 func_001a8bd0(s32);
s32 func_001a9080(u32, u32);
void func_001b75e8(Buf1b72*, u32, u32);

void func_001b72c0(u8* p, u32 b, u32 c, s32 idx);  // 0x001b72c0: definition moved into src/anon/unit_001b6a50.cpp
}

// ---- 001c0890
extern "C" {
struct BL1c08 { u8 pad[14080]; u8 count; u8 pad2[3]; u32 bits[1]; };
struct T1c08 { u32 pad; s32 n; u8 e[1]; };
extern BL1c08 D_0032bb30;
extern T1c08* D_01d49358;
u8* func_001c0648(u32);
s32 func_001c09c0(u32);
u32 func_001a1658(u8, s32);  // state_dispatch_0_1_14
void func_001c0690(u8*, u32);
void func_001a17c8(u32);
void func_00181670(void);
void bonuslevel_up(u32) asm("_ZN2YS10BONUSLEVEL2UpEi");

// YS::BONUSLEVEL::Up(int): marks bonus level `id` as obtained and applies its entries.
// 001c0890: moved to src/anon/unit_001c0638.cpp
void bonuslevel_up(u32 id);
}

// ---- 001d2418
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V1d24 {
    f32 x, y, z, w;
    V1d24& operator=(const V1d24& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
    V1d24& operator*=(f32 s)
    {
        asm("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

static inline f32 Normalize1d24(V1d24& v)
{
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}

extern "C" {
struct O1d24 { u8 pad[16]; V1d24 v16; V1d24 dir; };
struct G1d24 { u8 pad[224]; f32 speed; };
extern G1d24* D_00352130;
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
V1d24 func_0016af58(O1d24*);
void func_0016bd60_1d2418(O1d24*, s32) asm("func_0016bd60");
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);

void func_001d2418(O1d24* o);  // 0x001d2418: definition moved into src/anon/unit_001d14e0.cpp
}

// ---- 00200e80
extern "C" {
struct M200e { f32 m[16]; } __attribute__((aligned(16)));
struct G200e { u8 pad[16]; M200e mtx; };
union U200e { G200e* p; f32 f; };
extern U200e D_01d9e6e8;
extern M200e D_00354bd0;
extern f32 D_00354bc0[3];
void func_0021eb50(M200e*, void*);
void sceVu0InversMatrix(M200e*, M200e*);  // convert_vectors_to_scalar
void sceVu0MulMatrix(M200e*, M200e*, void*);

static inline void ScaleRow200e(f32* row, f32 s)
{
    asm("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(s) : "memory");
}

void func_00200e80(u8* p, u32, u8* a2)
{
    u32* offs = *(u32**)(a2 + 12);
    f32* pos = (f32*)(p + offs[0] + 160);
    u8* rot = p + offs[1] + 160;
    u8* m = p + offs[3] + 160;
    f32* scl = (f32*)(p + offs[2] + 160);
    M200e t;
    func_0021eb50(&D_01d9e6e8.p->mtx, rot);
    D_01d9e6e8.p->mtx.m[12] = pos[0];
    D_01d9e6e8.p->mtx.m[13] = pos[1];
    D_01d9e6e8.p->mtx.m[14] = pos[2];
    func_0021eb50(&t, &D_00354bd0);
    t.m[12] = D_00354bc0[0];
    t.m[13] = D_00354bc0[1];
    t.m[14] = D_00354bc0[2];
    sceVu0InversMatrix(&t, &t);  // convert_vectors_to_scalar
    sceVu0MulMatrix(&D_01d9e6e8.p->mtx, &D_01d9e6e8.p->mtx, m);
    sceVu0MulMatrix(&D_01d9e6e8.p->mtx, &t, &D_01d9e6e8.p->mtx);
    ScaleRow200e(&D_01d9e6e8.p->mtx.m[0], scl[0]);
    ScaleRow200e(&D_01d9e6e8.p->mtx.m[4], scl[1]);
    ScaleRow200e(&D_01d9e6e8.p->mtx.m[8], scl[2]);
}
}

// ---- 00222170
extern "C" {
struct M2221 { u8 a[32]; u8 b[16]; };
struct N2221 {
    N2221* next; N2221* prev; u8 pad[44]; u16 sel; u8 pad2[8]; u16 flags; M2221 m[1];
};
struct H2221 { N2221* first; u8 flags; };
struct C2221 { H2221* head; u32 a; void* b; N2221* list; u32 c; u32 d; };
struct W2221 { u8 pad[64]; N2221* node; u32 a; u32 l; void* b; };
void sceVu0UnitMatrix(W2221*);  // vu_store_w_splat
void func_002226b8(void*, u32);  // vec3_copy
void func_00221348(W2221*);
void func_00221ed0(N2221*);

void func_00222170(C2221* c)
{
    H2221* h = c->head;
    s32 fl = 0;
    W2221 w;
    if (h->flags & 2) {
        fl = 32;
        h->flags &= ~2;
    }
    sceVu0UnitMatrix(&w);  // vu_store_w_splat
    w.a = c->a;
    w.l = (u32)c->list;
    w.b = c->b;
    N2221* n = h->first;
    while (n) {
        if (n->flags & 0x200) {
            func_002226b8(n->m[n->sel].a, c->c);  // vec3_copy
            func_002226b8(n->m[n->sel].a + 32, c->d);  // vec3_copy
        }
        if (n->flags & 0x100) n->flags = fl | n->flags;
        w.node = n;
        func_00221348(&w);
        if (n->flags & 0x10) {
            N2221* cur = n;
            n = n->next;
            if (cur->next) cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            func_00221ed0(cur);
            cur->next = c->list->prev;
            c->list->prev = cur;
        } else {
            n = n->next;
        }
    }
}
}

// ---- 002418b8
extern "C" {
struct Date2418 { u8 pad; u8 sec; u8 min; u8 hour; u8 day; u8 month; u16 year; };
struct Ent2418 { u32 flags; u8 pad[20]; Date2418 date; };
struct T2418 { u8 pad[8]; Ent2418 e[99]; };
extern T2418* D_0035ec94;

static inline __attribute__((always_inline)) s32 Older2418(const Date2418* a, const Ent2418* e)
{
    s32 r = 0;
    if (a->year > e->date.year) ;
    else if (a->year < e->date.year) r = 1;
    else if (a->month > e->date.month) ;
    else if (a->month < e->date.month) r = 1;
    else if (a->day > e->date.day) ;
    else if (a->day < e->date.day) r = 1;
    else if (a->hour > e->date.hour) ;
    else if (a->hour < e->date.hour) r = 1;
    else if (a->min > e->date.min) ;
    else if (a->min < e->date.min) r = 1;
    else if (a->sec > e->date.sec) ;
    else if (a->sec < e->date.sec) r = 1;
    return r;
}

// Returns the index of the newest valid entry (0 if none).
s32 func_002418b8(void)
{
    Date2418 best;
    s32 found = -1;
    s32 i;
    Ent2418* e = D_0035ec94->e;
    for (i = 0; i < 99; i++, e++) {
        if (!(e->flags & 0x10)) continue;
        if (found < 0 || Older2418(&best, e)) {
            best = e->date;
            found = i;
        }
    }
    if (found < 0) found = 0;
    return found;
}
}

// ---- 00248f50
extern "C" {
struct S6_248 { s16 a, b, c; };
struct S36_248 { u8 b[36]; };
extern S6_248 D_00371d40[];
extern S36_248 D_00371d90[];
extern S36_248 D_00371e00[];
extern u32 D_0035ed5c;
extern u32 D_0035ed60;
s32 func_00287cd0(void);
s32 func_00289310(u32);
s32 func_002891e8(u32);
void func_002890e0(u32, s32, s32, s32, s32);
void func_00289038(u32, s32, s32, s32, s32, s32, s32);
void func_0023f070(u32, s16, s32);
void func_002493c8(void);
s32 func_0028d008(u32);
u32 func_002891d0(u32);
void func_0028cf28(u32, u32);  // record408_set_and_refresh
void func_002b4388(u32, S36_248*, s32);

void func_00248f50(u32 obj, s32 mode, u32 w)
{
    if (func_00287cd0() != 1) return;
    if (!func_00289310(obj)) return;
    s32 k = func_002891e8(obj);
    func_002890e0(obj, 1, 2, 0, -1);
    func_00289038(obj, k, 1, 1, 2, 0, -1);
    if (!mode) {
        func_0023f070(D_0035ed5c, D_00371d40[k].c, -1);
        func_002493c8();
    }
    if (func_0028d008(w)) func_0028cf28(w, func_002891d0(obj));
    func_002b4388(D_0035ed60, !mode ? &D_00371d90[k] : &D_00371e00[k], 0);
}
}

// ---- 00249ef0
extern "C" {
struct E249e { u8 pad[8]; u8 sub[8]; s8 on; u8 pad2; u16 id; u8 pad3[16]; };
extern E249e D_00371f58[];
extern u32 D_0035ed74;
extern u32 D_0035ed78;
extern u32 D_0035ed90;
void func_00288d80(u32, s32, s32, s32, u32, u16, E249e*, void*);
u8* func_002891b8(u32, s32);
u32 func_0023aa78(void*);
u32 func_0023aa98(void*);
void func_00288e08(u32, s32, u32, s32);
u32 func_0028dd90(u32);  // mod10_classify_012
u32 func_0028ddd8(u32);
void func_001395f8(u8*);
void func_002891f0(u32, s32, s32, s32, s32);
void func_002b4388_249ef0(u32, E249e*, s32) asm("func_002b4388");

void func_00249ef0(void)
{
    s32 i;
    s32 sel = 0;
    for (i = 0; i < 2; i++) {
        if (D_00371f58[i].on) sel = i;
        func_00288d80(D_0035ed74, i, 0, 0, D_0035ed78, D_00371f58[i].id, &D_00371f58[i], D_00371f58[i].sub);
        u8* o = func_002891b8(D_0035ed74, i);
        func_00288e08(D_0035ed74, i, func_0023aa78(o + 24), 0);
        u32 x = func_0023aa98(o + 24);
        *(u32*)(o + 432) = func_0028dd90(x);
        *(u32*)(o + 428) = func_0028ddd8(x);
        func_001395f8(o);
    }
    func_002891f0(D_0035ed74, sel, 1, 0, 2);
    func_002b4388_249ef0(D_0035ed90, &D_00371f58[sel], 0);
}
}

// ---- 00254648
extern "C" {
extern u8 D_0035f05c;
extern u32 D_0035f010;
void func_002593b8(s32, u32);
void func_00256b40(void);
void func_00274ea0(void);
void func_00170888(u32);
u32 func_00103570(void);
void func_00274ee8(u32);
void func_002a9ce8(void);
u8 func_002acc98(void);
void func_002a9d30(void);
void func_00274f50(void);
void func_00102448(u32, s32);
void func_00254770(void);
void func_00242618(s32, s32);
s32 func_00293ba0(void);
s32 func_002938e0(void);
s32 func_002938f0(void);
u32 func_00293bc0(void);
void func_002810c8(u32, u32);
void func_00293bb0(void);
void func_00236d60(void);  // clear_64_entries_24
void func_00293520(void);
s32 func_00255588(void);
void func_00255df0(void);

void func_00254648(u32 a)
{
    func_002593b8(2, a);
    func_00256b40();
    func_00274ea0();
    func_00170888(a);
    func_00274ee8(func_00103570());
    func_002a9ce8();
    D_0035f05c = func_002acc98();
    func_002a9d30();
    func_00274f50();
    func_00102448(a, 1);
    func_00254770();
    func_00242618(11, 1);
    for (;;) {
        if (!func_00293ba0() && func_002938e0() && func_002938f0()) {
            func_002810c8(D_0035f010, func_00293bc0());
            func_00293bb0();
        }
        func_00236d60();  // clear_64_entries_24
        func_00293520();
        if (func_00255588()) break;
        func_00255df0();
        func_00102448(a, 0);
    }
}
}

// ---- 00286160
extern "C" {
extern u32* D_0035f2e4;
u32* func_002859a0(void);
u8* func_001a80c8(s32);  // table24_find_by_id
s32 func_00286058(u8);

static inline s32 Check286(u32* got, u32 i)
{
    u32 m = 1 << (i & 31);
    if (!(D_0035f2e4[i >> 5] & m)) return 0;
    return (got[i >> 5] & m) != 0;
}

s32 func_00286160(s32 id);  // 0x00286160: definition moved into src/anon/unit_002853b8.cpp
}

// ---- 002a7dc8
extern "C" {
struct E2a7d { u16 id; u16 pad[2]; u16 h6; };
struct T2a7d { u32 pad[2]; s32 count; u32 pad2; E2a7d e[1]; };
struct P2a7d { s16 a; s16 b; };
struct O2a7d { s32 count; P2a7d e[64]; };
union U2a7d { O2a7d* p; u32 w; s16 h; };
extern U2a7d D_0035f600;
T2a7d* func_00294000(s32);
void func_002fde18(void*, s32, u32);
u8* func_001d56c8(u16);
s32 func_00276c18(void);

static inline bool Ge2a7d(u8 v) { return !(v < 2); }

// Builds the grouped index list for table 7.
void func_002a7dc8(void)
{
    s32 n = 0;
    s32 i = 0;
    T2a7d* t = func_00294000(7);
    E2a7d* es = t->e;
    func_002fde18(D_0035f600.p, 0, 260);
    for (; i < t->count; i++) {
        E2a7d* e = &es[i];
        if (Ge2a7d(*func_001d56c8(e->h6)) || func_00276c18()) {
            if (n == 0 || D_0035f600.p->e[n - 1].a != e->id) {
                D_0035f600.p->e[n].a = e->id;
                D_0035f600.p->e[n].b = -1;
                n++;
            }
            D_0035f600.p->e[n].a = *(volatile u16*)&e->id;
            D_0035f600.p->e[n].b = i;
            n++;
        }
    }
    D_0035f600.p->count = n;
}
}

// ---- 002ac420
extern "C" {
struct Ent2ac4 { s8 id; u8 kind; u8 pad[14]; };
struct Tbl2ac4 { u32 pad[2]; s32 count; u32 pad2; Ent2ac4 e[1]; };
Tbl2ac4* func_00294000_2ac420(s32) asm("func_00294000");
s32 func_002b3ac8(s8);
extern u8* D_0035f610;

// Returns 1 if any flag bit is set for the matching entries of table 9.
s32 func_002ac420(s32 id);  // 0x002ac420: definition moved into src/anon/unit_002a99c8.cpp
}

// ---- 002cd770
struct Vec2cd { f32 x, y, z, w; } __attribute__((aligned(16)));

static inline Vec2cd operator*(const Vec2cd& v, f32 s)
{
    Vec2cd r;
    asm("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}

static inline Vec2cd operator+(const Vec2cd& a, const Vec2cd& b)
{
    Vec2cd r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

extern "C" {
// Hermite interpolation between p[0]/q[0] with tangents p[1]/q[1].
Vec2cd func_002cd770(void*, Vec2cd* p, Vec2cd* q, f32 t);  // 0x002cd770: definition moved into src/taito/path.cpp
}

// ---- 002cf638
extern "C" {
struct E2cf6 { u32 used; u8 obj[8]; u32 w12; u32 w16; u8 pad[16]; s32 w36; };
extern s32 D_00361fa0;
extern E2cf6* D_00361fa4;
s32 func_002cf270(void*, s32);

// Scans the slot table; returns the index just past the last busy slot once n free slots were seen, or -1.
s32 func_002cf638(s32 n);  // 0x002cf638: definition moved into src/anon/unit_002cf260.cpp
}

// ---- 002d8670
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct M2d86 {
    u32 m[16];
    M2d86& operator=(const M2d86& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct P2d86 {
    u8 pad[88]; u8 dirty; u8 pad1[55]; u8 played; u8 pad2[3]; s32 count; u8 pad3[16]; s32 frame;
    f32 t; f32 prev; u8 pad4[4]; s32* info; u8 pad5[13]; u8 b201; u8 pad6[70]; M2d86 src; M2d86 dst;
    u8 pad7[65]; u8 b465; u8 done;
};

extern "C" {
extern f32 D_00349e10;
f32* func_002d73f0(P2d86*);
s32 func_002d94b8(P2d86*);
void func_002d74c8(P2d86*, s32, s32);
void func_001991a8_2d8670(s32, s32) asm("func_001991a8");
void func_002d8670_(s32) asm("_Z13func_002d8670i");

void func_002d8670_(s32 a);  // 0x002d8670: definition moved into src/anon/unit_002d6f70.cpp
}

// ---- 002dfba8
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V2dfb {
    f32 x, y, z, w;
    V2dfb& operator=(const V2dfb& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {
struct P2dfb {
    u8 pad[24]; f32 f24; u8 pad2[21]; u8 b49; u8 pad3[10]; f32 f60; f32 f64; f32 f68; u32 w72;
    u8 pad4[8]; u8 b84; u8 pad5[3]; f32 f88; f32 f92; u32 w96; u8 pad6[12]; V2dfb pos;
};
extern u32 D_00361f60;
f32 func_002dd250(u32, s32);
void func_002deb18(P2dfb*, u8*);
V2dfb* func_0016c028_2dfba8(u8*) asm("func_0016c028");
f32* func_002dc7c8(u32);

void func_002dfba8(P2dfb* p, u8* o);  // 0x002dfba8: definition moved into src/anon/unit_002de3c8.cpp
}

// ---- 002e0d28
extern "C" {
struct Buf2e0d { u8 b[64]; };
extern u8 D_00362dc8[];
extern u8 D_00375eb8[];
extern u8 D_00362d90[];
extern u8* D_0034e948;
void func_002ce958(u8*, s32, u32, s32);
void func_002e34b8(u8*);
void func_002ceae8(u8*, Buf2e0d*, void*);
u8* func_001708f8(Buf2e0d*, s32);
u8* func_00168b38(u8*, s32, s32);  // entry_array_find_nth
void func_002e34c0(u8*, u32);
u32 func_001050c8(void);
u8* func_001063c0(u32, u32);
void func_002e6fc0(u8*, u32);
void func_00102c80(void);
void func_002e1020(u8*);
void func_002cedd0(s32, void*);
void func_0016bd60(u8*, s32);
u8* func_0016b740(s32);

void func_002e0d28(u8* p, u32 a);  // 0x002e0d28: definition moved into src/anon/unit_002de3c8.cpp
}
