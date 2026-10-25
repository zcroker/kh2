#include "../common/types.h"

extern "C" {
extern s32 D_0034e948;
s32 func_0019ba60(s32);
void* func_001a8bd0(s32);
s32 func_001a8bf8(void*, s32);  // get_bits5_at
u8* func_001a8b28(void);  // get_data_1c7cc10
u8* func_0017e4f8(u16, s32, f32, f32, f32);
void func_001ad990(u8*, f32, f32, f32);

s32 func_00289380(void*);
s32 func_00289310(void*);
s32 func_002891e8(void*);
void func_002cac40(s32);
u8* func_001c3f58(s32);
void func_002c3da0(u8*);
void func_002c8648(void);
struct W254S10 { s16 h[5]; };

u8* func_001b9bc8(u8*);
s32 func_0016a040(u8*);
s32 func_0016a060(u8*);

struct W254File {
    u8* p;          /* 0 */
    s32 r;          /* 4 */
    s32 w;          /* 8 */
    s16 flags;      /* 12 */
    s16 file;       /* 14 */
    u8* base;       /* 16 */
    s32 size;       /* 20 */
    s32 lbfsize;    /* 24 */
    void* cookie;   /* 28 */
    s32 (*read)(void*, u8*, s32);   /* 32 */
    s32 (*write)(void*, u8*, s32);  /* 36 */
    u8 pad[84 - 40];
    u8* data;       /* 84 */
};
extern u8* D_00365c48;
s32 func_00303698(u8*, s32 (*)(W254File*));
void func_00302e10(u8*);

s32 func_001069e8(void);
void func_0015cff0(void);
f32 func_0017ce10(f32);
u8* func_00106a60(s32);  // buffer_get_by_index
void func_0013f9e0(u8*, u8*, u8*, u8, s32);
void func_0015d058(u8*, u8*);
void func_0015d208(f32*, f32*);
void func_00107300(u8*, u8*, u8*, f32);  // copy_blocks_and_store_float
u8* func_00106a18(s32);  // buffer_get_256
void func_00106de8(u8*, u8*, f32);

// Member lookup: find slot of id a0 in party (1..2), spawn its object, start its fade unless flagged.
u8* func_001c9c78(s32 a0) {
    void* m;
    s32 i;
    u8* r;
    if (func_0019ba60(D_0034e948) == 0) return 0;
    m = func_001a8bd0(-1);
    for (i = 1; i < 3; i++) {
        if (func_001a8bf8(m, i) == a0) break;
    }
    if (i >= 3) return 0;
    r = func_0017e4f8(*(u16*)(func_001a8b28() + a0 * 2 + 16), 0, 100.0f, 200.0f, 300.0f);
    if (r != 0) {
        if (!(*(u32*)(r + 2040) & 0x10)) {
            f32 c = 15.0f;
            f32 b = 1.0f;
            func_001ad990(r + 2092, 0.0f, b, c);
        }
    }
    return r;
}

// Landing-menu cursor update: switch on select result; confirm copies 10-byte entry then exits.
void func_002c3c90(u8* a0) {
    s32 r = func_00289380(*(void**)(a0 + 872));
    if (func_00289310(*(void**)(a0 + 872))) func_002cac40(1);
    switch (r) {
    case -2:
        func_002cac40(4);
        *(s32*)(a0 + 8240) = 0;
        func_002c3da0(a0);
        return;
    case -1:
    case -4:
        return;
    }
    if (func_002891e8(*(void**)(a0 + 872)) == 0) {
        func_002cac40(2);
        *(s32*)(a0 + 8240) = 1;
        *(u32*)(a0 + 24) |= 2;
        *(W254S10*)(a0 + 13608) = *(W254S10*)func_001c3f58(*(s32*)(a0 + 8236));
        func_002c3da0(a0);
        func_002c8648();
    } else {
        func_002cac40(2);
        *(s32*)(a0 + 8240) = 0;
        func_002c3da0(a0);
        asm volatile("");
    }
}

// Walk all objects; type 16 with sub-type 20/21/22/25/26/27 get virtual slot 10 called.
void func_002d0a78(void) {
    u8* o = 0;
    while ((o = func_001b9bc8(o)) != 0) {
        if (func_0016a040(o) != 16) continue;
        if (func_0016a060(o) == 20 || func_0016a060(o) == 21 || func_0016a060(o) == 22 ||
            func_0016a060(o) == 25 || func_0016a060(o) == 26 || func_0016a060(o) == 27) {
            (*(void (**)(u8*))(*(u8**)o + 40))(o);
        }
    }
}

// newlib fflush(fp): NULL flushes all via _fwalk; otherwise write out the buffer.
s32 func_00302b18(W254File* fp) {
    u8* p;
    s32 n;
    s32 t;
    if (fp == 0) return func_00303698(D_00365c48, func_00302b18);
    if (fp->data == 0) fp->data = D_00365c48;
    if (*(s32*)(fp->data + 56) == 0) func_00302e10(fp->data);
    t = fp->flags;
    if ((t & 8) == 0 || (p = fp->base) == 0)
        return 0;
    n = fp->p - p;
    fp->p = p;
    fp->w = t & 3 ? 0 : fp->size;
    while (n > 0) {
        t = fp->write(fp->cookie, p, n);
        if (t <= 0) {
            fp->flags |= 0x40;
            return -1;
        }
        p += t;
        n -= t;
    }
    return 0;
}

// Camera-mode-1 update: fix radian, optional helper calls, then apply to camera.
// 0015d2e8: moved to src/anon/unit_0015cdb0.cpp
struct W254PE { s32 key; u8 pad[16]; };
struct W254Pool { W254PE e[128]; s32 idx[128]; s32 count; };
extern W254Pool D_01c60d50;
u8* func_00186078(u8*);

static inline __attribute__((always_inline)) W254PE* w254_next(W254PE* prev) {
    W254PE* cur = D_01c60d50.e;
    if (prev) cur = prev + 1;
    while (cur < &D_01c60d50.e[128]) {
        s32 i = cur - D_01c60d50.e;
        s32 j;
        for (j = 0; j < D_01c60d50.count; j++) {
            if (D_01c60d50.idx[j] == i) {
                cur++;
                break;
            }
        }
        if (j == D_01c60d50.count) return cur;
    }
    return 0;
}

// Retarget key a0 -> a1 on every live object and on every pool entry not listed as free.
void func_00190570(s32 a0, s32 a1) {
    u8* p = 0;
    W254PE* e;
    while ((p = func_00186078(p)) != 0) {
        if (*(s32*)(p + 2548) == a0) *(s32*)(p + 2548) = a1;
    }
    for (e = 0; (e = w254_next(e)) != 0; ) {
        if (e->key == a0) e->key = a1;
    }
}
}

