#include "../common/types.h"

struct W1835V3 { f32 x, y, z; };
struct W1835Src { s32 id; s32 off; W1835V3 v; u8 k; };
struct W1835Idx { u8 pad[0xc]; s32* offp; };
struct W1835Obj { u8 pad[0xc]; s32 id; };
struct W1835Ctl { u8 pad[0xa8]; u64 flags; };

struct W1835Ent { u16 a; u16 type; s16 key; };
struct W1835Ctx { u8 pad[0x12]; u8 n; u8 pad2[0x34 - 0x13]; u16 ids[1]; };
struct W1835Res { u8 pad[6]; s8 idx; };
struct W1835Mode { u8 pad[0xb50]; s32 mode; };
struct W1835Self { u8 pad[0x268]; u8 sub[0x9e0 - 0x268]; W1835Mode* o; };
struct W1835Tbl { u8 pad[0x36f8]; u16 ids[4]; };

extern "C" {
extern s32 D_01d9ea9c;
extern W1835Ctl* D_01d9e6e0;
extern W1835V3 D_01d9e360;
extern W1835Tbl D_0032bb30;
extern u16 D_0036dc88[4];
void func_001bc778(void*);
W1835Res* func_001bc780(void*, u16, s32, s32);
W1835Ent* func_001b8e88(u16);
W1835Ctx* func_00177850(W1835Mode*);
f32 func_001ee5d8(u8);
f32 func_001ee5c8(f32, f32);
f32 func_001ee7a8(u8);
f32 func_001ee7a0(f32, f32);
f32 func_001ee988(u8);
f32 func_001ee980(f32, f32);

void func_001ee670(W1835Obj* self, W1835Src* p, W1835Idx* q) {
    f32* t;
    W1835V3* d;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (self->id == 0) {
        t = (f32*)((u8*)self + *q->offp + 0xa0);
        t[0] = func_001ee5d8(p->k);
        t[1] = func_001ee5d8(p->k);
        t[2] = func_001ee5d8(p->k);
    } else {
        if (p->id != self->id) return;
        t = (f32*)((u8*)self + *q->offp + 0xa0);
    }
    if (p->off != -1) d = (W1835V3*)((u8*)self + p->off + 0xa0);
    else d = &D_01d9e360;
    f32 b0 = t[0];
    d->x += func_001ee5c8(p->v.x, b0);
    d->y += func_001ee5c8(p->v.y, t[1]);
    d->z += func_001ee5c8(p->v.z, t[2]);
}

void func_001ee850(W1835Obj* self, W1835Src* p, W1835Idx* q) {
    f32* t;
    W1835V3* d;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (self->id == 0) {
        t = (f32*)((u8*)self + *q->offp + 0xa0);
        t[0] = func_001ee7a8(p->k);
        t[1] = func_001ee7a8(p->k);
        t[2] = func_001ee7a8(p->k);
    } else {
        if (p->id != self->id) return;
        t = (f32*)((u8*)self + *q->offp + 0xa0);
    }
    if (p->off != -1) d = (W1835V3*)((u8*)self + p->off + 0xa0);
    else d = &D_01d9e360;
    f32 b0 = t[0];
    d->x += func_001ee7a0(p->v.x, b0);
    d->y += func_001ee7a0(p->v.y, t[1]);
    d->z += func_001ee7a0(p->v.z, t[2]);
}

void func_001eea30(W1835Obj* self, W1835Src* p, W1835Idx* q) {
    f32* t;
    W1835V3* d;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (self->id == 0) {
        t = (f32*)((u8*)self + *q->offp + 0xa0);
        t[0] = func_001ee988(p->k);
        t[1] = func_001ee988(p->k);
        t[2] = func_001ee988(p->k);
    } else {
        if (p->id != self->id) return;
        t = (f32*)((u8*)self + *q->offp + 0xa0);
    }
    if (p->off != -1) d = (W1835V3*)((u8*)self + p->off + 0xa0);
    else d = &D_01d9e360;
    f32 b0 = t[0];
    d->x += func_001ee980(p->v.x, b0);
    d->y += func_001ee980(p->v.y, t[1]);
    d->z += func_001ee980(p->v.z, t[2]);
}


void func_001bed48(W1835Self* self) {
    void* sub = self->sub;
    s32 i = 0;
    func_001bc778(sub);
    W1835Tbl* t = &D_0032bb30;
    u16* alt = D_0036dc88;
    u16* ids = t->ids;
    do {
        u16 id = *ids;
        W1835Ent* e = func_001b8e88(id);
        s32 cnt;
        if (e->type == 3) {
            W1835Ctx* c = func_00177850(self->o);
            s32 j;
            cnt = 0;
            for (j = 0; j < c->n; j++) {
                if (c->ids[j] == e->key) cnt++;
            }
        } else {
            if (self->o->mode == 3) id = *alt;
            cnt = 1;
        }
        ids++;
        alt++;
        func_001bc780(sub, id, 0, cnt)->idx = i + 1;
        i++;
    } while (i < 4);
}

}
