// 00159368: camera follow (w3690). Match under -O2 -fno-strict-aliasing.
// The pinned &b pointer + empty asm at the final copy steers global-alloc so &b lands in t4 (partial asm).
#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct V159368 {
    f32 x, y, z, w;
    V159368() {}
    V159368(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V159368& operator=(const V159368& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V159368 operator-(const V159368& b) const {
        V159368 d;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&d), "r"(this), "r"(&b) : "memory");
        return d;
    }
    V159368 operator+(const V159368& b) const {
        V159368 d;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&d), "r"(this), "r"(&b) : "memory");
        return d;
    }
    V159368& operator*=(f32 s) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    f32 Length() const {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Obj159368;
struct Obj159368Vt { void* f[16]; s32 (*check)(Obj159368*); };
struct Obj159368 { Obj159368Vt* vt; };
struct Cam159368 {
    V159368 pos;
    u8 pad0[32];
    f32 f48;
    f32 f52;
    u8 pad1[12];
    Obj159368* obj;
    u8 pad2[24];
    V159368 f96;
    u8 pad3[16];
    V159368 f128;
};
extern "C" {
extern s8 D_004f35b8;
extern s8 D_004f35c0;
extern s8 D_004f35c8;
extern V159368 D_004f35d0;
extern V159368 D_004f35e0;
extern V159368 D_004f35f0;
extern f32 D_004f35b0;
extern s32 D_0034aa08;
void func_00159758(void);
void func_00159760(void);
void func_00159768(void);
void func_002fd188(void (*)(void));
u8* func_00167f18(s32);
void func_00159308(u8*);
V159368* func_0016c028(Obj159368*);
void func_00159240(V159368*, V159368*);
void func_0013f648(Cam159368*);
// Camera follow. The three offset vectors are function-local statics
// (guards D_004f35b8/c0/c8, empty atexit dtors func_00159758/60/68).
// 00159368: moved to src/anon/unit_00159240.cpp
}
