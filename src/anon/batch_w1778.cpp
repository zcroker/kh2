#include "../common/types.h"

struct W1778Obj;
struct W1778ObjVt { void* f[16]; s32 (*isOk)(W1778Obj*); };
struct W1778Obj { W1778ObjVt* vt; };

extern "C" {
extern W1778Obj* D_0034e948;
extern s32 D_01d48cb0;
extern u8 D_00351eb8[];
s32 YS__OBJ__is_exist(W1778Obj*);
void func_001b5250(s32, s32);
bool func_001c8db8(void*, s32);
void func_001d4180(void);

void func_001b4340(void);  // 0x001b4340: definition moved into src/anon/unit_001b2780.cpp
}
