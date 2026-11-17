/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libsupc++ eh_globals.cc (gcc 3.2-ee-040921), 0x3168d8-0x316d08: __cxa_get_globals(_fast) with the EE thread key. Linked unit (linked_units.tsv). */
#include <exception>
#include <cstdlib>
#define CXA_GLOBALS_THROW
#include "unwind-cxx.h"

using namespace __cxxabiv1;


// Single-threaded fallback buffer.
static __cxa_eh_globals globals_static;

#if __GTHREADS
static __gthread_key_t globals_key;
static int use_thread_key = -1;

static void
get_globals_dtor (void *ptr)
{
  __gthread_key_dtor (globals_key, ptr);
  if (ptr)
    std::free (ptr);
}

static void
get_globals_init ()
{
  use_thread_key =
    (__gthread_key_create (&globals_key, get_globals_dtor) == 0);
}

static void
get_globals_init_once ()
{
  static __gthread_once_t once = __GTHREAD_ONCE_INIT;
  if (__gthread_once (&once, get_globals_init) != 0
      || use_thread_key < 0)
    use_thread_key = 0;
}
#endif

extern "C" __cxa_eh_globals *
__cxa_get_globals_fast ()
{
#if __GTHREADS
  if (use_thread_key)
    return (__cxa_eh_globals *) __gthread_getspecific (globals_key);
  else
    return &globals_static;
#else
  return &globals_static;
#endif
}

extern "C" __cxa_eh_globals *
__cxa_get_globals ()
{
#if __GTHREADS
  __cxa_eh_globals *g;

  if (use_thread_key == 0)
    return &globals_static;

  if (use_thread_key < 0)
    {
      get_globals_init_once ();

      // Make sure use_thread_key got initialized.
      if (use_thread_key == 0)
	return &globals_static;
    }

  g = (__cxa_eh_globals *) __gthread_getspecific (globals_key);
  if (! g)
    {
      if ((g = (__cxa_eh_globals *)
	   std::malloc (sizeof (__cxa_eh_globals))) == 0
	  || __gthread_setspecific (globals_key, (void *) g) != 0)
        std::terminate ();
      g->caughtExceptions = 0;
      g->uncaughtExceptions = 0;
    }

  return g;
#else
  return &globals_static;
#endif
}
