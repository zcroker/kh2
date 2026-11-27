// Linked unit 0x001e8ac8-0x001ec098 (pppPart.c: particle programs; one namespace per old matched source, gap
// functions written for the unit). Built as C++ with -G0 -g -fno-strict-aliasing.
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>

// 001e8ac8 (was src/anon/batch_w76.cpp)
namespace n001e8ac8 {
// 0x001af0c0: definition moved into src/anon/unit_001ada38.cpp
extern char D_0036ef58[] asm("D_0036ef58");
extern char D_0036efb8[] asm("D_0036efb8");
extern char D_0036ef98[] asm("D_0036ef98");
extern char D_0036ef88[] asm("D_0036ef88");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
// device_vprintf_va
u8* func_001e7a98(u8*, u8*) asm("func_001e7a98");
static inline void AssertFail(const char* expr, const char* file, u32 line)
{
    func_002fdfc8(D_0036ef58, expr);  // device_vprintf_va
    func_002fdfc8(D_0036ef98, file, line);  // device_vprintf_va
    asm volatile("break");
}
/*TARGET 001e8ac8*/
void func_001e8ac8(u8* o) asm("func_001e8ac8");
void func_001e8ac8(u8* o)
{
    for (s32 i = 0; i < *(s32*)(o + 104); i++) {
        u8* e = *(u8**)(o + 128) + i * 16;
        if (!e) AssertFail(D_0036efb8, D_0036ef88, 964);
        if (*(s32*)(o + 88) < *(s32*)(e + 8)) continue;
        *(s32*)(e + 8) = 0x7fffffff;
        u8* r = func_001e7a98(o, e);
        *(u8**)(e + 4) = r;
        *(r + 156) = 0;
    }
}
}  // namespace n001e8ac8

// 001e8bb8 (was src/anon/batch_w49.cpp)
namespace n001e8bb8 {
// 00199468: moved to src/anon/unit_001991a8.cpp

struct NoTail { ~NoTail() {} };
// 0x001e7810: definition moved into src/anon/unit_001e0cb8.cpp

void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*AMBIG-MULTI*/ // device_vprintf_va
extern "C" char D_0036ef58[], D_0036efc8[], D_0036ef88[], D_0036ef98[];
void func_001e7878(u8*) asm("func_001e7878");
void func_001e8ac8(u8*) asm("func_001e8ac8");
void func_001e8330(u8*) asm("func_001e8330");
static inline void assert1e8bb8(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036ef58, e);  // device_vprintf_va
    func_002fdfc8(D_0036ef98, f, l);  // device_vprintf_va
    asm volatile("break");
}
/*TARGET 001e8bb8*/
void func_001e8bb8(u8* p) asm("func_001e8bb8");
void func_001e8bb8(u8* p) {
    NoTail g;
    if (!p) assert1e8bb8(D_0036efc8, D_0036ef88, 982);
    func_001e7878(p);
    func_001e8ac8(p);
    func_001e8330(p);
}
}  // namespace n001e8bb8

// 001e8c28 (was src/anon/batch_w326.c)
namespace n001e8c28 {
// 0x001e41e0: definition moved into src/anon/unit_001e0cb8.cpp

void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*AMBIG-MULTI*/ // device_vprintf_va
extern "C" char D_0036ef58[], D_0036efc8[], D_0036ef88[], D_0036ef98[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036ef58, e);  // device_vprintf_va
    func_002fdfc8(D_0036ef98, f, l);  // device_vprintf_va
    asm volatile("break");
}
void func_001e8558(void*, s32) asm("func_001e8558");
void func_001e78e0(void*) asm("func_001e78e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
/*TARGET 001e8c28*/
s32 func_001e8c28(u8* p, void* b) asm("func_001e8c28");
s32 func_001e8c28(u8* p, void* b) {
    s32 v, nv;
    if (!p) ryjAssert(D_0036efc8, D_0036ef88, 1000);
    func_001e8558(p, (s32)b);
    func_001e78e0(p);
    if (D_01d9ea9c != 0 || (*(u64*)(D_01d9e6e0 + 0xa8) & 0xff0000ff00ULL)) return 0;
    v = *(s32*)(p + 0x58);
    nv = v + 0x1000;
    *(s32*)(p + 0x5c) = v;
    *(s32*)(p + 0x58) = nv;
    if (p[0x84]) {
        if (p[0x85]) return *(s32*)(p + 0x74) == 0;
        if (nv > 0x6fffffff) {
            *(s32*)(p + 0x58) = 0x70000000;
            *(s32*)(p + 0x5c) = 0x6ffff000;
        }
        return 0;
    }
    return !(nv < *(s32*)(p + 0x54));
}
}  // namespace n001e8c28

// 001e8d38 (gap, written for the unit)
namespace n001e8d38 {
extern "C" void func_002fdfc8(const char*, ...);
extern "C" char D_0036ef58[], D_0036efc8[], D_0036ef88[], D_0036ef98[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036ef58, e);
    func_002fdfc8(D_0036ef98, f, l);
    asm volatile("break");
}
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
s32 func_001e8d38(u8* p) asm("func_001e8d38");
s32 func_001e8d38(u8* p) {
    s32 v, nv;
    if (!p) ryjAssert(D_0036efc8, D_0036ef88, 1030);
    if (D_01d9ea9c != 0 || (*(u64*)(D_01d9e6e0 + 0xa8) & 0xff0000ff00ULL)) return 0;
    v = *(s32*)(p + 0x58);
    nv = v + 0x1000;
    *(s32*)(p + 0x5c) = v;
    *(s32*)(p + 0x58) = nv;
    if (p[0x84]) {
        if (p[0x85]) return *(s32*)(p + 0x74) == 0;
        if (nv > 0x6fffffff) {
            *(s32*)(p + 0x58) = 0x70000000;
            *(s32*)(p + 0x5c) = 0x6ffff000;
        }
        return 0;
    }
    return !(nv < *(s32*)(p + 0x54));
}
}  // namespace n001e8d38

// 001e8e28 (was src/anon/batch_w1893_nsa.cpp)
namespace n001e8e28 {
struct O1893;
struct E1893;
typedef void (*Fn1893)(O1893*, u8*, E1893*);
struct H1893 { u32 x0; Fn1893 fn; };
struct E1893 { H1893* h; u16 off; u16 pad; u32 x8, xc; };
struct Hd1893 { u8 pad[0x20]; s32 x20; u16 x24; s16 n; E1893 e[1]; };
struct O1893 { u32 x0, x4; Hd1893** x8; s32 xc; };
struct G1893 { u8 pad[0xa8]; u64 xa8; };
extern Fn1893 D_00354bb0[] asm("D_00354bb0");
extern O1893* D_01d9e6e8 asm("D_01d9e6e8");
extern G1893* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
static inline s32 inL_w1893(Fn1893 f) {
    Fn1893* p = D_00354bb0;
    s32 r = 0;
    for (; *p != 0; p++) {
        if (f == *p) { r = 1; break; }
    }
    return r;
}
/*TARGET 001e8e28*/
void func_001e8e28(void* a, O1893* o) asm("func_001e8e28");
void func_001e8e28(void* a, O1893* o) {
    Hd1893* hd = *o->x8;
    u8** s = (u8**)((u8*)o + hd->x20);
    D_01d9e6e8 = o;
    for (s32 i = 0; i < hd->n; i++) {
        E1893* e = &hd->e[i];
        H1893* h = e->h;
        if (h != 0) {
            u8* p = *s;
            if (*(s32*)(p + e->off) == o->xc) { p += e->off; *s = p; }
            s++;
            Fn1893 f = h->fn;
            if (f != 0 && !inL_w1893(f)) f(o, p, e);
        }
    }
    if (D_01d9ea9c == 0 && (D_01d9e6e0->xa8 & 0xff0000ff00ULL) == 0) {
        o->xc += 0x1000;
        if (o->xc > 0x6fffffff) o->xc = 0x6ffff000;
    }
}
}  // namespace n001e8e28

// 001e8f98 (gap, written for the unit)
namespace n001e8f98 {
void func_001e8f98(void) asm("func_001e8f98");
void func_001e8f98(void) {}
}  // namespace n001e8f98

// 001e8fa0 (gap, written for the unit)
namespace n001e8fa0 {
void func_001e8fa0(void) asm("func_001e8fa0");
void func_001e8fa0(void) {}
}  // namespace n001e8fa0

// 001e8fa8 (gap, written for the unit)
namespace n001e8fa8 {
void func_001e8fa8(void) asm("func_001e8fa8");
void func_001e8fa8(void) {}
}  // namespace n001e8fa8

// 001e8fb0 (gap, written for the unit)
namespace n001e8fb0 {
void func_001e8fb0(void) asm("func_001e8fb0");
void func_001e8fb0(void) {}
}  // namespace n001e8fb0

// 001e8fb8 (gap, written for the unit)
namespace n001e8fb8 {
void func_001e8fb8(void) asm("func_001e8fb8");
void func_001e8fb8(void) {}
}  // namespace n001e8fb8

// 001e8fc0 (gap, written for the unit)
namespace n001e8fc0 {
void func_001e8fc0(void) asm("func_001e8fc0");
void func_001e8fc0(void) {}
}  // namespace n001e8fc0

// 001e8fc8 (gap, written for the unit)
namespace n001e8fc8 {
void func_001e8fc8(void) asm("func_001e8fc8");
void func_001e8fc8(void) {}
}  // namespace n001e8fc8

// 001e8fd0 (gap, written for the unit)
namespace n001e8fd0 {
void func_001e8fd0(void) asm("func_001e8fd0");
void func_001e8fd0(void) {}
}  // namespace n001e8fd0

// 001e8fd8 (gap, written for the unit)
namespace n001e8fd8 {
void func_001e8fd8(void) asm("func_001e8fd8");
void func_001e8fd8(void) {}
}  // namespace n001e8fd8

// 001e8fe0 (was src/anon/auto80_199_queue.cpp)
namespace n001e8fe0 {
/*TARGET 001e8fe0*/
// 0x001e74d8: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e8fe0(u32 a0, u32 a1) asm("_Z13func_001e8fe0jj");
// 0x001e74d8: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e8fe0(u32 a0, u32 a1) {
    u32 s0 = a1;
    B64_001e8fe0 b0;
    B64_001e8fe0 b1;
    B64_001e8fe0 b2;
    B64_001e8fe0 b3;

