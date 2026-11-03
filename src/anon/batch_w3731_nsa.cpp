// 002cbf70: empty asms keep the a2 copy to s5 after the barrier (first beqz delay slot) and keep sd s5 early.
// w2475 near-miss (build with -fno-strict-aliasing, _nsa): only the prologue differs (sched2 puts sd s2/sd s5/move s5 before swc1 f22/mov.s f22; original copies f12->f22 first and move s5,a2 sits in the first beqz delay slot). Body 0 real diffs. ce598 declared f32-returning fixed an f0/f1 choice.
#include "../common/types.h"
extern "C" {
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V2cbf70 {
    f32 x, y, z, w;
    V2cbf70() {}
    V2cbf70(const V2cbf70& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2cbf70& operator=(const V2cbf70& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2cbf70 operator-(const V2cbf70& b) const
    {
        V2cbf70 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
                     : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));

// curve path walker
struct Path2cbf70 {
    u8 pad0[4];
    s32 first;
    s32 n;
    u8 pad12[4];
    u8 loop;
    u8 pad17[7];
    f32 t0;
    f32 t;
    u8 pad32[8];
    f32 segLen;
    u8 pad44[4];
    V2cbf70 a0, a1, b0, b1, last;
    u8 pad128[4];
    u8 fwd, stop, fixed, mode;
    u8 pad136[4];
    s32 mark;
};

s32 func_002cb918(Path2cbf70*);
s32 func_002cb920(Path2cbf70*);
V2cbf70* func_002cb890(Path2cbf70*, s32);
V2cbf70 func_002cb938(Path2cbf70*, f32);
V2cbf70 func_002cd910(Path2cbf70*, f32);
f32 func_002ce598(Path2cbf70*, V2cbf70*);
void func_002cb800(Path2cbf70*, V2cbf70*);
void func_002ce6b8(Path2cbf70*, V2cbf70*, f32);
f32 func_002f8870(f32);

s32 func_002cbf70(Path2cbf70* p, V2cbf70* out, V2cbf70* pos0, f32 dist)
{
    V2cbf70* pos; asm("" : "=r"(pos));
    __typeof__(p->mode) m = p->mode;
    register V2cbf70* a asm("$6") = pos0;
    asm volatile("" : : "r"(a), "r"(m), "r"(pos));
    pos = a;
    if (m) {
        if (p->n < 2) return 0;
        if ((f32)func_002cb920(p) - 1.0f < p->t) return 0;
    } else {
        f32 t0 = p->t0;
        V2cbf70 a = func_002cd910(p, t0);
        V2cbf70 b = *pos;
        func_002ce6b8(p, pos, dist * 10.0f);
        V2cbf70 d1 = a - b;
        V2cbf70 d2 = *pos - b;
        f32 l1 = d1.length();
        f32 l2 = d2.length();
        if (func_002f8870(l2 - l1) < (l1 + l2) * 0.0001f) {
            p->t0 = t0;
            *pos = a;
        }
        p->t = p->t0;
        if (p->mark >= 0) {
            s32 it = (s32)p->t;
            if (!p->fixed) {
                if (it < p->mark) p->fwd = 1;
                else p->fwd = 0;
            }
        }
    }
    if (p->t < -1.0f) {
        func_002ce598(p, pos);
        p->t = p->t0;
    }
    if (p->mode) {
        s32 i = (s32)(p->t + 1.0f);
        if (i >= func_002cb918(p)) {
            V2cbf70* v = func_002cb890(p, i);
            p->b0 = v[0];
            p->b1 = v[1];
            p->segLen = (p->b0 - p->a0).length();
        }
    }
    p->last = *pos;
    s32 pass = 0;
    s32 done;
    do {
        done = 1;
        for (s32 k = 0; k < 20; k++) {
            V2cbf70 e = func_002cb938(p, p->t);
            {
                V2cbf70 d = e - *pos;
                d.y = 0.0f;
                if (dist < d.length()) {
                    *out = e;
                    return 1;
                }
            }
            f32 step = dist / p->segLen * 0.5f;
            s32 i;
            if (p->fwd) {
                p->t += step;
                if (!(p->a1.w + 1.0f <= p->t)) continue;
                i = (s32)(p->t + 1.0f);
                if (p->mode) {
                    if (i >= func_002cb920(p)) {
                        p->t = p->b1.w;
                        p->a0 = p->b0;
                        p->a1 = p->b1;
                        return 0;
                    }
                    if (i < func_002cb918(p)) {
                        func_002ce598(p, pos);
                        done = 0;
                        p->t = p->t0;
                        break;
                    }
                } else if (func_002cb920(p) < i) {
                    if (p->loop) {
                        i = i - func_002cb920(p) - 1;
                        i += func_002cb918(p);
                    } else if (p->stop) {
                        func_002cb800(p, pos);
                        done = 0;
                        break;
                    } else {
                        return 0;
                    }
                }
                p->t = p->b1.w;
                p->a0 = p->b0;
                p->a1 = p->b1;
                V2cbf70* v = func_002cb890(p, i);
                p->b0 = v[0];
                p->b1 = v[1];
                p->segLen = (p->b0 - p->a0).length();
            } else {
                p->t -= step;
                if (!(p->t <= p->a1.w)) continue;
                i = (s32)(p->a1.w + 0.5f) - 1;
                if (i < func_002cb918(p)) {
                    i -= func_002cb918(p);
                    i = i + func_002cb920(p) + 1;
                }
                if (p->mode) {
                    if (p->t < (f32)func_002cb918(p)) return 0;
                } else if (p->t <= (f32)func_002cb918(p)) {
                    if (p->loop) {
                        p->t = (f32)(func_002cb920(p) + 1);
                    } else if (p->stop) {
                        func_002cb800(p, pos);
                        done = 0;
                        break;
                    } else {
                        return 0;
                    }
                } else {
                    p->t = p->a1.w;
                }
                p->b0 = p->a0;
                p->b1 = p->a1;
                V2cbf70* v = func_002cb890(p, i);
                p->a0 = v[0];
                p->a1 = v[1];
                p->segLen = (p->b0 - p->a0).length();
            }
        }
        pass++;
    } while (pass < 2 && !done);
    *out = *pos;
    return 1;
}
}
