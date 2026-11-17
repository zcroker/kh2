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

// ---- 001c2b58 from src/anon/tiny_auto80_fptr4.cpp
namespace n001c2b58 {
extern u8 D_0032fc87 asm("D_0032fc87");
u32 func_001c2b58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c2b58jjjj");
u32 func_001c2b58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0032fc87;
    r4 = (u32)(r4 + r15);
    r2 = r4;
    return r2;
}
}  // namespace n001c2b58

// ---- 001c2b70 from src/anon/batch_w12.cpp
namespace n001c2b70 {
extern s32 D_01d49530[8] asm("D_01d49530");
extern s32 D_01d49550 asm("D_01d49550");
void func_001c2b70(void) asm("func_001c2b70");
void func_001c2b70(void) {
    s32* p = D_01d49530;
    s32 i = 7;
    do {
        *p = 0;
        i--;
        asm volatile("nop\n\tnop\n\tnop");
        p++;
    } while (i >= 0);
    D_01d49550 = 0;
}
}  // namespace n001c2b70

// ---- 001c2ba8 from src/anon/batch_w29.cpp
namespace n001c2ba8 {
u32 func_001dc9d0(u32) asm("func_001dc9d0");
extern u32 D_01d49530[] asm("D_01d49530");
void func_001c2ba8(void) asm("func_001c2ba8");
void func_001c2ba8(void) {
    u32* p = D_01d49530;
    for (s32 i = 7; i >= 0; i--) {
        if (*p && !func_001dc9d0(*p)) *p = 0;
        p++;
    }
}
}  // namespace n001c2ba8

// ---- 001c2c00 from src/anon/batch_w60.cpp
namespace n001c2c00 {
extern void* D_01d49530[8] asm("D_01d49530");
extern s32 D_01d49550 asm("D_01d49550");
void func_001dc978(void*, f32) asm("func_001dc978");
void func_001c2c00(void* x) asm("func_001c2c00");
void func_001c2c00(void* x) {
    void* o = D_01d49530[D_01d49550];
    if (o) func_001dc978(o, 4.0f);
    D_01d49530[D_01d49550] = x;
    D_01d49550 = (D_01d49550 + 1) % 8;
}
}  // namespace n001c2c00

// ---- 001c2c98 from src/anon/batch_w28.cpp
namespace n001c2c98 {
void func_001d7cd0(void*) asm("func_001d7cd0");
extern u8 D_00351468[] asm("D_00351468");
void func_001c2c98(u8* p) asm("func_001c2c98");
void func_001c2c98(u8* p) {
    func_001d7cd0(p);
    *(void**)p = D_00351468;
    *(u32*)(p + 0x588) |= 0x200000;
    *(u32*)(p + 0xabc) |= 4;
}
}  // namespace n001c2c98

// ---- 001c2ce8 from src/anon/batch_w29.cpp
namespace n001c2ce8 {
void func_001d7cd0(void*) asm("func_001d7cd0");
extern u8 D_00351468[] asm("D_00351468");
void func_001c2ce8(u8* p) asm("func_001c2ce8");
void func_001c2ce8(u8* p) {
    func_001d7cd0(p);
    *(void**)p = D_00351468;
    *(u32*)(p + 1416) |= 0x200000;
    *(u32*)(p + 2748) |= 4;
}
}  // namespace n001c2ce8

// ---- 001c2d38 from src/anon/tiny.cpp
namespace n001c2d38 {
void func_001c2d38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c2d38jjjj");
void func_001c2d38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-27304)) = (u32)a0;
}
}  // namespace n001c2d38

// ---- 001c2d48 from src/anon/batch_w6.cpp
namespace n001c2d48 {
void func_002fd248(u32, void*, u32, u32, void*) asm("func_002fd248");
extern u32* D_01d49558 asm("D_01d49558");
extern u8 D_00320c08 asm("D_00320c08");
void func_001c2d48(u32 a) asm("func_001c2d48");
void func_001c2d48(u32 a) {
    u32* p = D_01d49558;
    func_002fd248(a, p + 2, p[1], 8, &D_00320c08);
}
}  // namespace n001c2d48

