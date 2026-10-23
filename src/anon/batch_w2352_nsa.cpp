/* batch w2352, built with -fno-strict-aliasing (_nsa). */
#include "../common/types.h"

struct Ent { u8 pad[0x28]; u16 id; };
struct Res { u8 pad[8]; s32 v; };
struct Sub {
    u32 vt;
    s32 f4, f8, fc, f10, f14, f18, f1c;
};
struct Obj {
    Ent* ent;       /* 0x00 */
    s32 h;          /* 0x04 */
    s32 f8;         /* 0x08 */
    u8 pad0c[0x0c];
    u8 s18[0x1c];   /* 0x18 */
    s32 f34;        /* 0x34 */
    u8 pad38[0x0c];
    Sub* psub;      /* 0x44 */
    Sub sub;        /* 0x48 */
    u8 s68[4];      /* 0x68 */
    u8 s6c[0x3c];   /* 0x6c */
    u8 sa8[4];      /* 0xa8 */
    u8 sac[4];      /* 0xac */
};

extern "C" {
extern u8 D_00350e48[];
extern u8 D_0036da78[];
extern u8 D_0036da80[];
Res* func_00168b38(s32, s32, s32);
void func_0016cbc8(s32, s32, void*, s32);
s32 func_0016d080(s32, s32);
s32 func_001708f8(s32, s32);
void func_001b4c48(Obj*, void*, void*);
void func_001b5708(Obj*, s32);
void func_001d1698(void*, s32, s32, s32);
void func_001d16e8(void*, s32, s32);
void func_001d1a18(void*, s32, s32, s32);
void func_001d1d00(void*);
void func_001d1da0(void*, f32);
void func_001d20a8(void*);
void func_001d2248(void*, s32);
s32 func_001d3f98(Ent*);
s32 func_001d4550(Ent*);
void func_001dddd0(void*, s32);

static inline bool valid(Res* r) { return r && r->v; }

/* 001b4a00: set-up step of an entity: reads its parameters (0x14, 0x12, 3, 0x22) and initialises the sub-objects. */
void func_001b4a00(Obj* self, f32 f)
{
    Res* r;
    self->h = func_001708f8(func_001d3f98(self->ent), -1);
    r = func_00168b38(self->h, 0x14, 0);
    if (valid(r)) {
        self->f8 = r->v;
    }
    r = func_00168b38(self->h, 0x12, 0);
    if (valid(r)) {
        func_001dddd0(self->s18, r->v);
    }
    r = func_00168b38(self->h, 3, 0);
    if (valid(r)) {
        Obj* tmp;
        s32 m = func_0016d080(r->v, 0);
        self->f34 = m;
        tmp = self;
        func_0016cbc8(m, 0x16, &tmp, 1);
    }
    r = func_00168b38(self->h, 0x22, 0);
    if (valid(r)) {
        s32 v = r->v;
        Sub* s = &self->sub;
        /* The original addresses these words without the field types: as plain
           field stores gcc reorders them (it can tell the fields apart). */
        *(s32*)((u8*)s + 8) = -1;
        *(s32*)((u8*)s + 20) = 0x1800;
        *(s32*)((u8*)s + 12) = 0;
        *(s32*)((u8*)s + 16) = 0;
        s->f1c = v;
        s->vt = (u32)D_00350e48;
        *(s32*)((u8*)s + 4) = 2;
        self->psub = s;
    }
    func_001b4c48(self, self->s6c, D_0036da78);
    func_001d1a18(self->s68, 0, 999, 0);
    func_001d2248(self->s68, func_001d4550(self->ent));
    if (self->ent->id != 0x1e4 && self->ent->id != 0x26c) {
        func_001d20a8(self->s68);
    }
    func_001b4c48(self, self->sac, D_0036da80);
    func_001d16e8(self->sa8, 1, 12);
    {
        s32 i = (s32)f;
        func_001d1698(self->sa8, i, i, 0);
    }
    func_001d1da0(self->sa8, f);
    func_001d1d00(self->sa8);
    if (self->ent->id == 0x1e4) {
        func_001b5708(self, 3);
    }
}
}

