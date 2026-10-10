#include "../common/types.h"
struct XC { s32 o0; s32 o4; s32 o8; };
struct X { u8 pad[12]; s32 c; };
struct K { s32 id; s32 idx; s32 off; };
struct S { f32 f0; f32 f4; u8* p8; };
struct M { u8 pad[128]; u8* tbl; u8 pad2[168 - 132]; u64 fl; };
extern u8 D_01d9e360[];
extern M* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern "C" {
void func_002f3f10(void*, void*, void*);  // vec4_sub
f32 func_002229a0(void*);  // vec3_length
void func_002f3d98(void*, void*);  // vec4_normalize
void func_002f3f40(void*, void*, f32);  // vec_scale_by_f12
void func_00222750(void*, void*, void*);
void func_001fbfd8(u8* a, K* k, X* x) {
    u8 buf[16];
    S** slot = (S**)(a + ((XC*)x->c)->o8 + 160);
    if (*(s32*)(a + 12) == k->id) {
        s32 i = k->idx;
        S* v;
        if (i != -1) v = (S*)(*(u8**)(D_01d9e6e0->tbl + i * 16 + 4) + k->off + 160);
        else v = (S*)D_01d9e360;
        *(s32*)slot = (s32)v;
        if (*(s32*)(a + 12) == 0 && a[157] == 0) return;
    }
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->fl & 0xff0000ff00ULL) return;
    S* s = *slot;
    if (s == (S*)D_01d9e360) return;
    XC* c = (XC*)x->c;
    u8* d = a + c->o4 + 160;
    func_002f3f10(buf, s->p8, a + c->o0 + 160);  // vec4_sub
    f32 len = func_002229a0(buf);  // vec3_length
    func_002f3d98(buf, buf);  // vec4_normalize
    if (len < s->f0) {
        func_002f3f40(buf, buf, (1.0f - len / s->f0) * s->f4);  // vec_scale_by_f12
        func_00222750(d, d, buf);
    }
}
}

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) { if (this != &o) QCOPY(this, &o); return *this; }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct QM { QV r[4]; };
static inline void mulmv(QV* o, const QM* m, const QV* v) {
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(o), "r"(v), "r"(m) : "memory");
}

static inline f32 normalize(QV* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 dot3(QV* v) {
    register f32 d asm("$f0");
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(d) : "r"(v) : "$8", "memory");
    return d;
}
struct O { u8 pad[16]; QV v16; QV v32; };
struct GP { f32 f0, f4, f8, f12, f16, f20, f24, f28, g32; };
extern GP D_00363630;
extern "C" {
u64 func_00313b80(f32);  // float_to_double
s32 func_003142e0(u64, u64);  // double_compare
void func_00183768(O*, QV*, f32);  // copy_quad_at16_and_len
QV func_00184540(O*, f32, f32);
void func_00184ad0(O*, QV*);
QV func_002ede48(O*, QV*, f32, f32);
QV func_002ed068(void* unused, O* o) {
    QV r;
    r = o->v32;
    f32 len = normalize(&r);
    r.w = len;
    if (func_003142e0(0, func_00313b80(o->v16.w)) < 0 && o->v16.w <= len) {  // double_compare
        func_00183768(o, &o->v16, len);  // copy_quad_at16_and_len
    }
    f32 t = (D_00363630.f24 < o->v16.w) ? D_00363630.f16 : D_00363630.f20;
    r = func_00184540(o, D_00363630.f12, 1.0f - t);
    f32 d = dot3(&r);
    register f32 z asm("$f12") = 0.0f;
    if (z < d) func_00184ad0(o, &r);
    r = func_002ede48(o, &r, D_00363630.f28, D_00363630.g32);
    return r;
}
}

struct O2 { u8 pad[64]; QM m64; u8 pad2[320 - 128]; QV v320; u8 pad3[496 - 336]; QV v496; u8 pad4[1372 - 512]; f32 f1372; };
extern "C" {
s32 func_001c0cd8(O2*);
s32 func_0019c400(O2*);
void func_001835a0(O2*, f32);
void func_0011b6a8(QM*);
void func_0017ff68(QV*, QV*);
f32 func_0017ce10(f32);
void func_0011b720(QM*, f32);
QV func_001835f8(O2* o) {
    QV r;
    if (func_001c0cd8(o)) { r.zero(); return r; }
    QV* pos = &o->v320;
    QM m;
    QV t = o->v496;
    r = t;
    if (func_0019c400(o)) {
        r.w = 0.0f;
        mulmv(&t, &o->m64, &r);
        r = t;
        return r;
    }
    if (r.w != 0.0f) func_001835a0(o, r.w);
    func_0011b6a8(&m);
    f32 a = o->f1372 + 3.1415927f;
    func_0017ff68(&t, pos);
    a -= t.w;
    func_0011b720(&m, func_0017ce10(a));
    r.w = 0.0f;
    mulmv(&t, &m, &r);
    r = t;
    return r;
}
}

static inline void vsub3(QV* d, const QV* a, const QV* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void cross(QV* d, const QV* a, const QV* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void transl(QM* m, const QV* b) {
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(m), "r"(b) : "memory");
}
static inline void invortho(QM* m) {
    asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\tpextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\tpcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\tqmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
struct Cam { u8 pad[16]; QM m; QV eye; QV at; QV up; f32 roll; };
extern "C" {
void func_0011b6a8(QM*);
void func_0011b768(QM*, f32);
void func_00107118(Cam* c) {
    QM* m = &c->m;
    func_0011b6a8(m);
    vsub3(&m->r[2], &c->at, &c->eye);
    normalize(&m->r[2]);
    cross(&m->r[0], &m->r[2], &c->up);
    normalize(&m->r[0]);
    cross(&m->r[1], &m->r[2], &m->r[0]);
    transl(m, &c->eye);
    invortho(m);
    func_0011b768(m, c->roll);
}
}
