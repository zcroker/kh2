// Linked unit 0x00127a88-0x00127ec8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00127a88 (was src/anon/batch_w111.cpp)
namespace n00127a88 {
#define QCOPY12(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define MCOPY12(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                         : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct V12 { f32 x, y, z, w;
    V12& operator=(const V12& o) { if (this != &o) QCOPY12(this, &o); return *this; }
} __attribute__((aligned(16)));
struct M12 { V12 r[4];
    M12& operator=(const M12& o) { if (this != &o) MCOPY12(this, &o); return *this; }
};
struct Heap12 { void** vt; };
typedef void* (*AllocFn12)(Heap12*, s32, void*);
struct Src12Info { u8 pad[4]; s32 kind; };
struct Src12Sub { void** vt; Src12Info* info; };
struct Src12Tbl { u8 pad[8]; s32 n; u8 pad2[4]; u8 data[1]; };
struct Src12 {
    u8 pad[12]; u32 flags; u8 pad2[4]; Src12Sub* shape; Src12Sub* sub; V12* pos; V12* scl; u8 pad3[4]; union { M12* mtx; f32 fx; };
};
struct Dst12 { V12* pos; union { M12* mtx; f32 fx; }; u8 pad[4]; union { s32 f12; Src12Sub* f12p; }; void* tbl; Src12Sub* shape; u8 b24; u8 b25; };
void func_00124828(Dst12*) asm("func_00124828");
void* func_00124c48(Src12Sub*, s32) asm("func_00124c48");
void memcpy(void*, void*, s32) asm("memcpy");
Dst12* func_00127a88(Src12* o, Heap12* heap) asm("_Z13func_00127a88Pv");
typedef s32 (*CountFn12)(Src12Sub*);
typedef s32 (*SubFn12)(Src12Sub*, Src12*, Heap12*);
/*TARGET 00127a88*/
Dst12* func_00127a88(Src12* o, Heap12* heap) asm("_Z13func_00127a88Pv");
Dst12* func_00127a88(Src12* o, Heap12* heap)
{
    s32 n = ((CountFn12)o->shape->vt[7])(o->shape);
    Dst12* r = (Dst12*)((AllocFn12)heap->vt[0])(heap, n * 80 + 32, __builtin_return_address(0));
    func_00124828(r);
    r->f12 = 0;
    V12* p = (V12*)((u8*)r + 32);
    r->pos = p;
    r->tbl = 0;
    r->mtx = (M12*)(p + n);
    r->shape = o->shape;
    for (s32 i = 0; i < n; i++) {
        r->pos[i] = o->pos[i];
        V12& d = r->pos[i]; V12& sv = o->scl[i]; d.w = sv.x;
        r->mtx[i] = o->mtx[i];
    }
    if (o->flags & 1) r->b25 = 1;
    if (o->sub) {
        r->f12 = ((SubFn12)o->sub->vt[4])(o->sub, o, heap);
        s32 k = o->sub->info->kind;
        if (k == 1) r->b24 = k; else r->b24 = 0;
        Src12Tbl* t = (Src12Tbl*)func_00124c48(o->sub, 0);
        if (t) {
            s32 sz = t->n * 4;
            r->tbl = ((AllocFn12)heap->vt[0])(heap, sz + 4, 0);
            memcpy(r->tbl, t->data, sz);
            s16* e = (s16*)(sz + (u32)r->tbl);
            e[1] = -1;
            e[0] = -1;
        }
    }
    return r;
}
}  // namespace n00127a88

// 00127c70 (was src/anon/auto80_199_queue.cpp)
namespace n00127c70 {
/*TARGET 00127c70*/
void func_00127c70(u32 a0, Obj* a1, u32 a2) asm("_Z13func_00127c70jP3Objj");
void func_00127c70(u32 a0, Obj* a1, u32 a2) {
    Obj* s0 = a1;
    u32 s1 = a2;

    u32 t7 = *(u32*)(s1 + 12);
    if (t7 != 0) {
        ((VCall4)s0->vtbl[1])(s0, t7);
    }

    t7 = *(u32*)(s1 + 16);
    if (t7 != 0) {
        ((VCall4)s0->vtbl[1])(s0, t7);
    }

    func_00124840(s1);
    ((VCall4)s0->vtbl[1])(s0, s1);
    (void)a0;
}
}  // namespace n00127c70

