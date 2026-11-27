#include "../common/types.h"

// Ts lock-on helpers (0x2ea2b8-0x2eaa68): two small classes with vtable 0x363410 (C2/C1 ctor pairs;
// 0x2ea2b8, 0x2ea2f8 and 0x2ea318 were never written before), a motion reset callback (0x2ea338, never
// written before) and the turn-toward helper 0x2ea360. Every symbol is bound by asm label.

namespace n002ea2b8 {
extern u32 D_00363410 asm("D_00363410");
void func_002ea2b8(u32* p) asm("func_002ea2b8");
void func_002ea2b8(u32* p) {
    p[1] = 1;
    p[2] = 385;
    p[0] = (u32)&D_00363410;
}
}  // namespace n002ea2b8

// 002ea2d8 (from src/anon/batch_w5.cpp)
namespace n002ea2d8 {
extern u32 D_00363410 asm("D_00363410");
void func_002ea2d8(u32* p) asm("func_002ea2d8");
void func_002ea2d8(u32* p) {
    p[1] = 1;
    p[2] = 385;
    p[0] = (u32)&D_00363410;
}
}  // namespace n002ea2d8

namespace n002ea2f8 {
extern u32 D_00363410 asm("D_00363410");
void func_002ea2f8(u32* p, u32 a) asm("func_002ea2f8");
void func_002ea2f8(u32* p, u32 a) {
    p[1] = a;
    p[2] = 257;
    p[0] = (u32)&D_00363410;
}
void func_002ea318(u32* p, u32 a) asm("func_002ea318");
void func_002ea318(u32* p, u32 a) {
    p[1] = a;
    p[2] = 257;
    p[0] = (u32)&D_00363410;
}
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_002ea338(void*, u8* o) asm("func_002ea338");
void func_002ea338(void*, u8* o) {
    func_0017f488(o + 320, 3, 0.0f, 0.0f);
}
}  // namespace n002ea2f8

// 002ea360 (from src/anon/batch_w83.cpp)
namespace n002ea360 {
// 128-bit copy through $t0.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
extern f32 D_00349e10 asm("D_00349e10");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
f32 func_0017ce10(f32) asm("func_0017ce10");
Vec4 func_0017d0e8(f32) asm("func_0017d0e8");
// Turn cur's heading toward tgt by at most lim.
Vec4 func_002ea360(f32 lim, f32* cur, f32* tgt) asm("func_002ea360");
Vec4 func_002ea360(f32 lim, f32* cur, f32* tgt) {
    Vec4 r;
    f32 m = lim * D_00349e10;
    f32 d = func_002f8ad0(tgt[0], tgt[2]);
    f32 c = func_002f8ad0(cur[0], cur[2]);
    d = d - c;
    cur[3] = c;
    f32 e = func_0017ce10(d);
    if (m < e) r = func_0017d0e8(func_0017ce10(cur[3] + m));
    else if (e < -m) r = func_0017d0e8(func_0017ce10(cur[3] - m));
    else r = *(Vec4*)tgt;
    return r;
}
}  // namespace n002ea360

