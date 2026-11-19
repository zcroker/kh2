// Linked unit 0x002ddbf0-0x002de010: Ti::MGJump jump set-up (vtable slot after YS::BTLOBJ; base 0x2d00d8), never
// written as a separate match. The VU0 vector operators are inline asm (as in unit_002de3c8's V).
#include "../common/types.h"
namespace n002ddbf0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { QCOPY(this, &o); }
    V& operator=(const V& o) { if (this != &o) QCOPY(this, &o); return *this; }
    V operator-(const V& b) const {
        V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V operator+(const V& b) const {
        V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V& operator+=(const V& b) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    f32 normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Prm { u8 p0[6]; s16 ang; s16 time; u8 pa[2]; u16 kind; u8 pe[6]; s16 f20; };
struct Ref { u8 p0[4]; f32 x, y, z; u8 p10[20]; f32 ang; };
struct Cfg { u8 p0[124]; f32 spd[4]; u8 p8c[36]; f32 f176; };
struct P {
    u8 p0[264];
    u32 f264;
    u32 f268;
    u8 p110[1344 - 272];
    V pos;
    u8 p550[2800 - 1360];
    u8 st[8];
    Prm* prm;
    Ref* r2812;
    Ref* r2816;
    u8 pb04[2844 - 2820];
    u8 b2844;
    u8 pb1d[3];
    f32 time;
    f32 spd;
    u8 pb28[8];
    V dir;
    V start;
    f32 t1;
    f32 f2900;
    u8 pb58[8];
    V v2912;
    f32 f2928;
    u8 b2932;
    u8 pb75[11];
    V v2944;
    V v2960;
    V v2976;
    u8 pbb0[3056 - 2992];
    f32 f3056;
    f32 f3060;
};
extern void* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
void func_002d00d8(P*) asm("_Z13func_002d00d8Pv");
s32 lflag_check(u8*, u32) asm("_ZN2Ti5LFlag5checkEj");
void lflag_zero(u8*) asm("_ZN2Ti5LFlag4zeroEv");
void lflag_set(u8*, s32, s32) asm("_Z16wtarget_002cf280jjjj");
void change_action(P*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
f32 cosf(f32) asm("cosf");
f32 sinf(f32) asm("sinf");
Cfg* config(void*) asm("_ZN2Ti6MGJump6configEv");
void func_0016a9a0(P*) asm("func_0016a9a0");
void func_0016ac38(P*, s32, s32, s32, s32) asm("func_0016ac38");
f32 func_002de968(f32) asm("func_002de968");
void btlobj_pre_exec(P*) asm("_ZN2YS6BTLOBJ13_OVR_pre_execEv");

void func_002ddbf0(P* o) asm("func_002ddbf0");
void func_002ddbf0(P* o)
{
    u8* st;
    void* g;
    f32 a, c, sn;
    s32 s1, s2;
    func_002d00d8(o);
    st = o->st;
    if (lflag_check(st, 4)) {
        o->f268 |= 0x80;
        o->f264 |= 0x400;
        return;
    }
    lflag_zero(st);
    lflag_set(st, 1, 0);
    lflag_set(st, 0x1000, 0);
    change_action(o, 3);
    o->f264 |= 1;
    g = D_00361f60;
    if (g == 0) return;
    o->f3056 = 0.0f;
    if (o->prm == 0) return;
    if (o->prm->ang == 0x7fff) {
        a = o->r2812->ang;
    } else {
        a = (f32)o->prm->ang * 3.1415927f / 16.0f;
    }
    c = cosf(a);
    sn = sinf(a);
    V d0(c, -sn, 0.0f, 0.0f);
    o->b2844 = 0;
    if ((u16)(o->prm->kind - 1) < 3) {
        o->start = o->pos;
        V p(o->r2816->x, o->r2816->y, o->r2816->z, 0.0f);
        if (o->r2812) {
            V df = o->pos - V(o->r2812->x, o->r2812->y, o->r2812->z, 0.0f); p += df;
        }
        o->b2844 = 1;
        switch (o->prm->kind) {
        case 1: o->spd = config(g)->spd[0]; break;
        case 2: o->spd = config(g)->spd[1]; break;
        case 3: o->spd = config(g)->spd[2]; break;
        case 4: o->spd = config(g)->spd[3]; break;
        }
        o->time = (f32)o->prm->time;
        o->dir = p - o->pos;
        o->t1 = o->dir.normalize() / o->time;
        s1 = 0.0f < o->dir.x;
        s2 = 0.0f < d0.x;
        o->f2900 = (f32)o->prm->f20;
        if (s1 != s2) o->f2900 += 0.5f;
        o->v2912 = p;
        o->f2928 = (o->spd / o->time) * 2.0f * o->f2900 * 1.5f;
        o->b2932 = 0.0f < o->dir.x;
        o->v2944 = d0;
    } else {
        o->v2976 = d0;
        o->v2976.w = (f32)o->prm->time;
    }
    o->v2960 = o->pos;
}

}  // namespace n002ddbf0
