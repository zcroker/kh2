#include "../../common/types.h"

// dk::ScopeCamera, first part (0x158708-0x158900): the scope (first-person aim) camera. It looks
// from the target's head toward a point and blends the eye position. The rest of the file
// (ScopeCamera::destroy and the light fade values that share its data) is src/yasui/libys/light.cpp.

struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V4 Lerp(const V4& a, const V4& b, f32 t) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
static inline f32 Normalize(V4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void MulS(V4* v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "f"(s) : "$8", "memory");
}
static inline V4 operator-(const V4& a, const V4& b) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V4 operator+(const V4& a, const V4& b) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct C8708 { V4 p0; u8 pad[80]; V4 p96; u8 pad2[16]; V4 p128; };

extern u8* D_0034a990;  // target object
extern f32 D_0034a994;  // eye height offset

extern f32 D_0034a998;  // blend factor
extern f32 D_0034a99c;  // look distance
extern V4 D_0034a9a0;   // eye position

extern "C" {
V4* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_00141010(f32);
u8* func_00140df0(void) asm("_ZN2dk9ObjCamera11getInstanceEv");

void func_00158708(C8708* o) {
    V4 a;
    V4 d;
    a = *func_0016c028(D_0034a990);  // obj_get_attach_or_alt
    a.y -= D_0034a994;
    d = a - D_0034a9a0;
    Normalize(&d);
    MulS(&d, D_0034a99c);
    d = D_0034a9a0 + d;
    o->p96 = Lerp(a, d, D_0034a998);
    o->p128 = D_0034a9a0;
    o->p0 = D_0034a9a0;
}

void func_00158870(u8* obj, f32 f) {
    func_00141010(30.0f);
    *(u32*)(func_00140df0() + 64) = 7;
    D_0034a990 = obj;
    D_0034a994 = f;
    D_0034a998 = 0.5f;
    D_0034a99c = 10.0f;
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&D_0034a9a0) : "memory");
}

}  // extern "C"

u8* D_0034a990 = 0;
f32 D_0034a994 = 0.0f;
