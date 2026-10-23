/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct C8BD8Sel {
    u8 pad[0x188];
    s32 f188;
    void* f18c;
    s32 f190;
};
struct C8BD8O {
    u8 pad0[0x1b0];
    C8BD8Sel s1b0;
    u8 pad[0x348 - 0x1b0 - sizeof(C8BD8Sel)];
    C8BD8Sel s348;
    u8 padb[0x4e0 - 0x348 - sizeof(C8BD8Sel)];
    f32 f4e0;
    f32 f4e4;
    s32 f4e8;
};
extern "C" {
s32 func_00224910(C8BD8O*);
void func_00224920(s32);
QV func_0013f6e8(QV, QV, QV, f32, f32, f32, f32);
void func_00138c68(C8BD8Sel*, s32, s32);
void func_00138c10(C8BD8Sel*, s32);
s32 func_00139d78(C8BD8Sel*);
void func_00139570(C8BD8Sel*);
void func_00139580(C8BD8Sel*);
s32 func_0022b9e0(void);
s32 func_0022b720(void);
void func_001386e0(C8BD8Sel*, s32, s32, s32, s32, s32);
void func_001396b0(C8BD8Sel*);
void func_0031a260(C8BD8Sel*, void*);
}
static inline __attribute__((always_inline)) void c8bd8_setflag(C8BD8Sel* s, void* f) {
    s->f18c = f;
    func_001396b0(s);
    if (s->f18c) {
        s->f190 = 0;
        func_001396b0(s);
        if (s->f190) func_0031a260(s, 0);
    }
}

extern "C" {
/* 00228bd8: gauge update - clamp the input to +-10000, ease the gauge position with the spring helper
   (13f6e8), and switch the selector sprites when the value changes. */
void func_00228bd8(C8BD8O* o) {
    s32 v = func_00224910(o);
    s32 c = v < -10000 ? -10000 : (v > 10000 ? 10000 : v);
    func_00224920(c);
    v = v / 100;
    v = v < -100 ? -100 : (v > 100 ? 100 : v);
    QV a, b, d;
    v = -v;
    a.unit(); b.unit(); d.unit();
    f32 f = o->f4e0;
    d.x = (f32)v;
    o->f4e4 = f;
    a.x = f;
    b.x = f;
    b = func_0013f6e8(b, d, a, 0.4f, 1.2f, 0.5f, 0.1f);
    o->f4e0 = b.x;
    func_00138c68(&o->s1b0, 0, (s32)b.x);
    if (o->f4e8 != c) {
        C8BD8Sel* s1 = &o->s1b0;
        func_00138c10(s1, o->f4e8 >= c ? 24 : 26);
        s1->f188 = 23;
        if (c >= 6000) {
            C8BD8Sel* s = &o->s348;
            if (!func_00139d78(s)) {
                s32 r0 = func_0022b9e0();
                s32 r1 = func_0022b720();
                func_001386e0(s, 2800, r0, r1, 25, 11);
                c8bd8_setflag(s, s1);
                func_00139580(s);
            } else {
                func_00138c10(s, 25);
                func_00139580(s);
            }
        } else {
            if (func_00139d78(&o->s348)) func_00139570(&o->s348);
        }
    }
    o->f4e8 = c;
}
}


/* 00222aa8: build a 256-entry CLUT gradient. Entries are visited in the GS CLUT swizzle order
   (D_0035da40 step table, copied to scratch). Below pos the table is filled with one colour, the rest
   is a linear blend from colB to colA. */
extern "C" {
typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct { s8 v[32]; } __attribute__((aligned(16))) Swz222aa8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V222aa8;
extern Swz222aa8 D_0035da40;
extern s8 D_0035da60[];

void* func_0020eaf8(s32);
void func_0020ebd8(s32);
void func_002f3f10(V222aa8*, V222aa8*, V222aa8*);
void func_002f3e90(V222aa8*, V222aa8*, f32);
void func_002f3ef8(V222aa8*, V222aa8*, V222aa8*);
u32 func_00313bc0(f32); /* __fixunssfsi in the game image */
void func_00222aa8(u32 colA, u32 colB, u32* clut, f32 pos)
{
    Swz222aa8* sw = (Swz222aa8*)func_0020eaf8(32);
    s32 n, i;
    u32* p;
    f32 len;
    V222aa8 d, c;
    ((u128*)sw)[0] = ((u128*)&D_0035da40)[0];
    ((u128*)sw)[1] = ((u128*)&D_0035da40)[1];
    n = pos;
    if (n < 0) {
        if (n < -256) n = -256;
        n += 256;
        p = clut + (n & 0xe0) + D_0035da60[n & 31];
        for (i = n; i < 256; i++) {
            *p = colA;
            p += sw->v[i & 31];
        }
        len = n;
        p = clut;
        i = 0;
    } else {
        if (!(n < 256)) n = 255;
        p = clut;
        for (i = 0; i < n; i++) {
            *p = colB;
            p += sw->v[i & 31];
        }
        len = 256.0f - n;
        n = 256;
    }
    c.x = ((u8*)&colB)[0];
    c.y = ((u8*)&colB)[1];
    c.z = ((u8*)&colB)[2];
    c.w = ((u8*)&colB)[3];
    d.x = ((u8*)&colA)[0];
    d.y = ((u8*)&colA)[1];
    d.z = ((u8*)&colA)[2];
    d.w = ((u8*)&colA)[3];
    func_002f3f10(&d, &d, &c);
    func_002f3e90(&d, &d, len);
    for (; i < n; i++) {
        *p = (func_00313bc0(c.w) << 24 | func_00313bc0(c.y) << 8) | (func_00313bc0(c.x) | func_00313bc0(c.z) << 16);
        func_002f3ef8(&c, &c, &d);
        p += sw->v[i & 31];
    }
    func_0020ebd8(32);
}
}

