// Linked unit 0x001ec098-0x001ef780 (pppPart.c: random and colour programs; one namespace per old matched source,
// gap functions written for the unit). Built as C++ with -G0 -g.
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 001ec098 (gap, written for the unit)
namespace n001ec098 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; f32 s; u8 flag; };
void func_001ec098(PObj* o, M* m, PDesc* d) asm("func_001ec098");
void func_001ec098(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd();
            if (m->flag) r += rnd(); else r += r;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        f32* t;
        if (m->k != -1) t = (f32*)((u8*)o + m->k + 160);
        else t = (f32*)D_01d9e360;
        *t += m->s * *v - m->s;
    }
}
}  // namespace n001ec098

// 001ec1d8 (gap, written for the unit)
namespace n001ec1d8 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; f32 s; u8 flag; };
void func_001ec1d8(PObj* o, M* m, PDesc* d) asm("func_001ec1d8");
void func_001ec1d8(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd();
            if (m->flag) r = (r + rnd()) * 0.5f;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        f32* t;
        if (m->k != -1) t = (f32*)((u8*)o + m->k + 160);
        else t = (f32*)D_01d9e360;
        *t += m->s * *v;
    }
}
}  // namespace n001ec1d8

// 001ec328 (gap, written for the unit)
namespace n001ec328 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; f32 s; u8 flag; };
void func_001ec328(PObj* o, M* m, PDesc* d) asm("func_001ec328");
void func_001ec328(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd(); r = -r;
            if (m->flag) r = (r - rnd()) * 0.5f;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        f32* t;
        if (m->k != -1) t = (f32*)((u8*)o + m->k + 160);
        else t = (f32*)D_01d9e360;
        *t += m->s * *v;
    }
}
}  // namespace n001ec328

// 001ec478 (gap, written for the unit)
namespace n001ec478 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; u8 s; u8 flag; };
void func_001ec478(PObj* o, M* m, PDesc* d) asm("func_001ec478");
void func_001ec478(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd();
            if (m->flag) r += rnd(); else r += r;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        u8* t;
        if (m->k != -1) t = (u8*)((u8*)o + m->k + 160);
        else t = (u8*)D_01d9e360;
        *t += (s32)((f32)m->s * *v - (f32)m->s);
    }
}
}  // namespace n001ec478

// 001ec5c8 (gap, written for the unit)
namespace n001ec5c8 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; u8 s; u8 flag; };
void func_001ec5c8(PObj* o, M* m, PDesc* d) asm("func_001ec5c8");
void func_001ec5c8(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd();
            if (m->flag) r = (r + rnd()) * 0.5f;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        u8* t;
        if (m->k != -1) t = (u8*)((u8*)o + m->k + 160);
        else t = (u8*)D_01d9e360;
        *t += (s32)((f32)m->s * *v);
    }
}
}  // namespace n001ec5c8

// 001ec728 (gap, written for the unit)
namespace n001ec728 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; u8 s; u8 flag; };
void func_001ec728(PObj* o, M* m, PDesc* d) asm("func_001ec728");
void func_001ec728(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd(); r = -r;
            if (m->flag) r = (r - rnd()) * 0.5f;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        u8* t;
        if (m->k != -1) t = (u8*)((u8*)o + m->k + 160);
        else t = (u8*)D_01d9e360;
        *t += (s32)((f32)m->s * *v);
    }
}
}  // namespace n001ec728

// 001ec888 (gap, written for the unit)
namespace n001ec888 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; u16 s; u8 flag; };
void func_001ec888(PObj* o, M* m, PDesc* d) asm("func_001ec888");
void func_001ec888(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd();
            if (m->flag) r += rnd(); else r += r;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        u16* t;
        if (m->k != -1) t = (u16*)((u8*)o + m->k + 160);
        else t = (u16*)D_01d9e360;
        *t += (s32)((f32)m->s * *v - (f32)m->s);
    }
}
}  // namespace n001ec888

// 001ec9d8 (gap, written for the unit)
namespace n001ec9d8 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; u16 s; u8 flag; };
void func_001ec9d8(PObj* o, M* m, PDesc* d) asm("func_001ec9d8");
void func_001ec9d8(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd();
            if (m->flag) r = (r + rnd()) * 0.5f;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        u16* t;
        if (m->k != -1) t = (u16*)((u8*)o + m->k + 160);
        else t = (u16*)D_01d9e360;
        *t += (s32)((f32)m->s * *v);
    }
}
}  // namespace n001ec9d8

// 001ecb38 (gap, written for the unit)
namespace n001ecb38 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; u16 s; u8 flag; };
void func_001ecb38(PObj* o, M* m, PDesc* d) asm("func_001ecb38");
void func_001ecb38(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd(); r = -r;
            if (m->flag) r = (r - rnd()) * 0.5f;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        u16* t;
        if (m->k != -1) t = (u16*)((u8*)o + m->k + 160);
        else t = (u16*)D_01d9e360;
        *t += (s32)((f32)m->s * *v);
    }
}
}  // namespace n001ecb38

// 001ecc98 (gap, written for the unit)
namespace n001ecc98 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; u32 s; u8 flag; };
void func_001ecc98(PObj* o, M* m, PDesc* d) asm("func_001ecc98");
void func_001ecc98(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd();
            if (m->flag) r += rnd(); else r += r;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        s32* t;
        if (m->k != -1) t = (s32*)((u8*)o + m->k + 160);
        else t = (s32*)D_01d9e360;
        *t += (s32)((f32)m->s * *v - (f32)m->s);
    }
}
}  // namespace n001ecc98

// 001ece30 (gap, written for the unit)
namespace n001ece30 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; u32 s; u8 flag; };
void func_001ece30(PObj* o, M* m, PDesc* d) asm("func_001ece30");
void func_001ece30(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd();
            if (m->flag) r = (r + rnd()) * 0.5f;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        s32* t;
        if (m->k != -1) t = (s32*)((u8*)o + m->k + 160);
        else t = (s32*)D_01d9e360;
        *t += (s32)((f32)m->s * *v);
    }
}
}  // namespace n001ece30

// 001ecfb0 (gap, written for the unit)
namespace n001ecfb0 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
struct PObj { u32 p0, p4, p8; s32 id; };
struct PDesc { u32 p0, p4, p8; s32* off; };
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rnd(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
struct M { s32 id; s32 k; u32 s; u8 flag; };
void func_001ecfb0(PObj* o, M* m, PDesc* d) asm("func_001ecfb0");
void func_001ecfb0(PObj* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        f32* v;
        if (o->id == 0) {
            f32 r;
            r = rnd(); r = -r;
            if (m->flag) r = (r - rnd()) * 0.5f;
            v = (f32*)((u8*)o + d->off[0] + 160);
            *v = r;
        } else {
            if (m->id != o->id) return;
            v = (f32*)((u8*)o + d->off[0] + 160);
        }
        s32* t;
        if (m->k != -1) t = (s32*)((u8*)o + m->k + 160);
        else t = (s32*)D_01d9e360;
        *t += (s32)((f32)m->s * *v);
    }
}
}  // namespace n001ecfb0

