// Linked unit 0x00206be8-0x00207350 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
typedef f32 FMTX65b[4][4] __attribute__((aligned(16)));
typedef f32 FMTX206[4][4] __attribute__((aligned(16)));
typedef f32 FMTX208[4][4] __attribute__((aligned(16)));

// 00206be8 (was src/anon/batch_w1674_nsa.cpp)
namespace n00206be8 {
struct Work206b { u8 pad0[0x10]; FMTX206 world; FMTX206 view; };
struct State206b { u8 pad0[0xa8]; u64 flags; };
struct Frame206b { s16 dataOfs; s16 duration; s8 flags; u8 pad5[3]; };
struct Anim206b { u8 pad0[6]; s16 count; u8 pad8[8]; Frame206b frames[1]; };
struct AnimRef206b { Anim206b* anim; s32 x4; };
struct Bank206b { u8 pad0[0x14]; AnimRef206b* anims; };
struct DrawParam206b {
    u16 x00;
    u16 flags;          // 0x02
    u8 rgba[4];         // 0x04
    u32 x08[2];            // 0x08
    f32 (*viewMtx)[4];  // 0x10
    u8* packet;         // 0x14
    s8 x18;             // 0x18
    u8 pad19[3];
    f32 (*localMtx)[4]; // 0x1c
    u8 pad20[0x10];
};
struct Elem206b {
    u8 pad0[8];
    s32 anim;       // 0x08
    u16 speed;      // 0x0c
    u8 pad0e[2];
    u8 x10;         // 0x10
    u8 x11;         // 0x11
    u8 hasOffset;   // 0x12
    u8 pad13;
    f32 offset[3];  // 0x14
    u8 pad20[0x10];
    f32 scale[3];   // 0x30
    u8 rgb[3];      // 0x3c
    u8 alpha;       // 0x3f
    u8 periodA;     // 0x40
    u8 periodB;     // 0x41
    u8 pad42;
    u8 flicker;     // 0x43
    u8 x44;         // 0x44
};
struct Slot206b {
    f32 pos[4];
    Elem206b* elem;     // 0x10
    u8 pad14[4];
    u16 time;           // 0x18
    u16 frame;          // 0x1a
    u8 timerA;          // 0x1c
    u8 timerB;          // 0x1d
    u16 decay;          // 0x1e
    s32 phase;          // 0x20
    u8 pad24[0xc];
};
struct List206b { u8 pad0[8]; u32 count; u8 padc[8]; Slot206b* slots; };
extern Work206b* D_01d9e6e8 asm("D_01d9e6e8");
extern Bank206b* D_01d9e6e4 asm("D_01d9e6e4");
extern State206b* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9eaa4 asm("D_01d9eaa4");
extern FMTX206 D_01d9e730 asm("D_01d9e730");
extern FMTX206 D_01d9e8c0 asm("D_01d9e8c0");
extern f32 D_00359a20[] asm("D_00359a20");
void sceVu0ApplyMatrix(f32* out, f32 (*m)[4], f32* in) asm("sceVu0ApplyMatrix");
// sceVu0ApplyMatrix
void sceVu0MulMatrix(f32 (*out)[4], f32 (*a)[4], f32 (*b)[4]) asm("sceVu0MulMatrix");
// sceVu0MulMatrix
void sceVu0CopyVector(f32* out, f32* in) asm("sceVu0CopyVector");
// sceVu0CopyVector
void sceVu0CopyMatrix(f32 (*out)[4], f32 (*in)[4]) asm("sceVu0CopyMatrix");
// sceVu0CopyMatrix
void sceVu0UnitMatrix(f32 (*m)[4]) asm("sceVu0UnitMatrix");
// sceVu0UnitMatrix
u8* func_0021d048(u8* data, DrawParam206b* p, s32 x) asm("func_0021d048");
/*TARGET 00206be8*/
void draw_lamp(List206b* list) asm("draw_lamp");
void draw_lamp(List206b* list) {
    DrawParam206b p;
    FMTX206 local;
    u32 i;
    p.x18 = 0;
    p.viewMtx = D_01d9e6e8->view;
    *(u64*)p.x08 = 0;
    for (i = 0; i < list->count; i++) {
        Slot206b* s = &list->slots[i];
        Elem206b* e = s->elem;
        if (e == 0) continue;
        if (--s->timerA == 0xff) {
            s->timerA = e->periodA;
            if (s->phase == 0) s->phase = 0x7fff;
        }
        if (--s->timerB == 0xff) {
            s->timerB = e->periodB;
            if (s->phase == 0) s->phase = 0x7fff;
        }
        if (s->phase != 0) {
            s32 v = s->phase - s->decay;
            if (v < 0) v = 0;
            s->phase = v;
        }
        p.flags = 0;
        if (e->x44 == 1) p.flags = 0x10;
        if (e->x10) p.flags |= 0x800;
        if (e->x11) p.flags |= 0x400;
        u16 frame = s->frame;
        if (e->anim == 0xffff) continue;
        AnimRef206b* ref = &D_01d9e6e4->anims[e->anim];
        p.rgba[0] = e->rgb[0];
        p.rgba[1] = e->rgb[1];
        p.rgba[2] = e->rgb[2];
        f32 f = D_00359a20[(s->phase & 0xffff) >> 4];
        if (f < 0.0f) f = -f;
        s32 a = e->alpha - (u8)(s32)(e->flicker * f);
        if (a < 0) a = 0;
        p.rgba[3] = a;
        Anim206b* anim = ref->anim;
        Frame206b* fr = &anim->frames[frame];
        u8* data = (u8*)anim + fr->dataOfs;
        p.localMtx = 0;
        sceVu0UnitMatrix(D_01d9e6e8->view);
        D_01d9e6e8->view[0][0] = e->scale[0];
        D_01d9e6e8->view[1][1] = e->scale[1];
        D_01d9e6e8->view[2][2] = e->scale[2];
        sceVu0CopyMatrix(D_01d9e6e8->world, D_01d9e6e8->view);
        sceVu0CopyVector(D_01d9e6e8->world[3], s->pos);
        sceVu0ApplyMatrix(D_01d9e6e8->view[3], D_01d9e730, s->pos);
        if (e->hasOffset) {
            sceVu0CopyMatrix(local, D_01d9e6e8->view);
            local[3][0] += e->offset[0];
            local[3][1] += e->offset[1];
            local[3][2] += e->offset[2];
            sceVu0MulMatrix(local, D_01d9e8c0, local);
            p.localMtx = local;
        }
        sceVu0MulMatrix(D_01d9e6e8->view, D_01d9e8c0, D_01d9e6e8->view);
        p.packet = D_01d9eaa4;
        D_01d9eaa4 = func_0021d048(data, &p, ref->x4);
        if (D_01d9ea9c != 0) continue;
        if (D_01d9e6e0->flags & 0xff0000ff00ULL) continue;
        s->time += e->speed;
        if (s->time >= fr->duration) {
            s->time -= fr->duration;
            u16 old = s->frame;
            s->frame = old + 1;
            if ((u16)(old + 1) >= anim->count) {
                if (fr->flags & 0x80) {
                    s->frame = 0;
                    s->time = 0;
                } else {
                    s->frame = old;
                    s->time = 0;
                }
            }
        }
    }
}
}  // namespace n00206be8

