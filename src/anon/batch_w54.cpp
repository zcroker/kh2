#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));

// 128-bit value with a self-checking lq/sq copy
struct Q16 {
    u128 v;
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
struct Q16Pair {
    Q16 v[2];
};

// VU0 helpers
static inline void vu0_sub(Q16& r, const Q16& a, const Q16& b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void vu0_add(Q16& r, const Q16& a, const Q16& b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void vu0_scale(Q16& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&v), "f"(s) : "$8", "memory");
}
// noreorder: the original keeps the following branch delay slot empty
static inline void vu0_scaled(Q16& r, const Q16& v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\t"
                 "vmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
}
// normalize xyz in place, returns the length
static inline f32 vu0_normalize(Q16& v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
// same, but the original leaves the jr ra delay slot empty
static inline f32 vu0_normalize_nr(Q16& v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}

// unions with a char member: the original was built without strict aliasing
union U32c {
    u32 v;
    u8 c;
};
union S32c {
    s32 v;
    u8 c;
};
union S16c {
    s16 v;
    u8 c;
};

extern "C" {

void func_00103ea0(s32);  // set_hook_ptr
extern void (*D_0032ba34)(void);
extern s32 D_0032ba04;
// run the registered hook if any, otherwise set the state to 3
void func_001039f8(void) {
    if (D_0032ba34) {
        D_0032ba34();
        func_00103ea0(0);  // set_hook_ptr
        return;
    }
    D_0032ba04 = 3;
}

struct Link64 {
    s16 a;
    u16 b;
    s16 c;
    u16 d;
    u8 pad[56];
};
// rebuild the link fields of a 64-byte record table
void func_0011ed90(Link64* p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        p[i].b = 0xffff;
        p[i].d = 0xffff;
    }
    for (i = 0; i < n; i++) {
        s16 c = p[i].c;
        s32 t = p[i].a - i;
        if (c >= 0 && c >= t) {
            Link64* q = (Link64*)((u8*)((c - t) * 64) + (u32)p);
            u16 tmp = q->d;
            q->d = i + t;
            p[i].b = tmp;
        }
    }
}

typedef s32 (*VFn124)(void*, s32, s32, s32, s32, s32, u8, s32);
void* func_00124748(void*, s32);  // list_nth_node_rel
s32 func_00124618(void* a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, u8 t2, s32 t3) {
    void* o = func_00124748(a0, 0);  // list_nth_node_rel
    return (*(VFn124*)((*(u8**)o) + 80))(o, a1, a2, a3, t0, t1, t2, t3);
}

struct Snd132 {
    u8 pad[2];
    u16 a;
    u16 b;
};
struct Obj132 {
    u8 pad[20];
    U32c flags;
    u8 pad2[632 - 24];
    Snd132* cur;
    Snd132* last;
    f32 len;
    u32 pos;
};
u32 func_00106520(u32, u32);
void func_00132720(Obj132* p, Snd132* s) {
    if (p->cur != s) {
        if (s) {
            p->flags.v |= 1;
            p->len = (f32)func_00106520(s->a, s->b + 1);
            p->pos = 0;
        }
        p->last = s;
        p->cur = s;
    }
}

s32 func_00143d10(Q16Pair*, Q16*, void*, s32*);
void func_00140480(Q16* p) {
    Q16Pair in;
    Q16 out;
    s32 x;
    s32 y;
    Q16* pi = &in.v[1];
    Q16* ps = p + 1;
    in.v[0] = p[0];
    *pi = *ps;
    y = 0;
    Q16* po = &out;
    s32* px = &x;
    if (func_00143d10(&in, po, px, &y)) *p = *po;
}

void func_001391c8(void*, s32, s32);
s32 func_0014fbf8(void*);
extern S16c D_0034a458[][3];
void func_0014fc40(u8* p, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1) {
    func_001391c8(p, a3, t0);
    D_0034a458[a1][t1].v = a2;
    *(s32*)(p + 24) = a1;
    *(s32*)(p + 28) = t1;
    s32 r = func_0014fbf8(p);
    *(s32*)(p + 36) = r;
    *(f32*)(p + 40) = *(f32*)(p + 44) = (f32)r;
}

void func_00159ce0(void*, Q16*);
// out = from + (to - from) * t
void func_00159d30(void* a0, const Q16* to, Q16* out, f32 t) {
    Q16 from;
    func_00159ce0(a0, &from);
    Q16 d;
    vu0_sub(d, *to, from);
    vu0_scale(d, t);
    Q16 r;
    vu0_add(r, from, d);
    *out = r;
}

void func_0015b7c0(void*, s32);
void func_0015c068(void*, s32);
void func_001664c0(u32);
void func_0015bbc8(u8* p, s32 a1) {
    func_0014fc40(p, 18, 0, 5000, 0, 1);
    func_0015b7c0(p + 48, a1);
    func_0015c068(p, a1);
    func_001664c0(*(u32*)(p + 2976));
    *(f32*)(p + 2992) = 1.0f;
    *(u8*)(p + 3024) = 1;
    *(u8*)(p + 3025) = 96;
}

s32 func_00177860(void);
s32 func_001c3618(s32, s32);
f32* func_001ce300(s32);  // to_1ce2a0_index_minus1
f32 func_0016c460(u8* p, S32c* out) {
    f32 r = *(f32*)(p + 280);
    out->v = 3;
    if (*(u32*)(p + 1416) & 4) {
        if (*(u32*)(*(u8**)(p + 12) + 8) & 0x800) return r;
        s32 k = func_001c3618(func_00177860(), 0);
        if (k > 0) {
            r = *func_001ce300(k);  // to_1ce2a0_index_minus1
            out->v = 201;
        }
    }
    return r;
}

void* func_0014aba8(void);
void func_0014aa58(void*, s32, s32);
void func_0016df28(f32* p) {
    s32 v = (s32)(*p * 0.5f);
    func_0014aa58(func_0014aba8(), v, 1);
}

s32 func_001a35f8(u32, s32);
void func_00194070(void*, u8);
extern u16 D_0036c4e8[3];
extern u8 D_0036c4f0[];
void func_0017a718(void* p) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 3; i++) n += func_001a35f8(D_0036c4e8[i], 100) > 0;
    func_00194070(p, D_0036c4f0[n]);
}

