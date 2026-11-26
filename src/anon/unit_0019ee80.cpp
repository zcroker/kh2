// Linked unit 0x19ee80-0x19fb70 (YS player helpers: flag bits, JUMPER, RECOM_FLAG, PLACE, OBJ_ATTACK; .rodata 0x36d40c
// holds the 0x19ef90 jump table). Built -G0 -g -fno-strict-aliasing (_g and _nsa old copies).
// Each function keeps the declarations of the source it was matched in (namespace nADDR).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../yasui/libys/jumper.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../yasui/libys/recomflag.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../yasui/libys/attack.hpp"
#include "../yasui/libys/battlereport.hpp"
#include "../yasui/libys/obj.hpp"
#include "../yasui/libys/sheet.hpp"

// ---- 0019ee80 from src/anon/tiny_auto80_solver.cpp (rewritten without volatile: under -g gcc fills the delay slot itself)
namespace n0019ee80 {
extern u8 D_0032de28[] asm("D_0032de28");
void func_0019ee80(s32 a, u32 b) asm("_Z13func_0019ee80jjjjjjjj");
void func_0019ee80(s32 a, u32 b) {
    u8* p = D_0032de28 + a * 8;
    p += (b >> 5) * 4;
    *(u32*)p |= 1 << (b & 31);
}
}  // namespace n0019ee80

// ---- 0019eeb8 from src/anon/batch_w36.cpp
namespace n0019eeb8 {
s32 func_00194878(u32, s32) asm("func_00194878");
extern u32 D_0032de28[][2] asm("D_0032de28");
static inline s32 bit_test(const u32* bits, u32 n) { return (bits[n >> 5] & (1 << (n & 31))) != 0; }
s32 func_0019eeb8(s32 a, u32 b) asm("func_0019eeb8");
s32 func_0019eeb8(s32 a, u32 b) {
    if (func_00194878(b, a)) return 1;
    return bit_test(D_0032de28[a], b);
}
}  // namespace n0019eeb8

// ---- 0019ef30 from src/anon/tiny_auto80_queue.cpp
namespace n0019ef30 {
extern u8 D_0032de28 asm("D_0032de28");
void func_0019ef30(void) asm("_Z13func_0019ef30v");
void func_0019ef30(void) {
    u32 t7 = (u32)&D_0032de28;
    s32 t6 = 18;
    do {
        *(u32*)((u32)t7 + (s32)(0)) = 0u;
        t6 = (s32)(t6 + (-1));
        *(u32*)((u32)t7 + (s32)(4)) = 0u;
        t7 = (u32)((s32)t7 + (8));
    } while (t6 >= 0);
}
}  // namespace n0019ef30

// ---- 0019ef60 from src/anon/tiny.cpp
namespace n0019ef60 {
extern u32 D_01c62f98 asm("D_01c62f98");
void func_0019ef60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0019ef60jjjj");
void func_0019ef60(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    D_01c62f98 = (u32)((s32)-1);
}
}  // namespace n0019ef60

// ---- 0019ef70 from src/yasui/libys/jumper.cpp
namespace YS {
void JUMPER::clear() {
    char* p = reinterpret_cast<char*>(this);
    *(u32*)(p + 0) = 0;
    *(u32*)(p + 20) = (u32)-1;
    *(u32*)(p + 24) = 0;
    *(u32*)(p + 28) = 0;
    *(u32*)(p + 32) = 0;
}
}  // namespace YS (0019ef70)

// ---- 0019ef90 from src/anon/batch_wcx2.cpp
namespace n0019ef90 {
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
struct S19ef90 { u8 a; u8 b; u8 c; u8 pad; s16 x; s16 y; s16 z; };
struct T19ef90 { s32 type; S19ef90 s; s32 w; };
union U19ef90 { s16 h; u16 uh; s32 i; };
S19ef90 func_00199718(s32, s32) asm("func_00199718");
void func_0019ef90(T19ef90* d, u8* s) asm("func_0019ef90");
void func_0019ef90(T19ef90* d, u8* s) {
    d->type = ((U19ef90*)s)->h;
    d->w = ((U19ef90*)(s + 10))->h;
    switch (((U19ef90*)s)->uh) {
    case 4:
        d->s.a = s[2];
        break;
    case 1:
        d->s.a = s[2];
        d->s.b = s[4];
        d->s.c = s[6];
        d->s.z = -1;
        d->s.y = -1;
        d->s.x = -1;
        break;
    case 2:
        d->s = func_00199718(*(s16*)(s + 8), *(s16*)(s + 2));
        d->s.c = s[6];
        break;
    case 0: case 6:
        break;
    }
}
}  // namespace n0019ef90

