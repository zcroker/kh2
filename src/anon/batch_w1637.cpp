#include "../common/types.h"

#define W1637_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")

struct W1637Vec {
    f32 x, y, z, w;
    W1637Vec() {}
    W1637Vec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    void Set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    W1637Vec operator-(const W1637Vec& b) const {
        W1637Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1637Vec(const W1637Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1637Vec& operator=(const W1637Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct W1637Mtx {
    W1637Vec r[4];
    W1637Mtx() {}
    W1637Mtx(const W1637Mtx& o) { W1637_QCOPY4(this, &o); }
    W1637Mtx& operator=(const W1637Mtx& o) { if (this != &o) W1637_QCOPY4(this, &o); return *this; }
    W1637Vec operator*(const W1637Vec& v) const {
        W1637Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void Inverse() {
        asm volatile(
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.xyzw $vf1, $vf1, Q\n\tvmulq.xyzw $vf2, $vf2, Q\n\tvmulq.xyzw $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    W1637Mtx operator*(const W1637Mtx& b) const {
        W1637Mtx o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));

struct W1637Pad16 { u8 p[16]; };
struct W1637Cam : W1637Pad16, W1637Mtx {};
struct W1637Ent { u8 p0[8]; u32 f8; };
struct W1637Obj2;
struct W1637Obj2 {
    u8 p0[0xc];
    W1637Ent* ent;          // 0x00c
    W1637Vec v010;          // 0x010
    W1637Vec v020;          // 0x020
    u8 p030[0xd8];
    u32 f108;               // 0x108
    u8 p10c[0x54];
    u32 f160;               // 0x160
    u8 p164[0x3fc];
    W1637Vec v560;          // 0x560
    W1637Obj2* f570; u8 p574[2]; u16 h576;   // 0x570
    u8 p578[0x438];
    f32 f9b0;               // 0x9b0
};

static inline bool W1637_Flag12(u32 f) { return (f & 1) || (f & 2); }
static inline bool W1637_Bit(u32 f, u32 m) { return (f & m) != 0; }
static inline bool W1637_Flag4(u32 f) { return W1637_Bit(f, 4) || W1637_Bit(f, 8) || W1637_Bit(f, 0x10); }
static inline bool W1637_Flag20(u32 f) { return W1637_Bit(f, 0x20) || W1637_Bit(f, 0x1000000); }

extern "C" {
extern f32 D_00349e10;
extern W1637Mtx D_003511d0;
s32 W1637_is_attach(W1637Obj2*) asm("_ZN2YS3OBJ9is_attachEv");
void W1637_detach(W1637Obj2*) asm("_ZN2YS3OBJ6detachEv");
s32 W1637_ctarget_0019ba60(W1637Obj2*) asm("_Z16ctarget_0019ba60jjjj");
W1637Vec* W1637_get_pos(W1637Obj2*) asm("func_0016c028");
W1637Cam* func_00106a60(s32);

void func_0016a5b0(W1637Obj2* o)
{
    if (o->f160 & 0x40) {
        if (!(o->f108 & 0x1000000)) {
            if (!W1637_Flag12(o->ent->f8)) o->v020.Zero();
            o->f108 |= 0x1000000;
        }
        o->f108 &= ~0x800000;
    } else if (W1637_Flag20(o->f160)) {
        o->f108 |= 0x800000;
        o->f108 &= ~0x1000000;
    } else {
        o->f108 &= ~0x800000;
        o->f108 &= ~0x1000000;
    }
    if (W1637_is_attach(o) && (o->h576 & 1)) {
        if (!W1637_ctarget_0019ba60(o->f570) || !(o->f570->f160 & 0x8000)) W1637_detach(o);
    }
    if (o->f9b0 > 0.0f) {
        if (!W1637_Flag4(o->f160)) o->f9b0 = 0.0f;
        else o->f9b0 -= D_00349e10;
    }
    o->v010.Zero();
    if (o->f108 & 0x10) {
        W1637Vec pos = *W1637_get_pos(o);
        pos.w = 1.0f;
        pos = D_003511d0 * pos;
        pos.w = 1.0f;
        W1637Mtx inv = *func_00106a60(1);
        inv.Inverse();
        pos = inv * pos;
        o->v560 = pos - *W1637_get_pos(o);
    } else {
        o->v560.Zero();
    }
}
}
