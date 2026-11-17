// func_00111f50: per-frame party update (matrix setup, leader target copy, party member targets).
// Built with -g (file suffix _g).
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
struct FMat { QWord c[4]; };
static inline void MatMul(FMat* r, const FMat* a, const FMat* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}
struct Tgt {
    u32 w[5];
};
extern "C" {
s32 TARGET_is_exist(Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
}
static inline bool TgtValid(Tgt* t) {
    bool r = false;
    if (TARGET_is_exist(t)) r = t->w[0] != 0;
    return r;
}
struct Chara;
struct VObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); };
struct Chara {
    u8 p0[0x10c]; u32 x10c;
    u8 p1[0x160 - 0x110]; u32 x160;
    u8 p2[0x9f4 - 0x164]; Tgt tgt;
    u8 p3[0xb60 - 0xa08]; VObj* xb60;
    u8 p4[0xbe0 - 0xb64]; QWord xbe0;
    u8 p5[0xce0 - 0xbf0]; u32 xce0;
    u8 p6[0xcec - 0xce4]; u32 xcec;
};
extern "C" {
void func_00111e50(void);
void* func_00106a18(s32);
FMat* func_00106ad0(void*);
u8* func_00106a60(s32);
void func_00146680(void*, FMat*);
void* func_0016c028(Chara*);
s32 wtarget_0010b468(void*, void*) asm("_Z16wtarget_0010b468jjjj");
s32 func_00112d90(Tgt*);
void func_00190128(Tgt*);
s32 Friend_is_party(Tgt*) asm("_ZN2kn6Friend8is_partyEPKN2YS6TARGETE");
QWord func_00190388(Tgt*);
s32 ctarget_0019ba60(u32) asm("_Z16ctarget_0019ba60jjjj");
void func_001127c0(void);
void func_001118a8(void);
extern Chara* D_00341708[3];
extern Tgt D_003417b0;
extern u32 D_003417c4;
extern u8 D_003a9250[];
extern u8 D_003a9040[];

void func_00111f50(void);  // 0x00111f50: definition moved into src/anon/unit_001117d8.cpp
}
