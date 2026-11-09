#include "../common/types.h"
extern "C" {
struct Sub30 { u8 pad[184]; u32 flags; void SetF() { flags |= 8; } };
struct Obj30 { u8 pad[24]; Sub30 sub; u8 pad2[405 - 24 - 188]; u8 on; u8 pad3[26]; void SetOn() { on = 1; } };
struct Pair { u16 key; u16 val; };
extern Obj30* D_0035ee78;
extern u32 D_0035ee60;
extern u8 D_00372608[];
extern u8 D_00372610[][8];
extern Pair D_003725e8[];
// The two tables are read-only: their loads then never depend on the outgoing-argument store.
extern const s16 D_00372640[];
extern const s16 D_00372648[];
s32 func_001a6d08(u32);
s32 func_00181500(u32);
void func_0028b300(Obj30*, s32, s32, s32, u32, u8*, u8*, s32, s32);

// Picks the value of the first table entry whose key func_00181500 accepts, then calls func_0028b300 with it.
s32 func_00252428(void)
{
    s32 r = 0;
    for (s32 i = 0; D_003725e8[i].key != 0; i++) {
        if (func_00181500(D_003725e8[i].key)) { r = D_003725e8[i].val; break; }
    }
    s16 n;
    if (func_001a6d08(120)) n = D_00372640[r]; else n = D_00372648[r];
    func_0028b300(D_0035ee78, 30004, 1, 1, D_0035ee60, D_00372608, D_00372610[r], n, 0);
    D_0035ee78->SetOn();
    Sub30* sb = &D_0035ee78->sub;
    sb->SetF();
    return r;
}
}
