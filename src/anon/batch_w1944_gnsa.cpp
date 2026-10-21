#include "../common/types.h"

// 001ea758: morph blend of two s16 vertex shapes; -fno-strict-aliasing.
struct W1944SV { s16 x, y, z; };
struct W1944MorphShape { s32 count; u8 pad4[0x10]; W1944SV* verts; u8 pad18[0xc]; };
struct W1944MorphMgr { u8 pad0[0x10]; W1944MorphShape* shapes; };
struct W1944MorphState { f32 t; u8 pad4[8]; W1944SV* buf; };
struct W1944MorphKeys { u32 pad0; s32 from; s32 to; };
struct W1944MorphCtx { u8 pad0[0xc]; s32* offset; };
struct W1944MorphOut { u8 pad0[0x90]; W1944SV* buf; };
extern "C" {
extern W1944MorphMgr* D_01d9e6e4;
extern W1944MorphOut* D_01d9e6e8;
W1944SV* func_001e7698(W1944MorphMgr*, s32);
void func_001ea758(u8* base, W1944MorphKeys* k, W1944MorphCtx* c)
{
    if (k->from == 0xffff && k->to == 0xffff) return;
    W1944MorphState* st = (W1944MorphState*)(base + *c->offset + 0xa0);
    W1944SV* va = D_01d9e6e4->shapes[k->from].verts;
    W1944SV* vb = D_01d9e6e4->shapes[k->to].verts;
    s32 n = D_01d9e6e4->shapes[k->from].count;
    if (st->buf == 0) st->buf = func_001e7698(D_01d9e6e4, n * 6);
    W1944SV* out = st->buf;
    while (n--) {
        out->x = (s16)(s32)((f32)(vb->x - va->x) * st->t + (f32)va->x);
        out->y = (s16)(s32)((f32)(vb->y - va->y) * st->t + (f32)va->y);
        out->z = (s16)(s32)((f32)(vb->z - va->z) * st->t + (f32)va->z);
        va++; vb++; out++;
    }
    D_01d9e6e8->buf = st->buf;
}
}

// 0029de18: the first flag store goes through an int-parameter setter (keeps the two li 1 apart).
extern "C" {
struct W1944S43 { u8 pad[0xb8]; u32 fl; };
extern s32 D_0035f210;
extern s32 D_0035f3d4;
extern s16* D_0035f5ac;
void func_001386e0(u8*, s32, s32, u8*, s32, s32);
void func_00138c68(u8*, s32, s32);
void func_00139620(u8*);
s32 func_00139d78(u8*);
void func_002362b0(u8*, s32);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
s32 func_0023c4b8(s32, s32);
s32 func_0023f1b0(s32);
s32 func_00276638(s32);
u8* func_002766d0();
void func_0028dcc0(u8*, u8*);
s32 func_00292a90(s32);
s32 func_00293148(s32);
s8* func_0029da68(s32);
void func_0029dda8();
static inline __attribute__((always_inline)) void w1944_set8(u8* p, s32 v) { *p = v; }
void func_0029de18(void) {
    u8* w = func_002766d0();
    func_0029dda8();
    u8* obj = w + 0x4398;
    s32 kind = func_0029da68(D_0035f5ac[func_00276638(0xF) + 4])[1];
    if (func_00292a90(kind) == 0) return;
    if (func_00139d78(obj) != 0) return;
    u8* s3 = w + 0x18;
    s32 s1 = D_0035f3d4 + 2;
    s32 s2 = func_0023c4b8(func_0023f1b0(D_0035f210), 0);
    u8* e = w + 0xDCA0;
    func_002362b0(e, func_00293148(kind));
    w1944_set8(e + 0x190, 1);
    func_001386e0(obj, s1, s2, e, 1, 0);
    *(s32*)(obj + 0x188) = 2;
    func_00139620(obj);
    W1944S43* f = (W1944S43*)(w + 0x43B0);
    f->fl |= 8;
    obj[0x195] = 1;
    func_0028dcc0(obj, w);
    s32 a = func_0023aa18(s3);
    func_00138c68(obj, a, func_0023aa38(s3));
}
}

// 001cb720: VU0 vector macros (lqc2/vmulx/vadd) and an lq/sq copy as asm.
struct W1944QV {
    f32 x, y, z, w;
    W1944QV() {}
    W1944QV(const W1944QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1944QV& operator*=(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    W1944QV& operator+=(const W1944QV& b) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    W1944QV operator+(const W1944QV& b) const {
        W1944QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1944CamPos { u8 pad[48]; W1944QV pos; };
struct W1944Cam;
struct W1944CamVt { u8 pad[160]; W1944CamPos* (*get)(W1944Cam*); };
struct W1944Cam { W1944CamVt* vt; };
struct W1944Fx {
    W1944QV v;
    u8 pad10[6];
    s8 alpha;
    u8 pad17[0x40 - 0x17];
    f32 time;
    u8 pad44[0x70 - 0x44];
    W1944QV ofs;
    u8 pad80[0xa0 - 0x80];
    f32 ang;
    f32 pada4;
    f32 angVel;
    f32 scale;
};
extern "C" {
extern f32 D_00349e10;
extern f32 D_00351fd8;
W1944Cam* func_002d1260();
s32 func_0019ba60(W1944Cam*);
f32 func_001cbf50(f32);
f32 func_002f87c0(f32);
f32 func_002f8960(f32);

s32 func_001cb720(W1944Fx* o)
{
    W1944Cam* cam = func_002d1260();
    o->time -= D_00349e10;
    if (o->time <= 0.0f || func_0019ba60(cam) == 0) return 0;
    o->ang += o->angVel * D_00349e10;
    f32 r = o->time / D_00351fd8;
    f32 a = func_001cbf50(o->ang);
    o->v.x = func_002f87c0(a);
    o->v.y = func_002f8960(a);
    o->v.z = 0.0f;
    o->v *= o->scale * r;
    W1944QV t = o->ofs;
    t *= t.w * r;
    o->v += t + cam->vt->get(cam)->pos;
    o->alpha = (s8)(s32)(r * 255.0f);
    return 1;
}
}
