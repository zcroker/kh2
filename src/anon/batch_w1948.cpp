#include "../common/types.h"
struct V1d65f8 {
    f32 x, y, z, w;
    V1d65f8() {}
    V1d65f8& operator=(const V1d65f8& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_001a7610(unsigned int, unsigned int, unsigned int, float, float);
extern "C" {
static inline V1d65f8 sub_1d65f8(const V1d65f8& a, const V1d65f8& b) {
    V1d65f8 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
extern u32 D_003638d0;
static inline s32 rnd_1d65f8(s32 n) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return ((u64)D_003638d0 * n) >> 32;
}
struct O1d65f8 { u8 p0[64]; V1d65f8 v40; u8 p50[4]; void* cb; void* owner; u8 p5c[4]; };
struct S1d65f8 { u8 p0[20]; u8 heap[4]; };
struct T1d65f8 { u8 p0[2548]; T1d65f8* p9f4; };
V1d65f8* func_0016c028(void*);
void func_001c2858(void*, V1d65f8*, void*, void*);
s32 func_001c28f8(void*, V1d65f8*, s32);
O1d65f8* func_001db888(void*, s32, void*);
void func_001dbc58(O1d65f8*, T1d65f8*, V1d65f8*, V1d65f8*);
void func_001ce618(void);
extern V1d65f8 D_01d5ba78;
extern V1d65f8 D_01d5ba88;
void func_001d65f8(T1d65f8* self, void* a, void* b) {
    u8 obj[80];
    V1d65f8 v;
    func_001c2858(obj, func_0016c028(self), a, b);
    T1d65f8* s = self->p9f4->p9f4;
    while (func_001c28f8(obj, &v, 1)) {
    V1d65f8* sel = rnd_1d65f8(2) == 0 ? &D_01d5ba78 : &D_01d5ba88;
    func_001a7610((u32)&v, (u32)&v, 4, 1000.0f, 200.0f);
    v.y -= sel->z;
    O1d65f8* o = func_001db888((u8*)s + 20, 96, __builtin_return_address(0));
    func_001dbc58(o, s, &v, sel);
    o->v40 = sub_1d65f8(v, *func_0016c028(self));
    o->v40.w = 1.0f;
    o->owner = self;
    o->cb = (void*)func_001ce618;
    }
}
}

extern "C" {
struct V2bff98 {
    f32 x, y, z, w;
    V2bff98() {}
    V2bff98& operator=(const V2bff98& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V2bff98 add_2bff98(const V2bff98& a, const V2bff98& b) {
    V2bff98 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V2bff98 sub_2bff98(const V2bff98& a, const V2bff98& b) {
    V2bff98 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V2bff98 lerp_2bff98(const V2bff98& a, const V2bff98& b, f32 t) {
    V2bff98 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
static inline V2bff98 scale_2bff98(const V2bff98& a, f32 s) {
    V2bff98 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct O2bff98 {
    u32 vt;
    u8 p4[12];
    V2bff98 a;      // 0x10
    V2bff98 b;      // 0x20
    u8 p30[0x54 - 0x30];
    u8 sub[8];      // 0x54
    s32 f5c;        // 0x5c
    s32 f60;        // 0x60
    f32 f64;        // 0x64
    u8 p68[8];
    V2bff98 v70;
    V2bff98 v80;
    V2bff98 v90;
    V2bff98 va0;
    V2bff98 vb0;
    V2bff98 vc0;
};
void func_0031cc28(void*) asm("_Z13func_0031cc28Pv");
void func_002c6420(O2bff98*);
extern u8 D_00361da8;
extern u8 D_00361a60;
void func_002bff98(O2bff98* self, V2bff98* p, V2bff98* q, f32 t) {
    self->vt = (u32)&D_00361da8;
    func_0031cc28(self->sub);
    self->f5c = 0;
    func_002c6420(self);
    self->f60 = 0;
    self->vt = (u32)&D_00361a60;
    self->v70 = self->a;
    self->va0 = add_2bff98(*p, *q);
    self->v80 = lerp_2bff98(self->a, self->va0, 0.2f);
    self->v90 = lerp_2bff98(self->a, self->va0, 0.95f);
    self->vb0 = sub_2bff98(self->b, self->a);
    self->vc0 = scale_2bff98(*q, -1.0f);
    self->f64 = t;
    self->f5c = 0;
}
}
