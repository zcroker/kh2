#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));

struct Q16 {
    u128 v;
    Q16() {}
    Q16(const Q16& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};

struct Q16Pair {
    Q16 v[2];
};

struct E1a5 { f32 f; u8 b4, b5, b6, b7; };

typedef s32 (*VF4)(void*, u8, s32, s32);

typedef void (*VF0)(void*);

typedef s32 (*VF24)(void*, f32*, f32);

struct S1c2 {
    u32 w[8];
    u8 b32[5];
    u8 pad37[3];
    u32 f40;
    u8 b44, b45, b46, b47;
    u8 b48;
    u8 pad49[3];
    u32 f52;
    f32 f56, f60, f64;
    s16 h68, h70, h72, h74, h76, h78, h80, h82;
    u32 f84, f88;
    f32 f92, f96;
    u32 f100, f104;
    f32 f108, f112;
    u32 f116;
};

typedef u8* (*AllocFn)(void*, s32, s32);

struct Ent8 { u32 id; u32 v; };

struct Rec40 { struct Ent8 e[5]; };

typedef void (*DtorFn)(void*);

typedef void (*FreeFn)(void*, void*);

struct S2bb { u8 pad0[16]; u32 f16; u32 f20; u32 f24; u8 pad28[12]; s16 h40; s16 pad42; s16 h44; u8 pad46[2]; u8 state; };

struct E16 { s8 id; u8 pad[15]; };

struct T294 { u8 pad[8]; s32 n; u8 pad12[4]; struct E16 e[1]; };

struct OBv { u32 f0; volatile s32 f4; s32 f8; volatile s32 f12; u8 pad16[32]; volatile s32 f48; u8 pad52[12]; Q16 v64; s32 f80; };

struct VB { u16 a, b, c, d; };

struct K36 { s16 h0; u8 pad[18]; s16* f20; u8 pad24[12]; };

struct KE { s16 h0; s16 h2; u16* f4; };

struct KG { u8 pad[16]; struct K36* f16; u8 pad20[4]; struct KE* f24; };

extern "C" {
void func_001ae590(void*, u32);
void func_001ae4c0(u32, u32, void*);
char** func_00105c48(s32);
s32 func_002ff538(const void*, const void*, u32);
void func_00105af8(s32);
extern u32 D_0033caf8;
void func_0013a6f8(void);
void func_00103bb0(s32);
u32 func_001050c8(void);
void func_00139f38(u32);
extern u32 D_0034b278;
void func_00153c60(void);
void func_001385c0(void);
void func_00109e18(void);
void func_0015df68(void);
void func_00140ce8(void);
void func_00161ee8(void);
void func_001618f0(void);
void func_001618b8(void);
void func_0015a810(void);
extern u8 D_00348d68[];
void func_0014f268(void*);
void func_0014f1c8(void*);
void func_0014f208(void);
void func_0014f118(void);
void func_0013d7d0(void);
extern char D_0032bae0[];
extern char D_0032bb10[];
s32 func_001051a0(const char*, const char*);
s32 func_001bc130(void);
void func_0015b2d0(void);
void func_0013d7c0(void);
void func_00192290(u8, s32);
void func_001ac778(void);
void func_001b8348(void);
void func_0016c750(u32);
void func_001900d0(void);
void func_001b9230(void);
void func_0017dec0(void);
void func_00185d98(void);
void func_001aeae0(void);
void func_00196a40(void);
void func_001a0bc0(void);
void func_0018d738(void);
void func_001a5f50(void);
void func_00199548(void);
void func_001a6a10(void);
void func_001b14d8(void);
void func_0019ec20(void);
void func_001b4300(void);
void func_00179be8(void);
void func_001c8a90(void);
void func_001d3b60(void);
void func_001d5a48(void);
void func_001a3a88(void);
void func_001ba718(void);
void func_001a5928(void);
void func_001b24c0(void);
void func_00182b18(void);
s32 func_00143d10(Q16Pair*, Q16*, void*, s32*);
Q16* func_0016c028(void*);
s32 func_0019b3d0(void*, Q16*);
void func_0018c438(void*);
s32 func_0019b308(void*);
void func_0018c650(void*, Q16*, u32, s32, s32, f32, f32);
extern s32 D_0035037c;
s32 func_00197028(s32);
void func_00196e00(void*);
void func_00105110(void*);
extern s32 D_01c61b40;
s32 func_001991a8(s32, s32);
void func_001024a8(void*);
extern struct E1a5 D_0036d578[];
void func_00176be0(void*, f32);
void func_00187650(void*, u8, s32);
void func_00179a68(void*, f32);
void func_001d6110(u8, void*);
void func_0014f668(u8);
void func_00242500(u8);
s32 func_002f79c8(s32);
s32 func_002f7be8(u32, u32, void*, void*);
void func_001ae678(void);
void func_001ae620(void);
s32 func_002f7dc8(void);
void func_001ae650(void);
extern u8 D_00350ca0[];
extern s32 D_00350c88;
s32 func_00139d78(u32);
extern u32 D_0035ed00;
extern u8* D_0035ed10;
extern u32 D_0035ece8;
void func_002fde18(void*, s32, u32);
u32 func_002891e8(u32);
s32 func_00244ee8(u32);
void func_00139858(s32);
void func_001398d0(s32);
u8* func_001d56c8(s32);
u32 func_00192cc0(u8*, void*, u32);
s32 func_00192b30(u32);
u32 func_00192048(u16);
void func_00192c90(u32, u8*);
extern u8 D_00371958[];
s32 func_00257070(s32);
s32 func_00257088(s32);
s32 func_0028afa8(u32);
s32 func_002892f8(u32);
void func_002891f0(u32, s32, s32, s32, s32);
void func_0028afd0(u32, s32);
extern u32 D_0035f01c;
void func_00178cf8(void*, void*);
void func_00178cf8_1(void*) asm("func_00178cf8");
u32 func_0016a020(u32);
s32 func_002c5d38(void*, u32);
void func_002c8648(void);
void func_002ca0a8(void);
void func_00190388(Q16*, void*);
void func_0016aef0(void*, Q16*);
void func_002c5190(void*);
void func_002c17a0(void);
extern void* D_00361f60;
u8* func_002d1878(void*);
void func_00187750(void*);
extern f32 D_00349e10;
f32 func_002f8870(f32);
void func_00144450(f32*);
void func_001b7c80(void*, f32*);
void func_0016af58(Q16*, void*);
s32 func_00180cd0(void*);
f32 func_002f8ad0(f32, f32);
extern u8* D_00347f80;
extern u8 D_0035e050[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
void func_0031a838(void*);
void func_00239700(void*);
void func_00228ab0(void*);
extern u8 D_0035e340[];
extern u8 D_00347e80[];
void func_002361a0(void*);
void func_0022bda0(void*, s32, s32);
extern s32 D_0035de64;
extern s32 D_0035f680[];
extern struct Rec40* D_0035f660;
u32* func_002b6118(u32);
void func_001a98e8(void*, s32, u32, s32, u32);
void func_001a9ae8(void*, s32, s32, s32);
extern u8 D_0035e238[];
void func_00239870(void*);
void func_0031a840(void*);
void func_002bb8b0(void*);
void func_002b7c34(u32, u32, s16, s16);
s32 func_002bb510(void*);
void func_002bb5f8(void*);
void func_002b7cec(u32, u32, s16, s16);
void func_002bc358(u32, s32);
extern s32 D_0034dcc0[];
extern s32 D_0034dcc8[];
s32 func_0016ffc8(void*);
u8* func_00189200(void*, s32);
s32 func_001d62b0(void*, void*);
s32 func_001917c0(void);
s32 func_001d63a8(void*);
void func_001a32c8(s32, s32);
extern u8* D_00352130;
extern u8 D_0032e020[];
struct T294* func_00294000(s32);
s32 func_002941a8(void*);
s32 func_00276c18(void);
void* func_0016bc20(u32, s32, s32);
void func_001ad990(void*, f32, f32, f32);
extern struct KG* D_01d9e6e4;
union FH { f32 f; s16 h; };
void func_002f3cd8(union FH*, void*, union FH*);
void* func_0014e638(void*);
void* func_0014e648(void*);
void func_00166968(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0014db78(void*, s32, s32, s32, s32, s32, s32);
void func_0014dd60(void*, s32, s32, s32);
void func_0014dda0(void*, s32);
void func_0014dd18(void*);
void func_0014e2c0(void*);
void func_00102788(u32, s32, s32, void (*)(void));
void func_0014df48(void);
extern u8 D_00349f00[];
extern u32 D_0032b91c;
void func_00157990(u32);
void func_00138c10(u32, u32);
u32 func_00155d58(u32, s32);
void func_001543a0(u32, s32, u32);
s32 func_001581a8(u32);
s32 func_002ba358(void);
void func_002ba368(void);

static inline void vu0_scaled(Q16& r, const Q16& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\t"
                 "vmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
}

static inline void vu0_sub(Q16& r, const Q16& a, const Q16& b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}

static inline void vu0_normalize_f1(Q16& v) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f1\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&v) : "$8", "$f1", "memory");
}

static inline bool is_up(u8* o) { return *(f32*)(o + 52) > 0.0f; }

static inline u8* alloc_obj(s32 size) {
    u8* a = *(u8**)(D_00347f80 + 20);
    return (**(AllocFn**)a)(a, size, 0);
}

static inline bool is_big(s32 id) { return id >= 10000; }

static inline void sub_clamp(u8* e, s32 d) {
    s32 x = *(s32*)(e + 4) - d;
    if (x < 0) x = 0;
    *(s32*)(e + 4) = x;
}

void func_00105b58(void) {
    u32 info[12];
    u8 buf[2048];
    s32 i;
    func_001ae590(info, D_0033caf8);
    func_001ae4c0(info[0], (info[1] + 2047) >> 11, buf);
    for (i = 1; i < 9; i++) {
        if (func_002ff538(buf + 16, func_00105c48(i)[0], 4) == 0 &&
            func_002ff538(buf + 21, func_00105c48(i)[1], 3) == 0 &&
            func_002ff538(buf + 25, func_00105c48(i)[2], 2) == 0) {
            func_00105af8(i);
            return;
        }
    }
}

void func_00149cb8(void) {
    func_0013a6f8();
    func_00103bb0(-1);
    func_00139f38(func_001050c8());
    D_0034b278 = func_001050c8();
    func_00153c60();
    func_001385c0();
    func_00109e18();
    func_0015df68();
    func_00140ce8();
    func_00161ee8();
    func_001618f0();
    func_001618b8();
    func_0015a810();
    func_0014f268(D_00348d68);
    func_0014f1c8(D_00348d68);
    func_0014f208();
    func_0014f118();
    func_0013d7d0();
    if (func_001051a0(D_0032bae0, D_0032bb10) == 0 && func_001bc130() != 0) {
        func_0015b2d0();
        func_0013d7c0();
    }
}

void func_00169210(void) {
    func_00192290(D_0032bae0[0], 2);
    func_001ac778();
    func_001b8348();
    func_0016c750(func_001050c8());
    func_001900d0();
    func_001b9230();
    func_0017dec0();
    func_00185d98();
    func_001aeae0();
    func_00196a40();
    func_001a0bc0();
    func_0018d738();
    func_001a5f50();
    func_00199548();
    func_001a6a10();
    func_001b14d8();
    func_0019ec20();
    func_001b4300();
    func_00179be8();
    func_001c8a90();
    func_001d3b60();
    func_001d5a48();
    func_001a3a88();
    func_001ba718();
    func_001a5928();
    func_001b24c0();
    func_00182b18();
}

void func_00159240(Q16* out, Q16* in) {
    s32 y = 0;
    Q16 x;
    Q16 lo = *in;
    Q16 hi = *in;
    Q16Pair seg;
    Q16* ph = &seg.v[1];
    ((f32*)&lo)[1] -= 100.0f;
    ((f32*)&hi)[1] += 10000.0f;
    seg.v[0] = lo;
    *ph = hi;
    if (!func_00143d10(&seg, out, &x, &y)) *out = *in;
}

void func_0018b7f8(u8* p) {
    Q16 pos = *func_0016c028(p);
    void* t;
    s32 id;
    ((f32*)&pos)[1] -= 10.0f;
    t = *(void**)(p + 2072);
    if (t == 0) return;
    id = func_0019b3d0(t, &pos);
    if (id == *(s32*)(p + 2608)) return;
    {
        u8* q = p + 2624;
        if (q[48] == 0) {
            func_0018c438(q);
            if (id != 0) {
                Q16* v = func_0016c028(p);
                void* tt = *(void**)(p + 2072);
                u32 k = *(u16*)(*(u8**)((u8*)tt + 8) + 10);
                func_0018c650(q, v, k, func_0019b308(tt), id, *(f32*)(p + 2856), *(f32*)(p + 2860));
            }
        }
    }
    *(s32*)(p + 2608) = id;
}

void func_00197a00(void* a) {
    if (D_0035037c != 0) {
        u8* o;
        u8 flag;
        if (func_00197028(D_0035037c) != 0) return;
        o = (u8*)D_0035037c;
        flag = *(volatile u16*)(*(u8**)(o + 60) + 2) & 1;
        if (o != 0) {
            func_00196e00(o);
            func_00105110(o);
        }
        if (flag && func_001991a8(76, D_01c61b40++) != 0) return;
    }
    func_001024a8(a);
}

void func_001a52a8(void* a0, void** o, u8* c) {
    struct E1a5* e = &D_0036d578[c[20]];
    if (e->f > 0.0f) func_00176be0(o, e->f);
    if (e->b4) (*(VF4*)((u8*)*o + 120))(o, e->b4, 0, 0);
    if (e->b5) func_00187650(o, e->b5, 0);
    if (e->b6) {
        func_00179a68(o, e->b6);
        func_001d6110(e->b6, o);
    }
    if (e->b7) {
        func_0014f668(e->b7);
        func_00242500(e->b7);
    }
}

void func_001ae4c0(u32 a, u32 b, void* c) {
    for (;;) {
        if (func_002f79c8(1) != 2 || func_002f7be8(a, b, c, D_00350ca0) != 1) {
            func_001ae678();
            continue;
        }
        func_001ae620();
        if ((D_00350c88 = func_002f7dc8()) == 0) break;
        func_001ae650();
    }
}

void func_00244b38(void) {
    u8* buf;
    u8* p;
    if (func_00139d78(D_0035ed00) == 0) return;
    func_002fde18(D_0035ed10, 0, 32);
    if (func_00244ee8(func_002891e8(D_0035ece8)) == 0) func_001398d0(100);
    else func_00139858(100);
    buf = D_0035ed10;
    p = func_001d56c8(8);
    if (*p != 3) {
        func_00192c90(func_00192048(0xcb9b), buf);
    } else {
        s32 n = func_00192b30(func_00192cc0(buf, D_00371958, *(u32*)(p + 4)));
        func_00192c90(func_00192048(0xcb98), buf + n);
    }
}

void func_0027c2f8(void) {
    s32 sel = func_00257070(16);
    s32 top = func_00257088(16);
    s32 cnt = func_0028afa8(D_0035f01c);
    s32 vis = func_002892f8(D_0035f01c);
    if (cnt < top + vis) top = vis < cnt ? cnt - vis : 0;
    if (!(vis < cnt) && !(sel < cnt)) {
        sel = cnt - 1;
        top = 0;
    }
    func_002891f0(D_0035f01c, sel, 0, -1, -1);
    func_0028afd0(D_0035f01c, top);
}

void func_002c5c50(void* a, u32* b) {
    func_00178cf8_1(a);
    if (func_002c5d38(a, func_0016a020(*b)) != 0) {
        func_002c8648();
        func_002ca0a8();
        return;
    }
    {
        Q16 d;
        Q16 t;
        func_00190388(&t, b);
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&d), "r"(&t), "r"(func_0016c028(a)) : "memory");
        ((s32*)&d)[1] = 0;
        asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                     "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\t"
                     "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                     "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&d) : "$8", "$f0", "memory");
        func_0016aef0(a, &d);
        func_002c5190(b);
        func_002c17a0();
    }
}

