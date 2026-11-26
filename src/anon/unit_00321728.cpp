// Linked unit 0x00321728: linkonce (template) copies of game code that the linker gathered after the
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


// 00321728 (was src/anon/batch_w42.cpp)
namespace n00321728 {
// 002ec9d0: moved to src/anon/unit_002ec5f8.cpp

// 00321728: cache lookup; on miss reuse the entry with the lowest age
struct E4 { u8 a; u8 age; u16 key; };
/*TARGET 00321728*/
E4* func_00321728(E4* e, u32 a, u32 k) asm("func_00321728");
E4* func_00321728(E4* e, u32 a, u32 k)
{
    E4* best = 0;
    for (s32 i = 0; i < 128; i++, e++) {
        if (e->a == a && e->key == k) return e;
        if (!best || best->age > e->age) best = e;
    }
    best->a = a;
    best->key = k;
    best->age = 0;
    return best;
}
}  // namespace n00321728

// 00321790 (gap)
namespace n00321790 {
/*TARGET 00321790*/
u32 func_00321790(u32 a, u8* b) asm("func_00321790");
u32 func_00321790(u32 a, u8* b) { a -= *b; return a; }
}  // namespace n00321790

// 003217a0 (gap)
namespace n003217a0 {
/*TARGET 003217a0*/
u32 func_003217a0(u32 a, u8* b) asm("func_003217a0");
u32 func_003217a0(u32 a, u8* b) { a -= *b; return a; }
}  // namespace n003217a0

// 003217b0 (was src/anon/auto80_199_queue.cpp)
namespace n003217b0 {
/*TARGET 003217b0*/
void func_003217b0(u32 self) asm("_Z13func_003217b0j");
void func_003217b0(u32 self) {
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
}  // namespace n003217b0

// 00321830 (was src/anon/auto80_199_queue.cpp)
namespace n00321830 {
/*TARGET 00321830*/
void func_00321830(u32 self) asm("_Z13func_00321830j");
void func_00321830(u32 self) {
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
}  // namespace n00321830

// 003218b8 (gap)
namespace n003218b8 {
/*TARGET 003218b8*/
u32 func_003218b8(u32 a, u16* b) asm("func_003218b8");
u32 func_003218b8(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n003218b8

// 003218c8 (was src/anon/batch_w31.cpp)
namespace n003218c8 {
extern void* D_0034ee08[] asm("D_0034ee08");
void func_0019f9a8(void*) asm("func_0019f9a8");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
// 0x002dc808: definition moved into src/anon/unit_002da040.cpp

// Empty-destructor local: keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };
/*TARGET 003218c8*/
void func_003218c8(void** p) asm("func_003218c8");
void func_003218c8(void** p) {
    NoTail g;
    *p = D_0034ee08;
    func_0019f9a8((u8*)p + 2568);  // array8_free_slots
    func_001c0248((u8*)p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}
}  // namespace n003218c8

// 00321910 (was src/anon/batch_w31.cpp)
namespace n00321910 {
void func_00105110(void*) asm("func_00105110");
extern void* D_0034ee08[] asm("D_0034ee08");
void func_0019f9a8(void*) asm("func_0019f9a8");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
/*TARGET 00321910*/
void func_00321910(void** p) asm("func_00321910");
void func_00321910(void** p) {
    *p = D_0034ee08;
    func_0019f9a8((u8*)p + 2568);  // array8_free_slots
    func_001c0248((u8*)p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}  // namespace n00321910

// 00321958 (was src/anon/auto80_199_queue.cpp)
namespace n00321958 {
/*TARGET 00321958*/
void func_00321958(u32 self) asm("_Z13func_00321958j");
void func_00321958(u32 self) {
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
}  // namespace n00321958

// 003219d8 (was src/anon/auto80_199_queue.cpp)
namespace n003219d8 {
/*TARGET 003219d8*/
void func_003219d8(u32 self) asm("_Z13func_003219d8j");
void func_003219d8(u32 self) {
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
}  // namespace n003219d8

// 00321a60 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n00321a60 {
extern u32 D_00352a20 asm("D_00352a20");
/*TARGET 00321a60*/
void func_00321a60(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00321a60");
void func_00321a60(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00352a20;
}
}  // namespace n00321a60

// 00321a70 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00321a70 {
u32 func_00105110(u32, u32, u32, u32) asm("_Z13func_00105110jjjj");
extern u8 D_00352a20 asm("D_00352a20");
/*TARGET 00321a70*/
// 0x003037c0: definition moved into src/newlib/libc/locale.c

u32 func_00321a70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00321a70jjjj");
// 0x003037c0: definition moved into src/newlib/libc/locale.c

u32 func_00321a70(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00352a20);
    return func_00105110(a0, a1, a2, a3);
}
}  // namespace n00321a70

// 00321a90 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n00321a90 {
extern u32 D_00352a20 asm("D_00352a20");
/*TARGET 00321a90*/
void func_00321a90(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00321a90");
void func_00321a90(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00352a20;
}
}  // namespace n00321a90

// 00321aa0 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00321aa0 {
u32 func_00105110(u32, u32, u32, u32) asm("_Z13func_00105110jjjj");
extern u8 D_00352a20 asm("D_00352a20");
/*TARGET 00321aa0*/
u32 func_00321aa0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00321aa0jjjj");
u32 func_00321aa0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00352a20);
    return func_00105110(a0, a1, a2, a3);
}
}  // namespace n00321aa0

// 00321ac0 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n00321ac0 {
extern u32 D_00352a20 asm("D_00352a20");
/*TARGET 00321ac0*/
void func_00321ac0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00321ac0");
void func_00321ac0(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00352a20;
}
}  // namespace n00321ac0

// 00321ad0 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00321ad0 {
u32 func_00105110(u32, u32, u32, u32) asm("_Z13func_00105110jjjj");
extern u8 D_00352a20 asm("D_00352a20");
/*TARGET 00321ad0*/
u32 func_00321ad0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00321ad0jjjj");
u32 func_00321ad0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00352a20);
    return func_00105110(a0, a1, a2, a3);
}
}  // namespace n00321ad0

