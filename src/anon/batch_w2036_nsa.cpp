#include "../common/types.h"
extern "C" {
struct V15d058 {
    f32 x, y, z, w;
    V15d058() {}
    V15d058(const V15d058& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V15d058& operator=(const V15d058& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern V15d058 D_004f3760, D_004f3770, D_004f3780, D_004f3790, D_004f37a0, D_004f37b0;
V15d058 s15d058_spring(V15d058, V15d058, V15d058, f32, f32, f32, f32) asm("func_0013f6e8");
static inline void U15d058(V15d058& cur, V15d058& goal, V15d058& vel, f32 dt) { cur = s15d058_spring(cur, goal, vel, dt, 2.5f, 0.5f, 1.0f); }

void func_0015d058(V15d058* a, V15d058* b)
{
    D_004f37a0 = *b;
    D_004f3780 = *a;
    D_004f3760 = s15d058_spring(D_004f3760, D_004f37a0, D_004f37b0, 0.099999994f /* 0x3dcccccc */, 2.5f, 0.5f, 1.0f);
    *b = D_004f3760;
    U15d058(D_004f3770, D_004f3780, D_004f3790, 0.07f);
    *a = D_004f3770;
}
}
extern "C" {
struct V158dc0 {
    f32 x, y, z, w;
    V158dc0& operator=(const V158dc0& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Seg158dc0 { V158dc0 a, b; };
struct Tgt158dc0;
struct Tgt158dc0Vt { void* f[16]; s32 (*IsValid)(Tgt158dc0*); };
struct Tgt158dc0 { Tgt158dc0Vt* vt; };
struct C158dc0 { u8 pad[68]; Tgt158dc0* target; u8 pad2[8]; f32 dist; u8 pad3[12]; V158dc0 v96, v112, v128; };
extern V158dc0 D_0034a9b0;
extern u8 D_0034a9e8;
s32 func_00167f18(s32);
void func_00158ac8(C158dc0*);
void func_00158b78(s32, C158dc0*);
void func_00158b20(C158dc0*);
void func_00158c88(C158dc0*);
s32 func_0013f9e0(V158dc0*, V158dc0*, V158dc0*, s32, s32);
V158dc0 func_0016c2b0(Tgt158dc0*);
V158dc0* func_0016c028(Tgt158dc0*);
s32 func_00143d10(Seg158dc0*, V158dc0*, f32*, s32*);
f32 func_0013fd10(C158dc0*);
void func_00158dc0(C158dc0* c)
{
    s32 mode = func_00167f18(0);
    if (!c->target->vt->IsValid(c->target)) return;
    func_00158ac8(c);
    if (D_0034a9e8 == 1) {
        V158dc0 pos = func_0016c2b0(c->target);
        Seg158dc0 seg;
        V158dc0* pa = &seg.a;
        V158dc0& r = *func_0016c028(c->target);
        V158dc0* pb = &seg.b;
        *pa = r;
        *pb = pos;
        V158dc0 hit;
        f32 t;
        s32 n = 0;
        f32* pt = &t;
        if (func_00143d10(&seg, &hit, pt, &n)) D_0034a9b0 = hit;
        else D_0034a9b0 = pos;
        c->dist = func_0013fd10(c);
        D_0034a9e8 = 0;
    } else {
        func_00158b78(mode, c);
        if (func_0013f9e0(&c->v112, &c->v128, &c->v96, 1, 1)) {
            func_00158b20(c);
            func_00158c88(c);
            func_0013f9e0(&c->v112, &c->v128, &c->v96, 1, 1);
        }
    }
}
}
