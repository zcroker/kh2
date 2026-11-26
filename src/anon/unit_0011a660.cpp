#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
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
#include "../kn/fmatrix.hpp"

// ---- 0011a660 gap: C2 copy of the ctor after it
namespace n0011a660 {
extern u8 D_003478b0 asm("D_003478b0");
extern u8 D_00347880 asm("D_00347880");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
u32 func_0011a660(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0011a660");
u32 func_0011a660(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 r = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    *(u32*)(s0 + 48) = 0;
    *(volatile u32*)s0 = (u32)&D_003478b0;
    *(u32*)(s0 + 32) = 0;
    *(u32*)(s0 + 12) = 1;
    *(volatile u32*)(s0 + 16) = (u32)&D_00347880;
    return r;
}
}  // namespace n0011a660

// ---- 0011a6b0 from src/anon/tiny_auto80_solver.cpp
namespace n0011a6b0 {
extern u8 D_003478b0 asm("D_003478b0");
extern u8 D_00347880 asm("D_00347880");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
u32 kn__ChickenLittle__ChickenLittle(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z32kn__ChickenLittle__ChickenLittlejjjjjjjj");
u32 kn__ChickenLittle__ChickenLittle(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 r = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    *(u32*)(s0 + 48) = 0;
    *(volatile u32*)s0 = (u32)&D_003478b0;
    *(u32*)(s0 + 32) = 0;
    *(u32*)(s0 + 12) = 1;
    *(volatile u32*)(s0 + 16) = (u32)&D_00347880;
    return r;
}
}  // namespace n0011a6b0

// ---- 0011a700 from src/anon/tiny_auto80_queue.cpp
namespace n0011a700 {
u32 func_00113668(...) asm("func_00113668");
u32 dk__LockOn__end(...) asm("dk__LockOn__end");
extern u8 D_003478b0 asm("D_003478b0");
u32 func_0011a700(u32 a0) asm("_Z13func_0011a700j");
u32 func_0011a700(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_003478b0;
    ((u32*)(u32)r4)[0] = r15;
    r16 = r4;
    r14 = ((u32*)(u32)r4)[12];
    r4 = r14;
    if (r14 != 0u) {
    u32 (*fp_call4_0013e4b8)(u32) = (u32(*)(u32))dk__LockOn__end;
        r2 = fp_call4_0013e4b8(r4);
        ((u32*)(u32)r16)[12] = 0u;
    }
    r4 = r16;
    u32 (*fp_call4_00113668)(u32) = (u32(*)(u32))func_00113668;
    r2 = fp_call4_00113668(r4);
    return r2;
}
}  // namespace n0011a700

// ---- 0011a750 from src/anon/tiny_auto80_queue.cpp
namespace n0011a750 {
u32 func_00113668(...) asm("func_00113668");
u32 dk__LockOn__end(...) asm("dk__LockOn__end");
extern u8 D_003478b0 asm("D_003478b0");
u32 func_0011a750(u32 a0) asm("_Z13func_0011a750j");
u32 func_0011a750(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_003478b0;
    ((u32*)(u32)r4)[0] = r15;
    r16 = r4;
    r14 = ((u32*)(u32)r4)[12];
    r4 = r14;
    if (r14 != 0u) {
    u32 (*fp_call4_0013e4b8)(u32) = (u32(*)(u32))dk__LockOn__end;
        r2 = fp_call4_0013e4b8(r4);
        ((u32*)(u32)r16)[12] = 0u;
    }
    r4 = r16;
    u32 (*fp_call4_00113668)(u32) = (u32(*)(u32))func_00113668;
    r2 = fp_call4_00113668(r4);
    return r2;
}
}  // namespace n0011a750

// ---- 0011a7a0 from src/anon/tiny_auto80_queue.cpp
namespace n0011a7a0 {
u32 func_00105110(...) asm("func_00105110");
u32 func_00113668(...) asm("func_00113668");
u32 dk__LockOn__end(...) asm("dk__LockOn__end");
extern u8 D_003478b0 asm("D_003478b0");
u32 func_0011a7a0(u32 a0) asm("_Z13func_0011a7a0j");
u32 func_0011a7a0(u32 a0) {
    u32 tmp;
    u32 vt = (u32)&D_003478b0;
    ((u32*)(u32)a0)[0] = vt;
    u32 s0 = a0;
    u32 t6 = *(volatile u32*)((u32)a0 + (s32)(48));
    if (t6 != 0u) {
        dk__LockOn__end(t6);
        *(volatile u32*)((u32)s0 + (s32)(48)) = 0u;
    }
    func_00113668(s0);
    return func_00105110(s0);
}
}  // namespace n0011a7a0

// ---- 0011a7f0 from src/anon/auto80_199_queue.cpp
namespace n0011a7f0 {
u32 func_0011a7f0(u8* a0, u8* a1, u32* a2, u32* a3, u32 a4) asm("_Z13func_0011a7f0PhS_PjS0_j");
u32 func_0011a7f0(u8* a0, u8* a1, u32* a2, u32* a3, u32 a4) {
    if ((a4 & 0xff) != 0) {
        *a3 = 0;
        u8* t5 = *(u8**)(a0 + 4);
        a2[0] = *(u32*)(t5 + 0x9f4);
        a2[1] = *(u32*)(t5 + 0x9f8);
        a2[2] = *(u32*)(t5 + 0x9fc);
        a2[3] = *(u32*)(t5 + 0xa00);
        a2[4] = *(u32*)(t5 + 0xa04);
        return 1;
    }

    u32 p = *(u32*)(a0 + 4);
    func_00188170(p + 0x300, *(u32*)(a1 + 0x20));
    return 1;
}
}  // namespace n0011a7f0

// ---- 0011a858 from src/anon/batch_w1782.cpp
namespace n0011a858 {
struct V11a858 {
    f32 x, y, z, w;
} __attribute__((aligned(16)));
static inline V11a858 operator*(const V11a858& a, f32 k) {
    V11a858 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline V11a858 operator+(const V11a858& a, const V11a858& b) {
    V11a858 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
#define QCOPY134668(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Q134668 {
    f32 x, y, z, w;
    Q134668() {}
    Q134668(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    Q134668& operator=(const Q134668& o) {
        if (this != &o) QCOPY134668(this, &o);
        return *this;
    }
                                      
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
u8* func_00106a60(s32) asm("func_00106a60");
V11a858 func_00107388(u8*) asm("func_00107388");
V11a858 func_0011a858(void) asm("func_0011a858");
V11a858 func_0011a858(void) {
    u8* c = func_00106a60(1);
    V11a858 p = func_00107388(c);
    f32 x = *(f32*)(c + 0x18);
    f32 y = *(f32*)(c + 0x28);
    f32 z = *(f32*)(c + 0x38);
    V11a858 d;
    d.x = x; d.y = y; d.z = z; d.w = 0.0f;
    V11a858 r = p + d * 300.0f;
    r.w = 1.0f;
    return r;
}
}  // namespace n0011a858

// ---- 0011a900 from src/anon/batch_w5.cpp
namespace n0011a900 {
void* func_0011a900(void* dst, u8* src) asm("func_0011a900");
void* func_0011a900(void* dst, u8* src) {
    src += 0x40;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    return dst;
}
}  // namespace n0011a900

// ---- 0011a918 from src/anon/batch_w1.cpp
namespace n0011a918 {
void func_0011a918(u8* d, u8* s) asm("func_0011a918");
void func_0011a918(u8* d, u8* s) {
    d += 64;
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}
}  // namespace n0011a918

// ---- 0011a938 from src/anon/match_0011a938.cpp
namespace n0011a938 {
void func_00190128(void*) asm("func_00190128");
struct W1680QW {
    f32 x, y, z, w;
    W1680QW() {}
    W1680QW& operator=(const W1680QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1680Mtx {
    W1680QW r[4];
    W1680Mtx(const W1680Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
};
struct W1680Tgt {
    s32 a, b, c, d, e;
    W1680Tgt() { func_00190128(this); }
    void clear() { func_00190128(this); }
};
struct W1680Hit { s32 p0; f32 r; s32 p8; s32 z; W1680QW v; W1680Hit() { z = 0; } };
struct W1680Cam { u8 p0[16]; W1680Mtx m; };
struct W1680Self2 { u8 p0[64]; W1680QW pos; };
static inline void W1680_apply(W1680QW* out, const W1680Mtx* m, const W1680QW* v) {
    asm volatile("lqc2 $vf5,0(%1)\n\tlqc2 $vf1,0(%2)\n\tlqc2 $vf2,16(%2)\n\tlqc2 $vf3,32(%2)\n\tlqc2 $vf4,48(%2)\n\t"
                 "vmulax.xyz ACC,$vf1,$vf5x\n\tvmadday.xyz ACC,$vf2,$vf5y\n\tvmaddaz.xyz ACC,$vf3,$vf5z\n\t"
                 "vmaddw.xyz $vf5,$vf4,$vf0w\n\tvmove.w $vf5,$vf0\n\tsqc2 $vf5,0(%0)"
                 : : "r"(out), "r"(v), "r"(m) : "memory");
}
static inline void W1680_scale(W1680QW* r, const W1680QW* a, f32 k) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(a), "f"(k) : "$8", "memory");
}
static inline void W1680_sub(W1680QW* r, const W1680QW* a, const W1680QW* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline void W1680_zw(W1680QW* v, f32 z) { v->w = z; v->z = z; }
static inline W1680QW operator*(const W1680Mtx& m, const W1680QW& v) { W1680QW r; W1680_apply(&r, &m, &v); return r; }
static inline W1680QW operator*(const W1680QW& v, f32 k) { W1680QW r; W1680_scale(&r, &v, k); return r; }
static inline W1680QW operator-(const W1680QW& a, const W1680QW& b) { W1680QW r; W1680_sub(&r, &a, &b); return r; }
static inline void W1680_mul(W1680QW& r, const W1680Mtx& m, const W1680QW& v) { W1680_apply(&r, &m, &v); }
s32 W1680_is_exist(W1680Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
s32 W1680_can_attack(W1680Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
s32 W1680_is_culling(s32) asm("_ZN2YS3OBJ10is_cullingEv");
f32 W1680_getScreenZ(void*) asm("_ZNK2kn10Projection10getScreenZEv");
s32 YS__TARGET__each(W1680Tgt*, s32) asm("YS__TARGET__each");
s32 func_00112d90(W1680Tgt*) asm("func_00112d90");
void* kn__getProjection(s32) asm("kn__getProjection");
W1680Cam* func_00106a60(s32) asm("func_00106a60");
W1680QW func_00190388(W1680Tgt*) asm("func_00190388");
f32 fabsf(f32) asm("fabsf");
void func_0011a938(W1680Self2* self, W1680Tgt* out, f32 fx, f32 fy) asm("func_0011a938");
void func_0011a938(W1680Self2* self, W1680Tgt* out, f32 fx, f32 fy) {
    out->clear();
    f32 sz = W1680_getScreenZ(kn__getProjection(0));
    W1680Cam* c = func_00106a60(0);
    W1680Mtx m(c ? c->m : *(W1680Mtx*)0);
                                                                                      
    register u32 s0_busy asm("$16");
    asm volatile("" : "=r"(s0_busy));
    W1680Tgt it;
    W1680Hit hit;
    W1680QW p = m * self->pos;
    W1680QW center;
    center = p * (sz / p.z);
    it.clear();
    f32 best = fx * fx + fy * fy;
    s32 k = 0;
    W1680Mtx* pm = &m;
    while ((k = YS__TARGET__each(&it, k)) != 0) {
        if (!func_00112d90(&it)) continue;
        if (!W1680_can_attack(&it)) continue;
        if (W1680_is_culling(it.a)) continue;
        W1680QW p2;
        W1680QW s;
        W1680_mul(p2, *pm, func_00190388(&it));
        s = p2 * (sz / p2.z);
        W1680QW d = s - center;
        if (!(fabsf(d.x) <= fx)) continue;
        if (!(fabsf(d.y) <= fy)) continue;
        W1680_zw(&d, 0.0f);
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        if (!W1680_is_exist(out) || len < best) { best = len; *out = it; }
    }
}
}  // namespace n0011a938

// ---- 0011ac10 from src/anon/batch_w1650_nsa.cpp
namespace n0011ac10 {
void func_00190128(void*) asm("func_00190128");
struct W1650QW {
    f32 x, y, z, w;
    W1650QW() {}
    W1650QW(const W1650QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1650QW& operator=(const W1650QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1650Tgt {
    s32 a, b, c, d, e;
    W1650Tgt() { func_00190128(this); }
    void clear() { func_00190128(this); }
};
struct W1650Lock;
struct W1650LockVt { void* f[7]; void (*setPos)(W1650Lock*, W1650QW); };
struct W1650Lock { W1650LockVt* vt; };
struct W1650Friend { u8 p0[0x9f4]; W1650Tgt target; };
struct W1650Party { u8 p0[0xb40]; void* lockon; };
struct W1650Input { u64 trig; u64 press; };
struct W1650Fps { u8 p0[4]; W1650Friend* fr; u8 p8[0x2c - 8]; s32 kind; W1650Lock* lock; u8 p34[0x40 - 0x34]; W1650QW pos; };
s32 W1650_is_exist(W1650Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
s32 W1650_can_attack(W1650Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
void W1650_set_obj(W1650Tgt*, s32, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 W1650_is_culling(s32) asm("_ZN2YS3OBJ10is_cullingEv");
void* W1650_getObjObserver(W1650Friend*) asm("_ZN2kn6Friend14getObjObserverEv");
W1650Party* W1650_getPartyChara(s32) asm("_ZN2kn6Friend13getPartyCharaEi");
W1650Input* W1650_GetInputState(...) asm("_ZN2Tz10MenuCursor13GetInputStateEz");
s32 W1650_getEntryNum(void*) asm("_ZN2kn11ObjObserver11getEntryNumEv");
void W1650_lockon_start(void*, s32, W1650Tgt*) asm("_ZN2YS6LOCKON5startEiPNS_6TARGETE");
void W1650_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
s32 W1650_IsExec() asm("_ZN2YS5EVENT6IsExecEv");
void W1650_LockOn_show() asm("_ZN2dk6LockOn4showEv");
void W1650_FPSCamera_adjust() asm("_ZN2dk9FPSCamera6adjustEv");
s32 YS__TARGET__each(W1650Tgt*, s32) asm("YS__TARGET__each");
s32 func_00135c88(void*, s32) asm("func_00135c88");
s32 func_00135d00(void*, s32) asm("func_00135d00");
void func_00135bd0(void*, s32) asm("func_00135bd0");
void dk__LockOn__end(W1650Lock*) asm("dk__LockOn__end");
W1650Lock* func_0013e610(s32) asm("func_0013e610");
W1650QW func_00190388(W1650Tgt*) asm("func_00190388");
W1650QW func_0011a858(W1650Fps*) asm("func_0011a858");
static inline s32 W1650_next(void* obs, s32 prev) {
    s32 i = 0;
    if (prev != 0) {
        i = func_00135c88(obs, prev);
        i = i < 0 ? 0 : i + 1;
    }
    return i;
}
static inline bool W1650_valid(W1650Tgt* t) { return W1650_is_exist(t) && t->a != 0; }
void func_0011ac10(W1650Fps* self) asm("func_0011ac10");
void func_0011ac10(W1650Fps* self) {
    bool fps = false;
    void* obs = W1650_getObjObserver(self->fr);
    W1650Party* pc = W1650_getPartyChara(0);
    W1650Input* in = W1650_GetInputState(0);
    s32 kind = self->kind;
    if (in->press & 0x800) {
        W1650Tgt it;
        s32 prev;
        s32 o;
        {
        s32 k = 0;
        W1650Tgt* cur = &self->fr->target;
        prev = cur->a;
        cur->clear();
        while ((k = YS__TARGET__each(&it, k)) != 0) {
            if (!W1650_can_attack(&it)) continue;
            if (W1650_is_culling(it.a)) continue;
            if (func_00135c88(obs, it.a) >= 0) continue;
            o = it.a;
            self->fr->target = it;
            func_00135bd0(obs, o);
            break;
        }
        }
        if (!W1650_valid(&self->fr->target)) {
            s32 n = W1650_getEntryNum(obs);
            s32 start = W1650_next(obs, prev);
            for (s32 i = start; i < start + n; i++) {
                o = func_00135d00(obs, i);
                it.clear();
                W1650_set_obj(&it, o, 0);
                s32 j = 0;
                while ((j = YS__TARGET__each(&it, j)) != 0) {
                    if (it.a != o) break;
                    if (!W1650_can_attack(&it)) continue;
                    self->fr->target = it;
                    break;
                }
                if (W1650_valid(&self->fr->target)) break;
            }
        }
        if (W1650_valid(&self->fr->target)) {
            fps = true;
            if (pc->lockon) W1650_lockon_start(pc->lockon, 3, &self->fr->target);
            kind = 25;
        } else {
            self->fr->target.clear();
        }
        W1650_systemSePlay(7, 0);
    } else if (in->trig & 0x3c0000) {
        self->fr->target.clear();
        if (pc->lockon) W1650_lockon_start(pc->lockon, 3, 0);
        kind = 3;
    }
    if (W1650_can_attack(&self->fr->target)) {
        self->pos = func_00190388(&self->fr->target);
    } else {
        self->pos = func_0011a858(self);
        kind = 3;
    }
    if (!W1650_IsExec()) {
        if (self->lock == 0 || self->kind != kind) {
            if (self->lock) dk__LockOn__end(self->lock);
            self->kind = kind;
            self->lock = func_0013e610(kind);
            self->lock->vt->setPos(self->lock, self->pos);
            W1650_LockOn_show();
        }
    } else if (self->lock) {
        dk__LockOn__end(self->lock);
        self->lock = 0;
    }
    if (fps) W1650_FPSCamera_adjust();
    if (self->lock) self->lock->vt->setPos(self->lock, self->pos);
}
}  // namespace n0011ac10

// ---- 0011b038 from src/anon/batch_w48.cpp
namespace n0011b038 {
s32 func_00111e38(s32) asm("func_00111e38");
void func_0011ac10(s32) asm("func_0011ac10");
u8* func_00106a60(s32) asm("func_00106a60");
void func_0016aef0(s32, f32*) asm("func_0016aef0");
void func_0011b038(s32 a) asm("func_0011b038");
void func_0011b038(s32 a) {
    s32 h = func_00111e38(0);
    func_0011ac10(a);
    u8* p = func_00106a60(1);                        
    f32 v[4];
    f32 x = *(f32*)(p + 24);
    f32 z = *(f32*)(p + 56);
    v[0] = x;
    v[2] = z;
    v[3] = v[1] = 0.0f;
    func_0016aef0(h, v);
}
}  // namespace n0011b038

// ---- 0011b0a8 from src/anon/batch_w286.cpp
namespace n0011b0a8 {
#define QCOPY_bfa0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_bfa0 {
    f32 x, y, z, w;
    QV_bfa0() {}
    QV_bfa0(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_bfa0(const QV_bfa0& o) { QCOPY_bfa0(this, &o); }
    QV_bfa0& operator=(const QV_bfa0& o) { if (this != &o) QCOPY_bfa0(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline QV_bfa0 operator-(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 operator+(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 operator*(const QV_bfa0& a, f32 k) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
#define QCOPY_b0a8(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_b0a8 {
    f32 x, y, z, w;
    QV_b0a8() {}
    QV_b0a8(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_b0a8(const QV_b0a8& o) { QCOPY_b0a8(this, &o); }
} __attribute__((aligned(16)));
struct Fx_b0a8;
struct FxVt_b0a8 { void* s[7]; void (*f7)(Fx_b0a8*, QV_b0a8); };
struct Fx_b0a8 { FxVt_b0a8* vt; };
struct Ch_b0a8 { u8 p0[0x108]; u32 x108; u32 x10c; u8 p110[0x834 - 0x110]; u8 x834[0x9f4 - 0x834]; u8 x9f4[0xb40 - 0x9f4]; void* xb40; };
struct Ob_b0a8 { u8 p0[4]; union { Ch_b0a8* x4; u8 x4c; }; u8 p8[0x18]; u32 x20; f32 x24; f32 x28; s32 x2c; Fx_b0a8* x30; u8 p34[0xc]; QV_b0a8 x40; };
void func_001143d8(Ob_b0a8*) asm("func_001143d8");
Ch_b0a8* func_00111e38(s32) asm("func_00111e38");
void* func_0010c778(Ch_b0a8*) asm("func_0010c778");
void func_00135aa0(void*) asm("func_00135aa0");
void YS__OBJ__attach(Ch_b0a8*, Ch_b0a8*, s32, s32) asm("YS__OBJ__attach");
void func_0016ace0(Ch_b0a8*, const QV_b0a8&) asm("func_0016ace0");
void func_00198860(Ch_b0a8*, s32) asm("func_00198860");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");
void func_00190128(u8*) asm("func_00190128");
void func_0019ca90(void*, s32, s32) asm("func_0019ca90");
Fx_b0a8* func_0013e610(s32) asm("func_0013e610");
void func_0013e890(void) asm("func_0013e890");
void func_0016bd60(Ch_b0a8*, s32) asm("func_0016bd60");
void func_0014eb48(Ch_b0a8*, QV_b0a8*, f32) asm("func_0014eb48");
void kn__ChickenLittle__start_limit(Ob_b0a8* o) asm("kn__ChickenLittle__start_limit");
void kn__ChickenLittle__start_limit(Ob_b0a8* o) {
  func_001143d8(o);
  o->x28 = 0.0f;
  o->x24 = 100.0f;
  Ch_b0a8* c = func_00111e38(0);
  func_00135aa0(func_0010c778(o->x4));
  o->x20 |= 1;
  c->x108 |= 0x100;
  c->x10c |= 0x4000;
  o->x4->x108 |= 0x100;
  YS__OBJ__attach(o->x4, c, 0x4000, 4);
  func_0016ace0(o->x4, QV_b0a8(0.0f, 0.0f, -o->x28, 0.0f));
  func_00198860(o->x4, 5);
  func_001ad990(c->x834, 1.0f, 0.0f, 0.0f);
  func_001ad990(o->x4->x834, 1.0f, 0.0f, 0.0f);
  func_00190128(o->x4->x9f4);
  if (c->xb40) func_0019ca90(c->xb40, 3, 0);
  o->x2c = 3;
  o->x30 = func_0013e610(3);
  o->x30->vt->f7(o->x30, o->x40);
  func_0013e890();
  func_0016bd60(c, 62);
  func_0014eb48(c, &o->x40, o->x24);
}
}  // namespace n0011b0a8

// ---- 0011b250 from src/anon/batch_w281.cpp
namespace n0011b250 {
extern u32 D_0034f240 asm("D_0034f240");
void* func_0010c778(void*) asm("func_0010c778");
void func_00135aa0(void*) asm("func_00135aa0");
u8* func_00111e38(s32) asm("func_00111e38");
void func_001c0e60(void*) asm("func_001c0e60");
void YS__STDOBJ__reset_special_command(void*) asm("YS__STDOBJ__reset_special_command");
void dk__LockOn__end(void*) asm("dk__LockOn__end");
void func_0014ebd8(void) asm("func_0014ebd8");
void func_001ad990(void*, f32, f32, f32) asm("func_001ad990");
void func_00190128(void*) asm("func_00190128");
void YS__LOCKON__release(void*) asm("YS__LOCKON__release");
void func_0016bd60(void*, s32) asm("func_0016bd60");
void kn__ChickenLittle__end_limit(u8* p) asm("kn__ChickenLittle__end_limit");
void kn__ChickenLittle__end_limit(u8* p) {
    u8* c;
    func_00135aa0(func_0010c778((void*)*(u32*)(p + 4)));
    c = func_00111e38(0);
    *(u32*)(c + 264) &= ~0x100;
    *(u32*)(c + 268) &= ~0x4000;
    *(u32*)((u8*)*(u32*)(p + 4) + 264) &= ~0x100;
    func_001c0e60((void*)*(u32*)(p + 4));
    YS__STDOBJ__reset_special_command((void*)*(u32*)(p + 4));
    if (*(void**)(p + 48)) {
        dk__LockOn__end(*(void**)(p + 48));
        *(void**)(p + 48) = 0;
    }
    D_0034f240 &= ~0x4000;
    func_0014ebd8();
    func_001ad990(c + 2100, 0.0f, 1.0f, 0.0f);
    func_001ad990((u8*)*(u32*)(p + 4) + 2100, 0.0f, 1.0f, 0.0f);
    *(u32*)(p + 32) &= ~1;
    func_00190128((u8*)*(u32*)(p + 4) + 2548);
    if (*(void**)(c + 2880)) YS__LOCKON__release(*(void**)(c + 2880));
    if ((*(s32*)(*(u8**)(c + 12) + 4) ^ 0x3f) == 0) {
        func_0016bd60(c, 0);
        u8* o = *(u8**)(c + 12);
        (*(void (**)(void*, void*, f32))(*(u8**)o + 12))(o, c, 0.0f);
    } else func_0016bd60(c, 0);
}
}  // namespace n0011b250

// ---- 0011b3e0 from src/anon/tiny_wrappers_more.cpp
namespace n0011b3e0 {
u32 func_001124e0(u32, u32, u32, u32) asm("_Z13func_001124e0jjjj");
u32 func_0011b3e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011b3e0jjjj");
u32 func_0011b3e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001124e0(a0, a1, a2, a3);
}
}  // namespace n0011b3e0

