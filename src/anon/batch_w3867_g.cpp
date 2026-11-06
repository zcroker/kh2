// func_002b4440: (re)initialises a game-mode state block: clears counters, allocates lists, work objects and two 512-byte buffers.
// Built under -g (_g). Partial asm: one empty non-volatile asm makes the D_0035f6c8 store wait for the D_0035f6c4 reload
// (original order; pure C gives 2 differing lines).
#include "../common/types.h"
struct Heap { virtual void* Alloc(u32 n, void* ra); };
struct Mgr { u8 pad[20]; Heap* heap; };
extern "C" {
extern u32 D_00347f80;
typedef void* (*AllocFn)(u32, u32, void*);
extern Heap* D_0032ba14;
extern u8 D_00347e60[];
extern u8 D_00347e40[];
extern u8 D_00347f98[];
extern u8 D_0035f360[];
void func_0014a4b0(void);
s32 func_00103570(void);
void func_0023fd40(s32);
void func_00240b90(s32);
void func_00233ce0(void);
void func_00287b18(s32, s32);
void func_0028d068(s32, s32);
void* func_00288be8(u32);
void func_002889f0(void*, s32, s32);
void func_00288f48(void*, s32, s32, s32, s32);
void func_00239700(void*);
void* func_001063f0(s32, s32);
void func_0028b9b0(void*);
void func_0028d140(void*);
void func_0031a838(void*);
void func_002fde18(void*, s32, s32);
}
struct List { u8 pad[56];
    List(s32 a, s32 b) { func_002889f0(this, a, b); }
    static void* operator new(unsigned int n) { return func_00288be8(n); } };
struct HeapObj { static void* operator new(unsigned int n) { u32 h = *(u32*)(D_00347f80 + 20); return (*(AllocFn*)*(u32*)h)(h, n, 0); } };
struct Work : HeapObj { u32 vt; u8 p4[8]; s32 f0c; u8 p10[8]; u8 m18[384];
    Work() { *(u32*)this = (u32)D_00347e60; f0c = 0; func_00239700(m18); } };
struct WorkEx : Work { s32 f198; u8 pad[24]; WorkEx() { f198 = 0; *(u32*)this = (u32)D_00347e40; } };
struct Obj52 { u8 pad[52]; Obj52() { func_0028b9b0(this); }
    static void* operator new(unsigned int n) { return D_0032ba14->Alloc(n, __builtin_return_address(0)); } };
struct Obj444 : HeapObj { u8 pad[444]; Obj444() { func_0028d140(this); } };
struct Obj460 : HeapObj { u32 vt; u8 p4[8]; s32 f0c; u8 p10[8]; u8 m18[384]; s32 f198; u8 pad[48];
    Obj460() { *(u32*)this = (u32)D_00347f98; func_0031a838(&f0c); *(u32*)this = (u32)D_00347e60; func_00239700(m18); f198 = 0; *(u32*)this = (u32)D_0035f360; } };
extern "C" {
extern List* D_0035f64c;
extern List* D_0035f650;
extern s32 D_0035f654;
extern s32 D_0035f658;
extern void* D_0035f65c;
extern void* D_0035f660;
extern s32 D_0035f664;
extern s32 D_0035f668;
extern s32 D_0035f66c;
extern s32 D_0035f670;
extern s32 D_0035f674;
extern s32 D_0035f678;
extern s32 D_0035f67c;
extern s32 D_0035f680[4];
extern s32 D_0035f690[3][4];
extern s32 D_0035f6c0;
extern void* D_0035f6c4;
extern void* D_0035f6c8;
extern u8 D_0035f6d0;
extern s32 D_0035f3d4;

void func_002b4440(void)
{
    s32 i, j;
    func_0014a4b0();
    func_0023fd40(func_00103570());
    func_00240b90(0);
    func_00233ce0();
    func_00287b18(25, 3);
    D_0035f664 = 0;
    D_0035f654 = 0;
    D_0035f668 = 0;
    D_0035f66c = 0;
    D_0035f670 = 0;
    D_0035f674 = 0;
    D_0035f678 = 0;
    D_0035f67c = 0;
    D_0035f6d0 = 0;
    func_0028d068(30065, -1);
    for (i = 0; i < 4; i++) D_0035f680[i] = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++) D_0035f690[i][j] = 0;
    D_0035f64c = new List(4, 1);
    D_0035f650 = new List(2, 0);
    func_00288f48(D_0035f650, 128, 64, 0, 0);
    D_0035f654 = (s32)new WorkEx;
    D_0035f658 = (s32)new Work;
    D_0035f65c = func_001063f0(224, func_00103570());
    void** p660 = &D_0035f660;
    *p660 = func_001063f0(160, func_00103570());
    D_0035f678 = (s32)new Obj52;
    D_0035f67c = (s32)new Obj444;
    D_0035f6c0 = (s32)new Obj460;
    D_0035f6c4 = func_001063f0(512, func_00103570());
    void* b = func_001063f0(512, func_00103570());
    void* a = D_0035f6c4;
    asm("" : "+r"(b) : "r"(a));
    D_0035f6c8 = b;
    func_002fde18(a, 0, 512);
    func_002fde18(D_0035f6c8, 0, 512);
    D_0035f3d4 = 30045;
}
}
