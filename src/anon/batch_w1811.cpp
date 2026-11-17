/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

/* 001aaea8: builds a GS TEX0 register value for a texture page. */
struct W1811Tex { s32 fmt; s32 tbp; s32 tw; s32 th; u8 pad[2]; u8 dw; u8 dh; };

/* 00314ce8 is library code: libsupc++ eh_personality.cc parse_lsda_header (gcc 3.2-ee-040921),
 * the static helper between read_encoded_value_with_base (0x314b90) and get_ttype_entry (0x314dd8). */
typedef unsigned int W1811UnwindPtr;
typedef unsigned long W1811UnwindWord;
struct W1811LsdaHeaderInfo {
    W1811UnwindPtr Start;
    W1811UnwindPtr LPStart;
    W1811UnwindPtr ttype_base;
    const unsigned char* TType;
    const unsigned char* action_table;
    unsigned char ttype_encoding;
    unsigned char call_site_encoding;
};

extern "C" {
W1811UnwindPtr func_00317128(void*);       /* _Unwind_GetRegionStart */
W1811UnwindPtr func_00314a50(unsigned char, void*); /* base_of_encoded_value */
const unsigned char* func_00314b00(const unsigned char*, W1811UnwindWord*); /* read_uleb128 */
const unsigned char* func_00314b90(unsigned char, W1811UnwindPtr, const unsigned char*, W1811UnwindPtr*);

u64 func_001aaea8(W1811Tex* t, s32 n);  // 0x001aaea8: definition moved into src/anon/unit_001aaea8.cpp

static inline const unsigned char* w1811_read_encoded_value(void* context, unsigned char encoding,
                                                            const unsigned char* p, W1811UnwindPtr* val)
{
    return func_00314b90(encoding, func_00314a50(encoding, context), p, val);
}

const unsigned char* func_00314ce8(void* context, const unsigned char* p, W1811LsdaHeaderInfo* info);  // 0x00314ce8: definition moved into src/libsupc++/eh_personality.cpp
}
