#include "../common/types.h"
extern "C" {
struct T6b8 { u32 x0; s32 x4; };
struct O6b8 { u8 pad[0x30]; void* x30; };
T6b8* func_00102c80(void);
T6b8* func_00104190(void);
s32 func_00102180(T6b8**);
O6b8* func_00102788(s32, s32, s32, void*);
void func_001e0670(void);
extern char D_001e0690[];
void func_001e06b8(void) {
    T6b8* m0 = func_00102c80();
    T6b8* m1 = func_00104190();
    T6b8* list[4];
    func_00102180(list);
    if (list[0] == m0) {
        func_00102788(list[0]->x4, 1, 0x1fbd0, (void*)func_001e0670)->x30 = D_001e0690;
    } else if (list[0] == m1) {
        func_00102788(m1->x4, 0, 0x222e0, (void*)func_001e0670)->x30 = D_001e0690;
    }
}
s32 func_00287bc0(void);
void func_00287d68(void);
void func_00252020(void);
s32 func_00287db0(void);
s32 func_00250fb8(void);
void func_001039f8(void);
void func_00251780(void);
void func_002513b0(void);
u32 func_00251318(void) {
    s32 mode = func_00287bc0();
    func_00287d68();
    func_00252020();
    if (func_00287db0() != 0) {
        if (func_00250fb8() == 0) {
            func_00252020();
            func_001039f8();
            return 1;
        }
        return 0;
    }
    switch (mode) {
    case 0: func_002513b0(); break;
    case 1: func_00251780(); break;
    }
    return 0;
}
void func_00225b88(void);
void func_00225cd8(void);
s32 func_00225aa8(void);
s32 func_00225b00(s32);
s32 func_002263f0(s32*, void*);
s32 func_002ef7b8(void);
s32 func_002ef7a0(s32, s32);
extern s32 D_0035de20;
extern f32 D_0035de1c;
extern s32 D_0035de5c;
extern u8 D_0035de54;
extern char D_0035daf0[];
extern f32 D_00349e10;
void func_00225d30(void) {
    func_00225b88();
    func_00225cd8();
    if (func_00225aa8() == 0) {
        if (func_00225b00(-1) != 0) {
            if (func_002263f0(&D_0035de20, D_0035daf0) != 0) {
                D_0035de1c = (f32)D_0035de20 * 2.0f;
            } else {
                D_0035de54 = 0;
                D_0035de1c = (f32)D_0035de5c * 2.0f;
            }
        } else {
            D_0035de1c = D_0035de1c + D_00349e10;
        }
    }
    if (func_002ef7b8() != 0) {
        D_0035de20 = func_002ef7a0(7, 0);
    } else {
        D_0035de20 = (s32)(D_0035de1c * 0.5f);
    }
}
struct T1968 { s16 a; s16 b; s16 c; };
extern T1968 D_00371968[];
extern s32 D_0035ece8;
extern s32 D_0035ecec;
extern s32 D_0035ecf0;
extern s32 D_0035ecf4;
extern s32 D_0035ecf8;
extern s32 D_0035ecfc;
extern s32 D_0035ed00;
s32 func_00287bc0(void);
s32 func_00287cd0(void);
s32 func_00287db0(void);
s32 func_002887c8(void);
void func_0028dae0(s32, s32);
s32 func_0028acc8(s32);
s32 func_0028acb8(s32);
void func_0028aa40(s32);
s32 func_00139d78(s32);
s32 func_002891e8(s32);
s32 func_00244ee8(s32);
void func_0028dac8(s32, s32);
void func_0028ce38(void);
void func_00244db8(void);
void func_00244888(void);
s32 func_0028d008(s32);
void func_0028cc78(s32, s32, s32, s32, s32, s32);
s32 func_002891d0(s32);
void func_0028cf28(s32, s32);
void func_0028cdb8(s32);
s32 func_00287c50(void);
void func_0028ce98(s32, s32);
void func_00244708(s32, s32, s32);
struct NoTail4b8 { ~NoTail4b8() {} };
void func_002444b8(void) {
    NoTail4b8 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035ecf0, 31);
            if (func_0028acc8(D_0035ece8) != 0 && func_00139d78(D_0035ecf8) != 0) {
                s32 i = func_00244ee8(func_002891e8(D_0035ece8));
                func_0028dae0(D_0035ecf8, D_00371968[i].b);
            }
            func_0028dae0(D_0035ecf4, 34);
            if (func_0028acc8(D_0035ece8) != 0 && func_0028acb8(D_0035ece8) == 0) {
                func_0028aa40(D_0035ece8);
            }
            if (func_0028acc8(D_0035ecec) != 0 && func_0028acb8(D_0035ecec) == 0) {
                func_0028aa40(D_0035ecec);
            }
            func_0028dac8(D_0035ecfc, 32);
            func_0028dac8(D_0035ed00, 40);
        }
        func_0028ce38();
        func_00244db8();
    }
    func_00244888();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035ece8 : D_0035ecec;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                func_0028cc78(side, 0, 0, D_0035ecf0, 15, 14);
                func_0028cf28(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            func_0028ce98(0, side);
        }
        func_00244708(obj, mode, side);
    }
}
extern s32 D_0035ed20;
extern s32 D_0035ed24;
extern s32 D_0035ed28;
extern s32 D_0035ed2c;
extern s32 D_0035ed30;
s32 func_00287bc0(void);
void func_00287d68(void);
void func_00246708(void);
s32 func_00287db0(void);
s32 func_0028acc8(s32);
s32 func_00139d78(s32);
void func_00246f80(void);
void func_001039f8(void);
void func_00246070(void);
void func_00245eb8(void);
u32 func_00245dd0(void) {
    s32 mode = func_00287bc0();
    func_00287d68();
    func_00246708();
    if (func_00287db0() != 0) {
        if (func_0028acc8(D_0035ed20) == 0 && func_0028acc8(D_0035ed24) == 0 &&
            func_00139d78(D_0035ed28) == 0 && func_00139d78(D_0035ed2c) == 0 &&
            func_00139d78(D_0035ed30) == 0) {
            func_00246f80();
            func_001039f8();
            return 1;
        }
        return 0;
    }
    switch (mode) {
    case 0: func_00245eb8(); break;
    case 1: func_00246070(); break;
    }
    return 0;
}
struct T1d40 { s16 a; s16 b; s16 c; };
extern T1d40 D_00371d40[];
extern s32 D_0035ed4c;
extern s32 D_0035ed50;
extern s32 D_0035ed54;
extern s32 D_0035ed58;
extern s32 D_0035ed5c;
s32 func_00287bc0(void);
s32 func_00287cd0(void);
s32 func_00287db0(void);
s32 func_002887c8(void);
void func_0028dae0(s32, s32);
s32 func_0028acc8(s32);
s32 func_0028acb8(s32);
void func_0028aa40(s32);
s32 func_00139d78(s32);
s32 func_002891e8(s32);
void func_0028ce38(void);
void func_00249358(void);
void func_00249098(void);
s32 func_0028d008(s32);
void func_0028cc78(s32, s32, s32, s32, s32, s32);
s32 func_002891d0(s32);
void func_0028cf28(s32, s32);
void func_0028cdb8(s32);
s32 func_00287c50(void);
void func_0028ce98(s32, s32);
void func_00248f50(s32, s32, s32);
struct NoTail8d28 { ~NoTail8d28() {} };
void func_00248d28(void) {
    NoTail8d28 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035ed54, 31);
            if (func_0028acc8(D_0035ed4c) != 0 && func_00139d78(D_0035ed5c) != 0) {
                s32 i = func_002891e8(D_0035ed4c);
                func_0028dae0(D_0035ed5c, D_00371d40[i].b);
            }
            func_0028dae0(D_0035ed58, 34);
            if (func_0028acc8(D_0035ed4c) != 0 && func_0028acb8(D_0035ed4c) == 0) {
                func_0028aa40(D_0035ed4c);
            }
            if (func_0028acc8(D_0035ed50) != 0 && func_0028acb8(D_0035ed50) == 0) {
                func_0028aa40(D_0035ed50);
            }
        }
        func_00249358();
        func_0028ce38();
    }
    func_00249098();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035ed4c : D_0035ed50;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                func_0028cc78(side, 0, 0, D_0035ed54, 15, 14);
                func_0028cf28(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            func_0028ce98(0, side);
        }
        func_00248f50(obj, mode, side);
    }
}
struct Ta710 { s16 a; s16 b; s16 c; };
extern s32 D_0035ed70;
extern s32 D_0035ed74;
extern s32 D_0035ed78;
extern s32 D_0035ed7c;
extern s32 D_0035ed80;
extern s32 D_0035ed84;
extern s32 D_0035ed88;
s32 func_00287bc0(void);
s32 func_00287cd0(void);
s32 func_00287db0(void);
s32 func_002887c8(void);
void func_0028dae0(s32, s32);
s32 func_0028acc8(s32);
s32 func_0028acb8(s32);
void func_0028aa40(s32);
s32 func_00139d78(s32);
s32 func_002891e8(s32);
Ta710* func_0024b1a0(s32);
void func_0028dac8(s32, s32);
void func_0028ce38(void);
void func_0024ab00(void);
s32 func_0028d008(s32);
void func_0028cc78(s32, s32, s32, s32, s32, s32);
s32 func_002891d0(s32);
void func_0028cf28(s32, s32);
void func_0028cdb8(s32);
s32 func_00287c50(void);
void func_0028ce98(s32, s32);
void func_0024a948(s32, s32, s32);
struct NoTaila710 { ~NoTaila710() {} };
void func_0024a710(void) {
    NoTaila710 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035ed78, 31);
            if (func_0028acc8(D_0035ed70) != 0 && func_00139d78(D_0035ed80) != 0) {
                func_0028dae0(D_0035ed80, func_0024b1a0(func_002891e8(D_0035ed70))->b);
            }
            func_0028dae0(D_0035ed7c, 34);
            if (func_0028acc8(D_0035ed70) != 0 && func_0028acb8(D_0035ed70) == 0) {
                func_0028aa40(D_0035ed70);
            }
            if (func_0028acc8(D_0035ed74) != 0 && func_0028acb8(D_0035ed74) == 0) {
                func_0028aa40(D_0035ed74);
            }
            func_0028dac8(D_0035ed84, 32);
            func_0028dac8(D_0035ed88, 40);
        }
        func_0028ce38();
    }
    func_0024ab00();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035ed70 : D_0035ed74;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                func_0028cc78(side, 0, 0, D_0035ed78, 15, 14);
                func_0028cf28(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            func_0028ce98(0, side);
        }
        func_0024a948(obj, mode, side);
    }
}
struct Tc1a8 { s16 a; s16 b; s16 c; };
extern Tc1a8 D_00371ff0[];
extern s32 D_0035eda8;
extern s32 D_0035edac;
extern s32 D_0035edb0;
extern s32 D_0035edb4;
extern s32 D_0035edb8;
s32 func_00287bc0(void);
s32 func_00287cd0(void);
s32 func_00287db0(void);
s32 func_002887c8(void);
void func_0028dae0(s32, s32);
s32 func_0028acc8(s32);
s32 func_0028acb8(s32);
void func_0028aa40(s32);
s32 func_00139d78(s32);
s32 func_002891e8(s32);
void func_0028ce38(void);
void func_0024c828(void);
void func_0024c568(void);
s32 func_0028d008(s32);
void func_0028cc78(s32, s32, s32, s32, s32, s32);
s32 func_002891d0(s32);
void func_0028cf28(s32, s32);
void func_0028cdb8(s32);
s32 func_00287c50(void);
void func_0028ce98(s32, s32);
void func_0024c420(s32, s32, s32);
struct NoTailc1a8 { ~NoTailc1a8() {} };
void func_0024c1a8(void) {
    NoTailc1a8 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035edb0, 31);
            if (func_0028acc8(D_0035eda8) != 0 && func_00139d78(D_0035edb8) != 0) {
                s32 i = func_002891e8(D_0035eda8);
                func_0028dae0(D_0035edb8, D_00371ff0[i].b);
            }
            func_0028dae0(D_0035edb4, 34);
            if (func_0028acc8(D_0035eda8) != 0 && func_0028acb8(D_0035eda8) == 0) {
                func_0028aa40(D_0035eda8);
            }
            if (func_0028acc8(D_0035edac) != 0 && func_0028acb8(D_0035edac) == 0) {
                func_0028aa40(D_0035edac);
            }
        }
        func_0024c828();
        func_0028ce38();
    }
    func_0024c568();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035eda8 : D_0035edac;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                func_0028cc78(side, 0, 0, D_0035edb0, 15, 14);
                func_0028cf28(side, func_002891d0(obj));
                if (side != 0 && func_0028d008(0) == 0) {
                    func_0028cc78(0, 0, 0, D_0035edb0, 15, 14);
                    func_0028cf28(0, func_002891d0(D_0035eda8));
                    func_0028ce98(0, 1);
                }
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            func_0028ce98(0, side);
        }
        func_0024c420(obj, mode, side);
    }
}
struct Tdb28 { s16 a; s16 b; s16 c; };
extern s32 D_0035edcc;
extern s32 D_0035edd0;
extern s32 D_0035edd4;
extern s32 D_0035edd8;
extern s32 D_0035eddc;
extern s32 D_0035ede0;
extern s32 D_0035ede4;
s32 func_00287bc0(void);
s32 func_00287cd0(void);
s32 func_00287db0(void);
s32 func_002887c8(void);
void func_0028dae0(s32, s32);
s32 func_0028acc8(s32);
s32 func_0028acb8(s32);
void func_0028aa40(s32);
s32 func_00139d78(s32);
s32 func_002891e8(s32);
Tdb28* func_0024e008(s32);
void func_0028dac8(s32, s32);
void func_0028ce38(void);
void func_0024e530(void);
void func_0024dea8(void);
s32 func_0028d008(s32);
void func_0028cc78(s32, s32, s32, s32, s32, s32);
s32 func_002891d0(s32);
void func_0028cf28(s32, s32);
void func_0028cdb8(s32);
s32 func_00287c50(void);
void func_0028ce98(s32, s32);
void func_0024dd68(s32, s32, s32);
struct NoTaildb28 { ~NoTaildb28() {} };
void func_0024db28(void) {
    NoTaildb28 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035edd4, 31);
            if (func_0028acc8(D_0035edcc) != 0 && func_00139d78(D_0035eddc) != 0) {
                func_0028dae0(D_0035eddc, func_0024e008(func_002891e8(D_0035edcc))->b);
            }
            func_0028dae0(D_0035edd8, 34);
            if (func_0028acc8(D_0035edcc) != 0 && func_0028acb8(D_0035edcc) == 0) {
                func_0028aa40(D_0035edcc);
            }
            if (func_0028acc8(D_0035edd0) != 0 && func_0028acb8(D_0035edd0) == 0) {
                func_0028aa40(D_0035edd0);
            }
            func_0028dac8(D_0035ede0, 32);
            func_0028dac8(D_0035ede4, 40);
        }
        func_0024e530();
        func_0028ce38();
    }
    func_0024dea8();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035edcc : D_0035edd0;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                func_0028cc78(side, 0, 0, D_0035edd4, 15, 14);
                func_0028cf28(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            func_0028ce98(0, side);
        }
        func_0024dd68(obj, mode, side);
    }
}
struct T0328 { s16 a; s16 b; s16 c; };
extern T0328 D_00372448[];
extern s32 D_0035ee34;
extern s32 D_0035ee38;
extern s32 D_0035ee3c;
extern s32 D_0035ee40;
extern s32 D_0035ee44;
s32 func_00287bc0(void);
s32 func_00287cd0(void);
s32 func_00287db0(void);
s32 func_002887c8(void);
void func_0028dae0(s32, s32);
s32 func_0028acc8(s32);
s32 func_0028acb8(s32);
void func_0028aa40(s32);
s32 func_00139d78(s32);
s32 func_002891e8(s32);
void func_0028ce38(void);
void func_00250928(void);
void func_00250698(void);
s32 func_0028d008(s32);
void func_0028cc78(s32, s32, s32, s32, s32, s32);
s32 func_002891d0(s32);
void func_0028cf28(s32, s32);
void func_0028cdb8(s32);
s32 func_00287c50(void);
void func_0028ce98(s32, s32);
void func_00250550(s32, s32, s32);
struct NoTail0328 { ~NoTail0328() {} };
void func_00250328(void) {
    NoTail0328 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035ee3c, 31);
            if (func_0028acc8(D_0035ee34) != 0 && func_00139d78(D_0035ee44) != 0) {
                s32 i = func_002891e8(D_0035ee34);
                func_0028dae0(D_0035ee44, D_00372448[i].b);
            }
            func_0028dae0(D_0035ee40, 34);
            if (func_0028acc8(D_0035ee34) != 0 && func_0028acb8(D_0035ee34) == 0) {
                func_0028aa40(D_0035ee34);
            }
            if (func_0028acc8(D_0035ee38) != 0 && func_0028acb8(D_0035ee38) == 0) {
                func_0028aa40(D_0035ee38);
            }
        }
        func_00250928();
        func_0028ce38();
    }
    func_00250698();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035ee34 : D_0035ee38;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                func_0028cc78(side, 0, 0, D_0035ee3c, 15, 14);
                func_0028cf28(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            func_0028ce98(0, side);
        }
        func_00250550(obj, mode, side);
    }
}
}
