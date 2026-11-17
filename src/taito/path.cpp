// Ti::Path (0x2cb538-0x2ce958): path objects in a global list, their ctor pair, point access,
// spline evaluation, slope set-up and the static init of the list.
#include "../common/types.h"
#include "../anon/auto80_199_queue_decls.hpp"
#include "../anon/auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "../anon/tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "path.hpp"

// ---- 002cb538 gap: C2 copy of the 0x2cb5d8 ctor
namespace n002cb538 {
struct W1779Node {
    u8 m0; u8 p1[3];
    s32 m4, m8, mc;
    u8 m10; u8 p11[3];
    f32 m14;
    s32 m18;
    f32 m1c, m20, m24;
    u8 p28[0x80 - 0x28];
    s32 m80;
    u8 m84, m85, m86, m87;
    s32 m88, m8c, m90;
    W1779Node* next;
};
struct W1779List { W1779Node* head; W1779Node* tail; };
extern W1779List D_01e2be18 asm("D_01e2be18");
void func_002cb538(W1779Node* p, f32 f) asm("func_002cb538");
void func_002cb538(W1779Node* p, f32 f) {
    p->m0 = 0; p->m4 = 0; p->m8 = 0; p->mc = 0; p->m10 = 0;
    p->m14 = f; p->m18 = 0;
    p->m1c = -2.0f; p->m20 = 0.5f; p->m24 = 20.0f;
    p->m80 = 0; p->m84 = 1; p->m85 = 0; p->m87 = 0;
    p->m88 = 0; p->m8c = -1; p->m90 = 0;
    if (D_01e2be18.tail == 0) {
        D_01e2be18.tail = p;
        D_01e2be18.head = p;
        p->next = 0;
    } else {
        D_01e2be18.tail->next = p;
        p->next = 0;
        D_01e2be18.tail = p;
    }
}
}  // namespace n002cb538

// ---- 002cb5d8 from src/anon/batch_w1779_nsa.cpp
namespace n002cb5d8 {
struct W1779Node {
    u8 m0; u8 p1[3];
    s32 m4, m8, mc;
    u8 m10; u8 p11[3];
    f32 m14;
    s32 m18;
    f32 m1c, m20, m24;
    u8 p28[0x80 - 0x28];
    s32 m80;
    u8 m84, m85, m86, m87;
    s32 m88, m8c, m90;
    W1779Node* next;
};
struct W1779List { W1779Node* head; W1779Node* tail; };
extern W1779List D_01e2be18 asm("D_01e2be18");
void func_002cb5d8(W1779Node* p, f32 f) asm("func_002cb5d8");
void func_002cb5d8(W1779Node* p, f32 f) {
    p->m0 = 0; p->m4 = 0; p->m8 = 0; p->mc = 0; p->m10 = 0;
    p->m14 = f; p->m18 = 0;
    p->m1c = -2.0f; p->m20 = 0.5f; p->m24 = 20.0f;
    p->m80 = 0; p->m84 = 1; p->m85 = 0; p->m87 = 0;
    p->m88 = 0; p->m8c = -1; p->m90 = 0;
    if (D_01e2be18.tail == 0) {
        D_01e2be18.tail = p;
        D_01e2be18.head = p;
        p->next = 0;
    } else {
        D_01e2be18.tail->next = p;
        p->next = 0;
        D_01e2be18.tail = p;
    }
}
}  // namespace n002cb5d8

// ---- 002cb678 from src/anon/batch_w1551.cpp
namespace n002cb678 {
void func_00105110(void*) asm("func_00105110");
struct N2cb678 { u8 pad[0x80]; void* buf; u8 pad2[0x10]; N2cb678* next; };
struct L2cb678 { N2cb678* head; N2cb678* tail; };
extern L2cb678 D_01e2be18 asm("D_01e2be18");
void func_002cb678(N2cb678* n) asm("func_002cb678");
void func_002cb678(N2cb678* n) {
    func_00105110(n->buf);
    N2cb678* prev;
    if (n == D_01e2be18.head) {
        D_01e2be18.head = n->next;
        prev = 0;
    } else {
        prev = D_01e2be18.head;
        while (prev->next != n) prev = prev->next;
        prev->next = n->next;
    }
    if (n == D_01e2be18.tail) D_01e2be18.tail = prev;
    n->next = 0;
}
}  // namespace n002cb678

// ---- 002cb708 from src/anon/batch_w12.cpp
namespace n002cb708 {
void func_00105110(void*) asm("func_00105110");
u8 func_00325320(void*, void*) asm("func_00325320");
extern u8 D_01e2be18 asm("D_01e2be18");
s32 func_002cb708(u8* p) asm("func_002cb708");
s32 func_002cb708(u8* p) {
    func_00105110(*(void**)(p + 128));
    return func_00325320(&D_01e2be18, p);
}
}  // namespace n002cb708

// ---- 002cb740 gap: empty function
namespace n002cb740 {
void func_002cb740(void) asm("func_002cb740");
void func_002cb740(void) {
}
}  // namespace n002cb740

// ---- 002cb748 from src/anon/auto80_199_queue.cpp
namespace n002cb748 {
void func_002cb748() asm("_Z13func_002cb748v");
void func_002cb748() {
    u32 s0 = D_01e2be18;
    if (s0 == 0) {
        return;
    }

    while (1) {
        u32 s1 = *(u32*)(s0 + 148);
        if (s0 != 0) {
            func_002cb708(s0);
            func_00105110(s0);
        }
        if (s1 == 0) {
            break;
        }
        s0 = s1;
    }
}
}  // namespace n002cb748

// ---- 002cb7a0 from src/anon/tiny_auto80_queue.cpp
namespace n002cb7a0 {
void func_002cb7a0(u32 a0, u32 a1) asm("_Z13func_002cb7a0jj");
void func_002cb7a0(u32 a0, u32 a1) {
    if (*(u8*)(a0 + 134) == 0) {
        u8 v = (u8)a1;
        if (*(u8*)(a0 + 132) != v) {
            *(u8*)(a0 + 132) = v;
        }
    }
}
}  // namespace n002cb7a0

// ---- 002cb7c0 gap: setter of the word at +140 (third argument)
namespace n002cb7c0 {
void func_002cb7c0(u8* p, u32, s32 v) asm("func_002cb7c0");
void func_002cb7c0(u8* p, u32, s32 v) {
    *(s32*)(p + 140) = v;
}
}  // namespace n002cb7c0

// ---- 002cb7c8 from src/anon/batch_w13.cpp
namespace n002cb7c8 {
struct Q128 { u32 w[4]; };
Q128* func_002cb890(void*, void*) asm("func_002cb890");
Q128* func_002cb7c8(Q128* out, void* a, void* b) asm("func_002cb7c8");
Q128* func_002cb7c8(Q128* out, void* a, void* b) {                     
    Q128* s = func_002cb890(a, b);                    
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(s) : "$8", "memory");
    return out;
}
}  // namespace n002cb7c8

// ---- 002cb800 from src/anon/tiny_auto80_queue.cpp
namespace n002cb800 {
u32 func_002cb800(u32 a0) asm("_Z13func_002cb800j");
u32 func_002cb800(u32 a0) {
    if (*(u8*)(a0 + 134) != 0) {
        return *(u8*)(a0 + 132);
    }

    u8 v = (u8)(*(u8*)(a0 + 132) ^ 1);
    *(u8*)(a0 + 132) = v;
    return v;
}
}  // namespace n002cb800

