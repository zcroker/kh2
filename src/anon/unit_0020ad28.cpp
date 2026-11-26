// Linked unit 0x0020ad28-0x0020b4e8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
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
#include <stdarg.h>

// 0020ad28 (was gap, written for the unit)
namespace n0020ad28 {
struct VG { f32 x, y, z, w; } __attribute__((aligned(16)));
struct EmG { u8* parts; u8* work; s32 count; f32 f12; u16 timer; u8 on; };
struct CtxG { u8 pad0[12]; s32* off; };
extern u8* D_01d9e6e4 asm("D_01d9e6e4");
extern VG D_01d9e7f0 asm("D_01d9e7f0");
extern VG D_00354bc0 asm("D_00354bc0");
u8* func_001e7698(u8*, s32) asm("func_001e7698");
void wtarget_002fde18(u8*, s32, s32) asm("_Z16wtarget_002fde18jjjj");
void sceVu0SubVector(VG*, VG*, VG*) asm("sceVu0SubVector");
s32 func_0020a060(EmG*, u8*) asm("_Z13func_0020a060PhS_");
void func_0020ab48(EmG*, u8*, u8*) asm("func_0020ab48");
void func_0020ad28(u8* base, u8* d, CtxG* c) asm("func_0020ad28");
void func_0020ad28(u8* base, u8* d, CtxG* c) {
    u8* b = base + c->off[2];
    u8* w = base + c->off[1] + 160;
    EmG* e = (EmG*)(b + 160);
    if (*(u8**)(b + 160) == 0) {
        e->count = *(u16*)(d + 14);
        if ((*(u8**)(b + 160) = func_001e7698(D_01d9e6e4, e->count * 96)) != 0)
            wtarget_002fde18(*(u8**)(b + 160), 0, e->count * 96);
        if (d[182]) {
            if ((e->work = func_001e7698(D_01d9e6e4, e->count << 5)) != 0)
                wtarget_002fde18(e->work, 0, e->count << 5);
        }
    }
    if (!func_0020a060(e, d)) return;
    if (d[180]) {
        VG v;
        f32 len;
        sceVu0SubVector(&v, &D_01d9e7f0, &D_00354bc0);
        asm volatile(
            "lqc2 $vf10,0(%1)\n"
            "vmul.xyz $vf10,$vf10,$vf10\n"
            "vaddx.y $vf10,$vf10,$vf10x\n"
            "vaddy.z $vf10,$vf10,$vf10y\n"
            "vsqrt Q,$vf10z\n"
            "vwaitq\n"
            "vaddq.x $vf10,$vf0,Q\n"
            "qmfc2 %0,$vf10\n" : "=r"(len) : "r"(&v));
        if (*(f32*)(d + 172) < len) {
            e->on = 0;
        } else {
            e->on = 1;
            if (*(f32*)(d + 172) - len < *(f32*)(d + 176)) e->f12 = (*(f32*)(d + 172) - len) / *(f32*)(d + 176);
            else e->f12 = 1.0f;
        }
    }
    if (e->on) func_0020ab48(e, d, w);
}
}  // namespace n0020ad28

// 0020aec0 (was src/anon/misc_2.cpp)
namespace n0020aec0 {
/*TARGET 0020aec0*/
void func_0020aec0(void* self) asm("_Z13func_0020aec0Pv");
void func_0020aec0(void* self) {}
}  // namespace n0020aec0

// 0020aec8 (was src/anon/batch_wcx2.cpp)
namespace n0020aec8 {
// 0x001d9b40: definition moved into src/anon/unit_001d7458.cpp

extern f32 D_00354be0[3] asm("D_00354be0");
extern u8 D_01d9e730[] asm("D_01d9e730");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0UnitMatrix(f32 (*)[4]) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0RotMatrixZ(f32 (*)[4], f32 (*)[4], f32) asm("sceVu0RotMatrixZ");
void sceVu0CopyVector(f32*, u8*) asm("sceVu0CopyVector");
// memcpy16
void sceVu0ApplyMatrix(f32*, u8*, f32*) asm("sceVu0ApplyMatrix");
void sceVu0MulMatrix(f32 (*)[4], u8*, f32 (*)[4]) asm("sceVu0MulMatrix");
/*TARGET 0020aec8*/
f32 func_0020aec8(u32 a0, f32 (*m)[4], u8* a2, u32 a3, u8* s) asm("func_0020aec8");
f32 func_0020aec8(u32 a0, f32 (*m)[4], u8* a2, u32 a3, u8* s)
{
    sceVu0UnitMatrix(m);  // vu_store_w_splat
    m[0][0] = *(f32*)(s + 56) * D_00354be0[0];
    m[1][1] = *(f32*)(s + 60) * D_00354be0[1];
    m[2][2] = *(f32*)(s + 56) * D_00354be0[0];
    if (*(f32*)(s + 44) != 0.0f) sceVu0RotMatrixZ(m, m, *(f32*)(s + 44) * 3.14159274f / 180.0f);
    sceVu0CopyVector(m[3], s);  // memcpy16
    sceVu0ApplyMatrix(m[3], D_01d9e730, m[3]);
    f32 z = m[3][2];
    m[3][1] *= *(f32*)(a2 + 164);
    m[3][1] += *(f32*)(a2 + 168);
    sceVu0MulMatrix(m, D_01d9e8c0, m);
    return z;
}
}  // namespace n0020aec8

