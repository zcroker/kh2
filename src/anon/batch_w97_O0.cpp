#include "../common/types.h"

extern "C" {
// ---- 002b871c
struct Clip2b8 { s32 a, b, c, d, e, f, g; s32 xmax; s32 step; s32 ymax; s32 flag; };
struct Ctx2b8 { u8 pad[0x48000]; Clip2b8 clip; };
void func_002b871c(Ctx2b8* p) {
    p->clip.a = p->clip.b = p->clip.c = p->clip.d = p->clip.e = p->clip.f = p->clip.g = 0;
    p->clip.xmax = 16383;
    p->clip.step = 64;
    p->clip.ymax = 16383;
    p->clip.flag = 0;
}

}
