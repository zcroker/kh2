#include "../../common/types.h"

// dk::BookCamera (0x1589d0-0x159070): camera for the book (world map) screens. It orbits a
// point with a pad-controlled angle and remembers its last state between uses.

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; } __attribute__((aligned(16)));

static inline void QCOPY(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void VAssign(V4* d, const V4* s) {
    if (d != s) QCOPY(d, s);
}
static inline void ApplyM(V4* d, M4* m, V4* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
static inline void ApplyTo(V4* d, M4* m, V4* v) {
    V4 t;
    ApplyM(&t, m, v);
    VAssign(d, &t);
}
static inline void VAddTo(V4* d, V4* a, V4* b) {
    V4 t;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&t), "r"(a), "r"(b) : "memory");
    VAssign(d, &t);
}

// A camera vector kept between uses (empty constructor and destructor).
struct BcVec {
    f32 x, y, z, w;
    BcVec() {}
    ~BcVec() {}
    BcVec& operator=(const BcVec& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// Pad input and camera state as this file sees them.
struct BcPad { u64 p0; u64 flags; u8 pad[44 - 16]; f32 speed; };
struct BcTarget;
struct BcTargetVt { void* f[16]; s32 (*IsValid)(BcTarget*); };
struct BcTarget { BcTargetVt* vt; };
struct BcCam {
    u8 pad0[16];
    V4 cur;          // 16
    u8 pad20[36];
    BcTarget* target;  // 68
    f32 f72;         // 72
    f32 val;         // 76
    f32 out;         // 80
    u8 pad54[12];
    V4 v96;          // 96
    V4 v112;         // 112
    V4 v128;         // 128
    V4 v144;         // 144
};
struct BcSeg { BcVec a, b; };

BcVec D_0034a9b0;          // orbit centre
BcVec D_0034a9c0;          // saved v144
BcVec D_0034a9d0;          // saved v112
f32 D_0034a9e0 = 0.0f;     // saved f72
f32 D_0034a9e4 = 0.0f;     // saved out
u8 D_0034a9e8 = 0;         // first update pending

static u8* D_004f35a0 __attribute__((aligned(4)));                     // book data
static inline f32 Radians(f32 deg) { return deg * 0.0174532925f; }

static f32 D_004f35a4 __attribute__((aligned(4))) = Radians(3.0f);    // turn speed
static f32 D_004f35a8 __attribute__((aligned(4))) = Radians(10.0f);   // tilt speed

extern "C" {
extern f32 D_00349e10;  // frame time
u8* func_00140df0(void);   // dk::ObjCamera::getInstance
s32 func_00140dc0(void);   // dk::ObjCamera::getMode
void func_00140dd0(u8*);   // dk::ObjCamera::returnMode
void func_00141010(f32);
f32 func_0013fd10(BcCam*);
void func_0013fd78(BcCam*);
s32 func_0019c4d0(BcTarget*);
void func_0013fdf0(BcCam*, BcPad*, f32);
s32 func_001584f8(BcPad*);
s32 func_00158548(BcPad*);
f32 func_0017ce10(f32);
f32 func_0017ce80(f32, f32, f32);
void func_0011b6a8(M4*);
void func_0011b720(M4*, f32);
s32 func_00167f18(s32);
s32 func_0013f9e0(V4*, V4*, V4*, s32, s32);
BcVec func_0016c2b0(BcTarget*);
BcVec* func_0016c028(BcTarget*);
s32 func_00143d10(BcSeg*, BcVec*, f32*, s32*);

void func_001589d0(u8* p) {
    M4* m = (M4*)(D_004f35a0 + 64);
    ApplyTo((V4*)(p + 96), m, (V4*)(D_004f35a0 + 2928));
    ApplyTo((V4*)(p + 128), m, (V4*)(D_004f35a0 + 2944));
    VAssign((V4*)(p + 16), (V4*)(p + 96));
    VAssign((V4*)p, (V4*)(p + 128));
}

}

namespace dk {
class BookCamera {
public:
    static u8* create(u8* book);
};

u8* BookCamera::create(u8* book) {
    u8* cam = func_00140df0();
    *(u32*)(cam + 64) = 10;
    D_004f35a0 = book;
    return cam;
}
}  // namespace dk

extern "C" {

void func_00158ac8(BcCam* c) {
    VAssign((V4*)&D_0034a9c0, &c->v144);
    VAssign((V4*)&D_0034a9d0, &c->v112);
    D_0034a9e0 = c->f72;
    D_0034a9e4 = c->out;
}

void func_00158b20(BcCam* c) {
    c->f72 = D_0034a9e0;
    c->out = D_0034a9e4;
    *(BcVec*)&c->v144 = D_0034a9c0;
    *(BcVec*)&c->v112 = D_0034a9d0;
}

void func_00158c88(BcCam* c);

// Steps the angle toward its target (or snaps it while the hold flag is set).
void func_00158b78(BcPad* a, BcCam* b) {
    f32 k = D_00349e10;
    if (a->flags & 0x20000) {
        b->out = func_0013fd10(b);
        func_0013fd78(b);
        VAssign(&b->cur, &b->v96);
    } else if (func_001584f8(a)) {
        b->val += D_004f35a4 * a->speed * k;
        b->out = b->val = func_0017ce10(b->val);
    } else if (func_00158548(a)) {
        b->val -= D_004f35a4 * a->speed * k;
        b->out = b->val = func_0017ce10(b->val);
    }
    if (!func_0019c4d0(b->target)) func_0013fdf0(b, a, k);
    func_00158c88(b);
}

void func_00158c88(BcCam* c) {
    u8* p = (u8*)c;
    VAssign((V4*)(p + 0x80), (V4*)&D_0034a9b0);
    f32 d = *(f32*)(p + 0x48) - *(f32*)(p + 0xd0);
    f32 dt = D_00349e10;
    f32 h = *(f32*)(p + 0xd8) * (d * d);
    *(f32*)(p + 0x4c) = func_0017ce80(*(f32*)(p + 0x4c), *(f32*)(p + 0x50), D_004f35a8 * dt);
    V4 v;
    v.w = v.y = v.x = 0.0f;
    v.z = *(f32*)(p + 0x48);
    M4 m;
    func_0011b6a8(&m);
    func_0011b720(&m, *(f32*)(p + 0x4c));
    ApplyTo(&v, &m, &v);
    VAddTo((V4*)(p + 0x60), (V4*)(p + 0x80), &v);
    *(f32*)(p + 0x64) = *(f32*)(p + 0x84) - -220.0f - h;
}

void func_00158dc0(BcCam* c) {
    s32 mode = func_00167f18(0);
    if (!c->target->vt->IsValid(c->target)) return;
    func_00158ac8(c);
    if (D_0034a9e8 == 1) {
        BcVec pos = func_0016c2b0(c->target);
        BcSeg seg;
        BcVec* pa = &seg.a;
        BcVec& r = *func_0016c028(c->target);
        BcVec* pb = &seg.b;
        *pa = r;
        *pb = pos;
        BcVec hit;
        f32 t;
        s32 n = 0;
        f32* pt = &t;
        if (func_00143d10(&seg, &hit, pt, &n)) D_0034a9b0 = hit;
        else D_0034a9b0 = pos;
        *(f32*)((u8*)c + 80) = func_0013fd10(c);
        D_0034a9e8 = 0;
    } else {
        func_00158b78((BcPad*)mode, c);
        if (func_0013f9e0(&c->v112, &c->v128, &c->v96, 1, 1)) {
            func_00158b20(c);
            func_00158c88(c);
            func_0013f9e0(&c->v112, &c->v128, &c->v96, 1, 1);
        }
    }
}

void func_00158f40(void) {
    func_00141010(30.0f);
    u8* p = func_00140df0();
    func_00140dc0();
    *(s32*)(p + 0x40) = 6;
    D_0034a9e8 = 1;
}

void func_00158f90(void) {
    u8* cam = func_00140df0();
    if (func_00140dc0() == 6) func_00140dd0(cam);
}

}
