#include "../common/types.h"

// Draw-state helpers (0x109c30-0x10a918), incl. the never-written getters 0x10a888 and 0x10a8c0. -g from the old _g copy of 0x109e30, -fno-strict-aliasing from 0x109d00.
// Each function keeps the declarations of the source it was matched in (namespace nADDR); every symbol
// is bound by asm label.
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 00109c30 (from src/anon/batch_w53.cpp)
namespace n00109c30 {
struct Slot88 { u32 f0; u32 key; u32 pad8[2]; u32 f16; u8 pad20[60]; u32 f80; u32 f84; };
extern u32 D_0033cc60 asm("D_0033cc60");
extern u32 D_0033cc68 asm("D_0033cc68");
extern Slot88* D_0033cc6c asm("D_0033cc6c");
// Find the first free slot whose key matches the current key and clear it.
Slot88* func_00109c30(void) asm("func_00109c30");
Slot88* func_00109c30(void) {
    u32 i;
    Slot88* r = 0;
    for (i = 0; i < D_0033cc68; i++) {
        if (D_0033cc6c[i].f0 == 0 && D_0033cc6c[i].key == D_0033cc60) break;
    }
    if (i < D_0033cc68) {
        r = &D_0033cc6c[i];
        r->f0 = 0;
        r->key = 0;
        r->f16 = 0;
        r->f80 = 0;
        r->f84 = 0;
    }
    return r;
}
}  // namespace n00109c30

// 00109cc0 (from src/anon/batch_w18.cpp)
namespace n00109cc0 {
// 00103b78: moved to src/common/unit_001031b0.cpp

struct Obj109 { u8 pad[16]; u32 f16; };
extern Obj109* D_0033cc90[] asm("D_0033cc90");
extern u32 D_0033cc78[] asm("D_0033cc78");
void func_00109cc0(s32 i, u32 v) asm("func_00109cc0");
void func_00109cc0(s32 i, u32 v) {
    if (!D_0033cc90[i]) D_0033cc78[i] = v;
    else D_0033cc90[i]->f16 = v;
    D_0033cc90[i] = (Obj109*)v;
}
}  // namespace n00109cc0

// 00109d00 (from src/anon/batch_w1821_nsa.cpp)
namespace n00109d00 {
struct W1821B38 { s64 d[7]; };
struct W1821In { s32 a; s32 b; };
struct W1821Ctx { s32 x; W1821In* in; };
struct W1821N { s32 a0; W1821Ctx* ctx; s32 a3; s32 a4; u8 pad[8]; W1821B38 b; };
W1821N* func_00109c30() asm("func_00109c30");
void func_00109cc0(s32, W1821N*) asm("func_00109cc0");
extern s32 D_0033cca4 asm("D_0033cca4");
W1821N* func_00109d00(s32 a0, W1821B38* b, W1821Ctx* c, s32 a3, s32 a4) asm("func_00109d00");
W1821N* func_00109d00(s32 a0, W1821B38* b, W1821Ctx* c, s32 a3, s32 a4) {
    W1821N* n = func_00109c30();
    s32 m = 4;
    n->a0 = a0;
    n->b = *b;
    n->a3 = a3;
    n->a4 = a4;
    n->ctx = c;
    W1821In* in = c->in;
    if ((in->a ^ 2) == 0) {
        m = 2;
        if (in->b == 1) {
            if (D_0033cca4 == 0) func_00109cc0(0, n);
            else func_00109cc0(1, n);
            D_0033cca4++;
            return n;
        }
    }
    func_00109cc0(m, n);
    return n;
}
}  // namespace n00109d00

// 00109e18 (from src/anon/tiny.cpp)
namespace n00109e18 {
void func_00133e50(void*) asm("func_00133e50");
// 00102670: moved to src/global/unit_001022c0.cpp
// 00103398: Tz::MenuBasic::GetMenuNameId, moved to src/common/unit_001031b0.cpp
void func_00109e18(BD_VALUE* bd) asm("func_00109e18");
void func_00109e18(BD_VALUE* bd) { func_00133e50(bd); }
}  // namespace n00109e18

// 00109e30 (from src/anon/batch_w1758_g.cpp)
namespace n00109e30 {
s32 func_00133f80(void) asm("func_00133f80");
s32 func_00133f60(void) asm("func_00133f60");
void func_00133ea8(void) asm("func_00133ea8");
void func_00109330(void) asm("func_00109330");
void func_00109340(void) asm("func_00109340");
s32 func_00109e30(int a) asm("func_00109e30");
s32 func_00109e30(int a) {
    s32 r;
    if ((u8)a) r = func_00133f80();
    else r = func_00133f60();
    func_00133ea8();
    func_00109330();
    func_00109340();
    return r;
}
}  // namespace n00109e30

