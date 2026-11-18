// Linked unit 0x0028be78-0x0028bfc0 (scroll bar position update; was whole asm in src/anon/batch_w3884.s).
#include "../common/types.h"

namespace n0028be78 {
void func_0028e8b8(s32, s32, s32, s32) asm("func_0028e8b8");
struct Bar28b { s32 h; u8 p4[28]; s32 total; s32 disp; s32 pos; s32 size; s32 view; };
/*TARGET 0028be78*/
// Stores the new position, then places the bar: length = size / view * (disp / total) clamped to 1,
// offset = size / total * pos with pos clamped to total - disp. The position clamp comes after the
// ratio clamp in the source: written before it, the scheduler pulls `li a1,1` above the pos + disp add.
void func_0028be78(Bar28b* p, s32 pos) asm("func_0028be78");
void func_0028be78(Bar28b* p, s32 pos) {
    s32 flag = 0;
    p->pos = pos;
    s32 disp = p->disp;
    s32 total = p->total;
    f32 r = (f32)disp / (f32)total;
    if (1.0f <= r) { r = 1.0f; flag = 1; }
    s32 n = pos;
    if (pos + disp >= total) n = total - disp;
    f32 sz = (f32)p->size;
    f32 q = sz / (f32)p->view * r;
    r = sz / (f32)total * (f32)n;
    s32 v = (s32)r;
    func_0028e8b8(p->h, 1, 0, v);
    func_0028e8b8(p->h, 2, 0, v);
    f32 w = (f32)p->view * q;
    n = v + (s32)w;
    if (flag) { if (w - (f32)n == 0.0f) n--; }
    func_0028e8b8(p->h, 3, 0, n);
}
}  // namespace n0028be78
