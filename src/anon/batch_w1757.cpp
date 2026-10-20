#include "../common/types.h"

// 128-bit lq/sq copy: the original's FVector operator= (hand-written asm in kn).
#define QCOPY1757(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct W1757Vec {
    f32 x, y, z, w;
    W1757Vec& operator=(const W1757Vec& o) {
        if (this != &o) QCOPY1757(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

struct W1757Obj {
    u8 pad[0x540];
    W1757Vec pos;
};

struct W1757V3 { f32 x, y, z; };
struct W1757Timer {
    u8 pad[4];
    s32 cnt;
    W1757V3 p;
};
struct W1757V4 { f32 x, y, z, w; };

extern "C" {
extern W1757V4 D_00350990;
void func_001ba028(void*);
void func_00193608(void*);
u32 func_001024a8(...);

void W1757_set_pos(W1757Obj* self, const W1757Vec& v) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W1757_set_pos(W1757Obj* self, const W1757Vec& v) {
    func_001ba028(self);
    self->pos = v;
    self->pos.w = 1.0f;
    func_00193608(self);
}

// Counts down; when the count runs out, publishes the position (w = 0).
void func_001733f8(W1757Timer* o) {
    if (o->cnt-- > 0) return;
    f32 x = o->p.x, y = o->p.y, z = o->p.z;
    D_00350990.x = x;
    D_00350990.y = y;
    D_00350990.z = z;
    D_00350990.w = 0.0f;
    func_001024a8(o);
}
}