// 00109e90 (from src/anon/tiny.cpp)
namespace n00109e90 {
void func_001340e8(void*) asm("func_001340e8");
void func_00109e90(BD_VALUE* bd) asm("func_00109e90");
void func_00109e90(BD_VALUE* bd) { func_001340e8(bd); }
}  // namespace n00109e90

// 00109ea8 (from src/anon/batch_w1785.cpp)
namespace n00109ea8 {
// 0x0019f7d0: definition moved into src/anon/unit_0019ee80.cpp

u64 func_00109ea8(u32 mode, s32 flag, u8 v) asm("func_00109ea8");
u64 func_00109ea8(u32 mode, s32 flag, u8 v)
{
    u8 n;
    switch (mode) {
    case 7:
        if (flag == 0) return v != 0x80 ? 0x5000d : 0x5078d;
    case 1:
    case 3:
    case 5:
        if (v != 0x80) {
            n = v > 16 ? 16 : 0;
            return 0x5000d | ((u64)n << 4);
        }
        return 0x5010d;
    case 11:
        if (flag == 0) return 0x50007 | ((u64)v << 4);
        break;
    default:
        break;
    }
    return 0x5000d;
}
}  // namespace n00109ea8

// 00109f58 (from src/anon/batch_w1770.cpp)
namespace n00109f58 {
u64 func_00109f58(u32 a0, u32 a1, u8 a2) asm("func_00109f58");
u64 func_00109f58(u32 a0, u32 a1, u8 a2) {
    switch (a0) {
    case 7:
        if (a1 == 0) return 0x8000000044ULL;
    case 1: case 3: case 5:
        if (a2 != 0x80) return 0x8000000044ULL;
        return 42;
    case 11:
        if (a1 == 0) return 0x8000000044ULL;
    case 2: case 4: case 8:
        return 0x8000000044ULL;
    default:
        return 0x44;
    }
}
}  // namespace n00109f58

// 00109fe8 (from src/anon/batch_w295.cpp)
namespace n00109fe8 {
extern u8 D_00340ed0[3] asm("D_00340ed0");
extern u32 D_00340ed4 asm("D_00340ed4");
extern u64 D_00340ed8[] asm("D_00340ed8");
struct N7;
typedef void (*CB7)(N7*, s32);
struct N7 { u32* w0; u32 w4; u32 w8; u32 w12; N7* next; u8 pad20[4]; u32 w24; u8 b28, b29, b30, b31, b32, b33, b34; u8 pad35[5]; u64 d40; u64 d48; u8 pad56[24]; CB7 cb80; CB7 cb84; };
s32 func_00109f58(u32, u32, u8) asm("func_00109f58");
s32 func_00109ea8(u32, u32, u8) asm("func_00109ea8");
void func_00108c00(u64*, u32, u64, u64, s32, s32, u64, u64) asm("func_00108c00");
s32 func_0011c8f8(u32*, u32*, s32, u32, u32, u32) asm("func_0011c8f8");
void func_00134490(void) asm("func_00134490");
void func_00109fe8(N7* n) asm("func_00109fe8");
void func_00109fe8(N7* n) {
  while (n) {
    if (n->w0 != 0) {
      if (!(n->w24 & 2)) { n->b32 = D_00340ed0[0]; n->b33 = D_00340ed0[1]; n->b34 = D_00340ed0[2]; }
      if ((s8)n->b31 < 0) {
        s32 a = func_00109f58(D_00340ed4, *(u32*)(*(u32*)(*(u32*)((u8*)n->w0 + 20) + 4) + 4), n->b31);
        s32 b = func_00109ea8(D_00340ed4, *(u32*)(*(u32*)(*(u32*)((u8*)n->w0 + 20) + 4) + 4), n->b31);
        func_00108c00(D_00340ed8, 63, n->d40, n->d48 & ~(1ull << 32), b, a,
          ((u64)n->b32 << 0) | ((u64)n->b33 << 8) | ((u64)n->b34 << 16),
          ((u64)n->b28 << 0) | ((u64)n->b29 << 8) | ((u64)n->b30 << 16) | ((u64)n->b31 << 24) | ((u64)0x3f800000 << 32));
        u32* s = n->w0;
        if (n->cb80) n->cb80(n, 0);
        if (func_0011c8f8(n->w0, &n->w24, 0, n->w4, n->w8, n->w12)) s = 0;
        if (n->cb84) n->cb84(n, 0);
        n->w0 = s;
      }
    } else {
      if (n->cb80) n->cb80(n, 0);
      if (n->cb84) n->cb84(n, 0);
    }
    func_00134490();
    n = n->next;
  }
}
}  // namespace n00109fe8

