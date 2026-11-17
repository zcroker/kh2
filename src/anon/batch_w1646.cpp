#include "../common/types.h"
#define W1646_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1646Vec {
    f32 x, y, z, w;
    W1646Vec& operator=(const W1646Vec& o) { if (this != &o) W1646_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1646Hd { s32 f04; s32 f08; s32 f0c; };
struct W1646Act {
    s32 type;
    W1646Hd h;
    W1646Vec v10;
    s32 f20;
    u8 f24;
    f32 f28;
    f32 f2c;
    u8 f30;
    u8 f31;
    W1646Vec v40;
    f32 f50;
};
struct W1646Npc {
    u8 pad[0xa40];
    W1646Act act;
    W1646Act prev;
    f32 timer;
    u8 padb04[0xc];
    f32 fb10;
    f32 fb14;
    u8 padb18[4];
    f32 fb1c;
    f32 fb20;
};
static inline void w1646_vnorm(W1646Vec* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
}
static inline f32 w1646_vdot(const W1646Vec* a, const W1646Vec* b) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}
extern "C" {
extern f32 D_00349e10;
s32 func_001c0cd8(W1646Npc*);
void func_0018c570(W1646Act*);
s32 func_0018bd50(W1646Npc*, s32);
void func_0018c438(W1646Act*);
f32 w1646_angle(f32, f32) asm("_Z13func_001065a8jjjjjjjj");
W1646Npc* func_0018b8e0(W1646Npc*, s32*);
void func_0016af58(W1646Vec*, W1646Npc*);
void func_0018bb70(W1646Npc*, s32, W1646Npc*, u8, f32);
void func_0018b7f8(W1646Npc*);

void func_0018b478(W1646Npc* o);  // 0x0018b478: definition moved into src/yasui/libys/npc.cpp
}
