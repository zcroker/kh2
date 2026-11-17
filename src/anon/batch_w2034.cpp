/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
extern s32 D_01e3c770;
extern u8 D_01e3c780[64][1024];
extern u64 D_01e4c780;
extern "C" {
void* malloc(u32);
void func_002fde18(void*, s32, u32);
s32 DIntr();
void EIntr();
void func_00315440();
/* libsupc++ eh_alloc.cc __cxa_allocate_exception (gcc 3.2-ee-040921): GCC library code.
 * 0x50 = sizeof(__cxa_exception); 64 emergency buffers of 1024 bytes with a 64-bit used mask.
 * The gthread mutex lock/unlock is replaced by the game's interrupt-state calls
 * (DIntr result kept in D_01e3c770, EIntr restores it). func_00315440 = std::terminate. */
void* __cxa_allocate_exception(u32 thrown_size);  // 0x00316560: definition moved into src/libsupc++/eh_alloc.cpp
}
