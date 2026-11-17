// Linked unit 0x142c90-0x144450 (dk::Octree side: globals at 0x348800, array 0x348830 with its static
// init 0x1443c0 and I/D stubs). Flags: -G0 -fno-strict-aliasing.
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../harata/libdk/octfile.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 00142c90 from src/anon/batch_w1677_nsa.cpp
namespace n00142c90 {
struct W1677ResVtbl { void* fn[10]; };
struct W1677Res { W1677ResVtbl* vt; };
struct W1677Model {
    s32 handle;                                             
    W1677Res* res;              
    u8 pad08[8];
    u8 work[0x40];                                       
    u8 sub50[0x24];                                           
    void* tex;                  
    u8 pad78[0x10];
    s32 heap;                   
    u8 flag;                    
};
extern void* D_00348800 asm("D_00348800");
extern void* D_00348804 asm("D_00348804");
extern void* D_00348808 asm("D_00348808");
extern void* D_0034880c asm("D_0034880c");
extern void* D_00348810 asm("D_00348810");
extern void* D_00348814 asm("D_00348814");
extern W1677Model* D_00348818 asm("D_00348818");
extern u8 D_0034881c asm("D_0034881c");
extern u8 D_0034881d asm("D_0034881d");
void* func_001063c0(s32 size, s32 heap) asm("func_001063c0");
void func_00108698(void*) asm("func_00108698");
void func_0011b6a8(void*) asm("func_0011b6a8");
void func_0011e260(s32, void*) asm("func_0011e260");
void func_0011e880(s32, s32, s32, s32) asm("func_0011e880");
void func_0011eb08(s32, s32) asm("func_0011eb08");
void func_001415e8(void*, s32, u64) asm("func_001415e8");
void func_00142bf8(void*) asm("func_00142bf8");
void func_00143278(void) asm("func_00143278");
void func_00143298(void) asm("func_00143298");
void func_00145830(void*, s32, u8, u64) asm("func_00145830");
W1677Res* func_00149288(void*) asm("func_00149288");
void* func_00149290(void*) asm("func_00149290");
s32 func_00149298(void*) asm("func_00149298");
s32 func_001492a0(void*) asm("func_001492a0");
s32 func_001492a8(void*) asm("func_001492a8");
s32 func_001492b0(void*) asm("func_001492b0");
s32 func_001492b8(void*) asm("func_001492b8");
s32 func_001492c0(void*) asm("func_001492c0");
s32 func_001492d0(void*) asm("func_001492d0");
s32 func_001492d8(void*) asm("func_001492d8");
void func_0014ecb8(void) asm("func_0014ecb8");
void func_00153678(s32, u64, s32) asm("func_00153678");
void func_0015c500(void) asm("func_0015c500");
void func_0015c6d0(s32) asm("func_0015c6d0");
void func_00142c90(void* setup, s32 heap, u8 flag, u64 mask) asm("func_00142c90");
void func_00142c90(void* setup, s32 heap, u8 flag, u64 mask) {
    D_0034881c = flag;
    D_0034881d = 0;
    func_00143298();
    func_00143278();

    void* p = func_001063c0(0x5380, heap);
    func_00145830(p, func_00149298(setup), flag, mask);
    D_00348800 = p;

    W1677Model* m = (W1677Model*)func_001063c0(0x90, heap);
    W1677Res* res = func_00149288(setup);
    u8* work = m->work;
    void* tex = func_00149290(setup);
    m->res = res;
    func_00108698(m->sub50);
    m->heap = heap;
    m->handle = ((s32 (*)(W1677Res*, s32))m->res->vt->fn[9])(m->res, heap);
    if (tex) {
        m->tex = tex;
        func_0011e260(m->handle, tex);
    }
    func_0011b6a8(work);
    func_0011eb08(m->handle, 0);
    func_0011e880(m->handle, 2, 0, 0);
    m->flag = 0;
    D_00348818 = m;

    void* q;
    func_0014ecb8();
    if (func_001492a0(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492a0(setup), mask);
        D_00348804 = q;
        func_00142bf8(q);
    }
    if (func_001492a8(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492a8(setup), mask);
        D_00348808 = q;
    }
    if (func_001492b0(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492b0(setup), mask);
        D_0034880c = q;
    }
    if (func_001492b8(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492b8(setup), mask);
        D_00348810 = q;
    }
    if (func_001492c0(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492c0(setup), mask);
        D_00348814 = q;
    }
    func_0015c500();
    if (func_001492d8(setup)) func_0015c6d0(func_001492d8(setup));
    func_00153678(func_001492d0(setup), mask, heap);
}
}  // namespace n00142c90

