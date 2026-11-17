// Linked unit 0x001fe158-0x001fe8d8.
#include "../common/types.h"
#include <stdarg.h>

// 001fe158 (was gap)
namespace n001fe158 {
struct Gs { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct Idx { s32 f0; s32 f4; s32 f8; s32 f12; };
struct Ctx { u8 pad[12]; Idx* idx; };
struct Mot { f32 x, vx, ax; };
struct Req {
    s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 b29, b30, b31, b32, b33;
};
struct Tex { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Gs* D_01d9e6e0 asm("D_01d9e6e0");
extern Gs* D_01d9e6e4 asm("D_01d9e6e4");
extern u8* D_01d9eaa4 asm("D_01d9eaa4");
union IdU { s32 v; u8 c; };
union TagU { u64 v; u8 c; };
union PkU { u8* p; u8 c; };
void sceGsSetDefLoadImage(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) asm("sceGsSetDefLoadImage");
void func_00222aa8(s32 a, s32 b, u8* p, f32 x) asm("func_00222aa8");
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c) asm("func_0020e7a8");
void func_00222d40(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, u8* b) asm("func_00222d40");
void func_001fe158(u8* o, Req* r, Ctx* c) asm("func_001fe158");
void func_001fe158(u8* o, Req* r, Ctx* c)
{
    Mot* m = (Mot*)(o + c->idx->f8 + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0->st & 0xff0000ff00ULL)) {
        m->vx += m->ax;
        m->x += m->vx;
        if (((IdU*)(o + 12))->v == ((IdU*)&r->id)->v) {
            m->x += r->dx;
            m->vx += r->dvx;
            m->ax += r->dax;
        }
    }
    if (r->tex == 0xffff) return;
    {
        s32 off = r->tex * 36;
        u32 frame = r->frame * 4;
        u8* p = D_01d9eaa4 + 16;
        u32 bits = ((Tex*)(D_01d9e6e4->ent + off))->bits;
        u8* q;
        sceGsSetDefLoadImage(p, ((bits >> 5) & 0x3fff) + frame, 4, (bits >> 19) & 0xf, 0, 0, 16, 16);
        ((TagU*)(p + 80))->v = 0x0800000000008100ULL;
        q = ((PkU*)&D_01d9eaa4)->p;
        func_00222aa8(r->sx, r->sy, q + 112, m->x);
        func_0020e7a8(D_01d9eaa4, 263, 0, 0);
        ((PkU*)&D_01d9eaa4)->p = q + 4208;
        func_00222d40(r->tex, o + c->idx->f0 + 160, frame, 0, 0, (r->b29 | r->b33) | (r->b31 | r->b30) | r->b32, o + c->idx->f12 + 160);
    }
}
}  // namespace n001fe158

// 001fe378 (was gap)
namespace n001fe378 {
struct S { s32 a, b, c; };
void func_001fe378(u8* self, u8* t) asm("func_001fe378");
void func_001fe378(u8* self, u8* t) {
    S* s = (S*)(self + (*(s32**)(t + 12))[2] + 0xa0);
    s->a = 0;
    s->b = 0;
    s->c = 0;
}
}  // namespace n001fe378

