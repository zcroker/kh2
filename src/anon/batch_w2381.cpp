#include "../common/types.h"

// ---- 0014fcd8: spring a value toward an integer target
struct W2381V4 {
    f32 x, y, z, w;
    W2381V4() {}
    W2381V4(const W2381V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2381V4& operator=(const W2381V4& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct W2381Spring { u8 pad[0x24]; s32 tgt; f32 cur; f32 vel; };

extern "C" {
W2381V4 func_0013f6e8(W2381V4, W2381V4, W2381V4, f32, f32, f32, f32);
s32 func_0014fbf8(void*);

// Zero three VU0 vectors in one block.
static inline void w2381_zero3(W2381V4* a, W2381V4* b, W2381V4* c)
{
    asm volatile("sqc2 $vf0, 0(%0)\n\tsqc2 $vf0, 0(%1)\n\tsqc2 $vf0, 0(%2)" : : "r"(a), "r"(b), "r"(c) : "memory");
}

static inline void w2381_spring(W2381V4& cur, const W2381V4& goal, const W2381V4& vel, f32 dt, f32 k, f32 d, f32 r)
{
    cur = func_0013f6e8(cur, goal, vel, dt, k, d, r);
}

void w2381_ctarget(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_0014fcd8jjjj");
void w2381_ctarget(u32 a0, u32, u32, u32)
{
    W2381Spring* o = (W2381Spring*)a0;
    W2381V4 vel;
    W2381V4 pos;
    W2381V4 goal;
    w2381_zero3(&vel, &pos, &goal);
    f32 c = o->cur;
    pos.x = c;
    o->vel = c;
    vel.x = c;
    s32 t = func_0014fbf8(o);
    if (t != o->tgt) {
        goal.x = (f32)t;
        w2381_spring(pos, goal, vel, 0.4f, 1.2f, 0.5f, 0.1f);
        f32 r = pos.x;
        o->cur = r;
        o->tgt = (s32)r;
    }
}
}
