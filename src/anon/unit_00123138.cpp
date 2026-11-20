// Linked unit 0x00123138-0x00123650 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00123138 (gap function, not written before)
namespace g00123138 {
struct O;
typedef u32 (*Fn)(O*, u32, u32, u32, u32, u32, u8, u32);
struct O { Fn* vt; };
u32 func_00121cc8(O*, u32, u32, u32, u32, u32, u8, u32) asm("func_00121cc8");
u32 func_00123138(O* o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u32 a7) asm("func_00123138");
u32 func_00123138(O* o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u32 a7) {
    u32 r = func_00121cc8(o, a1, a2, a3, a4, a5, a6, a7);
    if (a6) o->vt[21](o, a1, a2, a3, a4, a5, a6, a7);
    return r;
}
}  // namespace g00123138

// 001231f8 (was src/anon/batch_w9.cpp)
namespace n001231f8 {
/*TARGET 001231f8*/
// 00107300: moved to src/naka/libkn/camera.cpp

u32 func_001231f8(void* o, u32 a1, u32 a2, u32 a3, u32 t0, u8 t1, u32 t2) asm("func_001231f8");
// 00107300: moved to src/naka/libkn/camera.cpp

u32 func_001231f8(void* o, u32 a1, u32 a2, u32 a3, u32 t0, u8 t1, u32 t2) {
    return (*(u32 (**)(void*, u32, u32, u32, u32, u32, u32, u32))(*(u8**)o + 76))(o, a1, a2, a3, t0, 0, t1, t2);
}
}  // namespace n001231f8

