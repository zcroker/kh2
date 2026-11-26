#include "../common/types.h"

namespace w245_a {
struct M22 { f32 m[16]; } __attribute__((aligned(16)));
extern "C" {
union Cam22 { u8* p; f32 f; };
extern Cam22 D_01d9e6e8;
extern M22 D_01d9e730;
void sceVu0InversMatrix(void*, void*);  // convert_vectors_to_scalar
}
static inline void ScaleRow(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
extern "C" {
void func_00201898(u8* o, u32 a1, u8* x);  // 0x00201898: definition moved into src/anon/unit_00200578.cpp
}
}

namespace w245_b {
struct QW { f32 f[4]; } __attribute__((aligned(16)));
struct P { QW pos; u8 pad[0x40-16]; QW vel; };
extern "C" {
union FU { f32 f; u8 c; };
extern FU D_00349e10;
s32 func_001c5f38(P*);
void func_001c6748(P*);
}
static inline void Scale(QW* d, QW* a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
static inline void Add(QW* d, QW* a, QW* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
extern "C" {
void func_001c6320(P* s);  // 0x001c6320: definition moved into src/anon/unit_001c5b90.cpp
}
}

namespace w245_c {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QW {
    f32 x, y, z, w;
    QW() {}
    QW(const QW& o) { QCOPY(this, &o); }
    QW& operator=(const QW& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline QW Scale(const QW& a, f32 s) {
    QW r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct Obj { u8 pad[320]; u8 sub[16]; };
extern "C" {
QW func_0018df90();
void func_0016aef0(Obj*, QW*);
void YS__BTLOBJ__set_hitback(Obj*, QW*, f32);
void func_0017f488(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, s32, f32, f32);
void func_00176a60(Obj*, f32);
// 00176680: moved to src/yasui/libys/party.cpp
}
}

inline void* operator new(unsigned int, void* p) { return p; }
namespace w245_d {
struct V4 { f32 x, y, z, w; V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } };
extern "C" {
extern V4 D_01e2bd20;
extern V4 D_01e2bd30;
extern V4 D_01e2bd40;
void wtarget_002c5298(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_002c5298jjjj");
void wtarget_002c5298(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002c5298: definition moved into src/anon/unit_002c4ca8.cpp
}
}