// 001ed130 (was src/anon/tiny_more2.cpp)
namespace n001ed130 {
/*TARGET 001ed130*/
// 0x001e7088: definition moved into src/anon/unit_001e0cb8.cpp

f32 func_001ed130(f32 a0,f32 a1,u32 a2,u32 a3) asm("_Z13func_001ed130ffjj");
// 0x001e7088: definition moved into src/anon/unit_001e0cb8.cpp

f32 func_001ed130(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; f32 v=a0*a1; return v-a0; }
}  // namespace n001ed130

// 001ed140 (was src/anon/batch_w1570.cpp)
namespace n001ed140 {
// VU0 random float in [0,1) (the game's inline vrnext sequence).
static inline f32 vu0Rand_1ed140(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
struct A1ed140 { s32 id; s32 idx; f32 a, b, c; u8 flag; };
struct B1ed140 { u8 pad[12]; s32* off; };
f32 func_001ed130(f32, f32) asm("func_001ed130");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern f32 D_01d9e360[] asm("D_01d9e360");
/*TARGET 001ed140*/
void func_001ed140(u8* p, A1ed140* __restrict a, B1ed140* b) asm("func_001ed140");
void func_001ed140(u8* p, A1ed140* __restrict a, B1ed140* b) {
    f32* base;
    f32* d;
    if (D_01d9ea9c != 0) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (*(s32*)(p + 12) == 0) {
        f32 r = vu0Rand_1ed140();
        if (a->flag != 0) r = r + vu0Rand_1ed140();
        else r = r + r;
        base = (f32*)(p + *b->off + 160);
        *base = r;
    } else {
        if (a->id != *(s32*)(p + 12)) return;
        base = (f32*)(p + *b->off + 160);
    }
    if (a->idx != -1) d = (f32*)(p + a->idx + 160);
    else d = D_01d9e360;
    f32 t;
    t = *base; d[0] += func_001ed130(a->a, t);
    d[1] += func_001ed130(a->b, *base);
    d[2] += func_001ed130(a->c, *base);
}
}  // namespace n001ed140

// 001ed2d8 (was src/anon/tiny_more.cpp)
namespace n001ed2d8 {
/*TARGET 001ed2d8*/
// 0x001e2778: definition moved into src/anon/unit_001e0cb8.cpp

f32 func_001ed2d8(f32 a0,f32 a1,u32 a2,u32 a3) asm("_Z13func_001ed2d8ffjj");
// 0x001e2778: definition moved into src/anon/unit_001e0cb8.cpp

f32 func_001ed2d8(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return a0 * a1; }
}  // namespace n001ed2d8

// 001ed2e0 (was src/anon/batch_w1573.cpp)
namespace n001ed2e0 {
static inline f32 W1573_VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
struct W1573_RandArg { s32 id; s32 off; f32 a; f32 b; f32 c; u8 two; };
struct W1573_T1 { u8 pad[12]; s32* p; };
union W1573_FU { f32 f; s32 i; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern f32 D_01d9e360[] asm("D_01d9e360");
f32 func_001ed2d8(f32, f32) asm("func_001ed2d8");
/*TARGET 001ed2e0*/
// 0x001bcf80: definition moved into src/anon/unit_001bc568.cpp

void func_001ed2e0(u8* o, W1573_RandArg* __restrict__ s, W1573_T1* t) asm("func_001ed2e0");
// 0x001bcf80: definition moved into src/anon/unit_001bc568.cpp

void func_001ed2e0(u8* o, W1573_RandArg* __restrict__ s, W1573_T1* t)
{
    W1573_FU* pr;
    f32* d;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (*(s32*)(o + 12) == 0) {
        f32 r = W1573_VRand();
        if (s->two) r = (r + W1573_VRand()) * 0.5f;
        pr = (W1573_FU*)(o + *t->p + 160);
        pr->f = r;
    } else {
        if (s->id != *(s32*)(o + 12)) return;
        pr = (W1573_FU*)(o + *t->p + 160);
    }
    if (s->off != -1) d = (f32*)(o + s->off + 160);
    else d = D_01d9e360;
    f32 v = pr->f;
    d[0] += func_001ed2d8(s->a, v);
    d[1] += func_001ed2d8(s->b, pr->f);
    d[2] += func_001ed2d8(s->c, pr->f);
}
}  // namespace n001ed2e0

// 001ed488 (was src/anon/tiny_more.cpp)
namespace n001ed488 {
/*TARGET 001ed488*/
f32 func_001ed488(f32 a0,f32 a1,u32 a2,u32 a3) asm("_Z13func_001ed488ffjj");
f32 func_001ed488(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return a0 * a1; }
}  // namespace n001ed488

// 001ed490 (was src/anon/batch_w1573.cpp)
namespace n001ed490 {
static inline f32 W1573_VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
struct W1573_RandArg { s32 id; s32 off; f32 a; f32 b; f32 c; u8 two; };
struct W1573_T1 { u8 pad[12]; s32* p; };
union W1573_FU { f32 f; s32 i; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern f32 D_01d9e360[] asm("D_01d9e360");
f32 func_001ed488(f32, f32) asm("func_001ed488");
/*TARGET 001ed490*/
void func_001ed490(u8* o, W1573_RandArg* __restrict__ s, W1573_T1* t) asm("func_001ed490");
void func_001ed490(u8* o, W1573_RandArg* __restrict__ s, W1573_T1* t)
{
    W1573_FU* pr;
    f32* d;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (*(s32*)(o + 12) == 0) {
        f32 r = W1573_VRand();
        r = -r;
        if (s->two) r = (r - W1573_VRand()) * 0.5f;
        pr = (W1573_FU*)(o + *t->p + 160);
        pr->f = r;
    } else {
        if (s->id != *(s32*)(o + 12)) return;
        pr = (W1573_FU*)(o + *t->p + 160);
    }
    if (s->off != -1) d = (f32*)(o + s->off + 160);
    else d = D_01d9e360;
    f32 v = pr->f;
    d[0] += func_001ed488(s->a, v);
    d[1] += func_001ed488(s->b, pr->f);
    d[2] += func_001ed488(s->c, pr->f);
}
}  // namespace n001ed490

// 001ed638 (was src/anon/tiny_auto80_queue.cpp)
namespace n001ed638 {
/*TARGET 001ed638*/
s32 func_001ed638(s32 a0, f32 a1) asm("_Z13func_001ed638if");
s32 func_001ed638(s32 a0, f32 a1) {  // int_float_mul_sub
    f32 f0 = (f32)a0;
    f32 f12 = (f32)(f0 * a1);
    f12 = (f32)(f12 - f0);
    return (s32)f12;
}
}  // namespace n001ed638

// 001ed658 (was src/anon/batch_w278.cpp)
namespace n001ed658 {
#define VRAND278(out) asm volatile( \
    "addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" \
    : "=r"(out) : : "$8")
union JF278 { f32 f; s32 i; u8 c; };
struct JEnt278 { s32 id; s32 off; void* a; void* b; void* c; u8 flag; };
struct JOwn278 { u8 pad[12]; s32 id; };
struct JSt278 { u8 pad[168]; u64 bits; };
struct JRef278 { u8 pad[12]; s32* off; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern JSt278* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9e360[] asm("D_01d9e360");
s32 func_001ed638(f32, void*) asm("func_001ed638");
/*TARGET 001ed658*/
// int_float_mul_sub
void func_001ed658(u8* o, JEnt278* e, JRef278* r) asm("func_001ed658");
// int_float_mul_sub
void func_001ed658(u8* o, JEnt278* e, JRef278* r) {
    if (D_01d9ea9c) return;
    if (D_01d9e6e0->bits & 0xff0000ff00ULL) return;
    if (e->id != ((JOwn278*)o)->id) return;
    f32 f, g;
    VRAND278(f);
    if (e->flag) {
        VRAND278(g);
        f += g;
    } else {
        f += f;
    }
    JF278* pf = (JF278*)(o + *r->off + 160);
    pf->f = f;
    s32* d;
    if (e->off != -1) d = (s32*)(o + e->off + 160);
    else d = D_01d9e360;
    d[0] += func_001ed638(pf->f, e->a);  // int_float_mul_sub
    d[1] += func_001ed638(pf->f, e->b);  // int_float_mul_sub
    d[2] += func_001ed638(pf->f, e->c);  // int_float_mul_sub
}
}  // namespace n001ed658

// 001ed7d8 (was src/anon/tiny_more2.cpp)
namespace n001ed7d8 {
/*TARGET 001ed7d8*/
u32 func_001ed7d8(u32 a0,f32 a1,u32 a2,u32 a3) asm("_Z13func_001ed7d8jfjj");
u32 func_001ed7d8(u32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; f32 fv=(f32)(s32)a0; fv=fv*a1; return (u32)(s32)fv; }
}  // namespace n001ed7d8

// 001ed7f0 (was src/anon/batch_w280.cpp)
namespace n001ed7f0 {
static inline f32 VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
struct S1 { s32 id; s32 off; void* a; void* b; void* c; u8 two; };
struct T1 { u8 pad[12]; s32* p; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9e360[] asm("D_01d9e360");
union FU { f32 f; s32 i; };
s32 func_001ed7d8(void*, f32) asm("func_001ed7d8");
/*TARGET 001ed7f0*/
// int_float_mul_m1_b
void func_001ed7f0(u8* o, S1* s, T1* t) asm("func_001ed7f0");
// int_float_mul_m1_b
void func_001ed7f0(u8* o, S1* s, T1* t)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (s->id != *(s32*)(o + 12)) return;
    f32 r = VRand();
    if (s->two) r = (r + VRand()) * 0.5f;
    FU* pr = (FU*)(o + *t->p + 160);
    pr->f = r;
    s32* d;
    if (s->off != -1) d = (s32*)(o + s->off + 160);
    else d = D_01d9e360;
    f32 v = pr->f;
    d[0] += func_001ed7d8(s->a, v);  // int_float_mul_m1_b
    d[1] += func_001ed7d8(s->b, pr->f);  // int_float_mul_m1_b
    d[2] += func_001ed7d8(s->c, pr->f);  // int_float_mul_m1_b
}
}  // namespace n001ed7f0

// 001ed978 (was src/anon/tiny_more2.cpp)
namespace n001ed978 {
/*TARGET 001ed978*/
u32 func_001ed978(u32 a0,f32 a1,u32 a2,u32 a3) asm("_Z13func_001ed978jfjj");
u32 func_001ed978(u32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; f32 fv=(f32)(s32)a0; fv=fv*a1; return (u32)(s32)fv; }
}  // namespace n001ed978

// 001ed990 (was src/anon/batch_w1568.cpp)
namespace n001ed990 {
static inline f32 VRand_w1568(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
/* 001ed990 */
s32 func_001ed978(f32, s32) asm("func_001ed978");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9e360[] asm("D_01d9e360");
enum E_w1568_ed990 { E_w1568_0 = 0, E_w1568_BIG = 0x7fffffff };
struct P1_w1568_ed990 { s32 id; s32 off; E_w1568_ed990 a; E_w1568_ed990 b; E_w1568_ed990 c; u8 two; };
struct P2_w1568_ed990 { u8 pad[0xc]; s32* off; };
union U_w1568_ed990 { f32 f; s32 v[3]; };
struct Ent_w1568_ed990 { u8 pad[0xa0]; U_w1568_ed990 u; };
/*TARGET 001ed990*/
void func_001ed990(u8* obj, P1_w1568_ed990* p, P2_w1568_ed990* q) asm("func_001ed990");
void func_001ed990(u8* obj, P1_w1568_ed990* p, P2_w1568_ed990* q)
{
    if (D_01d9ea9c != 0) return;
    if (*(u64*)(D_01d9e6e0 + 0xa8) & 0xff0000ff00ULL) return;
    if (p->id != *(s32*)(obj + 0xc)) return;
    f32 r = VRand_w1568();
    r = -r;
    if (p->two) r = (r - VRand_w1568()) * 0.5f;
    Ent_w1568_ed990* t = (Ent_w1568_ed990*)(obj + *q->off);
    t->u.f = r;
    U_w1568_ed990* fp = &t->u;
    s32* d;
    d = (p->off == -1) ? D_01d9e360 : ((Ent_w1568_ed990*)(obj + p->off))->u.v;
    d[0] += func_001ed978(fp->f, p->a);
    d[1] += func_001ed978(fp->f, p->b);
    d[2] += func_001ed978(fp->f, p->c);
}
}  // namespace n001ed990

// 001edb18 (was src/anon/tiny_auto80_queue.cpp)
namespace n001edb18 {
/*TARGET 001edb18*/
s8 func_001edb18(s8 a0, f32 a1) asm("_Z13func_001edb18af");
s8 func_001edb18(s8 a0, f32 a1) {  // fix8_mul_e
    f32 f0 = (f32)a0;
    f32 f12 = (f32)(f0 * a1);
    f12 = (f32)(f12 - f0);
    s32 v0 = (s32)f12;
    return (s8)v0;
}
}  // namespace n001edb18

// 001edb48 (was src/anon/batch_w283.cpp)
namespace n001edb48 {
// VU0 random float in [0,1) (the game's inline vrnext sequence).
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
struct W283_C8 { u8 r, g, b, a; };
struct W283_Arg8 { s32 id; s32 idx; W283_C8 add; u8 flag; };
union W283_FU { f32 f; u8 c; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360[] asm("D_01d9e360");
u8 func_001edb18(s32, f32) asm("func_001edb18");
/*TARGET 001edb48*/
// fix16_mul_e
void func_001edb48(u8* a0, W283_Arg8* a1, u8* a2) asm("func_001edb48");
// fix16_mul_e
void func_001edb48(u8* a0, W283_Arg8* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    if (a1->flag != 0) f = f + vu0Rand(); else f = f + f;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W283_FU*)(p + 160))->f = f;
    f32* s2 = (f32*)(p + 160);
    s32 idx = a1->idx;
    W283_C8* s1;
    if (idx != -1) s1 = (W283_C8*)(a0 + idx + 160); else s1 = (W283_C8*)D_01d9e360;

