#include "../common/types.h"
extern void* D_00352ae0[2];
extern s32 D_00352ae8;
extern u8 D_00352b48;
void func_001dc278(u8* p, s32 a1, s32 a2) {  // obj_ctor_vtable
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 0;
    *(u32*)p = (u32)&D_00352b48;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x24) = 0;
    *(f32*)(p + 0x20) = 1.0f;
    if (!D_00352ae0[1]) {
        D_00352ae0[1] = p;
        D_00352ae0[0] = p;
        *(s32*)(p + 0x28) = 0;
    } else {
        *(u8**)((u8*)D_00352ae0[1] + 0x28) = p;
        *(s32*)(p + 0x28) = 0;
        D_00352ae0[1] = p;
    }
    *(s32*)(p + 8) = a1;
    *(s32*)(p + 4) = a2;
    D_00352ae8++;
}
