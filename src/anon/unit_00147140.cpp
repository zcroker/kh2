// Linked unit 0x00147140-0x00148c50 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../harata/libdk/aabbox.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00147140 (was src/anon/batch_w8026_nsa.c)
namespace n00147140 {
/* 00147140 */
struct E30 { u8 pad[0x30]; };
struct H147 { u32 x0; struct E30* tab; };
struct O147 { u8 pad[0xd0]; u8 m[0x48]; u16 a; u16 b; };
s32 func_00144d90(void*, void*) asm("func_00144d90");
u16 func_00147050(struct H147*, u16, struct O147*, u16, s32*) asm("func_00147050");
/*TARGET 00147140*/
void func_00147140(struct H147* h, struct O147* o) asm("func_00147140");
void func_00147140(struct H147* h, struct O147* o) {
    s32 n; u16 r = o->a;
    if (!func_00144d90((u8*)&h->tab[r] + 0x10, o->m)) {
        n = 0;
        r = func_00147050(h, 0, o, 0, &n);
    } else {
        n = o->b;
        r = func_00147050(h, o->a, o, o->b, &n);
    }
    o->a = r;
    o->b = n;
}
}  // namespace n00147140

// 001471d8 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n001471d8 {
u32 func_00148a08(u32, u32, u32, u32) asm("_Z13func_00148a08jjjj");
/*TARGET 001471d8*/
// 0x00138c10: definition moved into src/anon/unit_00138480.cpp

u32 func_001471d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001471d8jjjj");
// 0x00138c10: definition moved into src/anon/unit_00138480.cpp

u32 func_001471d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r5;
    r2 = func_00148a08(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(8));
    r14 = (u32)((s32)0u + (-5));
    r15 = (u32)(r15 & r14);
    *(u32*)((u32)r16 + (s32)(8)) = r15;
    return r2;
}
}  // namespace n001471d8

// 00147210 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00147210 {
u32 func_00148a08(u32, u32, u32, u32) asm("_Z13func_00148a08jjjj");
/*TARGET 00147210*/
u32 func_00147210(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00147210jjjj");
u32 func_00147210(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r5;
    r2 = func_00148a08(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(8));
    r15 = (u32)(r15 | 0x0004u);
    *(u32*)((u32)r16 + (s32)(8)) = r15;
    return r2;
}
}  // namespace n00147210

// 00147240 (was src/anon/batch_w47.cpp)
namespace n00147240 {
// 0x0013e610: definition moved into src/anon/unit_0013dfb8.cpp

s32 func_00228378(u8*, u8*) asm("func_00228378");
/*TARGET 00147240*/
s32 func_00147240(u8* p, u8* q, f32 f) asm("func_00147240");
s32 func_00147240(u8* p, u8* q, f32 f) {
    s32 r;
    if (func_00228378(p, q)) r = 0;
    else if (!p[1912]) r = 0;
    else if ((*(u32*)(q + 248) & 1) == 1) r = f < *(f32*)(p + 1908);
    else r = 0;
    return r;
}
}  // namespace n00147240

// 001472b8 (was src/anon/batch_w95.cpp)
namespace n001472b8 {
union FI { f32 f; s32 i; };
/*TARGET 001472b8*/
// 0x0013f888: definition moved into src/anon/unit_0013ef70.cpp

// Quicksort of key[] (floats, ascending) carrying idx[] along.
void func_001472b8(FI* idx, FI* key, s32 lo, s32 hi) asm("func_001472b8");
// 0x0013f888: definition moved into src/anon/unit_0013ef70.cpp

// Quicksort of key[] (floats, ascending) carrying idx[] along.
void func_001472b8(FI* idx, FI* key, s32 lo, s32 hi) {
    s32 i = lo, j = hi;
    f32 p = key[(hi + lo) >> 1].f;
    do {
        while (key[i].f < p) i++;
        while (p < key[j].f) j--;
        if (i <= j) {
            f32 t = key[i].f; key[i].f = key[j].f; key[j].f = t;
            s32 u = idx[i].i; idx[i].i = idx[j].i; idx[j].i = u;
            i++; j--;
        }
    } while (i <= j);
    if (lo < j) func_001472b8(idx, key, lo, j);
    if (i < hi) func_001472b8(idx, key, i, hi);
}
}  // namespace n001472b8