// Interpolates between two keys by the current time.
f32 func_002d60e8(u8* p) {
    void* o = D_00361f60;
    u8* a = func_002d1878(o);
    u8* b = func_002d1878(o);
    u8* c = func_002d1878(o);
    u8* d = func_002d1878(o);
    f32 x = *(f32*)(p + 2868);
    f32 k = *(f32*)(b + 160);
    f32 w;
    if (x < k) return *(f32*)(a + 156);
    w = *(f32*)(c + 164);
    if (x < k + w) {
        f32 t = (x - k) / w;
        return *(f32*)(a + 156) * (1.0f - t) + *(f32*)(d + 168) * t;
    }
    return *(f32*)(d + 168);
}

void func_002daee8(u8* p) {
    f32 v;
    func_00187750(p);
    if (p[2840] == 0) return;
    *(f32*)(p + 2864) += *(f32*)(p + 2848) * D_00349e10;
    *(f32*)(p + 2868) += *(f32*)(p + 2852) * D_00349e10;
    v = *(f32*)(p + 2852) - D_00349e10 * 0.16666666f;
    *(f32*)(p + 2852) = v;
    if (v < 0.0f) {
        if (func_002f8870(*(f32*)(p + 2868) < 0.1f ? 1.0f : 0.0f) == 0.0f) return;
        p[2840] = 0;
        (*(VF0*)(*(u8**)p + 32))(p);
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 2864) : "memory");
    }
}

