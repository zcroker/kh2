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


// ---- 00139390 (gap: task callback; was unwritten)
namespace n00139390 {
struct M { u32 f0, f4, f8, f12, f16; };
struct TASK { u32 x0; M* owner; };
extern M* D_00347f80 asm("D_00347f80");
void func_00139c90(void) asm("func_00139c90");
void func_001029e8(u32) asm("func_001029e8");
void func_00139390(TASK* t) asm("func_00139390");
void func_00139390(TASK* t) {
    M* m = t->owner;
    D_00347f80 = m;
    func_00139c90();
    m->f16 = 0;
    m->f12 = 0;
    func_001029e8(m->f0);
}
}  // namespace n00139390

// ---- 001393c8 from src/anon/tiny.cpp
namespace n001393c8 {
void func_00139dc0(s32) asm("_Z13func_00139dc0i");
void func_001393c8(BD_VALUE* bd) asm("_Z13func_001393c8P8BD_VALUE");
void func_001393c8(BD_VALUE* bd) { func_00139dc0(0); }
}  // namespace n001393c8

// ---- 001393e0 from src/anon/tiny.cpp
namespace n001393e0 {
void func_00139dc0(s32) asm("_Z13func_00139dc0i");
void func_001393e0(BD_VALUE* bd) asm("_Z13func_001393e0P8BD_VALUE");
void func_001393e0(BD_VALUE* bd) { func_00139dc0(1); }
}  // namespace n001393e0

// ---- 001393f8 from src/anon/batch_w2374.cpp
namespace n001393f8 {
struct W2374Link { void* vt; W2374Link* next; };
struct W2374Obj;
typedef void (*W2374Fn)(W2374Obj*);
struct W2374Obj { W2374Fn* vt; W2374Obj* next; s32 pad8; u32 flags; s32 pad10; s32 id; };
struct W2374List {
    W2374Link* head;
    W2374Link* tail;
    __attribute__((always_inline)) void Remove(W2374Link* n) {
        W2374Link* prev;
        if (n == head) {
            head = n->next;
            prev = 0;
        } else {
            prev = head;
            while (prev->next != n) prev = prev->next;
            prev->next = n->next;
        }
        if (n == tail) tail = prev;
        n->next = 0;
    }
};
struct W2374Owner { W2374Link* h; W2374List list; };
void func_00102670(W2374Link*, s32) asm("func_00102670");
void func_001393f8(int a) asm("_Z13func_001393f8i");
void func_001393f8(int a)
{
    W2374Owner* o = (W2374Owner*)a;
    W2374Obj* n = (W2374Obj*)o->list.head;
    while (n) {
        W2374Obj* next = n->next;
        s32 m = n->flags & 1;
        if (m) {
            o->list.Remove((W2374Link*)n);
            func_00102670(o->h, n->id);
            (*n->vt[0])(n);
        }
        n = next;
    }
}
}  // namespace n001393f8

// ---- 001394c0 from src/anon/tiny.cpp
namespace n001394c0 {
void func_001393f8(s32) asm("_Z13func_001393f8i");
void func_001394c0(BD_VALUE* bd) asm("_Z13func_001394c0P8BD_VALUE");
void func_001394c0(BD_VALUE* bd) { func_001393f8(bd[1].i); }
}  // namespace n001394c0

// ---- 001394d8 from src/anon/batch_w15.cpp
namespace n001394d8 {
int obj_is_exist_00139768(void*) asm("_Z13func_00139768jjjjjjjj");
void func_001394c0(void*) asm("func_001394c0");
void func_00102750(u32) asm("func_00102750");
extern u32* D_00347f80 asm("D_00347f80");
void func_001394d8(void* p) asm("func_001394d8");
void func_001394d8(void* p) {
    obj_is_exist_00139768(p);
    func_001394c0(p);
    func_00102750(*D_00347f80);
}
}  // namespace n001394d8

// ---- 00139510 from src/harata/libdk/obj2d.cpp
namespace n00139510 {
}  // namespace n00139510
namespace dk {
void Obj2D::leave() { using namespace ::n00139510;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x0001u;
}
}  // namespace dk

