// Linked unit 0x00232f08-0x002335e8 (one namespace per old matched source; class methods in their own namespace).
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
#include "../sasa/event.hpp"
#include "../tozawa/menu_sound.hpp"

// 00232f08 (was src/anon/match_00232f08_mam.cpp)
namespace n00232f08 {
struct W1573_Q {
    u8 d[16];
    W1573_Q& operator=(const W1573_Q& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1573_P12 { u8 pad[20]; void* arc; };
struct W1573_E {
    s32 id;
    s32 pad4;
    u8* obj;
    W1573_P12* p12;
    f32 timer;
    s32 pad20;
    s16 a;
    s16 b;
    s32 pad28;
    W1573_Q vec;
    u8 flag;
    u8 pad49[15];
};
extern W1573_E* D_0035dcf8 asm("D_0035dcf8");
extern f32 D_00349e10 asm("D_00349e10");
void func_001ba028(u8*) asm("func_001ba028");
W1573_Q* func_0016c028(u8*) asm("func_0016c028");
void motion_start(void*, void*, f32, f32) asm("_ZN2YS6MOTION5startEPNS_6BINARCEff");
s32 obj_is_attach(u8*) asm("_ZN2YS3OBJ9is_attachEv");
void obj_set_pos(u8*, W1573_Q*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
/*TARGET 00232f08*/
void func_00232f08(void) asm("func_00232f08");
void func_00232f08(void)
{
    s32 i;

    if (D_0035dcf8 == 0) return;

    for (i = 0; i < 64; i++) {
        W1573_E* e = &D_0035dcf8[i];
        if (e->id == -1) continue;
        if (e->obj == 0) continue;
        if (e->b != -1) {
            if (e->flag == 1) {
                func_001ba028(e->obj);
                e->vec = *func_0016c028(e->obj);
                e->flag = 0;
            }
            f32 b2 = (f32)e->b + (f32)e->b;
            f32 a2 = (f32)e->a + (f32)e->a;
            if (b2 < e->timer) {
                f32 t = (f32)(s32)e->timer;
                t = t - b2;
                if (t < 2.0f) t = 2.0f;
                t = t + a2;
                func_001ba028(e->obj);
                motion_start(e->obj + 320, e->p12->arc, 0.0f, t);
                if (obj_is_attach(e->obj) == 0) obj_set_pos(e->obj, &e->vec);
                e->timer = t;
            }
        }
        e->timer = e->timer + D_00349e10;
    }
}
}  // namespace n00232f08

// .rodata 0x37136c-0x371388: strings read by 0x2330c8 as extern D_.
extern const u32 R_0037136c[1] asm("D_0037136c") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_00371370[2] asm("D_00371370") __attribute__((aligned(4))) = { 0x2f6d6e61, 0x0 };
extern const u32 R_00371378[2] asm("D_00371378") __attribute__((aligned(4))) = { 0x2f, 0x0 };
extern const u32 R_00371380[2] asm("D_00371380") __attribute__((aligned(4))) = { 0x626e612e, 0x0 };

// 002330b0 (was src/anon/tiny.cpp)
namespace n002330b0 {
void func_00226030(void*) asm("_Z13func_00226030Pv");
/*TARGET 002330b0*/
void func_002330b0(BD_VALUE* bd) asm("_Z13func_002330b0P8BD_VALUE");
void func_002330b0(BD_VALUE* bd) { func_00226030(bd); }
}  // namespace n002330b0

// 002330c8 (was src/anon/batch_w86.cpp)
namespace n002330c8 {
extern char D_01dadbd8[] asm("D_01dadbd8");
extern char D_00371370[] asm("D_00371370");
extern char D_00371378[] asm("D_00371378");
extern char D_00371380[] asm("D_00371380");
char* func_002feee8(char*, const char*) asm("func_002feee8");
void strlen(char*) asm("strlen");
/*TARGET 002330c8*/
// strlen
char* func_002330c8(const char* path, const char* name) asm("func_002330c8");
// strlen
char* func_002330c8(const char* path, const char* name)
{
    char buf[48];
    D_01dadbd8[0] = 0;
    func_002feee8(D_01dadbd8, D_00371370);
    s32 i = 0;
    const char* p;
    char* q;
    char c;
    do {
        p = path + i;
        q = buf + i;
        c = *p;
        i++;
        *q = c;
    } while (c != '/');
    *q = 0;
    func_002feee8(D_01dadbd8, buf + 4);
    func_002feee8(D_01dadbd8, D_00371378);
    func_002feee8(D_01dadbd8, name);
    func_002feee8(D_01dadbd8, p);
    func_002feee8(D_01dadbd8, D_00371380);
    strlen(D_01dadbd8);  // strlen
    strlen(buf);  // strlen
    return D_01dadbd8;
}
}  // namespace n002330c8

// 002331a0 (was src/anon/batch_w8010.cpp)
namespace n002331a0 {
// ---- 002331a0
struct Wk { s32 a; s32 b; u8 c; u8 pad[3]; s32 d; s32 e; s32 f; u8 pad2[8]; char n1[16]; char n2[16]; };
Wk* func_00227a28() asm("func_00227a28");
char* func_0022f4f0(s32) asm("func_0022f4f0");
char* func_002ff2e8(char*, const char*) asm("func_002ff2e8");
char* func_002330c8(char*, char*) asm("func_002330c8");
s32 readBuffAlloc_w8010(char*, Wk*, s32) asm("_ZN2sa5EVENT13readBuffAllocEPcPNS_7READ_WKENS_11EVENT_ALLOC10ALLOC_TYPEE");
void func_002330b0() asm("func_002330b0");
void func_001684c0(char*, s32, void (*)(), Wk*) asm("func_001684c0");
/*TARGET 002331a0*/
void func_002331a0(char* name, s32 type, s32 id, s32 d, s32 flag) asm("func_002331a0");
void func_002331a0(char* name, s32 type, s32 id, s32 d, s32 flag) {
    Wk* w = func_00227a28();
    w->d = d;
    w->a = w->b = 1;
    w->c = flag != 0;
    w->e = id;
    char* s = func_0022f4f0(id);
    char* dst = w->n1;
    func_002ff2e8(dst, s);
    func_002ff2e8(w->n2, name);
    s = func_0022f4f0(id);
    char* p = func_002330c8(name, s);
    s32 r = readBuffAlloc_w8010(p, w, type);
    w->f = r;
    func_001684c0(p, r, func_002330b0, w);
}
}  // namespace n002331a0

// 00233280 (was src/sasa/event.cpp)
namespace sa { // method 00233280
/*TARGET 00233280*/
void EVENT::setActorParam(YS::OBJ* obj) {
    u32 v0 = *(u32*)((u32)this + 264);
    u32 v1 = *(u32*)((u32)this + 1896);
    v0 |= 0x40000003u;
    v1 |= 0x6010u;
    *(u32*)((u32)this + 264) = v0;
    *(u32*)((u32)this + 1896) = v1;
    (void)obj;
}
}  // sa

// 002332a8 (was src/anon/batch_wcx2.cpp)
namespace n002332a8 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
// 0x001b4dd0: definition moved into src/anon/unit_001b2780.cpp

struct Ev18 { u32 res; u8 pad[4]; u8* obj; };
struct Sn18 { u8 pad[4]; u16 id; u8 pad2[2]; u16 sy; u8 pad3[4]; s16 kind; s16 sx; u8 arg[2]; };
s32 func_002282f0(u16) asm("func_002282f0");
Ev18* func_00227d10(s16) asm("func_00227d10");
u8* func_0016f000(u32, Vec4*, f32) asm("func_0016f000");
void func_001ba028(u8*) asm("func_001ba028");
// list_contains_ptr
void func_00233280(u8*) asm("func_00233280");
u32 func_00232e60(void) asm("func_00232e60");
u32 func_00232e18(s16) asm("func_00232e18");
u32 func_0022f4f0(u32) asm("func_0022f4f0");
u8* func_00227b00(u32, s32, u8*) asm("func_00227b00");
u8* func_00102c18(s32, s32, void (*)()) asm("func_00102c18");
void func_00227950() asm("func_00227950");
void func_00227a08() asm("func_00227a08");
void func_0017f430(u8*, u32, f32, f32) asm("func_0017f430");
void func_00232ea0(u32, Sn18*, Ev18*, u8*) asm("func_00232ea0");
/*TARGET 002332a8*/
void func_002332a8(Sn18* p) asm("func_002332a8");
void func_002332a8(Sn18* p)
{
    if (func_002282f0(p->id)) return;
    Ev18* e = func_00227d10(p->kind);
    u32 h;
    if (!e->obj) {
        Vec4 v;
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&v) : "memory");
        e->obj = func_0016f000(e->res | 0x40000000, &v, 3.1415925f);
        func_001ba028(e->obj);  // list_contains_ptr
        func_00233280(e->obj);
        h = func_00232e60();
    } else {
        h = func_00232e18(p->kind);
    }
    u8* s = func_00227b00(func_0022f4f0(e->res), 1, p->arg);
    *(s32*)(func_00102c18(1, 0xa7ee, func_00227950) + 4) = p->kind;
    if (!s[8]) *(u8**)(func_00102c18(1, 0xa7f3, func_00227a08) + 4) = s;
    u8* o = e->obj;
    func_001ba028(o);  // list_contains_ptr
    func_0017f430(o + 320, *(u32*)(s + 20), (f32)p->sx * 2.0f, (f32)p->sy * 2.0f);
    func_00232ea0(h, p, e, s);
}
}  // namespace n002332a8