// 00206fd8 (was gap, written for the unit)
namespace n00206fd8 {
struct BufG { s32 n0, n1, n2; u8* p0; u8* p1; u8* p2; };
void draw_shape(BufG*) asm("draw_shape");
void draw_model(BufG*) asm("draw_model");
void draw_lamp(BufG*) asm("draw_lamp");
void func_00206fd8(u8* base, u8* d, u8* c) asm("func_00206fd8");
void func_00206fd8(u8* base, u8* d, u8* c) {
    BufG* s = (BufG*)(base + (*(s32**)(c + 12))[0] + 160);
    draw_shape(s);
    draw_model(s);
    void (*f)(BufG*) = draw_lamp;
    f(s);
}
void func_00207020(u8* base, u8* c) asm("func_00207020");
void func_00207020(u8* base, u8* c) {
    BufG* s = (BufG*)(base + (*(s32**)(c + 12))[0] + 160);
    s->n0 = 0;
    s->n2 = 0;
    s->n1 = 0;
    s->p2 = 0;
    s->p1 = 0;
    s->p0 = 0;
}
}  // namespace n00206fd8

// 00207050 (was src/anon/batch_w62.cpp)
namespace n00207050 {
// 0x001dffd8: definition moved into src/anon/unit_001deb58.cpp

extern u32 D_01d9e6e4 asm("D_01d9e6e4");
void func_001e7798(u32, u32) asm("func_001e7798");
/*TARGET 00207050*/
// Releases the three handles at +12/+16/+20 of the sub-block.
void pppRyjMegaPlaceDes(u8* p, u8* d) asm("pppRyjMegaPlaceDes");
// Releases the three handles at +12/+16/+20 of the sub-block.
void pppRyjMegaPlaceDes(u8* p, u8* d) {
    u32* s = (u32*)(p + **(s32**)(d + 12) + 160);
    if (s[3]) { func_001e7798(D_01d9e6e4, s[3]); s[3] = 0; }
    if (s[4]) { func_001e7798(D_01d9e6e4, s[4]); s[4] = 0; }
    if (s[5]) { func_001e7798(D_01d9e6e4, s[5]); s[5] = 0; }
}
}  // namespace n00207050

// 002070d0 (was src/anon/auto80_199_queue.cpp)
namespace n002070d0 {
/*TARGET 002070d0*/
void func_002070d0(u32 a0, u32 a1, u32 a2) asm("_Z13func_002070d0jjj");
void func_002070d0(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a0;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    u32 s0 = t5 + t7;
    u32 t6b = *(u8*)(s0 + 160);
    if (t6b != 0) {
        return;
    }
    u32 t4 = *(u32*)(t6 + 0);
    u32 a0p = t5 + t4;
    u32 v0 = func_002061f8(a0p + 160, a1);
    if (v0 == 0) {
        return;
    }
    *(u8*)(s0 + 160) = 1;
}
}  // namespace n002070d0

