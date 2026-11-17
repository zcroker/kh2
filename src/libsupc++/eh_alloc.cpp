/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libsupc++ eh_alloc.cc (gcc 3.2-ee-040921), 0x316560-0x3166f0: __cxa_allocate_exception, __cxa_free_exception and the emergency pool. Linked unit (linked_units.tsv). */
#include <exception>
#include <cstdlib>
#include <cstring>
#include <climits>
#include "unwind-cxx.h"

using namespace __cxxabiv1;


// ??? How to control these parameters.

// Guess from the size of basic types how large a buffer is reasonable.
// Note that the basic c++ exception header has 13 pointers and 2 ints,
// so on a system with PSImode pointers we're talking about 56 bytes
// just for overhead.

#if INT_MAX == 32767
# define EMERGENCY_OBJ_SIZE	128
# define EMERGENCY_OBJ_COUNT	16
#elif LONG_MAX == 2147483647
# define EMERGENCY_OBJ_SIZE	512
# define EMERGENCY_OBJ_COUNT	32
#else
# define EMERGENCY_OBJ_SIZE	1024
# define EMERGENCY_OBJ_COUNT	64
#endif

#ifndef __GTHREADS
# undef EMERGENCY_OBJ_COUNT
# define EMERGENCY_OBJ_COUNT	4
#endif

#if INT_MAX == 32767 || EMERGENCY_OBJ_COUNT <= 32
typedef unsigned int bitmask_type;
#else
typedef unsigned long bitmask_type;
#endif


typedef char one_buffer[EMERGENCY_OBJ_SIZE] __attribute__((aligned));
static one_buffer emergency_buffer[EMERGENCY_OBJ_COUNT];
static bitmask_type emergency_used;


#ifdef __GTHREADS
#ifdef __GTHREAD_MUTEX_INIT
static __gthread_mutex_t emergency_mutex =__GTHREAD_MUTEX_INIT;
#else 
static __gthread_mutex_t emergency_mutex;
#endif

#ifdef __GTHREAD_MUTEX_INIT_FUNCTION
static void
emergency_mutex_init ()
{
  __GTHREAD_MUTEX_INIT_FUNCTION (&emergency_mutex);
}
#endif
#endif


extern "C" void *
__cxa_allocate_exception(std::size_t thrown_size)
{
  void *ret;

  thrown_size += sizeof (__cxa_exception);
  ret = std::malloc (thrown_size);

  if (! ret)
    {
#ifdef __GTHREADS
#ifdef __GTHREAD_MUTEX_INIT_FUNCTION
      static __gthread_once_t once = __GTHREAD_ONCE_INIT;
      __gthread_once (&once, emergency_mutex_init);
#endif
      __gthread_mutex_lock (&emergency_mutex);
#endif

      bitmask_type used = emergency_used;
      unsigned int which = 0;

      if (thrown_size > EMERGENCY_OBJ_SIZE)
	goto failed;
      while (used & 1)
	{
	  used >>= 1;
	  if (++which >= EMERGENCY_OBJ_COUNT)
	    goto failed;
	}

      emergency_used |= (bitmask_type)1 << which;
      ret = &emergency_buffer[which][0];

    failed:;
#ifdef __GTHREADS
      __gthread_mutex_unlock (&emergency_mutex);
#endif
      if (!ret)
	std::terminate ();
    }

  std::memset (ret, 0, sizeof (__cxa_exception));

  return (void *)((char *)ret + sizeof (__cxa_exception));
}


extern "C" void
__cxa_free_exception(void *vptr)
{
  char *ptr = (char *) vptr;
  if (ptr >= &emergency_buffer[0][0]
      && ptr < &emergency_buffer[0][0] + sizeof (emergency_buffer))
    {
      unsigned int which
	= (unsigned)(ptr - &emergency_buffer[0][0]) / EMERGENCY_OBJ_SIZE;

#ifdef __GTHREADS
      __gthread_mutex_lock (&emergency_mutex);
      emergency_used &= ~((bitmask_type)1 << which);
      __gthread_mutex_unlock (&emergency_mutex);
#else
      emergency_used &= ~((bitmask_type)1 << which);
#endif
    }
  else
    std::free (ptr - sizeof (__cxa_exception));
}
