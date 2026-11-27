#include "../../common/types.h"
#include "camera.hpp"
#include "projection.hpp"
#include "../../harata/libdk/viewfrustum.hpp"

// kn camera and projection (0x1065d8-0x108068): the camera/projection tables (two sets, single and
// multi view, plus a saved copy), the projection matrix set-up, the look-at matrix and the camera
// moves. The static initialiser (0x107d20) and its I/D stubs are plain functions; the .ctors/.dtors
// entries and the Camera vtable (0x33cc50) stay retail data.

s32 D_0033cc38_def asm("D_0033cc38") = 0;  // current camera number
s32 D_0033cc3c_def asm("D_0033cc3c") = 0;  // previous camera number
s32 D_0033cc40_def asm("D_0033cc40") = 0;  // camera index
u8 D_0033cc44_def asm("D_0033cc44") = 0;   // multi view flag

namespace kn {
extern u32 D_0033cc44 asm("D_0033cc44");
extern u32 D_0033cc50 asm("D_0033cc50");
}  // namespace kn

// ---- 001065d8 (from src/anon/batch_w1966.cpp)
namespace n001065d8 {
#define W1966_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
#define W1966_QCOPY1(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1966Mat {
    f32 m[4][4];
    W1966Mat& operator=(const W1966Mat& o) { if (this != &o) W1966_QCOPY4(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1966Vec {
    f32 v[4];
    W1966Vec& operator=(const W1966Vec& o) { if (this != &o) W1966_QCOPY1(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1966Pad {
    u8 b[16];
    W1966Pad& operator=(const W1966Pad&) { return *this; }
} __attribute__((aligned(16)));
struct W1966I3 { s32 a, b, c; };
struct W1966Pair { void* a; void* b; } __attribute__((aligned(8)));
struct W1966A {
    W1966Mat m0;
    f32 f40;
    s32 i44, i48;
    W1966I3 t4c;
    W1966Pair p58;
    void* p60;
    f32 f64, f68, f6c, f70, f74, f78;
    W1966Mat m80;
    W1966Mat mc0;
};
struct W1966B {
    W1966Pad e0;
    W1966Mat m10;
    W1966Vec v50, v60, v70;
    f32 f80;
};
extern W1966A D_003a7b70[2] asm("D_003a7b70");
extern W1966B D_003a7f70[2] asm("D_003a7f70");
extern W1966A D_003a81b0[2] asm("D_003a81b0");
extern W1966B D_003a83b0[2] asm("D_003a83b0");
void func_001065d8(void) asm("func_001065d8");
void func_001065d8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        D_003a81b0[i] = D_003a7b70[i];
        D_003a83b0[i] = D_003a7f70[i];
    }
}
#undef W1966_QCOPY4
#undef W1966_QCOPY1
}  // namespace n001065d8

// ---- 001067b8 (from src/anon/batch_w1966.cpp)
namespace n001067b8 {
#define W1966_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
#define W1966_QCOPY1(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1966Mat {
    f32 m[4][4];
    W1966Mat& operator=(const W1966Mat& o) { if (this != &o) W1966_QCOPY4(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1966Vec {
    f32 v[4];
    W1966Vec& operator=(const W1966Vec& o) { if (this != &o) W1966_QCOPY1(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1966Pad {
    u8 b[16];
    W1966Pad& operator=(const W1966Pad&) { return *this; }
} __attribute__((aligned(16)));
struct W1966I3 { s32 a, b, c; };
struct W1966Pair { void* a; void* b; } __attribute__((aligned(8)));
struct W1966A {
    W1966Mat m0;
    f32 f40;
    s32 i44, i48;
    W1966I3 t4c;
    W1966Pair p58;
    void* p60;
    f32 f64, f68, f6c, f70, f74, f78;
    W1966Mat m80;
    W1966Mat mc0;
};
struct W1966B {
    W1966Pad e0;
    W1966Mat m10;
    W1966Vec v50, v60, v70;
    f32 f80;
};
extern W1966A D_003a7b70[2] asm("D_003a7b70");
extern W1966B D_003a7f70[2] asm("D_003a7f70");
extern W1966A D_003a81b0[2] asm("D_003a81b0");
extern W1966B D_003a83b0[2] asm("D_003a83b0");
void func_001067b8(void) asm("func_001067b8");
void func_001067b8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        D_003a7b70[i] = D_003a81b0[i];
        D_003a7f70[i] = D_003a83b0[i];
    }
}
#undef W1966_QCOPY4
#undef W1966_QCOPY1
}  // namespace n001067b8

// ---- 00106998 kn::setCameraMulti
namespace kn {
void setCameraMulti(bool value) { *(u8*)&D_0033cc44 = (u8)((u32)value & 0xffu); }
}  // namespace kn

// ---- 001069a8 (from src/anon/tiny.cpp)
namespace n001069a8 {
u32 func_001069a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001069a8");
u32 func_001069a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0034u << 16);
    return (u32)(*(u8*)((u32)b + (-13244)));
}
}  // namespace n001069a8

// ---- 001069b8 (from src/anon/probe.cpp)
namespace n001069b8 {
extern u32 D_0033cc38 asm("D_0033cc38");
extern u32 D_0033cc3c asm("D_0033cc3c");
void func_001069b8(u32 v) asm("func_001069b8");
void func_001069b8(u32 v) {
    D_0033cc3c = D_0033cc38;
    D_0033cc38 = v;
}
}  // namespace n001069b8

// ---- 001069d0 (gap: restores the previous camera number)
namespace n001069d0 {
extern u32 D_0033cc38 asm("D_0033cc38");
extern u32 D_0033cc3c asm("D_0033cc3c");
void func_001069d0(void) asm("func_001069d0");
void func_001069d0(void) { D_0033cc38 = D_0033cc3c; }
}  // namespace n001069d0

// ---- 001069e8 (from src/anon/tiny.cpp)
namespace n001069e8 {
u32 func_001069e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001069e8");
u32 func_001069e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0034u << 16);
    return (u32)(*(u32*)((u32)b + (-13256)));
}
}  // namespace n001069e8

// ---- 001069f8 kn::setCameraNumber
namespace kn {
void setCameraNumber(s32 value) {
    u32 b = (0x0034u << 16);
    *(u32*)((u32)b + (-13248)) = (u32)value;
}
}  // namespace kn

// ---- 00106a08 (from src/anon/tiny.cpp)
namespace n00106a08 {
u32 func_00106a08(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00106a08");
u32 func_00106a08(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0034u << 16);
    return (u32)(*(u32*)((u32)b + (-13248)));
}
}  // namespace n00106a08

// ---- 00106a18 (from src/anon/batch_w33.cpp)
namespace n00106a18 {
struct Buf256 { u8 b[256]; };
extern Buf256 D_003a7b70[] asm("D_003a7b70");
extern Buf256 D_003a7d70[] asm("D_003a7d70");
extern s32 D_0033cc40 asm("D_0033cc40");
extern u8 D_0033cc44 asm("D_0033cc44");
void* kn__getProjection(u8 a) asm("kn__getProjection");
void* kn__getProjection(u8 a) {
    if (a || D_0033cc44) return &D_003a7b70[D_0033cc40];
    return &D_003a7d70[D_0033cc40];
}
}  // namespace n00106a18

// ---- 00106a60 (from src/anon/batch_w58.cpp)
namespace n00106a60 {
extern u8 D_0033cc44 asm("D_0033cc44");
extern s32 D_0033cc40 asm("D_0033cc40");
struct E144 { u8 pad[144]; };
extern E144 D_003a7f70[] asm("D_003a7f70");
extern E144 D_003a8090[] asm("D_003a8090");
E144* func_00106a60(u8 a) asm("func_00106a60");
E144* func_00106a60(u8 a) {
    if (a || D_0033cc44) return &D_003a7f70[D_0033cc40];
    return &D_003a8090[D_0033cc40];
}
}  // namespace n00106a60

// ---- 00106ab0 (gap: Projection C2 constructor, empty)
namespace n00106ab0 {
void func_00106ab0(void) asm("func_00106ab0");
void func_00106ab0(void) {}
}  // namespace n00106ab0

// ---- 00106ab8 (from src/anon/tiny.cpp)
namespace n00106ab8 {
void func_00106ab8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00106ab8");
void func_00106ab8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00106ab8

// ---- 00106ac0 / 00106ac8 kn::Projection D2/D1 (empty)
namespace kn {
Projection::~Projection() {}
}  // namespace kn

// ---- 00106ad0 dk::ViewFrustum::setMatrix
namespace dk {
u32 ViewFrustum::setMatrix(const kn::FMatrix&) { return (u32)((s32)(u32)this + (128)); }
}  // namespace dk

// ---- 00106ae0 kn::Projection::getViewClipGsMatrix
namespace kn {
u32 Projection::getViewClipGsMatrix() { return (u32)((s32)this + (192)); }
}  // namespace kn

// ---- 00106af0 (from src/anon/batch_w93.cpp)
namespace n00106af0 {
void func_0011b6a8(f32* m) asm("func_0011b6a8");
struct ProjCam {
    u8 pad0[64];
    f32 scale;
    u8 pad1[8];
    f32 aspectX;
    f32 aspectY;
    u8 pad2[24];
    f32 nearZ;
    f32 farZ;
};
void func_00106af0(ProjCam* c, f32* m, f32 w, f32 h) asm("func_00106af0");
void func_00106af0(ProjCam* c, f32* m, f32 w, f32 h)
{
    f32 sx = c->nearZ * w / (c->scale * c->aspectX);
    f32 sy = c->nearZ * h / (c->scale * c->aspectY);
    func_0011b6a8(m);
    m[0] = c->nearZ * 2.0f / (sx * 2.0f);
    m[5] = c->nearZ * 2.0f / (sy * 2.0f);
    m[10] = (c->farZ + c->nearZ) / (c->farZ - c->nearZ);
    m[14] = c->farZ * c->nearZ * -2.0f / (c->farZ - c->nearZ);
    m[11] = 1.0f;
    m[15] = 0;
}
}  // namespace n00106af0

// ---- 00106c08 (from src/anon/batch_w100.cpp)
namespace n00106c08 {
void func_0011b6a8(f32*) asm("func_0011b6a8");
void func_00106af0(f32*, f32*, f32, f32) asm("func_00106af0");
void kn__Projection__calcMatrix(f32* p) asm("kn__Projection__calcMatrix");
void kn__Projection__calcMatrix(f32* p) {
    f32 a[16] __attribute__((aligned(16)));
    f32 b[16] __attribute__((aligned(16)));
    f32* pb;
    func_0011b6a8(a);
    pb = b;
    a[0] = p[16];
    a[11] = 1.0f;
    a[5] = p[16];
    a[14] = 1.0f;
    a[10] = 0.0f;
    a[15] = 0.0f;
    func_0011b6a8(pb);
    b[0] = p[19];
    b[5] = p[20];
    b[10] = p[21];
    b[12] = p[22];
    b[13] = p[23];
    b[14] = p[24];
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
        : : "r"(p), "r"(pb), "r"(a) : "memory");
    func_00106af0(p, p + 32, p[29], p[30]);
    func_00106af0(p, p + 48, 2047.0f, 2047.0f);
}
}  // namespace n00106c08

// ---- 00106d40 (from src/anon/batch_w1782_nsa.cpp)
namespace n00106d40 {
struct P106d40 { u8 pad[0x4c]; f32 f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78; };
void func_00106fe8(P106d40*, f32) asm("func_00106fe8");
void kn__Projection__calcMatrix(P106d40*) asm("kn__Projection__calcMatrix");
void kn__Projection__set(P106d40* o, f32 p0, f32 p1, f32 p2, f32 p3, f32 p4, f32 a, f32 b, f32 c, f32 p8, f32 p9, f32 p10) asm("kn__Projection__set");
void kn__Projection__set(P106d40* o, f32 p0, f32 p1, f32 p2, f32 p3, f32 p4, f32 a, f32 b, f32 c, f32 p8, f32 p9, f32 p10) {
    // Stores through byte offsets: with the struct fields gcc schedules the stack argument
    // loads differently under strict aliasing (the old copy was an _nsa file).
    u8* q = (u8*)o;
    *(f32*)(q + 0x54) = c * 4000000.0f * (b - a) / (4000000.0f - c);
    *(f32*)(q + 0x60) = (-b * c + a * 4000000.0f) / (4000000.0f - c);
    *(f32*)(q + 0x4c) = p1;
    *(f32*)(q + 0x50) = p2;
    *(f32*)(q + 0x58) = p3;
    *(f32*)(q + 0x5c) = p4;
    *(f32*)(q + 0x64) = a;
    *(f32*)(q + 0x68) = b;
    *(f32*)(q + 0x6c) = c;
    *(f32*)(q + 0x70) = p8;
    *(f32*)(q + 0x74) = p9;
    *(f32*)(q + 0x78) = p10;
    func_00106fe8(o, p0);
    kn__Projection__calcMatrix(o);
}
}  // namespace n00106d40

// ---- 00106de8 (from src/anon/batch_w98.cpp)
namespace n00106de8 {
f32 func_002f8a18(f32) asm("func_002f8a18");
f32 atanf(f32) asm("atanf");
struct Proj106 { u8 pad[64]; f32 dist; f32 fovx; f32 fovy; f32 w; f32 h; };
void kn__Projection__setFOV(Proj106* p, s32 vert, f32 fov) asm("kn__Projection__setFOV");
void kn__Projection__setFOV(Proj106* p, s32 vert, f32 fov) {
    if (!vert) {
        f32 d = 512.0f / p->w * 0.5f / func_002f8a18(fov * 0.5f);
        p->fovx = fov;
        p->dist = d;
        p->fovy = atanf(416.0f / p->h * 0.5f / d) * 2;
    } else {
        f32 d = 416.0f / p->h * 0.5f / func_002f8a18(fov * 0.5f);
        p->dist = d;
        f32 r = atanf(512.0f / p->w * 0.5f / d) * 2;
        p->fovy = fov;
        p->fovx = r;
    }
}
}  // namespace n00106de8

// ---- 00106f30 kn::Projection::getFOV
namespace kn {
f32 Projection::getFOV(WorH a1) const {
    u32 p = (u32)a1;
    p <<= 2;
    p += (u32)this;
    return *(f32*)(p + 0x44);
}
}  // namespace kn

// ---- 00106f40 (from src/anon/batch_w235.cpp)
namespace n00106f40 {
f32 func_002f8a18(f32) asm("func_002f8a18");
f32 atanf(f32) asm("atanf");
struct W235A { u8 p[76]; f32 w; f32 h; };
f32 func_00106f40(W235A* o, f32 x) asm("func_00106f40");
f32 func_00106f40(W235A* o, f32 x) {
    f32 a = 512.0f / o->w;
    f32 t = func_002f8a18(x * 0.5f);
    a = a * 0.5f;
    a = a / t;
    f32 b = 416.0f / o->h;
    b = b * 0.5f;
    b = b / a;
    f32 r = atanf(b);
    return r + r;
}
}  // namespace n00106f40

// ---- 00106fe8 (from src/anon/batch_w239.cpp)
namespace n00106fe8 {
f32 atanf(f32) asm("atanf");
void func_00106fe8(u8* a, f32 x) asm("func_00106fe8");
void func_00106fe8(u8* a, f32 x) {
    f32 k = 0.5f;
    *(f32*)(a + 64) = x;
    *(f32*)(a + 68) = atanf(512.0f / *(f32*)(a + 76) * k / x) * 2.0f;
    *(f32*)(a + 72) = atanf(416.0f / *(f32*)(a + 80) * k / x) * 2.0f;
}
}  // namespace n00106fe8

// ---- 001070a0 kn::Projection::getScreenZ
namespace kn {
f32 Projection::getScreenZ() const {
    return reinterpret_cast<const ProjectionLayout*>(this)->screenZ;
}
}  // namespace kn

// ---- 001070a8 (from src/anon/tiny_more.cpp)
namespace n001070a8 {
f32 func_001070a8(u32 a0,u32 a1,u32 a2,u32 a3) asm("func_001070a8");
f32 func_001070a8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(f32*)((u32)a0 + (108)); }
}  // namespace n001070a8

// ---- 001070b0 (gap: returns the float at +112)
namespace n001070b0 {
f32 func_001070b0(u32 a0) asm("func_001070b0");
f32 func_001070b0(u32 a0) { return *(f32*)((u32)a0 + (112)); }
}  // namespace n001070b0

// ---- 001070b8 (gap: Camera C2 constructor, sets the vptr)
namespace n001070b8 {
extern u32 D_0033cc50 asm("D_0033cc50");
void func_001070b8(u32 a0) asm("func_001070b8");
void func_001070b8(u32 a0) { *(u32*)((u32)a0 + (0)) = (u32)&D_0033cc50; }
}  // namespace n001070b8

// ---- 001070c8 (from src/anon/tiny.cpp)
namespace n001070c8 {
extern u32 D_0033cc50 asm("D_0033cc50");
void func_001070c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001070c8");
void func_001070c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_0033cc50;
}
}  // namespace n001070c8

