#include "../common/types.h"
extern "C" {
struct W1963Res { u32 f0; u32 f4; u32 data; };
struct W1963Ent { u8 pad[0x13]; u8 b13; u8 pad2[8]; u32 d1c; };
extern W1963Ent D_01c6cc60[6];
extern u32 D_01c6cec0;
extern u32 D_01c6cec4;
extern s32 D_00350a30;
extern char* D_00350a28;
extern s32 D_0033caf4;
extern s8 D_0036d740[8], D_0036d748[8], D_0036d750[8];
void func_001aabd8(void);
void func_002fee78(char*, const char*, ...);
void* func_001b1490(void*);
W1963Res* func_00168b38(void*, s32, s32);
W1963Res* func_00168b88(void*, s32, s32, s32);
s32 func_00105c30(void);
static inline u32 TAG(const s8* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }

void func_001aaa08(void)
{
    char buf[48];
    W1963Ent* e = D_01c6cc60;
    func_001aabd8();
    s32 f = 0;
    func_002fee78(buf, D_00350a28, D_0033caf4);
    void* h = func_001b1490(buf);
    u32 v = func_00168b88(h, 2, TAG(D_0036d740), 0)->data;
    e[5].d1c = v;
    e[2].d1c = v;
    e[1].d1c = v;
    e[0].d1c = v;
    v = func_00168b88(h, 2, TAG(D_0036d748), 0)->data;
    e[4].d1c = v;
    e[3].d1c = v;
    D_01c6cec4 = func_00168b88(h, 2, TAG(D_0036d750), 0)->data;
    D_01c6cec0 = func_00168b38(h, 25, 0)->data;
    if (func_00105c30() == 1 || func_00105c30() == 8) f = 1;
    if ((u8)f == 0) {
        D_01c6cc60[5].b13 = 24;
        D_01c6cc60[2].b13 = 24;
        D_01c6cc60[1].b13 = 24;
        D_01c6cc60[0].b13 = 24;
        D_01c6cc60[4].b13 = 32;
        D_01c6cc60[3].b13 = 32;
        D_00350a30 = 32;
    }
}
}