// 001473e8 (was src/anon/batch_w3683_nsa.cpp)
namespace n001473e8 {
struct W1649Ob {
    u8 pad0[44];
    s32 group;          // 44
    u8 pad1[248 - 48];
    u32 flags;   // 248 (union: read after float stores)
    u8 pad2[12];
    f32 fadeDist;       // 264
    u8 alpha;           // 268
};
struct W1649Ent { W1649Ob* obj; u32 flags; };
struct W1649Eff { u8 pad[864]; s32 active; u8 pad1[12]; };
struct W1649Pos { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1649Mgr {
    u8 pad0[1912];
    u8 drawExtra;           // 1912
    u8 grouped;             // 1913
    u8 pad1[2];
    s32 extraOn[(1936 - 1916) / 4];   // 1916, per slot
    u8 extraEff[3152 - 1936];         // 1936
    s32 effCount[4];        // 3152, per slot
    W1649Eff effs[16];      // 3168
    W1649Ent ents[512];     // 17248
    s32 entCount;           // 21344
    u8 pad2[8];
    s32 slot;               // 21356
    void* pending0;         // 21360
    void* pending1;         // 21364
};
s32 func_00106a08(void) asm("func_00106a08");
void* func_00106a60(s32) asm("func_00106a60");
void kn__Camera__getPosition(void*, W1649Pos*) asm("kn__Camera__getPosition");
void func_00148598(W1649Mgr*, void*) asm("func_00148598");
void func_001b81e8(void) asm("func_001b81e8");
void func_001b8218(void) asm("func_001b8218");
void func_00148a30(W1649Mgr*) asm("func_00148a30");
void func_00148ac0(W1649Mgr*) asm("func_00148ac0");
void dk__OctDrawFile__calcCameraRelative(W1649Mgr*, W1649Ob*) asm("dk__OctDrawFile__calcCameraRelative");
f32 func_00148890(W1649Mgr*, W1649Ob*, W1649Pos*) asm("func_00148890");
void func_001472b8(void*, void*, s32, s32) asm("func_001472b8");
void func_00148e40(W1649Mgr*, W1649Ob*, W1649Ob** out, s32* n) asm("func_00148e40");
void func_00148ef0(W1649Mgr*, W1649Ob**, s32) asm("func_00148ef0");
s32 func_00147a68(W1649Mgr*, s32*, s32*) asm("func_00147a68");
void func_00147aa8(W1649Mgr*, W1649Ob*, f32) asm("func_00147aa8");
void W1649_effCreate(void*) asm("_ZN3ryj6EFFECT6CreateEPN2dk10UserEffectE");
// Scratchpad sort arrays (see func_001472b8): keys are floats, the carried values are entry pointers.
union W1649FI { f32 f; W1649Ent* e; };
#define W1649_KEYS ((W1649FI*)0x70000000)
#define W1649_DIST ((f32*)0x70000800)
#define W1649_SORTED ((W1649FI*)0x70001000)
/*TARGET 001473e8*/
// Built with -fno-strict-aliasing (_nsa file).
// Per-frame update of all entries: measures their distance to the camera, sorts the visible ones
// (nearest first, in scratchpad), fades out far ones, and updates them (by group when grouped).
void dk__OctDrawFile__drawObjectAll(W1649Mgr* m) asm("dk__OctDrawFile__drawObjectAll");
// Built with -fno-strict-aliasing (_nsa file).
// Per-frame update of all entries: measures their distance to the camera, sorts the visible ones
// (nearest first, in scratchpad), fades out far ones, and updates them (by group when grouped).
void dk__OctDrawFile__drawObjectAll(W1649Mgr* m)
{
    W1649Pos cam;
    W1649Ob* buf[32];
    s32 state[512];
    s32 nb;
    s32 last;
    f32* dist;
    W1649FI* sorted;
    W1649FI* keys;
    s32 n, cnt;

    m->slot = func_00106a08();
    if (m->pending0) func_00148598(m, m->pending0);
    if (m->pending1) func_00148598(m, m->pending1);
    dist = W1649_DIST;
    keys = W1649_KEYS;
    sorted = W1649_SORTED;
    cnt = 0;
    m->extraOn[m->slot] = 0;
    m->effCount[m->slot] = 0;
    func_001b81e8();
    func_00148a30(m);
    kn__Camera__getPosition(func_00106a60(1), &cam);
    n = m->entCount;
    {
        for (s32 i = 0; i < n; i++) {
            W1649Ent* e = &m->ents[i];
            W1649Ob* o = e->obj;
            dk__OctDrawFile__calcCameraRelative(m, o);
            f32 r = func_00148890(m, o, &cam);
            W1649_DIST[i] = r;
            if (o->flags & 4) {
                if (!(o->flags & 0x40)) {
                    keys[cnt].f = r;
                    sorted[cnt].e = e;
                    cnt++;
                }
            }
        }
    }
    if (cnt >= 2) func_001472b8(sorted, keys, 0, cnt - 1);
    last = cnt - 1;
    for (s32 i = 0; i < n; i++) {
        W1649Ent* e = &m->ents[i];
        if (!(e->flags & 2)) continue;
        W1649Ob* o = e->obj;
        if (!(o->flags & 0x2000)) {
            if (!(o->flags & 0x40)) {
                if (o->fadeDist != 0.0f) {
                    f32 dd = dist[i];
                    if (o->fadeDist < dd) continue;
                    f32 near = o->fadeDist - 400.0f;
                    if (near < dd) o->alpha = (s32)(o->alpha * (1.0f - (dd - near) / 400.0f));
                }
            }
        }
        nb = 0;
        func_00148e40(m, e->obj, buf, &nb);
        if (nb) {
            buf[nb] = 0;
            func_00148ef0(m, buf, nb);
        }
    }
    if (!m->grouped) {
        for (s32 i = last; i >= 0; i--) {
            W1649Ent* e = sorted[i].e;
            if (e->flags & 2) func_00147aa8(m, e->obj, keys[i].f);
        }
    } else {
        for (s32 i = last; i >= 0; i--) state[i] = sorted[i].e->obj->group;
        s32 k = last;
        for (;;) {
            s32 j = k;
            s32 g = func_00147a68(m, &k, state);
            if (g == 1) break;
            for (; j >= 0; j--) {
                W1649Ent* e = sorted[j].e;
                if (state[j] != 1 && state[j] == g) {
                    state[j] = 1;
                    if (e->flags & 2) func_00147aa8(m, e->obj, 0.0f);
                }
            }
        }
    }
    func_00148ac0(m);
    func_001b8218();
    s32 ec = m->effCount[m->slot];
    for (s32 i = 0; i < ec; i++) {
        W1649Eff* f = &m->effs[i];
        if (f->active) W1649_effCreate(f);
    }
    if (m->drawExtra && m->extraOn[m->slot]) W1649_effCreate(m->extraEff);
}
}  // namespace n001473e8

// 00147810 (was src/anon/batch_w323.cpp)
namespace n00147810 {
#define QCOPY323(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV323 {
    f32 x, y, z, w;
    QV323() {}
    QV323(const QV323& o) { QCOPY323(this, &o); }
    QV323& operator=(const QV323& o) { if (this != &o) QCOPY323(this, &o); return *this; }
    QV323 operator-(const QV323& o) const {
        QV323 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    QV323 operator*(f32 k) const {
        QV323 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 dot(const QV323& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 lensq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    void normalize0() {
        asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "$8", "$f0", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
#define QCOPY4_323(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QM323 {
    QV323 r[4];
    QM323() {}
    QM323(const QM323& o) { QCOPY4_323(this, &o); }
    QM323& operator=(const QM323& o) { if ((u32)this != (u32)&o) QCOPY4_323(this, &o); return *this; }
    QV323 operator*(const QV323& v) const {
        QV323 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    QM323 operator*(const QM323& b) const {
        QM323 o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
extern u8 D_0033cc50 asm("D_0033cc50");
void func_001070e8(void*) asm("func_001070e8");
struct Cam323 {
    u32 vt;
    QM323 m;
    QV323 a, b, c;
    f32 d;
    Cam323(const Cam323& o) : m(o.m), a((vt = (u32)&D_0033cc50, o.a)), b(o.b), c(o.c), d(o.d) {}
    ~Cam323() { func_001070e8(this); }
} __attribute__((aligned(16)));
Cam323* func_00106a60(s32) asm("func_00106a60");
/*TARGET 00147810*/
// buffer_get_by_index
void dk__OctDrawFile__calcCameraRelative(u32, u8* o) asm("dk__OctDrawFile__calcCameraRelative");
// buffer_get_by_index
void dk__OctDrawFile__calcCameraRelative(u32, u8* o) {
    if (!(*(u32*)(o + 248) & 0x1000)) return;
    if (*(u32*)(o + 288)) return;
    QM323 w;
    QV323 p;
    QV323 pad;
    Cam323 c(*func_00106a60(1));  // buffer_get_by_index
    c.m.invOrtho();
    p = c.m * *(QV323*)(o + 192);
    w = *(QM323*)(o + 64);
    w = c.m * w;
    *(QM323*)(o + 64) = w;
    *(QV323*)(o + 192) = p;
}
}  // namespace n00147810

// 00147a68 (was src/anon/tiny_auto80_queue.cpp)
namespace n00147a68 {
/*TARGET 00147a68*/
u32 func_00147a68(u32 a0, u32 a1, u32 a2) asm("_Z13func_00147a68jjj");
u32 func_00147a68(u32 a0, u32 a1, u32 a2) {
    s32 t6 = *(s32*)((u32)a1 + (s32)(0));
    u32 t7;
    u32 t5;
    u32 v0;
    if (t6 < 0) goto RET1;
    t7 = (u32)(t6 << 2);
    t5 = 1u;
    v0 = (u32)(t7 + a2);
LOOP:
    t7 = *(u32*)((u32)v0 + (s32)(0));
    if (t7 != t5) {
        *(s32*)((u32)a1 + (s32)(0)) = t6;
        return *(u32*)((u32)v0 + (s32)(0));
    }
    t6 = (s32)(t6 - 1);
    if (t6 >= 0) {
        v0 = (u32)((u32)v0 - 4);
        goto LOOP;
    }
RET1:
    return 1u;
}
}  // namespace n00147a68

// 00147aa8 (was src/anon/batch_w112.cpp)
namespace n00147aa8 {
struct Ob { u8 pad[56]; u32 f56; u8 pad1[4]; u8 f64[184]; u32 flags; u8 pad2[4]; u32 f256; u8 pad3[10]; u8 state[4]; };
struct Mgr { u8 pad[3152]; s32 cnt[(21356 - 3152) / 4]; s32 idx; };
void func_001349a8(u32, u8*, u32) asm("func_001349a8");
s32 func_00147240(Mgr*, Ob*, f32) asm("func_00147240");
void func_00147ca0(Mgr*, Ob*, f32) asm("func_00147ca0");
void func_00147d80(Mgr*, Ob*, f32) asm("func_00147d80");
void dk__OctDrawFile__drawModel(Mgr*, Ob*) asm("dk__OctDrawFile__drawModel");
/*TARGET 00147aa8*/
// Per-frame update of an entry: refreshes it, then queues it (bounded at 16 per slot) by state.
void func_00147aa8(Mgr* m, Ob* o, f32 t) asm("func_00147aa8");
// Per-frame update of an entry: refreshes it, then queues it (bounded at 16 per slot) by state.
void func_00147aa8(Mgr* m, Ob* o, f32 t) {
    s32 had = 0;
    if (o->flags & 0x4000) {
        o->flags &= ~0x4000;
        had = 1;
    }
    if (o->f56 && o->f256) func_001349a8(o->f56, o->f64, o->f256);
    if (func_00147240(m, o, t)) {
        func_00147ca0(m, o, t);
        o->state[m->idx] = 1;
        return;
    }
    if (o->state[m->idx] == 1) func_00147ca0(m, o, t);
    if (*(u8*)((u8*)o + 235) != 0 && *(s8*)((u8*)o + 235) >= 0 && m->cnt[m->idx] < 16 && (o->flags & 0x10)) {
        if (had == 1) return;
        func_00147d80(m, o, t);
        m->cnt[m->idx]++;
        return;
    }
    if (o->state[m->idx] == 2 && m->cnt[m->idx] < 16) {
        func_00147d80(m, o, t);
        m->cnt[m->idx]++;
    }
    dk__OctDrawFile__drawModel(m, o);
}
}  // namespace n00147aa8

// 00147c78 (was src/anon/batch_w3.cpp)
namespace n00147c78 {
/*TARGET 00147c78*/
// 00136fa8: moved to src/harata/libdk/bgm.cpp

// Copy the RGBA bytes at +0xe8 to +0x0c.
void func_00147c78(u32, u8* p) asm("func_00147c78");
// 00136fa8: moved to src/harata/libdk/bgm.cpp

// Copy the RGBA bytes at +0xe8 to +0x0c.
void func_00147c78(u32, u8* p) {  // copy_bytes_232_to_12
    u8 r = p[232], g = p[233], b = p[234], a = p[235];
    p[12] = r;
    p[13] = g;
    p[14] = b;
    p[15] = a;
}
}  // namespace n00147c78

// 00147ca0 (was src/anon/batch_w2378_nsa.cpp)
namespace n00147ca0 {
// 00147ca0: recursive node walk. num/cur reproduce the original's store/load order
// (the list store stays ahead of the count store, the cur load after both). Built -fno-strict-aliasing.
struct NodeW2378 { u8 pad[0xec]; NodeW2378* next; NodeW2378* child; NodeW2378* pad2; u32 flags; u8 pad3[0x11c - 0xfc]; u16 idx; };
struct TblW2378 { u32 on:1; u32 rest:31; u32 pad; };
struct MgrW2378 {
    u8 pad[0x770]; s32 hdr[3]; s32 cnt[3]; u8 pad1[0x794 - 0x788]; f32 time;
    NodeW2378* list[(0xc40 - 0x798) / 4]; volatile s32 num;
    u8 pad2[0x4364 - 0xc44]; TblW2378 tbl[(0x536c - 0x4364) / 8]; volatile s32 cur;
};
void func_00147c78(MgrW2378*, NodeW2378*, f32) asm("func_00147c78");
/*TARGET 00147ca0*/
// copy_bytes_232_to_12

// Queues every enabled node of the tree (flag 4 + table bit) and counts it for the current slot.
void func_00147ca0(MgrW2378* m, NodeW2378* n, f32 t) asm("func_00147ca0");
// copy_bytes_232_to_12

// Queues every enabled node of the tree (flag 4 + table bit) and counts it for the current slot.
void func_00147ca0(MgrW2378* m, NodeW2378* n, f32 t)
{
    u16 idx = n->idx;
    if ((n->flags & 4) && ((TblW2378*)((u32)m + (idx << 3) + 0x4364))->on) {
        func_00147c78(m, n, t);
        m->time = t;
        s32 i = m->num;
        s32 k = i * 4;
        *(NodeW2378**)((u8*)m + k + 0x798) = n;
        m->num = i + 1;
        s32* p = (s32*)(m->cur * 4 + (u32)m + 0x770);
        p[3]++;
    }
    NodeW2378* c = 0;
    while ((c = !c ? n->child : c->next) != 0) func_00147ca0(m, c, t);
}
}  // namespace n00147ca0

// 00147d80 (was src/anon/batch_w3729.cpp)
namespace n00147d80 {
struct NodeW { u8 p0[0xf]; s8 b0f; u8 p10[0xeb - 0x10]; u8 beb; NodeW* next; NodeW* child; NodeW* pad2; u32 flags; u8 pfc[0x10e - 0xfc]; u8 st[0xe]; u16 idx; };
struct TblW { u32 on:1; u32 rest:31; u32 pad; };
struct GrpW { u32 a; f32 time; NodeW* list[(0x360 - 8) / 4]; union { s32 n; f32 f; } num; u8 pad[0x370 - 0x364]; };
struct MgrW {
    u8 pad[0xc50]; s32 map[4]; GrpW grp[15]; u8 pad1[0x4364 - 0xc60 - 15 * 0x370];
    TblW tbl[(0x536c - 0x4364) / 8]; s32 cur;
};
union NumW { s32 n; f32 f; };
struct Sub2W { u8 p[14]; u8 st; void set(u8 v) { st = v; } };
// Adds node n (and recursively its children) to the manager's current group when it is flagged and enabled.
// Register pins and one empty asm (w3729) fix the t6/t7 choice and the count-block order.
void func_00147c78(MgrW*, NodeW*) asm("func_00147c78");
/*TARGET 00147d80*/
void func_00147d80(MgrW* m, NodeW* n, f32 t) asm("func_00147d80");
void func_00147d80(MgrW* m, NodeW* n, f32 t)
{
    u16 idx = n->idx;
    if ((n->flags & 4) && ((TblW*)((u32)m + (idx << 3) + 0x4364))->on) {
        if (n->beb) {
            s32 k = m->map[m->cur];
            func_00147c78(m, n);
            n->b0f = -128;
            u32 o = k * 0x370 + (u32)m; GrpW* g = (GrpW*)(o + 0xc60); g->time = t; NumW* c = (NumW*)(o + 0xfc0); s32 i = c->n;
            u32 a = (i << 2) + (u32)g;
            s32 j = i + 1;
            asm("" : "+r"(j) : "r"(a));
            c->n = j; *(NodeW**)(a + 8) = n;
        }
        register s32 cur asm("$14") = m->cur;
        s32 two = 2;
        ((Sub2W*)(cur + (u32)n + 0x100))->set(two);
    }
    NodeW* c = 0;
    while ((c = !c ? n->child : c->next) != 0) func_00147d80(m, c, t);
}
}  // namespace n00147d80

// 00147e80 (was src/anon/batch_w1670.cpp)
namespace n00147e80 {
void func_00134408(void) asm("func_00134408");
void func_00134428(u32, u64) asm("func_00134428");
void func_00134450(u32) asm("func_00134450");
/*TARGET 00147e80*/
// 0x001b53b0: definition moved into src/anon/unit_001b2780.cpp

void func_00147e80(u8* o) asm("func_00147e80");
// 0x001b53b0: definition moved into src/anon/unit_001b2780.cpp

void func_00147e80(u8* o) {
    u64 v = (u64)(s32)(0x7000 - *(s16*)(o + 0x14)) | ((u64)(0x7300 - *(s16*)(o + 0x16)) << 32);
    func_00134408();
    func_00134428(0x18, v);
    func_00134450(1);
}
}  // namespace n00147e80

// 00147ed0 (was src/anon/tiny_auto80_solver.cpp)
namespace n00147ed0 {
u32 func_00134408(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00134408");
u32 func_00134428(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00134428");
u32 func_00134450(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00134450");
/*TARGET 00147ed0*/
u32 func_00147ed0(void) asm("func_00147ed0");
u32 func_00147ed0(void) {
    ((u32(*)())func_00134408)();
    u64 a1 = 115;
    a1 <<= 40;
    ((u32(*)(u32, u64))func_00134428)(24, a1 | 0x7000u);
    return ((u32(*)(u32))func_00134450)(1);
}
}  // namespace n00147ed0

// 00147f08 (was src/anon/batch_w3701_nsa.cpp)
namespace n00147f08 {
// VU0 vector / matrix helpers (inline asm like the game's vector library).
struct W3701Vec {
    f32 x, y, z, w;
    W3701Vec() {}
    W3701Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W3701Vec& operator=(const W3701Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W3701Vec& operator+=(const W3701Vec& o) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
    // Perspective divide: this *= 1/w.
    void divW() {
        f32 d = w;
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(d) : "$8", "memory");
    }
} __attribute__((aligned(16)));
struct W3701Mtx {
    W3701Vec r[4];
    W3701Mtx() {}
    inline W3701Mtx(const W3701Mtx& o) __attribute__((always_inline));
    W3701Mtx& operator=(const W3701Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // Full 4x4 transform.
    void apply(W3701Vec& o, const W3701Vec& v) const {
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
    }
    // Point transform (w = 1).
    void applyPoint(W3701Vec& o, const W3701Vec& v) const {
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
    }
    // Inverse of a rotation + translation matrix (transpose, translation = -R^T t).
    void orthoInverse() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
                     "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                     "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                     "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                     "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
                     : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
inline W3701Mtx::W3701Mtx(const W3701Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
extern "C" void func_0031bae0(void*, const void*);   // sceVu0CopyMatrix
struct W3701F2 { f32 v[2]; };
struct W3701I3 { s32 v[3]; };
struct W3701DI { u64 d; s32 i; };
struct W3701I5 { s32 v[5]; };
struct W3701U64 { u64 v; };
struct W3701S32 { s32 v; };
struct W3701Mtx2 {
    f32 m[4][4];
} __attribute__((aligned(16)));
void W3701_projDtor(void*) asm("_ZN2kn10ProjectionD1Ev");
struct W3701Proj {
    W3701Mtx view;
    f32 f64;
    f32 fov[2];
    s32 i76[3];
    u64 d88;
    s32 i96;
    f32 f100, f104, f108, f112, f116, f120;
    W3701Mtx2 m128;
    W3701Mtx2 m192;
    inline W3701Proj(const W3701Proj& o, void* mgr) __attribute__((always_inline));
    ~W3701Proj() { W3701_projDtor(this); }
};

inline W3701Proj::W3701Proj(const W3701Proj& o, void* mgr) : view(o.view) {
        // Scalar part of the copy, loads in the original's order.
        register s32 b76 asm("$14"), b80 asm("$13"), b84 asm("$12");
        register u32 a68 asm("$8"), a72 asm("$9");
        register u64 d asm("$11");
        register s32 i asm("$10");
        register f32 c120 asm("$f6"), a64 asm("$f5");
        register f32 c100 asm("$f0"), c104 asm("$f1"), c108 asm("$f2"), c112 asm("$f3"), c116 asm("$f4");
        void* q1;
        void* q0;
        const W3701Proj* op = &o;
        asm volatile("lw %0, 76(%1)" : "=r"(b76) : "r"(op));
        asm volatile("addiu %0, %1, 160" : "=r"(q1) : "r"(mgr));
        asm volatile("lw %0, 80(%1)" : "=r"(b80) : "r"(op));
        asm volatile("addiu %0, $sp, 256" : "=r"(q0));
        asm volatile("lw %0, 84(%1)" : "=r"(b84) : "r"(op));
        asm volatile("lw %0, 68(%1)" : "=r"(a68) : "r"(op));
        asm volatile("lw %0, 72(%1)" : "=r"(a72) : "r"(op));
        asm volatile("ld %0, 88(%1)" : "=r"(d) : "r"(op));
        asm volatile("lw %0, 96(%1)" : "=r"(i) : "r"(op));
        asm volatile("lwc1 %0, 120(%1)" : "=f"(c120) : "r"(op));
        asm volatile("lwc1 %0, 64(%1)" : "=f"(a64) : "r"(op));
        asm volatile("lwc1 %0, 100(%1)" : "=f"(c100) : "r"(op));
        asm volatile("lwc1 %0, 104(%1)" : "=f"(c104) : "r"(op));
        asm volatile("lwc1 %0, 108(%1)" : "=f"(c108) : "r"(op));
        asm volatile("lwc1 %0, 112(%1)" : "=f"(c112) : "r"(op));
        asm volatile("lwc1 %0, 116(%1)" : "=f"(c116) : "r"(op));
        f64 = a64; ((u32*)fov)[0] = a68; ((u32*)fov)[1] = a72; i76[0] = b76; i76[1] = b80; i76[2] = b84;
        d88 = d; i96 = i; f100 = c100; f104 = c104; f108 = c108; f112 = c112; f116 = c116; f120 = c120;
        func_0031bae0(q0, q1);
        func_0031bae0(m192.m, o.m192.m);
    }
struct W3701Box { f32 x0, y0, z0, x1, y1, z1; };
struct W3701Ob {
    s32 id;             // 0
    u32 pad4;
    u8 sub8[16];        // 8
    u64 gs24;           // 24
    u64 gs32;           // 32
    u8 pad40[24];
    W3701Mtx mtx;       // 64
    u8 pad128[64];
    W3701Vec pos;       // 192
    W3701Box box;       // 208, bounds
    u8 color[4];        // 232
    u8 pad236[12];
    u32 flags;          // 248
    u8 pad252[8];
    f32 boxGrow;        // 260
    f32 fadeDist;       // 264
    u8 alpha;           // 268
    u8 b269;            // 269
    u8 vis[2];          // 270, per slot
    u8 pad272[14];
    u8 b286;            // 286
    u8 pad287;
    W3701Mtx* attach;   // 288
};
struct W3701ObFl { u8 pad[248]; u32 flags; };
struct W3701Mgr {
    u8 pad0[32];
    W3701Proj proj;     // 32
    u8 pad288[16];
    W3701Mtx view;      // 304
    W3701Mtx screen;    // 368?
    W3701Mtx clip;      // 432
    u8 frustum[21352 - 496];    // 496
    s32 x21352;         // 21352
    s32 slot;           // 21356
};
struct W3701Pkt { u8 pad0[20]; u32 xy; u8 pad24[56]; void* cb0; void* cb1; };
extern "C" {
void func_00147c78(W3701Mgr*, W3701Ob*);
void func_00106fe8(W3701Proj*, f32);
void kn__Projection__calcMatrix(W3701Proj*);
W3701Pkt* func_0011ca20(s32, void*, W3701Mtx*, void*, u8);
void func_00147e80(void);
void func_00147ed0(void);

void func_00147f08(W3701Mgr* m, W3701Ob* o)
{
    func_00147c78(m, o);
    s32 slot = m->slot;
    o->gs32 = 0x31000070;
    o->vis[slot] = 0;
    o->gs24 = 0x800d8;
    if (((W3701ObFl*)o)->flags & 0x1000) {
        W3701Mtx M;
        W3701Vec* pt = &M.r[3];
        W3701Vec t;
        W3701Vec scr;
        W3701Vec pos;
        W3701Vec* pv = &t;
        W3701Vec* ps = &scr;
        W3701Vec* pp = &pos;
        if (o->attach) {
            W3701Vec v;
            W3701Vec* pw = &v;
            M = *o->attach;
            pw->x = M.r[0].w;
            pw->y = M.r[1].w;
            pw->z = M.r[2].w;
            f32 s = M.r[3].w;
            M.r[3].w = 1.0f;
            M.r[0].w = 0.0f;
            M.r[1].w = 0.0f;
            M.r[2].w = 0.0f;
            W3701Proj cam(m->proj, m);
            func_00106fe8(&cam, s);
            kn__Projection__calcMatrix(&cam);
            *pp = *pt;
            *pp += *pw;
            cam.view.apply(*ps, *pp);
            ps->divW();
            ps->x -= 2048.0f;
            ps->y -= 2048.0f;
            pt->x -= pp->x;
            pt->y -= pp->y;
            W3701Pkt* p = func_0011ca20(o->id, &cam, &M, o->sub8, o->b269);
            p->cb0 = (void*)func_00147e80;
            p->xy = ((s32)(ps->x * 16.0f + 0.5f) & 0xffff) | ((s32)(ps->y * 16.0f + 0.5f) << 16);
            p->cb1 = (void*)func_00147ed0;
        } else {
            M = o->mtx;
            *pv = o->pos;
            m->view.applyPoint(*pp, *pv);
            *ps = o->pos;
            ps->w = 1.0f;
            m->clip.apply(*ps, *ps);
            ps->divW();
            ps->x -= 2048.0f;
            ps->y -= 2048.0f;
            W3701Mtx W(m->view);
            W.orthoInverse();
            W3701Vec z(0.0f, 0.0f, pp->z, 0.0f);
            W.applyPoint(*pt, z);
            W3701Pkt* p = func_0011ca20(o->id, &m->clip, &M, o->sub8, o->b269);
            p->cb0 = (void*)func_00147e80;
            p->xy = ((s32)(ps->x * 16.0f + 0.5f) & 0xffff) | ((s32)(ps->y * 16.0f + 0.5f) << 16);
            p->cb1 = (void*)func_00147ed0;
        }
    } else {
        func_0011ca20(o->id, &m->clip, &o->mtx, o->sub8, o->b269);
    }
}
}
}  // namespace n00147f08

// 00148470 (was src/anon/batch_w1790_gnsa.cpp)
namespace n00148470 {
// ---- 00148470 ----
struct W1790Node { u8 p0[235]; u8 eb; struct W1790Node* ec; struct W1790Node* f0; u32 f4; u32 f8; u8 pfc[32]; u16 h11c; u8 b11e; u8 b11f; };
struct W1790Flag { u32 f : 1; u32 r : 31; u32 pad; };
struct W1790Mgr { u8 p[17252]; W1790Flag tbl[1]; };
static inline u32 w1790_tst(u8* base, u32 off) { return ((W1790Flag*)(base + off))->f; }
static inline W1790Node* w1790_next(W1790Node* n, W1790Node* c) { return c == 0 ? n->f0 : c->ec; }
void func_00148a68(W1790Mgr*, W1790Node*) asm("func_00148a68");
void func_00147f08(W1790Mgr*, W1790Node*) asm("func_00147f08");
/*TARGET 00148470*/
// 0x0013aba8: definition moved into src/anon/unit_0013a8b8.cpp

void dk__OctDrawFile__drawModel(W1790Mgr* g, W1790Node* n) asm("dk__OctDrawFile__drawModel");
// 0x0013aba8: definition moved into src/anon/unit_0013a8b8.cpp

void dk__OctDrawFile__drawModel(W1790Mgr* g, W1790Node* n) {
    u16 i = n->h11c;
    if (n->eb && (n->f8 & 4)) {
        if (w1790_tst((u8*)g->tbl, i * 8)) {
            if (n->b11f) func_00148a68(g, n); else func_00147f08(g, n);
        }
    }
    W1790Node* c = 0;
    while ((c = w1790_next(n, c)) != 0) dk__OctDrawFile__drawModel(g, c);
}
}  // namespace n00148470

// 00148528 (was src/anon/tiny_auto80_queue.cpp)
namespace n00148528 {
/*TARGET 00148528*/
void func_00148528(u32 a0) asm("_Z13func_00148528j");
void func_00148528(u32 a0) {
    u32 t6 = *(u32*)((u32)a0 + (s32)(21360));
    if (t6 != 0u) {
        u32 t7 = *(u32*)((u32)t6 + (s32)(248));
        t7 = (u32)(t7 | 0x0004u);
        *(u32*)((u32)t6 + (s32)(248)) = t7;
    }
    a0 = *(u32*)((u32)a0 + (s32)(21364));
    if (a0 != 0u) {
        u32 t7 = *(u32*)((u32)a0 + (s32)(248));
        t7 = (u32)(t7 | 0x0004u);
        *(u32*)((u32)a0 + (s32)(248)) = t7;
    }
}
}  // namespace n00148528

// 00148560 (was src/anon/tiny_auto80_queue.cpp)
namespace n00148560 {
/*TARGET 00148560*/
void func_00148560(u32 a0) asm("_Z13func_00148560j");
void func_00148560(u32 a0) {
    u32 t5 = *(u32*)((u32)a0 + (s32)(21360));
    if (t5 != 0u) {
        u32 t6 = 0xfffffffbu;
        u32 t7 = *(u32*)((u32)t5 + (s32)(248));
        t7 = (u32)(t7 & t6);
        *(u32*)((u32)t5 + (s32)(248)) = t7;
    }
    a0 = *(u32*)((u32)a0 + (s32)(21364));
    if (a0 != 0u) {
        u32 t6 = 0xfffffffbu;
        u32 t7 = *(u32*)((u32)a0 + (s32)(248));
        t7 = (u32)(t7 & t6);
        *(u32*)((u32)a0 + (s32)(248)) = t7;
    }
}
}  // namespace n00148560

// 00148598 (was src/anon/batch_w61.cpp)
namespace n00148598 {
union FU { f32 f; void* p; u32 u; };
void func_00147c78(u8*, u8*) asm("func_00147c78");
// copy_bytes_232_to_12
void func_0011cd80(u32, u8*, u8*, u8*, void*, u32) asm("func_0011cd80");
struct B148 { s16 a, b; u8 pad[12]; };
/*TARGET 00148598*/
void func_00148598(u8* a0, u8* a1) asm("func_00148598");
void func_00148598(u8* a0, u8* a1) {
    if (a1[235] && (*(u32*)(a1 + 248) & 4)) {
        func_00147c78(a0, a1);  // copy_bytes_232_to_12
        B148 buf;
        (*(u8**)(a0 + 21356) + (u32)a1)[270] = 0;
        *(u64*)(a1 + 32) = 0x31000070;
        *(u64*)(a1 + 24) = 0x800d8;
        buf.a = -32768;
        buf.b = -1;
        func_0011cd80(((FU*)a1)->u, a0 + 432, a1 + 64, a1 + 8, &buf, 0);
    }
}
}  // namespace n00148598

// 00148638 (was src/anon/batch_w32.cpp)
namespace n00148638 {
/*TARGET 00148638*/
// Picks a state from four thresholds; 1/2 force a value, the others keep the current one.
void func_00148638(u32, u8* o, f32 x) asm("func_00148638");
// Picks a state from four thresholds; 1/2 force a value, the others keep the current one.
void func_00148638(u32, u8* o, f32 x) {
    f32* f = *(f32**)(o + 276);
    u8 v = o[269];
    f32 a = f[14], b = f[15], c = f[16], d = f[17];
    u8 r;
    if (d < x) r = 2;
    else if (c < x) r = v;
    else if (b < x) r = 1;
    else if (a < x) r = v;
    else r = 0;
    o[269] = r;
}
}  // namespace n00148638

// .rodata 0x36afac: a 4-byte table no code here loads by address
extern "C" const u32 D_0036afac = 0x00020100;

// 00148690 (was src/anon/batch_w2398.cpp)
namespace n00148690 {
struct W2398Lim { u8 pad[0x50]; f32 l50, l54, l58, l5c, l60, l64; };
struct W2398El { u8 b[7]; u8 a; };
struct W2398Own {
    void* h;
    u8 pad4[0x30];
    W2398El* el;
    u8 pad38[0xdc];
    W2398Lim* lim;
};
void func_0011c7c8(void*, s32) asm("func_0011c7c8");
void func_0011c7f8(void*, s32) asm("func_0011c7f8");
/*TARGET 00148690*/
/* Sets the alpha of three elements from t against three [low, high] ranges:
   0 above high, 0x80 below low, fading in between. One shared ratio variable. */
void dk__OctDrawFile__calcPartsLOD(void* self, W2398Own* p, f32 t) asm("dk__OctDrawFile__calcPartsLOD");
/* Sets the alpha of three elements from t against three [low, high] ranges:
   0 above high, 0x80 below low, fading in between. One shared ratio variable. */
void dk__OctDrawFile__calcPartsLOD(void* self, W2398Own* p, f32 t)
{
    if (p->el == 0) return;
    f32 ratio;
    W2398Lim* r = p->lim;
    f32 h1 = r->l64;
    f32 h3 = r->l54;
    f32 l2 = r->l58;
    f32 h2 = r->l5c;
    f32 l1 = r->l60;
    f32 l3 = r->l50;
    func_0011c7c8(p->h, 1);
    func_0011c7c8(p->h, 2);
    func_0011c7c8(p->h, 3);
    W2398El* q = p->el;
    if (h1 < t) {
        q->a = 0;
        func_0011c7f8(p->h, 1);
    } else if (t < l1) {
        q->a = 0x80;
    } else {
        ratio = (t - l1) / (h1 - l1);
        q->a = 0x80 - (s32)(128.0f * ratio);
    }
    q++;
    if (h2 < t) {
        q->a = 0;
        func_0011c7f8(p->h, 2);
    } else if (t < l2) {
        q->a = 0x80;
    } else {
        ratio = (t - l2) / (h2 - l2);
        q->a = 0x80 - (s32)(128.0f * ratio);
    }
    q++;
    if (h3 < t) {
        q->a = 0;
        func_0011c7f8(p->h, 3);
    } else if (t < l3) {
        q->a = 0x80;
    } else {
        ratio = (t - l3) / (h3 - l3);
        q->a = 0x80 - (s32)(128.0f * ratio);
    }
}
}  // namespace n00148690

// 00148890 (was src/anon/batch_wcx2.cpp)
namespace n00148890 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
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
struct V34 {
    f32 x, y, z, w;
    V34() {}
    V34& operator=(const V34& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Ent34 { u8 pad[192]; V34 pos; u8 pad2[40]; u32 fl; };
void func_00148638(f32) asm("func_00148638");
void dk__OctDrawFile__calcPartsLOD(u8*, Ent34*, f32) asm("dk__OctDrawFile__calcPartsLOD");
#define DIST34(r, p, q) { a = p; b = q; r = Dist34(a, b, c); }
static inline f32 Dist34(V34& a, V34& b, V34& c)
{
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&c), "r"(&b), "r"(&a) : "memory");
    f32 r;
    asm volatile("lqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\t"
                 "vsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0"
                 : "=f"(r) : "r"(&c) : "$8", "memory");
    return r;
}
/*TARGET 00148890*/
f32 func_00148890(u8* o, Ent34* e, const V34* q) asm("func_00148890");
f32 func_00148890(u8* o, Ent34* e, const V34* q)
{
    f32 d = 0.0f;
    V34 p;
    V34 a, b, c;
    asm volatile("lqc2 $vf5,0(%1)\n\tlqc2 $vf1,0(%2)\n\tlqc2 $vf2,16(%2)\n\tlqc2 $vf3,32(%2)\n\tlqc2 $vf4,48(%2)\n\t"
                 "vmulax.xyz ACC,$vf1,$vf5x\n\tvmadday.xyz ACC,$vf2,$vf5y\n\tvmaddaz.xyz ACC,$vf3,$vf5z\n\t"
                 "vmaddw.xyz $vf5,$vf4,$vf0w\n\tvmove.w $vf5,$vf0\n\tsqc2 $vf5,0(%0)"
                 : : "r"(&p), "r"(&e->pos), "r"(o + 304) : "memory");
    if (e->fl & 0x80) {
        DIST34(d, e->pos, *q);
        func_00148638(d);
    }
    if (e->fl & 0x100) {
        if (d == 0.0f) DIST34(d, e->pos, *q);
        dk__OctDrawFile__calcPartsLOD(o, e, d);
    }
    return p.z;
}
}  // namespace n00148890

// 00148a08 (was src/anon/tiny_auto80_solver.cpp)
namespace n00148a08 {
void func_00148a08(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00148a08");
/*TARGET 00148a08*/
void func_00148a08(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00148a08");
void func_00148a08(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = *(u16*)(a1 + 284);
    idx <<= 3;
    a0 += idx;
    u32 v = *(u32*)(a0 + 17252);
    v |= 1;
    *(u32*)(a0 + 17252) = v;
    u32 w = *(u32*)(a1 + 248);
    w |= 2;
    *(u32*)(a1 + 248) = w;
}
}  // namespace n00148a08

// 00148a30 (was src/anon/tiny_auto80_queue.cpp)
namespace n00148a30 {
extern u8 D_003a99f0 asm("D_003a99f0");
/*TARGET 00148a30*/
void func_00148a30(u32 a0) asm("_Z13func_00148a30j");
void func_00148a30(u32 a0) {
    *(u32*)((u32)a0 + (s32)(21372)) = 0u;
    u32 t7 = (u32)&D_003a99f0;
    s32 t6 = 255;
L0:
    *(u32*)((u32)t7 + (s32)(0)) = 0u;
    t6 = (s32)(t6 - 1);
    if (t6 >= 0) {
        t7 = (u32)((u32)t7 + 4);
        goto L0;
    }
}
}  // namespace n00148a30

// 00148a68 (was src/anon/batch_w33.cpp)
namespace n00148a68 {
// 00106a18: moved to src/naka/libkn/camera.cpp

extern u32 D_003a99f0[] asm("D_003a99f0");
struct Obj148 { u8 pad[287]; u8 slot; };
/*TARGET 00148a68*/
// Put o into the first free slot at or after its preferred index; bump the owner's count.
void func_00148a68(s32* owner, Obj148* o) asm("func_00148a68");
// Put o into the first free slot at or after its preferred index; bump the owner's count.
void func_00148a68(s32* owner, Obj148* o) {
    u32* t = D_003a99f0;
    u32 i = o->slot;
    while (t[i]) i++;
    t[i] = (u32)o;
    owner[21372 / 4]++;
}
}  // namespace n00148a68

// 00148ac0 (was src/anon/auto80_199_queue.cpp)
namespace n00148ac0 {
/*TARGET 00148ac0*/
void func_00148ac0(u8* a0) asm("_Z13func_00148ac0Ph");
void func_00148ac0(u8* a0) {
    s32 s0 = 0;
    u32* s2 = D_003a99f0;
    s32 s1 = *(s32*)(a0 + 21372);

    while (s0 < 256) {
        if (s1 <= 0) {
            return;
        }

        u32 t7 = *s2;
        s2 += 1;
        if (t7 != 0) {
            func_00147f08((u32)a0, t7);
            s1 -= 1;
        }

        s0 += 1;
    }
}
}  // namespace n00148ac0

// 00148b40 (was src/anon/sweep_00148b40_nsa.cpp)
namespace n00148b40 {
typedef struct G48 { u32 flags; u32 x4; s8 c[4]; } G48;
extern G48 D_00457480 asm("D_00457480");
extern s32 D_00457478 asm("D_00457478");
void func_0011de88(s32, G48*, s16*, s32, s32) asm("_Z13func_0011de88iP3G48Psii");
/*TARGET 00148b40*/
void func_00148b40(s32 u, s32* p) asm("_Z13func_00148b40iPi");
void func_00148b40(s32 u, s32* p) {
    s16 buf[32];
    s32 i;
    s32 n;
    for (i = 0; i < 32; i++) buf[i] = i;
    D_00457480.flags |= 2;
    buf[31] = -1;
    D_00457480.c[2] = -128;
    D_00457480.c[1] = -128;
    D_00457480.c[0] = -128;
    D_00457480.c[3] = -1;
    n = D_00457478;
    func_0011de88(*p, &D_00457480, buf, n, 0);
}
}  // namespace n00148b40

// 00148bc8 (was src/anon/auto80_199_queue.cpp)
namespace n00148bc8 {
u32 func_00144d10(f32* a0, f32* a1) asm("func_00144d10");
/*TARGET 00148bc8*/
void func_00148bc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00148bc8jjjjjjjj");
void func_00148bc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 cur = *(u32*)(a1 + 44);
    if (*(u32*)a2 == cur) {
        return;
    }
    if (cur == 0) {
        return;
    }

    while (cur != 0) {
        if (func_00144d10(cur + 208, a3) == 1) {
            if ((*(u32*)(cur + 248) & 2) != 0) {
                func_00148b40(a0, cur);
            }
        }
        cur = *(u32*)(cur + 272);
    }
}
}  // namespace n00148bc8