// ---- 001070d8 / 001070e8 kn::Camera D2/D1
namespace kn {
Camera::~Camera() { *(u32*)((u32)this + 0) = (u32)&D_0033cc50; }
}  // namespace kn

// ---- 001070f8 (from src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n001070f8 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00106420");
extern u8 D_0033cc50 asm("D_0033cc50");
u32 func_001070f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001070f8");
u32 func_001070f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0033cc50;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n001070f8

// ---- 00107118 (from src/anon/batch_w276.cpp)
namespace n00107118 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) { if (this != &o) QCOPY(this, &o); return *this; }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct QM { QV r[4]; };
static inline f32 normalize(QV* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
void func_0011b6a8(QM*) asm("func_0011b6a8");
static inline void vsub3(QV* d, const QV* a, const QV* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void cross(QV* d, const QV* a, const QV* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void transl(QM* m, const QV* b) {
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(m), "r"(b) : "memory");
}
static inline void invortho(QM* m) {
    asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\tpextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\tpcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\tqmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
struct Cam { u8 pad[16]; QM m; QV eye; QV at; QV up; f32 roll; };
void func_0011b6a8(QM*) asm("func_0011b6a8");
void func_0011b768(QM*, f32) asm("func_0011b768");
void func_00107118(Cam* c) asm("func_00107118");
void func_00107118(Cam* c) {
    QM* m = &c->m;
    func_0011b6a8(m);
    vsub3(&m->r[2], &c->at, &c->eye);
    normalize(&m->r[2]);
    cross(&m->r[0], &m->r[2], &c->up);
    normalize(&m->r[0]);
    cross(&m->r[1], &m->r[2], &m->r[0]);
    transl(m, &c->eye);
    invortho(m);
    func_0011b768(m, c->roll);
}
#undef QCOPY
}  // namespace n00107118

// ---- 00107288 (gap: sets position, reference and up vector from three vectors)
namespace n00107288 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void func_00107288(u8* p, u8* a, u8* b, u8* c) asm("func_00107288");
void func_00107288(u8* p, u8* a, u8* b, u8* c) {
    u8* d = p + 80;
    if (d != a) QCOPY(d, a);
    d = p + 96;
    if (d != b) QCOPY(d, b);
    p += 112;
    if (p != c) QCOPY(p, c);
}
#undef QCOPY
}  // namespace n00107288

// ---- 001072d0 (from src/anon/batch_w8.cpp)
namespace n001072d0 {
void kn__Camera__lookAt_2(u8* p, u8* a, u8* b) asm("kn__Camera__lookAt_2");
void kn__Camera__lookAt_2(u8* p, u8* a, u8* b) {
    u8* d = p + 0x50;
    if (d != a) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(a) : "$8", "memory");
    }
    p += 0x60;
    if (p != b) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(p), "r"(b) : "$8", "memory");
    }
}
}  // namespace n001072d0

