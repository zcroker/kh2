#include "../common/types.h"

// 128-bit copy (lq/sq through t0).
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// Same, kept out of the assembler's delay-slot filling.
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte aligned vector: copy-construct = quadword copy, assignment skips self.
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPYN(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

struct Mtx {
    Vec4 r[4];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// Random float in [0,1) from the VU0 R register.
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}

// Squared distance of two points (xyz) on VU0.
static inline f32 vu0DistSq(const void* a, const void* b) {
    f32 d;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.xyzw $vf5, $vf6, $vf4\n\tvmove.xyzw $vf4, $vf5\n\t"
                 "vmul.xyz $vf5, $vf4, $vf5\n\tvaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0"
                 : "=f"(d) : "r"(a), "r"(b) : "$2");
    return d;
}

typedef void (*VFn)(void*);

extern "C" {

void func_0017c4c8(void*, Vec4);
void func_0017f488(void*, s32, f32, f32);

static inline bool stateIsOne(u8* c) { return *(s32*)(c + 4) == 1; }

// 0010c940
void func_0010c940(u8* p, s32 n, f32 t)
{
    u8* c = *(u8**)(p + 12);
    if (c && stateIsOne(c)) return;
    f32 m = *(f32*)(p + 280);
    if (m < t) t = m;
    Vec4 v;
    v = *(Vec4*)(p + 16);
    v.y = t;
    func_0017c4c8(p, v);
    func_0017f488(p + 320, n, 0.0f, 0.0f);
    *(s32*)(p + 256) = n + 1;
    *(s32*)(p + 260) = n + 2;
    *(u32*)(p + 264) |= 0x10000;
}

// 00124b10: obj->matrix = m * obj->matrix (VU0)
void func_00124b10(u8* p, Mtx* m)
{
    Mtx* d = *(Mtx**)(p + 4);
    Mtx t;
    asm volatile(".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
        : : "r"(&t), "r"(m), "r"(d) : "memory");
    *d = t;
}

s16* func_001aec40(void*);
void func_002b9ab8(s32);
void func_002bc458(s32);
void func_001369d0(void);
void func_001369f0(void);
void func_002b9ed0(void);
void func_00136a60(void);
void func_001363a0(void*);
void func_00136560(void*);
extern u8 D_0032bae0;
extern u32 D_00347d20;

// 001366b8
void func_001366b8(void* a)
{
    s16* r = func_001aec40(a);
    if (!r) return;
    if (r[0] == -1) func_002b9ab8(20);
    else func_002b9ab8(r[0]);
    func_002bc458(r[1]);
    if (D_0032bae0 != D_00347d20) {
        func_001369d0();
        func_001369f0();
        D_00347d20 = D_0032bae0;
        func_002b9ed0();
    }
    func_00136a60();
    func_001363a0(a);
    func_00136560(a);
}

s32 func_00165db8(s32, s32, s32*, s32, s32, s32, s32*, s32, s32);
void func_00141c18(u32, s32, s32, s32, s32);
s32 func_00141ff0(u32, s32, s32, s32*, s32);
extern u32 D_00348804;

// 00143c68
s32 func_00143c68(s32 a, s32 b)
{
    s32 x, y;
    y = 0;
    s32 r = func_00165db8(a, b, &x, 512, 512, 0, &y, 15, 0);
    func_00141c18(D_00348804, 512, 512, 0, 0);
    r |= func_00141ff0(D_00348804, a, b, &x, 15);
    return r != 0;
}

struct Sphere { Vec4 c; f32 r; };
struct PointList { Vec4* v[4]; s32 n; };

// 00163168: the list point nearest to the sphere centre, if inside it
s32 func_00163168(Sphere* s, PointList* l, Vec4* out)
{
    f32 best = s->r * s->r;
    s32 idx = 4;
    for (s32 i = 0; i < l->n; i++) {
        f32 d = vu0DistSq(s, l->v[i]);
        if (d <= best) { best = d; idx = i; }
    }
    if (idx != 4) {
        *out = *l->v[idx];
        return 1;
    }
    return 0;
}

// 001ef398: random float, averaged with a second one when asked
f32 func_001ef398(u8 a)
{
    f32 x = vu0Rand();
    if (a) x = (x + vu0Rand()) * 0.5f;
    return x;
}

// 001ef5a0: negative random float, averaged with a second one when asked
f32 func_001ef5a0(u8 a)
{
    f32 x = vu0Rand();
    x = -x;
    if (a) x = (x - vu0Rand()) * 0.5f;
    return x;
}

s32 func_0016c028(void*);
void func_002bc188(s32, s32);

// 00198580
void func_00198580(u8* o, s32 id)
{
    u8* q = 0;
    if (id / 1000 == 500) {
        u32 fl = *(u32*)(o + 1416);
        if (fl & 0x40) q = o;
        else if (fl & 4) q = *(u8**)(o + 2808);
        if (q) {
            s16* e = *(s16**)(q + 2484);
            s32 k = e ? e[1] : -1;
            if (k >= 0) id = id % 1000 + k * 1000;
        }
    }
    func_002bc188(id, func_0016c028(o));
}

extern f32 D_00349e10;
Vec4 func_00184540(u8*, f32, f32);

// 001b2170
Vec4 func_001b2170(void* self, u8* o)
{
    f32 y0 = *(f32*)(o + 36);
    Vec4 r;
    r = func_00184540(o, *(f32*)(o + 240), *(f32*)(o + 240));
    f32 v = y0 + *(f32*)(o + 244) * D_00349e10;
    f32 m = *(f32*)(o + 288);
    f32 c;
    if (v < m) c = v; else c = m;
    *(f32*)(o + 36) = c;
    r.y = c * D_00349e10;
    return r;
}

s32 func_001818e8(void*);
s32 func_001bd590(void*);
s32 func_001bdb10(void*, s32);
void func_001bc720(u32);

// 001be410
void func_001be410(u8* o)
{
    if (!func_001818e8(o)) return;
    if ((**(u64**)(o + 2532) & 0x800000) && !func_001bd590(o)) {
        if (func_001bdb10(o, 5)) *(u32*)(o + 32) |= 2;
    } else if (func_001bdb10(o, *(s32*)(o + 2724))) {
        func_001bc720(**(u32**)(o + 2240));
        *(u32*)(o + 32) &= ~2;
    }
}

s32 func_001818a0(void*);
s32 func_00177870(void*);
void func_001bc780(void*, s32, s32, s32);

// 001be540
void func_001be540(u8* o, void* x)
{
    if (!func_001818a0(o)) { func_001bc780(x, 104, 0, 1); return; }
    if (D_0032bae0 == 9) { func_001bc780(x, 136, 0, 1); return; }
    u8* t = *(u8**)(o + 2528);
    if (*(s32*)(t + 2896) == 2) { func_001bc780(x, 365, 0, 1); return; }
    if (func_00177870(t)) func_001bc780(x, 541, 0, 1);
    else func_001bc780(x, 1, 0, 1);
}

s32 func_00242dc8(u32);
extern u32 D_01d49970[];

// 001c8788: test-and-set of a flag bit
s32 func_001c8788(u32 id, u8* o)
{
    if (*(u32*)(o + 2064)) return 0;
    s32 r = 0;
    switch (func_00242dc8(id)) {
    case 1: r = 1; break;
    case 2: r = (D_01d49970[id >> 5] & (1 << (id & 31))) == 0; break;
    }
    if (r) D_01d49970[id >> 5] |= 1 << (id & 31);
    return r;
}

extern void* D_0035ed70;
extern void* D_0035ed74;
s32 func_002892f8(void*);
s32 func_0028acc8(void*);
void func_00288e88(void*);

// 0024ab00
void func_0024ab00(void)
{
    if (D_0035ed70) {
        s32 a = func_002892f8(D_0035ed70);
        if (!func_0028acc8(D_0035ed70) && a) func_00288e88(D_0035ed70);
    }
    if (D_0035ed74) {
        s32 a = func_002892f8(D_0035ed74);
        if (!func_0028acc8(D_0035ed74) && a) func_00288e88(D_0035ed74);
    }
}

void* func_00257770(void);
s32 func_00287bc0(void);
s32 func_002570a0(s32);
s32 func_00272b60(s32);
void func_0028dac8(void*, s32);
s32 func_0028be58(u32);
void func_0028bdb8(u32);
struct Entry373 { s16 a; s16 b; s16 c; };
extern Entry373 D_00373a30[];
extern u32 D_0035f04c;

// 00272340
void func_00272340(void)
{
    void* s = func_00257770();
    u32 m = func_00287bc0() - 26;
    if (m < 8) {
        s32 v;
        if (m < 2) v = 229;
        else v = D_00373a30[func_00272b60(func_002570a0(26))].b;
        func_0028dac8(s, v);
        if (func_0028be58(D_0035f04c)) func_0028bdb8(D_0035f04c);
    }
}

s32 func_00103570(void);
u8* func_001063c0(s32, s32);
void func_00239700(u8*);
extern u8* D_0035f608;
extern u8* D_0035f60c;
extern u8 D_00347e60[];
extern u8 D_00347e40[];

// 002a8948: allocate the work buffers (ten 436-byte objects)
void func_002a8948(void)
{
    D_0035f608 = func_001063c0(772, func_00103570());
    u8* arr = func_001063c0(4360, func_00103570());
    u8* p = arr;
    s32 i = 9;
    do {
        *(u32*)(p + 12) = 0;
        *(u8**)p = D_00347e60;
        func_00239700(p + 24);
        *(u8**)p = D_00347e40;
        *(u32*)(p + 408) = 0;
        p += 436;
    } while (--i != -1);
    D_0035f60c = arr;
}

f32 func_002faaf0(f32, f32);
f32 func_002fb460(f32, f32, s32);
s32 func_002fa678(f32, f32*);
union FloatWord { f32 f; s32 i; };

// 002f87c0: cosf (fdlibm, without the inf/nan check)
f32 func_002f87c0(f32 x)
{
    f32 y[2];
    FloatWord u;
    u.f = x;
    s32 ix = u.i & 0x7fffffff;
    if (ix <= 0x3f490fd8) return func_002faaf0(x, 0.0f);
    s32 n = func_002fa678(x, y);
    switch (n & 3) {
    case 0: return func_002faaf0(y[0], y[1]);
    case 1: return -func_002fb460(y[0], y[1], 1);
    case 2: return -func_002faaf0(y[0], y[1]);
    default: return func_002fb460(y[0], y[1], 1);
    }
}

}

