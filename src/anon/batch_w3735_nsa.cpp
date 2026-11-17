#include "../common/types.h"

struct FV {
    f32 x, y, z, w;
    FV() {}
    FV(const FV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    FV& operator=(const FV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct FM {
    FV r[4];
    FV operator*(const FV& v) const {
        FV o;
        asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(&v), "r"(this) : "memory");
        return o;
    }
};
struct FTri { u16 x0, v0, v1, v2, v3, plane, x0c, mat; };
struct FPoly { FV* v[4]; s32 n; };
struct FColl {
    u8 pad0[0xc];
    FTri* tris;
    FV* verts;
    u32* mats;
    FV* planes;
    u8 pad1c[0x74];
    FM mtx;
    u8 padd0;
    u8 noMtx;
};
struct FFlags { u64 b0:1; u64 pad:31; u64 hit:1; u64 hi:31; };
struct FRes {
    FV base;
    f32 x10, x14, x18, x1c;
    f32 x20, x24, x28, x2c;
    FV pos;
    u8 pad40[0x20];
    s16 idx;
    u8 pad62[0xa];
    f32 x6c;
    FFlags fl;
    u8 pad78[8];
    f32 x80;
};

extern "C" {
void func_00141988(FColl*, FTri*, FPoly*);
s32 func_00163828(FV*, FV*, FV*);

// Collision triangle hit test: resolves a hit against triangle idx (or a height test when bit 0 is clear).
void func_001419f8(FColl* c, u16 idx, FRes* r, FV* p);  // 0x001419f8: definition moved into src/anon/unit_00141458.cpp
}