// 00233410 (was src/anon/batch_w51.cpp)
namespace n00233410 {
void func_001ba028(u32) asm("func_001ba028");
u32 func_002282f0(u16) asm("func_002282f0");
u32* func_00227d10(s16) asm("func_00227d10");
u32 func_0016f000(u32, void*, f32) asm("func_0016f000");
void func_00233280(u32) asm("func_00233280");
typedef unsigned int u128 __attribute__((mode(TI)));
/*TARGET 00233410*/
void func_00233410(u8* p) asm("func_00233410");
void func_00233410(u8* p) {
    if (func_002282f0(*(u16*)(p + 4))) return;
    u32* e = func_00227d10(*(s16*)(p + 6));
    if (e[2]) return;
    u128 v;
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&v) : "memory");
    e[2] = func_0016f000(e[0] | 0x40000000, &v, 3.1415925f);
    func_001ba028(e[2]);  // list_contains_ptr
    func_00233280(e[2]);
}
}  // namespace n00233410

// 00233490 (was src/anon/batch_w88.cpp)
namespace n00233490 {
// 16-byte aligned vector / matrix used with VU0 macro code.
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
s32 func_002282f0(u16) asm("func_002282f0");
u8* func_00227d10(s16) asm("func_00227d10");
f32 func_00227c78(u8*) asm("func_00227c78");
u32 func_00227ca8(u8*) asm("func_00227ca8");
u32 func_0016f000(u32, V4*, f32) asm("func_0016f000");
// 0x001cf9e0: definition moved into src/anon/unit_001cf0b0.cpp

typedef void (*VF233490)(u8*, V4*, u32);
/*TARGET 00233490*/
void func_00233490(u8* p) asm("func_00233490");
void func_00233490(u8* p) {
    if (func_002282f0(*(u16*)(p + 4))) return;
    u8* o = func_00227d10(*(s16*)(p + 6));
    if (*(u32*)(o + 8)) return;
    V4 a, b;
    a.x = func_00227c78(p + 8);
    a.y = func_00227c78(p + 12);
    a.z = func_00227c78(p + 16);
    *(u32*)(o + 8) = func_0016f000(*(u32*)o | 0x40000000, &a, func_00227c78(p + 36) * 0.017453292f);
    b.x = func_00227c78(p + 24);
    b.y = func_00227c78(p + 28);
    b.z = func_00227c78(p + 32);
    u32 r = func_00227ca8(p + 20);
    u8* q = *(u8**)(o + 8);
    (*(VF233490*)(*(u8**)q + 88))(q, &b, r);
}
}  // namespace n00233490

