#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../harata/libdk/sprite.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../tozawa/help_gra.hpp"
#include "../harata/libdk/obj2d.hpp"

// ---- 001391c8 from src/harata/libdk/obj2d.cpp
namespace n001391c8 {
}  // namespace n001391c8
namespace dk {
void Obj2D::create(s32 link_value, s32 state_value) { using namespace ::n001391c8;
    *reinterpret_cast<s32*>(reinterpret_cast<char*>(this) + 0x10) = state_value;
    *reinterpret_cast<s32*>(reinterpret_cast<char*>(this) + 0x0c) = 0;
    link(link_value);
}
}  // namespace dk

// ---- 001391e8 gap: empty function
namespace n001391e8 {
void func_001391e8(u8*) asm("func_001391e8");
void func_001391e8(u8*) {}
}  // namespace n001391e8

// ---- 001391f0 from src/anon/tiny.cpp
namespace n001391f0 {
void func_001391f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001391f0jjjj");
void func_001391f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n001391f0

// ---- 001391f8 from src/anon/batch_w1664.cpp
namespace n001391f8 {
void func_001391f8(void) asm("func_001391f8");
void func_001391f8(void) {}
}  // namespace n001391f8

// ---- 00139200 from src/anon/auto80_199_queue.cpp
namespace n00139200 {
void func_00139200(u32 a0) asm("_Z13func_00139200j");
void func_00139200(u32 a0) {
    u32 s0 = *(u32*)(a0 + 8);
    u32 s1 = *(u32*)(a0 + 4);

    *(u32*)(s1 + 96) = s0;
    if ((*(u32*)(s0 + 12) & 0x20) == 0) {
        ((void (*)(u32))(*(u32*)(*(u32*)s0 + 4)))(s0);
    }

    *(u32*)(s1 + 96) = 0;
    u32 p = s1 + 12;
    u32 n = *(u32*)(p + 4);

    if (n == 0) {
        *(u32*)(p + 4) = s0;
        *(u32*)(s1 + 12) = s0;
        *(u32*)(s0 + 8) = 0;
        return;
    }

    *(u32*)(n + 8) = s0;
    *(u32*)(s0 + 8) = 0;
    *(u32*)(p + 4) = s0;
}
}  // namespace n00139200

// ---- 00139280 from src/harata/libdk/obj2d.cpp
namespace n00139280 {
extern u32 D_00347f80 asm("D_00347f80");
extern "C" u32 TASK_MANAGER_create_task_raw(u32, u32, u32, u32)
    asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
extern u8 dk_Obj2D_ExecTask asm("_ZN2dk5Obj2D8ExecTaskEP4TASK");
}  // namespace n00139280
namespace dk {
void Obj2D::link(s32 v) { using namespace ::n00139280; using ::n00139280::D_00347f80; using ::n00139280::dk_Obj2D_ExecTask;
    u32 s1 = reinterpret_cast<u32>(this);
    u32 v0 = TASK_MANAGER_create_task_raw(*(u32*)D_00347f80, 0, (u32)v, (u32)&dk_Obj2D_ExecTask);
    u32 t = D_00347f80;

    *(u32*)(v0 + 8) = s1;
    *(u32*)(v0 + 4) = t;
    *(u32*)(s1 + 20) = v0;

    u32 head = D_00347f80;
    u32 p = head + 4;
    u32 n = *(u32*)(p + 4);

    if (n == 0) {
        *(u32*)(p + 4) = s1;
        *(u32*)(head + 4) = s1;
        *(u32*)(s1 + 4) = 0;
        return;
    }

    *(u32*)(n + 4) = s1;
    *(u32*)(s1 + 4) = 0;
    *(u32*)(p + 4) = s1;
}
}  // namespace dk

// ---- 00139308 gap: task callback, calls slot 2 of every drawable list node
namespace n00139308 {
struct N139 { void (**vt)(N139*); u32 p4; N139* next; u32 flags; };
struct M139 { u32 p0, p4, p8; N139* first; N139* last; u8 pad[76]; u32 cur; };
static inline N139* Next139(M139* m, N139* n) { return !n ? m->first : n->next; }
void func_00139308(u8* t) asm("func_00139308");
void func_00139308(u8* t) {
    M139* m = *(M139**)(t + 4);
    N139* n = 0;
    m->cur = 0;
    while ((n = Next139(m, n))) {
        m->cur = (u32)n;
        u32 f = n->flags;
        if (f & 2) continue;
        if (f & 0x40) continue;
        n->vt[2](n);
    }
    m->last = 0;
    m->first = 0;
    m->cur = 0;
}
}  // namespace n00139308

