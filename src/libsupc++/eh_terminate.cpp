/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libsupc++ eh_terminate.cc (gcc 3.2-ee-040921), 0x315418-0x3154a8: terminate/unexpected and their handlers (.data 0x3677a8). Linked unit (linked_units.tsv). */
#include <typeinfo>
#include <exception>
#include <cstdlib>
#include "unwind-cxx.h"

using namespace __cxxabiv1;

/* The current installed user handlers.  */
std::terminate_handler __cxxabiv1::__terminate_handler = std::abort;
std::unexpected_handler __cxxabiv1::__unexpected_handler = std::terminate;

void
__cxxabiv1::__terminate (std::terminate_handler handler)
{
  try {
    handler ();
    std::abort ();
  } catch (...) {
    std::abort ();
  }
}

void
std::terminate ()
{
  __terminate (__terminate_handler);
}

void
__cxxabiv1::__unexpected (std::unexpected_handler handler)
{
  handler();
  std::terminate ();
}

void
std::unexpected ()
{
  __unexpected (__unexpected_handler);
}

std::terminate_handler
std::set_terminate (std::terminate_handler func) throw()
{
  std::terminate_handler old = __terminate_handler;
  __terminate_handler = func;
  return old;
}

std::unexpected_handler
std::set_unexpected (std::unexpected_handler func) throw()
{
  std::unexpected_handler old = __unexpected_handler;
  __unexpected_handler = func;
  return old;
}
