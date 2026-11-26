// Linked unit 0x00144450-0x001451e0 (one namespace per old matched source; class methods in their own namespace).
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

// 00144450 (was src/harata/libdk/aabbox.cpp + small old files: dk::Aabbox)
namespace n00144450 {
struct Box { f32 v[6]; };
void Aabbox_init(Box* b) asm("_ZN2dk6Aabbox4initEv");
void Aabbox_init(Box* b) {
    f32 z = 0.0f;
    *(volatile f32*)&b->v[0] = z;
    *(volatile f32*)&b->v[5] = z;
    *(volatile f32*)&b->v[4] = z;
    *(volatile f32*)&b->v[3] = z;
    *(volatile f32*)&b->v[2] = z;
    *(volatile f32*)&b->v[1] = z;
}

// Aabbox(f32 x6): C2 (0x144470, never written) and C1
void Aabbox_C2_f6(Box* b, f32 a, f32 c, f32 d, f32 e, f32 f, f32 g) asm("_ZN2dk6AabboxC2Effffff");
void Aabbox_C2_f6(Box* b, f32 a, f32 c, f32 d, f32 e, f32 f, f32 g) {
    b->v[0] = a; b->v[1] = c; b->v[2] = d; b->v[3] = e; b->v[4] = f; b->v[5] = g;
}
void Aabbox_C1_f6(Box* b, f32 a, f32 c, f32 d, f32 e, f32 f, f32 g) asm("_ZN2dk6AabboxC1Effffff");
void Aabbox_C1_f6(Box* b, f32 a, f32 c, f32 d, f32 e, f32 f, f32 g) {
    b->v[0] = a; b->v[1] = c; b->v[2] = d; b->v[3] = e; b->v[4] = f; b->v[5] = g;
}

void Aabbox_set_vv(Box* b, const f32* a, const f32* c) asm("_ZN2dk6Aabbox3setERKN2kn7FVectorES4_");
void Aabbox_set_sphere(Box* b, const u8* s) asm("func_00144860");
void Aabbox_set_x(Box* b, const void* a, const void* c, const void* d) asm("_Z16wtarget_00144630jjjj");

// Aabbox(FVector const&, FVector const&): C2, C1
void Aabbox_C2_vv(Box* b, const f32* a, const f32* c) asm("func_001444b0");
void Aabbox_C2_vv(Box* b, const f32* a, const f32* c) { Aabbox_set_vv(b, a, c); }
void Aabbox_C1_vv(Box* b, const f32* a, const f32* c) asm("_ZN2dk6AabboxC1ERKN2kn7FVectorES4_");
void Aabbox_C1_vv(Box* b, const f32* a, const f32* c) { Aabbox_set_vv(b, a, c); }

// Aabbox(Sphere const&) forwarding to set: C2 (0x1444e0, never written), C1
void Aabbox_C2_s(Box* b, const u8* s) asm("func_001444e0");
void Aabbox_C2_s(Box* b, const u8* s) { Aabbox_set_sphere(b, s); }
void Aabbox_C1_s(Box* b, const u8* s) asm("func_001444f8");
void Aabbox_C1_s(Box* b, const u8* s) { Aabbox_set_sphere(b, s); }

// Box around a sphere (center xyz, radius at +16): C2 (0x144510, never written), C1
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void sphere_box(f32* box, const u8* s) {
    Vec4 v;
    if ((void*)&v != s) cpq(&v, s);
    f32 r = *(f32*)(s + 16);
    box[0] = v.x - r;
    box[1] = v.y - r;
    box[2] = v.z - r;
    box[3] = v.x + r;
    box[4] = v.y + r;
    box[5] = v.z + r;
}
void Aabbox_C2_sb(f32* box, const u8* s) asm("func_00144510");
void Aabbox_C2_sb(f32* box, const u8* s) { sphere_box(box, s); }
void Aabbox_C1_sb(f32* box, const u8* s) asm("func_00144570");
void Aabbox_C1_sb(f32* box, const u8* s) { sphere_box(box, s); }

// C2/C1 forwarding to 0x144630
void Aabbox_C2_x(Box* b, const void* a, const void* c, const void* d) asm("func_001445d0");
void Aabbox_C2_x(Box* b, const void* a, const void* c, const void* d) { Aabbox_set_x(b, a, c, d); }
void Aabbox_C1_x(Box* b, const void* a, const void* c, const void* d) asm("func_001445e8");
void Aabbox_C1_x(Box* b, const void* a, const void* c, const void* d) { Aabbox_set_x(b, a, c, d); }

// Aabbox(Line const&): C2 (0x144600, never written), C1
void Aabbox_C2_l(Box* b, const u8* l) asm("func_00144600");
void Aabbox_C2_l(Box* b, const u8* l) { Aabbox_set_vv(b, (const f32*)l, (const f32*)(l + 16)); }
void Aabbox_C1_l(Box* b, const u8* l) asm("_ZN2dk6AabboxC1ERKNS_4LineE");
void Aabbox_C1_l(Box* b, const u8* l) { Aabbox_set_vv(b, (const f32*)l, (const f32*)(l + 16)); }
}  // namespace n00144450

