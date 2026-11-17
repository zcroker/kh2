#include "../common/types.h"

struct VObj { void** vt; };
typedef s32 (*VFn)(void*);

extern "C" {

// 00100b70: compare two FDEs by their decoded initial PC (mixed CIE encodings).
s32 func_001009a0(u8*);
u32 func_00100920(u8, void*);  // classify_subtype
u8* func_001004c0(u8, u32, u8*, u32*);
struct Fde { u32 len; s32 cie; u8 pc[1]; };
static inline u8* FdeCie(Fde* f) { return (u8*)&f->cie - f->cie; }
s32 func_00100b70(void* ob, Fde* x, Fde* y)
{
    s32 xe, ye;
    u32 xp, yp;
    xe = func_001009a0(FdeCie(x));
    func_001004c0(xe, func_00100920(xe, ob), x->pc, &xp);
    ye = func_001009a0(FdeCie(y));
    func_001004c0(ye, func_00100920(ye, ob), y->pc, &yp);
    if (xp > yp) return 1;
    if (xp < yp) return -1;
    return 0;
}

// 0011e260: attach a chunk list, then process element 0 and every (0, i) pair.
void* func_00132068(void*, s32);  // entry_get_by_index
void* func_00132018(void*);  // entry_ptr_from_header
void func_0011e410(void*, void*);
void func_0011e450(void*, void*);
void func_0011e600(void*, void*, void*);
struct ChunkList { s16 tag; s16 pad; u32 n; };
struct ChunkUser { u8 pad[52]; ChunkList* list; };
static inline void* ChunkAt(ChunkList* c, s32 i) { return func_00132018(func_00132068(c, i)); }
void func_0011e260(ChunkUser* self, ChunkList* c);  // 0x0011e260: definition moved into src/anon/unit_0011c128.cpp

// 0011f2f0: initialise by kind, then run the object's two virtual hooks.
void func_00123ac0(void*, void*);
void func_0011f4b8(void*, void*);
void func_001206e0(void*, void*);
void func_0011ed90(s32, s32);
VObj* func_0011f2f0(u8* self);  // 0x0011f2f0: definition moved into src/anon/unit_0011c128.cpp

// 0013ba60: table lookups with fallbacks.
extern u32 D_00348060[][12];
extern u32 D_003483f0[];
extern u32 D_00348400[];
extern u32 D_00348410[];
s32 func_0013b9e0(s32, s32);
s32 func_0013ba50(s32);
s32 func_0013ba60(s32 a0, s32 a1, s32 a2, u8* a3, s32 a4, u32* a5, u32* a6);  // 0x0013ba60: definition moved into src/anon/unit_0013a8b8.cpp

// 001403b0: per-frame update using the global time step.
extern f32 D_00349e10;
void func_0013f5f0(void*);  // copy_float_220_to_48
s32 func_00167f18(s32);
s32 func_0013ff08(void*, s32, f32);
s32 func_00140370(void*, s32);
void func_00140210(void*, s32, f32);
void func_0013f828(void*);
void func_0013f888(void*, void*, s32);
void func_0013fca8(void*);
void func_001403b0(u8* self);  // 0x001403b0: definition moved into src/anon/unit_0013fca8.cpp

// 00143b88: two-stage lookup; the second stage overrides the first on success.
union Word { void* p; u32 w; u16 h; };
extern Word D_00348804;
s32 func_00165db8(u32, u32, u16*, u32, u32, u32, u32*, u32, u32);
void func_00141c18(void*, u32, u32, u32, u32);
s32 func_00141ff0(void*, u32, u32, u16*, u32);
s32 func_00143b88(u32 a0, u32 a1, u16* out, Word* flag, u32 a4);  // 0x00143b88: definition moved into src/anon/unit_00142c90.cpp

// 00146128
s32 func_00146730(void*, void*);
void func_00146100(void*, s32*, s16);
void func_00146128(u8* self, s32* cnt, s16 idx);  // 0x00146128: definition moved into src/anon/unit_00145600.cpp

// 0014ca80: split a 60 Hz frame counter into hours/minutes/seconds/hundredths.
u32 func_0014ca78(u32);
s32 __fixunssfsi(f32);
void func_0014ca80(u32 a0, u32* h, u32* m, u32* s, s32* cs);  // 0x0014ca80: definition moved into src/anon/unit_0014c7f0.cpp

// 0015d5d0
s32 func_0013ef80(u32);  // get_global_byte_358700
void func_001024a8(u32);
void func_0013f048(void);
void func_00236788(void*);  // to_236830
struct G34b0 { u8 pad[276]; u32 f276; u8 pad2[48]; u32 f328; u32 f332; };
extern G34b0 D_0034b0e0;
extern u8 D_0034af40[];
s32 func_00239d30(void*, u32);
s32 func_00239d10(void*);
u8* func_0014aba8(void);
void func_0023acd8(void*);
void func_0023ade0(void*);
// 0015d5d0: moved to src/anon/unit_0015d440.cpp

// 0017e138
void func_0017f488(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, s32, f32, f32);
u8* func_00177860(void*);
extern u8* D_00352130;
// 0017e138: moved to src/yasui/libys/friend.cpp

// 00194318: step a fade level by +-16 (clamped 0..128) and apply it to two colour entries.
u8* func_001bfd60(void*, u32);
void func_00194318(u8* self);  // 0x00194318: definition moved into src/anon/unit_00193be8.cpp

// 001a2340: apply percentage bonuses gated by ability flags.
s32 func_00177ba0(u32);
s32 func_00177bf8(u32);
struct BonusSrc { u8 pad[472]; u32 flags; u8 pad2[58]; u16 r0; u16 r1; u16 r2; u8 pad3[64]; u32 h; };
struct BonusMask { u8 pad[46]; u8 b0 : 1, b1 : 1, b2 : 1; };
static inline bool Mask0(BonusMask* q) { return q->b0; }
static inline bool Mask1(BonusMask* q) { return q->b1; }
static inline bool Mask2(BonusMask* q) { return q->b2; }
s32 func_001a2340(u32 unused, s32 dmg, BonusSrc* p, BonusMask* q);  // 0x001a2340: definition moved into src/anon/unit_0019fb70.cpp

// 001b6b10
s32 func_0019ba60(void*);
u8* func_001050d8(s32);
void func_001b6298(void*, void*, s32, s32);
void func_0016bd60(void*, s32);
void func_001c9860(s32);
extern u8 D_0032f054;
extern u8 D_0032bb30[];
void func_001b6b10(u8* self, s32 id);  // 0x001b6b10: definition moved into src/anon/unit_001b6a50.cpp

// 001bdd50: nudge a scale value by 1/8, clamped to [0.5, 1].
void func_0016bda8(void*, void*);
void func_0017cf00(void*, void*);
void func_0013b2b8(f32);
void func_001bdd50(u8* self);  // 0x001bdd50: definition moved into src/anon/unit_001bc568.cpp

// 001c3ba8
f32 func_00184a90(void*);
f32* func_0016c028(void*);  // obj_get_attach_or_alt
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define HEIGHT(o) (func_00184a90(o) - func_0016c028(o)[1])
struct RangeParam { u8 pad[36]; f32 k; f32 off; f32 max; };
struct RangeObj { u8 pad[240]; RangeParam* p; };
static inline f32 Above(RangeObj* o) { f32 t = MAX(HEIGHT(o), 0.0f); return t - o->p->off; }
f32 func_001c3ba8(u32 unused, RangeObj* o);  // 0x001c3ba8: definition moved into src/anon/unit_001c2b58.cpp

// 001c7440: fade-in alpha while timer < 12, otherwise tick a countdown and call a hook.
struct NoTail { ~NoTail() {} };
void func_001c7148(void*);
void func_001c71b8(void*);
void func_001c7420(void);
extern u64 D_01d49940;
// 001c7440: moved to src/anon/unit_001c7148.cpp (linked unit)

// 001ca758
extern void* D_00351f68;
extern const u8 D_0036e0f8[];
extern const u8 D_0036e108[][16];
void func_001a5420(void*, const void*, u32);
void func_001ca758(u32 a0, u8* cnt);  // 0x001ca758: definition moved into src/anon/unit_001ca638.cpp

// 001d3e40
u32 func_001d3f98(void*);
s32 func_00170978(u32);
s32 func_001a9758(u32, s32);
u32 func_0017df58(s32);
s32 func_0017e280(u32);
u8* func_00176b58(u8);
s32 func_0017e310(void*);
s32 func_001d3e40(u8* self);  // 0x001d3e40: definition moved into src/anon/unit_001d3c08.cpp

// 001d5f30: add points and level up while the next threshold is reached.
s32 func_001bbb28(void*);
struct Level { u32 a; s32 v; };
extern u8 D_0032e020[];
Level* func_00189200(void*, u32);
Level* func_001d5c10(u32, Level*);
void func_001d5d80(void*, u32);
void func_001b7468(void*);
void func_001d5f30(u8* self, s32 add);  // 0x001d5f30: definition moved into src/anon/unit_001d4f40.cpp

// 001e2130
void func_001e0e50(void*);
void func_001e2130(u8* self);  // 0x001e2130: definition moved into src/anon/unit_001e0cb8.cpp

// 001fb5b8: scale an RGBA byte colour by the global colour multipliers.
extern u8* D_01d9e6e0;
void sceVu0CopyVector(void*, void*);  // memcpy16
void func_001fb508(void*, s32, s32);
extern u8 D_00354be0[];
void func_001fb5b8(u8* base, u8* c, u8* a2)
{
    base += **(u32**)(a2 + 12);
    u8* p = base + 160;
    p[36] = (s32)(c[8] * *(f32*)(D_01d9e6e0 + 48));
    p[37] = (s32)(c[9] * *(f32*)(D_01d9e6e0 + 52));
    p[38] = (s32)(c[10] * *(f32*)(D_01d9e6e0 + 56));
    p[39] = (s32)(c[11] * *(f32*)(D_01d9e6e0 + 60));
    sceVu0CopyVector(base + 176, D_00354be0);  // memcpy16
    func_001fb508(p, 0, 0);
}

// 00248900
s32 func_00287bc0(void);
void func_00287d68(void);  // copy_globals_3words
s32 func_00287db0(void);
s32 func_0028acc8(void*);
s32 func_00139d78(void*);
void func_001039f8(void);
void func_00248b38(void);
void func_002489d8(void);
extern void* D_0035ed4c;
extern void* D_0035ed50;
extern void* D_0035ed54;
extern void* D_0035ed58;
extern void* D_0035ed5c;
s32 func_00248900(void);  // 0x00248900: definition moved into src/anon/unit_00247ff0.cpp

// 00256f18
extern void* D_0035f01c;
extern void* D_0035f020;
extern void* D_0035f024;
s32 func_002892f8(void*);
void func_00288e88(void*);
void func_00256f18(void);  // 0x00256f18: definition moved into src/anon/unit_00254020.cpp

// 0025d918: create the menu object and set up its layers.
u8* func_0023ee30(u32);
void func_002369a0(void*);  // obj_ctor_36eac8
void func_0023c008(void*);  // obj_ctor_36eae8
s32 func_0023f948(void*, s32);
void func_0028d7f0(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(void*);
void func_0028f280(s32, s32, void*, void*, void*);
void func_00263960(s32, s32, void*, void*, void*);  // store_globals_and_init
void func_0023d2e0(u32*);  // store_global_test_result
void func_00240b90(u32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0025dba8(void);
extern u8 D_0035eb98[];
extern u8* D_0035f664;
extern void* D_0035f674;
extern u8 D_00373100[];
extern u8 D_00373108[];
extern u8 D_00373130[];
extern u8 D_00373138[];
void func_0025d918(void);  // 0x0025d918: definition moved into src/anon/unit_002588e8.cpp

// 00265ab8: stop every active effect slot.
typedef void (*VoidFn)(void*);
static inline void StopIfActive(VObj* o) { if (func_00139d78(o)) ((VoidFn)o->vt[5])(o); }
u8* func_00257770(void);
void func_00139510(void*);
void func_0028abe0(void*);
void func_00265ab8(void);  // 0x00265ab8: definition moved into src/anon/unit_00265580.cpp

// 00285760
s32 func_00289380(void*);
s32 func_00289310(void*);
s32 func_0028ae28(void*, s32);
void func_00138c10(void*, s32);
void func_0028ab20(void*);
void func_00287df0(s32, s32, s32, s32, s32);
extern void* D_0035f2dc;
extern void* D_0035f2d8;
s32 func_00285760(void);  // 0x00285760: definition moved into src/anon/unit_002853b8.cpp

// 00290098
union HeapRef { u8* p; u32 w; };
extern HeapRef D_00347f80;
extern u8 D_00347e60[];
void func_00239700(void*);
void func_0028dfe8(void*);  // obj_ctor_36f440
void func_00258d58(u32, u32, u32);
typedef u8* (*AllocFn)(void*, u32, u32);
static inline u8* HeapAlloc(u32 n) { VObj* al = *(VObj**)(D_00347f80.p + 20); return ((AllocFn)al->vt[0])(al, n, 0); }
struct Pair290 { u8* a; u8* b; u16 v[3]; u16 pad; u32 x; };
void func_00290098(Pair290* self, u32 a1, u32 a2, u32 a3, u16* src);  // 00290098: moved to src/anon/unit_0028f1e0.cpp

// 00291288
void func_00291288(u8* self);  // 00291288: moved to src/anon/unit_00290f78.cpp

// 0029e170
u8* func_002766d0(void);
void func_0028d8c0(void*, void*, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(void*, void*);
void func_00138cb8(void*, s32*, s32*);
void func_00138c68(void*, s32, s32);
extern u8* D_0035f3d4;
extern u32 D_0035f148;
extern u32 D_0035f14c;
extern u32 D_0035f210;
void func_0029e170(s32 a0);  // 0x0029e170: definition moved into src/anon/unit_0029d008.cpp

// 002aa148 / 002aa378 / 002ab368: test unlock bits against the "available" mask.
struct Flags { u8 pad[136]; u32 a136[41]; u32 a300[4]; u32 a316[8]; };
Flags* func_002a9d68(void);
s32 func_002a9f50(s32);
u8* func_00294000(s32);
s32 func_002ab180(s32);
extern Flags* D_0035f610;
static inline u32 Bit(u32* a, u32 i) { return a[i >> 5] & (1 << (i & 31)); }
s32 func_002aa148(s32 id);  // 0x002aa148: definition moved into src/anon/unit_002a99c8.cpp

s32 func_002aa378(s32 id);  // 0x002aa378: definition moved into src/anon/unit_002a99c8.cpp

s32 func_002ab368(s32 id);  // 0x002ab368: definition moved into src/anon/unit_002a99c8.cpp

// 002d5e50
void func_002d00a0(void*);
s32 func_00181500(s32);
u32 func_002d1260(void);
void func_001c0d38(void*, u32, s32, s32);
u8* func_002d1878(void*);
void func_002e7340(void*, void*, s32, void*, f32, f32);
extern u8 D_00362380[];
extern u8 D_00362388[];
union PtrWord { void* p; u32 w; };
extern PtrWord D_00361f60;
void func_002d5e50(u8* self);  // 0x002d5e50: definition moved into src/anon/unit_002d4548.cpp

// 002ed738
s32 func_00190140(void*);
f32 func_001906f0(void*, void*);
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
void func_002ed630(void*);
void func_002ed720(void*);
u32 func_002ed830(void*);
void func_002ed8c0(void);
struct Fx { u32 pos[4]; u32 cb; u8 cur; u8 pad[63]; u8 src; u8 pad2[3]; f32 t; u8 pad3[8]; u8 trk[20]; struct { u32 on : 1; } fl; };
u32 u_call4_002ed738(Fx* self, u32, u32, u32) asm("_Z16u_call4_002ed738jjjj");
u32 u_call4_002ed738(Fx* self, u32, u32, u32)
{
    self->cur = self->src;
    if (self->fl.on) {
        if (func_00190140(self->trk)) {
            u32 tmp[4] __attribute__((aligned(16)));
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(self->pos) : "$8", "memory");
            if (func_003142e0(func_00313b80(func_001906f0(self->trk, tmp)), 30.0) < 0) self->fl.on = 0;
        } else {
            self->fl.on = 0;
        }
    }
    func_002ed630(self);
    func_002ed720(self);
    if (func_003142e0(func_00313b80(self->t), 0.0) <= 0) {  // double_compare
        self->t = 8.0f;
        self->cb = (u32)func_002ed8c0;
        return func_002ed830(self);
    }
    return 1;
}

// 00322228: destructor body (member arrays destroyed back to front, then the base part).
struct NoTail2 { ~NoTail2() {} };
extern u8 D_0035e1b8[];
extern u8 D_00347f98[];
void func_00239870(void*);
void func_0031a840(void*);
void func_00322228(u8* self)
{
    NoTail2 g;
    u8* m = self + 2560;
    *(void**)self = D_0035e1b8;
    *(void**)m = D_00347e60;
    func_00239870(m + 24);
    *(void**)m = D_00347f98;
    if (self + 864) {
        u8* p = m;
    l1:
        if (self + 864 == p) goto d1;
        p -= 848;
        ((VoidFn)((VObj*)p)->vt[3])(p);
        goto l1;
    }
d1:
    if (self + 440) {
        u8* p = self + 440 + 412;
    l2:
        if (self + 440 == p) goto d2;
        p -= 412;
        ((VoidFn)((VObj*)p)->vt[3])(p);
        goto l2;
    }
d2:
    *(void**)self = D_00347e60;
    func_00239870(self + 24);
    func_0031a840(self);
}

}

// 002b3fb0: release the three owned objects (the middle one is an array).
typedef void (*FreeFn)(void*, void*);
class W90Part {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual ~W90Part();
    u8 body[72];
    static void operator delete[](void* p) { VObj* al = *(VObj**)(D_00347f80.p + 20); ((FreeFn)al->vt[1])(al, p); }
};
class W90Res {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual ~W90Res();
};
struct W90Owner { W90Res* a; W90Part* parts; W90Res* c; };
extern "C" {
void func_002b3fb0(W90Owner* self);  // 0x002b3fb0: definition moved into src/anon/unit_002b3ac8.cpp
}

struct FV {
    f32 x, y, z, w;
    FV() {}
    FV& operator=(const FV& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline FV Sub(const FV* a, const FV* b)
{
    FV r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(a), "r"(b) : "memory");
    return r;
}
static inline void Cross(FV* d, const FV* a, const FV* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void Normalize(FV* v)
{
    asm volatile(
        "lqc2 $vf1, 0(%0)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, $f1\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%0)"
        : : "r"(v) : "$8", "$f1", "memory");
}
static inline f32 Dot(const FV* a, const FV* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
struct M44 { FV r[4]; };
static inline FV MulMV(const M44* m, const FV* v)
{
    FV out;
    asm volatile(
        "lqc2 $vf5, 0(%1)\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\t"
        "vmadday.wxyz ACC, $vf2, $vf5y\n\t"
        "vmaddaz.wxyz ACC, $vf3, $vf5z\n\t"
        "vmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&out), "r"(v), "r"(m) : "memory");
    return out;
}
struct PtrList { FV* p[4]; s32 n; };
extern "C" {

// 00163650: plane (normal, -d) through three points.
void func_00163650(f32* out, FV* p0, FV* p1, FV* p2)
{
    FV e1, e2, n;
    e1 = Sub(p1, p0);
    e2 = Sub(p2, p0);
    Cross(&n, &e1, &e2);
    Normalize(&n);
    out[0] = n.x;
    out[1] = n.y;
    out[2] = n.z;
    out[3] = -Dot(&n, p0);
}

// 001423c0: fetch a target point list, optionally transformed by the object matrix.

void func_00141988(void*, void*, PtrList*);  // collect_entry_ptrs_by_halves
u32 wtarget_001423c0(u8* self, u32 a1, FV* out, u32) asm("_Z16wtarget_001423c0jjjj");
u32 wtarget_001423c0(u8* self, u32 a1, FV* out, u32);  // 0x001423c0: definition moved into src/anon/unit_00141458.cpp
}
