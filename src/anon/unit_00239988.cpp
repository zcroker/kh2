// Linked unit 0x00239988-0x0023bc58: YI::SEQUENCE (gap functions written here).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../ishi/sequence.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_obj.hpp"
#include "../tozawa/layout.hpp"
#include "../tozawa/laymsg.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/mcard.hpp"

// 00239988 (was src/anon/batch_w275.cpp)
namespace n00239988 {
// 00228618: moved to src/anon/unit_00228618.cpp (linked unit)
void func_00237280(void*, void*) asm("func_00237280");
void func_002373a8(void*) asm("func_002373a8");
void func_00239fd0(void*, f32, f32, f32, f32) asm("func_00239fd0");
void func_00239d50(void*, f32) asm("func_00239d50");
void func_00239da0(void*, f32) asm("func_00239da0");
void func_00239df0(void*, f32) asm("func_00239df0");
void func_00239e60(void*, f32, f32, f32) asm("func_00239e60");
union U9 { u32 u; s32 s; u8 c; };
#define R(o) (((U9*)(d + (o)))->s)
#define W(o) (*(u32*)(p + (o)))
/*TARGET 00239988*/
s32 YI__SEQUENCE__Init(u8* p, u8* d) asm("YI__SEQUENCE__Init");
s32 YI__SEQUENCE__Init(u8* p, u8* d) {
    func_00237280(p, d);
    W(16) &= ~1;
    W(16) &= ~4;
    W(184) &= ~8;
    W(176) = (u32)(d + R(36));
    W(180) = (u32)(d + R(44));
    W(244) = R(32);
    W(248) = R(40);
    W(224) = 0x80808080;
    W(184) &= ~1;
    W(184) &= ~2;
    W(184) &= ~4;
    W(276) = -1;
    *(f32*)(p + 216) = 1.0f;
    *(f32*)(p + 220) = 1.0f;
    W(256) = 0;
    W(268) = 0;
    p[212] = 0;
    W(228) = 0;
    W(232) = 0;
    p[188] = 0;
    W(196) = 0;
    W(200) = 0;
    W(204) = 0;
    W(236) = 0;
    W(240) = 0;
    func_002373a8(p);
    *(f32*)(p + 68) = 1.0f;
    *(f32*)(p + 260) = 0.0f;
    func_00239fd0(p, 1.0f, 1.0f, 1.0f, 1.0f);
    func_00239d50(p, 0.0f);
    func_00239da0(p, 0.0f);
    func_00239df0(p, 0.0f);
    func_00239e60(p, 1.0f, 1.0f, 1.0f);
    W(328) = 0;
    W(332) = 0;
    W(252) = 0;
    return 1;
}
}  // namespace n00239988

// 00239af8 (was src/anon/auto80_199_queue.cpp)
namespace n00239af8 {
/*TARGET 00239af8*/
// 0x00236c38: definition moved into src/anon/unit_00236180.cpp

u32 func_00239af8(void* a0, u32 a1) asm("_Z13func_00239af8Pvj");
// 0x00236c38: definition moved into src/anon/unit_00236180.cpp

u32 func_00239af8(void* a0, u32 a1) {
    u8* s0;
    u8* s1;
    s32 v0;
    s32 t6;
    s32 t7;

    s1 = (u8*)a0;
    v0 = (s32)func_00239b50(a0, a1);  // find_entry_in_group

    s0 = (u8*)(a1 * 36u);
    s0 = (u8*)((u32)s0 + *(u32*)(s1 + 0xb4));
    t6 = *(s32*)(s0 + 0xc);
    v0 -= 1;
    if (t6 != 0) {
        t7 = (t6 < v0) ? 1 : 0;
        if (t7 != 0) {
            v0 = t6;
        }
    }
    return (u32)v0;
}
}  // namespace n00239af8

// 00239b50 (was src/anon/batch_w36.cpp)
namespace n00239b50 {
// 0x002384f8: definition moved into src/anon/unit_002384f8.cpp

struct Ent144 { u32 flags; u32 pad[2]; s32 v; u8 pad2[128]; };
struct Rng36 { u16 first, count; u8 pad[32]; };
/*TARGET 00239b50*/
s32 func_00239b50(u8* p, s32 i) asm("func_00239b50");
s32 func_00239b50(u8* p, s32 i) {  // find_entry_in_group
    Rng36* r = &(*(Rng36**)(p + 180))[i];
    Ent144* e = &(*(Ent144**)(p + 176))[r->first];
    s32 n = r->count;
    s32 m = 0;
    for (; n > 0; n--, e++) {
        s32 v = e->v;
        if (m < v) {
            if (e->flags & 0x8000) m = v - 1;
            else m = v;
        }
    }
    return m + 1;
}
}  // namespace n00239b50

// 00239bb8 (was src/anon/tiny_auto80_queue.cpp)
namespace n00239bb8 {
extern u8  D_00350000 asm("D_00350000");
s32 func_00239b50(...) asm("func_00239b50");
/*TARGET 00239bb8*/
// 0x00237a68: definition moved into src/anon/unit_00237068.cpp

f32 func_00239bb8(u8* a0) asm("_Z13func_00239bb8Ph");
// 0x00237a68: definition moved into src/anon/unit_00237068.cpp

f32 func_00239bb8(u8* a0) {
    u8* s0 = a0;
    s32 v0 = func_00239b50((u32)a0);  // find_entry_in_group
    f32 f0 = (f32)v0;
    f32 f1 = *(f32*)((u8*)&D_00350000 - 25068u);
    f32 f2 = *(f32*)(s0 + 68);
    f0 = f0 * f1;
    f0 = f0 * f2;
    return f0;
}
}  // namespace n00239bb8

// 00239bf8 (was src/anon/tiny_auto80_queue.cpp)
namespace n00239bf8 {
u32 func_00239c68(...) asm("func_00239c68");
/*TARGET 00239bf8*/
void func_00239bf8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00239bf8jjjjjjjj");
void func_00239bf8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r15 = ((u32*)(u32)r4)[69];
    r16 = r4;
    if (r15 != r5) {
        ((void(*)())func_00239c68)();
        r15 = (u32)((s32)0u + (1));
        ((u32*)(u32)r16)[65] = 0u;
        ((u32*)(u32)r16)[63] = r15;
    }
}
}  // namespace n00239bf8

// 00239c38 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00239c38 {
u32 func_00239c38(u32, u32, u32, u32) asm("_Z13func_00239c38jjjj");
u32 func_00239c68(u32, u32, u32, u32) asm("_Z13func_00239c68jjjj");
/*TARGET 00239c38*/
// 0x001e51f0: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00239c38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00239c38jjjj");
// 0x001e51f0: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00239c38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00239c68(r4, r5, r6, r7);
    r15 = (u32)((s32)0u + (1));
    *(u32*)((u32)r16 + (s32)(260)) = 0u;
    *(u32*)((u32)r16 + (s32)(252)) = r15;
    return r2;
}
}  // namespace n00239c38