// ---- 001c2d78 from src/anon/tiny.cpp
namespace n001c2d78 {
void func_001c2d78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c2d78jjjj");
void func_001c2d78(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-27300)) = (u32)a0;
}
}  // namespace n001c2d78

// ---- 001c2d88 from src/anon/batch_w263.cpp
namespace n001c2d88 {
extern u8 D_0032e020[] asm("D_0032e020");
void* func_00189200(void*, u8) asm("func_00189200");
void* func_00188fe0(void*, u8) asm("func_00188fe0");
void func_00188958(void*, u8) asm("func_00188958");
void func_001891b8(void*, u16) asm("func_001891b8");
void func_001a3188(u32, u8, u32) asm("func_001a3188");
void func_001c2d88(u8* p) asm("func_001c2d88");
void func_001c2d88(u8* p) {
    u8* s1;
    void* s2;
    s1 = 0;
    s2 = 0;
    if (p[2] & 0x80) {
        s2 = func_00189200(D_0032e020, p[2] % 128);
    } else {
        s1 = (u8*)func_00188fe0(D_0032e020, p[2]);
    }
    if (s1) {
        s1[5] = s1[4] = p[3];
        s1[7] = s1[6] = p[4];
        s1[8] = p[5];
        s1[9] = p[6];
        s1[10] = p[7];
        s1[11] = p[8];
        s1[16] = p[9];
        s1[17] = p[10];
        func_00188958(s1, p[11]);
    }
    for (s32 n = 0; n < 32; n++) {
        u16 v = ((u16*)(p + 12))[n];
        if (v) {
            if (s2 == 0) func_001a3188(v & 0xffff7fff, p[2], v >> 15);
            else func_001891b8(s2, v);
        }
    }
}
}  // namespace n001c2d88

// ---- 001c2eb8 from src/anon/batch_w89.cpp
namespace n001c2eb8 {
struct CEnt { u16 id; u8 pad[126]; };
struct CTbl { u32 f0; s32 count; CEnt e[1]; };
extern CTbl* D_01d4955c asm("D_01d4955c");
void func_001c2d88(CEnt*) asm("func_001c2d88");
static inline CEnt* FindC(u32 id) {
    CTbl* t = D_01d4955c;
    s32 n = t->count;
    CEnt* p = t->e;
    for (s32 i = 0; i < n; i++, p++)
        if (p->id == id) return p;
    return 0;
}
void u_call4_001c2eb8(u32, u32, u32, u32) asm("_Z16u_call4_001c2eb8jjjj");
void u_call4_001c2eb8(u32 id, u32, u32, u32) {
    CEnt* p = FindC(id);
    while (p < &D_01d4955c->e[D_01d4955c->count] && p->id == id) {
        func_001c2d88(p);
        p++;
    }
}
}  // namespace n001c2eb8