/* ---- 00222d40 ---- */

struct Ent24 { u8 pad[0x1c]; u32* data; s32 f20; };
struct Tbl { u8 pad[0x10]; Ent24* ents; };
struct Ctx { u8 pad[0x10]; u8 a[0x40]; u8 b[0x40]; s32 f90; s32 f94; };
struct Param {
    u32 flags;      /* 00 */
    void* p04;      /* 04 */
    u16 h08;        /* 08 */
    u8 b0a;         /* 0a */
    u8 pad0b;
    s16 h0c;        /* 0c */
    s16 h0e;        /* 0e */
    s32 x;          /* 10 */
    s32 y;          /* 14 */
    u8 c[4];        /* 18 */
    s32 f1c;        /* 1c */
    void* p20;      /* 20 */
    void* p24;      /* 24 */
    void* p28;      /* 28 */
    void* p2c;      /* 2c */
    void* p30;      /* 30 */
    s32 prev;       /* 34 */
    s32 f38;        /* 38 */
    s32 f3c;        /* 3c */
    s32 f40;        /* 40 */
    s32 f44;        /* 44 */
    u8 pad48[0x18];
};

extern "C" {
extern Tbl* D_01d9e6e4;
extern Ctx* D_01d9e6e8;
extern u8 D_01d9e840[];
extern u8 D_01d9e980[];
extern u8 D_01d9e9c0[];
extern s32 D_01d9eaa4;
extern u8 D_01d9eac0[];
void func_002f3d08(void*, void*, void*);
s32 func_0020f1e0(u32*, Param*, s32);

/* 00222d40: builds a draw parameter block for sprite idx (colour col, position x/y, flags fl) and submits it. */
void func_00222d40(s32 idx, u16* col, s32 z, s32 x, s32 y, u8 fl, s32 extra)
{
    Ent24* e;
    u32* d;
    u8 buf[0x40];
    Param p;
    if (idx == 0xffff) return;
    e = &D_01d9e6e4->ents[idx];
    d = e->data;
    p.flags = 0;
    if (fl & 2) {
        p.flags = 4;
        if ((*d & 1) == 0) p.flags |= 8;
    } else {
        if ((bool)(fl & 1)) p.flags = 0x80;
        if ((*d & 1) == 0) p.flags |= 8;
    }
    if ((*d & 2) == 0) p.flags |= 0x10;
    if (fl & 4) p.flags |= 0x200;
    if (fl & 8) p.flags |= 0x100;
    if (fl & 0x10) {
        p.flags |= 0x2000;
        p.p30 = buf;
        func_002f3d08(buf, D_01d9e840, D_01d9e6e8->a);
    }
    p.f44 = (fl & 0x20) ? extra : 0;
    /* These two go through casts: as field stores gcc lets the global loads below move above them. */
    *(u16*)((u8*)&p + 8) = ((u16*)d)[0x16 / 2];
    *(s32*)((u8*)&p + 0x1c) = 0;
    p.f38 = D_01d9e6e8->f90;
    p.f3c = D_01d9e6e8->f94;
    p.h0e = z;
    p.p04 = D_01d9eac0;
    p.x = x << 16;
    p.y = y << 16;
    p.c[0] = col[0] >> 7;
    p.c[1] = col[1] >> 7;
    p.c[2] = col[2] >> 7;
    p.c[3] = col[3] >> 7;
    p.p20 = D_01d9e6e8->b;
    p.p24 = D_01d9e9c0;
    p.p28 = D_01d9e980;
    p.p2c = D_01d9e6e8->a;
    p.prev = D_01d9eaa4;
    p.h0c = 0;
    p.f40 = 0;
    p.b0a = 0;
    D_01d9eaa4 = func_0020f1e0(d, &p, e->f20);
}
}