    func_0021ead0(&b0, *(u32*)(s0 + 8));  // table_float_pair_lookup
    func_0021ea50(&b1, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021e9d0(&b3, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    sceVu0MulMatrix(a0, (u32)&b2, (u32)&b3);
}
}  // namespace n001e8fe0

// 001e9078 (was src/anon/batch_w55.cpp)
namespace n001e9078 {
typedef void (*CbW55)(u8*, u32);
extern u32 D_01d9eaa0 asm("D_01d9eaa0");
/*TARGET 001e9078*/
// 0x001d2690: definition moved into src/anon/unit_001d14e0.cpp

// 001d34d0: moved to src/anon/unit_001d30b0.cpp

void func_001e9078(u8* a, u8* b, u8* c) asm("func_001e9078");
// 0x001d2690: definition moved into src/anon/unit_001d14e0.cpp

// 001d34d0: moved to src/anon/unit_001d30b0.cpp

void func_001e9078(u8* a, u8* b, u8* c) {
    *(u32*)(a + **(s32**)(c + 12) + 160) = *(u32*)(b + 4);
    CbW55* t = (CbW55*)D_01d9eaa0;
    if (!t) return;
    CbW55 f = t[(*(u8**)(a + 8))[14]];
    if (f) f(a, *(u32*)(b + 4));
}
}  // namespace n001e9078

// 001e90d8 (gap, written for the unit)
namespace n001e90d8 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e90d8(PObj* o, M* m, PDesc* d) asm("func_001e90d8");
void func_001e90d8(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) {
            V* v = &((PP*)((u8*)o + d->off[0]))->v;
            v->x += m->d.x; v->y += m->d.y; v->z += m->d.z;
        }
    }
}
}  // namespace n001e90d8

// 001e9160 (gap, written for the unit)
namespace n001e9160 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
void func_001e9160(u8* o, PDesc* d) asm("func_001e9160");
void func_001e9160(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = v->y = v->z = 0.0f; }
}  // namespace n001e9160

// 001e9188 (gap, written for the unit)
namespace n001e9188 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e9188(PObj* o, M* m, PDesc* d) asm("func_001e9188");
void func_001e9188(PObj* o, M* m, PDesc* d)
{
    V* p = &((PP*)((u8*)o + d->off[0]))->v;
    V* v = &((PP*)((u8*)o + d->off[1]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) { v->x += m->d.x; v->y += m->d.y; v->z += m->d.z; }
        p->x += v->x; p->y += v->y; p->z += v->z;
    }
}
}  // namespace n001e9188

// 001e9250 (gap, written for the unit)
namespace n001e9250 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
void func_001e9250(u8* o, PDesc* d) asm("func_001e9250");
void func_001e9250(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->x = v->y = v->z = 0.0f; }
}  // namespace n001e9250

// 001e9278 (gap, written for the unit)
namespace n001e9278 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e9278(PObj* o, M* m, PDesc* d) asm("func_001e9278");
void func_001e9278(PObj* o, M* m, PDesc* d)
{
    V* p = &((PP*)((u8*)o + d->off[0]))->v;
    V* v = &((PP*)((u8*)o + d->off[1]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) { v->x += m->d.x; v->y += m->d.y; v->z += m->d.z; }
        p->x += v->x; p->y += v->y; p->z += v->z;
    }
}
}  // namespace n001e9278

// 001e9340 (gap, written for the unit)
namespace n001e9340 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
void func_001e9340(u8* o, PDesc* d) asm("func_001e9340");
void func_001e9340(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->x = v->y = v->z = 0.0f; }
}  // namespace n001e9340

// 001e9368 (gap, written for the unit)
namespace n001e9368 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { s32 x; s32 y; s32 z; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e9368(PObj* o, M* m, PDesc* d) asm("func_001e9368");
void func_001e9368(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) {
            V* v = &((PP*)((u8*)o + d->off[0]))->v;
            v->x += m->d.x; v->y += m->d.y; v->z += m->d.z;
        }
    }
}
}  // namespace n001e9368

// 001e93f0 (gap, written for the unit)
namespace n001e93f0 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { s32 x; s32 y; s32 z; };
struct PP { u8 pad[160]; V v; };
void func_001e93f0(u8* o, PDesc* d) asm("func_001e93f0");
void func_001e93f0(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = v->y = v->z = 0; }
}  // namespace n001e93f0

// 001e9410 (gap, written for the unit)
namespace n001e9410 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { s32 x; s32 y; s32 z; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e9410(PObj* o, M* m, PDesc* d) asm("func_001e9410");
void func_001e9410(PObj* o, M* m, PDesc* d)
{
    V* p = &((PP*)((u8*)o + d->off[0]))->v;
    V* v = &((PP*)((u8*)o + d->off[1]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) { v->x += m->d.x; v->y += m->d.y; v->z += m->d.z; }
        p->x += v->x; p->y += v->y; p->z += v->z;
    }
}
}  // namespace n001e9410

// 001e94d8 (gap, written for the unit)
namespace n001e94d8 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { s32 x; s32 y; s32 z; };
struct PP { u8 pad[160]; V v; };
void func_001e94d8(u8* o, PDesc* d) asm("func_001e94d8");
void func_001e94d8(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->x = v->y = v->z = 0; }
}  // namespace n001e94d8

// 001e94f8 (gap, written for the unit)
namespace n001e94f8 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { s32 x; s32 y; s32 z; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e94f8(PObj* o, M* m, PDesc* d) asm("func_001e94f8");
void func_001e94f8(PObj* o, M* m, PDesc* d)
{
    V* p = &((PP*)((u8*)o + d->off[0]))->v;
    V* v = &((PP*)((u8*)o + d->off[1]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) { v->x += m->d.x; v->y += m->d.y; v->z += m->d.z; }
        p->x += v->x; p->y += v->y; p->z += v->z;
    }
}
}  // namespace n001e94f8

// 001e95c0 (gap, written for the unit)
namespace n001e95c0 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { s32 x; s32 y; s32 z; };
struct PP { u8 pad[160]; V v; };
void func_001e95c0(u8* o, PDesc* d) asm("func_001e95c0");
void func_001e95c0(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->x = v->y = v->z = 0; }
}  // namespace n001e95c0

// 001e95e0 (gap, written for the unit)
namespace n001e95e0 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e95e0(PObj* o, M* m, PDesc* d) asm("func_001e95e0");
void func_001e95e0(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) {
            V* v = &((PP*)((u8*)o + d->off[0]))->v;
            v->x += m->d.x; v->y += m->d.y; v->z += m->d.z;
        }
    }
}
}  // namespace n001e95e0

// 001e9668 (gap, written for the unit)
namespace n001e9668 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
void func_001e9668(u8* o, PDesc* d) asm("func_001e9668");
void func_001e9668(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = v->y = v->z = 0.0f; }
}  // namespace n001e9668

// 001e9690 (gap, written for the unit)
namespace n001e9690 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e9690(PObj* o, M* m, PDesc* d) asm("func_001e9690");
void func_001e9690(PObj* o, M* m, PDesc* d)
{
    V* p = &((PP*)((u8*)o + d->off[0]))->v;
    V* v = &((PP*)((u8*)o + d->off[1]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) { v->x += m->d.x; v->y += m->d.y; v->z += m->d.z; }
        p->x += v->x; p->y += v->y; p->z += v->z;
    }
}
}  // namespace n001e9690

// 001e9758 (gap, written for the unit)
namespace n001e9758 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
void func_001e9758(u8* o, PDesc* d) asm("func_001e9758");
void func_001e9758(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->x = v->y = v->z = 0.0f; }
}  // namespace n001e9758

// 001e9780 (gap, written for the unit)
namespace n001e9780 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e9780(PObj* o, M* m, PDesc* d) asm("func_001e9780");
void func_001e9780(PObj* o, M* m, PDesc* d)
{
    V* p = &((PP*)((u8*)o + d->off[0]))->v;
    V* v = &((PP*)((u8*)o + d->off[1]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) { v->x += m->d.x; v->y += m->d.y; v->z += m->d.z; }
        p->x += v->x; p->y += v->y; p->z += v->z;
    }
}
}  // namespace n001e9780

// 001e9848 (gap, written for the unit)
namespace n001e9848 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
void func_001e9848(u8* o, PDesc* d) asm("func_001e9848");
void func_001e9848(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->x = v->y = v->z = 0.0f; }
}  // namespace n001e9848

// 001e9870 (gap, written for the unit)
namespace n001e9870 {
struct PMng { u8 pad[48]; u8 col[16]; u8 pad2[0xa8 - 64]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" s32 D_00352c38;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct C4 { u16 x, y, z, w; };
struct V { C4 c; u8 r, g, b, a; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; C4 d; };
void func_001e9870(PObj* o, M* m, PDesc* d) asm("func_001e9870");
void func_001e9870(PObj* o, M* m, PDesc* d)
{
    V* v = &((PP*)((u8*)o + d->off[0]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) { v->c.x += m->d.x; v->c.y += m->d.y; v->c.z += m->d.z; v->c.w += m->d.w; }
    }
    f32 lim = 32767.0f;
    // u16 colour * manager colour scale, clamped to I, >> 7, packed to bytes (VU0 macro code)
    asm volatile(
        "lw $2, 4(%0)\n\tpextlw $2, $2, $0\n\tlw $3, 0(%0)\n\tor $2, $2, $3\n\tpextlh $2, $0, $2\n\tqmtc2 $2, $vf1\n"
        "\tlw $2, %2\n\tvitof0.xyzw $vf1, $vf1\n\tlqc2 $vf2, 0(%1)\n\tvmul.xyzw $vf1, $vf1, $vf2\n\tctc2 $2, $vi21\n"
        "\tvminii.xyzw $vf1, $vf1, I\n\tvftoi0.xyzw $vf1, $vf1\n\tqmfc2 $2, $vf1\n\tpsrlw $2, $2, 7\n\tppach $2, $0, $2\n"
        "\tppacb $2, $0, $2\n\tsw $2, 8(%0)"
        : : "r"(v), "r"(D_01d9e6e0->col), "m"(lim) : "$2", "$3", "memory");
    if (D_00352c38) {
        s32 g = (s32)(v->r * 0.3f + v->g * 0.59f + v->b * 0.11f);
        v->r = v->g = v->b = g;
    }
}
}  // namespace n001e9870

// 001e99f0 (gap, written for the unit)
namespace n001e99f0 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x; u16 y; u16 z; u16 w; };
struct PP { u8 pad[160]; V v; };
void func_001e99f0(u8* o, PDesc* d) asm("func_001e99f0");
void func_001e99f0(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = v->y = v->z = v->w = 0; }
}  // namespace n001e99f0

