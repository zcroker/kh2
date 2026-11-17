/* ctype.h: newlib's ctype macros over _ctype_ (libc/ctype/ctype_.c, 257 entries; the table is not linked as a
 * unit yet: _ctype_ + 1 is the game's D_00377b68). Third-party code notice: not covered by this project's MIT
 * License. newlib, Copyright (c) 1990 The Regents of the University of California (BSD license). */
#ifndef KH2_NEWLIB_CTYPE_H
#define KH2_NEWLIB_CTYPE_H
#define _U 01
#define _L 02
#define _N 04
#define _S 010
#define _P 020
#define _C 040
#define _X 0100
#define _B 0200
extern const char _ctype_[];
asm("_ctype_ = D_00377b68 - 1");
#define isalpha(c) ((_ctype_ + 1)[(unsigned)(c)] & (_U | _L))
#define isupper(c) ((_ctype_ + 1)[(unsigned)(c)] & _U)
#define islower(c) ((_ctype_ + 1)[(unsigned)(c)] & _L)
#define isdigit(c) ((_ctype_ + 1)[(unsigned)(c)] & _N)
#define isspace(c) ((_ctype_ + 1)[(unsigned)(c)] & _S)
#endif
