// Linked unit 0x001fb350-0x001fc720 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>

// 001fb350 (was gap)
namespace n001fb350 {
void func_001fa610(u8*, u8*, u8*) asm("func_001fa610");
void func_001fb350(u8* a0, u8* a1, u8* a2) asm("func_001fb350");
void func_001fb350(u8* a0, u8* a1, u8* a2) {
    func_001fa610(a0, a1, a2);
    u8* q = a0 + **(s32**)(a2 + 12) + 160;
    if (*(u32*)a1 == *(u32*)(a0 + 12)) {
        q[192] = a1[14] << 3;
        q[193] = a1[15] << 2;
        q[141] = a1[16];
    }
}
}  // namespace n001fb350

// 001fb3c8 (was src/anon/batch_w1786_nsa.cpp)
namespace n001fb3c8 {
struct W1786Vn { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1786A1fb { u8 pad[0xc]; s32* p; };
// 0x001adc48: definition moved into src/anon/unit_001ada38.cpp

void func_001fa668(u8*, s32, void*) asm("func_001fa668");
void W1786_wtarget(W1786Vn*, void*, W1786Vn*) asm("_Z17sceVu0ApplyMatrixjjjj");
void sceVu0ScaleVector(void*, W1786Vn*, f32) asm("sceVu0ScaleVector");
void func_001faea8(void*, s32, s32) asm("func_001faea8");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
/*TARGET 001fb3c8*/
void func_001fb3c8(u8* a0, s32 a1, W1786A1fb* a2) asm("func_001fb3c8");
void func_001fb3c8(u8* a0, s32 a1, W1786A1fb* a2) {
    func_001fa668(a0, a1, a2);
    u8* base = a0 + *a2->p;
    u8* pb = base + 0x150;
    u8* pa = base + 0xa0;
    W1786Vn v;
    f32 one = 1.0f;
    v.x = 0; v.y = 0; v.z = 0; v.w = one;
    W1786_wtarget(&v, D_01d9e6e8 + 0x50, &v);
    sceVu0ScaleVector(pb, &v, one / v.w);
    func_001faea8(pa, 0, 0);
}
}  // namespace n001fb3c8

// 001fb478 (was src/anon/batch_w1761_nsa.cpp)
namespace n001fb478 {
// Built with -fno-strict-aliasing (_nsa): 001fb478 and 002e9850 reload a global after stores of other types.

struct W1761S1 { u8 pad[0x8c]; u8 b8c; u8 b8d; u8 p2[0x9c - 0x8e]; s32 w9c; u8 p3[8]; s32 wa8; u8 p4[0xc0 - 0xac]; u8 bc0; u8 bc1; };
void func_0021f5d8(void*) asm("func_0021f5d8");
extern u8 D_003590b0 asm("D_003590b0");
/*TARGET 001fb478*/
void func_001fb478(char* a0, s32** a1) asm("func_001fb478");
void func_001fb478(char* a0, s32** a1) {
    W1761S1* p = (W1761S1*)(a0 + *a1[3] + 0xa0);
    func_0021f5d8(p);
    p->w9c = 0;
    p->wa8 = 0;
    p->b8c = D_003590b0;
    p->b8d = 2;
    p->bc0 = 0;
    p->bc1 = 0;
    D_003590b0++;
}
}  // namespace n001fb478

// 001fb4e0 (was gap)
namespace n001fb4e0 {
void func_001fb4e0(u8* a0, u8* t) asm("func_001fb4e0");
void func_001fb4e0(u8* a0, u8* t) {
    u8* q = a0 + **(s32**)(t + 12) + 160;
    *(s32*)(q + 156) = 0;
    *(s32*)(q + 168) = 0;
}
}  // namespace n001fb4e0

// 001fb500 (was gap)
namespace n001fb500 {
void func_001fb500(void) asm("func_001fb500");
void func_001fb500(void) {}
}  // namespace n001fb500

// 001fb508 (was src/anon/batch_w1746_nsa.cpp)
namespace n001fb508 {
struct W1746CallArg { void* obj; u32 v4; void* tbl; f32 f; void* sub; };
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void func_0021fa28(W1746CallArg*, s32) asm("func_0021fa28");
/*TARGET 001fb508*/
void func_001fb508(u8* o) asm("func_001fb508");
void func_001fb508(u8* o) {
    W1746CallArg a;
    a.obj = o;
    a.v4 = *(u32*)(o + 36);
    a.tbl = D_01d9e8c0;
    a.f = *(f32*)(o + 32);
    a.sub = o + 16;
    func_0021fa28(&a, 0);
}
}  // namespace n001fb508

// 001fb558 (was src/anon/auto80_199_queue.cpp)
namespace n001fb558 {
void func_001fa7b0(u32 a0, u32 a1, u32 a2) asm("_Z13func_001fa7b0jjj");
/*TARGET 001fb558*/
// 0x001facf8: definition moved into src/anon/unit_001fa1b8.cpp

void func_001fb558(u32 a0, u32 a1, u32 a2) asm("_Z13func_001fb558jjj");
// 0x001facf8: definition moved into src/anon/unit_001fa1b8.cpp

void func_001fb558(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 0);
    u32 t7p = a0 + t7;
    u32 s2 = t7p + 160;
    func_001fa7b0(s0, s1, a2);

