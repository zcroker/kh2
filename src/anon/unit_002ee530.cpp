// Linked unit 0x002ee530-0x002ee588 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
typedef unsigned int u128 __attribute__((mode(TI)));
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"

// 002ee530 (was src/anon/tiny.cpp)
namespace n002ee530 {
extern u32 D_003637f8 asm("D_003637f8");
/*TARGET 002ee530*/
// 0x002e10c0: definition moved into src/anon/unit_002de3c8.cpp

// 002e2920: moved to src/anon/unit_002e1908.cpp

// 002e2930: moved to src/anon/unit_002e1908.cpp

u32 func_002ee530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ee530jjjj");
// 0x002e10c0: definition moved into src/anon/unit_002de3c8.cpp

// 002e2920: moved to src/anon/unit_002e1908.cpp

// 002e2930: moved to src/anon/unit_002e1908.cpp

u32 func_002ee530(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_003637f8 != 0);
}
}  // namespace n002ee530

// 002ee540 (was src/anon/batch_w1669.cpp)
namespace n002ee540 {
struct W1669Pair { u32 a, b; };
extern W1669Pair D_01e2c080 asm("D_01e2c080");
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ee540jjjj");
/*TARGET 002ee540*/
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ee540jjjj");
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) { D_01e2c080.b = 0; D_01e2c080.a = 0; }
}
}  // namespace n002ee540

// 002ee568 (was src/anon/tiny_wrappers_more.cpp)
namespace n002ee568 {
u32 func_002ee540(u32, u32, u32, u32) asm("_Z13func_002ee540jjjj");
/*TARGET 002ee568*/
// 002ead78: moved to src/anon/unit_002eaa68.cpp

// 002eaf18: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_002eae08.cpp

// 002ebc00: moved to src/anon/unit_002eaf38.cpp

// 002ec138: moved to src/anon/unit_002eaf38.cpp

// 002ec560: moved to src/anon/unit_002eaf38.cpp

// 002ecaa8: moved to src/anon/unit_002ec5f8.cpp

// 002ecd58: moved to src/anon/unit_002ec5f8.cpp

u32 func_002ee568(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ee568jjjj");
// 002ead78: moved to src/anon/unit_002eaa68.cpp

// 002eaf18: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_002eae08.cpp

// 002ebc00: moved to src/anon/unit_002eaf38.cpp

// 002ec138: moved to src/anon/unit_002eaf38.cpp

// 002ec560: moved to src/anon/unit_002eaf38.cpp

// 002ecaa8: moved to src/anon/unit_002ec5f8.cpp

// 002ecd58: moved to src/anon/unit_002ec5f8.cpp

u32 func_002ee568(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002ee540(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002ee568

