// Linked unit 0x00241f98-0x002422b8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
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
#include "../tozawa/munny.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/config.hpp"
#include "../tozawa/sub_menu.hpp"
#include "../tozawa/smenu_he.hpp"
#include "../tozawa/smenu_heco.hpp"

// 00241f98 (was unwritten gap: C2 twin of 0x241fd0)
namespace n00241f98 {
struct W1587_S { u32 a; u8* b; };
void func_00242088(void*) asm("func_00242088");
u8* func_001063f0_n(u32) asm("func_001063f0");
void func_00241f98(W1587_S* p, u32 a1) asm("func_00241f98");
void func_00241f98(W1587_S* p, u32 a1) {
    W1587_S* s;
    asm("" : "=r"(s) : "0"(p));  /* keeps p in its own pseudo, as the original stores via s0 */
    s->a = a1;
    s->b = func_001063f0_n(0x400);
    func_00242088(s);
}
}  // namespace n00241f98

// 00241fd0 (was src/anon/batch_w1587.cpp)
namespace n00241fd0 {
// 0x0027c4d8: definition moved into src/anon/unit_0027a6d8.cpp

struct W1587_S { u32 a; u8* b; };
void func_00242088(void*) asm("func_00242088");
u8* func_001063f0_n(u32) asm("func_001063f0");
/*TARGET 00241fd0*/
void func_00241fd0(W1587_S* p, u32 a1) asm("func_00241fd0");
void func_00241fd0(W1587_S* p, u32 a1) {
    W1587_S* s;
    asm("" : "=r"(s) : "0"(p));  /* keeps p in its own pseudo, as the original stores via s0 */
    s->a = a1;
    s->b = func_001063f0_n(0x400);
    func_00242088(s);
}
}  // namespace n00241fd0

// 00242008 (was unwritten gap: twin of 0x242048)
namespace n00242008 {
void func_00106450(void*) asm("func_00106450");
struct Q { u32 a; void* p; };
void func_00242008(Q* q) asm("func_00242008");
void func_00242008(Q* q) {
    void* p = q->p;
    if (p) {
        func_00106450(p);
        q->p = 0;
    }
    q->a = 0;
}
}  // namespace n00242008

// 00242048 (was src/anon/tiny_auto80_queue.cpp)
namespace n00242048 {
u32 func_00106450(...) asm("func_00106450");
/*TARGET 00242048*/
void func_00242048(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00242048jjjjjjjj");
void func_00242048(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(4));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00106450)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u32*)((u32)r16 + (s32)(4)) = 0u;
    }
    *(u32*)((u32)r16 + (s32)(0)) = 0u;
}
}  // namespace n00242048

// 00242088 (was src/anon/batch_w30.cpp)
namespace n00242088 {
u32 func_001064a8(s32) asm("func_001064a8");
/*TARGET 00242088*/
// 0022af48: moved to src/sasa/musical_input.cpp (linked unit)

void func_00242088(u8* p) asm("func_00242088");
// 0022af48: moved to src/sasa/musical_input.cpp (linked unit)

void func_00242088(u8* p) {
    u32* d = *(u32**)(p + 4);
    s32 i;
    for (i = 255; i >= 0; i--) {
        *d++ = func_001064a8(-1);
    }
}
}  // namespace n00242088

// 002420d0 (was src/anon/misc_2.cpp)
namespace n002420d0 {
/*TARGET 002420d0*/
s32 func_002420d0(void* self) asm("_Z13func_002420d0Pv");
s32 func_002420d0(void* self) { return (s32)(*(s32*)((char*)self + 4)); }
}  // namespace n002420d0

// 002420d8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002420d8 {
extern u32 D_0035ecb8 asm("D_0035ecb8");
/*TARGET 002420d8*/
void func_002420d8(u32 a0, u32 a1) asm("_Z13func_002420d8jj");
void func_002420d8(u32 a0, u32 a1) {
    (void)a0;
    a1 &= 0xFF;
    if (a1 != 0) {
        u32 t7 = D_0035ecb8;
        t7 |= 1;
        D_0035ecb8 = t7;
        return;
    }
    u32 t6 = D_0035ecb8;
    t6 &= (u32)-2;
    D_0035ecb8 = t6;
}
}  // namespace n002420d8

