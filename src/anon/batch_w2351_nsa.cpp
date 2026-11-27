// Batch w2351 functions that need -fno-strict-aliasing (the build compiles *_nsa.cpp with it).
#include "../common/types.h"

#define QCOPY2040(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V2040 {
    f32 x, y, z, w;
    V2040() {}
    V2040(const V2040& o) { QCOPY2040(this, &o); }
    V2040& operator=(const V2040& o) { if (this != &o) QCOPY2040(this, &o); return *this; }
    V2040 operator-(const V2040& b) const {
        V2040 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2040 operator+(const V2040& b) const {
        V2040 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize() {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    V2040& operator*=(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Q2040 { u8 pad0[12]; s32 f12; V2040 v; };
struct Info2040 { u8 b0; u8 b1; u16 h2; };
struct Res2040 { u8 pad[0x18]; u32 flag : 1; bool isFlag() { return flag; } };
struct Ent2040 { void** vt; };
struct Ctx2040 { u8 pad[8]; void* f8; };
typedef void (*EntFn2040)(Ent2040*, Res2040*);

extern "C" {
s32 func_0018d940(Ctx2040*, Ent2040*);
Info2040* func_00112f88(Ent2040**);
void YS__COLLISION__set(Q2040*, Ent2040*, Info2040*);
f32 func_0018a970(Q2040*, V2040);
Res2040* YS__ATTACK__strike(Ctx2040*, Ent2040*, u16, u8);
void func_0018ca10(Res2040*);
void* func_0016ac80(void*, s32, V2040*, s32, s32);
V2040* func_001dc648(void*);
V2040 YS__MATH__VectorToAngle(const V2040&);
void YS__HITMARK__Add(void*);

}
extern "C" {
// Moves pos toward the target the query found, then runs the entity's hit callback and,
// for id >= 0, spawns effect id at the new position facing dir.
s32 func_001130b0(V2040* pos, Ent2040** pe, Ctx2040* ctx, s32 id);  // 0x001130b0: definition moved into src/anon/unit_001117d8.cpp
}

extern "C" {
struct Mem { u8 b[4]; };
struct Sel { u8 a, b, c; u8 pad; u16 d, e, f; };
struct Cmd { s32 f0; u8 b4; u8 p[11]; s32 f10; s32 f14; s32 f18; s32 f1c; };
void func_001a8bb8(Mem*);
s32 func_0019f2a8(Cmd*, Sel*);
Mem* func_001a8bd0(s32);
void func_001a8d40(Mem*, s32);
void func_001d94f8(Mem, Mem*);
void YS__MAGIC__Reset(void);
void func_002533e0(s32, const void*);
void AREA__MapJump(Sel*, u32, s32, s32, s32);
void YS__RECOV__Exec(s32);
void func_00149fe0(s32, u32);
void func_0014a138(s32);
void Tz__CampMenu__Start(s32, s32);
extern s8 D_01c62fa0;
extern Mem D_01c62fa8 __attribute__((aligned(4)));
extern s32 D_01c62f98;

void func_0019f070(Cmd* o, u32 a1);  // 0x0019f070: definition moved into src/anon/unit_0019ee80.cpp
}
namespace w2351 {
struct SprInfo { volatile u16 flags; u8 p2[2]; u8 kind; };
struct Spr { u8 p0[0x198]; s32 tag; u8 p19c[8]; u32 col; };
// 9 bytes per row; the per-slot flag bytes start at +8
struct SprRow { u8 pad[8]; u8 flag[1]; };
struct SprPool { u8 p0[0xa0]; SprRow rows[4]; };
}
using namespace w2351;
extern "C" {
extern s32 D_004573c0[];
s32 func_0013cb30(void);
s32 func_0013cb80(void);
s32 func_0013cb90(void);
Spr* func_0013aca0(s32, s32, s32, s32, s32, u8);
void func_0013ac60(Spr*, u8, s32);
void func_00138c10(Spr*, s32);
void func_00138c40(Spr*, s32, s32);
f32 func_0013b298(u8*);
void func_001395d0(Spr*);
void func_001395e8(Spr*);
s32 __fixunssfsi(f32);
void func_00138d48(Spr*, f32, f32, f32, f32);

// Takes the next sprite slot of list idx (creating the sprite on first use), positions it,
// sets its alpha from the fade level and records the info flag for the slot.
Spr* func_0013b5d0(u8* self, s32 idx, s32 c, SprInfo* info, u8 changed, s32 x, s32 y, s32 tag, f32 scale, u32 col, s32 mode);  // 0x0013b5d0: definition moved into src/anon/unit_0013a8b8.cpp
}
