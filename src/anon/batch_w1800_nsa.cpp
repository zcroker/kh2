#include "../common/types.h"

struct B1a0Mgr;
struct B1a0MgrVt { u8 pad[0x28]; void (*f28)(B1a0Mgr*, s32, s32); };
struct B1a0Mgr { B1a0MgrVt* vt; };
struct B1a0Obj { f32 pos[4]; void* fn; u8 pad[0x40 - 0x14]; f32 timer; u8 pad2[0x4c - 0x44]; s32* id; };

extern "C" {

/* 001cb1a0 */
extern B1a0Mgr* D_00361f60;
extern f32 D_00349e10;
f32* func_002d1f30(B1a0Mgr*);
s32 func_001cbab0(B1a0Obj*);
void func_001ca910(B1a0Obj*);
bool func_001ca9c0(B1a0Obj*);
void func_001cb180(void);
static inline __attribute__((always_inline)) void vadd(f32* d, f32* s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s) : "memory");
}
static inline B1a0Mgr* mgr() { return D_00361f60; }
bool func_001cb1a0(B1a0Obj* self) {
    if (D_00361f60) {
        vadd(self->pos, func_002d1f30(D_00361f60));
    }
    if (self->timer <= 0.0f) {
        if (func_001cbab0(self)) {
            self->fn = (void*)func_001cb180;
            D_00361f60->vt->f28(D_00361f60, 1, *self->id);
            func_001ca910(self);
            return 1;
        }
    }
    self->timer -= D_00349e10;
    return !func_001ca9c0(self);
}

}
