// Linked unit 0x001de9a8-0x001deb58 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 001de9a8 (was src/anon/batch_owner1021_gnsa_nogcse.cpp)
namespace n001de9a8 {
// 001de9a8 and 001dea80: two identical bodies, built with -g -fno-strict-aliasing -fno-gcse.
struct Bits { u32 b0:1; u32 p1:15; u32 b16:1; u32 b17:1; u32 rest:14; };
struct Info { u32 pad[4]; union { u32 w; s32 sw; Bits f; } fl; };
struct Obj { u8 pad[0x40]; s32 m40; Info* m44; s32 m48; s32 m4c; f32 m50; s32 m54; s32 m58; s32 m5c; };
s32 func_001e0128(s32) asm("func_001e0128");
void func_001e0370(s32) asm("func_001e0370");
void func_001dca30(s32, s32, s32) asm("func_001dca30");
/*TARGET 001de9a8*/
void func_001de9a8(Obj* o, s32 a1, Info* a2, s32 a3, f32 f) asm("func_001de9a8");
void func_001de9a8(Obj* o, s32 a1, Info* a2, s32 a3, f32 f) {
    o->m40 = a1; o->m44 = a2; o->m48 = a3; o->m50 = f; o->m4c = 0; o->m54 = -1; o->m58 = 0; o->m5c = 0;
    if ((u8)a2->fl.f.b0) o->m5c = 1;
    if (a2->fl.w & 0x20000) o->m5c |= 2;
    if (a2->fl.w & 0x10000) {
        s32 p = func_001e0128(0x40);
        func_001e0370(p);
        o->m58 = p;
        func_001dca30(o->m40, p + 0x20, 2);
        o->m5c |= 4;
    }
}
}  // namespace n001de9a8

// 001dea80 (was src/anon/batch_owner1021_gnsa_nogcse.cpp)
namespace n001dea80 {
// 001de9a8 and 001dea80: two identical bodies, built with -g -fno-strict-aliasing -fno-gcse.
struct Bits { u32 b0:1; u32 p1:15; u32 b16:1; u32 b17:1; u32 rest:14; };
struct Info { u32 pad[4]; union { u32 w; s32 sw; Bits f; } fl; };
struct Obj { u8 pad[0x40]; s32 m40; Info* m44; s32 m48; s32 m4c; f32 m50; s32 m54; s32 m58; s32 m5c; };
s32 func_001e0128(s32) asm("func_001e0128");
void func_001e0370(s32) asm("func_001e0370");
void func_001dca30(s32, s32, s32) asm("func_001dca30");
/*TARGET 001dea80*/
void func_001dea80(Obj* o, s32 a1, Info* a2, s32 a3, f32 f) asm("func_001dea80");
void func_001dea80(Obj* o, s32 a1, Info* a2, s32 a3, f32 f) {
    o->m40 = a1; o->m44 = a2; o->m48 = a3; o->m50 = f; o->m4c = 0; o->m54 = -1; o->m58 = 0; o->m5c = 0;
    if ((u8)a2->fl.f.b0) o->m5c = 1;
    if (a2->fl.w & 0x20000) o->m5c |= 2;
    if (a2->fl.w & 0x10000) {
        s32 p = func_001e0128(0x40);
        func_001e0370(p);
        o->m58 = p;
        func_001dca30(o->m40, p + 0x20, 2);
        o->m5c |= 4;
    }
}
}  // namespace n001dea80

