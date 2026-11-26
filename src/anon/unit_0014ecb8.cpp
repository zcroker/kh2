// Linked unit 0x0014ecb8-0x00153158 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../harata/libdk/information.hpp"
inline void* operator new(unsigned int, void* p) { return p; }
inline void* operator new[](unsigned int, void* p) { return p; }

// 0014ecb8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014ecb8 {
extern u8 D_0034a400 asm("D_0034a400");
extern u8 D_0034a408 asm("D_0034a408");
/*TARGET 0014ecb8*/
void func_0014ecb8() asm("_Z13func_0014ecb8v");
void func_0014ecb8() {
    *(u32*)((u32)&D_0034a400 + (s32)(0)) = 0u;
    u32 t6 = (u32)&D_0034a408;
    s32 t7 = 7;
    do {
        *(u32*)((u32)t6 + (s32)(0)) = (u32)-1;
        t7 = (s32)(t7 + (-1));
        t6 = (u32)((s32)t6 + (4));
    } while (t7 >= 0);
}
}  // namespace n0014ecb8

// 0014ecf8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014ecf8 {
u32 func_001aec40(...) asm("func_001aec40");
/*TARGET 0014ecf8*/
// get_global_1c9408c

u32 func_0014ecf8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0014ecf8jjjjjjjj");
// get_global_1c9408c

u32 func_0014ecf8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001aec40)();
    r15 = 0u;
    if (r2 != 0u) {
        r15 = (u32)(s32)(*(s16*)((u32)r2 + (s32)(10)));
    }
    r2 = r15;
    return r2;
}
}  // namespace n0014ecf8

// 0014ed28 (was src/anon/batch_w59.cpp)
namespace n0014ed28 {
// 0x00141850: definition moved into src/anon/unit_00141458.cpp

// --- 0014ed28
u32 func_0014ecf8(u32) asm("func_0014ecf8");
u32 func_00136958(void) asm("func_00136958");
u32 func_002bc2e8(u32, u32, u32) asm("func_002bc2e8");
extern s32 D_0034a400 asm("D_0034a400");
extern u32 D_0034a408[] asm("D_0034a408");
/*TARGET 0014ed28*/
void func_0014ed28(u32 a, u32 b) asm("func_0014ed28");
void func_0014ed28(u32 a, u32 b) {
    u32 r = func_0014ecf8(a);
    if (r) {
        u32 x = func_00136958();
        D_0034a408[D_0034a400] = func_002bc2e8(r, x, b);
        D_0034a400++;
    }
}
}  // namespace n0014ed28

// 0014eda8 (was src/anon/batch_w60.cpp)
namespace n0014eda8 {
extern s32 D_0034a400 asm("D_0034a400");
extern s32 D_0034a408[] asm("D_0034a408");
void func_002bc358(s32, s32) asm("func_002bc358");
/*TARGET 0014eda8*/
// 0x00143fc8: definition moved into src/anon/unit_00142c90.cpp

void func_0014eda8(void) asm("func_0014eda8");
// 0x00143fc8: definition moved into src/anon/unit_00142c90.cpp

void func_0014eda8(void) {
    s32 i;
    for (i = 0; i < D_0034a400; i++) {
        s32 v = D_0034a408[i];
        if (v != -1) func_002bc358(v, 1);
    }
}
}  // namespace n0014eda8

// 0014ee28 (was src/anon/batch_w111.cpp)
namespace n0014ee28 {
struct Vq14 {
    f32 x, y, z, w;
    Vq14& operator=(const Vq14& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Sph14 { Vq14 c; f32 r; };
struct Pts14 { Vq14* v[4]; s32 n; };
static inline f32 DistSq14(const void* a, const void* b) {
    f32 d;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.xyzw $vf5, $vf6, $vf4\n\tvmove.xyzw $vf4, $vf5\n\t"
                 "vmul.xyz $vf5, $vf4, $vf5\n\tvaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0"
                 : "=f"(d) : "r"(a), "r"(b) : "$2");
    return d;
}
void* func_00106a60(s32) asm("func_00106a60");
// buffer_get_by_index
void func_00107368(void*, Vq14*) asm("func_00107368");
// vec_copy_at80_if_diff
Vq14* func_00143ec8(u16) asm("func_00143ec8");
Pts14* func_00143ea8(u16) asm("func_00143ea8");
s32 func_00162b68(Sph14*, Vq14*, f32*) asm("func_00162b68");
s32 func_00162bb0(Sph14*, Pts14*, Vq14*, f32*, Vq14*) asm("func_00162bb0");
s32 func_00162c28(Sph14*, Pts14*, Vq14*) asm("func_00162c28");
s32 func_00163168(Sph14*, Pts14*, Vq14*) asm("func_00163168");
/*TARGET 0014ee28*/
// Picks the point of object `id` nearest the camera (within 5000 units); *direct tells whether it was a direct hit.
s32 func_0014ee28(s32 id, Vq14* out, u8* direct) asm("func_0014ee28");
// Picks the point of object `id` nearest the camera (within 5000 units); *direct tells whether it was a direct hit.
s32 func_0014ee28(s32 id, Vq14* out, u8* direct)
{
    Vq14 cam;
    Vq14 hit;
    Sph14 s;
    Vq14 dir;
    Pts14 pts;
    Vq14 alt;
    f32 t;
    func_00107368(func_00106a60(0), &cam);  // vec_copy_at80_if_diff
    s.c = cam;
    s.r = 5000.0f;
    dir = *func_00143ec8(id);
    pts = *func_00143ea8(id);
    if (func_00162b68(&s, &dir, &t)) {
        if (func_00162bb0(&s, &pts, &dir, &t, &hit)) {
            *direct = 1;
            *out = hit;
            return 1;
        }
    }
    f32 d2 = 0.0f;
    if (func_00162c28(&s, &pts, &hit)) {
        f32 d1 = DistSq14(&cam, &hit);
        if (func_00163168(&s, &pts, &alt)) d2 = DistSq14(&cam, &alt);
        if (d2 < d1) { *direct = 0; *out = alt; }
        else { *direct = 0; *out = hit; }
        return 1;
    }
    return 0;
}
}  // namespace n0014ee28

// 0014f030 (was src/anon/batch_w204.cpp)
namespace n0014f030 {
/*TARGET 0014f030*/
void func_0014f030(float* p, float a, float b, float c) asm("func_0014f030");
void func_0014f030(float* p, float a, float b, float c) {  // obj_set_lerp_params
    if (c == 0.0f) c = 1.0f;
    float d = (b - a) / c;
    p[0] = a; p[2] = b; p[1] = d;
}
}  // namespace n0014f030

// 0014f068 (was src/anon/batch_w28.cpp)
namespace n0014f068 {
/*TARGET 0014f068*/
// 0x00138140: definition moved into src/anon/unit_001374c8.cpp

// 0014b468: moved to src/anon/unit_0014b150.cpp

// 0014db78: moved to src/anon/unit_0014d680.cpp

// Clamp p[0] towards p[2] in the direction of p[1]; returns 0 once clamped.
u32 func_0014f068(f32* p) asm("func_0014f068");
// 0x00138140: definition moved into src/anon/unit_001374c8.cpp

// 0014b468: moved to src/anon/unit_0014b150.cpp

// 0014db78: moved to src/anon/unit_0014d680.cpp

// Clamp p[0] towards p[2] in the direction of p[1]; returns 0 once clamped.
u32 func_0014f068(f32* p) {
    if (p[1] >= 0.0f) {
        if (p[2] <= p[0]) { p[0] = p[2]; return 0; }
    } else {
        if (p[0] <= p[2]) { p[0] = p[2]; return 0; }
    }
    return 1;
}
}  // namespace n0014f068

// 0014f0b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014f0b0 {
u32 func_0014f068(u32) asm("_Z13func_0014f068j");
/*TARGET 0014f0b0*/
u32 func_0014f0b0(u32 a0) asm("func_0014f0b0");
u32 func_0014f0b0(u32 a0) {
    f32 f1 = *(f32*)((u32)a0 + (s32)(0));
    f32 f0 = *(f32*)((u32)a0 + (s32)(4));
    f0 = (f32)(f0 + f0);
    f1 = (f32)(f1 + f0);
    *(f32*)((u32)a0 + (s32)(0)) = f1;
    u32 (*fp)(u32) = func_0014f068;
    u32 v0 = fp(a0);
    return v0;
}
}  // namespace n0014f0b0

// 0014f0e0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014f0e0 {
u32 func_0014f068(u32) asm("_Z13func_0014f068j");
/*TARGET 0014f0e0*/
u32 func_0014f0e0(u32 a0) asm("_Z13func_0014f0e0j");
u32 func_0014f0e0(u32 a0) {
    f32 f1 = *(f32*)((u32)a0 + (s32)(0));
    u32 t7 = (u32)(0x0035u << 16);
    f32 f2 = *(f32*)((u32)t7 + (s32)(-25072));
    f32 f0 = *(f32*)((u32)a0 + (s32)(4));
    f0 = (f32)(f0 * f2);
    f1 = (f32)(f1 + f0);
    *(f32*)((u32)a0 + (s32)(0)) = f1;
    u32 (*fp)(u32) = func_0014f068;
    u32 v0 = fp(a0);
    return v0;
}
}  // namespace n0014f0e0

// 0014f118 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n0014f118 {
u32 func_00137fb8() asm("_Z13func_00137fb8v");
u32 func_0013e688() asm("_Z13func_0013e688v");
u32 func_0015b770() asm("_Z13func_0015b770v");
u32 func_00152f40() asm("_Z13func_00152f40v");
/*TARGET 0014f118*/
// 0x00138620: definition moved into src/anon/unit_00138480.cpp

u32 func_0014f118(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f118jjjj");
// 0x00138620: definition moved into src/anon/unit_00138480.cpp

u32 func_0014f118(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0015b770)() = func_0015b770;
    r2 = fp_call0_0015b770();
    u32 (*fp_call0_0013e688)() = func_0013e688;
    r2 = fp_call0_0013e688();
    u32 (*fp_call0_00137fb8)() = func_00137fb8;
    r2 = fp_call0_00137fb8();
    return func_00152f40();
}
}  // namespace n0014f118

// 0014f148 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014f148 {
// 00136cf0: moved to src/harata/libdk/bgm.cpp

void func_001380e8(void) asm("_Z13func_001380e8v");
u32 func_0013e808(...) asm("func_0013e808");
u32 func_00153100(...) asm("func_00153100");
u32 func_0015b778(...) asm("func_0015b778");
/*TARGET 0014f148*/
void func_0014f148() asm("_Z13func_0014f148v");
void func_0014f148() {
    func_00153100();
    func_001380e8();
    func_0013e808();
    func_0015b778();
}
}  // namespace n0014f148

// 0014f178 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n0014f178 {
u32 func_00153140() asm("_Z13func_00153140v");
u32 func_0015b780() asm("_Z13func_0015b780v");
u32 func_00138128() asm("_Z13func_00138128v");
u32 func_0014f178() asm("_Z13func_0014f178jjjj");
/*TARGET 0014f178*/
u32 func_0014f178(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f178jjjj");
u32 func_0014f178(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0015b780)() = func_0015b780;
    r2 = fp_call0_0015b780();
    u32 (*fp_call0_00153140)() = func_00153140;
    r2 = fp_call0_00153140();
    return func_00138128();
}
}  // namespace n0014f178

// 0014f1a0 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n0014f1a0 {
u32 func_00153158() asm("_Z13func_00153158v");
u32 func_0015b7a0() asm("_Z13func_0015b7a0v");
u32 func_00138140() asm("_Z13func_00138140v");
u32 func_0014f1a0() asm("_Z13func_0014f1a0jjjj");
/*TARGET 0014f1a0*/
u32 func_0014f1a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f1a0jjjj");
u32 func_0014f1a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0015b7a0)() = func_0015b7a0;
    r2 = fp_call0_0015b7a0();
    u32 (*fp_call0_00153158)() = func_00153158;
    r2 = fp_call0_00153158();
    return func_00138140();
}
}  // namespace n0014f1a0

// 0014f1c8 (was src/anon/tiny_wrappers_more.cpp)
namespace n0014f1c8 {
u32 func_0015af48(u32, u32, u32, u32) asm("_Z13func_0015af48jjjj");
/*TARGET 0014f1c8*/
// 0014d640: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_0014d298.cpp

// 0014e620: moved to src/harata/libdk/fpscamera.cpp

// 0014ec98: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/fpscamera.cpp

u32 func_0014f1c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f1c8jjjj");
// 0014d640: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_0014d298.cpp

// 0014e620: moved to src/harata/libdk/fpscamera.cpp

// 0014ec98: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/fpscamera.cpp

u32 func_0014f1c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0015af48(a0, a1, a2, a3);
}
}  // namespace n0014f1c8

// 0014f1e0 (was src/anon/tiny.cpp)
namespace n0014f1e0 {
void func_0015b100(void*) asm("_Z13func_0015b100Pv");
/*TARGET 0014f1e0*/
// 001491c0: moved to src/harata/libdk/mapfile.cpp
void func_0014f1e0(BD_VALUE* bd) asm("_Z13func_0014f1e0P8BD_VALUE");
// 001491c0: moved to src/harata/libdk/mapfile.cpp
void func_0014f1e0(BD_VALUE* bd) { func_0015b100(bd); }
}  // namespace n0014f1e0

// 0014f1f8 (was src/anon/misc_1.cpp)
namespace n0014f1f8 {
/*TARGET 0014f1f8*/
// 0014dd10: moved to src/anon/unit_0014d680.cpp

void func_0014f1f8(void* self) asm("_Z13func_0014f1f8Pv");
// 0014dd10: moved to src/anon/unit_0014d680.cpp

void func_0014f1f8(void* self) {}
}  // namespace n0014f1f8

// 0014f200 (was src/anon/misc_1.cpp)
namespace n0014f200 {
/*TARGET 0014f200*/
void func_0014f200(void* self) asm("_Z13func_0014f200Pv");
void func_0014f200(void* self) {}
}  // namespace n0014f200

// 0014f208 (was src/anon/tiny.cpp)
namespace n0014f208 {
void func_0014f300(void*) asm("_Z13func_0014f300Pv");
/*TARGET 0014f208*/
void func_0014f208(BD_VALUE* bd) asm("_Z13func_0014f208P8BD_VALUE");
void func_0014f208(BD_VALUE* bd) { func_0014f300(bd); }
}  // namespace n0014f208

// 0014f220 (was src/anon/tiny.cpp)
namespace n0014f220 {
void func_0014f428(void*) asm("_Z13func_0014f428Pv");
/*TARGET 0014f220*/
void func_0014f220(BD_VALUE* bd) asm("_Z13func_0014f220P8BD_VALUE");
void func_0014f220(BD_VALUE* bd) { func_0014f428(bd); }
}  // namespace n0014f220

// 0014f238 (was src/anon/tiny.cpp)
namespace n0014f238 {
void func_0014f4d8(void*) asm("_Z13func_0014f4d8Pv");
/*TARGET 0014f238*/
void func_0014f238(BD_VALUE* bd) asm("_Z13func_0014f238P8BD_VALUE");
void func_0014f238(BD_VALUE* bd) { func_0014f4d8(bd); }
}  // namespace n0014f238

