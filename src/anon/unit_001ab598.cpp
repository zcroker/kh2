// Linked unit 0x1ab598-0x1abad8 (YS file 0x1a8618-0x1abad8, part).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"

#ifndef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#endif

// 001ab598 (from src/anon/batch_w3886.c)
namespace n001ab598 {
typedef union Pk598 { u64 d[2]; u32 w[4]; } Pk598;
typedef struct Ctx598 { u32 a; u32 b; union { Pk598* p; u64 q; }; } Ctx598;
extern volatile u64 D_0036d770 asm("D_0036d770");
s32 func_001aaf98(u32, s32, s32, s32, s32) asm("func_001aaf98");
s32 func_001ab598(u32 a0, Ctx598* c, s32 x, s32 y, u32 col, s32 idx) asm("func_001ab598");
s32 func_001ab598(u32 a0, Ctx598* c, s32 x, s32 y, u32 col, s32 idx) {
    s32 r;
    u32 cc;
    if (func_001aaf98(a0, x, y, 384, 384) != 0) {
        r = 0;
    } else {
        Pk598* volatile* pp = (Pk598* volatile*)&c->p;
        r = 1;
        y += 64;
        cc = col >> 24;
        s32 u = (idx % 10 * 24) << 4;
        s32 v = (idx / 10 * 24) << 4;
        (*pp)->d[0] = D_0036d770;
        (*pp)->d[1] = 6;
        c->p++;
        *(u32*)c->p = 128;
        (*pp)->w[1] = 128;
        c->p->w[2] = 128;
        c->p->w[3] = cc;
        c->p++;
        c->p->w[0] = u + 8;
        c->p->w[1] = v + 8;
        c->p->w[2] = 0;
        c->p->w[3] = 0;
        c->p++;
        c->p->w[0] = x;
        c->p->w[1] = y - 384;
        c->p->w[2] = 0;
        c->p->w[3] = 0x8000;
        c->p++;
        c->p->w[0] = u + 392;
        c->p->w[1] = v + 392;
        c->p->w[2] = 0;
        c->p->w[3] = 0;
        c->p++;
        c->p->w[0] = x + 384;
        c->p->w[1] = y;
        c->p->w[2] = 0;
        c->p->w[3] = 0;
        c->p++;
    }
    return r;
}
} // n001ab598

// 001ab750 (from src/anon/batch_wcx2.cpp)
namespace n001ab750 {
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
void func_001b7e68(u8*, u32) asm("func_001b7e68");
u32 func_001aaea8(u8*, u32) asm("func_001aaea8");
void func_001b8010(u8*, u32, u32, u32, u32, u32, u32, u32, s32, u64, s32, u64, s32, u64, u64) asm("func_001b8010");
void func_001b80d8_b750(u8*) asm("func_001b80d8");
void func_001ab750(u8* p, u8* q) asm("func_001ab750");
void func_001ab750(u8* p, u8* q) {
    func_001b7e68(q, 8);
    u32 r = func_001aaea8(p, 0);
    func_001b8010(q, 1, 71, 0x3000d, 63, 0, 6, r, 20, 96, 22, 0x4007ff8001300000ull, 66, 68, 0xffff);
    func_001b80d8_b750(q);
}
} // n001ab750

// 001ab800 (from src/anon/tiny.cpp)
namespace n001ab800 {
extern u32 D_01c6cd20 asm("D_01c6cd20");
u32 func_001ab800(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001ab800");
u32 func_001ab800(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_01c6cd20;
}
} // n001ab800

// 001ab810 (from src/anon/tiny.cpp)
namespace n001ab810 {
u32 func_001ab810(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001ab810");
u32 func_001ab810(u32 a0, u32 a1, u32 a2, u32 a3) {                       
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x01c7u << 16);
    return (u32)(*(u32*)((u32)b + (-12608)));
}
} // n001ab810

// 001ab820 (from src/anon/auto80_199_queue.cpp)
namespace n001ab820 {
u32 func_001ab820(u32 a0) asm("func_001ab820");
u32 func_001ab820(u32 a0) {
    s32 v0 = func_00105c30();
    if ((v0 == 1) || (v0 == 8)) {
        s32 t = (s32)(((u32)*(u8*)(a0 + 0x10)) << 1);
        return (u32)(t / 3);
    }
    return ((u32)*(u8*)(a0 + 0x10)) / 3;
}
} // n001ab820

// 001ab890 (from src/anon/batch_w3782.cpp)
namespace n001ab890 {
void func_001aae28(void*, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_001aae28");
void image_ctor_001ab890(void*) asm("_ZN2YI5IMAGEC1Ev");
void func_002361d0(void*) asm("func_002361d0");
extern u8 D_01c6cc60[] asm("D_01c6cc60");
extern u8 D_01c6cd20[] asm("D_01c6cd20");
void wtarget_001ab890(u32 init, u32 prio, u32 a2, u32 a3) asm("_Z16wtarget_001ab890jjjj");
void wtarget_001ab890(u32 init, u32 prio, u32 a2, u32 a3)
{
    if (prio == 0xffff && init == 1) {
        func_001aae28(D_01c6cc60, 0, 0, 9, 8, 18, 18, 18, 18, 6, 6);
        func_001aae28(D_01c6cc60 + 32, 1, 0, 9, 8, 18, 18, 18, 18, 6, 12);
        func_001aae28(D_01c6cc60 + 64, 2, 0, 9, 8, 18, 18, 18, 18, 6, 30);
        s32 k = 2;
        asm("" : "+r"(k));
        func_001aae28(D_01c6cc60 + 96, 3, 2048, 9, 9, 24, 24, 24, 24, k, 6);
        func_001aae28(D_01c6cc60 + 128, 4, 2048, 9, 9, 24, 24, 24, 24, 2, 10);
        func_001aae28(D_01c6cc60 + 160, 5, 0, 9, 8, 18, 18, 18, 18, 6, 6);
        asm("" :: "r"(D_01c6cc60));
    }
    if (prio == 0xffff && init == 1) {
        image_ctor_001ab890(D_01c6cd20);
    }
    if (prio == 0xffff && init == 0) {
        func_002361d0(D_01c6cd20);
    }
}
} // n001ab890

// 001aba98 (from src/anon/tiny_wrappers_more.cpp)
namespace n001aba98 {
u32 func_001ab890(u32, u32, u32, u32) asm("func_001ab890");
u32 func_001aba98(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001aba98");
u32 func_001aba98(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ab890(0x00000001u, 0x0000ffffu, a2, a3);
}
} // n001aba98

// 001abab8 (gap: _GLOBAL__D_ stub)
namespace n001abab8 {
u32 func_001ab890(u32, u32, u32, u32) asm("func_001ab890");
u32 func_001abab8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001abab8");
u32 func_001abab8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ab890(0, 0x0000ffffu, a2, a3);
}
} // n001abab8
