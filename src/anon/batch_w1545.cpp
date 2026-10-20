#include "../common/types.h"

struct W1545V4 {
    f32 x, y, z, w;
    W1545V4() {}
    W1545V4(const W1545V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1545V4& operator=(const W1545V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};

// VU0: normalises xyz in place; returns the original length.
static inline f32 w1545_vnorm(W1545V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
// VU0: *d = *a * s (all four lanes).
#define W1545_VSCALE "lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"

struct W1545E18 { u8 used; u8 pad[3]; s32 id; u8 pad2[8]; };
struct W1545Hd { u8 pad[10]; u16 n; };
struct W1545H18 { u8 pad[8]; W1545Hd* hdr; };
struct W1545O18 { u8 pad[0x818]; W1545H18* h; };
struct W1545T32 { u16 a; u16 b; };
struct W1545S32 { u8 pad[0x1ef8]; W1545T32 arr[1]; };
struct W1545OK { u8 pad[0x60]; f32 x; f32 y; f32 z; u8 p2[1360 - 0x6c]; W1545V4 v; };

extern "C" {
s32 func_0016b740(s32);
W1545E18* func_0019b308(W1545H18*);
s32 func_00196618();
s32 func_001d52a0(s32, s32);
extern W1545S32 D_0032bb30;
s32 func_001c0cd8(u8*);
f32 func_002f8ad0(f32, f32);
void func_0017d0e8(W1545V4*, f32);
void func_0016bd60(u8*, s32);

// Finds the first unused entry whose id resolves to key.
W1545E18* func_0018bae8(W1545O18* self, s32 key) {
    W1545H18* a = self->h;
    u16 n = a->hdr->n;
    W1545E18* p = func_0019b308(a);
    for (s32 i = 0; i < n; i++) {
        if (p[i].used == 0 && func_0016b740(p[i].id) == key) return &p[i];
    }
    return 0;
}

// 0 / -1 pass through from the table, anything else is -2; 0 is then rechecked.
s32 func_00196768(s32 a, s32 b) {
    s32 idx = func_00196618();
    s32 r = 0;
    if (idx >= 0) {
        s32 t = D_0032bb30.arr[idx].a;
        if (t != 0 && t != -1) t = -2;
        if (t == 0) { if (func_001d52a0(a, b)) t = -2; }
        r = t;
    }
    return r;
}

// Facing vector (struct return): from the angle of -(x, z) when active, else the stored one.
W1545V4 func_0016af58(W1545OK* o) {  // obj_get_rotation
    if (func_001c0cd8((u8*)o) != 0) {
        f32 z = -o->z;
        f32 x = -o->x;
        f32 f = func_002f8ad0(x, z);
        W1545V4 t;
        func_0017d0e8(&t, f);
        t.w = f;
        return t;
    }
    return o->v;
}

// Normalises *v, stores v * v.w at +32, s at +240, then state 5.
void func_0019fdc0(u8* self, W1545V4* v, f32 s) {  // vec4_normalize_2
    f32 w = v->w;
    w1545_vnorm(v);
    W1545V4* d = (W1545V4*)(self + 32);
    W1545V4 t;
    asm volatile(W1545_VSCALE : : "r"(&t), "r"(v), "f"(w) : "$8", "memory");
    *d = t;
    *(f32*)(self + 240) = s;
    func_0016bd60(self, 5);
}

// Same as func_0019fdc0 with state 6.
void func_001a0710(u8* self, W1545V4* v, f32 s) {
    f32 w = v->w;
    w1545_vnorm(v);
    W1545V4* d = (W1545V4*)(self + 32);
    W1545V4 t;
    asm volatile(W1545_VSCALE : : "r"(&t), "r"(v), "f"(w) : "$8", "memory");
    *d = t;
    *(f32*)(self + 240) = s;
    func_0016bd60(self, 6);
}
}
