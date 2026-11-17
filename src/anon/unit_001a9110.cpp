// Linked unit 0x1a9110-0x1a9130 (YS file 0x1a8618-0x1abad8, part).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"

#ifndef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#endif

// 001a9110 (from src/anon/batch_w1726_g.cpp)
namespace n001a9110 {
struct U4 { u8 b[4]; };
extern U4 D_01c6cc48 asm("D_01c6cc48");
void func_001a9110(U4* p) asm("func_001a9110");
void func_001a9110(U4* p) { D_01c6cc48 = *p; }
} // n001a9110

