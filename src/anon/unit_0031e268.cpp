// Linked unit 0x0031e268: linkonce (template) copies of game code that the linker gathered after the
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


// 0031e268 (was src/anon/batch_w211.cpp)
namespace n0031e268 {
struct W211H { u8 c0, c1, c2, c3; f32 f; u32 z; u32 nx; };
/*TARGET 0031e268*/
// 0x0028b160: definition moved into src/anon/unit_00288b00.cpp

void func_0031e268(W211H* h) asm("func_0031e268");
// 0x0028b160: definition moved into src/anon/unit_00288b00.cpp

void func_0031e268(W211H* h) {
    h = (W211H*)((u8*)h + 4);
    s32 i = 7;
    do {
        *(u32*)((u8*)h - 4) = 0;
        u32 k = 128; h->c0 = k; h->c1 = k; h->c2 = k; h->c3 = k;
        h->f = 1.0f; h->z = 0; h++; i--;
    } while (i != -1);
}
}  // namespace n0031e268

// 0031e2b8 (was src/anon/misc_3.cpp)
namespace n0031e2b8 {
/*TARGET 0031e2b8*/
void func_0031e2b8(void* self) asm("_Z13func_0031e2b8Pv");
void func_0031e2b8(void* self) { *(s32*)((char*)self + 0) = 0; }
}  // namespace n0031e2b8

// 0031e2c0 (was src/anon/misc_3.cpp)
namespace n0031e2c0 {
/*TARGET 0031e2c0*/
void func_0031e2c0(void* self) asm("_Z13func_0031e2c0Pv");
void func_0031e2c0(void* self) { *(s32*)((char*)self + 0) = 0; }
}  // namespace n0031e2c0

// 0031e2c8 (was src/anon/auto200_999.cpp)
namespace n0031e2c8 {
/*TARGET 0031e2c8*/
// 0x002bcf58: definition moved into src/anon/unit_002bc978.cpp

void func_0031e2c8(u32 a0, u32 a1) asm("_Z13func_0031e2c8jj");
// 0x002bcf58: definition moved into src/anon/unit_002bc978.cpp

void func_0031e2c8(u32 a0, u32 a1) {
    u32 t7 = *(u32 *)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32 *)(a1 + 40);
        t5 = 0;
        *(u32 *)a0 = t7n;
    } else {
        u32 t6 = *(u32 *)(t7 + 40);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32 *)(t6 + 40);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32 *)(a1 + 40);
        *(u32 *)(t5 + 40) = t7n;
    }

    u32 t7c = *(u32 *)(a0 + 4);
    if (a1 == t7c) {
        *(u32 *)(a0 + 4) = t5;
    }
    *(u32 *)(a1 + 40) = 0;
}
}  // namespace n0031e2c8

// 0031e328 (was src/anon/auto200_999.cpp)
namespace n0031e328 {
/*TARGET 0031e328*/
void func_0031e328(u32 a0, u32 a1) asm("_Z13func_0031e328jj");
void func_0031e328(u32 a0, u32 a1) {
    u32 t7 = *(u32 *)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32 *)(a1 + 60);
        t5 = 0;
        *(u32 *)a0 = t7n;
    } else {
        u32 t6 = *(u32 *)(t7 + 60);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32 *)(t6 + 60);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32 *)(a1 + 60);
        *(u32 *)(t5 + 60) = t7n;
    }

    u32 t7c = *(u32 *)(a0 + 4);
    if (a1 == t7c) {
        *(u32 *)(a0 + 4) = t5;
    }
    *(u32 *)(a1 + 60) = 0;
}
}  // namespace n0031e328

// 0031e388 (gap)
namespace n0031e388 {
typedef unsigned int u128_ __attribute__((mode(TI)));
/*TARGET 0031e388*/
void func_0031e388(void) asm("func_0031e388");
void func_0031e388(void) { u128_ a[2]; (void)a; }
}  // namespace n0031e388

