#include "../common/types.h"
// batch w1772: built with -g (see Makefile *_g rule).
extern "C" {
u8* GetSeqTbl_w1772(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s8* GetMenuInfo_w1772(void) asm("_ZN2Tz6Jiminy11GetMenuInfoEv");
void func_00294288(s32, s32*, s32*);
s32 tail4_w1772(s32) asm("_Z16u_tail4_00192048jjjj");

void func_002960d0(void) {
    u8* s = GetSeqTbl_w1772();
    s8* q = GetMenuInfo_w1772();
    u8* a = s + 1632;
    u8* b = s + 2068;
    u8* c = s + 2504;
    u8* d = s + 2940;
    s32 x, y;
    func_00294288(*q, &x, &y);
    *(s32*)(a + 408) = tail4_w1772(x);
    *(s32*)(b + 408) = tail4_w1772(12883);
    *(s32*)(c + 408) = tail4_w1772(y);
    *(s32*)(d + 408) = tail4_w1772(12884);
}
}