// 0010a1d0 (from src/anon/batch_wcx2.cpp)
namespace n0010a1d0 {
// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// --------------------
// 0010a1d0: draw queued 2D image entries (GS alpha/test setup with libgraph-style register packing, pre/post callbacks)
#define GS_SET_RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define GS_SET_FOGCOL(r, g, b) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16))
struct L4_10a1d0 { u8 pad[4]; s32 id; };
struct L3_10a1d0 { u8 pad[4]; L4_10a1d0* l4; };
struct Img10a1d0 { u8 pad[20]; L3_10a1d0* l3; };
struct E10a1d0;
typedef void (*Cb10a1d0)(E10a1d0*, s32);
struct E10a1d0 {
    Img10a1d0* img;
    s32 f4, f8, f12;
    E10a1d0* next;
    u8 pad0[4];
    s32 f24;
    u8 r, g, b, a;
    u8 fr, fg, fb;
    u8 pad1[5];
    u64 alpha;
    u64 test;
    u8 pad2[24];
    Cb10a1d0 pre;
    Cb10a1d0 post;
};
extern s32 D_00340ed4 asm("D_00340ed4");
extern u8 D_00340ed8[] asm("D_00340ed8");
u32 f10a1d0_w(s32, s32, u8) asm("func_00109f58");
u32 f10a1d0_h(s32, s32, u8) asm("func_00109ea8");
void func_00108c00(u8*, s32, u64, u64, u32, u32, u64, u64) asm("func_00108c00");
s32 f10a1d0_draw(Img10a1d0*, s32*, s32, s32, s32, s32) asm("func_0011c8f8");
void func_00134490(void) asm("func_00134490");
void func_0010a1d0(E10a1d0* e) asm("func_0010a1d0");
void func_0010a1d0(E10a1d0* e)
{
    for (; e; e = e->next) {
        if (e->img) {
            if ((s8)e->a >= 0) {
                u32 w = f10a1d0_w(D_00340ed4, e->img->l3->l4->id, e->a);
                u32 h = f10a1d0_h(D_00340ed4, e->img->l3->l4->id, e->a);
                func_00108c00(D_00340ed8, 63, e->alpha, e->test & ~((u64)1 << 32), h, w,
                              GS_SET_FOGCOL(e->fr, e->fg, e->fb), GS_SET_RGBAQ(e->r, e->g, e->b, e->a, 0x3f800000));
                Img10a1d0* img = e->img;
                if (e->pre) e->pre(e, 0);
                if (f10a1d0_draw(e->img, &e->f24, 0, e->f4, e->f8, e->f12)) img = 0;
                if (e->post) e->post(e, 0);
                e->img = img;
            }
            if (!e->img) {
                e->img = 0;
            } else {
                if ((s8)e->a >= 0) func_00134490();
                u32 w = f10a1d0_w(D_00340ed4, e->img->l3->l4->id, e->a);
                u32 h = f10a1d0_h(D_00340ed4, e->img->l3->l4->id, e->a);
                func_00108c00(D_00340ed8, 63, e->alpha | ((u64)0xff << 56), e->test | ((u64)1 << 32), h, w,
                              GS_SET_FOGCOL(e->fr, e->fg, e->fb), GS_SET_RGBAQ(e->r, e->g, e->b, e->a, 0x3f800000));
                if (e->pre) e->pre(e, 1);
                f10a1d0_draw(e->img, &e->f24, 1, e->f4, e->f8, e->f12);
                if (e->post) e->post(e, 1);
                e->img = 0;
            }
        } else {
            if (!e->f4) {
                if (e->pre) e->pre(e, 1);
                if (e->post) e->post(e, 1);
            }
        }
        func_00134490();
    }
}
}  // namespace n0010a1d0

// 0010a4d0 (from src/anon/batch_w66.cpp)
namespace n0010a4d0 {
// 00105c68: moved to src/common/shop.cpp
// ---- 0010a4d0
struct E10a { u32 f0; u32 f4; u32 f8; u32 pad; u8 v16[64]; u8 v80[64]; u8 v144[64]; u8 v208[64]; u32 f272; u32 pad2[3]; };
extern u32 D_0033cc68 asm("D_0033cc68");
extern E10a* D_0033cc70 asm("D_0033cc70");
void func_0011d740(u32, void*, void*, u32, void*, void*, u32, u32) asm("func_0011d740");
void func_0010a4d0(void) asm("func_0010a4d0");
void func_0010a4d0(void) {
    for (u32 i = 0; i < D_0033cc68; i++) {
        E10a* e = &D_0033cc70[i];
        if (e->f4) {
            func_0011d740(e->f4, e->v80, e->v16, e->f8, e->v144, e->v208, e->f0, e->f272);
            e->f4 = 0;
            e->f0 = 0;
            e->f8 = 0;
        }
    }
}
}  // namespace n0010a4d0