// 00127cf8 (was src/anon/tiny_auto80_queue.cpp)
namespace n00127cf8 {
/*TARGET 00127cf8*/
void func_00127cf8(u32 a0) asm("_Z13func_00127cf8j");
void func_00127cf8(u32 a0) {
    if (a0 == 0) {
        return;
    }

    u64 mask = 1;
    mask <<= 53;
    u64 flags = *(u64*)(a0 + 16);
    if ((flags & mask) != 0) {
        return;
    }

    *(u32*)(a0 + 16) = 0;
loop:
    a0 += 32;
    flags = *(u64*)(a0 + 16);
    if ((flags & mask) == 0) {
        *(u32*)(a0 + 16) = 0;
        goto loop;
    }
}
}  // namespace n00127cf8

// 00127d40 (was src/anon/batch_w44.cpp)
namespace n00127d40 {
u32 wtarget_00127d40(u32, u32, u32, u32) asm("_Z16wtarget_00127d40jjjj");
// set_vtbl_347940
void func_00127f40(u32, u32) asm("func_00127f40");
void func_001316f0(u32, u32) asm("func_001316f0");
/*TARGET 00127d40*/
u32 wtarget_00127d40(u32 a, u32, u32, u32) asm("_Z16wtarget_00127d40jjjj");
u32 wtarget_00127d40(u32 a, u32, u32, u32) {
    u32 r = 0;
    u32 s = a + 144;
    switch (*(s32*)s) {
    case 0: func_00127f40(a, s); r = a; break;
    case 1: func_001316f0(a, s); r = a; break;
    }
    return r;
}
}  // namespace n00127d40

// 00127da0 (was src/anon/batch_w1.cpp)
namespace n00127da0 {
/*TARGET 00127da0*/
// 0x0011a918: definition moved into src/anon/unit_0011a660.cpp

// Virtual call: slot 0.
void func_00127da0(void** o) asm("func_00127da0");
// 0x0011a918: definition moved into src/anon/unit_0011a660.cpp

// Virtual call: slot 0.
void func_00127da0(void** o) {
    (*(void (**)(void*))*o)(o);
}
}  // namespace n00127da0

// 00127dc8 (was src/anon/tiny_wrappers_more.cpp)
namespace n00127dc8 {
u32 func_00127d40(u32, u32, u32, u32) asm("_Z13func_00127d40jjjj");
/*TARGET 00127dc8*/
u32 func_00127dc8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00127dc8jjjj");
u32 func_00127dc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00127d40(a0, a1, a2, a3);
}
}  // namespace n00127dc8

// 00127de0 (was src/anon/batch_w1664.cpp)
namespace n00127de0 {
// 0x00112568: definition moved into src/anon/unit_001117d8.cpp
void wtarget_00127de0(u32, u32, u32, u32) asm("_Z16wtarget_00127de0jjjj");
/*TARGET 00127de0*/
void wtarget_00127de0(u32, u32, u32, u32) asm("_Z16wtarget_00127de0jjjj");
void wtarget_00127de0(u32, u32, u32, u32) {}
}  // namespace n00127de0

// 00127de8 (was src/anon/batch_w55.cpp)
namespace n00127de8 {
/*TARGET 00127de8*/
// Wraps an angle into [-pi, pi].
f32 func_00127de8(f32 a) asm("func_00127de8");
// Wraps an angle into [-pi, pi].
f32 func_00127de8(f32 a) {  // clampf
    if (a > 0.0f) {
        while (a > 3.1415927f) a -= 6.2831855f;
    } else {
        while (a < -3.1415927f) a += 6.2831855f;
    }
    return a;
}
}  // namespace n00127de8

// 00127e80 (gap function, not written before)
namespace g00127e80 {
void func_00127e80(void) asm("func_00127e80");
void func_00127e80(void) {}
}  // namespace g00127e80

// 00127e88 (was src/anon/tiny_wrappers_more.cpp)
namespace n00127e88 {
u32 func_00127de0(u32, u32, u32, u32) asm("_Z13func_00127de0jjjj");
/*TARGET 00127e88*/
u32 func_00127e88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00127e88jjjj");
u32 func_00127e88(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00127de0(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00127e88

// 00127ea8 (gap function, not written before)
namespace g00127ea8 {
u32 func_00127de0(u32, u32, u32, u32) asm("_Z16wtarget_00127de0jjjj");
// _GLOBAL__D_ stub of this file.
u32 func_00127ea8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00127ea8");
u32 func_00127ea8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00127de0(0, 0x0000ffffu, a2, a3);
}
}  // namespace g00127ea8

