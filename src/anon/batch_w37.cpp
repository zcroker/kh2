#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq vscale162(const Vq& v, f32 s) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "$15", "memory");
    return r;
}
static inline Vq vsub162(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

extern "C" {
u32 func_00106178(void*, s32);
extern u8 D_01f18014[];
extern u32 D_0032ba14;
extern u32 D_0032ba18;
extern u8 D_0032ba30;


struct Node139 { u32 _0; Node139* next; u32 _8, _c; s32 id; };
struct List139 { u32 _0; Node139* head; };
extern List139* D_00347f80;
void func_001395a8(void*);


s32 func_00162560(void*, Vq*);
s32 func_00162bb0(const Vq* a, void* b, const Vq* c, const f32* s, Vq* out) {
    Vq t;
    t = vscale162(*c, *s);
    *out = vsub162(*a, t);
    return func_00162560(b, out) != 0;
}

extern s8 D_004f6330;
extern Vq D_004f6340;
void func_0016e898(void);
void func_002fd188(void (*)(void));  // pool_alloc_block
Vq func_0017d538(u32, f32);
void func_0016d5d0(u32* p) {
    if (!D_004f6330) {
        D_004f6330 = 1;
        func_002fd188(func_0016e898);  // pool_alloc_block
    }
    D_004f6340 = func_0017d538(p[0], *(f32*)&p[1]);
    p[0] = (u32)&D_004f6340;
}

void func_0013f5f0(void*);  // copy_float_220_to_48
u32 func_00167f18(u32);
void func_00140618(void*, u32);
typedef s32 (*VFn)(void*);

void func_00140760(u8* p) {
    func_0013f5f0(p);  // copy_float_220_to_48
    u32 v = func_00167f18(0);
    u8* o = *(u8**)(p + 68);
    if ((*(VFn*)(*(u8**)o + 64))(o)) func_00140618(p, v);
}

void func_001666f0(void*, u16, u32, u16, u16);  // obj_store_masked
void func_0014dc48(u8* p, u16 a, u32 b, u16 c, u16 d, u16 e, u32 f) {
    func_001666f0(p, a, b, c, d);  // obj_store_masked
    *(u32*)(p + 464) = f;
    *(u16*)(p + 468) = e;
    p[470] = 0;
    p[471] = 0;
    p[472] = 0;
    p[473] = 0;
}

void func_001548a8(u8* p, s32 n) {
    if (*(u32*)(p + 15568)) {
        for (s32 i = 0; i < n; i++) {
            if (i < 16) func_001395a8(p + 2904 + i * 816);
        }
    }
}

struct Obj160 { void** vt; u8 _4[128]; Obj160* next; u8 _88[248]; u32 flags; };
extern struct { Obj160* head; u32 tail; } D_004f3b40;
typedef void (*VFn0)(void*);
static inline Obj160* nx160b(Obj160* o) { return !o ? D_004f3b40.head : o->next; }
void func_00160b10(void) {
    Obj160* o = 0;
    while ((o = nx160b(o)) != 0) {
        if (!(o->flags & 4)) ((VFn0)o->vt[2])(o);
    }
    D_004f3b40.head = 0;
    D_004f3b40.tail = 0;
}

void* func_0017ec98(void*);
void* func_0017edf0(void*, void*);
u8* func_00168b38(void*, u32, u32);  // entry_array_find_nth
s32 func_0017f4e0(u8* p) {
    void* v = func_0017edf0(p, func_0017ec98(p));
    if (v) {
        u8* q = func_00168b38(v, 9, 0);  // entry_array_find_nth
        if (*(u32*)(p + 12) != *(u32*)(q + 8)) return 1;
    }
    return 0;
}

void func_001d7cd0(void*);
s32 func_0016a090(void*);  // get_byte74
extern u8 D_0034ed78[];
void func_00185b70(u8* p) {
    func_001d7cd0(p);
    *(u32*)(p + 2800) = 0;
    *(void**)p = D_0034ed78;
    *(u32*)(p + 1416) |= 0x10;
    *(f32*)(p + 2804) = 100.0f;
    if (func_0016a090(p) == 2) *(u32*)(p + 2748) |= 0x8000;
}

void* func_00185da8(void*);
s32 func_00186ce8(void*);
void func_0018f3a8(s32* out) {
    void* v = 0;
    s32 n = 0;
    while ((v = func_00185da8(v)) != 0) {
        if (func_00186ce8(v)) n++;
    }
    *out = n;
}

extern u32 D_0034f240;
s32 func_00197920(void);
s32 func_001c8db8(void*, u32);
extern u8 D_00351ec8[];
// 00191a50: moved to src/yasui/libys/status.cpp

s32 func_001a2478(void*);  // count_div4_compare
u8 func_0019e848(void*, void*, void*, u32);
extern u8 D_0036d3f0[];
u8 func_0019e6e8(void* a, u8* b) {
    void* t = *(void**)(b + 1164);
    if (!t || !func_001a2478(t)) return 0;
    return func_0019e848(a, b, D_0036d3f0, 5);
}

struct Pool1a1 { u8 d[600]; s32 timer; u8 _25c[12]; };
struct PoolMgr1a1 { Pool1a1 items[64]; s32 free[64]; s32 nfree; };
extern PoolMgr1a1 D_01c62fb8;
void func_001a1840(void*);
void func_001a17c8(Pool1a1* p) {
    func_001a1840(p);
    if (--p->timer <= 0) {
        D_01c62fb8.free[D_01c62fb8.nfree++] = p - D_01c62fb8.items;
    }
}

struct Obj1ac { void* vt; u8 _4[120]; Obj1ac* next; };
extern struct { Obj1ac* head; Obj1ac* tail; } D_01c6cec0;
extern u8 D_00350c50[];

u32 func_001ae210(const s8* s) {
    u32 c = 0xffffffff;
    s32 ch;
    while ((ch = *s++) != 0) {
        c ^= ch << 24;
        for (s32 i = 7; i >= 0; i--) {
            if (c & 0x80000000) c = (c << 1) ^ 0x04c11db7;
            else c <<= 1;
        }
    }
    return ~c;
}

struct Ent1c3 { u16 id; u8 _2[6]; };
struct Tbl1c3 { u32 _0; s32 n; Ent1c3 e[1]; };
extern Tbl1c3* D_01d49560;
extern u32 D_0032fca8[];

extern void* D_00351fe4;
extern u8 D_0036e180[];
u8* func_001cbc50(void*, void*, void*, u32);
void func_001cba90(void);
u8* func_001cbeb8(void* a, s32 i) {
    u8* r = 0;
    void* m = D_00351fe4;
    if (m) {
        u8* v = func_001cbc50(m, D_0036e180 + i * 16, a, 0);
        *(void**)(v + 16) = (void*)func_001cba90;
        *(u32*)(v + 40) |= 3;
        r = v;
    }
    return r;
}

void func_001980d0(void*, u32, u32);
void func_001dba88(void*);
extern u8 D_00352140[];
extern u8 D_01d5b9e0[];
void func_001ce3e8(u8* p, void* a, u32 b) {
    func_001980d0(p, b, 4);
    *(void**)(p + 2548) = a;
    *(void**)p = D_00352140;
    func_001dba88(a);
    *(u32*)(p + 1416) |= 0x800000;
    *(void**)(p + 2552) = D_01d5b9e0;
}

void func_001d1678(void*, s32);  // obj_init_28bytes
void func_001d19e8(void*, s32);
void func_001d16e8(void*, u32, u32);
extern u8 D_003525c8[];
extern u8 D_003525e8[];
void func_001d1f38(u32* p) {
    p[1] = 0;
    p[0] = (u32)D_003525c8;
    p[2] = 0;
    p[3] = 0;
    func_001d1678(p, -1);  // obj_init_28bytes
    p[12] = 0;
    p[0] = (u32)D_003525e8;
    func_001d19e8(p, -1);
    p[11] = 0;
    p[14] = 0;
    func_001d16e8(p, 0, 12);
}

f32 func_002f8b30(f32, f32);
void func_001d1b60(void*, s32);

void func_00321ce8(void*, void*);  // list_unlink_node
void func_001dc920(void*);
void func_001e0058(void*);
void func_001de450(u8* p) {
    u8* n = *(u8**)(p + 12);
    while (n) {
        u8* next = *(u8**)(n + 96);
        func_00321ce8(p + 12, n);  // list_unlink_node
        func_001dc920(*(void**)(n + 64));
        func_001e0058(n);
        n = next;
    }
}

typedef void (*VFnP)(void*);
struct Obj1e7 { u8 _0[24]; VFnP fn; };
struct Mgr1e7 { u8 _0[100]; s32 n; u8 _68[16]; Obj1e7** objs; };
void func_001e78e0(Mgr1e7* p) {
    for (s32 i = 0; i < p->n; i++) {
        Obj1e7* o = p->objs[i];
        if (o->fn) o->fn(p);
    }
}

void func_002f4000(void*);  // vu_store_w_splat
void func_002f3d08(void*, void*, void*);
extern u8* D_01d9e6e0;
extern u8* D_01d9e6e8;
void func_001eb0c8(void* unused, f32* s) {
    f32 m[16];
    func_002f4000(m);  // vu_store_w_splat
    f32 base = *(f32*)(D_01d9e6e0 + 64);
    f32 lim = s[2];
    u8* t = D_01d9e6e8 + 16;
    m[0] = base + base * s[1];
    if (lim < m[0]) m[0] = lim;
    m[10] = m[0];
    func_002f3d08(t, m, t);
}

void func_001fa950(void*, void*, void*);

void func_00313bc0(f32);
// Local with a non-trivial destructor: keeps the call a jal instead of a sibling call.
struct NoTail { ~NoTail() {} };
void func_00233ac0(u32 a) {
    NoTail g;
    func_00313bc0((f32)a / 216000.0f);
}

struct Ev234 { s32 type; s32 seq; u32 a, b, c, d, e, f; };
extern Ev234 D_01dadc00[64];
extern s32 D_0035e360;
extern s32 D_0035e368;
s32 func_00234400(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    s32 i = D_0035e360;
    s32 seq = D_0035e368;
    Ev234* ev = &D_01dadc00[i];
    ev->type = 10;
    ev->a = a; ev->b = b; ev->c = c; ev->d = d; ev->e = e;
    ev->seq = seq;
    ev->f = f;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = seq + 1;
    return seq;
}

u8* func_00236ca8(void*, s32);

s32 func_00242a00(void);
void func_0023d1d0(void);  // set_global_word1
void func_0023d1e0(void);  // zero_global_d
s32 func_00242a68(void);
void func_002b6bc4(s32);

extern void* D_0035ee5c;
s32 func_002892f8(void*);
s32 func_0028acc8(void*);
void func_00288e88(void*);
void func_00252020(void) {
    if (!D_0035ee5c) return;
    s32 r = func_002892f8(D_0035ee5c);
    if (func_0028acc8(D_0035ee5c)) return;
    if (!r) return;
    func_00288e88(D_0035ee5c);
}

void* func_002570a0(u32);
u16* func_002632d0(void*);
u32 func_002811b0(void*, u32);
void func_001a2a50(u32, u32, u32, u32);
void func_001a3458(u32, u32);
void func_0013dbb0(void);
extern void* D_0035f010;

struct E283 { u8 _0[6]; u8 kind; u8 _7; };
extern E283 D_003742c8[];
extern s8* D_0035f2b4;
void func_002835a8(void);
void func_00283900(u32);
void func_00283e48(void) {
    s8* p = D_0035f2b4;
    s32 i = p[14];
    if (i + 1 >= p[13]) {
        func_002835a8();
        return;
    }
    func_00283900(D_003742c8[p[i + 4]].kind != D_003742c8[p[i + 5]].kind);
}

s32 func_00293fb0(void);
u32 func_00103570(void);
void func_00293e00(u32);
void func_00293fc0(void);
void func_00253b30(void*, u32);
void func_0023fa90(u32, void*);
extern u32 D_0035f2bc;
extern u32 D_0035f2c4;
void func_002853b8(void) {
    u8 buf[128];
    if (!func_00293fb0()) {
        func_00293e00(func_00103570());
        func_00293fc0();
    }
    func_00253b30(buf, D_0035f2bc);
    func_0023fa90(D_0035f2c4, buf);
}

s32 func_0028b1c0(void*, s32);  // test_bit_field32
void func_00289b30(void*, void*, void*);
void func_0028afd0(s16* p, s32 a) {  // obj_set_signed18
    p[9] = a;
    s32 v = (s16)a + p[0];
    if (((u8*)p)[37] == 0) {
        if (func_0028b1c0(p, v)) func_00289b30(p, p, p + 9);  // test_bit_field32
    }
}

extern u8* D_0035f638;
void func_0023f900(void*);
s32 func_00292630(void);
u8* func_00294000(u32);
void* func_00293db8(u32, void*);
void func_0023fa08(void*, void*);
void func_002b27c8(void) {
    func_0023f900(D_0035f638);
    if (func_00292630()) return;
    u8* v = func_00294000(9);
    void* x = func_00293db8(5, v + ((s8*)D_0035f638)[52] * 16 + 22);
    func_0023fa08(D_0035f638, x);
    *(u32*)(D_0035f638 + 52) |= 0x200;
}

extern u8* D_0035f634;
s32 func_00139d78(void*);
s32 func_002b2d48(void) {
    s32 r = 0;
    if (func_00139d78(D_0035f634 + 19992) || func_00139d78(D_0035f634 + 20400)) r = 1;
    return r;
}

extern u8 D_01e2a410[];
void func_002bcfe8(void*);
void func_002bd030(void*);
void func_002b6adc(u32, s32);
void func_002ba040(void) {
    func_002bcfe8(D_01e2a410);
    func_002bd030(D_01e2a410);
    for (s32 i = 0; i < 2; i++) {
        func_002b6adc(2, i + 20);
        func_002b6adc(0, i + 20);
    }
}

void* func_001c3748(void*, void*);
void func_00192048(u16);

u8* func_001b9bc8(void*);
void func_002d24e8(void*, void*);
void func_002d25f0(void* a) {
    u8* v = 0;
    while ((v = func_001b9bc8(v)) != 0) {
        if (*(u32*)(v + 1416) & 0x08000000) func_002d24e8(a, v);
    }
}

typedef s32 (*VFnB)(void*);
s32 func_002ee040(u8* p) {
    if (!(*(VFnB*)(*(u8**)p + 8))(p)) return 0;
    u8* c = *(u8**)(p + 8);
    s32 r = 1;
    while (c) {
        u8* next = *(u8**)(c + 32);
        s32 t = func_002ee040(c) != 0;
        if (!r) t = 0;
        r = t;
        c = next;
    }
    return r;
}

void func_002f3f88(void*, u32);  // memcpy16

s32 func_003160e0(void*, u32, u32, u32);
typedef s32 (*VFn4)(void*, u32, u32, u32);
s32 func_00316110(u8* a, u32 b, u32 c, u32 d) {
    if (func_003160e0(a, b, c, d)) return 1;
    u8* o = *(u8**)(a + 8);
    return (*(VFn4*)(*(u8**)o + 24))(o, b, c, d);
}

void func_00239870(void*);
extern u8 D_003485b0[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8* D_00347f80_p asm("D_00347f80");
typedef void (*VFn2)(void*, void*);
void func_0031b000(u8* p) {
    *(void**)p = D_003485b0;
    func_00239870(p + 436);
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    *(u8**)p = (u8*)D_00347f98;
    u8* o = *(u8**)(D_00347f80_p + 20);
    (*(VFn2*)(*(u8**)o + 4))(o, p);
}

void func_002361d0(void*);
extern u8 D_0034a800[];
extern u8 D_00348608[];
void func_0031b648(u8* p) {
    *(void**)p = D_00348608;
    *(void**)(p + 64) = D_0034a800;
    func_002361d0(p + 480);
    *(void**)(p + 64) = D_00347e60;
    func_00239870(p + 88);
    *(void**)(p + 64) = D_00347f98;
    *(void**)p = D_00347f98;
}
}

extern "C" void func_0013ee88(void*);
extern "C" { extern void* D_00349270; extern u8 D_00348698[]; }
void func_0014a868(int a, int b) {
    if (b == 0xffff && a == 1) func_0013ee88(&D_00349270);
    if (b == 0xffff && a == 0) D_00349270 = D_00348698;
}

extern "C" { extern f32 D_004f3600; extern u8 D_0034aa18[]; void func_00190128(void*); }
void func_00159c58(int a, int b) {
    if (b == 0xffff && a == 1) D_004f3600 = 1.04719746f;
    if (b == 0xffff && a == 1) func_00190128(D_0034aa18);
}
