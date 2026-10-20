#include "../common/types.h"
extern "C" {
typedef struct JmE { u16 a0, a2, a4, a6, a8, aa, ac, ae; } JmE;
u8* func_00294000(s32);
s32 func_002941d8(JmE*);
s32 func_00295158(s32);
u16 func_00295270(s32 a, u8 b) {
    JmE* base = (JmE*)(func_00294000(0) + 16);
    a = func_00295158(a);
    a = (s32)(base + a);
    if (b) {
        if (func_002941d8((JmE*)a)) return ((JmE*)a)->ac;
        return ((JmE*)a)->a6;
    }
    if (func_002941d8((JmE*)a)) return ((JmE*)a)->aa;
    return ((JmE*)a)->a4;
}
}
