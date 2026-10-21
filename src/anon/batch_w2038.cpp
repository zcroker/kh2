#include "../common/types.h"

struct EVR { f32 x, y, z, w; } __attribute__((aligned(16)));
struct EV {
    f32 x, y, z, w;
    EV() {}
    EV& operator=(const EVR& o) {
        if ((void*)this != (void*)&o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    EV& operator=(const EV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    EV operator-(const EV& b) const {
        EV r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 lensq() const {
        f32 l;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(l) : "r"(this) : "$8", "memory");
        return l;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct EActor {
    u8 pad0[0x10];
    EV dir;
    u8 pad20[0x134];
    s32 x154;
    u8 pad158[0x3b0];
    s32 x508;
};
struct EObj;
struct EObjVt { void* f[8]; void (*f20)(EObj*, EActor*, s32); };
struct EObj { EObjVt* vt; };

extern "C" {
s32 func_002eb3b8(EActor*);
EV* func_0016c028(EActor*);
EVR func_0016af58(EActor*);
EVR func_002cba88(s32, const EV&, const EVR&, f32, f32);
void e_set_dir(EActor*, const EV&) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");
void func_002eda90(f32, s32, s32);
u64 func_00313b80(f32) __attribute__((const));
s32 func_003142e0(u64, u64) __attribute__((const));
extern u8 D_01e2c064;
extern f32 D_0036354c;
extern s32 D_003637d0;
extern f32 D_00349e10;
extern EV D_01e2c050;

void func_002ec5f8(EObj* self, EActor* a) {
    EV t;
    s32 id = a->x508;
    if (func_002eb3b8(a)) return;
    t = *func_0016c028(a);
    f32 r = 24.0f;
    a->dir = func_002cba88(id, t, func_0016af58(a), r, 0.5f);
    a->dir.normalize();
    a->dir.w = r;
    e_set_dir(a, a->dir);
    if (D_01e2c064) {
        if (D_0036354c < 0.0f && a->x154 == 269) {
            func_002eda90(60.0f, D_003637d0, 1);
            D_0036354c = 12.0f;
        } else {
            D_0036354c -= D_00349e10;
        }
    }
    t = D_01e2c050 - *func_0016c028(a);
    t.y = 0.0f;
    if (func_003142e0(func_00313b80(t.lensq()), 0x40e3880000000000ULL) < 0)
        self->vt->f20(self, a, 0);
}
}