extern "C" {
extern void* D_0034a434;
extern void* D_0034a430;
extern void* D_0034a42c;
extern void* D_0034a428;
}
#define RELEASE_GLOBAL(g) if (g) { (*(VFn*)(*(u8**)g + 16))(g); g = 0; }
// 0014f428: release four global objects
void func_0014f428(void*)
{
    RELEASE_GLOBAL(D_0034a434);
    RELEASE_GLOBAL(D_0034a430);
    RELEASE_GLOBAL(D_0034a42c);
    RELEASE_GLOBAL(D_0034a428);
}

// 00281c50: Tz CmItem LeavePopup
extern "C" {
s32 func_00139d78(void*);
extern u32 D_0035f274;
extern u8 D_0035f299;
extern void* D_0035f28c;
extern void* D_0035f290;
extern s16 D_0035f280;
extern u32 D_0035f294;
extern u8 D_0035f298;
void cmItemLeavePopup(void) asm("_ZN2Tz6CmItem10LeavePopupEv");
}
void cmItemLeavePopup(void)
{
    if (!D_0035f274 && D_0035f299) {
        if (func_00139d78(D_0035f28c)) (*(VFn*)(*(u8**)D_0035f28c + 20))(D_0035f28c);
    }
    if (func_00139d78(D_0035f290)) (*(VFn*)(*(u8**)D_0035f290 + 20))(D_0035f290);
    D_0035f280 = -1;
    D_0035f294 = 0;
    D_0035f298 = 0;
}

