// Linked unit 0x002a98a8-0x002a99c8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/jm_newinfo.hpp"
#include "../tozawa/jm_complete.hpp"
#include "../tozawa/jm_puzzle.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002a98a8 (was src/anon/batch_w3776_nsr.cpp)
namespace n002a98a8 {
struct Ent4 { u8 a; s8 b; u8 c, d; };
struct Tbl { s32 count; Ent4 e[1]; };
u8* func_002a9d68(void) asm("func_002a9d68");
void func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b038(u32) asm("func_0028b038");
u32 func_002a92a0(s32) asm("func_002a92a0");
s32 func_002a99c8(u32) asm("func_002a99c8");
void func_002aae30(s32) asm("func_002aae30");
extern u32 D_0035f200 asm("D_0035f200");
extern Tbl* D_0035f608 asm("D_0035f608");
void func_002a98a8(void) asm("func_002a98a8");
void func_002a98a8(void) {
    u8* p = func_002a9d68();
    func_00287bc0();
    s32 base = func_0028b038(D_0035f200);
    s32 n = D_0035f608->count;
    if (n > 10) n = 10;
    s32 i;
    for (i = 0; i < n;) {
        s32 k = base + i;
        i++;
        s32 c = D_0035f608->e[k].b;
        if (c < 0) continue;
        if (func_002a99c8(func_002a92a0(c)) == 3) continue;
        s32 d = D_0035f608->e[k].b;
        u32* bits = (u32*)(p + 148);
        if (bits[(u32)d >> 5] & (1 << (d & 31))) continue;
        func_002aae30(d);
    }
}
}  // namespace n002a98a8