Q16* func_002d38e8(Q16* out, u8* o) {
    if (*(void**)(o + 1296) != 0) {
        f32 m[6];
        func_00144450(m);
        func_001b7c80(*(void**)(o + 1296), m);
        Q16 s;
        Q16 r;
        ((f32*)&s)[3] = 0.0f;
        ((f32*)&s)[0] = m[0] + m[3];
        ((f32*)&s)[1] = m[1] + m[4];
        ((f32*)&s)[2] = m[2] + m[5];
        vu0_scaled(r, s, 0.5f);
        *out = r;
        ((s32*)out)[2] = 0;
    } else {
        *out = *func_0016c028(o);
        ((s32*)out)[2] = 0;
    }
    return out;
}

// Flat (y = 0) unit direction from the target to the actor, or the reversed facing.
Q16* func_0018d840(Q16* out, u8* o, void* a) {
    if (*(u8**)(o + 12) != 0) {
        Q16 d;
        vu0_sub(d, *func_0016c028(a), *(Q16*)(*(u8**)(o + 12) + 1840));
        *out = d;
        ((s32*)out)[1] = 0;
        vu0_normalize_f1(*out);
        ((f32*)out)[3] = 1.0f;
    } else {
        Q16 d;
        Q16 t;
        func_0016af58(&t, a);
        vu0_scaled(d, t, -1.0f);
        *out = d;
    }
    return out;
}

