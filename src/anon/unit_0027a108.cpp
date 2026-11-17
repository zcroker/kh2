// Linked unit 0x0027a108-0x0027a208 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 0027a108 (was src/anon/batch_w41.cpp)
namespace n0027a108 {
// 0x00259510: definition moved into src/anon/unit_002588e8.cpp

u32 func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028dac8(u32, u32) asm("func_0028dac8");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_0028acb8(u32) asm("func_0028acb8");
void func_0028aa40(u32) asm("func_0028aa40");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 0027a108*/
void func_0027a108(void) asm("func_0027a108");
void func_0027a108(void) {
    u32 o = func_00257770();
    if (func_00287bc0() == 15) {
        func_0028dac8(o, 142);
        if (func_0028acc8(D_0035f01c) && !func_0028acb8(D_0035f01c)) func_0028aa40(D_0035f01c);
    }
}
}  // namespace n0027a108

// 0027a180 (was src/anon/auto200_999.cpp)
namespace n0027a180 {
void func_002579e0(void) asm("_Z13func_002579e0v");
void func_0028abe0(u32) asm("_Z13func_0028abe0j");
u32 func_0028acc8(u32) asm("_Z13func_0028acc8j");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 0027a180*/
// 0x00271e80: definition moved into src/anon/unit_00271e08.cpp

void func_0027a180() asm("_Z13func_0027a180v");
// 0x00271e80: definition moved into src/anon/unit_00271e08.cpp

void func_0027a180() {
    func_002579e0();
    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028abe0(D_0035f01c);
    }
}
}  // namespace n0027a180

// 0027a1c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0027a1c8 {
extern u32 D_0035f01c asm("D_0035f01c");
u32 func_0028acc8(...) asm("func_0028acc8");
// 0x00262118: definition moved into src/anon/unit_0025f6b8.cpp

extern "C" u32 func_00257780(...) asm("func_00257780");
/*TARGET 0027a1c8*/
u32 func_0027a1c8() asm("_Z13func_0027a1c8v");
u32 func_0027a1c8() {
    u32 v0 = func_00257780();
    if (v0 == 0u) {
        u32 a0 = *(u32*)(u32)&D_0035f01c;
        if (a0 != 0u) {
            v0 = (u32)(0u < func_0028acc8(a0));
        }
    }
    return v0;
}
}  // namespace n0027a1c8