// ---- 00142f50 from src/anon/batch_wcx2.cpp
namespace n00142f50 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
struct VB30 {
    f32 x, y, z, w;
    VB30& operator=(const VB30& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB30 operator-(const VB30& b) const
    {
        VB30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct VObj5 { void** vt; };
struct Snd5 { u32 a; VObj5* dev; u8 pad[128]; u32 h; };
extern void* D_00348814 asm("D_00348814");
extern void* D_00348810 asm("D_00348810");
extern void* D_0034880c asm("D_0034880c");
extern void* D_00348808 asm("D_00348808");
extern Snd5* D_00348818 asm("D_00348818");
extern void* D_00348804 asm("D_00348804");
extern u8* D_00348800 asm("D_00348800");
void func_0014eda8(void) asm("func_0014eda8");
void func_001537f8(void) asm("func_001537f8");
void func_00106420(void*) asm("func_00106420");
void func_00145ab8(u8*) asm("func_00145ab8");
void func_00142f50(void) asm("func_00142f50");
void func_00142f50(void)
{
    func_0014eda8();
    func_001537f8();
    if (D_00348814) { func_00106420(D_00348814); D_00348814 = 0; }
    if (D_00348810) { func_00106420(D_00348810); D_00348810 = 0; }
    if (D_0034880c) { func_00106420(D_0034880c); D_0034880c = 0; }
    if (D_00348808) { func_00106420(D_00348808); D_00348808 = 0; }
    if (D_00348818) {
        Snd5* s = D_00348818;
        ((void (*)(VObj5*, u32, u32))s->dev->vt[10])(s->dev, s->h, s->a);
        func_00106420(s);
        D_00348818 = 0;
    }
    if (D_00348804) { func_00106420(D_00348804); D_00348804 = 0; }
    u8* o = D_00348800;
    if (o) {
        func_00145ab8(o);
        func_00106420(o);
        D_00348800 = 0;
    }
}
}  // namespace n00142f50

// ---- 00143060 from src/anon/auto80_199_queue.cpp
namespace n00143060 {
void func_00143060(u32 a0) asm("_Z13func_00143060j");
void func_00143060(u32 a0) {
    u32 s0 = a0 & 0xFF;

    func_00145c28(D_00348800, s0);

    if (D_00348814 != 0) {
        func_001418e8(D_00348814, s0);                           
    }
    if (D_00348804 != 0) {
        func_001418e8(D_00348804, s0);                           
    }
    if (D_00348810 != 0) {
        func_001418e8(D_00348810, s0);                           
    }
    if (D_0034880c != 0) {
        func_001418e8(D_0034880c, s0);                           
    }
    if (D_00348808 != 0) {
        func_001418e8(D_00348808, s0);                           
    }
}
}  // namespace n00143060

// ---- 00143110 from src/anon/auto80_199_queue.cpp
namespace n00143110 {
void func_00143110(u32 a0) asm("_Z13func_00143110j");
void func_00143110(u32 a0) {
    u32 s0 = a0 & 0xFF;

    func_00145c68(D_00348800, s0);

    if (D_00348814 != 0) {
        func_00141928(D_00348814, s0);                          
    }
    if (D_00348804 != 0) {
        func_00141928(D_00348804, s0);                          
    }
    if (D_00348810 != 0) {
        func_00141928(D_00348810, s0);                          
    }
    if (D_0034880c != 0) {
        func_00141928(D_0034880c, s0);                          
    }
    if (D_00348808 != 0) {
        func_00141928(D_00348808, s0);                          
    }
}
}  // namespace n00143110

// ---- 001431c0 from src/anon/tiny.cpp
namespace n001431c0 {
extern u32 D_00348818 asm("D_00348818");
void func_001431c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001431c0jjjj");
void func_001431c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    *(u8*)((u32)D_00348818 + (140)) = 0;
}
}  // namespace n001431c0

// ---- 001431d0 from src/anon/batch_w1666.cpp
namespace n001431d0 {
extern u8* D_00348818 asm("D_00348818");
void func_001431d0(void) asm("func_001431d0");
void func_001431d0(void) { D_00348818[140] = 1; }
}  // namespace n001431d0

// ---- 001431e8 from src/anon/tiny_wrappers_imp.cpp
namespace n001431e8 {
u32 func_001431e8(u32, u32, u32, u32) asm("_Z13func_001431e8jjjj");
u32 func_00148528(u32, u32, u32, u32) asm("_Z13func_00148528jjjj");
u32 func_001431e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001431e8jjjj");
u32 func_001431e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(-30720));
    return func_00148528(r4, r5, r6, r7);
}
}  // namespace n001431e8

// ---- 00143208 from src/anon/tiny_wrappers_imp.cpp
namespace n00143208 {
u32 func_00143208(u32, u32, u32, u32) asm("_Z13func_00143208jjjj");
u32 func_00148560(u32, u32, u32, u32) asm("_Z13func_00148560jjjj");
u32 func_00143208(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143208jjjj");
u32 func_00143208(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(-30720));
    return func_00148560(r4, r5, r6, r7);
}
}  // namespace n00143208

