// 0023da00: sl tied to a3 by an empty asm raises the a3 copy in sched1 (partial asm), so move s6,a3 comes before addu s0,a0,s0.
#include "../common/types.h"
extern "C" {
struct V23da00 {
    f32 x, y, z, w;
    V23da00() {}
    V23da00(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V23da00& operator=(const V23da00& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct Mot23da00 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6();
    virtual f32 len();
};
struct Res23da00 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8();
    virtual s32 get(s32);
};
struct Obj23da00 {
    V23da00 pos;
    V23da00 rot;
    V23da00 scl;
    s32 w48;
    u8 pad52[4];
    u32 flags;
    u8 pad60[4];
    s8 rgba[4];
    u8 pad68[92 - 68];
    void* p92;
    u8 pad96[112 - 96];
    void* mdl;
    Mot23da00* mot;
    s32 w120;
    s32 w124;
    u8 pad128[192 - 128];
    u8 m192[28];
    s32 w220[16];
    u8 pad284[0];
    s32 a2;
    s32 a3;
    s32 t0;
    s32 w296;
    f32 f300;
    f32 f304;
    f32 f308;
    struct Col { u8 r, g, b, a; void set(s32 R, s32 G, s32 B, s32 A) { r = R; g = G; b = B; a = A; } } col;
    u8 b316;
};
struct Mgr23da00 {
    u8 pad0[2916];
    u8 slot[4];
    s32 count;
};
void func_0023eac0(Mgr23da00*, s32, s32);
void func_0023dd28(Mgr23da00*, s32, s32, s32);
void func_00107330(void*, f32, f32, f32);
void func_00107340(void*, f32, f32, f32);
void func_00107350(void*, f32, f32, f32);
void func_00107360(void*, f32);
void func_00107118(void*);
s32 func_0013a1d8();
void* func_001063c0(s32, s32);
void func_001a91f8(void*);
void func_001a92d8(void*, s32, s32);
s32 func_00103580();
Res23da00* func_001a93e8(void*);
Mot23da00* func_001a9458(void*, s32, s32);
void* func_001a9420(void*);
void func_0011e260(s32, void*);
f32 func_0023e700(Mgr23da00*);
void* func_001a9528(void*);
void func_001dddd0(void*, void*);
void func_001a9560(void*, Obj23da00*, void*, s32*);
void func_0023da00(Mgr23da00* m, s32 idx, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2)
{
    u8* cam = (u8*)m + idx * 400 + 288;
    s32 sl = m->slot[idx] * 320; asm("" : "+r"(sl) : "r"(a3));
    Obj23da00* o = (Obj23da00*)((u8*)m + sl + 1632);
    func_0023eac0(m, idx, 16);
    func_0023dd28(m, idx, t1, t2);
    func_00107330(cam, 0.0f, -50.0f, -800.0f);
    func_00107340(cam, 0.0f, 0.0f, 55.0f);
    func_00107350(cam, 0.0f, -1.0f, 0.0f);
    func_00107360(cam, 0.0f);
    func_00107118(cam);
    o->rot.unit();
    o->pos = V23da00(0.0f, 0.0f, 0.0f, 0.0f);
    o->scl = V23da00(1.0f, 1.0f, 1.0f, 1.0f);
    void* p = func_001063c0(24, func_0013a1d8());
    func_001a91f8(p);
    func_001a92d8(p, a2, 0);
    o->mdl = p;
    o->a2 = a2;
    o->a3 = a3;
    o->t0 = t0;
    o->w48 = 0;
    s32 v = func_00103580();
    o->w48 = func_001a93e8(o->mdl)->get(v);
    if (a3 >= 0) o->mot = func_001a9458(o->mdl, a3, t0);
    else o->mot = 0;
    o->w120 = 0;
    o->w124 = 0;
    o->flags |= 2;
    o->rgba[3] = -1;
    o->rgba[2] = -128;
    o->rgba[1] = -128;
    o->rgba[0] = -128;
    o->p92 = func_001a9420(o->mdl);
    if (o->p92) func_0011e260(o->w48, o->p92);
    o->col.set(128, 128, 128, 128);
    if (o->mot) {
        o->f300 = o->mot->len();
        o->f304 = o->mot->len();
        o->f308 = func_0023e700(m);
        o->b316 = 1;
        o->w296 = 0;
    }
    for (s32 i = 0; i < 16; i++) o->w220[i] = 0;
    void* x = func_001a9528(o->mdl);
    if (x) {
        func_001dddd0(o->m192, x);
        func_001a9560(o->mdl, o, o->m192, o->w220);
    }
    m->count++;
}
}
