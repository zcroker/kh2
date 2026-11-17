#include "../common/types.h"

// Draw-state helpers (0x10a918-0x10aef0), incl. the never-written 0x10aea0 (log2 of a size). Split from unit_00109c30.cpp where .rodata becomes 8-aligned.
// Each function keeps the declarations of the source it was matched in (namespace nADDR); every symbol
// is bound by asm label.
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 0010a918 (from src/anon/batch_w1980_nsa.cpp)
namespace n0010a918 {
void func_00134408(void) asm("func_00134408");
void func_00134428(s32, u64) asm("func_00134428");
void func_00134450(s32) asm("func_00134450");
void func_001342c8(void*, s32, s32) asm("func_001342c8");
extern u8 D_00340fd0 asm("D_00340fd0");
extern u8 D_00341000 asm("D_00341000");
extern u8 D_00341030 asm("D_00341030");
extern u64 D_00340ed8[4] asm("D_00340ed8");
void func_0010a918(s32 mode) asm("func_0010a918");
void func_0010a918(s32 mode) {
    u64 scis = 0;
    u64 zbuf = 0;
    u64 frame = 0;
    u64 cl1 = 0;
    u64 cl2 = 0;
    void* p = 0;
    switch (mode) {
    case 0:
        cl1 = 0x3f0000003f0000ULL; cl2 = 0x3d0002003d0002ULL;
        frame = 0x10140; zbuf = 0x30000142; scis = (0x3fULL << 41) | 0x7e00;
        p = &D_00340fd0;
        break;
    case 1:
        cl1 = 0x7f0000007f0000ULL; cl2 = 0x7d0002007d0002ULL;
        frame = 0x20140; zbuf = 0x30000148; scis = (0x1fULL << 42) | 0x7c00;
        p = &D_00341000;
        break;
    case 2:
        cl1 = 0xff000000ff0000ULL; cl2 = 0xfd000200fd0002ULL;
        frame = 0x40140; zbuf = 0x30000160; scis = (0xfULL << 43) | 0x7800;
        p = &D_00341030;
        break;
    }
    func_00134408();
    func_00134428(0x4c, frame);
    func_00134428(0x4e, zbuf);
    func_00134428(0x47, 0x30003);
    func_00134428(0x18, scis);
    func_00134428(0x40, cl1);
    func_00134450(1);
    func_001342c8(p, 3, 0x13000000);
    func_00134408();
    func_00134428(0x47, 0x5000d);
    func_00134428(0x42, (1ULL << 39) | 0x44);
    func_00134428(0x40, cl2);
    func_00134450(1);
    D_00340ed8[0] = frame;
    D_00340ed8[1] = zbuf;
    D_00340ed8[2] = 0x5000d;
    D_00340ed8[3] = (1ULL << 39) | 0x44;
}
}  // namespace n0010a918

// 0010ab08 (from src/anon/batch_w39.cpp)
namespace n0010ab08 {
extern u8 D_00341060[] asm("D_00341060");
extern u8 D_00341270[] asm("D_00341270");
extern u8 D_00341480[] asm("D_00341480");
void func_001342c8(void*, int, u32) asm("func_001342c8");
void func_0010ab08(int n) asm("func_0010ab08");
void func_0010ab08(int n) {
    switch (n) {
    case 0: func_001342c8(D_00341060, 33, 0x13000000); break;
    case 1: func_001342c8(D_00341270, 33, 0x13000000); break;
    case 2: func_001342c8(D_00341480, 33, 0x13000000); break;
    }
}
}  // namespace n0010ab08

// 0010ab80 (from src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n0010ab80 {
u32 func_001342c8(u32, u32, u32, u32) asm("func_001342c8");
extern u8 D_003a8ed0 asm("D_003a8ed0");
u32 func_0010ab80(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0010ab80");
u32 func_0010ab80(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001342c8((u32)&D_003a8ed0, 0x00000017u, 0x13000000u, a3);
}
}  // namespace n0010ab80

// 0010aba8 (from src/anon/tiny.cpp)
namespace n0010aba8 {
// 0014e280: moved to src/anon/unit_0014d680.cpp
// 00159220: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/lightcyclecamera.cpp
// 00159cc0: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/talkcamera.cpp
// 0015a7d0: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/targetcamera.cpp

// merged from: tiny_patterns.cpp
// 00102e90: moved to src/common/title.cpp

// 00103560: moved to src/common/unit_001031b0.cpp

// 00103570: Tz::LoadDataGetSystem, moved to src/common/unit_001031b0.cpp

// 00103580: MENU::GetObjAllocator, moved to src/common/unit_001031b0.cpp

// 00103b38: MENU::isRunning, moved to src/common/unit_001031b0.cpp

// 00103c70: moved to src/common/unit_001031b0.cpp

// 00103c80: MENU::SetMapJump, moved to src/common/unit_001031b0.cpp

// 00103ea0: moved to src/common/unit_001031b0.cpp

// 001041a0: moved to src/common/gumibattle.cpp

// 001041f0: moved to src/common/gumibattle.cpp

// 00104288: moved to src/common/gumibattle.cpp

// 00104600: moved to src/common/gumimenu.cpp

// 001050b8: moved to src/common/area.cpp

// 001050c8: moved to src/common/area.cpp

// 00105a10: moved to src/common/unit_00105a10.cpp

// 00105c30: moved to src/common/region.cpp

// 001069a8: moved to src/naka/libkn/camera.cpp

// 001069e8: moved to src/naka/libkn/camera.cpp

// 00106a08: moved to src/naka/libkn/camera.cpp

// 00106ab8: moved to src/naka/libkn/camera.cpp

u32 func_0010aba8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0010aba8");
u32 func_0010aba8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_34ed4
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0034u << 16);
    return (u32)(*(u32*)((u32)b + (3796)));
}
}  // namespace n0010aba8

