#include "../common/types.h"

// ---- 0027dd18: deletes the panel object and the panel-group array (delete[] of 5116-byte groups)
namespace n0027dd18 {
extern "C" {
extern u8 D_00347e60[];
void func_00239870(void*) asm("_ZN2YI8SEQUENCED1Ev");
u8 func_0031a840(void*);
void func_0031abd8(void*);
}
struct Poly {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Poly();
};
struct X : Poly { u8 pad[432]; };
struct Y : Poly { u8 pad[404]; };
struct X0 {
    u8 pad[436];
    ~X0() { *(void**)this = D_00347e60; func_00239870(pad + 24); func_0031a840(this); }
};
struct Y0 {
    u8 pad[408];
    ~Y0() { func_0031abd8(this); }
};
struct Group {
    X0 m0;
    Y0 m436;
    Y a844[2];
    Y a1660[2];
    X a2476[3];
    X a3784[3];
    u8 tail[24];
};
extern "C" {
extern Poly* D_0035f244;
extern Group* D_0035f248;
extern s8 D_0035f24c;
extern s8 D_0035f24d;
extern s8 D_0035f24e;
void func_0027dd18(void);  // 0x0027dd18: definition moved into src/anon/unit_0027d2e8.cpp
}
}

// ---- 00266988: menu panel highlight for the current entry (mode 23 = list, else sub-panel)
enum E00266988 { E00266988_0 };
extern "C" {
u32 func_00257770();
s32 func_00287bc0();
s32 func_0028b040(u32);
u32 func_002670a0(s32);
s32 func_00257070(s32);
u32 func_00267248();
s32 func_002671e8(s32);
s32 Tz__CmNewFlg__isStatNew(s32);
void func_002865d0(s32);
s32 func_002864f8(s32);
void func_00138c10(u32, s32);
extern u32 D_0035f01c;
extern s32 D_003734f8;
extern s32 D_003734fc;

void Tz__CmStat__UpdateNew(void);  // 0x00266988: definition moved into src/anon/unit_00265580.cpp

}
