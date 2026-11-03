// w3722: built with -O2 -fno-strict-aliasing (_nsa).
#include "../common/types.h"
struct V4fbe0 {
    f32 x, y, z, w;
    V4fbe0() {}
    V4fbe0& operator=(const V4fbe0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V4fbe0(const V4fbe0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    V4fbe0 mulk(f32 s, f32 k) const {
        V4fbe0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Prmfbe0 { u8 pad[24]; f32 a; u8 pad2[4]; f32 b; };
struct Objfbe0 { u8 pad[32]; V4fbe0 vel; u8 pad2[244 - 48]; f32 f244; f32 f248; u8 pad3[288 - 252]; f32 f288; };
extern "C" {
extern Prmfbe0* D_00352130;
extern f32 D_00349e10;
extern f32 D_00349e10_b asm("D_00349e10");
extern Prmfbe0* D_00352130_b asm("D_00352130");
// Horizontal speed clamp + vertical step on o->vel; returns the scaled velocity.
V4fbe0 func_0019fbe0(void* unused, Objfbe0* o) {
    o->f248 = o->f248 + D_00349e10;
    V4fbe0 r;
    r = o->vel;
    r.y = 0;
    f32 B, C, D;
    register f32 L asm("$f3") = r.normalize();
    register f32 K asm("$f3") = L; asm("" : "+f"(K));  // placeholder keeps $f3 busy to the end (orig puts vel.y in $f4)
    f32 P = D_00352130->a;
    f32 A = L * P;
    f32 M = o->f244;
    if (!(M < A)) A = M;
    B = r.x * A; C = r.z * A;
    o->vel.x = B; o->vel.z = C;
    if (o->vel.y < 0) o->vel.y = o->vel.y * D_00352130_b->b;
    C = o->vel.y;
    D = C + 0.40816324949264526f;
    if (!(D < o->f288)) D = o->f288;
    o->vel.y = D;
    r = o->vel.mulk(D_00349e10_b, K);
    return r;
}
}

extern "C" {
struct E1993a0 { u32 f0, key, f8, f12; f32 f16; struct E1993a0* next; };
struct P1993a0 { struct E1993a0 e[4]; s32 freeIdx[4]; s32 n; };
struct L1993a0 { struct E1993a0* head; struct E1993a0* tail; };
extern struct P1993a0 D_01c620c8;
extern struct L1993a0 D_01c62140;
static inline __attribute__((always_inline)) void rm1993a0(E1993a0* n) {
    register E1993a0* prev asm("$11");  // pins: prev in t3, list head in t7 like the original
    register E1993a0* h asm("$15") = D_01c62140.head;
    if (n == h) {
        D_01c62140.head = *(E1993a0* volatile*)&n->next;
        prev = 0;
    } else {
        E1993a0* it;
        for (it = h; it->next != n; it = it->next) ;
        prev = it;
        prev->next = *(E1993a0* volatile*)&n->next;
    }
    L1993a0* l = &D_01c62140;
    if (__builtin_expect(n == l->tail,0)) l->tail = prev;
    n->next = 0;
    D_01c620c8.freeIdx[D_01c620c8.n++] = (s32)(n - D_01c620c8.e);
}
// Remove every node with this key from the D_01c62140 list, returning its slot to the pool free list.
void func_001993a0(u32 key) {
    E1993a0* c; E1993a0* n;
    for (c = D_01c62140.head; __builtin_expect(c != 0,0); c = n) {
        n = c->next;
        if (c->key == key) rm1993a0(c);
    }
}
}

#define QC(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QVfe88 {
    f32 x, y, z, w;
    QVfe88() {}
    QVfe88(const QVfe88& o) { QC(this, &o); }
    QVfe88& operator=(const QVfe88& o) { if (this != &o) QC(this, &o); return *this; }
} __attribute__((aligned(16)));
extern "C" {
QVfe88* func_001dc5f8(s32);
f32* func_001dc670(s32);
void func_00143860(u8*, QVfe88*);
// Set an object's colour from a lookup (optionally converted to grey).
void func_001dfe88(u8* o, u8 flag) {
    QVfe88 v;
    v = *func_001dc5f8(*(s32*)(o + 0x40));
    v.y += 100000.0f;
    QVfe88 a;
    QVfe88* src = func_001dc5f8(*(s32*)(o + 0x40));
    QVfe88 b;
    QVfe88* pb = &b;
    a = *src;
    *pb = v;
    u8 c[4];
    func_00143860(c, &a);
    f32 r = c[0] * 0.0078125f;
    f32 g = c[1] * 0.0078125f;
    f32 bl = c[2] * 0.0078125f;
    if (flag) {
        bl = r * 0.3f + g * 0.59f + bl * 0.11f;
        g = bl;
        r = bl;
    }
    func_001dc670(*(s32*)(o + 0x40))[0] = r;
    func_001dc670(*(s32*)(o + 0x40))[1] = g;
    func_001dc670(*(s32*)(o + 0x40))[2] = bl;
}
}
