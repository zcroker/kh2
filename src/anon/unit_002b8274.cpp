// Linked unit (see linked_units.tsv); one namespace per old matched source.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 002b8274 (was src/anon/batch_w62_O0.cpp)
namespace n002b8274 {
extern s32 D_01e21f40 asm("D_01e21f40");
extern u8 D_01e22040[] asm("D_01e22040");
s32 sceSifCallRpc(u8*, s32, s32, s32*, s32, s32*, s32, s32, s32) asm("sceSifCallRpc");
/*TARGET 002b8274*/
// Retries the request until it is accepted; returns the value sent.
s32 func_002b8274(s32 x) asm("_Z13func_002b8274i");
// Retries the request until it is accepted; returns the value sent.
s32 func_002b8274(s32 x) {
    s32 r;
    D_01e21f40 = x;
    do {
        r = sceSifCallRpc(D_01e22040, 1, 0, &D_01e21f40, 256, &D_01e21f40, 256, 0, 0);
    } while (r);
    return x;
}
}  // namespace n002b8274

// 002b82f8 (was src/anon/batch_w53_O0.cpp)
namespace n002b82f8 {
u32 func_002b82f8(void) asm("_Z13func_002b82f8Pv");
s32 sceSifCallRpc(void*, s32, s32, void*, s32, void*, s32, s32, s32) asm("sceSifCallRpc");
extern u8 D_01e22040[] asm("D_01e22040");
extern u32 D_01e21f40[] asm("D_01e21f40");
/*TARGET 002b82f8*/
// Retry until the call succeeds (returns 0), then read the first result word.
u32 func_002b82f8(void) asm("_Z13func_002b82f8Pv");
// Retry until the call succeeds (returns 0), then read the first result word.
u32 func_002b82f8(void) {
    s32 r;
    ;
    do {
        r = sceSifCallRpc(D_01e22040, 2, 0, D_01e21f40, 256, D_01e21f40, 256, 0, 0);
    } while (r != 0);
    return D_01e21f40[0];
}
}  // namespace n002b82f8

// 002b8374 (was src/anon/batch_w207_O0.cpp)
namespace n002b8374 {
u32 func_002b6708(u32, u32, u32) asm("func_002b6708");
/*TARGET 002b8374*/
u32 func_002b8374(u32 a) asm("func_002b8374");
u32 func_002b8374(u32 a) { return func_002b6708(2, 36, a); }
}  // namespace n002b8374

// 002b83b4 (was src/anon/batch_w204_O0.cpp)
namespace n002b83b4 {
extern void* func_002b6708(int, int) asm("func_002b6708");
void* func_002b83b4(void) asm("_Z13func_002b83b4Pv");
/*TARGET 002b83b4*/
void* func_002b83b4(void) asm("_Z13func_002b83b4Pv");
void* func_002b83b4(void) { return func_002b6708(1, 39); }
}  // namespace n002b83b4

// 002b83ec (was src/anon/batch_w55_O0.cpp)
namespace n002b83ec {
s32 func_002b6708(s32, s32, s32, s32) asm("func_002b6708");
/*TARGET 002b83ec*/
s32 func_002b83ec(s32 a, s32 b) asm("func_002b83ec");
s32 func_002b83ec(s32 a, s32 b) {
    return func_002b6708(3, 38, a, b);
}
}  // namespace n002b83ec

// 002b8434 (was src/anon/batch_w63_O0.cpp)
namespace n002b8434 {
s32 sceSifCallRpc(void*, s32, s32, void*, s32, void*, s32, s32, s32) asm("sceSifCallRpc");
extern u8 D_01e22040 asm("D_01e22040");
extern u32 D_01e21f40[64] asm("D_01e21f40");
/*TARGET 002b8434*/
// Retries an RPC call (send/receive through the same 256-byte buffer) until it succeeds.
u32 func_002b8434(u32 a) asm("func_002b8434");
// Retries an RPC call (send/receive through the same 256-byte buffer) until it succeeds.
u32 func_002b8434(u32 a) {
    s32 r;
    D_01e21f40[0] = a;
    do {
        r = sceSifCallRpc(&D_01e22040, 3, 0, D_01e21f40, 256, D_01e21f40, 256, 0, 0);
    } while (r != 0);
    return a;
}
}  // namespace n002b8434

