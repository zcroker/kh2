#include "../common/types.h"
struct V11de88 {
    f32 x, y, z, w;
    V11de88() {}
    ~V11de88() {}
    V11de88& operator=(const V11de88& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V11de88 operator+(const V11de88& b) const {
        V11de88 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V11de88 operator-(const V11de88& b) const {
        V11de88 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V11de88 operator*(f32 s) const {
        V11de88 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 length() const {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct R11de88 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M11de88 {
    R11de88 r[4];
    M11de88() {}
    M11de88(const M11de88& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    M11de88& operator=(const M11de88& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    M11de88 operator*(const M11de88& b) const {
        M11de88 o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Kind11de88 { s32 kind; };
struct Res11de88 { u8 pad[4]; Kind11de88* k; };
struct Self11de88 { u8 pad0[20]; Res11de88* res; u8 pad1[64 - 24]; M11de88 m64; M11de88 m128; };
struct Desc11de88 { u32 flags; };
struct Out11de88 { R11de88 v[4]; };
struct Mat11de88 { M11de88 m; R11de88 e[2]; };
void cam11de88_dtor(void*) asm("_Z13func_00134d58Pv");
extern "C" {
void func_0011dd08(V11de88*, void*);
void func_00134d10(void*);
void func_00134d60(void*, V11de88*);
void func_00134df8(void*, V11de88*, Out11de88*, Mat11de88*, void*);
void* func_00135640(void);
void func_0011be50(M11de88*);
void func_0010abf0(Self11de88*, M11de88*, Desc11de88*, void*, Mat11de88*, Out11de88*, void*, void*);
}
struct Cam11de88 {
    V11de88 pos;
    f32 f[4];
    Cam11de88() { func_00134d10(this); }
    ~Cam11de88() { cam11de88_dtor(this); }
};
extern "C" {
void func_0011de88(Self11de88* s, Desc11de88* d, void* a2, void* a3, void* e)
{
    Out11de88 o;
    Mat11de88 mt;
    V11de88 box[8];
    func_0011dd08(box, a3);
    if (d->flags & 1) {
        Cam11de88 c;
        V11de88 ctr;
        ctr = (box[0] + box[6]) * 0.5f;
        ctr.y -= (box[6] - box[0]).length() * 8.0f;
        func_00134d60(&c, &ctr);
        func_00134df8(&c, box, &o, &mt, e);
    } else {
        func_00134df8(func_00135640(), box, &o, &mt, e);
    }
    if (s->res->k->kind != 2) {
        M11de88 t(s->m64);
        func_0011be50(&t);
        mt.m = mt.m * s->m128 * t;
    } else {
        mt.m = mt.m * s->m128;
    }
    func_0010abf0(s, &s->m64, d, a2, &mt, &o, a3, e);
}
}
