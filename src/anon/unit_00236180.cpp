// Linked unit 0x00236180-0x00236d98: YI::IMAGE and texture upload helpers (gap functions written here).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 00236180 (was gap)
namespace n00236180 {
extern u8 D_0035ead8 asm("D_0035ead8");
// YI::IMAGE::IMAGE (C2 copy)
void func_00236180(u32 a0) asm("func_00236180");
void func_00236180(u32 a0) {
    u32 r4 = a0, r15;
    r15 = (u32)&D_0035ead8;
    *(u32*)(r4 + 408) = 0u;
    *(u32*)(r4 + 56) = 0u;
    *(volatile u32*)(r4 + 0) = r15;
    *(u32*)(r4 + 60) = 0u;
    *(volatile u32*)(r4 + 404) = 0u;
}
}  // namespace n00236180

// 002361a0 (was src/anon/tiny_auto80_solver.cpp)
namespace n002361a0 {
extern u8 D_0035ead8 asm("D_0035ead8");
/*TARGET 002361a0*/
void func_002361a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002361a0jjjjjjjj");
void func_002361a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r15;
    r15 = (u32)&D_0035ead8;
    *(u32*)(r4 + 408) = 0u;
    *(u32*)(r4 + 56) = 0u;
    *(u32*)(r4 + 60) = 0u;
    *(u32*)(r4 + 404) = 0u;
    *(u32*)(r4 + 0) = r15;
}
}  // namespace n002361a0

// 002361c0 (was gap)
namespace n002361c0 {
extern u32 D_0035ead8 asm("D_0035ead8");
// YI::IMAGE::~IMAGE (D2 copy)
void func_002361c0(u32 a0) asm("func_002361c0");
void func_002361c0(u32 a0) {
    *(u32*)((u32)a0 + (0)) = (u32)&D_0035ead8;
}
}  // namespace n002361c0

// 002361d0 (was src/anon/tiny.cpp)
namespace n002361d0 {
extern u32 D_0035ead8 asm("D_0035ead8");
// 0022ab80: moved to src/sasa/musical_input.cpp (linked unit)

void func_002361d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YI5IMAGED1Ev");
/*TARGET 002361d0*/
// YI::IMAGE::~IMAGE
void func_002361d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YI5IMAGED1Ev");
// YI::IMAGE::~IMAGE
void func_002361d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_0035ead8;
}
}  // namespace n002361d0

// 002361e0 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n002361e0 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_0035ead8 asm("D_0035ead8");
/*TARGET 002361e0*/
u32 func_002361e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002361e0jjjjjjjj");
u32 func_002361e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0035ead8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n002361e0

// 00236200 (was src/anon/batch_w1787_nsa.cpp)
namespace n00236200 {
// 0x0013eeb8: definition moved into src/anon/unit_0013dfb8.cpp

/* 00236200 */
extern u64 D_0035e3c0[6] asm("D_0035e3c0");
extern u64 D_0035e3f0[10] asm("D_0035e3f0");
void func_003058a0(s32) asm("func_003058a0");
void u_call0_00236200() asm("_Z16u_call0_00236200v");
/*TARGET 00236200*/
void u_call0_00236200() asm("_Z16u_call0_00236200v");
void u_call0_00236200() {
    D_0035e3c0[0] = 0x70000002;
    D_0035e3c0[2] = (1ULL << 60) | 0x8001;
    D_0035e3c0[3] = 0xe;
    D_0035e3c0[4] = 0x30000;
    D_0035e3c0[5] = 0x47;
    D_0035e3f0[0] = 0x70000004;
    D_0035e3f0[2] = (3ULL << 60) | 0x8001;
    D_0035e3f0[3] = 0xeee;
    D_0035e3f0[4] = 5;
    D_0035e3f0[5] = 8;
    D_0035e3f0[6] = 0x60;
    D_0035e3f0[7] = 0x14;
    D_0035e3f0[8] = 0x44;
    D_0035e3f0[9] = 0x42;
    func_003058a0(0);
}
}  // namespace n00236200