// ---- 001c2f90 from src/anon/batch_w79.cpp
namespace n001c2f90 {
struct S1c2 {
    u32 w[8];
    u8 b32[5];
    u8 pad37[3];
    u32 f40;
    u8 b44, b45, b46, b47;
    u8 b48;
    u8 pad49[3];
    u32 f52;
    f32 f56, f60, f64;
    s16 h68, h70, h72, h74, h76, h78, h80, h82;
    u32 f84, f88;
    f32 f92, f96;
    u32 f100, f104;
    f32 f108, f112;
    u32 f116;
};
void func_001c2f90(struct S1c2* p, u32 a) asm("func_001c2f90");
void func_001c2f90(struct S1c2* p, u32 a) {
    s32 i;
    p->f40 = a;
    for (i = 0; i < 8; i++) p->w[i] = 0;
    for (i = 0; i < 5; i++) p->b32[i] = 0;
    p->f52 = 0;
    p->b45 = 3;
    p->b46 = 1;
    p->f56 = 1.0f;
    p->f60 = 1.0f;
    p->f64 = 1.0f;
    p->b48 = 0;
    p->h68 = 100;
    p->h70 = 100;
    p->f84 = 0;
    p->f88 = 0;
    p->f92 = 1.0f;
    p->f96 = 1.0f;
    p->f100 = 0;
    p->f104 = 0;
    p->h74 = 0;
    p->h76 = 0;
    p->h78 = 0;
    p->h80 = 0;
    p->f108 = 1.0f;
    p->b44 = 3;
    p->b47 = 1;
    p->h72 = 100;
    p->f112 = 1.0f;
    p->h82 = 0;
    p->f116 = 0;
}
}  // namespace n001c2f90

// ---- 001c3060 from src/anon/batch_w87.cpp
namespace n001c3060 {
void* func_001a80c8(u16) asm("func_001a80c8");
void func_001c3150(void*, u16) asm("func_001c3150");
void func_001c35a0(void*) asm("func_001c35a0");
struct O40 { u8 pad[580]; u8* a; u16* b; };
static inline __attribute__((always_inline)) void slots_a(u8* p, u8* a, u16* b) {
    if (a) {
        u16* e;
        s32 i;
        for (i = 0, e = (u16*)(a + 80); i < 80; i++, e++) {
            if (((u32)e[2] & 0xffff) >> 15) {
                u8* r = (u8*)func_001a80c8(e[2] & 0x7fff);                       
                if (!r[6] || !b) func_001c3150(p, e[2] & 0x7fff);
            }
        }
    }
}
static inline __attribute__((always_inline)) void slots_b(u8* p, u16* b) {
    if (b) {
        u16* e;
        s32 i;
        for (i = 0, e = b + 4; i < 24; i++) {
            if (((u32)*e & 0xffff) >> 15) func_001c3150(p, *e & 0x7fff);
            e++;
        }
    }
}
void func_001c3060(u8* p) asm("func_001c3060");
void func_001c3060(u8* p) {
    O40* o = *(O40**)(p + 40);
    u8* a = o->a;
    u16* b = o->b;
    slots_a(p, a, b);
    slots_b(p, b);
    func_001c35a0(p);
}
}  // namespace n001c3060

