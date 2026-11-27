// Unit 0x1664c0-0x1672c8: texture/display helpers and the screen fade (D_004f4240), up to this file's
// _GLOBAL__D_ stub. 0x166148 before it is whole asm (batch_w3933.s); 0x165f70 is unit_00165f70.cpp.
// 0x1672c8 after the D stub is the first function of the next (pad/IOP) file.
#include "../common/types.h"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_top.hpp"

// ---- 001664c0 from src/anon/batch_w98.cpp
namespace n001664c0 {
struct ImgHdr166 { u8 pad[12]; u16 dataOff; u8 pad2[5]; u8 kind; u16 w; u16 h; };
extern u8 D_004f41d0[] asm("D_004f41d0");
void func_00166148(u8*, s32, s32) asm("func_00166148");
void sceGsSetDefStoreImage(void*, s32, s16, s32, s32, s32, s16, s16) asm("sceGsSetDefStoreImage");
void func_003058a0(s32) asm("func_003058a0");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
void sceGsExecStoreImage(void*, u8*) asm("sceGsExecStoreImage");
void func_001664c0(u8* p) asm("func_001664c0");
void func_001664c0(u8* p) {
    ImgHdr166* h = (ImgHdr166*)(p + 16);
    u8* data = (u8*)h + h->dataOff;
    if ((u8)(h->kind - 6) < 2) return;
    func_00166148(p, 10240, 13568);
    s32 x = 0, y = 0, z = 0;
    switch (h->kind) {
    case 4:
        x = h->w >> 7;
        y = h->w >> 1;
        z = h->h >> 2;
        h->kind = 6;
        break;
    case 5:
        x = h->w >> 7;
        y = h->w >> 1;
        z = h->h >> 1;
        h->kind = 7;
        break;
    }
    sceGsSetDefStoreImage(D_004f41d0, 10240, x, 0, 0, 0, y, z);
    func_003058a0(0);
    sceGsSyncPath(0, 0);
    sceGsExecStoreImage(D_004f41d0, data);
}
}  // namespace n001664c0

// ---- 001665d8 from src/anon/auto200_999.cpp
namespace n001665d8 {
u32 func_001665d8(u32 a0, u32 *a1, u32 *a2, u32 *a3, u32 *a4, u32 *a5,
                  u32 *a6) asm("_Z13func_001665d8jPjS_S_S_S_S_");
u32 func_001665d8(u32 a0, u32 *a1, u32 *a2, u32 *a3, u32 *a4, u32 *a5,
                  u32 *a6) {
    u32 p = a0 + 16;
    *a1 = *(u16 *)(p + 20);
    *a2 = *(u16 *)(p + 22);
    *a3 = *(u32 *)(p + 24);
    *a4 = *(u32 *)(p + 32);
    *a5 = *(u32 *)(a0 + 16);
    *a6 = *(u32 *)(p + 4);
    return *(u32 *)(p + 40);
}
}  // namespace n001665d8

// ---- 00166618 from src/anon/batch_w65.cpp
namespace n00166618 {
extern u8 D_0034c7b0[] asm("D_0034c7b0");
void sceGsSetDefLoadImage(void*, s32, s32, s32, s32, s32, s32, s32) asm("sceGsSetDefLoadImage");
void func_003058a0(s32) asm("func_003058a0");
void sceGsExecLoadImage(void*, u32) asm("sceGsExecLoadImage");
void func_00166618(u32 a, s16 b, s16 c, s16 d, s16 e, s16 f, s32 i) asm("func_00166618");
void func_00166618(u32 a, s16 b, s16 c, s16 d, s16 e, s16 f, s32 i) {
    u8* s = D_0034c7b0 + i * 96;
    sceGsSetDefLoadImage(s, c, d >> 6, b, 0, f, d, e);
    func_003058a0(0);
    sceGsExecLoadImage(s, a);
}
}  // namespace n00166618

// ---- 001666a0 from src/anon/tiny_auto80.cpp
namespace n001666a0 {
void func_001666a0(u32, u32, u32, u32) asm("_Z13func_001666a0jjjj");
void func_001666a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001666a0jjjj");
struct R { u32 w0; u16 h4; u16 h6; u16 h8; };
void func_001666a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    R* p = (R*)a0;
    p->w0 = 0;
    p->h4 = 0;
    p->h6 = 0;
    p->h8 = 0;
}
}  // namespace n001666a0