// ---- 002ea450 (never written before): lock-on per-frame move of the locked-on object. Clamps the horizontal
// speed and the fall speed, sweeps the object's collision shape along the velocity and, when it hits a wall
// (octree attribute kind 2), slides the velocity along the wall and turns it toward the player. Needs
// -fno-strict-aliasing: only then gcc 3.2 combines adjacent free temp slots, so every vector-operator temporary
// reuses one stack slot as in retail. Its .rodata (1.0, 5.0, 5 degrees) is this unit's .rodata at 0x3760c8.
namespace n002ea450 {
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V& operator=(const V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 normalize() {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    V& operator*=(f32 s) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V operator*(const V& a, f32 s) {
    V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline V operator+(const V& a, const V& b) {
    V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V operator-(const V& a, const V& b) {
    V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 dot(const V& a, const V& b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct CB {
    V v[6];
    u16 h96, h98, h100, h102;
    f32 f104, f108;
    u32 w112[2]; u32 w120, w124;
    CB& operator=(const CB& s) {
        v[0] = s.v[0]; v[1] = s.v[1]; v[2] = s.v[2]; v[3] = s.v[3]; v[4] = s.v[4]; v[5] = s.v[5];
        h96 = s.h96; h98 = s.h98; h100 = s.h100; h102 = s.h102;
        f104 = s.f104; f108 = s.f108;
        w112[0] = s.w112[0]; w112[1] = s.w112[1]; w120 = s.w120; w124 = s.w124;
        return *this;
    }
};
void coll_ctor(void*) asm("func_0031b9e0");
struct COLL : CB {
    u32 f128;
    COLL() { coll_ctor(this); }
};
struct PARAM { u8 pad[24]; f32 f24; u8 pad2[4]; f32 f32_; };
extern PARAM* D_00352130 asm("D_00352130");
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e18 asm("D_00349e18");
extern f32 D_00363400 asm("D_00363400");
extern f32 D_00363404 asm("D_00363404");
struct OBJ {
    u8 pad[32];
    V vel;            // 32
    u8 pad48[240];
    f32 f288;         // 288
    u8 pad292[1132];
    CB coll;          // 1424
};
V* obj_pos(void*) asm("YS__OBJ__get_pos");
void coll_update(COLL*) asm("dk__Octree__collisionToMap");
s32 coll_ray(V*, V*, V*, s32) asm("func_001a7588");
u32* oc_attr(u32, u32) asm("_Z19dk__Octree__getAttrjjjj");
V oc_get_normal(u16, bool) asm("_ZN2dk6Octree9getNormalEtb");
void* get_player() asm("_ZN2YS3OBJ9GetPlayerEv");
V turn_toward(f32, V, V) asm("func_002ea360");
asm("fptodp = func_00313b80");
asm("dpcmp = func_003142e0");

V func_002ea450(void*, OBJ* o) asm("func_002ea450");
V func_002ea450(void*, OBJ* o) {
    V t;
    V a, b, hit, n;
    COLL c;
    V* vel = &o->vel;
    t = *vel;
    t.y = 0.0f;
    f32 m = t.normalize() * D_00352130->f24;
    m = (1.0f < m) ? m : 1.0f;
    o->vel.x = t.x * m;
    o->vel.z = t.z * m;
    if (o->vel.y < 0.0f) o->vel.y = o->vel.y * D_00352130->f32_;
    f32 y = o->vel.y + D_00363404;
    if (!(y < o->f288)) y = o->f288;
    o->vel.y = y;
    V r;
    r = *vel * D_00349e10;
    CB* src = &o->coll;
    (CB&)c = *src;
    c.f128 = 0;
    c.v[0] = *obj_pos(o);
    c.v[1] = r;
    *(u64*)c.w112 |= 1;
    t = c.v[0] + c.v[1];
    coll_update(&c);
    t = (c.v[3] - t) * D_00349e18;
    t.y = 0.0f;
    f32 len = t.normalize();
    t.w = len;
    if (1.0 < len) {
        t *= -(len + src->v[2].x + 5.0f);
        a = c.v[3];
        b = a + t;
        s32 h = coll_ray(&a, &b, &hit, 0);
        if (h >= 0) {
            u16 idx = h;
            if ((*oc_attr(idx, 0) & 0xf) == 2) {
                n = oc_get_normal(idx, false);
                t = *vel;
                a = n * dot(n, t);
                b = t - a;
                a *= -D_00363400;
                a = a + b;
                a.y = 0.0f;
                f32 s = a.normalize();
                t = *obj_pos(get_player()) - hit;
                t = turn_toward(0.08726646f, a, t);
                t.y = 0.0f;
                t.normalize();
                t *= s;
                o->vel.x = t.x;
                o->vel.z = t.z;
            }
        }
    }
    t = *vel * D_00349e10;
    return r;
}
}
