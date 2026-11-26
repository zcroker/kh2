#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../yasui/libys/sora.hpp"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// ---- 001d14e0 from src/anon/batch_w25.cpp
namespace n001d14e0 {
extern u8 D_003524b8 asm("D_003524b8");
extern u8 D_0036e3a8 asm("D_0036e3a8");
void func_00177dc8(u8*, u32, u32, u32, u32) asm("func_00177dc8");
void YS__FIELD_COMMAND__set_minigame(u32, void*, u32) asm("YS__FIELD_COMMAND__set_minigame");
void func_001d14e0(u8* o, u32 a, u32 b, u32 c) asm("func_001d14e0");
void func_001d14e0(u8* o, u32 a, u32 b, u32 c) {
    func_00177dc8(o, a, 8, b, c);
    *(void**)o = &D_003524b8;
    *(u32*)(o + 1416) |= 0x4000000;
    YS__FIELD_COMMAND__set_minigame(*(u32*)(o + 2884), &D_0036e3a8, 2);
}
}  // namespace n001d14e0

// ---- 001d1540 from src/anon/batch_w26.cpp
namespace n001d1540 {
inline void* operator new(unsigned int, void* p) { return p; }
void func_00177dc8(void*, void*, s32, void*, void*) asm("func_00177dc8");
void YS__FIELD_COMMAND__set_minigame(void*, void*, s32) asm("YS__FIELD_COMMAND__set_minigame");
extern u8 D_003524b8[] asm("D_003524b8");
extern u8 D_0036e3a8[] asm("D_0036e3a8");
void func_001d1540(u8* o, void* a, void* b, void* c) asm("func_001d1540");
void func_001d1540(u8* o, void* a, void* b, void* c) {
    func_00177dc8(o, a, 8, b, c);
    *(u8**)o = D_003524b8;
    *(u32*)(o + 1416) |= 0x4000000;
    YS__FIELD_COMMAND__set_minigame(*(void**)(o + 2884), D_0036e3a8, 2);
}
}  // namespace n001d1540

// ---- 001d15a0 gap (never-written function)
namespace g001d15a0 {
void func_001780d8(u8*) asm("func_001780d8");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_001d15a0(u8* p) asm("func_001d15a0");
void func_001d15a0(u8* p) { func_001780d8(p); func_0016bd60(p, 29); }
}  // namespace g001d15a0

// ---- 001d15d0 gap (never-written function)
namespace g001d15d0 {
struct Msg { u16 a; u16 id; s16 arg; };
struct S20 { u32 w[5]; };
void YS__PLAYER___OVR_exec_command_player(u8*, Msg*) asm("YS__PLAYER___OVR_exec_command_player");
s32 YS__LMPLAYER__swim(u8*, Msg*) asm("YS__LMPLAYER__swim");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
// a message handler: the unhandled messages go to the base class (no tail call: the function
// returns a value but this path falls off the end)
s32 func_001d15d0(u8* p, Msg* m) asm("func_001d15d0");
s32 func_001d15d0(u8* p, Msg* m) {
    switch (m->id) {
    case 422: return YS__LMPLAYER__swim(p, m);
    default: YS__PLAYER___OVR_exec_command_player(p, m); break;
    case 421: {
        S20* s = (S20*)(*(u8**)(p + 2880) + 4);
        *(S20*)(p + 2548) = *s;
        func_0017f488(p + 320, 152, 8.0f, 0.0f);
        *(u8*)(p + 1300) = 6;
        break; }
    }
}
}  // namespace g001d15d0

// (id, count) pairs read by 0x1d14e0 and 0x1d1540
extern "C++" const u16 R_0036e3a8[4] asm("D_0036e3a8") __attribute__((aligned(8))) = { 0x1a6, 1, 0x1a5, 4 };

// ---- 001d1678 from src/anon/batch_w2.cpp
namespace n001d1678 {
void func_001d1678(s32* p, s32 a1) asm("func_001d1678");
void func_001d1678(s32* p, s32 a1) {                     
    p[4] = a1;
    p[3] = 1;
    p[1] = 0;
    p[6] = 0;
    p[10] = 0;
}
}  // namespace n001d1678

// ---- 001d1698 from src/anon/tiny_auto80_queue.cpp
namespace n001d1698 {
void func_001d1698(u8* a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d1698Phjjj");
void func_001d1698(u8* a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)(a0 + 20) = a1;
    *(u32*)(a0 + 28) = a3;

    if (a2 == 0) {
        return;
    }

    u32 t6 = a2 & 0xBFFFFFFF;
    u32 t7 = a2 & 0x40000000;
    *(u32*)(a0 + 24) = t6;

    if (t7 != 0) {
        u32 v = *(u32*)(a0 + 12);
        v |= 2;
        *(u32*)(a0 + 12) = v;
        return;
    }

    u32 v = *(u32*)(a0 + 12);
    v &= 0xFFFFFFFD;
    *(u32*)(a0 + 12) = v;
}
}  // namespace n001d1698

// ---- 001d16e8 from src/anon/tiny.cpp
namespace n001d16e8 {
void func_001d16e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d16e8jjjj");
void func_001d16e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a3;
    *(u32*)((u32)a0 + (32)) = a1;
    *(u32*)((u32)a0 + (36)) = a2;
}
}  // namespace n001d16e8

// ---- 001d16f8 from src/anon/tiny.cpp
namespace n001d16f8 {
void func_001d16f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d16f8jjjj");
void func_001d16f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t = *(u32*)((u32)a0 + (12));
    t |= 0x0004u;
    *(u32*)((u32)a0 + (12)) = t;
}
}  // namespace n001d16f8

