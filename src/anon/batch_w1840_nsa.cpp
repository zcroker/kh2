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

// 0x00315a08: definition moved into src/libsupc++/tinfo.cpp

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

void func_001ef038(u8* a0, W1840Arg8* a1, u8* a2);  // 0x001ef038: definition moved into src/anon/unit_001ec098.cpp
extern f32 D_01e2c060;
extern W1840Vec D_00363550;
u64 func_00313b80(f32);
u64 func_00313f40(u64, u64);
f32 __truncdfsf2(u64);
f32 sinf(f32);
W1840Vec* func_0016c028(W1840PathOwner*);

// 002ecb90: moved to src/anon/unit_002ec5f8.cpp
}
