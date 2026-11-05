#include "../common/types.h"
extern "C" {
struct E8 { s16 id; s8 f; u8 pad[5]; };
struct T8 { u8 hdr[8]; E8 e[1]; };
struct X244 { u8 pad[18]; u8 cnt; u8 pad2[33]; u16 a[8]; u16 b[8]; };
struct Y { u8 pad[580]; X244* x; };
extern T8* D_0035f12c;
extern s32 D_0035f01c;
extern s32 D_0035f010;
s32 func_00287bc0();
s32 func_0028b040(s32);
s32 func_002570a0(s32);
s32 func_00257070(s32);
Y* func_00281180(s32, s32);

// Returns 1 when the selected entry's id is in some slot's b list but not in its a list.
// Register pins: ok in t7, table base in t4, the GetData&1 result kept in v0 (tie stops combine
// folding it into ok); without them gcc picks v0 for ok and fills the first branch slot.
s32 func_00273b30(void)
{
    s32 mode = func_00287bc0();
    s32 k;
    switch (mode) {
    case 26: case 27: k = func_0028b040(D_0035f01c); break;
    default: k = func_002570a0(26); break;
    }
    if (func_002570a0(25)) k--;
    register T8* bp asm("$12") = D_0035f12c;
    s16 id = bp->e[k].id;
    register s32 ok asm("$15") = bp->e[k].f != 0;
    switch (mode) {
    case 26: case 27: break;
    default: {
        register s32 v asm("$2") = func_0028b040(D_0035f01c) & 1;
        asm("" : "+r"(v));
        ok = v == 0;
        break;
    }
    }
    if (ok) {
        X244* x = func_00281180(D_0035f010, func_00257070(25))->x;
        s32 n = x->cnt;
        for (s32 i = 0; i < n; i++) {
            if (x->a[i] == id) continue;
            if (x->b[i] != id) continue;
            if (x->a[i] != id) return 1;
        }
    }
    return 0;
}
}