// ---- 00139520 from src/harata/libdk/obj2d.cpp
namespace n00139520 {
}  // namespace n00139520
namespace dk {
void Obj2D::resetLeave() { using namespace ::n00139520;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v & static_cast<u32>(-2);
}
}  // namespace dk

// ---- 00139538 from src/harata/libdk/obj2d.cpp
namespace n00139538 {
}  // namespace n00139538
namespace dk {
u32 Obj2D::isLeave() { using namespace ::n00139538;
    u32 v = *(u32*)((u32)this + 12);
    return v & 0x1u;
}
}  // namespace dk

// ---- 00139548 from src/harata/libdk/obj2d.cpp
namespace n00139548 {
}  // namespace n00139548
namespace dk {
void Obj2D::setNoKick() { using namespace ::n00139548;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x1000u;
}
}  // namespace dk

// ---- 00139558 gap: Obj2D flag helper
namespace n00139558 {
void func_00139558(u8*) asm("func_00139558");
void func_00139558(u8* p) { *(u32*)(p + 12) &= ~0x1000; }
}  // namespace n00139558

// ---- 00139570 from src/harata/libdk/obj2d.cpp
namespace n00139570 {
}  // namespace n00139570
namespace dk {
void Obj2D::hide() { using namespace ::n00139570;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x0002u;
}
}  // namespace dk

// ---- 00139580 from src/harata/libdk/obj2d.cpp
namespace n00139580 {
}  // namespace n00139580
namespace dk {
void Obj2D::show() { using namespace ::n00139580;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v & static_cast<u32>(-3);
}
}  // namespace dk

// ---- 00139598 from src/harata/libdk/obj2d.cpp
namespace n00139598 {
}  // namespace n00139598
namespace dk {
void Obj2D::localHide() { using namespace ::n00139598;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x0040u;
}
}  // namespace dk

// ---- 001395a8 from src/harata/libdk/obj2d.cpp
namespace n001395a8 {
}  // namespace n001395a8
namespace dk {
void Obj2D::localShow() { using namespace ::n001395a8;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v & static_cast<u32>(-65);
}
}  // namespace dk

// ---- 001395c0 gap: Obj2D flag test
namespace n001395c0 {
u32 func_001395c0(u8*) asm("func_001395c0");
u32 func_001395c0(u8* p) { u32 m = *(u32*)(p + 12) & 0x40; return m != 0; }
}  // namespace n001395c0

// ---- 001395d0 from src/harata/libdk/obj2d.cpp
namespace n001395d0 {
}  // namespace n001395d0
namespace dk {
void Obj2D::getSeqColorOff() { using namespace ::n001395d0;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v & static_cast<u32>(-5);
}
}  // namespace dk

// ---- 001395e8 from src/harata/libdk/obj2d.cpp
namespace n001395e8 {
}  // namespace n001395e8
namespace dk {
void Obj2D::getSeqColorOn() { using namespace ::n001395e8;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x0004u;
}
}  // namespace dk

// ---- 001395f8 from src/harata/libdk/obj2d.cpp
namespace n001395f8 {
}  // namespace n001395f8
namespace dk {
void Obj2D::resetSeqAlphaOnly() { using namespace ::n001395f8;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v & static_cast<u32>(-9);
}
}  // namespace dk

// ---- 00139610 from src/harata/libdk/obj2d.cpp
namespace n00139610 {
}  // namespace n00139610
namespace dk {
void Obj2D::getSeqAlphaOnly() { using namespace ::n00139610;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x0008u;
}
}  // namespace dk

// ---- 00139620 from src/harata/libdk/obj2d.cpp
namespace n00139620 {
}  // namespace n00139620
namespace dk {
void Obj2D::getSeqPraramXYOff() { using namespace ::n00139620;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v & static_cast<u32>(-17);
}
}  // namespace dk

// ---- 00139638 from src/harata/libdk/obj2d.cpp
namespace n00139638 {
}  // namespace n00139638
namespace dk {
void Obj2D::getSeqPraramXYOn() { using namespace ::n00139638;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x0010u;
}
}  // namespace dk

// ---- 00139648 from src/harata/libdk/obj2d.cpp
namespace n00139648 {
}  // namespace n00139648
namespace dk {
void Obj2D::getParentSeqColorOff() { using namespace ::n00139648;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v & static_cast<u32>(-513);
}
}  // namespace dk