// 0010a580 (from src/anon/auto80_199_queue.cpp)
namespace n0010a580 {
void func_00134490() asm("func_00134490");
extern u8 D_0033cc84 asm("D_0033cc84");
u32 fn(...) asm("fn");
void func_0010a580(u32 a0) asm("func_0010a580");
void func_0010a580(u32 a0) {
    u32 s1 = a0 & 0xff;
    u8* s0 = *(u8**)&D_0033cc84;

    while (s0 != 0) {
        u32 fn = *(u32*)(s0 + 80);
        if (fn != 0) {
            ((void (*)(u8*, u32))fn)(s0, s1);
        }

        fn = *(u32*)(s0 + 84);
        if (fn != 0) {
            ((void (*)(u8*, u32))fn)(s0, s1);
        }

        func_00134490();
        s0 = *(u8**)(s0 + 16);
    }
}
}  // namespace n0010a580

// 0010a5f0 (from src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n0010a5f0 {
u32 func_001342c8(u32, u32, u32, u32) asm("func_001342c8");
extern u8 D_00340f30 asm("D_00340f30");
// 00102c18: FIELD::CreateTask, moved to src/common/unit_00102a70.cpp

// 00102f08: moved to src/common/title.cpp

// 001031b0: MENU::CreateTaskManager, moved to src/common/unit_001031b0.cpp

// 00103b48: moved to src/common/unit_001031b0.cpp

// 00103e78: moved to src/common/unit_001031b0.cpp

// 00104588: moved to src/common/gumimenu.cpp

// 00105d78: moved to src/common/shop.cpp

u32 func_0010a5f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0010a5f0");
u32 func_0010a5f0(u32 a0, u32 a1, u32 a2, u32 a3) {  // register_static_buffer
    return func_001342c8((u32)&D_00340f30, 0x0000000au, 0x13000000u, a3);
}
}  // namespace n0010a5f0

// 0010a618 (from src/anon/batch_w110.cpp)
namespace n0010a618 {
void func_00109330(void) asm("func_00109330");
void func_00109340(void) asm("func_00109340");
void func_001344b8(u32) asm("func_001344b8");
void func_00108998(void*) asm("func_00108998");
void func_00108f28(void*, u64) asm("func_00108f28");
void func_00109008(void*) asm("func_00109008");
void func_00109fe8(void*) asm("func_00109fe8");
void func_0010a1d0(void*) asm("func_0010a1d0");
void func_0010a5f0(void) asm("func_0010a5f0");
u64 func_00109050(void*) asm("func_00109050");
void func_00108ae0(void*, u32, u64, u64, u64, u64, u64, u64) asm("func_00108ae0");
void func_0010a580(void*) asm("func_0010a580");
void func_0010a4d0(void) asm("func_0010a4d0");
void func_00108a10(void*) asm("func_00108a10");
void func_00109070(void) asm("func_00109070");
extern void* D_0033cc78[5] asm("D_0033cc78");
extern u8 D_00340ed0[3] asm("D_00340ed0");
extern s32 D_00340ed4 asm("D_00340ed4");
extern u8 D_00340ed8[] asm("D_00340ed8");
// Runs the scene passes over the four draw lists (pass id in D_00340ed4).
void ctarget0_0010a618(void) asm("_Z17ctarget0_0010a618v");
void ctarget0_0010a618(void) {
    func_00109330();  // set_global_3756_return
    func_00109340();  // to_109450_zero
    func_001344b8(64);
    func_00108998(D_00340ed8);
    func_00108f28(D_00340ed8, (u64)D_00340ed0[0] | ((u64)D_00340ed0[1] << 8) | ((u64)D_00340ed0[2] << 16));
    func_00109008(D_00340ed8);
    if (D_0033cc78[0]) {
        D_00340ed4 = 1;
        func_00109fe8(D_0033cc78[0]);
        D_00340ed4 = 2;
        func_0010a1d0(D_0033cc78[0]);
        func_0010a5f0();
        func_00108ae0(D_00340ed8, 4, 0, 0, func_00109050(D_00340ed8), 0, 0, 0);
    }
    if (D_0033cc78[1]) {
        D_00340ed4 = 3;
        func_00109fe8(D_0033cc78[1]);
        D_00340ed4 = 4;
        func_0010a1d0(D_0033cc78[1]);
        func_0010a5f0();
        func_00108ae0(D_00340ed8, 4, 0, 0, func_00109050(D_00340ed8), 0, 0, 0);
    }
    D_00340ed4 = 5;
    func_00109fe8(D_0033cc78[2]);
    D_00340ed4 = 6;
    func_0010a580(0);
    D_00340ed4 = 7;
    func_00109fe8(D_0033cc78[4]);
    D_00340ed4 = 8;
    func_0010a1d0(D_0033cc78[2]);
    D_00340ed4 = 10;
    func_0010a4d0();
    D_00340ed4 = 11;
    func_0010a1d0(D_0033cc78[4]);
    func_00108a10(D_00340ed8);
    D_00340ed4 = 0;
    func_00109070();
}
}  // namespace n0010a618

