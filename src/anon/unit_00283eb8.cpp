// Linked unit 0x00283eb8-0x00283f50 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/gumi_pause.hpp"
#include "../tozawa/cmenu_config.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tz/ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/chg_member.hpp"

// 00283eb8 (was src/anon/batch_w3827_nsi.cpp)
namespace n00283eb8 {
struct E1 { u32 p; u8 b[3]; u8 f; };
extern E1 D_003742c8[] asm("D_003742c8");
extern s8 D_00374268[] asm("D_00374268");
extern char D_00374270[] asm("D_00374270");
s32 func_00283a58(s32, s32) asm("func_00283a58");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
/*TARGET 00283eb8*/
// Formats entry a1 of the D_003742c8 table into a0.
void func_00283eb8(char* a0, s32 a1) asm("func_00283eb8");
// Formats entry a1 of the D_003742c8 table into a0.
void func_00283eb8(char* a0, s32 a1) {
    register E1* e asm("$15") = &D_003742c8[a1]; // pin: entry address in t7
    u8 f = e->f;
    s32 v = func_00283a58((s32)a0, a1);
    if (f & 0xfb) {
        if (v != 1 || (f & 2)) goto T;
    }
    v = 2;
T:;
    s8* q = &D_00374268[v];
    u32 p = D_003742c8[a1].p;
    register char* r4 asm("$4") = a0; // pin: first argument
    // no code: one more reader of a0 so sched2 issues move a0 before the q address add
    asm("" : "+r"(p) : "r"(r4));
    func_002fee78(r4, D_00374270, p, *q);
}
}  // namespace n00283eb8