extern "C" {

// Word accessed through a union: aliases everything, as the original assumes.
union Word { f32 f; u32 u; };
// Global accessed through a union with a byte member: not assumed distinct
// from struct fields.
union GWord { s32 v; u8 c; };
typedef void (*VFn2)(void*, void*);

extern u8 D_00361e38[];
extern u8* D_00361e28;
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8* D_00347f80;
void func_002c1750(u8*);
void func_00239870(u8*);
void func_0023c098(u8*);
void func_002369f0(u8*);

// 002ca320: destructor
void func_002ca320(u8* o)
{
    *(u8**)o = D_00361e38;
    D_00361e28 = D_00361e28 == o ? 0 : D_00361e28;
    func_002c1750(o);
    *(u8**)(o + 192) = D_00347e60;
    func_00239870(o + 216);
    *(u8**)(o + 192) = D_00347f98;
    *(u8**)(o + 28) = D_0035eb98;
    func_0023c098(o + 76);
    func_002369f0(o + 52);
    *(u8**)(o + 28) = D_00347f98;
    *(u8**)o = D_00347f98;
    u8* m = *(u8**)(D_00347f80 + 20);
    (*(VFn2*)(*(u8**)m + 4))(m, o);
}

u32* func_002859a0(void);
u8* func_001a8110(u8*);
s32 func_00286058(u8);
s32 func_001a3570(u16);
extern u32* D_0035f2e4;

}
// 00285fa0
void u_call0_00285fa0(void)
{
    u8* e = 0;
    u32* bits = func_002859a0();
    for (;;) {
        e = func_001a8110(e);
        if (!e) break;
        if (!func_00286058(e[2])) continue;
        if (!func_001a3570(*(u16*)e)) continue;
        u16 id = *(u16*)e;
        u32 m = 1 << (id & 31);
        u32 off = id >> 5;
        if (bits[off] & m) continue;
        u32* d = D_0035f2e4;
        d += off;
        *d |= m;
    }
}
extern "C" {

struct BitInfo { u32 a, b; s32 n; };
u32* func_002a9d68(void);
void func_00294020(u32*);
BitInfo* func_00294000(s32);
union PtrWord { u32* p; u32 u; };
extern PtrWord D_0035f610;

// 002a9df0: clear the bits that are also set in the other set
void func_002a9df0(void)
{
    u32* other = func_002a9d68();
    func_00294020(D_0035f610.p);
    BitInfo* v = func_00294000(3);
    for (s32 i = 0; i < v->n; i++) {
        u32* base = D_0035f610.p;
        u32 off = (u32)i >> 5;
        u32 m = 1 << (i & 31);
        u32 w = base[off];
        if ((w & m) && (other[off] & m)) base[off] = w & ~m;
    }
}

extern u32* D_0035f620;
extern GWord D_0035f628;
extern GWord D_0035f62c;

// 002ad110: count set bits
void func_002ad110(void)
{
    func_00294020(D_0035f620);
    BitInfo* v = func_00294000(3);
    D_0035f628.v += v->n;
    for (s32 i = 0; i < v->n; i++) {
        if (D_0035f620[(u32)i >> 5] & (1 << (i & 31))) D_0035f62c.v++;
    }
}

extern u8 D_0034ab80[];

// 0031da48: destructor (seven 344-byte members with virtual destructors)
void func_0031da48(u8* o)
{
    *(u8**)o = D_0034ab80;
    if (o + 440) {
        u8* p = o + 2848;
        for (;;) {
            if (o + 440 == p) break;
            p -= 344;
            (**(VFn**)p)(p);
        }
    }
    *(u8**)o = D_00347e60;
    func_00239870(o + 24);
    *(u8**)o = D_00347f98;
    u8* m = *(u8**)(D_00347f80 + 20);
    (*(VFn2*)(*(u8**)m + 4))(m, o);
}

extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
void func_00239848(u8*);
void func_001ac5b8(u8*);
void func_00105110(u8*);

// 0031f590: destructor (four 344-byte members with virtual destructors)
void func_0031f590(u8* o)
{
    *(u8**)o = D_00350bb0;
    if (o + 1544) {
        u8* p = o + 2920;
        for (;;) {
            if (o + 1544 == p) break;
            p -= 344;
            (**(VFn**)p)(p);
        }
    }
    func_00239870(o + 1200);
    func_00239870(o + 848);
    func_00239870(o + 484);
    *(u8**)(o + 132) = D_0034e8a8;
    func_00239848(o + 132);
    func_001ac5b8(o);
    func_00105110(o);
}

void func_002d0718(void*);
void func_0011b6a8(Mtx*);
void func_0011b720(Mtx*, f32);
void func_001449a8(void*, Mtx*);
s32 func_002cec08(void*, void*);

// 002cee58
s32 func_002cee58(void* a, u8* o)
{
    u8 buf[32] __attribute__((aligned(16)));
    func_002d0718(buf);
    Mtx m;
    func_0011b6a8(&m);
    func_0011b720(&m, *(f32*)(o + 20));
    Vec4 t;
    t.x = *(f32*)(o + 4);
    t.y = *(f32*)(o + 8);
    t.z = *(f32*)(o + 12);
    t.w = 0.0f;
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(&m), "r"(&t) : "memory");
    func_001449a8(buf, &m);
    return func_002cec08(a, buf) != 0;
}