f32 func_0017ce10(f32);
f32 func_0017ce80(f32 a, f32 b, f32 c) {
    f32 d = b - a;
    f32 x;
    if (func_0017ce10(d) < -c) x = a - c;
    else if (c < func_0017ce10(d)) x = a + c;
    else x = a + func_0017ce10(d);
    return func_0017ce10(x);
}

f32 func_001db510(void*);
s32 func_0018c490(u8* p) {
    s32 r = 1;
    if (!*(u8*)(p + 49)) {
        void* q = *(void**)(p + 32);
        r = 0;
        if (q) {
            bool lt = *(f32*)(p + 44) < 0.5f;
            f32 v = func_001db510(q);
            r = 1;
            if (lt) {
                if (!(*(f32*)(p + 40) <= v)) r = 0;
            } else {
                if (!(v <= *(f32*)(p + 40))) r = 0;
            }
        }
    }
    return r;
}

struct Pair8 {
    u32 a;
    void* p;
};
extern Pair8 D_00350338[8];
void func_0016cce8(void*, void*, s32, s32, s32);
void func_00196aa0(void* a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < 8; i++) {
        void* o = D_00350338[i].p;
        if (o) func_0016cce8(o, a0, a1, a2, 0);
    }
}

void func_001c79a0(void*, void*, s32);
void func_001a52a8(void*, void*, void*);
void func_001a5380(void* a0, void* a1, void* a2) {
    func_001c79a0(a2, a1, 0);
    func_001a52a8(a0, a1, a2);
}

void func_00177998(void*);
void func_0016cbc8(void*, s32, s32, s32);
void func_001a6440(void** p) {
    if (*(u32*)((u8*)p[1] + 1416) & 4) func_00177998(p[1]);
    func_0016cbc8(p[0], 21, 0, 0);
}

s32 func_001a8f10(void*);  // arg_map_0_1_2
s32 func_001a8bf8(void*, s32);  // get_bits5_at
void func_001a8c60(void*, s32, s32);  // masked_byte_store
// move the entry matching a1 into slot 3, swapping with whatever was there
void func_001a8f68(void* a0, void* a1) {
    s32 v = func_001a8f10(a1);  // arg_map_0_1_2
    s32 i;
    for (i = 1; i < 3; i++) {
        if (func_001a8bf8(a0, i) == v) {  // get_bits5_at
            func_001a8c60(a0, i, func_001a8bf8(a0, 3));  // masked_byte_store
            break;
        }
    }
    func_001a8c60(a0, 3, v);  // masked_byte_store
}