// 00239c68 (was src/anon/batch_w62.cpp)
namespace n00239c68 {
// 0x002278e0: definition moved into src/anon/unit_00224780.cpp

struct E239 { u8 pad[4]; u16 h4; u16 pad2; u32 f8; u8 pad3[24]; };
struct S239 {
    u8 pad[180]; E239* tbl; u8 pad1[4]; u8 bc; u8 pad2[71];
    f32 f104; f32 f108; s32 f10c; u8 pad3[4]; u32 f114; u8 pad4[40]; u32 f140; u32 f144;
};
s32 func_00239af8(S239*, u32) asm("func_00239af8");
void ctarget_00239c68(S239* p, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_00239c68jjjj");
/*TARGET 00239c68*/
void ctarget_00239c68(S239* p, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_00239c68jjjj");
void ctarget_00239c68(S239* p, u32 a1, u32 a2, u32 a3) {
    p->bc = 0;
    E239* e = &p->tbl[a1];
    p->f114 = a1;
    p->f140 = e->h4;
    p->f144 = e->f8;
    f32 v = func_00239af8(p, a1);
    p->f108 = v;
    if (v < p->f104) p->f104 = v;
    p->bc = 0;
    p->f10c = 0;
    p->f108 += 1.0f;
}
}  // namespace n00239c68

// 00239cf0 (was src/anon/auto200_999.cpp)
namespace n00239cf0 {
/*TARGET 00239cf0*/
// 002e9a00: moved to src/anon/unit_002e9a00.cpp

u32 func_00239cf0(u32 a0) asm("_Z13func_00239cf0j");
// 002e9a00: moved to src/anon/unit_002e9a00.cpp

u32 func_00239cf0(u32 a0) {
    s32 idx = *(s32 *)(a0 + 276);
    s32 stride = 36;
    u32 base = *(u32 *)(a0 + 180);
    idx = idx * stride;
    u32 p = idx + base;
    u32 v = *(u16 *)(p + 2);
    return v < 1;
}
}  // namespace n00239cf0

// 00239d10 (was src/ishi/sequence.cpp)
namespace YI { // method 00239d10
/*TARGET 00239d10*/
u32 SEQUENCE::GetPlayMode() {
    u32 v = *(u32*)((u32)this + 252);
    v = (u32)((s32)v + (-1));
    return (v < 2u);
}
}  // YI

// 00239d20 (was src/ishi/sequence.cpp)
namespace YI { // method 00239d20
/*TARGET 00239d20*/
u32 SEQUENCE::GetDrawMode() { return (*(u32*)((u32)this + 252) != 0); }
}  // YI

// 00239d30 (was src/anon/tiny_auto80_solver.cpp)
namespace n00239d30 {
u32 func_00239d30(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00239d30jjjjjjjj");
/*TARGET 00239d30*/
u32 func_00239d30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00239d30jjjjjjjj");
u32 func_00239d30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)((s32)0u + (36));
    r5 = (u32)(r5 * r15);
    r15 = *(u32*)((u32)r4 + (s32)(180));
    r5 = (u32)(r5 + r15);
    r2 = (u32)(*(u16*)((u32)r5 + (s32)(4)));
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // namespace n00239d30

// 00239d50 (was src/anon/tiny_auto80_queue.cpp)
namespace n00239d50 {
/*TARGET 00239d50*/
void func_00239d50(u8* a0, f32 a1) asm("_Z13func_00239d50Phf");
void func_00239d50(u8* a0, f32 a1) {
    u32 t5 = 0;
    *(f32*)(a0 + 296) = a1;
    if (a1 != 0.0f) {
        goto set_one;
    }
    if (*(f32*)(a0 + 300) != 0.0f) {
        t5 = 1;
        goto patch_flags;
    }
    if (*(f32*)(a0 + 304) == 0.0f) {
        goto patch_flags;
    }
set_one:
    t5 = 1;
patch_flags:
    u32 t7 = *(u32*)(a0 + 184);
    u32 t6 = 0xfffffffe;
    t7 = t7 & t6;
    t7 = t7 | t5;
    *(u32*)(a0 + 184) = t7;
}
}  // namespace n00239d50

// 00239da0 (was src/anon/tiny_auto80_queue.cpp)
namespace n00239da0 {
/*TARGET 00239da0*/
void func_00239da0(u8* a0, f32 a1) asm("_Z13func_00239da0Phf");
void func_00239da0(u8* a0, f32 a1) {
    u32 t5 = 0;
    f32 f0 = *(f32*)(a0 + 296);
    *(f32*)(a0 + 300) = a1;
    if (f0 != 0.0f) {
        goto set_one;
    }
    if (a1 != 0.0f) {
        t5 = 1;
        goto patch_flags;
    }
    if (*(f32*)(a0 + 304) == 0.0f) {
        goto patch_flags;
    }
set_one:
    t5 = 1;
patch_flags:
    u32 t7 = *(u32*)(a0 + 184);
    u32 t6 = 0xfffffffe;
    t7 = t7 & t6;
    t7 = t7 | t5;
    *(u32*)(a0 + 184) = t7;
}
}  // namespace n00239da0

// 00239df0 (was src/anon/tiny_auto80_queue.cpp)
namespace n00239df0 {
/*TARGET 00239df0*/
void func_00239df0(u8* a0, f32 a1) asm("_Z13func_00239df0Phf");
void func_00239df0(u8* a0, f32 a1) {
    u32 t5 = 0;
    f32 f0 = *(f32*)(a0 + 296);
    *(f32*)(a0 + 304) = a1;
    if (f0 != 0.0f) {
        goto set_one;
    }
    f0 = *(f32*)(a0 + 300);
    if (f0 != 0.0f) {
        goto set_one;
    }
    if (a1 == 0.0f) {
        goto patch_flags;
    }
set_one:
    t5 = 1;
patch_flags:
    u32 t7 = *(u32*)(a0 + 184);
    u32 t6 = 0xfffffffe;
    t7 = t7 & t6;
    t7 = t7 | t5;
    *(u32*)(a0 + 184) = t7;
}
}  // namespace n00239df0

// 00239e40 (was gap)
namespace n00239e40 {
void func_00239e40(u8* p, f32* x, f32* y, f32* z) asm("func_00239e40");
void func_00239e40(u8* p, f32* x, f32* y, f32* z) {
    *x = *(f32*)(p + 308);
    *y = *(f32*)(p + 312);
    *z = *(f32*)(p + 316);
}
}  // namespace n00239e40

// 00239e60 (was src/anon/batch_w63.cpp)
namespace n00239e60 {
// 0x00232348: definition moved into src/anon/unit_00231500.cpp

struct F184 { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; };
/*TARGET 00239e60*/
void func_00239e60(u8* p, f32 x, f32 y, f32 z) asm("func_00239e60");
void func_00239e60(u8* p, f32 x, f32 y, f32 z) {
    *(f32*)(p + 308) = x;
    *(f32*)(p + 312) = y;
    *(f32*)(p + 316) = z;
    ((F184*)(p + 184))->b1 = !(x == 1.0f && y == 1.0f && z == 1.0f);
}
}  // namespace n00239e60

// 00239eb8 (was src/anon/batch_w39.cpp)
namespace n00239eb8 {
// 0x0022e188: definition moved into src/anon/unit_0022d358.cpp

// --- 00239eb8
// Sets the scale x and flags whether the scale differs from (1, 1, 1).
struct S239 {
    u8 pad[184];
    u32 b0 : 1;
    u32 scaled : 1;
    u8 pad2[308 - 188];
    f32 x, y, z;
};
/*TARGET 00239eb8*/
void func_00239eb8(S239* p, f32 v) asm("func_00239eb8");
void func_00239eb8(S239* p, f32 v) {
    p->x = v;
    p->scaled = !(v == 1.0f && p->y == 1.0f && p->z == 1.0f);
}
}  // namespace n00239eb8

// 00239f18 (was src/anon/batch_w40.cpp)
namespace n00239f18 {
struct F239 { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; };
/*TARGET 00239f18*/
void YI__SEQUENCE__SetScaleX(u8* p, f32 f) asm("YI__SEQUENCE__SetScaleX");
void YI__SEQUENCE__SetScaleX(u8* p, f32 f) {  // obj_set_float312_and_flags
    *(f32*)(p + 312) = f;
    ((F239*)(p + 184))->b1 = !(*(f32*)(p + 308) == 1.0f && f == 1.0f && *(f32*)(p + 316) == 1.0f);
}
}  // namespace n00239f18

// 00239f78 (was src/anon/batch_w64.cpp)
namespace n00239f78 {
// ---------------------------------------------------------------------------
struct Bits239f78 { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; };
/*TARGET 00239f78*/
// Sets the scale z and flags whether the scale differs from (1,1,1).
void func_00239f78(u8* p, f32 f) asm("func_00239f78");
// Sets the scale z and flags whether the scale differs from (1,1,1).
void func_00239f78(u8* p, f32 f) {
    *(f32*)(p + 316) = f;
    s32 b = 0;
    if (!(*(f32*)(p + 308) == 1.0f && *(f32*)(p + 312) == 1.0f && f == 1.0f)) b = 1;
    ((Bits239f78*)(p + 184))->b1 = b;
}
}  // namespace n00239f78

// 00239fd0 (was src/anon/batch_w253.cpp)
namespace n00239fd0 {
// 0x001128d0: definition moved into src/anon/unit_001117d8.cpp


u32 __fixunssfsi(f32) asm("__fixunssfsi");
void wt239(u8* a0, f32 r, f32 g, f32 b, f32 a) asm("_Z16wtarget_00239fd0jjjj");
/*TARGET 00239fd0*/
void wt239(u8* a0, f32 r, f32 g, f32 b, f32 a) asm("_Z16wtarget_00239fd0jjjj");
void wt239(u8* a0, f32 r, f32 g, f32 b, f32 a) {
    *(f32*)(a0 + 280) = r;
    *(f32*)(a0 + 284) = g;
    *(f32*)(a0 + 288) = b;
    *(f32*)(a0 + 292) = a;
    if (r != 1.0f || g != 1.0f || b != 1.0f || a != 1.0f) {
        *(u32*)(a0 + 184) |= 4;
        *(u32*)(a0 + 208) = __fixunssfsi(r * 128.0f) | (__fixunssfsi(g * 128.0f) << 8) | (__fixunssfsi(b * 128.0f) << 16) | (__fixunssfsi(a * 128.0f) << 24);
    } else {
        *(u32*)(a0 + 184) &= ~4;
    }
}
}  // namespace n00239fd0

// 0023a0d8 (was src/anon/batch_w1702_nsa.cpp)
namespace n0023a0d8 {
/* YI::SEQUENCE key (0x90 bytes): each pair is {value at start, value at end} */
struct W1702Key {
    u32 flags;          /* 0x00 */
    s32 pad04;          /* 0x04 */
    s32 start;          /* 0x08 */
    s32 end;            /* 0x0c */
    s32 x[2];           /* 0x10 */
    s32 y[2];           /* 0x18 */
    s32 w[2];           /* 0x20 */
    s32 h[2];           /* 0x28 */
    f32 rx[2];          /* 0x30 */
    f32 ry[2];          /* 0x38 */
    f32 rz[2];          /* 0x40 */
    f32 scale[2];       /* 0x48 */
    f32 sx[2];          /* 0x50 */
    f32 sy[2];          /* 0x58 */
    f32 ease[4];        /* 0x60 */
    f32 ampX[2];        /* 0x70 */
    f32 ampY[2];        /* 0x78 */
    u16 freqX;          /* 0x80 */
    u16 freqY;          /* 0x82 */
    u32 pad84;          /* 0x84 */
    u8 col[2][4];       /* 0x88 */
};
/* YI::SEQUENCE (fields used by the key evaluator) */
struct W1702Seq {
    u8 pad00[0xb8];
    u32 mode;           /* 0xb8 */
    u8 padbc[8];
    W1702Key* keys;     /* 0xc4 */
    s32 numKeys;        /* 0xc8 */
    f32 time;           /* 0xcc */
    u32 padd0;
    u8 active;          /* 0xd4 */
    f32 scaleX;         /* 0xd8 */
    f32 scaleY;         /* 0xdc */
    u32 rgba;           /* 0xe0 */
    s32 posX;           /* 0xe4 */
    s32 posY;           /* 0xe8 */
    u8 padec[0x118 - 0xec];
    f32 colScale[4];    /* 0x118 */
    f32 rot[3];         /* 0x128 */
    f32 scale;          /* 0x134 */
    f32 sx;             /* 0x138 */
    f32 sy;             /* 0x13c */
};
/* the game's own __fixunssfsi (float to u32) asm("__fixunssfsi"); const like the libcall */
u32 __fixunssfsi(f32) asm("__fixunssfsi") __attribute__((const));
f32 sinf(f32) asm("sinf");
/* sinf */
f32 cosf(f32) asm("cosf");
/*TARGET 0023a0d8*/
/* cosf */

/* Finds the active key at seq->time and evaluates color, scale and position. */

void YI__SEQUENCE__UpdateActive(W1702Seq* seq) asm("YI__SEQUENCE__UpdateActive");
/* cosf */

/* Finds the active key at seq->time and evaluates color, scale and position. */

void YI__SEQUENCE__UpdateActive(W1702Seq* seq) {
    seq->active = 1;
    s32 n = seq->numKeys;
    W1702Key* k = seq->keys;
    for (; n > 0; n--, k++) {
        if ((k->flags & 2) == 0) continue;
        /* frame range of the key; the array stays on the stack */
        f32 range[2];
        f32 time = seq->time;
        range[0] = (f32)k->start;
        if (!(range[0] <= time)) continue;
        range[1] = (f32)k->end;
        if (!(time <= range[1])) continue;

        f32 len = range[1] - range[0];
        f32 t;
        if (len == 0.0f) t = 1.0f;
        else t = (time - range[0]) / len;

        u32 flags = k->flags;
        /* ease: cubic Bezier with control points 1, 1 - ease[1], 1 - ease[3], 0 */
        if ((flags & 1) == 0) {
            f32 u = 1.0f - t;
            f32 uu = u * u;
            f32 tt = t * t;
            t = 1.0f - (uu * u + uu * 3.0f * t * (1.0f - k->ease[1]) + u * 3.0f * tt * (1.0f - k->ease[3]) + tt * t * 0.0f);
        }

        u32 mode = seq->mode;
        if (mode & 4) {
            u32 c;
            if ((flags & 0x80) == 0) {
                c = __fixunssfsi((k->col[0][0] + (s32)((k->col[1][0] - k->col[0][0]) * t)) * seq->colScale[0])
                  | (__fixunssfsi((k->col[0][1] + (s32)((k->col[1][1] - k->col[0][1]) * t)) * seq->colScale[1]) << 8)
                  | (__fixunssfsi((k->col[0][2] + (s32)((k->col[1][2] - k->col[0][2]) * t)) * seq->colScale[2]) << 16)
                  | (__fixunssfsi((k->col[0][3] + (s32)((k->col[1][3] - k->col[0][3]) * t)) * seq->colScale[3]) << 24);
            } else {
                c = __fixunssfsi(k->col[0][0] * seq->colScale[0]) | (__fixunssfsi(k->col[0][1] * seq->colScale[1]) << 8)
                  | (__fixunssfsi(k->col[0][2] * seq->colScale[2]) << 16) | (__fixunssfsi(k->col[0][3] * seq->colScale[3]) << 24);
            }
            seq->rgba = c;
        } else if ((flags & 0x80) == 0) {
            seq->rgba = (k->col[0][0] + (s32)((k->col[1][0] - k->col[0][0]) * t))
                      | ((k->col[0][1] + (s32)((k->col[1][1] - k->col[0][1]) * t)) << 8)
                      | ((k->col[0][2] + (s32)((k->col[1][2] - k->col[0][2]) * t)) << 16)
                      | ((k->col[0][3] + (s32)((k->col[1][3] - k->col[0][3]) * t)) << 24);
        } else {
            seq->rgba = *(u32*)k->col[0];
        }

        if (mode & 2) {
            if ((k->flags & 0x40) == 0) {
                f32 s = seq->scale * (k->scale[0] + (k->scale[1] - k->scale[0]) * t);
                seq->scaleX = s * seq->sx * (k->sx[0] + (k->sx[1] - k->sx[0]) * t);
                seq->scaleY = s * seq->sy * (k->sy[0] + (k->sy[1] - k->sy[0]) * t);
            } else {
                seq->scaleX = seq->scale * seq->sx;
                seq->scaleY = seq->scale * seq->sy;
            }
        } else if ((k->flags & 0x40) == 0) {
            seq->scaleX = k->sx[0] + (k->sx[1] - k->sx[0]) * t;
            seq->scaleY = k->sy[0] + (k->sy[1] - k->sy[0]) * t;
        } else {
            seq->scaleX = 1.0f;
            seq->scaleY = 1.0f;
        }

        s32 x = k->x[0] + (s32)((k->x[1] - k->x[0]) * t);
        s32 y = k->y[0] + (s32)((k->y[1] - k->y[0]) * t);
        if ((k->flags & 0x10) == 0) {
            f32 ax = k->ampX[0] + (k->ampX[1] - k->ampX[0]) * t;
            f32 ay = k->ampY[0] + (k->ampY[1] - k->ampY[0]) * t;
            if ((k->flags & 8) == 0) {
                f32 a = t * 3.1415927f;
                x += (s32)(ax * sinf(a * k->freqX));
                y += (s32)(ay * sinf(a * k->freqY));
            } else {
                f32 a = t * 3.1415927f;
                x += (s32)(ax * cosf(a * k->freqX));
                y += (s32)(ay * cosf(a * k->freqY));
            }
        }

        f32 ox = (k->w[0] + (s32)((k->w[1] - k->w[0]) * t)) * seq->scaleX;
        f32 oy = (k->h[0] + (s32)((k->h[1] - k->h[0]) * t)) * seq->scaleY;
        f32 rx, ry, rz;
        /* the original tests this bit without a bool conversion */
        if ((seq->mode & 1) == 1) {
            if ((k->flags & 0x20) == 0) {
                f32 x0 = k->rx[0], y0 = k->ry[0], z0 = k->rz[0];
                rx = x0 + (k->rx[1] - x0) * t + seq->rot[0];
                ry = y0 + (k->ry[1] - y0) * t + seq->rot[1];
                rz = z0 + (k->rz[1] - z0) * t + seq->rot[2];
            } else {
                rx = seq->rot[0];
                ry = seq->rot[1];
                rz = seq->rot[2];
            }
        } else if ((k->flags & 0x20) == 0) {
            f32 x0 = k->rx[0], y0 = k->ry[0], z0 = k->rz[0];
            rx = x0 + (k->rx[1] - x0) * t;
            ry = y0 + (k->ry[1] - y0) * t;
            rz = z0 + (k->rz[1] - z0) * t;
        } else {
            seq->posX = x + (s32)ox;
            seq->posY = y + (s32)oy;
            return;
        }
        f32 sa = sinf(rx);
        f32 ca = cosf(rx);
        f32 sb = sinf(ry);
        f32 cb = cosf(ry);
        f32 sc = sinf(rz);
        f32 cc = cosf(rz);
        f32 sasb = sa * sb;
        f32 nsc = -sc;
        f32 m00 = cb * cc;
        f32 m01 = sasb * cc + ca * sc;
        f32 m10 = cb * nsc;
        f32 m11 = sasb * nsc + ca * cc;
        seq->posX = x + (s32)(ox * m00 + oy * m01);
        seq->posY = y + (s32)(ox * m10 + oy * m11);
        return;
    }
}
}  // namespace n0023a0d8

// 0023a8a8 (was gap)
namespace n0023a8a8 {
u32 YI__SEQUENCE__UpdateActive(...) asm("YI__SEQUENCE__UpdateActive");
f32 func_0023a8a8(u8* a0) asm("func_0023a8a8");
f32 func_0023a8a8(u8* a0) {
    u8* s0 = a0;
    if (*(u8*)(a0 + 212) == 0) {
        YI__SEQUENCE__UpdateActive((u32)a0);
    }
    return *(f32*)(s0 + 216);
}
}  // namespace n0023a8a8

// 0023a8e0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023a8e0 {
u32 YI__SEQUENCE__UpdateActive(...) asm("YI__SEQUENCE__UpdateActive");
/*TARGET 0023a8e0*/
f32 func_0023a8e0(u8* a0) asm("_Z13func_0023a8e0Ph");
f32 func_0023a8e0(u8* a0) {
    u8* s0 = a0;
    if (*(u8*)(a0 + 212) == 0) {
        YI__SEQUENCE__UpdateActive((u32)a0);
    }
    return *(f32*)(s0 + 220);
}
}  // namespace n0023a8e0

// 0023a918 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023a918 {
u32 YI__SEQUENCE__UpdateActive(...) asm("YI__SEQUENCE__UpdateActive");
/*TARGET 0023a918*/
u32 func_0023a918(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023a918jjjjjjjj");
u32 func_0023a918(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r15 = (u32)(*(u8*)((u32)r4 + (s32)(212)));
    r16 = r4;
    if (r15 == 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))YI__SEQUENCE__UpdateActive)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    r2 = *(u32*)((u32)r16 + (s32)(224));
    return r2;
}
}  // namespace n0023a918

