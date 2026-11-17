// Linked unit 0x193038-0x193608 (YS model object per-frame colour/shadow update and its helper 0x193330).
// The whole-asm function 0x193608 (src/anon/batch_w3952.s) follows this unit; unit_00193be8.cpp follows it.
// 0x193038 is partial asm (moved as is from batch_w3906_g.cpp).
// Flags: -G0 -g -fno-strict-aliasing (old copies: 0x193038 _g, 0x193330 _nsa).
#include "../common/types.h"

// ---- 00193038 from src/anon/batch_w3906_g.cpp
namespace n00193038 {
struct Rgba193038 {
    u8 r, g, b, a;
    Rgba193038 operator*(Rgba193038 t) const
    {
                                                                                      
        Rgba193038 c;
        asm("lbu $13,%4\n\t"
            "la $14,%4\n\t"
            "lbu $15,%5\n\t"
            "lbu $12,1($14)\n\t"
            "mult $13,$13,$15\n\t"
            "lbu $10,3($14)\n\t"
            "lbu $11,2($14)\n\t"
            "lbu $14,%7\n\t"
            "lbu $15,%6\n\t"
            "sra $13,$13,7\n\t"
            "mult $11,$11,$14\n\t"
            "sb $13,%0\n\t"
            "mult $12,$12,$15\n\t"
            "sra $11,$11,7\n\t"
            "lbu $15,%8\n\t"
            "sra $12,$12,7\n\t"
            "sb $12,%1\n\t"
            "mult $10,$10,$15\n\t"
            "sb $11,%2\n\t"
            "sra $10,$10,7\n\t"
            "sb $10,%3"
            : "=m"(c.r), "=m"(c.g), "=m"(c.b), "=m"(c.a)
            : "m"(r), "m"(t.r), "m"(t.g), "m"(t.b), "m"(t.a)
            : "$10", "$11", "$12", "$13", "$14", "$15");
        return c;
    }
};
struct Def193038 { u8 pad[72]; u16 flags; };
struct O193038 {
    u8 pad0[8];
    Def193038* def;
    u8 pad1[940 - 12];
    Rgba193038 color;
    u8 pad2[1348 - 944];
    f32 f1348;
    u8 pad3[1416 - 1352];
    u32 f1416;
    u8 pad4[1536 - 1420];
    u64 f1536;
    bool castsShadow() { return ((f1536 >> 33) & 1) == 0; }
    u8 pad5[1656 - 1544];
    u32 f1656;
    u8 pad6[1667 - 1660];
    u8 b1667;
    u8 pad7[1700 - 1668];
    s32 f1700;
    u8 pad8[1880 - 1704];
    Rgba193038 outColor;
    u8 pad9[1896 - 1884];
    u32 f1896;
    u8 pad10[1908 - 1900];
    f32 fadeDist;
    u8 pad11[4];
    u8 shadow;
    u8 pad12[2236 - 1917];
    Rgba193038 tint;
    f32 f2240;
    u8 pad13[2472 - 2244];
    f32 f2472;
};
void func_00193330(O193038*) asm("func_00193330");
f32 func_00194690(O193038*) asm("func_00194690");
void func_0016a070(O193038*) asm("func_0016a070");
s32 func_0019bad8(O193038*) asm("func_0019bad8");
f32 func_00184a90(O193038*) asm("func_00184a90");
s32 func_001bfda0(void*, Rgba193038*) asm("func_001bfda0");
s32 func_001943e8(O193038*) asm("func_001943e8");
s32 func_0019c5d0(O193038*) asm("func_0019c5d0");
s32 func_0019c650(O193038*) asm("func_0019c650");
s32 func_001c0cd8(O193038*) asm("func_001c0cd8");
void func_00143398(void*) asm("func_00143398");
void func_00193038(O193038* o) asm("func_00193038");
void func_00193038(O193038* o)
{
    func_00193330(o);
    u8 work[112] __attribute__((aligned(16)));
    Rgba193038 c __attribute__((aligned(16)));
    if ((o->def->flags & 4) || (o->f1416 & 0x20000000)) {
        c = o->color;
        c.a = (o->color.a * o->tint.a) >> 7;
    } else {
        c = o->color * o->tint;
    }
    f32 k = func_00194690(o);
    {
                                                                                    
        register s32 a asm("$15");
        register O193038* arg asm("$4");
        asm("lbu $15,%6\n\t"
            "lbu $13,%8\n\t"
            "move $4,%5\n\t"
            "lbu $14,%9\n\t"
            "mtc1 $15,$f0\n\t"
            "cvt.s.w $f0,$f0\n\t"
            "lbu $15,%7\n\t"
            "sb $15,%0\n\t"
            "sb $13,%1\n\t"
            "mul.s $f0,$f0,%10\n\t"
            "sb $14,%2\n\t"
            "cvt.w.s $f1,$f0\n\t"
            "mfc1 $15,$f1"
            : "=m"(o->outColor.r), "=m"(o->outColor.g), "=m"(o->outColor.b), "=r"(a), "=r"(arg)
            : "r"(o), "m"(o->color.a), "m"(c.r), "m"(c.g), "m"(c.b), "f"(k)
            : "$13", "$14", "$f0", "$f1");
        o->outColor.a = a;
        func_0016a070(arg);
    }
    if (func_0019bad8(o)) {
        o->shadow = 0;
        if (o->castsShadow()) {
            f32 d = func_00184a90(o) - o->f1348;
            if (d < o->fadeDist) o->shadow = (s32)(o->f2472 * (c.a * 0.0078125f) * k * (1.0f - d / o->fadeDist));
        }
    } else {
        o->shadow = (s32)(o->f2472 * (c.a * 0.0078125f) * k);
    }
    if (o->f2240 < 1.0f) {
        o->f1656 |= 2;
        o->b1667 = (s32)(o->f2240 * 256.0f);
    } else {
        o->f1656 &= ~2;
    }
    o->f1700 = func_001bfda0((u8*)o + 2272, &o->outColor);
    if (func_001943e8(o)) o->f1656 |= 8;
    else o->f1656 &= ~8;
    if (func_0019c5d0(o)) o->f1896 &= ~4;
    else o->f1896 |= 4;
    if (func_0019c650(o)) o->f1896 &= ~8;
    else o->f1896 |= 8;
    if (!func_001c0cd8(o)) func_00143398((u8*)o + 1648);
}
}  // namespace n00193038

// ---- 00193330 from src/anon/batch_wcx2_nsa.cpp
namespace n00193330 {
inline void* operator new(unsigned int, void* p) { return p; }
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
static inline W2db210Vec operator*(f32 k, const W2db210Vec& v) { return v * k; }
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
                                
    V193330 operator*(const V193330& v) const
    {
        V193330 o;
        V193330* out = &o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(out), "r"(this), "r"(&v) : "memory");
        return o;
    }
};
struct Box193330;
void func_00144450(Box193330*) asm("func_00144450");
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
void func_001b7c80(void*, Box193330*) asm("func_001b7c80");
s32 func_00180cd0(void*) asm("func_00180cd0");
void func_00144be0(Box193330*, V193330*) asm("func_00144be0");
void func_00193330(O193330* o) asm("func_00193330");
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
}  // namespace n00193330

