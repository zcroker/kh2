// Linked unit 0x0014b838-0x0014c7f0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int W1820u128 __attribute__((mode(TI)));
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../harata/libdk/timer.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/clock.hpp"

// 0014b838 (was src/anon/batch_wcx.cpp)
namespace n0014b838 {
#define GS_SET_RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define GS_SET_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
struct Spr { u8 pad[4]; u16 w, h; s16 x, y; u32 z; u8 r, g, b, a; u8 pad2[180]; u64 rgbaq; u8 pad3[8]; u64 xyz0; u8 pad4[8]; u64 xyz1; u8 pad5[16]; u8 next[4]; };
void func_0014d8d0(u8*) asm("func_0014d8d0");
/*TARGET 0014b838*/
void func_0014b838(Spr* p) asm("func_0014b838");
void func_0014b838(Spr* p)
{
    p->rgbaq = GS_SET_RGBAQ(p->r, p->g, p->b, p->a, 1);
    p->xyz0 = GS_SET_XYZ(p->x * 16 + 0x7000, p->y * 16 + 0x7300, p->z);
    p->xyz1 = GS_SET_XYZ((p->x + p->w) * 16 + 0x7000, (p->y + p->h) * 16 + 0x7300, p->z);
    func_0014d8d0(p->next);
}
}  // namespace n0014b838

// 0014b8f0 (was gap)
namespace n0014b8f0 {
// twin of 0x14b920 (GS packet header)
void gap_0014b8f0(u64* p) asm("gap_0014b8f0");
void gap_0014b8f0(u64* p) {
    p[0] = 0x1000000000008001ULL;
    p[1] = 14;
    p[2] = 0x19f000001ff0000ULL;
    p[3] = 64;
}
}  // namespace n0014b8f0

// 0014b920 (was src/anon/batch_wcx2.cpp)
namespace n0014b920 {
/*TARGET 0014b920*/
void func_0014b920(u64* p) asm("func_0014b920");
void func_0014b920(u64* p) {
    p[0] = 0x1000000000008001ULL;
    p[1] = 14;
    p[2] = 0x19f000001ff0000ULL;
    p[3] = 64;
}
}  // namespace n0014b920

// 0014b950 (was src/anon/batch_w30.cpp)
namespace n0014b950 {
/*TARGET 0014b950*/
// 0x00143348: definition moved into src/anon/unit_00142c90.cpp

// GS SCISSOR register value from x/y/w/h.
void func_0014b950(u8* p, s16 x, s16 y, u16 w, u16 h) asm("func_0014b950");
// 0x00143348: definition moved into src/anon/unit_00142c90.cpp

// GS SCISSOR register value from x/y/w/h.
void func_0014b950(u8* p, s16 x, s16 y, u16 w, u16 h) {
    *(u64*)(p + 16) = (u64)x | ((u64)(x + w - 1) << 16) | ((u64)y << 32) | ((u64)(y + h - 1) << 48);
}
}  // namespace n0014b950

// 0014b9a8 (was src/anon/batch_w1764_nsa.cpp)
namespace n0014b9a8 {
struct W1764Pkt { u32 a, b; u128* p; };
void func_001b7e68(W1764Pkt*, s32) asm("func_001b7e68");
void func_001b80d8(W1764Pkt*) asm("func_001b80d8");
void func_001b7f30(W1764Pkt*) asm("func_001b7f30");
/*TARGET 0014b9a8*/
void func_0014b9a8(u128* src) asm("func_0014b9a8");
void func_0014b9a8(u128* src) {
    W1764Pkt pk;
    s32 i;
    pk.p = 0; pk.b = 0; pk.a = 0;
    func_001b7e68(&pk, 32);
    W1764Pkt* q = &pk;
    for (i = 1; i >= 0; i--) {
        *q->p = *src++;
        q->p++;
    }
    func_001b80d8(&pk);
    func_001b7f30(&pk);
}
}  // namespace n0014b9a8

