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

void func_0026c140(void);  // 0x0026c140: definition moved into src/anon/unit_0026c140.cpp

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

void func_00260ce0(void);  // 0x00260ce0: definition moved into src/anon/unit_0025f6b8.cpp

}