// 001fe398 (was src/anon/batch_wcx2.cpp)
namespace n001fe398 {
// --------------------
// Effect particle: integrate motion, apply the per-frame delta, then emit its sprite.
struct Gs1fe398 { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct Idx1fe398 { s32 f0; s32 f4; s32 f8; s32 f12; };
struct Ctx1fe398 { u8 pad[12]; Idx1fe398* idx; };
struct Mot1fe398 { f32 x, vx, ax, pad; f32 y, vy, ay, z, vz, az; };
struct Req1fe398 {
    s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 pad29[3];
    f32 dy, dvy, day, dz, dvz, daz; u8 b56, b57, b58, b59, b60;
};
struct Tex1fe398 { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Gs1fe398* D_01d9e6e0_x14106 asm("D_01d9e6e0");
extern Gs1fe398* D_01d9e6e4_x14107 asm("D_01d9e6e4");
extern u8* D_01d9eaa4 asm("D_01d9eaa4");
union IdU1fe398 { s32 v; u8 c; };
union TagU1fe398 { u64 v; u8 c; };
union PkU1fe398 { u8* p; u8 c; };
void sceGsSetDefLoadImage(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) asm("sceGsSetDefLoadImage");
void func_00222aa8(s32 a, s32 b, u8* p, f32 x) asm("func_00222aa8");
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c) asm("func_0020e7a8");
void func_00222d40_x14115(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, u8* b) asm("func_00222d40");
/*TARGET 001fe398*/
void func_001fe398(u8* o, Req1fe398* r, Ctx1fe398* c) asm("func_001fe398");
void func_001fe398(u8* o, Req1fe398* r, Ctx1fe398* c)
{
    Mot1fe398* m = (Mot1fe398*)(o + c->idx->f8 + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0_x14106->st & 0xff0000ff00ULL)) {
        m->vx += m->ax;
        m->vy += m->ay;
        m->vz += m->az;
        m->x += m->vx;
        m->y += m->vy;
        m->z += m->vz;
        if (((IdU1fe398*)(o + 12))->v == ((IdU1fe398*)&r->id)->v) {
            m->x += r->dx;
            m->vx += r->dvx;
            m->ax += r->dax;
            m->y += r->dy;
            m->vy += r->dvy;
            m->ay += r->day;
            m->z += r->dz;
            m->vz += r->dvz;
            m->az += r->daz;
        }
    }
    if (r->tex == 0xffff) return;
    {
        s32 off = r->tex * 36;
        u32 frame = r->frame * 4;
        u8* p = D_01d9eaa4 + 16;
        u32 bits = ((Tex1fe398*)(D_01d9e6e4_x14107->ent + off))->bits;
        u8* q;
        sceGsSetDefLoadImage(p, ((bits >> 5) & 0x3fff) + frame, 4, (bits >> 19) & 0xf, 0, 0, 16, 16);
        ((TagU1fe398*)(p + 80))->v = 0x0800000000008100ULL;
        q = ((PkU1fe398*)&D_01d9eaa4)->p;
        func_00222aa8(r->sx, r->sy, q + 112, m->x);
        func_0020e7a8(D_01d9eaa4, 263, 0, 0);
        ((PkU1fe398*)&D_01d9eaa4)->p = q + 4208;
        func_00222d40_x14115(r->tex, o + c->idx->f0 + 160, frame, (s32)m->y, (s32)m->z, (r->b56 | r->b60) | (r->b58 | r->b57) | r->b59, o + c->idx->f12 + 160);
    }
}
}  // namespace n001fe398

// 001fe648 (was gap)
namespace n001fe648 {
struct S { f32 a, b, c, d, e, f, g, h, i, j; };
void func_001fe648(u8* self, u8* t) asm("func_001fe648");
void func_001fe648(u8* self, u8* t) {
    S* s = (S*)(self + (*(s32**)(t + 12))[2] + 0xa0);
    s->a = s->b = s->c = s->e = s->f = s->g = s->h = s->i = s->j = 0.0f;
}
}  // namespace n001fe648

// 001fe688 (was gap)
namespace n001fe688 {
struct PDesc { u32 p0, p4, p8; s32* off; };
struct V { u16 x; u16 y; u16 z; };
struct PP { u8 pad[160]; V v; };
void func_001fe688(u8* o, PDesc* d) asm("func_001fe688");
void func_001fe688(u8* o, PDesc* d) { V* v = &((PP*)(o + d->off[0]))->v; v->x = v->y = v->z = 0; }
}  // namespace n001fe688

