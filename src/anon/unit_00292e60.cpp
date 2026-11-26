// Linked unit 0x00292e60-0x002958b0 (Tz unit load, ChgMember, JmData, JmInfo, JmWorldSel).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/unitload.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/chg_member.hpp"
#include "../tozawa/jm_data.hpp"
#include "../tozawa/jm_album.hpp"
#include "../tozawa/jm_info.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/menu_sound.hpp"

// 00292e60 (gap: load-done callback)
namespace g00292e60 {
extern s16 D_0035f4e0 asm("D_0035f4e0");
extern u8 D_0035f4e2 asm("D_0035f4e2");
void func_002930d8(void) asm("func_002930d8");
s32 func_00292eb0(void) asm("func_00292eb0");
void cb(u32 a0, u32 a1, u8* a2) asm("D_00292e60");
void cb(u32 a0, u32 a1, u8* a2) {
    if (a2 && *(s32*)(a2 + 12)) {
        *(u32*)(a2 + 8) = a1;
        *(s32*)(a2 + 4) = 1;
    }
    D_0035f4e2 = 0;
    func_002930d8();
    if (D_0035f4e0) func_00292eb0();
}
}  // namespace g00292e60

// 00292eb0 (was src/anon/batch_w47.cpp)
namespace n00292eb0 {
// 0028d068: moved to src/anon/unit_0028c878.cpp

s32 func_00293200(void) asm("func_00293200");
extern s16 D_0035f4e0 asm("D_0035f4e0");
extern s32 D_0035f4c4 asm("D_0035f4c4");
u8 func_00292f18(void) asm("func_00292f18");
u8 func_00292fe8(void) asm("func_00292fe8");
/*TARGET 00292eb0*/
s32 func_00292eb0(void) asm("func_00292eb0");
s32 func_00292eb0(void) {
    if (func_00293200()) return -1;
    if (!D_0035f4e0) return 0;
    if (!D_0035f4c4) return func_00292f18();
    return func_00292fe8();
}
}  // namespace n00292eb0

// 00292f18 (was src/anon/batch_w91.cpp)
namespace n00292f18 {
// 00290198: moved to src/anon/unit_0028f1e0.cpp

// --- 00292f18
struct E16 { u32 a; u32 b; u32 c; u32 d; };
union GE91 { E16* p; u32 u; };
union GU91 { u32 v; u8 c; };
union GS91 { s32 v; u8 c; };
extern u32* D_0035f4dc asm("D_0035f4dc");
extern GE91 D_0035f4d4 asm("D_0035f4d4");
extern GU91 D_0035f4c8 asm("D_0035f4c8");
extern GS91 D_0035f4c0 asm("D_0035f4c0");
extern u8 D_0035f4e2 asm("D_0035f4e2");
extern char D_00374578[] asm("D_00374578");
extern u8 D_00292e60[] asm("D_00292e60");
void func_002fee78(char*, char*, ...) asm("func_002fee78");
void func_00168388(char*, u32, u8*, E16*) asm("func_00168388");
/*TARGET 00292f18*/
u32 func_00292f18(void) asm("func_00292f18");
u32 func_00292f18(void) {
    char buf[32];
    s32 v = *D_0035f4dc;
    u32 lo = v & 0xffff;
    s32 hi = v >> 16;
    func_002fee78(buf, D_00374578, lo);
    D_0035f4d4.p[hi].a = lo;
    D_0035f4d4.p[hi].b = 2;
    D_0035f4d4.p[hi].d = D_0035f4c8.v + hi * D_0035f4c0.v;
    D_0035f4d4.p[hi].c = 0;
    func_00168388(buf, D_0035f4d4.p[hi].d, D_00292e60, &D_0035f4d4.p[hi]);
    D_0035f4e2 = 1;
    return 0;
}
}  // namespace n00292f18

// 00292fe8 (was src/anon/batch_w249.cpp)
namespace n00292fe8 {
// 00192990: moved to src/yasui/libys/message.cpp
struct Ent292 { s32 a; s32 b; s32 c; s32 d; };
union G292p { Ent292* p; s32* q; void* v; s32 i; u8 c; };
extern G292p D_0035f4e4 asm("D_0035f4e4");
extern G292p D_0035f4dc asm("D_0035f4dc");
extern G292p D_0035f4d4 asm("D_0035f4d4");
extern G292p D_0035f4c0 asm("D_0035f4c0");
extern G292p D_0035f4c8 asm("D_0035f4c8");
extern u8 D_0035f4e2 asm("D_0035f4e2");
void strlen(void*) asm("strlen");
// strlen
void func_00168410(void*, s32, s32, u16, void*, void*) asm("func_00168410");
void func_00292e60(void) asm("func_00292e60");
/*TARGET 00292fe8*/
s32 func_00292fe8(void) asm("func_00292fe8");
s32 func_00292fe8(void) {
    strlen(D_0035f4e4.v);  // strlen
    s32 v = *D_0035f4dc.q;
    s32 hi = v >> 16;
    s32 lo = v & 0xffff;
    D_0035f4d4.p[hi].a = lo;
    D_0035f4d4.p[hi].b = 2;
    D_0035f4d4.p[hi].d = D_0035f4c8.i + hi * D_0035f4c0.i;
    D_0035f4d4.p[hi].c = 0;
    func_00168410(D_0035f4e4.v, D_0035f4d4.p[hi].d, lo * D_0035f4c0.i / 2048, D_0035f4c0.i / 2048, (void*)func_00292e60, &D_0035f4d4.p[hi]);
    D_0035f4e2 = 1;
    return 0;
}
}  // namespace n00292fe8

// 002930d8 (was src/anon/batch_w42.cpp)
namespace n002930d8 {
// 0028d008: moved to src/anon/unit_0028c878.cpp

// 002930d8: drop the first element of a global list
union Count293 { s16 n; u32 w; };
union List293 { u32* p; u32 w; };
extern Count293 D_0035f4e0 asm("D_0035f4e0");
extern List293 D_0035f4dc asm("D_0035f4dc");
/*TARGET 002930d8*/
void func_002930d8(void) asm("func_002930d8");
void func_002930d8(void)
{
    s16 n = D_0035f4e0.n;
    if (n == 0) return;
    if (n >= 2) {
        for (s32 i = 1; i < D_0035f4e0.n; i++) D_0035f4dc.p[i - 1] = D_0035f4dc.p[i];
    }
    D_0035f4e0.n--;
}
}  // namespace n002930d8

// 00293148 (was src/anon/batch_w46.cpp)
namespace n00293148 {
// 0028e350: moved to src/anon/unit_0028c878.cpp

// ---- 00293148
struct E293 { s32 id; u32 on : 1; u32 pad; u32 val; };
extern s32 D_0035f4d0 asm("D_0035f4d0");
extern E293* D_0035f4d4 asm("D_0035f4d4");
/*TARGET 00293148*/
u32 func_00293148(s32 id) asm("func_00293148");
u32 func_00293148(s32 id) {
    for (s32 i = 0; i < D_0035f4d0; i++) {
        E293* e = &D_0035f4d4[i];
        if ((u8)e->on && e->id == id) return e->val;
    }
    return 0;
}
}  // namespace n00293148

// 002931a8 (was src/anon/auto80_199_queue.cpp)
namespace n002931a8 {
/*TARGET 002931a8*/
// 002911f8: moved to src/anon/unit_00290f78.cpp

void func_002931a8(u32 a0) asm("_Z13func_002931a8j");
// 002911f8: moved to src/anon/unit_00290f78.cpp

void func_002931a8(u32 a0) {
    u32 s16 = a0;
    strlen();  // strlen
    if (strcmp(D_0035f4e4, s16) != 0) {  // strcmp
        func_00292a58();
    }
    func_002ff2e8(D_0035f4e4, s16);
}
}  // namespace n002931a8

// 00293200 (was src/tozawa/unitload.cpp)
namespace Tz { // method 00293200
u32 func_001688b8() asm("func_001688b8");
/*TARGET 00293200*/
u32 UnitLoad::isReading() {
    u32 t5;
    if (func_001688b8() != 0) {
        goto set1;
    }
    t5 = 0;
    {
        u32 base = 0x00360000u;
        u32 t6 = *(u8*)(base + (s32)-2846);
        if (t6 == 0) {
            goto out;
        }
    }
set1:
    t5 = 1;
out:
    return t5;
}
}  // Tz

// 00293240 (was src/anon/batch_wcx.cpp)
namespace n00293240 {
union GP { s16* p; s16 h; };
extern GP D_0035f4e8 asm("D_0035f4e8");
extern GP D_0035f4ec asm("D_0035f4ec");
u32 func_00103570(void) asm("func_00103570");
s16* func_001063f0(s32, u32) asm("func_001063f0");
void func_002936e8(void) asm("func_002936e8");
/*TARGET 00293240*/
void func_00293240(void) asm("func_00293240");
void func_00293240(void)
{
    D_0035f4e8.p = func_001063f0(48, func_00103570());
    D_0035f4ec.p = func_001063f0(48, func_00103570());
    for (s32 i = 0; i < 8; i++) {
        D_0035f4e8.p[i * 3 + 0] = -1;
        D_0035f4e8.p[i * 3 + 1] = -1;
        D_0035f4e8.p[i * 3 + 2] = -1;
        D_0035f4ec.p[i * 3 + 0] = -1;
        D_0035f4ec.p[i * 3 + 1] = -1;
        D_0035f4ec.p[i * 3 + 2] = -1;
    }
    func_002936e8();
}
}  // namespace n00293240

// 002932f8 (was src/anon/auto80_199_queue.cpp)
namespace n002932f8 {
/*TARGET 002932f8*/
void func_002932f8(void) asm("_Z13func_002932f8v");
void func_002932f8(void) {
    if (D_0035f4e8 != 0) {
        func_00106450(D_0035f4e8);
        D_0035f4e8 = 0;
    }

    if (D_0035f4ec != 0) {
        func_00106450(D_0035f4ec);
        D_0035f4ec = 0;
    }

    func_002936e8();
}
}  // namespace n002932f8

