// w2485: 0 diffs (cmp2, -g and -g0) ONLY with -fmove-all-movables; plain -O2 gives 94 (inc-pointer best draft: 3). Needs a *_mam build rule.
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
struct W1573_Q {
    u8 d[16];
    W1573_Q& operator=(const W1573_Q& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1573_P12 { u8 pad[20]; void* arc; };
struct W1573_E {
    s32 id;
    s32 pad4;
    u8* obj;
    W1573_P12* p12;
    f32 timer;
    s32 pad20;
    s16 a;
    s16 b;
    s32 pad28;
    W1573_Q vec;
    u8 flag;
    u8 pad49[15];
};
extern "C" {
extern W1573_E* D_0035dcf8;
extern f32 D_00349e10;
void YS__OBJ__is_valid(u8*);
W1573_Q* YS__OBJ__get_pos(u8*);
void motion_start(void*, void*, f32, f32) asm("_ZN2YS6MOTION5startEPNS_6BINARCEff");
s32 obj_is_attach(u8*) asm("_ZN2YS3OBJ9is_attachEv");
void obj_set_pos(u8*, W1573_Q*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void func_00232f08(void);  // 0x00232f08: definition moved into src/anon/unit_00232f08.cpp
}