// 0020aff8 (was src/anon/batch_w2418_nsa.cpp)
namespace n0020aff8 {
typedef struct W2418Pk { u16 a0; u16 flags; u8 c[4]; u64 f8; void* f10; s32 f14; u8 f18; u32 f1c; u8 pad[16]; } W2418Pk;
typedef struct W2418It { u8 p0[0x24]; u16 f24; u16 f26; s8 c[4]; u8 p2c[0x54 - 0x2c]; f32 f54; u64 f58; } W2418It;
typedef struct W2418Vc { f32 x, y, z, w; u8 p10[16]; } W2418Vc;
typedef struct W2418Q { W2418It* it; W2418Vc* v; s32 n; f32 scale; u8 p10[2]; u8 f12; } W2418Q;
typedef struct W2418T { s32 a; s32 b; s32 c; } W2418T;
typedef struct W2418A2 { u8 p0[0xc]; W2418T* fc; } W2418A2;
typedef struct W2418A1 { u32 p0; s32 f4; u8 p8[4]; u8 fc; u8 p0d[0x94 - 0xd]; f32 f94; f32 f98; } W2418A1;
typedef struct W2418E { u8* data; s32 x; } W2418E;
typedef struct W2418O { u8 p0[0x14]; W2418E* f14; } W2418O;
extern W2418O* D_01d9e6e4 asm("D_01d9e6e4");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
s32 func_0021d048(u8*, W2418Pk*, s32) asm("func_0021d048");
s32 func_0020a060(W2418Q*, W2418A1*) asm("func_0020a060");
void func_0020aec0(void*, W2418A1*, W2418Q*) asm("func_0020aec0");
f32 func_0020aec8(void*, f32 (*)[4], W2418A1*, W2418Q*, W2418It*) asm("func_0020aec8");
/*TARGET 0020aff8*/
void pppRyjDrawMegaBirth(u8* a0, W2418A1* a1, W2418A2* a2) asm("pppRyjDrawMegaBirth");
void pppRyjDrawMegaBirth(u8* a0, W2418A1* a1, W2418A2* a2) {
    W2418Q* q = (W2418Q*)(a0 + a2->fc->c + 0xa0);
    W2418It* it = q->it;
    W2418Vc* v = q->v;
    u8* col = a0 + a2->fc->b + 0xa0;
    s32 n = q->n;
    if (func_0020a060(q, a1) && q->f12) {
        s32 id = a1->f4;
        if (__builtin_expect(id != 0xffff, 1)) {
            u8 bufA[64];
            f32 m[4][4] __attribute__((aligned(16)));
            W2418Pk p;
            W2418E* e;
            s32 cr, cg, cb, ca;
            u8* data;
            s32 i;
            func_0020aec0(bufA, a1, q);
            e = &D_01d9e6e4->f14[id];
            p.flags = 16;
            if (a1->fc) p.flags = 0x810;
            p.f1c = 0;
            p.f8 = 0;
            p.f18 = 0;
            p.f10 = m;
            data = e->data;
            cr = col[8];
            cg = col[9];
            cb = col[10];
            ca = col[11];
            for (i = 0; i < n; i++) {
                if (it->f26 != 0 && !(it->f58 & 0x100)) {
                    f32 d = func_0020aec8(bufA, m, a1, q, it);
                    f32 nr = a1->f94;
                    f32 w = a1->f98;
                    s32 r, g, b, al;
                    u8* a;
                    if (d < nr - w) {
                        it->f54 = 0.0f;
                    } else if (d < nr) {
                        it->f54 *= 1.0f - (nr - d) / w;
                    }
                    { s32 o = it->f24 * 8; a = data + *(s16*)(data + o + 16); }
                    r = cr + it->c[0];
                    g = cg + it->c[1];
                    b = cb + it->c[2];
                    al = ca + it->c[3];
                    if (v) {
                        r += (s32)v->x;
                        g += (s32)v->y;
                        b += (s32)v->z;
                        al += (s32)v->w;
                    }
                    if (r < 0) r = 0; else if (r >= 256) r = 255;
                    if (g < 0) g = 0; else if (g >= 256) g = 255;
                    if (b < 0) b = 0; else if (b >= 256) b = 255;
                    if (al < 0) al = 0; else if (al >= 128) al = 127;
                    p.c[3] = al;
                    p.c[0] = r;
                    p.c[1] = g;
                    p.c[2] = b;
                    p.c[3] = (s32)((f32)p.c[3] * it->f54 * q->scale);
                    if (p.c[3]) {
                        p.f14 = D_01d9eaa4;
                        D_01d9eaa4 = func_0021d048(a, &p, e->x);
                    }
                }
                it++;
                if (v) v++;
            }
        }
    }
}
}  // namespace n0020aff8

