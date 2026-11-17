/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
/* libsupc++ eh_personality.cc: check_exception_spec (GCC library code) */
typedef unsigned W1777UnwindWord __attribute__((__mode__(__word__)));
typedef signed W1777UnwindSword __attribute__((__mode__(__word__)));
typedef unsigned W1777UnwindPtr __attribute__((__mode__(__pointer__)));
class W1777TypeInfo {
public:
    virtual ~W1777TypeInfo();
    virtual bool __is_pointer_p() const;
    virtual bool __is_function_p() const;
    virtual bool __do_catch(const W1777TypeInfo* thr_type, void** thr_obj, unsigned outer) const;
};
struct W1777LsdaHeaderInfo {
    W1777UnwindPtr Start;
    W1777UnwindPtr LPStart;
    W1777UnwindPtr ttype_base;
    const unsigned char* TType;
    const unsigned char* action_table;
    unsigned char ttype_encoding;
    unsigned char call_site_encoding;
};
struct N1777;
typedef s32 (*N1777Fn)(N1777*, s32, s32, s32);
struct N1777 { N1777Fn* vt; };
struct O1777 { u8 pad[0x38]; N1777* first; };
extern "C" {
N1777* anim_next_1777(N1777*) asm("_ZNK2kn13AnimationWork7getNextEv");
N1777* func_0011e7e0(O1777* o, N1777* from, s32 a, s32 b, s32 c);  // 0x0011e7e0: definition moved into src/anon/unit_0011c128.cpp

const unsigned char* func_00314b00(const unsigned char*, W1777UnwindWord*); /* read_uleb128 */
const W1777TypeInfo* func_00314dd8(W1777LsdaHeaderInfo*, W1777UnwindWord); /* get_ttype_entry */
bool func_00314e48(W1777LsdaHeaderInfo* info, const W1777TypeInfo* throw_type, W1777UnwindSword filter_value);  // 0x00314e48: definition moved into src/libsupc++/eh_personality.cpp
}
