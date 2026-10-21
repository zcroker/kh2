#include "../common/types.h"
extern "C" {
u32 func_00257770();
u32 func_00139d78(u32);
void func_0028f4d8(s32, s32, s32);
u32 func_00257070(s32);
void func_00266df8(u32);
void func_0028d8c0(u32, s32, u32, u32, u32, u32, s32, s32);
void func_0028d980(u32, s32, u32, u32, u32, u32, s32, s32, s32);
void func_00288d80(u32, s32, u32, u32, u32, s32, s16*, s16*);
void func_002fde18(u32, u32, u32);
u32 func_002891b8(u32, s32);
void func_0028dcc0(u32, u32);
void func_00139620(u32);
void func_001395f8(u32);
void func_00138c10(u32, s32);
void func_00138c68(u32, s32, s32);
s32 func_0023aa18(u32);
s32 func_0023aa38(u32);
u32 func_00257140(s32);
void func_0028af90(u32, s32);
void func_002891f0(u32, s32, s32, s32, s32);
u32 func_0028af88(u32);
void func_0028af18(u32, u32);
void func_0028b218(u32, s32);
void func_0028b248(u32, s32);
void func_00266248(void);
void func_00265c78(void);
void func_002666a8(void);
void func_00256cc0(s32, s32, s32);
void func_00287cc0(s32);
extern u32 D_0035ef64, D_0035ef68, D_0035f03c, D_0035f01c, D_0035f020, D_0035f0e4;
extern u32 D_0035ef6c;
extern u16 D_0035ef6c_h asm("D_0035ef6c");
extern s32 D_0035f3d4;
extern s16 D_00373502;
extern u8 D_0035f0e8;

struct Num { s16 n;  };

void func_00264be0(void) {
    s32 i = 3;
    s32 cnt, col, i10, curId, fadeId;
    Num nums[4];
    u32 base = func_00257770();
    func_00139d78(base);
    func_0028f4d8(1, -1, 0);
    func_00266df8(func_00257070(0x17));
    { s16* p = &nums[0].n; while (i >= 0) { *p++ = D_0035ef6c_h; i--; } }
    s32 top = D_0035f3d4;
    func_0028d8c0(base, top - 1, D_0035ef68, D_0035ef64, D_0035f03c, 320, 321, 0);
    curId = top + 1;
    fadeId = top + 2;
    *(u8*)(D_0035f0e4 + 0x20) = 0;
    func_002fde18(D_0035f0e4 + 0x524, 0, 0x280);
    col = D_00373502;
    for (i = 0; i < 2; i++) {
        u32 sel = i ? D_0035f020 : D_0035f01c;
        cnt = 0;
        i10 = i * 10;
        s32 j;
        for (j = 0; j < 10; j++) {
            func_00288d80(sel, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, &nums[0].n, &nums[0].n);
            s32 idx = i10 + j;
            u32 item = func_002891b8(sel, j);
            func_0028dcc0(item, base);
            func_00139620(item);
            u32 cur = base + idx * 0x1B4 + 0x5EF0;
            func_001395f8(item);
            func_00138c10(item, col);
            s32 px = func_0023aa18(item + 0x18);
            s32 py = func_0023aa38(item + 0x18);
            func_00138c10(item, nums[0].n);
            *(u32*)(item + 0x198) = 0;
            func_0028d980(cur, curId, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(2), -1, -1, 0);
            func_0028dcc0(cur, item);
            func_00139620(cur);
            func_001395f8(cur);
            *(u32*)(cur + 0x1B0) = 1;
            func_00138c68(cur, px, py);
            *(void**)(cur + 0x198) = (void*)(D_0035f0e4 + idx * 32 + 0x524);
            u32 fade = base + idx * 0x198 + 0x87D0;
            func_0028d8c0(fade, fadeId, D_0035ef68, D_0035ef64, D_0035f03c, D_0035ef6c, -1, 0);
            func_0028dcc0(fade, item);
            func_00138c68(fade, px, py);
            if (*(u32*)(D_0035f0e4 + 0x18) & (1 << idx)) cnt++;
        }
        func_0028af90(sel, cnt);
    }
    func_002891f0(D_0035f01c, 0, 1, 0, 2);
    func_002891f0(D_0035f020, 0, 1, 0, 2);
    u32 en = func_0028af88(D_0035f01c);
    en |= 0xC0000;
    en |= 0xC000;
    en &= ~0x10;
    func_0028af18(D_0035f01c, en);
    func_0028af18(D_0035f020, en);
    func_0028b218(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 10);
    func_0028b218(D_0035f020, 1);
    func_0028b248(D_0035f020, 10);
    func_00266248();
    func_00265c78();
    func_002666a8();
    D_0035f0e8 = 0;
    func_00256cc0(0xB61A, -1, -1);
    func_00287cc0(0);
}
}
