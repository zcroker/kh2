#include "../common/types.h"
struct PauseParam1577 { bool b0; bool b1; bool b2; u8 b3; };
extern "C" {
extern s32 D_0035f254;
extern s8 D_0035f268;
extern u8 D_00374168[];
s32 func_00289380(s32);
s32 func_00289310(s32);
void func_002806f0(void);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
PauseParam1577* func_001040f8(void);
void func_00287da0(void);
s32 func_0028b040(s32);
void func_0027fd38(void);
bool func_00242a00(void);
void func_00242a28(u8);
void func_0027f9b0(void);
void func_00287bd0(s32, s32);

void func_0027f7f0(void) {
    s32 r = func_00289380(D_0035f254);
    if (func_00242848(func_00287df0(r, func_00289310(D_0035f254), 1, func_002806f0, 1))) return;
    switch (r) {
    case -4:
    case -2:
        func_001040f8()->b3 = 0;
        func_00287da0();
        return;
    case -13:
    case -12:
        switch (func_0028b040(D_0035f254)) {
        case 3: { PauseParam1577* p = func_001040f8(); p->b0 = !p->b0; break; }
        case 6: { PauseParam1577* p = func_001040f8(); p->b2 = !p->b2; break; }
        case 5: { PauseParam1577* p = func_001040f8(); p->b1 = !p->b1; break; }
        case 4: func_00242a28(!func_00242a00()); break;
        }
        func_0027fd38();
        return;
    case -1:
        break;
    default:
        if (r == 2) {
            func_0027f9b0();
            func_00287bd0(1, 0);
            return;
        }
        func_001040f8()->b3 = D_00374168[r];
        D_0035f268 = r;
        func_00287da0();
        break;
    }
}
}
