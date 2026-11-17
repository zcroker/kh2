// Linked unit 0x0023bc58-0x0023c940: YI::SEQUENCE keys, YI::LAYOUT (gap functions written here).
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
#include "../ishi/sequence.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_obj.hpp"
#include "../tozawa/layout.hpp"
#include "../tozawa/laymsg.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/mcard.hpp"

// 0023bc58 (was src/anon/batch_w1703_nsa.cpp)
namespace n0023bc58 {
struct W1703Frame { u16 sprite; u16 pad2; u8 pad4[12]; s32 w; s32 h; u8 pad18[12]; };
struct W1703Sprite { u32 pad0; void* parts; u8 pad8[0x88]; };
struct W1703Layout { u8 pad0[0xb0]; W1703Sprite* sprites; W1703Frame* frames; u8 padb8[0x5c]; s32 cur; };
s32 func_00237508(void*, void*, s32) asm("func_00237508");
s32 func_00237578(void*, void*, s32) asm("func_00237578");
void func_00237458(void*, void*, s32, s32) asm("func_00237458");
void func_002374c8(void*, void*, s32, s32) asm("func_002374c8");
void func_00237540(void*, void*, s32, s32) asm("func_00237540");
void func_002375b0(void*, void*, s32, s32) asm("func_002375b0");
void func_00237640(void*, void*, s32, s32, s32) asm("func_00237640");
/*TARGET 0023bc58*/
// parts: 0..8 = TL, T, TR, L, C, R, BL, B, BR
void func_0023bc58(W1703Layout* l, s32 w, s32 h) asm("func_0023bc58");
// parts: 0..8 = TL, T, TR, L, C, R, BL, B, BR
void func_0023bc58(W1703Layout* l, s32 w, s32 h) {
    s32 w0, h0, h1, h2, w3, w6;
    W1703Frame* f = &l->frames[l->cur];
    h = (h + f->h) & ~1;
    w = (w + f->w) & ~1;
    s32 hw = w >> 1; s32 hh = h >> 1;
    W1703Sprite* sp = &l->sprites[f->sprite];
    void* o = sp->parts;
    w0 = func_00237508(l, o, 0);
    h0 = func_00237578(l, o, 0);
    h1 = func_00237578(l, o, 1);
    h2 = func_00237578(l, o, 2);
    w3 = func_00237508(l, o, 3);
    w6 = func_00237508(l, o, 6);
    s32 y = -h / 2;
    s32 x = -w / 2;
    s32 y0 = y - h0; s32 x6 = x - w6; s32 x0 = x - w0; s32 y1 = y - h1; s32 y2 = y - h2;
    func_00237458(l, o, 0, x0);
    func_002374c8(l, o, 0, y0);
    func_00237458(l, o, 1, x);
    func_002374c8(l, o, 1, y1);
    s32 x3 = x - w3;
    func_00237540(l, o, 1, w);
    func_00237458(l, o, 2, hw);
    func_002374c8(l, o, 2, y2);
    func_00237458(l, o, 3, x3);
    func_002374c8(l, o, 3, y);
    func_002375b0(l, o, 3, h);
    func_00237458(l, o, 4, x);
    func_002374c8(l, o, 4, y);
    func_00237640(l, o, 4, w, h);
    func_00237458(l, o, 5, hw);
    func_002374c8(l, o, 5, y);
    func_002375b0(l, o, 5, h);
    func_00237458(l, o, 6, x6);
    func_002374c8(l, o, 6, hh);
    func_00237458(l, o, 7, x);
    func_002374c8(l, o, 7, hh);
    func_00237540(l, o, 7, w);
    func_00237458(l, o, 8, hw);
    func_002374c8(l, o, 8, hh);
}
}  // namespace n0023bc58

// 0023bfa0 (was gap)
namespace n0023bfa0 {
extern void* D_0035eb08[] asm("D_0035eb08");
// C2 copy of the constructor at 0x23c008.
void func_0023bfa0(u32* p) asm("func_0023bfa0");
void func_0023bfa0(u32* p) {
    *(void***)p = D_0035eb08;
    p[1] = 0;
    p[2] = 0; p[3] = 0; p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0; p[8] = 0; p[9] = 0;
    p[10] = 0; p[11] = 0; p[12] = 0; p[13] = 0; p[14] = 0; p[15] = 0; p[16] = 0;
    p[17] = 0; p[18] = 0; p[19] = 0;
    *(u8*)(p + 20) = 0;
    p[21] = 0;
    p[22] = 0;
}
}  // namespace n0023bfa0

