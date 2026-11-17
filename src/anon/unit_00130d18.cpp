// Linked unit 0x00130d18-0x00130ea0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00130d18 (was unwritten gap)
namespace n00130d18 {
struct C { u8 pad[20]; u32 v; };
struct O { u32 x0; C* c; };
u32 func_00130d18(O* o) asm("func_00130d18");
u32 func_00130d18(O* o) { return o->c->v; }
}  // namespace

// 00130d28 (was src/anon/batch_w277.cpp)
namespace n00130d28 {
struct Mtx { f32 m[4][4]; } __attribute__((aligned(16)));
static inline void CopyMtx(Mtx* d, const Mtx* s)
{
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void ScaleRow(f32* r, f32 s)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(r), "f"(s) : "$8", "memory");
}
struct Cam { s32 x0; s32 type; u8 pad[136]; f32 a; f32 b4; f32 c; };
struct Obj { s32 x0; Cam* cam; };
struct Arg { u8 pad[24]; Obj* owner; };
union UF { f32 f; u8 c; };
extern UF D_00347b70 asm("D_00347b70");
void func_00127cf8(void*) asm("func_00127cf8");
void func_00128480(Obj*, Arg*) asm("func_00128480");
void func_00128b38(Obj*, Arg*, f32) asm("func_00128b38");
void func_00130c18(Obj*, f32) asm("func_00130c18");
void func_0012d728(Obj*, Arg*, Mtx*, void*, void*) asm("func_0012d728");
void func_00129c38(Obj*, Arg*, Mtx*, void*, void*) asm("func_00129c38");
/*TARGET 00130d28*/
void func_00130d28(Obj* o, Arg* a, const Mtx* mtx, void* p3, void* p4, f32 t) asm("func_00130d28");
void func_00130d28(Obj* o, Arg* a, const Mtx* mtx, void* p3, void* p4, f32 t) {
    func_00127cf8(p4);
    t += o->cam->a * 60.0f / o->cam->c;
    D_00347b70.f = o->cam->a + t * o->cam->c / 60.0f;
    if (a->owner != o) func_00128480(o, a);
    func_00128b38(o, a, t);
    func_00130c18(o, t);
    Mtx m;
    f32* r1 = m.m[1];
    f32* r2 = m.m[2];
    CopyMtx(&m, mtx);
    ScaleRow(r1, -1.0f);
    ScaleRow(r2, -1.0f);
    if (o->cam->type == 1) func_0012d728(o, a, &m, p3, p4);
    else func_00129c38(o, a, &m, p3, p4);
}
}  // namespace n00130d28

