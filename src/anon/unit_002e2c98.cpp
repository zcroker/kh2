// Linked unit 0x002e2c98-0x002e2d18 (Ti::MG_EHSidecar direction maker; was whole asm in src/anon/asm_002e2c98.s).
#include "../common/types.h"

namespace n002e2c98 {
struct FV {
    f32 x, y, z, w;
    FV() {}
    // w is stored before y (after y is read): with the first scheduling pass off this is the order the
    // second pass keeps.
    FV(const f32* v, f32 c, f32 d) { x = v[0]; f32 b = v[1]; w = d; y = b; z = c; }
    ~FV() {}
    void Scale(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
    }
    f32 Normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));

// The 25.0 at 0x375f4c.
static const f32 K = 25.0f;

/*TARGET 002e2c98*/
// Direction from a 2D point: (x, y, 0, 0) scaled by 25, normalised, w = the length before normalising.
// NOT the original source shape. Retail reads the 25.0 through its full address (lui/addiu, lwc1 0(reg))
// and after the four stores. A plain literal is loaded before the stores. Here the constant is read
// through a pointer that an empty asm makes opaque, so the read cannot pass the stores; the row is built
// with -fno-schedule-insns.
FV func_002e2c98(void*, const f32* v) asm("func_002e2c98");
FV func_002e2c98(void*, const f32* v) {
    FV r(v, 0.0f, 0.0f);
    const f32* p = &K;
    asm("" : "+r"(p));
    r.Scale(*p);
    r.w = r.Normalize();
    return r;
}
}  // namespace n002e2c98