// ---- 001d1708 from src/anon/tiny.cpp
namespace n001d1708 {
void func_001d1708(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d1708jjjj");
void func_001d1708(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = *(u32*)((u32)a0 + (12));
    v &= (u32)((s32)-5);
    *(u32*)((u32)a0 + (12)) = v;
}
}  // namespace n001d1708

// ---- 001d1720 from src/anon/tiny_auto80_queue.cpp
namespace n001d1720 {
u32 func_001991a8(...) asm("func_001991a8");
void func_001d1720(u8* a0, u32 a1) asm("_Z13func_001d1720Phj");
void func_001d1720(u8* a0, u32 a1) {
    u32 t6 = a1;
    u32 a5 = *(u32*)(a0 + 16);
    if (a5 == 0xFFFFFFFF) {
        return;
    }

    u32 t7 = *(u32*)(a0 + 12);
    t7 = t7 & 4;
    if (t7 == 0) {
        return;
    }

    func_001991a8(t6, a5);
}
}  // namespace n001d1720

// ---- 001d1760 from src/anon/batch_w2362.cpp
namespace n001d1760 {
struct Gauge { u8 pad[0x14]; s32 max; u32 p18; s32 cur; };
s32 func_001d1760(Gauge* g, s32 n) asm("func_001d1760");
s32 func_001d1760(Gauge* g, s32 n) {
    s32 cur = g->cur;
    s32 r = 0;
    if (cur > 0) {
        if (cur < g->max) { if (cur < n) goto end; }
        else { if (n < cur) goto end; }
        r = 1;
    }
end:
    return r;
}
}  // namespace n001d1760

// ---- 001d17b0 from src/anon/auto80_199_queue.cpp
namespace n001d17b0 {
void func_001d17b0(u32 a0, s32) asm("func_001d17b0");
void func_001d17b0(u32 a0) {
    u32 s0 = a0;

    if (*(s32*)(s0 + 28) <= 0) {
        return;
    }

    if (func_001d1760() != 0) {
        if ((*(u32*)(s0 + 12) & 8u) != 0) {
            return;
        }
        u32* vt = *(u32**)s0;
        ((Cb)vt[3])(s0);
        return;
    }

    if ((*(u32*)(s0 + 12) & 8u) == 0) {
        return;
    }

    u32* vt = *(u32**)s0;
    ((Cb)vt[4])(s0);
}
}  // namespace n001d17b0

// ---- 001d1820 from src/anon/batch_w1671.cpp
namespace n001d1820 {
void func_002bc1e8(void*) asm("func_002bc1e8");
void YS__MISSION2D__set_warning(u8* a0) asm("YS__MISSION2D__set_warning");
void YS__MISSION2D__set_warning(u8* a0) {
    u32 f = *(u32*)(a0 + 0xc);
    if (!(f & 4)) goto set;
    if (f & 8) goto set;
    {
        void* q = *(void**)(a0 + 0x28);
        if (q) { func_002bc1e8(q); f = *(u32*)(a0 + 0xc); }
    }
set:
    *(u32*)(a0 + 0xc) = f | 8;
}
}  // namespace n001d1820

// ---- 001d1878 from src/anon/tiny_auto80_queue.cpp
namespace n001d1878 {
void func_001d1878(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001d1878jjjjjjjj");
void func_001d1878(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15, r16;
    r14 = ((u32*)(u32)r4)[3];
    r15 = (u32)(r14 & 0x0004u);
    r16 = r4;
    if (r15 != 0u) {
        r15 = ((u32*)(u32)r4)[0];
        r14 = ((u32*)(u32)r15)[2];
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))(u32)r14)(r4, r5, r6, r7, r8, r9, r10, r11);
        r14 = ((u32*)(u32)r16)[3];
    }
    r15 = (u32)(r14 | 0x0010u);
    ((u32*)(u32)r16)[3] = r15;
}
}  // namespace n001d1878

// ---- 001d18c0 from src/anon/batch_w34.cpp
namespace n001d18c0 {
void func_001d16f8(void*) asm("func_001d16f8");
void func_0014f688(u32, u32, u32, u32, u32) asm("func_0014f688");
void YS__MISSION_TIMER__start(void*, u32) asm("YS__MISSION_TIMER__start");
void func_001d18c0(u8* p) asm("func_001d18c0");
void func_001d18c0(u8* p) {
    func_001d16f8(p);
    u32 t = *(u32*)(p + 4);
    if (t) func_0014f688(t, *(u32*)(p + 8), *(u32*)(p + 32), *(u32*)(p + 36), *(u32*)(p + 28));
    YS__MISSION_TIMER__start(p, *(u32*)(p + 20));
}
}  // namespace n001d18c0

// ---- 001d1910 gap (never-written function)
namespace g001d1910 {
void func_0014f6c8() asm("func_0014f6c8");
void func_0014c9d8(s32) asm("func_0014c9d8");
void func_001d1708(u8*) asm("func_001d1708");
void func_001d1910(u8* p) asm("func_001d1910");
void func_001d1910(u8* p) {
    if (*(u32*)(p + 4)) func_0014f6c8();
    func_0014c9d8(2);
    func_001d1708(p);
}
}  // namespace g001d1910

// ---- 001d1950 from src/anon/tiny_auto80_queue.cpp
namespace n001d1950 {
extern "C" void dk_Timer_start_exact_0014c9b8(void) asm("_ZN2dk5Timer5startEv");
void func_0014c940(...) asm("func_0014c940");
void func_0014c9f0(...) asm("func_0014c9f0");
void func_0014c970(u32 a0) asm("_Z13func_0014c970j");
void YS__MISSION_TIMER__start(u8* a0, s32 a1) asm("_Z24YS__MISSION_TIMER__startPhi");
void YS__MISSION_TIMER__start(u8* a0, s32 a1) {
    u8* t7 = a0;
    if (a1 <= 0) {
        goto L1984;
    }

    func_0014c940((u32)a1);
    goto L196c;

L1984:
    func_0014c970(*(u32*)(t7 + 24));

L196c:
    dk_Timer_start_exact_0014c9b8();
    func_0014c9f0(2);
}
}  // namespace n001d1950