namespace w254_mtx {
struct Mtx { f32 m[16]; } __attribute__((aligned(16)));
static inline void MtxCopy(Mtx* d, const Mtx* s) {
    if (d != s)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
// In-place inverse of an orthonormal affine matrix: transpose rotation, negate rotated translation (VU0).
static inline void MtxInverseOrtho(Mtx* m) {
    asm volatile(
        "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
        "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
        "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
        "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
        "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
        "vsub.xyz $vf4, $vf0, $vf4\n\t"
        "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
        : : "r"(m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
extern "C" {
extern f32 D_00362d70;
u8* func_00106a18(s32);  // buffer_get_256
void func_00106de8(u8*, s32, f32);
void func_00106c08(u8*);
u8* func_00106a60(s32);  // buffer_get_by_index
void func_002e71a0(Mtx*, u32, u8, s32);

void wtarget_002e1178(u8* a0, u32, u32, u32) asm("_Z16wtarget_002e1178jjjj");
// Set camera FOV from degrees, rebuild projection, then store the inverse of a fresh view matrix.
void wtarget_002e1178(u8* a0, u32, u32, u32) {
    u8* v = func_00106a18(1);  // buffer_get_256
    Mtx tmp;
    Mtx* d;
    func_00106de8(v, 1, D_00362d70 * 0.017453292f);
    func_00106c08(v);
    u8* c = func_00106a60(1);  // buffer_get_by_index
    func_002e71a0(&tmp, *(u32*)(a0 + 112), (*(u8**)(a0 + 100))[8], 1);
    d = (Mtx*)(c + 16);
    MtxCopy(d, &tmp);
    MtxInverseOrtho(d);
}
}
}

namespace w254_v2 {
struct Vec {
    f32 x, y, z, w;
    Vec& operator=(const Vec& s) {
        if (this != &s)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void VecScale(Vec* a, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
}
extern "C" {
extern u16 D_0036c970[];
s32 func_001860b0(void);
void func_0016aef0(u8*, Vec*);
s32 func_0017f4e0(u8*, u16);
void func_0017f488(u8*, u16, f32, f32);
void func_0017f5e0(u8*, u32, s32, f32, f32);

// Optionally negate a direction, apply it, then pick motion 15/14 (flip if unavailable) and play it.
void func_00186590(u8* a0, Vec* a1, u32 a2) {
    Vec v;
    s32 i;
    v = *a1;
    if (func_001860b0()) {
        i = 0;
        VecScale(&v, -1.0f);
    } else {
        i = 1;
    }
    func_0016aef0(a0, &v);
    a0 += 320;
    if (!func_0017f4e0(a0, D_0036c970[i])) i ^= 1;
    func_0017f488(a0, D_0036c970[i], 0.0f, 0.0f);
    func_0017f5e0(a0, a2, 0, 0.0f, 0.0f);
    *(u32*)((u8*)a1 + 24) |= 1;
}
}
}
