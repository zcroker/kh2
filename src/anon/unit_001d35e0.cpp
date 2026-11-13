#include "unit_001d35e0.hpp"

// 0x1d35e0-0x1d3c08: background-hit queries (line test, surface normal and attribute) and the
// attractor fields (ATTRACT) that pull objects, kept in a file-wide list. VU0 macro code and
// 128-bit lq/sq copies are inline asm, as in the original.

typedef ATTRACT_VEC VEC;

struct LINE { VEC a, b; };
struct BGHIT { u8 pad[16]; s32 hit; s32 id; };

extern "C" {
s32 func_00143b88(LINE*, BGHIT*, u16*, s32*, u32);
s32 func_00143ae0(LINE*, BGHIT*, u16*);
void func_00143e50(void*, u32, u32);
void func_001422a0(void*, u32, u32);
u32* func_00142398(u32, u32);
u32 func_00143f28(u32, u32);
s32 func_0019bb98(u8*);
s32 func_0016a040(u8*);
VEC* func_0016c028(u8*);
f32 func_0016a0a0(u8*);
void func_0017d538(f32, VEC*, VEC*);
void* func_001050d8(u32);
void func_00105110(void*);
extern f32 D_00349e10;
}

static LIST<ATTRACT> D_01d5ba20;

extern "C" {

// Line test from a to b (w forced to 1); fills o->hit / o->id. Returns whether something was hit.
s32 func_001d35e0(BGHIT* o, const VEC& a, const VEC& b, u32 flags) {
    LINE l; u16 id; VEC* pb = &l.b;
    l.a = a; *pb = b; l.a.w = 1.0f; pb->w = 1.0f;
    o->id = -1;
    s32 r;
    if (flags & 0x10000) {
        asm("" : "+r"(flags));
        u32 f = flags & 0xffff;
        asm("" : "+r"(f));
        s32* hit = &o->hit;
        r = func_00143b88(&l, o, &id, hit, f);
    } else {
        o->hit = 0;
        r = func_00143ae0(&l, o, &id);
    }
    if (r) o->id = id;
    return o->id != -1;
}

}

void* BGHIT_get_normal(void* a0, u8* a1) asm("_ZN2YS5BGHIT10get_normalEv");
void* BGHIT_get_normal(void* a0, u8* a1) {
    u32 t7 = *(u32*)(a1 + 16);
    void* s0 = a0;
    if (t7 == 0) {
        u32 a5 = *(u16*)(a1 + 20);
        func_00143e50(s0, a5, 0);
        return s0;
    }
    u32 a6 = *(u16*)(a1 + 20);
    u32 a5 = *(u32*)(t7 + 4);
    func_001422a0(s0, a5, a6);
    return s0;
}

extern "C" u32 func_001d36e8(u8* a0) {
    u32 t7 = *(u32*)(a0 + 16);
    if (t7 != 0) {
        u32 a5 = *(u16*)(a0 + 20);
        u32* v0 = func_00142398(*(u32*)(t7 + 4), a5);
        u32 v = *v0;
        return v & 0xF;
    }
    u32 a4 = *(u16*)(a0 + 20);
    return func_00143f28(a4, 0);
}

inline void* ATTRACT::operator new(u32 n) { return func_001050d8(n); }
inline void ATTRACT::operator delete(void* p) { func_00105110(p); }

ATTRACT::ATTRACT(const VEC& p, f32 pw) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&pos), "r"(&p) : "$8", "memory");
    mask = 0; range = 0; power = pw; min = pw; max = pw; swirl = 0; center = 100.0f; falloff = 0.01f;
    D_01d5ba20.Append(this);
}

ATTRACT::~ATTRACT() {
    D_01d5ba20.Remove(this);
}

static inline void VSub(VEC* d, const VEC* a, const VEC* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void VAdd(VEC* d, const VEC* a, const VEC* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void VScale(VEC* d, const VEC* a, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "f"(k) : "$8", "memory");
}
static inline f32 VNormalize(VEC* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

extern "C" {

// Adds this field's pull on object t to vel.
void func_001d38a0(ATTRACT* f, VEC* vel, u8* t) {
    if (func_0019bb98(t)) return;
    if (f->mask & (1 << func_0016a040(t))) return;
    VEC d, b, a;
    VSub(&d, &f->pos, func_0016c028(t));
    d.y = 0.0f;
    d.w = VNormalize(&d);
    if (f->range != 0.0f && f->range <= d.w) return;
    f32 s = f->power * (func_0016a0a0(t) / 100.0f);
    s = s < f->min ? f->min : (f->max < s ? f->max : s);
    f32 k = (d.w - f->center) * f->falloff;
    if (k < -1.0f) k = -1.0f;
    else if (1.0f < k) k = 1.0f;
    VScale(&a, &d, s);
    VScale(&b, &a, k);
    VAdd(vel, vel, &b);
    if (f->swirl == 0.0f) return;
    func_0017d538(1.5707964f, &b, &d);
    d = b;
    VScale(&b, &d, f->swirl);
    VAdd(vel, vel, &b);
}

static inline ATTRACT* NextAttract(ATTRACT* n) { if (!n) return D_01d5ba20.head; return n->next; }

// The sum of every field's pull on object b, per frame.
VEC* func_001d3ac0(VEC* out, u8* b) {
    VEC acc;
    acc.w = acc.z = acc.y = acc.x = 0.0f;
    ATTRACT* n = 0;
    while ((n = NextAttract(n))) func_001d38a0(n, &acc, b);
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(out), "r"(&acc), "f"(D_00349e10) : "$8", "memory");
    return out;
}

}

void func_001d3b60(void*) {}

void u_call0_001d3b68(void) asm("_Z16u_call0_001d3b68v");
void u_call0_001d3b68(void) {
    ATTRACT* n = D_01d5ba20.head;
    while (n != 0) {
        ATTRACT* next = n->next;
        delete n;
        n = next;
    }
}
