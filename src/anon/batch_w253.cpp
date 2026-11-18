#include "../common/types.h"

// 16-byte vector copied with lq/sq (VU0 code in func_0018a318)
struct W253Vec {
    f32 x, y, z, w;
    W253Vec() {}
    W253Vec(const W253Vec& o) { asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W253Vec& operator=(const W253Vec& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {
extern u32 D_00341788[8];
extern s32 D_003417a8;
void u_tail4(u32 a0, u8 a1) asm("_Z16u_tail4_001128d0jjjj");
void u_tail4(u32 a0, u8 a1);  // 0x001128d0: definition moved into src/anon/unit_001117d8.cpp


u32 __fixunssfsi(f32);
void wt239(u8* a0, f32 r, f32 g, f32 b, f32 a) asm("_Z16wtarget_00239fd0jjjj");
void wt239(u8* a0, f32 r, f32 g, f32 b, f32 a);  // 0x00239fd0: definition moved into src/anon/unit_00239988.cpp


extern u32 D_003638d0;
extern u32 D_003512e8;
void func_00169398(void*, u32, void*, s32, s32, f32);
void func_0016bd60(void*, s32);
static inline f32 rf() { D_003638d0 = D_003638d0 * 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f; }
static inline f32 rnd2(f32 lo, f32 w) { return lo + rf() * w; }
void func_001bf270(u8* a0, u32* a1, s32 a2, u32 a3, f32 f);  // 0x001bf270: definition moved into src/anon/unit_001bc568.cpp

extern u32 D_0034b250;
extern u32 D_00348698;
extern u32 D_0034b268;
extern u32 D_0034b278;
struct VObj { void (**vt)(...); };
typedef void (*DtorFn)(u8*);
void func_0031dee8(u8* a0);  // 0x0031dee8: definition moved into src/anon/unit_0031b9e0.cpp

f32 fabsf(f32);  // fabsf
static inline W253Vec vsub(const f32* a, const f32* b) {
    W253Vec r;
    asm volatile(".set noreorder\n\tlqc2 vf1,0(%1)\n\tlqc2 vf2,0(%2)\n\tvsub.xyzw vf1,vf1,vf2\n\tsqc2 vf1,0(%0)\n\t.set reorder" : : "r"(&r), "r"(a), "r"(b) : "memory");
    return r;
}
static inline f32 vdot3m(const W253Vec& a, const W253Vec& b) {
    f32 r;
    asm volatile("lqc2 vf1,0(%1)\n\tlqc2 vf2,0(%2)\n\tvmul.xyz vf1,vf1,vf2\n\tvaddy.x vf1,vf1,vf1\n\tvaddz.x vf1,vf1,vf1\n\tqmfc2 $8,vf1\n\tmtc1 $8,%0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
s32 func_0018a318(u8* a0, u8* a1);  // 0x0018a318: definition moved into src/anon/unit_00189d38.cpp
}