f32* func_0017fe10(f32* out, u8* o, f32 t) {
    f32 m[16];
    u8* c;
    if (t < 0.0f) t = *(f32*)(o + 48);
    if (func_00180cd0(o) != 0 || is_up(o) ||
        (c = *(u8**)(o + 12), (*(VF24*)(*(u8**)c + 24))(c, m, t) != 0)) {
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
        return out;
    }
    out[1] = -m[13];
    out[0] = m[12];
    out[2] = -m[14];
    out[3] = -func_002f8ad0(m[8], m[10]);
    return out;
}

void func_001c2f90(struct S1c2* p, u32 a) {
    s32 i;
    p->f40 = a;
    for (i = 0; i < 8; i++) p->w[i] = 0;
    for (i = 0; i < 5; i++) p->b32[i] = 0;
    p->f52 = 0;
    p->b45 = 3;
    p->b46 = 1;
    p->f56 = 1.0f;
    p->f60 = 1.0f;
    p->f64 = 1.0f;
    p->b48 = 0;
    p->h68 = 100;
    p->h70 = 100;
    p->f84 = 0;
    p->f88 = 0;
    p->f92 = 1.0f;
    p->f96 = 1.0f;
    p->f100 = 0;
    p->f104 = 0;
    p->h74 = 0;
    p->h76 = 0;
    p->h78 = 0;
    p->h80 = 0;
    p->f108 = 1.0f;
    p->b44 = 3;
    p->b47 = 1;
    p->h72 = 100;
    p->f112 = 1.0f;
    p->h82 = 0;
    p->f116 = 0;
}