// 0014ba20 (was src/anon/batch_w39.cpp)
namespace n0014ba20 {
// 0010ab08: moved to src/anon/unit_0010a918.cpp

// --- 0014ba20
// Constructor: base ctor, vtable, then two GS register packets.
extern u64 D_0036b0d8 asm("D_0036b0d8");
extern void* D_00349da8[] asm("D_00349da8");
void func_0014b290(u8*) asm("func_0014b290");
/*TARGET 0014ba20*/
void func_0014ba20(u8* p) asm("func_0014ba20");
void func_0014ba20(u8* p) {
    func_0014b290(p);
    u64 d = D_0036b0d8;
    *(void**)p = D_00349da8;
    *(u64*)(p + 288) = 0x1000000000008001ULL;
    *(u64*)(p + 296) = 14;
    *(u64*)(p + 304) = d;
    *(u64*)(p + 312) = 64;
    *(u64*)(p + 256) = 0x1000000000008001ULL;
    *(u64*)(p + 264) = 14;
    *(u64*)(p + 272) = d;
    *(u64*)(p + 280) = 64;
}
}  // namespace n0014ba20

// 0014ba90 (was src/anon/batch_w40.cpp)
namespace n0014ba90 {
// 00103480: moved to src/common/unit_001031b0.cpp

void func_0014b290(u8*) asm("func_0014b290");
extern void* D_00349da8[] asm("D_00349da8");
extern u64 D_0036b0e0 asm("D_0036b0e0");
/*TARGET 0014ba90*/
// Constructor: two GIF-tag style 4-qword blocks at +0x100.
void func_0014ba90(u8* p) asm("func_0014ba90");
// Constructor: two GIF-tag style 4-qword blocks at +0x100.
void func_0014ba90(u8* p) {
    func_0014b290(p);
    u64 d = D_0036b0e0;
    *(void**)p = D_00349da8;
    *(u64*)(p + 288) = 0x1000000000008001ULL;
    *(u64*)(p + 296) = 14;
    *(u64*)(p + 304) = d;
    *(u64*)(p + 312) = 64;
    *(u64*)(p + 256) = 0x1000000000008001ULL;
    *(u64*)(p + 264) = 14;
    *(u64*)(p + 272) = d;
    *(u64*)(p + 280) = 64;
}
}  // namespace n0014ba90

// 0014bb00 (was src/anon/auto200_999.cpp)
namespace n0014bb00 {
/*TARGET 0014bb00*/
// 0014b220: moved to src/anon/unit_0014b150.cpp

// 0014b220: moved to src/anon/unit_0014b150.cpp

// set the rectangle at +320 (x, y, w, h)
struct Rect0014bb00 { u8 pad[320]; s16 x, y; u16 w, h; };
void func_0014bb00(Rect0014bb00* r, s16 x, s16 y, u16 w, u16 h) asm("_Z13func_0014bb00jjjjj");
void func_0014bb00(Rect0014bb00* r, s16 x, s16 y, u16 w, u16 h) {
    r->x = x;
    r->y = y;
    r->w = w;
    r->h = h;
}
}  // namespace n0014bb00