// ---- 001666b8 gap: second copy of 0x1666a0 (clear the rect)
namespace n001666b8 {
void func_001666b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001666b8");
void func_001666b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0;
    *(volatile u16*)((u32)r4 + (s32)(8)) = (u16)0u;
    *(u32*)((u32)r4 + (s32)(0)) = 0u;
    *(volatile u16*)((u32)r4 + (s32)(4)) = (u16)0u;
    *(volatile u16*)((u32)r4 + (s32)(6)) = (u16)0u;
}
}  // namespace n001666b8

// ---- 001666d0 from src/anon/tiny_auto80_solver.cpp
namespace n001666d0 {
void func_001666d0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001666d0jjjjjjjj");
void func_001666d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001666d0jjjjjjjj");
void func_001666d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    a1 &= 0xffff;
    *(u32*)a0 = a2;
    a3 &= 0xffff;
    *(u16*)(a0 + 8) = a1;
    a4 &= 0xffff;
    *(u16*)(a0 + 4) = a3;
    *(u16*)(a0 + 6) = a4;
}
}  // namespace n001666d0

// ---- 001666f0 from src/anon/tiny_auto80_solver.cpp
namespace n001666f0 {
void func_001666f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001666f0jjjjjjjj");
void func_001666f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    a1 &= 0xffff;
    *(u32*)a0 = a2;
    a3 &= 0xffff;
    *(u16*)(a0 + 8) = a1;
    a4 &= 0xffff;
    *(u16*)(a0 + 4) = a3;
    *(u16*)(a0 + 6) = a4;
}
}  // namespace n001666f0

