#include "../common/types.h"
struct TASK;
extern "C" {
struct Res1a5f50 { u8 pad[8]; s32 val; };
struct Data1a5f50 { s32 id; char name[1]; };
struct Ent1a5f50 { s32 cache; s32 res[2]; u8 arg[0x1c]; Data1a5f50* data; };
struct Task1a5f50 { u8 pad[48]; void (*fin)(TASK*); };
extern Ent1a5f50 D_00350800[6];
struct Pair1a5f50 { u32 a; u32 b; };
extern Pair1a5f50 D_01c6cb20;
Task1a5f50* t1a5f50_CreateTask(s32, s32, void (*)(TASK*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void t1a5f50_Finalizer(TASK*) asm("_ZN2YS5MAGIC9FinalizerEP4TASK");
void func_001a5db8(TASK*);
Data1a5f50* func_001a6658(s32);
s32 t1a5f50_Alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
Res1a5f50* func_00168b38(s32, s32, s32);
void t1a5f50_001dddd0(void*, s32) asm("_Z16wtarget_001dddd0jjjj");
static inline bool Has1a5f50(Res1a5f50* r) { return r && r->val != 0; }

// YS::MAGIC init: create the magic task, then load each of the 6 magic entries' cache/resources.
// Each field is walked by its own stepping pointer (matches the original's 5 separate stride-44 registers).
// 001a5f50: moved to src/yasui/libys/magic.cpp
}
