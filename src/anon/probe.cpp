#include "../common/types.h"

extern "C" {

// Clears two quadwords.
void func_0011c138(void* p) {  // vec4_zero
    asm volatile(".set noreorder\n\tsq $0, 0(%0)\n\tsq $0, 16(%0)\n\t.set reorder" : : "r"(p) : "memory");
}

struct Pair8 { u8 a; u8 b; u8 pad[2]; s32 c; };
void func_0010b550(Pair8* p);  // 0x0010b550: definition moved into src/anon/unit_0010b450.cpp

extern u32 D_0033cc38;
extern u32 D_0033cc3c;
// Sets the current value, keeping the previous one.
// 001069b8: moved to src/naka/libkn/camera.cpp

// 00134d60: moved to src/anon/unit_00134668.cpp

}