// 00144630 (was src/anon/batch_w1946.cpp)
namespace n00144630 {
struct BBSrc { union { f32* v[4]; u8 c; }; s32 n; };
void wtarget_00144630(f32* out, BBSrc* s) asm("_Z16wtarget_00144630jjjj");
#define AI(p) (*(f32*)((u32)(p) + (i << 2)))
#define AT(p) (*(f32*)((u8*)(p) + o))
#define UPDK(j) \
    if (AT(s->v[j]) < mn[k]) mn[k] = AT(s->v[j]); \
    else if (mx[k] < AT(s->v[j])) mx[k] = AT(s->v[j]);
#define UPDI(j) \
    if (AT(s->v[j]) < AI(mn)) AI(mn) = AT(s->v[j]); \
    else if (AI(mx) < AT(s->v[j])) AI(mx) = AT(s->v[j]);
/*TARGET 00144630*/
void wtarget_00144630(f32* out, BBSrc* s) asm("_Z16wtarget_00144630jjjj");
void wtarget_00144630(f32* out, BBSrc* s) {
    s32 i, k;
    if (s->n == 3) {
        f32* mn;
        f32* mx;
        i = 0;
        mn = out;
        mx = out + 3;
        for (; i < 3; i++) {
            s32 o = i * 4;
            AI(mn) = AI(mx) = AT(s->v[0]);
            UPDI(1)
            UPDI(2)
        }
    } else {
        f32* mn = out;
        f32* mx = out + 3;
        for (k = 0; k < 3; k++) {
            s32 o = k * 4;
            mn[k] = mx[k] = AT(s->v[0]);
            UPDK(1)
            UPDK(2)
            UPDK(3)
        }
    }
}
}  // namespace n00144630

// 001447c0 (was src/harata/libdk/aabbox.cpp)
namespace n001447c0 {
struct Box { f32 v[6]; };
void Aabbox_set_f6(Box* b, f32 a, f32 c, f32 d, f32 e, f32 f, f32 g) asm("_ZN2dk6Aabbox3setEffffff");
void Aabbox_set_f6(Box* b, f32 a, f32 c, f32 d, f32 e, f32 f, f32 g) {
    b->v[0] = a; b->v[1] = c; b->v[2] = d; b->v[3] = e; b->v[4] = f; b->v[5] = g;
}
}  // namespace n001447c0

// 001447e0 (was src/harata/libdk/aabbox.cpp)
namespace n001447e0 {
struct V3 { f32 x, y, z; };
struct Box { f32 v0, v1, v2, v3, v4, v5; };
void Aabbox_set_vv(Box* l, const V3* va, const V3* vb) asm("_ZN2dk6Aabbox3setERKN2kn7FVectorES4_");
void Aabbox_set_vv(Box* l, const V3* va, const V3* vb) {
    if (va->x < vb->x) {
        l->v0 = va->x;
        l->v3 = vb->x;
    } else {
        l->v0 = vb->x;
        l->v3 = va->x;
    }
    if (va->y < vb->y) {
        l->v1 = va->y;
        l->v4 = vb->y;
    } else {
        l->v1 = vb->y;
        l->v4 = va->y;
    }
    if (va->z < vb->z) {
        l->v2 = va->z;
        l->v5 = vb->z;
    } else {
        l->v2 = vb->z;
        l->v5 = va->z;
    }
}
}  // namespace n001447e0

