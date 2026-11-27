// Linked unit 0x1c9ea0-0x1ca060: first part of the file with the vtable at 0x351f40 and the cached
// parameter pointer D_00351f34 (gap method 0x1c9ea0 written here). .rodata at 0x36e0c8.
// 0x1ca060 (vtable slot 7, 0.8f at 0x36e0cc) is the last function of the unit.
// unit_001ca148.cpp continues the file.

#include "../common/types.h"

// ---- 001c9ea0 gap: vtable 0x351f40 slot 0
namespace n001c9ea0 {
extern u8* D_00351f34 asm("D_00351f34");
u8* func_001ce328(s32) asm("func_001ce328");
void func_001c9ea0(void* self, u8* o) asm("func_001c9ea0");
void func_001c9ea0(void* self, u8* o) {
    u8* p = D_00351f34;
    if (p == 0) {
        p = func_001ce328(54);
        D_00351f34 = p;
    }
    *(f32*)(o + 40) = *(f32*)(p + 4);
}
}  // namespace n001c9ea0

// ---- 001c9ee8 from src/anon/batch_w277.cpp
namespace n001c9ee8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Scale(const QWord& a, f32 s)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline void Zero(QWord* v)
{
    asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(v) : "memory");
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Mv {
    u8 pad0[16];
    QWord dir;           
    QWord v2;            
    u8 pad1[320 - 48];
    u8 sub[32];           
    u32 flags160;         
    u8 pad2[2040 - 356];
    u32 flags7f8;          
};
struct G1f34 { f32 a, b; };
extern G1f34* D_00351f34 asm("D_00351f34");
s32 func_001ca448(Mv*) asm("func_001ca448");
void YS__ACTION_LIGHTCYCLE__CheckCrash(Mv*) asm("YS__ACTION_LIGHTCYCLE__CheckCrash");
void func_0017f540(u8*, s32, f32, f32) asm("func_0017f540");
void func_001c9ee8(void* self, Mv* m) asm("func_001c9ee8");
void func_001c9ee8(void* self, Mv* m) {
    s32 mot = 0;
    QWord unused;
    if (func_001ca448(m) && !(m->flags7f8 & 4)) YS__ACTION_LIGHTCYCLE__CheckCrash(m);                      
    if (0.0f < m->dir.f[3]) {
        if (m->dir.f[0] < 0.0f) mot = 151;
        else if (0.0f < m->dir.f[0]) mot = 152;
        m->dir = Scale(m->dir, m->dir.f[3]);
    } else {
        Zero(&m->dir);
    }
    if (func_001ca448(m)) {                      
        m->dir.f[2] += D_00351f34->b;
    } else {
        Zero(&m->dir);
        Zero(&m->v2);
    }
    m->dir.f[3] = Normalize(&m->dir);
    u8* sub = m->sub;
    if (m->flags160 & 4) func_0017f540(sub, mot, 12.0f, 0.0f);
}
}  // namespace n001c9ee8


// ---- 001ca060 gap: vtable 0x351f40 slot 7 (reuses the QWord/Scale classes above)
namespace n001ca060 {
using n001c9ee8::QWord;
using n001c9ee8::Scale;
struct Mv {
    u8 pad0[16];
    QWord dir;           // +16, w = speed
    QWord v2;            // +32, z blended toward the target
    u8 pad1[1416 - 48];
    u32 flags588;
    u8 pad2[1644 - 1420];
    f32 f66c;
};
struct G1f34 { f32 a, b; u8 pad[32]; f32 f28; };
extern G1f34* D_00351f34 asm("D_00351f34");
extern f32 D_00349e10 asm("D_00349e10");
QWord YS__MATH__VectorRotY(f32, const QWord&) asm("YS__MATH__VectorRotY");
QWord func_001ca060(void* self, Mv* m) asm("func_001ca060");
QWord func_001ca060(void* self, Mv* m) {
    f32 k;
    if (m->flags588 & 0x80) k = D_00351f34->f28;
    else k = 0.8f;
    QWord w;
    w = Scale(m->dir, m->dir.f[3]);
    f32 z = w.f[2];
    z = z + (m->v2.f[2] - z) * k;
    w.f[2] = z;
    m->v2.f[2] = z;
    f32 f = m->f66c;   // a local for the call argument: gives z the f0 register
    w = YS__MATH__VectorRotY(f, w);
    return Scale(w, D_00349e10);
}
}  // namespace n001ca060
