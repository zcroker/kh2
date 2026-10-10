#include "../common/types.h"

// 16-byte vector copied with lq/sq (VU0 code in func_0018a318)
struct W253Vec {
    f32 x, y, z, w;
    W253Vec() {}
    W253Vec(const W253Vec& o) { asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W253Vec& operator=(const W253Vec& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {
extern u32 D_00341788[8];
extern s32 D_003417a8;
void u_tail4(u32 a0, u8 a1) asm("_Z16u_tail4_001128d0jjjj");
void u_tail4(u32 a0, u8 a1) {
    s32 i;
    for (i = 0; i < D_003417a8; i++)
        if (D_00341788[i] == a0) break;
    s32 n = D_003417a8;
    if (i < n) {
        if (a1 == 0) {
            s32 j;
            for (j = i + 1; j < n; j++) D_00341788[j - 1] = D_00341788[j];
            D_003417a8--;
        } else {
            s32 j;
            for (j = i + 1; j < n; j++) D_00341788[j - i - 1] = D_00341788[j];
            D_003417a8 = D_003417a8 - i - 1;
        }
    }
}


u32 func_00313bc0(f32);
void wt239(u8* a0, f32 r, f32 g, f32 b, f32 a) asm("_Z16wtarget_00239fd0jjjj");
void wt239(u8* a0, f32 r, f32 g, f32 b, f32 a) {
    *(f32*)(a0 + 280) = r;
    *(f32*)(a0 + 284) = g;
    *(f32*)(a0 + 288) = b;
    *(f32*)(a0 + 292) = a;
    if (r != 1.0f || g != 1.0f || b != 1.0f || a != 1.0f) {
        *(u32*)(a0 + 184) |= 4;
        *(u32*)(a0 + 208) = func_00313bc0(r * 128.0f) | (func_00313bc0(g * 128.0f) << 8) | (func_00313bc0(b * 128.0f) << 16) | (func_00313bc0(a * 128.0f) << 24);
    } else {
        *(u32*)(a0 + 184) &= ~4;
    }
}


extern u32 D_003638d0;
extern u32 D_003512e8;
void func_00169398(void*, u32, void*, s32, s32, f32);
void func_0016bd60(void*, s32);
static inline f32 rf() { D_003638d0 = D_003638d0 * 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f; }
static inline f32 rnd2(f32 lo, f32 w) { return lo + rf() * w; }
void func_001bf270(u8* a0, u32* a1, s32 a2, u32 a3, f32 f) {
    func_00169398(a0, *a1, a1, 4, a2, rnd2(-3.1415927f, 6.2831855f));
    *(u32*)(a0 + 1416) |= 0x40000;
    *(u32*)(a0 + 2484) = a3;
    *(f32*)(a0 + 2488) = f;
    *(f32*)(a0 + 60) = f;
    *(u32*)a0 = (u32)&D_003512e8;
    *(u32*)(a0 + 264) |= 2;
    *(u32*)(a0 + 2528) = 0;
    *(u32*)(a0 + 2532) = 0;
    *(u32*)(a0 + 2536) = 0;
    func_0016bd60(a0, 12);
}

extern u32 D_0034b250;
extern u32 D_00348698;
extern u32 D_0034b268;
extern u32 D_0034b278;
struct VObj { void (**vt)(...); };
typedef void (*DtorFn)(u8*);
void func_0031dee8(u8* a0) {
    *(u32*)a0 = (u32)&D_0034b250;
    u8* end = a0 + 4144;
    *(u32*)end = (u32)&D_00348698;
    if (a0 + 2608) {
        u8* e = end;
    t1:
        if (a0 + 2608 != e) { e -= 256; (*(DtorFn*)*(u32*)e)(e); goto t1; }
    }
    if (a0 + 1072) {
        u8* e = a0 + 2608;
    t2:
        if (a0 + 1072 != e) { e -= 256; (*(DtorFn*)*(u32*)e)(e); goto t2; }
    }
    if (a0 + 544) {
        u8* e = a0 + 1072;
    t3:
        if (a0 + 544 != e) { e -= 528; (*(DtorFn*)*(u32*)e)(e); goto t3; }
    }
    *(u32*)(a0 + 16) = (u32)&D_00348698;
    *(u32*)a0 = (u32)&D_0034b268;
    VObj* o = (VObj*)D_0034b278;
    ((void (*)(VObj*, u8*))o->vt[1])(o, a0);
}

f32 func_002f8870(f32);  // fabsf
static inline W253Vec vsub(const f32* a, const f32* b) {
    W253Vec r;
    asm volatile(".set noreorder\n\tlqc2 vf1,0(%1)\n\tlqc2 vf2,0(%2)\n\tvsub.xyzw vf1,vf1,vf2\n\tsqc2 vf1,0(%0)\n\t.set reorder" : : "r"(&r), "r"(a), "r"(b) : "memory");
    return r;
}
static inline f32 vdot3m(const W253Vec& a, const W253Vec& b) {
    f32 r;
    asm volatile("lqc2 vf1,0(%1)\n\tlqc2 vf2,0(%2)\n\tvmul.xyz vf1,vf1,vf2\n\tvaddy.x vf1,vf1,vf1\n\tvaddz.x vf1,vf1,vf1\n\tqmfc2 $8,vf1\n\tmtc1 $8,%0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
s32 func_0018a318(u8* a0, u8* a1) {
    W253Vec d;
    d = vsub((f32*)(a1 + 16), (f32*)(a0 + 16));
    f32 dy;
    dy = func_002f8870(d.y);  // fabsf
    f32 r1 = *(f32*)(a1 + 8);
    f32 r0 = *(f32*)(a0 + 8);
    if (r0 + r1 <= dy) return 0;
    f32 lim;
    if (r1 < dy) {
        dy = (dy - r1) / r0;
        lim = __builtin_sqrtf(1.0f - dy * dy) * *(f32*)(a0 + 4) + *(f32*)(a1 + 4);
    } else {
        lim = *(f32*)(a0 + 4) + *(f32*)(a1 + 4);
    }
    d.y = 0;
    if (vdot3m(d, d) < lim * lim) return 1;
    return 0;
}
}
