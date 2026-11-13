#include "../harata/libdk/monochrome.hpp"
#include "../harata/libdk/command_one.hpp"
#include "../harata/libdk/command_draw.hpp"
#include "../harata/libdk/gauge.hpp"
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 0013a8b8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013a8b8 {
u32 func_00131da8(...) asm("func_00131da8");
extern u8 D_00347ff8 asm("D_00347ff8");
extern u8 D_00347ffc asm("D_00347ffc");
void func_0013a8b8(void) asm("func_0013a8b8");
void func_0013a8b8(void) {
    if (*(u8*)((u32)&D_00347ffc + (s32)(0)) == (u8)0u) return;
    if (*(u32*)((u32)&D_00347ff8 + (s32)(0)) != 1u) return;
    func_00131da8();
}
} // n0013a8b8

// 0013a8f8 (from src/anon/auto80_199_queue.cpp)
namespace n0013a8f8 {
void func_0013a8f8(void) asm("func_0013a8f8");
void func_0013a8f8(void) {
    u32 a0;
    u8* p = &D_0032bae0;
    if (func_001948c0((u32)p[1], (u32)p[0]) != 0) {
        D_00347ff8 = 1;
        a0 = 1;
    } else {
        D_00347ff8 = 0;
        a0 = 0;
    }

    func_001dd208(a0);
    D_00347ffc = 1;
}
} // n0013a8f8

// 0013a958 (from src/anon/batch_w1520.cpp)
namespace n0013a958 {
s32 func_001948c0(s32, s32) asm("func_001948c0");
void func_0013a690_x(void) asm("_ZN2dk8Field2DD16ensureMonochromeEv");
void func_0013a9e8(s32) asm("func_0013a9e8");
void destroyAll(void) asm("_ZN2YS10CACHE_BUFF10DestroyAllEv");
extern s32 D_00347ff8 asm("D_00347ff8");
extern u8 D_00347ffc asm("D_00347ffc");
static inline s32 conv2(s32 v) { if (v == 0xffff) v = -1; return v; }
void func_0013a958(u8* p) asm("func_0013a958");
void func_0013a958(u8* p) {
    bool ok = func_001948c0(conv2(p[1]), conv2(p[0]));
    if (D_00347ff8 == 1 && !ok) { func_0013a690_x(); func_0013a9e8(1); destroyAll(); }
    D_00347ffc = 0;
}
} // n0013a958

// 0013a9d0
namespace dk {
extern u32 D_00347ff8 asm("D_00347ff8");
bool Monochrome::isMonochrome() { return D_00347ff8 == 1; }
}  // namespace dk

// 0013a9e8 (from src/anon/tiny.cpp)
namespace n0013a9e8 {
extern u32 D_00347ffd asm("D_00347ffd");
void func_0013a9e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013a9e8");
void func_0013a9e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = a0 & 0xffu;
    *(u8*)&D_00347ffd = (u8)v;
}
} // n0013a9e8

// 0013a9f8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013a9f8 {
u32 func_0013a9d0(...) asm("func_0013a9d0");
extern u8 D_00347ffd asm("D_00347ffd");
u32 func_0013a9f8(void) asm("func_0013a9f8");
u32 func_0013a9f8(void) {
    if (*(u8*)((u32)&D_00347ffd + (s32)(0)) == (u8)1u) {
        *(u8*)((u32)&D_00347ffd + (s32)(0)) = (u8)0u;
        return 1u;
    }
    return (u32)(func_0013a9d0() != 0u);
}
} // n0013a9f8

// 0013aa38 (from src/anon/batch_w2029.cpp)
namespace n0013aa38 {
extern s32 D_00347ff8 asm("D_00347ff8");
void func_001dd208(s32) asm("func_001dd208");
s32 func_0013aa38(s32 a) asm("func_0013aa38");
s32 func_0013aa38(s32 a) {
    s32 old = D_00347ff8;
    D_00347ff8 = a;
    if (a == 1) func_001dd208(a); else func_001dd208(0);
    return old;
}
} // n0013aa38

// 0013aa78 (from src/anon/batch_wcx.cpp)
namespace n0013aa78 {
void func_00138d60(u8*, s32, u32, u32, u32, u32, u32) asm("func_00138d60");
void func_00139620(u8*) asm("func_00139620");
void func_00239988(u8*, u32, u32) asm("func_00239988");
void func_0013ac60(u8*, u32, u32) asm("func_0013ac60");
void func_0013aa78(u8* p, u32 x, u32 y, u32 z, u32 w, u32 v, u32 u) asm("func_0013aa78");
void func_0013aa78(u8* p, u32 x, u32 y, u32 z, u32 w, u32 v, u32 u)
{
    func_00138d60(p, 5303, y, z, x, 0, v);
    *(s32*)(p + 412) = 10;
    *(s32*)(p + 416) = -7;
    *(s32*)(p + 424) = 14;
    *(s32*)(p + 428) = 1;
    func_00139620(p);
    func_00239988(p + 436, y, z);
    func_0013ac60(p, u, w);
}
} // n0013aa78

// 0013ab20 (never written before)
namespace n0013ab20 {
struct E784 { u8 d[784]; };
struct Pool { E784 e[36]; s32 free[36]; s32 n; };
extern Pool* D_00348058 asm("D_00348058");
void func_0013ab20(E784* r) asm("func_0013ab20");
void func_0013ab20(E784* r) {
    Pool* p = D_00348058;
    p->free[p->n++] = r - p->e;
}
} // n0013ab20

// 0013ab58
namespace dk {
extern u8 D_0034805c asm("D_0034805c");
extern "C" u32 func_00138840(...);
extern "C" u32 func_0023acd8(...);
void COMMAND_ONE::update() {
    u32 s0 = (u32)this;
    func_00138840((u32)this);
    if (*(s32*)((u32)this + (s32)(780)) >= *(s32*)((u32)&D_0034805c + (s32)(0))) {
        func_0023acd8((u32)((s32)s0 + (436)));
        return;
    }
}
}  // namespace dk

// 0013aba8 (from src/anon/batch_w1790_gnsa.cpp)
namespace n0013aba8 {
struct W1790Pos { u8 pad[328]; s32 x, y; };
struct W1790Obj { u8 p0[24]; u8 seq[344]; s32 a170, a174; u8 p178[60]; W1790Pos pos; u8 p[780 - 436 - 336]; s32 v30c; };
void func_00138988(W1790Obj*) asm("func_00138988");
void func_00138de0(W1790Obj*) asm("func_00138de0");
void seq_GetActiveXY(void*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
s32 seq_GetParamX(void*) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 seq_GetParamY(void*) asm("_ZN2YI8SEQUENCE9GetParamYEv");
void func_0023ade0(W1790Pos*) asm("func_0023ade0");
extern s32 D_0034805c asm("D_0034805c");
void func_0013aba8(W1790Obj* o) asm("func_0013aba8");
void func_0013aba8(W1790Obj* o) {
    s32 x = 0, y = 0;
    void* m = o->seq;
    func_00138988(o);
    func_00138de0(o);
    if (o->v30c >= D_0034805c) {
        seq_GetActiveXY(m, &x, &y);
        x += seq_GetParamX(m);
        y += seq_GetParamY(m);
        W1790Pos* p = &o->pos;
        s32 a = o->a170 + x;
        s32 b = o->a174 + y;
        p->y = b;
        p->x = a;
        func_0023ade0(p);
    }
}
} // n0013aba8

// 0013ac60 (from src/anon/tiny_auto80_solver.cpp)
namespace n0013ac60 {
extern u8 D_00348000 asm("D_00348000");
u32 func_00239bf8(...) asm("func_00239bf8");
u32 func_0013ac60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0013ac60");
u32 func_0013ac60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = 10u;
    r6 = (u32)(r6 * r15);
    *(volatile u32*)((u32)r4 + (s32)(780)) = r5;
    r4 = (u32)((s32)r4 + (436));
    r6 = (u32)(r6 + r5);
    r15 = (u32)&D_00348000;
    r6 = (u32)(r6 << 2);
    r6 = (u32)(r6 + r15);
    r5 = *(volatile u32*)((u32)r6 + (s32)(0));
    return ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00239bf8)(r4, r5, r6, r7, r8, r9, r10, r11);
}
} // n0013ac60

// 0013aca0 (from src/anon/batch_w47.cpp)
namespace n0013aca0 {
struct Pool13a { u8 pad[28224]; s32 free[36]; s32 n; };
extern u8* D_00348058 asm("D_00348058");
u8* func_0013aa78(u8*, u32, u32, u32, u32, u32, u32) asm("func_0013aa78");
u8* func_0013aca0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) asm("func_0013aca0");
u8* func_0013aca0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    Pool13a* p = (Pool13a*)D_00348058;
    s32 n = p->n - 1;
    p->n = n;
    u8* r = (u8*)p + p->free[n] * 784;
    func_0013aa78(r, a, b, c + 32, d, e, f);
    return r;
}
} // n0013aca0

// 0013ad20 (from src/anon/sweep_0013ad20_nsa.cpp)
namespace n0013ad20 {
struct Alloc;
struct AllocVt { void* (*alloc)(Alloc*, u32, u32); };
struct Alloc { AllocVt* vt; };
struct Heap { u8 pad[0x14]; Alloc* a; };
extern Heap* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_003485b0[] asm("D_003485b0");
extern u8 D_003485d0[] asm("D_003485d0");
extern void* D_00348050 asm("D_00348050");
extern void* D_00348054 asm("D_00348054");
extern void* D_00348058 asm("D_00348058");
u32 func_001050c8(void) asm("func_001050c8");
u8* func_001063c0(u32, u32) asm("func_001063c0");
void func_0031a838(void*) asm("func_0031a838");
void func_00239700(void*) asm("func_00239700");
void func_002361a0(void*) asm("func_002361a0");
void func_0013ad20(void) asm("func_0013ad20");
void func_0013ad20(void) {
    u32 h = func_001050c8();
    u8* m = func_001063c0(0x6ed4, h);
    u8* p;
    s32 n = 35;
    p = m;
    do {
        *(u32*)(p + 12) = 0;
        *(u32*)p = (u32)D_00347e60;
        func_00239700(p + 24);
        *(u32*)(p + 0x198) = 0;
        *(u32*)p = (u32)D_003485b0;
        func_00239700(p + 0x1b4);
        p += 0x310;
    } while (--n != -1);
    s32 i = 0;
    s32* q = (s32*)(m + 0x6e40);
    do { *q++ = i; i++; } while (i < 36);
    *(s32*)(m + 0x6ed0) = 36;
    *(u32*)&D_00348058 = (u32)m;
    u8* m2 = func_001063c0(0x3384, h);
    p = m2;
    n = 31;
    do {
        *(u32*)p = (u32)D_00347f98;
        func_0031a838(p + 12);
        *(u32*)p = (u32)D_00347e60;
        func_00239700(p + 24);
        *(u32*)p = (u32)D_003485d0;
        p += 0x198;
    } while (--n != -1);
    s32 j = 0;
    s32* r = (s32*)(m2 + 0x3300);
    do { *r++ = j; j++; } while (j < 32);
    *(s32*)(m2 + 0x3380) = 32;
    D_00348054 = m2;
    Alloc* al = ((Heap*)*(u32*)&D_00347f80)->a;
    u32* o = (u32*)al->vt->alloc(al, 0x1c0, 0);
    o[3] = 0;
    o[0] = (u32)D_00347e80;
    func_002361a0(o + 8);
    D_00348050 = o;
}
} // n0013ad20

