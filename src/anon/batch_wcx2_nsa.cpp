#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }
// Functions that only match with -fno-strict-aliasing (gcc 3.2 combines freed
// stack temporaries only without strict aliasing).

// --------------------
// 001b1100: is the target point inside the facing cone? (flattened direction vs dir,
// cone 15 degrees, or the lock-on target's own range in degrees)
struct V1b1100 {
    f32 x, y, z, w;
    V1b1100() {}
    V1b1100(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V1b1100(const V1b1100& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V1b1100& operator=(const V1b1100& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1b1100 operator-(const V1b1100& b) const
    {
        V1b1100 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1b1100& normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Pair1b1100 { V1b1100 a, b; };
struct Obj1b1100 { u8 pad[1344]; V1b1100 pos; V1b1100 dir; };
struct Tgt1b1100 { u8 pad[16]; s16 range; };
extern "C" {
Tgt1b1100* func_0016bc20(Obj1b1100*, s32, s32);
f32 func_0017d160(V1b1100, V1b1100);
Pair1b1100 func_0018a818(Obj1b1100*, Tgt1b1100*);
f32 func_002f8870(f32);
bool t1b1100(Obj1b1100*, V1b1100*) asm("_Z16ctarget_001b1100jjjj");
bool t1b1100(Obj1b1100* o, V1b1100* target)
{
    V1b1100 d;
    Tgt1b1100* t = func_0016bc20(o, 20, -1);
    if (!t) {
        d = *target - o->pos;
        V1b1100 v;
        v.x = d.x; v.z = d.z; v.w = v.y = 0.0f;
        v.normalize();
        return func_002f8870(func_0017d160(v, o->dir)) < 0.26179937f;
    } else {
        Pair1b1100 p = func_0018a818(o, t);
        d = *target - p.b;
        d.normalize();
        V1b1100 v;
        v.x = d.x; v.z = d.z; v.w = v.y = 0.0f;
        v.normalize();
        return func_002f8870(func_0017d160(v, o->dir)) <= t->range * 0.017453292f;
    }
}

// --------------------
// 002d1550: Ti::MGOarashi set-up (base init, "po_06" data, Afp resources, start pose)
// Member addresses are taken up front like the member constructors of the original ctor.
struct V2d1550 {
    f32 x, y, z, w;
    V2d1550() {}
    V2d1550(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void Init(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d1550 operator-(const V2d1550& b) const
    {
        V2d1550 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2d1550& operator+=(const V2d1550& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V2d1550& operator=(const V2d1550& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M2d1550 {
    V2d1550 r[4];
    M2d1550() {}
    M2d1550& operator=(const M2d1550& o)
    {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Ent2d1550 { u8 pad[8]; s32 data; };
struct Cfg2d1550 { u8 pad[36]; f32 f36; };
struct G2d1550 {
    u32 vt;
    u8 pad0[88];
    s32 f92;
    s32 bar;
    s32 f100;
    s32 id;
    s32 afp;
    f32 dist;
    u8 pad1[12];
    V2d1550 pos;
    f32 f144;
    u8 pad2[4];
    f32 f152;
    u8 pad3[4];
    M2d1550 m0;
    M2d1550 m1;
    V2d1550 v288;
    V2d1550 v304;
    u8 f320;
    u8 pad4[3];
    s32 f324;
    s32 f328;
};
extern u8 D_00362158[];
extern u8 D_00362110[];
void func_002ce958(G2d1550*, s32, s32, s32);
void g2d1550_make_data_path(G2d1550*, char*, const char*) asm("_ZN2Ti8MiniGame14make_data_pathEPcS1_");
s32 g2d1550_Alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
Ent2d1550* func_00168b38(s32, s32, s32);
Cfg2d1550* g2d1550_config(G2d1550*) asm("_ZN2Ti9MGOarashi6configEv");
void func_001ca8f8(f32, f32);
void g2d1550_getCount(s32) asm("_ZN2Ti3Afp8getCountEPv");
s32 func_002e64b8(s32, s32);
s32 g2d1550_getFieldMode(void) asm("_Z12getFieldModev");
void func_002e6ab0(f32, s32, M2d1550*);
void func_001069b8(s32);
void func_002cedd0(s32, u8*);
void func_002cf938(s32);
void func_002d1550(G2d1550* g, s32 id, s32 arg)
{
    func_002ce958(g, 0, arg, 0x800);
    M2d1550* m0 = &g->m0;
    M2d1550* m1 = &g->m1;
    V2d1550* v288 = &g->v288;
    V2d1550* v304 = &g->v304;
    g->id = id;
    g->f100 = 0;
    g->afp = 0;
    g->vt = (u32)D_00362158;
    g->dist = 40.0f;
    g->pos.Init(0.0f, 0.0f, 0.0f, 0.0f);
    g->f144 = 0.0f;
    g->f152 = 0.0f;
    g->f320 = 0;
    s32 bar;
    {
        char path[64];
        g2d1550_make_data_path(g, path, "po_06");
        bar = g2d1550_Alloc(path, -1);
    }
    g->bar = bar;
    func_00168b38(bar, 42, 0);
    g->f100 = func_00168b38(bar, 42, 0)->data + 16;
    func_00168b38(bar, 42, 1);
    s32 afp = func_00168b38(bar, 42, 1)->data;
    func_00168b38(bar, 42, g->id + 2);
    g->f92 = func_00168b38(bar, 42, g->id + 2)->data;
    func_001ca8f8(g2d1550_config(g)->f36, 0.0f);
    g2d1550_getCount(afp);
    g->afp = func_002e64b8(0, afp);
    g2d1550_getFieldMode();
    g->dist = 40.0f;
    g->pos = V2d1550(0.0f, 0.0f, 150.0f, 0.0f);
    g->f144 = 0.0f;
    M2d1550 m;
    func_002e6ab0(0.0f, g->afp, &m);
    *m0 = m;
    *m1 = m;
    *v288 = V2d1550(0.0f, 0.0f, 0.0f, 0.0f);
    *v304 = V2d1550(0.0f, 0.0f, 0.0f, 0.0f);
    g->f324 = 0;
    g->f328 = 0;
    func_001069b8(2);
    func_002cedd0(4, D_00362110);
    func_002cf938(1);
}

// --------------------
// 002d1908: Ti::MGOarashi per-frame update (camera, ride along the Afp path, speed from slope)
struct Afp2d1908 { u8 pad[4]; s32 frames; };
extern f32 D_00349e10;
void g2d1908_exec(void) asm("_ZN2Ti8MiniGame4execEv");
void func_002cf998(void);
void g2d1908_002cfb30(void) asm("func_002cfb30");
void* g2d1908_00106a18(s32) asm("func_00106a18");
void g2d1908_00106de8(void*, s32, f32) asm("func_00106de8");
void g2d1908_00106c08(void*) asm("func_00106c08");
void g2d1908_002e6ab0(s32, f32, M2d1550*) asm("func_002e6ab0");
void func_002e6930(f32, s32, V2d1550*);
f32* g2d1908_config(G2d1550*) asm("_ZN2Ti9MGOarashi6configEv");
f32 g2d1908_fabsf(f32) asm("func_002f8870");
void g2d1908(G2d1550*) asm("_Z16wtarget_002d1908jjjj");
void g2d1908(G2d1550* g)
{
    g2d1908_exec();
    func_002cf998();
    g2d1908_002cfb30();
    void* cam = g2d1908_00106a18(1);
    g2d1908_00106de8(cam, 1, g->dist * 0.017453292f);
    g2d1908_00106c08(cam);
    g->m1 = g->m0;
    g2d1908_002e6ab0(g->afp, g->f144, &g->m0);
    g->m0.r[3] += g->pos;
    if (!g->f320) {
        f32 thr = 0.5f;
        V2d1550 a, b;
        func_002e6930(g->f144, g->afp, &a);
        f32 k = *g2d1908_config(g);
        func_002e6930(g->f144 + k * 15.0f * 11.0f, g->afp, &b);
        if (g2d1908_fabsf(b.y) < thr) {
            if (g->f152 > 0.0f) g->f152 -= 1.3333333f;
        } else if (thr < g2d1908_fabsf(a.y)) {
            if (g->f152 < 20.0f) g->f152 += 1.3333333f;
        }
        if (g->f152 < 0.0f) g->f152 = 0.0f;
        if (20.0f < g->f152) g->f152 = 20.0f;
        g->f144 += k * (g->f152 + 1.0f) * D_00349e10 * 0.5f;
        s32 n = ((Afp2d1908*)g->afp)->frames;
        if (!((s32)g->f144 < n - 1)) g->f144 = n;
    }
    g->v304 = g->v288;
    g->v288 = g->m0.r[3] - g->m1.r[3];
}
}

// --------------------
// 00103ca0: field mode step: per-mode handling, then warp to the pending location (10-byte location record)
struct Ids103ca0 { u16 x, y, z; };
struct Loc103ca0 {
    u8 a, b, c, pad;
    Ids103ca0 ids;
    Loc103ca0() { Fill(0xffff); }
    void Fill(s32 v) { a = v; b = v; c = v; ids.x = v; ids.y = v; ids.z = v; }
};
struct Cur103ca0 { u8 type; u8 a, b, c; Ids103ca0 ids; u8 f10; };
extern "C" {
extern s32 D_0032ba2c;
extern s32 D_0032ba24;
extern Cur103ca0 D_0032ba38;
void func_00103c70(void);
void func_00103e78(void);
void func_00149fe0(s32, u32);
s32 func_0014aba8(void);
void func_0014aa58(s32, s32, s32);
void func_0014a138(s32);
Loc103ca0 func_001cd520(void);
Loc103ca0 func_00199718(u8, s32);
void func_00104f58(Loc103ca0*, s32, s32, s32, s32);
void func_00103ca0(void)
{
    s32 mode = D_0032ba2c;
    Loc103ca0 l;
    func_00103c70();
    switch (mode) {
    case 1:
        func_00149fe0(-1, 0x80000000);
        break;
    case 3:
        func_0014aa58(func_0014aba8(), 1, 0);
        func_0014a138(0);
        break;
    case 2:
        if (D_0032ba24 == 1) {
            if (D_0032ba38.type == 0) {
                l = func_001cd520();
                func_00104f58(&l, 1, 0, 1, 0);
            } else {
                if (D_0032ba38.type == D_0032ba24) {
                    l.a = D_0032ba38.a;
                    l.b = D_0032ba38.b;
                    l.c = D_0032ba38.c;
                    l.ids = D_0032ba38.ids;
                } else {
                    l = func_00199718(D_0032ba38.f10, -1);
                    l.c = D_0032ba38.c;
                }
                func_00104f58(&l, 1, 0, 0, 0);
            }
        }
        break;
    }
    func_00103e78();
}
}

extern "C" {
// --------------------
// 002d3b78: Ti::MGOarashi object hit by the player (count hits, prize, knock-back)
struct V2d3b78 {
    f32 x, y, z, w;
    V2d3b78() {}
    void Set(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void Zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void Set3(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0.0f; }
    V2d3b78(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d3b78(const V2d3b78& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2d3b78 operator+(const V2d3b78& b) const
    {
        V2d3b78 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2d3b78& operator+=(const V2d3b78& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V2d3b78& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V2d3b78& operator=(const V2d3b78& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2d3b78 operator-(const V2d3b78& b) const
    {
        V2d3b78 r;
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
struct Cfg2d3b78 { u8 pad[40]; u8 tab40[24]; s32 f64; u8 pad2[216 - 68]; u8 tab216[4]; };
struct O2d3b78 {
    u8 pad0[8];
    s32* kind;
    u8 pad1[320 - 12];
    u8 motion[1416 - 320];
    u32 flags;
    u8 pad2[2040 - 1420];
    u32 f2040;
    u8 pad3[2092 - 2044];
    u8 f2092[2924 - 2092];
    s32 f2924;
    s32 hits;
    s32* tbl;
    f32 f2936;
    u8 pad4[4];
    u8 f2944;
};
struct Hit2d3b78 { u8 pad[16]; O2d3b78* other; u8 pad2[8]; s32 f28; };
extern void* D_00361f60;
extern V2d3b78 D_0034eef0;
void func_002d39c8(O2d3b78*, Hit2d3b78*);
void* o2d3b78_current(void) asm("_ZN2Ti8MGPlayer7currentEv");
s32 func_002d5c40(void*);
void func_001b3e88(O2d3b78*, Hit2d3b78*);
void* o2d3b78_start_effect(O2d3b78*, s32, s32, s32) asm("_ZN2YS3OBJ12start_effectEiii");
V2d3b78* o2d3b78_effect_pos(void*) asm("_ZN3ryj6EFFECT3posEv");
s32 o2d3b78_appear_prize_ok(void*) asm("_ZN2Ti15MGOarashiPlayer15appear_prize_okEv");
Cfg2d3b78* o2d3b78_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
void func_002d3128(O2d3b78*, s32);
void func_002d3568(O2d3b78*, void*, s32);
void func_001ad990(void*, f32, f32, f32);
s32 func_0016ac38(O2d3b78*, s32, s32, s32, s32);
void o2d3b78_00186a90(O2d3b78*, V2d3b78*, f32) asm("_Z16ctarget_00186a90jjjj");
V2d3b78 o2d3b78_0016bda8(O2d3b78*) asm("_Z16ctarget_0016bda8jjjj");
void func_0017f488(void*, s32, f32, f32);
void o2d3b78_push(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
f32 func_002f8870(f32);
void func_002d3b78(O2d3b78* o, Hit2d3b78* h)
{
    void* g = D_00361f60;
    if (o->f2924 >= 0) return;
    if (o->f2944) return;
    O2d3b78* t = h->other;
    if (t && !(t->flags & 0x80)) {
        if ((t->flags & 0x08000000) && t->f2924 < 0) {
            func_002d39c8(o, h);
            return;
        }
    }
    s32 done = 0;
    s32 kind = func_002d5c40(o2d3b78_current());
    func_001b3e88(o, h);
    o->hits++;
    s32 eff = -1;
    s32 need;
    if (kind == 2) {
        eff = 1;
        need = o->tbl[1];
    } else if (kind == 3) {
        eff = 2;
        need = o->tbl[2];
    } else {
        need = o->tbl[0];
    }
    if (eff >= 0 && h->f28) {
        void* e = o2d3b78_start_effect(h->other, eff, 1, 0);
        if (e) *o2d3b78_effect_pos(e) = D_0034eef0;
    }
    if (o2d3b78_appear_prize_ok(o2d3b78_current())) {
        if (*o->kind == 1629 || (need > 0 && !(o->hits < need))) done = 1;
    }
    if (done) {
        if (*o->kind == 1629) func_002d3128(o, o2d3b78_config(g)->f64);
        else if (*o->kind == 1627) func_002d3568(o, o2d3b78_config(g)->tab216, 0);
        else func_002d3568(o, o2d3b78_config(g)->tab40, 2);
    }
    if (need > 0 && !(o->hits < need)) {
        if (!(o->f2040 & 0x10)) func_001ad990(o->f2092, 1.0f, 0.0f, 0.0f);
        func_0016ac38(o, 0, 1, 0, 0);
        o->f2944 = 1;
    } else if (*o->kind != 1626) {
        func_0017f488(o->motion, 14, 0.0f, 0.0f);
        o2d3b78_push(o->motion, 0, 0.0f, 0.0f, 0);
    }
    if (!h->other) return;
    if (*o->kind == 1627 || *o->kind == 1629) {
        V2d3b78 v;
        v.Set(1.0f, 0.0f, 0.0f, 0.0f);
        o2d3b78_00186a90(o, &v, func_002f8870(o->f2936));
    } else {
        V2d3b78 v = o2d3b78_0016bda8(o) - o2d3b78_0016bda8(h->other);
        v.z = 0.0f;
        v.normalize();
        if (o->f2936 < 0.0f) v.Zero();
        o2d3b78_00186a90(o, &v, func_002f8870(o->f2936));
    }
}
}

// --------------------
// 002d4b40: Ti::MGOarashi player-side update: project the player into the minigame plane, then pick the lock-on target
#define W2d4b40_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W2d4b40Vec {
    f32 x, y, z, w;
    W2d4b40Vec() {}
    W2d4b40Vec(const W2d4b40Vec& o) { W2d4b40_QCOPY(this, &o); }
    W2d4b40Vec& operator=(const W2d4b40Vec& o) { if (this != &o) W2d4b40_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2d4b40Mtx {
    W2d4b40Vec r0, r1, r2, r3;
    W2d4b40Mtx() {}
    W2d4b40Mtx(const W2d4b40Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W2d4b40Mtx& operator=(const W2d4b40Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W2d4b40Vec operator*(const W2d4b40Vec& v) const {
        W2d4b40Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
struct O2d4b40 { u8 pad0[2884]; s32 f2884; u8 pad1[3092 - 2888]; void* h3092; void* h3096; void* f3100; u8 pad2[3128 - 3104]; void* f3128; s32 f3132; };
extern void* D_00361f60;
void func_002d10a0(O2d4b40*);
W2d4b40Vec* func_0016c028(O2d4b40*);
W2d4b40Mtx* func_002d1f10(void*);
W2d4b40Mtx* func_002d1f00(void*);
void o2d4b40_set_pos(O2d4b40*, W2d4b40Vec*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void* func_0016b740(s32);
s32 func_002d5588(O2d4b40*);
s32 func_002d56a0(O2d4b40*);
s32 o2d4b40_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
struct Tgt2d4b40;
void func_00190128(Tgt2d4b40*);
void o2d4b40_set_obj(Tgt2d4b40*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
struct Tgt2d4b40 {
    u8 pad[64];
    Tgt2d4b40(void* obj) { func_00190128(this); o2d4b40_set_obj(this, obj, 0); }
};
void func_001bd3e0(s32, s32, s32, Tgt2d4b40*, s32, s32);
s32 func_002d55b8(O2d4b40*);
void* func_002d2660(void*, s32);
void func_002d4b40(O2d4b40* o)
{
    func_002d10a0(o);
    void* g = D_00361f60;
    if (!g) return;
    {
    W2d4b40Vec p(*func_0016c028(o));
    W2d4b40Mtx m(*func_002d1f10(g));
    m.invOrtho();
    p.w = 1.0f;
    W2d4b40Vec a = m * p;
    a.z = 0.0f;
    W2d4b40Vec b = *func_002d1f00(g) * a;
    b.z = 0.0f;
    o2d4b40_set_pos(o, &b);
    }
    if (!o->h3092) o->h3092 = func_0016b740(1565);
    if (!o->h3096) o->h3096 = func_0016b740(1628);
    if (func_002d5588(o)) return;
    if (func_002d56a0(o) && o->h3092 && o2d4b40_is_attach(o->h3092)) {
        Tgt2d4b40 t(o->f3100);
        func_001bd3e0(o->f2884, 1, 497, &t, 1, 100);
        return;
    }
    if (func_002d55b8(o)) {
        Tgt2d4b40 t(o->h3092);
        func_001bd3e0(o->f2884, 1, 496, &t, 1, 100);
        return;
    }
    void* r = func_002d2660(g, 0);
    if (r) {
        Tgt2d4b40 t(r);
        func_001bd3e0(o->f2884, 1, 578, &t, 1, 100);
        o->f3128 = r;
        o->f3132 = 0;
        return;
    }
    r = func_002d2660(g, 1);
    if (r) {
        Tgt2d4b40 t(r);
        func_001bd3e0(o->f2884, 1, 579, &t, 1, 100);
        o->f3128 = r;
        o->f3132 = 1;
    }
}
}

extern "C" {
// --------------------
// 002d5200: Ti::MGOarashi player bumped into an object (stop motions, prize/effect, knock-back)
struct V2d5200 {
    f32 x, y, z, w;
    V2d5200() {}
    void Set(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void Zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void Set3(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0.0f; }
    V2d5200(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d5200(const V2d5200& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2d5200 operator+(const V2d5200& b) const
    {
        V2d5200 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2d5200& operator+=(const V2d5200& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V2d5200& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V2d5200& operator=(const V2d5200& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2d5200 operator-(const V2d5200& b) const
    {
        V2d5200 r;
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
struct Cfg2d5200 { u8 pad[136]; f32 knock; };
struct O2d5200;
struct O2d5200Vt { void* f[24]; s32 (*busy)(O2d5200*); };
struct O2d5200 {
    O2d5200Vt* vt;
    u8 pad1[316];
    u8 motion[1416 - 320];
    u32 flags;
    u8 pad2[2780 - 1420];
    f32 height;
    u8 pad3[2800 - 2784];
    u8 lflag[3092 - 2800];
    O2d5200* h3092;
    O2d5200* h3096;
    bool InAir() { return 0.0f < height; }
};
struct G2d5200 { u8 pad[320]; u8 f320; };
struct Hit2d5200 { u8 pad[16]; O2d5200* other; u8 pad2[8]; s32 f28; };
extern G2d5200* g2d5200_game asm("D_00361f60");
extern V2d5200 g2d5200_zero asm("D_0034eef0");
V2d5200 o2d5200_0016bda8(O2d5200*) asm("_Z16ctarget_0016bda8jjjj");
s32 func_002d51f0(O2d5200*);
void func_0017f488(void*, s32, f32, f32);
void o2d5200_push(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
s32 o2d5200_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void func_002d6600(O2d5200*, V2d5200*);
void* o2d5200_start_effect(O2d5200*, s32, s32, s32) asm("_ZN2YS3OBJ12start_effectEiii");
V2d5200* o2d5200_effect_pos(void*) asm("_ZN3ryj6EFFECT3posEv");
void o2d5200_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
void func_002d3f18(O2d5200*);
Cfg2d5200* o2d5200_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
void o2d5200_00186a90(O2d5200*, V2d5200*, f32) asm("_Z16ctarget_00186a90jjjj");
f32 func_002f8870(f32);
void func_002d5200(O2d5200* o, Hit2d5200* h)
{
    G2d5200* g = g2d5200_game;
    if (!g) return;
    if (o->vt->busy(o)) return;
    V2d5200 d = o2d5200_0016bda8(o) - o2d5200_0016bda8(h->other);
    d.z = 0.0f;
    if (d.normalize() < 0.01f) {
        f32 zero = 0.0f;
        d.x = 1.0f; d.z = zero; d.y = zero;
    }
    if (!func_002d51f0(o)) {
        O2d5200* t = h->other;
        if (t && (t->flags & 0x08000000) && t->InAir()) return;
        func_0017f488(o->motion, 14, 0.0f, 0.0f);
        o2d5200_push(o->motion, 0, 0.0f, 0.0f, 0);
        if (o->h3096) {
            func_0017f488(o->h3096->motion, 14, 0.0f, 0.0f);
            o2d5200_push(o->h3096->motion, 0, 0.0f, 0.0f, 0);
        }
        if (o->h3092 && o2d5200_is_attach(o->h3092)) {
            g->f320 = 1;
            func_002d6600(o->h3092, &d);
        }
        if (h->f28) {
            void* e = o2d5200_start_effect(h->other, 1, 1, 0);
            if (e) *o2d5200_effect_pos(e) = g2d5200_zero;
        }
        if (h->other && (h->other->flags & 0x08000000)) {
            o2d5200_set(h->other->lflag, 256, 0);
            func_002d3f18(h->other);
        }
    }
    if (o2d5200_config(g)->knock < 0.0f) d.Zero();
    o2d5200_00186a90(o, &d, func_002f8870(o2d5200_config(g)->knock));
}
}

extern "C" {
// --------------------
// 002d9220: Ti::MGHachimitsuPo honey-pot round start (spawn pot, Pooh and the pot object, reset them, start motions)
struct V2d9220 {
    f32 x, y, z, w;
    V2d9220(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));
struct Obj2d9220 { u8 pad[320]; u8 motion[16]; };
struct O2d9220 { u8 pad[172]; s32 f172; u8 pad2[200 - 176]; u8 attached; u8 started; };
extern void* g2d9220_player asm("D_0034e948");
Obj2d9220* o2d9220_0016b740(s32) asm("func_0016b740");
Obj2d9220* func_0016f000(s32, const V2d9220&, f32);
s32 o2d9220_is_attach(Obj2d9220*) asm("_ZN2YS3OBJ9is_attachEv");
void o2d9220_stop_voice(Obj2d9220*) asm("_ZN2Ti14MGHachimitsuPo19stop_interval_voiceEv");
void o2d9220_detach(Obj2d9220*) asm("_ZN2YS3OBJ6detachEv");
void o2d9220_0016b070(Obj2d9220*, const V2d9220&) asm("_Z16wtarget_0016b070jjjj");
void o2d9220_set_pos(Obj2d9220*, const V2d9220&) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void o2d9220_001987a8(Obj2d9220*, const char*, s32) asm("_Z16wtarget_001987a8jjjj");
void func_00180378(void*, void*, s32, f32);
void func_0017f488(void*, s32, f32, f32);
void o2d9220_texanm_stop(Obj2d9220*, s32) asm("_ZN2YS3OBJ11texanm_stopEi");
struct Names2d9220 { const char* n[2]; };
// the {"00", "10"} initialiser table the compiler placed in .rodata
extern const Names2d9220 D_00375cb0;
void func_002d9220(O2d9220* o, s32 mode)
{
    o->f172 = 0;
    o->started = 1;
    void* pl = g2d9220_player;
    Obj2d9220* a = o2d9220_0016b740(1630);
    Obj2d9220* b = o2d9220_0016b740(1633);
    Obj2d9220* c = func_0016f000(mode ? 2035 : 2034, V2d9220(0.0f, 0.0f, 0.0f, 0.0f), 0.0f);
    o->attached = o2d9220_is_attach(a);
    o2d9220_stop_voice(a);
    if (o2d9220_is_attach(a)) o2d9220_detach(a);
    if (o2d9220_is_attach(b)) o2d9220_detach(b);
    o2d9220_0016b070(a, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_set_pos(a, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_0016b070(b, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_set_pos(b, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_0016b070(c, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_set_pos(c, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    Names2d9220 names = D_00375cb0;
    switch (mode) {
    case 0:
        o2d9220_001987a8(a, names.n[0], 0);
        func_00180378(a->motion, pl, 252, 0.0f);
        func_0017f488(a->motion, 171, 0.0f, 0.0f);
        func_0017f488(b->motion, 171, 0.0f, 0.0f);
        func_0017f488(c->motion, 161, 0.0f, 0.0f);
        o2d9220_texanm_stop(a, 12);
        break;
    case 1:
        o2d9220_001987a8(a, names.n[1], 0);
        func_00180378(a->motion, pl, 253, 0.0f);
        func_0017f488(a->motion, 172, 0.0f, 0.0f);
        func_0017f488(b->motion, 172, 0.0f, 0.0f);
        func_0017f488(c->motion, 170, 0.0f, 0.0f);
        o2d9220_texanm_stop(a, 12);
        break;
    }
}
}

// --------------------
// 002d9810: Ti::MGHachimitsu player update (spawn pot/Pooh, lock-on target, project into the play plane, pose matrix)
#define W2d9810_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W2d9810Vec {
    f32 x, y, z, w;
    W2d9810Vec() {}
    W2d9810Vec(const W2d9810Vec& o) { W2d9810_QCOPY(this, &o); }
    W2d9810Vec& operator=(const W2d9810Vec& o) { if (this != &o) W2d9810_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2d9810Mtx {
    W2d9810Vec r0, r1, r2, r3;
    W2d9810Mtx() {}
    W2d9810Mtx(const W2d9810Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W2d9810Mtx& operator=(const W2d9810Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W2d9810Vec operator*(const W2d9810Vec& v) const {
        W2d9810Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
struct Tgt2d9810;
void o2d9810_00190128(Tgt2d9810*) asm("func_00190128");
void o2d9810_set_obj(Tgt2d9810*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
struct Tgt2d9810 {
    s32 f0, f4, f8, f12, f16;
    Tgt2d9810(void* obj) { o2d9810_00190128(this); o2d9810_set_obj(this, obj, 0); }
};
struct G2d9810 { u8 pad[201]; u8 over; u8 pad2[336 - 202]; W2d9810Mtx view; };
struct O2d9810 {
    u8 pad0[2884]; s32 f2884; u8 pad1[3056 - 2888];
    void* pot; void* pooh; f32 f3064; u8 f3068; u8 pad2[3]; f32 f3072; bool f3076; u8 pad3[11];
    W2d9810Mtx m;
};
extern G2d9810* g2d9810_game asm("D_00361f60");
extern f32 D_00349e10;
void o2d9810_002d10a0(O2d9810*) asm("func_002d10a0");
void* o2d9810_0016b740(s32) asm("func_0016b740");
void func_002dbca0(void*, bool);
s32 o2d9810_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void o2d9810_001c0d38(void*, O2d9810*, s32, s32) asm("_Z16u_tail4_001c0d38jjjj");
s32 func_002da308(O2d9810*);
void* o2d9810_get_gopher(G2d9810*) asm("_ZN2Ti12MGHachimitsu10get_gopherEv");
s32 func_002da238(O2d9810*);
s32 func_002d8898(G2d9810*);
s32 o2d9810_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
void o2d9810_001bd3e0(s32, s32, s32, Tgt2d9810*, s32, s32) asm("func_001bd3e0");
W2d9810Vec* o2d9810_0016c028(O2d9810*) asm("func_0016c028");
void o2d9810_0011b6a8(W2d9810Mtx*) asm("func_0011b6a8");
W2d9810Vec* o2d9810_get_xyzrot(O2d9810*) asm("_ZN2YS3OBJ10get_xyzrotEv");
void o2d9810_rotateXYZ(W2d9810Mtx*, W2d9810Vec*) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
void func_002d9810(O2d9810* o)
{
    o2d9810_002d10a0(o);
    G2d9810* g = g2d9810_game;
    if (g->over) return;
    void* pot = o->pot;
    if (pot || (o->pot = pot = o2d9810_0016b740(1630)) != 0) {
        if (o->f3076) {
            func_002dbca0(pot, !o->f3076);
            o->f3076 = 0;
        }
    }
    void* pooh = o->pooh;
    if (pooh || (o->pooh = pooh = o2d9810_0016b740(1633)) != 0) {
        if (!o2d9810_is_attach(pooh)) o2d9810_001c0d38(o->pooh, o, 0x4000, 0);
    }
    if (func_002da308(o)) {
        Tgt2d9810 t(o2d9810_get_gopher(g));
        o2d9810_001bd3e0(o->f2884, 1, 498, &t, 1, 100);
    } else if (func_002da238(o) && func_002d8898(g) && !o2d9810_IsExec()) {
        Tgt2d9810 t(o->pot);
        o2d9810_001bd3e0(o->f2884, 1, 461, &t, 1, 100);
    }
    o->f3064 = 0.0f;
    if (!o->f3068) {
        W2d9810Mtx m(g->view);
        m.invOrtho();
        W2d9810Vec p(*o2d9810_0016c028(o));
        p.w = 1.0f;
        W2d9810Vec q = m * p;
        q.w = 1.0f;
        o->f3064 = q.x;
        q.y = 0.0f;
        q.z = 0.0f;
    }
    o2d9810_0011b6a8(&o->m);
    o2d9810_rotateXYZ(&o->m, o2d9810_get_xyzrot(o));
    o->m.r3 = *o2d9810_0016c028(o);
    o->m.r3.w = 1.0f;
    if (0.0f < o->f3072) o->f3072 -= D_00349e10;
}
}

// --------------------
// 002db210: Ti::MGHachimitsu honey pot thrown (release holder, place the pot, launch velocity from angle/speed)
#define W2db210_QCOPY(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct W2db210Vec {
    f32 x, y, z, w;
    W2db210Vec() {}
    W2db210Vec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    W2db210Vec operator*(f32 k) const
    {
        W2db210Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    void Zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    W2db210Vec(const W2db210Vec& o) { W2db210_QCOPY(this, &o); }
    W2db210Vec& operator=(const W2db210Vec& o) { if (this != &o) W2db210_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2db210Mtx {
    W2db210Vec r0, r1, r2, r3;
    W2db210Mtx() {}
    W2db210Mtx(const W2db210Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W2db210Mtx& operator=(const W2db210Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W2db210Vec operator*(const W2db210Vec& v) const {
        W2db210Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
static inline W2db210Vec operator*(f32 k, const W2db210Vec& v) { return v * k; }
extern "C" {
struct Cfg2db210 { u8 pad[44]; f32 f44; u8 pad2[8]; f32 speed; f32 angle; };
struct H2db210;
struct H2db210Vt { void* f[8]; void (*kill)(H2db210*); };
struct H2db210 { H2db210Vt* vt; };
struct O2db210 {
    u8 pad0[320]; u8 motion[2800 - 320];
    u8 lflag[36]; H2db210* holder; u8 f2840; u8 pad1[3]; s32 thrown;
    W2db210Vec vel; W2db210Vec acc; W2db210Vec pos; W2db210Vec rot;
};
extern void* g2db210_game asm("D_00361f60");
extern void* g2db210_player asm("D_0034e948");
void o2db210_detach(void*) asm("_ZN2YS3OBJ6detachEv");
void o2db210_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
s32 o2db210_alive(H2db210*) asm("_Z16ctarget_0019ba60jjjj");
s32 o2db210_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void o2db210_change(void*, s32, f32, f32) asm("_ZN2YS6MOTION6changeEiff");
W2db210Mtx* o2db210_002d8110(void*) asm("func_002d8110");
W2db210Vec* o2db210_0016c028(O2db210*) asm("func_0016c028");
W2db210Vec* o2db210_get_xyzrot(void*) asm("_ZN2YS3OBJ10get_xyzrotEv");
s32 func_001064a8(s32);
Cfg2db210* o2db210_002d73f0(void*) asm("func_002d73f0");
f32 func_002f87c0(f32);
f32 func_002f8960(f32);
void o2db210_002d9208(void*, s32) asm("_Z13func_002d9208Pvi");
void func_002db210(O2db210* o)
{
    o2db210_detach(o);
    o2db210_set(o->lflag, 1, 0);
    if (o->holder && o2db210_alive(o->holder)) {
        if (o2db210_is_attach(o->holder)) o2db210_detach(o->holder);
        o->holder->vt->kill(o->holder);
    }
    void* g = g2db210_game;
    o2db210_change(o->motion, 151, 0.0f, 0.0f);
    if (!o->thrown) {
        W2db210Mtx m(*o2db210_002d8110(g));
        m.invOrtho();
        o->pos = m * *o2db210_0016c028(o);
    } else {
        o->rot = *o2db210_get_xyzrot(g2db210_player);
        o->pos = *o2db210_0016c028(o);
    }
    f32 ang;
    if (func_001064a8(2)) ang = o2db210_002d73f0(g)->angle;
    else ang = 3.1415927f - o2db210_002d73f0(g)->f44;
    o->vel = o2db210_002d73f0(g)->speed * W2db210Vec(func_002f87c0(ang), func_002f8960(ang), 0.0f, 0.0f);
    o->acc.Zero();
    o->f2840 = 1;
    o2db210_002d9208(g, 0);
}

// --------------------
// 002e0898: jumping object update: sample ground height at three points, wait on the ground, launch, then fall back and land
struct P2e0898;
struct O2e0898 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12();
    virtual void land(P2e0898*);
    virtual void s14();
    virtual void jump(P2e0898*, s32);
    virtual s32 ready(P2e0898*, f32);
    virtual void wait(P2e0898*, f32, f32, f32);
    u8 pad0[8];
    f32 f12;
    u8 pad1[8];
    f32 top;
    f32 base;
    f32 v0;
    f32 y;
    f32 vel;
    f32 time;
    u8 onGround;
    u8 big;
    u8 pad2[38];
    f32 grav;
    f32 f92;
    f32 dur;
};
struct G2e0898 { u8 pad[3072]; f32 speed; };
extern void* g2e0898_game asm("D_00361f60");
extern G2e0898* g2e0898_gs asm("D_0034e948");
extern f32 g2e0898_one asm("D_00349e10");
void* func_002df140(void);
f32 func_002e51b0(void*, f32);
void func_002e5010(void*, f32, f32);
f32 func_002f8870(f32);
f32 func_002dd250(void*, s32);
f32 func_002dd280(void*, s32);
void func_002e0870(O2e0898*, f32*, f32*, f32*);
void func_002e0898(O2e0898* o, P2e0898* p, f32 x)
{
    void* g = g2e0898_game;
    x *= 0.01f;
    void* fld = func_002df140();
    f32 h = func_002e51b0(fld, x);
    f32 h1 = func_002e51b0(fld, x + 0.2f);
    f32 h2 = func_002e51b0(fld, x - 0.2f);
    if (h < h1) h = h1;
    if (h < h2) h = h2;
    f32 bounce = func_002f8870(o->vel * o->f12) * 0.3f;
    if (o->onGround) {
        o->wait(p, o->time, x, bounce);
        if (o->ready(p, o->time)) {
            s32 big = o->big != 0;
            o->base = h;
            o->onGround = 0;
            o->top = func_002dd250(g, big) * 0.01f;
            f32 dist = o->top - o->base;
            o->v0 = func_002dd280(g, big);
            func_002e0870(o, &o->grav, &o->v0, &dist);
            o->vel = 0.0f;
            o->y = o->base;
            o->time = 0.0f;
            o->dur = o->v0 / o->grav;
            o->jump(p, o->big != 0);
        } else {
            o->y = h;
            o->time += g2e0898_one;
        }
        return;
    }
    f32 t = o->time / 60.0f;
    G2e0898* gs = g2e0898_gs;
    f32 rate = 1.0f;
    if (o->dur < t) {
        rate = gs->speed;
        f32 dt = t - o->dur;
        o->vel = -o->f92 * dt;
        o->y = o->top - o->f92 * 0.5f * dt * dt;
    } else {
        gs->speed = rate;
        o->vel = o->v0 - o->grav * t;
        o->y = o->base + (o->v0 * t - o->grav * 0.5f * t * t);
    }
    o->time += g2e0898_one * rate;
    if (o->vel < 0.0f && o->y <= h) {
        o->y = h;
        func_002e5010(fld, x, -bounce);
        o->time = 0.0f;
        o->onGround = 1;
        o->land(p);
        o->big = 0;
    }
}
}

// --------------------
// 001df670: effect object attach step (follow a model node, sync the two end points, or copy a fixed matrix)
#define W1df670_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1df670Vec {
    f32 x, y, z, w;
    W1df670Vec() {}
    W1df670Vec(const W1df670Vec& o) { W1df670_QCOPY(this, &o); }
    W1df670Vec& operator=(const W1df670Vec& o) { if (this != &o) W1df670_QCOPY(this, &o); return *this; }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    W1df670Vec& operator+=(const W1df670Vec& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1df670Mtx {
    W1df670Vec r0, r1, r2, r3;
    W1df670Mtx() {}
    W1df670Mtx(const W1df670Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1df670Mtx& operator=(const W1df670Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    W1df670Mtx operator*(const W1df670Mtx& b) const {
        W1df670Mtx o;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    // rotate v in place by the 3x3 part
    void rot(W1df670Vec& v) const {
        asm volatile(".set noreorder\n\tlqc2 $vf4, 0(%0)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\t"
                     "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tsqc2 $vf4, 0(%0)\n\t.set reorder"
                     : : "r"(&v), "r"(this) : "memory");
    }
    // VU0 matrix * column vector.
    W1df670Vec operator*(const W1df670Vec& v) const {
        W1df670Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
struct Def1df670 { u8 pad[6]; u16 node; u8 pad1[20]; f32 a[3]; f32 b[3]; u8 pad2[12]; u16 nodeA; u16 nodeB; f32 lenA; f32 lenB; u8 on; };
struct Pair1df670 { W1df670Vec a, b; };
struct Model1df670 { void* skel; u8 pad[60]; W1df670Mtx m; u8 pad2[268 - 128]; u32 f268; };
struct O1df670 {
    W1df670Mtx mtx;
    void* h;
    Def1df670* def;
    Model1df670* model;
    u8 pad[12];
    Pair1df670* pair;
    u32 flags;
};
extern s32 D_00352b50;
s32 func_0019ba60(Model1df670*);
s32 func_0019c6f0(Model1df670*);
void func_001dc700(void*, s32);
void func_001dcc30(void*);
void func_001dcc48(void*);
void func_0016b0e0(Model1df670*, u16, W1df670Mtx*);
W1df670Vec func_0016b478(Model1df670*, u16, f32);
W1df670Mtx func_0023ec48(Model1df670*, u16);
void func_0011d6c0(void*, u16, W1df670Mtx*);
void func_001df670(O1df670* o)
{
    switch (D_00352b50) {
    case 1:
        if (!func_0019ba60(o->model)) {
            o->flags |= 0x10;
            func_001dc700(o->h, 0);
            return;
        }
        func_001dc700(o->h, func_0019c6f0(o->model));
        if (o->model->f268 & 0x80) func_001dcc30(o->h);
        else func_001dcc48(o->h);
        func_0016b0e0(o->model, o->def->node, &o->mtx);
        if (!(o->flags & 4)) return;
        o->pair->a = func_0016b478(o->model, o->def->nodeA, o->def->lenA);
        o->pair->b = func_0016b478(o->model, o->def->nodeB, o->def->lenB);
        if (!o->def->on) return;
        {
            W1df670Vec t;
            W1df670Mtx m;
            t.x = o->def->a[0];
            t.y = o->def->a[1];
            t.z = o->def->a[2];
            *(s32*)&t.w = 0;
            func_0016b0e0(o->model, o->def->nodeA, &m);
            m.r3.unit();
            m.rot(t);
            o->pair->a += t;
            t.x = o->def->b[0];
            t.y = o->def->b[1];
            t.z = o->def->b[2];
            *(s32*)&t.w = 0;
            func_0016b0e0(o->model, o->def->nodeB, &m);
            m.r3.unit();
            m.rot(t);
            o->pair->b += t;
        }
        break;
    case 2: {
        Model1df670* mdl = o->model;
        if (mdl->skel) {
            W1df670Mtx m;
            func_0011d6c0(mdl->skel, o->def->node, &m);
            o->mtx = mdl->m * m;
        } else {
            o->mtx = mdl->m;
        }
        break;
    }
    case 3:
        o->mtx = func_0023ec48(o->model, o->def->node);
        break;
    }
}
}

// --------------------
// 001c6460: ambient node update (distance from the player, cool-down, drift back home)
// VU0 macro-mode vector/matrix helpers (hand-written asm in the original math library)
struct V1c6460 {
    f32 x, y, z, w;
    V1c6460() {}
    V1c6460& operator=(const V1c6460& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1c6460 operator-(const V1c6460& b) const
    {
        V1c6460 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1c6460 operator+(const V1c6460& b) const
    {
        V1c6460 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1c6460& operator+=(const V1c6460& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V1c6460 operator*(f32 k) const
    {
        V1c6460 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 lengthSq() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct M1c6460 {
    V1c6460 r[4];
    V1c6460 operator*(const V1c6460& v) const {
        V1c6460 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
struct N1c6460 {
    V1c6460 pos;
    u8 pad0[5];
    u8 active;
    u8 pad1[26];
    V1c6460 home;
    u8 pad2[12];
    f32 timer;
    u8 cool;
};
extern V1c6460 D_00352a60;
extern M1c6460 D_01d497f0;
extern f32 D_00349e10;
s32 func_001c5f38(N1c6460*);
s32 func_001c5c08(N1c6460*);
void func_001c6310(N1c6460*);
s32 func_001dbd68(N1c6460*);
void func_001c5f90(N1c6460*);
double func_00313b80(f32);
s32 func_003142e0(double, double);
void func_001c6460(N1c6460* n)
{
    if (func_001c5f38(n)) return;
    if (func_001c5c08(n)) return;
    V1c6460 d, p;
    d = n->pos - D_00352a60;
    d.y = 0.0f;
    f32 dist = d.normalize();
    if (n->cool) {
        if (1400.0f < dist) n->cool = 1;
        if (--n->cool == 0) n->active = 0;
        return;
    }
    p = D_01d497f0 * n->pos;
    if (p.z < 1000.0f && p.lengthSq() < 90000.0f) {
        n->active = 0;
        return;
    }
    if (__builtin_expect(n->active != 0, 1)) {
        n->timer -= D_00349e10;
        n->pos += d * D_00349e10 * -30.0f;
        n->pos.w = 1.0f;
        if (func_003142e0(func_00313b80(n->timer), 0.0) > 0) return;
        func_001c6310(n);
    } else if (860.0f < dist) {
        n->pos = n->home + d * 12.0f * 30.0f;
        n->timer = 12.0f;
        n->active = 0x80;
    } else if (400.0f < dist) {
        if (func_001dbd68(n)) func_001c5f90(n);
    }
}
}

// --------------------
// 002ebc80: minigame player motion select (idle/walk/turn left/right from speed and heading change)
extern "C" {
struct V2ebc80 {
    f32 x, y, z, w;
    V2ebc80() {}
    V2ebc80& operator=(const V2ebc80& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 length() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct O2ebc80 {
    u8 pad0[16];
    f32 x, y, z, w;
    f32 tx, ty, tz, tw;
    u8 pad1[320 - 48];
    struct { u8 pad[20]; s32 id; } mot;
    s32 motion() { return mot.id; }
    u8 pad2[8];
    u32 flags;
    u8 pad3[2144 - 356];
    V2ebc80 vel;
};
extern s32 D_00363540;
extern f32 D_01e2c044;
void func_002eb1e8(O2ebc80*);
s32 func_002eb3b8(O2ebc80*);
void func_002eba30(void*, O2ebc80*);
void func_002eba78(void*, O2ebc80*);
void func_002ebac0(void*, O2ebc80*);
void func_002eb778(O2ebc80*, s32, s32, f32);
f32 func_002f8ad0(f32, f32);
f32 func_0017ce10(f32);
void func_002ebc80(void* c, O2ebc80* o)
{
    func_002eb1e8(o);
    if (func_002eb3b8(o)) return;
    V2ebc80 v;
    v = o->vel;
    v.y = 0.0f;
    f32 spd = v.length();
    if (o->w == v.y) {
        if (spd < 2.0f) {
            func_002eba30(c, o);
            return;
        }
        if (o->w == 0.0f) {
            if (o->motion() == 253 || o->motion() == 252 || (o->flags & 2)) {
                func_002eb778(o, 254, 0, 8.0f);
                if (spd < 16.0f) D_00363540 = 0;
            } else if (o->motion() == 262 || o->motion() == 261) {
                func_002eb778(o, 254, 0, 16.0f);
            }
            return;
        }
    }
    typeof(o->mot)* mo = &o->mot;
    if (mo->id == 252) {
        func_002eba78(c, o);
        return;
    }
    if (mo->id == 253) {
        if (!(o->flags & 2)) return;
        if (++D_00363540 <= 0) return;
        if (8.0f <= spd) func_002ebac0(c, o);
        return;
    }
    if (D_00363540 > 0) {
        s32 next = 254;
        f32 d = func_0017ce10(func_002f8ad0(o->tx, o->tz) - func_002f8ad0(o->x, o->z));
        if (D_01e2c044 * 0.6f < d) next = 261;
        else if (d < D_01e2c044 * -0.6f) next = 262;
        if (__builtin_expect(mo->id == 253, 1)) func_002eb778(o, next, 0, 4.0f);
        else func_002eb778(o, next, 0, 16.0f);
    } else {
        func_002eba78(c, o);
    }
}
}

// --------------------
// 00193330: rebuild the object world bounding box from its shape bounds (or radius) and its matrix
extern "C" {
struct V193330 {
    f32 x, y, z, w;
    ~V193330() {}
    V193330& operator=(const V193330& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M193330 {
    V193330 r[4];
    // out = this * v (full 4x4)
    V193330 operator*(const V193330& v) const
    {
        V193330 o;
        V193330* out = &o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(out), "r"(this), "r"(&v) : "memory");
        return o;
    }
};
struct Box193330;
void func_00144450(Box193330*);
struct Box193330 {
    f32 minx, miny, minz, maxx, maxy, maxz;
    Box193330() { func_00144450(this); }
    void init(const V193330& p)
    {
        maxx = minx = p.x;
        maxy = miny = p.y;
        maxz = minz = p.z;
    }
    void grow(const V193330& t)
    {
        if (t.x < minx) minx = t.x;
        else if (maxx < t.x) maxx = t.x;
        if (t.y < miny) miny = t.y;
        else if (maxy < t.y) maxy = t.y;
        if (t.z < minz) minz = t.z;
        else if (maxz < t.z) maxz = t.z;
    }
};
struct Shape193330 {
    virtual void s0(); virtual void s1(); virtual void s2();
    virtual f32 radius();
    virtual void bounds(V193330*, V193330*);
    virtual void s5(); virtual void s6();
    virtual s32 kind();
};
struct O193330 {
    u8 pad0[64];
    M193330 mtx;
    u8 pad1[536 - 128];
    Box193330 local;
    const Box193330& getLocal() const { return local; }
    u8 pad2[1856 - 560];
    Box193330 world;
    u8 pad3[2088 - 1880];
    void* p2088;
    u8 pad4[2224 - 2092];
    Shape193330* shape;
};
void func_001b7c80(void*, Box193330*);
s32 func_00180cd0(void*);
void func_00144be0(Box193330*, V193330*);
void func_00193330(O193330* o)
{
    Box193330 box;
    V193330 t;
    V193330 corners[8];
    if (!o->shape) {
        if (o->p2088) func_001b7c80(o->p2088, &o->world);
    } else {
        if (func_00180cd0((u8*)o + 320) && o->shape->kind() < 2) {
            V193330 p, q;
            o->shape->bounds(&p, &q);
            box.minx = p.x;
            box.miny = p.y;
            box.minz = p.z;
            box.maxx = q.x;
            box.maxy = q.y;
            box.maxz = q.z;
        } else {
            box = o->getLocal();
            f32 r = o->shape->radius();
            box.minx -= r;
            box.miny -= r;
            box.minz -= r;
            box.maxx += r;
            box.maxy += r;
            box.maxz += r;
        }
        func_00144be0(&box, corners);
        o->world.init(o->mtx * corners[0]);
        for (s32 i = 1; i < 8; i++) {
            t = o->mtx * corners[i];
            if (t.x < o->world.minx) o->world.minx = t.x;
            else if (o->world.maxx < t.x) o->world.maxx = t.x;
            if (t.y < o->world.miny) o->world.miny = t.y;
            else if (o->world.maxy < t.y) o->world.maxy = t.y;
            if (t.z < o->world.minz) o->world.minz = t.z;
            else if (o->world.maxz < t.z) o->world.maxz = t.z;
        }
    }
}

struct Alloc123e30 {
    virtual u8* alloc(u32 size, void* ra);
};
struct Hdr123e30 { u8 pad[16]; u16 cnt; };
struct Mdl123e30 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual s32 parts();
    Hdr123e30* hdr;
    u8 pad[8];
    s32 n;
    s32 a[3];
    s32 b[3];
};
struct Obj123e30 {
    u8 pad0[16];
    Alloc123e30* al;
    u8 pad1[8];
    u8* p28;
    u8* p32;
    u8* p36;
    u8* p40;
    u8* p44;
    u8* p48;
    u8 pad2[260 - 52];
    u8* vis;
    u8* p264;
    u8* p268;
};
Mdl123e30* func_00124748(Mdl123e30*, s32);
void func_0011c2d0(Obj123e30*);
u8* func_00120a20(Mdl123e30*, Obj123e30*, u8*, u8*, s32);
void func_0011eef8(Mdl123e30*, Obj123e30*);
Obj123e30* func_00123e30(Mdl123e30* mdl, Alloc123e30* al)
{
    s32 i = 0;
    Hdr123e30* h = func_00124748(mdl, 0)->hdr;
    u32 off = (mdl->b[mdl->n - 1] + 15) & ~15;
    Obj123e30* o = (Obj123e30*)al->alloc(304 + off + h->cnt * 48 + mdl->a[mdl->n - 1] * 2, __builtin_return_address(0));
    func_0011c2d0(o);
    o->vis = (u8*)o + 304;
    for (i = 0; i < mdl->parts(); i++) o->vis[i] = 1;
    u8* p = o->vis + off;
    o->p28 = p;
    p += h->cnt * 16;
    o->p32 = p;
    p += h->cnt * 16;
    o->p36 = p;
    u8* q = al->alloc(h->cnt * 192, __builtin_return_address(0));
    o->p40 = q;
    q += h->cnt * 64;
    o->p44 = q;
    q += h->cnt * 64;
    o->al = al;
    o->p48 = q;
    s32 tot = 0;
    for (i = 0; i < mdl->n; i++) tot += func_00124748(mdl, i)->parts();
    o->p264 = o->p36 + h->cnt * 16;
    o->p268 = o->p264 + tot * 4;
    u8* d = (u8*)(((u32)(o->p268 + tot * 4) + 15) & ~15);
    tot = 0;
    for (i = 0; i < mdl->n; i++) {
        Mdl123e30* s = func_00124748(mdl, i);
        d = func_00120a20(s, o, o->p264 + tot * 4, d, 0);
        d = func_00120a20(s, o, o->p268 + tot * 4, d, 1);
        tot += s->parts();
    }
    func_0011eef8(mdl, o);
    return o;
}

struct V1253c0 {
    f32 x, y, z, w;
    V1253c0& operator=(const V1253c0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M1253c0 {
    V1253c0 r[4];
    M1253c0& operator=(const M1253c0& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    M1253c0 operator*(const M1253c0& b) const {
        M1253c0 o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    V1253c0 operator*(const V1253c0& v) const {
        V1253c0 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void scale(const V1253c0& s) {
        asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)" : : "r"(this), "r"(&s) : "memory");
    }
} __attribute__((aligned(16)));
struct Bone1253c0 { u8 pad0[2]; s16 sibling; s16 parent; s16 child; u32 w8; u32 hasParent : 1; u32 rest : 31; u8 pad[48]; } __attribute__((aligned(16)));
struct Skel1253c0 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6();
    virtual s32 count();
    virtual Bone1253c0* bones();
};
struct Self1253c0 { u8 pad0[20]; Skel1253c0* skel; u8 pad1[16]; M1253c0* local; M1253c0* world; };
extern M1253c0 D_003a99f0[];
s32 func_0011f270(Skel1253c0*, s32);
void func_001253c0(Self1253c0* s, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 idx, f32 f)
{
    Bone1253c0* bones = s->skel->bones();
    M1253c0* mats = D_003a99f0;
    V1253c0* scales = (V1253c0*)&mats[s->skel->count()];
    while (idx >= 0) {
        V1253c0 t;
        s32 parent;
        if (!bones[idx].hasParent) parent = func_0011f270(s->skel, idx);
        else parent = bones[idx].parent;
        if (parent < 0) {
            mats[idx] = s->local[idx];
            t = s->local[idx].r[3];
        } else {
            mats[idx] = mats[parent] * s->local[idx];
            t = s->world[parent] * s->local[idx].r[3];
        }
        s->world[idx] = mats[idx];
        s->world[idx].scale(scales[idx]);
        s->world[idx].r[3] = t;
        if (bones[idx].child >= 0) func_001253c0(s, a1, a2, a3, a4, a5, bones[idx].child, f);
        idx = bones[idx].sibling;
    }
}
}
