// YS script traps, second part of the file 0x170f58-0x175590 (see unit_00170f58.cpp): object,
// camera, bg, flag and table traps, then the file's empty static init, the five empty atexit
// destructors of its function-local static vectors, and the _GLOBAL__I_/_GLOBAL__D_ stubs.
#include "../common/types.h"
#include "../yasui/libys/attack.hpp"
#include "../yasui/libys/battlereport.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"

// ---- 00171e58 from src/anon/batch_w10.cpp
namespace n00171e58 {
typedef void (*VFn)(void*);
void trap_obj_leave_force(void*) asm("_ZN2YS20trap_obj_leave_forceEP8BD_VALUE");
void trap_obj_leave_force(void* v) {
    void* o = *(void**)(*(u8**)v + 4);
    (*(VFn*)(*(u8**)o + 32))(o);
}
}  // namespace n00171e58

// ---- 00171e88 from src/ys/traps.cpp
namespace n00171e88 {
extern void YS_OBJ_change_action(void*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void trap_obj_action_lightcycle(BD_VALUE* bd) asm("_ZN2YS26trap_obj_action_lightcycleEP8BD_VALUE");
void trap_obj_action_lightcycle(BD_VALUE* bd) {
    YS_OBJ_change_action(*(void**)((char*)bd->i + 4), 0x17);
}
}  // namespace n00171e88

// ---- 00171ea8 from src/anon/batch_w30.cpp
namespace n00171ea8 {
void YS__OBJ__get_lightcycle_movement(void*, u32, u32, f32) asm("YS__OBJ__get_lightcycle_movement");
extern u8 D_01c5f480[16] asm("D_01c5f480");
void func_00171ea8(u8* p) asm("func_00171ea8");
void func_00171ea8(u8* p) {
    u8 tmp[16] __attribute__((aligned(16)));
    YS__OBJ__get_lightcycle_movement(tmp, *(u32*)(*(u8**)p + 4), *(u32*)(*(u8**)(p + 4) + 4), *(f32*)(p + 8));
    u8* d = D_01c5f480;
    if (d != tmp) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    }
    *(u8**)p = d;
}
}  // namespace n00171ea8

// ---- 00171f00 from src/ys/traps.cpp
namespace n00171f00 {
extern void YS_OBJ_scatter_prize(void*, s32) asm("_ZN2YS3OBJ13scatter_prizeEi");
void trap_obj_scatter_prize(BD_VALUE* bd) asm("_ZN2YS22trap_obj_scatter_prizeEP8BD_VALUE");
void trap_obj_scatter_prize(BD_VALUE* bd) {
    YS_OBJ_scatter_prize(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n00171f00

// ---- 00171f20 from src/anon/tiny_auto80_queue.cpp
namespace n00171f20 {
u32 YS__OBJ__get_target_pos(...) asm("YS__OBJ__get_target_pos");
u32 func_001c7d90(...) asm("func_001c7d90");
void func_00171f20(u32 a0) asm("_Z13func_00171f20j");
void func_00171f20(u32 a0) {
    struct {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } spv;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 s0 = a0;
    u32 a1 = *(u32*)((u32)t7 + (s32)(4));
    YS__OBJ__get_target_pos((u32)&spv, a1);
    f32 f12 = *(f32*)((u32)s0 + (s32)(4));
    ((void(*)(u32, f32))func_001c7d90)((u32)&spv, f12);
}
}  // namespace n00171f20

// ---- 00171f60 gap
namespace g00171f60 {
void func_00171f60(BD_VALUE* bd) asm("func_00171f60");
void func_00171f60(BD_VALUE* bd) {}
}  // namespace g00171f60

// ---- 00171f68 from src/anon/tiny_auto80_queue.cpp
namespace n00171f68 {
u32 YS__OBJ__get_target_pos(...) asm("YS__OBJ__get_target_pos");
u32 func_001d2930(...) asm("func_001d2930");
void func_00171f68(u32 a0) asm("_Z13func_00171f68j");
void func_00171f68(u32 a0) {
    struct {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } spv;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 s0 = a0;
    u32 a1 = *(u32*)((u32)t7 + (s32)(4));
    YS__OBJ__get_target_pos((u32)&spv, a1);
    a1 = *(u32*)((u32)s0 + (s32)(4));
    func_001d2930((u32)&spv, a1);
}
}  // namespace n00171f68

// ---- 00171fa8 from src/anon/batch_w45.cpp
namespace n00171fa8 {
u32 func_0016cf00(u32, u32, u32, u32*, u32) asm("func_0016cf00");
void func_00177460(u32, u32) asm("func_00177460");
extern u32 D_0034d8a0 asm("D_0034d8a0");
void func_00171fa8(u32* a0) asm("func_00171fa8");
void func_00171fa8(u32* a0) {
    u32 buf[2];
    u32 n = 1;
    u32 s = *(u32*)(a0[0] + 4);
    buf[0] = s;
    if (a0[2]) {
        buf[1] = a0[2];
        n = 2;
    }
    func_00177460(s, func_0016cf00(D_0034d8a0, 0, a0[1], buf, n));
}
}  // namespace n00171fa8

// ---- 00172008 from src/ys/traps.cpp
namespace n00172008 {
u32 func_00177460(u32, u32, u32, u32) asm("func_00177460");
u32 trap_obj_hook_stop(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS18trap_obj_hook_stopEP8BD_VALUE");
u32 trap_obj_hook_stop(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00177460(*(u32*)(*(u32*)(a0 + 0u) + 4u), 0, a2, a3);
}
}  // namespace n00172008

// ---- 00172028 from src/ys/traps.cpp
namespace n00172028 {
extern void YS_FIELDOBJ_mark_history(void*) asm("_ZN2YS8FIELDOBJ12mark_historyEv");
void trap_obj_history_mark(BD_VALUE* bd) asm("_ZN2YS21trap_obj_history_markEP8BD_VALUE");
void trap_obj_history_mark(BD_VALUE* bd) {
    YS_FIELDOBJ_mark_history(*(void**)((char*)bd->i + 4));
}
}  // namespace n00172028

// ---- 00172048 gap
namespace g00172048 {
s32 func_001a6c60(u8*) asm("func_001a6c60");
void func_00172048(BD_VALUE* bd) asm("func_00172048");
void func_00172048(BD_VALUE* bd) { bd->i = func_001a6c60(*(u8**)((u8*)bd[0].p + 4)); }
}  // namespace g00172048

// ---- 00172078 from src/anon/batch_w8007.cpp
namespace n00172078 {
void func_001945a0(u8*, s32, u32, f32) asm("func_001945a0");
struct W8007O72 { u8 pad[4]; u8* p; };
struct W8007S72 { W8007O72* o; s32 a; u32 b; f32 f; };
void func_00172078(W8007S72* s) asm("func_00172078");
void func_00172078(W8007S72* s) {
    u8* p = s->o->p;
    func_001945a0(p, s->a, s->b, s->f);
}
}  // namespace n00172078

// ---- 001720a8 gap
namespace g001720a8 {
void func_00194610(u8*, s32, f32) asm("func_00194610");
void func_001720a8(BD_VALUE* bd) asm("func_001720a8");
void func_001720a8(BD_VALUE* bd) {
    u8* o = *(u8**)((u8*)bd[0].p + 4);
    func_00194610(o, bd[1].i, bd[2].f);
}
}  // namespace g001720a8

// ---- 001720d0 from src/anon/tiny_wrappers_imp.cpp
namespace n001720d0 {
u32 func_0011c828(u32, u32, u32, u32) asm("_Z13func_0011c828jjjj");
u32 func_001720d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001720d0jjjj");
u32 func_001720d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r5 = *(u32*)((u32)r4 + (s32)(4));
    r14 = *(u32*)((u32)r15 + (s32)(4));
    r4 = *(u32*)((u32)r14 + (s32)(1648));
    return func_0011c828(r4, r5, r6, r7);
}
}  // namespace n001720d0

// ---- 001720f8 gap
namespace g001720f8 {
void func_0011c890(u32, s32) asm("func_0011c890");
void func_001720f8(BD_VALUE* bd) asm("func_001720f8");
void func_001720f8(BD_VALUE* bd) {
    s32 v = bd[1].i;
    func_0011c890(*(u32*)(*(u8**)((u8*)bd[0].p + 4) + 1648), v);
}
void func_00172120(BD_VALUE* bd) asm("func_00172120");
void func_00172120(BD_VALUE* bd) {
    u8* o = *(u8**)((u8*)bd[0].p + 4);
    u8* c = *(u8**)(o + 12);
    ((void (*)(u8*, u8*, f32))(*(void***)c)[3])(c, o, bd[1].f);
}
}  // namespace g001720f8

// ---- 00172158 from src/anon/batch_w65.cpp
namespace n00172158 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Vr {
    f32 x, y, z, w;
    Vr() {}
    Vr(const Vr& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
void YS__OBJ__prepare_jump(void*, Vq*) asm("YS__OBJ__prepare_jump");
void func_0017f488(void*, u32, f32, f32) asm("func_0017f488");
void YS__method_obj_jump(u32* p) asm("YS__method_obj_jump");
void YS__method_obj_jump(u32* p) {
    u8* o = *(u8**)(p[0] + 4);
    Vq t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(p[1]) : "$8", "memory");
    YS__OBJ__prepare_jump(o, &t);
    func_0017f488(o + 320, p[2], *(f32*)&p[3], 0.0f);
    if (p[4]) {
        s32 v = p[2];
        *(s32*)(o + 256) = v + 1;
        *(s32*)(o + 260) = v + 2;
    }
}
}  // namespace n00172158

// ---- 001721d8 from src/anon/batch_w21.cpp
namespace n001721d8 {
void YS_trap_obj_jump_direct(BD_VALUE*) asm("_ZN2YS20trap_obj_jump_directEP8BD_VALUE");
typedef void (*JumpFn)(void*, void*, s32);
void YS_trap_obj_jump_direct(BD_VALUE* bd) {
    u8* w = *(u8**)((u8*)bd[0].p + 4);
    void** o = *(void***)(w + 12);
    (*(JumpFn*)((u8*)*o + 8))(o, w, bd[1].i);
}
}  // namespace n001721d8

// ---- 00172210 gap
namespace g00172210 {
void func_00172210(BD_VALUE* bd) asm("func_00172210");
void func_00172210(BD_VALUE* bd) {
    s32 v = bd[1].i;
    u8* o = *(u8**)((u8*)bd[0].p + 4);
    *(s32*)(o + 256) = v + 1;
    *(s32*)(o + 260) = v + 2;
}
void func_00172230(BD_VALUE* bd) asm("func_00172230");
void func_00172230(BD_VALUE* bd) { *(s32*)(*(u8**)((u8*)bd[0].p + 4) + 256) = bd[1].i; }
void func_00172248(BD_VALUE* bd) asm("func_00172248");
void func_00172248(BD_VALUE* bd) { *(s32*)(*(u8**)((u8*)bd[0].p + 4) + 260) = bd[1].i; }
}  // namespace g00172210

// ---- 00172260 from src/anon/batch_w60.cpp
namespace n00172260 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
void func_001b2210(void*, void*, f32, f32) asm("func_001b2210");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
struct Args172 { u8** a; void* pos; f32 c; f32 d; s32 e; f32 f; s32 g; };
void YS__trap_obj_hop(Args172* s) asm("YS__trap_obj_hop");
void YS__trap_obj_hop(Args172* s) {
    u8* o = *(u8**)(*(u8**)s + 4);
    u32 tmp[4] __attribute__((aligned(16)));
    QCOPY(tmp, s->pos);
    func_001b2210(o, tmp, s->c, s->d);
    func_0017f488(o + 320, s->e, s->f, 0.0f);
    if (s->g) {
        s32 e = s->e;
        *(s32*)(o + 256) = e + 1;
        *(s32*)(o + 260) = e + 2;
    }
}
}  // namespace n00172260

// ---- 001722e8 from src/anon/batch_w50.cpp
namespace n001722e8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Q16 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct S172 { u8* o; Q16* v; u32 n; f32 f; u32 flag; };
void func_001b6dd0(void*, void*) asm("func_001b6dd0");
void func_0017f488(void*, u32, f32, f32) asm("func_0017f488");
void YS__trap_obj_flyjump(S172* s) asm("YS__trap_obj_flyjump");
void YS__trap_obj_flyjump(S172* s) {
    u8* o = *(u8**)(s->o + 4);
    Q16 t;
    QCOPY(&t, s->v);
    func_001b6dd0(o, &t);
    func_0017f488(o + 320, s->n, s->f, 0.0f);
    if (s->flag) {
        u32 n = s->n;
        *(u32*)(o + 256) = n + 1;
        *(u32*)(o + 260) = n + 2;
    }
}
}  // namespace n001722e8

// ---- 00172368 from src/anon/batch_w22.cpp
namespace n00172368 {
void func_001a0710(u32, void*, f32) asm("func_001a0710");
void func_00172368(u32** p) asm("func_00172368");
void func_00172368(u32** p) {
    u32 v[4] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v), "r"(p[1]) : "$8", "memory");
    func_001a0710(p[0][1], v, *(f32*)&p[2]);
}
}  // namespace n00172368

// ---- 001723a0 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001723a0 {
extern "C" u32 YS_OBJ_is_hover(u32, u32, u32, u32) asm("_ZN2YS3OBJ8is_hoverEv");
u32 func_001723a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001723a0jjjj");
u32 func_001723a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = YS_OBJ_is_hover(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001723a0

// ---- 001723d0 from src/anon/batch_w12.cpp
namespace n001723d0 {
void YS__OBJ__is_valid(u32) asm("YS__OBJ__is_valid");
void func_0016bd60(u32, s32) asm("func_0016bd60");
void trap_obj_idle(u32**) asm("_ZN2YS13trap_obj_idleEP8BD_VALUE");
void trap_obj_idle(u32** bd) {
    YS__OBJ__is_valid((*bd)[1]);                      
    func_0016bd60((*bd)[1], 0);
}
}  // namespace n001723d0

// ---- 00172408 gap
namespace g00172408 {
static inline bool busy(u32 f) { return (f & 1) || (f & 2); }
void func_00172408(BD_VALUE* bd) asm("func_00172408");
void func_00172408(BD_VALUE* bd) { bd->i = busy(*(u32*)(*(u8**)(*(u8**)((u8*)bd[0].p + 4) + 12) + 8)); }
}  // namespace g00172408

// ---- 00172440 from src/anon/batch_w35.cpp
namespace n00172440 {
u32 YS__MOTION__capture(u32, u32, u32, f32) asm("YS__MOTION__capture");
void func_00172440(u8* p) asm("func_00172440");
void func_00172440(u8* p) {
    *(u32*)p = YS__MOTION__capture(*(u32*)(*(u8**)p + 4) + 320, *(u32*)(*(u8**)(p + 4) + 4), *(u32*)(p + 8), *(f32*)(p + 12));
}
}  // namespace n00172440

// ---- 00172488 gap
namespace g00172488 {
void func_00172488(BD_VALUE* bd) asm("func_00172488");
void func_00172488(BD_VALUE* bd) { bd->i = (*(u8*)(*(u8**)((u8*)bd[0].p + 4) + 568) >> (bd[1].i - 1)) & 1; }
void func_001724b0(BD_VALUE* bd) asm("func_001724b0");
void func_001724b0(BD_VALUE* bd) { bd->i = (*(u8*)(*(u8**)((u8*)bd[0].p + 4) + 569) >> (bd[1].i - 1)) & 1; }
void func_001724d8(BD_VALUE* bd) asm("func_001724d8");
static inline bool test(u32 v, u32 m) { return (v & m) != 0; }
void func_001724d8(BD_VALUE* bd) { bd->i = test(*(u32*)(*(u8**)((u8*)bd[0].p + 4) + 352), 0x10); }
}  // namespace g00172488

// ---- 001724f8 from src/anon/tiny_wrappers_imp.cpp
namespace n001724f8 {
extern "C" u32 func_0017fd30(u32, u32, u32, u32) asm("_ZN2YS6MOTION4syncEPS0_");
u32 func_001724f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001724f8jjjj");
u32 func_001724f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = *(u32*)((u32)r4 + (s32)(4));
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r5 = *(u32*)((u32)r14 + (s32)(4));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r5 = (u32)((s32)r5 + (320));
    r4 = (u32)((s32)r4 + (320));
    return func_0017fd30(r4, r5, r6, r7);
}
}  // namespace n001724f8

