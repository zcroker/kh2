#include "../common/types.h"
struct S8 { s8 a, b, c; };
extern "C" {
S8* func_001040f8(void);
s32 func_001041c0(void);
void func_00138c10(s32, s32);
s32 func_00242a00(void);
extern s32 D_0035f25c; extern s32 D_003740f0; extern s32 D_003740f4; extern s8 D_00374168[];

void func_0027fd38(void) {
    s32 i, n = 0; s32 k2 = 2, k3 = 3, k4 = 4;
    for (i = 0; i < 9; i++) {
        s32 f;
        if (D_00374168[i] >= 0) continue;
        if (i == k2) continue;
        f = 0;
        if (i == k4) goto c4;
        if (i >= 5) goto ge5;
        if (i == k3) goto c3;
        goto join;
    join:
        if (func_001041c0() != 3 && i == 6) {
            func_00138c10(D_0035f25c + n*0x368, 0x1b);
            func_00138c10(D_0035f25c + n*0x368 + 0x1b4, 0x1b);
        } else {
            func_00138c10(D_0035f25c + n*0x368, f == 0 ? D_003740f0 : D_003740f4);
            func_00138c10(D_0035f25c + n*0x368 + 0x1b4, f ? D_003740f0 : D_003740f4);
        }
        n++;
        continue;
    c3: f = func_001040f8()->a; goto join;
    ge5:
        if (i == 5) goto c5;
        if (i != 6) goto join;
        f = func_001040f8()->c; goto join;
    c5: f = func_001040f8()->b; goto join;
    c4: f = func_00242a00() == 0; goto join;
    }
}
}
