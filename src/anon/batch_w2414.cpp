#include "../common/types.h"

struct MsgFont {
    u8 pad0[0x11];
    u8 height;          // 0x11
};
struct MsgStyle {
    s32 f0;
    f32 scale;          // 0x04
    f32 width;          // 0x08
    u32 color;          // 0x0c
};
struct MsgSize {
    union {
        s32 w;          // 0x00
        u8 b;           // (keeps loads/stores ordered like the original)
    };
    u32 h;              // 0x04
};

extern "C" {
u8* func_00192388(u8*);                 // next character
s32 func_00192440(u8*, s32);            // is control code
s32 func_00192450(u8*, s32);            // character code
void func_00192f98(MsgStyle*);
f32 func_00192fb8(MsgStyle*);           // scale * width
s32 func_001aae80(MsgFont*, s32);       // glyph width
s32 func_001aae90(u8);
s32 func_001ab820(MsgFont*);
u32 __fixunssfsi(f32);                 // __fixunssfsi

u8* func_00192528(u8* p, MsgFont* font, MsgStyle* st, MsgSize* out) asm("_Z13func_00192528Pv");
// 00192528: moved to src/yasui/libys/message.cpp
}
