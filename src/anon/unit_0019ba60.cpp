#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../yasui/libys/obj.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../yasui/libys/lockon.hpp"
#include "tiny_auto80_solver_structs.hpp"

// ---- 0019ba60 from src/anon/tiny_auto80_queue.cpp
namespace n0019ba60 {
u32 func_001ba028(...) asm("func_001ba028");
u32 func_0019baa8(...) asm("func_0019baa8");
u32 ctarget_0019ba60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_0019ba60jjjj");
u32 ctarget_0019ba60(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a0;
    u32 s1 = 0;
    u32 r = func_001ba028(s0);                      
    if (r != 0) {
        u32 r2 = func_0019baa8(s0);
        s1 = (r2 == 0) ? 1u : 0u;
    }
    return s1;
}
}  // namespace n0019ba60

// ---- 0019baa8 from src/yasui/libys/obj.cpp
namespace YS {  // n0019baa8
u32 OBJ::is_leave() {
    u32 t6 = *(u32*)((u32)this + 264);
    u32 t7 = (u32)(0x0008u << 16);
    t7 = (u32)(t6 & t7);
    u32 v0 = 0u;
    if (t7 != 0u) goto L1;
    t7 = (u32)(0x1000u << 16);
    t7 = (u32)(t6 & t7);
    if (t7 == 0u) goto L0;
L1:
    v0 = 1u;
L0:
    return v0;
}
}  // namespace YS (0019baa8)

// ---- 0019bad8 from src/anon/batch_w1735.cpp
namespace n0019bad8 {
struct Obj {
    u8 pad0[0x108];
    u32 flag108 : 1;
    u32 rest108 : 31;
    u8 pad1[0x7f8 - 0x10c];
    u32 flag7f8 : 1;
    u32 rest7f8 : 31;
};
s32 w1735_Obj_is_attach(Obj*) asm("_ZN2YS3OBJ9is_attachEv");
s32 func_0019bad8(Obj* o) asm("func_0019bad8");
s32 func_0019bad8(Obj* o) {
    if (!o->flag7f8) return 0;
    if (o->flag108) return 0;
    return w1735_Obj_is_attach(o) == 0;
}
}  // namespace n0019bad8

// ---- 0019bb18 from src/anon/tiny_auto80_queue.cpp
namespace n0019bb18 {
u32 func_0019bb18(u32 a0) asm("_Z13func_0019bb18j");
u32 func_0019bb18(u32 a0) {                   
    u32 v0 = 0u;
    u32 t7 = *(u32*)((u32)a0 + (s32)(264));
    t7 = (u32)(t7 & 0x0002u);
    if (t7 != 0u) {
        return v0;
    }
    t7 = *(u32*)((u32)a0 + (s32)(2040));
    t7 = (u32)(t7 & 0x1000u);
    if (t7 != 0u) {
        return v0;
    }
    a0 = *(u32*)((u32)a0 + (s32)(2088));
    if (a0 == 0u) {
        return v0;
    }
    t7 = *(u32*)((u32)a0 + (s32)(0));
    v0 = (u32)((s32)t7 > 0);
    return v0;
}
}  // namespace n0019bb18

// ---- 0019bb58 from src/anon/tiny_auto80_queue.cpp
namespace n0019bb58 {
u32 func_0019bb58(u32 a0) asm("_Z13func_0019bb58j");
u32 func_0019bb58(u32 a0) {
    u32 v0 = 0u;
    u32 t7 = *(u32*)((u32)a0 + (s32)(2040));
    t7 = (u32)(t7 & 0x0004u);
    if (t7 != 0u) {
        return v0;
    }
    t7 = *(u32*)((u32)a0 + (s32)(264));
    t7 = (u32)(t7 & 0x0008u);
    if (t7 != 0u) {
        return v0;
    }
    a0 = *(u32*)((u32)a0 + (s32)(1296));
    if (a0 == 0u) {
        return v0;
    }
    t7 = *(u32*)((u32)a0 + (s32)(0));
    v0 = (u32)((s32)t7 > 0);
    return v0;
}
}  // namespace n0019bb58

// ---- 0019bb98 from src/anon/batch_w68.cpp
namespace n0019bb98 {
f32 func_0016a0a0(void*) asm("func_0016a0a0");
s32 func_001c0cd8(void*) asm("func_001c0cd8");
s32 func_0019c6f0(void*) asm("func_0019c6f0");
s32 func_0019bb98(u8* p) asm("func_0019bb98");
s32 func_0019bb98(u8* p) {
    s32 r = 0;
    if (func_0016a0a0(p) == 0.0f || (*(u32*)(p + 264) & 4) || (*(u32*)(p + 352) & 0x2000000)
        || func_001c0cd8(p) || (*(u32*)(*(u8**)(p + 12) + 8) & 4) || func_0019c6f0(p))
        r = 1;
    return r;
}
}  // namespace n0019bb98

// ---- 0019bc38 from src/anon/batch_w1798.cpp
namespace n0019bc38 {
struct Obj_19bc38 { u8 p0[0x108]; u32 f108; u8 p1[0x570 - 0x10c]; u8* p570; u8 p2[0x7f8 - 0x574]; u32 f7f8; };
u32 get_type_19bc38(Obj_19bc38*) asm("_ZN2YS3OBJ8get_typeEv");
s32 each_coll_19bc38(Obj_19bc38*, s32, void*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
s32 battle_19bc38(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
s32 attach_19bc38(Obj_19bc38*) asm("_ZN2YS3OBJ9is_attachEv");
extern u32 D_0034f240 asm("D_0034f240");
s32 func_0019bc38(Obj_19bc38* p) asm("func_0019bc38");
s32 func_0019bc38(Obj_19bc38* p) {
    switch (get_type_19bc38(p)) {
    case 8: case 13:
        if (battle_19bc38() && (D_0034f240 & 0x10000)) return 0;
    default:
        if (attach_19bc38(p) && (*(u32*)(p->p570 + 0x588) & 0x80)) return 0;
        if (!(p->f7f8 & 0x400)) return 0;
        if (p->f108 & 0x20) return 0;
        if (each_coll_19bc38(p, 3, 0)) return 1;
    case 0: case 1: case 5:
        return 0;
    }
}
}  // namespace n0019bc38

// ---- 0019bd08 from src/anon/batch_w80.cpp
namespace n0019bd08 {
struct U1_Lock { u8 pad[4]; u32 mask; };
struct U1_Lk { u8 pad[1140]; u8 a[8]; u8 b[8]; u8 pad2[2264 - 1156]; U1_Lock* lock; };
s32 func_0019f528(u8*, s32) asm("func_0019f528");
s32 func_0019f550(u8*, s32) asm("func_0019f550");
s32 func_0019bd08(U1_Lk* o, s32 n) asm("func_0019bd08");
s32 func_0019bd08(U1_Lk* o, s32 n) {
    if (!o->lock) return 0;
    if (func_0019f528(o->b, n)) return 1;
    if (func_0019f550(o->b, n)) return 0;
    if (func_0019f528(o->a, n)) return 1;
    if (func_0019f550(o->a, n)) return 0;
    return (o->lock->mask & (1 << n)) != 0;
}
}  // namespace n0019bd08

// ---- 0019bdc8 from src/anon/batch_w76.cpp
namespace n0019bdc8 {
u8 func_0019f6f0(u8*, u32, u32) asm("func_0019f6f0");
u8 func_0019f740(u8*, u32, u32) asm("func_0019f740");
u8 func_0019bd08(u8*, u32) asm("func_0019bd08");
u8 func_0019bdc8(u8* o, u32 a, u32 b) asm("func_0019bdc8");
u8 func_0019bdc8(u8* o, u32 a, u32 b)
{
    u8* s = o + 1044;
    if (func_0019f6f0(s, a, b)) return 1;
    if (func_0019f740(s, a, b)) return 0;
    s = o + 948;
    if (func_0019f6f0(s, a, b)) return 1;
    if (func_0019f740(s, a, b)) return 0;
    return func_0019bd08(o, b);
}
}  // namespace n0019bdc8

// ---- 0019be88 from src/anon/auto80_199_queue.cpp
namespace n0019be88 {
extern "C" u32 YS_STATUS_IsBattleMode(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
void func_0019be88(u32 a0) asm("_Z13func_0019be88j");
void func_0019be88(u32 a0) {
    u32 v0 = (*(u32 (**)(u32))(*(u32*)a0 + 0x40))(a0);
    if (v0 == 0) {
        return;
    }
    if ((*(u32*)(a0 + 0x588) & 4) == 0) {
        return;
    }
    if ((*(u32*)(a0 + 0x108) & 0x00100000) == 0) {
        return;
    }
    if (YS_STATUS_IsBattleMode() != 0) {
        return;
    }
    *(u32*)(a0 + 0x108) = *(u32*)(a0 + 0x108) & 0xffefffff;
}
}  // namespace n0019be88

// ---- 0019bf00 from src/anon/batch_w26.cpp
namespace n0019bf00 {
inline void* operator new(unsigned int, void* p) { return p; }
s32 func_0017a538(void*) asm("func_0017a538");
s32 func_0019bf00(u8* o) asm("func_0019bf00");
s32 func_0019bf00(u8* o) {
    if (*(u32*)(o + 1416) & 0x80) {
        if (func_0017a538(o)) return 1;
    }
    u32 m = *(u32*)(o + 264) & 0x100000;
    return m != 0;
}
}  // namespace n0019bf00

// ---- 0019bf50 from src/anon/batch_w62.cpp
namespace n0019bf50 {
struct u128 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vq {
    union { u128 q; f32 f[4]; };
    Vq() {}
    Vq(const Vq& o) { QCOPY(this, &o); }
    void operator=(const Vq& o) { if (this != &o) QCOPY(this, &o); }
};
struct S19b {
    u8 pad[1344];
    Vq a;
    u8 pad2[64];
    Vq b;
    Vq c;
    u8 pad3[80];
    u64 w;
};
void func_00185118(S19b*) asm("func_00185118");
void func_00143928(Vq*) asm("func_00143928");
s32 func_0019bf50(S19b* p, Vq* v) asm("func_0019bf50");
s32 func_0019bf50(S19b* p, Vq* v) {
    func_00185118(p);
    p->b = p->a;
    p->c = *v;
    p->w &= ~1ULL;
    func_00143928(&p->b);
    return (s32)(p->w >> 32) & 1;
}
}  // namespace n0019bf50

// ---- 0019bfd0 from src/anon/batch_w1792.cpp
namespace n0019bfd0 {
struct QW1792 {
    f32 x, y, z, w;
    QW1792& operator=(const QW1792& o) {
                                 
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Obj1792 {
    u8 pad[0x590];
    QW1792 pos;                 
    QW1792 rot;                 
    u8 pad2[0x10];
    QW1792 tgt;                 
    u8 pad3[0x30];
    u64 flags;                  
};
void func_00185118(Obj1792*, QW1792*) asm("func_00185118");
void func_00143928(QW1792*) asm("func_00143928");
s32 func_0019bfd0(Obj1792* self, QW1792* v) asm("func_0019bfd0");
s32 func_0019bfd0(Obj1792* self, QW1792* v)
{
    func_00185118(self, v);
    self->pos = *v;
    self->pos.w = 1.0f;
                                  
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&self->rot) : "memory");
    self->flags |= 1;
    func_00143928(&self->pos);
    QW1792 d;
    f32 len;
                                        
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&self->tgt), "r"(v), "r"(&d) : "memory");
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(len) : "r"(&d) : "$8", "memory");
    return len < 5.0f;
}
}  // namespace n0019bfd0

