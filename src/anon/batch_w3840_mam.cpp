// func_0029fcb0: -fmove-all-movables (hoists the 0x10000/0x110a0 constants to the stack like the original).
// One counter i is reused for both loops; the empty asm reading cnt at the loop bottom raises cnt's
// register-allocation priority (s3) like the original.
#include "../common/types.h"
namespace w1606c {
struct E { u8 b[64]; };
struct W { u8 pad[0x110a0]; E e[10]; };
struct L { s8 n; u8 pad[5]; s8 id[1]; };
}
using namespace w1606c;
extern "C" {
W* func_002766d0(void);
s32 func_0028b038(s32);
void func_0028be78(s32, s32);
void func_002fde18(void*, s32, s32);
s32 func_002892f8(s32);
void func_00138c10(u8*, s32);
u8* func_002a01c8(s32);
s32 func_002943e8(u8*);
s32 func_00192048(s32);
void func_00192c90(s32, E*);
void func_0028de08(s32, E*, s32);
u8* func_002891b8(s32, s32);
s32 func_002aa2f8(s32);
s32 func_002aa378(s32);
extern s32 D_0035f200;
extern s32 D_0035f214;
extern L* D_0035f5d0;
extern s32 D_00374b1c;
extern s32 D_00374b20;

// Rebuilds the menu entry list from D_0035f5d0 (up to 10 entries) and their highlight colours.
void func_0029fcb0(void) {
    W* w = func_002766d0();
    s32 m = func_0028b038(D_0035f200);
    func_0028be78(D_0035f214, m);
    func_002fde18(w->e, 0, 640);
    s32 c = func_002892f8(D_0035f200);
    s32 i;
    for (i = 0; i < c; i++) {
        func_00138c10((u8*)w + 0xa998 + i * 0x198, 2);
    }
    s32 n = 0;
    s32 cnt = D_0035f5d0->n;
    s32 k = 0;
    i = 0;
    for (; i < cnt && n < 10; i++) {
        if (i < m) continue;
        u16 id = *(u16*)(func_002a01c8(D_0035f5d0->id[i]) + 2);
        s32 f = func_002943e8(func_002a01c8(D_0035f5d0->id[i]));
        if (f) {
            func_00192c90(func_00192048(id), &w->e[n]);
        } else {
            func_0028de08(id, &w->e[n], 64);
        }
        *(E**)(func_002891b8(D_0035f200, n) + 0x198) = &w->e[n]; n++;
        if (f && func_002aa2f8(D_0035f5d0->id[i])) {
            func_00138c10((u8*)w + 0xa998 + k * 0x198, func_002aa378(D_0035f5d0->id[i]) ? D_00374b20 : D_00374b1c);
        }
        k++;
        asm("" :: "r"(cnt));
    }
}


}
