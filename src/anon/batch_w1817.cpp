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
void func_0022a0f8(u8* p, s32 a1, s32 a2, s32 a3) {
    c_create(p, a1, a3);
    *(s32*)(p + 0x344) = a2;
    c_ftGsPrim(p + 0x20, 4);
    c_setRot(p + 0x20, 0.0f);
    c_ftGsTest(p + 0x20, 0x32001);
    if (a2 == 0) {
        c_setWH(p + 0x20, 100, 100);
        return;
    }
    c_setWH(p + 0x20, 64, 64);
    c_setCenterXY(p + 0x20, -32, -32);
    c_rcGsPrim(p + 0x140, 6);
    c_rcGsTest(p + 0x140, 0x32001);
    c_setWH(p + 0x140, 64, 64);
    c_rcGsPrim(p + 0x240, 6);
    c_rcGsTest(p + 0x240, 0x32001);
    c_setWH(p + 0x240, 64, 64);
}


void func_00190a28(void*, void*);
void func_00190a80(void*, void*);
void func_00190b30(void*, void*);
void func_00191218(void*, void*, f32);
void func_00190f80(void*, void*, f32);
void w920_set_obj(void*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
f32 w920_lockon(void*) asm("_ZN2YS6STATUS14GetLockOnRatioEv");
extern void* D_0034e948;
void wtarget_00190920(u8* self, u32 kind, u8* obj, u32 a3) asm("_Z16wtarget_00190920jjjj");
void wtarget_00190920(u8* self, u32 kind, u8* obj, u32 a3) {
    switch (kind) {
    case 0: func_00190a28(self, obj); break;
    case 1: func_00190a80(self, obj); break;
    case 2: w920_set_obj(self, D_0034e948, 0); break;
    case 3: func_00191218(self, obj, 0.0f); break;
    case 4: func_00190b30(self, obj); break;
    case 5: func_00191218(self, obj, 10000.0f); break;
    case 6: {
        u8* t = *(u8**)(obj + 304);
        if (t) {
            func_00190f80(self, obj, *(f32*)(t + 92) * w920_lockon(self));
        }
        break;
    }
    }
    *(u32*)(self + 12) = kind;
}
}
