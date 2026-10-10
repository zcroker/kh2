#include "../common/types.h"
#define QCOPY323(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV323 {
    f32 x, y, z, w;
    QV323() {}
    QV323(const QV323& o) { QCOPY323(this, &o); }
    QV323& operator=(const QV323& o) { if (this != &o) QCOPY323(this, &o); return *this; }
    QV323 operator-(const QV323& o) const {
        QV323 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    QV323 operator*(f32 k) const {
        QV323 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 dot(const QV323& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 lensq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    void normalize0() {
        asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "$8", "$f0", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
#define QCOPY4_323(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QM323 {
    QV323 r[4];
    QM323() {}
    QM323(const QM323& o) { QCOPY4_323(this, &o); }
    QM323& operator=(const QM323& o) { if ((u32)this != (u32)&o) QCOPY4_323(this, &o); return *this; }
    QV323 operator*(const QV323& v) const {
        QV323 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    QM323 operator*(const QM323& b) const {
        QM323 o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
extern "C" {
#define FLD(T, o) (*(T*)((u8*)self + (o)))
typedef s32 (*VF)(void*);
#define VC(o) ((VF)((*(void***)self)[(o) / 4]))(self)
typedef void (*VV_)(void*);
#define VV(o) ((VV_)((*(void***)self)[(o) / 4]))(self)
extern f32 D_00349e10;
extern u32 D_0034f240;
struct List1d4 { u8* head; u8* tail; };
extern List1d4 D_01d48db0;
s32 objIsLeave(void*) asm("_ZN2YS3OBJ8is_leaveEv");
s32 objIsDummy(void*) asm("_ZN2YS3OBJ11is_dummyobjEv");
s32 ctarget(void*) asm("_Z16ctarget_0019c6f0jjjj");
void func_001d7a88(void*);
void func_00194010(void*);
void func_0017f620(void*, f32);
void func_0017f938(void*);
void func_00183088(void*);
void func_0011ea40(u32, f32);
void func_001b9420(u8* self) {
    f32 dt = D_00349e10;
    if (FLD(u32, 264) & 0x10000000) {
        if (VC(36)) VV(40);
    }
    if (objIsLeave(self)) {
        FLD(u32, 2040) |= 0x100;
    } else {
        if (!(FLD(u32, 2040) & 0x80)) VV(8);
        func_001d7a88(self + 1304);
        if (!ctarget(self) && !(D_0034f240 & 0x20)) {
            if (objIsDummy(self)) {
                VV(20);
            } else {
                VV(12);
                if (!(FLD(u32, 268) & 0x400000)) {
                    func_0017f620(self + 320, dt);
                    if (FLD(u32, 2040) & 2) func_0011ea40(FLD(u32, 1648), dt);
                }
                VV(16);
                if (VC(64)) VV(20);
                VV(24);
                func_0017f938(self + 320);
                func_00183088(self);
            }
            func_00194010(self);
            if ((FLD(f32, 2092) == 0.0f && (FLD(u32, 2040) & 0x10)) || FLD(f32, 2256) == 0.0f) VV(32);
        } else {
            if (!objIsDummy(self)) func_0017f938(self + 320);
        }
        if (!objIsLeave(self)) {
            if (!D_01d48db0.tail) {
                D_01d48db0.tail = self;
                D_01d48db0.head = self;
                FLD(u8*, 2232) = 0;
            } else {
                *(u8**)(D_01d48db0.tail + 2232) = self;
                FLD(u8*, 2232) = 0;
                D_01d48db0.tail = self;
            }
        }
    }
    FLD(u32, 2040) |= 0x800;
    FLD(u32, 2040) &= ~0x2000;
}
#undef FLD

#define FLD(T, o) (*(T*)((u8*)self + (o)))
extern u8 D_0034a4f0[]; extern u8 D_0034a518[];
void func_0014fcd8(void*); s32 func_00139d78(void*); void func_001506e0(void*);
void func_00138c40(void*, u32, u32); void func_00150260(void*, u32, s32, s32*);
void func_00138c10(void*, s32); void func_001395a8(void*); void func_00139598(void*);
void func_00150328(u8* self) {
    s32 buf[8];
    func_0014fcd8(self);
    if (FLD(s32, 6176) == 1) {
        if (!func_00139d78(self + 840)) func_001506e0(self);
        return;
    }
    func_00138c40(self + 840, FLD(u32, 32), FLD(u32, 36));
    FLD(u32, 6148) = **(u32**)(self + 6144);
    FLD(u32, 6160) = **(u32**)(self + 6156);
    if (FLD(u32, 6152) != FLD(u32, 6148)) {
        func_00150260(D_0034a4f0, FLD(u32, 6148), 5, buf);
        for (s32 i = FLD(s32, 6168) - 1; i >= 0; i--) {
            func_00138c10(self + 1656 + i * 408, buf[i]);
            func_001395a8(self + 1656 + i * 408);
        }
        for (s32 j = FLD(s32, 6168) - 1; j > 0; j--) {
            if (buf[j] != 12) break;
            if (FLD(s32, 6172) == 2) func_00139598(self + 1656 + j * 408);
            else func_00138c10(self + 1656 + j * 408, 22);
        }
    }
    if (FLD(u32, 6164) != FLD(u32, 6160) && FLD(s32, 6172) == 1) {
        func_00150260(D_0034a518, FLD(u32, 6160), 5, buf);
        for (s32 k = FLD(s32, 6168) - 1; k >= 0; k--) {
            func_00138c10(self + 3696 + k * 408, buf[k]);
        }
        for (s32 l = FLD(s32, 6168) - 1; l > 0; l--) {
            if (buf[l] != 24) break;
            func_00138c10(self + 3696 + l * 408, 34);
        }
    }
    FLD(u32, 6164) = FLD(u32, 6160);
    FLD(u32, 6152) = FLD(u32, 6148);
}
}
extern "C" {
extern u8 D_0033cc50;
void func_001070e8(void*);
}
struct Cam323 {
    u32 vt;
    QM323 m;
    QV323 a, b, c;
    f32 d;
    Cam323(const Cam323& o) : m(o.m), a((vt = (u32)&D_0033cc50, o.a)), b(o.b), c(o.c), d(o.d) {}
    ~Cam323() { func_001070e8(this); }
} __attribute__((aligned(16)));
extern "C" {
Cam323* func_00106a60(s32);  // buffer_get_by_index
void func_00147810(u32, u8* o) {
    if (!(*(u32*)(o + 248) & 0x1000)) return;
    if (*(u32*)(o + 288)) return;
    QM323 w;
    QV323 p;
    QV323 pad;
    Cam323 c(*func_00106a60(1));  // buffer_get_by_index
    c.m.invOrtho();
    p = c.m * *(QV323*)(o + 192);
    w = *(QM323*)(o + 64);
    w = c.m * w;
    *(QM323*)(o + 64) = w;
    *(QV323*)(o + 192) = p;
}
}
extern "C" {
extern u8* D_00361f60;
QV323& func_0016c028(void);  // obj_get_attach_or_alt
QV323 func_002d1d30(u8*, const QV323&);
f32 rnd2d4548(f32, f32) asm("_Z13func_001065a8jjjjjjjj");
f32 func_002f8870(f32);  // fabsf
void func_002d4548(u8* self) {
    u8* cam = D_00361f60;
    f32 save = *(f32*)(self + 2876);
    QV323 v = func_0016c028();  // obj_get_attach_or_alt
    QV323 r = func_002d1d30(cam, v);
    if ((0.8f < r.x && 0.0f < *(f32*)(self + 2864)) || (r.x < -0.8f && *(f32*)(self + 2864) < 0.0f) ||
        (0.8f < r.y && 0.0f < *(f32*)(self + 2868)) || (r.y < -0.8f && *(f32*)(self + 2868) < 0.0f)) {
        f32 a, b;
        do {
            a = rnd2d4548(-1.0f, 1.0f);
            b = rnd2d4548(-1.0f, 1.0f);
        } while (func_002f8870(a) < 0.001f && func_002f8870(b) < 0.001f);  // fabsf
        if (0.7f < r.x) a = -func_002f8870(a);  // fabsf
        if (r.x < -0.7f) a = func_002f8870(a);  // fabsf
        if (0.7f < r.y) b = -func_002f8870(b);  // fabsf
        if (r.y < -0.7f) b = func_002f8870(b);  // fabsf
        *(f32*)(self + 2864) = a;
        *(f32*)(self + 2868) = b;
        *(f32*)(self + 2872) = 0.0f;
    }
    ((QV323*)(self + 2864))->normalize0();
    *(f32*)(self + 2876) = save;
}

f32 func_002cd518(u32, f32* out, const QV323* a, const QV323* b, const QV323* c) {
    QV323 d1 = *c - *b;
    QV323 d2 = *a - *b;
    if (d1.dot(d2) < 0.0f) {
        *out = d2.length();
        return 0.0f;
    }
    f32 len = d1.normalize();
    QM323 m;
    m.r[0] = d1 * d1.x;
    m.r[1] = d1 * d1.y;
    m.r[2] = d1 * d1.z;
    d2.w = 0.0f;
    QV323 p = m * d2;
    f32 pl = p.length();
    if (len < pl) {
        *out = (*a - *c).length();
        return 1.0f;
    }
    f32 h = d2.lensq() - p.lensq();
    if (h <= 0.0f) *out = 0.0f;
    else *out = __builtin_sqrtf(h);
    return pl / len;
}
}
