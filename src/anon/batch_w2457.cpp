#include "../common/types.h"
extern "C" {
extern u16 D_00374548[];
extern u16 D_00374560[];
extern u32 D_00374498;
extern u32 D_003744a0;
u8* func_002924d0(u8*, s32);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
s32 func_0023aa78(u8*);
void func_00138c10(u8*, s32);
void func_00138c68(u8*, s32, s32);
s32 func_00192048(s32);
s32 func_00291370(u8*, s32);
void func_0028dcc0(u8*, u8*);
u8* func_001a80c8(s32);
void func_00192cc0(u8*, u32*, s32);
void func_00291510(u8* obj, s32 mode, s32 id, s32 mask)
{
    u8* p = func_002924d0(obj, id);
    s32 c;
    switch (mode) {
    case 0:
    case 4:
        c = *(s16*)(obj + 11054);
        break;
    case 1:
        c = *(s16*)(obj + 11056);
        break;
    case 2:
        c = *(s16*)(obj + 11060);
        break;
    case 3:
    default:
        c = *(s16*)(obj + 11064);
        break;
    }
    s32 k = 0;
    s32 t;
    u8* o = *(u8**)(obj + 400) + 24;
    s32 x2, y2;
    s32 X = func_0023aa18(o);
    s32 Y = func_0023aa38(o);
    for (u32 i = 0; (s32)i < 9; i++) {
        if (((mask >> i) ^ 1) & 1) continue;
        u8* e = obj + k * 436 + 4;
        if (mode == 1 && i == 8) c = *(s16*)(obj + 11058);
        func_00138c10(e, c);
        s32 x = X;
        s32 h = func_0023aa78(e + 24);
        x2 = func_0023aa18(e + 24);
        y2 = func_0023aa38(e + 24);
        s32 y = Y + h * k;
        func_00138c68(e, x, y);
        if (mode != 0) t = D_00374560[i];
        else t = D_00374548[i];
        if (t == 0) t = D_00374548[i];
        *(s32*)(e + 408) = func_00192048(t);
        if (mode - 2u < 2) {
            e = obj + k * 436 + 2184;
            if (mode == 2) t = *(s16*)(obj + 11062);
            else t = *(s16*)(obj + 11066);
            func_00138c10(e, t);
            func_00138c68(e, X, y);
        }
        x = x2;
        y = y2;
        e = obj + k * 436 + 4364;
        if ((mode == 0 || mode == 4) && i == 8) y += h;
        if (mode == 3) {
            t = func_00291370(obj, 0);
            x = 0;
            y = 0;
            func_0028dcc0(e, obj + k * 436 + 2184);
        } else if (i == 8) {
            t = func_00291370(obj, 2);
            func_0028dcc0(e, obj + k * 436 + 4);
        } else {
            t = func_00291370(obj, 0);
            func_0028dcc0(e, obj + k * 436 + 4);
        }
        func_00138c68(e, x, y);
        func_00138c10(e, t);
        t = -1;
        switch (i) {
        case 0: t = p[7]; break;
        case 1: t = p[4]; break;
        case 2: t = p[5]; break;
        case 3: t = p[6]; break;
        case 4: t = p[9]; break;
        case 5: t = p[10]; break;
        case 6: t = p[11]; break;
        case 7: t = p[12]; break;
        case 8: t = *(u16*)(p + 2); break;
        }
        *(s32*)(e + 432) = 1;
        if (i == 8) {
            u8* it = func_001a80c8(t);
            if (mode == 1) *(s32*)(e + 432) = 2;
            *(s32*)(e + 408) = func_00192048(*(u16*)(it + 8));
        } else {
            if (i - 4 < 4) func_00192cc0(obj + k * 8 + 10904, &D_00374498, 100 - t);
            else func_00192cc0(obj + k * 8 + 10904, &D_003744a0, t);
            *(u8**)(e + 408) = obj + k * 8 + 10904;
        }
        k++;
    }
}
}
