// Linked unit 0x001f0868-0x001f0a38 (ppp oscillator programs; one namespace per old matched source, gap functions written for the unit).
#include "../common/types.h"
#include "../tozawa/menu_sound.hpp"

// 001f0868 (was src/anon/auto200_999.cpp)
namespace n001f0868 {
/*TARGET 001f0868*/



void func_001f0868(u32 a0, u32 a1) asm("_Z13func_001f0868jj");



void func_001f0868(u32 a0, u32 a1) {
    f32 f1 = *(f32 *)(a0 + 8);
    f32 z = 0.0f;
    *(volatile f32 *)(a1 + 4) = f1;
    f32 f2 = *(volatile f32 *)(a0 + 20);
    *(volatile u32 *)a1 = a0;
    *(f32 *)(a1 + 16) = f2;
    *(volatile f32 *)(a1 + 8) = z;
    *(f32 *)(a1 + 24) = z;
    *(volatile f32 *)(a1 + 20) = z;
    *(volatile f32 *)(a1 + 12) = z;
}
}  // namespace n001f0868

// 001f0898 (gap, written for the unit)
namespace n001f0898 {
struct XfCtx2 { u8 pad[12]; s32* offs; };
void func_001f0898(u8* base, XfCtx2* c) asm("func_001f0898");
void func_001f0898(u8* base, XfCtx2* c) {
    *(u32*)(base + c->offs[2] + 160) = 0;
}
}  // namespace n001f0898

// 001f08b0 (gap, written for the unit)
namespace n001f08b0 {
struct Osc { u32 on; f32 pos; f32 vel; f32 acc; f32 pos2; f32 vel2; f32 acc2; };
struct XfCtx2 { u8 pad[12]; s32* offs; };
void func_001f08b0(u8* base, XfCtx2* c) asm("func_001f08b0");
void func_001f08b0(u8* base, XfCtx2* c) {
    Osc* o = (Osc*)(base + c->offs[2] + 160);
    o->vel = o->acc = o->vel2 = o->acc2 = 0.0f;
}
}  // namespace n001f08b0

// 001f08d8 (gap, written for the unit)
namespace n001f08d8 {
void func_001f08d8(void) asm("func_001f08d8");
void func_001f08d8(void) {}
}  // namespace n001f08d8

// 001f08e0 (was src/anon/batch_w95.cpp)
namespace n001f08e0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct XfCtx2 { u8 pad[12]; u32* offs; };
struct Osc { u32 on; f32 pos; f32 vel; f32 acc; f32 pos2; f32 vel2; f32 acc2; };
struct OscIn { u32 id; u32 pad[2]; f32 a, b; u32 pad2; f32 c, d; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u32 D_01d9eab4 asm("D_01d9eab4");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_001f0868(OscIn*, Osc*) asm("func_001f0868");
f32 func_002f8b00(f32, f32) asm("func_002f8b00");
/*TARGET 001f08e0*/
// to_2f9a38
void func_001f08e0(u8* base, OscIn* in, XfCtx2* c) asm("func_001f08e0");
// to_2f9a38
void func_001f08e0(u8* base, OscIn* in, XfCtx2* c) {
    Osc* o = (Osc*)(base + c->offs[2] + 160);
    if (o->on == 0) func_001f0868(in, o);
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0x000000ff0000ff00ULL) return;
    if (in->id == *(u32*)(base + 12)) {
        o->vel += in->a;
        o->acc += in->b;
        o->vel2 += in->c;
        o->acc2 += in->d;
    }
    if (D_01d9eab4) return;
    o->vel += o->acc;
    o->pos += o->vel;
    o->vel2 += o->acc2;
    o->pos2 += o->vel2;
    o->pos = func_002f8b00(o->pos, 32768.0f);  // to_2f9a38
    o->pos2 = func_002f8b00(o->pos2, 32768.0f);  // to_2f9a38
}
}  // namespace n001f08e0

