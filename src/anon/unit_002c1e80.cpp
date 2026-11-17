// Linked unit 0x2c1e80-0x2c2228 (-fno-strict-aliasing): a model-view class (C2/C1 ctor 0x2c1e80 /
// 0x2c1f08, vtable 0x361be8 stays retail data), the matrix/vector trap helpers and the file
// statics in .bss 0x1e2bca0 with the empty static initialiser and its I/D stubs (made by gcc).
// Under strict aliasing the ctor store order differs; under -fno-strict-aliasing the dtors of
// unit_002c10e0.cpp differ, so the file is linked as two units. .rodata starts at 0x375538.
// Bodies come from the old split files named above each function, bound by asm label.
#include "../common/types.h"

// ---- 002c1e80 (gap, never written): C2 copy of the ctor 0x2c1f08, same body
namespace n002c1e80 {
typedef struct V4 { f32 x, y, z, w; } V4;
typedef struct O3 { void* vt; u8 pad[0x20c]; V4 a; V4 b; } O3;
void* func_001050c8(void) asm("func_001050c8");
void func_002ee8a8(O3*, void*, u32) asm("func_002ee8a8");
extern u8 D_00361bf0[] asm("D_00361bf0");
static inline void vset(V4* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
void func_002c1e80(O3* p, u32 a) asm("func_002c1e80");
void func_002c1e80(O3* p, u32 a) {
    func_002ee8a8(p, func_001050c8(), a);
    p->vt = D_00361bf0;
    vset(&p->a, 0.0f, 0.0f, 0.0f, 0.0f);
    vset(&p->b, 0.0f, 0.0f, 0.0f, 1.0f);
}
}  // namespace n002c1e80

// ---- 002c1f08 from src/anon/batch_w1768_nsa.cpp
namespace n002c1f08 {
typedef struct V4 { f32 x, y, z, w; } V4;
typedef struct O3 { void* vt; u8 pad[0x20c]; V4 a; V4 b; } O3;
void* func_001050c8(void) asm("func_001050c8");
void func_002ee8a8(O3*, void*, u32) asm("func_002ee8a8");
extern u8 D_00361bf0[] asm("D_00361bf0");
static inline void vset(V4* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
void func_002c1f08(O3* p, u32 a) asm("func_002c1f08");
void func_002c1f08(O3* p, u32 a) {
    func_002ee8a8(p, func_001050c8(), a);
    p->vt = D_00361bf0;
    vset(&p->a, 0.0f, 0.0f, 0.0f, 0.0f);
    vset(&p->b, 0.0f, 0.0f, 0.0f, 1.0f);
}
}  // namespace n002c1f08

// ---- 002c1f90 from src/anon/batch_w1888_nsa.cpp
namespace n002c1f90 {
struct W1888eV {
    f32 x, y, z, w;
    W1888eV() {}
    W1888eV(const W1888eV& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    W1888eV& operator=(const W1888eV& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1888eV operator+(const W1888eV& b) const {
        W1888eV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1888eV operator*(f32 k) const {
        W1888eV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1888eM {
    W1888eV r[4];
} __attribute__((aligned(16)));
static inline W1888eV operator*(const W1888eM& m, const W1888eV& v) {
    W1888eV r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
#define QCP(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCP4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1888cV {
    f32 x, y, z, w;
    W1888cV() {}
    W1888cV& operator=(const W1888cV& o) { if (this != &o) QCP(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1888cM {
    W1888cV r[4];
    W1888cM() {}
    W1888cM& operator=(const W1888cM& o) { if (this != &o) QCP4(this, &o); return *this; }
    W1888cM operator*(const W1888cM& b) const {
        W1888cM o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
            "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
            : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1888cA { s32 a, b; };
struct W1888cB { u8 c[4]; };
struct W1888cO { u8 pad[0x150]; W1888cM m150; u8 pad2[0x210 - 0x190]; W1888cV v210; W1888cV v220; };
extern W1888cM D_01e2bcc0 asm("D_01e2bcc0");
void func_0011b6a8(W1888cM*) asm("func_0011b6a8");
W1888cM* func_0011b7b0(W1888cM*, W1888cV*) asm("func_0011b7b0");
void func_002eee68(W1888cO*, W1888cA, W1888cB) asm("func_002eee68");
void func_002c1f90(W1888cO* o, W1888cA a, W1888cB b) asm("func_002c1f90");
void func_002c1f90(W1888cO* o, W1888cA a, W1888cB b)
{
    W1888cM m;
    W1888cV* t = &m.r[3];
    func_0011b6a8(&m);
    m = *func_0011b7b0(&m, &o->v210);
    *t = o->v220;
    {
        W1888cM r = D_01e2bcc0 * m;
        o->m150 = r;
    }
    func_002eee68(o, a, b);
}
}  // namespace n002c1f90

// ---- 002c20f8 from src/anon/batch_w43.cpp
namespace n002c20f8 {
struct V4 {
    u32 w[4];
} __attribute__((aligned(16)));
extern V4 D_01e2bca0 asm("D_01e2bca0");
extern V4 D_01e2bcb0 asm("D_01e2bcb0");
struct M4 { V4 r[4]; };
extern M4 D_01e2bcc0 asm("D_01e2bcc0");
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
void func_0017d8c0(M4*, V4*, V4*) asm("func_0017d8c0");
void func_002c20f8(V4* a) asm("func_002c20f8");
void func_002c20f8(V4* a) {
    if (a != &D_01e2bca0) cpq(&D_01e2bca0, a);
    M4 m;
    func_0017d8c0(&m, &D_01e2bcb0, &D_01e2bca0);
    if (&m != &D_01e2bcc0)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(&D_01e2bcc0), "r"(&m) : "$8", "$9", "$10", "$11", "memory");
}
}  // namespace n002c20f8

// ---- 002c2168 from src/anon/batch_w44.cpp
namespace n002c2168 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
void func_0017d8c0(void*, void*, void*) asm("func_0017d8c0");
struct M64 { Q16 r[4]; };
extern Q16 D_01e2bcb0 asm("D_01e2bcb0");
extern Q16 D_01e2bca0 asm("D_01e2bca0");
extern M64 D_01e2bcc0 asm("D_01e2bcc0");
void func_002c2168(Q16* q) asm("func_002c2168");
void func_002c2168(Q16* q) {
    Q16* d = &D_01e2bcb0;
    if (q != d) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(q) : "$8", "memory");
    M64 m;
    func_0017d8c0(&m, d, &D_01e2bca0);
    M64* e = &D_01e2bcc0;
    if (&m != e)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(e), "r"(&m) : "$8", "$9", "$10", "$11", "memory");
}
}  // namespace n002c2168

// ---- 002c21d8 (gap, never written): empty function
namespace n002c21d8 {
void func_002c21d8() asm("func_002c21d8");
void func_002c21d8() {}
}  // namespace n002c21d8

// worldmap::WM_TOTAL_INFO::getBaseNum table (0x375540), last object of the file's .rodata.
extern const s16 R_00375540[16] asm("D_00375540") = {
    0, 2, 1, -1, 3, 5, 4, -1, 6, 9, 8, -1, 10, 5, 4, -1,
};

// File statics in .bss (0x1e2bca0-0x1e2bd00): the trap result vector/matrix buffers used by
// 0x2c1f90, 0x2c20f8 and 0x2c2168. The empty ctor/dtor of the first one gives the empty
// static initialiser 0x2c21e0 and its _GLOBAL__I_ (0x2c21e8) / _GLOBAL__D_ (0x2c2208) stubs.
struct SVec2c21e0 {
    f32 x, y, z, w;
    SVec2c21e0() {}
    ~SVec2c21e0() {}
} __attribute__((aligned(16)));
struct PVec2c21e0 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct PMat2c21e0 { PVec2c21e0 r[4]; } __attribute__((aligned(16)));
static SVec2c21e0 s_bca0 asm("D_01e2bca0");
static PVec2c21e0 s_bcb0 asm("D_01e2bcb0");
static PMat2c21e0 s_bcc0 asm("D_01e2bcc0");



