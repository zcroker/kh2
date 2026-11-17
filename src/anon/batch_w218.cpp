#include "../common/types.h"
struct V4 { f32 a,b,c,d; };
struct T218 { u32* o; u32 z; f32 x, y; };
union UF218 { u32 u; f32 f; u8 c; };
extern "C" {
u32 func_00190140(void);
u32 func_00112d28(u32);
u32 func_0016a020(u32);
void func_0019b0e8(V4*, u32, u32, f32, f32);
void func_0016ace0(u32, V4*);
void func_00185b00(void*);
extern u8 D_00350ce0[];

u32 func_00112d90(u32* p) {
    u32 ok = 0; u32 r = 0;
    if (func_00190140()) ok = *p != 0;
    if ((u8)ok) r = func_00112d28(*p);
    return r;
}

void func_00172928(T218* t);  // 0x00172928: definition moved into src/anon/unit_00171e58.cpp

void ctarget_001ae9a0(u8* p) asm("_Z16ctarget_001ae9a0jjjj");
void ctarget_001ae9a0(u8* p);  // 0x001ae9a0: definition moved into src/anon/unit_001ada38.cpp
}
