/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

namespace w1763 {
/* 00315948 is GCC library code: libsupc++ tinfo.cc,
   __cxxabiv1::__class_type_info::__do_upcast(const __class_type_info*, void**) const.
   It is byte-identical to the toolchain's libsupc++.a (no -fexceptions needed). */
struct ClassTI;
enum SubKind {
    unknown = 0,
    not_contained,
    contained_ambig,
    contained_virtual_mask = 1,
    contained_public_mask = 2,
    contained_mask = 4,
    contained_private = contained_mask,
    contained_public = contained_mask | contained_public_mask
};
struct UpcastResult {
    const void* dst_ptr;
    SubKind part2dst;
    int src_details;
    const ClassTI* base_type;
    UpcastResult(int d) : dst_ptr(0), part2dst(unknown), src_details(d), base_type(0) {}
};
inline bool contained_public_p(SubKind access_path) {
    return (access_path & contained_public) == contained_public;
}
struct ClassTI {
    virtual ~ClassTI();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool do_upcast(const ClassTI* dst, const void* obj, UpcastResult& result) const;
};
}

extern "C" {
bool func_00315948(const w1763::ClassTI* self, const w1763::ClassTI* dst_type, void** obj_ptr) {
    w1763::UpcastResult result(16);
    self->do_upcast(dst_type, *obj_ptr, result);
    if (!w1763::contained_public_p(result.part2dst)) return false;
    *obj_ptr = const_cast<void*>(result.dst_ptr);
    return true;
}
}
