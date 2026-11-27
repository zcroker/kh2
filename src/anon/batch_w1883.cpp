#include "../common/types.h"
struct QV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct S20 { s32 v[5]; };
/* VU0 vector subtract (lqc2/vsub/sqc2 macro sequence). */
static inline __attribute__((always_inline)) QV vsub_w1883(const QV& p, const QV* q) {
    QV d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(&p), "r"(q) : "memory");
    return d;
}
extern "C" {
void YS__COMMAND_SLOT__set(u8*, u8*, u8*, u8*, s32);
QV func_00190388(u8*);
QV* YS__OBJ__get_pos(u8*);
void YS__RC_SEARCHER__set(u8* a0, u8* a1, u8* a2, s32 a3, s32 a4);  // 0x0019da68: definition moved into src/anon/unit_0019ba60.cpp
}
