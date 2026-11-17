#include "../common/types.h"
extern "C" {
extern s32 D_0035f458;
extern s32 D_0035f45c;
extern s32 D_0035f460;
extern u8 D_00347e60[];
void func_0031a840(void*);
void func_00323d30(void*);
}
void yi_sequence_dtor_28f3e8(void*) asm("_ZN2YI8SEQUENCED1Ev");
struct A0_28f3e8 { ~A0_28f3e8() { func_0031a840(this); } };
struct M18_28f3e8 { u8 d[0x1b4 - 0x18]; ~M18_28f3e8() { yi_sequence_dtor_28f3e8(this); } };
struct B0_28f3e8 : A0_28f3e8 { void* vt; u8 pad[20]; M18_28f3e8 m; ~B0_28f3e8() { vt = D_00347e60; } };
struct M1b4_28f3e8 { u8 d[884 - 436]; ~M1b4_28f3e8() { func_00323d30(this); } };
struct C0_28f3e8 : B0_28f3e8 { M1b4_28f3e8 m2; ~C0_28f3e8() {} };
extern "C" {
extern C0_28f3e8* D_0035f480;
extern C0_28f3e8* D_0035f480_b asm("D_0035f480");
void func_0028f3e8(void);  // 0028f3e8: moved to src/anon/unit_0028f1e0.cpp
}

extern "C" {
struct JmEnt_2ae0c0 { s8 id; u8 pad[11]; };
struct JmData_2ae0c0 { int a; int b; int n; int c; JmEnt_2ae0c0 e[1]; };
JmData_2ae0c0* jm_getdata_2ae0c0(int) asm("_ZN2Tz6JmInfo7GetDataEi");
u32 func_002abf40(int, int);
struct Flags_2ae0c0 { u8 pad[0xac]; u32 bits[1]; };
extern Flags_2ae0c0* D_0035f620;
int func_002ae0c0(int id);  // 0x002ae0c0: definition moved into src/anon/unit_002a99c8.cpp
}
