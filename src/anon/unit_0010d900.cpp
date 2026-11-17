// Linked unit 0x0010d900-0x0010dc08 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include <stdarg.h>
#include "../naka/libkn/friend.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../../src/common/types.h"
extern "C" float fabsf(float);
#include "tiny_auto80_solver_structs.hpp"

// 0010d900 (was src/anon/tiny.cpp)
namespace n0010d900 {
void func_0010d2b8(void*) asm("_Z13func_0010d2b8Pv");
/*TARGET 0010d900*/
void func_0010d900(BD_VALUE* bd) asm("_Z13func_0010d900P8BD_VALUE");
void func_0010d900(BD_VALUE* bd) { func_0010d2b8(bd); }
}  // namespace n0010d900

// 0010d918 (was src/anon/batch_w3680.cpp)
namespace n0010d918 {
void func_00190128(void*) asm("func_00190128");
struct QW { f32 x, y, z, w; QW() {} } __attribute__((aligned(16)));
struct Tgt {
    s32 a, b, c, d, e;
    Tgt() { func_00190128(this); }
};
struct Hit { s32 p0; f32 r; s32 p8; s32 z; QW v; Hit() { z = 0; } };
extern u32 D_00341788[8] asm("D_00341788");
extern s32 D_003417a8 asm("D_003417a8");
void func_00190878(Tgt*, u32, s32) asm("func_00190878");
s32 func_00190730(Tgt*, s32) asm("func_00190730");
s32 func_001901c0(Tgt*) asm("func_001901c0");
s32 func_00112d28(u32, s32) asm("func_00112d28");
/*TARGET 0010d918*/
void func_0010d918(s32 a0, s32 a1, Tgt* out) asm("func_0010d918");
void func_0010d918(s32 a0, s32 a1, Tgt* out) {
    s32 i;
    for (i = D_003417a8 - 1; i >= 0; i--) {
        Hit hit;
        u32 id = D_00341788[i];
        Tgt it;
        func_00190878(&it, id, 0);
        s32 k = 0;
        while ((k = func_00190730(&it, k)) != 0) {
            if (it.a != D_00341788[i]) break;
            if (!func_001901c0(&it)) continue;
            {
                // The empty asm (copy of k, memory clobber) keeps sched1 from
                // hoisting the a1 argument above the previous test, so reorg
                // fills that branch's delay slot from its target like the original.
                s32 kk = k;
                asm("" : "+r"(kk) : : "memory");
                if (!func_00112d28(D_00341788[i], kk)) continue;
            }
            *out = it;
            break;
        }
    }
}
}  // namespace n0010d918

// 0010da40 (was src/anon/batch_w2393_nsa.cpp)
namespace n0010da40 {
/* batch w2393: built with -fno-strict-aliasing (_nsa). */

struct Vec10da40 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Hnd10da40 { s32 id; s32 a; s32 b; s32 c; s32 d; };
struct Info10da40 { s32 p0; f32 r; s32 p8; s32 pc; Vec10da40 pos; Info10da40() { pc = 0; } };
s32 func_00190140(Hnd10da40*) asm("_ZNK2YS6TARGET8is_existEv");
void func_00190128(Hnd10da40*) asm("func_00190128");
void func_00190878(Hnd10da40*, s32, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 func_00190730(Hnd10da40*, s32) asm("func_00190730");
void func_0018a818(Info10da40*, s32, s32) asm("func_0018a818");
void* func_0016c028(void*) asm("func_0016c028");
extern Hnd10da40 D_003417b0 asm("D_003417b0");
extern s32 D_003417c4 asm("D_003417c4");
static inline void vsub10da40(const Vec10da40* a, const Vec10da40* b, Vec10da40* r) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(r) : "memory");
}
static inline f32 vlen10da40(const Vec10da40* a) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(a) : "$8", "memory");
    return len;
}
static inline bool valid10da40(Hnd10da40* h) { return func_00190140(h) && h->id != 0; }
/*TARGET 0010da40*/
void func_0010da40(void* self, s32 unused, Hnd10da40* out) asm("func_0010da40");
void func_0010da40(void* self, s32 unused, Hnd10da40* out) {
    if (D_003417c4 == 0) return;
    if (valid10da40(&D_003417b0) && D_003417b0.id == D_003417c4) {
        *out = D_003417b0;
        return;
    }
    Info10da40 info;
    f32 best = 0.0f;
    s32 key = D_003417c4;
    Hnd10da40 it;
    func_00190128(&it);
    s32 cur = 0;
    func_00190878(&it, key, 0);
    while ((cur = func_00190730(&it, cur)) != 0 && it.id == D_003417c4) {
        func_0018a818(&info, it.id, cur);
        Vec10da40* p = (Vec10da40*)func_0016c028(self);
        Vec10da40 d;
        vsub10da40(&info.pos, p, &d);
        f32 dist = vlen10da40(&d) - info.r;
        if (best == 0.0f || dist < best) {
            best = dist;
            *out = it;
        }
    }
}
}  // namespace n0010da40

