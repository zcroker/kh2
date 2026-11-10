// Orbiting object move (same object as 002d2b50). Built with -fno-strict-aliasing.
#include "../common/types.h"
extern "C" {
struct V2d31b0 {
    f32 x, y, z, w;
    V2d31b0() {}
    void Set3(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0.0f; }
    V2d31b0(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2d31b0(const V2d31b0& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2d31b0 operator+(const V2d31b0& b) const
    {
        V2d31b0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2d31b0& operator+=(const V2d31b0& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V2d31b0& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V2d31b0& operator=(const V2d31b0& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2d31b0 operator-(const V2d31b0& b) const
    {
        V2d31b0 r;
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
struct O2d31b0 {
    u8 pad0[264];
    u32 f264;
    u8 pad1[1344 - 268];
    V2d31b0 pos;
    u8 pad2[2780 - 1360];
    f32 height;
    u8 pad3[2800 - 2784];
    u8 lflag[4];
    s32 f2804;
    void* rec;
    u8 pad4[2864 - 2812];
    V2d31b0 dir;
    V2d31b0 to;
    f32 ang, radius, angVel, f2908, period, phase, bob;
    u8 pad5[2944 - 2924];
    u8 f2944;
    u8 pad6[3];
    f32 timer[64];
    bool InAir() { return 0.0f < height; }
};
extern void* D_00361f60;
extern f32 D_00349e10;
void func_0016a9a0(O2d31b0*);
void o2d31b0_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
s32 o2d31b0_is_attach(O2d31b0*) asm("_ZN2YS3OBJ9is_attachEv");
V2d31b0* func_002d1f20(void*);
V2d31b0 func_002d2870(void*, O2d31b0*);
void func_002d36f0(O2d31b0*);
f32 func_002d48b8(f32);
f32 cosf(f32);
f32 sinf(f32);
// Moves the object: attach check, circular path around "to", pending timers, bobbing.
void func_002d31b0(O2d31b0* o)
{
    func_0016a9a0(o);
    void* g = D_00361f60;
    // Partial asm: the original loads f264 only after g, with f264 in t7 (the register the
    // lui of g just freed). gcc hoists the load above g and picks t6.
    register u32 f asm("$15"); asm("lw %0,%1" : "=r"(f) : "m"(o->f264), "r"(g));
    o->f264 = f | 2;
    asm volatile(""); // keeps the f264 store above the f2944 load
    if (o->f2944 && !o->InAir()) o2d31b0_set(o->lflag, 4, 0);
    if (!o->rec) return;
    if (o2d31b0_is_attach(o)) return;
    V2d31b0 v(*func_002d1f20(D_00361f60));
    bool air = o->InAir();
    f32 zero = 0.0f;
    if (air) {
        o->pos.z = zero;
        o->pos.x += v.x;
    } else {
        V2d31b0 c = o->pos - o->to;
        V2d31b0 w(o->dir);
        w *= w.w * D_00349e10;
        v.z = zero;
        v.y = zero;
        w.x += v.x;
        c += w;
        o->ang = func_002d48b8(o->ang + o->angVel * D_00349e10);
        f32 cs = cosf(o->ang);
        V2d31b0 r(cs, sinf(o->ang), 0.0f, 0.0f);
        r *= o->radius;
        o->pos = c + r;
        o->pos.y += o->bob;
        o->to = o->pos - c;
        o->pos.z = zero;
    }
    o->pos += func_002d2870(g, o);
    for (s32 i = 0; i < 64; i++) {
        if (0.0f <= o->timer[i]) {
            o->timer[i] -= D_00349e10;
            if (o->timer[i] < 0.0f) func_002d36f0(o);
        }
    }
    if (0.0f < o->period) {
        f32 a = o->phase * 6.2831855f / o->period;
        o->phase += D_00349e10;
        while (o->period < o->phase) o->phase -= o->period;
        o->bob = sinf(a) * o->f2908;
    }
}

}