// 00242110 (was src/anon/auto80_199_queue.cpp)
namespace n00242110 {
/*TARGET 00242110*/
void func_00242110(u32 a0) asm("_Z13func_00242110j");
void func_00242110(u32 a0) {
    u32 s18 = func_002421e8(a0);
    u32 s17 = *(u32*)(a0 + 4);
    func_002efb60(s17);
    func_00242258(a0);
    if (s18 != 0) {
        func_002efa88(s17);
    }
}
}  // namespace n00242110

// 00242180 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00242180 {
u32 func_002ef9e0(u32, u32, u32, u32) asm("_Z13func_002ef9e0jjjj");
/*TARGET 00242180*/
u32 Tz__McSys__isEnableDataKH2(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z26Tz__McSys__isEnableDataKH2jjjj");
u32 Tz__McSys__isEnableDataKH2(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = *(u32*)((u32)r4 + (s32)(4));
    u32 (*fp_call4_002ef9e0)(u32, u32, u32, u32) = func_002ef9e0;
    r2 = fp_call4_002ef9e0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00242180

// 002421a0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002421a0 {
u32 func_002efc10(u32, u32, u32, u32) asm("_Z13func_002efc10jjjj");
/*TARGET 002421a0*/
u32 func_002421a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002421a0jjjj");
u32 func_002421a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = *(u32*)((u32)r4 + (s32)(4));
    u32 (*fp_call4_002efc10)(u32, u32, u32, u32) = func_002efc10;
    r2 = fp_call4_002efc10(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002421a0

// 002421c0 (was src/anon/batch_w17.cpp)
namespace n002421c0 {
void func_00242088(void*) asm("func_00242088");
void func_002ef938(u32) asm("func_002ef938");
/*TARGET 002421c0*/
void func_002421c0(u8* p) asm("func_002421c0");
void func_002421c0(u8* p) {
    u32 s = *(u32*)(p + 4);
    func_00242088(p);
    func_002ef938(s);
}
}  // namespace n002421c0

// 002421e8 (was src/anon/batch_w65.cpp)
namespace n002421e8 {
u32 func_002efa40(u32) asm("func_002efa40");
extern volatile u32 D_0035ecb8 asm("D_0035ecb8");
/*TARGET 002421e8*/
s32 func_002421e8(u8* p) asm("func_002421e8");
s32 func_002421e8(u8* p) {
    s32 r = 0;
    if (func_002efa40(*(u32*)(p + 4)) || (u8)(D_0035ecb8 & 1)) r = 1;
    return r;
}
}  // namespace n002421e8

// 00242238 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00242238 {
u32 func_002efc70(u32, u32, u32, u32) asm("_Z13func_002efc70jjjj");
/*TARGET 00242238*/
u32 func_00242238(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00242238jjjj");
u32 func_00242238(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = *(u32*)((u32)r4 + (s32)(4));
    u32 (*fp_call4_002efc70)(u32, u32, u32, u32) = func_002efc70;
    r2 = fp_call4_002efc70(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00242238

// 00242258 (was src/anon/tiny_auto80_queue.cpp)
namespace n00242258 {
u32 func_001064a8(...) asm("func_001064a8");
/*TARGET 00242258*/
void func_00242258(u32 a0) asm("_Z13func_00242258j");
void func_00242258(u32 a0) {
    s32 s1 = 98;
    u32 t7 = *(u32*)(a0 + 4);
    u32 s0 = t7 + 628;
    do {
        *(u32*)s0 = func_001064a8((u32)-1);
        s1 -= 1;
        s0 += 4;
    } while (s1 >= 0);
}
}  // namespace n00242258

// 002422a0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002422a0 {
u32 func_002efb88(u32, u32, u32, u32) asm("_Z13func_002efb88jjjj");
/*TARGET 002422a0*/
u32 func_002422a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002422a0jjjj");
u32 func_002422a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002efb88(((u32)(*(u32*)((u32)(a0) + 4u))), a1, a2, a3);
}
}  // namespace n002422a0

