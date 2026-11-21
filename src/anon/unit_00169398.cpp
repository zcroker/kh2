// 00169398 / 00169990: object constructor (vtable D_0034d850), base-object (C2) and complete-object (C1) clones
// from one source. The clones differ only in the two one-word table Clear() calls (see W1637TabA/B below).
#include "../common/types.h"

struct W1637Param { u8 p0[6]; u8 b6; u8 p7[0x41]; u16 h48; u8 p4a[10]; u8 b54; u8 p55; u8 b56; };
struct W1637Res { u8 p0[8]; s32 f8; };
struct W1637Mdl;
typedef s32 (*W1637VFn)(W1637Mdl*, s32);
struct W1637Mdl { W1637VFn* vt; };

extern "C" {
extern u8 D_0034d850[];
extern u32 D_0034f240;
void func_001ddd10(void*);
void func_001957e8(void*);
void func_0017e9d0(void*, void*);
void func_0019f578(void*);
void func_0031e2c0(void*);
void func_0031b9e0(void*);
void func_0031e158(void*);
void func_001a91f8(void*);
void func_001a92d8(void*, u32, W1637Param*);
void func_0031e268(void*);
s32 func_001948e0(void);
W1637Mdl* func_001a93e8(void*);
s32 func_001050c8(void);
s32 func_001a9420(void*);
void func_0011e260(s32, s32);
void func_0011c4b0(s32);
W1637Res* func_00168b38(s32, s32, s32);
void func_001826c8(f32);
}

