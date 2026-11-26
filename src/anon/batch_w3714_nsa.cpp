// 0024c950 (_nsa): partial inline asm. The flag-byte stores to D_0035edf0/D_0035edfc are
// written as single instructions because gcc moves their lui down to the store
// (local-alloc REG_EQUIV); the third heap holder is pinned to $15 (t7).
#include "../common/types.h"
extern "C" {
struct Alloc;
struct AllocVt { u8* (*alloc)(Alloc*, u32, void*); };
struct Alloc { AllocVt* vt; };
struct HeapHolder { u8 pad[0x14]; Alloc* heap; };
extern Alloc* D_0032ba14;
extern HeapHolder* D_00347f80;
extern u8 D_0032bae1;
extern u32 D_00347e40;
extern u32 D_00347e60;
extern u32 D_00347f98;
extern u32 D_0024cda8;
extern u32 D_0035edcc;
extern u32 D_0035edd0;
extern s32 D_0035edd4;
extern s32 D_0035edd8;
extern s32 D_0035eddc;
extern u8* D_0035ede0;
extern u8* D_0035ede4;
extern u8* D_0035ede8;
extern u8* D_0035edec;
extern u8 D_0035edf0;
extern s32 D_0035edf4;
extern u32 D_0035edf8;
extern u8 D_0035edfc;
s32 func_0024dfe0(void);
void func_00287b18(s32, s32);
u32 func_00288be8(s32);
void func_002889f0(u32, s32, s32);
void func_00288f48(u32, s32, s32, s32, s32);
void func_002b3df8(u8*);
void func_00239700(u8*);
void func_0031a838(u8*);
u32 func_00103570(void);
u32 func_001063f0(s32, u32);
void func_002fde18(u32, s32, s32);
void func_0028d068(s32, s32);
u8* func_00103eb0(void);
void TASK_MANAGER__create_thread(u32, s32, s32, u32*, s32);

void func_0024c950(void);  // 0x0024c950: definition moved into src/anon/unit_0024ba58.cpp
}