// 0020b300 (was gap, written for the unit)
namespace n0020b300 {
struct VG { f32 x, y, z, w; } __attribute__((aligned(16)));
extern VG D_01d9e7f0 asm("D_01d9e7f0");
extern VG D_01d9e800 asm("D_01d9e800");
extern VG D_01da8b90 asm("D_01da8b90");
void sceVu0SubVector(VG*, VG*, VG*) asm("sceVu0SubVector");
void sceVu0Normalize(VG*, VG*) asm("sceVu0Normalize");
void func_0020b300(void) asm("func_0020b300");
void func_0020b300(void) {
    sceVu0SubVector(&D_01da8b90, &D_01d9e800, &D_01d9e7f0);
    sceVu0Normalize(&D_01da8b90, &D_01da8b90);
    D_01da8b90.w = 1.0f;
}
}  // namespace n0020b300

// 0020b358 (was gap, written for the unit)
namespace n0020b358 {
struct EmG { u8* parts; u8* work; s32 count; f32 f12; u16 timer; u8 on; };
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_0020b358(u8* base, u8* c) asm("func_0020b358");
void func_0020b358(u8* base, u8* c) {
    EmG* e = (EmG*)(base + (*(s32**)(c + 12))[2] + 160);
    e->on = 1;
    e->work = 0;
    e->count = 0;
    e->timer = 0;
    e->f12 = 1.0f;
    e->parts = 0;
    D_01d9e6e0[171] = 1;
}
}  // namespace n0020b358

// 0020b3a0 (was src/anon/auto80_199_queue.cpp)
namespace n0020b3a0 {
/*TARGET 0020b3a0*/
void func_0020b3a0(u32 a0, u32 a1) asm("_Z13func_0020b3a0jj");
void func_0020b3a0(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6;
    u32 s1 = s0 + 160;

    u32 p0 = *(u32*)(s0 + 160);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 160) = 0;
    }

    u32 p1 = *(u32*)(s1 + 4);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s1 + 4) = 0;
    }
}
}  // namespace n0020b3a0

// 0020b410 (was src/anon/batch_w51.cpp)
namespace n0020b410 {
/*TARGET 0020b410*/
// VU0 random float (hand-written VU0 asm).
f32 func_0020b410(void) asm("func_0020b410");
// VU0 random float (hand-written VU0 asm).
f32 func_0020b410(void) {  // vu_const_5f_b
    register u32 b asm("$15");
    asm volatile(
        "addi $8, $0, -1\n\t"
        "qmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vitof0.x $vf2, $vf2\n\t"
        "vadd.x $vf1, $vf1, $vf2\n\t"
        "qmfc2 %0, $vf1"
        : "=r"(b) : : "$8");
    union { u32 u; f32 f; } c;
    c.u = b;
    return c.f;
}
}  // namespace n0020b410

// 0020b458 (was src/anon/auto80_199_queue.cpp)
namespace n0020b458 {
/*TARGET 0020b458*/
s32 func_0020b458(u32 a0) asm("_Z13func_0020b458j");
s32 func_0020b458(u32 a0) {
    u32 s0 = a0 & 0xff;
    f32 f20 = (f32)(s32)(s0 << 1);
    f32 f0 = func_0020b410(a0);  // vu_const_5f_b
    f20 = f20 * f0;
    f0 = (f32)(s32)(s0 >> 1);
    f20 = f20 - f0;
    s32 v0 = (s32)f20;
    return (s8)v0;
}
}  // namespace n0020b458

// 0020b4b8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0020b4b8 {
/*TARGET 0020b4b8*/
s32 func_0020b4b8(u8* a0, u8* a1) asm("_Z13func_0020b4b8PhS_");
s32 func_0020b4b8(u8* a0, u8* a1) {
    if (*(u32*)(a0 + 0) == 0) {
        return 0;
    }
    if (*(u8*)(a1 + 242) == 0 || *(u32*)(a0 + 4) != 0) {
        return 1;
    }
    return 0;
}
}  // namespace n0020b4b8

