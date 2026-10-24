#include "../common/types.h"

// 128-bit block copied with lq/sq (EE quadword move).
struct Q_w2372 {
    u32 w[4];
    Q_w2372& operator=(const Q_w2372& o) {
        asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Rec96_w2372 { u16 h0, h1, h2, h3; f32 f0, f1; };
struct Rec120_w2372 { u32 a, b; f32 c; };
struct Rec_w2372 {
    Q_w2372 q0, q1, q2, q3, q4, q5;
    Rec96_w2372 r96;
    u32 x, y;
    Rec120_w2372 r120;
};

// The tail groups are addressed through casts (each group its own type, no shared
// struct), which keeps the original's group-by-group order under -fno-strict-aliasing.
#define R96(p) ((Rec96_w2372*)((u8*)(p) + 96))
#define R120(p) ((Rec120_w2372*)((u8*)(p) + 120))

extern "C" {
// Copies one 132-byte record: six quadwords, then the scalar tail group by group.
void func_00319e90(Rec_w2372* d, Rec_w2372* s) {
    d->q0 = s->q0; d->q1 = s->q1; d->q2 = s->q2; d->q3 = s->q3; d->q4 = s->q4; d->q5 = s->q5;
    {
        u16 h0 = R96(s)->h0, h1 = R96(s)->h1, h2 = R96(s)->h2, h3 = R96(s)->h3;
        f32 f0 = R96(s)->f0, f1 = R96(s)->f1;
        R96(d)->f0 = f0; R96(d)->h0 = h0; R96(d)->h1 = h1; R96(d)->h2 = h2; R96(d)->h3 = h3; R96(d)->f1 = f1;
    }
    *(u32*)((u8*)d + 112) = *(u32*)((u8*)s + 112);
    *(u32*)((u8*)d + 116) = *(u32*)((u8*)s + 116);
    R120(d)->a = R120(s)->a; R120(d)->b = R120(s)->b; R120(d)->c = R120(s)->c;
}
}
