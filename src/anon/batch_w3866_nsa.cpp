#include "../common/types.h"
#define W1dee88_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1dee88Vec {
    f32 x, y, z, w;
    W1dee88Vec() {}
    W1dee88Vec(const W1dee88Vec& o) { W1dee88_QCOPY(this, &o); }
    W1dee88Vec& operator=(const W1dee88Vec& o) { if (this != &o) W1dee88_QCOPY(this, &o); return *this; }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1dee88Mtx {
    W1dee88Vec r0, r1, r2, r3;
    W1dee88Mtx() {}
    W1dee88Mtx(const W1dee88Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1dee88Mtx& operator=(const W1dee88Mtx& o) {
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
    void mul(const W1dee88Mtx& a, const W1dee88Mtx& b) {
        W1dee88Mtx& o = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
    }
    // VU0 matrix * column vector.
    W1dee88Vec operator*(const W1dee88Vec& v) const {
        W1dee88Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
struct Key1dee88 { u16 id; u16 flags; f32 pos[3]; f32 rot[3]; f32 scale[3]; };
struct Src1dee88 { u8 pad[16]; u32 flags; u8 pad2[8]; f32 pos[3]; f32 rot[3]; f32 scale[3]; };
struct O1dee88 { W1dee88Mtx world; void* h; Src1dee88* src; u32 pad; f32 frame; u8 pad2[8]; Key1dee88* key; u32 flags; };
void func_0011b6a8(W1dee88Mtx*);
void func_0011b7b0(W1dee88Mtx*, W1dee88Vec*);
W1dee88Vec* func_001dc5f8(void*);
void func_0011bac8(W1dee88Mtx*, W1dee88Vec*);
W1dee88Vec* func_001dc648(void*);
f32 func_0017ce10(f32);
W1dee88Vec* func_001dc620(void*);
double func_00313b80(f32);
s32 func_003142e0(double, double);
void sceVu0CopyVector(void*, void*);
static inline void xform1dee88(W1dee88Vec* out, const W1dee88Mtx* m, const W1dee88Vec* v)
{
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(out), "r"(m), "r"(v) : "memory");
}
static inline void vmul1dee88(W1dee88Vec* out, const W1dee88Vec* a, const W1dee88Vec* b)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(out), "r"(a), "r"(b) : "memory");
}
// Writes a node's position, rotation and scale slots: from the key (world matrix times position) or from the source (world times local transform, axes normalised, lengths kept for scale).
void func_001dee88(O1dee88* o)
{
    W1dee88Vec pos, rot, scale;
    W1dee88Mtx r, m;
    W1dee88Vec len;
    W1dee88Mtx prod;
    W1dee88Mtx *mp, *rp, *pp;
    s32 local = 0;
    if (o->flags & 8) {
        Key1dee88* k = o->key;
        pos.x = k->pos[0];
        pos.y = k->pos[1];
        pos.z = k->pos[2];
        rot.x = k->rot[0];
        rot.y = k->rot[1];
        rot.z = k->rot[2];
        scale.x = k->scale[0];
        scale.y = k->scale[1];
        scale.z = k->scale[2];
        if (k->flags & 1) local = 1;
    } else {
        Src1dee88* s = o->src;
        pos.x = s->pos[0];
        pos.y = s->pos[1];
        pos.z = s->pos[2];
        rot.x = s->rot[0];
        rot.y = s->rot[1];
        rot.z = s->rot[2];
        scale.x = s->scale[0];
        scale.y = s->scale[1];
        scale.z = s->scale[2];
        u32 f = s->flags & 4; local = f != 0;
    }
    pos.w = 1.0f;
    rot.w = 0.0f;
    scale.w = 0.0f;
    if (local) {
        xform1dee88(func_001dc5f8(o->h), &o->world, &pos);
        *func_001dc648(o->h) = rot;
    } else {
        mp = &m;
        func_0011b6a8(mp);
        func_0011b7b0(mp, &rot);
        mp->r3 = pos;
        rp = &r;
        pp = &prod;
        pp->mul(o->world, *mp);
        *rp = *pp;
        *func_001dc5f8(o->h) = rp->r3;
        len.x = rp->r0.normalize();
        len.y = rp->r1.normalize();
        len.z = rp->r2.normalize();
        *(s32*)&len.w = 0;
        rp->r3.unit();
        func_0011bac8(rp, func_001dc648(o->h));
        func_001dc648(o->h)->x = func_0017ce10(func_001dc648(o->h)->x);
        func_001dc648(o->h)->y = func_0017ce10(func_001dc648(o->h)->y);
        func_001dc648(o->h)->z = func_0017ce10(func_001dc648(o->h)->z);
        if (o->src->flags & 0x100) {
            W1dee88Vec* d = func_001dc620(o->h);
            vmul1dee88(&pp->r0, &scale, &len);
            *d = pp->r0;
            goto tail;
        }
    }
    if (func_003142e0(func_00313b80(o->frame), 0) <= 0) {
        *func_001dc620(o->h) = scale;
    }
tail:
    if (o->flags & 4) {
        sceVu0CopyVector((u8*)o->key + 32, o->key);
        sceVu0CopyVector((u8*)o->key + 48, (u8*)o->key + 16);
    }
}
}
