#include "../common/types.h"
typedef u8* (*AllocFn)(...);
struct Alloc { AllocFn* vt; };
extern "C" {
void func_002427c0(void);
void func_00253818(s32);
void Tz__CmComm__DataLoad(s32);
void func_00287b18(s32, s32);
void func_00242618(s32, s32);
void func_0028d068(s32, s32);
u8* func_00288be8(s32);
void func_002889f0(u8*, s32, s32);
u8* func_0023ee30(u32);
void func_0031a838(u8*);
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8*);
void YI__LAYOUT__LAYOUT(u8*);
void func_00239700(u8*);
u8* func_00103eb0(void);
void func_002809d8(u32);
void TASK_MANAGER__create_thread(u32, u32, u32, void (*)(u32), u32);
extern u8* D_00347f80;
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_00347e40[];
extern u8 D_0035eb98[];
extern u8* D_0035f250;
extern u8* D_0035f254;
extern u8* D_0035f258;
extern u8* D_0035f25c;
// Startup: builds the global managers (D_0035f250..5c) and starts a thread.
void Tz__GumiGameOver__Init(void);  // 0x00280720: definition moved into src/anon/unit_0027f2b0.cpp
}
