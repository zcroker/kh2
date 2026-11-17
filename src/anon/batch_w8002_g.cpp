#include "../common/types.h"
struct Info1ad { s32 a; s32 size; };
struct Ent1ad { s32 v; u8 pad[40]; };
extern "C" {
void func_001adc48();
void func_001adc08(void*, s32, void*);
s32 func_00105ee8(s32);
void func_00168388(void*, u32, void (*)(void*, s32, void*), void*);
void func_001ae4c0(s32, u32, void*);
void func_001ae590(Info1ad*, s32);
void func_002f6698(void (*)());
void func_002fee78(char*, const char*, s32);
extern s32 D_00350c8c;
extern s32 D_00350c90;
extern s32 D_00350c94;
extern s32 D_00350c98;
extern char D_0036d820[];
extern Ent1ad D_01c6cf00[4];
extern s32* D_01c6cfb0;
extern s32* D_01c6cfb4;
extern u32 D_01c6cfb8;
extern s32 D_01c6cfc0[];
extern u8 D_01c94000[];
void func_001adcf8(s32 arg0);  // 0x001adcf8: definition moved into src/anon/unit_001ada38.cpp
}
