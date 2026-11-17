// Linked unit 0x002a40c8-0x002a4e38.
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

// 002a40c8 (was src/anon/batch_w96.cpp)
namespace n002a40c8 {
s32 func_00139d78(u8*) asm("func_00139d78");
extern u8* D_0035f5e8 asm("D_0035f5e8");
/*TARGET 002a40c8*/
// 0028e190: moved to src/anon/unit_0028c878.cpp

// Returns nonzero if any of the screen's widgets is still busy.
s32 func_002a40c8(void) asm("func_002a40c8");
// 0028e190: moved to src/anon/unit_0028c878.cpp

// Returns nonzero if any of the screen's widgets is still busy.
s32 func_002a40c8(void) {
    s32 r;
    s32 i, j;
    if ((r = func_00139d78(D_0035f5e8 + 29376)) != 0) return r;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 8; j++) {
            if ((r = func_00139d78(D_0035f5e8 + i * 3264 + j * 408)) != 0) return r;
        }
    }
    if ((r = func_00139d78(D_0035f5e8 + 29784)) != 0) return r;
    if ((r = func_00139d78(D_0035f5e8 + 30220)) != 0) return r;
    if ((r = func_00139d78(D_0035f5e8 + 30656)) != 0) return r;
    for (i = 0; i < 9; i++) {
        if ((r = func_00139d78(D_0035f5e8 + i * 436 + 31092)) != 0) return r;
        if ((r = func_00139d78(D_0035f5e8 + i * 436 + 0x88c8)) != 0) return r;
    }
    return r;
}
}  // namespace n002a40c8

// 002a41f0 (was src/anon/batch_wcx2.cpp)
namespace n002a41f0 {
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
struct ObA51 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[404];
};
struct ObB51 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[432];
};
struct Mgr51 {
    ObA51 grp[9][8];
    ObA51 a;
    ObB51 b, c, d;
    ObB51 e[9];
    ObB51 f[9];
};
extern Mgr51* D_0035f5e8 asm("D_0035f5e8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510__82352(void*) asm("func_00139510");
/*TARGET 002a41f0*/
void func_002a41f0(void) asm("func_002a41f0");
void func_002a41f0(void)
{
    if (func_00139d78(&D_0035f5e8->a)) func_00139510__82352(&D_0035f5e8->a);
    s32 j;
    for (j = 0; j < 9; j++) {
        for (s32 i = 0; i < 8; i++) {
            if (func_00139d78(&D_0035f5e8->grp[j][i])) D_0035f5e8->grp[j][i].v5();
        }
    }
    if (func_00139d78(&D_0035f5e8->b)) func_00139510__82352(&D_0035f5e8->b);
    if (func_00139d78(&D_0035f5e8->c)) func_00139510__82352(&D_0035f5e8->c);
    if (func_00139d78(&D_0035f5e8->d)) func_00139510__82352(&D_0035f5e8->d);
    for (j = 0; j < 9; j++) {
        if (func_00139d78(&D_0035f5e8->e[j])) D_0035f5e8->e[j].v5();
        if (func_00139d78(&D_0035f5e8->f[j])) D_0035f5e8->f[j].v5();
    }
}
}  // namespace n002a41f0

// 002a4380 (was src/anon/misc_2.cpp)
namespace n002a4380 {
/*TARGET 002a4380*/
s64 func_002a4380(s64 param0, s64 param1, s64 param2, s64 param3) asm("_Z13func_002a4380xxxx");
s64 func_002a4380(s64 param0, s64 param1, s64 param2, s64 param3) {
    s64 result = 0, arg0 = param0, arg1 = param1, arg2 = param2, arg3 = param3, returnAddr = 0;
    arg0 = (s64)((u64)arg0 ^ 0x0008);
    arg0 = ((u64)arg0 < (u64)((s64)1)) ? 1 : 0;
    result = arg0 + 0;
    return result;
}
}  // namespace n002a4380

// 002a4390 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002a4390 {
u32 func_001a8450(u32, u32, u32, u32) asm("_Z13func_001a8450jjjj");
/*TARGET 002a4390*/
// 00290848: moved to src/anon/unit_0028f1e0.cpp