// ---- 0019f060 from src/yasui/libys/jumper.cpp
namespace YS {
u32 JUMPER::is_jump() { return (*(u32*)((u32)this + 0) != 0); }
}  // namespace YS (0019f060)

// ---- 0019f070 from src/anon/batch_w2351_nsa.cpp
namespace n0019f070 {
struct Mem { u8 b[4]; };
struct Sel { u8 a, b, c; u8 pad; u16 d, e, f; };
struct Cmd { s32 f0; u8 b4; u8 p[11]; s32 f10; s32 f14; s32 f18; s32 f1c; };
void func_001a8bb8(Mem*) asm("func_001a8bb8");
s32 func_0019f2a8(Cmd*, Sel*) asm("func_0019f2a8");
Mem* func_001a8bd0(s32) asm("func_001a8bd0");
void func_001a8d40(Mem*, s32) asm("func_001a8d40");
void func_001d94f8(Mem, Mem*) asm("func_001d94f8");
void func_001a60c8(void) asm("func_001a60c8");
void func_002533e0(s32, const void*) asm("func_002533e0");
void func_00104f58(Sel*, u32, s32, s32, s32) asm("func_00104f58");
void func_001ada38(s32) asm("func_001ada38");
void func_00149fe0(s32, u32) asm("func_00149fe0");
void func_0014a138(s32) asm("func_0014a138");
void func_00253180(s32, s32) asm("func_00253180");
extern s8 D_01c62fa0 asm("D_01c62fa0");
extern Mem D_01c62fa8 asm("D_01c62fa8") __attribute__((aligned(4)));
extern s32 D_01c62f98 asm("D_01c62f98");
void func_0019f070(Cmd* o, u32 a1) asm("func_0019f070");
void func_0019f070(Cmd* o, u32 a1) {
    Sel s;
    s32 ff = 0xffff;
    s.a = ff; s.b = ff; s.c = ff;
    s.d = ff; s.e = ff; s.f = ff;
    s32 mode = 0;
    if (D_01c62fa0 == 0) {
        func_001a8bb8(&D_01c62fa8);
        D_01c62fa0 = 1;
    }
    u32 fl = 0;
    s32 t = o->f10;
    if (t >= 0) {
        if (t & 0x4000) fl = (t & ~0x4000) | 0x80000000;
        else fl = t;
    }
    s32 v = func_0019f2a8(o, &s);
    fl |= a1;
    switch (o->f0) {
    case 4:
        fl = 1;
        if (v) {
            D_01c62f98 = o->b4;
        } else {
            if (D_01c62f98 >= 0) {
                o->b4 = D_01c62f98;
                D_01c62f98 = -1;
            }
            func_00149fe0(o->b4, 0);
        }
        break;
    case 6:
        func_0014a138(0);
        break;
    case 5:
        func_00253180(15, -1);
        break;
    }
    if (o->f14 >= 0) {
        Mem* m = func_001a8bd0(v ? s.a : -1);
        D_01c62fa8 = *m;
        func_001a8d40(m, o->f14);
        Mem* ps = &D_01c62fa8;
        s32 k = o->f1c;
        if (k != 0) {
            s32 a = 0;
            if (k == 1) goto blk;
            if (k == 2) {
                a = 2;
                func_001d94f8(D_01c62fa8, m);
            blk:
                func_001a60c8();
                func_002533e0(a, ps);
            }
            mode = 2;
        }
    }
    if (v) {
        func_00104f58(&s, fl, mode, 0, o->f18);
    } else if (o->f18) {
        func_001ada38(o->f18);
    }
}
}  // namespace n0019f070

