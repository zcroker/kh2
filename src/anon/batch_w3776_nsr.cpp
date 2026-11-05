#include "../common/types.h"
extern "C" {
struct Ent4 { u8 a; s8 b; u8 c, d; };
struct Tbl { s32 count; Ent4 e[1]; };
u8* func_002a9d68(void);
void func_00287bc0(void);
s32 func_0028b038(u32);
u32 func_002a92a0(s32);
s32 func_002a99c8(u32);
void func_002aae30(s32);
extern u32 D_0035f200;
extern Tbl* D_0035f608;
}

/* Walks up to 10 table entries from a base index; for each valid id that is not
   in state 3 and whose bit is clear in the owner bitset, calls func_002aae30. */
extern "C" {
void func_002a98a8(void) {
    u8* p = func_002a9d68();
    func_00287bc0();
    s32 base = func_0028b038(D_0035f200);
    s32 n = D_0035f608->count;
    if (n > 10) n = 10;
    s32 i;
    for (i = 0; i < n;) {
        s32 k = base + i;
        i++;
        s32 c = D_0035f608->e[k].b;
        if (c < 0) continue;
        if (func_002a99c8(func_002a92a0(c)) == 3) continue;
        s32 d = D_0035f608->e[k].b;
        u32* bits = (u32*)(p + 148);
        if (bits[(u32)d >> 5] & (1 << (d & 31))) continue;
        func_002aae30(d);
    }
}
}