// 0023a950 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023a950 {
u32 YI__SEQUENCE__UpdateActive(...) asm("YI__SEQUENCE__UpdateActive");
/*TARGET 0023a950*/
u32 func_0023a950(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023a950jjjjjjjj");
u32 func_0023a950(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r15 = (u32)(*(u8*)((u32)r4 + (s32)(212)));
    r16 = r4;
    if (r15 == 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))YI__SEQUENCE__UpdateActive)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    r2 = *(u32*)((u32)r16 + (s32)(228));
    return r2;
}
}  // namespace n0023a950

// 0023a988 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023a988 {
u32 YI__SEQUENCE__UpdateActive(...) asm("YI__SEQUENCE__UpdateActive");
/*TARGET 0023a988*/
u32 func_0023a988(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023a988jjjjjjjj");
u32 func_0023a988(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r15 = (u32)(*(u8*)((u32)r4 + (s32)(212)));
    r16 = r4;
    if (r15 == 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))YI__SEQUENCE__UpdateActive)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    r2 = *(u32*)((u32)r16 + (s32)(232));
    return r2;
}
}  // namespace n0023a988

// 0023a9c0 (was src/anon/batch_w65.cpp)
namespace n0023a9c0 {
void SEQ_GetActiveXY(u8* p, s32* x, s32* y) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
// 0x00227da8: definition moved into src/anon/unit_00224780.cpp

void YI__SEQUENCE__UpdateActive(void*) asm("YI__SEQUENCE__UpdateActive");
/*TARGET 0023a9c0*/
void SEQ_GetActiveXY(u8* p, s32* x, s32* y) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
void SEQ_GetActiveXY(u8* p, s32* x, s32* y) {
    if (!p[212]) YI__SEQUENCE__UpdateActive(p);
    *x = *(s32*)(p + 228);
    *y = *(s32*)(p + 232);
}
}  // namespace n0023a9c0

