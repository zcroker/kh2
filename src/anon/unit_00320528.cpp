// Linked unit 0x00320528: linkonce (template) copies of game code that the linker gathered after the
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


// 00320528 (was src/anon/batch_w3718.cpp)
namespace n00320528 {
void func_001ddd10(void*) asm("func_001ddd10");
void func_00320400(void*) asm("func_00320400");
void func_001d1678(void*, s32) asm("func_001d1678");
void func_001d1fa8(void*) asm("func_001d1fa8");
void func_001d4d28(void*) asm("func_001d4d28");
extern u8 D_003525c8[] asm("D_003525c8");
extern u8 D_003525a8[] asm("D_003525a8");
extern u8 D_00352588[] asm("D_00352588");
extern u8 D_00352560[] asm("D_00352560");
extern u8 D_00352858[] asm("D_00352858");
static inline void c320528_B(u8* p) { *(u32*)(p + 4) = 0; *(u32*)(p + 8) = 0; *(void**)p = D_003525c8; func_00320400(p + 0xc); func_001d1678(p, -1); }
/*TARGET 00320528*/
// Constructor: zeroes fields, builds the embedded sub-objects at +0xbc, +0xe8 (x3), +0x190 (x3), +0x22c and +0x260.
// The +0x5c/+0x78/+0x94/+0xb0 and +0x22c members are pointer-typed (their alias set fixes the store order).
void __sti___11_mission_cpp_fcee223a(u8* p) asm("__sti___11_mission_cpp_fcee223a");
// Constructor: zeroes fields, builds the embedded sub-objects at +0xbc, +0xe8 (x3), +0x190 (x3), +0x22c and +0x260.
// The +0x5c/+0x78/+0x94/+0xb0 and +0x22c members are pointer-typed (their alias set fixes the store order).
void __sti___11_mission_cpp_fcee223a(u8* p) {
    *(u32*)(p + 4) = 0;
    func_001ddd10(p + 0xc);
    *(u32*)(p + 0x58) = 0;
    *(u32*)(p + 0x74) = 0;
    *(u32*)(p + 0x90) = 0;
    *(u32*)(p + 0xac) = 0;
    { u8* q = p + 0xbc;
    *(void**)(p + 0x5c) = 0;
    *(u32*)(q + 4) = 0;
    *(void**)(p + 0x78) = 0;
    *(u32*)q = (u32)D_003525c8;
    *(void**)(p + 0x94) = 0;
    *(void**)(p + 0xb0) = 0;
    *(u32*)(p + 0xc4) = 0;
    func_00320400(q + 0xc); func_001d1678(q, -1); }
    *(void**)(p + 0xbc) = D_003525a8;
    { u8* q = p + 0xe8; s32 i = 2; do { c320528_B(q); *(void**)q = D_00352588; *(u32*)(q + 0x30) = 0; i--; q += 0x38; } while (i != -1); }
    { u8* q = p + 0x190; s32 i = 2; do { c320528_B(q); *(void**)q = D_00352560; *(u32*)(q + 0x30) = 0; i--; q += 0x34; } while (i != -1); }
    u8* q;
    q = p + 0x22c;
    *(u32*)(p + 0x234) = 0; *(void**)(q + 4) = 0; *(void**)q = D_003525c8; func_00320400(q + 0xc); func_001d1678(q, -1); *(void**)(p + 0x22c) = D_00352858;
    q = p + 0x260;
    func_001d1fa8(q);
    *(u32*)(p + 0x2d0) = 0;
    *(u32*)(p + 0x2d4) = 0;
    func_001d4d28(p + 0x2e4);
}
}  // namespace n00320528

// 003206c0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n003206c0 {
// is_halfword42_zero
u32 func_001d48b0(u32, u32, u32, u32) asm("_Z13func_001d48b0jjjj");
extern u8 D_00351228 asm("D_00351228");
/*TARGET 003206c0*/
u32 func_003206c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_003206c0jjjj");
u32 func_003206c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = (u32)&D_00351228;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)((s32)r4 + (2496));
    r4 = r14;
    u32 (*fp_call4_001d48b0)(u32, u32, u32, u32) = func_001d48b0;
    r2 = fp_call4_001d48b0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n003206c0

