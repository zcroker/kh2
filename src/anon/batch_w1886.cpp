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

void func_0018a670(W1886Body* a, W1886Body* b, W1886V* out)
{
    W1886V s;
    W1886V inv;
    W1886V d;
    inv.x = inv.z = 1.0f / (a->h + b->h);
    inv.y = 1.0f / (a->r + b->r);
    d = b->pos - a->pos;
    s = d * inv;
    f32 l = s.x * s.x + s.z * s.z;
    if (0.0f < l) {
        *out = s * ((__builtin_sqrtf((1.0f - s.y * s.y) / l) - 1.0f) * (a->h + b->h + 5.0f));
    } else {
        out->x = a->h + b->h + 5.0f;
        out->z = 0.0f;
    }
    out->y = 0.0f;
}

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
void func_001b5250(W1886Obj* t, u8 flag)
{
    if ((t->flags & 4) && func_001b55e8(t)) {
        func_001b5460(t);
        delete t;
        return;
    }
    if (!flag) {
        if (D_0034f240 & 0x20) return;
        if ((t->flags & 1) == 1) {
            func_00185e20(1);
            t->flags = (t->flags & ~1) | 2;
        } else if ((t->flags & 2) && !func_00197920()) {
            func_0016c640(1);
            t->flags &= ~2;
        }
    }
    if (t->p44) func_001b0250(t->p44);
    if (t->p34 && func_0016cd48(t->p34, 0) == 1) func_001b5588(t);
    if (func_001b5680(t)) func_001b53b0(t, D_00349e10);
}

const unsigned char* func_00314b00(const unsigned char*, W1886UnwindWord*); /* read_uleb128 */
const unsigned char* func_00314b38(const unsigned char*, W1886UnwindSword*); /* read_sleb128 */
void func_002fd160(void) __attribute__((noreturn)); /* abort */
const unsigned char* func_00314b90(unsigned char encoding, W1886UnwindPtr base, const unsigned char* p, W1886UnwindPtr* val)
{
    union unaligned {
        void* ptr;
        unsigned u2 __attribute__((mode(HI)));
        unsigned u4 __attribute__((mode(SI)));
        unsigned u8 __attribute__((mode(DI)));
        signed s2 __attribute__((mode(HI)));
        signed s4 __attribute__((mode(SI)));
        signed s8 __attribute__((mode(DI)));
    } __attribute__((__packed__));
    const union unaligned* u = (const union unaligned*)p;
    W1886UnwindPtr result;
    if (encoding == 0x50) {
        W1886UnwindPtr a = (W1886UnwindPtr)p;
        a = (a + sizeof(void*) - 1) & -sizeof(void*);
        result = *(W1886UnwindPtr*)a;
        p = (const unsigned char*)(a + sizeof(void*));
    } else {
        switch (encoding & 0x0f) {
        case 0x00:
            result = (W1886UnwindPtr)u->ptr;
            p += sizeof(void*);
            break;
        case 0x01: {
            W1886UnwindWord tmp;
            p = func_00314b00(p, &tmp);
            result = (W1886UnwindPtr)tmp;
        } break;
        case 0x09: {
            W1886UnwindSword tmp;
            p = func_00314b38(p, &tmp);
            result = (W1886UnwindPtr)tmp;
        } break;
        case 0x02:
            result = u->u2;
            p += 2;
            break;
        case 0x03:
            result = u->u4;
            p += 4;
            break;
        case 0x04:
            result = u->u8;
            p += 8;
            break;
        case 0x0a:
            result = u->s2;
            p += 2;
            break;
        case 0x0b:
            result = u->s4;
            p += 4;
            break;
        case 0x0c:
            result = u->s8;
            p += 8;
            break;
        default:
            func_002fd160();
        }
        if (result != 0) {
            if ((encoding & 0x70) != 0x10) result += base; else result += (W1886UnwindPtr)u;
            if (encoding & 0x80)
                result = *(W1886UnwindPtr*)result;
        }
    }
    *val = result;
    return p;
}
}