// ---- 00139660 from src/harata/libdk/obj2d.cpp
namespace n00139660 {
}  // namespace n00139660
namespace dk {
void Obj2D::getParentSeqColorOn() { using namespace ::n00139660;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x0200u;
}
}  // namespace dk

// ---- 00139670 gap: Obj2D flag helper
namespace n00139670 {
void func_00139670(u8*) asm("func_00139670");
void func_00139670(u8* p) { *(u32*)(p + 12) &= ~0x400; }
}  // namespace n00139670

// ---- 00139688 from src/harata/libdk/obj2d.cpp
namespace n00139688 {
}  // namespace n00139688
namespace dk {
void Obj2D::getParentSeqAlphaOnly() { using namespace ::n00139688;
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x0400u;
}
}  // namespace dk

// ---- 00139698 gap: Obj2D flag helper
namespace n00139698 {
void func_00139698(u8*) asm("func_00139698");
void func_00139698(u8* p) { *(u32*)(p + 12) &= ~0x800; }
}  // namespace n00139698

// ---- 001396b0 from src/anon/tiny.cpp
namespace n001396b0 {
void func_001396b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001396b0jjjj");
void func_001396b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t = *(u32*)((u32)a0 + (12));
    t |= 0x0800u;
    *(u32*)((u32)a0 + (12)) = t;
}
}  // namespace n001396b0

// ---- 001396c0 from src/harata/libdk/obj2d.cpp
namespace n001396c0 {
}  // namespace n001396c0
namespace dk {
u32 Obj2D::isHide() { using namespace ::n001396c0;
    u32 v = *(u32*)((u32)this + 12);
    v &= 0x0002u;
    return (v != 0);
}
}  // namespace dk

// ---- 001396d0 from src/anon/tiny.cpp
namespace n001396d0 {
void func_001396d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001396d0jjjj");
void func_001396d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t = *(u32*)((u32)a0 + (12));
    t |= 0x0020u;
    *(u32*)((u32)a0 + (12)) = t;
}
}  // namespace n001396d0

// ---- 001396e0 from src/anon/tiny.cpp
namespace n001396e0 {
void func_001396e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001396e0jjjj");
void func_001396e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = *(u32*)((u32)a0 + (12));
    v &= (u32)((s32)-33);
    *(u32*)((u32)a0 + (12)) = v;
}
}  // namespace n001396e0

// ---- 001396f8 gap: Obj2D flag test
namespace n001396f8 {
u32 func_001396f8(u8*) asm("func_001396f8");
u32 func_001396f8(u8* p) { u32 m = *(u32*)(p + 12) & 0x20; return m != 0; }
}  // namespace n001396f8