// 00144860 (was src/anon/batch_w1782.cpp)
namespace n00144860 {
// batch w1782

struct Box144860 { f32 mn[3]; f32 mx[3]; };
struct V11a858 {
    f32 x, y, z, w;
} __attribute__((aligned(16)));
static inline V11a858 operator+(const V11a858& a, const V11a858& b) {
    V11a858 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// Merge two boxes: componentwise min of the first corner, max of the second.
void func_00144860(Box144860* __restrict o, Box144860* a, Box144860* b) asm("_Z13func_00144860Pv");
/*TARGET 00144860*/
void func_00144860(Box144860* __restrict o, Box144860* a, Box144860* b) asm("_Z13func_00144860Pv");
void func_00144860(Box144860* __restrict o, Box144860* a, Box144860* b) {
    o->mn[0] = a->mn[0] < b->mn[0] ? a->mn[0] : b->mn[0];
    o->mn[1] = a->mn[1] < b->mn[1] ? a->mn[1] : b->mn[1];
    o->mn[2] = a->mn[2] < b->mn[2] ? a->mn[2] : b->mn[2];
    o->mx[0] = b->mx[0] < a->mx[0] ? a->mx[0] : b->mx[0];
    o->mx[1] = b->mx[1] < a->mx[1] ? a->mx[1] : b->mx[1];
    o->mx[2] = b->mx[2] < a->mx[2] ? a->mx[2] : b->mx[2];
}
}  // namespace n00144860

// 00144908 (was src/anon/batch_wcx.cpp)
namespace n00144908 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
/*TARGET 00144908*/
void func_00144908(f32* b, V4* out) asm("func_00144908");
void func_00144908(f32* b, V4* out)
{
    V4 d;
    d.w = 1.0f;
    d.x = b[3] - b[0];
    d.y = b[4] - b[1];
    d.z = b[5] - b[2];
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(&d), "f"(0.5f) : "$8", "memory");
    out->x = b[0] + d.x;
    out->y = b[1] + d.y;
    out->z = b[2] + d.z;
    out->w = 1.0f;
}
}  // namespace n00144908

