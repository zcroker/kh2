#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../yasui/libys/sora.hpp"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// ---- 001cefb0 (was whole asm, never written in C): message handler (motion per message id, base handler for the rest).
// Each case calls play then returns push (sibcall); 403/410 pass a local 0.0f (kept in $f20); the base call
// result goes through r (initialised from m) so it stays a jal, like 0x1d1190.
namespace n001cefb0 {
struct Msg1cefb0 { u16 f0; u16 id; };
struct Obj1cefb0 { u8 pad[320]; u8 motion[16]; };
u32 func_001cf0b0(Obj1cefb0*) asm("_Z13func_001cf0b0Ph");
s32 func_00178bf0(Obj1cefb0*, Msg1cefb0*) asm("func_00178bf0");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
s32 func_0017f5e0(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");

s32 func_001cefb0(Obj1cefb0* o, Msg1cefb0* m) asm("func_001cefb0");
s32 func_001cefb0(Obj1cefb0* o, Msg1cefb0* m)
{
    s32 r = (s32)m;
    switch (m->id) {
    case 401: if (func_001cf0b0(o)) { func_0017f488(o->motion, 181, 0.0f, 0.0f); } else { func_0017f488(o->motion, 184, 0.0f, 0.0f); } return func_0017f5e0(o->motion, 0, 0.0f, 0.0f, 0);
    default: r = func_00178bf0(o, m); break;
    case 402: if (func_001cf0b0(o)) { func_0017f488(o->motion, 187, 0.0f, 0.0f); } else { func_0017f488(o->motion, 188, 0.0f, 0.0f); } return func_0017f5e0(o->motion, 0, 0.0f, 0.0f, 0);
    case 403: { f32 f = 0.0f; func_0017f488(o->motion, 189, f, 0.0f); return func_0017f5e0(o->motion, 0, 0.0f, 0.0f, 0); }
    case 410: { f32 f = 0.0f; func_0017f488(o->motion, 190, f, 0.0f); return func_0017f5e0(o->motion, 0, 0.0f, 0.0f, 0); }
    }
    return r;
}
}  // namespace n001cefb0

// ---- 001cf0b0 from src/anon/tiny_auto80_queue.cpp
namespace n001cf0b0 {
u32 func_001cf0b0(u8* a0) asm("_Z13func_001cf0b0Ph");
u32 func_001cf0b0(u8* a0) {
    u8* t7 = *(u8**)(a0 + 2884);
    f32 f0 = 0.0f;
    f32 f1 = *(f32*)(t7 + 2608);
    if (f1 < f0) {
        return 1;
    }
    return 0;
}
}  // namespace n001cf0b0

// ---- 001cf0d8 from src/anon/batch_w2046_nsa.cpp
namespace n001cf0d8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator=(const V& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline V Cross(const V& a, const V& b)
{
    V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Mot { u8 pad[0x14]; s32 id; };
struct Info { u8 pad[0x2b]; u8 kind; };
struct Tgt { V v; u8 pad[0x10]; Info* info; };
struct Self {
    u8 pad[0x140];
    Mot mot;                            
    u8 pad2[0x58c - 0x158];
    u32 flags;                          
    u8 pad3[0xb6c - 0x590];
    s32 party;                          
};
void mo488_w2046(Mot*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void mopush_w2046(Mot*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
void ct186a90_w2046(Self*, V*, f32) asm("_Z23YS__BTLOBJ__set_hitbackjjjj");
s32 ct19ba60_w2046(s32) asm("_Z17YS__OBJ__is_existjjjj");
void f16ac38_w2046(s32, s32, s32, s32, s32) asm("_Z13func_0016ac38jjjjjjjj");
extern "C" s32 D_0036e318 asm("D_0036e318");
extern "C" s32 D_0036e31c asm("D_0036e31c");
static inline __attribute__((always_inline)) s32 motIdB(Mot* m) { if (m->id == 189) return D_0036e318; return D_0036e31c; }
V YS__OBJ__get_dir(Self*) asm("YS__OBJ__get_dir");
V YS__MATH__VectorRotY(const V&, f32) asm("YS__MATH__VectorRotY");
f32 YS__DAMAGE__get_hitback(Tgt*) asm("YS__DAMAGE__get_hitback");
void func_001cf0d8(Self* self, Tgt* t) asm("func_001cf0d8");
void func_001cf0d8(Self* self, Tgt* t)
{
    V n;
    V d;
    n = Cross(YS__OBJ__get_dir(self), t->v);
    switch (t->info->kind) {
    case 0:
        mo488_w2046(&self->mot, 30, 0.0f, 0.0f);
        mopush_w2046(&self->mot, 0, 0.0f, 0.0f, 0);
        break;
    case 1: {
        s32 id = motIdB(&self->mot);
        Mot* m = &self->mot;
        f32 k;
        if (0.0f < n.y) {
            k = 1.5707964f;
            mo488_w2046(m, 32, 0.0f, 0.0f);
            id++;
        } else {
            k = -1.5707964f;
            mo488_w2046(m, 31, 0.0f, 0.0f);
        }
        d = YS__MATH__VectorRotY(YS__OBJ__get_dir(self), k);
        ct186a90_w2046(self, &d, YS__DAMAGE__get_hitback(t));
        if (self->flags & 4) {
            if (ct19ba60_w2046(self->party)) {
                f16ac38_w2046(self->party, id, 1, 0, 0);
            }
        }
        mopush_w2046(m, 0, 0.0f, 0.0f, 0);
        break;
    }
    case 2:
        mo488_w2046(&self->mot, 16, 0.0f, 0.0f);
        mopush_w2046(&self->mot, 0, 0.0f, 0.0f, 0);
        break;
    case 3:
        if (0.0f < n.y) mo488_w2046(&self->mot, 33, 0.0f, 0.0f);
        else mo488_w2046(&self->mot, 34, 0.0f, 0.0f);
        mopush_w2046(&self->mot, 0, 0.0f, 0.0f, 0);
        break;
    }
}
}  // namespace n001cf0d8

// ---- 001cf320 from src/anon/batch_w1965.cpp
namespace n001cf320 {
#define W1965aQCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1965aV {
    f32 x, y, z, w;
    W1965aV() {}
    W1965aV(const W1965aV& o) { W1965aQCOPY(this, &o); }
    W1965aV& operator=(const W1965aV& o) { if (this != &o) W1965aQCOPY(this, &o); return *this; }
    W1965aV operator-(const W1965aV& b) const {
        W1965aV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline W1965aV W1965aCross(const W1965aV& a, const W1965aV& b)
{
    W1965aV r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 W1965aNormalize(W1965aV* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct W1965aTgt { u8 pad[12]; u8* obj; };
W1965aV* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
W1965aV YS__OBJ__get_dir(u8*) asm("YS__OBJ__get_dir");
W1965aV YS__MATH__VectorRotY(const W1965aV&, f32) asm("YS__MATH__VectorRotY");
s32 func_0018f010(W1965aTgt*) asm("func_0018f010");
void YS__BTLOBJ__set_hitback(u8*, W1965aV*, f32) asm("YS__BTLOBJ__set_hitback");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
void YS__TRPLAYER__ExecReflect(u8* o, s32 a1, W1965aTgt* t) asm("YS__TRPLAYER__ExecReflect");
void YS__TRPLAYER__ExecReflect(u8* o, s32 a1, W1965aTgt* t)
{
    f32 spd = 100.0f;
    W1965aV c;
    W1965aV n;
    n = *YS__OBJ__get_pos(t->obj) - *YS__OBJ__get_pos(o);
    W1965aNormalize(&n);
    c = W1965aCross(YS__OBJ__get_dir(o), n);
    s32 id;
    f32 ang;
    if (c.y < 0.0f) { id = 140; ang = 1.5707964f; }
    else { id = 141; ang = -1.5707964f; }
    n = YS__MATH__VectorRotY(YS__OBJ__get_dir(o), ang);
    if (func_0018f010(t)) spd = 2000.0f;
    YS__BTLOBJ__set_hitback(o, &n, spd);
    func_0017f488(o + 320, id, 0.0f, 0.0f);
    func_0017f5e0(o + 320, 0, 0, 0.0f, 0.0f);
}
}  // namespace n001cf320
// read as globals by 0x1cf0d8 (two motion ids)
extern "C++" const s32 R_0036e318 asm("D_0036e318") = 1;
extern "C++" const s32 R_0036e31c asm("D_0036e31c") = 10;

// ---- 001cf4f8 gap (never-written function)
namespace g001cf4f8 {
void func_00179e18(u8*) asm("func_00179e18");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
extern u32 D_0034f240 asm("D_0034f240");
void func_001991a8(s32, s32) asm("func_001991a8");
void func_001af290(u8*, s32) asm("func_001af290");
void func_001cf4f8(u8* p) asm("func_001cf4f8");
void func_001cf4f8(u8* p) {
    func_00179e18(p);
    func_0017f488(p + 320, 30, 0.0f, 0.0f);
    if (!(D_0034f240 & 0x20000)) func_001af290(p, 0);
    else func_001991a8(90, 0);
}
}  // namespace g001cf4f8

// ---- 001cf560 from src/anon/batch_w26.cpp
namespace n001cf560 {
inline void* operator new(unsigned int, void* p) { return p; }
s32 func_001ca448(void*) asm("func_001ca448");
s32 func_001cf560(u8* o) asm("func_001cf560");
s32 func_001cf560(u8* o) {
    s32 r = 0;
    if (func_001ca448(o) || *(s32*)(o + 340) == 44) r = 1;
    return r;
}
}  // namespace n001cf560

// ---- 001cf5b0 from src/anon/match_001cf5b0_nsa.cpp
namespace n001cf5b0 {
void func_00177dc8(void*, u32, s32, u32, u32) asm("func_00177dc8");
void func_00158a90(void*) asm("func_00158a90");
extern u8 D_00352288[] asm("D_00352288");
struct W1807V4s { f32 x, y, z, w; void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } };
struct W1807Cam { u32 vt; u8 pad[2924]; W1807V4s a; W1807V4s b; f32 r0, r1, r2, r3; u32 z0, z1; };
void func_001cf5b0(W1807Cam* p, u32 a1, u32 a2, u32 a3) asm("func_001cf5b0");
void func_001cf5b0(W1807Cam* p, u32 a1, u32 a2, u32 a3) {
    func_00177dc8(p, a1, 11, a2, a3);
    p->vt = (u32)D_00352288;
    p->a.set(0.0f, -200.0f, 200.0f, 1.0f);
    p->b.set(0.0f, 0.0f, -100.0f, 1.0f);
    p->r0 = 0.05235987529158592f; p->r1 = 0.7853981256484985f; p->r2 = 0.01745329238474369f; p->r3 = 0.2617993652820587f;
    p->z0 = 0; p->z1 = 0;
    func_00158a90(p);
}
}  // namespace n001cf5b0

// ---- 001cf698 from src/anon/match_001cf698_nsa.cpp
namespace n001cf698 {
void func_00177dc8(void*, u32, s32, u32, u32) asm("func_00177dc8");
void func_00158a90(void*) asm("func_00158a90");
extern u8 D_00352288[] asm("D_00352288");
struct W1807V4s { f32 x, y, z, w; void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } };
struct W1807Cam { u32 vt; u8 pad[2924]; W1807V4s a; W1807V4s b; f32 r0, r1, r2, r3; u32 z0, z1; };
void func_001cf698(W1807Cam* p, u32 a1, u32 a2, u32 a3) asm("func_001cf698");
void func_001cf698(W1807Cam* p, u32 a1, u32 a2, u32 a3) {
    func_00177dc8(p, a1, 11, a2, a3);
    p->vt = (u32)D_00352288;
    p->a.set(0.0f, -200.0f, 200.0f, 1.0f);
    p->b.set(0.0f, 0.0f, -100.0f, 1.0f);
    p->r0 = 0.05235987529158592f; p->r1 = 0.7853981256484985f; p->r2 = 0.01745329238474369f; p->r3 = 0.2617993652820587f;
    p->z0 = 0; p->z1 = 0;
    func_00158a90(p);
}
}  // namespace n001cf698

// ---- 001cf780 gap (never-written function)
namespace g001cf780 {
struct Vq { f32 x, y, z, w; Vq& operator=(const Vq& s) { if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory"); return *this; } } __attribute__((aligned(16)));
static inline void VZero(void* p) { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p) : "memory"); }
void func_001780d8(u8*) asm("func_001780d8");
void func_00198860(u8*, s32) asm("func_00198860");
void func_0017a7d8(u8*) asm("func_0017a7d8");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016b070(u8*, Vq*) asm("func_0016b070");
void func_001cf780(u8* p) asm("func_001cf780");
void func_001cf780(u8* p) {
    func_001780d8(p);
    func_00198860(p, 10);
    func_0017a7d8(p);
    func_0016bd60(p, 28);
    Vq z;
    VZero(&z);
    func_0016b070(p, &z);
}
}  // namespace g001cf780

// ---- 001cf7d8 from src/anon/batch_w82.cpp
namespace n001cf7d8 {
struct Mat82 { f32 m[16]; } __attribute__((aligned(16)));
void func_001bc778(u8*) asm("func_001bc778");
u8* YS__COMMAND_MENU__add(u8*, s32, s32, s32) asm("YS__COMMAND_MENU__add");
s32 func_001cf998(void) asm("func_001cf998");
void YS__NMPLAYER__set_lamp(u8*, s32) asm("YS__NMPLAYER__set_lamp");
s32 func_001d8898(s32) asm("func_001d8898");
void func_00190128(void*) asm("func_00190128");
void func_00190878(void*, u8*, s32) asm("func_00190878");
void func_001bd3e0(u32, s32, s32, void*, s32, s32) asm("func_001bd3e0");
void func_00178888(u8*) asm("func_00178888");
void YS__NMPLAYER___OVR_control(u8* a0) asm("YS__NMPLAYER___OVR_control");
void YS__NMPLAYER___OVR_control(u8* a0)
{
    u8 tmp[32] __attribute__((aligned(16)));
    u8* s = *(u8**)(a0 + 2884) + 1660;
    u8* v;
    func_001bc778(s);
    v = YS__COMMAND_MENU__add(s, 411, 0, 1);
    v[6] = 1;
    if (func_001cf998()) {
        YS__NMPLAYER__set_lamp(a0, 0);
    } else {
        YS__NMPLAYER__set_lamp(a0, 1);
        v[5] = 5;
    }
    if (func_001d8898(1)) {
        func_00190128(tmp);
        func_00190878(tmp, a0, 0);
        func_001bd3e0(*(u32*)(a0 + 2884), 1, 412, tmp, 1, 100);
    }
    func_00178888(a0);
}
}  // namespace n001cf7d8

// ---- 001cf8a8 gap (never-written function)
namespace g001cf8a8 {
struct Vq { f32 x, y, z, w; Vq& operator=(const Vq& s) { if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory"); return *this; } } __attribute__((aligned(16)));
void func_001cf8a8(u8* p) asm("func_001cf8a8");
void func_001cf8a8(u8* p) { *(Vq*)(p + 16) = *(Vq*)(*(u8**)(p + 2884) + 2608); }
}  // namespace g001cf8a8

// ---- 001cf8d0 from src/anon/batch_wcx2.cpp
namespace n001cf8d0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
void func_001d86a0(s32, u32) asm("func_001d86a0");
void func_001d8820(s32) asm("func_001d8820");
void func_0017f488_f8d0(u8*, u32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, u32, f32, f32) asm("func_0017f5e0");
void YS__NMPLAYER___OVR_exec_command_player(u8* p, u8* a1) asm("YS__NMPLAYER___OVR_exec_command_player");
void YS__NMPLAYER___OVR_exec_command_player(u8* p, u8* a1) {
    f32 z;
    switch (*(u16*)(a1 + 2)) {
    case 411:
        z = 0.0f;
        func_001d86a0(-1, 1);
        func_0017f488_f8d0(p + 320, 201, z, z);
        func_0017f5e0(p + 320, 0, 0, z, z);
        break;
    case 412:
        z = 0.0f;
        func_001d8820(1);
        func_0017f488_f8d0(p + 320, 161, z, z);
        func_0017f5e0(p + 320, 0, 0, z, z);
        break;
    }
}
}  // namespace n001cf8d0

// ---- 001cf998 from src/anon/batch_w26.cpp
namespace n001cf998 {
inline void* operator new(unsigned int, void* p) { return p; }
s32 mission_is_exec(void) asm("_ZN2YS7MISSION6IsExecEv");
s32 mission_get_count(s32) asm("_ZN2YS7MISSION8GetCountEi");
s32 func_001cf998(void) asm("func_001cf998");
s32 func_001cf998(void) {
    s32 r = 0;
    if (!mission_is_exec() || mission_get_count(1) > 0) r = 1;
    return r;
}
}  // namespace n001cf998

// ---- 001cf9e0 from src/anon/batch_w88.cpp
namespace n001cf9e0 {
u32 func_0016ac38(u8*, u32, u32, u32, u32) asm("func_0016ac38");
void func_001dc840(u32) asm("func_001dc840");
void func_001940f0(u8*, u32) asm("func_001940f0");
void func_00194108(u8*, u32) asm("func_00194108");
void YS__NMPLAYER__set_lamp(u8* p, s32 mode) asm("YS__NMPLAYER__set_lamp");
void YS__NMPLAYER__set_lamp(u8* p, s32 mode) {
    switch (mode) {
    case 0:
        if (!*(u32*)(p + 2976)) *(u32*)(p + 2976) = func_0016ac38(p, 12, 1, 0, 0);
        if (*(u32*)(p + 2980)) { func_001dc840(*(u32*)(p + 2980)); *(u32*)(p + 2980) = 0; }
        func_001940f0(p, 2);
        func_00194108(p, 1);
        break;
    case 1:
        if (!*(u32*)(p + 2980)) *(u32*)(p + 2980) = func_0016ac38(p, 13, 1, 0, 0);
        if (*(u32*)(p + 2976)) { func_001dc840(*(u32*)(p + 2976)); *(u32*)(p + 2976) = 0; }
        func_001940f0(p, 1);
        func_00194108(p, 2);
        break;
    }
}
}  // namespace n001cf9e0

// ---- 001cfac0 from src/anon/batch_wcx2.cpp
namespace n001cfac0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
void func_001cfac0(u8* p, f32 a, f32 b, f32 c, f32 d) asm("func_001cfac0");
void func_001cfac0(u8* p, f32 a, f32 b, f32 c, f32 d) {
    *(f32*)(p + 2960) = a * 0.017453292f;
    *(f32*)(p + 2964) = b * 0.017453292f;
    *(f32*)(p + 2968) = c * 0.017453292f;
    *(f32*)(p + 2972) = d * 0.017453292f;
}
}  // namespace n001cfac0

// ---- 001cfaf0 from src/anon/batch_w248.cpp
namespace n001cfaf0 {
struct W248V4 {
    f32 x, y, z, w;
    W248V4() {}
    W248V4(const W248V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W248Mv { u8 pad[16]; f32 f10, f14; u8 pad2[4]; f32 f1c; u8 pad3[0xb90 - 0x20]; f32 kx, limx, ky, limy; };
static inline f32 W248Clamp(f32 v, f32 lim) {
    f32 lo = -lim;
    if (v < lo) return lo;
    if (lim < v) return lim;
    return v;
}
extern f32 D_00349e10 asm("D_00349e10");
W248V4* func_0016b0a0(W248Mv*) asm("func_0016b0a0");
void func_0016b070(W248Mv*, W248V4*) asm("func_0016b070");
void YS__ACTION_NMGUN__control(void* self, W248Mv* m) asm("YS__ACTION_NMGUN__control");
void YS__ACTION_NMGUN__control(void* self, W248Mv* m) {
    W248V4 v = *func_0016b0a0(m);
    if (0.0f < m->f1c) {
        v.y += m->f10 * m->kx * D_00349e10;
        v.y = W248Clamp(v.y, m->limx);
        v.x += m->f14 * m->ky * D_00349e10;
        v.x = W248Clamp(v.x, m->limy);
        func_0016b070(m, &v);
    }
}
}  // namespace n001cfaf0

// ---- 001cfbd8 from src/anon/batch_w259.cpp
namespace n001cfbd8 {
struct Sub1cf { u8 pad[4]; u32 f4; u8 p2[431-8]; u8 b431; u8 b432; u8 b433; u8 b434; };
struct S2932 { u32 a; u32 b; u32 pad[6]; u32 c; };
extern u8 D_00352360[] asm("D_00352360");
struct C32bb30 { u8 pad[15792]; u16 a; u16 b; };
extern C32bb30 D_0032bb30 asm("D_0032bb30");
extern f32 D_0036e3bc asm("D_0036e3bc");
extern u8 D_00351ec0[] asm("D_00351ec0");
void func_00177dc8(u8*, u32, s32, u32, u32) asm("func_00177dc8");
void func_0017a480(u8*, u32, s32, s32) asm("func_0017a480");
void func_001a1a50(Sub1cf*, s32) asm("func_001a1a50");
void func_001d2648(u8*, s32, f32) asm("func_001d2648");
void func_001c8d80(u8*, s32) asm("func_001c8d80");
void func_001cfbd8(u8* p, u32 a1, u32 a2, u32 a3) asm("func_001cfbd8");
void func_001cfbd8(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00177dc8(p, a1, 11, a2, a3);
    *(u32*)(p + 2920) = 0;
    *(u32*)(p + 2924) = 0;
    *(u32*)(p + 0) = (u32)D_00352360;
    *(u8*)(p + 2928) = 0;
    S2932* s2 = (S2932*)(p + 2932);
    u8* s = (u8*)s2;
    s2->a = 0;
    s2->b = 0;
    s2->c = 0;
    *(u32*)(p + 1416) |= 0x2000000;
    ((Sub1cf*)*(u32*)(p + 1164))->b432 = 0;
    ((Sub1cf*)*(u32*)(p + 1164))->b433 = 0;
    ((Sub1cf*)*(u32*)(p + 1164))->b434 = 3;
    func_0017a480(p, ((Sub1cf*)*(u32*)(p + 1164))->f4, 0, 0);
    func_001a1a50((Sub1cf*)*(u32*)(p + 1164), 0);
    f32 k = D_0036e3bc;
    ((Sub1cf*)*(u32*)(p + 1164))->b431 = 1;
    if (D_0032bb30.a < 999) D_0032bb30.a++;
    if (D_0032bb30.b < 999) D_0032bb30.b++;
    *(u32*)(p + 2748) |= 0x240;
    func_001d2648(s, 0xbbc2, k);                        
    func_001c8d80(D_00351ec0, 4);
}
}  // namespace n001cfbd8

// ---- 001cfcf8 from src/anon/batch_w92.cpp
namespace n001cfcf8 {
inline void* operator new(unsigned int, void* p) { return p; }
struct Big1cd { u64 d[0x10fc0 / 8]; } __attribute__((aligned(16)));
struct Sub1cf { u32 a, b; u32 pad[6]; u32 c; };
static inline void init1cf(Sub1cf* p) { p->a = 0; p->b = 0; p->c = 0; }
struct C1cf { u8 pad[431]; u8 b431; u8 b432; u8 b433; u8 b434; };
struct G1cf { u8 pad[15792]; u16 c0; u16 c1; };
void func_00177dc8(u8*, u32, s32, u32, u32) asm("func_00177dc8");
void func_0017a480(u8*, u32, s32, s32) asm("func_0017a480");
void func_001a1a50(C1cf*, s32) asm("func_001a1a50");
void func_001d2648(u8*, u32, f32) asm("func_001d2648");
void func_001c8d80(void*, s32) asm("func_001c8d80");
extern u8 D_00352360 asm("D_00352360");
extern Big1cd D_0032bb30 asm("D_0032bb30");
extern u8 D_00351ec0 asm("D_00351ec0");
extern f32 D_0036e3bc asm("D_0036e3bc");
void YS__MICKEY__MICKEY(u8* self, u32 a, u32 b, u32 c) asm("YS__MICKEY__MICKEY");
void YS__MICKEY__MICKEY(u8* self, u32 a, u32 b, u32 c) {
    func_00177dc8(self, a, 11, b, c);
    u8* sub = self + 2932;
    *(u32*)(self + 2920) = 0;
    *(u32*)(self + 2924) = 0;
    *(u32*)self = (u32)&D_00352360;
    self[2928] = 0;
    init1cf((Sub1cf*)sub);
    *(u32*)(self + 1416) |= 0x2000000;
    ((C1cf*)*(u32*)(self + 1164))->b432 = 0;
    ((C1cf*)*(u32*)(self + 1164))->b433 = 0;
    ((C1cf*)*(u32*)(self + 1164))->b434 = 3;
    func_0017a480(self, *(u32*)(*(u32*)(self + 1164) + 4), 0, 0);
    func_001a1a50((C1cf*)*(u32*)(self + 1164), 0);
    f32 k = D_0036e3bc;
    ((C1cf*)*(u32*)(self + 1164))->b431 = 1;
    G1cf* g = (G1cf*)&D_0032bb30;
    if (g->c0 < 999) g->c0++;
    if (g->c1 < 999) g->c1++;
    *(u32*)(self + 2748) |= 0x240;
    func_001d2648(sub, 0xbbc2, k);                        
    func_001c8d80(&D_00351ec0, 4);
}
}  // namespace n001cfcf8

// ---- 001cfe18 from src/anon/batch_w61.cpp
namespace n001cfe18 {
void func_001c8d98(void*, u32) asm("func_001c8d98");
void func_001c9b90(void) asm("func_001c9b90");
void func_001d2710(void*) asm("func_001d2710");
void func_00319f88(void*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(void*) asm("YS__OBJ_ATTACK__clear");
void func_001c0248(void*) asm("func_001c0248");
void func_00319fb0(void*) asm("func_00319fb0");
extern u8 D_00352360[] asm("D_00352360");
extern u8 D_00351eb8[] asm("D_00351eb8");
extern u8 D_00351ec0[] asm("D_00351ec0");
extern u8 D_0034e8b8[] asm("D_0034e8b8");
extern u8 D_0034ee08[] asm("D_0034ee08");
struct NoTail { ~NoTail() {} };
void func_001cfe18(u8* p) asm("func_001cfe18");
void func_001cfe18(u8* p) {
    NoTail g;
    *(u8**)p = D_00352360;
    func_001c8d98(D_00351eb8, 0);
    func_001c8d98(D_00351ec0, 4);
    func_001c9b90();
    func_001d2710(p + 2932);
    *(u8**)p = D_0034e8b8;
    func_00319f88(p + 2824);
    *(u8**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);                      
    func_001c0248(p + 2640);
    func_00319fb0(p);                 
}
}  // namespace n001cfe18

// ---- 001cfeb0 from src/anon/batch_w62.cpp
namespace n001cfeb0 {
struct NoTail { ~NoTail() {} };
void func_001c8d98(u8*, u32) asm("func_001c8d98");
void func_001c9b90(void) asm("func_001c9b90");
void func_001d2710(u8*) asm("func_001d2710");
void func_00319f88(u8*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(u8*) asm("YS__OBJ_ATTACK__clear");
void func_001c0248(u8*) asm("func_001c0248");
void func_00319fb0(u8*) asm("func_00319fb0");
extern u8 D_00352360[] asm("D_00352360");
extern u8 D_0034e8b8[] asm("D_0034e8b8");
extern u8 D_0034ee08[] asm("D_0034ee08");
extern u8 D_00351eb8[] asm("D_00351eb8");
extern u8 D_00351ec0[] asm("D_00351ec0");
void func_001cfeb0(u8* p) asm("func_001cfeb0");
void func_001cfeb0(u8* p) {
    NoTail g;
    *(u32*)p = (u32)D_00352360;
    func_001c8d98(D_00351eb8, 0);
    func_001c8d98(D_00351ec0, 4);
    func_001c9b90();
    func_001d2710(p + 2932);
    *(u32*)p = (u32)D_0034e8b8;
    func_00319f88(p + 2824);
    *(u32*)p = (u32)D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);                      
    func_001c0248(p + 2640);
    func_00319fb0(p);                 
}
}  // namespace n001cfeb0

// ---- 001cff48 from src/anon/batch_w64.cpp
namespace n001cff48 {
extern char D_00352360[] asm("D_00352360");
extern char D_0034e8b8[] asm("D_0034e8b8");
extern char D_0034ee08[] asm("D_0034ee08");
extern char D_00351eb8[] asm("D_00351eb8");
extern char D_00351ec0[] asm("D_00351ec0");
void func_001c8d98(void*, s32) asm("func_001c8d98");
void func_001c9b90(void) asm("func_001c9b90");
void func_001d2710(u8*) asm("func_001d2710");
void func_00319f88(u8*) asm("func_00319f88");
void YS__OBJ_ATTACK__clear(u8*) asm("YS__OBJ_ATTACK__clear");
void func_001c0248(u8*) asm("func_001c0248");
void func_00319fb0(u8*) asm("func_00319fb0");
void func_00105110(u8*) asm("func_00105110");
void func_001cff48(u8* p) asm("func_001cff48");
void func_001cff48(u8* p) {
    *(void**)p = D_00352360;
    func_001c8d98(D_00351eb8, 0);
    func_001c8d98(D_00351ec0, 4);
    func_001c9b90();
    func_001d2710(p + 2932);
    *(void**)p = D_0034e8b8;
    func_00319f88(p + 2824);
    *(void**)p = D_0034ee08;
    YS__OBJ_ATTACK__clear(p + 2568);                      
    func_001c0248(p + 2640);
    func_00319fb0(p);                 
    func_00105110(p);
}
}  // namespace n001cff48

// ---- 001cffe0 from src/anon/batch_w59.cpp
namespace n001cffe0 {
void func_001780d8(u8*) asm("func_001780d8");
void func_00198860(u8*, u32) asm("func_00198860");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, u32, f32, f32) asm("func_0017f5e0");
void YS__STDOBJ__start_camera(u8*, void*, u8*) asm("YS__STDOBJ__start_camera");
void func_001cffe0(u8* p) asm("func_001cffe0");
void func_001cffe0(u8* p) {
    func_001780d8(p);
    func_00198860(p, 1);
    func_0017f488(p + 320, 191, 0.0f, 0.0f);
    func_0017f5e0(p + 320, 0, 0, 0.0f, 0.0f);
    YS__STDOBJ__start_camera(p, (u8*)"00", p);
}
}  // namespace n001cffe0

// ---- 001d0068 from src/anon/batch_w1578_g.cpp
namespace n001d0068 {
void* W1578_YS_TABLE_Get(void) asm("_ZN2YS6MEMBER5TABLE3GetEv");
void* W1578_YS_CACHE_BUFF_Clear(s32) asm("_ZN2YS10CACHE_BUFF5ClearEi");
void W1578_wtarget_0016ed50(void*, u32, u32) asm("_Z25YS__OBJENTRY__ReadRequestjjjj");
void YS__MICKEY__ReadRequest(void) asm("YS__MICKEY__ReadRequest");
void YS__MICKEY__ReadRequest(void) {
    void* t = W1578_YS_TABLE_Get();
    W1578_YS_CACHE_BUFF_Clear(5000);
    W1578_wtarget_0016ed50(t, 5000, 7);
}
}  // namespace n001d0068

// ---- 001d00a8 from src/anon/batch_wcx2b_g.cpp
namespace n001d00a8 {
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
static inline QWord operator-(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
s32 YS_TABLE_Get(void) asm("_ZN2YS6MEMBER5TABLE3GetEv");
u8* YS_PLAYER_Stun(void) asm("_ZN2YS6PLAYER4StunEv");
QWord* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
QWord YS_BG_RandomPos(const QWord&, f32, f32, s32) asm("_ZN2YS2BG9RandomPosERKN2kn7FVectorEffi");
u8* AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void* JmInfo_GetCharaData(s32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
f32 f_atan2f(f32, f32) asm("f_atan2f");
void YS__MICKEY__MICKEY(f32, u8*, void*, u32, QWord*) asm("YS__MICKEY__MICKEY");
void YS__MOTION__capture(f32, u8*, u8*, s32) asm("YS__MOTION__capture");
void* YS_EFFECT_GetSystemPax(void) asm("_ZN2YS6EFFECT12GetSystemPaxEv");
s32 ryj__PAX__start(void*, s32, s32, s32, s32, u8*) asm("ryj__PAX__start");
void func_00190570(u8*, u8*) asm("func_00190570");
void func_001d00a8(void) asm("func_001d00a8");
void func_001d00a8(void) {
    s32 id = YS_TABLE_Get();
    u8* pl = YS_PLAYER_Stun();
    QWord pos = *YS__OBJ__get_pos(pl);
    pos.f[1] -= 200.0f;
    QWord tmp = YS_BG_RandomPos(pos, 200.0f, 200.0f, 0x10000);
    pos = tmp;
    QWord d = pos - *YS__OBJ__get_pos(pl);
    u8* w = AREA_Alloc(0xba0);
    void* cd = JmInfo_GetCharaData(id);
    YS__MICKEY__MICKEY(f_atan2f(d.f[0], d.f[2]), w, cd, *(u32*)(pl + 0xb38), &pos);
    YS__MOTION__capture(0.0f, w + 0x140, pl, 0xfc);
    ryj__PAX__start(YS_EFFECT_GetSystemPax(), 0x11, 1, 1, 0, pl);
    func_00190570(pl, w);
}
}  // namespace n001d00a8

// ---- 001d01e0 from src/anon/tiny_jal_wrappers.cpp
namespace n001d01e0 {
u32 func_001a8b28(u32, u32, u32, u32) asm("_Z13func_001a8b28jjjj");
u32 func_001d01e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d01e0jjjj");
u32 func_001d01e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001a8b28(r4, r5, r6, r7);                     
    r2 = (u32)(*(u16*)((u32)r2 + (s32)(36)));
    return r2;
}
}  // namespace n001d01e0

// ---- 001d0200 from src/anon/batch_w8.cpp
namespace n001d0200 {
void YS__STDOBJ__reset_special_command(void*) asm("YS__STDOBJ__reset_special_command");
void YS__PLAYER___OVR_leave_req(void*) asm("YS__PLAYER___OVR_leave_req");
void mickey_leave_req(void* o) asm("_ZN2YS3OBJ6VTABLEINS_6MICKEYEE9leave_reqEPS0_");
void mickey_leave_req(void* o) {
    YS__STDOBJ__reset_special_command(o);
    YS__PLAYER___OVR_leave_req(o);
}
}  // namespace n001d0200

// ---- 001d0228 from src/anon/batch_w8008.cpp
namespace n001d0228 {
struct W8008Obj;
struct W8008Vt { u8 pad[0x20]; void (*f20)(W8008Obj*); u8 pad2[0x78 - 0x24]; s32 (*f78)(W8008Obj*, s32, s32, s32); };
struct W8008Sub { s32 pad; s32 v; };
struct W8008Obj { W8008Vt* vt; u8 pad[0x140 - 4]; u8 mot[0x48c - 0x140]; W8008Sub* sub; };
W8008Obj* w8008_StunEnd(void) asm("_ZN2YS6PLAYER7StunEndEv");
void w8008_motion_push(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
void w8008_wt1987a8(W8008Obj*, char*, W8008Obj*) asm("_Z24YS__STDOBJ__start_camerajjjj");
s32 func_00190570(W8008Obj*, W8008Obj*) asm("func_00190570");
void YS__MOTION__capture(void*, W8008Obj*, s32, f32) asm("YS__MOTION__capture");
void YS__RECOV__Exec(s32) asm("YS__RECOV__Exec");
void w8008_recov_holylight(W8008Obj* m) asm("_ZN2YS6MICKEY15recov_holylightEv");
void w8008_recov_holylight(W8008Obj* m)
{
    m->vt->f20(m);
    W8008Obj* p = w8008_StunEnd();
    func_00190570(m, p);
    YS__MOTION__capture(m->mot, p, 253, 0.0f);
    w8008_motion_push(p->mot, 0, 0.0f, 0.0f, 0);
    w8008_wt1987a8(m, (char*)"10", p);
    YS__RECOV__Exec(10);
}
}  // namespace n001d0228

// ---- 001d02c8 from src/anon/batch_w8008.cpp
namespace n001d02c8 {
struct W8008Obj;
struct W8008Vt { u8 pad[0x20]; void (*f20)(W8008Obj*); u8 pad2[0x78 - 0x24]; s32 (*f78)(W8008Obj*, s32, s32, s32); };
struct W8008Sub { s32 pad; s32 v; };
struct W8008Obj { W8008Vt* vt; u8 pad[0x140 - 4]; u8 mot[0x48c - 0x140]; W8008Sub* sub; };
struct W8008Sys { u8 pad[0x54]; f32 scale; };
extern W8008Sys* D_00352130 asm("D_00352130");
W8008Obj* w8008_StunEnd(void) asm("_ZN2YS6PLAYER7StunEndEv");
void w8008_motion_push(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
void w8008_wt1987a8(W8008Obj*, char*, W8008Obj*) asm("_Z24YS__STDOBJ__start_camerajjjj");
s32 func_00190570(W8008Obj*, W8008Obj*) asm("func_00190570");
void YS__MOTION__capture(void*, W8008Obj*, s32, f32) asm("YS__MOTION__capture");
s32 func_001d02c8(W8008Obj* self) asm("func_001d02c8");
s32 func_001d02c8(W8008Obj* self)
{
    self->vt->f20(self);
    W8008Obj* p = w8008_StunEnd();
    func_00190570(self, p);
    YS__MOTION__capture(self->mot, p, 0xfe, 0.0f);
    w8008_motion_push(p->mot, 0, 0.0f, 0.0f, 0);
    w8008_wt1987a8(self, (char*)"20", p);
    return p->vt->f78(p, (s32)((f32)p->sub->v * D_00352130->scale), 0, 0);
}
}  // namespace n001d02c8

// ---- 001d03a0 from src/anon/batch_w112.cpp
namespace n001d03a0 {
struct Iter { u8 d[32]; };
struct Lv { u8 pad[433]; u8 cur; u8 max; };
struct Cfg2 { u8 pad[212]; f32 interval; };
struct Ch {
    u8 pad[320]; u8 mot[844]; Lv* lv; u8 pad2[1716]; u32 f2884; u8 pad3[32]; f32 timer; f32 tick; u8 flag; u8 pad4[3]; u8 eff[4];
};
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_0036e3bc asm("D_0036e3bc");
extern Cfg2* D_00352130 asm("D_00352130");
void YS__PLAYER___OVR_pre_exec(Ch*) asm("YS__PLAYER___OVR_pre_exec");
s32 func_00180618(u8*) asm("func_00180618");
void YS__SHEET__add_drive(Lv*, u32) asm("YS__SHEET__add_drive");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, u32, f32, f32) asm("func_0017f5e0");
void func_00190128(Iter*) asm("func_00190128");
void func_001d0558(Ch*) asm("func_001d0558");
void func_001d2648(u8*, u32, f32) asm("func_001d2648");
void func_001d2690(u8*, u32, f32) asm("func_001d2690");
u32 func_001d14a0(void) asm("func_001d14a0");
void func_00190878(Iter*, u32, u32) asm("func_00190878");
void func_001bd418(u32, u32, u32, Iter*, u32, u32) asm("func_001bd418");
s32 func_00197920(void) asm("func_00197920");
void YS__INTERVAL_INFO__exec(u8*) asm("YS__INTERVAL_INFO__exec");
static inline bool IsFull(Lv* l) { return l->cur >= l->max; }
void func_001d03a0(Ch* o) asm("func_001d03a0");
void func_001d03a0(Ch* o) {
    Iter it;
    YS__PLAYER___OVR_pre_exec(o);
    if (0.0f < o->timer) {
        if (func_00180618(o->mot)) {
            if ((o->tick -= D_00349e10) <= 0.0f) {
                YS__SHEET__add_drive(o->lv, 1);                      
                o->tick += D_00352130->interval;
            }
        }
        if ((o->timer -= D_00349e10) <= 0.0f) {
            o->timer = 0.0f;
            func_0017f488(o->mot, 5, 0.0f, 0.0f);
            func_0017f5e0(o->mot, 0, 0, 0.0f, 0.0f);
        }
    }
    func_00190128(&it);
    if (IsFull(o->lv)) {
        if (!o->flag) {
            func_001d0558(o);
            func_001d2648(o->eff, 0xbbc3, D_0036e3bc);                        
            func_001d2690(o->eff, 0xbbc4, D_0036e3bc);
        }
        func_00190878(&it, func_001d14a0(), 0);
        func_001bd418(o->f2884, 1, 456, &it, 1, 100);
    } else {
        if (func_00197920()) goto done;
        func_00190878(&it, (u32)o, 0);
        func_001bd418(o->f2884, 1, 455, &it, 1, 100);
    }
done:
    YS__INTERVAL_INFO__exec(o->eff);
}
}  // namespace n001d03a0

// ---- 001d0558 from src/anon/auto80_199_queue.cpp
namespace n001d0558 {
void func_001d0558(u8* a0) asm("_Z13func_001d0558Ph");
void func_001d0558(u8* a0) {
    s32 i = 10;
    u8* s1 = a0;

    while (1) {
        func_0016ac38((u32)s1, (u32)i, 1, 0, 0);
        i = i + 1;
        if (i < 22) {
            continue;
        }
        break;
    }

    *(u8*)(s1 + 2928) = 1;
}
}  // namespace n001d0558

// ---- 001d05b8 from src/anon/auto80_199_queue.cpp
namespace n001d05b8 {
void func_001d05b8(u32 a0) asm("_Z13func_001d05b8j");
void func_001d05b8(u32 a0) {
    u32 s1 = a0;
    u8 st[16];
    u8 pad[16];
    (void)pad;

    if (*(u32*)(*(u32*)(a0 + 1164) + 0) == 1) {
        func_001d6a80(*(u32*)(a0 + 2876));

        *(u32*)(s1 + 264) = *(u32*)(s1 + 264) | 0x100u;

        u32 s2 = YS__COMMAND_ELEM__Get(554);
        if (YS__OBJ__can_decide(s1, s2) != 0) {
            u32 s0 = func_001d14a0();
            func_00190128((u32)st);
            func_00190878((u32)st, s0, 0);
            YS__PARTY__exec_item(s1, s2, (u32)st, 0);
            func_001d07e0(s1);
        }
    }

    YS__PLAYER___OVR_exec(s1);
}
}  // namespace n001d05b8

// ---- 001d0678 from src/anon/batch_w274.cpp
namespace n001d0678 {
struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
static inline V4 operator*(const M4& m, const V4& v) {
    V4 r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)" : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
static inline V4 operator-(const V4& a, const V4& b) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V4 operator+(const V4& a, const V4& b) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
void YS__PLAYER___OVR_exec_command_player(u8*, u8*) asm("YS__PLAYER___OVR_exec_command_player");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, f32, f32, void*) asm("func_0017f5e0");
void func_001d07e0(u8*) asm("func_001d07e0");
void func_001d0870(u8*) asm("func_001d0870");
void YS__MICKEY___OVR_exec_command_player(u8* p, u8* msg) asm("YS__MICKEY___OVR_exec_command_player");
void YS__MICKEY___OVR_exec_command_player(u8* p, u8* msg) {
    switch (*(u16*)(msg + 2)) {
    case 452: {
        u8* m = p + 320;
        p[2804] = msg[28];
        func_0017f488(m, 194, 8.0f, 0.0f);
        func_0017f5e0(m, 4, 8.0f, 0.0f, 0);
        break;
    }
    case 455: {
        u8* m = p + 320;
        func_0017f488(m, 193, 8.0f, 0.0f);
        *(void**)(m + 404) = (void*)func_001d0870;
        asm volatile("" ::: "memory");
        *(f32*)(p + 2924) = 0.0f;
        *(f32*)(p + 2920) = 120.0f;
        break;
    }
    case 456:
        func_0017f488(p + 320, 192, 8.0f, 0.0f);
        func_001d07e0(p);
        break;
    case 457:
        *(f32*)(p + 2920) = 30.0f;
        break;
    default:
        YS__PLAYER___OVR_exec_command_player(p, msg);
        break;
    }
}
}  // namespace n001d0678

// ---- 001d07e0 from src/anon/batch_w14.cpp
namespace n001d07e0 {
void YS__LOCKON__release(void*) asm("YS__LOCKON__release");
void func_001d2710(void*) asm("func_001d2710");
void INDICATION_disable(u8*) asm("_ZN2YS10INDICATION7disableEv");
void INDICATION_disable(u8* p) {
    func_001d2710(p + 2932);
    YS__LOCKON__release(*(void**)(p + 2880));
    *(u32*)(p + 268) |= 0x200000;
}
}  // namespace n001d07e0

// ---- 001d0820 from src/anon/tiny_auto80_queue.cpp
namespace n001d0820 {
extern u8  D_00350000 asm("D_00350000");
u32 YS__OBJ__is_exist(...) asm("YS__OBJ__is_exist");
u32 func_001d0820() asm("_Z13func_001d0820v");
u32 func_001d0820() {
    u32 s1 = 0;
    u8* s0 = *(u8**)((u8*)&D_00350000 - 5816u);
    if (YS__OBJ__is_exist(s0) != 0) {
        u32 t6 = *(u32*)(s0 + 1416);
        u32 t7 = 0x02000000;
        t6 = t6 & t7;
        s1 = (t6 != 0);
    }
    return s1;
}
}  // namespace n001d0820

// ---- 001d0870 gap (never-written function)
namespace g001d0870 {
void func_001d0870(u8* p) asm("func_001d0870");
void func_001d0870(u8* p) { *(u32*)(p + 2920) = 0; }
}  // namespace g001d0870

// ---- 001d0878 from src/anon/batch_w76.cpp
namespace n001d0878 {
void func_00177dc8(u8*, u32, s32) asm("func_00177dc8");
extern u8 D_00352410[] asm("D_00352410");
extern u32 D_00352400 asm("D_00352400");
s32 func_00181978(void) asm("func_00181978");
extern u32 D_0034f240 asm("D_0034f240");
void func_001a1c90(u8*, s32, s32) asm("func_001a1c90");
s32 func_001d6d88(void) asm("func_001d6d88");
u8* func_001c1130(s32) asm("func_001c1130");
u32 func_00192048(s32) asm("func_00192048");
void func_001c11a8(s32) asm("func_001c11a8");
void func_001d0878(u8* o, u32 a, s32 kind) asm("func_001d0878");
void func_001d0878(u8* o, u32 a, s32 kind)
{
    func_00177dc8(o, a, kind);
    *(u32*)(o + 2920) = 0;
    *(u32*)o = (u32)D_00352410;
    *(u32*)(o + 2924) = 0;
    *(u32*)(o + 1416) |= 0x1000000;
    *(u32*)(o + 2928) = 0;
    D_00352400 = (u32)o;
    if (func_00181978()) {
        if (D_0034f240 & 0x40000) *(*(u8**)(o + 1164) + 431) = 4;
        else if (*(s32*)(o + 2896) == 12) func_001a1c90(*(u8**)(o + 1164), 2, -1);
        else if (func_001d6d88()) *(*(u8**)(o + 1164) + 431) = 3;
        else *(*(u8**)(o + 1164) + 431) = 1;
    }
    if (kind == 6) {
        u8* r = func_001c1130(29);                               
        *(u32*)(r + 24) = func_00192048(0xc44f);
    } else {
        func_001c11a8(29);
    }
}
}  // namespace n001d0878

// ---- 001d0980 from src/anon/batch_w1817_nsa.cpp
namespace n001d0980 {
void func_00177dc8(void*, s32, s32) asm("func_00177dc8");
s32 func_00181978() asm("func_00181978");
s32 func_00192048(s32) asm("func_00192048");
void func_001a1c90(void*, s32, s32) asm("func_001a1c90");
u8* func_001c1130(s32) asm("func_001c1130");
void func_001c11a8(s32) asm("func_001c11a8");
s32 func_001d6d88() asm("func_001d6d88");
extern u32 D_0034f240 asm("D_0034f240");
extern void* D_00352400 asm("D_00352400");
extern u8 D_00352410[] asm("D_00352410");
void func_001d0980(u8* p, s32 a1, s32 a2) asm("func_001d0980");
void func_001d0980(u8* p, s32 a1, s32 a2) {
    func_00177dc8(p, a1, a2);
    *(void**)(p + 0) = D_00352410;
    *(s32*)(p + 0xB68) = 0;
    *(s32*)(p + 0xB6C) = 0;
    *(s32*)(p + 0xB70) = 0;
    *(u32*)(p + 0x588) |= 0x01000000;
    D_00352400 = p;
    if (func_00181978() != 0) {
        if (D_0034f240 & 0x40000) {
            (*(u8**)(p + 0x48C))[0x1AF] = 4;
        } else if (*(s32*)(p + 0xB50) == 0xC) {
            func_001a1c90(*(void**)(p + 0x48C), 2, -1);
        } else if (func_001d6d88() != 0) {
            (*(u8**)(p + 0x48C))[0x1AF] = 3;
        } else {
            (*(u8**)(p + 0x48C))[0x1AF] = 1;
        }
    }
    if (a2 == 6) {
        u8* q = func_001c1130(0x1D);
        *(s32*)(q + 0x18) = func_00192048(0xC44F);
        return;
    }
    func_001c11a8(0x1D);
}
}  // namespace n001d0980


// ---- 001d0a88 (was whole asm, never written in C): _OVR_initialize override, motion set-up by mode.
// A switch on the mode (case 0, case 3, default): the case 0 body then ends in a jump (break), which keeps the
// argument set-up of its three motion calls in source order.
namespace n001d0a88 {
struct QV1d0a88 {
    f32 x, y, z, w;
    QV1d0a88() {}
    QV1d0a88(const QV1d0a88& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV1d0a88(int) { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    static QV1d0a88 Zero() { QV1d0a88 r; r.zero(); return r; }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct Ctl1d0a88 { u8 pad[431]; u8 b431; };
struct Obj1d0a88 {
    u8 pad0[264]; u32 f264;
    u8 pad1[320 - 268]; u8 motion[1164 - 320];
    Ctl1d0a88* ctl;
    u8 pad2[2896 - 1168]; s32 f2896;
    u8 pad3[2924 - 2900]; s32 mode;
};
extern u8 D_00351eb8[] asm("D_00351eb8");
void func_001780d8(Obj1d0a88*) asm("_ZN2YS6PLAYER15_OVR_initializeEv");
void func_00187818(Obj1d0a88*) asm("_ZN2YS6BTLOBJ4deadEv");
void func_0019fdc0(Obj1d0a88*, QV1d0a88, f32) asm("func_0019fdc0");
void func_001c8d80(void*, s32) asm("_ZN2YS5MUTEX4lockEi");
void func_0016ac38(Obj1d0a88*, s32, s32, s32, s32) asm("func_0016ac38");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
extern u8 D_001d0cb8[] asm("func_001d0cb8");

static inline bool chk1d0a88(s32 v, s32 lo, s32 hi) { return v != lo && v < hi; }
void func_001d0a88(Obj1d0a88* o) asm("func_001d0a88");
void func_001d0a88(Obj1d0a88* o)
{
    func_001780d8(o);
    s32 m = o->mode;
    switch (m) {
    case 0:
        if (chk1d0a88(o->f2896, 0, 7)) {
            func_0017f488(o->motion, 53, 0.0f, 0.0f);
            func_0017f5e0(o->motion, 6, 8.0f, 0.0f, 0);
            func_0017f5e0(o->motion, 0, 0.0f, 0.0f, 0);
            o->ctl->b431 = 2;
            func_001c8d80(D_00351eb8, 0);
        }
        break;
    case 3: func_00187818(o); break;
    default:
        if (o->f2896 == 0) {
            o->f264 |= 0x100000;
            if (m == 1) {
                func_0017f488(o->motion, 0, 0.0f, 0.0f);
                func_0017f488(o->motion, 0, 0.0f, 0.0f);
            } else {
                func_0017f488(o->motion, 4, 0.0f, 0.0f);
            }
            for (s32 i = 15; i < 28; i++) func_0016ac38(o, i, 1, 0, 0);
        } else {
            func_0017f488(o->motion, 53, 0.0f, 0.0f);
            if (o->mode == 1) {
                func_0017f5e0(o->motion, 6, 8.0f, 0.0f, 0);
                func_0017f5e0(o->motion, 0, 0.0f, 0.0f, 0);
            } else {
                QV1d0a88 v;
                v.zero();
                func_0019fdc0(o, v, 1.0f);
                func_0017f5e0(o->motion, 4, 8.0f, 0.0f, D_001d0cb8);
            }
        }
        break;
    }
}
}