// 00293350 (was src/anon/batch_w41.cpp)
namespace n00293350 {
// record408_alloc_init
// 0028ce38: moved to src/anon/unit_0028c878.cpp

u8* func_00103eb0(void) asm("func_00103eb0");
u32* func_00102818(u32, u32, u32, void (*)(void), u32) asm("func_00102818");
void func_002933b8(void) asm("func_002933b8");
/*TARGET 00293350*/
void func_00293350(u32 a, u32 b, u32 c) asm("func_00293350");
void func_00293350(u32 a, u32 b, u32 c) {
    u32* r = func_00102818(*(u32*)(func_00103eb0() + 4), 0, 0x222e0, func_002933b8, 4096);
    r[1] = a;
    r[2] = b;
    r[3] = c;
}
}  // namespace n00293350

// 002933b8 (was src/anon/tiny_wrappers_more.cpp)
namespace n002933b8 {
u32 func_00175f68(u32, u32, u32, u32) asm("_Z13func_00175f68jjjj");
/*TARGET 002933b8*/
// 00292550: moved to src/anon/unit_00290f78.cpp

u32 func_002933b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002933b8jjjj");
// 00292550: moved to src/anon/unit_00290f78.cpp

u32 func_002933b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00175f68(a0, ((u32)(*(u32*)((u32)(a0) + 4u))), ((u32)(*(u32*)((u32)(a0) + 8u))), ((u32)(*(u32*)((u32)(a0) + 12u))));
}
}  // namespace n002933b8

// 002933d8 (was src/anon/batch_w1598.cpp)
namespace n002933d8 {
// 0x0025f430: definition moved into src/anon/unit_0025da20.cpp

struct P6 { s16 x, y, z; };
extern P6* D_0035f4e8 asm("D_0035f4e8");
union UP6 { P6* p; s16 h; };
extern UP6 D_0035f4ec_ asm("D_0035f4ec");
#define D_0035f4ec D_0035f4ec_.p
/*TARGET 002933d8*/
void func_002933d8(s32 a0, s32 a1, s32 a2, P6* a3) asm("func_002933d8");
void func_002933d8(s32 a0, s32 a1, s32 a2, P6* a3) {  // table_find_pair
    s32 i;
    s32 found = -1;
    if (!a3) a3 = D_0035f4e8;
    for (i = 0; i < 8; i++) {
        if (a3[i].x == a0 && a3[i].y == a1) {
            a3[i].x = a0;
            a3[i].y = a1;
            a3[i].z = a2;
            found = i;
            break;
        }
    }
    if (found < 0) {
        for (i = 0; i < 8; i++) {
            if (a3[i].x < 0) {
                a3[i].x = a0;
                a3[i].y = a1;
                a3[i].z = a2;
                found = i;
                break;
            }
        }
    }
    if (a3 == D_0035f4ec) return;
    for (i = 0; i < 8; i++) {
        if (D_0035f4ec[i].x == a3[found].x && D_0035f4ec[i].y == a3[found].y && D_0035f4ec[i].z == a3[found].z) {
            a3[found].x = -1;
            a3[found].y = -1;
            a3[found].z = -1;
            return;
        }
    }
}
}  // namespace n002933d8
#undef D_0035f4ec

// 00293500 (was src/anon/batch_w1587.cpp)
namespace n00293500 {
extern u32 D_0035f4ec asm("D_0035f4ec");
u32 func_002933d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002933d8");
/*TARGET 00293500*/
// 0x00276fe8: definition moved into src/anon/unit_002748a0.cpp

void func_00293500(u32 a0, u32 a1, u32 a2) asm("func_00293500");
// 0x00276fe8: definition moved into src/anon/unit_002748a0.cpp

void func_00293500(u32 a0, u32 a1, u32 a2) { func_002933d8(a0, a1, a2, D_0035f4ec); }
}  // namespace n00293500

// 00293520 (was src/anon/batch_w95.cpp)
namespace n00293520 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct SeReq { s16 id; s16 pass; s16 arg; };
struct TaskInfo { u32 a; u32 name; };
// 0x00287910: definition moved into src/anon/unit_00286d28.cpp

extern u8 D_0035f4f0 asm("D_0035f4f0");
union SeReqRef { SeReq* p; s16 h; };
extern SeReqRef D_0035f4e8 asm("D_0035f4e8");
TaskInfo* func_00103eb0(void) asm("func_00103eb0");
s32 func_00102a38(u32, void (*)(void)) asm("func_00102a38");
// list_contains_id
void func_002933b8(void) asm("func_002933b8");
u32* func_001a8bd0(s32) asm("func_001a8bd0");
u32 func_001a8c10(u32*, s32) asm("func_001a8c10");
void func_00293350(s16, s16, s16) asm("func_00293350");
/*TARGET 00293520*/
void func_00293520(void) asm("func_00293520");
void func_00293520(void) {
    if (D_0035f4f0) return;
    if (func_00102a38(func_00103eb0()->name, func_002933b8)) return;
    s32 id = func_001a8c10(func_001a8bd0(-1), 3);
    s32 found = -1;
    for (s32 pass = 0; pass < 2; pass++) {
        for (s32 i = 0; i < 8; i++) {
            if (D_0035f4e8.p[i].id == id) {
                D_0035f4e8.p[i].id = -1;
                D_0035f4e8.p[i].pass = -1;
                D_0035f4e8.p[i].arg = -1;
            } else if (D_0035f4e8.p[i].id >= 0 && D_0035f4e8.p[i].pass == pass) {
                found = i;
                break;
            }
        }
        if (found >= 0) break;
    }
    if (found >= 0) {
        func_00293350(D_0035f4e8.p[found].id, D_0035f4e8.p[found].pass, D_0035f4e8.p[found].arg);
        D_0035f4e8.p[found].id = -1;
        D_0035f4e8.p[found].pass = -1;
        D_0035f4e8.p[found].arg = -1;
    }
}
}  // namespace n00293520

// 00293668 (was src/anon/batch_w44.cpp)
namespace n00293668 {
u8* func_00103eb0(void) asm("func_00103eb0");
s32 func_00102a38(void*, void*) asm("func_00102a38");
void func_002933b8(void) asm("func_002933b8");
// Tz::LoadDataIsFlushing(): true while load data is still being flushed.
// 00292630: moved to src/anon/unit_00292620.cpp

extern s16* D_0035f4e8 asm("D_0035f4e8");
/*TARGET 00293668*/
s32 func_00293668(void) asm("func_00293668");
s32 func_00293668(void) {
    s32 r = 0;
    if (!func_00102a38(*(void**)(func_00103eb0() + 4), (void*)func_002933b8)) {  // list_contains_id
        s16* p = D_0035f4e8;
        for (s32 i = 0; i < 8; i++, p += 3) {
            if (*p >= 0) { r = 1; break; }
        }
    } else {
        r = 1;
    }
    return r;
}
}  // namespace n00293668

// 002936d8 (was src/anon/batch_w1587.cpp)
namespace n002936d8 {
extern u8 D_0035f4f0 asm("D_0035f4f0");
/*TARGET 002936d8*/
void func_002936d8(void) asm("func_002936d8");
void func_002936d8(void) { D_0035f4f0 = 1; }
}  // namespace n002936d8

// 002936e8 (was src/anon/tiny.cpp)
namespace n002936e8 {
/*TARGET 002936e8*/
// 0x0028b248: definition moved into src/anon/unit_00288b00.cpp

void func_002936e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002936e8jjjj");
// 0x0028b248: definition moved into src/anon/unit_00288b00.cpp

void func_002936e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + (-2832)) = (u8)0;
}
}  // namespace n002936e8

// 002936f8 (was src/anon/tiny.cpp)
namespace n002936f8 {
/*TARGET 002936f8*/
u32 func_002936f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002936f8jjjj");
u32 func_002936f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-2832)));
}
}  // namespace n002936f8

// 00293708 (was src/anon/batch_w1590_g.cpp)
namespace n00293708 {
struct W1590C4 { u8 b[4]; };
u32 func_00103570(void) asm("func_00103570");
void* func_001063c0(s32, u32) asm("func_001063c0");
void func_001a8bb8(void*) asm("func_001a8bb8");
W1590C4* func_001a8bd0(s32) asm("func_001a8bd0");
extern W1590C4* D_0035f4f4 asm("D_0035f4f4");
extern u8 D_0035f4f8 asm("D_0035f4f8");
extern u8 D_0035f4f9 asm("D_0035f4f9");
extern u8 D_0035f4fa asm("D_0035f4fa");
/*TARGET 00293708*/
void func_00293708(void) asm("func_00293708");
void func_00293708(void) {
    W1590C4* p;
    D_0035f4fa = 1;
    D_0035f4f8 = 0;
    D_0035f4f9 = 0;
    p = (W1590C4*)func_001063c0(4, func_00103570());
    func_001a8bb8(p);
    D_0035f4f4 = p;
    *p = *func_001a8bd0(-1);
}
}  // namespace n00293708

// 00293780 (was src/anon/tiny_auto80_queue.cpp)
namespace n00293780 {
// 0x00277070: definition moved into src/anon/unit_002748a0.cpp

extern "C" u32 func_00106450(...) asm("func_00106450");
/*TARGET 00293780*/
void func_00293780() asm("_Z13func_00293780v");
void func_00293780() {
    u32 base = 0x00360000u;
    u32 p = *(u32*)(base + (s32)-2828);
    if (p != 0) {
        func_00106450((void*)p);
        *(u32*)(base + (s32)-2828) = 0;
    }

    base = 0;
    u32 base2 = 0x00360000u;
    *(u8*)(base2 + (s32)-2824) = 0;
}
}  // namespace n00293780

// 002937c0 (was src/anon/batch_w60.cpp)
namespace n002937c0 {
extern u8 D_0035f4f8 asm("D_0035f4f8");
extern u8 D_0035f4f9 asm("D_0035f4f9");
extern u8 D_0035f4fa asm("D_0035f4fa");
s32 func_002938f0(void) asm("func_002938f0");
void func_00170320(s32) asm("func_00170320");
u8* func_00103eb0(void) asm("func_00103eb0");
void func_00102818(u32, s32, u32, void (*)(), s32) asm("func_00102818");
void func_00293848() asm("func_00293848");
/*TARGET 002937c0*/
// 0x00287430: definition moved into src/anon/unit_00286d28.cpp

void func_002937c0(void) asm("func_002937c0");
// 0x00287430: definition moved into src/anon/unit_00286d28.cpp

void func_002937c0(void) {
    if (func_002938f0()) {
        D_0035f4f9 = 0;

    }
    if (D_0035f4f9 == 0) {
        D_0035f4f9 = 1;
        D_0035f4f8 = 0;
        D_0035f4fa = 0;
        func_00170320(5100);
        func_00102818(*(u32*)(func_00103eb0() + 4), 0, 0x222e0, func_00293848, 4096);
    }
}
}  // namespace n002937c0

