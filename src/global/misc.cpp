#include "./misc.hpp"

void printf(void* self) { reinterpret_cast<IntSlot*>(self)->value = 0; }

void pppPartDrawEnd() {}

void ErrorRaise(void* self) { reinterpret_cast<IntSlot*>(self)->value = 0; }

// libgcc's 64-bit divides live in the game itself (__divdi3 0x3125c0, __udivdi3
// 0x312db8). Defining them here, in an object, keeps ld from pulling the
// toolchain's own copies out of -lgcc when C code writes a plain `u64 / u64`.
asm(".globl __divdi3\n\t__divdi3 = 0x003125c0\n\t"
    ".globl __udivdi3\n\t__udivdi3 = 0x00312db8");
