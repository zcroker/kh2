#include "../common/types.h"
#define CBQCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct CbV {
    f32 x, y, z, w;
    CbV() {}
    CbV& operator=(const CbV& o) { if (this != &o) CBQCOPY(this, &o); return *this; }
    CbV operator-(const CbV& b) const {
        CbV r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct CbObj;
typedef CbV (*CbVFn)(CbObj*);
struct CbObj { CbVFn* vt; };
struct CbRange { u8 pad[12]; s16 lo; s16 hi; };
struct CbSelf { u8 pad0[0x14]; u32 f14; u8 pad18[4]; CbObj* f1c; CbRange* f20; u8 pad24[2]; u8 f26; u8 f27; };
struct CbPrm { u8 pad[44]; f32 f2c; f32 f30; f32 f34; };
extern "C" {

// 0018cb30
extern CbPrm* D_00352130;
extern u32 D_003638d0;
s32 func_0018ca48(u8);
CbV* func_0016c028(u32);
void func_0018cd28(CbSelf*, f32*, f32*);
f32 func_0018cb30(CbSelf* self)
{
    CbV v;
    CbV* pv = &v;
    f32 r = D_00352130->f30;
    switch (func_0018ca48(self->f27)) {
    case 4:
        func_0018cd28(self, &pv->y, &pv->z);
        pv->x = 0.0f;
        r = pv->length() * D_00352130->f2c;
        break;
    case 5: {
        f32 len;
        f32 lo, hi;
        *pv = self->f1c->vt[2](self->f1c) - *func_0016c028(self->f14);
        pv->y = 0.0f;
        len = pv->length();
        lo = (f32)self->f20->lo;
        hi = (f32)self->f20->hi;
        D_003638d0 *= 0x10dcd;
        r = -(len - (lo + (f32)D_003638d0 * 2.3283064365386963e-10f * (hi - lo)));
        break;
    }
    case 3:
        r = D_00352130->f34;
    default:
        if (self->f20 && self->f20->lo != 0x7fff) r = (f32)self->f20->lo;
        break;
    }
    if (self->f26 == 12 || self->f26 == 13) r *= 0.5f;
    return r;
}

// 0019dd10
struct TgtD { u8 pad[32]; };
extern s32 D_0034f240;
void func_00190128(void*);
void dd_set_obj(TgtD*, u32, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 func_0019c4f8(u8*);
s32 func_0019dbc0(u8* a0, s32 a1, void* a2, s32 a3, s32 a4);
u8* dd_get_override(void*, s32) asm("_ZN2YS14PLAYER_COMMAND12get_overrideEi");
s32 dd_is_exec(void) asm("_ZN2YS5LIMIT6IsExecEv");
u8* func_0016bc20(void* a, s32 b, s32 id);
void func_0018a818(u8*, u8*, u8*);
void func_0019e170(u8*);
void func_0019e400(u8*);
s32 dd_is_exist(u8*) asm("_ZN2YS12COMMAND_SLOT8is_existEv");
s32 dd_is_pinch(u32) asm("_ZNK2YS5SHEET8is_pinchEv");
s32 func_0019e758(u8*, u8*);
s32 func_0019e6e8(u8*, u8*);
void func_0019ead0(u8*, u8*);
struct Sub140 { u8 pad[32]; u32 flags; u8 pad2[216]; u32 obj; };
void func_0019dd10(u8* self)
{
    TgtD tgt;
    u8* ob = *(u8**)(**(u8***)self + 0x9e0);
    func_00190128(&tgt);
    if (func_0019c4f8(ob)) return;
    if (D_0034f240 & 0x4000) return;
    if (*(u32*)(ob + 0x588) & 0x80) {
        s32 a1 = *(s32*)(ob + 0xb48);
        if (a1 && func_0019dbc0(self, a1, ob + 0x9f4, 201, 0)) self[9] = 8;
    }
    {
        u8* v = dd_get_override(**(void***)self, 1);
        if (v) func_0019dbc0(self, *(u16*)(v + 2), v + 12, 203, 0);
    }
    Sub140* sub = (Sub140*)(ob + 0x140);
    if (*(u32*)(ob + 0x160) & 0x100000) {
        dd_set_obj(&tgt, sub->obj, 0);
        if (func_0019dbc0(self, *(s32*)(ob + 0x50c), &tgt, 204, 0)) self[9] = 7;
    }
    if (dd_is_exec()) return;
    if (*(u32*)(ob + 0x588) & 0x2000000) return;
    {
        u8* t = func_0016bc20(ob, 1, -1);
        if (t) {
            func_0018a818(self + 48, ob, t);
            func_0019e170(self);
            func_0019e400(self);
        }
    }
    {
        s32 f = *(s32*)(self + 36);
        if (f >= 0 && (f & 0x40000000)) self[9] = 5;
    }
    if (dd_is_exist(self + 4)) return;
    if (!(*(u32*)(ob + 0x588) & 0x80)) return;
    if (*(u32*)(ob + 0x160) & 0x4000) return;
    if (!dd_is_pinch(*(u32*)(*(u8**)(ob + 0xb44) + 0x9e8))) return;
    if (func_0019e758(self, ob)) return;
    if (func_0019e6e8(self, ob)) return;
    func_0019ead0(self, ob);
}

// 001f7180, 001f7660
struct F7Gs { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct F7Idx { s32 f0; s32 f4; s32 f8; };
struct F7Ctx { u8 pad[12]; F7Idx* idx; };
struct F7Mot { f32 x, vx, ax; };
struct F7Req { s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 f29; };
struct F7Tex { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c;
extern F7Gs* D_01d9e6e0;
extern F7Gs* D_01d9e6e4;
extern u8* D_01d9eaa4;
union F7IdU { s32 v; u8 c; };
union F7TagU { u64 v; u8 c; };
union F7PkU { u8* p; u8 c; };
void func_002f28b8(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g);
void func_00222aa8(s32 a, s32 b, u8* p, f32 x);
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c);
void func_00222d40(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, s32 b);
void func_001f7180(u8* o, F7Req* r, F7Ctx* c)
{
    F7Mot* m = (F7Mot*)(o + c->idx->f8 + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0->st & 0xff0000ff00ULL)) {
        m->vx += m->ax;
        m->x += m->vx;
        if (((F7IdU*)(o + 12))->v == ((F7IdU*)&r->id)->v) {
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
        u32 bits = ((F7Tex*)(D_01d9e6e4->ent + off))->bits;
        u8* q;
        func_002f28b8(p, ((bits >> 5) & 0x3fff) + frame, 4, (bits >> 19) & 0xf, 0, 0, 16, 16);
        ((F7TagU*)(p + 80))->v = 0x0800000000008100ULL;
        q = ((F7PkU*)&D_01d9eaa4)->p;
        func_00222aa8(r->sx, r->sy, q + 112, m->x);
        func_0020e7a8(D_01d9eaa4, 263, 0, 0);
        ((F7PkU*)&D_01d9eaa4)->p = q + 4208;
        func_00222d40(r->tex, o + c->idx->f0 + 160, frame, 0, 0, 1, 0);
    }
}
void func_001f7660(u8* o, F7Req* r, F7Ctx* c)
{
    F7Mot* m = (F7Mot*)(o + c->idx->f8 + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0->st & 0xff0000ff00ULL)) {
        m->vx += m->ax;
        m->x += m->vx;
        if (((F7IdU*)(o + 12))->v == ((F7IdU*)&r->id)->v) {
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
        u32 bits = ((F7Tex*)(D_01d9e6e4->ent + off))->bits;
        u8* q;
        func_002f28b8(p, ((bits >> 5) & 0x3fff) + frame, 4, (bits >> 19) & 0xf, 0, 0, 16, 16);
        ((F7TagU*)(p + 80))->v = 0x0800000000008100ULL;
        q = ((F7PkU*)&D_01d9eaa4)->p;
        func_00222aa8(r->sx, r->sy, q + 112, m->x);
        func_0020e7a8(D_01d9eaa4, 263, 0, 0);
        ((F7PkU*)&D_01d9eaa4)->p = q + 4208;
        func_00222d40(r->tex, o + c->idx->f0 + 160, frame, 0, 0, r->f29, 0);
    }
}
}