// ---- 00107300 (from src/anon/batch_w9.cpp)
namespace n00107300 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void func_00107300(u8* p, u8* a, u8* b, f32 f) asm("func_00107300");
void func_00107300(u8* p, u8* a, u8* b, f32 f) {
    u8* d = p + 80;
    if (d != a) QCOPY(d, a);
    d = p + 96;
    if (d != b) QCOPY(d, b);
    *(f32*)(p + 128) = f;
}
#undef QCOPY
}  // namespace n00107300

// ---- 00107330..00107360 kn::Camera setters
namespace kn {
void Camera::setPosition(f32 x, f32 y, f32 z) {
    CameraLayout* c = reinterpret_cast<CameraLayout*>(this);
    c->positionX = x;
    c->positionY = y;
    c->positionZ = z;
}
void Camera::setReference(f32 x, f32 y, f32 z) {
    CameraLayout* c = reinterpret_cast<CameraLayout*>(this);
    c->referenceX = x;
    c->referenceY = y;
    c->referenceZ = z;
}
void Camera::setUpVector(f32 x, f32 y, f32 z) {
    *(f32*)((u32)this + 112) = x;
    *(f32*)((u32)this + 116) = y;
    *(f32*)((u32)this + 120) = z;
}
void Camera::setRoll(f32 roll) { *(f32*)((u32)this + (s32)(128)) = roll; }
}  // namespace kn

