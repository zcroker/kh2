#include "../common/types.h"
extern "C" {
extern s32 D_0035f024;
s32 func_00289380(s32);
s32 func_00287cd0(void);
void func_00287bc0(void);
s32 func_002576d0(void);
void func_002575a8(void);
void func_00287c30(void);
void func_00287cc0(s32);
s32 func_00289310(s32);
s32 func_00257610(s32);
void func_00257670(s32);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00257530(s32);
void func_00281d48(void);
void func_00281e20(void);
void Tz__CmEquip__CtrlAbilityWarning(void);  // 0x002693a8: definition moved into src/anon/unit_00268b30.cpp
extern u8* D_0035f2e4;
s32 func_002813b8(void);
s32 func_0027aa78(void);
s32 func_002812e0(void);
static inline bool TestBit(u32* a, u32 b) { return (a[b >> 5] & (1 << (b & 31))) != 0; }
static inline s32 IsOffI(s32 f, s32 i) { return (u8)!((f >> i) & 1); }
s32 Tz__CmNewFlg__isAbilityNewForm(s32 sel, s32 n);  // 0x00286ec8: definition moved into src/anon/unit_00286d28.cpp
}