// ---- 0019c090 from src/anon/batch_w1762.cpp
namespace n0019c090 {
struct T9_1762 { u8 pad[8]; u32 f:1; bool F() { return f; } };
struct RB1762 { u32 r0:24; u32 r24:1; u32 r25:7; };
struct T10_1762 {
    u8 pad[12]; T9_1762* p; u8 pad2[0x108 - 16];
    u32 q0:23; u32 q23:1; u32 q24:8;
    u8 p3[0x160 - 0x10c];
    u32 r0:5; u32 r5:1; u32 r6:18; u32 r24:1; u32 r25:7;
                                                                                            
    bool A() { bool b = false; if (r5 || ((RB1762*)&p3[0x160 - 0x10c])->r24) b = true; return b; }
};
s32 func_0019c090(T10_1762* a0) asm("func_0019c090");
s32 func_0019c090(T10_1762* a0) {
    s32 r = 0;
    if (a0->p->F() || a0->A() || a0->q23) r = 1;
    return r;
}
}  // namespace n0019c090

// ---- 0019c0f8 from src/anon/batch_w27.cpp
namespace n0019c0f8 {
s32 func_0019c090(void*) asm("func_0019c090");
s32 func_0019c0f8(u8* p) asm("func_0019c0f8");
s32 func_0019c0f8(u8* p) {
    s32 r = 0;
    if (func_0019c090(p)) {                   
        if (!(*(u32*)(p + 352) & 0x20)) {
            u32 m = *(u32*)(*(u8**)(p + 12) + 8) & 0x200;
            r = m == 0;
        }
    }
    return r;
}
}  // namespace n0019c0f8

// ---- 0019c158 from src/anon/batch_w1667.cpp
namespace n0019c158 {
u8 func_0019c158(u8* p) asm("func_0019c158");
u8 func_0019c158(u8* p) { return (*(u16*)(*(u8**)(p + 8) + 0x48) >> 3) & 1; }
}  // namespace n0019c158

// ---- 0019c170 from src/anon/batch_w235.cpp
namespace n0019c170 {
struct W235B { u8 p[352]; u32 fl; u8 q[1060]; u32 fl2; u8 r[644]; W235B* o2064; u8 r2[712]; f32 f; };
s32 func_0016a040(W235B*) asm("func_0016a040");
static inline bool w235_pos(f32 x) { return 0.0f < x; }
s32 func_0019c170(W235B* o) asm("func_0019c170");
s32 func_0019c170(W235B* o) {
    s32 r = 0;
    W235B* p;
    if (o->fl & 0x800000) goto set;
    p = o->o2064;
    if (p) {
        if (!(p->fl & 0x10000000)) {
            if (!(p->fl2 & 0x8000)) goto set;
        }
    }
    if (o->fl2 & 2) {
        bool b = w235_pos(o->f);
        if (b) goto set;
    }
    if (func_0016a040(o) == 15) {
        set:
        r = 1;
    }
    return r;
}
}  // namespace n0019c170

// ---- 0019c218 from src/anon/batch_w1946.cpp
namespace n0019c218 {
struct A19 { u8 p0[0x140]; s32 f140; u8 p1[0x1c]; s32 f160; s32 p164; s32 f168; u8 p2[0x50c - 0x16c]; s32 f50c; u8 p3[0x9b0 - 0x510]; f32 f9b0; };
struct B19 { u16 h0; u16 p2[5]; s32 f0c; u8 p10[0x12]; u16 h22; };
s32 func_0019c090(A19*, B19*) asm("func_0019c090");
s32 func_001917c0(void) asm("func_001917c0");
static inline __attribute__((always_inline)) bool anyf_0019c218(s32 f) {
    bool v = 0;
    if (f & 4) goto s;
    if (f & 8) goto s;
    if (!(f & 0x10)) goto e;
s:
    v = 1;
e:
    return v;
}
static inline __attribute__((always_inline)) s32 h2_0019c218(A19* a, B19* b) {
    s32 r = 0;
    if (a->f9b0 <= 0.0f) {
        if (a->f140 == 0) goto one;
        if (anyf_0019c218(a->f160)) goto one;
        if ((u8)((b->f0c >> 7) & 1)) goto t4;
        if (a->f160 & 0x400) goto one;
        if (a->f168 & 0x20) goto one;
    t4:
        if (b->f0c & 4) {
        one:
            r = 1;
        }
    }
    return r;
}
static inline __attribute__((always_inline)) s32 h1_0019c218(A19* a, B19* b) {
    if ((b->f0c & 2) && func_0019c090(a, b)) return 0;
    if ((a->f160 & 0x20000) && a->f50c == b->h0) return 1;
    if (b->h22 != 0 && (a->f160 & 0x200000) && a->f50c == b->h22) return 1;
    if (a->f160 & 0x40000000) return 0;
    if ((u8)((b->f0c >> 4) & 1)) {
    } else if (func_001917c0()) return 0;
    if ((u8)((b->f0c >> 8) & 1) && (a->f160 & 0x80000)) return 1;
    return h2_0019c218(a, b);
}
s32 func_0019c218(A19* a, B19* b) asm("func_0019c218");
s32 func_0019c218(A19* a, B19* b) {
    return h1_0019c218(a, b);
}
}  // namespace n0019c218

// ---- 0019c3a8 gap function (unwritten before; flag test on +0x160)
namespace n0019c3a8 {
static inline bool g0019c3a8_bit(u32 v, u32 m) { return (v & m) != 0; }
static inline bool g0019c3a8_low(u32 f) { return g0019c3a8_bit(f, 4) || g0019c3a8_bit(f, 8) || g0019c3a8_bit(f, 0x10); }
u32 func_0019c3a8(u8* o) asm("func_0019c3a8");
u32 func_0019c3a8(u8* o) {
    u32 f = *(u32*)(o + 352);
    u32 r = 0;
    if ((f & 0x200000) || g0019c3a8_low(f)) r = 1;
    return r;
}
}  // namespace n0019c3a8

// ---- 0019c400 from src/yasui/libys/obj.cpp
namespace YS {  // n0019c400
u32 OBJ::is_xyzrot() {
    u32 v = *(u32*)((u32)this + 2040);
    v &= 0x0008u;
    return (v != 0);
}
}  // namespace YS (0019c400)

// ---- 0019c410 from src/yasui/libys/obj.cpp
namespace YS {  // n0019c410
u32 func_001a7790(...) asm("func_001a7790");
u32 OBJ::is_culling() {
    u32 r2 = 0u;
    u32 r15 = *(u32*)((u32)this + (s32)(2040));
    r15 = (u32)(r15 & 0x0400u);
    u32 r4 = (u32)((s32)(u32)this + (1856));
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_001a7790)(r4);
    }
    return r2;
}
}  // namespace YS (0019c410)

// ---- 0019c440 from src/anon/auto200_999.cpp
namespace n0019c440 {
struct Info_0019c440 {
    u8 pad0[72];
    u16 bits0 : 5;
    u16 bit5 : 1;
    bool flag5() { return bit5; }
};
struct Obj_0019c440 {
    u8 pad0[8];
    Info_0019c440* info;  // +8
    u8 pad1[2268 - 12];
    u8 state;             // +2268
};
u32 ctarget_0019c440(u32 a0, u32, u32, u32) asm("_Z16ctarget_0019c440jjjj");
u32 ctarget_0019c440(u32 a0, u32, u32, u32) {
    Obj_0019c440* o = (Obj_0019c440*)a0;
    return o->info->flag5() && o->state == 1;
}
}  // namespace n0019c440