// ---- 00143228 from src/anon/tiny_wrappers_imp.cpp
namespace n00143228 {
u32 func_00143208(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143208jjjj");
u32 func_00143228(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143228jjjj");
u32 func_00143228(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = (u32)((s32)0u + (1));
    r15 = (u32)(0x0035u << 16);
    *(u8*)((u32)r15 + (s32)(-30691)) = (u8)r14;
    return func_00143208(r4, r5, r6, r7);
}
}  // namespace n00143228

// ---- 00143248 from src/anon/tiny_wrappers_imp.cpp
namespace n00143248 {
u32 func_001431e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001431e8jjjj");
u32 func_00143248(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143248jjjj");
u32 func_00143248(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    *(u8*)((u32)r15 + (s32)(-30691)) = (u8)0u;
    return func_001431e8(r4, r5, r6, r7);
}
}  // namespace n00143248

// ---- 00143268 from src/anon/tiny.cpp
namespace n00143268 {
extern u32 D_0034881e asm("D_0034881e");
void func_00143268(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143268jjjj");
void func_00143268(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0034881e = (u8)v;
}
}  // namespace n00143268

// ---- 00143278 from src/anon/tiny.cpp
namespace n00143278 {
void func_00143278(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143278jjjj");
void func_00143278(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u8*)((u32)b + (-30690)) = (u8)0;
}
}  // namespace n00143278

// ---- 00143288: unwritten gap getter (byte flag at 0x34881f)
namespace n00143288 {
u32 func_00143288(void) asm("func_00143288");
u32 func_00143288(void) {
    u32 b = (0x0035u << 16);
    return *(u8*)((u32)b + (-30689));
}
}  // namespace n00143288

// ---- 00143298 from src/anon/tiny.cpp
namespace n00143298 {
extern u32 D_0034881f asm("D_0034881f");
void func_00143298(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143298jjjj");
void func_00143298(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0034881f = (u8)v;
}
}  // namespace n00143298

// ---- 001432a8 from src/anon/tiny.cpp
namespace n001432a8 {
void func_001432a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001432a8jjjj");
void func_001432a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u8*)((u32)b + (-30689)) = (u8)0;
}
}  // namespace n001432a8

// ---- 001432b8: unwritten gap setters/getter of the byte at +1913 of the object at 0x348800
namespace n001432b8 {
extern u8* D_00348800 asm("D_00348800");
void func_001432b8(void) asm("func_001432b8");
void func_001432b8(void) { D_00348800[1913] = 1; }
void func_001432d0(void) asm("func_001432d0");
void func_001432d0(void) { D_00348800[1913] = 0; }
u8 func_001432e0(void) asm("func_001432e0");
u8 func_001432e0(void) { return D_00348800[1913]; }
}  // namespace n001432b8

// ---- 001432f0 from src/anon/tiny_auto80_solver.cpp
namespace n001432f0 {
void func_001432f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001432f0jjjjjjjj");
void func_001432f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 base = 0x0035u << 16;
    u32 p = *(u32*)((u32)base + (s32)-30696);
    a0 &= 0xff;
    a1 &= 0xff;
    a2 &= 0xff;
    *(u8*)(p + 84) = a0;
    *(u8*)(p + 85) = a1;
    *(u8*)(p + 86) = a2;
}
}  // namespace n001432f0

// ---- 00143318 from src/anon/tiny_more.cpp
namespace n00143318 {
extern u32 D_00348818 asm("D_00348818");
u32 func_00143318(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00143318jjjj");
u32 func_00143318(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p = D_00348818; return *(u32*)((u32)p + (0)); }
}  // namespace n00143318

// ---- 00143328 from src/anon/tiny_wrappers_imp.cpp
namespace n00143328 {
u32 func_00146e88(u32, u32, u32, u32) asm("_Z13func_00146e88jjjj");
u32 func_00143328(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143328jjjj");
u32 func_00143328(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r5 = r4;
    r15 = (u32)(0x0035u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(-30720));
    return func_00146e88(r4, r5, r6, r7);
}
}  // namespace n00143328

// ---- 00143348 from src/anon/batch_w30.cpp
namespace n00143348 {
s16 func_00147050(u32, u32, void*, u32, void*) asm("func_00147050");
extern u32 D_00348800 asm("D_00348800");
void func_00143348(u8* p) asm("func_00143348");
void func_00143348(u8* p) {                    
    s16 t[2];
    *(s32*)t = 0;
    *(s16*)(p + 0x118) = func_00147050(D_00348800, 0, p, 0, t);
    *(s16*)(p + 0x11a) = t[0];
}
}  // namespace n00143348

// ---- 00143398 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n00143398 {
u32 func_00146f28(u32, u32, u32, u32) asm("_Z13func_00146f28jjjj");
extern u8 D_00350000 asm("D_00350000");
u32 func_00143398(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143398jjjj");
u32 func_00143398(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00146f28(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30720u))), a0, 0x00000001u, a3);
}
}  // namespace n00143398

// ---- 001433c0 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n001433c0 {
u32 func_00146e70(u32, u32, u32, u32) asm("_Z13func_00146e70jjjj");
extern u8 D_00350000 asm("D_00350000");
u32 func_001433c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001433c0jjjj");
u32 func_001433c0(u32 a0, u32 a1, u32 a2, u32 a3) {                   
    return func_00146e70(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30720u))), a0, a1, a3);
}
}  // namespace n001433c0

// ---- 001433e8 from src/anon/auto80_199_queue.cpp
namespace n001433e8 {
void func_001433e8(void) asm("_Z13func_001433e8v");
void func_001433e8(void) {
    func_00146d68(D_00348800);
    u32 s0 = D_00348818;
    func_0011c4b0(*(u32*)s0);

    if (*(u8*)(s0 + 140) != 0) {
        return;
    }

    func_0011ea40(*(u32*)s0, D_00349e10);
}
}  // namespace n001433e8

// ---- 00143448 from src/anon/batch_w2.cpp
namespace n00143448 {
extern void* D_00348804 asm("D_00348804");
u8 func_00141778(void*, u16) asm("func_00141778");
u8 func_00143448(u16 id) asm("func_00143448");
u8 func_00143448(u16 id) {
    return func_00141778(D_00348804, id);
}
}  // namespace n00143448

// ---- 00143470 from src/anon/batch_w35.cpp
namespace n00143470 {
extern u32 D_00348804 asm("D_00348804");
u8 func_001652c8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001652c8");
u32 func_00143470(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) asm("func_00143470");
u32 func_00143470(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    return func_001652c8(D_00348804, a, b, c, d, e, f, g);
}
}  // namespace n00143470