// 0031e398 (was src/anon/batch_w87.cpp)
namespace n0031e398 {
// 0x0024e9c0: definition moved into src/anon/unit_0024e7e8.cpp

// ---- 0x2816f0: reset state and release three owned objects ----
typedef void (*VFn)(void*);
void func_00105110(void*) asm("func_00105110");
extern u8 D_00350ab0[] asm("D_00350ab0");
void func_00239870(void*) asm("func_00239870");
// ---- 0x31e398: deleting destructor ----
extern u8 D_0034e888[] asm("D_0034e888");
extern u8 D_00363828[] asm("D_00363828");
extern u8 D_003637e0[] asm("D_003637e0");
void func_0031e590(void*) asm("func_0031e590");
void func_002ee380(void*) asm("func_002ee380");
/*TARGET 0031e398*/
void func_0031e398(u8* p) asm("func_0031e398");
void func_0031e398(u8* p) {
    void** q36 = (void**)(p + 36);
    u8* o = p + 80;
    *(void**)p = D_0034e888;
    *q36 = D_00363828;
    *(void**)o = D_00350ab0;
    if (o + 3280) {
        u8* e = o + 4656;
        u8* b = o + 3280;
        for (;;) {
            if (b == e) break;
            e -= 344;
            (**(VFn**)e)(e);
        }
    }
    func_00239870(o + 2936);
    func_0031e590(o);
    *q36 = D_003637e0;
    func_002ee380(p);
    func_00105110(p);
}
}  // namespace n0031e398

// 0031e460 (gap)
namespace n0031e460 {
typedef void (*VFn)(void*);
extern u8 D_00350ab0[] asm("D_00350ab0");
void func_00239870(void*) asm("func_00239870");
extern u8 D_0034e888[] asm("D_0034e888");
extern u8 D_00363828[] asm("D_00363828");
extern u8 D_003637e0[] asm("D_003637e0");
void func_0031e590(void*) asm("func_0031e590");
void func_002ee380(void*) asm("func_002ee380");
/*TARGET 0031e460*/
// Destructor (0x31e398 is the deleting one).
void func_0031e460(u8* p) asm("func_0031e460");
void func_0031e460(u8* p) {
    void** q36 = (void**)(p + 36);
    u8* o = p + 80;
    *(void**)p = D_0034e888;
    *q36 = D_00363828;
    *(void**)o = D_00350ab0;
    if (o + 3280) {
        u8* e = o + 4656;
        u8* b = o + 3280;
        for (;;) {
            if (b == e) break;
            e -= 344;
            (**(VFn**)e)(e);
        }
    }
    func_00239870(o + 2936);
    func_0031e590(o);
    *q36 = D_003637e0;
    func_002ee380(p);
    u32 t = (u32)p;
    (void)t;
}
}  // namespace n0031e460

// 0031e520 (was src/anon/batch_w46.cpp)
namespace n0031e520 {
struct VObj { void (**vt)(VObj*); };
// 002eecd0: moved to src/anon/unit_002ee8a8.cpp

// ---- 0031e520
s32 func_002ee6d8(u8*) asm("func_002ee6d8");
void func_002edfd8(VObj*, u8*) asm("func_002edfd8");
/*TARGET 0031e520*/
// list_unlink_and_clear
s32 func_0031e520(VObj* p) asm("func_0031e520");
// list_unlink_and_clear
s32 func_0031e520(VObj* p) {
    if (func_002ee6d8((u8*)p + 36)) {
        func_002edfd8(p, (u8*)p + 36);  // list_unlink_and_clear
        if (p) p->vt[1](p);
        return 0;
    }
    return 1;
}
}  // namespace n0031e520

