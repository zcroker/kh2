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
QWord* func_0016c028(u8*);
QWord YS_BG_RandomPos(const QWord&, f32, f32, s32) asm("_ZN2YS2BG9RandomPosERKN2kn7FVectorEffi");
u8* AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void* JmInfo_GetCharaData(s32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
f32 f_atan2f(f32, f32);
void func_001cfcf8(f32, u8*, void*, u32, QWord*);
void func_00180378(f32, u8*, u8*, s32);
void* YS_EFFECT_GetSystemPax(void) asm("_ZN2YS6EFFECT12GetSystemPaxEv");
s32 func_001de168(void*, s32, s32, s32, s32, u8*);
void func_00190570(u8*, u8*);

void func_001d00a8(void) {
    s32 id = YS_TABLE_Get();
    u8* pl = YS_PLAYER_Stun();
    QWord pos = *func_0016c028(pl);
    pos.f[1] -= 200.0f;
    QWord tmp = YS_BG_RandomPos(pos, 200.0f, 200.0f, 0x10000);
    pos = tmp;
    QWord d = pos - *func_0016c028(pl);
    u8* w = AREA_Alloc(0xba0);
    void* cd = JmInfo_GetCharaData(id);
    func_001cfcf8(f_atan2f(d.f[0], d.f[2]), w, cd, *(u32*)(pl + 0xb38), &pos);
    func_00180378(0.0f, w + 0x140, pl, 0xfc);
    func_001de168(YS_EFFECT_GetSystemPax(), 0x11, 1, 1, 0, pl);
    func_00190570(pl, w);
}
}
