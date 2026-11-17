// Linked unit 0x19fb70-0x1a28b8 (YS: the vtable 0x350478 class, YS mission traps (trap table .data 0x3504f0, 23 gap
// functions from it and the vtables), SHEET, the 0x1c62fb8 array static init + _GLOBAL__I_ stub as plain functions).
// .rodata starts 0x36d440. Built -G0 -g -fno-strict-aliasing. 0x1a28b8 after the I stub is the next file's.
// Each function keeps the declarations of the source it was matched in (namespace nADDR).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../yasui/libys/jumper.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../yasui/libys/recomflag.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../yasui/libys/attack.hpp"
#include "../yasui/libys/battlereport.hpp"
#include "../yasui/libys/obj.hpp"
#include "../yasui/libys/sheet.hpp"

// ---- 0019fb70 from src/anon/batch_w214.cpp
namespace n0019fb70 {
void func_0019fb70(u32 a0, u8* a1) asm("func_0019fb70");
void func_0019fb70(u32 a0, u8* a1) {
    u32 tmp[4] __attribute__((aligned(16)));
    asm volatile(
        "addiu $15,%1,32\n\t"
        "lq $8,0($15)\n\t"
        "sq $8,%0\n\t"
        "sw $0,4(%2)\n\t"
        "lqc2 vf1,%0\n\t"
        "vmul.xyz vf1,vf1,vf1\n\t"
        "vaddy.x vf1,vf1,vf1y\n\t"
        "vaddz.x vf1,vf1,vf1z\n\t"
        "vsqrt Q,vf1x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8,$22\n\t"
        "mtc1 $8,$f1\n\t"
        "lui $15,%%hi(D_00352130)\n\t"
        "lw $14,%%lo(D_00352130)($15)\n\t"
        "lwc1 $f0,28($14)\n\t"
        "mul.s $f1,$f1,$f0\n\t"
        "sw $0,248(%1)\n\t"
        "swc1 $f1,244(%1)\n\t"
        : "=m"(tmp) : "r"(a1), "r"(tmp) : "$8", "$14", "$15", "$f0", "$f1", "memory");
}
}  // namespace n0019fb70

// ---- 0019fbc8 from src/anon/tiny_wrappers_more.cpp
namespace n0019fbc8 {
u32 func_001878e8(u32, u32, u32, u32) asm("_Z13func_001878e8jjjj");
u32 func_0019fbc8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0019fbc8jjjj");
u32 func_0019fbc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001878e8(a1, a1, a2, a3);
}
}  // namespace n0019fbc8

