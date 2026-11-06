#include "../common/types.h"
extern "C" {
s32 func_00287bc0(void);
u8* func_00257770(void);
s32 func_0028b040(u32);
s32 func_00257070(s32);
void func_002713a0(s32, s8**, s32*);
s32 func_00272c20(s32);
void func_002fde18(void*, s32, s32);
u8* func_00273140(s32);
void func_00271710(s32, u8*, s32, s32, s32);
void func_00271828(s32, u8*);
u8* func_00273180(s32, s32);
void func_002595b8(s32, u8*, s32);
extern u32 D_0035f01c;
extern u8* D_0035f12c;
extern s8* D_01e21ed0;
extern s8 D_00373aa8[];

// 002713c8: fills the menu entry list (32-byte entries at base+0xae10) for each target type,
// marking the default selection, and loads icons for types 2 and 4 when flag is set.
void ttarget0_002713c8() asm("_Z17ttarget0_002713c8v");
void ttarget0_002713c8() {
    s32 arr[8];
    s32 count;
    s32 mode;
    s32 flag;
    s32 n;
    s32 k;
    s32 j;
    u8* base;
    s32 sel;
    s32 i;
    s32 m;
    mode = func_00287bc0();
    base = func_00257770();
    if (mode == 25) flag = func_0028b040(D_0035f01c);
    else flag = func_00257070(25);
    func_002713a0(flag, &D_01e21ed0, &count);
    for (i = 0; i < count; i++) {
        arr[i] = func_00272c20(D_01e21ed0[i]);
    }
    j = 0;
    func_002fde18(base + 0xae10, 0, 0x300);
    k = 0;
    func_002fde18(base + 0xb110, 0, 0x60);
    for (i = 0; i < count; i++) {
        n = arr[i];
        for (m = 0; m < n; m++, k++) {
            s32 on = 0;
            s32 t = D_01e21ed0[i];
            sel = -1;
            // switch (t) { case 0: ... case 1: ... } as the compiler's compare tree
            if (t == 1) goto type1;
            if (t >= 2) goto done;
            if (t != 0) goto done;
            on = 1;
            if (mode == 25) sel = D_00373aa8[m];
            goto done;
        type1:
            on = 1;
        done:
            if (D_01e21ed0[i] != 3) {
                s32 a3;
                if (*(s16*)(D_0035f12c + j * 8 + 8) != 0 && func_00273140(j)[2] == 18) {
                    a3 = *(s8*)(D_0035f12c + j * 8 + 10) == 0;
                } else {
                    a3 = *(s8*)(D_0035f12c + j * 8 + 10) == 1;
                }
                func_00271710(*(s16*)(D_0035f12c + j * 8 + 8), base + k * 32 + 0xae10, on, a3, sel);
                j++;
            } else {
                func_00271828(*(s8*)(D_0035f12c + 3), base + k * 32 + 0xae10);
            }
            if (flag) {
                s32 a0 = D_01e21ed0[i];
                if (a0 == 2 || a0 == 4) {
                    func_002595b8(func_00273180(a0, *(s8*)(D_0035f12c + j * 8 + 3))[4], base + k * 4 + 0xb110, 1);
                }
            }
        }
    }
}
}