// 001fe6a8 (was gap)
namespace n001fe6a8 {
struct PMng { u8 pad[0xa8]; u64 f0 : 8; u64 f1 : 8; u64 f2 : 16; u64 f4 : 8; u64 f5 : 24; };
extern "C" s32 D_01d9ea9c;
extern "C" PMng* D_01d9e6e0;
struct PDesc { u32 p0, p4, p8; s32* off; };
struct AK { u8 p0[2]; s16 dur; s8 flags; u8 p5[3]; };
struct AN { u8 p0[6]; s16 count; u8 p8[8]; AK k[1]; };
struct AE { AN* an; u32 p4; };
struct G { u8 pad[20]; AE* tbl; };
extern "C" G* D_01d9e6e4;
struct V { u16 cnt, frame, idx; };
struct PP { u8 pad[160]; V v; };
struct M { s32 p0; s32 id; u16 spd; };
void func_001fe6a8(u8* o, M* m, PDesc* d) asm("func_001fe6a8");
void func_001fe6a8(u8* o, M* m, PDesc* d)
{
    if (D_01d9ea9c == 0 && D_01d9e6e0->f1 == 0 && D_01d9e6e0->f4 == 0) {
        V* v = &((PP*)(o + d->off[0]))->v;
        s32 id = m->id;
        if (id == 0xffff) return;
        AN* an = *(AN**)((u8*)D_01d9e6e4->tbl + (id << 3));
        u16 fr = v->frame;
        AK* k = &an->k[v->idx];
        v->idx = fr;
        v->cnt += m->spd;
        if (v->cnt >= k->dur) {
            v->cnt -= k->dur;
            v->frame = fr + 1;
            if ((u16)(fr + 1) >= an->count) {
                if (k->flags & 0x80) { v->frame = 0; v->cnt = 0; }
                else { v->frame = fr; v->cnt = 0; }
            }
        }
    }
}
}  // namespace n001fe6a8

// 001fe798 (was src/anon/batch_w3763_nsa.cpp)
namespace n001fe798 {
struct Prm { u16 a0; u16 flags; u8 c[4]; u64 z8; void* p10; s32 v14; u8 b18; u8 pad19[3]; void* p1c; u8 pad20[0x10]; };
struct Ent { s32 a; s32 b; };
struct Tbl { u8 pad[0x14]; Ent* ents; };
struct Rec { u8 pad[0x10]; s16 off; };
struct Node { u8 pad[4]; u16 idx; u8 pad6[2]; u8 c[4]; };
struct Arg1 { u8 pad[4]; s32 id; u8 pad8[4]; u8 bc, bd, be, bf, b10; };
struct Arg2 { u8 pad[0xc]; s32* offs; };
extern Tbl* D_01d9e6e4 asm("D_01d9e6e4");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
s32 func_0021d048(u8*, Prm*, s32) asm("func_0021d048");
/*TARGET 001fe798*/
void func_001fe798(u8* base, Arg1* a, Arg2* b) asm("func_001fe798");
void func_001fe798(u8* base, Arg1* a, Arg2* b) {
    s32* offs = b->offs;
    s32 id = a->id;
    Node* n0 = (Node*)(base + offs[0] + 0xa0);
    Node* n1 = (Node*)(base + offs[1] + 0xa0);
    if (id == 0xffff) return;
    Ent* e = &D_01d9e6e4->ents[id];
    Prm p;
    if (!a->bf) p.flags = 0x80; else p.flags = 0;
    if (a->b10 == 1) p.flags |= 0x10;
    if (a->bc) p.flags |= 0x800;
    if (a->bd) p.flags |= 0x400;
    if (a->be) p.p1c = base + offs[3] + 0xa0; else p.p1c = 0;
    p.p10 = D_01d9e6e8 + 0x50;
    p.c[0] = n1->c[0];
    p.c[1] = n1->c[1];
    p.c[2] = n1->c[2];
    p.c[3] = n1->c[3];
    p.z8 = 0;
    p.b18 = 0;
    u8* d = (u8*)e->a;
    u32 kk = n0->idx * 8;
    Rec* q = (Rec*)(d + kk);
    s32 of = q->off;
    p.v14 = D_01d9eaa4;
    s32 eb = e->b;
    u8* aa = d + of;
    D_01d9eaa4 = func_0021d048(aa, &p, eb);
}
}  // namespace n001fe798