// 003206f0 (was src/anon/batch_w18.cpp)
namespace n003206f0 {
void func_00106420(void*) asm("func_00106420");
// 0x003158c8: definition moved into src/libsupc++/tinfo.cpp

extern u32 D_00351228 asm("D_00351228");
void func_001d48b0(void*) asm("func_001d48b0");
/*TARGET 003206f0*/
void func_003206f0(u8* p) asm("func_003206f0");
void func_003206f0(u8* p) {
    *(void**)p = &D_00351228;
    func_001d48b0(p + 2496);
    func_00106420(p);
}
}  // namespace n003206f0

// 00320728 (gap; copy of 0x00105a10, was src/common/unit_00320728.cpp)
namespace n00320728 {
/*TARGET 00320728*/
void func_00320728(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00320728");
void func_00320728(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00320728

// 00320730 (was src/anon/tiny_leaf.cpp)
namespace n00320730 {
/*TARGET 00320730*/
void func_00320730(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00320730jjjj");
void func_00320730(u32 a0, u32 a1, u32 a2, u32 a3) {  // zero_halfword
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(u16*)((u32)r4 + (s32)(0)) = (u16)0u;
}
}  // namespace n00320730

// 00320738 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00320738 {
// is_halfword42_zero
u32 func_001d48b0(u32, u32, u32, u32) asm("_Z13func_001d48b0jjjj");
extern u8 D_00351228 asm("D_00351228");
/*TARGET 00320738*/
u32 func_00320738(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00320738jjjj");
u32 func_00320738(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = (u32)&D_00351228;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)((s32)r4 + (2496));
    r4 = r14;
    u32 (*fp_call4_001d48b0)(u32, u32, u32, u32) = func_001d48b0;
    r2 = fp_call4_001d48b0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00320738

// 00320768 (was src/anon/batch_w19.cpp)
namespace n00320768 {
// set_vtbl_36eb28_then_call
void func_00106420(void*) asm("func_00106420");
void func_001d48b0(void*) asm("func_001d48b0");
extern u8 D_00351228[] asm("D_00351228");
/*TARGET 00320768*/
void func_00320768(u8* p) asm("func_00320768");
void func_00320768(u8* p) {
    *(void**)p = D_00351228;
    func_001d48b0(p + 0x9c0);
    func_00106420(p);
}
}  // namespace n00320768

// 003207a0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n003207a0 {
u32 func_0016a358(u32, u32, u32, u32) asm("_Z13func_0016a358jjjj");
extern u8 D_003512e8 asm("D_003512e8");
/*TARGET 003207a0*/
u32 func_003207a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_003207a0jjjj");
u32 func_003207a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003512e8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0016a358)(u32, u32, u32, u32) = func_0016a358;
    r2 = fp_call4_0016a358(r4, r5, r6, r7);
    return r2;
}
}  // namespace n003207a0

// 003207c8 (was src/anon/batch_w15.cpp)
namespace n003207c8 {
void func_00105110(void*) asm("func_00105110");
// 0x00315678: definition moved into src/libsupc++/tinfo.cpp

extern u8 D_003512e8 asm("D_003512e8");
void func_0016a358(void*) asm("func_0016a358");
/*TARGET 003207c8*/
void func_003207c8(void** self) asm("func_003207c8");
void func_003207c8(void** self) {
    *self = &D_003512e8;
    func_0016a358(self);
    func_00105110(self);
}
}  // namespace n003207c8

// 00320800 (gap; copy of 0x00321468, was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00320800 {
u32 func_0017a968(u32, u32, u32, u32) asm("_Z13func_0017a968jjjj");
/*TARGET 00320800*/
u32 func_00320800(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00320800");
u32 func_00320800(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0017a968(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n00320800

// 00320828 (was src/anon/auto200_999.cpp)
namespace n00320828 {
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
/*TARGET 00320828*/
// 003204c8: LIST<YS::ITEM_EFFECT>::Remove, now made by gcc in src/yasui/libys/itemeffectlist.cpp
void wtarget_00320828(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00320828jjjj");
// 003204c8: LIST<YS::ITEM_EFFECT>::Remove, now made by gcc in src/yasui/libys/itemeffectlist.cpp
void wtarget_00320828(u32 a0, u32 a1, u32 a2, u32 a3) { UNLINK_BODY(80) }
}  // namespace n00320828

// 00320888 (gap)
namespace n00320888 {
/*TARGET 00320888*/
u32 func_00320888(u32 a, u32* b) asm("func_00320888");
u32 func_00320888(u32 a, u32* b) { a -= *b; return a; }
}  // namespace n00320888

// 00320898 (gap)
namespace n00320898 {
/*TARGET 00320898*/
u32 func_00320898(u32 a, u16* b) asm("func_00320898");
u32 func_00320898(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n00320898

// 003208a8 (was src/anon/auto200_999.cpp)
namespace n003208a8 {
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
/*TARGET 003208a8*/
void func_003208a8(u32 a0, u32 a1) asm("_Z13func_003208a8jj");
void func_003208a8(u32 a0, u32 a1) { UNLINK_BODY(36) }
}  // namespace n003208a8

// 00320908 (gap; copy of 0x00320938, was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00320908 {
u32 func_001c1df8(u32, u32, u32, u32) asm("_Z13func_001c1df8jjjj");
/*TARGET 00320908*/
u32 func_00320908(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00320908");
u32 func_00320908(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r5 = r6;
    r16 = r4;
    r2 = func_001c1df8(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n00320908

// 00320938 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00320938 {
u32 func_001c1df8(u32, u32, u32, u32) asm("_Z13func_001c1df8jjjj");
/*TARGET 00320938*/
u32 func_00320938(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00320938jjjj");
u32 func_00320938(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r5 = r6;
    r16 = r4;
    r2 = func_001c1df8(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n00320938

// 00320968 (was src/anon/auto80_199_queue.cpp)
namespace n00320968 {
/*TARGET 00320968*/
void func_00320968(u32 self) asm("_Z13func_00320968j");
void func_00320968(u32 self) {
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
}  // namespace n00320968

// 003209e8 (was src/anon/auto80_199_queue.cpp)
namespace n003209e8 {
/*TARGET 003209e8*/
void func_003209e8(u32 self) asm("_Z13func_003209e8j");
void func_003209e8(u32 self) {
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
}  // namespace n003209e8

// 00320a70 (gap; copy of 0x00319fb0, was src/anon/auto200_999.cpp)
namespace n00320a70 {
void func_001b0188(u32) asm("_Z13func_001b0188j");
void func_001d5718(u32) asm("_Z13func_001d5718j");
void func_0016a358(u32) asm("_Z13func_0016a358j");
extern u32 D_003503e0 asm("D_003503e0");
extern u32 D_00350e48 asm("D_00350e48");
static inline u32 addr_D_003503e0() { return (u32)&D_003503e0; }
static inline u32 addr_D_00350e48() { return (u32)&D_00350e48; }
/*TARGET 00320a70*/
void func_00320a70(u32 self) asm("func_00320a70");
void func_00320a70(u32 self) {  // big_obj_dtor
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
}  // namespace n00320a70

// 00320af0 (was src/anon/auto80_199_queue.cpp)
namespace n00320af0 {
/*TARGET 00320af0*/
void func_00320af0(u32 self) asm("_Z13func_00320af0j");
void func_00320af0(u32 self) {
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
}  // namespace n00320af0

// 00320b78 (gap; copy of 0x002cff98, was src/anon/unit_002cf260.cpp)
namespace n00320b78 {
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 00320b78*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00320b78(u8* o) asm("func_00320b78");
/*TARGET 00320b78*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00320b78(u8* o) asm("func_00320b78");
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00320b78(u8* o) {
    *(u8**)o = D_0034ee08;
    YS__OBJ_ATTACK__clear(o + 2568);  // array8_free_slots
    func_001c0248(o + 2640);
    return func_00319fb0(o);  // big_obj_dtor
}
}  // namespace n00320b78

// 00320bc0 (was src/anon/batch_w30.cpp)
namespace n00320bc0 {
// strlen
extern u8 D_0034ee08[] asm("D_0034ee08");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
// big_obj_dtor
void func_00105110(void*) asm("func_00105110");
/*TARGET 00320bc0*/
void func_00320bc0(u8* p) asm("func_00320bc0");
void func_00320bc0(u8* p) {
    *(void**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}  // namespace n00320bc0

// 00320c08 (gap)
namespace n00320c08 {
/*TARGET 00320c08*/
u32 func_00320c08(u32 a, u32* b) asm("func_00320c08");
u32 func_00320c08(u32 a, u32* b) { a -= *b; return a; }
}  // namespace n00320c08

// 00320c18 (was src/anon/batch_w15.cpp)
namespace n00320c18 {
struct Ent8 { u16 id; u16 _2; u32 _4; };
/*TARGET 00320c18*/
Ent8* func_00320c18(u8* p, u32 id) asm("func_00320c18");
Ent8* func_00320c18(u8* p, u32 id) {  // table_find_short
    int n = *(int*)(p + 4);
    Ent8* e = (Ent8*)(p + 8);
    for (int i = 0; i < n; i++, e++) {
        if (e->id == id) return e;
    }
    return 0;
}
}  // namespace n00320c18

// 00320c58 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00320c58 {
u32 func_0031ffc0(u32, u32, u32, u32) asm("_Z13func_0031ffc0jjjj");
extern u8 D_00352878 asm("D_00352878");
/*TARGET 00320c58*/
u32 func_00320c58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00320c58jjjj");
u32 func_00320c58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00352878;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0031ffc0)(u32, u32, u32, u32) = func_0031ffc0;
    r2 = fp_call4_0031ffc0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00320c58

// 00320c80 (was src/anon/batch_w16.cpp)
namespace n00320c80 {
void func_00105110(void*) asm("func_00105110");
// set_vtbl_367878
void func_0031ffc0(void*) asm("func_0031ffc0");
extern u8 D_00352878 asm("D_00352878");
/*TARGET 00320c80*/
// 0x003157b8: definition moved into src/libsupc++/tinfo.cpp

void func_00320c80(void* p) asm("func_00320c80");
// 0x003157b8: definition moved into src/libsupc++/tinfo.cpp

void func_00320c80(void* p) {
    *(void**)p = &D_00352878;
    func_0031ffc0(p);
    func_00105110(p);
}
}  // namespace n00320c80

// 00320cb8 (gap; copy of 0x00320da8, was src/anon/auto80_199_queue.cpp)
namespace n00320cb8 {
/*TARGET 00320cb8*/
void func_00320cb8(u32 self) asm("func_00320cb8");
void func_00320cb8(u32 self) {
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

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}
}  // namespace n00320cb8

// 00320d30 (was src/anon/auto80_199_queue.cpp)
namespace n00320d30 {
/*TARGET 00320d30*/
void func_00320d30(u32 self) asm("_Z13func_00320d30j");
void func_00320d30(u32 self) {
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

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}
}  // namespace n00320d30

// 00320da8 (was src/anon/auto80_199_queue.cpp)
namespace n00320da8 {
/*TARGET 00320da8*/
void func_00320da8(u32 self) asm("_Z13func_00320da8j");
void func_00320da8(u32 self) {
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

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}
}  // namespace n00320da8

// 00320e20 (was src/anon/auto80_199_queue.cpp)
namespace n00320e20 {
/*TARGET 00320e20*/
void func_00320e20(u32 self) asm("_Z13func_00320e20j");
void func_00320e20(u32 self) {
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

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}
}  // namespace n00320e20

// 00320e98 (was src/anon/auto80_199_queue.cpp)
namespace n00320e98 {
/*TARGET 00320e98*/
void func_00320e98(u32 self) asm("_Z13func_00320e98j");
void func_00320e98(u32 self) {
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
}  // namespace n00320e98

// 00320f18 (was src/anon/auto80_199_queue.cpp)
namespace n00320f18 {
/*TARGET 00320f18*/
void func_00320f18(u32 self) asm("_Z13func_00320f18j");
void func_00320f18(u32 self) {
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
}  // namespace n00320f18

// 00320fa0 (gap; copy of 0x00105a10, was src/common/unit_00320fa0.cpp)
namespace n00320fa0 {
/*TARGET 00320fa0*/
void func_00320fa0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00320fa0");
void func_00320fa0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00320fa0

// 00320fa8 (was src/anon/auto80_199_queue.cpp)
namespace n00320fa8 {
/*TARGET 00320fa8*/
void func_00320fa8(u32 self) asm("_Z13func_00320fa8j");
void func_00320fa8(u32 self) {
    u32 c0 = addr_D_0034e8b8();
    u32 c2824 = addr_D_00350e60();
    *(u32*)(self + 2824) = c2824;
    *(u32*)(self + 0) = c0;

    u32 s18 = self;
    func_001b0188(s18 + 2824);

    *(u32*)(s18 + 0) = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s18 + 2568);  // array8_free_slots
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
    u32 t = s18;
    (void)t;
}
}  // namespace n00320fa8

// 00321058 (gap)
namespace n00321058 {
/*TARGET 00321058*/
u32 func_00321058(u32 a, u32* b) asm("func_00321058");
u32 func_00321058(u32 a, u32* b) { a -= *b; return a; }
}  // namespace n00321058

// 00321068 (was src/anon/batch_w262.cpp)
namespace n00321068 {
struct W262In { u32 a[20]; u32 b[3]; u32 c[18]; u32 d[9]; u32 x200, x204; };
struct W262Q { u32 a[4]; u8 b; };
struct W262S {
    u8 pad[12];
    W262In in;
    u8 pad2[2108 - 12 - 208];
    u32 x83c, x840;
    W262Q q;
    u8 pad3[2136 - 2116 - 20];
};
void func_00319d20(void*) asm("func_00319d20");
// zero_two_words
void func_00321198(void*) asm("func_00321198");
// zero_3_words
void func_00319d58(void*) asm("func_00319d58");
// store_zero_byte
void func_00319a60(void*) asm("func_00319a60");
/*TARGET 00321068*/
// clear_fixed_blocks
void func_00321068(u8* p) asm("func_00321068");
// clear_fixed_blocks
void func_00321068(u8* p) {  // clear_19_words
    W262S* s = (W262S*)p;
    W262In* in = &s->in;
    W262Q* q;
    int i;
    for (i = 0; i < 20; i++) in->a[i] = 0;
    for (i = 0; i < 3; i++) in->b[i] = 0;
    for (i = 0; i < 18; i++) in->c[i] = 0;
    for (i = 0; i < 9; i++) in->d[i] = 0;
    in->x200 = 0; in->x204 = 0;
    s->x83c = 0; s->x840 = 0;
    q = &s->q;
    for (i = 0; i < 4; i++) q->a[i] = 0;
    q->b = 0;
    func_00319d20(p + 2136);  // zero_two_words
    func_00319d20(p + 2144);  // zero_two_words
    func_00321198(p + 2152);  // zero_3_words
    func_00321198(p + 2164);  // zero_3_words
    func_00321198(p + 2176);  // zero_3_words
    func_00319d20(p + 2188);  // zero_two_words
    func_00319d58(p + 2713);  // store_zero_byte
    func_00319a60(p + 2716);  // clear_fixed_blocks
}
}  // namespace n00321068

// 00321198 (was src/anon/tiny_auto80_queue.cpp)
namespace n00321198 {
/*TARGET 00321198*/
void func_00321198(u32* a0) asm("_Z13func_00321198Pj");
void func_00321198(u32* a0) {  // zero_3_words
    s32 t7 = 2;
    do {
        *a0 = 0;
        t7 -= 1;
        a0 += 1;
    } while (t7 >= 0);
}
}  // namespace n00321198

// 003211c0 (was src/anon/auto80_199_queue.cpp)
namespace n003211c0 {
/*TARGET 003211c0*/
void func_003211c0(u32 self) asm("_Z13func_003211c0j");
void func_003211c0(u32 self) {
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
}  // namespace n003211c0

// 00321240 (was src/anon/auto80_199_queue.cpp)
namespace n00321240 {
/*TARGET 00321240*/
void func_00321240(u32 self) asm("_Z13func_00321240j");
void func_00321240(u32 self) {
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
}  // namespace n00321240

// 003212c8 (gap)
namespace n003212c8 {
extern u32 D_003521e0 asm("D_003521e0");
extern u32 D_0034e8b8 asm("D_0034e8b8");
extern u32 D_0034ee08 asm("D_0034ee08");
void func_001d5718(u32) asm("func_001d5718");
void func_00319f88(u32) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(u32) asm("YS__OBJ_ATTACK__clear");
void func_001c0248(u32) asm("func_001c0248");
void func_00319fb0(u32) asm("func_00319fb0");
/*TARGET 003212c8*/
// Destructor (0x321338 is the deleting one).
void func_003212c8(u32 self) asm("func_003212c8");
void func_003212c8(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = (u32)&D_003521e0;
    func_001d5718(s16 + 2932);
    *(u32*)s16 = (u32)&D_0034e8b8;
    func_00319f88(s16 + 2824);
    *(u32*)s16 = (u32)&D_0034ee08;
    YS__OBJ_ATTACK__clear(s16 + 2568);
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);
    u32 t = s16;
    (void)t;
}
}  // namespace n003212c8

// 00321338 (was src/anon/auto80_199_queue.cpp)
namespace n00321338 {
/*TARGET 00321338*/
void func_00321338(u32 self) asm("_Z13func_00321338j");
void func_00321338(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_003521e0();
    func_001d5718(s16 + 2932);  // list_free_nodes

    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);

    *(u32*)s16 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}
}  // namespace n00321338

// 003213a8 (was src/anon/auto80_199_queue.cpp)
namespace n003213a8 {
/*TARGET 003213a8*/
void func_003213a8(u32 self) asm("_Z13func_003213a8j");
void func_003213a8(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
}
}  // namespace n003213a8

// 00321400 (was src/anon/auto80_199_queue.cpp)
namespace n00321400 {
/*TARGET 00321400*/
void func_00321400(u32 self) asm("_Z13func_00321400j");
void func_00321400(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}
}  // namespace n00321400

// 00321460 (gap; copy of 0x002061f0, was src/anon/unit_002061d8.cpp)
namespace n00321460 {
/*TARGET 00321460*/
s64 func_00321460(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_00321460");
/*TARGET 00321460*/
s64 func_00321460(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_00321460");
s64 func_00321460(s64 param0, s64 param1, s64 param2, s64 param3) {
    s64 result = 0, arg0 = param0, arg1 = param1, arg2 = param2, arg3 = param3, returnAddr = 0;
    result = 0 + 0;
    return result;
}
}  // namespace n00321460

// 00321468 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00321468 {
u32 func_0017a968(u32, u32, u32, u32) asm("_Z13func_0017a968jjjj");
/*TARGET 00321468*/
u32 func_00321468(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00321468jjjj");
u32 func_00321468(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0017a968(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n00321468

// 00321490 (gap; copy of 0x00105a10, was src/common/unit_00321490.cpp)
namespace n00321490 {
/*TARGET 00321490*/
void func_00321490(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00321490");
void func_00321490(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00321490

// 00321498 (was src/anon/auto80_199_queue.cpp)
namespace n00321498 {
/*TARGET 00321498*/
void func_00321498(u32 self) asm("_Z13func_00321498j");
void func_00321498(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
}
}  // namespace n00321498

// 003214f0 (was src/anon/auto80_199_queue.cpp)
namespace n003214f0 {
/*TARGET 003214f0*/
void func_003214f0(u32 self) asm("_Z13func_003214f0j");
void func_003214f0(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}
}  // namespace n003214f0

// 00321550 (gap; copy of 0x0031e820, was src/anon/auto80_199_queue.cpp)
namespace n00321550 {
/*TARGET 00321550*/
void func_00321550(u32 self) asm("func_00321550");
void func_00321550(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
}
}  // namespace n00321550

// 003215a8 (was src/anon/auto80_199_queue.cpp)
namespace n003215a8 {
/*TARGET 003215a8*/
void func_003215a8(u32 self) asm("_Z13func_003215a8j");
void func_003215a8(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}
}  // namespace n003215a8

// 00321608 (gap; copy of 0x001395f8, was src/anon/unit_001391c8.cpp)
namespace n00321608 {
/*TARGET 00321608*/
void func_00321608(void* t) asm("func_00321608");
void func_00321608(void* t) {
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(t) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(t) + 0x0c) = v & static_cast<u32>(-9);
}
}  // namespace n00321608

// 00321620 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00321620 {
u32 YS__MISSION_GAUGE__destroy(u32, u32, u32, u32) asm("_Z26YS__MISSION_GAUGE__destroyjjjj");
extern u8 D_00352560 asm("D_00352560");
/*TARGET 00321620*/
u32 func_00321620(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00321620jjjj");
u32 func_00321620(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00352560;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001d1ed0)(u32, u32, u32, u32) = YS__MISSION_GAUGE__destroy;
    r2 = fp_call4_001d1ed0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00321620

// 00321648 (was src/anon/batch_w17.cpp)
namespace n00321648 {
// set_vtbl_347c00
void func_00106420(void*) asm("func_00106420");
// 0x00316890: definition moved into src/libsupc++/eh_exception.cpp

extern u32 D_00352560 asm("D_00352560");
void YS__MISSION_GAUGE__destroy(void*) asm("YS__MISSION_GAUGE__destroy");
/*TARGET 00321648*/
void func_00321648(void** p) asm("func_00321648");
void func_00321648(void** p) {
    *p = &D_00352560;
    YS__MISSION_GAUGE__destroy(p);
    func_00106420(p);
}
}  // namespace n00321648

// 00321680 (gap)
namespace n00321680 {
/*TARGET 00321680*/
void func_00321680(void) asm("func_00321680");
void func_00321680(void) {}
}  // namespace n00321680

// 00321688 (gap)
namespace n00321688 {
/*TARGET 00321688*/
u32 func_00321688(u32 a, u16* b) asm("func_00321688");
u32 func_00321688(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n00321688

// 00321698 (gap)
namespace n00321698 {
/*TARGET 00321698*/
u32 func_00321698(u32 a, u16* b) asm("func_00321698");
u32 func_00321698(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n00321698

// 003216a8 (gap)
namespace n003216a8 {
/*TARGET 003216a8*/
u32 func_003216a8(u32 a, u8* b) asm("func_003216a8");
u32 func_003216a8(u32 a, u8* b) { a -= *b; return a; }
}  // namespace n003216a8

// 003216b8 (gap)
namespace n003216b8 {
/*TARGET 003216b8*/
u32 func_003216b8(u32 a, u32* b) asm("func_003216b8");
u32 func_003216b8(u32 a, u32* b) { a -= *b; return a; }
}  // namespace n003216b8
