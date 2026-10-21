#include "../common/types.h"

// ---- 00128b38 ----
struct V4w1992 { f32 v[4]; };
struct M4w1992 { f32 m[4][4]; };
struct Key128b38 { u16 idx; u8 ch:4; u8 hi:4; u8 pad[3]; };
struct Hdr128b38 { u8 pad[0x18]; s32 offM; u8 pad2[0x30 - 0x1c]; s32 off1; s32 n1; s32 off2; s32 n2; };
struct Obj128b38 { u32 x; Hdr128b38* h; };
struct Out128b38 { u8 pad[0x1c]; V4w1992* a; V4w1992* b; V4w1992* c; };

// ---- 0016eb48 ----
struct P16eb48 { u32 w0; u8 b4; u8 pad[0x48 - 5]; u8 b48; u8 pad2[0x4e - 0x49]; u16 h4e; u8 pad3[0x58 - 0x50]; u16 sub[4]; };

// ---- 00228f18 ----
struct AVT228f18 { void* (*alloc)(struct Alc228f18*, u32, u32); };
struct Alc228f18 { AVT228f18* vt; };
struct Mgr228f18 { u8 pad[20]; Alc228f18* a; };

extern "C" {
void func_001285f8(Obj128b38*, s32*, s32*);
f32 func_00128750(Obj128b38*, Key128b38*, s32, s32, f32);

P16eb48* func_0016e920(u32);
s32 func_0016f6f8(u32);
s32 func_0016f770(u32);
s32 func_0016f8d0(u32);
u32 func_0016f470(P16eb48*, s32);
u32 func_0016f4b8(P16eb48*, s32);
u32 func_0016f520(P16eb48*, u32, s32);
u32 func_0016f6a0(P16eb48*, s32);
void func_00170518(u32, s32, s32);
void func_00170530(u32, s32, s32, s32);
void func_0016ef58(u16, s32, u32, s32, s32);
extern s32 D_0036c278[];

extern Mgr228f18* D_00347f80;
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_0035e190[];
extern u8 D_0035e070[];
extern u8 D_0035e0a8[];
extern u8 D_0035e114[];
extern u8 D_0035e0e0[];
void func_0031a838(void*);
void func_00239700(void*);
void* func_00224870();
void* func_00224880();
void func_002294c8(void*, s32, void*, void*);
}

static inline void* w1992_kalloc(u32 n) { Alc228f18* a = D_00347f80->a; return a->vt->alloc(a, n, 0); }
struct B228f18 { u32 vt; u8 pad[8]; u8 m12[12]; B228f18() { vt = (u32)D_00347f98; func_0031a838(m12); } };
struct Sub228f18 : B228f18 { u8 m24[408 - 24]; Sub228f18() { vt = (u32)D_00347e60; func_00239700(m24); } };
struct Mid228f18 : B228f18 { Mid228f18() { vt = (u32)D_0035e190; } };
struct Outer228f18 : Mid228f18 { Sub228f18 subs[7]; u8 tail[20];
  void* operator new(unsigned int n) { return w1992_kalloc(n); } };
struct B0228f18 { u32 vt; u8 pad[8]; u32 f12; u8 pad2[8]; B0228f18() { vt = (u32)D_0035e190; f12 = 0; } };
struct Outer0228f18 : B0228f18 { Sub228f18 subs[7]; u8 tail[20];
  void* operator new(unsigned int n) { return w1992_kalloc(n); } };

static inline s32 w1992_off2(P16eb48* p) { return !(p->b48 & 1); }

extern "C" {

void func_00128b38(Obj128b38* o, Out128b38* out, f32 t) {
    s32 s0, s1;
    func_001285f8(o, &s0, &s1);
    Hdr128b38* h = o->h;
    Key128b38* k = (Key128b38*)((u8*)h + h->off1);
    s32 n = h->n1;
    for (s32 i = 0; i < n; i++, k++) {
        f32 v = func_00128750(o, k, s0, s1, t);
        switch (k->ch) {
        case 0: case 1: case 2: { u8* q = (u8*)out->a + k->idx * 16; s32 j = k->ch * 4; *(f32*)(q + j) = v; } break;
        case 3: case 4: case 5: { u8* q = (u8*)out->b + k->idx * 16; s32 j = k->ch - 3; s32 j4 = j * 4; *(f32*)(q + j4) = v; } break;
        case 6: case 7: case 8: { u8* q = (u8*)out->c + k->idx * 16; s32 j = k->ch - 6; s32 j4 = j * 4; *(f32*)(q + j4) = v; } break;
        }
    }
    M4w1992* m = (M4w1992*)((u8*)h + h->offM);
    k = (Key128b38*)((u8*)h + h->off2);
    n = h->n2;
    for (s32 i = 0; i < n; i++, k++) {
        f32 v = func_00128750(o, k, s0, s1, t);
        switch (k->ch) {
        case 0: case 1: case 2: { u8* q = (u8*)m + k->idx * 64; s32 j = (k->ch) * 4; *(f32*)(q + j + 16) = v; } break;
        case 3: case 4: case 5: { u8* q = (u8*)m + k->idx * 64; s32 j = k->ch - 3; s32 j4 = j * 4; *(f32*)(q + j4 + 32) = v; } break;
        case 6: case 7: case 8: { u8* q = (u8*)m + k->idx * 64; s32 j = k->ch - 6; s32 j4 = j * 4; *(f32*)(q + j4 + 48) = v; } break;
        }
    }
}

void w1992_tail4_16eb48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_tail4_0016eb48jjjj");
void w1992_tail4_16eb48(u32 a0, u32 a1, u32 a2, u32 a3) {
    P16eb48* p = func_0016e920(a0);
    if (p == 0) return;
    if ((s32)a1 == -1) {
        a1 = (u32)-200;
        if (!func_0016f6f8(a0)) a1 = D_0036c278[p->b4];
        if (!func_0016f770(a0) && a1 == 2400) a1 = func_0016f8d0(p->w0);
    }
    func_00170518(func_0016f470(p, 0), a1, 0);
    if (!func_0016f6f8(a0)) {
        if (!func_0016f770(a0)) {
            if (w1992_off2(p)) func_00170530(func_0016f4b8(p, 0), a1, a2, 0);
        }
    }
    if (!func_0016f6f8(a0)) {
        u32 r = func_0016f520(p, a0, 0);
        if (r) func_00170518(r, a1, 0);
    }
    if (func_0016f770(a0)) return;
    for (s32 i = 0; i < 2; ) {
        if ((s32)a1 >= 0) a1++;
        u32 r = func_0016f6a0(p, i);
        s32 k = i++;
        u32 c = a2;
        if ((s32)a3 >= 0) a2 = a3;
        if (r) { r |= a0 & 0x40000000; func_0016ef58(p->h4e, k, r, a1, c); }
    }
    for (s32 j = 3; j >= 0; j--) {
        u16* q = &p->sub[3 - j];
        if (*q) w1992_tail4_16eb48(*q, a1, a2, a3);
    }
}

void func_00228f18() {
    Outer0228f18* a = new Outer0228f18;
    func_002294c8(a, 3, func_00224870(), D_0035e070);
    Outer228f18* b = new Outer228f18;
    func_002294c8(b, 3, func_00224880(), D_0035e0a8);
    Outer228f18* c = new Outer228f18;
    func_002294c8(c, 3, D_0035e114, D_0035e0e0);
}

}

