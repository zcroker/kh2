#include "../common/types.h"
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
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../harata/libdk/lockon.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/dbg_smenu.hpp"
#include "../harata/libdk/objcamera.hpp"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// ---- 0013ef70 from src/anon/tiny.cpp
namespace n0013ef70 {
extern u32 D_00348700 asm("D_00348700");
void func_0013ef70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0013ef70jjjj");
void func_0013ef70(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_00348700 = (u8)v;
}
}  // namespace n0013ef70

// ---- 0013ef80 from src/anon/tiny.cpp
namespace n0013ef80 {
u32 func_0013ef80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0013ef80jjjj");
u32 func_0013ef80(u32 a0, u32 a1, u32 a2, u32 a3) {                           
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u8*)((u32)b + (-30976)));
}
}  // namespace n0013ef80

// ---- 0013ef90 from src/anon/auto80_199_queue.cpp
namespace n0013ef90 {
u32 func_0013ef90(u32 a0) asm("_Z13func_0013ef90j");
u32 func_0013ef90(u32 a0) {
    func_0014df88(a0);
    if ((D_00348704 & 0x40000000) == 0) {
        func_0014e0d8(216);
    } else {
        func_0014e098();
    }
    return func_001024a8(a0);
}
}  // namespace n0013ef90

// ---- 0013efe8 from src/anon/batch_w18.cpp
namespace n0013efe8 {
extern u8 D_00348700 asm("D_00348700");
extern void* D_0032b96c asm("D_0032b96c");
void func_0013ef90(void) asm("func_0013ef90");
void func_00102788(void*, u32, u32, void*) asm("func_00102788");
void func_0013efe8(void) asm("func_0013efe8");
void func_0013efe8(void) {
    D_00348700 = 0;
    func_00102788(D_0032b96c, 0, 300000, (void*)func_0013ef90);
}
}  // namespace n0013efe8

