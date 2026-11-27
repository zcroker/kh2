// Linked unit 0x0031f2f8: linkonce (template) copies of game code that the linker gathered after the
// toolchain libraries. One namespace per old matched source.
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../global/misc.hpp"


// 0031f2f8 (gap; copy of 0x002cff98, was src/anon/unit_002cf260.cpp)
namespace n0031f2f8 {
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 0031f2f8*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_0031f2f8(u8* o) asm("func_0031f2f8");
/*TARGET 0031f2f8*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_0031f2f8(u8* o) asm("func_0031f2f8");
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_0031f2f8(u8* o) {
    *(u8**)o = D_0034ee08;
    YS__OBJ_ATTACK__clear(o + 2568);  // array8_free_slots
    func_001c0248(o + 2640);
    return func_00319fb0(o);  // big_obj_dtor
}
}  // namespace n0031f2f8

// 0031f340 (was src/anon/batch_w27.cpp)
namespace n0031f340 {
void func_00105110(void*) asm("func_00105110");
// 002ceaa8: moved to src/taito/minigame_base.cpp (linked unit)

extern u32 D_0034ee08 asm("D_0034ee08");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
/*TARGET 0031f340*/
void func_0031f340(u8* p) asm("func_0031f340");
void func_0031f340(u8* p) {
    *(void**)p = &D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}  // namespace n0031f340

// 0031f388 (was src/anon/auto80_199_queue.cpp)
namespace n0031f388 {
/*TARGET 0031f388*/
void func_0031f388(u32 self) asm("_Z13func_0031f388j");
void func_0031f388(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}
}  // namespace n0031f388

// 0031f408 (was src/anon/auto80_199_queue.cpp)
namespace n0031f408 {
/*TARGET 0031f408*/
void func_0031f408(u32 self) asm("_Z13func_0031f408j");
void func_0031f408(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}
}  // namespace n0031f408

// 0031f490 (gap; copy of 0x001b0188, was src/anon/unit_001ada38.cpp)
namespace n0031f490 {
u32 func_001ac5b8(u32, u32, u32, u32) asm("_Z13func_001ac5b8jjjj");
extern u8 D_00350bf0 asm("D_00350bf0");
u32 func_0031f490(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f490");
/*TARGET 0031f490*/
u32 func_0031f490(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f490");
u32 func_0031f490(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00350bf0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001ac5b8)(u32, u32, u32, u32) = func_001ac5b8;
    r2 = fp_call4_001ac5b8(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031f490

// 0031f4b8 (was src/anon/batch_w22.cpp)
namespace n0031f4b8 {
void func_00105110(void*) asm("func_00105110");
// 002f1130: moved to src/naka/libkn/trapfunctions.cpp

// --- 0031f4b8
extern u32 D_00350bf0 asm("D_00350bf0");
void func_001ac5b8(void*) asm("func_001ac5b8");
/*TARGET 0031f4b8*/
void func_0031f4b8(void** p) asm("func_0031f4b8");
void func_0031f4b8(void** p) {
    *p = &D_00350bf0;
    func_001ac5b8(p);
    func_00105110(p);
}
}  // namespace n0031f4b8

// 0031f4f0 (gap; copy of 0x0031e590, was src/anon/batch_wcx.cpp)
namespace n0031f4f0 {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
void func_00239870(u8*) asm("func_00239870");
void func_00239848(u8*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(u8*) asm("func_001ac5b8");
struct NoTail { ~NoTail() {} };
/*TARGET 0031f4f0*/
void func_0031f4f0(u8* p) asm("func_0031f4f0");
void func_0031f4f0(u8* p)
{
    NoTail g;
    *(void**)p = D_00350bb0;
    if (p != (u8*)-1544) {
        u8* q = p + 2920;
        u8* a = p + 1544;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
}
}  // namespace n0031f4f0

// 0031f590 (was src/anon/batch_w67.cpp)
namespace n0031f590 {
typedef void (*VFn)(void*);
void func_00239870(u8*) asm("func_00239870");
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
void func_00239848(u8*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(u8*) asm("func_001ac5b8");
void func_00105110(u8*) asm("func_00105110");
/*TARGET 0031f590*/
// 0031f590: destructor (four 344-byte members with virtual destructors)
void func_0031f590(u8* o) asm("func_0031f590");
// 0031f590: destructor (four 344-byte members with virtual destructors)
void func_0031f590(u8* o)
{
    *(u8**)o = D_00350bb0;
    if (o + 1544) {
        u8* p = o + 2920;
        for (;;) {
            if (o + 1544 == p) break;
            p -= 344;
            (**(VFn**)p)(p);
        }
    }
    func_00239870(o + 1200);
    func_00239870(o + 848);
    func_00239870(o + 484);
    *(u8**)(o + 132) = D_0034e8a8;
    func_00239848(o + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(o);
    func_00105110(o);
}
}  // namespace n0031f590

// 0031f638 (gap; copy of 0x0031e590, was src/anon/batch_wcx.cpp)
namespace n0031f638 {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
void func_00239870(u8*) asm("func_00239870");
void func_00239848(u8*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(u8*) asm("func_001ac5b8");
struct NoTail { ~NoTail() {} };
/*TARGET 0031f638*/
void func_0031f638(u8* p) asm("func_0031f638");
void func_0031f638(u8* p)
{
    NoTail g;
    *(void**)p = D_00350bb0;
    if (p != (u8*)-1544) {
        u8* q = p + 2920;
        u8* a = p + 1544;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
}
}  // namespace n0031f638

// 0031f6d8 (was src/anon/batch_w68.cpp)
namespace n0031f6d8 {
typedef void (*VF)(void*);
void func_00239870(void*) asm("func_00239870");
// 001b2578: moved to src/anon/unit_001b1d20.cpp

/* ---- 0031f6d8: destructor body ---- */
extern void* D_00350bb0 asm("D_00350bb0");
extern void* D_0034e8a8 asm("D_0034e8a8");
void func_00239848(void*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(void*) asm("func_001ac5b8");
void func_00105110(void*) asm("func_00105110");
/*TARGET 0031f6d8*/
void func_0031f6d8(u8* o) asm("func_0031f6d8");
void func_0031f6d8(u8* o) {
    *(u32*)o = (u32)&D_00350bb0;
    if (o + 1544) {
        u8* p = o + 2920;
        u8* end = o + 1544;
    loop:
        if (end == p) goto done;
        p -= 344;
        ((VF*)*(void**)p)[0](p);
        goto loop;
    }
done:
    func_00239870(o + 1200);
    func_00239870(o + 848);
    func_00239870(o + 484);
    *(void**)(o + 132) = &D_0034e8a8;
    func_00239848(o + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(o);
    func_00105110(o);
}
}  // namespace n0031f6d8

// 0031f780 (gap; copy of 0x0031e590, was src/anon/batch_wcx.cpp)
namespace n0031f780 {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
void func_00239870(u8*) asm("func_00239870");
void func_00239848(u8*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(u8*) asm("func_001ac5b8");
struct NoTail { ~NoTail() {} };
/*TARGET 0031f780*/
void func_0031f780(u8* p) asm("func_0031f780");
void func_0031f780(u8* p)
{
    NoTail g;
    *(void**)p = D_00350bb0;
    if (p != (u8*)-1544) {
        u8* q = p + 2920;
        u8* a = p + 1544;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
}
}  // namespace n0031f780

// 0031f820 (was src/anon/batch_wcx.cpp)
namespace n0031f820 {
typedef void (*VFn)(void*);
// 0031f820 / 0031c518: destructors (member arrays destroyed back to front)
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
void func_00239870(u8*) asm("func_00239870");
void func_00239848(u8*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(u8*) asm("func_001ac5b8");
void func_00105110(u8*) asm("func_00105110");
/*TARGET 0031f820*/
void func_0031f820(u8* p) asm("func_0031f820");
void func_0031f820(u8* p)
{
    *(void**)p = D_00350bb0;
    if (p != (u8*)-1544) {
        u8* q = p + 2920;
        u8* a = p + 1544;
    loop1544:
        if (a == q) goto done1544;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop1544;
    }
done1544:
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
    func_00105110(p);
}
}  // namespace n0031f820

// 0031f8c8 (gap)
namespace n0031f8c8 {
/*TARGET 0031f8c8*/
void func_0031f8c8(u8* p) asm("func_0031f8c8");
void func_0031f8c8(u8* p) { *(u32*)(p + 112) = 3; }
}  // namespace n0031f8c8

// 0031f8d8 (gap; copy of 0x00105a10, was src/common/unit_0031f8d8.cpp)
namespace n0031f8d8 {
/*TARGET 0031f8d8*/
void func_0031f8d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f8d8");
void func_0031f8d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031f8d8

// 0031f8e0 (gap; copy of 0x00105a10, was src/common/unit_0031f8e0.cpp)
namespace n0031f8e0 {
/*TARGET 0031f8e0*/
void func_0031f8e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f8e0");
void func_0031f8e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031f8e0

// 0031f8e8 (gap; copy of 0x00105a10, was src/common/unit_0031f8e8.cpp)
namespace n0031f8e8 {
/*TARGET 0031f8e8*/
void func_0031f8e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f8e8");
void func_0031f8e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031f8e8

// 0031f8f0 (gap; copy of 0x00105a10, was src/common/unit_0031f8f0.cpp)
namespace n0031f8f0 {
/*TARGET 0031f8f0*/
void func_0031f8f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f8f0");
void func_0031f8f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031f8f0

// 0031f8f8 (gap; copy of 0x00105a10, was src/common/unit_0031f8f8.cpp)
namespace n0031f8f8 {
/*TARGET 0031f8f8*/
void func_0031f8f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f8f8");
void func_0031f8f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031f8f8

// 0031f900 (gap; copy of 0x00105a10, was src/common/unit_0031f900.cpp)
namespace n0031f900 {
/*TARGET 0031f900*/
void func_0031f900(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f900");
void func_0031f900(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031f900

// 0031f908 (gap; copy of 0x00105a10, was src/common/unit_0031f908.cpp)
namespace n0031f908 {
/*TARGET 0031f908*/
void func_0031f908(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f908");
void func_0031f908(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031f908

// 0031f910 (was src/anon/tiny_auto80.cpp)
namespace n0031f910 {
/*TARGET 0031f910*/
void YS__WINDOW_OBJ2D__destroy(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z25YS__WINDOW_OBJ2D__destroyjjjj");
void YS__WINDOW_OBJ2D__destroy(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    if (r4 != 0u) {
        r15 = *(u32*)((u32)r4 + (s32)(0));
        r14 = *(u32*)((u32)r15 + (s32)(16));
        ((void(*)(u32,u32,u32,u32))(u32)r14)(r4, r5, r6, r7);
    }
}
}  // namespace n0031f910

// 0031f940 (was src/anon/batch_w11.cpp)
namespace n0031f940 {
// 0x001da278: definition moved into src/anon/unit_001d9d00.cpp

typedef void (*VFn)(void*);
/*TARGET 0031f940*/
void YS__WINDOW_OBJ2D__draw(u8* p) asm("YS__WINDOW_OBJ2D__draw");
void YS__WINDOW_OBJ2D__draw(u8* p) {
    void* o = *(void**)(p + 24);
    (*(VFn*)((*(u8**)o) + 16))(o);
}
}  // namespace n0031f940

// 0031f968 (was src/anon/auto80_199_queue.cpp)
namespace n0031f968 {
/*TARGET 0031f968*/
void func_0031f968(u32 self) asm("_Z13func_0031f968j");
void func_0031f968(u32 self) {
    *(u32*)self = addr_D_00350c30();
    u32 s16 = self;

    u32 p = *(u32*)(self + 24);
    if (p != 0) {
        Fn_0031f968 fn = (Fn_0031f968)*(u32*)(*(u32*)p + 8);
        fn(p);
    }

    *(u32*)s16 = addr_D_00347f98();
}
}  // namespace n0031f968

// 0031f9c0 (was src/anon/auto80_199_queue.cpp)
namespace n0031f9c0 {
/*TARGET 0031f9c0*/
void func_0031f9c0(u32 self) asm("_Z13func_0031f9c0j");
void func_0031f9c0(u32 self) {
    *(u32*)self = addr_D_00350c30();
    u32 s16 = self;

    u32 p = *(u32*)(self + 24);
    if (p != 0) {
        Fn_0031f9c0 fn = (Fn_0031f9c0)*(u32*)(*(u32*)p + 8);
        fn(p);
    }

    *(u32*)s16 = addr_D_00347f98();
    func_00105110(s16);
}
}  // namespace n0031f9c0

// 0031fa18 (was src/anon/batch_wcx.cpp)
namespace n0031fa18 {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
void func_00239870(u8*) asm("func_00239870");
void func_00239848(u8*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(u8*) asm("func_001ac5b8");
void func_00105110(u8*) asm("func_00105110");
/*TARGET 0031fa18*/
// same shape as 0031f820
void func_0031fa18(u8* p) asm("func_0031fa18");
// same shape as 0031f820
void func_0031fa18(u8* p)
{
    *(void**)p = D_00350bb0;
    if (p != (u8*)-1544) {
        u8* q = p + 2920;
        u8* a = p + 1544;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
    func_00105110(p);
}
}  // namespace n0031fa18

// 0031fac0 (gap; copy of 0x0031e590, was src/anon/batch_wcx.cpp)
namespace n0031fac0 {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
void func_00239870(u8*) asm("func_00239870");
void func_00239848(u8*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(u8*) asm("func_001ac5b8");
struct NoTail { ~NoTail() {} };
/*TARGET 0031fac0*/
void func_0031fac0(u8* p) asm("func_0031fac0");
void func_0031fac0(u8* p)
{
    NoTail g;
    *(void**)p = D_00350bb0;
    if (p != (u8*)-1544) {
        u8* q = p + 2920;
        u8* a = p + 1544;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
}
}  // namespace n0031fac0

// 0031fb60 (was src/anon/tiny_wrappers_more.cpp)
namespace n0031fb60 {
u32 func_001abd10(u32, u32, u32, u32) asm("_Z13func_001abd10jjjj");
/*TARGET 0031fb60*/
u32 YS__WINDOW_BASE__set_select(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z27YS__WINDOW_BASE__set_selectjjjj");
u32 YS__WINDOW_BASE__set_select(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001abd10(((u32)(a0) + 828u), a1, a2, a3);
}
}  // namespace n0031fb60

// 0031fb78 (was src/anon/tiny_wrappers_more.cpp)
namespace n0031fb78 {
u32 func_001ac078(u32, u32, u32, u32) asm("_Z13func_001ac078jjjj");
/*TARGET 0031fb78*/
u32 func_0031fb78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031fb78jjjj");
u32 func_0031fb78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ac078(((u32)(a0) + 1196u), a1, a2, a3);
}
}  // namespace n0031fb78

// 0031fb90 (was src/anon/batch_w83.cpp)
namespace n0031fb90 {
void func_00105110(void*) asm("func_00105110");
struct E344 { virtual void f0(); u8 pad[340]; };
void func_00239870(void*) asm("func_00239870");
extern u32 D_00350ab0[] asm("D_00350ab0");
extern u32 D_00350bb0[] asm("D_00350bb0");
extern u32 D_0034e8a8[] asm("D_0034e8a8");
void func_00239848(void*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(void*) asm("func_001ac5b8");
/*TARGET 0031fb90*/
// Deleting destructor.
void func_0031fb90(u8* p) asm("func_0031fb90");
// Deleting destructor.
void func_0031fb90(u8* p) {
    *(u32*)p = (u32)D_00350ab0;
    if (p + 3280) {
        E344* e = (E344*)(p + 4656);
        for (;;) {
            if ((E344*)(p + 3280) == e) break;
            --e;
            e->f0();
        }
    }
    func_00239870(p + 2936);
    *(u32*)p = (u32)D_00350bb0;
    if (p + 1544) {
        E344* e = (E344*)(p + 2920);
        for (;;) {
            if ((E344*)(p + 1544) == e) break;
            --e;
            e->f0();
        }
    }
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(u32*)(p + 132) = (u32)D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
    func_00105110(p);
}
}  // namespace n0031fb90

// 0031fc78 (was src/anon/batch_w84.cpp)
namespace n0031fc78 {
typedef void (*VFn)(void*);
struct NoTail { ~NoTail() {} };
// Destructor: virtual-destroy two 4-element member arrays, then members and base.
struct E344 { VFn* vt; u8 pad[340]; };
extern void* D_00350ab0[] asm("D_00350ab0");
extern void* D_00350bb0[] asm("D_00350bb0");
extern void* D_0034e8a8[] asm("D_0034e8a8");
void func_00239870(void*) asm("func_00239870");
void func_00239848(void*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(void*) asm("func_001ac5b8");
/*TARGET 0031fc78*/
void func_0031fc78(u8* p) asm("func_0031fc78");
void func_0031fc78(u8* p) {
    NoTail nt;
    *(void**)p = D_00350ab0;
    if (p + 3280 != 0) {
        E344* q = (E344*)(p + 4656);
        E344* b = (E344*)(p + 3280);
        while (1) {
            if (b == q) break;
            --q;
            q->vt[0](q);
        }
    }
    func_00239870(p + 2936);
    *(void**)p = D_00350bb0;
    if (p + 1544 != 0) {
        E344* q = (E344*)(p + 2920);
        E344* b = (E344*)(p + 1544);
        while (1) {
            if (b == q) break;
            --q;
            q->vt[0](q);
        }
    }
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
}
}  // namespace n0031fc78

// 0031fd60 (was src/anon/tiny_wrappers_more.cpp)
namespace n0031fd60 {
u32 func_001ac2a8(u32, u32, u32, u32) asm("_Z13func_001ac2a8jjjj");
/*TARGET 0031fd60*/
u32 func_0031fd60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031fd60jjjj");
u32 func_0031fd60(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ac2a8(((u32)(a0) + 2924u), a1, a2, a3);
}
}  // namespace n0031fd60

// 0031fd78 (was src/anon/batch_w23.cpp)
namespace n0031fd78 {
// 0x002fb900: definition moved into src/newlib/libm/sf_copysign.c

void YS__WINDOW_BASE__page_end(void*) asm("YS__WINDOW_BASE__page_end");
/*TARGET 0031fd78*/
void func_0031fd78(void* p) asm("func_0031fd78");
void func_0031fd78(void* p) {
    YS__WINDOW_BASE__page_end(p);
    (*(void (**)(void*))((*(u8**)p) + 32))(p);
}
}  // namespace n0031fd78

// 0031fdb0 (was src/anon/batch_w1671.cpp)
namespace n0031fdb0 {
// 00158f40: moved to src/harata/libdk/bookcamera.cpp

struct LNode_w1671 { u8 pad[0x7c]; LNode_w1671* next; };
struct LList_w1671 { LNode_w1671* head; LNode_w1671* tail; };
/*TARGET 0031fdb0*/
void func_0031fdb0(LList_w1671* l, LNode_w1671* after, LNode_w1671* n) asm("func_0031fdb0");
void func_0031fdb0(LList_w1671* l, LNode_w1671* after, LNode_w1671* n) {
    if (after == 0) {
        LNode_w1671* h = l->head;
        if (h == 0) { l->tail = n; l->head = n; n->next = 0; return; }
        n->next = h; l->head = n; return;
    }
    if (after == l->tail) { after->next = n; n->next = 0; l->tail = n; return; }
    n->next = after->next; after->next = n;
}
}  // namespace n0031fdb0

// 0031fe00 (was src/anon/auto200_999.cpp)
namespace n0031fe00 {
#define UNLINK_BODY(link_offset)                                               \
    u32 t7 = *(u32 *)a0;                                                       \
    u32 t5;                                                                    \
    if (a1 == t7) {                                                            \
        u32 t7n = *(u32 *)(a1 + (link_offset));                                \
        t5 = 0;                                                                \
        *(u32 *)a0 = t7n;                                                      \
    } else {                                                                   \
        u32 t6 = *(u32 *)(t7 + (link_offset));                                 \
        if (t6 != a1) {                                                        \
            do {                                                               \
                u32 t7x = *(u32 *)(t6 + (link_offset));                        \
                t5 = t6;                                                       \
                if (t7x == a1) {                                               \
                    break;                                                     \
                }                                                              \
                t6 = t7x;                                                      \
            } while (1);                                                       \
        } else {                                                               \
            t5 = t7;                                                           \
        }                                                                      \
        u32 t7n = *(u32 *)(a1 + (link_offset));                                \
        *(u32 *)(t5 + (link_offset)) = t7n;                                    \
    }                                                                          \
    u32 t7c = *(u32 *)(a0 + 4);                                                \
    if (a1 == t7c) {                                                           \
        *(u32 *)(a0 + 4) = t5;                                                 \
    }                                                                          \
    *(u32 *)(a1 + (link_offset)) = 0;
/*TARGET 0031fe00*/
// 0031f298: LIST<YS::MAGIC>::Remove, now made by gcc in src/yasui/libys/magiclist.cpp
void func_0031fe00(u32 a0, u32 a1) asm("_Z13func_0031fe00jj");
// 0031f298: LIST<YS::MAGIC>::Remove, now made by gcc in src/yasui/libys/magiclist.cpp
void func_0031fe00(u32 a0, u32 a1) { UNLINK_BODY(124) }
}  // namespace n0031fe00

// 0031fe60 (gap; copy of 0x003200f0, was src/anon/tiny_auto80_fptr4.cpp)
namespace n0031fe60 {
u32 func_0031fec0(u32, u32, u32, u32) asm("func_0031fec0");
extern u8 D_00351100 asm("D_00351100");
/*TARGET 0031fe60*/
u32 func_0031fe60(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031fe60");
u32 func_0031fe60(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00351100;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0031fec0)(u32, u32, u32, u32) = func_0031fec0;
    r2 = fp_call4_0031fec0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031fe60

// 0031fe88 (was src/anon/batch_w11.cpp)
namespace n0031fe88 {
void func_00105110(void*) asm("func_00105110");
extern u32 D_00351100 asm("D_00351100");
void func_0031fec0(void*) asm("func_0031fec0");
/*TARGET 0031fe88*/
void func_0031fe88(void** p) asm("func_0031fe88");
void func_0031fe88(void** p) {
    *p = &D_00351100;
    func_0031fec0(p);
    func_00105110(p);
}
}  // namespace n0031fe88

// 0031fec0 (was src/anon/auto80_199_queue.cpp)
namespace n0031fec0 {
/*TARGET 0031fec0*/
void func_0031fec0(u32 self) asm("_Z13func_0031fec0j");
void func_0031fec0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}
}  // namespace n0031fec0

// 0031ff60 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0031ff60 {
u32 func_0031ffc0(u32, u32, u32, u32) asm("_Z13func_0031ffc0jjjj");
extern u8 D_00352878 asm("D_00352878");
/*TARGET 0031ff60*/
u32 func_0031ff60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031ff60jjjj");
u32 func_0031ff60(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00352878;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0031ffc0)(u32, u32, u32, u32) = func_0031ffc0;
    r2 = fp_call4_0031ffc0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031ff60

// 0031ff88 (was src/anon/batch_w12.cpp)
namespace n0031ff88 {
void func_00105110(void*) asm("func_00105110");
void func_0031ffc0(void*) asm("func_0031ffc0");
extern u8 D_00352878 asm("D_00352878");
/*TARGET 0031ff88*/
// Deleting destructor: reset vtable, run base dtor, free.
void func_0031ff88(void** p) asm("func_0031ff88");
// Deleting destructor: reset vtable, run base dtor, free.
void func_0031ff88(void** p) {
    *p = &D_00352878;
    func_0031ffc0(p);
    func_00105110(p);
}
}  // namespace n0031ff88

// 0031ffc0 (was src/anon/auto80_199_queue.cpp)
namespace n0031ffc0 {
/*TARGET 0031ffc0*/
void func_0031ffc0(u32 self) asm("_Z13func_0031ffc0j");
void func_0031ffc0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}
}  // namespace n0031ffc0

// 00320050 (was src/anon/batch_w13.cpp)
namespace n00320050 {
// set_vtbl_347940
void func_00106420(void*) asm("func_00106420");
void func_001b0188(void*) asm("func_001b0188");
extern void (*D_0035e380[])(void) asm("D_0035e380");
extern u8 D_00350e60 asm("D_00350e60");
/*TARGET 00320050*/
void func_00320050(void** p) asm("func_00320050");
void func_00320050(void** p) {
    *p = &D_00350e60;
    func_001b0188(p);
    func_00106420(p);
}
}  // namespace n00320050

// 00320088 (gap; copy of 0x00320050, was src/anon/batch_w13.cpp)
namespace n00320088 {
// set_vtbl_347940
void func_00106420(void*) asm("func_00106420");
void func_001b0188(void*) asm("func_001b0188");
extern void (*D_0035e380[])(void) asm("D_0035e380");
extern u8 D_00350e48 asm("D_00350e48");
/*TARGET 00320088*/
void func_00320088(void** p) asm("func_00320088");
void func_00320088(void** p) {
    *p = &D_00350e48;
    func_001b0188(p);
    func_00106420(p);
}
}  // namespace n00320088

// 003200c0 (was src/anon/tiny_auto80_queue.cpp)
namespace n003200c0 {
/*TARGET 003200c0*/
void func_003200c0(u32* a0) asm("_Z13func_003200c0Pj");
void func_003200c0(u32* a0) {
    s32 t5 = 0;
    u32* t6 = (u32*)((u8*)a0 + 640);
    while (1) {
        *t6 = (u32)t5;
        t5 += 1;
        if (t5 >= 16) {
            break;
        }
        t6 += 1;
    }
    a0[704 / 4] = 16;
}
}  // namespace n003200c0

// 003200f0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n003200f0 {
u32 func_0031fec0(u32, u32, u32, u32) asm("_Z13func_0031fec0jjjj");
extern u8 D_00351100 asm("D_00351100");
/*TARGET 003200f0*/
u32 func_003200f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_003200f0jjjj");
u32 func_003200f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00351100;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0031fec0)(u32, u32, u32, u32) = func_0031fec0;
    r2 = fp_call4_0031fec0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n003200f0

// 00320118 (was src/anon/batch_w14.cpp)
namespace n00320118 {
void func_00105110(void*) asm("func_00105110");
void func_0031fec0(void*) asm("func_0031fec0");
extern u8 D_00351100[] asm("D_00351100");
/*TARGET 00320118*/
void func_00320118(u8* p) asm("func_00320118");
void func_00320118(u8* p) {
    *(u8**)p = D_00351100;
    func_0031fec0(p);
    func_00105110(p);
}
}  // namespace n00320118

// 00320150 (gap; copy of 0x002cff98, was src/anon/unit_002cf260.cpp)
namespace n00320150 {
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 00320150*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00320150(u8* o) asm("func_00320150");
/*TARGET 00320150*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00320150(u8* o) asm("func_00320150");
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00320150(u8* o) {
    *(u8**)o = D_0034ee08;
    YS__OBJ_ATTACK__clear(o + 2568);  // array8_free_slots
    func_001c0248(o + 2640);
    return func_00319fb0(o);  // big_obj_dtor
}
}  // namespace n00320150

// 00320198 (was src/anon/batch_w28.cpp)
namespace n00320198 {
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
// big_obj_dtor
void func_00105110(void*) asm("func_00105110");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 00320198*/
void func_00320198(u8* p) asm("func_00320198");
void func_00320198(u8* p) {
    *(void**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 0xa08);  // array8_free_slots
    func_001c0248(p + 0xa50);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}  // namespace n00320198

// 003201e0 (gap; copy of 0x00105a10, was src/common/unit_003201e0.cpp)
namespace n003201e0 {
/*TARGET 003201e0*/
void func_003201e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003201e0");
void func_003201e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n003201e0

// 003201e8 (was src/anon/auto200_999.cpp)
namespace n003201e8 {
#define UNLINK_BODY(link_offset)                                               \
    u32 t7 = *(u32 *)a0;                                                       \
    u32 t5;                                                                    \
    if (a1 == t7) {                                                            \
        u32 t7n = *(u32 *)(a1 + (link_offset));                                \
        t5 = 0;                                                                \
        *(u32 *)a0 = t7n;                                                      \
    } else {                                                                   \
        u32 t6 = *(u32 *)(t7 + (link_offset));                                 \
        if (t6 != a1) {                                                        \
            do {                                                               \
                u32 t7x = *(u32 *)(t6 + (link_offset));                        \
                t5 = t6;                                                       \
                if (t7x == a1) {                                               \
                    break;                                                     \
                }                                                              \
                t6 = t7x;                                                      \
            } while (1);                                                       \
        } else {                                                               \
            t5 = t7;                                                           \
        }                                                                      \
        u32 t7n = *(u32 *)(a1 + (link_offset));                                \
        *(u32 *)(t5 + (link_offset)) = t7n;                                    \
    }                                                                          \
    u32 t7c = *(u32 *)(a0 + 4);                                                \
    if (a1 == t7c) {                                                           \
        *(u32 *)(a0 + 4) = t5;                                                 \
    }                                                                          \
    *(u32 *)(a1 + (link_offset)) = 0;
/*TARGET 003201e8*/
void func_003201e8(u32 a0, u32 a1) asm("_Z13func_003201e8jj");
void func_003201e8(u32 a0, u32 a1) { UNLINK_BODY(24) }
}  // namespace n003201e8

// 00320248 (gap; copy of 0x002cff98, was src/anon/unit_002cf260.cpp)
namespace n00320248 {
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 00320248*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00320248(u8* o) asm("func_00320248");
/*TARGET 00320248*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00320248(u8* o) asm("func_00320248");
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00320248(u8* o) {
    *(u8**)o = D_0034ee08;
    YS__OBJ_ATTACK__clear(o + 2568);  // array8_free_slots
    func_001c0248(o + 2640);
    return func_00319fb0(o);  // big_obj_dtor
}
}  // namespace n00320248

// 00320290 (was src/anon/batch_w29.cpp)
namespace n00320290 {
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
// big_obj_dtor
void func_00105110(void*) asm("func_00105110");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 00320290*/
// 0x00314190: definition moved into src/libgcc/_div_df.c

void func_00320290(u8* p) asm("func_00320290");
// 0x00314190: definition moved into src/libgcc/_div_df.c

void func_00320290(u8* p) {
    *(void**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}  // namespace n00320290

// 003202d8 (was src/anon/auto80_199_queue.cpp)
namespace n003202d8 {
/*TARGET 003202d8*/
void func_003202d8(u32 self) asm("_Z13func_003202d8j");
void func_003202d8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}
}  // namespace n003202d8

// 00320368 (was src/anon/auto80_199_queue.cpp)
namespace n00320368 {
/*TARGET 00320368*/
void func_00320368(u32 self) asm("_Z13func_00320368j");
void func_00320368(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}
}  // namespace n00320368

// 00320400 (was src/anon/tiny.cpp)
namespace n00320400 {
/*TARGET 00320400*/
void func_00320400(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00320400jjjj");
void func_00320400(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = 0;
}
}  // namespace n00320400

// 00320408 (gap)
namespace n00320408 {
/*TARGET 00320408*/
u32 func_00320408(u32 a, u16* b) asm("func_00320408");
u32 func_00320408(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n00320408

// 00320418 (was src/anon/tiny_auto80_queue.cpp)
namespace n00320418 {
/*TARGET 00320418*/
void func_00320418(u32* a0) asm("_Z13func_00320418Pj");
void func_00320418(u32* a0) {
    s32 t5 = 0;
    u32* t6 = (u32*)((u8*)a0 + 160);
    while (1) {
        *t6 = (u32)t5;
        t5 += 1;
        if (t5 >= 8) {
            break;
        }
        t6 += 1;
    }
    a0[192 / 4] = 8;
}
}  // namespace n00320418

// 00320448 (gap)
namespace n00320448 {
/*TARGET 00320448*/
u32 func_00320448(u32 a, u8* b) asm("func_00320448");
u32 func_00320448(u32 a, u8* b) { a -= *b; return a; }
}  // namespace n00320448

// 00320458 (gap)
namespace n00320458 {
/*TARGET 00320458*/
u32 func_00320458(u32 a, u16* b) asm("func_00320458");
u32 func_00320458(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n00320458

// 00320468 (was src/anon/auto200_999.cpp)
namespace n00320468 {
#define UNLINK_BODY(link_offset)                                               \
    u32 t7 = *(u32 *)a0;                                                       \
    u32 t5;                                                                    \
    if (a1 == t7) {                                                            \
        u32 t7n = *(u32 *)(a1 + (link_offset));                                \
        t5 = 0;                                                                \
        *(u32 *)a0 = t7n;                                                      \
    } else {                                                                   \
        u32 t6 = *(u32 *)(t7 + (link_offset));                                 \
        if (t6 != a1) {                                                        \
            do {                                                               \
                u32 t7x = *(u32 *)(t6 + (link_offset));                        \
                t5 = t6;                                                       \
                if (t7x == a1) {                                               \
                    break;                                                     \
                }                                                              \
                t6 = t7x;                                                      \
            } while (1);                                                       \
        } else {                                                               \
            t5 = t7;                                                           \
        }                                                                      \
        u32 t7n = *(u32 *)(a1 + (link_offset));                                \
        *(u32 *)(t5 + (link_offset)) = t7n;                                    \
    }                                                                          \
    u32 t7c = *(u32 *)(a0 + 4);                                                \
    if (a1 == t7c) {                                                           \
        *(u32 *)(a0 + 4) = t5;                                                 \
    }                                                                          \
    *(u32 *)(a1 + (link_offset)) = 0;
/*TARGET 00320468*/
void func_00320468(u32 a0, u32 a1) asm("_Z13func_00320468jj");
void func_00320468(u32 a0, u32 a1) { UNLINK_BODY(2232) }
}  // namespace n00320468