// ---- 00172528 gap
namespace g00172528 {
static inline bool test(u32 v, u32 m) { return (v & m) != 0; }
void func_0017fd60(u8*, u8*) asm("func_0017fd60");
void func_00172528(BD_VALUE* bd) asm("func_00172528");
void func_00172528(BD_VALUE* bd) {
    u8* b = *(u8**)((u8*)bd[1].p + 4);
    u8* a = *(u8**)((u8*)bd[0].p + 4);
    func_0017fd60(a + 320, b + 320);
}
u32 YS__OBJ__is_exist(u8*) asm("YS__OBJ__is_exist");
void func_00172558(BD_VALUE* bd) asm("func_00172558");
void func_00172558(BD_VALUE* bd) {
    YS__OBJ__is_exist(*(u8**)((u8*)bd[0].p + 4));
    bd->i = test(*(u32*)(*(u8**)((u8*)bd[0].p + 4) + 352), 0x4000);
}
void func_001725a0(BD_VALUE* bd) asm("func_001725a0");
void func_001725a0(BD_VALUE* bd) { bd->i = *(s32*)(*(u8**)((u8*)bd[0].p + 4) + 344); }
}  // namespace g00172528

// ---- 001725b8 from src/ys/traps.cpp
namespace n001725b8 {
u32 func_00180d40(u32, u32, u32, u32) asm("func_00180d40");
u32 trap_obj_motion_capture_id(u32 a0, u32 a1, u32 a2, u32 a3)
    asm("_ZN2YS26trap_obj_motion_capture_idEP8BD_VALUE");
u32 trap_obj_motion_capture_id(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00180d40(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 320u), *(u32*)(a0 + 4u), a2, a3);
}
}  // namespace n001725b8

// ---- 001725e0 gap
namespace g001725e0 {
void func_00180d88(u8*, s32) asm("func_00180d88");
void func_001725e0(BD_VALUE* bd) asm("func_001725e0");
void func_001725e0(BD_VALUE* bd) { func_00180d88(*(u8**)((u8*)bd[0].p + 4) + 320, bd[1].i); }
s32 func_0016abf8(u8*, s32, s32, s32) asm("func_0016abf8");
void func_00172608(BD_VALUE* bd) asm("func_00172608");
void func_00172608(BD_VALUE* bd) { bd->i = func_0016abf8(*(u8**)((u8*)bd[0].p + 4), bd[1].i, bd[2].i, bd[3].i); }
}  // namespace g001725e0