// 0023aa18 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023aa18 {
u32 func_0023aa18(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0023aa18jjjjjjjj");
/*TARGET 0023aa18*/
u32 func_0023aa18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023aa18jjjjjjjj");
u32 func_0023aa18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = *(u32*)((u32)a0 + (s32)(276));
    u8* base = *(u8**)((u32)a0 + (s32)(180));
    return *(u32*)(base + idx * 36 + 16);
}
}  // namespace n0023aa18

// 0023aa38 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023aa38 {
u32 func_0023aa38(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0023aa38jjjjjjjj");
/*TARGET 0023aa38*/
u32 func_0023aa38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023aa38jjjjjjjj");
u32 func_0023aa38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = *(u32*)((u32)a0 + (s32)(276));
    u8* base = *(u8**)((u32)a0 + (s32)(180));
    return *(u32*)(base + idx * 36 + 20);
}
}  // namespace n0023aa38

// 0023aa58 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023aa58 {
/*TARGET 0023aa58*/
u32 func_0023aa58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023aa58jjjjjjjj");
u32 func_0023aa58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = *(u32*)((u32)a0 + (s32)(276));
    u8* base = *(u8**)((u32)a0 + (s32)(180));
    return *(u32*)(base + idx * 36 + 24);
}
}  // namespace n0023aa58

