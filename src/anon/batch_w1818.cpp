#include "../common/types.h"

// 128-bit copy (lq/sq through t0).
#define QCOPY1818(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct Vec1818 {
    f32 x, y, z, w;
    Vec1818() {}
    Vec1818(const Vec1818& o) { QCOPY1818(this, &o); }
    Vec1818& operator=(const Vec1818& o) { if (this != &o) QCOPY1818(this, &o); return *this; }
} __attribute__((aligned(16)));

// VU0: r = a - b (all four lanes)
static inline Vec1818 operator-(const Vec1818& a, const Vec1818& b) {
    Vec1818 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// VU0: xyz length
static inline f32 vlen1818(const Vec1818& v) {
    f32 l;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(l) : "r"(&v) : "$8", "memory");
    return l;
}
// VU0: xyz squared length
static inline f32 vlensq1818(const Vec1818& v) {
    f32 l;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(l) : "r"(&v) : "$8", "memory");
    return l;
}

struct Obj1818 { u32 a, b; s32* id; };
struct Slot1818 { u32 x; Obj1818* p; };
struct Owner1818 { u8 pad[320]; u32 q[4]; };
struct Act1818 { u8 pad[0x508]; u32 p; };

extern "C" {

// --- 002d24e8: keep the nearer of two objects with id 2031/2032
extern Vec1818* YS__OBJ__get_pos(Obj1818*);  // obj_get_attach_or_alt
extern Obj1818* func_002d1260(void);
void Ti__MGOarashi__set_current_tornado(Owner1818* s, Obj1818* o);  // 0x002d24e8: definition moved into src/anon/unit_002d2498.cpp

// --- 002eb098: target within +-30 height and 50 horizontal distance
extern Vec1818* func_0016c028_a(Act1818*) asm("YS__OBJ__get_pos");
extern Vec1818 func_002cbed8(u32);
// 002eb098: moved to src/anon/unit_002eaf38.cpp

}
