#include "../common/types.h"

struct I1E { u16 id; u16 h2; };
struct I1 { u8 b0; u8 b1; u8 n; u8 b3; I1E e[4]; u8 pad20[2]; s16 h22; u32 w24; };
extern "C" {
extern char D_0036e978[];
extern char D_0036e998[];
extern char D_0036e9d0[];
extern char D_0036eb60[];
extern char D_0036eb90[];
extern char D_0036ebc8[];
extern char D_0036ebf0[];
extern char D_0036ec18[];
u32 func_002fdfc8(const char*, ...);  // device_vprintf_va
s32* func_001e3650(void*);  // ptr_add4
s32* func_001e3660_x(s32*, s32) asm("_Z13func_001e3660ji");
static inline void assert_fail_1e3690(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
s32 func_001e3690(u8* o);  // 0x001e3690: definition moved into src/anon/unit_001e0cb8.cpp

extern u32 D_0035f118;
#define G118 ((I1*)D_0035f118)
extern u32 D_0035f104;
extern u32* D_0035f11c;
extern u32 D_0035f100;
extern u32 D_0035f10c;
extern u16* D_0035f114;
extern s8 D_0035f120;
void func_0026e140(s32, s32, s32);
void gspxy_x(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void SetDisableButton_x(void*, u32) asm("_ZN2Tz6Select16SetDisableButtonEj");
u8* Tz__MenuItem__start(s32, s32, s32, u32, u32, u32);
void func_00288ce0(void*, void*, s32, s16*, s16*);
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32);
void Tz__Selector__SetupSelector(void);  // 0x0026df30: definition moved into src/anon/unit_0026c450.cpp

void setOffsetPos_x(void*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
s32 u_call4_00139d78_x(void*) asm("_Z16u_call4_00139d78jjjj");
s32 GetParamEx_x(void*) asm("_ZN2YI8SEQUENCE10GetParamExEv");
u8* GetItemPtr_x(void*, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
s32 GetItemMax_x(void*) asm("_ZN2Tz6Select10GetItemMaxEv");
void Tz__Selector__AdjustSeqPos(void);  // 0x0026e3b0: definition moved into src/anon/unit_0026c450.cpp

}
