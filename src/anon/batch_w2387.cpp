#include "../common/types.h"

/* 128-bit vector with lq/sq copies (hand-written MMI copy in the original's vector class). */
#define QCOPY_w2387(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord_w2387 {
    u32 v[4];
    QWord_w2387() {}
    QWord_w2387(const QWord_w2387& o) { QCOPY_w2387(this, &o); }
    QWord_w2387& operator=(const QWord_w2387& o) {
        if (this != &o) QCOPY_w2387(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord_w2387 VSub_w2387(const QWord_w2387& a, const QWord_w2387& b)
{
    QWord_w2387 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
/* Normalize xyz in place (VU0), returns the length. */
static inline f32 VNormalize_w2387(QWord_w2387* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Act_w2387 { u8 pad[340]; s32 state; };
struct Self_w2387 { u8 pad[36]; s32 f24; s32 f28; };
QWord_w2387 actor_pos_w2387(Act_w2387*) asm("_Z16ctarget_0016bda8jjjj");
extern "C" {
extern Act_w2387* D_0034e948;
extern u32 D_003638d0;
Act_w2387* friend_get_w2387(s32) asm("_ZN2YS6FRIEND3GetEi");
QWord_w2387* func_001e0cc8(Self_w2387*);
void func_001e0d68(Self_w2387*, QWord_w2387*);

/* Pick D_0034e948 or party actor 0 (by state 270/271, else a random bit), then store the
   normalized direction from this object's point to that actor's position. */
void func_001e0e50(Self_w2387* o);  // 0x001e0e50: definition moved into src/anon/unit_001e0cb8.cpp

s32 func_002ef7b8();
s32 func_0022bb38();
void func_00226dc8();
s32 func_00228378();
u8* func_0014ac08();
void func_0014ce60();
s32 func_002bc7a8(s32);
extern s32 D_0035de20;
extern s32 D_0035de28;
extern s32 D_0035de2c;
extern u8 D_0035de56;
}
static inline s32 is4_w2387() { return *(s32*)(func_0014ac08() + 0xfc) == 4; }
extern "C" {
void func_00225b88(void);  // 0x00225b88: definition moved into src/anon/unit_00224780.cpp
}
