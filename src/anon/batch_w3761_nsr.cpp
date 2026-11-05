#include "../common/types.h"
extern "C" {
struct Ent { s16 a; s16 b; };
struct Tbl { s32 n; Ent e[1]; };
struct Item { u8 pad[6]; u16 k; };
extern Tbl* D_0035f600;
extern s32 D_0035f200;
u8* func_002a9d68();
s32 func_00287bc0();
s32 func_0028b038(s32);
Item* func_002a7f20(s32);
u8* func_001d56c8(u32);
void func_002ab258(s32);

// Built with -fno-strength-reduce (_nsr).
void func_002a8768(void) {
    s32 i = 0;
    u8* w = func_002a9d68();
    func_00287bc0();
    s32 base = func_0028b038(D_0035f200);
    s32 n = D_0035f600->n;
    if (n > 10) n = 10;
    if (n > 0) {
        do {
            s32 id = D_0035f600->e[base + i].b;
            i++;
            if (id >= 0 && *func_001d56c8(func_002a7f20(id)->k) != 0) {
                u32* bits = (u32*)(w + 136);
                if (!(bits[(u32)id >> 5] & (1 << (id & 31)))) {
                    func_002ab258(id);
                }
            }
        } while (i < n);
    }
}
}
