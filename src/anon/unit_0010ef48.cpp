// Linked unit 0x0010ef48-0x0010f098 (one namespace per old matched source; class methods in their own namespace).
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

// 0010ef48 (was src/anon/batch_w3726_gnsa_nogcse.cpp)
namespace n0010ef48 {
struct C1882 { void* vt; };
struct E1882 { u32 flags; u32 ptr; s32 delta; u8 pad[24]; };
typedef s32 (*Fn1882)(C1882*, E1882*, void*, void*, s32);
struct L1882 { u8 b[32]; };
struct M1882 { u8 b[16]; };
struct S1882 { u8 pad[2912]; C1882* obj; u8 pad2[24]; u32 f2940; };
s32 func_001137e0(C1882*) asm("func_001137e0");
E1882* func_001137e8(C1882*) asm("func_001137e8");
void func_00190128(L1882*) asm("func_00190128");
E1882* func_0010fea0(S1882*) asm("func_0010fea0");
/*TARGET 0010ef48*/
s32 func_0010ef48(S1882* self) asm("func_0010ef48");
s32 func_0010ef48(S1882* self) {
    s32 i = 0;
    s32 r = 0;
    s32 n = func_001137e0(self->obj);
    E1882* e = func_001137e8(self->obj);
    L1882 l;
    M1882 m;
    func_00190128(&l);
    s32 f = self->f2940;
    self->f2940 = f & ~4;
    s32 had = (f >> 2) & 1;
    E1882* skip = func_0010fea0(self);
    for (; i < n; i++, e++) {
        u32 ptr = e->ptr;
        if (!ptr) continue;
        if (!(e->flags & 2)) continue;
        if (skip == e) continue;
        C1882* o = self->obj;
        s32 d = e->delta;
        Fn1882 f;
        if ((bool)(d & 1)) { u32 idx = ptr >> 2 << 2; s32 adj = d >> 1; asm("" : "+r"(adj) : "r"(idx)); u8* ao = (u8*)o + adj; f = *(Fn1882*)(idx + *(u32*)ao); }
        else f = (Fn1882)ptr;
        if (f((C1882*)((u8*)o + (e->delta >> 1)), e, &l, &m, 1)) { r = 1; break; }
    }
    if (had) self->f2940 |= 4;
    return r;
}
}  // namespace n0010ef48