// 0010abb8 (from src/anon/tiny_more3.cpp)
namespace n0010abb8 {
extern u32 D_00340ed4 asm("D_00340ed4");
// 00102fa0: moved to src/common/title.cpp

u32 func_0010abb8(u32 a0,u32 a1,u32 a2,u32 a3) asm("func_0010abb8");
u32 func_0010abb8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 old=D_00340ed4; D_00340ed4=a0; return old; }
}  // namespace n0010abb8

// 0010abc8 (from src/anon/batch_w3.cpp)
namespace n0010abc8 {
extern u32 D_00340ea8 asm("D_00340ea8");
u32 func_0010abc8(u32 size) asm("func_0010abc8");
u32 func_0010abc8(u32 size) {  // bump_alloc
    u32 p = D_00340ea8;
    D_00340ea8 = p + ((size + 3) & ~3);
    return p;
}
}  // namespace n0010abc8

// 0010abf0 (from src/anon/batch_wcx2.cpp)
namespace n0010abf0 {
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
// 4x4 matrix copy: hand-written lq/sq through t0-t3 (as in the original).
#define MCOPY10abf0(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
    "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct Mtx10abf0 {
    f32 m[16];
    Mtx10abf0& operator=(const Mtx10abf0& o) {
        if (this != &o) MCOPY10abf0(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Blk10abf0 { u32 flags; u32 f4; u64 q[6]; };
union BlkU10abf0 { Blk10abf0 b; u8 c; };
union LP10abf0 { u32* p; u8 c; };
union Id10abf0 { s16 v; u8 c; };
union IP10abf0 { Id10abf0* p; u8 c; };
struct Ent10abf0 {
    LP10abf0 list;
    union { void* p; u8 c; } key;
    IP10abf0 ids;
    u32 pad12;
    Blk10abf0 blk;
    u8 pad72[8];
    Mtx10abf0 m1;
    Mtx10abf0 m2;
    Mtx10abf0 m3;
    u32 f272;
    u8 pad276[12];
};
extern u32 D_0033cc68_x13907 asm("D_0033cc68");
extern Ent10abf0* D_0033cc70_x13908 asm("D_0033cc70");
void* func_0010abc8(u32 size) asm("func_0010abc8");
void func_0010abf0(void* key, Mtx10abf0* m1, BlkU10abf0* blk, Id10abf0* ids, Mtx10abf0* m2, Mtx10abf0* m3, u32* list, u32 v) asm("func_0010abf0");
void func_0010abf0(void* key, Mtx10abf0* m1, BlkU10abf0* blk, Id10abf0* ids, Mtx10abf0* m2, Mtx10abf0* m3, u32* list, u32 v)
{
    u32 i;
    s32 n, k;
    Ent10abf0* e;

    for (i = 0; i < D_0033cc68_x13907; i++) {
        if (D_0033cc70_x13908[i].key.p == 0) break;
    }
    e = &D_0033cc70_x13908[i];
    e->key.p = key;
    n = 0;
    if (list[0] != 0) {
        do n++; while (list[n] != 0);
    }
    if (n == 0) return;
    e->list.p = (u32*)func_0010abc8(n * 4 + 4);
    for (k = 0; k < n; k++) e->list.p[k] = list[k];
    e->list.p[k] = 0;
    n = 0;
    if (ids[0].v != -1) {
        do n++; while (ids[n].v != -1);
    }
    e->ids.p = (Id10abf0*)func_0010abc8(n * 2 + 2);
    for (k = 0; k < n; k++) e->ids.p[k].v = ids[k].v;
    e->ids.p[k].v = -1;
    e->blk = blk->b;
    e->blk.flags |= 0x10000;
    e->m1 = *m1;
    e->m2 = *m2;
    e->m3 = *m3;
    e->f272 = v;
}
}  // namespace n0010abf0

// 0010ae90 (from src/anon/tiny.cpp)
namespace n0010ae90 {
extern u32 D_00340ed8 asm("D_00340ed8");
// 001070c8: moved to src/naka/libkn/camera.cpp

u32 func_0010ae90(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0010ae90");
u32 func_0010ae90(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_table_34ed8
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_00340ed8;
}
}  // namespace n0010ae90

namespace n0010aea0 {
s32 func_0010aea0(u32 n) asm("func_0010aea0");
s32 func_0010aea0(u32 n) {  // never written before: number of doublings of 1 below n
    s32 r = 0;
    for (u32 i = 1; i < n; i <<= 1) r++;
    return r;
}
}  // namespace n0010aea0

// 0010aed8 (from src/anon/tiny_more2.cpp)
namespace n0010aed8 {
extern u32 D_00341698 asm("D_00341698");
u32 func_0010aed8(u32 a0,u32 a1,u32 a2,u32 a3) asm("func_0010aed8");
u32 func_0010aed8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00341698 + ((u32)a0 << 2) + (0)); }
}  // namespace n0010aed8

