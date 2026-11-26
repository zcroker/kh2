#include "../common/types.h"
// 0019e400 (built with -fno-strict-aliasing). The owner's object is read once before the
// entity loop (that gave the original's register order). "d2" is an unused local that
// reproduces the 16-byte stack gap at sp+48 (frame 224).
struct E4V {
    f32 x, y, z, w;
    E4V() {}
    E4V& operator=(const E4V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    E4V operator+(const E4V& o) const {
        E4V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    E4V operator-(const E4V& o) const {
        E4V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct E4Hit { s32 a; f32 b; s32 x8; s32 c; E4V v; E4Hit() { c = 0; } };
struct E4Tgt { u8 pad[32]; };
struct E4Obj;
struct E4Ent;
typedef E4V (*E4VFn)(E4Ent*, E4Obj*);
struct E4Ent {
    E4VFn* vt; u8 pad4[0xe0 - 4]; E4V pa; u8 padf0[0x114 - 0xf0];
    u32 f114; u32 f118; f32 f11c; f32 f120; u8 pad124[0x130 - 0x124]; E4V pb;
};
struct E4Owner { u8 pad0[0x9e0]; E4Obj* obj; };
struct E4Head { E4Owner* owner; };
struct E4Self { E4Head* head; u8 pad4[0x2c]; E4Hit hit; };
struct E4Prm { u16 id; };
extern "C" {
void func_00190128(E4Tgt*);
E4Ent* func_0018ee28(E4Ent*);
E4Prm* YS__RC_SEARCHER__get_command_elem(E4Self*, u32);
void e4_make(E4Hit*, s32, f32, f32) asm("_ZN2YS9COLLISION4makeEiff");
s32 func_0018a550(E4Hit*, E4Hit*);
void func_001908c0(E4Tgt*, E4Ent*, u32);
E4V func_00190388(E4Tgt*);
s32 e4_draw(E4Self*, E4Prm*) asm("_ZN2YS9COLLISION4drawEji");
s32 YS__RC_SEARCHER__get_dist(E4Self*, E4Prm*, E4Tgt*, const E4V&, s32);
s32 YS__RC_SEARCHER__check_set(E4Self*, s32, E4Tgt*, s32, s32);
void YS__RC_SEARCHER__check_magic(E4Self* self);  // 0x0019e400: definition moved into src/anon/unit_0019ba60.cpp
}
