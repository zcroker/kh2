#include "../common/types.h"
inline void* operator new[](unsigned int, void* p) { return p; }
inline void* operator new(unsigned int, void* p) { return p; }

extern "C" {
extern u8 D_00363860[];
void func_002edf28(u8*);  // obj_ctor_3637e0
void YS__OBJDATA__clear(u8*);  // obj_init_24bytes
void func_001a92d8(u8*, u32, s32);
void func_00106ab8(u8*);  // noop_ret
void func_00108698(u8*);
void func_002eeee8(u8*, u8*);
struct VObj { void** vt; };
VObj* func_001a93e8(u8*);
u32 func_001a9420(u8*);
void func_0011e260(u32, u32);
void kn__Projection__set(u8*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void kn__Projection__calcMatrix(u8*);
void func_0011b6a8(u8*);
struct V4 { f32 x, y, z, w; V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
  void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
  V4& operator=(const V4& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct C4 { u8 r, g, b, a; void set(u8 R, u8 G, u8 B, u8 A) { r = R; g = G; b = B; a = A; } };
typedef u32 (*Fn9)(VObj*, u32);


// 002ee8a8: moved to src/anon/unit_002ee8a8.cpp

// 002eea80: moved to src/anon/unit_002ee8a8.cpp

}

// ---- 00188c30
namespace n00188c30 {
extern "C" {
void YS__PARTRAM__PARTRAM(void*);
void func_00189170(void*);
void func_001a8bb8(void*);  // obj_set_header_bytes
void func_001d9768(void*);
}
struct A276 { u8 d[276]; A276() { YS__PARTRAM__PARTRAM(this); } };
struct A56 { u8 d[56]; A56() { func_00189170(this); } };
struct A4 { u8 d[4]; A4() { func_001a8bb8(this); } };
struct Z4 { u32 v; Z4() { v = 0; } };
struct Z8 { u8 a; u32 b; Z8() { a = 0; b = 0; } };
struct E { Z8 e[64]; u32 x[4]; E() __attribute__((always_inline)); };
inline E::E() { for (s32 i = 0; i < 4; i++) x[i] = 0; }
extern "C" {
void YS__SAVERAM_BATTLE__SAVERAM_BATTLE(u8* p);  // 0x00188c30: definition moved into src/anon/unit_00188848.cpp
}
}

// ---- 002df868
namespace n002df868 {
#undef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void ScaleIn(QWord* a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
}
static inline f32 Length(const QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void Normalize(QWord* v)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "$8", "$f0", "memory");
}
extern "C" {
extern u8* D_00361f60;
extern u8* D_0034e948;
void Ti__ACTION_PO_JUMP__control(u8*, u8*);
QWord* YS__OBJ__get_pos(u8*);  // obj_get_attach_or_alt
u8* func_002dc7c8(u8*);
void func_002dd2d8(u8*, f32*, f32*);
void Ti__ACTION_PO_JUMP_ROO__control(u8* s, u8* o);  // 0x002df868: definition moved into src/anon/unit_002de3c8.cpp
}
}

// ---- 001bfa08
namespace n001bfa08 {
#undef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline void ScaleTo(QWord* r, const QWord& a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(&a), "f"(k) : "$8", "memory");
}
static inline void AddTo(QWord* r, const QWord& a, const QWord& b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(&a), "r"(&b) : "memory");
}
extern "C" {
extern f32 D_00349e10;
s32 YS__OBJ__is_exist(u32);
f32 sinf(f32);
void YS__OBJ__get_dir(QWord*, u8*);
void func_0016aeb8(u8*, f32);
void func_0016be98(QWord*, u32);
void func_0016ace0(u8*, QWord*);
u32 func_001a37e8(u32, s32);
void dk__TREASURE_INFO__openPrizeInfo(u32);
typedef void (*VF8)(u8*);
void YS__ACTION_PRIZEBOX_GET__control(u8* a0, u8* p);  // 0x001bfa08: definition moved into src/anon/unit_001bc568.cpp
}
}