// 0013aed8 (from src/anon/batch_w76.cpp)
namespace n0013aed8 {
typedef void (*VFn)(void*);
extern void* D_00348050 asm("D_00348050");
extern u8* D_00348058 asm("D_00348058");
extern u8* D_00348054 asm("D_00348054");
void func_00106420(void*) asm("func_00106420");
void func_0013aed8(void) asm("func_0013aed8");
void func_0013aed8(void)
{
    if (D_00348050) {
        (*(VFn*)(*(u8**)D_00348050 + 16))(D_00348050);
        D_00348050 = 0;
    }
    u8* p = D_00348058;
    if (p) {
        u8* q = p + 28224;
    l1: if (p == q) goto d1; q -= 784; (*(VFn*)(*(u8**)q + 12))(q); goto l1;
    d1:
        func_00106420(p);
        D_00348058 = 0;
    }
    p = D_00348054;
    if (p) {
        u8* q = p + 13056;
    l2: if (p == q) goto d2; q -= 408; (*(VFn*)(*(u8**)q + 12))(q); goto l2;
    d2:
        func_00106420(p);
        D_00348054 = 0;
    }
}
} // n0013aed8

// 0013afa0, 0013afb0 (never written before)
namespace n0013afa0 {
extern u32 D_0034805c asm("D_0034805c");
void func_0013afa0() asm("func_0013afa0");
void func_0013afa0() { D_0034805c = 1; }
struct E520 { u8 d[408]; };
struct Pool { E520 e[32]; s32 free[32]; s32 n; };
extern Pool* D_00348054 asm("D_00348054");
void func_0013afb0(E520* r) asm("func_0013afb0");
void func_0013afb0(E520* r) {
    Pool* p = D_00348054;
    p->free[p->n++] = r - p->e;
}
} // n0013afa0

// 0013afe8 (from src/anon/batch_w57.cpp)
namespace n0013afe8 {
struct T13a {
    void* vtbl; u8 p4[8]; u32 f0c; u8 p10[0xdc]; s32 fec; u32 ff0; s32 ff4; s32 ff8; u8 b0, b1, b2, b3; u32 f100; void* f104; u8 p108[8]; u32 f110; u8 p114[8]; u8 f11c[0x180]; u32 f29c, f2a0, f2a4; u8 b2a8, b2a9, p2aa[2]; f32 f2ac; u32 f2b0; f32 f2b4;
};
extern u8 D_00348590 asm("D_00348590");
extern u8 D_00347e60 asm("D_00347e60");
u32 func_00239700(void*) asm("func_00239700");
void func_0013afe8(T13a* t) asm("func_0013afe8");
void func_0013afe8(T13a* t) {
    t->vtbl = &D_00348590;
    t->fec = -1;
    t->ff4 = -1;
    t->ff8 = -1;
    t->f104 = &D_00347e60;
    t->f0c = 0;
    t->ff0 = 0;
    t->b0 = 0; t->b1 = 0; t->b2 = 0; t->b3 = 0;
    t->f100 = 0;
    t->f110 = 0;
    func_00239700(&t->f11c);
    t->f29c = 0;
    t->f2a0 = 0;
    t->f2a4 = 0;
    t->b2a8 = 0;
    t->b2a9 = 0;
    t->f2ac = 1.0f;
    t->f2b0 = 0;
    t->f2b4 = 1.0f;
}
} // n0013afe8

// 0013b088 (from src/anon/batch_w58.cpp)
namespace n0013b088 {
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00348590[] asm("D_00348590");
void func_00239700(void*) asm("func_00239700");
void func_0013b088(u8* p) asm("func_0013b088");
void func_0013b088(u8* p) {
    *(void**)p = D_00348590;
    *(u32*)(p + 12) = 0;
    *(s32*)(p + 236) = -1;
    *(u32*)(p + 240) = 0;
    *(s32*)(p + 244) = -1;
    *(s32*)(p + 248) = -1;
    p[252] = 0;
    p[253] = 0;
    p[254] = 0;
    p[255] = 0;
    *(u32*)(p + 256) = 0;
    *(void**)(p + 260) = D_00347e60;
    *(u32*)(p + 272) = 0;
    func_00239700(p + 284);
    *(u32*)(p + 668) = 0;
    *(u32*)(p + 672) = 0;
    *(u32*)(p + 676) = 0;
    p[680] = 0;
    p[681] = 0;
    *(f32*)(p + 684) = 1.0f;
    *(u32*)(p + 688) = 0;
    *(f32*)(p + 692) = 1.0f;
}
} // n0013b088

// 0013b128 (from src/anon/auto80_199_queue.cpp)
namespace n0013b128 {
void func_0013b128(u32 a0) asm("func_0013b128");
void func_0013b128(u32 a0) {
    s32 t15 = -1;
    s32 t11 = 0;
    *(u32*)(a0 + 248) = (u32)t15;
    s32 t10 = -1;
    u32 t12 = a0;

L0013b13c:
    {
        u32 t15 = (u32)t11 << 3;
        *(u32*)(t12 + 220) = (u32)t10;
        u32 t14 = t15 + (u32)t11;
        *(u32*)(t12 + 204) = (u32)t10;
        u32 t9 = t15 + a0;
        t14 = (t14 << 2);
        t15 = t9 + (u32)t11;
        t14 = t14 + a0;
        t15 = t15 + 168;
        t14 = t14 + 24;

        s32 t13 = 8;
L0013b168:
        *(u32*)t14 = 0;
        t13 = t13 - 1;
        *(u8*)t15 = 0;
        t14 = t14 + 4;
        if (t13 >= 0) {
            t15 = t15 + 1;
            goto L0013b168;
        }
    }

    t11 = t11 + 1;
    if (t11 < 4) {
        t12 = t12 + 4;
        goto L0013b13c;
    }
}
} // n0013b128

// 0013b1a0 (from src/anon/batch_w7.cpp)
namespace n0013b1a0 {
void func_001391c8(u32, u32, u32) asm("func_001391c8");
void func_0013b128(u32) asm("func_0013b128");
void func_0013b1a0(u32 a0) asm("func_0013b1a0");
void func_0013b1a0(u32 a0) {
    func_001391c8(a0, 5302, 1);
    func_0013b128(a0);
}
} // n0013b1a0

// 0013b1d0 (from src/anon/batch_w50.cpp)
namespace n0013b1d0 {
u32 func_0013a800(void) asm("func_0013a800");
void func_00138650(void*, s32, u32, s32) asm("func_00138650");
s32 func_00242c70(void) asm("func_00242c70");
s32 func_0013a9d0(void) asm("func_0013a9d0");
void func_002368e8(void*, f32) asm("func_002368e8");
void func_002367c8(void*) asm("func_002367c8");
extern u8* D_00348050 asm("D_00348050");
void func_0013b1d0(void) asm("func_0013b1d0");
void func_0013b1d0(void) {
    func_00138650(D_00348050, 5200, func_0013a800(), 1);
    if (func_00242c70()) return;
    if (!func_0013a9d0()) return;
    u8* p = D_00348050 + 32;
    func_002368e8(p, 0.8f);
    func_002367c8(p);                            
}
} // n0013b1d0

// 0013b258 (from src/anon/misc_1.cpp)
namespace n0013b258 {
void func_0013b258(void* self, s32 v) asm("func_0013b258");
void func_0013b258(void* self, s32 v) { *(s32*)((char*)self + 668) = v; }
} // n0013b258

// 0013b260 (from src/anon/batch_w16.cpp)
namespace n0013b260 {
void func_0013b258(void*) asm("func_0013b258");
void func_0013b1d0(void*) asm("func_0013b1d0");
void func_0013d208(void*) asm("func_0013d208");
void func_0013b1a0(void*) asm("func_0013b1a0");
void func_0013b260(void* p) asm("func_0013b260");
void func_0013b260(void* p) {
    func_0013b258(p);
    func_0013b1d0(p);
    func_0013d208(p);
    func_0013b1a0(p);
}
} // n0013b260

// 0013b298 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013b298 {
f32 func_0013b298(u32 a0) asm("func_0013b298");
f32 func_0013b298(u32 a0) {
    return (*(f32*)((u32)a0 + (s32)(692))) * (*(f32*)((u32)a0 + (s32)(688)));
}
} // n0013b298

// 0013b2a8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013b2a8 {
f32 func_0013b2a8(u32 a0) asm("func_0013b2a8");
f32 func_0013b2a8(u32 a0) {                     
    return (*(f32*)((u32)a0 + (s32)(692))) * (*(f32*)((u32)a0 + (s32)(684)));
}
} // n0013b2a8

// 0013b2b8 (from src/anon/tiny_more.cpp)
namespace n0013b2b8 {
extern u32 D_003484a0 asm("D_003484a0");
void func_0013b2b8(f32 a0,u32 a1,u32 a2,u32 a3) asm("func_0013b2b8");
void func_0013b2b8(f32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = D_003484a0; *(f32*)((u32)p + (692)) = a0; }
} // n0013b2b8

// 0013b2c8 (never written before)
namespace n0013b2c8 {
extern u8* D_003484a0 asm("D_003484a0");
void func_0013b2c8(f32 v) asm("func_0013b2c8");
void func_0013b2c8(f32 v) { *(f32*)(D_003484a0 + 684) = v; }
} // n0013b2c8

// 0013b2d8 (from src/anon/tiny_more.cpp)
namespace n0013b2d8 {
extern u32 D_003484a0 asm("D_003484a0");
void func_0013b2d8(f32 a0,u32 a1,u32 a2,u32 a3) asm("func_0013b2d8");
void func_0013b2d8(f32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = D_003484a0; *(f32*)((u32)p + (688)) = a0; }
} // n0013b2d8

// 0013b2e8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013b2e8 {
extern u8 D_003484a0 asm("D_003484a0");
f32 func_0013b2e8(void) asm("func_0013b2e8");
f32 func_0013b2e8(void) {
    u32 r14 = *(u32*)((u32)&D_003484a0 + (s32)(0));
    return *(f32*)((u32)r14 + (s32)(688));
}
} // n0013b2e8

// 0013b2f8 (from src/anon/tiny_wrappers_imp.cpp)
namespace n0013b2f8 {
u32 func_0013b4b0(u32, u32, u32, u32) asm("func_0013b4b0");
u32 func_0013b2f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013b2f8");
u32 func_0013b2f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r13 = 0u, r14 = 0u, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r14 = (u32)((s32)0u + (1));
    r13 = *(u32*)((u32)r15 + (s32)(-31584));
    *(u8*)((u32)r13 + (s32)(680)) = (u8)r14;
    return func_0013b4b0(r4, r5, r6, r7);
}
} // n0013b2f8

