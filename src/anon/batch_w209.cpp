#include "../common/types.h"

// 128-bit copy (lq/sq through t0).
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte aligned vector; assignment copies a quadword unless self-assigned.
struct V209 {
    f32 x, y, z, w;
    V209() {}
    V209(const V209& o) { QCOPY(this, &o); }
    V209& operator=(const V209& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

union E209 { struct { u16 a, b; } s; u32 u; u8 c; };

extern "C" {

// --- 0016d800
struct VP209 { V209* p; u32 x; f32 y; };
extern V209 func_0017d348(V209* self, u32 x, f32 y);
void func_0016d800(VP209* a) {
    V209* self = a->p;
    u32 x = a->x;
    *self = func_0017d348(self, x, a->y);
}

// --- 001a6600
extern f32 func_001826e0(void);  // global_float_diff
u32 cac209(f32 f) asm("_ZN2YS5MAGIC10CanAddCostEf");
u32 cac209(f32 f) { return f <= func_001826e0() + 2.0f; }

// --- 001a8450
extern u32 D_0032dedc[];
u32 call4_209(u8* a, u32 b, u32 c, u32 d) asm("_Z16u_call4_001a8450jjjj");
u32 call4_209(u8* a, u32 b, u32 c, u32 d) {
    u32 r = 0;
    if (a) {
        u32 t = *(u16*)(a + 10);
        u32 bit = t & 0x1f;
        u32 idx = t >> 5;
        if (t)
            r = (D_0032dedc[idx] & (1 << bit)) != 0;
    }
    return r;
}

// --- 001db250
extern u8* D_0034e948;
extern void func_0017d0e8(void* out, f32 f);
extern void func_0019c778(void* a, void* b);
void func_001db250(u8* a) {
    u8 tmp[16] __attribute__((aligned(16)));
    f32 f = *(f32*)(*(u8**)(a + 0x6c) + 0x20);
    func_0017d0e8(tmp, -1.5707964f - f);
    func_0019c778(D_0034e948, tmp);
}

// --- 002376d8
void func_002376d8(u8* a, s32 b) {
    if (b < *(s32*)(a + 0x3c)) {
        E209* t = *(E209**)(a + 12) + b;
        *(s32*)(a + 0x68) = b;
        *(u32*)(a + 0x14) = *(u32*)(a + 8) + t->s.a * 20;
        *(u32*)(a + 0x18) = t->s.b;
    }
}

// --- 00242b88
extern u8* func_001058e8(void);
void func_00242b88(u8 a) {
    u8* p = func_001058e8() + 16800;
    u32 v = a == 0;
    *(u32*)(p + 4) = (*(u32*)(p + 4) & ~0x10u) | (v << 4);
}

// --- 00281cf0
extern void func_00281b30(u32);
extern u8 D_0035f298;
extern f32 D_0035f294;
extern u16 D_0035f280;
void func_00281cf0(u32 a) {
    D_0035f294 = 15.0f;
    D_0035f298 = 0;
    func_00281b30(a);
    D_0035f280 = a;
}

// --- 002cd3e0
extern V209* func_0016c028(u32);  // obj_get_attach_or_alt
extern void func_002cd428(u32, V209*);
void func_002cd3e0(u32 a, u32 b) {
    V209 t(*func_0016c028(b));  // obj_get_attach_or_alt
    func_002cd428(a, &t);
}

}
