#include "../common/types.h"
extern "C" {
extern void func_0022f5a0(void*, s32, s32);
extern char* D_0035dcfc;
struct EE_22d4e8 { s32 a; s32 b; char pad[14]; u8 f; char z[17]; };

void func_0022d4e8(char* a) {
    if (D_0035dcfc) {
        for (s32 i = 0; i < 96; i++) {
            EE_22d4e8* e = (EE_22d4e8*)((u32)(i * 40) + (u32)D_0035dcfc);
            s32 x = e->a;
            if (x == -1) continue;
            s32 y = e->b;
            if (a[y + 6] != 0 && e->f == 1)
                func_0022f5a0((char*)e + 23, x, y);
        }
    }
}
}