// 002b84b8 (was src/anon/batch_w54_O0.cpp)
namespace n002b84b8 {
s32 sceSifCallRpc(void*, s32, s32, void*, s32, void*, s32, s32, s32) asm("sceSifCallRpc");
extern u8 D_01e22040[] asm("D_01e22040");
extern s32 D_01e21f40 asm("D_01e21f40");
/*TARGET 002b84b8*/
s32 func_002b84b8(void) asm("func_002b84b8");
s32 func_002b84b8(void) {
    s32 r;
    do {
        r = sceSifCallRpc(D_01e22040, 4, 0, &D_01e21f40, 256, &D_01e21f40, 256, 0, 0);
    } while (r != 0);
    return D_01e21f40;
}
}  // namespace n002b84b8

// 002b8534 (was src/anon/batch_wcx_O0.cpp)
namespace n002b8534 {
void func_003058a0(s32) asm("func_003058a0");
struct E104 { u8 pad[4]; s8 used; u8 pad2[11]; s32 id; u8 pad3[16]; s32 val; u8 pad4[64]; };
extern E104 D_01e2a080[] asm("D_01e2a080");
/*TARGET 002b8534*/
// 002b8534: look up the value of the live slot with this id
s32 func_002b8534(s32 id) asm("func_002b8534");
// 002b8534: look up the value of the live slot with this id
s32 func_002b8534(s32 id)
{
    func_003058a0(0);
    E104* e = D_01e2a080;
    for (s32 i = 0; i < 8; i++, e++) {
        if (e->used && e->id == id) return e->val;
    }
    return 0;
}
}  // namespace n002b8534

// 002b85e4 (was src/anon/batch_wcx_O0.cpp)
namespace n002b85e4 {
void func_003058a0(s32) asm("func_003058a0");
struct E104b { u8 pad[4]; s8 used; u8 pad2[11]; s32 id; u8 pad3[4]; s32 val; u8 pad4[76]; };
extern E104b D_01e2a080b[] asm("D_01e2a080");
/*TARGET 002b85e4*/
// 002b85e4: same lookup as 002b8534, other field
s32 func_002b85e4(s32 id) asm("func_002b85e4");
// 002b85e4: same lookup as 002b8534, other field
s32 func_002b85e4(s32 id)
{
    func_003058a0(0);
    E104b* e = D_01e2a080b;
    for (s32 i = 0; i < 8; i++, e++) {
        if (e->used && e->id == id) return e->val;
    }
    return 0;
}
}  // namespace n002b85e4

// 002b8694 (was src/anon/batch_w62_O0.cpp)
namespace n002b8694 {
/*TARGET 002b8694*/
// Byte-swaps a 32-bit word.
s32 func_002b8694(s32 x) asm("func_002b8694");
// Byte-swaps a 32-bit word.
s32 func_002b8694(s32 x) {
    s32 b[4];
    b[0] = x & 0xff;
    b[1] = (x >> 8) & 0xff;
    b[2] = (x >> 16) & 0xff;
    b[3] = (x >> 24) & 0xff;
    return (b[0] << 24) | (b[1] << 16) | (b[2] << 8) | b[3];
}
}  // namespace n002b8694