    u32 t6b = *(u32*)(s0 + 12);
    u32 t7b = *(u32*)(s1 + 0);
    if (t7b != t6b) {
        return;
    }
    f32 f0 = *(f32*)(s1 + 12);
    *(f32*)(s2 + 32) = f0;
}
}  // namespace n001fb558

// 001fb5b8 (was src/anon/batch_w90.cpp)
namespace n001fb5b8 {
// 0x001e2130: definition moved into src/anon/unit_001e0cb8.cpp

// 001fb5b8: scale an RGBA byte colour by the global colour multipliers.
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
// memcpy16
void func_001fb508(void*, s32, s32) asm("func_001fb508");
extern u8 D_00354be0[] asm("D_00354be0");
/*TARGET 001fb5b8*/
void func_001fb5b8(u8* base, u8* c, u8* a2) asm("func_001fb5b8");
void func_001fb5b8(u8* base, u8* c, u8* a2)
{
    base += **(u32**)(a2 + 12);
    u8* p = base + 160;
    p[36] = (s32)(c[8] * *(f32*)(D_01d9e6e0 + 48));
    p[37] = (s32)(c[9] * *(f32*)(D_01d9e6e0 + 52));
    p[38] = (s32)(c[10] * *(f32*)(D_01d9e6e0 + 56));
    p[39] = (s32)(c[11] * *(f32*)(D_01d9e6e0 + 60));
    sceVu0CopyVector(base + 176, D_00354be0);  // memcpy16
    func_001fb508(p, 0, 0);
}
}  // namespace n001fb5b8

// 001fb698 (was src/anon/batch_w2.cpp)
namespace n001fb698 {
struct OffsetHolder { u32 pad[3]; u32* offsets; };
void func_0021fbc0(u32) asm("func_0021fbc0");
/*TARGET 001fb698*/
// 0x001d2648: definition moved into src/anon/unit_001d14e0.cpp

void func_001fb698(u32 base, OffsetHolder* h) asm("func_001fb698");
// 0x001d2648: definition moved into src/anon/unit_001d14e0.cpp

void func_001fb698(u32 base, OffsetHolder* h) {
    func_0021fbc0(base + *h->offsets + 160);
}
}  // namespace n001fb698

// 001fb6c0 (was gap)
namespace n001fb6c0 {
void func_001fb6c0(void) asm("func_001fb6c0");
void func_001fb6c0(void) {}
}  // namespace n001fb6c0

// 001fb6c8 (was src/anon/batch_w1753_nsa.cpp)
namespace n001fb6c8 {
struct W1753Obj { u8 pad[48]; u8 m30[16]; f32 f40; f32 f44; u32 w48; };
struct W1753Rec { u32 p; u32 v; void* fn; f32 b; f32 a; void* q; };
void func_0021f620(W1753Rec*, u32) asm("func_0021f620");
extern u8 D_01d9e8c0 asm("D_01d9e8c0");
/*TARGET 001fb6c8*/
// Needs -fno-strict-aliasing for the original store order.
void func_001fb6c8(W1753Obj* o) asm("func_001fb6c8");
// Needs -fno-strict-aliasing for the original store order.
void func_001fb6c8(W1753Obj* o) {
    W1753Rec r;
    r.a = o->f40;
    r.p = (u32)o;
    r.v = o->w48;
    r.b = o->f44;
    r.fn = &D_01d9e8c0;
    r.q = o->m30;
    func_0021f620(&r, 0);
}
}  // namespace n001fb6c8

// 001fb720 (was src/anon/batch_wcx2.cpp)
namespace n001fb720 {
// 0x00123c20: definition moved into src/anon/unit_00123990.cpp

// ---- 001fb720
void func_001fa950(u8*, u8*, u8*) asm("func_001fa950");
union UH_001fb720 { u16 h; f32 f; };
/*TARGET 001fb720*/
void func_001fb720(u8* a0, u8* a1, u8* a2) asm("func_001fb720");
void func_001fb720(u8* a0, u8* a1, u8* a2) {
    u8* q = a0 + **(s32**)(a2 + 12) + 160;
    func_001fa950(a0, a1, a2);
    if (*(u32*)a1 == *(u32*)(a0 + 12)) {
        *(f32*)(q + 68) = *(f32*)(a1 + 12);
        *(f32*)(q + 64) = ((UH_001fb720*)(a1 + 20))->h;
    }
}
}  // namespace n001fb720

