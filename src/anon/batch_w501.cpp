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

void func_00255df0(void);  // 0x00255df0: definition moved into src/anon/unit_00254020.cpp
}
