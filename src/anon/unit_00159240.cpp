#include "../common/types.h"

// The light-cycle follow camera, second file (0x159240-0x159790): follows the bike from behind,
// or from a fixed point when the pad button toggles it.

typedef unsigned int u128 __attribute__((mode(TI)));

struct Q16 {
    u128 v;
    Q16() {}
    Q16(const Q16& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};

struct Q16Pair {
    Q16 v[2];
};

struct V159368 {
    f32 x, y, z, w;
    V159368() {}
    ~V159368() {}
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

static inline f32 deg2rad(f32 d) { return d * 3.1415927f / 180.0f; }

static f32 D_004f35b0 = deg2rad(60.0f);  // view angle

extern "C" {
u32 D_0034aa08;  // 1: fixed view

s32 func_00143d10(Q16Pair*, Q16*, Q16*, s32*);
s32 func_00162098(void);
void func_00162058(f32);
void* func_00140df0(void);
u8* func_00167f18(s32);
V159368* func_0016c028(Obj159368*);
void func_0013f648(Cam159368*);

// Drops a point onto the ground below it (or keeps it when nothing is hit).
void func_00159240(Q16* out, Q16* in) {
    s32 y = 0;
    Q16 x;
    Q16 lo = *in;
    Q16 hi = *in;
    Q16Pair seg;
    Q16* ph = &seg.v[1];
    ((f32*)&lo)[1] -= 100.0f;
    ((f32*)&hi)[1] += 10000.0f;
    seg.v[0] = lo;
    *ph = hi;
    if (!func_00143d10(&seg, out, &x, &y)) *out = *in;
}

void func_00159308(u8* p) {
    if (*(u64*)(p + 8) & 0x400000) {
        if (!func_00162098()) {
            D_0034aa08 ^= 1;
            func_00162058(12.0f);
        }
    }
}

// Camera follow. The pinned &b pointer and empty asm at the final copy steer global-alloc so
// &b lands in t4 (partial asm, carried from the function match).
void func_00159368(Cam159368* c)
{
    static V159368 s_ofs(600.0f, -500.0f, 0.0f, 1.0f);
    static V159368 s_fixEye(51.0f, -1492.0f, 0.0f, 1.0f);
    static V159368 s_fixAt(256.0f, -1777.0f, 0.0f, 1.0f);
    u8* in = func_00167f18(0);
    if (c->obj->vt->check(c->obj)) func_00159308(in);
    V159368 d;
    V159368 t;
    V159368 p;
    V159368 b;
    V159368 a;
    f32 k;
    if (D_0034aa08) {
        a = s_fixEye;
        b = s_fixAt;
        k = 1.5f;
    } else {
        a = c->pos;
        t = *func_0016c028(c->obj);
        func_00159240((Q16*)&p, (Q16*)&t);
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
        b = a + s_ofs;
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



void func_00159700(void) {
    D_0034aa08 = 0;
    *(u32*)((u8*)func_00140df0() + 64) = 5;
}

}
