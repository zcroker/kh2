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
void func_001adcf8(s32 arg0) {
    union { Info1ad info; char buf[48]; } u;
    if (arg0 == -1) {
        s32 sz;
        u32 n;
        func_002f6698(func_001adc48);
        func_001ae590(&u.info, D_00350c94);
        D_01c6cfb0 = D_01c6cfc0;
        n = (u32)(u.info.size + 0x7ff) >> 11;
        func_001ae4c0(u.info.a, n, D_01c6cfb0);
        sz = u.info.size;
        func_001ae590(&u.info, D_00350c98);
        func_001adc08(D_01c6cfb0, sz, &u.info);
        D_01c6cfb4 = (s32*)(((u32)D_01c6cfb0 + *D_01c6cfb0 * 16 + 0x43) & ~0x3f);
        func_001ae590(&u.info, D_00350c8c);
        n = (u32)(u.info.size + 0x7ff) >> 11;
        func_001ae4c0(u.info.a, n, D_01c6cfb4);
        sz = u.info.size;
        func_001ae590((Info1ad*)D_01c94000, D_00350c90);
        func_001adc08(D_01c6cfb4, sz, D_01c94000);
        for (s32 i = 0; i < 4; i++) D_01c6cf00[i].v = 0;
        D_01c6cfb8 = 0;
    } else {
        func_002fee78(u.buf, D_0036d820, func_00105ee8(arg0));
        D_01c6cfb8 = ((u32)D_01c6cfb4 + *D_01c6cfb4 * 16 + 0x43) & ~0x3f;
        func_00168388(u.buf, D_01c6cfb8, func_001adc08, D_01c94000);
    }
}
}
