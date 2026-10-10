#include "../common/types.h"
inline void* operator new[](unsigned int, void* p) { return p; }
inline void* operator new(unsigned int, void* p) { return p; }

extern "C" {
extern u8 D_00363860[];
void func_002edf28(u8*);  // obj_ctor_3637e0
void func_001a91f8(u8*);  // obj_init_24bytes
void func_001a92d8(u8*, u32, s32);
void func_00106ab8(u8*);  // noop_ret
void func_00108698(u8*);
void func_002eeee8(u8*, u8*);
struct VObj { void** vt; };
VObj* func_001a93e8(u8*);
u32 func_001a9420(u8*);
void func_0011e260(u32, u32);
void func_00106d40(u8*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_00106c08(u8*);
void func_0011b6a8(u8*);
struct V4 { f32 x, y, z, w; V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
  void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
  V4& operator=(const V4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct C4 { u8 r, g, b, a; void set(u8 R, u8 G, u8 B, u8 A) { r = R; g = G; b = B; a = A; } };
typedef u32 (*Fn9)(VObj*, u32);


void func_002ee8a8(u8* p, u32 a, u32 b)
{
    func_002edf28(p);  // obj_ctor_3637e0
    *(u32*)(p + 40) = a;
    *(u32*)(p + 36) = 0;
    *(u32*)p = (u32)D_00363860;
    func_001a91f8(p + 44);  // obj_init_24bytes
    func_001a92d8(p + 44, b, 0);
    func_00106ab8(p + 80);  // noop_ret
    func_00108698(p + 400);
    func_002eeee8(p + 456, p);
    VObj* v = func_001a93e8(p + 44);
    *(u32*)(p + 68) = ((Fn9)v->vt[9])(v, *(u32*)(p + 40));
    u32 s = func_001a9420(p + 44);
    func_0011e260(*(u32*)(p + 68), s);
    *(u32*)(p + 436) = s;
    *(u8*)(p + 408) = 0x80;
    *(u8*)(p + 409) = 0x80;
    *(u8*)(p + 410) = 0x80;
    *(f32*)(p + 432) = 80000.0f;
    *(u32*)(p + 400) |= 2;
    *(u8*)(p + 411) = 0xff;
    func_00106d40(p + 80, 512.0f, 0.799999952f, 0.866666615f, 2048.0f, 2048.0f, 1.0f, 16770000.0f, 1.0f, 4000000.0f, 256.0f, 208.0f);
    func_00106c08(p + 80);
    func_0011b6a8(p + 336);
    ((V4*)(p + 384))->set(0.0f, 0.0f, 500.0f, 1.0f);
}

void func_002eea80(u8* p, u32 a, u32 b)
{
    func_002edf28(p);  // obj_ctor_3637e0
    *(u32*)(p + 40) = a;
    *(u32*)(p + 36) = 0;
    *(u32*)p = (u32)D_00363860;
    func_001a91f8(p + 44);  // obj_init_24bytes
    func_001a92d8(p + 44, b, 0);
    func_00106ab8(p + 80);  // noop_ret
    func_00108698(p + 400);
    func_002eeee8(p + 456, p);
    VObj* v = func_001a93e8(p + 44);
    *(u32*)(p + 68) = ((Fn9)v->vt[9])(v, *(u32*)(p + 40));
    u32 s = func_001a9420(p + 44);
    func_0011e260(*(u32*)(p + 68), s);
    *(u32*)(p + 436) = s;
    *(u8*)(p + 408) = 0x80;
    *(u8*)(p + 409) = 0x80;
    *(u8*)(p + 410) = 0x80;
    *(f32*)(p + 432) = 80000.0f;
    *(u32*)(p + 400) |= 2;
    *(u8*)(p + 411) = 0xff;
    func_00106d40(p + 80, 512.0f, 0.799999952f, 0.866666615f, 2048.0f, 2048.0f, 1.0f, 16770000.0f, 1.0f, 4000000.0f, 256.0f, 208.0f);
    func_00106c08(p + 80);
    func_0011b6a8(p + 336);
    ((V4*)(p + 384))->set(0.0f, 0.0f, 500.0f, 1.0f);
}

}

// ---- 00188c30
namespace n00188c30 {
extern "C" {
void func_001888c8(void*);
void func_00189170(void*);
void func_001a8bb8(void*);  // obj_set_header_bytes
void func_001d9768(void*);
}
struct A276 { u8 d[276]; A276() { func_001888c8(this); } };
struct A56 { u8 d[56]; A56() { func_00189170(this); } };
struct A4 { u8 d[4]; A4() { func_001a8bb8(this); } };
struct Z4 { u32 v; Z4() { v = 0; } };
struct Z8 { u8 a; u32 b; Z8() { a = 0; b = 0; } };
struct E { Z8 e[64]; u32 x[4]; E() __attribute__((always_inline)); };
inline E::E() { for (s32 i = 0; i < 4; i++) x[i] = 0; }
extern "C" {
void func_00188c30(u8* p)
{
    new (p) A276[13];
    new (p + 3588) A56[10];
    p[4148] = 0;
    p[4149] = 0;
    p[4150] = 1;
    p[4152] = 100;
    p[4153] = 3;
    p[4154] = 3;
    new (p + 4164) A4[19];
    for (s32 i = 0; i < 8; i++) ((u32*)(p + 4560))[i] = 0;
    *(u32*)(p + 4592) = 0;
    for (s32 i = 0; i < 8; i++) ((u32*)(p + 4628))[i] = 0;
    for (s32 i = 0; i < 8; i++) ((u32*)(p + 4660))[i] = 0;
    *(u32*)(p + 4692) = 0;
    for (s32 i = 0; i < 10; i++) ((u32*)(p + 6296))[i] = 0;
    new (p + 6340) E;
    func_001d9768(p + 6878);
    *(s16*)(p + 6906) = 0;
    for (s32 i = 0; i < 4; i++) ((s16*)(p + 4616))[i] = 0;
}
}
}

// ---- 002df868
namespace n002df868 {
#undef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void ScaleIn(QWord* a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
}
static inline f32 Length(const QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void Normalize(QWord* v)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "$8", "$f0", "memory");
}
extern "C" {
extern u8* D_00361f60;
extern u8* D_0034e948;
void func_002df040(u8*, u8*);
QWord* func_0016c028(u8*);  // obj_get_attach_or_alt
u8* func_002dc7c8(u8*);
void func_002dd2d8(u8*, f32*, f32*);
void func_002df868(u8* s, u8* o)
{
    func_002df040(s, o);
    u8* m = D_00361f60;
    QWord t = *func_0016c028(o);  // obj_get_attach_or_alt
    QWord* d = (QWord*)(o + 16);
    t.v[0] = t.v[0] + *(f32*)(func_002dc7c8(m) + 240) * (f32)*(s32*)(s + 52);
    f32 lo, hi;
    func_002dd2d8(m, &lo, &hi);
    hi *= 0.95f;
    lo *= 0.95f;
    if (hi < t.v[0]) t.v[0] = hi;
    if (t.v[0] < lo) t.v[0] = lo;
    ScaleIn(d, *(f32*)(o + 28));
    *(f32*)(o + 16) = t.v[0] - func_0016c028(o)->v[0];
    f32 len = Length(d);
    Normalize(d);
    *(f32*)(o + 28) = len;
    if (*(s32*)(s + 56) == 0) {
        QWord e = Sub(*func_0016c028(D_0034e948), t);  // obj_get_attach_or_alt
        f32 dist = Length(&e);
        if (dist <= *(f32*)(func_002dc7c8(m) + 260)) *(s32*)(s + 56) = 1;
    }
}
}
}

// ---- 001bfa08
namespace n001bfa08 {
#undef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline void ScaleTo(QWord* r, const QWord& a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(&a), "f"(k) : "$8", "memory");
}
static inline void AddTo(QWord* r, const QWord& a, const QWord& b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(&a), "r"(&b) : "memory");
}
extern "C" {
extern f32 D_00349e10;
s32 func_0019ba60(u32);
f32 func_002f8960(f32);
void func_0016af58(QWord*, u8*);
void func_0016aeb8(u8*, f32);
void func_0016be98(QWord*, u32);
void func_0016ace0(u8*, QWord*);
u32 func_001a37e8(u32, s32);
void func_00138210(u32);
typedef void (*VF8)(u8*);
void func_001bfa08(u8* a0, u8* p)
{
    *(f32*)(p + 2492) -= D_00349e10;
    f32 r;
    if (func_0019ba60(*(u32*)(p + 2536)) && 0.0f < (r = *(f32*)(p + 2492))) {
        f32 t = r / *(f32*)(p + 2496);
        f32 one = 1.0f;
        f32 pi = 3.14159274f;
        t = one - func_002f8960((one - t) * pi * 0.5f);
        QWord v, s, w;
        ScaleTo(&s, *(QWord*)(p + 2512), t);
        v = s;
        v.v[1] -= func_002f8960(t * pi) * 50.0f;
        func_0016af58(&s, p);
        func_0016aeb8(p, s.v[3] + (one - t) * 0.52359873f);
        func_0016be98(&w, *(u32*)(p + 2536));
        AddTo(&s, w, v);
        func_0016ace0(p, &s);
        if (t < 0.1f) {
            t *= 9.99999905f;
            *(f32*)(p + 60) = *(f32*)(p + 2488) * t;
        }
        return;
    }
    u32 h = *(u32*)(p + 2484);
    if (h) func_00138210(func_001a37e8(h, -1));
    ((VF8)(*(void***)p)[8])(p);
}
}
}
