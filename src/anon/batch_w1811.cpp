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

u64 func_001aaea8(W1811Tex* t, s32 n) {
    s32 q = n / (((1 << t->tw) / t->dw) * ((1 << t->th) / t->dh));
    s32 cbp = 36;
    if (q >= 2) cbp = 44;
    s32 psm = (q & 1) + 8;
    switch (t->fmt) {
    case 0: case 1: case 2: case 5: break;
    case 3: psm += 2; break;
    case 4: psm += 4; break;
    }
    return (u64)t->tbp | ((u64)((1 << t->tw) / 64) << 14) | ((u64)cbp << 20) | ((u64)t->tw << 26) | ((u64)t->th << 30) | ((u64)1 << 34) | ((u64)0 << 35) | ((u64)0x3ffc << 37) | ((u64)0 << 51) | ((u64)0 << 55) | ((u64)psm << 56) | ((u64)0 << 61);
}

static inline const unsigned char* w1811_read_encoded_value(void* context, unsigned char encoding,
                                                            const unsigned char* p, W1811UnwindPtr* val)
{
    return func_00314b90(encoding, func_00314a50(encoding, context), p, val);
}

const unsigned char* func_00314ce8(void* context, const unsigned char* p, W1811LsdaHeaderInfo* info)
{
    W1811UnwindWord tmp;
    unsigned char lpstart_encoding;

    info->Start = (context ? func_00317128(context) : 0);

    lpstart_encoding = *p++;
    if (lpstart_encoding != 0xff)
        p = w1811_read_encoded_value(context, lpstart_encoding, p, &info->LPStart);
    else
        info->LPStart = info->Start;

    info->ttype_encoding = *p++;
    if (info->ttype_encoding != 0xff) {
        p = func_00314b00(p, &tmp);
        info->TType = p + tmp;
    } else
        info->TType = 0;

    info->call_site_encoding = *p++;
    p = func_00314b00(p, &tmp);
    info->action_table = p + tmp;

    return p;
}
}
