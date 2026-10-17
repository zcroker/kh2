#include "../common/types.h"
struct F11c { u8 pad[24]; void (*fn)(s32, s32); };
extern "C" {
s32 func_00289380(u32);
void func_002892f8(u32);
s32 func_00289310(u32);
s32 func_00287df0(s32, s32, s32, s32, s32);
void func_00258af0(s32);
void func_001bbba8(s32);
void func_00242790(void);
s32 func_001bba88(void);
void func_0026e840(void);
void func_00225e28(void);
void func_00136a18(void);
void func_002427c0(void);
void func_00197e68(void);
void func_00287da0(void);
void func_00242660(s32);
extern u32 D_0035f10c;
extern s16* D_0035f114;
extern F11c* D_0035f11c;
extern s8 D_0035f120;
void func_0026e638(s32 a0) {
    s32 r = func_00289380(D_0035f10c);
    func_002892f8(D_0035f10c);
    s32 ret = func_00287df0(r, func_00289310(D_0035f10c), 1, 0, 0);
    switch (r) {
    case -4:
    case -2:
        func_00242790();
        func_00287da0();
        break;
    case -1:
        break;
    default:
        switch ((u16)D_0035f114[r]) {
        case 1:
            func_00258af0(3);
            break;
        case 3:
        case 4:
            func_001bbba8(D_0035f114[r]);
            break;
        case 6:
            func_00242790();
            break;
        case 10:
            func_00258af0(4);
            break;
        case 12:
            if (func_001bba88()) func_0026e840();
            break;
        case 17:
            func_00258af0(1);
            break;
        default:
            if (D_0035f11c && D_0035f11c->fn) D_0035f11c->fn(D_0035f114[r], a0);
            break;
        case 5:
        case 19:
            func_00225e28();
            func_00136a18();
            func_00242790();
            func_002427c0();
            func_00197e68();
            break;
        }
        D_0035f120 = r;
        if (D_0035f114[r] != 12) func_00287da0();
        break;
    }
    if (ret) func_00242660(ret);
}
// ---- 0029fee8
struct List29f {
    s8 count;
    u8 pad[5];
    s8 items[1];
};
s32 func_00276620(s32);
s32 func_00276638(s32);
s32 func_002a01c8(s32);
s32 func_002943e8(s32);
extern List29f* D_0035f5d0;
void func_002765e8(s32, s32, s32);
void func_002a03d0(void);
void func_0029fee8(s32 dir)
{
    s32 top = func_00276620(24);
    s32 cur = func_00276638(24);
    s32 i;

    if (dir == -10) {
        for (i = cur + 1; i < D_0035f5d0->count; i++) {
            if (func_002943e8(func_002a01c8(D_0035f5d0->items[i]))) break;
        }
        if (i >= D_0035f5d0->count) {
            for (i = 0; i < cur; i++) {
                if (func_002943e8(func_002a01c8(D_0035f5d0->items[i]))) break;
            }
        }
        if (i < D_0035f5d0->count) {
            cur = i;
        } else {
            cur = 0;
            top = 0;
        }
    } else {
        for (i = cur - 1; i >= 0; i++)  /* sic: original counts up here */ {
            if (func_002943e8(func_002a01c8(D_0035f5d0->items[i]))) break;
        }
        if (i < 0) {
            for (i = D_0035f5d0->count - 1; i > cur; i--) {
                if (func_002943e8(func_002a01c8(D_0035f5d0->items[i]))) break;
            }
        }
        cur = i;
        if (i < 0) {
            cur = D_0035f5d0->count - 1;
            top = D_0035f5d0->count - 11;
        }
    }
    if (cur - top >= 10) {
        top += cur - top - 9;
    } else if (cur - top < 0) {
        top += cur - top;
    }
    func_002765e8(24, cur - top, top);
    func_002a03d0();
}
}