// 0014bb30 (was src/anon/batch_w2038_nsa.cpp)
namespace n0014bb30 {
struct BPkt { u32 a, b; u128* p; };
struct BObj {
    u8 pad0[4];
    u16 w, h;
    s16 x, y;
    u32 z;
    u8 r, g, b, a;
    u8 pad14[0xc];
    u128 q20[13];
    u8 padf0[0x10];
    u128 q100[2];
    u128 q120[2];
    s16 sx, sy;
    u16 sw, sh;
};
void func_001b7e68(BPkt*, s32) asm("func_001b7e68");
void func_001b80d8(BPkt*) asm("func_001b80d8");
void func_001b7f30(BPkt*) asm("func_001b7f30");
/*TARGET 0014bb30*/
void func_0014bb30(BObj* o) asm("func_0014bb30");
void func_0014bb30(BObj* o) {
    BPkt k1, k2, k3;
    s32 i;
    *(u64*)((u8*)o + 0x110) = (u64)(s16)o->sx | ((u64)(o->sx + o->sw - 1) << 16) | ((u64)o->sy << 32) | ((u64)(o->sy + o->sh - 1) << 48);
    *(u64*)((u8*)o + 0xc8) = (u64)o->r | ((u64)o->g << 8) | ((u64)o->b << 16) | ((u64)o->a << 24) | (1ULL << 32);
    u64 z = (u64)o->z << 32;
    *(u64*)((u8*)o + 0xd8) = (u64)(o->x * 16 + 0x7000) | ((u64)(o->y * 16 + 0x7300) << 16) | z;
    *(u64*)((u8*)o + 0xe8) = (u64)((o->x + o->w) * 16 + 0x7000) | ((u64)((o->y + o->h) * 16 + 0x7300) << 16) | z;
    {
        k1.p = 0; k1.b = 0; k1.a = 0;
        func_001b7e68(&k1, 32);
        BPkt* q = &k1;
        u128* s = o->q100;
        s32 j;
        for (j = 1; j >= 0; j--) {
            *q->p = *s++;
            q->p++;
        }
        func_001b80d8(&k1);
    }
    {
        k2.p = 0; k2.b = 0; k2.a = 0;
        func_001b7e68(&k2, 0xd0);
        BPkt* q = &k2;
        u128* s = o->q20;
        for (i = 12; i >= 0; i--) {
            *q->p = *s++;
            q->p++;
        }
        func_001b80d8(&k2);
    }
    {
        k3.p = 0; k3.b = 0; k3.a = 0;
        func_001b7e68(&k3, 32);
        BPkt* q = &k3;
        u128* s = o->q120;
        s32 j;
        for (j = 1; j >= 0; j--) {
            *q->p = *s++;
            q->p++;
        }
        func_001b80d8(&k3);
    }
    func_001b7f30(&k3);
    func_001b7f30(&k2);
    func_001b7f30(&k1);
}
}  // namespace n0014bb30