// 0014f250 (was src/anon/tiny.cpp)
namespace n0014f250 {
void func_0014f528(void*) asm("_Z13func_0014f528Pv");
/*TARGET 0014f250*/
void func_0014f250(BD_VALUE* bd) asm("_Z13func_0014f250P8BD_VALUE");
void func_0014f250(BD_VALUE* bd) { func_0014f528(bd); }
}  // namespace n0014f250

// 0014f268 (was src/anon/tiny_jal_tail_wrappers.cpp)
namespace n0014f268 {
// zero_global_byte_b
u32 func_0015c0f8() asm("_Z13func_0015c0f8v");
u32 func_0013d820() asm("_Z13func_0013d820v");
/*TARGET 0014f268*/
// 0013a6d0: moved to src/harata/libdk/field2dd.cpp

u32 func_0014f268(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f268jjjj");
// 0013a6d0: moved to src/harata/libdk/field2dd.cpp

u32 func_0014f268(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_0015c0f8();
    return func_0013d820();
}
}  // namespace n0014f268

// 0014f288 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n0014f288 {
u32 func_0013b458() asm("_Z13func_0013b458v");
u32 func_0013d9e0() asm("_Z13func_0013d9e0v");
u32 func_0015c1b0() asm("_Z13func_0015c1b0v");
/*TARGET 0014f288*/
u32 func_0014f288(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f288jjjj");
u32 func_0014f288(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0013d9e0)() = func_0013d9e0;
    r2 = fp_call0_0013d9e0();
    u32 (*fp_call0_0013b458)() = func_0013b458;
    r2 = fp_call0_0013b458();
    return func_0015c1b0();
}
}  // namespace n0014f288

// 0014f2b0 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n0014f2b0 {
u32 func_0013b4b0() asm("_Z13func_0013b4b0v");
u32 func_0013daf8() asm("_Z13func_0013daf8v");
u32 func_0014f2b0() asm("_Z13func_0014f2b0jjjj");
u32 func_0015c1f0() asm("_Z13func_0015c1f0v");
/*TARGET 0014f2b0*/
u32 func_0014f2b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f2b0jjjj");
u32 func_0014f2b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0013daf8)() = func_0013daf8;
    r2 = fp_call0_0013daf8();
    u32 (*fp_call0_0013b4b0)() = func_0013b4b0;
    r2 = fp_call0_0013b4b0();
    return func_0015c1f0();
}
}  // namespace n0014f2b0

// 0014f2d8 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n0014f2d8 {
u32 func_0013b508() asm("_Z13func_0013b508v");
u32 func_0013db60() asm("_Z13func_0013db60v");
u32 func_0014f2d8() asm("_Z13func_0014f2d8jjjj");
u32 func_0015c210() asm("_Z13func_0015c210v");
/*TARGET 0014f2d8*/
u32 func_0014f2d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f2d8jjjj");
u32 func_0014f2d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0013db60)() = func_0013db60;
    r2 = fp_call0_0013db60();
    u32 (*fp_call0_0013b508)() = func_0013b508;
    r2 = fp_call0_0013b508();
    return func_0015c210();
}
}  // namespace n0014f2d8

// 0014f300 (was src/anon/batch_w3710_nsa.cpp)
namespace n0014f300 {
struct Heap;
struct HeapVT { void* (*alloc)(Heap*, u32, s32); };
struct Heap { HeapVT* vt; };
struct Sys { u8 pad[0x14]; Heap* heap; };
extern void* D_0034a428 asm("D_0034a428");
extern void* D_0034a42c asm("D_0034a42c");
extern void* D_0034a430 asm("D_0034a430");
extern void* D_0034a434 asm("D_0034a434");
extern u8 D_0034a568[] asm("D_0034a568");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
void func_0014fba0(void*) asm("func_0014fba0");
void func_0031bd98(void*) asm("func_0031bd98");
void func_0031be70(void*) asm("func_0031be70");
void func_0031a838(void*) asm("func_0031a838");
void func_00239700(void*) asm("func_00239700");
void func_0031bed8(void*) asm("func_0031bed8");
void func_0031bf50(void*) asm("func_0031bf50");
// System heap: Sys at 0x347f80 (= hi 0x340000 + 0x7f80), heap->vt->alloc(heap, size, 0).
static inline void* halloc1(u8* b, u32 n) { register Sys* s asm("$14") = *(Sys**)(b + 0x7f80); return s->heap->vt->alloc(s->heap, n, 0); }
static inline void* halloc(u8* b, u32 n) { Sys* s = *(Sys**)(b + 0x7f80); return s->heap->vt->alloc(s->heap, n, 0); }
/*TARGET 0014f300*/
void func_0014f300(void* a0) asm("_Z13func_0014f300Pv");
void func_0014f300(void* a0) {
    func_0014fba0(a0);
    u8* b = (u8*)0x340000;
    asm("" : "+r"(b));
    void* p = halloc1(b, 0x19b0);
    func_0031bd98(p);
    D_0034a428 = p;
    u8* q = (u8*)halloc(b, 0x3e0);
    *(s32*)(q + 0xc) = 0;
    *(void**)q = D_0034a568;
    func_0031be70(q + 0x30);
    *(void**)(q + 0x230) = D_00347f98;
    func_0031a838(q + 0x23c);
    *(void**)(q + 0x230) = D_00347e60;
    func_00239700(q + 0x248);
    *(s32*)(q + 0x3cc) = 0;
    D_0034a42c = q;
    p = halloc(b, 0xb54);
    func_0031bed8(p);
    D_0034a430 = p;
    p = halloc(b, 0xb54);
    func_0031bf50(p);
    D_0034a434 = p;
}
}  // namespace n0014f300

// 0014f428 (was src/anon/batch_w67.cpp)
namespace n0014f428 {
typedef void (*VFn)(void*);
extern void* D_0034a434 asm("D_0034a434");
extern void* D_0034a430 asm("D_0034a430");
extern void* D_0034a42c asm("D_0034a42c");
extern void* D_0034a428 asm("D_0034a428");
#define RELEASE_GLOBAL(g) if (g) { (*(VFn*)(*(u8**)g + 16))(g); g = 0; }
/*TARGET 0014f428*/
// 0014f428: release four global objects
void func_0014f428(void*) asm("_Z13func_0014f428Pv");
// 0014f428: release four global objects
void func_0014f428(void*)
{
    RELEASE_GLOBAL(D_0034a434);
    RELEASE_GLOBAL(D_0034a430);
    RELEASE_GLOBAL(D_0034a42c);
    RELEASE_GLOBAL(D_0034a428);
}
}  // namespace n0014f428

// 0014f4d8 (was src/anon/batch_w29.cpp)
namespace n0014f4d8 {
void func_00139858(u32) asm("func_00139858");
void func_00139ab0(u32) asm("func_00139ab0");
/*TARGET 0014f4d8*/
void func_0014f4d8(void) asm("func_0014f4d8");
void func_0014f4d8(void) {
    func_00139858(7);
    func_00139858(9);
    func_00139858(8);
    func_00139858(10);
    func_00139ab0(7);
    func_00139ab0(9);
    func_00139ab0(8);
    func_00139ab0(10);
}
}  // namespace n0014f4d8

// 0014f528 (was src/anon/batch_w30.cpp)
namespace n0014f528 {
void func_001398d0(s32) asm("func_001398d0");
void func_00139a38(s32) asm("func_00139a38");
/*TARGET 0014f528*/
void func_0014f528(void) asm("func_0014f528");
void func_0014f528(void) {
    func_001398d0(7);
    func_001398d0(9);
    func_001398d0(8);
    func_001398d0(10);
    func_00139a38(7);
    func_00139a38(9);
    func_00139a38(8);
    func_00139a38(10);
}
}  // namespace n0014f528

// 0014f578 (was src/anon/batch_w31.cpp)
namespace n0014f578 {
extern void* D_0034a42c asm("D_0034a42c");
int func_00150bc0(void*) asm("func_00150bc0");
void func_00150940(void*, u32) asm("func_00150940");
void func_001507b8(void*, u32) asm("func_001507b8");
/*TARGET 0014f578*/
// 0014a138: moved to src/anon/unit_00149fa8.cpp

void func_0014f578(u32 a) asm("func_0014f578");
// 0014a138: moved to src/anon/unit_00149fa8.cpp

void func_0014f578(u32 a) {
    if (func_00150bc0(D_0034a42c)) {
        func_00150940(D_0034a42c, a);
    } else {
        func_001507b8(D_0034a42c, a);
    }
}
}  // namespace n0014f578

// 0014f5d0 (was src/anon/batch_w48.cpp)
namespace n0014f5d0 {
// vec_copy_at416_if_diff
s32 func_00139d78(void*) asm("func_00139d78");
// 0x00144060: definition moved into src/anon/unit_00142c90.cpp

s32 func_00150bc0(void*) asm("func_00150bc0");
s32 func_00150be0(void*) asm("func_00150be0");
void func_00150b68(void*) asm("func_00150b68");
extern void* D_0034a42c asm("D_0034a42c");
/*TARGET 0014f5d0*/
void func_0014f5d0(s32 id) asm("func_0014f5d0");
void func_0014f5d0(s32 id) {
    if (!func_00150bc0(D_0034a42c)) return;
    if (id != 0 && func_00150be0(D_0034a42c) != id) return;
    if (!func_00139d78(D_0034a42c)) return;
    func_00150b68(D_0034a42c);
}
}  // namespace n0014f5d0

// 0014f648 (was src/anon/tiny_wrappers_imp.cpp)
namespace n0014f648 {
u32 func_001521c8(u32, u32, u32, u32) asm("_Z13func_001521c8jjjj");
/*TARGET 0014f648*/
u32 func_0014f648(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f648jjjj");
u32 func_0014f648(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r5 = r4;
    r15 = (u32)(0x0035u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(-23504));
    return func_001521c8(r4, r5, r6, r7);
}
}  // namespace n0014f648

// 0014f668 (was src/anon/tiny_wrappers_imp.cpp)
namespace n0014f668 {
u32 func_00151df0(u32, u32, u32, u32) asm("_Z13func_00151df0jjjj");
/*TARGET 0014f668*/
u32 func_0014f668(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f668jjjj");
u32 func_0014f668(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r5 = r4;
    r15 = (u32)(0x0035u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(-23500));
    return func_00151df0(r4, r5, r6, r7);
}
}  // namespace n0014f668

// 0014f688 (was src/anon/batch_w19.cpp)
namespace n0014f688 {
void func_00150dc0(u32, u32, u32, u32, u32, u32) asm("func_00150dc0");
extern u32 D_0034a428 asm("D_0034a428");
/*TARGET 0014f688*/
// 0x0013f160: definition moved into src/anon/unit_0013ef70.cpp

void func_0014f688(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_0014f688");
// 0x0013f160: definition moved into src/anon/unit_0013ef70.cpp

void func_0014f688(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_00150dc0(D_0034a428, a, b, c, d, e);
}
}  // namespace n0014f688

// 0014f6c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014f6c8 {
u32 func_00139d78(...) asm("func_00139d78");
u32 func_00151528(...) asm("func_00151528");
extern u8 D_0034a428 asm("D_0034a428");
/*TARGET 0014f6c8*/
void func_0014f6c8() asm("_Z13func_0014f6c8v");
void func_0014f6c8() {
    if (func_00139d78(*(u32*)((u32)&D_0034a428 + (s32)(0))) == 0u) {
        return;
    }
    func_00151528(*(u32*)((u32)&D_0034a428 + (s32)(0)));
}
}  // namespace n0014f6c8

// 0014f708 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014f708 {
u32 func_00139d78(...) asm("func_00139d78");
u32 func_001514b0(...) asm("func_001514b0");
extern u8 D_0034a428 asm("D_0034a428");
/*TARGET 0014f708*/
void func_0014f708() asm("_Z13func_0014f708v");
void func_0014f708() {
    if (func_00139d78(*(u32*)((u32)&D_0034a428 + (s32)(0))) == 0u) {
        return;
    }
    func_001514b0(*(u32*)((u32)&D_0034a428 + (s32)(0)));
}
}  // namespace n0014f708

// 0014f748 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014f748 {
u32 func_00139d78(...) asm("func_00139d78");
u32 func_001515b0(...) asm("func_001515b0");
extern u8 D_0034a428 asm("D_0034a428");
/*TARGET 0014f748*/
void func_0014f748() asm("_Z13func_0014f748v");
void func_0014f748() {
    if (func_00139d78(*(u32*)((u32)&D_0034a428 + (s32)(0))) == 0u) {
        return;
    }
    func_001515b0(*(u32*)((u32)&D_0034a428 + (s32)(0)));
}
}  // namespace n0014f748