// ---- 00107368 (from src/anon/batch_w4.cpp)
namespace n00107368 {
void kn__Camera__getPosition(u8* p, void* dst) asm("kn__Camera__getPosition");
void kn__Camera__getPosition(u8* p, void* dst) {
    void* src = p + 80;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}
}  // namespace n00107368

// ---- 00107388 (from src/anon/batch_w85.cpp)
namespace n00107388 {
static inline void vu_scale_to(void* d, const void* s, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void vu_mulmv(void* out, const void* m, const void* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
static inline void vu_mcopy(f32 (*d)[4], const u8* s) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void vu_qcopy(f32* d, const f32* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void vu_unit(f32* d) {
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(d) : "memory");
}
static inline void vu_minv(f32 (*d)[4], f32 (*s)[4]) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%1)\n\t"
                 "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                 "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                 "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                 "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
f32* func_00107388(f32* out, u8* o) asm("func_00107388");
f32* func_00107388(f32* out, u8* o) {
    f32 m[4][4] __attribute__((aligned(16)));
    f32 t[4] __attribute__((aligned(16)));
    f32 r[4] __attribute__((aligned(16)));
    f32* row3 = m[3];
    vu_mcopy(m, o + 16);
    vu_qcopy(t, row3);
    vu_unit(row3);
    vu_minv(m, m);
    vu_mulmv(r, m, t);
    vu_scale_to(out, r, -1.0f);
    return out;
}
}  // namespace n00107388

// ---- 00107478 (from src/anon/batch_w5.cpp)
namespace n00107478 {
void func_00107478(u8* src, u8* dst) asm("func_00107478");
void func_00107478(u8* src, u8* dst) {
    src += 0x60;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}
}  // namespace n00107478

// ---- 00107498 (gap: copies the up vector out)
namespace n00107498 {
void func_00107498(u8* src, u8* dst) asm("func_00107498");
void func_00107498(u8* src, u8* dst) {
    src += 0x70;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}
}  // namespace n00107498

// ---- 001074b8 kn::Camera::getRoll
namespace kn {
f32 Camera::getRoll() const { return reinterpret_cast<const CameraLayout*>(this)->roll; }
}  // namespace kn

// ---- 001074c0 (from src/anon/batch_w280.cpp)
namespace n001074c0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct QMat {
    QWord r[4];
    QMat() {}
    QMat& operator=(const QMat& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// FIXME static fn in C++ ctx ('namespace w280_a1',)
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// FIXME static fn in C++ ctx ('namespace w280_a1',)
static inline QWord Add(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// FIXME static fn in C++ ctx ('namespace w280_a1',)
static inline void CrossTo(QWord* r, const QWord& a, const QWord& b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(r), "r"(&a), "r"(&b) : "memory");
}
// FIXME static fn in C++ ctx ('namespace w280_a1',)
static inline QWord MulV(const QMat& m, const QWord& v)
{
    QWord r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
QMat func_0011b558(const QWord*) asm("func_0011b558");
void func_001074c0(u8* o, s32 mode, f32 ang) asm("func_001074c0");
void func_001074c0(u8* o, s32 mode, f32 ang)
{
    QWord* pos = (QWord*)(o + 80);
    QWord* ctr = (QWord*)(o + 96);
    QWord d, ax;
    QMat m;
    QWord* pax = &ax;
    QMat* pm = &m;
    d = Sub(*pos, *ctr);
    switch (mode) {
    case 0: {
        f32 s = sinf(ang);
        f32 c = cosf(ang);
        f32 x = c * d.f[0] + s * d.f[2];
        f32 z = -s * d.f[0] + c * d.f[2];
        *(f32*)(o + 80) = *(f32*)(o + 96) + x;
        *(f32*)(o + 88) = *(f32*)(o + 104) + z;
        break;
    }
    case 1: {
        CrossTo(pax, d, *(QWord*)(o + 112));
        ax.f[3] = ang;
        *pm = func_0011b558(pax);
        *pos = Add(*ctr, MulV(*pm, d));
        break;
    }
    }
}
#undef QCOPY
}  // namespace n001074c0

// ---- 00107648 (gap: moves the position along the view line by a factor, kept if not too short)
namespace n00107648 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 f[4];
    QWord() {}
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QWord Add(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void Scale(QWord& v, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&v), "f"(k) : "$8", "memory");
}
static inline f32 Length(const QWord& v)
{
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
void func_00107648(u8* o, f32 k) asm("func_00107648");
void func_00107648(u8* o, f32 k)
{
    QWord* pos = (QWord*)(o + 80);
    QWord* ref = (QWord*)(o + 96);
    QWord d;
    d = Sub(*pos, *ref);
    Scale(d, k + 1.0f);
    if (Length(d) < 1e-5f) return;
    *pos = Add(*ref, d);
}
#undef QCOPY
}  // namespace n00107648

// ---- 00107700 (from src/anon/batch_wcx2.cpp)
namespace n00107700 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V86 {
    f32 x, y, z, w;
    V86() {}
    V86& operator=(const V86& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline V86 Sub86(const V86& a, const V86& b)
{
    V86 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void Norm86(V86& v)
{
    asm volatile("lqc2 $vf1,0(%0)\n\tvmul.xyz $vf2,$vf1,$vf1\n\tvaddy.x $vf2,$vf2,$vf2y\n\tvaddz.x $vf2,$vf2,$vf2z\n\t"
                 "vsqrt Q,$vf2x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tvaddq.x $vf2,$vf0,Q\n\tmtc1 $8,$f0\n\tvnop\n\t"
                 "vdiv Q,$vf0w,$vf2x\n\tvwaitq\n\tvmulq.xyz $vf1,$vf1,Q\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&v) : "$8", "$f0", "memory");
}
static inline void Cross86(V86& r, const V86& a, const V86& b)
{
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf3,$vf0,$vf0\n\t"
                 "vopmula.xyz ACC,$vf1,$vf2\n\tvopmsub.xyz $vf3,$vf2,$vf1\n\tsqc2 $vf3,0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void AddTo86(V86& a, const V86& b)
{
    asm volatile("lqc2 $vf1,0(%0)\n\tlqc2 $vf2,0(%1)\n\tvadd.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&a), "r"(&b) : "memory");
}
struct Cam86 { u8 pad[80]; V86 eye; V86 at; V86 up; };
void func_00107700(Cam86* c, f32 dx, f32 dy) asm("func_00107700");
void func_00107700(Cam86* c, f32 dx, f32 dy)
{
    V86 side, up, fwd;
    fwd = Sub86(c->eye, c->at);
    Norm86(fwd);
    up = c->up;
    Norm86(up);
    Cross86(side, up, fwd);
    Norm86(side);
    Cross86(up, fwd, side);
    fwd.x = side.x * dx + up.x * dy;
    fwd.y = side.y * dx + up.y * dy;
    fwd.z = side.z * dx + up.z * dy;
    AddTo86(c->eye, fwd);
    AddTo86(c->at, fwd);
}
#undef QCOPY
}  // namespace n00107700

// ---- 00107888 (from src/anon/batch_w2399.cpp)
namespace n00107888 {
#define W2399_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
#define W2399_QCOPY1(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W2399Mat {
    f32 m[4][4];
    W2399Mat& operator=(const W2399Mat& o) { if (this != &o) W2399_QCOPY4(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2399Vec {
    f32 v[4];
    W2399Vec& operator=(const W2399Vec& o) { if (this != &o) W2399_QCOPY1(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2399Pad {
    u8 b[16];
    W2399Pad& operator=(const W2399Pad&) { return *this; }
} __attribute__((aligned(16)));
struct W2399I3 { s32 a, b, c; };
struct W2399Pair { void* a; void* b; } __attribute__((aligned(8)));
struct W2399A {
    W2399Mat m0;
    f32 f40;
    s32 i44, i48;
    W2399I3 t4c;
    W2399Pair p58;
    void* p60;
    f32 f64, f68, f6c, f70, f74, f78;
    W2399Mat m80;
    W2399Mat mc0;
};
struct W2399B {
    W2399Pad e0;
    W2399Mat m10;
    W2399Vec v50, v60, v70;
    f32 f80;
};
extern W2399A D_003a7b70[2] asm("D_003a7b70");
extern W2399B D_003a7f70[2] asm("D_003a7f70");
extern W2399A D_003a7d70[2] asm("D_003a7d70");
extern W2399B D_003a8090[2] asm("D_003a8090");
extern s32 D_0033cc40 asm("D_0033cc40");
void kn__Projection__calcMatrix(W2399A*) asm("kn__Projection__calcMatrix");
void func_00107118(W2399B*) asm("func_00107118");
void kn__camera_task(void) asm("kn__camera_task");
void kn__camera_task(void)
{
    D_003a7d70[D_0033cc40] = D_003a7b70[D_0033cc40];
    D_003a8090[D_0033cc40] = D_003a7f70[D_0033cc40];
    kn__Projection__calcMatrix(&D_003a7b70[D_0033cc40]);
    func_00107118(&D_003a7f70[D_0033cc40]);
}
#undef W2399_QCOPY4
#undef W2399_QCOPY1
}  // namespace n00107888

// ---- 00107a90 (from src/anon/batch_wcx2.cpp)
namespace n00107a90 {
extern u8 D_003a7b70[] asm("D_003a7b70");
extern u8 D_003a7f70[] asm("D_003a7f70");
void func_00106998(s32) asm("func_00106998");
void func_001069b8(s32) asm("func_001069b8");
void func_001069f8(s32) asm("func_001069f8");
void kn__Projection__set(void*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32) asm("kn__Projection__set");
void kn__Projection__setFOV(void*, s32, f32) asm("kn__Projection__setFOV");
void func_00107330(void*, f32, f32, f32) asm("func_00107330");
void func_00107340(void*, f32, f32, f32) asm("func_00107340");
void func_00107350(void*, f32, f32, f32) asm("func_00107350");
void func_00107360(void*, f32) asm("func_00107360");
void gb__PLAYER_CAMERA__exec(void) asm("gb__PLAYER_CAMERA__exec");
void gb__PLAYER_CAMERA__exec(void) {
    func_00106998(0);
    func_001069b8(0);
    func_001069f8(0);
    kn__Projection__set(D_003a7b70, 512.0f, 0.7999999523162842f, 0.8666666150093079f, 2048.0f, 2048.0f, 1.0f, 16770000.0f, 1.0f, 4000000.0f, 256.0f, 208.0f);
    kn__Projection__set(D_003a7b70 + 256, 512.0f, 0.7999999523162842f, 0.8666666150093079f, 2048.0f, 2048.0f, 1.0f, 16770000.0f, 1.0f, 4000000.0f, 256.0f, 208.0f);
    func_00107330(D_003a7f70, 0.0f, -600.0f, -10000.0f);
    func_00107340(D_003a7f70, 1000.0f, -1000.0f, 0.0f);
    func_00107350(D_003a7f70, 0.0f, -1.0f, 0.0f);
    func_00107360(D_003a7f70, 0.0f);
    func_00107330(D_003a7f70 + 144, 0.0f, -600.0f, -10000.0f);
    func_00107340(D_003a7f70 + 144, 1000.0f, -1000.0f, 0.0f);
    func_00107350(D_003a7f70 + 144, 0.0f, -1.0f, 0.0f);
    func_00107360(D_003a7f70 + 144, 0.0f);
    kn__Projection__setFOV(D_003a7b70, 0, 1.5f);
    kn__Projection__setFOV(D_003a7b70 + 256, 0, 1.5f);
}
void func_00106998(s32) asm("func_00106998");
}  // namespace n00107a90

// ---- 00107d20 (from src/anon/batch_wcx2.cpp)
namespace n00107d20 {
struct W1633Big { u8 pad[256]; };
struct W1633Virt { void (**vtbl)(W1633Virt*); u8 pad[140]; };
extern W1633Big w1633_003a7b70[2] asm("D_003a7b70");
extern W1633Big w1633_003a7d70[2] asm("D_003a7d70");
extern W1633Virt w1633_003a7f70[2] asm("D_003a7f70");
extern W1633Virt w1633_003a8090[2] asm("D_003a8090");
extern W1633Big w1633_003a81b0[2] asm("D_003a81b0");
extern W1633Virt w1633_003a83b0[2] asm("D_003a83b0");
void w1633_00106ab8(W1633Big*) asm("func_00106ab8");
void w1633_00106ac8(W1633Big*) asm("func_00106ac8");
void w1633_001070c8(W1633Virt*) asm("func_001070c8");
void func_00107d20(int init, int prio) asm("func_00107d20");
void func_00107d20(int init, int prio) {
    if (prio == 0xffff && init == 1) {
        w1633_00106ab8(&w1633_003a7b70[0]);
        w1633_00106ab8(&w1633_003a7b70[1]);
    }
    if (prio == 0xffff && init == 1) {
        w1633_00106ab8(&w1633_003a7d70[0]);
        w1633_00106ab8(&w1633_003a7d70[1]);
    }
    if (prio == 0xffff && init == 1) {
        w1633_001070c8(&w1633_003a7f70[0]);
        w1633_001070c8(&w1633_003a7f70[1]);
    }
    if (prio == 0xffff && init == 1) {
        w1633_001070c8(&w1633_003a8090[0]);
        w1633_001070c8(&w1633_003a8090[1]);
    }
    if (prio == 0xffff && init == 1) {
        w1633_00106ab8(&w1633_003a81b0[0]);
        w1633_00106ab8(&w1633_003a81b0[1]);
    }
    if (prio == 0xffff && init == 1) {
        w1633_001070c8(&w1633_003a83b0[0]);
        w1633_001070c8(&w1633_003a83b0[1]);
    }
    if (prio == 0xffff && init == 0) {
        u32 t = (u32)w1633_003a83b0;
        if (t != 0) {
            W1633Virt* p = (W1633Virt*)(t + 288);
            W1633Virt* base = (W1633Virt*)t;
        loop_D_003a83b0:
            if (p == base) goto done_D_003a83b0;
            --p;
            p->vtbl[0](p);
            goto loop_D_003a83b0;
        done_D_003a83b0:;
        }
    }
    if (prio == 0xffff && init == 0) {
        u32 t = (u32)w1633_003a81b0;
        if (t != 0) {
            W1633Big* p = (W1633Big*)(t + 512);
            W1633Big* base = (W1633Big*)t;
        loop_D_003a81b0:
            if (p == base) goto done_D_003a81b0;
            --p;
            w1633_00106ac8(p);
            goto loop_D_003a81b0;
        done_D_003a81b0:;
        }
    }
    if (prio == 0xffff && init == 0) {
        u32 t = (u32)w1633_003a8090;
        if (t != 0) {
            W1633Virt* p = (W1633Virt*)(t + 288);
            W1633Virt* base = (W1633Virt*)t;
        loop_D_003a8090:
            if (p == base) goto done_D_003a8090;
            --p;
            p->vtbl[0](p);
            goto loop_D_003a8090;
        done_D_003a8090:;
        }
    }
    if (prio == 0xffff && init == 0) {
        u32 t = (u32)w1633_003a7f70;
        if (t != 0) {
            W1633Virt* p = (W1633Virt*)(t + 288);
            W1633Virt* base = (W1633Virt*)t;
        loop_D_003a7f70:
            if (p == base) goto done_D_003a7f70;
            --p;
            p->vtbl[0](p);
            goto loop_D_003a7f70;
        done_D_003a7f70:;
        }
    }
    if (prio == 0xffff && init == 0) {
        u32 t = (u32)w1633_003a7d70;
        if (t != 0) {
            W1633Big* p = (W1633Big*)(t + 512);
            W1633Big* base = (W1633Big*)t;
        loop_D_003a7d70:
            if (p == base) goto done_D_003a7d70;
            --p;
            w1633_00106ac8(p);
            goto loop_D_003a7d70;
        done_D_003a7d70:;
        }
    }
    if (prio == 0xffff && init == 0) {
        u32 t = (u32)w1633_003a7b70;
        if (t != 0) {
            W1633Big* p = (W1633Big*)(t + 512);
            W1633Big* base = (W1633Big*)t;
        loop_D_003a7b70:
            if (p == base) goto done_D_003a7b70;
            --p;
            w1633_00106ac8(p);
            goto loop_D_003a7b70;
        done_D_003a7b70:;
        }
    }
}
}  // namespace n00107d20

// ---- 00108028 (from src/anon/tiny.cpp)
namespace n00108028 {
void func_00107d20(s32, s32) asm("func_00107d20");
void func_00108028(BD_VALUE* bd) asm("func_00108028");
void func_00108028(BD_VALUE* bd) { func_00107d20(1, 0xffff); }
}  // namespace n00108028

// ---- 00108048 (gap: _GLOBAL__D_ stub, runs the destructors)
namespace n00108048 {
void func_00107d20(s32, s32) asm("func_00107d20");
void func_00108048(void) asm("func_00108048");
void func_00108048(void) { func_00107d20(0, 0xffff); }
}  // namespace n00108048
