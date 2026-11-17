// Linked unit 0x00237068-0x00237d38: YI::SPRITE (gap functions written here).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 00237068 (was src/anon/batch_w247.cpp)
namespace n00237068 {
extern u8 D_0035eae8 asm("D_0035eae8");
struct Sub6_247 { u32 a, b, c, d, e, f; };
struct Obj237 {
    u32 vt; u32 f4, f8, f12;
    u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1;
    u32 f20, f24, f28, f32, f36, f40, f44, f48, f52, f56, f60, f64, f68, f72, f76;
    Sub6_247 s;
    u32 g[14];
};
/*TARGET 00237068*/
// Constructor: vtable, clear every field and seven flag bits.
void func_00237068(Obj237* o) asm("func_00237068");
// Constructor: vtable, clear every field and seven flag bits.
void func_00237068(Obj237* o)
{
    o->s.a = 0;
    o->vt = (u32)&D_0035eae8;
    Sub6_247* s = &o->s;
    s->b = 0; s->c = 0; s->d = 0; s->e = 0; s->f = 0;
    o->f4 = 0; o->f8 = 0; o->f12 = 0;
    o->b0 = 0; o->b1 = 0; o->b2 = 0; o->b3 = 0; o->b4 = 0; o->b5 = 0; o->b6 = 0;
    o->f20 = 0; o->f24 = 0; o->f28 = 0; o->f32 = 0; o->f36 = 0; o->f40 = 0; o->f44 = 0;
    o->f52 = 0; o->f56 = 0; o->f60 = 0; o->f64 = 0; o->f68 = 0; o->f72 = 0; o->f76 = 0;
    o->g[0] = 0; o->g[1] = 0; o->g[2] = 0; o->g[3] = 0; o->g[4] = 0; o->g[5] = 0; o->g[6] = 0; o->g[7] = 0;
    o->g[8] = 0; o->g[9] = 0; o->g[10] = 0; o->g[11] = 0; o->g[12] = 0; o->g[13] = 0;
}
}  // namespace n00237068

// 00237150 (was gap)
namespace n00237150 {
extern u8 D_0035eae8 asm("D_0035eae8");
struct Sub6_247 { u32 a, b, c, d, e, f; };
struct Obj237 {
    u32 vt; u32 f4, f8, f12;
    u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1;
    u32 f20, f24, f28, f32, f36, f40, f44, f48, f52, f56, f60, f64, f68, f72, f76;
    Sub6_247 s;
    u32 g[14];
};
// C1 copy of the constructor at 0x237068.
void func_00237150(Obj237* o) asm("func_00237150");
void func_00237150(Obj237* o)
{
    o->s.a = 0;
    o->vt = (u32)&D_0035eae8;
    Sub6_247* s = &o->s;
    s->b = 0; s->c = 0; s->d = 0; s->e = 0; s->f = 0;
    o->f4 = 0; o->f8 = 0; o->f12 = 0;
    o->b0 = 0; o->b1 = 0; o->b2 = 0; o->b3 = 0; o->b4 = 0; o->b5 = 0; o->b6 = 0;
    o->f20 = 0; o->f24 = 0; o->f28 = 0; o->f32 = 0; o->f36 = 0; o->f40 = 0; o->f44 = 0;
    o->f52 = 0; o->f56 = 0; o->f60 = 0; o->f64 = 0; o->f68 = 0; o->f72 = 0; o->f76 = 0;
    o->g[0] = 0; o->g[1] = 0; o->g[2] = 0; o->g[3] = 0; o->g[4] = 0; o->g[5] = 0; o->g[6] = 0; o->g[7] = 0;
    o->g[8] = 0; o->g[9] = 0; o->g[10] = 0; o->g[11] = 0; o->g[12] = 0; o->g[13] = 0;
}
}  // namespace n00237150

