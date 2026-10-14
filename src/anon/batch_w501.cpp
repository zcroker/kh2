#include "../common/types.h"

// Menu/pad-help selector update (Tz menu): keeps the three Select lists,
// the menu cursor slots and the LightCur in sync with the menu mode.

struct SelItem {
    u8 pad[0x18c];
    void* sub;      // 0x18c
    s32 active;     // 0x190
};

struct VObj;
struct VObjVt {
    void* f[5];
    void (*update)(VObj*); // 0x14
};
struct VObj {
    VObjVt* vt;
};

struct LightCur {
    VObjVt* vt;
    u8 pad[0x188];
    void* target;   // 0x18c
};

extern "C" {
s32 func_00287bc0(void);
s32 func_00287db0(void);
s32 func_002887c8(void);
s32 func_00139d78(void*);
s32 func_0023f0c0(u32);
void func_0023f070(u32, s32, s32);
s32 func_0028acc8(u32);
s32 func_0028acb8(u32);
SelItem* func_002891b8(u32, s32);
void func_0028aa40(u32);
void func_00254e60(void);
void func_0028f7a0(void);
void func_0028d5d0(LightCur*);
void func_0028ffe8(u32, s32);
void func_00290508(u32, s32);
void func_0025f6b8(void);
void func_002676e8(void);
void func_0026bbe0(void);
void func_0026ede0(void);
void func_002770a8(void);
void func_0027c540(void);
void func_00283180(void);
void func_0027e6e0(void);
void func_00264408(void);
void func_00263d28(void);
void func_00288018(void);
void func_0028ce38(void);
void func_00256f18(void);
u32 func_00267248(void);
SelItem* func_002891d0(u32);
void func_00258080(s32*, s32*);
s32 func_00287cd0(void);
s32 func_0028d008(s32);
void func_0028cc78(s32, u32, u32, u32, s32, s32);
void func_0028cf28(s32, void*);
s32 func_0028d6e8(LightCur*);
void func_0028d1c0(LightCur*, s32, u32, u32, u32, void*, s32);
void func_0028ce98(s32, s32);
void func_0028d660(LightCur*, void*);
s32 func_0028cf10(s32);
void func_0028cdb8(s32);
void func_002566f0(u32, s32, s32);
s32 func_00289310(u32);
void func_0026a3b8(s32, s32);
void func_0026d620(s32, s32);
void func_00273368(s32, s32);
void func_0027bd40(s32, s32);
void func_002633a8(s32, s32);

extern u32 D_0035ef64;
extern u32 D_0035ef68;
extern u32 D_0035f01c;
extern u32 D_0035f020;
extern u32 D_0035f024;
extern VObj* D_0035f030;
extern u32 D_0035f03c;
extern u32 D_0035f044;
extern u32 D_0035f048;
extern LightCur* D_0035f050;
extern u8 D_0035f054;
extern u8 D_0035f055;
extern u8 D_003729b0[];

static inline u8 isBusy(SelItem* it)
{
    u8 busy = 0;
    if (it->active || it->sub) busy = 1;
    return busy;
}

#define START_IF_IDLE(sel)                                          \
    if (func_0028acc8(sel) && !func_0028acb8(sel)) {                \
        if (!isBusy(func_002891b8(sel, 0))) func_0028aa40(sel);     \
    }

void func_00255df0(void)
{
    s32 mode = func_00287bc0();

    if (func_00287db0()) {
        if (!func_002887c8()) {
            if (func_00139d78((void*)D_0035f03c)) {
                if (func_0023f0c0(D_0035f03c) != 2) func_0023f070(D_0035f03c, 2, -1);
            }
            START_IF_IDLE(D_0035f01c)
            START_IF_IDLE(D_0035f020)
            START_IF_IDLE(D_0035f024)
            func_00254e60();
            func_0028f7a0();
            func_0028d5d0(D_0035f050);
            func_0028ffe8(D_0035f044, 1);
            func_00290508(D_0035f048, 1);
            func_0025f6b8();
            func_002676e8();
            func_0026bbe0();
            func_0026ede0();
            func_002770a8();
            func_0027c540();
            func_00283180();
            func_0027e6e0();
            func_00264408();
        }
        if (func_00139d78(D_0035f030)) D_0035f030->vt->update(D_0035f030);
        func_00263d28();
        func_00288018();
        func_0028ce38();
    }
    func_00256f18();
    if (func_00287db0()) return;

    u32 sel;
    if (mode == 3 || mode == 4 || mode == 22 || mode == 21 || mode == 28 || mode == 13 || mode == 14) {
        sel = D_0035f024;
    } else if (mode == 12) {
        sel = D_0035f020;
    } else if (mode == 24) {
        sel = func_00267248();
    } else {
        sel = D_0035f01c;
    }

    s32 n;
    if (sel == D_0035f020) n = 1;
    else if (sel == D_0035f024 && func_0028acc8(D_0035f01c)) n = (mode == 13) ? 2 : 1;
    else n = 0;
    if (mode == 21 || mode == 24) n = 0;

    if (D_0035f054 == 0) {
        void* target = 0;
        if (func_0028acc8(sel)) {
            if (mode == 36) target = func_002891d0(sel)->sub;
            else target = func_002891d0(sel);
        }
        s32 px, py;
        func_00258080(&px, &py);
        if (func_0028acc8(sel) && func_00287cd0() == 1) {
            if (!func_0028d008(n)) {
                func_0028cc78(n, D_0035ef68, D_0035ef64, D_0035f03c, px, py);
                func_0028cf28(n, func_002891d0(sel));
                if (!func_0028d6e8(D_0035f050))
                    func_0028d1c0(D_0035f050, 30026, D_0035ef68, D_0035ef64, D_0035f03c, D_003729b0, 0);
                if (n != 0) {
                    for (s32 i = 0; i < n; i++) {
                        if (func_0028d008(i)) {
                            func_0028ce98(i, 1);
                        } else {
                            u32 s;
                            if (i == 0) s = D_0035f01c;
                            else s = (sel == D_0035f024) ? D_0035f020 : D_0035f024;
                            func_0028cc78(i, D_0035ef68, D_0035ef64, D_0035f03c, px, py);
                            func_0028cf28(i, func_002891d0(s));
                            func_0028ce98(i, 1);
                        }
                    }
                }
                func_0028d660(D_0035f050, target);
            }
        } else if (func_00287cd0() == 2 && D_0035f055 == 0) {
            if (func_0028d008(n)) {
                if (n == 0) {
                    if (func_0028cf10(0) != 1) func_0028ce98(0, 1);
                }
            } else {
                func_0028cc78(n, D_0035ef68, D_0035ef64, D_0035f03c, px, py);
                func_0028cf28(n, func_002891d0(sel));
                func_0028ce98(n, 1);
                if (!func_0028d6e8(D_0035f050))
                    func_0028d1c0(D_0035f050, 30026, D_0035ef68, D_0035ef64, D_0035f03c, D_003729b0, 0);
            }
        } else if (func_00287cd0() == 2 && D_0035f055 != 0) {
            if (func_0028d008(n)) {
                func_0028cdb8(n);
                if (n != 0) {
                    func_0028ce98(n - 1, 0);
                    if (mode == 36) target = func_002891d0(D_0035f01c)->sub;
                    else target = func_002891d0(D_0035f01c);
                    func_0028d660(D_0035f050, target);
                } else {
                    func_0028d5d0(D_0035f050);
                }
            } else if (func_0028d6e8(D_0035f050)) {
                if (n != 0) {
                    if (mode == 36) target = func_002891d0(D_0035f01c)->sub;
                    else if (mode == 13) target = func_002891d0(D_0035f020);
                    else target = func_002891d0(D_0035f01c);
                    func_0028d660(D_0035f050, target);
                } else {
                    func_0028d5d0(D_0035f050);
                }
            }
            if (n != 0) {
                if (func_0028acb8(D_0035f01c) && func_0028d008(0)) {
                    func_0028cdb8(0);
                    func_0028d5d0(D_0035f050);
                }
            }
        }
        if (n != 0 && func_0028acc8(sel) && func_00287cd0() == 0 && func_0028d6e8(D_0035f050)
            && D_0035f050->target != target) {
            func_0028d660(D_0035f050, target);
        }
    } else {
        if (func_0028d008(n)) func_0028ce38();
        if (func_0028d6e8(D_0035f050)) D_0035f050->vt->update((VObj*)D_0035f050);
    }

    if (mode < 0) return;
    if (mode < 37) {
        func_002566f0(sel, mode, n);
        if (mode == 2 || mode == 5 || mode == 6 || mode == 7 || mode == 8 || mode == 9) {
            func_0026a3b8(0, func_00289310(sel));
        } else if (mode == 20 || mode == 22) {
            func_0026d620(n, func_00289310(sel));
        } else if (mode == 26 || mode == 27 || mode == 29 || mode == 30 || mode == 31 || mode == 32 || mode == 33) {
            func_00273368(0, func_00289310(sel));
        } else if (mode >= 16 && mode <= 19) {
            func_0027bd40(0, func_00289310(sel));
        } else if (mode >= 11 && mode <= 13) {
            func_002633a8(n, func_00289310(sel));
        }
    }
}
}
