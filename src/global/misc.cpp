#include "./misc.hpp"

void printf(void* self) { reinterpret_cast<IntSlot*>(self)->value = 0; }

void pppPartDrawEnd() {}

void ErrorRaise(void* self) { reinterpret_cast<IntSlot*>(self)->value = 0; }

// libgcc's 64-bit helpers live in the game itself (__divdi3 0x3125c0, __udivdi3
// 0x312db8, __umoddi3 0x313498, __muldi3 0x311aa0). Defining them here, in an
// object, keeps ld from pulling the toolchain's own copies out of -lgcc when code
// writes a plain `u64 / u64`, `%` or `*`.
asm(".globl __divdi3\n\t__divdi3 = 0x003125c0\n\t"
    ".globl __udivdi3\n\t__udivdi3 = 0x00312db8\n\t"
    ".globl __umoddi3\n\t__umoddi3 = 0x00313498\n\t"
    ".globl __muldi3\n\t__muldi3 = 0x00311aa0");
