#include "../common/types.h"
extern "C" {
u32 func_00287bc0(void);
s16* func_00276fa8(void);
s32 func_00287db0(void);
s32 func_00139d78(void*);
s32 func_0023f0c0(void*);
void func_0023f070(void*, s32, s32);
s32 func_0028acc8(void*);
s32 func_0028acb8(void*);
u8* func_002891b8(void*, s32);
void func_0028aa40(void*);
void func_0028f7a0(void);
void func_0028d5d0(u32);
void func_002748a0(void);
void func_00276e28(void);
void func_0028ce38(void);
void func_00288018(void);
void func_00276438(void);
s32 func_00287cd0(void);
s32 func_0028d008(s32);
s32 func_002891d0(void*);
void func_00275980(s32, s32);
void func_002759e8(s32);
void func_0028d620(u32);
void func_0028cdb8(s32);
s32 func_0028d6e8(u32);
void func_002756f8(void*, u32, s32);
struct VObj { void (**vt)(VObj*); };
extern void* D_0035f200;
extern VObj* D_0035f208;
extern void* D_0035f210;
extern u32 D_0035f218;
extern u8 D_0035f220;
extern u8 D_0035f221;
static inline bool busy_00275438(u8* v) { return *(s32*)(v + 400) || *(s32*)(v + 396); }
static inline void tailL() { if (func_0028d6e8(D_0035f218)) func_0028d5d0(D_0035f218); }
void func_00275438(void) {
    u32 mode = func_00287bc0();
    s16* q = func_00276fa8();
    void* p;
    if (func_00287db0()) {
        if (func_00139d78(D_0035f210)) {
            if (func_0023f0c0(D_0035f210) != q[1]) func_0023f070(D_0035f210, q[1], -1);
        }
        if (func_0028acc8(D_0035f200) && !func_0028acb8(D_0035f200)) {
            u8* v = func_002891b8(D_0035f200, 0);
            if (!busy_00275438(v)) func_0028aa40(D_0035f200);
        }
        if (func_00139d78(D_0035f208)) D_0035f208->vt[5](D_0035f208);
        func_0028f7a0();
        func_0028d5d0(D_0035f218);
        func_002748a0();
        func_00276e28();
        func_0028ce38();
    }
    func_00288018();
    func_00276438();
    if (func_00287db0()) return;
    p = D_0035f200;
    if (mode != 7 && mode != 9 && mode != 26 && mode != 34) {
        if (!D_0035f220) {
            if (func_0028acc8(p) && func_00287cd0() == 1) {
                if (!func_0028d008(0)) {
                    func_00275980(0, func_002891d0(p));
                    if (!D_0035f221) func_002759e8(func_002891d0(p));
                    else func_0028d620(D_0035f218);
                }
            } else if (func_00287cd0() == 2) {
                if (func_0028d008(0)) { func_0028cdb8(0); tailL(); } else tailL();
            }
        } else {
            if (func_0028d008(0)) func_0028cdb8(0);
            tailL();
        }
    }
    switch (mode) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6:
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
    case 20: case 21: case 22: case 23: case 24: case 25: case 27: case 28: case 29:
    case 35: case 36: case 37: case 38: case 40:
        func_002756f8(p, mode, 0);
        break;
    }
}
}
