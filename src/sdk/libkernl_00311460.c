/* libkernl_00311460.c: Sony PS2 Runtime Library 3.0.0 libkernl: TLB handler range check, 0x311460-0x311490.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int func_00311450(int);
int func_00311460(int x) { if ((unsigned int)(x - 13) >= 35) return -1; return func_00311450(x); }
