#include "../common/types.h"
inline void* operator new(__SIZE_TYPE__, void* p) { return p; }

// --- 0016e3e0: function-local statics (guards and atexit dtors spelled out)
struct W1816Vs {
    f32 x, y, z, w;
    W1816Vs() {}
    W1816Vs(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    W1816Vs& operator=(const W1816Vs& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
} __attribute__((aligned(16)));
struct W1816Mx { W1816Vs r[4]; };
struct W1816Hd { W1816Vs* v; };
static inline W1816Vs W1816MulV(const W1816Mx* m, const W1816Vs* v) {
    W1816Vs r;
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(m), "r"(v) : "memory");
    return r;
}

// --- 00232398
struct W1816E { void* p; u16 pad; u8 flag; char name[25]; };
struct W1816M { u32 x; s16 count; s16 pad; W1816E e[1]; };
struct W1816O { s32 a; s32 b; s32 c; s32 d; s32 e; u8 pad[28]; char name[16]; };

extern "C" {
extern s8 D_004f6370;
extern W1816Vs D_004f6380;
extern s8 D_004f6378;
extern W1816Vs D_004f6390;
void func_0016e8a8(void);
void func_0016e8b0(void);
void func_002fd188(void (*)(void));
void func_0011b6a8(W1816Mx*);
void* func_001dc648(W1816Vs*);
void func_0011b7b0(W1816Mx*, void*);
// o->v = (object matrix) * (0,0,1,0), through a function-local static.
void func_0016e3e0(W1816Hd* o) {
    if (!D_004f6370) {
        new (&D_004f6380) W1816Vs(0.0f, 0.0f, 1.0f, 0.0f);
        D_004f6370 = 1;
        func_002fd188(func_0016e8a8);
    }
    if (!D_004f6378) {
        D_004f6378 = 1;
        func_002fd188(func_0016e8b0);
    }
    W1816Mx m;
    func_0011b6a8(&m);
    func_0011b7b0(&m, func_001dc648(o->v));
    D_004f6390 = W1816MulV(&m, &D_004f6380);
    o->v = &D_004f6390;
}

extern W1816M* D_0035de4c;
void func_00232590(void);
W1816O* func_00227a28(void);
void func_002feee8(char*, const char*);
void func_00232398(W1816M* m) {
    s32 i;
    func_00232590();
    D_0035de4c = m;
    for (i = 0; i < m->count; i++) { m->e[i].p = 0; m->e[i].flag = 0; }
    for (i = 0; i < m->count; i++) {
        W1816O* o = func_00227a28();
        o->a = 3; o->b = 1; o->d = -1; o->e = -1;
        o->name[0] = 0;
        func_002feee8(o->name, m->e[i].name);
        m->e[i].p = o;
    }
}
}
