// 00116db0: per-frame update of the 24 effect slots attached to an object (load/free the effect
// handle, then place it on a model node, a camera node, or the inverse camera). Partial asm:
// VU0/128-bit helpers, plus register pins (slot position in s0 in cases 1 and 2, the call
// argument 1 in a0) that reproduce the original's reload and delay-slot choices.
#include "../common/types.h"
#define E116_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct E116Vec {
    f32 x, y, z, w;
    E116Vec() {}
    E116Vec(const E116Vec& o) { E116_QCOPY(this, &o); }
    E116Vec& operator=(const E116Vec& o) { if (this != &o) E116_QCOPY(this, &o); return *this; }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct E116Mtx {
    E116Vec r0, r1, r2, r3;
    E116Mtx() {}
    E116Mtx(const E116Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    E116Mtx& operator=(const E116Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    E116Mtx operator*(const E116Mtx& b) const {
        E116Mtx o;
        const E116Mtx& a = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
        return o;
    }
    // general 4x4 inverse in place (affine: cofactors via outer products, 1/det in Q)
    void inverse() {
        asm volatile(".set noreorder\n\t"
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
            "vmulq.wxyz $vf1, $vf1, Q\n\tvmulq.wxyz $vf2, $vf2, Q\n\tvmulq.wxyz $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    E116Vec operator*(const E116Vec& v) const {
        E116Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
// transform a point (w = 1) by a VU0 matrix
static inline void E116_xformPt(E116Vec* out, const E116Mtx* m, const E116Vec* v)
{
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
struct E116Model { u8 pad[340]; s32 f340; u8 pad1[8]; u32 f352; };
struct E116Sub { u8 pad[24]; s32 f24; };
struct E116Cam { u8 pad[320]; E116Sub sub; u8 pad1[4]; u32 f352; };
struct E116Slot {
    s32 flags;
    s32 res;
    s32 handle;
    u32 f12;
    s32 f16;
    s32 f20;
    s32 node;
    s32 pad28;
    E116Vec rot;
    E116Vec pos;
};
struct E116Obj {
    u8 pad0[4];
    E116Model* model;
    u8 pad8[24];
    E116Slot slots[24];
    s32 f1568;
    s32 f1572;
};
extern "C" E116Cam* func_00111e38(s32);
extern "C" s32 func_0019ba60(E116Model*);
extern "C" void func_001dc920(s32);
extern "C" void func_00117910(E116Obj*, s32);
extern "C" void func_00117aa8(E116Obj*, s32);
extern "C" s32 func_001dc9d0(s32);
extern "C" s32 func_001dc9e0(s32);
extern "C" s32 func_0016abf8(E116Model*, s32, u32, s32);
extern "C" u8* func_00106a60(s32);
extern "C" E116Vec* func_001dc5f8(s32);
extern "C" E116Vec* func_001dc620(s32);
extern "C" E116Vec* func_001dc648(s32);
extern "C" f32* func_001dc670(s32);
extern "C" void func_0016b0e0(void*, s32, E116Mtx*);
extern "C" void func_0011b6a8(E116Mtx*);
extern "C" void func_0011b7b0(E116Mtx*, E116Vec*);
extern "C" void func_00115c08(E116Obj*, E116Mtx*, E116Vec*, E116Vec*, E116Vec*, u8);
extern "C" void func_001161c8(E116Obj*, E116Mtx*, E116Vec*, E116Vec*, E116Vec*, u8);
extern "C" f32 func_00194690(E116Model*);
extern "C" void func_0018f028(s32);


extern "C" {
void func_00116db0(E116Obj* o)
{
    E116Mtx M;
    E116Mtx mtx;
    E116Mtx M2;
    E116Vec scale, rot, pos;
    E116Cam* cam = func_00111e38(0);
    for (s32 i = 0; i < 24; i++) {
        if (o->slots[i].handle) {
            if (!func_0019ba60(o->model) || (o->slots[i].flags & 0x40000000)) {
                func_001dc920(o->slots[i].handle);
                func_00117910(o, i);
                continue;
            }
            if (func_001dc9d0(o->slots[i].handle)) {
                if (o->slots[i].f20 >= 0) {
                    s32 chg = 0;
                    switch (o->slots[i].flags & 3) {
                    case 0:
                    case 1:
                        if (o->slots[i].f20 != o->model->f340) chg = 1;
                        break;
                    case 2:
                        {
                    E116Sub* sb = &cam->sub;
                    if (!(cam->f352 & 0x4000) || o->slots[i].f20 != -sb->f24) chg = 1;
                }
                        break;
                    }
                    if (chg) func_00117aa8(o, i);
                }
            } else {
                bool lp = o->slots[i].f12 & 1;
                if (lp) o->slots[i].flags |= 0x40000000;
            }
        } else if (o->slots[i].res >= 0) {
            o->slots[i].handle = func_0016abf8(o->model, o->slots[i].res, o->slots[i].f12 & ~1, o->slots[i].f16);
            if (o->slots[i].handle) o->slots[i].res = -1;
        }
        if (!o->slots[i].handle || !func_001dc9e0(o->slots[i].handle)) continue;
        if (o->slots[i].node < 0) continue;
        switch (o->slots[i].flags & 3) {
        case 0:
            break;
        case 1: {
            func_0016b0e0(o->model, o->slots[i].node, &mtx);
            pos = mtx.r3;
            if (!(o->slots[i].flags & 8) && o->slots[i].node != 0x4000) func_0016b0e0(o->model, 0x4000, &mtx);
            mtx.r3 = pos;
            func_0011b6a8(&M2);
            func_0011b7b0(&M2, &o->slots[i].rot);
            M2.r3 = o->slots[i].pos;
            M = mtx * M2;
            func_00115c08(o, &M, &scale, &rot, &pos, 1);
            *func_001dc620(o->slots[i].handle) = scale;
            *func_001dc648(o->slots[i].handle) = rot;
            *func_001dc5f8(o->slots[i].handle) = pos;
            if (o->slots[i].flags & 0x20) {
                f32* q = func_001dc670(o->slots[i].handle);
                q[3] = func_00194690(o->model);
            }
            if (o->slots[i].flags & 0x10) {
                o->slots[i].flags |= 3;
                register E116Vec* qp asm("$16");
                register s32 one asm("$4") = 1;
                asm volatile("" : "+r"(one));
                qp = &o->slots[i].pos;
                asm("" : "+r"(qp));
                u8* c = func_00106a60(one);
                E116_xformPt(qp, (E116Mtx*)(c ? c + 16 : 0), &pos);
            }
            break;
        }
        case 2: {
            register E116Vec* pp asm("$16");
            func_0016b0e0(cam, o->slots[i].node, &mtx);
            pos = mtx.r3;
            if (!(o->slots[i].flags & 8) && o->slots[i].node != 0x4000) func_0016b0e0(cam, 0x4000, &mtx);
            mtx.r3 = pos;
            pp = &o->slots[i].pos;
            asm("" : "+r"(pp));
            func_0011b6a8(&M2);
            func_0011b7b0(&M2, &o->slots[i].rot);
            M2.r3 = *pp;
            M = mtx * M2;
            func_001161c8(o, &M, &scale, &rot, &pos, 1);
            *func_001dc620(o->slots[i].handle) = scale;
            *func_001dc648(o->slots[i].handle) = rot;
            *func_001dc5f8(o->slots[i].handle) = pos;
            if (o->slots[i].flags & 0x10) {
                o->slots[i].flags |= 3;
                u8* c = func_00106a60(1);
                E116_xformPt(pp, (E116Mtx*)(c ? c + 16 : 0), &pos);
            }
            break;
        }
        case 3: {
            u8* c = func_00106a60(1);
            E116Mtx m = *(E116Mtx*)(c ? c + 16 : 0);
            m.inverse();
            E116_xformPt(&pos, &m, &o->slots[i].pos);
            *func_001dc5f8(o->slots[i].handle) = pos;
            break;
        }
        }
    }
    if (o->f1568) {
        if (!func_0019ba60(o->model) || (o->f1572 >= 0 && (o->f1572 != o->model->f340 || (o->model->f352 & 2)))) {
            func_0018f028(o->f1568);
            o->f1568 = 0;
        }
    }
}

}
