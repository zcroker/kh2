#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa): stack temporaries of different types share slots.
// 002e6ab0: path frame at time t: interpolates the key rotation (matrix -> quaternion slerp) and position.
namespace n002e6ab0 {
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV operator+(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator-(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator*(f32 s) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Row {
    f32 x, y, z, w;
    void operator+=(const QV& v) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&v) : "memory");
    }
} __attribute__((aligned(16)));
struct Mtx;
void mtx_ident(void*) asm("func_0011b6a8");
void mtx_rotxyz(Mtx*, const QV&) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
struct Mtx {
    Row r[4];
    Mtx() {}
    void Identity() { mtx_ident(this); }
    void RotateXYZ(const QV& v) { mtx_rotxyz(this, v); }
    void AddTrans(const QV& v) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)\n\t.set reorder" : : "r"(this), "r"(&v) : "memory");
    }
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    Mtx operator*(const Mtx& b) const {
        Mtx o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Quat;
void quat_dtor(Quat*) asm("_Z13func_002e44b8Pv");
void quat_from_mtx(Quat*, Mtx*) asm("func_002e42d8");
struct Quat {
    f32 x, y, z, w;
    Quat() {}
    ~Quat() { quat_dtor(this); }
} __attribute__((aligned(16)));
extern "C" Quat func_002e47a8(const Quat&, const Quat&, f32);
Mtx quat_to_mtx(const Quat&) asm("func_002e4588");
struct KV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct PathKey { KV pos; KV rot; };
struct Path { u8 pad0[3]; u8 flags; s32 count; f32 start; u32 padc; PathKey key[1]; };
static inline QV conv(const KV& p) { return QV(p.x, -p.y, -p.z, 0.0f); }
void path_seek(Path* p, s32* idx, f32* frac, f32 t) asm("func_002e66f0");
extern "C" {
void func_002e6ab0(Path* p, Mtx* m, f32 t)
{
    s32 idx;
    f32 frac;
    path_seek(p, &idx, &frac, t);
    PathKey* k0 = &p->key[idx];
    PathKey* k1 = &p->key[idx + 1];
    if (frac > 0.0001f) {
        QV r0(k0->rot.x, -k0->rot.y, -k0->rot.z, 0.0f);
        QV r1(k1->rot.x, -k1->rot.y, -k1->rot.z, 0.0f);
        Mtx m0, m1;
        m0.Identity();
        m1.Identity();
        m0.RotateXYZ(r0);
        m1.RotateXYZ(r1);
        Quat q0;
        quat_from_mtx(&q0, &m0);
        Quat q1;
        quat_from_mtx(&q1, &m1);
        Quat q = func_002e47a8(q0, q1, frac);
        QV a = conv(k0->pos);
        QV b = conv(k1->pos);
        QV pos = a + (b - a) * frac;
        m->Identity();
        if (p->flags & 1) {
            m->AddTrans(QV(0.0f, 100.0f, 0.0f, 0.0f));
            *m = quat_to_mtx(q) * *m;
            m->AddTrans(QV(0.0f, -100.0f, 0.0f, 0.0f));
        } else {
            *m = quat_to_mtx(q);
        }
        m->AddTrans(pos);
    } else {
        QV pos = conv(k0->pos);
        QV rot(k0->rot.x, -k0->rot.y, -k0->rot.z, 0.0f);
        m->Identity();
        if (p->flags & 1) {
            m->AddTrans(QV(0.0f, 100.0f, 0.0f, 1.0f));
            m->RotateXYZ(rot);
            m->AddTrans(QV(0.0f, -100.0f, 0.0f, 1.0f));
        } else {
            m->RotateXYZ(rot);
        }
        m->AddTrans(pos);
    }
}
}
}

