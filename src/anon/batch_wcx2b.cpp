#include "../common/types.h"
extern "C" {
s32 func_00287cd0(void);
s32 func_00289380(s32);
s32 func_0028acc8(s32);
s32 func_00289310(s32);
void func_0028abe0(s32);
s32 func_002891e8(s32);
s32 func_0024ac88(void);
void func_002b4388(s32, const char*, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28(s32, s32);
void func_0028ab20(s32);
void func_00287c90(s32);
void func_00287df0(s32, s32, s32, s32, s32);
void func_0028aa40(s32);
void func_00287b08(s32);
void func_00287da0(void);
extern s32 D_0035ed70;
extern s32 D_0035ed74;
extern s32 D_0035ed90;
extern char D_00371f30[];
extern char D_00371ee8[][36];
extern s16 D_00371e78[];

void func_0024a4d0(void) {
    s32 mode = func_00287cd0();
    s32 r = func_00289380(D_0035ed74);
    s32 v;
    if (mode == 2) {
        if (func_0028acc8(D_0035ed74)) {
            if (r == -1 && !func_00289310(D_0035ed74)) return;
            func_0028abe0(D_0035ed74);
            return;
        }
        v = func_002891e8(D_0035ed70);
        if (v == 1 && func_0024ac88()) {
            func_002b4388(D_0035ed90, D_00371f30, 0);
        } else {
            func_002b4388(D_0035ed90, D_00371ee8[v], 0);
        }
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310(D_0035ed74)) {
        if (!func_0028ae28(D_0035ed74, 0)) func_0028ab20(D_0035ed74);
    }
    if (mode == 0 && func_0028ae28(D_0035ed74, 0)) func_00287c90(1);
    func_00287df0(r, func_00289310(D_0035ed74), 0, 0, 1);
    switch (r) {
    case -4:
    case -3:
        break;
    case -2:
    case 1:
        func_0028aa40(D_0035ed74);
        func_00287c90(1);
        break;
    case 0: {
        s32 k = func_002891e8(D_0035ed70);
        if (k == 1 && func_0024ac88()) v = 62;
        else v = D_00371e78[k];
        func_00287b08(v);
        func_00287da0();
        break;
    }
    }
}
}