// ---- 001c3150 from src/anon/batch_wcx2.cpp
namespace n001c3150 {
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
struct Stat1c3 {
    u32 abil[11];
    u8 c44, c45, c46, c47, c48;
    u8 pad49[3];
    f32 f52, f56, f60, f64;
    u16 h68, h70, h72, h74, h76, h78, h80, h82;
    f32 f84, f88, f92, f96, f100, f104, f108, f112, f116;
};
struct Prm1c3 {
    u8 pad[284];
    u16 h284; u16 pad286;
    f32 f288, f292, f296, f300;
    u16 h304; u16 pad306;
    u16 h308; u16 pad310;
    f32 f312, f316, f320;
    u8 pad324[4];
    u8 b328; u8 pad329[3];
    u16 h332; u16 pad334;
    f32 f336, f340, f344, f348, f352;
    u16 h356; u16 pad358;
    u8 pad360[4];
    f32 f364, f368, f372;
};
struct Item1c3 { u8 pad[4]; u16 abil; };
extern Prm1c3* D_00352130_3150 asm("D_00352130");
Item1c3* func_001a80c8_3150(s32 id) asm("func_001a80c8");
void func_001c3150(Stat1c3* s, s32 id) asm("func_001c3150");
void func_001c3150(Stat1c3* s, s32 id) {
    switch (id) {
    case 0:
        return;
    case 162: s->c44++; break;
    case 163: s->c45++; break;
    case 393: s->c46++; break;
    case 401: s->c47++; break;
    case 390: s->h74 += D_00352130_3150->h304; break;
    case 391: s->h76 += D_00352130_3150->h304; break;
    case 392: s->h78 += D_00352130_3150->h308; break;
    case 394:
        s->c44--;
        s->c45--;
        break;
    case 395: s->h82 += D_00352130_3150->h284; break;
    case 396: s->f84 += D_00352130_3150->f312; break;
    case 397: s->f60 += D_00352130_3150->f316; break;
    case 398: s->f64 *= D_00352130_3150->f320; break;
    case 399: s->f108 *= D_00352130_3150->f364; break;
    case 400: s->f96 *= D_00352130_3150->f344; break;
    case 405: s->f52 += D_00352130_3150->f300; break;
    case 406: s->f100 += D_00352130_3150->f348; break;
    case 407: s->f104 += D_00352130_3150->f352; break;
    case 408: s->h68 += D_00352130_3150->h332; break;
    case 409: s->h70 += D_00352130_3150->h332; break;
    case 410: s->h72 += D_00352130_3150->h332; break;
    case 411: s->h80 += D_00352130_3150->h356; break;
    case 412: s->f88 += D_00352130_3150->f336; break;
    case 413: s->f56 += D_00352130_3150->f288; break;
    case 414: s->c48 += D_00352130_3150->b328; break;
    case 419: s->f92 *= D_00352130_3150->f340; break;
    case 421: s->f56 += D_00352130_3150->f292; break;
    case 422: s->f56 += D_00352130_3150->f296; break;
    case 540: s->f112 *= D_00352130_3150->f368; break;
    case 542: s->f116 += D_00352130_3150->f372; break;
    }
    u32 a = func_001a80c8_3150(id)->abil;
    u32* p = s->abil;
    p += a >> 5;
    *p |= 1 << (a & 31);
}
}  // namespace n001c3150

// ---- 001c35a0 from src/anon/batch_w42.cpp
namespace n001c35a0 {
extern u8 D_0036dde8[5][5] asm("D_0036dde8");
void func_001c35a0(u32* bits) asm("func_001c35a0");
void func_001c35a0(u32* bits)
{
    for (s32 i = 0; i < 5; i++) {
        for (s32 j = 4; j >= 0; j--) {
            u8 id = D_0036dde8[i][j];
            if (bits[id >> 5] & (1 << (id & 31))) {
                *(u8*)(i + (u32)bits + 32) = j + 1;
                break;
            }
        }
    }
}
}  // namespace n001c35a0

// ---- 001c3618 from src/anon/tiny_auto80_queue.cpp
namespace n001c3618 {
u32 func_00191c50(...) asm("func_00191c50");
u32 func_001c3618(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001c3618jjjjjjjj");
u32 func_001c3618(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16, r17;
    r16 = r5;
    r17 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00191c50)(r4, r5, r6, r7, r8, r9, r10, r11);
    r16 = (u32)(r16 + r17);
    r15 = (u32)((s32)0u + (5));
    if (r2 == 0u) {
        r15 = (u32)(*(u8*)((u32)r16 + (s32)(32)));
    }
    r2 = r15;
    return r2;
}
}  // namespace n001c3618

// ---- 001c3660 from src/anon/tiny.cpp
namespace n001c3660 {
void func_001c3660(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c3660jjjj");
void func_001c3660(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-27296)) = (u32)a0;
}
}  // namespace n001c3660

// ---- 001c3670 from src/anon/batch_wcx2.cpp
namespace n001c3670 {
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
struct E_001c3670 { u16 id; u8 pad[6]; };
struct T_001c3670 { u32 x; s32 n; E_001c3670 e[1]; };
extern T_001c3670* D_01d49560 asm("D_01d49560");
extern u32 D_0032fca8[] asm("D_0032fca8");
void func_001c3670(u32 id) asm("func_001c3670");
void func_001c3670(u32 id) {
    T_001c3670* t = D_01d49560;
    E_001c3670* e = t->e;
    for (s32 i = 0; i < t->n; i++, e++) {
        if (e->id == id) break;
    }
    u32 m = 1 << (id & 31);
    u32* b = D_0032fca8;
    b[id >> 5] |= m;
    b += 4;
    b[id >> 5] |= m;
}
}  // namespace n001c3670