// ---- 001434d0 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n001434d0 {
u32 func_00142900(u32, u32, u32, u32) asm("_Z13func_00142900jjjj");
extern u8 D_00350000 asm("D_00350000");
u32 func_001434d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001434d0jjjj");
u32 func_001434d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00142900(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30716u))), 0x00000000u, a0, a3);
}
}  // namespace n001434d0

// ---- 001434f8: unwritten gap wrapper (like 0x1434d0, with the object at 0x348808)
namespace n001434f8 {
u32 func_00142900(u32, u32, u32, u32) asm("_Z13func_00142900jjjj");
extern u32 D_00348808 asm("D_00348808");
u32 func_001434f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001434f8");
u32 func_001434f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00142900(D_00348808, 0, a0, a3);
}
}  // namespace n001434f8

// ---- 00143520 from src/anon/batch_wcx2.cpp
namespace n00143520 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
struct S_00143520 { u8 pad[48]; Vec4 pos; u8 pad2[32]; s16 h96, h98, h100; u8 pad3[6]; f32 f108; u8 pad4[8]; u32 w120; u8 pad5[20]; };
void func_0031b9e0(S_00143520*) asm("func_0031b9e0");
void func_00143648(S_00143520*, u32) asm("func_00143648");
void func_00143520(Vec4* v, u32 a1) asm("func_00143520");
void func_00143520(Vec4* v, u32 a1) {
    S_00143520 s;
    func_0031b9e0(&s);
    if (&s.pos != v) QCOPY(&s.pos, v);
    s.w120 = 0;
    s.h96 = -1;
    s.f108 = 100.0f;
    s.h100 = -1;
    s.h98 = -1;
    func_00143648(&s, a1);
}
}  // namespace n00143520

// ---- 00143598: unwritten empty gap function (no caller, no address taken)
namespace n00143598 {
void func_00143598(void) asm("func_00143598");
void func_00143598(void) {}
}  // namespace n00143598

// ---- 001435a0 from src/anon/batch_w66.cpp
namespace n001435a0 {
struct E143 { u8 pad[14]; u16 h14; };
struct T143 { u8 pad[12]; E143* f12; u8 pad2[4]; u32* f20; };
extern T143* D_00348814 asm("D_00348814");
void func_00141980(T143*, u8*) asm("func_00141980");
u32 func_00142848(T143*, u32) asm("func_00142848");
u32 func_00142688(T143*, u32*, u32, u32) asm("func_00142688");
u32 func_001435a0(u32 a) asm("func_001435a0");
u32 func_001435a0(u32 a) {
    u8 buf[2048];
    u32 x;
    u32 r = 0;
    if (!D_00348814) return r;
    func_00141980(D_00348814, buf);
    u32 v = func_00142848(D_00348814, a);
    x = 0;
    u32 i = func_00142688(D_00348814, &x, v, a);
    r = 0;
    if (i == 0xffff) return r;
    u32 o = i * 16;
    T143* t = D_00348814;
    u32 o2 = ((E143*)((u8*)t->f12 + o))->h14 * 4;
    return (*(u32*)((u8*)t->f20 + o2) >> 14) & 3;
}
}  // namespace n001435a0