// 002362b0 (was src/anon/batch_w1886_nsa.cpp)
namespace n002362b0 {
/* 002362b0 */
struct W1886GSrc {
    u8 pad[8]; s32 o8; u8 pad1[4]; s32 o16; u8 pad2[4];
    s32 v24; u16 h28, h30, h32, h34, h36, h38; s32 v40; u16 h44, h46, h48, h50;
    u8 pad3[8]; u32 f0:1; u32 f1:1; u32 f2:1;
};
struct W1886GDst {
    u8 pad[4]; s32 v4; u32 h8, h12, h16, h20, h24, h28; s32 v32; u32 h36, h40, h44;
    u64 h48:32; u64 b0:1; u64 b1:1; u64 b2:1;
    u8* p56; u8* p60; u8 pad4[400 - 64]; u8 neg2; u8 pad5[3]; s32 z404; u8* p408;
};
// 0x00112ab8: definition moved into src/anon/unit_001117d8.cpp

void func_00236560(W1886GDst*) asm("func_00236560");
/*TARGET 002362b0*/
void YI__IMAGE__Init(W1886GDst* d, W1886GSrc* s) asm("YI__IMAGE__Init");
void YI__IMAGE__Init(W1886GDst* d, W1886GSrc* s)
{
    d->v4 = s->v24 < 0 ? 0x3600 : s->v24 >> 8;
    d->h8 = s->h28;
    d->h12 = s->h30;
    d->h16 = s->h32;
    d->h20 = s->h34;
    d->h24 = s->h36;
    d->h28 = s->h38;
    d->v32 = s->v40 < 0 ? 0x3500 : s->v40 >> 8;
    d->h36 = s->h44;
    d->h40 = s->h46;
    d->h44 = s->h48;
    d->h48 = s->h50;
    d->b0 = s->f0;
    d->b1 = s->f1;
    d->b2 = s->f2;
    d->p56 = (u8*)s + s->o8;
    d->p60 = (u8*)s + s->o16;
    d->neg2 = s->v24 == -2;
    d->z404 = 0;
    d->p408 = (u8*)s + 56;
    func_00236560(d);
}
}  // namespace n002362b0

// 00236410 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n00236410 {
u32 func_00236560() asm("_Z13func_00236560v");
/*TARGET 00236410*/
// 0x00233580: definition moved into src/anon/unit_00232f08.cpp

u32 func_00236410(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00236410jjjj");
// 0x00233580: definition moved into src/anon/unit_00232f08.cpp

u32 func_00236410(u32 a0, u32 a1, u32 a2, u32 a3) {  // obj_set4_then_call
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(u32*)((u32)r4 + (s32)(4)) = r5;
    return func_00236560();
}
}  // namespace n00236410

// 00236428 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n00236428 {
u32 func_00236560() asm("_Z13func_00236560v");
/*TARGET 00236428*/
u32 func_00236428(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00236428jjjj");
u32 func_00236428(u32 a0, u32 a1, u32 a2, u32 a3) {  // obj_set32_then_call
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(u32*)((u32)r4 + (s32)(32)) = r5;
    return func_00236560();
}
}  // namespace n00236428