// 001fb790 (was src/anon/batch_w91.cpp)
namespace n001fb790 {
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
// 0x001f6778: definition moved into src/anon/unit_001f6298.cpp

// --- 001fb790
// Sets the RGBA bytes of a node from 0..255 inputs scaled by the global colour.
extern f32 D_00354be0[] asm("D_00354be0");
void sceVu0CopyVector(u8*, f32*) asm("sceVu0CopyVector");
// memcpy16
void func_001fb6c8(u8*, u32, u32) asm("func_001fb6c8");
/*TARGET 001fb790*/
void func_001fb790(u8* base, u8* c, u8* a2) asm("func_001fb790");
void func_001fb790(u8* base, u8* c, u8* a2) {
    u8* s = base + **(u32**)(a2 + 12) + 160;
    s[72] = (s32)(c[8] * *(f32*)(D_01d9e6e0 + 48));
    s[73] = (s32)(c[9] * *(f32*)(D_01d9e6e0 + 52));
    s[74] = (s32)(c[10] * *(f32*)(D_01d9e6e0 + 56));
    s[75] = (s32)(c[11] * *(f32*)(D_01d9e6e0 + 60));
    sceVu0CopyVector(s + 48, D_00354be0);  // memcpy16
    func_001fb6c8(s, 0, 0);
}
}  // namespace n001fb790

// 001fb870 (was src/anon/batch_w20.cpp)
namespace n001fb870 {
void func_0021fa10(u8*) asm("func_0021fa10");
/*TARGET 001fb870*/
// 0x001ddc48: definition moved into src/anon/unit_001dd920.cpp

void func_001fb870(u8* a, u8* b) asm("func_001fb870");
// 0x001ddc48: definition moved into src/anon/unit_001dd920.cpp

void func_001fb870(u8* a, u8* b) {
    u8* s = a + **(s32**)(b + 12) + 160;
    func_0021fa10(s);
    s[8] = 4;
}
}  // namespace n001fb870

// 001fb8b0 (was gap)
namespace n001fb8b0 {
void func_001fb8b0(void) asm("func_001fb8b0");
void func_001fb8b0(void) {}
}  // namespace n001fb8b0

// 001fb8b8 (was src/anon/batch_w1764_nsa.cpp)
namespace n001fb8b8 {
struct W1764Arg { void* a; u32 b; void* c; f32 d; s16 x, y; void* e; };
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void func_0021fbd8(W1764Arg*, s32) asm("func_0021fbd8");
/*TARGET 001fb8b8*/
// 001ad158: moved to src/anon/unit_001abb28.cpp

void func_001fb8b8(u8* o) asm("func_001fb8b8");
// 001ad158: moved to src/anon/unit_001abb28.cpp

void func_001fb8b8(u8* o) {
    W1764Arg s;
    s.a = o;
    s.b = *(u32*)(o + 36);
    s.c = D_01d9e8c0;
    s.d = *(f32*)(o + 32);
    s.x = (s16)*(f32*)(o + 40);
    s.y = (s16)*(f32*)(o + 44);
    s.e = o + 16;
    func_0021fbd8(&s, 0);
}
}  // namespace n001fb8b8

// 001fb928 (was src/anon/batch_w64.cpp)
namespace n001fb928 {
// 0x001ddb78: definition moved into src/anon/unit_001dd920.cpp

// ---------------------------------------------------------------------------
union Word1fb928 { f32 f; u16 h[2]; u32 w; };
void func_001fab48(u8*, u32*, u8*) asm("func_001fab48");
/*TARGET 001fb928*/
void func_001fb928(u8* p, u32* q, u8* r) asm("func_001fb928");
void func_001fb928(u8* p, u32* q, u8* r) {
    Word1fb928* d = (Word1fb928*)(p + **(s32**)(r + 12) + 160);
    func_001fab48(p, q, r);
    Word1fb928* s = (Word1fb928*)q;
    if (s[0].w == *(u32*)(p + 12)) {
        d[8].f = s[3].f;
        d[10].f = s[4].h[0];
        d[11].f = s[4].h[1];
    }
}
}  // namespace n001fb928

// 001fb9a8 (was src/anon/batch_w76.cpp)
namespace n001fb9a8 {
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
// 0x001f6b68: definition moved into src/anon/unit_001f6b68.cpp

extern u8 D_00354be0[] asm("D_00354be0");
void sceVu0CopyVector(u8*, void*) asm("sceVu0CopyVector");
// memcpy16
void func_001fb8b8(u8*, s32, s32) asm("func_001fb8b8");
/*TARGET 001fb9a8*/
void func_001fb9a8(u8* base, u8* in, u8* desc) asm("func_001fb9a8");
void func_001fb9a8(u8* base, u8* in, u8* desc)
{
    u8* p = base + **(u32**)(desc + 12);
    u8* q = p + 160;
    q[36] = (s32)(in[8] * *(f32*)(D_01d9e6e0 + 48));
    q[37] = (s32)(in[9] * *(f32*)(D_01d9e6e0 + 52));
    q[38] = (s32)(in[10] * *(f32*)(D_01d9e6e0 + 56));
    q[39] = (s32)(in[11] * *(f32*)(D_01d9e6e0 + 60));
    sceVu0CopyVector(p + 176, D_00354be0);  // memcpy16
    func_001fb8b8(q, 0, 0);
}
}  // namespace n001fb9a8

