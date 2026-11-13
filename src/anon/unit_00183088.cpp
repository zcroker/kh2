#include "../common/types.h"

// 0x183088-0x1855e0: YS::OBJ movement and ground/space handling (the file after YS::UNIT), up to the
// never-written 0x1855e0. Each function keeps the declarations of the source it was matched in
// (namespace oN); every symbol is bound by asm label.

// 00183088 (src/anon/batch_w1652_gnsa.cpp)
namespace o0 {
#define W1652_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1652Vec {
    f32 x, y, z, w;
    W1652Vec() {}
    W1652Vec(const W1652Vec& o) { W1652_QCOPY(this, &o); }
    W1652Vec& operator=(const W1652Vec& o) { if (this != &o) W1652_QCOPY(this, &o); return *this; }
    W1652Vec operator+(const W1652Vec& o) const {
        W1652Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1652Vec operator-(const W1652Vec& o) const {
        W1652Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1652Vec& operator+=(const W1652Vec& o) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
    W1652Vec operator*(f32 k) const {
        W1652Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct W1652Tag {
    u8 b[4];
};
struct W1652Ctl {
    void** vt;
    u8 pad4[4];
    u32 flags;
};
typedef W1652Vec (*W1652GetFn)(W1652Ctl*, void*);
struct W1652Par;
struct W1652Obj {
    u8 pad0[0xc];
    W1652Ctl* ctl;
    u8 pad10[0xd8 - 0x10];
    f32 height;
    u8 padDC[0x108 - 0xdc];
    u32 flags108;
    u32 flags10C;
    u8 pad110[0x160 - 0x110];
    u32 flags160;
    u8 pad164[0x540 - 0x164];
    W1652Vec pos;
    u8 pad550[0x560 - 0x550];
    W1652Vec push;
    W1652Par* parent;
    u8 pad574[0x588 - 0x574];
    u32 flags588;
    u8 pad58C[0x654 - 0x58c];
    u8 b654;
    u8 pad655[0x7f8 - 0x655];
    u32 flags7F8;
    u8 pad7FC[0x810 - 0x7fc];
    s32 unk810;
    u8 pad814[0x840 - 0x814];
    W1652Vec oldPos;
    W1652Vec move;
    W1652Vec vel;
    W1652Vec v870;
    W1652Vec v880;
    u8 pad890[0x8bc - 0x890];
    W1652Tag tag;
    u8 pad8C0[0x8dc - 0x8c0];
    u8 b8DC;
} __attribute__((aligned(16)));
struct W1652Par { u8 pad0[0x8bc]; W1652Tag tag; u8 pad8C0[0x8dc - 0x8c0]; u8 b8DC; };
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e18 asm("D_00349e18");
extern f32* D_00352130 asm("D_00352130");
s32 W1652_IsAttach(W1652Obj*) asm("_ZN2YS3OBJ9is_attachEv");
W1652Vec func_001835f8(W1652Obj*) asm("func_001835f8");
W1652Vec func_00186b90(W1652Obj*) asm("func_00186b90");
s32 func_0019bad8(W1652Obj*) asm("func_0019bad8");
s32 func_0019c090(W1652Obj*) asm("func_0019c090");
W1652Vec func_00184bb0(W1652Obj*) asm("func_00184bb0");
W1652Vec func_001d3ac0(W1652Obj*) asm("func_001d3ac0");
W1652Vec func_001b3428(s32*, W1652Obj*) asm("func_001b3428");
void func_00183918(W1652Obj*, const W1652Vec&, const W1652Vec&, W1652Vec&) asm("func_00183918");
static inline bool W1652_CtlBusy(W1652Obj* self) { return (self->ctl->flags & 2) || (self->flags160 & 0x40); }
static inline bool W1652_CanPush(W1652Obj* self) { bool skip = false; if (func_0019c090(self) || W1652_CtlBusy(self)) skip = true; return !skip; }

void func_00183088(W1652Obj* self)
{
    W1652Vec acc;
    W1652Vec d;
    W1652Vec a;
    W1652Vec b;
    W1652Vec u0, u1, u2, u3;
    self->oldPos = self->pos;
    self->flags108 &= ~0x400000;
    if (W1652_IsAttach(self)) {
        self->vel.zero();
        self->tag = self->parent->tag;
        self->b8DC = self->parent->b8DC;
        self->unk810 = 0;
    } else if (!(self->flags10C & 0x40)) {
        W1652Ctl* c = self->ctl;
        acc = ((W1652GetFn)c->vt[7])(c, self);
        acc += func_001835f8(self);
        if (self->flags588 & 2) acc += func_00186b90(self);
        acc += self->v880 * (self->v880.w * D_00349e10);
        if (func_0019bad8(self) && self->b654) {
            if (W1652_CanPush(self)) acc += func_00184bb0(self);
        }
        acc += self->push;
        acc += func_001d3ac0(self);
        a = self->v870;
        a.w = 1.0f;
        s32* pu = &self->unk810;
        if (*pu) b = func_001b3428(pu, self);
        else b.unit();
        self->move = (acc + a + b) * D_00349e18;
        { W1652Vec t0(acc); W1652Vec t1(a); func_00183918(self, t0, t1, b); }
        acc += a + b;
        d = self->pos - self->oldPos;
        self->height += d.y - acc.y;
        self->vel = d * D_00349e18;
        if (acc.y < 0.0f && d.y / acc.y < *D_00352130) self->flags108 |= 0x400000;
    } else {
        W1652Ctl* c = self->ctl;
        acc = ((W1652GetFn)c->vt[7])(c, self);
        acc += func_001835f8(self);
        acc += self->v880 * (self->v880.w * D_00349e10);
        self->move = acc * D_00349e18;
        self->pos += acc;
        d = self->pos - self->oldPos;
        self->vel = d * D_00349e18;
    }
    self->v880.zero();
    self->v870.zero();
    self->flags7F8 &= ~0x1000;
}
}  // namespace o0

// 001835a0 (src/anon/batch_w50.cpp)
namespace o1 {
typedef void (*VFn)(void*);
typedef void (*VFn3)(void*, void*, void*);
s32 func_0019c400(void*) asm("func_0019c400");
void func_0016ae58(void*, f32) asm("func_0016ae58");
f32 func_0017ce10(f32) asm("func_0017ce10");

void func_001835a0(u8* o, f32 d) {
    if (func_0019c400(o)) return;
    func_0016ae58(o, *(f32*)(o + 1372) + d);
    *(f32*)(o + 1644) = func_0017ce10(*(f32*)(o + 1644) + d);
}
}  // namespace o1

// 001835f8 (src/anon/batch_w276.cpp)
namespace o2 {
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
struct O2 { u8 pad[64]; QM m64; u8 pad2[320 - 128]; QV v320; u8 pad3[496 - 336]; QV v496; u8 pad4[1372 - 512]; f32 f1372; };
s32 func_001c0cd8(O2*) asm("func_001c0cd8");
s32 func_0019c400(O2*) asm("func_0019c400");
void func_001835a0(O2*, f32) asm("func_001835a0");
void func_0011b6a8(QM*) asm("func_0011b6a8");
void func_0017ff68(QV*, QV*) asm("func_0017ff68");
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_0011b720(QM*, f32) asm("func_0011b720");

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
}  // namespace o2

// 00183768 (src/anon/batch_w51.cpp)
namespace o3 {
typedef unsigned int u128  asm("u128")__attribute__((mode(TI)));
u32 wtarget_001339d0(u32, u32, u32, u32, u32) asm("_Z16wtarget_001339d0jjjj");
u32 wtarget_00180828(u32, u32, u32, u32) asm("_Z16wtarget_00180828jjjj");
u32 wtarget_001d9980(u32, u32, u32, u32) asm("_Z16wtarget_001d9980jjjj");
void wtarget_002cb188(u32, u32, u32, u32) asm("_Z16wtarget_002cb188jjjj");
void wtarget_002e1878(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");
typedef s32 (*VFnI)(void*);
typedef void (*VFn)(void*);
typedef void (*VFn1)(void*, u32);
struct Pkt { u16 h0; u8 b2; u8 b3; u32 w4; u32 w8; u32 w12; };
union PktCursor { Pkt* p; u32 u; u16 h; };
u32 wtarget_001339d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) asm("func_001339d0");
s32 func_0017ebc8(void*) asm("func_0017ebc8");
u32 func_001a97b8(u32, s32) asm("func_001a97b8");
u32 func_00180408(void*, u32) asm("func_00180408");
extern s32 D_0036c5b8[] asm("D_0036c5b8");
extern s32 D_0036c5cc[] asm("D_0036c5cc");
u32 wtarget_00180828(u32 a0, u32, u32, u32) asm("func_00180828");

// Store v at p+16 normalized (VU0), set p+28 = x; returns the original length.
f32 func_00183768(u8* p, u128* v, f32 x) {  // copy_quad_at16_and_len
    u128* d = (u128*)(p + 16);
    f32 len;
    if (d != v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(v) : "$8", "memory");
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, %0\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(d) : "$8", "memory");
    *(f32*)(p + 28) = x;
    return len;
}
}  // namespace o3

// 001837c0 (src/anon/batch_w63.cpp)
namespace o4 {
typedef void (*VFn)(void*);
s32 func_00141080(u32) asm("func_00141080");
s32 func_001b9d40(u32) asm("func_001b9d40");  // vtable_call_slot64_flags
void func_001835a0(u32, f32) asm("func_001835a0");
void func_00175b68(u32) asm("func_00175b68");
u8* func_00256b68(s32) asm("func_00256b68");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
s32 func_0028be58(u32) asm("func_0028be58");
void func_0028be18(u32) asm("func_0028be18");
extern f32 D_00349e10 asm("D_00349e10");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f04c asm("D_0035f04c");
struct WNode { u16 h0; u16 h2; u32 w4; u32 w8; u32 tag; u64 idx : 15; u64 rest : 49; };
struct WCtx { u8 pad[24]; WNode* cur; u32 pad28; union { WNode* top; u16 h; }; };
void wtarget_00133ae8(u32, u32, u32, u32) asm("_Z16wtarget_00133ae8jjjj");
void wtarget_00133ae8(u32 a0, u32 a1, u32, u32) asm("func_00133ae8");
void* cam_sxfs(u32, u32) asm("_ZN2dk6Camera20singleCrossFadeStartEf");
typedef void (*VFn3)(void*, void*, void*);
void wtarget_001789b8(u32, u32, u32, u32) asm("_Z16wtarget_001789b8jjjj");
void wtarget_001789b8(u32 a0, u32, u32, u32) asm("func_001789b8");
struct TGT { u32 w[5]; };
struct TPool { TGT items[128]; s32 freel[128]; s32 count; };
extern TPool D_01c60d50 asm("D_01c60d50");
TGT* tgt_dup(TGT*) asm("_ZN2YS6TARGET3dupEv");
void cmitem_leave(void) asm("_ZN2Tz6CmItem13LeaveCategoryEv");
struct W63Vec {
    f32 x, y, z, w;
    W63Vec& operator=(const W63Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
static inline void vsub(W63Vec* d, const W63Vec* a, const W63Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vnormalize(W63Vec* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

// Stores the horizontal (y = 0) unit direction from +1344 towards *target, and w.
void func_001837c0(u8* p, const W63Vec* target, f32 w) {
    W63Vec d;
    W63Vec t;
    vsub(&t, target, (W63Vec*)(p + 1344));
    d = t;
    d.y = 0.0f;
    vnormalize(&d);
    *(W63Vec*)(p + 16) = d;
    *(f32*)(p + 28) = w;
}
}  // namespace o4

// 00183848 (src/anon/batch_w84.cpp)
namespace o5 {
typedef void (*VFn)(void*);
u8* func_001b9bc8(u8*) asm("func_001b9bc8");
s32 func_0019bb18(u8*) asm("func_0019bb18");  // obj_is_blocked
s32 func_00144d10(u8*, u8*) asm("func_00144d10");
s32 func_002cf1f8(u8*, u8*) asm("func_002cf1f8");
void func_001b7a18(u32, u32, u32) asm("func_001b7a18");

void func_00183848(u8* a, u32 b) {
    u8* o = 0;
    while ((o = func_001b9bc8(o)) != 0) {
        if (!func_0019bb18(o)) continue;
        if (*(u8**)(a + 1392) == o) continue;
        if (*(u8**)(o + 1392) == a) continue;
        if (o == a) continue;
        if (*(u32*)(a + 2224) && *(u32*)(o + 2224)) {
            if (!func_00144d10(a + 1856, o + 1856)) continue;
        }
        if (!func_002cf1f8(a, o)) continue;
        func_001b7a18(*(u32*)(a + 2088), *(u32*)(o + 2088), b);
    }
}
}  // namespace o5

// 00183918 (src/anon/batch_w1675_gnsa.cpp)
namespace o6 {
#define W1675_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
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
struct W1675Tag {
    u8 r, g, b, a;
    void set(s32 r_, s32 g_, s32 b_, s32 a_) { r = r_; g = g_; b = b_; a = a_; }
};
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
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e18 asm("D_00349e18");
extern f32 D_0034ed08 asm("D_0034ed08");
s32 func_0019bb18(W1675Obj*) asm("func_0019bb18");
void func_00183848(W1675Obj*, const W1675Vec&) asm("func_00183848");
s32 func_002cebb0(void) asm("func_002cebb0");
void func_002cf170(W1675Obj*, const W1675Vec&, const W1675Vec&) asm("func_002cf170");
s32 func_0019bad8(W1675Obj*) asm("func_0019bad8");
void W1675_PrepareBg(W1675Obj*) asm("_ZN2YS3OBJ20prepare_bg_collisionEv");
s32 W1675_IsAttach(W1675Obj*) asm("_ZN2YS3OBJ9is_attachEv");
s32 func_0019c090(W1675Obj*) asm("func_0019c090");
void func_00143928(W1675Vec*) asm("func_00143928");
s32 func_0019c0f8(W1675Obj*) asm("func_0019c0f8");
void func_00184308(W1675Obj*) asm("func_00184308");
void func_00143648(W1675Vec*, W1675Ground*) asm("func_00143648");
void func_00143520(W1675Vec*, W1675Ground*) asm("func_00143520");
void func_001b3388(s32*, s32) asm("func_001b3388");
void func_001841f0(W1675Obj*) asm("func_001841f0");
W1675Vec func_001840c0(W1675Obj*, const W1675Vec&) asm("func_001840c0");
W1675Collider* func_001cecc8(void) asm("func_001cecc8");
W1675Vec func_0016af58(W1675Obj*) asm("func_0016af58");
f32 fabsf(f32) asm("fabsf");
s32 func_0019c170(W1675Obj*) asm("func_0019c170");
s32 func_0019bf50(W1675Obj*, const W1675Vec&) asm("func_0019bf50");
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
                        if (fabsf(n.x) > fabsf(n.z)) mv.z = 0.0f;
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
}  // namespace o6

// 001840c0 (src/anon/batch_w97.cpp)
namespace o7 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 vnormalize(Vq* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline Vq vcrossn(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void vscalei(Vq* v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v), "f"(s) : "$8", "memory");
}
static inline void vcopy(Vq* d, const Vq* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct Task104 { u32 f0; u32 f4; u8 f8; u32 f12; u32 f16; };
Task104* func_00102788(u32, u32, u32, void (*)(void)) asm("func_00102788");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
struct Menu158;
typedef void (*Menu158Fn)(Menu158*);
struct Menu158 { Menu158Fn* vt; u8 pad[40]; u32 f44; u32 f48; u32 f52; };

// ---- 001840c0
Vq func_001840c0(u8* o, Vq* v) {  // vec4_normalize_ptr
    f32 len = vnormalize(v);
    const Vq& up = *(Vq*)(o + 1584);
    Vq c;
    c = vcrossn(up, *v);
    vnormalize(&c);
    *v = vcrossn(c, up);
    vnormalize(v);
    vscalei(v, len);
    Vq r;
    vcopy(&r, v);
    return r;
}
}  // namespace o7

// 001841f0 (src/anon/batch_w85.cpp)
namespace o8 {
u8* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
void func_00102788(u32, s32, s32, void (*)(void)) asm("func_00102788");
typedef s32 (*PartFn)(void*);
void func_00188340(void*, s32, s32, s32) asm("func_00188340");
void func_0016cce8(void*, s32, s32, s32, s32) asm("func_0016cce8");
struct Obj184;
struct Obj184vt { u8 pad[44]; void (*f44)(Obj184*); };
struct Sub184vt { u8 pad[16]; void (*f16)(void*, Obj184*); };
struct Sub184 { Sub184vt* vt; };
struct Obj184 { Obj184vt* vt; u8 p4[8]; Sub184* f12; u8 p16[248]; u32 flags; u8 p268[500]; u8 f768[388]; void* f1156; };

void func_001841f0(Obj184* o) {
    o->flags &= ~0x04000000;
    func_00188340(o->f768, 1, 0, 0);
    if (!(o->flags & 0x04000000) && o->f1156) func_0016cce8(o->f1156, 13, 0, 0, 0);
    if (!(o->flags & 0x04000000)) o->f12->vt->f16(o->f12, o);
    if (!(o->flags & 0x04000000)) o->vt->f44(o);
}
}  // namespace o8

// 001842c0 (src/anon/tiny_auto80_queue.cpp)
namespace o9 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);

void func_001842c0(u32 a0) {
    f32 f12 = 0.0f;
    u32 s0 = a0;
    a0 = *(u32*)((u32)a0 + (s32)(12));
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 t6 = *(u32*)((u32)t7 + (s32)(12));
    ((void(*)(u32,u32,f32))(u32)t6)(a0, s0, f12);
    u32 t7b = *(u32*)((u32)s0 + (s32)(264));
    u32 t6b = (u32)(0x0400u << 16);
    t7b = (u32)(t7b | t6b);
    *(u32*)((u32)s0 + (s32)(264)) = t7b;
}
}  // namespace o9

// 00184308 (src/anon/batch_w86.cpp)
namespace o10 {
struct Obj;
struct Ctl;
typedef void (*CFn)(Ctl*, Obj*);
typedef void (*OFn)(Obj*);
struct Ctl { CFn* vt; };
struct Obj { OFn* vt; u8 p4[8]; Ctl* ctl; u8 p16[248]; u32 f264; u8 p268[500]; u8 sub768[388]; void* f1156; };
void func_00188340(void*, s32, s32, s32) asm("func_00188340");
void func_0016cce8(void*, s32, s32, s32, s32) asm("func_0016cce8");

void func_00184308(Obj* o)
{
    o->f264 &= ~0x08000000;
    func_00188340(o->sub768, 2, 0, 0);
    if (!(o->f264 & 0x08000000) && o->f1156) func_0016cce8(o->f1156, 14, 0, 0, 0);
    if (!(o->f264 & 0x08000000)) o->ctl->vt[5](o->ctl, o);
    if (!(o->f264 & 0x08000000)) o->vt[12](o);
}
}  // namespace o10

// 001843d8 (src/anon/batch_w228.cpp)
namespace o11 {
s32 func_001805a8(u8*, s32) asm("func_001805a8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");

void func_001843d8(u8* p) {
    u8* m = p + 320;
    if (!(*(u32*)(p + 360) & 0x10)) {
        if (func_001805a8(m, 5)) {
            func_0017f488(m, 5, 0.0f, 0.0f);
            func_0017f5e0(m, 0, 0, 0.0f, 0.0f);
        }
    }
    func_0016bd60(p, 0);
    *(u32*)(p + 264) |= 0x08000000;
}
}  // namespace o11

// 00184478 (src/anon/batch_w49.cpp)
namespace o12 {
typedef s32 (*Fn184478)(void*);

s32 func_00184478(u8* o) {
    s32 r = 0;
    if ((*(Fn184478*)(*(u8**)o + 64))(o)) {
        if (*(f32*)(o + 2112) != *(f32*)(o + 1344) || *(f32*)(o + 2120) != *(f32*)(o + 1352)) r = 1;
    }
    return r;
}
}  // namespace o12

// 001844e8 (src/anon/auto80_199_queue.cpp)
namespace o13 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_00184478(u32 a0) asm("func_00184478");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef u32 (*Method1)(u32);

u32 func_001844e8(u32 a0) {
    u32 s0 = a0;
    u32 s1 = 0;
    if (func_00184478(s0) != 0) {
        s1 = 1;
    } else {
        volatile float *p1 = (volatile float *)(s0 + 1348);
        float f1 = *p1;
        volatile float *p0 = (volatile float *)(s0 + 2116);
        float f0 = *p0;
        if (!(f0 == f1)) {
            s1 = 1;
        }
    }
    return s1;
}
}  // namespace o13

// 00184540 (src/anon/batch_wcx2.cpp)
namespace o14 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
extern f32 D_00349e10 asm("D_00349e10");
f32 fabsf(f32) asm("fabsf");  // fabsf
static inline void vu_Scale11(Vec4* s, Vec4* d, f32 f)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : : "r"(s), "r"(d), "f"(f) : "$8", "memory");
}
static inline void vu_Interp11(Vec4* a, Vec4* b, Vec4* d, f32 t)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\t"
                 "vaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\t"
                 "vmulax.xyzw ACC, $vf2, $vf3x\n\tvmaddx.xyzw $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(a), "r"(b), "r"(d), "f"(t) : "$8", "memory");
}
static inline void vu_Copy11(Vec4* d, Vec4* s)
{
    if (d != s) QCOPYN(d, s);
}
struct Obj11 { u8 pad[16]; Vec4 dir; Vec4 pos; };