// ---- 0019c470 from src/anon/tiny_jal_wrappers.cpp
namespace n0019c470 {
u32 func_0016a070(u32, u32, u32, u32) asm("_Z13func_0016a070jjjj");
u32 func_0019c470(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0019c470jjjj");
u32 func_0019c470(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_0016a070(r4, r5, r6, r7);
    r2 = (u32)(r2 ^ 0x0065u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // namespace n0019c470

// ---- 0019c498 from src/anon/auto200_999.cpp
namespace n0019c498 {
struct Info_0019c498 {
    u8 pad0[8];
    u32 flags;  // +8
};
struct Obj_0019c498 {
    u8 pad0[12];
    Info_0019c498* info;  // +12
    u8 pad1[352 - 16];
    u32 f352;             // +352
    u32 f356;
    u32 f360;             // +360
};
u32 func_0019c498(u32 a0) asm("_Z13func_0019c498j");
u32 func_0019c498(u32 a0) {
    Obj_0019c498* o = (Obj_0019c498*)a0;
    return (o->info->flags & 0x80) && !(o->f352 & 0x4000) && !(o->f360 & 2);
}
}  // namespace n0019c498

// ---- 0019c4d0 from src/yasui/libys/obj.cpp
namespace YS {  // n0019c4d0
u32 OBJ::is_updown() {
    u32 p = *(u32*)((u32)this + 12);
    u32 v = *(u32*)((u32)p + 8);
    v &= 0x8u;
    return (0u < v);
}
}  // namespace YS (0019c4d0)

// ---- 0019c4e8 from src/yasui/libys/obj.cpp
namespace YS {  // n0019c4e8
u32 OBJ::can_capture_control() {
    u32 v = *(u32*)((u32)this + 352);
    v &= 0x0004u;
    return (v != 0);
}
}  // namespace YS (0019c4e8)

// ---- 0019c4f8 from src/anon/perm_0019c4f8.cpp
namespace n0019c4f8 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
s32 func_0019c6f0(u8 *) asm("func_0019c6f0");
s32 func_0019c4f8(u8 *p) asm("func_0019c4f8");
s32 func_0019c4f8(u8 *p)
{
  u32 f = *((u32 *) (p + 2040));
  u32 m;
  u32 n = f & 4;
  s32 r = 0;
  if (((((n || (!(f & 0x400))) || ((*((u32 *) (p + 264))) & 0x40)) || ((*((u32 *) (p + 352))) & 0x8000000)) || func_0019c6f0(p)) || ((*((u32 *) ((*((u8 **) (p + 12))) + 8))) & 0x2000))
  {
    r = 1;
  }
  return r;
}
}  // namespace n0019c4f8

// ---- 0019c590 from src/anon/batch_w8016.c
namespace n0019c590 {
typedef struct Sum { u8 pad[0x588]; u32 w; } Sum;
s32 Sum_GetMode0(void) asm("_ZN2YS6SUMMON7GetModeEv");
s32 func_0019c590(Sum* s) asm("func_0019c590");
s32 func_0019c590(Sum* s) {
    u32 w = s->w;
    if (w & 4) return 0;
    if (w & 0x40) return 0;
    return Sum_GetMode0() == 1;
}
}  // namespace n0019c590

// ---- 0019c5d0 from src/anon/auto80_199_queue.cpp
namespace n0019c5d0 {
u32 func_0019c5d0(u32 a0) asm("_Z13func_0019c5d0j");
u32 func_0019c5d0(u32 a0) {
    u32 uVar1;
    u32 s0 = a0;
    u32 t7;
    u32 t6;

    t7 = *(u32 *)(s0 + 0x10c);
    t6 = t7 & 0x100;
    t7 = t7 & 0x80;
    uVar1 = 0;
    if (t7 != 0) {
        goto LAB_TRUE;
    }
    if (t6 != 0) {
        uVar1 = 1;
        goto LAB_RET;
    }
    if (func_0019c590() != 0) {
        goto LAB_TRUE;
    }
    if (func_0019c768(s0) != 0) {
        uVar1 = 1;
        goto LAB_RET;
    }
    if (func_002be5f8() != 0) {
LAB_TRUE:
        uVar1 = 1;
    }
LAB_RET:
    return uVar1;
}
}  // namespace n0019c5d0

// ---- 0019c650 from src/anon/batch_wcx.cpp
namespace n0019c650 {
extern u8 D_00350e8c asm("D_00350e8c");
extern u32 D_0034f240 asm("D_0034f240");
s32 func_0019c590(void) asm("func_0019c590");
s32 func_0019c768(u8*) asm("func_0019c768");
s32 func_002be5f8(void) asm("func_002be5f8");
s32 func_0019c650(u8* p) asm("func_0019c650");
s32 func_0019c650(u8* p)
{
    s32 r;
    u32 f = *(u32*)(p + 268);
    u32 b = f & 0x80;
    u32 a = f & 0x200;
    r = 0;
    if (b || a || D_00350e8c || func_0019c590() || (D_0034f240 & 0x1000) || func_0019c768(p) || func_002be5f8()) r = 1;
    return r;
}
}  // namespace n0019c650

// ---- 0019c6f0 from src/anon/auto80_199_queue.cpp
namespace n0019c6f0 {
u32 func_0019c6f0(u32 a0) asm("_Z13func_0019c6f0j");
u32 func_0019c6f0(u32 a0) {
    u32 s0 = a0;
    u32 uVar1;

    uVar1 = 0;
    if (func_001d7b80(a0 + 0x518) != 0) {
        goto LAB_TRUE;
    }
    if (func_0019c590(s0) != 0) {
        goto LAB_TRUE;
    }
    if (func_0019c768(s0) != 0) {
        uVar1 = 1;
        goto LAB_RET;
    }
    if (func_002be5f8() != 0) {
LAB_TRUE:
        uVar1 = 1;
    }
LAB_RET:
    return uVar1;
}
}  // namespace n0019c6f0

// ---- 0019c768 from src/yasui/libys/obj.cpp
namespace YS {  // n0019c768
u32 OBJ::is_ghost() {
    u32 v = *(u32*)((u32)this + 264);
    v &= 0x0400u;
    return (v != 0);
}
}  // namespace YS (0019c768)

// ---- 0019c778 from src/anon/batch_w82.cpp
namespace n0019c778 {
struct Vec82 {
    f32 x, y, z, w;
    Vec82& operator=(const Vec82& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct V82z { f32 v[4]; } __attribute__((aligned(16)));
static inline f32 Dot82(const void* a, const void* b)
{
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}
s32 func_001b9d40(u8*, u8*) asm("func_001b9d40");
void func_0016af58(void*, u8*) asm("func_0016af58");
s32 func_0019c778(u8* a0, u8* a1) asm("func_0019c778");
s32 func_0019c778(u8* a0, u8* a1)
{
    s32 r = 0;
    Vec82 t;
    if (func_001b9d40(a0, a1) && 0.0f < *(f32*)(a0 + 28)) {                             
        func_0016af58(&t, a0);
        if (Dot82(a1, &t) >= 0.7f && Dot82(a1, a0 + 16) >= 0.7f) r = 1;
    }
    return r;
}
}  // namespace n0019c778

// ---- 0019c838 from src/anon/batch_w28.cpp
namespace n0019c838 {
u32 func_0019bad8(void*) asm("func_0019bad8");
u32 func_0019c838(u8* p) asm("func_0019c838");
u32 func_0019c838(u8* p) {
    u32 r = 0;
    if (func_0019bad8(p) || (*(u32*)(p + 0x588) & 0x8000000)) {
        u32 m = *(u32*)(p + 0x108) & 0x80;
        r = m == 0;
    }
    return r;
}
}  // namespace n0019c838

// ---- 0019c898 from src/yasui/libys/obj.cpp
namespace YS {  // n0019c898
u32 OBJ::IsKinoko(int v) {
    u32 r4 = (u32)v;
    r4 = (u32)((s32)r4 + (-1047));
    r4 = ((u32)r4 < 0x0000000du);
    u32 r2 = r4;
    return r2;
}
}  // namespace YS (0019c898)

// ---- 0019c8a8 from src/anon/batch_w3.cpp
namespace n0019c8a8 {
u8 func_0019c898(u32) asm("func_0019c898");
u32 func_0016a070() asm("func_0016a070");
u32 func_0019c8a8() asm("func_0019c8a8");
u32 func_0019c8a8() { return func_0019c898(func_0016a070()); }
}  // namespace n0019c8a8

// ---- 0019c8d0 from src/anon/batch_w27.cpp
namespace n0019c8d0 {
void func_00190128(void*) asm("func_00190128");
void func_0019ca20(void*) asm("func_0019ca20");
extern void* D_00350444 asm("D_00350444");
void func_0019c8d0(u32* p) asm("func_0019c8d0");
void func_0019c8d0(u32* p) {
    p[0] = 0;
    func_00190128(p + 1);
    p[6] = 0;
    p[8] = 0;
    p[11] = 0;
    func_0019ca20(p);
    D_00350444 = D_00350444 ? D_00350444 : p;
}
}  // namespace n0019c8d0

// ---- 0019c920 from src/anon/batch_w28.cpp
namespace n0019c920 {
void func_00190128(void*) asm("func_00190128");
void func_0019ca20(void*) asm("func_0019ca20");
extern void* D_00350444 asm("D_00350444");
void func_0019c920(u8* p) asm("func_0019c920");
void func_0019c920(u8* p) {
    *(u32*)p = 0;
    func_00190128(p + 4);
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x20) = 0;
    *(u32*)(p + 0x2c) = 0;
    func_0019ca20(p);
    D_00350444 = D_00350444 ? D_00350444 : p;
}
}  // namespace n0019c920

// ---- 0019c970 from src/anon/batch_w13.cpp
namespace n0019c970 {
void func_0019cc20(void*) asm("func_0019cc20");
extern void* D_00350444 asm("D_00350444");
void func_0019c970(void* p) asm("func_0019c970");
void func_0019c970(void* p) {
    func_0019cc20(p);
    D_00350444 = (D_00350444 == p) ? 0 : D_00350444;
}
}  // namespace n0019c970

// ---- 0019c9a8 from src/anon/batch_w14.cpp
namespace n0019c9a8 {
void func_0019cc20(void*) asm("func_0019cc20");
extern void* D_00350444 asm("D_00350444");
void LOCKON_dtor(void*) asm("_ZN2YS6LOCKOND1Ev");
void LOCKON_dtor(void* l) {
    func_0019cc20(l);
    D_00350444 = D_00350444 == l ? 0 : D_00350444;
}
}  // namespace n0019c9a8

// ---- 0019c9e0 from src/anon/tiny_auto80_queue.cpp
namespace n0019c9e0 {
u32 func_0015a638(...) asm("func_0015a638");
void func_0019c9e0(u32 a0, u32 a1) asm("_Z13func_0019c9e0jj");
void func_0019c9e0(u32 a0, u32 a1) {
    *(u32*)((u32)a0 + (s32)(40)) = a1;
    u32 s0 = a0;
    if (*(u32*)((u32)s0 + (s32)(0)) == 2u) {
        func_0015a638((u32)((s32)a0 + (4)));
    }
    *(u32*)((u32)s0 + (s32)(44)) = 0u;
}
}  // namespace n0019c9e0

// ---- 0019ca20 from src/yasui/libys/lockon.cpp
namespace YS {  // n0019ca20
void LOCKON::reset_player() { reinterpret_cast<LOCKONLayout*>(this)->player = 0; }
}  // namespace YS (0019ca20)

// ---- 0019ca28 from src/anon/batch_w43.cpp
namespace n0019ca28 {
void func_001902a8(void*, void*) asm("func_001902a8");
void func_0019ca28(u8* p, u32* s) asm("func_0019ca28");
void func_0019ca28(u8* p, u32* s) {
    u32 buf[8];
    buf[3] = 0;
    *(u32*)(p + 4) = s[0];
    *(u32*)(p + 8) = s[1];
    *(u32*)(p + 12) = s[2];
    *(u32*)(p + 16) = s[3];
    *(u32*)(p + 20) = s[4];
    func_001902a8(p + 4, buf);
    *(u32*)(p + 36) = ((u8*)buf[3])[1];
}
}  // namespace n0019ca28

// ---- 0019ca90 from src/anon/auto80_199_queue.cpp
namespace n0019ca90 {
void func_0019ca90(u32 a0, u32 a1, u32 a2) asm("_Z13func_0019ca90jjj");
void func_0019ca90(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 uVar1;

    if (*(u32 *)s0 != 0) {
        func_0019cc20();
    }
    *(u32 *)s0 = s1;
    if ((s2 != 0) && (func_00190140(s2) != 0)) {
        func_0019ca28(s0, s2);
    }
    if (s1 == 1) {
        goto LAB_SET_ZERO;
    }
    if (s1 == 2) {
        func_002ba2e8(7, 0);
        func_0019d438(s0);
        uVar1 = func_0016bff0(*(u32 *)s2);
        func_001991a8(0x9e, uVar1);
    }
LAB_TAIL:
    func_0019cb48(s0);
    func_0019d260(s0);
    return;
LAB_SET_ZERO:
    *(u32 *)(s0 + 0x1c) = 0;
    goto LAB_TAIL;
}
}  // namespace n0019ca90

// ---- 0019cb48 from src/anon/batch_w231.cpp
namespace n0019cb48 {
struct W231Ent { u32 a; u32 b; u32 c; };
struct W231Q { char p[0x108]; u32 flags; char q[0x48c - 0x10c]; W231Ent* tab; };
struct W231S { char p[4]; W231Q* q; char r[0x18]; u32 w20; u32 idx; W231Q* q28; };
void func_0019cbe8(W231S*) asm("func_0019cbe8");
u32* func_00177860(W231Q*) asm("func_00177860");
s32 func_0019ba60(W231Q*) asm("func_0019ba60");
u32 func_00154b40(u32, u32) asm("func_00154b40");
void func_0019cb48(W231S* s) asm("func_0019cb48");
void func_0019cb48(W231S* s) {
    u32 z[5];
    z[3] = 0;
    func_0019cbe8(s);
    if (s->q28->tab) {
        if (*func_00177860(s->q28) & 0x80000) {
            if (func_0019ba60(s->q)) {
                if (!(s->q->flags & 0x4000)) {
                    W231Ent* t = s->q->tab;
                    if (t) {
                        W231Ent* e = (W231Ent*)(s->idx * 12 + (u32)t);
                        s->w20 = func_00154b40(e->a, e->b);
                    }
                }
            }
        }
    }
}
}  // namespace n0019cb48

// ---- 0019cbe8 from src/anon/tiny_auto80_queue.cpp
namespace n0019cbe8 {
u32 func_00154b80(...) asm("func_00154b80");
void func_0019cbe8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0019cbe8jjjjjjjj");
void func_0019cbe8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(32));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00154b80)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u32*)((u32)r16 + (s32)(32)) = 0u;
    }
}
}  // namespace n0019cbe8