// 0023aa78 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023aa78 {
/*TARGET 0023aa78*/
u32 func_0023aa78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023aa78jjjjjjjj");
u32 func_0023aa78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = *(u32*)((u32)a0 + (s32)(276));
    u8* base = *(u8**)((u32)a0 + (s32)(180));
    return *(u32*)(base + idx * 36 + 28);
}
}  // namespace n0023aa78

// 0023aa98 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023aa98 {
u32 func_0023aa98(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0023aa98jjjjjjjj");
/*TARGET 0023aa98*/
u32 func_0023aa98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023aa98jjjjjjjj");
u32 func_0023aa98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = *(u32*)((u32)a0 + (s32)(276));
    u8* base = *(u8**)((u32)a0 + (s32)(180));
    return *(u32*)(base + idx * 36 + 32);
}
}  // namespace n0023aa98

// 0023aab8 (was src/anon/batch_w319.cpp)
namespace n0023aab8 {
// 0x0013c190: definition moved into src/anon/unit_0013a8b8.cpp

s32 func_002384f8(...) asm("func_002384f8");
union W319U { u32 w; u16 h[2]; u8* p; };
struct W319BF { u32 b0:4; u32 b4:1; u32 b5:1; u32 b6:1; u32 b7:1; u32 b8:1; u32 b9:1; u32 b10:1; u32 rest:21; };
/*TARGET 0023aab8*/
void func_0023aab8(u8* p) asm("func_0023aab8");
void func_0023aab8(u8* p) {
    if (*(u8*)(p + 188) == 0) {
        s32 idx = *(s32*)(p + 276);
        u16* e;
        u8* s1;
        s32 n;
        u32 s0;
        ((W319U*)(p + 192))->w = idx;
        *(u8*)(p + 188) = 1;
        e = (u16*)(*(u8**)(p + 180) + idx * 36);
        s0 = 0;
        ((W319U*)(p + 196))->p = *(u8**)(p + 176) + e[0] * 144;
        ((W319U*)(p + 200))->w = e[1];
        n = e[1];
        s1 = *(u8**)(p + 176) + e[0] * 144;
        if (n > 0) {
            do {
                u32 f = *(u32*)s1;
                if (f & 4) s0 |= 1;
                if (*(u32*)(s1 + 132)) s0 |= 2;
                if (!(f & 0x20)) s0 |= 4;
                if (!(f & 0x40)) s0 |= 8;
                if (!(f & 0x400)) s0 |= 0x10;
                if (func_002384f8(p, *(u32*)(s1 + 4))) s0 |= 0x20;
                if ((*(u32*)s1 & 0x1010) != 0x1010) s0 |= 0x40;
                s1 += 144;
                if (s0 == 127) break;
            } while (--n > 0);
        }
        { W319BF* b = (W319BF*)(p + 184);
        b->b4 = 0; b->b5 = 0; b->b6 = 0; b->b7 = 0; b->b8 = 0; b->b9 = 0; b->b10 = 0;
        if (!(s0 & 1)) b->b4 = 1;
        if (!(s0 & 2)) b->b5 = 1;
        if (!(s0 & 4)) b->b6 = 1;
        if (!(s0 & 8)) b->b7 = 1;
        if (!(s0 & 0x10)) b->b8 = 1;
        if (!(s0 & 0x20)) b->b9 = 1;
        if (!(s0 & 0x40)) b->b10 = 1; }
    }
    *(f32*)(p + 204) = (f32)(s32)*(f32*)(p + 260);
}
}  // namespace n0023aab8

