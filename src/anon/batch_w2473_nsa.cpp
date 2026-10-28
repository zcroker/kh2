#include "../common/types.h"
extern "C" {
struct V2d2b50 {
    f32 x, y, z, w;
    V2d2b50() {}
    void Set3(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0.0f; }
    V2d2b50(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d2b50(const V2d2b50& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2d2b50& operator=(const V2d2b50& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2d2b50 operator-(const V2d2b50& b) const
    {
        V2d2b50 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Rec2d2b50 { u8 pad[6]; s16 angle; s16 height; s16 mode; u8 pad2[2]; u16 turn; u8 pad3[10]; s16 h26; s16 h28; };
struct Pt2d2b50 { u8 pad[4]; f32 x, y, z; u8 pad2[20]; f32 angle; };
struct It2d2b50 { u8 pad[16]; f32 a, b, c; };
struct Cfg2d2b50 {
    u8 pad[92]; f32 f92, f96; u8 pad1[100 - 100]; u8 tab100[12]; u8 tab112[12]; u8 tab124[20];
    f32 f144, f148, f152; u8 pad2[180 - 156]; f32 f180[2]; f32 f188, f192, f196, f200; u8 pad3[240 - 204]; f32 f240, f244, f248;
};
struct O2d2b50;
struct O2d2b50Vt { void* f[20]; void (*msg)(O2d2b50*, s32, s32, O2d2b50*, s32); };
struct O2d2b50 {
    O2d2b50Vt* vt;
    u8 pad0[4];
    s32* kind;
    u8 pad1[944 - 12];
    s32 f944;
    u8 pad2[1344 - 948];
    V2d2b50 pos;
    u8 pad3[2076 - 1360];
    It2d2b50* item;
    u8 pad4[2800 - 2080];
    u8 lflag[4];
    s32 f2804;
    Rec2d2b50* rec;
    Pt2d2b50* pt;
    u8 pad5[2828 - 2816];
    s32 f2828;
    u8 pad6[4];
    f32 f2836, f2840, f2844, f2848, f2852;
    u8 pad7[2864 - 2856];
    V2d2b50 dir;
    V2d2b50 to;
    f32 f2896, f2900, f2904, f2908, f2912, f2916, f2920;
    s32 f2924, f2928;
    u8* f2932;
    f32 f2936, f2940;
    u8 f2944;
    u8 pad8[3];
    f32 f2948[64];
};
extern void* D_00361f60;
void o2d2b50_init(O2d2b50*) asm("_ZN2Ti5MGObj15_OVR_initializeEv");
void o2d2b50_change_action(O2d2b50*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
s32 func_0016ac38(O2d2b50*, s32, s32, s32, s32);
void o2d2b50_0016b070(O2d2b50*, V2d2b50*) asm("_Z16wtarget_0016b070jjjj");
void o2d2b50_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
Cfg2d2b50* o2d2b50_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
f32 func_002f87c0(f32);
f32 func_002f8960(f32);
f32 o2d2b50_atan2f(f32, f32) asm("f_atan2f");
// Ti::MGOarashi object init: action, dir/to vectors, turn/side/kind setup
void func_002d2b50(O2d2b50* o)
{
    o2d2b50_init(o);
    o2d2b50_change_action(o, 3);
    void* g = D_00361f60;
    if (!o->rec) return;
    f32 ang;
    if (o->rec->angle == 0x7fff) ang = o->pt->angle;
    else ang = o->rec->angle * 3.1415927f * 0.0625f;
    f32 c = func_002f87c0(ang);
    o->dir = V2d2b50(c, -func_002f8960(ang), 0.0f, o->rec->height);
    V2d2b50 p(o->pt->x, o->pt->y, o->pt->z, 0.0f);
    o->to = o->pos - p;
    V2d2b50 n(o->to);
    n.z = 0.0f;
    f32 len = n.normalize();
    o->f2900 = len;
    if (len < 0.01f) o->f2896 = 0.0f;
    else o->f2896 = o2d2b50_atan2f(n.y, n.x);
    switch (o->rec->turn) {
    default:
        o->f2904 = 0.0f;
        break;
    case 1: o->f2904 = o2d2b50_config(g)->f240 * 0.017453292f; break;
    case 2: o->f2904 = -(o2d2b50_config(g)->f240 * 0.017453292f); break;
    case 3: o->f2904 = o2d2b50_config(g)->f244 * 0.017453292f; break;
    case 4: o->f2904 = -(o2d2b50_config(g)->f244 * 0.017453292f); break;
    case 5: o->f2904 = o2d2b50_config(g)->f248 * 0.017453292f; break;
    case 6: o->f2904 = -(o2d2b50_config(g)->f248 * 0.017453292f); break;
    }
    if (o->rec->mode) {
        switch (o->rec->mode) {
        case 1: o->f2804 = 0; break;
        case 2: o->f2804 = 1; break;
        case 3: o->f2804 = 2; break;
        case 0:
            if (1.0f < o->pos.z) o->f2804 = 1;
            else if (o->pos.z < -1.0f) o->f2804 = 2;
            else o->f2804 = 0;
            break;
        }
        o->f2852 = 0.0f;
        switch (o->f2804) {
        case 0: o->f2852 = 0.0f; break;
        case 1: if (g) o->f2852 = o2d2b50_config(g)->f96; break;
        case 2: if (g) o->f2852 = o2d2b50_config(g)->f92; break;
        }
    }
    o->f2936 = 0.0f;
    if (*o->kind == 2031) {
        o->f2924 = 0;
        o->f944 = 1;
        o->f2828 = func_0016ac38(o, 0, 1, 0, 0);
        o2d2b50_set(o->lflag, 128, 0);
        o2d2b50_set(o->lflag, 1024, 0);
        o2d2b50_set(o->lflag, 2048, 0);
    } else if (*o->kind == 2032) {
        o->f944 = 1;
        o->f2924 = 1;
        o->f2828 = func_0016ac38(o, 0, 1, 0, 0);
        o2d2b50_set(o->lflag, 128, 0);
        o2d2b50_set(o->lflag, 1024, 0);
        o2d2b50_set(o->lflag, 2048, 0);
    } else {
        o->f2828 = 0;
        o->f944 = 2;
        o->f2924 = -1;
        switch ((u32)*o->kind) {
        case 1627:
            o->f2932 = o2d2b50_config(g)->tab112;
            o->f2936 = o2d2b50_config(g)->f148;
            break;
        case 1629:
            o->f2932 = o2d2b50_config(g)->tab124;
            o->f2936 = o2d2b50_config(g)->f152;
            break;
        case 1626:
        default:
            o->f2932 = o2d2b50_config(g)->tab100;
            o->f2936 = o2d2b50_config(g)->f144;
            break;
        }
    }
    if (o->f2924 < 0) {
        o->f944 = 0;
        o->vt->msg(o, 1236, 0, o, 0);
        o->f944 = 2;
    }
    if (o->rec->height == 0 && o->f2924 >= 0) o->f2940 = o2d2b50_config(g)->f180[o->f2924];
    else o->f2940 = -1.0f;
    o->f2928 = 0;
    o->f2836 = o2d2b50_config(g)->f192;
    o->f2840 = o2d2b50_config(g)->f188;
    o->f2844 = o2d2b50_config(g)->f196;
    o->f2848 = o2d2b50_config(g)->f200;
    if (o->item) {
        n.Set3(o->item->a, -o->item->b, -o->item->c);
        o2d2b50_0016b070(o, &n);
    }
    o->f2912 = o->rec->h26;
    o->f2908 = o->rec->h28;
    o->f2916 = 0.0f;
    o->f2944 = 0;
    o->f2920 = 0.0f;
    for (s32 i = 0; i < 64; i++) o->f2948[i] = -1.0f;
}


struct V11cdf0 {
    f32 x, y, z, w;
    V11cdf0() {}
    V11cdf0(const V11cdf0& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V11cdf0& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M11cdf0 {
    V11cdf0 r[4];
    M11cdf0() {}
    M11cdf0(const M11cdf0& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    M11cdf0& operator=(const M11cdf0& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    static void mul(M11cdf0* o, const M11cdf0* a, const M11cdf0* b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
    }
    M11cdf0 operator*(const M11cdf0& b) const {
        M11cdf0 o;
        mul(&o, this, &b);
        return o;
    }
} __attribute__((aligned(16)));
extern u8 D_0033cc50[];
struct XfB11cdf0 {
    u32 vt;
    M11cdf0 m;
    XfB11cdf0(const XfB11cdf0& o) : m(o.m) { vt = (u32)D_0033cc50; }
};
struct Xf11cdf0 : XfB11cdf0 {
    V11cdf0 a, b, c;
    f32 s;
};
struct Hdr11cdf0 { s16 kind; u8 pad[2]; u32 count; s32 off[1]; };
struct Desc11cdf0 {
    u32 flags;
    u8 b4, b5, b6, b7;
    u8 r, g, b, pad11;
    u8 pad12[4];
    u64 a16;
    u64 a24;
    u32 p32;
    Hdr11cdf0* hdr;
    u8 pad40[12];
    M11cdf0* xf;
} __attribute__((aligned(8)));
struct Seq11cdf0 { s32 id; s32 p4; };
struct Mdl11cdf0 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18();
    virtual s32 draw(M11cdf0*, s32*, Desc11cdf0*, s32, s32, s32, M11cdf0*);
    Seq11cdf0* seq;
    u8 pad[4];
    u32 flags;
};
struct Self11cdf0 {
    u8 pad0[20];
    Mdl11cdf0* mdl;
    u8 pad1[56 - 24];
    s32 p56;
    u8 pad2[64 - 60];
    M11cdf0 world;
    M11cdf0 local;
    M11cdf0 xf;
    u8 pad3[260 - 256];
    s32 base;
    s32* tbl;
};
Mdl11cdf0* func_00124748(Mdl11cdf0*, u32);
s32 func_00124788(Mdl11cdf0*, u32);
Xf11cdf0* func_00106a60(s32);
void func_001070e8(Xf11cdf0*);
void func_002f25a0(s32, s32);
s32 func_00134278();
void func_00109330();
void func_00109340();
void* func_0010ae90();
void func_001344b8(s32);
void func_0010a800(u8*, u8*, u8*);
void func_00108998(void*);
s32 func_0010abb8(s32);
s32 func_00109f58(s32, s32, u8);
s32 func_00109ea8(s32, s32, u8);
void func_00108c00(void*, s32, u64, u64, s32, s32, u64, u64);
void func_00108a10(void*);
void func_001342a8();
s32 func_00133d38();
void func_002f3918(s32, s32);
// two-pass model draw (sibling of 0011ca20)
void func_0011cdf0(Self11cdf0* s, const M11cdf0* w, const M11cdf0* l, Desc11cdf0* desc, u32 idx)
{
    s->local = *l;
    s->local.r[1] *= -1.0f;
    s->local.r[2] *= -1.0f;
    s->world = *w * s->local;
    Mdl11cdf0* m = s->mdl;
    Mdl11cdf0* o = m;
    s32* tbl = s->tbl;
    if (m->seq->id == -1) {
        m = func_00124748(m, idx);
        tbl = s->tbl + func_00124788(o, idx);
    }
    Desc11cdf0 d = *desc;
    Hdr11cdf0* h = d.hdr;
    if (h && h->kind == -1) {
        if (idx >= h->count) idx = h->count - 1;
        d.hdr = (Hdr11cdf0*)((u8*)h + h->off[idx]);
    }
    func_002f25a0(0, 0);
    s32 saved = func_00134278();
    func_00109330();
    func_00109340();
    void* pk = func_0010ae90();
    func_001344b8(64);
    u8 rgb[3];
    if (!(desc->flags & 2)) {
        func_0010a800(&rgb[0], &rgb[1], &rgb[2]);
    } else {
        rgb[0] = desc->r;
        rgb[1] = desc->g;
        rgb[2] = desc->b;
    }
    func_00108998(pk);
    s32 mode = 5;
    if (m->seq->id != 2) mode = 7;
    s32 old = func_0010abb8(mode);
    {
    s32 a = func_00109f58(mode, m->seq->p4, desc->b7);
    s32 b = func_00109ea8(mode, m->seq->p4, desc->b7);
    func_00108c00(pk, 63, desc->a16, desc->a24 & ~((u64)1 << 32), b, a,
                  (u64)rgb[0] | ((u64)rgb[1] << 8) | ((u64)rgb[2] << 16),
                  (u64)desc->b4 | ((u64)desc->b5 << 8) | ((u64)desc->b6 << 16) | ((u64)desc->b7 << 24) | ((u64)127 << 55));
    }
    M11cdf0* xf = desc->xf;
    if (!xf && (m->flags & 2)) {
        Xf11cdf0 x(*func_00106a60(1));
        M11cdf0::mul(&s->xf, &x.m, &s->local);
        xf = &s->xf;
        func_001070e8(&x);
    }
    if (!m->draw(&s->world, tbl, &d, s->base, s->p56, 0, xf)) {
        mode = 8;
        if (m->seq->id != 2) mode = 11;
        func_0010abb8(mode);
        s32 a2 = func_00109f58(mode, m->seq->p4, desc->b7);
        s32 b2 = func_00109ea8(mode, m->seq->p4, desc->b7);
        func_00108c00(pk, 63, desc->a16 | ((u64)-1 << 56), desc->a24 | ((u64)1 << 32), b2, a2,
                      (u64)rgb[0] | ((u64)rgb[1] << 8) | ((u64)rgb[2] << 16),
                      (u64)desc->b4 | ((u64)desc->b5 << 8) | ((u64)desc->b6 << 16) | ((u64)desc->b7 << 24) | ((u64)127 << 55));
        m->draw(&s->world, tbl, &d, s->base, s->p56, 1, xf);
    }
    func_00108a10(pk);
    func_001342a8();
    func_0010abb8(old);
    func_002f3918(func_00133d38(), saved);
    func_002f25a0(0, 0);
}
}
