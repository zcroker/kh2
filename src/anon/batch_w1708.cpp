#include "../common/types.h"
extern "C" {
extern u8 D_0035f0b0;
extern s32 D_0035eca4;
extern s32 D_0035f674;
s32 func_00240ba0(void);
s32 func_00287cd0(void);
s32 func_002b4fb8(void);
s32 func_002b4ff8(void);
void func_00287c30(void);
s32 func_00287bc0(void);
void func_00287cc0(s32);
s32 func_00287d30(void);
void func_00240108(void);
s32 func_001058e8(void);
s32 func_001058d8(s32);
s32 func_002421e8(s32);
void func_002420d8(s32, s32);
s32 func_00233e70(s32);
s32 func_00234758(void);
s32 func_00234798(void);
s32 func_002347a8(void);
s32 func_002347b8(void);
s32 func_002347c8(void);
s32 func_002347d8(void);
s32 func_002347e8(void);
s32 func_002349c8(s32, s32);
s32 func_002348a8(s32, s32);
s32 func_00234888(s32, s32);
void func_00234570(s32, s32);
void func_00241450(s32);
void func_00287d20(s32);
void func_00287bd0(s32, s32);
void func_00287c00(s32);
void func_002400f8(s32);
void func_002b5108(s32, s32);
void func_002b4c88(s32);
s32 func_00240bd0(void);
void func_00240e10(s32);
void func_00240360(s32);
void func_00240450(s32, s32);
void func_00240bb0(s32);
void func_002414c0(void);
void func_00241008(void);
u32 func_00241160(void);
void func_00241320(void);
s32 func_00241358(void);
void func_00241528(void);
void func_00241568(s32);
void func_002415a0(s32, s32, s32);
void func_00241608(s32, s32, s32);
s32 func_00241670(s32);
s32 func_00241a48(void);
void func_00241a70(void);
s32 func_002420d0(s32);
void func_00242110(s32);
s32 func_00242180(s32);
void func_002421c0(s32);
s32 func_0028b8d0(s32);
s32 func_0028b8d8(s32);

void func_0025c3c0(void) {
    s32 fail = 0;
    s32 id = func_00240ba0();
    u32 flags;
    if (func_00287cd0() == 2) {
        if (func_002b4fb8() != 0) return;
        func_00287c30();
        func_00287d20(0);
        if (func_00287bc0() != 0xf) return;
        func_00241450(1);
        func_00287bd0(0xf, 0);
        func_00287d20(0x1e);
        func_002400f8(0);
        func_00287cc0(0);
        return;
    }
    func_00240108();
    if (func_002b4ff8() == 0) return;
    if (func_00287cd0() == 0) {
        func_00287cc0(1);
        if (func_001058d8(func_001058e8()) != 0 && func_002421e8(D_0035eca4) == 0) {
            func_002420d8(D_0035eca4, 1);
        }
    }
    switch (func_00287d30()) {
    case 0x46:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                func_00240e10(func_00240bd0());
                func_00287d20(0x47);
            }
        }
        break;
    case 0x47:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else if (func_002349c8(id, 0) <= 0) {
                func_002414c0();
                func_00287d20(0x48);
            } else {
                func_00241450(0);
                func_00287d20(0x49);
            }
        }
        break;
    case 0x48:
        if (func_00233e70(0) == 0) {
            if (func_002347a8() != 0) {
                fail = 1;
            } else {
                func_00240360(func_00240bd0());
                func_00241450(0);
                func_00287d20(0x49);
            }
        }
        break;
    case 0x49:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                func_00240e10(-4);
                func_00287d20(0x4a);
            }
        }
        break;
    case 0x4a:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else {
                func_00241008();
                flags = func_00241160();
                if (flags & 0xff0) {
                    func_00241358();
                    func_00241528();
                    func_00287d20(0x4b);
                } else {
                    func_00240360(-2);
                    if (!(flags & 2)) {
                        func_00241568(0);
                        func_00287d20(0x4d);
                    } else {
                        func_002415a0(1, 0, 0);
                        func_00287d20(0x4c);
                    }
                }
            }
        }
        break;
    case 0x4b:
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
                        func_00287d20(0x4d);
                    } else {
                        func_002415a0(1, 0, 0);
                        func_00287d20(0x4c);
                    }
                } else {
                    func_00241528();
                }
            }
        }
        break;
    case 0x4c:
        if (func_00233e70(0) == 0) {
            if (func_002347d8() != 0) {
                fail = 1;
            } else if (func_00241670(func_0028b8d0(D_0035f674)) != 0) {
                func_00240360(-3);
                func_00241568(0);
                func_00287d20(0x4f);
            } else {
                func_00241608(1, 0, func_0028b8d8(D_0035f674));
                func_00287d20(0x4e);
            }
        }
        break;
    case 0x4d:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00241608(1, 0, func_0028b8d8(D_0035f674));
                func_00287d20(0x4e);
            }
        }
        break;
    case 0x4e:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                func_00240360(-3);
                flags = func_00241160();
                bool no = !(flags & 1);
                if (no) {
                    func_00241568(0);
                    func_00287d20(0x4f);
                } else {
                    func_00240450(0, func_00240bd0());
                    func_00241608(0, 0, 0);
                    func_00287d20(0x50);
                }
            }
        }
        break;
    case 0x4f:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_00240450(0, func_00240bd0());
                func_00241608(0, 0, 0);
                func_00287d20(0x50);
            }
        }
        break;
    case 0x50:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                func_00240360(func_00240bd0());
                flags = func_00241160();
                if (!(flags & 4)) {
                    func_00241568(0);
                    func_00287d20(0x51);
                } else if (flags & 2) {
                    bool no = !(flags & 1);
                    if (no) {
                        func_002421c0(D_0035eca4);
                        func_00287d20(0x53);
                    } else {
                        func_002415a0(2, 0, func_002420d0(D_0035eca4));
                        func_00287d20(0x52);
                    }
                } else {
                    func_002421c0(D_0035eca4);
                    func_00287d20(0x53);
                }
            }
        }
        break;
    case 0x51:
        if (func_00233e70(0) == 0) {
            if (func_002347b8() != 0) {
                fail = 1;
            } else {
                func_002421c0(D_0035eca4);
                func_00287d20(0x53);
            }
        }
        break;
    case 0x52:
        if (func_00233e70(0) == 0) {
            if (func_002347d8() != 0) {
                fail = 1;
            } else if (func_00242180(D_0035eca4) != 0) {
                func_00287d20(0x53);
            } else {
                func_002421c0(D_0035eca4);
                func_00287d20(0x53);
            }
        }
        break;
    case 0x53:
        func_00242110(D_0035eca4);
        func_00241608(2, 0, func_002420d0(D_0035eca4));
        func_00287d20(0x54);
        break;
    case 0x54:
        if (func_00233e70(0) == 0) {
            if (func_002347e8() != 0) {
                fail = 1;
            } else {
                func_00234570(id, 0);
                func_00287d20(0x55);
            }
        }
        break;
    case 0x55:
        if (func_00233e70(0) == 0) {
            id = func_00240ba0();
            if (func_002348a8(id, 0) == 3) {
                fail = 1;
            } else {
                func_00240bb0(func_00234888(id, 0));
                if (func_00241a48() == 0) func_00241a70();
                func_00287c00(0xf);
                func_00287d20(0);
                func_00287cc0(2);
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
        func_002400f8(0);
    }
}
}
