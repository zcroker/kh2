#include "../common/types.h"
// w1648: target picking near 0x119fc0 (YS::TARGET search loops).
extern "C" void func_00190128(void*);
struct W1648QW { f32 x, y, z, w; W1648QW() {} } __attribute__((aligned(16)));
// YS::TARGET (5 words); the constructor runs the init routine twice.
struct W1648Tgt {
    s32 a, b, c, d, e;
    W1648Tgt() { func_00190128(this); func_00190128(this); }
};
// Hit sphere filled by func_0018a818: radius at +4, centre at +16.
struct W1648Hit { s32 p0; f32 r; s32 p8; s32 z; W1648QW v; W1648Hit() { z = 0; } };
struct W1648Kind { s32 p0, p4; u32 flags; };
struct W1648Obj { u8 p0[12]; W1648Kind* kind; u8 p1[268 - 16]; u32 f10c; u8 p2[0xae4 - 0x110]; s32 ae4; };
struct W1648Act { u8 pad[0xb7c]; u32 b7c; };
extern "C" {
extern s32 D_00341708;
s32 W1648_is_exist(W1648Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
s32 W1648_can_attack(W1648Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
s32 func_00190730(W1648Tgt*, s32);
s32 func_00112d90(W1648Tgt*);
void func_0018a818(W1648Hit*, W1648Obj*, s32);
W1648QW* func_0016c028(W1648Act*);
s32 func_00119f48(u32);
void func_0010da40(W1648Act*, W1648Tgt*, W1648Tgt*);
static inline bool W1648_valid(W1648Tgt* t) { return W1648_is_exist(t) && t->a != 0; }
// Pick the nearest attackable target (distance to its hit sphere surface); fall back to
// func_0010da40, then to *src. Writes the result to *out when it is valid.
void func_00119fc0(W1648Act* self, W1648Tgt* src, W1648Tgt* out) {
    W1648Tgt cur;
    W1648Hit hit;
    W1648Tgt it;
    W1648QW d;
    f32 best = 0.0f;
    s32 k = 0;
    while ((k = func_00190730(&it, k)) != 0) {
        if (!func_00112d90(&it)) continue;
        if (!W1648_can_attack(&it)) continue;
        W1648Obj* o = (W1648Obj*)it.a;
        if (o->kind == 0) continue;
        if (!(o->kind->flags & 0x40)) continue;
        if (!(o->f10c & 0x20000)) continue;
        if (o->ae4 != D_00341708) continue;
        func_0018a818(&hit, o, k);
        W1648QW* p = func_0016c028(self);
        f32 len;
        // VU0 macro code: d = hit.v - *p; len = |d.xyz|
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(&hit.v), "r"(p), "r"(&d) : "memory");
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        len = len - hit.r;
        if (best == 0.0f || len < best) { best = len; cur = it; }
    }
    if (!W1648_valid(&cur)) {
        if (func_00119f48(self->b7c)) func_0010da40(self, src, &cur);
    }
    if (!W1648_valid(&cur)) cur = *src;
    if (W1648_valid(&cur)) *out = cur;
}
}
