#include "../common/types.h"

struct W1566E32 { u32 a, b, c, d; u32 pad[4]; };
struct W1566H { u8 hdr[16]; W1566E32 arr[4]; };
struct W1566E16 { u32 w[4]; };

extern W1566H D_01e2bfb0;
extern u8 D_00345c08[], D_0034e8b8[], D_0034ee08[];

extern "C" {
void func_00319f88(void*);
void YS__OBJ_ATTACK__clear(void*);
void func_001c0248(void*);
void func_00319fb0(void*);
void func_00105110(void*);

// static init/destruction of a 4-element array of 32-byte objects (ctor clears +0xc, empty dtor)
void wtarget_002e98f0(u32 a, u32 b) asm("_Z16wtarget_002e98f0jjjj");
// 002e98f0: static initialiser, now made by gcc in src/sugi/flare.cpp

// deleting destructor: three vtable levels, member array of 16-byte objects, then operator delete
void func_00319df8(u8* p);  // 0x00319df8: definition moved into src/anon/unit_003197d0.cpp
}