// ---- 00139708 from src/anon/tiny.cpp
namespace n00139708 {
void func_00139708(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00139708jjjj");
void func_00139708(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t = *(u32*)((u32)a0 + (12));
    t |= 0x0100u;
    *(u32*)((u32)a0 + (12)) = t;
}
}  // namespace n00139708

// ---- 00139718 from src/anon/tiny.cpp
namespace n00139718 {
void func_00139718(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00139718jjjj");
void func_00139718(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = *(u32*)((u32)a0 + (12));
    v &= (u32)((s32)-257);
    *(u32*)((u32)a0 + (12)) = v;
}
}  // namespace n00139718

// ---- 00139730 gap: Obj2D flag test
namespace n00139730 {
u32 func_00139730(u8*) asm("func_00139730");
u32 func_00139730(u8* p) { u32 m = *(u32*)(p + 12) & 0x100; return m != 0; }
}  // namespace n00139730

// ---- 00139740 from src/anon/tiny.cpp
namespace n00139740 {
void func_00139740(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00139740jjjj");
void func_00139740(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t = *(u32*)((u32)a0 + (12));
    t |= 0x0080u;
    *(u32*)((u32)a0 + (12)) = t;
}
}  // namespace n00139740

// ---- 00139750 gap: Obj2D flag helper
namespace n00139750 {
void func_00139750(u8*) asm("func_00139750");
void func_00139750(u8* p) { *(u32*)(p + 12) &= ~0x80; }
}  // namespace n00139750

// ---- 00139768 (was whole-asm src/anon/obj2d_isExist.s): call slot 5 of every listed node without flag bit 0
namespace n00139768 {
struct Node768 { void (**vt)(Node768*); Node768* next; u32 pad8; u32 flags; };
struct Head768 { u32 pad; Node768* first; };
extern Head768* D_00347f80 asm("D_00347f80");
static inline Node768* Next768(Node768* n) {
    Head768* h = D_00347f80;
    if (!n) return h->first;
    return n->next;
}
void func_00139768(void*) asm("_ZN2dk5Obj2D7isExistEPS0_");
void func_00139768(void*) {
    Node768* n = 0;
    while ((n = Next768(n))) {
        u32 f = n->flags & 1;
        if (f) continue;
        n->vt[5](n);
    }
}
}  // namespace n00139768

// ---- 001397d8 from src/anon/batch_w46.cpp
namespace n001397d8 {
void func_001397d8_i(s32 id) asm("_Z13func_001397d8i");
struct Node139 { void (**vt)(Node139*); Node139* next; u32 pad[2]; s32 id; };
struct Head139 { u32 pad; Node139* first; };
extern Head139* D_00347f80 asm("D_00347f80");
static inline Node139* Next139(Node139* n) {
    Head139* h = D_00347f80;
    if (!n) return h->first;
    return n->next;
}
void func_001397d8_i(s32 id) {
    Node139* n = 0;
    while ((n = Next139(n))) if (n->id == id) n->vt[5](n);
}
}  // namespace n001397d8

// ---- 00139858 from src/anon/batch_w49.cpp
namespace n00139858 {
void Obj2D_showGroup(int) asm("_ZN2dk5Obj2D9showGroupEi");
struct Node139858 { u32 f0; Node139858* next; u8 pad8[8]; s32 group; };
struct List139858 { u32 f0; Node139858* head; };
extern List139858* D_00347f80 asm("D_00347f80");
void func_00139580(Node139858*) asm("func_00139580");
static inline Node139858* next139858(Node139858* o) {
    List139858* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void Obj2D_showGroup(int group) {
    Node139858* o = 0;
    while ((o = next139858(o)) != 0)
        if (o->group == group) func_00139580(o);
}
}  // namespace n00139858

// ---- 001398d0 from src/anon/batch_w1520.cpp
namespace n001398d0 {
struct Node139 { u32 f0; Node139* next; u8 pad8[8]; s32 id; };
struct List139 { u32 f0; Node139* head; };
extern List139* D_00347f80 asm("D_00347f80");
static inline Node139* nextNode(Node139* o) {
    List139* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void hide139(Node139*) asm("_ZN2dk5Obj2D4hideEv");
void func_001398d0_i(s32 id) asm("_Z13func_001398d0i");
void func_001398d0_i(s32 id) {
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) hide139(o);
}
}  // namespace n001398d0

// ---- 00139948 from src/anon/batch_w1520.cpp
namespace n00139948 {
struct Node139 { u32 f0; Node139* next; u8 pad8[8]; s32 id; };
struct List139 { u32 f0; Node139* head; };
extern List139* D_00347f80 asm("D_00347f80");
static inline Node139* nextNode(Node139* o) {
    List139* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void lshow139(Node139*) asm("_ZN2dk5Obj2D9localShowEv");
void func_00139948(s32 id) asm("func_00139948");
void func_00139948(s32 id) {
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) lshow139(o);
}
}  // namespace n00139948

// ---- 001399c0 from src/anon/batch_w38.cpp
namespace n001399c0 {
struct Node1399c0 { u32 f0; Node1399c0* next; u8 pad8[8]; void* owner; };
struct List1399c0 { u32 f0; Node1399c0* head; };
extern List1399c0* D_00347f80 asm("D_00347f80");
void func_00139598(Node1399c0*) asm("func_00139598");
static inline Node1399c0* nextNode(Node1399c0* o) {
    List1399c0* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void func_001399c0(void* owner) asm("func_001399c0");
void func_001399c0(void* owner) {
    Node1399c0* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->owner == owner) func_00139598(o);
}
}  // namespace n001399c0

// ---- 00139a38 from src/anon/batch_w1520.cpp
namespace n00139a38 {
struct Node139 { u32 f0; Node139* next; u8 pad8[8]; s32 id; };
struct List139 { u32 f0; Node139* head; };
extern List139* D_00347f80 asm("D_00347f80");
static inline Node139* nextNode(Node139* o) {
    List139* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void func_001396d0(Node139*) asm("func_001396d0");
void func_00139a38(s32 id) asm("func_00139a38");
void func_00139a38(s32 id) {
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) func_001396d0(o);
}
}  // namespace n00139a38

// ---- 00139ab0 from src/anon/batch_w1520.cpp
namespace n00139ab0 {
struct Node139 { u32 f0; Node139* next; u8 pad8[8]; s32 id; };
struct List139 { u32 f0; Node139* head; };
extern List139* D_00347f80 asm("D_00347f80");
static inline Node139* nextNode(Node139* o) {
    List139* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void func_001396e0(Node139*) asm("func_001396e0");
void func_00139ab0(s32 id) asm("func_00139ab0");
void func_00139ab0(s32 id) {                     
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) func_001396e0(o);
}
}  // namespace n00139ab0

// ---- 00139b28 from src/anon/batch_w41.cpp
namespace n00139b28 {
struct W41Node { u32 f0; W41Node* next; u32 f8, fc; u32 key; };
struct W41List { u32 f0; W41Node* head; };
extern W41List* D_00347f80_list asm("D_00347f80");
void func_00139708(W41Node*) asm("func_00139708");
static inline W41Node* w41NextNode(W41List* l, W41Node* n) { if (n == 0) return l->head; return n->next; }
void func_00139b28(u32 key) asm("func_00139b28");
void func_00139b28(u32 key) {
    W41Node* n = 0;
    while ((n = w41NextNode(D_00347f80_list, n)) != 0) {
        if (n->key == key) func_00139708(n);
    }
}
}  // namespace n00139b28

// ---- 00139ba0 from src/anon/batch_w1520.cpp
namespace n00139ba0 {
struct Node139 { u32 f0; Node139* next; u8 pad8[8]; s32 id; };
struct List139 { u32 f0; Node139* head; };
extern List139* D_00347f80 asm("D_00347f80");
static inline Node139* nextNode(Node139* o) {
    List139* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void func_00139718(Node139*) asm("func_00139718");
void func_00139ba0(s32 id) asm("func_00139ba0");
void func_00139ba0(s32 id) {
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) func_00139718(o);
}
}  // namespace n00139ba0

// ---- 00139c18 from src/anon/perm_00139c18.cpp
namespace n00139c18 {
typedef unsigned char u8;
typedef signed int s32;
struct VObj139
{
  void (**vt)(VObj139 *);
};
typedef struct Pair139
{
  VObj139 a;
  u8 pad[20];
  VObj139 b;
} Pair139;
s32 u_call4_00139d78(void *) asm("_Z16u_call4_00139d78jjjj");
s32 func_00139c18(Pair139 *p) asm("func_00139c18");
s32 func_00139c18(Pair139 *p)
{
  VObj139 *new_var;
  if (u_call4_00139d78(p))
  {
    new_var = &p->a;
    p->a.vt[5](new_var);
    return 1;
  }
  new_var = &p->b;
  if (u_call4_00139d78(new_var))
  {
    p->b.vt[5](new_var);
  }
  return 0;
}
}  // namespace n00139c18

// ---- 00139c90 from src/anon/batch_w86.cpp
namespace n00139c90 {
struct Mtx {
    u32 m[16];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Mtx Mul(const Mtx& a, const Mtx& b)
{
    Mtx r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Cam { u8 p0[32]; Mtx m; };
struct Mats { u8 p0[16]; Mtx m; };
extern Cam* D_00347f80 asm("D_00347f80");
Mtx* func_00106a18(s32) asm("func_00106a18");
Mats* func_00106a60(s32) asm("func_00106a60");
void func_00139c90(void) asm("func_00139c90");
void func_00139c90(void)
{
    Mtx* d = &D_00347f80->m;
    Mtx* a = func_00106a18(0);                   
    Mats* b = func_00106a60(0);                        
    *d = Mul(*a, b ? b->m : *(Mtx*)0);
}
}  // namespace n00139c90

// ---- 00139d78 from src/anon/batch_w24.cpp
namespace n00139d78 {
struct LNode { u32 _0; LNode* next; };
struct LMgr { u32 _0; LNode* head; u8 _8[92]; u32 cur; };
static inline s32 list_has(LNode** hp, u32 a) {
    LNode* n = 0;
    while ((n = !n ? *hp : n->next) != 0) {
        if ((u32)n == a) return 1;
    }
    return 0;
}
u8 u_call4_00139d78(u32, u32, u32, u32) asm("_Z16u_call4_00139d78jjjj");
u8 u_call4_00139d78(u32 a, u32, u32, u32) {
    *(u32*)(D_00347f80 + 100) = a;  // u32 global (decls header); a field store would not reload it
    return list_has(&((LMgr*)D_00347f80)->head, a);
}
}  // namespace n00139d78

// ---- 00139dc0 from src/anon/tiny_auto80_solver.cpp
namespace n00139dc0 {
extern u8 D_00347ea0 asm("D_00347ea0");
void func_00139dc0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00139dc0jjjjjjjj");
void func_00139dc0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {                 
    u32 stride = 112;
    u32 base = (u32)&D_00347ea0;
    a0 *= stride;
    a0 += base;
    u32 gp = 0x00340000u;
    *(u32*)(gp + 32640) = a0;
    *(u32*)(a0 + 96) = 0;
    *(u32*)(a0 + 100) = 0;
}
}  // namespace n00139dc0

// ---- 00139de8 from src/anon/tiny.cpp
namespace n00139de8 {
void func_00139dc0(s32) asm("_Z13func_00139dc0i");
void func_00139de8(BD_VALUE* bd) asm("_Z13func_00139de8P8BD_VALUE");
void func_00139de8(BD_VALUE* bd) { func_00139dc0(0); }
}  // namespace n00139de8

// ---- 00139e00 from src/anon/batch_w93.cpp
namespace n00139e00 {
struct W93V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void W93Set(W93V* d, const W93V* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct W93Vec { W93V v; W93Vec& operator=(const W93Vec& o) { W93Set(&v, &o.v); return *this; } };
static inline __attribute__((always_inline)) W93Vec operator-(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator+(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator*(const W93Vec& a, f32 k)
{ W93Vec r; asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory"); return r; }
struct W93Task { u32 f0; void* owner; u8 pad[40]; void* fn; };
struct W93G { u32 f0; u32 f4; u32 f8; u8 pad[8]; u32 f20; };
extern W93G* D_00347f80 asm("D_00347f80");
void func_00139dc0(s32) asm("func_00139dc0");
W93Task* func_00105d78(u32, u32, void*) asm("func_00105d78");
W93Task* func_00103b48(u32, u32, void*) asm("func_00103b48");
u32 func_001024b0(u32) asm("func_001024b0");
W93Task* func_00102788(u32, u32, u32, void*) asm("func_00102788");
void func_00139390() asm("func_00139390");
void func_001393e0() asm("func_001393e0");
void func_001394c0() asm("func_001394c0");
void func_001394d8() asm("func_001394d8");
void func_00139308() asm("func_00139308");
void func_00139e00(u32 a, u8 flag) asm("func_00139e00");
void func_00139e00(u32 a, u8 flag)
{
    W93Task* t;
    func_00139dc0(1);
    *(W93G**)((u8*)D_00347f80 + 20) = (W93G*)a;
    D_00347f80->f8 = 0;
    D_00347f80->f4 = 0;
    if (flag) t = func_00105d78(0, 0x186a0, (void*)func_00139390);
    else t = func_00103b48(0, 0x186a0, (void*)func_00139390);
    t->fn = (void*)func_001393e0;
    t->owner = D_00347f80;
    if (flag) t = func_00105d78(0, 0x1944c, (void*)func_001394c0);
    else t = func_00103b48(0, 0x1944c, (void*)func_001394c0);
    *(W93G**)((u8*)t + 4) = D_00347f80;
    *(W93G**)((u8*)t + 48) = (W93G*)func_001394d8;
    *(W93G**)D_00347f80 = (W93G*)func_001024b0(a);
    t = func_00102788(D_00347f80->f0, 0, 0x19258, (void*)func_00139308);
    t->owner = D_00347f80;
}
}  // namespace n00139e00

// ---- 00139f38 from src/anon/batch_w109.cpp
namespace n00139f38 {
struct G139f38 { s32 x0; s32 x4; s32 x8; u8 pad[8]; G139f38* x20; };
union U139f38 { G139f38* p; void* q; };
extern U139f38 D_00347f80_u asm("D_00347f80");
struct T139f38 { u8 pad[4]; void* x4; u8 pad2[40]; void* x48; };
void func_00139dc0(s32) asm("func_00139dc0");
s32 func_00102c80(void) asm("func_00102c80");
s32 func_00103070(void) asm("func_00103070");
s32 func_001045f0(void) asm("func_001045f0");
void func_00102180(s32*) asm("func_00102180");
T139f38* func_00102c18(s32, s32, void*) asm("func_00102c18");
T139f38* func_00102f08(s32, s32, void*) asm("func_00102f08");
T139f38* func_00104588(s32, s32, void*) asm("func_00104588");
s32 func_001024b0(G139f38*) asm("func_001024b0");
T139f38* func_00102788(s32, s32, s32, void*) asm("func_00102788");
void func_00139de8(void) asm("func_00139de8");
void func_00139390(void) asm("func_00139390");
void func_001393c8(void) asm("func_001393c8");
void func_001394c0(void) asm("func_001394c0");
void func_001394d8(void) asm("func_001394d8");
void func_00139308(void) asm("func_00139308");
void func_00139f38(G139f38* arg) asm("func_00139f38");
void func_00139f38(G139f38* arg) {
    T139f38* o;
    s32 mode;
    func_00139dc0(0);
    D_00347f80_u.p->x20 = arg;
    G139f38* g = D_00347f80_u.p;
    g->x8 = 0;
    g->x4 = 0;
    s32 m0 = func_00102c80();
    s32 m1 = func_00103070();
    s32 m2 = func_001045f0();
    func_00102180(&mode);
    if (mode == m0) {
        func_00102c18(1, 6010, (void*)func_00139de8);
        o = func_00102c18(1, 100000, (void*)func_00139390);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001393c8;
        o = func_00102c18(1, 103500, (void*)func_001394c0);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001394d8;
        D_00347f80_u.p->x0 = func_001024b0(arg);
        func_00102788(D_00347f80_u.p->x0, 0, 103000, (void*)func_00139308)->x4 = D_00347f80_u.p;
    } else if (mode == m1) {
        o = func_00102f08(0, 100000, (void*)func_00139390);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001393c8;
        o = func_00102f08(0, 125000, (void*)func_001394c0);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001394d8;
        D_00347f80_u.p->x0 = func_001024b0(arg);
        func_00102788(D_00347f80_u.p->x0, 0, 120000, (void*)func_00139308)->x4 = D_00347f80_u.p;
    } else if (mode == m2) {
        o = func_00104588(0, 100000, (void*)func_00139390);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001393c8;
        o = func_00104588(0, 127500, (void*)func_001394c0);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001394d8;
        D_00347f80_u.p->x0 = func_001024b0(arg);
        func_00102788(D_00347f80_u.p->x0, 0, 110000, (void*)func_00139308)->x4 = D_00347f80_u.p;
    }
}
}  // namespace n00139f38

// ---- 0013a178 from src/anon/batch_w47.cpp
namespace n0013a178 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern s32 D_003b8b40[4] asm("D_003b8b40");
s32* func_0013a178(Vec4* v, Vec4* m) asm("func_0013a178");
s32* func_0013a178(Vec4* v, Vec4* m) {             
    s32* d = D_003b8b40;
    asm volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,16(%1)\n\tlqc2 $vf6,32(%1)\n\tlqc2 $vf7,48(%1)\n\tlqc2 $vf8,0(%2)\n\t"
        "vmulax.wxyz ACC,$vf4,$vf8x\n\tvmadday.wxyz ACC,$vf5,$vf8y\n\tvmaddaz.wxyz ACC,$vf6,$vf8z\n\tvmaddw.wxyz $vf12,$vf7,$vf8w\n\t"
        "vdiv Q,$vf0w,$vf12w\n\tvwaitq\n\tvmulq.wxyz $vf12,$vf12,Q\n\tvftoi0.wxyz $vf13,$vf12\n\tsqc2 $vf13,0(%0)"
        : : "r"(d), "r"(m), "r"(v) : "memory");
    D_003b8b40[0] -= 1792;
    d[1] -= 1840;
    return d;
}
}  // namespace n0013a178

// ---- 0013a1d8 from src/harata/libdk/obj2d.cpp
namespace n0013a1d8 {
extern u32 D_00347f80 asm("D_00347f80");
}  // namespace n0013a1d8
namespace dk {
u32 Obj2D::GetAllocator() { using namespace ::n0013a1d8; using ::n0013a1d8::D_00347f80;
    u32 p = D_00347f80;
    return *(u32*)((u32)p + 20);
}
}  // namespace dk

// ---- 0013a1e8 from src/anon/tiny_more2.cpp
namespace n0013a1e8 {
extern u32 D_00347f80 asm("D_00347f80");
extern u32 D_00347f84 asm("D_00347f84");
void func_0013a1e8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0013a1e8jjjj");
void func_0013a1e8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; D_00347f84 = D_00347f80; }
}  // namespace n0013a1e8

// ---- 0013a200 from src/anon/batch_w1.cpp
namespace n0013a200 {
extern s32 D_00347f80 asm("D_00347f80");
extern s32 D_00347f84 asm("D_00347f84");
void func_0013a200(void) asm("func_0013a200");
void func_0013a200(void) {
    D_00347f80 = D_00347f84;
    D_00347f84 = 0;
}
}  // namespace n0013a200

// ---- 0013a218 from src/anon/tiny_wrappers_imp.cpp
namespace n0013a218 {
u32 func_001393f8(u32, u32, u32, u32) asm("_Z13func_001393f8jjjj");
u32 func_0013a218(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0013a218jjjj");
u32 func_0013a218(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0034u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(32640));
    return func_001393f8(r4, r5, r6, r7);
}
}  // namespace n0013a218

// ---- 0013a238 gap: empty function
namespace n0013a238 {
void func_0013a238(u8*) asm("func_0013a238");
void func_0013a238(u8*) {}
}  // namespace n0013a238

// ---- 0013a240 from src/anon/batch_w3749.cpp
namespace n0013a240 {
struct Obj { s32 a0; s32 a4; s32 a8; s32 ac; s32 b0; s32 b4; u8 pad[8]; u8 sub[0x40]; s32 c0; u8 pad2[0xc]; ~Obj() {} };
extern Obj D_00347ea0[2] asm("D_00347ea0");
void func_0031ae00(void*) asm("func_0031ae00");
void func_0013a240(int a, int b) asm("_Z13func_0013a240ii");
void func_0013a240(int a, int b) {
    if (b == 0xffff && a == 1) {
        Obj* p = D_00347ea0; s32 n = 1; s32* q = (s32*)((u8*)p + 96);
        do {
            q[-22] = 0; q[-23] = 0; q[-20] = 0; q[-21] = 0;
            void* s = p->sub; p++; n--;
            func_0031ae00(s);
            q[-19] = 0; q[0] = 0;
            q += 28;
        } while (n != -1);
    }
    if (b == 0xffff && a == 0) { if (D_00347ea0) { Obj* e = D_00347ea0 + 2; for (;;) { e->~Obj(); if (e == D_00347ea0) break; --e; } } }
}
}  // namespace n0013a240

// ---- 0013a328 from src/anon/tiny.cpp
namespace n0013a328 {
void func_0013a240(s32, s32) asm("_Z13func_0013a240ii");
void func_0013a328(BD_VALUE* bd) asm("_Z13func_0013a328P8BD_VALUE");
void func_0013a328(BD_VALUE* bd) { func_0013a240(1, 0xffff); }
}  // namespace n0013a328

// ---- 0013a348 gap: _GLOBAL__D_ stub of the Obj2D file
namespace n0013a348 {
void func_0013a240(s32, s32) asm("_Z13func_0013a240ii");
void func_0013a348(void) asm("func_0013a348");
void func_0013a348(void) { func_0013a240(0, 0xffff); }
}  // namespace n0013a348

