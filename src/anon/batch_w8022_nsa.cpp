#include "../common/types.h"
struct W8022_Al { virtual void* alloc(u32, void*); };
inline void* operator new[](unsigned int sz, W8022_Al* a) { return a->alloc(sz, 0); }
extern "C" {
void func_00239700(void*);
extern u8 D_00347e60;
}
struct W8022_T {
    u32 vt; u8 p4[8]; u32 f12; u8 p16[8]; u8 sub[384];
    W8022_T() { f12 = 0; vt = (u32)&D_00347e60; func_00239700(sub); }
    ~W8022_T();
};
extern "C" {
void func_00287b18(s32, s32);
void* func_00288be8(s32);
void func_002889f0(void*, s32, s32);
void func_00288f48(void*, s32, s32, s32, s32);
void func_002b3df8(void*);
void func_0028d068(s32, s32);
u8* func_00103eb0(void);
void func_00102818(u32, s32, s32, void*, s32);
void func_0024f698(void);
typedef void* (*AllocFn)(void*, u32, void*);
extern void** D_0032ba14;
extern u8* D_00347f80;
extern void* D_0035ee34;
extern void* D_0035ee38;
extern s32 D_0035ee3c, D_0035ee40, D_0035ee44;
extern W8022_T* D_0035ee48;
extern void* D_0035ee4c;
extern u8 D_0035ee50, D_0035ee51;
void func_0024f398(void) {
    void* o;
    func_00287b18(5, 3);
    o = func_00288be8(56);
    func_002889f0(o, 5, 1);
    D_0035ee34 = o;
    o = func_00288be8(56);
    func_002889f0(o, 2, 0);
    D_0035ee38 = o;
    func_00288f48(o, 64, 128, 0, 0);
    D_0035ee3c = 0;
    D_0035ee40 = 0;
    D_0035ee44 = 0;
    o = (**(AllocFn**)D_0032ba14)(D_0032ba14, 12, __builtin_return_address(0));
    func_002b3df8(o);
    D_0035ee4c = o;
    D_0035ee50 = 0;
    D_0035ee48 = new (*(W8022_Al**)(D_00347f80 + 20)) W8022_T[5];
    D_0035ee51 = 0;
    func_0028d068(30026, -1);
    func_00102818(*(u32*)(func_00103eb0() + 4), 0, 2000, (void*)func_0024f698, 4096);
}
}