// 0023acd8 (was src/anon/batch_wcx2.cpp)
namespace n0023acd8 {
// 0x001b8838: definition moved into src/anon/unit_001b87a0.cpp

extern f32 D_00349e14 asm("D_00349e14");
void func_0023aab8(u8*) asm("func_0023aab8");
void func_00237ae8_x421(u8*) asm("func_00237ae8");
/*TARGET 0023acd8*/
void func_0023acd8(u8* p) asm("func_0023acd8");
void func_0023acd8(u8* p)
{
    f32 d = D_00349e14 * *(f32*)(p + 68);
    *(f32*)(p + 256) += d;
    switch (*(s32*)(p + 252)) {
    case 1:
        *(f32*)(p + 260) = 0.0f;
        *(s32*)(p + 252) = 2;
        func_0023aab8(p);
        func_00237ae8_x421(p);
        *(s32*)(p + 272) = 0;
        break;
    case 2:
        *(f32*)(p + 260) += d;
        if (*(f32*)(p + 264) <= *(f32*)(p + 260)) {
            *(s32*)(p + 272) = 0;
            *(f32*)(p + 260) = (f32)*(s32*)(p + 324);
            if (*(s32*)(p + 320)) {
                (*(s32*)(p + 320))--;
                (*(s32*)(p + 268))++;
                if (*(s32*)(p + 320) == 0) {
                    *(s32*)(p + 252) = 3;
                    *(f32*)(p + 260) = *(f32*)(p + 264) - 1.0f;
                    void (*cb)(u8*) = *(void (**)(u8*))(p + 236);
                    if (cb) cb(p);
                }
            }
        }
        func_0023aab8(p);
        func_00237ae8_x421(p);
        break;
    case 0:
    default:
        return;
    }
    p[212] = 0;
}
}  // namespace n0023acd8