u32 func_00184540(u32 out, u32 a1, f32 t, f32 s) asm("_Z13func_00184540jjff");
u32 func_00184540(u32 out, u32 a1, f32 t, f32 s)
{
    Obj11* p = (Obj11*)a1;
    if (t != 0.0f) {
        if (fabsf(p->pos.x) < 100000000.0f && fabsf(p->pos.y) < 100000000.0f && fabsf(p->pos.z) < 100000000.0f) {  // fabsf
        }
    }
    Vec4 r, b, a;
    if (0.0f < p->dir.w) {
        vu_Scale11(&p->dir, &a, p->dir.w);
        vu_Interp11(&a, &p->pos, &b, t);
        vu_Copy11(&r, &b);
    } else {
        vu_Scale11(&p->pos, &b, s);
        vu_Copy11(&r, &b);
    }
    vu_Copy11(&p->pos, &r);
    vu_Scale11(&r, (Vec4*)out, D_00349e10);
    return out;
}
}  // namespace o14

// 001846a0 (src/anon/batch_w52.cpp)
namespace o15 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
u32 wtarget_00109450(s32, s32, u32, u32) asm("_Z16wtarget_00109450jjjj");
void wtarget_002e2e50(u32, u32, u32, u32) asm("_Z16wtarget_002e2e50jjjj");
struct Obj;
typedef void (*ObjFn)(Obj*, ...);
struct Obj {
    ObjFn* vt;
};
struct Vec4 {
    f32 x, y, z, w;
} __attribute__((aligned(16)));
#define MULV(m, v, out) asm volatile( \
    "lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t" \
    "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\t" \
    "vmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%2)" : : "r"(m), "r"(v), "r"(out) : "memory")

