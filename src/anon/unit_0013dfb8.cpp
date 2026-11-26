#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../harata/libdk/lockon.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/dbg_smenu.hpp"
#include "../harata/libdk/objcamera.hpp"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// ---- 0013dfb8 from src/anon/auto80_199_queue.cpp
namespace n0013dfb8 {
void func_0013dfb8(u32 a0) asm("_Z13func_0013dfb8j");
void func_0013dfb8(u32 a0) {
    func_001391c8(a0);
    u32 s0 = a0 + 32;
    func_0013ee38(s0, 4);
    ((dk::Ft4Base*)s0)->setRot(0.0f);
    func_0013ee18(s0, 0x00032001u);
    func_0014b208(s0, 50, 120);
    ((dk::Ft4Base*)s0)->setCenterXY(-25, -60);
}
}  // namespace n0013dfb8

// ---- 0013e028 gap (SECTOR_MASK draw)
namespace n0013e028 {
void GetActiveXY(u8*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
void getPos(u8*, s32*, s32*) asm("_ZN2dk6Sprite6getPosERiS1_");
void getOfs(u8*, s16*, s16*) asm("func_0014b258");
void setXY(u8*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void draw(u8*) asm("func_0013eeb8");
void func_0013e028(u8* o) asm("func_0013e028");
void func_0013e028(u8* o) {
    s16 x, y;
    s32 a, b, c, d;
    if (*(u8**)(o + 320)) {
        GetActiveXY(*(u8**)(o + 320) + 24, &a, &b);
        getPos(*(u8**)(o + 320), &c, &d);
        s32 px = c + a;
        s32 py = d + b;
        x = 0;
        y = 0;
        getOfs(o + 32, &x, &y);
        px += x;
        py += y;
        setXY(o + 32, px, py);
    }
    draw(o + 32);
}
}  // namespace n0013e028

// ---- 0013e0f8 from src/anon/batch_w89.cpp
namespace n0013e0f8 {
void func_001391c8(u8*, u32, u32) asm("func_001391c8");
void func_0013ee38(u8*, u32) asm("func_0013ee38");
void func_0013edd0(u8*, f32) asm("func_0013edd0");
void func_0013ee18(u8*, u32) asm("func_0013ee18");
void func_0014b208(u8*, s32, s32) asm("func_0014b208");
void func_0013ede0(u8*, s32, s32) asm("func_0013ede0");
void func_0014b5e0(u8*, u32) asm("func_0014b5e0");
void func_0014b618(u8*, u32) asm("func_0014b618");
void func_0013e0f8(u8* o, u32 a1, u32 a2, u32 a3) asm("func_0013e0f8");
void func_0013e0f8(u8* o, u32 a1, u32 a2, u32 a3) {
    func_001391c8(o, a1, a3);
    *(u32*)(o + 580) = a2;
    u8* s = o + 32;
    func_0013ee38(s, 4);
    func_0013edd0(s, 0.0f);
    func_0013ee18(s, 0x32001);
    if (!a2) { func_0014b208(s, 100, 100); return; }
    func_0014b208(s, 64, 64);
    func_0013ede0(s, -32, -32);
    func_0014b5e0(o + 320, 6);
    func_0014b618(o + 320, 0x32001);
    func_0014b208(o + 320, 64, 64);
}
}  // namespace n0013e0f8

// ---- 0013e1c8 gap (draw with optional second rect)
namespace n0013e1c8 {
void GetActiveXY(u8*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
void getPos(u8*, s32*, s32*) asm("_ZN2dk6Sprite6getPosERiS1_");
void getOfs(u8*, u16*, u16*) asm("func_0014b258");
void setXY(u8*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void draw(u8*) asm("func_0013eeb8");
void draw2(u8*) asm("func_0014b698");
void func_0013e1c8(u8* o) asm("func_0013e1c8");
void func_0013e1c8(u8* o) {
    u16 x, y;
    s32 a, b, c, d;
    if (*(u8**)(o + 576)) {
        GetActiveXY(*(u8**)(o + 576) + 24, &a, &b);
        getPos(*(u8**)(o + 576), &c, &d);
        s32 px = c + a;
        s32 py = d + b;
        setXY(o + 32, px, py);
        if (*(s32*)(o + 580) == 1) {
            getOfs(o + 320, &x, &y);
            setXY(o + 320, x + px, y + py);
        }
    }
    draw(o + 32);
    if (*(s32*)(o + 580) == 1) draw2(o + 320);
}
}  // namespace n0013e1c8

// ---- 0013e2d8 from src/anon/batch_w59.cpp
namespace n0013e2d8 {
u32 func_0013a7e8(u32) asm("func_0013a7e8");
void dk__Sprite__create(u8*, u32, u32, u32, u32, u32) asm("dk__Sprite__create");
void func_00139598(u8*) asm("func_00139598");
void func_00139708(u8*) asm("func_00139708");
void dk__LockOn__start(u8* p, u32 a, u32 b) asm("dk__LockOn__start");
void dk__LockOn__start(u8* p, u32 a, u32 b) {
    *(u32*)(p + 436) = a;
    dk__Sprite__create(p, 4000, func_0013a7e8(0), b, a, 17);
    dk__Sprite__create(p + 448, 4000, func_0013a7e8(0), b, 20, 17);
    func_00139598(p + 448);
    func_00139708(p + 448);
}
}  // namespace n0013e2d8

// ---- 0013e378 gap (pool free)
namespace n0013e378 {
struct Elem { u8 d[896]; };
struct Pool { Elem e[9]; s32 free[9]; s32 n; };
extern Pool* D_003486a4 asm("D_003486a4");
void func_0013e378(Elem* p) asm("func_0013e378");
void func_0013e378(Elem* p) {
    Pool* pool = D_003486a4;
    s32 i = p - pool->e;
    pool->free[pool->n++] = i;
}
}  // namespace n0013e378

// ---- 0013e3b0 from src/anon/batch_w48.cpp
namespace n0013e3b0 {
struct Vq {
    f32 x, y, z, w;
    Vq() {}
    Vq(const Vq& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_001391a8(void*, Vq) asm("func_001391a8");
s32 func_00139d78(void*) asm("func_00139d78");
void dk__LockOn__setPos(u8* o, Vq* v) asm("dk__LockOn__setPos");
void dk__LockOn__setPos(u8* o, Vq* v) {
    func_001391a8(o, *v);                           
    if (func_00139d78(o + 448)) func_001391a8(o + 448, *v);
}
}  // namespace n0013e3b0

// ---- 0013e410 gap
namespace n0013e410 {
void func_0013e410(u8* o) asm("func_0013e410");
void func_0013e410(u8* o) {
    f32 v = (f32)*(s32*)(o + 432) * 1e-05f + 0.4f;
    if (v > 1.0f) v = 1.0f;
    if (v < 0.5f) v = 0.5f;
    *(f32*)(o + 384) = v;
}
}  // namespace n0013e410

// ---- 0013e470 from src/anon/tiny_auto80_queue.cpp
namespace n0013e470 {
u32 dk__Sprite3D__update(...) asm("dk__Sprite3D__update");
u32 func_00139d78(...) asm("func_00139d78");
void dk__LockOn__update(u32 a0) asm("_Z18dk__LockOn__updatej");
void dk__LockOn__update(u32 a0) {
    u32 base = a0;
    dk__Sprite3D__update(a0);
    u32 dst = (u32)((s32)base + (448));
    if (func_00139d78(dst) != 0u) {
        *(volatile f32*)((u32)dst + (s32)(384)) = *(volatile f32*)((u32)base + (s32)(384));
    }
}
}  // namespace n0013e470

// ---- 0013e4b8 from src/anon/batch_w47.cpp
namespace n0013e4b8 {
s32 func_00139d78(void*) asm("func_00139d78");
struct S13e { u8 pad[388]; s32 f388; u8 pad2[56]; u8 sub[16]; };
void func_00138c10(void*, s32) asm("func_00138c10");
void func_00139510(void*) asm("func_00139510");
void dk__LockOn__end(S13e* p) asm("dk__LockOn__end");
void dk__LockOn__end(S13e* p) {
    if (!func_00139d78(p)) return;
    func_00138c10(p, p->f388 - 1);
    if (func_00139d78(p->sub)) func_00139510(p->sub);
}
}  // namespace n0013e4b8

// ---- 0013e520 from src/anon/auto80_199_queue.cpp
namespace n0013e520 {
void func_0013e520(u32 a0, u32 a1) asm("_Z13func_0013e520jj");
void func_0013e520(u32 a0, u32 a1) {
    u32 s0 = a0 + 448;
    u32 s1 = a1 & 0xFF;

    if (func_00139d78(s0) == 0) {
        return;
    }

    if (s1 == 1) {
        func_001395a8(s0);
        func_00139718(s0);
    } else {
        func_00139598(s0);
        func_00139708(s0);
    }
}
}  // namespace n0013e520

// ---- 0013e5a8 from src/anon/batch_w46.cpp
namespace n0013e5a8 {
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
void func_0013e610(u32) asm("func_0013e610");
struct O13e { void (**vt)(O13e*); u8 pad[432]; u32 f1b4; u32 pad2[2]; u8 sub[16]; };
static inline void upd13e(u8* s) { if (func_00139d78(s)) func_00139510(s); }
void dk__LockOn__change(O13e* p) asm("dk__LockOn__change");
void dk__LockOn__change(O13e* p) {
    if (func_00139d78(p)) p->vt[5](p);
    upd13e(p->sub);
    func_0013e610(p->f1b4);
}
}  // namespace n0013e5a8

// ---- 0013e610 from src/anon/batch_w47.cpp
namespace n0013e610 {
struct Pool13e { u8 pad[8064]; s32 free[9]; s32 n; };
struct G13e { u32 v; };
extern u8* D_003486a4 asm("D_003486a4");
extern G13e D_003486a0 asm("D_003486a0");
void dk__LockOn__start(u8*, u32, u32) asm("dk__LockOn__start");
u8* func_0013e610(u32 a) asm("func_0013e610");
u8* func_0013e610(u32 a) {
    Pool13e* p = (Pool13e*)D_003486a4;
    s32 n = p->n - 1;
    p->n = n;
    u8* r = (u8*)p + p->free[n] * 896;
    dk__LockOn__start(r, a, D_003486a0.v + 32);
    return r;
}
}  // namespace n0013e610

// ---- 0013e678 from src/harata/libdk/lockon.cpp
namespace dk {
extern u32 D_003486a0 asm("D_003486a0");
void* LockOn::getYIImage() {
    u32 p = D_003486a0;
    return (void*)((s32)p + 32);
}
}  // namespace dk

// ---- 0013e688 from src/anon/batch_w3710_nsa.cpp
namespace n0013e688 {
struct Heap;
struct HeapVT { void* (*alloc)(Heap*, u32, s32); };
struct Heap { HeapVT* vt; };
struct Sys { u8 pad[0x14]; Heap* heap; };
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
void func_0031a838(void*) asm("func_0031a838");
void func_00239700(void*) asm("func_00239700");
void* func_001050c8(void) asm("func_001050c8");
u8* func_001063c0(u32, void*) asm("func_001063c0");
void func_002361a0(void*) asm("func_002361a0");
s32 func_0013a7d0(s32) asm("func_0013a7d0");
void dk__SpriteImage__create(void*, s32, s32, s32) asm("dk__SpriteImage__create");
void func_0013e890(void) asm("func_0013e890");
extern u32 D_00347e18[] asm("D_00347e18");
extern u32 D_003486b0[] asm("D_003486b0");
extern u32 D_00347e80[] asm("D_00347e80");
extern u8* D_003486a0 asm("D_003486a0");
void dk__LockOn__init(void) asm("_Z16dk__LockOn__initv");
void dk__LockOn__init(void) {
    u8* p = func_001063c0(8112, func_001050c8());
    u8* q = p;
    u32* r = (u32*)(p + 12);
    for (s32 i = 8; i != -1; i--) {
        u32 ve60 = (u32)D_00347e60;
        u32 ve18 = (u32)D_00347e18;
        u32 vb0 = (u32)D_003486b0;
        u32 vf98 = (u32)D_00347f98;
        r[0] = 0;
        r[-3] = ve60;
        func_00239700(q + 24);
        r[105] = 0;
        r[-3] = vb0;
        r[109] = vf98;
        func_0031a838(q + 460);
        r[109] = ve60;
        func_00239700(q + 472);
        r[109] = ve18;
        r[217] = 0;
        q += 896;
        r += 224;
    }
    for (s32 j = 0; j < 9; j++) ((s32*)(p + 8064))[j] = j;
    u8* b = (u8*)0x340000;
    asm("" : "+r"(b));
    *(u32*)(p + 8100) = 9;
    register u32 n asm("$5") = 448;
    register s32 z asm("$6") = 0;
    u8* c;
    asm volatile("lui %0,0x35" : "=r"(c));
    *(u8**)(c - 31068) = p;                  
    Heap* hp = (*(Sys**)(b + 0x7f80))->heap;
    u8* o = (u8*)hp->vt->alloc(hp, n, z);
    *(u32*)(o + 12) = 0;
    *(u32**)o = D_00347e80;
    func_002361a0(o + 32);
    D_003486a0 = o;
    dk__SpriteImage__create(D_003486a0, 3700, func_0013a7d0(0), 0);
    func_0013e890();
}
}  // namespace n0013e688

// ---- 0013e808 from src/anon/auto80_199_queue.cpp
namespace n0013e808 {
void func_0013e808(void) asm("_Z13func_0013e808v");
void func_0013e808(void) {
    u32 p = D_003486a0;
    if (p != 0) {
        ((void (*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        D_003486a0 = 0;
    }

    u32 s1 = D_003486a4;
    if (s1 != 0) {
        u32 s0 = s1 + 8064;
L0013e84c:
        if (s1 != s0) {
            s0 = s0 - 896;
            ((void (*)(u32))(*(u32*)(*(u32*)s0 + 12)))(s0);
            goto L0013e84c;
        }

        func_00106420(s1);
        D_003486a4 = 0;
    }
}
}  // namespace n0013e808

// ---- 0013e890 from src/harata/libdk/lockon.cpp
namespace dk {
extern void Obj2D_showGroup(s32) asm("_ZN2dk5Obj2D9showGroupEi");
void LockOn::show() { Obj2D_showGroup(0x11); }
}  // namespace dk

// ---- 0013e8a8 from src/anon/tiny.cpp
namespace n0013e8a8 {
void func_001398d0(s32) asm("_Z13func_001398d0i");
void func_0013e8a8(BD_VALUE* bd) asm("_Z13func_0013e8a8P8BD_VALUE");
void func_0013e8a8(BD_VALUE* bd) { func_001398d0(17); }
}  // namespace n0013e8a8

// ---- 0013e8c0 from src/anon/tiny_auto80_solver.cpp
namespace n0013e8c0 {
u32 func_0013e8c0(u32) asm("_Z13func_0013e8c0j");
u32 dk__Ft4Base__createPacket(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z25dk__Ft4Base__createPacketjjjjjjjj");
void func_0014b150(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0014b150jjjjjjjj");
extern u8 D_003486f0 asm("D_003486f0");
u32 func_0013e8c0(u32 a0) asm("_Z13func_0013e8c0j");
u32 func_0013e8c0(u32 a0) {
    u32 s0 = a0;
    ((u32(*)(u32))func_0014b150)(a0);
    *(u32*)(s0 + 272) = 0;
    *(u32*)(s0 + 276) = 0;
    *(u32*)s0 = (u32)&D_003486f0;
    *(u32*)(s0 + 280) = 0;
    return ((u32(*)(u32))dk__Ft4Base__createPacket)(s0);
}
}  // namespace n0013e8c0

// ---- 0013e900 from src/anon/auto200_999.cpp
namespace n0013e900 {
u32 dk__Ft4Base__createPacket(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z25dk__Ft4Base__createPacketjjjjjjjj");
void func_0014b150(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0014b150jjjjjjjj");
extern u8 D_003486f0 asm("D_003486f0");
u32 func_0013e900(u32 a0) asm("_Z13func_0013e900j");
u32 func_0013e900(u32 a0) {
    u32 s0 = a0;
    ((u32 (*)(u32))func_0014b150)(a0);
    *(u32 *)(s0 + 272) = 0;
    *(u32 *)(s0 + 276) = 0;
    *(u32 *)s0 = (u32)&D_003486f0;
    *(u32 *)(s0 + 280) = 0;
    return ((u32 (*)(u32))dk__Ft4Base__createPacket)(s0);
}
}  // namespace n0013e900

// ---- 0013e940 from src/anon/batch_w1820_nsa.cpp
namespace n0013e940 {
struct W1820Gs {
    u8 pad[4];
    u16 w, h;
    s16 x, y;
    u32 z;
    u8 b0, b1, b2, b3;
    u8 pad2[12];
    u64 g[22];
    u64 g2[2];
};
void dk__Ft4Base__calcXYZ(W1820Gs*) asm("dk__Ft4Base__calcXYZ");
void dk__Ft4Base__createPacket(W1820Gs* p) asm("dk__Ft4Base__createPacket");
void dk__Ft4Base__createPacket(W1820Gs* p)
{
    p->g[0] = 0x8000000000000001ULL;
    p->g[1] = 0xEEEEEEEEULL;
    p->g[2] = 0;
    p->g[3] = 0x3f;
    p->g[4] = 0x800d8;
    p->g[5] = 0x4c;
    p->g[6] = 0x31000070;
    p->g[7] = 0x4e;
    p->g[8] = 0;
    p->g[9] = 6;
    p->g[10] = 0x60;
    p->g[11] = 0x14;
    p->g[12] = 0x30000;
    p->g[13] = 0x47;
    p->g[14] = 0x44;
    p->g[15] = 0x42;
    p->g[16] = 5;
    p->g[17] = 8;
    p->g[18] = 0xA400000000008001ULL;
    p->g[19] = 0x5353535310ULL;
    p->g[20] = 0x144;
    p->g[21] = (u64)p->b0 | ((u64)p->b1 << 8) | ((u64)p->b2 << 16) | ((u64)p->b3 << 24) | (1ULL << 32);
    dk__Ft4Base__calcXYZ(p);
}
}  // namespace n0013e940

// ---- 0013ea50 from src/anon/batch_wcx.cpp
namespace n0013ea50 {
union FI { f32 f; s32 i; s16 h; };
void sceVu0ApplyMatrix(FI*) asm("sceVu0ApplyMatrix");
void func_0013ea50(u8* p, u32, FI* v, s32* ox, s32* oy) asm("func_0013ea50");
void func_0013ea50(u8* p, u32, FI* v, s32* ox, s32* oy)
{
    sceVu0ApplyMatrix(v);
    *ox = (s32)(v[0].f * 16.0f);
    *oy = (s32)(v[1].f * 16.0f);
    *ox = ((FI*)(p + 8))->h * 16 + *ox + 28672;
    *oy = ((FI*)(p + 10))->h * 16 + *oy + 29440;
}
}  // namespace n0013ea50

// ---- 0013eb00 from src/anon/sweep_0013eb00_nsa.cpp
namespace n0013eb00 {
struct W1624Mat {
    f32 m[4][4];
    W1624Mat() {}
    W1624Mat& operator=(const W1624Mat& o) { asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W1624Vec {
    f32 x, y, z, w;
    W1624Vec() {}
    W1624Vec(const W1624Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W1624Ft4 {
    u8 _pad0[4];
    u16 w;                    
    u16 h;                    
    s16 ofsX;                 
    s16 ofsY;                 
    u32 z;                    
    u8 _pad10[0xd8 - 0x10];
    u64 xyz0;                 
    u64 _pad0e0;
    u64 xyz1;                 
    u64 _pad0f0;
    u64 xyz2;                 
    u64 _pad100;
    u64 xyz3;                  
    f32 rot;                   
    s32 cx;                    
    s32 cy;                    
};
#define W1624_GS_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
void func_0011b6a8(W1624Mat*) asm("func_0011b6a8");
void sceVu0RotMatrixZ(f32, W1624Mat*, W1624Mat*) asm("sceVu0RotMatrixZ");
void func_0013ea50(W1624Ft4*, W1624Mat*, W1624Vec, s32*, s32*) asm("func_0013ea50");
void dk__Ft4Base__calcXYZ(W1624Ft4* p) asm("dk__Ft4Base__calcXYZ");
void dk__Ft4Base__calcXYZ(W1624Ft4* p)
{
    s32 left = p->cx - (p->w >> 1);
    s32 top = p->cy - (p->h >> 1);
    s32 right = p->cx + (p->w >> 1);
    s32 bottom = p->cy + (p->h >> 1);
    W1624Mat m;
    W1624Vec v;
    W1624Mat mc;
    s32 x, y;
    func_0011b6a8(&m);
    sceVu0RotMatrixZ(p->rot, &m, &m);
    v.x = left; v.y = top;
    mc = m;
    func_0013ea50(p, &mc, v, &x, &y);
    p->xyz0 = W1624_GS_XYZ(x, y, p->z);
    v.x = right; v.y = top;
    mc = m;
    func_0013ea50(p, &mc, v, &x, &y);
    p->xyz1 = W1624_GS_XYZ(x, y, p->z);
    v.x = left; v.y = bottom;
    mc = m;
    func_0013ea50(p, &mc, v, &x, &y);
    p->xyz2 = W1624_GS_XYZ(x, y, p->z);
    v.x = right; v.y = bottom;
    mc = m;
    func_0013ea50(p, &mc, v, &x, &y);
    p->xyz3 = W1624_GS_XYZ(x, y, p->z);
}
}  // namespace n0013eb00
#undef W1624_GS_XYZ

// ---- 0013ed78 gap (Ft4 UV from size)
namespace n0013ed78 {
void func_0013ed78(dk::Ft4Base* p, u16 w, u16 h) asm("func_0013ed78");
void func_0013ed78(dk::Ft4Base* p, u16 w, u16 h) {
    s32 u = (w << 4) + 8;
    s32 v = (h << 4) + 8;
    p->setGsUV(0x80008, u | 0x80000, ((u64)v << 16) | 8, (u64)u | ((u64)v << 16));
}
}  // namespace n0013ed78

// ---- 0013edd0 from src/harata/libdk/ft4.cpp
namespace dk {
void Ft4Base::setRot(f32 v) { *(f32*)((u32)this + 272) = v; }
}  // namespace dk

// ---- 0013edd8 from src/anon/misc_1.cpp
namespace n0013edd8 {
f32 func_0013edd8(void* self) asm("_Z13func_0013edd8Pv");
f32 func_0013edd8(void* self) { return (f32)(*(f32*)((char*)self + 272)); }
}  // namespace n0013edd8

// ---- 0013ede0 from src/harata/libdk/ft4.cpp
namespace dk {
void Ft4Base::setCenterXY(s32 x, s32 y) {
    *(s32*)((u32)this + 276) = x;
    *(s32*)((u32)this + 280) = y;
}
}  // namespace dk

// ---- 0013edf0 gap (Ft4 getCenterXY)
namespace n0013edf0 {
void func_0013edf0(u8* p, s32* x, s32* y) asm("func_0013edf0");
void func_0013edf0(u8* p, s32* x, s32* y) {
    *x = *(s32*)(p + 276);
    *y = *(s32*)(p + 280);
}
void func_0013ee08(u8* p, u64 v) asm("func_0013ee08");
void func_0013ee08(u8* p, u64 v) { *(u64*)(p + 64) = v; }
void func_0013ee10(u8* p, u64 v) asm("func_0013ee10");
void func_0013ee10(u8* p, u64 v) { *(u64*)(p + 80) = v; }
}  // namespace n0013edf0

// ---- 0013ee18 from src/harata/libdk/ft4.cpp
namespace dk {
void Ft4Base::setGsTest(u64 v) { reinterpret_cast<Ft4BaseLayout*>(this)->gs_test = v; }
}  // namespace dk

// ---- 0013ee20 gap
namespace n0013ee20 {
void func_0013ee20(u8* p, u64 v) asm("func_0013ee20");
void func_0013ee20(u8* p, u64 v) { *(u64*)(p + 144) = v; }
}  // namespace n0013ee20

// ---- 0013ee28 from src/harata/libdk/ft4.cpp
namespace dk {
void Ft4Base::setGsTex0(u64 v) { reinterpret_cast<Ft4BaseLayout*>(this)->gs_tex0 = v; }
}  // namespace dk

// ---- 0013ee30 from src/anon/misc_1.cpp
namespace n0013ee30 {
void func_0013ee30(void* self, s64 v) asm("_Z13func_0013ee30Pvx");
void func_0013ee30(void* self, s64 v) { *(s64*)((char*)self + 112) = v; }
}  // namespace n0013ee30

// ---- 0013ee38 from src/harata/libdk/ft4.cpp
namespace dk {
void Ft4Base::setGsPrim(u64 v) { reinterpret_cast<Ft4BaseLayout*>(this)->gs_prim = v; }
}  // namespace dk

// ---- 0013ee40 from src/anon/auto200_999.cpp
namespace dk {
void Ft4Base::setGsUV(u64 a0, u64 a1, u64 a2, u64 a3) {
    *(volatile u64 *)((u8 *)this + 208) = a0;
    *(volatile u64 *)((u8 *)this + 256) = a3;
    *(volatile u64 *)((u8 *)this + 224) = a1;
    *(volatile u64 *)((u8 *)this + 240) = a2;
}
}  // namespace dk

// ---- 0013ee58 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n0013ee58 {
u32 func_0013e8c0(u32, u32, u32, u32) asm("_Z13func_0013e8c0jjjj");
extern u8 D_003486d8 asm("D_003486d8");
u32 func_0013ee58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0013ee58jjjj");
u32 func_0013ee58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0013e8c0(r4, r5, r6, r7);
    r15 = (u32)&D_003486d8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0013ee58

// ---- 0013ee88 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n0013ee88 {
u32 func_0013e8c0(u32, u32, u32, u32) asm("_Z13func_0013e8c0jjjj");
extern u8 D_003486d8 asm("D_003486d8");
u32 func_0013ee88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0013ee88jjjj");
u32 func_0013ee88(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0013e8c0(r4, r5, r6, r7);
    r15 = (u32)&D_003486d8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0013ee88

// ---- 0013eeb8 from src/anon/batch_w1787_nsa.cpp
namespace n0013eeb8 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Pkt13eeb8 { u32 a; u32 b; u128* p; };
struct Obj13eeb8 { u8 pad[0x10]; u8 c[4]; u8 pad2[0xc]; union { u128 q[15]; struct { u8 pad[0xa8]; u64 tag; } t; }; };
void dk__Ft4Base__calcXYZ(Obj13eeb8*) asm("dk__Ft4Base__calcXYZ");
void func_001b7e68(Pkt13eeb8*, s32) asm("func_001b7e68");
void func_001b80d8(Pkt13eeb8*) asm("func_001b80d8");
void func_001b7f30(Pkt13eeb8*) asm("func_001b7f30");
void func_0013eeb8(Obj13eeb8* o) asm("func_0013eeb8");
void func_0013eeb8(Obj13eeb8* o) {
    o->t.tag = (u64)o->c[0] | ((u64)o->c[1] << 8) | ((u64)o->c[2] << 16) | ((u64)o->c[3] << 24) | ((u64)1 << 32);
    dk__Ft4Base__calcXYZ(o);
    Pkt13eeb8 k;
    k.p = 0; k.b = 0; k.a = 0;
    func_001b7e68(&k, 240);
    Pkt13eeb8* pk = &k; u128* src = o->q;
    for (s32 i = 14; i >= 0; i--) { *pk->p = *src++; pk->p++; }
    func_001b80d8(&k);
    func_001b7f30(&k);
}
}  // namespace n0013eeb8