// ---- 001d1998 from src/anon/tiny.cpp
namespace n001d1998 {
void func_0014ca38(void*) asm("func_0014ca38");
void func_001d1998(BD_VALUE* bd) asm("_Z13func_001d1998P8BD_VALUE");
void func_001d1998(BD_VALUE* bd) { func_0014ca38(bd); }
}  // namespace n001d1998

// ---- 001d19b0 gap (never-written function)
namespace g001d19b0 {
void func_0014f708() asm("func_0014f708");
void YS__MISSION2D__set_warning(u8*) asm("YS__MISSION2D__set_warning");
void func_001d19b0(u8* p) asm("func_001d19b0");
void func_001d19b0(u8* p) {
    if (*(u32*)(p + 4)) func_0014f708();
    YS__MISSION2D__set_warning(p);
}
}  // namespace g001d19b0

// ---- 001d19e8 from src/anon/tiny_auto80_solver.cpp
namespace n001d19e8 {
void func_001d1678(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001d1678jjjjjjjj");
u32 func_001d19e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001d19e8jjjjjjjj");
u32 func_001d19e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001d1678)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(48)) = 0u;
    *(volatile u32*)((u32)r16 + (s32)(52)) = 0u;
    return r2;
}
}  // namespace n001d19e8

// ---- 001d1a18 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001d1a18 {
u32 func_001d1698(u32, u32, u32, u32) asm("_Z13func_001d1698jjjj");
u32 YS__MISSION_COUNT__set_param(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z28YS__MISSION_COUNT__set_paramjjjj");
u32 YS__MISSION_COUNT__set_param(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u, r17 = 0u;
    r16 = r5;
    r17 = r4;
    r2 = func_001d1698(r4, r5, r6, r7);
    *(u32*)((u32)r17 + (s32)(44)) = r16;
    return r2;
}
}  // namespace n001d1a18

// ---- 001d1a50 from src/anon/auto80_199_queue.cpp
namespace n001d1a50 {
void func_001d1a50(u32 a0) asm("_Z13func_001d1a50j");
void func_001d1a50(u32 a0) {
    u32 s0 = a0;

    func_001d16f8(s0);

    if (*(u32*)(s0 + 4) == 0) {
        return;
    }

    if (*(u32*)(s0 + 52) == 0) {
        *(u32*)(s0 + 52) = func_0017d930(*(u32*)(s0 + 24));
    }

    u32 f = *(u32*)(s0 + 12);
    u32 arg3 = f & 2u;
    arg3 = (0u < arg3);

    u32 v = func_0014f8d0(
        *(u32*)(s0 + 4),
        *(u32*)(s0 + 8),
        *(u32*)(s0 + 32),
        arg3,
        *(u32*)(s0 + 52),
        s0 + 44,
        s0 + 24,
        *(u32*)(s0 + 36));

    *(u32*)(s0 + 48) = v;

    if ((*(u32*)(s0 + 12) & 8u) != 0) {
        func_00150610(v);
    }
}
}  // namespace n001d1a50

// ---- 001d1ae8 from src/anon/tiny_auto80_queue.cpp
namespace n001d1ae8 {
u32 func_0014f9a8(...) asm("func_0014f9a8");
u32 func_001d1708(...) asm("func_001d1708");
u32 YS__MISSION_COUNT__deactivate(u32 a0) asm("_Z29YS__MISSION_COUNT__deactivatej");
u32 YS__MISSION_COUNT__deactivate(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(48));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_0014f9a8)(r4);
        *(volatile u32*)((u32)r16 + (s32)(48)) = 0u;
    }
    r4 = r16;
    return ((u32(*)(u32))func_001d1708)(r4);
}
}  // namespace n001d1ae8

// ---- 001d1b28 from src/anon/tiny_auto80_queue.cpp
namespace n001d1b28 {
u32 func_0014f9a8(...) asm("func_0014f9a8");
u32 func_001d1708(...) asm("func_001d1708");
u32 func_001d1b28(u32 a0) asm("_Z13func_001d1b28j");
u32 func_001d1b28(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(48));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_0014f9a8)(r4);
    }
    r4 = r16;
    return ((u32(*)(u32))func_001d1708)(r4);
}
}  // namespace n001d1b28

// ---- 001d1b60 from src/anon/auto80_199_queue.cpp
namespace n001d1b60 {
void func_001d17b0(u32 a0, s32) asm("func_001d17b0");
void YS__MISSION_COUNT__set(u32 a0, s32 a1) asm("_Z22YS__MISSION_COUNT__setji");
void YS__MISSION_COUNT__set(u32 a0, s32 a1) {
    s32 s0 = a1;
    s32 v = *(s32*)(a0 + 24);

    if (a1 >= v) {
        if (*(s32*)(a0 + 44) < v) {
            func_001d1720(a0, 123);
            v = *(s32*)(a0 + 24);
        }
        s0 = v;
    } else {
        if (a1 <= 0) {
            if (*(s32*)(a0 + 44) > 0) {
                func_001d1720(a0, 14);
            }
            s0 = 0;
        }
    }

    func_001d17b0(a0, s0);
    *(u32*)(a0 + 44) = (u32)s0;
}
}  // namespace n001d1b60

