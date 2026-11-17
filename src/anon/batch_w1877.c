/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
/* unwind.inc _Unwind_ForcedUnwind_Phase2 (gcc 3.2 unwind-dw2.c): GCC library code. */
struct UwCtx { u8 pad[708]; void* cfa; u32 ra; u8 pad2[28]; };
typedef s32 (*Pers)(s32, s32, u64, void*, struct UwCtx*);
struct UwFs { u8 pad[2840]; s64 cfa_offset; u64 cfa_reg; u8 pad2[4]; s32 cfa_how; void* pc; Pers personality; u8 pad3[24]; };
struct UwExc { u64 exception_class; void* cleanup; u64 private_1; u64 private_2; };
typedef s32 (*StopFn)(s32, s32, u64, struct UwExc*, struct UwCtx*, void*);
s32 func_00317d80(struct UwCtx*, struct UwFs*);
void func_003181a0(struct UwCtx*, struct UwFs*);
s32 func_00318ca0(struct UwExc* exc, struct UwCtx* context);  // 0x00318ca0: definition moved into src/libgcc/unwind-dw2.c
