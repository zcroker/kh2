#include "../common/types.h"
struct V4w1574 {
    f32 x, y, z, w;
    V4w1574() {}
    V4w1574(const V4w1574& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct E15c { f32 m[9]; s32 off; s32 bit; s32 a2c; s32 a30; s32 a34; u8 pad[104-56]; };
struct Alloc15c { union { void* (**vt)(Alloc15c*, s32, void*); f32 f; }; };
struct QW10d { f32 x, y, z, w;
    QW10d() {}
    QW10d(const QW10d& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct Tgt10d { s32 a, b, c, d, e; };
struct Hit10d { s32 p0; f32 r; s32 p8; s32 z; QW10d v; Hit10d() { z = 0; } };
struct Act10d { u8 pad[0xb60]; s32 b60; u8 pad2[0xcec - 0xb64]; s32 cec; };
struct QW187 { f32 x, y, z, w; QW187() {} } __attribute__((aligned(16)));
struct Kind187 { s32 p0; s32 type; };
struct Obj187 { u8 p0[12]; Kind187* kind; u8 p1[320 - 16]; u8 mot[1]; };
struct Ev187 { s32 p0; u32 flags; };
static inline void Scale187(QW187* r, QW187* a, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(a), "f"(k) : "$8", "memory");
}
extern "C" {
extern s32 D_0034af28;
extern E15c* D_0034af20;
extern s32 D_0034af24;
union U15c { u64 v; f32 f; };
extern U15c D_0034af30;
extern Alloc15c* D_0034c738;
void func_0015fe18(void*, E15c*, s32, V4w1574, V4w1574, V4w1574, s32, s32, s32, s32, s32);
void func_0015c2a0(s32 base, u64 mask) {
    V4w1574 a, b, c;
    D_0034af28 = base;
    E15c* e = D_0034af20;
    c.w = 1.0f; b.w = 1.0f; a.w = 1.0f;
    s32 n = D_0034af24;
    s32 i = 0;
    if (n > 0) do {
        u64 bit = (u64)1 << e->bit;
        if (bit & mask) {
            D_0034af30.v |= bit;
            a.x = e->m[0]; a.y = e->m[1]; a.z = e->m[2];
            b.x = e->m[3]; b.y = e->m[4]; b.z = e->m[5];
            c.x = e->m[6]; c.y = e->m[7]; c.z = e->m[8];
            void* p = D_0034c738->vt[0](D_0034c738, 0x2f0, __builtin_return_address(0));
            func_0015fe18(p, e, base + e->off, a, b, c, i, e->a2c, e->a30, e->bit, e->a34);
        }
        i++; e++;
    } while (i < n);
}
f32 func_001142c0(s32);
void func_00190128(Tgt10d*);
QW10d* func_0016c028(Act10d*);
void func_00112df0(s32, Tgt10d*, QW10d*, f32);
s32 Tgt10d_is_exist(Tgt10d*) asm("_ZNK2YS6TARGET8is_existEv");
s32 Tgt10d_can_attack(Tgt10d*) asm("_ZNK2YS6TARGET10can_attackEv");
s32 func_00190730(Tgt10d*, s32);
s32 func_00112d90(Tgt10d*);
void func_0018a818(Hit10d*, s32, s32);
void func_0010d2b8_impl(Act10d* self, void* unused, Tgt10d* out) asm("_Z13func_0010d2b8Pv");
void func_0010d2b8_impl(Act10d* self, void* unused, Tgt10d* out) {
    Hit10d hit;
    Tgt10d it;
    f32 best = func_001142c0(self->b60);
    func_00190128(&it);
    func_00190128(&it);
    if (self->cec) {
        QW10d pos(*func_0016c028(self));
        func_00112df0(self->cec, &it, &pos, best);
        if (Tgt10d_is_exist(&it)) { *out = it; return; }
    }
    s32 k = 0;
    while ((k = func_00190730(&it, k)) != 0) {
        if (!func_00112d90(&it)) continue;
        if (!Tgt10d_can_attack(&it)) continue;
        func_0018a818(&hit, it.a, k);
        QW10d* p = func_0016c028(self);
        f32 len;
        QW10d d;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(&hit.v), "r"(p), "r"(&d) : "memory");
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        len = len - hit.r;
        if (len < best) { best = len; *out = it; }
    }
}
void func_001cf320(Obj187*, Ev187*, s32, s32, f32);
s32 func_0019c090(Obj187*);
void f17f488_187(void*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void push_187(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
void func_0016af58(QW187*, Obj187*);
void func_00186c58(Obj187*, QW187*, f32);
void ctarget_00186a90_187(Obj187*, QW187*, f32) asm("_Z16ctarget_00186a90jjjj");
static inline void Back187(QW187* t, Obj187* self) { QW187 v; func_0016af58(&v, self); Scale187(t, &v, -1.0f); }
void func_00187018(Obj187* self, Ev187* ev, s32 a2, s32 mot, f32 spd) {
    QW187 t;
    if (ev->flags & 0x40) return;
    u32 d = self->kind->type ^ 0x17; if (d == 0) { func_001cf320(self, ev, a2, mot, spd); return; }
    if (spd < 0.0f) spd = 50.0f;
    if (func_0019c090(self)) {
        f17f488_187(self->mot, mot < 0 ? 43 : mot, 0.0f, 0.0f);
        push_187(self->mot, 4, 0.0f, 0.0f, 0);
        if (spd > 0.0f) {
            Back187(&t, self);
            func_00186c58(self, &t, spd);
        }
    } else {
        f17f488_187(self->mot, mot < 0 ? 41 : mot, 0.0f, 0.0f);
        if (spd > 0.0f) {
            Back187(&t, self);
            ctarget_00186a90_187(self, &t, spd);
        }
        push_187(self->mot, 0, 0.0f, 0.0f, 0);
    }
    ev->flags |= 0x40;
}
}