// 001e9a18 (gap, written for the unit)
namespace n001e9a18 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x; u16 y; u16 z; u16 w; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e9a18(PObj* o, M* m, PDesc* d) asm("func_001e9a18");
void func_001e9a18(PObj* o, M* m, PDesc* d)
{
    V* p = &((PP*)((u8*)o + d->off[0]))->v;
    V* v = &((PP*)((u8*)o + d->off[1]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) { v->x += m->d.x; v->y += m->d.y; v->z += m->d.z; v->w += m->d.w; }
        p->x += v->x; p->y += v->y; p->z += v->z; p->w += v->w;
    }
}
}  // namespace n001e9a18

// 001e9af8 (gap, written for the unit)
namespace n001e9af8 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x; u16 y; u16 z; u16 w; };
struct PP { u8 pad[160]; V v; };
void func_001e9af8(u8* o, PDesc* d) asm("func_001e9af8");
void func_001e9af8(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->x = v->y = v->z = v->w = 0; }
}  // namespace n001e9af8

// 001e9b20 (gap, written for the unit)
namespace n001e9b20 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x; u16 y; u16 z; u16 w; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; V d; };
void func_001e9b20(PObj* o, M* m, PDesc* d) asm("func_001e9b20");
void func_001e9b20(PObj* o, M* m, PDesc* d)
{
    V* p = &((PP*)((u8*)o + d->off[0]))->v;
    V* v = &((PP*)((u8*)o + d->off[1]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        if (m->id == o->id) { v->x += m->d.x; v->y += m->d.y; v->z += m->d.z; v->w += m->d.w; }
        p->x += v->x; p->y += v->y; p->z += v->z; p->w += v->w;
    }
}
}  // namespace n001e9b20

// 001e9c00 (gap, written for the unit)
namespace n001e9c00 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x; u16 y; u16 z; u16 w; };
struct PP { u8 pad[160]; V v; };
void func_001e9c00(u8* o, PDesc* d) asm("func_001e9c00");
void func_001e9c00(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->x = v->y = v->z = v->w = 0; }
}  // namespace n001e9c00

// 001e9c28 (was src/anon/batch_w79.cpp)
namespace n001e9c28 {
struct K36 { s16 h0; u8 pad[18]; s16* f20; u8 pad24[12]; };
struct KE { s16 h0; s16 h2; u16* f4; };
struct KG { u8 pad[16]; struct K36* f16; u8 pad20[4]; struct KE* f24; };
extern struct KG* D_01d9e6e4 asm("D_01d9e6e4");
union FH { f32 f; s16 h; };
void sceVu0ApplyMatrix(union FH*, void*, union FH*) asm("sceVu0ApplyMatrix");
/*TARGET 001e9c28*/
// 001b0798: moved to src/yasui/libys/lookat.cpp

void func_001e9c28(u8* base, u8* a1, u8* a2) asm("func_001e9c28");
// 001b0798: moved to src/yasui/libys/lookat.cpp

void func_001e9c28(u8* base, u8* a1, u8* a2) {
    union FH v[4];
    s32 k = *(s16*)(a1 + 12);
    if (k >= 0) {
        s32* offs = *(s32**)(a2 + 12);
        u8* src = base + offs[0];
        u8* dst = base + offs[1];
        struct KE* e = &D_01d9e6e4->f24[k];
        s16* p = D_01d9e6e4->f16[e->h0].f20 + e->f4[*(u16*)(src + 160)] * 3;
        volatile f32* d = (f32*)(dst + 160);
        v[0].f = p[0];
        v[1].f = p[1];
        v[2].f = p[2];
        v[3].f = 1.0f;
        sceVu0ApplyMatrix(v, *(u8**)(base + 4) + 16, v);
        d[0] = *(f32*)&v[0].f;
        {
            f32 z = *(volatile f32*)&v[2].f;
            f32 y = *(volatile f32*)&v[1].f;
            d[2] = z;
            d[1] = y;
        }
    }
}
}  // namespace n001e9c28

// 001e9d30 (gap, written for the unit)
namespace n001e9d30 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x, y; };
struct PP { u8 pad[160]; V v; };
void func_001e9d30(u8* o, PDesc* d) asm("func_001e9d30");
void func_001e9d30(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = 0; v->y = 0; }
}  // namespace n001e9d30

// 001e9d48 (was src/anon/batch_w1815_nsa.cpp)
namespace n001e9d48 {
// 001788b8: moved to src/yasui/libys/player.cpp

struct V4e9 { f32 x, y, z, w; };
struct V3e9 { f32 x, y, z; };
struct Oe9 { u8 p0[0x80]; u8* f80; };
struct Re9 { u32 a; s32 f4; };
struct Ae9 { u8 p0[0xc]; s32 idx; s32 f10; };
extern Oe9* D_01d9e6e0 asm("D_01d9e6e0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
Re9* func_001e7a98(Oe9*, void*) asm("func_001e7a98");
void sceVu0ApplyMatrix(V4e9*, void*, V4e9*) asm("sceVu0ApplyMatrix");
/*TARGET 001e9d48*/
void apea(s32 a0, Ae9* a1, s16* a2) asm("apea");
void apea(s32 a0, Ae9* a1, s16* a2) {
    if (a1->idx != -1) {
        Re9* r = 0;
        Oe9* o = D_01d9e6e0;
        void* p = o->f80 + a1->idx * 16;
        if (p) {
            r = func_001e7a98(o, p);
            r->f4 = a0;
        }
        V4e9 v;
        v.x = a2[0]; v.y = a2[1]; v.z = a2[2]; v.w = 1.0f;
        sceVu0ApplyMatrix(&v, D_01d9e6e8 + 16, &v);
        V3e9* d = (V3e9*)((u8*)r + a1->f10 + 0xa0);
        d->x = v.x; d->y = v.y; d->z = v.z;
    }
}
}  // namespace n001e9d48

// 001e9e48 (was src/anon/batch_w2505_nsa.c)
namespace n001e9e48 {
typedef struct { s16 a, b, c; } EmitPt1e9e48;
typedef struct { s16 set; s16 count; u16* idx; } EmitTbl1e9e48;
typedef struct { u8 pad0[16]; u8* sets; u8 pad1[4]; EmitTbl1e9e48* tbls; } EmitRes1e9e48;
typedef struct { u8 pad0[144]; EmitPt1e9e48* pts; } EmitOvr1e9e48;
typedef struct { u8 pad0[4]; s16 tbl; u8 num; u8 wait; u8 mode; } Emit1e9e48;
typedef struct { u16 cur; u16 wait; } EmitSt1e9e48;
typedef struct { u8 pad0[12]; s32* off; } EmitCtx1e9e48;
typedef struct { u8 pad0[168]; u64 b168 : 8, stopA : 8, b170 : 8, dead : 8, stopB : 8, b173 : 24; } Part1e9e48;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Part1e9e48* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9eab4 asm("D_01d9eab4");
extern EmitRes1e9e48* D_01d9e6e4 asm("D_01d9e6e4");
extern EmitOvr1e9e48* D_01d9e6e8 asm("D_01d9e6e8");
void apea(u8*, Emit1e9e48*, EmitPt1e9e48*) asm("apea");
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rand1e9e48(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
/*TARGET 001e9e48*/
/* partMng particle emitter: spawn e->num points per tick (sequential or VU0-random pick) */
void pppVertexAp(u8* base, Emit1e9e48* e, EmitCtx1e9e48* c) asm("pppVertexAp");
/* partMng particle emitter: spawn e->num points per tick (sequential or VU0-random pick) */
void pppVertexAp(u8* base, Emit1e9e48* e, EmitCtx1e9e48* c)
{
    EmitSt1e9e48* st = (EmitSt1e9e48*)(base + *c->off + 160);
    EmitTbl1e9e48* t;
    EmitPt1e9e48* src;
    EmitPt1e9e48 pt;
    s32 n;
    if (D_01d9ea9c) return;
    if (D_01d9e6e0->stopA || D_01d9e6e0->stopB) return;
    if (D_01d9eab4) return;
    if (e->tbl < 0) return;
    if (st->wait == 0) {
        t = &D_01d9e6e4->tbls[e->tbl];
        src = D_01d9e6e8->pts;
        if (!src) src = *(EmitPt1e9e48**)(D_01d9e6e4->sets + t->set * 36 + 20);
        n = e->num;
        switch (e->mode) {
        case 0:
            while (n--) {
                if (st->cur >= t->count) st->cur = 0;
                s32 k = t->idx[st->cur++]; pt = src[k];
                apea(base, e, &pt);
            }
            break;
        case 1:
            while (n--) {
                f32 r = rand1e9e48();
                pt = src[t->idx[(s32)(r * (f32)t->count)]];
                apea(base, e, &pt);
            }
            break;
        }
        st->wait = e->wait;
    }
    st->wait--;
}
}  // namespace n001e9e48

// 001ea0d8 (gap, written for the unit)
namespace n001ea0d8 {
void func_001ea0d8(void) asm("func_001ea0d8");
void func_001ea0d8(void) {}
}  // namespace n001ea0d8

// 001ea0e0 (gap, written for the unit)
namespace n001ea0e0 {
void func_001ea0e0(void) asm("func_001ea0e0");
void func_001ea0e0(void) {}
}  // namespace n001ea0e0

// 001ea0e8 (gap, written for the unit)
namespace n001ea0e8 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x, y; };
struct PP { u8 pad[160]; V v; };
void func_001ea0e8(u8* o, PDesc* d) asm("func_001ea0e8");
void func_001ea0e8(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = 0; v->y = 0; }
}  // namespace n001ea0e8

// 001ea100 (was src/anon/batch_wcx.cpp)
namespace n001ea100 {
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
u8* func_001e7a98(u8*, u8*) asm("func_001e7a98");
union HF { s16 h; f32 f; };
/*TARGET 001ea100*/
void pppVertexApLc(u32 x, u8* d, HF* v) asm("pppVertexApLc");
void pppVertexApLc(u32 x, u8* d, HF* v)
{
    s32 k = *(s32*)(d + 12);
    if (k == -1) return;
    u8* r = 0;
    u8* base = D_01d9e6e0;
    u8* a = *(u8**)(base + 128) + k * 16;
    if (a) { r = func_001e7a98(base, a); *(u32*)(r + 4) = x; }
    f32* q = (f32*)(r + *(s32*)(d + 16) + 160);
    q[0] = ((HF*)((s16*)v + 0))->h;
    q[1] = ((HF*)((s16*)v + 1))->h;
    q[2] = ((HF*)((s16*)v + 2))->h;
}
}  // namespace n001ea100