    { f32 ff = *s2; s1->r += func_001edb18((s8)a1->add.r, ff); }
    s1->g += func_001edb18((s8)a1->add.g, *s2);  // fix8_mul_e
    s1->b += func_001edb18((s8)a1->add.b, *s2);  // fix8_mul_e
    s1->a += func_001edb18((s8)a1->add.a, *s2);  // fix8_mul_e
}
}  // namespace n001edb48

// 001edce0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001edce0 {
/*TARGET 001edce0*/
s32 func_001edce0(s32 a0, f32 a1) asm("_Z13func_001edce0if");
s32 func_001edce0(s32 a0, f32 a1) {  // fix8_mul_d
    return (s8)((s32)((f32)(s8)a0 * a1));
}
}  // namespace n001edce0

// 001edd08 (was src/anon/batch_w1572.cpp)
namespace n001edd08 {
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
struct W1572_C8 { u8 r, g, b, a; };
struct W1572_Arg8 { s32 id; s32 idx; W1572_C8 add; u8 flag; };
union W1572_FU { f32 f; u8 c; };
// 0x001d4940: definition moved into src/anon/unit_001d3c08.cpp
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360[] asm("D_01d9e360");
u8 func_001edce0(s32, f32) asm("func_001edce0");
/*TARGET 001edd08*/
void func_001edd08(u8* a0, W1572_Arg8* a1, u8* a2) asm("func_001edd08");
void func_001edd08(u8* a0, W1572_Arg8* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    if (a1->flag != 0) f = (f + vu0Rand()) * 0.5f;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1572_FU*)(p + 160))->f = f;
    f32* s2 = (f32*)(p + 160);
    s32 idx = a1->idx;
    W1572_C8* s1;
    if (idx != -1) s1 = (W1572_C8*)(a0 + idx + 160); else s1 = (W1572_C8*)D_01d9e360;