// ---- 002cb828 from src/anon/batch_w38.cpp
namespace n002cb828 {
struct Q128 { u32 w[4]; } __attribute__((aligned(16)));
static inline void qcopy(void* d, const void* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct Ent2cb828 { Q128 v; u8 pad[16]; };
struct Ring2cb828 { u32 f0; s32 head; s32 cnt; s32 cap; u8 pad[112]; Ent2cb828* buf; };
Ent2cb828* func_002cb828(Ring2cb828* r, Q128* src) asm("func_002cb828");
Ent2cb828* func_002cb828(Ring2cb828* r, Q128* src) {                       
    s32 cnt = r->cnt;
    s32 head = r->head;
    s32 idx = (head + cnt) % r->cap;
    if (cnt < r->cap) r->cnt = cnt + 1;
    else r->head = head + 1;
    qcopy(&r->buf[idx].v, src);
    return &r->buf[idx];
}
}  // namespace n002cb828

// ---- 002cb890 from src/anon/tiny_auto80_queue.cpp
namespace n002cb890 {
u32 func_002cb890(u32 a0, s32 a1) asm("_Z13func_002cb890ji");
u32 func_002cb890(u32 a0, s32 a1) {                    
    s32 d = *(s32*)(a0 + 12);
    s32 r = a1 % d;
    return *(u32*)(a0 + 128) + ((u32)r << 5);
}
}  // namespace n002cb890

// ---- 002cb8b8 from src/anon/tiny_auto80_queue.cpp
namespace n002cb8b8 {
u32 func_002cb8b8(u32 a0) asm("_Z13func_002cb8b8j");
u32 func_002cb8b8(u32 a0) {
    s32 d = *(s32*)(a0 + 12);
    s32 n = *(s32*)(a0 + 4);
    s32 r = n % d;
    return *(u32*)(a0 + 128) + ((u32)r << 5);
}
}  // namespace n002cb8b8

// ---- 002cb8e0 from src/anon/tiny_auto80_queue.cpp
namespace n002cb8e0 {
u32 func_002cb8e0(u32 a0) asm("_Z13func_002cb8e0j");
u32 func_002cb8e0(u32 a0) {
    s32 extra = *(s32*)(a0 + 8);
    s32 n = *(s32*)(a0 + 4);
    s32 d = *(s32*)(a0 + 12);
    s32 r = (n + extra - 1) % d;
    return *(u32*)(a0 + 128) + ((u32)r << 5);
}
}  // namespace n002cb8e0

// ---- 002cb918 from src/anon/misc_2.cpp
namespace n002cb918 {
s32 func_002cb918(void* self) asm("_Z13func_002cb918Pv");
s32 func_002cb918(void* self) { return (s32)(*(s32*)((char*)self + 4)); }
}  // namespace n002cb918

// ---- 002cb920 from src/anon/tiny_more.cpp
namespace n002cb920 {
u32 func_002cb920(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_002cb920jjjj");
u32 func_002cb920(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = *(u32*)((u32)a0 + (4)) + *(u32*)((u32)a0 + (8)); return (u32)((s32)v + (-1)); }
}  // namespace n002cb920

// ---- 002cb938 from src/anon/batch_w1825_nsa.cpp
namespace n002cb938 {
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
W1825QV func_002cb938(f32 t, W1825Hermite* c) asm("func_002cb938");
W1825QV func_002cb938(f32 t, W1825Hermite* c)
{
    W1825QV r = w1825_hermite(c->p0, c->m0, c->p1, c->m1, t - c->m0.w);
    r.w = 1.0f;
    return r;
}
}  // namespace n002cb938

// ---- 002cba50 from src/anon/batch_w2028.cpp
namespace n002cba50 {
struct S5 { u8 pad[36]; f32 f; };
void func_002cba88(void*, S5*, void*, void*, f32, f32) asm("func_002cba88");
void* func_002cba50(void* a0, S5* a1, void* a2, void* a3) asm("func_002cba50");
void* func_002cba50(void* a0, S5* a1, void* a2, void* a3) {
    func_002cba88(a0, a1, a2, a3, a1->f, 1.0f);
    return a0;
}
}  // namespace n002cba50

// ---- 002cba88 from src/anon/batch_w2023_nsa.cpp
namespace n002cba88 {
struct W2023Q {
    f32 x, y, z, w;
    W2023Q() {}
    W2023Q(const W2023Q& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2023Q& operator=(const W2023Q& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W2023Q operator-(const W2023Q& b) const
    {
        W2023Q r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W2023Q operator+(const W2023Q& b) const
    {
        W2023Q r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W2023Q operator*(f32 k) const
    {
        W2023Q r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 normalize()
    {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
s32 func_002cbf70(void* a, W2023Q* out, W2023Q* p, f32 t) asm("func_002cbf70");
W2023Q func_002cba88(void* a, const W2023Q& from, const W2023Q& other, f32 t, f32 k) asm("func_002cba88");
W2023Q func_002cba88(void* a, const W2023Q& from, const W2023Q& other, f32 t, f32 k)
{
    W2023Q o;
    W2023Q p = from;
    if (t > 50.0f) t = 50.0f;
    if (!func_002cbf70(a, &o, &p, t)) {
        W2023Q r = other;
        r.w = 0.0f;
        return r;
    }
    W2023Q d1 = o - from;
    W2023Q d2 = o - p;
    f32 l1 = d1.normalize();
    d2.normalize();
    if (t * 10.0f < l1) {
        d1.w = 1.0f;
        return d1;
    }
    W2023Q m = d1 * (1.0f - k) + d2 * k;
    m.normalize();
    m.w = 1.0f;
    return m;
}
}  // namespace n002cba88

// ---- 002cbca0 from src/anon/batch_w50.cpp
namespace n002cbca0 {
f32* func_002cba88(f32*, u8*, f32, f32) asm("func_002cba88");
f32* func_002cbca0(f32* out, u8* p) asm("func_002cbca0");
f32* func_002cbca0(f32* out, u8* p) {
    func_002cba88(out, p, *(f32*)(p + 36), 1.0f);
    out[3] = *(f32*)(p + 20);
    return out;
}
}  // namespace n002cbca0

// ---- 002cbcf0 from src/anon/tiny_wrappers_more.cpp
namespace n002cbcf0 {
u32 func_002cbd20(u32, u32, u32, u32) asm("_Z13func_002cbd20jjjj");
u32 func_002cbcf0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002cbcf0jjjj");
u32 func_002cbcf0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002cbd20(a0, ((u32)(a0) + 28u), a2, a3);
}
}  // namespace n002cbcf0

// ---- 002cbd08 from src/anon/tiny_wrappers_more.cpp
namespace n002cbd08 {
u32 func_002cbd20(u32, u32, u32, u32) asm("_Z13func_002cbd20jjjj");
u32 func_002cbd08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002cbd08jjjj");
u32 func_002cbd08(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002cbd20(a0, ((u32)(a0) + 24u), a2, a3);
}
}  // namespace n002cbd08

// ---- 002cbd20 from src/anon/batch_w284.cpp
namespace n002cbd20 {
struct QV284 {
    f32 v[4];
    QV284() {}
    QV284& operator=(const QV284& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline void vsub284(QV284* d, const QV284* a, const QV284* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vlen284(const QV284* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
void func_002cd910(QV284*, u8*, f32) asm("func_002cd910");
f32 fabsf(f32) asm("fabsf");
s32 func_002cb920(u8*) asm("func_002cb920");
s32 wtarget_002cbd20(u8*, f32*, f32) asm("_Z16wtarget_002cbd20jjjj");
s32 wtarget_002cbd20(u8* obj, f32* t, f32 dist) {
    QV284 a;
    f32 acc = 0.0f;
    f32 t0 = *t;
    s32 i = 0;
    func_002cd910(&a, obj, t0);                     
    while (acc < dist) {
        QV284 b, d;
        func_002cd910(&b, obj, *t);                     
        vsub284(&d, &b, &a);
        f32 prev = acc;
        acc += vlen284(&d);
        if (dist <= acc) {
            if (fabsf(prev - dist) < fabsf(acc - dist)) *t = t0;
            break;
        }
        a = b;
        t0 = *t;
        *t = t0 + 5e-05f;
        if ((f32)(func_002cb920(obj) + 1) <= *t) *t = *t - (f32)(func_002cb920(obj) + 1);                          
        i++;
        if (i >= 1024) break;
    }
    return 1;
}
}  // namespace n002cbd20

// ---- 002cbec0 from src/anon/tiny_wrappers_more.cpp
namespace n002cbec0 {
u32 func_002ce598(u32, u32, u32, u32) asm("_Z13func_002ce598jjjj");
u32 func_002cbec0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002cbec0jjjj");
u32 func_002cbec0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002ce598(a0, a1, a2, a3);
}
}  // namespace n002cbec0

// ---- 002cbed8 from src/anon/tiny_auto80_queue.cpp
namespace n002cbed8 {
void func_002cd910(f32) asm("_Z13func_002cd910f");
u32 func_002cbed8(...) asm("_Z13func_002cbed8jj");
u32 func_002cbed8(u32 a0, u32 a1) asm("_Z13func_002cbed8jj");
u32 func_002cbed8(u32 a0, u32 a1) {
    func_002cd910(*(f32*)(a1 + 24));                     
    return a0;
}
}  // namespace n002cbed8

// ---- 002cbf08 from src/anon/batch_w1517.cpp
namespace n002cbf08 {
struct QW_w1517 { f32 v[4]; } __attribute__((aligned(16)));
static inline f32 Normalize_w1517(QW_w1517* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
void func_002cdb00(QW_w1517*, f32) asm("func_002cdb00");
struct T_002cbf08 { u8 pad[0x18]; f32 f18; };
QW_w1517* func_002cbf08(QW_w1517* a0, T_002cbf08* a1) asm("func_002cbf08");
QW_w1517* func_002cbf08(QW_w1517* a0, T_002cbf08* a1) {
    asm volatile("");
    func_002cdb00(a0, a1->f18);
    Normalize_w1517(a0);
    return a0;
}
}  // namespace n002cbf08

// ---- 002cbf70 from src/anon/batch_w3731_nsa.cpp
namespace n002cbf70 {
struct V2cbf70 {
    f32 x, y, z, w;
    V2cbf70() {}
    V2cbf70(const V2cbf70& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2cbf70& operator=(const V2cbf70& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2cbf70 operator-(const V2cbf70& b) const
    {
        V2cbf70 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
                     : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Path2cbf70 {
    u8 pad0[4];
    s32 first;
    s32 n;
    u8 pad12[4];
    u8 loop;
    u8 pad17[7];
    f32 t0;
    f32 t;
    u8 pad32[8];
    f32 segLen;
    u8 pad44[4];
    V2cbf70 a0, a1, b0, b1, last;
    u8 pad128[4];
    u8 fwd, stop, fixed, mode;
    u8 pad136[4];
    s32 mark;
};
s32 func_002cb918(Path2cbf70*) asm("func_002cb918");
s32 func_002cb920(Path2cbf70*) asm("func_002cb920");
V2cbf70* func_002cb890(Path2cbf70*, s32) asm("func_002cb890");
V2cbf70 func_002cb938(Path2cbf70*, f32) asm("func_002cb938");
V2cbf70 func_002cd910(Path2cbf70*, f32) asm("func_002cd910");
f32 func_002ce598(Path2cbf70*, V2cbf70*) asm("func_002ce598");
void func_002cb800(Path2cbf70*, V2cbf70*) asm("func_002cb800");
void func_002ce6b8(Path2cbf70*, V2cbf70*, f32) asm("func_002ce6b8");
f32 fabsf(f32) asm("fabsf");
s32 func_002cbf70(Path2cbf70* p, V2cbf70* out, V2cbf70* pos0, f32 dist) asm("func_002cbf70");
s32 func_002cbf70(Path2cbf70* p, V2cbf70* out, V2cbf70* pos0, f32 dist)
{
    V2cbf70* pos; asm("" : "=r"(pos));
    __typeof__(p->mode) m = p->mode;
    register V2cbf70* a asm("$6") = pos0;
    asm volatile("" : : "r"(a), "r"(m), "r"(pos));
    pos = a;
    if (m) {
        if (p->n < 2) return 0;
        if ((f32)func_002cb920(p) - 1.0f < p->t) return 0;
    } else {
        f32 t0 = p->t0;
        V2cbf70 a = func_002cd910(p, t0);
        V2cbf70 b = *pos;
        func_002ce6b8(p, pos, dist * 10.0f);
        V2cbf70 d1 = a - b;
        V2cbf70 d2 = *pos - b;
        f32 l1 = d1.length();
        f32 l2 = d2.length();
        if (fabsf(l2 - l1) < (l1 + l2) * 0.0001f) {
            p->t0 = t0;
            *pos = a;
        }
        p->t = p->t0;
        if (p->mark >= 0) {
            s32 it = (s32)p->t;
            if (!p->fixed) {
                if (it < p->mark) p->fwd = 1;
                else p->fwd = 0;
            }
        }
    }
    if (p->t < -1.0f) {
        func_002ce598(p, pos);
        p->t = p->t0;
    }
    if (p->mode) {
        s32 i = (s32)(p->t + 1.0f);
        if (i >= func_002cb918(p)) {
            V2cbf70* v = func_002cb890(p, i);
            p->b0 = v[0];
            p->b1 = v[1];
            p->segLen = (p->b0 - p->a0).length();
        }
    }
    p->last = *pos;
    s32 pass = 0;
    s32 done;
    do {
        done = 1;
        for (s32 k = 0; k < 20; k++) {
            V2cbf70 e = func_002cb938(p, p->t);
            {
                V2cbf70 d = e - *pos;
                d.y = 0.0f;
                if (dist < d.length()) {
                    *out = e;
                    return 1;
                }
            }
            f32 step = dist / p->segLen * 0.5f;
            s32 i;
            if (p->fwd) {
                p->t += step;
                if (!(p->a1.w + 1.0f <= p->t)) continue;
                i = (s32)(p->t + 1.0f);
                if (p->mode) {
                    if (i >= func_002cb920(p)) {
                        p->t = p->b1.w;
                        p->a0 = p->b0;
                        p->a1 = p->b1;
                        return 0;
                    }
                    if (i < func_002cb918(p)) {
                        func_002ce598(p, pos);
                        done = 0;
                        p->t = p->t0;
                        break;
                    }
                } else if (func_002cb920(p) < i) {
                    if (p->loop) {
                        i = i - func_002cb920(p) - 1;
                        i += func_002cb918(p);
                    } else if (p->stop) {
                        func_002cb800(p, pos);
                        done = 0;
                        break;
                    } else {
                        return 0;
                    }
                }
                p->t = p->b1.w;
                p->a0 = p->b0;
                p->a1 = p->b1;
                V2cbf70* v = func_002cb890(p, i);
                p->b0 = v[0];
                p->b1 = v[1];
                p->segLen = (p->b0 - p->a0).length();
            } else {
                p->t -= step;
                if (!(p->t <= p->a1.w)) continue;
                i = (s32)(p->a1.w + 0.5f) - 1;
                if (i < func_002cb918(p)) {
                    i -= func_002cb918(p);
                    i = i + func_002cb920(p) + 1;
                }
                if (p->mode) {
                    if (p->t < (f32)func_002cb918(p)) return 0;
                } else if (p->t <= (f32)func_002cb918(p)) {
                    if (p->loop) {
                        p->t = (f32)(func_002cb920(p) + 1);
                    } else if (p->stop) {
                        func_002cb800(p, pos);
                        done = 0;
                        break;
                    } else {
                        return 0;
                    }
                } else {
                    p->t = p->a1.w;
                }
                p->b0 = p->a0;
                p->b1 = p->a1;
                V2cbf70* v = func_002cb890(p, i);
                p->a0 = v[0];
                p->a1 = v[1];
                p->segLen = (p->b0 - p->a0).length();
            }
        }
        pass++;
    } while (pass < 2 && !done);
    *out = *pos;
    return 1;
}
}  // namespace n002cbf70

// ---- 002cc620 from src/anon/batch_w286.cpp
namespace n002cc620 {
#define QCOPY_bfa0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_bfa0 {
    f32 x, y, z, w;
    QV_bfa0() {}
    QV_bfa0(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_bfa0(const QV_bfa0& o) { QCOPY_bfa0(this, &o); }
    QV_bfa0& operator=(const QV_bfa0& o) { if (this != &o) QCOPY_bfa0(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline f32 normalize_bfa0(QV_bfa0* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline QV_bfa0 operator-(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 operator+(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 operator*(const QV_bfa0& a, f32 k) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline f32 dot_c620(const QV_bfa0& a, const QV_bfa0& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct Ob_c620 { u8 pad[0x84]; u8 x84; u8 x85; u8 x86; };
#define QCOPY_b0a8(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_b0a8 {
    f32 x, y, z, w;
    QV_b0a8() {}
    QV_b0a8(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_b0a8(const QV_b0a8& o) { QCOPY_b0a8(this, &o); }
} __attribute__((aligned(16)));
QV_bfa0* func_0016c028(void*) asm("func_0016c028");
void func_002ce2a0(Ob_c620*, s32*, f32*, QV_bfa0*) asm("func_002ce2a0");
QV_bfa0 func_002cda68(Ob_c620*, s32, f32) asm("func_002cda68");
void func_002cc620(Ob_c620* o, void* a, void* b) asm("func_002cc620");
void func_002cc620(Ob_c620* o, void* a, void* b) {
  if (o->x86) return;
  QV_bfa0 d = *func_0016c028(a) - *func_0016c028(b);                          

  if (normalize_bfa0(&d) < 0.01f) return;
  s32 i; f32 f;
  func_002ce2a0(o, &i, &f, func_0016c028(a));
  QV_bfa0 v = func_002cda68(o, i, f);
  if (normalize_bfa0(&v) < 0.01f) return;
  QV_bfa0 w = v * -1.0f;
  f32 dv = dot_c620(d, v);
  f32 dw = dot_c620(d, w);
  o->x84 = dw <= dv;
}
}  // namespace n002cc620

// ---- 002cc7d0 from src/anon/batch_w3865_gnsa.cpp
namespace n002cc7d0 {
struct V2cc7d0 {
    f32 x, y, z, w;
    V2cc7d0() {}
    V2cc7d0& operator=(const V2cc7d0& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2cc7d0 operator-(const V2cc7d0& b) const
    {
        V2cc7d0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2cc7d0 operator+(const V2cc7d0& b) const
    {
        V2cc7d0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2cc7d0 operator*(f32 k) const
    {
        V2cc7d0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V2cc7d0 operator/(f32 k) const
    {
        V2cc7d0 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V2cc7d0& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    f32 Length() const
    {
        f32 l;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(l) : "r"(this) : "$8");
        return l;
    }
} __attribute__((aligned(16)));
struct Pt2cc7d0 { V2cc7d0 pos; V2cc7d0 tan; };
struct Path2cc7d0 { u8 pad0[8]; s32 count; u8 pad1[4]; u8 loop; u8 pad2[15]; f32 tension; u8 pad3[128 - 36]; Pt2cc7d0* pts; };
void func_002cc7d0(Path2cc7d0* p) asm("func_002cc7d0");
void func_002cc7d0(Path2cc7d0* p)
{
    s32 i;
    if (p->count < 3) {
        p->pts[0].tan = p->pts[1].pos - p->pts[0].pos;
        p->pts[1].tan = p->pts[0].tan;
        p->loop = 0;
        return;
    }
    for (i = 0; i < p->count; i++) {
        if (!p->loop && i == 0) {
            Pt2cc7d0* q = p->pts;
            f32 l0, l1, s, u;
            V2cc7d0* c = &q[2].pos;
            V2cc7d0* a = &q[0].pos;
            V2cc7d0* b = &q[1].pos;
            V2cc7d0 m;
            V2cc7d0 d;
            d = *b - *a;
            l0 = d.Length();
            d = *c - *b;
            s = d.Length();
            s = l0 / (l0 + s);
            u = 1.0f - s;
            m = (*b - *a * u * u - *c * s * s) / ((s + s) * u);
            d = (m - *a) * 2.0f;
            V2cc7d0 v = *a * (u * -2.0f) + m * (2.0f - s * 4.0f) + *c * 2.0f * s;
            l1 = v.Length();
            d *= ((*c - *a) * p->tension).Length() / l1;
            p->pts[i].tan = d;
        } else if (!p->loop && i == p->count - 1) {
            Pt2cc7d0* q = &p->pts[i];
            f32 l0, l1, s, u;
            V2cc7d0* c = &q[0].pos;
            V2cc7d0* a = &q[-2].pos;
            V2cc7d0* b = &q[-1].pos;
            V2cc7d0 m;
            V2cc7d0 d;
            d = *b - *a;
            l0 = d.Length();
            d = *c - *b;
            s = d.Length();
            s = l0 / (l0 + s);
            u = 1.0f - s;
            m = (*b - *a * u * u - *c * s * s) / ((s + s) * u);
            d = (*c - m) * 2.0f;
            V2cc7d0 v = *a * (u * -2.0f) + m * (2.0f - s * 4.0f) + *c * 2.0f * s;
            l1 = v.Length();
            d *= ((*c - *a) * p->tension).Length() / l1;
            p->pts[i].tan = d;
        } else {
            s32 prev = i - 1;
            s32 next = i + 1;
            if (prev < 0) prev += p->count;
            if (next >= p->count) next -= p->count;
            p->pts[i].tan = (p->pts[next].pos - p->pts[prev].pos) * p->tension;
        }
        p->pts[i].tan.w = (f32)i;
    }
}
}  // namespace n002cc7d0

// ---- 002ccf80 gap: flag setters
namespace n002ccf80 {
void func_002ccf80(u8* p) asm("func_002ccf80");
void func_002ccf80(u8* p) {
    *p = 1;
}
void func_002ccf90(u8* p) asm("func_002ccf90");
void func_002ccf90(u8* p) {
    *p = 0;
}
}  // namespace n002ccf80

// ---- 002ccf98 from src/anon/auto80_199_queue.cpp
namespace n002ccf98 {
void func_002ccf98(u32 a0) asm("_Z13func_002ccf98j");
void func_002ccf98(u32 a0) {
    u32 s0 = a0;

    if (*(u8*)(a0 + 135) == 0) {
        return;
    }

    u32 t7 = *(u32*)(a0 + 136);
    if (t7 != 0) {
        if (func_0019ba60(t7) != 0) {
            func_002cd3e0(s0, *(u32*)(s0 + 136));
            return;
        }
    }

    func_002cd260(s0);
}
}  // namespace n002ccf98

// ---- 002cd008 from src/taito/path.cpp
namespace Ti {
u32 Path::check_data(const YS::UNIT_DATA_PATH* data) {
    u32 v = *(u32*)((u32)this + 144);
    v ^= (u32)data;
    return (v < (u32)1);
}
}  // namespace Ti

// ---- 002cd018 from src/anon/batch_w290.cpp
namespace n002cd018 {
struct W290V {
    f32 x, y, z, w;
    W290V() {}
    W290V(const W290V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W290V& operator=(const W290V& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 Length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 Normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 LengthSq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W290M { W290V r[4]; };
static inline W290V operator*(const W290M& m, const W290V& v) {
    W290V r;
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
static inline W290V operator-(const W290V& a, const W290V& b) {
    W290V r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W290V operator+(const W290V& a, const W290V& b) {
    W290V r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
void* func_001050d8(u32) asm("func_001050d8");
void func_002cb5d8(void*, f32) asm("func_002cb5d8");
s32 func_0018ac80(void*, s32) asm("func_0018ac80");
void func_002cb828(void*, f32*) asm("func_002cb828");
void func_002cc7d0(void*) asm("func_002cc7d0");
void func_002ce870(void*, void*) asm("func_002ce870");
void func_002ce598(void*, void*) asm("func_002ce598");
struct W290Ent { f32 a; f32 b; f32 c; };
struct W290Dat { u16 h0; u16 n; u8 b4; u8 p5[3]; W290Ent e[1]; };
struct W290Cd {  u8 p0[12]; u32 n; u8 b16; u8 p17[15]; f32 f32_; u8 p36[92]; u32 buf; u8 p132; u8 b133; u8 b134; u8 p135[9]; W290Dat* dat; };
W290Cd* func_002cd018(u8* act, W290Dat* d, void* a2, f32 f) asm("func_002cd018");
W290Cd* func_002cd018(u8* act, W290Dat* d, void* a2, f32 f) {
    s32 s4 = 0;
    W290Cd* p = (W290Cd*)func_001050d8(160);
    func_002cb5d8(p, f);
    u16 n = d->n;
    p->n = n;
    p->buf = (u32)func_001050d8(n << 5);
    if (*(u32*)(act + 1416) & 8) s4 = func_0018ac80(act, 3) != 0;
    for (s32 i = 0; i < d->n; i++) {
        f32 t[4];
        t[0] = d->e[i].a;
        t[1] = d->e[i].b;
        if (s4) t[1] = d->e[0].b;
        t[2] = d->e[i].c;
        t[3] = 1.0f;
        func_002cb828(p, t);                       
    }
    p->b16 = d->b4 & 1;
    f32 z = 0.0f;
    if (!(d->b4 & 2)) z = 0.5f;
    p->f32_ = z;
    func_002cc7d0(p);
    if (*(u32*)(act + 1416) & 8) {
        p->b134 = func_0018ac80(act, 2);
        if (func_0018ac80(act, 1)) func_002ce598(p, a2);
        else func_002ce870(p, act);
    } else {
        p->b134 = 0;
        func_002ce598(p, a2);
    }
    p->dat = d;
    p->b133 = p->b134 == 0;
    return p;
}
}  // namespace n002cd018

// ---- 002cd1d8 from src/anon/batch_w64.cpp
namespace n002cd1d8 {
u8* func_001050d8(u32) asm("func_001050d8");
void func_002cb5d8(u8*, f32) asm("func_002cb5d8");
void func_002cd290(u8*, u32, u32) asm("func_002cd290");
u8* func_002cd1d8(u32 a, u32 b) asm("func_002cd1d8");
u8* func_002cd1d8(u32 a, u32 b) {
    u8* o = func_001050d8(160);
    func_002cb5d8(o, 8.0f);
    o[134] = 0;
    *(u32*)(o + 12) = 32;
    *(u8**)(o + 128) = func_001050d8(1024);
    o[135] = 1;
    func_002cd290(o, a, b);
    return o;
}
}  // namespace n002cd1d8

// ---- 002cd260 from src/anon/batch_wcx2.cpp
namespace n002cd260 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
void func_002cd260(u8* p) asm("func_002cd260");
void func_002cd260(u8* p) {
    if (p[135]) {
        *(s32*)(p + 136) = 0;
        *(s32*)(p + 4) = 0;
        *(f32*)(p + 28) = -2.0f;
        *(s32*)(p + 8) = 0;
        *(s32*)(p + 24) = 0;
    }
}
}  // namespace n002cd260

// ---- 002cd290 from src/anon/batch_w98.cpp
namespace n002cd290 {
struct M200 { f32 m[4][4]; } __attribute__((aligned(16)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) QW2cd;
static inline void VSub2cd(QW2cd* d, const QW2cd* a, const QW2cd* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 VLen2cd(const QW2cd* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void VScale2cd(QW2cd* d, const QW2cd* s, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void VAdd2cd(QW2cd* d, const QW2cd* a, const QW2cd* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct O2cd { u8 pad[4]; u32 f4; u32 f8; u8 pad2[12]; u32 f24; f32 f28; u8 pad3[4]; f32 range; u8 pad4[95]; u8 on; u8* target; };
QW2cd* func_0016c028(u8*) asm("func_0016c028");
void func_002cd3e0(O2cd*, u8*) asm("func_002cd3e0");
void func_002cd428(O2cd*, QW2cd*) asm("func_002cd428");
void func_002cd290(O2cd* o, u8* from, u8* to) asm("func_002cd290");
void func_002cd290(O2cd* o, u8* from, u8* to) {
    if (!o->on) return;
    if (o->target == to) return;
    if (!to) {
        to = o->target;
        if (!to) return;
    }
    o->target = to;
    o->f4 = 0;
    o->f8 = 0;
    o->f28 = -2.0f;
    o->f24 = 0;
    QW2cd* a = func_0016c028(from);                          
    QW2cd* b = func_0016c028(to);                          
    QW2cd d, p, e;
    VSub2cd(&d, b, a);
    f32 len = VLen2cd(&d);
    if (o->range + o->range < len) {
        VScale2cd(&e, &d, (len - 110.0f) / len);
        VAdd2cd(&p, &e, a);
        func_002cd3e0(o, from);
        func_002cd428(o, &p);
        func_002cd3e0(o, to);
    }
}
}  // namespace n002cd290

// ---- 002cd3e0 from src/anon/batch_w209.cpp
namespace n002cd3e0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V209 {
    f32 x, y, z, w;
    V209() {}
    V209(const V209& o) { QCOPY(this, &o); }
    V209& operator=(const V209& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
V209* func_0016c028(u32) asm("func_0016c028");
void func_002cd428(u32, V209*) asm("func_002cd428");
void func_002cd3e0(u32 a, u32 b) asm("func_002cd3e0");
void func_002cd3e0(u32 a, u32 b) {
    V209 t(*func_0016c028(b));                          
    func_002cd428(a, &t);
}
}  // namespace n002cd3e0

// ---- 002cd428 from src/anon/batch_w86.cpp
namespace n002cd428 {
struct Obj;
struct Obj;
struct Obj;
struct Obj;
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Length(const QWord& v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
struct Pt { QWord pos; QWord dir; };
struct Obj { u8 p0[8]; s32 f8; };
QWord* func_002cb828(Obj*, QWord*) asm("func_002cb828");
Pt* func_002cb8e0(Obj*) asm("func_002cb8e0");
s32 func_002cb920(Obj*) asm("func_002cb920");
void func_002cd428(Obj* o, QWord* p) asm("func_002cd428");
void func_002cd428(Obj* o, QWord* p)
{
    if (!o->f8) {
        func_002cb828(o, p);                       
        return;
    }
    QWord d = Sub(func_002cb8e0(o)->pos, *p);
    if (Length(d) < 100.0f) return;
    Pt* t = func_002cb8e0(o);
    QWord* q = func_002cb828(o, p);                       
    t->dir = Sub(*q, t->pos);
    t->dir.v[3] = func_002cb920(o) - 1;
}
}  // namespace n002cd428

// ---- 002cd518 from src/anon/batch_w323.cpp
namespace n002cd518 {
#define QCOPY323(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV323 {
    f32 x, y, z, w;
    QV323() {}
    QV323(const QV323& o) { QCOPY323(this, &o); }
    QV323& operator=(const QV323& o) { if (this != &o) QCOPY323(this, &o); return *this; }
    QV323 operator-(const QV323& o) const {
        QV323 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    QV323 operator*(f32 k) const {
        QV323 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 dot(const QV323& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 lensq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    void normalize0() {
        asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "$8", "$f0", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
#define QCOPY4_323(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QM323 {
    QV323 r[4];
    QM323() {}
    QM323(const QM323& o) { QCOPY4_323(this, &o); }
    QM323& operator=(const QM323& o) { if ((u32)this != (u32)&o) QCOPY4_323(this, &o); return *this; }
    QV323 operator*(const QV323& v) const {
        QV323 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    QM323 operator*(const QM323& b) const {
        QM323 o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
extern u8 D_0033cc50 asm("D_0033cc50");
void func_001070e8(void*) asm("func_001070e8");
struct Cam323 {
    u32 vt;
    QM323 m;
    QV323 a, b, c;
    f32 d;
    Cam323(const Cam323& o) : m(o.m), a((vt = (u32)&D_0033cc50, o.a)), b(o.b), c(o.c), d(o.d) {}
    ~Cam323() { func_001070e8(this); }
} __attribute__((aligned(16)));
f32 func_002cd518(u32, f32* out, const QV323* a, const QV323* b, const QV323* c) asm("func_002cd518");
f32 func_002cd518(u32, f32* out, const QV323* a, const QV323* b, const QV323* c) {
    QV323 d1 = *c - *b;
    QV323 d2 = *a - *b;
    if (d1.dot(d2) < 0.0f) {
        *out = d2.length();
        return 0.0f;
    }
    f32 len = d1.normalize();
    QM323 m;
    m.r[0] = d1 * d1.x;
    m.r[1] = d1 * d1.y;
    m.r[2] = d1 * d1.z;
    d2.w = 0.0f;
    QV323 p = m * d2;
    f32 pl = p.length();
    if (len < pl) {
        *out = (*a - *c).length();
        return 1.0f;
    }
    f32 h = d2.lensq() - p.lensq();
    if (h <= 0.0f) *out = 0.0f;
    else *out = __builtin_sqrtf(h);
    return pl / len;
}
}  // namespace n002cd518

// ---- 002cd770 from src/anon/batch_w99.cpp
namespace n002cd770 {
struct V10ce {
    f32 x, y, z, w;
    V10ce& operator=(const V10ce& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline V10ce operator-(const V10ce& a, const V10ce& b)
{
    V10ce r;
    asm(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct V13f6 {
    f32 x, y, z, w;
    V13f6() {}
    V13f6(const V13f6& o) { QCOPY(this, &o); }
    V13f6& operator=(const V13f6& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
    V13f6& operator*=(f32 s)
    {
        asm("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V13f6& operator+=(const V13f6& o)
    {
        asm("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V13f6 operator-(const V13f6& a, const V13f6& b)
{
    V13f6 r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V13f6 operator*(const V13f6& v, f32 s)
{
    V13f6 r;
    asm(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
struct V1791 {
    f32 x, y, z, w;
    V1791& operator=(const V1791& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline V1791 operator*(const V1791& v, f32 s)
{
    V1791 r;
    asm("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec2cd { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline Vec2cd operator*(const Vec2cd& v, f32 s)
{
    Vec2cd r;
    asm("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
static inline Vec2cd operator+(const Vec2cd& a, const Vec2cd& b)
{
    Vec2cd r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
Vec2cd func_002cd770(void*, Vec2cd* p, Vec2cd* q, f32 t) asm("func_002cd770");
Vec2cd func_002cd770(void*, Vec2cd* p, Vec2cd* q, f32 t)
{
    f32 t2 = t * t;
    f32 t3 = t2 * t;
    f32 h00 = t3 + t3 - 3.0f * t2 + 1.0f;
    f32 h01 = -2.0f * t3 + 3.0f * t2;
    f32 h10 = t3 - (t2 + t2) + t;
    f32 h11 = t3 - t2;
    Vec2cd r = p[0] * h00 + q[0] * h01 + p[1] * h10 + q[1] * h11;
    r.w = 1.0f;
    return r;
}
}  // namespace n002cd770

// ---- 002cd878 from src/anon/auto80_199_queue.cpp
namespace n002cd878 {
u32 func_002cd878(u32 a0, u32 a1, s32 a2, f32 a3) asm("func_002cd878");
u32 func_002cd878(u32 a0, u32 a1, s32 a2, f32 a3) {
    u32 s3 = a0;
    u32 s1 = a1;
    s32 s0 = a2;
    f32 f20 = a3;

    u32 s2 = func_002cb890(s1, (u32)s0);                    

    s0 = s0 + 1;
    s32 t7 = *(s32*)(s1 + 8);
    s32 rem = s0 % t7;
    u32 v0 = func_002cb890(s1, (u32)rem);                    

    func_002cd770(f20, s3, s1, s2, v0);
    return s3;
}
}  // namespace n002cd878

// ---- 002cd910 from src/anon/batch_w13.cpp
namespace n002cd910 {
void func_002cd878(void*, u32, s32, f32) asm("func_002cd878");
void* func_002cd910_f(void*, u32, f32) asm("_Z13func_002cd910f");
void* func_002cd910_f(void* r, u32 a1, f32 f) {
    s32 i = (s32)f;
    func_002cd878(r, a1, i, f - (f32)i);
    return r;
}
}  // namespace n002cd910

// ---- 002cd950 from src/anon/batch_w257.cpp
namespace n002cd950 {
#define QCOPY257(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV257 {
    f32 x, y, z, w;
    QV257() {}
    QV257(const QV257& o) { QCOPY257(this, &o); }
} __attribute__((aligned(16)));
static inline QV257 operator*(const QV257& a, f32 k) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline QV257 operator+(const QV257& a, const QV257& b) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV257 operator-(const QV257& a, const QV257& b) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
QV257 func_002cd950(void* self, f32 t, const QV257* p, const QV257* q) asm("func_002cd950");
QV257 func_002cd950(void* self, f32 t, const QV257* p, const QV257* q) {
    f32 t2 = t * t;
    f32 h00 = t2 * 6.0f - t * 6.0f;
    f32 h01 = t2 * -6.0f + t * 6.0f;
    f32 h10 = t2 * 3.0f - t * 4.0f + 1.0f;
    f32 h11 = t2 * 3.0f - (t + t);
    return p[0] * h00 + q[0] * h01 + p[1] * h10 + q[1] * h11;
}
}  // namespace n002cd950

// ---- 002cda68 from src/anon/auto80_199_queue.cpp
namespace n002cda68 {
u32 func_002cda68(u32 a0, u32 a1, s32 a2, f32 a3) asm("_Z13func_002cda68jjif");
u32 func_002cda68(u32 a0, u32 a1, s32 a2, f32 a3) {
    u32 s3 = a0;
    u32 s1 = a1;
    s32 s0 = a2;
    f32 f20 = a3;

    u32 s2 = func_002cb890(s1, (u32)s0);                    

    s0 = s0 + 1;
    s32 t7 = *(s32*)(s1 + 8);
    s32 rem = s0 % t7;
    u32 v0 = func_002cb890(s1, (u32)rem);                    

    func_002cd950(f20, s3, s1, s2, v0);
    return s3;
}
}  // namespace n002cda68

// ---- 002cdb00 from src/anon/auto80_199_queue.cpp
namespace n002cdb00 {
u32 func_002cda68(u32 a0, u32 a1, s32 a2, f32 a3) asm("_Z13func_002cda68jjif");
u32 func_002cdb00(u32 a0, u32 a1, f32 a2) asm("_Z13func_002cdb00jjf");
u32 func_002cdb00(u32 a0, u32 a1, f32 a2) {
    f32 f20 = a2;
    u32 s0 = a1;
    u32 s1 = a0;

    f32 f0 = floorf(a0);
    f20 = f20 - f0;
    s32 t6 = (s32)f0;

    func_002cda68(s1, s0, t6, f20);
    return s1;
}
}  // namespace n002cdb00

// ---- 002cdb60 from src/anon/batch_w277.cpp
namespace n002cdb60 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
QWord func_002cd770(void* p, const QWord* lo, const QWord* hi, f32 t) asm("func_002cd770");
void func_002cd518(void* p, f32* d, void* q, QWord* a, QWord* b) asm("func_002cd518");
f32 func_002cdb60(void* p, f32* out, void* q, const QWord* lo, const QWord* hi, f32 t0, f32 t1) asm("func_002cdb60");
f32 func_002cdb60(void* p, f32* out, void* q, const QWord* lo, const QWord* hi, f32 t0, f32 t1) {
    QWord a = *lo;
    QWord b = *hi;
    f32 d0, d1, mid, r;
    s32 i;
    for (i = 0; i < 33; i++) {
        mid = (t0 + t1) * 0.5f;
        QWord c = func_002cd770(p, lo, hi, mid);
        func_002cd518(p, &d0, q, &a, &c);
        func_002cd518(p, &d1, q, &c, &b);
        if (d0 < d1) { t1 = mid; b = c; r = d1; }
        else { t0 = mid; a = c; r = d0; }
    }
    *out = (t0 + t1) * 0.5f;
    return r;
}
}  // namespace n002cdb60

// ---- 002cdcd8 from src/anon/batch_w2414_nsa.cpp
namespace n002cdcd8 {
typedef struct V2cdcd8 { f32 x, y, z, w; } __attribute__((aligned(16))) V2cdcd8;
typedef struct Path2cdcd8 { u8 pad0[8]; s32 count; u8 pad1[12]; f32 pos; u8 pad2[132 - 28]; u8 forward; } Path2cdcd8;
V2cdcd8* func_002cb890(Path2cdcd8*, s32) asm("func_002cb890");
f32 func_002cdb60(Path2cdcd8*, f32*, V2cdcd8*, V2cdcd8*, V2cdcd8*, f32, f32) asm("func_002cdb60");
static inline f32 vdist(V2cdcd8* a, V2cdcd8* b)
{
    V2cdcd8 r;
    f32 d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(a), "r"(b) : "memory");
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(d) : "r"(&r) : "$8");
    return d;
}
struct V165ad8 {
    f32 x, y, z, w;
    V165ad8& operator=(const V165ad8& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
f32 func_002cdcd8(Path2cdcd8* p, s32* idx, f32* t, V2cdcd8* pos, f32 maxDist) asm("func_002cdcd8");
f32 func_002cdcd8(Path2cdcd8* p, s32* idx, f32* t, V2cdcd8* pos, f32 maxDist)
{
    V2cdcd8* v;
    s32 last;
    *idx = (s32)p->pos;
    *t = p->pos - (f32)*idx;
    if (p->forward && 0.9999f < *t) {
        (*idx)++;
        *t = 0.0f;
    } else if (!p->forward && *t < 0.0001f) {
        (*idx)--;
        *t = 1.0f;
    }
    last = p->count - 1;
    if (*idx >= last) {
        *idx = last;
        v = func_002cb890(p, last);
    } else if (*idx < 0) {
        *idx = 0;
        *t = 0.0f;
        v = func_002cb890(p, *idx);
    } else {
        f32 lo, hi, bestT, best;
        s32 bestIdx, n;
        if (p->forward) {
            lo = *t;
            hi = 1.0f;
        } else {
            hi = *t;
            lo = 0.0f;
        }
        bestT = *t;
        best = -1.0f;
        bestIdx = *idx;
        for (n = 0; n < 2; n++) {
            V2cdcd8* a = func_002cb890(p, *idx);
            V2cdcd8* b = func_002cb890(p, (*idx + 1) % p->count);
            f32 d = func_002cdb60(p, t, pos, a, b, lo, hi);
            if (best < 0.0f || d < best) {
                best = d;
                bestIdx = *idx;
                bestT = *t;
            }
            if (p->forward) *idx = *idx + 1; else *idx = *idx - 1;
            if (*idx < 0 || *idx >= p->count - 1) break;
            *t = 0.0f;
            hi = 1.0f;
            lo = *t;
        }
        *idx = bestIdx;
        *t = bestT;
        if (best < maxDist) return best;
        return -1.0f;
    }
    return vdist(pos, v);
}
}  // namespace n002cdcd8

// ---- 002cdfb0 from src/anon/batch_w3865_nsa.cpp
namespace n002cdfb0 {
typedef struct V2cdfb0 { f32 x, y, z, w; } __attribute__((aligned(16))) V2cdfb0;
typedef struct Path2cdfb0 { u8 pad0[8]; s32 count; u8 pad1[4]; u8 loop; u8 pad1b[7]; f32 pos; u8 pad2[132 - 28]; u8 forward; } Path2cdfb0;
V2cdfb0* func_002cb890(Path2cdfb0*, s32) asm("func_002cb890");
f32 func_002cdb60(Path2cdfb0*, f32*, V2cdfb0*, V2cdfb0*, V2cdfb0*, f32, f32) asm("func_002cdb60");
f32 func_002cdcd8(Path2cdfb0*, s32*, f32*, V2cdfb0*, f32) asm("func_002cdcd8");
f32 func_002cdfb0(Path2cdfb0* p, s32* idx, f32* t, V2cdfb0* pos, f32 maxDist) asm("func_002cdfb0");
f32 func_002cdfb0(Path2cdfb0* p, s32* idx, f32* t, V2cdfb0* pos, f32 maxDist)
{
    f32 lo, hi, best;
    s32 firstIdx, nextIdx;
    f32 nextT, lo2, hi2;
    V2cdfb0* a;
    V2cdfb0* b;
    V2cdfb0* c;
    V2cdfb0* e;
    if (!p->loop) return func_002cdcd8(p, idx, t, pos, maxDist);
    *idx = (s32)p->pos;
    *t = p->pos - (f32)*idx;
    if (p->forward && 0.9999f < *t) {
        *idx = (*idx + 1) % p->count;
        *t = 0.0f;
    } else if (!p->forward && *t < 0.0001f) {
        *idx = (*idx + p->count - 1) % p->count;
        *t = 1.0f;
    }
    if (p->forward) {
        lo = *t;
        hi = 1.0f;
    } else {
        hi = *t;
        lo = 0.0f;
    }
    a = func_002cb890(p, *idx);
    b = func_002cb890(p, (*idx + 1) % p->count);
    lo = func_002cdb60(p, t, pos, a, b, lo, hi);                                              
    firstIdx = *idx;
    hi = *t;
    *t = 0.0f;
    lo2 = 0.0f;
    hi2 = 1.0f;
    if (p->forward) *idx = (*idx + 1) % p->count;
    else *idx = (*idx + p->count - 1) % p->count;
    c = func_002cb890(p, *idx);
    e = func_002cb890(p, (*idx + 1) % p->count);
    best = func_002cdb60(p, t, pos, c, e, lo2, hi2);
    nextIdx = *idx;
    nextT = *t;
    if (lo < best) {
        best = lo;
        *idx = firstIdx;
        *t = hi;
    } else {
        *idx = nextIdx;
        *t = nextT;
    }
    if (best < maxDist) return best;
    return -1.0f;
}
}  // namespace n002cdfb0

// ---- 002ce2a0 (was whole asm in batch_w3877.s; const parameters fix the outIdx spill order)
namespace n002ce2a0 {
struct V2ce2a0 {
    f32 x, y, z, w;
    V2ce2a0() {}
    V2ce2a0(const V2ce2a0& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2ce2a0& operator=(const V2ce2a0& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Path2ce2a0 { u8 pad0[8]; s32 count; u8 pad1[4]; u8 loop; };
V2ce2a0* func_002cb890(Path2ce2a0*, s32) asm("func_002cb890");
f32 func_002cd518(Path2ce2a0*, f32*, V2ce2a0*, V2ce2a0*, V2ce2a0*) asm("func_002cd518");
void func_002cd770(V2ce2a0*, Path2ce2a0*, V2ce2a0*, V2ce2a0*, f32) asm("func_002cd770");
f32 func_002ce2a0(Path2ce2a0* p, s32* outIdx, f32* outT, V2ce2a0* pos) asm("func_002ce2a0");
f32 func_002ce2a0(Path2ce2a0* const p, s32* const outIdx, f32* const outT, V2ce2a0* const pos)
{
    f32 best = 0.0f;
    f32 bestT = 0.0f;
    s32 bestIdx = 0;
    if (p->count == 2) {
        V2ce2a0* a = func_002cb890(p, 0);
        *outT = func_002cd518(p, &best, pos, a, func_002cb890(p, 1));
        *outIdx = 0;
        return best;
    }
    s32 n = p->count - !p->loop;
    for (s32 i = 0; i < n; ) {
        s32 next = i + 1;
        s32 j = next % p->count;
        f32 dist;
        V2ce2a0* a = func_002cb890(p, i);
        V2ce2a0* b = func_002cb890(p, j);
        f32 t = func_002cd518(p, &dist, pos, a, b);
        if (i == 0 || (0.0f <= dist && dist < best)) {
            bestT = t;
            bestIdx = i;
            best = dist;
        }
        i = next;
    }
    *outIdx = bestIdx;
    if (bestT <= 0.0001f || 0.9999f <= bestT) {
        *outT = bestT;
        return best;
    }
    f32 lo = 0.0f, hi = 1.0f;
    V2ce2a0* a = func_002cb890(p, bestIdx);
    V2ce2a0* b = func_002cb890(p, (bestIdx + 1) % p->count);
    V2ce2a0 A(*a), B(*b), M;
    for (s32 k = 0; k < 33; k++) {
        f32 mid = (lo + hi) * 0.5f;
        f32 d1, d2;
        func_002cd770(&M, p, a, b, mid);
        func_002cd518(p, &d1, pos, &A, &M);
        func_002cd518(p, &d2, pos, &M, &B);
        if (d1 < d2) {
            hi = mid;
            B = M;
        } else {
            lo = mid;
            A = M;
        }
    }
    *outT = (lo + hi) * 0.5f;
    return best;
}
}  // namespace n002ce2a0

// ---- 002ce598 from src/anon/batch_w258.cpp
namespace n002ce598 {
struct V4w258 {
    f32 x, y, z, w;
    V4w258() {}
    V4w258(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V4w258& operator=(const V4w258& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V4w258 operator-(const V4w258& b) const {
        V4w258 d;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(this), "r"(&b) : "memory");
        return d;
    }
    V4w258 operator*(f32 k) const {
        V4w258 d;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(this), "f"(k) : "$8", "memory");
        return d;
    }
    f32 len() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Seg258 { V4w258 a, b; };
struct Rail258 { u8 p0[8]; s32 n; u8 p1[12]; f32 f18; u8 p2[12]; f32 f28; u8 p3[4]; V4w258 a0, b0, a1, b1; };
f32 func_002ce2a0(Rail258*, s32*, f32*, u32) asm("func_002ce2a0");
Seg258* func_002cb890(Rail258*, s32) asm("func_002cb890");
f32 wtarget_002ce598(Rail258* p, u32 a1) asm("_Z16wtarget_002ce598jjjj");
f32 wtarget_002ce598(Rail258* p, u32 a1) {
    s32 i;
    f32 fr;
    V4w258* pa = &p->a0;
    f32 r = func_002ce2a0(p, &i, &fr, a1);
    Seg258* s = func_002cb890(p, i);                    
    *pa = s->a;
    p->b0 = s->b;
    V4w258* pb = &p->a1;
    s = func_002cb890(p, (i + 1) % p->n);                    
    *pb = s->a;
    p->b1 = s->b;
    p->f18 = (f32)i + fr;
    p->f28 = (*pb - *pa).len();
    return r;
}
}  // namespace n002ce598

// ---- 002ce6b8 from src/anon/batch_w1952_nsa.cpp
namespace n002ce6b8 {
struct W1952V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void W1952Set(W1952V* d, const W1952V* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct W1952Vec { W1952V v; W1952Vec& operator=(const W1952Vec& o) { W1952Set(&v, &o.v); return *this; } };
struct W1952Seg { W1952Vec a, b; };
static inline __attribute__((always_inline)) W1952Vec operator-(const W1952Vec& a, const W1952Vec& b)
{ W1952Vec r; asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) f32 W1952Len(const W1952Vec& a)
{ f32 r; asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a) : "$8", "memory"); return r; }
struct W1952Path {
    u8 pad[8];
    s32 n;                
    u8 pad2[12];
    f32 t;                 
    u8 pad3[12];
    f32 len;               
    u8 pad4[4];
    W1952Seg s0;           
    W1952Seg s1;           
};
f32 func_002cdfb0(W1952Path*, s32*, f32*, W1952Vec*) asm("func_002cdfb0");
f32 func_002ce2a0(W1952Path*, s32*, f32*, W1952Vec*) asm("func_002ce2a0");
W1952Seg* func_002cb890(W1952Path*, s32) asm("func_002cb890");
W1952Vec func_002cd770(W1952Path*, W1952Seg*, W1952Seg*, f32) asm("func_002cd770");
f32 func_002ce6b8(W1952Path* p, W1952Vec* out, f32 lim) asm("func_002ce6b8");
f32 func_002ce6b8(W1952Path* p, W1952Vec* out, f32 lim) {
    s32 i;
    f32 f;
    f32 r = -1.0f;
    if (p->n >= 3) r = func_002cdfb0(p, &i, &f, out);
    if (r < 0.0f || r >= lim) r = func_002ce2a0(p, &i, &f, out);
    p->s0 = *func_002cb890(p, i);
    p->s1 = *func_002cb890(p, (i + 1) % p->n);
    p->t = (f32)i + f;
    W1952Vec d = p->s1.a - p->s0.a;
    p->len = W1952Len(d);
    W1952Vec q = func_002cd770(p, &p->s0, &p->s1, f);
    *out = q;
    return r;
}
}  // namespace n002ce6b8

// ---- 002ce870 from src/anon/auto80_199_queue.cpp
namespace n002ce870 {
void func_002cd878(void*, u32, s32, f32) asm("_Z13func_002cd878Pvjif");
void func_002ce870(u8* a0, u32 a1) asm("_Z13func_002ce870Phj");
void func_002ce870(u8* a0, u32 a1) {
    u8* s0 = a0;
    u32 s1 = a1;

    f32 f12;
    if (*(u8*)(a0 + 16) != 0) {
        f12 = (f32)(*(s32*)(a0 + 8));
    } else {
        s32 t7 = *(s32*)(a0 + 8);
        t7 = t7 - 1;
        f12 = (f32)t7;
    }

    f32 f20 = func_00106558(f12);
    u32 v0 = func_001064a8(2);                        

    s32 t6 = (s32)f20;
    *(u8*)(s0 + 132) = (v0 != 0);

    f32 ftmp = (f32)t6;
    f32 frac = f20 - ftmp;

    u8 tmp[16];
    func_002cd878(tmp, (u32)s0, t6, frac);
    func_0016ace0(s1, tmp);

    *(f32*)(s0 + 24) = f20;
}
}  // namespace n002ce870

// ---- 002ce910 from src/anon/batch_w1669.cpp
namespace n002ce910 {
struct W1669Pair { u32 a, b; };
extern W1669Pair D_01e2be18 asm("D_01e2be18");
void wtarget_002ce910(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ce910jjjj");
void wtarget_002ce910(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) { D_01e2be18.b = 0; D_01e2be18.a = 0; }
}
}  // namespace n002ce910

// ---- 002ce938 from src/anon/tiny_wrappers_more.cpp
namespace n002ce938 {
u32 func_002ce910(u32, u32, u32, u32) asm("_Z13func_002ce910jjjj");
u32 func_002ce938(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ce938jjjj");
u32 func_002ce938(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002ce910(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002ce938

