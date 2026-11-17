/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

/* 0018a670: VU0 vector helpers (lq/sq copy, vsub/vmul macro ops). */
#define W1886QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1886V {
    f32 x, y, z, w;
    W1886V() {}
    W1886V(const W1886V& o) { W1886QCOPY(this, &o); }
    W1886V& operator=(const W1886V& o) { if (this != &o) W1886QCOPY(this, &o); return *this; }
    W1886V operator-(const W1886V& b) const {
        W1886V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1886V operator*(const W1886V& b) const {
        W1886V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1886V operator*(f32 s) const {
        W1886V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1886Body { u8 pad[4]; f32 h; f32 r; u8 pad2[4]; W1886V pos; };

/* 001b5250 */
struct W1886Obj {
    u8 pad[0x34]; s32 p34; u8 pad2[8]; u32 flags; s32 p44;
    inline ~W1886Obj() __attribute__((always_inline));
    static void operator delete(void*) asm("func_00105110");
};

/* 00314b90 is library code: libsupc++ unwind-pe.h read_encoded_value_with_base (gcc 3.2-ee-040921). */
typedef unsigned int W1886UnwindPtr;
typedef unsigned long W1886UnwindWord;
typedef long W1886UnwindSword;

extern "C" void func_001b4f40(W1886Obj*);
inline W1886Obj::~W1886Obj() { func_001b4f40(this); }

extern "C" {

void func_0018a670(W1886Body* a, W1886Body* b, W1886V* out);  // 0x0018a670: definition moved into src/anon/unit_00189d38.cpp

extern u32 D_0034f240;
extern f32 D_00349e10;
s32 func_001b55e8(W1886Obj*);
void func_001b5460(W1886Obj*);
void func_00185e20(s32);
s32 func_00197920(void);
void func_0016c640(s32);
void func_001b0250(s32);
s32 func_0016cd48(s32, s32);
void func_001b5588(W1886Obj*);
s32 func_001b5680(W1886Obj*);
void func_001b53b0(W1886Obj*, f32);
void func_001b5250(W1886Obj* t, u8 flag);  // 0x001b5250: definition moved into src/anon/unit_001b2780.cpp

const unsigned char* func_00314b00(const unsigned char*, W1886UnwindWord*); /* read_uleb128 */
const unsigned char* func_00314b38(const unsigned char*, W1886UnwindSword*); /* read_sleb128 */
void func_002fd160(void) __attribute__((noreturn)); /* abort */
const unsigned char* func_00314b90(unsigned char encoding, W1886UnwindPtr base, const unsigned char* p, W1886UnwindPtr* val);  // 0x00314b90: definition moved into src/libsupc++/eh_personality.cpp
}
