/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc2.c _muldi3.o (gcc 3.2-ee-040921), 0x311aa0-0x311af0: __muldi3. Linked unit (linked_units.tsv). */
typedef int SItype __attribute__((mode(SI)));
typedef unsigned int USItype __attribute__((mode(SI)));
typedef int DItype __attribute__((mode(DI)));
typedef unsigned int UDItype __attribute__((mode(DI)));
struct DWstruct { SItype low, high; };
typedef union { struct DWstruct s; DItype ll; } DWunion;

DItype __muldi3(DItype u, DItype v)
{
    DWunion w;
    DWunion uu, vv;
    uu.ll = u, vv.ll = v;
    w.ll = (UDItype)(USItype)uu.s.low * (USItype)vv.s.low;
    w.s.high += ((USItype)uu.s.low * (USItype)vv.s.high
                 + (USItype)uu.s.high * (USItype)vv.s.low);
    return w.ll;
}