// ---- 0019cc20 from src/anon/batch_w44.cpp
namespace n0019cc20 {
void func_0019d228(void*) asm("func_0019d228");
void func_0019cbe8(void*) asm("func_0019cbe8");
void func_0019d480(void*) asm("func_0019d480");
void func_00190128(void*) asm("func_00190128");
void func_0019cc20(s32* p) asm("func_0019cc20");
void func_0019cc20(s32* p) {
    if (*p) {
        func_0019d228(p);
        func_0019cbe8(p);
        if (*p == 2) func_0019d480(p);
        *p = 0;
        func_00190128(p + 1);
    }
}
}  // namespace n0019cc20

// ---- 0019cc88 from src/anon/auto80_199_queue.cpp
namespace n0019cc88 {
void func_0019ca90(u32 a0, u32 a1, u32 a2) asm("_Z13func_0019ca90jjj");
void func_0019cc88(u32 a0, u32 a1) asm("_Z13func_0019cc88jj");
void func_0019cc88(u32 a0, u32 a1) {
    u32 s0 = a0 + 4;
    u32 s1 = a0;
    u32 s2 = a1;
    u32 v0;
    u32 t7;

    if (func_00190680(s0) != 0) {
        return;
    }
    v0 = func_001906c0(s0);
    s0 = v0;
    v0 = func_001906c0(s2);
    if (s0 != v0) {
        func_0019ca90(s1, *(u32 *)s1, s2);
        goto LAB_TAIL;
    }
    func_0019ca28(s1, s2, s2);
    t7 = *(u32 *)(s1 + 0x18);
    if (t7 != 0) {
        *(u32 *)(s1 + 0x18) = func_0013e5a8(t7);
    }
LAB_TAIL:
    func_0019cb48(s1);
}
}  // namespace n0019cc88

// ---- 0019cd40 from src/anon/batch_w251.cpp
namespace n0019cd40 {
struct JV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct JO;
typedef void (*JVF)(JV*, JO*);
struct JO { JVF* vt; };
struct JP { u8 pad[0x588]; u32 flags; };
struct JA { s32 state; JP* p; u8 pad[32]; JO* o; };
s32 func_00190140(void*) asm("func_00190140");
f32 func_00191c20(void) asm("func_00191c20");
f32 func_00191c40(void) asm("func_00191c40");
f32 func_001906f0(void*, JV*) asm("func_001906f0");
void func_0019cc20(JA*) asm("func_0019cc20");
void func_0019cd40(JA* a) asm("func_0019cd40");
void func_0019cd40(JA* a)
{
    JV t[3];
    t[0].w = 0;
    switch (a->state) {
    case 0:
        return;
    case 1:
        if (!func_00190140(&a->p)) break;
        return;
    case 2:
        if (func_00190140(&a->p)) {
            if (a->p->flags & 0x400) {
                if (!(func_00191c20() < 1.0f)) return;
            }
            JV v;
            a->o->vt[39](&v, a->o);
            f32 d = func_001906f0(&a->p, &v);
            if (!(func_00191c40() < d)) return;
        }
        break;
    default:
        return;
    }
    func_0019cc20(a);
}
}  // namespace n0019cd40

// ---- 0019ce48 from src/anon/batch_w1720.cpp
namespace n0019ce48 {
struct W1720Rec { s32 w[5]; };
struct W1720Flags { u8 pad0[8]; u64 flags; };
struct W1720Owner { u8 pad0[0xb38]; W1720Flags* xb38; };
struct W1720Ent { u8 pad0[8]; u64 flags; u8 pad10[0x10]; u8 x20[4]; };
struct W1720Obj {
    s32 state;
    W1720Rec rec;
    s32 x18;
    f32 timer;
    u8 pad20[8];
    W1720Owner* owner;
};
extern f32 D_00349e10 asm("D_00349e10");
void func_00190128(W1720Rec*) asm("func_00190128");
s32 func_00190140(W1720Rec*) asm("func_00190140");
void func_00190920(W1720Rec*, s32, W1720Owner*) asm("func_00190920");
W1720Rec func_00190d10(f32, W1720Rec*, W1720Owner*) asm("func_00190d10");
W1720Rec func_001913d8(W1720Rec*, W1720Owner*, void*) asm("func_001913d8");
W1720Ent* func_00167bf0(s32) asm("func_00167bf0");
s32 func_0019bb58(s32) asm("func_0019bb58");
s32 func_0019bc38(s32) asm("func_0019bc38");
void func_0019ca90(W1720Obj*, s32, W1720Rec*) asm("func_0019ca90");
void func_0019cc20(W1720Obj*) asm("func_0019cc20");
void func_0019cc88(W1720Obj*, W1720Rec*) asm("func_0019cc88");
s32 func_0019d4a8(W1720Obj*) asm("func_0019d4a8");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
void func_002c0688(W1720Owner*, W1720Rec*) asm("func_002c0688");
void func_0015a6c8(W1720Rec*) asm("func_0015a6c8");
void func_0019ce48(W1720Obj* self) asm("func_0019ce48");
void func_0019ce48(W1720Obj* self) {
    W1720Flags* f = self->owner->xb38;
    s32 next = -1;
    W1720Rec rec;
    func_00190128(&rec);
    W1720Ent* ent = func_00167bf0(0);
    s32 state = self->state;
    switch (state) {
    case 0:
        if (f->flags & 0x800) {
            next = 4;
            state = 2;
        } else if (func_0019d4a8(self) == 0) {
            next = 6;
            state = 1;
        }
        break;
    case 1:
        if (f->flags & 0x800) {
            rec = self->rec;
            func_0019ca90(self, 2, &rec);
        } else if (self->timer > 0.0f && func_0019bb58(self->rec.w[0]) != 0) {
            self->timer -= D_00349e10;
        } else {
            func_00190920(&rec, 6, self->owner);
            if (func_00190140(&rec) != 0) {
                func_0019cc88(self, &rec);
            } else {
                func_0019cc20(self);
            }
        }
        break;
    case 2: {
        W1720Rec* cur = &self->rec;
        if (func_0019bc38(cur->w[0]) == 0 || (f->flags & 0x800)) {
            func_002ba2e8(8, 0);
            func_0019cc20(self);
        } else if (func_0019d4a8(self) != 0) {
            if (ent->flags & 0xf0000) {
                rec = func_001913d8(cur, self->owner, ent->x20);
                if (func_00190140(&rec) != 0) {
                    func_0019cc88(self, &rec);
                    func_002c0688(self->owner, &rec);
                }
            }
        } else {
            if (f->flags & (1ull << 36)) {
                rec = func_00190d10(-1.0f, cur, self->owner);
            } else if (f->flags & (1ull << 37)) {
                rec = func_00190d10(1.0f, cur, self->owner);
            } else {
                break;
            }
            if (func_00190140(&rec) != 0) {
                func_0019cc88(self, &rec);
                func_0015a6c8(&rec);
            }
        }
        break;
    }
    }
    if (next != -1) {
        func_00190920(&rec, next, self->owner);
        if (func_00190140(&rec) != 0) {
            if (state == self->state) {
                func_0019cc88(self, &rec);
            } else {
                func_0019ca90(self, state, &rec);
            }
        }
    }
}
}  // namespace n0019ce48

