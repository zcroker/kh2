#include "../common/types.h"
struct V4 { f32 x, y, z, w; V4() {} V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
struct Node { void* vt; s32 f4; s32 f8; u8 sub[0x58]; s32 f64; s32 pad68; s32 f6c; s32 f70; s32 f74; s32 f78; Node* next; s32 f80; };
struct List { Node* head; Node* tail; };
extern "C" {
extern u8 D_00350c50[];
extern List D_01c6ced0;
s32 func_00192048(s32);
void func_001a98e8(void*, s32, s32, s32, s32);
s32 func_001a9808(s32, s32);
static inline Node* nextOf(Node* p) { return p ? p->next : D_01c6ced0.head; }
// 001ac378: moved to src/anon/unit_001abb28.cpp

// VU0 macro asm (vector subtract, normalize, dot product), as in the original.
extern void* D_0034e948;
V4* func_0016c028(void*);
void func_0016af58(V4*, void*);
void func_0015b1b0(u8, u8, u8);
void func_0015b268(f32, s32);
s32 func_001967f0(u8, u8, s32);
static inline f32 vnorm(V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
s32 func_0019a6c0(void* self, u8* ids, f32* pos, u8 flag, u8 arg);  // 0x0019a6c0: definition moved into src/anon/unit_00199688.cpp
}
