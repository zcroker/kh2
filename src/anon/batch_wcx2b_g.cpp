// 001d00a8: built with -g. lq/sq copy asm and VU0 vsub macro asm (owner-approved kinds).
#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord operator-(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
extern "C" {
s32 YS_TABLE_Get(void) asm("_ZN2YS6MEMBER5TABLE3GetEv");
u8* YS_PLAYER_Stun(void) asm("_ZN2YS6PLAYER4StunEv");
QWord* YS__OBJ__get_pos(u8*);
QWord YS_BG_RandomPos(const QWord&, f32, f32, s32) asm("_ZN2YS2BG9RandomPosERKN2kn7FVectorEffi");
u8* AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void* JmInfo_GetCharaData(s32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
f32 f_atan2f(f32, f32);
void YS__MICKEY__MICKEY(f32, u8*, void*, u32, QWord*);
void YS__MOTION__capture(f32, u8*, u8*, s32);
void* YS_EFFECT_GetSystemPax(void) asm("_ZN2YS6EFFECT12GetSystemPaxEv");
s32 ryj__PAX__start(void*, s32, s32, s32, s32, u8*);
void func_00190570(u8*, u8*);

void func_001d00a8(void);  // 0x001d00a8: definition moved into src/anon/unit_001cf0b0.cpp
}
