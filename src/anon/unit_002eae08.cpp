#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

// 128-bit vector with an asm self-checked assignment (non-POD: returned via hidden pointer)
struct Vec128 {
    u128 q;
    Vec128() {}
    Vec128(const Vec128& o) : q(o.q) {}
    Vec128& operator=(const Vec128& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};

static inline f32 angle_pi_over_8() { return 0.392699063f; }

// Seven parameters at 0x3634e8-0x363503. D_003634f0 is set by this file's static initialiser
// (0x2eaee8, called by _GLOBAL__I_D_003634e8 at 0x2eaf18, a .ctors entry).
extern "C" {
f32 D_003634e8 = 4.0f;
f32 D_003634ec = 4.0f;
f32 D_003634f0 = angle_pi_over_8();
f32 D_003634f4 = 0.95f;
f32 D_003634f8 = 0.01f;
f32 D_003634fc = 100.0f;
f32 D_00363500 = 3.0f;

Vec128 func_00184540(u32, f32, f32);
Vec128 func_002ede48(u32, Vec128*, f32, f32);

/* ---- 002ead98 (gap): action method, sets flag 0x1000, clears the velocity, loads the default params ---- */
void func_002ead98(u32, u8* o) {
    *(u32*)(o + 2748) |= 0x1000;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(o + 32) : "memory");
    *(f32*)(o + 272) = D_003634e8;
    *(f32*)(o + 276) = D_003634ec;
    *(f32*)(o + 284) = D_003634f0;
}

/* ---- 002eadd8 (gap): action method, clears flag 0x1000, loads params from the table at +300 ---- */
void func_002eadd8(u32, u8* o) {
    union UF { u32 u; };
    ((UF*)(o + 2748))->u &= ~0x1000;
    f32* t = *(f32**)(o + 300);
    *(f32*)(o + 272) = t[0];
    *(f32*)(o + 276) = t[1];
    *(f32*)(o + 284) = t[3];
}

/* ---- 002eae08 ---- */
Vec128* func_002eae08(Vec128* out, u32 a1, u32 a2) {
    *out = func_00184540(a2, D_003634f4, 1.0f - D_003634f8);
    *out = func_002ede48(a2, out, D_003634fc, D_00363500);
    return out;
}

/* ---- 002eaea8 ---- */
void func_002eaea8(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    D_003634e8 = a; D_003634ec = b; D_003634f0 = c; D_003634f4 = d;
    D_003634f8 = e; D_003634fc = f; D_00363500 = g;
}
}
