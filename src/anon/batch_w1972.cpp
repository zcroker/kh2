#include "../common/types.h"

struct W1972Vq {
    f32 x, y, z, w;
    W1972Vq& operator=(const W1972Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct W1972Glob { W1972Vq a, b, c, res; u8 pad40[0x30]; u64 flags; };
struct W1972Own { u8 pad0[4]; f32 y; s32 f8; };
struct W1972Ent {
    W1972Vq pos;        // 0x00
    u32 state;          // 0x10
    u8 pad14[0x14];
    u32 flags;          // 0x28
    u8 pad2c[4];
    W1972Vq vel;        // 0x30
    u8 pad40[4];
    u8 cnt;             // 0x44
    u8 pad45[7];
    W1972Own* own;      // 0x4c
};

extern W1972Glob D_01d498d0;
extern u8 D_001c7520[];

static inline W1972Vq w1972_vsub(const W1972Vq& a, const W1972Vq& b) {
    W1972Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void w1972_vzero(W1972Vq* v) {
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "memory");
}

extern "C" {
void func_001c7148(W1972Ent*);
void func_002bc188(s32, W1972Ent*);
f32 func_002f8870(f32);

void func_001c71f8(W1972Ent* o, f32 k) {
    func_001c7148(o);
    f32 vy = o->vel.y;
    if (0.0f <= vy && !(D_01d498d0.flags & (1ULL << 32))) {
        if (5.0f < vy) {
            o->vel.y = vy * k;
            if (o->cnt < 2) func_002bc188(o->own->f8, o);
            o->cnt++;
        } else {
            w1972_vzero(&o->vel);
            o->state = (u32)D_001c7520;
        }
    }
    W1972Vq d;
    d = w1972_vsub(D_01d498d0.res, D_01d498d0.a);
    f32 lim = 0.1f;
    if (lim < func_002f8870(d.x - o->vel.x)) o->vel.x = -o->vel.x;
    if (lim < func_002f8870(d.z - o->vel.z)) o->vel.z = -o->vel.z;
    o->pos = D_01d498d0.res;
    o->pos.y -= o->own->y;
    f32 v = o->vel.y + 3.0f;
    o->vel.y = v;
    if (50.0f < v) o->vel.y = 50.0f;
    o->vel.x *= 0.95f;
    o->vel.z *= 0.95f;
    if (0.0f <= o->vel.y) o->flags |= 1;
}
}
