// Linked unit (see linked_units.tsv); one namespace per old matched source.
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include <stdarg.h>

// 002b6678 (was src/anon/batch_w61_O0.cpp)
namespace n002b6678 {
void func_003058a0(u32) asm("func_003058a0");
struct E64 { u32 used; u8 pad[60]; };
extern E64 D_01e22080[512] asm("D_01e22080");
/*TARGET 002b6678*/
// Returns the index of the first free 64-byte slot, or -1.
s32 func_002b6678(void) asm("func_002b6678");
// Returns the index of the first free 64-byte slot, or -1.
s32 func_002b6678(void) {
    func_003058a0(0);
    for (s32 i = 0; i < 512; i++) {
        if (D_01e22080[i].used == 0) return i;
    }
    return -1;
}
}  // namespace n002b6678

