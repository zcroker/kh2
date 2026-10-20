#include "../common/types.h"
// 002815d8
// 002815d8: -fno-strict-aliasing; reading D_0035f288 back for D_0035f28c gives the original store order.
extern "C" {
struct W1825Heap;
struct W1825HeapVt { u8* (*alloc)(W1825Heap*, s32, s32); };
struct W1825Heap { W1825HeapVt* vt; };
struct W1825Sys { u8 pad[20]; W1825Heap* heap; };
union W1825SysU { W1825Sys* s; u8* p; };
extern u8* D_00347f80;
#define SYS ((W1825Sys*)D_00347f80)
extern u8 D_00347e60[];
extern u8* D_0035f288;
extern u8* D_0035f28c;
extern u8* D_0035f290;
extern u8* D_0035f29c;
extern s16 D_0035f280;
extern s8 D_0035f299;
extern s32 D_0035f274;
extern s32 D_0035f270;
extern s32 D_0035f278;
extern s32 D_0035f27c;
extern s32 D_0035f284;
void func_00239700(u8*);
u32 func_00103570();
u8* func_001063c0(s32, u32);
void func_002361a0(u8*);
void func_002817b8();
static inline __attribute__((always_inline)) u8* w1825_mk() {
    u8* a = SYS->heap->vt->alloc(SYS->heap, 408, 0);
    *(u8**)a = D_00347e60;
    *(u32*)(a + 12) = 0;
    func_00239700(a + 24);
    return a;
}
void func_002815d8(void)
{
    u8* a; u8* c;
    D_0035f288 = w1825_mk();
    D_0035f28c = D_0035f288;
    D_0035f290 = w1825_mk();
    c = func_001063c0(416, func_00103570());
    func_002361a0(c);
    D_0035f29c = c;
    D_0035f280 = D_0035f27c = D_0035f278 = D_0035f270 = D_0035f274 = -1;
    D_0035f299 = 1;
    D_0035f284 = 0;
    func_002817b8();
}
}

// 002cb938
struct W1825QV {
    f32 x, y, z, w;
    W1825QV operator*(f32 s) const {
        W1825QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    W1825QV operator+(const W1825QV& b) const {
        W1825QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1825Hermite { u8 pad[48]; W1825QV p0; W1825QV m0; W1825QV p1; W1825QV m1; };
static inline W1825QV w1825_hermite(const W1825QV& p0, const W1825QV& m0, const W1825QV& p1, const W1825QV& m1, f32 s)
{
    f32 s2 = s * s;
    f32 s3 = s2 * s;
    f32 h00 = 2.0f * s3 - 3.0f * s2 + 1.0f;
    f32 h01 = -2.0f * s3 + 3.0f * s2;
    f32 h10 = s3 - 2.0f * s2 + s;
    f32 h11 = s3 - s2;
    return p0 * h00 + p1 * h01 + m0 * h10 + m1 * h11;
}
extern "C" {
W1825QV func_002cb938(f32 t, W1825Hermite* c)
{
    W1825QV r = w1825_hermite(c->p0, c->m0, c->p1, c->m1, t - c->m0.w);
    r.w = 1.0f;
    return r;
}
}

// 00186ec0
struct W1825Flags {
    u32 a, b, c;
    u32 get() { return (a | b) & ~c; }
};
struct W1825Obj {
    u8 pad0[352]; u32 f352;
    u8 pad1[1416 - 356]; u32 f1416;
    u8 pad2[2748 - 1420]; W1825Flags flags;
    u32 fl() { W1825Flags* f = &flags; return (flags.a | f->b) & ~f->c; }
};
struct W1825Oth { u8 pad0[16]; W1825Obj* owner; u8 pad1[37 - 20]; u8 b37; u8 b38; };
extern "C" {
s32 func_0018cae0(W1825Oth*);
s32 func_00186ec0(W1825Obj* o, W1825Oth* p)
{
    u32 m = o->fl();
    if (m & 0x200) return 1;
    if (m & 0x400) {
        if ((m & 0x80000) || !p->b37) {
            if (!func_0018cae0(p)) return 1;
        }
    }
    if ((o->fl() & 0x800) || p->b37) {
        if (!func_0018cae0(p) && !(p->owner->f1416 & 0x80)) return 1;
    }
    if (!(o->f1416 & 0x80)) return 0;
    if ((o->f352 & 0x4000) && !p->b38) return 1;
    return 0;
}
}

// 001cd690
struct W1825Slot { u32 val; void* obj; };
extern "C" {
s32 func_0019ba60(void*);
}
static inline bool w1825_dead(void* p)
{
    bool r = 0;
    if (!p || !func_0019ba60(p)) r = 1;
    return r;
}
extern "C" {
void func_001cd690(W1825Slot* s, u32 val, void* obj)
{
    W1825Slot* e;
    s32 i;
    W1825Slot* found;
    for (i = 7, e = s; i >= 0; i--, e++) {
        if (!w1825_dead(e->obj)) {
            if (!func_0019ba60(e->obj)) e->obj = 0;
        }
    }
    if (!func_0019ba60(obj)) return;
    found = 0;
    for (i = 0; i < 8; i++) {
        if (s[i].obj == obj) { found = &s[i]; break; }
        if (w1825_dead(s[i].obj)) found = &s[i];
    }
    found->val = val;
    found->obj = obj;
}
}

// 001871c8
#define W1825QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1825V {
    f32 x, y, z, w;
    W1825V() {}
    W1825V(const W1825V& o) { W1825QCOPY(this, &o); }
    W1825V& operator=(const W1825V& o) { if (this != &o) W1825QCOPY(this, &o); return *this; }
    W1825V operator+(const W1825V& b) const {
        W1825V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1825V operator-(const W1825V& b) const {
        W1825V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1825Act { u8 pad[1376]; W1825V pos; };
struct W1825Tgt { W1825Act* owner; };
extern "C" {
s32 func_00187300(W1825Act*, W1825Tgt*, f32);
s32 func_00190180(W1825Tgt*);
W1825V func_00190388(W1825Tgt*);
W1825V* func_0016c028(W1825Act*);
void func_0016b010(W1825Act*, W1825V);
s32 u_call4_001871c8(W1825Act* o, W1825Tgt* t, f32 r) asm("_Z16u_call4_001871c8jjjj");
s32 u_call4_001871c8(W1825Act* o, W1825Tgt* t, f32 r)
{
    s32 res;
    if (0.0f < r) {
        res = func_00187300(o, t, r);
    } else if (!func_00190180(t)) {
        res = 0;
    } else {
        if (t->owner != o) {
            W1825V d;
            d = func_00190388(t) - (*func_0016c028(o) + o->pos);
            d.y = 0.0f;
            if (50.0f < d.length()) func_0016b010(o, d);
        }
        res = 1;
    }
    return res;
}
}
