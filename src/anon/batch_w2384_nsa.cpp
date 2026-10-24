#include "../common/types.h"

extern "C" {

struct St5 { s32 a, b, c, d, e; };
struct Inner { u8 pad[0x300]; u8 sub[0x6f4]; St5 st; u8 pad2[0xec]; s8 flag; };
struct Owner { u32 x0; Inner* in; };
struct Req { u8 pad[0x10]; s32* q; u8 pad2[0xc]; s32 id; };
s32 func_001883d8(void*, s32);
s32 func_00188758(void*);
s32 func_0010f448(Inner*, Req*, s32, s32);
void func_00188170(void*, s32);

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

}
