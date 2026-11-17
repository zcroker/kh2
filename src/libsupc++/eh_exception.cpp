/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libsupc++ eh_exception.cc (gcc 3.2-ee-040921), 0x3167f8-0x3168d8: std::exception, std::bad_exception. Linked unit (linked_units.tsv). */
#include "typeinfo"
#include "exception"
#include "unwind-cxx.h"

std::exception::~exception() throw() { }

std::bad_exception::~bad_exception() throw() { }

const char* 
std::exception::what() const throw()
{
  return typeid (*this).name ();
}