// 0023ade0 (was src/anon/batch_w500.cpp)
namespace n0023ade0 {
// 2D sprite keyframe animation (YI__SEQUENCE__Draw draws one animated sprite).
// One keyframe of the track (0x90 bytes).
struct SprKey {
    u32 flags;        // 0x00
    s32 image;        // 0x04
    s32 start;        // 0x08 first frame
    s32 end;          // 0x0c last frame
    s32 x[2];         // 0x10
    s32 y[2];         // 0x18
    s32 u[2];         // 0x20
    s32 v[2];         // 0x28
    f32 pos[3][2];    // 0x30 (x0,x1,y0,y1,z0,z1)
    f32 scale[3][2];  // 0x48
    f32 ease[2][2];   // 0x60
    f32 amp[2][2];    // 0x70 wobble amplitude x, y
    u16 freq[2];      // 0x80 wobble frequency x, y
    s32 blend;        // 0x84
    u8 rgba[2][4];    // 0x88
};
struct SprAnim;
typedef void (*SprAnimCb)(SprAnim*, s32);
struct SprAnim {
    u8 pad00[0x10];
    union { u32 state; f32 stateF; };        // 0x10
    u8 pad14[0x40 - 0x14];
    void* image;      // 0x40
    u8 pad44[0x68 - 0x44];
    s32 imageNo;      // 0x68
    u8 pad6c[0x88 - 0x6c];
    u32 color;        // 0x88
    u8 pad8c[0xb8 - 0x8c];
    s32 mode;         // 0xb8
    u8 padbc[0xc4 - 0xbc];
    SprKey* keys;     // 0xc4
    s32 nkeys;        // 0xc8
    f32 time;         // 0xcc
    u32 baseColor;    // 0xd0
    u8 padd4[0xf0 - 0xd4];
    SprAnimCb cb;     // 0xf0
    u8 padf4[0xfc - 0xf4];
    s32 visible;      // 0xfc
    u8 pad100[0x110 - 0x100];
    s32 cbCount;      // 0x110
    u8 pad114[0x118 - 0x114];
    f32 colorMul[4];  // 0x118 r,g,b,a
    f32 ofs[3];       // 0x128
    f32 scl[3];       // 0x134
    u8 pad140[0x148 - 0x140];
    s32 px;           // 0x148
    s32 py;           // 0x14c
};
void YI_IMAGE_LoadImage(void*) asm("_ZN2YI5IMAGE9LoadImageEv");
u32 func_002f35e8(s32) asm("func_002f35e8");
void func_002f3918(u32, void*) asm("func_002f3918");
void func_002376d8(SprAnim*, s32) asm("func_002376d8");
void func_00237740(SprAnim*, f32, f32, f32) asm("func_00237740");
void func_00237a68(SprAnim*, f32, f32, f32) asm("func_00237a68");
void YI__SPRITE___Draw(SprAnim*, s32, s32, s32, s32) asm("YI__SPRITE___Draw");
void YI__SPRITE___Draw2(SprAnim*, s32, s32, s32, s32) asm("YI__SPRITE___Draw2");
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
u32 __fixunssfsi(f32)  asm("__fixunssfsi")__attribute__((const));
// __fixunssfsi (float -> u32)

extern u8 D_0035e3c0[] asm("D_0035e3c0");
extern u8 D_01dae590[][0x30] asm("D_01dae590");
extern u8 D_01dae5f0[][0x30] asm("D_01dae5f0");
#define ILERP(a, b, t) ((a) + (s32)((f32)((b) - (a)) * (t)))
#define FLERP(a, b, t) ((a) + ((b) - (a)) * (t))
/*TARGET 0023ade0*/
void YI__SEQUENCE__Draw(SprAnim* o) asm("YI__SEQUENCE__Draw");
void YI__SEQUENCE__Draw(SprAnim* o)
{
    if (o->visible == 0) return;
    if ((u32)(o->px + 0x200) > 0x600) return;
    if (o->py < -0x1a0) return;
    if (o->py > 0x340) return;

    if ((u8)((o->mode >> 3) & 1)) YI_IMAGE_LoadImage(o->image);
    u8* img = (u8*)o->image;
    func_002f3918(func_002f35e8(2), img + 0x100);
    if (((o->state >> 1) & 1) == 1) func_002f3918(func_002f35e8(2), D_0035e3c0);

    s32 n = o->nkeys;
    SprKey* k = o->keys;
    for (; n > 0; n--, k++) {
        f32 fr[2]; // key start/end frame (kept in memory like the original)
        fr[0] = (f32)k->start;
        if (!(fr[0] <= o->time)) continue;
        if (fr[0] == o->time && o->cb && (k->flags & 0x80000)) {
            o->cb(o, o->cbCount++);
        }
        fr[1] = (f32)k->end;
        if (fr[1] < o->time) continue;
        if (o->time == fr[1] && (k->flags & 0x8000)) continue;

        if (o->imageNo != k->image) func_002376d8(o, k->image);

        if (!(o->mode & 0x10)) {
            func_002f3918(func_002f35e8(2), D_01dae590[(k->flags >> 2) & 1]);
        } else if (o->mode & 0x2000) {
            func_002f3918(func_002f35e8(2), D_01dae590[1]);
        }
        if (!(o->mode & 0x20)) {
            func_002f3918(func_002f35e8(2), D_01dae5f0[k->blend]);
        }

        f32 d = fr[1] - fr[0];
        f32 t;
        if (d != 0.0f) t = (o->time - fr[0]) / d;
        else t = 1.0f;

        // Unless the key is linear, ease t with a cubic Bezier (control points 1, 1-e0, 1-e1, 0).
        if ((k->flags & 1) != 1) {
            f32 u = 1.0f - t;
            f32 c3 = 3.0f;
            f32 tt = t * t;
            f32 uu = u * u;
            t = 1.0f - (uu * u + uu * c3 * t * (1.0f - k->ease[0][1])
                        + u * c3 * tt * (1.0f - k->ease[1][1]) + tt * t * 0.0f);
        }

        if ((o->mode & 1) == 1) {
            o->state &= ~8;
            if (k->flags & 0x20) {
                func_00237740(o, o->ofs[0], o->ofs[1], o->ofs[2]);
            } else {
                f32 z = FLERP(k->pos[2][0], k->pos[2][1], t) + o->ofs[2];
                f32 y = FLERP(k->pos[1][0], k->pos[1][1], t) + o->ofs[1];
                f32 x = FLERP(k->pos[0][0], k->pos[0][1], t) + o->ofs[0];
                func_00237740(o, x, y, z);
            }
        } else if (k->flags & 0x20) {
            o->state |= 8;
        } else {
            o->state &= ~8;
            f32 z = FLERP(k->pos[2][0], k->pos[2][1], t);
            f32 y = FLERP(k->pos[1][0], k->pos[1][1], t);
            f32 x = FLERP(k->pos[0][0], k->pos[0][1], t);
            func_00237740(o, x, y, z);
        }

        if (o->mode & 2) {
            o->state &= ~0x10;
            if (k->flags & 0x40) {
                func_00237a68(o, o->scl[0], o->scl[1], o->scl[2]);
            } else {
                f32 z = o->scl[2] * FLERP(k->scale[2][0], k->scale[2][1], t);
                f32 y = o->scl[1] * FLERP(k->scale[1][0], k->scale[1][1], t);
                f32 x = o->scl[0] * FLERP(k->scale[0][0], k->scale[0][1], t);
                func_00237a68(o, x, y, z);
            }
        } else if (k->flags & 0x40) {
            o->state |= 0x10;
        } else {
            o->state &= ~0x10;
            f32 z = FLERP(k->scale[2][0], k->scale[2][1], t);
            f32 y = FLERP(k->scale[1][0], k->scale[1][1], t);
            f32 x = FLERP(k->scale[0][0], k->scale[0][1], t);
            func_00237a68(o, x, y, z);
        }

        if (o->mode & 4) {
            o->state &= ~0x20;
            if (k->flags & 0x400) {
                o->color = o->baseColor;
            } else {
                if (k->flags & 0x80) {
                    u32 r = __fixunssfsi((f32)k->rgba[0][0] * o->colorMul[0]);
                    r |= __fixunssfsi((f32)k->rgba[0][3] * o->colorMul[3]) << 24;
                    u32 b = __fixunssfsi((f32)k->rgba[0][2] * o->colorMul[2]) << 16;
                    b |= __fixunssfsi((f32)k->rgba[0][1] * o->colorMul[1]) << 8;
                    r |= b;
                    o->color = r;
                } else {
                    u32 r = __fixunssfsi((f32)ILERP(k->rgba[0][0], k->rgba[1][0], t) * o->colorMul[0]);
                    r |= __fixunssfsi((f32)ILERP(k->rgba[0][3], k->rgba[1][3], t) * o->colorMul[3]) << 24;
                    u32 b = __fixunssfsi((f32)ILERP(k->rgba[0][2], k->rgba[1][2], t) * o->colorMul[2]) << 16;
                    b |= __fixunssfsi((f32)ILERP(k->rgba[0][1], k->rgba[1][1], t) * o->colorMul[1]) << 8;
                    r |= b;
                    o->color = r;
                }
            }
        } else if (k->flags & 0x400) {
            o->state |= 0x20;
        } else if (k->flags & 0x80) {
            o->state &= ~0x20;
            o->color = *(u32*)k->rgba[0];
        } else {
            o->state &= ~0x20;
            o->color = ILERP(k->rgba[0][0], k->rgba[1][0], t) | ((ILERP(k->rgba[0][3], k->rgba[1][3], t) << 24) | ((ILERP(k->rgba[0][2], k->rgba[1][2], t) << 16) | (ILERP(k->rgba[0][1], k->rgba[1][1], t) << 8)));
        }

        s32 x, y;
        if (o->mode & 0x400) {
            x = k->x[0];
            y = k->y[0];
        } else {
            x = ILERP(k->x[0], k->x[1], t);
            y = ILERP(k->y[0], k->y[1], t);
            if (!(k->flags & 0x10)) {
                f32 ax = FLERP(k->amp[0][0], k->amp[0][1], t);
                f32 ay = FLERP(k->amp[1][0], k->amp[1][1], t);
                if (!(k->flags & 8)) {
                    f32 a = t * 3.1415927f;
                    x += (s32)(ax * sinf(a * (f32)k->freq[0]));
                    y += (s32)(ay * sinf(a * (f32)k->freq[1]));
                } else {
                    f32 a = t * 3.1415927f;
                    x += (s32)(ax * cosf(a * (f32)k->freq[0]));
                    y += (s32)(ay * cosf(a * (f32)k->freq[1]));
                }
            }
        }

        s32 cu = 0, cv = 0;
        if (!(k->flags & 0x4000)) {
            cu = ILERP(k->u[0], k->u[1], t);
            cv = ILERP(k->v[0], k->v[1], t);
        }
        if (!(o->mode & 0x200)) {
            YI__SPRITE___Draw(o, o->px + x, o->py + y, cu, cv);
        } else {
            YI__SPRITE___Draw2(o, o->px + x, o->py + y, cu, cv);
        }
    }
}
}  // namespace n0023ade0


