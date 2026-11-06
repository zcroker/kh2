/* Built with -fno-schedule-insns (_nosched). */
#include "../common/types.h"

extern u16 D_00373d70[3];
extern u8* D_0035f1fc;

/* Picks the previous/next entries of a 3-slot ring (index from mode a) out of the u16 table D_00373d70. */
void func_00276088(s32 a, s32* l, s32* r) {
    s32 next, prev, c;
    u16* T;
    s32 i = 0;
    if (a < 3) {
        if (a > 0) goto one;
    } else if (a == 13) goto two_;
    goto done;
one:
    i = 1;
    goto done;
two_:
    i = 2;
done:;
    if (i == 0) prev = 2; else prev = i - 1;
    T = D_00373d70;
    c = i < 2;
    {
        s32 t = i + 1;
        s32 po = prev * 2;
        /* no code: keeps t and c live at the shift so prev*2 gets t6 (local-alloc order) */
        asm("" : "+r"(po) : "r"(t), "r"(c));
        next = c ? t : 0;
        {
            u16* A = (u16*)((u8*)T + po);
            u16* C = &T[next];
            *l = *A;
            *r = *C;
        }
    }
    if (*D_0035f1fc >= 15) {
        s32 k;
        if (i != 2) k = 2; else k = 0;
        if (prev == 1) *l = T[k];
        if (next == 1) *r = T[k];
    }
}