// ---- 00143648 from src/anon/batch_w2400_nsa.cpp
namespace n00143648 {
struct V4q {
    f32 x, y, z, w;
    V4q() {}
    V4q(const V4q& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4q& operator=(const V4q& o) {
        if (this == &o) return *this;
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct EntQ { u8 b0; u8 b1; u8 pad[14]; };
struct MgrQ { u8 pad[12]; EntQ* tbl; };
struct InfQ { s16 h0; s16 h2; };
struct ObjQ { u8 pad[48]; V4q pos; u8 pad2[32]; u16 h96; u8 pad3[10]; f32 f108; u8 pad4[8]; MgrQ** p120; };
struct OutQ { V4q v0; V4q v16; u8 sub[4]; u32 f36; u32 f40; u32 f44; u32 f48; u8 b52; };
extern MgrQ* D_0034880c asm("D_0034880c");
extern MgrQ* D_00348804 asm("D_00348804");
void func_0015cb78(u8*, s32) asm("func_0015cb78");
void func_00141980(MgrQ*, u8*) asm("func_00141980");
s32 func_00142848(MgrQ*, ObjQ*) asm("func_00142848");
u16 func_00142688(MgrQ*, u32*, s32, ObjQ*) asm("func_00142688");
void func_001539c0(u8*, V4q*) asm("func_001539c0");
u32 func_001435a0(ObjQ*) asm("func_001435a0");
V4q func_00143e50(u16, s32) asm("func_00143e50");
V4q func_001422a0(MgrQ*, u16) asm("func_001422a0");
InfQ* func_00142398(MgrQ*, u16) asm("func_00142398");
InfQ* func_00143ee8(u16, s32) asm("func_00143ee8");
void func_00141988(MgrQ*, EntQ*, V4q*) asm("func_00141988");
static inline void negq(V4q* d, const V4q* s) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tvsub.xyz $vf5, $vf0, $vf4\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(s) : "memory");
}
void func_00143648(ObjQ* o, OutQ* out) asm("func_00143648");
void func_00143648(ObjQ* o, OutQ* out) {
    out->f40 = 0;
    out->b52 = 0;
    out->f44 = 0;
    out->f48 = 0;
    func_0015cb78(out->sub, 0);
    if (D_0034880c) {
        u8 buf[2048];
        func_00141980(D_0034880c, buf);
        s32 n = func_00142848(D_0034880c, o);
        u32 r = 0;
        u16 h = func_00142688(D_0034880c, &r, n, o);
        if (h != 0xffff) {
            EntQ* e = &D_0034880c->tbl[h];
            u8 b0 = e->b0;
            out->f44 = e->b1;
            func_0015cb78(out->sub, b0);
        }
    }
    V4q p = o->pos;
    p.y -= o->f108;
    func_001539c0(out->sub, &p);
    out->f48 = func_001435a0(o);
    out->f36 = o->h96;
    if (o->h96 == 0xffff) {
        out->v0.x = 0.0f;
        out->v0.y = -1.0f;
        out->v0.z = 0.0f;
        out->v0.w = 1.0f;
        out->v16.x = 0.0f;
        out->v16.y = 1.0f;
        out->v16.z = 0.0f;
        out->v16.w = 1.0f;
        return;
    }
    MgrQ* m;
    InfQ* inf;
    MgrQ** pp = o->p120;
    if (!pp) {
        m = D_00348804;
        out->v0 = func_00143e50(o->h96, 0);
        inf = func_00143ee8(o->h96, 0);
        { s32 fl = inf->h2; out->b52 = fl & 1; }
    } else {
        m = o->p120[1];
        out->v0 = func_001422a0(m, o->h96);
        inf = func_00142398(o->p120[1], o->h96);
        { s32 fl = inf->h2; out->b52 = fl & 1; }
    }
    EntQ* e = &m->tbl[o->h96];
    V4q hit;
    func_00141988(m, e, &hit);
    out->f40 = e->b0;
    negq(&out->v16, &out->v0);
}
}  // namespace n00143648

// ---- 00143860 from src/anon/batch_w78.cpp
namespace n00143860 {
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_0015cb78(void*, u32) asm("func_0015cb78");
void func_00141c18(void*, u32, u32, u32, u32) asm("func_00141c18");
s32 func_00141ff0(void*, void*, void*, void*, s32) asm("func_00141ff0");
struct W78VecC { f32 x,y,z,w; W78VecC(const W78VecC& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
void func_001539c0(void*, W78VecC) asm("func_001539c0");
extern u8* D_0034880c asm("D_0034880c");
struct W78Hit { u8 pad[12]; u8* tbl; };
void* func_00143860(void* self, W78VecC* v) asm("func_00143860");
void* func_00143860(void* self, W78VecC* v) {
    W78Vec a;
    s16 idx = -1;
    func_0015cb78(self, 0);
    if (D_0034880c) {
        func_00141c18(D_0034880c, 0, 0, 0, 0);
        if (func_00141ff0(D_0034880c, v, &a, &idx, 15) && (u16)idx != 0xffff)
            func_0015cb78(self, *(u8*)(((W78Hit*)D_0034880c)->tbl + ((u16)idx << 4)));
    }
    func_001539c0(self, *v);
    return self;
}
}  // namespace n00143860

// ---- 00143928 from src/anon/batch_w1828_nsa.cpp
namespace n00143928 {
struct V143 {
    f32 x, y, z, w;
    V143() {}
    V143& operator=(const V143& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V143 v143_sub(const V143& a, const V143& b) {
    V143 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct O143 {
    V143 v0;
    V143 v10;
    V143 v20;
    V143 v30;
    u8 pad40[0x22];
    s16 h62;
    s16 h64;
    s16 pad66;
    f32 f68;
    s32 pad6c;
    u64 flags;
    s32 i78;
};
extern s32 D_00348804 asm("D_00348804");
s32 func_00165a10() asm("func_00165a10");
s32 func_00164718(s32, O143*) asm("func_00164718");
s32 func_00165ad8(O143*, f32*) asm("func_00165ad8");
s32 func_001424c0(s32, O143*) asm("func_001424c0");
s32 func_00143928(O143* o) asm("func_00143928");
s32 func_00143928(O143* o) {
    o->h64 = -1;
    o->flags &= ~(1ULL << 34);
    f32 t = 10000000.0f;
    o->h62 = -1;
    s32 r = func_00165a10() | func_00164718(D_00348804, o);
    o->i78 = 0;
    if (func_00165ad8(o, &t) == 0) {
        if (func_001424c0(D_00348804, o)) o->i78 = 0;
    } else {
        o->v10 = v143_sub(o->v30, o->v0);
        r |= func_00164718(D_00348804, o);
    }
    if (t != 10000000.0f) {
        o->f68 = t;
        o->flags &= ~(1ULL << 33);
    }
    return r;
}
}  // namespace n00143928

// ---- 00143a48 from src/anon/batch_w46.cpp
namespace n00143a48 {
extern u32 D_00348804 asm("D_00348804");
void func_00141c18(u32, u32, u32, u32, u32) asm("func_00141c18");
void func_00141ff0(u32, u32, u32, void*, u32) asm("func_00141ff0");
void func_00143a48(u32 a, u32 b, u32 c) asm("func_00143a48");
void func_00143a48(u32 a, u32 b, u32 c) {
    u8 buf[16];
    func_00141c18(D_00348804, 15, 4, 1, 1);
    func_00141ff0(D_00348804, a, b, buf, c);
}
}  // namespace n00143a48

// ---- 00143ac0 from src/anon/tiny_auto80_queue.cpp
namespace n00143ac0 {
u32 func_00143ae0(...) asm("func_00143ae0");
u32 func_00143ac0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00143ac0jjjjjjjj");
u32 func_00143ac0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u64 scratch[2];
    return func_00143ae0(a0, a1, (u32)&scratch, a2, a4, a5, a6, a7);
}
}  // namespace n00143ac0

// ---- 00143ae0 from src/anon/batch_w56.cpp
namespace n00143ae0 {
struct NoTail { ~NoTail() {} };
extern void* D_00348804 asm("D_00348804");
void func_00141c18(void*, u32, u32, u32, u32) asm("func_00141c18");
void func_00141ff0(void*, u32, u32, u32, u32) asm("func_00141ff0");
void func_00143ae0(u32 a, u32 b, u32 c, u32 d) asm("func_00143ae0");
void func_00143ae0(u32 a, u32 b, u32 c, u32 d)
{
    NoTail g;
    func_00141c18(D_00348804, 0, 0, 0, 0);
    func_00141ff0(D_00348804, a, b, c, d);
}
}  // namespace n00143ae0

// ---- 00143b60 from src/anon/batch_w1.cpp
namespace n00143b60 {
void func_00143b88(u32, u32, u32*, u32*, u32) asm("func_00143b88");
void func_00143b60(u32 a0, u32 a1, u32 a2) asm("func_00143b60");
void func_00143b60(u32 a0, u32 a1, u32 a2) {
    u32 x;
    u32 y = 0;
    func_00143b88(a0, a1, &x, &y, a2);
}
}  // namespace n00143b60

// ---- 00143b88 from src/anon/batch_w90.cpp
namespace n00143b88 {
union Word { void* p; u32 w; u16 h; };
extern Word D_00348804 asm("D_00348804");
s32 func_00165db8(u32, u32, u16*, u32, u32, u32, u32*, u32, u32) asm("func_00165db8");
void func_00141c18(void*, u32, u32, u32, u32) asm("func_00141c18");
s32 func_00141ff0(void*, u32, u32, u16*, u32) asm("func_00141ff0");
s32 func_00143b88(u32 a0, u32 a1, u16* out, Word* flag, u32 a4) asm("func_00143b88");
s32 func_00143b88(u32 a0, u32 a1, u16* out, Word* flag, u32 a4)
{
    u16 id[2];
    flag->w = 0;
    s32 r = func_00165db8(a0, a1, &id[0], 0, 0, 0, &flag->w, a4, 0);
    *out = id[0];
    func_00141c18(D_00348804.p, 0, 0, 0, 0);
    if (func_00141ff0(D_00348804.p, a0, a1, &id[1], a4)) { flag->w = 0; r = 1; *out = id[1]; }
    return r;
}
}  // namespace n00143b88

// ---- 00143c68 from src/anon/batch_w67.cpp
namespace n00143c68 {
s32 func_00165db8(s32, s32, s32*, s32, s32, s32, s32*, s32, s32) asm("func_00165db8");
void func_00141c18(u32, s32, s32, s32, s32) asm("func_00141c18");
s32 func_00141ff0(u32, s32, s32, s32*, s32) asm("func_00141ff0");
extern u32 D_00348804 asm("D_00348804");
s32 func_00143c68(s32 a, s32 b) asm("func_00143c68");
s32 func_00143c68(s32 a, s32 b)
{
    s32 x, y;
    y = 0;
    s32 r = func_00165db8(a, b, &x, 512, 512, 0, &y, 15, 0);
    func_00141c18(D_00348804, 512, 512, 0, 0);
    r |= func_00141ff0(D_00348804, a, b, &x, 15);
    return r != 0;
}
}  // namespace n00143c68

// ---- 00143d10 from src/anon/batch_w1792_nsa.cpp
namespace n00143d10 {
extern s32 D_00348808 asm("D_00348808");
void func_00141c18(s32, s32, s32, s32, s32) asm("func_00141c18");
s32 func_00141ff0(s32, s32, s32, void*, s32) asm("func_00141ff0");
s32 func_00143d10(s32 a, s32 b, u16* out, s32* flag) asm("func_00143d10");
s32 func_00143d10(s32 a, s32 b, u16* out, s32* flag) {
    s32 ret = 0;
    *flag = 0;
    if (D_00348808 != 0) {
        u16 buf[8];
        func_00141c18(D_00348808, 0, 0, 0, 0);
        if (func_00141ff0(D_00348808, a, b, buf, 15) != 0) {
            *flag = 0;
            *out = buf[0];
            ret = 1;
        }
        return ret;
    }
    return 0;
}
}  // namespace n00143d10

// ---- 00143dd0 from src/anon/batch_w57.cpp
namespace n00143dd0 {
struct NoTail { ~NoTail() {} };
extern u32 D_00348804 asm("D_00348804");
void func_00141c18(u32, u32, u32, u32, u32) asm("func_00141c18");
u32 func_00141ff0(u32, u32, u32, u32, u32) asm("func_00141ff0");
void func_00143dd0(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_00143dd0");
void func_00143dd0(u32 a, u32 b, u32 c, u32 d, u32 e) {
    NoTail g;
    func_00141c18(D_00348804, 15, d, 0, 0);
    func_00141ff0(D_00348804, a, b, c, e);
}
}  // namespace n00143dd0

// ---- 00143e50 from src/anon/auto80_199_queue.cpp
namespace n00143e50 {
u32 func_00143e50(u32 a0, u32 a1, u32 a2) asm("_Z13func_00143e50jjj");
u32 func_00143e50(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a1 & 0xFFFF;
    u32 t7 = a2 & 0xFF;
    u32 a2v = t5;
    u32 s0 = a0;

    if (t7 != 0) {
        u32 t6 = D_00348808;
        if (t6 != 0) {
            func_001422a0(s0, t6, a2v);                           
            return s0;
        }
    }

    func_001422a0(s0, D_00348804, a2v);                           
    return s0;
}
}  // namespace n00143e50

// ---- 00143ea8 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n00143ea8 {
u32 func_00142208(u32, u32, u32, u32) asm("_Z13func_00142208jjjj");
extern u8 D_00350000 asm("D_00350000");
u32 func_00143ea8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143ea8jjjj");
u32 func_00143ea8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00142208(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30716u))), ((u32)(a0) & 0xffffu), a2, a3);
}
}  // namespace n00143ea8

// ---- 00143ec8 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n00143ec8 {
u32 func_00142278(u32, u32, u32, u32) asm("_Z13func_00142278jjjj");
extern u8 D_00350000 asm("D_00350000");
u32 func_00143ec8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143ec8jjjj");
u32 func_00143ec8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00142278(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30716u))), ((u32)(a0) & 0xffffu), a2, a3);
}
}  // namespace n00143ec8

