#include "../common/types.h"

// Ti::MG_EHSidecar (the side-car shooting minigame: path, camera task, target list), 0x2e1908-0x2e2c98.
// Linked unit (the rest is unit_002e2d18.cpp). The vtables and task tables (0x362e80-0x362f48) stay retail data.

typedef unsigned int u128 __attribute__((mode(TI)));
struct FV6 {
    f32 x, y, z, w;
    FV6() {}
    FV6(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    FV6(const f32* v, f32 c, f32 d) { x = v[0]; y = v[1]; z = c; w = d; }
    ~FV6() {}
} __attribute__((aligned(16)));
extern "C" {
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362eb8[] asm("D_00362eb8");
void func_002e70b0(void*);
void func_00106420(void*);
void func_002cea28(void*);
void func_00105110(void*);
void func_002cebc0(void*);
s32 func_002e34c8(void*);
void func_002e2728(u8*, s32, s32);
void func_002ceb08(void*);
void func_002e2660(u8*);
void func_002e26c0(u8*);
}
void wtarget_002e2440(void*) asm("_Z16wtarget_002e2440jjjj");
void wtarget_002e2570(void*) asm("_Z16wtarget_002e2570jjjj");
void wtarget_002e27c8(void*) asm("_Z16wtarget_002e27c8jjjj");

// ---- 2e1908 (src/anon/batch_w64.cpp)
namespace n2e1908 {
struct V16 { u128 q; };
static inline void vcopy(void* d, void* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
extern u32 D_00361f60 asm("D_00361f60");
void func_00184540(V16*, u32, f32, f32) asm("func_00184540");
void func_002e10d0(V16*, u32) asm("func_002e10d0");
extern "C" V16* func_002e1908(V16* out, u32 a1, u32 a2) {
    V16 m[4];
    V16 t;
    func_00184540(out, a2, 0.800000012f, 0.800000012f);
    func_002e10d0(m, D_00361f60);
    ((u32*)out)[3] = 0;
    asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)" : : "r"(&t), "r"(out), "r"(m) : "memory");
    vcopy(out, &t);
    return out;
}
}

// ---- 2e1998 (src/anon/batch_w1678_nsa.cpp)
namespace n2e1998 {
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
extern s32 D_00361f60 asm("D_00361f60");
extern f32 D_00362d88 asm("D_00362d88");
s32 func_002ceb28(void) asm("func_002ceb28");
s32 func_002e0fe8(s32) asm("func_002e0fe8");
Cam1998Mtx func_002e10d0(s32) asm("func_002e10d0");
Cam1998Mtx* func_002e10c0(s32) asm("func_002e10c0");
Cam1998Mtx34 func_002e1108(s32) asm("func_002e1108");
Cam1998Vec* func_0016c028(Cam1998Act*) asm("func_0016c028");
void func_0016ace0(Cam1998Act*, const Cam1998Vec&) asm("func_0016ace0");
void func_0016b070(Cam1998Act*, Cam1998Vec*) asm("func_0016b070");
void func_0011b6a8(Cam1998Mtx*) asm("func_0011b6a8");
void func_0011b720(Cam1998Mtx*, f32) asm("func_0011b720");
void func_002d08b8(Cam1998Vec*, const Cam1998Mtx&) asm("func_002d08b8");
extern "C" void func_002e1998(void*, Cam1998Act* o)
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

// ---- 2e1d10
void mg_2e1d10(void* self) {}

FV6 mg_2e1d18(void* self) {
    FV6 r;
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&r) : "memory");
    return r;
}