// ---- 00166710 gap: third copy of the rect setter 0x1666d0
namespace n00166710 {
void func_00166710(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00166710");
void func_00166710(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    a1 &= 0xffff;
    *(u32*)a0 = a2;
    a3 &= 0xffff;
    *(u16*)(a0 + 8) = a1;
    a4 &= 0xffff;
    *(u16*)(a0 + 4) = a3;
    *(u16*)(a0 + 6) = a4;
}
}  // namespace n00166710

// ---- 00166730 from src/anon/batch_w51.cpp
namespace n00166730 {
u32 func_001667d0(u16) asm("func_001667d0");
struct TexInfo { u32 w0; u16 h4; u16 h6; u16 h8; };
u64 func_00166730(TexInfo* t) asm("func_00166730");
u64 func_00166730(TexInfo* t) {
    u32 lg = func_001667d0(t->h4);
    return (u64)(u32)(t->w0 << 5) | ((u64)(u16)(t->h4 >> 6) << 14) | ((u64)t->h8 << 20) |
           ((u64)lg << 26) | ((u64)9 << 30) | ((u64)1 << 34) | ((u64)1 << 51) | ((u64)1 << 61);
}
}  // namespace n00166730

// ---- 001667d0 from src/anon/tiny_auto80_queue.cpp
namespace n001667d0 {
u32 func_001667d0(u32 a0) asm("_Z13func_001667d0j");
u32 func_001667d0(u32 a0) {
    u32 t6 = 1u;
    u32 v0 = 0u;
    if (t6 < a0) {
        do {
            t6 = (u32)(t6 << 1);
            v0 = (u32)((s32)v0 + (1));
        } while (t6 < a0);
    }
    return v0;
}
}  // namespace n001667d0

// ---- 00166808 from src/anon/batch_w38.cpp
namespace n00166808 {
void func_001666f0(u8*, u16, u32, u16, u16) asm("func_001666f0");
void func_00166808(u8* p, u8 k, u16 a, u32 b, u16 c, u16 d, s16 x, s16 y) asm("func_00166808");
void func_00166808(u8* p, u8 k, u16 a, u32 b, u16 c, u16 d, s16 x, s16 y) {
    func_001666f0(p, a, b, c, d);
    *(s16*)(p + 10) = x;
    *(s16*)(p + 12) = y;
    p[14] = k;
}
}  // namespace n00166808

// ---- 00166880 from src/anon/batch_w39.cpp
namespace n00166880 {
void func_001666f0(u8*, u16, u32, u16, u16) asm("func_001666f0");
void func_00166880(u8* p, u8 c, u16 a, u32 b, u16 d, u16 e, s16 x, s16 y) asm("func_00166880");
void func_00166880(u8* p, u8 c, u16 a, u32 b, u16 d, u16 e, s16 x, s16 y) {
    func_001666f0(p, a, b, d, e);
    *(s16*)(p + 10) = x;
    *(s16*)(p + 12) = y;
    p[14] = c;
}
}  // namespace n00166880

// ---- 001668f8 from src/anon/batch_w14.cpp
namespace n001668f8 {
void func_001666a0(void*) asm("func_001666a0");
void func_001668f8(u8* p) asm("func_001668f8");
void func_001668f8(u8* p) {
    func_001666a0(p);
    *(s16*)(p + 12) = 0;
    p[14] = 1;
    *(s16*)(p + 10) = 0;
}
}  // namespace n001668f8

// ---- 00166930 from src/anon/batch_w15.cpp
namespace n00166930 {
void func_001666a0(void*) asm("func_001666a0");
void func_00166930(u8* p) asm("func_00166930");
void func_00166930(u8* p) {
    func_001666a0(p);
    *(u16*)(p + 12) = 0;
    *(u8*)(p + 14) = 1;
    *(u16*)(p + 10) = 0;
}
}  // namespace n00166930

// ---- 00166968 from src/anon/batch_w40.cpp
namespace n00166968 {
void func_001666d0(u8*, u16, u32, u16, u16) asm("func_001666d0");
void func_00166968(u8* p, u8 b, u16 c, u32 d, u16 e, u16 g, s16 h, s16 i) asm("func_00166968");
void func_00166968(u8* p, u8 b, u16 c, u32 d, u16 e, u16 g, s16 h, s16 i) {
    func_001666d0(p, c, d, e, g);
    p[14] = b;
    *(s16*)(p + 10) = h;
    *(s16*)(p + 12) = i;
}
}  // namespace n00166968

// ---- 001669e0 from src/anon/batch_w2406_nsa.c
namespace n001669e0 {
typedef unsigned long u_long;
typedef struct { u_long EN1:1; u_long EN2:1; u_long CRTMD:3; u_long MMOD:1; u_long AMOD:1; u_long SLBG:1; u_long ALP:8; u_long p0:48; } sceGsPmode;
typedef struct { u_long INT:1; u_long FFMD:1; u_long DPMS:2; u_long p0:60; } sceGsSmode2;
typedef struct { u_long FBP:9; u_long FBW:6; u_long PSM:5; u_long p0:12; u_long DBX:11; u_long DBY:11; u_long p1:10; } sceGsDispfb;
typedef struct { u32 DX:12; u32 DY:11; u32 MAGH:4; u32 MAGV:2; u32 p0:3; u32 DW:12; u32 DH:11; u32 p1:9; } __attribute__((aligned(8))) sceGsDisplay;
typedef struct { u_long R:8; u_long G:8; u_long B:8; u_long p0:40; } sceGsBgcolor;
typedef struct { sceGsPmode pmode; sceGsSmode2 smode2; sceGsDispfb dispfb; sceGsDisplay display; sceGsBgcolor bgcolor; } sceGsDispEnv;
#define SCE_GS_SET_DISPFB(fbp, fbw, psm, dbx, dby) \
    ((u_long)(fbp) | ((u_long)(fbw) << 9) | ((u_long)(psm) << 15) | ((u_long)(dbx) << 32) | ((u_long)(dby) << 43))
#define SCE_GS_SET_DISPLAY(dx, dy, magh, magv, dw, dh) \
    ((u_long)(dx) | ((u_long)(dy) << 12) | ((u_long)(magh) << 23) | ((u_long)(magv) << 27) | ((u_long)(dw) << 32) | ((u_long)(dh) << 44))
typedef struct { u32 fbp; s16 w, h, psm, x, y; u8 direct; } Screen1669e0;
extern u16 D_0034c870 asm("D_0034c870");
extern u16 D_0034c872 asm("D_0034c872");
extern u16 D_0034c874 asm("D_0034c874");
extern u16 D_0034c876 asm("D_0034c876");
void func_00242980(s32*, s32*) asm("func_00242980");
void sceGsSetDefDispEnv(sceGsDispEnv*, s16, s16, s16, s16, s16) asm("sceGsSetDefDispEnv");
void sceGsPutDispEnv(sceGsDispEnv*) asm("sceGsPutDispEnv");
void func_001669e0(Screen1669e0* s) asm("func_001669e0");
void func_001669e0(Screen1669e0* s)
{
    sceGsDispEnv env;
    s32 ox = 0, oy = 0;
    u16 dx, dy;
    func_00242980(&ox, &oy);
    dx = ox; dy = oy;
    D_0034c870 = dx;
    D_0034c872 = dy;
    *(u64*)0x120000d0 = 0;
    sceGsSetDefDispEnv(&env, s->psm, s->w, s->h, D_0034c874 + (s->x + dx), D_0034c876 + (s->y + dy));
    env.dispfb.FBP = s->fbp;
    sceGsPutDispEnv(&env);
    if (s->direct) {
        *(u64*)0x12000000 = 0x7f23;
        *(u64*)0x12000070 = SCE_GS_SET_DISPFB(s->fbp, (u16)s->w >> 6, (u16)s->psm, 0, 0);
        *(u64*)0x12000090 = SCE_GS_SET_DISPFB(s->fbp, (u16)s->w >> 6, (u16)s->psm, 0, 0);
        *(u64*)0x12000080 = SCE_GS_SET_DISPLAY(env.display.DX, env.display.DY, env.display.MAGH, env.display.MAGV, env.display.DW, env.display.DH);
        *(u64*)0x120000a0 = SCE_GS_SET_DISPLAY(env.display.DX, env.display.DY - 1U, env.display.MAGH, env.display.MAGV, env.display.DW, env.display.DH);
    }
}
}  // namespace n001669e0

// ---- 00166c58 gap: byte setter at +14
namespace n00166c58 {
void func_00166c58(u8* p, u8 v) asm("func_00166c58");
void func_00166c58(u8* p, u8 v) {
    p[14] = v;
}
}  // namespace n00166c58

// ---- 00166c68 gap: clear the display offset
namespace n00166c68 {
extern s16 D_0034c874 asm("D_0034c874");
extern s16 D_0034c876 asm("D_0034c876");
void func_00166c68() asm("func_00166c68");
void func_00166c68() {
    D_0034c874 = 0;
    D_0034c876 = 0;
}
}  // namespace n00166c68

// ---- 00166c80 from src/anon/batch_w3.cpp
namespace n00166c80 {
extern s16 D_0034c874 asm("D_0034c874");
extern s16 D_0034c876 asm("D_0034c876");
void func_00166c80(s16 a, s16 b) asm("func_00166c80");
void func_00166c80(s16 a, s16 b) {
    D_0034c874 = a;
    D_0034c876 = b;
}
}  // namespace n00166c80

// ---- 00166ca8 gap: read the display offset
namespace n00166ca8 {
extern u16 D_0034c874 asm("D_0034c874");
extern u16 D_0034c876 asm("D_0034c876");
void func_00166ca8(u16* x, u16* y) asm("func_00166ca8");
void func_00166ca8(u16* x, u16* y) {
    *x = D_0034c874;
    *y = D_0034c876;
}
}  // namespace n00166ca8

// ---- 00166cc8 from src/anon/tiny_auto80_solver.cpp
namespace n00166cc8 {
u32 func_001a2478(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001a2478jjjjjjjj");
u32 func_00166cc8(u32 a0) asm("_Z13func_00166cc8j");
u32 func_00166cc8(u32 a0) {
    u32 v = 0;
    if (a0 != 0) {
        v = ((u32(*)(u32))func_001a2478)(*(u32*)(a0 + 1164));
    }
    return v;
}
}  // namespace n00166cc8

// ---- 00166cf0 from src/anon/tiny_auto80_fptr4.cpp
namespace n00166cf0 {
u32 func_00166cf0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00166cf0jjjj");
u32 func_00166cf0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r2 = 0u;
    if (r4 != 0u) {
        r15 = *(u32*)((u32)r4 + (s32)(2040));
        r15 = (u32)(r15 & 0x0004u);
        r2 = ((u32)0u < (u32)r15);
    }
    return r2;
}
}  // namespace n00166cf0

// ---- 00166d10 from src/anon/tiny_auto80_queue.cpp
namespace n00166d10 {
u32 func_00166d10(...) asm("_Z13func_00166d10ii");
f32 func_00166d10(s32 a0, s32 a1) asm("_Z13func_00166d10ii");
f32 func_00166d10(s32 a0, s32 a1) {
    return (f32)a0 / (f32)a1;
}
}  // namespace n00166d10

// ---- 00166d38 from src/anon/tiny_auto80_queue.cpp
namespace n00166d38 {
f32 func_00166d10(s32, s32) asm("_Z13func_00166d10ii");
f32 func_00166d38(u32 a0) asm("_Z13func_00166d38j");
f32 func_00166d38(u32 a0) {
    if (a0 == 0u) {
        return 0.0f;
    }
    u32 t7 = *(u32*)((u32)a0 + (s32)(1164));
    u32 y = *(u32*)((u32)t7 + (s32)(4));
    u32 x = *(u32*)((u32)t7 + (s32)(0));
    return func_00166d10(x, y);
}
}  // namespace n00166d38

// ---- 00166d70 from src/anon/tiny_auto80_queue.cpp
namespace n00166d70 {
f32 func_00166d10(s32, s32) asm("_Z13func_00166d10ii");
f32 func_00166d70(u32 a0) asm("_Z13func_00166d70j");
f32 func_00166d70(u32 a0) {
    if (a0 == 0u) {
        return 0.0f;
    }
    u32 t7 = *(u32*)((u32)a0 + (s32)(1164));
    u32 y = *(u32*)((u32)t7 + (s32)(388));
    u32 x = *(u32*)((u32)t7 + (s32)(384));
    return func_00166d10(x, y);
}
}  // namespace n00166d70

// ---- 00166da8 from src/anon/batch_w3940_nsa.cpp
namespace n00166da8 {
struct Src166da8 { u8 on; u8 mode; u8 pad[2]; s32 z; };
extern u64 D_0034c990[] asm("D_0034c990");
extern u64 D_0034caf0[] asm("D_0034caf0");
extern u8 D_0034cce0[] asm("D_0034cce0");
extern u8 D_0034d150[] asm("D_0034d150");
extern u8 D_0034d180[] asm("D_0034d180");
void func_0014d8d0(void*) asm("func_0014d8d0");
void func_00166da8(Src166da8* p) asm("func_00166da8");
void func_00166da8(Src166da8* p)
{
    if (!p->on) return;
    if (!p->mode) {
        D_0034c990[4] = ((u64)p->z << 32) | 0x73007000;
        D_0034c990[5] = ((u64)p->z << 32) | 0x8d009000;
        D_0034caf0[3] = 0x180808080ULL;
        D_0034caf0[5] = ((u64)p->z << 32) | 0x72e06fe0;
        D_0034caf0[7] = ((u64)p->z << 32) | 0x8ce08fe0;
        D_0034caf0[9] = 0x140808080ULL;
        D_0034caf0[11] = ((u64)p->z << 32) | 0x72c06fc0;
        D_0034caf0[13] = ((u64)p->z << 32) | 0x8cc08fc0;
        D_0034caf0[15] = 0x140808080ULL;
        D_0034caf0[17] = ((u64)p->z << 32) | 0x73007000;
        D_0034caf0[19] = ((u64)p->z << 32) | 0x8d009000;
        D_0034caf0[21] = 0x140808080ULL;
        D_0034caf0[23] = ((u64)p->z << 32) | 0x73006fc0;
        D_0034caf0[25] = ((u64)p->z << 32) | 0x8d008fc0;
        D_0034caf0[27] = 0x140808080ULL;
        D_0034caf0[29] = ((u64)p->z << 32) | 0x72c07000;
        D_0034caf0[31] = ((u64)p->z << 32) | 0x8cc09000;
        D_0034caf0[33] = 0x120808080ULL;
        D_0034caf0[35] = ((u64)p->z << 32) | 0x72c06fe0;
        D_0034caf0[37] = ((u64)p->z << 32) | 0x8cc08fe0;
        D_0034caf0[39] = 0x120808080ULL;
        D_0034caf0[41] = ((u64)p->z << 32) | 0x72e06fc0;
        D_0034caf0[43] = ((u64)p->z << 32) | 0x8ce08fc0;
        D_0034caf0[45] = 0x120808080ULL;
        D_0034caf0[47] = ((u64)p->z << 32) | 0x73006fe0;
        D_0034caf0[49] = ((u64)p->z << 32) | 0x8d008fe0;
        D_0034caf0[51] = 0x120808080ULL;
        D_0034caf0[53] = ((u64)p->z << 32) | 0x72e07000;
        D_0034caf0[55] = ((u64)p->z << 32) | 0x8ce09000;
        func_0014d8d0(D_0034cce0);
    } else {
        D_0034caf0[3] = 0x120808080ULL;
        D_0034caf0[5] = ((u64)p->z << 32) | 0x72d06fe0;
        D_0034caf0[7] = ((u64)p->z << 32) | 0x8cd08fe0;
        D_0034caf0[9] = 0x120808080ULL;
        D_0034caf0[11] = ((u64)p->z << 32) | 0x72e06fd0;
        D_0034caf0[13] = ((u64)p->z << 32) | 0x8ce08fd0;
        D_0034caf0[15] = 0x120808080ULL;
        D_0034caf0[17] = ((u64)p->z << 32) | 0x72f06fe0;
        D_0034caf0[19] = ((u64)p->z << 32) | 0x8cf08fe0;
        D_0034caf0[21] = 0x120808080ULL;
        D_0034caf0[23] = ((u64)p->z << 32) | 0x72e06ff0;
        D_0034caf0[25] = ((u64)p->z << 32) | 0x8ce08ff0;
        D_0034caf0[27] = 0x180808080ULL;
        D_0034caf0[29] = 0x3a9872e06fe0ULL;
        D_0034caf0[31] = 0x3a988ce08fe0ULL;
        D_0034caf0[33] = 0x140808080ULL;
        D_0034caf0[35] = 0x3a9872c06fe0ULL;
        D_0034caf0[37] = 0x3a988cc08fe0ULL;
        D_0034caf0[39] = 0x140808080ULL;
        D_0034caf0[41] = 0x3a9872e06fc0ULL;
        D_0034caf0[43] = 0x3a988ce08fc0ULL;
        D_0034caf0[45] = 0x140808080ULL;
        D_0034caf0[47] = 0x3a9873006fe0ULL;
        D_0034caf0[49] = 0x3a988d008fe0ULL;
        D_0034caf0[51] = 0x140808080ULL;
        D_0034caf0[53] = 0x3a9872e07000ULL;
        D_0034caf0[55] = 0x3a988ce09000ULL;
        func_0014d8d0(D_0034d150);
    }
    func_0014d8d0(D_0034d180);
}
}  // namespace n00166da8

// ---- 001671e8 from src/anon/batch_w6.cpp
namespace n001671e8 {
struct S4240 { u8 flag; u8 b; u8 pad[2]; s32 time; };
extern S4240 D_004f4240 asm("D_004f4240");
void func_001671e8(s32 t, u8 b) asm("func_001671e8");
void func_001671e8(s32 t, u8 b) {
    if (t < 15000) t = 15000;
    D_004f4240.time = t;
    D_004f4240.flag = 1;
    D_004f4240.b = b;
}
}  // namespace n001671e8

// ---- 00167218 from src/anon/tiny.cpp
namespace n00167218 {
void func_00167218(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00167218jjjj");
void func_00167218(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x004fu << 16);
    *(u8*)((u32)b + (16960)) = (u8)0;
}
}  // namespace n00167218

// ---- 00167228 from src/anon/tiny_auto80_queue.cpp
namespace n00167228 {
u32 func_00166da8(...) asm("func_00166da8");
u32 func_00167218(...) asm("func_00167218");
extern u8 D_004f4240 asm("D_004f4240");
u32 func_00167228(u32 a0) asm("_Z13func_00167228j");
u32 func_00167228(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)(*(u8*)((u32)r4 + (s32)(4)));
    r16 = r4;
    if (r15 == 0u) {
        r2 = ((u32(*)(u32))func_00167218)(r4);
        r15 = (u32)((s32)0u + (1));
        *(u8*)((u32)r16 + (s32)(4)) = (u8)r15;
    }
    return ((u32(*)(u32))func_00166da8)((u32)&D_004f4240);
}
}  // namespace n00167228

// ---- 00167268 from src/anon/batch_w1667.cpp
namespace n00167268 {
extern u8 D_004f4240 asm("D_004f4240");
void wtarget_00167268(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00167268jjjj");
void wtarget_00167268(u32 a, u32 b, u32 c, u32 d) {
    if (b == 0xffff && a == 1) D_004f4240 = 0;
}
}  // namespace n00167268

// ---- 00167288 from src/anon/tiny_wrappers_more.cpp
namespace n00167288 {
u32 func_00167268(u32, u32, u32, u32) asm("_Z13func_00167268jjjj");
u32 func_00167288(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00167288jjjj");
u32 func_00167288(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00167268(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00167288

// ---- 001672a8 gap: _GLOBAL__D_ stub of the 0x167268 static init
namespace n001672a8 {
u32 func_00167268(u32, u32, u32, u32) asm("_Z13func_00167268jjjj");
u32 func_001672a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001672a8");
u32 func_001672a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00167268(0x00000000u, 0x0000ffffu, a2, a3);
}
}  // namespace n001672a8