// ---- 0019f2a8 from src/anon/batch_w1965_g.cpp
namespace n0019f2a8 {
struct W1965dV3 { u16 x, y, z; };
struct W1965dItem { u8 a, b, c; W1965dV3 v; };
struct W1965dSrc { s32 type; W1965dItem it; };
static inline void W1965dv3set(W1965dV3* p, s32 v) { p->x = v; p->y = v; p->z = v; }
extern W1965dItem D_0032bb00 asm("D_0032bb00");
s32 func_00181500(s32) asm("func_00181500");
W1965dItem func_00199718(s32, s32) asm("func_00199718");
s32 func_0019f2a8(W1965dSrc* s, W1965dItem* out) asm("func_0019f2a8");
s32 func_0019f2a8(W1965dSrc* s, W1965dItem* out)
{
    switch (s->type) {
    case 1:
    case 2:
        *out = s->it;
        break;
    case 3:
        *out = D_0032bb00;
        break;
    case 4:
        if (func_00181500(0x1071) && !func_00181500(0x1072)
            && (func_00181500(0x140f) || func_00181500(0x1822) || func_00181500(0x200b))) {
            out->a = 4;
            out->b = 0;
            out->c = 0;
            W1965dv3set(&out->v, 0xffff);
            break;
        }
        if (func_00181500(0x8cd)) goto fail;
        if (func_00181500(0x3834) || func_00181500(0x1c1c)) {
            *out = func_00199718(64, 18);
            break;
        }
        goto fail;
    default:
        goto fail;
    }
    if (func_00181500(0x872)) goto done;
    if (!func_00181500(0x86e)) goto done;
    if (!func_00181500(0x86f)) goto done;
    if (!func_00181500(0x870)) goto done;
    if (func_00181500(0x871)) *out = func_00199718(122, 2);
done:
    return 1;
fail:
    return 0;
}
}  // namespace n0019f2a8

// ---- 0019f480 from src/anon/tiny_auto80.cpp (rewritten without volatile, see 0019ee80)
namespace n0019f480 {
void func_0019f480(u32* p) asm("_Z13func_0019f480jjjj");
void func_0019f480(u32* p) {
    p[0] = 0;
    p[1] = 0;
}
}  // namespace n0019f480

// ---- 0019f490 from src/anon/auto200_999.cpp
namespace n0019f490 {
void func_0019f490(u32 a0, u32 a1) asm("_Z13func_0019f490jj");
void func_0019f490(u32 a0, u32 a1) {
    u32 idx = a1 >> 5;
    u32 mask = 1;
    idx <<= 2;
    a1 &= 31;
    a0 += idx;
    mask <<= a1;
    u32 val = *(u32 *)a0;
    *(u32 *)a0 = val | mask;
}
}  // namespace n0019f490

// ---- 0019f4b8 from src/anon/auto200_999.cpp
namespace n0019f4b8 {
void func_0019f4b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7) asm("_Z13func_0019f4b8jjjjjjjj");
void func_0019f4b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7) {
    u32 idx = a1 >> 5;
    a0 += 4;
    idx <<= 2;
    a1 &= 31;
    a0 += idx;
    u32 val = *(u32 *)a0;
    u32 mask = 1u << a1;
    val |= mask;
    *(u32 *)a0 = val;
}
}  // namespace n0019f4b8

// ---- 0019f4e8 from src/anon/batch_w1670.cpp
namespace n0019f4e8 {
static inline void bitclr_w1670(u32* p, u32 n) { u32* w = &p[n >> 5]; *w &= ~(1 << (n & 0x1f)); }
void func_0019f4e8(u32* p, u32 n) asm("func_0019f4e8");
void func_0019f4e8(u32* p, u32 n) {
    bitclr_w1670(p, n);
    bitclr_w1670(p + 1, n);
}
}  // namespace n0019f4e8

// ---- 0019f528 from src/anon/auto200_999.cpp
namespace n0019f528 {
u32 func_0019f528(u32 a0, u32 a1) asm("_Z13func_0019f528jj");
u32 func_0019f528(u32 a0, u32 a1) {
    return (((u32 *)a0)[a1 >> 5] & (1 << (a1 & 0x1f))) != 0;
}
}  // namespace n0019f528

