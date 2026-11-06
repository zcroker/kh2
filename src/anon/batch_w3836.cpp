#include "../common/types.h"

extern "C" {

// --------------------
// 0026b200: true if the current entry's id is found in the second id list but not the first.
u32 func_0028b040(u32);
u32 func_00257130(void);
u8* func_00281f20(u32);
u32 func_00257070(u32);
u8* func_00281180(u32, u32);
extern u32 D_0035f01c;
extern u32 D_0035f010;
struct E26b200 { u16 id; u8 pad; u8 on; u16 x; };
struct S26b200 { u8 pad[18]; u8 n; u8 pad2[33]; u16 a[8]; u16 b[8]; };
s32 func_0026b200(void) {
    s32 idx = func_0028b040(D_0035f01c);
    u32 b = (u32)func_00281f20(func_00257130());
    E26b200* e = (E26b200*)(idx * sizeof(E26b200) + b);
    s32 r;
    register u32 id asm("$17") = e->id;
    if (!e->on) {
        r = 0;
    } else {
        S26b200* t = *(S26b200**)(func_00281180(D_0035f010, func_00257070(1)) + 580);
        u8 n = t->n;
        s32 i;
        for (i = 0; i < n; i++) {
            if ((t->a[i] == id || t->b[i] == id) && t->a[i] != id) {
                r = 1;
                goto out;
            }
        }
        r = 0;
    }
out:
    // no code: keeps idx live so the product gets its own register
    asm("" :: "r"(idx));
    return r;
}

}