// 0023c008 (was src/anon/batch_w43.cpp)
namespace n0023c008 {
extern void* D_0035eb08[] asm("D_0035eb08");
/*TARGET 0023c008*/
// 0x00225328: definition moved into src/anon/unit_00224780.cpp

void func_0023c008(u32* p) asm("func_0023c008");
// 0x00225328: definition moved into src/anon/unit_00224780.cpp

void func_0023c008(u32* p) {  // obj_ctor_36eae8
    *(void***)p = D_0035eb08;
    p[1] = 0;
    p[2] = 0; p[3] = 0; p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0; p[8] = 0; p[9] = 0;
    p[10] = 0; p[11] = 0; p[12] = 0; p[13] = 0; p[14] = 0; p[15] = 0; p[16] = 0;
    p[17] = 0; p[18] = 0; p[19] = 0;
    *(u8*)(p + 20) = 0;
    p[21] = 0;
    p[22] = 0;
}
}  // namespace n0023c008

// 0023c070 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0023c070 {
u32 func_0023c300(u32, u32, u32, u32) asm("_Z13func_0023c300jjjj");
extern u8 D_0035eb08 asm("D_0035eb08");
/*TARGET 0023c070*/
// 0x00239870: definition moved into src/anon/unit_002384f8.cpp

u32 func_0023c070(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023c070jjjj");
// 0x00239870: definition moved into src/anon/unit_002384f8.cpp

u32 func_0023c070(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035eb08;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0023c300)(u32, u32, u32, u32) = func_0023c300;
    r2 = fp_call4_0023c300(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0023c070

// 0023c098 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0023c098 {
u32 func_0023c300(u32, u32, u32, u32) asm("_Z13func_0023c300jjjj");
extern u8 D_0035eb08 asm("D_0035eb08");
/*TARGET 0023c098*/
u32 func_0023c098(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023c098jjjj");
u32 func_0023c098(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_36eae8_then_call
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035eb08;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0023c300)(u32, u32, u32, u32) = func_0023c300;
    r2 = fp_call4_0023c300(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0023c098

// 0023c0c0 (was src/anon/batch_w14.cpp)
namespace n0023c0c0 {
// set_vtbl_347b88
void func_00106420(void*) asm("func_00106420");
void func_0023c300(void*) asm("func_0023c300");
extern u8 D_0035eb08[] asm("D_0035eb08");
/*TARGET 0023c0c0*/
// 0x00237458: definition moved into src/anon/unit_00237068.cpp

void func_0023c0c0(u8* p) asm("func_0023c0c0");
// 0x00237458: definition moved into src/anon/unit_00237068.cpp

void func_0023c0c0(u8* p) {
    *(u8**)p = D_0035eb08;
    func_0023c300(p);
    func_00106420(p);
}
}  // namespace n0023c0c0

// 0023c0f8 (was src/anon/misc_2.cpp)
namespace n0023c0f8 {
/*TARGET 0023c0f8*/
// 0x00237278: definition moved into src/anon/unit_00237068.cpp

void func_0023c0f8(void* self) asm("_Z13func_0023c0f8Pv");
// 0x00237278: definition moved into src/anon/unit_00237068.cpp

void func_0023c0f8(void* self) {}
}  // namespace n0023c0f8

// 0023c100 (was src/anon/batch_w1987_nsa.cpp)
namespace n0023c100 {
struct Elem1987;
void* znaj1987(u32, u32) asm("_Znaj");
s32 getimg1987(s32, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_00239700(Elem1987*) asm("func_00239700");
void func_00239988(Elem1987*, u8*, s32) asm("func_00239988");
struct Elem1987 { virtual ~Elem1987(); u8 pad[340]; };
struct Res1987 { u8 pad[8]; s32 o8; s32 oc; s32 o10; s32 o14; s32 o18; s32 o1c; };
struct MB1987 {
    u32 f0; u32 heap; u8* res; s32 fc; u8* p10; u8* p14; s32* offs; s32 f1c; s32 f20; s32 n;
    s32 img; Elem1987* arr; Elem1987* arr2; s32 f34; s32 f38; s32 f3c; u8 pad40[8]; f32 f48;
};
void f23c598_1987(MB1987*) asm("_Z13func_0023c598Pv");
void setoff1987(MB1987*, s32, s32) asm("_ZN2YI6LAYOUT9SetOffsetEii");
void func_0023c6f8(MB1987*, s32) asm("func_0023c6f8");
s32 v1(MB1987* self, u8* res, s32 img, u32 heap) asm("_ZN2Tz9MenuBasic9SetMesResEz");
/*TARGET 0023c100*/
s32 v1(MB1987* self, u8* res, s32 img, u32 heap) asm("_ZN2Tz9MenuBasic9SetMesResEz");
s32 v1(MB1987* self, u8* res, s32 img, u32 heap)
{
    Res1987* r = (Res1987*)res;
    s32 i;
    self->heap = heap;
    self->img = img;
    self->res = res;
    self->p10 = res + r->oc;
    self->p14 = res + r->o14;
    self->offs = (s32*)(res + r->o1c);
    self->f1c = r->o8;
    self->f20 = r->o10;
    self->n = r->o18;
    delete[] self->arr;
    {
        s32 n = self->n;
        s32* raw = (s32*)znaj1987(n * 344 + 4, self->heap);
        Elem1987* arr;
        *raw = n;
        arr = (Elem1987*)(raw + 1);
        {
            Elem1987* p = arr;
            s32 k = n - 1;
            if (__builtin_expect(n != 0, 1)) { do { func_00239700(p); p++; } while (--k != -1); }
        }
        self->arr = arr;
    }
    delete[] self->arr2;
    self->arr2 = 0;
    for (i = 0; i < self->n; i++) {
        func_00239988(&self->arr[i], res + self->offs[i], getimg1987(self->img, 0));
    }
    self->f3c = 0;
    self->f38 = 1;
    self->fc = 0;
    self->f48 = 1.0f;
    f23c598_1987(self);
    setoff1987(self, 0, 0);
    func_0023c6f8(self, 0);
    return 1;
}
}  // namespace n0023c100

// 0023c300 (was src/anon/auto80_199_queue.cpp)
namespace n0023c300 {
/*TARGET 0023c300*/
void func_0023c300(void* a0) asm("_Z13func_0023c300Pv");
void func_0023c300(void* a0) {
    u8* s1;
    u8* a;
    u8* s0;

    s1 = (u8*)a0;

    a = (u8*)*(u32*)(s1 + 0x2c);
    if (a != 0) {
        s0 = a + (*(s32*)(a - 4) * 344);
        for (;;) {
            if (a == s0) {
                break;
            }
            s0 -= 344;
            ((void(**)(void*))(*(u32*)s0))[0]((void*)s0);
            a = (u8*)*(u32*)(s1 + 0x2c);
        }
        func_00106450((void*)(a - 4));
        *(u32*)(s1 + 0x2c) = 0;
    }

    a = (u8*)*(u32*)(s1 + 0x30);
    if (a != 0) {
        s0 = a + (*(s32*)(a - 4) * 344);
        for (;;) {
            if (a == s0) {
                break;
            }
            s0 -= 344;
            ((void(**)(void*))(*(u32*)s0))[0]((void*)s0);
            a = (u8*)*(u32*)(s1 + 0x30);
        }
        func_00106450((void*)(a - 4));
        *(u32*)(s1 + 0x30) = 0;
    }
}
}  // namespace n0023c300

// 0023c3b0 (was gap)
namespace n0023c3b0 {
u8* func_0023c3b0(u8* p, s32 i) asm("func_0023c3b0");
u8* func_0023c3b0(u8* p, s32 i) { return *(u8**)(p + 44) + i * 344; }
u8* func_0023c3c8(u8* p, s32 i) asm("func_0023c3c8");
u8* func_0023c3c8(u8* p, s32 i) { return *(u8**)(p + 48) + i * 344; }
}  // namespace n0023c3b0

// 0023c3e0 (was src/anon/batch_w243.cpp)
namespace n0023c3e0 {
// 0x0018d940: definition moved into src/anon/unit_0018d050.cpp

struct w243_E2c { u8 pad[0xf8]; s32 len; u8 pad2[344 - 0xfc]; };
struct w243_E14 { u16 h; u8 pad[18]; };
struct w243_E10 { u32 a; s32 i; s32 off; u8 pad[12]; };
struct w243_O { u8 pad[0x10]; w243_E10* t10; w243_E14* t14; u8 pad2[0x24 - 0x18]; s32 cnt; u8 pad3[4]; w243_E2c* arr; u8* base; s32 cnt34; u8 pad4[0x4c - 0x38]; s32 idx; };
/*TARGET 0023c3e0*/
u8* func_0023c3e0(w243_O* o, s32 x, s32 n) asm("func_0023c3e0");
u8* func_0023c3e0(w243_O* o, s32 x, s32 n) {
    s32 acc = 0;
    s32 i;
    for (i = 0; i < o->cnt; i++) {
        s32 prev = acc;
        acc += o->arr[i].len;
        if (x < acc) {
            s32 off = x - prev;
            w243_E14* h = &o->t14[o->idx];
            w243_E10* e = &o->t10[h->h];
            s32 j;
            for (j = 0; j < o->cnt34; j++, e++) {
                if (e->i == i && e->off == off) {
                    if (n == 0) return o->base + j * 344;
                    n--;
                }
            }
        }
    }
    return 0;
}
}  // namespace n0023c3e0

// 0023c4b8 (was src/anon/tiny_leaf.cpp)
namespace n0023c4b8 {
/*TARGET 0023c4b8*/
// 0x00236cc0: definition moved into src/anon/unit_00236180.cpp

u32 func_0023c4b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023c4b8jjjj");
// 0x00236cc0: definition moved into src/anon/unit_00236180.cpp

u32 func_0023c4b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r14 = *(u32*)((u32)r4 + (s32)(24));
    r5 = (u32)(r5 << 2);
    r2 = *(u32*)((u32)r4 + (s32)(8));
    r5 = (u32)(r5 + r14);
    r15 = *(u32*)((u32)r5 + (s32)(0));
    r2 = (u32)(r2 + r15);
    return r2;
}
}  // namespace n0023c4b8

// 0023c4d8 (was src/anon/tiny_wrappers_more.cpp)
namespace n0023c4d8 {
u32 func_00236cc0(u32, u32, u32, u32) asm("_Z13func_00236cc0jjjj");
/*TARGET 0023c4d8*/
// 0x002346a0: definition moved into src/anon/unit_002335e8.cpp

u32 func_0023c4d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023c4d8jjjj");
// 0x002346a0: definition moved into src/anon/unit_002335e8.cpp

u32 func_0023c4d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00236cc0(((u32)(*(u32*)((u32)(a0) + 40u))), a1, a2, a3);
}
}  // namespace n0023c4d8

// 0023c4f0 (was gap)
namespace n0023c4f0 {
struct E24 { s32 a, b, c, d, e, f; };
struct I20 { u16 base; u16 pad; u32 x[4]; };
struct L23c { u8 pad[16]; E24* ent; I20* idx; u8 pad2[76 - 24]; s32 cur; };
s32 func_0023c4f0(L23c* l, s32 i) asm("func_0023c4f0");
s32 func_0023c4f0(L23c* l, s32 i) { u32 c = l->cur * 20; u8* e = (u8*)l->ent; I20* x = (I20*)((u8*)l->idx + c); e += (x->base + i) * 24; return ((E24*)e)->a; }
s32 func_0023c528(L23c* l, s32 i) asm("func_0023c528");
s32 func_0023c528(L23c* l, s32 i) { u32 c = l->cur * 20; u8* e = (u8*)l->ent; I20* x = (I20*)((u8*)l->idx + c); e += (x->base + i) * 24; return ((E24*)e)->b; }
s32 func_0023c560(L23c* l, s32 i) asm("func_0023c560");
s32 func_0023c560(L23c* l, s32 i) { u32 c = l->cur * 20; u8* e = (u8*)l->ent; I20* x = (I20*)((u8*)l->idx + c); e += (x->base + i) * 24; return ((E24*)e)->c; }
}  // namespace n0023c4f0

// 0023c598 (was src/anon/misc_2.cpp)
namespace n0023c598 {
/*TARGET 0023c598*/
void func_0023c598(void* self) asm("_Z13func_0023c598Pv");
void func_0023c598(void* self) { *(s32*)((char*)self + 64) = 0; }
}  // namespace n0023c598

// 0023c5a0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023c5a0 {
// find_entry_in_group
extern "C" u32 func_0023c5f0(...) asm("func_0023c5f0");
u32 func_0023ca30(...) asm("func_0023ca30");
/*TARGET 0023c5a0*/
u32 func_0023c5a0(u32 a0) asm("_Z13func_0023c5a0j");
u32 func_0023c5a0(u32 a0) {
    s32 s1 = (s32)func_0023c5f0(a0) - 1;
    s32 v0 = (s32)func_0023ca30(a0, 0);
    if (v0 != 0) {
        if (v0 < s1) {
            s1 = v0;
        }
    }
    return (u32)s1;
}
}  // namespace n0023c5a0

// 0023c5f0 (was src/anon/batch_w86.cpp)
namespace n0023c5f0 {
struct Grp { u16 first; u16 n; u8 p4[16]; };
struct Ent { s32 f0; s32 idx; s32 arg; s32 add; u8 p16[8]; };
struct Item { u8 p0[344]; };
struct Obj { u8 p0[16]; Ent* ents; Grp* grps; u8 p24[20]; Item* items; };
s32 func_00239b50(Item*, s32) asm("func_00239b50");
/*TARGET 0023c5f0*/
// find_entry_in_group
s32 func_0023c5f0(Obj* o, s32 g) asm("func_0023c5f0");
// find_entry_in_group
s32 func_0023c5f0(Obj* o, s32 g)
{
    Grp* gp = &o->grps[g];
    Ent* e = &o->ents[gp->first];
    s32 best = 0;
    for (s32 i = 0; i < gp->n; i++, e++) {
        s32 v = func_00239b50(&o->items[e->idx], e->arg) + e->add;
        if (best < v) best = v;
    }
    return best;
}
}  // namespace n0023c5f0

// 0023c6b8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023c6b8 {
extern f32 D_00349e14 asm("D_00349e14");
// find_entry_in_group
extern "C" u32 func_0023c5f0(...) asm("func_0023c5f0");
/*TARGET 0023c6b8*/
f32 func_0023c6b8(u32 a0) asm("_Z13func_0023c6b8j");
f32 func_0023c6b8(u32 a0) {
    u32 s0 = a0;
    s32 v0 = (s32)func_0023c5f0(s0);
    return (f32)v0 * D_00349e14 * *(f32*)(s0 + 72);
}
}  // namespace n0023c6b8

// 0023c6f8 (was src/anon/batch_w6.cpp)
namespace n0023c6f8 {
// 0x00234720: definition moved into src/anon/unit_002335e8.cpp

void func_0023c728(u32*) asm("func_0023c728");
void func_0023c598(u32*) asm("func_0023c598");
/*TARGET 0023c6f8*/
void func_0023c6f8(u32* p) asm("func_0023c6f8");
void func_0023c6f8(u32* p) {
    func_0023c728(p);
    p[14] = 1;
    func_0023c598(p);
}
}  // namespace n0023c6f8

// 0023c728 (was src/anon/batch_w294.cpp)
namespace n0023c728 {
struct Ent { union { u16 f0; u8 fx; }; u16 f2; u8 pad[16]; };
struct Seg { s32 f0; s32 f4; s32 f8; s32 pad[3]; };
// Item's constructor is func_00239700; the mangled name is equated to it below.
struct Item {
    Item();
    virtual ~Item();
    u8 pad[64];
    f32 f68;
    u8 pad2[272];
    static void* operator new[](unsigned int n, void* h) asm("_Znaj");
    static void operator delete[](void* p) asm("_ZdaPv");
};
asm(".equ _ZN9n0023c7284ItemC1Ev, _ZN2YI8SEQUENCEC1Ev");
struct Obj {
    u32 f0; void* f4; u8* f8; u8 pad0[4]; Seg* f16; Ent* f20; s32* f24; u8 pad1[12];
    void* f40; u8 pad2[4]; Item* f48; union { s32 f52; u8 c52; }; u8 pad3[8]; f32 f64; f32 f68; f32 f72; s32 f76; u8 f80;
};
u8* GetImage294(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void wtarget294_00239bf8(void*, s32) asm("_Z16wtarget_00239bf8jjjj");
s32 func_0023c5a0(Obj*, s32) asm("func_0023c5a0");
void func_00239988(Item*, u8*, u8*) asm("func_00239988");
u8 func_0023c978(Obj*) asm("func_0023c978");
/*TARGET 0023c728*/
void func_0023c728(Obj* o, s32 idx) asm("func_0023c728");
void func_0023c728(Obj* o, s32 idx) {
    o->f76 = idx;
    Ent* e = &o->f20[idx];
    o->f52 = e->f2;
    delete[] o->f48;
    o->f48 = new (o->f4) Item[o->f52];
    f32 r = func_0023c5a0(o, idx);
    o->f68 = r;
    if (r < o->f64) o->f64 = r;
    o->f68 = o->f68 + 1.0f;
    Seg* s = &o->f16[e->f0];
    for (s32 i = 0; i < o->f52; i++) {
        u8* img = GetImage294(o->f40, s->f0);
        func_00239988(&o->f48[i], o->f8 + o->f24[s->f4], img);
        wtarget294_00239bf8(&o->f48[i], s->f8);
        s++;
        Item& it = o->f48[i]; it.f68 = o->f72;
    }
    o->f80 = func_0023c978(o);
}
}  // namespace n0023c728

// 0023c900 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023c900 {
/*TARGET 0023c900*/
u32 func_0023c900(u32 a0) asm("_Z13func_0023c900j");
u32 func_0023c900(u32 a0) {
    if ((u32)(*(u32*)(a0 + 56) - 1) < 2) {
        if (*(u8*)(a0 + 80) == 0) {
            f32 f1 = *(volatile f32*)(a0 + 68);
            f32 f0 = *(volatile f32*)(a0 + 64);
            if (f1 <= f0) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
}  // namespace n0023c900

