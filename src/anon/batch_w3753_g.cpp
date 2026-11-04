#include "../common/types.h"
extern "C" {
struct VO;
typedef void (*VFn6)(VO*, s32, s32, s32, s32, s32, s32);
struct VO { void** vt; };
struct Hd { u8 pad[8]; u32 f8; };
s32 func_00246840(void);
VO* func_00287dc0(void);
void func_0023d808(VO*, s32);
void func_0023e858(VO*, s32, f32);
void func_0023e8b8(VO*, s32, f32);
void func_0023e8d8(VO*, s32, f32);
s32 func_00139d78(u32);
void func_0023e9b0(VO*, s32, u32);
void func_0023e690(VO*, s32, s32, s32);
extern Hd* D_0035ed38;

void func_00245968(void) {
    s32 id, x, y;
    f32 f;
    if (func_00246840()) {
        id = 1106; f = -149.0f; x = 204; y = 386;
    } else {
        id = 1105; f = -626.0f; x = 177; y = 163;
    }
    VO* o = func_00287dc0();
    func_0023d808(o, 30008);
    ((VFn6)o->vt[6])(o, 0, id | 0x20000000, 134, 2, x, y);
    func_0023e858(o, 0, f);
    func_0023e8b8(o, 0, 0.0f);
    func_0023e8d8(o, 0, 22.0f);
    register s32 r4 asm("$4");
    Hd* h;
    asm("" : "=r"(h) : "0"(D_0035ed38), "r"(r4));
    func_00139d78(h->f8);
    u32 v = h->f8;
    func_0023e9b0(o, 0, v);
    func_0023e690(o, 0, 135, -1);
}
}
