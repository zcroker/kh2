#include "../common/types.h"
extern "C" {
u8* func_00257770(void);
u8* func_00281f20(u32);
s32 func_00287bc0(void);
s32 func_0028b040(u32);
s32 func_00285d58(u16);
void func_00285f50(u16);
s32 func_00285e30(u16);
s32 func_002891e8(u32);
void func_00138c10(u8*, s32);
extern u32 D_0035f01c;
extern u32 D_0035f0ec;
extern s32 D_00373730;
extern s32 D_00373734;

void func_0026a900(void) {
    u16* e;
    s32 v;
    u8* p = func_00257770();
    u8* tbl = func_00281f20(D_0035f0ec);
    s32 w = func_00287bc0();
    s32 idx = func_0028b040(D_0035f01c);
    s32 flag = (u32)(w - 5) < 2;
    if (!flag) {
        if (idx == 0) return;
        idx--;
    }
    e = (u16*)(idx * 6 + (u32)tbl);
    if (func_00285d58(*e)) {
        func_00285f50(*e);
        if (func_00285e30(*e)) v = D_00373734;
        else v = D_00373730;
        func_00138c10(p + func_002891e8(D_0035f01c) * 0x198 + 0x87d0, v);
    }
}
}