void func_001ac970(void*, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_00350af0[];
void func_001ad1d0(u8* p, s32 a1) {
    func_001ac970(p, 3, 4, a1, 0, 256, 32, 3);
    *(s32*)(p + 104) = 0;
    *(s32*)(p + 100) = 2;
    *(void**)p = D_00350af0;
}

void func_001b08e8(u8* p, const Q16* v) {
    Q16* d = (Q16*)(p + 32);
    *d = *v;
    vu0_normalize_nr(*d);
}

void func_001c0ae0(void*);
void func_001c0ca0(s32);
extern u8 D_01d49368[];
extern void* D_00351338;
extern s32 D_01d4937c;
extern u8 D_0032bae0;
void func_001c0a00(s32 a) {
    if (a == 0) {
        func_001c0ae0(D_01d49368);
        D_00351338 = D_01d49368;
        D_01d4937c = D_01d49368[D_0032bae0];
    } else {
        D_01d4937c = a;
        D_00351338 = 0;
    }
    asm volatile("" ::: "memory");
    if (D_01d4937c == 0) {
        D_01d4937c = 1;
        asm volatile("" ::: "memory");
    }
    func_001c0ca0(D_01d4937c);
}

extern void* D_003520c0;
extern u8 D_0036e278[][16];
u8* func_001a5420(void*, void*, void*);
void func_001ccf18(void* a0, s32 a1, s32 n) {
    if (D_003520c0) {
        s32 i;
        for (i = 0; i < n; i++) {
            u8* r = func_001a5420(D_003520c0, D_0036e278[a1], a0);
            *(u32*)(r + 40) |= 4;
        }
    }
}

s32 func_001db9a8(void*, s32, s32);
void* func_001050d8(u32);
void func_001ce3e8(void*, s32, void*, void*, f32);
void* func_001ce488(void* a0, void* a1, f32 f) {
    s32 h = func_001db9a8(a0, 0, 1000);
    void* o = func_001050d8(2560);
    func_001ce3e8(o, h, a0, a1, f);
    return o;
}

void func_002f4000(f32*);  // vu_store_w_splat
void func_002f3d08(void*, f32*, void*);
extern u8* D_01d9e6e0;
extern u8* D_01d9e6e8;
// scale matrix built from two clamped factors
void func_001eb030(void* a0, f32* s) {
    f32 m[16];
    func_002f4000(m);  // vu_store_w_splat
    f32 k = s[1];
    f32 mx = s[2];
    u8* t = D_01d9e6e0;
    f32 x = *(f32*)(t + 64);
    m[0] = x + x * k;
    if (mx < m[0]) m[0] = mx;
    m[10] = m[0];
    f32 y = *(f32*)(t + 68);
    m[5] = y + y * k;
    if (mx < m[5]) m[5] = mx;
    func_002f3d08(D_01d9e6e8 + 16, m, D_01d9e6e8 + 16);
}

// VU0 random float in [0,1) (R register); one or two samples
f32 func_001ee5d8(u8 two) {
    f32 r, r2;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    if (two) {
        asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                     : "=r"(r2) : : "$8");
        return r + r2;
    }
    return r + r;
}

struct Obj232 {
    u8 pad[20];
    u32 id;
    u8 pad2[24];
    char name[16];
};
Obj232* func_00227a60(void*, s32);
char* func_00232498(void*);
char* func_002ff2e8(char*, const char*);
u32 func_00227870(char*, void*, void*);
void func_00226030(void);
void func_00168388(char*, u32, void*, void*);
void func_00232510(void* a0, void* a1) {
    Obj232* s = func_00227a60(a0, 3);
    func_002ff2e8(s->name, func_00232498(a0));
    s->id = func_00227870(s->name, s, a1);
    func_00168388(s->name, s->id, (void*)func_00226030, s);
}

s32 func_0024dfe0(void);
s32 func_00139d78(void*);
struct Obj408 {
    void** vtbl;
    u8 pad[404];
};
extern Obj408* D_0035ede8;
void func_0024e530(void) {
    s32 i;
    for (i = 0; i < func_0024dfe0(); i++) {
        if (func_00139d78(&D_0035ede8[i])) {
            Obj408* o = (Obj408*)((u8*)(i * 408) + (u32)D_0035ede8);
            ((void (*)(Obj408*))o->vtbl[5])(o);
        }
    }
}

extern u8* D_0035ee18[5];
void func_00138c10(void*, s32);
void func_0024eac0(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (D_0035ee18[i]) {
            if (func_00139d78(D_0035ee18[i])) {
                if (*(s32*)(D_0035ee18[i] + 388) != 2) {
                    func_00138c10(D_0035ee18[i], 2);
                    *(s32*)(D_0035ee18[i] + 392) = -1;
                }
            } else {
                D_0035ee18[i] = 0;
            }
        }
    }
}

u8* func_002632d0(void);
s32 func_002635d8(void) {
    s8 tbl[3] = {0, 1, -1};
    s32 r = 0;
    u8* v = func_002632d0();
    u8 c = v[2];
    s32 i;
    for (i = 0; tbl[i] >= 0; i++) {
        if (c == tbl[i]) {
            r = 1;
            break;
        }
    }
    return r;
}

