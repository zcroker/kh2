// 00159368: camera follow (w3690). Match under -O2 -fno-strict-aliasing.
// The pinned &b pointer + empty asm at the final copy steers global-alloc so &b lands in t4 (partial asm).
#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct V159368 {
    f32 x, y, z, w;
    V159368() {}
    V159368(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V159368& operator=(const V159368& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V159368 operator-(const V159368& b) const {
        V159368 d;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&d), "r"(this), "r"(&b) : "memory");
        return d;
    }
    V159368 operator+(const V159368& b) const {
        V159368 d;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&d), "r"(this), "r"(&b) : "memory");
        return d;
    }
    V159368& operator*=(f32 s) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    f32 Length() const {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Obj159368;
struct Obj159368Vt { void* f[16]; s32 (*check)(Obj159368*); };
struct Obj159368 { Obj159368Vt* vt; };
struct Cam159368 {
    V159368 pos;
    u8 pad0[32];
    f32 f48;
    f32 f52;
    u8 pad1[12];
    Obj159368* obj;
    u8 pad2[24];
    V159368 f96;
    u8 pad3[16];
    V159368 f128;
};
extern "C" {
extern s8 D_004f35b8;
extern s8 D_004f35c0;
extern s8 D_004f35c8;
extern V159368 D_004f35d0;
extern V159368 D_004f35e0;
extern V159368 D_004f35f0;
extern f32 D_004f35b0;
extern s32 D_0034aa08;
void func_00159758(void);
void func_00159760(void);
void func_00159768(void);
void func_002fd188(void (*)(void));
u8* func_00167f18(s32);
void func_00159308(u8*);
V159368* func_0016c028(Obj159368*);
void func_00159240(V159368*, V159368*);
void func_0013f648(Cam159368*);
// Camera follow. The three offset vectors are function-local statics
// (guards D_004f35b8/c0/c8, empty atexit dtors func_00159758/60/68).
void func_00159368(Cam159368* c)
{
    if (!D_004f35b8) {
        new (&D_004f35d0) V159368(600.0f, -500.0f, 0.0f, 1.0f);
        D_004f35b8 = 1;
        func_002fd188(func_00159758);
    }
    if (!D_004f35c0) {
        new (&D_004f35e0) V159368(51.0f, -1492.0f, 0.0f, 1.0f);
        D_004f35c0 = 1;
        func_002fd188(func_00159760);
    }
    if (!D_004f35c8) {
        new (&D_004f35f0) V159368(256.0f, -1777.0f, 0.0f, 1.0f);
        D_004f35c8 = 1;
        func_002fd188(func_00159768);
    }
    u8* in = func_00167f18(0);
    if (c->obj->vt->check(c->obj)) func_00159308(in);
    V159368 d;
    V159368 t;
    V159368 p;
    V159368 b;
    V159368 a;
    f32 k;
    if (D_0034aa08) {
        a = D_004f35e0;
        b = D_004f35f0;
        k = 1.5f;
    } else {
        a = c->pos;
        t = *func_0016c028(c->obj);
        func_00159240(&p, &t);
        p.y -= 150.0f;
        d = p - a;
        f32 l;
        if (d.Length() < 0.0f) {
            l = 0.0f;
        } else if (d.Length() > 200.0f) {
            l = 200.0f;
        } else {
            l = d.Length();
        }
        d *= l / 200.0f;
        a = a + d;
        b = a + D_004f35d0;
        k = D_004f35b0;
    }
    c->f48 = k;
    c->f52 = 0.0f;
    c->f128 = a;
    register V159368* pb asm("$12") = &b;
    asm("" : "+r"(pb));
    c->f96 = *pb;
    func_0013f648(c);
}
}
