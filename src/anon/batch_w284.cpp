#include "../common/types.h"
struct V4w284 { f32 x, y, z, w; };
static inline void set4w284(V4w284* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }

// ---- 002c9998 / 002c9b38: destructor (two identical ABI copies)
struct E284 { void (**vt)(E284*); u8 pad[404]; };
// shared 16-byte vector helpers (lq/sq copy, VU0 sub/length)
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
extern "C" {
extern u8 D_00361e10[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8* D_00361e00;
void func_00170950(u32);
void func_00239870(u8*);
void func_0023c098(u8*);  // set_vtbl_36eae8_then_call
void func_002369f0(u8*);  // set_vtbl_36eac8_then_call
#define ARR(b, e) if (p + (b)) { E284* q = (E284*)(p + (e)); top##b: if ((E284*)(p + (b)) == q) goto out##b; q--; q->vt[3](q); goto top##b; } out##b:
void func_002c9998(u8* p) {
    *(void**)p = D_00361e10;
    u32 x = *(u32*)(p + 9604); asm volatile("" ::: "memory");
    func_00170950(x);
    D_00361e00 = (D_00361e00 == p) ? 0 : D_00361e00;
    ARR(8376, 9600)
    ARR(4704, 8376)
    ARR(3480, 4704)
    ARR(2256, 3480)
    ARR(1032, 2256)
    *(u32*)(p + 624) = (u32)D_00347e60;
    func_00239870(p + 648);
    *(u32*)(p + 624) = (u32)D_00347f98;
    *(u32*)(p + 188) = (u32)D_00347e60;
    func_00239870(p + 212);
    *(u32*)(p + 188) = (u32)D_00347f98;
    *(u32*)(p + 28) = (u32)D_0035eb98;
    func_0023c098(p + 76);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 52);  // set_vtbl_36eac8_then_call
    *(u32*)(p + 28) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
}

void func_002c9b38(u8* p) {
    *(void**)p = D_00361e10;
    u32 x = *(u32*)(p + 9604); asm volatile("" ::: "memory");
    func_00170950(x);
    D_00361e00 = (D_00361e00 == p) ? 0 : D_00361e00;
    ARR(8376, 9600)
    ARR(4704, 8376)
    ARR(3480, 4704)
    ARR(2256, 3480)
    ARR(1032, 2256)
    *(u32*)(p + 624) = (u32)D_00347e60;
    func_00239870(p + 648);
    *(u32*)(p + 624) = (u32)D_00347f98;
    *(u32*)(p + 188) = (u32)D_00347e60;
    func_00239870(p + 212);
    *(u32*)(p + 188) = (u32)D_00347f98;
    *(u32*)(p + 28) = (u32)D_0035eb98;
    func_0023c098(p + 76);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 52);  // set_vtbl_36eac8_then_call
    *(u32*)(p + 28) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
}

// ---- 002c6cd8: static initializer for five vectors
extern V4w284 D_01e2bdc0, D_01e2bdd0, D_01e2bde0, D_01e2bdf0, D_01e2be00;
void wtarget_002c6cd8(u32, u32, u32, u32) asm("_Z16wtarget_002c6cd8jjjj");
void wtarget_002c6cd8(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) { f32 z = 0.0f; set4w284(&D_01e2bdc0, z, -500.0f, z, 1.0f); }
    if (b == 0xffff && a == 1) set4w284(&D_01e2bdd0, 0.0f, -2300.0f, -3000.0f, 1.0f);
    if (b == 0xffff && a == 1) set4w284(&D_01e2bde0, 0.0f, -1760.0f, -3180.0f, 1.0f);
    if (b == 0xffff && a == 1) set4w284(&D_01e2bdf0, 0.0f, -790.0f, -8580.0f, 1.0f);
    if (b == 0xffff && a == 1) set4w284(&D_01e2be00, 0.0f, -2500.0f, -2000.0f, 1.0f);
}

// ---- 002cbd20: step *t along a path until the travelled distance reaches dist
void func_002cd910(QV284*, u8*, f32);  // split_float_call
f32 func_002f8870(f32);  // fabsf
s32 func_002cb920(u8*);  // get_sum_fields_minus1
s32 wtarget_002cbd20(u8*, f32*, f32) asm("_Z16wtarget_002cbd20jjjj");
s32 wtarget_002cbd20(u8* obj, f32* t, f32 dist) {
    QV284 a;
    f32 acc = 0.0f;
    f32 t0 = *t;
    s32 i = 0;
    func_002cd910(&a, obj, t0);  // split_float_call
    while (acc < dist) {
        QV284 b, d;
        func_002cd910(&b, obj, *t);  // split_float_call
        vsub284(&d, &b, &a);
        f32 prev = acc;
        acc += vlen284(&d);
        if (dist <= acc) {
            if (func_002f8870(prev - dist) < func_002f8870(acc - dist)) *t = t0;
            break;
        }
        a = b;
        t0 = *t;
        *t = t0 + 5e-05f;
        if ((f32)(func_002cb920(obj) + 1) <= *t) *t = *t - (f32)(func_002cb920(obj) + 1);  // get_sum_fields_minus1
        i++;
        if (i >= 1024) break;
    }
    return 1;
}
}
