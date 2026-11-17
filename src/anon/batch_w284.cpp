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
void func_002c9998(u8* p);  // 0x2c9998: moved to src/anon/unit_002c9998.cpp


void func_002c9b38(u8* p);  // 0x2c9b38: moved to src/anon/unit_002c9998.cpp


// ---- 002c6cd8: static initializer for five vectors
extern V4w284 D_01e2bdc0, D_01e2bdd0, D_01e2bde0, D_01e2bdf0, D_01e2be00;
void wtarget_002c6cd8(u32, u32, u32, u32) asm("_Z16wtarget_002c6cd8jjjj");
// 002c6cd8: moved to src/anon/unit_002c6420.cpp (linked unit)

// ---- 002cbd20: step *t along a path until the travelled distance reaches dist
void func_002cd910(QV284*, u8*, f32);  // split_float_call
f32 fabsf(f32);  // fabsf
s32 func_002cb920(u8*);  // get_sum_fields_minus1
s32 wtarget_002cbd20(u8*, f32*, f32) asm("_Z16wtarget_002cbd20jjjj");
s32 wtarget_002cbd20(u8* obj, f32* t, f32 dist);  // 0x002cbd20: definition moved into src/taito/path.cpp
}
