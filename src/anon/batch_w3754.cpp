// Quaternion slerp (002e47a8). partial asm: one FP register pin on u; the rest is plain C++.
#include "../common/types.h"
extern "C" {
struct Q1987 { f32 x, y, z, w; } __attribute__((aligned(16)));
void func_002e40a8(Q1987*, Q1987*);
f32 func_002e49a8(Q1987*, Q1987*);
void func_002e44c0(Q1987*, f32);
void func_002e3f58(Q1987*);
void f2e44b8_1987(Q1987*) asm("_Z13func_002e44b8Pv");
f32 acos1987(f32) asm("_ZN3Axa15InnerProductXYZERKNS_8FVECTOR4ES2_");
f32 sinf(f32);
f32 fabsf(f32);
Q1987* func_002e47a8(Q1987* out, Q1987* a, Q1987* b, f32 tp)
{
    Q1987 q;
    f32 t; register f32 u asm("$f24"); f32 s0; f32 s; f32 s1;
    f32 c, om;
    t = tp;
    func_002e40a8(&q, b);
    if (func_002e49a8(a, &q) < 0.0f) {
        func_002e44c0(&q, -1.0f);
    }
    func_002e3f58(out);
    c = a->x * q.x + a->y * q.y + a->z * q.z + a->w * q.w;
    if (1.0f < c) c = 1.0f;
    om = acos1987(c);
    u = 1.0f - t;
    s = sinf(om);
    s0 = sinf(om * u);
    s1 = sinf(om * t);
    if (fabsf(s) < 1e-05f) {
        out->x = a->x * u + q.x * t;
        out->y = a->y * u + q.y * t;
        out->z = a->z * u + q.z * t;
        out->w = a->w * u + q.w * t;
        f2e44b8_1987(&q);
        return out;
    } else {
        s = 1.0f / s;
        out->x = (a->x * s0 + q.x * s1) * s;
        out->y = (a->y * s0 + q.y * s1) * s;
        out->z = (a->z * s0 + q.z * s1) * s;
        out->w = (a->w * s0 + q.w * s1) * s;
        f2e44b8_1987(&q);
        return out;
    }
}
}
