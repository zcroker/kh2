#include "../common/types.h"
// VU0 vector/matrix helpers (inline asm: the original uses the VU0 macro library).
// Built with -fno-strict-aliasing (_nsa): func_0017d348 needs the combined temp slots and
// func_001bd6a8 needs the u32-store/u64-load reload.
#define W1975_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1975_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1975V {
    f32 x, y, z, w;
    W1975V() {}
    W1975V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1975V(const W1975V& o) { W1975_QCOPY(this, &o); }
    W1975V& operator=(const W1975V& o) { if (this != &o) W1975_QCOPY(this, &o); return *this; }
    void scale(f32 s) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(this), "f"(s) : "$8", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
// gas would move the final sqc2 into a following branch delay slot; the original keeps it out.
static inline W1975V W1975_cross(const W1975V& a, const W1975V& b) {
    W1975V o;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\t.set noreorder\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(&a), "r"(&b) : "memory");
    return o;
}
struct W1975M {
    W1975V r[4];
    W1975M() {}
    W1975M& operator=(const W1975M& o) { if (this != &o) W1975_QCOPY4(this, &o); return *this; }
    W1975V operator*(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t.set noreorder\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    W1975V apply3(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf4, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tsqc2 $vf4, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
inline void* operator new(unsigned int, void* p) { return p; }

void W1975_identity(W1975M*) asm("_Z13func_0011b6a8Pv");
void W1975_rotateX(W1975M*, f32) asm("_ZN2kn7FMatrix7rotateXEf");
void W1975_rotateY(W1975M*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
void W1975_rotateZ(W1975M*, f32) asm("_ZN2kn7FMatrix7rotateZEf");
f32 W1975_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");

// func_001bd6a8 types
struct W1975Slot {
    u8 b0, b1; u16 id; u8 b4; u8 type; u16 pad6; s32 arg;
    bool small() { return type < 4; }
};
struct W1975Wk { u64 d0; u64 d8; u8 pad[32]; W1975V v; };
struct W1975Ai { void** vt; };
struct W1975Self {
    void** vt;
    u8 sub4[4];
    u32 f8;
    u8 pad12[20];
    u32 flags;
    bool isB0() { u32 f = flags; u8 b = f & 1; return b; }
    u8 pad36[2528 - 36];
    W1975Ai* ai;
    W1975Wk* wk;
    u8 pad2536[16];
    u8 sub2552[36];
    W1975Slot slot;
    u8 pad2600[8];
    W1975V v;
};
s32 W1975_Slot_is_exist(W1975Slot*) asm("_ZN2YS12COMMAND_SLOT8is_existEv");
s32 W1975_Slot_is_beep(const W1975Slot*) asm("_ZNK2YS12COMMAND_SLOT7is_beepEv");
s32 W1975_u_call4_001b8e88(u32) asm("_Z16u_call4_001b8e88jjjj");
s32 W1975_ctarget_001c8db8(void*, u32) asm("_Z16ctarget_001c8db8jjjj");
void W1975_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
typedef void (*W1975VFn)(W1975Self*);
typedef s32 (*W1975AFn)(W1975Ai*);

// func_001e1160 types
struct W1975Obj { u8 pad[36]; s32 f24; s32 f28; };

// func_0022eb80 types
struct W1975Ev { s16 h0; s16 h2; s16 h4; s16 h6; s32 f8; s32 f12; s16 h16; s16 h18; };
struct W1975Work { u8 pad[8]; u8* p8; };
f32 W1975_Ev_get_float(void*) asm("_ZN2sa5EVENT9get_floatEPv");
W1975Work* W1975_Ev_entry_work_get(s32) asm("_ZN2sa5EVENT14entry_work_getEi");
// The mangled name lists only the f32, but the call passes a vector pointer in a1 as well.
void W1975_LookAt_release(u8*, f32, W1975V*) asm("_ZN2YS6LOOKAT7releaseEf");

extern "C" {
extern f32 D_00349e10;
extern u8 D_00351ec8;
extern u32 D_003638d0;
extern s8 D_01dadaf0;
extern W1975V D_01dadb00;
f32 func_0017d160(const W1975V*, const W1975V*);
W1975M func_0017d1d8(const W1975V&, f32);
void func_0017bf40(u8*);
void func_0019d790(u8*);
void func_001bdd50(W1975Self*);
void func_001bd3a0(W1975Self*);
s32 func_001bd918(W1975Self*, s32, s32);
void func_0013c720(void);
W1975V* func_001e0ce8(W1975Obj*);
void func_001e0d68(W1975Obj*, W1975V*);
s32 func_002282f0(s32);
void func_001ba028(u8*);
void func_002fd188(void (*)(void));
void func_0022f8e8(void);
void func_001b0858(u8*, f32, W1975V*, s32);

static inline f32 W1975_clampf(f32 v, f32 lo, f32 hi) { if (hi < v) v = hi; else if (v < lo) v = lo; return v; }

// Rotates a toward b by at most t * D_00349e10 radians.
W1975V func_0017d348(const W1975V& a, const W1975V& b, f32 t) {
    W1975V axis;
    W1975V na;
    W1975V nb;
    W1975M m;
    na = a;
    na.normalize();
    nb = b;
    nb.normalize();
    f32 ang;
    { W1975V c1 = na; W1975V c2 = nb; ang = func_0017d160(&c1, &c2); }
    t = t * D_00349e10;
    ang = W1975_clampf(ang, -t, t);
    axis = W1975_cross(na, nb);
    axis.normalize();
    m = func_0017d1d8(axis, ang);
    return m.apply3(na);
}

void func_001bd6a8(W1975Self* self) {
    if (self->ai == 0) return;
    if (self->wk == 0) return;
    func_0017bf40(self->sub4);
    ((W1975VFn)self->vt[3])(self);
    func_0019d790(self->sub2552);
    func_001bdd50(self);
    if (((W1975AFn)self->ai->vt[16])(self->ai) == 0 || self->isB0() || W1975_ctarget_001c8db8(&D_00351ec8, 0) != 0) {
        func_001bd3a0(self);
        self->v.zero();
        return;
    }
    if (self->flags & 2) self->slot.type = 5;
    self->v = self->wk->v;
    if (!(self->flags & 2) && (self->wk->d8 & 0x400) && W1975_Slot_is_exist(&self->slot)) {
        if (self->slot.small()) {
            s32 r = W1975_u_call4_001b8e88(self->slot.id);
            if (func_001bd918(self, r, self->slot.arg)) {
                func_0013c720();
                self->f8 |= 0x10;
            }
        } else if (W1975_Slot_is_beep(&self->slot)) {
            W1975_systemSePlay(5, 0);
        }
    } else {
        ((W1975VFn)self->vt[4])(self);
    }
    if (self->wk->d0 & 0x100) self->f8 |= 1;
    if (self->wk->d0 & 0x200) self->f8 |= 4;
    func_001bd3a0(self);
}

static inline f32 W1975_frand() {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return (f32)D_003638d0 * 2.3283064e-10f;
}
static inline f32 W1975_frange(f32 lo, f32 hi) { return lo + W1975_frand() * (hi - lo); }

void func_001e1160(W1975Obj* self) {
    W1975V v;
    W1975M m;
    v = *func_001e0ce8(self);
    v.scale(-1.0f);
    v.y -= W1975_frange(0.5f, 1.0f);
    v.w = 0.0f;
    W1975_identity(&m);
    W1975_rotateY(&m, W1975_frange(-0.17453292f, 0.17453292f));
    v = m * v;
    v.normalize();
    func_001e0d68(self, &v);
    self->f28 = 0;
    self->f24 = 4;
}

// D_01dadb00 is a function-local static (guard D_01dadaf0, empty atexit dtor func_0022f8e8).
void func_0022eb80(W1975Ev* self) {
    W1975Work* w;
    f32 rx, rz;
    W1975V v;
    W1975M m;
    if (func_002282f0(self->h4) != 0) return;
    w = W1975_Ev_entry_work_get(self->h6);
    func_001ba028(w->p8);
    if (!D_01dadaf0) {
        D_01dadaf0 = 1;
        new (&D_01dadb00) W1975V(0.0f, 1.0f, 0.0f, 1.0f);
        func_002fd188(func_0022f8e8);
    }
    f32 k = 0.017453292f;
    f32 az = W1975_Ev_get_float(&self->f12) * k;
    f32 ax = W1975_Ev_get_float(&self->f8) * k;
    rz = W1975_FixRadian(az);
    rx = W1975_FixRadian(ax);
    W1975_identity(&m);
    W1975_rotateX(&m, rx);
    W1975_rotateZ(&m, rz);
    v = m * D_01dadb00;
    v.normalize();
    if (self->h18 == 0) func_001b0858(w->p8 + 1184, (f32)self->h16 * 2.0f, &v, 0);
    else W1975_LookAt_release(w->p8 + 1184, (f32)self->h16 * 2.0f, &v);
}
}
