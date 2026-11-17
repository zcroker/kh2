// Linked unit (extracted from the matched per-function sources).
#include "../common/types.h"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"

// ---- 0x0015b100 (src/anon/batch_wcx.cpp)
namespace n0015b100 {
extern void* D_0034aaa8 asm("D_0034aaa8");
extern void* D_0034aaa4 asm("D_0034aaa4");
extern void* D_0034aa9c asm("D_0034aa9c");
extern void* D_0034aaa0 asm("D_0034aaa0");
typedef void (*VFn)(void*);
#define VDEL(o) if (o) { (*(VFn*)(*(u8**)o + 16))(o); o = 0; }
void func_0015b100(void*) asm("_Z13func_0015b100Pv");
void func_0015b100(void*) asm("func_0015b100");
void func_0015b100(void*)
{
    VDEL(D_0034aaa8);
    VDEL(D_0034aaa4);
    VDEL(D_0034aa9c);
    VDEL(D_0034aaa0);
}
}  // namespace n0015b100

// ---- 0x0015b1b0 (src/anon/batch_w2372.cpp)
namespace n0015b1b0 {
extern char D_004f3608[] asm("D_004f3608");
extern void* D_0034aaa0 asm("D_0034aaa0");
s32 func_0019eeb8(void*, void*) asm("func_0019eeb8");
char* func_0019f880(void*, void*) asm("func_0019f880");
char* func_00192048(s32) asm("func_00192048");
s32 func_00192c40(char*, char*) asm("func_00192c40");
void func_0015aa98(void*, char*, s32, f32) asm("func_0015aa98");
void func_0015b1b0(void* a, void* b, u8 c) asm("func_0015b1b0");
void func_0015b1b0(void* a, void* b, u8 c) {
    s32 n;
    if (func_0019eeb8(b, a)) {
        n = func_00192c40(func_0019f880(a, b), D_004f3608);
    } else {
        n = func_00192c40(func_00192048(0x82b8), D_004f3608);
    }
    if (c) {
        n += func_00192c40(func_00192048(0x8add), D_004f3608 + n);
    }
    D_004f3608[n] = 0;
    func_0015aa98(D_0034aaa0, D_004f3608, 16, 0.0f);
}
}  // namespace n0015b1b0

// ---- 0x0015b268 (src/anon/batch_w40.cpp)
namespace n0015b268 {
struct S15b { u8 pad[436]; f32 f; };
union U15b { S15b* p; f32 f; };
extern s32 D_0034aa98 asm("D_0034aa98");
extern U15b D_0034aa9c asm("D_0034aa9c");
void func_0015ad80(S15b*, u32) asm("func_0015ad80");
void func_0015aea8(S15b*, u32) asm("func_0015aea8");
void func_0015b268(u32 a, f32 f) asm("func_0015b268");
void func_0015b268(u32 a, f32 f) {
    if (D_0034aa98 == 0) {
        func_0015ad80(D_0034aa9c.p, a);
        D_0034aa98++;
    } else {
        D_0034aa9c.p->f = f;
        func_0015aea8(D_0034aa9c.p, a);
    }
}
}  // namespace n0015b268

// ---- 0x0015b2d0 (src/anon/batch_w57.cpp)
namespace n0015b2d0 {
extern u32  D_0034aaac asm("D_0034aaac");
extern u32 D_0034aaa8 asm("D_0034aaa8");
extern u32 D_0034aaa4 asm("D_0034aaa4");
u32 func_001492f8(u32) asm("func_001492f8");
u32 func_00149300(u32) asm("func_00149300");
u32 func_0019f880(s32, s32) asm("func_0019f880");
void func_0015aa98(u32, u32, u32, f32) asm("func_0015aa98");
void func_0015aba8(u32, u32, u32) asm("func_0015aba8");
void func_0015b2d0(void) asm("func_0015b2d0");
void func_0015b2d0(void) {
    u32 a = func_001492f8(D_0034aaac);
    u32 b = func_00149300(D_0034aaac);
    if (!a || !b) {
        func_0015aa98(D_0034aaa8, func_0019f880(-1, -1), 20, 120.0f);
    } else {
        func_0015aba8(D_0034aaa4, a, b);
    }
}
}  // namespace n0015b2d0

