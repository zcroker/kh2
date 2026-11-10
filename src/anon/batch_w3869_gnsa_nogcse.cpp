/* 0020d1d0: draws one coloured render entry (soft-double scale of D_01d9e8c0.f56). */
#include "../common/types.h"
typedef struct { s32 key; s32 id; f32 v[3]; u8 b20, b21, b22, b23; f32 f24; u8 b28; } Ent20d1d0;
typedef struct { u8 pad0[12]; s32* off; } Ctx20d1d0;
typedef struct { u8 pad0[56]; f32 f56; } Blk20d1d0;
typedef struct { u8 pad0[24]; s32 w24; u32* p28; u8 pad32[4]; } Tab20d1d0;
typedef struct { u8 pad0[16]; Tab20d1d0* tab; } Bank20d1d0;
typedef struct { u8 pad0[144]; s32 w144; } View20d1d0;
typedef struct {
    u64 q0;
    u64 q8;
    Blk20d1d0* p16;
    Blk20d1d0* p20;
    void* p24;
    u32* p28;
    f32 f32_;
    u32 w36;
    u64 q40;
    f32* p48;
    f32* p52;
    s32 w56;
    s32 w60;
    s32 w64;
    u32 w68;
    u8 b72;
} Req20d1d0;
extern s32 D_01d9ea9c;
extern Bank20d1d0* D_01d9e6e4;
extern View20d1d0* D_01d9e6e8;
extern Blk20d1d0 D_01d9e8c0;
extern f32 D_00354be0[];
extern s32 D_00352be4, D_00352be8, D_00352bec, D_00352bf0, D_00352bf8, D_00352bfc;
extern u64 D_00352c18;
extern "C" {
void sceVu0ScaleVector(f32*, f32*, f32);
u64 func_00313b80(f32);
u64 __subdf3(u64, u64);
u64 func_00313f40(u64, u64);
u64 func_00314190(u64, u64);
f32 __truncdfsf2(u64);
void* func_0020eaf8(s32);
void func_0020ebd8(s32);
void func_0020d528(Req20d1d0*, u8);

void func_0020d1d0(u8* base, Ent20d1d0* e, Ctx20d1d0* c)
{
    Blk20d1d0* m = (Blk20d1d0*)(base + c->off[2] + 160);
    f32* pos = (f32*)(base + c->off[0] + 160);
    u8* col;
    f32 v[4];
    Req20d1d0 r;
    f32 save;
    struct { u8 v; } fl;
    s32 id;
    if (D_01d9ea9c == 0) {
        f32 ax = pos[2];
        f32 vx = pos[1] + ax;
        f32 x = pos[0] + vx;
        pos[1] = vx;
        pos[0] = x;
        if (*(s32*)(base + 12) == e->key) {
            pos[0] = x + e->v[0];
            pos[1] = vx + e->v[1];
            pos[2] = ax + e->v[2];
        }
    }
    if (e->id == 0xffff) return;
    c = (Ctx20d1d0*)(base + c->off[1] + 160);
    col = (u8*)c;
    { u8 a = col[11]; u8 r, g, bl;
      if (a == 0) return;
      r = col[8]; g = col[9]; bl = col[10];
      v[2] = bl; v[3] = a; v[0] = r; v[1] = g; }
    register f32* a0v asm("$4") = v;
    sceVu0ScaleVector(a0v, v, 0.0078125f);
    save = D_01d9e8c0.f56;
    /* Partial asm: emits nothing. Reading the a0 argument gives its move one more
       dependent, so sched1 issues move a0,sp before move a1,sp as the original does. */
    asm("" : "+r"(pos) : "r"(a0v));
    D_01d9e8c0.f56 = __truncdfsf2(__subdf3(func_00313b80(save),
        func_00314190(func_00313f40(func_00313b80(e->f24), 0x416312D000000000ULL), func_00313b80(m->f56))));
    r.p16 = &D_01d9e8c0;
    r.p20 = m;
    r.p48 = v;
    r.p52 = v;
    r.p24 = func_0020eaf8(448);
    id = e->id;
    r.p28 = D_01d9e6e4->tab[id].p28;
    fl.v = e->b22;
    if (fl.v) r.f32_ = pos[0] * D_00354be0[0];
    else r.f32_ = pos[0];
    r.w36 = e->b21;
    r.w56 = D_01d9e6e8->w144;
    r.w60 = D_01d9e6e4->tab[id].w24;
    if (*r.p28 & 2) r.w64 = 0;
    else r.w64 = 1;
    r.w68 = fl.v;
    if (e->b20 == 0) {
        r.q8 = (D_00352bf8 << 5) | ((u64)(D_00352bec / 64) << 14) | ((u64)85 << 27);
        r.q0 = ((2048 - D_00352bec / 2) << 4) | ((u64)(2048 - D_00352bf0 / 2) << 36);
    } else {
        r.q8 = (D_00352bfc << 5) | ((u64)(D_00352be4 / 64) << 14) | ((u64)85 << 27);
        r.q0 = ((2048 - D_00352be4 / 2) << 4) | ((u64)(2048 - D_00352be8 / 2) << 36);
    }
    r.q40 = D_00352c18;
    r.b72 = e->b23;
    func_0020d528(&r, e->b28);
    D_01d9e8c0.f56 = save;
    func_0020ebd8(448);
}


}
