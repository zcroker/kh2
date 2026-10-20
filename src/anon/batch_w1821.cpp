#include "../common/types.h"
struct W1821Vec {
    f32 x, y, z, w;
    W1821Vec() {}
    W1821Vec(const W1821Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1821Vec& operator=(const W1821Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1821Obj { u8 pad[16]; W1821Vec p10; W1821Vec p20; u8 pad2[0xd0]; s32 w100; s32 w104; u8 pad3[0x40c]; s8 b514; };
static inline f32 w1821_norm(W1821Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
extern "C" {

void func_001c1130(s32);
void func_001c11a8(s32);
s32 func_00224860();
s32 func_00224910();
u32 func_002249b8();
void func_002249c8();
void func_002249d8();
s32 func_002249e8();
s32 func_00225260();
void func_00228518();
void func_00228590();
extern s32 D_0035dac8;

void func_002249f8(void) {
    func_001c11a8(8);
    func_001c1130(0xC);
    func_002249c8();
    if (func_00225260() == 0) {
        switch (func_002249b8()) {
        case 1:
            if (func_00224860() == 5) func_002249d8();
            break;
        case 2:
            if (D_0035dac8 < 5) func_002249d8();
            break;
        case 3:
            if (func_00224910() < 6000) func_002249d8();
            break;
        case 4:
            if (func_00224910() < 8000) func_002249d8();
            break;
        case 5:
            if (func_00224910() < 30000) func_002249d8();
            break;
        default:
            if (func_00224910() == 0) func_002249d8();
            break;
        }
    }
    if (func_002249e8() == 1) {
        func_00228518();
        return;
    }
    func_00228590();
}


W1821Vec func_0017c030(W1821Obj*, s32*, u8);
void func_0017c4c8(W1821Obj*, W1821Vec);
void func_002eb778(W1821Obj*, u32, s32, f32);

void func_002ec850(void* unused, W1821Obj* p, u8 c) {
    W1821Vec v = p->p20;
    s32 k;
    f32 len = w1821_norm(&v);
    v.w = len;
    if (p->p10.w < len) p->p10 = v;
    v = func_0017c030(p, &k, c);
    v.y = 385.0f;
    func_0017c4c8(p, v);
    p->b514 = 8;
    func_002eb778(p, 255, 1, 0.0f);
    p->w100 = 0x100;
    p->w104 = 0x101;
}
}