// ---- 0019fbe0 from src/anon/batch_w3722_nsa.cpp
namespace n0019fbe0 {
struct V4fbe0 {
    f32 x, y, z, w;
    V4fbe0() {}
    V4fbe0& operator=(const V4fbe0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V4fbe0(const V4fbe0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    V4fbe0 mulk(f32 s, f32 k) const {
        V4fbe0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Prmfbe0 { u8 pad[24]; f32 a; u8 pad2[4]; f32 b; };
struct Objfbe0 { u8 pad[32]; V4fbe0 vel; u8 pad2[244 - 48]; f32 f244; f32 f248; u8 pad3[288 - 252]; f32 f288; };
extern "C" { extern Prmfbe0* D_00352130; }
extern "C" { extern f32 D_00349e10; }
extern f32 D_00349e10_b asm("D_00349e10");
extern Prmfbe0* D_00352130_b asm("D_00352130");
V4fbe0 func_0019fbe0(void* unused, Objfbe0* o) asm("func_0019fbe0");
V4fbe0 func_0019fbe0(void* unused, Objfbe0* o) {
    o->f248 = o->f248 + D_00349e10;
    V4fbe0 r;
    r = o->vel;
    r.y = 0;
    f32 B, C, D;
    register f32 L asm("$f3") = r.normalize();
    register f32 K asm("$f3") = L; asm("" : "+f"(K));                                                                   
    f32 P = D_00352130->a;
    f32 A = L * P;
    f32 M = o->f244;
    if (!(M < A)) A = M;
    B = r.x * A; C = r.z * A;
    o->vel.x = B; o->vel.z = C;
    if (o->vel.y < 0) o->vel.y = o->vel.y * D_00352130_b->b;
    C = o->vel.y;
    D = C + 0.40816324949264526f;
    if (!(D < o->f288)) D = o->f288;
    o->vel.y = D;
    r = o->vel.mulk(D_00349e10_b, K);
    return r;
}
}  // namespace n0019fbe0

// ---- 0019fd00 from src/anon/auto80_199_queue.cpp
namespace n0019fd00 {
void func_0019fd00(u32 a0, u32 a1, u32 a2) asm("_Z13func_0019fd00jjj");
void func_0019fd00(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 s1;
    f32 f20;
    u32 v0;
    u32 t7;

    func_0016bd60(s0, a2);
    s1 = s0 + 0x140;
    f20 = 0.0f;
    v0 = func_0019fdb0(s0);
    ((void(*)(u32, u32, f32, f32))func_0017f488)(s1, v0, f20, f20);
    ((u32(*)(u32, u32, u32, f32, f32))func_0017f5e0)(s1, 0, 0, f20, f20);
    t7 = *(u32 *)(s0 + 0x108);
    t7 = t7 | 0x08000000;
    *(u32 *)(s0 + 0x108) = t7;
}
}  // namespace n0019fd00

// ---- 0019fd88 from src/anon/batch_w4.cpp
namespace n0019fd88 {
void func_0019fd88(void** o, u32 a) asm("func_0019fd88");
void func_0019fd88(void** o, u32 a) {
    ((void (*)(void*, u32, u32))((void**)*o)[9])(o, a, 0);
}
}  // namespace n0019fd88

// ---- 0019fdb0 from src/anon/tiny_more.cpp
namespace n0019fdb0 {
u32 func_0019fdb0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0019fdb0jjjj");
u32 func_0019fdb0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = *(u32*)((u32)a0 + (340)); return (u32)((s32)v + (1)); }
}  // namespace n0019fdb0

// ---- 0019fdc0 from src/anon/batch_w1545.cpp
namespace n0019fdc0 {
struct W1545V4 {
    f32 x, y, z, w;
    W1545V4() {}
    W1545V4(const W1545V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1545V4& operator=(const W1545V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
static inline f32 w1545_vnorm(W1545V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
#define W1545_VSCALE "lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0019fdc0(u8* self, W1545V4* v, f32 s) asm("func_0019fdc0");
void func_0019fdc0(u8* self, W1545V4* v, f32 s) {                     
    f32 w = v->w;
    w1545_vnorm(v);
    W1545V4* d = (W1545V4*)(self + 32);
    W1545V4 t;
    asm volatile(W1545_VSCALE : : "r"(&t), "r"(v), "f"(w) : "$8", "memory");
    *d = t;
    *(f32*)(self + 240) = s;
    func_0016bd60(self, 5);
}
}  // namespace n0019fdc0

// ---- 0019fe48 from src/anon/tiny_auto80_queue.cpp
namespace n0019fe48 {
void func_00184540(u32, u32, f32, f32) asm("_Z13func_00184540jjff");
u32 func_0019fe48(u32 a0, u32, u32 a2) asm("_Z13func_0019fe48jjj");
u32 func_0019fe48(u32 a0, u32, u32 a2) {
    f32 v = *(f32*)((u8*)a2 + 0xF0);
    func_00184540(a0, a2, v, v);
    return a0;
}
}  // namespace n0019fe48

// ---- 0019fe80 from src/anon/tiny.cpp
namespace n0019fe80 {
void func_0019fe80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0019fe80jjjj");
void func_0019fe80(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01c6u << 16);
    *(u32*)((u32)b + (12212)) = (u32)a0;
}
}  // namespace n0019fe80

// ---- 0019fe90 from src/anon/auto80_199_queue.cpp
namespace n0019fe90 {
u32 func_0019fe90(u32 a0, u32 a1, u32, u32, u32, u32, u32, u32) asm("_Z13func_0019fe90jjjjjjjj");
u32 func_0019fe90(u32 a0, u32 a1, u32, u32, u32, u32, u32, u32) {
    u32* base = *(u32**)(&D_01c60000[0x2fb4]);
    u32 v0 = func_002fd248((a0 << 16) | (a1 << 8), (u32)(base + 2), base[1], 48, (u32)&D_0031f158);
    if (*(u8*)(v0 + 37) == 2) {
        return v0 - 48;
    }
    return v0;
}
}  // namespace n0019fe90

// ---- 0019fee8 from src/anon/auto80_199_queue.cpp
namespace n0019fee8 {
u8* func_0019fee8(u8* a0, s32 a1, u32, u32, u32, u32, u32, u32) asm("_Z13func_0019fee8Phijjjjjj");
u8* func_0019fee8(u8* a0, s32 a1, u32, u32, u32, u32, u32, u32) {
    u8* base = (u8*)*(u32**)(&D_01c60000[0x2fb4]);
    u32 stride = 48;
    u8* limit = base + 8 + (*(u32*)(base + 4) * stride);
    u8* cur = a0 + 48;
    u8* out = a0;
    if (cur < limit) {
        s32 mask = -256;
        s32 key = *(s32*)a0 & mask;
        do {
            if (((*(s32*)cur) & mask) != key) {
                break;
            }
            s32 b0 = cur[0];
            if (a1 < b0) {
                break;
            }
            s32 cls = ((a1 - b0) & 1) + 1;
            s32 tag = cur[37];
            if (tag == 0) {
                out = cur;
                cur += 48;
            } else if (cls != tag) {
                cur += 48;
            } else {
                out = cur;
                cur += 48;
            }
        } while (cur < limit);
    }
    return out;
}
}  // namespace n0019fee8

// ---- 0019ff78 from src/anon/tiny_leaf_more.cpp
namespace n0019ff78 {
u32 func_0019ff78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0019ff78jjjj");
u32 func_0019ff78(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(24));
    r4 = (u32)(r4 + r15);
    if (r15 == 0u) r4 = 0u;
    r2 = r4;
    return r2;
}
}  // namespace n0019ff78

// ---- 0019ff90 from src/ys/traps.cpp
namespace n0019ff90 {
extern s32 YS_EVENT_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
void trap_event_is_exec(BD_VALUE* bd) asm("_ZN2YS18trap_event_is_execEP8BD_VALUE");
void trap_event_is_exec(BD_VALUE* bd) { bd->i = YS_EVENT_IsExec(); }
}  // namespace n0019ff90

// ---- 0019ffb8 from src/ys/traps.cpp
namespace n0019ffb8 {
extern void YS_EVENT_ContinueControlOff(void) asm("_ZN2YS5EVENT18ContinueControlOffEv");
void trap_event_continue_control_off(BD_VALUE* bd) asm("_ZN2YS31trap_event_continue_control_offEP8BD_VALUE");
void trap_event_continue_control_off(BD_VALUE* bd) {
    (void)bd;
    YS_EVENT_ContinueControlOff();
}
}  // namespace n0019ffb8

// ---- 0019ffd0 gap trap (trap table 0x350500)
namespace n0019ffd0 {
void func_001bb958(s32) asm("func_001bb958");
void trap_0019ffd0(BD_VALUE* bd) asm("func_0019ffd0");
void trap_0019ffd0(BD_VALUE* bd) { func_001bb958(bd->i); }
}  // namespace n0019ffd0

// ---- 0019ffe8 from src/ys/traps.cpp
namespace n0019ffe8 {
extern void YS_MISSION_Complete(s32) asm("_ZN2YS7MISSION8CompleteEi");
void trap_mission_complete(BD_VALUE* bd) asm("_ZN2YS21trap_mission_completeEP8BD_VALUE");
void trap_mission_complete(BD_VALUE* bd) { YS_MISSION_Complete(bd->i); }
}  // namespace n0019ffe8

// ---- 001a0000 from src/ys/traps.cpp
namespace n001a0000 {
extern void YS_MISSION_DeadBoss(s32) asm("_ZN2YS7MISSION8DeadBossEi");
void trap_mission_dead_boss(BD_VALUE* bd) asm("_ZN2YS22trap_mission_dead_bossEP8BD_VALUE");
void trap_mission_dead_boss(BD_VALUE* bd) { YS_MISSION_DeadBoss(bd->i); }
}  // namespace n001a0000

// ---- 001a0018 from src/ys/traps.cpp
namespace n001a0018 {
extern void YS_MISSION_Failed(void) asm("_ZN2YS7MISSION6FailedEv");
void trap_mission_failed(BD_VALUE* bd) asm("_ZN2YS19trap_mission_failedEP8BD_VALUE");
void trap_mission_failed(BD_VALUE* bd) {
    (void)bd;
    YS_MISSION_Failed();
}
}  // namespace n001a0018

// ---- 001a0030 gap trap (trap table 0x350590)
namespace n001a0030 {
void YS_MISSION_Exit(s32) asm("_ZN2YS7MISSION4ExitEi");
void trap_001a0030(BD_VALUE* bd) asm("func_001a0030");
void trap_001a0030(BD_VALUE* bd) { YS_MISSION_Exit(bd->i); }
}  // namespace n001a0030

// ---- 001a0048 from src/ys/traps.cpp
namespace n001a0048 {
extern void YS_MISSION_Activate2d(void) asm("_ZN2YS7MISSION10Activate2dEv");
void trap_mission_activate2d(BD_VALUE* bd) asm("_ZN2YS23trap_mission_activate2dEP8BD_VALUE");
void trap_mission_activate2d(BD_VALUE* bd) {
    (void)bd;
    YS_MISSION_Activate2d();
}
}  // namespace n001a0048

// ---- 001a0060 gap traps (trap table 0x350550, 0x350558, 0x350588)
namespace n001a0060 {
void func_001d8010() asm("func_001d8010");
void func_001d80f0() asm("func_001d80f0");
s32 func_001d8158() asm("func_001d8158");
void trap_001a0060(BD_VALUE* bd) asm("func_001a0060");
void trap_001a0060(BD_VALUE* bd) { func_001d8010(); }
void trap_001a0078(BD_VALUE* bd) asm("func_001a0078");
void trap_001a0078(BD_VALUE* bd) { func_001d80f0(); }
void trap_001a0090(BD_VALUE* bd) asm("func_001a0090");
void trap_001a0090(BD_VALUE* bd) { bd->i = func_001d8158(); }
}  // namespace n001a0060

// ---- 001a00b8 from src/ys/traps.cpp
namespace n001a00b8 {
extern void YS_MISSION_Return(void) asm("_ZN2YS7MISSION6ReturnEv");
void trap_mission_is_activate2d(BD_VALUE* bd) asm("_ZN2YS26trap_mission_is_activate2dEP8BD_VALUE");
void trap_mission_is_activate2d(BD_VALUE* bd) {
    (void)bd;
    YS_MISSION_Return();
}
}  // namespace n001a00b8

// ---- 001a00d0 gap trap (trap table 0x350690)
namespace n001a00d0 {
extern u8 D_00351ec8[] asm("D_00351ec8");
void YS_MUTEX_lock(void*, s32) asm("_ZN2YS5MUTEX4lockEi");
void trap_001a00d0(BD_VALUE* bd) asm("func_001a00d0");
void trap_001a00d0(BD_VALUE* bd) { YS_MUTEX_lock(D_00351ec8, 0); }
}  // namespace n001a00d0

// ---- 001a00f0 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001a00f0 {
u32 func_001c8db8(u32, u32, u32, u32) asm("_Z13func_001c8db8jjjj");
extern u8 D_00351ec8 asm("D_00351ec8");
u32 func_001a00f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001a00f0jjjj");
u32 func_001a00f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r5 = 0u;
    r16 = r4;
    r4 = (u32)&D_00351ec8;
    r2 = func_001c8db8(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001a00f0

// ---- 001a0128 from src/ys/traps.cpp
namespace n001a0128 {
extern void YS_MISSION_RestartTimer(s32, s32) asm("_ZN2YS7MISSION12RestartTimerEii");
void trap_mission_restart_timer(BD_VALUE* bd) asm("_ZN2YS26trap_mission_restart_timerEP8BD_VALUE");
void trap_mission_restart_timer(BD_VALUE* bd) { YS_MISSION_RestartTimer(bd->i, bd[1].i); }
}  // namespace n001a0128

// ---- 001a0148 gap trap
namespace n001a0148 {
u32 func_001d8270(u32, u32, u32, u32) asm("func_001d8270");
void trap_001a0148(u32 a0) asm("func_001a0148");
void trap_001a0148(u32 a0) {
    func_001d8270(((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), ((u32)(*(u32*)((u32)(a0) + 8u))), ((u32)(*(u32*)((u32)(a0) + 12u))));
}
}  // namespace n001a0148

// ---- 001a0170 from src/ys/traps.cpp
namespace n001a0170 {
extern void dk_Timer_pauseOn(s32) asm("_ZN2dk5Timer7pauseOnEj");
void trap_mission_pause_timer(BD_VALUE* bd) asm("_ZN2YS24trap_mission_pause_timerEP8BD_VALUE");
void trap_mission_pause_timer(BD_VALUE* bd) {
    (void)bd;
    dk_Timer_pauseOn(2);
}
}  // namespace n001a0170

// ---- 001a0188 from src/ys/traps.cpp
namespace n001a0188 {
extern void dk_Timer_pauseOff(s32) asm("_ZN2dk5Timer8pauseOffEj");
void trap_mission_cancel_pause_timer(BD_VALUE* bd) asm("_ZN2YS31trap_mission_cancel_pause_timerEP8BD_VALUE");
void trap_mission_cancel_pause_timer(BD_VALUE* bd) {
    (void)bd;
    dk_Timer_pauseOff(2);
}
}  // namespace n001a0188

// ---- 001a01a0 from src/ys/traps.cpp
namespace n001a01a0 {
extern s32 YS_MISSION_GetTimer(s32) asm("_ZN2YS7MISSION8GetTimerEi");
void trap_mission_get_timer(BD_VALUE* bd) asm("_ZN2YS22trap_mission_get_timerEP8BD_VALUE");
void trap_mission_get_timer(BD_VALUE* bd) { bd->i = YS_MISSION_GetTimer(bd->i); }
}  // namespace n001a01a0

// ---- 001a01d0 from src/ys/traps.cpp
namespace n001a01d0 {
extern s32 YS_MISSION_GetTimerSecond(s32) asm("_ZN2YS7MISSION14GetTimerSecondEi");
void trap_mission_get_timer_second(BD_VALUE* bd) asm("_ZN2YS29trap_mission_get_timer_secondEP8BD_VALUE");
void trap_mission_get_timer_second(BD_VALUE* bd) { bd->i = YS_MISSION_GetTimerSecond(bd->i); }
}  // namespace n001a01d0

// ---- 001a0200 from src/ys/traps.cpp
namespace n001a0200 {
extern void YS_MISSION_WarningTimer(s32) asm("_ZN2YS7MISSION12WarningTimerEi");
void trap_mission_warning_timer(BD_VALUE* bd) asm("_ZN2YS26trap_mission_warning_timerEP8BD_VALUE");
void trap_mission_warning_timer(BD_VALUE* bd) { YS_MISSION_WarningTimer(bd->i); }
}  // namespace n001a0200

// ---- 001a0218 from src/ys/traps.cpp
namespace n001a0218 {
extern void YS_MISSION_DisableTimer(s32) asm("_ZN2YS7MISSION12DisableTimerEi");
void trap_mission_disable_timer(BD_VALUE* bd) asm("_ZN2YS26trap_mission_disable_timerEP8BD_VALUE");
void trap_mission_disable_timer(BD_VALUE* bd) { YS_MISSION_DisableTimer(bd->i); }
}  // namespace n001a0218

// ---- 001a0230 from src/ys/traps.cpp
namespace n001a0230 {
extern void YS_MISSION_SetWatch(s32, s32) asm("_ZN2YS7MISSION8SetWatchEii");
void trap_mission_set_watch(BD_VALUE* bd) asm("_ZN2YS22trap_mission_set_watchEP8BD_VALUE");
void trap_mission_set_watch(BD_VALUE* bd) { YS_MISSION_SetWatch(bd->i, bd[1].i); }
}  // namespace n001a0230

// ---- 001a0250 gap trap
namespace n001a0250 {
void func_001d9488(s32) asm("func_001d9488");
void trap_001a0250(BD_VALUE* bd) asm("func_001a0250");
void trap_001a0250(BD_VALUE* bd) { func_001d9488(bd->i); }
}  // namespace n001a0250

// ---- 001a0268 from src/ys/traps.cpp
namespace n001a0268 {
extern void YS_MISSION_SetCount(s32, s32) asm("_ZN2YS7MISSION8SetCountEii");
void trap_mission_decrement_count(BD_VALUE* bd) asm("_ZN2YS28trap_mission_decrement_countEP8BD_VALUE");
void trap_mission_decrement_count(BD_VALUE* bd) { YS_MISSION_SetCount(bd->i, bd[1].i); }
}  // namespace n001a0268

// ---- 001a0288 gap traps (trap table 0x350510, 0x350580)
namespace n001a0288 {
void YS_MISSION_AddCount(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
void trap_001a0288(BD_VALUE* bd) asm("func_001a0288");
void trap_001a0288(BD_VALUE* bd) { YS_MISSION_AddCount(1, bd->i); }
void trap_001a02a8(BD_VALUE* bd) asm("func_001a02a8");
void trap_001a02a8(BD_VALUE* bd) { YS_MISSION_AddCount(-1, bd->i); }
}  // namespace n001a0288

// ---- 001a02c8 gap trap
namespace n001a02c8 {
u32 func_001d8578(u32, u32, u32, u32) asm("func_001d8578");
void trap_001a02c8(u32 a0) asm("func_001a02c8");
void trap_001a02c8(u32 a0) {
    func_001d8578(((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), ((u32)(*(u32*)((u32)(a0) + 8u))), ((u32)(*(u32*)((u32)(a0) + 12u))));
}
}  // namespace n001a02c8

// ---- 001a02f0 from src/ys/traps.cpp
namespace n001a02f0 {
extern s32 YS_MISSION_GetCount(s32) asm("_ZN2YS7MISSION8GetCountEi");
void trap_mission_get_count(BD_VALUE* bd) asm("_ZN2YS22trap_mission_get_countEP8BD_VALUE");
void trap_mission_get_count(BD_VALUE* bd) { bd->i = YS_MISSION_GetCount(bd->i); }
}  // namespace n001a02f0

// ---- 001a0320 from src/ys/traps.cpp
namespace n001a0320 {
extern void YS_MISSION_AddCount(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
void trap_mission_add_count(BD_VALUE* bd) asm("_ZN2YS22trap_mission_add_countEP8BD_VALUE");
void trap_mission_add_count(BD_VALUE* bd) { YS_MISSION_AddCount(bd->i, bd[1].i); }
}  // namespace n001a0320

// ---- 001a0340 gap trap
namespace n001a0340 {
void func_001d8908(s32) asm("func_001d8908");
void trap_001a0340(BD_VALUE* bd) asm("func_001a0340");
void trap_001a0340(BD_VALUE* bd) { func_001d8908(bd->i); }
}  // namespace n001a0340

// ---- 001a0358 from src/ys/traps.cpp
namespace n001a0358 {
extern void YS_MISSION_DisableCount(s32, s32) asm("_ZN2YS7MISSION12DisableCountEi");
void trap_mission_disable_count(BD_VALUE* bd) asm("_ZN2YS26trap_mission_disable_countEP8BD_VALUE");
void trap_mission_disable_count(BD_VALUE* bd) { YS_MISSION_DisableCount(bd->i, bd[1].i); }
}  // namespace n001a0358

// ---- 001a0378 gap traps (trap table 0x350660, 0x350670, 0x3506b0, 0x350520)
namespace n001a0378 {
u32 func_001d89e8(u32, u32, u32) asm("func_001d89e8");
void func_001d8ad8(s32, s32) asm("func_001d8ad8");
void func_001d8c70(f32, s32) asm("func_001d8c70");
void trap_001a0378(u32 a0) asm("func_001a0378");
void trap_001a0378(u32 a0) {
    func_001d89e8(((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), ((u32)(*(u32*)((u32)(a0) + 8u))));
}
void trap_001a03a0(BD_VALUE* bd) asm("func_001a03a0");
void trap_001a03a0(BD_VALUE* bd) { func_001d8ad8(bd->i, 1); }
void trap_001a03c0(BD_VALUE* bd) asm("func_001a03c0");
void trap_001a03c0(BD_VALUE* bd) { func_001d8ad8(bd->i, 0); }
void trap_001a03e0(BD_VALUE* bd) asm("func_001a03e0");
void trap_001a03e0(BD_VALUE* bd) { func_001d8c70(bd->f, bd[1].i); }
}  // namespace n001a0378

// ---- 001a0400 from src/anon/tiny_auto80_queue.cpp
namespace n001a0400 {
void func_001d8d08(f32, u32) asm("_Z13func_001d8d08fj");
void func_001a0400(u32* param_1) asm("_Z13func_001a0400Pj");
void func_001a0400(u32* param_1) {
    func_001d8d08(*(f32*)&param_1[0], param_1[1]);
}
}  // namespace n001a0400

// ---- 001a0420 from src/anon/tiny_auto80_queue.cpp
namespace n001a0420 {
void func_001d8da0(f32, u32) asm("_Z13func_001d8da0fj");
void func_001a0420(u32* param_1) asm("_Z13func_001a0420Pj");
void func_001a0420(u32* param_1) {
    func_001d8da0(*(f32*)&param_1[0], param_1[1]);
}
}  // namespace n001a0420

// ---- 001a0440 from src/ys/traps.cpp
namespace n001a0440 {
extern f32 YS_MISSION_GetGaugeRatio(s32) asm("_ZN2YS7MISSION13GetGaugeRatioEi");
void trap_mission_get_gauge_ratio(BD_VALUE* bd) asm("_ZN2YS28trap_mission_get_gauge_ratioEP8BD_VALUE");
void trap_mission_get_gauge_ratio(BD_VALUE* bd) { bd->f = YS_MISSION_GetGaugeRatio(bd->i); }
}  // namespace n001a0440

// ---- 001a0470 from src/anon/tiny_wrappers_more.cpp
namespace n001a0470 {
u32 func_001d8bd0(u32, u32, u32, u32) asm("_Z13func_001d8bd0jjjj");
u32 func_001a0470(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001a0470jjjj");
u32 func_001a0470(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d8bd0(((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), ((u32)(*(u32*)((u32)(a0) + 8u))), ((u32)(*(u32*)((u32)(a0) + 12u))));
}
}  // namespace n001a0470

// ---- 001a0498 from src/ys/traps.cpp
namespace n001a0498 {
extern f32 YS_MISSION_GetGaugeWarningRatio(s32) asm("_ZN2YS7MISSION20GetGaugeWarningRatioEi");
void trap_mission_get_gauge_warning_ratio(BD_VALUE* bd) asm("_ZN2YS36trap_mission_get_gauge_warning_ratioEP8BD_VALUE");
void trap_mission_get_gauge_warning_ratio(BD_VALUE* bd) { bd->f = YS_MISSION_GetGaugeWarningRatio(bd->i); }
}  // namespace n001a0498

// ---- 001a04c8 from src/ys/traps.cpp
namespace n001a04c8 {
extern s32 YS_MISSION_IsGaugeWarning(s32) asm("_ZN2YS7MISSION14IsGaugeWarningEi");
void trap_mission_is_gauge_warning(BD_VALUE* bd) asm("_ZN2YS29trap_mission_is_gauge_warningEP8BD_VALUE");
void trap_mission_is_gauge_warning(BD_VALUE* bd) { bd->i = YS_MISSION_IsGaugeWarning(bd->i); }
}  // namespace n001a04c8

// ---- 001a04f8 from src/anon/batch_w5.cpp
namespace n001a04f8 {
void func_001d8fa8(u32, u32) asm("func_001d8fa8");
void func_001a04f8(BD_VALUE* bd) asm("func_001a04f8");
void func_001a04f8(BD_VALUE* bd) {
    func_001d8fa8(bd[0].i != 0, bd[1].u);
}
}  // namespace n001a04f8

// ---- 001a0520 gap trap (trap table 0x3505a8)
namespace n001a0520 {
void func_001d9050(s32, f32, s32) asm("func_001d9050");
void trap_001a0520(BD_VALUE* bd) asm("func_001a0520");
void trap_001a0520(BD_VALUE* bd) { func_001d9050(1, bd->f, 0); }
}  // namespace n001a0520

// ---- 001a0540 from src/ys/traps.cpp
namespace n001a0540 {
extern void YS_MISSION_ResetComboCounter(s32) asm("_ZN2YS7MISSION17ResetComboCounterEi");
void trap_mission_start_combo_counter(BD_VALUE* bd) asm("_ZN2YS32trap_mission_start_combo_counterEP8BD_VALUE");
void trap_mission_start_combo_counter(BD_VALUE* bd) {
    (void)bd;
    YS_MISSION_ResetComboCounter(0);
}
}  // namespace n001a0540

// ---- 001a0558 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001a0558 {
u32 func_001d9148(u32, u32, u32, u32) asm("_Z13func_001d9148jjjj");
u32 func_001a0558(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001a0558jjjj");
u32 func_001a0558(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r4 = 0u;
    r2 = func_001d9148(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001a0558

// ---- 001a0588 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001a0588 {
u32 func_001d9228(u32, u32, u32, u32) asm("_Z13func_001d9228jjjj");
u32 func_001a0588(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001a0588jjjj");
u32 func_001a0588(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r4 = 0u;
    r2 = func_001d9228(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001a0588

// ---- 001a05b8 from src/anon/tiny_auto80_queue.cpp
namespace n001a05b8 {
void func_001d9050(u32, u32, f32) asm("_Z13func_001d9050jjf");
void func_001a05b8(u32* param_1) asm("_Z13func_001a05b8Pj");
void func_001a05b8(u32* param_1) {
    f32 v = *(f32*)((u8*)param_1 + 4);
    func_001d9050(param_1[0], 0u, v);
}
}  // namespace n001a05b8

// ---- 001a05d8 from src/ys/traps.cpp
namespace n001a05d8 {
extern void YS_MISSION_SetMaxComboCounter(s32, s32) asm("_ZN2YS7MISSION18SetMaxComboCounterEii");
void trap_mission_set_combo_counter_param(BD_VALUE* bd) asm("_ZN2YS36trap_mission_set_combo_counter_paramEP8BD_VALUE");
void trap_mission_set_combo_counter_param(BD_VALUE* bd) {
    YS_MISSION_SetMaxComboCounter(bd->i, bd[1].i);
}
}  // namespace n001a05d8

// ---- 001a05f8 gap trap
namespace n001a05f8 {
u32 func_001d9288(u32, u32, u32, u32) asm("func_001d9288");
void trap_001a05f8(u32 a0) asm("func_001a05f8");
void trap_001a05f8(u32 a0) {
    func_001d9288(((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), ((u32)(*(u32*)((u32)(a0) + 8u))), ((u32)(*(u32*)((u32)(a0) + 12u))));
}
}  // namespace n001a05f8

// ---- 001a0620 from src/ys/traps.cpp
namespace n001a0620 {
extern void YS_MISSION_WarningComboCounter(s32) asm("_ZN2YS7MISSION19WarningComboCounterEi");
void trap_mission_warning_combo_counter(BD_VALUE* bd) asm("_ZN2YS34trap_mission_warning_combo_counterEP8BD_VALUE");
void trap_mission_warning_combo_counter(BD_VALUE* bd) { YS_MISSION_WarningComboCounter(bd->i); }
}  // namespace n001a0620

// ---- 001a0638 from src/ys/traps.cpp
namespace n001a0638 {
extern void YS_MISSION_SetComboCounterWarningSe(s32, s32) asm("_ZN2YS7MISSION24SetComboCounterWarningSeEii");
void trap_mission_set_combo_counter_warning_se(BD_VALUE* bd) asm("_ZN2YS41trap_mission_set_combo_counter_warning_seEP8BD_VALUE");
void trap_mission_set_combo_counter_warning_se(BD_VALUE* bd) {
    YS_MISSION_SetComboCounterWarningSe(bd->i, bd[1].i);
}
}  // namespace n001a0638

// ---- 001a0658 gap traps (trap table 0x3505f8, 0x350600)
namespace n001a0658 {
void trap_001a0658(BD_VALUE* bd) asm("func_001a0658");
void trap_001a0658(BD_VALUE* bd) { bd->i = *(u8*)bd->p; }
void trap_001a0668(BD_VALUE* bd) asm("func_001a0668");
void trap_001a0668(BD_VALUE* bd) { bd->i = ((s32*)bd->p)[1]; }
}  // namespace n001a0658

// ---- 001a0678 from src/anon/batch_w14.cpp
namespace n001a0678 {
void* func_001d5af8(void*, void*, void*) asm("func_001d5af8");
void func_001a0678(void** p) asm("func_001a0678");
void func_001a0678(void** p) {
    p[0] = func_001d5af8(p[0], p[1], p[2]);
}
}  // namespace n001a0678

// ---- 001a06b0 from src/ys/traps.cpp
namespace n001a06b0 {
extern s32 YS_MINIGAME_GetScore(s32) asm("_ZN2YS8MINIGAME8GetScoreEi");
void trap_score_get(BD_VALUE* bd) asm("_ZN2YS14trap_score_getEP8BD_VALUE");
void trap_score_get(BD_VALUE* bd) { bd->i = YS_MINIGAME_GetScore(bd->i); }
}  // namespace n001a06b0

// ---- 001a06e0 from src/anon/batch_w9.cpp
namespace n001a06e0 {
u32 func_001d96c0(u32, u32) asm("func_001d96c0");
void func_001a06e0(u32* p) asm("func_001a06e0");
void func_001a06e0(u32* p) {
    p[0] = func_001d96c0(p[0], p[1]);
}
}  // namespace n001a06e0

// ---- 001a0710 from src/anon/batch_w1545.cpp
namespace n001a0710 {
struct W1545V4 {
    f32 x, y, z, w;
    W1545V4() {}
    W1545V4(const W1545V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1545V4& operator=(const W1545V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
static inline f32 w1545_vnorm(W1545V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
#define W1545_VSCALE "lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_001a0710(u8* self, W1545V4* v, f32 s) asm("func_001a0710");
void func_001a0710(u8* self, W1545V4* v, f32 s) {
    f32 w = v->w;
    w1545_vnorm(v);
    W1545V4* d = (W1545V4*)(self + 32);
    W1545V4 t;
    asm volatile(W1545_VSCALE : : "r"(&t), "r"(v), "f"(w) : "$8", "memory");
    *d = t;
    *(f32*)(self + 240) = s;
    func_0016bd60(self, 6);
}
}  // namespace n001a0710

// ---- 001a0798 from src/yasui/libys/obj.cpp
namespace YS {
u32 OBJ::is_hover() {
    u32 p = *(u32*)((u32)this + 12);
    u32 v = *(u32*)((u32)p + 4);
    v ^= 0x6u;
    return (v < 1u);
}
}  // namespace YS (001a0798)

// ---- 001a07b0 from src/anon/batch_w31.cpp
namespace n001a07b0 {
void** func_0017aab8(int) asm("func_0017aab8");
typedef void (*VFn3)(void*, void*, u32);
void* func_001a07b0(void* p, u32 a, u32 b) asm("func_001a07b0");
void* func_001a07b0(void* p, u32 a, u32 b) {
    void** o = func_0017aab8(5);
    (*(VFn3*)(*(u8**)o + 28))(p, o, b);
    return p;
}
}  // namespace n001a07b0

// ---- 001a0800 from src/anon/batch_w100.cpp
namespace n001a0800 {
struct Box16 {
    u32 f0;
    s32 b0 : 1; s32 b1 : 1; s32 b2 : 1; s32 b3 : 1; s32 b4 : 1; s32 rest : 27;
    u8 pad[24];
    f32 x0, x1, top, bottom, z1, z0;
};
static inline bool B1(Box16* b) { return b->b1; }
static inline bool B3(Box16* b) { return b->b3; }
static inline bool B4(Box16* b) { return b->b4; }
f32 func_0016c4e8(u32) asm("func_0016c4e8");
bool func_001a0800(Box16* b, u32 w, f32* d, f32 x, f32 y, f32 z) asm("func_001a0800");
bool func_001a0800(Box16* b, u32 w, f32* d, f32 x, f32 y, f32 z) {
    f32 top = b->top;
    f32 bot = b->bottom;
    if (B1(b)) bot -= func_0016c4e8(w);
    if (B3(b)) top -= d[2];
    else top += d[2];
    if (B4(b)) bot += d[2];
    else bot -= d[2];
    return b->x0 <= x && x < b->x1 && y <= top && bot < y && z <= b->z0 && b->z1 < z;
}
}  // namespace n001a0800

// ---- 001a0920 from src/anon/batch_w2440.cpp
namespace n001a0920 {
struct A2_w2440 { u8 pad0[3]; s8 id; s32 fl; u16 h8; u8 pad[0x36]; u16 h40; };
struct BB_w2440 { u8 pad[0x1cc]; u32 bits[1]; };
struct B_w2440 { u8 pad[0x48c]; BB_w2440* p; };
s32 func_001778c0(B_w2440*, s8) asm("func_001778c0");
s32 func_00177958(B_w2440*) asm("func_00177958");
u32 func_0019c090(B_w2440*) asm("func_0019c090");
static inline __attribute__((always_inline)) s32 check_001a0920(A2_w2440* a, B_w2440* b) {
    if (a->h8 == 0) return 0;
    u32 f = a->h40;
    if (f != 0 && !(*(u32*)((u8*)b->p->bits + ((f >> 5) << 2)) & (1 << (f & 0x1f)))) return 0;
    if (func_0019c090(b) != (u32)(a->fl & 1)) return 0;
    if ((u8)((a->fl >> 2) & 1)) { if (!func_001778c0(b, a->id)) return 0; }
    else if (func_00177958(b)) return 0;
    return 1;
}
s32 func_001a0920(A2_w2440* a, B_w2440* b) asm("func_001a0920");
s32 func_001a0920(A2_w2440* a, B_w2440* b) {
    return check_001a0920(a, b);
}
}  // namespace n001a0920

// ---- 001a09f0 gap function (vtable 0x350708)
namespace n001a09f0 {
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_001a09f0(void* self, u8* o) asm("func_001a09f0");
void func_001a09f0(void* self, u8* o) {
    struct NoTail { ~NoTail() {} } nt;
    if (*(f32*)(o + 212) <= *(f32*)(o + 208) + 5.0f) {
        u8* s = o + 320;
        if (*(s32*)(s + 20) == 155) func_0017f488(s, 156, 0.0f, 0.0f);
    }
}
}  // namespace n001a09f0

// ---- 001a0a48 from src/anon/batch_w83.cpp
namespace n001a0a48 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
extern f32 D_00349e10 asm("D_00349e10");
f32 func_0017c930(void*, void*) asm("func_0017c930");
Vec4 func_00184540(f32, f32) asm("func_00184540");
s32 func_00180618(void*) asm("func_00180618");
Vec4 func_001a0a48(void* a, u8* o) asm("func_001a0a48");
Vec4 func_001a0a48(void* a, u8* o) {
    Vec4 r;
    f32 t = *(f32*)(o + 208) + D_00349e10;
    if (t < *(f32*)(o + 212)) {
        *(f32*)(o + 208) = t;
        r.y = func_0017c930(a, o);
        r.x = r.z = 0.0f;
        return r;
    }
    r = func_00184540(0.95f, 0.9f);
    u8* s = o + 320;
    if (*(s32*)(s + 20) == 156 && !func_00180618(s)) {
        r.y = 0;
        return r;
    }
    *(f32*)(o + 208) = t;
    r.y = func_0017c930(a, o);
    return r;
}
}  // namespace n001a0a48

// ---- 001a0b40 gap function (vtable 0x350700)
namespace n001a0b40 {
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
void func_001a0b40(void* self, u8* o) asm("func_001a0b40");
void func_001a0b40(void* self, u8* o) {
    f32 z = 0.0f;
    func_0016bd60(o, 0);
    u8* s = o + 320;
    func_0017f488(s, 157, z, z);
    func_0017f5e0(s, 0, 0, z, z);
    *(u32*)(o + 264) |= 0x8000000;
}
}  // namespace n001a0b40

// ---- 001a0bc0 from src/anon/auto80_199_queue.cpp
namespace n001a0bc0 {
void func_001a0bc0() asm("_Z13func_001a0bc0v");
void func_001a0bc0() {
    u8* base = D_01c62fb8;
    s32 i = 0;
    u32 off = 0x9a00;
    u32* p = (u32*)(base + off);
    do {
        *p = (u32)i;
        i += 1;
        p += 1;
    } while (i < 64);

    u8* base2 = D_01c62fb8;
    u32 off2 = 0x8000;
    u32 value = 64;
    *(u32*)(base2 + off2 + 6912) = value;
    D_01c70000[-3409] = 0;
}
}  // namespace n001a0bc0

// ---- 001a0c18 from src/anon/batch_w1834_nsa.cpp
namespace n001a0c18 {
struct W1834E12 { s32 a, b, c; };
struct W1834H4 { s16 a, b, c, d; };
struct W1834P2 { s32 n, m; };
struct W1834Grp { s32 a[8]; u8 pad[0x78 - 0x20]; };
struct W1834Big {
    W1834E12 e[32];                 
    s32 f180, f184;                 
    W1834H4 h188, h190;             
    W1834P2 p198, p1a0;             
    u8 c1a8[7];                     
    u8 b1af, b1b0, b1b1, b1b2;
    s32 w1b4[6];                    
    W1834Grp grp;                   
    s32 f244, f248;
    u8 b24c; u8 pad24d[3];
    s32 f250, f254, f258, f25c, f260, f264;
};
void func_001c2f90(W1834Grp*, W1834Big*) asm("func_001c2f90");
static inline void w1834_h4_init(W1834H4* h) { h->a = 0; h->b = 0; h->c = 0; h->d = 0; }
static inline void w1834_p2_init(W1834P2* p) { p->n = 99999; p->m = 1; }
static inline void w1834_grp_init(W1834Grp* g) { s32 k; for (k = 0; k < 8; k++) g->a[k] = 0; }
void func_001a0c18(W1834Big* o) asm("func_001a0c18");
void func_001a0c18(W1834Big* o) {
    W1834E12* e = o->e;
    s32 i = 31;
    do { e->a = 0; e->b = 0; e->c = 0; e++; i--; } while (i != -1);
    o->f180 = 0; o->f184 = 0;
    w1834_h4_init(&o->h188); w1834_h4_init(&o->h190);
    w1834_p2_init(&o->p198); w1834_p2_init(&o->p1a0);
    o->b1af = 0; o->b1b0 = 0; o->b1b1 = 0; o->b1b2 = 0;
    o->w1b4[0] = 0; o->w1b4[1] = 0; o->w1b4[2] = 0; o->w1b4[3] = 0; o->w1b4[4] = 0; o->w1b4[5] = 0;
    w1834_grp_init(&o->grp);
    o->f244 = 0; o->f248 = 0; o->b24c = 0; o->f250 = 0;
    o->f254 = -1; o->f258 = 1; o->f25c = 0; o->f260 = 0; o->f264 = 0;
    s32 k;
    for (k = 0; k < 7; k++) o->c1a8[k] = 100;
    func_001c2f90(&o->grp, o);
}
}  // namespace n001a0c18

// ---- 001a0d48 from src/anon/batch_w1834_nsa.cpp
namespace n001a0d48 {
struct W1834E12 { s32 a, b, c; };
struct W1834H4 { s16 a, b, c, d; };
struct W1834P2 { s32 n, m; };
struct W1834Grp { s32 a[8]; u8 pad[0x78 - 0x20]; };
struct W1834Big {
    W1834E12 e[32];                 
    s32 f180, f184;                 
    W1834H4 h188, h190;             
    W1834P2 p198, p1a0;             
    u8 c1a8[7];                     
    u8 b1af, b1b0, b1b1, b1b2;
    s32 w1b4[6];                    
    W1834Grp grp;                   
    s32 f244, f248;
    u8 b24c; u8 pad24d[3];
    s32 f250, f254, f258, f25c, f260, f264;
};
void func_001c2f90(W1834Grp*, W1834Big*) asm("func_001c2f90");
static inline void w1834_h4_init(W1834H4* h) { h->a = 0; h->b = 0; h->c = 0; h->d = 0; }
static inline void w1834_p2_init(W1834P2* p) { p->n = 99999; p->m = 1; }
static inline void w1834_grp_init(W1834Grp* g) { s32 k; for (k = 0; k < 8; k++) g->a[k] = 0; }
void func_001a0d48(W1834Big* o) asm("func_001a0d48");
void func_001a0d48(W1834Big* o) {
    W1834E12* e = o->e;
    s32 i = 31;
    do { e->a = 0; e->b = 0; e->c = 0; e++; i--; } while (i != -1);
    o->f180 = 0; o->f184 = 0;
    w1834_h4_init(&o->h188); w1834_h4_init(&o->h190);
    w1834_p2_init(&o->p198); w1834_p2_init(&o->p1a0);
    o->b1af = 0; o->b1b0 = 0; o->b1b1 = 0; o->b1b2 = 0;
    o->w1b4[0] = 0; o->w1b4[1] = 0; o->w1b4[2] = 0; o->w1b4[3] = 0; o->w1b4[4] = 0; o->w1b4[5] = 0;
    w1834_grp_init(&o->grp);
    o->f244 = 0; o->f248 = 0; o->b24c = 0; o->f250 = 0;
    o->f254 = -1; o->f258 = 1; o->f25c = 0; o->f260 = 0; o->f264 = 0;
    s32 k;
    for (k = 0; k < 7; k++) o->c1a8[k] = 100;
    func_001c2f90(&o->grp, o);
}
}  // namespace n001a0d48

// ---- 001a0e78 from src/anon/auto80_199_queue.cpp
namespace n001a0e78 {
void* func_001a0e78() asm("_Z13func_001a0e78v");
void* func_001a0e78() {
    u8* base = D_01c62fb8;
    u32 off = 0x8000;
    u8* p = base + off;
    u32 n = *(u32*)(p + 6912) - 1;
    *(u32*)(p + 6912) = n;
    u32 idx = *(u32*)(base + 0x9a00 + (n << 2));
    void* out = base + (idx * 616);
    func_001a0d48(out);
    return out;
}
}  // namespace n001a0e78

// ---- 001a0ee0 from src/anon/batch_w1839_nsa.cpp
namespace n001a0ee0 {
struct Ent { s32 a; s32 b; s32 c; };
struct Dst {
    Ent e[32];
    u8 pad0[0x188 - 0x180]; u16 h188; u16 pad18a; u16 h18c; u16 pad18e;
    u8 pad1[0x198 - 0x190]; s32 w198; s32 w19c; s32 w1a0; s32 w1a4;
    u8 b1a8[7];
    u8 pad2[0x1c4 - 0x1af]; f32 f1c4;
    u8 pad3[0x264 - 0x1c8]; struct Src* src;
};
struct Src { u16 h0; u16 id; u16 v[32]; u16 m44; u16 m46; u16 k[7]; };
struct G { u8 pad[300]; f32 f; };
extern G* D_00352130 asm("D_00352130");
u16* func_001c0c80(u16) asm("func_001c0c80");
u16* func_001c0cc8(void) asm("func_001c0cc8");
void func_001a0ee0(Dst* d, Src* s) asm("func_001a0ee0");
void func_001a0ee0(Dst* d, Src* s) {
    u16* t;
    s32 i;
    if (s->id) t = func_001c0c80(s->id);
    else t = func_001c0cc8();
    for (i = 0; i < 32; i++) {
        d->e[i].b = d->e[i].a = (t[0] * s->v[i] + 99) / 100;
        d->e[i].c = 0;
    }
    d->h188 = t[1];
    d->h18c = t[2];
    d->w198 = t[3];
    d->w19c = t[4];
    s32 r = d->e[0].b;
    d->w1a0 = (r * s->m44 + 9999) / 10000;
    d->w1a4 = (r * s->m46 + 9999) / 10000;
    for (i = 0; i < 7; i++) d->b1a8[i] = s->k[i];
    d->f1c4 = D_00352130->f;
    d->src = s;
}
}  // namespace n001a0ee0

// ---- 001a1018 from src/anon/batch_w26.cpp
namespace n001a1018 {
inline void* operator new(unsigned int, void* p) { return p; }
void* sheet_ctor(void*) asm("_ZN2YS5SHEETC1Ev");
void* func_001db5a8(void*) asm("func_001db5a8");
void func_001a0ee0(void*, void*) asm("func_001a0ee0");
void* func_001a1018(void* a) asm("func_001a1018");
void* func_001a1018(void* a) {
    void* s = sheet_ctor(a);
    func_001a0ee0(s, func_001db5a8(a));
    return s;
}
}  // namespace n001a1018

// ---- 001a1060 from src/anon/batch_w447.cpp
namespace n001a1060 {
struct W447E1a1 { u8 p0[600]; s32 cnt; u8 p604[8]; s32 key; };
struct W447P1a1 { W447E1a1 e[64]; s32 freel[64]; s32 nfree; };
extern W447P1a1 D_01c62fb8 asm("D_01c62fb8");
s32 func_001db5a8(u32) asm("func_001db5a8");
W447E1a1* func_001a1018(u32) asm("func_001a1018");
static inline __attribute__((always_inline)) W447E1a1* w447_next1a1(W447E1a1* p)
{
    W447E1a1* q = D_01c62fb8.e;
    if (p) q = p + 1;
    while (q < D_01c62fb8.e + 64) {
        s32 idx = q - D_01c62fb8.e;
        s32 i;
        for (i = 0; i < D_01c62fb8.nfree; i++) {
            if (D_01c62fb8.freel[i] == idx) { q++; break; }
        }
        if (i == D_01c62fb8.nfree) return q;
    }
    return 0;
}
W447E1a1* func_001a1060(u32 a0) asm("func_001a1060");
W447E1a1* func_001a1060(u32 a0)
{
    W447E1a1* p = 0;
    s32 v;
    v = func_001db5a8(a0);
    while ((p = w447_next1a1(p)) != 0) {
        if (p->key == v) {
            p->cnt++;
            return p;
        }
    }
    return func_001a1018(a0);
}
}  // namespace n001a1060

// ---- 001a11b0 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001a11b0 {
u32 func_00189200(u32, u32, u32, u32) asm("_Z13func_00189200jjjj");
extern u8 D_0032e020 asm("D_0032e020");
u32 func_001a11b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001a11b0jjjj");
u32 func_001a11b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r4 = (u32)&D_0032e020;
    r2 = func_00189200(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(584)) = r2;
    return r2;
}
}  // namespace n001a11b0

// ---- 001a11e0 from src/anon/batch_w1635.cpp
namespace n001a11e0 {
struct W1635SheetData;
struct W1635Obj;
struct W1635Gauge {
    s32 cur;                    
    s32 max;                    
    s32 x8;                     
};
struct W1635FormInfo {
    u8 pad0[4];
    u8 str, mag, def;                 
};
struct W1635Drive {
    u8 pad0[0x1038];
    u8 c[4];                        
    f32 f0, f1;                     
};
union W1635Int { s32 v; f32 f; };
struct W1635Sheet {
    W1635Gauge g[1];                                                                   
    u8 pad0c[0x180 - 0xc];
    s32 x180;                      
    s32 x184;                      
    u16 stat[4];                   
    u16 stat2[4];                  
    s32 lo;                                           
    s32 hi;                                           
    s32 x1a0;                      
    s32 x1a4;                      
    u8 rate[7];                                               
    u8 pad1af;
    u8 c[4];                       
    f32 f1b4, f1b8;                
    f32 f1bc, f1c0;                
    u8 pad1c4[0x1cc - 0x1c4];
    u8 sub[0x1fc - 0x1cc];         
    u8 b1fc;                       
    u8 pad1fd[0x240 - 0x1fd];
    f32 f240;                      
    W1635SheetData* data;          
    u16* extra;                    
    u8 pad24c[0x254 - 0x24c];
    s32 form;                      
    u8 pad258[0x25c - 0x258];
    W1635Obj* owner;               
    W1635Drive* drive;             
};
struct W1635SheetData {
    u16 ability[2];               
    u8 b4, b5, b6, b7;            
    u8 b8, b9, b10, b11;          
    u8 b12, b13, b14, b15;        
    u8 n10, n11;                  
    u8 pad12[2];
    u16 list10[8];                
    u16 list11[8];                
};
struct W1635Obj {
    u8 pad0[0x48c];
    W1635Sheet* sheet;             
    u8 pad490[0x588 - 0x490];
    u32 flags;                     
    u8 pad58c[0xb50 - 0x58c];
    s32 xb50;                      
};
W1635FormInfo* func_001b6fb0(s32, u8) asm("func_001b6fb0");
s32 func_001b73e8(W1635FormInfo*, s32) asm("func_001b73e8");
void func_001c2f90(void*, W1635Sheet*) asm("func_001c2f90");
void func_001c3060(void*) asm("func_001c3060");
void func_001a24a0(W1635Sheet*, u16) asm("func_001a24a0");
extern W1635Int D_01c6cabc asm("D_01c6cabc");
void func_001a11e0(W1635Sheet* s, W1635SheetData* d) asm("func_001a11e0");
void func_001a11e0(W1635Sheet* s, W1635SheetData* d) {
    if (d == 0) {
        W1635SheetData* p = s->data;
        if (p == 0) return;
        d = p;
    }
    W1635FormInfo* fi = func_001b6fb0(s->form, d->b15);
    s32 v = d->b5;
    s->g[0].cur = v;
    s->g[0].max = v;
    s->g[0].x8 = 0;
    s32 m = d->b4;
    if (v < m) m = v;
    s->g[0].cur = m;
    s->x180 = (u32)d->b6 < (u32)d->b7 ? d->b6 : d->b7;
    s->x184 = d->b7;
    s->stat[0] = s->stat2[0] = fi->str + d->b9;
    s->stat[1] = s->stat2[1] = fi->mag + d->b10;
    s->stat[2] = s->stat2[2] = fi->def + d->b11;
    s32 r = func_001b73e8(fi, s->form);
    s->stat[3] = s->stat2[3] = d->b8 + r;
    s->f1bc = d->b12 * 60.0f;
    s->f1c0 = d->b13 * 60.0f;
    W1635Drive* dr = s->drive;
    if (dr) {
        s->c[0] = dr->c[0];
        s->c[1] = dr->c[1];
        s->c[2] = dr->c[2];
        s->c[3] = dr->c[3];
        s->f1b4 = dr->f0;
        s->f1b8 = dr->f1;
        s->g[0].x8 = D_01c6cabc.v;
    }
    void* sub = s->sub;
    func_001c2f90(sub, s);
    for (s32 j = 0; j < 7; j++) s->rate[j] = 100;
    s32 i;
    for (i = 0; i < 2; i++) func_001a24a0(s, d->ability[i]);
    if (s->extra) func_001a24a0(s, *s->extra);
    for (i = 0; i < d->n10; i++) func_001a24a0(s, d->list10[i]);
    for (i = 0; i < d->n11; i++) func_001a24a0(s, d->list11[i]);
    func_001c3060(sub);
}
}  // namespace n001a11e0

// ---- 001a1460 from src/anon/batch_w10.cpp
namespace n001a1460 {
void func_001a1840(void*) asm("func_001a1840");
void func_001a11e0(void*, s32) asm("func_001a11e0");
void SHEET_reload(void*) asm("_ZN2YS5SHEET6reloadEv");
void SHEET_reload(void* s) {
    func_001a1840(s);
    func_001a11e0(s, 0);
}
}  // namespace n001a1460

// ---- 001a1490 from src/anon/batch_wcx.cpp
namespace n001a1490 {
extern u8 D_01c62fb8[] asm("D_01c62fb8");
extern u8 D_0032e020[] asm("D_0032e020");
u8* func_0031f168(u8*, u8*) asm("func_0031f168");
void func_001a1840(u8*) asm("func_001a1840");
u8* func_001a0e78(void) asm("func_001a0e78");
u32 func_00188fe0(u8*, s32) asm("func_00188fe0");
u8* func_001a1490(s32 k) asm("func_001a1490");
u8* func_001a1490(s32 k)
{
    if ((u32)(k - 1) >= 15) return 0;
    u8* o = 0;
    while ((o = func_0031f168(D_01c62fb8, o))) {
        if (*(s32*)(o + 596) == k) {
            (*(s32*)(o + 600))++;
            func_001a1840(o);
            return o;
        }
    }
    o = func_001a0e78();
    *(s32*)(o + 596) = k;
    *(u32*)(o + 580) = func_00188fe0(D_0032e020, k);
    return o;
}
}  // namespace n001a1490

// ---- 001a1540 from src/anon/auto80_199_queue.cpp
namespace n001a1540 {
void* func_001a0e78() asm("_Z13func_001a0e78v");
u32 func_001a1540(u32 a0) asm("_Z13func_001a1540j");
u32 func_001a1540(u32 a0) {
    u32 s1 = a0;
    u32 s0 = func_001a1490(a0);
    if (s0) {
        func_001a11e0(s0, 0);
        return s0;
    }

    s0 = func_001a0e78();
    *(u32*)(s0 + 596) = s1;
    u32 r = func_00188fe0((u32)&D_0032e020, 1);
    func_001a11e0(s0, r);
    func_001a1950(s0, *(u32*)(s0 + 4), 0, 0);
    return s0;
}
}  // namespace n001a1540

// ---- 001a15d0 from src/anon/auto80_199_queue.cpp
namespace n001a15d0 {
u32 func_001a15d0(u32 a0, s32 a1) asm("_Z13func_001a15d0ji");
u32 func_001a15d0(u32 a0, s32 a1) {
    u32 s1 = a0;
    s32 s2 = a1;
    u32 s0 = func_001a1490(a0);
    if (s0) {
        if (s1 == 1 || s1 == 14) {
            if (*(u32*)(s0 + 608) == 0) {
                *(u32*)(s0 + 608) = (u32)&D_0032e020;
            }
            if (s2 >= 0) {
                func_001a11b0(s0, (u32)s2);
            }
        }
        func_001a11e0(s0, 0);
    }
    return s0;
}
}  // namespace n001a15d0

// ---- 001a1658 from src/anon/batch_w32.cpp
namespace n001a1658 {
s32 func_001a15d0(s32) asm("func_001a15d0");
s32 func_001a1540(s32) asm("func_001a1540");
s32 func_001a1658(s32 x) asm("func_001a1658");
s32 func_001a1658(s32 x) {                          
    switch (x) {
    case 0: return 0;
    case 1: case 14: return func_001a15d0(x);
    default: return func_001a1540(x);
    }
}
}  // namespace n001a1658

// ---- 001a16b0 gap function
namespace n001a16b0 {
void* func_001a8bd0(s32) asm("func_001a8bd0");
u32 func_001a8c10(void*, s32) asm("func_001a8c10");
u32 func_001a1540(u32) asm("_Z13func_001a1540j");
u32 func_001a15d0(u32, s32) asm("_Z13func_001a15d0ji");
u32 func_001a16b0(s32 kind, s32 n) asm("func_001a16b0");
u32 func_001a16b0(s32 kind, s32 n) {
    u32 r = func_001a8c10(func_001a8bd0(-1), kind);
    if (r) {
        if (kind == 0) return func_001a15d0(r, n);
        return func_001a1540(r);
    }
    return r;
}
}  // namespace n001a16b0

// ---- 001a1728 from src/anon/auto80_199_queue.cpp
namespace n001a1728 {
void* func_001a0e78() asm("_Z13func_001a0e78v");
u32 func_001a1728(u32 a0, u32 a1) asm("_Z13func_001a1728jj");
u32 func_001a1728(u32 a0, u32 a1) {
    u32 s2 = a0;
    u32 s0 = a1;
    u32 s1 = func_001a0e78();
    *(u32*)(s1 + 596) = s2;

    u32 s3 = (u32)&D_0032e020;
    *(u32*)(s1 + 580) = func_00188fe0(s3, s2);

    if (s2 == 1 || s2 == 14) {
        if (*(u32*)(s1 + 608) == 0) {
            *(u32*)(s1 + 608) = s3;
        }
        func_001a11b0(s1, s0);
    }

    func_001a11e0(s1, 0);
    return s1;
}
}  // namespace n001a1728

// ---- 001a17c8 from src/anon/batch_w37.cpp
namespace n001a17c8 {
struct Pool1a1 { u8 d[600]; s32 timer; u8 _25c[12]; };
struct PoolMgr1a1 { Pool1a1 items[64]; s32 free[64]; s32 nfree; };
extern PoolMgr1a1 D_01c62fb8 asm("D_01c62fb8");
void func_001a1840(void*) asm("func_001a1840");
void func_001a17c8(Pool1a1* p) asm("func_001a17c8");
void func_001a17c8(Pool1a1* p) {
    func_001a1840(p);
    if (--p->timer <= 0) {
        D_01c62fb8.free[D_01c62fb8.nfree++] = p - D_01c62fb8.items;
    }
}
}  // namespace n001a17c8

// ---- 001a1840 from src/anon/batch_w91.cpp
namespace n001a1840 {
union UF91 { f32 f; u32 u; };
extern u32 D_01c6cabc asm("D_01c6cabc");
void wtarget_001a1840(u8* p, u32, u32, u32) asm("_Z16wtarget_001a1840jjjj");
void wtarget_001a1840(u8* p, u32, u32, u32) {
    u8* q = *(u8**)(p + 580);
    if (q) {
        q[4] = p[0];
        (*(u8**)(p + 580))[5] = p[4];
        (*(u8**)(p + 580))[6] = p[384];
        (*(u8**)(p + 580))[7] = p[388];
        (*(u8**)(p + 580))[12] = (s32)(*(f32*)(p + 444) / 60.0f);
        (*(u8**)(p + 580))[13] = (s32)(*(f32*)(p + 448) / 60.0f);
    }
    u8* r = *(u8**)(p + 608);
    if (r) {
        r[4152] = p[432];
        r[4153] = p[433];
        r[4154] = p[434];
        r[4155] = p[435];
        ((UF91*)(r + 4156))->f = ((UF91*)(p + 436))->f;
        ((UF91*)(r + 4160))->f = ((UF91*)(p + 440))->f;
        D_01c6cabc = ((UF91*)(p + 8))->u;
    }
}
}  // namespace n001a1840

// ---- 001a1910 from src/anon/batch_w12.cpp
namespace n001a1910 {
struct Range { s32 cur, max, min; };
s32 func_001a1910(Range* r, s32 d, s32 i) asm("func_001a1910");
s32 func_001a1910(Range* r, s32 d, s32 i) {                        
    Range* e = &r[i];
    s32 v = e->cur + d;
    return e->cur = v < e->min ? e->min : (e->max < v ? e->max : v);
}
}  // namespace n001a1910

// ---- 001a1950 from src/anon/batch_w8016.c
namespace n001a1950 {
typedef struct VT_1a1950 { void* f[30]; s32 (*m)(void*, s32, s32, u8); } VT_1a1950;
typedef struct Obj_1a1950 { VT_1a1950* vt; } Obj_1a1950;
s32 func_001a1910(void*, s32, s32) asm("func_001a1910");
s32 func_001a1950(void* a0, s32 a1, s32 a2, u8 a3) asm("func_001a1950");
s32 func_001a1950(void* a0, s32 a1, s32 a2, u8 a3) {
    Obj_1a1950* o = *(Obj_1a1950**)((u8*)a0 + 0x25c);
    if (o == 0) return func_001a1910(a0, a1, a2);
    return o->vt->m(o, a1, a2, a3);
}
}  // namespace n001a1950

// ---- 001a1990 from src/anon/auto80_199_queue.cpp
namespace n001a1990 {
u32 func_001a1990(u32 a0, s32 a1) asm("_Z13func_001a1990ji");
u32 func_001a1990(u32 a0, s32 a1) {
    u32 s1 = a0;
    s32 s0 = a1;
    if (func_001a1de0(a0)) {
        if (s0 > 0) {
            f32 k = *(f32*)(*(u32*)&D_00352130 + 124);
            f32 v = (f32)s0 * k;
            func_001a1d50(s1, -v);
        }
        return *(u32*)(s1 + 384);
    }

    s32 sum = *(s32*)(s1 + 384) + s0;
    s32 out;
    if (sum < 0) {
        goto neg;
    }
    out = sum;
    {
        s32 hi = *(s32*)(s1 + 388);
        if (hi < sum) {
            out = hi;
        }
        goto store;
    }
neg:
    out = 0;
store:
    *(s32*)(s1 + 384) = out;
    return (u32)out;
}
}  // namespace n001a1990

// ---- 001a1a20 from src/anon/batch_w10.cpp
namespace n001a1a20 {
void func_00187650(void*, void*) asm("func_00187650");
void func_001a1990(void*, void*, u8) asm("func_001a1990");
void func_001a1a20(u8* p, void* a, u8 b) asm("func_001a1a20");
void func_001a1a20(u8* p, void* a, u8 b) {
    void* o = *(void**)(p + 604);
    if (o) {
        func_00187650(o, a);
    } else {
        func_001a1990(p, a, b);
    }
}
}  // namespace n001a1a20

// ---- 001a1a50 from src/anon/tiny_auto80_queue.cpp
namespace n001a1a50 {
void func_001a1a20(...) asm("func_001a1a20");
void func_001a1db8(...) asm("func_001a1db8");
u32 func_001a1de0(...) asm("func_001a1de0");
void func_001a1a50(u32 a0, u32 a1) asm("_Z13func_001a1a50jj");
void func_001a1a50(u32 a0, u32 a1) {
    u32 s1 = a1 & 0xFFu;
    if (func_001a1de0(a0) != 0u) {
        func_001a1db8(a0);
    }
    func_001a1a20(a0, *(u32*)(a0 + 0x184), s1);
}
}  // namespace n001a1a50

// ---- 001a1aa0 from src/anon/batch_w53.cpp
namespace n001a1aa0 {
void func_001a1aa0(u8* p, s32 d) asm("func_001a1aa0");
void func_001a1aa0(u8* p, s32 d) {                      
    s32 v = p[432] + d;
    if (d >= 0) {
        while (v >= 100) {
            if (p[433] < p[434]) p[433]++;
            if (p[433] >= p[434]) {
                v = 100;
                break;
            }
            v -= 100;
        }
    } else if (v < 0) {
        if (p[433] != 0) {
            p[433]--;
            v += 100;
        } else {
            v = 0;
        }
    }
    p[432] = v;
}
}  // namespace n001a1aa0

// ---- 001a1b30 from src/anon/batch_w1733.cpp
namespace n001a1b30 {
struct S1a1b30 { u8 pad[432]; u8 b0; u8 b1; u8 b2; };
static inline s32 sub_clamp0(s32 a, s32 b) {
    s32 v = a - b;
    if (v < 0) v = 0;
    return v;
}
void func_001a1b30(S1a1b30* s, s32 n) asm("func_001a1b30");
void func_001a1b30(S1a1b30* s, s32 n) {
    if (s->b1 == s->b2 || s->b1 < n) s->b0 = 0;
    s->b1 = sub_clamp0(s->b1, n);
}
}  // namespace n001a1b30

// ---- 001a1b68 from src/anon/batch_w88.cpp
namespace n001a1b68 {
void func_0019ba60(u32) asm("func_0019ba60");
s32 func_001a1c30(u8*) asm("func_001a1c30");
void func_001d6f28(s32) asm("func_001d6f28");
void func_001a1b68(u8* p, f32 d) asm("func_001a1b68");
void func_001a1b68(u8* p, f32 d) {
    func_0019ba60(*(u32*)(p + 604));
    s32 m = *(s32*)(*(u8**)(p + 604) + 2896);
    bool neg = m == 6;
    if (neg) {
        if (0.0f < d) d = -d;
    }
    s32 a = func_001a1c30(p);
    f32 v = *(f32*)(p + 436) + d;
    f32 r;
    if (v < 0.0f) r = 0.0f;
    else if (*(f32*)(p + 440) < v) r = *(f32*)(p + 440);
    else r = v;
    *(f32*)(p + 436) = r;
    if (p[431] == 3) func_001d6f28(a - func_001a1c30(p));
}
}  // namespace n001a1b68

// ---- 001a1c30 from src/anon/tiny_auto80_queue.cpp
namespace n001a1c30 {
extern u32 D_00352130 asm("D_00352130");
s32 func_001a1c30(u32 a0) asm("_Z13func_001a1c30j");
s32 func_001a1c30(u32 a0) {
    f32 cur = *(f32*)(a0 + 0x1B4);
    s32 out = (s32)(cur / *(f32*)(D_00352130 + 0x68));
    if (cur == *(f32*)(a0 + 0x1B8)) {
        out -= 1;
    }
    return out;
}
}  // namespace n001a1c30

// ---- 001a1c70 from src/anon/auto200_999.cpp
namespace n001a1c70 {
void func_001a1c70(u32 a0) asm("_Z13func_001a1c70j");
void func_001a1c70(u32 a0) {
    u8 v = *(u8 *)(a0 + 434);
    *(u8 *)(a0 + 432) = 100;
    *(u8 *)(a0 + 433) = v;
    *(u32 *)(a0 + 436) = 0;
    *(u32 *)(a0 + 440) = 0;
}
}  // namespace n001a1c70

// ---- 001a1c90 from src/yasui/libys/sheet.cpp
namespace YS {
extern u32 D_00352130 asm("D_00352130");
void SHEET::start_drive(s32 a1, s32 a2) {
    a2 += 3;
    *(u8*)((u32)this + 0x1AF) = (u8)a1;
    *(u8*)((u32)this + 0x1B3) = (u8)a2;
    f32 v = *(f32*)(D_00352130 + 0x68) * (f32)a2;
    *(f32*)((u32)this + 0x1B8) = v;
    *(f32*)((u32)this + 0x1B4) = v;
}
}  // namespace YS (001a1c90)

// ---- 001a1cc0 from src/anon/auto80_199_queue.cpp
namespace n001a1cc0 {
u32 func_001a1cc0(u32 a0, u32 a1, u32 a2) asm("_Z13func_001a1cc0jjj");
u32 func_001a1cc0(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 z = 0;
    u32 v1 = *(u32*)(s0 + 4);
    func_001a1950(s0, v1, z, z);
    func_001a1a50(s0, 0);
    if (s1 == 6) {
        s2 = *(u32*)(*(u32*)&D_00352130 + 140) - 2;
    }
    return func_001a1c90(s0, 2, s2);
}
}  // namespace n001a1cc0

// ---- 001a1d40 from src/anon/auto200_999.cpp
namespace n001a1d40 {
void func_001a1d40(u32 a0, f32 f12) asm("_Z13func_001a1d40jf");
void func_001a1d40(u32 a0, f32 f12) {
    *(u32 *)(a0 + 384) = 0;
    *(f32 *)(a0 + 448) = f12;
    *(f32 *)(a0 + 444) = f12;
}
}  // namespace n001a1d40

// ---- 001a1d50 from src/anon/batch_w45.cpp
namespace n001a1d50 {
void func_001a1db8(u8*) asm("func_001a1db8");
void func_001a1d50(u8* a0, f32 d) asm("func_001a1d50");
void func_001a1d50(u8* a0, f32 d) {
    f32 max = *(f32*)(a0 + 448);
    if (0.0f < max) {
        f32 v = *(f32*)(a0 + 444) + d;
        f32 r = v < 0.0f ? 0.0f : (max < v ? max : v);
        *(f32*)(a0 + 444) = r;
        if (r == 0.0f) func_001a1db8(a0);
    }
}
}  // namespace n001a1d50

// ---- 001a1db8 from src/anon/batch_w9.cpp
namespace n001a1db8 {
void func_001a1a20(void*, u32, u32) asm("func_001a1a20");
struct Obj1a1db8 { u8 pad[444]; f32 x, y; };
void func_001a1db8(Obj1a1db8* p) asm("func_001a1db8");
void func_001a1db8(Obj1a1db8* p) {
    p->x = p->y = 0.0f;
    func_001a1a20(p, *(u32*)((u8*)p + 388), 0);
}
}  // namespace n001a1db8

// ---- 001a1de0 from src/anon/tiny_auto80_queue.cpp
namespace n001a1de0 {
u32 u_call4_001a1de0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_001a1de0jjjj");
u32 u_call4_001a1de0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return (*(f32*)(a0 + 448u) > 0.0f) ? 1u : 0u;
}
}  // namespace n001a1de0

// ---- 001a1e00 from src/anon/tiny_auto80_queue.cpp
namespace n001a1e00 {
f32 func_001a1e00(u32 a0) asm("_Z13func_001a1e00j");
f32 func_001a1e00(u32 a0) {
    f32 f1 = *(volatile f32*)((u32)a0 + (s32)(448));
    f32 f0 = *(volatile f32*)((u32)a0 + (s32)(444));
    return (f32)(f0 / f1);
}
}  // namespace n001a1e00

// ---- 001a1e20 from src/anon/batch_w1635.cpp
namespace n001a1e20 {
struct W1635SheetData;
struct W1635Obj;
struct W1635Gauge {
    s32 cur;                    
    s32 max;                    
    s32 x8;                     
};
struct W1635Drive {
    u8 pad0[0x1038];
    u8 c[4];                        
    f32 f0, f1;                     
};
struct W1635Sheet {
    W1635Gauge g[1];                                                                   
    u8 pad0c[0x180 - 0xc];
    s32 x180;                      
    s32 x184;                      
    u16 stat[4];                   
    u16 stat2[4];                  
    s32 lo;                                           
    s32 hi;                                           
    s32 x1a0;                      
    s32 x1a4;                      
    u8 rate[7];                                               
    u8 pad1af;
    u8 c[4];                       
    f32 f1b4, f1b8;                
    f32 f1bc, f1c0;                
    u8 pad1c4[0x1cc - 0x1c4];
    u8 sub[0x1fc - 0x1cc];         
    u8 b1fc;                       
    u8 pad1fd[0x240 - 0x1fd];
    f32 f240;                      
    W1635SheetData* data;          
    u16* extra;                    
    u8 pad24c[0x254 - 0x24c];
    s32 form;                      
    u8 pad258[0x25c - 0x258];
    W1635Obj* owner;               
    W1635Drive* drive;             
};
struct W1635SheetData {
    u16 ability[2];               
    u8 b4, b5, b6, b7;            
    u8 b8, b9, b10, b11;          
    u8 b12, b13, b14, b15;        
    u8 n10, n11;                  
    u8 pad12[2];
    u16 list10[8];                
    u16 list11[8];                
};
struct W1635Obj {
    u8 pad0[0x48c];
    W1635Sheet* sheet;             
    u8 pad490[0x588 - 0x490];
    u32 flags;                     
    u8 pad58c[0xb50 - 0x58c];
    s32 xb50;                      
};
struct W1635Attack {
    u8 pad0[8];
    s32 x8;                      
    W1635Obj* obj;               
};
struct W1635AttackData {
    u8 pad0[4];
    u8 type;                     
    u8 kind;                     
    u16 power;                   
    u8 pad8;
    u8 elem;                     
};
struct W1635Default {
    u8 pad0[2];
    u16 v;                       
    u8 pad4[2];
    u16 lo;                      
    u16 hi;                      
};
struct W1635Info {
    u8 pad0[0x52];
    u16 bonus;                    
};
struct W1635Param {
    u8 pad0[0x94];
    f32 f94;                      
    u8 pad98[0x178 - 0x98];
    s32 x178;                      
};
extern W1635Param* D_00352130 asm("D_00352130");
W1635Info* func_00177860(W1635Obj*) asm("func_00177860");
s32 func_0019ba60(W1635Obj*) asm("func_0019ba60");
s32 func_001a1de0(W1635Sheet*) asm("func_001a1de0");
s32 func_001a2108(W1635Sheet*, s32, s32) asm("func_001a2108");
s32 func_001a2200(W1635Sheet*, s32) asm("func_001a2200");
s32 func_001a22b0(W1635Sheet*, s32, W1635Sheet*, W1635AttackData*) asm("func_001a22b0");
s32 func_001a2340(W1635Sheet*, s32, W1635Sheet*, W1635AttackData*) asm("func_001a2340");
s32 func_001a2478(W1635Sheet*) asm("func_001a2478");
W1635Default* func_001c0cc8(void) asm("func_001c0cc8") __attribute__((pure));
static inline bool W1635_is6(W1635Obj* o) { return o->xb50 == 6; }
s32 func_001a1e20(W1635Sheet* s, W1635Attack* a, W1635AttackData* ad, s32 idx) asm("func_001a1e20");
s32 func_001a1e20(W1635Sheet* s, W1635Attack* a, W1635AttackData* ad, s32 idx) {
    s32 v = 0;
    W1635Sheet* sh = 0;
    s32 lo, hi;
    W1635Obj* o = a->obj;
    if (o && (sh = o->sheet)) {
        switch (ad->kind) {
        case 0:
            v = sh->stat[0];
            if ((o->flags & 4) && func_001a1de0(sh)) v += func_00177860(a->obj)->bonus;
            break;
        case 1:
            v = sh->stat[1];
            break;
        }
        lo = sh->lo;
        hi = sh->hi;
    } else {
        W1635Default* dft = func_001c0cc8();
        v = dft->v;
        lo = dft->lo;
        hi = dft->hi;
    }
    switch (ad->type) {
    case 5:
        v = (s->g[idx].max * v * ad->power + 9999) / 10000;
        break;
    case 6:
        v = (v * ad->power + 99) / 100;
        break;
    default: {
        v -= s->stat[2];
        if (func_001a2478(s)) v -= s->b1fc;
        s32 mx = lo < s->x1a0 ? lo : s->x1a0;
        s32 mn = s->x1a4 < hi ? hi : s->x1a4;
        v = v < mx ? v : mx;
        v = mn < v ? v : mn;
        s32 rate = s->rate[ad->elem] * s->rate[6];
        v = (v * ad->power * rate + 999999) / 1000000;
        v = func_001a2108(s, v, a->x8);
        v = func_001a2200(s, v);
        if (func_0019ba60(s->owner)) {
            W1635Obj* ow = s->owner;
            if ((ow->flags & 0x80) && W1635_is6(ow)) v = (s32)(v * D_00352130->f94);
        }
        v = func_001a22b0(s, v, sh, ad);
        v = func_001a2340(s, v, sh, ad);
        break;
    }
    }
    if ((s32)(s->g[idx].max * s->f240) >= s->g[idx].cur) v = (v * D_00352130->x178 + 99) / 100;
    return v;
}
}  // namespace n001a1e20

// ---- 001a2108 from src/anon/batch_w84.cpp
namespace n001a2108 {
s32 func_0019ba60(u32) asm("func_0019ba60");
extern s32 D_0032dfc8 asm("D_0032dfc8");
s32 func_001a2108(u8* a, s32 v, u8* b) asm("func_001a2108");
s32 func_001a2108(u8* a, s32 v, u8* b) {
    if (v > 0 && func_0019ba60(*(u32*)(a + 604))) {
        s32 m1, m2;
        switch (D_0032dfc8) {
        case 0: m1 = 50; m2 = 150; break;
        case 2: m1 = 200; m2 = 100; break;
        case 3: m1 = 200; m2 = 125; break;
        default: return v;
        }
        if (*(u32*)(*(u8**)(a + 604) + 1416) & 4) {
            v = (v * m1 + 99) / 100;
        } else if (func_0019ba60((u32)b) && (*(u32*)(b + 1416) & 4)) {
            v = (v * m2 + 99) / 100;
        }
    }
    return v;
}
}  // namespace n001a2108

// ---- 001a2200 from src/anon/batch_wcx.cpp
namespace n001a2200 {
extern u32 D_0034f240 asm("D_0034f240");
u8* func_001ba158(void) asm("func_001ba158");
s32 func_0019ba60(u8*) asm("func_0019ba60");
s32 func_001a2200(u8* p, s32 n) asm("func_001a2200");
s32 func_001a2200(u8* p, s32 n)
{
    if (n <= 0) return n;
    if (!(D_0034f240 & 0x20000)) return n;
    s32 c = *(s32*)(func_001ba158() + 8) + 1;
    if (c < 2) return n;
    if (func_0019ba60(*(u8**)(p + 604)) && (*(u32*)(*(u8**)(p + 604) + 1416) & 0x80)) {
        n /= c;
        if (n <= 0) n = 1;
    } else {
        n *= c;
    }
    return n;
}
}  // namespace n001a2200

// ---- 001a22b0 from src/anon/sweep_001a22b0_g.cpp
namespace n001a22b0 {
typedef struct P22 { u8 pad[0x210]; u16 r[3]; } P22;
typedef struct Q22 { u8 pad[9]; u8 k; } Q22;
s32 func_001a22b0(s32 a0, s32 v, P22* p, Q22* q) asm("_Z13func_001a22b0iiP3P22P3Q22");
s32 func_001a22b0(s32 a0, s32 v, P22* p, Q22* q) {
    if (p) {
        switch (q->k) {
        case 1: v = (v * p->r[0] + 99) / 100; break;
        case 2: v = (v * p->r[1] + 99) / 100; break;
        case 3: v = (v * p->r[2] + 99) / 100; break;
        }
    }
    return v;
}
}  // namespace n001a22b0

// ---- 001a2340 from src/anon/batch_w90.cpp
namespace n001a2340 {
s32 func_00177ba0(u32) asm("func_00177ba0");
s32 func_00177bf8(u32) asm("func_00177bf8");
struct BonusSrc { u8 pad[472]; u32 flags; u8 pad2[58]; u16 r0; u16 r1; u16 r2; u8 pad3[64]; u32 h; };
struct BonusMask { u8 pad[46]; u8 b0 : 1, b1 : 1, b2 : 1; };
static inline bool Mask0(BonusMask* q) { return q->b0; }
static inline bool Mask1(BonusMask* q) { return q->b1; }
static inline bool Mask2(BonusMask* q) { return q->b2; }
s32 func_001a2340(u32 unused, s32 dmg, BonusSrc* p, BonusMask* q) asm("func_001a2340");
s32 func_001a2340(u32 unused, s32 dmg, BonusSrc* p, BonusMask* q)
{
    if (!p) return dmg;
    if ((p->flags & 0x40) && Mask0(q)) {
        s32 s = p->r0;
        dmg += (dmg * (s * func_00177ba0(p->h)) + 99) / 100;
    } else if ((p->flags & 0x80) && Mask1(q)) {
        s32 s = p->r1;
        dmg += (dmg * (s * func_00177bf8(p->h)) + 99) / 100;
    } else if ((p->flags & 0x100) && Mask2(q)) {
        dmg += (dmg * p->r2 + 99) / 100;
    }
    return dmg;
}
}  // namespace n001a2340

// ---- 001a2438 from src/anon/tiny_auto80_queue.cpp
namespace n001a2438 {
void func_001a2438(u32 a0, u32 a1, s32 a2) asm("_Z13func_001a2438jji");
void func_001a2438(u32 a0, u32 a1, s32 a2) {
    u32 t = *(u32*)(a0 + 0x264);
    u32 i = a1 << 1;
    s32 d = 100;
    a1 = a1 + a0;
    i = i + t;
    a1 = a1 + 0x1A0;
    u16 v = *(u16*)(i + 0x48);
    s32 n = (s32)((u32)v * (u32)a2 + 99u);
    *(u8*)(a1 + 8) = (u8)(n / d);
}
}  // namespace n001a2438

// ---- 001a2478 from src/anon/tiny_auto80_solver.cpp
namespace n001a2478 {
u32 func_001a2478(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001a2478jjjjjjjj");
u32 func_001a2478(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001a2478jjjjjjjj");
u32 func_001a2478(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {                       
    s32 value = *(s32*)(a0 + 4);
    s32 limit = *(s32*)a0;
    s32 adjusted = value + 3;
    if (value < 0) {
        value = adjusted;
    }
    value >>= 2;
    return !(value < limit);
}
}  // namespace n001a2478

// ---- 001a24a0 from src/anon/batch_w85.cpp
namespace n001a24a0 {
u32 func_001a80c8(u32) asm("func_001a80c8");
u8* func_001a8190(u32) asm("func_001a8190");
void func_001c3150(void*, u16) asm("func_001c3150");
struct St1a2 { u8 pad[392]; u16 s[4]; u8 p400[24]; u8 r[8]; u8 p432[28]; u8 f460[4]; };
void func_001a24a0(St1a2* o, u32 id) asm("func_001a24a0");
void func_001a24a0(St1a2* o, u32 id) {
    u8* v;
    s32 i;
    if (!id) return;
    v = func_001a8190(func_001a80c8(id));
    if (!v) return;
    o->s[0] += v[4];
    o->s[1] += v[5];
    o->s[2] += v[6];
    o->s[3] += v[7];
    for (i = 0; i < 7; i++) o->r[i] = (o->r[i] * v[8 + i] + 99) / 100;
    func_001c3150(o->f460, *(u16*)(v + 2));
}
}  // namespace n001a24a0

// ---- 001a2578 from src/anon/batch_w32.cpp
namespace n001a2578 {
void func_001a2578(u8* p, s32 n) asm("func_001a2578");
void func_001a2578(u8* p, s32 n) {
    u8* s = *(u8**)(p + 580);
    if (s) {
        if (s[9] + n > 100) n = 100 - s[9];
        s[9] += n;
    }
    *(u16*)(p + 392) += n;
    *(u16*)(p + 400) += n;
}
}  // namespace n001a2578

// ---- 001a25c8 from src/anon/batch_w33.cpp
namespace n001a25c8 {
struct Sub1a2 { u8 pad[10]; u8 v; };
struct Obj1a2 { u8 pad[394]; u16 a; u8 pad2[6]; u16 b; u8 pad3[580 - 404]; Sub1a2* s; };
void func_001a25c8(Obj1a2* o, s32 n) asm("func_001a25c8");
void func_001a25c8(Obj1a2* o, s32 n) {
    if (o->s) {
        if (o->s->v + n > 100) n = 100 - o->s->v;
        o->s->v += n;
    }
    o->a += n;
    o->b += n;
}
}  // namespace n001a25c8

// ---- 001a2618 from src/anon/batch_w34.cpp
namespace n001a2618 {
void func_001a2618(u8* p, s32 n) asm("func_001a2618");
void func_001a2618(u8* p, s32 n) {
    u8* q = *(u8**)(p + 580);
    if (q) {
        if (q[11] + n > 100) n = 100 - q[11];
        q[11] += n;
    }
    *(u16*)(p + 396) += n;
    *(u16*)(p + 404) += n;
}
}  // namespace n001a2618

// ---- 001a2668 from src/anon/batch_w35.cpp
namespace n001a2668 {
void func_001a2668(u8* p, s32 n) asm("func_001a2668");
void func_001a2668(u8* p, s32 n) {
    u8* q = *(u8**)(p + 580);
    if (q) {
        if (q[8] + n > 100) n = 100 - q[8];
        q[8] += n;
    }
    *(u16*)(p + 398) += n;
    *(u16*)(p + 406) += n;
}
}  // namespace n001a2668

// ---- 001a26b8 from src/anon/auto80_199_queue.cpp
namespace n001a26b8 {
void func_001a26b8(u32 a0) asm("_Z13func_001a26b8j");
void func_001a26b8(u32 a0) {
    u32 s0 = a0;
    u32 flags = *(u32*)(a0 + 592);
    if ((flags & 1) == 0) {
        u32 v0;
        u32 v1;
        u32 p = *(u32*)(a0 + 604);
        if (func_0016c060(p, (u32)&v0, (u32)&v1)) {
            func_0013dab0();
        }
        *(u32*)(s0 + 592) = *(u32*)(s0 + 592) | 1;
    }
}
}  // namespace n001a26b8

// ---- 001a2710 from src/anon/batch_w29.cpp
namespace n001a2710 {
struct Flag250 { u8 pad[592]; u32 on:1; u32 rest:31; };
void func_0013dad0(void*) asm("func_0013dad0");
void func_001a2710(Flag250* p) asm("func_001a2710");
void func_001a2710(Flag250* p) {
    if (p->on) {
        func_0013dad0(p);
        p->on = 0;
    }
}
}  // namespace n001a2710

// ---- 001a2758 from src/anon/tiny_auto80_queue.cpp
namespace n001a2758 {
u32 func_001a2758(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001a2758jjjjjjjj");
u32 func_001a2758(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(580));
    r2 = 0u;
    if (r14 != 0u) {
        r15 = (u32)(*(u8*)((u32)r14 + (s32)(9)));
        r15 = ((u32)r15 < 0x00000064u);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
}  // namespace n001a2758

// ---- 001a2778 from src/anon/tiny_auto80_queue.cpp
namespace n001a2778 {
u32 func_001a2778(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001a2778jjjjjjjj");
u32 func_001a2778(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(580));
    r2 = 0u;
    if (r14 != 0u) {
        r15 = (u32)(*(u8*)((u32)r14 + (s32)(10)));
        r15 = ((u32)r15 < 0x00000064u);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
}  // namespace n001a2778

// ---- 001a2798 from src/anon/tiny_auto80_queue.cpp
namespace n001a2798 {
u32 func_001a2798(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001a2798jjjjjjjj");
u32 func_001a2798(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(580));
    r2 = 0u;
    if (r14 != 0u) {
        r15 = (u32)(*(u8*)((u32)r14 + (s32)(11)));
        r15 = ((u32)r15 < 0x00000064u);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
}  // namespace n001a2798

// ---- 001a27b8 from src/anon/tiny_auto80_queue.cpp
namespace n001a27b8 {
u32 func_001a27b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001a27b8jjjjjjjj");
u32 func_001a27b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(580));
    r2 = 0u;
    if (r14 != 0u) {
        r15 = (u32)(*(u8*)((u32)r14 + (s32)(8)));
        r15 = ((u32)r15 < 0x00000064u);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
}  // namespace n001a27b8

// ---- 001a27d8 from src/anon/tiny_auto80_queue.cpp
namespace n001a27d8 {
u32 func_001a27d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001a27d8jjjjjjjj");
u32 func_001a27d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = *(volatile u32*)((u32)r4 + (s32)(580));
    r2 = 0u;
    if (r15 != 0u) {
        r2 = (u32)(*(u8*)((u32)r15 + (s32)(15)));
    }
    return r2;
}
}  // namespace n001a27d8

// ---- 001a27f0 from src/anon/auto80_199_queue.cpp
namespace n001a27f0 {
void func_001a27f0(u32 a0, u32 a1) asm("_Z13func_001a27f0jj");
void func_001a27f0(u32 a0, u32 a1) {
    if (a1 == 0xffff && a0 == 1) {
        u8* p = D_01c62fb8;
        s32 i = 63;
        do {
            func_001a0d48((u32)p);
            i = i - 1;
            p = p + 616;
        } while (i != -1);

        u8* base = D_01c62fb8;
        u32* t = (u32*)(base + 0x9a00);
        s32 n = 0;
        do {
            *t = (u32)n;
            n = n + 1;
            t = t + 1;
        } while (n < 64);
        *(u32*)(base + 0x8000 + 6912) = 64;
    }
}
}  // namespace n001a27f0

// ---- 001a2898 from src/anon/tiny_wrappers_more.cpp
namespace n001a2898 {
u32 func_001a27f0(u32, u32, u32, u32) asm("_Z13func_001a27f0jjjj");
u32 func_001a2898(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001a2898jjjj");
u32 func_001a2898(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001a27f0(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001a2898