// 0013b320 (from src/anon/tiny_jal_wrappers.cpp)
namespace n0013b320 {
u32 func_0013b508(u32, u32, u32, u32) asm("func_0013b508");
u32 func_0013b320(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013b320");
u32 func_0013b320(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_0013b508(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    r14 = *(u32*)((u32)r15 + (s32)(-31584));
    *(u8*)((u32)r14 + (s32)(680)) = (u8)0u;
    return r2;
}
} // n0013b320

// 0013b348 (from src/anon/auto80_199_queue.cpp)
namespace n0013b348 {
void func_0013b348(u32 a0) asm("func_0013b348");
void func_0013b348(u32 a0) {
    u32 s1 = a0;
    u32 v0 = D_003484a0;
    if (v0 != 0) {
        func_0013b258(v0, s1);
        return;
    }

    func_0013b570();
    func_0013ad20();

    u32 mgr = D_00347f80;
    u32 obj = *(u32*)(mgr + 20);
    u32 s0 = ((u32(*)(u32, u32, u32))(*(u32*)(*(u32*)obj + 0)))(obj, 696, 0);
    func_0013b088(s0);
    D_003484a0 = s0;
    func_0013b260(s0, s1);
    func_0013b508();
    func_0013b5a8();
}
} // n0013b348

// 0013b3f8 (from src/anon/auto80_199_queue.cpp)
namespace n0013b3f8 {
void func_0013b3f8(void) asm("func_0013b3f8");
void func_0013b3f8(void) {
    u32 v0 = D_003484a0;
    if (v0 == 0) {
        return;
    }

    func_0013b570();
    func_0013b1d0(D_003484a0);
    func_0013d2d0(D_003484a0);
    func_0013b1a0(D_003484a0);
    func_0013b4b0();
    func_0013b5a8();
}
} // n0013b3f8

// 0013b458 (from src/anon/auto80_199_queue.cpp)
namespace n0013b458 {
void func_0013b458(void) asm("func_0013b458");
void func_0013b458(void) {
    func_0013b538();
    func_0013b570();
    func_0013aed8();

    u32 p = D_003484a0;
    if (p != 0) {
        ((void (*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        D_003484a0 = 0;
    }

    func_0013b5a8();
}
} // n0013b458

// 0013b4b0 (from src/anon/batch_w30.cpp)
namespace n0013b4b0 {
void func_00139858(s32) asm("func_00139858");
void func_00139ab0(s32) asm("func_00139ab0");
extern u8* D_003484a0 asm("D_003484a0");
void wtarget_0013b4b0(u32, u32, u32, u32) asm("_Z16wtarget_0013b4b0jjjj");
void wtarget_0013b4b0(u32, u32, u32, u32) {
    u8* p = D_003484a0;
    if (p && p[680]) {
        func_00139858(2);
        func_00139858(1);
        func_00139ab0(2);
        func_00139ab0(1);
    }
}
} // n0013b4b0

// 0013b508 (from src/anon/tiny_auto80_solver.cpp)
namespace n0013b508 {
u32 func_001398d0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001398d0");
u32 func_00139a38(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00139a38");
u32 func_0013b508(void) asm("func_0013b508");
u32 func_0013b508(void) asm("func_0013b508");
u32 func_0013b508(void) {
    ((u32(*)(u32))func_001398d0)(2);
    ((u32(*)(u32))func_001398d0)(1);
    ((u32(*)(u32))func_00139a38)(2);
    return ((u32(*)(u32))func_00139a38)(1);
}
} // n0013b508

// 0013b538 (from src/anon/tiny_auto80_solver.cpp)
namespace n0013b538 {
u32 func_001397d8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001397d8");
u32 func_0013a218(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0013a218");
u32 func_0013b570(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0013b570");
u32 func_0013b5a8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0013b5a8");
u32 func_0013b538(void) asm("func_0013b538");
u32 func_0013b538(void) {
    ((u32(*)())func_0013b570)();
    ((u32(*)(u32))func_001397d8)(1);
    ((u32(*)(u32))func_001397d8)(2);
    ((u32(*)())func_0013a218)();
    return ((u32(*)())func_0013b5a8)();
}
} // n0013b538

// 0013b570 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013b570 {
u32 func_00103b38(...) asm("func_00103b38");
u32 func_00139dc0(...) asm("func_00139dc0");
u32 func_0013a1e8(...) asm("func_0013a1e8");
void func_0013b570(void) asm("func_0013b570");
void func_0013b570(void) {
    if (func_00103b38() != 0u) {
        func_0013a1e8();
        func_00139dc0(0u);
    }
}
} // n0013b570

// 0013b5a8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013b5a8 {
u32 func_00103b38(...) asm("func_00103b38");
u32 func_0013a200(...) asm("func_0013a200");
void func_0013b5a8(void) asm("func_0013b5a8");
void func_0013b5a8(void) {
    if (func_00103b38() != 0u) {
        func_0013a200();
    }
}
} // n0013b5a8

// 0013b5d0 (from src/anon/batch_w2351_nsa.cpp)
namespace n0013b5d0 {
struct SprInfo { volatile u16 flags; u8 p2[2]; u8 kind; };
struct Spr { u8 p0[0x198]; s32 tag; u8 p19c[8]; u32 col; };
struct SprRow { u8 pad[8]; u8 flag[1]; };
struct SprPool { u8 p0[0xa0]; SprRow rows[4]; };
extern s32 D_004573c0[] asm("D_004573c0");
s32 func_0013cb30(void) asm("func_0013cb30");
s32 func_0013cb80(void) asm("func_0013cb80");
s32 func_0013cb90(void) asm("func_0013cb90");
Spr* func_0013aca0(s32, s32, s32, s32, s32, u8) asm("func_0013aca0");
void func_0013ac60(Spr*, u8, s32) asm("func_0013ac60");
void func_00138c10(Spr*, s32) asm("func_00138c10");
void func_00138c40(Spr*, s32, s32) asm("func_00138c40");
f32 func_0013b298(u8*) asm("func_0013b298");
void func_001395d0(Spr*) asm("func_001395d0");
void func_001395e8(Spr*) asm("func_001395e8");
s32 __fixunssfsi(f32) asm("__fixunssfsi");
void func_00138d48(Spr*, f32, f32, f32, f32) asm("func_00138d48");
Spr* func_0013b5d0(u8* self, s32 idx, s32 c, SprInfo* info, u8 changed, s32 x, s32 y, s32 tag, f32 scale, u32 col, s32 mode) asm("func_0013b5d0");
Spr* func_0013b5d0(u8* self, s32 idx, s32 c, SprInfo* info, u8 changed, s32 x, s32 y, s32 tag, f32 scale, u32 col, s32 mode) {
    u8 flag;
    u8 kind;
    if (info == 0) {
        flag = 0;
        kind = 0;
    } else {
        kind = info->kind;
        flag = info->flags & 1;
    }
    s32 n = D_004573c0[idx];
    Spr** slot = (Spr**)((idx * 9 + n) * 4 + (u32)self + 0x18);
    Spr* e = *slot;
    s32 s2 = func_0013cb90();
    if (e == 0) {
        s32 s0 = func_0013cb30();
        e = func_0013aca0(c, s0, func_0013cb80(), s2, mode, kind);
        *slot = e;
    } else {
        if (changed == 1) func_00138c10(e, c);
        func_0013ac60(e, kind, s2);
    }
    e->tag = tag;
    func_00138c40(e, x, y);
    f32 r = func_0013b298(self);
    if (r < 1.0f) func_001395d0(e); else func_001395e8(e);
    col &= 0xffffff;
    col |= __fixunssfsi(r * 128.0f) << 24;
    e->col = col;
    func_00138d48(e, scale, scale, scale, r);
    ((SprRow*)((u8*)&((SprPool*)self)->rows[idx] + n))->flag[0] = flag;
    D_004573c0[idx]++;
    return e;
}
} // n0013b5d0

// 0013b808 (from src/anon/tiny_auto80_solver.cpp)
namespace n0013b808 {
extern u8 D_004573c0 asm("D_004573c0");
u32 func_0013b808(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0013b808");
u32 func_0013b808(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {                      
    u32* table = (u32*)&D_004573c0;
    u32 off4 = a1 << 2;
    u32 off8 = a1 << 3;
    u32 base = *(u32*)((u32)table + off4);
    u32 p = off8 + a1;
    p += a0;
    p += base;
    return *(u8*)(p + 168);
}
} // n0013b808

// 0013b838 (from src/anon/auto80_199_queue.cpp)
namespace n0013b838 {
void func_0013b838(u32 a0) asm("func_0013b838");
void func_0013b838(u32 a0) {
    s32 s2 = 0;
    u32* s3 = &D_004573c0;
    u32 s4 = a0;

L0013b864:
    {
        s32 s1 = (s32)*s3;
        if (s1 < 9) {
            u32 off = (s2 << 3) + s2;
            off = off + s1;
            off = off << 2;
            u32 s0 = off + s4;

L0013b884:
            {
                u32 p = *(u32*)(s0 + 24);
                if (p != 0) {
                    ((void (*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
                    *(u32*)(s0 + 24) = 0;
                }
                s1 = s1 + 1;
                if (s1 < 9) {
                    s0 = s0 + 4;
                    goto L0013b884;
                }
            }
        }
    }

    s2 = s2 + 1;
    if (s2 < 4) {
        s3 = (u32*)((u8*)s3 + 4);
        goto L0013b864;
    }
}
} // n0013b838

// 0013b8e8 (from src/anon/auto80_199_queue.cpp)
namespace n0013b8e8 {
void func_0013b8e8(u32 a0, s32 a1, s32 a2) asm("func_0013b8e8");
void func_0013b8e8(u32 a0, s32 a1, s32 a2) {
    s32 s2 = a1;
    s32 s3 = a2;
    u32 s4 = a0;

    if (s2 >= s3) {
        return;
    }

L0013b91c:
    {
        s32 s1 = 8;
        u32 off = ((u32)s2 << 3) + (u32)s2;
        off = off << 2;
        u32 s0 = off + s4;

L0013b92c:
        {
            u32 p = *(u32*)(s0 + 24);
            if (p != 0) {
                ((void (*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
                *(u32*)(s0 + 24) = 0;
            }
            s1 = s1 - 1;
            if (s1 >= 0) {
                s0 = s0 + 4;
                goto L0013b92c;
            }
        }

        s2 = s2 + 1;
        if (s2 < s3) {
            goto L0013b91c;
        }
    }
}
} // n0013b8e8

// 0013b988 (from src/anon/auto80_199_queue.cpp)
namespace n0013b988 {
u32 func_0013b988(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) asm("func_0013b988");
u32 func_0013b988(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {                       
    u32 i = a2 & 0xFF;
    u32 b4 = a4 & 0xFF;
    u32 b5 = a5 & 0xFF;

    if (b5 == 1) {
        return *(u32*)((u32)&D_003484a8 + (i << 2));
    }
    if (b4 == 1) {
        return *(u32*)((u32)&D_003484f8 + (i << 2));
    }
    return *(u32*)((u32)&D_003484d0 + (i << 2));
}
} // n0013b988

// 0013b9e0 (from src/anon/batch_w36.cpp)
namespace n0013b9e0 {
s32 func_0013ba50(u8*, s32) asm("func_0013ba50");
s32 func_0013b9e0(u8* p, s32 b) asm("func_0013b9e0");
s32 func_0013b9e0(u8* p, s32 b) {
    if (func_0013ba50(p, b)) return 0;
    if (b == 0 && *(s32*)(p + 236) == 6) return 1;
    if (b == 6 && *(s32*)(p + 236) == 0) return 1;
    return 0;
}
} // n0013b9e0

// 0013ba50 (from src/anon/tiny.cpp)
namespace n0013ba50 {
u32 func_0013ba50(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013ba50");
u32 func_0013ba50(u32 a0, u32 a1, u32 a2, u32 a3) {                   
    (void)a1;
    (void)a2;
    (void)a3;
    return ((*(u32*)((u32)a0 + (236)) ^ 0x0005u) == 0);
}
} // n0013ba50

// 0013ba60 (from src/anon/batch_w90.cpp)
namespace n0013ba60 {
extern u32 D_00348060[][12] asm("D_00348060");
extern u32 D_003483f0[] asm("D_003483f0");
extern u32 D_00348400[] asm("D_00348400");
extern u32 D_00348410[] asm("D_00348410");
s32 func_0013b9e0(s32, s32) asm("func_0013b9e0");
s32 func_0013ba50(s32) asm("func_0013ba50");
s32 func_0013ba60(s32 a0, s32 a1, s32 a2, u8* a3, s32 a4, u32* a5, u32* a6) asm("func_0013ba60");
s32 func_0013ba60(s32 a0, s32 a1, s32 a2, u8* a3, s32 a4, u32* a5, u32* a6)
{
    *a5 = D_00348060[a4][a2];
    if (a1) return 0;
    if (func_0013b9e0(a0, a4)) { *a3 = 1; *a5 = D_003483f0[a2]; }
    else if (!func_0013ba50(a0)) { *a5 = D_00348400[a2]; }
    *a6 = D_00348410[a2];
    return 1;
}
} // n0013ba60

// 0013bb58 (from src/anon/batch_w87.cpp)
namespace n0013bb58 {
s32 func_0013ba60(void*, s32, s32, u8*, s32, s32*, s32*) asm("func_0013ba60");
u8* func_0013b5d0(void*, s32, s32, s32, u8, s32, s32, s32, f32, u32, s32) asm("func_0013b5d0");
u8* func_0013bb58(void* a0, u8* a1, s32 a2, s32 a3, u8 b, s32 c, s32 d) asm("func_0013bb58");
u8* func_0013bb58(void* a0, u8* a1, s32 a2, s32 a3, u8 b, s32 c, s32 d) {
    s32 r20 = 0;
    s32 r24 = -1;
    s32 ok = func_0013ba60(a0, a2, a3, &b, d, &r20, &r24);
    u8* r = func_0013b5d0(a0, a2, r20, 0, b, c + 28, 388 - *(s32*)(a1 + 8) * 22, 0, 1.0f, 0x80b4b4b4, 2);
    if (ok) *(s32*)(r + 392) = r24;
    return r;
}
} // n0013bb58

// 0013bc40 (from src/anon/tiny_leaf.cpp)
namespace n0013bc40 {
u32 func_0013bc40(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013bc40");
u32 func_0013bc40(u32 a0, u32 a1, u32 a2, u32 a3) {                
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r5 = ((u32)r5 < 0x00000001u);
    r2 = r5;
    return r2;
}
} // n0013bc40

// 0013bc50 (from src/anon/batch_w1639.cpp)
namespace n0013bc50 {
struct W1639Sprite {
    u8 pad0[0x18c];
    s32 on18c;
    s32 on190;
};
struct W1639Cmd {
    u8 pad0[0xd0];
    s32 unkD0;
    u8 padD4[0x29c - 0xd4];
    s32 unk29C;
};
extern s32 D_00348430[] asm("D_00348430");
s32 func_0013bc40(W1639Cmd*, s32) asm("func_0013bc40");
W1639Sprite* func_0013b5d0(f32, W1639Cmd*, s32, s32, s32, u8, s32, s32, s32, s32, s32) asm("func_0013b5d0");
void func_001396b0(W1639Sprite*) asm("func_001396b0");
void func_0031a260(W1639Sprite*, s32) asm("func_0031a260");
void func_00139570(W1639Sprite*) asm("func_00139570");
void func_00139580(W1639Sprite*) asm("func_00139580");
void func_0013c820(W1639Cmd*, s32) asm("func_0013c820");
s32 func_001bdcd0(s32) asm("func_001bdcd0");
static inline __attribute__((always_inline)) void W1639_SetShow(W1639Sprite* p, s32 v)
{
    p->on18c = v;
    func_001396b0(p);
    if (p->on18c) {
        p->on190 = 0;
        func_001396b0(p);
        if (p->on190) func_0031a260(p, 0);
    }
}
void func_0013bc50(W1639Cmd* self, s32* sel, s32 a2, s32 idx, u8 t0, s32 t1, u8* info, s32 show) asm("func_0013bc50");
void func_0013bc50(W1639Cmd* self, s32* sel, s32 a2, s32 idx, u8 t0, s32 t1, u8* info, s32 show)
{
    if (!func_0013bc40(self, a2)) return;
    s32 kind = (*sel == 0) ? 0x14 : 0x15;
    s32 id;
    switch (info[7]) {
    case 1: id = 0x25; break;
    default: id = -1; break;
    case 2: id = 0x29; break;
    case 3: id = 0x27; break;
    case 4: id = 0x2c; break;
    case 5: id = 0x2b; break;
    case 6: id = 0x26; break;
    case 7: id = 0x28; break;
    }
    W1639Sprite* p;
    if (id != -1) {
        p = func_0013b5d0(1.0f, self, a2, D_00348430[idx], 0, t0, 0, 0, 0, t1, 2);
        if (!p) return;
        W1639_SetShow(p, show);
        func_00139580(p);
        p = func_0013b5d0(1.0f, self, a2, id, 0, t0, 0, 0, 0, t1, 2);
        W1639_SetShow(p, show);
        func_00139580(p);
        p = func_0013b5d0(1.0f, self, a2, kind, 0, t0, 0, 0, 0, t1, 2);
        W1639_SetShow(p, show);
        if (self->unkD0 == -1) func_00139580(p);
        else func_00139570(p);
        if (func_001bdcd0(self->unk29C)) func_00139570(p);
    } else {
        f32 f = 1.0f;
        
        p = func_0013b5d0(f, self, a2, D_00348430[idx], 0, t0, 0, 0, 0, t1, 2);
        if (!p) return;
        func_00139570(p);
        func_0013c820(self, a2);
        p = func_0013b5d0(f, self, a2, kind, 0, t0, 0, 0, 0, t1, 2);
        W1639_SetShow(p, show);
        if (func_001bdcd0(self->unk29C)) func_00139570(p);
        else func_00139580(p);
    }
}
} // n0013bc50

// 0013c080 (from src/anon/batch_wcx2.cpp)
namespace n0013c080 {
extern u32 D_00348470[][3] asm("D_00348470");
extern u32 D_00348440[][3] asm("D_00348440");
u32 func_0013b808(u32, u32) asm("func_0013b808");
struct Fl6 { u16 on : 1; u16 rest : 15; u8 On() { return on; } };
void func_0013c080(u32 a0, Fl6* fl, u32 a2, s32 col, u8* changed, s32 row, u32* outA, u32* outB) asm("func_0013c080");
void func_0013c080(u32 a0, Fl6* fl, u32 a2, s32 col, u8* changed, s32 row, u32* outA, u32* outB)
{
    if (fl->On()) {
        *outA = D_00348470[row][col];
        if (func_0013b808(a0, a2) != fl->on) {                      
            *outA = D_00348440[row][col];
            *outB = D_00348470[row][col];
            *changed = 1;
        }
    }
    if (func_0013b808(a0, a2)) {                      
        if (func_0013b808(a0, a2) != fl->on) *changed = 1;
    }
}
} // n0013c080

// 0013c190 (from src/anon/batch_w319.cpp)
namespace n0013c190 {
extern s32 D_00348060[] asm("D_00348060");
extern s32 D_00348420[] asm("D_00348420");
u32 func_0013b988(void*, void*, u8, s32, s32, s32) asm("func_0013b988");
void func_0013c080(void*, void*, s32, s32, u8*, s32, s32*, s32*) asm("func_0013c080");
u32 func_0013bc40(void*, s32) asm("func_0013bc40");
u32 func_0013b9e0(void*, s32) asm("func_0013b9e0");
u8* func_001b8e88(u16) asm("func_001b8e88");
u32 func_00192048(u32) asm("func_00192048");
u8* func_0013b5d0(void*, s32, s32, void*, u8, s32, s32, u32, f32, u32, s32) asm("func_0013b5d0");
void func_0013bc50(void*, void*, s32, s32, u8, u32, u8*, u8*) asm("func_0013bc50");
void func_0013c190(u8* p, u8* a1, s32 a2, s32 a3, u8 t0, s32 t1, s32 t2, s32 t3, u8* s6) asm("func_0013c190");
void func_0013c190(u8* p, u8* a1, s32 a2, s32 a3, u8 t0, s32 t1, s32 t2, s32 t3, u8* s6) {
    u8 flag;
    s32 w20;
    s32 w24;
    s32 s4 = *(s32*)(a1 + 108);
    u32 s8 = func_0013b988(p, a1, s6[5], s4, 1, 0);                       
    u8* v;
    u8* r;
    flag = 0;
    { u32 x = *(u32*)(a1 + 8); if (*(u32*)(p + a2 * 4 + 220) != x) flag = 1; }
    if (*(s32*)(p + a2 * 4 + 204) != s4) flag = 1;
    w24 = -1;
    w20 = D_00348060[t1 * 12 + a3 + 3];
    if (t0 == 1) {
        flag = t0;
        if (*(s32*)a1 == 0 || *(s32*)a1 == 6) w20 = D_00348420[a3];
    }
    func_0013c080(p, s6, a2, a3, &flag, 1, &w20, &w24);
    if (func_0013bc40(p, a2) && func_0013b9e0(p, t1)) flag = 1;
    v = func_001b8e88(*(u16*)(a1 + s4 * 12 + 14));
    r = func_0013b5d0(p, a2, w20, s6, flag, t2 + 8, t3, func_00192048(*(u32*)(v + 8)), 1.0f, s8, 2);
    if (w24 != -1) *(s32*)(r + 392) = w24;
    func_0013bc50(p, a1, a2, a3, flag, s8, v, r);
    *(s32*)(p + a2 * 4 + 204) = s4;
}
} // n0013c190

// 0013c3b8 (from src/anon/batch_w3799_nsamam.cpp)
namespace n0013c3b8 {
struct W1639Sprite {
    u8 pad0[0x188];
    s32 on188;
    s32 on18c;
    s32 on190;
};
struct W1639Cmd {
    u8 pad0[0xcc];
    s32 cursor[4];            
    s32 count[4];             
};
struct W1639Entry {
    u8 pad0[2];
    u16 id;                 
    u8 pad4;
    u8 kind;                
    u8 pad6[6];
};
struct W1639Menu {
    s32 type;                 
    u8 pad4[4];
    s32 count;                
    W1639Entry ent[8];        
    s32 sel;                  
};
extern s32 D_00348060[] asm("D_00348060");
u8* func_0013bb58(W1639Cmd*, W1639Menu*, s32, s32, u8, s32, s32) asm("func_0013bb58");
u8* func_001b8e88(u16) asm("func_001b8e88");
void func_0013c080(W1639Cmd*, W1639Entry*, s32, s32, u8*, s32, s32*, s32*) asm("func_0013c080");
s32 func_00192048(s32) asm("func_00192048");
s32 func_0013b988(W1639Cmd*, W1639Menu*, s32, s32, s32, s32) asm("func_0013b988");
W1639Sprite* func_0013b5d0(f32, W1639Cmd*, s32, s32, void*, u8, s32, s32, s32, s32, s32) asm("func_0013b5d0");
void func_0013c190(W1639Cmd*, W1639Menu*, s32, s32, u8, s32, s32, s32, W1639Entry*) asm("func_0013c190");
s32 func_0013bc40(W1639Cmd*, s32) asm("func_0013bc40");
void func_0013ce08(W1639Cmd*, s32) asm("func_0013ce08");
void func_0013c3b8(W1639Cmd* self, W1639Menu* m, s32 slot, s32 col, u8 force) asm("func_0013c3b8");
void func_0013c3b8(W1639Cmd* self, W1639Menu* m, s32 slot, s32 col, u8 force)
{
    u8 flag;
    s32 v;
    s32 extra;
    s32 i = 0;
    u8* item;
    s32 selX;
    s32 selY;
    s32 type = m->type;
    s32 sx = slot * 16;
    v = 0;
    func_0013bb58(self, m, slot, col, force, sx, type);
    s32 y;
    selY = -64;
    asm("" : "+m"(m->count) : "g"(selY));
    selX = 0;
    y = 410 - m->count * 22;
    if (i < m->count) {
    u16* pid = &m->ent[0].id;
    asm("" : "+r"(pid));
    do {
        item = func_001b8e88(*pid);
        flag = 0;
        extra = -1;
        if (self->cursor[slot] == i) flag = 1;
        if (force == 1) flag = force;
        if (self->count[slot] != m->count) flag = 1;
        if (m->sel == i) {
            selY = y;
            selX = sx + 28;
        } else {
            if (i == m->count - 1) v = D_00348060[type * 12 + col + 9];
            else v = D_00348060[type * 12 + col + 6];
            register s32 k asm("$18");
            asm("" : "=r"(k) : "0"((s32)m->ent[i].kind), "m"(flag));
            W1639Entry* e = &m->ent[i];

            func_0013c080(self, e, slot, col, &flag, 2, &v, &extra);
            s32 r = func_00192048(*(s32*)(item + 8));
            s32 q = func_0013b988(self, m, k, i, 0, 0);
            W1639Sprite* p = func_0013b5d0(1.0f, self, slot, v, e, flag, sx + 28, y, r, q, 2);
            s32 c = -1;
            asm("" : "+r"(c) : "r"(p));
            if (extra != c) p->on188 = extra;
        }
        y += 22; pid += 6; i++;
    } while (i < m->count);
    }
    func_0013c190(self, m, slot, col, force, type, selX, selY, &m->ent[m->sel]);
    self->count[slot] = m->count;
    if (func_0013bc40(self, slot)) func_0013ce08(self, m->count);
}
} // n0013c3b8

// 0013c688 (from src/anon/tiny_leaf.cpp)
namespace n0013c688 {
u32 func_0013c688(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013c688");
u32 func_0013c688(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(668));
    r14 = *(u32*)((u32)r15 + (s32)(2596));
    r2 = *(u32*)((u32)r14 + (s32)(0));
    return r2;
}
} // n0013c688

// 0013c698 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013c698 {
u32 func_0013c698(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0013c698");
u32 func_0013c698(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {                
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(668));
    r2 = 0u;
    if (r14 != 0u) {
        r15 = (u32)(*(u16*)((u32)r14 + (s32)(2590)));
        r2 = ((u32)0u < (u32)r15);
    }
    return r2;
}
} // n0013c698

// 0013c6b8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013c6b8 {
u32 func_0013c698(...) asm("func_0013c698");
extern u8 D_003484a0 asm("D_003484a0");
u32 func_0013c6b8(void) asm("func_0013c6b8");
u32 func_0013c6b8(void) {
    u32 r14 = *(u32*)((u32)&D_003484a0 + (s32)(0));
    u32 r2 = 0u;
    if (r14 != 0u) {
        r2 = func_0013c698(r14);
    }
    return r2;
}
} // n0013c6b8

// 0013c6e8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013c6e8 {
u32 func_0013c688(...) asm("func_0013c688");
extern u8 D_003484a0 asm("D_003484a0");
u32 func_0013c6e8(void) asm("func_0013c6e8");
u32 func_0013c6e8(void) {
    u32 r14 = *(u32*)((u32)&D_003484a0 + (s32)(0));
    if (r14 != 0u) {
        return func_0013c688(r14);
    }
    return 0u;
}
} // n0013c6e8

// 0013c720 (from src/anon/tiny_more2.cpp)
namespace n0013c720 {
extern u32 D_003484a0 asm("D_003484a0");
void func_0013c720(u32 a0,u32 a1,u32 a2,u32 a3) asm("func_0013c720");
void func_0013c720(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p=D_003484a0; *(u8*)((u32)p + (254)) = (u8)((u32)((s32)1)); }
} // n0013c720

// 0013c738 (from src/anon/batch_w58.cpp)
namespace n0013c738 {
struct VObj { void** vt; };
VObj* func_0016b0d0(void) asm("func_0016b0d0");
u8* func_00167f18(s32) asm("func_00167f18");
s32 func_0013c698(u8*) asm("func_0013c698");
s32 func_0013c8b0(u8*) asm("func_0013c8b0");
s32 func_0013c738(u8* p) asm("func_0013c738");
s32 func_0013c738(u8* p) {
    if (!p[681]) {
        p[681] = 1;
        return 0;
    }
    VObj* o = func_0016b0d0();
    if (o && ((s32 (*)(void*))o->vt[16])(o)) {
        if (*(u64*)(func_00167f18(0) + 8)) return 1;
    }
    if (func_0013c698(p)) return 1;
    return func_0013c8b0(p) != 0;
}
} // n0013c738

// 0013c7d0 (from src/anon/batch_w25.cpp)
namespace n0013c7d0 {
extern void* D_003484a0 asm("D_003484a0");
extern u8 D_003484a4 asm("D_003484a4");
s32 func_0013c738(void*) asm("func_0013c738");
s32 func_0013c7d0(void) asm("func_0013c7d0");
s32 func_0013c7d0(void) {
    void* p = D_003484a0;
    if (p) {
        if (func_0013c738(p)) return 1;
        if (D_003484a4 == 1) return 1;
    }
    return 0;
}
} // n0013c7d0

// 0013c820 (from src/anon/batch_wcx2.cpp)
namespace n0013c820 {
u32 func_0013b5d0(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, f32) asm("func_0013b5d0");
void func_00139570_c820(u32) asm("func_00139570");
void func_0013c820(u32 a0, u32 a1) asm("func_0013c820");
void func_0013c820(u32 a0, u32 a1) {
    func_00139570_c820(func_0013b5d0(a0, a1, 2, 0, 0, 0, 0, 0, 0x80e6e6e6, 2, 1.0f));
}
} // n0013c820

// 0013c878 (from src/anon/tiny_leaf.cpp)
namespace n0013c878 {
u32 func_0013c878(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013c878");
u32 func_0013c878(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = (u32)(*(u8*)((u32)r4 + (s32)(255)));
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
} // n0013c878

// 0013c888 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013c888 {
u32 func_0013c888(u32 a0, u32 a1) asm("func_0013c888");
u32 func_0013c888(u32 a0, u32 a1) {
    if (*(u8*)((u32)a0 + (s32)(255)) == (u8)1u) {
        *(u8*)((u32)a0 + (s32)(255)) = (u8)0u;
        return 1u;
    }
    return (u32)((a1 ^ *(u32*)((u32)a0 + (s32)(248))) != 0u);
}
} // n0013c888

// 0013c8b0
namespace dk {
extern u8 D_003484a0 asm("D_003484a0");
extern "C" u32 func_0013cb08(...);
extern "C" u32 func_001bcf38(...);
extern "C" u32 func_0013a810(...);
u32 COMMAND_DRAW::isInsertSkipCommand() {
    u32 t6;
    u32 t7 = *(u32*)((u32)this + (s32)(668));
    if (t7 == 0u) {
        t6 = 0u;
    } else {
        u32 s0 = *(u32*)((u32)t7 + (s32)(2536));
        if (func_0013cb08() != 0u) {
            t6 = 0u;
        } else {
            t6 = func_001bcf38(s0);  // state_in_set_5_10_13to18
        }
    }
    return t6;
}
}  // namespace dk

// 0013c900 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013c900 {
void func_0013b8e8(...) asm("func_0013b8e8");
void func_0013c900(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013c900");
void func_0013c900(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t7 = a1 << 2;
    t7 = t7 + a0;
    u32 t5 = *(u32*)(a2 + 8);
    u32 t6 = *(u32*)(t7 + 220);
    if (t6 != t5) {
        func_0013b8e8(a0, a1, a3);
    }
}
} // n0013c900

// 0013c938 (from src/anon/batch_w8019_nsa.c)
namespace n0013c938 {
typedef struct Q { u8 p0[32]; u32 f20; u8 p1[2240 - 36]; u32** cur; u8 p2[2536 - 2244]; u32* arr[4]; } Q;
typedef struct P { u8 p0[204]; s32 fcc[4]; u8 p1[236 - 220]; u32 fec; u8 p2[248 - 240]; u32 ff8; u8 p3[668 - 252]; Q* q; } P;
extern u32 D_004573c0[4] asm("D_004573c0");
void func_0013d3f8(P*) asm("func_0013d3f8");
u32 w8019_GetMode(void) asm("_ZN2YS6STATUS7GetModeEv");
void func_0013ce08(P*, s32) asm("func_0013ce08");
void func_0013b838(P*) asm("func_0013b838");
s32 func_001bcf38(u32*) asm("func_001bcf38");
void func_0013c900(P*, s32, u32*, s32) asm("func_0013c900");
u32 func_0013c878(P*) asm("func_0013c878");
void func_0013cbb8(P*, u32*, u32) asm("func_0013cbb8");
u32 func_0013c888(P*, u32) asm("func_0013c888");
void func_0013c3b8(P*, u32*, s32, u32, u32) asm("func_0013c3b8");
void func_0013c938(P* p) asm("func_0013c938");
void func_0013c938(P* p)
{
    s32 i, j, k, n;
    u32 t, m;
    Q* q;
    u32* e;
    func_0013d3f8(p);
    t = w8019_GetMode();
    for (j = 0; j < 4; j++) D_004573c0[j] = 0;
    q = p->q;
    e = q->arr[0];
    if (q->cur) n = (q->cur - q->arr) + 1;
    else n = 0;
    if (q->f20 & 8) {
        func_0013ce08(p, *e == 10 ? 0 : 4);
    } else if (func_001bcf38(e)) {
        func_0013c900(p, 0, e, n);
        m = func_0013c878(p);
        func_0013cbb8(p, e, m);
    } else {
        m = func_0013c888(p, t);
        for (i = 0; i < n; i++) {
            e = p->q->arr[i];
            func_0013c900(p, i, e, n);
            func_0013c3b8(p, e, i, t, m);
        }
        for (k = n; k < 4; k++) p->fcc[k] = -1;
    }
    p->fec = *p->q->arr[0];
    func_0013b838(p);
    p->ff8 = t;
}
} // n0013c938

// 0013cb08 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013cb08 {
u32 ctarget_0013cb08(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013cb08");
u32 ctarget_0013cb08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t6 = *(u32*)(a0 + 0x29cu);
    if (t6 == 0) return 0;
    u32 t7 = *(u32*)(*(u32*)(t6 + 0x9e8u));
    return (u32)((t7 ^ 0xeu) < 1u);
}
} // n0013cb08

// 0013cb30
namespace dk {
u32 COMMAND_DRAW::getSqd() {
    if (func_0013cb08(*(u32*)((u32)&D_003484a0 + (s32)(0))) != 0u) {
        u32 t7 = *(u32*)((u32)&D_003484a0 + (s32)(0));
        return *(u32*)((u32)t7 + (s32)(672));
    }
    u32 t7 = *(u32*)((u32)&D_003484a0 + (s32)(0));
    u32 t6 = *(u32*)((u32)t7 + (s32)(676));
    if (t6 != 0u) return t6;
    return func_0013a810();
}
}  // namespace dk

// 0013cb80 (from src/anon/tiny.cpp)
namespace n0013cb80 {
u32 func_0013cb80(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013cb80");
u32 func_0013cb80(u32 a0, u32 a1, u32 a2, u32 a3) {                      
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (-32688)));
}
} // n0013cb80

// 0013cb90
namespace dk {
u32 COMMAND_DRAW::getShortCutType() {
    u32 r15 = (u32)(0x0035u << 16);
    u32 r4 = *(u32*)((u32)r15 + (s32)(-31584));
    u32 r2 = func_0013cb08(r4);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace dk

// 0013cbb8 (from src/anon/batch_w317.cpp)
namespace n0013cbb8 {
struct W317E { u16 a; u16 id; u8 x; u8 b; u8 c; u8 d; u32 e; };
struct W317H { s32 kind; s32 pad; s32 count; W317E e[1]; };
s32 func_0013cb90(void) asm("func_0013cb90");
u32 func_001b8e88(u32) asm("func_001b8e88");
s32 func_0013b988(u8*, W317H*, u32, s32, s32, s32) asm("func_0013b988");
u32 func_00192048(u32) asm("func_00192048");
void func_0013b5d0(u8*, s32, s32, void*, u32, s32, s32, u32, f32, u32, s32) asm("func_0013b5d0");
void func_0013c820(u8*, s32) asm("func_0013c820");
void func_0013ce08(u8*, s32) asm("func_0013ce08");
extern s32 D_00348520[][5] asm("D_00348520");
void func_0013cbb8(u8* self, W317H* h, u8 a2) asm("func_0013cbb8");
void func_0013cbb8(u8* self, W317H* h, u8 a2) {
    self[255] = 1;
    s32 idx = func_0013cb90();
    s32 c0 = D_00348520[idx][0];
    if (h->kind == 10) c0 = 8;
    func_0013b5d0(self, 0, c0, 0, a2, 28, 388 - h->count * 22, 0, 1.0f, 0x80b4b4b4, 2);
    s32 y = 410 - h->count * 22;
    s32 i = 0;
    if (h->count > 0) {
        W317E* e = h->e;
        W317H* p = h;
        do {
            u8* q = (u8*)func_001b8e88(p->e[0].id);
            s32 c = 0;
            s32 r = func_0013b988(self, h, p->e[0].b, i++, 0, 1);                       
            if (p->e[0].c) c = D_00348520[idx][p->e[0].c];
            p = (W317H*)((u8*)p + 12);
            u32 t = func_00192048(*(u32*)(q + 8));
            func_0013b5d0(self, 0, c, e, a2, 28, y, t, 1.0f, r, 2);
            y += 22;
            e++;
        } while (i < h->count);
    }
    *(s32*)(self + 220) = h->count;
    for (s32 j = h->count; j < 7; j++) func_0013c820(self, 0);
    __asm__("" : "+r"(self));
    func_0013ce08(self, h->count);
}
} // n0013cbb8

// 0013cdc8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013cdc8 {
u32 func_0023aa98(...) asm("func_0023aa98");
void func_0013cdc8(u32 a0, u32 a1) asm("func_0013cdc8");
void func_0013cdc8(u32 a0, u32 a1) {
    u32 s0 = a1;
    if (func_0023aa98((u32)((s32)a1 + (24))) == 0u) {
        *(u32*)((u32)s0 + (s32)(432)) = 0u;
        return;
    }
    *(u32*)((u32)s0 + (s32)(432)) = 2u;
}
} // n0013cdc8

// a constant no code loads (retail .rodata 0x36ad54)
extern "C" const s32 D_0036ad54 = 36;

// 0013ce08 (from src/anon/batch_w3700.cpp)
namespace n0013ce08 {
struct W1640Info {
    u16 flags;
    u16 id;
    u8 pad4;
    u8 kind;
};
struct W1640Owner {
    u8 pad0[0xa1c];
    W1640Info info;
};
struct W1640Cmd {
    u8 pad0[0xf0];
    s32 lastId;
    s32 lastCol;
    u8 padF8[0xfc - 0xf8];
    u8 active;
    u8 padFD;
    u8 flash;
    u8 padFF;
    s32 tag;
    u8 pad104[0x29c - 0x104];
    W1640Owner* owner;
    u8 pad2a0[4];
    s32 unk2A4;
};
struct W1640Spr {
    u8 pad0[0x110];
    s32 unk110;
    u8 pad114[0x198 - 0x114];
};
struct W1640Pool {
    u8 pad0[0x3300];
    s32 freeIdx[32];
    s32 nFree;
};
extern s32 D_00348548[][6] asm("D_00348548");
extern s32 D_003484f8[] asm("D_003484f8");
extern f32 D_0036ad70[] asm("D_0036ad70");
extern W1640Pool* D_00348054 asm("D_00348054");
s32 func_0013cb90(void) asm("func_0013cb90");
s32 func_0013cb80(void) asm("func_0013cb80");
s32 func_0013cb30(void) asm("func_0013cb30");
u8* func_001b8e88(u32) asm("func_001b8e88");
u32 func_00192048(u32) asm("func_00192048");
void* func_0013b5d0(W1640Cmd*, s32, s32, void*, u32, s32, s32, u32, f32, u32, s32) asm("func_0013b5d0");
void func_00139580(void*) asm("func_00139580");
void func_00139570(void*) asm("func_00139570");
void func_00139740(void*) asm("func_00139740");
s32 func_001396c0(void*) asm("func_001396c0");
void func_0013cdc8(W1640Cmd*, void*) asm("func_0013cdc8");
void func_001386e0(W1640Spr*, s32, s32, s32, s32, s32) asm("func_001386e0");
void func_00138c40(W1640Spr*, s32, s32) asm("func_00138c40");
f32 func_0013b2e8(void) asm("func_0013b2e8");
void func_00138d48(f32, f32, f32, f32, W1640Spr*) asm("func_00138d48");
static inline __attribute__((always_inline)) W1640Spr* W1640_Alloc(void)
{
    W1640Pool* o = D_00348054;
    o->nFree--;
    return (W1640Spr*)((u8*)o + o->freeIdx[o->nFree] * 0x198);
}
void func_0013ce08(W1640Cmd* self, s32 n) asm("func_0013ce08");
void func_0013ce08(W1640Cmd* self, s32 n)
{
    s32 y = 377 - n * 22;
    s32 idx = func_0013cb90();
    W1640Info* info = &self->owner->info;
    u32 id = info->id;
    u8 kind = info->kind;
    u32 changed = 0;
    if (info->flags & 2) changed = 1;
    if (self->lastId != id) changed = 1;
    s32 c;
    void* p;
    if (id) {
        self->active = 1;
        u8* item = func_001b8e88(id);
        s32 r = idx * 6;
        c = ((s32*)D_00348548)[r];
        if (kind == 7) c = D_00348548[idx][1];
        else if ((u8)((*(s32*)(item + 12) >> 3) & 1)) c = D_00348548[idx][2];
        if (c != self->lastCol) changed = 1;
        u32 t = func_00192048(*(u32*)(item + 8));
        self->tag = t;
        asm("" : "+r"(changed));                                                                            
        p = func_0013b5d0(self, 0, c, info, changed, 36, y, t, D_0036ad70[kind], D_003484f8[kind], 2);
        func_00139580(p);
        if (!self->flash) self->tag = 0;
    } else {
        if (self->tag == 0) c = D_00348548[idx][3];
        else c = D_00348548[idx][4];
        p = func_0013b5d0(self, 0, c, info, changed, 36, y, self->tag, 1.0f, 0x80e6e6e6, 2);
        func_00139740(p);
        if (changed != 1) {
            if (self->active != 1) goto hide;
            if (func_001396c0(p)) goto clr;
        }
        func_00139580(p);
        goto common;
    clr:
        self->active = 0;
    hide:
        func_00139570(p);
    }
common:
    func_0013cdc8(self, p);
    self->lastId = id;
    self->lastCol = c;
    if (self->flash == 1) {
        W1640Spr* s = W1640_Alloc();
        s32 z = func_0013cb80() + 32;
        func_001386e0(s, 5303, func_0013cb30(), z, D_00348548[idx][5], 2);
        func_00138c40(s, 36, y);
        func_00138d48(1.0f, 1.0f, 1.0f, func_0013b2e8(), s);
        self->flash = 0;
        if (self->unk2A4 && s->unk110 >= 100) {
            s = W1640_Alloc();
            func_001386e0(s, 5400, func_0013cb30(), z, 99, 2);
            func_00138c40(s, 28, 322);
        }
    }
}
} // n0013ce08

// 0013d1d0 (from src/anon/batch_w1732.cpp)
namespace n0013d1d0 {
void func_00139598(void*) asm("func_00139598");
struct T0013d1d0 { u8 pad[0x20]; u32 flags; };
struct S0013d1d0 { u8 pad[0x104]; u8 sub[0x198]; T0013d1d0* q; };
void func_0013d1d0(S0013d1d0* p) asm("func_0013d1d0");
void func_0013d1d0(S0013d1d0* p) {
    if (__builtin_expect(p->q && (p->q->flags & 8), 0)) func_00139598(p->sub);
}
} // n0013d1d0

// 0013d208 (from src/anon/batch_w89.cpp)
namespace n0013d208 {
struct Pair8 { u32 x, y; };
extern Pair8 D_00348578[] asm("D_00348578");
s32 func_0013cb80(void) asm("func_0013cb80");
s32 func_0013cb90(void) asm("func_0013cb90");
u32 func_0013cb30(void) asm("func_0013cb30");
void func_001386e0(u8*, u32, u32, s32, u32, u32) asm("func_001386e0");
void func_00138c40(u8*, u32, u32) asm("func_00138c40");
f32 func_0013b2a8(u8*) asm("func_0013b2a8");
void func_00138d48(u8*, f32, f32, f32, f32) asm("func_00138d48");
void func_0013d1d0(u8*) asm("func_0013d1d0");
void func_0013d208(u8* o) asm("func_0013d208");
void func_0013d208(u8* o) {
    s32 a = func_0013cb80();                      
    u8* s = o + 260;
    s32 b = func_0013cb90();
    a += 32;
    u32 c = func_0013cb30();
    Pair8* e = &D_00348578[b];
    func_001386e0(s, 5301, c, a, e->x, 1);
    func_00138c40(s, 28, 322);
    *(u32*)(s + 392) = e->y;
    f32 r = func_0013b2a8(o);                     
    func_00138d48(s, 1.0f, 1.0f, 1.0f, r);
    func_0013d1d0(o);
}
} // n0013d208

// 0013d2d0 (from src/anon/batch_w68.cpp)
namespace n0013d2d0 {
struct Pair1 { u32 a, b; };
extern Pair1 D_00348578[] asm("D_00348578");
u8* func_0013cb80(void) asm("func_0013cb80");
s32 func_0013cb90(void) asm("func_0013cb90");
u32 func_0013cb30(void) asm("func_0013cb30");
void func_001386e0(void*, u32, u32, void*, u32, u32) asm("func_001386e0");
void func_00138c40(void*, u32, u32) asm("func_00138c40");
f32 func_0013b2a8(void*) asm("func_0013b2a8");
void func_00138d48(void*, f32, f32, f32, f32) asm("func_00138d48");
void func_0013d1d0(void*) asm("func_0013d1d0");
void func_0013d2d0(u8* p) asm("func_0013d2d0");
void func_0013d2d0(u8* p) {
    u8* s = p + 260;
    u8* a = func_0013cb80();                      
    s32 i = func_0013cb90();
    func_001386e0(s, 5301, func_0013cb30(), a + 32, D_00348578[i].b, 1);
    func_00138c40(s, 28, 322);
    func_00138d48(s, 1.0f, 1.0f, 1.0f, func_0013b2a8(p));
    func_0013d1d0(p);
}
} // n0013d2d0

// 0013d390 (from src/anon/auto80_199_queue.cpp)
namespace n0013d390 {
u32 func_0013d390(u32 a0) asm("func_0013d390");
u32 func_0013d390(u32 a0) {
    u32 s0 = a0 + 260;
    u32 v0;

    if (*(u8*)(s0 + 404) != 0) {
        goto Lret1;
    }

    if (func_0013c7d0() == 0) {
        goto Lret0;
    }

    v0 = func_0013cb90();
    v0 = (v0 << 3);
    v0 = v0 + (u32)&D_00348578;
    func_00138c10(s0, *(u32*)(v0 + 4));

Lret1:
    return 1;
Lret0:
    return 0;
}
} // n0013d390

// 0013d3f8 (from src/anon/batch_wcx.cpp)
namespace n0013d3f8 {
s32 func_0013d390(void) asm("func_0013d390");
void func_00139a38(s32) asm("func_00139a38");
void func_001399c0(s32) asm("func_001399c0");
void func_00139ab0(s32) asm("func_00139ab0");
void func_00139948(s32) asm("func_00139948");
void func_0013b2d8(f32) asm("func_0013b2d8");
f32 func_0013b2a8(u8*) asm("func_0013b2a8");
void func_00138d48(u8*, f32, f32, f32, f32) asm("func_00138d48");
void func_0013d3f8(u8* p) asm("func_0013d3f8");
void func_0013d3f8(u8* p)
{
    if (!p[253]) {
        if (func_0013d390() == 0) {
            func_00139a38(2);
            func_001399c0(2);
        } else {
            p[253] = 1;
            func_0013b2d8(1.0f);
            func_00139ab0(2);
            func_00139948(2);
        }
    }
    func_00138d48(p + 260, 1.0f, 1.0f, 1.0f, func_0013b2a8(p));
}
} // n0013d3f8

// 0013d498
namespace dk {
u32 COMMAND_DRAW::isSpecialCommand() {
    u32 t6 = *(u32*)((u32)&D_003484a0 + (s32)(0));
    u32 ret = 0u;
    if (t6 != 0u) {
        ret = func_0013cb08(t6);
    }
    return ret;
}
}  // namespace dk

// 0013d4c8 (from src/anon/auto80_199_queue.cpp)
namespace n0013d4c8 {
void func_0013b838(u32 a0) asm("func_0013b838");
void func_0013d4c8(void) asm("func_0013d4c8");
void func_0013d4c8(void) {
    u32* p = &D_004573c0;
    s32 i = 3;

L0013d4e0:
    *p = 0;
    i = i - 1;
    if (i >= 0) {
        p = (u32*)((u8*)p + 4);
        goto L0013d4e0;
    }

    func_0013b838(D_003484a0);
    *(u8*)(D_003484a0 + 253) = 0;
    *(u8*)(D_003484a0 + 252) = 0;
    *(u8*)(D_003484a0 + 681) = 0;
    *(u32*)(D_003484a0 + 240) = 0;
    *(u32*)(D_003484a0 + 244) = 0xFFFFFFFFu;
    *(u8*)(D_003484a0 + 255) = 0;
    func_0013d7d0();
}
} // n0013d4c8

// 0013d550 (from src/anon/batch_w80.cpp)
namespace n0013d550 {
struct U0_Ctx { u8 pad[260]; u8 sub[392]; u32 f652; u8 pad2[16]; u32 f672; };
struct U0_Cfg { u32 f0, f4, f8, f12; };
extern U0_Ctx* D_003484a0 asm("D_003484a0");
extern u8* D_00348050 asm("D_00348050");
extern U0_Cfg D_00348578 asm("D_00348578");
void func_0013b348(u32) asm("func_0013b348");
void func_002362b0(u8*, u32) asm("func_002362b0");
s32 func_0013a9d0(void) asm("func_0013a9d0");
void func_002368e8(u8*, f32) asm("func_002368e8");
void func_002367c8(u8*) asm("func_002367c8");
void func_0013d4c8(void) asm("func_0013d4c8");
u8* func_0013cb80(void) asm("func_0013cb80");
void func_001387f8(u8*, u32, u8*, u32) asm("func_001387f8");
void func_0013b2d8(f32) asm("func_0013b2d8");
void func_0013d550(u32 a, u32 b) asm("func_0013d550");
void func_0013d550(u32 a, u32 b) {
    u8* s;
    if (!D_003484a0) func_0013b348(0);
    s = D_00348050 + 32;
    func_002362b0(s, a);
    if (func_0013a9d0()) func_002368e8(s, 0.95f);
    func_002367c8(s);                            
    D_003484a0->f672 = b;
    func_0013d4c8();
    func_001387f8(D_003484a0->sub, b, func_0013cb80() + 32, D_00348578.f8);
    D_003484a0->f652 = D_00348578.f12;
    func_0013b2d8(0.0f);
}
} // n0013d550

// 0013d620 (from src/anon/batch_w55.cpp)
namespace n0013d620 {
void func_00138698(u32, u32) asm("func_00138698");
u32 func_0013a800(void) asm("func_0013a800");
void func_0013d4c8(void) asm("func_0013d4c8");
u32 func_0013a810(void) asm("func_0013a810");
u32 func_0013cb80(void) asm("func_0013cb80");
void func_001387f8(u32, u32, u32, u32) asm("func_001387f8");
void func_0013b2d8(f32) asm("func_0013b2d8");
extern u32 D_00348050 asm("D_00348050");
extern u8* D_003484a0 asm("D_003484a0");
extern u32 D_00348578[2] asm("D_00348578");
void func_0013d620(void) asm("func_0013d620");
void func_0013d620(void) {
    func_00138698(D_00348050, func_0013a800());
    *(u32*)(D_003484a0 + 672) = 0;
    func_0013d4c8();
    u32 s = func_0013a810();
    u32 v = func_0013cb80();                      
    func_001387f8((u32)(D_003484a0 + 260), s, v + 32, D_00348578[0]);
    *(u32*)(D_003484a0 + 652) = D_00348578[1];
    func_0013b2d8(0.0f);
}
} // n0013d620

// 0013d6b0 (from src/anon/batch_wcx.cpp)
namespace n0013d6b0 {
extern u8* D_003484a0 asm("D_003484a0");
extern u32 D_00348050 asm("D_00348050");
struct P2 { u32 a, b; };
extern P2 D_00348578 asm("D_00348578");
void func_0013b348(s32) asm("func_0013b348");
void func_00138698(u32, u32) asm("func_00138698");
void func_0013d4c8(void) asm("func_0013d4c8");
u8* func_0013cb80(void) asm("func_0013cb80");
void func_001387f8(u8*, u32, u8*, u32) asm("func_001387f8");
void func_0013b2d8(f32) asm("func_0013b2d8");
void func_0013d6b0(u32 a, u32 b) asm("func_0013d6b0");
void func_0013d6b0(u32 a, u32 b)
{
    if (!D_003484a0) func_0013b348(0);
    func_00138698(D_00348050, a);
    *(u32*)(D_003484a0 + 676) = b;
    func_0013d4c8();
    u8* r = func_0013cb80();                      
    func_001387f8(D_003484a0 + 260, b, r + 32, D_00348578.a);
    *(u32*)(D_003484a0 + 652) = D_00348578.b;
    func_0013b2d8(0.0f);
}
} // n0013d6b0

// 0013d750 (from src/anon/batch_w25.cpp)
namespace n0013d750 {
extern void* D_003484a0 asm("D_003484a0");
void func_0013d620(void) asm("func_0013d620");
void func_0013b128(void*) asm("func_0013b128");
void func_0013d7c0(void) asm("func_0013d7c0");
void func_001024a8(u32) asm("func_001024a8");
void func_0013d750(u32 a) asm("func_0013d750");
void func_0013d750(u32 a) {
    func_0013d620();
    func_0013b128(D_003484a0);
    *(u32*)((u8*)D_003484a0 + 676) = 0;
    func_0013d7c0();
    func_001024a8(a);
}
} // n0013d750

// 0013d798 (from src/anon/batch_w5.cpp)
namespace n0013d798 {
void func_0013d750(void) asm("func_0013d750");
void func_00102c18(u32, u32, void (*)(void)) asm("func_00102c18");
void func_0013d798(void) asm("func_0013d798");
void func_0013d798(void) {
    func_00102c18(1, 100000, func_0013d750);
}
} // n0013d798

// 0013d7c0 (from src/anon/tiny.cpp)
namespace n0013d7c0 {
extern u32 D_003484a4 asm("D_003484a4");
void func_0013d7c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013d7c0");
void func_0013d7c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_003484a4 = (u8)v;
}
} // n0013d7c0

// 0013d7d0 (from src/anon/tiny.cpp)
namespace n0013d7d0 {
void func_0013d7d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013d7d0");
void func_0013d7d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u8*)((u32)b + (-31580)) = (u8)0;
}
} // n0013d7d0

// 0013d7e0
namespace dk {
extern u32 D_003485e8 asm("D_003485e8");
extern u32 D_003485f0 asm("D_003485f0");
void* GAUGE_DRAW::getImage() {
    u32 p = D_003485e8;
    return (void*)((s32)p + 32);
}
}  // namespace dk

// 0013d7f0
namespace dk {
u32 GAUGE_DRAW::getFriend1() { return D_003485f0; }
}  // namespace dk

// 0013d800 (never written before)
namespace n0013d800 {
extern u32 D_003485f4 asm("D_003485f4");
u32 func_0013d800() asm("func_0013d800");
u32 func_0013d800() { return D_003485f4; }
} // n0013d800

// 0013d810 (from src/anon/tiny.cpp)
namespace n0013d810 {
u32 func_0013d810(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013d810");
u32 func_0013d810(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (-31240)));
}
} // n0013d810

// 0013d820 (from src/anon/batch_w1956_nsa.cpp)
namespace n0013d820 {
struct Heap1956;
struct HeapVt1956 { void* (*alloc)(Heap1956*, u32, u32); };
struct Heap1956 { HeapVt1956* vt; };
struct Sys1956 { u8 pad[20]; Heap1956* heap; };
struct Obj13d820w1956 { u32 vt; u32 f4; u32 f8; u32 f12; u8 pad[16]; u8 sub[1]; };
extern Sys1956* D_00347f80 asm("D_00347f80");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_003485fc asm("D_003485fc");
extern Obj13d820w1956* D_003485e8 asm("D_003485e8");
extern void* D_003485ec asm("D_003485ec");
extern void* D_003485f0 asm("D_003485f0");
extern void* D_003485f4 asm("D_003485f4");
extern void* D_003485f8 asm("D_003485f8");
void func_002361a0(void*) asm("func_002361a0");
void func_0031b130(void*) asm("func_0031b130");
void func_0031b3b8(void*) asm("func_0031b3b8");
void func_0031b4f0(void*) asm("func_0031b4f0");
s32 func_0013a7d0(s32) asm("func_0013a7d0");
void func_00138650(void*, s32, s32, s32) asm("func_00138650");
s32 func_0013dda0(s32) asm("func_0013dda0");
void func_00154f30(void*, s32, s32) asm("func_00154f30");
void func_001569d8(void*, s32) asm("func_001569d8");
void func_00154558(void*) asm("func_00154558");
void func_0013db60(void) asm("func_0013db60");
void ttarget0_0013d820(void) asm("_Z17ttarget0_0013d820v");
void ttarget0_0013d820(void) {
    Heap1956* h;
    void* p;
    D_003485fc = 0;
    h = D_00347f80->heap;
    Obj13d820w1956* o = (Obj13d820w1956*)h->vt->alloc(h, 448, 0);
    o->f12 = 0;
    o->vt = (u32)D_00347e80;
    func_002361a0(o->sub + 0);
    D_003485e8 = o;
    h = D_00347f80->heap;
    p = h->vt->alloc(h, 15616, 0);
    func_0031b130(p);
    D_003485ec = p;
    h = D_00347f80->heap;
    p = h->vt->alloc(h, 5552, 0);
    func_0031b3b8(p);
    D_003485f0 = p;
    h = D_00347f80->heap;
    p = h->vt->alloc(h, 5552, 0);
    func_0031b3b8(p);
    D_003485f4 = p;
    h = D_00347f80->heap;
    p = h->vt->alloc(h, 15588, 0);
    func_0031b4f0(p);
    D_003485f8 = p;
    func_00138650(D_003485e8, 6000, func_0013a7d0(1), 0);
    func_00154f30(D_003485f4, func_0013dda0(2), 1);
    func_00154f30(D_003485f0, func_0013dda0(1), 0);
    func_001569d8(D_003485ec, func_0013dda0(0));
    func_00154558(D_003485f8);
    func_0013db60();
}
} // n0013d820

// 0013d9e0 (from src/anon/batch_w81.cpp)
namespace n0013d9e0 {
struct VObj0 { void (**vt)(VObj0*); };
extern VObj0* D_003485f8 asm("D_003485f8");
extern VObj0* D_003485f4 asm("D_003485f4");
extern VObj0* D_003485f0 asm("D_003485f0");
extern VObj0* D_003485ec asm("D_003485ec");
extern VObj0* D_003485e8 asm("D_003485e8");
void u_call0_0013d9e0(void) asm("_Z16u_call0_0013d9e0v");
void u_call0_0013d9e0(void) {
    if (D_003485f8) { D_003485f8->vt[4](D_003485f8); D_003485f8 = 0; }
    if (D_003485f4) { D_003485f4->vt[4](D_003485f4); D_003485f4 = 0; }
    if (D_003485f0) { D_003485f0->vt[4](D_003485f0); D_003485f0 = 0; }
    if (D_003485ec) { D_003485ec->vt[4](D_003485ec); D_003485ec = 0; }
    if (D_003485e8) { D_003485e8->vt[4](D_003485e8); D_003485e8 = 0; }
}
} // n0013d9e0

// 0013dab0 (from src/anon/tiny_wrappers_imp.cpp)
namespace n0013dab0 {
u32 func_0013daf8(u32, u32, u32, u32) asm("func_0013daf8");
u32 func_0013dab0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013dab0");
u32 func_0013dab0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = (u32)((s32)0u + (1));
    r15 = (u32)(0x0035u << 16);
    *(u8*)((u32)r15 + (s32)(-31236)) = (u8)r14;
    return func_0013daf8(r4, r5, r6, r7);
}
} // n0013dab0

// 0013dad0 (from src/anon/tiny_jal_wrappers.cpp)
namespace n0013dad0 {
u32 func_0013db60(u32, u32, u32, u32) asm("func_0013db60");
u32 func_0013dad0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013dad0");
u32 func_0013dad0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_0013db60(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    *(u8*)((u32)r15 + (s32)(-31236)) = (u8)0u;
    return r2;
}
} // n0013dad0

// 0013daf8 (from src/anon/auto80_199_queue.cpp)
namespace n0013daf8 {
void func_0013daf8(void) asm("func_0013daf8");
void func_0013daf8(void) {
    if (D_003485fc == 0) {
        return;
    }

    func_00139858(3);
    func_00139ba0(3);
    func_00139858(4);
    func_00139ba0(4);
    func_00139858(5);
    func_00139ba0(5);
    func_00139858(6);
    func_00139ba0(6);
}
} // n0013daf8

// 0013db60 (from src/anon/tiny_auto80_solver.cpp)
namespace n0013db60 {
u32 func_001398d0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001398d0");
u32 func_00139b28(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00139b28");
u32 func_0013db60(void) asm("func_0013db60");
u32 func_0013db60(void) asm("func_0013db60");
u32 func_0013db60(void) {
    ((u32(*)(u32))func_001398d0)(3);
    ((u32(*)(u32))func_00139b28)(3);
    ((u32(*)(u32))func_001398d0)(4);
    ((u32(*)(u32))func_00139b28)(4);
    ((u32(*)(u32))func_001398d0)(5);
    ((u32(*)(u32))func_00139b28)(5);
    ((u32(*)(u32))func_001398d0)(6);
    return ((u32(*)(u32))func_00139b28)(6);
}
} // n0013db60

// 0013dbb0
namespace dk {
extern u8 D_003485ec asm("D_003485ec");
extern "C" void func_00157880(u32);
void GAUGE_DRAW::checkAlertOff() {
    u32 t6 = *(u32*)((u32)&D_003485ec + 0);
    if (t6 != 0u) {
        func_00157880(t6);
    }
}
}  // namespace dk

// 0013dbe0 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013dbe0 {
void func_0013dbe0(u32 a0) asm("func_0013dbe0");
void func_0013dbe0(u32 a0) {
    s32 t7 = 2;
    do {
        *(u32*)((u32)a0 + (s32)(0)) = 0u;
        t7 = (s32)(t7 + (-1));
        *(u32*)((u32)a0 + (s32)(12)) = 0u;
        a0 = (u32)((s32)a0 + (4));
    } while (t7 >= 0);
}
} // n0013dbe0

// 0013dc08 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013dc08 {
u32 func_0013dc08(u32 a0, u32 a1) asm("func_0013dc08");
u32 func_0013dc08(u32 a0, u32 a1) {                       
    for (s32 i = 0; i < 3; i++) {
        if (((u32*)a0)[i] == a1) return (u32)i;
    }
    return (u32)((s32)0u + (-1));
}
} // n0013dc08

// 0013dc38 (from src/anon/tiny_leaf.cpp)
namespace n0013dc38 {
void func_0013dc38(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013dc38");
void func_0013dc38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r5 = (u32)(r5 << 2);
    r5 = (u32)(r5 + r4);
    r15 = *(u32*)((u32)r5 + (s32)(12));
    *(u32*)((u32)r5 + (s32)(0)) = r6;
    r15 = (u32)(r15 | 0x0001u);
    *(u32*)((u32)r5 + (s32)(12)) = r15;
}
} // n0013dc38

// 0013dc58 (from src/anon/tiny_leaf.cpp)
namespace n0013dc58 {
void func_0013dc58(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013dc58");
void func_0013dc58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r5 = (u32)(r5 << 2);
    r5 = (u32)(r5 + r4);
    r15 = *(u32*)((u32)r5 + (s32)(12));
    *(u32*)((u32)r5 + (s32)(0)) = 0u;
    r15 = (u32)(r15 | 0x0001u);
    *(u32*)((u32)r5 + (s32)(12)) = r15;
}
} // n0013dc58

// 0013dc78 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013dc78 {
void func_0013dc78(u32 a0, u32 a1, u32 a2) asm("func_0013dc78");
void func_0013dc78(u32 a0, u32 a1, u32 a2) {
    a1 = (u32)(a1 << 2);
    u32 idx = (u32)(a2 >> 5);
    a0 = (u32)(a0 + a1);
    idx = (u32)(idx << 2);
    a0 = (u32)((s32)a0 + (12));
    a0 = (u32)(a0 + idx);
    a2 = (u32)(a2 & 31u);
    u32 val = *(volatile u32*)((u32)a0 + (s32)(0));
    u32 mask = 1u;
    mask = (u32)(mask << (a2 & 31u));
    val = (u32)(val | mask);
    *(volatile u32*)((u32)a0 + (s32)(0)) = val;
}
} // n0013dc78

// 0013dcb0 (from src/anon/tiny_auto80_solver.cpp)
namespace n0013dcb0 {
void func_0013dcb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0013dcb0");
void func_0013dcb0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0013dcb0");
void func_0013dcb0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    a1 <<= 2;
    u32 idx = a2 >> 5;
    a0 += a1;
    idx <<= 2;
    a0 += 12;
    a2 &= 31;
    a0 += idx;
    u32 mask = 1;
    u32 val = *(u32*)a0;
    mask <<= a2;
    mask = ~mask;
    val &= mask;
    *(u32*)a0 = val;
}
} // n0013dcb0

// 0013dce8 (from src/anon/tiny_leaf_more.cpp)
namespace n0013dce8 {
u32 func_0013dce8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013dce8");
u32 func_0013dce8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r5 = (u32)(r5 << 2);
    r15 = (u32)(r6 >> 5);
    r4 = (u32)(r4 + r5);
    r15 = (u32)(r15 << 2);
    r4 = (u32)(r4 + r15);
    r6 = (u32)(r6 & 0x001fu);
    r2 = *(u32*)((u32)r4 + (s32)(12));
    r15 = (u32)((s32)0u + (1));
    r15 = (u32)(r15 << (r6 & 31));
    r2 = (u32)(r2 & r15);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
} // n0013dce8

// 0013dd18 (from src/anon/tiny_leaf.cpp)
namespace n0013dd18 {
u32 func_0013dd18(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013dd18");
u32 func_0013dd18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r5 = (u32)(r5 << 2);
    r5 = (u32)(r5 + r4);
    r2 = *(u32*)((u32)r5 + (s32)(0));
    return r2;
}
} // n0013dd18

// 0013dd28 (from src/harata/libdk/gauge.cpp)
namespace n0013dd28 {
extern u32 D_00348638 asm("D_00348638");
u32 wtarget_0013dbe0(u32, u32, u32, u32) asm("_Z16wtarget_0013dbe0jjjj");
u32 GAUGE_init_raw(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2dk5GAUGE4initEv");
u32 GAUGE_init_raw(u32 a0, u32 a1, u32 a2, u32 a3) {
    return wtarget_0013dbe0((u32)&D_00348638, a1, a2, a3);
}
} // n0013dd28

// 0013dd48 (from src/anon/tiny_auto80_solver.cpp)
namespace n0013dd48 {
u32 func_0013dce8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0013dce8");
extern u8 D_00348638 asm("D_00348638");
u32 func_0013dd48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0013dd48");
u32 func_0013dd48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = r4;
    r6 = r5;
    r4 = (u32)&D_00348638;
    r5 = r15;    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0013dce8)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2 != 0) {
        return r2;
    }
    return r2;
}
} // n0013dd48

// 0013dd78 (from src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n0013dd78 {
u32 func_0013dcb0(u32, u32, u32, u32) asm("func_0013dcb0");
extern u8 D_00348638 asm("D_00348638");
u32 func_0013dd78(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013dd78");
u32 func_0013dd78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0013dcb0((u32)&D_00348638, a0, a1, a3);
}
} // n0013dd78

// 0013dda0 (from src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n0013dda0 {
u32 func_0013dd18(u32, u32, u32, u32) asm("func_0013dd18");
extern u8 D_00348638 asm("D_00348638");
u32 func_0013dda0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013dda0");
u32 func_0013dda0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0013dd18((u32)&D_00348638, a0, a2, a3);
}
} // n0013dda0

// 0013ddc0 (from src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n0013ddc0 {
u32 func_0013dc38(u32, u32, u32, u32) asm("func_0013dc38");
extern u8 D_00348638 asm("D_00348638");
u32 func_0013ddc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013ddc0");
u32 func_0013ddc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0013dc38((u32)&D_00348638, a0, a1, a3);
}
} // n0013ddc0