// ---- 0019d188 from src/anon/batch_w64.cpp
namespace n0019d188 {
typedef s32 (*IFn)(void*);
s32 func_001c8ab0(u8*) asm("func_001c8ab0");
extern u32 D_0034f240 asm("D_0034f240");
void func_0019cc20(u8*) asm("func_0019cc20");
void func_0019cd40(u8*) asm("func_0019cd40");
void func_0019ce48(u8*) asm("func_0019ce48");
void func_0019d260(u8*) asm("func_0019d260");
void func_0019d188(u8* p) asm("func_0019d188");
void func_0019d188(u8* p) {
    u8* o;
    if (func_001c8ab0(p) == 1 || (D_0034f240 & 0x4000) || !(o = *(u8**)(p + 40)) ||
        (*(u32*)(*(u8**)(o + 12) + 8) & 0x20000)) {
        func_0019cc20(p);
        return;
    }
    if ((*(IFn*)(*(u8**)o + 64))(o)) {
        func_0019cd40(p);
        func_0019ce48(p);
    }
    func_0019d260(p);
}
}  // namespace n0019d188

// ---- 0019d228 from src/anon/tiny_auto80_queue.cpp
namespace n0019d228 {
u32 func_0013e4b8(...) asm("func_0013e4b8");
void func_0019d228(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0019d228jjjjjjjj");
void func_0019d228(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(24));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0013e4b8)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u32*)((u32)r16 + (s32)(24)) = 0u;
    }
}
}  // namespace n0019d228

// ---- 0019d260 from src/anon/batch_w250.cpp
namespace n0019d260 {
struct Q { u8 pad[0x588]; u32 f588; u8 pad2[0xac8-0x58c]; s32 fac8; s32 facc; };
struct Obj;
struct ObjVt { void* s[7]; void (*f7)(Obj*, void*); };
struct Obj { ObjVt* vt; };
struct P { s32 mode; Q* q; u8 pad[0x10]; Obj* obj; u8 pad2[8]; s32 x24; u8 pad3[4]; u32 x2c; };
Obj* func_0013e610(s32) asm("func_0013e610");
void func_00190388(void*, Q**) asm("func_00190388");
void func_0013e520(Obj*, s32) asm("func_0013e520");
void func_0019d228(P*) asm("func_0019d228");
void func_0019d260(P* p) asm("func_0019d260");
void func_0019d260(P* p) {
  u32 m = p->x2c & 1;
  if (m) {
    func_0019d228(p);
  } else {
    switch (p->mode) {
    case 2:
      if (!p->obj) p->obj = func_0013e610(p->x24 == 0 ? 27 : 23);
      break;
    case 1:
      if (!p->obj) p->obj = func_0013e610(p->x24 == 0 ? 5 : 1);
      break;
    default:
      func_0019d228(p);
      break;
    }
  }
  if (p->obj) {
    u8 buf[16] __attribute__((aligned(16)));
    func_00190388(buf, &p->q);                  
    p->obj->vt->f7(p->obj, buf);
    s32 flag = 0;
    Q* q = p->q;
    if (q->f588 & 2) {
      if (q->fac8 > 0 || q->facc > 0) flag = 1;
    }
    func_0013e520(p->obj, flag);
  }
}
}  // namespace n0019d260

// ---- 0019d358 from src/yasui/libys/lockon.cpp
namespace YS {  // n0019d358
void LOCKON::auto_lock() {
    if (reinterpret_cast<LOCKONLayout*>(this)->mode != 1) {
        return;
    }
    u32 target = *(u32*)((u32)this + (s32)(40));
    u32 obj = *(u32*)((u32)target + (s32)(304));
    reinterpret_cast<LOCKONLayout*>(this)->lock_value = *(f32*)((u32)obj + (s32)(104));
}
}  // namespace YS (0019d358)

// ---- 0019d380 from src/anon/batch_w11.cpp
namespace n0019d380 {
struct G19d { u32 pad0; s32 a; u8 pad8[24]; s32 v; s32 b; };
extern G19d* D_00350444 asm("D_00350444");
s32 func_0019d380(s32 a, s32 b) asm("func_0019d380");
s32 func_0019d380(s32 a, s32 b) {
    G19d* g = D_00350444;
    s32 v = g->v;
    if (v != 0 && g->a == a && g->b == b) return v;
    return 0;
}
}  // namespace n0019d380

// ---- 0019d3b8 from src/anon/tiny_auto80_queue.cpp
namespace n0019d3b8 {
u32 func_00154c10(...) asm("func_00154c10");
u32 func_0019d380(...) asm("func_0019d380");
void func_0019d3b8(u32 a0, u32 a1, u32 a2) asm("_Z13func_0019d3b8jjj");
void func_0019d3b8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    u32 v0 = func_0019d380(a0, a1);
    a0 = v0;
    a1 = s0;
    if (v0 != 0u) {
        func_00154c10(a0, a1);
        return;
    }
}
}  // namespace n0019d3b8

// ---- 0019d3f8 from src/anon/tiny_auto80_queue.cpp
namespace n0019d3f8 {
u32 func_00154b98(...) asm("func_00154b98");
u32 func_0019d380(...) asm("func_0019d380");
void func_0019d3f8(u32 a0, u32 a1, u32 a2) asm("_Z13func_0019d3f8jjj");
void func_0019d3f8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    u32 v0 = func_0019d380(a0, a1);
    a0 = v0;
    a1 = s0;
    if (v0 != 0u) {
        func_00154b98(a0, a1);
        return;
    }
}
}  // namespace n0019d3f8

// ---- 0019d438 from src/anon/batch_w27.cpp
namespace n0019d438 {
s32 func_0019d4a8(void*) asm("func_0019d4a8");
void func_002c0688(u32, void*) asm("func_002c0688");
void func_0015a638(void*, void*) asm("func_0015a638");
void func_0019d438(u8* p) asm("func_0019d438");
void func_0019d438(u8* p) {
    if (func_0019d4a8(p)) {
        func_002c0688(*(u32*)(p + 40), p + 4);
    } else {
        func_0015a638(p + 4, p + 4);
    }
}
}  // namespace n0019d438

// ---- 0019d480 from src/anon/tiny_auto80_queue.cpp
namespace n0019d480 {
u32 func_0015a708(...) asm("func_0015a708");
u32 func_0019d4a8(...) asm("func_0019d4a8");
u32 func_002c0700(...) asm("func_002c0700");
void func_0019d480(void) asm("_Z13func_0019d480v");
void func_0019d480(void) {
    if (func_0019d4a8() != 0u) {
        func_002c0700();
        return;
    }
    func_0015a708();
}
}  // namespace n0019d480

// ---- 0019d4a8 from src/anon/tiny_auto80_queue.cpp
namespace n0019d4a8 {
u32 func_0019ba60(...) asm("func_0019ba60");
u32 func_0019d4a8(...) asm("func_0019d4a8");
u32 func_0019d4a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0019d4a8");
u32 func_0019d4a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r13, r14, r15, r16, r17;
    r16 = r4;
    r17 = 0u;
    r4 = ((u32*)(u32)r4)[10];
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0019ba60)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)(0x2000u << 16);
    if (r2 != 0u) {
        r13 = ((u32*)(u32)r16)[10];
        r14 = ((u32*)(u32)r13)[354];
        r14 = (u32)(r14 & r15);
        r17 = ((u32)0u < (u32)r14);
    }
    r2 = r17;
    return r2;
}
}  // namespace n0019d4a8

// ---- 0019d4f8 from src/anon/batch_w1725.cpp
namespace n0019d4f8 {
void func_0019d518(void* p) asm("func_0019d518");
void func_0019d4f8(u8* p) asm("func_0019d4f8");
void func_0019d4f8(u8* p) {
    *(u32*)(p + 4) = 0;
    *(u32*)(p + 8) = 0;
    func_0019d518(p);
}
}  // namespace n0019d4f8

// ---- 0019d518 from src/anon/batch_w1669.cpp
namespace n0019d518 {
void func_001bc688(void*) asm("_ZN2YS12COMMAND_SLOT5clearEv");
void func_00190128(void*) asm("func_00190128");
void func_0019d518(u8* p) asm("func_0019d518");
void func_0019d518(u8* p) {
    func_001bc688(p + 36);
    func_00190128(p + 12);
}
}  // namespace n0019d518

// ---- 0019d548 from src/anon/tiny_auto80_queue.cpp
namespace n0019d548 {
u32 func_0013e4b8(...) asm("func_0013e4b8");
void func_0019d548(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0019d548jjjjjjjj");
void func_0019d548(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(8));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0013e4b8)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u32*)((u32)r16 + (s32)(4)) = 0u;
        *(u32*)((u32)r16 + (s32)(8)) = 0u;
    }
}
}  // namespace n0019d548

// .rodata table at 0x36d3b8 (read by 0x19d588 through its extern; no code loads it directly)
extern "C" const s32 D_0036d3b8[9] = { 50, 52, 54, 56, 58, 60, 62, 64, 66 };

// ---- 0019d588 from src/anon/batch_w41.cpp
namespace n0019d588 {
struct W41S19 { u32 f0; s32 id; u32 res; };
void func_0019d548(W41S19*) asm("func_0019d548");
u32 func_0013e610(u32) asm("func_0013e610");
extern u32 D_0036d3b8[] asm("D_0036d3b8");
void func_0019d588(W41S19* p, s32 id) asm("func_0019d588");
void func_0019d588(W41S19* p, s32 id) {
    if (id != p->id) func_0019d548(p);
    if (id != 0 && p->res == 0) p->res = func_0013e610(D_0036d3b8[id - 1]);
    p->id = id;
}
}  // namespace n0019d588

// ---- 0019d5f8 from src/anon/batch_w260.cpp
namespace n0019d5f8 {
struct W260B20 { union { int w[5]; u8 c; }; };
struct W260Hdr { u16 h0; u16 h2; u8 b4; u8 b5; u8 b6, b7; W260B20* p8; };
struct W260Ent { u8 pad[12]; W260B20 d; u8 pad2[4]; W260Hdr hdr; };
struct W260Z { u8 pad[12]; int f12; u8 pad2[20]; u8 b36; };
W260Z* w260_u_call4(int) asm("_Z16u_call4_001b8e88jjjj");
int w260_is_same(void*, void*) asm("_ZNK2YS6TARGET7is_sameERKS0_");
void func_0019d548(W260Ent*) asm("func_0019d548");
void func_0019d588(W260Ent*, int) asm("func_0019d588");
void func_0019d5f8(W260Ent* e, W260Hdr* h) asm("func_0019d5f8");
void func_0019d5f8(W260Ent* e, W260Hdr* h)
{
    W260Z* z = w260_u_call4(h->h2);
    if (e->hdr.h2 != h->h2 || !w260_is_same(&e->d, h->p8)) func_0019d548(e);
    if (e->hdr.h2 == h->h2 && e->hdr.b5 != h->b5 && e->hdr.b5 == 8 && (u8)((z->f12 >> 3) & 1)) h->h0 |= 2;
    e->hdr = *h;
    __builtin_memcpy(&e->d, h->p8, 20);
    e->hdr.p8 = &e->d;
    func_0019d588(e, h->b5 == 8 ? 0 : z->b36);
}
}  // namespace n0019d5f8

