#include "../common/types.h"

// Keyframe curve: 16-byte keys {time:29, type:3, value, slopeIn, slopeOut}.
// Evaluates at time/30 seconds (frame = 512 ticks), extrapolating linearly
// before the first and after the last key, else binary-searches and calls
// the segment interpolator func_00230de0.
extern "C" {
struct W1694Key {
    s32 time : 29;
    u32 type : 3;
    f32 value;
    f32 slopeIn;
    f32 slopeOut;
};
s32 func_00232328(void);
f32 func_00230de0(f32, s32, W1694Key*, s32);

f32 func_00230f10(f32 time, W1694Key* keys, s32 n, s32 arg);  // 0x00230f10: definition moved into src/anon/unit_002302c0.cpp
}