// 00236440 (was src/anon/tiny_auto80_add_force0.cpp)
namespace n00236440 {
u32 func_00236560(u32, u32, u32, u32) asm("_Z13func_00236560jjjj");
/*TARGET 00236440*/
u32 func_00236440(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00236440jjjj");
u32 func_00236440(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(u32*)((u32)r4 + (s32)(4)) = r5;
    *(u32*)((u32)r4 + (s32)(32)) = r6;
    return ((u32(*)(u32))func_00236560)(r4);
}
}  // namespace n00236440

// 00236460 (was gap)
namespace n00236460 {
void u_tail0_00236560(u8* p) asm("_Z16u_tail0_00236560v");
void func_00236460(u8* p, s32 v) asm("func_00236460");
void func_00236460(u8* p, s32 v) {
    *(s32*)(p + 28) = v;
    u_tail0_00236560(p);
}
}  // namespace n00236460

// 00236478 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n00236478 {
u32 func_00236560() asm("_Z13func_00236560v");
/*TARGET 00236478*/
u32 func_00236478(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00236478jjjj");
u32 func_00236478(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(u32*)((u32)r4 + (s32)(48)) = r5;
    return func_00236560();
}
}  // namespace n00236478

// 00236490 (was src/anon/auto80_199_queue.cpp)
namespace n00236490 {
/*TARGET 00236490*/
// 0x00233a18: definition moved into src/anon/unit_002335e8.cpp

u32 func_00236490(void* a0) asm("_Z13func_00236490Pv");
// 0x00233a18: definition moved into src/anon/unit_002335e8.cpp

u32 func_00236490(void* a0) {
    s32 key;
    s32 i;
    DivEntry* p;

    key = *(s32*)((u8*)a0 + 0x1c);
    i = 0;
    p = &D_0035ea48[0];

    while (i < 14) {
        if (p->key == key) {
            s32 t6 = *(s32*)((u8*)a0 + 0xc);
            s32 t7 = *(s32*)((u8*)a0 + 0x8);
            s32 d = p->div;
            s32 n = t7 * t6;
            if (n < 0) {
                n += 15;
            }
            n >>= 4;
            return (u32)(n / d);
        }
        i += 1;
        p += 1;
    }

    return 0;
}
}  // namespace n00236490

// 002364f8 (was src/anon/auto80_199_queue.cpp)
namespace n002364f8 {
/*TARGET 002364f8*/
u32 func_002364f8(void* a0) asm("_Z13func_002364f8Pv");
u32 func_002364f8(void* a0) {
    s32 key;
    s32 i;
    DivEntry* p;

    key = *(s32*)((u8*)a0 + 0x30);
    i = 0;
    p = &D_0035ea48[0];

    while (i < 14) {
        if (p->key == key) {
            s32 t6 = *(s32*)((u8*)a0 + 0x28);
            s32 t7 = *(s32*)((u8*)a0 + 0x24);
            s32 d = p->div;
            s32 n = t7 * t6;
            if (n < 0) {
                n += 15;
            }
            n >>= 4;
            return (u32)(n / d);
        }
        i += 1;
        p += 1;
    }

    return 0;
}
}  // namespace n002364f8

// 00236560 (was src/anon/batch_w2351.cpp)
namespace n00236560 {
#define TEX0_W2351(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | \
    ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | \
    ((u64)(cpsm) << 51) | ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))
void sceGsSetDefLoadImage(void*, s16, s16, s16, s16, s16, s16, s16) asm("sceGsSetDefLoadImage");
void func_003058a0(s32) asm("func_003058a0");
// Texture + CLUT upload descriptor followed by a GIF packet that sets TEX0/TEX1/TEX2.
struct TexUpload2351 {
    s32 x0, tbp, w, h, tw, th, tbw, psm, cbp, clutX, clutY, clutW;
    union { struct { s32 cpsm; s32 x34; } s; u64 q; } u;
    u8 pad38[0x40 - 0x38];
    u8 texXfer[0x60];
    u8 clutXfer[0x60];
    u64 g[0x20];
};
void u_tail0_00236560(TexUpload2351* p) asm("_Z16u_tail0_00236560v");
/*TARGET 00236560*/
void u_tail0_00236560(TexUpload2351* p) asm("_Z16u_tail0_00236560v");
void u_tail0_00236560(TexUpload2351* p) {
    s32 cbp = p->cbp;
    s32 tbp = p->tbp;
    s32 tbw, psm, w, h;
    sceGsSetDefLoadImage(p->clutXfer, cbp, p->clutW, p->u.s.cpsm, 0, 0, p->clutX, p->clutY);
    tbw = p->tbw; psm = p->psm; w = p->w; h = p->h;
    if (p->u.q & (1ULL << 34)) {
        // 8/4-bit textures are uploaded as PSMCT32
        switch (psm) {
        case 19: tbw /= 2; w /= 2; h /= 2; psm = 0; break;
        case 20: tbw /= 2; w /= 2; h /= 4; psm = 0; break;
        }
    }
    sceGsSetDefLoadImage(p->texXfer, tbp, tbw, psm, 0, 0, w, h);
    p->g[0] = 0x70000008;
    p->g[2] = (7ULL << 60) | 0x8001;
    p->g[3] = 0xeeeeeee;
    p->g[4] = 5;
    p->g[5] = 8;
    p->g[6] = 0;
    p->g[7] = 0x3f;
    p->g[8] = TEX0_W2351(tbp, p->tbw, p->psm, p->tw, p->th, 1, 0, cbp, p->u.s.cpsm, 0, 0, 1);
    p->g[9] = 6;
    p->g[10] = 0x60;
    p->g[11] = 0x14;
    {
        u64 lo = (u64)cbp << 37 | 1ULL << 62;
        u64 hi = (u64)p->u.s.cpsm << 51 | 0x1300000;
        p->g[12] = lo | hi;
    }
    p->g[13] = 0x16;
    p->g[14] = (u64)p->psm << 20 | ((u64)p->u.s.cpsm << 51 | (u64)cbp << 37);
    p->g[15] = 0x16;
    p->g[16] = 0x44;
    p->g[17] = 0x42;
    func_003058a0(0);
}
}  // namespace n00236560