// ---- 0019d720 from src/anon/batch_w8.cpp
namespace n0019d720 {
void func_0019d548(void*) asm("func_0019d548");
void func_0019d4f8(void*) asm("func_0019d4f8");
void func_0019d720(void* p) asm("func_0019d720");
void func_0019d720(void* p) {
    func_0019d548(p);
    func_0019d4f8(p);
}
}  // namespace n0019d720

// ---- 0019d748 from src/anon/batch_w24.cpp
namespace n0019d748 {
s32 func_00181858(u32*) asm("func_00181858");
s32 func_0019d748(u32* p) asm("func_0019d748");
s32 func_0019d748(u32* p) {
    s32 r = 0;
    if (func_00181858(p)) {
        u32 m = p[8] & 1;
        r = m != 0;
    }
    return r;
}
}  // namespace n0019d748

// ---- 0019d790 from src/anon/batch_w2352_gnsa.cpp
namespace n0019d790 {
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
struct Obj { u8 pad[0x7f8]; u32 flags; };
struct Tgt { Obj* obj; u8 pad[0x10]; s32 f14; u8 pad2[0x8]; };
struct Slot { u8 pad[0xc]; };
struct Buf {
    void* owner;            
    Slot slot;              
    Tgt tgt;                
    u8 pad[0x60 - 0x30];
};
struct Sub0c { u8 pad[8]; u32 f8; };
struct Q {
    u8 pad[0xc];
    Sub0c* f0c;              
    u8 pad1[0x168 - 0x10];
    u32 f168;                 
    u8 pad2[0x508 - 0x16c];
    void* path;               
    u8 pad3[0xb50 - 0x50c];
    s32 fb50;                 
};
struct P { u8 pad[0x9e0]; Q* q; };
typedef void (*VFn)(void*, V);
struct VObj { VFn* vt; };
bool tgt_exist(Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
void tgt_setobj(Tgt*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
bool slot_exist(Slot*) asm("_ZN2YS12COMMAND_SLOT8is_existEv");
V path_pos(void*) asm("_ZN2Ti4Path15get_current_posEv");
s32 func_0019d748(u8*) asm("func_0019d748");
void func_0019da20(Buf*, u8*) asm("func_0019da20");
void func_0019dd10(Buf*) asm("func_0019dd10");
void func_0019d5f8(u8*, Slot*) asm("func_0019d5f8");
void func_0019d720(u8*) asm("func_0019d720");
void func_00196028(Obj*) asm("func_00196028");
void* func_0016b740(s32) asm("func_0016b740");
void func_00190128(Tgt*) asm("func_00190128");
V func_00190388(Tgt*) asm("func_00190388");
static inline bool hasobj(u8* s) { bool r = false; if (tgt_exist((Tgt*)(s + 0xc))) r = ((Tgt*)(s + 0xc))->obj != 0; return r; }
static inline bool is6(Q* q) { return q->fb50 == 6; }
static inline bool low(u8* s) { return *(u8*)(s + 0x29) < 4; }
#define SELF_P(s)   (*(P**)((s) + 0x00))
#define SELF_VO(s)  (*(VObj**)((s) + 0x08))
#define SELF_TGT(s) ((Tgt*)((s) + 0x0c))
#define SELF_ID(s)  (*(u16*)((s) + 0x26))
#define SELF_ST(s)  (*(u8*)((s) + 0x29))
void func_0019d790(u8* self) asm("func_0019d790");
void func_0019d790(u8* self)
{
    Buf b;
    if (!func_0019d748(self)) return;
    func_0019da20(&b, self);
    func_0019dd10(&b);
    if (slot_exist(&b.slot)) {
        bool has;
        Q* q;
        func_0019d5f8(self, &b.slot);
        has = hasobj(self);
        if (has) SELF_TGT(self)->obj->flags |= 0x2000;
        q = SELF_P(self)->q;
        if (is6(q) || (q->f0c->f8 & 0x8000) || (q->f168 & 0x80)) SELF_ST(self) = 5;
    } else {
        func_0019d720(self);
    }
    if (low(self) && SELF_ID(self) == 55) func_00196028(SELF_TGT(self)->obj);
    if (b.tgt.f14 > 0 && (b.tgt.f14 & 0x40000000)) SELF_ST(self) = 5;
    if (SELF_VO(self)) {
        V pos;
        switch (SELF_ID(self)) {
        case 440:
        case 464: {
            void* o = func_0016b740(1762);
            if (o) {
                Tgt t;
                func_00190128(&t);
                tgt_setobj(&t, o, 0);
                pos = func_00190388(&t);
            } else {
                pos = func_00190388(SELF_TGT(self));
            }
            break;
        }
        case 523:
            pos = path_pos(SELF_P(self)->q->path);
            break;
        default:
            pos = func_00190388(SELF_TGT(self));
            break;
        }
        SELF_VO(self)->vt[7](SELF_VO(self), pos);
    }
}
}  // namespace n0019d790

// ---- 0019d9d8 gap function (unwritten C2 copy of the ctor at 0x19da20)
namespace n0019d9d8 {
void func_001bc688(void*) asm("func_001bc688");
void func_00190128(void*) asm("func_00190128");
void func_0019d9d8(u8* o, u32 a) asm("func_0019d9d8");
void func_0019d9d8(u8* o, u32 a) {
    *(u32*)o = a;
    *(u16*)(o + 4) = 0;
    func_001bc688(o + 4);
    func_00190128(o + 16);
    *(u32*)(o + 60) = 0;
    *(s32*)(o + 36) = -1;
    *(u32*)(o + 80) = 0;
}
}  // namespace n0019d9d8

// ---- 0019da20 from src/anon/batch_w25.cpp
namespace n0019da20 {
void func_001bc688(void*) asm("func_001bc688");
void func_00190128(void*) asm("func_00190128");
void func_0019da20(u8* o, u32 a) asm("func_0019da20");
void func_0019da20(u8* o, u32 a) {
    *(u32*)o = a;
    *(u16*)(o + 4) = 0;
    func_001bc688(o + 4);
    func_00190128(o + 16);
    *(u32*)(o + 60) = 0;
    *(s32*)(o + 36) = -1;
    *(u32*)(o + 80) = 0;
}
}  // namespace n0019da20

// ---- 0019da68 from src/anon/batch_w1883.cpp
namespace n0019da68 {
struct QV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct S20 { s32 v[5]; };
static inline __attribute__((always_inline)) QV vsub_w1883(const QV& p, const QV* q) {
    QV d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(&p), "r"(q) : "memory");
    return d;
}
void func_001bc6a8(u8*, u8*, u8*, u8*, s32) asm("func_001bc6a8");
QV func_00190388(u8*) asm("func_00190388");
QV* func_0016c028(u8*) asm("func_0016c028");
void func_0019da68(u8* a0, u8* a1, u8* a2, s32 a3, s32 a4) asm("func_0019da68");
void func_0019da68(u8* a0, u8* a1, u8* a2, s32 a3, s32 a4) {
    u8* o = (u8*)*(s32*)(*(s32*)*(s32*)a0 + 0x9e0);
    *(S20*)(a0 + 0x10) = *(S20*)a2;
    func_001bc6a8(a0 + 4, a1, o, a0 + 0x10, 1);
    *(s32*)(a0 + 0x24) = a4;
    *(s32*)(a0 + 0x50) = a3;
    if (a3 != 0xc9 && (*(s32*)(o + 0x588) & 0x80)) {
        *(s32*)(o + 0xb48) = 0;
    }
    if (*(u16*)(a1 + 0x28) != 0 && *(s32*)(a0 + 0x24) <= 0x3fffffff) {
        QV d = vsub_w1883(func_00190388(a2), func_0016c028(o));
        f32 len;
        d.y = 0;
                                                                      
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        if ((f32)*(u16*)(a1 + 0x28) < len) {
            *(s32*)(a0 + 0x24) |= 0x40000000;
        }
    }
}
}  // namespace n0019da68

// ---- 0019dbc0 from src/anon/batch_w269.cpp
namespace n0019dbc0 {
#define QCOPYL269(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct LV269 {
    f32 x, y, z, w;
    LV269() {}
    LV269(const LV269& o) { QCOPYL269(this, &o); }
    LV269& operator=(const LV269& o) { if (this != &o) QCOPYL269(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline LV269 operator*(const LV269& a, f32 k) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline LV269 operator+(const LV269& a, const LV269& b) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct NM269 {
    f32 m[16];
    NM269() {}
    NM269& operator=(const NM269& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
u16* func_001b8e88(s32) asm("func_001b8e88");
s32 func_001b90f0(u16*, s32) asm("func_001b90f0");
s32 func_001c11e0(void) asm("func_001c11e0");
s32 func_00190140(u32*) asm("func_00190140");
s32 func_0019c4f8(u32) asm("func_0019c4f8");
void func_0019da68(u8*, u16*, u32*, s32, s32) asm("func_0019da68");
s32 func_0019dbc0(u8* a0, s32 a1, u32* a2, s32 a3, s32 a4) asm("func_0019dbc0");
s32 func_0019dbc0(u8* a0, s32 a1, u32* a2, s32 a3, s32 a4) {
    if (a3 >= *(s32*)(a0 + 0x50)) {
        if (a3 != *(s32*)(a0 + 0x50)) goto body;
        if (a4 < *(s32*)(a0 + 0x24)) goto body;
    }
    return 0;
body:
    u16* v = func_001b8e88(a1);
    if (a3 != 201) {
        s32 k = *(s32*)(**(u8***)a0 + 2528);
        if (!func_001b90f0(v, k)) return 0;
        if (*v == 30 || *v == 604) {
            if (func_001c11e0()) return 0;
        }
        if (*v != 456) {
            u32 ok = 0;
            if (func_00190140(a2)) ok = *a2 != 0;
            if ((u8)ok) {
                if (func_0019c4f8(*a2)) return 0;
            }
        }
    }
    func_0019da68(a0, v, a2, a3, a4);
    return 1;
}
}  // namespace n0019dbc0

// ---- 0019dd10 from src/anon/batch_w1984_nsa.cpp
namespace n0019dd10 {
struct TgtD { u8 pad[32]; };
extern s32 D_0034f240 asm("D_0034f240");
void func_00190128(void*) asm("func_00190128");
void dd_set_obj(TgtD*, u32, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 func_0019c4f8(u8*) asm("func_0019c4f8");
s32 func_0019dbc0(u8* a0, s32 a1, void* a2, s32 a3, s32 a4) asm("func_0019dbc0");
u8* dd_get_override(void*, s32) asm("_ZN2YS14PLAYER_COMMAND12get_overrideEi");
s32 dd_is_exec(void) asm("_ZN2YS5LIMIT6IsExecEv");
u8* func_0016bc20(void* a, s32 b, s32 id) asm("func_0016bc20");
void func_0018a818(u8*, u8*, u8*) asm("func_0018a818");
void func_0019e170(u8*) asm("func_0019e170");
void func_0019e400(u8*) asm("func_0019e400");
s32 dd_is_exist(u8*) asm("_ZN2YS12COMMAND_SLOT8is_existEv");
s32 dd_is_pinch(u32) asm("_ZNK2YS5SHEET8is_pinchEv");
s32 func_0019e758(u8*, u8*) asm("func_0019e758");
s32 func_0019e6e8(u8*, u8*) asm("func_0019e6e8");
void func_0019ead0(u8*, u8*) asm("func_0019ead0");
struct Sub140 { u8 pad[32]; u32 flags; u8 pad2[216]; u32 obj; };
void func_0019dd10(u8* self) asm("func_0019dd10");
void func_0019dd10(u8* self)
{
    TgtD tgt;
    u8* ob = *(u8**)(**(u8***)self + 0x9e0);
    func_00190128(&tgt);
    if (func_0019c4f8(ob)) return;
    if (D_0034f240 & 0x4000) return;
    if (*(u32*)(ob + 0x588) & 0x80) {
        s32 a1 = *(s32*)(ob + 0xb48);
        if (a1 && func_0019dbc0(self, a1, ob + 0x9f4, 201, 0)) self[9] = 8;
    }
    {
        u8* v = dd_get_override(**(void***)self, 1);
        if (v) func_0019dbc0(self, *(u16*)(v + 2), v + 12, 203, 0);
    }
    Sub140* sub = (Sub140*)(ob + 0x140);
    if (*(u32*)(ob + 0x160) & 0x100000) {
        dd_set_obj(&tgt, sub->obj, 0);
        if (func_0019dbc0(self, *(s32*)(ob + 0x50c), &tgt, 204, 0)) self[9] = 7;
    }
    if (dd_is_exec()) return;
    if (*(u32*)(ob + 0x588) & 0x2000000) return;
    {
        u8* t = func_0016bc20(ob, 1, -1);
        if (t) {
            func_0018a818(self + 48, ob, t);
            func_0019e170(self);
            func_0019e400(self);
        }
    }
    {
        s32 f = *(s32*)(self + 36);
        if (f >= 0 && (f & 0x40000000)) self[9] = 5;
    }
    if (dd_is_exist(self + 4)) return;
    if (!(*(u32*)(ob + 0x588) & 0x80)) return;
    if (*(u32*)(ob + 0x160) & 0x4000) return;
    if (!dd_is_pinch(*(u32*)(*(u8**)(ob + 0xb44) + 0x9e8))) return;
    if (func_0019e758(self, ob)) return;
    if (func_0019e6e8(self, ob)) return;
    func_0019ead0(self, ob);
}
}  // namespace n0019dd10

// ---- 0019df08 from src/anon/batch_w1721_nsa.cpp
namespace n0019df08 {
struct W1721V4 {
    f32 x, y, z, w;
    W1721V4() {}
    W1721V4& operator=(const W1721V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1721V4 operator-(const W1721V4& o) const {
        W1721V4 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    f32 dot(const W1721V4& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1721Target;
struct W1721Obj { u8 pad0[0x588]; s32 flags; u8 pad58c[0xb40 - 0x58c]; u8* b40; };
struct W1721Owner { u8 pad0[0x9e0]; W1721Obj* obj; };
struct W1721Head { W1721Owner* owner; };
struct W1721Self { W1721Head* head; u8 pad4[0x3c]; W1721V4 pos; };
struct W1721Param { u8 pad0[0xc]; s32 flags; f32 angle; f32 cone; f32 range; };
static inline bool W1721_lt(f32 a, f32 b) { return a < b; }
s32 func_00190680(W1721Target*, void*) asm("_ZNK2YS6TARGET7is_sameERKS0_");
W1721V4 func_00190388(W1721Target*) asm("func_00190388");
void func_0016af58(W1721V4*, W1721Obj*) asm("func_0016af58");
W1721V4 func_0017d538(f32, s32) asm("func_0017d538");
s32 func_0019c090(W1721Obj*) asm("func_0019c090");
s32 func_0019df08(W1721Self* self, W1721Param* prm, W1721Target* tgt, s32 a3, s32 dmg) asm("func_0019df08");
s32 func_0019df08(W1721Self* self, W1721Param* prm, W1721Target* tgt, s32 a3, s32 dmg)
{
    W1721Obj* o = self->head->owner->obj;
    if ((o->flags & 0x80) && func_00190680(tgt, o->b40 + 4)) {
        dmg = (s32)(dmg * 0.5f);
    } else if (func_00190680(tgt, (u8*)self->head + 12)) {
        dmg = (s32)(dmg * 0.8f);
    }
    if (dmg > 0x3fffffff) dmg = 0x3fffffff;
    W1721V4 d;
    W1721V4 t2;
    d = func_00190388(tgt) - self->pos;
    d.normalize();
    if (-1.0f < prm->angle) {
        W1721V4 t;
        func_0016af58(&t, o);
        if (W1721_lt(d.dot(t), prm->angle)) dmg |= 0x40000000;
    }
    if (-1.0f < prm->range) {
        t2 = func_0017d538(prm->cone + 3.1415927f, a3);
        if (d.dot(t2) < prm->range) dmg |= 0x40000000;
    }
    if ((prm->flags >> 1) & 1) {
        if (func_0019c090(o)) dmg |= 0x40000000;
    }
    return dmg;
}
}  // namespace n0019df08

// ---- 0019e170 from src/anon/batch_wcx.cpp
namespace n0019e170 {
u8* func_001b9bc8(u8*) asm("func_001b9bc8");
void func_0019e210(u8**, u32) asm("func_0019e210");
void func_0019e170(u8** p) asm("func_0019e170");
void func_0019e170(u8** p)
{
    u8* o = *(u8**)(**(u8***)p + 2528);
    if (*(u32*)(o + 1416) & 0x20000000) {
        u32* s = *(u32**)(o + 2880);
        if (s[0] == 2) { func_0019e210(p, s[1]); return; }
    }
    u8* n = 0;
    while ((n = func_001b9bc8(n))) func_0019e210(p, (u32)n);
}
}  // namespace n0019e170

// ---- 0019e210 from src/anon/batch_w2397.cpp
namespace n0019e210 {
struct W2397V {
    f32 x, y, z, w;
    W2397V() {}
    W2397V& operator=(const W2397V& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
    W2397V operator-(const W2397V& b) const {
        W2397V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize() {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 dot(const W2397V& b) const {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
                 : "=f"(r) : "r"(this), "r"(&b) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W2397Col { W2397V a; W2397V b; };
struct W2397Elem { u8 b0; u8 b1; u16 id; u8 kind; };
struct W2397Sub { u8 pad[0x2c]; u16 id; };
struct W2397Obj { u8 pad[0x81c]; W2397Sub* sub; u8 pad2[0xaa4 - 0x820]; u32 id; };
struct W2397Coll { u8 pad[0x30]; W2397Col col; };
struct W2397Tgt { u8 d[32]; };
struct W2397X { u8 d[16]; };
s32 func_0019c4f8(W2397Obj*) asm("func_0019c4f8");
W2397Elem* W2397Obj_select(W2397Obj*, u32, W2397Elem*) asm("_ZN2YS3OBJ16select_collisionEjPKNS_14COLLISION_ELEME");
s32 func_0019bdc8(W2397Obj*, u32, u32) asm("func_0019bdc8");
u16* func_0019e5f8(W2397Coll*, u32) asm("func_0019e5f8");
void func_0018a818(W2397Col*, W2397Obj*, W2397Elem*) asm("func_0018a818");
s32 func_0018a550(W2397Col*, W2397Col*) asm("func_0018a550");
void func_00190128(W2397Tgt*) asm("func_00190128");
void W2397Tgt_set_obj(W2397Tgt*, W2397Obj*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 W2397Coll_draw(W2397Coll*, u16*) asm("_ZN2YS9COLLISION4drawEji");
void func_0016af58(W2397X*, W2397Obj*) asm("func_0016af58");
s32 func_0019df08(W2397Coll*, u16*, W2397Tgt*, W2397X*, s32) asm("func_0019df08");
void func_0019dbc0(W2397Coll*, u32, W2397Tgt*, s32, s32) asm("func_0019dbc0");
void func_0019e210(W2397Coll* self, W2397Obj* obj) asm("func_0019e210");
void func_0019e210(W2397Coll* self, W2397Obj* obj) {
    if (func_0019c4f8(obj)) return;
    W2397Elem* el = 0; W2397V* cb = &self->col.b; u32 k5 = 5; u32 k131 = 131;
    for (;;) {
        el = W2397Obj_select(obj, 0x4020, el);
        if (!el) break;
        u32 id;
        if (el->kind == k5) {
            id = el->id;
            if (id == k131 && obj->sub) id = obj->sub->id;
        } else {
            id = obj->id;
        }
        if (!func_0019bdc8(obj, id, el->b0)) continue;
        u16* e = func_0019e5f8(self, id);
        if (!e) continue;
        W2397Col c;
        func_0018a818(&c, obj, el);
        if (!func_0018a550(&c, &self->col)) continue;
        W2397V d = c.b - *cb;
        d.y = 0;
        s32 dist = (s32)d.normalize();
        u8 k = el->b0;
        W2397Tgt tgt;
        func_00190128(&tgt);
        W2397Tgt_set_obj(&tgt, obj, k);
        s32 r = W2397Coll_draw(self, e);
        W2397X x;
        func_0016af58(&x, obj);
        func_0019dbc0(self, *e, &tgt, r, func_0019df08(self, e, &tgt, &x, dist));
    }
}
}  // namespace n0019e210

// ---- 0019e400 from src/anon/batch_w2398_nsa.cpp
namespace n0019e400 {
struct E4V {
    f32 x, y, z, w;
    E4V() {}
    E4V& operator=(const E4V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    E4V operator+(const E4V& o) const {
        E4V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    E4V operator-(const E4V& o) const {
        E4V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct E4Hit { s32 a; f32 b; s32 x8; s32 c; E4V v; E4Hit() { c = 0; } };
struct E4Tgt { u8 pad[32]; };
struct E4Obj;
struct E4Ent;
typedef E4V (*E4VFn)(E4Ent*, E4Obj*);
struct E4Ent {
    E4VFn* vt; u8 pad4[0xe0 - 4]; E4V pa; u8 padf0[0x114 - 0xf0];
    u32 f114; u32 f118; f32 f11c; f32 f120; u8 pad124[0x130 - 0x124]; E4V pb;
};
struct E4Owner { u8 pad0[0x9e0]; E4Obj* obj; };
struct E4Head { E4Owner* owner; };
struct E4Self { E4Head* head; u8 pad4[0x2c]; E4Hit hit; };
struct E4Prm { u16 id; };
void func_00190128(E4Tgt*) asm("func_00190128");
E4Ent* func_0018ee28(E4Ent*) asm("func_0018ee28");
E4Prm* func_0019e5f8(E4Self*, u32) asm("func_0019e5f8");
void e4_make(E4Hit*, s32, f32, f32) asm("_ZN2YS9COLLISION4makeEiff");
s32 func_0018a550(E4Hit*, E4Hit*) asm("func_0018a550");
void func_001908c0(E4Tgt*, E4Ent*, u32) asm("func_001908c0");
E4V func_00190388(E4Tgt*) asm("func_00190388");
s32 e4_draw(E4Self*, E4Prm*) asm("_ZN2YS9COLLISION4drawEji");
s32 func_0019df08(E4Self*, E4Prm*, E4Tgt*, const E4V&, s32) asm("func_0019df08");
s32 func_0019dbc0(E4Self*, s32, E4Tgt*, s32, s32) asm("func_0019dbc0");
void func_0019e400(E4Self* self) asm("func_0019e400");
void func_0019e400(E4Self* self)
{
    E4Hit hit;
    E4V d;
    E4V d2;
    E4Tgt tgt;
    E4Ent* e;
    E4Obj* o;
    func_00190128(&tgt);
    e = 0;
    o = self->head->owner->obj;
    while ((e = func_0018ee28(e)) != 0) {
        E4Prm* p; s32 len; s32 v;
        if (!e->f118) continue;
        p = func_0019e5f8(self, e->f118);
        if (!p) continue;
        e4_make(&hit, 0, e->f11c, e->f120);
        hit.v = e->pa + e->pb;
        if (!func_0018a550(&hit, &self->hit)) continue;
        func_001908c0(&tgt, e, e->f114);
        d = func_00190388(&tgt) - self->hit.v;
        d.y = 0.0f;
        len = (s32)d.normalize();
        v = e4_draw(self, p);
        func_0019dbc0(self, p->id, &tgt, v, func_0019df08(self, p, &tgt, e->vt[3](e, o), len));
    }
}
}  // namespace n0019e400

// ---- 0019e5f8 from src/anon/batch_w2369.cpp
namespace n0019e5f8 {
struct FindEnt { u8 pad[12]; s32 flags; u8 pad2[34 - 16]; u16 id; };
struct FindPl { u8 pad[0x160]; u32 st; u8 pad2[0x50c - 0x164]; u32 id; };
struct FindWk { u8 pad[0x9e0]; FindPl* pl; };
struct FindCtx { FindWk** w; };
FindEnt* func_001b8e88(s32) asm("func_001b8e88");
s32 func_001917c0(void) asm("func_001917c0");
FindEnt* func_0019e5f8(FindCtx* c, s32 id) asm("func_0019e5f8");
FindEnt* func_0019e5f8(FindCtx* c, s32 id) {
    FindPl* pl = (*c->w)->pl;
    if (id == 0) return 0;
    FindEnt* e = func_001b8e88(id);
    if (func_001917c0() != 0) {
        u8 b = (e->flags >> 4) & 1;
        if (!b) return 0;
    }
    u8 b6 = (e->flags >> 6) & 1;
    if (b6) {
        if (!(pl->st & 0x200000) || pl->id != e->id) return 0;
    }
    return e;
}
}  // namespace n0019e5f8

// ---- 0019e698 from src/anon/tiny_auto80_queue.cpp
namespace n0019e698 {
u32 func_0019e698(u32 a0, u32 a1) asm("_Z13func_0019e698jj");
u32 func_0019e698(u32 a0, u32 a1) {
    u32 v0 = (u32)(*(u8*)((u32)a1 + (s32)(30)));
    if ((s32)v0 < 202) {
        a1 = (u32)(*(u16*)((u32)a1 + (s32)(34)));
        if (a1 != 0u) {
            u32 t7 = *(u32*)((u32)a0 + (s32)(0));
            u32 t6 = *(u32*)((u32)t7 + (s32)(0));
            a0 = *(u32*)((u32)t6 + (s32)(2528));
            t7 = *(u32*)((u32)a0 + (s32)(352));
            t6 = (u32)(0x0020u << 16);
            t7 = (u32)(t7 & t6);
            if (t7 != 0u) {
                t6 = 202u;
                t7 = *(u32*)((u32)a0 + (s32)(1292));
                t7 = (u32)(t7 ^ a1);
                if (t7 == 0u) {
                    v0 = t6;
                }
            }
    }
        }
    return v0;
}
}  // namespace n0019e698

// .rodata id tables at 0x36d3f0 / 0x36d400 (passed by 0x19e6e8 / 0x19e758 to 0x19e848)
extern "C" const u16 D_0036d3f0[5] = { 0x184, 0x183, 0x238, 0x182, 0x181 };
extern "C" const u16 D_0036d400[4] = { 0x19, 0x9f, 0xa0, 0x17f };

// ---- 0019e6e8 from src/anon/batch_w37.cpp
namespace n0019e6e8 {
s32 func_001a2478(void*) asm("func_001a2478");
u8 func_0019e848(void*, void*, void*, u32) asm("func_0019e848");
extern u8 D_0036d3f0[] asm("D_0036d3f0");
u8 func_0019e6e8(void* a, u8* b) asm("func_0019e6e8");
u8 func_0019e6e8(void* a, u8* b) {
    void* t = *(void**)(b + 1164);
    if (!t || !func_001a2478(t)) return 0;
    return func_0019e848(a, b, D_0036d3f0, 5);
}
}  // namespace n0019e6e8

// ---- 0019e758 from src/anon/batch_wcx2.cpp
namespace n0019e758 {
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
struct V2e2350 {
    f32 x, y, z, w;
    V2e2350() {}
    V2e2350(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
                                        
    V2e2350& operator=(const V2e2350& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
u8* func_00177860_19e758(u8*) asm("func_00177860");
u8* func_0017df58_19e758(s32) asm("func_0017df58");
s32 func_0019ba60_19e758(u8*) asm("func_0019ba60");
u8 func_0019e848_19e758(u8*, u8*, u8*, s32) asm("func_0019e848");
extern u8 D_0036d400[] asm("D_0036d400");
s32 func_0019e758(u8* o, u8* t) asm("func_0019e758");
s32 func_0019e758(u8* o, u8* t)
{
    if (*(u32*)(t + 1164) != 0 && (*(u32*)(func_00177860_19e758(t) + 4) & 0x1000000)) {
        s32* p = *(s32**)(*(u8**)(t + 2884) + 2536);
        if (p == 0 || *p != 6) return 0;
        s32 found = 0;
        for (s32 i = 0; i < 2; i++) {
            u8* m = func_0017df58_19e758(i);
            if (func_0019ba60_19e758(m) && (*(u32*)(m + 2040) & 4)) {
                found = 1;
                break;
            }
        }
        if (!found) return 0;
        return func_0019e848_19e758(o, t, D_0036d400, 4);
    }
    return 0;
}
}  // namespace n0019e758


// ---- 0019e848 (was whole asm in src/anon/batch_w3885.s)
namespace n0019e848 {
struct Rec { s32 w[8]; };
struct Ent { u8 pad[0x10]; u16 x10; };
struct Info { u8 pad[0x26]; u16 x26; };
void func_00190128(Rec*) asm("func_00190128");
void func_00190878(Rec*, s32, s32) asm("func_00190878");
Ent* func_001a80c8(u16) asm("func_001a80c8");
u16* func_001b8e88(u16) asm("func_001b8e88");
s32 func_0019ea10(s32, Ent*, u16*) asm("func_0019ea10");
extern u32 D_003638d0 asm("D_003638d0");
struct Obj {
    Info* in;
    void Set(u16*, Rec*, s32, s32) asm("func_0019da68");
    s32 Pick(s32 key, u16* ids, s32 cnt) asm("func_0019e848");
};
// `this` is a const pointer: its spill slot is an unchanging MEM, so every register save has an output
// dependence on the spill store (sw a0,32(s8)) and sched2 puts it after them and after the VLA sp save.
s32 Obj::Pick(s32 key, u16* ids, s32 cnt) {
    Rec rec;
    s32 i = 0;
    s32 n = 0;
    func_00190128(&rec);
    func_00190878(&rec, key, 0);
    u16* list[cnt];
    for (; i < cnt; i++) {
        Ent* e = func_001a80c8(ids[i]);
        u16* q = func_001b8e88(e->x10);
        if (func_0019ea10(key, e, q)) {
            if (in->x26 == *q) {
                Set(q, &rec, 0, 0);
                return 1;
            }
            list[n++] = q;
        }
    }
    if (n > 0) {
        D_003638d0 *= 0x10dcd;
        u32 m = n;
        s32 idx = (u64)D_003638d0 / ((0x100000000ull + (m - 1)) / m);
        Set(list[idx], &rec, 0, 0);
        return 1;
    }
    return 0;
}
}  // namespace n0019e848
