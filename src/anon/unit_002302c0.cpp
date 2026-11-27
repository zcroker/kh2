// Linked unit 0x002302c0-0x00231500 (one namespace per old matched source; class methods in their own namespace).
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
#include "../sasa/event.hpp"
#include "../tozawa/menu_sound.hpp"

// 002302c0 (was src/anon/match_002302c0_ncfj.cpp)
namespace n002302c0 {
struct Vec {
    f32 x, y, z, w;
    Vec() {}
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
static inline void Vec_sub(Vec* r, const Vec* a, const Vec* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline Vec operator-(const Vec& a, const Vec& b) { Vec r; Vec_sub(&r, &a, &b); return r; }
struct Rot { f32 x, y, z; };
struct PathKey { u8 pad[0x24]; f32 dist; };
struct Path {
    u8 pad0[6];
    s16 count;
    s16 type;
    u8 pad1[2];
    f32 length;
    PathKey keys[1];
};
void func_0022fe08(Vec* out, f32 s, Path* p, s32 i) asm("func_0022fe08");
void func_00230260(Vec* a, Vec* b, Rot* rot) asm("func_00230260");
/*TARGET 002302c0*/
s32 func_002302c0(f32 t, Path* p, Vec* out, Rot* rot) asm("func_002302c0");
s32 func_002302c0(f32 t, Path* p, Vec* out, Rot* rot) {
    Vec p0, p1, d;
    f32 pos;
    f32 acc;
    f32 s;
    s32 i;
    PathKey* keys = p->keys;
    s16 cnt;
    rot->x = 0.0f;
    rot->y = 0.0f;
    rot->z = 0.0f;
    if (t < rot->x) t = rot->x;
    if (100.0f < t) t = 100.0f;
    pos = p->length * t / 100.0f;
    cnt = p->count;
    if (p->type == 1) {
        s32 n;
        PathKey* k;
        n = cnt - 1;
        
        for (i = 0; i < n; i++) {
            k = &keys[i];
            if (k->dist <= pos && pos < k[1].dist) {
                f32 l;
                acc = k->dist;
                func_0022fe08(&p0, 0.0f, p, i);
                if (pos == acc) {
                    *out = p0;
                    func_0022fe08(&p1, 0.025f, p, i);
                    func_00230260(&p0, &p1, rot);
                    return 1;
                }
                for (s = 0.025f; s <= 1.0f; s += 0.025f) {
                    func_0022fe08(&p1, s, p, i);
                    d = p1 - p0;
                    l = d.length();
                    if (pos < acc + l) {
                        s = pos - acc;
                        s /= l;
                        out->x = p0.x + (p1.x - p0.x) * s;
                        out->y = p0.y + (p1.y - p0.y) * s;
                        out->z = p0.z + (p1.z - p0.z) * s;
                        goto done0;
                    }
                    acc += l;
                    p0 = p1;
                }
            }
        }
        return 0;
    done0:
        func_00230260(&p0, &p1, rot);
        return 1;
    } else {
        s32 n;
        PathKey* k;
        n = cnt - 2;
        
        for (i = 1; i < n; i++) {
            k = &keys[i];
            if (k->dist <= pos && pos <= k[1].dist) {
                f32 l;
                acc = k->dist;
                func_0022fe08(&p0, 0.0f, p, i);
                if (pos == acc) {
                    *out = p0;
                    func_0022fe08(&p1, 0.025f, p, i);
                    func_00230260(&p0, &p1, rot);
                    return 1;
                }
                for (s = 0.025f; s < 1.0f; s += 0.025f) {
                    func_0022fe08(&p1, s, p, i);
                    d = p1 - p0;
                    l = d.length();
                    if (pos < acc + l) {
                        s = pos - acc;
                        s /= l;
                        out->x = p0.x + (p1.x - p0.x) * s;
                        out->y = p0.y + (p1.y - p0.y) * s;
                        out->z = p0.z + (p1.z - p0.z) * s;
                        goto done1;
                    }
                    acc += l;
                    p0 = p1;
                }
            }
        }
        return 0;
    done1:
        func_00230260(&p0, &p1, rot);
        return 1;
    }
}
}  // namespace n002302c0

// 002306a8 (was src/anon/batch_w3777_nsamam.cpp)
namespace n002306a8 {
struct Clip { u8 pad[8]; u16 n; u16 pad2; u8 data[1]; };
struct ClipRef { Clip* clip; s32 b; };
struct Obj { u8 pad[6]; u16 start; u16 end; };
struct Ent { Obj* o; ClipRef* r; s32 w; };
struct V4 { f32 x, y, z, w; };
struct S2 { f32 a, b; };
extern Ent* D_0035dcec asm("D_0035dcec");
extern s32 D_0035de20 asm("D_0035de20");
extern f32 D_0035de1c asm("D_0035de1c");
void YS__OBJ__is_valid(s32) asm("YS__OBJ__is_valid");
void func_0016ace0(s32, V4*) asm("func_0016ace0");
void func_0016aeb8(s32, f32) asm("func_0016aeb8");
s32 func_002302c0(f32, s32, V4*, S2*) asm("func_002302c0");
f32 func_00230f10(f32, void*, u32, s32) asm("func_00230f10");
/*TARGET 002306a8*/
void func_002306a8(void) asm("func_002306a8");
void func_002306a8(void) {
    s32 i;
    if (D_0035dcec != 0) {
        for (i = 0; i < 64; i++) {
            Obj* o = D_0035dcec[i].o;
            if (o != 0) {
                if (o->end < D_0035de20) {
                    D_0035dcec[i].o = 0;
                    D_0035dcec[i].r = 0;
                } else if (D_0035de20 >= o->start) {
                    V4 v; S2 s;
                    Clip* c = D_0035dcec[i].r->clip;
                    if (func_002302c0(func_00230f10(D_0035de1c * 0.5f - (f32)o->start, c->data, c->n, 0),
                                      D_0035dcec[i].r->b, &v, &s) == 1) {
                        s32 w;
                        v.w = 1.0f;
                        v.y = -v.y;
                        v.z = -v.z;
                        w = D_0035dcec[i].w;
                        YS__OBJ__is_valid(w);
                        func_0016ace0(w, &v);
                        func_0016aeb8(w, s.b);
                    }
                }
            }
        }
    }
}
}  // namespace n002306a8

// 00230838 (was src/anon/batch_wcx2.cpp)
namespace n00230838 {
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
// 0x002e0720: definition moved into src/anon/unit_002de3c8.cpp

// --------------------
struct E230838 { s32 a; s32 b; };
union U230838 { E230838* p; s32 i; };
extern U230838 D_0035dce8_x10906 asm("D_0035dce8");
/*TARGET 00230838*/
void func_00230838(s32 v) asm("func_00230838");
void func_00230838(s32 v) {
    s32 i;
    for (i = 0; i < 64; i++) {
        E230838* e = (E230838*)((i << 3) + (u32)D_0035dce8_x10906.p);
        if (e->a == 0) {
            e->a = v;
            return;
        }
    }
}
}  // namespace n00230838
#undef QCOPY

// 00230878 (was src/anon/batch_wcx2.cpp)
namespace n00230878 {
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
// --------------------
struct E230878 { u8* a; u8* b; };
union U230878 { E230878* p; s32 i; };
extern U230878 D_0035dce8_878 asm("D_0035dce8");
/*TARGET 00230878*/
void func_00230878(u8* q) asm("func_00230878");
void func_00230878(u8* q) {
    s32 i;
    s16 id = *(s16*)(q + 4);
    for (i = 0; i < 64; i++) {
        E230878* e = (E230878*)((i << 3) + (u32)D_0035dce8_878.p);
        if (e->a && *(s16*)(e->a + 4) == id) {
            e->b = q;
            return;
        }
    }
}
}  // namespace n00230878
#undef QCOPY

// 002308c8 (was src/anon/batch_w1815_nsa.cpp)
namespace n002308c8 {
// 0x001ebb30: definition moved into src/anon/unit_001e8ac8.cpp

struct A23 { u32 p0; s16 s4; u8 p6[4]; u16 u10; };
struct E23a { A23* a; void* b; s32 c; };
struct E23b { s32 f0; s32 f4; s32 f8; u8 pc[28]; };
struct T23 { u32 p0; s16 s4; };
struct E23c { T23* p; u32 x; };
extern E23a* D_0035dcec asm("D_0035dcec");
extern E23b* D_0035dcfc asm("D_0035dcfc");
extern E23c* D_0035dce8 asm("D_0035dce8");
/*TARGET 002308c8*/
void func_002308c8(A23* a) asm("func_002308c8");
void func_002308c8(A23* a) {
    for (s32 i = 0; i < 64; i++) {
        if (D_0035dcec[i].a == 0) {
            D_0035dcec[i].c = 0;
            for (s32 j = 0; j < 96; j++) {
                if (D_0035dcfc[j].f0 >= 0 && a->s4 == D_0035dcfc[j].f4) D_0035dcec[i].c = D_0035dcfc[j].f8;
            }
            for (s32 k = 0; k < 64; k++) {
                if (D_0035dce8[k].p && D_0035dce8[k].p->s4 == a->u10) {
                    D_0035dcec[i].a = a;
                    D_0035dcec[i].b = &D_0035dce8[k];
                    return;
                }
            }
        }
    }
}
}  // namespace n002308c8

// 002309c8 (was src/anon/batch_w97.cpp)
namespace n002309c8 {
// ---- 002309c8
union FP230 { f32* p; f32 f; };
struct Obj230 { u32 f0; u32 owner; FP230 x; FP230 y; FP230 z; };
s32 YS__OBJ__is_valid(u32) asm("YS__OBJ__is_valid");
// list_contains_ptr
s32 func_0014f0e0(f32*) asm("func_0014f0e0");
void func_0016ace0(u32, f32*) asm("func_0016ace0");
void func_00106420(f32*) asm("func_00106420");
void func_001024a8(Obj230*) asm("func_001024a8");
/*TARGET 002309c8*/
void sa__EVENT__objMoveTask(Obj230* o) asm("sa__EVENT__objMoveTask");
void sa__EVENT__objMoveTask(Obj230* o) {
    u32 owner = o->owner;
    if (!YS__OBJ__is_valid(owner)) return;
    f32 v[4];
    f32* px = o->x.p;
    v[3] = 1.0f;
    f32* pz = o->z.p;
    f32* py = o->y.p;
    s32 bx = func_0014f0e0(px);
    s32 by = func_0014f0e0(py);
    s32 bz = func_0014f0e0(pz);
    if (!bx && !by && !bz) {
        v[0] = *px;
        v[1] = *py;
        v[2] = *pz;
        func_0016ace0(owner, v);
        func_00106420(px);
        func_00106420(py);
        func_00106420(pz);
        o->x.p = 0;
        o->y.p = 0;
        o->z.p = 0;
        func_001024a8(o);
    } else {
        v[0] = *px;
        v[1] = *py;
        v[2] = *pz;
        func_0016ace0(owner, v);
    }
}
}  // namespace n002309c8

// 00230ae8 (was gap)
namespace n00230ae8 {
void func_00106420(void*) asm("func_00106420");
struct T4 { u8 pad[8]; void* a; void* b; void* c; };
void func_00230ae8(T4* t) asm("func_00230ae8");
void func_00230ae8(T4* t) {
    void* a = t->a;
    void* b = t->b;
    void* c = t->c;
    if (a) func_00106420(a);
    if (b) func_00106420(b);
    if (c) func_00106420(c);
}
}  // namespace n00230ae8

// 00230b50 (was src/anon/batch_w2024_nsa.cpp)
namespace n00230b50 {
struct W2024c_V4 { f32 x, y, z, w; W2024c_V4() {} W2024c_V4(const W2024c_V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
struct W2024c_Ent { u8 pad[8]; s32 h; };
struct W2024c_P3 { s32 a; s32 b; f32 c; };
struct W2024c_Tk { u8 pad[4]; s32 f4; W2024c_P3* p0; W2024c_P3* p1; W2024c_P3* p2; u8 pad2[0x1c]; void* f30; };
struct W2024c_Ev { u8 pad[4]; s16 id; u16 key; u8 v0[0x24]; u16 n; };
f32 W2024c_ev_get_float(void*) asm("_ZN2sa5EVENT9get_floatEPv");
W2024c_Ent* W2024c_ev_entry_work_get(s32) asm("_ZN2sa5EVENT14entry_work_getEi");
W2024c_Tk* W2024c_field_create_task(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void* W2024c_area_get_alloc(void) asm("_ZN4AREA12GetAllocatorEv");
W2024c_P3* W2024c_tz_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
s32 sa__EVENT__checkStart(u16) asm("sa__EVENT__checkStart");
s32 sa__EVENT__isJumpMode(u16) asm("sa__EVENT__isJumpMode");
void YS__OBJ__is_valid(s32) asm("YS__OBJ__is_valid");
void func_0016adc8(s32, W2024c_V4) asm("func_0016adc8");
void func_0022f6b8(s32, W2024c_V4*) asm("func_0022f6b8");
s32 sa__EVENT__getEventPriority(void) asm("sa__EVENT__getEventPriority");
void sa__EVENT__objMoveTask(void*) asm("sa__EVENT__objMoveTask");
void func_00230ae8(void*) asm("func_00230ae8");
void func_0014f030(W2024c_P3*, f32, f32, f32) asm("func_0014f030");
/*TARGET 00230b50*/
void func_00230b50(W2024c_Ev* e) asm("func_00230b50");
void func_00230b50(W2024c_Ev* e) {
    W2024c_V4 a, c, b;
    W2024c_Ent* en;
    W2024c_Tk* t;
    void* al;
    W2024c_P3* p0;
    W2024c_P3* p1;
    W2024c_P3* p2;
    f32 one;
    if (sa__EVENT__checkStart(e->key) != 0) return;
    if (sa__EVENT__isJumpMode(e->key) != 0) return;
    one = 1.0f;
    en = W2024c_ev_entry_work_get(e->id);
    YS__OBJ__is_valid(en->h);
    a.x = W2024c_ev_get_float(e->v0 + 0);
    a.y = W2024c_ev_get_float(e->v0 + 4);
    a.z = W2024c_ev_get_float(e->v0 + 8);
    a.w = one;
    func_0016adc8(en->h, a);
    b.x = W2024c_ev_get_float(e->v0 + 0x18);
    b.y = W2024c_ev_get_float(e->v0 + 0x1c);
    b.z = W2024c_ev_get_float(e->v0 + 0x20);
    b.w = one;
    func_0022f6b8(en->h, &b);
    c.x = W2024c_ev_get_float(e->v0 + 0xc);
    c.y = W2024c_ev_get_float(e->v0 + 0x10);
    c.z = W2024c_ev_get_float(e->v0 + 0x14);
    c.w = one;
    t = W2024c_field_create_task(1, sa__EVENT__getEventPriority(), sa__EVENT__objMoveTask);
    t->f30 = (void*)func_00230ae8;
    t->f4 = en->h;
    al = W2024c_area_get_alloc();
    p0 = W2024c_tz_alloc(12, al);
    p0->a = 0; p0->b = 0; p0->c = one;
    p1 = W2024c_tz_alloc(12, al);
    p1->a = 0; p1->b = 0; p1->c = one;
    p2 = W2024c_tz_alloc(12, al);
    p2->a = 0; p2->b = 0; p2->c = one;
    t->p0 = p0;
    t->p1 = p1;
    t->p2 = p2;
    func_0014f030(p0, a.x, c.x, (f32)e->n * 2.0f);
    func_0014f030(p1, a.y, c.y, (f32)e->n * 2.0f);
    func_0014f030(p2, a.z, c.z, (f32)e->n * 2.0f);
}
}  // namespace n00230b50

// 00230d68 (was gap)
namespace n00230d68 {
void func_00230d68(void) asm("func_00230d68");
void func_00230d68(void) {}
}  // namespace n00230d68

// 00230d70 (was gap)
namespace n00230d70 {
void func_00230d70(void) asm("func_00230d70");
void func_00230d70(void) {}
}  // namespace n00230d70

// 00230d78 (was src/anon/batch_w47.cpp)
namespace n00230d78 {
// Stores s into the first free (id == -1) of 128 table entries. Unions with a
// char member reproduce the original's reloads (built without strict aliasing).
union GU230 { u32 v; u8 c; };
union SH230 { s16 s; u16 h; u8 c; };
struct S230 { u8 pad[4]; SH230 id; SH230 a; SH230 b; };
struct E230 { s32 id; u16 a; u16 b; };
extern GU230 D_0035dce4 asm("D_0035dce4");
/*TARGET 00230d78*/
void func_00230d78(S230* s) asm("func_00230d78");
void func_00230d78(S230* s) {
    for (s32 i = 0; i < 128; i++) {
        E230* e = (E230*)(i * 8 + D_0035dce4.v);
        if (e->id == -1) {
            e->id = s->id.s;
            ((E230*)(i * 8 + D_0035dce4.v))->a = s->a.h;
            ((E230*)(i * 8 + D_0035dce4.v))->b = s->b.h;
            return;
        }
    }
}
}  // namespace n00230d78

// 00230de0 (was src/anon/batch_w262.cpp)
namespace n00230de0 {
struct W262Key { s32 t : 29; u32 type : 3; f32 v; f32 m1; f32 m0; };
/*TARGET 00230de0*/
f32 func_00230de0(s32 i, W262Key* keys, W262Key* out, f32 t) asm("func_00230de0");
f32 func_00230de0(s32 i, W262Key* keys, W262Key* out, f32 t) {
    W262Key* k = (W262Key*)((u32)(i << 4) + (u32)keys);
    W262Key* n;
    f32 p0 = k->v;
    f32 m0 = k->m0;
    f32 t0 = (f32)k->t * 0.001953125f;
    f32 t1, p1, m1;
    f32 r;
    if (out) out->m0 = m0;
    n = k + 1;
    p1 = n->v;
    m1 = n->m1;
    t1 = (f32)n->t * 0.001953125f;
    switch (k->type) {
    case 0:
        r = p0;
        break;
    case 1:
        r = p0 + (p1 - p0) * (t - t0) / (t1 - t0);
        break;
    case 2: case 3: case 4: {
        f32 inv = 1.0f / (t1 - t0);
        f32 s = t - t0;
        f32 s2 = s * s;
        f32 inv2 = inv * inv;
        f32 a = s2 * s * inv2;
        f32 b = s2 * 3.0f * inv2;
        f32 c = s2 * inv;
        f32 a2 = (a + a) * inv;
        r = p0 * (a2 - b + 1.0f) + p1 * (b - a2) + m0 * (a - (c + c) + s) + m1 * (a - c);
        break;
    }
    default:
        r = 0.0f;
        break;
    }
    return r;
}
}  // namespace n00230de0

// 00230f10 (was src/anon/batch_w1694.cpp)
namespace n00230f10 {
struct W1694Key {
    s32 time : 29;
    u32 type : 3;
    f32 value;
    f32 slopeIn;
    f32 slopeOut;
};
s32 func_00232328(void) asm("func_00232328");
f32 func_00230de0(f32, s32, W1694Key*, s32) asm("func_00230de0");
/*TARGET 00230f10*/
f32 func_00230f10(f32 time, W1694Key* keys, s32 n, s32 arg) asm("func_00230f10");
f32 func_00230f10(f32 time, W1694Key* keys, s32 n, s32 arg) {
    f32 result = 0.0f;
    f32 t = time / 30.0f;
    s32 pre = 1;
    s32 post = 1;
    if (n > 0) {
        if (n == 1) {
            result = keys[0].value;
        } else {
            s32 frame;
            if (func_00232328() != 0) {
                frame = (s32)(t * 512.0f + 0.5f);
            } else {
                frame = (s32)(t * 512.0f);
            }
            if (frame <= keys[0].time) {
                if (pre == 1) {
                    f32 d = (f32)(keys[1].time - keys[0].time);
                    f32 slope;
                    if (keys[0].type == 1 && d != 0.0f) slope = (keys[1].value - keys[0].value) / d;
                    else slope = keys[0].slopeIn;
                    result = keys[0].value - (f32)(keys[0].time - frame) * slope;
                } else {
                    result = 0.0f;
                }
            } else if (frame >= keys[n - 1].time) {
                if (post == 1) {
                    f32 d = (f32)(keys[n - 1].time - keys[n - 2].time);
                    f32 slope;
                    if (keys[n - 1].type == 1 && d != 0.0f) slope = (keys[n - 1].value - keys[n - 2].value) / d;
                    else slope = keys[n - 1].slopeOut;
                    result = keys[n - 1].value + (f32)(frame - keys[n - 1].time) * slope;
                } else {
                    result = 0.0f;
                }
            } else {
                s32 lo = 0;
                s32 hi = n - 1;
                while (hi - lo >= 2) {
                    s32 mid = (lo + hi) / 2;
                    if (frame < keys[mid].time) {
                        hi = mid;
                    } else if (frame > keys[mid].time) {
                        lo = mid;
                    } else {
                        result = keys[mid].value;
                        goto end;
                    }
                }
                return func_00230de0(t, hi - 1, keys, arg);
            }
        }
    }
end:
    return result;
}
}  // namespace n00230f10

// 002311c0 (was src/anon/batch_w292.cpp)
namespace n002311c0 {
// 0x0025caf0: definition moved into src/anon/unit_002588e8.cpp

struct K231 { u8 b[16]; };
struct H231 { u8 pad[6]; struct { u16 start, count; } ch[8]; u8 pad2[40 - 38]; K231 keys[1]; };
extern u8 D_0035de90[8][32] asm("D_0035de90");
f32 func_00230f10(K231*, s32, void*, f32) asm("func_00230f10");
/*TARGET 002311c0*/
void sa__EVENT__calcValue_enc(f32* out, H231* h, f32 t) asm("sa__EVENT__calcValue_enc");
void sa__EVENT__calcValue_enc(f32* out, H231* h, f32 t)
{
    if (h->ch[0].count) out[0] = func_00230f10(&h->keys[h->ch[0].start], h->ch[0].count, D_0035de90[0], t);
    if (h->ch[1].count) out[1] = -func_00230f10(&h->keys[h->ch[1].start], h->ch[1].count, D_0035de90[1], t);
    if (h->ch[2].count) out[2] = -func_00230f10(&h->keys[h->ch[2].start], h->ch[2].count, D_0035de90[2], t);
    if (h->ch[3].count) out[3] = func_00230f10(&h->keys[h->ch[3].start], h->ch[3].count, D_0035de90[3], t);
    if (h->ch[4].count) out[4] = -func_00230f10(&h->keys[h->ch[4].start], h->ch[4].count, D_0035de90[4], t);
    if (h->ch[5].count) out[5] = -func_00230f10(&h->keys[h->ch[5].start], h->ch[5].count, D_0035de90[5], t);
    if (h->ch[6].count) out[6] = func_00230f10(&h->keys[h->ch[6].start], h->ch[6].count, D_0035de90[6], t) * 3.14159274f / 180.0f;
    if (h->ch[7].count) out[7] = func_00230f10(&h->keys[h->ch[7].start], h->ch[7].count, D_0035de90[7], t);
}
}  // namespace n002311c0

// 00231390 (was src/anon/batch_w92.cpp)
namespace n00231390 {
f32 func_00230f10(u8*, s32, s32, f32) asm("func_00230f10");
/*TARGET 00231390*/
void func_00231390(f32* out, u8* c, f32 t) asm("func_00231390");
void func_00231390(f32* out, u8* c, f32 t) {
    out[0] = func_00230f10(c, 2, 0, t);
    out[1] = -func_00230f10(c + 32, 2, 0, t);
    out[2] = -func_00230f10(c + 64, 2, 0, t);
    out[3] = func_00230f10(c + 96, 2, 0, t);
    out[4] = -func_00230f10(c + 128, 2, 0, t);
    out[5] = -func_00230f10(c + 160, 2, 0, t);
    out[6] = func_00230f10(c + 192, 2, 0, t) * 3.14159274f / 180.0f;
    out[7] = func_00230f10(c + 224, 2, 0, t);
}
}  // namespace n00231390

// 002314c0 (was src/anon/batch_w11.cpp)
namespace n002314c0 {
struct V2 { f32 a[4]; f32 b[4]; };
extern V2 D_0035db20 asm("D_0035db20");
/*TARGET 002314c0*/
void func_002314c0(f32* s) asm("func_002314c0");
void func_002314c0(f32* s) {
    D_0035db20.a[0] = s[0];
    D_0035db20.a[1] = s[1];
    D_0035db20.a[2] = s[2];
    D_0035db20.b[0] = s[3];
    D_0035db20.b[1] = s[4];
    D_0035db20.b[2] = s[5];
}
}  // namespace n002314c0

