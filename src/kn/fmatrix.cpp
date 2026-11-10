#include "fmatrix.hpp"

namespace kn {

class FVector;



extern "C" f32 func_0011c050(...);  // float_bucket_index
extern "C" u32 sceVu0RotMatrixX(...);

u32 FMatrix::rotateX(f32 a1) {
    u32 s0 = (u32)this;
    if (a1 == 0.0f) return s0;
    f32 f0 = func_0011c050();  // float_bucket_index
    ((u32 (*)(f32, u32, u32))sceVu0RotMatrixX)(f0, s0, s0);
    return s0;
}

extern "C" u32 sceVu0RotMatrixY(...);
extern "C" u32 sceVu0RotMatrixZ(...);

u32 FMatrix::rotateY(f32 a1) {
    u32 s0 = (u32)this;
    if (a1 == 0.0f) return s0;
    f32 f0 = func_0011c050();  // float_bucket_index
    ((u32 (*)(f32, u32, u32))sceVu0RotMatrixY)(f0, s0, s0);
    return s0;
}

u32 FMatrix::rotateZ(f32 a1) {
    u32 s0 = (u32)this;
    if (a1 == 0.0f) return s0;
    f32 f0 = func_0011c050();  // float_bucket_index
    ((u32 (*)(f32, u32, u32))sceVu0RotMatrixZ)(f0, s0, s0);
    return s0;
}

}  // namespace kn
