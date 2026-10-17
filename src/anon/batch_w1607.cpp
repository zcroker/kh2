#include "../common/types.h"
struct E270 { s16 id; s8 a; s8 b; u8 pad[4]; };
struct T270 { u8 pad[3]; s8 h3; u8 pad2[4]; E270 e[1]; };
struct L270 { u16 id; u16 pad[2]; };
struct R270 { u8 pad[5]; u8 f5; };
extern "C" {
struct Pad2a23a0 { u64 a; u64 b; u64 c; u64 d; };
Pad2a23a0* func_00167f18(s32);
void func_00242618(s32, s32);
void func_00274cf0(s32);
void func_00276220(s32, s32);
s32 func_00276358(void);
s32 func_00276368(void);
s32 func_00276398(void);
s32 func_00276888(void);
void func_00276dc0(void);
s32 func_00287bc0(void);
void func_00287c00(s32);
void func_00287c30(void);
void func_00287cc0(s32);
s32 func_00287cd0(void);
void func_00287da0(void);
void func_00287f90(s32);
void func_00288018(void);
s32 func_00288040(void);
void func_0028f6f0(s32);
void func_002925c0(void);
s32 func_00292630(void);
void func_002958b0(void);
void func_002995e8(void);
void func_002a2148(void);
void func_002a2150(void);
s32 func_002a40c8(void);
void func_002a4470(void);
void func_002a45a0(void);
void func_002a4620(Pad2a23a0*);
void func_002a23a0(void) {
    Pad2a23a0* pad = func_00167f18(0);
    s32 st = func_00287cd0();
    s32 sub = func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_00276888() || func_002a40c8()) {
            if (pad->b & 0xc1fc) {
                func_00287f90(0);
                func_002a2150();
            }
        } else if (func_00292630() == 0) {
            func_002a2150();
            func_00287c30();
            sub = func_00287bc0();
            func_00276220(func_00276358(), 0);
            func_00274cf0(sub);
            func_002925c0();
            if (sub == 13) {
                func_002995e8();
                return;
            }
            if (sub == st) {
                func_002958b0();
            }
        }
    } else {
        if ((pad->b & 0xc1fc) && func_00276398() == 0) {
            func_00276220(0, 2);
        }
        if (st == 0 && func_00276398()) {
            func_002a4470();
            func_00287cc0(1);
        }
        if (pad->d & 0xc0f0) {
            func_002a4620(pad);
        } else {
            u64 b = pad->b;
            if (b & 0x100) {
                func_00242618(5, 1);
                func_002a45a0();
                func_00287da0();
            } else if (b & 8) {
                s32 m;
                func_00242618(3, 1);
                func_0028f6f0(0);
                func_002a2148();
                func_00276dc0();
                func_002a45a0();
                func_00276220(1, 1);
                if (sub == 26 || sub == 34) m = 13; else m = 2;
                func_00287c00(m);
                func_00287cc0(2);
            }
        }
        if (func_00288040()) {
            func_00288018();
        }
    }
}
void func_002aed60(void);
void func_002a2818(void) {
    Pad2a23a0* pad = func_00167f18(0);
    s32 st = func_00287cd0();
    s32 sub = func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_00276888() || func_002a40c8()) {
            if (pad->b & 0xc1fc) {
                func_00287f90(0);
                func_002a2150();
            }
        } else if (func_00292630() == 0) {
            func_002a2150();
            func_00287c30();
            sub = func_00287bc0();
            func_00276220(func_00276358(), 0);
            func_00274cf0(sub);
            func_002925c0();
            if (sub == 27) {
                func_002aed60();
                return;
            }
            if (sub == st) {
                func_002958b0();
            }
        }
    } else {
        if ((pad->b & 0xc1fc) && func_00276398() == 0) {
            func_00276220(0, 2);
        }
        if (st == 0 && func_00276398()) {
            func_002a4470();
            func_00287cc0(1);
        }
        if (pad->d & 0xc0f0) {
            func_002a4620(pad);
        } else {
            u64 b = pad->b;
            if (b & 0x100) {
                func_00242618(5, 1);
                func_002a45a0();
                func_00287da0();
            } else if (b & 8) {
                s32 m;
                func_00242618(3, 1);
                if (sub == 33) {
                    func_0028f6f0(1);
                    m = 27;
                } else {
                    func_0028f6f0(0);
                    m = 2;
                }
                func_00287c00(m);
                func_002a2148();
                func_00276dc0();
                func_002a45a0();
                func_00276220(1, 1);
                func_00287cc0(2);
            }
        }
        if (func_00288040()) {
            func_00288018();
        }
    }
}
extern s32 D_0035f01c;
void func_0027c3e0(void);
s32 func_00289380(s32);
s32 func_00287c10(void);
s32 func_0027ad80(void);
s32 func_0028f930(s32);
s32 func_00256ef0(void);
s32 func_00289310(s32);
void func_0027acf8(void);
void func_00279040(void);
void func_00277d20(void);
s32 func_0027a990(void);
void func_0027aa10(void);
void func_0028fa98(s32);
void func_0027b6b8(void);
void func_00287c90(s32);
s32 func_0028afa8(s32);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void func_0027c1c0(void);
void func_00263c60(void);
void func_00256e80(void);
void func_0027ac38(void);
void func_00287bd0(s32, s32);
void func_002831e0(s32, s32);
void func_00278dd0(void) {
    s32 r = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 m = func_00287c10();
        if (func_0027ad80() || func_0028f930(2) || func_00256ef0()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_0027acf8();
            }
        } else {
            func_00287c30();
            if (m == 16) {
                func_00279040();
                func_00277d20();
            }
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && func_0027a990() == 0) {
        func_0027aa10();
        func_0028fa98(-1);
    }
    if (st == 0 && func_0027a990()) {
        func_0027b6b8();
        func_00287c90(1);
    }
    {
        s32 n = func_0028afa8(D_0035f01c);
        if (func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, func_0027c3e0, 1)) == 0) {
            switch (r) {
            case -1:
                break;
            default:
                if (r < 0 || r >= n) break;
                func_0027c1c0();
            case -2:
                func_00263c60();
                func_00256e80();
                func_0028f6f0(2);
                func_0027ac38();
                func_00287c90(1);
                func_00287c00(16);
                break;
            case -7: {
                s32 m = func_00287bc0();
                func_00287bd0(37, 0);
                func_002831e0(2, m);
                break;
            }
            case -4:
                func_00287da0();
                break;
            }
        }
    }
    if (func_00288040()) {
        func_00288018();
    }
}
extern T270* D_0035f12c;
extern s32 D_0035f014;
extern s32 D_0035f04c;
s32 func_002570a0(s32);
u32 func_00272b60(s32);
s32 func_00281f18(s32);
L270* func_00281f20(s32);
R270* func_00273180(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
void func_0028afd0(s32, s32);
void func_0028be78(s32, s32);
void func_00270648(void) {
    s32 max = 0;
    s32 cur = 0;
    s32 top = 0;
    s32 idx = func_002570a0(26);
    s32 i;
    switch (func_00272b60(idx)) {
    case 0: {
        s32 n = func_00281f18(D_0035f014);
        s16 id = D_0035f12c->e[idx].id;
        if (id == 0) {
            cur = 0;
        } else {
            L270* l = func_00281f20(D_0035f014);
            for (i = 0; i < n; i++) {
                if (l[i].id == id) {
                    cur = i + 1;
                    break;
                }
            }
        }
        max = n + 1;
        break;
    }
    case 1:
        max = 2;
        cur = D_0035f12c->e[idx].a != 0;
        break;
    case 2:
        max = 2;
        if (func_002570a0(25)) {
            idx--;
            max = 4;
        }
        cur = D_0035f12c->e[idx].a != 0;
        if (func_002570a0(25) && D_0035f12c->e[idx].b == 2) cur += 2;
        break;
    case 3:
        max = 6;
        for (i = 0; i < 6; i++) {
            if (D_0035f12c->h3 == func_00273180(3, i)->f5) {
                cur = i;
                break;
            }
        }
        break;
    case 4:
        max = 3;
        if (func_002570a0(25)) idx--;
        for (i = 0; i < 3; i++) {
            if (D_0035f12c->e[idx].b == func_00273180(4, i)->f5) {
                cur = i;
                break;
            }
        }
        break;
    }
    if (cur >= 8) {
        top = cur - 7;
        cur = 7;
    }
    if (top + cur >= max) {
        top = cur - max + 1;
        cur = max - 1;
    }
    func_002891f0(D_0035f01c, cur, 0, -1, -1);
    func_0028afd0(D_0035f01c, top);
    func_0028be78(D_0035f04c, top);
}
}