// 00293848 (gap: party member task)
namespace g00293848 {
u32* func_001a8bd0(s32) asm("func_001a8bd0");
s32 func_001a8bf8(void*, s32) asm("func_001a8bf8");
u32 func_002812c8(s32) asm("func_002812c8");
void func_0016ed50(u32, u32, u32) asm("func_0016ed50");
void func_00170888(u32) asm("func_00170888");
void task(u32 a0) asm("D_00293848");
void task(u32 a0) {
    u32* m = func_001a8bd0(-1);
    s32 i;
    for (i = 0; i < 4; i++) {
        if (func_001a8bf8(m, i) != 18) {
            func_0016ed50(func_002812c8(i) | 0x20000000, 5100, 30);
        }
    }
    func_00170888(a0);
}
}  // namespace g00293848

// 002938e0 (was src/tozawa/chg_member.cpp)
namespace Tz { // method 002938e0
extern u8 D_0035f4f9 asm("D_0035f4f9");
/*TARGET 002938e0*/
u32 ChgMember::isLoadExec() {
    (void)D_0035f4f9;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-2823)));
}
}  // Tz

// 002938f0 (was src/tozawa/chg_member.cpp)
namespace Tz { // method 002938f0
extern u8 D_0035f4f9 asm("D_0035f4f9");
u32 func_00102a38(...) asm("func_00102a38");
// list_contains_id
extern "C" u32 func_00103eb0(...) asm("func_00103eb0");
u32 func_00170cd0(...) asm("func_00170cd0");
extern u8 D_00293848 asm("D_00293848");
/*TARGET 002938f0*/
u32 ChgMember::isLoadFinish() {
    if (D_0035f4f9 == 0) {
        return 0;
    }
    if (func_00102a38(*(u32*)(func_00103eb0() + 4), (u32)&D_00293848) != 0) {  // list_contains_id
        return 0;
    }
    return (func_00170cd0() ^ 1) & 0xff;
}
}  // Tz

// 00293948 (was src/anon/batch_w110.cpp)
namespace n00293948 {
struct JmSrc { u8 pad[18]; u16 f18; u16 f20; };
JmSrc* func_001a8b28(void) asm("func_001a8b28");
struct ReqObj { u32 f0; u32 f4; u32 f8; u32 f12; };
struct SysA { u32 f0; u32 f4; };
struct Tbl16 { u8 pad[16]; u16 v[1]; };
extern u8 D_0035f4f8 asm("D_0035f4f8");
extern void* D_0035f4f4 asm("D_0035f4f4");
void* func_001a8bd0(s32) asm("func_001a8bd0");
void func_00170320(s32) asm("func_00170320");
s32 func_001a8bf8(void*, s32) asm("func_001a8bf8");
// get_bits5_at
void func_001a8ff8(void*, s32, s32) asm("func_001a8ff8");
// swap_bytes
s32 func_00253598(void) asm("func_00253598");
SysA* func_00103eb0(void) asm("func_00103eb0");
ReqObj* func_00102818(u32, s32, s32, void*, s32) asm("func_00102818");
u32 func_001a8c10(void*, s32) asm("func_001a8c10");
u32 func_0017e668(u32) asm("func_0017e668");
void func_00293b08(void) asm("func_00293b08");
/*TARGET 00293948*/
// Starts the party-change request once (flag D_0035f4f8) when the slot setup differs.
u8 func_00293948(void) asm("func_00293948");
// Starts the party-change request once (flag D_0035f4f8) when the slot setup differs.
u8 func_00293948(void) {
    void* cur = func_001a8bd0(-1);
    if (D_0035f4f8) return D_0035f4f8;
    func_00170320(5100);
    D_0035f4f8 = 1;
    if (func_001a8bf8(cur, 1) != func_001a8bf8(D_0035f4f4, 1) && func_001a8bf8(cur, 2) != func_001a8bf8(D_0035f4f4, 2))
        func_001a8ff8(cur, 1, 2);  // swap_bytes
    s32 k = func_001a8bf8(cur, 3);  // get_bits5_at
    if (k != 18) {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (i != 0 && func_001a8bf8(D_0035f4f4, i) == k) break;
        }
        if (i != 3) {
            if (func_00253598()) {
                ReqObj* o = func_00102818(func_00103eb0()->f4, 0, 0x222e0, (void*)func_00293b08, 6144);
                Tbl16* t = (Tbl16*)func_001a8b28();  // get_data_1c7cc10
                u16 v = t->v[func_001a8bf8(func_001a8bd0(-1), 3)];
                o->f4 = func_0017e668(func_001a8c10(func_001a8bd0(-1), i));
                o->f8 = v;
                o->f12 = func_001a8c10(func_001a8bd0(-1), i);
            } else {
                func_001a8ff8(cur, i, 3);  // swap_bytes
            }
        }
    }
    return D_0035f4f8;
}
}  // namespace n00293948

// 00293b08 (gap: member change task)
namespace g00293b08 {
u32* func_001a8bd0(s32) asm("func_001a8bd0");
void func_001b5ce8(void*, s32, s32, s32) asm("func_001b5ce8");
void func_001b5cf8(void*, u8*) asm("func_001b5cf8");
void func_001a8f68(u32*, s32) asm("func_001a8f68");
void func_00170888(u8*) asm("func_00170888");
void task(u8* p) asm("D_00293b08");
void task(u8* p) {
    u8 buf[16];
    s32 t = *(s32*)(p + 4);
    if (t) {
        func_001b5ce8(buf, 1, t, *(s32*)(p + 8));
        func_001b5cf8(buf, p);
        func_00170888(p);
    }
    func_001a8f68(func_001a8bd0(-1), *(s32*)(p + 12));
}
}  // namespace g00293b08

// 00293b70 (was src/anon/batch_w11.cpp)
namespace n00293b70 {
// 0028cc08: moved to src/anon/unit_0028c878.cpp

u8* func_00103eb0(void) asm("func_00103eb0");
u8 func_00102a38(u32, void (*)(void)) asm("func_00102a38");
// list_contains_id
void func_00293b08(void) asm("func_00293b08");
u32 ChgMember_isExec(void) asm("_ZN2Tz9ChgMember18isExecChangeMemberEv");
/*TARGET 00293b70*/
u32 ChgMember_isExec(void) asm("_ZN2Tz9ChgMember18isExecChangeMemberEv");
u32 ChgMember_isExec(void) {
    return func_00102a38(*(u32*)(func_00103eb0() + 4), func_00293b08);  // list_contains_id
}
}  // namespace n00293b70

// 00293ba0 (was src/anon/tiny.cpp)
namespace n00293ba0 {
/*TARGET 00293ba0*/
u32 func_00293ba0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00293ba0jjjj");
u32 func_00293ba0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-2822)));
}
}  // namespace n00293ba0

// 00293bb0 (was src/anon/tiny.cpp)
namespace n00293bb0 {
extern u32 D_0035f4fa asm("D_0035f4fa");
/*TARGET 00293bb0*/
// 0x0028b200: definition moved into src/anon/unit_00288b00.cpp

void func_00293bb0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00293bb0jjjj");
// 0x0028b200: definition moved into src/anon/unit_00288b00.cpp

void func_00293bb0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035f4fa = (u8)v;
}
}  // namespace n00293bb0

// 00293bc0 (was src/tozawa/chg_member.cpp)
namespace Tz { // method 00293bc0
extern u32 D_0035f4f4 asm("D_0035f4f4");
/*TARGET 00293bc0*/
// 0x00284048: definition moved into src/anon/unit_00283f50.cpp

void* ChgMember::GetMember() { return reinterpret_cast<void*>(D_0035f4f4); }
}  // Tz

// 00293bd0 (was src/anon/auto80_199_queue.cpp)
namespace n00293bd0 {
/*TARGET 00293bd0*/
/*AMBIG*/ void func_00293bd0(u32 a0, u32 a1, u32 a2);
void func_00293bd0(u32 a0, u32 a1, u32 a2) {
    u8 buf[128];
    u32 v = a2 & 0xff;
    if (v == 0) {
        func_00170cd0();
    }
    func_00293cb8(buf, a0, a1);
    u32 msg = 5100;
    msg = (a0 != 0) ? 5101 : msg;
    func_00292568(buf, msg, v);
}
}  // namespace n00293bd0

// 00293c40 (was src/tozawa/jm_data.cpp)
namespace Tz { // method 00293c40
u32 func_00292630(...) asm("func_00292630");
u32 func_0016e920(...) asm("func_0016e920");
u32 func_0016f470(...) asm("func_0016f470");
void func_00170a90(...) asm("func_00170a90");
void func_0016ed50(...) asm("func_0016ed50");
extern u8 D_0035f4b8 asm("D_0035f4b8");
/*TARGET 00293c40*/
void JMData::LoadObjRequest(s32 a0, bool a1) {
    u32 flag = (u32)a1 & 0xff;
    func_00292630((u32)a0);
    if (flag != 0) {
        u32 v = func_0016e920((u32)a0 | 0x30000000);
        v = func_0016f470(v, 0);
        func_00170a90(v);
    }
    func_0016ed50((u32)a0 | 0x30000000, 5103, 30);
    D_0035f4b8 = 1;
}
}  // Tz

// 00293cb8 (was src/anon/batch_w77.cpp)
namespace n00293cb8 {
extern const char* D_0035f508[] asm("D_0035f508");
extern const char* D_0035f500 asm("D_0035f500");
extern const char* D_0035f504 asm("D_0035f504");
void func_00253b30(char*, const char*) asm("func_00253b30");
void func_002feee8(char*, const char*) asm("func_002feee8");
/*TARGET 00293cb8*/
void func_00293cb8(char* buf, s32 k, const char* s) asm("func_00293cb8");
void func_00293cb8(char* buf, s32 k, const char* s)
{
    func_00253b30(buf, D_0035f508[k]);
    if (k == 2 && s) {
        func_002feee8(buf, s);
        func_002feee8(buf, D_0035f500);
    } else if (k == 3) {
        func_002feee8(buf, s);
        func_002feee8(buf, D_0035f504);
    } else if (k == 4) {
        func_002feee8(buf, s);
        func_002feee8(buf, D_0035f500);
    } else if (k == 5) {
        func_002feee8(buf, s);
        func_002feee8(buf, D_0035f504);
    }
}
}  // namespace n00293cb8

