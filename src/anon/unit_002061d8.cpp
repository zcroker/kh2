// Linked unit 0x002061d8-0x00206388 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
typedef f32 FMTX65b[4][4] __attribute__((aligned(16)));
typedef f32 FMTX206[4][4] __attribute__((aligned(16)));
typedef f32 FMTX208[4][4] __attribute__((aligned(16)));

// 002061d8 (was gap, written for the unit)
namespace n002061d8 {
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_002061d8(void) asm("func_002061d8");
void func_002061d8(void) {
    D_01d9e6e0[171] = 1;
}
}  // namespace n002061d8

// 002061f0 (was src/anon/misc_2.cpp)
namespace n002061f0 {
/*TARGET 002061f0*/
s64 func_002061f0(s64 param0, s64 param1, s64 param2, s64 param3) asm("_Z13func_002061f0xxxx");
s64 func_002061f0(s64 param0, s64 param1, s64 param2, s64 param3) {
    s64 result = 0, arg0 = param0, arg1 = param1, arg2 = param2, arg3 = param3, returnAddr = 0;
    result = 0 + 0;
    return result;
}
}  // namespace n002061f0

// 002061f8 (was src/anon/batch_w8003_gnsa_nogcse.cpp)
namespace n002061f8 {
// Built with -g -fno-strict-aliasing -fno-gcse. Without gcse, loop invariant
// motion keeps the separate copy of the entry base (move t3,t7).
struct W8003Src { s32 f0; s32 f4; u8 pad[0x18]; f32 x, y, z; };
struct W8003Ent { f32 x, y, z, w; W8003Src* src; s32 f14; s32 pad[2]; };
struct W8003Tbl { u32 n; s32 f4, f8; W8003Ent* e; };
s32 func_002061f0(s32) asm("_Z13func_002061f0xxxx");
/*TARGET 002061f8*/
s32 func_002061f8(W8003Tbl* t, W8003Src* s) asm("func_002061f8");
s32 func_002061f8(W8003Tbl* t, W8003Src* s) {
    if (t->e == 0) return 0;
    for (u32 i = 0; i < t->n; i++) {
        W8003Ent* e = &t->e[i];
        if (e->src == 0) {
            e->src = s;
            e->f14 = func_002061f0(s->f4);
            e->x += s->x;
            e->y += s->y;
            e->z += s->z;
            e->w = 1.0f;
            break;
        }
    }
    return 1;
}
}  // namespace n002061f8

// 002062c0 (was src/anon/batch_w8003_gnsa_nogcse.cpp)
namespace n002062c0 {
struct W8003Src2 { s32 pad0; s32 id; s32 pad[6]; f32 x, y, z; };
struct W8003Ent2 { f32 x, y, z, w; W8003Src2* src; s32 h; s32 pad[2]; };
struct W8003Mgr { s32 pad0; u32 num; s32 pad[2]; W8003Ent2* ents; };
s32 func_002061f0(s32) asm("_Z13func_002061f0xxxx");
/*TARGET 002062c0*/
s32 func_002062c0(W8003Mgr* m, W8003Src2* s) asm("func_002062c0");
s32 func_002062c0(W8003Mgr* m, W8003Src2* s) {
    if (m->ents == 0) return 0;
    for (u32 i = 0; i < m->num; i++) {
        W8003Ent2* e = &m->ents[i];
        if (e->src == 0) {
            e->src = s;
            e->h = func_002061f0(s->id);
            e->x += s->x;
            e->y += s->y;
            e->z += s->z;
            e->w = 1.0f;
            break;
        }
    }
    return 1;
}
}  // namespace n002062c0

