#include "../common/types.h"

// 00117970: takes a free 64-byte slot from the manager, fills its header and parameter
// block, clears its two vectors (VU0) and sets the owner/attribute flags.
struct W3831SlotH { u32 flags; s32 a; s32 pad8; s32 c; };
struct W3831SlotP { s32 d; s32 w; s32 z; s32 pad; };
struct W3831Slot64 { u8 pad[32]; W3831SlotH h; W3831SlotP p; f32 v0[4]; f32 v1[4]; };
struct W3831Slot { W3831SlotH h; W3831SlotP p; f32 v0[4]; f32 v1[4]; };
struct W3831SlotMgr { s32 pad0; s32 owner; u8 pad8[24]; W3831Slot slot[24]; };

extern "C" {
s32 func_001178d0(W3831SlotMgr*);
s32 func_00111e38(s32);

s32 kn__Stitch__startEffect(W3831SlotMgr* m, s32 a, s32 y, s32 z, s32 w, u8 b, s32 c, s32 d);  // 0x00117970: definition moved into src/anon/unit_001178b8.cpp
}