// 00316188 is libsupc++'s __vmi_class_type_info::__do_upcast (tinfo.cc, GCC 3.2), written as a plain function:
// 003160e0 is the __class_type_info::__do_upcast it calls first; nonvirtual_base_type is the pointer value 8.
struct U316Result;
struct U316ClassTI {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual bool do_upcast(const U316ClassTI* dst, const void* obj, U316Result& result) const;
    const char* name;
    bool operator==(const U316ClassTI& o) const { return name == o.name; }
};
enum U316SubKind {
    sk_unknown = 0, sk_not_contained, sk_contained_ambig,
    sk_virtual_mask = 1, sk_public_mask = 2, sk_contained_mask = 4,
    sk_contained_private = 4, sk_contained_public = 6
};
struct U316Result {
    const void* dst_ptr;
    U316SubKind part2dst;
    int src_details;
    const U316ClassTI* base_type;
    U316Result(int d) : dst_ptr(0), part2dst(sk_unknown), src_details(d), base_type(0) {}
};
struct U316BaseInfo {
    const U316ClassTI* base;
    long offset_flags;
    bool is_virtual_p() const { return offset_flags & 1; }
    bool is_public_p() const { return offset_flags & 2; }
    int offset() const { return static_cast<int>(offset_flags) >> 8; }
};
static inline bool u316_contained_p(U316SubKind k) { return k >= sk_contained_mask; }
static inline bool u316_virtual_p(U316SubKind k) { return k & sk_virtual_mask; }
static inline const void* u316_convert_to_base(const void* addr, bool is_virtual, int offset) {
    if (is_virtual) {
        const void* vtable = *static_cast<const void* const*>(addr);
        offset = *reinterpret_cast<const int*>(static_cast<const char*>(vtable) + offset);
    }
    return static_cast<const char*>(addr) + offset;
}
static const U316ClassTI* const u316_nonvirtual_base_type = static_cast<const U316ClassTI*>(0) + 1;
struct U316VmiTI : U316ClassTI {
    virtual void key();
    unsigned int flags;
    unsigned int base_count;
    U316BaseInfo base_info[1];
    bool do_upcast(const U316ClassTI* dst, const void* obj_ptr, U316Result& result) const;
};
extern "C" {
bool u316_class_do_upcast(const U316VmiTI* self, const U316ClassTI* dst, const void* obj, U316Result& r) asm("func_003160e0");
bool func_00316188(const U316VmiTI* self, const U316ClassTI* dst, const void* obj_ptr, U316Result& result)
{
    if (u316_class_do_upcast(self, dst, obj_ptr, result))
        return true;

    int src_details = result.src_details;
    if (src_details & 0x10)
        src_details = self->flags;

    for (unsigned int i = self->base_count; i--;) {
        U316Result result2(src_details);
        const void* base = obj_ptr;
        int offset = self->base_info[i].offset();
        bool is_virtual = self->base_info[i].is_virtual_p();
        bool is_public = self->base_info[i].is_public_p();

        if (!is_public && !(src_details & 1))
            continue;

        if (base)
            base = u316_convert_to_base(base, is_virtual, offset);

        if (self->base_info[i].base->do_upcast(dst, base, result2)) {
            if (result2.base_type == u316_nonvirtual_base_type && is_virtual)
                result2.base_type = self->base_info[i].base;
            if (u316_contained_p(result2.part2dst) && !is_public)
                result2.part2dst = U316SubKind(result2.part2dst & ~sk_public_mask);

            if (!result.base_type) {
                result = result2;
                if (!u316_contained_p(result.part2dst))
                    return true;

                if (result.part2dst & sk_public_mask) {
                    if (!(self->flags & 1))
                        return true;
                } else {
                    if (!u316_virtual_p(result.part2dst))
                        return true;
                    if (!(self->flags & 2))
                        return true;
                }
            } else if (result.dst_ptr != result2.dst_ptr) {
                result.dst_ptr = 0;
                result.part2dst = sk_contained_ambig;
                return true;
            } else if (result.dst_ptr) {
                result.part2dst = U316SubKind(result.part2dst | result2.part2dst);
            } else {
                if (result2.base_type == u316_nonvirtual_base_type
                    || result.base_type == u316_nonvirtual_base_type
                    || !(*result2.base_type == *result.base_type)) {
                    result.part2dst = sk_contained_ambig;
                    return true;
                }
                result.part2dst = U316SubKind(result.part2dst | result2.part2dst);
            }
        }
    }
    return result.part2dst != sk_unknown;
}
}
