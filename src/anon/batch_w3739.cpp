#include "../common/types.h"
extern "C" {
struct Ent { s32 idx; s32 one; s32 v; u8* p; };
extern Ent D_0035eee0[7];
extern s32 D_0035ef50;
extern s32 D_0035ef54;
extern u8 D_0035ef58;
extern u8 D_01dae6c0[];
extern s32 D_0035eec0[];
void func_002fde18(void*, s32, s32);
s32 func_002ff3fc(s32);
char* func_00253b30(char*, s32);
s32 func_00168328(char*, u8*);
s32 func_00253948(s32);
s32 func_001688b8(void);

// Loads up to two entries (handles from D_0035eec0) into the D_01dae6c0 buffer and records them.
// The empty asm (no code) keeps total's add after dst's (sched2 order).
void func_00253638(void) {
    char buf[128];
    s32 total = 0;
    func_002fde18(D_0035eee0, 0, 0x70);
    D_0035ef50 = 0;
    D_0035ef54 = 0;
    u8* dst = D_01dae6c0;
    s32 i;
    for (i = 0; i < 2; i++) {
        s32 h = D_0035eec0[i];
        if (h != 0 && func_002ff3fc(h) != 0) {
            Ent* e = &D_0035eee0[i];
            s32 v = func_00168328(func_00253b30(buf, h), dst);
            e->p = dst;
            e->idx = i;
            e->one = 1;
            e->v = v;
            s32 n = func_00253948(v);
            dst += n; asm("" : "+r"(n) : "r"(dst)); total += n;
        }
    }
    D_0035ef50 = total;
    D_0035ef54 = 2;
    if (D_0035ef58 != 0 && func_001688b8() == 0) {
        D_0035ef58 = 0;
    }
}
}