// 001fba88 (was src/anon/batch_w3.cpp)
namespace n001fba88 {
// 0x001da3d8: definition moved into src/anon/unit_001d9d00.cpp

void func_0021fe28(u32) asm("func_0021fe28");
/*TARGET 001fba88*/
void func_001fba88(u32 base, const u32* info) asm("func_001fba88");
void func_001fba88(u32 base, const u32* info) { func_0021fe28(base + **(const u32* const*)(info + 3) + 160); }
}  // namespace n001fba88

// 001fbab0 (was gap)
namespace n001fbab0 {
void func_001fbab0(void) asm("func_001fbab0");
void func_001fbab0(void) {}
}  // namespace n001fbab0

// 001fbab8 (was src/anon/sweep_001fbab8_nsa.cpp)
namespace n001fbab8 {
struct Arg2 { void* a; s32 b; void* c; f32 d; s16 e; u16 f; void* g; };
extern u8 D_01d9e8c0 asm("D_01d9e8c0");
void func_0021fe40(Arg2*, s32) asm("func_0021fe40");
struct T2 { u8 pad[0x20]; f32 f20; s32 w24; f32 f28; u16 h2c; };
/*TARGET 001fbab8*/
void func_001fbab8(T2* a0) asm("func_001fbab8");
void func_001fbab8(T2* a0) {
    Arg2 s;
    s.b = a0->w24;
    s.d = a0->f20;
    s.e = (s32)a0->f28;
    s.f = a0->h2c;
    s.c = &D_01d9e8c0;
    s.g = (char*)a0 + 16;
    s.a = a0;
    func_0021fe40(&s, 0);
}
}  // namespace n001fbab8

// 001fbb20 (was src/anon/batch_w38.cpp)
namespace n001fbb20 {
// Bitfield members carry the struct's alias set, so these loads stay after
// the float stores as in the original.
struct Out1fbb20 { u8 pad[32]; f32 f32_; u32 f36; f32 f40; u16 f44; };
struct In1fbb20 { u32 id; u8 pad[8]; f32 f12; u16 f16 : 16; u16 f18 : 16; };
void func_001facf8(u8*, In1fbb20*, u8*) asm("func_001facf8");
/*TARGET 001fbb20*/
void func_001fbb20(u8* p, In1fbb20* q, u8* r) asm("func_001fbb20");
void func_001fbb20(u8* p, In1fbb20* q, u8* r) {
    Out1fbb20* d = (Out1fbb20*)(p + **(s32**)(r + 12) + 160);
    func_001facf8(p, q, r);
    if (q->id == *(u32*)(p + 12)) {
        d->f32_ = q->f12;
        d->f40 = q->f16;
        d->f44 = q->f18;
    }
}
}  // namespace n001fbb20

// 001fbb98 (was src/anon/batch_w77.cpp)
namespace n001fbb98 {
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_00354be0 asm("D_00354be0");
void sceVu0CopyVector(u8*, void*) asm("sceVu0CopyVector");
// memcpy16
void func_001fbab8(u8*, s32, s32) asm("func_001fbab8");
/*TARGET 001fbb98*/
void func_001fbb98(u8* a, u8* col, u8* c) asm("func_001fbb98");
void func_001fbb98(u8* a, u8* col, u8* c)
{
    u8* d = a + **(u32**)(c + 12);
    u8* s = d + 160;
    s[36] = (s32)(col[8] * *(f32*)(D_01d9e6e0 + 48));
    s[37] = (s32)(col[9] * *(f32*)(D_01d9e6e0 + 52));
    s[38] = (s32)(col[10] * *(f32*)(D_01d9e6e0 + 56));
    s[39] = (s32)(col[11] * *(f32*)(D_01d9e6e0 + 60));
    sceVu0CopyVector(d + 176, &D_00354be0);  // memcpy16
    func_001fbab8(s, 0, 0);
}
}  // namespace n001fbb98

// 001fbc78 (was src/anon/batch_w4.cpp)
namespace n001fbc78 {
void func_00220070(void*) asm("func_00220070");
/*TARGET 001fbc78*/
// 0x001fa928: definition moved into src/anon/unit_001fa1b8.cpp

void func_001fbc78(u8* p, u8* q) asm("func_001fbc78");
// 0x001fa928: definition moved into src/anon/unit_001fa1b8.cpp

void func_001fbc78(u8* p, u8* q) {
    func_00220070(p + *(s32*)*(u32*)(q + 12) + 160);
}
}  // namespace n001fbc78