// 0014bd50 (was src/anon/batch_w1640.cpp)
namespace n0014bd50 {
void func_0014b290(u8*) asm("func_0014b290");
struct W1640ParamEnt { u16 type; u8 pad; u8 flag; void* ptr; u32 p8, pc; };
struct W1640ParamObj { void* vt; u8 pad[28]; u8 data[224]; W1640ParamEnt e[33]; };
extern void* D_00349d90[] asm("D_00349d90");
extern u8 D_00349b50[] asm("D_00349b50");
extern u8 D_00349b70[] asm("D_00349b70");
extern u8 D_00349b90[] asm("D_00349b90");
extern u8 D_00349bb0[] asm("D_00349bb0");
extern u8 D_00349bd0[] asm("D_00349bd0");
extern u8 D_00349bf0[] asm("D_00349bf0");
extern u8 D_00349c10[] asm("D_00349c10");
extern u8 D_00349c30[] asm("D_00349c30");
extern u8 D_00349c50[] asm("D_00349c50");
extern u8 D_00349c70[] asm("D_00349c70");
extern u8 D_00349c90[] asm("D_00349c90");
extern u8 D_00349cb0[] asm("D_00349cb0");
extern u8 D_00349cd0[] asm("D_00349cd0");
extern u8 D_00349cf0[] asm("D_00349cf0");
extern u8 D_00349d10[] asm("D_00349d10");
extern u8 D_00349d30[] asm("D_00349d30");
extern u8 D_00349d50[] asm("D_00349d50");
static inline void W1640_SetEnt(W1640ParamEnt* e, u8 f, void* q) { e->flag = f; e->ptr = q; }
void func_0014bd50(W1640ParamObj* p) asm("func_0014bd50");
/*TARGET 0014bd50*/
// constructor (second copy, same vtable as func_0014c050): fills a 33-entry parameter table
void func_0014bd50(W1640ParamObj* p) asm("func_0014bd50");
// constructor (second copy, same vtable as func_0014c050): fills a 33-entry parameter table
void func_0014bd50(W1640ParamObj* p) {
    func_0014b290((u8*)p);
    p->vt = D_00349d90;
    W1640_SetEnt(&p->e[0], 48, D_00349b50); p->e[0].type = 2;
    W1640_SetEnt(&p->e[1], 48, &p->pad[28]); p->e[1].type = 13;
    W1640_SetEnt(&p->e[2], 48, D_00349b70); p->e[2].type = 2;
    W1640_SetEnt(&p->e[3], 48, &p->pad[28]); p->e[3].type = 13;
    W1640_SetEnt(&p->e[4], 48, D_00349b90); p->e[4].type = 2;
    W1640_SetEnt(&p->e[5], 48, &p->pad[28]); p->e[5].type = 13;
    W1640_SetEnt(&p->e[6], 48, D_00349bb0); p->e[6].type = 2;
    W1640_SetEnt(&p->e[7], 48, &p->pad[28]); p->e[7].type = 13;
    W1640_SetEnt(&p->e[8], 48, D_00349bd0); p->e[8].type = 2;
    W1640_SetEnt(&p->e[9], 48, &p->pad[28]); p->e[9].type = 13;
    W1640_SetEnt(&p->e[10], 48, D_00349bf0); p->e[10].type = 2;
    W1640_SetEnt(&p->e[11], 48, &p->pad[28]); p->e[11].type = 13;
    W1640_SetEnt(&p->e[12], 48, D_00349c10); p->e[12].type = 2;
    W1640_SetEnt(&p->e[13], 48, &p->pad[28]); p->e[13].type = 13;
    W1640_SetEnt(&p->e[14], 48, D_00349c30); p->e[14].type = 2;
    W1640_SetEnt(&p->e[15], 48, &p->pad[28]); p->e[15].type = 13;
    W1640_SetEnt(&p->e[16], 48, D_00349c50); p->e[16].type = 2;
    W1640_SetEnt(&p->e[17], 48, &p->pad[28]); p->e[17].type = 13;
    W1640_SetEnt(&p->e[18], 48, D_00349c70); p->e[18].type = 2;
    W1640_SetEnt(&p->e[19], 48, &p->pad[28]); p->e[19].type = 13;
    W1640_SetEnt(&p->e[20], 48, D_00349c90); p->e[20].type = 2;
    W1640_SetEnt(&p->e[21], 48, &p->pad[28]); p->e[21].type = 13;
    W1640_SetEnt(&p->e[22], 48, D_00349cb0); p->e[22].type = 2;
    W1640_SetEnt(&p->e[23], 48, &p->pad[28]); p->e[23].type = 13;
    W1640_SetEnt(&p->e[24], 48, D_00349cd0); p->e[24].type = 2;
    W1640_SetEnt(&p->e[25], 48, &p->pad[28]); p->e[25].type = 13;
    W1640_SetEnt(&p->e[26], 48, D_00349cf0); p->e[26].type = 2;
    W1640_SetEnt(&p->e[27], 48, &p->pad[28]); p->e[27].type = 13;
    W1640_SetEnt(&p->e[28], 48, D_00349d10); p->e[28].type = 2;
    W1640_SetEnt(&p->e[29], 48, &p->pad[28]); p->e[29].type = 13;
    W1640_SetEnt(&p->e[30], 48, D_00349d30); p->e[30].type = 2;
    W1640_SetEnt(&p->e[31], 48, &p->pad[28]); p->e[31].type = 13;
    W1640_SetEnt(&p->e[32], 0, D_00349d50); p->e[32].type = 2;
}
}  // namespace n0014bd50

