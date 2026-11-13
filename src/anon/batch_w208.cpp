#include "../common/types.h"
struct S242 { u32 w0; u32 :3; u32 f:1; };
struct VT208 { void* f[22]; void (*fn)(void*, void*); };
struct Obj208 { VT208* vt; };
struct O80_208 { char pad[80]; Obj208* o; };
extern "C" {
S242* func_001058e8(void);
void func_00242b10(u8 a) {
    S242* p = (S242*)((char*)func_001058e8() + 16800);
    p->f = a != 0;
}
u8 func_001c71f8(u32 p, f32 f);
void ctarget_001d7730(u32, u32, u32, u32) asm("_Z16ctarget_001d7730jjjj");
void ctarget_001d7730(u32 a, u32, u32, u32);  // 0x001d7730: definition moved into src/anon/unit_001d7458.cpp
}