// 0014f788 (was src/anon/auto80_199_queue.cpp)
namespace n0014f788 {
/*TARGET 0014f788*/
// 001491d8: moved to src/harata/libdk/mapfile.cpp

// 0014ddb0: moved to src/anon/unit_0014d680.cpp

u32 func_0014f788(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("_Z13func_0014f788jjjjj");
// 001491d8: moved to src/harata/libdk/mapfile.cpp

// 0014ddb0: moved to src/anon/unit_0014d680.cpp

u32 func_0014f788(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 b34 = 0x00340000;
    u32 s1 = a4;
    u32 s2 = a1;
    u32 s3 = a2;
    u32 s4 = a3;
    u32 s5 = a0;

    u32 t = *(u32*)(b34 + 32640);
    u32 obj = *(u32*)(t + 20);
    u32 fn = *(u32*)(*(u32*)obj + 0);
    u32 s0 = ((u32 (*)(u32, u32, u32))fn)(obj, 6576, 0);
    func_0031bd98(s0);
    func_00150de0(s0, s5, s2, s3, s4, s1);
    return s0;
}
}  // namespace n0014f788

// 0014f830 (was src/anon/batch_w15.cpp)
namespace n0014f830 {
// 0x00142900: definition moved into src/anon/unit_00141458.cpp

int func_00139d78(void*) asm("func_00139d78");
void func_00151528(void*) asm("func_00151528");
/*TARGET 0014f830*/
void func_0014f830(void* p) asm("func_0014f830");
void func_0014f830(void* p) {
    if (func_00139d78(p)) func_00151528(p);
}
}  // namespace n0014f830

// 0014f870 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0014f870 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 0014f870*/
// 0014b208: moved to src/anon/unit_0014b150.cpp

u32 func_0014f870(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f870jjjj");
// 0014b208: moved to src/anon/unit_0014b150.cpp

u32 func_0014f870(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0014f870

// 0014f890 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014f890 {
u32 func_00139d78(...) asm("func_00139d78");
u32 func_001515b0(...) asm("func_001515b0");
/*TARGET 0014f890*/
void func_0014f890(u32 a0) asm("_Z13func_0014f890j");
void func_0014f890(u32 a0) {
    if (func_00139d78(a0) == 0u) {
        return;
    }
    func_001515b0(a0);
}
}  // namespace n0014f890

// 0014f8d0 (was src/anon/batch_w82.cpp)
namespace n0014f8d0 {
struct Alloc0014 { struct VT { void* (*alloc)(void*, u32, u32); }* vt; };
struct Mgr0014 { u8 pad[20]; Alloc0014* heap; };
extern Mgr0014* D_00347f80 asm("D_00347f80");
void func_0031bc58(void*) asm("func_0031bc58");
void func_0014fe00(void*, u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0014fe00");
/*TARGET 0014f8d0*/
// 0x0013fdf0: definition moved into src/anon/unit_0013fca8.cpp

// Allocates a 6192-byte object from the global heap and constructs it.
void* func_0014f8d0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) asm("func_0014f8d0");
// 0x0013fdf0: definition moved into src/anon/unit_0013fca8.cpp

// Allocates a 6192-byte object from the global heap and constructs it.
void* func_0014f8d0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h)
{
    Alloc0014* hp = D_00347f80->heap;
    void* p = hp->vt->alloc(hp, 6192, 0);
    func_0031bc58(p);
    func_0014fe00(p, a, b, c, d, e, f, g, h);
    return p;
}
}  // namespace n0014f8d0

// 0014f9a8 (was src/anon/batch_w16.cpp)
namespace n0014f9a8 {
u32 func_00139d78(void*) asm("func_00139d78");
void func_00150678(void*) asm("func_00150678");
/*TARGET 0014f9a8*/
void func_0014f9a8(void* p) asm("func_0014f9a8");
void func_0014f9a8(void* p) {
    if (func_00139d78(p)) func_00150678(p);
}
}  // namespace n0014f9a8

// 0014f9e8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0014f9e8 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 0014f9e8*/
u32 func_0014f9e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014f9e8jjjj");
u32 func_0014f9e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0014f9e8

// 0014fa08 (was src/anon/batch_w17.cpp)
namespace n0014fa08 {
void forceLeaveCounter(void* c) asm("_ZN2dk11INFORMATION17forceLeaveCounterEPNS_7COUNTERE");
u32 func_00139d78(void*) asm("func_00139d78");
void func_001506e0(void*) asm("func_001506e0");
/*TARGET 0014fa08*/
void forceLeaveCounter(void* c) asm("_ZN2dk11INFORMATION17forceLeaveCounterEPNS_7COUNTERE");
void forceLeaveCounter(void* c) {
    if (func_00139d78(c)) func_001506e0(c);
}
}  // namespace n0014fa08

// 0014fa48 (was src/anon/batch_w8026.c)
namespace n0014fa48 {
struct A1Vt { void* (*alloc)(struct A1Obj*, s32, s32); };
struct A1Obj { struct A1Vt* vt; };
struct A1Mgr { u8 pad[0x14]; struct A1Obj* heap; };
extern struct A1Mgr* D_00347f80 asm("D_00347f80");
void func_0031bcf8(void*) asm("func_0031bcf8");
void func_001516b0(void*, s32, s32, s32, f32, s32, s32) asm("func_001516b0");
/*TARGET 0014fa48*/
void* func_0014fa48(s32 a, s32 b, s32 c, f32 f, s32 d, s32 e) asm("func_0014fa48");
void* func_0014fa48(s32 a, s32 b, s32 c, f32 f, s32 d, s32 e) {
    struct A1Obj* h = D_00347f80->heap;
    void* p = h->vt->alloc(h, 0xb60, 0);
    func_0031bcf8(p);
    func_001516b0(p, a, b, c, f, d, e);
    return p;
}
}  // namespace n0014fa48

// 0014fb00 (was src/anon/batch_w18.cpp)
namespace n0014fb00 {
// 0014d8d0: moved to src/anon/unit_0014d680.cpp

u32 func_00139d78(void*) asm("func_00139d78");
void func_00151bf0(void*) asm("func_00151bf0");
/*TARGET 0014fb00*/
void func_0014fb00(void* p) asm("func_0014fb00");
void func_0014fb00(void* p) {
    if (func_00139d78(p)) func_00151bf0(p);
}
}  // namespace n0014fb00

// 0014fb40 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0014fb40 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 0014fb40*/
u32 func_0014fb40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014fb40jjjj");
u32 func_0014fb40(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0014fb40

// 0014fb60 (was src/anon/batch_w19.cpp)
namespace n0014fb60 {
u8 func_00139d78(void*) asm("func_00139d78");
void func_00151c70(void*) asm("func_00151c70");
void force_leave_mission_gauge(void* g) asm("_ZN2dk11INFORMATION22forceLeaveMissionGaugeEPNS_13MISSION_GAUGEE");
/*TARGET 0014fb60*/
void force_leave_mission_gauge(void* g) asm("_ZN2dk11INFORMATION22forceLeaveMissionGaugeEPNS_13MISSION_GAUGEE");
void force_leave_mission_gauge(void* g) {
    if (func_00139d78(g)) func_00151c70(g);
}
}  // namespace n0014fb60

// 0014fba0 (was src/anon/batch_w63.cpp)
namespace n0014fba0 {
extern s16 D_0034a458[19][3] asm("D_0034a458");
/*TARGET 0014fba0*/
void func_0014fba0(void) asm("func_0014fba0");
void func_0014fba0(void) {
    for (s32 i = 0; i < 19; i++)
        for (s32 j = 0; j < 3; j++)
            D_0034a458[i][j] = 0;
}
}  // namespace n0014fba0

// 0014fbf8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014fbf8 {
extern u8 D_0034a458 asm("D_0034a458");
/*TARGET 0014fbf8*/
u32 func_0014fbf8(u32 a0) asm("_Z13func_0014fbf8j");
u32 func_0014fbf8(u32 a0) {  // sum_table_shorts
    s32 t7 = *(s32*)((u32)a0 + (s32)(24));
    if (t7 <= 0) {
        return 0u;
    }
    u32 t6 = *(u32*)((u32)a0 + (s32)(28));
    s32 t5 = t7;
    u32 v0 = 0u;
    t6 = (u32)(t6 << 1);
    u32 p = (u32)((u32)&D_0034a458 + t6);
    do {
        s32 t = (s32)*(s16*)((u32)p + (s32)(0));
        t5 = (s32)(t5 + (-1));
        v0 = (u32)(v0 + t);
        p = (u32)((s32)p + (6));
    } while (t5 != 0);
    return v0;
}
}  // namespace n0014fbf8

// 0014fc40 (was src/anon/batch_w54.cpp)
namespace n0014fc40 {
union S16c {
    s16 v;
    u8 c;
};
// 0x00140480: definition moved into src/anon/unit_0013fca8.cpp

void func_001391c8(void*, s32, s32) asm("func_001391c8");
s32 func_0014fbf8(void*) asm("func_0014fbf8");
extern S16c D_0034a458[][3] asm("D_0034a458");
/*TARGET 0014fc40*/
void func_0014fc40(u8* p, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1) asm("func_0014fc40");
void func_0014fc40(u8* p, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1) {
    func_001391c8(p, a3, t0);
    D_0034a458[a1][t1].v = a2;
    *(s32*)(p + 24) = a1;
    *(s32*)(p + 28) = t1;
    s32 r = func_0014fbf8(p);
    *(s32*)(p + 36) = r;
    *(f32*)(p + 40) = *(f32*)(p + 44) = (f32)r;
}
}  // namespace n0014fc40

// 0014fcd8 (was src/anon/batch_w2381.cpp)
namespace n0014fcd8 {
// ---- 0014fcd8: spring a value toward an integer target
struct W2381V4 {
    f32 x, y, z, w;
    W2381V4() {}
    W2381V4(const W2381V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2381V4& operator=(const W2381V4& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2381Spring { u8 pad[0x24]; s32 tgt; f32 cur; f32 vel; };
W2381V4 func_0013f6e8(W2381V4, W2381V4, W2381V4, f32, f32, f32, f32) asm("func_0013f6e8");
s32 func_0014fbf8(void*) asm("func_0014fbf8");
// Zero three VU0 vectors in one block.
static inline void w2381_zero3(W2381V4* a, W2381V4* b, W2381V4* c)
{
    asm volatile("sqc2 $vf0, 0(%0)\n\tsqc2 $vf0, 0(%1)\n\tsqc2 $vf0, 0(%2)" : : "r"(a), "r"(b), "r"(c) : "memory");
}
static inline void w2381_spring(W2381V4& cur, const W2381V4& goal, const W2381V4& vel, f32 dt, f32 k, f32 d, f32 r)
{
    cur = func_0013f6e8(cur, goal, vel, dt, k, d, r);
}
void w2381_ctarget(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_0014fcd8jjjj");
/*TARGET 0014fcd8*/
void w2381_ctarget(u32 a0, u32, u32, u32) asm("_Z16ctarget_0014fcd8jjjj");
void w2381_ctarget(u32 a0, u32, u32, u32)
{
    W2381Spring* o = (W2381Spring*)a0;
    W2381V4 vel;
    W2381V4 pos;
    W2381V4 goal;
    w2381_zero3(&vel, &pos, &goal);
    f32 c = o->cur;
    pos.x = c;
    o->vel = c;
    vel.x = c;
    s32 t = func_0014fbf8(o);
    if (t != o->tgt) {
        goal.x = (f32)t;
        w2381_spring(pos, goal, vel, 0.4f, 1.2f, 0.5f, 0.1f);
        f32 r = pos.x;
        o->cur = r;
        o->tgt = (s32)r;
    }
}
}  // namespace n0014fcd8

// 0014fdd0 (was src/anon/tiny_auto80_solver.cpp)
namespace n0014fdd0 {
extern u8 D_0034a458 asm("D_0034a458");
/*TARGET 0014fdd0*/
void func_0014fdd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0014fdd0jjjjjjjj");
void func_0014fdd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // entry_clear_by_fields
    u32 x = *(u32*)(a0 + 24);
    u32 y = *(u32*)(a0 + 28);
    u32 idx = x << 1;
    idx += x;
    idx += y;
    idx <<= 1;
    u32 base = (u32)&D_0034a458;
    *(u16*)(idx + base) = 0;
}
}  // namespace n0014fdd0

// 0014fe00 (was src/anon/perm_0014fe00.cpp)
namespace n0014fe00 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct W1630Seq
{
  u8 pad[344];
};
struct W1630Sprite
{
  u8 pad0[24];
  W1630Seq seq;
  u8 pad1[28];
  void *parent;
  s32 flag;
  u8 pad2[4];
};
struct W1630Menu
{
  u8 pad0[32];
  s32 x;
  s32 y;
  u8 pad1[8];
  W1630Sprite root;
  u8 pad2[40];
  W1630Seq title;
  W1630Sprite base;
  W1630Sprite cursor;
  W1630Sprite items[5];
  W1630Sprite items2[5];
  W1630Sprite extra;
  u32 p1;
  u32 v1;
  s32 f6152;
  u32 p2;
  u32 v2;
  s32 f6164;
  s32 count;
  s32 hasExtra;
  s32 f6176;
};
void func_00138650(W1630Sprite *, u32, u32, u32) asm("func_00138650");
void func_001386e0(W1630Sprite *, u32, u32, void *, u32, u32) asm("func_001386e0");
void func_001396b0(W1630Sprite *) asm("_ZN2Tz6Select10BeginLeaveEz");
void func_0031a260(W1630Sprite *, u32) asm("_ZN2Tz6Select7SetFlagEz");
void func_00139660(W1630Sprite *) asm("_ZN2dk5Obj2D19getParentSeqColorOnEv");
void func_00139688(W1630Sprite *) asm("_ZN2dk5Obj2D21getParentSeqAlphaOnlyEv");
void func_00138c68(W1630Sprite *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
void func_00138c40(W1630Sprite *, s32, s32) asm("_ZN2dk6Sprite6setPosEii");
void func_00239988(W1630Seq *, u32, void *) asm("func_00239988");
void func_00239c38(W1630Seq *, s32) asm("_ZN2YI8SEQUENCE14SetNumberForceEi");
void func_0023acd8(W1630Seq *) asm("func_0023acd8");
s32 func_0023a950(W1630Seq *) asm("_ZN2YI8SEQUENCE10GetActiveXEv");
s32 func_0023a988(W1630Seq *) asm("_ZN2YI8SEQUENCE10GetActiveYEv");
s32 func_0023aa78(W1630Seq *) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
s32 func_0023aa98(W1630Seq *) asm("_ZN2YI8SEQUENCE10GetParamExEv");
void func_0014fc40(W1630Menu *, u32, s32, u32, u32, s32) asm("func_0014fc40");
void func_00150660(W1630Menu *) asm("func_00150660");
inline static void W1630_setParent(W1630Sprite *obj, W1630Sprite *parent)
{
  obj->parent = parent;
  func_001396b0(obj);
  if (obj->parent != 0)
  {
    obj->flag = 0;
    func_001396b0(obj);
    if (obj->flag != 0)
    {
      func_0031a260(obj, 0);
    }
  }
}
/*TARGET 0014fe00*/
void func_0014fe00(W1630Menu *self, u32 a1, u32 a2, s32 mode, s32 hasExtra, s32 count, u32 *p1, u32 *p2, u32 a8) asm("func_0014fe00");
void func_0014fe00(W1630Menu *self, u32 a1, u32 a2, s32 mode, s32 hasExtra, s32 count, u32 *p1, u32 *p2, u32 a8)
{
  s32 num;
  void *s5;
  s32 cr;
  u32 *new_var2;
  s32 i;
  s32 k;
  s32 sum;
  W1630Sprite *p;
  s32 *new_var;
  self->hasExtra = hasExtra;
  self->count = count;
  self->f6176 = 0;
  self->p1 = (u32) p1;
  self->v1 = *p1;
  self->p2 = (u32) p2;
  self->v2 = *p2;
  num = 0;
  s5 = ((u8 *) (&self->root)) + 32;
  func_00138650(&self->root, 3200, a1, 8);
  switch (mode)
  {
    case 0:
      num = 36;
      break;

    case 2:
      num = 35;
      break;

    case 1:
      num = 37;
      break;

  }

  func_00239988(&self->title, a2, s5);
  func_00239c38(&self->title, num);
  func_0023acd8(&self->title);
  self->x = func_0023a950(&self->title);
  func_001386e0(&self->base, 3200, a2, s5, 3, 8);
  cr = func_0023aa78(&self->base.seq);
  func_001386e0(&self->cursor, 3200, a2, s5, 9, 8);
  W1630_setParent(&self->cursor, &self->base);
  func_00139660(&self->cursor);
  func_00139688(&self->cursor);
  func_00138c68(&self->cursor, func_0023a950(&self->base.seq), func_0023a988(&self->base.seq));
  i = 0;
  new_var2 = &a8;
  sum = 0;
  k = self->count - 1;
  for (; i < self->count; i++)
  {
    s32 w;
    func_001386e0(&self->items[i], 3200, a2, s5, 12, 8);
    W1630_setParent(&self->items[i], &self->base);
    func_00139660(&self->items[i]);
    func_00139688(&self->items[i]);
    new_var = &mode;
    w = func_0023aa98(&self->items[0].seq);
    func_00138c68(&self->items[i], k * w, 0);
    sum += w;
    k--;
  }

  if (self->hasExtra == 1)
  {
    func_001386e0(&self->extra, 3200, a2, s5, 23, 8);
    W1630_setParent(&self->extra, &self->base);
    func_00139660(&self->extra);
    func_00139688(&self->extra);
    {
      s32 w = func_0023aa98(&self->extra.seq);
      func_00138c68(&self->extra, sum, 0);
      sum += w;
    }
    k = self->count - 1;
    for (i = 0; i < self->count; i++)
    {
      func_001386e0(&self->items2[i], 3200, a2, s5, 24, 8);
      W1630_setParent(&self->items2[i], &self->base);
      func_00139660(&self->items2[i]);
      func_00139688(&self->items2[i]);
      func_00138c68(&self->items2[i], sum + (k * func_0023aa98(&self->items2[0].seq)), 0);
      k--;
    }

  }
  func_0014fc40(self, *new_var2, cr, 3200, 8, *new_var);
  W1630_setParent(&self->base, 0);
  func_00138c40(&self->base, self->x, self->y);
  func_00150660(self);
  self->f6152 = -1;
  sum = 1;
  self->f6164 = -sum;
}
}  // namespace n0014fe00

// 00150260 (was src/anon/auto80_199_queue.cpp)
namespace n00150260 {
/*TARGET 00150260*/
void func_00150260(u32 a0, u32 a1, s32 a2, u32 a3) asm("_Z13func_00150260jjij");
void func_00150260(u32 a0, u32 a1, s32 a2, u32 a3) {
    char buf[16];
    u32 s1 = a0;
    s32 s2 = a2;
    u32 s0 = a3;

    func_002fee78((u32)buf, (u32)D_0036b228, a1);

    if (s2 > 0) {
        s32 n = s2;
        char* p = &buf[8];

        do {
            s32 d = (s32)(*p) - 48;
            n--;
            p--;
            u32 idx = ((u32)d) << 2;
            idx = idx + s1;
            *(u32*)s0 = *(u32*)idx;
            s0 += 4;
        } while (n != 0);
    }
}
}  // namespace n00150260

// 001502e8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001502e8 {
void func_0014fdd0(...) asm("func_0014fdd0");
/*TARGET 001502e8*/
// entry_clear_by_fields
void func_001502e8(Obj001502e8* a0) asm("_Z13func_001502e8P11Obj001502e8");
// entry_clear_by_fields
void func_001502e8(Obj001502e8* a0) {
    func_0014fdd0((u32)a0);  // entry_clear_by_fields
    if (a0 != 0) {
        a0->vtbl->fn10(a0);
    }
}
}  // namespace n001502e8

// 00150328 (was src/anon/batch_w323.cpp)
namespace n00150328 {
#define FLD(T, o) (*(T*)((u8*)self + (o)))
extern u8 D_0034a4f0[] asm("D_0034a4f0");
extern u8 D_0034a518[] asm("D_0034a518");
void func_0014fcd8(void*) asm("func_0014fcd8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_001506e0(void*) asm("func_001506e0");
void func_00138c40(void*, u32, u32) asm("func_00138c40");
void func_00150260(void*, u32, s32, s32*) asm("func_00150260");
void func_00138c10(void*, s32) asm("func_00138c10");
void func_001395a8(void*) asm("func_001395a8");
void func_00139598(void*) asm("func_00139598");
/*TARGET 00150328*/
void func_00150328(u8* self) asm("func_00150328");
void func_00150328(u8* self) {
    s32 buf[8];
    func_0014fcd8(self);
    if (FLD(s32, 6176) == 1) {
        if (!func_00139d78(self + 840)) func_001506e0(self);
        return;
    }
    func_00138c40(self + 840, FLD(u32, 32), FLD(u32, 36));
    FLD(u32, 6148) = **(u32**)(self + 6144);
    FLD(u32, 6160) = **(u32**)(self + 6156);
    if (FLD(u32, 6152) != FLD(u32, 6148)) {
        func_00150260(D_0034a4f0, FLD(u32, 6148), 5, buf);
        for (s32 i = FLD(s32, 6168) - 1; i >= 0; i--) {
            func_00138c10(self + 1656 + i * 408, buf[i]);
            func_001395a8(self + 1656 + i * 408);
        }
        for (s32 j = FLD(s32, 6168) - 1; j > 0; j--) {
            if (buf[j] != 12) break;
            if (FLD(s32, 6172) == 2) func_00139598(self + 1656 + j * 408);
            else func_00138c10(self + 1656 + j * 408, 22);
        }
    }
    if (FLD(u32, 6164) != FLD(u32, 6160) && FLD(s32, 6172) == 1) {
        func_00150260(D_0034a518, FLD(u32, 6160), 5, buf);
        for (s32 k = FLD(s32, 6168) - 1; k >= 0; k--) {
            func_00138c10(self + 3696 + k * 408, buf[k]);
        }
        for (s32 l = FLD(s32, 6168) - 1; l > 0; l--) {
            if (buf[l] != 24) break;
            func_00138c10(self + 3696 + l * 408, 34);
        }
    }
    FLD(u32, 6164) = FLD(u32, 6160);
    FLD(u32, 6152) = FLD(u32, 6148);
}
}  // namespace n00150328

// 00150578 (was src/anon/batch_w11.cpp)
namespace n00150578 {
void func_00138c10(void*, s32) asm("func_00138c10");
/*TARGET 00150578*/
void func_00150578(u8* p) asm("func_00150578");
void func_00150578(u8* p) {
    func_00138c10(p + 840, 0);
    func_00138c10(p + 1248, 6);
}
}  // namespace n00150578

// 001505b0 (was src/anon/auto80_199_queue.cpp)
namespace n001505b0 {
/*TARGET 001505b0*/
void func_001505b0(u32 a0) asm("_Z13func_001505b0j");
void func_001505b0(u32 a0) {
    u32 s1 = a0 + 840;
    func_00138c10(s1, 4);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 1248;
    func_00138c10(s0, 10);
    *(s32*)(s0 + 392) = s2;
}
}  // namespace n001505b0

// 00150610 (was src/anon/batch_w12.cpp)
namespace n00150610 {
void func_00138c10(void*, s32) asm("func_00138c10");
void COUNTER_alertLoop(u8*) asm("_ZN2dk7COUNTER9alertLoopEv");
/*TARGET 00150610*/
void COUNTER_alertLoop(u8* self) asm("_ZN2dk7COUNTER9alertLoopEv");
void COUNTER_alertLoop(u8* self) {
    func_00138c10(self + 840, 1);
    func_00138c10(self + 1248, 7);
}
}  // namespace n00150610

// 00150648 (was src/anon/tiny.cpp)
namespace n00150648 {
void func_001505b0(void*) asm("_Z13func_001505b0Pv");
/*TARGET 00150648*/
void func_00150648(BD_VALUE* bd) asm("_Z13func_00150648P8BD_VALUE");
void func_00150648(BD_VALUE* bd) { func_001505b0(bd); }
}  // namespace n00150648

// 00150660 (was src/anon/tiny_more2.cpp)
namespace n00150660 {
/*TARGET 00150660*/
// 0x0013c720: definition moved into src/anon/unit_0013a8b8.cpp

void func_00150660(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00150660jjjj");
// 0x0013c720: definition moved into src/anon/unit_0013a8b8.cpp

void func_00150660(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; *(u32*)((u32)a0 + (1232)) = (u32)((s32)4); *(u32*)((u32)a0 + (1640)) = (u32)((s32)10); }
}  // namespace n00150660

// 00150678 (was src/anon/auto80_199_queue.cpp)
namespace n00150678 {
/*TARGET 00150678*/
void func_00150678(u32 a0) asm("_Z13func_00150678j");
void func_00150678(u32 a0) {
    *(u32*)(a0 + 6176) = 1;

    u32 s1 = a0 + 840;
    func_00138c10(s1, 5);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 1248;
    func_00138c10(s0, 11);
    *(s32*)(s0 + 392) = s2;
}
}  // namespace n00150678

// 001506e0 (was src/anon/batch_w91.cpp)
namespace n001506e0 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00139510(void*) asm("func_00139510");
// --- 001506e0
void func_001396b0(void*) asm("func_001396b0");
void func_0031a260(void*, s32) asm("func_0031a260");
struct Ent506 { void (**vt)(Ent506*); u8 pad[392]; u32 a; u32 b; u8 pad2[4]; };
struct Own506 { void (**vt)(Own506*); u8 pad[44]; u8 sub[792]; Ent506 e[13]; };
/*TARGET 001506e0*/
void func_001506e0(Own506* p) asm("func_001506e0");
void func_001506e0(Own506* p) {
    if (u_call4_00139d78(p)) p->vt[5](p);
    if (u_call4_00139d78(p->sub)) func_00139510(p->sub);
    for (s32 i = 0; i < 13; i++) {
        if (u_call4_00139d78(&p->e[i])) {
            p->e[i].a = 0;
            func_001396b0(&p->e[i]);
            if (p->e[i].a) {
                p->e[i].b = 0;
                func_001396b0(&p->e[i]);
                if (p->e[i].b) func_0031a260(&p->e[i], 0);
            }
            p->e[i].vt[5](&p->e[i]);
        }
    }
}
}  // namespace n001506e0

// 001507b8 (was src/anon/perm_001507b8.cpp)
namespace n001507b8 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct S1507b8
{
  u8 pad[392];
  s32 f392;
  u8 pad2[116];
};
struct O1507b8
{
  u8 pad[48];
  S1507b8 a;
  u8 pad2[412];
  u32 f972;
};
u32 func_0013a7e8(s32) asm("func_0013a7e8");
u32 func_0013d7e0() asm("func_0013d7e0");
void func_00138d60(S1507b8 *, s32, u32, u32, s32, s32, s32) asm("func_00138d60");
void func_001386e0(S1507b8 *, s32, u32, u32, s32, s32) asm("func_001386e0");
u32 func_0023aa78(u8 *) asm("func_0023aa78");
void func_0014fc40(O1507b8 *, s32, u32, s32, s32, s32) asm("func_0014fc40");
void func_001508a0(O1507b8 *, s32) asm("func_001508a0");
/*TARGET 001507b8*/
void func_001507b8(O1507b8 *o, s32 v) asm("func_001507b8");
void func_001507b8(O1507b8 *o, s32 v)
{
  u32 a;
  S1507b8 *s;
  S1507b8 *t;
  u32 b;
  a = func_0013a7e8(1);
  s = &o->a;
  ;
  b = func_0013d7e0();
  func_00138d60(s, 8000, a, b, 0, v, 7);
  func_001386e0((S1507b8 *) (((u8 *) o) + 560), 8000, a, b, 0, 7);
  s->f392 = 1;
  ((S1507b8 *) (((u8 *) o) - -560))->f392 = 2;
  func_0014fc40(o, 1, func_0023aa78(((u8 *) o) + 72), 8000, 7, 0);
  o->f972 = 0;
  func_001508a0(o, v);
}
}  // namespace n001507b8

// .rodata 0x36b224-0x36b230: gas pad + a format string that the code reads as extern D_
extern "C" const u32 D_0036b224 = 0;
extern const char R_0036b228[8] asm("D_0036b228") __attribute__((aligned(4))) = "%09d";

// 001508a0 (was src/anon/batch_wcx.cpp)
namespace n001508a0 {
struct T96 { u8 pad[80]; s32 v; u8 pad2[12]; };
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
void func_001395a8(u8*) asm("func_001395a8");
void func_001a98e8(T96*, s32, u32, s32, s32) asm("func_001a98e8");
s32 func_0023aa18(u8*) asm("func_0023aa18");
/*TARGET 001508a0*/
void func_001508a0(u8* p, u32 a) asm("func_001508a0");
void func_001508a0(u8* p, u32 a)
{
    func_002ba2e8(34, 0);
    u8* q = p + 48;
    *(u32*)(p + 972) &= ~2;
    func_001395a8(p + 560);
    T96 t;
    func_001a98e8(&t, 0, a, 0, 0);
    s32 v = func_0023aa18(p + 72);
    *(s32*)(p + 968) = v - t.v;
    *(s32*)(q + 412) = v;
    *(s32*)(q + 416) = 0;
    *(f32*)(p + 976) = 180.0f;
}
}  // namespace n001508a0

// 00150940 (was src/anon/perm_00150940.cpp)
namespace n00150940 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct Sub
{
  u8 pad[0x188];
  s32 m188;
  u8 pad2[0xc];
  s32 m198;
};
struct Obj
{
  u8 pad[0x30];
  Sub a;
  u8 pad2[(0x230 - 0x30) - (sizeof(Sub))];
  Sub b;
  u32 f0 : 1;
  u32 f1 : 1;
};
void func_00138c10(Sub *, s32) asm("_ZN2dk6Sprite6setNumEi");
void func_001508a0(Obj *, s32) asm("func_001508a0");
/*TARGET 00150940*/
void func_00150940(Obj *o, s32 x) asm("func_00150940");
void func_00150940(Obj *o, s32 x)
{
  int new_var2;
  Sub *new_var;
  if (o->f0)
  {
    Sub *a = &o->a;
    Sub *b = &o->b;
    a->m198 = x;
    func_001508a0(o, x);
    func_00138c10(a, 0);
    new_var2 = 1;
    func_00138c10(b, 0);
    a->m188 = new_var2;
    new_var = b;
    new_var->m188 = 2;
    o->f0 = 0;
  }
  else
  {
    Sub *a = &o->a;
    a->m198 = x;
    func_00138c10(a, 1);
    a->m188 = -1;
    func_00138c10(&o->b, 2);
    func_001508a0(o, x);
    o->f1 = 1;
  }
}
}  // namespace n00150940

// 00150a18 (was src/anon/batch_wcx2.cpp)
namespace n00150a18 {
// 0x0013c080: definition moved into src/anon/unit_0013a8b8.cpp

extern f32 D_00349e14 asm("D_00349e14");
void func_0014fcd8(u8*) asm("func_0014fcd8");
s32 func_00139538(u8*) asm("func_00139538");
void func_00139510(u8*) asm("func_00139510");
void func_0014b950(u8*, s32, s16, u32, s32) asm("func_0014b950");
void func_00138c40(u8*, s32, s32) asm("func_00138c40");
u32 func_0023aa98(u8*) asm("func_0023aa98");
void func_00150b68(u8*) asm("func_00150b68");
struct NoTail7 { ~NoTail7() {} };
struct Fl7 { u32 busy : 1; u32 alt : 1; u32 rest : 30; };
struct Obj7 { u8 pad[972]; Fl7 fl; };
/*TARGET 00150a18*/
void func_00150a18(u8* p) asm("func_00150a18");
void func_00150a18(u8* p)
{
    NoTail7 nt;
    func_0014fcd8(p);
    u8* m = p + 48;
    if (func_00139538(m)) {
        (*(void (**)(u8*))(*(u8**)p + 20))(p);
        func_00139510(p + 560);
        ((Obj7*)p)->fl.busy = 0;
        return;
    }
    Obj7* o = (Obj7*)p;
    if (o->fl.busy) return;
    if (m[404] && !o->fl.alt) o->fl.alt = 1;
    if (!o->fl.alt) {
        func_0014b950(p + 496, 0, *(s16*)(p + 36), 1, 1);
    } else {
        func_0014b950(p + 496, 0, *(s16*)(p + 36), (u16)func_0023aa98(p + 72), 64);
        if (0.0f < *(f32*)(p + 976)) {
            *(f32*)(p + 976) -= D_00349e14;
        } else {
            if (--*(s32*)(m + 412) < *(s32*)(p + 968)) func_00150b68(p);
        }
    }
    func_00138c40(m, 0, *(s32*)(p + 36));
    func_00138c40(p + 560, 0, *(s32*)(p + 36));
}
}  // namespace n00150a18

// 00150b68 (was src/harata/libdk/information.cpp)
namespace dk { // method 00150b68
void func_00138c10(u32, u32) asm("func_00138c10");
void func_00139598(u32) asm("func_00139598");
/*TARGET 00150b68*/
void INFORMATION_WINDOW_close(INFORMATION_WINDOW* self) asm("_ZN2dk18INFORMATION_WINDOW5closeEv");
void INFORMATION_WINDOW_close(INFORMATION_WINDOW* self) {
    u32 s0 = (u32)self;
    u32 s1 = (u32)self + 48;

    *(u32*)((u32)self + 972) = *(u32*)((u32)self + 972) | 1u;
    *(u32*)(s1 + 408) = 0u;

    func_00138c10(s1, 3u);

    *(s32*)(s1 + 392) = -1;
    func_00139598(s0 + 560);
}
}  // dk

// 00150bc0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00150bc0 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 00150bc0*/
u32 func_00150bc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00150bc0jjjj");
u32 func_00150bc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)r4 + (48));
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00150bc0