// 001ea1b0 (was src/anon/batch_w2505_nsa.c)
namespace n001ea1b0 {
typedef struct { s16 a, b, c; } EmitPt1e9e48;
typedef struct { s16 set; s16 count; u16* idx; } EmitTbl1e9e48;
typedef struct { u8 pad0[16]; u8* sets; u8 pad1[4]; EmitTbl1e9e48* tbls; } EmitRes1e9e48;
typedef struct { u8 pad0[144]; EmitPt1e9e48* pts; } EmitOvr1e9e48;
typedef struct { u8 pad0[4]; s16 tbl; u8 num; u8 wait; u8 mode; } Emit1e9e48;
typedef struct { u16 cur; u16 wait; } EmitSt1e9e48;
typedef struct { u8 pad0[12]; s32* off; } EmitCtx1e9e48;
typedef struct { u8 pad0[168]; u64 b168 : 8, stopA : 8, b170 : 8, dead : 8, stopB : 8, b173 : 24; } Part1e9e48;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Part1e9e48* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9eab4 asm("D_01d9eab4");
extern EmitRes1e9e48* D_01d9e6e4 asm("D_01d9e6e4");
extern EmitOvr1e9e48* D_01d9e6e8 asm("D_01d9e6e8");
void pppVertexApLc(u8*, Emit1e9e48*, EmitPt1e9e48*) asm("pppVertexApLc");
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rand1e9e48(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
/*TARGET 001ea1b0*/
/* twin of pppVertexAp with a different spawn callee */
void func_001ea1b0(u8* base, Emit1e9e48* e, EmitCtx1e9e48* c) asm("func_001ea1b0");
/* twin of pppVertexAp with a different spawn callee */
void func_001ea1b0(u8* base, Emit1e9e48* e, EmitCtx1e9e48* c)
{
    EmitSt1e9e48* st = (EmitSt1e9e48*)(base + *c->off + 160);
    EmitTbl1e9e48* t;
    EmitPt1e9e48* src;
    EmitPt1e9e48 pt;
    s32 n;
    if (D_01d9ea9c) return;
    if (D_01d9e6e0->stopA || D_01d9e6e0->stopB) return;
    if (D_01d9eab4) return;
    if (e->tbl < 0) return;
    if (st->wait == 0) {
        t = &D_01d9e6e4->tbls[e->tbl];
        src = D_01d9e6e8->pts;
        if (!src) src = *(EmitPt1e9e48**)(D_01d9e6e4->sets + t->set * 36 + 20);
        n = e->num;
        switch (e->mode) {
        case 0:
            while (n--) {
                if (st->cur >= t->count) st->cur = 0;
                s32 k = t->idx[st->cur++]; pt = src[k];
                pppVertexApLc(base, e, &pt);
            }
            break;
        case 1:
            while (n--) {
                f32 r = rand1e9e48();
                pt = src[t->idx[(s32)(r * (f32)t->count)]];
                pppVertexApLc(base, e, &pt);
            }
            break;
        }
        st->wait = e->wait;
    }
    st->wait--;
}
}  // namespace n001ea1b0

// 001ea440 (gap, written for the unit)
namespace n001ea440 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x, y; };
struct PP { u8 pad[160]; V v; };
void func_001ea440(u8* o, PDesc* d) asm("func_001ea440");
void func_001ea440(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = 0; v->y = 0; }
}  // namespace n001ea440

// 001ea458 (was src/anon/batch_w59.cpp)
namespace n001ea458 {
// 0x001e0de8: definition moved into src/anon/unit_001e0cb8.cpp

// --- 001ea458
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
u8* func_001e7a98(u8*, u8*) asm("func_001e7a98");
/*TARGET 001ea458*/
void func_001ea458(u32 a, u8* b, u16 c) asm("func_001ea458");
void func_001ea458(u32 a, u8* b, u16 c) {
    if (*(s32*)(b + 12) == -1) return;
    u8* m = D_01d9e6e0;
    u8* r = 0;
    u8* e = *(u8**)(m + 128) + *(s32*)(b + 12) * 16;
    if (e) {
        r = func_001e7a98(m, e);
        *(u32*)(r + 4) = a;
    }
    *(u16*)(r + *(u32*)(b + 16) + 160) = c;
}
}  // namespace n001ea458

// 001ea4d8 (was src/anon/batch_w2396.c)
namespace n001ea4d8 {
typedef struct { u8 pad0[0xa8]; u64 flags; } St4d8;
typedef struct { s16 x0; s16 x2; s32 x4; } Ent4d8;
typedef struct { u8 pad0[0x18]; Ent4d8* tbl; } Bank4d8;
typedef struct { u8 pad0[4]; s16 idx; u8 n; u8 reset; u8 mode; } Obj4d8;
typedef struct { u8 pad0[0xc]; s32* ofs; } Arg4d8;
typedef struct { u16 cur; u16 wait; } Cnt4d8;
extern St4d8* D_01d9e6e0 asm("D_01d9e6e0");
extern Bank4d8* D_01d9e6e4 asm("D_01d9e6e4");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern s32 D_01d9eab4 asm("D_01d9eab4");
void func_001ea458(s32 a, Obj4d8* o, u16 v) asm("func_001ea458");
static __inline__ f32 VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
/*TARGET 001ea4d8*/
void func_001ea4d8(s32 base, Obj4d8* o, Arg4d8* arg) asm("func_001ea4d8");
void func_001ea4d8(s32 base, Obj4d8* o, Arg4d8* arg)
{
    Cnt4d8* c = (Cnt4d8*)(base + *arg->ofs + 0xa0);
    s16 idx;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (D_01d9eab4 != 0) return;
    idx = o->idx;
    if (idx < 0) return;
    if (c->wait == 0) {
        s32 n = o->n;
        Ent4d8* e = &D_01d9e6e4->tbl[idx];
        switch (o->mode) {
        case 0:
            while (--n != -1) {
                if (c->cur >= e->x2) c->cur = 0;
                func_001ea458(base, o, c->cur++);
            }
            break;
        case 1:
            while (--n != -1) {
                func_001ea458(base, o, (u16)(s32)(VRand() * (f32)e->x2));
            }
            break;
        }
        c->wait = o->reset;
    }
    c->wait--;
}
}  // namespace n001ea4d8

// 001ea6c0 (gap, written for the unit)
namespace n001ea6c0 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x, v, a; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; s32 pad[2]; f32 x, v, a; };
void func_001ea6c0(PObj* o, M* m, PDesc* d) asm("func_001ea6c0");
void func_001ea6c0(PObj* o, M* m, PDesc* d)
{
    V* v = &((PP*)((u8*)o + d->off[0]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        v->v += v->a;
        v->x += v->v;
        if (m->id == o->id) { v->x += m->x; v->v += m->v; v->a += m->a; }
    }
}
}  // namespace n001ea6c0

// 001ea758 (was src/anon/batch_w1944_gnsa.cpp)
namespace n001ea758 {
// 001ea758: morph blend of two s16 vertex shapes; -fno-strict-aliasing.
struct W1944SV { s16 x, y, z; };
struct W1944MorphShape { s32 count; u8 pad4[0x10]; W1944SV* verts; u8 pad18[0xc]; };
struct W1944MorphMgr { u8 pad0[0x10]; W1944MorphShape* shapes; };
struct W1944MorphState { f32 t; u8 pad4[8]; W1944SV* buf; };
struct W1944MorphKeys { u32 pad0; s32 from; s32 to; };
struct W1944MorphCtx { u8 pad0[0xc]; s32* offset; };
struct W1944MorphOut { u8 pad0[0x90]; W1944SV* buf; };
extern W1944MorphMgr* D_01d9e6e4 asm("D_01d9e6e4");
extern W1944MorphOut* D_01d9e6e8 asm("D_01d9e6e8");
W1944SV* func_001e7698(W1944MorphMgr*, s32) asm("func_001e7698");
/*TARGET 001ea758*/
void func_001ea758(u8* base, W1944MorphKeys* k, W1944MorphCtx* c) asm("func_001ea758");
void func_001ea758(u8* base, W1944MorphKeys* k, W1944MorphCtx* c)
{
    if (k->from == 0xffff && k->to == 0xffff) return;
    W1944MorphState* st = (W1944MorphState*)(base + *c->offset + 0xa0);
    W1944SV* va = D_01d9e6e4->shapes[k->from].verts;
    W1944SV* vb = D_01d9e6e4->shapes[k->to].verts;
    s32 n = D_01d9e6e4->shapes[k->from].count;
    if (st->buf == 0) st->buf = func_001e7698(D_01d9e6e4, n * 6);
    W1944SV* out = st->buf;
    while (n--) {
        out->x = (s16)(s32)((f32)(vb->x - va->x) * st->t + (f32)va->x);
        out->y = (s16)(s32)((f32)(vb->y - va->y) * st->t + (f32)va->y);
        out->z = (s16)(s32)((f32)(vb->z - va->z) * st->t + (f32)va->z);
        va++; vb++; out++;
    }
    D_01d9e6e8->buf = st->buf;
}
}  // namespace n001ea758

// 001ea8d8 (gap, written for the unit)
namespace n001ea8d8 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x, y, z; s32 w; };
struct PP { u8 pad[160]; V v; };
void func_001ea8d8(u8* o, PDesc* d) asm("func_001ea8d8");
void func_001ea8d8(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = v->w = v->y = v->z = 0.0f; }
}  // namespace n001ea8d8

// 001ea900 (gap, written for the unit)
namespace n001ea900 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 x; f32 y; f32 z; };
struct PP { u8 pad[160]; V v; };
void func_001ea900(u8* o, PDesc* d) asm("func_001ea900");
void func_001ea900(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = v->y = v->z = 0.0f; }
}  // namespace n001ea900