// 00293d80 (was src/tozawa/jm_data.cpp)
namespace Tz { // method 00293d80
u32 func_00292690(...) asm("_ZN2Tz8LoadData5ClearEi");
/*TARGET 00293d80*/
u32 JMData::Clear(s32 which) {
    u32 r15 = (u32)which;
    u32 r4 = 5100u;
    if (r15 != 0u) r4 = r15;
    return func_00292690(r4);
}
}  // Tz

// 00293da0 (was src/tozawa/jm_data.cpp)
namespace Tz { // method 00293da0
u32 func_001703a8(u32) asm("func_001703a8");
/*TARGET 00293da0*/
u32 JMData::Destroy(s32 which) { return func_001703a8((u32)which); }
}  // Tz

// 00293db8 (was src/tozawa/jm_data.cpp)
namespace Tz { // method 00293db8
void func_00293cb8(...) asm("func_00293cb8");
u32 func_002926a8(...) asm("func_002926a8");
/*TARGET 00293db8*/
u32 JMData::CacheAlloc(s32 a0, const char* a1) {
    u8 tmp[128];
    func_00293cb8(tmp, (u32)a0, (u32)a1);
    return func_002926a8(tmp);
}
}  // Tz

// 00293de8 (was src/tozawa/jm_album.cpp)
namespace Tz { // method 00293de8
extern u32 D_0035f520 asm("D_0035f520");
/*TARGET 00293de8*/
u32 JmAlbum::GetImageName(u32 index) {
    return *(u32*)((u32)&D_0035f520 + (index << 2));
}
}  // Tz

// 00293e00 (was src/anon/batch_w239.cpp)
namespace n00293e00 {
void* func_001063c0(s32, s32) asm("func_001063c0");
void func_002907c0(void*, s32, s32) asm("func_002907c0");
extern s32 D_0035f570 asm("D_0035f570");
extern void* D_0035f574 asm("D_0035f574");
extern u32* D_0035f578 asm("D_0035f578");
/*TARGET 00293e00*/
void func_00293e00(s32 a) asm("func_00293e00");
void func_00293e00(s32 a) {
    D_0035f570 = a;
    void* p = func_001063c0(24, D_0035f570);
    func_002907c0(p, D_0035f570, 10);
    D_0035f574 = p;
    u32* q = (u32*)func_001063c0(64, D_0035f570);
    u32* t = q;
    for (s32 i = 15; i >= 0; i--) *t++ = 0;
    s32 j = 15;
    D_0035f578 = q;
    u32* r = *(u32* volatile*)&D_0035f578;
    for (; j >= 0; j--) *r++ = 0;
}
}  // namespace n00293e00

// 00293eb0 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 00293eb0
extern u32 D_0035f570 asm("D_0035f570");
extern u32 D_0035f574 asm("D_0035f574");
extern u32 D_0035f578 asm("D_0035f578");
void LoadDataFree(...) asm("_ZN2Tz12LoadDataFreeEz");
/*TARGET 00293eb0*/
// 00290940: moved to src/anon/unit_0028f1e0.cpp

void JmInfo::Exit() {
    if (D_0035f574 != 0) {
        if (IsLoaded(D_0035f574) != 0) {
            Unload(D_0035f574);
        }
    }
    if (D_0035f574 != 0) {
        u32 p = D_0035f574;
        ((void (*)(u32))(*(u32*)(*(u32*)p + 4)))(p);
        D_0035f574 = 0;
    }
    if (D_0035f578 != 0) {
        LoadDataFree(D_0035f578);
        D_0035f578 = 0;
    }
    D_0035f570 = 0;
}
}  // Tz

// 00293f40 (was src/anon/tiny_auto80_queue.cpp)
namespace n00293f40 {
/*TARGET 00293f40*/
u32 func_00293f40(u32 a0) asm("_Z13func_00293f40j");
u32 func_00293f40(u32 a0) {
    u32 base = 0x00360000u;
    u32 obj = *(u32*)(base + (s32)-2704);
    u32 vtbl = *(u32*)obj;
    u32 fn = *(u32*)vtbl;
    u32 ra = (u32)__builtin_return_address(0);
    return ((u32(*)(u32, u32, u32))fn)(obj, a0, ra);
}
}  // namespace n00293f40

// 00293f78 (was src/anon/batch_w17.cpp)
namespace n00293f78 {
typedef void (*VFn2)(void*, void*);
extern void* D_0035f570 asm("D_0035f570");
/*TARGET 00293f78*/
void func_00293f78(void* a) asm("func_00293f78");
void func_00293f78(void* a) {
    if (a) {
        void* o = D_0035f570;
        (*(VFn2*)((*(u8**)o) + 4))(o, a);
    }
}
}  // namespace n00293f78

// 00293fb0 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 00293fb0
extern u32 D_0035f570 asm("D_0035f570");
/*TARGET 00293fb0*/
u32 JmInfo::isInit() { return (D_0035f570 != 0); }
}  // Tz

// 00293fc0 (was src/anon/batch_w18.cpp)
namespace n00293fc0 {
// 0x0026ec70: definition moved into src/anon/unit_0026c450.cpp

extern void* D_0035f574 asm("D_0035f574");
void func_00290940(void*) asm("func_00290940");
u32 func_00293db8(u32, u32) asm("func_00293db8");
void func_00290960(void*, u32, u32) asm("func_00290960");
/*TARGET 00293fc0*/
void func_00293fc0(void) asm("func_00293fc0");
void func_00293fc0(void) {
    func_00290940(D_0035f574);
    func_00290960(D_0035f574, func_00293db8(0, 0), 43);
}
}  // namespace n00293fc0

// 00294000 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 00294000
/*TARGET 00294000*/
u32 JmInfo::GetData(s32 index) {
    u32 r5 = (u32)index;
    u32 r15 = (u32)(0x0036u << 16);
    u32 r4 = *(u32*)((u32)r15 + (s32)(-2700));
    return GetDataImpl(r4, r5);
}
}  // Tz

// 00294020 (was src/anon/batch_w1935.cpp)
namespace n00294020 {
typedef struct R3_w { u8 pad[4]; u16 id; u8 pad2[0x1e]; } R3_w;
typedef struct E5_w { u16 id; u8 pad[6]; } E5_w;
typedef struct R5_w { u8 pad[5]; s8 n; u8 pad2[2]; s32 off; } R5_w;
typedef struct T_w { u8 pad[8]; s32 n; u8 pad2[4]; } T_w;
T_w* func_00294000(s32) asm("func_00294000");
s32 func_00294368(R3_w*) asm("func_00294368");
s32 func_00294480(R5_w*) asm("func_00294480");
extern u32* D_0035f578 asm("D_0035f578");
/*TARGET 00294020*/
void func_00294020(u32* bits) asm("func_00294020");
void func_00294020(u32* bits)
{
    if (bits == 0) bits = D_0035f578;
    T_w* t = func_00294000(3);
    R3_w* r3 = (R3_w*)(t + 1);
    u32* p = bits;
    for (s32 k = 15; k >= 0; k--) *p++ = 0;
    s32 i;
    u16 id;
    for (i = 0; i < t->n; i++) {
        if (func_00294368(&r3[i])) {
            id = r3[i].id;
            u32* w = bits + (id >> 5);
            *w |= 1 << (id & 0x1f);
        }
    }
    T_w* t5 = func_00294000(5);
    R5_w* r5 = (R5_w*)(t5 + 1);
    for (i = 0; i < t5->n; i++) {
        if (func_00294480(&r5[i])) {
            E5_w* e = (E5_w*)((u8*)t5 + r5[i].off);
            for (s32 j = 0; j < r5[i].n; j++) {
                id = e[j].id;
                u32* w = bits;
                w += id >> 5;
                *w |= 1 << (id & 0x1f);
            }
        }
    }
}
}  // namespace n00294020

// 002941a8 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 002941a8
/*TARGET 002941a8*/
u32 JmInfo::isWorldOpen(JmWorldDataInfo const* info) {
    u32 r15 = (u32)(s32)(*(s8*)((u32)info + (s32)(0)));
    r15 = ((s32)r15 < (16));
    u32 r2 = 1u;
    if (r15 != 0u) {
        u32 r4 = (u32)(*(u16*)((u32)info + (s32)(8)));
        r2 = YS::PROGRESS::CheckFlag((s32)r4);
    }
    return r2;
}
}  // Tz

// 002941d8 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 002941d8
/*TARGET 002941d8*/
u32 JmInfo::isWorldChgName(JmWorldDataInfo const* info) {
    u32 r2 = 0u;
    u32 r15 = (u32)(*(u16*)((u32)info + (s32)(14)));
    u32 r4 = r15;
    if (r15 != 0u) {
        r2 = YS::PROGRESS::CheckFlag((s32)r4);
    }
    return r2;
}
}  // Tz

// 00294208 (was src/anon/batch_w48.cpp)
namespace n00294208 {
// 0x00275f08: definition moved into src/anon/unit_002748a0.cpp

u8* func_00294000(s32) asm("func_00294000");
u8 func_002941d8(u8*) asm("func_002941d8");
/*TARGET 00294208*/
s32 func_00294208(s32 id) asm("func_00294208");
s32 func_00294208(s32 id) {
    u8* t = func_00294000(0);
    s32 n = *(s32*)(t + 8);
    u8* e = t + 16;
    for (s32 i = 0; i < n; i++, e += 16) {
        if (*(s8*)e == id) return func_002941d8(e);
    }
    return 0;
}
}  // namespace n00294208

