#include "../common/types.h"
// 00252320: matched (draft by w2446/zl90), plain -O2.
extern "C" {
// 00252320: const on D_00372638 makes the lh an unchanging read, so it gets no
// anti-dependence on the outgoing stack-argument store (sw zero,0(sp)).
struct W2446Sub { u8 pad[184]; u32 flags; void SetF() { flags |= 8; } };
struct W2446Obj { u8 pad[24]; W2446Sub sub; u8 pad2[405 - 24 - 188]; u8 on; u8 pad3[26]; void SetOn() { on = 1; } };
extern W2446Obj* D_0035ee74;
extern u32 D_0035ee60;
extern u8 D_00372608[];
extern u8 D_00372610[][8];
extern u16 D_003725d8[];
extern const s16 D_00372638[];
s32 func_001a6d08(u32);
void func_0028b300(W2446Obj*, s32, s32, s32, u32, u8*, u8*, s32, s32);
void func_00252320(void)
{
    for (s32 i = 0; i < 4; i++) {
        if (!func_001a6d08(D_003725d8[i])) continue;
        u32 t = D_0035ee60;
        s32 v = D_00372638[i];
        func_0028b300(&D_0035ee74[i], 30011, 2, 2, t, D_00372608, D_00372610[i], v, 0);
        D_0035ee74[i].SetOn();
        W2446Sub* sb = &D_0035ee74[i].sub;
        sb->SetF();
    }
}
}
