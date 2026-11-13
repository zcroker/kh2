#include "../common/types.h"

// 16-byte VU0 vector.
struct W1634Vec {
    f32 x, y, z, w;
} __attribute__((aligned(16)));

// Motion player embedded in the object at +320.
struct W1634Motion {
    u8 pad0[20];
    s32 id;                  // current motion id (+340 in the object)
    u8 pad18[8];
};

struct W1634MotObj {
    u8 pad0[16];
    W1634Vec vel;            // +16 (y = vertical speed, w = horizontal speed)
    W1634Vec dir;            // +32
    u8 pad30[236];
    f32 turnLimit;           // +284
    u8 pad120[32];
    W1634Motion motion;      // +320
    u32 motFlags;            // +352
};

extern "C" {
extern s32 D_003638d8[3][6];   // motion id tables: idle, idle2, stop, turn right, turn left
s32 func_0016a070(W1634MotObj*);   // YS::OBJ::get_part_num
f32 fabsf(f32);            // fabsf
s32 func_002eff58(W1634MotObj*);
void func_0016af58(W1634Vec*, W1634MotObj*);
f32 func_002f8aa0(f32);
f32 func_002efe18(W1634MotObj*, s32, f32);
void func_0017f488(W1634Motion*, s32, f32, f32);
}

static inline void W1634VecCopy(W1634Vec* d, const W1634Vec* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void W1634VecAdd(W1634Vec* d, const W1634Vec* a, const W1634Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 W1634Normalize(W1634Vec* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline f32 W1634Dot(const W1634Vec* a, const W1634Vec* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
static inline void W1634Cross(W1634Vec* r, const W1634Vec* a, const W1634Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}

// t[2] is pinned to t6: the original keeps the stop-motion entry in t6 at every compare
// (register pin, no code; the closest plain C put it in t7 and changed the delay-slot fills).
static inline bool W1634InTable(s32 id, const s32* t) {
    register s32 stop asm("$14");
    if (id == t[0] || id == t[1] || id == (stop = t[2]) || id == t[3] || id == t[4]) return true;
    return false;
}

// True unless the change is idle -> stop or stop -> none (those cut without blending when flag 2 is set).
static inline bool W1634NeedBlend(s32 cur, s32 next, s32 idle, s32 stop) {
    if (cur == idle && next == stop) return false;
    if (cur == stop && next == 0) return false;
    return true;
}

extern "C" {
// Picks the idle/turn motion for obj from its part's table and starts it.
// 002eff90: moved to src/anon/unit_002efd68.cpp
}