// 00294268 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 00294268
/*TARGET 00294268*/
u32 JmInfo::isEnableStory(JmStoryDataInfo const* info) {
    u32 r4 = (u32)(*(u16*)((u32)info + (s32)(10)));
    u32 r2 = YS::PROGRESS::CheckFlag((s32)r4);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // Tz

// 00294288 (was src/anon/batch_wcx2.cpp)
namespace n00294288 {
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
// ---- 00295158
u8* func_00294000(u32) asm("func_00294000");
// ---- 00294288
union UH_294288 { u16 h; u32 i; };
s32 func_00294268(u8*) asm("func_00294268");
/*TARGET 00294288*/
void func_00294288(s32 id, u32* a, u32* b) asm("func_00294288");
void func_00294288(s32 id, u32* a, u32* b) {
    u8* t = func_00294000(1);
    *b = 0x8adc;
    *a = 0x8adc;
    u8* base = t + 16;
    for (s32 i = 0; i < *(s32*)(t + 8); i++) {
        u8* e = base + i * 12;
        if (*(s8*)e == id && func_00294268(e)) {
            *a = ((UH_294288*)(e + 4))->h;
            *b = ((UH_294288*)(e + 6))->h;
        }
    }
}
}  // namespace n00294288
#undef QCOPY

// 00294348 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 00294348
/*TARGET 00294348*/
u32 JmInfo::isEnableAlbum(JmAlbumDataInfo const* info) {
    u32 r4 = (u32)(*(u16*)((u32)info + (s32)(6)));
    u32 r2 = YS::PROGRESS::CheckFlag((s32)r4);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // Tz

// 00294368 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 00294368
/*TARGET 00294368*/
u32 JmInfo::GetDefeatCnt(JmCharaDataInfo const* info) {
    u32 r15 = (u32)(*(u16*)((u32)info + (s32)(16)));
    r15 = (u32)(r15 & 0x0800u);
    u32 r2 = 0u;
    if (r15 != 0u) {
        u32 r4 = (u32)(*(u16*)((u32)info + (s32)(12)));
        r2 = GetCharaData(r4);
        u32 r16 = (u32)(*(u16*)((u32)r2 + (s32)(76)));
        r2 = JiminyGetBase();
        r4 = (u32)((s32)r2 + (9456));
        r2 = FindDefeatCount(r4, r16);
    }
    return r2;
}
}  // Tz

// 002943b0 (was src/anon/auto200_999.cpp)
namespace n002943b0 {
extern u32* D_0035f578 asm("D_0035f578");
/*TARGET 002943b0*/
// 0x001aa6f0: definition moved into src/anon/unit_001a9130.cpp

u32 func_002943b0(u32 a0) asm("_Z13func_002943b0j");
// 0x001aa6f0: definition moved into src/anon/unit_001a9130.cpp

u32 func_002943b0(u32 a0) {  // test_bit_global_array
    u32 bit = *(u16*)(a0 + 4);
    return (D_0035f578[bit >> 5] & (1 << (bit & 31))) != 0;
}
}  // namespace n002943b0

// 002943e8 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 002943e8
/*TARGET 002943e8*/
u32 JmInfo::isHaveAnsem(JmAnsemDataInfo const* info) {
    u32 r4 = (u32)(*(u16*)((u32)info + (s32)(0)));
    u32 r2 = HasAnsemEntry(r4);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // Tz

// 00294408 (was src/anon/batch_w40.cpp)
namespace n00294408 {
// 002914a8: moved to src/anon/unit_00290f78.cpp

s32 func_00181500(u16) asm("func_00181500");
s32 func_001a3570(u16) asm("func_001a3570");
/*TARGET 00294408*/
s32 func_00294408(u16* p) asm("func_00294408");
s32 func_00294408(u16* p) {
    s32 r = 0;
    if (*(s8*)(p + 3) != 2) { if (func_00181500(p[0])) r = 1; }
    else r = func_001a3570(p[0]) > 0;
    if (p[1] && func_00181500(p[1])) r = 0;
    return r;
}
}  // namespace n00294408

// 00294480 (was src/anon/batch_w25.cpp)
namespace n00294480 {
// 0x00284ea8: definition moved into src/anon/unit_00284220.cpp

s32 func_00181500(u16) asm("func_00181500");
s32 func_001a3570(u16) asm("func_001a3570");
/*TARGET 00294480*/
s32 func_00294480(u16* o) asm("func_00294480");
s32 func_00294480(u16* o) {  // record_lookup_success
    s32 r = 0;
    if (((s8*)o)[6] != 2) {
        if (func_00181500(o[0])) r = 1;
    } else {
        r = func_001a3570(o[0]) > 0;
    }
    return r;
}
}  // namespace n00294480

// 002944d0 (was src/tozawa/jm_info.cpp)
namespace Tz { // method 002944d0
/*TARGET 002944d0*/
u32 JmInfo::isEnableLimit(JmLimitDataInfo const* info) {
    u32 r4 = (u32)(*(u16*)((u32)info + (s32)(0)));
    u32 r2 = GetLimitEntry(r4);
    r4 = r2;
    r2 = IsLimitEnabled(r4);
    r2 = ((s32)0u < (s32)r2);
    return r2;
}
}  // Tz

// 002944f8 (was src/anon/batch_w1583_g.cpp)
namespace n002944f8 {
s32 func_00103570(void) asm("func_00103570");
s32 func_001063c0(s32, s32) asm("func_001063c0");
void func_0023f800(s32) asm("func_0023f800");
extern s32 D_0035f57c asm("D_0035f57c");
extern u8 D_0035f580 asm("D_0035f580");
extern u8 D_0035f581 asm("D_0035f581");
/*TARGET 002944f8*/
// 0x0027d450: definition moved into src/anon/unit_0027d2e8.cpp
void func_002944f8(void) asm("func_002944f8");
// 0x0027d450: definition moved into src/anon/unit_0027d2e8.cpp
void func_002944f8(void) {
    D_0035f580 = 0;
    D_0035f581 = 0;
    s32 r = func_001063c0(0x1C, func_00103570());
    func_0023f800(r);
    D_0035f57c = r;
}
}  // namespace n002944f8

// 00294550 (was src/anon/batch_w26.cpp)
namespace n00294550 {
extern u8 D_0035f580 asm("D_0035f580");
extern u8 D_0035f581 asm("D_0035f581");
extern void* D_0035f57c asm("D_0035f57c");
struct Obj { void (**vt)(Obj*); };
/*TARGET 00294550*/
// 0028e6c0: moved to src/anon/unit_0028c878.cpp

void func_00294550(void) asm("func_00294550");
// 0028e6c0: moved to src/anon/unit_0028c878.cpp

void func_00294550(void) {
    D_0035f580 = 0;
    D_0035f581 = 0;
    Obj* o = (Obj*)D_0035f57c;
    if (o) {
        o->vt[1](o);
        D_0035f57c = 0;
    }
}
}  // namespace n00294550

// 002945a0 (was src/anon/misc_2.cpp)
namespace n002945a0 {
/*TARGET 002945a0*/
// 0x0028b8d8: definition moved into src/anon/unit_00288b00.cpp

void func_002945a0(void* self) asm("_Z13func_002945a0Pv");
// 0x0028b8d8: definition moved into src/anon/unit_00288b00.cpp

void func_002945a0(void* self) {}
}  // namespace n002945a0

// 002945a8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002945a8 {
u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
u32 func_00287bc0(...) asm("func_00287bc0");
u32 func_00294ea8(...) asm("func_00294ea8");
/*TARGET 002945a8*/
u32 func_002945a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002945a8jjjjjjjj");
u32 func_002945a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00287bc0)();
    if (r2 == 0u) {
        r2 = ((u32(*)())func_00294ea8)();
        r2 = ((u32(*)())func_00274ac8)();
        r15 = (u32)(0x0036u << 16);
        *(u8*)((u32)r15 + (s32)(-2687)) = (u8)0u;
    }
    return r2;
}
}  // namespace n002945a8

