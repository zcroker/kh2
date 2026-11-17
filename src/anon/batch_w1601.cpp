#include "../common/types.h"
extern "C" {

// ---- a.cpp
struct Gw2a63a0 { u8 pad[2]; s8 col; u8 pad3; u16 id; };
struct Rc2a63a0 { u8 pad[20]; s32 w; };
extern void *D_0035f200;
extern u8 *D_0035f224;
extern Gw2a63a0 *D_0035f5ec;
u8 *func_002766d0(void);
s32 func_0028b040(void *a);
void func_0014b950(void *p, s16 x, s16 y, u16 w, u16 c);
void func_0014b9a8(void *p);
s32 func_0023aa58(void *p);
s32 func_0023aa78(void *p);
Rc2a63a0 *func_001aae68(s32 a);
s32 func_00192048(u16 id);
void func_001a98e8(void *t, s32 a, s32 b, s32 c, s32 d);
void func_001aa6d0(void *t, s32 w);
void func_001a9ae8(void *t, s32 x, s32 y, s32 z);
void func_002a63a0(s32 x, s32 y, s32 z);  // 0x002a63a0: definition moved into src/anon/unit_002a5a90.cpp

// ---- b3.cpp
extern u16 D_0035f090;
extern u16 D_0035f092;
extern u16 D_0035f096;
void func_0014cbe0(u32*, u32*, u32*, u32*);
void func_0028e560(s32, u16*, s32, s32);
void func_00258eb8_i(s32 a) asm("_Z13func_00258eb8i");
void func_00258eb8_i(s32 a);  // 0x00258eb8: definition moved into src/anon/unit_002588e8.cpp

// ---- c4.cpp
union UG_0028f280 { u8* p; u32 i; };
extern UG_0028f280 D_0035f480;
extern u32 D_0035f458;
extern u32 D_0035f45c;
extern u32 D_0035f460;
extern u16 D_0035f468[];
extern u16 D_0035f470[];
extern u16 D_0035f478[];
extern u8 D_00347e60[];
extern u8 D_00347e40[];
u32 func_00103570(void);
void* func_001063f0(u32, u32);
void func_00239700(u8*);
void func_0028d140(u8*);
struct Rec0028f280 {
    u8 a[436];
    u8 b[444];
    u32 f880;
    void* operator new[](unsigned int sz, u32 h) { return func_001063f0(sz, h); }
    inline Rec0028f280() __attribute__((always_inline));
    ~Rec0028f280() {}
};
inline Rec0028f280::Rec0028f280() {
        *(u32*)(a + 12) = 0;
        *(u32*)a = (u32)D_00347e60;
        func_00239700(a + 24);
        *(u32*)a = (u32)D_00347e40;
        *(u32*)(a + 408) = 0;
        func_0028d140(b);
}
void func_0028f280(u32 a, u32 b, u32 c, u16* d, u16* e);  // 0028f280: moved to src/anon/unit_0028f1e0.cpp

// ---- g1.cpp
typedef void (*VFn26cc30)(u8*);
#define VCALL26cc30(p) (*(VFn26cc30*)(*(u8**)(p) + 20))(p)
extern u8* D_0035f0f4;
extern s32 D_0035f01c;
extern s32 D_0035f024;
s32 func_00287bc0(void);
u8* func_00256b68(s32);
s32 func_00139d78(u8*);
void func_00139510(u8*);
s32 func_0028acc8(s32);
void func_0028abe0(s32);
void func_00288e88(s32);
void func_0026c450(void);
void func_0026d828(void);
void Tz_CmParty_LeaveList_26cc30(void) asm("_ZN2Tz7CmParty9LeaveListEv");
void Tz_CmParty_LeaveList_26cc30(void);  // 0x0026cc30: definition moved into src/anon/unit_0026c450.cpp
}
