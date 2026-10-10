#include "../common/types.h"
struct NoTail { ~NoTail() {} };
struct V4b { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void nrm(V4b* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
}
struct V7b {
    f32 x, y, z, w;
    V7b() {}
    V7b(const V7b& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V7b& operator=(const V7b& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    V7b& operator+=(const V7b& o) { asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline V7b scl(const V7b& a, f32 n, f32 d) {
    V7b r;
    asm volatile(".set noreorder\n\tnop\n\tnop\n\tdiv.s $f0, %2, %3\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, $f0\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(n), "f"(d) : "$8", "memory");
    return r;
}
struct V7e {
    f32 x, y, z, w;
    V7e() {}
    V7e(const V7e& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V7e& operator=(const V7e& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 len() const { f32 r; asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory"); return r; }
} __attribute__((aligned(16)));
static inline V7e operator-(const V7e& a, const V7e& b) {
    V7e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
extern "C" {
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
f32* func_0017d1d8(f32* m, f32* a, f32 ang) {
    V4b v;
    v.x = a[0]; v.y = a[1]; v.z = a[2];
    nrm(&v);
    f32 x = v.x, y = v.y, z = v.z;
    f32 s = func_002f8960(ang);
    f32 c = func_002f87c0(ang);
    f32 t = 1.0f - c;
    m[0] = x * x * t + c;
    m[1] = x * y * t + z * s;
    m[2] = x * z * t - y * s;
    m[3] = 0;
    m[4] = x * y * t - z * s;
    m[5] = y * y * t + c;
    m[6] = y * z * t + x * s;
    m[7] = 0;
    m[8] = x * z * t + y * s;
    m[9] = y * z * t - x * s;
    m[10] = z * z * t + c;
    m[11] = 0;
    m[12] = 0; m[13] = 0; m[14] = 0;
    m[15] = 1.0f;
    return m;
}

extern s32 D_01D48CB0;
extern u8 D_00351EB8;
extern u8 D_00352560;
extern u8 D_00350E48;
s32 func_0019ba60(void*);
void func_0016cab8(void*);
void func_0016c7d8(void*);
void func_001dde40(void*);
void func_001b1c10(void*, f32);
void func_0016c640(s32);
void func_001d4570(void*, void*);
void func_00170950(void*);
s32 func_001b5858(void*);
s32 func_001b5cb8(void*);
void func_001c8d98(void*, s32);
void func_001d1ed0(void*);
void func_001d2048(void*);
void func_001b0188(void*);
void func_001ddd88(void*);

void func_001b4f40(u8* p) {
    NoTail nt;
    u32* q = (u32*)p;
    s32 i;
    *(u32*)(*(u8**)(p + 12) + 268) &= ~0x10000;
    for (i = 1; i >= 0; i--, q++) {
        if (func_0019ba60((void*)q[4])) {
            *(u32*)((u8*)q[4] + 268) &= ~0x10000;
            ((u8*)q[4])[2892] = 0;
        }
    }
    void* o = *(void**)(p + 52);
    if (o) { func_0016cab8(o); func_0016c7d8(o); }
    u8* m24 = p + 24;
    if (*(void**)(p + 24)) func_001dde40(m24);
    u8* m = p + 104;
    func_001b1c10(*(void**)(p + 56), 30.0f);
    func_0016c640(1);
    func_001d4570(*(void**)p, *(void**)(m + 56));
    void* o4 = *(void**)(p + 4); if (o4) func_00170950(o4);
    D_01D48CB0 = 0;
    if (!func_001b5858(p) && !func_001b5cb8(p)) func_001c8d98(&D_00351EB8, 0);
    *(void**)(p + 168) = &D_00352560;
    func_001d1ed0(p + 168);
    func_001d2048(m);
    *(void**)(p + 72) = &D_00350E48;
    func_001b0188(p + 72);
    func_001ddd88(m24);
}
s32 func_0019bb98(void*);
f32 func_0016a0a0(void*);
void func_001b7958(void*, V7b*);  // add_vec_to_records
void func_001b7b10(u8* a, u8* b, V7b* src, V7b* dst) {
    if (func_0019bb98(*(void**)(b + 4))) {
        if (func_0019bb98(*(void**)(a + 4))) {
            *dst = *src;
        }
        return;
    }
    if (func_0019bb98(*(void**)(a + 4))) {
        *(V7b*)(*(u8**)(b + 4) + 2160) += *dst;
        func_001b7958(b, dst);  // add_vec_to_records
        dst->zero();
        return;
    }
    f32 ma = func_0016a0a0(*(void**)(a + 4));
    f32 mb = func_0016a0a0(*(void**)(b + 4));
    V7b v;
    v = scl(*dst, ma, ma + mb);
    *dst = scl(v, mb, ma);
    *(V7b*)(*(u8**)(b + 4) + 2160) += v;
    func_001b7958(b, &v);  // add_vec_to_records
}
s32 func_001bfca0(void*);
void func_001991a8(s32, s32);
V7e* func_0016c028(void*);  // obj_get_attach_or_alt
V7e func_0016be98(void*);
void func_0016bd60(void*, s32);
void* func_0016a070(void*);
void* func_001a3018(void*, void*, s32);
void func_001a3188(void*, void*, s32);
void func_001bf378(u8* p, u8* t) {
    *(u8**)(p + 2536) = t;
    if (func_001bfca0(p)) {
        if (*(u32*)(*(u8**)(p + 2536) + 1416) & 0x80) func_001991a8(81, 1);
        (*(s32*)(*(u8**)(p + 2536) + 2764))++;
    } else {
        void* r = func_001a3018(*(void**)(p + 2484), func_0016a070(*(void**)(p + 2536)), 1);
        if (r) func_001a3188(*(void**)(p + 2484), r, 0);
    }
    *(u32*)(p + 2528) |= 4;
    V7e* d = (V7e*)(p + 2512);
    *d = *func_0016c028(p) - func_0016be98(*(void**)(p + 2536));
    f32 l = d->len() * 0.05f;
    l = l < 30.0f ? 30.0f : (l > 60.0f ? 60.0f : l);
    *(f32*)(p + 2496) = l;
    *(f32*)(p + 2492) = l;
    func_0016bd60(p, 13);
}
extern u8* D_00347F80;
extern u8 D_0035E190;
extern u8 D_00347F98;
extern u8 D_00347E60;
extern u8 D_0035DFB0;
extern u8 D_0035E01C;
extern u8 D_0035DFE8;
void func_0031a838(void*);
void func_00239700(void*);
void* func_00224930(void);
void func_002294c8(void*, s32, void*, void*);
typedef u8* (*AF)(void*, s32, s32);
static inline u8* alloc(s32 n) {
    void* a = *(void**)(D_00347F80 + 20);
    return (**(AF**)a)(a, n, 0);
}
static inline void elems(u8* e) {
    s32 i;
    for (i = 6; i != -1; i--) {
        *(void**)e = &D_00347F98;
        func_0031a838(e + 12);
        *(void**)e = &D_00347E60;
        func_00239700(e + 24);
        e += 408;
    }
}
void func_00228618(void) {
    u8* o = alloc(2900);
    *(s32*)(o + 12) = 0;
    *(void**)o = &D_0035E190;
    elems(o + 24);
    func_002294c8(o, 6, func_00224930(), &D_0035DFB0);
    o = alloc(2900);
    *(void**)o = &D_00347F98;
    func_0031a838(o + 12);
    *(void**)o = &D_0035E190;
    elems(o + 24);
    func_002294c8(o, 6, &D_0035E01C, &D_0035DFE8);
}
void func_00237280(void*, void*);
void func_002373a8(void*);
void func_00239fd0(void*, f32, f32, f32, f32);
void func_00239d50(void*, f32);
void func_00239da0(void*, f32);
void func_00239df0(void*, f32);
void func_00239e60(void*, f32, f32, f32);
union U9 { u32 u; s32 s; u8 c; };
#define R(o) (((U9*)(d + (o)))->s)
#undef W
#define W(o) (*(u32*)(p + (o)))
s32 func_00239988(u8* p, u8* d) {
    func_00237280(p, d);
    W(16) &= ~1;
    W(16) &= ~4;
    W(184) &= ~8;
    W(176) = (u32)(d + R(36));
    W(180) = (u32)(d + R(44));
    W(244) = R(32);
    W(248) = R(40);
    W(224) = 0x80808080;
    W(184) &= ~1;
    W(184) &= ~2;
    W(184) &= ~4;
    W(276) = -1;
    *(f32*)(p + 216) = 1.0f;
    *(f32*)(p + 220) = 1.0f;
    W(256) = 0;
    W(268) = 0;
    p[212] = 0;
    W(228) = 0;
    W(232) = 0;
    p[188] = 0;
    W(196) = 0;
    W(200) = 0;
    W(204) = 0;
    W(236) = 0;
    W(240) = 0;
    func_002373a8(p);
    *(f32*)(p + 68) = 1.0f;
    *(f32*)(p + 260) = 0.0f;
    func_00239fd0(p, 1.0f, 1.0f, 1.0f, 1.0f);
    func_00239d50(p, 0.0f);
    func_00239da0(p, 0.0f);
    func_00239df0(p, 0.0f);
    func_00239e60(p, 1.0f, 1.0f, 1.0f);
    W(328) = 0;
    W(332) = 0;
    W(252) = 0;
    return 1;
}
#undef W
#undef R
}
