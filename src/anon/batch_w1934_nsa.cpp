#include "../common/types.h"
// w1934 retry batch (built with -fno-strict-aliasing).
struct W1934S36 { u8 b[36]; };
extern "C" {
s32 func_00287cd0(void);
s32 func_00289380(u32);
s32 func_00289310(u32);
s32 func_0028acc8(u32);
void func_0028abe0(u32);
s32 func_002891e8(u32);
s32 func_00244ee8(s32);
void func_002b4388(u32, W1934S36*, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28(u32, s32);
void func_0028ab20(u32);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
void func_0028aa40(u32);
void func_00287b08(s16);
void func_00287da0(void);
extern u32 D_0035ecec;
extern u32 D_0035ece8;
extern u32 D_0035ed08;
extern W1934S36 D_003719a0[];
extern s16 D_00371938[];
void func_002442b8(void) {
    s32 i;
    s32 m = func_00287cd0();
    s32 r = func_00289380(D_0035ecec);
    if (m == 2) {
        if (func_0028acc8(D_0035ecec)) {
            if (r != -1 || func_00289310(D_0035ecec)) func_0028abe0(D_0035ecec);
        } else {
            i = func_00244ee8(func_002891e8(D_0035ece8));
            func_002b4388(D_0035ed08, &D_003719a0[i], 0);
            func_00287bd0(0, 0);
            func_00287cc0(1);
        }
        return;
    }
    if (r != -1 || func_00289310(D_0035ecec)) {
        if (!func_0028ae28(D_0035ecec, 0)) func_0028ab20(D_0035ecec);
    }
    if (m == 0) {
        if (func_0028ae28(D_0035ecec, 0)) func_00287c90(1);
    }
    func_00287df0(r, func_00289310(D_0035ecec), 0, 0, 1);
    switch (r) {
    case -4:
    case -3:
    case -1:
        break;
    case -2:
    case 1:
        func_0028aa40(D_0035ecec);
        func_00287c90(1);
        break;
    case 0:
        i = func_00244ee8(func_002891e8(D_0035ece8));
        func_00287b08(D_00371938[i]);
        func_00287da0();
        break;
    }
}
}

extern "C" {
struct W1934Heap;
typedef void* (*W1934AllocFn)(W1934Heap*, u32, s32);
struct W1934Heap { W1934AllocFn* vt; };
struct W1934Mgr { u8 p0[20]; W1934Heap* heap; };
extern void* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00347e40[];
extern s32 D_0035f100;
extern void* D_0035f104;
extern void* D_0035f108;
extern void* D_0035f10c;
extern void* D_0035f110;
union W1934U114 { s16* p; s16 h; };
extern W1934U114 D_0035f114;
extern s8 D_0035f120;
extern void* D_0035f124;
void func_00287b18(s32, s32);
void func_00242618(s32, s32);
void func_0028d068(s32, s32);
void* func_00288be8(s32);
void func_00239700(void*);
s32 func_00103570(void);
s16* func_001063f0(s32, s32);
static inline void* W1934Alloc(u32 n) { W1934Heap* h = ((W1934Mgr*)D_00347f80)->heap; return h->vt[0](h, n, 0); }
struct W1934B408 {
    void* vt; u8 p4[8]; u32 f0c; u8 p10[8]; u8 m[384];
    W1934B408() { f0c = 0; vt = D_00347e60; func_00239700(m); }
    static void* operator new(unsigned int n) { return W1934Alloc(n); }
};
struct W1934C436 : W1934B408 {
    u32 f198; u8 p19c[24];
    W1934C436() { vt = D_00347e40; f198 = 0; }
    ~W1934C436() {}
    static void* operator new[](unsigned int n) { return W1934Alloc(n); }
};
void func_0028d140(void*);
void func_00290610(void*);
void func_002889f0(void*, s32, s32);
struct W1934X444 { u8 d[444]; W1934X444() { func_0028d140(this); } static void* operator new(unsigned int n) { return W1934Alloc(n); } };
struct W1934X832 { u8 d[832]; W1934X832() { func_00290610(this); } static void* operator new(unsigned int n) { return W1934Alloc(n); } };
struct W1934X56 { u8 d[56]; W1934X56(s32 a, s32 b) { func_002889f0(this, a, b); } static void* operator new(unsigned int n) { return func_00288be8(n); } };
void func_0026d968(void)
{
    func_00287b18(2, 3);
    func_00242618(11, 1);
    func_0028d068(30026, -1);
    D_0035f100 = 0;
    D_0035f10c = new W1934X56(8, 0);
    D_0035f104 = new W1934C436[3];
    D_0035f108 = new W1934B408;
    D_0035f110 = new W1934X444;
    D_0035f124 = new W1934X832;
    D_0035f114.p = func_001063f0(18, func_00103570());
    for (s32 i = 0; i < 9; i++) D_0035f114.p[i] = -1;
    if (D_0035f120 < 0) D_0035f120 = 0;
}
}
