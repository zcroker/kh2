#include "../common/types.h"
struct Alloc { void* (**vt)(Alloc*, u32, void*); };
struct Holder { u8 pad[0x14]; Alloc* al; };
#define QCP(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCP4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCP(this, &o); }
    QV& operator=(const QV& o) { if (this != &o) QCP(this, &o); return *this; }
    QV operator+(const QV& b) const {
        QV o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct QM {
    QV r[4];
    QM() {}
    QM(const QM& o) { QCP4(this, &o); }
    QV operator*(const QV& v) const {
        QV o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
extern Alloc* D_0032ba14;
extern Holder* D_00347f80;
extern u8 D_00347e60;
extern s32 D_0035ed20; extern s32 D_0035ed24; extern s32 D_0035ed28; extern s32 D_0035ed2c;
extern s32 D_0035ed30; extern void* D_0035ed34; extern s32 D_0035ed38; extern s8 D_0035ed3c;
extern s32 D_0035ed40; extern s8 D_0035ed44;
void func_00287b18(s32, s32);
s32 func_00288be8(s32);
void func_002889f0(s32, s32, s32);
void func_00288f48(s32, s32, s32, s32, s32);
void func_002b3df8(s32);
s32 func_00103570(void);
s32 func_001063c0(s32, s32);
void Tz__JmDic__Init(s32);
void func_002fde18(s32, s32, s32);
void func_00239700(void*);
s32* func_00103eb0(void);
void TASK_MANAGER__create_thread(s32, s32, s32, void*, s32);
void PauseThread_(void*) asm("_ZN2Tz4HECO11PauseThreadEP4TASK");

typedef void* (*AF)(s32, u32, void*);
extern s32 D_0032ba14_i asm("D_0032ba14");
static inline void* Al(u32 n) { s32 a = D_0032ba14_i; return (*(AF*)*(s32*)a)(a, n, __builtin_return_address(0)); }
void Tz__HECO__Init(void);  // 0x00244f10: definition moved into src/anon/unit_00242478.cpp

extern u8 D_0035f0b0;
s32 func_00240ba0(void);
s32 func_00287cd0(void);
s32 func_002b4ff8(void);
void func_00287cc0(s32);
s32 func_00287d30(void);
s32 func_00233e70(s32);
s32 func_00234798(void);
s32 func_00234758(void);
void func_00241450(s32);
void func_00287d20(s32);
s32 Tz__MCard__ChkFileSize(s32);
void func_00287bd0(s32, s32);
void func_002400f8(s32);
void func_002b5108(s32, s32);
void Tz__CmSLBase__SetupWarningConfirm(s32);
void Tz__MCard__GetDirInfo(s32);
void func_00234570(s32, s32);

void func_0025bbe0(void);  // 0x0025bbe0: definition moved into src/anon/unit_002588e8.cpp

extern u8* D_00361f60;
void func_0016a9a0(void);
QM* Ti__MGHachimitsu__get_current_center_matrix(u8*);
void Ti__MGObj__set_matrix_2(u8*, QM*);
void func_0011b6a8(QM*);
void func_0011b7b0(QM*, u8*);
void func_0016ace0(u8*, QV*);
void func_0016b070(u8*, u8*);
void func_002d8120(f32, QM*, u8*, u8*);
void Ti__MGObj__set_matrix(u8*, QM*);

void func_002dafd0(u8* o);  // 0x002dafd0: definition moved into src/anon/unit_002da040.cpp
}
