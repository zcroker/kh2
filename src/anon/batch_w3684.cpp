#include "../common/types.h"

extern "C" {

extern u8 D_0033cc18[];
void func_00106108(void*);

struct S { void* vt; u32 a; u32 b; };

// Initialises an object (vtable 0x33cc18 and two words) and continues in func_00106108.
// The empty asm emits nothing; it hides where p points so the scheduler keeps the
// stores after the ra save, as in the original.
// 001060b8: moved to src/naka/libkn/memoryallocator.cpp

// Twin of func_001060b8 (same body).
// 001060e0: moved to src/naka/libkn/memoryallocator.cpp

}