// 00321af0 (gap; copy of 0x0031b910, was src/anon/tiny.cpp)
namespace n00321af0 {
extern u32 D_00352a20 asm("D_00352a20");
/*TARGET 00321af0*/
void func_00321af0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00321af0");
void func_00321af0(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_3486a8_d
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00352a20;
}
}  // namespace n00321af0

// 00321b00 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00321b00 {
u32 func_00105110(u32, u32, u32, u32) asm("_Z13func_00105110jjjj");
extern u8 D_00352a20 asm("D_00352a20");
/*TARGET 00321b00*/
u32 func_00321b00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00321b00jjjj");
u32 func_00321b00(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00352a20);
    return func_00105110(a0, a1, a2, a3);
}
}  // namespace n00321b00

// 00321b20 (gap)
namespace n00321b20 {
/*TARGET 00321b20*/
s32 func_00321b20(void) asm("func_00321b20");
s32 func_00321b20(void) { return 1; }
}  // namespace n00321b20

// 00321b28 (gap)
namespace n00321b28 {
/*TARGET 00321b28*/
u32 func_00321b28(u32 a, u16* b) asm("func_00321b28");
u32 func_00321b28(u32 a, u16* b) { a -= *b; return a; }
}  // namespace n00321b28

// 00321b38 (gap; copy of 0x00305dd0, was src/sdk/glue.c)
namespace n00321b38 {
/*TARGET 00321b38*/
int func_00321b38(int fd) asm("func_00321b38");
int func_00321b38(int fd) { return 1; }
}  // namespace n00321b38