// 002945e8 (was src/anon/batch_w3805_nsamam.cpp)
namespace n002945e8 {
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00139620(u8*) asm("func_00139620");
void func_00275a80(void) asm("func_00275a80");
void func_00275f68(s32, s32) asm("func_00275f68");
void func_00276088(s32, s32*, s32*) asm("func_00276088");
u8* func_00276348(void) asm("func_00276348");
s8* func_00276568(void) asm("func_00276568");
void func_00276588(s32) asm("func_00276588");
u8* func_002766d0(void) asm("func_002766d0");
s32 func_00276c18(void) asm("func_00276c18");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00288d80(s32, s32, s32, s32, s32, s32, u16*, u16*) asm("func_00288d80");
void func_00288e88(s32) asm("func_00288e88");
u8* func_002891b8(s32, s32) asm("func_002891b8");
void func_002891f0(s32, s32, s32, s32, s32) asm("func_002891f0");
s32 func_0028af88(s32) asm("func_0028af88");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_0028af90(s32, s32) asm("func_0028af90");
void func_0028b078(s32, s32, s32) asm("func_0028b078");
void func_0028b200(s32, s32) asm("func_0028b200");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
struct T294 { u8 pad[8]; s32 n; };
T294* func_00294000(s32) asm("func_00294000");
s32 func_002941a8(s8*) asm("func_002941a8");
void func_00294998(void) asm("func_00294998");
void func_00294e48(void) asm("func_00294e48");
void func_00294f78(s32) asm("func_00294f78");
s32 func_002952f8(s32) asm("func_002952f8");
void func_002955a8(void) asm("func_002955a8");
s32 func_002ac9b0(s32) asm("func_002ac9b0");
s32 func_002acb20(s32) asm("func_002acb20");
s32 func_002ae908(s32) asm("func_002ae908");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f150 asm("D_0035f150");
extern u16 D150h asm("D_0035f150");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_003746b4 asm("D_003746b4");
extern s32 D_003746b8 asm("D_003746b8");
struct Sub208 { u8 pad[184]; s32 flags; };
struct E408 { u8 pad[24]; Sub208 sub; u8 pad2[408 - 212]; };
struct B408 { u8 pad[30360]; E408 e[64]; };
/*TARGET 002945e8*/
void func_002945e8(void) asm("func_002945e8");
void func_002945e8(void)
{
    u16 arr[2][4];
    s32 a, b;
    s32 i = 0;
    T294* t;
    s8* ents;
    u8* w = func_00276348();
    u8* base = func_002766d0();
    func_00276588(0);
    func_00288e88(D_0035f200);
    func_00294e48();
    func_00275a80();
    func_00276088(func_00287bc0(), &a, &b);
    func_00275f68(a, b);
    t = func_00294000(0);
    ents = (s8*)t + 16;
    do {
        u16* p = (u16*)(i * 8 + (u32)arr);
        s32 j = 3;
        do {
            *p = D150h;
            j--;
            p++;
        } while (j >= 0);
        i++;
    } while (i < 2);
    u8* q = base;
    i = 0;
    s32 v2 = D_0035f3d4 + 2;
    s32 v3 = D_0035f3d4 + 3;
    do {
        func_00288d80(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, arr[0], arr[1]);
        u8* o = func_002891b8(D_0035f200, i++);
        func_00139620(o);
        func_0028dcc0(o, w);
        u8* e = q + 30360;
        func_0028d8c0(e, v2, D_0035f14c, D_0035f148, D_0035f210, D_0035f150, -1, 0);
        func_0028dcc0(e, o);
        ((Sub208*)(q + 30360 + 24))->flags |= 8;
        e = q + 0xa998;
        q += 408;
        func_0028d8c0(e, v3, D_0035f14c, D_0035f148, D_0035f210, D_0035f150, -1, 0);
        func_0028dcc0(e, o);
        { Sub208* s = (Sub208*)(e + 24); s->flags |= 8; }
    } while (i < 18);
    B408* bb = (B408*)base;
    s32 cnt = 0;
    s32 n = t->n;
    if (n > 0) {
        i = n;
        s8* e = ents;
        do {
            if (*e < 16) {
                s32 r = func_002941a8(e);
                s32 c = *e;
                if (r || func_00276c18()) {
                    func_00138c10(func_002891b8(D_0035f200, cnt), 173);
                    *(s32*)(func_002891b8(D_0035f200, cnt) + 392) = -1;
                    if (r) {
                        if (func_002ac9b0(c)) func_00138c10((u8*)&bb->e[cnt + 32], func_002acb20(c) ? D_003746b8 : D_003746b4);
                        if (func_002ae908(c)) func_00138c10((u8*)&bb->e[cnt], 176);
                    }
                    cnt++;
                }
            }
            e += 16;
        } while (--i);
    }
    func_00294f78(0);
    s32 c = *func_00276568();
    if (c < 0) c = 15;
    func_002891f0(D_0035f200, func_002952f8(c), 0, -1, -1);
    func_0028b078(D_0035f200, 6, 3);
    func_0028b200(D_0035f200, 1);
    func_0028af90(D_0035f200, cnt);
    func_0028af18(D_0035f200, func_0028af88(D_0035f200) | 0x3000);
    func_00294998();
    func_002955a8();
    func_00287cc0(0);
}
}  // namespace n002945e8

// 00294998 (was src/anon/perm_00294998.cpp)
namespace n00294998 {
typedef unsigned char u8;
typedef signed int s32;
extern s32 D_0035f200 asm("D_0035f200");
s32 func_0028afa8(s32) asm("_ZN2Tz6Select12GetSelectMaxEv");
u8 *func_002891b8(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
s32 func_0023aa78(u8 *) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
s32 func_0023aa98(u8 *) asm("_ZN2YI8SEQUENCE10GetParamExEv");
void func_00138c68(u8 *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
inline int inline_fn(s32 arg0, int arg1)
{
  return arg0 + arg1;
}
/*TARGET 00294998*/
void func_00294998(void) asm("func_00294998");
void func_00294998(void)
{
  s32 row = 0;
  s32 n = func_0028afa8(D_0035f200);
  s32 a = func_0023aa78(func_002891b8(D_0035f200, 0) + 24);
  s32 b = func_0023aa98(func_002891b8(D_0035f200, 0) + 24);
  s32 cols = (n < 7) ? (n) : (6);
  s32 x0;
  s32 rows = inline_fn((n % 6) != 0, n / 6);
  x0 = -((b * (cols - 1)) / 2);
  s32 y0 = -((a * (rows - 1)) / 2);
  s32 i;
  for (; row < rows; row++)
  {
    if (n < inline_fn(row * 6, 6))
    {
      x0 = -((b * ((n % 6) - 1)) / 2);
    }
    for (i = 0; i < cols; i++)
    {
      func_00138c68(func_002891b8(D_0035f200, inline_fn(row * 6, i)), inline_fn(x0, i * b), y0 + (row * a));
    }

  }

}
}  // namespace n00294998

// 00294b80 (was src/anon/batch_w1584_g.cpp)
namespace n00294b80 {
extern u8 D_00295710[] asm("D_00295710");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00276368() asm("func_00276368");
s32 func_00276888() asm("func_00276888");
void func_00287f90(s32) asm("func_00287f90");
void func_002945a8() asm("func_002945a8");
s32 func_00292630() asm("func_00292630");
void func_00287c30() asm("func_00287c30");
void func_0028b0e0(s32) asm("func_0028b0e0");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_00274cf0(s32) asm("func_00274cf0");
void func_002925c0() asm("func_002925c0");
s32 func_00276358() asm("func_00276358");
void func_00276220(s32, s32) asm("func_00276220");
void func_002958b0() asm("func_002958b0");
void func_002995e8() asm("func_002995e8");
void func_00294f00() asm("func_00294f00");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00276398() asm("func_00276398");
void func_00275b60() asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
void func_00295508() asm("func_00295508");
void func_002956a0() asm("func_002956a0");
s32 func_00287df0(s32, s32, s32, void*, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0() asm("func_00287da0");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
void func_00276150(s32, s32*, s32*) asm("func_00276150");
void func_00276dc0() asm("func_00276dc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00295228(s32) asm("func_00295228");
void func_00276578(s32) asm("func_00276578");
extern s32 D_0035f200 asm("D_0035f200");
s32 func_00287bc0() asm("func_00287bc0");
/*TARGET 00294b80*/
void func_00294b80(void) asm("func_00294b80");
void func_00294b80(void) {
    s32 r = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    s32 m = func_00287bc0();
    if (st == 2) {
        if (func_00276368() != 0 || func_00276888() != 0) {
            if (r != -1) {
                func_00287f90(0);
                func_002945a8();
            }
            return;
        }
        if (func_00292630() != 0) return;
        func_002945a8();
        func_00287c30();
        m = func_00287bc0();
        func_0028b0e0(D_0035f200);
        func_0028af18(D_0035f200, 0x73);
        func_00274cf0(m);
        func_002925c0();
        func_00276220(func_00276358(), 0);
        if (m == st) {
            func_002958b0();
        } else if (m == 13) {
            func_002995e8();
        }
        return;
    }
    func_00294f00();
    if ((r != -1 || func_00289310(D_0035f200) != 0) && func_00276398() == 0) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398() != 0) {
        func_00287c90(1);
        func_00295508();
        func_002956a0();
    }
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, D_00295710, 1)) == 0) {
        s32 x;
        s32 a;
        s32 b0, b1;
        switch (r) {
        case -4:
        case -2:
            func_00287da0();
            break;
        case -1:
            break;
        case -9:
        case -8:
            func_00276150(m, &b0, &b1);
            if (r == -8) {
                x = b1;
                a = 0;
            } else {
                x = b0;
                a = 1;
            }
            func_00276220(a, 1);
            func_00276dc0();
            func_00287c00(x);
            func_00287cc0(2);
            break;
        default:
            if (r >= 0) {
                r = func_00295228(r);
                func_00276578(r);
                func_00276220(0, 1);
                func_00276dc0();
                func_00287c00(r < 15 ? 2 : 13);
                func_00287cc0(2);
            }
            break;
        }
    }
    if (func_00288040() != 0) {
        func_00288018();
    }
}
}  // namespace n00294b80

// 00294e48 (was src/anon/batch_w47.cpp)
namespace n00294e48 {
extern u32 D_0035f57c asm("D_0035f57c");
extern u8 D_0035f580 asm("D_0035f580");
void func_0023f900(u32) asm("func_0023f900");
s32 func_00292630(void) asm("func_00292630");
u32 func_00293db8(s32, s32) asm("func_00293db8");
void func_0023fa08(u32, u32) asm("func_0023fa08");
/*TARGET 00294e48*/
void func_00294e48(void) asm("func_00294e48");
void func_00294e48(void) {
    func_0023f900(D_0035f57c);
    if (func_00292630()) return;
    func_0023fa08(D_0035f57c, func_00293db8(1, 0));
    D_0035f580 = 1;
}
}  // namespace n00294e48

// 00294ea8 (was src/anon/auto80_199_queue.cpp)
namespace n00294ea8 {
/*TARGET 00294ea8*/
void func_00294ea8(void) asm("_Z13func_00294ea8v");
void func_00294ea8(void) {
    if (D_0035f580 != 0) {
        if (func_0023f900(D_0035f57c) != 0) {
            func_0023fad0(D_0035f57c);
        }
    }
    func_00293d80(5101);
    D_0035f580 = 0;
}
}  // namespace n00294ea8

// 00294f00 (was src/anon/batch_wcx2.cpp)
namespace n00294f00 {
// ---- 00294f00
extern bool D_0035f580 asm("D_0035f580");
extern bool D_0035f581 asm("D_0035f581");
void func_00294e48() asm("func_00294e48");
void func_00294f78(u32) asm("func_00294f78");
/*TARGET 00294f00*/
void func_00294f00() asm("func_00294f00");
void func_00294f00() {
    if (D_0035f580 && D_0035f581) return;
    if (!D_0035f580) func_00294e48();
    if (D_0035f580 && !D_0035f581) func_00294f78(1);
}
}  // namespace n00294f00

