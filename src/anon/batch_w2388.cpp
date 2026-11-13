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
f32 sinf(f32);
extern f32 D_00349e10;

static inline u32 flag20(Obj17c930* o) { return o->flags & 0x20; }
static inline u32 flag1000000(Obj17c930* o) { return o->flags & 0x1000000; }
static inline u32 flag40(Obj17c930* o) { return o->flags & 0x40; }
static inline bool frozen(Obj17c930* o) { return flag20(o) || flag1000000(o); }
static inline bool stopped(Obj17c930* o) { return frozen(o) || flag40(o); }
static inline bool moving(Obj17c930* o) { return !stopped(o); }

// 0017c930: moved to src/anon/unit_0017c400.cpp
}