// ---- 2e1d28 (src/anon/batch_w2024.cpp)
namespace n2e1d28 {
struct W2024b_Vec {
    f32 x, y, z, w;
    W2024b_Vec() {}
    W2024b_Vec(const W2024b_Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2024b_Vec& operator=(const W2024b_Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2024b_Mtx { W2024b_Vec m[4]; };
struct W2024b_Obj;
struct W2024b_Cam;
static inline void W2024b_vouter(W2024b_Vec& d, const W2024b_Vec& a, const W2024b_Vec& b, W2024b_Vec* r) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
        : : "r"(r), "r"(&a), "r"(&b) : "memory");
    d = *r;
}
static inline f32 W2024b_vnorm(W2024b_Vec& v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
s32 W2024b_mg_be_ready(void*) asm("_ZN2Ti8MiniGame8be_readyEv");
s32 W2024b_cam_matrix(W2024b_Cam*) asm("_ZN2Ti11MG_ALEscape13camera_matrixEv");
void W2024b_obj_set_pos(W2024b_Obj*, const W2024b_Vec*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W2024b_obj_set_pos_trans(W2024b_Obj*, const W2024b_Vec*) asm("_ZN2YS3OBJ13set_pos_transERKN2kn7FVectorE");
void W2024b_obj_set_rot(W2024b_Obj*, const W2024b_Vec*) asm("_Z16wtarget_0016b070jjjj");
extern W2024b_Cam* D_00361f60 asm("D_00361f60");
extern void* D_0034e948 asm("D_0034e948");
W2024b_Vec* func_0016c028(void*) asm("func_0016c028");
void func_002e10d0(W2024b_Mtx*, W2024b_Cam*) asm("func_002e10d0");
void func_002e1140(W2024b_Mtx*, W2024b_Cam*) asm("func_002e1140");
void func_0011b6a8(void*) asm("func_0011b6a8");
void func_002d08b8(W2024b_Vec*, const W2024b_Mtx*) asm("func_002d08b8");
extern "C" void func_002e1d28(void* self, W2024b_Obj* o) {
    W2024b_Cam* c = D_00361f60;
    W2024b_Mtx a, b, m;
    W2024b_Vec q;
    W2024b_Vec q2;
    W2024b_Mtx b2;
    if (!W2024b_mg_be_ready(self)) return;
    if (W2024b_cam_matrix(c)) {
        W2024b_obj_set_pos_trans(o, func_0016c028(D_0034e948));
        func_002e10d0(&a, c);
        func_002e1140(&b, c);
        func_0011b6a8(&m);
        m.m[1] = a.m[1];
        W2024b_vouter(m.m[0], m.m[1], b.m[2], &q);
        W2024b_vouter(m.m[2], m.m[0], m.m[1], &q);
        W2024b_vnorm(m.m[0]);
        W2024b_vnorm(m.m[1]);
        W2024b_vnorm(m.m[2]);
        m.m[0].w = 0.0f;
        m.m[1].w = 0.0f;
        m.m[2].w = 0.0f;
        func_002d08b8(&q, &m);
        W2024b_obj_set_rot(o, &q);
    } else {
        func_002e1140(&b2, c);
        func_002d08b8(&q2, &b2);
        W2024b_obj_set_rot(o, &q2);
        W2024b_obj_set_pos(o, &b2.m[3]);
    }
}
}

// ---- 2e1f40 (src/anon/batch_w10.cpp)
namespace n2e1f40 {
void* func_001050d8(s32) asm("func_001050d8");
void func_002e20d8(void*, void*) asm("func_002e20d8");
extern "C" void func_002e1f40(void* a) {
    func_002e20d8(func_001050d8(320), a);
}
}

// ---- 2e1f70 (src/anon/batch_wcx2.cpp)
namespace n2e1f70 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
extern u8* D_0034e948 asm("D_0034e948");
extern u8* D_0034e948 asm("D_0034e948");
struct Rec57 { u8 pad[8]; u32 v; };
struct Obj57 { u32 vt; u8 pad[84]; u8 b88; u8 pad2[7]; u32 h; u32 pad3; u8 sub[4]; void* m; };
extern u8 D_00362eb8[] asm("D_00362eb8");
extern u8 D_00375f18[] asm("D_00375f18");
extern u8 D_00362e80[] asm("D_00362e80");
extern u8* D_0034e948 asm("D_0034e948");
void func_002ce958(Obj57*, s32, u32, s32) asm("func_002ce958");
void func_002e34b8(u8*) asm("func_002e34b8");
void func_002ceae8(Obj57*, char*, u8*) asm("func_002ceae8");
u32 func_001708f8(char*, s32) asm("func_001708f8");
Rec57* func_00168b38(u32, s32, s32) asm("func_00168b38");
void func_002e34c0(u8*, u32) asm("func_002e34c0");
void func_002e64b0(u32) asm("func_002e64b0");
u32 func_001050c8(void) asm("func_001050c8");
void* func_001063c0(s32, u32) asm("func_001063c0");
void func_002e6fc0(void*, u32) asm("func_002e6fc0");
void func_002cedd0(s32, u8*) asm("func_002cedd0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
u8* func_0016b740(s32) asm("func_0016b740");
void func_002e2350(Obj57*) asm("func_002e2350");
extern "C" void func_002e1f70(Obj57* o, u32 a)
{
    func_002ce958(o, 5, a, 0);
    o->vt = (u32)D_00362eb8;
    func_002e34b8(o->sub);
    char name[64];
    func_002ceae8(o, name, (u8*)"eh_22");
    u32 h = func_001708f8(name, -1);
    o->h = h;
    func_00168b38(h, 42, 0);  // entry_array_find_nth
    func_002e34c0(o->sub, func_00168b38(h, 42, 0)->v);
    func_00168b38(h, 42, 1);  // entry_array_find_nth
    u32 x = func_00168b38(h, 42, 1)->v;
    func_002e64b0(x);
    void* m = func_001063c0(12, func_001050c8());
    func_002e6fc0(m, x);
    o->m = m;
    func_002cedd0(3, D_00362e80);
    u8* p = D_0034e948;
    func_0016bd60(p, 53);
    *(u32*)(p + 264) |= 1;
    p = func_0016b740(2113);
    func_0016bd60(p, 54);
    *(u32*)(p + 264) |= 1;
    func_002e2350(o);
    o->b88 = 1;
}
}

// ---- 2e20d8 (src/anon/batch_wcx2.cpp)
namespace n2e20d8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
extern u8* D_0034e948 asm("D_0034e948");
extern u8* D_0034e948 asm("D_0034e948");
struct Rec57 { u8 pad[8]; u32 v; };
struct Obj57 { u32 vt; u8 pad[84]; u8 b88; u8 pad2[7]; u32 h; u32 pad3; u8 sub[4]; void* m; };
extern u8 D_00362eb8[] asm("D_00362eb8");
extern u8 D_00375f18[] asm("D_00375f18");
extern u8 D_00362e80[] asm("D_00362e80");
extern u8* D_0034e948 asm("D_0034e948");
void func_002ce958(Obj57*, s32, u32, s32) asm("func_002ce958");
void func_002e34b8(u8*) asm("func_002e34b8");
void func_002ceae8(Obj57*, char*, u8*) asm("func_002ceae8");
u32 func_001708f8(char*, s32) asm("func_001708f8");
Rec57* func_00168b38(u32, s32, s32) asm("func_00168b38");
void func_002e34c0(u8*, u32) asm("func_002e34c0");
void func_002e64b0(u32) asm("func_002e64b0");
u32 func_001050c8(void) asm("func_001050c8");
void* func_001063c0(s32, u32) asm("func_001063c0");
void func_002e6fc0(void*, u32) asm("func_002e6fc0");
void func_002cedd0(s32, u8*) asm("func_002cedd0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
u8* func_0016b740(s32) asm("func_0016b740");
void func_002e2350(Obj57*) asm("func_002e2350");
extern u8* D_0034e948 asm("D_0034e948");
struct Rec83 { u8 pad[8]; u32 v; };
struct Obj83 { u32 vt; u8 pad[84]; u8 b88; u8 pad2[7]; u32 h; u32 pad3; u8 sub[4]; void* m; };
extern u8 D_00362eb8[] asm("D_00362eb8");
extern u8 D_00375f18[] asm("D_00375f18");
extern u8 D_00362e80[] asm("D_00362e80");
extern u8* D_0034e948 asm("D_0034e948");
void func_002ce958_102666(Obj83*, s32, u32, s32) asm("func_002ce958");
void func_002e34b8(u8*) asm("func_002e34b8");
void func_002ceae8_102666(Obj83*, char*, u8*) asm("func_002ceae8");
u32 func_001708f8(char*, s32) asm("func_001708f8");
Rec83* func_00168b38_102666(u32, s32, s32) asm("func_00168b38");
void func_002e34c0(u8*, u32) asm("func_002e34c0");
void func_002e64b0(u32) asm("func_002e64b0");
u32 func_001050c8(void) asm("func_001050c8");
void* func_001063c0(s32, u32) asm("func_001063c0");
void func_002e6fc0(void*, u32) asm("func_002e6fc0");
void func_002cedd0(s32, u8*) asm("func_002cedd0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
u8* func_0016b740(s32) asm("func_0016b740");
void func_002e2350_102666(Obj83*) asm("func_002e2350");
extern "C" void func_002e20d8(Obj83* o, u32 a)
{
    func_002ce958_102666(o, 5, a, 0);
    o->vt = (u32)D_00362eb8;
    func_002e34b8(o->sub);
    char name[64];
    func_002ceae8_102666(o, name, (u8*)"eh_22");
    u32 h = func_001708f8(name, -1);
    o->h = h;
    func_00168b38_102666(h, 42, 0);
    func_002e34c0(o->sub, func_00168b38_102666(h, 42, 0)->v);
    func_00168b38_102666(h, 42, 1);
    u32 x = func_00168b38_102666(h, 42, 1)->v;
    func_002e64b0(x);
    void* m = func_001063c0(12, func_001050c8());
    func_002e6fc0(m, x);
    o->m = m;
    func_002cedd0(3, D_00362e80);
    u8* p = D_0034e948;
    func_0016bd60(p, 53);
    *(u32*)(p + 264) |= 1;
    p = func_0016b740(2113);
    func_0016bd60(p, 54);
    *(u32*)(p + 264) |= 1;
    func_002e2350_102666(o);
    o->b88 = 1;
}
}

// ---- 2e2240 (src/anon/batch_w30.cpp)
namespace n2e2240 {
extern u8 D_00362eb8[] asm("D_00362eb8");
void func_002e70b0(void*) asm("func_002e70b0");
void func_00106420(void*) asm("func_00106420");
u8 func_002cea28(void*) asm("func_002cea28");
extern "C" s32 func_002e2240(u8* p) {
    *(void**)p = D_00362eb8;
    void* o = *(void**)(p + 0x6c);
    if (o) {
        func_002e70b0(o);
        func_00106420(o);
    }
    return func_002cea28(p);
}
}

// ---- 2e2298 (src/anon/batch_w31.cpp)
namespace n2e2298 {
extern void* D_00362eb8[] asm("D_00362eb8");
void func_002e70b0(void*) asm("func_002e70b0");
void func_00106420(void*) asm("func_00106420");
void func_002cea28(void*) asm("func_002cea28");
struct NoTail { ~NoTail() {} };
extern "C" void func_002e2298(void** p) {
    NoTail g;
    *p = D_00362eb8;
    void* o = p[27];
    if (o) {
        func_002e70b0(o);
        func_00106420(o);
    }
    func_002cea28(p);
}
}

// ---- 2e22f0
extern "C" void func_002e22f0(u8* p) {
    *(u8**)p = D_00362eb8;
    void* t = *(void**)(p + 108);
    if (t) {
        func_002e70b0(t);
        func_00106420(t);
    }
    func_002cea28(p);
    func_00105110(p);
}

// ---- 2e2350
namespace n2e2350 {
#define QCOPY2e2350(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V2e2350 {
    f32 x, y, z, w;
    V2e2350() {}
    V2e2350(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V2e2350& operator=(const V2e2350& s) { if (this != &s) QCOPY2e2350(this, &s); return *this; }
} __attribute__((aligned(16)));
union U2e2350 { s32* p; s32 i; u32 u; };
struct O2e2350 {
    u8 pad[100]; U2e2350 cur; u8 b104[152]; u32 f256; f32 f260; u32 f264; u8 f268; u8 p269[3];
    U2e2350 f272; U2e2350 f276; u8 p280[8]; V2e2350 v288; V2e2350 v304;
};
s32* func_002e34d8_2e2350(u8*, s32) asm("func_002e34d8");
void func_002e24e0(O2e2350*) asm("func_002e24e0");
void Init2e2350(O2e2350* o) asm("func_002e2350");
void Init2e2350(O2e2350* o)
{
    o->f264 = 0;
    o->f256 = 0;
    s32* c = func_002e34d8_2e2350(o->b104, 0);
    o->cur.p = c;
    o->f260 = (f32)*c;
    func_002e24e0(o);
    o->f268 = 1;
    o->f276.i = -1;
    o->f272.u = 0;
    o->v288 = V2e2350(130.0f, 180.0f, 0.0f, 0.0f);
    o->v304 = V2e2350(140.0f, 150.0f, 0.0f, 0.0f);
}
}

// ---- 2e2428
extern "C" void func_002e2428(u8* p) {
    func_002cebc0(p);
}

// ---- 2e2440
namespace n2e2440 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
s32 func_00197920(u8*) asm("func_00197920");
void func_002e2728(u8*, s32, u8) asm("func_002e2728");
void func_002e24e0(u8*) asm("func_002e24e0");
extern V4 D_00362e70 asm("D_00362e70");
extern u8* D_0034e948 asm("D_0034e948");
void func_0016ace0(u8*, V4*) asm("func_0016ace0");
void wtarget_002e2440(u32, u32, u32, u32) asm("_Z16wtarget_002e2440jjjj");
void wtarget_002e2440(u32 a, u32, u32, u32)
{
    u8* p = (u8*)a;
    if (func_00197920(p)) return;
    s32 k = *(s32*)(p + 276);
    if (k >= 0) {
        func_002e2728(p, k, p[280]);
        *(s32*)(p + 276) = -1;
    }
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 240) : "memory");
    func_002e24e0(p);
    if (p[268]) {
        V4 t;
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(p + 224) : "$8", "memory");
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&t), "r"(&t), "r"(&D_00362e70) : "memory");
        func_0016ace0(D_0034e948, &t);
        p[268] = 0;
    }
}
}

