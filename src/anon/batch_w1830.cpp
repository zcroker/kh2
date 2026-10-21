#include "../common/types.h"
struct W1830QW {
    f32 x, y, z, w;
    W1830QW() {}
    W1830QW(const W1830QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1830QW& operator=(const W1830QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// VU0 dot product (xyz)
static inline f32 w1830_vdot(const W1830QW* a, const W1830QW* b) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}
// VU0 cross product (xyz, w = 0)
static inline W1830QW w1830_vcross(const W1830QW& a, const W1830QW& b) {
    W1830QW r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// VU0 length (xyz)
static inline f32 w1830_vlen(const W1830QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
// VU0 scale (wxyz)
static inline W1830QW w1830_vscale(const W1830QW& a, f32 k) {
    W1830QW r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
struct W1830Obj1 { u8 p0[0x10]; W1830QW dir; u8 p20[0x140 - 0x20]; u8 snd[4]; };
struct W1830Prm { u8 p0[0x20]; f32 f20; u8 p24[0xc]; f32 f30; };
struct W1830Obj2 { u8 p0[0x20]; W1830QW v20; u8 p30[0xf0 - 0x30]; W1830Prm* prm; };
extern "C" {
extern f32 D_00349e10;
W1830QW func_0016af58(void*);
void func_0017f540(f32, f32, void*, s32);
void func_001c39d0(s32, W1830Obj1*);
f32 func_001c3ba8(void*, W1830Obj2*);

void func_001c3cf8(s32 a0, W1830Obj1* o) {
    W1830QW c;
    s32 id = 0xcd;
    if (o->dir.w > 0.0f) {
        W1830QW t = func_0016af58(o);
        if (w1830_vdot(&t, &o->dir) < 0.98f) {
            c = w1830_vcross(func_0016af58(o), o->dir);
            if (c.y > 0.0f) id = 0xce; else id = 0xcf;
        }
    }
    func_0017f540(16.0f, 0.0f, o->snd, id);
    func_001c39d0(a0, o);
}

W1830QW func_001c3e20(void* a1, W1830Obj2* o) {
    f32 k = o->prm->f30;
    f32 len = w1830_vlen(&o->v20);
    W1830QW c;
    c = w1830_vscale(func_0016af58(o), o->prm->f20 * (1.0f - k) + len * k);
    o->v20 = c;
    c.y = func_001c3ba8(a1, o);
    return w1830_vscale(c, D_00349e10);
}
}