// 00237238 (was src/anon/tiny.cpp)
namespace n00237238 {
extern u32 D_0035eae8 asm("D_0035eae8");
/*TARGET 00237238*/
void func_00237238(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00237238jjjj");
void func_00237238(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_0035eae8;
}
}  // namespace n00237238

// 00237248 (was gap)
namespace n00237248 {
extern u32 D_0035eae8 asm("D_0035eae8");
void func_00237248(u32 a0) asm("func_00237248");
void func_00237248(u32 a0) {
    *(u32*)((u32)a0 + (0)) = (u32)&D_0035eae8;
}
}  // namespace n00237248

// 00237258 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n00237258 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_0035eae8 asm("D_0035eae8");
/*TARGET 00237258*/
u32 func_00237258(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00237258jjjjjjjj");
u32 func_00237258(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0035eae8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n00237258

// 00237278 (was src/anon/misc_2.cpp)
namespace n00237278 {
/*TARGET 00237278*/
void func_00237278(void* self) asm("_Z13func_00237278Pv");
void func_00237278(void* self) {}
}  // namespace n00237278

// 00237280 (was src/anon/batch_w1822_nsa.cpp)
namespace n00237280 {
// 00237280
struct W22Hdr { s32 f0, f4, n8, oc, n10, o14, n18, o1c; };
struct W22Obj {
    s32 f0; void* p4; void* p8; void* pc;
    u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, rest:26;
    s32 f14, f18; u8 pad1c[0x34 - 0x1c];
    s32 n34, n38, n3c, f40; f32 f44; s32 f48; u8 pad4c[0x68 - 0x4c]; s32 f68;
    u8 pad6c[0x88 - 0x6c]; u32 f88; s32 f8c, f90, f94, f98;
};
// 0x0018ad18: definition moved into src/yasui/libys/npc.cpp

void func_002373a8(W22Obj*) asm("func_002373a8");
void func_00237680(W22Obj*, s32) asm("func_00237680");
void func_00237740(W22Obj*, f32, f32, f32) asm("func_00237740");
void func_00237a68(W22Obj*, f32, f32, f32) asm("func_00237a68");
void func_00237ad8(W22Obj*, s32) asm("func_00237ad8");
/*TARGET 00237280*/
s32 func_00237280(W22Obj* o, W22Hdr* h, s32 a) asm("func_00237280");
s32 func_00237280(W22Obj* o, W22Hdr* h, s32 a)
{
    f32 one = 1.0f;
    o->p4 = (u8*)h + h->oc;
    o->p8 = (u8*)h + h->o14;
    o->pc = (u8*)h + h->o1c;
    o->n34 = h->n8;
    o->n38 = h->n10;
    o->n3c = h->n18;
    o->f68 = -1;
    o->b0 = 1; o->b1 = 1; o->b2 = 1;
    o->b3 = 0; o->b4 = 0; o->b5 = 0;
    o->f40 = a;
    o->f44 = one;
    o->f48 = 0;
    o->f14 = 0;
    o->f18 = 0;
    func_002373a8(o);
    func_00237680(o, 0);
    func_00237740(o, 0.0f, 0.0f, 0.0f);
    func_00237a68(o, one, one, one);
    o->f8c = 0;
    o->f90 = 0;
    o->f88 = 0x80808080;
    o->f94 = 0;
    o->f98 = 0;
    func_00237ad8(o, 0);
    return 1;
}
}  // namespace n00237280

// 00237398 (was gap)
namespace n00237398 {
u32 func_00237398(u8* p) asm("func_00237398");
u32 func_00237398(u8* p) { return *(u32*)(p + 80) < 2; }
}  // namespace n00237398

// 002373a8 (was src/anon/tiny.cpp)
namespace n002373a8 {
/*TARGET 002373a8*/
// 0x00232100: definition moved into src/anon/unit_00231500.cpp

void func_002373a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002373a8jjjj");
// 0x00232100: definition moved into src/anon/unit_00231500.cpp

void func_002373a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (80)) = 0;
}
}  // namespace n002373a8

// 002373b0 (was gap)
namespace n002373b0 {
u32 func_002373b0(u8* p) asm("func_002373b0");
u32 func_002373b0(u8* p) { return (u32)(*(s32*)(p + 80) - 2) < 2; }
void func_002373c0(u8* p, s32 a, s32 b) asm("func_002373c0");
void func_002373c0(u8* p, s32 a, s32 b) {
    *(s32*)(p + 80) = 2;
    *(s32*)(p + 96) = a;
    *(s32*)(p + 100) = b;
}
u32 func_002373d8(u8* p) asm("func_002373d8");
u32 func_002373d8(u8* p) { return (u32)(*(s32*)(p + 80) - 4) < 2; }
void func_002373e8(u8* p, s32 a, s32 b) asm("func_002373e8");
void func_002373e8(u8* p, s32 a, s32 b) {
    *(s32*)(p + 80) = 4;
    *(s32*)(p + 96) = a;
    *(s32*)(p + 100) = b;
}
u32 func_00237400(u8* p) asm("func_00237400");
u32 func_00237400(u8* p) { return (u32)(*(s32*)(p + 80) - 6) < 2; }
void func_00237410(u8* p, s32 a, s32 b) asm("func_00237410");
void func_00237410(u8* p, s32 a, s32 b) {
    *(s32*)(p + 80) = 6;
    *(s32*)(p + 96) = a;
    *(s32*)(p + 100) = b;
}
struct E237 { s32 a, b, c, d, e; };
struct T237 { u32 pad[2]; E237* ent; u16* idx; };
s32 func_00237428(T237* t, s32 i, s32 j) asm("func_00237428");
s32 func_00237428(T237* t, s32 i, s32 j) {
    return t->ent[t->idx[i * 2] + j].a;
}
}  // namespace n002373b0

// 00237458 (was src/anon/batch_w14.cpp)
namespace n00237458 {
/*TARGET 00237458*/
void func_00237458(u8* p, u32 i, s32 j, s32 v) asm("func_00237458");
void func_00237458(u8* p, u32 i, s32 j, s32 v) {  // entry20_accumulate
    u8* t = *(u8**)(p + 12);
    s32* e = (s32*)(*(u8**)(p + 8) + (*(u16*)(i * 4 + (u32)t) + j) * 20);
    e[2] = v + e[2] - e[0];
    e[0] = v;
}
}  // namespace n00237458

// 00237498 (was gap)
namespace n00237498 {
struct E237 { s32 a, b, c, d, e; };
struct T237 { u32 pad[2]; E237* ent; u16* idx; };
s32 func_00237498(T237* t, s32 i, s32 j) asm("func_00237498");
s32 func_00237498(T237* t, s32 i, s32 j) {
    return t->ent[t->idx[i * 2] + j].b;
}
}  // namespace n00237498

// 002374c8 (was src/anon/batch_w15.cpp)
namespace n002374c8 {
// 0x002346f0: definition moved into src/anon/unit_002335e8.cpp

struct Ent20 { u32 _0; u32 b; u32 _8; u32 c; u32 _10; };
struct Tbl { u32 _0; u32 _4; Ent20* ents; u32* idx; };
/*TARGET 002374c8*/
void func_002374c8(Tbl* t, int i, int j, u32 v) asm("func_002374c8");
void func_002374c8(Tbl* t, int i, int j, u32 v) {  // entry20_accumulate_b
    Ent20* e = &t->ents[*(u16*)&t->idx[i] + j];
    e->c = v + e->c - e->b;
    e->b = v;
}
}  // namespace n002374c8

// 00237508 (was src/anon/batch_w22.cpp)
namespace n00237508 {
// 0022be28: moved to src/sasa/event_countdown.cpp (linked unit)

// --- 00237508
struct E237 { s32 a, b, c, d, e; };
struct T237 { u32 pad[2]; E237* ent; u16* idx; };
/*TARGET 00237508*/
s32 func_00237508(T237* t, s32 i, s32 j) asm("func_00237508");
s32 func_00237508(T237* t, s32 i, s32 j) {  // entry20_field8_minus0
    E237* e = &t->ent[t->idx[i * 2] + j];
    return e->c - e->a;
}
}  // namespace n00237508

// 00237540 (was src/anon/batch_w23.cpp)
namespace n00237540 {
// 0x00227cd8: definition moved into src/anon/unit_00224780.cpp

struct E20 { s32 a; s32 pad; s32 c; u8 pad2[8]; };
struct I4 { u16 idx; u16 pad; };
struct T237 { u32 pad[2]; E20* e; I4* ix; };
/*TARGET 00237540*/
void func_00237540(T237* t, s32 i, s32 off, s32 add) asm("func_00237540");
void func_00237540(T237* t, s32 i, s32 off, s32 add) {
    E20* e = &t->e[t->ix[i].idx + off];
    e->c = e->a + add;
}
}  // namespace n00237540

// 00237578 (was src/anon/batch_w11.cpp)
namespace n00237578 {
// 0x002314c0: definition moved into src/anon/unit_002302c0.cpp

struct E237 { u32 a; s32 lo; u32 b; s32 hi; u32 c; };
struct P237 { u32 pad[2]; E237* e; u16* idx; };
/*TARGET 00237578*/
s32 func_00237578(P237* p, s32 i, s32 j) asm("func_00237578");
s32 func_00237578(P237* p, s32 i, s32 j) {  // entry20_field12_minus4
    E237* e = &p->e[p->idx[i * 2] + j];
    return e->hi - e->lo;
}
}  // namespace n00237578

// 002375b0 (was src/anon/batch_w12.cpp)
namespace n002375b0 {
/*TARGET 002375b0*/
// 0x00232110: definition moved into src/anon/unit_00231500.cpp

void func_002375b0(u8* o, s32 i, s32 j, s32 d) asm("func_002375b0");
// 0x00232110: definition moved into src/anon/unit_00231500.cpp

void func_002375b0(u8* o, s32 i, s32 j, s32 d) {
    u8* e = *(u8**)(o + 8) + (*(u16*)(*(u8**)(o + 12) + i * 4) + j) * 20;
    *(s32*)(e + 12) = *(s32*)(e + 4) + d;
}
}  // namespace n002375b0

// 002375e8 (was gap)
namespace n002375e8 {
struct E237 { s32 a, b, c, d, e; };
struct T237 { u32 pad[2]; E237* ent; u16* idx; };
void func_002375e8(T237* t, s32 i, s32 j, s32 x, s32 y) asm("func_002375e8");
void func_002375e8(T237* t, s32 i, s32 j, s32 x, s32 y) {
    E237* e = &t->ent[t->idx[i * 2] + j];
    e->c = x + e->c - e->a;
    e->d = y + e->d - e->b;
    e->a = x;
    e->b = y;
}
}  // namespace n002375e8

// 00237640 (was src/anon/batch_w16.cpp)
namespace n00237640 {
// 0x0022e160: definition moved into src/anon/unit_0022d358.cpp

// Offsets a 20-byte point: out = pos + (dx, dy).
struct Ent20 {
    s32 x, y;
    s32 ox, oy;
    u32 pad;
};
struct IdxEnt {
    u16 base;
    u16 pad;
};
/*TARGET 00237640*/
void func_00237640(u8* p, s32 i, s32 j, s32 dx, s32 dy) asm("func_00237640");
void func_00237640(u8* p, s32 i, s32 j, s32 dx, s32 dy) {
    Ent20* e = *(Ent20**)(p + 8) + ((*(IdxEnt**)(p + 12))[i].base + j);
    e->ox = e->x + dx;
    e->oy = e->y + dy;
}
}  // namespace n00237640

// 00237680 (was src/anon/batch_w1725.cpp)
namespace n00237680 {
void func_00237698(void* p) asm("func_00237698");
/*TARGET 00237680*/
void func_00237680(void* p) asm("func_00237680");
void func_00237680(void* p) { func_00237698(p); }
}  // namespace n00237680

// 00237698 (was src/anon/batch_w2029_nsa.cpp)
namespace n00237698 {
struct W2029_O68 { u8 p0[8]; u8* f8; u16* fc; u8 p10[4]; u8* f14; u32 f18; u8 p1c[0x4c]; s32 f68; };
/*TARGET 00237698*/
void func_00237698(W2029_O68* o, s32 n) asm("func_00237698");
void func_00237698(W2029_O68* o, s32 n) {
    if (o->f68 != n) {
        u16* e = o->fc + n * 2;
        o->f68 = n;
        o->f14 = o->f8 + e[0] * 0x14;
        o->f18 = e[1];
    }
}
}  // namespace n00237698

// 002376d8 (was src/anon/batch_w209.cpp)
namespace n002376d8 {
union E209 { struct { u16 a, b; } s; u32 u; u8 c; };
/*TARGET 002376d8*/
// --- 002376d8
void func_002376d8(u8* a, s32 b) asm("func_002376d8");
// --- 002376d8
void func_002376d8(u8* a, s32 b) {
    if (b < *(s32*)(a + 0x3c)) {
        E209* t = *(E209**)(a + 12) + b;
        *(s32*)(a + 0x68) = b;
        *(u32*)(a + 0x14) = *(u32*)(a + 8) + t->s.a * 20;
        *(u32*)(a + 0x18) = t->s.b;
    }
}
}  // namespace n002376d8

// 00237720 (was gap)
namespace n00237720 {
void func_00237720(u8* p, f32* x, f32* y, f32* z) asm("func_00237720");
void func_00237720(u8* p, f32* x, f32* y, f32* z) {
    *x = *(f32*)(p + 112);
    *y = *(f32*)(p + 116);
    *z = *(f32*)(p + 120);
}
}  // namespace n00237720

// 00237740 (was src/anon/batch_w85.cpp)
namespace n00237740 {
// 0x0022f5e8: definition moved into src/anon/unit_0022d358.cpp

f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
struct Rot237 { u8 p0[28]; f32 m28, m32, m36, m40; u8 p44[68]; f32 x, y, z; };
/*TARGET 00237740*/
// sets euler angles and rebuilds the matrix rows that depend on them
void func_00237740(Rot237* r, f32 x, f32 y, f32 z) asm("func_00237740");
// sets euler angles and rebuilds the matrix rows that depend on them
void func_00237740(Rot237* r, f32 x, f32 y, f32 z) {
    f32 sx, cx, sy, cy, sz, cz, sxsy;
    r->y = y;
    r->z = z;
    r->x = x;
    sx = sinf(r->x);
    cx = cosf(r->x);
    sy = sinf(r->y);
    cy = cosf(r->y);
    sz = sinf(r->z);
    cz = cosf(r->z);
    sxsy = sx * sy;
    r->m28 = cy * cz;
    r->m36 = sxsy * cz + cx * sz;
    r->m32 = cy * -sz;
    r->m40 = sxsy * -sz + cx * cz;
}
}  // namespace n00237740

// 00237808 (was src/anon/batch_w80.cpp)
namespace n00237808 {
// ---- unit 8 (g.cpp)
struct U8_Rot3 { u8 pad[28]; f32 m00, m01, m02, m03; u8 pad2[112 - 44]; f32 rx, ry, rz; };
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
/*TARGET 00237808*/
// 0x002328c0: definition moved into src/anon/unit_00231500.cpp


void func_00237808(U8_Rot3* o, f32 rx) asm("func_00237808");
// 0x002328c0: definition moved into src/anon/unit_00231500.cpp


void func_00237808(U8_Rot3* o, f32 rx) {
    f32 sx, cx, sy, cy, sz, cz, sxsy;
    o->rx = rx;
    sx = sinf(o->rx);
    cx = cosf(o->rx);
    sy = sinf(o->ry);
    cy = cosf(o->ry);
    sz = sinf(o->rz);
    cz = cosf(o->rz);
    sxsy = sx * sy;
    o->m00 = cy * cz;
    o->m02 = sxsy * cz + cx * sz;
    o->m01 = cy * -sz;
    o->m03 = sxsy * -sz + cx * cz;
}
}  // namespace n00237808

// 002378c8 (was src/anon/batch_w87.cpp)
namespace n002378c8 {
// 0x00222080: definition moved into src/anon/unit_00221e28.cpp

// ---- 0x2378c8: rotation matrix rows from Euler angles at +112 ----
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
/*TARGET 002378c8*/
void func_002378c8(f32* p, f32 z) asm("func_002378c8");
void func_002378c8(f32* p, f32 z) {
    p[29] = z;
    f32 sx = sinf(p[28]);
    f32 cx = cosf(p[28]);
    f32 sy = sinf(p[29]);
    f32 cy = cosf(p[29]);
    f32 sz = sinf(p[30]);
    f32 cz = cosf(p[30]);
    p[7] = cy * cz;
    p[9] = sx * sy * cz + cx * sz;
    p[8] = cy * -sz;
    p[10] = sx * sy * -sz + cx * cz;
}
}  // namespace n002378c8

// 00237988 (was src/anon/batch_w88.cpp)
namespace n00237988 {
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
/*TARGET 00237988*/
// 0x00233490: definition moved into src/anon/unit_00232f08.cpp

void func_00237988(u8* p, f32 z) asm("func_00237988");
// 0x00233490: definition moved into src/anon/unit_00232f08.cpp

void func_00237988(u8* p, f32 z) {
    *(f32*)(p + 120) = z;
    f32 a = sinf(*(f32*)(p + 112));
    f32 b = cosf(*(f32*)(p + 112));
    f32 c = sinf(*(f32*)(p + 116));
    f32 d = cosf(*(f32*)(p + 116));
    f32 e = sinf(*(f32*)(p + 120));
    f32 f = cosf(*(f32*)(p + 120));
    f32 ac = a * c;
    *(f32*)(p + 28) = d * f;
    *(f32*)(p + 32) = d * -e;
    *(f32*)(p + 36) = ac * f + b * e;
    *(f32*)(p + 40) = ac * -e + b * f;
}
}  // namespace n00237988

// 00237a48 (was gap)
namespace n00237a48 {
void func_00237a48(u8* p, f32* x, f32* y, f32* z) asm("func_00237a48");
void func_00237a48(u8* p, f32* x, f32* y, f32* z) {
    *x = *(f32*)(p + 124);
    *y = *(f32*)(p + 128);
    *z = *(f32*)(p + 132);
}
}  // namespace n00237a48

// 00237a68 (was src/anon/tiny_auto80_queue.cpp)
namespace n00237a68 {
/*TARGET 00237a68*/
void func_00237a68(u8* a0, f32 a1, f32 a2, f32 a3) asm("_Z13func_00237a68Phfff");
void func_00237a68(u8* a0, f32 a1, f32 a2, f32 a3) {  // set_float124_128
    f32 f0 = a1 * a2;
    *(f32*)(a0 + 124) = a1;
    *(f32*)(a0 + 128) = a2;
    *(f32*)(a0 + 132) = a3;
    a1 = a1 * a3;
    *(f32*)(a0 + 44) = f0;
    *(f32*)(a0 + 48) = a1;
}
}  // namespace n00237a68

// 00237a88 (was gap)
namespace n00237a88 {
void func_00237a88(u8* p, f32 x) asm("func_00237a88");
void func_00237a88(u8* p, f32 x) {
    *(f32*)(p + 124) = x;
    *(f32*)(p + 44) = x * *(f32*)(p + 128);
    *(f32*)(p + 48) = x * *(f32*)(p + 132);
}
void func_00237aa8(u8* p, f32 y) asm("func_00237aa8");
void func_00237aa8(u8* p, f32 y) {
    *(f32*)(p + 128) = y;
    *(f32*)(p + 44) = *(f32*)(p + 124) * y;
}
void func_00237ac0(u8* p, f32 z) asm("func_00237ac0");
void func_00237ac0(u8* p, f32 z) {
    *(f32*)(p + 132) = z;
    *(f32*)(p + 48) = *(f32*)(p + 124) * z;
}
}  // namespace n00237a88

// 00237ad8 (was src/anon/tiny.cpp)
namespace n00237ad8 {
/*TARGET 00237ad8*/
// 0x002347e8: definition moved into src/anon/unit_002335e8.cpp

void func_00237ad8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00237ad8jjjj");
// 0x002347e8: definition moved into src/anon/unit_002335e8.cpp

void func_00237ad8(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)a0 + (156)) = (u32)a1;
}
}  // namespace n00237ad8

