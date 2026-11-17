// Linked unit 0x001fcaf8-0x001fcc58 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>

// 001fcaf8 (was gap)
namespace n001fcaf8 {
void func_001fcaf8(u8* a0, u8* t) asm("func_001fcaf8");
void func_001fcaf8(u8* a0, u8* t) {
    struct S { s32 a, b, c; };
    u8* b = a0 + **(s32**)(t + 12);
    S* s = (S*)(b + 160);
    s->a = 0;
    s->b = 0;
    s->c = 0;
}
}  // namespace n001fcaf8

// 001fcb18 (was src/anon/batch_w46.cpp)
namespace n001fcb18 {
// 001e0750: static initialiser, now made by gcc in src/anon/unit_001e0398.cpp

// ---- 001fcb18
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0MulMatrix(u8*, u8*, u8*) asm("sceVu0MulMatrix");
void sceVu0CopyMatrix(u8*, u8*) asm("sceVu0CopyMatrix");
/*TARGET 001fcb18*/
void func_001fcb18(u8* p, u32, u8* const q) asm("func_001fcb18");
void func_001fcb18(u8* p, u32, u8* const q) {
    u8* s = p + *(u32*)(*(u8**)(q + 12) + 4) + 160;
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e840, D_01d9e6e8 + 16);
    sceVu0CopyMatrix(s, D_01d9e6e8 + 80);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
}  // namespace n001fcb18

// 001fcb90 (was src/anon/batch_w82.cpp)
namespace n001fcb90 {
extern f32 D_00354be0[3] asm("D_00354be0");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
void sceVu0ScaleVector(u8*, u8*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0ApplyMatrix(u8*, u8*, u8*) asm("sceVu0ApplyMatrix");
void sceVu0CopyMatrix(u8*, u8*) asm("sceVu0CopyMatrix");
void sceVu0MulMatrix(u8*, u8*, u8*) asm("sceVu0MulMatrix");
/*TARGET 001fcb90*/
void func_001fcb90(u8* a0, u32, u8* a2) asm("func_001fcb90");
void func_001fcb90(u8* a0, u32, u8* a2)
{
    u8* p = a0 + *(u32*)(*(u8**)(a2 + 12) + 4) + 160;
    sceVu0ScaleVector(D_01d9e6e8 + 80, D_01d9e6e8 + 16, D_00354be0[0]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8 + 96, D_01d9e6e8 + 32, D_00354be0[1]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8 + 112, D_01d9e6e8 + 48, D_00354be0[2]);  // vec_scale_by_f12
    sceVu0ApplyMatrix(D_01d9e6e8 + 128, D_01d9e840, D_01d9e6e8 + 64);
    sceVu0CopyMatrix(p, D_01d9e6e8 + 80);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
}  // namespace n001fcb90

