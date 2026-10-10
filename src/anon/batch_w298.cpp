#include "../common/types.h"

#define QCOPY298(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV298 {
    f32 x, y, z, w;
    QV298() {}
    QV298(const QV298& o) { QCOPY298(this, &o); }
    QV298& operator=(const QV298& o) { if (this != &o) QCOPY298(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Act5cf8 { void** vt; };
struct O5cf8 { s32 f0; u8* p4; s32 f8; };
static inline QV298 operator-(const QV298& a, const QV298& b) {
    QV298 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vlen298(const QV298* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct Rng8cb { u8 pad[12]; s16 lo; s16 hi; };
struct O8cb { u8 pad[20]; u8* p20; u8 pad2[4]; u8* p28; Rng8cb* p32; u8 pad3[2]; u8 b38; u8 b39; };
extern u8* D_00352130;
extern u32 D_003638d0;
void func_0018cd28(struct O8cb*, f32*, f32*);
extern "C" {
f32 func_0017ce10(f32);
s32 func_0022a3d0(s32 n, f32 x, s32* a, s32* b, s32* c, s32* d, s32* e, s32* f, s32* g, s32* h, f32* out)
{
    f32 r = (f32)n * 0.25f;
    f32 ang = (x + r) * (90.0f / r * 0.017453292f);
    *out = ang;
    *out = func_0017ce10(ang);
    if (x < r) {
        *a = 0; *b = 0; *c = 64; *d = 50; *e = -64; *f = -50; *g = 64; *h = 100;
        return 1;
    }
    if (x < r + r) {
        *a = 0; *b = -50; *c = 0; *d = 0; *e = -64; *f = -50; *g = 64; *h = 100;
        return 2;
    }
    if (x < r * 3.0f) {
        *a = 0; *b = 50; *c = 0; *d = 0; *e = -64; *f = -50; *g = 64; *h = 50;
        return 3;
    }
    *a = 0; *b = -50; *c = 0; *d = 0; *e = 0; *f = -50; *g = 64; *h = 50;
    return 4;
}

s32 func_0016a070(u8*);
QV298* func_0016c028(u8*);
void func_001703a8(s32);
void func_001afb80(void*, s32, s32, s32);
void func_0016ed50(s32, s32, s32);
void func_00170888(void*);
void func_001c9e50(void*);
s32 func_0017e4f8(s32, QV298*, f32, f32, f32);
void func_001617d8(void);
void func_001ad990(u8*, f32, f32, f32);
s32 func_001ba028(u8*);
void func_00102448(void*, s32);
s32 func_001b5cf8(O5cf8* o, void* a1)
{
    s32 s5 = -1;
    s32 s6 = func_0016a070(o->p4);
    s32 id = ((s32 (*)(u8*))(*(void***)o->p4)[15])(o->p4);
    s32 s4 = *(s32*)(o->p4 + 1964);
    switch (id) {
    case 2410: s5 = 5; break;
    case 2420: s5 = 6; break;
    }
    QV298 pos;
    pos = *func_0016c028(o->p4);
    switch (o->f0) {
    case 0: {
        u8* p = o->p4;
        if (!(*(u32*)(p + 2040) & 0x10)) { f32 c = 8.0f; func_001ad990(p + 2092, 1.0f, 0.0f, c); }
        *(u32*)(p + 2040) |= 0x10;
        while (func_001ba028(o->p4)) func_00102448(a1, 0);
        func_00102448(a1, 1);
        break;
    }
    case 1:
        ((void (*)(u8*))(*(void***)o->p4)[36])(o->p4);
        break;
    }
    func_001703a8(id);
    func_001703a8(id + 1);
    func_001703a8(id + 2);
    func_001afb80(a1, s4, s6, o->f8);
    func_0016ed50(o->f8, id, s5);
    func_00170888(a1);
    func_001c9e50(a1);
    s32 r = func_0017e4f8(o->f8, &pos, 100.0f, 200.0f, 300.0f);
    if (o->f0 == 1) func_001617d8();
    return r;
}

s32 func_0018ca48(u8);
QV298* func_0016c028(u8*);
}
