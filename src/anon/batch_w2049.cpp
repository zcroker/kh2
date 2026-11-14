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

void func_0018e420(W2049Ctx** ctx, u8* obj, W2049Hit* hit, void* src, u64 mask);  // 0x0018e420: definition moved into src/anon/unit_0018d050.cpp
}
