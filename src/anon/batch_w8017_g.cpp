#include "../common/types.h"
extern "C" {
u32 func_00287bc0(void);
s16* func_00276fa8(void);
s32 func_00287db0(void);
s32 func_00139d78(void*);
s32 func_0023f0c0(void*);
void func_0023f070(void*, s32, s32);
s32 func_0028acc8(void*);
s32 func_0028acb8(void*);
u8* func_002891b8(void*, s32);
void func_0028aa40(void*);
void func_0028f7a0(void);
void func_0028d5d0(u32);
void func_002748a0(void);
void func_00276e28(void);
void func_0028ce38(void);
void func_00288018(void);
void func_00276438(void);
s32 func_00287cd0(void);
s32 func_0028d008(s32);
s32 func_002891d0(void*);
void func_00275980(s32, s32);
void func_002759e8(s32);
void func_0028d620(u32);
void func_0028cdb8(s32);
s32 func_0028d6e8(u32);
void func_002756f8(void*, u32, s32);
struct VObj { void (**vt)(VObj*); };
extern void* D_0035f200;
extern VObj* D_0035f208;
extern void* D_0035f210;
extern u32 D_0035f218;
extern u8 D_0035f220;
extern u8 D_0035f221;
static inline bool busy_00275438(u8* v) { return *(s32*)(v + 400) || *(s32*)(v + 396); }
static inline void tailL() { if (func_0028d6e8(D_0035f218)) func_0028d5d0(D_0035f218); }
void func_00275438(void);  // 0x00275438: definition moved into src/anon/unit_002748a0.cpp
}
