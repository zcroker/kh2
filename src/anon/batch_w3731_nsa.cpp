// 002cbf70: empty asms keep the a2 copy to s5 after the barrier (first beqz delay slot) and keep sd s5 early.
// w2475 near-miss (build with -fno-strict-aliasing, _nsa): only the prologue differs (sched2 puts sd s2/sd s5/move s5 before swc1 f22/mov.s f22; original copies f12->f22 first and move s5,a2 sits in the first beqz delay slot). Body 0 real diffs. ce598 declared f32-returning fixed an f0/f1 choice.
#include "../common/types.h"
extern "C" {
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V2cbf70 {
    f32 x, y, z, w;
    V2cbf70() {}
    V2cbf70(const V2cbf70& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2cbf70& operator=(const V2cbf70& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2cbf70 operator-(const V2cbf70& b) const
    {
        V2cbf70 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
                     : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));

// curve path walker
struct Path2cbf70 {
    u8 pad0[4];
    s32 first;
    s32 n;
    u8 pad12[4];
    u8 loop;
    u8 pad17[7];
    f32 t0;
    f32 t;
    u8 pad32[8];
    f32 segLen;
    u8 pad44[4];
    V2cbf70 a0, a1, b0, b1, last;
    u8 pad128[4];
    u8 fwd, stop, fixed, mode;
    u8 pad136[4];
    s32 mark;
};

s32 func_002cb918(Path2cbf70*);
s32 func_002cb920(Path2cbf70*);
V2cbf70* func_002cb890(Path2cbf70*, s32);
V2cbf70 func_002cb938(Path2cbf70*, f32);
V2cbf70 func_002cd910(Path2cbf70*, f32);
f32 func_002ce598(Path2cbf70*, V2cbf70*);
void func_002cb800(Path2cbf70*, V2cbf70*);
void func_002ce6b8(Path2cbf70*, V2cbf70*, f32);
f32 fabsf(f32);

s32 func_002cbf70(Path2cbf70* p, V2cbf70* out, V2cbf70* pos0, f32 dist);  // 0x002cbf70: definition moved into src/taito/path.cpp
}
