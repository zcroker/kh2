// Linked unit 0x00324808: linkonce (template) copies of game code that the linker gathered after the
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


// 00324808 (was src/anon/auto80_199_queue.cpp)
namespace n00324808 {
/*TARGET 00324808*/
void func_00324808(u32 self) asm("_Z13func_00324808j");
void func_00324808(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s2 + 2568);  // array8_free_slots
    func_001c0248(s2 + 2640);
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}
}  // namespace n00324808

// 00324898 (was src/anon/auto80_199_queue.cpp)
namespace n00324898 {
/*TARGET 00324898*/
u32 func_00324898(u32 self) asm("_Z13func_00324898j");
u32 func_00324898(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_0034ee08();
    YS__OBJ_ATTACK__clear(s2 + 2568);  // array8_free_slots
    func_001c0248(s2 + 2640);
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}
}  // namespace n00324898

// 00324930 (gap; copy of 0x00105a10, was src/common/unit_00324930.cpp)
namespace n00324930 {
/*TARGET 00324930*/
void func_00324930(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00324930");
void func_00324930(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00324930

// 00324938 (was src/anon/batch_w32.cpp)
namespace n00324938 {
// set_vtbl_36eac8_then_call
extern u8 D_0034ee08[] asm("D_0034ee08");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
/*TARGET 00324938*/
s32 func_00324938(void** p) asm("func_00324938");
s32 func_00324938(void** p) {
    p[0] = D_0034ee08;
    YS__OBJ_ATTACK__clear((u8*)p + 0xa08);  // array8_free_slots
    func_001c0248((u8*)p + 0xa50);
    return func_00319fb0(p);  // big_obj_dtor
}
}  // namespace n00324938

// 00324980 (was src/anon/batch_w33.cpp)
namespace n00324980 {
void func_00105110(void*) asm("func_00105110");
extern void* D_0034ee08[] asm("D_0034ee08");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
/*TARGET 00324980*/
// big_obj_dtor
void func_00324980(u8* p) asm("func_00324980");
// big_obj_dtor
void func_00324980(u8* p) {
    *(void**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}  // namespace n00324980

// 003249c8 (gap)
namespace n003249c8 {
extern u8 D_00361a60[] asm("D_00361a60");
extern u8 D_00361da8[] asm("D_00361da8");
struct E324a30 { u8 pad[16]; ~E324a30() {} } __attribute__((aligned(16)));
struct B324a30 { u32 vt; ~B324a30() { vt = (u32)D_00361da8; } };
struct O324a30 : B324a30 {
    u8 pad[0x6c];
    E324a30 a[4];
    E324a30 b[2];
    ~O324a30() { vt = (u32)D_00361a60; }
};
/*TARGET 003249c8*/
// Destructor (0x324a30 is the deleting one).
void func_003249c8(O324a30* p) asm("func_003249c8");
void func_003249c8(O324a30* p) { p->~O324a30(); }
}  // namespace n003249c8

// 00324a30 (was src/anon/batch_w1551.cpp)
namespace n00324a30 {
extern u8 D_00361a60[] asm("D_00361a60");
extern u8 D_00361da8[] asm("D_00361da8");
void func_00105110(void*) asm("func_00105110");
struct E324a30 { u8 pad[16]; ~E324a30() {} } __attribute__((aligned(16)));
struct B324a30 { u32 vt; ~B324a30() { vt = (u32)D_00361da8; } };
struct O324a30 : B324a30 {
    u8 pad[0x6c];
    E324a30 a[4];
    E324a30 b[2];
    ~O324a30() { vt = (u32)D_00361a60; }
};
/*TARGET 00324a30*/
// 0x002cb678: definition moved into src/taito/path.cpp

// Deleting destructor.
void func_00324a30(O324a30* p) asm("func_00324a30");
// 0x002cb678: definition moved into src/taito/path.cpp

// Deleting destructor.
void func_00324a30(O324a30* p) {
    p->~O324a30();
    func_00105110(p);
}
}  // namespace n00324a30

// 00324ac0 (gap; copy of 0x002cff98, was src/anon/unit_002cf260.cpp)
namespace n00324ac0 {
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
u8 func_00319fb0(void*) asm("func_00319fb0");
extern u8 D_0034ee08[] asm("D_0034ee08");
/*TARGET 00324ac0*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00324ac0(u8* o) asm("func_00324ac0");
/*TARGET 00324ac0*/
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00324ac0(u8* o) asm("func_00324ac0");
// 0x002beea8: definition moved into src/anon/unit_002bebd0.cpp

u8 func_00324ac0(u8* o) {
    *(u8**)o = D_0034ee08;
    YS__OBJ_ATTACK__clear(o + 2568);  // array8_free_slots
    func_001c0248(o + 2640);
    return func_00319fb0(o);  // big_obj_dtor
}
}  // namespace n00324ac0

// 00324b08 (was src/anon/batch_w34.cpp)
namespace n00324b08 {
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
// array8_free_slots
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
// big_obj_dtor
void func_00105110(void*) asm("func_00105110");
extern void* D_0034ee08[] asm("D_0034ee08");
/*TARGET 00324b08*/
void func_00324b08(void** p) asm("func_00324b08");
void func_00324b08(void** p) {
    *p = D_0034ee08;
    YS__OBJ_ATTACK__clear((u8*)p + 2568);  // array8_free_slots
    func_001c0248((u8*)p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}  // namespace n00324b08

// 00324b50 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00324b50 {
u32 func_002eec58(u32, u32, u32, u32) asm("_Z13func_002eec58jjjj");
extern u8 D_00361bf0 asm("D_00361bf0");
/*TARGET 00324b50*/
u32 func_00324b50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00324b50jjjj");
u32 func_00324b50(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00361bf0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002eec58)(u32, u32, u32, u32) = func_002eec58;
    r2 = fp_call4_002eec58(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00324b50

// 00324b78 (was src/anon/batch_w21.cpp)
namespace n00324b78 {
void func_00105110(void*) asm("func_00105110");
void func_002eec58(void*) asm("func_002eec58");
extern u32 D_00361bf0 asm("D_00361bf0");
void worldmap_ObjWidget_D0(void**) asm("_ZN8worldmap9ObjWidgetD0Ev");
/*TARGET 00324b78*/
void worldmap_ObjWidget_D0(void** p) asm("_ZN8worldmap9ObjWidgetD0Ev");
void worldmap_ObjWidget_D0(void** p) {
    *p = &D_00361bf0;
    func_002eec58(p);
    func_00105110(p);
}
}  // namespace n00324b78

// 00324bb0 (gap)
namespace n00324bb0 {
/*TARGET 00324bb0*/
u32 func_00324bb0(u32 a, u32* b) asm("func_00324bb0");
u32 func_00324bb0(u32 a, u32* b) { a -= *b; return a; }
}  // namespace n00324bb0

// 00324bc0 (was src/anon/batch_wcx2.cpp)
namespace n00324bc0 {
// 0x00145830: definition moved into src/anon/unit_00145600.cpp

// --------------------
// Copy constructor: base part, vtable, then the member data.
union W324bc0 { s32 v; u8 c; };
struct Obj324bc0 {
    u32 vt;
    u8 pad4[172];
    s32 f176;
    s32 f180;
    W324bc0 a184[13];
    s32 f236;
    s32 f240;
    s32 f244;
    s32 f248;
    s32 f252;
    f32 f256;
    f32 f260;
    f32 f264;
    s32 f268;
    s32 f272;
    s32 f276;
    f32 f280;
    f32 f284;
    f32 f288;
    f32 f292;
    f32 f296;
    f32 f300;
    f32 f304;
    f32 f308;
    f32 f312;
    f32 f316;
    s32 f320;
    s32 f324;
    s32 f328;
    s32 f332;
    s32 f336;
    s32 f340;
};
extern u8 D_0035eaf8[] asm("D_0035eaf8");
void func_00324d50(Obj324bc0* d, Obj324bc0* s) asm("func_00324d50");
/*TARGET 00324bc0*/
void func_00324bc0(Obj324bc0* d, Obj324bc0* s) asm("func_00324bc0");
void func_00324bc0(Obj324bc0* d, Obj324bc0* s)
{
    func_00324d50(d, s);
    d->vt = (u32)D_0035eaf8;
    d->f176 = s->f176;
    d->f180 = s->f180;
    d->a184[0].v = s->a184[0].v;
    d->a184[1].v = s->a184[1].v;
    d->a184[2].v = s->a184[2].v;
    d->a184[3].v = s->a184[3].v;
    d->a184[4].v = s->a184[4].v;
    d->a184[5].v = s->a184[5].v;
    d->a184[6].v = s->a184[6].v;
    d->a184[7].v = s->a184[7].v;
    d->a184[8].v = s->a184[8].v;
    d->a184[9].v = s->a184[9].v;
    d->a184[10].v = s->a184[10].v;
    d->a184[11].v = s->a184[11].v;
    d->a184[12].v = s->a184[12].v;
    d->f236 = s->f236;
    d->f240 = s->f240;
    d->f244 = s->f244;
    d->f248 = s->f248;
    d->f252 = s->f252;
    d->f256 = s->f256;
    d->f260 = s->f260;
    d->f264 = s->f264;
    d->f268 = s->f268;
    d->f272 = s->f272;
    d->f276 = s->f276;
    d->f280 = s->f280;
    d->f284 = s->f284;
    d->f288 = s->f288;
    d->f292 = s->f292;
    d->f296 = s->f296;
    d->f300 = s->f300;
    d->f304 = s->f304;
    d->f308 = s->f308;
    d->f312 = s->f312;
    d->f316 = s->f316;
    d->f320 = s->f320;
    d->f324 = s->f324;
    d->f328 = s->f328;
    d->f332 = s->f332;
    d->f336 = s->f336;
    d->f340 = s->f340;
}
}  // namespace n00324bc0

// 00324d50 (was src/anon/perm_00324d50_nsa.cpp)
namespace n00324d50 {
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
struct S3
{
  s32 a;
  s32 b;
  s32 c;
};
struct S4
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
};
struct F2
{
  f32 x;
  f32 y;
};
struct F7
{
  f32 a;
  f32 b;
  f32 c;
  f32 d;
  f32 e;
  f32 f;
  f32 g;
};
struct T9
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
  s32 f;
  s32 g;
  s32 h;
  s32 i;
};
struct Q8
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  s32 e;
  s32 f;
  s32 g;
  s32 h;
};
struct Obj
{
  void *vptr;
  S3 m4;
  S3 b16;
  S3 b28;
  S3 b40;
  S4 m52;
  f32 m68;
  F2 m72;
  S3 b80;
  S3 b92;
  s32 m104;
  F7 m108;
  s32 m136;
  T9 m140;
};
extern u8 D_0035eae8 asm("D_0035eae8");
/*TARGET 00324d50*/
void func_00324d50(Obj *d, const Obj *s) asm("func_00324d50");
void func_00324d50(Obj *d, const Obj *s)
{
  d->vptr = &D_0035eae8;
  d->m4.a = s->m4.a;
  d->m4.b = s->m4.b;
  d->m4.c = s->m4.c;
  d->b16 = s->b16;
  d->b28 = s->b28;
  d->b40 = s->b40;
  d->m52.a = s->m52.a;
  d->m52.b = s->m52.b;
 do { d->m52.c = s->m52.c; d->m52.d = s->m52.d; d->m68 = s->m68; d->m72.x = s->m72.x; d->m72.y = s->m72.y; d->b80 = s->b80; d->b92 = s->b92; } while (0);
  d->m104 = s->m104;
  d->m108.a = s->m108.a;
  d->m108.b = s->m108.b;
  d->m108.c = s->m108.c;
  d->m108.d = s->m108.d;
  d->m108.e = s->m108.e;
  d->m108.f = s->m108.f;
  d->m108.g = s->m108.g;
  d->m136 = s->m136;
  ((Q8 *) (&d->m140))->f = ((const Q8 *) (&s->m140))->f;
  ((Q8 *) (&d->m140))->h = ((const Q8 *) (&s->m140))->h;
  (&d->m140)->a = ((const Q8 *) (&s->m140))->a;
  d->m140.b = s->m140.b;
  d->m140.c = s->m140.c;
  d->m140.d = s->m140.d;
  d->m140.e = s->m140.e;
  d->m140.g = s->m140.g;
  d->m140.i = s->m140.i;
}
}  // namespace n00324d50

// 00324eb8 (was src/anon/auto80_199_queue.cpp)
namespace n00324eb8 {
/*TARGET 00324eb8*/
void func_00324eb8(u32 self) asm("_Z13func_00324eb8j");
void func_00324eb8(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}
}  // namespace n00324eb8

// 00324f38 (was src/anon/auto80_199_queue.cpp)
namespace n00324f38 {
/*TARGET 00324f38*/
u32 func_00324f38(u32 self) asm("_Z13func_00324f38j");
u32 func_00324f38(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}
}  // namespace n00324f38

// 00324fc0 (gap; copy of 0x00319fb0, was src/anon/auto200_999.cpp)
namespace n00324fc0 {
void func_001b0188(u32) asm("_Z13func_001b0188j");
void func_001d5718(u32) asm("_Z13func_001d5718j");
void func_0016a358(u32) asm("_Z13func_0016a358j");
extern u32 D_003503e0 asm("D_003503e0");
extern u32 D_00350e48 asm("D_00350e48");
static inline u32 addr_D_003503e0() { return (u32)&D_003503e0; }
static inline u32 addr_D_00350e48() { return (u32)&D_00350e48; }
/*TARGET 00324fc0*/
void func_00324fc0(u32 self) asm("func_00324fc0");
void func_00324fc0(u32 self) {  // big_obj_dtor
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
}  // namespace n00324fc0

// 00325040 (was src/anon/auto80_199_queue.cpp)
namespace n00325040 {
/*TARGET 00325040*/
u32 func_00325040(u32 self) asm("_Z13func_00325040j");
u32 func_00325040(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}
}  // namespace n00325040

// 003250c8 (gap)
namespace n003250c8 {
struct E_25158 { u8 d[16]; ~E_25158() {} } __attribute__((aligned(16)));
struct H_25158 { E_25158 a[4]; };
extern u32 D_00361d00 asm("D_00361d00");
extern u32 D_0034e8b8 asm("D_0034e8b8");
extern u32 D_0034ee08 asm("D_0034ee08");
void func_00319f88(void*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
/*TARGET 003250c8*/
// Destructor (0x325158 is the deleting one).
void func_003250c8(u8* p) asm("func_003250c8");
void func_003250c8(u8* p) {
    *(u32**)p = &D_00361d00;
    ((H_25158*)(p + 0xb70))->~H_25158();
    *(u32**)p = &D_0034e8b8;
    func_00319f88(p + 0xb08);
    *(u32**)p = &D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 0xa08);
    func_001c0248(p + 0xa50);
    func_00319fb0(p);
    u32 t = (u32)p;
    (void)t;
}
}  // namespace n003250c8

// 00325158 (was src/anon/batch_w1552.cpp)
namespace n00325158 {
struct E_25158 { u8 d[16]; ~E_25158() {} } __attribute__((aligned(16)));
struct H_25158 { E_25158 a[4]; };
// 0x003147a0: definition moved into src/libgcc/_unpack_df.c

extern u32 D_00361d00 asm("D_00361d00");
extern u32 D_0034e8b8 asm("D_0034e8b8");
extern u32 D_0034ee08 asm("D_0034ee08");
void func_00319f88(void*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
void AREA_Free_25158(void*) asm("_ZN4AREA4FreeEPv");
/*TARGET 00325158*/
void func_00325158(u8* p) asm("func_00325158");
void func_00325158(u8* p) {
    *(u32**)p = &D_00361d00;
    ((H_25158*)(p + 0xb70))->~H_25158();
    *(u32**)p = &D_0034e8b8;
    func_00319f88(p + 0xb08);
    *(u32**)p = &D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 0xa08);
    func_001c0248(p + 0xa50);
    func_00319fb0(p);
    AREA_Free_25158(p);
}
}  // namespace n00325158

// 003251e8 (gap; copy of 0x002361d0, was src/anon/unit_00236180.cpp)
namespace n003251e8 {
extern u32 D_00361da8 asm("D_00361da8");
/*TARGET 003251e8*/
// YI::IMAGE::~IMAGE
void func_003251e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003251e8");
/*TARGET 003251e8*/
// YI::IMAGE::~IMAGE
void func_003251e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003251e8");
// YI::IMAGE::~IMAGE
void func_003251e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00361da8;
}
}  // namespace n003251e8

// 003251f8 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n003251f8 {
u32 func_00105110(u32, u32, u32, u32) asm("_Z13func_00105110jjjj");
extern u8 D_00361da8 asm("D_00361da8");
/*TARGET 003251f8*/
u32 func_003251f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_003251f8jjjj");
u32 func_003251f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00361da8);
    return func_00105110(a0, a1, a2, a3);
}
}  // namespace n003251f8

// 00325218 (was src/anon/auto80_199_queue.cpp)
namespace n00325218 {
/*TARGET 00325218*/
void func_00325218(u32 self) asm("_Z13func_00325218j");
void func_00325218(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}
}  // namespace n00325218

// 00325298 (was src/anon/auto80_199_queue.cpp)
namespace n00325298 {
/*TARGET 00325298*/
u32 func_00325298(u32 self) asm("_Z13func_00325298j");
u32 func_00325298(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}
}  // namespace n00325298

// 00325320 (was src/anon/auto80_199_queue.cpp)
namespace n00325320 {
/*TARGET 00325320*/
void func_00325320(u32 a0, u32 a1) asm("_Z13func_00325320jj");
void func_00325320(u32 a0, u32 a1) {  // list_remove_by_ptr
    u32 t7 = *(u32*)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32*)(a1 + 148);
        t5 = 0;
        *(u32*)a0 = t7n;
    } else {
        u32 t6 = *(u32*)(t7 + 148);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32*)(t6 + 148);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32*)(a1 + 148);
        *(u32*)(t5 + 148) = t7n;
    }

    u32 t7c = *(u32*)(a0 + 4);
    if (a1 == t7c) {
        *(u32*)(a0 + 4) = t5;
    }
    *(u32*)(a1 + 148) = 0;
}
}  // namespace n00325320

