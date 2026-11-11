#include "../../common/types.h"
#include "../../yasui/libys/target.hpp"

// dk::TargetCamera (0x159ce0-0x15a810): camera that follows the locked-on target. The eye
// is eased toward the player, kept on screen and above the target, and turned by the pad.

#define TC_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct TcVec {
    f32 x, y, z, w;
    TcVec() {}
    TcVec(const TcVec& o) { TC_QCOPY(this, &o); }
    TcVec& operator=(const TcVec& o) { if (this != &o) TC_QCOPY(this, &o); return *this; }
    TcVec operator-(const TcVec& o) const {
        TcVec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    TcVec& sub(const TcVec& p, const TcVec& q) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&p), "r"(&q) : "memory");
        return *this;
    }
    void normalize(const TcVec& v) { TC_QCOPY(this, &v); normalize(); }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

// VU0 helpers
static inline void vu0_sub(TcVec& r, const TcVec& a, const TcVec& b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void vu0_add(TcVec& r, const TcVec& a, const TcVec& b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void vu0_scale(TcVec& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(s) : "$8", "memory");
}

struct M159 { f32 m[4][4]; } __attribute__((aligned(16)));
static inline void mulmat159(M159* d, const void* a, const void* b) {
    asm volatile(
        "lqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
        "lqc2 $vf5,0(%2)\n\tlqc2 $vf6,16(%2)\n\tlqc2 $vf7,32(%2)\n\tlqc2 $vf8,48(%2)\n\t"
        "vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\tvmaddw.wxyz $vf5,$vf4,$vf5w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf6x\n\tvmadday.wxyz ACC,$vf2,$vf6y\n\tvmaddaz.wxyz ACC,$vf3,$vf6z\n\tvmaddw.wxyz $vf6,$vf4,$vf6w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf7x\n\tvmadday.wxyz ACC,$vf2,$vf7y\n\tvmaddaz.wxyz ACC,$vf3,$vf7z\n\tvmaddw.wxyz $vf7,$vf4,$vf7w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf8x\n\tvmadday.wxyz ACC,$vf2,$vf8y\n\tvmaddaz.wxyz ACC,$vf3,$vf8z\n\tvmaddw.wxyz $vf8,$vf4,$vf8w\n\t"
        "sqc2 $vf5,0(%0)\n\tsqc2 $vf6,16(%0)\n\tsqc2 $vf7,32(%0)\n\tsqc2 $vf8,48(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}

struct TcCam {
    u8 pad0[0x44];
    u32 target;      // 0x44
    f32 f72;         // 0x48
    f32 f76;         // 0x4c
    f32 f80;         // 0x50
    u8 pad54[0x2c];
    TcVec eye;       // 0x80
};
struct TcPad { u64 f0; u64 f8; u8 pad[28]; f32 speed; };

namespace dk {
class ObjCamera;
class TargetCamera {
public:
    static u32 checkVisibleObject(TcVec obj, s32* box);
    static void control(TcPad* pad, TcCam* cam);
    static void updateCollision(ObjCamera* cam);
    static void checkEyeCollision(TcCam* cam);
    static void updateTargetCamera(TcCam* cam, TcVec* target, f32 t);
    static void update(TcCam* cam);
    static void change(YS::TARGET* t);
    static void create(YS::TARGET* t);
    static void destroy(void);
};
}  // namespace dk


struct ChangeFlag { u8 changed; };

struct TcPoint { f32 x, y, z, w; } __attribute__((aligned(16)));

// Turn speed of the pad (a constant with an empty destructor, set by the static initialiser).
struct TcSpeed {
    f32 v;
    TcSpeed(f32 a) { v = a; }
    ~TcSpeed() {}
};

s32 D_0034aa30[4] = {32, 480, 8, 408};  // on-screen box (x0, x1, y0, y1)
ChangeFlag D_0034aa40 = {1};
f32 D_0034aa44 = 0.0f;                  // yaw offset
TcPoint D_0034aa50[2];                  // target and player
static TcSpeed D_004f3604 __attribute__((aligned(4))) = TcSpeed(0.0523598753f);  // 3 degrees
YS::TARGET D_0034aa70;                  // locked-on target
f32 D_0034aa84 = 0.0f;                  // camera height
f32 D_0034aa88 = 10000.0f;

extern "C" {
extern f32 D_00349e10;  // frame time
TcVec* func_0016c028(u32);  // obj_get_attach_or_alt
u8* func_00106a18(s32);  // buffer_get_256
u8* func_00106a60(s32);  // buffer_get_by_index
s32* func_0013a178(void*, M159*);
s32 func_00158450(TcPad*);
s32 func_001584a0(TcPad*);
s32 func_0013fda0(TcCam*);
void func_0013fdc8(TcCam*);
f32 func_002f8ad0(f32, f32);  // atan2
f32 func_0017ce10(f32);
void* func_001584f8(TcPad*);
s32 func_00158548(TcPad*);
void* func_0019c4d0(u32);
void func_0013fd90(TcCam*);
void func_001400b0(f32, TcCam*);
void func_0013f9e0(void*, void*, void*, u32, u32);
void func_0013f888(TcCam*, TcVec*, u32);
void func_0013fca8(TcCam*);
void func_001904a8(void*, YS::TARGET*);
u32 func_00167f18(s32);
void func_00141010(f32);
u8* func_00140df0(void);
s32 func_00140dc0(void);
void func_00140dd0(u8*);

// The player's position, 170 below.
void func_00159ce0(TcCam* c, TcVec* out) {
    TcVec* r = func_0016c028(c->target);
    *out = *r;
    out->y -= 170.0f;
}

// out = from + (to - from) * t
void func_00159d30(TcCam* c, const TcVec* to, TcVec* out, f32 t) {
    TcVec from;
    func_00159ce0(c, &from);
    TcVec d;
    vu0_sub(d, *to, from);
    vu0_scale(d, t);
    TcVec r;
    vu0_add(r, from, d);
    *out = r;
}

// Projects through the current view matrices and returns screen-clip outcode bits.
u32 dk::TargetCamera::checkVisibleObject(TcVec obj, s32* rc) {
    M159 m;
    u8* a = func_00106a18(1);
    u8* b = func_00106a60(1);
    mulmat159(&m, a, b ? b + 16 : 0);
    s32* r = func_0013a178(&obj, &m);
    u32 f = (r[0] < rc[0]) << 2;
    if (rc[1] < r[0]) f |= 8;
    f |= r[1] < rc[2];
    if (rc[3] < r[1]) f |= 2;
    if (r[2] <= 0) f |= 0x10;
    if (r[2] > 4000000) f |= 0x20;
    return f;
}

void func_00159ef8(TcCam* c) {
    TcVec* src = &c->eye;
    TcVec* v = func_0016c028(c->target);
    TcVec* d = (TcVec*)D_0034aa50;
    *d = *src;
    d++;
    *d = *v;
}

// A global constant in the original: it stays in .rodata although the multiply becomes an add.
extern const f32 D_0036b37c = 2.0f;

u32 func_00159f50(TcCam* c, u32 clip) {
    f32 k = D_00349e10;
    if (clip & 1) return 0;
    if (!(clip & 2)) return 0;
    c->f72 = c->f72 - k * D_0036b37c;
    return 1;
}

s32 func_00159f90(TcCam*, u32 clip) {
    D_0034aa44 = 0.0f;
    if (clip & 4) D_0034aa44 = 0.34906584f;        // 20 degrees
    else if (clip & 8) D_0034aa44 = -0.34906584f;
    return 1;
}

void func_00159fd0(TcCam* b, TcPad* in, f32 dt) {
    if (func_00158450(in)) {
        D_0034aa84 = b->f72 -= in->speed * 8.0f * dt;
        func_0013fda0(b);
    } else if (func_001584a0(in)) {
        D_0034aa84 = b->f72 += in->speed * 8.0f * dt;
        func_0013fdc8(b);
    } else return;
    D_0034aa40.changed = 0;
}

}

// A by-value vector copy here checks for self-assignment too.
struct TcVecC {
    f32 x, y, z, w;
    TcVecC() {}
    TcVecC(const TcVecC& o) { if (this != &o) TC_QCOPY(this, &o); }
    TcVecC& operator=(const TcVecC& o) { if (this != &o) TC_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline TcVecC SubC(const TcVecC& a, const TcVecC& b) {
    TcVecC r;
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 YawC(TcVecC v) { return func_002f8ad0(v.x, v.z); }

extern "C" {

// Yaw from the player to the target.
f32 func_0015a098(void) {
    TcVecC a, d;
    TcVecC* p = (TcVecC*)D_0034aa50;
    a = p[0];
    d = SubC(p[1], p[0]);
    d.w = 1.0f;
    a.w = 1.0f;
    return YawC(d);
}

void func_0015a118(TcCam* c) {
    c->f80 = func_0017ce10(func_0015a098() + D_0034aa44);
}

void dk::TargetCamera::control(TcPad* p, TcCam* o) {
    f32 k = D_00349e10;
    if (func_001584f8(p)) {
        o->f76 += D_004f3604.v * p->speed * k;
        o->f80 = o->f76 = func_0017ce10(o->f76);
    } else if (func_00158548(p)) {
        o->f76 -= D_004f3604.v * p->speed * k;
        o->f80 = o->f76 = func_0017ce10(o->f76);
    }
    if (!func_0019c4d0(o->target)) func_00159fd0(o, p, k);
    else if (p->f0 & 0x100000000ull) func_00159fd0(o, p, k);
    if (p->f8 & 0x20000) {
        o->f80 = func_0015a098();
        func_0013fd90(o);
        D_0034aa84 = o->f72;
    }
}

void dk::TargetCamera::updateTargetCamera(TcCam* self, TcVec* target, f32 t) {
    TcVec cur;
    func_00159d30(self, target, &cur, t);
    func_00159ef8(self);
    TcVec pos = *func_0016c028(self->target);
    pos.y -= 100.0f;
    s32 id0 = checkVisibleObject(*target, D_0034aa30);
    s32 id1 = checkVisibleObject(pos, D_0034aa30);
    s32 vis0 = func_00159f50(self, id0);
    s32 vis1 = func_00159f50(self, id1);
    func_0013fda0(self);
    func_0013fdc8(self);
    TcVec dir;
    TcVec a; a = cur;
    TcVec b; b = pos;
    TcVec c; c = a;
    TcVec e; e = dir.sub(b, a);
    e.w = 1.0f;
    c.w = 1.0f;
    dir.normalize(e);
    if (e.length() > 300.0f && dir.y > 0.5f) {
        func_00159ce0(self, &cur);
    } else {
        if (vis0 == 0 && vis1 == 0) func_001400b0(D_00349e10, self);
        s32 id;
        if (id0 != 0) {
            id = id0;
        } else {
            if (id1 == 0) goto set_eye;
            id = id1;
        }
        if (func_00159f90(self, id)) {
            self->eye = cur;
            func_0015a118(self);
        }
        return;
    }
set_eye:
    self->eye = cur;
}

}

namespace dk {

void TargetCamera::updateCollision(ObjCamera* o) {
    TcVec p;
    func_00159ce0((TcCam*)o, &p);
    func_0013f9e0((u8*)o + 112, &p, (u8*)o + 16, 1, 0);
}

}  // namespace dk

extern "C" {

// Collision step with the eye at the player.
void dk::TargetCamera::checkEyeCollision(TcCam* c) {
    TcVec saved(c->eye);
    TcVec v;
    func_00159ce0(c, &v);
    func_0013f888(c, &v, 0);
    c->eye = v;
    func_0013fca8(c);
    c->eye = saved;
}

void dk::TargetCamera::update(TcCam* c) {
    u8 buf[16];
    func_001904a8(buf, &D_0034aa70);
    updateTargetCamera(c, (TcVec*)buf, 0.3f);
    u32 s = func_00167f18(0);
    void* o = (void*)c->target;
    if ((*(s32 (**)(void*))(*(u8**)o + 64))(o)) control((TcPad*)s, c);
    checkEyeCollision(c);
}

void dk::TargetCamera::create(YS::TARGET* t) {
    func_00141010(30.0f);
    u8* o = func_00140df0();
    o[59] = 1;
    s32 m = func_00140dc0();
    if (m == 6 || m == 8) return;
    f32 x = *(f32*)(o + 72);
    *(u32*)(o + 64) = 2;
    D_0034aa84 = x;
    change(t);
}

}

namespace dk {

void TargetCamera::change(YS::TARGET* t) {
    D_0034aa70 = *t;
    D_0034aa40.changed = 1;
}

}  // namespace dk

void dk::TargetCamera::destroy(void) {
    u8* o = func_00140df0();
    o[59] = 0;
    s32 m = func_00140dc0();
    if (m == 6) return;
    if (m == 8) return;
    if (m != 2) return;
    func_00140dd0(o);
}