// ---- 0019f550 from src/anon/tiny_leaf_more.cpp
namespace n0019f550 {
u32 func_0019f550(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0019f550jjjj");
u32 func_0019f550(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r15 = (u32)(r5 >> 5);
    r14 = (u32)((s32)0u + (1));
    r15 = (u32)(r15 << 2);
    r5 = (u32)(r5 & 0x001fu);
    r4 = (u32)(r4 + r15);
    r14 = (u32)(r14 << (r5 & 31));
    r2 = *(u32*)((u32)r4 + (s32)(4));
    r2 = (u32)(r2 & r14);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace n0019f550

// ---- 0019f578 from src/yasui/libys/recomflag.cpp
namespace YS {
void RECOM_FLAG::clear() {
    u32 a0 = (u32)this;
    u32 t6 = (u32)((s32)a0 + 96);
    do {
        *(u32*)((u32)a0 + (s32)(0)) = 0u;
        a0 = (u32)((s32)a0 + (12));
    } while ((s32)a0 < (s32)t6);
}
}  // namespace YS (0019f578)

// ---- 0019f5a8 from src/anon/auto200_999.cpp
namespace n0019f5a8 {
u32 func_0019f5a8(u32 a0) asm("_Z13func_0019f5a8j");
u32 func_0019f5a8(u32 a0) {
    u32 end = a0 + 96;
    u32 ret = a0;
    do {
        if (*(u32 *)a0 == 0) {
            return ret;
        }
        a0 += 12;
        if ((s32)a0 >= (s32)end) {
            return 0;
        }
        ret = a0;
    } while (1);
}
}  // namespace n0019f5a8

// ---- 0019f5d8 from src/anon/batch_w15.cpp
namespace n0019f5d8 {
struct Pair12 { u32 a; u32 b; u32 c; };
Pair12* func_0019f5d8(Pair12* e, u32 a, u32 b) asm("func_0019f5d8");
Pair12* func_0019f5d8(Pair12* e, u32 a, u32 b) {
    for (int i = 0; i < 8; i++) {
        if (e[i].a == a && e[i].b == b) return &e[i];
    }
    return 0;
}
}  // namespace n0019f5d8

// ---- 0019f610 from src/anon/auto80_199_queue.cpp
namespace n0019f610 {
void func_0019f610(u32 a0, u32 a1, u32 a2) asm("_Z13func_0019f610jjj");
void func_0019f610(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 v0;

    v0 = func_0019f5d8(s0);
    if (v0 == 0) {
        v0 = func_0019f5a8(s0);
    }
    *(u32 *)(v0 + 0) = s1;
    *(u32 *)(v0 + 4) = s2;
    *(u8 *)(v0 + 8) = 1;
}
}  // namespace n0019f610

// ---- 0019f670 from src/anon/auto80_199_queue.cpp
namespace n0019f670 {
void func_0019f670(u32 a0, u32 a1, u32 a2) asm("_Z13func_0019f670jjj");
void func_0019f670(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 v0;

    v0 = func_0019f5d8(s0);
    if (v0 == 0) {
        v0 = func_0019f5a8(s0);
    }
    *(u32 *)(v0 + 0) = s1;
    *(u32 *)(v0 + 4) = s2;
    *(u8 *)(v0 + 8) = 0;
}
}  // namespace n0019f670

// ---- 0019f6c8 from src/anon/tiny_auto80_queue.cpp
namespace n0019f6c8 {
u32 func_0019f5d8(...) asm("func_0019f5d8");
void func_0019f6c8(void) asm("_Z13func_0019f6c8v");
void func_0019f6c8(void) {
    u32 v0 = func_0019f5d8();
    if (v0 != 0u) {
        *(u32*)((u32)v0 + (s32)0) = 0u;
    }
}
}  // namespace n0019f6c8

// ---- 0019f6f0 from src/anon/tiny_auto80_queue.cpp
namespace n0019f6f0 {
u32 func_0019f6f0(u32 a0, u32 a1, u32 a2) asm("_Z13func_0019f6f0jjj");
u32 func_0019f6f0(u32 a0, u32 a1, u32 a2) {
    u32 t5 = 0xffffffffu;
    u32 t6 = (u32)((s32)a0 + (96));
    do {
        u32 t7 = *(u32*)((u32)a0 + (s32)(0));
        if (t7 == a1) {
            t7 = *(u32*)((u32)a0 + (s32)(4));
            if (t7 == t5 || t7 == a2) {
                t7 = (u32)(*(u8*)((u32)a0 + (s32)(8)));
                if (t7 != 0u) {
                    return 1u;
                }
            }
        }
        a0 = (u32)((s32)a0 + (12));
    } while ((u32)(((s32)a0 < (s32)t6) ? 1 : 0) != 0u);
    return 0u;
}
}  // namespace n0019f6f0

// ---- 0019f740 from src/anon/batch_w30.cpp
namespace n0019f740 {
struct E19f740 {
    u32 a;
    s32 b;
    u8 c;
};
s32 func_0019f740(E19f740* e, u32 a, s32 b) asm("func_0019f740");
s32 func_0019f740(E19f740* e, u32 a, s32 b) {
    s32 m = -1;
    E19f740* end = e + 8;
    for (; (s32)e < (s32)end; e++) {
        if (e->a == a && (e->b == m || e->b == b) && !e->c) return 1;
    }
    return 0;
}
}  // namespace n0019f740

// ---- 0019f790 from src/anon/tiny_auto80_queue.cpp
namespace n0019f790 {
extern u32 D_0033caf4 asm("D_0033caf4");
extern u32 D_00350470 asm("D_00350470");
extern u32 D_01c62fb0 asm("D_01c62fb0");
u32 func_001b1490(...) asm("func_001b1490");
u32 func_002fee78(...) asm("func_002fee78");
void func_0019f790() asm("_Z13func_0019f790v");
void func_0019f790() {
    u8 sp[48];
    func_002fee78(sp, D_00350470, D_0033caf4);
    D_01c62fb0 = func_001b1490(sp);
}
}  // namespace n0019f790

// ---- 0019f7d0 from src/anon/batch_w1785.cpp
namespace n0019f7d0 {
struct Pair32 { u8 a; u8 b; };
extern Pair32 D_0032bae0 asm("D_0032bae0");
extern void* D_01c62fb0 asm("D_01c62fb0");
s8* func_00105ee8(s32) asm("func_00105ee8");
struct Res168 { u32 x0; u32 x4; u32* x8; };
Res168* func_00168b88(void*, s32, s32, s32) asm("func_00168b88");
u32* func_0019f7d0(s32 idx, s32 id) asm("func_0019f7d0");
u32* func_0019f7d0(s32 idx, s32 id)
{
    s32 a = D_0032bae0.a;
    if (idx < 0) idx = D_0032bae0.b;
    void* h = D_01c62fb0;
    if (id < 0) id = a;
    s8* p = func_00105ee8(id);
    Res168* r = func_00168b88(h, 2, p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24), 0);
    if (r) {
        u32* t = r->x8;
        if (t) return t + idx;
    }
    return 0;
}
}  // namespace n0019f7d0

// ---- 0019f880 from src/anon/tiny_auto80_queue.cpp
namespace n0019f880 {
u32 func_0019f7d0(...) asm("func_0019f7d0");
u32 func_00192048(...) asm("func_00192048");
u32 func_0019f880() asm("_Z13func_0019f880v");
u32 func_0019f880() {
    u32 t7 = func_0019f7d0();
    if (t7 == 0) {
        return 0;
    }
    u32 a0 = *(u16*)t7;
    if (a0 == 0) {
        return 0;
    }
    return func_00192048(a0);
}
}  // namespace n0019f880

// ---- 0019f8c0 from src/anon/batch_w13.cpp
namespace n0019f8c0 {
u8* func_0019f7d0(void) asm("func_0019f7d0");
u8* func_0019f8c0(void) asm("func_0019f8c0");
u8* func_0019f8c0(void) {
    u8* v = func_0019f7d0();
    if (v) {
        u16 t = *(u16*)(v + 2);
        if (t) return v + t;
    }
    return 0;
}
}  // namespace n0019f8c0

// ---- 0019f8f8 from src/anon/batch_w1753.cpp
namespace n0019f8f8 {
struct W1753Pair { u32 a; u32 b; };
struct W1753Sub { u32 w[16]; };
struct W1753S1 { u32 x0; u32 x4; W1753Pair arr[8]; W1753Sub sub; };
void func_001c0150(W1753Sub*, u32) asm("func_001c0150");
void func_0019f8f8(W1753S1* p, u32 v) asm("func_0019f8f8");
void func_0019f8f8(W1753S1* p, u32 v) {
    p->x0 = v;
    p->x4 = 0;
    func_001c0150(&p->sub, v);
    for (int i = 0; i < 8; i++) p->arr[i].b = 0;
}
}  // namespace n0019f8f8

// ---- 0019f950 from src/anon/batch_w1753.cpp
namespace n0019f950 {
struct W1753Pair { u32 a; u32 b; };
struct W1753Sub { u32 w[16]; };
struct W1753S1 { u32 x0; u32 x4; W1753Pair arr[8]; W1753Sub sub; };
void func_001c0150(W1753Sub*, u32) asm("func_001c0150");
void func_0019f950(W1753S1* p, u32 v) asm("func_0019f950");
void func_0019f950(W1753S1* p, u32 v) {
    p->x0 = v;
    p->x4 = 0;
    func_001c0150(&p->sub, v);
    for (int i = 0; i < 8; i++) p->arr[i].b = 0;
}
}  // namespace n0019f950

// ---- 0019f9a8 from src/anon/batch_w48.cpp
namespace n0019f9a8 {
void func_0018f028(void*) asm("func_0018f028");
void func_0019f9a8(u8* o) asm("func_0019f9a8");
void func_0019f9a8(u8* o) {
    u8* p = o;
    for (s32 i = 7; i >= 0; i--) {
        if (*(void**)(p + 12)) {
            func_0018f028(*(void**)(p + 12));
            *(u32*)(p + 12) = 0;
        }
        p += 8;
    }
    *(u32*)o = 0;
}
}  // namespace n0019f9a8

// ---- 0019fa08 from src/anon/tiny_auto80_queue.cpp
namespace n0019fa08 {
u32 func_0019fa08(u8* a0, u32 a1, u32 a2) asm("_Z13func_0019fa08Phjj");
u32 func_0019fa08(u8* a0, u32 a1, u32 a2) {
    u32 c = 0;
    s32 d = 0;
    u32 e;
loop:
    e = *(u32*)(a0 + 12);
    if (e == 0) {
        c = (u32)(a0 + 8);
        d = d + 1;
        goto check;
    }
    if (*(u32*)(e + 196) != a1) {
        d = d + 1;
        goto check;
    }
    if (*(u32*)(e + 16) == a2) {
        return (u32)(a0 + 8);
    }
    d = d + 1;
check:
    if (d < 8) {
        a0 = a0 + 8;
        goto loop;
    }
    return c;
}
}  // namespace n0019fa08

// ---- 0019fa58 from src/anon/batch_w2380_nsa.cpp
namespace n0019fa58 {
struct W2380Ctx { u8 pad[0xaa4]; s32 faa4; };
struct W2380Obj { u8 pad[0x14]; u32 f14; u8 pad18[8]; s32 f20; };
struct W2380Ent { u32 f0; W2380Obj* p4; };
struct W2380Mgr { W2380Ctx* p0; s32 f4; };
W2380Ent* func_0019fa08(W2380Mgr*, u32, u32) asm("func_0019fa08");
void func_0018f028(W2380Obj*) asm("func_0018f028");
W2380Obj* func_001050d8(u32) asm("func_001050d8");
void func_001a3f08(W2380Obj*, W2380Ctx*, u32, u32, W2380Obj**, s32, u32) asm("func_001a3f08");
void wtarget_0019fa58(W2380Mgr* m, u32 key, u32 a2, u32 a3, u32 tag) asm("_Z16wtarget_0019fa58jjjj");
void wtarget_0019fa58(W2380Mgr* m, u32 key, u32 a2, u32 a3, u32 tag) {
    s32 id = tag ? m->f4 : -1;
    W2380Ent* e = func_0019fa08(m, a2, a3);
    if (e->p4) {
        if (e->p4->f14 == key && e->f0 == tag) return;
        func_0018f028(e->p4);
    }
    m->p0->faa4 = 0;
    e->f0 = tag;
    W2380Obj* n = func_001050d8(0x2e0);
    func_001a3f08(n, m->p0, a3, key, &e->p4, id, a2);
    e->p4 = n;
    m->f4 = n->f20;
}
}  // namespace n0019fa58

// ---- 0019fb48 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n0019fb48 {
extern "C" u32 YS_ATTACK_CHECK_NewComboGroup(u32, u32, u32, u32) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");
u32 func_0019fb48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0019fb48jjjj");
u32 func_0019fb48(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = YS_ATTACK_CHECK_NewComboGroup(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(4)) = r2;
    return r2;
}
}  // namespace n0019fb48