// ---- 001c36e8 from src/anon/auto80_199_queue.cpp
namespace n001c36e8 {
u32 func_00320c18(u32, u32) asm("_Z13func_00320c18jj");
extern u32 D_01d49560 asm("D_01d49560");
extern u32 D_0032fcb8[] asm("D_0032fcb8");
void func_001c36e8(u32 a0) asm("_Z13func_001c36e8j");
void func_001c36e8(u32 a0) {
    u32 s0 = a0;
    func_00320c18(D_01d49560, s0);

    u32 idx = s0 >> 5;
    u32* bits = &D_0032fcb8[idx];
    u32 bit = 1u << (s0 & 31);
    *bits = *bits & ~bit;
}
}  // namespace n001c36e8

// ---- 001c3748 from src/anon/batch_w96.cpp
namespace n001c3748 {
struct Ent_w96 { u16 id; u8 kind; u8 pad[5]; };
struct EntTbl_w96 { u32 hdr; s32 count; Ent_w96 ents[1]; };
extern EntTbl_w96* D_01d49560 asm("D_01d49560");
s32 func_001c3850(Ent_w96*) asm("func_001c3850");
Ent_w96* func_001c3748(u32 kind, Ent_w96* e) asm("func_001c3748");
Ent_w96* func_001c3748(u32 kind, Ent_w96* e) {
    if (e == 0) {
        s32 i;
        for (i = 0; i < D_01d49560->count; i++) {
            if (D_01d49560->ents[i].kind == kind) {
                e = &D_01d49560->ents[i];
                break;
            }
        }
    } else {
        e++;
    }
    for (; e != 0 && e < &D_01d49560->ents[D_01d49560->count] && e->kind == kind; e++) {
        if (func_001c3850(e)) return e;
    }
    return 0;
}
}  // namespace n001c3748

// ---- 001c3850 from src/anon/tiny_auto80_fptr4.cpp
namespace n001c3850 {
extern u8 D_0032fca8 asm("D_0032fca8");
u32 func_001c3850(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c3850jjjj");
u32 func_001c3850(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r12, r13, r14, r15;
    r14 = (u32)(*(u16*)((u32)r4 + (s32)(0)));
    r15 = (u32)&D_0032fca8;
    r12 = (u32)((s32)0u + (1));
    r13 = (u32)(r14 >> 5);
    r13 = (u32)(r13 << 2);
    r14 = (u32)(r14 & 0x001fu);
    r13 = (u32)(r13 + r15);
    r12 = (u32)(r12 << (r14 & 31));
    r2 = *(u32*)((u32)r13 + (s32)(0));
    r2 = (u32)(r2 & r12);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace n001c3850

// ---- 001c3888 from src/anon/tiny_auto80_fptr4.cpp
namespace n001c3888 {
extern u8 D_0032fcb8 asm("D_0032fcb8");
u32 func_001c3888(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c3888jjjj");
u32 func_001c3888(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r12, r13, r14, r15;
    r14 = (u32)(*(u16*)((u32)r4 + (s32)(0)));
    r15 = (u32)&D_0032fcb8;
    r12 = (u32)((s32)0u + (1));
    r13 = (u32)(r14 >> 5);
    r13 = (u32)(r13 << 2);
    r14 = (u32)(r14 & 0x001fu);
    r13 = (u32)(r13 + r15);
    r12 = (u32)(r12 << (r14 & 31));
    r2 = *(u32*)((u32)r13 + (s32)(0));
    r2 = (u32)(r2 & r12);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace n001c3888

