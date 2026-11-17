#include "../common/types.h"
#include "../ryj/effect.hpp"
#include "../ryj/effect_data.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 001dd2b8 from src/anon/batch_w44.cpp
namespace n001dd2b8 {
void* func_00106a18(s32) asm("func_00106a18");
void* func_00106a60(s32) asm("func_00106a60");
void func_001dd320(void*, void*, s32) asm("func_001dd320");
extern u8 D_00352af0 asm("D_00352af0");
extern u8 D_00352af1 asm("D_00352af1");
void func_001dd2b8(void) asm("func_001dd2b8");
void func_001dd2b8(void) {
    if (D_00352af1) return;
    if (!D_00352af0) return;
    void* a = func_00106a18(0);                   
    func_001dd320(a, func_00106a60(0), 1);
}
}  // namespace n001dd2b8

// ---- 001dd320 from src/anon/batch_w2045.cpp
namespace n001dd320 {
struct W2045_M44 {
    f32 m[16];
    W2045_M44() {}
                                           
    W2045_M44& operator=(const W2045_M44& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2045_V4 { f32 v[4]; } __attribute__((aligned(16)));
struct W2045_Obj { u8 pad[8]; s32 flags; u8 pad2[16]; s32 h; u8 pad3[8]; W2045_Obj* next; };
struct W2045_Arg1 { u8 pad[16]; W2045_M44 m; };
W2045_M44* func_00106ad0(s32) asm("func_00106ad0");
void func_00107368(W2045_Arg1*, W2045_V4*) asm("func_00107368");
void func_00107478(W2045_Arg1*, W2045_V4*) asm("func_00107478");
void func_00143f78(void*, W2045_V4*) asm("func_00143f78");
void func_00146680(void*, W2045_M44*) asm("func_00146680");
void func_001b81e8(void) asm("func_001b81e8");
void func_001b8218(void) asm("func_001b8218");
s32 func_001dc738(W2045_Obj*) asm("func_001dc738");
s32 func_001dc790(W2045_Obj*) asm("func_001dc790");
s32 func_001dc9d0(W2045_Obj*) asm("func_001dc9d0");
s32 func_001dc9e0(W2045_Obj*) asm("func_001dc9e0");
void func_001dca70(W2045_Obj*) asm("func_001dca70");
void func_001dcae0(W2045_Obj*) asm("func_001dcae0");
s32 func_001dcc60(W2045_Obj*) asm("func_001dcc60");
s32 func_001dccc8(W2045_Obj*, u8) asm("func_001dccc8");
void func_001e2c70(s32, s32) asm("func_001e2c70");
void func_001e3330(s32) asm("func_001e3330");
void func_001e6250(void) asm("func_001e6250");
s32 func_001e6280(s32, s32) asm("func_001e6280");
void func_001e65c8(void) asm("func_001e65c8");
void func_001e6c00(s32) asm("func_001e6c00");
void func_001e6ed8(W2045_M44*, s32, W2045_V4*, W2045_V4*) asm("func_001e6ed8");
void func_001e7008(f32) asm("func_001e7008");
extern f32 D_00349e10 asm("D_00349e10");
extern W2045_Obj* D_00352ae0 asm("D_00352ae0");
extern u8 D_00352b00[] asm("D_00352b00");
static inline bool w2045_flag26(W2045_Obj* o) { u8 b = (o->flags >> 26) & 1; return b; }
struct W2045_V4b { f32 x, y, z, w; } __attribute__((aligned(16)));
void func_001dd320(s32 a0, W2045_Arg1* a1, u8 a2) asm("func_001dd320");
void func_001dd320(s32 a0, W2045_Arg1* a1, u8 a2) {
    W2045_V4 v0;
    W2045_V4 v1;
    W2045_M44 m;
    W2045_M44 r;
    func_00107368(a1, &v0);
    func_00107478(a1, &v1);
    func_001e6ed8(&a1->m, a0, &v0, &v1);
    m = *func_00106ad0(a0);
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
        : : "r"(&r), "r"(&m), "r"(&a1->m) : "memory");
    func_00146680(D_00352b00, &r);
    if (a2) func_00143f78(D_00352b00, &v0);
    func_001e7008(D_00349e10);
    func_001b81e8();
    func_001e6250();
    W2045_Obj* next;
    for (W2045_Obj* o = D_00352ae0; o; o = next) {
        next = o->next;
        if (func_001dc9d0(o) && !w2045_flag26(o) && func_001dcc60(o)) {
            if (o->h) {
                func_001e2c70(o->h, func_001dc790(o));
                func_001dca70(o);
                func_001e3330(o->h);
                if (!func_001e6280(o->h, func_001dccc8(o, a2))) {
                    func_001e6c00(o->h);
                    o->h = 0;
                    o->flags |= 0x10000;
                }
            }
            if (func_001dc9e0(o) && !func_001dc738(o)) func_001dcae0(o);
        }
    }
    func_001e65c8();
    func_001b8218();
}
}  // namespace n001dd320

// ---- 001dd568 from src/anon/batch_w96.cpp
namespace n001dd568 {
union FU_w96 { f32 f; u32 u; };
void func_001dd568(u32* ids, FU_w96* keys, s32 lo, s32 hi) asm("func_001dd568");
void func_001dd568(u32* ids, FU_w96* keys, s32 lo, s32 hi) {
    s32 i = lo;
    s32 j = hi;
    f32 pivot = keys[(lo + hi) / 2].f;
    for (;;) {
        while (pivot < keys[i].f) i++;
        while (keys[j].f < pivot) j--;
        if (i >= j) break;
        {
            f32 t = keys[i].f;
            u32 u;
            keys[i].f = keys[j].f;
            keys[j].f = t;
            u = ids[i];
            ids[i] = ids[j];
            ids[j] = u;
        }
        i++;
        j--;
    }
    if (lo < i - 1) func_001dd568(ids, keys, lo, i - 1);
    if (j + 1 < hi) func_001dd568(ids, keys, j + 1, hi);
}
}  // namespace n001dd568