// 00325380 (gap; copy of 0x00305dd0, was src/sdk/glue.c)
namespace n00325380 {
/*TARGET 00325380*/
int func_00325380(int fd) asm("func_00325380");
int func_00325380(int fd) { return 1; }
}  // namespace n00325380

// 00325388 (gap; copy of 0x00105a10, was src/common/unit_00325388.cpp)
namespace n00325388 {
/*TARGET 00325388*/
void func_00325388(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00325388");
void func_00325388(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00325388

// 00325390 (gap; copy of 0x002061f0, was src/anon/unit_002061d8.cpp)
namespace n00325390 {
/*TARGET 00325390*/
s64 func_00325390(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_00325390");
/*TARGET 00325390*/
s64 func_00325390(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_00325390");
s64 func_00325390(s64 param0, s64 param1, s64 param2, s64 param3) {
    s64 result = 0, arg0 = param0, arg1 = param1, arg2 = param2, arg3 = param3, returnAddr = 0;
    result = 0 + 0;
    return result;
}
}  // namespace n00325390

// 00325398 (gap; copy of 0x00305dd0, was src/sdk/glue.c)
namespace n00325398 {
/*TARGET 00325398*/
int func_00325398(int fd) asm("func_00325398");
int func_00325398(int fd) { return 1; }
}  // namespace n00325398

// 003253a0 (gap; copy of 0x002061f0, was src/anon/unit_002061d8.cpp)
namespace n003253a0 {
/*TARGET 003253a0*/
s64 func_003253a0(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_003253a0");
/*TARGET 003253a0*/
s64 func_003253a0(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_003253a0");
s64 func_003253a0(s64 param0, s64 param1, s64 param2, s64 param3) {
    s64 result = 0, arg0 = param0, arg1 = param1, arg2 = param2, arg3 = param3, returnAddr = 0;
    result = 0 + 0;
    return result;
}
}  // namespace n003253a0

// 003253a8 (gap; copy of 0x002d5c20, was src/anon/unit_002d4548.cpp)
namespace n003253a8 {
/*TARGET 003253a8*/
// 0x002c5460: definition moved into src/anon/unit_002c53c8.cpp

f32* func_003253a8(f32* v) asm("func_003253a8");
/*TARGET 003253a8*/
// 0x002c5460: definition moved into src/anon/unit_002c53c8.cpp

f32* func_003253a8(f32* v) asm("func_003253a8");
// 0x002c5460: definition moved into src/anon/unit_002c53c8.cpp

f32* func_003253a8(f32* v) {  // vec4_clear
    v[3] = v[2] = v[1] = v[0] = 0.0f;
    return v;
}
}  // namespace n003253a8

// 003253c8 (gap; copy of 0x00105a10, was src/common/unit_003253c8.cpp)
namespace n003253c8 {
/*TARGET 003253c8*/
void func_003253c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003253c8");
void func_003253c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n003253c8

// 003253d0 (gap; copy of 0x00105a10, was src/common/unit_003253d0.cpp)
namespace n003253d0 {
/*TARGET 003253d0*/
void func_003253d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003253d0");
void func_003253d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n003253d0

// 003253d8 (gap; copy of 0x002061f0, was src/anon/unit_002061d8.cpp)
namespace n003253d8 {
/*TARGET 003253d8*/
s64 func_003253d8(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_003253d8");
/*TARGET 003253d8*/
s64 func_003253d8(s64 param0, s64 param1, s64 param2, s64 param3) asm("func_003253d8");
s64 func_003253d8(s64 param0, s64 param1, s64 param2, s64 param3) {
    s64 result = 0, arg0 = param0, arg1 = param1, arg2 = param2, arg3 = param3, returnAddr = 0;
    result = 0 + 0;
    return result;
}
}  // namespace n003253d8

// 003253e0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n003253e0 {
u32 func_002d0f38(u32, u32, u32, u32) asm("_Z13func_002d0f38jjjj");
extern u8 D_003622c0 asm("D_003622c0");
/*TARGET 003253e0*/
u32 func_003253e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_003253e0jjjj");
u32 func_003253e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003622c0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002d0f38)(u32, u32, u32, u32) = func_002d0f38;
    r2 = fp_call4_002d0f38(r4, r5, r6, r7);
    return r2;
}
}  // namespace n003253e0

// 00325408 (was src/anon/batch_w22.cpp)
namespace n00325408 {
void func_00105110(void*) asm("func_00105110");
// --- 00325408
extern u32 D_003622c0 asm("D_003622c0");
void func_002d0f38(void*) asm("func_002d0f38");
/*TARGET 00325408*/
void func_00325408(void** p) asm("func_00325408");
void func_00325408(void** p) {
    *p = &D_003622c0;
    func_002d0f38(p);
    func_00105110(p);
}
}  // namespace n00325408

// 00325440 (gap)
namespace n00325440 {
struct E16 { u8 d[16]; ~E16() {} };
void func_002d0f38(void*) asm("func_002d0f38");
extern void* D_003625e0[] asm("D_003625e0");
struct Head2d0f38 { u32 vt; ~Head2d0f38() { func_002d0f38(this); } };
struct Obj325498 {
    Head2d0f38 head;
    u8 pad4[3228];
    E16 arr[8];
    ~Obj325498() { *(void**)this = D_003625e0; }
};
/*TARGET 00325440*/
// Destructor (0x325498 is the deleting one).
void func_00325440(Obj325498* p) asm("func_00325440");
void func_00325440(Obj325498* p) { p->~Obj325498(); }
}  // namespace n00325440

// 00325498 (was src/anon/batch_w38.cpp)
namespace n00325498 {
// 16-byte element with an empty destructor; arrays of it get a destructor loop.
struct E16 { u8 d[16]; ~E16() {} };
void func_00105110(void*) asm("func_00105110");
void func_002d0f38(void*) asm("func_002d0f38");
extern void* D_003625e0[] asm("D_003625e0");
struct Head2d0f38 { u32 vt; ~Head2d0f38() { func_002d0f38(this); } };
struct Obj325498 {
    Head2d0f38 head;
    u8 pad4[3228];
    E16 arr[8];
    ~Obj325498() { *(void**)this = D_003625e0; }
    static void operator delete(void* p) { func_00105110(p); }
};
/*TARGET 00325498*/
// Deleting destructor.
// 001a4060: moved to src/anon/unit_001a3e70.cpp

// Deleting destructor.
void func_00325498(Obj325498* p) asm("func_00325498");
// Deleting destructor.
// 001a4060: moved to src/anon/unit_001a3e70.cpp

// Deleting destructor.
void func_00325498(Obj325498* p) {
    p->~Obj325498();
    Obj325498::operator delete(p);
}
}  // namespace n00325498

// 00325500 (gap; copy of 0x001a1de0, was src/anon/unit_0019fb70.cpp)
namespace n00325500 {
u32 u_call4_00325500(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00325500");
/*TARGET 00325500*/
u32 u_call4_00325500(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00325500");
u32 u_call4_00325500(u32 a0, u32 a1, u32 a2, u32 a3) {
    return (*(f32*)(a0 + 3072u) > 0.0f) ? 1u : 0u;
}
}  // namespace n00325500

// 00325520 (gap; copy of 0x00105a10, was src/common/unit_00325520.cpp)
namespace n00325520 {
/*TARGET 00325520*/
void func_00325520(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00325520");
void func_00325520(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00325520

// 00325528 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00325528 {
u32 func_002d0f38(u32, u32, u32, u32) asm("_Z13func_002d0f38jjjj");
extern u8 D_00362a20 asm("D_00362a20");
/*TARGET 00325528*/
u32 func_00325528(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00325528jjjj");
u32 func_00325528(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362a20;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002d0f38)(u32, u32, u32, u32) = func_002d0f38;
    r2 = fp_call4_002d0f38(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00325528

// 00325550 (was src/anon/batch_w23.cpp)
namespace n00325550 {
void func_00105110(void*) asm("func_00105110");
extern u32 D_00362a20 asm("D_00362a20");
void func_002d0f38(void*) asm("func_002d0f38");
/*TARGET 00325550*/
void func_00325550(void** p) asm("func_00325550");
void func_00325550(void** p) {
    *p = &D_00362a20;
    func_002d0f38(p);
    func_00105110(p);
}
}  // namespace n00325550

// 00325588 (gap; copy of 0x00105a10, was src/common/unit_00325588.cpp)
namespace n00325588 {
/*TARGET 00325588*/
void func_00325588(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00325588");
void func_00325588(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00325588

// 00325590 (was src/anon/tiny_auto80_solver.cpp)
namespace n00325590 {
u32 func_002dea80(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002dea80jjjjjjjj");
extern u8 D_00362cc8 asm("D_00362cc8");
/*TARGET 00325590*/
u32 func_00325590(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00325590jjjjjjjj");
u32 func_00325590(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)&D_00362cc8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002dea80)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n00325590

// 003255b8 (was src/anon/batch_w11.cpp)
namespace n003255b8 {
void func_00106420(void*) asm("func_00106420");
extern u32 D_00362cc8 asm("D_00362cc8");
void func_002dea80(void*) asm("func_002dea80");
/*TARGET 003255b8*/
// set_vtbl_362d20
void func_003255b8(void** p) asm("func_003255b8");
// set_vtbl_362d20
void func_003255b8(void** p) {
    *p = &D_00362cc8;
    func_002dea80(p);  // set_vtbl_362d20
    func_00106420(p);
}
}  // namespace n003255b8

// 003255f0 (gap; copy of 0x00325590, was src/anon/tiny_auto80_solver.cpp)
namespace n003255f0 {
u32 func_002dea80(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002dea80jjjjjjjj");
extern u8 D_00362c70 asm("D_00362c70");
/*TARGET 003255f0*/
u32 func_003255f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_003255f0");
u32 func_003255f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)&D_00362c70;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002dea80)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n003255f0

// 00325618 (was src/anon/batch_w12.cpp)
namespace n00325618 {
// set_vtbl_347940
void func_00106420(void*) asm("func_00106420");
void func_002dea80(void*) asm("func_002dea80");
extern u8 D_00362c70 asm("D_00362c70");
/*TARGET 00325618*/
// Deleting destructor: reset vtable, run base dtor, free.
void func_00325618(void** p) asm("func_00325618");
// Deleting destructor: reset vtable, run base dtor, free.
void func_00325618(void** p) {
    *p = &D_00362c70;
    func_002dea80(p);  // set_vtbl_362d20
    func_00106420(p);
}
}  // namespace n00325618

// 00325650 (gap; copy of 0x00325590, was src/anon/tiny_auto80_solver.cpp)
namespace n00325650 {
u32 func_002dea80(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002dea80jjjjjjjj");
extern u8 D_00362c18 asm("D_00362c18");
/*TARGET 00325650*/
u32 func_00325650(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00325650");
u32 func_00325650(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)&D_00362c18;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002dea80)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n00325650

// 00325678 (was src/anon/batch_w13.cpp)
namespace n00325678 {
// set_vtbl_347940
void func_00106420(void*) asm("func_00106420");
void func_002dea80(void*) asm("func_002dea80");
extern void (*D_0035e380[])(void) asm("D_0035e380");
extern u8 D_00362c18 asm("D_00362c18");
/*TARGET 00325678*/
void func_00325678(void** p) asm("func_00325678");
void func_00325678(void** p) {
    *p = &D_00362c18;
    func_002dea80(p);  // set_vtbl_362d20
    func_00106420(p);
}
}  // namespace n00325678

// 003256b0 (gap; copy of 0x002361d0, was src/anon/unit_00236180.cpp)
namespace n003256b0 {
extern u32 D_00363410 asm("D_00363410");
/*TARGET 003256b0*/
// YI::IMAGE::~IMAGE
void func_003256b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003256b0");
/*TARGET 003256b0*/
// YI::IMAGE::~IMAGE
void func_003256b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003256b0");
// YI::IMAGE::~IMAGE
void func_003256b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00363410;
}
}  // namespace n003256b0

// 003256c0 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n003256c0 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00363410 asm("D_00363410");
/*TARGET 003256c0*/
u32 func_003256c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_003256c0jjjjjjjj");
u32 func_003256c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00363410;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n003256c0

// 003256e0 (gap; copy of 0x00105a10, was src/common/unit_003256e0.cpp)
namespace n003256e0 {
/*TARGET 003256e0*/
void func_003256e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003256e0");
void func_003256e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n003256e0

// 003256e8 (gap; copy of 0x00105a10, was src/common/unit_003256e8.cpp)
namespace n003256e8 {
/*TARGET 003256e8*/
void func_003256e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003256e8");
void func_003256e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n003256e8

// 003256f0 (gap; copy of 0x00105a10, was src/common/unit_003256f0.cpp)
namespace n003256f0 {
/*TARGET 003256f0*/
void func_003256f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003256f0");
void func_003256f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n003256f0

// 003256f8 (gap; copy of 0x00105a10, was src/common/unit_003256f8.cpp)
namespace n003256f8 {
/*TARGET 003256f8*/
void func_003256f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_003256f8");
void func_003256f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n003256f8

// 00325700 (was src/anon/auto80_199_queue.cpp)
namespace n00325700 {
/*TARGET 00325700*/
void func_00325700(u32 self) asm("_Z13func_00325700j");
void func_00325700(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}
}  // namespace n00325700

// 00325780 (was src/anon/auto80_199_queue.cpp)
namespace n00325780 {
/*TARGET 00325780*/
u32 func_00325780(u32 self) asm("_Z13func_00325780j");
u32 func_00325780(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}
}  // namespace n00325780

// 00325808 (gap; copy of 0x002361d0, was src/anon/unit_00236180.cpp)
namespace n00325808 {
extern u32 D_003637e0 asm("D_003637e0");
/*TARGET 00325808*/
// YI::IMAGE::~IMAGE
void func_00325808(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00325808");
/*TARGET 00325808*/
// YI::IMAGE::~IMAGE
void func_00325808(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00325808");
// YI::IMAGE::~IMAGE
void func_00325808(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_003637e0;
}
}  // namespace n00325808

// 00325818 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n00325818 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_003637e0 asm("D_003637e0");
/*TARGET 00325818*/
u32 func_00325818(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00325818jjjjjjjj");
u32 func_00325818(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_003637e0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n00325818

// 00325838 (gap; copy of 0x00305dd0, was src/sdk/glue.c)
namespace n00325838 {
/*TARGET 00325838*/
int func_00325838(int fd) asm("func_00325838");
int func_00325838(int fd) { return 1; }
}  // namespace n00325838

// 00325840 (was src/anon/auto80_199_queue.cpp)
namespace n00325840 {
/*TARGET 00325840*/
void func_00325840(u32 a0, u32 a1) asm("_Z13func_00325840jj");
void func_00325840(u32 a0, u32 a1) {
    u32 t7 = *(u32*)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32*)(a1 + 32);
        t5 = 0;
        *(u32*)a0 = t7n;
    } else {
        u32 t6 = *(u32*)(t7 + 32);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32*)(t6 + 32);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32*)(a1 + 32);
        *(u32*)(t5 + 32) = t7n;
    }

    u32 t7c = *(u32*)(a0 + 4);
    if (a1 == t7c) {
        *(u32*)(a0 + 4) = t5;
    }
    *(u32*)(a1 + 32) = 0;
}
}  // namespace n00325840

// 003258a0 (gap)
namespace n003258a0 {
struct U21_DObj;
struct U21_DObjVt { void (*dtor)(U21_DObj*); };
struct U21_DObj { U21_DObjVt* vt; u8 pad[340]; };
extern u8 D_00363828[] asm("D_00363828");
extern u8 D_003637e0[] asm("D_003637e0");
extern u8 D_00350ab0[] asm("D_00350ab0");
extern u8 D_00350bb0[] asm("D_00350bb0");
#define U21_W80_DTOR_ARR(base, off, n) \
    if ((u32)(base) != (u32)-(off)) { \
        U21_DObj* e_ = (U21_DObj*)((base) + (off)) + (n); \
        U21_DObj* b_ = (U21_DObj*)((base) + (off)); \
        for (;;) { \
            if (b_ == e_) break; \
            e_--; \
            e_->vt->dtor(e_); \
        } \
    }
void func_00239870(u8*) asm("func_00239870");
void func_0031e668(u8*) asm("func_0031e668");
void func_001ac5b8(u8*) asm("func_001ac5b8");
/*TARGET 003258a0*/
// Destructor (0x3259a0 is the deleting one).
void func_003258a0(u8* o) asm("func_003258a0");
void func_003258a0(u8* o) {
    u8* s = o + 44;
    *(u8**)o = D_00363828;
    *(u8**)s = D_00350ab0;
    U21_W80_DTOR_ARR(s, 3280, 4)
    func_00239870(s + 2936);
    *(u8**)s = D_00350bb0;
    U21_W80_DTOR_ARR(s, 1544, 4)
    func_00239870(s + 1200);
    func_00239870(s + 848);
    func_00239870(s + 484);
    func_0031e668(s + 132);
    func_001ac5b8(s);
    *(u8**)o = D_003637e0;
}
#undef U21_W80_DTOR_ARR
}  // namespace n003258a0

// 003259a0 (was src/anon/batch_w80.cpp)
namespace n003259a0 {
struct U21_DObj;
struct U21_DObjVt { void (*dtor)(U21_DObj*); };
struct U21_DObj { U21_DObjVt* vt; u8 pad[340]; };
extern u8 D_00363828[] asm("D_00363828");
extern u8 D_003637e0[] asm("D_003637e0");
extern u8 D_00350ab0[] asm("D_00350ab0");
extern u8 D_00350bb0[] asm("D_00350bb0");
#define U21_W80_DTOR_ARR(base, off, n) \
    if ((u32)(base) != (u32)-(off)) { \
        U21_DObj* e_ = (U21_DObj*)((base) + (off)) + (n); \
        U21_DObj* b_ = (U21_DObj*)((base) + (off)); \
        for (;;) { \
            if (b_ == e_) break; \
            e_--; \
            e_->vt->dtor(e_); \
        } \
    }
void func_00106420(void*) asm("func_00106420");
void func_00239870(u8*) asm("func_00239870");
void func_0031e668(u8*) asm("func_0031e668");
void func_001ac5b8(u8*) asm("func_001ac5b8");
/*TARGET 003259a0*/
// 0x002bbc90: definition moved into src/anon/unit_002bb8b0.cpp


void func_003259a0(u8* o) asm("func_003259a0");
// 0x002bbc90: definition moved into src/anon/unit_002bb8b0.cpp


void func_003259a0(u8* o) {
    u8* s = o + 44;
    *(u8**)o = D_00363828;
    *(u8**)s = D_00350ab0;
    U21_W80_DTOR_ARR(s, 3280, 4)
    func_00239870(s + 2936);
    *(u8**)s = D_00350bb0;
    U21_W80_DTOR_ARR(s, 1544, 4)
    func_00239870(s + 1200);
    func_00239870(s + 848);
    func_00239870(s + 484);
    func_0031e668(s + 132);
    func_001ac5b8(s);
    *(u8**)o = D_003637e0;
    func_00106420(o);
}
}  // namespace n003259a0

// 00325aa0 (was src/anon/batch_w35.cpp)
namespace n00325aa0 {
extern u8 D_003637e0[] asm("D_003637e0");
extern u8 D_00363880[] asm("D_00363880");
void func_0023c098(void*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(void*) asm("func_002369f0");
/*TARGET 00325aa0*/
// set_vtbl_36eac8_then_call
void func_00325aa0(u8* p) asm("func_00325aa0");
// set_vtbl_36eac8_then_call
void func_00325aa0(u8* p) {
    *(void**)p = D_00363880;
    func_0023c098(p + 64);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 40);  // set_vtbl_36eac8_then_call
    *(void**)p = D_003637e0;
}
}  // namespace n00325aa0

// 00325ae8 (was src/anon/batch_w31.cpp)
namespace n00325ae8 {
void func_00106420(void*) asm("func_00106420");
// big_obj_dtor
extern void* D_00363880[] asm("D_00363880");
extern void* D_003637e0[] asm("D_003637e0");
void func_0023c098(void*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(void*) asm("func_002369f0");
/*TARGET 00325ae8*/
void func_00325ae8(void** p) asm("func_00325ae8");
void func_00325ae8(void** p) {
    *p = D_00363880;
    func_0023c098((u8*)p + 64);  // set_vtbl_36eae8_then_call
    func_002369f0((u8*)p + 40);  // set_vtbl_36eac8_then_call
    *p = D_003637e0;
    func_00106420(p);
}
}  // namespace n00325ae8

// 00325b38 (gap; copy of 0x00325aa0, was src/anon/batch_w35.cpp)
namespace n00325b38 {
extern u8 D_003637e0[] asm("D_003637e0");
extern u8 D_003638a8[] asm("D_003638a8");
void func_00239870(void*) asm("func_00239870");
// set_vtbl_36eae8_then_call
void func_002361d0(void*) asm("func_002361d0");
/*TARGET 00325b38*/
// set_vtbl_36eac8_then_call
void func_00325b38(u8* p) asm("func_00325b38");
// set_vtbl_36eac8_then_call
void func_00325b38(u8* p) {
    *(void**)p = D_003638a8;
    func_00239870(p + 468);
    func_002361d0(p + 48);
    *(void**)p = D_003637e0;
}
}  // namespace n00325b38

// 00325b80 (was src/anon/batch_w32.cpp)
namespace n00325b80 {
void func_00106420(void*) asm("func_00106420");
// big_obj_dtor
extern u8 D_003638a8[] asm("D_003638a8");
extern u8 D_003637e0[] asm("D_003637e0");
void func_00239870(void*) asm("func_00239870");
void func_002361d0(void*) asm("func_002361d0");
/*TARGET 00325b80*/
void Tz__CmTutorial__Exit(void** p) asm("Tz__CmTutorial__Exit");
void Tz__CmTutorial__Exit(void** p) {
    p[0] = D_003638a8;
    func_00239870((u8*)p + 0x1d4);
    func_002361d0((u8*)p + 48);
    p[0] = D_003637e0;
    func_00106420(p);
}
}  // namespace n00325b80
