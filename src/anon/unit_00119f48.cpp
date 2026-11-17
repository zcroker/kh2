#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fmatrix.hpp"

// ---- 00119f48 from src/anon/batch_w222.cpp
namespace n00119f48 {
int func_00112c48(u32) asm("func_00112c48");
float func_00112c28(void) asm("func_00112c28");
float func_00112c38(void) asm("func_00112c38");
int func_00119f48(u32 a) asm("func_00119f48");
int func_00119f48(u32 a) {
    int r = func_00112c48(a);
    a &= 0x200;
    if (r >= 0) {
        if (a == 0) {
            float t = func_00112c28() + 8.0f;
            float u = func_00112c38();
            if (u <= t) return 1;
        }
    }
    return 0;
}
}  // namespace n00119f48

// ---- 00119fb8 gap: returns 1
namespace n00119fb8 {
u32 func_00119fb8(void) asm("func_00119fb8");
u32 func_00119fb8(void) { return 1; }
}  // namespace n00119fb8

// ---- 00119fc0 from src/anon/batch_w1648.cpp
namespace n00119fc0 {
void func_00190128(void*) asm("func_00190128");
struct W1648QW { f32 x, y, z, w; W1648QW() {} } __attribute__((aligned(16)));
struct W1648Tgt {
    s32 a, b, c, d, e;
    W1648Tgt() { func_00190128(this); func_00190128(this); }
};
struct W1648Hit { s32 p0; f32 r; s32 p8; s32 z; W1648QW v; W1648Hit() { z = 0; } };
struct W1648Kind { s32 p0, p4; u32 flags; };
struct W1648Obj { u8 p0[12]; W1648Kind* kind; u8 p1[268 - 16]; u32 f10c; u8 p2[0xae4 - 0x110]; s32 ae4; };
struct W1648Act { u8 pad[0xb7c]; u32 b7c; };
extern s32 D_00341708 asm("D_00341708");
s32 W1648_is_exist(W1648Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
s32 W1648_can_attack(W1648Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
s32 func_00190730(W1648Tgt*, s32) asm("func_00190730");
s32 func_00112d90(W1648Tgt*) asm("func_00112d90");
void func_0018a818(W1648Hit*, W1648Obj*, s32) asm("func_0018a818");
W1648QW* func_0016c028(W1648Act*) asm("func_0016c028");
s32 func_00119f48(u32) asm("func_00119f48");
void func_0010da40(W1648Act*, W1648Tgt*, W1648Tgt*) asm("func_0010da40");
static inline bool W1648_valid(W1648Tgt* t) { return W1648_is_exist(t) && t->a != 0; }
void func_00119fc0(W1648Act* self, W1648Tgt* src, W1648Tgt* out) asm("func_00119fc0");
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
}  // namespace n00119fc0

