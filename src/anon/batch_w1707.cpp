#include "../common/types.h"
extern "C" {
extern u8 D_0035f0b0;
extern u8 D_0035f0b2;
extern s32 D_0035f674;
s32 func_00240ba0(void);
s32 func_00287cd0(void);
s32 func_002b4fb8(void);
s32 func_00287c10(void);
s32 func_00233e70(s32);
s32 func_00233e60(void);
void func_00287c30(void);
void func_00287d20(s32);
s32 func_00287bc0(void);
void func_002b5c30(s32);
void func_0025cd40(void);
void func_00287cc0(s32);
void func_00240108(void);
s32 func_002b4ff8(void);
s32 func_00287d30(void);
s32 func_00234798(void);
s32 func_00234758(void);
s32 func_002347a8(void);
s32 func_002347b8(void);
s32 func_002347c8(void);
s32 func_002347d8(void);
s32 func_002347e8(void);
s32 func_00240bd0(void);
void func_00240e10(s32);
s32 func_002349c8(s32, s32);
void func_002414c0(void);
void func_00241450(s32);
void func_00240360(s32);
void func_00241008(void);
u32 func_00241160(void);
s32 func_00241358(void);
void func_00241528(void);
void func_002415a0(s32, s32, s32);
void func_00241568(s32);
void func_00241320(void);
s32 func_0028b8d0(s32);
s32 func_00241670(s32);
void func_00241608(s32, s32, s32);
void func_00240450(s32, s32);
void func_00240a70(s32);
void func_00234570(s32, s32);
s32 func_002348a8(s32, s32);
s32 func_00234888(s32, s32);
void func_00240bb0(s32);
void func_00241740(s32);
void func_002417a0(void);
void func_0023d2c8(s32, s32);
void func_00242618(s32, s32);
void func_002b4ee0(void);
void func_00287c00(s32);
void func_002b4c88(s32);
void func_002b5108(s32, s32);
void func_00287bd0(s32, s32);

void func_0025bd98(void) {
    s32 fail = 0;
    s32 id = func_00240ba0();
    u32 flags;
    if (func_00287cd0() == 2) {
        if (func_002b4fb8() != 0) return;
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (func_00233e60() == 0) return;
        }
        func_00287c30();
        func_00287d20(0);
        s32 next = func_00287bc0();
        if (next == 12 || next == 24) {
            func_002b5c30(0);
            if (next == 24) func_0025cd40();
            func_00287cc0(0);
        }
        return;
    }
    func_00240108();
    if (func_002b4ff8() == 0) return;
    if (func_00287cd0() == 0) func_00287cc0(1);
    switch (func_00287d30()) {
    case 30:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                func_00240e10(func_00240bd0());
                func_00287d20(31);
            }
        }
        break;
    case 31:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else if (func_002349c8(id, 0) <= 0) {
                func_002414c0();
                func_00287d20(32);
            } else {
                func_00241450(0);
                func_00287d20(33);
            }
        }
        break;
    case 32:
        if (func_00233e70(0) == 0) {
            if (func_002347a8() != 0) {
                fail = 1;
            } else {
                func_00240360(func_00240bd0());
                func_00241450(0);
                func_00287d20(33);
            }
        }
        break;
    case 33:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                func_00240e10(-4);
                func_00287d20(34);
            }
        }
        break;
    case 34:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else {
                func_00241008();
                flags = func_00241160();
                if (flags & 0xff0) {
                    func_00241358();
                    func_00241528();
                    func_00287d20(35);
                } else {
                    func_00240360(-2);
                    if (!(flags & 2)) {
                        func_00241568(0);
                        func_00287d20(37);
                    } else {
                        func_002415a0(1, 0, 0);
                        func_00287d20(36);
                    }
                }
            }
        }
        break;
    case 35:
        if (func_00233e70(0) == 0) {
            if (func_002347c8() != 0) {
                fail = 1;
            } else {
                func_00241320();
                if (func_00241358() < 0) {
                    flags = func_00241160();
                    func_00240360(-2);
                    if (!(flags & 2)) {
                        func_00241568(0);
                        func_00287d20(37);
                    } else {
                        func_002415a0(1, 0, 0);
                        func_00287d20(36);
                    }
                } else {
                    func_00241528();
                }
            }
        }
        break;
    case 36:
        if (func_00233e70(0) == 0) {
            if (func_002347d8() != 0) {
                fail = 1;
            } else if (func_00241670(func_0028b8d0(D_0035f674)) != 0) {
                func_00240360(-3);
                func_00241568(0);
                func_00287d20(39);
            } else {
                func_00241608(1, 0, func_0028b8d0(D_0035f674));
                func_00287d20(38);
            }
        }
        break;
    case 37:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00241608(1, 0, func_0028b8d0(D_0035f674));
                func_00287d20(38);
            }
        }
        break;
    case 38:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                func_00240360(-3);
                flags = func_00241160();
                if (!(flags & 1)) {
                    func_00241568(0);
                    func_00287d20(39);
                } else {
                    func_00240450(0, func_00240bd0());
                    func_00241608(0, 0, 0);
                    func_00287d20(40);
                }
            }
        }
        break;
    case 39:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00240450(0, func_00240bd0());
                func_00241608(0, 0, 0);
                func_00287d20(40);
            }
        }
        break;
    case 40:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                func_00240360(func_00240bd0());
                func_00240a70(0);
                flags = func_00241160();
                if (flags & 4) {
                    func_00241608(2, 0, 0);
                    func_00287d20(42);
                } else {
                    func_00241568(0);
                    func_00287d20(41);
                }
            }
        }
        break;
    case 41:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00241608(2, 0, 0);
                func_00287d20(42);
            }
        }
        break;
    case 42:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                func_00234570(id, 0);
                func_00287d20(43);
            }
        }
        break;
    case 43:
        if (func_00233e70(0) == 0) {
            id = func_00240ba0();
            if (func_002348a8(id, 0) == 3) {
                fail = 1;
            } else {
                func_00240bb0(func_00234888(id, 0));
                func_00241740(-1);
                func_002417a0();
                func_0023d2c8(id, func_00240bd0());
                func_00242618(12, 1);
                func_002b4ee0();
                func_00287c00(D_0035f0b2 != 0 ? 24 : 12);
                func_00287cc0(2);
                func_00287d20(0);
            }
        }
        break;
    }
    if (fail) {
        func_002b4c88(0);
        func_002b5108(0x8a8b, id);
        func_00287bd0(7, 0);
        func_00234570(id, 0);
        D_0035f0b0 = 0;
    }
}
}