// ---- 001d1bf0 gap (never-written function)
namespace g001d1bf0 {
void func_00150578(u8*) asm("func_00150578");
void YS__MISSION2D__set_warning(u8*) asm("YS__MISSION2D__set_warning");
void func_001d1bf0(u8* p) asm("func_001d1bf0");
void func_001d1bf0(u8* p) {
    u8* t = *(u8**)(p + 48);
    if (t) func_00150578(t);
    YS__MISSION2D__set_warning(p);
}
}  // namespace g001d1bf0

// ---- 001d1c28 from src/anon/tiny_auto80_queue.cpp
namespace n001d1c28 {
void func_001505b0(...) asm("func_001505b0");
void YS__MISSION_COUNT__reset_warning(u8* a0) asm("_Z32YS__MISSION_COUNT__reset_warningPh");
void YS__MISSION_COUNT__reset_warning(u8* a0) {
    u8* s0 = a0;
    u8* t7 = *(u8**)(a0 + 48);
    if (t7 != 0) {
        func_001505b0(t7);
    }
    u32 t7v = *(u32*)(s0 + 12);
    u32 t6 = 0xFFFFFFF7;
    t7v = t7v & t6;
    *(u32*)(s0 + 12) = t7v;
}
}  // namespace n001d1c28

// ---- 001d1c70 from src/anon/tiny_auto80_queue.cpp
namespace n001d1c70 {
u32 func_0014fa08(...) asm("func_0014fa08");
void func_001d1c70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001d1c70jjjjjjjj");
void func_001d1c70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(48));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0014fa08)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(48)) = 0u;
    }
}
}  // namespace n001d1c70

// ---- 001d1ca8 from src/anon/tiny_auto80_queue.cpp
namespace n001d1ca8 {
u32 func_0014f9e8(...) asm("func_0014f9e8");
u32 func_001d1ca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001d1ca8jjjjjjjj");
u32 func_001d1ca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = 0u;
    r15 = *(volatile u32*)((u32)r4 + (s32)(48));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0014f9e8)(r4, r5, r6, r7, r8, r9, r10, r11);
        r2 = ((u32)0u < (u32)r2);
    }
    return r2;
}
}  // namespace n001d1ca8

// ---- 001d1cd8 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001d1cd8 {
u32 func_001d1678(u32, u32, u32, u32) asm("_Z13func_001d1678jjjj");
u32 func_001d1cd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d1cd8jjjj");
u32 func_001d1cd8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_001d1678(r4, r5, r6, r7);                     
    *(u32*)((u32)r16 + (s32)(48)) = 0u;
    return r2;
}
}  // namespace n001d1cd8

// ---- 001d1d00 from src/anon/auto80_199_queue.cpp
namespace n001d1d00 {
void func_001d1d00(u32 a0) asm("_Z13func_001d1d00j");
void func_001d1d00(u32 a0) {
    u32 s0 = a0;

    func_001d16f8(s0);

    f32 v = (f32)*(s32*)(s0 + 20);
    *(f32*)(s0 + 44) = v;

    if (*(u32*)(s0 + 4) != 0) {
        YS__MISSION_GAUGE__destroy(s0);

        f32 f = (f32)*(s32*)(s0 + 24);
        *(u32*)(s0 + 48) = func_0014fa48(
            *(u32*)(s0 + 4),
            *(u32*)(s0 + 8),
            *(u32*)(s0 + 32),
            s0 + 44,
            *(u32*)(s0 + 36),
            f);
    }
}
}  // namespace n001d1d00

// ---- 001d1d68 from src/anon/tiny_auto80_queue.cpp
namespace n001d1d68 {
u32 func_0014fb00(...) asm("func_0014fb00");
u32 func_001d1708(...) asm("func_001d1708");
u32 func_001d1d68(u32 a0) asm("_Z13func_001d1d68j");
u32 func_001d1d68(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(48));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_0014fb00)(r4);
    }
    r4 = r16;
    return ((u32(*)(u32))func_001d1708)(r4);
}
}  // namespace n001d1d68

// ---- 001d1da0 from src/anon/batch_wcx.cpp
namespace n001d1da0 {
void func_001d1720(u8*, s32) asm("func_001d1720");
void func_001d17b0(u8*, s32) asm("func_001d17b0");
void YS__MISSION_GAUGE__set(u8* p, f32 x) asm("YS__MISSION_GAUGE__set");
void YS__MISSION_GAUGE__set(u8* p, f32 x)
{
    if (x <= 0.0f) {
        if (0.0f < *(f32*)(p + 44)) func_001d1720(p, 136);
        x = 0.0f;
    } else if ((f32)*(s32*)(p + 24) <= x) {
        if (*(f32*)(p + 44) < (f32)*(s32*)(p + 24)) func_001d1720(p, 137);
        x = (f32)*(s32*)(p + 24);
    }
    func_001d17b0(p, (s32)x);
    *(f32*)(p + 44) = x;
}
}  // namespace n001d1da0

// ---- 001d1e50 gap (never-written function)
namespace g001d1e50 {
void dk__MISSION_GAUGE__alert(u8*) asm("dk__MISSION_GAUGE__alert");
void YS__MISSION2D__set_warning(u8*) asm("YS__MISSION2D__set_warning");
void func_001d1e50(u8* p) asm("func_001d1e50");
void func_001d1e50(u8* p) {
    u8* t = *(u8**)(p + 48);
    if (t) dk__MISSION_GAUGE__alert(t);
    YS__MISSION2D__set_warning(p);
}
}  // namespace g001d1e50