// 00236788 (was src/anon/tiny.cpp)
namespace n00236788 {
void func_00236830(void*) asm("_Z13func_00236830Pv");
/*TARGET 00236788*/
// 0x002330b0: definition moved into src/anon/unit_00232f08.cpp
void func_00236788(BD_VALUE* bd) asm("_Z13func_00236788P8BD_VALUE");
// 0x002330b0: definition moved into src/anon/unit_00232f08.cpp
void func_00236788(BD_VALUE* bd) { func_00236830(bd); }
}  // namespace n00236788

// 002367a0 (was src/anon/batch_w7.cpp)
namespace n002367a0 {
u32 func_002f35e8(u32) asm("func_002f35e8");
void func_002f3918(u32, void*) asm("func_002f3918");
extern char D_0035e3f0[] asm("D_0035e3f0");
/*TARGET 002367a0*/
// 0x00234590: definition moved into src/anon/unit_002335e8.cpp

void func_002367a0(void) asm("func_002367a0");
// 0x00234590: definition moved into src/anon/unit_002335e8.cpp

void func_002367a0(void) {
    func_002f3918(func_002f35e8(2), D_0035e3f0);
}
}  // namespace n002367a0

// 002367c8 (was src/anon/batch_w49.cpp)
namespace n002367c8 {
// 0x001e8bb8: definition moved into src/anon/unit_001e8ac8.cpp

void sceGsExecLoadImage(u8*, u32) asm("sceGsExecLoadImage");
/*TARGET 002367c8*/
void func_002367c8(u8* p) asm("func_002367c8");
void func_002367c8(u8* p) {  // obj_dispatch_bitfield64
    if (((s32)(*(s64*)(p + 48) >> 32) & 1) == 0) sceGsExecLoadImage(p + 64, *(u32*)(p + 56));
    if (((*(u64*)(p + 48) >> 33) & 1) == 0) sceGsExecLoadImage(p + 160, *(u32*)(p + 60));
}
}  // namespace n002367c8

// 00236830 (was src/anon/auto80_199_queue.cpp)
namespace n00236830 {
/*TARGET 00236830*/
void func_00236830(void* a0) asm("_Z13func_00236830Pv");
void func_00236830(void* a0) {
    u64 t6;
    s32 t7;

    if (*(u8*)((u8*)a0 + 0x190) != 0) {
        func_00236d98(a0);
        return;
    }

    t6 = *(u64*)((u8*)a0 + 0x30);
    t7 = ((s32)(t6 >> 32)) & 1;
    if (t7 != 0) {
        sceGsExecLoadImage((u8*)a0 + 0x40, *(u32*)((u8*)a0 + 0x38));
        t6 = *(u64*)((u8*)a0 + 0x30);
    }

    t7 = ((s32)(t6 >> 33)) & 1;
    if (t7 != 0) {
        sceGsExecLoadImage((u8*)a0 + 0xa0, *(u32*)((u8*)a0 + 0x3c));
    }
}
}  // namespace n00236830

// 002368b0 (was src/anon/batch_w14.cpp)
namespace n002368b0 {
void sceGsExecLoadImage(void*, void*) asm("sceGsExecLoadImage");
/*TARGET 002368b0*/
// 002289c0: moved to src/anon/unit_00228618.cpp (linked unit)

void func_002368b0(u8* p) asm("func_002368b0");
// 002289c0: moved to src/anon/unit_00228618.cpp (linked unit)

void func_002368b0(u8* p) {
    sceGsExecLoadImage(p + 64, *(void**)(p + 56));
    sceGsExecLoadImage(p + 160, *(void**)(p + 60));
}
}  // namespace n002368b0