// ---- 0013f020 from src/anon/tiny.cpp
namespace n0013f020 {
extern u32 D_00348700 asm("D_00348700");
void func_0013f020(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0013f020jjjj");
void func_0013f020(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_00348700 = (u8)v;
}
}  // namespace n0013f020

// ---- 0013f030 from src/harata/libdk/drawframe.cpp
namespace dk {
extern "C" void drawFrameEnable_clear_raw(void) asm("_Z13func_0014df98v");
void clearDrawFrameEnable() { drawFrameEnable_clear_raw(); }
}  // namespace dk

// ---- 0013f048 from src/tozawa/dbg_smenu.cpp
namespace Tz {
void DbgSMenu::SignalCall() {}
}  // namespace Tz

// ---- 0013f050 from src/anon/batch_w53.cpp
namespace n0013f050 {
extern s32 D_00348704 asm("D_00348704");
void func_0013f230(void) asm("func_0013f230");
void func_0015d540(void) asm("func_0015d540");
void func_0013f378(void) asm("func_0013f378");
void func_0013f498(void) asm("func_0013f498");
void func_0013f050(s32 a) asm("func_0013f050");
void func_0013f050(s32 a) {
    if (a < 0) {
        D_00348704 = a & 0x7fffffff;
        return;
    }
    D_00348704 = a;
    a &= 0x3fffffff;
    if (a == 1) goto L1;
    if (a == 0) goto L0;
    if (a == 2) goto L2;
    if (a != 3) return;
    func_0013f498();
    return;
L2:
    func_0013f378();
    return;
L0:
    func_0015d540();
    return;
L1:
    func_0013f230();
}
}  // namespace n0013f050

// ---- 0013f0d0 from src/anon/batch_w50.cpp
namespace n0013f0d0 {
s32 func_001991a8(s32, s32) asm("func_001991a8");
void func_0013f030(void) asm("func_0013f030");
void func_0013f048(void) asm("func_0013f048");
extern u32 D_00348704 asm("D_00348704");
void func_0013f288(void) asm("func_0013f288");
void func_0015d690(void) asm("func_0015d690");
void func_0013f3d0(void) asm("func_0013f3d0");
void func_0013f4d8(void) asm("func_0013f4d8");
void func_0013f0d0(void) asm("func_0013f0d0");
void func_0013f0d0(void) {
    if (func_001991a8(0, 0)) {
        func_0013f030();
        func_0013f048();
        return;
    }
    switch (D_00348704 & 0x3fffffff) {
    case 1: func_0013f288(); break;
    case 0: func_0015d690(); break;
    case 2: func_0013f3d0(); break;
    case 3: func_0013f4d8(); break;
    }
}
}  // namespace n0013f0d0

// ---- 0013f160 from src/anon/batch_w19.cpp
namespace n0013f160 {
void func_0013f030(void) asm("func_0013f030");
void func_0013f048(void) asm("func_0013f048");
void* func_0014aba8(void) asm("func_0014aba8");
void func_0014aa80(void*, s32, s32) asm("func_0014aa80");
void jumpeffect_outclear(void) asm("_ZN2dk10JumpEffect8outClearEv");
void jumpeffect_outclear(void) {
    func_0013f030();
    func_0013f048();
    func_0014aa80(func_0014aba8(), 1, 0);
}
}  // namespace n0013f160

// ---- 0013f198 from src/anon/tiny_auto80_queue.cpp
namespace n0013f198 {
u32 func_001024a8(...) asm("func_001024a8");
u32 func_0013f020(...) asm("func_0013f020");
u32 func_0014aba8(...) asm("func_0014aba8");
void func_0013f198(u32 a0) asm("_Z13func_0013f198j");
void func_0013f198(u32 a0) {
    u32 s0 = a0;
    u32 r2 = func_0014aba8();
    u32 t7 = *(volatile u32*)((u32)r2 + (s32)(252));
    t7 = (u32)(t7 ^ 4u);
    if (t7 == 0u) {
        func_001024a8(s0);
        func_0013f020();
        return;
    }
}
}  // namespace n0013f198

// ---- 0013f1e8 from src/anon/tiny_auto80_queue.cpp
namespace n0013f1e8 {
u32 func_001024a8(...) asm("func_001024a8");
u32 func_0013f048(...) asm("func_0013f048");
u32 func_0014aba8(...) asm("func_0014aba8");
void func_0013f1e8(u32 a0) asm("_Z13func_0013f1e8j");
void func_0013f1e8(u32 a0) {
    u32 s0 = a0;
    u32 r2 = func_0014aba8();
    u32 t7 = *(volatile u32*)((u32)r2 + (s32)(252));
    if (t7 == 0u) {
        func_001024a8(s0);
        func_0013f048();
        return;
    }
}
}  // namespace n0013f1e8

// ---- 0013f230 from src/anon/auto80_199_queue.cpp
namespace n0013f230 {
u32 func_0013f230(void) asm("_Z13func_0013f230v");
u32 func_0013f230(void) {
    func_0013efe8();
    u32 v0 = func_00102c80();
    u32 a0 = *(u32*)(v0 + 4);
    u32 a2 = 0x00040000;
    u32 a3 = (u32)&func_0013f198;
    func_00102788(a0, 0, a2 | 0x93E0, a3);
    v0 = func_0014aba8();
    return func_0014aa58(v0, 15, 0);
}
}  // namespace n0013f230

// ---- 0013f288 from src/anon/auto80_199_queue.cpp
namespace n0013f288 {
u32 func_0013f288(void) asm("_Z13func_0013f288v");
u32 func_0013f288(void) {
    func_0013f030();
    u32 v0 = func_00102c80();
    u32 a0 = *(u32*)(v0 + 4);
    u32 a2 = 0x00040000;
    u32 a3 = (u32)&func_0013f1e8;
    func_00102788(a0, 1, a2 | 0x93E0, a3);
    v0 = func_0014aba8();
    return func_0014aa80(v0, 15, 0);
}
}  // namespace n0013f288

// ---- 0013f2e0 gap (jump effect out task)
namespace n0013f2e0 {
u8* getAllFade(void) asm("_ZN2dk10getAllFadeEv");
void taskEnd(void*) asm("func_001024a8");
void outFinal(void) asm("_ZN2dk10JumpEffect8outFinalEv");
void func_0013f2e0(void* t) asm("func_0013f2e0");
void func_0013f2e0(void* t) {
    bool done = *(s32*)(getAllFade() + 252) == 4;
    if (done) {
        taskEnd(t);
        outFinal();
    }
}
}  // namespace n0013f2e0

// ---- 0013f330 from src/anon/tiny_auto80_queue.cpp
namespace n0013f330 {
u32 func_001024a8(...) asm("func_001024a8");
u32 func_0013f048(...) asm("func_0013f048");
u32 func_0014aba8(...) asm("func_0014aba8");
void func_0013f330(u32 a0) asm("_Z13func_0013f330j");
void func_0013f330(u32 a0) {
    u32 s0 = a0;
    u32 r2 = func_0014aba8();
    u32 t7 = *(volatile u32*)((u32)r2 + (s32)(252));
    if (t7 == 0u) {
        func_001024a8(s0);
        func_0013f048();
        return;
    }
}
}  // namespace n0013f330

// ---- 0013f378 from src/anon/auto80_199_queue.cpp
namespace n0013f378 {
u32 func_0013f378(void) asm("_Z13func_0013f378v");
u32 func_0013f378(void) {
    func_0013efe8();
    u32 v0 = func_00102c80();
    u32 a0 = *(u32*)(v0 + 4);
    u32 a2 = 0x00040000;
    u32 a3 = (u32)&func_0013f2e0;
    func_00102788(a0, 0, a2 | 0x93E0, a3);
    v0 = func_0014aba8();
    return func_0014aa58(v0, 15, 1);
}
}  // namespace n0013f378

// ---- 0013f3d0 from src/anon/auto80_199_queue.cpp
namespace n0013f3d0 {
u32 func_0013f3d0(void) asm("_Z13func_0013f3d0v");
u32 func_0013f3d0(void) {
    func_0013f030();
    u32 v0 = func_00102c80();
    u32 a0 = *(u32*)(v0 + 4);
    u32 a2 = 0x00040000;
    u32 a3 = (u32)&func_0013f330;
    func_00102788(a0, 1, a2 | 0x93E0, a3);
    v0 = func_0014aba8();
    return func_0014aa80(v0, 15, 1);
}
}  // namespace n0013f3d0

// ---- 0013f428 gap
namespace n0013f428 {
void taskEnd(void*) asm("func_001024a8");
void outFinal(void) asm("_ZN2dk10JumpEffect8outFinalEv");
void func_0013f428(void* t) asm("func_0013f428");
void func_0013f428(void* t) {
    outFinal();
    taskEnd(t);
}
}  // namespace n0013f428

// ---- 0013f450 from src/anon/batch_w26.cpp
namespace n0013f450 {
inline void* operator new(unsigned int, void* p) { return p; }
void loadImage(u32) asm("_ZN2dk9loadImageEj");
void TaskYield(...) asm("_ZN2Tz9TaskYieldEz");
void SignalCall(void) asm("_ZN2Tz8DbgSMenu10SignalCallEv");
void jumpEffectIn_task(void*) asm("_ZN2dk14StopJumpEffect17jumpEffectIn_taskEP4TASK");
void jumpEffectIn_task(void* task) {
    loadImage(216);
    TaskYield(task, 0);
    loadImage(216);
    TaskYield(task, 0);
    SignalCall();
}
}  // namespace n0013f450

// ---- 0013f498 from src/anon/batch_w21.cpp
namespace n0013f498 {
void func_0013efe8(void) asm("func_0013efe8");
u8* func_00102c80(void) asm("func_00102c80");
void func_00102788(u32, u32, u32, void*) asm("func_00102788");
void func_0013f428(void) asm("func_0013f428");
void func_0013f498(void) asm("func_0013f498");
void func_0013f498(void) {
    func_0013efe8();
    func_00102788(*(u32*)(func_00102c80() + 4), 0, 300000, (void*)func_0013f428);
}
}  // namespace n0013f498

// ---- 0013f4d8 from src/anon/batch_w13.cpp
namespace n0013f4d8 {
void func_0013f030(void) asm("func_0013f030");
void* func_00102c80(void) asm("func_00102c80");
void func_00102818(u32, s32, u32, void*, s32) asm("func_00102818");
void func_0013f450(void) asm("func_0013f450");
void func_0013f4d8(void) asm("func_0013f4d8");
void func_0013f4d8(void) {
    func_0013f030();
    u8* v = (u8*)func_00102c80();
    func_00102818(*(u32*)(v + 4), 1, 0x493e0, (void*)func_0013f450, 4096);
}
}  // namespace n0013f4d8

// ---- 0013f518 gap (C2 copy of 0x13f538)
namespace n0013f518 {
void func_0013f518(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013f518");
void func_0013f518(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0;
    *(volatile u32*)((u32)r4 + (s32)(68)) = 0u;
    *(volatile u8*)((u32)r4 + (s32)(56)) = (u8)0u;
    *(volatile u8*)((u32)r4 + (s32)(57)) = (u8)0u;
    *(volatile u8*)((u32)r4 + (s32)(59)) = (u8)0u;
    *(volatile u32*)((u32)r4 + (s32)(60)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(64)) = 0u;
}
}  // namespace n0013f518

// ---- 0013f538 from src/anon/tiny_auto80.cpp
namespace n0013f538 {
void func_0013f538(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0013f538jjjj");
void func_0013f538(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u32*)((u32)r4 + (s32)(68)) = 0u;
    *(volatile u8*)((u32)r4 + (s32)(56)) = (u8)0u;
    *(volatile u8*)((u32)r4 + (s32)(57)) = (u8)0u;
    *(volatile u8*)((u32)r4 + (s32)(59)) = (u8)0u;
    *(volatile u32*)((u32)r4 + (s32)(60)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(64)) = 0u;
}
}  // namespace n0013f538

// ---- 0013f558 from src/anon/batch_w51.cpp
namespace n0013f558 {
f32 func_0013fd10(void*) asm("func_0013fd10");
void func_0013f828(void*) asm("func_0013f828");
void func_0013f888(void*, void*, u32) asm("func_0013f888");
void func_0013f5f0(void*) asm("func_0013f5f0");
void func_0013f608(void*) asm("func_0013f608");
void func_0013f648(void*) asm("func_0013f648");
void func_0013f558(u8* p) asm("func_0013f558");
void func_0013f558(u8* p) {
    p[57] = 0;
    p[58] = 1;
    p[56] = 0;
    p[59] = 0;
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(p + 160) : "memory");
    *(u32*)(p + 52) = 0;
    if (*(u32*)(p + 68)) {
        f32 x = func_0013fd10(p);
        *(f32*)(p + 80) = x;
        *(f32*)(p + 76) = x;
        func_0013f828(p);
        func_0013f888(p, p + 128, 0);
        func_0013f5f0(p);                         
        func_0013f608(p);
        func_0013f648(p);
    }
}
}  // namespace n0013f558

// ---- 0013f5f0 from src/anon/tiny_leaf_fpu.cpp
namespace n0013f5f0 {
void func_0013f5f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0013f5f0jjjj");
void func_0013f5f0(u32 a0, u32 a1, u32 a2, u32 a3) {                         
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    f32 f0 = 0.0f, f1 = 0.0f;
    f0 = *(f32*)((u32)r4 + (s32)(220));
    f1 = *(f32*)((u32)r4 + (s32)(224));
    *(f32*)((u32)r4 + (s32)(48)) = f0;
    *(f32*)((u32)r4 + (s32)(52)) = f1;
}
}  // namespace n0013f5f0

// ---- 0013f608 from src/anon/batch_w22.cpp
namespace n0013f608 {
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_0013f608(f32* p) asm("func_0013f608");
void func_0013f608(f32* p) {
    f32 a = p[13];
    p[41] = a;
    p[40] = p[12];
    p[41] = func_0017ce10(a);
}
}  // namespace n0013f608

// ---- 0013f648 from src/anon/batch_w60.cpp
namespace n0013f648 {
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
void func_0013f608(void*) asm("func_0013f608");
void func_0013f648(QWord* p) asm("func_0013f648");
void func_0013f648(QWord* p) {
    func_0013f608(p);
    p[1] = p[7] = p[6];
    p[0] = p[9] = p[8];
    p[2] = p[11] = p[10];
}
}  // namespace n0013f648

// ---- 0013f6e8 from src/anon/batch_w99.cpp
namespace n0013f6e8 {
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
static inline f32 Length13f6(const V13f6& v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\t"
        "vsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
static inline f32 Dot13f6(const V13f6& a, const V13f6& b)
{
    register f32 r asm("$f0");
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
        "vaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
static inline f32 Normalize13f6(V13f6& v)
{
    register f32 len asm("$f2");
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
V13f6 func_0013f6e8(V13f6* pos, V13f6* anchor, V13f6* vel, f32 dt, f32 k, f32 c, f32 rest) asm("func_0013f6e8");
V13f6 func_0013f6e8(V13f6* pos, V13f6* anchor, V13f6* vel, f32 dt, f32 k, f32 c, f32 rest)
{
    V13f6 d;
    V13f6 v;
    d = *pos - *anchor;
    v = (*vel - *anchor) * dt;
    f32 len = Length13f6(d);
    if (len != 0.0f) {
        f32 f = k * (rest - len) + c * (Dot13f6(d, v) / len);
        Normalize13f6(d);
        d *= f * dt;
        *pos += d;
    }
    return *pos;
}
}  // namespace n0013f6e8

// ---- 0013f828 from src/anon/batch_w217.cpp
namespace n0013f828 {
u32* func_0016c028(u32) asm("func_0016c028");
void func_0013f828(u32* t) asm("func_0013f828");
void func_0013f828(u32* t) {
    u32* s0 = t + 32;
    u32* v = func_0016c028(t[17]);                          
    if (s0 != v) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(s0), "r"(v) : "$8", "memory");
    ((f32*)t)[33] = ((f32*)t)[33] - 170.0f;
}
}  // namespace n0013f828

// ---- 0013f888 from src/anon/batch_w95.cpp
namespace n0013f888 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; } __attribute__((aligned(16)));
static inline void QCOPY_FN(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void VAssign(V4* d, V4* s) {
    if (d != s) QCOPY_FN(d, s);
}
static inline void ApplyM(V4* d, M4* m, V4* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
static inline void ApplyTo(V4* d, M4* m, V4* v) { V4 t; ApplyM(&t, m, v); VAssign(d, &t); }
static inline void VAddTo(V4* d, V4* a, V4* b) {
    V4 t;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&t), "r"(a), "r"(b) : "memory");
    VAssign(d, &t);
}
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator-(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct SaveBig { u64 d[0x10fc0 / 8]; } __attribute__((aligned(16)));
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_004573dc asm("D_004573dc");
void func_0011b6a8(M4*) asm("func_0011b6a8");
void func_0011b720(M4*, f32) asm("func_0011b720");
f32 func_0017ce80(f32, f32, f32) asm("func_0017ce80");
void func_0013f648(u8*) asm("func_0013f648");
void func_0013f888(u8* p, V4* pos, u8 mode) asm("func_0013f888");
void func_0013f888(u8* p, V4* pos, u8 mode) {
    f32 d = *(f32*)(p + 0x48) - *(f32*)(p + 0xd0);
    f32 h = *(f32*)(p + 0xd8) * (d * d);
    if (mode == 1) *(f32*)(p + 0x4c) = *(f32*)(p + 0x50);
    else {
        f32 dt = D_00349e10;
        *(f32*)(p + 0x4c) = func_0017ce80(*(f32*)(p + 0x4c), *(f32*)(p + 0x50), D_004573dc * dt);
    }
    V4 v;
    v.w = v.y = v.x = 0.0f;
    v.z = *(f32*)(p + 0x48);
    M4 m;
    func_0011b6a8(&m);
    func_0011b720(&m, *(f32*)(p + 0x4c));
    ApplyTo(&v, &m, &v);
    VAddTo((V4*)(p + 0x60), pos, &v);
    *(f32*)(p + 0x64) = pos->y - -150.0f - h;
    if (mode == 1) func_0013f648(p);
}
}  // namespace n0013f888