// ---- 001d1e88 from src/anon/tiny_auto80_queue.cpp
namespace n001d1e88 {
void dk__MISSION_GAUGE__releaseAlert(...) asm("dk__MISSION_GAUGE__releaseAlert");
void func_001d1e88(u8* a0) asm("_Z13func_001d1e88Ph");
void func_001d1e88(u8* a0) {
    u8* s0 = a0;
    u8* t7 = *(u8**)(a0 + 48);
    if (t7 != 0) {
        dk__MISSION_GAUGE__releaseAlert(t7);
    }
    u32 t7v = *(u32*)(s0 + 12);
    u32 t6 = 0xFFFFFFF7;
    t7v = t7v & t6;
    *(u32*)(s0 + 12) = t7v;
}
}  // namespace n001d1e88

// ---- 001d1ed0 from src/anon/tiny_auto80_queue.cpp
namespace n001d1ed0 {
u32 func_0014fb60(...) asm("func_0014fb60");
void YS__MISSION_GAUGE__destroy(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z26YS__MISSION_GAUGE__destroyjjjjjjjj");
void YS__MISSION_GAUGE__destroy(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(48));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0014fb60)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(48)) = 0u;
    }
}
}  // namespace n001d1ed0

// ---- 001d1f08 from src/anon/tiny_auto80_queue.cpp
namespace n001d1f08 {
u32 func_0014fb40(...) asm("func_0014fb40");
u32 YS__MISSION_GAUGE__is_open(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z26YS__MISSION_GAUGE__is_openjjjjjjjj");
u32 YS__MISSION_GAUGE__is_open(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = 0u;
    r15 = *(volatile u32*)((u32)r4 + (s32)(48));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0014fb40)(r4, r5, r6, r7, r8, r9, r10, r11);
        r2 = ((u32)0u < (u32)r2);
    }
    return r2;
}
}  // namespace n001d1f08

// ---- 001d1f38 from src/anon/batch_w37.cpp
namespace n001d1f38 {
void func_001d1678(void*, s32) asm("func_001d1678");
void func_001d19e8(void*, s32) asm("func_001d19e8");
void func_001d16e8(void*, u32, u32) asm("func_001d16e8");
extern u8 D_003525c8[] asm("D_003525c8");
extern u8 D_003525e8[] asm("D_003525e8");
void YS__COMBOCOUNTER__COMBOCOUNTER(u32* p) asm("YS__COMBOCOUNTER__COMBOCOUNTER");
void YS__COMBOCOUNTER__COMBOCOUNTER(u32* p) {
    p[1] = 0;
    p[0] = (u32)D_003525c8;
    p[2] = 0;
    p[3] = 0;
    func_001d1678(p, -1);                     
    p[12] = 0;
    p[0] = (u32)D_003525e8;
    func_001d19e8(p, -1);
    p[11] = 0;
    p[14] = 0;
    func_001d16e8(p, 0, 12);
}
}  // namespace n001d1f38

// ---- 001d1fa8 from src/anon/batch_w39.cpp
namespace n001d1fa8 {
extern void* D_003525c8[] asm("D_003525c8");
extern void* D_003525e8[] asm("D_003525e8");
void func_00320400(u8*) asm("func_00320400");
void func_001d1678(u8*, int) asm("func_001d1678");
void func_001d19e8(u8*, int) asm("func_001d19e8");
void func_001d16e8(u8*, int, int) asm("func_001d16e8");
void func_001d1fa8(u8* p) asm("func_001d1fa8");
void func_001d1fa8(u8* p) {                    
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_003525c8;
    *(u32*)(p + 8) = 0;
    func_00320400(p + 12);
    func_001d1678(p, -1);                     
    *(u32*)(p + 48) = 0;
    *(u32*)p = (u32)D_003525e8;
    func_001d19e8(p, -1);
    *(u32*)(p + 44) = 0;
    *(u32*)(p + 56) = 0;
    func_001d16e8(p, 0, 12);
}
}  // namespace n001d1fa8