// 002b871c (was src/anon/batch_w97_O0.cpp)
namespace n002b871c {
// ---- 002b871c
struct Clip2b8 { s32 a, b, c, d, e, f, g; s32 xmax; s32 step; s32 ymax; s32 flag; };
struct Ctx2b8 { u8 pad[0x48000]; Clip2b8 clip; };
/*TARGET 002b871c*/
void func_002b871c(Ctx2b8* p) asm("func_002b871c");
void func_002b871c(Ctx2b8* p) {
    p->clip.a = p->clip.b = p->clip.c = p->clip.d = p->clip.e = p->clip.f = p->clip.g = 0;
    p->clip.xmax = 16383;
    p->clip.step = 64;
    p->clip.ymax = 16383;
    p->clip.flag = 0;
}
}  // namespace n002b871c

// 002b8824 (was src/anon/batch_wcx2_O0.cpp)
namespace n002b8824 {
struct Ctl78 { s32 on; s32 f4, f8, f12, f16, f20; s32 f24; u32 a, b, c, d; s32 f44, f48, f52; };
struct Obj78 { u8 pad[0x48000]; Ctl78 ctl; };
/*TARGET 002b8824*/
void func_002b8824(Obj78* o, u32 a, u32 b, u32 c, u32 d) asm("func_002b8824");
void func_002b8824(Obj78* o, u32 a, u32 b, u32 c, u32 d)
{
    o->ctl.f4 = o->ctl.f8 = o->ctl.f12 = o->ctl.f16 = o->ctl.f20 = 0;
    o->ctl.f24 = 0x8000;
    o->ctl.a = a;
    o->ctl.b = b;
    o->ctl.c = c;
    o->ctl.d = d;
    o->ctl.on = 1;
    o->ctl.f44 = o->ctl.f48 = o->ctl.f52 = 0;
}
}  // namespace n002b8824

// 002b8984 (was src/anon/batch_w40_O0.cpp)
namespace n002b8984 {
struct S2b8984 { u8 pad[0x4801c]; u32 a; u32 b; };
/*TARGET 002b8984*/
s32 func_002b8984(S2b8984* p, u32 a, u32 b) asm("func_002b8984");
s32 func_002b8984(S2b8984* p, u32 a, u32 b) {
    p->a = a;
    p->b = b;
    return 0;
}
}  // namespace n002b8984

// 002b89e4 (was src/anon/batch_w57_O0.cpp)
namespace n002b89e4 {
u32 func_002b6708_5(u32, u32, u32, u32, u32) asm("func_002b6708");
struct Sub2b8 { u8 p[36]; u32 x; u32 y; };
u32 wtarget_002b89e4(u32 a, u32 b, u32 c) asm("_Z16wtarget_002b89e4jjjj");
/*TARGET 002b89e4*/
// Record two values in the sub-block at +0x48000, then dispatch (4, 28).
u32 wtarget_002b89e4(u32 a, u32 b, u32 c) asm("_Z16wtarget_002b89e4jjjj");
// Record two values in the sub-block at +0x48000, then dispatch (4, 28).
u32 wtarget_002b89e4(u32 a, u32 b, u32 c) {
    ((Sub2b8*)(a + 0x48000))->x = b;
    ((Sub2b8*)(a + 0x48000))->y = c;
    return func_002b6708_5(4, 28, a + 0x8000, b, c);
}
}  // namespace n002b89e4

// 002b8a70 (was src/anon/batch_w55_O0.cpp)
namespace n002b8a70 {
void func_002b78ec(u8*) asm("func_002b78ec");
/*TARGET 002b8a70*/
void func_002b8a70(u8* p) asm("func_002b8a70");
void func_002b8a70(u8* p) {
    func_002b78ec(p + 0x8000);
    *(u32*)(p + 0x48000) = 0;
}
}  // namespace n002b8a70