// ---- 00143ee8 from src/anon/tiny_auto80_queue.cpp
namespace n00143ee8 {
extern u32 D_00348804 asm("D_00348804");
extern u32 D_00348808 asm("D_00348808");
u32* func_00142398(u32, u32) asm("_Z13func_00142398jj");
void func_00143ee8(u32 a0, u32 a1) asm("_Z13func_00143ee8jj");
void func_00143ee8(u32 a0, u32 a1) {
    u32 t5 = a0 & 0xFFFFu;
    if ((a1 & 0xFFu) != 0) {
        u32 p = D_00348808;
        if (p != 0) {
            func_00142398(p, t5);
            return;
        }
    }
    func_00142398(D_00348804, t5);
}
}  // namespace n00143ee8

// ---- 00143f28 from src/anon/tiny_jal_wrappers.cpp
namespace n00143f28 {
u32 func_00143ee8(u32, u32, u32, u32) asm("_Z13func_00143ee8jjjj");
u32 func_00143f28(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143f28jjjj");
u32 func_00143f28(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = (u32)(r4 & 0xffffu);
    r5 = (u32)(r5 & 0x00ffu);
    r2 = func_00143ee8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(0));
    r2 = (u32)(r2 & 0x000fu);
    return r2;
}
}  // namespace n00143f28

