// Linked unit 0x002b05f8-0x002b0950 (C, was src/anon/batch_w1910_nsa.c).
#include "../common/types.h"
struct Bf { u32 b0 : 1; u32 rest : 15; } __attribute__((packed,aligned(2)));
typedef struct Bf Bf;
struct Fl { u8 pad[486]; Bf h486; };
extern void* D_0035f200;
extern void* D_0035f214;
s32 func_00289380(void*);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
struct Fl* func_002a9d68(void);
s32 func_00287c10(void);
s32 func_00276368(void);
s32 func_0028acc8(void*);
s32 func_00276888(void);
void func_00287f90(s32);
void func_002aecf0(s32);
void func_00287c30(void);
void func_0028af18(void*, s32);
void func_00276690(s32);
s32 func_00276358(void);
void Tz__Jiminy__SetParentSeqNum(s32, s32);
void func_002aed60(void);
void func_002afaf0(void);
s32 func_00289310(void*);
s32 func_00276398(void);
void func_00275b60(void);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, void*, s32);
void func_002b3b78(void);
s32 func_00242848(s32);
s32 func_0028b038(void*);
void Tz__ScrollBar__SetPos(void*, s32);
void func_002aece8(void);
void Tz__Jiminy__FadeOutHelp(void);
s32 func_00276608(s32);
s32 func_002b2338(s32);
void Tz__JmPuzzle__RequestGraLoad(s32);
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_00288040(void);
void func_00288018(void);
s32 func_002891e8(void*);
void func_002765e8(s32, s32, s32);
void func_00287da0(void);

void Tz__JmPuzzle__CtrlTutorial(void) {
    s32 r = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    s32 m = func_00287bc0();
    struct Fl* f = func_002a9d68();
    if (st == 2) {
        s32 n = func_00287c10();
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (r != -1) {
                func_00287f90(0);
                func_002aecf0(n != 29);
            }
            return;
        }
        func_002aecf0(n != 29);
        func_00287c30();
        m = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_00276690(0);
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        switch (m) {
        case 29: func_002afaf0(); return;
        case 27: func_002aed60(); return;
        }
        return;
    }
    if (r != -1 || func_00289310(D_0035f200)) {
        if (!func_00276398()) {
            Tz__Jiminy__SetParentSeqNum(0, 2);
            func_00275b60();
        }
    }
    if (st == 0 && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, (void*)func_002b3b78, 1))) {
        if (func_00289310(D_0035f200)) Tz__ScrollBar__SetPos(D_0035f214, func_0028b038(D_0035f200));
        switch (r) {
        case -4:
            if (!f->h486.b0) f->h486.b0 = 1;
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
        default: {
        s32 v = 1;
        func_002aece8();
        Tz__Jiminy__FadeOutHelp();
        if (!f->h486.b0) {
            f->h486.b0 = 1;
            v = m != 30;
        }
        Tz__Jiminy__SetParentSeqNum(v, 1);
        v = 27;
        if (m == 30) {
            v = 29;
            Tz__JmPuzzle__RequestGraLoad(func_002b2338(func_00276608(28)));
        }
        func_00287c00(v);
        func_00287cc0(2);
        break;
        }}
    }
    if (func_00288040()) func_00288018();
}
