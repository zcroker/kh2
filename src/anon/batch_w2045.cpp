#include "../common/types.h"

// ---- shared declarations ----
extern "C" {
s32 func_001818e8();
u8* func_001b8e88(u16);
void func_001bc720(void*);
void func_001bc730(u8*, s32);
void func_001bcc28(u8*);
s32 func_001bcd08(u8*);
void func_001bce00(u8*);
s32 func_001bcf18(void*);
s32 func_001bcf38(void*);
void func_001bd5b0(void*, s32, s32);
void func_001bd618(void*, s32);
void func_001bd988(void*);
void func_002ba2e8(s32, s32);
}
struct W2045_S2240 { u8 pad[2240]; void** sp; };
struct W2045_Elem { u8 a[2]; u16 id; u8 b; u8 kind; u8 c[6]; };
struct W2045_Menu { u8 pad[4]; u8* o; s32 n; W2045_Elem e[8]; };
static inline bool w2045_entry_busy(void* e) {
    bool b = false;
    if (func_001bcf18(e) || func_001bcf38(e)) b = true;
    return b;
}
static inline bool w2045_kind_ok(W2045_Elem* e) { return e->kind < 4; }

struct W2045_M44 {
    f32 m[16];
    W2045_M44() {}
    // lq/sq 64-byte copy (VU0 matrix copy)
    W2045_M44& operator=(const W2045_M44& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2045_V4 { f32 v[4]; } __attribute__((aligned(16)));
struct W2045_Obj { u8 pad[8]; s32 flags; u8 pad2[16]; s32 h; u8 pad3[8]; W2045_Obj* next; };
struct W2045_Arg1 { u8 pad[16]; W2045_M44 m; };
extern "C" {
W2045_M44* func_00106ad0(s32);
void func_00107368(W2045_Arg1*, W2045_V4*);
void func_00107478(W2045_Arg1*, W2045_V4*);
void func_00143f78(void*, W2045_V4*);
void func_00146680(void*, W2045_M44*);
void func_001b81e8(void);
void func_001b8218(void);
s32 func_001dc738(W2045_Obj*);
s32 func_001dc790(W2045_Obj*);
s32 func_001dc9d0(W2045_Obj*);
s32 func_001dc9e0(W2045_Obj*);
void func_001dca70(W2045_Obj*);
void func_001dcae0(W2045_Obj*);
s32 func_001dcc60(W2045_Obj*);
s32 func_001dccc8(W2045_Obj*, u8);
void func_001e2c70(s32, s32);
void func_001e3330(s32);
void func_001e6250(void);
s32 func_001e6280(s32, s32);
void func_001e65c8(void);
void func_001e6c00(s32);
void func_001e6ed8(W2045_M44*, s32, W2045_V4*, W2045_V4*);
void func_001e7008(f32);
extern f32 D_00349e10;
extern W2045_Obj* D_00352ae0;
extern u8 D_00352b00[];
}
static inline bool w2045_flag26(W2045_Obj* o) { u8 b = (o->flags >> 26) & 1; return b; }

struct W2045_V4b { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W2045_Self { u8 pad[2848]; W2045_V4b dir; };
extern "C" {
W2045_V4b* func_0016c028(void);
f32 func_001065a8(f32, f32);
void func_002d1d30(W2045_V4b*, void*, W2045_V4b*);
f32 func_002f8870(f32);
extern void* D_00361f60;
}
// VU0 normalize xyz in place
static inline f32 w2045_norm(W2045_V4b* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

extern "C" {

// ---- 0x1bc9e8 ----
s32 func_001bc9e8(u8* p) {
    u8* s1 = *(u8**)(*(u8**)(p + 4) + 2532);
    if (func_001bcd08(p)) return 0;
    if (func_001bcf38(p)) { func_001bcc28(p); return 0; }
    if (!func_001bcf18(p)) func_001bce00(p);
    u64 f = *(u64*)(s1 + 8);
    if (f & 0x200000004ULL) {
        func_001bd988(*(void**)(p + 4));
    } else if (f & 8) {
        if (func_001bcf18(*(*(W2045_S2240**)(p + 4))->sp)) {
            *(u32*)(*(u8**)(p + 4) + 8) |= 2;
        } else {
            func_001bd618(*(void**)(p + 4), 1);
            if (w2045_entry_busy(*(*(W2045_S2240**)(p + 4))->sp)) func_001bc720(*(*(W2045_S2240**)(p + 4))->sp);
        }
    } else if (func_001818e8()) {
        f = *(u64*)(s1 + 8);
        if (f & 0x200) {
            *(u32*)(*(u8**)(p + 4) + 8) |= 8;
        } else if (f & 0x4000) {
            s32 i = *(s32*)(p + 108);
            if (i > 0) func_001bc730(p, i - 1);
            else func_001bc730(p, *(s32*)(p + 8) - 1);
            func_002ba2e8(1, 0);
        } else if (f & 0x8000) {
            s32 i = *(s32*)(p + 108);
            if (i < *(s32*)(p + 8) - 1) func_001bc730(p, i + 1);
            else func_001bc730(p, 0);
            func_002ba2e8(1, 0);
        } else if (f & 0x10000000) {
            W2045_Elem* e = &((W2045_Menu*)p)->e[*(s32*)(p + 108)];
            if (w2045_kind_ok(e)) {
                s32 b = (s8)func_001b8e88(e->id)[6];
                if (b >= 0) func_001bd5b0(*(void**)(p + 4), b, 1);
            }
        }
    }
    return 1;
}

// ---- 0x1dd320 (VU0 matrix multiply asm) ----
void func_001dd320(s32 a0, W2045_Arg1* a1, u8 a2) {
    W2045_V4 v0;
    W2045_V4 v1;
    W2045_M44 m;
    W2045_M44 r;
    func_00107368(a1, &v0);
    func_00107478(a1, &v1);
    func_001e6ed8(&a1->m, a0, &v0, &v1);
    m = *func_00106ad0(a0);
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
        : : "r"(&r), "r"(&m), "r"(&a1->m) : "memory");
    func_00146680(D_00352b00, &r);
    if (a2) func_00143f78(D_00352b00, &v0);
    func_001e7008(D_00349e10);
    func_001b81e8();
    func_001e6250();
    W2045_Obj* next;
    for (W2045_Obj* o = D_00352ae0; o; o = next) {
        next = o->next;
        if (func_001dc9d0(o) && !w2045_flag26(o) && func_001dcc60(o)) {
            if (o->h) {
                func_001e2c70(o->h, func_001dc790(o));
                func_001dca70(o);
                func_001e3330(o->h);
                if (!func_001e6280(o->h, func_001dccc8(o, a2))) {
                    func_001e6c00(o->h);
                    o->h = 0;
                    o->flags |= 0x10000;
                }
            }
            if (func_001dc9e0(o) && !func_001dc738(o)) func_001dcae0(o);
        }
    }
    func_001e65c8();
    func_001b8218();
}

// ---- 0x2d62d0 (VU0 normalize asm, lq/sq copy) ----
void func_002d62d0(W2045_Self* self) {
    W2045_V4b v;
    W2045_V4b o;
    void* s = D_00361f60;
    W2045_V4b* pv = &v;
    W2045_V4b* src = func_0016c028();
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(pv), "r"(src) : "$8", "memory");
    func_002d1d30(&o, s, pv);
    if ((o.x > 0.8f && self->dir.x > 0.0f) || (o.x < -0.8f && self->dir.x < 0.0f)
        || (o.y > 0.8f && self->dir.y > 0.0f) || (o.y < -0.8f && self->dir.y < 0.0f)) {
        f32 a, b;
        do {
            a = func_001065a8(-1.0f, 1.0f);
            b = func_001065a8(-1.0f, 1.0f);
        } while (func_002f8870(a) < 0.001f && func_002f8870(b) < 0.001f);
        if (o.x > 0.7f) a = -func_002f8870(a);
        if (o.x < -0.7f) a = func_002f8870(a);
        if (o.y > 0.7f) b = -func_002f8870(b);
        if (o.y < -0.7f) b = func_002f8870(b);
        self->dir.x = a;
        self->dir.y = b;
        self->dir.z = 0.0f;
        w2045_norm(&self->dir);
    }
}

}