// 00233580 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n00233580 {
u32 func_00233c98() asm("_Z13func_00233c98v");
u32 func_00236200() asm("_Z13func_00236200v");
u32 func_00236a50() asm("_Z13func_00236a50v");
u32 func_00236d10() asm("_Z13func_00236d10v");
u32 func_00237278() asm("_Z13func_00237278v");
u32 func_002398d0() asm("_Z13func_002398d0v");
u32 func_0023c0f8() asm("_Z13func_0023c0f8v");
u32 func_0023cdb8() asm("_Z13func_0023cdb8v");
/*TARGET 00233580*/
// 0x001e2bc8: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00233580(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00233580jjjj");
// 0x001e2bc8: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00233580(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_00233c98)() = func_00233c98;
    r2 = fp_call0_00233c98();
    u32 (*fp_call0_00236200)() = func_00236200;
    r2 = fp_call0_00236200();
    u32 (*fp_call0_00236a50)() = func_00236a50;
    r2 = fp_call0_00236a50();
    u32 (*fp_call0_00236d10)() = func_00236d10;
    r2 = fp_call0_00236d10();
    u32 (*fp_call0_00237278)() = func_00237278;
    r2 = fp_call0_00237278();
    u32 (*fp_call0_002398d0)() = func_002398d0;
    r2 = fp_call0_002398d0();
    u32 (*fp_call0_0023c0f8)() = func_0023c0f8;
    r2 = fp_call0_0023c0f8();
    return func_0023cdb8();
}
}  // namespace n00233580

// 002335d0 (was gap)
namespace n002335d0 {
u32 func_00233580_w(void) asm("_Z13func_00233580jjjj");
u32 func_002335d0(void) asm("func_002335d0");
u32 func_002335d0(void) { return func_00233580_w(); }
}  // namespace n002335d0

