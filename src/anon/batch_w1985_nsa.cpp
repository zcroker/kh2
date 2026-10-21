#include "../common/types.h"
extern "C" {
typedef struct { s32 t; s32 v; } W1985Key;
typedef struct { u8 pad[0x40]; } W1985Obj;
typedef struct { u8 pad[4]; u8 y; } W1985Byte;
extern s32 D_0035eb18[2];
extern W1985Key* D_0035eb20[2];
extern s32 D_0035eb28;
extern f32 D_0035eb2c;
extern s32 D_0035eb30;
extern s32 D_0035eb34;
extern f32 D_00349e14;
W1985Obj* func_00167bf0(s32);

// Steps a two-track key animation and writes the interpolated values to bytes 0x44/0x45.
void func_0023cfb8(void) {
    s32 i;
    switch (D_0035eb28) {
    case 1: D_0035eb28 = 2; D_0035eb2c = 0.0f; break;
    case 2: D_0035eb2c += D_00349e14 * 0.5f; break;
    case 0: default: return;
    }
    if ((f32)D_0035eb30 <= D_0035eb2c) { D_0035eb28 = 0; D_0035eb2c = (f32)(D_0035eb30 - 1); }
    if (D_0035eb34 == 0) return;
    for (i = 0; i < 2; i++) {
        W1985Key* k = D_0035eb20[i] + 1;
        s32 j;
        if (D_0035eb2c < (f32)k[-1].t) continue;
        for (j = D_0035eb18[i] - 1; j > 0; j--, k++) {
            if (D_0035eb2c <= (f32)k[0].t) {
                f32 t1 = (f32)k[0].t;
                f32 t0 = (f32)k[-1].t;
                f32 d = t1 - t0;
                f32 r;
                if (d != 0.0f) r = (D_0035eb2c - (f32)k[-1].t) / d; else r = 1.0f;
                {
                    s32 a = k[-1].v;
                    s32 b = k[0].v;
                    ((W1985Byte*)((u32)func_00167bf0(0) + (i + 0x40)))->y = a + (s32)((f32)(b - a) * r);
                }
                break;
            }
        }
    }
}

struct W1985Mtx {
    f32 m[4][4];
    W1985Mtx() {}
    W1985Mtx(const W1985Mtx& o)
    {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1985Mtx& operator=(const W1985Mtx& o)
    {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline W1985Mtx W1985Mul(const W1985Mtx& l, const W1985Mtx& r)
{
    W1985Mtx d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&d), "r"(&l), "r"(&r) : "memory");
    return d;
}
struct W1985Bone { u32 f0; s16 parent; s16 f6; u64 flags; u8 pad[48]; };
struct W1985SkelVt { void* f[8]; W1985Bone* (*bones)(void*); };
struct W1985Skel { W1985SkelVt* vt; };
struct W1985Bones { u32 f0; W1985Mtx* mats; u8 pad[12]; W1985Skel* skel; };

void func_00124848(W1985Bones* self, s32 idx, W1985Mtx* out)
{
    W1985Bone* b = self->skel->vt->bones(self->skel);
    if (b[idx].parent >= 0 && (b[b[idx].parent].flags & 0x100000000ULL)) {
        W1985Mtx m(self->mats[idx]);
        s32 p;
        for (p = b[idx].parent; p >= 0 && (b[p].flags & 0x100000000ULL); p = b[p].parent)
            m = W1985Mul(self->mats[p], m);
        *out = m;
    } else {
        *out = self->mats[idx];
    }
}

struct W1985Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void w1985_vadd(W1985Vec* d, const W1985Vec* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
static inline void w1985_vsub(W1985Vec* d, const W1985Vec* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
static inline void w1985_vscale(W1985Vec* v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(v), "f"(s) : "$8", "memory");
}
static inline f32 w1985_vnorm(W1985Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct W1985W1985MgrVt { void* f[10]; void (*fn40)(void*, s32, s32); };
struct W1985Mgr { W1985W1985MgrVt* vt; };
struct W1985PlVt { void* f[40]; u8* (*fn160)(void*); };
struct W1985Pl { W1985PlVt* vt; };
struct W1985Self {
    W1985Vec pos;            // 0
    void (*fn)(void*);  // 16
    u8 pad14[0x40 - 0x14];
    f32 time;           // 40
    u8 pad44[8];
    s32* p4c;           // 4c
    u8 pad50[0x10];
    f32 t60, t64, t68;  // 60
    u8 pad6c[4];
    f32 v70[3];         // 70
    f32 f7c;            // 7c
    u8 pad80[0x20];
    f32 fa0, fa4, fa8, fac, fb0, fb4;
};
extern f32 D_00349e10;
extern f32 D_00351fd8;
extern W1985Mgr* D_00361f60;
W1985Vec* func_002d1f30(W1985Mgr*);
f32 func_001cbf50(f32);
f32 func_002f87c0(f32);
f32 func_002f8960(f32);
s32 func_001cbab0(W1985Self*);
W1985Pl* func_002d1260(void);
void func_001ca910(W1985Self*);
bool func_001ca9c0(W1985Self*);
void func_001caee0(void*);

// Signature-mangled stub name: only a0 (the object) is read.
u32 u_call4_001cb278(W1985Self* self, u32, u32, u32) asm("_Z16u_call4_001cb278jjjj");
u32 u_call4_001cb278(W1985Self* self, u32, u32, u32)
{
    f32 a;
    if (self->time >= self->t60) {
        self->fa0 += self->fa8 * D_00349e10;
        self->fac += self->fb4 * D_00349e10;
    }
    if (D_00361f60) w1985_vadd((W1985Vec*)self->v70, func_002d1f30(D_00361f60));
    a = func_001cbf50(self->fa0);
    self->pos.x = func_002f87c0(a);
    self->pos.y = func_002f8960(a);
    self->pos.z = 0.0f;
    w1985_vscale(&self->pos, self->fac);
    w1985_vadd(&self->pos, (W1985Vec*)self->v70);
    if (self->time > self->t68 && func_001cbab0(self)) {
        W1985Pl* p = func_002d1260();
        w1985_vsub((W1985Vec*)self->v70, (W1985Vec*)(p->vt->fn160(p) + 48));
        self->f7c = w1985_vnorm((W1985Vec*)self->v70);
        self->time = D_00351fd8;
        self->fn = func_001caee0;
        D_00361f60->vt->fn40(D_00361f60, 1, *self->p4c);
        func_001ca910(self);
        return 1;
    }
    self->time += D_00349e10;
    if (self->time < self->t64) return 1;
    return !func_001ca9c0(self);
}
}
