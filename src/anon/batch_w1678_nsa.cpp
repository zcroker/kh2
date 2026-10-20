#include "../common/types.h"
struct Cam1998Vec {
    f32 x, y, z, w;
    Cam1998Vec() {}
    Cam1998Vec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    Cam1998Vec& operator=(const Cam1998Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Cam1998Mtx {
    f32 m[16];
    Cam1998Mtx() {}
    Cam1998Mtx(const Cam1998Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    Cam1998Mtx& operator=(const Cam1998Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // inverse of a rotation + translation matrix, in place
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    Cam1998Mtx inverse() const {
        Cam1998Mtx r(*this);
        r.invOrtho();
        return r;
    }
    Cam1998Vec operator*(const Cam1998Vec& v) const {
        Cam1998Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                     "sqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&v), "r"(this) : "memory");
        return r;
    }
    Cam1998Mtx operator*(const Cam1998Mtx& b) const {
        Cam1998Mtx r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Cam1998Mtx34 { f32 m[12]; };
struct Cam1998Act { u8 pad0[0x10]; Cam1998Vec vel; };

extern "C" {
extern s32 D_00361f60;
extern f32 D_00362d88;
s32 func_002ceb28(void);
s32 func_002e0fe8(s32);
Cam1998Mtx func_002e10d0(s32);
Cam1998Mtx* func_002e10c0(s32);
Cam1998Mtx34 func_002e1108(s32);
Cam1998Vec* func_0016c028(Cam1998Act*);
void func_0016ace0(Cam1998Act*, const Cam1998Vec&);
void func_0016b070(Cam1998Act*, Cam1998Vec*);
void func_0011b6a8(Cam1998Mtx*);
void func_0011b720(Cam1998Mtx*, f32);
void func_002d08b8(Cam1998Vec*, const Cam1998Mtx&);

void func_002e1998(void*, Cam1998Act* o)
{
    s32 cam = D_00361f60;
    if (func_002ceb28() == 0) return;
    Cam1998Vec pos(0.0f, 0.0f, 0.0f, 1.0f);
    if (func_002e0fe8(cam) != 0) {
        Cam1998Mtx view = func_002e10d0(cam);
        Cam1998Mtx inv = func_002e10c0(cam)->inverse();
        {
            Cam1998Vec p = inv * *func_0016c028(o);
            p.z = D_00362d88;
            Cam1998Vec q = view * p;
            Cam1998Mtx vi = view.inverse();
            Cam1998Vec q2 = vi * q;
            Cam1998Vec q3 = view * q2;
            q = q3;
            func_0016ace0(o, q);
        }
        func_0011b6a8(&inv);
        func_0011b720(&inv, 3.1415927f);
        inv = view * inv;
        func_002d08b8(&pos, inv);
        func_0016b070(o, &pos);
    } else {
        const Cam1998Mtx34 m = func_002e1108(cam);
        func_002d08b8(&pos, *(const Cam1998Mtx*)&m);
        func_0016b070(o, &pos);
        const Cam1998Vec t;
        func_0016ace0(o, t);
        asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&o->vel) : "memory");
    }
}
}