// 001ea928 (was src/anon/batch_w32.cpp)
namespace n001ea928 {
void func_001e7798(void*, void*) asm("func_001e7798");
extern void* D_01d9e6e4 asm("D_01d9e6e4");
/*TARGET 001ea928*/
// 0x001dc738: definition moved into src/anon/unit_001dbfd8.cpp

void func_001ea928(u8* a, u8* b) asm("func_001ea928");
// 0x001dc738: definition moved into src/anon/unit_001dbfd8.cpp

void func_001ea928(u8* a, u8* b) {
    u8* s = a + **(s32**)(b + 12) + 160;
    void* e = *(void**)(s + 12);
    if (e) {
        func_001e7798(D_01d9e6e4, e);
        *(void**)(s + 12) = 0;
    }
}
}  // namespace n001ea928

// 001ea970 (was src/anon/batch_w247.cpp)
namespace n001ea970 {
union PtrF247 { u8* p; f32 f; };
extern PtrF247 D_01d9e6e8 asm("D_01d9e6e8");
void func_001e8fe0(u8*, u8*) asm("func_001e8fe0");
// VU0 macro: scale row xyz by k.
static inline void ScaleRow247(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
/*TARGET 001ea970*/
void func_001ea970(u8* base, u32 unused, u8* desc) asm("func_001ea970");
void func_001ea970(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_001e8fe0(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow247(D_01d9e6e8.p + 16, s[0]);
    ScaleRow247(D_01d9e6e8.p + 32, s[1]);
    ScaleRow247(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
}  // namespace n001ea970

// 001eaa58 (was src/anon/batch_w248.cpp)
namespace n001eaa58 {
union W248Cam { u8* p; f32 f; };
extern W248Cam D_01d9e6e8 asm("D_01d9e6e8");
void func_0021eb50(void*, void*) asm("func_0021eb50");
static inline void W248Scale(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
/*TARGET 001eaa58*/
void func_001eaa58(u8* o, u32 a1, u8* x) asm("func_001eaa58");
void func_001eaa58(u8* o, u32 a1, u8* x) {
    s32* off = *(s32**)(x + 12);
    f32* pos = (f32*)(o + off[0] + 160);
    f32* rot = (f32*)(o + off[1] + 160);
    f32* scl = (f32*)(o + off[2] + 160);
    func_0021eb50(D_01d9e6e8.p + 16, rot);
    W248Scale(D_01d9e6e8.p + 16, scl[0]);
    W248Scale(D_01d9e6e8.p + 32, scl[1]);
    W248Scale(D_01d9e6e8.p + 48, scl[2]);
    *(f32*)(D_01d9e6e8.p + 64) = pos[0];
    *(f32*)(D_01d9e6e8.p + 68) = pos[1];
    *(f32*)(D_01d9e6e8.p + 72) = pos[2];
}
}  // namespace n001eaa58

// 001eab40 (was src/anon/batch_w248.cpp)
namespace n001eab40 {
union W248Cam { u8* p; f32 f; };
extern W248Cam D_01d9e6e8 asm("D_01d9e6e8");
void func_0021ebe8(void*, void*) asm("func_0021ebe8");
static inline void W248Scale(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
/*TARGET 001eab40*/
void func_001eab40(u8* o, u32 a1, u8* x) asm("func_001eab40");
void func_001eab40(u8* o, u32 a1, u8* x) {
    s32* off = *(s32**)(x + 12);
    f32* pos = (f32*)(o + off[0] + 160);
    f32* rot = (f32*)(o + off[1] + 160);
    f32* scl = (f32*)(o + off[2] + 160);
    func_0021ebe8(D_01d9e6e8.p + 16, rot);
    W248Scale(D_01d9e6e8.p + 16, scl[0]);
    W248Scale(D_01d9e6e8.p + 32, scl[1]);
    W248Scale(D_01d9e6e8.p + 48, scl[2]);
    *(f32*)(D_01d9e6e8.p + 64) = pos[0];
    *(f32*)(D_01d9e6e8.p + 68) = pos[1];
    *(f32*)(D_01d9e6e8.p + 72) = pos[2];
}
}  // namespace n001eab40

// 001eac28 (was src/anon/batch_w247.cpp)
namespace n001eac28 {
union PtrF247 { u8* p; f32 f; };
extern PtrF247 D_01d9e6e8 asm("D_01d9e6e8");
void func_0021ec80(u8*, u8*) asm("func_0021ec80");
// VU0 macro: scale row xyz by k.
static inline void ScaleRow247(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
/*TARGET 001eac28*/
void func_001eac28(u8* base, u32 unused, u8* desc) asm("func_001eac28");
void func_001eac28(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_0021ec80(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow247(D_01d9e6e8.p + 16, s[0]);
    ScaleRow247(D_01d9e6e8.p + 32, s[1]);
    ScaleRow247(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
}  // namespace n001eac28

// 001ead10 (was src/anon/batch_w91.cpp)
namespace n001ead10 {
// 0x001e1070: definition moved into src/anon/unit_001e0cb8.cpp

// --- 001ead10
// Scales the work matrix rows by the bone's scale and copies its translation.
union GP91 { u8* p; f32 f; };
extern GP91 D_01d9e6e8 asm("D_01d9e6e8");
void func_0021ed18(u8*, u8*) asm("func_0021ed18");
static inline void vscl91(u8* m, u32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(m), "r"(s) : "memory");
}
/*TARGET 001ead10*/
void func_001ead10(u8* base, u32, u8* a2) asm("func_001ead10");
void func_001ead10(u8* base, u32, u8* a2) {
    u32* t = *(u32**)(a2 + 12);
    u8* m = base + t[1] + 160;
    f32* tr = (f32*)(base + t[0] + 160);
    u32* sc = (u32*)(base + t[2] + 160);
    func_0021ed18(D_01d9e6e8.p + 16, m);
    vscl91(D_01d9e6e8.p + 16, sc[0]);
    vscl91(D_01d9e6e8.p + 32, sc[1]);
    vscl91(D_01d9e6e8.p + 48, sc[2]);
    *(f32*)(D_01d9e6e8.p + 64) = tr[0];
    *(f32*)(D_01d9e6e8.p + 68) = tr[1];
    *(f32*)(D_01d9e6e8.p + 72) = tr[2];
}
}  // namespace n001ead10

// 001eadf8 (was src/anon/batch_w76.cpp)
namespace n001eadf8 {
// 001dbe78: moved to src/anon/unit_001dbbe0.cpp

union PtrF { u8* p; f32 f; };
extern PtrF D_01d9e6e8 asm("D_01d9e6e8");
void func_0021edb0(u8*, u8*) asm("func_0021edb0");
static inline void ScaleRow(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
/*TARGET 001eadf8*/
void func_001eadf8(u8* base, u32 unused, u8* desc) asm("func_001eadf8");
void func_001eadf8(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_0021edb0(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow(D_01d9e6e8.p + 16, s[0]);
    ScaleRow(D_01d9e6e8.p + 32, s[1]);
    ScaleRow(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
}  // namespace n001eadf8

// 001eaee0 (was src/anon/batch_w3713.cpp)
namespace n001eaee0 {
struct G2_1eaee0 { u8 pad[0x40]; f32 x, y, z; };
union U2_1eaee0 { G2_1eaee0* p; u32 u; u8 c; };
void sceVu0UnitMatrix(void*) asm("sceVu0UnitMatrix");
extern U2_1eaee0 D_01d9e6e8 asm("D_01d9e6e8");
/*TARGET 001eaee0*/
// Copies the owner's 3-float vector at +0xa0 into the global object's x/y/z (after sceVu0UnitMatrix on it).
// Partial asm: the pointer to the vector is formed by one asm addiu pinned to t5 with a "memory"
// clobber, so the float load comes first and the next global reload waits for it (closest C: 6 diffs,
// t6/t7 swapped and ld s0/ra order).
void func_001eaee0(s32 a0, s32 a1, u32** a2) asm("func_001eaee0");
// Copies the owner's 3-float vector at +0xa0 into the global object's x/y/z (after sceVu0UnitMatrix on it).
// Partial asm: the pointer to the vector is formed by one asm addiu pinned to t5 with a "memory"
// clobber, so the float load comes first and the next global reload waits for it (closest C: 6 diffs,
// t6/t7 swapped and ld s0/ra order).
void func_001eaee0(s32 a0, s32 a1, u32** a2) {
    u8* p = (u8*)(a0 + **(s32**)((u8*)a2 + 0xc));
    sceVu0UnitMatrix((u8*)D_01d9e6e8.p + 0x10);
    f32 f = *(f32*)(p + 0xa0);
    register f32* v asm("$13");
    asm("addiu %0,%1,160" : "=r"(v) : "r"(p) : "memory");
    D_01d9e6e8.p->x = f;
    D_01d9e6e8.p->y = v[1];
    D_01d9e6e8.p->z = v[2];
}
}  // namespace n001eaee0

// 001eaf50 (was src/anon/batch_wcx2.cpp)
namespace n001eaf50 {
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
// 0x0011bfa0: definition moved into src/anon/unit_0011b3f8.cpp

// --------------------
struct P1eaf50 { f32 x, y, z; };
struct M1eaf50 { u8 pad[16]; f32 m[4][4]; };
union G1eaf50 { M1eaf50* p; u32 u; };
extern G1eaf50 D_01d9e6e8_1eaf50 asm("D_01d9e6e8");
struct O1eaf50 { u32 a; u32 b; };
struct H1eaf50 { u8 pad[0xc]; O1eaf50* ofs; };
void sceVu0UnitMatrix(f32 (*)[4]) asm("sceVu0UnitMatrix");
/*TARGET 001eaf50*/
void func_001eaf50(u8* base, u32, H1eaf50* h) asm("func_001eaf50");
void func_001eaf50(u8* base, u32, H1eaf50* h)
{
    O1eaf50* o = h->ofs;
    u8* r = base + o->a;
    u8* q = base + o->b;
    P1eaf50* s = (P1eaf50*)(q + 160);
    sceVu0UnitMatrix(D_01d9e6e8_1eaf50.p->m);
    P1eaf50* t = (P1eaf50*)(r + 160);
    D_01d9e6e8_1eaf50.p->m[0][0] = s->x;
    D_01d9e6e8_1eaf50.p->m[1][1] = s->y;
    D_01d9e6e8_1eaf50.p->m[2][2] = s->z;
    D_01d9e6e8_1eaf50.p->m[3][0] = t->x;
    D_01d9e6e8_1eaf50.p->m[3][1] = t->y;
    D_01d9e6e8_1eaf50.p->m[3][2] = t->z;
}
}  // namespace n001eaf50

// 001eb000 (was src/anon/tiny_wrappers_imp.cpp)
namespace n001eb000 {
u32 sceVu0ApplyMatrix(u32, u32, u32, u32) asm("_Z17sceVu0ApplyMatrixjjjj");
/*TARGET 001eb000*/
u32 func_001eb000(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001eb000jjjj");
u32 func_001eb000(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = r4;
    r15 = (u32)(0x01dau << 16);
    r4 = *(u32*)((u32)r15 + (s32)(-6424));
    r5 = *(u32*)((u32)r14 + (s32)(4));
    r4 = (u32)((s32)r4 + (64));
    r5 = (u32)((s32)r5 + (16));
    r6 = r4;
    return sceVu0ApplyMatrix(r4, r5, r6, r7);
}
}  // namespace n001eb000

// 001eb030 (was src/anon/batch_w54.cpp)
namespace n001eb030 {
void sceVu0UnitMatrix(f32*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0MulMatrix(void*, f32*, void*) asm("sceVu0MulMatrix");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
/*TARGET 001eb030*/
// scale matrix built from two clamped factors
void func_001eb030(void* a0, f32* s) asm("func_001eb030");
// scale matrix built from two clamped factors
void func_001eb030(void* a0, f32* s) {
    f32 m[16];
    sceVu0UnitMatrix(m);  // vu_store_w_splat
    f32 k = s[1];
    f32 mx = s[2];
    u8* t = D_01d9e6e0;
    f32 x = *(f32*)(t + 64);
    m[0] = x + x * k;
    if (mx < m[0]) m[0] = mx;
    m[10] = m[0];
    f32 y = *(f32*)(t + 68);
    m[5] = y + y * k;
    if (mx < m[5]) m[5] = mx;
    sceVu0MulMatrix(D_01d9e6e8 + 16, m, D_01d9e6e8 + 16);
}
}  // namespace n001eb030

// 001eb0c8 (was src/anon/batch_w37.cpp)
namespace n001eb0c8 {
// 0x001e78e0: definition moved into src/anon/unit_001e0cb8.cpp

void sceVu0UnitMatrix(void*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
/*TARGET 001eb0c8*/
void func_001eb0c8(void* unused, f32* s) asm("func_001eb0c8");
void func_001eb0c8(void* unused, f32* s) {
    f32 m[16];
    sceVu0UnitMatrix(m);  // vu_store_w_splat
    f32 base = *(f32*)(D_01d9e6e0 + 64);
    f32 lim = s[2];
    u8* t = D_01d9e6e8 + 16;
    m[0] = base + base * s[1];
    if (lim < m[0]) m[0] = lim;
    m[10] = m[0];
    sceVu0MulMatrix(t, m, t);
}
}  // namespace n001eb0c8

// 001eb140 (was src/anon/batch_w44.cpp)
namespace n001eb140 {
void sceVu0UnitMatrix(void*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
// 0x001dd2b8: definition moved into src/anon/unit_001dd2b8.cpp

extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
/*TARGET 001eb140*/
void func_001eb140(void*, f32* v) asm("func_001eb140");
void func_001eb140(void*, f32* v) {
    f32 m[4][4];
    sceVu0UnitMatrix(m);  // vu_store_w_splat
    f32 h = *(f32*)(D_01d9e6e0 + 68);
    f32 y = h + h * v[1];
    m[1][1] = y;
    if (v[2] < y) m[1][1] = v[2];
    u8* p = D_01d9e6e8 + 16;
    sceVu0MulMatrix(p, m, p);
}
}  // namespace n001eb140

// 001eb1b0 (was src/anon/batch_w44.cpp)
namespace n001eb1b0 {
void sceVu0UnitMatrix(void*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
// 0x001dd2b8: definition moved into src/anon/unit_001dd2b8.cpp

extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
/*TARGET 001eb1b0*/
void func_001eb1b0(void*, f32* v) asm("func_001eb1b0");
void func_001eb1b0(void*, f32* v) {
    f32 m[4][4];
    sceVu0UnitMatrix(m);  // vu_store_w_splat
    f32 h = *(f32*)(D_01d9e6e0 + 68);
    f32 y = h + h * v[1];
    m[1][1] = y;
    if (v[2] < y) m[1][1] = v[2];
    m[0][0] = m[1][1] = m[2][2];
    u8* p = D_01d9e6e8 + 16;
    sceVu0MulMatrix(p, m, p);
}
}  // namespace n001eb1b0

// 001eb228 (was src/anon/batch_w45.cpp)
namespace n001eb228 {
void sceVu0UnitMatrix(f32*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0MulMatrix(u8*, f32*, u8*) asm("sceVu0MulMatrix");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
/*TARGET 001eb228*/
// scale matrix (clamped) applied to the global transform
void func_001eb228(u32 a0, f32* a1) asm("func_001eb228");
// scale matrix (clamped) applied to the global transform
void func_001eb228(u32 a0, f32* a1) {
    f32 m[16] __attribute__((aligned(16)));
    sceVu0UnitMatrix(m);  // vu_store_w_splat
    f32 s = *(f32*)(D_01d9e6e0 + 64);
    f32 v = s + s * a1[1];
    m[0] = v;
    if (a1[2] < v) m[0] = a1[2];
    m[10] = m[0];
    m[5] = m[0];
    u8* p = D_01d9e6e8 + 16;
    sceVu0MulMatrix(p, m, p);
}
}  // namespace n001eb228

// 001eb2a0 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n001eb2a0 {
u32 sceVu0MulMatrix(u32, u32, u32, u32) asm("_Z15sceVu0MulMatrixjjjj");
extern u8 D_01d9e900 asm("D_01d9e900");
extern u8 D_01da0000 asm("D_01da0000");
/*TARGET 001eb2a0*/
// 0x001d9ad8: definition moved into src/anon/unit_001d7458.cpp

// 001e0428: moved to src/anon/unit_001e0398.cpp

// 001e0670: moved to src/anon/unit_001e0398.cpp

u32 func_001eb2a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001eb2a0jjjj");
// 0x001d9ad8: definition moved into src/anon/unit_001d7458.cpp

// 001e0428: moved to src/anon/unit_001e0398.cpp

// 001e0670: moved to src/anon/unit_001e0398.cpp

u32 func_001eb2a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return sceVu0MulMatrix(((u32)(((u32)(*(u32*)((u32)((u32)&D_01da0000) - 6424u)))) + 80u), (u32)&D_01d9e900, ((u32)(((u32)(*(u32*)((u32)((u32)&D_01da0000) - 6424u)))) + 16u), a3);
}
}  // namespace n001eb2a0

// 001eb2d0 (gap, written for the unit)
namespace n001eb2d0 {
extern "C" f32 D_00354be0[3];
extern "C" u8* D_01d9e6e8;
extern "C" u8 D_01d9e840[], D_01d9e8c0[];
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
void sceVu0ApplyMatrix(void*, void*, void*) asm("sceVu0ApplyMatrix");
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
void func_001eb2d0(void) asm("func_001eb2d0");
void func_001eb2d0(void)
{
    sceVu0ScaleVector(D_01d9e6e8 + 80, D_01d9e6e8 + 16, D_00354be0[0]);
    sceVu0ScaleVector(D_01d9e6e8 + 96, D_01d9e6e8 + 32, D_00354be0[1]);
    sceVu0ScaleVector(D_01d9e6e8 + 112, D_01d9e6e8 + 48, D_00354be0[2]);
    sceVu0ApplyMatrix(D_01d9e6e8 + 128, D_01d9e840, D_01d9e6e8 + 64);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
}  // namespace n001eb2d0

// 001eb368 (was src/anon/batch_w86.cpp)
namespace n001eb368 {
struct M { u8 p0[16]; u8 a[16]; u8 b[16]; u8 c[16]; u8 d[16]; u8 r0[16]; u8 r1[16]; u8 r2[16]; f32 t[4]; };
union MP { M* p; f32 f; };
extern MP D_01d9e6e8 asm("D_01d9e6e8");
extern f32 D_00354be0[] asm("D_00354be0");
extern f32 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0MulVector(void*, void*, f32*) asm("sceVu0MulVector");
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
/*TARGET 001eb368*/
void func_001eb368(void) asm("func_001eb368");
void func_001eb368(void)
{
    sceVu0ScaleVector(D_01d9e6e8.p->r0, D_01d9e6e8.p->a, D_00354be0[0]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8.p->r1, D_01d9e6e8.p->b, D_00354be0[1]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8.p->r2, D_01d9e6e8.p->c, D_00354be0[2]);  // vec_scale_by_f12
    sceVu0MulVector(D_01d9e6e8.p->t, D_01d9e6e8.p->d, D_00354be0);
    D_01d9e6e8.p->t[0] += D_01d9e840[12];
    D_01d9e6e8.p->t[1] += D_01d9e840[13];
    D_01d9e6e8.p->t[2] += D_01d9e840[14];
    D_01d9e6e8.p->t[3] = 1.0f;
    sceVu0MulMatrix(D_01d9e6e8.p->r0, D_01d9e8c0, D_01d9e6e8.p->r0);
}
}  // namespace n001eb368

// 001eb458 (gap, written for the unit)
namespace n001eb458 {
void func_001eb458(void) asm("func_001eb458");
void func_001eb458(void) {}
}  // namespace n001eb458

// 001eb460 (was src/anon/batch_wcx.cpp)
namespace n001eb460 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern f32 D_00354be0[3] asm("D_00354be0");
extern u8 D_01d9e940[] asm("D_01d9e940");
extern u8 D_01d9e900[] asm("D_01d9e900");
void sceVu0ScaleVector(u8*, u8*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0MulMatrix(u8*, u8*, u8*) asm("sceVu0MulMatrix");
void sceVu0ApplyMatrix(u8*, u8*, u8*) asm("sceVu0ApplyMatrix");
union GPV { u8* p; V4 v; };
extern GPV D_01d9e6e8u asm("D_01d9e6e8");
/*TARGET 001eb460*/
void func_001eb460(void) asm("func_001eb460");
void func_001eb460(void)
{
    f32* s = D_00354be0;
    sceVu0ScaleVector(D_01d9e6e8u.p + 80, D_01d9e6e8u.p + 16, s[0]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8u.p + 96, D_01d9e6e8u.p + 32, s[1]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8u.p + 112, D_01d9e6e8u.p + 48, s[2]);  // vec_scale_by_f12
    *(V4*)(D_01d9e6e8u.p + 128) = *(V4*)(D_01d9e6e8u.p + 64);
    sceVu0MulMatrix(D_01d9e6e8u.p + 80, D_01d9e940, D_01d9e6e8u.p + 80);
    sceVu0ApplyMatrix(D_01d9e6e8u.p + 128, D_01d9e900, D_01d9e6e8u.p + 64);
}
}  // namespace n001eb460

// 001eb508 (gap, written for the unit)
namespace n001eb508 {
struct PDesc { u32 p0, p4, p8; s32* off; };
extern "C" u8* D_01d9ea94;
void func_001eb508(u8* o, void* m, PDesc* d) asm("func_001eb508");
void func_001eb508(u8* o, void* m, PDesc* d) { D_01d9ea94 = o + d->off[0] + 160; }
}  // namespace n001eb508

// 001eb528 (was src/anon/batch_w3832_nsa.c)
namespace n001eb528 {
struct Prm {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s32 w16; s32 w20;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; s32 w68; s32 w72; u8 b76; u8 b77; u8 pad78[2]; s32 pad80[4];
};
struct Slot { u8 pad[28]; u32* h; s32 w32; };
struct Sys { u8 pad[16]; Slot* slots; };
struct Sys2 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Arg1 { s32 w0; s32 idx; };
struct Arg2 { u8 pad[12]; s32* off; };
struct Col { u8 pad[8]; u8 r, g, b, a; };
extern Sys* D_01d9e6e4 asm("D_01d9e6e4");
extern Sys2* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern u8 D_01d9e980[] asm("D_01d9e980");
s32 func_0020f1e0(u32*, Prm*, s32) asm("func_0020f1e0");
/*TARGET 001eb528*/
void func_001eb528(u8* base, Arg1* a, Arg2* b) asm("func_001eb528");
void func_001eb528(u8* base, Arg1* a, Arg2* b) {
    Prm prm;
    s32 idx = a->idx;
    if (idx == 0xffff) return;
    Col* c = (Col*)(base + *b->off + 0xa0);
    prm.c27 = c->a;
    if (prm.c27 == 0) return;
    Slot* s = &D_01d9e6e4->slots[idx];
    u32* h = s->h;
    u32 h1 = *h & 1; if (h1) *(s32*)&prm = 128; else *(s32*)&prm = 12;
    if (!(*h & 2)) *(s32*)&prm |= 0x10;
    Sys2* g = D_01d9e6e8;
    *(u16*)((u8*)&prm + 8) = ((u16*)h)[0x16 / 2];
    prm.b10 = 0;
    *(s32*)((u8*)&prm + 28) = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.c24 = c->r;
    prm.c25 = c->g;
    prm.c26 = c->b;
    prm.p32 = g->a80;
    prm.p36 = D_01d9e9c0;
    prm.p40 = D_01d9e980;
    prm.p44 = g->a16;
    *(s32*)((u8*)&prm + 52) = D_01d9eaa4;
    prm.w12 = 0;
    *(s64*)((u8*)&prm + 16) = 0;
    *(s32*)((u8*)&prm + 64) = 0;
    prm.w68 = 0;
    prm.b76 = 0;
    prm.b77 = 0;
    D_01d9eaa4 = func_0020f1e0(h, &prm, s->w32);
}
}  // namespace n001eb528

// 001eb668 (was src/anon/batch_w8009_nsa.cpp)
namespace n001eb668 {
// 001eb668: the h8 store goes through a byte-offset cast. As a plain field store it
// ranks lhu above the lui of D_01d9e6e8 in sched2.
struct Prm1eb668 {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s64 d16;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; s32 w68; s32 w72; s32 w76; s32 pad80[4];
};
struct Slot1eb668 { u8 pad[28]; u32* h; s32 w32; };
struct Sys1eb668 { u8 pad[16]; Slot1eb668* slots; };
struct Sys21eb668 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Arg11eb668 { s32 w0; s32 idx; u16 h8; };
struct Arg21eb668 { u8 pad[12]; s32* off; };
struct Pos1eb668 { s16 v[4]; };
extern Sys1eb668* D_01d9e6e4 asm("D_01d9e6e4");
extern Sys21eb668* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern u8 D_01d9e980[] asm("D_01d9e980");
s32 func_0020f1e0(u32*, Prm1eb668*, s32) asm("func_0020f1e0");
/*TARGET 001eb668*/
void func_001eb668(u8* base, Arg11eb668* a, Arg21eb668* b) asm("func_001eb668");
void func_001eb668(u8* base, Arg11eb668* a, Arg21eb668* b) {
    Prm1eb668 prm;
    s32 idx = a->idx;
    if (idx == 0xffff) return;
    u8* q = base + *b->off;
    Pos1eb668* ps = (Pos1eb668*)(q + 0xa0);
    prm.c27 = ps->v[3] >> 7;
    if (prm.c27 == 0) return;
    Slot1eb668* s = &D_01d9e6e4->slots[idx];
    u32* h = s->h;
    prm.flags = 0x80;
    if (!(*h & 2)) prm.flags = 0x90;
    Sys21eb668* g = D_01d9e6e8;
    *(u16*)((u8*)&prm + 8) = a->h8;
    prm.b10 = 0;
    prm.w28 = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.w12 = 0;
    prm.d16 = 0;
    prm.w64 = 0;
    prm.c24 = ((Pos1eb668*)(q + 0xa0))->v[0] >> 7;
    prm.c25 = ps->v[1] >> 7;
    prm.c26 = ps->v[2] >> 7;
    prm.p32 = g->a80;
    prm.p36 = D_01d9e9c0;
    prm.p40 = D_01d9e980;
    prm.p44 = g->a16;
    prm.w52 = D_01d9eaa4;
    prm.w68 = 0;
    D_01d9eaa4 = func_0020f1e0(h, &prm, s->w32);
}
}  // namespace n001eb668

// 001eb7a0 (gap, written for the unit)
namespace n001eb7a0 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 a; f32 b; f32 c; f32 d; f32 e; f32 f; };
struct PP { u8 pad[160]; V v; };
void func_001eb7a0(u8* o, PDesc* d) asm("func_001eb7a0");
void func_001eb7a0(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[2]))->v; v->a = v->b = v->c = v->d = v->e = v->f = 0.0f; }
}  // namespace n001eb7a0

// 001eb7d0 (gap, written for the unit)
namespace n001eb7d0 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { f32 a, b, c, d, e, f; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; s32 pad; f32 a, b, c, d, e, f; };
void func_001eb7d0(PObj* o, M* m, PDesc* d) asm("func_001eb7d0");
void func_001eb7d0(PObj* o, M* m, PDesc* d)
{
    V* v = &((PP*)((u8*)o + d->off[2]))->v;
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        v->b += v->c;
        v->a += v->b;
        v->e += v->f;
        v->d += v->e;
        if (m->id == o->id) {
            v->a += m->a; v->b += m->b; v->c += m->c;
            v->d += m->d; v->e += m->e; v->f += m->f;
        }
    }
}
}  // namespace n001eb7d0

// 001eb8a8 (was src/anon/batch_w3793_nsa.c)
namespace n001eb8a8 {
struct Prm {
    union { s32 flags; struct { u32 lo : 4; u32 b4 : 1; } bits; }; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s32 w16; s32 w20;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; s32 w68; s32 w72; u8 b76; u8 b77; u8 pad78[2]; s32 pad80[4];
};
struct Slot { u8 pad[28]; u32* h; s32 w32; };
struct Sys { u8 pad[16]; Slot* slots; };
struct Sys2 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Arg1 { s32 w0; s32 idx; };
struct Arg2 { u8 pad[12]; s32* off; };
struct Col { u8 pad[8]; u8 r, g, b, a; };
struct Pos { f32 x, y, z, w; };
extern Sys* D_01d9e6e4 asm("D_01d9e6e4");
extern Sys2* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern u8 D_01d9e980[] asm("D_01d9e980");
s32 func_0020f1e0(u32*, Prm*, s32) asm("func_0020f1e0");
/*TARGET 001eb8a8*/
void func_001eb8a8(u8* base, Arg1* a, Arg2* b) asm("func_001eb8a8");
void func_001eb8a8(u8* base, Arg1* a, Arg2* b) {
    Prm prm;
    s32* off = b->off;
    s32 idx = a->idx;
    Pos* ps = (Pos*)(base + off[2] + 0xa0);
    if (idx == 0xffff) return;
    Col* c = (Col*)(base + off[0] + 0xa0);
    prm.c27 = c->a;
    if (prm.c27 == 0) return;
    Slot* s = &D_01d9e6e4->slots[idx];
    u32* h = s->h;
    if ((*h & 1) == 1) *(s32*)&prm = 128; else *(s32*)&prm = 12;
    if (!(*h & 2)) *(s32*)&prm |= 0x10;
    *(u16*)((u8*)&prm + 8) = ((u16*)h)[0x16 / 2];
    Sys2* g = D_01d9e6e8;
    prm.b10 = 0;
    *(s32*)((u8*)&prm + 28) = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.c24 = c->r;
    prm.w16 = (s32)(ps->x * 65536.0f);
    prm.c25 = c->g;
    prm.c26 = c->b;
    prm.w12 = 0;
    prm.p32 = g->a80;
    prm.p36 = D_01d9e9c0;
    prm.p40 = D_01d9e980;
    *(s32*)((u8*)&prm + 20) = (s32)(ps->w * 65536.0f);
    prm.p44 = g->a16;
    *(s32*)((u8*)&prm + 64) = 0;
    *(s32*)((u8*)&prm + 52) = D_01d9eaa4;
    prm.w68 = 0;
    prm.b76 = 0;
    prm.b77 = 0;
    D_01d9eaa4 = func_0020f1e0(h, &prm, s->w32);
}
}  // namespace n001eb8a8

// 001eba20 (gap, written for the unit)
namespace n001eba20 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x; u16 y; u16 z; };
struct PP { u8 pad[160]; V v; };
void func_001eba20(u8* o, PDesc* d) asm("func_001eba20");
void func_001eba20(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = v->y = v->z = 0; }
}  // namespace n001eba20

// 001eba40 (gap, written for the unit)
namespace n001eba40 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PDesc { u32 p0, p4, p8; s32* off; };
struct AK { u8 p0[2]; s16 dur; s8 flags; u8 p5[3]; };
struct AN { u8 p0[6]; s16 count; u8 p8[8]; AK k[1]; };
struct AE { AN* an; u32 p4; };
struct G { u8 pad[20]; AE* tbl; };
extern "C" G* D_01d9e6e4;
struct V { u16 cnt, frame, idx; };
struct PP { u8 pad[160]; V v; };
struct M { s32 p0; s32 id; u16 spd; };
void func_001eba40(u8* o, M* m, PDesc* d) asm("func_001eba40");
void func_001eba40(u8* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        V* v = &((PP*)(o + d->off[0]))->v;
        s32 id = m->id;
        if (id == 0xffff) return;
        AN* an = *(AN**)((u8*)D_01d9e6e4->tbl + (id << 3));
        u16 fr = v->frame;
        AK* k = &an->k[v->idx];
        v->idx = fr;
        v->cnt += m->spd;
        if (v->cnt >= k->dur) {
            v->cnt -= k->dur;
            v->frame = fr + 1;
            if ((u16)(fr + 1) >= an->count) {
                if (k->flags & 0x80) { v->frame = 0; v->cnt = 0; }
                else { v->frame = fr; v->cnt = 0; }
            }
        }
    }
}
}  // namespace n001eba40

// 001ebb30 (was src/anon/batch_w1815_nsa.cpp)
namespace n001ebb30 {
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
struct Peb { u16 a0; u16 flags; u8 c[4]; u64 f8; u8* f10; s32 f14; u8 f18; u32 f1c; u8 pad[16]; };
struct Teb { s32 a; s32 b; };
struct A2eb { u8 p0[0xc]; Teb* fc; };
struct A1eb { u32 p0; s32 f4; u8 p8[4]; u8 bc; u8 bd; };
struct Eeb { u8* data; s32 x; };
struct Oeb { u8 p0[0x14]; Eeb* f14; };
extern Oeb* D_01d9e6e4 asm("D_01d9e6e4");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
s32 func_0021d048(u8*, Peb*, s32) asm("func_0021d048");
/*TARGET 001ebb30*/
void func_001ebb30(u8* a0, A1eb* a1, A2eb* a2) asm("func_001ebb30");
void func_001ebb30(u8* a0, A1eb* a1, A2eb* a2) {
    u8* q = a0 + a2->fc->a + 0xa0;
    u8* t = a0 + a2->fc->b + 0xa0;
    if (a1->f4 != 0xffff) {
        Eeb* e = &D_01d9e6e4->f14[a1->f4];
        Peb p;
        p.f10 = D_01d9e6e8 + 80;
        p.f8 = 0;
        p.f18 = 0;
        p.f1c = 0;
        if (!a1->bc) p.flags = 0x80; else p.flags = 0;
        if (a1->bd == 1) p.flags |= 0x10;
        s32 old = D_01d9eaa4;
        p.c[0] = t[8]; p.c[1] = t[9]; p.c[2] = t[10]; p.c[3] = t[11];
        s32 o = *(u16*)(q + 4) * 8;
        u8* d = e->data;
        u8* a = d + *(s16*)(d + o + 16);
        p.f14 = old;
        s32 x = e->x;
        D_01d9eaa4 = func_0021d048(a, &p, x);
    }
}
}  // namespace n001ebb30

// 001ebc30 (gap, written for the unit)
namespace n001ebc30 {
struct E16 { u32 p0; u8* obj; u32 p8, pc; };
struct PMng { u8 pad[0x80]; E16* tbl; u8 pad2[0xa8 - 0x84]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V3 { f32 x, y, z; };
extern "C" V3 D_01d9e360;
struct V { f32 x, y, z; V3* src; };
struct PP { u8 pad[160]; V v; };
struct M { s32 id; s32 k; s32 off; };
void func_001ebc30(PObj* o, M* m, PDesc* d) asm("func_001ebc30");
void func_001ebc30(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        V* v = &((PP*)((u8*)o + d->off[0]))->v;
        if (m->id == o->id) {
            V3* n;
            if (m->k != -1) n = (V3*)(D_01d9e6e0->tbl[m->k].obj + m->off + 160);
            else n = &D_01d9e360;
            v->src = n;
        }
        V3* s = v->src;
        f32 x = s->x, y = s->y, z = s->z;
        v->x = x; v->y = y; v->z = z;
    }
}
}  // namespace n001ebc30

// 001ebcd8 (gap, written for the unit)
namespace n001ebcd8 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u8 a, b; };
struct PP { u8 pad[160]; V v; };
void func_001ebcd8(u8* o, PDesc* d) asm("func_001ebcd8");
void func_001ebcd8(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->b = 0; }
}  // namespace n001ebcd8

// 001ebcf0 (was src/anon/batch_w1836_nsa.cpp)
namespace n001ebcf0 {
struct W1836Ebc { u8 pad[128]; u8* tbl; u8 pad2[36]; s64 flags; };
struct W1836EbOff { s32 a; s32 b; };
struct W1836EbArg2 { u8 pad[12]; W1836EbOff* off; };
struct W1836EbArg1 { s32 pad0; s32 idx; s32 ofs; u8 reset; u8 cnt; };
struct W1836V3c { f32 x, y, z; };
// 0x001e3330: definition moved into src/anon/unit_001e0cb8.cpp

u8* func_001e7a98(W1836Ebc*, u8*) asm("func_001e7a98");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern W1836Ebc* D_01d9e6e0 asm("D_01d9e6e0");
/*TARGET 001ebcf0*/
void func_001ebcf0(u8* a0, W1836EbArg1* a1, W1836EbArg2* a2) asm("func_001ebcf0");
void func_001ebcf0(u8* a0, W1836EbArg1* a1, W1836EbArg2* a2)
{
    W1836EbOff* o = a2->off;
    f32* src = (f32*)(a0 + o->a + 160);
    u8* st = a0 + o->b + 160;
    s32 n;

    if (D_01d9ea9c != 0)
        return;
    if (D_01d9e6e0->flags & 0xff0000ff00LL)
        return;
    if (st[1] == 0) {
        n = a1->cnt;
        while (n-- != 0) {
            u8* v = 0;
            u8* t = D_01d9e6e0->tbl + a1->idx * 16;
            if (t != 0) {
                v = func_001e7a98(D_01d9e6e0, t);
                *(u8**)(v + 4) = a0;
            }
            W1836V3c* d = (W1836V3c*)(v + a1->ofs + 160);
            W1836V3c* sp = (W1836V3c*)src;
            d->x = sp->x;
            d->y = sp->y;
            d->z = sp->z;
        }
        st[1] = a1->reset;
    }
    st[1]--;
}
}  // namespace n001ebcf0

// 001ebe28 (gap, written for the unit)
namespace n001ebe28 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u8 a, b; };
struct PP { u8 pad[160]; V v; };
void func_001ebe28(u8* o, PDesc* d) asm("func_001ebe28");
void func_001ebe28(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[1]))->v; v->b = 0; }
}  // namespace n001ebe28

// 001ebe40 (was src/anon/batch_w3917_nsa.c)
namespace n001ebe40 {
typedef struct { f32 x, y, z; } SpV1ebe40;
typedef struct { u8 pad0[4]; f32 rad; f32 speed; s32 obj; s32 posOff; u8 pad1[4]; s32 velOff; u8 wait; } Spawn1ebe40;
typedef struct { u8 pad0[1]; u8 wait; } SpSt1ebe40;
typedef struct { u8 pad0[12]; s32* off; } SpCtx1ebe40;
typedef struct { u8 pad0[128]; u8* objs; u8 pad1[168 - 132]; u64 b168 : 8, stopA : 8, b170 : 8, dead : 8, stopB : 8, b173 : 24; } Part1ebe40;
typedef struct { u8 pad0[4]; u8* base; } SpObj1ebe40;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Part1ebe40* D_01d9e6e0 asm("D_01d9e6e0");
extern f32 D_00359a20[] asm("D_00359a20");
/* sine table, 4096 entries for a 65536 turn */
SpObj1ebe40* func_001e7a98(Part1ebe40*, u8*) asm("func_001e7a98");
#define SIN1ebe40(a) D_00359a20[((u32)(a) >> 4) & 0xfff]
#define COS1ebe40(a) D_00359a20[((u32)(a) + 16384 >> 4) & 0xfff]
#define RAND1ebe40(r) asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(r) : : "$8")
/*TARGET 001ebe40*/
/* Particle emitter step: when the wait counter runs out, spawn one object at a random
   point on a sphere of radius e->rad around pos, moving outwards at e->speed. */
void func_001ebe40(u8* base, Spawn1ebe40* e, SpCtx1ebe40* c) asm("func_001ebe40");
/* Particle emitter step: when the wait counter runs out, spawn one object at a random
   point on a sphere of radius e->rad around pos, moving outwards at e->speed. */
void func_001ebe40(u8* base, Spawn1ebe40* e, SpCtx1ebe40* c)
{
    SpSt1ebe40* st = (SpSt1ebe40*)(base + c->off[1] + 160);
    SpV1ebe40* pos;
    SpObj1ebe40* o;
    u8* tmpl;
    SpV1ebe40* p;
    SpV1ebe40* v;
    s32 a;
    f32 r, sa, ca, sb;

    if (D_01d9ea9c) return;
    if (D_01d9e6e0->stopA || D_01d9e6e0->stopB) return;
    if (st->wait == 0) {
        pos = (SpV1ebe40*)(base + c->off[0] + 160);
        if (e->obj == -1) return;
        tmpl = D_01d9e6e0->objs + e->obj * 16;
        if (!tmpl) {
            o = 0;
        } else {
            o = func_001e7a98(D_01d9e6e0, tmpl);
            o->base = base;
        }
        RAND1ebe40(r);
        a = r * 32768.0f - 16384.0f;
        sa = SIN1ebe40(a) * e->rad;
        ca = COS1ebe40(a) * e->rad;
        RAND1ebe40(r);
        a = r * 32768.0f * 2.0f;
        sb = SIN1ebe40(a) * ca;
        ca = ca * COS1ebe40(a);
        p = (SpV1ebe40*)((u8*)o + e->posOff + 160);
        v = (SpV1ebe40*)((u8*)o + e->velOff + 160);
        p->x = pos->x + sb;
        p->y = pos->y + sa;
        p->z = pos->z + ca;
        v->x = sb * e->speed;
        v->y = sa * e->speed;
        v->z = ca * e->speed;
        st->wait = e->wait;
    }
    st->wait--;
}
}  // namespace n001ebe40