// 001449a8 (was src/anon/batch_w3719.cpp)
namespace n001449a8 {
struct QV {
    f32 x, y, z, w;
    QV() {}
    ~QV() {}
    QV(const QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) { if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct QM {
    QV r[4];
    QV operator*(const QV& v) const {
        QV o;
        register QV* po asm("$11") = &o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(po), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
void func_00144b38(void*, QV*) asm("func_00144b38");
void func_001447e0(void*, QV*) asm("func_001447e0");
/*TARGET 001449a8*/
void dk__Aabbox__mulMatrix(void* a, QM* m) asm("dk__Aabbox__mulMatrix");
void dk__Aabbox__mulMatrix(void* a, QM* m) {
    QV mn, mx, cur;
    register s32 e1 asm("$11");
    {
    QV c[8];
    s32 i;
    register s32 d1 asm("$9"); register s32 d2 asm("$10"); register s32 d3 asm("$7");
    func_00144b38(a, c);
    asm("" : "=r"(d1), "=r"(d2), "=r"(d3));
    for (i = 0; i < 8; i++) {
        c[i] = *m * c[i];
        cur = c[i];
        QV* px = &mx;
        if (i == 0) {
            mn = *px = cur;
        } else {
            if (cur.x < mn.x) mn.x = cur.x; else if (mx.x < cur.x) mx.x = cur.x;
            if (cur.y < mn.y) mn.y = cur.y; else if (mx.y < cur.y) mx.y = cur.y;
            if (cur.z < mn.z) mn.z = cur.z; else if (mx.z < cur.z) mx.z = cur.z;
        }
    }
    asm("" : : "r"(d1), "r"(d2), "r"(d3));
    func_001447e0(a, &mn);
    asm("" : "=r"(e1));
    }
    asm("" : : "r"(e1));
}
}  // namespace n001449a8

// 00144b38 (was src/anon/batch_wcx.cpp)
namespace n00144b38 {
/*TARGET 00144b38*/
// 0x00142848: definition moved into src/anon/unit_00141458.cpp
void func_00144b38(f32* b, f32* v) asm("func_00144b38");
// 0x00142848: definition moved into src/anon/unit_00141458.cpp
void func_00144b38(f32* b, f32* v)
{
    f32 x0 = b[0], y0 = b[1], z0 = b[2], x1 = b[3], y1 = b[4], z1 = b[5];
    v[0] = x0; v[1] = y0; v[2] = z0; v[3] = 1.0f;
    v[4] = x0; v[5] = y1; v[6] = z0; v[7] = 1.0f;
    v[8] = x1; v[9] = y1; v[10] = z0; v[11] = 1.0f;
    v[12] = x1; v[13] = y0; v[14] = z0; v[15] = 1.0f;
    v[16] = x0; v[17] = y0; v[18] = z1; v[19] = 1.0f;
    v[20] = x0; v[21] = y1; v[22] = z1; v[23] = 1.0f;
    v[24] = x1; v[25] = y1; v[26] = z1; v[27] = 1.0f;
    v[28] = x1; v[29] = y0; v[30] = z1; v[31] = 1.0f;
}
}  // namespace n00144b38

// 00144be0 (was src/anon/batch_wcx2.cpp)
namespace n00144be0 {
// 0x0011c8f8: definition moved into src/anon/unit_0011c128.cpp

struct V4f { f32 x, y, z, w; };
/*TARGET 00144be0*/
// 00144be0: eight corners of the box min(0,1,2)/max(3,4,5), y and z negated
void func_00144be0(f32* b, V4f* v) asm("func_00144be0");
// 00144be0: eight corners of the box min(0,1,2)/max(3,4,5), y and z negated
void func_00144be0(f32* b, V4f* v)
{
    v[0].w = v[1].w = v[2].w = v[3].w = v[4].w = v[5].w = v[6].w = v[7].w = 1.0f;
    v[0].x = b[0]; v[0].y = -b[4]; v[0].z = -b[5];
    v[1].x = b[0]; v[1].y = -b[1]; v[1].z = -b[5];
    v[2].x = b[3]; v[2].y = -b[1]; v[2].z = -b[5];
    v[3].x = b[3]; v[3].y = -b[4]; v[3].z = -b[5];
    v[4].x = b[0]; v[4].y = -b[4]; v[4].z = -b[2];
    v[5].x = b[0]; v[5].y = -b[1]; v[5].z = -b[2];
    v[6].x = b[3]; v[6].y = -b[1]; v[6].z = -b[2];
    v[7].x = b[3]; v[7].y = -b[4]; v[7].z = -b[2];
}
}  // namespace n00144be0

// 00144d10 (was src/anon/auto80_199_queue.cpp)
namespace n00144d10 {
/*TARGET 00144d10*/
u32 func_00144d10(f32* a0, f32* a1) asm("func_00144d10");
// 0x00143e50: definition moved into src/anon/unit_00142c90.cpp

u32 func_00144d10(f32* a0, f32* a1) {
    if (a0[3] < a1[0]) {
        return 0;
    }
    f32 f1 = a0[0];
    f32 f0 = a1[3];
    if (f0 < f1) {
        return 0;
    }
    if (a0[4] < a1[1]) {
        return 0;
    }
    f1 = a0[1];
    f0 = a1[4];
    if (f0 < f1) {
        return 0;
    }
    if (a0[5] < a1[2]) {
        return 0;
    }
    f1 = a0[2];
    f0 = a1[5];
    if (f0 < f1) {
        return 0;
    }
    return 1;
}
}  // namespace n00144d10

// 00144d90 (was src/anon/auto80_199_queue.cpp)
namespace n00144d90 {
/*TARGET 00144d90*/
u32 func_00144d90(f32* a0, f32* a1) asm("_Z13func_00144d90PfS_");
u32 func_00144d90(f32* a0, f32* a1) {  // aabb_overlap
    f32 f1 = a0[0];
    f32 f0 = a1[0];
    if (f0 < f1) {
        return 0;
    }

    f1 = a0[3];
    f0 = a1[3];
    if (f1 < f0) {
        return 0;
    }

    f1 = a0[1];
    f0 = a1[1];
    if (f0 < f1) {
        return 0;
    }

    f1 = a0[4];
    f0 = a1[4];
    if (f1 < f0) {
        return 0;
    }

    f1 = a0[2];
    f0 = a1[2];
    if (f0 < f1) {
        return 0;
    }

    f1 = a0[5];
    f0 = a1[5];
    if (f1 < f0) {
        return 0;
    }

    return 1;
}
}  // namespace n00144d90

// 00144e10 (was gap, never written)
namespace n00144e10 {
// clear an s16 box
void func_00144e10(s16* b) asm("func_00144e10");
void func_00144e10(s16* b) {
    b[5] = 0; b[4] = 0; b[3] = 0; b[2] = 0; b[1] = 0; b[0] = 0;
}
}  // namespace n00144e10

// 00144e30 (was src/anon/tiny_auto80.cpp)
namespace n00144e30 {
/*TARGET 00144e30*/
// 0x0013f538: definition moved into src/anon/unit_0013ef70.cpp

void func_00144e30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00144e30jjjj");
// 0x0013f538: definition moved into src/anon/unit_0013ef70.cpp

void func_00144e30(u32 a0, u32 a1, u32 a2, u32 a3) {  // zero_6_halfwords
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u16*)((u32)r4 + (s32)(0)) = (u16)0u;
    *(volatile u16*)((u32)r4 + (s32)(10)) = (u16)0u;
    *(volatile u16*)((u32)r4 + (s32)(8)) = (u16)0u;
    *(volatile u16*)((u32)r4 + (s32)(6)) = (u16)0u;
    *(volatile u16*)((u32)r4 + (s32)(4)) = (u16)0u;
    *(volatile u16*)((u32)r4 + (s32)(2)) = (u16)0u;
}
}  // namespace n00144e30

// 00144e50 (was src/anon/batch_wcx2.cpp)
namespace n00144e50 {
// 0010abf0: moved to src/anon/unit_0010a918.cpp

// --------------------
// Quantise six floats to s16 with the per-mode bias/scale tables.
extern f32 D_00348d30[] asm("D_00348d30");
extern f32 D_00348d40[] asm("D_00348d40");
#define Q144e50(f) do { \
    if (!(-32768.0f < (f))) { \
        (f) = ((f) < -32767.0f) ? -32767.0f : ((32767.0f < (f)) ? 32767.0f : (f)); \
    } \
} while (0)
#define R144e50(f) do { \
    if (!((f) < 32768.0f)) { \
        (f) = ((f) < -32767.0f) ? -32767.0f : ((32767.0f < (f)) ? 32767.0f : (f)); \
    } \
} while (0)
union O144e50 { s16 v; u8 c; };
/*TARGET 00144e50*/
void func_00144e50(O144e50* out, f32* in, s32 mode) asm("func_00144e50");
void func_00144e50(O144e50* out, f32* in, s32 mode)
{
    f32 b = D_00348d30[mode];
    f32 s = D_00348d40[mode];
    f32 f;
    f = in[0] - b; if (mode) f *= s; Q144e50(f); out[0].v = (s32)f;
    f = in[1] - b; if (mode) f *= s; Q144e50(f); out[1].v = (s32)f;
    f = in[2] - b; if (mode) f *= s; Q144e50(f); out[2].v = (s32)f;
    f = in[3] + b; if (mode) f *= s; R144e50(f); out[3].v = (s32)f;
    f = in[4] + b; if (mode) f *= s; R144e50(f); out[4].v = (s32)f;
    f = in[5] + b; if (mode) f *= s; R144e50(f); out[5].v = (s32)f;
}
}  // namespace n00144e50

// 001450e8 (was src/anon/batch_w76.cpp)
namespace n001450e8 {
// 0x0013aed8: definition moved into src/anon/unit_0013a8b8.cpp

extern f32 D_00348d30[] asm("D_00348d30");
union HalfOrFloat6 { s16 h[6]; f32 f[6]; };
/*TARGET 001450e8*/
/* six s16 values to floats, optionally scaled by a table entry */
void func_001450e8(HalfOrFloat6* src, s32 idx, HalfOrFloat6* out) asm("func_001450e8");
/* six s16 values to floats, optionally scaled by a table entry */
void func_001450e8(HalfOrFloat6* src, s32 idx, HalfOrFloat6* out)
{
    if (idx == 0) {
        out->f[0] = src->h[0];
        out->f[1] = src->h[1];
        out->f[2] = src->h[2];
        out->f[3] = src->h[3];
        out->f[4] = src->h[4];
        out->f[5] = src->h[5];
    } else {
        f32 s = D_00348d30[idx];
        out->f[0] = src->h[0] * s;
        out->f[1] = src->h[1] * s;
        out->f[2] = src->h[2] * s;
        out->f[3] = src->h[3] * s;
        out->f[4] = src->h[4] * s;
        out->f[5] = src->h[5] * s;
    }
}
}  // namespace n001450e8

