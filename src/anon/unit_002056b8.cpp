// Linked unit 0x002056b8-0x00205798 (one namespace per old matched source; class methods in their own namespace).
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

// 002056b8 (was gap, written for the unit)
namespace n002056b8 {
typedef unsigned int u128g __attribute__((mode(TI)));
struct EmG { f32 m[4][4]; u128g v; u8* parts; u8* p84; u8* p88; s32 count; u16 h96; u16 h98; };
extern f32 D_01da8b50[4][4] asm("D_01da8b50");
void sceVu0UnitMatrix(f32 (*)[4]) asm("sceVu0UnitMatrix");
void func_002056b8(u8* base, u8* c) asm("func_002056b8");
void func_002056b8(u8* base, u8* c) {
    EmG* e = (EmG*)(base + (*(s32**)(c + 12))[2] + 160);
    sceVu0UnitMatrix(e->m);
    e->v = 0;
    e->parts = 0;
    e->p84 = 0;
    e->p88 = 0;
    e->count = 0;
    e->h96 = 0;
    e->h98 = 0;
    void (*f)(f32 (*)[4]) = sceVu0UnitMatrix;
    f(D_01da8b50);
}
}  // namespace n002056b8

// 00205718 (was src/anon/batch_w61.cpp)
namespace n00205718 {
void func_001e7798(u32, u32) asm("func_001e7798");
extern u32 D_01d9e6e4 asm("D_01d9e6e4");
/*TARGET 00205718*/
void func_00205718(u8* a0, u8* a1) asm("func_00205718");
void func_00205718(u8* a0, u8* a1) {
    u8* s = a0 + *(u32*)(*(u8**)(a1 + 12) + 8) + 160;
    if (*(u32*)(s + 80)) { func_001e7798(D_01d9e6e4, *(u32*)(s + 80)); *(u32*)(s + 80) = 0; }
    if (*(u32*)(s + 84)) { func_001e7798(D_01d9e6e4, *(u32*)(s + 84)); *(u32*)(s + 84) = 0; }
    if (*(u32*)(s + 88)) { func_001e7798(D_01d9e6e4, *(u32*)(s + 88)); *(u32*)(s + 88) = 0; }
}
}  // namespace n00205718

