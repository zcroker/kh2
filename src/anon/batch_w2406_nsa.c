#include "../common/types.h"
typedef struct { u16 qwc; u8 mark; u8 id; u32 addr; u32 vif[2]; } Tag21cdd0;
typedef struct { s16 flags; s16 counter; u32 dataOff; u8 pad8[8]; u64 tex; u8 pad24[8]; u8 data[1]; } Shape21cdd0;
typedef struct {
    u8 pad0[16];
    s32 r, g, b;
    u8 pad28[4];
    u64 tex;
    s32 flags;
    s32 counter;
    u8 pad48[112 - 48];
    u64 spr[1];
} ShpWork21cdd0;
typedef struct { u8 pad0[8]; s32 sprites; s32 masked; } ShpStat21cdd0;
extern s32 D_00352c38;
extern ShpStat21cdd0 D_01da8cd0;
extern char D_00370aa0[];
extern char D_00370ab8[];
extern char D_00370ad8[];
extern char D_00370ae8[];
void func_002fdfc8(const char*, ...);
void func_001e75a8(u32);
static inline void shpAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_00370aa0, e);
    func_002fdfc8(D_00370ae8, f, l);
    asm volatile("break");
}
void func_0021cdd0(Shape21cdd0* sh, ShpWork21cdd0* w)
{
    s32 n, q, q1;
    u64* spr;
    u64* src;
    u64* dst;
    Tag21cdd0* t;
    Tag21cdd0* p;
    if (!(sh->counter <= 8)) {
        shpAssert(D_00370ab8, D_00370ad8, 338);
    }
    if (D_00352c38) {
        w->b = w->g = w->r = (s32)((f32)w->r * 0.30000001192092896f + (f32)w->g * 0.5899999737739563f + (f32)w->b * 0.10999999940395355f);
    }
    w->flags = sh->flags;
    w->counter = sh->counter;
    w->tex = sh->tex;
    src = (u64*)((u8*)sh + sh->dataOff);
    spr = w->spr;
    dst = spr;
    n = sh->counter;
    while (n--) *dst++ = *src++;
    q = (s32)(((u64)(sh->counter * 8) + 15) & ~15) / 16;
    t = (Tag21cdd0*)((u8*)spr + q * 16);
    p = t;
    p->qwc = 7;
    p->id = 0x30;
    p->addr = (u32)w | 0x80000000;
    p->vif[0] = 0;
    p->vif[1] = 0x6c078000;
    p = t + 1;
    q1 = (s32)(((u64)sh->dataOff - 32 + 15) & ~15) / 16;
    p->qwc = q1;
    p->id = 0x30;
    p->addr = (u32)sh->data;
    p->vif[0] = 0;
    p->vif[1] = (q1 << 17) | 0x6d008007;
    p = t + 2;
    p->qwc = q;
    p->id = 0x30;
    p->addr = (u32)spr | 0x80000000;
    p->vif[0] = 0;
    p->vif[1] = (q << 18) | 0x6e00c01f;
    p = t + 3;
    p->qwc = 0;
    p->id = 0x70;
    p->addr = 0;
    p->vif[0] = 0x13000000;
    p->vif[1] = 0x17000000;
    func_001e75a8((u32)t | 0x80000000);
    if (sh->flags & 8) D_01da8cd0.masked += sh->counter;
    D_01da8cd0.sprites += sh->counter;
}

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
extern u16 D_0034c870;
extern u16 D_0034c872;
extern u16 D_0034c874;
extern u16 D_0034c876;
void func_00242980(s32*, s32*);
void func_002f20d0(sceGsDispEnv*, s16, s16, s16, s16, s16);
void func_002f2448(sceGsDispEnv*);
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
    func_002f20d0(&env, s->psm, s->w, s->h, D_0034c874 + (s->x + dx), D_0034c876 + (s->y + dy));
    env.dispfb.FBP = s->fbp;
    func_002f2448(&env);
    if (s->direct) {
        *(u64*)0x12000000 = 0x7f23;
        *(u64*)0x12000070 = SCE_GS_SET_DISPFB(s->fbp, (u16)s->w >> 6, (u16)s->psm, 0, 0);
        *(u64*)0x12000090 = SCE_GS_SET_DISPFB(s->fbp, (u16)s->w >> 6, (u16)s->psm, 0, 0);
        *(u64*)0x12000080 = SCE_GS_SET_DISPLAY(env.display.DX, env.display.DY, env.display.MAGH, env.display.MAGV, env.display.DW, env.display.DH);
        *(u64*)0x120000a0 = SCE_GS_SET_DISPLAY(env.display.DX, env.display.DY - 1U, env.display.MAGH, env.display.MAGV, env.display.DW, env.display.DH);
    }
}
