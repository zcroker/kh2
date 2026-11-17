#include "../common/types.h"
extern "C" {
struct W1718Select {
    s16 cur;        // 0x00 cursor inside the visible page
    s16 pad2;
    s16 last;       // 0x04
    s16 keyUp;      // 0x06
    s16 keyDown;    // 0x08
    s16 keyLeft;    // 0x0a
    s16 keyRight;   // 0x0c
    s16 padE[2];
    s16 top;        // 0x12 first item of the visible page
    s16 pad14;
    s16 count;      // 0x16 item count
    s16 cols;       // 0x18 items per row
    s16 rows;       // 0x1a visible rows
    u8 pad1c[8];
    u8 loop;        // 0x24 wrap around
};
struct W1718Pad {
    u64 pad0;
    u64 trig;       // 0x08
    u64 pad10;
    u64 rep;        // 0x18
};
s32 func_0028af78(W1718Select*, s32);
void func_0028b120(W1718Select*, s32*, s32*, s32);
u8 W1718_IsCenter(void*) asm("_Z13func_0028b210Pv");
s32 func_0028a5a8(W1718Select*, W1718Pad*);

// Tz::Select: move the cursor on a grid of items from the pad input.
// Returns 1 if a direction key was handled, 0 if the move is blocked.
s32 func_00289ef8(W1718Select* sel, W1718Pad* pad);  // 0x00289ef8: definition moved into src/anon/unit_00288b00.cpp
}
