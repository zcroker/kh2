// Linked unit 0x00117588-0x00117808.
#include "../naka/libkn/stitch.hpp"
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 00117588 (was whole asm src/anon/asm_00117588.s)
namespace n00117588 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) { if (this != &o) QCOPY(this, &o); return *this; }
    QV operator*(f32 s) const {
        QV o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\t.set noreorder\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "f"(s) : "$8", "memory");
        return o;
    }
} __attribute__((aligned(16)));
#define QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QM {
    f32 m[4][4];
    QV& row(int i) { return *(QV*)m[i]; }
    QM() {}
    QM& operator=(const QM& o) { if (this != &o) QCOPY4(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Owner { u8 pad[320]; u8 sub; };
struct Stitch {
    u32 f0;
    Owner* owner;
    u8 pad8[1600 - 8];
    QV pos;
    u8 pad1616[48];
    QM m0;
    QM m1;
    QM m2;
    QM m3;
};
void M_identity(QM*) asm("_Z13func_0011b6a8Pv");
void M_rotateZ(QM*, f32) asm("_ZN2kn7FMatrix7rotateZEf");
f32 FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
extern "C" {
QV func_0017ff68(u8*);
extern QV D_003a99e0;
}
// The matrix is a plain f32[4][4]: the column stores then may alias the temp vector reads, so they stay grouped.
/*TARGET 00117588*/
void Stitch_update_obj_pos(Stitch* self) asm("_ZN2kn6Stitch14update_obj_posEv");
void Stitch_update_obj_pos(Stitch* self) {
    QV* p = &self->pos;
    f32 k = 0.50364393f;
    QV r = func_0017ff68(&self->owner->sub);
    M_identity(&self->m0);
    M_rotateZ(&self->m0, FixRadian(self->pos.w - r.w));
    self->m0.row(3) = *p * k;
    self->m0.m[3][3] = 1.0f;
    f32 w = 1024.0f;
    {
        QV t(0.0f, -10.0f, 0.0f, 0.0f);
        self->m1 = self->m0;
        self->m1.m[0][3] = t.x;
        self->m1.m[1][3] = t.y;
        self->m1.m[2][3] = t.z;
        self->m1.m[3][3] = w;
    }
    M_identity(&self->m2);
    self->m2.row(3) = D_003a99e0 * k;
    self->m2.m[3][3] = 1.0f;
    {
        QV t(0.0f, -70.0f, 0.0f, 0.0f);
        self->m3 = self->m2;
        self->m3.m[0][3] = t.x;
        self->m3.m[1][3] = t.y;
        self->m3.m[2][3] = t.z;
        self->m3.m[3][3] = w;
    }
}
}  // namespace n00117588
#undef QCOPY
#undef QCOPY4

// 00117778 (was src/naka/libkn/stitch.cpp)
namespace kn { // method 00117778
extern void Stitch_update_obj_pos(void*) asm("_ZN2kn6Stitch14update_obj_posEv");
/*TARGET 00117778*/
void Stitch::post_exec() { Stitch_update_obj_pos(this); }
}  // kn

// 00117790 (was gap)
namespace g00117790 {
s32 func_001dca20(void*) asm("func_001dca20");
void func_00117910(void*, s32) asm("func_00117910");
// For each of the 24 slots whose object is still alive, call the slot handler 0x117910.
void f(u8* o) asm("func_00117790");
void f(u8* o) {
    u8* p = o + 40;
    for (s32 i = 0; i < 24; i++) {
        void* e = *(void**)p;
        p += 64;
        if (e && func_001dca20(e)) func_00117910(o, i);
    }
}
}  // namespace g00117790

