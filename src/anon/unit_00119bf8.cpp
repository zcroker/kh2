#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fmatrix.hpp"

// ---- 00119bf8 gap: C2 copy of the ctor after it
namespace n00119bf8 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00347728 asm("D_00347728");
extern u8 D_003477a0 asm("D_003477a0");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
u32 func_00119bf8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00119bf8");
u32 func_00119bf8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00347728;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003477a0;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 2;
    return r2;
}
}  // namespace n00119bf8

// ---- 00119c40 from src/anon/tiny_auto80_solver.cpp
namespace n00119c40 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00347728 asm("D_00347728");
extern u8 D_003477a0 asm("D_003477a0");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
u32 func_00119c40(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00119c40jjjjjjjj");
u32 func_00119c40(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00347728;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003477a0;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 2;
    return r2;
}
}  // namespace n00119c40

// ---- 00119c88 from src/anon/batch_w7.cpp
namespace n00119c88 {
u32 func_001c8cd8(void) asm("func_001c8cd8");
void kn__Genie__changeForm(u32, u32) asm("kn__Genie__changeForm");
void func_00119c88(u32 a0) asm("func_00119c88");
void func_00119c88(u32 a0) {
    kn__Genie__changeForm(a0, func_001c8cd8());
}
}  // namespace n00119c88

// ---- 00119cb8 gap: D2 copy of the dtor after it
namespace n00119cb8 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003477a0 asm("D_003477a0");
u32 func_00119cb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00119cb8");
u32 func_00119cb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003477a0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00119cb8

// ---- 00119ce0 from src/anon/tiny_auto80_fptr4.cpp
namespace n00119ce0 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003477a0 asm("D_003477a0");
u32 func_00119ce0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00119ce0jjjj");
u32 func_00119ce0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003477a0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00119ce0

// ---- 00119d08 from src/anon/batch_w22.cpp
namespace n00119d08 {
extern u32 D_003477a0 asm("D_003477a0");
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
void func_00119d08(void** p) asm("func_00119d08");
void func_00119d08(void** p) {
    *p = &D_003477a0;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00119d08

// ---- 00119d40 gap: script callback (table 0x347728)
namespace n00119d40 {
void kn__Friend__followPlayer(u32) asm("kn__Friend__followPlayer");
u32 func_00119d40(u32* a0, u32 a1, u32* a2, u32* a3, u8 t0) asm("func_00119d40");
u32 func_00119d40(u32* a0, u32 a1, u32* a2, u32* a3, u8 t0) {
    if (!t0) kn__Friend__followPlayer(a0[1]);
    return 1;
}
}  // namespace n00119d40

// ---- 00119d70 from src/anon/batch_w249.cpp
namespace n00119d70 {
void func_00190128(u32*) asm("func_00190128");
void* func_00111e38(s32) asm("func_00111e38");
s32 func_0010f6b8(void*, f32) asm("func_0010f6b8");
u32 func_00190140(u32*) asm("func_00190140");
void func_00190878(u32*, void*, s32) asm("func_00190878");
void func_0010cbc8(u32, s32, void*, s32) asm("func_0010cbc8");
static inline __attribute__((always_inline)) u8 valid(u32* t) {
    u8 ok = 0;
    if (func_00190140(t)) ok = *t != 0;
    return ok;
}
u32 func_00119d70(u32* a0, u32 a1, u32* a2, u32* a3, u8 t0) asm("func_00119d70");
u32 func_00119d70(u32* a0, u32 a1, u32* a2, u32* a3, u8 t0) {
    if (t0) {
        *a3 = 0;
        func_00190128(a2);
        void* p = func_00111e38(0);
        if (func_0010f6b8(p, 0.25f)) {                            
            if (!valid(a2)) func_00190878(a2, p, 0);
        }
        if (valid(a2)) goto one;
        return 0;
    } else {
        func_0010cbc8(a0[1], 1, func_00111e38(0), 0);
        goto one;
    }
one:
    return 1;
}
}  // namespace n00119d70

// ---- 00119e60 from src/anon/batch_wcx.cpp
namespace n00119e60 {
struct E6 { s16 a, b, c; };
extern E6 D_00347770[6] asm("D_00347770");
void func_00194108(u32, s16) asm("func_00194108");
void func_001940f0(u32, s16) asm("func_001940f0");
void func_001c8cf8(s32) asm("func_001c8cf8");
void kn__Genie__changeForm(u8* p, s32 v) asm("kn__Genie__changeForm");
void kn__Genie__changeForm(u8* p, s32 v)
{
    *(s32*)(p + 20) = v;
    s32 i;
    for (i = 0; i < 6; i++) func_00194108(*(u32*)(p + 4), D_00347770[i].c);
    for (i = 0; i < 6; i++)
        if (*(s32*)(p + 20) == D_00347770[i].a) { func_001940f0(*(u32*)(p + 4), D_00347770[i].c); break; }
    func_001c8cf8(i + 1);
}
}  // namespace n00119e60

// ---- 00119f08 from src/anon/batch_w1670.cpp
namespace n00119f08 {
struct E6_347770 { s16 key; s16 val; s16 pad; };
extern E6_347770 D_00347770[6] asm("D_00347770");
s32 func_00119f08(u8* p) asm("func_00119f08");
s32 func_00119f08(u8* p) {
    E6_347770* e = D_00347770;
    do {
        if (*(s32*)(p + 0x14) == e->key) return e->val;
        e++;
    } while ((s32)e < (s32)(D_00347770 + 6));
    return 0;
}
}  // namespace n00119f08

