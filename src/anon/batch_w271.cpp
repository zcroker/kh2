#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V4_w271 {
    f32 x, y, z, w;
    V4_w271() {}
    V4_w271(const V4_w271& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct VT_w271 { void* f[32]; };
struct Obj_w271 { VT_w271* vt; };
extern u32 D_0034e948;
extern "C" {
u32 func_0019ba60(u32);
u32 func_0019c090(u32);
u32 func_0019c5d0(Obj_w271*);
f32 func_001849d8(u32);
u32 c5d0f(Obj_w271*, f32) asm("func_0019c5d0");
V4_w271* func_0016c028(u32);
f32 func_0016afe0(u32);
void func_0016aeb8(Obj_w271*, f32);
void func_0016ace0(Obj_w271*, V4_w271*);
void func_0016ad68(Obj_w271*, u32);
void func_0016ac38(Obj_w271*, s32, s32, s32, s32);
void func_001b2db8(u32 self, Obj_w271* o) {
    u32 w = D_0034e948;
    if (func_0019ba60(w)) {
        if (func_0019c090(w)) {
            if (!c5d0f(o, 0.0f)) {
                f32 a = func_001849d8(w);
                if (a < func_0016c028((u32)o)->y) ((void (*)(Obj_w271*))o->vt->f[17])(o);
            }
            func_0016aeb8(o, func_0016afe0(w));
            V4_w271 t(*func_0016c028(w));
            t.y = (func_0016c028((u32)o)->y < t.y) ? t.y : func_0016c028((u32)o)->y;
            func_0016ace0(o, &t);
        } else {
            func_0016ad68(o, w);
            if (func_0019c5d0(o)) {
                func_0016ac38(o, 1, 1, 0, 0);
                ((void (*)(Obj_w271*))o->vt->f[18])(o);
            }
        }
    }
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"((u8*)o + 16) : "memory");
}
}
struct M_w271 { f32 m[12]; f32 t[4]; } __attribute__((aligned(16)));
extern "C" {
union Cam_w271 { u8* p; f32 f; };
extern Cam_w271 D_01d9e6e8;
extern u8 D_00354bd0[];
extern f32 D_00354bc0[3];
void func_0021ebe8(void*, void*);
void func_0021edb0(void*, void*);
void func_002f3e20(M_w271*, M_w271*);
void func_002f3d08(void*, void*, void*);
}
static inline void ScaleRow_w271(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
#define BODY_W271(ROT) \
    s32* off = *(s32**)(x + 12); \
    M_w271 m; \
    u8* mtx = o + off[3] + 160; \
    f32* scl = (f32*)(o + off[2] + 160); \
    f32* pos = (f32*)(o + off[0] + 160); \
    ROT(D_01d9e6e8.p + 16, o + off[1] + 160); \
    *(f32*)(D_01d9e6e8.p + 64) = pos[0]; \
    *(f32*)(D_01d9e6e8.p + 68) = pos[1]; \
    *(f32*)(D_01d9e6e8.p + 72) = pos[2]; \
    ROT(&m, D_00354bd0); \
    m.t[0] = D_00354bc0[0]; \
    m.t[1] = D_00354bc0[1]; \
    m.t[2] = D_00354bc0[2]; \
    func_002f3e20(&m, &m); \
    func_002f3d08(D_01d9e6e8.p + 16, D_01d9e6e8.p + 16, mtx); \
    func_002f3d08(D_01d9e6e8.p + 16, &m, D_01d9e6e8.p + 16); \
    ScaleRow_w271(D_01d9e6e8.p + 16, scl[0]); \
    ScaleRow_w271(D_01d9e6e8.p + 32, scl[1]); \
    ScaleRow_w271(D_01d9e6e8.p + 48, scl[2]);
extern "C" {
void func_002012e0(u8* o, u32 a1, u8* x) { BODY_W271(func_0021ebe8) }
void func_00201740(u8* o, u32 a1, u8* x) { BODY_W271(func_0021edb0) }
}
struct E_w271 { u8 a[8]; u8 b[8]; s8 c; u8 pad; u16 h; u8 rest[16]; };
extern "C" {
extern void* D_0035edac;
extern u32 D_0035edb0;
extern void* D_0035edc0;
extern E_w271 D_003720a0[];
void func_00288d80(void*, s32, s32, s32, u32, u32, E_w271*, void*);
u8* func_002891b8(void*, s32);
u32 func_0023aa78(void*);
u32 func_0023aa98(void*);
void func_00288e08(void*, s32, u32, s32);
u32 func_0028dd90(u32);
u32 func_0028ddd8(u32);
void func_001395f8(u8*);
void func_002891f0(void*, s32, s32, s32, s32);
void func_002b4388(void*, E_w271*, s32);
void func_0024ba58(void) {
    s32 sel = 0;
    s32 i;
    for (i = 0; i < 2; i++) {
        if (D_003720a0[i].c) sel = i;
        func_00288d80(D_0035edac, i, 0, 0, D_0035edb0, D_003720a0[i].h, &D_003720a0[i], D_003720a0[i].b);
        u8* v = func_002891b8(D_0035edac, i);
        func_00288e08(D_0035edac, i, func_0023aa78(v + 24), 0);
        u32 s = func_0023aa98(v + 24);
        *(u32*)(v + 432) = func_0028dd90(s);
        *(u32*)(v + 428) = func_0028ddd8(s);
        func_001395f8(v);
    }
    func_002891f0(D_0035edac, sel, 1, 0, 2);
    func_002b4388(D_0035edc0, &D_003720a0[sel], 0);
}
}
#ifndef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#endif
struct QW_w271 {
    f32 x, y, z, w;
    QW_w271() {}
    QW_w271(const QW_w271& o) { QCOPY(this, &o); }
    QW_w271& operator=(const QW_w271& o) { if (this != &o) QCOPY(this, &o); return *this; }
    ~QW_w271() {}
} __attribute__((aligned(16)));
static inline QW_w271 operator-(const QW_w271& a, const QW_w271& b)
{
    QW_w271 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QW_w271 Cross_w271(const QW_w271& a, const QW_w271& b)
{
    QW_w271 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Poly_w271 { QW_w271* v[4]; s32 n; };
extern "C" {
extern s32 D_0034c780[];
extern s32 D_0034c790[];
s32 func_00162408(Poly_w271* o, QW_w271* pt) {
    s32 n = o->n;
    s32* idx = (n == 3) ? D_0034c780 : D_0034c790;
    QW_w271 e[2];
    QW_w271 c;
    for (s32 i = 0; i < n; i++) {
        e[0] = *o->v[idx[i]] - *o->v[i];
        e[1] = *pt - *o->v[i];
        c = Cross_w271(e[1], e[0]);
        if (c.y < 0.0f) return 0;
    }
    return 1;
}
}
