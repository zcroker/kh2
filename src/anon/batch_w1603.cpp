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
void func_0027dd18(void) {
    if (D_0035f244) { delete D_0035f244; D_0035f244 = 0; }
    if (D_0035f248) { delete[] D_0035f248; D_0035f248 = 0; }
    D_0035f24c = -1;
    D_0035f24d = -1;
    D_0035f24e = -1;
}
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
s32 func_00286418(s32);
void func_002865d0(s32);
s32 func_002864f8(s32);
void func_00138c10(u32, s32);
extern u32 D_0035f01c;
extern s32 D_003734f8;
extern s32 D_003734fc;

void func_00266988(void) {
    u32 base = func_00257770();
    s32 mode = func_00287bc0();
    s32 v = func_0028b040(D_0035f01c);
    u32 tgt;
    s32 k, n;
    if (mode == 23) {
        tgt = D_0035f01c;
        switch (func_002670a0(v)) {
        case 1: k = 0; break;
        case 2: k = 1; break;
        case 3: k = 2; break;
        case 4: k = 3; break;
        case 5: k = 4; break;
        default: return;
        }
    } else {
        v = func_00257070(23);
        if (v != 6) return;
        tgt = func_00267248();
        if (tgt == D_0035f01c) return;
        switch ((E00266988)func_002671e8(func_0028b040(tgt))) {
        case 10: k = 5; break;
        case 11: k = 6; break;
        case 12: k = 7; break;
        default: k = 8; break;
        }
    }
    if (func_00286418(k) == 0) return;
    func_002865d0(k);
    if (func_002864f8(k) != 0) k = D_003734fc;
    else k = D_003734f8;
    if (mode == 23 || v == 6) {
        s32 i = func_0028b040(tgt);
        if (mode != 23) i = func_002671e8(i);
        func_00138c10(base + i * 0x198 + 0x87D0, k);
    }
}

}
