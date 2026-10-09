#include "../common/types.h"
struct Sub1cf { u8 pad[4]; u32 f4; u8 p2[431-8]; u8 b431; u8 b432; u8 b433; u8 b434; };
struct S2932 { u32 a; u32 b; u32 pad[6]; u32 c; };
struct E259 { u8 p0[8]; u8 f8[10]; u16 h18; u8 p1[16]; };
struct A22e { u8 p[4]; s16 h4; s16 h6; u8 b8; u8 b9; s16 h10; };
struct B22e { u8 p[2472]; f32 f2472; };
struct C22e { u8 p[8]; B22e* f8; };
struct W22e { u32 f0; u32 f4; f32 f8; };
struct V22e { u32 f0; B22e* f4; union { W22e* p; u32 u; f32 f; } f8; u8 p[36]; B22e* f48; };
struct __attribute__((aligned(16))) W259V4 {
    f32 x, y, z, w;
    W259V4& operator=(const W259V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
static inline void w259_vscale(W259V4* d, const W259V4* a, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
static inline f32 w259_vnorm(W259V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void w259_vzero(W259V4* d) {
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(d) : "memory");
}
struct P178 { u64 fl; u8 pad[48 - 8]; u8 m48[12]; f32 f60; };
struct O178 { u8 pad[16]; W259V4 v; u8 p1[272 - 32]; f32 f272; f32 f276; u8 p2[292 - 280]; f32 f292; u8 p3[2872 - 296]; P178* f2872; };
extern "C" {

extern u8 D_00352360[];
struct C32bb30 { u8 pad[15792]; u16 a; u16 b; };
extern C32bb30 D_0032bb30;
extern f32 D_0036e3bc;
extern u8 D_00351ec0[];
void func_00177dc8(u8*, u32, s32, u32, u32);
void func_0017a480(u8*, u32, s32, s32);
void func_001a1a50(Sub1cf*, s32);
void func_001d2648(u8*, s32, f32);
void func_001c8d80(u8*, s32);
s32 func_002a0360(void);
s32 func_002a9b88(s32);
s32 func_002a8870(s32);
s32 func_002b3ae8(void);
s32 func_002a6500(void);
s32 func_002a7530(void);
s32 func_0029a5f0(s32 idx) {
    s32 tbl[12];
    s32* p = tbl;
    for (s32 i = 0; i < 12; i++) {
        if (i == 0 && !func_002a0360()) continue;
        if (i == 7 && !func_002a9b88(-1)) continue;
        if (i == 8 && !func_002a8870(-1)) continue;
        if (i == 5 && !func_002b3ae8()) continue;
        if (i == 9 && !func_002a6500()) continue;
        if (i == 10 && !func_002a7530()) continue;
        *p++ = i;
    }
    return tbl[idx];
}
void func_001cfbd8(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00177dc8(p, a1, 11, a2, a3);
    *(u32*)(p + 2920) = 0;
    *(u32*)(p + 2924) = 0;
    *(u32*)(p + 0) = (u32)D_00352360;
    *(u8*)(p + 2928) = 0;
    S2932* s2 = (S2932*)(p + 2932);
    u8* s = (u8*)s2;
    s2->a = 0;
    s2->b = 0;
    s2->c = 0;
    *(u32*)(p + 1416) |= 0x2000000;
    ((Sub1cf*)*(u32*)(p + 1164))->b432 = 0;
    ((Sub1cf*)*(u32*)(p + 1164))->b433 = 0;
    ((Sub1cf*)*(u32*)(p + 1164))->b434 = 3;
    func_0017a480(p, ((Sub1cf*)*(u32*)(p + 1164))->f4, 0, 0);
    func_001a1a50((Sub1cf*)*(u32*)(p + 1164), 0);
    f32 k = D_0036e3bc;
    ((Sub1cf*)*(u32*)(p + 1164))->b431 = 1;
    if (D_0032bb30.a < 999) D_0032bb30.a++;
    if (D_0032bb30.b < 999) D_0032bb30.b++;
    *(u32*)(p + 2748) |= 0x240;
    func_001d2648(s, 0xbbc2, k);
    func_001c8d80(D_00351ec0, 4);
}

extern E259 D_00372ed8[];
extern void* D_0035f64c;
extern u32 D_0035f664;
s32 func_00253578(void);
void func_00288d80(void*, s32, s32, s32, u32, u32, E259*, void*);
void func_00288e08(void*, s32, s32, s32);
u32 func_002891b8(void*, s32);
void func_00139620(u32);
void func_001395f8(u32);
void func_002891f0(void*, s32, s32, s32, s32);
void func_0028af18(void*, s32);
void func_00259e90(void) {
    for (s32 i = 0; i < 2; i++) {
        if (i == 1 && func_00253578() == 2) break;
        func_00288d80(D_0035f64c, i, 0, 0, D_0035f664, D_00372ed8[i].h18, &D_00372ed8[i], D_00372ed8[i].f8);
        func_00288e08(D_0035f64c, i, 0, -1);
        func_00139620(func_002891b8(D_0035f64c, i));
        func_001395f8(func_002891b8(D_0035f64c, i));
    }
    func_002891f0(D_0035f64c, 0, 1, 0, 2);
    func_0028af18(D_0035f64c, 115);
}

s32 func_002282f0(s32);
void* func_002282d8(void);
C22e* func_00227d10(s32);
void func_001ba028(B22e*);
s32 func_00225b00(s32);
V22e* func_00102c18(s32, void*, void*);
void* func_001050c8(void);
W22e* func_001063c0(s32, void*);
void func_0014f030(W22e*, f32, f32, f32);
void func_0022ed70(void);
void func_0022ee00(void);
void func_0022ee30(A22e* a) {
    if (func_002282f0(a->h4)) return;
    void* s = func_002282d8();
    C22e* c = func_00227d10(a->h6);
    func_001ba028(c->f8);
    if (!func_00225b00(a->h4)) {
    V22e* v = func_00102c18(1, s, (void*)func_0022ed70);
    v->f48 = (B22e*)func_0022ee00;
    v->f4 = c->f8;
    W22e* w = func_001063c0(12, func_001050c8());
    w->f0 = 0;
    w->f4 = 0;
    w->f8 = 1.0f;
    v->f8.p = w;
    func_0014f030(w, (f32)a->b8, (f32)a->b9, (f32)a->h10 * 2.0f);
    } else {
        c->f8->f2472 = (f32)a->b9;
    }
}

W259V4 func_00178330(void*);
void func_001785b8(O178* o) {
    w259_vzero(&o->v);
    if (0.0f < o->f2872->f60) {
        o->v = func_00178330(o->f2872->m48);
        f32 k = (o->f2872->f60 < 0.8f) ? o->f272 : o->f276;
        w259_vscale(&o->v, &o->v, k);
    }
    u64 fl = o->f2872->fl;
    if (!(fl & (1ull << 32))) {
        if (fl & 0x20000000) o->v.y = -o->f292;
        else if (fl & 0x40000000) o->v.y = o->f292;
    }
    o->v.w = w259_vnorm(&o->v);
}
}
