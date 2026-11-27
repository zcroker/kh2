// Linked unit 0x00246f80-0x00247198 (own flags: -fno-strength-reduce)
#include "../common/types.h"
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
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/munny.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/config.hpp"
#include "../tozawa/sub_menu.hpp"
#include "../tozawa/smenu_he.hpp"
#include "../tozawa/smenu_heco.hpp"

// 00246f80 (was src/anon/batch_w317.cpp)
namespace n00246f80 {
struct W317Obj;
struct W317VT { void* f[5]; void (*f20)(W317Obj*); };
struct W317Obj { W317VT* vt; };
struct W317A { u8 d[408]; };
struct W317B { u8 d[436]; };
struct W317G { W317B b0; W317B b1; W317B b[4][4]; u8 pad[7848 - 872 - 436 * 16]; W317A a[4][4]; };
// 0x0013cbb8: definition moved into src/anon/unit_0013a8b8.cpp

s32 func_00139d78(W317Obj*) asm("func_00139d78");
extern W317G* D_0035ed40 asm("D_0035ed40");
static inline void w317upd(void* p) {
    W317Obj* o = (W317Obj*)p;
    if (func_00139d78(o)) o->vt->f20(o);
}
/*TARGET 00246f80*/
void func_00246f80(void) asm("func_00246f80");
void func_00246f80(void) {
    w317upd(&D_0035ed40->b0);
    w317upd(&D_0035ed40->b1);
    s32 k = 0;
    s32 ob = 0;
    s32 oa = 0;
    do {
        w317upd((u8*)D_0035ed40 + oa + 7848);
        w317upd((u8*)D_0035ed40 + oa + 9480);
        w317upd((u8*)D_0035ed40 + oa + 11112);
        w317upd((u8*)D_0035ed40 + oa + 12744);
        w317upd((u8*)D_0035ed40 + ob + 872);
        w317upd((u8*)D_0035ed40 + ob + 2616);
        w317upd((u8*)D_0035ed40 + ob + 4360);
        w317upd((u8*)D_0035ed40 + ob + 6104);
        k++;
        ob += 436;
        oa += 408;
    } while (k < 4);
}
}  // namespace n00246f80