// ---- 00143f50 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n00143f50 {
u32 func_001423c0(u32, u32, u32, u32) asm("_Z13func_001423c0jjjj");
extern u8 D_00350000 asm("D_00350000");
u32 func_00143f50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00143f50jjjj");
u32 func_00143f50(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001423c0(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30716u))), ((u32)(a0) & 0xffffu), a1, a3);
}
}  // namespace n00143f50

// ---- 00143f78 from src/anon/tiny_auto80_queue.cpp
namespace n00143f78 {
extern u32 D_00348810 asm("D_00348810");
extern u8  D_0034881f asm("D_0034881f");
extern u32 D_00348820 asm("D_00348820");
extern u32 D_00348830 asm("D_00348830");
void func_00165f70(...) asm("func_00165f70");
void func_00143f78(u32 a0, u32 a1) asm("_Z13func_00143f78jj");
void func_00143f78(u32 a0, u32 a1) {
    D_00348820 = 0;
    u32 p = D_00348810;
    if (p == 0) {
        return;
    }
    if (D_0034881f == 0) {
        return;
    }
    func_00165f70(p, a1, (u32)&D_00348830, (u32)&D_00348820, a0);
}
}  // namespace n00143f78

// ---- 00143fc8 from src/anon/batch_w60.cpp
namespace n00143fc8 {
extern s32 D_00348820 asm("D_00348820");
extern u8 D_00348830[][80] asm("D_00348830");
s32 func_001466b0(void*) asm("func_001466b0");
s32 func_00146cb0(void*, void*) asm("func_00146cb0");
s32 func_00143fc8(void* a, void* b) asm("func_00143fc8");
s32 func_00143fc8(void* a, void* b) {
    s32 i;
    if (!func_001466b0(a)) return 1;
    for (i = 0; i < D_00348820; i++) {
        if (func_00146cb0(D_00348830[i], b)) return 1;
    }
    return 0;
}
}  // namespace n00143fc8

// ---- 00144060 from src/anon/batch_w48.cpp
namespace n00144060 {
u8* func_00106a60(s32) asm("func_00106a60");
void func_00107368(void*, void*) asm("func_00107368");
void func_00165f70(void*, void*, void*, void*, void*) asm("func_00165f70");
extern u8* D_00348800 asm("D_00348800");
extern u32 D_00348810 asm("D_00348810");
extern u8 D_0034881f asm("D_0034881f");
void func_00144060(void) asm("func_00144060");
void func_00144060(void) {
    u8 buf[16];
    *(u32*)(D_00348800 + 1904) = 0;
    if (D_00348810 != 0 && D_0034881f != 0) {
        func_00107368(func_00106a60(1), buf);                          
        u8* q = D_00348800;
        func_00165f70((void*)D_00348810, buf, q + 624, q + 1904, q + 496);
    }
}
}  // namespace n00144060