// 0031e590 (was src/anon/batch_wcx.cpp)
namespace n0031e590 {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[] asm("D_00350bb0");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
void func_00239870(u8*) asm("func_00239870");
void func_00239848(u8*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_001ac5b8(u8*) asm("func_001ac5b8");
struct NoTail { ~NoTail() {} };
/*TARGET 0031e590*/
void func_0031e590(u8* p) asm("func_0031e590");
void func_0031e590(u8* p)
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
}  // namespace n0031e590

// 0031e630 (was src/anon/batch_w19.cpp)
namespace n0031e630 {
void func_00239848(void*) asm("func_00239848");
// set_vtbl_36eb28_then_call
void func_00106420(void*) asm("func_00106420");
extern u8 D_0034e8a8[] asm("D_0034e8a8");
/*TARGET 0031e630*/
// 0x002d5dd0: definition moved into src/anon/unit_002d4548.cpp

// 002e7738: moved to src/anon/unit_002e7658.cpp

// Returns the callee's result when p[2] == 8 (result undefined otherwise, as in the original).
// 002ef1b8: moved to src/anon/unit_002ee8a8.cpp

// 002f09d8: moved to src/naka/libkn/trapfunctions.cpp

void func_0031e630(void** p) asm("func_0031e630");
// 0x002d5dd0: definition moved into src/anon/unit_002d4548.cpp

// 002e7738: moved to src/anon/unit_002e7658.cpp

// Returns the callee's result when p[2] == 8 (result undefined otherwise, as in the original).
// 002ef1b8: moved to src/anon/unit_002ee8a8.cpp

// 002f09d8: moved to src/naka/libkn/trapfunctions.cpp

void func_0031e630(void** p) {
    *p = D_0034e8a8;
    func_00239848(p);  // set_vtbl_36eb28_then_call
    func_00106420(p);
}
}  // namespace n0031e630

// 0031e668 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0031e668 {
extern u8 D_0034e8a8 asm("D_0034e8a8");
// 0x002369f0: definition moved into src/anon/unit_00236180.cpp

u32 func_00239848(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00239848jjjj");
/*TARGET 0031e668*/
u32 func_0031e668(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031e668jjjj");
u32 func_0031e668(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0034e8a8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00239848)(u32, u32, u32, u32) = func_00239848;
    r2 = fp_call4_00239848(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031e668

// 0031e690 (was src/anon/auto200_999.cpp)
namespace n0031e690 {
void func_001b0188(u32) asm("_Z13func_001b0188j");
void func_001c0248(u32) asm("_Z13func_001c0248j");
void func_001d5718(u32) asm("_Z13func_001d5718j");
void func_0016a358(u32) asm("_Z13func_0016a358j");
void func_0019f9a8(u32) asm("_Z13func_0019f9a8j");
void func_0031e7f8(u32) asm("_Z13func_0031e7f8j");
extern u32 D_0034e8b8 asm("D_0034e8b8");
extern u32 D_0034ee08 asm("D_0034ee08");
extern u32 D_003503e0 asm("D_003503e0");
extern u32 D_00350e60 asm("D_00350e60");
static inline u32 addr_D_0034e8b8() { return (u32)&D_0034e8b8; }
static inline u32 addr_D_0034ee08() { return (u32)&D_0034ee08; }
static inline u32 addr_D_003503e0() { return (u32)&D_003503e0; }
static inline u32 addr_D_00350e60() { return (u32)&D_00350e60; }
/*TARGET 0031e690*/
void func_0031e690(u32 self) asm("_Z13func_0031e690j");
void func_0031e690(u32 self) {
    u32 c0 = addr_D_0034e8b8();
    u32 c2824 = addr_D_00350e60();
    *(u32 *)(self + 2824) = c2824;
    *(u32 *)(self + 0) = c0;

    u32 s18 = self;
    func_001b0188(s18 + 2824);

    *(u32 *)(s18 + 0) = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32 *)(s18 + 0) = addr_D_003503e0();
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
}  // namespace n0031e690

// 0031e740 (was src/anon/auto80_199_queue.cpp)
namespace n0031e740 {
/*TARGET 0031e740*/
void func_0031e740(u32 self) asm("_Z13func_0031e740j");
void func_0031e740(u32 self) {
    u32 c0 = addr_D_0034e8b8();
    u32 c2824 = addr_D_00350e60();
    *(u32*)(self + 2824) = c2824;
    *(u32*)(self + 0) = c0;

    u32 s18 = self;
    func_001b0188(s18 + 2824);

    *(u32*)(s18 + 0) = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)(s18 + 0) = addr_D_003503e0();
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
    func_00105110(s18);
}
}  // namespace n0031e740

// 0031e7f8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0031e7f8 {
extern u8 D_00350e48 asm("D_00350e48");
// 0x001a9798: definition moved into src/anon/unit_001a9130.cpp

u32 func_001b0188(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b0188jjjj");
/*TARGET 0031e7f8*/
u32 func_0031e7f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031e7f8jjjj");
u32 func_0031e7f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00350e48;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001b0188)(u32, u32, u32, u32) = func_001b0188;
    r2 = fp_call4_001b0188(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031e7f8

// 0031e820 (was src/anon/auto80_199_queue.cpp)
namespace n0031e820 {
/*TARGET 0031e820*/
void func_0031e820(u32 self) asm("_Z13func_0031e820j");
void func_0031e820(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
}
}  // namespace n0031e820

// 0031e878 (was src/anon/auto80_199_queue.cpp)
namespace n0031e878 {
/*TARGET 0031e878*/
void func_0031e878(u32 self) asm("_Z13func_0031e878j");
void func_0031e878(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}
}  // namespace n0031e878

// 0031e8d8 (gap; copy of 0x00105a10, was src/common/unit_0031e8d8.cpp)
namespace n0031e8d8 {
/*TARGET 0031e8d8*/
void func_0031e8d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e8d8");
void func_0031e8d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031e8d8

// 0031e8e0 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0031e8e0 {
u32 func_0016bda8(u32, u32, u32, u32) asm("_Z13func_0016bda8jjjj");
/*TARGET 0031e8e0*/
// 0x00303fc0: definition moved into src/newlib/libc/mprec.c

u32 func_0031e8e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031e8e0jjjj");
// 0x00303fc0: definition moved into src/newlib/libc/mprec.c

u32 func_0031e8e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0016bda8(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n0031e8e0

// 0031e908 (gap; copy of 0x00105a10, was src/common/unit_0031e908.cpp)
namespace n0031e908 {
/*TARGET 0031e908*/
void func_0031e908(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e908");
void func_0031e908(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031e908

// 0031e910 (gap; copy of 0x00105a10, was src/common/unit_0031e910.cpp)
namespace n0031e910 {
/*TARGET 0031e910*/
void func_0031e910(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e910");
void func_0031e910(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031e910

// 0031e918 (gap; copy of 0x00105a10, was src/common/unit_0031e918.cpp)
namespace n0031e918 {
/*TARGET 0031e918*/
void func_0031e918(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e918");
void func_0031e918(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031e918

// 0031e920 (gap; copy of 0x00105a10, was src/common/unit_0031e920.cpp)
namespace n0031e920 {
/*TARGET 0031e920*/
void func_0031e920(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e920");
void func_0031e920(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031e920

// 0031e928 (gap; copy of 0x00105a10, was src/common/unit_0031e928.cpp)
namespace n0031e928 {
/*TARGET 0031e928*/
void func_0031e928(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e928");
void func_0031e928(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031e928

// 0031e930 (gap; copy of 0x00105a10, was src/common/unit_0031e930.cpp)
namespace n0031e930 {
/*TARGET 0031e930*/
void func_0031e930(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e930");
void func_0031e930(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031e930

// 0031e938 (was src/anon/tiny.cpp)
namespace n0031e938 {
/*TARGET 0031e938*/
// 0x002d1f40: definition moved into src/anon/unit_002cf260.cpp

// 002e7688: moved to src/anon/unit_002e7658.cpp

void func_0031e938(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031e938jjjj");
// 0x002d1f40: definition moved into src/anon/unit_002cf260.cpp

// 002e7688: moved to src/anon/unit_002e7658.cpp

void func_0031e938(u32 a0, u32 a1, u32 a2, u32 a3) {  // store_zero_u32
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = 0;
}
}  // namespace n0031e938

// 0031e940 (gap; copy of 0x00105a10, was src/common/unit_0031e940.cpp)
namespace n0031e940 {
/*TARGET 0031e940*/
void func_0031e940(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031e940");
void func_0031e940(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031e940

// 0031e948 (was src/anon/auto80_199_queue.cpp)
namespace n0031e948 {
/*TARGET 0031e948*/
void func_0031e948(u32 self) asm("_Z13func_0031e948j");
void func_0031e948(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
}
}  // namespace n0031e948

// 0031e9a0 (was src/anon/auto80_199_queue.cpp)
namespace n0031e9a0 {
/*TARGET 0031e9a0*/
void func_0031e9a0(u32 self) asm("_Z13func_0031e9a0j");
void func_0031e9a0(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}
}  // namespace n0031e9a0

// 0031ea00 (gap; copy of 0x00319fb0, was src/anon/auto200_999.cpp)
namespace n0031ea00 {
void func_001b0188(u32) asm("_Z13func_001b0188j");
void func_001d5718(u32) asm("_Z13func_001d5718j");
void func_0016a358(u32) asm("_Z13func_0016a358j");
extern u32 D_003503e0 asm("D_003503e0");
extern u32 D_00350e48 asm("D_00350e48");
static inline u32 addr_D_003503e0() { return (u32)&D_003503e0; }
static inline u32 addr_D_00350e48() { return (u32)&D_00350e48; }
/*TARGET 0031ea00*/
void func_0031ea00(u32 self) asm("func_0031ea00");
void func_0031ea00(u32 self) {  // big_obj_dtor
    u32 s18 = self;
    *(u32 *)s18 = addr_D_003503e0();

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

    *(u32 *)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}
}  // namespace n0031ea00

// 0031ea80 (was src/anon/auto80_199_queue.cpp)
namespace n0031ea80 {
/*TARGET 0031ea80*/
void func_0031ea80(u32 self) asm("_Z13func_0031ea80j");
void func_0031ea80(u32 self) {
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
}  // namespace n0031ea80

// 0031eb08 (gap; copy of 0x0010f908, was src/anon/unit_0010f338.cpp)
namespace n0031eb08 {
/*TARGET 0031eb08*/
// 00292540: moved to src/anon/unit_00290f78.cpp
void func_0031eb08(u8* p) asm("func_0031eb08");
/*TARGET 0031eb08*/
// 00292540: moved to src/anon/unit_00290f78.cpp
void func_0031eb08(u8* p) asm("func_0031eb08");
// 00292540: moved to src/anon/unit_00290f78.cpp
void func_0031eb08(u8* p) { *(u32*)(p + 268) |= 0x700; }
}  // namespace n0031eb08

// 0031eb18 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0031eb18 {
u32 func_00194468(u32, u32, u32, u32) asm("_Z13func_00194468jjjj");
/*TARGET 0031eb18*/
u32 func_0031eb18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0031eb18jjjj");
u32 func_0031eb18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r14 = (u32)((s32)0u + (-257));
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(268));
    r15 = (u32)(r15 & r14);
    *(u32*)((u32)r4 + (s32)(268)) = r15;
    r2 = func_00194468(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(268));
    r14 = (u32)((s32)0u + (-1025));
    r15 = (u32)(r15 & r14);
    *(u32*)((u32)r16 + (s32)(268)) = r15;
    return r2;
}
}  // namespace n0031eb18

// 0031eb60 (gap; copy of 0x00105868, was src/common/saveram.cpp)
namespace n0031eb60 {
/*TARGET 0031eb60*/
s32 func_0031eb60(void* self) asm("func_0031eb60");
s32 func_0031eb60(void* self) { return *(s32*)((char*)self + 2560); }
}  // namespace n0031eb60

// 0031eb68 (was src/anon/batch_w30.cpp)
namespace n0031eb68 {
// strlen
extern u8 D_0034ee08[] asm("D_0034ee08");
void func_0019f9a8(void*) asm("func_0019f9a8");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
/*TARGET 0031eb68*/
s32 func_0031eb68(u8* p) asm("func_0031eb68");
s32 func_0031eb68(u8* p) {
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    return func_00319fb0(p);  // big_obj_dtor
}
}  // namespace n0031eb68

// 0031ebb0 (was src/anon/batch_w26.cpp)
namespace n0031ebb0 {
void area_free(void*) asm("_ZN4AREA4FreeEPv");
void func_0019f9a8(void*) asm("func_0019f9a8");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 0031ebb0*/
void func_0031ebb0(u8* o) asm("func_0031ebb0");
void func_0031ebb0(u8* o) {
    *(u8**)o = D_0034ee08;
    func_0019f9a8(o + 2568);  // array8_free_slots
    func_001c0248(o + 2640);
    func_00319fb0(o);  // big_obj_dtor
    area_free(o);
}
}  // namespace n0031ebb0

// 0031ebf8 (was src/anon/auto80_199_queue.cpp)
namespace n0031ebf8 {
/*TARGET 0031ebf8*/
void func_0031ebf8(u32 self) asm("_Z13func_0031ebf8j");
void func_0031ebf8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
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
}  // namespace n0031ebf8

// 0031ec98 (was src/anon/auto80_199_queue.cpp)
namespace n0031ec98 {
/*TARGET 0031ec98*/
void func_0031ec98(u32 self) asm("_Z13func_0031ec98j");
void func_0031ec98(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
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
    func_00105110(s18);
}
}  // namespace n0031ec98

// 0031ed38 (gap; copy of 0x00105a10, was src/common/unit_0031ed38.cpp)
namespace n0031ed38 {
/*TARGET 0031ed38*/
void func_0031ed38(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031ed38");
void func_0031ed38(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031ed38

// 0031ed40 (gap; copy of 0x00105a10, was src/common/unit_0031ed40.cpp)
namespace n0031ed40 {
/*TARGET 0031ed40*/
void func_0031ed40(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031ed40");
void func_0031ed40(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031ed40

// 0031ed48 (was src/anon/auto80_199_queue.cpp)
namespace n0031ed48 {
/*TARGET 0031ed48*/
void func_0031ed48(u32 self) asm("_Z13func_0031ed48j");
void func_0031ed48(u32 self) {
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
}  // namespace n0031ed48

// 0031edc8 (was src/anon/auto80_199_queue.cpp)
namespace n0031edc8 {
/*TARGET 0031edc8*/
void func_0031edc8(u32 self) asm("_Z13func_0031edc8j");
void func_0031edc8(u32 self) {
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
}  // namespace n0031edc8

// 0031ee50 (gap; copy of 0x00105a10, was src/common/unit_0031ee50.cpp)
namespace n0031ee50 {
/*TARGET 0031ee50*/
void func_0031ee50(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031ee50");
void func_0031ee50(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031ee50

// 0031ee58 (gap; copy of 0x00105a10, was src/common/unit_0031ee58.cpp)
namespace n0031ee58 {
/*TARGET 0031ee58*/
void func_0031ee58(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031ee58");
void func_0031ee58(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031ee58

// 0031ee60 (gap; copy of 0x00105a10, was src/common/unit_0031ee60.cpp)
namespace n0031ee60 {
/*TARGET 0031ee60*/
void func_0031ee60(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031ee60");
void func_0031ee60(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0031ee60

// 0031ee68 (was src/anon/auto200_999.cpp)
namespace n0031ee68 {
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
/*TARGET 0031ee68*/
void func_0031ee68(u32 a0, u32 a1) asm("_Z13func_0031ee68jj");
void func_0031ee68(u32 a0, u32 a1) { UNLINK_BODY(192) }
}  // namespace n0031ee68

// 0031eec8 (gap)
namespace n0031eec8 {
/*TARGET 0031eec8*/
u32 func_0031eec8(u32 a, u16* b) asm("func_0031eec8");
u32 func_0031eec8(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n0031eec8

// 0031eed8 (was src/anon/auto80_199_queue.cpp)
namespace n0031eed8 {
/*TARGET 0031eed8*/
void func_0031eed8(u32 self) asm("_Z13func_0031eed8j");
void func_0031eed8(u32 self) {
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
}  // namespace n0031eed8

// 0031ef58 (was src/anon/auto80_199_queue.cpp)
namespace n0031ef58 {
/*TARGET 0031ef58*/
void func_0031ef58(u32 self) asm("_Z13func_0031ef58j");
void func_0031ef58(u32 self) {
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
}  // namespace n0031ef58

// 0031efe0 (gap; copy of 0x003207a0, was src/anon/tiny_auto80_fptr4.cpp)
namespace n0031efe0 {
u32 func_0016a358(u32, u32, u32, u32) asm("_Z13func_0016a358jjjj");
extern u8 D_00350388 asm("D_00350388");
/*TARGET 0031efe0*/
u32 func_0031efe0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031efe0");
u32 func_0031efe0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00350388;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0016a358)(u32, u32, u32, u32) = func_0016a358;
    r2 = fp_call4_0016a358(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031efe0

// 0031f008 (was src/anon/batch_w20.cpp)
namespace n0031f008 {
void func_00105110(void*) asm("func_00105110");
void func_0016a358(void*) asm("func_0016a358");
extern void* D_00350388[] asm("D_00350388");
/*TARGET 0031f008*/
// 0x002db8a8: definition moved into src/anon/unit_002da040.cpp

// 002ef180: moved to src/anon/unit_002ee8a8.cpp

// 002f0598: moved to src/anon/unit_002efd68.cpp

// 002f0a68: moved to src/naka/libkn/trapfunctions.cpp

void func_0031f008(void** p) asm("func_0031f008");
// 0x002db8a8: definition moved into src/anon/unit_002da040.cpp

// 002ef180: moved to src/anon/unit_002ee8a8.cpp

// 002f0598: moved to src/anon/unit_002efd68.cpp

// 002f0a68: moved to src/naka/libkn/trapfunctions.cpp

void func_0031f008(void** p) {
    *p = D_00350388;
    func_0016a358(p);
    func_00105110(p);
}
}  // namespace n0031f008

// 0031f040 (gap; copy of 0x00319fb0, was src/anon/auto200_999.cpp)
namespace n0031f040 {
void func_001b0188(u32) asm("_Z13func_001b0188j");
void func_001d5718(u32) asm("_Z13func_001d5718j");
void func_0016a358(u32) asm("_Z13func_0016a358j");
extern u32 D_003503e0 asm("D_003503e0");
extern u32 D_00350e48 asm("D_00350e48");
static inline u32 addr_D_003503e0() { return (u32)&D_003503e0; }
static inline u32 addr_D_00350e48() { return (u32)&D_00350e48; }
/*TARGET 0031f040*/
void func_0031f040(u32 self) asm("func_0031f040");
void func_0031f040(u32 self) {  // big_obj_dtor
    u32 s18 = self;
    *(u32 *)s18 = addr_D_003503e0();

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

    *(u32 *)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}
}  // namespace n0031f040

// 0031f0c0 (was src/anon/auto80_199_queue.cpp)
namespace n0031f0c0 {
/*TARGET 0031f0c0*/
void func_0031f0c0(u32 self) asm("_Z13func_0031f0c0j");
void func_0031f0c0(u32 self) {
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
}  // namespace n0031f0c0

// 0031f148 (gap)
namespace n0031f148 {
/*TARGET 0031f148*/
u32 func_0031f148(u32 a, u16* b) asm("func_0031f148");
u32 func_0031f148(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n0031f148

// 0031f158 (gap)
namespace n0031f158 {
/*TARGET 0031f158*/
u32 func_0031f158(u32 a, u32* b) asm("func_0031f158");
u32 func_0031f158(u32 a, u32* b) { a -= *b; return a; }
}  // namespace n0031f158

// 0031f168 (was src/anon/batch_w1781_nsa.cpp)
namespace n0031f168 {
// 0x2c7060: moved to src/anon/unit_002c6eb8.cpp


struct W1781Ent616 { u8 d[616]; };
struct W1781Mgr616 { W1781Ent616 ent[64]; s32 list[64]; s32 count; };
/*TARGET 0031f168*/
W1781Ent616* func_0031f168(W1781Mgr616* m, W1781Ent616* p) asm("func_0031f168");
W1781Ent616* func_0031f168(W1781Mgr616* m, W1781Ent616* p) {
    if (p) p++; else p = m->ent;
    while (p < &m->ent[64]) {
        s32 idx = p - m->ent;
        s32 i;
        for (i = 0; i < m->count; i++) {
            if (m->list[i] == idx) { p++; break; }
        }
        if (i == m->count) return p;
    }
    return 0;
}
}  // namespace n0031f168

// 0031f210 (gap; copy of 0x001b0188, was src/anon/unit_001ada38.cpp)
namespace n0031f210 {
u32 func_0018d420(u32, u32, u32, u32) asm("_Z13func_0018d420jjjj");
extern u8 D_00350778 asm("D_00350778");
u32 func_0031f210(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f210");
/*TARGET 0031f210*/
u32 func_0031f210(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0031f210");
u32 func_0031f210(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00350778;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0018d420)(u32, u32, u32, u32) = func_0018d420;
    r2 = fp_call4_0018d420(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0031f210

// 0031f238 (was src/anon/batch_w21.cpp)
namespace n0031f238 {
void func_00105110(void*) asm("func_00105110");
void func_0018d420(void*) asm("func_0018d420");
extern u32 D_00350778 asm("D_00350778");
/*TARGET 0031f238*/
// 0x002df160: definition moved into src/anon/unit_002de3c8.cpp

// 002f0da8: moved to src/naka/libkn/trapfunctions.cpp

// 002f0e60: moved to src/naka/libkn/trapfunctions.cpp

void func_0031f238(void** p) asm("func_0031f238");
// 0x002df160: definition moved into src/anon/unit_002de3c8.cpp

// 002f0da8: moved to src/naka/libkn/trapfunctions.cpp

// 002f0e60: moved to src/naka/libkn/trapfunctions.cpp

void func_0031f238(void** p) {
    *p = &D_00350778;
    func_0018d420(p);
    func_00105110(p);
}
}  // namespace n0031f238

// 0031f270 (gap)
namespace n0031f270 {
/*TARGET 0031f270*/
u8* func_0031f270(u8* d, u8* s) asm("func_0031f270");
u8* func_0031f270(u8* d, u8* s) {
    s += 224;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    return d;
}
}  // namespace n0031f270

// 0031f288 (gap)
namespace n0031f288 {
/*TARGET 0031f288*/
u32 func_0031f288(u32 a, u16* b) asm("func_0031f288");
u32 func_0031f288(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n0031f288
