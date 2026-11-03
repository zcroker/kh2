#include "../common/types.h"

extern "C" {
extern s32 D_0035f200;
extern u8 D_00296f28[];
extern u16 D_00374758[];
s32 func_00289380(s32);
s32 func_00287cd0();
s32 func_00287bc0();
s32 func_00276368();
s32 func_0028acc8(s32);
s32 func_00276888();
void func_00287f90(s32);
void func_00295868();
s32 func_00292630();
void func_00287c30();
void func_0028af18(s32, s32);
void func_00274cf0(s32);
void func_002925c0();
s32 func_00276358();
void func_00276220(s32, s32);
void func_002945e8();
void func_002995e8();
void func_00297050();
void func_00297e68();
void func_002a21b0();
void func_002a2600();
void func_002a0908(s32);
void func_002a77a0();
void func_002a8ac8();
void func_00296b08();
s32 func_00289310(s32);
s32 func_00276398();
void func_00275b60();
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, void*, s32);
s32 func_00242848(s32);
void func_00287da0();
s32 func_00288040();
void func_00288018();
void func_00276150(s32, s32*, s32*);
void func_00276dc0();
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_00296da8(s32);
void func_0028fb28(s32, u16);
void func_00275dd0();
void func_002765e8(s32, s32, s32);
u32 func_00267248();
s32 func_00287c10();
s32 func_00265b88();
s32 func_0028f930(s32);
s32 func_00257970();
s32 func_00256ef0();
void func_00265ab8();
void func_00256ea8();
void func_0028f7e8(s32);
void func_002644a0(s32);
void func_00264be0();
s32 func_0028ae28(u32, s32);
s32 func_00265c10();
void func_0028ab20(u32);
void func_00265c50();
void func_0028fa98(s32);
void func_00256e30();
void func_00267398();
void func_00267280();
void func_002674f8(s32);
void func_00263c60();
void func_0028f6f0(s32);
void func_00265a30();
void func_00256e80();
extern u8 D_00267590[];
extern u32 D_0035f01c;
extern u32 D_0035f020;
extern u8 D_0035f0e8;

void func_00265018(void) {
    u32 sel = func_00267248();
    D_0035f0e8 = 0;
    s32 st = func_00289380(sel);
    s32 mode = func_00287cd0();
    if (mode == 2) {
        s32 f = 0;
        s32 cur = func_00287c10();
        if (func_00265b88() || func_0028f930(1) || func_00257970()) f = 1;
        if (cur == 23) f = f || func_00256ef0();
        if (f) {
            if (st != -1 || func_00289310(sel)) {
                func_00287f90(0);
                func_00265ab8();
                if (cur == 23) func_00256ea8();
            }
        } else {
            func_00265ab8();
            func_00287c30();
            register s32 t asm("$2") = func_00287bc0();
            s32 n;
            {
                /* sched2 tie: gcc puts li a1 in the jal delay slot; the original keeps n's copy there. */
                u32 g = D_0035f01c;
                register u32 a0 asm("$4") = g;
                register u32 a1 asm("$5") = 0x73;
                asm volatile(".set noreorder\n\tjal func_0028af18\n\tmove %0,%1\n\t.set reorder"
                             : "=r"(n) : "r"(t), "r"(a0), "r"(a1)
                             : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13",
                               "$14", "$15", "$24", "$25", "$31", "hi", "lo", "memory");
            }
            func_0028af18(D_0035f020, 0x73);
            func_0028f7e8(1);
            if (n == 23) func_002644a0(0);
            else if (n == 24) func_00264be0();
        }
    } else {
        if (st != -1 || func_00289310(sel)) {
            if (!func_0028ae28(sel, 0) || !func_00265c10()) {
                func_0028ab20(D_0035f01c);
                func_0028ab20(D_0035f020);
                func_00265c50();
                func_0028fa98(-1);
                func_00256e30();
            }
        }
        if (mode == 0 && func_0028ae28(sel, 0) && func_00265c10()) func_00287cc0(1);
        if (!func_00242848(func_00287df0(st, func_00289310(sel), 1, D_00267590, 1))) {
            switch (st) {
            case -4:
                func_00267398();
                func_00287da0();
                break;
            case -13:
            case -12:
                func_00267280();
                break;
            case -11:
            case -10:
                func_002674f8(st == -10);
                func_00263c60();
                func_0028f6f0(1);
                func_00265a30();
                func_00287c00(func_00287bc0());
                func_00287cc0(2);
                break;
            case -1:
                break;
            case -2:
                func_00263c60();
                func_0028f6f0(1);
                func_00265a30();
                func_00256e80();
                func_00287c00(23);
                func_00287c90(1);
                break;
            }
        }
        if (func_00288040()) func_00288018();
    }
}