// ---- 001440e0 from src/anon/batch_w2389_nsa.cpp
namespace n001440e0 {
struct W2389Vec { f32 x, y, z, w; W2389Vec() {} W2389Vec(const W2389Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
struct W2389Mtx {
    W2389Vec r[4];
    W2389Vec operator*(const W2389Vec& v) const {
        W2389Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W2389Cam {
    u8 pad0[0x130];
    W2389Mtx m;
    u8 pad170[0x40];
    u8 m1b0[0x5c4];
    f32 f774;
    u8 pad778[0x4cc];
    s32 c44, c48, c4c;
};
extern u8 D_0034881c asm("D_0034881c");
extern W2389Cam* D_00348800 asm("D_00348800");
void* func_0016b0d0(void) asm("func_0016b0d0");
W2389Vec* func_0016c028(void*) asm("func_0016c028");
void func_002f47d8(void* d, void* m, void* v, u32 f) asm("func_002f47d8");
void func_001440e0(void) asm("func_001440e0");
void func_001440e0(void) {
    if (D_0034881c != 0) {
        void* o = func_0016b0d0();
        if (o != 0) {
            W2389Vec v(*func_0016c028(o));
            W2389Vec r = D_00348800->m * v;
            s32 a[4], b[4];
            D_00348800->f774 = r.z;
            func_002f47d8(a, D_00348800->m1b0, &v, 0);
            v.y -= 200.0f;
            func_002f47d8(b, D_00348800->m1b0, &v, 0);
            s32 t = (a[1] - b[1]) >> 4;
            D_00348800->c4c = (s32)((f32)t * 1.6f);
            t = D_00348800->c4c / 2;
            D_00348800->c44 = (a[0] >> 4) - t - 0x700;
            D_00348800->c48 = (b[0] >> 4) - t / 2 - 0x730;
        } else {
            D_00348800->f774 = 0;
        }
    }
}
}  // namespace n001440e0

// ---- 00144250: unwritten gap function (per-frame update of the object at 0x348800; the
// VU0 matrix multiply is the same asm statement as in the matched batch_w67.cpp copy)
namespace n00144250 {
extern u8* D_00348800 asm("D_00348800");
extern u8* D_00348818 asm("D_00348818");
extern u8 D_0034881d asm("D_0034881d");
extern u8 D_0034881e asm("D_0034881e");
void func_00145cb0(u8*) asm("func_00145cb0");
void func_00146de0(u8*) asm("func_00146de0");
void func_00144060(void) asm("func_00144060");
void func_001440e0(void) asm("func_001440e0");
void func_00146070(u8*, s16*) asm("func_00146070");
void func_00146078(u8*, u32) asm("func_00146078");
void func_00146498(u8*, u32, s32*) asm("func_00146498");
u8* func_00106a60(s32) asm("func_00106a60");
u8* func_00106a18(s32) asm("func_00106a18");
void func_0011cd80(u32, u8*, u8*, u8*, s16*, u32) asm("func_0011cd80");
void func_001473e8(u8*) asm("func_001473e8");
void func_00144250(void) asm("func_00144250");
void func_00144250(void) {
    s16 list[2048];
    u8 m[64] __attribute__((aligned(16)));
    s32 n;
    if (D_0034881e == 1) return;
    func_00145cb0(D_00348800);
    func_00146de0(D_00348800);
    func_00144060();
    func_001440e0();
    list[0] = -1;
    n = 0;
    func_00146070(D_00348800, list);
    func_00146078(D_00348800, *(u32*)D_00348818);
    func_00146498(D_00348800, 0, &n);
    list[n] = -1;
    if (D_0034881d == 0) {
        u8* o = D_00348818;
        u8* c = func_00106a60(1);
        u8* s = func_00106a18(1);
        u8* d = c + 16;
        asm volatile(".set noreorder\n\t"
            "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
            "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
            "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
            "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
            "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
            : : "r"(m), "r"(s), "r"(d) : "memory");
        func_0011cd80(*(u32*)o, m, o + 16, o + 80, list, 0);
    }
    func_001473e8(D_00348800);
}
}  // namespace n00144250

// ---- 001443c0 from src/anon/batch_w2363.cpp
namespace n001443c0 {
struct Slot2363 { u8 b[16]; ~Slot2363() {} } __attribute__((aligned(16)));
struct Entry50_2363 { Slot2363 s[5]; };
struct Table2363 { Entry50_2363 e[16]; };
extern Table2363 D_00348830 asm("D_00348830");
void wtarget_001443c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001443c0jjjj");
void wtarget_001443c0(u32 a0, u32 a1, u32 a2, u32 a3)
{
    if (a1 == 0xffff && a0 == 0) D_00348830.~Table2363();
}
}  // namespace n001443c0

// ---- 00144410 from src/anon/tiny_wrappers_more.cpp
namespace n00144410 {
u32 func_001443c0(u32, u32, u32, u32) asm("_Z13func_001443c0jjjj");
u32 func_00144410(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00144410jjjj");
u32 func_00144410(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001443c0(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00144410

// ---- 00144430: unwritten _GLOBAL__D_ stub of the static init at 0x1443c0
namespace n00144430 {
u32 func_001443c0(u32, u32, u32, u32) asm("_Z13func_001443c0jjjj");
u32 func_00144430(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00144430");
u32 func_00144430(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001443c0(0x00000000u, 0x0000ffffu, a2, a3);
}
}  // namespace n00144430

