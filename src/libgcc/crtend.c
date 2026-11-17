/* Third-party code notice: this file contains code rebuilt to match the GNU Compiler
 * Collection's runtime startup file crtstuff.c (GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* crtend.o: the CRT_END part of crtstuff.c (0x101ce0-0x101d50), a linked unit. It runs the
 * static constructors from the end of .ctors backwards. CRT_CALL_STATIC_FUNCTION puts the call
 * stub's jal in .init (0x319798, inside _init in src/anon/gcc_crt_init.s), so only the stub's
 * frame is left in .text. */

typedef void (*func_ptr)(void);

/* __CTOR_END__: the zero word that ends the game's .ctors table. */
extern func_ptr __CTOR_END__[] asm("D_0037a6e4");

void __do_global_ctors_aux(void) asm("func_00101ce0");
void __do_global_ctors_aux(void)
{
    func_ptr *p;
    for (p = __CTOR_END__ - 1; *p != (func_ptr)-1; p--)
        (*p)();
}

void call___do_global_ctors_aux(void) asm("func_00101d38");
void call___do_global_ctors_aux(void)
{
    asm(".section\t.init");
    __do_global_ctors_aux();
    asm(".section\t.text");
}
