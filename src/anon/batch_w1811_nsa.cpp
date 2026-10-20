#include "../common/types.h"

struct W1811V {
    f32 x, y, z, w;
    W1811V() {}
    W1811V& operator=(const W1811V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1811V operator-(const W1811V& o) const {
        W1811V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1811V operator*(f32 k) const {
        W1811V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    W1811V& operator+=(const W1811V& b) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

/* 001c6760: falling particle (velocity damping, gravity clamp, fade-out timer in vel.w). */
struct W1811Part { W1811V pos; u8 pad[5]; u8 alpha; u8 pad2[0x2a]; W1811V vel; };

/* 002ed630: homing mover (target at 0x64, turn rate 0x60, speed 0x5c). */
struct W1811Tgt { s32 a, b, c, d, e; };
struct W1811Homer { W1811V pos; u8 p10[0x20]; W1811V dir; W1811V vel; u8 p50[0xc]; f32 spd; f32 turn; W1811Tgt tgt; s32 flags; };

extern f32 D_00349e10;

extern "C" {
W1811V func_00190388(W1811Tgt*);
W1811V func_0017d348(W1811V*, W1811V*, f32);

void func_001c6760(W1811Part* o) {
    o->vel.x *= 0.95f;
    o->vel.z *= 0.95f;
    f32 y = o->vel.y + D_00349e10 * 0.41666666f;
    o->vel.y = (30.0f < y) ? 30.0f : y;
    o->pos += o->vel * D_00349e10;
    f32 tm = o->vel.w;
    if (tm < 4.0f) o->alpha = (s32)(tm * 0.25f * 128.0f);
    o->vel.w = tm - D_00349e10;
}

void func_002ed630(W1811Homer* o) {
    if ((o->flags & 1) == 1) {
        o->dir = func_00190388(&o->tgt) - o->pos;
        o->vel = func_0017d348(&o->vel, &o->dir, o->turn);
    }
    o->pos += o->vel * o->spd * D_00349e10;
}
}
