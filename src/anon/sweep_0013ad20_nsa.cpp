#include "../common/types.h"
typedef struct Alloc Alloc; typedef struct AllocVt AllocVt; typedef struct Heap Heap;
struct Alloc;
struct AllocVt { void* (*alloc)(Alloc*, u32, u32); };
struct Alloc { AllocVt* vt; };
struct Heap { u8 pad[0x14]; Alloc* a; };

extern Heap* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u8 D_003485b0[];
extern u8 D_003485d0[];
extern void* D_00348050;
extern void* D_00348054;
extern void* D_00348058;
u32 func_001050c8(void);
u8* func_001063c0(u32, u32);
void func_0031a838(void*);
void func_00239700(void*);
void func_002361a0(void*);
void func_0013ad20(void);  // 0x0013ad20: definition moved into src/anon/unit_0013a8b8.cpp