// 002368e8 (was src/anon/batch_w53.cpp)
namespace n002368e8 {
s32 func_001319d8(s32, f32) asm("func_001319d8");
/*TARGET 002368e8*/
// 0022afa0: moved to src/sasa/musical_input.cpp (linked unit)

void YI__IMAGE__ClutGray(u8* p, f32 x) asm("YI__IMAGE__ClutGray");
// 0022afa0: moved to src/sasa/musical_input.cpp (linked unit)

void YI__IMAGE__ClutGray(u8* p, f32 x) {
    if (**(s8**)(p + 408) == 0 && *(u32*)(p + 48) == 0) {
        s32 n = *(s32*)(p + 36) * *(s32*)(p + 40);
        s32* a = *(s32**)(p + 60);
        for (; n > 0; n--) {
            *a = func_001319d8(*a, x);
            a++;
        }
        **(s8**)(p + 408) = 1;
    }
}
}  // namespace n002368e8

// 00236978 (was gap)
namespace n00236978 {
extern u8 D_0035eac8 asm("D_0035eac8");
void func_00236978(u32 a0) asm("func_00236978");
void func_00236978(u32 a0) {
    u32 r4 = a0, r15;
    r15 = (u32)&D_0035eac8;
    *(u32*)(r4 + 20) = 0u;
    *(u32*)(r4 + 4) = 0u;
    *(volatile u32*)(r4 + 0) = r15;
    *(u32*)(r4 + 8) = 0u;
    *(volatile u32*)(r4 + 12) = 0u;
    *(volatile u32*)(r4 + 16) = 0u;
}
}  // namespace n00236978

// 002369a0 (was src/anon/tiny_auto80_solver.cpp)
namespace n002369a0 {
extern u8 D_0035eac8 asm("D_0035eac8");
/*TARGET 002369a0*/
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z30YI__IMAGE_FREEZE__IMAGE_FREEZEjjjjjjjj");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // obj_ctor_36eac8
    u32 r4 = a0, r15;
    r15 = (u32)&D_0035eac8;
    *(u32*)(r4 + 20) = 0u;
    *(u32*)(r4 + 4) = 0u;
    *(u32*)(r4 + 8) = 0u;
    *(u32*)(r4 + 12) = 0u;
    *(u32*)(r4 + 16) = 0u;
    *(u32*)(r4 + 0) = r15;
}
}  // namespace n002369a0

// 002369c8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002369c8 {
u32 func_00236c38(u32, u32, u32, u32) asm("_Z13func_00236c38jjjj");
extern u8 D_0035eac8 asm("D_0035eac8");
/*TARGET 002369c8*/
// 0x00232328: definition moved into src/anon/unit_00231500.cpp

u32 func_002369c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002369c8jjjj");
// 0x00232328: definition moved into src/anon/unit_00231500.cpp

