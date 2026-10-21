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
void* func_002fd3e8(u32);
void func_002fde18(void*, s32, u32);
s32 func_0030edb0();
void func_0030ee00();
void func_00315440();
/* libsupc++ eh_alloc.cc __cxa_allocate_exception (gcc 3.2-ee-040921): GCC library code.
 * 0x50 = sizeof(__cxa_exception); 64 emergency buffers of 1024 bytes with a 64-bit used mask.
 * The gthread mutex lock/unlock is replaced by the game's interrupt-state calls
 * (func_0030edb0 result kept in D_01e3c770, func_0030ee00 restores it). func_00315440 = std::terminate. */
void* func_00316560(u32 thrown_size) {
    void* ret;
    thrown_size += 0x50;
    ret = func_002fd3e8(thrown_size);
    if (!ret) {
        D_01e3c770 = func_0030edb0();
        u64 used = D_01e4c780;
        u32 which = 0;
        if (thrown_size > 1024) goto failed;
        while ((bool)(used & 1)) {
            used >>= 1;
            if (++which >= 64) goto failed;
        }
        D_01e4c780 |= (u64)1 << which;
        ret = &D_01e3c780[which][0];
    failed:;
        if (D_01e3c770) func_0030ee00();
        if (!ret) func_00315440();
    }
    func_002fde18(ret, 0, 0x50);
    return (char*)ret + 0x50;
}
}
