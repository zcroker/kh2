#include "../common/types.h"
struct NoTail { ~NoTail() {} };
struct V4b { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void nrm(V4b* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
}
struct V7b {
    f32 x, y, z, w;
    V7b() {}
    V7b(const V7b& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V7b& operator=(const V7b& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    V7b& operator+=(const V7b& o) { asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline V7b scl(const V7b& a, f32 n, f32 d) {
    V7b r;
    asm volatile(".set noreorder\n\tnop\n\tnop\n\tdiv.s $f0, %2, %3\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, $f0\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(n), "f"(d) : "$8", "memory");
    return r;
}
struct V7e {
    f32 x, y, z, w;
    V7e() {}
    V7e(const V7e& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V7e& operator=(const V7e& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 len() const { f32 r; asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory"); return r; }
} __attribute__((aligned(16)));
static inline V7e operator-(const V7e& a, const V7e& b) {
    V7e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
extern "C" {
f32 sinf(f32);
f32 cosf(f32);
// 0017d1d8: moved to src/anon/unit_0017c400.cpp

extern s32 D_01D48CB0;
extern u8 D_00351EB8;
extern u8 D_00352560;
extern u8 D_00350E48;
s32 func_0019ba60(void*);
void func_0016cab8(void*);
void func_0016c7d8(void*);
void func_001dde40(void*);
void func_001b1c10(void*, f32);
void func_0016c640(s32);
void func_001d4570(void*, void*);
void func_00170950(void*);
s32 func_001b5858(void*);
s32 func_001b5cb8(void*);
void func_001c8d98(void*, s32);
void func_001d1ed0(void*);
void func_001d2048(void*);
void func_001b0188(void*);
void func_001ddd88(void*);

void func_001b4f40(u8* p);  // 0x001b4f40: definition moved into src/anon/unit_001b2780.cpp
s32 func_0019bb98(void*);
f32 func_0016a0a0(void*);
void func_001b7958(void*, V7b*);  // add_vec_to_records
void func_001b7b10(u8* a, u8* b, V7b* src, V7b* dst);  // 0x001b7b10: definition moved into src/anon/unit_001b6a50.cpp
s32 func_001bfca0(void*);
void func_001991a8(s32, s32);
V7e* func_0016c028(void*);  // obj_get_attach_or_alt
V7e func_0016be98(void*);
void func_0016bd60(void*, s32);
void* func_0016a070(void*);
void* func_001a3018(void*, void*, s32);
void func_001a3188(void*, void*, s32);
void func_001bf378(u8* p, u8* t);  // 0x001bf378: definition moved into src/anon/unit_001bc568.cpp
extern u8* D_00347F80;
extern u8 D_0035E190;
extern u8 D_00347F98;
extern u8 D_00347E60;
extern u8 D_0035DFB0;
extern u8 D_0035E01C;
extern u8 D_0035DFE8;
void func_0031a838(void*);
void func_00239700(void*);
void* func_00224930(void);
void func_002294c8(void*, s32, void*, void*);
typedef u8* (*AF)(void*, s32, s32);
static inline u8* alloc(s32 n) {
    void* a = *(void**)(D_00347F80 + 20);
    return (**(AF**)a)(a, n, 0);
}
static inline void elems(u8* e) {
    s32 i;
    for (i = 6; i != -1; i--) {
        *(void**)e = &D_00347F98;
        func_0031a838(e + 12);
        *(void**)e = &D_00347E60;
        func_00239700(e + 24);
        e += 408;
    }
}
void func_00228618(void);  // 00228618: moved to src/anon/unit_00228618.cpp (linked unit)
void func_00237280(void*, void*);
void func_002373a8(void*);
void func_00239fd0(void*, f32, f32, f32, f32);
void func_00239d50(void*, f32);
void func_00239da0(void*, f32);
void func_00239df0(void*, f32);
void func_00239e60(void*, f32, f32, f32);
union U9 { u32 u; s32 s; u8 c; };
#define R(o) (((U9*)(d + (o)))->s)
#undef W
#define W(o) (*(u32*)(p + (o)))
s32 func_00239988(u8* p, u8* d);  // 0x00239988: definition moved into src/anon/unit_00239988.cpp
#undef W
#undef R
}
