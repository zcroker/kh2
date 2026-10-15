/* Original license notice of newlib/libc/stdio/puts.c, retained as it requires: */
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/* Original license notice of newlib/libc/stdio/wsetup.c, retained as it requires: */
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/* newlib/libc/reent/readr.c carries no license notice of its own; it is part of newlib
 * (https://sourceware.org/newlib/), whose components are BSD-style/permissively licensed. */

/* Reconstructions of newlib C-library functions the game links (newlib 1.10/1.11-era sources),
 * built as C by the game's gcc 3.2.
 *   002fe018 _puts_r    - from newlib/libc/stdio/puts.c (University of California, Berkeley)
 *   003015f8 __swsetup  - from newlib/libc/stdio/wsetup.c (University of California, Berkeley)
 *   00305168 _read_r    - from newlib/libc/reent/readr.c (newlib, Cygnus Support)
 */
#include "../common/types.h"

/* newlib stdio FILE (struct __sFILE) */
struct __sbuf { u8* _base; s32 _size; };
struct _reent;
struct __sFILE {
    u8* _p; s32 _r; s32 _w;
    s16 _flags; s16 _file;
    struct __sbuf _bf;
    s32 _lbfsize;
    void* _cookie;
    s32 (*_read)(void*, char*, s32);
    s32 (*_write)(void*, const char*, s32);
    s32 (*_seek)(void*, s32, s32);
    s32 (*_close)(void*);
    struct __sbuf _ub;
    u8* _up; s32 _ur;
    u8 _ubuf[3]; u8 _nbuf[1];
    struct __sbuf _lb;
    s32 _blksize; s32 _offset;
    struct _reent* _data;
};
struct __siov { const void* iov_base; s32 iov_len; };
struct __suio { struct __siov* uio_iov; s32 uio_iovcnt; s32 uio_resid; };
/* newlib struct _reent, leading fields */
struct _reent {
    s32 _errno;
    struct __sFILE *_stdin, *_stdout, *_stderr;
    s32 _inc;
    char _emergency[25];
    s32 _current_category;
    const char* _current_locale;
    s32 __sdidinit;
};

extern struct _reent* D_00365c48;                          /* _impure_ptr */
extern int D_00378ae4;                                     /* errno */
extern const char D_003778d8[];                            /* "\n" */
u32  func_002ff3fc(const char* s);                         /* strlen */
s32  func_003032d0(struct __sFILE* fp, struct __suio* uio);/* __sfvwrite */
void func_00302e10(struct _reent* s);                      /* __sinit */
void func_00302e90(struct _reent* ptr, void* p);           /* _free_r */
void func_00303808(struct __sFILE* fp);                    /* __smakebuf */
int  func_00305c68(int fd, void* buf, u32 cnt);            /* _read */

#define NULL 0
#define EOF  (-1)
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SRD  0x0004
#define __SWR  0x0008
#define __SRW  0x0010
#define __SEOF 0x0020
#define CHECK_INIT(fp) \
  do { if ((fp)->_data == 0) (fp)->_data = D_00365c48; \
       if (!(fp)->_data->__sdidinit) func_00302e10((fp)->_data); } while (0)
#define HASUB(fp) ((fp)->_ub._base != NULL)
#define FREEUB(fp) { \
    if ((fp)->_ub._base != (fp)->_ubuf) \
      func_00302e90((fp)->_data, (char *)(fp)->_ub._base); \
    (fp)->_ub._base = NULL; \
  }

/* 002fe018: _puts_r (newlib/libc/stdio/puts.c) */
int func_002fe018(struct _reent* ptr, const char* s) asm("_Z16wtarget_002fe018jjjj");
int func_002fe018(struct _reent* ptr, const char* s)
{
  u32 c = func_002ff3fc(s);
  struct __suio uio;
  struct __siov iov[2];

  iov[0].iov_base = s;
  iov[0].iov_len = c;
  iov[1].iov_base = D_003778d8;
  iov[1].iov_len = 1;
  uio.uio_resid = c + 1;
  uio.uio_iov = &iov[0];
  uio.uio_iovcnt = 2;

  return (func_003032d0(ptr->_stdout, &uio) ? EOF : '\n');
}

/* 003015f8: __swsetup (newlib/libc/stdio/wsetup.c; this version has no __SSTR test) */
int func_003015f8(struct __sFILE* fp)
{
  CHECK_INIT (fp);

  if ((fp->_flags & __SWR) == 0)
    {
      if ((fp->_flags & __SRW) == 0)
        return EOF;
      if (fp->_flags & __SRD)
        {
          /* clobber any ungetc data */
          if (HASUB (fp))
            FREEUB (fp);
          fp->_flags &= ~(__SRD | __SEOF);
          fp->_r = 0;
          fp->_p = fp->_bf._base;
        }
      fp->_flags |= __SWR;
    }

  if (fp->_bf._base == NULL)
    func_00303808 (fp);

  if (fp->_flags & __SLBF)
    {
      fp->_w = 0;
      fp->_lbfsize = -fp->_bf._size;
    }
  else
    fp->_w = fp->_flags & __SNBF ? 0 : fp->_bf._size;

  return 0;
}

/* 00305168: _read_r (newlib/libc/reent/readr.c); _ssize_t is long */
long func_00305168(struct _reent* ptr, int fd, void* buf, u32 cnt)
{
  long ret;

  D_00378ae4 = 0;
  if ((ret = (long)func_00305c68 (fd, buf, cnt)) == -1 && D_00378ae4 != 0)
    ptr->_errno = D_00378ae4;
  return ret;
}
