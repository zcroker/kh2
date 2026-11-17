/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libsupc++ eh_catch.cc (gcc 3.2-ee-040921), 0x3166f0-0x3167f8: __cxa_begin_catch, __cxa_end_catch, std::uncaught_exception. Linked unit (linked_units.tsv). */
#include <cstdlib>
#include "unwind-cxx.h"

using namespace __cxxabiv1;


extern "C" void *
__cxa_begin_catch (void *exc_obj_in)
{
  _Unwind_Exception *exceptionObject
    = reinterpret_cast <_Unwind_Exception *>(exc_obj_in);

  // ??? Foreign exceptions can't be stacked here, and there doesn't
  // appear to be any place to store for __cxa_end_catch to destroy.

  __cxa_exception *header = __get_exception_header_from_ue (exceptionObject);
  __cxa_eh_globals *globals = __cxa_get_globals ();
  __cxa_exception *prev = globals->caughtExceptions;
  int count = header->handlerCount;

  // Count is less than zero if this exception was rethrown from an
  // immediately enclosing region.
  if (count < 0)
    count = -count + 1;
  else
    count += 1;
  header->handlerCount = count;

  globals->uncaughtExceptions -= 1;
  if (header != prev)
    {
      header->nextException = prev;
      globals->caughtExceptions = header;
    }

  return header->adjustedPtr;
}


extern "C" void
__cxa_end_catch ()
{
  __cxa_eh_globals *globals = __cxa_get_globals_fast ();
  __cxa_exception *header = globals->caughtExceptions;
  int count = header->handlerCount;

  if (count < 0)
    {
      // This exception was rethrown.  Decrement the (inverted) catch
      // count and remove it from the chain when it reaches zero.
      if (++count == 0)
	{
	  globals->uncaughtExceptions += 1;
	  globals->caughtExceptions = header->nextException;
	}
    }
  else if (--count == 0)
    {
      // Handling for this exception is complete.  Destroy the object.
      globals->caughtExceptions = header->nextException;
      _Unwind_DeleteException (&header->unwindHeader);
      return;
    }
  else if (count < 0)
    // A bug in the exception handling library or compiler.
    std::abort ();

  header->handlerCount = count;
}


bool
std::uncaught_exception() throw()
{
  __cxa_eh_globals *globals = __cxa_get_globals ();
  return globals->uncaughtExceptions != 0;
}
