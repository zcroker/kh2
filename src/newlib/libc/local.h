/* local.h: the parts of newlib's libc/stdio/local.h and stdio.h flags that the stdio objects use.
 * Third-party code notice: not covered by this project's MIT License. newlib, Copyright (c) 1990 The Regents
 * of the University of California (BSD license). */
#ifndef KH2_NEWLIB_LOCAL_H
#define KH2_NEWLIB_LOCAL_H
#include "newlib.h"
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SRD  0x0004
#define __SWR  0x0008
#define __SRW  0x0010
#define __SEOF 0x0020
#define __SERR 0x0040
#define __SMBF 0x0080
#define __SAPP 0x0100
#define __SSTR 0x0200
#define __SOPT 0x0400
#define __SNPT 0x0800
#define __SOFF 0x1000
#define __SMOD 0x2000

#define _REENT _impure_ptr
void __sinit(struct _reent *);
#ifndef KH2_DEFINES_SINIT
asm("__sinit = func_00302e10");
#endif
#define CHECK_INIT(fp) \
  do { \
    if ((fp)->_data == 0) \
      (fp)->_data = _REENT; \
    if (!(fp)->_data->__sdidinit) \
      __sinit((fp)->_data); \
  } while (0)

#define HASUB(fp) ((fp)->_ub._base != NULL)
#define FREEUB(fp) { \
    if ((fp)->_ub._base != (fp)->_ubuf) \
      _free_r((fp)->_data, (char *)(fp)->_ub._base); \
    (fp)->_ub._base = NULL; \
  }
#endif
