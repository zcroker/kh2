// Linked unit 0x00117778-0x00119bf8.
#include "../naka/libkn/stitch.hpp"
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 00117778 (was src/naka/libkn/stitch.cpp)
namespace kn { // method 00117778
extern void Stitch_update_obj_pos(void*) asm("_ZN2kn6Stitch14update_obj_posEv");
/*TARGET 00117778*/
void Stitch::post_exec() { Stitch_update_obj_pos(this); }
}  // kn

// 00117790 (was gap)
namespace g00117790 {
s32 func_001dca20(void*) asm("func_001dca20");
void func_00117910(void*, s32) asm("func_00117910");
// For each of the 24 slots whose object is still alive, call the slot handler 0x117910.
void f(u8* o) asm("func_00117790");
void f(u8* o) {
    u8* p = o + 40;
    for (s32 i = 0; i < 24; i++) {
        void* e = *(void**)p;
        p += 64;
        if (e && func_001dca20(e)) func_00117910(o, i);
    }
}
}  // namespace g00117790

