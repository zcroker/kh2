#include "../common/types.h"
struct W1669NoTail { ~W1669NoTail() {} };
struct W1669Pair { u32 a, b; };
struct W1669Tri { u32 a, b; f32 c; };
extern "C" {
extern W1669Pair D_01e2be18;
extern W1669Pair D_01e2bf00;
extern W1669Pair D_01e2c080;
extern f32 D_00351fe0;
extern W1669Tri D_004574b8;
extern u32 D_0032df30[];
extern u8 D_00348d68[];
void func_001491c0(void*);
void func_001a1460(u32) asm("_ZN2YS5SHEET6reloadEv");
f32 func_00166d70(u32);
void func_00154de8(u8*, f32);
void func_001bc688(void*) asm("_ZN2YS12COMMAND_SLOT5clearEv");
void func_00190128(void*);
f32 func_001065a8(f32, f32) asm("_Z13func_001065a8jjjjjjjj");

void wtarget_002ce910(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ce910jjjj");
void wtarget_002ce910(u32 a0, u32 a1, u32, u32);  // 0x002ce910: definition moved into src/taito/path.cpp
void wtarget_002e7610(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002e7610jjjj");
void wtarget_002e7610(u32 a0, u32 a1, u32, u32);  // 0x002e7610: definition moved into src/anon/unit_002e5f70.cpp
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ee540jjjj");
void wtarget_002ee540(u32 a0, u32 a1, u32, u32);  // 0x002ee540: definition moved into src/anon/unit_002ecdb0.cpp
void func_001cbf20(u32 a0, u32 a1);  // 0x001cbf20: definition moved into src/anon/unit_001ca8e0.cpp
void wtarget_0014d240(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_0014d240jjjj");
void wtarget_0014d240(u32 a0, u32 a1, u32, u32);  // 0x0014d240: definition moved into src/anon/unit_0014c7f0.cpp
void func_00149f30(int a0, int a1) asm("_Z13func_00149f30ii");
// 00149f30: static initialiser, now made by gcc in src/harata/libdk/area.cpp
void func_00323ad0(u32* p);  // 0x00323ad0: definition moved into src/anon/unit_00323978.cpp
void func_001e7440(void);  // 0x001e7440: definition moved into src/anon/unit_001e0cb8.cpp
struct W1669VObj { void** vt; };
void dk__Layout__destroy(W1669VObj* p);  // 0x00153c98: definition moved into src/anon/unit_00153678.cpp
// 00177678: moved to src/yasui/libys/party.cpp
// 001556c0: moved to src/anon/unit_00153ea0.cpp
void func_001556c0(u8* p);
void func_0019d518(u8* p);  // 0x0019d518: definition moved into src/anon/unit_0019ba60.cpp
void func_001a9160(u32 n);  // 0x001a9160: definition moved into src/anon/unit_001a9130.cpp
void func_002e73a8(u8* p);  // 0x002e73a8: definition moved into src/anon/unit_002e5f70.cpp
}