// 00150be0 (was src/harata/libdk/information.cpp)
namespace dk { // method 00150be0
/*TARGET 00150be0*/
s32 INFORMATION_WINDOW_getMessage(INFORMATION_WINDOW* self) asm("_ZN2dk18INFORMATION_WINDOW10getMessageEv");
s32 INFORMATION_WINDOW_getMessage(INFORMATION_WINDOW* self) {
    return reinterpret_cast<INFORMATION_WINDOW_Layout*>(self)->message;
}
}  // dk

// 00150be8 (was src/anon/batch_w114.cpp)
namespace n00150be8 {
void func_001396b0(u8*) asm("func_001396b0");
void func_0031a260(u8*, s32) asm("func_0031a260");
void func_00139660(u8*) asm("func_00139660");
void func_00139688(u8*) asm("func_00139688");
void func_00138c40(u8*, s32, u32) asm("func_00138c40");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
s32 func_0023aa98(u8*) asm("func_0023aa98");
static inline void settle(u8* m) {
    func_001396b0(m);
    if (*(u32*)(m + 396)) {
        *(u32*)(m + 400) = 0;
        func_001396b0(m);
        if (*(u32*)(m + 400)) func_0031a260(m, 0);
    }
}
void func_00150be8(u8* p) asm("func_00150be8");
/*TARGET 00150be8*/
void func_00150be8(u8* p) asm("func_00150be8");
void func_00150be8(u8* p) {
    u8* m = p + 496;
    u8* e;
    s32 i, off;
    *(u32*)(p + 6568) = 0;
    *(u32*)(m + 392) = 4;
    *(u32*)(p + 1296) = 10;
    e = m;
    for (i = 9; i >= 0; i--) {
        *(u8**)(e + 396) = m;
        settle(e);
        func_00139660(e);
        func_00139688(e);
        e += 408;
    }
    *(u32*)(m + 396) = 0;
    settle(m);
    func_00138c40(m, *(u32*)(p + 32), *(u32*)(p + 36));
    func_00138c68(p + 1312, 0, 0);
    off = func_0023aa98(p + 1336);
    func_00138c68(p + 1720, off, 0);
    off += func_0023aa98(p + 1744);
    func_00138c68(p + 3760, off, 0);
    off += func_0023aa98(p + 3784);
    func_00138c68(p + 2128, off, 0);
    off += func_0023aa98(p + 2152);
    func_00138c68(p + 2536, off, 0);
    off += func_0023aa98(p + 2560);
    func_00138c68(p + 4168, off, 0);
    off += func_0023aa98(p + 4192);
    func_00138c68(p + 2944, off, 0);
    off += func_0023aa98(p + 2968);
    func_00138c68(p + 3352, off, 0);
    *(s32*)(p + 6564) = -1;
}
}  // namespace n00150be8

