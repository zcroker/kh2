#include "../common/types.h"
struct V4_w2050a { f32 x, y, z, w; V4_w2050a() {} } __attribute__((aligned(16)));
struct M4_w2050a {
    V4_w2050a r[4];
    M4_w2050a() {}
    M4_w2050a(const M4_w2050a& o) { asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory"); }
} __attribute__((aligned(16)));
static inline void Zero_w2050a(V4_w2050a* v) { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "memory"); }
static inline void Inverse_w2050a(M4_w2050a* m)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
        "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
        "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
        "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
        "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
        "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
        "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
        "vdiv Q, $vf0w, $vf8x\n\t"
        "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
        "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
        "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
        "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
        "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
        "vmulq.wxyz $vf1, $vf1, Q\n\tvmulq.wxyz $vf2, $vf2, Q\n\tvmulq.wxyz $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
        "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)"
        : : "r"(m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
static inline void ApplyPoint_w2050a(V4_w2050a* o, const M4_w2050a* m, const V4_w2050a* v)
{
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)"
        : : "r"(o), "r"(m), "r"(v) : "memory");
}
static inline f32 Normalize_w2050a(V4_w2050a* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Node_w2050a;
struct Sub_w2050a;
struct Obj_w2050a { V4_w2050a ax[3]; V4_w2050a pos[3]; u8 sub[16]; };
extern "C" {
void func_00134d78(Node_w2050a*, V4_w2050a*);
void func_00134db0(Node_w2050a*, V4_w2050a*);
void func_00135670(void*);

void func_00134730(Obj_w2050a* self, const M4_w2050a& src, Node_w2050a* a, Node_w2050a* b, Node_w2050a* c)
{
    M4_w2050a m(src);
    V4_w2050a v;
    V4_w2050a t;
    Node_w2050a* n[3] = { a, b, c };
    Zero_w2050a(&self->ax[0]);
    V4_w2050a* a1 = &self->ax[1];
    Zero_w2050a(a1);
    V4_w2050a* a2 = &self->ax[2];
    Zero_w2050a(a2);
    Inverse_w2050a(&m);
    for (s32 i = 0; i < 3; i++) {
        if (n[i]) {
            func_00134d78(n[i], &v);
            ApplyPoint_w2050a(&t, &m, &v);
            t.y = -t.y;
            t.z = -t.z;
            t.w = 0;
            Normalize_w2050a(&t);
            s32 o = i * 4;
            *(f32*)((u8*)self + o) = t.x;
            *(f32*)((u8*)a1 + o) = t.y;
            *(f32*)((u8*)a2 + o) = t.z;
            func_00134db0(n[i], &self->pos[i]);
        } else {
            Zero_w2050a(&self->pos[i]);
        }
    }
    func_00135670(self->sub);
}
}

extern "C" {
typedef void (*VFn_w2050b)(void*);
s32 func_00281be0(void);
s32 func_00139d78(s32);
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_001b1e70(void);
s32 func_00293148(s32);
void func_002362b0(u8*, s32);
void func_001386e0(u8*, s32, s32, u8*, s32, s32);
s32 func_0023aa98(s32);
s32 func_0023f1b0(s32);
s32 func_0023c3e0(s32, s32, s32);
void func_001396b0(u8*);
void func_0031a260(u8*, s32);
void func_0031ac78(u8*, s32);
u64 func_00313b80(f32);
u64 func_00314190(u64, u64) __attribute__((const));
f32 func_003144b0(u64);
extern s32 D_0035f270;
extern s32 D_0035f274;
extern s32 D_0035f278;
extern s32 D_0035f27c;
extern s32 D_0035f284;
extern s32 D_0035f28c;
extern u8* D_0035f290;
extern u8* D_0035f29c;
extern s16 D_0035f2a0[3];
extern s16 D_0035f2a8[2];

void func_002818b8(s32 arg0) {
    s32 n;
    u8* o;
    if (func_00281be0() != 0) {
        (*(VFn_w2050b*)(*(u8**)D_0035f290 + 0x14))(D_0035f290);
        return;
    }
    if (D_0035f274 == 0 && func_00139d78(D_0035f28c) == 0) {
        func_0028d8c0(D_0035f28c, D_0035f270, D_0035f278, D_0035f27c, D_0035f284, D_0035f2a0[0], D_0035f2a0[2], 0);
    }
    s32 r = func_001b1e70();
    func_002362b0(D_0035f29c, func_00293148(arg0));
    D_0035f29c[0x190] = 1;
    func_001386e0(D_0035f290, D_0035f270, r, D_0035f29c, D_0035f2a8[0], 0);
    if (D_0035f274 == 0) {
        n = func_0023aa98(D_0035f28c + 0x18);
        u8* p = D_0035f290;
        *(s32*)(p + 0x18c) = D_0035f28c;
        func_001396b0(p);
        if (*(s32*)(p + 0x18c) != 0) {
            *(s32*)(p + 0x190) = 0;
            func_001396b0(p);
            if (*(s32*)(p + 0x190) != 0) func_0031a260(p, 0);
        }
    } else {
        n = func_0023aa98(func_0023c3e0(func_0023f1b0(D_0035f284), D_0035f2a0[2], 0));
        o = D_0035f290;
        *(s32*)(o + 0x190) = func_0023c3e0(func_0023f1b0(D_0035f284), D_0035f2a0[2], 0);
        func_001396b0(o);
        if (*(s32*)(o + 0x190) != 0) {
            *(s32*)(o + 0x18c) = 0;
            func_001396b0(o);
            if (*(s32*)(o + 0x18c) != 0) func_0031ac78(o, 0);
        }
    }
    if (n <= 0) n = 100;
    u8* s = D_0035f290 + 0x18;
    *(u32*)(s + 0xb8) |= 8;
    u64 d = func_00313b80((f32)n);
    u8* q = D_0035f290;
    *(f32*)(q + 0x180) = func_003144b0(func_00314190(d, 0x4059000000000000ULL));
    D_0035f290[0x195] = 1;
    func_001396b0(D_0035f290);
}
}

#define QC_w2050c(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V4_w2050c {
    f32 x, y, z, w;
    V4_w2050c() {}
    V4_w2050c(const V4_w2050c& o) { QC_w2050c(this, &o); }
    V4_w2050c& operator=(const V4_w2050c& o) { if (this != &o) QC_w2050c(this, &o); return *this; }
    V4_w2050c operator-(const V4_w2050c& o) const {
        V4_w2050c r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    V4_w2050c& sub(const V4_w2050c& p, const V4_w2050c& q) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&p), "r"(&q) : "memory");
        return *this;
    }
    void normalize(const V4_w2050c& v) { QC_w2050c(this, &v); normalize(); }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    V4_w2050c normalized() const { V4_w2050c r = *this; r.normalize(); return r; }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct TCam_w2050c {
    u8 pad0[0x44];
    s32 target;      // 0x44
    u8 pad48[0x38];
    V4_w2050c eye;          // 0x80
};