Vec4 func_0016af58(u8*);
Vec4 func_002cba88(u32, s32, const Vec4&, f32, f32);
extern Vec4 D_01e2be20;

// 002e3540
void func_002e3540(u8** o)
{
    u8* s = *(u8**)(*o + 4);
    if (!*(u32*)(s + 1288)) return;
    s32 v = func_0016c028(s);
    D_01e2be20 = func_002cba88(*(u32*)(s + 1288), v, func_0016af58(s), *(f32*)(o + 1), 1.0f);
    *o = (u8*)&D_01e2be20;
}

s32 func_00253918(void);
s32 func_002537c8(s32);
void func_00236c38(u32);
void func_00236a58(u32, s32, s32);
void func_002805d0(void);
struct State280 { s32 v; s8 pad[2]; s8 b6; s8 b7; };
union StatePtr { State280* p; u8 c; };
extern StatePtr D_0035f260;
extern u32 D_0035f264;

// 00280528
void func_00280528(void)
{
    if (func_00253918()) return;
    if (D_0035f260.p->b7 < 0) return;
    D_0035f260.p->b7 = -1;
    D_0035f260.p->v = func_002537c8(6);
    if (D_0035f260.p->b6 >= 0) return;
    func_00236c38(D_0035f264);
    func_00236a58(D_0035f264, D_0035f260.p->v, func_00103570());
    func_002805d0();
}