#define W1637_AI __attribute__((always_inline))
struct W1637V {
    f32 x, y, z, w;
    W1637_AI inline W1637V() {}
    W1637_AI inline W1637V(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    W1637V(const W1637V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1637V& operator=(const W1637V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1637_AI inline void Set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
};
struct W1637Col { u8 r, g, b, a; W1637_AI inline W1637Col() {} W1637_AI inline W1637Col(s32 v) : r(v), g(v), b(v), a(v) {} W1637_AI inline void Set(s32 v) { r = v; g = v; b = v; a = v; } };
extern "C" void func_001ddd10(void*);
struct W1637X1c { u8 d[0x1c]; W1637_AI inline W1637X1c() { func_001ddd10(this); } };
struct W1637V3 { f32 x, y, z; };
struct W1637M9 { W1637V3 v[3]; W1637_AI inline W1637M9() { v[0].x = 0.0f; v[2].z = 0.0f; v[0].z = 0.0f; v[1].x = 0.0f; v[1].y = 0.0f; v[1].z = 0.0f; v[2].x = 0.0f; v[2].y = 0.0f; v[0].y = 0.0f; } };
struct W1637X110 { u8 d[0x30]; W1637_AI inline W1637X110() { func_001957e8(this); } };
struct W1637X140 { u8 d[0x1c0]; W1637_AI inline W1637X140(void* own) { func_0017e9d0(this, own); } };
// One-element pointer tables. Clear() is a template member: gcc inlines it only at its first use in the file
// (while the instantiation is still pending) and calls the out-of-line copy everywhere after that, which is
// what makes the two constructor clones differ (C2 inlines one Clear per table, C1 inlines none).
template <class T> struct W1637TabA { T* v[1]; inline void Clear() asm("_Z13func_0031cc28Pv"); };
template <class T> inline void W1637TabA<T>::Clear() { for (s32 i = 0; i < 1; i++) v[i] = 0; }
template <class T> struct W1637TabB { T* v[1]; inline void Clear() asm("_Z13func_0031e2b8Pv"); };
template <class T> inline void W1637TabB<T>::Clear() { for (s32 i = 0; i < 1; i++) v[i] = 0; }
struct W1637Slot { s32 a; W1637TabA<void> h; inline W1637Slot() { a = 0; h.Clear(); h.Clear(); } };
struct W1637S300 {
    s32 a, b; W1637Slot slot[16]; s32 c[5]; W1637TabB<void> e; s32 d;
    W1637_AI inline W1637S300() { a = 0; b = 0; c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0; c[4] = 0; e.Clear(); d = 0; }
};
struct W1637X60 { u8 d[0x60]; W1637_AI inline W1637X60() { func_0019f578(this); } };
struct W1637X4 { u32 d; W1637_AI inline W1637X4() { func_0031e2c0(this); } };
struct W1637Pair { s32 a, b; W1637_AI inline W1637Pair() : a(0), b(0) {} };
struct W1637Q4a0 { s32 a, b, c, d; W1637_AI inline W1637Q4a0() : a(0), b(0), c(0), d(-1) {} };
struct W1637EF { f32 e, f; W1637_AI inline W1637EF() { f = e = 0.0f; } };
struct W1637G5 { s32 g[5]; W1637_AI inline W1637G5() { g[0] = 0; g[1] = 0; g[2] = 0; g[3] = 0; g[4] = 0; } };
struct W1637HI { u8 h; u8 p1[3]; s16 i; u8 p6[2]; W1637Pair pr[4]; W1637_AI inline W1637HI() : h(0), i(0) { } };
struct W1637S570 { s32 a; u8 p4[2]; s16 b; s32 c; W1637_AI inline W1637S570() : a(0), b(0), c(3) {} };
struct W1637X590 { u8 d[0x90]; W1637_AI inline W1637X590() { func_0031b9e0(this); } };
struct W1637S620 {
    W1637V a; W1637V b; u8 p20[4]; s32 c, d, e, f; u8 g;
    W1637_AI inline W1637S620() : c(0xffff), d(0), e(0), f(0), g(0) {
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&a) : "memory");
        asm volatile("lqc2 $vf4, 0(%1)\n\tvsub.xyz $vf5, $vf0, $vf4\n\tsqc2 $vf5, 0(%0)" : : "r"(&b), "r"(&a) : "memory");
    }
};
struct W1637F660 { u32 b0:1; u32 b1:1; u32 b2:1; u32 r:29; W1637_AI inline W1637F660() { b0 = 0; b1 = 1; b2 = 0; } };
struct W1637S670 {
    s32 h; u8 p4[0x28]; s32 f2c; u8 p30[0xc8]; s32 ff8; u8 pfc[8]; f32 f104, f108; u8 p10c[0x13]; u8 b11f;
    W1637_AI inline W1637S670() { func_0031e158(this); }
    W1637_AI inline void SetRange(f32 a, f32 b) { f104 = a; f108 = b; }
    W1637_AI inline void SetB(u8 v) { b11f = v; }
};
struct W1637S7a0 {
    u8 d[0xc]; s32 fc; u8 p10[8]; u8 o18[0x40];
    W1637_AI inline s32 GetFc() { return fc; }
    W1637_AI inline void Attach(void* own, void* p, void* q);
    W1637_AI inline W1637S7a0(u32 id, W1637Param* prm) { func_001a91f8(this); func_001a92d8(this, id, prm); }
};
struct W1637I4 { s32 a, b, c, d; W1637_AI inline W1637I4() : a(0), b(0), c(0), d(0) {} };
union W1637U { s32 i; f32 f; W1637_AI inline W1637U(s32 v) : i(v) {} };
struct W1637X8e0 { u8 d[0xc8]; W1637_AI inline void Init() { func_0031e268(this); } };

struct W1637T { W1637V v860, v870, v880, v890, v8a0; W1637Mdl* mdl; u8 p8b4[8]; };
union W1637UF { s32 i; f32 f; };
struct W1637FI { f32 a; W1637UF b; W1637_AI inline W1637FI() : a(1.0f) { b.i = 0; } W1637_AI inline f32 GetB() { return b.f; } };
struct W1637Obj {
    void* vt;               // 0x000
    W1637Obj* self;         // 0x004
    W1637Param* param;      // 0x008
    u8 p00c[4];
    W1637V v010;            // 0x010
    W1637V v020;            // 0x020
    W1637V v030;            // 0x030
    u8 p040[0x40];
    W1637X1c o080;          // 0x080
    W1637X1c o09c;          // 0x09c
    u8 p0b8[8];
    W1637M9 m0c0;           // 0x0c0
    u8 p0e4[0x1c];
    s32 f100, f104, f108, f10c;   // 0x100
    W1637X110 o110;         // 0x110
    W1637X140 o140;         // 0x140
    W1637S300 s300;         // 0x300
    u8 p3a4[8];
    W1637Col col3ac;        // 0x3ac
    s32 f3b0;               // 0x3b0
    W1637X60 o3b4;          // 0x3b4
    W1637X60 o414;          // 0x414
    s32 f474;               // 0x474
    W1637X4 o478;           // 0x478
    s32 f47c;               // 0x47c
    W1637X4 o480;           // 0x480
    s32 f484, f488, f48c;   // 0x484
    u8 p490[0x10];
    W1637Q4a0 s4a0;         // 0x4a0
    W1637EF ef4b0; u8 p4b8[0x48]; s32 g500, g504, g508, g50c, g510; W1637HI hi514;
    u8 p53c[0x24];
    W1637V v560;            // 0x560
    W1637S570 s570;         // 0x570
    s32 d57c; u8 p580[8]; s32 e588, f58c;
    W1637X590 o590;         // 0x590
    W1637S620 s620;         // 0x620
    u8 p658[8];
    W1637F660 fl660;        // 0x660
    s32 f664, f668;         // 0x664
    s32 f66c;
    W1637S670 s670;         // 0x670
    u8 p790[0x10];
    W1637S7a0 s7a0;         // 0x7a0
    s32 f7f8;               // 0x7f8
    u8 b7fc; u8 p7fd[3];
    W1637I4 i800;           // 0x800
    s32 f810; u8 p814[4]; s32 f818, f81c, f820, f824, f828;  // 0x810
    W1637FI s82c;           // 0x82c
    W1637FI s834;           // 0x834
    u8 p83c[0x24];
    W1637T t860;            // 0x860
    W1637Col col8bc;
    f32 f8c0, f8c4, f8c8, f8cc, f8d0, f8d4;
    s32 f8d8; u8 b8dc, b8dd; u8 p8de[2];
    W1637X8e0 o8e0;         // 0x8e0
    f32 f9a8;               // 0x9a8
    u8 b9ac, b9ad; u8 p9ae[2];
    s32 f9b0;               // 0x9b0

