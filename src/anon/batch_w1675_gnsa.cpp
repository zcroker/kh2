#include "../common/types.h"

#define W1675_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// VU0 4-float vector (same shape as W1640Vec).
struct W1675Vec {
    f32 x, y, z, w;
    W1675Vec() {}
    W1675Vec(const W1675Vec& o) { W1675_QCOPY(this, &o); }
    W1675Vec& operator=(const W1675Vec& o) { if (this != &o) W1675_QCOPY(this, &o); return *this; }
    W1675Vec operator+(const W1675Vec& o) const {
        W1675Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1675Vec operator-(const W1675Vec& o) const {
        W1675Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1675Vec operator*(f32 k) const {
        W1675Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    W1675Vec& operator*=(f32 k) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    // Normalises xyz in place; returns the old length.
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));

struct W1675Ctl {
    void** vt;
    u8 pad4[4];
    union {
        u32 flags;
        struct { u32 hold : 1; u32 busy : 1; };
    };
};

// RGBA colour, byte aligned.
struct W1675Tag {
    u8 r, g, b, a;
    void set(s32 r_, s32 g_, s32 b_, s32 a_) { r = r_; g = g_; b = b_; a = a_; }
};

// Ground/contact info block at obj+0x620.
struct W1675Ground {
    u8 pad0[0x20];
    u8 color[4];      // +0x20 (obj+0x640): target colour
    u8 pad24[8];
    u8 b2c;           // +0x2c (obj+0x64c)
    u8 pad2d[3];
    s32 kind;         // +0x30 (obj+0x650)
    s32 getKind() { return kind; }
    u8 b34;           // +0x34 (obj+0x654)
    u8 pad35[0x40 - 0x35];
    u32 u40;          // +0x40 (obj+0x660)
};

struct W1675Collider;
struct W1675ColliderVt { void* pad[2]; s32 (*hit)(W1675Collider*, const W1675Vec&); };
struct W1675Collider { W1675ColliderVt* vt; };


struct W1675Obj {
    u8 pad0[0xc];
    W1675Ctl* ctl;            // 0x0c
    u8 pad10[0x20 - 0x10];
    W1675Vec dir;             // 0x20
    u8 pad30[0x108 - 0x30];
    u32 flags108;
    u32 flags10C;
    u8 pad110[0x160 - 0x110];
    u32 flags160;
    u8 pad164[0x540 - 0x164];
    W1675Vec pos;             // 0x540
    u8 pad550[0x560 - 0x550];
    W1675Vec push;            // 0x560
    W1675Obj* parent;         // 0x570
    u8 pad574[0x588 - 0x574];
    u32 flags588;
    u32 flags58C;
    W1675Vec prevPos;         // 0x590
    W1675Vec target;          // 0x5a0
    f32 f5b0;                 // 0x5b0
    u8 pad5b4[0x5c0 - 0x5b4];
    W1675Vec hitPos;          // 0x5c0
    u8 pad5d0[0x600 - 0x5d0];
    union {
        u64 flags600;
        struct { u32 lo600; u32 hi604; };
    };
    s32 x608;
    u8 pad60c[0x620 - 0x60c];
    W1675Ground ground;       // 0x620
    u8 pad664[0x78e - 0x664];
    u8 b78e;
    u8 pad78f[0x810 - 0x78f];
    s32 x810;
    u8 pad814[0x8a0 - 0x814];
    W1675Vec v8a0;
    u8 pad8b0[0x8bc - 0x8b0];
    W1675Tag color;           // 0x8bc
    u8 pad8c0[0x8dc - 0x8c0];
    u8 b8dc;
    u8 pad8dd[0xad0 - 0x8dd];
    W1675Vec vad0;
} __attribute__((aligned(16)));
extern "C" {
extern f32 D_00349e10;
extern f32 D_00349e18;
extern f32 D_0034ed08;
s32 func_0019bb18(W1675Obj*);
void func_00183848(W1675Obj*, const W1675Vec&);
s32 func_002cebb0(void);
void func_002cf170(W1675Obj*, const W1675Vec&, const W1675Vec&);
s32 func_0019bad8(W1675Obj*);
void W1675_PrepareBg(W1675Obj*) asm("_ZN2YS3OBJ20prepare_bg_collisionEv");
s32 W1675_IsAttach(W1675Obj*) asm("_ZN2YS3OBJ9is_attachEv");
s32 func_0019c090(W1675Obj*);
void func_00143928(W1675Vec*);
s32 func_0019c0f8(W1675Obj*);
void func_00184308(W1675Obj*);
void func_00143648(W1675Vec*, W1675Ground*);
void func_00143520(W1675Vec*, W1675Ground*);
void func_001b3388(s32*, s32);
void func_001841f0(W1675Obj*);
W1675Vec func_001840c0(W1675Obj*, const W1675Vec&);
W1675Collider* func_001cecc8(void);
W1675Vec func_0016af58(W1675Obj*);
f32 func_002f8870(f32);
s32 func_0019c170(W1675Obj*);
s32 func_0019bf50(W1675Obj*, const W1675Vec&);

static inline __attribute__((always_inline)) void W1675_CopyTag(W1675Tag* d, W1675Tag* s) { __builtin_memcpy(d, s, 4); }
static inline bool W1675_CtlBusy(W1675Obj* self) { return (self->ctl->flags & 2) || (self->flags160 & 0x40); }
static inline bool W1675_Blocked(W1675Obj* self) { bool skip = false; if (func_0019c090(self) || W1675_CtlBusy(self)) skip = true; return skip; }
static inline bool W1675_CtlHold(W1675Obj* self) { return self->ctl->hold; }
static inline u32 W1675_F20(W1675Obj* self) { return self->flags160 & 0x20; }
static inline u32 W1675_F1000000(W1675Obj* self) { return self->flags160 & 0x1000000; }
static inline bool W1675_Frozen(W1675Obj* self) { return W1675_F20(self) || W1675_F1000000(self); }

void func_00183918(W1675Obj* self, W1675Vec acc, W1675Vec a, W1675Vec b)
{
    W1675Vec mv;
    W1675Vec d;
    f32 len;
    if (func_0019bb18(self)) func_00183848(self, a);
    if (func_002cebb0()) func_002cf170(self, acc, a);
    if (func_0019bad8(self)) {
        W1675_PrepareBg(self);
        if (W1675_Blocked(self)) {
            self->target = acc + a + b;
            self->flags600 |= 1;
        } else {
            self->flags600 &= ~1ULL;
            mv = func_001840c0(self, acc + a);
            if (self->flags58C & 4) {
                W1675Collider* c = func_001cecc8();
                if (c) {
                    if (!c->vt->hit(c, self->pos + mv)) {
                        W1675Vec n = func_0016af58(self);
                        if (func_002f8870(n.x) > func_002f8870(n.z)) mv.z = 0.0f;
                        else mv.x = 0.0f;
                    }
                }
                self->target = mv;
            } else if (func_0019c170(self)) {
                d = mv;
                len = d.normalize();
                d *= len + self->f5b0 * D_0034ed08;
                if (func_0019bf50(self, d + b)) {
                    if (self->flags588 & 2) self->vad0.zero();
                    self->target = b;
                } else {
                    self->target = mv + b;
                }
            } else {
                self->target = mv + b;
            }
        }
        self->prevPos = self->pos;
        mv = self->target;
        func_00143928(&self->prevPos);
        self->v8a0 = (self->hitPos - self->pos - mv) * D_00349e18;
        self->pos = self->hitPos;
        self->pos.w = 1.0f;
        if (W1675_CtlHold(self) || W1675_Frozen(self) || W1675_CtlBusy(self)) {
            if (0.0f <= mv.y && func_0019c0f8(self) && !(self->flags600 & (1ULL << 32))) func_00184308(self);
        } else if ((self->flags600 & (1ULL << 32)) && !(self->flags160 & 0x800000)) {
            self->dir = acc;
            len = self->dir.normalize() / D_00349e10;
            f32 k;
            if (len < 8.0f) k = len; else k = 8.0f;
            self->dir *= k;
            self->dir.w = 1.0f;
            func_001841f0(self);
        }
        func_00143648(&self->prevPos, &self->ground);
        self->x810 = 0;
        self->ground.u40 = self->hi604;
        if (!W1675_Blocked(self) && self->x608) func_001b3388(&self->x810, self->x608);
    } else {
        self->pos = self->pos + acc + a + b;
        self->pos.w = 1.0f;
        if (W1675_IsAttach(self)) {
            W1675_CopyTag(&self->color, &self->parent->color);
            self->b8dc = self->parent->b8dc;
            return;
        }
        func_00143520(&self->pos, &self->ground);
        self->x810 = 0;
    }
    self->b78e = self->ground.b2c;
    switch (self->ground.getKind()) {
    case 0: self->b8dc = 1; break;
    case 1: self->b8dc = 0; break;
    }
    // Colour: snap to the ground colour once, or step each channel toward it by at most 16.
    if (self->flags108 & 0x200000) {
        self->color.set(self->ground.color[0], self->ground.color[1], self->ground.color[2], self->ground.color[3]);
        self->flags108 &= ~0x200000;
    } else {
        for (s32 i = 0; i < 4; i++) {
            u8* cb = &self->color.r;
            u8* g = self->ground.color;
            s32 v;
            s32 cur = cb[i];
            s32 d = g[i] - cur;
            v = cur + d;
            if (d > 16) v = cur + 16;
            // Empty asm keeps this arm a branch, as in the original (gcc otherwise turns it into movn).
            if (d < -16) { v = cur - 16; asm(""); }
            cb[i] = v;
        }
    }
    if (self->flags108 & 0x2000) self->color.set(0x80, 0x80, 0x80, 0x80);
}
}
