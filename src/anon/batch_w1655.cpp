#include "../common/types.h"
extern "C" void func_00190128(void*);
struct W1655QW {
    f32 x, y, z, w;
    W1655QW() {}
    W1655QW(const W1655QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1655QW& operator=(const W1655QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// d = a - b (VU0)
static inline void w1655_vsub(W1655QW* d, const W1655QW* a, const W1655QW* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
// normalize xyz in place, return the old length
static inline f32 w1655_vnorm(W1655QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w1655_vlen(const W1655QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w1655_vdot(const W1655QW* a, const W1655QW* b) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}
struct W1655Obj;
// YS::TARGET: object + collision element id (20 bytes)
struct W1655Tgt {
    W1655Obj* obj;
    s32 id;
    s32 c, d, e;
    W1655Tgt() { func_00190128(this); }
};
// YS::COLLISION_ELEM
struct W1655Elem { u8 id; u8 p1; u16 flags; };
// hit sphere filled by func_0018a818
struct W1655Hit { s32 p0; f32 radius; f32 height; s32 pc; W1655QW centre; };
struct W1655Prm { u8 p0[0x60]; f32 low; f32 high; u8 p68[4]; f32 yscale; f32 dirmin; };
struct W1655ObjVt { void* f[39]; W1655QW (*getPos)(W1655Obj*); };
struct W1655Obj { W1655ObjVt* vt; u8 p4[0x130 - 4]; W1655Prm* prm; u8 p134[0x588 - 0x134]; u32 flags; };
struct W1655Sys { u8 p0[0x4c]; f32 lockRange; };
extern "C" {
extern W1655Sys* D_00352130;
f32 W1655_GetLockOnRatio() asm("_ZN2YS6STATUS14GetLockOnRatioEv");
W1655Obj* W1655_ctarget(W1655Obj*) asm("_Z16ctarget_001b9bc8jjjj");
W1655Elem* W1655_each_collision(W1655Obj*, s32, W1655Elem*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
void W1655_set_obj(W1655Tgt*, W1655Obj*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
f32 W1655_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
f32 f_atan2f(f32, f32);
f32 fabsf(f32);  // fabsf
s32 func_0019bc38(W1655Obj*);
s32 func_0019bb58(W1655Obj*);
void func_0018a818(W1655Hit*, W1655Obj*, W1655Elem*);
W1655QW func_00190388(W1655Tgt*);
W1655QW* func_0016c028(W1655Obj*);
W1655QW func_0016af58(W1655Obj*);
}
// Best candidate so far: the target plus its score (kept in memory, next to the target).
struct W1655Best { W1655Tgt t; f32 v; };
static inline W1655QW w1655_sub(const W1655QW& a, const W1655QW& b) { W1655QW r; w1655_vsub(&r, &a, &b); return r; }
extern "C" {
// Pick the collision element whose bearing from obj is most in front, within lock-on range.
W1655Tgt func_00190d10(W1655Tgt* cur, W1655Obj* self, f32 scale);  // 0x00190d10: definition moved into src/anon/unit_001900d0.cpp

// Lock onto the nearest collision element, weighted by how far it is off self's facing.
void func_00190f80(W1655Tgt* t, W1655Obj* self, f32 limit);  // 0x00190f80: definition moved into src/anon/unit_001900d0.cpp

// Pick the nearest collision element lying in direction dir (flattened), within lock-on range.
W1655Tgt func_001913d8(W1655Tgt* cur, W1655Obj* self, const W1655QW* dir);  // 0x001913d8: definition moved into src/anon/unit_001900d0.cpp
}
