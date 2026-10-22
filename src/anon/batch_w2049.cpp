#include "../common/types.h"
extern "C" {
struct W2049Q {
    union { struct { f32 x, y, z, w; }; u8 b[16]; };
    W2049Q() {}
    W2049Q(const W2049Q& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2049Q& operator=(const W2049Q& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2049Fx { u8 pad0[11]; u8 count; u8 pad0c[0x24 - 0xc]; u8 slot; u8 pad25[0x2d - 0x25]; u8 spread; };
struct W2049Hit { u8 pad0[0x18]; u32 flags; u8 pad1c[4]; W2049Fx* fx; };
struct W2049List { u32 n; };
struct W2049Ctx { u8 pad0[0x24]; W2049List* list; };
extern W2049Q D_0034eef0;
extern s32 D_003638d0;
extern f32 D_0036ccd0;
W2049Q func_0018e160(W2049Ctx**, void*);
void func_0018e108(W2049Q*, W2049Hit*);
s32 func_001a3b48(void*, u64, W2049Q*, s32, s32, s32);
void* func_001a3a78(void);
s32 func_001de168(void*, s32, s32, s32, s32, s32);
W2049Q* func_001dc5f8(s32);
W2049Q* func_001dc648(s32);
void func_0017d050(W2049Q*, W2049Hit*);
void func_001c2c00(s32);
u64 func_00312db8(u64, u64);

void func_0018e420(W2049Ctx** ctx, u8* obj, W2049Hit* hit, void* src, u64 mask)
{
    W2049Fx* fx = hit->fx;
    {
    W2049Q v = func_0018e160(ctx, src);
    func_0018e108(&v, hit);
    if ((*ctx)->list->n) {
        s32 n = fx->count;
        if (__builtin_expect(n != 0, 1)) {
            s32 id;
            if (hit->flags & 4) {
                id = func_001de168(func_001a3a78(), 18, 1, 1, 10000, 0);
                *func_001dc5f8(id) = D_0034eef0;
            } else {
                u32 k = fx->spread;
                if (k) {
                    s32 seed = D_003638d0 * 0x10dcd;
                    u64 bit = 0x100000000ULL;
                    s32 sh = n - 1;
                    D_003638d0 = seed;
                    sh += (s32)func_00312db8((u32)seed, func_00312db8((u64)(k - 1) + bit, (u64)k));
                    bit <<= sh;
                    mask |= bit;
                } else {
                    mask |= 0x100000000ULL << (n - 1);
                }
                id = func_001a3b48((*ctx)->list, mask, &D_0034eef0, 1, 1, 10000);
            }
            if (id) {
                W2049Q* m = func_001dc648(id);
                func_0017d050(&v, hit);
                *m = v;
                func_001c2c00(id);
            }
        }
    }
    }
    u32* lst = (u32*)(obj + 0x80);
    if (*lst && fx->slot && !(*(u32*)(obj + 0x108) & 0x200) && !(hit->flags & 4)) {
        W2049Q v = D_0034eef0;
        v.y -= 1.0f;
        mask = (0x100000000ULL << (fx->slot - 1)) | 0x200;
        func_001a3b48(lst, mask, &v, 1, 1, 10000);
    }
}
}
