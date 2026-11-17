#include "../common/types.h"
#include "../tozawa/load_data.hpp"

// 00292998 (from src/anon/batch_w84.cpp)
namespace n00292998 {
union GP { struct E16* p; u32 u; s16 h; };
union GS { s16 v; u32 u; };
struct E16 { u32 a, b, c, d; };
extern s16* D_0035f4dc asm("D_0035f4dc");
extern s32 D_0035f4bc asm("D_0035f4bc");
extern s16 D_0035f4e0 asm("D_0035f4e0");
extern GS D_0035f4d8 asm("D_0035f4d8");
extern u8 D_0035f4e2 asm("D_0035f4e2");
extern GP D_0035f4d4 asm("D_0035f4d4");
void func_002fde18(void*, s32, u32) asm("func_002fde18");
void func_00292998(void) asm("func_00292998");
void func_00292998(void) {
    D_0035f4e0 = 0;
    func_002fde18(D_0035f4dc, 0, D_0035f4bc * 4);
    s16 k = D_0035f4dc[D_0035f4e0 * 2 + 1];
    D_0035f4d8.v = k;
    if (D_0035f4e2) {
        D_0035f4d4.p[D_0035f4d8.v].a = 0;
        D_0035f4d4.p[D_0035f4d8.v].b = 0;
        D_0035f4d4.p[D_0035f4d8.v].d = 0;
        D_0035f4d4.p[D_0035f4d8.v].c = 0;
    }
}
}  // namespace n00292998

// 00292a58 (from src/anon/batch_w14.cpp)
namespace n00292a58 {
void func_002fde18(void*, s32, s32) asm("func_002fde18");
void func_00292998(void) asm("func_00292998");
extern u16 D_0035f4d8 asm("D_0035f4d8");
extern void* D_0035f4d4 asm("D_0035f4d4");
extern s32 D_0035f4bc asm("D_0035f4bc");
// 0028e710: moved to src/anon/unit_0028c878.cpp

void func_00292a58(void) asm("func_00292a58");
void func_00292a58(void) {
    D_0035f4d8 = 0;
    func_002fde18(D_0035f4d4, 0, D_0035f4bc << 4);
    func_00292998();
}
}  // namespace n00292a58

// 00292a90 (from src/anon/batch_w45.cpp)
namespace n00292a90 {
struct E16 { s32 id; u32 flag : 1; u32 pad[2]; };
extern s32 D_0035f4d0 asm("D_0035f4d0");
extern E16* D_0035f4d4 asm("D_0035f4d4");
// 0028ce98: moved to src/anon/unit_0028c878.cpp

s32 func_00292a90(s32 id) asm("func_00292a90");
s32 func_00292a90(s32 id) {
    s32 r = 0;
    for (s32 i = 0; i < D_0035f4d0; i++) {
        E16* e = &D_0035f4d4[i];
        if ((u8)e->flag && e->id == id) { r = 1; break; }
    }
    return r;
}
}  // namespace n00292a90

// 00292af0 (from src/anon/batch_w1749.cpp)
namespace n00292af0 {
extern s16 D_0035f4e0 asm("D_0035f4e0");
struct E4 { u16 id; u16 x; };
extern E4* D_0035f4dc asm("D_0035f4dc");
s32 func_00292af0(s32 id) asm("func_00292af0");
s32 func_00292af0(s32 id)
{
    s32 r = 0;
    for (s32 i = 0; i < D_0035f4e0; i++) {
        if (D_0035f4dc[i].id == id) { r = 1; break; }
    }
    return r;
}
}  // namespace n00292af0

// 00292b40 (from src/anon/batch_wcx2.cpp)
namespace n00292b40 {
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
// Assign ring slots to the requested ids that are not already resident.
union Ent292b40 { s16 v; u8 c; };
union Slot292b40 { u32 w; struct { u16 id; u16 slot; } h; };
struct Res292b40 { s32 id; s32 used; s32 pad[2]; };
union U0035f4bc { s32 v; u8 c; };
extern U0035f4bc D_0035f4bc asm("D_0035f4bc");
union U0035f4d0 { s32 v; u8 c; };
extern U0035f4d0 D_0035f4d0 asm("D_0035f4d0");
union U0035f4d4 { Res292b40* v; u8 c; };
extern U0035f4d4 D_0035f4d4 asm("D_0035f4d4");
union U0035f4d8 { s16 v; u8 c; };
extern U0035f4d8 D_0035f4d8 asm("D_0035f4d8");
union U0035f4dc { Slot292b40* v; u8 c; };
extern U0035f4dc D_0035f4dc asm("D_0035f4dc");
union U0035f4e0 { s16 v; u8 c; };
extern U0035f4e0 D_0035f4e0 asm("D_0035f4e0");
s32 func_00292a90(s16 id) asm("func_00292a90");
s32 func_00292af0(s16 id) asm("func_00292af0");
void func_00292998(void) asm("func_00292998");
void func_00292eb0(void) asm("func_00292eb0");
void func_00292b40(s16* list, s32 n) asm("func_00292b40");
void func_00292b40(s16* list, s32 n)
{
    Ent292b40 buf[D_0035f4bc.v];
    s32 cnt, i, k;
    s32 mask;

    cnt = 0;
    for (i = 0; i < n; i++) {
        if (func_00292a90(list[i])) continue;
        if (func_00292af0(list[i])) continue;
        buf[cnt++].v = list[i];
    }
    if (cnt + D_0035f4e0.v > D_0035f4d0.v) {
        for (i = 0; i < n; i++) {
            for (k = 0; k < D_0035f4e0.v; k++) {
                if (D_0035f4dc.v[k].h.id == list[i]) {
                    buf[cnt++].v = list[i];
                    break;
                }
            }
        }
        func_00292998();
    }
    mask = 0;
    for (i = 0; i < D_0035f4d0.v; i++) {
        k = 0;
        if (D_0035f4d4.v[i].used) {
            for (k = 0; k < n; k++) {
                if (D_0035f4d4.v[i].id == list[k]) break;
            }
        }
        if (!D_0035f4d4.v[i].used || k >= n) mask |= 1 << i;
    }
    for (i = 0; i < cnt; i++) {
        for (k = 0; k < D_0035f4d0.v; k++) {
            s32 p = D_0035f4d8.v + k;
            if (p >= D_0035f4d0.v) p = 0;
            if ((mask >> p) & 1) {
                D_0035f4d8.v = p;
                mask &= ~(1 << p);
                break;
            }
        }
        {
            s16 b = buf[i].v;
            s32 e = D_0035f4e0.v++;
            Slot292b40* tab = D_0035f4dc.v;
            u16 d = D_0035f4d8.v++;
            tab[e].w = (d << 16) | (u16)b;
        }
        if (D_0035f4d8.v >= D_0035f4d0.v) D_0035f4d8.v = 0;
    }
    func_00292eb0();
}
}  // namespace n00292b40

