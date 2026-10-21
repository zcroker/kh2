#include "../common/types.h"

struct W1835Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1835Spark { W1835Vec pos; f32 lo; f32 val; f32 ang; s32 zero; s32 n; };

struct W1835VObj;
struct W1835VTbl { u8 pad[0x20]; void (*release)(W1835VObj*); };
struct W1835VObj { W1835VTbl* vt; };
struct W1835Slot { W1835VObj* p; s16 b; s16 a; };
struct W1835Req { u8 pad[4]; s16 id; s16 a; s16 b; s16 mode; };

extern "C" {
extern u32 D_003638d0;
extern s32 D_003509a0;
extern W1835Slot D_01dad9c0[32];
s32 func_002282f0(s16);
s32 func_00225b00(s16);
W1835VObj* func_001050d8(s32);
void func_001ac8b0(W1835VObj*, s16);
void func_001ac7c8(W1835VObj*, W1835VObj*);

/* lq/sq 128-bit copy: no C equivalent with this register. */
static inline void W1835Copy(W1835Vec* d, const W1835Vec* s)
{
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 W1835Rnd()
{
    D_003638d0 *= 0x10dcd;
    return (f32)D_003638d0 * 2.3283064365386963e-10f;
}
static inline f32 W1835RandF(f32 r) __attribute__((always_inline));
static inline f32 W1835RandF(f32 r) { return W1835Rnd() * r; }

void func_001a7a48(W1835Spark* s, W1835Vec* v, f32 lo, f32 hi, s32 n) {
    W1835Copy(&s->pos, v);
    s->lo = lo;
    s->val = lo + W1835Rnd() * (hi - lo);
    s->n = n;
    s->zero = 0;
    f32 k = 0.78539818525f;
    s->ang = (f32)(((D_003509a0 & 4) >> 2) | (D_003509a0 << 1)) * k + W1835RandF(k);
    D_003509a0 = (D_003509a0 + 1) % 8;
}

void func_0022d880(W1835Req* a) {
    s32 i;
    if (func_002282f0(a->id) != 0) return;
    if (func_00225b00(a->id) != 0) return;
    if (a->mode == 0) {
        for (i = 0; i < 32; i++) {
            W1835Slot* s = &D_01dad9c0[i];
            if (s->p == 0) {
                s16 v = a->b;
                W1835VObj* o = func_001050d8(0x84);
                func_001ac8b0(o, v);
                func_001ac7c8(func_001050d8(0x1c), o);
                s->p = o;
                s->a = a->a;
                s->b = a->b;
                return;
            }
        }
    } else {
        for (i = 0; i < 32; i++) {
            W1835Slot* s = &D_01dad9c0[i];
            if (s->p != 0 && s->a == a->a && s->b == a->b) {
                s->p->vt->release(s->p);
                s->p = 0;
                return;
            }
        }
    }
}

}
