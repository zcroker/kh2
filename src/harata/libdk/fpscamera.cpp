#include "fpscamera.hpp"

// dk::FPSCamera (0x14e2c0-0x14ecb8): the first-person camera (look around with the pad, clamped to
// the field of view around the target), and the GS copy packet it uses. The VU0 and 128-bit
// lq/sq copies are hand-written inline asm (VU0 macro code), as in the original.

#define GS_ZBUF(zbp, psm, zmsk) ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))
#define GS_FRAME(fbp, fbw, psm, fbmsk) \
    ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))
#define GS_SCISSOR(x0, x1, y0, y1) \
    ((u64)(x0) | ((u64)(x1) << 16) | ((u64)(y0) << 32) | ((u64)(y1) << 48))
#define GS_XYOFFSET(ofx, ofy) ((u64)(ofx) | ((u64)(ofy) << 32))
#define GS_RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define GS_UV(u, v) ((u64)(u) | ((u64)(v) << 16))
#define GS_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
#define GS_CLAMP(wms, wmt, minu, maxu, minv, maxv) ((u64)(wms) | ((u64)(wmt) << 2))
#define GIF_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | ((u64)(flg) << 58) | ((u64)(nreg) << 60))

struct DmaTag {
    u16 qwc; u8 pad; u8 id; void* next;
    void Set(u16 q, void* n) { qwc = q; id = 0; next = n; }
};
struct Env { u32 fbp; u16 w; u16 h; u16 psm; u8 pad[6]; };
struct TexInfo { u32 w0; u16 w; u16 h; u16 h8; u8 pad[6]; };
struct Strip { u64 uv0, xyz0, uv1, xyz1; };
struct Pkt {
    u64 giftag[2];
    u64 zbuf, zbufReg;
    u64 frame, frameReg;
    u64 tex0, tex0Reg;
    u64 tex1, tex1Reg;
    u64 test, testReg;
    u64 alpha, alphaReg;
    u64 scissor, scissorReg;
    u64 xyoffset, xyoffsetReg;
    u64 clamp, clampReg;
    u64 giftag2[2];
    u64 prim, rgbaq;
    u64 giftag3[2];
    Strip strip[16];
};
struct CopyPkt {
    DmaTag tag; u8 pad0[8];
    Pkt pkt;
    Env env;
    TexInfo tex;
    u8 pad1[0x4d0 - 0x300];
    u8 bright;
};
struct V14e8b8 {
    f32 x, y, z, w;
    V14e8b8() {}
    V14e8b8& operator=(const V14e8b8& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V14e8b8 operator+(const V14e8b8& o) const {
        V14e8b8 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M14e8b8 {
    V14e8b8 r[4];
    V14e8b8 operator*(const V14e8b8& v) const {
        V14e8b8 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Pad14e8b8 { u8 pad0[8]; u64 flags; u8 pad1[36 - 16]; f32 stick; u8 pad2[4]; f32 scale; };
struct Cam14e8b8 {
    V14e8b8 eye;
    V14e8b8 at;
    u8 pad32[76 - 32];
    f32 f76;
    f32 f80;
    u8 pad84[96 - 84];
    V14e8b8 tgt;
    u8 pad112[128 - 112];
    V14e8b8 pos;
    u8 pad144[192 - 144];
    f32 yaw;
    f32 pitch;
};
struct W290Q { f32 x, y, z, w; } __attribute__((aligned(16)));

extern "C" {
u32 D_0034a3f0 = 0;      // the target object
W290Q* D_0034a3f4 = 0;  // the point to look from
f32 D_0034a3f8 = 0;      // height offset
extern f32 D_00349e10;
}
static inline f32 Angle(f32 a) { return a; }
static f32 s_pitchMin = Angle(-0.523598731f);
static f32 s_pitchMax = Angle(1.22173035f);

extern "C" {
u64 func_00166730(TexInfo*);
void func_001669e0(u8*);
void func_0014d8d0(u8*);
void func_0014ddb0(u8*);
W290Q* func_0016c028(u32);
f32 func_002f8ad0(f32, f32);
void* func_00106a18(s32);
f32 func_00106f30(void*, s32);
void func_00141010(f32);
Cam14e8b8* func_00140df0(void);
u32 func_00140dc0(void);
void func_00140dd0(Cam14e8b8*);
s32 c14e8b8_19ba60(void*) asm("func_0019ba60");
void func_0013f5f0(Cam14e8b8*);
V14e8b8* c14e8b8_16c028(void*) asm("func_0016c028");
Pad14e8b8* c14e8b8_167f18(s32) asm("func_00167f18");
void c14e8b8_11b6a8(M14e8b8*) asm("func_0011b6a8");
void c14e8b8_11b6d8(M14e8b8*, f32) asm("func_0011b6d8");
void c14e8b8_11b720(M14e8b8*, f32) asm("func_0011b720");
s32 func_001584f8(Pad14e8b8*);
s32 func_00158548(Pad14e8b8*);
s32 func_00158450(Pad14e8b8*);
s32 func_001584a0(Pad14e8b8*);
f32 func_0017ce10(f32);
f32 fabsf(f32);

void func_0014e2c0(CopyPkt* p)
{
    Env* env = &p->env;
    TexInfo* tex = &p->tex;
    Pkt* g = &p->pkt;
    s32 n = env->w >> 5;
    g->giftag[1] = 0xeeeeeeeeeULL;
    g->zbuf = GS_ZBUF(0x70, 0x31, 1);
    g->zbufReg = 0x4e;
    g->giftag[0] = GIF_TAG(1, 0, 0, 0, 0, 9);
    g->frame = GS_FRAME(env->fbp, (u16)(env->w >> 6), env->psm, 0);
    g->frameReg = 0x4c;
    g->tex0 = func_00166730(tex);
    g->tex0Reg = 6;
    g->tex1 = 0x60;
    g->tex1Reg = 0x14;
    g->test = 0x30000;
    g->testReg = 0x47;
    g->alpha = 0x44;
    g->alphaReg = 0x42;
    g->scissor = GS_SCISSOR(0, env->w - 1, 0, env->h - 1);
    g->scissorReg = 0x40;
    g->xyoffset = GS_XYOFFSET((2048 - (env->w >> 1)) << 4, (2048 - (env->h >> 1)) << 4);
    g->xyoffsetReg = 0x18;
    g->clamp = 5;
    g->clampReg = 8;
    g->giftag2[0] = GIF_TAG(1, 0, 0, 0, 1, 2) | 1;
    g->giftag2[1] = 0x10;
    g->prim = 0x116;
    g->rgbaq = GS_RGBAQ(p->bright, p->bright, p->bright, 0x80, 1);
    g->giftag3[0] = GIF_TAG(n, 1, 0, 0, 1, 4);
    g->giftag3[1] = 0x5353;
    s32 q = tex->w / n;
    s32 h = env->h;
    u64 tx = (u64)(2048 - (env->w >> 1)) << 4;
    s32 ofx = tx;
    u64 ty = (u64)(2048 - (env->h >> 1)) << 4;
    s32 ofy = ty; u16 hh = h;
    u16 th = tex->h;
    for (s32 i = 0; i < n; i++) {
        Strip* s = &g->strip[i];
        s->uv0 = GS_UV(((i * q) << 4) + 8, 8);
        s->xyz0 = GS_XYZ((u32)(ofx + (i << 9)), (u32)ofy, 0);
        s->uv1 = GS_UV((((i + 1) * q) << 4) + 8, (th << 4) + 8);
        s->xyz1 = GS_XYZ((u32)(ofx + ((i + 1) << 9)), (u32)(ofy + (hh << 4)), 0);
    }
    p->tag.Set((n * 32 + 208) >> 4, g->giftag);
}


void func_0014e5b0(CopyPkt* p, u8 b) {
    p->bright = b;
    p->pkt.rgbaq = GS_RGBAQ(b, b, b, 0x80, 1);
}

void func_0014e5f0(u8* p) {
    func_001669e0(p + 736);
    func_0014d8d0(p);
}

void func_0014e620(u8* p) {
    func_0014ddb0(p + 752);
}

u8* func_0014e638(u8* p) { return p + 736; }
u8* func_0014e648(u8* p) { return p + 752; }

// Yaw/pitch (atan2) of the offset from the target to the eye point.
void func_0014e658(Cam14e8b8* c) {
    f32 d[4] __attribute__((aligned(16)));
    W290Q* a = D_0034a3f4;
    W290Q* b = func_0016c028(D_0034a3f0);
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
    d[1] += D_0034a3f8;
    c->yaw = func_002f8ad0(d[0], d[2]);
    c->pitch = -func_002f8ad0(d[1], __builtin_sqrtf(d[0] * d[0] + d[2] * d[2]));
}

// Clamps yaw and pitch to the field of view around the target.
void func_0014e6f8(Cam14e8b8* c) {
    W290Q* a = D_0034a3f4;
    W290Q* b = func_0016c028(D_0034a3f0);
    W290Q d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(a), "r"(b) : "memory");
    d.y += D_0034a3f8;
    f32 t = func_002f8ad0(d.x, d.z);
    f32 r = func_0017ce10(c->yaw - t);
    f32 lim = func_00106f30(func_00106a18(1), 0) * 0.5f - 0.17453292f;
    if (r < -lim) c->yaw = func_0017ce10(t - lim);
    else if (lim < r) c->yaw = func_0017ce10(t + lim);
    t = -func_002f8ad0(d.y, __builtin_sqrtf(d.x * d.x + d.z * d.z));
    r = func_0017ce10(c->pitch - t);
    lim = func_00106f30(func_00106a18(1), 1) * 0.5f - 0.17453292f;
    if (r < -lim) c->pitch = func_0017ce10(t - lim);
    else if (lim < r) c->pitch = func_0017ce10(t + lim);
    if (s_pitchMax < c->pitch) c->pitch = s_pitchMax;
    else if (c->pitch < s_pitchMin) c->pitch = s_pitchMin;
}

void func_0014e8b8(Cam14e8b8* c)
{
    if (!c14e8b8_19ba60((void*)D_0034a3f0)) {
        dk::FPSCamera::destroy();
        return;
    }
    func_0013f5f0(c);
    c->tgt = *c14e8b8_16c028((void*)D_0034a3f0);
    c->tgt.y -= D_0034a3f8;
    Pad14e8b8* pad = c14e8b8_167f18(0);
    if (pad->flags & 0x20000) {
        func_0014e658(c);
    } else {
        f32 dt = D_00349e10;
        if (func_001584f8(pad)) c->yaw = func_0017ce10(c->yaw - dt * 0.05235987901687622f);
        else if (func_00158548(pad)) c->yaw = func_0017ce10(c->yaw + dt * 0.05235987901687622f);
        c->f76 = c->f80 = func_0017ce10(c->yaw - 3.1415927410125732f);
        if (func_00158450(pad)) c->pitch = func_0017ce10(c->pitch + fabsf(pad->stick * pad->scale) * 0.05235987901687622f * dt);
        else if (func_001584a0(pad)) c->pitch = func_0017ce10(c->pitch - fabsf(pad->stick * pad->scale) * 0.05235987901687622f * dt);
    }
    func_0014e6f8(c);
    V14e8b8 v;
    v.w = v.y = v.x = 0.0f;
    v.z = 100.0f;
    M14e8b8 m;
    c14e8b8_11b6a8(&m);
    c14e8b8_11b6d8(&m, c->pitch);
    c14e8b8_11b720(&m, c->yaw);
    v = m * v;
    c->pos = c->tgt + v;
    c->at = c->tgt;
    c->eye = c->pos;
}


void func_0014eb48(u32 target, W290Q* from, f32 height) {
    func_00141010(30.0f);
    Cam14e8b8* c = func_00140df0();
    *(s32*)((u8*)c + 64) = 9;
    D_0034a3f0 = target;
    D_0034a3f4 = from;
    D_0034a3f8 = height;
    func_0014e658(c);
    func_0014e6f8(c);
    func_0014e8b8(c);
}

}  // extern "C"

namespace dk {

void FPSCamera::destroy() {
    Cam14e8b8* c = func_00140df0();
    if (func_00140dc0() == 9) func_00140dd0(c);
}

void FPSCamera::adjust() {
    func_0014e658(func_00140df0());
}

}  // namespace dk
