#include "../common/types.h"
extern "C" {
s32 func_00289380(void*);
s32 func_00287cd0(void);
s32 func_002938e0(void);
s32 func_002938f0(void);
void func_00254ab8(void);
void* func_00287dc0(void);
void func_0023d820(void*);
s32 func_0028acc8(void*);
s32 func_00139d78(void*);
s32 func_0027e920(void);
s32 func_00257970(void);
s32 func_00289310(void*);
void func_00287f90(s32);
void func_0028abe0(void*);
void func_0027e770(void);
void func_00287c30(void);
s32 func_00287bc0(void);
void func_0025f7f0(s32);
void func_002772c8(s32);
void func_0026bc10(void);
void func_002644a0(s32);
void func_0026ee78(void);
void func_0027c5a0(void);
s32 func_0028ae28(void*, s32);
void func_0028ab20(void*);
void func_0027ead0(void);
void func_00256a58(void);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void func_00258118(void);
u8* func_002891b8(void*, s32);
void func_0028fb68(s32, s32);
s32 func_00257fa8(s32);
void func_00257050(s32, s32, s32);
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_00288670(void (*)(void));
void func_00254f80(void);
void func_00287da0(void);
void func_00287c00(s32);
void func_0028aa40(void*);
void func_00263c60(void);
void func_00254e60(void);
void func_0027e6e0(void);
s32 func_002891e8(void*);
s32 func_00288040(void);
void func_00288018(void);
extern void* D_0035f01c;
extern u8 D_0035f056;
extern u8 D_0035f057;
extern u8 D_0035ef60;

void func_00255900(void) {
    s32 r;
    s32 mode;
    void* obj;
    s32 k;

    r = D_0035f057 ? -1 : func_00289380(D_0035f01c);
    mode = func_00287cd0();
    if ((func_002938e0() && func_002938f0()) || !D_0035f056) {
        if (D_0035ef60) {
            if (mode != 2) func_00254ab8();
            else func_0023d820(func_00287dc0());
        }
    }
    if (D_0035f057) return;
    obj = func_00287dc0();
    if (mode == 2) {
        if (func_0028acc8(D_0035f01c) || func_00139d78(obj) || func_0027e920() || func_00257970()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_0028abe0(D_0035f01c);
                func_0027e770();
            }
            return;
        }
        func_00287c30();
        k = func_00287bc0();
        if (k == 1) func_0025f7f0(-1);
        else if (k == 15) func_002772c8(-1);
        else if (k == 20) func_0026bc10();
        else if (k == 23) func_002644a0(1);
        else if (k == 25) func_0026ee78();
        else if (k == 36) func_0027c5a0();
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && !func_0028ae28(D_0035f01c, 0)) {
        func_0028ab20(D_0035f01c);
        func_0027ead0();
    }
    if (mode == 0 && func_0028ae28(D_0035f01c, 0)) {
        func_00256a58();
        func_00287c90(1);
    }
    if (!func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, func_00258118, 1))) {
        switch (r) {
        default:
            k = -1;
            func_0028fb68(0, *(s32*)(func_002891b8(D_0035f01c, r) + 408));
            func_00257050(0, func_00257fa8(r), 0);
            switch (func_00257fa8(r)) {
            case 0:
                k = 1;
                break;
            case 1:
                k = 15;
                break;
            case 2:
                k = 25;
                break;
            case 3:
                k = 20;
                break;
            case 4:
                k = 23;
                break;
            case 5:
            case 6:
                k = -1;
                func_002535b0(func_00257fa8(r) == 5 ? 1 : 2);
                func_00288658(2, 0);
                func_00288670(func_00254f80);
                func_00287da0();
                if (func_002938e0() && !func_002938f0()) func_0023d820(obj);
                break;
            case 7:
                k = 36;
                break;
            }
            if (k >= 0) {
                func_00287c00(k);
                func_0028aa40(D_0035f01c);
                func_00263c60();
                func_00254e60();
                func_0027e6e0();
                func_00287c90(1);
            }
            break;
        case -1:
            break;
        case -2:
        case -4:
            func_00287da0();
            func_00257050(0, func_00257fa8(func_002891e8(D_0035f01c)), 0);
            if (func_002938e0() && !func_002938f0()) func_0023d820(obj);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

struct VT4020 {
    void* f0;
    void (*f4)(void*, void*);
    void* f8;
    void (*fC)(void*);
    void (*f10)(void*);
};
struct VO4020 { VT4020* vt; };
extern u8 D_0035f055;
extern u8 D_0035ef60;
extern u8 D_0035f05b;
extern VO4020* D_0032ba14;
extern u8* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern void* D_0035f010;
extern void* D_0035f014;
extern void* D_0035f018;
extern void* D_0035f01c;
extern void* D_0035f020;
extern void* D_0035f024;
extern u8* D_0035f028;
extern VO4020* D_0035f02c;
extern VO4020* D_0035f030;
extern VO4020* D_0035f034;
extern u8* D_0035f038;
extern VO4020* D_0035f03c;
extern VO4020* D_0035f040;
extern void* D_0035f044;
extern void* D_0035f048;
extern void* D_0035f04c;
extern VO4020* D_0035f050;
void func_00280ee0(void*);
void func_00290c30(void*);
void func_00106420(void*);
void func_00281f10(void*);
void func_00288b00(void*);
void func_00288c20(void*);
void func_00258158(void*);
void func_0031acc0(void*);
void func_0031abd8(void*);
void func_00239870(void*);
void func_0028fdd0(void*);
void func_00290300(void*);
void func_0028ba80(void*);
void func_00285910(void);
void func_0026ed20(void);
void func_0025f6b0(void);
void func_00267608(void);
void func_0026bab8(void);
void func_002643d0(void);
void func_00277008(void);
void func_0027c508(void);
void func_002830b8(void);
void func_0028f3e8(void);
void func_002639f8(void);
void func_002927b8(void);
void func_002816f0(void);
void func_0027dd18(void);
void func_002932f8(void);
void func_00293780(void);
void func_001776a8(void);

void ExitPartyImpl_4020(void) asm("_ZN2Tz5CmTop13ExitPartyImplEz");
void ExitPartyImpl_4020(void) {
    void* p;
    u8* o;
    u8* q;
    u8* r;

    D_0035f055 = 1;
    D_0035ef60 = 0;
    D_0035f05b = 0;
    p = D_0035f010;
    if (p) {
        func_00280ee0(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f010 = 0;
    }
    p = D_0035f018;
    if (p) {
        func_00290c30(p);
        func_00106420(p);
        D_0035f018 = 0;
    }
    p = D_0035f014;
    if (p) {
        func_00281f10(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f014 = 0;
    }
    p = D_0035f01c;
    if (p) {
        func_00288b00(p);
        func_00288c20(p);
        D_0035f01c = 0;
    }
    p = D_0035f020;
    if (p) {
        func_00288b00(p);
        func_00288c20(p);
        D_0035f020 = 0;
    }
    p = D_0035f024;
    if (p) {
        func_00288b00(p);
        func_00288c20(p);
        D_0035f024 = 0;
    }
    if (D_0035f02c) {
        D_0035f02c->vt->f10(D_0035f02c);
        D_0035f02c = 0;
    }
    if (D_0035f028) {
        q = D_0035f028 + ((s32*)D_0035f028)[-1] * 408;
        for (;;) {
            r = D_0035f028;
            if (r == q) break;
            q -= 408;
            (*(VT4020**)q)->fC(q);
        }
        {
            VO4020* a = *(VO4020**)(D_00347f80 + 20);
            a->vt->f4(a, r - 4);
        }
        D_0035f028 = 0;
    }
    if (D_0035f030) {
        D_0035f030->vt->f10(D_0035f030);
        D_0035f030 = 0;
    }
    if (D_0035f034) {
        D_0035f034->vt->f10(D_0035f034);
        D_0035f034 = 0;
    }
    o = D_0035f038;
    if (o) {
        func_00258158(o + 0xb350);
        if (o + 0x87d0) {
            q = o + 0xae10;
            {
                u8* e = o + 0x87d0;
            l1:
                if (e == q) goto l1x;
                q -= 408;
                (*(VT4020**)q)->fC(q);
                goto l1;
            l1x:;
            }
        }
        if (o + 24304) {
            q = o + 0x87d0;
            {
                u8* e = o + 24304;
            l2:
                if (e == q) goto l2x;
                q -= 436;
                (*(VT4020**)q)->fC(q);
                goto l2;
            l2x:;
            }
        }
        if (o + 13840) {
            q = o + 24304;
            {
                u8* e = o + 13840;
            l3:
                if (e == q) goto l3x;
                q -= 436;
                (*(VT4020**)q)->fC(q);
                goto l3;
            l3x:;
            }
        }
        if (o + 3376) {
            q = o + 13840;
            {
                u8* e = o + 3376;
            l4:
                if (e == q) goto l4x;
                q -= 436;
                (*(VT4020**)q)->fC(q);
                goto l4;
            l4x:;
            }
        }
        func_0031acc0(o + 2940);
        func_0031acc0(o + 2504);
        func_0031acc0(o + 2068);
        func_0031acc0(o + 1632);
        func_0031abd8(o + 1224);
        func_0031abd8(o + 816);
        func_0031abd8(o + 408);
        *(u32*)o = (u32)D_00347e60;
        func_00239870(o + 24);
        *(u32*)o = (u32)D_00347f98;
        func_00106420(o);
        D_0035f038 = 0;
    }
    if (D_0035f03c) {
        D_0035f03c->vt->f10(D_0035f03c);
        D_0035f03c = 0;
    }
    if (D_0035f040) {
        D_0035f040->vt->f10(D_0035f040);
        D_0035f040 = 0;
    }
    p = D_0035f044;
    if (p) {
        func_0028fdd0(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f044 = 0;
    }
    p = D_0035f048;
    if (p) {
        func_00290300(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f048 = 0;
    }
    p = D_0035f04c;
    if (p) {
        func_0028ba80(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f04c = 0;
    }
    if (D_0035f050) {
        D_0035f050->vt->f10(D_0035f050);
        D_0035f050 = 0;
    }
    func_00285910();
    func_0026ed20();
    func_0025f6b0();
    func_00267608();
    func_0026bab8();
    func_002643d0();
    func_00277008();
    func_0027c508();
    func_002830b8();
    func_0028f3e8();
    func_002639f8();
    func_002927b8();
    func_002816f0();
    func_0027dd18();
    func_002932f8();
    func_00293780();
    func_001776a8();
}
}
