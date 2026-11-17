/* Sony PS2 Runtime Library (libkernl timer helpers). Third-party code: Sony Computer Entertainment's
 * library, rebuilt here only to match the game's executable; it is not covered by this project's license. */

/* Bus clock ticks (147.456 MHz) divided by a tick count. The original was built by a compiler that
 * emits two nops before div.s (ee-gcc 2.96 does); ee-gcc 2.9 does not, so only the divide is asm.
 * The u64 -> float conversion calls libgcc's __floatdisf at 0x311af0 directly (gcc's own expansion
 * would link to a different copy). */
extern float __floatdisf(long);
float func_00310900(unsigned long x);  // 0x00310900: definition moved into src/sdk/libkernl_00310048.c
