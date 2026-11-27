/* libkernl_00310958.c: Sony PS2 Runtime Library 3.0.0 libkernl: frequency to bus clock conversion, 0x310958-0x310990.
 * ee-gcc 2.96 -O2 -G0 -fno-optimize-sibling-calls (nop;nop before div.s, no sibling call), linked unit.
 * Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */

/* ---- 0x310958 (gap) */
extern unsigned long func_00311cc0(float);
unsigned long func_00310958(float usec)
{
    return func_00311cc0(147456000.0f / usec);
}