// 00294f78 (was src/anon/batch_w3875_nsamam.cpp)
namespace n00294f78 {
extern u8 D_0035f580 asm("D_0035f580");
extern u8 D_0035f581 asm("D_0035f581");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f57c asm("D_0035f57c");
extern s32 D_0035f200 asm("D_0035f200");
u8* func_002766d0() asm("func_002766d0");
u8* func_00294000(u32) asm("func_00294000");
s32 func_002941a8(u8*) asm("func_002941a8");
s32 func_00276c18() asm("func_00276c18");
s32 func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(s32, s32) asm("func_0023c4b8");
s32 func_0023f988(s32, s32) asm("func_0023f988");
void func_002362b0(u8*, s32) asm("func_002362b0");
void func_001386e0(u8*, s32, s32, u8*, s32, s32) asm("func_001386e0");
void func_00139620(u8*) asm("func_00139620");
u8* func_002891b8(s32, s32) asm("func_002891b8");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
/*TARGET 00294f78*/
void func_00294f78(u8 flag) asm("func_00294f78");
void func_00294f78(u8 flag) {
    u8* w = func_002766d0();
    if (!D_0035f580) return;
    if (D_0035f581) return;
    s32 v;
    s32 cnt = 0;
    u8* t = func_00294000(0);
    s32 n = *(s32*)(t + 8);
    v = D_0035f3d4 + 1;
    u8* base = t + 16;
    if (n > 0) {
    u8* e = base;
    u8* a = w + 0xDCA0;
    s32 c = n;
    u8* o = w;
    u8* a2 = a;
    do {
        if (*(s8*)e < 16) {
            s32 r = func_002941a8(e);
            if (r || func_00276c18()) {
                s32 k = *(s8*)e;
                if (r == 0) k = 16;
                s32 x = func_0023c4b8(func_0023f1b0(D_0035f210), 2);
                func_002362b0(a, func_0023f988(D_0035f57c, k));
                a[400] = 1;
                s32 q, m;
                if (flag) { q = 1; m = 2; } else { q = 2; m = -1; }
                u8* p = o + 0x4398;
                func_001386e0(p, v, x, a2, q, 0);
                a += 416;
                *(s32*)(o + 0x4520) = m;
                func_00139620(p);
                a2 += 416;
                o[0x452d] = 1;
                *(u32*)(o + 0x4468) |= 8;
                s32 cc = cnt++;
                o += 408;
                func_0028dcc0(p, func_002891b8(D_0035f200, cc));
            }
        }
        e += 16;
    } while (--c);
    }
    D_0035f581 = 1;
}
}  // namespace n00294f78

// 00295158 (was src/anon/batch_wcx2.cpp)
namespace n00295158 {
// ---- 00295158
u8* func_00294000(u32) asm("func_00294000");
s32 func_002941a8(u8*) asm("func_002941a8");
s32 func_00276c18() asm("func_00276c18");
/*TARGET 00295158*/
s32 func_00295158(s32 k) asm("func_00295158");
s32 func_00295158(s32 k) {
    s32 cnt = -1;
    s32 res = -1;
    u8* t = func_00294000(0);
    u8* base = t + 16;
    for (s32 i = 0; i < *(s32*)(t + 8); i++) {
        u8* e = base + i * 16;
        if (*(s8*)e < 16 && (func_002941a8(e) || func_00276c18())) {
            cnt++;
            if (k == cnt) { res = i; break; }
        }
    }
    return res;
}
}  // namespace n00295158

// 00295228 (was src/anon/batch_w31.cpp)
namespace n00295228 {
u8* func_00294000(int) asm("func_00294000");
int func_00295158(u32) asm("func_00295158");
/*TARGET 00295228*/
// 0x00281f90: definition moved into src/anon/unit_00281cf0.cpp

s8 func_00295228(u32 x) asm("func_00295228");
// 0x00281f90: definition moved into src/anon/unit_00281cf0.cpp

s8 func_00295228(u32 x) {
    u8* base = func_00294000(0) + 16;
    return *(s8*)(base + func_00295158(x) * 16);
}
}  // namespace n00295228

// 00295270 (was src/anon/batch_w1768.cpp)
namespace n00295270 {
typedef struct JmE { u16 a0, a2, a4, a6, a8, aa, ac, ae; } JmE;
u8* func_00294000(s32) asm("func_00294000");
s32 func_002941d8(JmE*) asm("func_002941d8");
s32 func_00295158(s32) asm("func_00295158");
/*TARGET 00295270*/
u16 func_00295270(s32 a, u8 b) asm("func_00295270");
u16 func_00295270(s32 a, u8 b) {
    JmE* base = (JmE*)(func_00294000(0) + 16);
    a = func_00295158(a);
    a = (s32)(base + a);
    if (b) {
        if (func_002941d8((JmE*)a)) return ((JmE*)a)->ac;
        return ((JmE*)a)->a6;
    }
    if (func_002941d8((JmE*)a)) return ((JmE*)a)->aa;
    return ((JmE*)a)->a4;
}
}  // namespace n00295270

// 002952f8 (was src/anon/batch_w79.cpp)
namespace n002952f8 {
struct E16 { s8 id; u8 pad[15]; };
struct T294 { u8 pad[8]; s32 n; u8 pad12[4]; struct E16 e[1]; };
struct T294* func_00294000(s32) asm("func_00294000");
s32 func_002941a8(void*) asm("func_002941a8");
s32 func_00276c18(void) asm("func_00276c18");
/*TARGET 002952f8*/
// 0x001d61b8: definition moved into src/anon/unit_001d4f40.cpp

s32 func_002952f8(s32 id) asm("func_002952f8");
// 0x001d61b8: definition moved into src/anon/unit_001d4f40.cpp

s32 func_002952f8(s32 id) {
    s32 i = 0;
    s32 k = -1;
    s32 r = -1;
    struct T294* t = func_00294000(0);
    struct E16* e = t->e;
    for (; i < t->n; i++) {
        if (e[i].id < 20 && (func_002941a8(&e[i]) != 0 || func_00276c18() != 0)) {
            k++;
            if (e[i].id == id) {
                r = k;
                break;
            }
        }
    }
    return r;
}
}  // namespace n002952f8

// 002953c8 (was src/anon/batch_w48.cpp)
namespace n002953c8 {
// 0x00275f08: definition moved into src/anon/unit_002748a0.cpp

u8* func_00294000(s32) asm("func_00294000");
struct E2953 { s8 id; u8 pad[15]; };
/*TARGET 002953c8*/
E2953* func_002953c8(s32 id) asm("func_002953c8");
E2953* func_002953c8(s32 id) {
    u8* t = func_00294000(0);
    s32 n = *(s32*)(t + 8);
    E2953* e = (E2953*)(t + 16);
    s32 i;
    for (i = 0; i < n; i++) {
        if (e[i].id == id) break;
    }
    return &e[i];
}
}  // namespace n002953c8

// 00295430 (was src/anon/batch_wcx2.cpp)
namespace n00295430 {
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
// 0x001eaf50: definition moved into src/anon/unit_001e8ac8.cpp

// --------------------
struct E295430 { s8 key; u8 pad[3]; u16 a, b; u8 pad8[2]; u16 c, d; u8 pade[2]; };
struct T295430 { u8 pad[8]; s32 n; u8 pad2[4]; E295430 e[1]; };
T295430* func_00294000_295430(s32) asm("func_00294000");
s32 func_002941d8(E295430*) asm("func_002941d8");
/*TARGET 00295430*/
u16 func_00295430(s32 key, u8 alt) asm("func_00295430");
u16 func_00295430(s32 key, u8 alt)
{
    T295430* t = func_00294000_295430(0);
    s32 idx = -1;
    E295430* e = t->e;
    for (s32 i = 0; i < t->n; i++) {
        if (e[i].key == key) {
            idx = i;
            break;
        }
    }
    if (alt) {
        E295430* r = &e[idx];
        return func_002941d8(r) ? r->d : r->b;
    } else {
        E295430* r = &e[idx];
        return func_002941d8(r) ? r->c : r->a;
    }
}
}  // namespace n00295430
#undef QCOPY

// 002954e0 (was src/anon/batch_w5.cpp)
namespace Tz { // method 002954e0
u32 func_002953c8(s32) asm("func_002953c8");
u8 func_002941a8(u32) asm("func_002941a8");
// 0x0026c9c8: definition moved into src/anon/unit_0026c450.cpp
class JmWorldSel { public: static u32 isWorldOpen(s32); };
/*TARGET 002954e0*/
u32 JmWorldSel::isWorldOpen(s32 world) {
    return func_002941a8(func_002953c8(world));
}
}  // Tz

// 00295508 (was src/anon/batch_w8018_g.c)
namespace n00295508 {
extern s32 D_0035f200 asm("D_0035f200");
s32 func_00275e68(s32, s32, s32) asm("func_00275e68");
s32 func_00275ec8(s32) asm("func_00275ec8");
s32 func_002766d0() asm("func_002766d0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_0028de08(s32, s32, s32) asm("func_0028de08");
s32 func_00295270(s32, s32) asm("func_00295270");
s32 func_002956c0(s32) asm("func_002956c0");
/*TARGET 00295508*/
void func_00295508(void) asm("func_00295508");
void func_00295508(void) {
    s32 base = func_002766d0();
    s32 v = func_0028b040(D_0035f200);
    s32 s2 = func_00295270(v, 0);
    s32 p;
    if (func_002956c0(v) != 0) {
        func_00275e68(s2, base + 0x110A0, 0x40);
        return;
    }
    p = base + 0x110A0;
    p = func_0028de08(s2, p, 0x40);
    func_00275ec8(p);
}
}  // namespace n00295508

// 002955a8 (was src/anon/batch_w85.cpp)
namespace n002955a8 {
// 002926c0: moved to src/anon/unit_00292620.cpp

extern void* D_0035f200 asm("D_0035f200");
s32 func_0028afa8(void*) asm("func_0028afa8");
s32 func_0028b040(void*) asm("func_0028b040");
u8* func_002891b8(void*, s32) asm("func_002891b8");
void func_00138c10(void*, s32) asm("func_00138c10");
/*TARGET 002955a8*/
void func_002955a8(void) asm("func_002955a8");
void func_002955a8(void) {
    s32 i = 0;
    s32 n = func_0028afa8(D_0035f200);
    s32 cur = func_0028b040(D_0035f200);
    for (; i < n; i++) {
        if (*(s32*)(func_002891b8(D_0035f200, i) + 388) == 172) func_00138c10(func_002891b8(D_0035f200, i), 173);
        if (i == cur) func_00138c10(func_002891b8(D_0035f200, i), 172);
    }
}
}  // namespace n002955a8

// 00295668 (was src/anon/tiny_auto80_queue.cpp)
namespace n00295668 {
void func_00295508(...) asm("func_00295508");
void func_002955a8(...) asm("func_002955a8");
u32 func_00289310() asm("_ZN2Tz6Select12isCursorMoveEv");
/*TARGET 00295668*/
void func_00295668() asm("_Z13func_00295668v");
void func_00295668() {
    if (func_00289310() == 0) {
        return;
    }
    func_00295508();
    func_002955a8();
}
}  // namespace n00295668

// 002956a0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002956a0 {
u32 func_00276c50(u32, u32, u32, u32) asm("_Z13func_00276c50jjjj");
/*TARGET 002956a0*/
u32 func_002956a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002956a0jjjj");
u32 func_002956a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00276c50(0x000048cbu, 0x00000000u, a2, a3);
}
}  // namespace n002956a0

