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
