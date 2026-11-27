#include "../common/types.h"

extern "C" {
struct Pad { u8 p0[8]; u64 trig; u8 p16[8]; u64 rep; };
struct Cur { u8 p0[4]; s8 count; s8 sel; };
extern Cur* D_0035f260;
Pad* func_00167f18(s32);
s32 func_00287cd0(void);
s32 func_00280290(void);
void func_002802e8(void);
void func_00287bd0(s32, s32);
void func_00280458(void);
void Tz__GumiPause__UpdateAdviceGra(void);
s32 func_00280368(void);
void func_002803e0(void);
void func_00287cc0(s32);
void func_00242618(s32, s32);
void func_00280240(void);
void func_002800d0(void);

void func_0027f9d8(void);  // 0x0027f9d8: definition moved into src/anon/unit_0027f2b0.cpp

}