// 0014c050 (was src/anon/batch_w118.cpp)
namespace n0014c050 {
void func_0014b290(u8*) asm("func_0014b290");
struct ParamEnt { u16 type; u8 pad; u8 flag; void* ptr; u32 p8, pc; };
struct ParamObj { void* vt; u8 pad[28]; u8 data[224]; ParamEnt e[33]; };
extern void* D_00349d90[] asm("D_00349d90");
extern u8 D_00349b50[] asm("D_00349b50");
extern u8 D_00349b70[] asm("D_00349b70");
extern u8 D_00349b90[] asm("D_00349b90");
extern u8 D_00349bb0[] asm("D_00349bb0");
extern u8 D_00349bd0[] asm("D_00349bd0");
extern u8 D_00349bf0[] asm("D_00349bf0");
extern u8 D_00349c10[] asm("D_00349c10");
extern u8 D_00349c30[] asm("D_00349c30");
extern u8 D_00349c50[] asm("D_00349c50");
extern u8 D_00349c70[] asm("D_00349c70");
extern u8 D_00349c90[] asm("D_00349c90");
extern u8 D_00349cb0[] asm("D_00349cb0");
extern u8 D_00349cd0[] asm("D_00349cd0");
extern u8 D_00349cf0[] asm("D_00349cf0");
extern u8 D_00349d10[] asm("D_00349d10");
extern u8 D_00349d30[] asm("D_00349d30");
extern u8 D_00349d50[] asm("D_00349d50");
static inline void setEnt(ParamEnt* e, u8 f, void* q) { e->flag = f; e->ptr = q; }
void func_0014c050(ParamObj* p) asm("func_0014c050");
/*TARGET 0014c050*/
// constructor filling a 33-entry parameter table
void func_0014c050(ParamObj* p) asm("func_0014c050");
// constructor filling a 33-entry parameter table
void func_0014c050(ParamObj* p) {
    func_0014b290((u8*)p);
    p->vt = D_00349d90;
    setEnt(&p->e[0], 48, D_00349b50); p->e[0].type = 2;
    setEnt(&p->e[1], 48, &p->pad[28]); p->e[1].type = 13;
    setEnt(&p->e[2], 48, D_00349b70); p->e[2].type = 2;
    setEnt(&p->e[3], 48, &p->pad[28]); p->e[3].type = 13;
    setEnt(&p->e[4], 48, D_00349b90); p->e[4].type = 2;
    setEnt(&p->e[5], 48, &p->pad[28]); p->e[5].type = 13;
    setEnt(&p->e[6], 48, D_00349bb0); p->e[6].type = 2;
    setEnt(&p->e[7], 48, &p->pad[28]); p->e[7].type = 13;
    setEnt(&p->e[8], 48, D_00349bd0); p->e[8].type = 2;
    setEnt(&p->e[9], 48, &p->pad[28]); p->e[9].type = 13;
    setEnt(&p->e[10], 48, D_00349bf0); p->e[10].type = 2;
    setEnt(&p->e[11], 48, &p->pad[28]); p->e[11].type = 13;
    setEnt(&p->e[12], 48, D_00349c10); p->e[12].type = 2;
    setEnt(&p->e[13], 48, &p->pad[28]); p->e[13].type = 13;
    setEnt(&p->e[14], 48, D_00349c30); p->e[14].type = 2;
    setEnt(&p->e[15], 48, &p->pad[28]); p->e[15].type = 13;
    setEnt(&p->e[16], 48, D_00349c50); p->e[16].type = 2;
    setEnt(&p->e[17], 48, &p->pad[28]); p->e[17].type = 13;
    setEnt(&p->e[18], 48, D_00349c70); p->e[18].type = 2;
    setEnt(&p->e[19], 48, &p->pad[28]); p->e[19].type = 13;
    setEnt(&p->e[20], 48, D_00349c90); p->e[20].type = 2;
    setEnt(&p->e[21], 48, &p->pad[28]); p->e[21].type = 13;
    setEnt(&p->e[22], 48, D_00349cb0); p->e[22].type = 2;
    setEnt(&p->e[23], 48, &p->pad[28]); p->e[23].type = 13;
    setEnt(&p->e[24], 48, D_00349cd0); p->e[24].type = 2;
    setEnt(&p->e[25], 48, &p->pad[28]); p->e[25].type = 13;
    setEnt(&p->e[26], 48, D_00349cf0); p->e[26].type = 2;
    setEnt(&p->e[27], 48, &p->pad[28]); p->e[27].type = 13;
    setEnt(&p->e[28], 48, D_00349d10); p->e[28].type = 2;
    setEnt(&p->e[29], 48, &p->pad[28]); p->e[29].type = 13;
    setEnt(&p->e[30], 48, D_00349d30); p->e[30].type = 2;
    setEnt(&p->e[31], 48, &p->pad[28]); p->e[31].type = 13;
    setEnt(&p->e[32], 0, D_00349d50); p->e[32].type = 2;
}
}  // namespace n0014c050

