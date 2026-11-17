// Linked unit 0x195c80-0x195d00: one function from an old _gnsa file. It needs -g
// (empty call delay slots), which breaks other functions of the neighbouring units.
// Flags: -G0 -g -fno-strict-aliasing.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/menu_sound.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 00195c80 from src/anon/sweep_00195c80_gnsa.cpp
namespace n00195c80 {
struct W1530_V4 {
    f32 x, y, z, w;
    W1530_V4() {}
    W1530_V4& operator=(const W1530_V4& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
struct W1530_H;
struct W1530_HC { virtual void f0(); virtual void f1(); virtual void f2(W1530_H*, W1530_V4*); };
struct W1530_H { u8 pad[0xc]; W1530_HC* xc; u8 pad2[0x860 - 0x10]; W1530_V4 v; };
void func_00195c80(W1530_H* p) asm("func_00195c80");
void func_00195c80(W1530_H* p) {
    W1530_V4 v;
    f32 len;
    v = p->v;
    asm volatile("lqc2 $vf1,0(%1)\n\t"
        "vmul.xyz $vf2,$vf1,$vf1\n\t"
        "vaddy.x $vf2,$vf2,$vf2y\n\t"
        "vaddz.x $vf2,$vf2,$vf2z\n\t"
        "vsqrt Q,$vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8,$vi22\n\t"
        "vaddq.x $vf2,$vf0,Q\n\t"
        "mtc1 $8,%0\n\t"
        "vnop\n\t"
        "vdiv Q,$vf0w,$vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1,$vf1,Q\n\t"
        "sqc2 $vf1,0(%1)"
        : "=f"(len) : "r"(&v) : "$8", "memory");
    v.w = len;
    W1530_H* q = p;
    v.y = 0;
    q->xc->f2(q, &v);
}
}  // namespace n00195c80