extern u8* D_0035f480;
void func_00139510(void*);
s32 func_0028d6e8(void*);
// Tz::JmStory::LeaveAllPost(...)
void JmStory_LeaveAllPost(s32 i) asm("_ZN2Tz7JmStory12LeaveAllPostEz");
void JmStory_LeaveAllPost(s32 i) {
    if (!D_0035f480) return;
    s32 off = i * 884;
    if (func_00139d78(D_0035f480 + off)) func_00139510(D_0035f480 + off);
    if (func_0028d6e8(D_0035f480 + off + 436)) func_00139510(D_0035f480 + off + 436);
}

struct Bits2aa {
    u8 pad[148];
    u32 bits[6];
};
extern Bits2aa* D_0035f610;
static inline s32 bit_test(u32* b, u32 i) {
    return (b[i >> 5] & (1 << (i & 31))) != 0;
}
// test flag n; n < 0 tests whether any of the 192 flags is set
s32 func_002aacd8(s32 n) {  // test_bit_global_d
    if (n < 0) {
        s32 r;
        s32 i;
        u32* b = D_0035f610->bits;
        for (i = 0; i < 192; i++) {
            r = bit_test(b, i);
            if (r) break;
        }
        return r;
    }
    return bit_test(D_0035f610->bits, n);
}

void func_002cf2b0(void*, s32);
void func_0017f488(void*, s32, f32, f32);
struct Flags108 {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 5;
    u32 b7 : 1;
    u32 b8 : 2;
    u32 b10 : 1;
    u32 rest : 21;
};
void func_002d0d88(u8* p) {
    func_002cf2b0(p + 2800, 4);
    ((Flags108*)(p + 264))->b0 = 0;
    ((Flags108*)(p + 264))->b1 = 0;
    ((Flags108*)(p + 268))->b7 = 0;
    (*(void (**)(void*))(*(u8**)p + 124))(p);
    ((Flags108*)(p + 264))->b10 = 0;
    func_0017f488(p + 320, 0, 0.0f, 0.0f);
}

struct Vec4f {
    f32 x, y, z, w;
};
void func_002d00a0(void*);
s32 func_00181500(s32);
void func_0016bd60(void*, s32);
void func_0016b070(void*, void*);
void func_002db968(void*, s32);
extern u8 D_003628f0[];
void func_002dba40(u8* p) {
    func_002d00a0(p);
    Vec4f v;
    bool off = func_00181500(9271) == 0;
    D_003628f0[1] = 21 - off;
    func_0016bd60(p, 3);
    v.w = v.z = v.y = v.x = 0.0f;
    ((U32c*)(p + 264))->v |= 1;
    func_0016b070(p, &v);
    *(f32*)(p + 3056) = 0.0f;
    func_002db968(p, 1);
}

// wrap an angle into [-pi, pi]
f32 func_002de968(f32 a) {
    if (a > 0.0f) {
        if (a > 3.1415927f) {
            do a -= 6.2831855f;
            while (a > 3.1415927f);
        }
    } else {
        while (a < -3.1415927f) a += 6.2831855f;
    }
    return a;
}

struct Glob363 {
    u8 pad[16];
    f32 a, b;
};
extern Glob363 D_00363630;
void func_002ed1d8(u8* p, Q16* v, f32 a, f32 b) {
    D_00363630.a = a;
    D_00363630.b = b;
    f32 w = ((f32*)v)[3];
    vu0_normalize(*v);
    Q16* dst = (Q16*)(p + 32);
    Q16 t;
    vu0_scaled(t, *v, w);
    *dst = t;
    func_0016bd60(p, 42);
}

extern u8 D_01e2c080[];
extern u8 D_00363808[];
extern u8 D_003637e0[];
void func_00325840(void*, void*);
void func_00106420(void*);
// destructor: unregister from the list at D_01e2c080, then the base destructor
void func_002ee448(void** p) {
    *(u32*)p = (u32)D_00363808;
    func_00325840(D_01e2c080, p);
    *p = D_003637e0;
    func_00106420(p);
}

void* func_00102788(void*, void*, void*, void*);
void func_002ef928(void);
void func_002ef8d0(void** p, void* a1) {
    if (!p[3]) {
        void** r = (void**)func_00102788(a1, p[0], p[1], p[2]);
        p[3] = r;
        r[1] = p;
        ((void**)p[3])[12] = (void*)func_002ef928;
    }
}

s32 func_003060f0(void);  // ee_intr_disabled
s32 func_0030edb0(void);
extern s32 D_003660a8;
extern s32 D_003660ac;
void func_002fded8(void) {
    if (func_003060f0() != 1) {  // ee_intr_disabled
        if (D_003660a8 == 0) D_003660ac = func_0030edb0();
        D_003660a8++;
    }
}

}