void func_00228e58(void) {
    u8* v = alloc_obj(1260);
    u8* e;
    s32 i;
    *(u32*)(v + 12) = 0;
    *(u32*)v = (u32)D_0035e050;
    e = v + 24;
    for (i = 2; i != -1; i--) {
        *(u32*)e = (u32)D_00347f98;
        func_0031a838(e + 12);
        *(u32*)e = (u32)D_00347e60;
        func_00239700(e + 24);
        e += 408;
    }
    func_00228ab0(v);
}

void func_0022c108(void) {
    s32 m = D_0035de64;
    s32 mode;
    u8* v;
    if (m == 0) return;
    mode = 0;
    if (m != 1) mode = m == 2 ? 5 : 0;
    D_0035de64 = 0;
    v = alloc_obj(880);
    *(u32*)v = (u32)D_00347f98;
    func_0031a838(v + 12);
    *(u32*)v = (u32)D_00347e60;
    func_00239700(v + 24);
    *(u32*)(v + 416) = (u32)D_00347f98;
    *(u32*)v = (u32)D_0035e340;
    func_0031a838(v + 428);
    *(u32*)(v + 416) = (u32)D_00347e80;
    func_002361a0(v + 448);
    func_0022bda0(v, mode, 0);
}

void func_002b6138(s32 x, s32 y, s32 a2, s32 a3, s32 key) {
    u8 buf[96];
    s32 i;
    s32 n = -1;
    struct Ent8* e;
    for (i = 0; i < 4; i++) {
        if (D_0035f680[i] == key) {
            n = i;
            break;
        }
    }
    e = D_0035f660[n].e;
    for (i = 0; i < 5; i++, e++) {
        u32* s;
        if (e->v == 0) break;
        s = func_002b6118(e->id);
        func_001a98e8(buf, 1, e->v, 14, s[2]);
        func_001a9ae8(buf, s[0] + x, s[1] + y, a3);
    }
}

