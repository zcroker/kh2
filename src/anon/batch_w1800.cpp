#include "../common/types.h"

struct Cc30Obj { u8 pad[0x104]; s32 action; u32 flags108; u8 pad2[0x140 - 0x10c]; u8 mot[0x28]; u32 flags168; };
struct B0a8V { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Fe8Atk { u32 x0; u32 b0 : 1; u32 b1 : 1; u32 combo : 1; bool isCombo() { return combo; } };
struct Fe8Party { u8 pad[0x108]; u32 f108; u8 pad2[0x160 - 0x10c]; u32 f160; u32 pad3; u32 f168; u8 pad4[0xb40 - 0x16c]; s32 fb40; bool chk108(u32 m) { return (f108 & m) != 0; } u32 get108(u32 m) { return f108 & m; } };

extern "C" {

/* 0017cc30 */
void func_00180c88(u8*, s32, f32);
void cc30_17f488(u8*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void cc30_push(u8*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
s32 cc30_is_exist(u8*, s32) asm("_ZN2YS6MOTION8is_existEi");
void cc30_change_action(Cc30Obj*, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void wtarget_0017cc30(u32, Cc30Obj*, u32, u32) asm("_Z16wtarget_0017cc30jjjj");
void wtarget_0017cc30(u32 a0, Cc30Obj* o, u32 act, u32 a3) {
    u8* m = o->mot;
    s32 a = o->action;
    if (a >= 0 && !(o->flags168 & 0x10)) {
        if (a != 5) {
            func_00180c88(m, a, 0.0f);
            cc30_push(m, 0, 0.0f, 0.0f, 0);
        } else if (cc30_is_exist(m, 5)) {
            cc30_17f488(m, 5, 0.0f, 0.0f);
            cc30_push(m, 0, 0.0f, 0.0f, 0);
        }
    }
    cc30_change_action(o, act);
    o->flags108 |= 0x8000000;
}

/* 001cb0a8 */
void* b0a8_current(void) asm("_ZN2Ti8MGPlayer7currentEv");
B0a8V* func_0016c028(void*);
static inline __attribute__((always_inline)) f32 b0a8_normalize(B0a8V* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline __attribute__((always_inline)) void b0a8_scale(B0a8V* v, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "f"(k) : "$8", "memory");
}
static inline __attribute__((always_inline)) void b0a8_add(B0a8V* d, B0a8V* a, B0a8V* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline __attribute__((always_inline)) void sub_B(B0a8V* a, B0a8V* b, B0a8V* d) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
bool func_001cb0a8(B0a8V* self) {
    B0a8V d;
    sub_B(self, func_0016c028(b0a8_current()), &d);
    f32 len = b0a8_normalize(&d);
    if (len < 15.0f) return 0;
    if (6.0f < len) len = 6.0f;
    b0a8_scale(&d, len);
    b0a8_add(self, self, &d);
    return 1;
}

/* 00178fe8 */
Fe8Atk* fe8_get_partyattack(Fe8Party*, s32) asm("_ZN2YS5PARTY15get_partyattackEi");
bool fe8_is_combo_finish(Fe8Party*, s32) asm("_ZN2YS5PARTY15is_combo_finishEi");
bool func_001a0920(Fe8Atk*, Fe8Party*);
bool func_00177ab8(Fe8Party*, bool);
void func_00177008(Fe8Party*, Fe8Atk*, s32);
bool func_00178fe8(Fe8Party* self, s32 i) {
    Fe8Atk* a = fe8_get_partyattack(self, i);
    if (a) {
        if (func_001a0920(a, self)) {
            if (a->isCombo() || !fe8_is_combo_finish(self, 0)) {
                if ((self->f160 & 0x400) || (self->f168 & 0x20)) {
                    if (func_00177ab8(self, self->chk108(0x2000000))) {
                        func_00177008(self, a, self->fb40 + 4);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

}
