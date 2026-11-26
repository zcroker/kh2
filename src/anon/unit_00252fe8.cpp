// Linked unit 0x00252fe8-0x002530c8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/smenu_cana.hpp"
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
#include "../tozawa/campmenu.hpp"
#include "../tozawa/cmenu_data.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00252fe8 (was src/anon/batch_owner1023_nsi.cpp)
namespace n00252fe8 {
void func_0023d320() asm("func_0023d320");
s32 func_002888c8() asm("func_002888c8");
s32 func_002535d0(s32) asm("func_002535d0");
void Tz__MenuSound__SetPause(s32) asm("Tz__MenuSound__SetPause");
s32 func_0028cbf8() asm("func_0028cbf8");
s16 func_0028d0c8(s32) asm("func_0028d0c8");
void func_00287910(s32, s32, s32) asm("func_00287910");
s32 func_00103570() asm("func_00103570");
void Tz__MenuCursor__Init(s32, s32) asm("Tz__MenuCursor__Init");
void func_002530c8() asm("func_002530c8");
void func_002425d0(s32) asm("func_002425d0");
struct W1595Fns { void (*f0)(); void (*f4)(); };
W1595Fns* func_00253330(s32) asm("func_00253330");
extern volatile s32 D_0035f3d4v asm("D_0035f3d4");
struct W1595Pair { s16 a, b; };
extern W1595Pair D_01dae6a8 asm("D_01dae6a8");
/*TARGET 00252fe8*/
void func_00252fe8(s32 id) asm("func_00252fe8");
void func_00252fe8(s32 id) {
    func_0023d320();
    s32 k = id;
    if (id == 10) k = func_002888c8();
    if (k != 9 && k != 15 && k != 8) Tz__MenuSound__SetPause(func_002535d0(k));
    D_01dae6a8.a = D_0035f3d4v;
    D_01dae6a8.b = !func_0028cbf8() ? -1 : func_0028d0c8(0);
    func_00287910(id, 4, 0);
    Tz__MenuCursor__Init(func_00103570(), 3);
    func_002530c8();
    func_002425d0(1);
    func_00253330(id)->f4();
}
}  // namespace n00252fe8

