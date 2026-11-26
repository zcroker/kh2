// Linked unit 0x0020d178-0x0020d1d0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
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

// 0020d178 (was src/anon/tiny_wrappers_more.cpp)
namespace n0020d178 {
u32 func_001e7230(u32, u32, u32, u32) asm("_Z13func_001e7230jjjj");
/*TARGET 0020d178*/
// 0x001f4fe0: definition moved into src/anon/unit_001f45f8.cpp

u32 pppSnoScaleAllCon(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z17pppSnoScaleAllConjjjj");
// 0x001f4fe0: definition moved into src/anon/unit_001f45f8.cpp

u32 pppSnoScaleAllCon(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e7230(((u32)(((u32)(a0) + (u32)(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a1) + 12u)))) + 0u)))))) + 160u), 0x0000003cu, a2, a3);
}
}  // namespace n0020d178

// 0020d1a0 (was gap, written for the unit)
namespace n0020d1a0 {
void func_0020d1a0(u8* self, u8* t) asm("func_0020d1a0");
void func_0020d1a0(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    *(u64*)(b + 160) = 0;
    *(u32*)(b + 168) = 0;
}
void func_0020d1b8(u8* self, u8* t) asm("func_0020d1b8");
void func_0020d1b8(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    *(u64*)(b + 160) = 0;
    *(u32*)(b + 168) = 0;
}
}  // namespace n0020d1a0