u32 func_002369c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035eac8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00236c38)(u32, u32, u32, u32) = func_00236c38;
    r2 = fp_call4_00236c38(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002369c8

// 002369f0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002369f0 {
u32 func_00236c38(u32, u32, u32, u32) asm("_Z13func_00236c38jjjj");
extern u8 D_0035eac8 asm("D_0035eac8");
/*TARGET 002369f0*/
u32 func_002369f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002369f0jjjj");
u32 func_002369f0(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_36eac8_then_call
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035eac8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00236c38)(u32, u32, u32, u32) = func_00236c38;
    r2 = fp_call4_00236c38(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002369f0

// 00236a18 (was src/anon/batch_w20.cpp)
namespace n00236a18 {
void func_00236c38(void*) asm("func_00236c38");
void func_00106420(void*) asm("func_00106420");
extern void* D_0035eac8[] asm("D_0035eac8");
/*TARGET 00236a18*/
void func_00236a18(void** p) asm("func_00236a18");
void func_00236a18(void** p) {
    *p = D_0035eac8;
    func_00236c38(p);
    func_00106420(p);
}
}  // namespace n00236a18

// 00236a50 (was src/anon/misc_2.cpp)
namespace n00236a50 {
/*TARGET 00236a50*/
// 0x00233e58: definition moved into src/anon/unit_002335e8.cpp

void func_00236a50(void* self) asm("_Z13func_00236a50Pv");
// 0x00233e58: definition moved into src/anon/unit_002335e8.cpp

void func_00236a50(void* self) {}
}  // namespace n00236a50

// 00236a58 (was src/anon/batch_w1886_nsa.cpp)
namespace n00236a58 {
/* 002362b0 */
struct W1886GSrc {
    u8 pad[8]; s32 o8; u8 pad1[4]; s32 o16; u8 pad2[4];
    s32 v24; u16 h28, h30, h32, h34, h36, h38; s32 v40; u16 h44, h46, h48, h50;
    u8 pad3[8]; u32 f0:1; u32 f1:1; u32 f2:1;
};
struct W1886GDst {
    u8 pad[4]; s32 v4; u32 h8, h12, h16, h20, h24, h28; s32 v32; u32 h36, h40, h44;
    u64 h48:32; u64 b0:1; u64 b1:1; u64 b2:1;
    u8* p56; u8* p60; u8 pad4[400 - 64]; u8 neg2; u8 pad5[3]; s32 z404; u8* p408;
};
void* func_001063f0(u32, u32) asm("func_001063f0");
struct W1886Gra {
    u8 pad[396]; u8 flag; u8 pad2[15];
    static void* operator new[](unsigned int sz, u32 h) { return func_001063f0(sz, h); }
    static void operator delete[](void*) asm("func_00106450");
    W1886Gra(); /* the complete constructor is func_002361a0 (see the asm alias below) */
    void setFlag() { flag = 1; }
    virtual ~W1886Gra();
} __attribute__((aligned(16)));
asm("_ZN9n00236a588W1886GraC1Ev = _Z13func_002361a0jjjjjjjj");
struct W1886Ent { s32 off; s32 pad; };
struct W1886Res { u8 pad[6]; s8 flag; u8 pad2; s32 entOff; s32 n; };
struct W1886Menu { u8 pad[4]; u32 heap; W1886Res* res; W1886Ent* ents; s32 n; W1886Gra* gra; };
void YI__IMAGE__Init(W1886GDst* d, W1886GSrc* s) asm("YI__IMAGE__Init");
void func_002367c8(W1886Gra*) asm("func_002367c8");
void W1886_SetGraRes(W1886Menu* m, W1886Res* r, u32 heap) asm("_ZN2Tz9MenuBasic9SetGraResEz");
/*TARGET 00236a58*/
void W1886_SetGraRes(W1886Menu* m, W1886Res* r, u32 heap) asm("_ZN2Tz9MenuBasic9SetGraResEz");
void W1886_SetGraRes(W1886Menu* m, W1886Res* r, u32 heap)
{
    s32 i;
    m->heap = heap;
    m->res = r;
    m->ents = (W1886Ent*)((u8*)r + r->entOff);
    m->n = r->n;
    if (m->gra) delete[] m->gra;
    m->gra = new (m->heap) W1886Gra[m->n];
    for (i = 0; i < m->n; i++) {
        YI__IMAGE__Init((W1886GDst*)&m->gra[i], (W1886GSrc*)((u8*)r + m->ents[i].off));
        func_002367c8(&m->gra[i]);
        if (r->flag) m->gra[i].setFlag();
    }
}
}  // namespace n00236a58

// 00236bb8 (was src/anon/batch_w52.cpp)
namespace n00236bb8 {
void func_002367c8(u8*) asm("func_002367c8");
// 0x00232070: definition moved into src/anon/unit_00231500.cpp

void YI__IMAGE__ClutGray(u8*, f32) asm("YI__IMAGE__ClutGray");
/*TARGET 00236bb8*/
void func_00236bb8(u8* p, f32 f) asm("func_00236bb8");
void func_00236bb8(u8* p, f32 f) {
    s32 i;
    for (i = 0; i < *(s32*)(p + 16); i++) {
        YI__IMAGE__ClutGray(*(u8**)(p + 20) + i * 416, f);
        func_002367c8(*(u8**)(p + 20) + i * 416);  // obj_dispatch_bitfield64
    }
}
}  // namespace n00236bb8

// 00236c38 (was src/anon/auto80_199_queue.cpp)
namespace n00236c38 {
/*TARGET 00236c38*/
void func_00236c38(void* a0) asm("_Z13func_00236c38Pv");
void func_00236c38(void* a0) {
    u8* base;
    u8* end;

    base = (u8*)*(u32*)((u8*)a0 + 0x14);
    if (base == 0) {
        return;
    }

    end = base + (*(s32*)(base - 4) * 0x1a0);
    for (;;) {
        if (base == end) {
            break;
        }
        end -= 0x1a0;
        ((void(**)(void*))(*(u32*)end))[0]((void*)end);
        base = (u8*)*(u32*)((u8*)a0 + 0x14);
    }

    func_00106450((void*)(base - 0x10));
    *(u32*)((u8*)a0 + 0x14) = 0;
}
}  // namespace n00236c38

// 00236ca8 (was src/anon/tiny_auto80_solver.cpp)
namespace n00236ca8 {
/*TARGET 00236ca8*/
u32 func_00236ca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00236ca8jjjjjjjj");
u32 func_00236ca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)((s32)0u + (416));
    r5 = (u32)(r5 * r15);
    r2 = *(u32*)((u32)r4 + (s32)(20));
    r2 = (u32)(r2 + r5);
    return r2;
}
}  // namespace n00236ca8

