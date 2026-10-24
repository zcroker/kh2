#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V4_784 {
    f32 x, y, z, w;
    V4_784& operator=(const V4_784& o) { if (this != &o) QCOPY(this, &o); return *this; }
    void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct Tgt_784 { u8 pad[0xa30]; V4_784 pos; };
struct Ob_784 {
    u8 pad[0x10]; V4_784 dir; u8 p2[0x110 - 0x20]; f32 f110, f114;
    u8 p3[0x66c - 0x118]; f32 angle; u8 p4[0xb44 - 0x670]; Tgt_784* target;
};
extern "C" {
V4_784 func_00178330(V4_784*) asm("_Z16ctarget_00178330jjjj");
f32 func_002f8960(f32);  // sinf
f32 func_002f87c0(f32);  // cosf

/* 001784a8: aim direction toward the target if it has one (w > 0), else from the facing angle.
   The inline V4::set in the else branch leaves its `this` copy's save slot (unused s1) behind. */
void func_001784a8(Ob_784* o) {
    if (o->target->pos.w > 0.0f) {
        o->dir = func_00178330(&o->target->pos);
        o->dir.w = (o->dir.w < 0.8f) ? o->f110 : o->f114;
    } else {
        o->dir.set(func_002f8960(o->angle), 0.0f, func_002f87c0(o->angle), 0.0f);
    }
}
}
