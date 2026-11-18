// Linked unit 0x001002b0-0x001003c8.
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 001002b0 (was src/anon/batch_w57.cpp)
namespace n001002b0 {
// 0x1008d0 is __deregister_frame_info (src/libgcc/unwind-dw2-fde.c); crtbegin references it weakly.
void func_001008d0(BD_VALUE*) asm("__deregister_frame_info") __attribute__((weak));
// Run the static constructors once (crt-style).
extern u8 D_0037aa00 asm("D_0037aa00");
extern void (**D_0032b914)() asm("D_0032b914");
extern BD_VALUE D_00378ae8 asm("D_00378ae8");
/*TARGET 001002b0*/
void func_001002b0(void) asm("func_001002b0");
void func_001002b0(void) {
    if (!D_0037aa00) {
        void (**p)();
        void (*f)();
        while ((f = *(p = D_0032b914)) != 0) {
            D_0032b914 = p + 1;
            f();
        }
        u32 r = 1;
        if (func_001008d0) {
            func_001008d0(&D_00378ae8);
        }
        D_0037aa00 = r;
    }
}
}  // namespace n001002b0

// 00100338 (was src/anon/batch_w2.cpp)
namespace n00100338 {
/*TARGET 00100338*/
// Empty function that still saves ra (clobber forces the frame).
void func_00100338(void) asm("func_00100338");
// Empty function that still saves ra (clobber forces the frame).
void func_00100338(void) {
    asm volatile("" : : : "$31");
}
}  // namespace n00100338

// 00100350 (was src/anon/auto80_199_queue.cpp)
namespace n00100350 {
/*TARGET 00100350*/
// 0x001003c8: definition moved into src/libgcc/unwind-dw2-fde.c

void func_00100350(void) asm("_Z13func_00100350v");
// 0x001003c8: definition moved into src/libgcc/unwind-dw2-fde.c

void func_00100350(void) {
    if (func_00100690 != 0) {
        func_00100690(&D_00378ae8, (u32)&D_0037aa08);
    }

    if (*(u32*)&D_0037a4b0 != 0) {
        if (func_00000000 != 0) {
            func_00000000(&D_0037a4b0);
        }
    }
}
}  // namespace n00100350

// 001003b0 (was src/anon/batch_w3.cpp)
namespace n001003b0 {
/*TARGET 001003b0*/
// Empty function that still saves ra (the clobber forces the frame).
void func_001003b0() asm("func_001003b0");
// Empty function that still saves ra (the clobber forces the frame).
void func_001003b0() { asm volatile("" ::: "$31"); }
}  // namespace n001003b0