// 0010a7d8 (from src/anon/batch_w2.cpp)
namespace n0010a7d8 {
// Batch w2: small leaf / wrapper functions.

struct Rgb8 { u8 r, g, b; };
extern Rgb8 D_00340ed0 asm("D_00340ed0");
// Set the current RGB colour.
void func_0010a7d8(u8 r, u8 g, u8 b) asm("func_0010a7d8");
void func_0010a7d8(u8 r, u8 g, u8 b) {  // store_triple_bytes
    u8* c = (u8*)&D_00340ed0;
    c[0] = r;
    c[1] = g;
    c[2] = b;
}
}  // namespace n0010a7d8

// 0010a800 (from src/anon/auto200_999.cpp)
namespace n0010a800 {
extern u8 D_00340ed0 asm("D_00340ed0");
void func_0010a800(u8 *a0, u8 *a1, u8 *a2) asm("func_0010a800");
void func_0010a800(u8 *a0, u8 *a1, u8 *a2) {  // copy_global_3bytes
    u8 *p = &D_00340ed0;
    *a0 = p[0];
    *a1 = p[1];
    *a2 = p[2];
}
}  // namespace n0010a800

// 0010a828 (from src/anon/batch_w217.cpp)
namespace n0010a828 {
extern f32 D_00340eb4 asm("D_00340eb4"); extern f32 D_00340eb8 asm("D_00340eb8"); extern f32 D_00340ebc asm("D_00340ebc"); extern f32 D_00340ec0 asm("D_00340ec0");
void func_0010a828(f32 a, f32 b) asm("func_0010a828");
void func_0010a828(f32 a, f32 b) {
    D_00340eb8 = b;
    D_00340eb4 = a;
    f32 d = b - a;
    D_00340ebc = -255.0f / d;
    D_00340ec0 = 255.0f * b / d;
}
}  // namespace n0010a828

namespace n0010a888 {
extern f32 D_00340eb4 asm("D_00340eb4");
extern f32 D_00340eb8 asm("D_00340eb8");
void func_0010a888(f32* a, f32* b) asm("func_0010a888");
void func_0010a888(f32* a, f32* b) {  // never written before
    *a = D_00340eb4;
    *b = D_00340eb8;
}
}  // namespace n0010a888

// 0010a8a8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0010a8a8 {
extern f32 D_00340ec8[] asm("D_00340ec8");
void func_0010a8a8(f32 f12, f32 f13) asm("func_0010a8a8");
void func_0010a8a8(f32 f12, f32 f13) {  // store_global_float_pair
    D_00340ec8[0] = f12;
    D_00340ec8[1] = f13;
}
}  // namespace n0010a8a8

namespace n0010a8c0 {
extern f32 D_00340ec8[2] asm("D_00340ec8");
void func_0010a8c0(f32* a, f32* b) asm("func_0010a8c0");
void func_0010a8c0(f32* a, f32* b) {  // never written before
    *a = D_00340ec8[0];
    *b = D_00340ec8[1];
}
}  // namespace n0010a8c0

// 0010a8e0 (from src/anon/tiny_auto80_queue.cpp)
namespace n0010a8e0 {
extern f32 D_00340ebc asm("D_00340ebc");
extern f32 D_00340ec0 asm("D_00340ec0");
extern f32 D_00340ec8[] asm("D_00340ec8");
void func_0010a8e0(f32* a0) asm("func_0010a8e0");
void func_0010a8e0(f32* a0) {
    a0[0] = D_00340ebc;
    a0[1] = D_00340ec0;
    a0[2] = D_00340ec8[0];
    a0[3] = D_00340ec8[1];
}
}  // namespace n0010a8e0