// 00236cc0 (was src/anon/tiny_leaf.cpp)
namespace n00236cc0 {
/*TARGET 00236cc0*/
// 0x00231928: definition moved into src/anon/unit_00231500.cpp

u32 func_00236cc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00236cc0jjjj");
// 0x00231928: definition moved into src/anon/unit_00231500.cpp

u32 func_00236cc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r14 = *(u32*)((u32)r4 + (s32)(12));
    r5 = (u32)(r5 << 3);
    r2 = *(u32*)((u32)r4 + (s32)(8));
    r5 = (u32)(r5 + r14);
    r15 = *(u32*)((u32)r5 + (s32)(0));
    r2 = (u32)(r2 + r15);
    return r2;
}
}  // namespace n00236cc0

// 00236ce0 (was src/anon/tiny.cpp)
namespace n00236ce0 {
void func_00236d10(void*) asm("_Z13func_00236d10Pv");
/*TARGET 00236ce0*/
void func_00236ce0(BD_VALUE* bd) asm("_Z13func_00236ce0P8BD_VALUE");
void func_00236ce0(BD_VALUE* bd) { func_00236d10(bd); }
}  // namespace n00236ce0

// 00236cf8 (was gap)
namespace n00236cf8 {
void init_00236d10(void*) asm("_Z13func_00236d10Pv");
void func_00236cf8(void* p) asm("func_00236cf8");
void func_00236cf8(void* p) {
    init_00236d10(p);
}
}  // namespace n00236cf8

// 00236d10 (was src/anon/batch_w33.cpp)
namespace n00236d10 {
// 0x00234298: definition moved into src/anon/unit_002335e8.cpp

struct Slot236 { u8 used; u8 pad[3]; s32 a; s32 b; s32 pad2; s32 x; s32 y; };
extern Slot236 D_0035e440[] asm("D_0035e440");
extern s32 D_0035ea40 asm("D_0035ea40");
void init_00236d10(void*) asm("_Z13func_00236d10Pv");
/*TARGET 00236d10*/
void init_00236d10(void*) asm("_Z13func_00236d10Pv");
void init_00236d10(void*) {
    Slot236* s = D_0035e440;
    s32 y = 0x3500, x = 0x3600;
    for (s32 i = 63; i >= 0; i--) {
        s->x = x;
        s->y = y;
        s->used = 0;
        x += 32;
        s->a = 0;
        y += 4;
        s->b = 0;
        s++;
    }
    D_0035ea40 = 1;
}
}  // namespace n00236d10

// 00236d60 (was src/anon/batch_w21.cpp)
namespace n00236d60 {
struct E24 { u8 a; u32 b; u32 pad[4]; };
extern E24 D_0035e440[64] asm("D_0035e440");
/*TARGET 00236d60*/
// Clear the 64-entry table at D_0035e440.
void YI__IMAGE_CACHE__Clear(void) asm("YI__IMAGE_CACHE__Clear");
// Clear the 64-entry table at D_0035e440.
void YI__IMAGE_CACHE__Clear(void) {  // clear_64_entries_24
    E24* e;
    for (e = D_0035e440; (s32)e < (s32)(D_0035e440 + 64); e++) {
        e->a = 0;
        e->b = 0;
    }
}
}  // namespace n00236d60