// 00237ae0 (was gap)
namespace n00237ae0 {
void func_00237ae0(void* p) asm("func_00237ae0");
void func_00237ae0(void* p) {}
}  // namespace n00237ae0

// 00237ae8 (was src/anon/batch_wcx2.cpp)
namespace n00237ae8 {
// --------------------
// Fade controller: advance the timer for the current fade state and update the output level.
struct Fade237ae8 {
    u8 pad[68]; f32 speed; f32 time; u8 pad76[4]; s32 state; f32 t; f32 dur; f32 wait;
    s32 dur_init; s32 wait_init; u8 pad104[4]; f32 out;
};
extern f32 D_00349e14 asm("D_00349e14");
f32 sinf(f32 x) asm("sinf");
/*TARGET 00237ae8*/
void func_00237ae8(Fade237ae8* p) asm("func_00237ae8");
void func_00237ae8(Fade237ae8* p)
{
    f32 dt = D_00349e14 * p->speed;
    p->time += dt;
    switch (p->state) {
    case 0:
        p->state = 1;
        p->out = 1.0f;
        break;
    case 1:
        break;
    case 2:
        p->state = 3;
        if (p->dur_init != -1) {
            p->t = 0.0f;
            p->dur = p->dur_init;
            p->out = 1.0f;
        }
        if (p->wait_init != -1) p->wait = p->wait_init;
    case 3:
        if (0.0f < p->wait) {
            p->wait -= dt;
            break;
        }
        p->t += dt;
        if (p->dur < p->t) {
            p->t = p->dur;
            p->state = 1;
        }
        p->out = (p->dur - p->t) / p->dur;
        break;
    case 4:
        p->state = 5;
        if (p->dur_init != -1) {
            p->t = 0.0f;
            p->dur = p->dur_init;
            p->out = 0.0f;
        }
        if (p->wait_init != -1) p->wait = p->wait_init;
    case 5:
        if (0.0f < p->wait) {
            p->wait -= dt;
            break;
        }
        p->t += dt;
        if (p->dur < p->t) {
            p->t = p->dur;
            p->state = 1;
        }
        p->out = p->t / p->dur;
        break;
    case 6:
        p->state = 7;
        if (p->dur_init != -1) {
            p->t = 0.0f;
            p->dur = p->dur_init;
            p->out = 1.0f;
        }
        if (p->wait_init != -1) p->wait = p->wait_init;
    case 7:
        if (0.0f < p->wait) {
            p->wait -= dt;
            break;
        }
        p->t += dt;
        if (p->dur < p->t) p->t = 0.0f;
        p->out = sinf(p->t / p->dur * 3.14159274f);
        break;
    }
}
}  // namespace n00237ae8

