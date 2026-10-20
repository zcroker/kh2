#include "../common/types.h"
typedef f32 FMTX206[4][4] __attribute__((aligned(16)));
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
extern "C" {
extern Work206b* D_01d9e6e8;
extern Bank206b* D_01d9e6e4;
extern State206b* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern u8* D_01d9eaa4;
extern FMTX206 D_01d9e730;
extern FMTX206 D_01d9e8c0;
extern f32 D_00359a20[];
void func_002f3cd8(f32* out, f32 (*m)[4], f32* in);       // sceVu0ApplyMatrix
void func_002f3d08(f32 (*out)[4], f32 (*a)[4], f32 (*b)[4]); // sceVu0MulMatrix
void func_002f3f88(f32* out, f32* in);                  // sceVu0CopyVector
void func_002f3f98(f32 (*out)[4], f32 (*in)[4]);         // sceVu0CopyMatrix
void func_002f4000(f32 (*m)[4]);                        // sceVu0UnitMatrix
u8* func_0021d048(u8* data, DrawParam206b* p, s32 x);

void func_00206be8(List206b* list) {
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
        func_002f4000(D_01d9e6e8->view);
        D_01d9e6e8->view[0][0] = e->scale[0];
        D_01d9e6e8->view[1][1] = e->scale[1];
        D_01d9e6e8->view[2][2] = e->scale[2];
        func_002f3f98(D_01d9e6e8->world, D_01d9e6e8->view);
        func_002f3f88(D_01d9e6e8->world[3], s->pos);
        func_002f3cd8(D_01d9e6e8->view[3], D_01d9e730, s->pos);
        if (e->hasOffset) {
            func_002f3f98(local, D_01d9e6e8->view);
            local[3][0] += e->offset[0];
            local[3][1] += e->offset[1];
            local[3][2] += e->offset[2];
            func_002f3d08(local, D_01d9e8c0, local);
            p.localMtx = local;
        }
        func_002f3d08(D_01d9e6e8->view, D_01d9e8c0, D_01d9e6e8->view);
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
}