// 00150dc0 (was src/anon/tiny_wrappers_more.cpp)
namespace n00150dc0 {
u32 func_00150e00(u32, u32, u32, u32) asm("_Z13func_00150e00jjjj");
/*TARGET 00150dc0*/
u32 func_00150dc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00150dc0jjjj");
u32 func_00150dc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 6560u) = (u32)(0xffffffffu);
    return func_00150e00(a0, a1, a2, a3);
}
}  // namespace n00150dc0

// 00150de0 (was src/anon/batch_w1.cpp)
namespace n00150de0 {
void func_00150e00(void*, u32, u32, u32, u32, s32) asm("func_00150e00");
/*TARGET 00150de0*/
// 0x00143b60: definition moved into src/anon/unit_00142c90.cpp

void func_00150de0(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) asm("func_00150de0");
// 0x00143b60: definition moved into src/anon/unit_00142c90.cpp

void func_00150de0(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    *(u32*)(p + 0x19a0) = a5;
    func_00150e00(p, a1, a2, a3, a4, -1);
}
}  // namespace n00150de0

// 00150e00 (was src/anon/batch_w1630.cpp)
namespace n00150e00 {
struct W1630Seq { u8 pad[344]; };
struct W1630Sprite {
    u8 pad0[24];
    W1630Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W1630Menu2 {
    u8 pad0[32];
    s32 x, y;               // 32, 36
    u8 pad1[8];
    W1630Sprite root;       // 48
    u8 pad2[40];
    W1630Sprite title;      // 496
    W1630Sprite base;       // 904
    W1630Sprite items[6];   // 1312
    W1630Sprite extra;      // 3760
    W1630Sprite extra2;     // 4168
    u8 pad3[1632];
    W1630Seq seq;           // 6208
    s32 f6552;
    u32 f6556;
};
s32 func_00151590(W1630Menu2*) asm("func_00151590");
void func_001514e8(W1630Menu2*) asm("func_001514e8");
u32 func_00139d78(void*) asm("func_00139d78");
void func_00138650(W1630Sprite*, u32, u32, u32) asm("func_00138650");
s32 func_0013a9d0(void) asm("func_0013a9d0");
void func_002368e8(void*, f32) asm("func_002368e8");
void func_002367c8(void*) asm("func_002367c8");
s32 func_00139538(W1630Sprite*) asm("func_00139538");
void func_00139520(W1630Sprite*) asm("func_00139520");
void func_001386e0(W1630Sprite*, u32, u32, void*, u32, u32) asm("func_001386e0");
void func_00239988(W1630Seq*, u32, void*) asm("func_00239988");
void func_00239c38(W1630Seq*, s32) asm("func_00239c38");
void func_0023acd8(W1630Seq*) asm("func_0023acd8");
s32 func_0023a950(W1630Seq*) asm("func_0023a950");
s32 func_0023aa78(W1630Seq*) asm("func_0023aa78");
void func_0014fc40(W1630Menu2*, u32, s32, u32, u32, s32) asm("func_0014fc40");
void func_00150be8(W1630Menu2*) asm("func_00150be8");
void wtarget_00150e00(W1630Menu2* self, u32 a1, u32 a2, s32 mode, u32 a4) asm("_Z16wtarget_00150e00jjjj");
/*TARGET 00150e00*/
// (Re)builds the menu panel: root sprite, title sequence, base/item sprites, then the shared init.
void wtarget_00150e00(W1630Menu2* self, u32 a1, u32 a2, s32 mode, u32 a4) asm("_Z16wtarget_00150e00jjjj");
// (Re)builds the menu panel: root sprite, title sequence, base/item sprites, then the shared init.
void wtarget_00150e00(W1630Menu2* self, u32 a1, u32 a2, s32 mode, u32 a4) {
    void* s5;
    s32 num;
    s32 i;
    W1630Sprite* p;
    s32 cr;
    if (func_00151590(self)) {
        func_001514e8(self);
        return;
    }
    if (!func_00139d78(&self->root)) {
        func_00138650(&self->root, 3600, a1, 9);
        if (func_0013a9d0()) {
            func_002368e8((u8*)&self->root + 32, 0.8f);
            func_002367c8((u8*)&self->root + 32);
        }
    } else if (func_00139538(&self->root)) {
        func_00139520(&self->root);
    }
    s5 = (u8*)&self->root + 32;
    self->f6552 = 0;
    self->f6556 = a2;
    num = 0;
    switch (mode) {
    case 0: num = 26; break;
    case 2: num = 25; break;
    case 1: num = 27; break;
    }
    func_00239988(&self->seq, a2, s5);
    func_00239c38(&self->seq, num);
    func_0023acd8(&self->seq);
    self->x = func_0023a950(&self->seq);
    func_001386e0(&self->title, 3600, a2, s5, 3, 9);
    if (!func_00139d78(&self->base)) {
        func_001386e0(&self->base, 3600, a2, s5, 9, 9);
    }
    for (i = 0; i < 6; i++) {
        if (!func_00139d78(&self->items[i])) {
            func_001386e0(&self->items[i], 3600, a2, s5, 12, 9);
        }
    }
    if (!func_00139d78(&self->extra)) {
        func_001386e0(&self->extra, 3600, a2, s5, 23, 9);
    }
    if (!func_00139d78(&self->extra2)) {
        func_001386e0(&self->extra2, 3600, a2, s5, 24, 9);
    }
    cr = func_0023aa78(&self->title.seq);
    if (!func_00139d78(self)) {
        func_0014fc40(self, a4, cr, 3600, 9, mode);
    }
    func_00150be8(self);
}
}  // namespace n00150e00

// 001510b0 (was gap, never written)
namespace n001510b0 {
void func_0014fdd0(u8*) asm("_Z13func_0014fdd0jjjjjjjj");
void func_001510b0(u8* p) asm("func_001510b0");
void func_001510b0(u8* p) {
    func_0014fdd0(p);
    if (*(s32*)(p + 6560) != -1 && p != 0) ((void (*)(u8*))(*(void***)p)[4])(p);
}
}  // namespace

// 00151100 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00151100 {
// set_vtbl_36eb28_then_call
u32 func_0023aa98(u32, u32, u32, u32) asm("_Z13func_0023aa98jjjj");
/*TARGET 00151100*/
u32 func_00151100(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00151100jjjj");
u32 func_00151100(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r16;
    r4 = (u32)((s32)r4 + (928));
    r16 = r5;
    u32 (*fp_call4_0023aa98)(u32, u32, u32, u32) = func_0023aa98;
    r2 = fp_call4_0023aa98(r4, r5, r6, r7);
    r16 = ((u32)0u < (u32)r16);
    r2 = (u32)(r2 ^ 0x0001u);
    if (r2 != 0u) r16 = 0u;
    r2 = r16;
    return r2;
}
}  // namespace n00151100

// 00151138 (was src/anon/batch_w1898.cpp)
namespace n00151138 {
struct W1898Seq { u8 pad[344]; };
struct W1898Sprite {
    u8 pad0[24];
    W1898Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W1898Menu2 {
    u8 pad0[32];
    s32 x, y;               // 32, 36
    u8 pad1[8];
    W1898Sprite root;       // 48
    u8 pad2[40];
    W1898Sprite title;      // 496
    W1898Sprite base;       // 904
    W1898Sprite items[6];   // 1312
    W1898Sprite extra;      // 3760
    W1898Sprite extra2;     // 4168
    W1898Sprite icons[4];   // 4576
    W1898Seq seq;           // 6208
    u32 flags;              // 6552
    u32 f6556;
    s32 time;               // 6560
    s32 shown;              // 6564
    s32 f6568;
};
void func_0014fcd8(W1898Menu2*) asm("func_0014fcd8");
u32 func_00139d78(void*) asm("func_00139d78");
void func_001515b0(W1898Menu2*) asm("func_001515b0");
void func_00138c40(W1898Sprite*, s32, s32) asm("func_00138c40");
s32 func_0014ca38(void) asm("func_0014ca38");
void func_0014ca80(s32, s32*, s32*, s32*, s32*) asm("func_0014ca80");
s32 func_00151100(W1898Menu2*, s32) asm("func_00151100");
void func_00150260(void*, s32, s32, s32*) asm("func_00150260");
void func_00138c10(W1898Sprite*, s32) asm("func_00138c10");
s32 func_0014c9a0(void) asm("func_0014c9a0");
void func_001386e0(W1898Sprite*, u32, u32, void*, u32, u32) asm("func_001386e0");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
extern u8 D_0034a580[] asm("D_0034a580");
/*TARGET 00151138*/
void func_00151138(W1898Menu2* self) asm("func_00151138");
void func_00151138(W1898Menu2* self) {
    s32 buf[2];
    s32 a, b, c, d;
    s32 v;
    u32 s3;
    void* s4;
    func_0014fcd8(self);
    if (self->f6568 == 1) {
        if (!func_00139d78(&self->title)) {
            func_001515b0(self);
        }
        return;
    }
    func_00138c40(&self->title, self->x, self->y);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    if (self->time == -1) {
        v = func_0014ca38();
    } else {
        v = self->time;
    }
    func_0014ca80(v, &a, &b, &c, &d);
    if (a != 0) {
        return;
    }
    if (self->shown != v) {
        if (func_00151100(self, v)) {
            v += 60;
            func_0014ca80(v, &a, &b, &c, &d);
        }
        func_00150260(D_0034a580, b, 2, buf);
        func_00138c10(&self->items[0], buf[1]);
        func_00138c10(&self->items[1], buf[0]);
        func_00150260(D_0034a580, c, 2, buf);
        func_00138c10(&self->items[2], buf[1]);
        func_00138c10(&self->items[3], buf[0]);
        func_00150260(D_0034a580, d, 2, buf);
        func_00138c10(&self->items[4], buf[1]);
        func_00138c10(&self->items[5], buf[0]);
        func_00138c10(&self->extra, 23);
        func_00138c10(&self->extra2, 24);
        if (func_00151100(self, v)) {
            v -= 60;
            func_0014ca80(v, &a, &b, &c, &d);
        }
    }
    if (self->time == -1 && func_0014c9a0() && a == 0 && b == 0) {
        s3 = self->f6556;
        s4 = (u8*)&self->root + 32;
        if (c == 2 && !func_00139d78(&self->icons[0]) && (self->flags & 1) == 0) {
            func_001386e0(&self->icons[0], 3600, s3, s4, 31, 7);
            self->flags |= 1;
            func_002ba2e8(43, 0);
        } else if (c == 1 && !func_00139d78(&self->icons[1]) && !(self->flags & 2)) {
            func_001386e0(&self->icons[1], 3600, s3, s4, 30, 7);
            self->flags |= 2;
            func_002ba2e8(43, 0);
        } else if (c == 0 && !func_00139d78(&self->icons[2]) && !(self->flags & 4)) {
            func_001386e0(&self->icons[2], 3600, s3, s4, 29, 7);
            self->flags |= 4;
            func_002ba2e8(43, 0);
        } else if (v == 0 && !func_00139d78(&self->icons[3]) && !(self->flags & 8)) {
            func_001386e0(&self->icons[3], 3600, s3, s4, 28, 7);
            self->flags |= 8;
        }
    }
    self->shown = v;
}
}  // namespace n00151138

// 001514b0 (was src/anon/batch_w13.cpp)
namespace n001514b0 {
// zero_fields_0_4_6_8
void func_00138c10(void*, s32) asm("func_00138c10");
extern void (*D_0035e380[])(void) asm("D_0035e380");
/*TARGET 001514b0*/
// 0x0013f4d8: definition moved into src/anon/unit_0013ef70.cpp

// 0014dbc8: moved to src/anon/unit_0014d680.cpp

void func_001514b0(u8* p) asm("func_001514b0");
// 0x0013f4d8: definition moved into src/anon/unit_0013ef70.cpp

// 0014dbc8: moved to src/anon/unit_0014d680.cpp

void func_001514b0(u8* p) {
    func_00138c10(p + 496, 0);
    func_00138c10(p + 904, 6);
}
}  // namespace n001514b0

// 001514e8 (was src/anon/batch_w20.cpp)
namespace n001514e8 {
void func_00138c10(void*, u32) asm("func_00138c10");
void func_00150be8(void*) asm("func_00150be8");
/*TARGET 001514e8*/
// 0x001385c0: definition moved into src/anon/unit_00138480.cpp

// 00149c08: moved to src/harata/libdk/area.cpp

void func_001514e8(u8* p) asm("func_001514e8");
// 0x001385c0: definition moved into src/anon/unit_00138480.cpp

// 00149c08: moved to src/harata/libdk/area.cpp

void func_001514e8(u8* p) {
    func_00138c10(p + 496, 3);
    func_00138c10(p + 904, 9);
    func_00150be8(p);
}
}  // namespace n001514e8

// 00151528 (was src/anon/auto80_199_queue.cpp)
namespace n00151528 {
/*TARGET 00151528*/
void func_00151528(u32 a0) asm("_Z13func_00151528j");
void func_00151528(u32 a0) {
    *(u32*)(a0 + 6568) = 1;

    u32 s1 = a0 + 496;
    func_00138c10(s1, 5);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 904;
    func_00138c10(s0, 11);
    *(s32*)(s0 + 392) = s2;
}
}  // namespace n00151528

// 00151590 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00151590 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 00151590*/
u32 func_00151590(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00151590jjjj");
u32 func_00151590(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)r4 + (496));
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00151590

// 001515b0 (was src/anon/batch_w91.cpp)
namespace n001515b0 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00139510(void*) asm("func_00139510");
/*TARGET 001515b0*/
// --- 001515b0
void func_001515b0(u8* p) asm("func_001515b0");
// --- 001515b0
void func_001515b0(u8* p) {
    s32 i;
    if (u_call4_00139d78(p)) (*(void (**)(u8*))(*(u8**)p + 20))(p);
    if (u_call4_00139d78(p + 48)) func_00139510(p + 48);
    for (i = 0; i < 10; i++) {
        u8* o = p + 496 + i * 408;
        if (u_call4_00139d78(o)) (*(void (**)(u8*))(*(u8**)o + 20))(o);
    }
    for (i = 0; i < 4; i++) {
        u8* o = p + 4576 + i * 408;
        if (u_call4_00139d78(o)) (*(void (**)(u8*))(*(u8**)o + 20))(o);
    }
}
}  // namespace n001515b0

// 00151690 (was src/anon/tiny_auto80_queue.cpp)
namespace n00151690 {
/*TARGET 00151690*/
f32 func_00151690(u32 a0) asm("_Z13func_00151690j");
f32 func_00151690(u32 a0) {  // scale_ratio_2888_2880
    f32 f1 = *(volatile f32*)((u32)a0 + (s32)(2880));
    f32 f0 = *(volatile f32*)((u32)a0 + (s32)(2888));
    return (f32)(f0 / f1);
}
}  // namespace n00151690

// 001516b0 (was src/anon/batch_w2418_nsa.cpp)
namespace n001516b0 {
struct W2418Seq { u8 pad[344]; };
struct W2418Sprite {
    u8 pad0[24];
    W2418Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W2418Menu3 {
    u8 pad0[32];
    s32 x, y;               // 32, 36
    u8 pad1[8];
    W2418Sprite root;       // 48
    u8 pad2[40];
    W2418Seq title;         // 496
    W2418Sprite spr[5];     // 840
    union { f32 f; u8 c; } f2880;
    union { u32 u; u8 c; } p2884;
    f32 f2888;
    f32 f2892;
    union { s32 i; u8 c; } f2896;
};
void func_00138650(W2418Sprite*, u32, u32, u32) asm("func_00138650");
void func_001386e0(W2418Sprite*, u32, u32, void*, u32, u32) asm("func_001386e0");
s32 func_0013a9d0(void) asm("func_0013a9d0");
void func_002368e8(void*, f32) asm("func_002368e8");
void func_002367c8(void*) asm("func_002367c8");
void func_001396b0(W2418Sprite*) asm("func_001396b0");
void func_0031a260(W2418Sprite*, u32) asm("func_0031a260");
void func_00139660(W2418Sprite*) asm("func_00139660");
void func_00139688(W2418Sprite*) asm("func_00139688");
void func_00138c68(W2418Sprite*, s32, s32) asm("func_00138c68");
void func_00138c40(W2418Sprite*, s32, s32) asm("func_00138c40");
void func_00239988(W2418Seq*, u32, void*) asm("func_00239988");
void func_00239c38(W2418Seq*, s32) asm("func_00239c38");
void func_0023acd8(W2418Seq*) asm("func_0023acd8");
s32 func_0023a950(W2418Seq*) asm("func_0023a950");
s32 func_0023a988(W2418Seq*) asm("func_0023a988");
s32 func_0023aa18(W2418Seq*) asm("func_0023aa18");
s32 func_0023aa38(W2418Seq*) asm("func_0023aa38");
s32 func_0023aa78(W2418Seq*) asm("func_0023aa78");
void func_0014fc40(W2418Menu3*, u32, s32, u32, u32, s32) asm("func_0014fc40");
void func_001519f8(W2418Menu3*) asm("func_001519f8");
void func_00151bd8(W2418Menu3*) asm("func_00151bd8");
static inline void W2418_setParent(W2418Sprite* obj, W2418Sprite* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}
/*TARGET 001516b0*/
void func_001516b0(W2418Menu3* self, u32 a1, u32 a2, s32 mode, f32* pv, u32 a5, f32 f) asm("func_001516b0");
void func_001516b0(W2418Menu3* self, u32 a1, u32 a2, s32 mode, f32* pv, u32 a5, f32 f) {
    s32 num;
    void* s5;
    s32 cr, i;
    self->p2884.u = (u32)pv;
    self->f2880.f = f;
    self->f2896.i = 0;
    self->f2888 = *pv;
    func_00138650(&self->root, 3400, a1, 10);
    s32 r = func_0013a9d0();
    if (__builtin_expect(r, 0)) {
        s5 = (u8*)&self->root + 32;
        func_002368e8(s5, 0.8f);
        func_002367c8(s5);
    } else {
        s5 = (u8*)&self->root + 32;
    }
    num = 0;
    switch (mode) {
    case 0: num = 16; break;
    case 2: num = 15; break;
    case 1: num = 17; break;
    }
    func_00239988(&self->title, a2, s5);
    func_00239c38(&self->title, num);
    func_0023acd8(&self->title);
    self->x = func_0023a950(&self->title);
    func_001386e0(&self->spr[0], 3400, a2, s5, 3, 10);
    func_001386e0(&self->spr[1], 3400, a2, s5, 12, 10);
    func_001386e0(&self->spr[2], 3400, a2, s5, 13, 10);
    func_001386e0(&self->spr[3], 3400, a2, s5, 14, 10);
    func_001386e0(&self->spr[4], 3400, a2, s5, 9, 10);
    cr = func_0023aa78(&self->spr[0].seq);
    func_0014fc40(self, a5, cr, 3400, 10, mode);
    func_001519f8(self);
    for (i = 0; i < 5; i++) {
        W2418_setParent(&self->spr[i], &self->spr[0]);
        func_00139660(&self->spr[i]);
        func_00139688(&self->spr[i]);
        func_00138c68(&self->spr[i], func_0023a950(&self->spr[0].seq), func_0023a988(&self->spr[0].seq));
    }
    func_00138c68(&self->spr[2], func_0023aa18(&self->spr[0].seq), func_0023aa38(&self->spr[0].seq));
    W2418_setParent(&self->spr[0], 0);
    func_00138c40(&self->spr[0], self->x, self->y);
    func_00151bd8(self);
    self->f2892 = -1.0f;
}
}  // namespace n001516b0

// 001519b8 (was gap, never written)
namespace n001519b8 {
void func_0014fdd0(u8*) asm("_Z13func_0014fdd0jjjjjjjj");
void func_001519b8(u8* p) asm("func_001519b8");
void func_001519b8(u8* p) {
    func_0014fdd0(p);
    if (p) ((void (*)(u8*))(*(void***)p)[4])(p);
}
}  // namespace

// 001519f8 (was src/anon/batch_w68.cpp)
namespace n001519f8 {
/* ---- 001519f8 ---- */
s32 func_0023aa98(void*) asm("func_0023aa98");
f32 func_00151690(void*) asm("func_00151690");
// scale_ratio_2888_2880
void func_00239f18(void*, f32) asm("func_00239f18");
// obj_set_float312_and_flags
void func_00138c68(void*, s32, u32) asm("func_00138c68");
/*TARGET 001519f8*/
void func_001519f8(u8* p) asm("func_001519f8");
void func_001519f8(u8* p) {
    u8* a = p + 1272;
    u8* b = p + 1680;
    u8* c = p + 2064;
    f32 n = (f32)func_0023aa98(p + 2088);
    func_00239f18(a, func_00151690(p));  // obj_set_float312_and_flags
    func_00239f18(b, 1.0f - func_00151690(p));  // obj_set_float312_and_flags
    func_00138c68(c, (s32)(func_00151690(p) * n), 0);
}
}  // namespace n001519f8

// 00151aa8 (was src/anon/batch_w55.cpp)
namespace n00151aa8 {
// zero_global_byte_g
void func_0014fcd8(u8*) asm("func_0014fcd8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00151c70(u8*) asm("func_00151c70");
void func_00138c40(u8*, u32, u32) asm("func_00138c40");
void func_001519f8(u8*) asm("func_001519f8");
/*TARGET 00151aa8*/
// 0x001407d0: definition moved into src/anon/unit_0013fca8.cpp

void func_00151aa8(u8* p) asm("func_00151aa8");
// 0x001407d0: definition moved into src/anon/unit_0013fca8.cpp

void func_00151aa8(u8* p) {
    func_0014fcd8(p);
    if (*(s32*)(p + 2896) == 1) {
        if (!func_00139d78(p + 840)) {
            func_00151c70(p);
        }
        return;
    }
    func_00138c40(p + 840, *(u32*)(p + 32), *(u32*)(p + 36));
    f32 f = **(f32**)(p + 2884);
    *(f32*)(p + 2888) = f;
    if (*(f32*)(p + 2892) != f) func_001519f8(p);
    *(f32*)(p + 2892) = *(f32*)(p + 2888);
}
}  // namespace n00151aa8

// 00151b40 (was src/anon/batch_w14.cpp)
namespace n00151b40 {
// zero_fields_0_4_6_8
void func_00138c10(void*, s32) asm("func_00138c10");
/*TARGET 00151b40*/
// 0x001418e8: definition moved into src/anon/unit_00141458.cpp

// 0014dc08: moved to src/anon/unit_0014d680.cpp

void func_00151b40(u8* p) asm("func_00151b40");
// 0x001418e8: definition moved into src/anon/unit_00141458.cpp

// 0014dc08: moved to src/anon/unit_0014d680.cpp

void func_00151b40(u8* p) {
    func_00138c10(p + 840, 0);
    func_00138c10(p + 2472, 6);
}
}  // namespace n00151b40

// 00151b78 (was src/anon/auto80_199_queue.cpp)
namespace n00151b78 {
/*TARGET 00151b78*/
void func_00151b78(u32 a0) asm("_Z13func_00151b78j");
void func_00151b78(u32 a0) {
    u32 s1 = a0 + 840;
    func_00138c10(s1, 4);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 2472;
    func_00138c10(s0, 10);
    *(s32*)(s0 + 392) = s2;
}
}  // namespace n00151b78

// 00151bd8 (was src/anon/tiny_more2.cpp)
namespace n00151bd8 {
/*TARGET 00151bd8*/
void func_00151bd8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00151bd8jjjj");
void func_00151bd8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; *(u32*)((u32)a0 + (1232)) = (u32)((s32)4); *(u32*)((u32)a0 + (2864)) = (u32)((s32)10); }
}  // namespace n00151bd8

// 00151bf0 (was src/anon/auto80_199_queue.cpp)
namespace n00151bf0 {
/*TARGET 00151bf0*/
void func_00151bf0(u32 a0) asm("_Z13func_00151bf0j");
void func_00151bf0(u32 a0) {
    *(u32*)(a0 + 2896) = 1;

    u32 s0 = a0;
    u32 s1 = a0 + 840;

    func_00138c10(s1, 5);
    s0 = s0 + 2472;
    func_00138c10(s0, 11);

    s32 v = -1;
    *(s32*)(s1 + 392) = v;
    *(s32*)(s0 + 392) = v;
}
}  // namespace n00151bf0

// 00151c50 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00151c50 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 00151c50*/
u32 func_00151c50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00151c50jjjj");
u32 func_00151c50(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)r4 + (840));
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00151c50

// 00151c70 (was src/anon/batch_w77.cpp)
namespace n00151c70 {
typedef void (*VFn)(void*);
struct Elem { void** vt; u8 pad[392]; u32 f396; u32 f400; u8 pad2[4]; };
struct Own { void** vt; u8 pad[44]; u8 sub[792]; Elem e[5]; };
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
void func_001396b0(void*) asm("func_001396b0");
void func_0031a260(void*, s32) asm("func_0031a260");
/*TARGET 00151c70*/
void func_00151c70(Own* p) asm("func_00151c70");
void func_00151c70(Own* p)
{
    if (func_00139d78(p)) ((VFn)p->vt[5])(p);
    if (func_00139d78(p->sub)) func_00139510(p->sub);
    Elem* e = p->e;
    for (s32 i = 0; i < 5; i++, e++) {
        if (func_00139d78(e)) {
            p->e[i].f396 = 0;
            func_001396b0(e);
            if (p->e[i].f396) {
                p->e[i].f400 = 0;
                func_001396b0(e);
                if (p->e[i].f400) func_0031a260(e, 0);
            }
            ((VFn)p->e[i].vt[5])(e);
        }
    }
}
}  // namespace n00151c70

// 00151d48 (was src/anon/batch_wcx.cpp)
namespace n00151d48 {
// 0x00140150: definition moved into src/anon/unit_0013fca8.cpp

s32 func_0015b4f8(void*, u32, s32*) asm("func_0015b4f8");
void func_00239c38(void*, s32) asm("func_00239c38");
s32 func_0023aa98(void*) asm("func_0023aa98");
extern u8 D_0034a5e8[] asm("D_0034a5e8");
struct E344 { u8 d[344]; };
struct S151 { u8 pad[456]; E344 e[7]; s32 arr[7]; u32 key; s32 n; };
/*TARGET 00151d48*/
// 00151d48: load up to 7 entries and keep a running total of their sizes
void func_00151d48(S151* p) asm("func_00151d48");
// 00151d48: load up to 7 entries and keep a running total of their sizes
void func_00151d48(S151* p)
{
    s32 buf[8];
    s32 sum = 0;
    p->n = func_0015b4f8(D_0034a5e8, p->key, buf);
    for (s32 i = 0; i < p->n; i++) {
        func_00239c38(&p->e[i], buf[i]);
        sum += func_0023aa98(&p->e[i]);
        p->arr[i] = sum;
    }
}
}  // namespace n00151d48

// 00151df0 (was src/anon/batch_w95.cpp)
namespace n00151df0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void wtarget_00151df0(u32, u32, u32, u32) asm("_Z16wtarget_00151df0jjjj");
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
s32 func_00152100(u32, u32) asm("func_00152100");
void func_001520c0(u32, u32) asm("func_001520c0");
u32 func_0013e678(void) asm("func_0013e678");
u32 func_0013a7e8(u32) asm("func_0013a7e8");
void func_001386e0(u8*, u32, u32, u32, u32, u32) asm("func_001386e0");
void func_001396b0(u8*) asm("func_001396b0");
void func_0031a260(u8*, u32) asm("func_0031a260");
void func_00138c40(u8*, u32, u32) asm("func_00138c40");
void func_00239988(u8*, u32, u32) asm("func_00239988");
void func_00239bf8(u8*, u32) asm("func_00239bf8");
void func_00151d48(u8*) asm("func_00151d48");
u32 func_0023aa78(u8*) asm("func_0023aa78");
void func_0014fc40(u8*, u32, u32, u32, u32, u32) asm("func_0014fc40");
/*TARGET 00151df0*/
void wtarget_00151df0(u32 a, u32 b, u32, u32) asm("_Z16wtarget_00151df0jjjj");
void wtarget_00151df0(u32 a, u32 b, u32, u32) {
    u8* p = (u8*)a;
    if (func_00152100(a, b)) {
        func_001520c0(a, b);
        return;
    }
    *(u32*)(p + 2892) = b;
    u32 w = func_0013e678();
    u32 m = func_0013a7e8(0);
    u8* q = p + 48;
    func_001386e0(q, 4600, m, w, 17, 7);
    *(u32*)(q + 396) = 0;
    func_001396b0(q);
    if (*(u32*)(q + 396)) {
        *(u32*)(q + 400) = 0;
        func_001396b0(q);
        if (*(u32*)(q + 400)) func_0031a260(q, 0);
    }
    func_00138c40(q, 0, *(u32*)(p + 36));
    u8* r = p + 456;
    for (s32 i = 0; i < 7; i++) {
        func_00239988(r, m, w);
        func_00239bf8(r, 28);
        r += 344;
    }
    func_00151d48(p);
    func_0014fc40(p, 17, func_0023aa78(p + 72), 4600, 7, 0);
}
}  // namespace n00151df0