// ---- 00172648 from src/anon/tiny_auto80_solver.cpp
namespace n00172648 {
u32 func_0016ac80(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0016ac80jjjjjjjj");
u32 func_00172648(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00172648jjjjjjjj");
u32 func_00172648(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 vtable = *(u32*)a0;
    u32 v0 = func_0016ac80(*(u32*)(vtable + 4), *(u32*)(a0 + 4), *(u32*)(s0 + 8), *(u32*)(s0 + 12), *(u32*)(s0 + 16), a5, a6, a7);
    *(u32*)s0 = v0;
    return v0;
}
}  // namespace n00172648

// ---- 00172688 from src/anon/tiny_auto80_solver.cpp
namespace n00172688 {
u32 func_0016ac38(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0016ac38jjjjjjjj");
u32 func_00172688(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00172688jjjjjjjj");
u32 func_00172688(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 vtable = *(u32*)a0;
    u32 v0 = func_0016ac38(*(u32*)(vtable + 4), *(u32*)(a0 + 4), *(u32*)(s0 + 8), *(u32*)(s0 + 12), 0, a5, a6, a7);
    *(u32*)s0 = v0;
    return v0;
}
}  // namespace n00172688

// ---- 001726c8 from src/anon/tiny_auto80_solver.cpp
namespace n001726c8 {
u32 func_0016ac38(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0016ac38jjjjjjjj");
u32 func_001726c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001726c8jjjjjjjj");
u32 func_001726c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 8);
    u32 vtable = *(u32*)a0;
    u32 v0 = func_0016ac38(*(u32*)(vtable + 4), *(u32*)(s0 + 4), *(u32*)(s0 + 12), *(u32*)(s0 + 16), *(u32*)(p + 4), a5, a6, a7);
    *(u32*)s0 = v0;
    return v0;
}
}  // namespace n001726c8

// ---- 00172710 from src/ys/traps.cpp
namespace n00172710 {
u32 func_001de508(u32, u32, u32, u32) asm("func_001de508");
u32 trap_obj_effect_unbind(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS22trap_obj_effect_unbindEP8BD_VALUE");
u32 trap_obj_effect_unbind(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001de508(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 128u), *(u32*)(a0 + 4u), a2, a3);
}
}  // namespace n00172710

// ---- 00172738 gap
namespace g00172738 {
void func_001de450(u8*) asm("func_001de450");
void func_00172738(BD_VALUE* bd) asm("func_00172738");
void func_00172738(BD_VALUE* bd) { func_001de450(*(u8**)((u8*)bd[0].p + 4) + 128); }
}  // namespace g00172738

// ---- 00172758 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00172758 {
u32 func_001b1328(u32, u32, u32, u32) asm("_Z13func_001b1328jjjj");
u32 func_00172758(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00172758jjjj");
u32 func_00172758(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(4));
    r14 = *(u32*)((u32)r4 + (s32)(0));
    r5 = *(u32*)((u32)r15 + (s32)(4));
    r4 = *(u32*)((u32)r14 + (s32)(4));
    r2 = func_001b1328(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n00172758

// ---- 00172790 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00172790 {
u32 func_001b1100(u32, u32, u32, u32) asm("_Z13func_001b1100jjjj");
u32 func_00172790(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00172790jjjj");
u32 func_00172790(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r5 = *(u32*)((u32)r4 + (s32)(4));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = func_001b1100(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n00172790

// ---- 001727c8 from src/anon/batch_w23.cpp
namespace n001727c8 {
void func_001b0798(void*, void*, s32, f32) asm("func_001b0798");
void func_001727c8(u8** p) asm("func_001727c8");
void func_001727c8(u8** p) {
    func_001b0798(*(u8**)(p[0] + 4) + 1184, *(void**)(p[1] + 4), 1, *(f32*)(p + 2));
}
}  // namespace n001727c8

// ---- 00172800 gap
namespace g00172800 {
void func_001b0728(u8*, s32, s32, f32) asm("func_001b0728");
void func_00172800(BD_VALUE* bd) asm("func_00172800");
void func_00172800(BD_VALUE* bd) {
    s32 v = bd[1].i;
    func_001b0728(*(u8**)((u8*)bd[0].p + 4) + 1184, v, 1, bd[2].f);
}
}  // namespace g00172800

// ---- 00172830 from src/anon/batch_w1.cpp
namespace n00172830 {
void func_001b0700(void*, f32) asm("func_001b0700");
void func_00172830(BD_VALUE* bd) asm("func_00172830");
void func_00172830(BD_VALUE* bd) {
    func_001b0700(*(u8**)((u8*)bd[0].p + 4) + 1184, bd[1].f);
}
}  // namespace n00172830

// ---- 00172858 gap
namespace g00172858 {
s32 func_00184eb8(u8*, s32, s32) asm("func_00184eb8");
void func_00172858(BD_VALUE* bd) asm("func_00172858");
void func_00172858(BD_VALUE* bd) { bd->i = func_00184eb8(*(u8**)((u8*)bd[0].p + 4), bd[1].i, 0); }
}  // namespace g00172858

// ---- 00172890 from src/anon/batch_w28.cpp
namespace n00172890 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void func_001850a0(Q16*, u32) asm("func_001850a0");
extern Q16 D_01c5f480 asm("D_01c5f480");
void func_00172890(u8** p) asm("func_00172890");
void func_00172890(u8** p) {
    Q16 t;
    func_001850a0(&t, *(u32*)(*p + 4));
    if (&t != &D_01c5f480) QCOPY(&D_01c5f480, &t);
    *p = (u8*)&D_01c5f480;
}
}  // namespace n00172890

// ---- 001728e0 from src/anon/tiny_auto80_queue.cpp
namespace n001728e0 {
u32 func_0016a020(...) asm("func_0016a020");
u32 func_0016ace0(...) asm("func_0016ace0");
u32 YS__UNIT_GROUP__RandomPosPlayer(...) asm("YS__UNIT_GROUP__RandomPosPlayer");
void func_001728e0(u32 a0) asm("_Z13func_001728e0j");
void func_001728e0(u32 a0) {
    struct {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } spv;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 s0 = *(u32*)((u32)t7 + (s32)(4));
    u32 v0 = func_0016a020(s0);
    void (*call)(u32, u32) = (void(*)(u32, u32))YS__UNIT_GROUP__RandomPosPlayer;
    call((u32)&spv, v0);
    func_0016ace0(s0, (u32)&spv);
}
}  // namespace n001728e0

// ---- 00172928 from src/anon/batch_w218.cpp
namespace n00172928 {
struct V4 { f32 a,b,c,d; };
struct T218 { u32* o; u32 z; f32 x, y; };
u32 func_0016a020(u32) asm("func_0016a020");
void func_0019b0e8(V4*, u32, u32, f32, f32) asm("func_0019b0e8");
void func_0016ace0(u32, V4*) asm("func_0016ace0");
void func_00172928(T218* t) asm("func_00172928");
void func_00172928(T218* t) {
    u32 s = t->o[1];
    V4 v;
    u32 q = func_0016a020(s);
    u32 z = t->z;
    func_0019b0e8(&v, q, z, t->x, t->y);
    func_0016ace0(s, &v);
}
}  // namespace n00172928

// ---- 00172988 gap
namespace g00172988 {
void func_00172988(BD_VALUE* bd) asm("func_00172988");
void func_00172988(BD_VALUE* bd) {
    u8* o = *(u8**)((u8*)bd[0].p + 4);
    *(u32*)(o + 1536) = (*(u32*)(o + 1536) & ~0x78) | ((bd[1].i & 0xf) << 3);
}
void func_001729b8(BD_VALUE* bd) asm("func_001729b8");
void func_001729b8(BD_VALUE* bd) {
    bd->i = *(u16*)(*(u8**)(*(u8**)(*(u8**)((u8*)bd[0].p + 4) + 2072) + 8) + 2);
}
}  // namespace g00172988

// ---- 001729d8 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001729d8 {
extern "C" u32 YS_OBJ_get_unit_arg(u32, u32, u32, u32) asm("_ZN2YS3OBJ12get_unit_argEi");
u32 func_001729d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001729d8jjjj");
u32 func_001729d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r5 = *(u32*)((u32)r4 + (s32)(4));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = YS_OBJ_get_unit_arg(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001729d8

// ---- 00172a10 from src/anon/batch_w21.cpp
namespace n00172a10 {
void YS__OBJ__is_exist(u32) asm("YS__OBJ__is_exist");
void func_0016c018(u32, u32, u32) asm("func_0016c018");
void func_00172a10(u32* p) asm("func_00172a10");
void func_00172a10(u32* p) {
    if (p[0]) YS__OBJ__is_exist(*(u32*)(p[0] + 4));
    func_0016c018(*(u32*)(p[0] + 4), p[1], p[2]);
}
}  // namespace n00172a10

// ---- 00172a50 gap
namespace g00172a50 {
void func_00172a50(BD_VALUE* bd) asm("func_00172a50");
void func_00172a50(BD_VALUE* bd) {
    u8* m = *(u8**)(*(u8**)((u8*)bd[0].p + 4) + 2072);
    bd->i = !m || (*(u32*)(m + 4) & 8);
}
}  // namespace g00172a50

// ---- 00172a80 from src/anon/batch_w46.cpp
namespace n00172a80 {
struct Fl172 { u32 pad; u32 on : 1; };
void func_0019ae60(u8*) asm("func_0019ae60");
void func_0019a1a0(u8*, u32) asm("func_0019a1a0");
void func_00172a80(u8*** p) asm("func_00172a80");
void func_00172a80(u8*** p) {
    Fl172* o = *(Fl172**)((*p)[1] + 2072);
    if (o && !(u8)o->on) {
        func_0019ae60((u8*)o);
        func_0019a1a0((u8*)o, 0);
    }
}
}  // namespace n00172a80

// ---- 00172ae0 from src/anon/batch_w29.cpp
namespace n00172ae0 {
typedef u32 (*VFn4)(void*, u32, u32, u32);
u32 trap_obj_add_hp(u32* v) asm("_ZN2YS15trap_obj_add_hpEP8BD_VALUE");
u32 trap_obj_add_hp(u32* v) {
    void* o = *(void**)(v[0] + 4);
    return v[0] = (*(VFn4*)((*(u8**)o) + 120))(o, v[1], v[2], v[3] != 0);
}
}  // namespace n00172ae0

// ---- 00172b28 from src/ys/traps.cpp
namespace n00172b28 {
extern void YS_BTLOBJ_dead(void*) asm("_ZN2YS6BTLOBJ4deadEv");
void trap_obj_dead(BD_VALUE* bd) asm("_ZN2YS13trap_obj_deadEP8BD_VALUE");
void trap_obj_dead(BD_VALUE* bd) { YS_BTLOBJ_dead(*(void**)((char*)bd->i + 4)); }
}  // namespace n00172b28

// ---- 00172b48 gap
namespace g00172b48 {
void func_00172b48(BD_VALUE* bd) asm("func_00172b48");
static inline bool test(u32 v, u32 m) { return (v & m) != 0; }
void func_00172b48(BD_VALUE* bd) { bd->i = test(*(u32*)(*(u8**)((u8*)bd[0].p + 4) + 2040), 4); }
}  // namespace g00172b48

// ---- 00172b68 from src/ys/traps.cpp
namespace n00172b68 {
extern void YS_BTLOBJ_sys_dead(void*) asm("_ZN2YS6BTLOBJ8sys_deadEv");
void trap_obj_dead_mark(BD_VALUE* bd) asm("_ZN2YS18trap_obj_dead_markEP8BD_VALUE");
void trap_obj_dead_mark(BD_VALUE* bd) { YS_BTLOBJ_sys_dead(*(void**)((char*)bd->i + 4)); }
}  // namespace n00172b68

// ---- 00172b88 gap
namespace g00172b88 {
void func_00187728(u8*, f32) asm("func_00187728");
void func_00172b88(BD_VALUE* bd) asm("func_00172b88");
void func_00172b88(BD_VALUE* bd) { func_00187728(*(u8**)((u8*)bd[0].p + 4), bd[1].f); }
}  // namespace g00172b88

// ---- 00172ba8 from src/anon/batch_w7.cpp
namespace n00172ba8 {
u32 func_0016b740(u32) asm("func_0016b740");
void trap_obj_search_by_entry_impl(u32* bd) asm("_ZN2gm24trap_obj_search_by_entryEP8BD_VALUE");
void trap_obj_search_by_entry_impl(u32* bd) {
    u32* out = (u32*)bd[0];
    out[1] = func_0016b740(bd[1]);
}
}  // namespace n00172ba8

// ---- 00172bd8 from src/anon/batch_w8.cpp
namespace n00172bd8 {
u32 func_0016b7a0(u32) asm("func_0016b7a0");
void trap_obj_search_by_serial(u32* p) asm("_ZN2YS25trap_obj_search_by_serialEP8BD_VALUE");
void trap_obj_search_by_serial(u32* p) {
    u32* r = (u32*)p[0];
    r[1] = func_0016b7a0(p[1]);
}
}  // namespace n00172bd8

// ---- 00172c08 from src/anon/batch_w9.cpp
namespace n00172c08 {
u32 func_0016b800(u32) asm("func_0016b800");
void trap_obj_search_by_part(u32* v) asm("_ZN2YS23trap_obj_search_by_partEP8BD_VALUE");
void trap_obj_search_by_part(u32* v) {
    u8* out = (u8*)v[0];
    u32 r = func_0016b800(v[1]);
    *(u32*)(out + 4) = r;
}
}  // namespace n00172c08

// ---- 00172c38 from src/anon/batch_w43.cpp
namespace n00172c38 {
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
s32 func_0016c008(u8*, u32) asm("func_0016c008");
void func_00172c38(u8* p) asm("func_00172c38");
void func_00172c38(u8* p) {
    u8* v = 0;
    while ((v = YS__OBJ__Each(v)) != 0) {
        if (func_0016c008(v, *(u32*)(p + 4)) == *(s32*)(p + 8)) break;
    }
    *(u8**)(*(u8**)p + 4) = v;
}
}  // namespace n00172c38

// ---- 00172ca0 gap
namespace g00172ca0 {
struct V4 { f32 x, y, z, w; };
extern s8 D_01c5f4b0 asm("D_01c5f4b0");
extern V4 D_01c5f4c0 asm("D_01c5f4c0");
void func_00175530(void) asm("func_00175530");
void func_002fd188(void (*)(void)) asm("func_002fd188");
u32 YS__OBJ__SearchByCamera(s32, V4*, s32) asm("YS__OBJ__SearchByCamera");
void func_00172ca0(BD_VALUE* bd) asm("func_00172ca0");
void func_00172ca0(BD_VALUE* bd) {
    if (D_01c5f4b0 == 0) {
        f32 z = 0.0f;
        D_01c5f4c0.x = z;
        D_01c5f4c0.y = z;
        D_01c5f4c0.z = 10000.0f;
        D_01c5f4c0.w = 1.0f;
        D_01c5f4b0 = 1;
        func_002fd188(func_00175530);
    }
    u8* d = (u8*)bd[0].p;
    *(u32*)(d + 4) = YS__OBJ__SearchByCamera(bd[1].i, &D_01c5f4c0, 0);
}
u32 func_0016b8b8_2(s32, s32, s32) asm("YS__OBJ__SearchByCamera");
void func_00172d40(BD_VALUE* bd) asm("func_00172d40");
void func_00172d40(BD_VALUE* bd) {
    u8* d = (u8*)bd[0].p;
    s32 v = bd[1].i;
    *(u32*)(d + 4) = func_0016b8b8_2(v, v, 0);
}
}  // namespace g00172ca0

// ---- 00172d78 from src/ys/traps.cpp
namespace n00172d78 {
extern s32 YS_OBJ_CountEntry(s32) asm("_ZN2YS3OBJ10CountEntryEj");
void trap_obj_count_entry(BD_VALUE* bd) asm("_ZN2YS20trap_obj_count_entryEP8BD_VALUE");
void trap_obj_count_entry(BD_VALUE* bd) { bd->i = YS_OBJ_CountEntry(bd->i); }
}  // namespace n00172d78

// ---- 00172da8 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00172da8 {
u32 YS__OBJ__Each(u32, u32, u32, u32) asm("_Z13YS__OBJ__Eachjjjj");
u32 func_00172da8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00172da8jjjj");
u32 func_00172da8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    r2 = YS__OBJ__Each(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n00172da8

// ---- 00172dd8 from src/anon/tiny_wrappers_more_alt.cpp
namespace n00172dd8 {
u32 YS__STDOBJ__start_camera(u32, u32, u32, u32) asm("_Z24YS__STDOBJ__start_camerajjjj");
u32 func_00172dd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00172dd8jjjj");
u32 func_00172dd8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 p0 = ((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u)));
    u32 p1 = ((u32)(*(u32*)((u32)(a0) + 4u)));
    u32 p2 = ((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 8u)))) + 4u)));
    u32 p3 = a3;
    return YS__STDOBJ__start_camera(p0, p1, p2, p3);
}
}  // namespace n00172dd8

// ---- 00172e08 gap
namespace g00172e08 {
void YS__STDOBJ__start_camera(u8*, s32, s32) asm("YS__STDOBJ__start_camera");
void func_00172e08(BD_VALUE* bd) asm("func_00172e08");
void func_00172e08(BD_VALUE* bd) { YS__STDOBJ__start_camera(*(u8**)((u8*)bd[0].p + 4), bd[1].i, 0); }
void func_00172e30(BD_VALUE* bd) asm("func_00172e30");
void func_00172e30(BD_VALUE* bd) { *(s32*)(*(u8**)((u8*)bd[0].p + 4) + 2760) = bd[1].i; }
}  // namespace g00172e08

// ---- 00172e48 from src/anon/batch_w18.cpp
namespace n00172e48 {
void YS__OBJ__is_exist(void*) asm("YS__OBJ__is_exist");
void func_00172e48(u8** p) asm("func_00172e48");
void func_00172e48(u8** p) {
    YS__OBJ__is_exist(*(void**)(p[0] + 4));
    *(u32*)p = *(u32*)(*(u8**)(p[0] + 4) + 2760);
}
}  // namespace n00172e48

// ---- 00172e88 from src/ys/traps.cpp
namespace n00172e88 {
extern void YS_PRIZE_CA_Appear(void*, s32) asm("_ZN2YS8PRIZE_CA6AppearEPNS_6BTLOBJEi");
void trap_obj_scatter_medal(BD_VALUE* bd) asm("_ZN2YS22trap_obj_scatter_medalEP8BD_VALUE");
void trap_obj_scatter_medal(BD_VALUE* bd) {
    YS_PRIZE_CA_Appear(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n00172e88

// ---- 00172ea8 from src/ys/traps.cpp
namespace n00172ea8 {
extern void YS_MICKEY_recov_holylight(void*) asm("_ZN2YS6MICKEY15recov_holylightEv");
void trap_obj_recov_holylight(BD_VALUE* bd) asm("_ZN2YS24trap_obj_recov_holylightEP8BD_VALUE");
void trap_obj_recov_holylight(BD_VALUE* bd) { YS_MICKEY_recov_holylight(*(void**)((char*)bd->i + 4)); }
}  // namespace n00172ea8

// ---- 00172ec8 gap
namespace g00172ec8 {
void func_00179f80(u8*) asm("func_00179f80");
void func_00172ec8(BD_VALUE* bd) asm("func_00172ec8");
void func_00172ec8(BD_VALUE* bd) { func_00179f80(*(u8**)((u8*)bd[0].p + 4)); }
void func_001879f0(s32) asm("func_001879f0");
void func_00172ee8(BD_VALUE* bd) asm("func_00172ee8");
void func_00172ee8(BD_VALUE* bd) { func_001879f0(bd[0].i); }
}  // namespace g00172ec8

// ---- 00172f00 from src/anon/batch_w6.cpp
namespace n00172f00 {
void func_00187a18(u32, u32, u32, u32, void*) asm("func_00187a18");
void func_00172f00(u32* p) asm("func_00172f00");
void func_00172f00(u32* p) {
    func_00187a18(p[0], p[1], p[2], p[3], p + 4);
}
}  // namespace n00172f00

// ---- 00172f30 gap
namespace g00172f30 {
struct Key { u8 a, b, c, d; u16 e, f, g; };
extern Key D_0032bae0 asm("D_0032bae0");
void func_00188490(s32, s32, f32) asm("func_00188490");
void func_00172f30(BD_VALUE* bd) asm("func_00172f30");
void func_00172f30(BD_VALUE* bd) { func_00188490(bd[0].i, 0, bd[1].f); }
void func_00172f50(BD_VALUE* bd) asm("func_00172f50");
void func_00172f50(BD_VALUE* bd) { bd->i = D_0032bae0.a; }
void func_00172f60(BD_VALUE* bd) asm("func_00172f60");
void func_00172f60(BD_VALUE* bd) { bd->i = D_0032bae0.b; }
void func_00172f70(BD_VALUE* bd) asm("func_00172f70");
void func_00172f70(BD_VALUE* bd) { bd->i = D_0032bae0.e; }
void func_00172f80(BD_VALUE* bd) asm("func_00172f80");
void func_00172f80(BD_VALUE* bd) { bd->i = D_0032bae0.f; }
void func_00172f90(BD_VALUE* bd) asm("func_00172f90");
void func_00172f90(BD_VALUE* bd) { bd->i = D_0032bae0.g; }
void func_00172fa0(BD_VALUE* bd) asm("func_00172fa0");
void func_00172fa0(BD_VALUE* bd) { bd->i = D_0032bae0.c; }
}  // namespace g00172f30

// ---- 00172fb0 from src/anon/batch_w1752_nsa.cpp
namespace n00172fb0 {
struct W1752Key { u8 a, b, c, d; u16 e, f, g; };
void AREA__MapJump(W1752Key*, u32, s32, s32, s32) asm("AREA__MapJump");
void YS__trap_area_jump(u8* p) asm("YS__trap_area_jump");
void YS__trap_area_jump(u8* p) {
    W1752Key s;
    u16 v = 0xffff;
    s.a = v; s.e = v; s.f = v; s.g = v;
    s.b = p[0]; s.c = p[4];
    AREA__MapJump(&s, *(u32*)(p + 8), 0, 0, 0);
}
}  // namespace n00172fb0

// ---- 00173008 from src/anon/batch_w51.cpp
namespace n00173008 {
struct Pad10 {
    u8 a, b, c;
    u16 d, e, f;
    Pad10() { u16 m = 0xffff; a = m; b = m; c = m; d = m; e = m; f = m; }
};
Pad10 func_00199718(u32, s32) asm("func_00199718");
void AREA__MapJump(Pad10*, u32, u32, u32, u32) asm("AREA__MapJump");
union U32x { u32 u; u16 h; u8 b; };
void YS__trap_area_setjump(U32x* p) asm("YS__trap_area_setjump");
void YS__trap_area_setjump(U32x* p) {
    Pad10 s;
    s = func_00199718(p[0].u, -1);
    AREA__MapJump(&s, p[1].u, 0, 0, 0);
}
}  // namespace n00173008

// ---- 00173088 gap
namespace g00173088 {
struct S { u8 pad[12]; u8 a, b, c; };
extern S D_0032bb30 asm("D_0032bb30");
void func_00173088(BD_VALUE* bd) asm("func_00173088");
void func_00173088(BD_VALUE* bd) {
    D_0032bb30.a = bd[0].i;
    D_0032bb30.b = bd[1].i;
    D_0032bb30.c = bd[2].i;
}
}  // namespace g00173088

// ---- 001730b0 from src/anon/tiny_auto80_queue.cpp
namespace n001730b0 {
f32 YS__AREADATA__GetCostRest() asm("_Z25YS__AREADATA__GetCostRestv");
void func_001730b0(u32 a0) asm("_Z13func_001730b0j");
void func_001730b0(u32 a0) {
    u32 s0 = a0;
    *(u32*)((u32)s0 + (s32)(0)) = (u32)(s32)((f32(*)(u32))YS__AREADATA__GetCostRest)(a0);
}
}  // namespace n001730b0

// ---- 001730e0 gap
namespace g001730e0 {
struct Key { u8 a, b, c, d; u16 e, f, g; };
extern Key D_0032bae0 asm("D_0032bae0");
extern Key D_0032bb00 asm("D_0032bb00");
void func_001730e0(BD_VALUE* bd) asm("func_001730e0");
void func_001730e0(BD_VALUE* bd) {
    D_0032bb00 = D_0032bae0;
    D_0032bb00.c++;
}
}  // namespace g001730e0

// ---- 00173120 from src/anon/tiny_auto80_queue.cpp
namespace n00173120 {
f32 func_001826f8(u32,u32,u32,u32,u32,u32,u32,u32) asm("_Z13func_001826f8jjjjjjjj");
void func_00173120(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00173120jjjjjjjj");
void func_00173120(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    f32 f0 = func_001826f8(a0, a1, a2, a3, a4, a5, a6, a7);
    *(volatile f32*)((u32)s0 + (s32)(0)) = f0;
}
}  // namespace n00173120

// ---- 00173148 gap
namespace g00173148 {
struct Key { u8 a, b, c, d; u16 e, f, g; };
extern Key D_0032bb00 asm("D_0032bb00");
extern Key D_0032bb10 asm("D_0032bb10");
extern u16 D_0032bb14 asm("D_0032bb14");
void func_00173148(BD_VALUE* bd) asm("func_00173148");
void func_00173148(BD_VALUE* bd) {
    u32 x = D_0032bb14;
    bool b = x > 50;
    if (b) return;
    D_0032bb00 = D_0032bb10;
    if (D_0032bb00.a != 17) return;
    D_0032bb00.c = 50;
    if ((D_0032bb00.b == 5 && D_0032bb00.g == 21) || (D_0032bb00.b == 8 && D_0032bb00.g == 22)) D_0032bb00.c = 55;
}
}  // namespace g00173148

// ---- 001731e0 from src/anon/auto80_199_queue.cpp
namespace n001731e0 {
void func_001731e0(u32* a0) asm("_Z13func_001731e0Pj");
void func_001731e0(u32* a0) {
    u32* s1 = a0;
    u32 s3 = *(u32*)(a0 + 0);
    u32 s2 = *(u32*)(s1 + 1);

    u32 s0 = func_001050d8(2924);
    func_001ad0f8(s0, s3, s2);

    u32 v0 = func_001050d8(28);
    func_001ac7c8(v0, s0);

    *s1 = s0;
}
}  // namespace n001731e0

// ---- 00173258 gap
namespace g00173258 {
void func_00173258(BD_VALUE* bd) asm("func_00173258");
void func_00173258(BD_VALUE* bd) { bd->i = *(s32*)((u8*)bd[0].p + 112) == 3; }
}  // namespace g00173258

// ---- 00173270 from src/anon/batch_w2.cpp
namespace n00173270 {
typedef void (*MsgFn)(void*);
void method_message_is_end(BD_VALUE* v) asm("_ZN2YS21method_message_is_endEP8BD_VALUE");
void method_message_is_end(BD_VALUE* v) {
    void* o = v[0].p;
    (*(MsgFn*)((*(u8**)o) + 32))(o);
}
}  // namespace n00173270

// ---- 00173298 from src/ys/traps.cpp
namespace n00173298 {
extern void dk_Map_setHideGroup(s32) asm("_ZN2dk3Map12setHideGroupEj");
void trap_bg_hide(BD_VALUE* bd) asm("_ZN2gb12trap_bg_hideEP8BD_VALUE");
void trap_bg_hide(BD_VALUE* bd) { dk_Map_setHideGroup(bd->i); }
}  // namespace n00173298

// ---- 001732b0 from src/ys/traps.cpp
namespace n001732b0 {
extern void dk_Map_setVisibleGroup(s32) asm("_ZN2dk3Map15setVisibleGroupEj");
void trap_bg_show(BD_VALUE* bd) asm("_ZN2gb12trap_bg_showEP8BD_VALUE");
void trap_bg_show(BD_VALUE* bd) { dk_Map_setVisibleGroup(bd->i); }
}  // namespace n001732b0

// ---- 001732c8 from src/anon/batch_w13.cpp
namespace n001732c8 {
u32 func_001a7588(u32, u32, u32, u32) asm("func_001a7588");
void trap_bg_cross_pos(u32*) asm("_ZN2YS17trap_bg_cross_posEP8BD_VALUE");
void trap_bg_cross_pos(u32* v) {
    u32 c = v[2];
    u32 b = v[1];
    v[0] = func_001a7588(v[0], b, c, v[3]);
}
}  // namespace n001732c8

// ---- 00173300 from src/anon/tiny_auto80_queue.cpp
namespace n00173300 {
u32 func_00143f28(...) asm("func_00143f28");
u32 func_00173300(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00173300jjjj");
u32 func_00173300(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 v0 = 0u;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 s0 = a0;
    if ((s32)t7 >= 0) {
        a0 = *(u16*)((u32)a0 + (s32)(0));
        v0 = func_00143f28(a0, 0u, a2, a3);
        v0 = (u32)(v0 ^ 1u);
        v0 = (u32)(v0 < 1u);
    }
    *(u32*)((u32)s0 + (s32)(0)) = v0;
    return v0;
}
}  // namespace n00173300

// ---- 00173348 from src/anon/batch_w39.cpp
namespace n00173348 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
extern s8 D_01c5f4d0 asm("D_01c5f4d0");
extern Vec4 D_01c5f4e0 asm("D_01c5f4e0");
void func_00175538(void) asm("func_00175538");
void func_002fd188(void (*)(void)) asm("func_002fd188");
Vec4 func_00143e50(u16, int) asm("func_00143e50");
void func_00173348(void* p) asm("func_00173348");
void func_00173348(void* p) {
    if (!D_01c5f4d0) {
        D_01c5f4d0 = 1;
        func_002fd188(func_00175538);                     
    }
    D_01c5f4e0 = func_00143e50(*(u16*)p, 0);
    *(Vec4**)p = &D_01c5f4e0;
}
}  // namespace n00173348

// ---- 001733b8 from src/anon/tiny_auto80_queue.cpp
namespace n001733b8 {
u32 func_001a7610(u32, u32, u32, f32, f32) asm("_Z13func_001a7610jjjff");
u32 func_001733b8(u32 a0) asm("_Z13func_001733b8j");
u32 func_001733b8(u32 a0) {
    u32 s0 = a0;
    volatile u32* p = (volatile u32*)(u32)a0;
    u32 a1 = p[1];
    volatile float* pf = (volatile float*)(u32)s0;
    float f0 = pf[2];
    u32 v0 = func_001a7610(*(u32*)((u32)a0 + (s32)(0)), a1, (u32)(4u), f0, 0.0f);
    *(u32*)((u32)s0 + (s32)(0)) = v0;
    return v0;
}
}  // namespace n001733b8

// ---- 001733f8 from src/anon/batch_w1757.cpp
namespace n001733f8 {
struct W1757V3 { f32 x, y, z; };
struct W1757Timer {
    u8 pad[4];
    s32 cnt;
    W1757V3 p;
};
struct W1757V4 { f32 x, y, z, w; };
extern W1757V4 D_00350990 asm("D_00350990");
u32 func_001024a8(...) asm("func_001024a8");
void func_001733f8(W1757Timer* o) asm("func_001733f8");
void func_001733f8(W1757Timer* o) {
    if (o->cnt-- > 0) return;
    f32 x = o->p.x, y = o->p.y, z = o->p.z;
    D_00350990.x = x;
    D_00350990.y = y;
    D_00350990.z = z;
    D_00350990.w = 0.0f;
    func_001024a8(o);
}
}  // namespace n001733f8

// ---- 00173450 from src/anon/auto80_199_queue.cpp
namespace n00173450 {
u32 func_00173450(u32 a0) asm("_Z13func_00173450j");
u32 func_00173450(u32 a0) {
    u32 s0 = a0;
    u32 a2 = (u32)func_001733f8;
    u32 a1 = 14002;
    u32 v0 = func_00102c18(1, a1, a2);

    *(u32*)(v0 + 4) = 1;

    volatile u32* vp = (volatile u32*)s0;
    f32 f0;

    {
        u32 t6 = vp[0];
        f0 = *(f32*)(t6 + 0);
        *(volatile f32*)(v0 + 8) = f0;
    }

    {
        u32 t7 = vp[0];
        f0 = *(f32*)(t7 + 4);
        *(volatile f32*)(v0 + 12) = f0;
    }

    {
        u32 t7 = vp[0];
        f0 = *(f32*)(t7 + 8);
        *(volatile f32*)(v0 + 16) = f0;
    }

    return v0;
}
}  // namespace n00173450

// ---- 001734b0 from src/anon/auto80_199_queue.cpp
namespace n001734b0 {
u32 func_001734b0(u32 a0) asm("_Z13func_001734b0j");
u32 func_001734b0(u32 a0) {
    u32 s0 = a0;
    s32 t7 = *(s32*)(a0 + 4);
    s32 t6 = t7;
    t7 = t7 - 1;
    *(s32*)(a0 + 4) = t7;

    if (t6 > 0) {
        return;
    }

    u32 v0 = func_0015ef38();
    func_0011e9a8(v0, 2, 0, 0, *(f32*)(s0 + 8));
    return func_001024a8(s0);
}
}  // namespace n001734b0

// ---- 00173518 from src/anon/batch_w22.cpp
namespace n00173518 {
void func_001734b0(void) asm("func_001734b0");
u8* func_00102c18(u32, u32, void (*)(void)) asm("func_00102c18");
struct T173 { u32 pad; f32 a; f32 b; };
void func_00173518(f32* p) asm("func_00173518");
void func_00173518(f32* p) {
    T173* t = (T173*)func_00102c18(1, 14002, func_001734b0);
    t->a = 0;
    t->b = *p;
}
}  // namespace n00173518

// ---- 00173558 from src/anon/batch_w31.cpp
namespace n00173558 {
extern u8 D_01c5f480[] asm("D_01c5f480");
void func_001a7888(void*, u32, int, f32, f32) asm("func_001a7888");
struct Elem64 { u8 d[64]; ~Elem64() {} } __attribute__((aligned(16)));
void func_00173558(u8* p) asm("func_00173558");
void func_00173558(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    func_001a7888(tmp, *(u32*)p, 1, *(f32*)(p + 4), *(f32*)(p + 8));
    u8* d = D_01c5f480;
    if ((u8*)tmp != d) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    }
    *(u8**)p = d;
}
}  // namespace n00173558

// ---- 001735b0 from src/anon/batch_w31.cpp
namespace n001735b0 {
extern u8 D_01c5f480[] asm("D_01c5f480");
void* func_001a78c0(void*, u32, int, f32, f32, f32, f32) asm("func_001a78c0");
struct Elem64 { u8 d[64]; ~Elem64() {} } __attribute__((aligned(16)));
void func_001735b0(u8* p) asm("func_001735b0");
void func_001735b0(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    func_001a78c0(tmp, *(u32*)p, 2, *(f32*)(p + 4), *(f32*)(p + 8), *(f32*)(p + 12), *(f32*)(p + 16));
    u8* d = D_01c5f480;
    if ((u8*)tmp != d) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    }
    *(u8**)p = d;
}
}  // namespace n001735b0

// ---- 00173610 from src/ys/traps.cpp
namespace n00173610 {
extern void dk_Map_setAnimationSpeedRatio(s32, f32) asm("_ZN2dk3Map22setAnimationSpeedRatioEN2kn13AnimationWork4TYPEEf");
void trap_bg_set_animation_speed(BD_VALUE* bd) asm("_ZN2YS27trap_bg_set_animation_speedEP8BD_VALUE");
void trap_bg_set_animation_speed(BD_VALUE* bd) { dk_Map_setAnimationSpeedRatio(2, bd->f); }
}  // namespace n00173610

// ---- 00173630 gap
namespace g00173630 {
void func_001991a8(s32, s32) asm("func_001991a8");
void func_00173630(BD_VALUE* bd) asm("func_00173630");
void func_00173630(BD_VALUE* bd) { func_001991a8(bd[0].i, bd[1].i); }
void func_0019b478(void) asm("func_0019b478");
void func_00173650(BD_VALUE* bd) asm("func_00173650");
void func_00173650(BD_VALUE* bd) { func_0019b478(); }
void func_00182bc0(s32) asm("func_00182bc0");
void func_00173668(BD_VALUE* bd) asm("func_00173668");
void func_00173668(BD_VALUE* bd) { func_00182bc0(bd[0].i); }
}  // namespace g00173630

// ---- 00173680 from src/ys/traps.cpp
namespace n00173680 {
u32 func_0019eb60(u32, u32, u32, u32) asm("func_0019eb60");
u32 func_area_activate_unit(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS23func_area_activate_unitEP8BD_VALUE");
u32 func_area_activate_unit(u32 a0, u32 a1, u32 a2, u32 a3) { return func_0019eb60(a0, a1, a2, a3); }
}  // namespace n00173680

// ---- 00173698 gap
namespace g00173698 {
static inline bool busy(u8* o) { return (*(u32*)(*(u8**)(o + 12) + 8) & 1); }
void func_0019ebc0(void) asm("func_0019ebc0");
void func_00173698(BD_VALUE* bd) asm("func_00173698");
void func_00173698(BD_VALUE* bd) { func_0019ebc0(); }
void func_0019f610(u8*, s32, s32) asm("func_0019f610");
void func_001736b0(BD_VALUE* bd) asm("func_001736b0");
void func_001736b0(BD_VALUE* bd) {
    u8* o = *(u8**)((u8*)bd[0].p + 4) + 1044;
    func_0019f610(o, bd[1].i, bd[2].i);
}
void func_0019f670(u8*, s32, s32) asm("func_0019f670");
void func_001736e0(BD_VALUE* bd) asm("func_001736e0");
void func_001736e0(BD_VALUE* bd) {
    u8* o = *(u8**)((u8*)bd[0].p + 4) + 1044;
    func_0019f670(o, bd[1].i, bd[2].i);
}
void func_0019f6c8(u8*, s32, s32) asm("func_0019f6c8");
void func_00173710(BD_VALUE* bd) asm("func_00173710");
void func_00173710(BD_VALUE* bd) {
    u8* o = *(u8**)((u8*)bd[0].p + 4) + 1044;
    func_0019f6c8(o, bd[1].i, bd[2].i);
}
void func_0019f490(u8*, s32) asm("func_0019f490");
void func_00173740(BD_VALUE* bd) asm("func_00173740");
void func_00173740(BD_VALUE* bd) { func_0019f490(*(u8**)((u8*)bd[0].p + 4) + 1148, bd[1].i); }
void func_0019f4b8(u8*, s32) asm("func_0019f4b8");
void func_00173768(BD_VALUE* bd) asm("func_00173768");
void func_00173768(BD_VALUE* bd) { func_0019f4b8(*(u8**)((u8*)bd[0].p + 4) + 1148, bd[1].i); }
void func_0019f4e8(u8*, s32) asm("func_0019f4e8");
void func_00173790(BD_VALUE* bd) asm("func_00173790");
void func_00173790(BD_VALUE* bd) { func_0019f4e8(*(u8**)((u8*)bd[0].p + 4) + 1148, bd[1].i); }
s32 func_0019c410(u8*) asm("func_0019c410");
void func_001737b8(BD_VALUE* bd) asm("func_001737b8");
void func_001737b8(BD_VALUE* bd) { bd->i = func_0019c410(*(u8**)((u8*)bd[0].p + 4)); }
void func_001737e8(BD_VALUE* bd) asm("func_001737e8");
void func_001737e8(BD_VALUE* bd) { bd->i = *(u32*)(*(u8**)(*(u8**)((u8*)bd[0].p + 4) + 12) + 8) & 1; }
}  // namespace g00173698

// ---- 00173808 from src/anon/batch_w11.cpp
namespace n00173808 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
struct P173 { u8** a; Q16* q; f32 f; };
void func_0019fdc0(u8*, Q16*, f32) asm("func_0019fdc0");
void func_00173808(P173* p) asm("func_00173808");
void func_00173808(P173* p) {
    Q16 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(p->q) : "$8", "memory");
    func_0019fdc0(p->a[1], &t, p->f);
}
}  // namespace n00173808

// ---- 00173840 gap
namespace g00173840 {
struct Ctl { u8 pad[8]; u32 flags; };
struct Obj { u8 pad0[0xc]; Ctl* ctl; u8 pad10[0x160 - 0x10]; u32 flags160; };
static inline bool CtlBusy(Obj* o) { return (o->ctl->flags & 2) || (o->flags160 & 0x40); }
void func_00173840(BD_VALUE* bd) asm("func_00173840");
void func_00173840(BD_VALUE* bd) { bd->i = CtlBusy(*(Obj**)((u8*)bd[0].p + 4)); }
}  // namespace g00173840

// ---- 00173878 from src/anon/batch_w1775.cpp
namespace n00173878 {
struct W1775Ctl { u8 pad[8]; u32 flags; };
struct W1775Obj { u8 pad0[0xc]; W1775Ctl* ctl; u8 pad10[0x160 - 0x10]; u32 flags160; };
struct W1775Hold { u8 pad[4]; W1775Obj* obj; };
struct W1775Self { W1775Hold* h; };
void YS__OBJ__is_exist(W1775Obj*) asm("YS__OBJ__is_exist");
s32 func_0019c090(W1775Obj*) asm("func_0019c090");
static inline bool W1775_CtlBusy(W1775Obj* o) { return (o->ctl->flags & 2) || (o->flags160 & 0x40); }
static inline bool W1775_Busy(W1775Obj* o) { bool r = false; if (func_0019c090(o) || W1775_CtlBusy(o)) r = true; return r; }
void YS__trap_obj_is_air(W1775Self* s) asm("YS__trap_obj_is_air");
void YS__trap_obj_is_air(W1775Self* s) {
    if (s->h) YS__OBJ__is_exist(s->h->obj);
    W1775Obj* o = s->h->obj;
    *(u32*)s = W1775_Busy(o);
}
}  // namespace n00173878

// ---- 00173918 from src/anon/batch_w41.cpp
namespace n00173918 {
typedef unsigned int u128 __attribute__((mode(TI)));
extern s8 D_01c5f4f0 asm("D_01c5f4f0");
extern u128 D_01c5f500 asm("D_01c5f500");
void func_00175540(void) asm("func_00175540");
void func_002fd188(void (*)(void)) asm("func_002fd188");
void func_00173918(u8** p) asm("func_00173918");
void func_00173918(u8** p) {
                                                 
    if (!D_01c5f4f0) {
        D_01c5f4f0 = 1;
        func_002fd188(func_00175540);                     
    }
    u8* s = *(u8**)(p[0] + 4) + 2144;
    if ((u128*)s != &D_01c5f500)
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&D_01c5f500), "r"(s) : "$8", "memory");
    *p = (u8*)&D_01c5f500;
}
}  // namespace n00173918

// ---- 00173980 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00173980 {
u32 func_00180618(u32, u32, u32, u32) asm("_Z13func_00180618jjjj");
u32 func_00173980(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00173980jjjj");
u32 func_00173980(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r4 = (u32)((s32)r4 + (320));
    r2 = func_00180618(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n00173980

// ---- 001739b8 from src/anon/batch_w42.cpp
namespace n001739b8 {
typedef unsigned int u128 __attribute__((mode(TI)));
extern s8 D_01c5f510 asm("D_01c5f510");
extern u128 D_01c5f520 asm("D_01c5f520");
extern u8 D_00175548[] asm("D_00175548");
void func_002fd188(void*) asm("func_002fd188");
void func_001739b8(u128** out) asm("func_001739b8");
void func_001739b8(u128** out)
{
    if (!D_01c5f510) {
        D_01c5f510 = 1;
        func_002fd188(D_00175548);                     
    }
    u128* src = (u128*)(*(u8**)((u8*)*out + 4) + 2128);
    u128* dst = &D_01c5f520;
    if (src != dst) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    *out = dst;
}
}  // namespace n001739b8

// ---- 00173a20 gap
namespace g00173a20 {
void func_00173a20(BD_VALUE* bd) asm("func_00173a20");
void func_00173a20(BD_VALUE* bd) { *(u32*)(*(u8**)((u8*)bd[0].p + 4) + 264) |= 0x4000000; }
void func_00173a40(BD_VALUE* bd) asm("func_00173a40");
void func_00173a40(BD_VALUE* bd) { *(u32*)(*(u8**)((u8*)bd[0].p + 4) + 264) |= 0x8000000; }
}  // namespace g00173a20

// ---- 00173a60 from src/anon/tiny_auto80_queue.cpp
namespace n00173a60 {
f32 YS__MOTION__get_length(u32, int) asm("_Z22YS__MOTION__get_lengthji");
void func_00173a60(u32 a0) asm("_Z13func_00173a60j");
void func_00173a60(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 a1 = *(u32*)((u32)a0 + (s32)(4));
    a0 = *(u32*)((u32)t7 + (s32)(4));
    f32 f0 = YS__MOTION__get_length((u32)((s32)a0 + (320)), a1);
    *(f32*)((u32)s0 + (s32)(0)) = f0;
}
}  // namespace n00173a60

// ---- 00173a98 from src/anon/tiny_auto80_queue.cpp
namespace n00173a98 {
u32 func_00180770(...) asm("func_00180770");
void func_00173a98(u32 a0) asm("_Z13func_00173a98j");
void func_00173a98(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 a1 = *(u32*)((u32)a0 + (s32)(4));
    a0 = *(u32*)((u32)t7 + (s32)(4));
    f32 f0 = ((f32(*)(u32, u32))func_00180770)((u32)((s32)a0 + (320)), a1);
    *(f32*)((u32)s0 + (s32)(0)) = f0;
}
}  // namespace n00173a98

// ---- 00173ad0 gap
namespace g00173ad0 {
struct BS {
    u32 w[8];
    void set(u32 n) { u32* p = &w[n >> 5]; *p |= 1 << (n & 31); }
    void clr(u32 n) { u32* p = &w[n >> 5]; *p &= ~(1 << (n & 31)); }
    bool get(u32 n) { return (w[n >> 5] & (1 << (n & 31))) != 0; }
};
void func_00173ad0(BD_VALUE* bd) asm("func_00173ad0");
void func_00173ad0(BD_VALUE* bd) { bd->f = *(f32*)(*(u8**)((u8*)bd[0].p + 4) + 368); }
void func_00173ae8(BD_VALUE* bd) asm("func_00173ae8");
void func_00173ae8(BD_VALUE* bd) { ((BS*)(*(u8**)((u8*)bd[0].p + 4) + 264))->set(bd[1].i); }
void func_00173b20(BD_VALUE* bd) asm("func_00173b20");
void func_00173b20(BD_VALUE* bd) { ((BS*)(*(u8**)((u8*)bd[0].p + 4) + 264))->clr(bd[1].i); }
void func_00173b60(BD_VALUE* bd) asm("func_00173b60");
void func_00173b60(BD_VALUE* bd) { bd->i = ((BS*)(*(u8**)((u8*)bd[0].p + 4) + 264))->get(bd[1].i); }
}  // namespace g00173ad0

// ---- 00173b98 from src/ys/traps.cpp
namespace n00173b98 {
u32 func_0017ec30(u32, u32, u32, u32) asm("func_0017ec30");
u32 trap_obj_check_flag(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_obj_check_flagEP8BD_VALUE");
u32 trap_obj_check_flag(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0017ec30(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 320u), *(u32*)(a0 + 4u), a2, a3);
}
}  // namespace n00173b98

// ---- 00173bc0 gap
namespace g00173bc0 {
static inline bool test(u32 v, u32 m) { return (v & m) != 0; }
void func_0017ec80(u8*) asm("func_0017ec80");
void func_00173bc0(BD_VALUE* bd) asm("func_00173bc0");
void func_00173bc0(BD_VALUE* bd) { func_0017ec80(*(u8**)((u8*)bd[0].p + 4) + 320); }
void func_00173be0(BD_VALUE* bd) asm("func_00173be0");
void func_00173be0(BD_VALUE* bd) { bd->i = *(u32*)(*(u8**)((u8*)bd[0].p + 4) + 324) != 0; }
void func_00173bf8(BD_VALUE* bd) asm("func_00173bf8");
void func_00173bf8(BD_VALUE* bd) { bd->i = test(*(u32*)(*(u8**)((u8*)bd[0].p + 4) + 352), 0x200); }
}  // namespace g00173bc0

// ---- 00173c18 from src/ys/traps.cpp
namespace n00173c18 {
extern void YS_OBJ_set_dir(void*, s32) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");
void trap_obj_motion_is_hook(BD_VALUE* bd) asm("_ZN2YS23trap_obj_motion_is_hookEP8BD_VALUE");
void trap_obj_motion_is_hook(BD_VALUE* bd) {
    YS_OBJ_set_dir(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n00173c18

// ---- 00173c38 from src/anon/tiny_auto80_queue.cpp
namespace n00173c38 {
u32 YS__OBJ__turn_to_dir(...) asm("YS__OBJ__turn_to_dir");
void func_00173c38(u32 a0) asm("_Z13func_00173c38j");
void func_00173c38(u32 a0) {
    u32 s0 = a0;
    volatile u32* p = (volatile u32*)(u32)a0;
    u32 t7 = p[0];
    u32 a1 = p[1];
    volatile f32* pf = (volatile f32*)(u32)s0;
    f32 f12 = pf[2];
    u32 v0 = ((u32(*)(u32, u32, f32))YS__OBJ__turn_to_dir)(*(u32*)((u32)t7 + (s32)(4)), a1, f12);
    *(u32*)((u32)s0 + (s32)(0)) = v0;
}
}  // namespace n00173c38

// ---- 00173c70 from src/anon/auto80_199_queue.cpp
namespace n00173c70 {
void func_00173c70(u32 a0) asm("_Z13func_00173c70j");
void func_00173c70(u32 a0) {
    u32 s1 = a0;
    u32 t7 = *(u32*)(a0 + 0);
    u32 s0 = *(u32*)(a0 + 4);
    u32 s2 = *(u32*)(t7 + 4);

    if (s0 != 0) {
        func_0016cff0(*(u32*)(s2 + 1156), s0, s0);
    }

    u32 v0 = func_0016cfa0(*(u32*)(s2 + 1156), s0, *(u32*)(s1 + 8), s1 + 16, 1);
    *(u32*)(v0 + 36) = *(u32*)(s1 + 12);
    *(u32*)(s1 + 0) = v0;
}
}  // namespace n00173c70

// ---- 00173ce8 from src/anon/batch_w52.cpp
namespace n00173ce8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
} __attribute__((aligned(16)));
f32 YS__OBJ__get_bone_matrix(u32, u32, f32*) asm("YS__OBJ__get_bone_matrix");
#define MULV(m, v, out) asm volatile( \
    "lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t" \
    "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\t" \
    "vmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%2)" : : "r"(m), "r"(v), "r"(out) : "memory")
extern Vec4 D_01c5f480 asm("D_01c5f480");
struct Ref173 {
    u32* a;
    u32 b;
    Vec4* v;
};
void func_00173ce8(Ref173* p) asm("func_00173ce8");
void func_00173ce8(Ref173* p) {
    f32 m[16] __attribute__((aligned(16)));
    Vec4 t;
    YS__OBJ__get_bone_matrix(*(u32*)((u8*)p->a + 4), p->b, m);
    MULV(m, p->v, &t);
    if (&t != &D_01c5f480) QCOPY(&D_01c5f480, &t);
    p->a = (u32*)&D_01c5f480;
}
}  // namespace n00173ce8

// ---- 00173d68 gap
namespace g00173d68 {
void func_00173d68(BD_VALUE* bd) asm("func_00173d68");
void func_00173d68(BD_VALUE* bd) { bd->i = *(s32*)(*(u8**)((u8*)bd[0].p + 4) + 1164); }
}  // namespace g00173d68

// ---- 00173d80 from src/ys/traps.cpp
namespace n00173d80 {
extern void YS_OBJ_texanm_start(void*, s32) asm("_ZN2YS3OBJ12texanm_startEi");
void trap_obj_sheet(BD_VALUE* bd) asm("_ZN2YS14trap_obj_sheetEP8BD_VALUE");
void trap_obj_sheet(BD_VALUE* bd) { YS_OBJ_texanm_start(*(void**)((char*)bd->i + 4), bd[1].i); }
}  // namespace n00173d80

// ---- 00173da0 from src/ys/traps.cpp
namespace n00173da0 {
extern void YS_OBJ_texanm_stop(void*, s32) asm("_ZN2YS3OBJ11texanm_stopEi");
void trap_obj_texanm_stop(BD_VALUE* bd) asm("_ZN2YS20trap_obj_texanm_stopEP8BD_VALUE");
void trap_obj_texanm_stop(BD_VALUE* bd) {
    YS_OBJ_texanm_stop(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n00173da0

// ---- 00173dc0 from src/anon/batch_w29.cpp
namespace n00173dc0 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct E16 { u32 w[4]; ~E16() {} } __attribute__((aligned(16)));
void YS__OBJ__get_target_pos(Q16*, u32) asm("YS__OBJ__get_target_pos");
extern Q16 D_01c5f480 asm("D_01c5f480");
void func_00173dc0(u32* v) asm("func_00173dc0");
void func_00173dc0(u32* v) {
    Q16 t;
    YS__OBJ__get_target_pos(&t, *(u32*)(v[0] + 4));
    Q16* d = &D_01c5f480;
    if (d != &t) QCOPY(d, &t);
    v[0] = (u32)d;
}
}  // namespace n00173dc0

// ---- 00173e10 from src/anon/batch_w3.cpp
namespace n00173e10 {
void func_001846a0(u32, s32, f32) asm("func_001846a0");
void func_00173e10(BD_VALUE* bd) asm("func_00173e10");
void func_00173e10(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    s32 b = bd[1].i;
    u32 obj = ((u32*)a.p)[1];
    func_001846a0(obj, b, bd[2].f);
}
}  // namespace n00173e10

// ---- 00173e38 from src/anon/batch_w7.cpp
namespace n00173e38 {
void func_00188470(u32, u32, f32) asm("func_00188470");
void func_00173e38(u32* a0) asm("func_00173e38");
void func_00173e38(u32* a0) {
    func_00188470(*(u32*)(a0[0] + 4) + 768, a0[1], *(f32*)&a0[2]);
}
}  // namespace n00173e38

// ---- 00173e68 gap
namespace g00173e68 {
void func_00176a60(u8*, f32) asm("func_00176a60");
void func_00173e68(BD_VALUE* bd) asm("func_00173e68");
void func_00173e68(BD_VALUE* bd) { func_00176a60(*(u8**)((u8*)bd[0].p + 4), bd[1].f); }
}  // namespace g00173e68

// ---- 00173e88 from src/ys/traps.cpp
namespace n00173e88 {
extern s32 YS_PARTY_Get(s32) asm("_ZN2YS5PARTY3GetEi");
void trap_obj_star(BD_VALUE* bd) asm("_ZN2YS13trap_obj_starEP8BD_VALUE");
void trap_obj_star(BD_VALUE* bd) { bd->i = YS_PARTY_Get(bd->i); }
}  // namespace n00173e88

// ---- 00173eb8 from src/ys/traps.cpp
namespace n00173eb8 {
extern void YS_OBJ_fly_to_jump(void*) asm("_ZN2YS3OBJ11fly_to_jumpEv");
void trap_obj_fly_to_jump(BD_VALUE* bd) asm("_ZN2YS20trap_obj_fly_to_jumpEP8BD_VALUE");
void trap_obj_fly_to_jump(BD_VALUE* bd) { YS_OBJ_fly_to_jump(*(void**)((char*)bd->i + 4)); }
}  // namespace n00173eb8

// ---- 00173ed8 gap
namespace g00173ed8 {
void func_00173ed8(BD_VALUE* bd) asm("func_00173ed8");
void func_00173ed8(BD_VALUE* bd) { bd->i = *(s32*)(*(u8**)(*(u8**)((u8*)bd[0].p + 4) + 12) + 4); }
void func_00173ef0(BD_VALUE* bd) asm("func_00173ef0");
void func_00173ef0(BD_VALUE* bd) { bd->p = *(u8**)((u8*)bd[0].p + 4) + 272; }
}  // namespace g00173ed8

// ---- 00173f08 from src/anon/batch_w47.cpp
namespace n00173f08 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
Vec4* YS__OBJ__get_pos(void*) asm("YS__OBJ__get_pos");
union U173 { f32 f[4]; u32 u[4]; } __attribute__((aligned(16)));
extern U173 D_01c5f480 asm("D_01c5f480");
f32 func_00184a90(void*) asm("func_00184a90");
void YS__trap_obj_step_pos(u32* p) asm("YS__trap_obj_step_pos");
void YS__trap_obj_step_pos(u32* p) {
    U173* v = (U173*)YS__OBJ__get_pos(*(void**)(p[0] + 4));                          
    U173* d = &D_01c5f480;
    if (v != d) QCOPY(d, v);
    d->f[1] = func_00184a90(*(void**)(p[0] + 4));
    *p = (u32)d;
}
}  // namespace n00173f08

// ---- 00173f68 from src/anon/batch_w59.cpp
namespace n00173f68 {
f32 func_00184a90(u32) asm("func_00184a90");
f32* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
void YS__trap_obj_float_height(u8* p) asm("YS__trap_obj_float_height");
void YS__trap_obj_float_height(u8* p) {
    u32 o = *(u32*)(*(u8**)p + 4);
    f32 d = func_00184a90(o) - YS__OBJ__get_pos(o)[1];
    f32 v;
    if (0.0f < d) v = func_00184a90(o) - YS__OBJ__get_pos(o)[1];
    else v = 0.0f;
    *(f32*)p = -v;
}
}  // namespace n00173f68

// ---- 00173ff8 from src/anon/tiny_auto80_queue.cpp
namespace n00173ff8 {
f32 func_0017d130(f32) asm("_Z13func_0017d130f");
void func_00173ff8(u32 a0) asm("_Z13func_00173ff8j");
void func_00173ff8(u32 a0) {
    f32 f12 = *(f32*)((u32)a0 + (s32)(0));
    u32 s0 = a0;
    f32 f0 = func_0017d130(f12);                       
    *(f32*)((u32)s0 + (s32)(0)) = f0;
}
}  // namespace n00173ff8

// ---- 00174028 gap
namespace g00174028 {
void func_00174028(BD_VALUE* bd) asm("func_00174028");
void func_00174028(BD_VALUE* bd) { *(u32*)(*(u8**)((u8*)bd[0].p + 4) + 1896) |= 0x40; }
void func_00174040(BD_VALUE* bd) asm("func_00174040");
void func_00174040(BD_VALUE* bd) { *(u32*)(*(u8**)((u8*)bd[0].p + 4) + 1896) &= ~0x40; }
}  // namespace g00174028

// ---- 00174060 from src/anon/batch_w8.cpp
namespace n00174060 {
void func_00199468(u32, u32, f32, u32) asm("func_00199468");
struct S174060 { u32* obj; f32 f; u32 a; u32 b; };
void func_00174060(S174060* p) asm("func_00174060");
void func_00174060(S174060* p) {
    u32 b = p->b;
    u32 o = p->obj[1];
    func_00199468(o, p->a, p->f, b);
}
}  // namespace n00174060

// ---- 00174090 gap
namespace g00174090 {
void func_001994d8(u8*, s32, s32) asm("func_001994d8");
void func_00174090(BD_VALUE* bd) asm("func_00174090");
void func_00174090(BD_VALUE* bd) {
    u8* o = *(u8**)((u8*)bd[0].p + 4);
    func_001994d8(o, bd[1].i, bd[2].i);
}
}  // namespace g00174090

// ---- 001740b8 from src/anon/tiny_auto80.cpp
namespace n001740b8 {
u32 func_00198c28(u32, u32, u32, u32) asm("_Z13func_00198c28jjjj");
u32 func_001740b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001740b8jjjj");
u32 func_001740b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r5 = *(volatile u32*)((u32)r4 + (s32)(4));
    r4 = *(volatile u32*)((u32)r4 + (s32)(0));
    r2 = ((u32(*)(u32,u32,u32,u32))func_00198c28)(r4, r5, r6, r7);
    r15 = (u32)((s32)0u + (1));
    *(volatile u8*)((u32)r2 + (s32)(48)) = (u8)r15;
    return r2;
}
}  // namespace n001740b8

// ---- 001740e0 gap
namespace g001740e0 {
void func_001740e0(BD_VALUE* bd) asm("func_001740e0");
void func_001740e0(BD_VALUE* bd) { *(f32*)(*(u8**)((u8*)bd[0].p + 4) + 564) = bd[1].f; }
}  // namespace g001740e0

// ---- 001740f8 from src/ys/traps.cpp
namespace n001740f8 {
extern void YS_OBJ_show_part(void*, s32) asm("_ZN2YS3OBJ9show_partEi");
void trap_obj_motion_speed(BD_VALUE* bd) asm("_ZN2YS21trap_obj_motion_speedEP8BD_VALUE");
void trap_obj_motion_speed(BD_VALUE* bd) {
    YS_OBJ_show_part(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n001740f8

// ---- 00174118 from src/ys/traps.cpp
namespace n00174118 {
extern void YS_OBJ_hide_part(void*, s32) asm("_ZN2YS3OBJ9hide_partEi");
void trap_obj_hide_part(BD_VALUE* bd) asm("_ZN2gb18trap_obj_hide_partEP8BD_VALUE");
void trap_obj_hide_part(BD_VALUE* bd) {
    YS_OBJ_hide_part(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n00174118

// ---- 00174138 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00174138 {
extern "C" u32 func_0016bf20(u32, u32, u32, u32) asm("_ZN2YS3OBJ14get_appear_wayEv");
u32 func_00174138(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00174138jjjj");
u32 func_00174138(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = func_0016bf20(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n00174138

// ---- 00174168 from src/anon/batch_w4.cpp
namespace n00174168 {
void func_00183768(u32, u32, f32) asm("func_00183768");
struct Obj00174168 {
    u32 x;
    u32 m;
};
struct Args00174168 {
    Obj00174168* o;
    u32 a;
    f32 f;
};
void func_00174168(Args00174168* p) asm("func_00174168");
void func_00174168(Args00174168* p) {
    Obj00174168* o = p->o;
    u32 a = p->a;
    u32 m = o->m;
    func_00183768(m, a, p->f);                           
}
}  // namespace n00174168

// ---- 00174190 from src/anon/tiny_auto80_queue.cpp
namespace n00174190 {
u32 func_001796e8(...) asm("func_001796e8");
extern u8 D_01c5f480 asm("D_01c5f480");
void func_00174190(u32 a0) asm("_Z13func_00174190j");
void func_00174190(u32 a0) {
    u32 s0 = a0;
    kn::FVector tmp;
    func_001796e8((u32)&tmp, *(u32*)((u32)*(u32*)((u32)a0 + (s32)(0)) + (s32)(4)));
    u32 t7 = (u32)&D_01c5f480;
    kn::FVector* dst = (kn::FVector*)(u32)t7;
    *dst = tmp;
    *(u32*)((u32)s0 + (s32)(0)) = t7;
}
}  // namespace n00174190

// ---- 001741e0 from src/anon/batch_w9.cpp
namespace n001741e0 {
u32 func_001d14a0(void) asm("func_001d14a0");
void func_001b6bd8(u32, u32) asm("func_001b6bd8");
void trap_player_capture_form(u32* v) asm("_ZN2YS24trap_player_capture_formEP8BD_VALUE");
void trap_player_capture_form(u32* v) {
    func_001b6bd8(func_001d14a0(), v[0]);
}
}  // namespace n001741e0

// ---- 00174210 gap
namespace g00174210 {
u32 func_001d14a0(void) asm("func_001d14a0");
void YS__CHANGEFORM__CaptureEnd(u32) asm("YS__CHANGEFORM__CaptureEnd");
void func_00174210(BD_VALUE* bd) asm("func_00174210");
void func_00174210(BD_VALUE* bd) { YS__CHANGEFORM__CaptureEnd(func_001d14a0()); }
}  // namespace g00174210

// ---- 00174230 from src/ys/traps.cpp
namespace n00174230 {
extern s32 YS_CHANGEFORM_CanCaptureForm(BD_VALUE*) asm("_ZN2YS10CHANGEFORM14CanCaptureFormEv");
void trap_player_can_capture_form(BD_VALUE* bd) asm("_ZN2YS28trap_player_can_capture_formEP8BD_VALUE");
void trap_player_can_capture_form(BD_VALUE* bd) { bd->i = YS_CHANGEFORM_CanCaptureForm(bd); }
}  // namespace n00174230

// ---- 00174258 from src/ys/traps.cpp
namespace n00174258 {
extern void YS_PLAYER_set_exec_rc(void*, s32) asm("_ZN2YS6PLAYER11set_exec_rcEi");
void trap_player_set_exec_rc(BD_VALUE* bd) asm("_ZN2YS23trap_player_set_exec_rcEP8BD_VALUE");
void trap_player_set_exec_rc(BD_VALUE* bd) {
    YS_PLAYER_set_exec_rc(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n00174258

// ---- 00174278 gap
namespace g00174278 {
void func_00174278(BD_VALUE* bd) asm("func_00174278");
void func_00174278(BD_VALUE* bd) { bd->i = *(u16*)(*(u8**)(*(u8**)((u8*)bd[0].p + 4) + 2884) + 2590); }
}  // namespace g00174278

// ---- 00174290 from src/anon/batch_w43.cpp
namespace n00174290 {
void func_00190128(void*) asm("func_00190128");
void func_00190878(void*, u32, u32) asm("func_00190878");
void func_001d6ab0(u32) asm("func_001d6ab0");
void func_0019ca90(u32, u32, void*) asm("func_0019ca90");
void func_00174290(u8* p) asm("func_00174290");
void func_00174290(u8* p) {
    u8 buf[32];
    u32 x = *(u32*)(*(u8**)(p + 8) + 4);
    func_00190128(buf);
    func_00190878(buf, x, 0);
    u8* o = *(u8**)(*(u8**)p + 4);
    func_001d6ab0(*(u32*)(o + 2876));
    func_0019ca90(*(u32*)(o + 2880), *(u32*)(p + 4), buf);
}
}  // namespace n00174290

// ---- 001742f8 from src/ys/traps.cpp
namespace n001742f8 {
extern void YS_STATUS_CageOn(void) asm("_ZN2YS6STATUS6CageOnEv");
void trap_command_cage_off(BD_VALUE* bd) asm("_ZN2YS21trap_command_cage_offEP8BD_VALUE");
void trap_command_cage_off(BD_VALUE* bd) {
    (void)bd;
    YS_STATUS_CageOn();
}
}  // namespace n001742f8

// ---- 00174310 gap
namespace g00174310 {
void func_001919a8(void) asm("func_001919a8");
void func_00174310(BD_VALUE* bd) asm("func_00174310");
void func_00174310(BD_VALUE* bd) { func_001919a8(); }
extern u8* D_0034e948 asm("D_0034e948");
void func_00190128(void*) asm("func_00190128");
void func_00190878(void*, u32, u32) asm("func_00190878");
s32 func_001bd3e0(u32, s32, s32, void*, s32, s32) asm("func_001bd3e0");
void func_00174328(BD_VALUE* bd) asm("func_00174328");
void func_00174328(BD_VALUE* bd) {
    u8 t[32];
    func_00190128(t);
    func_00190878(t, *(u32*)((u8*)bd[2].p + 4), 0);
    func_001bd3e0(*(u32*)(D_0034e948 + 2884), bd[0].i, bd[1].i, t, bd[3].i, 100);
}
}  // namespace g00174310

// ---- 00174388 from src/anon/auto80_199_queue.cpp
namespace n00174388 {
void func_00174388(u32 a0) asm("_Z13func_00174388j");
void func_00174388(u32 a0) {
    u8 local[32];
    u32 s0 = a0;

    func_00190128(local);

    u32 t7 = *(u32*)(s0 + 16);
    func_00190878(local, *(u32*)(t7 + 4), 0);

    u32 t6 = D_0034e948;
    func_001bd4e8(*(u32*)(t6 + 2884), s0, (u32)local);
}
}  // namespace n00174388

// ---- 001743e0 gap
namespace g001743e0 {
extern u8* D_0034e948 asm("D_0034e948");
void func_001743e0(BD_VALUE* bd) asm("func_001743e0");
void func_001743e0(BD_VALUE* bd) { *(u32*)(*(u8**)(D_0034e948 + 2884) + 32) &= ~0x10; }
}  // namespace g001743e0

// ---- 00174400 from src/anon/tiny_wrappers_imp.cpp
namespace n00174400 {
u32 func_001d6ab0(u32, u32, u32, u32) asm("_Z13func_001d6ab0jjjj");
u32 func_00174400(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00174400jjjj");
u32 func_00174400(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r14 = *(u32*)((u32)r15 + (s32)(-5816));
    r4 = *(u32*)((u32)r14 + (s32)(2876));
    return func_001d6ab0(r4, r5, r6, r7);
}
}  // namespace n00174400

// ---- 00174420 from src/anon/tiny_wrappers_imp.cpp
namespace n00174420 {
u32 func_001be4e0(u32, u32, u32, u32) asm("_Z13func_001be4e0jjjj");
u32 func_00174420(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00174420jjjj");
u32 func_00174420(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r5 = (u32)((s32)0u + (6));
    r14 = *(u32*)((u32)r15 + (s32)(-5816));
    r4 = *(u32*)((u32)r14 + (s32)(2884));
    return func_001be4e0(r4, r5, r6, r7);
}
}  // namespace n00174420

// ---- 00174448 gap
namespace g00174448 {
extern u8* D_0034e948 asm("D_0034e948");
void func_00190128(void*) asm("func_00190128");
void func_00190878(void*, u32, u32) asm("func_00190878");
s32 func_001bd3e0(u32, s32, s32, void*, s32, s32) asm("func_001bd3e0");
void func_00174448(BD_VALUE* bd) asm("func_00174448");
void func_00174448(BD_VALUE* bd) {
    u8 t[32];
    u32 x = *(u32*)((u8*)bd[2].p + 4);
    func_00190128(t);
    func_00190878(t, x, 0);
    bd->i = func_001bd3e0(*(u32*)(D_0034e948 + 2884), bd[0].i, bd[1].i, t, bd[3].i, 100);
}
}  // namespace g00174448

// ---- 001744b8 from src/anon/tiny_wrappers_imp.cpp
namespace n001744b8 {
u32 func_001bf100(u32, u32, u32, u32) asm("_Z13func_001bf100jjjj");
u32 func_001744b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001744b8jjjj");
u32 func_001744b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r14 = *(u32*)((u32)r15 + (s32)(-5816));
    r5 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r14 + (s32)(2884));
    return func_001bf100(r4, r5, r6, r7);
}
}  // namespace n001744b8

// ---- 001744e0 gap
namespace g001744e0 {
extern u8* D_0034e948 asm("D_0034e948");
void func_001bf118(u32, s32) asm("func_001bf118");
void func_001744e0(BD_VALUE* bd) asm("func_001744e0");
void func_001744e0(BD_VALUE* bd) { func_001bf118(*(u32*)(D_0034e948 + 2884), bd[0].i); }
void func_00174508(BD_VALUE* bd) asm("func_00174508");
void func_00174508(BD_VALUE* bd) { *((u8*)bd[0].p + 5) = bd[1].i; }
}  // namespace g001744e0

// ---- 00174518 from src/anon/batch_w23.cpp
namespace n00174518 {
s32 func_00184780(void*, void*, f32, f32, f32) asm("func_00184780");
struct P174 { s32 r; u8* b; f32 x, y; };
void func_00174518(P174* p) asm("func_00174518");
void func_00174518(P174* p) {
    p->r = func_00184780(*(void**)(*(u8**)p + 4), p->b, *(f32*)(p->b + 12), p->x, p->y);
}
}  // namespace n00174518

// ---- 00174558 from src/anon/tiny_auto80_queue.cpp
namespace n00174558 {
u32 func_00190388(...) asm("func_00190388");
extern u8 D_01c5f480 asm("D_01c5f480");
void func_00174558(u32 a0) asm("_Z13func_00174558j");
void func_00174558(u32 a0) {
    u32 s0 = a0;
    kn::FVector tmp;
    func_00190388((u32)&tmp, *(u32*)((u32)a0 + (s32)(0)));                  
    u32 t7 = (u32)&D_01c5f480;
    kn::FVector* dst = (kn::FVector*)(u32)t7;
    *dst = tmp;
    *(u32*)((u32)s0 + (s32)(0)) = t7;
}
}  // namespace n00174558

// ---- 001745a0 from src/anon/tiny_wrappers_more_alt.cpp
namespace n001745a0 {
u32 func_00190920(u32, u32, u32, u32) asm("_Z13func_00190920jjjj");
u32 func_001745a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001745a0jjjj");
u32 func_001745a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 p0 = ((u32)(*(u32*)((u32)(a0) + 0u)));
    u32 p1 = ((u32)(*(u32*)((u32)(a0) + 8u)));
    u32 p2 = ((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 4u)))) + 4u)));
    u32 p3 = a3;
    return func_00190920(p0, p1, p2, p3);
}
}  // namespace n001745a0

// ---- 001745c8 from src/ys/traps.cpp
namespace n001745c8 {
extern s32 YS_TARGET_dup(s32) asm("_ZN2YS6TARGET3dupEv");
void trap_target_dup(BD_VALUE* bd) asm("_ZN2YS15trap_target_dupEP8BD_VALUE");
void trap_target_dup(BD_VALUE* bd) { bd->i = YS_TARGET_dup(bd->i); }
}  // namespace n001745c8

// ---- 001745f8 from src/ys/traps.cpp
namespace n001745f8 {
extern void YS_TARGET_free(s32) asm("_ZN2YS6TARGET4freeEv");
void trap_target_free(BD_VALUE* bd) asm("_ZN2YS16trap_target_freeEP8BD_VALUE");
void trap_target_free(BD_VALUE* bd) { YS_TARGET_free(bd->i); }
}  // namespace n001745f8

// ---- 00174610 from src/ys/traps.cpp
namespace n00174610 {
extern s32 YS_TARGET_is_exist(s32) asm("_ZNK2YS6TARGET8is_existEv");
void trap_target_is_exist(BD_VALUE* bd) asm("_ZN2YS20trap_target_is_existEP8BD_VALUE");
void trap_target_is_exist(BD_VALUE* bd) { bd->i = YS_TARGET_is_exist(bd->i); }
}  // namespace n00174610

// ---- 00174640 from src/ys/traps.cpp
namespace n00174640 {
u32 func_00190878(u32, u32, u32, u32) asm("func_00190878");
u32 trap_target_set_obj(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_target_set_objEP8BD_VALUE");
u32 trap_target_set_obj(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00190878(*(u32*)(a0 + 0u), *(u32*)(*(u32*)(a0 + 4u) + 4u), 0, a3);
}
}  // namespace n00174640

// ---- 00174668 gap
namespace g00174668 {
void func_00191398(u8*, s32) asm("func_00191398");
void func_00174668(BD_VALUE* bd) asm("func_00174668");
void func_00174668(BD_VALUE* bd) { func_00191398(*(u8**)((u8*)bd[0].p + 4), bd[1].i); }
}  // namespace g00174668

// ---- 00174688 from src/ys/traps.cpp
namespace n00174688 {
extern void YS_TARGET_ClearBeforePlayer(void) asm("_ZN2YS6TARGET17ClearBeforePlayerEv");
void trap_target_clear_before_player(BD_VALUE* bd) asm("_ZN2YS31trap_target_clear_before_playerEP8BD_VALUE");
void trap_target_clear_before_player(BD_VALUE* bd) {
    (void)bd;
    YS_TARGET_ClearBeforePlayer();
}
}  // namespace n00174688

// ---- 001746a0 gap
namespace g001746a0 {
void func_001746a0(BD_VALUE* bd) asm("func_001746a0");
void func_001746a0(BD_VALUE* bd) {}
void func_001746a8(BD_VALUE* bd) asm("func_001746a8");
void func_001746a8(BD_VALUE* bd) {}
void func_001746b0(BD_VALUE* bd) asm("func_001746b0");
void func_001746b0(BD_VALUE* bd) { bd->i = *(s32*)((u8*)bd[0].p + 8); }
void func_001746c0(BD_VALUE* bd) asm("func_001746c0");
void func_001746c0(BD_VALUE* bd) {}
}  // namespace g001746a0

// ---- 001746c8 from src/anon/tiny_auto80_queue.cpp
namespace n001746c8 {
void func_001ad990(u32, f32, f32, f32) asm("_Z13func_001ad990jfff");
void func_001746c8(u32 a0) asm("_Z13func_001746c8j");
void func_001746c8(u32 a0) {
    f32 f12 = *(f32*)((u32)a0 + (s32)(4));
    f32 f13 = f12;
    f32 f14 = 0.0f;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a0 = *(u32*)((u32)t7 + (s32)(4));
    a0 = (u32)((s32)a0 + (2248));
    func_001ad990(a0, f12, f13, f14);
}
}  // namespace n001746c8

// ---- 001746f8 gap
namespace g001746f8 {
s32 func_0019c158(u8*) asm("func_0019c158");
void func_001746f8(BD_VALUE* bd) asm("func_001746f8");
void func_001746f8(BD_VALUE* bd) { bd->i = func_0019c158(*(u8**)((u8*)bd[0].p + 4)); }
}  // namespace g001746f8

// ---- 00174728 from src/anon/batch_w10.cpp
namespace n00174728 {
void func_001ad990(void*, f32, f32, f32) asm("func_001ad990");
void func_00174728(u8* p) asm("func_00174728");
void func_00174728(u8* p) {
    u8* o = *(u8**)p;
    f32 x = *(f32*)(p + 4), y = *(f32*)(p + 8), z = *(f32*)(p + 12);
    func_001ad990(*(u8**)(o + 4) + 2248, x, y, z);
}
}  // namespace n00174728

// ---- 00174758 gap
namespace g00174758 {
s32 func_00197920(void) asm("func_00197920");
void func_00174758(BD_VALUE* bd) asm("func_00174758");
void func_00174758(BD_VALUE* bd) { bd->i = func_00197920(); }
}  // namespace g00174758

// ---- 00174780 from src/ys/traps.cpp
namespace n00174780 {
extern f32 YS_EVENT_GetRestTime(void) asm("_ZN2YS5EVENT11GetRestTimeEv");
void trap_event_get_rest_time(BD_VALUE* bd) asm("_ZN2YS24trap_event_get_rest_timeEP8BD_VALUE");
void trap_event_get_rest_time(BD_VALUE* bd) { bd->f = YS_EVENT_GetRestTime(); }
}  // namespace n00174780

// ---- 001747a8 from src/ys/traps.cpp
namespace n001747a8 {
extern void YS_EVENT_ControlOff(void) asm("_ZN2YS5EVENT10ControlOffEv");
void trap_event_control_off(BD_VALUE* bd) asm("_ZN2YS22trap_event_control_offEP8BD_VALUE");
void trap_event_control_off(BD_VALUE* bd) {
    (void)bd;
    YS_EVENT_ControlOff();
}
}  // namespace n001747a8

// ---- 001747c0 gap
namespace g001747c0 {
void func_00197780(void) asm("func_00197780");
void func_001747c0(BD_VALUE* bd) asm("func_001747c0");
void func_001747c0(BD_VALUE* bd) { func_00197780(); }
void func_00197c90(void) asm("func_00197c90");
void func_001d6c58(void) asm("func_001d6c58");
void func_001747d8(BD_VALUE* bd) asm("func_001747d8");
void func_001747d8(BD_VALUE* bd) {
    func_00197c90();
    func_001d6c58();
}
void func_001d6c88(void) asm("func_001d6c88");
void func_00197cc0(void) asm("func_00197cc0");
void func_001747f8(BD_VALUE* bd) asm("func_001747f8");
void func_001747f8(BD_VALUE* bd) {
    func_001d6c88();
    func_00197cc0();
}
s32 ryj__PAX__start(s32, s32, s32, s32, s32, s32) asm("ryj__PAX__start");
void func_00174818(BD_VALUE* bd) asm("func_00174818");
void func_00174818(BD_VALUE* bd) { bd->i = ryj__PAX__start(bd[0].i, bd[1].i, bd[2].i, 1, bd[3].i, 0); }
}  // namespace g001747c0

// ---- 00174858 from src/anon/batch_w58.cpp
namespace n00174858 {
u32 ryj__PAX__start(u32, u32, u32, u32, u32, u32) asm("ryj__PAX__start");
void func_00174858(u32* p) asm("func_00174858");
void func_00174858(u32* p) {
    p[0] = ryj__PAX__start(p[0], p[1], p[3], 1, p[4], ((u32*)p[2])[1]);                      
}
}  // namespace n00174858

// ---- 001748a0 from src/ys/traps.cpp
namespace n001748a0 {
extern s32 YS_MISSION_IsExec(void) asm("_ZN2YS7MISSION6IsExecEv");
void trap_status_is_mission(BD_VALUE* bd) asm("_ZN2YS22trap_status_is_missionEP8BD_VALUE");
void trap_status_is_mission(BD_VALUE* bd) { bd->i = YS_MISSION_IsExec(); }
}  // namespace n001748a0

// ---- 001748c8 gap
namespace g001748c8 {
extern u32 D_0034f240 asm("D_0034f240");
static inline bool test(u32 v, u32 m) { return (v & m) != 0; }
void func_001748c8(BD_VALUE* bd) asm("func_001748c8");
void func_001748c8(BD_VALUE* bd) { D_0034f240 |= 2; }
void func_001748e0(BD_VALUE* bd) asm("func_001748e0");
void func_001748e0(BD_VALUE* bd) { D_0034f240 &= ~2; }
void func_001748f8(BD_VALUE* bd) asm("func_001748f8");
void func_001748f8(BD_VALUE* bd) { bd->i = test(D_0034f240, 4); }
void func_00174910(BD_VALUE* bd) asm("func_00174910");
void func_00174910(BD_VALUE* bd) { D_0034f240 |= 8; }
void func_00174928(BD_VALUE* bd) asm("func_00174928");
void func_00174928(BD_VALUE* bd) { D_0034f240 &= ~8; }
void func_00174940(BD_VALUE* bd) asm("func_00174940");
void func_00174940(BD_VALUE* bd) { D_0034f240 |= 0x80; }
void func_00174958(BD_VALUE* bd) asm("func_00174958");
void func_00174958(BD_VALUE* bd) { D_0034f240 &= ~0x80; }
void func_00174970(BD_VALUE* bd) asm("func_00174970");
void func_00174970(BD_VALUE* bd) { bd->i = test(D_0034f240, 0x80); }
}  // namespace g001748c8

// ---- 00174988 from src/ys/traps.cpp
namespace n00174988 {
extern s32 YS_STATUS_IsBattleMode(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
void trap_status_force_leave_end(BD_VALUE* bd) asm("_ZN2YS27trap_status_force_leave_endEP8BD_VALUE");
void trap_status_force_leave_end(BD_VALUE* bd) { bd->i = YS_STATUS_IsBattleMode(); }
}  // namespace n00174988

// ---- 001749b0 from src/ys/traps.cpp
namespace n001749b0 {
extern void YS_STATUS_SetPrizeRatio(f32) asm("_ZN2YS6STATUS13SetPrizeRatioEf");
void trap_status_set_prize_ratio(BD_VALUE* bd) asm("_ZN2YS27trap_status_set_prize_ratioEP8BD_VALUE");
void trap_status_set_prize_ratio(BD_VALUE* bd) { YS_STATUS_SetPrizeRatio(bd->f); }
}  // namespace n001749b0

// ---- 001749c8 from src/anon/tiny_auto80_queue.cpp
namespace n001749c8 {
void func_00191bf0(f32) asm("_Z13func_00191bf0f");
void func_001749c8(u32 a0) asm("_Z13func_001749c8j");
void func_001749c8(u32 a0) {
    f32 f12 = *(f32*)((u32)a0 + (s32)(0));
    func_00191bf0(f12);
}
}  // namespace n001749c8

// ---- 001749e0 gap
namespace g001749e0 {
extern u32 D_0034f240 asm("D_0034f240");
void func_001749e0(BD_VALUE* bd) asm("func_001749e0");
void func_001749e0(BD_VALUE* bd) { D_0034f240 |= 0x1000; }
void func_001749f8(BD_VALUE* bd) asm("func_001749f8");
void func_001749f8(BD_VALUE* bd) { D_0034f240 &= ~0x1000; }
void func_00174a10(BD_VALUE* bd) asm("func_00174a10");
void func_00174a10(BD_VALUE* bd) { D_0034f240 |= 0x2000; }
void func_00174a28(BD_VALUE* bd) asm("func_00174a28");
void func_00174a28(BD_VALUE* bd) { D_0034f240 &= ~0x2000; }
void func_00174a40(BD_VALUE* bd) asm("func_00174a40");
void func_00174a40(BD_VALUE* bd) { D_0034f240 |= 0x20000; }
void func_00174a58(BD_VALUE* bd) asm("func_00174a58");
void func_00174a58(BD_VALUE* bd) { D_0034f240 |= 0x100000; }
void func_00174a70(BD_VALUE* bd) asm("func_00174a70");
void func_00174a70(BD_VALUE* bd) { D_0034f240 &= ~0x100000; }
}  // namespace g001749e0

// ---- 00174a90 from src/ys/traps.cpp
namespace n00174a90 {
extern s32 YS_LIGHT_Create(s32) asm("_ZN2YS5LIGHT6CreateEi");
void trap_light_create(BD_VALUE* bd) asm("_ZN2YS17trap_light_createEP8BD_VALUE");
void trap_light_create(BD_VALUE* bd) { bd->i = YS_LIGHT_Create(bd->i); }
}  // namespace n00174a90

// ---- 00174ac0 gap
namespace g00174ac0 {
struct BS {
    u32 w[8];
    void set(u32 n) { u32* p = &w[n >> 5]; *p |= 1 << (n & 31); }
};
void func_00174ac0(BD_VALUE* bd) asm("func_00174ac0");
void func_00174ac0(BD_VALUE* bd) { ((BS*)((u8*)bd[0].p + 16))->set(bd[1].i); }
}  // namespace g00174ac0

// ---- 00174af8 from src/anon/batch_w10.cpp
namespace n00174af8 {
void func_001b1bb8(void*, u32, u32, u32, s32, f32) asm("func_001b1bb8");
void func_00174af8(u8* p) asm("func_00174af8");
void func_00174af8(u8* p) {
    void* o = *(void**)p;
    func_001b1bb8(o, *(u32*)(p + 4), *(u32*)(p + 8), *(u32*)(p + 12), 128, *(f32*)(p + 16));
}
}  // namespace n00174af8

// ---- 00174b28 from src/anon/batch_w3.cpp
namespace n00174b28 {
void func_001b1c10(s32, f32) asm("func_001b1c10");
void func_00174b28(BD_VALUE* bd) asm("func_00174b28");
void func_00174b28(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_001b1c10(a.i, bd[1].f);
}
}  // namespace n00174b28

// ---- 00174b48 gap
namespace g00174b48 {
void func_00174b48(BD_VALUE* bd) asm("func_00174b48");
void func_00174b48(BD_VALUE* bd) { *(f32*)((u8*)bd[0].p + 24) = bd[1].f; }
void func_00174b58(BD_VALUE* bd) asm("func_00174b58");
void func_00174b58(BD_VALUE* bd) { *(f32*)((u8*)bd[0].p + 28) = bd[1].f; }
void func_00174b68(BD_VALUE* bd) asm("func_00174b68");
void func_00174b68(BD_VALUE* bd) { *(f32*)((u8*)bd[0].p + 32) = bd[1].f; }
void func_00174b78(BD_VALUE* bd) asm("func_00174b78");
void func_00174b78(BD_VALUE* bd) { *(f32*)((u8*)bd[0].p + 36) = bd[1].f; }
}  // namespace g00174b48

// ---- 00174b88 from src/anon/batch_w4.cpp
namespace n00174b88 {
void func_001b1be0(u32, f32) asm("func_001b1be0");
struct ArgsUF {
    u32 a;
    f32 f;
};
void func_00174b88(ArgsUF* p) asm("func_00174b88");
void func_00174b88(ArgsUF* p) {
    u32 a = p->a;
    func_001b1be0(a, p->f);
}
}  // namespace n00174b88

// ---- 00174ba8 from src/anon/batch_w5.cpp
namespace n00174ba8 {
u32 func_00140df0(void) asm("func_00140df0");
void func_00140f10(u32) asm("func_00140f10");
void trap_camera_warp(BD_VALUE* bd) asm("_ZN2YS16trap_camera_warpEP8BD_VALUE");
void trap_camera_warp(BD_VALUE* bd) {
    func_00140f10(func_00140df0());
}
}  // namespace n00174ba8

// ---- 00174bc8 from src/anon/batch_w1.cpp
namespace n00174bc8 {
void func_00140f20(void*) asm("func_00140f20");
void* ObjCamera_getInstance() asm("_ZN2dk9ObjCamera11getInstanceEv");
void trap_camera_reset(BD_VALUE*) asm("_ZN2YS17trap_camera_resetEP8BD_VALUE");
void trap_camera_reset(BD_VALUE*) { func_00140f20(ObjCamera_getInstance()); }
}  // namespace n00174bc8

// ---- 00174be8 from src/anon/tiny_auto80_queue.cpp
namespace n00174be8 {
u32 dk__ReactionCamera__create(...) asm("dk__ReactionCamera__create");
u32 func_00190128(...) asm("func_00190128");
u32 func_00190878(...) asm("func_00190878");
void func_00174be8(u32 a0) asm("_Z13func_00174be8j");
void func_00174be8(u32 a0) {
    struct { u32 w0,w1,w2,w3,w4,w5,w6,w7; } spv;
    u32 s0 = a0;
    func_00190128((u32)&spv);
    u32 t7 = *(u32*)((u32)s0 + (s32)(0));
    func_00190878((u32)&spv, *(u32*)((u32)t7 + (s32)(4)), 0u);
    dk__ReactionCamera__create((u32)&spv);
}
}  // namespace n00174be8

// ---- 00174c30 from src/ys/traps.cpp
namespace n00174c30 {
void func_00226e60(u32) asm("func_00226e60");
void trap_camera_apply_pos(BD_VALUE* bd) asm("_ZN2YS21trap_camera_apply_posEP8BD_VALUE");
void trap_camera_apply_pos(BD_VALUE* bd) { func_00226e60((s32)(bd->i != 0)); }
}  // namespace n00174c30

// ---- 00174c50 gap
namespace g00174c50 {
extern u8 D_003511d0[] asm("D_003511d0");
extern u8 D_01c5f480[] asm("D_01c5f480");
static inline void vu_mcopy(f32 (*d)[4], const u8* s) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void vu_minv(f32 (*d)[4], f32 (*s)[4]) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%1)\n\t"
                 "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                 "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                 "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                 "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
static inline void vu_xfp(u8* out, f32 (*m)[4], const u8* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                 "sqc2 $vf5, 0(%0)"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
void func_00174c50(BD_VALUE* bd) asm("func_00174c50");
void func_00174c50(BD_VALUE* bd) {
    f32 m[4][4] __attribute__((aligned(16)));
    vu_mcopy(m, D_003511d0);
    vu_minv(m, m);
    vu_xfp(D_01c5f480, m, (u8*)bd[0].p);
    bd->p = D_01c5f480;
}
}  // namespace g00174c50

// ---- 00174d18 from src/anon/batch_w2.cpp
namespace n00174d18 {
struct ObjRef { u32 pad0; void* obj; };
struct BdObjFloat { ObjRef* ref; f32 value; };
void func_00158870(void* obj, f32 v) asm("func_00158870");
void func_00174d18(BdObjFloat* a) asm("func_00174d18");
void func_00174d18(BdObjFloat* a) {
    func_00158870(a->ref->obj, a->value);
}
}  // namespace n00174d18

// ---- 00174d38 from src/ys/traps.cpp
namespace n00174d38 {
extern void dk_ScopeCamera_destroy(void) asm("_ZN2dk11ScopeCamera7destroyEv");
void trap_camera_end_scope(BD_VALUE* bd) asm("_ZN2YS21trap_camera_end_scopeEP8BD_VALUE");
void trap_camera_end_scope(BD_VALUE* bd) {
    (void)bd;
    dk_ScopeCamera_destroy();
}
}  // namespace n00174d38

// ---- 00174d50 gap
namespace g00174d50 {
extern u8 D_01c5f480[] asm("D_01c5f480");
u32 func_00106a60(s32) asm("func_00106a60");
void kn__Camera__getPosition(u32, u8*) asm("kn__Camera__getPosition");
void func_00174d50(BD_VALUE* bd) asm("func_00174d50");
void func_00174d50(BD_VALUE* bd) {
    kn__Camera__getPosition(func_00106a60(1), D_01c5f480);
    bd->p = D_01c5f480;
}
}  // namespace g00174d50

// ---- 00174d98 from src/anon/batch_w30.cpp
namespace n00174d98 {
extern u8 D_01c5f480[16] asm("D_01c5f480");
u32 func_00106a60(s32) asm("func_00106a60");
void func_00107478(u32, void*) asm("func_00107478");
void trap_camera_at(void**) asm("_ZN2YS14trap_camera_atEP8BD_VALUE");
void trap_camera_at(void** v) {
    func_00107478(func_00106a60(1), D_01c5f480);                          
    *v = D_01c5f480;
}
}  // namespace n00174d98

// ---- 00174de0 from src/ys/traps.cpp
namespace n00174de0 {
extern void YS_LIGHT_fadeout(f32) asm("_ZN2YS5LIGHT7fadeoutEf");
void trap_camera_set_scope_zoom(BD_VALUE* bd) asm("_ZN2YS26trap_camera_set_scope_zoomEP8BD_VALUE");
void trap_camera_set_scope_zoom(BD_VALUE* bd) { YS_LIGHT_fadeout(bd->f); }
}  // namespace n00174de0

// ---- 00174df8 from src/ys/traps.cpp
namespace n00174df8 {
extern void YS_LIGHT_fadein(f32) asm("_ZN2YS5LIGHT6fadeinEf");
void trap_camera_set_scope_closeup_distance(BD_VALUE* bd) asm("_ZN2YS38trap_camera_set_scope_closeup_distanceEP8BD_VALUE");
void trap_camera_set_scope_closeup_distance(BD_VALUE* bd) { YS_LIGHT_fadein(bd->f); }
}  // namespace n00174df8

// ---- 00174e10 from src/anon/batch_w5.cpp
namespace n00174e10 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
void func_00158920(Q16*) asm("func_00158920");
void func_00174e10(Q16** pp) asm("func_00174e10");
void func_00174e10(Q16** pp) {
    Q16 tmp;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&tmp), "r"(*pp) : "$8", "memory");
    func_00158920(&tmp);
}
}  // namespace n00174e10

// ---- 00174e38 from src/anon/batch_w98.cpp
namespace n00174e38 {
struct M174 { f32 m[4][4]; } __attribute__((aligned(16)));
struct IV174 { f32 x, y, z; s32 w; };
union PU174 { IV174* p; f32 f; };
extern IV174 D_01c5f480 asm("D_01c5f480");
u8* kn__getProjection(s32) asm("kn__getProjection");
u8* func_00106a60(s32) asm("func_00106a60");
void func_002f47d8(void*, void*, void*, u32) asm("func_002f47d8");
static inline void mulmat174(M174* d, const void* a, const void* b) {
    asm volatile(
        "lqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
        "lqc2 $vf5,0(%2)\n\tlqc2 $vf6,16(%2)\n\tlqc2 $vf7,32(%2)\n\tlqc2 $vf8,48(%2)\n\t"
        "vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\tvmaddw.wxyz $vf5,$vf4,$vf5w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf6x\n\tvmadday.wxyz ACC,$vf2,$vf6y\n\tvmaddaz.wxyz ACC,$vf3,$vf6z\n\tvmaddw.wxyz $vf6,$vf4,$vf6w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf7x\n\tvmadday.wxyz ACC,$vf2,$vf7y\n\tvmaddaz.wxyz ACC,$vf3,$vf7z\n\tvmaddw.wxyz $vf7,$vf4,$vf7w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf8x\n\tvmadday.wxyz ACC,$vf2,$vf8y\n\tvmaddaz.wxyz ACC,$vf3,$vf8z\n\tvmaddw.wxyz $vf8,$vf4,$vf8w\n\t"
        "sqc2 $vf5,0(%0)\n\tsqc2 $vf6,16(%0)\n\tsqc2 $vf7,32(%0)\n\tsqc2 $vf8,48(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
void func_00174e38(PU174* pv) asm("func_00174e38");
void func_00174e38(PU174* pv) {
    M174 m;
    s32 o[4];
    u8* a = kn__getProjection(1);                   
    u8* b = func_00106a60(1);                        
    mulmat174(&m, a, b ? b + 16 : 0);
    func_002f47d8(o, &m, pv->p, 0);                               
    D_01c5f480.x = (f32)((o[0] >> 4) - 2048);
    D_01c5f480.y = (f32)((o[1] >> 4) - 2048);
    D_01c5f480.z = (f32)(o[2] >> 4);
    D_01c5f480.w = 0;
    pv->p = &D_01c5f480;
}
}  // namespace n00174e38

// ---- 00174f58 from src/ys/traps.cpp
namespace n00174f58 {
extern void YS_UNIT_GROUP_Disable(s32) asm("_ZN2YS10UNIT_GROUP7DisableEi");
void trap_unit_disable(BD_VALUE* bd) asm("_ZN2YS17trap_unit_disableEP8BD_VALUE");
void trap_unit_disable(BD_VALUE* bd) { YS_UNIT_GROUP_Disable(bd->i); }
}  // namespace n00174f58

// ---- 00174f70 from src/ys/traps.cpp
namespace n00174f70 {
extern void YS_UNIT_GROUP_Enable(s32) asm("_ZN2YS10UNIT_GROUP6EnableEi");
void trap_unit_enable(BD_VALUE* bd) asm("_ZN2YS16trap_unit_enableEP8BD_VALUE");
void trap_unit_enable(BD_VALUE* bd) { YS_UNIT_GROUP_Enable(bd->i); }
}  // namespace n00174f70

// ---- 00174f88 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00174f88 {
u32 func_0019abe8(u32, u32, u32, u32) asm("_Z13func_0019abe8jjjj");
u32 func_00174f88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00174f88jjjj");
u32 func_00174f88(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0019abe8(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n00174f88

// ---- 00174fb0 gap
namespace g00174fb0 {
struct E { s32 v, max, min; };
void func_00174fb0(BD_VALUE* bd) asm("func_00174fb0");
void func_00174fb0(BD_VALUE* bd) { bd->i = ((E*)bd[0].p)[bd[1].i].v; }
void func_00174fd0(BD_VALUE* bd) asm("func_00174fd0");
void func_00174fd0(BD_VALUE* bd) { bd->i = ((E*)bd[0].p)[bd[1].i].max; }
void func_00174ff0(BD_VALUE* bd) asm("func_00174ff0");
void func_00174ff0(BD_VALUE* bd) { bd->i = ((E*)bd[0].p)[bd[1].i].min; }
void func_00175010(BD_VALUE* bd) asm("func_00175010");
void func_00175010(BD_VALUE* bd) {
    E* t = (E*)bd[0].p;
    s32 i = bd[1].i;
    bd->f = (f32)t[i].v / (f32)t[i].max;
}
void func_00175048(BD_VALUE* bd) asm("func_00175048");
void func_00175048(BD_VALUE* bd) {
    E* e = &((E*)bd[0].p)[bd[2].i];
    s32 x = bd[1].i;
    s32 r;
    if (x < e->min) {
        r = e->min;
    } else {
        r = x;
        if (e->max < x) r = e->max;
    }
    e->v = r;
}
void func_00175090(BD_VALUE* bd) asm("func_00175090");
void func_00175090(BD_VALUE* bd) { ((E*)bd[0].p)[bd[2].i].min = bd[1].i; }
}  // namespace g00174fb0

// ---- 001750b0 from src/ys/traps.cpp
namespace n001750b0 {
extern s32 Tz_Munny_Get(void) asm("_ZN2Tz5Munny3GetEv");
void trap_sheet_munny(BD_VALUE* bd) asm("_ZN2YS16trap_sheet_munnyEP8BD_VALUE");
void trap_sheet_munny(BD_VALUE* bd) { bd->i = Tz_Munny_Get(); }
}  // namespace n001750b0

// ---- 001750d8 from src/ys/traps.cpp
namespace n001750d8 {
extern s32 Tz_Munny_Add(u32) asm("_ZN2Tz5Munny3AddEj");
void trap_sheet_add_munny(BD_VALUE* bd) asm("_ZN2YS20trap_sheet_add_munnyEP8BD_VALUE");
void trap_sheet_add_munny(BD_VALUE* bd) { bd->i = Tz_Munny_Add((u32)bd->i); }
}  // namespace n001750d8

// ---- 00175108 from src/anon/batch_w2.cpp
namespace n00175108 {
void func_001a2438(u32, u32, u32) asm("func_001a2438");
void func_00175108(u32* v) asm("func_00175108");
void func_00175108(u32* v) {
    u32 a = v[0];
    func_001a2438(a, v[1], v[2]);
}
}  // namespace n00175108

// ---- 00175130 gap
namespace g00175130 {
void func_00175130(BD_VALUE* bd) asm("func_00175130");
void func_00175130(BD_VALUE* bd) { *(f32*)((u8*)bd[0].p + 452) = bd[1].f; }
void func_00175140(BD_VALUE* bd) asm("func_00175140");
void func_00175140(BD_VALUE* bd) { *(f32*)((u8*)bd[0].p + 456) = bd[1].f; }
void func_00175150(BD_VALUE* bd) asm("func_00175150");
void func_00175150(BD_VALUE* bd) { bd->i = *((u8*)bd[0].p + 588); }
void func_00175160(BD_VALUE* bd) asm("func_00175160");
void func_00175160(BD_VALUE* bd) { *((u8*)bd[0].p + 588) = bd[1].i; }
}  // namespace g00175130

// ---- 00175170 from src/ys/traps.cpp
namespace n00175170 {
u32 func_001a27d8(u32, u32, u32, u32) asm("func_001a27d8");
u32 trap_sheet_attack_level(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS23trap_sheet_attack_levelEP8BD_VALUE");
u32 trap_sheet_attack_level(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r16 = a0;
    u32 r2 = func_001a27d8(*(u32*)(a0 + 0u), a1, a2, a3);
    *(u32*)(r16 + 0) = r2;
    return r2;
}
}  // namespace n00175170

// ---- 001751a0 gap
namespace g001751a0 {
void func_001751a0(BD_VALUE* bd) asm("func_001751a0");
void func_001751a0(BD_VALUE* bd) { bd->i = ((s32*)(*(u8**)((u8*)bd[0].p + 4) + 2808))[bd[1].i]; }
}  // namespace g001751a0

// ---- 001751c0 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001751c0 {
extern "C" u32 YS_PARTY_hand_to_bone(u32, u32, u32, u32) asm("_ZN2YS5PARTY12hand_to_boneEi");
u32 func_001751c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001751c0jjjj");
u32 func_001751c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r5 = *(u32*)((u32)r4 + (s32)(4));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = YS_PARTY_hand_to_bone(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001751c0

// ---- 001751f8 from src/anon/batch_w3.cpp
namespace n001751f8 {
void trap_prize_appear_tr(BD_VALUE* bd) asm("_ZN2YS20trap_prize_appear_trEP8BD_VALUE");
void func_001d2930(s32, s32) asm("func_001d2930");
void trap_prize_appear_tr(BD_VALUE* bd) asm("_ZN2YS20trap_prize_appear_trEP8BD_VALUE");
void trap_prize_appear_tr(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_001d2930(a.i, bd[1].i);
}
}  // namespace n001751f8

// ---- 00175218 from src/ys/traps.cpp
namespace n00175218 {
extern s32 YS_PRIZE_GetAppearNum(void) asm("_ZN2YS5PRIZE12GetAppearNumEv");
void trap_prize_num(BD_VALUE* bd) asm("_ZN2YS14trap_prize_numEP8BD_VALUE");
void trap_prize_num(BD_VALUE* bd) { bd->i = YS_PRIZE_GetAppearNum(); }
}  // namespace n00175218

// ---- 00175240 from src/ys/traps.cpp
namespace n00175240 {
extern void YS_PRIZE_TR_GetAll(void*) asm("_ZN2YS8PRIZE_TR6GetAllEPNS_6BTLOBJE");
void trap_prize_get_all_tr(BD_VALUE* bd) asm("_ZN2YS21trap_prize_get_all_trEP8BD_VALUE");
void trap_prize_get_all_tr(BD_VALUE* bd) { YS_PRIZE_TR_GetAll(*(void**)((char*)bd->i + 4)); }
}  // namespace n00175240

// ---- 00175260 gap
namespace g00175260 {
s32 func_001cc5c8(u8*, u8*, s32) asm("func_001cc5c8");
void func_00175260(BD_VALUE* bd) asm("func_00175260");
void func_00175260(BD_VALUE* bd) {
    u8* b = *(u8**)((u8*)bd[1].p + 4);
    u8* a = *(u8**)((u8*)bd[0].p + 4);
    bd->i = func_001cc5c8(a, b, bd[2].i);
}
}  // namespace g00175260

// ---- 001752a0 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001752a0 {
u32 YS__PRIZE_CA__Vacuum(u32, u32, u32, u32) asm("_Z20YS__PRIZE_CA__Vacuumjjjj");
u32 func_001752a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001752a0jjjj");
u32 func_001752a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(4));
    r14 = *(u32*)((u32)r4 + (s32)(0));
    r6 = *(u32*)((u32)r16 + (s32)(8));
    r5 = *(u32*)((u32)r15 + (s32)(4));
    r4 = *(u32*)((u32)r14 + (s32)(4));
    r2 = YS__PRIZE_CA__Vacuum(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001752a0

// ---- 001752e0 from src/anon/batch_w4.cpp
namespace n001752e0 {
void func_001cc9c8(u32, f32) asm("func_001cc9c8");
void func_001752e0(u32* p) asm("func_001752e0");
void func_001752e0(u32* p) {
    func_001cc9c8(((u32*)p[0])[1], ((f32*)p)[1]);
}
}  // namespace n001752e0

// ---- 00175300 from src/ys/traps.cpp
namespace n00175300 {
extern s32 YS_PRIZE_CA_GetAppearNum(void) asm("_ZN2YS8PRIZE_CA12GetAppearNumEv");
void trap_prize_num_ca(BD_VALUE* bd) asm("_ZN2YS17trap_prize_num_caEP8BD_VALUE");
void trap_prize_num_ca(BD_VALUE* bd) { bd->i = YS_PRIZE_CA_GetAppearNum(); }
}  // namespace n00175300

// ---- 00175328 from src/anon/batch_w3.cpp
namespace n00175328 {
void func_001a5880(s32, s32, s32) asm("func_001a5880");
void func_00175328(BD_VALUE* bd) asm("func_00175328");
void func_00175328(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_001a5880(a.i, bd[1].i, bd[2].i);
}
}  // namespace n00175328

// ---- 00175350 gap
namespace g00175350 {
void func_001da2b8(s32, s32) asm("func_001da2b8");
void func_00175350(BD_VALUE* bd) asm("func_00175350");
void func_00175350(BD_VALUE* bd) {
    s32 a = bd[0].i;
    func_001da2b8(a, bd[1].i);
}
}  // namespace g00175350

// ---- 00175370 from src/anon/batch_w40.cpp
namespace n00175370 {
u8* func_001050d8(u32) asm("func_001050d8");
void menu__Window__Window(u8*) asm("menu__Window__Window");
void func_002ee5d8(u8*, u32) asm("func_002ee5d8");
void func_002edfa8(u8*, u8*) asm("func_002edfa8");
extern void* D_0034e888[] asm("D_0034e888");
void YS__trap_tutorial_pause(u32* a) asm("YS__trap_tutorial_pause");
void YS__trap_tutorial_pause(u32* a) {
    u8* o = func_001050d8(4736);
    u32 v = *a;
    menu__Window__Window(o);
    *(void**)o = D_0034e888;
    func_002ee5d8(o + 36, v);
    func_002edfa8(o, o + 36);
}
}  // namespace n00175370

// ---- 001753e0 gap
namespace g001753e0 {
u32 func_001050d8(u32) asm("func_001050d8");
void func_001ad5f0(u32, u32) asm("func_001ad5f0");
void func_001ac7c8(u32, u32) asm("func_001ac7c8");
void func_001753e0(BD_VALUE* bd) asm("func_001753e0");
struct NoTail {
    ~NoTail() {}
};
void func_001753e0(BD_VALUE* bd) {
    NoTail nt;
    u32 x = bd[0].i;
    u32 w = func_001050d8(4656);
    func_001ad5f0(w, x);
    func_001ac7c8(func_001050d8(28), w);
}
}  // namespace g001753e0

// ---- 00175438 from src/ys/traps.cpp
namespace n00175438 {
extern s32 YS_WINDOW_SYSTEM_TUTORIAL_IsOpen(void) asm("_ZN2YS22WINDOW_SYSTEM_TUTORIAL6IsOpenEv");
void trap_tutorial_is_open(BD_VALUE* bd) asm("_ZN2YS21trap_tutorial_is_openEP8BD_VALUE");
void trap_tutorial_is_open(BD_VALUE* bd) { bd->i = YS_WINDOW_SYSTEM_TUTORIAL_IsOpen(); }
}  // namespace n00175438

// ---- 00175460 from src/ys/traps.cpp
namespace n00175460 {
u32 func_0023f070(u32, u32, u32, u32) asm("func_0023f070");
u32 trap_picture_change(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_picture_changeEP8BD_VALUE");
u32 trap_picture_change(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0023f070(*(u32*)(a0 + 0u), *(u32*)(a0 + 4u), 0xffffffffu, a3);
}
}  // namespace n00175460

// ---- 00175480 from src/anon/batch_w4.cpp
namespace n00175480 {
void func_00153e28(u32, f32, f32) asm("func_00153e28");
void func_00175480(u32* p) asm("func_00175480");
void func_00175480(u32* p) {
    func_00153e28(p[0], ((f32*)p)[1], ((f32*)p)[2]);
}
}  // namespace n00175480

// ---- 001754a8 gap
namespace g001754a8 {
s32 func_001ba158(void) asm("func_001ba158");
void func_001754a8(BD_VALUE* bd) asm("func_001754a8");
void func_001754a8(BD_VALUE* bd) { bd->i = func_001ba158(); }
}  // namespace g001754a8

// ---- 001754d0 from src/anon/batch_w19.cpp
namespace n001754d0 {
u32 func_001a8258(u32) asm("func_001a8258");
u32 func_001a8418(u32) asm("func_001a8418");
u32 func_001a8510(void) asm("func_001a8510");
void func_001382b8(u32) asm("func_001382b8");
void trap_treasure_get(u32* v) asm("_ZN2YS17trap_treasure_getEP8BD_VALUE");
void trap_treasure_get(u32* v) {
    func_001a8418(func_001a8258(*v));
    func_001382b8(func_001a8510());
}
}  // namespace n001754d0

// ---- 00175500 from src/ys/traps.cpp
namespace n00175500 {
extern void YS_JIGSAW_Get(s32, s32) asm("_ZN2YS6JIGSAW3GetEii");
void trap_jigsaw_get(BD_VALUE* bd) asm("_ZN2YS15trap_jigsaw_getEP8BD_VALUE");
void trap_jigsaw_get(BD_VALUE* bd) { YS_JIGSAW_Get(bd->i, bd[1].i); }
}  // namespace n00175500

// ---- 00175520 from src/anon/batch_w1664.cpp
namespace n00175520 {
void wtarget_00175520(u32, u32, u32, u32) asm("_Z16wtarget_00175520jjjj");
void wtarget_00175520(u32, u32, u32, u32) {}
}  // namespace n00175520

// ---- 00175528 gap
namespace g00175528 {
void func_00175528(void) asm("func_00175528");
void func_00175528(void) {}
void func_00175530(void) asm("func_00175530");
void func_00175530(void) {}
void func_00175538(void) asm("func_00175538");
void func_00175538(void) {}
void func_00175540(void) asm("func_00175540");
void func_00175540(void) {}
void func_00175548(void) asm("func_00175548");
void func_00175548(void) {}
}  // namespace g00175528

// ---- 00175550 from src/anon/tiny_wrappers_more.cpp
namespace n00175550 {
u32 func_00175520(u32, u32, u32, u32) asm("_Z13func_00175520jjjj");
u32 func_00175550(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00175550jjjj");
u32 func_00175550(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00175520(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00175550

// ---- 00175570 gap
namespace g00175570 {
u32 func_00175520(u32, u32, u32, u32) asm("func_00175520");
u32 func_00175570(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00175570");
u32 func_00175570(u32 a0, u32 a1, u32 a2, u32 a3) { return func_00175520(0, 0x0000ffffu, a2, a3); }
}  // namespace g00175570
