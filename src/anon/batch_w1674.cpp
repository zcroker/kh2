#include "../common/types.h"
struct Rect14b { u8 pad0[4]; u16 w; u16 h; s16 x; s16 y; u8 pad1[4]; u8 r, g, b, a; u8 pad2[12]; u64 pk[26]; };
#define RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
extern "C" {
// 0014b300: moved to src/anon/unit_0014b150.cpp
}

#define QCOPY186(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV186 {
    f32 x, y, z, w;
    QV186() {}
    QV186(const QV186& o) { QCOPY186(this, &o); }
    QV186& operator=(const QV186& o) { if (this != &o) QCOPY186(this, &o); return *this; }
    QV186 operator-(const QV186& b) const {
        QV186 o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Info186 { u32 pad0; s32 kind; };
struct Obj186 { u8 pad0[0xc]; Info186* info; u8 pad10[0x508]; u8 sub518[4]; };
struct Msg186 { QV186 dir; u8 pad10[8]; u32 flags; u8 pad1c[0xa]; u8 action; u8 type; };
extern "C" {
extern void* D_0034e948;
QV186* func_0016c028(void*);
s32 func_001d7b90(void*);
void func_001cf0d8(Obj186*, Msg186*);
u32 func_0018ca48(u8);
s32 func_001c0cd8(Obj186*);
void func_001c0e60(Obj186*);
f32 func_0018cb30(Msg186*);
void func_00186378(Obj186*, Msg186*, f32);
void func_00186478(Obj186*, Msg186*);
void func_001863a8(Obj186*, Msg186*, f32);
void func_0018cd28(Msg186*, f32*, f32*);
void func_00186740(Obj186*, Msg186*, s32, s32, f32, f32);
void func_00186948(Obj186*, Msg186*);
void func_00186988(Obj186*, Msg186*, f32);
void func_001cd078(Msg186*);

static inline bool isType17(Obj186* o) { return o->info->kind == 0x17; }
// 00186160: moved to src/anon/unit_00185d10.cpp
void func_00186160(Obj186* obj, Msg186* msg);
}
