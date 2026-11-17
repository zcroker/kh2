#include "../common/types.h"

extern "C" {
void wt7658_w1893(void*, u64) asm("_Z16wtarget_00167658jjjj");
void lst_w1893(void*) asm("_Z13func_0031a830Pv");
}
inline void* operator new(unsigned int, void* p) { return p; }
struct S1893 { u8 b[16]; ~S1893() {} } __attribute__((aligned(16)));
struct X1893 {
    u64 m[4];
    S1893 v[2];
    u32 x40;
    X1893() { wt7658_w1893(this, 0); }
};
struct A1893 : X1893 { u8 pad[384 - 80]; };
struct B1893 : X1893 {
    u32 x44;
    u32 x48;
    u32 x4c;
    u8 pad50[16];
    B1893() { x44 = 0; lst_w1893(&x48); x4c = 0; }
};
struct WA1893 { A1893 a[2]; };
struct WB1893 { B1893 a[2]; };

extern "C" {
extern WA1893 D_0034d3c0;
extern WB1893 D_0034d6c0;

// --- 00168068: static init/destruction of two global object arrays
void wtarget_00168068(u32 a, u32 b, u32, u32) asm("_Z16wtarget_00168068jjjj");
// 00168068: moved to src/anon/unit_00167358.cpp

// --- 00256cc0
extern u8 D_00372940[];
extern u32 D_0035f3d4; extern u32 D_0035ef68; extern u32 D_0035ef64; extern u32 D_0035f03c;
u8* func_00257770(void);
u32 func_00192cc0(u8*, u8*);
s32 func_00192b30(u32);
u32 func_00192048(s32);
s32 func_00192c90(u32, u8*);
void memcpy(u8*, u8*, s32);
s32 func_00139d78(u8*);
void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32);
void func_00256cc0(s32 a, s32 b, s32 c);  // 0x00256cc0: definition moved into src/anon/unit_00254020.cpp

}