// Deleting destructor: tears down the member arrays, then frees through the allocator.
void func_00322608(u8* p) {
    u8* q;
    u8* a;
    *(u32*)p = (u32)D_0035e238;
    *(u32*)(p + 5072) = (u32)D_00347e60;
    q = p + 5072;
    func_00239870(p + 5096);
    *(u32*)(p + 5072) = (u32)D_00347f98;
    if (p + 1680 != 0) {
        u8* b = p + 1680;
    l1:
        if (b == q) goto d1;
        q -= 848;
        (*(DtorFn*)(*(u8**)q + 12))(q);
        goto l1;
    }
d1:
    if (p + 440 != 0) {
        u8* b;
        q = p + 1676;
        b = p + 440;
    l2:
        if (b == q) goto d2;
        q -= 412;
        (*(DtorFn*)(*(u8**)q + 12))(q);
        goto l2;
    }
d2:
    *(u32*)p = (u32)D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    a = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)a + 4))(a, p);
}

void func_002bbbc8(struct S2bb* p) {
    switch (p->state) {
    case 0:
        break;
    case 1:
        func_002bb8b0(p);
        func_002b7c34(p->f24, p->f16, p->h40, p->h44);
        p->state = 2;
        break;
    case 2:
        if (func_002bb510(p) == 0) {
            func_002bc358(p->f20, 1);
            break;
        }
        func_002bb5f8(p);
        func_002bb8b0(p);
        func_002b7cec(p->f24, p->f16, p->h40, p->h44);
        break;
    case 3:
        func_002bc358(p->f20, 1);
        break;
    }
}

void func_00170018(u8* p) {
    s32 i = 0;
    s32 id = *(s32*)(p + 40);
    s32 v;
    if (!is_big(id)) {
        for (; i < 2; i++) {
            if (id == D_0034dcc0[i]) { *(s32*)(p + 40) = 29000; return; }
        }
        i = 0;
        v = func_0016ffc8(p);
        *(s32*)(p + 40) = v;
        for (; i < 13; i++) {
            if (v == D_0034dcc8[i]) { *(s32*)(p + 40) = i + 15400; return; }
        }
        if (v >= 0) *(s32*)(p + 40) = v + 10000;
        else *(s32*)(p + 40) = 30000;
    } else if (id < 30000) {
        *(s32*)(p + 40) = id + 50;
    }
}

