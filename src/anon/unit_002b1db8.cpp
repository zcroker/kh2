// Linked unit (see linked_units.tsv).
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002b1db8 (was src/anon/batch_w2417_nsa.cpp)
namespace n002b1db8 {
struct E2b1 {
    u32 id:16;
    u32 kind:8;
    u32 a:1;
    u32 b:1;
    u32 c:1;
    u32 d:1;
    u32 e:1;
    u32 pad:3;
    char name[32];
};
struct S2b1 { u8 pad[0x34]; u32 lo:14; u32 cnt:4; u32 hi:14; };
struct H2b1 { u8 b0; u8 b1; u16 id; u16 w4; u8 pad[10]; };
struct T2b1 { s32 x0; s32 x4; s32 count; s32 xc; H2b1 e[1]; };
struct W2b1 { u8 pad[0x1e4]; u16 bits[2]; struct { s8 v; u8 p[3]; } q[1]; };
union U2b1 { E2b1* p; u32 u; };
extern U2b1 D_0035f630_u asm("D_0035f630");
#define D_0035f630 D_0035f630_u.p
extern S2b1* D_0035f638 asm("D_0035f638");
T2b1* func_00294000(s32) asm("func_00294000");
W2b1* func_002a9d68(void) asm("func_002a9d68");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 func_00276c18(void) asm("func_00276c18");
void* func_00192048(u32) asm("func_00192048");
void func_00192c90(void*, char*) asm("func_00192c90");
void Tz__MenuUtil__MakeQuestionStr(u32, char*, s32) asm("Tz__MenuUtil__MakeQuestionStr");
/*TARGET 002b1db8*/
void func_002b1db8(void) asm("func_002b1db8");
void func_002b1db8(void) {
    u32 i;
    T2b1* t = func_00294000(9);
    H2b1* e = t->e;
    W2b1* w = func_002a9d68();
    D_0035f638->cnt = 0;
    func_002fde18(D_0035f630, 0, 0x168);
    u16* bits;
    for (i = 0; (s32)i < t->count; i++, e++) {
        bits = w->bits;
        s32 h = 24;
        s32 j = 0;
        s32 n = (e->b1 & 0xf) ? 48 : h;
        s32 found = 0;
        if (n) {
            s8* q = (s8*)((u32)(i * 192) + (u32)w + 488);
            do {
                if (*q >= 0) { found = 1; break; }
                q += 4;
                j++;
            } while (j < n);
        }
        D_0035f630[i].a = (found || func_00276c18()) ? 1 : 0;
        D_0035f630[i].b = found;
        if (D_0035f630[i].b) D_0035f638->cnt++;
        { s32 m = 1 << (i & 15); D_0035f630[i].c = (bits[i >> 4] & m) != 0; }
        D_0035f630[i].d = (e->b1 & 0xf) != 0;
        D_0035f630[i].e = (e->b1 & 0xf0) != 0;
        if (D_0035f630[i].b) func_00192c90(func_00192048(e->id), D_0035f630[i].name);
        else Tz__MenuUtil__MakeQuestionStr(e->id, D_0035f630[i].name, 32);
        D_0035f630[i].kind = e->b0;
        D_0035f630[i].id = e->w4;
    }
}
#undef D_0035f630
}  // namespace n002b1db8

// 002b20b8 (was src/anon/batch_wcx2.cpp)
namespace n002b20b8 {
// 0x002acb20: definition moved into src/anon/unit_002a99c8.cpp

struct Ob31;
extern Ob31* D_0035f634 asm("D_0035f634");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(u8*) asm("func_00139510");
s32 func_00281be0(void) asm("func_00281be0");
void func_00281c50(void) asm("func_00281c50");
void func_002b2c80(void) asm("func_002b2c80");
struct Ob31 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[404];
};
static inline void Kill31(s32 off)
{
    if (func_00139d78((u8*)D_0035f634 + off)) func_00139510((u8*)D_0035f634 + off);
}
/*TARGET 002b20b8*/
void Tz__JmPuzzle__LeaveSeqTbl(void) asm("Tz__JmPuzzle__LeaveSeqTbl");
void Tz__JmPuzzle__LeaveSeqTbl(void)
{
    for (s32 i = 0; i < 48; i++) {
        if (func_00139d78(&D_0035f634[i])) D_0035f634[i].v5();
    }
    Kill31(21216);
    Kill31(22032);
    Kill31(22468);
    Kill31(24212);
    Kill31(21624);
    Kill31(23340);
    Kill31(23776);
    Kill31(22904);
    if (func_00281be0()) func_00281c50();
    func_002b2c80();
}
}  // namespace n002b20b8