// 00151f40 (was src/anon/batch_w63.cpp)
namespace n00151f40 {
typedef void (*VFn)(void*);
// clear_quads_set_flags
void func_0014fcd8(void*) asm("func_0014fcd8");
s32 func_00139538(void*) asm("func_00139538");
void func_00138c40(void*, s32, u32) asm("func_00138c40");
void func_0023acd8(void*) asm("func_0023acd8");
/*TARGET 00151f40*/
void func_00151f40(u8* p) asm("func_00151f40");
void func_00151f40(u8* p) {
    func_0014fcd8(p);
    if (func_00139538(p + 48)) {
        (*(VFn*)(*(u8**)p + 20))(p);
        return;
    }
    func_00138c40(p + 48, 0, *(u32*)(p + 36));
    for (s32 i = 0; i < *(s32*)(p + 2896); i++)
        func_0023acd8(p + 456 + i * 344);
}
}  // namespace n00151f40

// 00151fe0 (was gap, never written)
namespace n00151fe0 {
void func_001391f8(u8*) asm("func_001391f8");
void func_00138c50(u8*, s32*, s32*) asm("func_00138c50");
void func_00138cd0(u8*, s32*, s32*) asm("func_00138cd0");
void func_0023ade0(u8*) asm("func_0023ade0");
void func_00151fe0(u8* p) asm("func_00151fe0");
void func_00151fe0(u8* p) {
    s32 i = 0;
    u8* w = p + 48;
    func_001391f8(p);
    s32 x, y, dx, dy;
    dx = 0; dy = 0; x = 0; y = 0;
    func_00138c50(w, &x, &y);
    func_00138cd0(w, &dx, &dy);
    x += dx; y += dy;
    for (; i < *(s32*)(p + 2896); i++) {
        u8* e = p + 456 + i * 344;
        *(s32*)(e + 328) = x + ((s32*)(p + 2864))[i];
        *(s32*)(e + 332) = y;
        func_0023ade0(e);
    }
}
}  // namespace

