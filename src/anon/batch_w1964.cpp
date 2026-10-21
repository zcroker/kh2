#include "../common/types.h"

extern "C" {
struct E2 {
    f32 x, y, z;
    union { f32 w; u8 flag; };
    E2() {}
    E2(const E2& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    E2& operator=(const E2& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M2 { f32 m[4][4]; } __attribute__((aligned(16)));
struct C2 { u8 pad[16]; M2 mtx; };
C2* func_00106a60(s32);

static inline __attribute__((always_inline)) void apply(E2* d, const M2* m, const E2* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(m), "r"(s) : "memory");
}

void wtarget_001e2450(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001e2450jjjj");
void wtarget_001e2450(u32 a0, u32 a1, u32 a2, u32 a3) {
    E2* e = (E2*)a1;
    s32 n = a2;
    f32 d[n];
    C2* c = func_00106a60(0);
    s32 i, j;
    for (s32 k = 0; k < n; k++) {
        if (e[k].flag) {
            E2 t(e[k]);
            t.w = 1.0f;
            apply(&t, &c->mtx, &t);
            d[k] = t.z;
        } else {
            d[k] = 0;
        }
    }
    for (i = 0; i < n - 1; i++) {
        s32 b = i;
        f32 mx = d[i];
        for (j = i + 1; j < n; j++) {
            if (e[j].flag && mx < d[j]) {
                mx = d[j];
                b = j;
            }
        }
        E2 t;
        t = e[b];
        e[b] = e[i];
        e[i] = t;
        f32 f = d[b];
        d[b] = d[i];
        d[i] = f;
    }
}
}

extern "C" {
struct V5 { f32 x, y, z, w; V5() {} ~V5() {} } __attribute__((aligned(16)));
struct P5 { f32 x, y, z, d; } __attribute__((aligned(16)));
struct X5 { u8 b[32]; } __attribute__((aligned(16)));
struct G5 { u8 p[28]; u16 start, end; };
struct I5 { u8 p[12]; u16 start, end; u8 flag; u8 q[3]; };
struct T5 { u8 p[10]; u16 idx; u8 q[4]; };
struct O5 {
    s32 f0;
    G5* grp;    // 4
    I5* item;   // 8
    T5* tri;    // c
    s32 f10, f14;
    P5* pl;     // 18
    s32 f1c;
    s32 n;      // 20
};
void func_00141988(O5*, T5*, X5*);
void func_001626e0(X5*, V5*);
s32 func_001466b0(void*, V5*);
void func_00146ab0(u8*, P5*, V5*);

static inline __attribute__((always_inline)) f32 dot(const P5* a, const P5* b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}

void func_00165f70(O5* o, P5* p, u8* out, s32* cnt, void* a4) {
    V5 poly[8];
    X5 x;
    s32 n = o->n;
    for (s32 i = 0; i < n; i++) {
        G5* g = &o->grp[i];
        s32 je = g->end;
        s32 j = g->start;
        for (; j < je; j++) {
            I5* it = &o->item[j];
            if (it->flag) {
                s32 ke = it->end;
                s32 k = it->start;
                for (; k < ke; k++) {
                    T5* t = &o->tri[k];
                    P5* pl = &o->pl[t->idx];
                    if (dot(p, pl) + pl->d < 0.0f) continue;
                    func_00141988(o, t, &x);
                    func_001626e0(&x, poly);
                    if (func_001466b0(a4, poly)) {
                        func_00146ab0(out, p, poly);
                        out += 80;
                        (*cnt)++;
                    }
                }
            }
        }
    }
}
}