// 002d8d68: swing sweep test: interpolates 4 in-between frames from m3 to m2 (quaternion slerp + position lerp),
// transforms the hit point by each frame, then tests every target near obj against those points.
namespace n002d8d68 {
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV(const QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    QV operator+(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator-(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator*(f32 s) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 Length() const {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct PV : QV {
    PV() {}
    ~PV() {}
    PV& operator=(const QV& o) { QV::operator=(o); return *this; }
} __attribute__((aligned(16)));
struct Mtx {
    QV r[4];
    Mtx() {}
    ~Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    QV operator*(const QV& v) const {
        QV o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "sqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    // Inverse of an orthonormal frame: transpose the rotation, translation = -(R^T t).
    void InvOrtho() {
        asm volatile(".set noreorder\n\tlq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct Quat;
void quat_dtor(Quat*) asm("_Z13func_002e44b8Pv");
struct Quat {
    f32 x, y, z, w;
    Quat() {}
    ~Quat() { quat_dtor(this); }
} __attribute__((aligned(16)));
struct Hit { s32 a; f32 b; s32 x8; s32 c; QV v; };
struct Rgn { u8 pad[8]; s16 x, y, z; };
struct Kind { u8 pad[5]; u8 kind; };
struct LFlag { u8 pad; };
struct Obj;
typedef void (*ObjFn)(Obj*);
struct Obj { ObjFn* vt; u8 pad4[4]; Kind* kind; u8 pad0c[2040 - 12]; u32 f7f8; u8 pad7fc[2800 - 2044]; LFlag flag; };
s32 lflag_check(LFlag*, u32) asm("_ZN2Ti5LFlag5checkEj");
void quat_from_mtx(Quat*, Mtx*) asm("func_002e42d8");
Quat quat_slerp(const Quat&, const Quat&, f32) asm("func_002e47a8");
Mtx quat_to_mtx(const Quat&) asm("func_002e4588");
extern "C" {
Rgn* func_0016bc20(Obj*, s32, s32);
void func_0018a818(Hit*, Obj*, Rgn*);
Obj* func_001b9bc8(Obj*);
QV* func_0016c028(Obj*);
s32 func_0018a550(Hit*, Hit*);
void func_002cf280(LFlag*, u32, u32);
s32 func_002d8d68(void* self, Obj* obj, Mtx* m2, Mtx* m3)
{
    Quat qa;
    quat_from_mtx(&qa, m3);
    QV va = m3->r[3];
    Quat qb;
    quat_from_mtx(&qb, m2);
    QV vb = m2->r[3];
    Rgn* rg = func_0016bc20(obj, 2, -1);
    if (!rg) return 0;
    Mtx mats[5];
    Hit x;
    func_0018a818(&x, obj, rg);
    for (s32 i = 1; i < 5; i++) {
        f32 t = (f32)i / 5.0f;
        mats[i] = quat_to_mtx(quat_slerp(qa, qb, t));
        mats[i].r[3] = (vb - va) * t + va;
        mats[i].r[3].w = 1.0f;
    }
    PV pts[5];
    {
        QV w((f32)rg->x, (f32)rg->y, (f32)rg->z, 1.0f);
        for (s32 k = 1; k < 5; k++) pts[k] = mats[k] * w;
    }
    for (s32 k = 1; k < 5; k++) mats[k].InvOrtho();
    s32 n = 0;
    Obj* e = 0;
    f32 range = 1000.0f;
    while ((e = func_001b9bc8(e)) != 0) {
        if (e->kind->kind != 21) continue;
        if (lflag_check(&e->flag, 64)) continue;
        QV d = *func_0016c028(e) - *func_0016c028(obj);
        if (d.Length() > range) continue;
        Rgn* h = func_0016bc20(e, 6, -1);
        if (!h) continue;
        Hit y;
        y.c = 0;
        func_0018a818(&y, e, h);
        for (s32 j = 1; j < 5; j++) {
            x.v = pts[j];
            if (func_0018a550(&x, &y) && !(e->f7f8 & 4)) {
                func_002cf280(&e->flag, 256, 0);
                n++;
                e->vt[8](e);
                break;
            }
        }
    }
    return n;
}
}
}
