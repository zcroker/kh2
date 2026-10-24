#include "../common/types.h"

struct V4c17c930 { f32 x, y, z, w; };
struct Obj17c930 {
    u8 pad0[0xd0];
    f32 t, len, base, amp;
    u8 pade0[0x120 - 0xe0];
    f32 scale;
    u8 pad124[0x160 - 0x124];
    u32 flags;
};

extern "C" {
V4c17c930* func_0016c028(Obj17c930*);
f32 func_002f8960(f32);
extern f32 D_00349e10;

static inline u32 flag20(Obj17c930* o) { return o->flags & 0x20; }
static inline u32 flag1000000(Obj17c930* o) { return o->flags & 0x1000000; }
static inline u32 flag40(Obj17c930* o) { return o->flags & 0x40; }
static inline bool frozen(Obj17c930* o) { return flag20(o) || flag1000000(o); }
static inline bool stopped(Obj17c930* o) { return frozen(o) || flag40(o); }
static inline bool moving(Obj17c930* o) { return !stopped(o); }

/* 0017c930: offset that follows func_002f8960(func_002f8960(t*pi/2)*pi/2) while t < len and a parabola
   after it, measured from the current position (func_0016c028()->y) and clamped to scale * D_00349e10. */
f32 func_0017c930(void* self, Obj17c930* o) {
    if (moving(o)) {
        f32 r;
        f32 a = o->t; f32 b = o->len;
        if (a < b) {
            f32 t = a / b;
            t = func_002f8960(func_002f8960(t * 3.14159274f * 0.5f) * 3.14159274f * 0.5f);
            r = o->base + o->amp * t;
        } else {
            f32 t = a - b;
            r = o->base + o->amp + t * 0x1.a1f58cp-2f * t * 0.5f;
        }
        f32 v = r - func_0016c028(o)->y;
        f32 lim = o->scale * D_00349e10;
        if (v < lim) return r - func_0016c028(o)->y;
        return lim;
    }
    return 0.0f;
}
}
