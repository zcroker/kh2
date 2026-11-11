#include "../common/types.h"
extern "C" {
void func_001396b0(u8*);
void func_0031a260(u8*, s32);
void func_00139660(u8*);
void func_00139688(u8*);
u32 func_00158290(u8*);
u32 func_0013a7e8(s32);
u32 func_0013d7e0(void);
s32 func_00139c18(u8*);
void func_001386e0(u8*, s32, u32, u32, u32, u32);
void func_00154048(u8*, s32, s32, s32, s32, u32);
u32 func_0017df58(s32);
s32 func_0016c060(u32, s32*, s32*);
}
static inline void settle(u8* m) {
    func_001396b0(m);
    if (*(u32*)(m + 396)) {
        *(u32*)(m + 400) = 0;
        func_001396b0(m);
        if (*(u32*)(m + 400)) func_0031a260(m, 0);
    }
}
extern "C" {
void wt_001572e8(u8* p, u32 a, u32 b, u32) asm("_Z16wtarget_001572e8jjjj");
}
// 001572e8: moved to src/anon/unit_00153ea0.cpp