    static void* operator new(unsigned int, void* p) { return p; }
    W1637Obj(u32 id, W1637Param* prm, s32 a3, const W1637V& pos, f32 rot);
};

extern "C" {
void func_001b9380(W1637Obj*);
void func_0016bd10(W1637Obj*, s32);
void func_00194468(W1637Obj*);
void func_0016a1b8(W1637Obj*, s32);
void func_001b0448(void*, W1637Obj*);
void func_0016aeb8(W1637Obj*, f32);
void func_0016adc8(W1637Obj*, W1637V);
void func_00193608(W1637Obj*);
void func_0016a2b0(W1637Obj*);
void func_001a9560(void*, W1637Obj*, void*, void*);
}

W1637_AI inline void W1637S7a0::Attach(void* own, void* p, void* q) { func_001a9560(this, (W1637Obj*)own, p, q); }

W1637Obj::W1637Obj(u32 id, W1637Param* prm, s32 a3, const W1637V& pos, f32 rot)
    : vt(D_0034d850), self(this), param(prm),
      v010(0.0f, 0.0f, 0.0f, 0.0f), v020(0.0f, 0.0f, 0.0f, 0.0f), v030(1.0f, 1.0f, 1.0f, 1.0f),
      f100(-1), f104(5), f108(0), f10c(0), o140(this), col3ac(0x80), f3b0(0), f474(0), f47c(0), f484(0), f488(0), f48c(0),
      d57c(0), e588(0), f58c(0),
      g500(0), g504(0), g508(0), g50c(0), g510(0),
      v560(0.0f, 0.0f, 0.0f, 0.0f), s7a0(id, prm),
      f7f8(0), b7fc(0), f810(0), f818(0), f81c(0), f828(0)
{
    f32 z = s834.GetB();
    t860.v860.Set(z, z, z, z); t860.v870.Set(z, z, z, z); t860.v880.Set(z, z, z, z); t860.v8a0.Set(z, z, z, z);
    col8bc.Set(0x80); f8c0 = 1.0f; f8c4 = z; f8c8 = z; f8cc = z; f8d0 = 1.0f; f8d4 = z; f8d8 = 0; b8dc = 1; b8dd = 0;
    o8e0.Init();
    f9a8 = 64.0f;
    b9ac = (func_001948e0() || (D_0034f240 & 0x10)) ? 0 : prm->b56; b9ad = a3; f9b0 = 0;
    func_001b9380(this);
    func_0016bd10(this, 0);
    t860.mdl = func_001a93e8(&s7a0);
    if (t860.mdl) {
        s32 r;
        s670.h = t860.mdl->vt[9](t860.mdl, func_001050c8());
        r = func_001a9420(&s7a0);
        if (r) {
            func_0011e260(s670.h, r);
            s670.f2c = r;
            f7f8 |= 2;
        }
        func_0011c4b0(s670.h);
        s670.SetRange(300.0f, 2000.0f);
        func_00194468(this);
        if (prm->h48 & 0x10) s670.ff8 |= 0x20;
        s670.SetB(param->b6);
    } else {
        s670.h = 0;
        s670.ff8 &= ~4;
        s670.ff8 &= ~8;
    }
    f668 = 0;
    f664 = 0;
    {
        W1637Res* r = func_00168b38(s7a0.GetFc(), 23, 0);
        if (r && r->f8) func_0016a1b8(this, r->f8);
    }
    s620.b.Set(0.0f, 1.0f, 0.0f, 1.0f);
    func_001826c8((f32)prm->b54);
    func_001b0448(&s4a0, this);
    f820 = 0; f824 = 0;
    t860.v890 = pos;
    t860.v890.w = rot;
    func_0016aeb8(this, rot);
    func_0016adc8(this, pos);
    func_00193608(this);
    func_0016a2b0(this);
    s7a0.Attach(this, &o09c, s7a0.o18);
}

