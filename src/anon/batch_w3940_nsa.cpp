#include "../common/types.h"
// Frame-border GS sprite packets: fill RGBAQ / XYZ2 data words (z from the source), then kick the packets.
struct Src166da8 { u8 on; u8 mode; u8 pad[2]; s32 z; };
extern u64 D_0034c990[];
extern u64 D_0034caf0[];
extern u8 D_0034cce0[];
extern u8 D_0034d150[];
extern u8 D_0034d180[];
extern "C" {
void func_0014d8d0(void*);
void func_00166da8(Src166da8* p);  // 0x00166da8: definition moved into src/anon/unit_001664c0.cpp
}
