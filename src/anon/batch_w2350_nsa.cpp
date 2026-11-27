#include "../common/types.h"
// Needs -fno-strict-aliasing: the s32 stores into the new data block reload p's s16 fields.

struct Obj_f;
struct VT_f { void* pad[8]; void (*f20)(Obj_f*, s32); };
struct Obj_f { VT_f* vt; };
struct Data_f { s32 type; s32 f4; s32 f8; s32 fc; s32 f10; s32 f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; Obj_f* f2c; s32 f30; s32 f34; u8 b38; u8 pad39[3]; s32 f3c; };
struct Task_f { u8 pad0[4]; Data_f* data; u8 pad8[0x30 - 8]; void (*f30)(Task_f*); };
struct Arg_f { u8 pad0[4]; s16 f4; s16 type; s16 f8; s16 fa; s16 fc; s16 fe; s16 f10; s16 f12; s16 f14; };

extern "C" {
Task_f* CreateTask_f(s32, s32, void (*)(Task_f*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void* Alloc_f(u32) asm("_ZN4AREA5AllocEj");
Obj_f* ComboStart_f(s32) asm("_ZN2sa13MUSICAL_COMBO5startEi");
s32 sa__EVENT__checkStart(s32);
s32 sa__EVENT__getEventPriority(void);
s32 func_002247d8(void);
void func_00224f38(s32, Task_f**, Obj_f**, s32);
void func_00224f08(Task_f*);
void sa__MUSICAL_COMBO__printTask(Task_f*);

// Spawns a task for a grid cell: picks the task kind from p->type, then fills its data block
// with cell offsets (centre, up, left/right neighbours) relative to p->f4.
void func_00224fa0(Arg_f* p);  // 0x00224fa0: definition moved into src/anon/unit_00224780.cpp
}
