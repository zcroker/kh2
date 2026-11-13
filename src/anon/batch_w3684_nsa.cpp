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

// 00134df8: moved to src/anon/unit_00134668.cpp

}
