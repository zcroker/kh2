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

f32 func_00230f10(f32 time, W1694Key* keys, s32 n, s32 arg) {
    f32 result = 0.0f;
    f32 t = time / 30.0f;
    s32 pre = 1;
    s32 post = 1;
    if (n > 0) {
        if (n == 1) {
            result = keys[0].value;
        } else {
            s32 frame;
            if (func_00232328() != 0) {
                frame = (s32)(t * 512.0f + 0.5f);
            } else {
                frame = (s32)(t * 512.0f);
            }
            if (frame <= keys[0].time) {
                if (pre == 1) {
                    f32 d = (f32)(keys[1].time - keys[0].time);
                    f32 slope;
                    if (keys[0].type == 1 && d != 0.0f) slope = (keys[1].value - keys[0].value) / d;
                    else slope = keys[0].slopeIn;
                    result = keys[0].value - (f32)(keys[0].time - frame) * slope;
                } else {
                    result = 0.0f;
                }
            } else if (frame >= keys[n - 1].time) {
                if (post == 1) {
                    f32 d = (f32)(keys[n - 1].time - keys[n - 2].time);
                    f32 slope;
                    if (keys[n - 1].type == 1 && d != 0.0f) slope = (keys[n - 1].value - keys[n - 2].value) / d;
                    else slope = keys[n - 1].slopeOut;
                    result = keys[n - 1].value + (f32)(frame - keys[n - 1].time) * slope;
                } else {
                    result = 0.0f;
                }
            } else {
                s32 lo = 0;
                s32 hi = n - 1;
                while (hi - lo >= 2) {
                    s32 mid = (lo + hi) / 2;
                    if (frame < keys[mid].time) {
                        hi = mid;
                    } else if (frame > keys[mid].time) {
                        lo = mid;
                    } else {
                        result = keys[mid].value;
                        goto end;
                    }
                }
                return func_00230de0(t, hi - 1, keys, arg);
            }
        }
    }
end:
    return result;
}
}
