// Linked unit 0x00113fb0-0x001140d0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../naka/libkn/friend_personality.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../naka/libkn/ability_info.hpp"

// 00113fb0 (was src/anon/batch_w2384_nsa.cpp)
namespace n00113fb0 {
struct St5 { s32 a, b, c, d, e; };
struct Inner { u8 pad[0x300]; u8 sub[0x6f4]; St5 st; u8 pad2[0xec]; s8 flag; };
struct Owner { u32 x0; Inner* in; };
struct Req { u8 pad[0x10]; s32* q; u8 pad2[0xc]; s32 id; };
s32 func_001883d8(void*, s32) asm("func_001883d8");
s32 func_00188758(void*) asm("func_00188758");
s32 func_0010f448(Inner*, Req*, s32, s32) asm("func_0010f448");
void func_00188170(void*, s32) asm("func_00188170");
/*TARGET 00113fb0*/
// mode != 0: save the state block into *st and run the checks; mode == 0: restore it.
s32 func_00113fb0(Owner* o, Req* a, St5* st, s32* out, u8 mode) asm("func_00113fb0");
// mode != 0: save the state block into *st and run the checks; mode == 0: restore it.
s32 func_00113fb0(Owner* o, Req* a, St5* st, s32* out, u8 mode) {
    if (mode) {
        *out = 0;
        *st = o->in->st;
        if (!a || !a->id || !func_001883d8(o->in->pad + 0x300, a->id) || !func_00188758(o->in->pad + 0x300)) return 0;
        if (!func_0010f448(o->in, a, 1, 1)) return 0;
    } else {
        o->in->st = *st;
        if (a->q) { s32 v = a->q[2]; o->in->flag = v; }
        func_00188170(o->in->pad + 0x300, a->id);
    }
    return 1;
}
}  // namespace n00113fb0