// 00123228 (was src/anon/batch_w3721_nsa.cpp)
namespace n00123228 {
typedef unsigned int W3721bu128 __attribute__((mode(TI)));
struct W3721bTex { u8 pad[3]; u8 vis; };
struct W3721bPart { u32 w0; u8 pad[28]; };
struct W3721bMdl { u8 pad[28]; s32 count; W3721bPart parts[1]; };
struct W3721bObj { u8 pad[4]; W3721bMdl* mdl; };
struct W3721bDesc { u8 pad[4]; u8 r, g, b, a; };
// 64-byte matrix, copied with 128-bit loads/stores (hand-written asm in the original's operator=).
struct W3721bMtx {
    W3721bu128 row[4];
    W3721bMtx& operator=(const W3721bMtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W3721bHdr {
    W3721bu128 tag;      // 0
    u8 pad[40];
    f32 depth;          // 56
    u8 pad1[20];
    W3721bMtx mtx;       // 80
};
extern W3721bu128 D_00347a10 asm("D_00347a10");
s32 func_0010ae90(void) asm("func_0010ae90");
W3721bMdl* func_00120800(W3721bObj*) asm("func_00120800");
W3721bTex* func_00108930(W3721bDesc*, s32) asm("func_00108930");
s32 func_001344f8(void) asm("func_001344f8");
void func_00109360(s32, s32) asm("func_00109360");
W3721bHdr* func_00108730(W3721bDesc*, s32) asm("func_00108730");
void func_00133bb8(s32, s32, u32, u32) asm("func_00133bb8");
void func_00108f98(s32, u64) asm("func_00108f98");
void func_00109008(s32) asm("func_00109008");
void func_00133c60(s32, s32, s32, s32, s32) asm("func_00133c60");
/*TARGET 00123228*/
// Needs -fno-strict-aliasing (_nsa). Register pin (w3721): in three of the four part loops the texture
// pointer is pinned to t5 ($13); without it gcc swaps t5/t6 for the pointer and its vis byte (closest C: 8 diffs).
// Draws the visible parts of an object's model (or of its sub-model) with a per-part mask.
s32 func_00123228(W3721bObj* o, W3721bMtx* mtx, s32* ids, W3721bDesc* d, u8* mask) asm("func_00123228");
// Needs -fno-strict-aliasing (_nsa). Register pin (w3721): in three of the four part loops the texture
// pointer is pinned to t5 ($13); without it gcc swaps t5/t6 for the pointer and its vis byte (closest C: 8 diffs).
// Draws the visible parts of an object's model (or of its sub-model) with a per-part mask.
s32 func_00123228(W3721bObj* o, W3721bMtx* mtx, s32* ids, W3721bDesc* d, u8* mask)
{
    W3721bTex* tex[32];
    s32 pk = func_0010ae90();
    W3721bMdl* mdl = o->mdl;
    W3721bMdl* m2 = func_00120800(o);
    s32 n = 0;
    s32 i;
    for (i = 0; i < 32; i++) tex[i] = func_00108930(d, i);
    if (m2) {
        for (i = 0; i < m2->count; i++) {
            u8 f = mask[mdl->count + i] & 0xf;
            if (f && !(f & 4)) {
                register W3721bTex* tp asm("$13") = tex[m2->parts[i].w0 & 0x1f];
                if (tp->vis) n++;
            }
        }
        if (n) {
            s32 g = func_001344f8();
            func_00109360(g, 3);
            W3721bHdr* h = func_00108730(d, g);
            h->tag = D_00347a10;
            h->mtx = *mtx;
            for (i = 0; i < m2->count; i++) {
                u8 f = mask[mdl->count + i] & 0xf;
                if (f && !(f & 4) && tex[m2->parts[i].w0 & 0x1f]->vis) {
                    func_00133bb8(g, 0, 0x11000000, 0x13000000);
                    func_00108f98(pk, (u64)d->r | ((u64)d->g << 8) | ((u64)d->b << 16) | ((u64)d->a << 24) | (127ULL << 55));
                    func_00109008(pk);
                    func_00133c60(g, ids[mdl->count + i], 0, 0, 0);
                }
            }
        }
    } else {
        for (i = 0; i < mdl->count; i++) {
            u8 f = mask[i] & 0xf;
            if (f && !(f & 4)) {
                register W3721bTex* tp asm("$13") = tex[(mdl->parts[i].w0 >> 6) & 0x1f];
                if (tp->vis) n++;
            }
        }
        if (n) {
            s32 g = func_001344f8();
            func_00109360(g, 2);
            W3721bHdr* h = func_00108730(d, g);
            h->mtx = *mtx;
            h->depth = 100000000.0f;
            for (i = 0; i < mdl->count; i++) {
                u8 f = mask[i] & 0xf;
                if (f && !(f & 4)) {
                    register W3721bTex* tp asm("$13") = tex[(mdl->parts[i].w0 >> 6) & 0x1f];
                    if (tp->vis) {
                        func_00133bb8(g, 0, 0x11000000, 0x13000000);
                        func_00108f98(pk, (u64)d->r | ((u64)d->g << 8) | ((u64)d->b << 16) | ((u64)d->a << 24) | (127ULL << 55));
                        func_00109008(pk);
                        func_00133c60(g, ids[i], 0, 0, 0);
                    }
                }
            }
        }
    }
    return 1;
}
}  // namespace n00123228

// 00123650 (was whole asm, never written in C before)
namespace g00123650 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Tex { u8 pad[3]; u8 vis; };
struct Part { u32 w0; u8 pad[28]; };
struct Mdl { u8 pad[28]; s32 count; Part parts[1]; };
struct Obj { u8 pad[4]; Mdl* mdl; };
struct Desc { u8 pad[24]; u64 flags; u8 pad2[9]; u8 r, g, b; };
struct Mtx {
    u128 row[4];
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Hdr { u8 pad[16]; u32 r, g, b, a; u8 pad2[48]; Mtx mtx; };
struct Prim { f32 f0, f4; u32 f8, f12; f32 f16, f20; u32 f24, f28; };
s32 func_0010ae90(void) asm("func_0010ae90");
Tex* func_00108930(Desc*, s32) asm("func_00108930");
u64 func_00109048(s32) asm("func_00109048");
u64 func_00109068(s32) asm("func_00109068");
void func_0010ab80(void) asm("func_0010ab80");
void func_00108dd8(s32, u64) asm("func_00108dd8");
void func_00109008(s32) asm("func_00109008");
s32 func_001344f8(void) asm("func_001344f8");
void func_00109360(s32, s32) asm("func_00109360");
Hdr* func_00108730(Desc*, s32) asm("func_00108730");
Prim* func_00133bb8(s32, s32, u32, u32) asm("func_00133bb8");
void func_00133c60(s32, s32, s32, s32, s32) asm("func_00133c60");
u64 func_00109040(s32) asm("func_00109040");
u64 func_00109050(s32) asm("func_00109050");
u64 func_00109058(s32) asm("func_00109058");
u64 func_00109060(s32) asm("func_00109060");
void func_00108ae0(s32, u32, u64, u64, u64, u64, u64, u64) asm("func_00108ae0");
// Draws the masked (flag 4) visible parts of an object's model as a second pass.
s32 func_00123650(Obj* o, Mtx* mtx, s32* ids, Desc* d, u8* mask) asm("func_00123650");
s32 func_00123650(Obj* o, Mtx* mtx, s32* ids, Desc* d, u8* mask)
{
    Tex* tex[32];
    Mdl* mdl = o->mdl;
    s32 n = 0;
    s32 i;
    { Desc* src = d; for (i = 0; i < 32; i++) tex[i] = func_00108930(src, i); }
    for (i = 0; i < mdl->count; i++) {
        u8 f = mask[i] & 0xf;
        if (f && (f & 4)) {
            Tex* p = (Tex*)(((mdl->parts[i].w0 >> 6) & 0x1f) * 4 + (u32)tex); p = *(Tex**)p; if (p->vis) n++;
        }
    }
    if (n) {
        s32 pk = func_0010ae90();
        u32 a = func_00109048(pk);
        u32 b = func_00109068(pk);
        func_0010ab80();
        func_00108dd8(pk, d->flags & ~(1ULL << 32));
        func_00109008(pk);
        s32 g = func_001344f8();
        func_00109360(g, 4);
        Hdr* h = func_00108730(d, g);
        h->r = d->r;
        h->g = d->g;
        h->b = d->b;
        h->a = 128;
        h->mtx = *mtx;
        Prim* p = func_00133bb8(g, 2, 0x01000101, 0x6c02400a);
        p->f28 = 0;
        p->f8 = 0;
        p->f12 = 0;
        p->f24 = 0;
        p->f0 = 0.001953125f;
        p->f16 = -3.5f;
        p->f20 = -4.42307663f;
        p->f4 = 0.00240384601f;
        for (i = 0; i < mdl->count; i++) {
            u8 f = mask[i] & 0xf;
            if (f && (f & 4)) {
                Tex* p = (Tex*)(((mdl->parts[i].w0 >> 6) & 0x1f) * 4 + (u32)tex); p = *(Tex**)p;
                if (p->vis) {
                    func_00133bb8(g, 0, 0x11000000, 0x13000000);
                    func_00133c60(g, ids[i], 0, 0, 0);
                }
            }
        }
        func_00108ae0(pk, 63, func_00109040(pk), a, func_00109050(pk), func_00109058(pk), func_00109060(pk), b);
    }
    return 1;
}
}  // namespace g00123650

