#include "../common/types.h"
struct W1575Hdr { u16 f0, f2, f4, f6, lo, hi, max, fe, f10, f12, f14, f16; s32 off; };
struct W1575Obj { u8 pad[8]; s32 f8; };
extern "C" {
// Compare two resources: same header fields and the same set of valid table entries.
s32 func_00132338(W1575Obj*);
W1575Hdr* func_00132c68(W1575Obj*);
s32 func_00132ab0(W1575Obj* a, W1575Obj* b);  // 0x00132ab0: definition moved into src/anon/unit_00131418.cpp
}