// ---- 2e24e0 (src/anon/batch_w65.cpp)
namespace n2e24e0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Mq {
    Vq r[4];
    Mq& operator=(const Mq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
};
extern struct { u8 v; } D_01d48d94;
void func_002e7108(u32, f32) asm("func_002e7108");
Mq func_002e71a0(u32, u32, s32) asm("func_002e71a0");
extern "C" void func_002e24e0(u8* p) {
    Mq* d = (Mq*)(p + 176);
    func_002e7108(*(u32*)(p + 108), *(f32*)(p + 260));
    *d = func_002e71a0(*(u32*)(p + 108), *(u8*)(*(u32*)(p + 100) + 8), 1);
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(d), "r"(p + 240) : "memory");
}
}

// ---- 2e2570 (src/anon/batch_w81.cpp)
namespace n2e2570 {
struct M81 {
    u8 b[64];
    M81() {}
    M81(const M81& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    M81& operator=(const M81& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
union IF81 { s32 i; f32 f; };
extern f32 D_00349e10 asm("D_00349e10");
s32 func_00197920(u8*) asm("func_00197920");
void wtarget_002e2570(u8* o, u32, u32, u32) {
    if (func_00197920(o)) return;
    *(M81*)(o + 112) = *(M81*)(o + 176);
    s32 st = *(s32*)(o + 272);
    if (st == 1) {
        *(f32*)(o + 260) = *(f32*)(o + 260) + D_00349e10 * 0.5f;
        f32 lim = (f32)((IF81*)*(u8**)(o + 100))[1].i;
        if (lim <= *(f32*)(o + 260)) { *(f32*)(o + 260) = lim; *(s32*)(o + 272) = 0; }
    } else if (st == 2) {
        *(f32*)(o + 260) = *(f32*)(o + 260) - D_00349e10 * 0.5f;
        f32 lim = (f32)((IF81*)*(u8**)(o + 100))[0].i;
        if (*(f32*)(o + 260) <= lim) { *(f32*)(o + 260) = lim; *(s32*)(o + 272) = 0; }
    }
}
}

// ---- 2e2660
extern "C" void func_002e2660(u8* p) {
    if (*(s32*)(p + 272)) return;
    s32 n = *(s32*)(p + 264) - 1;
    if (n < 0) n = func_002e34c8(p + 104) - 1;
    func_002e2728(p, n, 0);
}

extern "C" void func_002e26c0(u8* p) {
    if (*(s32*)(p + 272)) return;
    s32 n = *(s32*)(p + 264);
    if (func_002e34c8(p + 104) < n) n = 0;
    func_002e2728(p, n, 1);
}

// ---- 2e2728 (src/anon/batch_wcx2.cpp)
namespace n2e2728 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
struct R2e2728 { s32 a, b; };
struct O2e2728 { u8 pad[0x64]; R2e2728* r; u8 m68[0x98]; s32 idx; f32 v; s32 n; u8 pad10c[4]; s32 state; };
void func_002e34c8(u8*) asm("func_002e34c8");
R2e2728* func_002e34d8(u8*, s32) asm("func_002e34d8");
extern "C" void func_002e2728(O2e2728* o, s32 idx, u8 b)
{
    if (o->state != 0) return;
    o->idx = idx;
    if (idx >= 0) func_002e34c8(o->m68);
    R2e2728* r = func_002e34d8(o->m68, o->idx);
    o->r = r;
    f32 v = (f32)(b ? r->a : r->b);
    o->state = b ? 1 : 2;
    o->v = v;
    s32 n = o->idx;
    if (b) n = n + 1;
    o->n = n;
}
}

// ---- 2e27c8 (src/anon/batch_w1567.cpp)
namespace n2e27c8 {
struct NM1567 {
    f32 m[16];
    NM1567() {}
    NM1567& operator=(const NM1567& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
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
struct QV1567 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern f32 D_00362e60 asm("D_00362e60");
s32 func_00197920(void) asm("func_00197920");
s32 func_00106a18(s32) asm("func_00106a18");
void func_00106de8(f32, s32, s32) asm("func_00106de8");
void func_00106c08(s32) asm("func_00106c08");
u8* func_00106a60(s32) asm("func_00106a60");
NM1567 func_002e71a0(s32, u8, s32) asm("func_002e71a0");
void func_001072d0(u8*, u8*, QV1567*) asm("func_001072d0");
void wt1567(u8* a0, u32, u32, u32) {
    if (func_00197920() == 0) {
        s32 b = func_00106a18(1);
        func_00106de8(D_00362e60 * 0.017453292f, b, 1);
        func_00106c08(b);
        u8* cam = func_00106a60(1);
        NM1567 m = func_002e71a0(*(s32*)(a0 + 0x6c), (*(u8**)(a0 + 0x64))[8], 1);
        asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(&m), "r"(a0 + 0xf0) : "memory");
        NM1567* d = (NM1567*)(cam + 0x10);
        *d = m;
        QV1567 t;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(cam + 0x40), "r"(cam + 0x30), "r"(&t) : "memory");
        func_001072d0(cam, cam + 0x40, &t);
        d->invOrtho();
    }
}
}

// ---- 2e2920
extern "C" u8* func_002e2920(u8* p) { return p + 112; }
extern "C" u8* func_002e2930(u8* p) { return p + 176; }

// ---- 2e2940 (src/anon/batch_w82.cpp)
namespace n2e2940 {
struct Node0017 { u8 pad[40]; s32 val; u8 pad2[16]; Node0017* next; };
extern struct { Node0017* first; } D_0034dca0;
struct Vec82 {
    f32 x, y, z, w;
    Vec82& operator=(const Vec82& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
Vec82* func_0016c028(u32) asm("func_0016c028");
union FU001d { f32 f; s32 i; };
struct Q001d { u32 a; FU001d f; };
struct S001d { s32 end; s32 cur; Q001d e[3]; u32 cur_a; f32 cur_f; f32 timer; };
s32 func_00197920(S001d*) asm("func_00197920");
static inline void QCopy82(void* d, const void* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
static inline void VSub82(void* d, const void* a, const void* b) { asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void VAdd82(void* d, const void* a, const void* b) { asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
void func_002e2a30(u8*, Vec82*, u8*, u8*) asm("func_002e2a30");
extern "C" void func_002e2940(u8* a0, u8* a1, Vec82* a2, Vec82* a3)
{
    Vec82 b, a, e, d;
    if (func_00197920((S001d*)a0)) return;
    if (!a0[88]) return;
    if (!(*(u32*)(a1 + 1416) & 0x80)) return;
    VAdd82(&a, func_0016c028((u32)a1), a2);  // obj_get_attach_or_alt
    VAdd82(&b, &a, a3);
    QCopy82(&a, &b);
    func_002e2a30(a0, &a, a0 + 288, a0 + 304);
    VSub82(&d, &a, &b);
    VAdd82(&e, &d, a3);
    *a3 = e;
}
}

// ---- 2e2a30 (src/anon/batch_w2039.cpp)
namespace n2e2a30 {
#define QCOPY_x(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPY4_x(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV_x {
    f32 x, y, z, w;
    QV_x() {}
    QV_x(const QV_x& o) { QCOPY_x(this, &o); }
    QV_x& operator=(const QV_x& o) { if (this != &o) QCOPY_x(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM_x {
    QV_x r[4];
    QM_x() {}
    QM_x(const QM_x& o) { QCOPY4_x(this, &o); }
    QM_x& operator=(const QM_x& o) { if (this != &o) QCOPY4_x(this, &o); return *this; }
    QV_x operator*(const QV_x& v) const {
        QV_x o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
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
struct Obj_x { u8 pad[0xb0]; QM_x m; };
extern f32 D_00362e60 asm("D_00362e60");
f32 func_002f8a18(f32) asm("func_002f8a18");
f32 fabsf(f32) asm("fabsf");
extern "C" void func_002e2a30(Obj_x* o, QV_x* v, const QV_x* lo, const QV_x* hi)
{
    QM_x inv = o->m;
    inv.invOrtho();
    v->w = 1.0f;
    *v = inv * *v;
    f32 t = func_002f8a18(D_00362e60 * 0.5f * 0.017453292f);
    t = t * fabsf(v->z);
    f32 h = t * 4.0f / 3.0f;
    f32 a = h - hi->x;
    if (a < v->x) v->x = a;
    a = lo->x - h;
    if (v->x < a) v->x = a;
    f32 b = t - hi->y;
    if (b < v->y) v->y = b;
    f32 c = lo->y - t;
    if (v->y < c) v->y = c;
    *v = o->m * *v;
}
}

// ---- 2e2c50
void ceb08_noarg(void) asm("func_002ceb08");
struct TASK;
namespace Ti {
struct MG_EHSidecar {
    static void task_update_camera(TASK* t);
    static void MoveToBeforePoint();
    static s32 GetCurrentPoint();
};
void MG_EHSidecar::task_update_camera(TASK* t) {
    wtarget_002e2440(*(void**)((u8*)t + 4));
}
}
extern "C" void func_002e2c68(TASK* t) {
    wtarget_002e27c8(*(void**)((u8*)t + 4));
}
extern "C" void func_002e2c80(TASK* t) {
    wtarget_002e2570(*(void**)((u8*)t + 4));
}



