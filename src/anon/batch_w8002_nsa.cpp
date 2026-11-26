#include "../common/types.h"
struct Msg189d38 { s32 a; s32 b; s32 c; };
#define QCOPY(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct QV1832 {
    f32 x, y, z, w;
    QV1832() {}
    QV1832(const QV1832& o) { QCOPY(this, &o); }
    QV1832& operator=(const QV1832& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM1832 {
    QV1832 r[4];
    QV1832 operator*(const QV1832& v) const {
        QV1832 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
static inline f32 norm1832(QV1832* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct Obj1832 {
    QV1832 pos;
    void* fn;
    u8 pad14[0x1c];
    QV1832 dir;
    f32 f40;
    u8 pad44[8];
    s32* p4c;
    u8 pad50[0x68];
    s32 b8;
};
struct S1adb80 { s32 a; s32 b; };
extern "C" {

s32 func_00180dc0(void*, u16);
s32 ryj__PAX__start(s32*, u16, s32, s32, s32, void*);
s32 YS__LIMIT__AnmatrEffect(s32*, void*, u16, s32);
void func_0016cce8(s32, s32, Msg189d38*, s32, s32);
struct Obj189d38 { u8 pad0[8]; u8* owner; u8 pad[0xf0-12]; s32* list; u8 pad2[8]; u8* alt; };
struct Arg189d38 { s32 x; u16 id; };

extern u8 D_001cad40;
extern f32 D_00351fd8;
extern void* D_00361f60;
s32 func_001cbab0();
s32 func_001064a8(s32);
void** func_002d1260();
bool func_001ca9c0(Obj1832*);
void func_001ca910(Obj1832*);
u8 ys_max_mp_1adb80(void*, bool) asm("_ZN2YS5SHEET6max_mpEb");
u8 func_001a1910_u8(void*, s32, s32) asm("func_001a1910");
void YS__ANMATR__TriggerEffect(Obj189d38* self, Arg189d38* arg);  // 0x00189d38: definition moved into src/anon/unit_00189d38.cpp


bool func_001ca9e0(Obj1832* self);  // 0x001ca9e0: definition moved into src/anon/unit_001ca8e0.cpp

u8 func_001adb80(void* a0, S1adb80* a1);  // 0x001adb80: definition moved into src/anon/unit_001ada38.cpp
}