// 002b8ac0 (was src/anon/batch_w112_O0.cpp)
namespace n002b8ac0 {
struct StrmSt { s32 mode; s32 size; };
struct Strm { u8 pad[0x48000]; StrmSt st; };
s32 func_002b85e4(u8*) asm("func_002b85e4");
/*TARGET 002b8ac0*/
// Classifies the stream buffer state: 0 idle, 1 small, 2 in range, 3 behind.
s32 func_002b8ac0(Strm* p) asm("func_002b8ac0");
// Classifies the stream buffer state: 0 idle, 1 small, 2 in range, 3 behind.
s32 func_002b8ac0(Strm* p) {
    s32 r = 0;
    s32 n = func_002b85e4((u8*)p + 0x8000);
    if (p->st.mode != 0) {
        if (p->st.mode == 1 && p->st.size <= 0x1ffff) r = 1;
        if (p->st.mode == 2 && n > 0x8000 && n < p->st.size && p->st.size <= 0x3ffff) r = 2;
        if (p->st.mode == 2 && n > p->st.size && p->st.size < n - 0x8000) r = 3;
    }
    return r;
}
}  // namespace n002b8ac0

// 002b8c78 (was src/anon/batch_wcx2_O0.cpp)
namespace n002b8c78 {
struct Ctl78 { s32 on; s32 f4, f8, f12, f16, f20; s32 f24; u32 a, b, c, d; s32 f44, f48, f52; };
struct Obj78 { u8 pad[0x48000]; Ctl78 ctl; };
// ---- 002b8c78
struct Hdr78 { u8 pad0[12]; s32 f12; u8 pad1[4]; s32 f20; s32 f24; u8 pad2; u8 f29; };
void memcpy(void*, void*, u32) asm("memcpy");
s32 func_002b8694(s32) asm("func_002b8694");
s32 func_002b6708(s32, s32, void*, s32, u32, u32, s32, s32) asm("func_002b6708");
/*TARGET 002b8c78*/
void func_002b8c78(Obj78* o) asm("func_002b8c78");
void func_002b8c78(Obj78* o)
{
    s32 i;
    if (o->ctl.on != 0) {
        switch (o->ctl.on) {
        case 1:
            if (o->ctl.f44 == 0) {
                Hdr78* h = (Hdr78*)o;
                o->ctl.f20 = h->f29;
                if (h->f20 == 0) o->ctl.f8 = 0;
                else o->ctl.f8 = func_002b8694(h->f20) / 28 * o->ctl.f20 * 16 + 128;
                if (h->f24 == 0) o->ctl.f12 = func_002b8694(h->f12);
                else o->ctl.f12 = func_002b8694(h->f24) / 28 * o->ctl.f20 * 16 + 128;
                o->ctl.f48 = o->ctl.f8 & -0x8000;
            }
            memcpy((u8*)o + o->ctl.f4 + 0x8000, o, 0x8000);
            o->ctl.f4 = (o->ctl.f4 + 0x8000) % 0x40000;
            o->ctl.f44 += o->ctl.f24 / 2048;
            break;
        case 2:
            for (i = 0; i < o->ctl.f24 / 16; i++) {
                memcpy((u8*)o + o->ctl.f4 + 0x8000, (u8*)o + (o->ctl.f52 + i * 16), 16);
                o->ctl.f4 = (o->ctl.f4 + 16) % 0x40000;
            }
            o->ctl.f44 += 16;
            break;
        }
        o->ctl.f16 += o->ctl.f24;
        o->ctl.f24 = 0x8000;
        o->ctl.f52 = 0;
        if (o->ctl.f8 != 0 && o->ctl.f16 >= o->ctl.f12) {
            o->ctl.f4 -= o->ctl.f16 - o->ctl.f12;
            if (o->ctl.f4 < 0) o->ctl.f4 += 0x40000;
            o->ctl.f16 = o->ctl.f8;
            o->ctl.f44 = o->ctl.f48 / 2048;
            o->ctl.f52 = o->ctl.f8 - o->ctl.f48;
            o->ctl.f24 = 0x8000 - o->ctl.f52;
        }
        if (o->ctl.on == 1 && o->ctl.f44 * 2048 > 0x1ffff) {
            func_002b6708(7, 25, (u8*)o + 0x8000, 0x40000, o->ctl.a, o->ctl.b, 2, 2);
            o->ctl.on = 2;
        }
    }
}
}  // namespace n002b8c78