// 0014c350 (was src/anon/batch_wcx.cpp)
namespace n0014c350 {
#define GS_SET_RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define GS_SET_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
struct Spr { u8 pad[4]; u16 w, h; s16 x, y; u32 z; u8 r, g, b, a; u8 pad2[180]; u64 rgbaq; u8 pad3[8]; u64 xyz0; u8 pad4[8]; u64 xyz1; u8 pad5[16]; u8 next[4]; };
void func_0014d8d0(u8*) asm("func_0014d8d0");
/*TARGET 0014c350*/
void func_0014c350(Spr* p) asm("func_0014c350");
void func_0014c350(Spr* p)
{
    p->rgbaq = GS_SET_RGBAQ(p->r, p->g, p->b, p->a, 1);
    p->xyz0 = GS_SET_XYZ(p->x * 16 + 0x7000, p->y * 16 + 0x7300, p->z);
    p->xyz1 = GS_SET_XYZ((p->x + p->w) * 16 + 0x7000, (p->y + p->h) * 16 + 0x7300, p->z);
    func_0014d8d0(p->next);
}
}  // namespace n0014c350

// 0014c408 (was gap)
namespace n0014c408 {
void func_0014b290(u8*) asm("func_0014b290");
// twin of 0x14c5a0: constructor filling a 17-entry parameter table
struct ParamEnt { u16 type; u8 pad; u8 flag; void* ptr; u32 p8, pc; };
struct ParamObj { void* vt; u8 pad[28]; u8 data[224]; ParamEnt e[17]; };
extern void* D_00349d78[] asm("D_00349d78");
extern u8 D_00349b50[] asm("D_00349b50");
extern u8 D_00349b70[] asm("D_00349b70");
extern u8 D_00349b90[] asm("D_00349b90");
extern u8 D_00349bb0[] asm("D_00349bb0");
extern u8 D_00349bd0[] asm("D_00349bd0");
extern u8 D_00349bf0[] asm("D_00349bf0");
extern u8 D_00349c10[] asm("D_00349c10");
extern u8 D_00349c30[] asm("D_00349c30");
extern u8 D_00349d50[] asm("D_00349d50");
static inline void setEnt(ParamEnt* e, u8 f, void* q) { e->flag = f; e->ptr = q; }
void gap_0014c408(ParamObj* p) asm("gap_0014c408");
void gap_0014c408(ParamObj* p) {
    func_0014b290((u8*)p);
    p->vt = D_00349d78;
    setEnt(&p->e[0], 48, D_00349b50); p->e[0].type = 2;
    setEnt(&p->e[1], 48, &p->pad[28]); p->e[1].type = 13;
    setEnt(&p->e[2], 48, D_00349b70); p->e[2].type = 2;
    setEnt(&p->e[3], 48, &p->pad[28]); p->e[3].type = 13;
    setEnt(&p->e[4], 48, D_00349b90); p->e[4].type = 2;
    setEnt(&p->e[5], 48, &p->pad[28]); p->e[5].type = 13;
    setEnt(&p->e[6], 48, D_00349bb0); p->e[6].type = 2;
    setEnt(&p->e[7], 48, &p->pad[28]); p->e[7].type = 13;
    setEnt(&p->e[8], 48, D_00349bd0); p->e[8].type = 2;
    setEnt(&p->e[9], 48, &p->pad[28]); p->e[9].type = 13;
    setEnt(&p->e[10], 48, D_00349bf0); p->e[10].type = 2;
    setEnt(&p->e[11], 48, &p->pad[28]); p->e[11].type = 13;
    setEnt(&p->e[12], 48, D_00349c10); p->e[12].type = 2;
    setEnt(&p->e[13], 48, &p->pad[28]); p->e[13].type = 13;
    setEnt(&p->e[14], 48, D_00349c30); p->e[14].type = 2;
    setEnt(&p->e[15], 48, &p->pad[28]); p->e[15].type = 13;
    setEnt(&p->e[16], 0, D_00349d50); p->e[16].type = 2;
}
}  // namespace n0014c408

