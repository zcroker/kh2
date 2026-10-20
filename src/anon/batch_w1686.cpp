#include "../common/types.h"

extern "C" {

// 16-byte VU0 vector (FVector)
struct W1686Vec {
    f32 x, y, z, w;
    W1686Vec() {}
    W1686Vec& operator=(const W1686Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// YS::COLLISION
struct W1686Col {
    s32 type;
    f32 a, b;
    s32 c;
    W1686Vec pos;
    W1686Col() { c = 0; }
};

struct W1686Magic;

// attack work handed to the work manager
struct W1686Work {
    W1686Magic* owner;
    s32 pad[3];
    W1686Col col;
};

struct W1686Magic {
    s32 pad0;
    u32 flags;               // 0x04
    u8 pad8[0xc4 - 0x8];
    void* effect;            // 0xc4
    f32 time;                // 0xc8
    f32 time_max;            // 0xcc
    W1686Vec size_start;     // 0xd0
    W1686Vec pos;            // 0xe0
    W1686Vec line_end;       // 0xf0
    W1686Vec size;           // 0x100
    u32 is_line() const { return flags & 0x20; }
    u32 is_track() const { return flags & 4; }
};

s32 func_001dc9d0(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
W1686Vec* func_001dc5f8(void*) asm("_ZN3ryj6EFFECT3posEv");
void func_001a48c0(W1686Magic*, W1686Vec*);
void func_0018f028(W1686Magic*) asm("_ZN2YS6ATTACK7destroyEv");
f32 func_002f8960(f32);
void func_0018a958(W1686Col*, s32, f32, f32) asm("_ZN2YS9COLLISION4makeEiff");
s32 func_0018eaf8(void*, W1686Work*);
void func_0018dc28(W1686Magic*, W1686Vec*, W1686Vec*);

extern u32 D_0034f240;
extern f32 D_00349e10;

static inline W1686Vec w1686_lerp(const W1686Vec& a, const W1686Vec& b, f32 t) {
    W1686Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}

static inline W1686Vec w1686_sub(const W1686Vec& a, const W1686Vec& b) {
    W1686Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

// normalize xyz in place, return the old length
static inline f32 w1686_norm(W1686Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

static inline void w1686_scale(W1686Vec* v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(v), "f"(s) : "$8", "memory");
}

static inline void w1686_add(W1686Vec* d, const W1686Vec* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}

static inline f32 w1686_min(f32 a, f32 b) { return a < b ? a : b; }

// YS::ATTACK_MAGIC::make_work(ATTACK_WORK_MANAGER*)
void func_001a45b8(W1686Magic* self, void* mgr) {
    W1686Vec pos;
    W1686Vec dir;
    W1686Vec size;
    W1686Work work;

    if (self->effect) {
        if (!func_001dc9d0(self->effect)) { func_0018f028(self); return; }
        func_001a48c0(self, func_001dc5f8(self->effect));
    }
    if (self->time_max > 0.0f) {
        if (!(D_0034f240 & 0x20)) {
            self->time += D_00349e10;
            if (self->time_max < self->time) { func_0018f028(self); return; }
        }
        size = w1686_lerp(self->size_start, self->size, func_002f8960(self->time / self->time_max * 3.1415927f * 0.5f));
    } else {
        size = self->size;
    }
    {
        f32 len;
        f32 step = w1686_min(size.x, size.y);
        if (step <= 0.0f) return;
        pos = self->pos;
        if (self->is_line() || self->is_track()) {
            dir = w1686_sub(self->line_end, self->pos);
            len = w1686_norm(&dir);
            w1686_scale(&dir, step);
        } else {
            len = 0.0f;
        }
        s32 mode = 3;
        work.owner = self;
        if (size.x != size.y) mode = 0;
        do {
            func_0018a958(&work.col, mode, size.x, size.y);
            work.col.pos = pos;
            if (!func_0018eaf8(mgr, &work)) break;
            w1686_add(&pos, &dir);
            len -= step;
        } while (step * 0.5f < len);
        if (self->is_track()) func_0018dc28(self, &self->line_end, &self->pos);
    }
}

}