static inline __attribute__((always_inline)) V4_w2050c dirTo_w2050c(const V4_w2050c& from, const V4_w2050c& to, f32* dist) {
    V4_w2050c a; a = from;
    V4_w2050c b; b = to;
    V4_w2050c c; c = a;
    V4_w2050c e; e = b - a;
    e.w = 1.0f;
    c.w = 1.0f;
    V4_w2050c r = e;
    r.normalize();
    *dist = e.length();
    return r;
}
extern "C" {
extern u32 D_0034aa30;
extern f32 D_00349e10;
void func_00159d30(TCam_w2050c*, const V4_w2050c*, V4_w2050c*, f32);
void func_00159ef8(TCam_w2050c*);
V4_w2050c* func_0016c028(s32);
s32 func_00159dc0(V4_w2050c, u32*);
s32 func_00159f50(TCam_w2050c*, s32);
s32 func_00159f90(TCam_w2050c*, s32);
s32 func_0013fda0(TCam_w2050c*);
void func_0013fdc8(TCam_w2050c*);
void func_001400b0(f32, TCam_w2050c*);
void func_00159ce0(TCam_w2050c*, V4_w2050c*);
void func_0015a118(TCam_w2050c*);

void func_0015a260(TCam_w2050c* self, V4_w2050c* target, f32 t) {
    V4_w2050c cur;
    func_00159d30(self, target, &cur, t);
    func_00159ef8(self);
    V4_w2050c pos = *func_0016c028(self->target);
    pos.y -= 100.0f;
    s32 id0 = func_00159dc0(*target, &D_0034aa30);
    s32 id1 = func_00159dc0(pos, &D_0034aa30);
    s32 vis0 = func_00159f50(self, id0);
    s32 vis1 = func_00159f50(self, id1);
    func_0013fda0(self);
    func_0013fdc8(self);
    V4_w2050c dir;
    V4_w2050c a; a = cur;
    V4_w2050c b; b = pos;
    V4_w2050c c; c = a;
    V4_w2050c e; e = dir.sub(b, a);
    e.w = 1.0f;
    c.w = 1.0f;
    dir.normalize(e);
    if (e.length() > 300.0f && dir.y > 0.5f) {
        func_00159ce0(self, &cur);
    } else {
        if (vis0 == 0 && vis1 == 0) func_001400b0(D_00349e10, self);
        s32 id;
        if (id0 != 0) {
            id = id0;
        } else {
            if (id1 == 0) goto set_eye;
            id = id1;
        }
        if (func_00159f90(self, id)) {
            self->eye = cur;
            func_0015a118(self);
        }
        return;
    }
set_eye:
    self->eye = cur;
}
}
