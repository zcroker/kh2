/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

// 001ef038: per-channel random colour offset (u8 channels)
struct W1840C8 { u8 r, g, b, a; };
struct W1840Arg8 { s32 id; s32 idx; W1840C8 add; u8 flag; };
union W1840FU { f32 f; u8 c; };

// 00315a08 is libsupc++'s __vmi_class_type_info::__do_find_public_src (tinfo.cc, GCC 3.2).
struct W1840TypeInfo {
    const char* name;
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual s32 find_public_src(s32 src2dst, const void* obj, const W1840TypeInfo* src, const void* srcp) const;
    bool operator==(const W1840TypeInfo& o) const { return name == o.name; }
};
struct W1840BaseInfo {
    const W1840TypeInfo* base; long flags;
    bool is_virtual() const { return flags & 1; }
    bool is_public() const { return flags & 2; }
    s32 offset() const { return (s32)flags >> 8; }
};
static inline bool w1840_contained_p(s32 k) { return k >= 4; }
static inline const void* w1840_convert_to_base(const void* addr, bool v, s32 off) {
    if (v) { const void* vt = *(const void* const*)addr; off = *(const s32*)((const char*)vt + off); }
    return (const char*)addr + off;
}
struct W1840VmiTypeInfo : W1840TypeInfo {
    virtual void key(); // never defined here, so this file emits no vtable
    u32 vflags; u32 count; W1840BaseInfo info[1];
    s32 find_public_src(s32 src2dst, const void* obj, const W1840TypeInfo* src, const void* srcp) asm("func_00315a08");
};
// the line break keeps the layout scanner able to see this definition
s32 W1840VmiTypeInfo::
find_public_src(s32 src2dst, const void* obj, const W1840TypeInfo* src, const void* srcp) {
    if (obj == srcp && *this == *src) return 6;
    for (u32 i = count; i--;) {
        if (!info[i].is_public()) continue;
        const void* base = obj;
        s32 off = info[i].offset();
        bool v = info[i].is_virtual();
        if (v) { if (src2dst == -3) continue; }
        base = w1840_convert_to_base(base, v, off);
        s32 k = info[i].base->find_public_src(src2dst, base, src, srcp);
        if (w1840_contained_p(k)) {
            if (v) k = k | 1;
            return k;
        }
    }
    return 1;
}

// 002ecb90: 16-byte VU0 vector with lq/sq copies and VU0 macro-mode operators
struct W1840Vec {
    f32 x, y, z, w;
    W1840Vec() {}
    W1840Vec(const W1840Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1840Vec& operator=(const W1840Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1840Vec operator-(const W1840Vec& b) const {
        W1840Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1840Vec operator+(const W1840Vec& b) const {
        W1840Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1840Vec operator*(f32 s) const {
        W1840Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    W1840Vec& operator-=(const W1840Vec& b) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1840Path;
struct W1840PathOwner { u8 pad[1288]; W1840Path* path; };
W1840Vec w1840_get_current_pos(W1840Path*) asm("_ZN2Ti4Path15get_current_posEv");
extern "C" {
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern u8 D_01d9e360[];
f32 func_001eef90(u8);
s8 func_001eef68(s32, f32);

void func_001ef038(u8* a0, W1840Arg8* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1840FU*)(p + 160))->f = func_001eef90(a1->flag);
    f32* s3 = (f32*)(p + 160);
    s3[1] = func_001eef90(a1->flag);
    s3[2] = func_001eef90(a1->flag);
    s3[3] = func_001eef90(a1->flag);
    s32 idx = a1->idx;
    W1840C8* s0;
    if (idx != -1) s0 = (W1840C8*)(a0 + idx + 160); else s0 = (W1840C8*)D_01d9e360;
    { f32 ff = s3[0]; s0->r += func_001eef68((s8)a1->add.r, ff); }
    s0->g += func_001eef68((s8)a1->add.g, s3[1]);
    s0->b += func_001eef68((s8)a1->add.b, s3[2]);
    s0->a += func_001eef68((s8)a1->add.a, s3[3]);
}
extern f32 D_01e2c060;
extern W1840Vec D_00363550;
u64 func_00313b80(f32);
u64 func_00313f40(u64, u64);
f32 func_003144b0(u64);
f32 func_002f8960(f32);
W1840Vec* func_0016c028(W1840PathOwner*);

W1840Vec* func_002ecb90(W1840Vec* r, void* self, W1840PathOwner* o) {
    f32 s = D_01e2c060 / 10.0f;
    s = func_002f8960(func_003144b0(func_00313f40(func_00313b80(s * 3.14159274f), 0x3fe0000000000000ULL)));
    W1840Vec p;
    p = w1840_get_current_pos(o->path);
    *r = p - D_00363550;
    *r = D_00363550 + *r * s;
    *r -= *func_0016c028(o);
    return r;
}
}
