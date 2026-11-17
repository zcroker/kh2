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
f32 fabsf(f32);
bool t1b1100(Obj1b1100*, V1b1100*) asm("_Z16ctarget_001b1100jjjj");
// 001b1100: moved to src/yasui/libys/lookat.cpp

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
void func_002d1550(G2d1550* g, s32 id, s32 arg);  // 0x002d1550: definition moved into src/anon/unit_002cf260.cpp

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
f32 g2d1908_fabsf(f32) asm("fabsf");
void g2d1908(G2d1550*) asm("_Z16wtarget_002d1908jjjj");
void g2d1908(G2d1550* g);  // 0x002d1908: definition moved into src/anon/unit_002cf260.cpp
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
// 00103ca0: moved to src/common/unit_001031b0.cpp
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
f32 fabsf(f32);
void func_002d3b78(O2d3b78* o, Hit2d3b78* h);  // 0x002d3b78: definition moved into src/anon/unit_002d2498.cpp
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
void func_002d4b40(O2d4b40* o);  // 0x002d4b40: definition moved into src/anon/unit_002d4548.cpp
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
f32 fabsf(f32);
void func_002d5200(O2d5200* o, Hit2d5200* h);  // 0x002d5200: definition moved into src/anon/unit_002d4548.cpp
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
void func_002d9220(O2d9220* o, s32 mode);  // 0x002d9220: definition moved into src/anon/unit_002d6f70.cpp
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
void func_002d9810(O2d9810* o);  // 0x002d9810: definition moved into src/anon/unit_002d96d8.cpp
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
f32 cosf(f32);
f32 sinf(f32);
void o2db210_002d9208(void*, s32) asm("_Z13func_002d9208Pvi");
void func_002db210(O2db210* o);  // 0x002db210: definition moved into src/anon/unit_002da040.cpp

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
f32 fabsf(f32);
f32 func_002dd250(void*, s32);
f32 func_002dd280(void*, s32);
void func_002e0870(O2e0898*, f32*, f32*, f32*);
void func_002e0898(O2e0898* o, P2e0898* p, f32 x);  // 0x002e0898: definition moved into src/anon/unit_002de3c8.cpp
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
void func_001c6460(N1c6460* n);  // 0x001c6460: definition moved into src/anon/unit_001c5b90.cpp
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
// 002ebc80: moved to src/anon/unit_002eaf38.cpp
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
void func_00193330(O193330* o);  // 0x00193330: definition moved into src/anon/unit_00193038.cpp

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
Obj123e30* func_00123e30(Mdl123e30* mdl, Alloc123e30* al);  // 0x00123e30: definition moved into src/anon/unit_00123990.cpp

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
void func_001253c0(Self1253c0* s, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 idx, f32 f);  // 0x001253c0: definition moved into src/anon/unit_00123990.cpp

struct V1e1988 {
    f32 x, y, z, w;
    V1e1988() {}
    V1e1988& operator=(const V1e1988& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1e1988 operator-(const V1e1988& o) const {
        V1e1988 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    void zero() { asm volatile(".set noreorder\n\tsqc2 $vf0, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize() {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M1e1988 {
    V1e1988 r[4];
    V1e1988 operator*(const V1e1988& v) const {
        V1e1988 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Self1e1988 {
    u8 pad0[3524];
    M1e1988* mats;
    u8* items;
    s32 nitems;
    void* res;
    void* o3540;
    void* o3544;
    void* o3548;
    void* o3552;
};
void* func_0016abf8(void*, s32, s32, s32);
void func_001dca50(void*, M1e1988*, s32);
void func_001dca30(void*, void*, s32);
f32 cosf(f32);
void func_0011b6a8(M1e1988*);
void func_0011b720(M1e1988*, f32);
void func_001e0de8(void*);
void func_001e1988(Self1e1988* s);  // 0x001e1988: definition moved into src/anon/unit_001e0cb8.cpp

struct P2b5 { s16 x; s16 p2; s16 y; };
struct Q2b5 { u8 pad[8]; s32 a; s32 b; u8 pad2[8]; P2b5* p; };
struct F2b5 { u32 b0:3; u32 b3:1; u32 hi:28; };
struct Sub2b5 { u8 pad[0xb8]; F2b5 f; };
struct O2b5 { u8 pad[0x18]; Sub2b5 sub; u8 pad2[0x1b4 - 0xd4]; void* cb; };
extern Q2b5* D_0035f6cc;
extern O2b5* D_0035f658;
extern s32 D_0035f644;
extern s32 D_0035f640;
extern s32 D_0035f664;
extern s32 D_0035f648;
extern s32 D_0035f64c;
extern s32 D_0035f678;
extern s32 D_0035f3d4;
extern O2b5* D_0035f680[4];
void func_002b6138();
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
s32* func_0023f1b0(s32);
s32 func_0023c4b8(s32*, s32);
s32 func_00236ca8(s32, s32);
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00288d80(s32, s32, s32, s32, s32, s32, s32, s32);
void* func_002891b8(s32, s32);
void func_001395f8(void*);
void func_00139620(void*);
void func_00288e08(s32, s32, s32, s32);
void func_002b57e0(void);
O2b5* func_0028c198(s32, s32, s32, s32, s32, s32);
void func_0028dcc0(void*, void*);
void func_0028af90(s32, s32);
s32 func_0023d2e0(s32*);
s32 func_00240ba0(void);
void func_0023d300(s32*);
s32 func_002418b8(void);
void func_002891f0(s32, s32, s32, s32, s32);
void func_002b5c30(s32);
s32 func_00233e60(void);
void func_00234570(s32, s32);
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
void func_00287cc0(s32);

void func_002b5188(s32 arg0, s32 arg1);  // 0x002b5188: definition moved into src/anon/unit_002b3ac8.cpp
}

struct Obj1db808 { void** vt; };
struct B1db808 { void* vt; Obj1db808* o; u32 p8; s32 c; };
typedef void (*Fn1db808)(Obj1db808*, s32);
extern "C" {
void func_00106420(void*);
extern void* D_00352a38;
void func_001db808(B1db808* b) {
    b->vt = &D_00352a38;
    Obj1db808* o = b->o;
    ((Fn1db808)o->vt[1])(o, b->c);
    func_00106420(b);
}
}
