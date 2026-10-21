#include "../common/types.h"

// 002edd20: vector with lq/sq copy-assign (self-check), used by value in a segment.
struct W1831QV {
    f32 x, y, z, w;
    W1831QV() {}
    W1831QV& operator=(const W1831QV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1831Seg {
    W1831QV a, b;
    W1831Seg(const W1831QV& p, const W1831QV& q) { a = p; b = q; }
    W1831Seg() {}
};
struct W1831Obj { u8 pad[0x600]; s64 lo : 3; s64 kind : 32; };

// 002ecef8: vector with lq/sq copy ctor, copy-assign and VU0 scale.
struct W1831QC {
    f32 x, y, z, w;
    W1831QC() {}
    W1831QC(const W1831QC& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1831QC& operator=(const W1831QC& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1831QC& operator*=(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    W1831QC operator*(f32 k) const {
        W1831QC r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1831Body {
    u8 p0[0x10];
    W1831QC v10;
    W1831QC v20;
    u8 p30[0xf0 - 0x30];
    f32 ff0;
    u8 pf4[0x114 - 0xf4];
    f32 f114;
};

extern "C" {
// Soft-float double helpers (game copies). Declared const so gcc treats them like its own libcalls.
u64 func_00313b80(f32) __attribute__((const));
u64 func_00313ed8(u64, u64) __attribute__((const));
u64 func_00313e80(u64, u64) __attribute__((const));
f32 func_003144b0(u64) __attribute__((const));
s32 func_003142e0(u64, u64) __attribute__((const));

W1831QV* func_0016c028(W1831Obj*);
s32 func_00143b60(W1831Seg, W1831QV*, s32);

f32 func_002edd20(W1831Obj* o) {
    W1831QV hit;
    W1831QV a;
    W1831QV b;
    W1831Seg s;
    W1831QV* pa = &a;
    W1831QV* pb = &b;
    W1831QV* pc = &s.a;
    W1831QV* pd = &s.b;
    *pa = *func_0016c028(o);
    *pb = *pa;
    a.y = func_003144b0(func_00313ed8(func_00313b80(a.y), 0x4069000000000000ULL));
    b.y = func_003144b0(func_00313e80(func_00313b80(b.y), 0x40c3ec0000000000ULL));
    *pc = *pa;
    *pd = *pb;
    if (func_00143b60(s, &hit, o->kind & 0xf)) return -(func_0016c028(o)->y - hit.y);
    return 10000.0f;
}

extern f32 D_00349e10;
void func_0016b010(W1831Body*, W1831QC);
W1831QC func_0016af58(W1831Body*);

W1831QC func_002ecef8(void* self, W1831Body* o) {
    W1831QC a;
    if (func_003142e0(0, func_00313b80(o->v10.w)) < 0 && o->v10.x != 0.0f && o->v10.z != 0.0f) {
        func_0016b010(o, o->v10);
    }
    a = func_0016af58(o);
    a *= o->f114;
    a.y = o->v10.y * o->v10.w * (1.0f - o->ff0) + o->v20.y * o->ff0;
    o->v20 = a;
    return a * D_00349e10;
}
}