void func_00296168(void) {
    s32 r = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    s32 m = func_00287bc0();
    if (st == 2) {
        if (func_00276368() != 0 || func_0028acc8(D_0035f200) != 0 || func_00276888() != 0) {
            if (r != -1) {
                func_00287f90(0);
                func_00295868();
            }
            return;
        }
        if (func_00292630() != 0) return;
        func_00295868();
        func_00287c30();
        {
            /* sched2 tie: gcc puts li a1 in the jal delay slot; the original keeps m's copy there. */
            register s32 t asm("$2") = func_00287bc0();
            s32 g = D_0035f200;
            register s32 a0 asm("$4") = g;
            register s32 a1 asm("$5") = 0x73;
            asm volatile(".set noreorder\n\tjal func_0028af18\n\tmove %0,%1\n\t.set reorder"
                         : "=r"(m) : "r"(t), "r"(a0), "r"(a1)
                         : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13",
                           "$14", "$15", "$24", "$25", "$31", "hi", "lo", "memory");
        }
        func_00274cf0(m);
        func_002925c0();
        func_00276220(func_00276358(), 0);
        if (m == 0) {
            func_002945e8();
        } else if (m == 13) {
            func_002995e8();
        } else if (m == 3) {
            func_00297050();
        } else if (m == 4) {
            func_00297e68();
        } else if (m == 7 || m == 9) {
            func_002a21b0();
        } else if (m == 8) {
            func_002a2600();
        } else if (m == 6 || m == 12) {
            func_002a0908(-1);
        } else if (m == 11) {
            func_002a77a0();
        } else if (m == 10) {
            func_002a8ac8();
        }
        return;
    }
    func_00296b08();
    if ((r != -1 || func_00289310(D_0035f200) != 0) && func_00276398() == 0) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398() != 0) {
        func_00287c90(1);
    }
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, D_00296f28, 1)) == 0) {
        s32 x;
        s32 a;
        s32 b0, b1;
        switch (r) {
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -9:
        case -8:
            func_00276150(m, &b0, &b1);
            if (r == -8) {
                x = b1;
                a = 0;
            } else {
                x = b0;
                a = 1;
            }
            func_00276220(a, 1);
            func_00276dc0();
            func_00287c00(x);
            func_00287cc0(2);
            break;
        default: {
            s32 v = func_00296da8(r);
            func_00276220(0, 1);
            func_0028fb28(0, D_00374758[v]);
            s32 k;
            switch (v) {
            case 0: k = 6; break;
            case 1: k = 3; break;
            case 2: k = 4; break;
            case 3: k = 7; break;
            case 4: k = 8; break;
            case 5: k = 9; break;
            case 6: k = 10; break;
            case 7: k = 11; break;
            case 8:
            default: k = 12; break;
            }
            func_00287c00(k);
            func_00275dd0();
            func_00276dc0();
            func_00287cc0(2);
            func_002765e8(m, r, 0);
            break;
        }
        case -2:
            func_00276220(1, 1);
            func_00276dc0();
            func_00287c00(0);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040() != 0) {
        func_00288018();
    }
}

}