// ---- 001d2020 from src/anon/tiny_auto80_fptr4.cpp
namespace n001d2020 {
u32 func_001d2210(u32, u32, u32, u32) asm("_Z13func_001d2210jjjj");
extern u8 D_003525e8 asm("D_003525e8");
u32 func_001d2020(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d2020jjjj");
u32 func_001d2020(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003525e8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001d2210)(u32, u32, u32, u32) = func_001d2210;
    r2 = fp_call4_001d2210(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001d2020

// ---- 001d2048 from src/anon/tiny_auto80_fptr4.cpp
namespace n001d2048 {
u32 func_001d2210(u32, u32, u32, u32) asm("_Z13func_001d2210jjjj");
extern u8 D_003525e8 asm("D_003525e8");
u32 func_001d2048(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d2048jjjj");
u32 func_001d2048(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003525e8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001d2210)(u32, u32, u32, u32) = func_001d2210;
    r2 = fp_call4_001d2210(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001d2048

// ---- 001d2070 from src/anon/batch_w13.cpp
namespace n001d2070 {
void func_00106420(void*) asm("func_00106420");
void func_001d2210(void*) asm("func_001d2210");
extern u8 D_003525e8 asm("D_003525e8");
void func_001d2070(void** p) asm("func_001d2070");
void func_001d2070(void** p) {
    *p = &D_003525e8;
    func_001d2210(p);
    func_00106420(p);
}
}  // namespace n001d2070

// ---- 001d20a8 from src/anon/auto80_199_queue.cpp
namespace n001d20a8 {
void func_001d20a8(u32 a0) asm("_Z13func_001d20a8j");
void func_001d20a8(u32 a0) {
    u32 s0 = a0;

    func_001d16f8(s0);

    if (*(u32*)(s0 + 52) == 0) {
        *(u32*)(s0 + 52) = func_0017d930(*(u32*)(s0 + 24));
    }

    u32 v = func_0014f8d0(
        *(u32*)(s0 + 4),
        *(u32*)(s0 + 8),
        *(u32*)(s0 + 32),
        1,
        *(u32*)(s0 + 52),
        s0 + 44,
        s0 + 56,
        *(u32*)(s0 + 36));

    *(u32*)(s0 + 48) = v;
}
}  // namespace n001d20a8

// ---- 001d2110 from src/anon/perm_001d2110.cpp
namespace n001d2110 {
typedef unsigned char u8;
typedef signed int s32;
inline u8 *inline_fn(void *arg0)
{
  return (u8 *) arg0;
}
void func_001d2110(void *p, s32 n) asm("func_001d2110");
void func_001d2110(void *p, s32 n)
{
  s32 new_var;
  s32 max = *((s32 *) (((u8 *) p) + 24));
  s32 lt = n < max;
  if (n <= 0)
  {
    n = 0;
  }
  if (!lt)
  {
    if (n)
    {
      n = max;
    }
    else
    {
      new_var = max;
      n = new_var;
    }
  }
  *((s32 *) (inline_fn(p) + 44)) = n;
}
}  // namespace n001d2110

// ---- 001d2130 from src/anon/batch_w35.cpp
namespace n001d2130 {
void func_001d2110(void*, s32) asm("func_001d2110");
void func_001d2248(void*, s32) asm("func_001d2248");
void func_001d2130(u8* p, s32 n, f32 f) asm("func_001d2130");
void func_001d2130(u8* p, s32 n, f32 f) {
    func_001d2110(p, *(s32*)(p + 44) + n);
    func_001d2248(p, *(s32*)(p + 44));
    *(f32*)(p + 60) = f;
}
}  // namespace n001d2130

// ---- 001d2180 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001d2180 {
u32 func_001d2110(u32, u32, u32, u32) asm("_Z13func_001d2110jjjj");
u32 YS__COMBOCOUNTER__reset(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z23YS__COMBOCOUNTER__resetjjjj");
u32 YS__COMBOCOUNTER__reset(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r5 = 0u;
    r16 = r4;
    r2 = func_001d2110(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(12));
    r14 = (u32)((s32)0u + (-9));
    *(u32*)((u32)r16 + (s32)(60)) = 0u;
    r15 = (u32)(r15 & r14);
    *(u32*)((u32)r16 + (s32)(12)) = r15;
    return r2;
}
}  // namespace n001d2180

// ---- 001d21c0 from src/anon/batch_w27.cpp
namespace n001d21c0 {
extern f32 D_00349e10 asm("D_00349e10");
void YS__COMBOCOUNTER__reset(void*) asm("YS__COMBOCOUNTER__reset");
s32 func_001d21c0(u8* p) asm("func_001d21c0");
s32 func_001d21c0(u8* p) {
    if (*(f32*)(p + 60) > 0.0f) {
        f32 n = *(f32*)(p + 60) - D_00349e10;
        *(f32*)(p + 60) = n;
        if (n <= 0.0f) { YS__COMBOCOUNTER__reset(p); return 0; }
    }
    return 1;
}
}  // namespace n001d21c0

// ---- 001d2210 from src/anon/batch_w14.cpp
namespace n001d2210 {
void u_call4_001d2210(u32, u32, u32, u32) asm("_Z16u_call4_001d2210jjjj");
void u_call4_001d2210(u32 a0, u32, u32, u32) {
    u8* p = (u8*)a0;
    if (*(u32*)(p + 12) & 4) {
        (*(void (**)(void*))(*(u8**)p + 8))(p);
    }
}
}  // namespace n001d2210

// ---- 001d2248 from src/anon/batch_w1749.cpp
namespace n001d2248 {
struct M2D { u8 pad[0x1c]; s32 m1c; u8 pad2[0x18]; s32 m38; };
void check_warning(M2D* self, s32 v) asm("_ZN2YS9MISSION2D13check_warningEi");
void func_001d2248(M2D* o, s32 v) asm("func_001d2248");
void func_001d2248(M2D* o, s32 v)
{
    if (o->m38 < v) {
        o->m38 = v;
        check_warning(o, v);
        if (o->m1c != 0 && o->m1c < o->m38) o->m1c = o->m38;
    }
}
}  // namespace n001d2248

// ---- 001d2298 from src/anon/tiny.cpp
namespace n001d2298 {
void func_001d2298(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d2298jjjj");
void func_001d2298(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d6u << 16);
    *(u32*)((u32)b + (-17920)) = (u32)a0;
}
}  // namespace n001d2298

// ---- 001d22a8 from src/anon/batch_w15.cpp
namespace n001d22a8 {
u8 func_002fd248(u32, void*, u32, u32, void*) asm("func_002fd248");
extern u8* D_01d5ba00 asm("D_01d5ba00");
extern u8 D_00321688 asm("D_00321688");
u8 func_001d22a8(u32 a) asm("func_001d22a8");
u8 func_001d22a8(u32 a) {
    u8* t = D_01d5ba00;
    return func_002fd248(a, t + 8, *(u32*)(t + 4), 16, &D_00321688);
}
}  // namespace n001d22a8

// ---- 001d22e0 from src/anon/batch_w1791.cpp
namespace n001d22e0 {
void func_0017f540(void*, s32, f32, f32) asm("func_0017f540");
struct Ch {
    u8 pad0[0x10];
    f32 f10, f14, f18, f1c;
    u8 pad20[0x110 - 0x20];
    f32 f110, f114;
    u8 pad118[0x140 - 0x118];
    u8 snd[0x20];
    u32 flags;
};
void YS__ACTION_LM__control(void* a, Ch* c) asm("YS__ACTION_LM__control");
void YS__ACTION_LM__control(void* a, Ch* c) {
    s32 id;
    f32 v = c->f1c;
    if (v > 0.0f) {
        if (c->f10 == 0.0f && c->f18 == 0.0f) {
            if (c->f14 < 0.0f) id = 154; else id = 155;
        } else {
            if (v < (c->f110 + c->f114) * 0.5f) id = 1; else id = 2;
        }
    } else {
        id = 0;
    }
    void* p = c->snd;
    if (c->flags & 4) func_0017f540(p, id, 20.0f, 0.0f);
}
}  // namespace n001d22e0

// ---- 001d2398 gap (never-written function)
namespace g001d2398 {
struct Vq { f32 x, y, z, w; Vq& operator=(const Vq& s) { if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory"); return *this; } } __attribute__((aligned(16)));
Vq kn__MotionPrototype0__calcLimitValue(u8*, f32, f32) asm("kn__MotionPrototype0__calcLimitValue");
Vq func_001d2398(u32, u8* o) asm("func_001d2398");
Vq func_001d2398(u32, u8* o) { u8* p = *(u8**)(o + 300); return kn__MotionPrototype0__calcLimitValue(o, *(f32*)(p + 40), *(f32*)(p + 44)); }
}  // namespace g001d2398

// ---- 001d23d0 from src/anon/tiny.cpp
namespace n001d23d0 {
void func_001d23d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d23d0jjjj");
void func_001d23d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d6u << 16);
    *(u32*)((u32)b + (-17916)) = (u32)a0;
}
}  // namespace n001d23d0

// ---- 001d23e0 from src/anon/batch_w16.cpp
namespace n001d23e0 {
u8 func_002fd248(u32, void*, u32, u32, void*) asm("func_002fd248");
extern u32* D_01d5ba04 asm("D_01d5ba04");
extern u8 D_00321698 asm("D_00321698");
u8 func_001d23e0(u32 a) asm("func_001d23e0");
u8 func_001d23e0(u32 a) {
    u32* p = D_01d5ba04;
    return func_002fd248(a, p + 2, p[1], 12, &D_00321698);
}
}  // namespace n001d23e0

// ---- 001d2418 from src/anon/batch_w99.cpp
namespace n001d2418 {
struct V10ce {
    f32 x, y, z, w;
    V10ce& operator=(const V10ce& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline V10ce operator-(const V10ce& a, const V10ce& b)
{
    V10ce r;
    asm(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct V13f6 {
    f32 x, y, z, w;
    V13f6() {}
    V13f6(const V13f6& o) { QCOPY(this, &o); }
    V13f6& operator=(const V13f6& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
    V13f6& operator*=(f32 s)
    {
        asm("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V13f6& operator+=(const V13f6& o)
    {
        asm("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V13f6 operator-(const V13f6& a, const V13f6& b)
{
    V13f6 r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V13f6 operator*(const V13f6& v, f32 s)
{
    V13f6 r;
    asm(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
struct V1791 {
    f32 x, y, z, w;
    V1791& operator=(const V1791& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline V1791 operator*(const V1791& v, f32 s)
{
    V1791 r;
    asm("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V1d24 {
    f32 x, y, z, w;
    V1d24& operator=(const V1d24& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
    V1d24& operator*=(f32 s)
    {
        asm("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 Normalize1d24(V1d24& v)
{
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
struct O1d24 { u8 pad[16]; V1d24 v16; V1d24 dir; };
struct G1d24 { u8 pad[224]; f32 speed; };
extern G1d24* D_00352130 asm("D_00352130");
double func_00313b80(f32) asm("func_00313b80");
s32 func_003142e0(double, double) asm("func_003142e0");
V1d24 YS__OBJ__get_dir(O1d24*) asm("YS__OBJ__get_dir");
void func_0016bd60_1d2418(O1d24*, s32) asm("func_0016bd60");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
void YS__LMPLAYER__swim(O1d24* o) asm("YS__LMPLAYER__swim");
void YS__LMPLAYER__swim(O1d24* o)
{
    if (0.0f < o->v16.w && (o->v16.x != 0.0f || func_003142e0(func_00313b80(o->v16.z), 0.0))) {                   
        o->dir = o->v16;
    } else {
        o->dir = YS__OBJ__get_dir(o);
    }
    o->dir.y = 0.0f;
    Normalize1d24(o->dir);
    o->dir *= D_00352130->speed;
    func_0016bd60_1d2418(o, 39);
    func_0017f488((u8*)o + 320, 151, 8.0f, 0.0f);
    func_0017f5e0((u8*)o + 320, 0, 0, 0.0f, 0.0f);
}
}  // namespace n001d2418

// a global constant (60 frames) that other files read
extern "C++" const f32 R_0036e3bc asm("D_0036e3bc") = 60.0f;

// ---- 001d2578 gap (never-written function)
namespace g001d2578 {
struct QW1d2 { f32 x, y, z, w;
    QW1d2() {}
    QW1d2(const QW1d2& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QW1d2& operator=(const QW1d2& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline QW1d2 operator*(const QW1d2& a, f32 k) {
    QW1d2 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
struct Cfg { u8 p[228]; f32 f228; f32 f232; u8 q[268 - 236]; f32 lo268, hi272, lo276; };
struct Obj1d2 { u8 p0[12]; u8* f12; u8 pp[12]; f32 f28; QW1d2 v32; u8 p1[340 - 48]; s32 f340; u8 rest[2920 - 344]; f32 timer; };
extern Cfg* D_00352130 asm("D_00352130");
void func_0016bd60(Obj1d2*, s32) asm("func_0016bd60");
void YS__OBJ__set_wish_dir(Obj1d2*, QW1d2*) asm("YS__OBJ__set_wish_dir");
void func_001d2578(void*, Obj1d2* o) asm("func_001d2578");
void func_001d2578(void*, Obj1d2* o) {
    if (o->f340 != 151) {
        func_0016bd60(o, 29);
        u8* m = o->f12;
        (*(void (**)(u8*, Obj1d2*))(*(u8**)m + 24))(m, o);
    } else {
        if (o->f28 > 0.0f) o->f28 = D_00352130->f228;
        QW1d2 v(o->v32);
        YS__OBJ__set_wish_dir(o, &v);
    }
}
}  // namespace g001d2578

// ---- 001d2608 gap (never-written function)
namespace g001d2608 {
struct QW1d2 { f32 x, y, z, w;
    QW1d2() {}
    QW1d2(const QW1d2& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QW1d2& operator=(const QW1d2& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline QW1d2 operator*(const QW1d2& a, f32 k) {
    QW1d2 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
struct Cfg { u8 p[228]; f32 f228; f32 f232; u8 q[268 - 236]; f32 lo268, hi272, lo276; };
struct Obj1d2 { u8 p0[12]; u8* f12; u8 pp[12]; f32 f28; QW1d2 v32; u8 p1[340 - 48]; s32 f340; u8 rest[2920 - 344]; f32 timer; };
extern Cfg* D_00352130 asm("D_00352130");
QW1d2 kn__MotionPrototype0__calcLimitValue(Obj1d2*, f32, f32) asm("kn__MotionPrototype0__calcLimitValue");
QW1d2 func_001d2608(void*, Obj1d2* o) asm("func_001d2608");
QW1d2 func_001d2608(void*, Obj1d2* o) { f32 f = D_00352130->f232; return kn__MotionPrototype0__calcLimitValue(o, f, f); }
}  // namespace g001d2608

// ---- 001d2648 from src/anon/batch_w2.cpp
namespace n001d2648 {
void func_001d2690(void*) asm("func_001d2690");
void func_001d2648(s32* p) asm("func_001d2648");
void func_001d2648(s32* p) {                        
    p[0] = 0;
    p[1] = 0;
    p[8] = 0;
    func_001d2690(p);
}
}  // namespace n001d2648

// ---- 001d2668 from src/anon/tiny_auto80_queue.cpp
namespace n001d2668 {
void dk__INFORMATION__openInformationWindow(...) asm("dk__INFORMATION__openInformationWindow");
void func_001d2668(u8* a0, u32 a1, f32 a2) asm("_Z13func_001d2668Phjf");
void func_001d2668(u8* a0, u32 a1, f32 a2) {
    u8* t7 = a0;
    *(u32*)(t7 + 32) = a1;
    *(f32*)(t7 + 36) = a2;
    *(f32*)(t7 + 40) = a2;
    dk__INFORMATION__openInformationWindow(a1);
}
}  // namespace n001d2668

// ---- 001d2690 from src/anon/batch_w55.cpp
namespace n001d2690 {
struct RingEW55 { u32 v; f32 f; };
struct RingW55 { s32 idx; s32 pad; RingEW55 e[3]; };
s32 func_00192048(u32) asm("func_00192048");
void func_001d2690(RingW55* r, u32 b, f32 f) asm("func_001d2690");
void func_001d2690(RingW55* r, u32 b, f32 f) {
    s32 i = r->idx;
    r->idx = (i + 1) % 3;
    RingEW55* e = &r->e[i];
    e->v = func_00192048(b);
    e->f = f * 60.0f;
}
}  // namespace n001d2690

// ---- 001d2710 from src/anon/tiny_auto80_queue.cpp
namespace n001d2710 {
u32 dk__INFORMATION__closeInformationWindow(...) asm("dk__INFORMATION__closeInformationWindow");
void func_001d2710(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001d2710jjjjjjjj");
void func_001d2710(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    ((u32*)(u32)r4)[0] = 0u;
    ((u32*)(u32)r4)[1] = 0u;
    r16 = r4;
    r15 = ((u32*)(u32)r4)[8];
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))dk__INFORMATION__closeInformationWindow)(r4, r5, r6, r7, r8, r9, r10, r11);
        ((u32*)(u32)r16)[8] = 0u;
    }
}
}  // namespace n001d2710

// ---- 001d2750 from src/anon/batch_w82.cpp
namespace n001d2750 {
extern f32 D_00349e10 asm("D_00349e10");
union FU001d { f32 f; s32 i; };
struct Q001d { u32 a; FU001d f; };
struct S001d { s32 end; s32 cur; Q001d e[3]; u32 cur_a; f32 cur_f; f32 timer; };
s32 func_00197920(S001d*) asm("func_00197920");
void func_001d2668(S001d*, u32, f32) asm("func_001d2668");
void YS__INTERVAL_INFO__exec(S001d* a0) asm("YS__INTERVAL_INFO__exec");
void YS__INTERVAL_INFO__exec(S001d* a0)
{
    u32 w;
    s32 i;
    if (func_00197920(a0)) return;
    w = a0->cur_a;
    if (w) {
        a0->timer -= D_00349e10;
        if (a0->timer <= 0.0f) w = 0;
        if (w) return;
    }
    i = a0->cur;
    if (i != a0->end) {
        Q001d* q = &a0->e[i];
        a0->cur = (i + 1) % 3;
        func_001d2668(a0, q->a, q->f.f);
    } else if (a0->cur_a) {
        func_001d2668(a0, a0->cur_a, a0->cur_f);
    }
}
}  // namespace n001d2750