// 001fbca0 (was gap)
namespace n001fbca0 {
void func_001fbca0(void) asm("func_001fbca0");
void func_001fbca0(void) {}
}  // namespace n001fbca0

// 001fbca8 (was gap)
namespace n001fbca8 {
struct In { s32 id; f32 a, b; };
struct V { f32 x, y; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_001fbca8(u8* a0, In* in, u8* t) asm("func_001fbca8");
void func_001fbca8(u8* a0, In* in, u8* t) {
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    s32* off = *(s32**)(t + 12);
    V* pa = (V*)(a0 + off[0] + 160);
    u8* pb = a0 + off[1] + 160;
    if (*(s32*)(a0 + 12) == in->id) {
        pa->x += in->a;
        pa->y += in->b;
        if (*(s32*)(a0 + 12) == 0 && a0[157] == 0) return;
    }
    *(f32*)(pb + 156) += pa->x;
    *(f32*)(pb + 168) += pa->y;
}
}  // namespace n001fbca8

// 001fbd60 (was gap)
namespace n001fbd60 {
void func_001fbd60(u8* a0, u8* t) asm("func_001fbd60");
void func_001fbd60(u8* a0, u8* t) {
    u8* q = a0 + **(s32**)(t + 12);
    *(s32*)(q + 160) = 0;
    *(s32*)(q + 164) = 0;
}
}  // namespace n001fbd60

// 001fbd78 (was src/anon/batch_w1983_nsa.cpp)
namespace n001fbd78 {
struct V4_w1983 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Sub_w1983 { f32 f0; char* p4; };
struct Tbl_w1983 { s32 o0; s32 o4; s32 o8; };
struct A0_w1983 { char pad[0xc]; s32 id; char pad2[0x9d - 0x10]; u8 b9d; };
struct A1_w1983 { s32 id; f32 f4; s32 idx; s32 off; };
struct A2_w1983 { char pad[0xc]; Tbl_w1983* t; };
struct Ent_w1983 { s32 a; char* p; s32 c, d; };
struct G_w1983 { char pad[0x80]; Ent_w1983* e; char pad2[0xa8 - 0x84]; u64 fl; };
s32 func_00222568(void) asm("func_00222568");
void func_002226b8(void*, void*) asm("func_002226b8");
f32 func_002229a0(void*) asm("func_002229a0");
void sceVu0Normalize(void*, void*) asm("sceVu0Normalize");
void sceVu0InterVector(void*, void*, void*, f32) asm("sceVu0InterVector");
void sceVu0AddVector(void*, void*, void*) asm("sceVu0AddVector");
void sceVu0SubVector(void*, void*, void*) asm("sceVu0SubVector");
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
void sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
extern char D_01d9e360[] asm("D_01d9e360");
extern G_w1983* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
/*TARGET 001fbd78*/
void func_001fbd78(A0_w1983* a0, A1_w1983* a1, A2_w1983* a2) asm("func_001fbd78");
void func_001fbd78(A0_w1983* a0, A1_w1983* a1, A2_w1983* a2) {
    V4_w1983 v;
    struct { s64 a, b; } r;
    V4_w1983 u;
    Sub_w1983* s = (Sub_w1983*)((char*)a0 + a2->t->o8 + 0xa0);
    if (a0->id == a1->id) {
        s32 idx;
        char* p;
        s->f0 = a1->f4;
        idx = a1->idx;
        if (idx != -1) {
            p = D_01d9e6e0->e[idx].p + a1->off + 0xa0;
        } else {
            p = D_01d9e360;
        }
        s->p4 = p;
        if (a0->id == 0 && a0->b9d == 0) return;
    }
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->fl & 0xFF0000FF00ULL) return;
    if (s->p4 == D_01d9e360) return;
    {
        Tbl_w1983* t = a2->t;
        char* p2 = (char*)a0 + t->o4 + 0xa0;
        sceVu0SubVector(&v, s->p4, (char*)a0 + t->o0 + 0xa0);
        sceVu0Normalize(&v, &v);
        sceVu0CopyVector(&u, p2);
        f32 len = func_002229a0(&u);
        sceVu0Normalize(&u, &u);
        sceVu0AddVector(&r, &u, &v);
        if (r.a == 0 && r.b == 0) {
            (&v.x)[func_00222568() % 3] += 0.05f;
        }
        sceVu0InterVector(&v, &v, &u, s->f0);
        sceVu0Normalize(&v, &v);
        sceVu0ScaleVector(&v, &v, len);
        func_002226b8(p2, &v);
    }
}
}  // namespace n001fbd78