    { f32 ff = *s2; s1->r += func_001edce0((s8)a1->add.r, ff); }
    s1->g += func_001edce0((s8)a1->add.g, *s2);
    s1->b += func_001edce0((s8)a1->add.b, *s2);
    s1->a += func_001edce0((s8)a1->add.a, *s2);
}
}  // namespace n001edd08

// 001edea8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001edea8 {
/*TARGET 001edea8*/
s32 func_001edea8(s32 a0, f32 a1) asm("_Z13func_001edea8if");
s32 func_001edea8(s32 a0, f32 a1) {  // fix8_mul_c
    return (s8)((s32)((f32)(s8)a0 * a1));
}
}  // namespace n001edea8

// 001eded0 (was src/anon/batch_w1572.cpp)
namespace n001eded0 {
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
struct W1572_C8 { u8 r, g, b, a; };
struct W1572_Arg8 { s32 id; s32 idx; W1572_C8 add; u8 flag; };
union W1572_FU { f32 f; u8 c; };
// 0x001d4940: definition moved into src/anon/unit_001d3c08.cpp
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360[] asm("D_01d9e360");
u8 func_001edea8(s32, f32) asm("func_001edea8");
/*TARGET 001eded0*/
void func_001eded0(u8* a0, W1572_Arg8* a1, u8* a2) asm("func_001eded0");
void func_001eded0(u8* a0, W1572_Arg8* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    f = -f;
    if (a1->flag != 0) { f32 g = vu0Rand(); f = (f - g) * 0.5f; }
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1572_FU*)(p + 160))->f = f;
    f32* s2 = (f32*)(p + 160);
    s32 idx = a1->idx;
    W1572_C8* s1;
    if (idx != -1) s1 = (W1572_C8*)(a0 + idx + 160); else s1 = (W1572_C8*)D_01d9e360;

    { f32 ff = *s2; s1->r += func_001edea8((s8)a1->add.r, ff); }
    s1->g += func_001edea8((s8)a1->add.g, *s2);
    s1->b += func_001edea8((s8)a1->add.b, *s2);
    s1->a += func_001edea8((s8)a1->add.a, *s2);
}
}  // namespace n001eded0

// 001ee070 (was src/anon/tiny_auto80_queue.cpp)
namespace n001ee070 {
/*TARGET 001ee070*/
s32 func_001ee070(s32 a0, f32 a1) asm("_Z13func_001ee070if");
s32 func_001ee070(s32 a0, f32 a1) {  // fix16_mul_e
    f32 v = (f32)(s16)a0;
    return (s16)((s32)(v * a1 - v));
}
}  // namespace n001ee070

// 001ee0a0 (was src/anon/batch_w283.cpp)
namespace n001ee0a0 {
// VU0 random float in [0,1) (the game's inline vrnext sequence).
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
struct W283_C16 { u16 r, g, b, a; };
struct W283_Arg16 { s32 id; s32 idx; W283_C16 add; u8 flag; };
union W283_FU { f32 f; u8 c; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360[] asm("D_01d9e360");
// fix8_mul_e
u16 func_001ee070(s32, f32) asm("func_001ee070");
/*TARGET 001ee0a0*/
void func_001ee0a0(u8* a0, W283_Arg16* a1, u8* a2) asm("func_001ee0a0");
void func_001ee0a0(u8* a0, W283_Arg16* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    if (a1->flag != 0) f = f + vu0Rand(); else f = f + f;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W283_FU*)(p + 160))->f = f;
    W283_FU* s2 = (W283_FU*)(p + 160);
    s32 idx = a1->idx;
    W283_C16* s1;
    if (idx != -1) s1 = (W283_C16*)(a0 + idx + 160); else s1 = (W283_C16*)D_01d9e360;

