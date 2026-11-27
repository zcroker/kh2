#include "../common/types.h"
// 00252320: matched (draft by w2446/helper), plain -O2.
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
void Tz__LaySeq__create(W2446Obj*, s32, s32, s32, u32, u8*, u8*, s32, s32);
void func_00252320(void);  // 0x00252320: definition moved into src/anon/unit_00250fb8.cpp
}