// 001fbf68 (was gap)
namespace n001fbf68 {
void func_001fbf68(void) asm("func_001fbf68");
void func_001fbf68(void) {}
}  // namespace n001fbf68

// 001fbf70 (was gap)
namespace n001fbf70 {
struct In { s32 id; f32 a, b; };
struct V { f32 x, y; u8* p; };
void func_001fbf70(u8* a0, In* in, u8* t) asm("func_001fbf70");
void func_001fbf70(u8* a0, In* in, u8* t) {
    if (*(s32*)(a0 + 12) != in->id) return;
    V* v = (V*)(a0 + (*(s32**)(t + 12))[1] + 160);
    v->x = in->a;
    v->y = in->b;
    v->p = a0 + (*(s32**)(t + 12))[0] + 160;
}
}  // namespace n001fbf70

// 001fbfc0 (was gap)
namespace n001fbfc0 {
void func_001fbfc0(u8* a0, u8* t) asm("func_001fbfc0");
void func_001fbfc0(u8* a0, u8* t) {
    u8* q = a0 + (*(s32**)(t + 12))[1];
    *(s32*)(q + 168) = 0;
}
}  // namespace n001fbfc0

// 001fbfd8 (was src/anon/batch_w276.cpp)
namespace n001fbfd8 {
struct XC { s32 o0; s32 o4; s32 o8; };
struct X { u8 pad[12]; s32 c; };
struct K { s32 id; s32 idx; s32 off; };
struct S { f32 f0; f32 f4; u8* p8; };
struct M { u8 pad[128]; u8* tbl; u8 pad2[168 - 132]; u64 fl; };
extern u8 D_01d9e360[] asm("D_01d9e360");
extern M* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
void sceVu0SubVector(void*, void*, void*) asm("sceVu0SubVector");
// vec4_sub
f32 func_002229a0(void*) asm("func_002229a0");
// vec3_length
void sceVu0Normalize(void*, void*) asm("sceVu0Normalize");
// vec4_normalize
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void func_00222750(void*, void*, void*) asm("func_00222750");
/*TARGET 001fbfd8*/
void func_001fbfd8(u8* a, K* k, X* x) asm("func_001fbfd8");
void func_001fbfd8(u8* a, K* k, X* x) {
    u8 buf[16];
    S** slot = (S**)(a + ((XC*)x->c)->o8 + 160);
    if (*(s32*)(a + 12) == k->id) {
        s32 i = k->idx;
        S* v;
        if (i != -1) v = (S*)(*(u8**)(D_01d9e6e0->tbl + i * 16 + 4) + k->off + 160);
        else v = (S*)D_01d9e360;
        *(s32*)slot = (s32)v;
        if (*(s32*)(a + 12) == 0 && a[157] == 0) return;
    }
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->fl & 0xff0000ff00ULL) return;
    S* s = *slot;
    if (s == (S*)D_01d9e360) return;
    XC* c = (XC*)x->c;
    u8* d = a + c->o4 + 160;
    sceVu0SubVector(buf, s->p8, a + c->o0 + 160);  // vec4_sub
    f32 len = func_002229a0(buf);  // vec3_length
    sceVu0Normalize(buf, buf);  // vec4_normalize
    if (len < s->f0) {
        sceVu0ScaleVector(buf, buf, (1.0f - len / s->f0) * s->f4);  // vec_scale_by_f12
        func_00222750(d, d, buf);
    }
}
}  // namespace n001fbfd8

// 001fc150 (was gap)
namespace n001fc150 {
void func_001fc150(void) asm("func_001fc150");
void func_001fc150(void) {}
}  // namespace n001fc150

// 001fc158 (was gap)
namespace n001fc158 {
struct In { s32 id; f32 a; };
void func_001fc158(u8* a0, In* in, u8* t) asm("func_001fc158");
void func_001fc158(u8* a0, In* in, u8* t) {
    if (*(s32*)(a0 + 12) != in->id) return;
    s32* off = *(s32**)(t + 12);
    u8* q = a0 + off[1];
    *(u8**)(q + 164) = a0 + off[0] + 160;
    *(f32*)(q + 160) = in->a;
}
}  // namespace n001fc158

// 001fc198 (was gap)
namespace n001fc198 {
void func_001fc198(void) asm("func_001fc198");
void func_001fc198(void) {}
}  // namespace n001fc198

