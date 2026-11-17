#include "../common/types.h"
struct Entry1832 { s32 id; s32 time; u8 pad[0x200]; };
struct Cache1832 { Entry1832 e[4]; Entry1832* cur; s32 counter; };
struct FlareItem1832 { u8 d[0x40]; };
struct FlarePool1832 { FlareItem1832 item[30]; s32 free[30]; s32 count; };
struct Heap1832 { void** vt; };
typedef void* (*AllocFn1832)(Heap1832*, s32, s32);
extern "C" {
extern u8 D_0032bae1;
void func_00195430(Entry1832*);
void func_001955a8(Cache1832* c, s32 range);  // 0x001955a8: definition moved into src/anon/unit_00194790.cpp

u8* CreateTask1832(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
Heap1832* GetAllocator1832(void) asm("_ZN4AREA12GetAllocatorEv");
void func_002e92e8(void*);
void func_002e9338(void*);
void func_002e93a0(FlareItem1832*);
extern u8* D_003633c8;
extern FlarePool1832* D_01e2bfa0;
extern s32 D_01e2bfa4;
// Ts::FLARE::Init()
void FlareInit1832(void) asm("_ZN2Ts5FLARE4InitEv");
// 002e9690: moved to src/sugi/flare.cpp
}
