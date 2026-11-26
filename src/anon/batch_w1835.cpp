#include "../common/types.h"

struct W1835V3 { f32 x, y, z; };
struct W1835Src { s32 id; s32 off; W1835V3 v; u8 k; };
struct W1835Idx { u8 pad[0xc]; s32* offp; };
struct W1835Obj { u8 pad[0xc]; s32 id; };
struct W1835Ctl { u8 pad[0xa8]; u64 flags; };

struct W1835Ent { u16 a; u16 type; s16 key; };
struct W1835Ctx { u8 pad[0x12]; u8 n; u8 pad2[0x34 - 0x13]; u16 ids[1]; };
struct W1835Res { u8 pad[6]; s8 idx; };
struct W1835Mode { u8 pad[0xb50]; s32 mode; };
struct W1835Self { u8 pad[0x268]; u8 sub[0x9e0 - 0x268]; W1835Mode* o; };
struct W1835Tbl { u8 pad[0x36f8]; u16 ids[4]; };

extern "C" {
extern s32 D_01d9ea9c;
extern W1835Ctl* D_01d9e6e0;
extern W1835V3 D_01d9e360;
extern W1835Tbl D_0032bb30;
extern u16 D_0036dc88[4];
void func_001bc778(void*);
W1835Res* YS__COMMAND_MENU__add(void*, u16, s32, s32);
W1835Ent* YS__COMMAND_ELEM__Get(u16);
W1835Ctx* func_00177850(W1835Mode*);
f32 func_001ee5d8(u8);
f32 func_001ee5c8(f32, f32);
f32 func_001ee7a8(u8);
f32 func_001ee7a0(f32, f32);
f32 func_001ee988(u8);
f32 func_001ee980(f32, f32);

void func_001ee670(W1835Obj* self, W1835Src* p, W1835Idx* q);  // 0x001ee670: definition moved into src/anon/unit_001ec098.cpp

void func_001ee850(W1835Obj* self, W1835Src* p, W1835Idx* q);  // 0x001ee850: definition moved into src/anon/unit_001ec098.cpp

void func_001eea30(W1835Obj* self, W1835Src* p, W1835Idx* q);  // 0x001eea30: definition moved into src/anon/unit_001ec098.cpp


void YS__FIELD_COMMAND__make_shortcut(W1835Self* self);  // 0x001bed48: definition moved into src/anon/unit_001bc568.cpp

}