    { f32 ff = s2->f; s1->r += func_001ee070((s16)a1->add.r, ff); }
    s1->g += func_001ee070((s16)a1->add.g, s2->f);  // fix16_mul_e
    s1->b += func_001ee070((s16)a1->add.b, s2->f);  // fix16_mul_e
    s1->a += func_001ee070((s16)a1->add.a, s2->f);  // fix16_mul_e
}
}  // namespace n001ee0a0

// 001ee238 (was src/anon/tiny_auto80_queue.cpp)
namespace n001ee238 {
/*TARGET 001ee238*/
s32 func_001ee238(s32 a0, f32 a1) asm("_Z13func_001ee238if");
s32 func_001ee238(s32 a0, f32 a1) {  // fix16_mul_d
    return (s16)((s32)((f32)(s16)a0 * a1));
}
}  // namespace n001ee238

// 001ee260 (was src/anon/batch_w1572.cpp)
namespace n001ee260 {
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
union W1572_FU { f32 f; u8 c; };
struct W1572_C16 { u16 r, g, b, a; };
struct W1572_Arg16 { s32 id; s32 idx; W1572_C16 add; u8 flag; };
// 0x001d4940: definition moved into src/anon/unit_001d3c08.cpp
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360[] asm("D_01d9e360");
u16 func_001ee238(s32, f32) asm("func_001ee238");
/*TARGET 001ee260*/
void func_001ee260(u8* a0, W1572_Arg16* a1, u8* a2) asm("func_001ee260");
void func_001ee260(u8* a0, W1572_Arg16* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    if (a1->flag != 0) f = (f + vu0Rand()) * 0.5f;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1572_FU*)(p + 160))->f = f;
    W1572_FU* s2 = (W1572_FU*)(p + 160);
    s32 idx = a1->idx;
    W1572_C16* s1;
    if (idx != -1) s1 = (W1572_C16*)(a0 + idx + 160); else s1 = (W1572_C16*)D_01d9e360;

    { f32 ff = s2->f; s1->r += func_001ee238((s16)a1->add.r, ff); }
    s1->g += func_001ee238((s16)a1->add.g, s2->f);
    s1->b += func_001ee238((s16)a1->add.b, s2->f);
    s1->a += func_001ee238((s16)a1->add.a, s2->f);
}
}  // namespace n001ee260

// 001ee400 (was src/anon/tiny_auto80_queue.cpp)
namespace n001ee400 {
/*TARGET 001ee400*/
s32 func_001ee400(s32 a0, f32 a1) asm("_Z13func_001ee400if");
s32 func_001ee400(s32 a0, f32 a1) {  // fix16_mul_c
    return (s16)((s32)((f32)(s16)a0 * a1));
}
}  // namespace n001ee400

// 001ee428 (was src/anon/batch_w1572.cpp)
namespace n001ee428 {
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
union W1572_FU { f32 f; u8 c; };
struct W1572_C16 { u16 r, g, b, a; };
struct W1572_Arg16 { s32 id; s32 idx; W1572_C16 add; u8 flag; };
// 0x001d4940: definition moved into src/anon/unit_001d3c08.cpp
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360[] asm("D_01d9e360");
u16 func_001ee400(s32, f32) asm("func_001ee400");
/*TARGET 001ee428*/
void func_001ee428(u8* a0, W1572_Arg16* a1, u8* a2) asm("func_001ee428");
void func_001ee428(u8* a0, W1572_Arg16* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    f = -f;
    if (a1->flag != 0) { f32 g = vu0Rand(); f = (f - g) * 0.5f; }
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1572_FU*)(p + 160))->f = f;
    W1572_FU* s2 = (W1572_FU*)(p + 160);
    s32 idx = a1->idx;
    W1572_C16* s1;
    if (idx != -1) s1 = (W1572_C16*)(a0 + idx + 160); else s1 = (W1572_C16*)D_01d9e360;

    { f32 ff = s2->f; s1->r += func_001ee400((s16)a1->add.r, ff); }
    s1->g += func_001ee400((s16)a1->add.g, s2->f);
    s1->b += func_001ee400((s16)a1->add.b, s2->f);
    s1->a += func_001ee400((s16)a1->add.a, s2->f);
}
}  // namespace n001ee428

// 001ee5c8 (was src/anon/tiny_more2.cpp)
namespace n001ee5c8 {
/*TARGET 001ee5c8*/
f32 func_001ee5c8(f32 a0,f32 a1,u32 a2,u32 a3) asm("_Z13func_001ee5c8ffjj");
f32 func_001ee5c8(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; f32 v=a0*a1; return v-a0; }
}  // namespace n001ee5c8

// 001ee5d8 (was src/anon/batch_w54.cpp)
namespace n001ee5d8 {
/*TARGET 001ee5d8*/
// VU0 random float in [0,1) (R register); one or two samples
f32 func_001ee5d8(u8 two) asm("func_001ee5d8");
// VU0 random float in [0,1) (R register); one or two samples
f32 func_001ee5d8(u8 two) {
    f32 r, r2;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    if (two) {
        asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                     "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                     : "=r"(r2) : : "$8");
        return r + r2;
    }
    return r + r;
}
}  // namespace n001ee5d8