s32 func_001d61b8(void* a, s32 b) {
    u8* e = func_00189200(D_0032e020, 6);
    if (b == 5) {
        sub_clamp(e, *(s32*)(D_00352130 + 164));
        return 5;
    }
    if (!func_001d62b0(a, e)) return b;
    if (!func_001917c0()) return b;
    if (func_001d63a8(a)) {
        func_001a32c8(29, 1);
        sub_clamp(e, *(s32*)(D_00352130 + 164));
        return 5;
    }
    sub_clamp(e, *(s32*)(D_00352130 + 144));
    return 6;
}

s32 func_002952f8(s32 id) {
    s32 i = 0;
    s32 k = -1;
    s32 r = -1;
    struct T294* t = func_00294000(0);
    struct E16* e = t->e;
    for (; i < t->n; i++) {
        if (e[i].id < 20 && (func_002941a8(&e[i]) != 0 || func_00276c18() != 0)) {
            k++;
            if (e[i].id == id) {
                r = k;
                break;
            }
        }
    }
    return r;
}

void func_001b0798(OBv* o, s32 a, s32 b, f32 t) {
    VB* v;
    Q16 tmp;
    if (*(s32*)((u8*)o + 12) < 0) return;
    v = (VB*)func_0016bc20(o->f0, 20, -1);
    if (v == 0) return;
    {
    Q16* d = &o->v64;
    o->f12 = v->d;
    o->f4 = 2;
    o->f48 = a;
    func_0016af58(&tmp, (void*)a);
    *d = tmp;
    }
    *(f32*)&o->f80 = 0.0f;
    func_001ad990(&o->f8 + 2, *(f32*)&o->f80, 1.0f, t);
    o->f8 = b;
}

void func_001e9c28(u8* base, u8* a1, u8* a2) {
    union FH v[4];
    s32 k = *(s16*)(a1 + 12);
    if (k >= 0) {
        s32* offs = *(s32**)(a2 + 12);
        u8* src = base + offs[0];
        u8* dst = base + offs[1];
        struct KE* e = &D_01d9e6e4->f24[k];
        s16* p = D_01d9e6e4->f16[e->h0].f20 + e->f4[*(u16*)(src + 160)] * 3;
        volatile f32* d = (volatile f32*)(dst + 160);
        v[0].f = p[0];
        v[1].f = p[1];
        v[2].f = p[2];
        v[3].f = 1.0f;
        func_002f3cd8(v, *(u8**)(base + 4) + 16, v);
        d[0] = *(volatile f32*)&v[0].f;
        {
            f32 z = *(volatile f32*)&v[2].f;
            f32 y = *(volatile f32*)&v[1].f;
            d[2] = z;
            d[1] = y;
        }
    }
}

}

void u_call0_0014dfa8() {
    void* a = func_0014e638(D_00349f00);
    void* b = func_0014e648(D_00349f00);
    func_00166968(a, 1, 1, 0, 512, 448, 0, 0);
    func_0014db78(b, 0, 216, 512, 416, 49, 112);
    func_0014dd60(b, 0, 0, 0);
    func_0014dda0(b, 1);
    func_0014dd18(b);
    func_0014e2c0(D_00349f00);
    func_00102788(D_0032b91c, 0, 100000, func_0014df48);
}

void wtarget_001574f8(u32 a, u32 b, u32, u32) {
    u32 o;
    func_00157990(a);
    o = a + 6704;
    func_00138c10(o, b);
    *(u32*)(o + 392) = func_00155d58(a, 0);
    func_00138c10(a + 7116, func_00155d58(a, 1));
    func_00138c10(a + 8352, func_00155d58(a, 2));
    func_001543a0(a + 64, 1, *(u32*)(a + 24));
    if (func_001581a8(a) != 0 && func_002ba358() == 0) func_002ba368();
}