// Sets and normalizes the direction at +2176 (VU0), stores f at +2188.
void func_001846a0(u8* p, Vec4* v, f32 f) {
    Vec4* d = (Vec4*)(p + 2176);
    if (d != v) QCOPY(d, v);
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d) : "$8", "$f0", "memory");
    *(f32*)(p + 2188) = f;
}
}  // namespace o15

// 001846f8 (src/anon/batch_w64.cpp)
namespace o_46f8 {
typedef void (*VFn)(void*);
typedef s32 (*IFn)(void*);
static inline void vcopy(void* d, void* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void ys_obj_fly_to_jump(u8* self) asm("_ZN2YS3OBJ11fly_to_jumpEv");

// Sets up a ballistic jump: time from distance, initial height offset, target copy.
void ys_obj_fly_to_jump(u8* self) {
    func_0016bd60(self, 1);
    f32 t = *(f32*)(self + 2148) / 0.408163249f;
    *(u32*)(self + 220) = 0;
    *(u32*)(self + 212) = 0;
    *(f32*)(self + 208) = t;
    *(f32*)(self + 216) = *(f32*)(self + 1348) - t * 0.408163249f * t * 0.5f;
    vcopy(self + 32, self + 2144);
}
}  // namespace o_46f8

// 00184780 (src/anon/batch_w2042_nsa.cpp)
namespace o17 {
struct W2042Vec {
    f32 x, y, z, w;
    W2042Vec() {}
    W2042Vec& operator=(const W2042Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2042Seg { W2042Vec a, b; };
struct W2042Obj { u8 p0[0x5fc]; f32 r; u64 :3; s64 k:32; };
W2042Vec* func_0016c028(W2042Obj*) asm("func_0016c028");
s32 func_00143ae0(W2042Seg*, W2042Vec*, W2042Vec*, s32) asm("func_00143ae0");
static inline f32 w2042_norm(W2042Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline W2042Vec w2042_mul(const W2042Vec& a, f32 s) {
    W2042Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline W2042Vec w2042_add(const W2042Vec& a, const W2042Vec& b) {
    W2042Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

s32 func_00184780(W2042Obj* o, W2042Vec* dir, f32 s, f32 d, f32 e) {
    W2042Seg seg;
    W2042Vec A, B, C, D, o1, o2;
    A = *func_0016c028(o);
    B = *dir;
    B.y = 0;
    w2042_norm(&B);
    C = A;
    C.y -= d;
    D = w2042_add(C, w2042_mul(B, s));
    seg.a = C;
    seg.b = D;
    if (func_00143ae0(&seg, &o1, &o2, o->k & 0xf)) return 3;
    C = D;
    C.y += d + e;
    seg.a = D;
    seg.b = C;
    if (!func_00143ae0(&seg, &o1, &o2, o->k & 0xf)) return 3;
    f32 f = o->r * 0.4f;
    if (o1.y < A.y - f) return 1;
    if (A.y + f < o1.y) return 2;
    return 0;
}
}  // namespace o17

// 001849b8 YS::OBJ::get_ground (src/yasui/libys/obj.cpp)
namespace o_49b8 {
u32 OBJ_get_ground(u8* self) asm("_ZN2YS3OBJ10get_groundEv");
u32 OBJ_get_ground(u8* self) {
    u32 r14 = ((u32*)(u32)self)[3];
    u32 r15 = ((u32*)(u32)r14)[2];
    r15 = (u32)(r15 & 0x0020u);
    u32 r2 = (u32)((s32)0u + 18);
    if (r15 == 0u) {
        r2 = ((u32*)(u32)self)[402];
    }
    return r2;
}
}  // namespace o_49b8

// 001849d8 (src/anon/batch_w68.cpp)
namespace o19 {
typedef void (*VF)(void*);
/* ---- 001849d8 ---- */
struct Bits3 { u64 lo:3; u64 kind:4; u64 mid:26; u64 dirty:1; };
struct Ent3 { u8 pad[1528]; f32 val; u32 pad2; union { u64 raw; Bits3 b; } u; };
void* func_0016c028(Ent3*) asm("func_0016c028");  // obj_get_attach_or_alt
s32 func_001a7610(void*, f32*, s32, f32, f32) asm("func_001a7610");
static inline bool clean3(Ent3* e) { return !e->u.b.dirty; }

f32 f_001849d8(Ent3* e) asm("_Z13func_001849d8j");
f32 f_001849d8(Ent3* e) {
    if (!clean3(e)) {
        f32 out[4];
        if (func_001a7610(func_0016c028(e), out, (s32)(e->u.raw >> 3) & 0xf, 100000.0f, 200.0f)) {
            e->val = out[1];
            e->u.b.dirty = 0;
        } else {
            e->val = ((f32*)func_0016c028(e))[1];
        }
    }
    return e->val;
}
}  // namespace o19

// 00184a90 (src/anon/tiny_auto80_queue.cpp)
namespace o20 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
f32 func_001849d8(u32) asm("func_001849d8");

f32 func_00184a90(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(12));
    u32 t6 = *(u32*)((u32)t7 + (s32)(8));
    u32 t5 = (u32)(t6 & 1u);
    t6 = (u32)(t6 & 0x20u);
    if (t6 != 0u) {
        if ((u32)(t5 & 0xffu) != 0u) {
            return *(f32*)((u32)a0 + (s32)(224));
        }
    }
    return func_001849d8(a0);
}
}  // namespace o20

// 00184ad0 (src/anon/batch_w80.cpp)
namespace o21 {
struct HasF4 { u32 f0; f32 f4; };
struct U1_Turn { u8 pad[284]; f32 f284; u8 pad2[1372 - 288]; f32 yaw; };
extern f32 D_00349e10 asm("D_00349e10");
struct U11_CurObj { u8 pad[24]; u8 sub[184]; u32 f208; u8 pad2[392 - 212]; u32 f392; u8 pad3[405 - 396]; u8 f405; u8 pad4[2]; u8* f408; u8 pad5[428 - 412]; u32 f428; u32 f432; };
struct U21_DObj;
struct U21_DObjVt { void (*dtor)(U21_DObj*); };
struct U21_DObj { U21_DObjVt* vt; u8 pad[340]; };
#define U21_W80_DTOR_ARR(base, off, n) \
    if ((u32)(base) != (u32)-(off)) { \
        U21_DObj* e_ = (U21_DObj*)((base) + (off)) + (n); \
        U21_DObj* b_ = (U21_DObj*)((base) + (off)); \
        for (;;) { \
            if (b_ == e_) break; \
            e_--; \
            e_->vt->dtor(e_); \
        } \
    }
struct U23_W80Vec {
    f32 x, y, z, w;
    U23_W80Vec() {}
    U23_W80Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    U23_W80Vec operator-(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec operator+(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec& operator=(const U23_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct U24_W80Vec {
    f32 x, y, z, w;
    U24_W80Vec& operator=(const U24_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct U24_W80Param { u32 a, b, c, d, e; };
struct U24_W80Eff { u8 pad[64]; U24_W80Vec pos; u8 pad2[100 - 80]; U24_W80Param prm; };
struct U24_W80Own { u8 pad[2548]; u8* heap; };
s32 func_0019c400(U1_Turn*) asm("func_0019c400");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_0016aeb8(U1_Turn*, f32) asm("func_0016aeb8");
HasF4* func_0016c028(void*) asm("func_0016c028");  // obj_get_attach_or_alt
void func_00102818(u32, u32, u32, void (*)(void), u32) asm("func_00102818");
U23_W80Vec* w80_pos_vec(void*) asm("func_0016c028");
void func_002ed558(U24_W80Eff*, U24_W80Own*, u32, u32, void (*)(void)) asm("func_002ed558");
void w80_MenuCursor_Create(U11_CurObj* c, u32 a1, u32 a2, u32 a3, u32 sprA, u32 t1, u32 t2, s32 t3, u32 st) asm("_ZN2Tz10MenuCursor6CreateEz");
void w80_JmBattle_LeaveAllInner(void) asm("_ZN2Tz8JmBattle13LeaveAllInnerEv");

// turn toward the direction v, limited by speed
s32 func_00184ad0(U1_Turn* o, f32* v, f32 speed) {
    s32 r = 1;
    f32 ang, d, a;
    if (func_0019c400(o)) return 0;
    if (speed == 0.0f) speed = o->f284;
    speed *= D_00349e10;
    ang = func_002f8ad0(v[0], v[2]);
    d = func_0017ce10(ang - o->yaw);
    if (speed < d) a = func_0017ce10(o->yaw + speed);
    else if (d < -speed) a = func_0017ce10(o->yaw - speed);
    else { a = ang; r = 0; }
    func_0016aeb8(o, a);
    return r;
}
}  // namespace o21

// 00184bb0 (src/anon/batch_w1676_g.cpp)
namespace o22 {
#define W1676_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1676Vec {
    f32 x, y, z, w;
    W1676Vec() {}
    W1676Vec(const W1676Vec& o) { W1676_QCOPY(this, &o); }
    W1676Vec& operator=(const W1676Vec& o) { if (this != &o) W1676_QCOPY(this, &o); return *this; }
    W1676Vec operator+(const W1676Vec& o) const {
        W1676Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1676Vec operator-(const W1676Vec& o) const {
        W1676Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1676Vec operator*(f32 k) const {
        W1676Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    W1676Vec& operator*=(f32 k) {
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
    W1676Vec cross(const W1676Vec& o) const {
        W1676Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1676Pt : W1676Vec {
    W1676Pt& operator=(const W1676Vec& o) { W1676Vec::operator=(o); return *this; }
    ~W1676Pt() {}
} __attribute__((aligned(16)));
struct W1676Mtx {
    W1676Vec r[4];
    W1676Vec operator*(const W1676Vec& v) const {
        W1676Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1676Ctl {
    void** vt;
    u8 pad4[4];
    union {
        u32 flags;
        struct { u32 hold : 1; u32 busy : 1; };
    };
};
struct W1676Tag {
    u8 b[4];
    void set(s32 r, s32 g, s32 bl, s32 a) { b[0] = r; b[1] = g; b[2] = bl; b[3] = a; }
};
struct W1676Ground {
    u8 pad0[0x20];
    W1676Tag color;      // +0x20 (obj+0x640): target colour
    u16 poly;         // +0x24 (obj+0x644)
    u8 pad26[6];
    u8 b2c;           // +0x2c (obj+0x64c)
    u8 pad2d[3];
    s32 kind;         // +0x30 (obj+0x650)
    s32 getKind() { return kind; }
    u8 b34;           // +0x34 (obj+0x654)
    u8 pad35[0x40 - 0x35];
    u32 u40;          // +0x40 (obj+0x660)
};
struct W1676Obj {
    u8 pad0[0xc];
    W1676Ctl* ctl;            // 0x0c
    u8 pad10[0x20 - 0x10];
    W1676Vec dir;             // 0x20
    u8 pad30[0x108 - 0x30];
    u32 flags108;
    u32 flags10C;
    u8 pad110[0x160 - 0x110];
    u32 flags160;
    u8 pad164[0x540 - 0x164];
    W1676Vec pos;             // 0x540
    u8 pad550[0x560 - 0x550];
    W1676Vec push;            // 0x560
    W1676Obj* parent;         // 0x570
    u8 pad574[0x588 - 0x574];
    u32 flags588;
    u32 flags58C;
    W1676Vec prevPos;         // 0x590
    W1676Vec target;          // 0x5a0
    f32 f5b0;                 // 0x5b0
    u8 pad5b4[0x5c0 - 0x5b4];
    W1676Vec hitPos;          // 0x5c0
    u8 pad5d0[0x600 - 0x5d0];
    union {
        u64 flags600;
        struct { u32 lo600; u32 hi604; };
    };
    s32 x608;
    u8 pad60c[0x620 - 0x60c];
    W1676Ground ground;       // 0x620
    u8 pad664[0x78e - 0x664];
    u8 b78e;
    u8 pad78f[0x810 - 0x78f];
    s32 x810;
    u8 pad814[0x8a0 - 0x814];
    W1676Vec v8a0;
    u8 pad8b0[0x8bc - 0x8b0];
    W1676Tag color;           // 0x8bc
    u8 pad8c0[0x8dc - 0x8c0];
    u8 b8dc;
    u8 pad8dd[0xad0 - 0x8dd];
    W1676Vec vad0;
} __attribute__((aligned(16)));
extern f32 D_00349e10 asm("D_00349e10");
extern W1676Vec D_00350990 asm("D_00350990");
void func_00143f50(u16, W1676Pt*) asm("func_00143f50");
W1676Vec W1676_GetNormal(u16, bool) asm("_ZN2dk6Octree9getNormalEtb");
void W1676_MtxUnit(W1676Mtx*) asm("_Z13func_0011b6a8Pv");

W1676Vec func_00184bb0(W1676Obj* self)
{
    W1676Pt pts[4];
    W1676Vec v;
    W1676Vec up;
    W1676Mtx m;
    func_00143f50(self->ground.poly, pts);
    s32 n = 3;
    do {
        s32 last = -1;
        for (s32 j = 1; j <= n; j++) {
            if (pts[j - 1].z > pts[j].z) {
                last = j - 1;
                v = pts[last];
                pts[last] = pts[j];
                pts[j] = v;
            }
        }
        n = last;
    } while (n >= 0);
    if (pts[0].x > pts[1].x) v = pts[1] - pts[0];
    else v = pts[0] - pts[1];
    v.normalize();
    up = W1676_GetNormal(self->ground.poly, 0);
    W1676_MtxUnit(&m);
    m.r[0] = v.cross(up);
    m.r[0].normalize();
    m.r[1] = up;
    m.r[2] = m.r[0].cross(m.r[1]);
    m.r[2].normalize();
    m.r[0].w = 0.0f;
    m.r[1].w = 0.0f;
    m.r[2].w = 0.0f;
    v = D_00350990;
    v.w = 0.0f;
    return (m * v) * D_00349e10;
}
}  // namespace o22

// 00184eb8 (src/anon/batch_w80.cpp)
namespace o23 {
struct HasF4 { u32 f0; f32 f4; };
struct U1_Eff { u8 pad[1288]; void* eff; u8 pad2[1416 - 1292]; u32 f1416; u8 pad3[2072 - 1420]; void* tgt; };
struct U11_CurObj { u8 pad[24]; u8 sub[184]; u32 f208; u8 pad2[392 - 212]; u32 f392; u8 pad3[405 - 396]; u8 f405; u8 pad4[2]; u8* f408; u8 pad5[428 - 412]; u32 f428; u32 f432; };
struct U21_DObj;
struct U21_DObjVt { void (*dtor)(U21_DObj*); };
struct U21_DObj { U21_DObjVt* vt; u8 pad[340]; };
#define U21_W80_DTOR_ARR(base, off, n) \
    if ((u32)(base) != (u32)-(off)) { \
        U21_DObj* e_ = (U21_DObj*)((base) + (off)) + (n); \
        U21_DObj* b_ = (U21_DObj*)((base) + (off)); \
        for (;;) { \
            if (b_ == e_) break; \
            e_--; \
            e_->vt->dtor(e_); \
        } \
    }
struct U23_W80Vec {
    f32 x, y, z, w;
    U23_W80Vec() {}
    U23_W80Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    U23_W80Vec operator-(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec operator+(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec& operator=(const U23_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct U24_W80Vec {
    f32 x, y, z, w;
    U24_W80Vec& operator=(const U24_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct U24_W80Param { u32 a, b, c, d, e; };
struct U24_W80Eff { u8 pad[64]; U24_W80Vec pos; u8 pad2[100 - 80]; U24_W80Param prm; };
struct U24_W80Own { u8 pad[2548]; u8* heap; };
void func_002cb708(void*) asm("func_002cb708");
void func_00105110(void*) asm("func_00105110");
void* func_0019b328(void*, u32) asm("func_0019b328");
void* func_00182e08(u32) asm("func_00182e08");
HasF4* func_0016c028(void*) asm("func_0016c028");  // obj_get_attach_or_alt
void* func_002cd018(U1_Eff*, void*, HasF4*, f32) asm("func_002cd018");
void func_00102818(u32, u32, u32, void (*)(void), u32) asm("func_00102818");
U23_W80Vec* w80_pos_vec(void*) asm("func_0016c028");
void func_002ed558(U24_W80Eff*, U24_W80Own*, u32, u32, void (*)(void)) asm("func_002ed558");
void w80_MenuCursor_Create(U11_CurObj* c, u32 a1, u32 a2, u32 a3, u32 sprA, u32 t1, u32 t2, s32 t3, u32 st) asm("_ZN2Tz10MenuCursor6CreateEz");
void w80_JmBattle_LeaveAllInner(void) asm("_ZN2Tz8JmBattle13LeaveAllInnerEv");

s32 func_00184eb8(U1_Eff* o, u32 id, void* t) {
    void* s;
    if (!t) t = o->tgt;
    s = o->eff;
    if (s) {
        func_002cb708(s);
        func_00105110(s);
        o->eff = 0;
    }
    s = 0;
    if (t) s = func_0019b328(t, id);
    if (!s && (o->f1416 & 0x80)) s = func_00182e08(id);
    if (!s) return 0;
    o->eff = func_002cd018(o, s, func_0016c028(o), 8.0f);
    return 1;
}
}  // namespace o23

// 00184f90 (src/anon/batch_w91.cpp)
namespace o24 {
void func_002cb708(u8*) asm("func_002cb708");
void func_00105110(u8*) asm("func_00105110");
u8* func_0019b380(u8*, u32) asm("func_0019b380");
u8* func_00182e98(u32) asm("func_00182e98");
u32 func_0016c028(u8*) asm("func_0016c028");  // obj_get_attach_or_alt
u8* func_002cd018(u8*, u8*, u32, f32) asm("func_002cd018");

u32 ctarget_00184f90(u8* p, u32 a1, u32, u32) asm("_Z16ctarget_00184f90jjjj");
u32 ctarget_00184f90(u8* p, u32 a1, u32, u32) {
    u8* h = *(u8**)(p + 1288);
    if (h) {
        func_002cb708(h);
        func_00105110(h);
        *(u8**)(p + 1288) = 0;
    }
    u8* t;
    if (*(u8**)(p + 2072)) t = func_0019b380(*(u8**)(p + 2072), a1); else t = 0;
    if (!t && (*(u32*)(p + 1416) & 0x80)) t = func_00182e98(a1);
    if (t) {
        *(u8**)(p + 1288) = func_002cd018(p, t, func_0016c028(p), 8.0f);
        return 1;
    }
    return 0;
}
}  // namespace o24

// 00185050 (src/anon/batch_w30.cpp)
namespace o25 {
void func_00139858(s32) asm("func_00139858");
void func_00139ab0(s32) asm("func_00139ab0");
extern u8* D_003484a0 asm("D_003484a0");
u32 func_002cd1d8(void*, u32) asm("func_002cd1d8");
void func_002cd290(u32, void*, u32) asm("func_002cd290");
void func_00292608(void*) asm("_ZN2Tz8LoadData9FlushTaskEP4TASK");
void wtarget_0013b4b0(u32, u32, u32, u32) asm("_Z16wtarget_0013b4b0jjjj");
void wtarget_00185050(u32, u32, u32, u32) asm("_Z16wtarget_00185050jjjj");
void wtarget_001d7a08(u32, u32, u32, u32) asm("_Z16wtarget_001d7a08jjjj");
void trap_camera_at(void**) asm("_ZN2YS14trap_camera_atEP8BD_VALUE");
void func_00281008_impl(void*) asm("_Z13func_00281008Pv");
void wtarget_0013b4b0(u32, u32, u32, u32) asm("func_0013b4b0");

// Lazily creates the object at +0x508, otherwise forwards to it.
void wtarget_00185050(u32 a, u32 b, u32, u32) {
    u8* p = (u8*)a;
    u32 o = *(u32*)(p + 0x508);
    if (!o) *(u32*)(p + 0x508) = func_002cd1d8(p, b);
    else func_002cd290(o, p, b);
}
}  // namespace o25

// 001850a0 (src/anon/batch_w47.cpp)
namespace o26 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void func_00134508(s32, s32) asm("_Z13func_00134508ii");
void u_call0_0018d790(void) asm("_Z16u_call0_0018d790v");
void wtarget_00198690(u32, u32, u32, u32) asm("_Z16wtarget_00198690jjjj");
u32 func_001b84b8(u32, u32, u32, u32) asm("_Z13func_001b84b8jjjj");
void wtarget_001e7230(u32, u32, u32, u32) asm("_Z16wtarget_001e7230jjjj");
void wtarget_0028d068(u32, u32, u32, u32) asm("_Z16wtarget_0028d068jjjj");
Vec4* func_0016c028(void*) asm("func_0016c028");  // obj_get_attach_or_alt
extern u8 D_00347c88[] asm("D_00347c88");
void func_00133570(void*) asm("func_00133570");
void func_00133590(void*) asm("func_00133590");
void func_00134508(s32 a, s32 b) asm("func_00134508");
void func_002cbca0(Vec4*, u32, Vec4*, u8*) asm("func_002cbca0");

Vec4* func_001850a0(Vec4* out, u8* p) {
    if (!*(u32*)(p + 1288)) {
        asm volatile("vsub.wxyz $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)" : : "r"(out) : "memory");
        return out;
    }
    Vec4 t;
    func_002cbca0(&t, *(u32*)(p + 1288), func_0016c028(p), p + 1360);
    if (out != &t) QCOPY(out, &t);
    return out;
}
}  // namespace o26

// 00185118 (src/anon/tiny_auto80_queue.cpp)
namespace o27 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern u8 D_0034ed0c asm("D_0034ed0c");

void func_00185118(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(2064));
    if (t7 != 0u) {
        f32 f0 = *(f32*)((u32)&D_0034ed0c + (s32)(0));
        *(f32*)((u32)a0 + (s32)(1552)) = f0;
        return;
    }
    *(u32*)((u32)a0 + (s32)(1552)) = 0u;
}
}  // namespace o27

// 00185138 (src/anon/batch_wcx2.cpp)
namespace o28 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
typedef s32 (*Fn5)(void*, void*, u32, void*, u32, u32, u8, u32);
Vec4* func_0016c028(u8*) asm("func_0016c028");  // obj_get_attach_or_alt
extern f32 D_00349e10 asm("D_00349e10");
f32 fabsf(f32) asm("fabsf");  // fabsf
static inline void vu_Scale11(Vec4* s, Vec4* d, f32 f)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : : "r"(s), "r"(d), "f"(f) : "$8", "memory");
}
static inline void vu_Interp11(Vec4* a, Vec4* b, Vec4* d, f32 t)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\t"
                 "vaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\t"
                 "vmulax.xyzw ACC, $vf2, $vf3x\n\tvmaddx.xyzw $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(a), "r"(b), "r"(d), "f"(t) : "$8", "memory");
}
static inline void vu_Copy11(Vec4* d, Vec4* s)
{
    if (d != s) QCOPYN(d, s);
}
struct Obj11 { u8 pad[16]; Vec4 dir; Vec4 pos; };
u32 func_00184540(u32 out, u32 a1, f32 t, f32 s) asm("_Z13func_00184540jjff");
u32 func_00184540(u32 out, u32 a1, f32 t, f32 s) asm("func_00184540");
struct Ray12 { Vec4 a, b, c, hit; u8 pad[48]; u64 on:1; u64 mode:2; u64 rest:29; u64 hitflag:1; u64 rest2:31; u8 pad2[24]; };
void func_00319e90(Ray12*, void*) asm("func_00319e90");
void func_00143928(Ray12*) asm("func_00143928");
static inline void Copy12(Vec4* d, Vec4* s)
{
    if (d != s) QCOPY(d, s);
}

s32 func_00185138(u8* p, Vec4* out, u8 flag, f32 dist)
{
    Ray12 r;
    func_00319e90(&r, p + 1424);
    Copy12(&r.a, func_0016c028(p));  // obj_get_attach_or_alt
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&r.b) : "memory");
    r.mode = 2;
    if (flag) r.on = 1; else r.on = 0;
    s32 ret = 0;
    f32 d = 0.0f;
    while (d < dist) {
        d += 100.0f;
        if (dist < d) d = dist;
        r.c.x = r.c.z = d;
        func_00143928(&r);
        if (!flag && r.hitflag) return ret;
        Copy12(&r.a, &r.hit);
        Copy12(out, &r.hit);
        ret = 1;
    }
    return ret;
}
}  // namespace o28

// 00185278 (src/anon/tiny_auto80_queue.cpp)
namespace o29 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern "C" u32 func_0016ad38(...) asm("func_0016ad38");
extern "C" u32 func_00185138(...) asm("func_00185138");

void func_00185278(u32 a0, u32 a1) {
    struct {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } sp;
    u32 a2 = (u32)(a1 & 0x00ffu);
    u32 s0 = a0;
    u32 v0 = func_00185138(a0, (u32)&sp, a2);
    if (v0 != 0u) {
        func_0016ad38(s0, (u32)&sp);
    }
}
}  // namespace o29

// 001852b8 (src/anon/batch_w43.cpp)
namespace o30 {
u32 func_0016c028(void*) asm("func_0016c028");  // obj_get_attach_or_alt
s32 func_001a7610(u32, void*, s32, f32, f32) asm("func_001a7610");
void func_0016ace0(void*, void*) asm("func_0016ace0");

void func_001852b8(u8* p) {
    u8 buf[16];
    u32 v = func_0016c028(p);  // obj_get_attach_or_alt
    if (func_001a7610(v, buf, (((s32)(*(s64*)(p + 1536) << 29 >> 32)) & 0xf) | 0x10000, 100000.0f, 200.0f))
        func_0016ace0(p, buf);
}
}  // namespace o30

extern "C" const f32 D_0036c8d4 = 0.0f;  // unused constant kept in retail .rodata

// 00185330 (src/anon/batch_w97.cpp)
namespace o31 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Task104 { u32 f0; u32 f4; u8 f8; u32 f12; u32 f16; };
Task104* func_00102788(u32, u32, u32, void (*)(void)) asm("func_00102788");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
struct Menu158;
typedef void (*Menu158Fn)(Menu158*);
struct Menu158 { Menu158Fn* vt; u8 pad[40]; u32 f44; u32 f48; u32 f52; };
extern u8 D_0034ed18[] asm("D_0034ed18");
void func_001980d0(u8*, u32, s32, Vq*, f32) asm("func_001980d0");
void func_001a93b0(u8*, u32) asm("func_001a93b0");
u32 func_00185920(u32, u32, s32) asm("func_00185920");
u32 func_001708f8(u32, s32) asm("func_001708f8");
void func_0017ebe8(u8*, u32) asm("func_0017ebe8");
void func_0017fd30(u8*, u8*) asm("func_0017fd30");
u32 func_001762c0(u8*, u32) asm("func_001762c0");
void func_001c0d38(u8*, u8*, u32, s32) asm("func_001c0d38");

void func_00185330(u8* p, u32 a1, u8* owner, u32 a3, u32 a4, u32 a5) {
    Vq z;
    z.w = z.z = z.y = z.x = 0.0f;
    func_001980d0(p, a1, 12, &z, 3.1415927f);
    *(u32*)p = (u32)D_0034ed18;
    *(u32*)(p + 1416) |= 0x40;
    *(u32*)(p + 264) |= 2;
    *(u32*)(p + 944) = 1;
    *(u8**)(p + 2548) = owner;
    *(u32*)(p + 2552) = 0;
    *(u32*)(p + 2556) = a4;
    *(u32*)(p + 2560) = a5;
    func_001a93b0(p + 1952, a5);
    u32 v = func_00185920(a3, a4, 0);
    if (v) {
        func_0017ebe8(p + 320, func_001708f8(v, -1));
        func_0017fd30(owner + 320, p + 320);
        func_001c0d38(p, owner, func_001762c0(owner, a4), 0);
    }
    *(u32*)(p + 268) |= 0x700;
}
}  // namespace o31

// 00185468 (src/anon/batch_w98.cpp)
namespace o32 {
struct V185 { f32 x, y, z, w; };
void func_001980d0(u8*, u32, s32, V185*, f32) asm("func_001980d0");
void func_001a93b0(u8*, u32) asm("func_001a93b0");
u8* func_00185920(u32, u32, s32) asm("func_00185920");
u32 func_001708f8(u8*, s32) asm("func_001708f8");
void func_0017ebe8(u8*, u32) asm("func_0017ebe8");
void func_0017fd30(u8*, u8*) asm("func_0017fd30");
u32 func_001762c0(u8*, u32) asm("func_001762c0");
void func_001c0d38(u8*, u8*, u32, s32) asm("func_001c0d38");
extern u32 D_0034ed18[] asm("D_0034ed18");

// Constructor: base init, owner link and initial effect attachment.
void func_00185468(u8* p, u32 a1, u8* owner, u32 a3, u32 t0, u32 t1) {
    V185 v;
    v.w = v.z = v.y = v.x = 0.0f;
    func_001980d0(p, a1, 12, &v, 3.1415927f);
    *(u32*)p = (u32)D_0034ed18;
    *(u32*)(p + 1416) |= 0x40;
    *(u32*)(p + 264) |= 2;
    *(u32*)(p + 944) = 1;
    *(u8**)(p + 2548) = owner;
    *(u32*)(p + 2552) = 0;
    *(u32*)(p + 2556) = t0;
    *(u32*)(p + 2560) = t1;
    func_001a93b0(p + 1952, t1);
    u8* r = func_00185920(a3, t0, 0);
    if (r) {
        func_0017ebe8(p + 320, func_001708f8(r, -1));
        func_0017fd30(owner + 320, p + 320);
        func_001c0d38(p, owner, func_001762c0(owner, t0), 0);
    }
    *(u32*)(p + 268) |= 0x700;
}
}  // namespace o32

// 001855a0 (src/anon/tiny_auto80_queue.cpp)
namespace o33 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_001dc920(...) asm("func_001dc920");
extern "C" u32 func_0016b5b8(...) asm("func_0016b5b8");

u32 func_001855a0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(2552));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_001dc920)(r4);
        *(volatile u32*)((u32)r16 + (s32)(2552)) = 0u;
    }
    r4 = r16;
    return ((u32(*)(u32))func_0016b5b8)(r4);
}
}  // namespace o33