// 001ee670 (was src/anon/batch_w1835.cpp)
namespace n001ee670 {
struct W1835V3 { f32 x, y, z; };
struct W1835Src { s32 id; s32 off; W1835V3 v; u8 k; };
struct W1835Idx { u8 pad[0xc]; s32* offp; };
struct W1835Obj { u8 pad[0xc]; s32 id; };
struct W1835Ctl { u8 pad[0xa8]; u64 flags; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern W1835Ctl* D_01d9e6e0 asm("D_01d9e6e0");
extern W1835V3 D_01d9e360 asm("D_01d9e360");
f32 func_001ee5d8(u8) asm("func_001ee5d8");
f32 func_001ee5c8(f32, f32) asm("func_001ee5c8");
/*TARGET 001ee670*/
void func_001ee670(W1835Obj* self, W1835Src* p, W1835Idx* q) asm("func_001ee670");
void func_001ee670(W1835Obj* self, W1835Src* p, W1835Idx* q) {
    f32* t;
    W1835V3* d;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (self->id == 0) {
        t = (f32*)((u8*)self + *q->offp + 0xa0);
        t[0] = func_001ee5d8(p->k);
        t[1] = func_001ee5d8(p->k);
        t[2] = func_001ee5d8(p->k);
    } else {
        if (p->id != self->id) return;
        t = (f32*)((u8*)self + *q->offp + 0xa0);
    }
    if (p->off != -1) d = (W1835V3*)((u8*)self + p->off + 0xa0);
    else d = &D_01d9e360;
    f32 b0 = t[0];
    d->x += func_001ee5c8(p->v.x, b0);
    d->y += func_001ee5c8(p->v.y, t[1]);
    d->z += func_001ee5c8(p->v.z, t[2]);
}
}  // namespace n001ee670

// 001ee7a0 (was src/anon/tiny_more.cpp)
namespace n001ee7a0 {
/*TARGET 001ee7a0*/
f32 func_001ee7a0(f32 a0,f32 a1,u32 a2,u32 a3) asm("_Z13func_001ee7a0ffjj");
f32 func_001ee7a0(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return a0 * a1; }
}  // namespace n001ee7a0

// 001ee7a8 (was src/anon/batch_wcx.cpp)
namespace n001ee7a8 {
static inline f32 VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
/*TARGET 001ee7a8*/
f32 func_001ee7a8(u8 two) asm("func_001ee7a8");
f32 func_001ee7a8(u8 two)
{
    f32 r = VRand();
    if (two) r = (r + VRand()) * 0.5f;
    return r;
}
}  // namespace n001ee7a8

// 001ee850 (was src/anon/batch_w1835.cpp)
namespace n001ee850 {
struct W1835V3 { f32 x, y, z; };
struct W1835Src { s32 id; s32 off; W1835V3 v; u8 k; };
struct W1835Idx { u8 pad[0xc]; s32* offp; };
struct W1835Obj { u8 pad[0xc]; s32 id; };
struct W1835Ctl { u8 pad[0xa8]; u64 flags; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern W1835Ctl* D_01d9e6e0 asm("D_01d9e6e0");
extern W1835V3 D_01d9e360 asm("D_01d9e360");
f32 func_001ee7a8(u8) asm("func_001ee7a8");
f32 func_001ee7a0(f32, f32) asm("func_001ee7a0");
/*TARGET 001ee850*/
void func_001ee850(W1835Obj* self, W1835Src* p, W1835Idx* q) asm("func_001ee850");
void func_001ee850(W1835Obj* self, W1835Src* p, W1835Idx* q) {
    f32* t;
    W1835V3* d;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (self->id == 0) {
        t = (f32*)((u8*)self + *q->offp + 0xa0);
        t[0] = func_001ee7a8(p->k);
        t[1] = func_001ee7a8(p->k);
        t[2] = func_001ee7a8(p->k);
    } else {
        if (p->id != self->id) return;
        t = (f32*)((u8*)self + *q->offp + 0xa0);
    }
    if (p->off != -1) d = (W1835V3*)((u8*)self + p->off + 0xa0);
    else d = &D_01d9e360;
    f32 b0 = t[0];
    d->x += func_001ee7a0(p->v.x, b0);
    d->y += func_001ee7a0(p->v.y, t[1]);
    d->z += func_001ee7a0(p->v.z, t[2]);
}
}  // namespace n001ee850

// 001ee980 (was src/anon/tiny_more.cpp)
namespace n001ee980 {
/*TARGET 001ee980*/
f32 func_001ee980(f32 a0,f32 a1,u32 a2,u32 a3) asm("_Z13func_001ee980ffjj");
f32 func_001ee980(f32 a0,f32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; return a0 * a1; }
}  // namespace n001ee980

// 001ee988 (was src/anon/batch_wcx.cpp)
namespace n001ee988 {
static inline f32 VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
/*TARGET 001ee988*/
f32 func_001ee988(u8 two) asm("func_001ee988");
f32 func_001ee988(u8 two)
{
    f32 r = VRand();
    r = -r;
    if (two) r = (r - VRand()) * 0.5f;
    return r;
}
}  // namespace n001ee988

// 001eea30 (was src/anon/batch_w1835.cpp)
namespace n001eea30 {
struct W1835V3 { f32 x, y, z; };
struct W1835Src { s32 id; s32 off; W1835V3 v; u8 k; };
struct W1835Idx { u8 pad[0xc]; s32* offp; };
struct W1835Obj { u8 pad[0xc]; s32 id; };
struct W1835Ctl { u8 pad[0xa8]; u64 flags; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern W1835Ctl* D_01d9e6e0 asm("D_01d9e6e0");
extern W1835V3 D_01d9e360 asm("D_01d9e360");
f32 func_001ee988(u8) asm("func_001ee988");
f32 func_001ee980(f32, f32) asm("func_001ee980");
/*TARGET 001eea30*/
void func_001eea30(W1835Obj* self, W1835Src* p, W1835Idx* q) asm("func_001eea30");
void func_001eea30(W1835Obj* self, W1835Src* p, W1835Idx* q) {
    f32* t;
    W1835V3* d;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (self->id == 0) {
        t = (f32*)((u8*)self + *q->offp + 0xa0);
        t[0] = func_001ee988(p->k);
        t[1] = func_001ee988(p->k);
        t[2] = func_001ee988(p->k);
    } else {
        if (p->id != self->id) return;
        t = (f32*)((u8*)self + *q->offp + 0xa0);
    }
    if (p->off != -1) d = (W1835V3*)((u8*)self + p->off + 0xa0);
    else d = &D_01d9e360;
    f32 b0 = t[0];
    d->x += func_001ee980(p->v.x, b0);
    d->y += func_001ee980(p->v.y, t[1]);
    d->z += func_001ee980(p->v.z, t[2]);
}
}  // namespace n001eea30

// 001eeb60 (was src/anon/tiny_auto80_queue.cpp)
namespace n001eeb60 {
/*TARGET 001eeb60*/
s32 func_001eeb60(s32 a0, f32 a1) asm("_Z13func_001eeb60if");
s32 func_001eeb60(s32 a0, f32 a1) {  // fix8_mul_sub
    f32 v = (f32)(s8)a0;
    return (s8)((s32)(v * a1 - v));
}
}  // namespace n001eeb60

// 001eeb90 (was src/anon/batch_w55.cpp)
namespace n001eeb90 {
// Random float in [0,1) from the VU0 R register.
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
/*TARGET 001eeb90*/
// Sum of two VU0 randoms, or twice one.
f32 func_001eeb90(u8 a) asm("func_001eeb90");
// Sum of two VU0 randoms, or twice one.
f32 func_001eeb90(u8 a) {
    f32 r = vu0Rand();
    if (a) return r + vu0Rand();
    return r + r;
}
}  // namespace n001eeb90

// 001eec28 (was src/anon/batch_w264.cpp)
namespace n001eec28 {
struct W264In8 { u32 id; s32 o; s8 c[4]; u8 k; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360 asm("D_01d9e360");
f32 func_001eeb90(u8) asm("func_001eeb90");
s8 func_001eeb60(s8, f32) asm("func_001eeb60");
/*TARGET 001eec28*/
// fix8_mul_sub
void func_001eec28(u8* base, const W264In8* in, u8* desc) asm("func_001eec28");
// fix8_mul_sub
void func_001eec28(u8* base, const W264In8* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001eeb90(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001eeb90(in->k);
    q[2] = func_001eeb90(in->k);
    q[3] = func_001eeb90(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s8 r = func_001eeb60(in->c[0], v);  // fix8_mul_sub
    s8 c = in->c[1];
    p[0] = r + p[0];
    r = func_001eeb60(c, q[1]);  // fix8_mul_sub
    c = in->c[2];
    p[1] = r + p[1];
    r = func_001eeb60(c, q[2]);  // fix8_mul_sub
    c = in->c[3];
    p[2] = r + p[2];
    p[3] = func_001eeb60(c, q[3]) + p[3];
}
}  // namespace n001eec28

// 001eed60 (was src/anon/tiny_auto80_queue.cpp)
namespace n001eed60 {
/*TARGET 001eed60*/
s32 func_001eed60(s32 a0, f32 a1) asm("_Z13func_001eed60if");
s32 func_001eed60(s32 a0, f32 a1) {  // fix8_mul_b
    return (s8)((s32)((f32)(s8)a0 * a1));
}
}  // namespace n001eed60

// 001eed88 (was src/anon/batch_w66.cpp)
namespace n001eed88 {
// 0x001cbc50: definition moved into src/anon/unit_001ca8e0.cpp
// ---- 001eed88
static inline f32 rnd01(void) {
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
/*TARGET 001eed88*/
f32 func_001eed88(u8 a) asm("func_001eed88");
f32 func_001eed88(u8 a) {
    f32 r = rnd01();
    if (a) r = (r + rnd01()) * 0.5f;
    return r;
}
}  // namespace n001eed88

// 001eee30 (was src/anon/batch_w264.cpp)
namespace n001eee30 {
struct W264In8 { u32 id; s32 o; s8 c[4]; u8 k; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360 asm("D_01d9e360");
f32 func_001eed88(u8) asm("func_001eed88");
s8 func_001eed60(s8, f32) asm("func_001eed60");
/*TARGET 001eee30*/
// fix8_mul_b
void func_001eee30(u8* base, const W264In8* in, u8* desc) asm("func_001eee30");
// fix8_mul_b
void func_001eee30(u8* base, const W264In8* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001eed88(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001eed88(in->k);
    q[2] = func_001eed88(in->k);
    q[3] = func_001eed88(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s8 r = func_001eed60(in->c[0], v);  // fix8_mul_b
    s8 c = in->c[1];
    p[0] = r + p[0];
    r = func_001eed60(c, q[1]);  // fix8_mul_b
    c = in->c[2];
    p[1] = r + p[1];
    r = func_001eed60(c, q[2]);  // fix8_mul_b
    c = in->c[3];
    p[2] = r + p[2];
    p[3] = func_001eed60(c, q[3]) + p[3];
}
}  // namespace n001eee30

// 001eef68 (was src/anon/tiny_auto80_queue.cpp)
namespace n001eef68 {
/*TARGET 001eef68*/
s32 func_001eef68(s32 a0, f32 a1) asm("_Z13func_001eef68if");
s32 func_001eef68(s32 a0, f32 a1) {  // fix8_mul
    return (s8)((s32)((f32)(s8)a0 * a1));
}
}  // namespace n001eef68

// 001eef90 (was src/anon/batch_w66.cpp)
namespace n001eef90 {
// 0x001cbc50: definition moved into src/anon/unit_001ca8e0.cpp
// ---- 001eed88
static inline f32 rnd01(void) {
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
/*TARGET 001eef90*/
f32 func_001eef90(u8 a) asm("func_001eef90");
f32 func_001eef90(u8 a) {
    f32 r = rnd01();
    r = -r;
    if (a) r = (r - rnd01()) * 0.5f;
    return r;
}
}  // namespace n001eef90

// 001ef038 (was src/anon/batch_w1840_nsa.cpp)
namespace n001ef038 {
// 001ef038: per-channel random colour offset (u8 channels)
struct W1840C8 { u8 r, g, b, a; };
struct W1840Arg8 { s32 id; s32 idx; W1840C8 add; u8 flag; };
union W1840FU { f32 f; u8 c; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360[] asm("D_01d9e360");
f32 func_001eef90(u8) asm("func_001eef90");
s8 func_001eef68(s32, f32) asm("func_001eef68");
/*TARGET 001ef038*/
void func_001ef038(u8* a0, W1840Arg8* a1, u8* a2) asm("func_001ef038");
void func_001ef038(u8* a0, W1840Arg8* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1840FU*)(p + 160))->f = func_001eef90(a1->flag);
    f32* s3 = (f32*)(p + 160);
    s3[1] = func_001eef90(a1->flag);
    s3[2] = func_001eef90(a1->flag);
    ((W1840FU*)&s3[3])->f = func_001eef90(a1->flag);
    s32 idx = a1->idx;
    W1840C8* s0;
    if (idx != -1) s0 = (W1840C8*)(a0 + idx + 160); else s0 = (W1840C8*)D_01d9e360;
    { f32 ff = s3[0]; s0->r += func_001eef68((s8)a1->add.r, ff); }
    s0->g += func_001eef68((s8)a1->add.g, s3[1]);
    s0->b += func_001eef68((s8)a1->add.b, s3[2]);
    s0->a += func_001eef68((s8)a1->add.a, s3[3]);
}
}  // namespace n001ef038

// 001ef170 (was src/anon/tiny_auto80_queue.cpp)
namespace n001ef170 {
/*TARGET 001ef170*/
s32 func_001ef170(s32 a0, f32 a1) asm("_Z13func_001ef170if");
s32 func_001ef170(s32 a0, f32 a1) {  // fix16_mul_sub
    f32 v = (f32)(s16)a0;
    return (s16)((s32)(v * a1 - v));
}
}  // namespace n001ef170

// 001ef1a0 (was src/anon/batch_w56.cpp)
namespace n001ef1a0 {
// 0x001d77a0: definition moved into src/anon/unit_001d7458.cpp

// 001ef1a0: VU0 random number(s)
static inline f32 vu0_rand(void)
{
    f32 x;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(x) : : "$8");
    return x;
}
/*TARGET 001ef1a0*/
f32 func_001ef1a0(u8 a) asm("func_001ef1a0");
f32 func_001ef1a0(u8 a)
{
    f32 x = vu0_rand();
    if (a) return x + vu0_rand();
    return x + x;
}
}  // namespace n001ef1a0

// 001ef238 (was src/anon/batch_w264.cpp)
namespace n001ef238 {
union W264H { u16 h; u8 b; };
struct W264In16 { u32 id; s32 o; s16 c[4]; u8 k; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360 asm("D_01d9e360");
f32 func_001ef1a0(u8) asm("func_001ef1a0");
s16 func_001ef170(s16, f32) asm("func_001ef170");
/*TARGET 001ef238*/
// fix16_mul_sub
void func_001ef238(u8* base, const W264In16* in, u8* desc) asm("func_001ef238");
// fix16_mul_sub
void func_001ef238(u8* base, const W264In16* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001ef1a0(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001ef1a0(in->k);
    q[2] = func_001ef1a0(in->k);
    q[3] = func_001ef1a0(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s16 r = func_001ef170(in->c[0], v);  // fix16_mul_sub
    s16 c = in->c[1];
    ((W264H*)p)[0].h = r + ((W264H*)p)[0].h;
    r = func_001ef170(c, q[1]);  // fix16_mul_sub
    c = in->c[2];
    ((W264H*)p)[1].h = r + ((W264H*)p)[1].h;
    r = func_001ef170(c, q[2]);  // fix16_mul_sub
    c = in->c[3];
    ((W264H*)p)[2].h = r + ((W264H*)p)[2].h;
    ((W264H*)p)[3].h = func_001ef170(c, q[3]) + ((W264H*)p)[3].h;
}
}  // namespace n001ef238

// 001ef370 (was src/anon/tiny_auto80_queue.cpp)
namespace n001ef370 {
/*TARGET 001ef370*/
s32 func_001ef370(s32 a0, f32 a1) asm("_Z13func_001ef370if");
s32 func_001ef370(s32 a0, f32 a1) {  // fix16_mul_b
    return (s8)((s32)((f32)(s16)a0 * a1));
}
}  // namespace n001ef370

// 001ef398 (was src/anon/batch_w67.cpp)
namespace n001ef398 {
// Random float in [0,1) from the VU0 R register.
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
/*TARGET 001ef398*/
// 001ef398: random float, averaged with a second one when asked
f32 func_001ef398(u8 a) asm("func_001ef398");
// 001ef398: random float, averaged with a second one when asked
f32 func_001ef398(u8 a)
{
    f32 x = vu0Rand();
    if (a) x = (x + vu0Rand()) * 0.5f;
    return x;
}
}  // namespace n001ef398

// 001ef440 (was src/anon/batch_w264.cpp)
namespace n001ef440 {
union W264H { u16 h; u8 b; };
struct W264In16 { u32 id; s32 o; s16 c[4]; u8 k; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360 asm("D_01d9e360");
f32 func_001ef398(u8) asm("func_001ef398");
s8 func_001ef370(s16, f32) asm("func_001ef370");
/*TARGET 001ef440*/
// fix16_mul_b
void func_001ef440(u8* base, const W264In16* in, u8* desc) asm("func_001ef440");
// fix16_mul_b
void func_001ef440(u8* base, const W264In16* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001ef398(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001ef398(in->k);
    q[2] = func_001ef398(in->k);
    q[3] = func_001ef398(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s8 r = func_001ef370(in->c[0], v);  // fix16_mul_b
    s16 c = in->c[1];
    ((W264H*)p)[0].h = r + ((W264H*)p)[0].h;
    r = func_001ef370(c, q[1]);  // fix16_mul_b
    c = in->c[2];
    ((W264H*)p)[1].h = r + ((W264H*)p)[1].h;
    r = func_001ef370(c, q[2]);  // fix16_mul_b
    c = in->c[3];
    ((W264H*)p)[2].h = r + ((W264H*)p)[2].h;
    ((W264H*)p)[3].h = func_001ef370(c, q[3]) + ((W264H*)p)[3].h;
}
}  // namespace n001ef440

// 001ef578 (was src/anon/tiny_auto80_queue.cpp)
namespace n001ef578 {
/*TARGET 001ef578*/
s32 func_001ef578(s32 a0, f32 a1) asm("_Z13func_001ef578if");
s32 func_001ef578(s32 a0, f32 a1) {  // fix16_mul
    return (s8)((s32)((f32)(s16)a0 * a1));
}
}  // namespace n001ef578

// 001ef5a0 (was src/anon/batch_w67.cpp)
namespace n001ef5a0 {
// Random float in [0,1) from the VU0 R register.
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
/*TARGET 001ef5a0*/
// 001ef5a0: negative random float, averaged with a second one when asked
f32 func_001ef5a0(u8 a) asm("func_001ef5a0");
// 001ef5a0: negative random float, averaged with a second one when asked
f32 func_001ef5a0(u8 a)
{
    f32 x = vu0Rand();
    x = -x;
    if (a) x = (x - vu0Rand()) * 0.5f;
    return x;
}
}  // namespace n001ef5a0

// 001ef648 (was src/anon/batch_w264.cpp)
namespace n001ef648 {
union W264H { u16 h; u8 b; };
struct W264In16 { u32 id; s32 o; s16 c[4]; u8 k; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e360 asm("D_01d9e360");
f32 func_001ef5a0(u8) asm("func_001ef5a0");
s8 func_001ef578(s16, f32) asm("func_001ef578");
/*TARGET 001ef648*/
// fix16_mul
void func_001ef648(u8* base, const W264In16* in, u8* desc) asm("func_001ef648");
// fix16_mul
void func_001ef648(u8* base, const W264In16* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001ef5a0(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001ef5a0(in->k);
    q[2] = func_001ef5a0(in->k);
    q[3] = func_001ef5a0(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s8 r = func_001ef578(in->c[0], v);  // fix16_mul
    s16 c = in->c[1];
    ((W264H*)p)[0].h = r + ((W264H*)p)[0].h;
    r = func_001ef578(c, q[1]);  // fix16_mul
    c = in->c[2];
    ((W264H*)p)[1].h = r + ((W264H*)p)[1].h;
    r = func_001ef578(c, q[2]);  // fix16_mul
    c = in->c[3];
    ((W264H*)p)[2].h = r + ((W264H*)p)[2].h;
    ((W264H*)p)[3].h = func_001ef578(c, q[3]) + ((W264H*)p)[3].h;
}
}  // namespace n001ef648

