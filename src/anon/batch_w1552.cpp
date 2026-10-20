#include "../common/types.h"

struct V4_df040 {
    f32 x, y, z, w;
    V4_df040() {}
    V4_df040(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    V4_df040(const V4_df040& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4_df040& operator=(const V4_df040& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));

struct E_25158 { u8 d[16]; ~E_25158() {} } __attribute__((aligned(16)));
struct H_25158 { E_25158 a[4]; };

extern "C" {

extern u8 D_0032f054;
struct JS_198040 { u8 pad[0x26]; u16 h[7]; };
JS_198040* func_001a8b28(void);
u16 func_00198040(s32 a0) {
    JS_198040* p = func_001a8b28();
    u16 r;
    if (a0 == 1) {
        switch (D_0032f054) {
        case 1: r = p->h[1]; break;
        default: r = p->h[0]; break;
        case 2: r = p->h[2]; break;
        case 3: r = p->h[3]; break;
        case 4: r = p->h[4]; break;
        case 5: r = p->h[5]; break;
        case 6: r = p->h[6]; break;
        }
    } else r = 0;
    return r;
}

/* heap block free + coalesce with free neighbours */
struct Blk_225fa0 { Blk_225fa0* next; Blk_225fa0* prev; u8 used; u8 pad[3]; s32 size; };
void func_00225fa0(void* a0, void* p) {
    Blk_225fa0* b = (Blk_225fa0*)((u8*)p - 0x40);
    b->used = 0;
    Blk_225fa0* lo = b;
    while (lo->prev && !lo->prev->used) lo = lo->prev;
    Blk_225fa0* hi = b;
    while (hi->next && !hi->next->used) hi = hi->next;
    Blk_225fa0* n = hi->next;
    if (n) n->prev = lo;
    lo->next = n;
    lo->size = (u8*)hi + hi->size - (u8*)lo;
}

void func_0016aef0(u8*, V4_df040*);
V4_df040* func_0016c028(u8*);
void func_0016ace0(u8*, V4_df040*);
void func_002deda8(u8*, u8*);
void func_002df040(u8* a0, u8* a1) {
    V4_df040 v(0.0f, 0.0f, -1.0f, 0.0f);
    func_0016aef0(a1, &v);
    v = *func_0016c028(a1);
    v.z = *(f32*)(a0 + 0x14);
    func_0016ace0(a1, &v);
    func_002deda8(a0, a1);
}

/* libgcc fp-bit unpack_d (double) */
struct Fpn_3147a0 { s32 cls; u32 sign; s32 normal_exp; s32 pad; u64 ll; };
void func_003147a0(u64* src, Fpn_3147a0* dst) {  // dbl_unpack
    u64 fraction = *src & ((((u64)1) << 52) - 1);
    s32 exp = ((s32)(*src >> 52)) & 0x7ff;
    s32 sign = (s32)(*src >> 63);
    dst->sign = sign;
    if (exp == 0) {
        dst->cls = 2;
    } else if (exp == 0x7ff) {
        if (fraction == 0) {
            dst->cls = 4;
        } else {
            if (fraction & ((u64)1 << 51)) dst->cls = 1;
            else dst->cls = 0;
            dst->ll = fraction;
        }
    } else {
        dst->normal_exp = exp - 1023;
        dst->cls = 3;
        dst->ll = (fraction << 8) | ((u64)1 << 60);
    }
}

extern u32 D_00361d00;
extern u32 D_0034e8b8;
extern u32 D_0034ee08;
void func_00319f88(void*);
void func_0019f9a8(void*);
void func_001c0248(void*);
void func_00319fb0(void*);
void AREA_Free_25158(void*) asm("_ZN4AREA4FreeEPv");
void func_00325158(u8* p) {
    *(u32**)p = &D_00361d00;
    ((H_25158*)(p + 0xb70))->~H_25158();
    *(u32**)p = &D_0034e8b8;
    func_00319f88(p + 0xb08);
    *(u32**)p = &D_0034ee08;
    func_0019f9a8(p + 0xa08);
    func_001c0248(p + 0xa50);
    func_00319fb0(p);
    AREA_Free_25158(p);
}

f32 func_0017d130(f32);
void func_0017c400(u8*, s32);
struct J_17c430 { u8 pad[0xd0]; f32 d0, d4, d8, dc; };
void func_0017c430(J_17c430* a0, f32 x) {
    if (0.0f <= x) {
        a0->d0 = 0.0f;
        a0->d8 = 0.0f;
        a0->dc = -x;
        a0->d4 = func_0017d130(x);
    } else {
        a0->dc = 0.0f;
        a0->d0 = __builtin_sqrtf(x * -2.0f / 0.40816325f);
        a0->d8 = x;
        a0->d4 = 0.0f;
    }
    func_0017c400((u8*)a0, 1);
}

}
