#include "../common/types.h"
struct V299 {
    f32 x, y, z, w;
    V299() {}
    V299& operator=(const V299& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 Normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline V299 operator-(const V299& a, const V299& b) {
    V299 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct M299 {
    f32 m[4][4];
    M299& operator=(const M299& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void MulM299(M299* d, const M299* a, const M299* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct Act2d6;
struct Act2d6Vt { void* s[24]; s32 (*f96)(Act2d6*); };
struct Act2d6 { Act2d6Vt* vt; u8 pad[1412]; u32 f1416; u8 pad2[2780 - 1420]; f32 f2780; u8 pad3[2868 - 2784]; f32 f2868; };
struct Ctx2d6 { u8 pad[16]; Act2d6* f16; };
struct Cfg2d6 { u8 pad[140]; f32 f140; u8 pad2[12]; f32 f156; };
struct Mg2d6 { u8 pad[320]; u8 f320; };
extern "C" {
extern s32 D_0032dfc8;
extern u8 D_0032f230;
void func_001b74b8(void*);
void func_001a1950(void*, s32, s32, s32);
void func_001a1a20(void*, s32, s32);
void func_001a1aa0(void*, s32);  // ring_buffer_index
void func_00188958(void*, s32);
void func_001b7508(void*, s32, s32);
void func_001a3188(s32, s32, s32);
void func_001b7538(void*, s32);
void func_001b7428(s32);
void func_001b7658(void*, s32, s32);
struct Sub1c0 { u8 pad[16]; u8 f16; u8 f17; u8 f18; };
struct Obj1c0 { u8 pad0[4]; s32 f4; u8 pad8[388-8]; s32 f388; u8 pad392[434-392]; u8 f434; u8 pad435[580-435]; Sub1c0* f580; u8 pad584[596-584]; s32 f596; u8 pad600[4]; s32 f604; };
void func_001c0690(u8* p, Obj1c0* o) {
    u8 buf[80];
    func_001b74b8(buf);
    s32 a = p[2];
    s32 b = p[3];
    if (D_0032dfc8 == 3) {
        s32 t = p[1];
        if (t != 0 && (t < 4 || t == 14)) {
            a /= 2;
            b /= 2;
        }
    }
    o->f4 += a;
    o->f388 += b;
    func_001a1950(o, a, 0, 0);
    func_001a1a20(o, b, 0);
    s32 n = o->f434 + p[4];
    if (n >= 10) n = 9;
    o->f434 = n;
    func_001a1aa0(o, 0);  // ring_buffer_index
    if (o->f580) {
        func_00188958(o->f580, o->f580->f18 + p[5]);
        o->f580->f17 += p[6];
        o->f580->f16 += p[7];
    }
    func_001b7508(buf, a, 0x8ae2);
    func_001b7508(buf, b, 0x8ae3);
    func_001b7508(buf, p[4], 0x8ae4);
    func_001b7508(buf, p[5], 0x8ae5);
    func_001b7508(buf, p[6], 0x8ae6);
    func_001b7508(buf, p[7], 0x8ae7);
    u8* q = p;
    s32 i = 1;
    do {
        if (*(u16*)(q+8)) {
            func_001a3188(*(u16*)(q+8), o->f596, 0);
            func_001b7538(buf, *(u16*)(q+8));
        }
        i--;
        q += 2;
    } while (i >= 0);
    if (o->f604) func_001b7428(o->f604);
    func_001b7658(buf, p[1], D_0032f230);
}
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
void func_0011b6a8(void*) asm("_Z13func_0011b6a8Pv");
M299* func_0011b8d0(M299* m, const V299& axis, f32 ang) {
    V299 v;
    v = axis;
    v.Normalize();
    f32 x = v.x, y = v.y, z = v.z;
    f32 s = func_002f8960(ang);
    f32 c = func_002f87c0(ang);
    M299 r;
    func_0011b6a8(&r);
    f32 t = 1.0f - c;
    r.m[0][0] = x * x * t + c;
    r.m[0][1] = x * y * t + z * s;
    r.m[0][2] = x * z * t - y * s;
    r.m[1][0] = x * y * t - z * s;
    r.m[1][1] = y * y * t + c;
    r.m[1][2] = y * z * t + x * s;
    r.m[2][0] = x * z * t + y * s;
    r.m[2][1] = y * z * t - x * s;
    r.m[2][2] = z * z * t + c;
    M299 tmp;
    MulM299(&tmp, &r, m);
    *m = tmp;
    return m;
}

extern Mg2d6* D_00361f60;
Cfg2d6* config2d6(Mg2d6*) asm("_ZN2Ti9MGOarashi6configEv");
s32 is_attach2d6(Act2d6*) asm("_ZN2YS3OBJ9is_attachEv");
V299 getpos2d6(Act2d6*) asm("_Z16ctarget_0016bda8jjjj");
void setdir2d6(Act2d6*, V299*, f32) asm("_Z16ctarget_00186a90jjjj");
void wt2cf280(void*, s32, s32) asm("_Z16wtarget_002cf280jjjj");
void func_002d6600(Act2d6*, V299*);
void func_002d3f18(Act2d6*);
f32 func_002f8870(f32);  // fabsf
static inline u8 pos2d6(Act2d6* t) { return 0.0f < t->f2780; }
void func_002d6750(Act2d6* a, Ctx2d6* c) {
    Mg2d6* g = D_00361f60;
    Cfg2d6* cf = config2d6(g);
    if (is_attach2d6(a)) return;
    if (cf->f156 > a->f2868) return;
    if (a->vt->f96(a)) return;
    Act2d6* t = c->f16;
    if (!t) return;
    if ((t->f1416 & 0x8000000) && pos2d6(t)) return;
    if (!t) return;
    V299 d = getpos2d6(a) - getpos2d6(c->f16);
    d.z = 0;
    f32 len = d.Normalize();
    if (len < 0.01f) {
        d.y = d.z = 0.0f;
        d.x = 1.0f;
    }
    g->f320 = 1;
    if (is_attach2d6(a)) {
        func_002d6600(a, &d);
    } else {
        if (config2d6(g)->f140 < 0.0f) d.Zero();
        setdir2d6(a, &d, func_002f8870(config2d6(g)->f140));  // fabsf
    }
    wt2cf280((u8*)c->f16 + 2800, 256, 0);
    func_002d3f18(c->f16);
}
struct Obj2d69 { u8 pad[56]; f32 f56; };
void func_002d6948(Act2d6* a, Obj2d69* o) {
    if (is_attach2d6(a)) return;
    o->f56 -= 50.0f;
}
}
