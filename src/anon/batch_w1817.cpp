#include "../common/types.h"
extern "C" {

void c_create(void*, s32, s32) asm("_ZN2dk5Obj2D6createEii");
void c_setRot(void*, f32) asm("_ZN2dk7Ft4Base6setRotEf");
void c_setCenterXY(void*, s32, s32) asm("_ZN2dk7Ft4Base11setCenterXYEii");
void c_ftGsTest(void*, u64) asm("_ZN2dk7Ft4Base9setGsTestEy");
void c_ftGsPrim(void*, u64) asm("_ZN2dk7Ft4Base9setGsPrimEy");
void c_setWH(void*, u16, u16) asm("_ZN2dk13RectParamBase14setWidthHeightEtt");
void c_rcGsPrim(void*, u64) asm("_ZN2dk8RectBase9setGsPrimEy");
void c_rcGsTest(void*, u64) asm("_ZN2dk8RectBase9setGsTestEy");
void func_0022a0f8(u8* p, s32 a1, s32 a2, s32 a3);  // 0022a0f8: moved to src/sasa/musical_input.cpp (linked unit)


void func_00190a28(void*, void*);
void func_00190a80(void*, void*);
void func_00190b30(void*, void*);
void func_00191218(void*, void*, f32);
void YS__TARGET__search_auto_lockon(void*, void*, f32);
void w920_set_obj(void*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
f32 w920_lockon(void*) asm("_ZN2YS6STATUS14GetLockOnRatioEv");
extern void* D_0034e948;
void wtarget_00190920(u8* self, u32 kind, u8* obj, u32 a3) asm("_Z16wtarget_00190920jjjj");
void wtarget_00190920(u8* self, u32 kind, u8* obj, u32 a3);  // 0x00190920: definition moved into src/anon/unit_001900d0.cpp
}
