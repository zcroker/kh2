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
Q1987* func_002e47a8(Q1987* out, Q1987* a, Q1987* b, f32 tp);  // 0x002e47a8: definition moved into src/anon/unit_002e3f58.cpp
}