void func_0010b978(void*);
void func_001e02a0(u8*, u8*);
void func_0010c7f0(void*);
extern u8 D_00351e18[];
extern u8* D_01d49960[2];

// 001c7f10: constructor; registers itself in a two-slot table
void func_001c7f10(u8* o)
{
    func_0010b978(o);
    *(u32*)o = (u32)D_00351e18;
    *(u32*)(o + 1416) |= 0x400000;
    *(u32*)(o + 1896) &= ~0x10;
    s32 i;
    for (i = 0; i < 2; i++) {
        if (!D_01d49960[i]) { D_01d49960[i] = o; break; }
    }
    if (i > 0) func_001e02a0(o + 128, D_01d49960[0] + 128);
    *(s32*)(o + 152) = 1;
    func_0010c7f0(o);
}

void func_002cfeb0(u8*, void*, s32, s32);
extern u8 D_00362b68[];

// 002dd9e0: constructor
void func_002dd9e0(u8* o, Word* p, s32 c)
{
    func_002cfeb0(o, p, 3, c);
    *(u8**)o = D_00362b68;
    *(f32*)(o + 2840) = 300.0f;
    switch (p->u) {
    case 1637: *(s32*)(o + 2836) = 1; break;
    case 1636: *(s32*)(o + 2836) = 2; break;
    case 1638: *(s32*)(o + 2836) = 0; break;
    case 1639: *(s32*)(o + 2836) = 3; break;
    }
}

extern s32 D_01e2bfb0;
extern u8 D_01e2bfc0[];
extern void* D_0034e948;
s32 func_0019ba60(void*);
void* func_0016bba8(void*, s32, void*);
void func_0018a818(u8*, void*, void*);

// 002e9248: collect the list entries into 32-byte records
void func_002e9248(void)
{
    void* x = 0;
    D_01e2bfb0 = 0;
    void* s = D_0034e948;
    if (!func_0019ba60(s)) return;
    while ((x = func_0016bba8(s, 4, x))) {
        func_0018a818(D_01e2bfc0 + D_01e2bfb0 * 32, s, x);
        D_01e2bfb0++;
    }
}

Vec4 func_0017c030(u8*, s32*, u8);

// 001c96c8
void func_001c96c8(void* a, u8* o, u8 f)
{
    s32 x;
    Vec4 v = func_0017c030(o, &x, f);
    if (*(u32*)(o + 268) & 0x10) {
        v.w = *(f32*)(*(u8**)(o + 300) + 36);
        func_0017c4c8(o, v);
        o[1300] = 5;
    } else {
        func_0017c4c8(o, v);
    }
    func_0017f488(o + 320, x, 0.0f, 0.0f);
    *(s32*)(o + 256) = 4;
    *(s32*)(o + 260) = 5;
}

s32 func_002282f0(s16);
void func_0014a768(u8);
void func_0014a788(u16, u16);
f32 func_00227c78(u8*);
void func_0014a7b8(s16, f32);
void func_0014a7e8(s32);
void func_0014a7f8(s32);

// 0022cd48
void func_0022cd48(u8* o)
{
    if (func_002282f0(*(s16*)(o + 4))) return;
    s32 a;
    if (!o[6]) {
        func_0014a768(o[7]);
        func_0014a788(*(s16*)(o + 12) >> 1, *(s16*)(o + 14) >> 1);
        if (func_00227c78(o + 8) != 0.0f) func_0014a7b8(*(s16*)(o + 16), func_00227c78(o + 8));
        func_0014a7e8(1);
        a = 1;
    } else a = 0;
    func_0014a7f8(a);
}

}
