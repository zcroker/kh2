#include "../common/types.h"

extern "C" {

struct Ctl78 { s32 on; s32 f4, f8, f12, f16, f20; s32 f24; u32 a, b, c, d; s32 f44, f48, f52; };
struct Obj78 { u8 pad[0x48000]; Ctl78 ctl; };
void func_002b8824(Obj78* o, u32 a, u32 b, u32 c, u32 d)
{
    o->ctl.f4 = o->ctl.f8 = o->ctl.f12 = o->ctl.f16 = o->ctl.f20 = 0;
    o->ctl.f24 = 0x8000;
    o->ctl.a = a;
    o->ctl.b = b;
    o->ctl.c = c;
    o->ctl.d = d;
    o->ctl.on = 1;
    o->ctl.f44 = o->ctl.f48 = o->ctl.f52 = 0;
}

} // extern "C"
