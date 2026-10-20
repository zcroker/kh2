#include "../common/types.h"
// batch w1782

struct Box144860 { f32 mn[3]; f32 mx[3]; };

struct V11a858 {
    f32 x, y, z, w;
} __attribute__((aligned(16)));
// VU0 macro ops: scale by a scalar, vector add.
static inline V11a858 operator*(const V11a858& a, f32 k) {
    V11a858 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline V11a858 operator+(const V11a858& a, const V11a858& b) {
    V11a858 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

#define QCOPY134668(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Q134668 {
    f32 x, y, z, w;
    Q134668() {}
    Q134668(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    Q134668& operator=(const Q134668& o) {
        if (this != &o) QCOPY134668(this, &o);
        return *this;
    }
    // VU0 zero vector (vsub vf0-vf0).
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct O134668 { Q134668 a, b, c, d, e, f, g; };

extern "C" {
u8* func_00106a60(s32);
V11a858 func_00107388(u8*);
extern Q134668 D_00347ce0;

// Merge two boxes: componentwise min of the first corner, max of the second.
void func_00144860(Box144860* __restrict o, Box144860* a, Box144860* b) asm("_Z13func_00144860Pv");
void func_00144860(Box144860* __restrict o, Box144860* a, Box144860* b) {
    o->mn[0] = a->mn[0] < b->mn[0] ? a->mn[0] : b->mn[0];
    o->mn[1] = a->mn[1] < b->mn[1] ? a->mn[1] : b->mn[1];
    o->mn[2] = a->mn[2] < b->mn[2] ? a->mn[2] : b->mn[2];
    o->mx[0] = b->mx[0] < a->mx[0] ? a->mx[0] : b->mx[0];
    o->mx[1] = b->mx[1] < a->mx[1] ? a->mx[1] : b->mx[1];
    o->mx[2] = b->mx[2] < a->mx[2] ? a->mx[2] : b->mx[2];
}

V11a858 func_0011a858(void) {
    u8* c = func_00106a60(1);
    V11a858 p = func_00107388(c);
    f32 x = *(f32*)(c + 0x18);
    f32 y = *(f32*)(c + 0x28);
    f32 z = *(f32*)(c + 0x38);
    V11a858 d;
    d.x = x; d.y = y; d.z = z; d.w = 0.0f;
    V11a858 r = p + d * 300.0f;
    r.w = 1.0f;
    return r;
}

void func_00134668(O134668* o) {
    Q134668* b = &o->b; Q134668* c = &o->c; Q134668* d = &o->d; Q134668* e = &o->e; Q134668* f = &o->f; Q134668* g = &o->g;
    o->a.Zero();
    b->Zero();
    c->Zero();
    o->b.z = 1.0f;
    o->b.y = 1.0f;
    o->b.x = 1.0f;
    *f = Q134668(1.0f, 1.0f, 1.0f, 1.0f);
    *e = *f;
    *d = *e;
    *g = D_00347ce0;
}
}