// 0013dde8 (from src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n0013dde8 {
u32 func_0013dc58(u32, u32, u32, u32) asm("func_0013dc58");
extern u8 D_00348638 asm("D_00348638");
u32 func_0013dde8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013dde8");
u32 func_0013dde8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0013dc58((u32)&D_00348638, a0, a2, a3);
}
} // n0013dde8

// 0013de08 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013de08 {
u32 func_0013dc08(...) asm("func_0013dc08");
u32 func_0013dc78(...) asm("func_0013dc78");
extern u8 D_00348638 asm("D_00348638");
void func_0013de08(u32 a0) asm("func_0013de08");
void func_0013de08(u32 a0) {
    u32 s0 = (u32)&D_00348638;
    s32 v0 = (s32)func_0013dc08(s0, a0);                       
    if (v0 >= 0) {
        func_0013dc78(s0, (u32)v0, 1u);
        return;
    }
}
} // n0013de08

// 0013de58 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013de58 {
u32 func_0013dc08(...) asm("func_0013dc08");
u32 func_0013dc78(...) asm("func_0013dc78");
extern u8 D_00348638 asm("D_00348638");
void func_0013de58(u32 a0) asm("func_0013de58");
void func_0013de58(u32 a0) {
    u32 s0 = (u32)&D_00348638;
    s32 v0 = (s32)func_0013dc08(s0, a0);                       
    if (v0 >= 0) {
        func_0013dc78(s0, (u32)v0, (u32)((s32)0u + (2)));
        return;
    }
}
} // n0013de58

