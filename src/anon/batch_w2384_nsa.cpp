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
s32 func_00113fb0(Owner* o, Req* a, St5* st, s32* out, u8 mode);  // 0x00113fb0: definition moved into src/anon/unit_00113fb0.cpp

}
