#include "../common/types.h"
extern "C" {
void func_00294b80(void);
void func_002968d8(void);
void func_00296168(void);
void func_00297630(void);
void func_00298410(void);
void func_00298988(void);
void func_002a2818(void);
void func_00299e70(void);
void func_0029b378(void);
void func_0029ba88(void);
void func_0029c098(void);
void func_0029c5c8(void);
void func_0029f220(void);
void func_0029f938(void);
void func_002af010(void);
void func_002a23a0(void);
void func_002a8d98(void);
void func_002a7a60(void);
void func_002a52b0(void);
void func_002a5a90(void);
void func_002a6be0(void);
void func_002a0cb8(void);
u8* func_00276fa8(void);
void func_00287d68(void);
void func_00276438(void);
s32 func_00287db0(void);
u32 func_00287dc0(void);
s32 func_00139d78(u32);
void func_002749f0(void);
s32 func_002887c8(void);
void func_002766c0(void);
void func_00288750(void (*)(void));
void func_001039f8(void);
s32 func_0023f0c0(u32);
s32 func_00288088(void);
void func_0023f070(u32, s32, s32);
u32 func_00287bc0(void);
extern u32 D_0035f210;
extern u32 D_0035f140;
extern u8 D_0035f222;
s32 func_00275180(void) {
    u8* p = func_00276fa8();
    func_00287d68();
    func_00276438();
    if (func_00287db0()) {
        if (func_00139d78(func_00287dc0())) return 0;
        if (func_00139d78(D_0035f210)) goto out;
        func_002749f0();
        if (D_0035f140 & 4) {
            if (D_0035f222) return 0;
            if (func_002887c8()) {
                D_0035f222 = 1;
                func_00288750(func_002766c0);
            }
        }
        if (D_0035f222) goto out;
        func_001039f8();
        return 1;
    }
    goto other;
out:
    return 0;
other:
    if (func_00139d78(D_0035f210) && func_0023f0c0(D_0035f210) != *(s16*)(p + 4)) {
        if (!func_00288088()) goto out;
        func_0023f070(D_0035f210, *(s16*)(p + 4), -1);
    }
    switch (func_00287bc0()) {
    case 0:
        func_00294b80();
        return 0;
    case 1:
        func_002968d8();
        return 0;
    case 2:
        func_00296168();
        return 0;
    case 3:
        func_00297630();
        return 0;
    case 4:
        func_00298410();
        return 0;
    case 5:
        func_00298988();
        return 0;
    case 8:
        func_002a2818();
        return 0;
    case 13:
        func_00299e70();
        return 0;
    case 14:
        func_0029b378();
        return 0;
    case 15:
    case 18:
    case 21:
        func_0029ba88();
        return 0;
    case 16:
    case 19:
    case 22:
        func_0029c098();
        return 0;
    case 17:
    case 20:
    case 23:
        func_0029c5c8();
        return 0;
    case 24:
        func_0029f220();
        return 0;
    case 25:
        func_0029f938();
        return 0;
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
        func_002af010();
        return 0;
    case 7:
    case 9:
    case 26:
    case 34:
        func_002a23a0();
        return 0;
    case 10:
    case 35:
        func_002a8d98();
        return 0;
    case 11:
    case 36:
        func_002a7a60();
        return 0;
    case 37:
        func_002a52b0();
        return 0;
    case 38:
        func_002a5a90();
        return 0;
    case 39:
        func_002a6be0();
        return 0;
    case 6:
    case 12:
    case 40:
        func_002a0cb8();
        return 0;
    }
    goto out;
}
}