// 002956c0 (was src/anon/batch_w29.cpp)
namespace n002956c0 {
s32 SelCheck(s32 i) asm("_ZN2Tz10JmWorldSel8SelCheckEi");
u8* func_00294000(u32) asm("func_00294000");
s32 func_00295158(s32) asm("func_00295158");
u8 func_002941a8(u8*) asm("func_002941a8");
/*TARGET 002956c0*/
// 0x00258a30: definition moved into src/anon/unit_002588e8.cpp

// 0028d140: moved to src/anon/unit_0028c878.cpp

s32 SelCheck(s32 i) asm("_ZN2Tz10JmWorldSel8SelCheckEi");
// 0x00258a30: definition moved into src/anon/unit_002588e8.cpp

// 0028d140: moved to src/anon/unit_0028c878.cpp

s32 SelCheck(s32 i) {
    u8* b = func_00294000(0) + 16;
    return func_002941a8(b + func_00295158(i) * 16);
}
}  // namespace n002956c0

// 00295710 (was src/anon/batch_wcx.cpp)
namespace n00295710 {
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00276150(u32, s32*, s32*) asm("func_00276150");
s32 func_00276568(void) asm("func_00276568");
s32 func_002956c0(s32) asm("func_002956c0");
/*TARGET 00295710*/
s32 func_00295710(s32 a) asm("func_00295710");
s32 func_00295710(s32 a)
{
    s32 r = 0;
    u32 o = func_00287bc0();
    if ((u32)(a + 9) < 2) {
        s32 x, y;
        func_00276150(o, &x, &y);
        s32 v = a == -8 ? y : x;
        s32 c = *(s8*)func_00276568();
        if (v != 2) r = 1;
        else if ((u32)c < 15) r = 1;
    } else if (a >= 0) {
        r = func_002956c0(a);
    }
    return r;
}
}  // namespace n00295710

// 002957b8 (was src/anon/batch_w1589_g.cpp)
namespace n002957b8 {
s32 func_00103570(void) asm("func_00103570");
void* func_001063c0(s32, s32) asm("func_001063c0");
void func_0023f800(void*) asm("func_0023f800");
extern u8 D_0035f590 asm("D_0035f590");
extern u8 D_0035f591 asm("D_0035f591");
extern void* D_0035f58c asm("D_0035f58c");
/*TARGET 002957b8*/
void func_002957b8(void) asm("func_002957b8");
void func_002957b8(void)
{
    void* o;
    D_0035f590 = 0;
    D_0035f591 = 0;
    o = func_001063c0(28, func_00103570());
    func_0023f800(o);
    D_0035f58c = o;
}
}  // namespace n002957b8

// 00295810 (was src/anon/batch_w27.cpp)
namespace n00295810 {
// 002908f0: moved to src/anon/unit_0028f1e0.cpp

extern u8 D_0035f590 asm("D_0035f590");
extern u8 D_0035f591 asm("D_0035f591");
extern void** D_0035f58c asm("D_0035f58c");
/*TARGET 00295810*/
void func_00295810(void) asm("func_00295810");
void func_00295810(void) {
    D_0035f590 = 0;
    D_0035f591 = 0;
    if (D_0035f58c) {
        (*(void (**)(void*))(*(u8**)D_0035f58c + 4))(D_0035f58c);
        D_0035f58c = 0;
    }
}
}  // namespace n00295810

// 00295860 (was src/anon/misc_2.cpp)
namespace n00295860 {
/*TARGET 00295860*/
void func_00295860(void* self) asm("_Z13func_00295860Pv");
void func_00295860(void* self) {}
}  // namespace n00295860

// 00295868 (was src/anon/tiny_auto80_queue.cpp)
namespace n00295868 {
u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
u32 func_00287bc0(...) asm("func_00287bc0");
u32 func_00296ab0(...) asm("func_00296ab0");
/*TARGET 00295868*/
u32 func_00295868(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00295868jjjjjjjj");
u32 func_00295868(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00287bc0)();
    r2 = (u32)((s32)r2 + (-1));
    r2 = ((u32)r2 < 0x00000002u);
    if (r2 != 0u) {
        r2 = ((u32(*)())func_00296ab0)();
        r2 = ((u32(*)())func_00274ac8)();
        r15 = (u32)(0x0036u << 16);
        *(u8*)((u32)r15 + (s32)(-2671)) = (u8)0u;
    }
    return r2;
}
}  // namespace n00295868


// 002958b0 (was whole asm src/anon/batch_w3949.s)
namespace n002958b0 {
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
void jm_cover(s32) asm("_ZN2Tz6Jiminy8SetCoverEi");
void jm_mainframe(void) asm("_ZN2Tz6Jiminy14SetupMainFrameEv");
void func_00288e88(s32) asm("func_00288e88");
void func_002969e0(void) asm("func_002969e0");
void func_00276088(s32, s32*, s32*) asm("func_00276088");
void func_00275f68(s32, s32) asm("func_00275f68");
s32 func_00295430(s32, s32) asm("func_00295430");
void func_00275e68(s32) asm("func_00275e68");
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
s32 yi_cr(void*) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
s32 mb_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 jm_curpos(s32) asm("_ZN2Tz6Jiminy9GetCurPosEi");
void jm_savecur(s32, s32, s32) asm("_ZN2Tz6Jiminy10SaveCurPosEiii");
s8* jm_info(void) asm("_ZN2Tz6Jiminy11GetMenuInfoEv");
u32 sel_gen(s32) asm("_ZN2Tz6Select15GetEnableButtonEv");
void sel_sen(s32, u32) asm("_ZN2Tz6Select15SetEnableButtonEj");
void jr_draw(void) asm("_ZN2Tz8JmReport10DrawUpdateEPNS_6SelectEii");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f200 asm("D_0035f200");
struct Obj { u8 pad[408]; void* x198; u8 pad2[8]; s32 x1a4; u8 pad3[4]; s32 x1ac; s32 x1b0; u8 pad4[4]; };
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("func_00288d80");
Obj* sel_item(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void reset_alpha(void*) asm("_ZN2dk5Obj2D17resetSeqAlphaOnlyEv");
void set_off(Obj*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
void mc_create(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz10MenuCursor6CreateEz");
void func_002891f0(s32, s32, s32, s32, s32) asm("func_002891f0");
void func_00296b80(s32) asm("func_00296b80");
void func_002960d0(void) asm("func_002960d0");
void func_00295d28(void) asm("func_00295d28");
struct Cur { u8 pad[432]; s32 x1b0; };
/*TARGET 002958b0*/
void func_002958b0(void) asm("func_002958b0");
void func_002958b0(void) {
    s16 h[2][4];
    s32 a, b;
    s32 i = 0;
    s32 cr;
    u8* par = jm_parent();
    u8* seq = jm_seqtbl();
    u8* A;
    u8* B;
    jm_cover(1);
    func_00288e88(D_0035f200);
    func_002969e0();
    jm_mainframe();
    func_00276088(mb_mode(), &a, &b);
    func_00275f68(a, b);
    func_00275e68(func_00295430(*jm_info(), 0));
    for (i = 0; i < 2; i++)
        for (s32 j = 0; j < 4; j++) h[i][j] = 3;
    s32 n = D_0035f3d4 - 1;
    pz_cfo(seq, n, D_0035f14c, D_0035f148, D_0035f210, 159, -1, 0);
    i = 0;
    obj_xyoff(seq);
    mc_as(seq, par);
    A = seq + 816;
    pz_cfo(A, n, D_0035f14c, D_0035f148, D_0035f210, 169, -1, 0);
    obj_xyoff(A);
    mc_as(A, par);
    B = seq + 1632;
    mc_create(B, n, D_0035f14c, D_0035f148, D_0035f210, 167, -1, -1, 0);
    reset_alpha(B);
    mc_as(B, par);
    Cur* c1 = (Cur*)(seq + 2068);
    mc_create(c1, n, D_0035f14c, D_0035f148, D_0035f210, 3, -1, -1, 0);
    obj_xyoff(c1);
    mc_as(c1, B);
    c1->x1b0 = 2;
    u8* c2 = seq + 2504;
    mc_create(c2, n, D_0035f14c, D_0035f148, D_0035f210, 168, -1, -1, 0);
    reset_alpha(c2);
    mc_as(c2, par);
    Cur* c3 = (Cur*)(seq + 2940);
    mc_create(c3, n, D_0035f14c, D_0035f148, D_0035f210, 3, -1, -1, 0);
    obj_xyoff(c3);
    mc_as(c3, c2);
    c3->x1b0 = 2;
    cr = yi_cr(seq + 24);
    n = D_0035f3d4;
    for (i = 0; i < 9; i++) {
        func_00288d80(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, h[0], h[1]);
        Obj* it = sel_item(D_0035f200, i);
        obj_xyoff(it);
        mc_as(it, seq);
        set_off(it, 0, i * cr);
        u8* e = seq + 30360 + i * 408;
        pz_cfo(e, n + 1, D_0035f14c, D_0035f148, D_0035f210, 3, -1, 0);
        mc_as(e, it);
        e = seq + 0xa998 + i * 408;
        pz_cfo(e, n + 2, D_0035f14c, D_0035f148, D_0035f210, 3, -1, 0);
        mc_as(e, it);
    }
    func_00296b80(0);
    func_002891f0(D_0035f200, jm_curpos(mb_mode()), 0, -1, -1);
    jm_savecur(mb_mode(), 0, 0);
    func_002960d0();
    func_00295d28();
    sel_sen(D_0035f200, sel_gen(D_0035f200) | 0x3000);
    jr_draw();
    sel_set(0);
}
}  // namespace n002958b0
