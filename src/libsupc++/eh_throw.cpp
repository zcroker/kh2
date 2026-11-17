/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libsupc++ eh_throw.cc (gcc 3.2-ee-040921), 0x3154a8-0x3155c0: __cxa_throw, __cxa_rethrow. Linked unit (linked_units.tsv). */
#include <typeinfo>
#include <exception>
#include "unwind-cxx.h"

using namespace __cxxabiv1;


static void
__gxx_exception_cleanup (_Unwind_Reason_Code code, _Unwind_Exception *exc)
{
  __cxa_exception *header = __get_exception_header_from_ue (exc);

  // If we haven't been caught by a foreign handler, then this is
  // some sort of unwind error.  In that case just die immediately.
  if (code != _URC_FOREIGN_EXCEPTION_CAUGHT)
    __terminate (header->terminateHandler);

  if (header->exceptionDestructor)
    header->exceptionDestructor (header + 1);

  __cxa_free_exception (header + 1);
}


extern "C" void
__cxa_throw (void *obj, std::type_info *tinfo, void (*dest) (void *))
{
  __cxa_exception *header = __get_exception_header_from_obj (obj);
  header->exceptionType = tinfo;
  header->exceptionDestructor = dest;
  header->unexpectedHandler = __unexpected_handler;
  header->terminateHandler = __terminate_handler;
  header->unwindHeader.exception_class = __gxx_exception_class;
  header->unwindHeader.exception_cleanup = __gxx_exception_cleanup;

  __cxa_eh_globals *globals = __cxa_get_globals ();
  globals->uncaughtExceptions += 1;

#ifdef _GLIBCPP_SJLJ_EXCEPTIONS
  _Unwind_SjLj_RaiseException (&header->unwindHeader);
#else
  _Unwind_RaiseException (&header->unwindHeader);
#endif

  // Some sort of unwinding error.  Note that terminate is a handler.
  __cxa_begin_catch (&header->unwindHeader);
  std::terminate ();
}

extern "C" void
__cxa_rethrow ()
{
  __cxa_eh_globals *globals = __cxa_get_globals ();
  __cxa_exception *header = globals->caughtExceptions;

  // Watch for luser rethrowing with no active exception.
  if (header)
    {
      // Tell __cxa_end_catch this is a rethrow.
      header->handlerCount = -header->handlerCount;

#ifdef _GLIBCPP_SJLJ_EXCEPTIONS
      _Unwind_SjLj_RaiseException (&header->unwindHeader);
#else
      _Unwind_RaiseException (&header->unwindHeader);
#endif

      // Some sort of unwinding error.  Note that terminate is a handler.
      __cxa_begin_catch (&header->unwindHeader);
    }
  std::terminate ();
}
