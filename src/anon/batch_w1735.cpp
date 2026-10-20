/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

namespace w1735 {
// YS::OBJ: bit 0 of the word at 0x108 and bit 0 of the word at 0x7f8 are flag bitfields.
struct Obj {
    u8 pad0[0x108];
    u32 flag108 : 1;
    u32 rest108 : 31;
    u8 pad1[0x7f8 - 0x10c];
    u32 flag7f8 : 1;
    u32 rest7f8 : 31;
};
// Per-id bit sets: 64 bits per id.
struct BitRow { u32 w[2]; };
struct BitKey { u8 id; u8 bit; };
static inline bool BitTest(u32* bits, u32 n) { return (bits[n >> 5] & (1 << (n & 31))) != 0; }
// libsupc++ __class_type_info layout (gcc 3.2 tinfo.cc); vtable slot 8 = __do_find_public_src.
struct ClassTI {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual s32 do_find_public_src(s32 src2dst, const void* obj_ptr, const ClassTI* src_type, const void* src_ptr) const;
    const char* name;
};
struct SiClassTI : ClassTI { const ClassTI* base_type; };
}

extern "C" {
s32 w1735_Obj_is_attach(w1735::Obj*) asm("_ZN2YS3OBJ9is_attachEv");
extern w1735::BitRow D_0032dfd0[];

s32 func_0019bad8(w1735::Obj* o) {
    if (!o->flag7f8) return 0;
    if (o->flag108) return 0;
    return w1735_Obj_is_attach(o) == 0;
}

s32 func_001d9d48(w1735::BitKey* k) {
    return w1735::BitTest(D_0032dfd0[k->id].w, k->bit);
}

// libsupc++ __si_class_type_info::__do_find_public_src (6 = __contained_public).
s32 func_003159c8(const w1735::SiClassTI* self, s32 src2dst, const void* obj_ptr, const w1735::ClassTI* src_type, const void* src_ptr) {
    if (src_ptr == obj_ptr && self->name == src_type->name) return 6;
    return self->base_type->do_find_public_src(src2dst, obj_ptr, src_type, src_ptr);
}
}
