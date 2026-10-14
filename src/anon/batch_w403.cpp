#include "../common/types.h"

extern "C" {
extern u8 D_0032bae0;

/* Index lookup with a hole-y switch; negative input means "use the current value"
   (byte at 0x32bae0). default sits mid-switch in the original (body order proves it). */
s32 func_002764b0(s32 a) {
    if (a < 0) a = D_0032bae0;
    switch (a) {
    case 2: return 0;
    case 4: return 1;
    case 5: return 2;
    case 1: case 6: return 3;
    case 7: return 4;
    case 8: return 5;
    case 9: return 6;
    case 10: return 7;
    case 11: return 8;
    case 12: return 9;
    case 13: return 10;
    case 14: return 11;
    default: return -1;
    case 16: return 12;
    case 17: return 13;
    case 18: return 14;
    }
}
}