// ---- 002dbd30 ----
// VU0 macro asm (vmulx scale, vsub zero) and lq/sq 128-bit copies: no C equivalent.
#define W1992_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1992_MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                         : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QW2dbd30 { union { u32 v[4]; f32 f[4]; };
  QW2dbd30() {}
  QW2dbd30(f32 x, f32 y, f32 z, f32 w) { f[0] = x; f[1] = y; f[2] = z; f[3] = w; }
  QW2dbd30& operator=(const QW2dbd30& o) { if (this != &o) W1992_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct MT2dbd30 { QW2dbd30 r[4];
  MT2dbd30& operator=(const MT2dbd30& o) { if (this != &o) W1992_MCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Cfg2dbd30 { u8 pad[0x28]; f32 f28; f32 f2c; u8 pad2[0x40 - 0x30]; f32 f40; };
struct Ob2dbd30 { u8 pad[0x140]; u8 s140[0xb1c - 0x140]; u8 neg; u8 pad2[3]; MT2dbd30 m20; MT2dbd30 m60;
  u8 pad3[0xbc0 - 0xba0]; u8 bc0; u8 pad4[15]; QW2dbd30 vd0; QW2dbd30 ve0; u8 pad5[0xbf4 - 0xbf0]; f32 bf4; };
extern "C" {
extern s32 D_00361f60;
extern u32 D_0034e948;
extern u8 D_003628e0[];
void func_0017f540(void*, s32, f32, f32);
void func_001c0e60(Ob2dbd30*);
void func_0011b6a8(MT2dbd30*);
u32 func_0016b0a0(u32);
void func_0011b7b0(MT2dbd30*, u32);
QW2dbd30* func_0016c028(Ob2dbd30*);
Cfg2dbd30* func_002d73f0(s32);
f32 func_002f87c0(f32);
f32 func_002f8960(f32);
void func_002e7568(Ob2dbd30*, s32, void*, f32);
void func_002db968(Ob2dbd30*, s32);
}
static inline void w1992_scale(QW2dbd30& d, const QW2dbd30& a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&d), "r"(&a), "f"(s) : "$8", "memory");
}
static inline void w1992_zero(QW2dbd30* d) { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(d) : "memory"); }
static inline void w1992_setdir(QW2dbd30& out, f32 a, f32 r) {
    QW2dbd30 res;
    QW2dbd30 v(func_002f87c0(a), func_002f8960(a), 0.0f, 0.0f);
    w1992_scale(res, v, r);
    out = res;
}
extern "C" {
void func_002dbd30(Ob2dbd30* self, f32 x) {
    s32 id = D_00361f60;
    func_0017f540(self->s140, 153, 0.0f, 0.0f);
    func_001c0e60(self);
    self->neg = x < 0.0f;
    func_0011b6a8(&self->m60);
    func_0011b7b0(&self->m60, func_0016b0a0(D_0034e948));
    self->m60.r[3] = *func_0016c028(self);
    self->m60.r[3].f[3] = 1.0f;
    self->m20 = self->m60;
    self->bc0 = 1;
    f32 a;
    if (self->neg) a = func_002d73f0(id)->f2c;
    else a = 3.14159274f - func_002d73f0(id)->f2c;
    w1992_setdir(self->vd0, a, func_002d73f0(id)->f28);
    f32 y = self->vd0.f[1];
    self->bf4 = y * y / (2.0f * func_002d73f0(id)->f40);
    w1992_zero(&self->ve0);
    func_002e7568(self, 5, D_003628e0, 1.0f);
    func_002db968(self, 0);
}
}
