#include "../common/types.h"
struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
struct OB { u8 pad[64]; M4 m; };
union UOB { OB* p; f32 f; };
struct OO { u8 pad[8]; UOB u; };
static inline V4 operator*(const M4& m, const V4& v) {
    V4 r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)" : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
static inline V4 Lerp(const V4& a, const V4& b, f32 t) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
struct C6490 {
    u8 pad[16];
    V4 a0;    // 16
    V4 b0;    // 32
    V4 a1;    // 48
    V4 b1;    // 64
    f32 f80;
    u32 flags;
    f32 t;
    f32 dur;
};
static inline f32 Normalize(V4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void MulS(V4* v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "f"(s) : "$8", "memory");
}
static inline V4 operator-(const V4& a, const V4& b) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V4 operator+(const V4& a, const V4& b) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct C8708 { V4 p0; u8 pad[80]; V4 p96; u8 pad2[16]; V4 p128; };
static inline void Zero(V4* v) {
    asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(v) : "memory");
}
static inline f32 Length(const V4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct C5088 { u8 pad[16]; V4 v; u8 pad2[2840]; u8* o2872; u8 pad3[228]; V4 v3104; };
static inline u8 IsMode2(u8* e) { return *(s32*)(e + 944) == 2; }
extern "C" {
void func_00209178(u8* a0, f32* m) {
    f32 w, h, b;
    switch (a0[49]) { case 1: w = 0.48999998f; break; case 2: w = 0.24f; break; case 0: default: w = 0.98999995f; break; }
    switch (a0[50]) { case 1: h = 0.48999998f; break; case 2: h = 0.24f; break; case 0: default: h = 0.98999995f; break; }
    switch (a0[51]) { case 1: b = 0.25f; break; case 2: b = 0.5f; break; case 3: b = 0.75f; break; case 0: default: b = 0.0f; break; }
    f32 x1 = b + w;
    f32 y0 = 0.01f;
    f32 x0 = b + y0;
    f32 z = 1.0f;
    m[0] = m[4] = m[24] = m[28] = x0;
    m[8] = m[12] = m[16] = m[20] = x1;
    m[5] = m[13] = m[21] = m[29] = h;
    m[1] = m[9] = m[17] = m[25] = y0;
    m[2] = m[6] = m[10] = m[14] = m[18] = m[22] = m[26] = m[30] = z;
}

void func_00178ae8(u8*, u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, f32, f32, void*);
void func_001d07e0(u8*);
void func_001d0870(u8*);
void func_001d0678(u8* p, u8* msg) {
    switch (*(u16*)(msg + 2)) {
    case 452: {
        u8* m = p + 320;
        p[2804] = msg[28];
        func_0017f488(m, 194, 8.0f, 0.0f);
        func_0017f5e0(m, 4, 8.0f, 0.0f, 0);
        break;
    }
    case 455: {
        u8* m = p + 320;
        func_0017f488(m, 193, 8.0f, 0.0f);
        *(void**)(m + 404) = (void*)func_001d0870;
        asm volatile("" ::: "memory");
        *(f32*)(p + 2924) = 0.0f;
        *(f32*)(p + 2920) = 120.0f;
        break;
    }
    case 456:
        func_0017f488(p + 320, 192, 8.0f, 0.0f);
        func_001d07e0(p);
        break;
    case 457:
        *(f32*)(p + 2920) = 30.0f;
        break;
    default:
        func_00178ae8(p, msg);
        break;
    }
}
extern u8 D_0035de26;
s32 func_002283b0(void);
s32 func_002283c8(void);
OO* func_00227cd8(s32);
void* func_00106a60(s32);  // buffer_get_by_index
void func_00107368(void*, V4*);  // vec_copy_at80_if_diff
void func_00107478(void*, V4*);  // vec_copy_at96_if_diff
s32 func_001ba028(u8*);  // list_contains_ptr
void func_001072d0(void*, V4*, V4*);
void func_001024a8(void*);
void func_00232150(void* self) {
    OO* o;
    if (func_002283b0()) o = func_00227cd8(1363);
    else if (func_002283c8()) o = func_00227cd8(1489);
    else o = func_00227cd8(572);
    if (D_0035de26 == 1) {
        V4 a, b;
        void* c = func_00106a60(1);  // buffer_get_by_index
        func_00107368(c, &a);  // vec_copy_at80_if_diff
        func_00107478(c, &b);  // vec_copy_at96_if_diff
        if (o) {
            if (func_001ba028((u8*)o->u.p)) {  // list_contains_ptr
                a.w = 1.0f;
                a = o->u.p->m * a;
                b.w = 1.0f;
                b = o->u.p->m * b;
                func_001072d0(c, &a, &b);
            } else func_001024a8(self);
        } else func_001024a8(self);
    } else func_001024a8(self);
}
extern f32 D_00349e10;
void func_002c6420(C6490*);
f32 func_002f8960(f32);
void* func_00106a18(s32);  // buffer_get_256
void func_00107300(void*, V4*, V4*, f32);  // copy_blocks_and_store_float
void func_00106de8(void*, s32, f32);
s32 func_002c6490(C6490* p) {
    u32 m = p->flags & 1;
    if (m == 0) func_002c6420(p);
    V4 a = p->a1;
    V4 b = p->b1;
    if (p->t < p->dur) {
        p->t += D_00349e10;
        if (p->t < p->dur) {
            f32 s = func_002f8960(p->t / p->dur * 1.5707964f);
            a = Lerp(p->a0, p->a1, s);
            b = Lerp(p->b0, p->b1, s);
        }
    }
    func_00107300(func_00106a60(1), &a, &b, 0.0f);  // copy_blocks_and_store_float
    func_00106de8(func_00106a18(1), 0, p->f80);
    p->flags |= 1;
    return 1;
}
V4* func_0016c028(u8*);  // obj_get_attach_or_alt
extern u8* D_0034a990;
extern f32 D_0034a994;
extern f32 D_0034a998;
extern f32 D_0034a99c;
extern V4 D_0034a9a0;
void func_00158708(C8708* o) {
    V4 a;
    V4 d;
    a = *func_0016c028(D_0034a990);  // obj_get_attach_or_alt
    a.y -= D_0034a994;
    d = a - D_0034a9a0;
    Normalize(&d);
    MulS(&d, D_0034a99c);
    d = D_0034a9a0 + d;
    o->p96 = Lerp(a, d, D_0034a998);
    o->p128 = D_0034a9a0;
    o->p0 = D_0034a9a0;
}
extern u8* D_00361f60;
s32 func_001b9d40(void);  // vtable_call_slot64_flags
s32 func_002d5588(C5088*);
u8* func_002d1878(u8*);
void func_002d5088(C5088* p) {
    Zero(&p->v);
    if (!func_001b9d40()) return;
    u8* cfg = D_00361f60;
    V4 a = *(V4*)(p->o2872 + 48);
    a.z = 0.0f;
    a.w = Length(&a);
    V4 b;
    f32 z = a.z;
    b.x = a.x; b.y = a.y; b.z = z; b.w = z;
    if (Normalize(&b) < 0.1f) {
        b.w = z;
    } else {
        p->v3104 = b;
        *(f32*)((u8*)p + 3116) = 1.0f;
        if (func_002d5588(p)) b.w = *(f32*)(func_002d1878(cfg) + 204);
        else b.w = *(f32*)(func_002d1878(cfg) + 4);
    }
    p->v = b;
}
extern u32 D_0034f240;
extern u8* D_0034e948;
s32 func_0019ba60(u8*);
u8* func_00185da8(u8*);
s32 func_0019c8a8(u8*);
void func_00191cd8(void) {
    D_0034f240 &= ~0x10000;
    u8* pl = D_0034e948;
    if (!func_0019ba60(pl)) return;
    V4 a = *func_0016c028(pl);  // obj_get_attach_or_alt
    u8* e = 0;
    while ((e = func_00185da8(e)) != 0) {
        if (*(u32*)(e + 1416) & 0x400) { D_0034f240 |= 0x10000; return; }
        if (!IsMode2(e)) continue;
        if (func_0019c8a8(e)) { D_0034f240 |= 0x10000; return; }
        V4 d = *func_0016c028(e) - a;
        d.y = 0.0f;
        if (Length(&d) < 1200.0f) { D_0034f240 |= 0x10000; return; }
    }
}
}