// 0013dea8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013dea8 {
u32 func_0013dc08(...) asm("func_0013dc08");
u32 func_0013dc78(...) asm("func_0013dc78");
extern u8 D_00348638 asm("D_00348638");
void func_0013dea8(u32 a0) asm("func_0013dea8");
void func_0013dea8(u32 a0) {
    u32 s0 = (u32)&D_00348638;
    s32 v0 = (s32)func_0013dc08(s0, a0);                       
    if (v0 >= 0) {
        func_0013dc78(s0, (u32)v0, (u32)((s32)0u + (3)));
        return;
    }
}
} // n0013dea8

// 0013def8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0013def8 {
u32 func_0013dc08(...) asm("func_0013dc08");
u32 func_0013dc78(...) asm("func_0013dc78");
extern u8 D_00348638 asm("D_00348638");
void func_0013def8(u32 a0) asm("func_0013def8");
void func_0013def8(u32 a0) {
    u32 s0 = (u32)&D_00348638;
    s32 v0 = (s32)func_0013dc08(s0, a0);                       
    if (v0 >= 0) {
        func_0013dc78(s0, (u32)v0, (u32)((s32)0u + (4)));
        return;
    }
}
} // n0013def8

// 0013df48 (from src/anon/batch_w1670.cpp)
namespace n0013df48 {
struct S_348638 { s32 a, b, c; s32 d[3]; };
extern S_348638 D_00348638 asm("D_00348638");
void wtarget_0013df48(u32 a, u32 b, u32, u32) asm("_Z16wtarget_0013df48jjjj");
void wtarget_0013df48(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        S_348638* s = &D_00348638;
        s32* p = s->d;
        s32 i = 2;
        do { *p++ = 0; } while (--i != -1);
    }
}
} // n0013df48

// 0013df98 (from src/anon/tiny_wrappers_more.cpp)
namespace n0013df98 {
u32 func_0013df48(u32, u32, u32, u32) asm("func_0013df48");
u32 func_0013df98(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0013df98");
u32 func_0013df98(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0013df48(0x00000001u, 0x0000ffffu, a2, a3);
}
} // n0013df98