// ---- 0x0015b368 (src/anon/batch_w96.cpp)
namespace n0015b368 {
u32 func_0013a7e8(u32) asm("func_0013a7e8");
void func_001386e0(u32, u32, u32, u32, u32, u32) asm("func_001386e0");
void func_00239988(u32, u32, u32) asm("func_00239988");
void func_00239bf8(u32, u32) asm("func_00239bf8");
s32 func_0015b4f8(void*, u32, s32*) asm("func_0015b4f8");
s32 func_0023aa98(u32) asm("func_0023aa98");
extern u8 D_0034ab50[] asm("D_0034ab50");
void func_0015b368(u32 self, u32 a1, u32 a2, u32 a3) asm("func_0015b368");
void func_0015b368(u32 self, u32 a1, u32 a2, u32 a3) {
    s32 ids[8];
    s32 sum = 0;
    s32 i = 0;
    s32 half, v;
    u32 s5 = func_0013a7e8(0);
    func_001386e0(self, 3800, s5, a2, a1, 15);
    *(s32*)(self + 436) = func_0015b4f8(D_0034ab50, a3, ids);
    for (; i < *(s32*)(self + 436); i++) {
        u32 p = self + 440 + i * 344;
        func_00239988(p, s5, a2);
        func_00239bf8(p, ids[i]);
        sum += func_0023aa98(p);
    }
    v = func_0023aa98(self + 24);
    i = 0;
    sum += v;
    half = sum / 2;
    sum = 0;
    *(s32*)(self + 376) = half - v;
    for (; i < *(s32*)(self + 436); i++) {
        ((s32*)(self + 2848))[i] = sum - half;
        sum += func_0023aa98(self + 440 + i * 344);
    }
}
}  // namespace n0015b368

// ---- 0x0015b4c0 (src/anon/batch_w16.cpp)
namespace n0015b4c0 {
typedef void (*VFn1)(void*, void*);
void* func_001050c8(void*) asm("func_001050c8");
void func_0015b4c0(void* p) asm("func_0015b4c0");
void func_0015b4c0(void* p) {
    void* o = func_001050c8(p);
    (*(VFn1*)(*(u8**)o + 4))(o, p);
}
}  // namespace n0015b4c0

// ---- 0x0015b4f8 (src/anon/batch_w63.cpp)
namespace n0015b4f8 {
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
extern char D_0036b3c0[] asm("D_0036b3c0");
s32 func_0015b4f8(s32* tbl, s32 v, s32* out) asm("func_0015b4f8");
s32 func_0015b4f8(s32* tbl, s32 v, s32* out) {
    char buf[16];
    func_002fee78(buf, D_0036b3c0, v);
    s32 n = 0;
    for (s32 i = 0; i < 16; i++) {
        if (!buf[i]) break;
        u32 d = buf[i] - '0';
        *out++ = tbl[d];
        n++;
    }
    return n;
}
}  // namespace n0015b4f8

// ---- 0x0015b578 (src/anon/auto80_199_queue.cpp)
namespace n0015b578 {
void func_001390f0(u32 a0) asm("func_001390f0");
void func_0015b578(u32 a0) asm("func_0015b578");
void func_0015b578(u32 a0) {
    u32 s1 = 0;
    u32 s2 = a0;
    u32 s0;
    s32 n;

    n = *(s32*)(a0 + 436);
    if (n > 0) {
        s0 = a0 + 440;
        do {
            func_0023acd8(s0);
            s1 += 1;
            n = *(s32*)(s2 + 436);
            if ((s32)s1 < n) {
                s0 += 344;
                continue;
            }
            break;
        } while (1);
    }
    func_001390f0(s2);
}
}  // namespace n0015b578

