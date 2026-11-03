#include "../common/types.h"

typedef struct JumpCfg { u8 pad[0xa0]; f32 max; } JumpCfg;
JumpCfg* MGJump_config(void) asm("_ZN2Ti6MGJump6configEv");
extern f32 D_00349e10; /* 1.0f */
typedef struct JS { u8 pad[0x68]; f32 v; u8 flag; } JS;

extern "C" {
/* Ramp a value up toward the jump config's maximum, or back down to 0, by 1.0 per call.
   Register pins ($14 for the offset, $13 for the flag) reproduce the original's t6/t5 numbering. */
void func_002dcf18(u8* a0) {
    register u32 off asm("$14") = 0x8000;
    JS* s = (JS*)(a0 + off);
    register u32 f asm("$13") = s->flag;
    if (f) {
        if (s->v < MGJump_config()->max) s->v = s->v + D_00349e10;
    } else {
        if (s->v > 0.0f) s->v = s->v - D_00349e10;
    }
}
}
