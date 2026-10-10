#include "../common/types.h"
extern "C" {
extern s32 D_0035f024;
s32 func_00289380(s32);
s32 func_00287cd0(void);
void func_00287bc0(void);
s32 func_002576d0(void);
void func_002575a8(void);
void func_00287c30(void);
void func_00287cc0(s32);
s32 func_00289310(s32);
s32 func_00257610(s32);
void func_00257670(s32);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00257530(s32);
void func_00281d48(void);
void func_00281e20(void);
void func_002693a8(void) {
    s32 a = func_00289380(D_0035f024);
    s32 b = func_00287cd0();
    func_00287bc0();
    if (b == 2) {
        if (func_002576d0()) return;
        func_002575a8();
        func_00287c30();
        func_00287cc0(1);
        return;
    }
    if (a != -1 || func_00289310(D_0035f024)) {
        if (!func_00257610(0)) func_00257670(0);
    }
    if (b == 0 && func_00257610(0)) func_00287c90(1);
    if (!func_00242848(func_00287df0(a, func_00289310(D_0035f024), 0, 0, 1))) {
        if (a == -2) goto d;
        if (a < -1) goto e;
        if (a == -1) goto e;
        if (a != 0) goto e;
    d:
        func_00257530(0);
        func_00287cc0(2);
    e:;
    }
    func_00281d48();
    func_00281e20();
}
extern u8* D_0035f2e4;
s32 func_002813b8(void);
s32 func_0027aa78(void);
s32 func_002812e0(void);
static inline bool TestBit(u32* a, u32 b) { return (a[b >> 5] & (1 << (b & 31))) != 0; }
static inline s32 IsOffI(s32 f, s32 i) { return (u8)!((f >> i) & 1); }
s32 func_00286ec8(s32 sel, s32 n) {
    s32 res = 0;
    s32 flags = func_002813b8();
    if (func_0027aa78()) flags |= 0x80;
    s32 k = 0;
    for (s32 i = 1; i < 8; i++, k++) {
        if (i == 6) { k--; continue; }
        if (sel >= 0 && i != sel) continue;
        if (func_002812e0() && i != 7) continue;
        if (IsOffI(flags, i)) continue;
        for (s32 j = 0; j < 48; j++) {
            if (n >= 0 && j != n) continue;
            res = TestBit((u32*)(D_0035f2e4 + 164), k * 48 + j);
            if (res) break;
        }
        if (res) break;
    }
    return res;
}
}