// ---- 0x0015b5d8 (src/anon/auto80_199_queue.cpp)
namespace n0015b5d8 {
void func_0015b5d8(u32 a0) asm("_ZN2dk3Exp4drawEv");
void func_0015b5d8(u32 a0) {
    u32 s1 = a0;
    s32 n;
    u32 s3;
    u32 s2;
    u32 s0;
    u32 v;
    u32 t0;
    u32 t1;

    n = *(s32*)(a0 + 432);
    if (n <= 0) {
        return;
    }
    if (n > 0x003d0900) {
        return;
    }

    func_00139170();
    s3 = 0;
    if (*(s32*)(s1 + 436) <= 0) {
        return;
    }
    s2 = s1 + 2848;
    s0 = s1 + 440;

    do {
        v = *(u32*)(s2 + 0);
        t0 = *(u32*)(s1 + 368);
        t1 = *(u32*)(s1 + 372);
        s3 += 1;
        s2 += 4;
        *(u32*)(s0 + 328) = t0 + v;
        *(u32*)(s0 + 332) = t1;
        func_0023ade0(s0);
        if ((s32)s3 < *(s32*)(s1 + 436)) {
            s0 += 344;
            continue;
        }
        break;
    } while (1);
}
}  // namespace n0015b5d8

// ---- 0x0015b680 (src/anon/batch_w88.cpp)
namespace n0015b680 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void QCOPY(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
u32 func_001050c8(void) asm("func_001050c8");
u8* func_001063c0(u32, u32) asm("func_001063c0");
void func_00239700(u8*) asm("func_00239700");
u32 func_0013e678(void) asm("func_0013e678");
void func_0015b368(u8*, u32, u32, u32) asm("func_0015b368");
void func_001391a8(u8*, V4*) asm("func_001391a8");
void func_0014f648(u32) asm("func_0014f648");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0034ab80[] asm("D_0034ab80");
void func_0015b680(V4* pos, u32 a, u32 b) asm("func_0015b680");
void func_0015b680(V4* pos, u32 a, u32 b) {
    u8* o = func_001063c0(2880, func_001050c8());
    *(u32*)(o + 12) = 0;
    *(u32*)o = (u32)D_00347e60;
    func_00239700(o + 24);
    *(u32*)(o + 432) = 0;
    *(u32*)o = (u32)D_0034ab80;
    u8* q = o + 440;
    for (s32 i = 6; i != -1; i--, q += 344) func_00239700(q);
    func_0015b368(o, 16, func_0013e678(), a);
    V4 t;
    QCOPY(&t, pos);
    func_001391a8(o, &t);  // vec_copy_at416_if_diff
    func_0014f648(b);
}
}  // namespace n0015b680

// ---- 0x0015b770 (src/anon/tiny.cpp)
namespace n0015b770 {
void func_0015b770(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2dk3Exp4initEv");
void func_0015b770(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n0015b770

// ---- 0x0015b778 (gap, written here)
namespace n0015b778 {
extern "C" void func_0015b778(void) {}
}

// ---- 0x0015b780 (src/anon/batch_w4.cpp)
namespace n0015b780 {
void func_00139858(s32) asm("func_00139858");
void func_00139ab0(s32) asm("func_00139ab0");
void func_0015b780(void) asm("func_0015b780");
void func_0015b780(void) {
    func_00139858(15);
    func_00139ab0(15);
}
}  // namespace n0015b780

// ---- 0x0015b7a0 (src/anon/batch_w5.cpp)
namespace n0015b7a0 {
void func_001398d0(u32) asm("func_001398d0");
void func_00139a38(u32) asm("func_00139a38");
void func_0015b7a0(void) asm("func_0015b7a0");
void func_0015b7a0(void) {
    func_001398d0(15);
    func_00139a38(15);
}
}  // namespace n0015b7a0

// ---- 0x0015b7c0 (src/anon/batch_w11.cpp)
namespace n0015b7c0 {
struct RadarS { u8 pad[2928]; void* data; s32 n; };
void func_0015b7f8(void*) asm("func_0015b7f8");
void func_0015bab8(void*) asm("func_0015bab8");
void Radar_create(RadarS*, void*) asm("_ZN2dk5Radar6createEPv");
void Radar_create(RadarS* self, void* data) asm("_ZN2dk5Radar6createEPv");
void Radar_create(RadarS* self, void* data) {
    self->data = data;
    self->n = 16;
    func_0015b7f8(self);
    func_0015bab8(self);
}
}  // namespace n0015b7c0