// 00207128 (was gap, written for the unit)
namespace n00207128 {
void func_00207128(u8* base, u8* c) asm("func_00207128");
void func_00207128(u8* base, u8* c) {
    s32* off = *(s32**)(c + 12);
    u8* p = base + off[1] + 160;
    s32* q = (s32*)(base + off[0] + 160);
    *p = 0;
    q[0]++;
}
}  // namespace n00207128

// 00207150 (was src/anon/auto80_199_queue.cpp)
namespace n00207150 {
/*TARGET 00207150*/
void func_00207150(u32 a0, u32 a1, u32 a2) asm("_Z13func_00207150jjj");
void func_00207150(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a0;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    u32 s0 = t5 + t7;
    u32 t6b = *(u8*)(s0 + 160);
    if (t6b != 0) {
        return;
    }
    u32 t4 = *(u32*)(t6 + 0);
    u32 a0p = t5 + t4;
    u32 v0 = func_002062c0(a0p + 160, a1);
    if (v0 == 0) {
        return;
    }
    *(u8*)(s0 + 160) = 1;
}
}  // namespace n00207150

// 002071a8 (was gap, written for the unit)
namespace n002071a8 {
void func_002071a8(u8* base, u8* c) asm("func_002071a8");
void func_002071a8(u8* base, u8* c) {
    s32* off = *(s32**)(c + 12);
    u8* p = base + off[1] + 160;
    s32* q = (s32*)(base + off[0] + 160);
    *p = 0;
    q[1]++;
}
}  // namespace n002071a8

// 002071d8 (was src/anon/auto80_199_queue.cpp)
namespace n002071d8 {
/*TARGET 002071d8*/
void pppRyjMegaPlaceLamp(u32 a0, u32 a1, u32 a2) asm("_Z19pppRyjMegaPlaceLampjjj");
void pppRyjMegaPlaceLamp(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a0;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    u32 s0 = t5 + t7;
    u32 t6b = *(u8*)(s0 + 160);
    if (t6b != 0) {
        return;
    }
    u32 t4 = *(u32*)(t6 + 0);
    u32 a0p = t5 + t4;
    u32 v0 = func_00206388(a0p + 160, a1);
    if (v0 == 0) {
        return;
    }
    *(u8*)(s0 + 160) = 1;
}
}  // namespace n002071d8

// 00207230 (was gap, written for the unit)
namespace n00207230 {
void func_00207230(u8* base, u8* c) asm("func_00207230");
void func_00207230(u8* base, u8* c) {
    s32* off = *(s32**)(c + 12);
    u8* p = base + off[1] + 160;
    s32* q = (s32*)(base + off[0] + 160);
    *p = 0;
    q[2]++;
}
}  // namespace n00207230

// 00207260 (was src/anon/batch_w34.cpp)
namespace n00207260 {
/*TARGET 00207260*/
// Returns a random float in [0,1) from the VU0 random unit (hand-written VU0 macro code).
f32 func_00207260(void) asm("func_00207260");
// Returns a random float in [0,1) from the VU0 random unit (hand-written VU0 macro code).
f32 func_00207260(void) {
    f32 r;
    asm volatile(
        "addi $8, $0, -1\n\t"
        "qmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vitof0.x $vf2, $vf2\n\t"
        "vadd.x $vf1, $vf1, $vf2\n\t"
        "qmfc2 %0, $vf1"
        : "=r"(r) : : "$8");
    return r;
}
}  // namespace n00207260

// 002072a8 (was src/anon/batch_w45.cpp)
namespace n002072a8 {
f32 func_00207260(void) asm("func_00207260");
/*TARGET 002072a8*/
// 0x001eb228: definition moved into src/anon/unit_001e8ac8.cpp

// random value in about [-n/2, 3n/2)
s8 func_002072a8(u8 n) asm("func_002072a8");
// 0x001eb228: definition moved into src/anon/unit_001e8ac8.cpp

// random value in about [-n/2, 3n/2)
s8 func_002072a8(u8 n) {
    func_00207260();
    return (s8)(s32)((f32)(n * 2) * func_00207260() - (f32)(n >> 1));
}
}  // namespace n002072a8

// 00207308 (was src/anon/batch_w33.cpp)
namespace n00207308 {
struct A207 { u8 pad[16]; s32 a; s32 b; s32 c; };
struct B207 { u8 pad[257]; u8 x; u8 pad2[4]; u8 y; };
/*TARGET 00207308*/
s32 func_00207308(A207* a, B207* b) asm("func_00207308");
s32 func_00207308(A207* a, B207* b) {
    if (!a->a) return 0;
    if (b->y && !a->b) return 0;
    if (b->x && !a->c) return 0;
    return 1;
}
}  // namespace n00207308

