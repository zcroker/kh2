// Built with -O2 -fno-strict-aliasing (nsa). The VU0 matrix/vector helpers are inline asm (gcc cannot emit VU0 ops).
// mulMV pins its matrix and output pointers to t4/t3 so the loop-preheader copies come out in the original order.
#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }

struct V {
    f32 x, y, z, w;
    V() {}
    V(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void set(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V& operator=(const V& r) {
        if (this != &r) asm volatile(".set noreorder\n\t""lq $8,0(%1)\n\tsq $8,0(%0)""\n\t.set reorder" : : "r"(this), "r"(&r) : "$8", "memory");
        return *this;
    }
    V& operator+=(const V& r) {
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%0)\n\tlqc2 $vf2,0(%1)\n\tvadd.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)""\n\t.set reorder" : : "r"(this), "r"(&r) : "memory");
        return *this;
    }
    V& operator*=(f32 s) {
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%0)\n\tmfc1 $8,%1\n\tqmtc2 $8,$vf2\n\tvmulx.wxyz $vf1,$vf1,$vf2x\n\tsqc2 $vf1,0(%0)""\n\t.set reorder" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V operator-(const V& r) const {
        V t;
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)""\n\t.set reorder" : : "r"(&t), "r"(this), "r"(&r) : "memory");
        return t;
    }
    f32 normalize() {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tvmul.xyz $vf2,$vf1,$vf1\n\tvaddy.x $vf2,$vf2,$vf2y\n\tvaddz.x $vf2,$vf2,$vf2z\n\tvsqrt Q,$vf2x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tvaddq.x $vf2,$vf0,Q\n\tmtc1 $8,%0\n\tvnop\n\tvdiv Q,$vf0w,$vf2x\n\tvwaitq\n\tvmulq.xyz $vf1,$vf1,Q\n\tsqc2 $vf1,0(%1)\n\t.set reorder"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 length() const {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\tvsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0\n\t.set reorder"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 dot(const V& r) const {
        f32 d;
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvmul.xyz $vf1,$vf1,$vf2\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\tqmfc2 $8,$vf1\n\tmtc1 $8,%0""\n\t.set reorder"
            : "=f"(d) : "r"(this), "r"(&r) : "$8", "memory");
        return d;
    }
    void cross(const V& a, const V& b) {
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf3,$vf0,$vf0\n\tvopmula.xyz ACC,$vf1,$vf2\n\tvopmsub.xyz $vf3,$vf2,$vf1\n\tsqc2 $vf3,0(%0)""\n\t.set reorder" : : "r"(this), "r"(&a), "r"(&b) : "memory");
    }
} __attribute__((aligned(16)));

struct M {
    V r[4];
    M() {}
    M& operator=(const M& s) {
        if (this != &s)
            asm volatile(".set noreorder\n\t""lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\tsq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)""\n\t.set reorder" : : "r"(this), "r"(&s) : "$8","$9","$10","$11","memory");
        return *this;
    }
    M operator*(const M& b) const {
        M t;
        asm volatile(".set noreorder\n\t"
"lqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
"lqc2 $vf5,0(%2)\n\tlqc2 $vf6,16(%2)\n\tlqc2 $vf7,32(%2)\n\tlqc2 $vf8,48(%2)\n\t"
"vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\tvmaddw.wxyz $vf5,$vf4,$vf5w\n\t"
"vmulax.wxyz ACC,$vf1,$vf6x\n\tvmadday.wxyz ACC,$vf2,$vf6y\n\tvmaddaz.wxyz ACC,$vf3,$vf6z\n\tvmaddw.wxyz $vf6,$vf4,$vf6w\n\t"
"vmulax.wxyz ACC,$vf1,$vf7x\n\tvmadday.wxyz ACC,$vf2,$vf7y\n\tvmaddaz.wxyz ACC,$vf3,$vf7z\n\tvmaddw.wxyz $vf7,$vf4,$vf7w\n\t"
"vmulax.wxyz ACC,$vf1,$vf8x\n\tvmadday.wxyz ACC,$vf2,$vf8y\n\tvmaddaz.wxyz ACC,$vf3,$vf8z\n\tvmaddw.wxyz $vf8,$vf4,$vf8w\n\t"
"sqc2 $vf5,0(%0)\n\tsqc2 $vf6,16(%0)\n\tsqc2 $vf7,32(%0)\n\tsqc2 $vf8,48(%0)""\n\t.set reorder"
            : : "r"(&t), "r"(this), "r"(&b) : "memory");
        return t;
    }
    V operator*(const V& v) const;
    void translate(const V& r) {
        asm volatile(".set noreorder\n\tlqc2 $vf1,48(%0)\n\tlqc2 $vf2,0(%1)\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,48(%0)\n\t.set reorder" : : "r"(this), "r"(&r) : "memory");
    }
    void invert() {
        asm volatile(".set noreorder\n\t"
"lq $8,0(%0)\n\tlq $9,16(%0)\n\tlq $10,32(%0)\n\tqmfc2 $11,$vf0\n\tlqc2 $vf4,48(%0)\n\t"
"pextlw $12,$9,$8\n\tpextuw $13,$9,$8\n\tpextlw $14,$11,$10\n\tpextuw $15,$11,$10\n\t"
"pcpyld $8,$14,$12\n\tpcpyud $9,$12,$14\n\tpcpyld $10,$15,$13\n\t"
"qmtc2 $8,$vf1\n\tqmtc2 $9,$vf2\n\tqmtc2 $10,$vf3\n\t"
"vmulax.xyz ACC,$vf1,$vf4x\n\tvmadday.xyz ACC,$vf2,$vf4y\n\tvmaddz.xyz $vf4,$vf3,$vf4z\n\tvsub.xyz $vf4,$vf0,$vf4\n\t"
"sq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsqc2 $vf4,48(%0)""\n\t.set reorder"
            : : "r"(this) : "$8","$9","$10","$11","$12","$13","$14","$15","memory");
    }
};