// 0014c5a0 (was src/anon/batch_w114.cpp)
namespace n0014c5a0 {
void func_0014b290(u8*) asm("func_0014b290");
// ---- 0014c5a0: constructor filling a 17-entry parameter table
struct ParamEnt { u16 type; u8 pad; u8 flag; void* ptr; u32 p8, pc; };
struct ParamObj { void* vt; u8 pad[28]; u8 data[224]; ParamEnt e[17]; };
extern void* D_00349d78[] asm("D_00349d78");
extern u8 D_00349b50[] asm("D_00349b50");
extern u8 D_00349b70[] asm("D_00349b70");
extern u8 D_00349b90[] asm("D_00349b90");
extern u8 D_00349bb0[] asm("D_00349bb0");
extern u8 D_00349bd0[] asm("D_00349bd0");
extern u8 D_00349bf0[] asm("D_00349bf0");
extern u8 D_00349c10[] asm("D_00349c10");
extern u8 D_00349c30[] asm("D_00349c30");
extern u8 D_00349d50[] asm("D_00349d50");
static inline void setEnt(ParamEnt* e, u8 f, void* q) { e->flag = f; e->ptr = q; }
void func_0014c5a0(ParamObj* p) asm("func_0014c5a0");
/*TARGET 0014c5a0*/
void func_0014c5a0(ParamObj* p) asm("func_0014c5a0");
void func_0014c5a0(ParamObj* p) {
    func_0014b290((u8*)p);
    p->vt = D_00349d78;
    setEnt(&p->e[0], 48, D_00349b50); p->e[0].type = 2;
    setEnt(&p->e[1], 48, &p->pad[28]); p->e[1].type = 13;
    setEnt(&p->e[2], 48, D_00349b70); p->e[2].type = 2;
    setEnt(&p->e[3], 48, &p->pad[28]); p->e[3].type = 13;
    setEnt(&p->e[4], 48, D_00349b90); p->e[4].type = 2;
    setEnt(&p->e[5], 48, &p->pad[28]); p->e[5].type = 13;
    setEnt(&p->e[6], 48, D_00349bb0); p->e[6].type = 2;
    setEnt(&p->e[7], 48, &p->pad[28]); p->e[7].type = 13;
    setEnt(&p->e[8], 48, D_00349bd0); p->e[8].type = 2;
    setEnt(&p->e[9], 48, &p->pad[28]); p->e[9].type = 13;
    setEnt(&p->e[10], 48, D_00349bf0); p->e[10].type = 2;
    setEnt(&p->e[11], 48, &p->pad[28]); p->e[11].type = 13;
    setEnt(&p->e[12], 48, D_00349c10); p->e[12].type = 2;
    setEnt(&p->e[13], 48, &p->pad[28]); p->e[13].type = 13;
    setEnt(&p->e[14], 48, D_00349c30); p->e[14].type = 2;
    setEnt(&p->e[15], 48, &p->pad[28]); p->e[15].type = 13;
    setEnt(&p->e[16], 0, D_00349d50); p->e[16].type = 2;
}
}  // namespace n0014c5a0

// 0014c738 (was src/anon/batch_wcx.cpp)
namespace n0014c738 {
#define GS_SET_RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define GS_SET_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
struct Spr { u8 pad[4]; u16 w, h; s16 x, y; u32 z; u8 r, g, b, a; u8 pad2[180]; u64 rgbaq; u8 pad3[8]; u64 xyz0; u8 pad4[8]; u64 xyz1; u8 pad5[16]; u8 next[4]; };
void func_0014d8d0(u8*) asm("func_0014d8d0");
/*TARGET 0014c738*/
void func_0014c738(Spr* p) asm("func_0014c738");
void func_0014c738(Spr* p)
{
    p->rgbaq = GS_SET_RGBAQ(p->r, p->g, p->b, p->a, 1);
    p->xyz0 = GS_SET_XYZ(p->x * 16 + 0x7000, p->y * 16 + 0x7300, p->z);
    p->xyz1 = GS_SET_XYZ((p->x + p->w) * 16 + 0x7000, (p->y + p->h) * 16 + 0x7300, p->z);
    func_0014d8d0(p->next);
}
}  // namespace n0014c738