// 00321b40 (gap; copy of 0x002061f0, was src/anon/unit_002061d8.cpp)
namespace n00321b40 {
/*TARGET 00321b40*/
s64 func_00321b40(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_00321b40");
/*TARGET 00321b40*/
s64 func_00321b40(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_00321b40");
s64 func_00321b40(s64 param0, s64 param1, s64 param2, s64 param3) {
    s64 result = 0, arg0 = param0, arg1 = param1, arg2 = param2, arg3 = param3, returnAddr = 0;
    result = 0 + 0;
    return result;
}
}  // namespace n00321b40

// 00321b48 (was src/anon/auto80_199_queue.cpp)
namespace n00321b48 {
/*TARGET 00321b48*/
void func_00321b48(u32 self) asm("_Z13func_00321b48j");
void func_00321b48(u32 self) {
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
}  // namespace n00321b48

// 00321bc8 (was src/anon/auto80_199_queue.cpp)
namespace n00321bc8 {
/*TARGET 00321bc8*/
void func_00321bc8(u32 self) asm("_Z13func_00321bc8j");
void func_00321bc8(u32 self) {
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
}  // namespace n00321bc8

// 00321c50 (was src/anon/auto200_999.cpp)
namespace n00321c50 {
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
/*TARGET 00321c50*/
// 003216c8: LIST<ATTRACT>::Remove, now made by gcc in src/anon/attractlist.cpp
void func_00321c50(u32 a0, u32 a1) asm("_Z13func_00321c50jj");
// 003216c8: LIST<ATTRACT>::Remove, now made by gcc in src/anon/attractlist.cpp
void func_00321c50(u32 a0, u32 a1) { UNLINK_BODY(40) }
}  // namespace n00321c50

// 00321cb0 (was src/anon/batch_w18.cpp)
namespace n00321cb0 {
struct Node321 { u8 pad[20]; Node321* next; };
u32 u_call4_00321cb0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_00321cb0jjjj");
/*TARGET 00321cb0*/
u32 u_call4_00321cb0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_00321cb0jjjj");
u32 u_call4_00321cb0(u32 a0, u32 a1, u32 a2, u32 a3) {
    Node321* n = 0;
    while ((n = !n ? *(Node321**)a0 : n->next) != 0) {
        if (n == (Node321*)a1) return 1;
    }
    return 0;
}
}  // namespace n00321cb0

// 00321ce8 (was src/anon/auto200_999.cpp)
namespace n00321ce8 {
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
/*TARGET 00321ce8*/
void func_00321ce8(u32 a0, u32 a1) asm("_Z13func_00321ce8jj");
void func_00321ce8(u32 a0, u32 a1) { UNLINK_BODY(96) }
}  // namespace n00321ce8

// 00321d48 (gap; copy of 0x0031a2f0, was src/anon/auto200_999.cpp)
namespace n00321d48 {
void func_00239870(u32) asm("_Z13func_00239870j");
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
static inline u32 addr_D_00347e60() { return (u32)&D_00347e60; }
static inline u32 addr_D_00347f98() { return (u32)&D_00347f98; }
/*TARGET 00321d48*/
// 0x002d0ef0: definition moved into src/anon/unit_002cf260.cpp

void func_00321d48(u32 self) asm("func_00321d48");
// 0x002d0ef0: definition moved into src/anon/unit_002cf260.cpp

void func_00321d48(u32 self) {
    u32 s16 = self;
    *(u32 *)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32 *)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32 *)(t + 20);
    Fn_00322908 fn = (Fn_00322908) * (u32 *)(*(u32 *)obj + 4);
    fn(obj, s16);
}
}  // namespace n00321d48

// 00321da8 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n00321da8 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 00321da8*/
u32 func_00321da8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00321da8jjjj");
u32 func_00321da8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n00321da8

// 00321de8 (was src/anon/auto80_199_queue.cpp)
namespace n00321de8 {
/*TARGET 00321de8*/
void func_00321de8(u32 self) asm("_Z13func_00321de8j");
void func_00321de8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e028();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321de8 fn = (Fn_00321de8)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}
}  // namespace n00321de8

// 00321e60 (was src/anon/auto80_199_queue.cpp)
namespace n00321e60 {
/*TARGET 00321e60*/
void func_00321e60(u32 self) asm("_Z13func_00321e60j");
void func_00321e60(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e028();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321e60_dtor fn = (Fn_00321e60_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00321e60_mgr fn2 = (Fn_00321e60_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}
}  // namespace n00321e60

// 00321ef8 (was src/anon/auto80_199_queue.cpp)
namespace n00321ef8 {
/*TARGET 00321ef8*/
void func_00321ef8(u32 self) asm("_Z13func_00321ef8j");
void func_00321ef8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e050();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321ef8 fn = (Fn_00321ef8)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}
}  // namespace n00321ef8

// 00321f70 (was src/anon/auto80_199_queue.cpp)
namespace n00321f70 {
/*TARGET 00321f70*/
void func_00321f70(u32 self) asm("_Z13func_00321f70j");
void func_00321f70(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e050();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321f70_dtor fn = (Fn_00321f70_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00321f70_mgr fn2 = (Fn_00321f70_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}
}  // namespace n00321f70

// 00322008 (was src/anon/auto80_199_queue.cpp)
namespace n00322008 {
/*TARGET 00322008*/
void func_00322008(u32 self) asm("_Z13func_00322008j");
void func_00322008(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e168();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2472;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322008 fn = (Fn_00322008)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}
}  // namespace n00322008

// 00322080 (was src/anon/auto80_199_queue.cpp)
namespace n00322080 {
/*TARGET 00322080*/
void func_00322080(u32 self) asm("_Z13func_00322080j");
void func_00322080(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e168();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2472;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322080_dtor fn = (Fn_00322080_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322080_mgr fn2 = (Fn_00322080_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}
}  // namespace n00322080

// 00322118 (was src/anon/auto80_199_queue.cpp)
namespace n00322118 {
/*TARGET 00322118*/
void func_00322118(u32 self) asm("_Z13func_00322118j");
void func_00322118(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e190();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2880;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322118_dtor fn = (Fn_00322118_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322118_mgr fn2 = (Fn_00322118_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}
}  // namespace n00322118

// 003221b0 (was src/anon/auto80_199_queue.cpp)
namespace n003221b0 {
/*TARGET 003221b0*/
void func_003221b0(u32 self) asm("_Z13func_003221b0j");
void func_003221b0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e190();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2880;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_003221b0 fn = (Fn_003221b0)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}
}  // namespace n003221b0

// 00322228 (was src/anon/batch_w90.cpp)
namespace n00322228 {
struct VObj { void** vt; };
// 0x0025d918: definition moved into src/anon/unit_002588e8.cpp

// 00265ab8: stop every active effect slot.
typedef void (*VoidFn)(void*);
extern u8 D_00347e60[] asm("D_00347e60");
// 0x002ed738: definition moved into src/anon/unit_002ecdb0.cpp

// 00322228: destructor body (member arrays destroyed back to front, then the base part).
struct NoTail2 { ~NoTail2() {} };
extern u8 D_0035e1b8[] asm("D_0035e1b8");
extern u8 D_00347f98[] asm("D_00347f98");
void func_00239870(void*) asm("func_00239870");
void func_0031a840(void*) asm("func_0031a840");
/*TARGET 00322228*/
void func_00322228(u8* self) asm("func_00322228");
void func_00322228(u8* self)
{
    NoTail2 g;
    u8* m = self + 2560;
    *(void**)self = D_0035e1b8;
    *(void**)m = D_00347e60;
    func_00239870(m + 24);
    *(void**)m = D_00347f98;
    if (self + 864) {
        u8* p = m;
    l1:
        if (self + 864 == p) goto d1;
        p -= 848;
        ((VoidFn)((VObj*)p)->vt[3])(p);
        goto l1;
    }
d1:
    if (self + 440) {
        u8* p = self + 440 + 412;
    l2:
        if (self + 440 == p) goto d2;
        p -= 412;
        ((VoidFn)((VObj*)p)->vt[3])(p);
        goto l2;
    }
d2:
    *(void**)self = D_00347e60;
    func_00239870(self + 24);
    func_0031a840(self);
}
}  // namespace n00322228

// 00322300 (was src/anon/batch_wcx2.cpp)
namespace n00322300 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
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
void func_00239870(u8*) asm("func_00239870");
// --------------------
struct AVt322300 { void* alloc; void (*free)(void* self, void* p); };
struct AO322300 { AVt322300* vt; };
struct H322300 { u8 pad[20]; AO322300* al; };
union HU322300 { H322300* h; u32 u; };
extern HU322300 D_00347f80_322300 asm("D_00347f80");
extern u8 D_0035e1b8_322300[] asm("D_0035e1b8");
extern u8 D_00347e60_322300[] asm("D_00347e60");
extern u8 D_00347f98_322300[] asm("D_00347f98");
struct EA322300;
struct EAVt322300 { void* p[3]; void (*dtor)(EA322300*); };
struct EA322300 { EAVt322300* vt; u8 pad[408]; };
struct EB322300;
struct EBVt322300 { void* p[3]; void (*dtor)(EB322300*); };
struct EB322300 { EBVt322300* vt; u8 pad[844]; };
struct X322300 { u32 vt; u8 pad[20]; u8 y[16]; };
struct O322300 { u32 vt; u8 pad[20]; u8 m24[416]; EA322300 a[1]; u8 p2[12]; EB322300 b[2]; X322300 x; };
void func_0031a840(O322300*) asm("func_0031a840");
/*TARGET 00322300*/
void func_00322300(O322300* o) asm("func_00322300");
void func_00322300(O322300* o)
{
    o->vt = (u32)D_0035e1b8_322300;
    X322300* x = &o->x;
    x->vt = (u32)D_00347e60_322300;
    func_00239870(x->y);
    x->vt = (u32)D_00347f98_322300;
    if ((u8*)o + 864 != 0) {
        EB322300* p = o->b + 2;
        EB322300* b = o->b;
        for (;;) { if (b == p) break; --p; p->vt->dtor(p); }
    }
    if ((u8*)o + 440 != 0) {
        EA322300* p = o->a + 1;
        EA322300* b = o->a;
        for (;;) { if (b == p) break; --p; p->vt->dtor(p); }
    }
    o->vt = (u32)D_00347e60_322300;
    func_00239870(o->m24);
    func_0031a840(o);
    AO322300* al = D_00347f80_322300.h->al;
    al->vt->free(al, o);
}
}  // namespace n00322300

// 003223f8 (gap; copy of 0x00105a10, was src/common/unit_003223f8.cpp)
namespace n003223f8 {
/*TARGET 003223f8*/
void func_003223f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003223f8");
void func_003223f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n003223f8

// 00322400 (gap; copy of 0x00105a10, was src/common/unit_00322400.cpp)
namespace n00322400 {
/*TARGET 00322400*/
void func_00322400(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00322400");
void func_00322400(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00322400

// 00322408 (gap; copy of 0x00105a10, was src/common/unit_00322408.cpp)
namespace n00322408 {
/*TARGET 00322408*/
void func_00322408(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00322408");
void func_00322408(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00322408

// 00322410 (gap; copy of 0x00105a10, was src/common/unit_00322410.cpp)
namespace n00322410 {
/*TARGET 00322410*/
void func_00322410(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00322410");
void func_00322410(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00322410

// 00322418 (was src/anon/batch_w256.cpp)
namespace n00322418 {
// 0x002da120: definition moved into src/anon/unit_002da040.cpp


void func_00239700(void*) asm("func_00239700");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035e1b8[] asm("D_0035e1b8");
extern u8 D_0034a958[] asm("D_0034a958");
extern u8 D_0035e280[] asm("D_0035e280");
void func_0031a838(void*) asm("func_0031a838");
void func_0013ee88(void*) asm("func_0013ee88");
void func_0014b668(void*) asm("func_0014b668");
/*TARGET 00322418*/
void func_00322418(u8* t) asm("func_00322418");
void func_00322418(u8* t) {
  *(u32*)t = (u32)D_00347f98; func_0031a838(t + 12);
  *(u32*)t = (u32)D_00347e60; func_00239700(t + 24);
  *(u32*)(t + 432) = 0; t[436] = 0; *(u32*)t = (u32)D_0035e1b8;
  u8* m = t + 440;
  *(u32*)m = (u32)D_00347f98; func_0031a838(m + 12);
  *(u32*)m = (u32)D_00347e60; func_00239700(m + 24);
  *(u32*)m = (u32)D_0034a958;
  u8* e = t + 864;
  for (s32 i = 1; i != -1; i--, e += 848) {
    *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
    *(u32*)e = (u32)D_0035e280; func_0013ee88(e + 32);
    func_0014b668(e + 320); func_0014b668(e + 576);
  }
  *(u32*)(t + 2572) = 0; *(u32*)(t + 2560) = (u32)D_00347e60; func_00239700(t + 2584);
}
}  // namespace n00322418

// 00322530 (gap)
namespace n00322530 {
typedef void (*DtorFn)(void*);
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035e238[] asm("D_0035e238");
void func_00239870(void*) asm("func_00239870");
void func_0031a840(void*) asm("func_0031a840");
/*TARGET 00322530*/
// Destructor (0x322608 is the deleting one).
void func_00322530(u8* p) asm("func_00322530");
void func_00322530(u8* p) {
    u8* q;
    *(u32*)p = (u32)D_0035e238;
    *(u32*)(p + 5072) = (u32)D_00347e60;
    q = p + 5072;
    func_00239870(p + 5096);
    *(u32*)(p + 5072) = (u32)D_00347f98;
    if (p + 1680 != 0) {
        u8* b = p + 1680;
    l1:
        if (b == q) goto d1;
        q -= 848;
        (*(DtorFn*)(*(u8**)q + 12))(q);
        goto l1;
    }
d1:
    if (p + 440 != 0) {
        u8* b;
        q = p + 1676;
        b = p + 440;
    l2:
        if (b == q) goto d2;
        q -= 412;
        (*(DtorFn*)(*(u8**)q + 12))(q);
        goto l2;
    }
d2:
    *(u32*)p = (u32)D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    u32 t = (u32)p;
    (void)t;
}
}  // namespace n00322530

// 00322608 (was src/anon/batch_w79.cpp)
namespace n00322608 {
typedef void (*DtorFn)(void*);
typedef void (*FreeFn)(void*, void*);
extern u8* D_00347f80 asm("D_00347f80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035e238[] asm("D_0035e238");
void func_00239870(void*) asm("func_00239870");
void func_0031a840(void*) asm("func_0031a840");
/*TARGET 00322608*/
// 0x002b6138: definition moved into src/anon/unit_002b60e8.cpp

// Deleting destructor: tears down the member arrays, then frees through the allocator.
void func_00322608(u8* p) asm("func_00322608");
// 0x002b6138: definition moved into src/anon/unit_002b60e8.cpp

// Deleting destructor: tears down the member arrays, then frees through the allocator.
void func_00322608(u8* p) {
    u8* q;
    u8* a;
    *(u32*)p = (u32)D_0035e238;
    *(u32*)(p + 5072) = (u32)D_00347e60;
    q = p + 5072;
    func_00239870(p + 5096);
    *(u32*)(p + 5072) = (u32)D_00347f98;
    if (p + 1680 != 0) {
        u8* b = p + 1680;
    l1:
        if (b == q) goto d1;
        q -= 848;
        (*(DtorFn*)(*(u8**)q + 12))(q);
        goto l1;
    }
d1:
    if (p + 440 != 0) {
        u8* b;
        q = p + 1676;
        b = p + 440;
    l2:
        if (b == q) goto d2;
        q -= 412;
        (*(DtorFn*)(*(u8**)q + 12))(q);
        goto l2;
    }
d2:
    *(u32*)p = (u32)D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    a = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)a + 4))(a, p);
}
}  // namespace n00322608

// 00322700 (gap; copy of 0x00105a10, was src/common/unit_00322700.cpp)
namespace n00322700 {
/*TARGET 00322700*/
void func_00322700(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00322700");
void func_00322700(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00322700

// 00322708 (gap; copy of 0x00105a10, was src/common/unit_00322708.cpp)
namespace n00322708 {
/*TARGET 00322708*/
void func_00322708(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00322708");
void func_00322708(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00322708

// 00322710 (gap)
namespace n00322710 {
struct AVt { void* alloc; void (*free)(void* self, void* p); };
struct AO { AVt* vt; };
struct H { u8 pad[20]; AO* al; };
union HU { H* h; u32 u; };
extern HU D_00347f80 asm("D_00347f80");
extern u8 D_00348698[] asm("D_00348698");
extern u8 D_00347f98[] asm("D_00347f98");
/*TARGET 00322710*/
void func_00322710(u8* p) asm("func_00322710");
void func_00322710(u8* p) {
    *(u8**)p = D_00347f98;
    *(u8**)(p + 576) = D_00348698;
    *(u8**)(p + 320) = D_00348698;
    *(u8**)(p + 32) = D_00348698;
    AO* al = D_00347f80.h->al;
    al->vt->free(al, p);
}
}  // namespace n00322710

// 00322768 (gap)
namespace n00322768 {
extern u8 D_00348698[] asm("D_00348698");
extern u8 D_00347f98[] asm("D_00347f98");
/*TARGET 00322768*/
void func_00322768(u8* p) asm("func_00322768");
void func_00322768(u8* p) {
    *(u8**)(p + 576) = D_00348698;
    *(u8**)(p + 320) = D_00348698;
    *(u8**)(p + 32) = D_00348698;
    *(u8**)p = D_00347f98;
}
}  // namespace n00322768

// 00322790 (was src/anon/batch_w443.cpp)
namespace n00322790 {
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035e238[] asm("D_0035e238");
extern u8 D_0034a958[] asm("D_0034a958");
extern u8 D_0035e280[] asm("D_0035e280");
void func_0031a838(void*) asm("func_0031a838");
void func_00239700(void*) asm("func_00239700");
void func_0013ee88(void*) asm("func_0013ee88");
void func_0014b668(void*) asm("func_0014b668");
/*TARGET 00322790*/
void func_00322790(u8* t) asm("func_00322790");
void func_00322790(u8* t) {
    u8* p;
    s32 i;
    *(u8**)t = D_00347f98;
    func_0031a838(t + 12);
    *(u8**)t = D_00347e60;
    func_00239700(t + 24);
    *(s32*)(t + 0x1b0) = 0;
    t[0x1b4] = 0;
    *(u8**)t = D_0035e238;
    p = t + 440;
    i = 2;
    do {
        *(u8**)p = D_00347f98;
        func_0031a838(p + 12);
        *(u8**)p = D_00347e60;
        func_00239700(p + 24);
        *(u8**)p = D_0034a958;
        i--;
        p += 412;
    } while (i != -1);
    p = t + 1680;
    i = 3;
    do {
        *(u8**)p = D_00347f98;
        func_0031a838(p + 12);
        *(u8**)p = D_0035e280;
        func_0013ee88(p + 32);
        func_0014b668(p + 320);
        func_0014b668(p + 576);
        i--;
        p += 848;
    } while (i != -1);
    *(s32*)(t + 0x13dc) = 0;
    *(u8**)(t + 0x13d0) = D_00347e60;
    func_00239700(t + 0x13e8);
}
}  // namespace n00322790

// 003228c8 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n003228c8 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 003228c8*/
u32 func_003228c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_003228c8jjjj");
u32 func_003228c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n003228c8

// 00322908 (was src/anon/auto80_199_queue.cpp)
namespace n00322908 {
/*TARGET 00322908*/
void func_00322908(u32 self) asm("_Z13func_00322908j");
void func_00322908(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32*)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322908 fn = (Fn_00322908)*(u32*)(*(u32*)obj + 4);
    fn(obj, s16);
}
}  // namespace n00322908

// 00322968 (was src/anon/batch_w2.cpp)
namespace n00322968 {
// 0x00308200: definition moved into src/sdk/libkernl_003081d0.c

typedef void (*VFn1)(void*);
/*TARGET 00322968*/
void func_00322968(void** o) asm("func_00322968");
void func_00322968(void** o) {
    ((VFn1*)*o)[5](o);
}
}  // namespace n00322968

// 00322990 (gap; copy of 0x00105a10, was src/common/unit_00322990.cpp)
namespace n00322990 {
/*TARGET 00322990*/
void func_00322990(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00322990");
void func_00322990(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00322990

// 00322998 (gap; copy of 0x00105a10, was src/common/unit_00322998.cpp)
namespace n00322998 {
/*TARGET 00322998*/
void func_00322998(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00322998");
void func_00322998(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00322998

// 003229a0 (was src/anon/auto80_199_queue.cpp)
namespace n003229a0 {
/*TARGET 003229a0*/
void func_003229a0(u32 self) asm("_Z13func_003229a0j");
void func_003229a0(u32 self) {
    u32 c0 = addr_D_0035e340();
    u32 c416 = addr_D_00347e80();
    *(u32*)(self + 416) = c416;
    *(u32*)self = c0;

    u32 s16 = self;
    func_002361d0(s16 + 448);

    u32 s17 = addr_D_00347f98();
    *(u32*)(s16 + 416) = s17;
    *(u32*)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32*)s16 = s17;
}
}  // namespace n003229a0

// 00322a10 (was src/anon/auto80_199_queue.cpp)
namespace n00322a10 {
/*TARGET 00322a10*/
void func_00322a10(u32 self) asm("_Z13func_00322a10j");
void func_00322a10(u32 self) {
    u32 c0 = addr_D_0035e340();
    u32 c416 = addr_D_00347e80();
    *(u32*)(self + 416) = c416;
    *(u32*)self = c0;

    u32 s16 = self;
    func_002361d0(s16 + 448);

    u32 s17 = addr_D_00347f98();
    *(u32*)(s16 + 416) = s17;
    *(u32*)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32*)s16 = s17;

    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322a10 fn = (Fn_00322a10)*(u32*)(*(u32*)obj + 4);
    fn(obj, s16);
}
}  // namespace n00322a10

// 00322a98 (was src/anon/auto80_199_queue.cpp)
namespace n00322a98 {
/*TARGET 00322a98*/
void func_00322a98(u32 self) asm("_Z13func_00322a98j");
void func_00322a98(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e320();

    if (s18 != (u32)-28) {
        u32 s16 = s18 + 1252;
        u32 s17 = s18 + 28;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322a98 fn = (Fn_00322a98)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}
}  // namespace n00322a98

// 00322b10 (was src/anon/auto80_199_queue.cpp)
namespace n00322b10 {
/*TARGET 00322b10*/
void func_00322b10(u32 self) asm("_Z13func_00322b10j");
void func_00322b10(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e320();

    if (s18 != (u32)-28) {
        u32 s16 = s18 + 1252;
        u32 s17 = s18 + 28;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322b10_dtor fn = (Fn_00322b10_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322b10_mgr fn2 = (Fn_00322b10_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}
}  // namespace n00322b10

// 00322ba8 (was src/anon/batch_w19.cpp)
namespace n00322ba8 {
u8 func_00108698(void*) asm("func_00108698");
u8 func_001ddd10(void*) asm("func_001ddd10");
/*TARGET 00322ba8*/
u32 func_00322ba8(u8* p) asm("func_00322ba8");
u32 func_00322ba8(u8* p) {
    func_00108698(p + 56);
    return func_001ddd10(p + 192);
}
}  // namespace n00322ba8

// 00322be0 (was src/anon/batch_w66.cpp)
namespace n00322be0 {
void func_0023d7c8(void*) asm("func_0023d7c8");
void func_001ddd88(void*) asm("func_001ddd88");
void func_001070e8(void*) asm("func_001070e8");
void func_00106ac8(void*) asm("func_00106ac8");
extern void* D_00347f98[] asm("D_00347f98");
extern void* D_0035eb60[] asm("D_0035eb60");
extern void* D_00348698[] asm("D_00348698");
struct Base31 { u32 vt; ~Base31() { *(void**)this = D_00347f98; } };
struct E320 { u8 pad[192]; u8 m[128]; ~E320() { func_001ddd88(m); } };
struct E400 { u8 pad[256]; u8 m[144]; ~E400() { func_001070e8(m); func_00106ac8(this); } };
struct M784 { u32 vt; u8 pad[780]; ~M784() { *(void**)this = D_00348698; } };
struct Obj322 : Base31 {
    u8 pad[28];
    E400 a[4];
    E320 b[4];
    u8 pad2[32];
    M784 m0;
    M784 m1;
    M784 m2;
    ~Obj322() { *(void**)this = D_0035eb60; func_0023d7c8(this); }
};
/*TARGET 00322be0*/
void func_00322be0(Obj322* p) asm("func_00322be0");
void func_00322be0(Obj322* p) { p->~Obj322(); }
}  // namespace n00322be0

// 00322c98 (was src/anon/batch_wcx2.cpp)
namespace n00322c98 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
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
void func_001ddd88(u8*) asm("func_001ddd88");
// --------------------
struct AVt322c98 { void* alloc; void (*free)(void* self, void* p); };
struct AO322c98 { AVt322c98* vt; };
struct H322c98 { u8 pad[20]; AO322c98* al; };
union HU322c98 { H322c98* h; u32 u; };
extern HU322c98 D_00347f80_322c98 asm("D_00347f80");
extern u8 D_0035eb60_322c98[] asm("D_0035eb60");
extern u8 D_00348698_322c98[] asm("D_00348698");
extern u8 D_00347f98_322c98[] asm("D_00347f98");
void func_0023d7c8(void*) asm("func_0023d7c8");
void func_001070e8(u8*) asm("func_001070e8");
void func_00106ac8(void*) asm("func_00106ac8");
struct EA322c98 { u8 pad[256]; u8 m[144]; };
struct EB322c98 { u8 pad[192]; u8 m[128]; };
struct O322c98 { u32 vt; u8 pad4[28]; EA322c98 a[4]; EB322c98 b[4]; u8 pad2[32]; u32 v1; u8 p1[780]; u32 v2; u8 p2[780]; u32 v3; };
static inline __attribute__((always_inline)) void DelB322c98(O322c98* o)
{
    if ((u8*)o + 1632 != 0) {
        EB322c98* p = o->b + 4;
        EB322c98* b = o->b;
        for (;;) {
            if (b == p) break;
            --p;
            func_001ddd88(p->m);
        }
    }
}
static inline __attribute__((always_inline)) void DelA322c98(O322c98* o)
{
    if ((u8*)o + 32 != 0) {
        EA322c98* p = o->a + 4;
        EA322c98* b = o->a;
        for (;;) {
            if (b == p) break;
            --p;
            func_001070e8(p->m);
            func_00106ac8(p);
        }
    }
}
/*TARGET 00322c98*/
void func_00322c98(O322c98* o) asm("func_00322c98");
void func_00322c98(O322c98* o)
{
    o->vt = (u32)D_0035eb60_322c98;
    func_0023d7c8(o);
    o->v3 = (u32)D_00348698_322c98;
    o->v2 = (u32)D_00348698_322c98;
    o->v1 = (u32)D_00348698_322c98;
    DelB322c98(o);
    DelA322c98(o);
    o->vt = (u32)D_00347f98_322c98;
    AO322c98* al = D_00347f80_322c98.h->al;
    al->vt->free(al, o);
}
}  // namespace n00322c98

// 00322d70 (was src/anon/batch_w32.cpp)
namespace n00322d70 {
extern void* D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
void func_0023c098(void*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(void*) asm("func_002369f0");
/*TARGET 00322d70*/
void func_00322d70(void** p) asm("func_00322d70");
void func_00322d70(void** p) {
    p[0] = D_0035eb98;
    func_0023c098((u8*)p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0((u8*)p + 24);  // set_vtbl_36eac8_then_call
    p[0] = D_00347f98;
}
}  // namespace n00322d70

// 00322db8 (was src/anon/batch_w30.cpp)
namespace n00322db8 {
extern void* D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
void func_0023c098(void*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(void*) asm("func_002369f0");
// set_vtbl_36eac8_then_call
void func_0023ee68(void*) asm("func_0023ee68");
/*TARGET 00322db8*/
void func_00322db8(u8* p) asm("func_00322db8");
void func_00322db8(u8* p) {
    *(void**)p = D_0035eb98;
    func_0023c098(p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 24);  // set_vtbl_36eac8_then_call
    *(void**)p = D_00347f98;
    func_0023ee68(p);
}
}  // namespace n00322db8

// 00322e08 (gap; copy of 0x0031a840, was src/anon/tiny.cpp)
namespace n00322e08 {
extern u32 D_00347f98 asm("D_00347f98");
/*TARGET 00322e08*/
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_00322e08(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00322e08");
// 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_00322e08(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347f98;
}
}  // namespace n00322e08

// 00322e18 (was src/anon/batch_w35.cpp)
namespace n00322e18 {
extern void* D_00347f98[] asm("D_00347f98");
extern void*** D_00347f80 asm("D_00347f80");
typedef void (*VFn2)(void*, void*);
/*TARGET 00322e18*/
void func_00322e18(u8* p) asm("func_00322e18");
void func_00322e18(u8* p) {
    *(void***)p = D_00347f98;
    void** o = (void**)D_00347f80[5];
    ((VFn2)((void**)*o)[1])(o, p);
}
}  // namespace n00322e18

// 00322e58 (was src/anon/batch_w1628.cpp)
namespace n00322e58 {
void func_00239700(void*) asm("func_00239700");
void func_0031a838(void*) asm("func_0031a838");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
// --------------------
// 00322e58: constructor of an object made of six 436-byte elements followed by
// sixteen 408-byte elements. Element constructors written out inline:
//   Elem436: 00347f98 base (func_0031a838 at +12) -> vt 00347e60 (func_00239700 at +24)
//            -> vt 00347e40, word at +408 cleared
//   Elem408: vt 00347e60, word at +12 cleared, func_00239700 at +24
extern u8 D_00347e40[] asm("D_00347e40");
static inline __attribute__((always_inline)) void W1628_ctor436(u8* e)
{
    *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
    *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
    *(u32*)(e + 408) = 0; *(u32*)e = (u32)D_00347e40;
}
/*TARGET 00322e58*/
void func_00322e58(u8* t) asm("func_00322e58");
void func_00322e58(u8* t)
{
    u8* m = t + 436;
    W1628_ctor436(t);
    W1628_ctor436(m);
    {
        u8* e = m + 436;
        s32 i = 3;
        for (; i != -1; i--, e += 436) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
        }
    }
    {
        u8* e = t + 2616;
        s32 i = 3;
        for (; i != -1; i--, e += 436) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
        }
    }
    {
        u8* e = t + 4360;
        s32 i = 3;
        for (; i != -1; i--, e += 436) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
        }
    }
    {
        u8* e = t + 6104;
        s32 i = 3;
        for (; i != -1; i--, e += 436) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
        }
    }
    {
        u8* e = t + 7848;
        s32 i = 3;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 9480;
        s32 i = 3;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 11112;
        s32 i = 3;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 12744;
        s32 i = 3;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
}
}  // namespace n00322e58

// 00323110 (was src/anon/batch_w2417_nsa.cpp)
namespace n00323110 {
// 00323110: constructor of a large object (same family as 00322e58/00324510/003241a0):
// 4 x A (408 bytes), 4 x B (436 bytes), 3 x B[24], A[24], then a T of 3 B at +0xb350.
// The base-class vtable store (00347f98) is a plain void* store, the h0..h3 blocks share one
// loaded vtable address. Needs -fno-strict-aliasing.
extern "C" u8 D_00347e60[] asm("D_00347e60");
extern "C" u8 D_00347f98[] asm("D_00347f98");
extern "C" u8 D_00347e40[] asm("D_00347e40");
void func_00239700(void*) asm("func_00239700");
void func_0031a838(void*) asm("func_0031a838");
inline void* operator new(unsigned int, void* p) { return p; }
inline void* operator new[](unsigned int, void* p) { return p; }
struct W2417_A {
    void* vt; u8 p4[8]; u32 f0c; u8 p10[8]; u8 m[384];
    W2417_A() { f0c = 0; vt = D_00347e60; func_00239700(m); }
};
struct W2417_B {
    void* vt; u8 p4[8]; u8 m0c[12]; u8 m[384]; u32 f198; u8 pad[24];
    W2417_B() { *(void**)this = D_00347f98; func_0031a838(m0c); vt = D_00347e60; func_00239700(m); vt = D_00347e40; f198 = 0; }
};
struct W2417_T { W2417_B b0, b1, b2; };
struct W2417_Big {
    W2417_A a0, a1, a2, a3;
    W2417_B h0, h1, h2, h3;
    W2417_B x[24]; W2417_B y[24]; W2417_B z[24];
    W2417_A w[24];
    u8 gap[1344];
    W2417_T p;
};
/*TARGET 00323110*/
void func_00323110(W2417_Big* p) asm("func_00323110");
void func_00323110(W2417_Big* p)
{
    void* va = D_00347f98;
    new (&p->a0) W2417_A; new (&p->a1) W2417_A; new (&p->a2) W2417_A; new (&p->a3) W2417_A;
    { W2417_B* h = &p->h0; *(void**)h = va; func_0031a838(h->m0c); h->vt = D_00347e60; func_00239700(h->m); h->vt = D_00347e40; h->f198 = 0; }
    { W2417_B* h = &p->h1; *(void**)h = va; func_0031a838(h->m0c); h->vt = D_00347e60; func_00239700(h->m); h->vt = D_00347e40; h->f198 = 0; }
    { W2417_B* h = &p->h2; *(void**)h = va; func_0031a838(h->m0c); h->vt = D_00347e60; func_00239700(h->m); h->vt = D_00347e40; h->f198 = 0; }
    { W2417_B* h = &p->h3; *(void**)h = va; func_0031a838(h->m0c); h->vt = D_00347e60; func_00239700(h->m); h->vt = D_00347e40; h->f198 = 0; }
    new (p->x) W2417_B[24]; new (p->y) W2417_B[24]; new (p->z) W2417_B[24]; new (p->w) W2417_A[24];
    new (&p->p) W2417_T;
}
}  // namespace n00323110

// 00323408 (was src/anon/batch_w263.cpp)
namespace n00323408 {
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e40[] asm("D_00347e40");
void func_00239700(void*) asm("func_00239700");
void func_0031a838(void*) asm("func_0031a838");
struct W263A {
    u8* vt; u32 f4, f8, f12, f16, f20; u8 m24[384];
    W263A() { f12 = 0; vt = D_00347e60; func_00239700(m24); }
};
struct W263B {
    u8* vt; u32 f4, f8; u8 m12[12]; u8 m24[384]; u32 f408; u8 pad[24];
    W263B() {
        vt = D_00347f98; func_0031a838(m12);
        vt = D_00347e60; func_00239700(m24);
        vt = D_00347e40; f408 = 0;
    }
};
struct W263S : W263A {
    W263A a[4]; W263B b[4]; u8 pad[32]; W263B c[5];
    inline W263S() __attribute__((always_inline));
};
inline W263S::W263S() {}
inline void* operator new(unsigned int, void* p) { return p; }
/*TARGET 00323408*/
void func_00323408(W263S* p) asm("func_00323408");
void func_00323408(W263S* p) { new (p) W263S; }
}  // namespace n00323408

// 00323540 (was src/anon/batch_w2505b_nsa.cpp)
namespace n00323540 {
void func_0031a838(void*) asm("func_0031a838");
void func_00239700(void*) asm("func_00239700");
void W2505_ImageCtor(void*) asm("_ZN2YI5IMAGEC1Ev");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
static inline __attribute__((always_inline)) void H436(u8* e, u32 a, u32 b)
{
    *(u32*)e = a; func_0031a838(e + 12);
    *(u32*)e = b; func_00239700(e + 24);
    *(u32*)(e + 408) = 0; *(volatile u32*)e = (u32)D_00347e40;
}
static inline __attribute__((always_inline)) void H436b(u8* e, u32 a, u32 b)
{
    *(volatile u32*)e = a; func_0031a838(e + 12);
    *(u32*)e = b; func_00239700(e + 24);
    *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
}
static inline __attribute__((always_inline)) void H408(u8* e, u32 b)
{
    *(u32*)(e + 12) = 0; *(u32*)e = b; func_00239700(e + 24);
}
static inline __attribute__((always_inline)) void L408(u8* q)
{
    s32 i = 31; do { *(u32*)(q + 12) = 0; *(u32*)q = (u32)D_00347e60; func_00239700(q + 24); i--; q += 408; } while (i != -1);
}
/*TARGET 00323540*/
void func_00323540(u8* p) asm("func_00323540");
void func_00323540(u8* p) {
    u32 vb = (u32)D_00347e60; u32 va = (u32)D_00347f98;
    H408(p, vb); H408(p + 408, vb); H408(p + 816, vb); H408(p + 1224, vb);
    H436(p + 1632, va, vb); H436(p + 2068, va, vb); H436(p + 2504, va, vb);
    H436(p + 2940, va, vb); H436(p + 3376, va, vb); H436b(p + 3812, va, vb);
    L408(p + 4248); L408(p + 17304); L408(p + 30360); L408(p + 43416);
    { u8* q = p + 56480; s32 i = 31; do { W2505_ImageCtor(q); i--; q += 416; } while (i != -1); }
}
}  // namespace n00323540

// 003237e0 (was src/anon/batch_w1571.cpp)
namespace n003237e0 {
void func_0031a838(void*) asm("func_0031a838");
void func_00239700(void*) asm("func_00239700");
extern u8 D_00347e40[] asm("D_00347e40");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
static inline void c3237e0_A(u8* p) { *(void**)p = D_00347f98; func_0031a838(p + 0xc); }
static inline void cB(u8* p) { c3237e0_A(p); *(void**)p = D_00347e60; func_00239700(p + 0x18); }
static inline void cC(u8* p) { cB(p); *(void**)p = D_00347e40; *(u32*)(p + 0x198) = 0; }
static inline void cD(u8* p) { *(u32*)(p + 0xc) = 0; *(void**)p = D_00347e60; func_00239700(p + 0x18); }
/*TARGET 003237e0*/
void func_003237e0(u8* p) asm("func_003237e0");
void func_003237e0(u8* p) {
    cC(p);
    cD(p + 0x1b4);
    { u8* q = p + 0x34c; s32 i = 1; do { cD(q); i--; q += 0x198; } while (i != -1); }
    { u8* q = p + 0x67c; s32 i = 1; do { cD(q); i--; q += 0x198; } while (i != -1); }
    { u8* q = p + 0x9ac; s32 i = 2; do { cC(q); i--; q += 0x1b4; } while (i != -1); }
    { u8* q = p + 0xec8; s32 i = 2; do { cC(q); i--; q += 0x1b4; } while (i != -1); }
}
}  // namespace n003237e0