static inline void mulMV(V* o, const M* m, const V* v) {
    register const M* rm asm("$12") = m; register V* ro asm("$11") = o;
    asm volatile(".set noreorder\n\t"
"lqc2 $vf5,0(%2)\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
"vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\tvmaddw.wxyz $vf5,$vf4,$vf5w\n\t"
"sqc2 $vf5,0(%0)""\n\t.set reorder" : : "r"(ro), "r"(rm), "r"(v) : "memory");
}
inline V M::operator*(const V& v) const {
    V t;
    mulMV(&t, this, &v);
    return t;
}
extern "C" {

void func_0011b6a8(M* m);
void func_002fd188(void (*f)(void));
void func_00135750(void);
extern s8 D_003b8ae0;
extern V D_003b8af0[3];

static inline s32 shadowSize(s32 mode) {
    switch (mode) {
    case 0: return 64;
    case 1: return 128;
    case 2: return 256;
    }
    return 0;
}

// builds the light view and projection matrices of a shadow camera looking at a box of 8 points
void func_00134df8(V* pos, V* pts, M* view, M* tex, s32 mode) {
    if (!D_003b8ae0) {
        V* base = D_003b8af0;
        V* p = base;
        s32 n = 2;
        { V* t = p; t->set(1.0f, 0.0f, 0.0f, 0.0f); } p++; n--;
        { V* t = p; t->set(0.0f, 1.0f, 0.0f, 0.0f); } p++; n--;
        { V* t = p; t->set(0.0f, 0.0f, 1.0f, 0.0f); } p++; n--;
        D_003b8ae0 = 1;
        func_002fd188(func_00135750);
    }
    V c;
    c = pts[0];
    for (s32 i = 1; i < 8; i++) c += pts[i];
    c *= 0.125f;
    M m;
    func_0011b6a8(&m);
    m.r[2] = c - *pos;
    f32 dist = m.r[2].normalize();
    f32 best = m.r[2].dot(D_003b8af0[0]);
    if (best < 0.0f) best = -best;
    s32 bi = 0;
    for (s32 i = 1; i < 3; i++) {
        f32 d = m.r[2].dot(D_003b8af0[bi]);
        if (d < 0.0f) d = -d;
        if (d < best) { best = d; bi = i; }
    }
    m.r[0].cross(D_003b8af0[bi], m.r[2]);
    m.r[0].normalize();
    m.r[1].cross(m.r[2], m.r[0]);
    m.r[1].normalize();
    m.translate(*pos);
    m.invert();
    f32 mx = 0.0f, my = 0.0f;
    for (s32 i = 0; i < 8; i++) {
        V v;
        v = m * pts[i];
        f32 x = v.x * dist / v.z;
        f32 y = v.y * dist / v.z;
        if (x < 0.0f) x = -x;
        if (y < 0.0f) y = -y;
        if (mx < x) mx = x;
        if (my < y) my = y;
    }
    M p;
    func_0011b6a8(&p);
    p.r[0].x = dist;
    p.r[1].y = dist;
    p.r[2].z = 0.0f;
    p.r[2].w = 1.0f;
    p.r[3].z = 1.0f;
    p.r[3].w = 0.0f;
    f32 nearz = 1.0f;
    f32 farz = dist + (pts[6] - pts[0]).length();
    f32 w = shadowSize(mode);
    f32 h = shadowSize(mode);
    f32 sx = mx + mx;
    f32 sy = my + my;
    f32 w2 = w - 2.0f;
    f32 h2 = h - 2.0f;
    M s;
    func_0011b6a8(&s);
    s.r[0].x = w2 / sx;
    s.r[1].y = h2 / sy;
    s.r[2].z = farz * 16769999.0f / (farz - nearz);
    s.r[3].x = 2048.0f;
    s.r[3].y = 2048.0f;
    s.r[3].z = (farz + -16770000.0f) / (farz - nearz);
    *view = s * p * m;
    func_0011b6a8(&s);
    s.r[0].x = w2 / (sx * w);
    s.r[1].y = h2 / (sy * h);
    s.r[2].z = farz * 16769999.0f / (farz - nearz);
    s.r[3].x = 0.5f;
    s.r[3].y = 0.5f;
    s.r[3].z = (farz + -16770000.0f) / (farz - nearz);
    *tex = s * p * m;
}

}
