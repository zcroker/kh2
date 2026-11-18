#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 001c38c0 from src/anon/batch_w66.cpp
namespace n001c38c0 {
extern f32 D_00349e10 asm("D_00349e10");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
void func_001c38c0(u32, u8* p) asm("func_001c38c0");
void func_001c38c0(u32, u8* p) {
    if (0.0f < *(f32*)(p + 244)) {
        if (*(u32*)(p + 268) & 4) *(f32*)(p + 244) -= D_00349e10;
        else *(f32*)(p + 244) = 0.0f;
        if (*(f32*)(p + 244) <= 0.0f) {
            *(f32*)(p + 240) = *(f32*)(p + 248);
            func_0017f488(p + 320, 204, 0.0f, 0.0f);
            func_0017f5e0(p + 320, 4, 0, 8.0f, 0.0f);
        }
    }
}
}  // namespace n001c38c0

// ---- 001c3978 gap (vector damping, same family as 001c3b20)
namespace n001c3978 {
#define W3978_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V3978 {
    f32 x, y, z, w;
    V3978() {}
    V3978(const V3978& o) { W3978_QCOPY(this, &o); }
    V3978& operator=(const V3978& o) { if (this != &o) W3978_QCOPY(this, &o); return *this; }
    V3978 operator*(f32 k) const {
        V3978 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct O3978 { u8 pad[0x20]; V3978 v20; u8 p30[240 - 0x30]; f32 f240; };
extern f32 D_00349e10 asm("D_00349e10");
V3978 func_001c3978(void* a, O3978* o) asm("func_001c3978");
V3978 func_001c3978(void* a, O3978* o) {
    o->v20 = o->v20 * o->f240;
    return o->v20 * D_00349e10;
}
}  // namespace n001c3978

// ---- 001c39d0 from src/anon/batch_w80.cpp
namespace n001c39d0 {
struct HasF4 { u32 f0; f32 f4; };
struct U4_VO;
struct U4_VOVt { void* f0; void* f4; void* f8; void (*f12)(U4_VO*, void*, f32); };
struct U4_VO { U4_VOVt* vt; };
struct U4_Lim { u8 pad[56]; f32 f56; };
struct U4_Mover { u8 pad[12]; U4_VO* f12; u8 pad2[240 - 16]; U4_Lim* f240; u8 pad3[268 - 244]; u32 f268; u8 pad4[320 - 272]; u8 f320[4]; };
#define U4_W80_MAX(a, b) ((a) > (b) ? (a) : (b))
HasF4* func_0016c028(void*) asm("func_0016c028");
f32 func_00184a90(U4_Mover*) asm("func_00184a90");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void func_001c39d0(void* self, U4_Mover* m) asm("func_001c39d0");
void func_001c39d0(void* self, U4_Mover* m) {
    if (m->f268 & 4) {
        f32 d = U4_W80_MAX(func_00184a90(m) - func_0016c028(m)->f4, 0.0f);
        if (!(d < m->f240->f56)) return;
    }
    func_0017f488(m->f320, 4, 16.0f, 0.0f);
    m->f12->vt->f12(m->f12, m, 0.0f);
}
}  // namespace n001c39d0

// ---- 001c3aa0 from src/anon/batch_w53.cpp
namespace n001c3aa0 {
void func_0016bd60(u8*, u32) asm("func_0016bd60");
void func_0017f540(u8*, u32, f32, f32) asm("func_0017f540");
void func_001c39d0(u8*, u8*) asm("func_001c39d0");
void func_001c3aa0(u8* a, u8* b) asm("func_001c3aa0");
void func_001c3aa0(u8* a, u8* b) {
    if (0.0f < *(f32*)(b + 28)) {
        func_0016bd60(b, 18);
        return;
    }
    func_0017f540(b + 320, 208, 16.0f, 0.0f);
    func_001c39d0(a, b);
}
}  // namespace n001c3aa0

// ---- 001c3b20 from src/anon/batch_w1767.cpp
namespace n001c3b20 {
#define W1767_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1767Vec {
    f32 x, y, z, w;
    W1767Vec() {}
    W1767Vec(const W1767Vec& o) { W1767_QCOPY(this, &o); }
    W1767Vec& operator=(const W1767Vec& o) { if (this != &o) W1767_QCOPY(this, &o); return *this; }
    W1767Vec operator*(f32 k) const {
        W1767Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    W1767Vec& operator*=(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1767Obj { u8 pad[0x20]; W1767Vec v20; };
extern f32 D_00349e10 asm("D_00349e10");
f32 func_001c3ba8(void*, W1767Obj*) asm("func_001c3ba8");
W1767Vec func_001c3b20(void* a, W1767Obj* o) asm("func_001c3b20");
W1767Vec func_001c3b20(void* a, W1767Obj* o) {
    o->v20 *= 0.9f;
    W1767Vec t;
    t = o->v20;
    t.y = func_001c3ba8(a, o);
    return t * D_00349e10;
}
}  // namespace n001c3b20

// ---- 001c3ba8 from src/anon/batch_w90.cpp
namespace n001c3ba8 {
f32 func_00184a90(void*) asm("func_00184a90");
f32* func_0016c028(void*) asm("func_0016c028");
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define HEIGHT(o) (func_00184a90(o) - func_0016c028(o)[1])
struct RangeParam { u8 pad[36]; f32 k; f32 off; f32 max; };
struct RangeObj { u8 pad[240]; RangeParam* p; };
static inline f32 Above(RangeObj* o) { f32 t = MAX(HEIGHT(o), 0.0f); return t - o->p->off; }
f32 func_001c3ba8(u32 unused, RangeObj* o) asm("func_001c3ba8");
f32 func_001c3ba8(u32 unused, RangeObj* o)
{
    f32 x = MAX(Above(o), 0.0f);
    return MIN(x * o->p->k, o->p->max);
}
}  // namespace n001c3ba8

// ---- 001c3ca8 from src/anon/tiny_auto80_queue.cpp
namespace n001c3ca8 {
void func_0017c578(...) asm("func_0017c578");
void func_001c3ca8(void* a0, u8* a1) asm("_Z13func_001c3ca8PvPh");
void func_001c3ca8(void* a0, u8* a1) {
    u8* s0 = a1;
    func_0017c578(a0);
    u8* t7 = *(u8**)(s0 + 240);
    *(f32*)(s0 + 284) = *(f32*)(t7 + 60);
}
}  // namespace n001c3ca8

// ---- 001c3cd8 from src/anon/batch_w5.cpp
namespace n001c3cd8 {
void func_0017c660(u8*, u8*) asm("func_0017c660");
void func_001c3cd8(u8* a, u8* b) asm("func_001c3cd8");
void func_001c3cd8(u8* a, u8* b) {
    *(f32*)(b + 0x11c) = *(f32*)(*(u8**)(b + 0x12c) + 12);
    func_0017c660(a, b);
}
}  // namespace n001c3cd8

// ---- 001c3cf8 from src/anon/batch_w1830.cpp
namespace n001c3cf8 {
struct W1830QW {
    f32 x, y, z, w;
    W1830QW() {}
    W1830QW(const W1830QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1830QW& operator=(const W1830QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 w1830_vdot(const W1830QW* a, const W1830QW* b) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}
static inline W1830QW w1830_vcross(const W1830QW& a, const W1830QW& b) {
    W1830QW r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct W1830Obj1 { u8 p0[0x10]; W1830QW dir; u8 p20[0x140 - 0x20]; u8 snd[4]; };
W1830QW func_0016af58(void*) asm("func_0016af58");
void func_0017f540(f32, f32, void*, s32) asm("func_0017f540");
void func_001c39d0(s32, W1830Obj1*) asm("func_001c39d0");
void func_001c3cf8(s32 a0, W1830Obj1* o) asm("func_001c3cf8");
void func_001c3cf8(s32 a0, W1830Obj1* o) {
    W1830QW c;
    s32 id = 0xcd;
    if (o->dir.w > 0.0f) {
        W1830QW t = func_0016af58(o);
        if (w1830_vdot(&t, &o->dir) < 0.98f) {
            c = w1830_vcross(func_0016af58(o), o->dir);
            if (c.y > 0.0f) id = 0xce; else id = 0xcf;
        }
    }
    func_0017f540(16.0f, 0.0f, o->snd, id);
    func_001c39d0(a0, o);
}
}  // namespace n001c3cf8

// ---- 001c3e20 from src/anon/batch_w1830.cpp
namespace n001c3e20 {
struct W1830QW {
    f32 x, y, z, w;
    W1830QW() {}
    W1830QW(const W1830QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1830QW& operator=(const W1830QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 w1830_vlen(const W1830QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline W1830QW w1830_vscale(const W1830QW& a, f32 k) {
    W1830QW r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
struct W1830Prm { u8 p0[0x20]; f32 f20; u8 p24[0xc]; f32 f30; };
struct W1830Obj2 { u8 p0[0x20]; W1830QW v20; u8 p30[0xf0 - 0x30]; W1830Prm* prm; };
extern f32 D_00349e10 asm("D_00349e10");
W1830QW func_0016af58(void*) asm("func_0016af58");
f32 func_001c3ba8(void*, W1830Obj2*) asm("func_001c3ba8");
W1830QW func_001c3e20(void* a1, W1830Obj2* o) asm("func_001c3e20");
W1830QW func_001c3e20(void* a1, W1830Obj2* o) {
    f32 k = o->prm->f30;
    f32 len = w1830_vlen(&o->v20);
    W1830QW c;
    c = w1830_vscale(func_0016af58(o), o->prm->f20 * (1.0f - k) + len * k);
    o->v20 = c;
    c.y = func_001c3ba8(a1, o);
    return w1830_vscale(c, D_00349e10);
}
}  // namespace n001c3e20

// ---- 001c3f48 from src/anon/tiny.cpp
namespace n001c3f48 {
void func_001c3f48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c3f48jjjj");
void func_001c3f48(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-27288)) = (u32)a0;
}
}  // namespace n001c3f48

// ---- 001c3f58 (was whole asm, src/anon/asm_001c3f58.s): find the table entry with this id and the
// current kind, fill the static result record D_01d49570 from it and return the record.
// Two returns (one inside the loop, one after it) are what make the epilogue load the address as one `la`.
namespace n001c3f58 {
struct Ent { u8 id; u8 kind; u8 c; u8 d; };
struct Tbl { u32 pad; s32 count; Ent e[1]; };
struct S3 { u16 x, y, z; };
struct R { u8 a, b, c, pad; S3 s; };
struct Q { u8 x; u8 kind; };
extern Tbl* D_01d49568 asm("D_01d49568");
extern R D_01d49570 asm("D_01d49570");
Q* func_001b6d70(s32) asm("func_001b6d70");
R func_00199718(u8 c, s32 id) asm("func_00199718");
static inline void init3(S3* s, u32 a, u32 m) { s->x = a; s->y = m; s->z = m; }
R* func_001c3f58(s32 id) asm("func_001c3f58");
R* func_001c3f58(s32 id) {
    Q* q = func_001b6d70(id);
    Ent* e = D_01d49568->e;
    for (s32 i = 0; i < D_01d49568->count; i++, e++) {
        if (e->id == id && e->kind == q->kind) {
            u8 c = e->c;
            if (c < 51) {
                u8 d = e->d;
                D_01d49570.a = id;
                D_01d49570.b = c;
                D_01d49570.c = d;
                init3(&D_01d49570.s, 0xffff, 0xffff);
            } else {
                D_01d49570 = func_00199718(c, id);
            }
            return &D_01d49570;
        }
    }
    return &D_01d49570;
}
}  // namespace n001c3f58