// 0023b798 (was gap): sequence clock: advance the frame, loop or stop at the end (YI::SEQUENCE update).
namespace n0023b798 {
struct Seq;
typedef void (*SeqCb)(Seq*);
struct Seq {
    u8 pad00[0x44];
    f32 speed;        // 0x44
    u8 pad48[0xd4 - 0x48];
    u8 dirty;         // 0xd4
    u8 padd5[0xec - 0xd5];
    SeqCb cb;         // 0xec
    u8 padf0[0xfc - 0xf0];
    s32 state;        // 0xfc
    f32 total;        // 0x100
    f32 frame;        // 0x104
    f32 end;          // 0x108
    s32 count;        // 0x10c
    s32 cbCount;      // 0x110
    u8 pad114[0x140 - 0x114];
    s32 loops;        // 0x140
    s32 loopStart;    // 0x144
};
extern f32 D_00349e14 asm("D_00349e14");
void func_0023aab8(Seq*) asm("func_0023aab8");
void func_00239230(Seq*) asm("func_00239230");
void func_0023b798(Seq* o) asm("func_0023b798");
void func_0023b798(Seq* o) {
    f32 dt = D_00349e14 * o->speed;
    o->total += dt;
    s32 st = o->state;
    switch (st) {
    case 1:
        o->frame = 0;
        o->state = 2;
        func_00239230(o);
        o->dirty = 1;
        o->cbCount = 0;
        break;
    case 0: break;
    case 2: {
        f32 end = o->end;
        o->frame += dt;
        if (end <= o->frame) {
            o->frame = (f32)o->loopStart;
            o->cbCount = 0;
            if (o->loops) {
                o->loops--;
                o->count++;
                if (o->loops == 0) {
                    o->state = 3;
                    o->frame = end - 1.0f;
                    if (o->cb) o->cb(o);
                }
            }
        }
        func_0023aab8(o);
        func_00239230(o);
        o->dirty = 1;
        break;
    }
    }
}
}  // namespace n0023b798

// 0023b8a8 (was gap): apply the keys at the current frame (scale, colour, sprite rect) without drawing.
namespace n0023b8a8 {
using n0023ade0::SprKey;
using n0023ade0::SprAnim;
using n0023ade0::YI_IMAGE_LoadImage;
using n0023ade0::func_002f35e8;
using n0023ade0::func_002f3918;
using n0023ade0::func_002376d8;
using n0023ade0::func_00237a68;
using n0023ade0::D_0035e3c0;
void func_00239250(SprAnim*, s32, s32, s32, s32) asm("func_00239250");
void func_0023b8a8(SprAnim* o) asm("func_0023b8a8");
void func_0023b8a8(SprAnim* o)
{
    if (o->visible == 0) return;
    if ((u32)(o->px + 0x200) > 0x600) return;
    if (o->py < -0x1a0) return;
    if (o->py > 0x340) return;

    if ((u8)((o->mode >> 3) & 1)) YI_IMAGE_LoadImage(o->image);
    u8* img = (u8*)o->image;
    func_002f3918(func_002f35e8(2), img + 0x100);
    if (((o->state >> 1) & 1) == 1) func_002f3918(func_002f35e8(2), D_0035e3c0);
    SprKey* k = o->keys;
    o->state |= 8;
    s32 n = o->nkeys;
    for (; n > 0; n--, k++) {
        f32 fr[2];
        fr[0] = (f32)k->start;
        if (!(fr[0] <= o->time)) continue;
        fr[1] = (f32)k->end;
        if (fr[1] < o->time) continue;
        if (o->time == fr[1] && (k->flags & 0x8000)) continue;

        if (o->imageNo != k->image) func_002376d8(o, k->image);

        f32 d = fr[1] - fr[0];
        f32 t;
        if (d != 0.0f) t = (o->time - fr[0]) / d;
        else t = 1.0f;

        if (k->flags & 0x40) {
            o->state |= 0x10;
        } else {
            o->state &= ~0x10;
            f32 z = FLERP(k->scale[2][0], k->scale[2][1], t);
            f32 y = FLERP(k->scale[1][0], k->scale[1][1], t);
            f32 x = FLERP(k->scale[0][0], k->scale[0][1], t);
            func_00237a68(o, x, y, z);
        }

        if (k->flags & 0x400) {
            o->state |= 0x20;
        } else if (k->flags & 0x80) {
            o->state &= ~0x20;
            o->color = *(u32*)k->rgba[0];
        } else {
            o->state &= ~0x20;
            o->color = ILERP(k->rgba[0][0], k->rgba[1][0], t) | ((ILERP(k->rgba[0][3], k->rgba[1][3], t) << 24) | ((ILERP(k->rgba[0][2], k->rgba[1][2], t) << 16) | (ILERP(k->rgba[0][1], k->rgba[1][1], t) << 8)));
        }
        s32 y = o->py + ILERP(k->y[0], k->y[1], t);
        s32 v = ILERP(k->v[0], k->v[1], t);
        s32 u = ILERP(k->u[0], k->u[1], t);
        s32 x = o->px + ILERP(k->x[0], k->x[1], t);
        func_00239250(o, x, y, u, v);
    }
}
}  // namespace n0023b8a8