// 001520c0 (was src/anon/batch_w20.cpp)
namespace n001520c0 {
void func_00138c10(void*, u32) asm("func_00138c10");
void func_00151d48(void*) asm("func_00151d48");
/*TARGET 001520c0*/
void func_001520c0(u8* p, s32 a) asm("func_001520c0");
void func_001520c0(u8* p, s32 a) {
    *(s32*)(p + 0xb4c) += a;
    func_00138c10(p + 48, 17);
    func_00151d48(p);
}
}  // namespace n001520c0

// 00152100 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00152100 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 00152100*/
u32 func_00152100(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00152100jjjj");
u32 func_00152100(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)r4 + (48));
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00152100

// 00152120 (was src/anon/batch_wcx.cpp)
namespace n00152120 {
s32 func_0015b4f8(void*, u32, s32*) asm("func_0015b4f8");
void func_00239c38(void*, s32) asm("func_00239c38");
s32 func_0023aa98(void*) asm("func_0023aa98");
extern u8 D_0034a630[] asm("D_0034a630");
struct E344 { u8 d[344]; };
struct S151 { u8 pad[456]; E344 e[7]; s32 arr[7]; u32 key; s32 n; };
/*TARGET 00152120*/
void func_00152120(S151* p) asm("func_00152120");
void func_00152120(S151* p)
{
    s32 buf[8];
    s32 sum = 0;
    p->n = func_0015b4f8(D_0034a630, p->key, buf);
    for (s32 i = 0; i < p->n; i++) {
        func_00239c38(&p->e[i], buf[i]);
        sum += func_0023aa98(&p->e[i]);
        p->arr[i] = sum;
    }
}
}  // namespace n00152120

// 001521c8 (was src/anon/batch_w96.cpp)
namespace n001521c8 {
u32 func_001524e8(u32, u32) asm("func_001524e8");
void func_00152498(u32, u32) asm("func_00152498");
u32 func_0013e678(void) asm("func_0013e678");
u32 func_0013a7e8(u32) asm("func_0013a7e8");
void func_001386e0(u32, u32, u32, u32, u32, u32) asm("func_001386e0");
void func_001396b0(u32) asm("func_001396b0");
void func_0031a260(u32, u32) asm("func_0031a260");
void func_00138c40(u32, u32, u32) asm("func_00138c40");
void func_00239988(u32, u32, u32) asm("func_00239988");
void func_00239bf8(u32, u32) asm("func_00239bf8");
void func_00152120(u32) asm("func_00152120");
u32 func_0023aa78(u32) asm("func_0023aa78");
void func_0014fc40(u32, u32, u32, u32, u32, u32) asm("func_0014fc40");
// push_entry_onto_slot_list

// Builds the widget: icons, 7 child panels, then hands off to the shared init.
void wtarget_001521c8(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_001521c8jjjj");
/*TARGET 001521c8*/
void wtarget_001521c8(u32 self, u32 id, u32, u32) asm("_Z16wtarget_001521c8jjjj");
void wtarget_001521c8(u32 self, u32 id, u32, u32) {
    u32 obj, s3, s4, p;
    s32 i;
    if (func_001524e8(self, id)) {
        func_00152498(self, id);
        return;
    }
    *(u32*)(self + 2892) = id;
    s4 = func_0013e678();
    s3 = func_0013a7e8(0);
    obj = self + 48;
    func_001386e0(obj, 4500, s3, s4, 48, 7);
    *(u32*)(obj + 396) = 0;
    func_001396b0(obj);
    if (*(u32*)(obj + 396) != 0) {
        *(u32*)(obj + 400) = 0;
        func_001396b0(obj);
        if (*(u32*)(obj + 400) != 0) {
            func_0031a260(obj, 0);
        }
    }
    func_00138c40(obj, 0, *(u32*)(self + 36));
    p = self + 456;
    for (i = 6; i >= 0; i--) {
        func_00239988(p, s3, s4);
        func_00239bf8(p, 38);
        p += 344;
    }
    func_00152120(self);
    func_0014fc40(self, 14, func_0023aa78(self + 72), 4500, 7, 0);
}
}  // namespace n001521c8

// 00152318 (was src/anon/batch_w64.cpp)
namespace n00152318 {
typedef void (*VFn)(void*);
// 0x00137560: definition moved into src/anon/unit_001374c8.cpp

// ---------------------------------------------------------------------------
void func_0014fcd8(u8*) asm("func_0014fcd8");
s32 func_00139538(u8*) asm("func_00139538");
void func_00138c40(u8*, s32, u32) asm("func_00138c40");
void func_0023acd8(u8*) asm("func_0023acd8");
/*TARGET 00152318*/
void func_00152318(u8* p) asm("func_00152318");
void func_00152318(u8* p) {
    func_0014fcd8(p);
    if (func_00139538(p + 48)) {
        (*(VFn*)(*(u8**)p + 20))(p);
        return;
    }
    func_00138c40(p + 48, 0, *(u32*)(p + 36));
    for (s32 i = 0; i < *(s32*)(p + 2896); i++) func_0023acd8(p + 456 + i * 344);
}
}  // namespace n00152318

// 001523b8 (was gap, never written)
namespace n001523b8 {
void func_001391f8(u8*) asm("func_001391f8");
void func_00138c50(u8*, s32*, s32*) asm("func_00138c50");
void func_00138cd0(u8*, s32*, s32*) asm("func_00138cd0");
void func_0023ade0(u8*) asm("func_0023ade0");
void func_001523b8(u8* p) asm("func_001523b8");
void func_001523b8(u8* p) {
    s32 i = 0;
    u8* w = p + 48;
    func_001391f8(p);
    s32 x, y, dx, dy;
    dx = 0; dy = 0; x = 0; y = 0;
    func_00138c50(w, &x, &y);
    func_00138cd0(w, &dx, &dy);
    x += dx; y += dy;
    for (; i < *(s32*)(p + 2896); i++) {
        u8* e = p + 456 + i * 344;
        *(s32*)(e + 328) = x + ((s32*)(p + 2864))[i];
        *(s32*)(e + 332) = y;
        func_0023ade0(e);
    }
}
}  // namespace

// 00152498 (was src/anon/tiny_auto80_queue.cpp)
namespace n00152498 {
void func_00152120(...) asm("func_00152120");
u32 func_00138c10(...) asm("func_00138c10");
/*TARGET 00152498*/
void func_00152498(Obj00152498* a0, u32 a1) asm("_Z13func_00152498P11Obj00152498j");
void func_00152498(Obj00152498* a0, u32 a1) {
    if (a0->field_b4c != a1) {
        func_00138c10((u8*)a0 + 48, (a0->field_b4c = a1, 48));
        func_00152120((u32)a0);
    }
}
}  // namespace n00152498

// 001524e8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001524e8 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 001524e8*/
u32 func_001524e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001524e8jjjj");
u32 func_001524e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)r4 + (48));
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001524e8

// 00152508 (was src/anon/batch_w59.cpp)
namespace n00152508 {
// 0x0010cce0: definition moved into src/anon/unit_0010b978.cpp

// --- 0013e2d8
u32 func_0013a7e8(u32) asm("func_0013a7e8");
// --- 00152508
u32 func_0013d7e0(void) asm("func_0013d7e0");
void func_00138d60(u8*, u32, u32, u32, u32, u32, u32) asm("func_00138d60");
void func_0023aa78(u8*) asm("func_0023aa78");
/*TARGET 00152508*/
void func_00152508(u8* p, u32 a, u32 b, u32 c, u32 d) asm("func_00152508");
void func_00152508(u8* p, u32 a, u32 b, u32 c, u32 d) {
    u32 r = func_0013a7e8(1);
    func_00138d60(p, 9000, r, func_0013d7e0(), a, c, 14);
    *(u32*)(p + 372) = d;
    *(u32*)(p + 424) = 14;
    func_0023aa78(p + 24);
}
}  // namespace n00152508

// 00152598 (was src/anon/batch_w2.cpp)
namespace n00152598 {
struct Pair32 { u32 a, b; };
/*TARGET 00152598*/
u32 func_00152598(u32 a0, s32 i, s32 second, Pair32* tbl) asm("func_00152598");
u32 func_00152598(u32 a0, s32 i, s32 second, Pair32* tbl) {  // pair_get
    if (!second) return tbl[i].a;
    return tbl[i].b;
}
}  // namespace n00152598

// 001525b8 (was src/anon/batch_w91.cpp)
namespace n001525b8 {
// --- 001525b8
extern char D_0034a678[] asm("D_0034a678");
extern char D_0034a698[] asm("D_0034a698");
u32 func_00152598(u8*, u32, u32, char*) asm("func_00152598");
void func_00152508(u8*, u32, u32, u32, u32) asm("func_00152508");
/*TARGET 001525b8*/
void func_001525b8(u8* p, s32 mode, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) asm("func_001525b8");
void func_001525b8(u8* p, s32 mode, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    u32 r = 0;
    switch (mode) {
    case 0: r = func_00152598(p, e, c, D_0034a678); break;
    case 1: r = func_00152598(p, e, c, D_0034a698); break;
    }
    *(u32*)(p + 448) = e;
    *(u32*)(p + 444) = d;
    *(u32*)(p + 440) = c;
    *(u32*)(p + 436) = a;
    func_00152508(p, r, a, b, f);
}
}  // namespace n001525b8

// 00152688 (was src/anon/batch_w60.cpp)
namespace n00152688 {
extern char D_0036b248[] asm("D_0036b248");
void* func_00192cc0(void*, const char*, u32) asm("func_00192cc0");
void func_001a98e8(void*, s32, void*, u32, s32) asm("func_001a98e8");
void func_001a9ae8(void*, void*, void*, void*) asm("func_001a9ae8");
/*TARGET 00152688*/
void func_00152688(u8* a, void* b, void* c, void* d) asm("func_00152688");
void func_00152688(u8* a, void* b, void* c, void* d) {
    char name[16];
    u8 obj[96];
    void* r = func_00192cc0(name, D_0036b248, *(u32*)(a + 444));
    func_001a98e8(obj, 1, r, *(u32*)(a + 424), 0);
    func_001a9ae8(obj, b, c, d);
}
}  // namespace n00152688

