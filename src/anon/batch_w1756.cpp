#include "../common/types.h"
extern "C" {

u32 func_00224c20();
extern u32 D_0035db18;
void func_00224cf0()
{
    switch (func_00224c20()) {
    case 0:
        break;
    case 1:
    case 2:
        D_0035db18 = 0x700000;
        break;
    case 3:
    case 4:
    case 5:
        D_0035db18 = 0x600000;
        break;
    }
}

struct WTarget_w1756 { u32 type; u32 id; u32 a; u32 b; u32 c; u32 pad[3]; };
extern s32 D_0035e360;
extern s32 D_0035e368;
extern WTarget_w1756 D_01dadc00[];
u32 wtarget_002341e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_002341e8jjjj");
u32 wtarget_002341e8(u32 a0, u32 a1, u32 a2, u32 a3)
{
    s32 i = D_0035e360;
    u32 id = D_0035e368;
    WTarget_w1756* e = &D_01dadc00[i];
    e->type = 4;
    e->id = id;
    e->a = a0;
    e->b = a1;
    e->c = a2;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}

struct E6_w1756 { s16 id; s16 a; s16 b; };
extern E6_w1756 D_00372b50[];
s32 func_00259460(s32 id, u8 f)
{
    s32 r = 11;
    s32 i;
    for (i = 0; D_00372b50[i].id >= 0; i++) {
        if (D_00372b50[i].id == id) {
            if (f) r = D_00372b50[i].b; else r = D_00372b50[i].a;
            break;
        }
    }
    return r;
}

void* ctarget_001b9bc8(void*) asm("_Z16ctarget_001b9bc8jjjj");
void* func_002be908(void* p)
{
    while ((p = ctarget_001b9bc8(p)) != 0) {
        if (*(u32*)((u8*)p + 0x588) & 0x40000000) return p;
    }
    return 0;
}

}
