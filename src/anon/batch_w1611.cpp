#include "../common/types.h"
extern "C" {
extern void* D_0035f200;
s32 func_00242848(s32);
void func_00274cf0(s32);
void func_00275b60();
void func_00276220(s32, s32);
s32 func_00276358();
s32 func_00276368();
s32 func_00276398();
void func_002765e8(s32, s32, s32);
void func_002766b0(s32);
s32 func_00276888();
void func_00276dc0();
s32 func_00287bc0();
void func_00287c00(s32);
void func_00287c30();
void func_00287c90(s32);
void func_00287cc0(s32);
s32 func_00287cd0();
void func_00287da0();
s32 func_00287df0(s32, s32, s32, void*, s32);
void func_00287f90(s32);
void func_00288018();
s32 func_00288040();
s32 func_002891e8(void*);
s32 func_00289310(void*);
s32 func_00289380(void*);
s32 func_0028acc8(void*);
void func_0028af18(void*, s32);
s32 func_0028b038(void*);
void func_0028f6f0(s32);
void func_002925c0();
s32 func_00292630();
void func_002995e8();
void func_0029ee30();
void func_0029ee38();
void func_0029f520();
extern char D_002a0518[];

void func_0029f220(void) {
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                func_0029ee38();
            }
            return;
        }
        if (func_00292630()) return;
        func_0029ee38();
        func_00287c30();
        s32 mode = func_00287bc0();
        func_0028af18(D_0035f200, 0x73);
        func_00276220(func_00276358(), 0);
        if (mode == 13) {
            func_00274cf0(13);
            func_002925c0();
            func_002766b0(0);
            func_002995e8();
        } else if (mode == 25) {
            func_0029f520();
        }
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) {
        func_00287c90(1);
    }
    if (!func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, D_002a0518, 1))) {
        switch (sel) {
        default:
            func_0029ee30();
            func_00276dc0();
            func_00276220(0, 1);
            func_00287c00(25);
            func_00287cc0(2);
            {
                s32 a = func_00287bc0();
                s32 b = func_002891e8(D_0035f200);
                func_002765e8(a, b, func_0028b038(D_0035f200));
            }
            break;
        case -4:
            {
                s32 a = func_00287bc0();
                s32 b = func_002891e8(D_0035f200);
                func_002765e8(a, b, func_0028b038(D_0035f200));
            }
            func_00287da0();
            break;
        case -1:
            break;
        case -2:
            func_0028f6f0(0);
            func_0029ee30();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            {
                s32 a = func_00287bc0();
                s32 b = func_002891e8(D_0035f200);
                func_002765e8(a, b, func_0028b038(D_0035f200));
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

struct O26c;
struct V26c { void* f[6]; void (*draw)(O26c*, s32, s32, s32, s32, s32, s32); };
struct O26c { V26c* vt; };
struct B26c { u8 pad[0x198]; u8 a[4][0x198]; };
extern u8* D_0035f0f4;
extern s32 D_0035f010;
extern u8 D_0035f0f0;
extern s32 D_0035ef68;
extern s32 D_0035ef64;
extern s32 D_0035f03c;
O26c* func_00287dc0(void);
s32 func_00139d78(O26c*);
void func_0023d808(O26c*, s32);
void func_0023ebd0(O26c*, s32);
s32 func_00281128(s32, s32);
void func_00138c78(void*, s32*, s32*);
void func_0023dd28(O26c*, s32, s32, s32);
void func_0023e738(O26c*, s32, s32, s32);
void func_0023e9c8(O26c*, s32, void*);
s32 func_0026d8c0(s32);
s32 func_00281538(s32, s32);
s32 func_0023ec18(O26c*, s32);
s32 func_002811e0(s32, s32);
s32 func_00281238(s32, s32);
void func_0023e858(f32, O26c*, s32);
void func_0023e8b8(f32, O26c*, s32);
void func_0023e8d8(f32, O26c*, s32);
s32 func_002811b0(s32, s32);
void func_0023eae0(O26c*, s32, s32, s32);
void func_0023eac0(O26c*, s32, s32);
void func_0023e958(O26c*, s32, s32, s32, s32, s32);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0023e9e0(O26c*, s32, void*);

void func_0026c140(void) {
    s32 x, y;
    s32 i;
    u8 flag = 0;
    O26c* o = func_00287dc0();
    if (!func_00139d78(o)) {
        func_0023d808(o, 0x7545);
        func_0023ebd0(o, 1);
        y = 0;
        x = 0;
        for (i = 0; i < 4; i++) {
            if (func_00281128(D_0035f010, i)) {
                func_00138c78(D_0035f0f4 + i * 0x1b4 + 0x7f8, &x, &y);
                func_0023dd28(o, i, 0, 0x8a);
                func_0023e738(o, i, (s16)x, (s16)(y - 0x8a));
                func_0023e9c8(o, i, D_0035f0f4 + i * 0x1b4 + 0x7f8);
            }
        }
    }
    y = 0;
    x = 0;
    for (i = 0; i < 4; i++) {
        s32 c = 16;
        s32 id = func_0026d8c0(i);
        if (!func_00281128(D_0035f010, id)) continue;
        if (!func_00281538(D_0035f010, id) || func_0023ec18(o, id)) {
            if (!func_00281538(D_0035f010, id)) flag = 1;
            continue;
        }
        if (i != 0 && func_002811e0(D_0035f010, id) == 3) c = 15;
        o->vt->draw(o, id, func_00281238(D_0035f010, id) | 0x20000000, 0x8b, 2, 0, 0x8a);
        func_0023e858(-100.0f, o, id);
        func_0023e8b8(0.0f, o, id);
        func_0023e8d8(0.0f, o, id);
        if (func_002811b0(D_0035f010, id) == 8) func_0023eae0(o, id, 20, 32);
        func_0023eac0(o, id, c);
        func_0023e958(o, id, 96, 96, 96, -1);
        if (D_0035f0f0) {
            func_0028d8c0(D_0035f0f4 + id * 0x198 + 0x198, c, D_0035ef68, D_0035ef64, D_0035f03c, 125, -1, 0);
            func_0023e9e0(o, id, D_0035f0f4 + id * 0x198 + 0x198);
        }
    }
    D_0035f0f0 = flag;
}

extern void* D_0035f01c;
extern void* D_0035f018;
s32 func_00287c10();
s32 func_002631d8();
s32 func_00262e30();
s32 func_00281c30();
s32 func_002911f8(void*);
void func_00281c50();
void func_00291288(void*);
void func_00262cb8();
void func_002631f8();
void func_0025ffd0();
void func_00261000();
void func_00257718(s32);
s32 func_00262f18();
void func_00262f58();
s32 func_002637e8(s32);
void func_00287bd0(s32, s32);
void func_00261820();
void func_00281b30();
void func_0025f7d8();
void func_002631b0();
void func_00263c60();
void func_00262c40();
void func_00281d48();
void func_00281e20();
extern char D_002638e0[];

void func_00260ce0(void) {
    s32 sel = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 m, f, mode;
        m = func_00287c10();
        if (m != 10) goto L1;
        f = func_00262e30();
    L2:
        if (!f) {
            if (func_00281c30() || func_002911f8(D_0035f018)) f = 1;
        }
        if (f) {
            if (sel == -1 && !func_00289310(D_0035f01c)) return;
            func_00287f90(0);
            func_00281c50();
            func_00291288(D_0035f018);
            if (m == 10) func_00262cb8();
            else func_002631f8();
            return;
        }
        func_00287c30();
        mode = func_00287bc0();
        func_0028af18(D_0035f01c, 0x73);
        if (mode == 10) func_0025ffd0();
        else func_00261000();
        func_00257718(1);
        return;
    L1:
        f = func_002631d8();
        goto L2;
    }
    if ((sel != -1 || func_00289310(D_0035f01c)) && !func_00262f18()) {
        func_00262f58();
    }
    if (st == 0 && func_00262f18()) {
        func_00287c90(1);
    }
    if (!func_00242848(func_00287df0(sel, func_00289310(D_0035f01c), 1, D_002638e0, 1))) {
        switch (sel) {
        default:
            if (!func_002637e8(sel)) {
                func_00257718(0);
                func_00281b30();
                func_0025f7d8();
                func_002631b0();
                func_00287c00(12);
                func_00287c90(1);
            } else {
                func_00287bd0(14, 0);
                func_00261820();
                func_00287cc0(1);
            }
            break;
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -2:
            func_00263c60();
            func_00262c40();
            func_00281b30();
            func_00287c90(1);
            func_00287c00(10);
            func_0025f7d8();
            break;
        }
    }
    if (func_00287cd0() == 1) {
        func_00281d48();
        func_00281e20();
    }
    if (func_00288040()) func_00288018();
}

}
