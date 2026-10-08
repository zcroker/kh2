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
void wt_001572e8(u8* p, u32 a, u32 b, u32) {
    u32 h = func_00158290(p);
    u32 x = func_0013a7e8(1);
    u32 y = func_0013d7e0();
    s32 i = func_00139c18(p + 1732);
    u8* m = p + i * 408 + 1732;
    func_001386e0(m, 7000, x, y, a, h);
    *(u32*)(m + 392) = b;
    *(u8**)(m + 396) = p + 6704;
    settle(m);
    s32 s0, s4;
    s4 = 0;
    s0 = 0;
    if (func_0016c060(func_0017df58(0), &s0, &s4)) {
        s32 j = func_00139c18(p + 5008);
        u8* n = p + j * 848 + 5008;
        func_00154048(n, 13000, s4, s0, 3, h);
        *(u8**)(n + 396) = p + i * 408 + 1732;
        settle(n);
        u8* q = p + j * 848 + 5008;
        func_00139660(q);
        func_00139688(q);
    }
}