// 002b2220 (was src/anon/batch_w257.cpp)
namespace n002b2220 {
extern u8* D_0035f634 asm("D_0035f634");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_002b1660(void) asm("func_002b1660");
/*TARGET 002b2220*/
void func_002b2220(void) asm("func_002b2220");
void func_002b2220(void) {
    struct NoTail { ~NoTail(){} } nt;
    s32 i;
    for (i = 0; i < 48; i++) {
        if (func_00139d78(D_0035f634 + i * 408)) return;
    }
    if (func_00139d78(D_0035f634 + 19584)) return;
    for (i = 0; i < 2; i++) {
        if (func_00139d78(D_0035f634 + 19992 + i * 408)) return;
    }
    if (func_00139d78(D_0035f634 + 20808)) return;
    if (func_00139d78(D_0035f634 + 21216)) return;
    if (func_00139d78(D_0035f634 + 22032)) return;
    if (func_00139d78(D_0035f634 + 22468)) return;
    if (func_00139d78(D_0035f634 + 24212)) return;
    func_002b1660();
}
}  // namespace n002b2220

// 002b2338 (was src/anon/tiny_auto80_queue.cpp)
namespace n002b2338 {
/*TARGET 002b2338*/
u32 func_002b2338(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002b2338jjjjjjjj");
u32 func_002b2338(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r12, r13, r14, r15;
    r15 = (u32)(0x0036u << 16);
    r13 = 0u;
    r14 = *(u32*)((u32)r15 + (s32)(-2512));
    r2 = 0u;
    r12 = (u32)(0x0100u << 16);
    while (1) {
        r15 = *(u32*)((u32)r14 + (s32)(0));
        r15 = (u32)(r15 & r12);
        r14 = (u32)((s32)r14 + (36));
        if (r15 != 0u) {
            if (r13 == r4) break;
            r13 = (u32)((s32)r13 + (1));
        }
        r2 = (u32)((s32)r2 + (1));
        r15 = ((s32)r2 < (s32)10);
        if (r15 == 0u) break;
    }
    return r2;
}
}  // namespace n002b2338

// 002b2380 (was src/anon/auto80_199_queue.cpp)
namespace n002b2380 {
/*TARGET 002b2380*/
// 0x002aecf0: definition moved into src/anon/unit_002aeba0.cpp

s32 func_002b2380(s32 a0, s32 a1) asm("_Z13func_002b2380ii");
// 0x002aecf0: definition moved into src/anon/unit_002aeba0.cpp

s32 func_002b2380(s32 a0, s32 a1) {
    u32* p = Tz__JmPuzzle__GetImageInfo(-1);  // list_entry_by_index_checked
    u32 t7 = p[0];
    t7 >>= 25;
    t7 &= 4;
    s32 t5 = D_00374cd0[t7];
    a1 = a1 * t5;
    a1 = a1 + a0;
    return a1;
}
}  // namespace n002b2380

// 002b23e0 (was src/anon/batch_w32.cpp)
namespace n002b23e0 {
s32 func_00276608(s32) asm("func_00276608");
s32 func_002b2338(s32) asm("func_002b2338");
extern u8* D_0035f630 asm("D_0035f630");
/*TARGET 002b23e0*/
// 0x00282c68: definition moved into src/anon/unit_00282c68.cpp

u8* Tz__JmPuzzle__GetImageInfo(s32 i) asm("Tz__JmPuzzle__GetImageInfo");
// 0x00282c68: definition moved into src/anon/unit_00282c68.cpp

u8* Tz__JmPuzzle__GetImageInfo(s32 i) {  // list_entry_by_index_checked
    if (i < 0) i = func_00276608(28);
    return D_0035f630 + func_002b2338(i) * 36;
}
}  // namespace n002b23e0

// 002b2428 (was src/anon/batch_wcx.cpp)
namespace n002b2428 {
// 0x002c6050: definition moved into src/anon/unit_002c53c8.cpp
u8* func_00294000(s32) asm("func_00294000");
union U52 { u8 b; s8 c; u32 w; };
extern u8* D_0035f638 asm("D_0035f638");
s32 func_00292630(void) asm("func_00292630");
void Tz__JmPuzzle__LeaveAll(void) asm("Tz__JmPuzzle__LeaveAll");
void func_00293bd0(s32, u8*, s32) asm("func_00293bd0");
void func_002925c0(void) asm("func_002925c0");
/*TARGET 002b2428*/
void Tz__JmPuzzle__RequestGraLoad(u32 v) asm("Tz__JmPuzzle__RequestGraLoad");
void Tz__JmPuzzle__RequestGraLoad(u32 v)
{
    ((U52*)(D_0035f638 + 52))->b = v;
    if (func_00292630()) { ((U52*)(D_0035f638 + 52))->w &= ~0x100; return; }
    u8* t = func_00294000(9) + 16;
    Tz__JmPuzzle__LeaveAll();
    func_00293bd0(5, t + ((U52*)(D_0035f638 + 52))->c * 16 + 6, 0);
    func_002925c0();
    ((U52*)(D_0035f638 + 52))->w |= 0x100;
}
}  // namespace n002b2428

// 002b24c8 (was src/anon/batch_w3803.cpp)
namespace n002b24c8 {
struct S2b2 { u8 pad[0x34]; s32 idx:8; u32 flag:1; u32 rest:23; };
struct I2b2 { u32 lo:26; u32 b26:1; u32 b27:1; u32 hi:4; };
struct L2b2 { s8 cols; s8 rows; s16 step; };
struct F2b2 { u32 b0:3; u32 b3:1; u32 b4:9; u32 b13:1; u32 hi:18; };
struct Sub2b2 { u8 pad[0xb8]; F2b2 f; };
struct O2b2 { u8 pad[0x18]; Sub2b2 sub; u8 pad2[0x195 - 0x18 - 0xbc]; u8 b195; u8 pad3[2]; };
extern S2b2* D_0035f638 asm("D_0035f638");
extern O2b2* D_0035f634 asm("D_0035f634");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f210 asm("D_0035f210");
extern const L2b2 D_00374cd0[] asm("D_00374cd0");
void Tz__JmPuzzle__RequestGraLoad(s32) asm("Tz__JmPuzzle__RequestGraLoad");
s32 func_00292630(void) asm("func_00292630");
u8* func_002766d0(void) asm("func_002766d0");
I2b2* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
void func_002b27c8(void) asm("func_002b27c8");
s32 func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(s32, s32) asm("func_0023c4b8");
s32 func_0023f988(void*, s32) asm("func_0023f988");
void YI__IMAGE__Init(void*, s32) asm("YI__IMAGE__Init");
void dk__Sprite__create(void*, s32, s32, void*, s32, s32) asm("dk__Sprite__create");
void func_00139620(void*) asm("func_00139620");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void func_002b28b0(u32, s32, s32, void*) asm("func_002b28b0");
void YI__SPRITE__SetDirextUV(void*, void*, void*) asm("YI__SPRITE__SetDirextUV");
void Tz__JmPuzzle__UpdatePiece(s32) asm("Tz__JmPuzzle__UpdatePiece");
void func_002b2a18(void) asm("func_002b2a18");
void func_002b2da8(s32) asm("func_002b2da8");
void func_002b3050(s32) asm("func_002b3050");
/*TARGET 002b24c8*/
// 0x00272c90: definition moved into src/anon/unit_00271e08.cpp

// Builds a grid of menu entries (rows x cols from the D_00374cd0 layout table) and lays them out.
void func_002b24c8(void) asm("func_002b24c8");
// 0x00272c90: definition moved into src/anon/unit_00271e08.cpp

// Builds a grid of menu entries (rows x cols from the D_00374cd0 layout table) and lays them out.
void func_002b24c8(void) {
    if (!D_0035f638->flag) {
        if (D_0035f638->idx >= 0) Tz__JmPuzzle__RequestGraLoad(D_0035f638->idx);
        return;
    }
    if (D_0035f638->idx < 0) return;
    if (func_00292630()) return;
    {
        u8 b0[16];
        u8* base;
        s32 row;
        s32 v;
        s32 rows;
        s32 step;
        void* name;
        I2b2* info;
        s32 font;
        s32 cols;
        base = func_002766d0();
        row = 0;
        info = Tz__JmPuzzle__GetImageInfo(-1);
        func_002b27c8();
        v = D_0035f3d4 + 2;
        name = (u8*)D_0035f634 + 0x52e0;
        font = func_0023c4b8(func_0023f1b0(D_0035f210), 6);
        s32 r = func_0023f988(D_0035f638, 0);
        u8* w = base + 0xdca0;
        YI__IMAGE__Init(w, r);
        w[400] = 1;
        u32 k = info->b27;
        step = D_00374cd0[k].step;
        rows = D_00374cd0[k].rows;
        cols = D_00374cd0[k].cols;
        for (; row < rows; row++) {
            s32 col;
            for (col = 0; col < cols; col++) {
                O2b2* o = &D_0035f634[row * cols + col];
                dk__Sprite__create(o, v, font, base + 0xdca0, 0, 0);
                s32 n = row * cols + col;
                if (row == 0 && col == 0) {
                    Sub2b2* t = &o->sub;
                    t->f.b3 = 1;
                    o->b195 = 1;
                }
                Sub2b2* s = &o->sub;
                func_00139620(o);
                func_0028dcc0(o, name);
                s32 one = 1;
                s->f.b13 = one;
                func_00138c68(o, col * step, row * step);
                func_002b28b0(info->b27, n, 0, b0);
                YI__SPRITE__SetDirextUV(s, b0, b0 + 8);
            }
        }
        Tz__JmPuzzle__UpdatePiece(1);
        func_002b2a18();
        if (!info->b26) {
            func_002b2da8(0);
            func_002b3050(1);
        }
        D_0035f638->idx = -1;
        D_0035f638->flag = 0;
    }
}
}  // namespace n002b24c8

// 002b27c8 (was src/anon/batch_w37.cpp)
namespace n002b27c8 {
// 0x0028afd0: definition moved into src/anon/unit_00288b00.cpp

extern u8* D_0035f638 asm("D_0035f638");
void func_0023f900(void*) asm("func_0023f900");
s32 func_00292630(void) asm("func_00292630");
u8* func_00294000(u32) asm("func_00294000");
void* func_00293db8(u32, void*) asm("func_00293db8");
void func_0023fa08(void*, void*) asm("func_0023fa08");
/*TARGET 002b27c8*/
void func_002b27c8(void) asm("func_002b27c8");
void func_002b27c8(void) {
    func_0023f900(D_0035f638);
    if (func_00292630()) return;
    u8* v = func_00294000(9);
    void* x = func_00293db8(5, v + ((s8*)D_0035f638)[52] * 16 + 22);
    func_0023fa08(D_0035f638, x);
    *(u32*)(D_0035f638 + 52) |= 0x200;
}
}  // namespace n002b27c8

// 002b2840 (was src/anon/batch_w48.cpp)
namespace n002b2840 {
// 0x002a1ec8: definition moved into src/anon/unit_002a1d38.cpp

extern u8* D_0035f638 asm("D_0035f638");
s32 func_0023f900(void*) asm("func_0023f900");
void func_0023fad0(void*) asm("func_0023fad0");
void func_00293d80(s32) asm("func_00293d80");
/*TARGET 002b2840*/
void Tz__JmPuzzle__LeaveAll(void) asm("Tz__JmPuzzle__LeaveAll");
void Tz__JmPuzzle__LeaveAll(void) {
    if (*(u32*)(D_0035f638 + 52) & 0x200) {
        if (func_0023f900(D_0035f638)) func_0023fad0(D_0035f638);
    }
    func_00293d80(5101);
    *(u32*)(D_0035f638 + 52) &= ~0x200;
}
}  // namespace n002b2840

// 002b28b0 (was src/anon/batch_wcx2.cpp)
namespace n002b28b0 {
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
// 0x002c3368: definition moved into src/anon/unit_002c2228.cpp

struct Grid55 { s8 cols; u8 pad; s16 size; };
struct UV55 { s16 u[4]; s16 v[4]; };
extern Grid55 D_00374cd0[] asm("D_00374cd0");
u32* func_002b23e0__86355(s32) asm("Tz__JmPuzzle__GetImageInfo");
static inline void Put55(UV55* o, const UV55& t, s32 a, s32 b, s32 c, s32 d)
{
    o->u[0] = t.u[a]; o->v[0] = t.v[a];
    o->u[1] = t.u[b]; o->v[1] = t.v[b];
    o->u[2] = t.u[c]; o->v[2] = t.v[c];
    o->u[3] = t.u[d]; o->v[3] = t.v[d];
}
/*TARGET 002b28b0*/
void func_002b28b0(u32 a0, s32 idx, s32 mode, UV55* out) asm("func_002b28b0");
void func_002b28b0(u32 a0, s32 idx, s32 mode, UV55* out)
{
    Grid55* g = &D_00374cd0[(*func_002b23e0__86355(-1) >> 27) & 1];
    s32 cols = g->cols;
    s32 sz = g->size;
    s32 row = idx / cols;
    s32 col = idx % cols;
    UV55 t;
    t.u[0] = col * sz;
    t.v[0] = row * sz;
    t.u[3] = (col + 1) * sz;
    t.v[3] = (row + 1) * sz;
    t.u[2] = col * sz;
    t.u[1] = (col + 1) * sz;
    t.v[1] = row * sz;
    t.v[2] = (row + 1) * sz;
    switch (mode) {
    case 0: *out = t; break;
    case 1: Put55(out, t, 2, 0, 3, 1); break;
    case 2: Put55(out, t, 3, 2, 1, 0); break;
    case 3: Put55(out, t, 1, 3, 0, 2); break;
    }
}
}  // namespace n002b28b0

