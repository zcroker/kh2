#include "../common/types.h"
extern "C" {
void func_002fee78(char*, char*, s32, s32, s32, s32, s32, s32, s32, s32);
extern char D_0036eeb0[];
extern char D_01d9e4b0[];
/* Empty asm ties keep the two lo_sum addresses of the buffer apart and place the second one before the load. */
char* func_001e6100(u8* p) {
    char* a = D_01d9e4b0; asm("" : "+r"(a));
    char* r = D_01d9e4b0;
    u8* q = *(u8**)(p + 0x8c);
    asm("" : "+r"(r) : "r"(p));
    func_002fee78(a, D_0036eeb0,
        *(s32*)(p + 0x114) + *(s32*)(p + 0x104),
        *(s32*)(p + 0x118) + *(s32*)(p + 0x108),
        *(s32*)(p + 0xc4), *(s32*)(p + 0xd4), *(s32*)(p + 0xe4), *(s32*)(p + 0xf4),
        *(s32*)(p + 0x144), *(s32*)(q + 0xf0) / 1024);
    return r;
}
}
