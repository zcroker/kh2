#include "../common/types.h"
struct Alloc { void (**vt)(Alloc*, ...); };
struct Holder { u8 pad[0x14]; Alloc* al; };
typedef void (*DtorFn)(u8*);
extern "C" {
extern void* D_00347f80;
extern u8 D_00347e60, D_00347f98, D_0035eb98, D_00361e10;
extern u8* D_00361e00;
void func_00170950(s32);
void func_00239870(u8*);
void func_0023c098(u8*);
void func_002369f0(u8*);


static inline void Free(void* p) { Alloc* al = ((Holder*)D_00347f80)->al; al->vt[1](al, p); }
void func_002c9cd8(u8* self);  // 0x2c9cd8: moved to src/anon/unit_002c9998.cpp

}
