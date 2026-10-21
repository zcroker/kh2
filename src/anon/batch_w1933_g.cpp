#include "../common/types.h"
extern "C" {
u32* func_002a9d68(void);
u8* func_002766d0(void);
u8* func_00294000(s32);
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_00276638(s32);
s32 func_002943b0(u8*);
void func_002aa048(s32);
s32 func_002891e8(s32);
s32 func_00139d78(u8*);
void func_00138c10(u8*, s32);
struct S5ac { u8 pad[5]; s8 b5; u8 pad2[2]; s16 ids[1]; };
extern S5ac* D_0035f5ac;
extern s32 D_0035f200;
void func_0029eaa8(void) {
    u32* bits = func_002a9d68();
    u8* base = func_002766d0();
    if (D_0035f5ac->b5 == 0) return;
    u8* tbl = func_00294000(3) + 16;
    s32 k = func_00287bc0();
    s32 idx;
    switch (k) {
    case 15: case 18: case 21:
        idx = func_0028b040(D_0035f200);
        break;
    case 16: case 19: case 22:
        idx = func_00276638(15);
        break;
    default:
        return;
    }
    s16 id = D_0035f5ac->ids[idx];
    if (func_002943b0(tbl + id * 36) == 0) return;
    u32 uid = id;
    if (bits[uid >> 5] & (1 << (uid & 31))) return;
    func_002aa048(id);
    switch (k) {
    case 15: case 18: case 21: {
        idx = func_002891e8(D_0035f200);
        u8* o = base + idx * 0x198 + 0xa998;
        if (func_00139d78(o) != 0) func_00138c10(o, 93);
        break;
    }
    }
}
}