// 00152718 (was src/anon/auto80_199_queue.cpp)
namespace n00152718 {
/*TARGET 00152718*/
void func_00152718(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00152718jjjj");
void func_00152718(u32 a0, u32 a1, u32 a2, u32 a3) {
    u8 buf[96];
    u32 s1 = a0 + 24;
    u32 s2 = a1;
    u32 s3 = a2;
    u32 s4 = a3;

    u32 n = *(u32*)(a0 + 440);
    if (n == 0) {
        return;
    }

    volatile u32* vp = (u32*)a0;
    u32 a1v = vp[107];
    u32 a3v = vp[106];
    func_001a98e8(buf, a1v, n, a3v, 0);

    u32 s0 = s2 + func_0023aa18(s1);
    u32 v = func_0023aa38(s1);
    func_001a9ae8(buf, s0, s3 + v + 17, s4);
}
}  // namespace n00152718

// 001527b8 (was src/anon/auto80_199_queue.cpp)
namespace n001527b8 {
/*TARGET 001527b8*/
void func_001527b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001527b8jjjj");
void func_001527b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u8 buf[96];
    u32 s2 = a3;
    u32 s0 = a1;
    u32 s1 = a2;

    func_001a98e8(buf, 1, *(u32*)(a0 + 436), *(u32*)(a0 + 424), 1);
    func_001a9ae8(buf, s0, s1, s2);
}
}  // namespace n001527b8

// 00152820 (was src/anon/batch_w87.cpp)
namespace n00152820 {
// 0x0013bb58: definition moved into src/anon/unit_0013a8b8.cpp

// ---- 0x152820: screen rect of a sprite ----
void func_0023a9c0(void*, s32*, s32*) asm("func_0023a9c0");
u32 func_0023a918(void*) asm("func_0023a918");
s32 func_0023aa98(void*) asm("func_0023aa98");
/*TARGET 00152820*/
void func_00152820(u8* p, s32* x, s32* y, s32* r, s32* b, u32* fl) asm("func_00152820");
void func_00152820(u8* p, s32* x, s32* y, s32* r, s32* b, u32* fl) {
    s32 ox = 0;
    s32 oy = 0;
    u8* o = p + 24;
    func_0023a9c0(o, &ox, &oy);
    *fl = *(u32*)(p + 420);
    u32 v = func_0023a918(o);
    *fl = (*fl & 0xffffff) | (v & 0xff000000);
    *x = *(s32*)(p + 368) + ox;
    *y = *(s32*)(p + 372) + oy;
    *r = *x + func_0023aa98(o);
    *b = *y;
}
}  // namespace n00152820

// 00152910 (was src/anon/auto80_199_queue.cpp)
namespace n00152910 {
void func_00152718(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00152718jjjj");
void func_001527b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001527b8jjjj");
/*TARGET 00152910*/
void func_00152910(u32 a0) asm("_Z13func_00152910j");
void func_00152910(u32 a0) {
    u32 s0 = a0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    func_001390c0(s0);

    func_00152820(s0, (u32)&v0, (u32)&v1, (u32)&v2, (u32)&v3, (u32)&v4);

    func_001527b8(s0, v0, v1, v4);
    func_00152688(s0, v2, v3, v4);
    func_00152718(s0, v0, v1, v4);
}
}  // namespace n00152910

// 00152990 (was src/anon/batch_wcx.cpp)
namespace n00152990 {
// 0x0014ad58: definition moved into src/harata/libdk/fade.cpp
extern u8 D_0034a6b8[] asm("D_0034a6b8");
u32 func_00152598(u8*, u32, u32, u8*) asm("func_00152598");
void func_00152508(u8*, u32, u32, u32, u32) asm("func_00152508");
/*TARGET 00152990*/
void func_00152990(u8* p, u32 a1, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) asm("func_00152990");
void func_00152990(u8* p, u32 a1, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    u32 r = func_00152598(p, f, d, D_0034a6b8);
    *(u32*)(p + 448) = f;
    *(u32*)(p + 444) = e;
    *(u32*)(p + 440) = d;
    *(u32*)(p + 436) = b;
    func_00152508(p, r, b, c, g);
}
}  // namespace n00152990

// 00152a30 (was src/anon/auto80_199_queue.cpp)
namespace n00152a30 {
void func_00152718(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00152718jjjj");
void func_001527b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001527b8jjjj");
/*TARGET 00152a30*/
void func_00152a30(u32 a0) asm("_Z13func_00152a30j");
void func_00152a30(u32 a0) {
    u32 s0 = a0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    func_001390c0(s0);
    func_00152820(s0, (u32)&v0, (u32)&v1, (u32)&v2, (u32)&v3, (u32)&v4);

    func_001527b8(s0, v0, v1, v4);
    if (*(u32*)(s0 + 448) != 0) {
        func_00152688(s0, v2, v3, v4);
    }
    func_00152718(s0, v0, v1, v4);
}
}  // namespace n00152a30

// 00152ab8 (was src/anon/batch_w203.cpp)
namespace n00152ab8 {
void func_00152508(void*, u32, u32, u32, u32) asm("func_00152508");
struct W203C { u8 p[0x1b4]; u32 a, b, c, d; };
/*TARGET 00152ab8*/
void func_00152ab8(W203C* a, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00152ab8");
void func_00152ab8(W203C* a, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  a->c = a5; a->b = a4; a->a = a2; a->d = a6;
  func_00152508(a, 108, a2, a3, a7);
}
}  // namespace n00152ab8

// 00152ae8 (was src/anon/auto80_199_queue.cpp)
namespace n00152ae8 {
void func_001527b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001527b8jjjj");
/*TARGET 00152ae8*/
void func_00152ae8(u32 a0) asm("_Z13func_00152ae8j");
void func_00152ae8(u32 a0) {
    u32 s0 = a0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    func_001390c0(s0);
    func_00152820(s0, (u32)&v0, (u32)&v1, (u32)&v2, (u32)&v3, (u32)&v4);

    func_001527b8(s0, v0, v1, v4);
    func_00152688(s0, v2, v3, v4);
}
}  // namespace n00152ae8

// 00152b50 (was src/anon/batch_w2433.c)
namespace n00152b50 {
// 0x001cbe30: definition moved into src/anon/unit_001ca8e0.cpp

/* 00152b50: three sub-inits; fields keep the store order, the c rmw goes through a cast */
s32 func_001391c8(void*, s32, s32) asm("func_001391c8");
typedef struct W2433_S { u32 a; volatile u32 b; volatile u32 c; volatile u32 d; volatile u32 e; } W2433_S;
typedef struct W2433_B {
    u8 pad[24]; W2433_S s1; u8 pad2[9644 - 24 - 20]; W2433_S s2; u8 pad3[12064 - 9644 - 20]; W2433_S s3;
} W2433_B;
/*TARGET 00152b50*/
void func_00152b50(W2433_B* p) asm("func_00152b50");
void func_00152b50(W2433_B* p) {
    { W2433_S* s1 = &p->s1; p->s1.a = 0; s1->b = 0; p->s1.c = 0; *(u32*)((u8*)s1 + 8) |= 1; s1->d = 0; p->s1.e = 0; }
    { W2433_S* s2 = &p->s2; p->s2.a = 0; s2->b = 0; p->s2.c = 0; *(u32*)((u8*)s2 + 8) |= 1; s2->d = 0; p->s2.e = 0; }
    { W2433_S* s3 = &p->s3; p->s3.a = 0; s3->b = 0; p->s3.c = 0; *(u32*)((u8*)s3 + 8) |= 1; s3->d = 0; p->s3.e = 0; }
    func_001391c8(p, 9000, 0);
}
}  // namespace n00152b50

// 00152bd8 (was src/anon/batch_w2423.cpp)
namespace n00152bd8 {
// 00152bd8 (w2423): three ring-buffer queues. Queue reference plus the ready test written through self, expect on the loop-exit test.
struct W1631Entry {
    u8 pad0[0x1c4];
    s32 hasExt;     // 0x1c4
    s32 b;          // 0x1c8
    s32 a;          // 0x1cc
    s32 c;          // 0x1d0
    s32 d;          // 0x1d4
    u8 info[64];    // 0x1d8
    u8 ext[64];     // 0x218
};
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_001525b8(W1631Entry*, s32, s32, void*, void*, s32, s32, s32) asm("func_001525b8");
s32 func_00152990(W1631Entry*, s32, s32, void*, void*, s32, s32, s32) asm("func_00152990");
s32 func_00152ab8(W1631Entry*, s32, s32, void*, void*, s32, s32, s32) asm("func_00152ab8");
typedef s32 (*W1631EntryFn)(W1631Entry*, s32, s32, void*, void*, s32, s32, s32);
template <int N> struct W1631Ring {
    s32 w;
    s32 r;
    W1631Entry e[N];
    bool isEmpty() { return r == w; }
    W1631Entry* front() { return &e[r]; }
    W1631Entry* pop() {
        s32 idx = r;
        r = (idx + 1) % N;
        return &e[idx];
    }
};
template <int N> struct W1631Queue {
    W1631Entry* cur;
    s32 acc;
    u32 flags;
    W1631Ring<N> ring;
    template <W1631EntryFn fn> __attribute__((always_inline)) void process() {
        s32 i;
        cur = ring.front();
        for (i = 0; i < 4; i++) {
            W1631Entry* e = ring.pop();
            acc += fn(e, e->a, e->b, e->info, e->hasExt ? e->ext : 0, e->c, e->d, acc);
            s32 em = ring.isEmpty();
            if ((em)) break;
        }
        flags &= ~1;
    }
    __attribute__((always_inline)) void check() {
        if (cur && !func_00139d78(cur)) {
            cur = 0;
            acc = 0;
            flags |= 1;
        }
    }
};
struct W1631Disp {
    u8 pad0[0x18];
    W1631Queue<16> q0;  // 0x18
    W1631Queue<4> q1;   // 0x25ac
    W1631Queue<4> q2;   // 0x2f20
};
/*TARGET 00152bd8*/
void func_00152bd8(W1631Disp* self) asm("func_00152bd8");
void func_00152bd8(W1631Disp* self) {
    {
        W1631Queue<16>& q = self->q0;
        if (!self->q0.ring.isEmpty() && (s32)(self->q0.flags & 1) == 1) q.process<func_001525b8>();
        q.check();
    }
    {
        W1631Queue<4>& q = self->q1;
        if (!self->q1.ring.isEmpty() && (s32)(self->q1.flags & 1) == 1) q.process<func_00152990>();
        q.check();
    }
    {
        W1631Queue<4>& q = self->q2;
        if (!self->q2.ring.isEmpty() && (s32)(self->q2.flags & 1) == 1) q.process<func_00152ab8>();
        q.check();
    }
}
}  // namespace n00152bd8

// 00152f40 (was src/anon/batch_w3873_nsa.cpp)
namespace n00152f40 {
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0034a700[] asm("D_0034a700");
extern u8 D_0034a760[] asm("D_0034a760");
extern u8 D_0034a740[] asm("D_0034a740");
extern u8 D_0034a720[] asm("D_0034a720");
void func_0031a838(void*) asm("func_0031a838");
void func_00239700(void*) asm("func_00239700");
void func_0031cc28(void*) asm("func_0031cc28");
void func_00152b50(void*) asm("func_00152b50");
struct HeapA1577 { virtual void* Alloc(u32, u32); };
struct SysA1577 { u8 pad[20]; HeapA1577* heap; };
extern SysA1577* D_00347f80 asm("D_00347f80");
struct M1_1577 { u8 d[12]; M1_1577() { func_0031a838(this); } };
struct M2_1577 { u8 d[384]; M2_1577() { func_00239700(this); } };
struct M3_1577 { u32 d; M3_1577() { func_0031cc28(this); } };
struct EA0_1577 { u32 vt; EA0_1577() { vt = (u32)D_00347f98; } };
struct EA1577 : EA0_1577 { u32 f4, f8; M1_1577 m12; };
struct EBv1577 : EA1577 { EBv1577() { vt = (u32)D_00347e60; } };
struct EB1577 : EBv1577 {
    M2_1577 m24;
    u32 f408;
    u8 pad[188];
    EB1577() { f408 = 0; }
};
template <int K> struct EC1577 : EB1577 { EC1577(); };
template <> inline EC1577<0>::EC1577() { vt = (u32)D_0034a760; }
template <> inline EC1577<1>::EC1577() { vt = (u32)D_0034a740; }
template <> inline EC1577<2>::EC1577() { vt = (u32)D_0034a720; }
struct P1577 { u32 a, b; void clr() { a = 0; b = 0; } };
static inline void clrP(P1577& r) { r.b = 0; r.a = 0; }
template <int K, int N> struct In1577 {
    P1577 p;
    EC1577<K> e[N];
    In1577() { p.clr(); }
};
template <int K, int N> struct Grp1577 {
    M3_1577 s;
    In1577<K, N> in;
    u8 pad[8];
};
struct ObjB1577 { u32 vt; u32 f4, f8, f12; ObjB1577() { f12 = 0; vt = (u32)D_0034a700; } };
struct Obj152f40 : ObjB1577 {
    u8 pad[16];
    Grp1577<0, 16> g0;
    Grp1577<1, 4> g1;
    Grp1577<2, 4> g2;
};
extern Obj152f40* volatile D_0034a6f0 asm("D_0034a6f0");
void u_tail0_00152f40(void) asm("_Z16u_tail0_00152f40v");
void u_tail0_00152f40(void) { register Obj152f40* o asm("$20") = (Obj152f40*)D_00347f80->heap->Alloc(14484, 0); new (o) ObjB1577; {EC1577<0>* eb; asm("addiu %0,%1,44" : "=r"(eb) : "r"(o));P1577* p; asm("addiu %0,%1,36" : "=r"(p) : "r"(o)); func_0031cc28(&o->g0.s); new (eb) EC1577<0>[16]; p->clr();} {P1577* p=&o->g1.in.p; func_0031cc28(&o->g1.s); new (o->g1.in.e) EC1577<1>[4]; p->clr();} {P1577* p=&o->g2.in.p; func_0031cc28(&o->g2.s); new (o->g2.in.e) EC1577<2>[4]; p->clr();} D_0034a6f0 = o; func_00152b50(D_0034a6f0); }
}  // namespace n00152f40

// 00153100 (was src/anon/batch_w21.cpp)
namespace n00153100 {
extern void** D_0034a6f0 asm("D_0034a6f0");
/*TARGET 00153100*/
// 0x0014ad20: definition moved into src/harata/libdk/fade.cpp

// Release the object held in D_0034a6f0 (virtual slot 4) and clear the pointer.
void func_00153100(void) asm("func_00153100");
// 0x0014ad20: definition moved into src/harata/libdk/fade.cpp

// Release the object held in D_0034a6f0 (virtual slot 4) and clear the pointer.
void func_00153100(void) {
    void** o = D_0034a6f0;
    if (o) {
        (*(void (**)(void*))((u8*)*o + 16))(o);
        D_0034a6f0 = 0;
    }
}
}  // namespace n00153100

// 00153140 (was src/anon/tiny.cpp)
namespace n00153140 {
// memset
void func_00139858(s32) asm("_Z13func_00139858i");
/*TARGET 00153140*/
// 0x0013e8a8: definition moved into src/anon/unit_0013dfb8.cpp
void func_00153140(BD_VALUE* bd) asm("_Z13func_00153140P8BD_VALUE");
// 0x0013e8a8: definition moved into src/anon/unit_0013dfb8.cpp
void func_00153140(BD_VALUE* bd) { func_00139858(14); }
}  // namespace n00153140

// .rodata 0x36b244-0x36b250: gas pad + a format string that the code reads as extern D_
extern "C" const u32 D_0036b244 = 0;
extern const char R_0036b248[8] asm("D_0036b248") __attribute__((aligned(4))) = "%2d";

