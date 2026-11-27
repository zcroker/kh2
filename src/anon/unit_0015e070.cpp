#include "../common/types.h"

// 0x15e070-0x15eba8: two overlay classes that draw the queued 3D models with a copy of the current
// kn::Projection and kn::Camera, then their rects. Class A (vtable 0x34c6e0: D1/D0 0x31e048/0x31e068, draw
// 0x15e070, ctors 0x15e3b8/0x15e4e0) and class B (vtable 0x34c6c8: D1/D0 0x31e098/0x31e0b8, draw 0x15e608,
// ctors 0x15e8c8/0x15e9e0) stay retail data; methods are plain functions. The file-static rect at 0x4f3820
// (ctor 0x14c050, inline dtor) gives the static init 0x15eaf8 and its I/D stubs, kept as plain functions.
// The matrix product and lq/sq copies are VU0 asm (as in the old batch_wcx2.cpp copies).

namespace n15e608 {
// 0015e070 / 0015e608: draw the queued 3D models with a snapshot of the current kn::Projection
// and kn::Camera (copied by value), then the overlay rects. Matrix product and lq/sq copies are VU0 asm.
// 4x4 float matrix (16-byte aligned rows), copied with lq/sq.
struct M15e608 {
    f32 m[4][4];
    M15e608() {}
    M15e608(const M15e608& o)
    {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
} __attribute__((aligned(16)));
struct V15e608 {
    f32 x, y, z, w;
    V15e608(const V15e608& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
static inline M15e608 Mul15e608(const M15e608& l, const M15e608& r)
{
    M15e608 d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&d), "r"(&l), "r"(&r) : "memory");
    return d;
}
// kn::Projection members at 128/192 (out-of-line copy ctor).
struct PM15e608;
void b15e_0031bae0(PM15e608*, const PM15e608*) asm("func_0031bae0");
struct PM15e608 {
    M15e608 m;
    PM15e608(const PM15e608& o) { b15e_0031bae0(this, &o); }
};
// Field types reproduce the original's alias sets (see batch_w1681.cpp).
struct H15e608 { void* p; };
union U15e608 { s32 i; s32* p; };
struct R15e608 { s32* begin; s32* end; } __attribute__((aligned(8)));
struct Proj15e608 {
    M15e608 world;
    f32 f40;
    H15e608 h44;
    void* p48;
    s32 i4c;
    U15e608 v50;
    void* p54;
    R15e608 r58;
    s32* p60;
    f32 f64, f68, f6c, f70, f74, f78;
    PM15e608 view;
    PM15e608 clip;
    Proj15e608(const Proj15e608& o) __attribute__((always_inline));
    ~Proj15e608();
};
void b15e_projDtor(Proj15e608*) asm("_ZN2kn10ProjectionD1Ev");
inline Proj15e608::~Proj15e608() { b15e_projDtor(this); }
inline Proj15e608::Proj15e608(const Proj15e608& o)
    : world(o.world), f40(o.f40), h44(o.h44), p48(o.p48), i4c(o.i4c), v50(o.v50), p54(o.p54), r58(o.r58), p60(o.p60),
      f64(o.f64), f68(o.f68), f6c(o.f6c), f70(o.f70), f74(o.f74), f78(o.f78), view(o.view), clip(o.clip) {}
extern u8 D_0033cc50 asm("D_0033cc50");
struct Cam15e608 {
    u32 vt;
    M15e608 m;
    V15e608 a, b, c;
    f32 d;
    Cam15e608(const Cam15e608& o) : m(o.m), a((vt = (u32)&D_0033cc50, o.a)), b(o.b), c(o.c), d(o.d) {}
    ~Cam15e608();
} __attribute__((aligned(16)));
void b15e_camDtor(Cam15e608*) asm("_ZN2kn6CameraD1Ev");
inline Cam15e608::~Cam15e608() { b15e_camDtor(this); }
struct Model15e608 { u32 handle; u8 pad0[4]; u8 f8[16]; u64 f24; u64 f32; u8 pad1[88]; u8 f128[107]; u8 f235; u8 f236[33]; u8 f269; };
struct Rect15e608 { u8 pad[16]; };
struct Owner15e608 {
    u8 pad0[4];
    f32 z;
    Model15e608* models[18];
    Rect15e608 rect;
    u8 pad1[864 - 96];
    s32 nModels;
};
extern Rect15e608 D_004f3820 asm("D_004f3820");
extern u8 D_0034b280[] asm("D_0034b280");
Proj15e608* b15e_00106a18(s32) asm("kn__getProjection");
Cam15e608* b15e_00106a60(s32) asm("func_00106a60");
void m15e608_swap(u32) asm("_ZN2kn8ModelObj10matrixSwapEv");
void b15e_0011cdf0(u32, M15e608*, void*, void*, u8) asm("func_0011cdf0");
void r15e608_setXY(Rect15e608*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void r15e608_setZ(Rect15e608*, u32) asm("_ZN2dk13RectParamBase4setZEj");
void r15e608_setWH(Rect15e608*, u16, u16) asm("_ZN2dk13RectParamBase14setWidthHeightEtt");
void r15e608_setColor(Rect15e608*, u8, u8, u8, u8) asm("_ZN2dk13RectParamBase8setColorEhhhh");
void r15e608_setPrim(Rect15e608*, u64) asm("_ZN2dk8RectBase9setGsPrimEy");
void r15e608_setFrame(Rect15e608*, u64) asm("_ZN2dk8RectBase10setGsFrameEy");
void r15e608_setZbuf(Rect15e608*, u64) asm("_ZN2dk8RectBase9setGsZbufEy");
void r15e608_setTex0(Rect15e608*, u64) asm("_ZN2dk8RectBase9setGsTex0Ey");
void b15e_0014b838(Rect15e608*) asm("func_0014b838");
void b15e_0014c350(Rect15e608*) asm("func_0014c350");
u64 b15e_00166148(u8*, s32, s32) asm("func_00166148");
u32 b15e_00313bc0(f32) asm("__fixunssfsi");
}  // namespace n15e608

namespace n15e608 {
struct Owner15e070 {
    u8 pad0[4];
    f32 z;
    Model15e608* models[34];
    Rect15e608 rect;
    u8 pad1[416 - 160];
    Rect15e608 rect2;
    u8 pad2[1200 - 432];
    s32 nModels;
    s16 x; u8 pad3[2];
    s16 y; u8 pad4[2];
    u16 size;
};
void dk__SpotBlend__draw(Owner15e070* o) asm("dk__SpotBlend__draw");
void dk__SpotBlend__draw(Owner15e070* o)
{
    r15e608_setZbuf(&D_004f3820, 0x131000070ULL);
    r15e608_setFrame(&D_004f3820, 0x80140);
    r15e608_setPrim(&D_004f3820, 6);
    r15e608_setColor(&D_004f3820, 0, 0, 0, 0);
    r15e608_setWH(&D_004f3820, 512, 416);
    b15e_0014c350(&D_004f3820);
    Proj15e608 proj(*b15e_00106a18(0));
    Cam15e608 cam(*b15e_00106a60(0));
    s32 n = o->nModels;
    for (s32 i = 0; i < n; i++) {
        Model15e608* mo = o->models[i];
        mo->f32 = 0x31000070;
        mo->f24 = 0x80140;
        m15e608_swap(mo->handle);
        M15e608 mat = Mul15e608(proj.world, cam.m);
        b15e_0011cdf0(mo->handle, &mat, mo->f128, mo->f8, mo->f269);
        m15e608_swap(mo->handle);
    }
    o->nModels = 0;
    r15e608_setXY(&o->rect, o->x, o->y);
    r15e608_setWH(&o->rect, o->size, o->size);
    r15e608_setTex0(&o->rect, b15e_00166148(D_0034b280, 0x3500, 0x3540));
    b15e_0014b838(&o->rect);
    r15e608_setZ(&o->rect2, b15e_00313bc0(o->z));
    b15e_0014c350(&o->rect2);
}
}  // namespace n15e608

// 0x15e3b8 (C2) / 0x15e4e0 (C1): class A constructor.
namespace n15e3b8 {
extern u8 D_0034c6e0[] asm("D_0034c6e0");
void func_0014b7f0(u8*) asm("func_0014b7f0");
void func_0014c050(u8*) asm("func_0014c050");
void func_0014b610(u8*, u64) asm("func_0014b610");
void func_0014b608(u8*, u64) asm("func_0014b608");
void func_0014b5e0(u8*, u64) asm("func_0014b5e0");
void func_0014b630(u8*, u64) asm("func_0014b630");
void func_0014b618(u8*, u64) asm("func_0014b618");
void func_0014b5e8(u8*, u64, u64) asm("func_0014b5e8");
void func_0014b208(u8*, u64, u64) asm("func_0014b208");
void func_0014b468(u8*, u64, u64) asm("func_0014b468");
void func_0014b628(u8*, u64) asm("func_0014b628");
void dk__SpotBlend__SpotBlend(u8* p) asm("dk__SpotBlend__SpotBlend");
void dk__SpotBlend__SpotBlend(u8* p) {
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_0034c6e0;
    u8* a = p + 144;
    func_0014b7f0(a);
    func_0014c050(p + 416);
    *(u32*)(p + 1200) = 0;
    func_0014b610(a, 0x131000070ULL);
    func_0014b608(a, 0x00ffffff00080140ULL);
    func_0014b5e0(a, 278);
    func_0014b630(a, 96);
    func_0014b618(a, 0x3cfe5);
    func_0014b5e8(a, 0x80008, 0x4080408);
    func_0014b610(p + 416, 0x131000070ULL);
    func_0014b5e0(p + 416, 342);
    func_0014b630(p + 416, 96);
    func_0014b618(p + 416, 0x3001d);
    func_0014b208(p + 416, 512, 416);
    func_0014b468(p + 416, 512, 416);
    func_0014b628(p + 416, 0x2006a00664022800ULL);
}
}  // namespace n15e3b8

namespace n15e4e0 {
void func_0014b208(u32, u32, u32) asm("func_0014b208");
void func_0014b7f0(u32) asm("func_0014b7f0");
void func_0014c050(u32) asm("func_0014c050");
void func_0014b610(u32, u64) asm("func_0014b610");
void func_0014b608(u32, u64) asm("func_0014b608");
void func_0014b5e0(u32, u32) asm("func_0014b5e0");
void func_0014b630(u32, u32) asm("func_0014b630");
void func_0014b618(u32, u32) asm("func_0014b618");
void func_0014b5e8(u32, u64, u64) asm("func_0014b5e8");
void func_0014b468(u32, u32, u32) asm("func_0014b468");
void func_0014b628(u32, u64) asm("func_0014b628");
void func_0014b220(u32, u32, u32, u32, u32) asm("func_0014b220");
extern u8 D_0034c6e0[] asm("D_0034c6e0");
extern u8 D_0034c6c8[] asm("D_0034c6c8");
extern u8 D_004f3820[] asm("D_004f3820");
void gm__SPRITEFROM3D__draw_common(u32 p) asm("gm__SPRITEFROM3D__draw_common");
void gm__SPRITEFROM3D__draw_common(u32 p) {
    u32 s1, s2;
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_0034c6e0;
    s1 = p + 144;
    func_0014b7f0(s1);
    s2 = p + 416;
    func_0014c050(s2);
    *(u32*)(p + 1200) = 0;
    func_0014b610(s1, 0x131000070ULL);
    func_0014b608(s1, 0x00ffffff00080140ULL);
    func_0014b5e0(s1, 278);
    func_0014b630(s1, 96);
    func_0014b618(s1, 0x3cfe5);
    func_0014b5e8(s1, 0x80008, 0x4080408);
    func_0014b610(s2, 0x131000070ULL);
    func_0014b5e0(s2, 342);
    func_0014b630(s2, 96);
    func_0014b618(s2, 0x3001d);
    func_0014b208(s2, 512, 416);
    func_0014b468(s2, 512, 416);
    func_0014b628(s2, 0x2006a00664022800ULL);
}
}  // namespace n15e4e0

namespace n15e608 {
void dk__ModelSprite__draw(Owner15e608* o) asm("dk__ModelSprite__draw");
void dk__ModelSprite__draw(Owner15e608* o)
{
    b15e_0014c350(&D_004f3820);
    Proj15e608 proj(*b15e_00106a18(0));
    Cam15e608 cam(*b15e_00106a60(0));
    Model15e608* mo;
    s32 n = o->nModels;
    for (s32 i = 0; i < n; i++) {
        mo = o->models[i];
        mo->f32 = 0x31000070;
        mo->f24 = 0x80140;
        m15e608_swap(mo->handle);
        M15e608 mat = Mul15e608(proj.world, cam.m);
        b15e_0011cdf0(mo->handle, &mat, mo->f128, mo->f8, mo->f269);
        m15e608_swap(mo->handle);
    }
    o->nModels = 0;
    u32 z = b15e_00313bc0(o->z);
    mo = o->models[0];
    r15e608_setZ(&o->rect, z);
    r15e608_setColor(&o->rect, 128, 128, 128, mo->f235);
    b15e_0014c350(&o->rect);
}
}  // namespace n15e608

// 0x15e8c8 (C2) / 0x15e9e0 (C1): class B constructor.
namespace n15e3b8 {
extern u8 D_0034c6c8[] asm("D_0034c6c8");
extern u8 D_004f3820[] asm("D_004f3820");
void func_0014b220(u8*, u64, u64, u64, u64) asm("func_0014b220");
void gm__FRAMEBUFFER__Init(u8* p) asm("gm__FRAMEBUFFER__Init");
void gm__FRAMEBUFFER__Init(u8* p) {
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_0034c6c8;
    func_0014c050(p + 80);
    *(u32*)(p + 864) = 0;
    func_0014b610(D_004f3820, 0x131000070ULL);
    func_0014b608(D_004f3820, 0x80140);
    func_0014b5e0(D_004f3820, 6);
    func_0014b220(D_004f3820, 0, 0, 0, 0);
    func_0014b208(D_004f3820, 512, 416);
    func_0014b610(p + 80, 0x131000070ULL);
    func_0014b5e0(p + 80, 342);
    func_0014b630(p + 80, 96);
    func_0014b618(p + 80, 0x3001d);
    func_0014b208(p + 80, 512, 416);
    func_0014b468(p + 80, 512, 416);
    func_0014b628(p + 80, 0x2006a00664022800ULL);
}
}  // namespace n15e3b8

namespace n15e4e0 {
void dk__ModelSprite__ModelSprite(u32 p) asm("dk__ModelSprite__ModelSprite");
void dk__ModelSprite__ModelSprite(u32 p) {
    u32 s2;
    u32 g;
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_0034c6c8;
    s2 = p + 80;
    func_0014c050(s2);
    *(u32*)(p + 864) = 0;
    g = (u32)D_004f3820;
    func_0014b610(g, 0x131000070ULL);
    func_0014b608(g, 0x80140);
    func_0014b5e0(g, 6);
    func_0014b220(g, 0, 0, 0, 0);
    func_0014b208(g, 512, 416);
    func_0014b610(s2, 0x131000070ULL);
    func_0014b5e0(s2, 342);
    func_0014b630(s2, 96);
    func_0014b618(s2, 0x3001d);
    func_0014b208(s2, 512, 416);
    func_0014b468(s2, 512, 416);
    func_0014b628(s2, 0x2006a00664022800ULL);
}
}  // namespace n15e4e0

// 0x15eaf8: static init of the file-static rect at 0x4f3820, with its I (0x15eb68) and D (0x15eb88) stubs.
namespace n15eaf8 {
void func_0014c050(void*) asm("func_0014c050");
extern u8 D_004f3820[] asm("D_004f3820");
extern void* D_00348698[] asm("D_00348698");
void wtarget_0015eaf8(u32 a, u32 b, u32, u32) asm("_Z16wtarget_0015eaf8jjjj");
void wtarget_0015eaf8(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) func_0014c050(D_004f3820);
    if (b == 0xffff && a == 0) *(void***)D_004f3820 = D_00348698;
}
u32 func_0015eaf8(u32, u32, u32, u32) asm("_Z16wtarget_0015eaf8jjjj");
u32 func_0015eb68(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0015eb68");
u32 func_0015eb68(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0015eaf8(0x00000001u, 0x0000ffffu, a2, a3);
}
u32 func_0015eb88(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0015eb88");
u32 func_0015eb88(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0015eaf8(0, 0x0000ffffu, a2, a3);
}
}  // namespace n15eaf8