u32 func_002a4390(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002a4390jjjj");
// 00290848: moved to src/anon/unit_0028f1e0.cpp


u32 func_002a4390(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_001a8450)(u32, u32, u32, u32) = func_001a8450;
    r2 = fp_call4_001a8450(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002a4390

// 002a43b0 (was src/tozawa/jm_treasure.cpp)
namespace n002a43b0 {
u32 func_001a3570(...) asm("func_001a3570");
/*TARGET 002a43b0*/
// Tz::JmTreasure::isEnableNavi (static), plain function bound by asm label
u32 JmTreasure_isEnableNavi(const void* entry) asm("_ZN2Tz10JmTreasure12isEnableNaviEPKN2YS8TREASURE5TABLEE");
u32 JmTreasure_isEnableNavi(const void* entry) {
    u32 r4 = (u32)(*(u16*)((u32)entry + (s32)(2)));
    u32 r2 = func_001a3570(r4);
    r2 = ((s32)0u < (s32)r2);
    return r2;
}
}  // namespace n002a43b0

// 002a43d0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002a43d0 {
u32 func_001d9d48(u32, u32, u32, u32) asm("_Z13func_001d9d48jjjj");
/*TARGET 002a43d0*/
u32 func_002a43d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002a43d0jjjj");
u32 func_002a43d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_001d9d48)(u32, u32, u32, u32) = func_001d9d48;
    r2 = fp_call4_001d9d48(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002a43d0

// 002a43f0 (was src/anon/batch_w21.cpp)
namespace n002a43f0 {
s32 func_00287bc0(void) asm("func_00287bc0");
/*TARGET 002a43f0*/
// 0x00288c20: definition moved into src/anon/unit_00288b00.cpp

s32 func_002a43f0(void) asm("func_002a43f0");
// 0x00288c20: definition moved into src/anon/unit_00288b00.cpp

s32 func_002a43f0(void) {
    s32 v = func_00287bc0();
    s32 r = 0;
    if (v == 7 || v == 26) r = 1;
    return r;
}
}  // namespace n002a43f0

// 002a4430 (was src/anon/tiny_auto80_queue.cpp)
namespace n002a4430 {
u32 func_002a4430() asm("func_002a4430");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 002a4430*/
u32 func_002a4430() asm("func_002a4430");
u32 func_002a4430() {
    u32 v0 = func_00287bc0();
    return (v0 == 8 || v0 == 33) ? 1u : 0u;
}
}  // namespace n002a4430

// 002a4470 (was src/anon/batch_w94.cpp)
namespace n002a4470 {
u8* func_002766d0(void) asm("func_002766d0");
void func_00138c78(u8*, u32*, u32*) asm("func_00138c78");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620(u8*) asm("func_00139620");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
void func_00275980(s32, u8*) asm("func_00275980");
void func_002759e8(u8*) asm("func_002759e8");
s32 func_002a4990(s32) asm("func_002a4990");
void func_00138c10(u8*, u32) asm("func_00138c10");
extern u8* D_0035f5e4 asm("D_0035f5e4");
extern u8* D_0035f5e8 asm("D_0035f5e8");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f210 asm("D_0035f210");
/*TARGET 002a4470*/
void func_002a4470(void) asm("func_002a4470");
void func_002a4470(void) {
    u8* x = func_002766d0();
    s32 n = *(s32*)(D_0035f5e4 + 4232);
    s32 r = n % 8;
    u8* o = D_0035f5e8 + (n / 8) * 3264 + r * 408;
    u32 t0, t1;
    func_00138c78(o, &t0, &t1);
    o = D_0035f5e8 + 29376;
    func_0028d8c0(o, D_0035f3d4 + 1, D_0035f14c, D_0035f148, D_0035f210, 65, -1, 0);
    func_00139620(o);
    func_0028dcc0(o, x);
    func_00138c68(o, t0, t1);
    func_00275980(0, o);
    func_002759e8(o);
    u8* g = D_0035f5e4;
    if (!g[func_002a4990(-1) * 8 + 4096]) func_00138c10(o, 66);
}
}  // namespace n002a4470

// 002a45a0 (was src/anon/auto80_199_queue.cpp)
namespace n002a45a0 {
/*TARGET 002a45a0*/
// 0x002a07f0: definition moved into src/anon/unit_0029f938.cpp

void func_002a45a0(void) asm("_Z13func_002a45a0v");
// 0x002a07f0: definition moved into src/anon/unit_0029f938.cpp

void func_002a45a0(void) {
    u32* s0 = &D_0035f5e8;
    if (func_00139d78(*s0 + 29376) != 0) {
        func_00139510(*s0 + 29376);
    }

    if (func_0028d008(0) != 0) {
        func_0028cdb8(0);  // record408_alloc_init
    }

    s0 = &D_0035f218;
    if (func_0028d6e8(*s0) != 0) {
        func_0028d5d0(*s0);
    }
}
}  // namespace n002a45a0

// 002a4620 (was src/anon/batch_w2423_nsa.cpp)
namespace n002a4620 {
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
void func_00138c78(u8*, u32*, u32*) asm("func_00138c78");
void func_00242618(s32, s32) asm("func_00242618");
void func_002a3aa8(void) asm("func_002a3aa8");
s32 func_002a4990(s32) asm("func_002a4990");
s32 func_002a4a00(s32) asm("func_002a4a00");
extern u8* D_0035f5e4 asm("D_0035f5e4");
extern u8* D_0035f5e8 asm("D_0035f5e8");
struct Pad2a { u8 p0[8]; u64 trig; u8 p1[8]; u64 rep; };
/*TARGET 002a4620*/
void func_002a4620(Pad2a* pad) asm("func_002a4620");
void func_002a4620(Pad2a* pad) {
    s32 sel = *(s32*)(D_0035f5e4 + 4232);
    s32 top = *(s32*)(D_0035f5e4 + 4228);
    s32 total = *(s32*)(D_0035f5e4 + 4224);
    s32 vis = total;
    s32 col = sel % 8;
    s32 row = sel / 8;
    s32 idx = row + top;
    s32 n = func_002a4a00(idx);
    if (vis >= 10) vis = 9;
    if (pad->rep & 0x10) {
        if (row != 0) { row--; goto calc; }
        if (top != 0) { top--; idx = top; goto recount; }
        if (pad->trig & 0x10) { top = total - vis; row = vis - 1; goto calc; }
        goto recount;
    } else if (pad->rep & 0x20) {
        if (row < vis - 1) { row++; goto calc; }
        if (top + 9 < total) { top++; goto calc; }
        if (pad->trig & 0x20) { top = 0; row = 0; idx = 0; }
        goto recount;
    } else if (pad->rep & 0x8000) {
        if (vis < top) { top -= vis; goto calc; }
        if (top != 0) { top = 0; row = 0; idx = 0; goto recount; }
        if (col != 0) { col = 0; goto recount; }
        if (pad->trig & 0x8000) {
            top = total - vis; row = vis - 1; idx = row + top;
            col = func_002a4a00(idx) - 1;
        }
        goto recount;
    calc:
        idx = row + top;
    recount:
        n = func_002a4a00(idx);
        if (col >= n) col = n - 1;
    } else if (pad->rep & 0x4000) {
        s32 lim = total - vis;
        s32 nt = top + vis;
        if (nt < lim) { top = nt; goto calc2; }
        if (top < lim) { top = lim; row = vis - 1; goto calc2; }
        if (col < n - 1) { top = lim; col = n - 1; goto calc2; }
        if (pad->trig & 0x4000) { top = 0; row = 0; col = 0; idx = 0; }
        goto recount2;
    calc2:
        idx = row + top;
    recount2:
        n = func_002a4a00(idx);
        if (col >= n) col = n - 1;
    }
    if (pad->rep & 0x40) col = col == 0 ? n - 1 : col - 1;
    else if (pad->rep & 0x80) col = col < n - 1 ? col + 1 : 0;
    sel = row * 8 + col;
    if (top != *(s32*)(D_0035f5e4 + 4228) || sel != *(s32*)(D_0035f5e4 + 4232)) {
        func_00242618(1, 1);
        u8* o = D_0035f5e8 + row * 3264 + col * 408;
        u32 t0, t1;
        func_00138c78(o, &t0, &t1);
        o = D_0035f5e8 + 29376;
        func_00138c68(o, t0, t1);
        s32 k = func_002a4990(idx);
        if (!D_0035f5e4[k * 8 + 4096] && *(s32*)(o + 388) != 66) func_00138c10(o, 66);
        else if (D_0035f5e4[k * 8 + 4096] && *(s32*)(o + 388) == 66) func_00138c10(o, 65);
        *(s32*)(D_0035f5e4 + 4228) = top;
        *(s32*)(D_0035f5e4 + 4232) = sel;
        func_002a3aa8();
    }
}
}  // namespace n002a4620

// 002a4990 (was src/anon/batch_w45.cpp)
namespace n002a4990 {
extern u8* D_0035f5e4 asm("D_0035f5e4");
/*TARGET 002a4990*/
// 00292a90: moved to src/anon/unit_00292998.cpp

s32 func_002a4990(s32 a0) asm("func_002a4990");
// 00292a90: moved to src/anon/unit_00292998.cpp

s32 func_002a4990(s32 a0) {
    if (a0 < 0) a0 = *(s32*)(D_0035f5e4 + 4228) + *(s32*)(D_0035f5e4 + 4232) / 8;
    s32 sum = 0;
    s32 i;
    for (i = 0; i < 15; i++) {
        u8 c = D_0035f5e4[4097 + i * 8];
        if (c) {
            sum += c;
            if (a0 < sum) break;
        }
    }
    return i;
}
}  // namespace n002a4990

// 002a4a00 (was src/anon/batch_w89.cpp)
namespace n002a4a00 {
struct Slot8 { u8 b0, b1; u8 pad[6]; };
struct A4 { u8 pad[4096]; Slot8 s[1]; };
struct A4h { u8 pad[4228]; s32 base; s32 bits; };
extern u8* D_0035f5e4 asm("D_0035f5e4");
s32 func_002a4990(s32) asm("func_002a4990");
/*TARGET 002a4a00*/
s32 func_002a4a00(s32 i) asm("func_002a4a00");
s32 func_002a4a00(s32 i) {
    if (i < 0) i = ((A4h*)D_0035f5e4)->base + ((A4h*)D_0035f5e4)->bits / 8;
    s32 n = func_002a4990(i);
    s32 sum = 0;
    for (s32 j = 0; j < n; j++) sum += ((A4*)D_0035f5e4)->s[j].b1;
    Slot8* e = (Slot8*)((u32)n * 8 + (u32)D_0035f5e4 + 4096);
    s32 r = 8;
    if (!(i - sum < e->b1 - 1)) {
        u8 b = e->b0;
        r = b & 7;
        if (!r) r = b ? 8 : 1;
    }
    return r;
}
}  // namespace n002a4a00

// 002a4ad8 (was src/anon/batch_wcx.cpp)
namespace n002a4ad8 {
extern u8* D_0035f5e4 asm("D_0035f5e4");
s32 func_002a4990(u8*) asm("func_002a4990");
/*TARGET 002a4ad8*/
s32 func_002a4ad8(s32 a) asm("func_002a4ad8");
s32 func_002a4ad8(s32 a)
{
    if (a < 0) a = *(s32*)(D_0035f5e4 + 4232);
    s32 n = func_002a4990(*(u8**)(D_0035f5e4 + 4228) + a / 8);
    s32 sum = 0;
    if (n > 0) {
        u8* q = D_0035f5e4 + 4097;
        do {
            sum += *q;
            n--;
            // R5900 short-loop padding
            asm volatile("nop\n\tnop");
            q += 8;
        } while (n);
    }
    return a - (sum - *(s32*)(D_0035f5e4 + 4228)) * 8;
}
}  // namespace n002a4ad8

// 002a4b78 (was src/anon/batch_w76.cpp)
namespace n002a4b78 {
s32 func_00287bc0(void) asm("func_00287bc0");
// 0x00296da8: definition moved into src/anon/unit_00295d28.cpp
union GP { u8* p; s32 i; };
extern GP D_0035f5e4 asm("D_0035f5e4");
s8* func_00276568(void) asm("func_00276568");
/*TARGET 002a4b78*/
void func_002a4b78(void) asm("func_002a4b78");
void func_002a4b78(void)
{
    s32 m = func_00287bc0();
    if (m == 26 || m == 34 || m == 33) {
        *(s32*)(D_0035f5e4.p + 4228) = 0;
        *(s32*)(D_0035f5e4.p + 4232) = 0;
        return;
    }
    s32 lim = *(s32*)(D_0035f5e4.p + 4224);
    if (lim >= 10) lim = 9;
    s32 n = *func_00276568();
    s32 sum = 0;
    for (s32 i = 0; i < n; i++) sum += *(D_0035f5e4.p + 4097 + i * 8);
    s32 d = *(s32*)(D_0035f5e4.p + 4224) - lim;
    if (d >= sum) {
        *(s32*)(D_0035f5e4.p + 4228) = sum;
        *(s32*)(D_0035f5e4.p + 4232) = 0;
    } else {
        *(s32*)(D_0035f5e4.p + 4228) = d;
        *(s32*)(D_0035f5e4.p + 4232) = (sum - *(s32*)(D_0035f5e4.p + 4228)) * 8;
    }
}
}  // namespace n002a4b78

// 002a4c68 (was src/anon/batch_w3689.cpp)
namespace n002a4c68 {
s32 func_00103570() asm("func_00103570");
void* func_001063c0(s32, s32) asm("func_001063c0");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
void func_00239700(void*) asm("func_00239700");
struct Heap2a4c;
struct Heap2a4cVt { void* (*alloc)(Heap2a4c*, s32, s32); };
struct Heap2a4c { Heap2a4cVt* vt; };
struct Sys2a4c { u8 pad[20]; Heap2a4c* heap; };
extern Sys2a4c* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
extern void* D_0035f5ec asm("D_0035f5ec");
extern void* D_0035f5f0 asm("D_0035f5f0");
struct Obj2a4c {
    void* vt; s32 f4, f8, f12; u8 pad[8]; u8 m24[384]; s32 f408; u8 pad2[24];
};
/*TARGET 002a4c68*/
// Allocates a 192-byte buffer, then a counted array of 10 objects (new[] with an
// inlined constructor: base vtable, member init, derived vtable).
void func_002a4c68(void) asm("func_002a4c68");
// Allocates a 192-byte buffer, then a counted array of 10 objects (new[] with an
// inlined constructor: base vtable, member init, derived vtable).
void func_002a4c68(void) {
    s32 n;
    register s32 end asm("$20"); // pinned: keeps li 9 / li -1 where the original has them
    void* v60;
    void* v40;
    Obj2a4c* q;
    void* p = func_001063c0(192, func_00103570());
    D_0035f5ec = p;
    func_002fde18(p, 0, 192);
    Heap2a4c* h = D_00347f80->heap;
    s32* c = (s32*)h->vt->alloc(h, 4364, 0);
    c[0] = 10;
    Obj2a4c* a = (Obj2a4c*)(c + 1);
    end = -1;
    n = 9;
    v60 = D_00347e60;
    v40 = D_00347e40;
    q = a;
    while (n != end) {
        q->f12 = 0;
        q->vt = v60;
        func_00239700(q->m24);
        q->vt = v40;
        q->f408 = 0;
        n--;
        q++;
    }
    D_0035f5f0 = a;
}
}  // namespace n002a4c68

// 002a4d48 (was src/anon/batch_w1592.cpp)
namespace n002a4d48 {
struct Heap { void (**vt)(Heap*, void*); };
struct HeapHolder { u8 pad[20]; Heap* heap; };
extern "C" HeapHolder* D_00347f80;
struct El {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El();
    u8 pad[432];
    static void operator delete[](void* p) { D_00347f80->heap->vt[1](D_00347f80->heap, p); }
};
extern void* D_0035f5ec asm("D_0035f5ec");
extern El* D_0035f5f0 asm("D_0035f5f0");
void func_00106420(void*) asm("func_00106420");
/*TARGET 002a4d48*/
void func_002a4d48(void) asm("func_002a4d48");
void func_002a4d48(void) {
    if (D_0035f5ec) { func_00106420(D_0035f5ec); D_0035f5ec = 0; }
    if (D_0035f5f0) { delete[] D_0035f5f0; D_0035f5f0 = 0; }
}
}  // namespace n002a4d48

// 002a4df0 (was src/anon/misc_2.cpp)
namespace n002a4df0 {
/*TARGET 002a4df0*/
void func_002a4df0(void* self) asm("_Z13func_002a4df0Pv");
void func_002a4df0(void* self) {}
}  // namespace n002a4df0

// 002a4df8 (was src/tozawa/jm_battle.cpp)
namespace n002a4df8 {
void func_00274ac8() asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
s32 MenuBase_GetMode() asm("_ZN2Tz8MenuBase7GetModeEv");
void JmBattle_LeaveAllInner() asm("_ZN2Tz8JmBattle13LeaveAllInnerEv");
/*TARGET 002a4df8*/
// Tz::JmBattle::LeaveAll (static), plain function bound by asm label
void JmBattle_LeaveAll() asm("_ZN2Tz8JmBattle8LeaveAllEv");
void JmBattle_LeaveAll() {
    if ((u32)(MenuBase_GetMode() - 37u) < 2u) {
        JmBattle_LeaveAllInner();
        func_00274ac8();
    }
}
}  // namespace n002a4df8

