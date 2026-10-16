#include "../common/types.h"
extern "C" {
extern u8* D_004f3b38;
void func_00160d18(u8*);
static inline u8* w1562_next(u8* p) { if (!p) return D_004f3b38; return *(u8**)(p + 0x80); }
void func_00160d70(s32 k) {
    u8* p = 0;
    while ((p = w1562_next(p)) != 0) {
        if (*(s32*)(p + 0x1a8) == k) func_00160d18(p);
    }
}
}
