#include "../common/types.h"
// Built with -fmove-all-movables: the per-group start offsets (base*80, base*6) and the
// D_00374240[k] pointer copy are hoisted as movables, which gives the original's spills.
extern "C" {
struct Ent282b00 { u16 id; u8 a; u8 b; u16 c; };
struct Row282b00 { char name[8]; u8 flag; u8 pad[7]; char buf[64]; };
struct Obj282b00 { s32 n; Ent282b00 e[256]; Row282b00 rows[32]; u8 pad[12]; s32 cnt[5]; };
extern s16 D_00374240[];
void func_00259570(s32, char*, s32, s32);
s32 func_002595e0(void);
void func_002595e8(char*, u32);
u32 func_00192048(u32);
u32 func_00259618(u16, char*, s32);
void func_00192b30(u32);

void func_00282b00(Obj282b00* obj)
{
    s32 base = 0;
    for (s32 k = 0; k < 5; k++) {
        if (k == 1) continue;
        s32 n = obj->cnt[k];
        if (k == 0) n += obj->cnt[1];
        for (s32 j = 0; j < n; j++) {
            s32 i = base + j;
            if (obj->e[i].id == 0) {
                func_00259570(D_00374240[k], obj->rows[i].buf, 0, 1);
                char* p = obj->rows[i].buf + func_002595e0();
                func_002595e8(p, func_00192048(0x8448));
            } else {
                func_00192b30(func_00259618(obj->e[i].id, obj->rows[i].buf, obj->e[i].b != 0));
            }
        }
        base += n;
    }
}
}