// 001fc1a0 (was src/anon/batch_wcx2.cpp)
namespace n001fc1a0 {
// 0x001b7c80: definition moved into src/anon/unit_001b6a50.cpp

struct Gs100 { u8 pad[128]; u8* tab; u8 pad2[36]; u64 st; };
struct Idx100 { s32 f0; s32 f4; s32 f8; };
struct Ctx100 { u8 pad[12]; Idx100* idx; };
struct Req100 { s32 id; s32 snd; s32 off; u8 on; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Gs100* D_01d9e6e0 asm("D_01d9e6e0");
u8* func_001e7a98(Gs100*, u8*) asm("func_001e7a98");
void func_002226b8(u8*, u8*) asm("func_002226b8");
/*TARGET 001fc1a0*/
// vec3_copy
void func_001fc1a0(u8* o, Req100* r, Ctx100* c) asm("func_001fc1a0");
// vec3_copy
void func_001fc1a0(u8* o, Req100* r, Ctx100* c)
{
    u8* sa = o + c->idx->f8 + 160;
    if (*sa & 2) return;
    if (*(s32*)(o + 12) == r->id) {
        if (r->on) *sa |= 1;
        else *sa &= ~1;
    }
    if (D_01d9ea9c) return;
    if (D_01d9e6e0->st & 0xff0000ff00ULL) return;
    u8* sb = o + c->idx->f4 + 160;
    u8 en = sb[16] & 1;
    if (!en) return;
    if (r->snd == -1) return;
    u8* w = 0;
    u8* q = D_01d9e6e0->tab + r->snd * 16;
    if (q) {
        w = func_001e7a98(D_01d9e6e0, q);
        *(u8**)(w + 4) = o;
    }
    u8* sc = o + c->idx->f0 + 160;
    u8* dst = w + r->off + 160;
    u8 hit = *sa & 1;
    if (!hit) {
        *sa |= 2;
        sc = sb;
    }
    func_002226b8(dst, sc);  // vec3_copy
}
}  // namespace n001fc1a0

// 001fc308 (was gap)
namespace n001fc308 {
void func_001fc308(u8* a0, u8* t) asm("func_001fc308");
void func_001fc308(u8* a0, u8* t) {
    u8* q = a0 + (*(s32**)(t + 12))[2];
    q[160] = 0;
}
}  // namespace n001fc308

// 001fc320 (was src/anon/batch_w317.cpp)
namespace n001fc320 {
union W317YM { u8* p; u8 c; };
struct W317OF { s32 o0; s32 o4; s32 o8; };
struct W317Q { u8 pad[12]; W317OF* of; };
struct W317P { s32 a; s32 k; s32 off; u8 flag; };
struct W317Y { f32 f; W317YM m4; };
struct W317X { f32 v[4]; u8 flags; u8 pad[3]; u32 y; };
struct W317E16 { s32 a; s32 b; s32 c; s32 d; };
struct W317L { f32 a[4]; f32 b[4]; f32 t; f32 u; f32 pad[2]; f32 c[4]; };
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern W317Y D_01d9e360 asm("D_01d9e360");
void sceVu0SubVector(void*, void*, void*) asm("sceVu0SubVector");
// vec4_sub
void sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
// memcpy16
s32 func_002225a8(void*) asm("func_002225a8");
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0AddVector(void*, void*, void*) asm("sceVu0AddVector");
// vec4_add
void func_00222730(void*, void*, void*) asm("func_00222730");
/*TARGET 001fc320*/
void func_001fc320(u8* self, W317P* p, W317Q* q) asm("func_001fc320");
void func_001fc320(u8* self, W317P* p, W317Q* q) {
    W317X* x = (W317X*)(self + q->of->o8 + 160);
    W317L l;
    u8 fl = x->flags;
    bool b = fl & 1;
    if (b) return;
    if (*(s32*)(self + 12) == p->a) {
        s32 k = p->k;
        W317Y* y;
        if (k != -1) y = (W317Y*)((*(W317E16**)(D_01d9e6e0 + 128))[k].b + p->off + 160);
        else y = &D_01d9e360;
        x->y = (u32)y;
        if (p->flag) x->flags = fl | 2;
        if (*(s32*)(self + 12) == 0) { if (self[157] == 0) return; }
    }
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    W317Y* y = (W317Y*)x->y;
    if (y == &D_01d9e360) return;
    f32 f = y->f;
    u8* s4 = self + q->of->o0 + 160;
    u8* s3 = self + q->of->o4 + 160;
    if (f == 0.0f) return;
    l.t = f;
    sceVu0SubVector(&l, s4, y->m4.p);  // vec4_sub
    sceVu0CopyVector(l.b, s3);  // memcpy16
    if (!func_002225a8(&l)) return;
    f32 u = l.u;
    if (u < 0.0f) return;
    if (1.0f < u) return;
    x->flags |= 1;
    sceVu0ScaleVector(l.c, l.b, u);  // vec_scale_by_f12
    sceVu0AddVector(l.c, l.c, &l);  // vec4_add
    sceVu0AddVector(x, ((W317Y*)x->y)->m4.p, l.c);  // vec4_add
    if (x->flags & 2) {
        func_00222730(s3, x, s4);
        *(s32*)(self + 12) = 0xffff0000;
    }
}
}  // namespace n001fc320

// 001fc530 (was gap)
namespace n001fc530 {
void func_001fc530(u8* a0, u8* t) asm("func_001fc530");
void func_001fc530(u8* a0, u8* t) {
    u8* q = a0 + (*(s32**)(t + 12))[2] + 160;
    q[16] = 0;
    *(f32*)(q + 12) = 1.0f;
}
}  // namespace n001fc530

// 001fc558 (was gap)
namespace n001fc558 {
struct In { s32 id; f32 a, b, c; };
void func_001fc558(u8* a0, In* in, u8* t) asm("func_001fc558");
void func_001fc558(u8* a0, In* in, u8* t) {
    if (*(s32*)(a0 + 12) != in->id) return;
    f32* v = (f32*)(a0 + **(s32**)(t + 12) + 160);
    v[0] = in->a;
    v[1] = in->b;
    v[2] = in->c;
}
}  // namespace n001fc558

// 001fc598 (was gap)
namespace n001fc598 {
void func_001fc598(u8* a0, u8* t) asm("func_001fc598");
void func_001fc598(u8* a0, u8* t) {
    u8* q = a0 + **(s32**)(t + 12);
    *(f32*)(q + 172) = 1.0f;
}
}  // namespace n001fc598

// 001fc5b8 (was src/anon/batch_w2370_nsa.c)
namespace n001fc5b8 {
typedef unsigned int u128_w2370 __attribute__((mode(TI)));
typedef struct { s32 x, y, z; } PVec_w2370;
typedef PVec_w2370 PVec8_w2370 __attribute__((aligned(8)));
typedef struct {
    u8 pad[0x40];
    u8 work[0x30];       /* 0x40 */
    u128_w2370 m70;      /* 0x70 */
    PVec8_w2370 pos;     /* 0x80 */
} PartEnt_w2370;
typedef struct { u8 pad[0xc]; s32* offs; } PartCmd_w2370;
extern PartEnt_w2370* D_01d9ea94 asm("D_01d9ea94");
extern u128_w2370 D_0035da80 asm("D_0035da80");
void func_001e8fe0(void*, PVec_w2370*) asm("func_001e8fe0");
/*TARGET 001fc5b8*/
/* Moves entry 0 to entry 1's position, passing the move delta on. */
void func_001fc5b8(u8* base, s32 a1, PartCmd_w2370* cmd) asm("func_001fc5b8");
/* Moves entry 0 to entry 1's position, passing the move delta on. */
void func_001fc5b8(u8* base, s32 a1, PartCmd_w2370* cmd) {
    s32* o = cmd->offs;
    PartEnt_w2370* e;
    PVec_w2370* to;
    s32 x, y, z;
    PVec8_w2370 d;
    e = (PartEnt_w2370*)(base + o[0] + 0xa0);
    to = (PVec_w2370*)(base + o[1] + 0xa0);
    D_01d9ea94 = e;
    *(u64*)&d = *(u64*)&e->pos; d.z = e->pos.z;
    x = to->x; y = to->y; z = to->z;
    d.x -= x; d.y -= y; d.z -= z;
    e->pos.x = x; e->pos.y = y; e->pos.z = z;
    func_001e8fe0(e->work, (PVec_w2370*)&d);
    e->m70 = D_0035da80;
}
}  // namespace n001fc5b8

// 001fc658 (was gap)
namespace n001fc658 {
void func_001fc658(u8* a0, u8* t) asm("func_001fc658");
void func_001fc658(u8* a0, u8* t) {
    u8* q = a0 + **(s32**)(t + 12) + 160;
    *(s32*)(q + 128) = 0;
    *(s32*)(q + 132) = 0;
    *(s32*)(q + 136) = 0;
}
}  // namespace n001fc658

// 001fc678 (was src/anon/auto80_199_queue.cpp)
namespace n001fc678 {
/*TARGET 001fc678*/
void func_001fc678(u32 a0) asm("_Z13func_001fc678j");
void func_001fc678(u32 a0) {
    u32 buf[20];
    u32* gp = (u32*)0x01da0000;
    u32 s0 = *(u32*)(a0 + 4);
    u32 s2 = s0 + 16;
    u32 s3 = (u32)buf + 64;

    sceVu0Normalize((u32)buf, s2);  // vec4_normalize
    sceVu0Normalize((u32)buf + 16, s0 + 32);  // vec4_normalize
    u32 a0c = (u32)buf + 32;
    u32 a1c = s0 + 48;
    s0 = a1c;
    sceVu0Normalize(a0c, a1c);  // vec4_normalize

    u32 t6 = gp[-1606];
    sceVu0ApplyMatrix(s3, s2, t6 + 64);

    u32 t4 = gp[-1606] + 16;
    sceVu0MulMatrix(t4, (u32)buf, t4);

    u32 t5 = gp[-1606] + 64;
    sceVu0CopyVector(t5, s3);  // memcpy16
}
}  // namespace n001fc678

