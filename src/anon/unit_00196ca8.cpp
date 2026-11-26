// Linked unit 0x196bf0-0x197fe0: a record init (gap 0x196bf0), YS::EVENT and its helpers, up to the file's static initialiser
// (0x197ea8, three event tasks at 0x1c61b10, written as a plain function like its I stub 0x197f60),
// then the YS::STDOBJ C2 ctor copy 0x197f80 (its C1 0x197fe0 is unit_00197fe0.cpp).
// Gap functions written: 0x196bf0, 0x197af8, 0x197cf0, 0x197d40, 0x197ea8, 0x197f80. .rodata 0x36d078-0x36d0ac.
// Flags: -G0 -fno-strict-aliasing.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/menu_sound.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 00196bf0 gap: record init (area id triples reset to 0xffff at +16/+20), same placement-new
// triple ctors as the EVENT88 constructors (unit_00198e40.cpp).
namespace n00196bf0 {
inline void* operator new(unsigned int, void* p) { return p; }
struct C3 { u8 a, b, c; C3(u32 x, u32 y, u32 z) { a = x; b = y; c = z; } };
struct S3 { u16 a; s16 b; s16 c; S3(u32 x, s32 y, s32 z) { a = x; b = y; c = z; } };
struct REC {
    u32 f0; u32 f4; u32 f8; u8 f12[4]; u8 f16[3]; u8 pad19; u16 f20[3]; u8 pad26[18]; u32 f44;
    u8 pad48[12]; s32 f60; s32 f64; u8 pad68[12]; u8 f80[68]; s32 f148; s32 f152; s32 f156; s32 f160;
};
void func_0019ef70(u8*) asm("func_0019ef70");
s32 func_001d30c0(u32) asm("func_001d30c0");
void func_0011b6a8(u8*) asm("func_0011b6a8");
void func_00138480(s32) asm("func_00138480");
void func_00196bf0(REC* o, u32 flags, u32 v) asm("func_00196bf0");
void func_00196bf0(REC* o, u32 flags, u32 v) {
    s32 m = 0xffff;
    o->f4 = v;
    o->f0 = 0;
    o->f8 = 0;
    new (o->f16) C3(m, m, m);
    new (o->f20) S3(m, m, m);
    o->f44 = 0;
    func_0019ef70(o->f12);
    o->f60 = func_001d30c0(flags & 0x3f);
    o->f64 = 1;
    func_0011b6a8(o->f80);
    o->f148 = 0;
    o->f152 = 0;
    o->f156 = -1;
    o->f160 = -1;
    if (flags & 0x80) func_00138480(1);
}
}  // namespace n00196bf0

// ---- 00196ca8 from src/anon/batch_wcx2.cpp
namespace n00196ca8 {
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
void YS__EVENT__EVENT(u8*, s32, u32) asm("YS__EVENT__EVENT");
void func_0031cc28(u8*) asm("func_0031cc28");
#define QCOPY_11bfa0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V11bfa0 {
    f32 x, y, z, w;
    void Set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V11bfa0& operator=(const V11bfa0& o) { if (this != &o) QCOPY_11bfa0(this, &o); return *this; }
} __attribute__((aligned(16)));
struct A196ca8 { u8 a, b, c; };
struct X196ca8 { u16 d, e, f; };
struct O196ca8 {
    u32 f0; union { u32 u; u16 h; u8 b; } f4; u32 f8; u8 m0c[4]; A196ca8 bytes; u8 pad13; X196ca8 shorts; u8 pad1a[0x12];
    u8 m2c[0x10]; u32 f3c, f40; u8 pad44[0xc]; u8 m50[0x44]; u32 f94, f98, f9c, fa0;
};
void func_0019ef70(u8*) asm("func_0019ef70");
u32 func_001d30c0(u32) asm("func_001d30c0");
void func_0011b6a8_196ca8(u8*) asm("func_0011b6a8");
void func_00138480(u32) asm("func_00138480");
static inline void Init196ca8(X196ca8* x, s32 v)
{
    A196ca8* p = (A196ca8*)((u8*)x - 4);
    p->a = v; p->b = v; p->c = v; x->d = v; x->e = v; x->f = v;
}
void YS__EVENT__EVENT(u8* p, s32 flags, u32 v) asm("YS__EVENT__EVENT");
void YS__EVENT__EVENT(u8* p, s32 flags, u32 v)
{
    O196ca8* o = (O196ca8*)p;
    o->f4.u = v;
    o->f0 = 0;
    o->f8 = 0;
    Init196ca8(&o->shorts, 0xffff);
    u8* m = o->m0c;
    func_0031cc28(o->m2c);
    func_0019ef70(m);
    o->f3c = func_001d30c0(flags & 0x3f);
    o->f40 = 1;
    func_0011b6a8_196ca8(o->m50);
    o->f98 = 0;
    o->f9c = -1;
    o->fa0 = -1;
    o->f94 = 0;
    if (flags & 0x80) func_00138480(1);
}
}  // namespace n00196ca8

// ---- 00196d78 from src/anon/batch_w55.cpp
namespace n00196d78 {
void func_00226da8(u8*) asm("func_00226da8");
void func_0014c9f0(s32) asm("func_0014c9f0");
void func_001c11a8(s32) asm("func_001c11a8");
void func_001384a0(s32) asm("func_001384a0");
void func_002bc798(void) asm("func_002bc798");
void func_002ba610(void) asm("func_002ba610");
extern u32 D_0035037c asm("D_0035037c");
void func_00196d78(u8* p) asm("func_00196d78");
void func_00196d78(u8* p) {
    func_00226da8(p);
    func_0014c9f0(4);
    func_001c11a8(12);
    func_001384a0(1);
    if ((u8)((*(u16*)(*(u8**)(p + 60) + 2) >> 5) & 1) == 0) func_002bc798();
    u32 v = *(u16*)(*(u8**)(p + 60) + 2);
    if ((u8)(v & 1)) func_002ba610();                         
    D_0035037c = 0;
}
}  // namespace n00196d78

// ---- 00196e00 from src/anon/batch_w56.cpp
namespace n00196e00 {
struct Fl196 { u16 h0; u16 b0 : 1; u16 b1 : 4; u16 b5 : 1; };
inline u8 fl196_b5(Fl196* f) { return f->b5; }
inline u8 fl196_b0(Fl196* f) { return f->b0; }
struct O196 { u8 pad[60]; Fl196* fl; };
void func_00226da8(O196*) asm("func_00226da8");
void func_0014c9f0(s32) asm("func_0014c9f0");
void func_001c11a8(s32) asm("func_001c11a8");
void func_001384a0(s32) asm("func_001384a0");
void func_002bc798(void) asm("func_002bc798");
void func_002ba610(void) asm("func_002ba610");
extern u32 D_0035037c asm("D_0035037c");
void func_00196e00(O196* a) asm("func_00196e00");
void func_00196e00(O196* a)
{
    func_00226da8(a);
    func_0014c9f0(4);
    func_001c11a8(12);
    func_001384a0(1);
    if (!fl196_b5(a->fl)) func_002bc798();
    if (fl196_b0(a->fl)) func_002ba610();                         
    D_0035037c = 0;
}
}  // namespace n00196e00

// ---- 00196e88 from src/anon/tiny_auto80_queue.cpp
namespace n00196e88 {
void func_00196e88(u32, u32, u32, f32) asm("_Z13func_00196e88jjjf");
void func_00196e88(u32 a0, u32 a1, u32 a2, f32 a3) asm("_Z13func_00196e88jjjf");
void func_00196e88(u32 a0, u32 a1, u32 a2, f32 a3) {
    *(u32*)((u32)a0 + (s32)(48)) = a1;
    *(u32*)((u32)a0 + (s32)(52)) = a2;
    *(f32*)((u32)a0 + (s32)(56)) = a3;
}
}  // namespace n00196e88

// ---- 00196e98 from src/anon/batch_w39.cpp
namespace n00196e98 {
int func_00227118(u32) asm("func_00227118");
void func_001d30f8(u8*, int, int) asm("func_001d30f8");
void YS__EVENT__set_camera_target(u8* p, int x) asm("YS__EVENT__set_camera_target");
void YS__EVENT__set_camera_target(u8* p, int x) {
    if (!x) return;
    if (func_00227118(*(u32*)(p + 4)) == 2) func_001d30f8(p + 64, 3, x);
    else func_001d30f8(p + 64, 2, x);
}
}  // namespace n00196e98

// ---- 00196f00 from src/anon/batch_w92.cpp
namespace n00196f00 {
inline void* operator new(unsigned int, void* p) { return p; }
struct H196 {
    u16 f0;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
};
static inline u8 bit0_196(H196* h) { return h->b0; }
static inline u8 bit2_196(H196* h) { return h->b2; }
static inline u8 bit3_196(H196* h) { return h->b3; }
struct P196 {
    u32 f0; void* f4; u32 f8; u8 pad[48]; H196* f60; u8 pad2[4]; u32 f68; u8 pad3[8]; u8 f80[76]; u32 f156; u32 f160;
};
struct G196 { u32 f0; u32 f4; };
void func_00226ac0(void*, u8*, u32, u32, void (*)(void), u32, u32) asm("func_00226ac0");
void func_00197d40(void) asm("func_00197d40");
void func_00196e00(P196*) asm("func_00196e00");
void func_00105110(P196*) asm("func_00105110");
void func_001c1130(s32) asm("func_001c1130");
void func_0014c9d8(s32) asm("func_0014c9d8");
void func_00197760(void) asm("func_00197760");
void func_00197c90(void) asm("func_00197c90");
void func_002ef8d0(void*, u32) asm("func_002ef8d0");
void func_00196e88(P196*, s32, s32, f32) asm("func_00196e88");
extern P196* D_0035037c asm("D_0035037c");
extern G196 D_0032b968 asm("D_0032b968");
extern u8 D_01c61b10 asm("D_01c61b10");
extern u8 D_01c61b20 asm("D_01c61b20");
void YS__EVENT__start(P196* p) asm("YS__EVENT__start");
void YS__EVENT__start(P196* p) {
    if (p->f4) func_00226ac0(p->f4, p->f80, p->f68, p->f8, func_00197d40, p->f156, p->f160);
    P196* old = D_0035037c;
    if (old) {
        func_00196e00(old);
        func_00105110(old);
    }
    D_0035037c = p;
    func_001c1130(12);                               
    func_0014c9d8(4);
    if (!bit3_196(p->f60)) func_00197760();
    if (!bit2_196(p->f60)) func_00197c90();
    func_002ef8d0(&D_01c61b10, D_0032b968.f4);
    func_002ef8d0(&D_01c61b20, D_0032b968.f4);
    if (!bit0_196(p->f60)) p->f0 |= 2;
    func_00196e88(p, 0, 0, 0.0f);
}
}  // namespace n00196f00

// ---- 00197028 from src/anon/batch_wcx2.cpp
namespace n00197028 {
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
extern f32 D_00349e10 asm("D_00349e10");
struct T197028 { u8 pad[48]; s32 state; s32 wait; f32 fwait; };
s32 func_002ee530(T197028*) asm("func_002ee530");
void func_00197148(T197028*) asm("func_00197148");
void func_00197280(T197028*) asm("func_00197280");
void func_00197318_x8314(T197028*) asm("func_00197318");
void func_00197390(T197028*) asm("func_00197390");
void func_001973f0(T197028*) asm("func_001973f0");
void func_00197430_x8317(T197028*) asm("func_00197430");
void func_00197568(T197028*) asm("func_00197568");
void func_001975a0(T197028*) asm("func_001975a0");
s32 func_00197028(T197028* p) asm("func_00197028");
s32 func_00197028(T197028* p) {
    if (func_002ee530(p)) return 1;
    for (;;) {
        if (p->wait > 0) {
            p->wait--;
            return 1;
        }
        if (p->fwait > 0.0f) {
            p->fwait -= D_00349e10;
            return 1;
        }
        switch (p->state) {
        case 0: func_00197148(p); break;
        case 1: func_00197280(p); break;
        case 2: func_00197318_x8314(p); break;
        case 3: func_00197390(p); break;
        case 5: func_001973f0(p); break;
        case 6: func_00197430_x8317(p); break;
        case 7: func_00197568(p); break;
        case 9: func_001975a0(p); return 0;
        default: return 1;
        }
    }
}
}  // namespace n00197028

// ---- 00197148 from src/anon/batch_w100.cpp
namespace n00197148 {
struct Info14 { u8 type; u8 kind; u16 bits; f32 val; };
struct Obj14 { u32 flags; u8 pad[56]; Info14* info; };
static inline bool G00(Info14* d) { return d->bits & 1; }
static inline bool G01(Info14* d) { return (d->bits >> 1) & 1; }
extern u8 D_01c61b30[] asm("D_01c61b30");
extern u32 D_0032b96c asm("D_0032b96c");
u32 func_0014aba8(void) asm("func_0014aba8");
void func_0014aa58(u32, s32, s32) asm("func_0014aa58");
void dk__KeyHoleJumpEffect__out(void) asm("dk__KeyHoleJumpEffect__out");
void func_002ef8d0(u8*, u32) asm("func_002ef8d0");
void func_002bc788(void) asm("func_002bc788");
void func_00196e88(Obj14*, s32, s32, f32) asm("func_00196e88");
void func_00197148(Obj14* o) asm("func_00197148");
void func_00197148(Obj14* o) {
    switch (o->info->kind) {
    case 1: func_0014aa58(func_0014aba8(), (s32)(o->info->val * 0.5f), 0); break;
    case 2: func_0014aa58(func_0014aba8(), (s32)(o->info->val * 0.5f), 1); break;
    case 3: dk__KeyHoleJumpEffect__out(); break;
    }
    if (G01(o->info)) {
        func_002ef8d0(D_01c61b30, D_0032b96c);
        if (o->info->type == 16) o->flags |= 4;
        func_002bc788();
    }
    if (G00(o->info)) func_00196e88(o, 1, 1, 0.0f);
    else func_00196e88(o, 4, 0, 0.0f);
}
}  // namespace n00197148

// ---- 00197280 from src/anon/auto80_199_queue.cpp
namespace n00197280 {
void func_00197280(u32 a0) asm("_Z13func_00197280j");
void func_00197280(u32 a0) {
    u32 s0 = a0;
    if (YS__CACHE_BUFF__IsFlushing(a0) != 0) {
        *(u32*)(s0 + 52) = 1;
        return;
    }
    u32 t = *(u32*)(s0 + 60);
    u32 f = (u32)*(u16*)(t + 2);
    if ((u8)((f >> 1) & 1) == 0) {
        if (func_00197c28(s0) != 0) {
            *(u32*)(s0 + 52) = 1;
            return;
        }
    }
    func_00197738();
    func_002bc798();
    func_002ba600();
    func_00196e88(s0, 2, 3, 0.0f);
}
}  // namespace n00197280

// ---- 00197318 from src/anon/batch_wcx2.cpp
namespace n00197318 {
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
void func_00170320(u32) asm("func_00170320");
void func_00196e88_7318(u32*, u32, u32, f32) asm("func_00196e88");
union UH_00197318 { u16 h; u32 i; };
void func_00197318(u32* p) asm("func_00197318");
void func_00197318(u32* p) {
    func_00170320(2000);
    u32 fl = p[0];
    p[0] = fl | 1;
    u8 b = (((UH_00197318*)(p[15] + 2))->h >> 1) & 1;
    if (b) { func_00196e88_7318(p, 3, 0, 0.0f); return; }
    p[0] = fl | 3;
    func_00196e88_7318(p, 4, 0, 0.0f);
}
}  // namespace n00197318

// ---- 00197390 from src/anon/batch_w24.cpp
namespace n00197390 {
s32 func_00197c28(u32*) asm("func_00197c28");
void func_00196e88(u32*, s32, s32, f32) asm("func_00196e88");
void func_00197390(u32* p) asm("func_00197390");
void func_00197390(u32* p) {
    if (func_00197c28(p)) {
        p[13] = 1;
        return;
    }
    p[0] |= 2;
    func_00196e88(p, 4, 0, 0.0f);
}
}  // namespace n00197390

// ---- 001973f0 from src/anon/batch_w16.cpp
namespace n001973f0 {
u32 func_00196e88(void*, u32, u32, f32) asm("func_00196e88");
struct Flags2 {
    u16 a;
    u16 on : 1;
};
static inline u8 is_on(u8* p) { return (*(Flags2**)(p + 60))->on; }
void func_001973f0(u8* p) asm("func_001973f0");
void func_001973f0(u8* p) {
    if (is_on(p)) func_00196e88(p, 6, 2, 0.0f);
    else func_00196e88(p, 6, 0, 0.0f);
}
}  // namespace n001973f0

// ---- 00197430 from src/anon/batch_wcx2.cpp
namespace n00197430 {
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
struct Def15 {
    u8 pad; u8 mode; u16 b0:4; u16 snd:1; u16 alt:1;
    bool Snd() { return snd; }
    bool Alt() { return alt; }
};
struct Obj15 { u8 pad[60]; Def15* def; u8 pad2[80]; f32 vol; };
u32 func_0014abe8(void) asm("func_0014abe8");
u32 func_0014abf8(void) asm("func_0014abf8");
u32 func_0014aba8(void) asm("func_0014aba8");
void func_0014aa58(u32, s32, s32) asm("func_0014aa58");
void func_0014aa80(u32, s32, s32) asm("func_0014aa80");
void func_0013f160(void) asm("func_0013f160");
void func_00196e88(Obj15*, s32, s32, f32) asm("func_00196e88");
void func_00197430(Obj15* p) asm("func_00197430");
void func_00197430(Obj15* p)
{
    if (p->def->Snd()) {
        func_0014aa58(func_0014abe8(), 0, 0);
        func_0014aa58(func_0014abf8(), 0, 0);
    }
    switch (p->def->mode) {
    case 1:
    case 3:
        func_0013f160();
        func_0014aa80(func_0014aba8(), (s32)(p->vol * 0.5f), 0);
        break;
    case 2:
        func_0013f160();
        func_0014aa80(func_0014aba8(), (s32)(p->vol * 0.5f), 1);
        break;
    }
    if (!p->def->Alt()) func_00196e88(p, 7, 2, 0.0f);
    else func_00196e88(p, 8, 0, 0.0f);
}
}  // namespace n00197430

// ---- 00197568 from src/anon/tiny_auto80_queue.cpp
namespace n00197568 {
void func_00196e88(u32, u32, u32, f32) asm("_Z13func_00196e88jjjf");
extern "C" u32 func_002bc788(...) asm("_ZN5SOUND11SE3DDisableEv");
void func_00197568(u32 a0) asm("_Z13func_00197568j");
void func_00197568(u32 a0) {
    u32 s0 = a0;
    func_002bc788(a0);
    func_00196e88(s0, 8u, 0u, 0.0f);
}
}  // namespace n00197568

// ---- 001975a0 from src/anon/batch_w112.cpp
namespace n001975a0 {
struct Cfg { u16 h0; u16 b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, rest : 11; };
struct Obj { u32 flags; u8 pad[8]; u8 sub[48]; Cfg* cfg; };
struct St { u8 pad[244]; u8 b244; u8 pad2[7]; s32 f252; };
extern u8 D_00350379 asm("D_00350379");
extern u8 D_0032b9dd asm("D_0032b9dd");
extern u32 D_0032b9e0 asm("D_0032b9e0");
void dk__Vsync__initGameSpeed(void) asm("dk__Vsync__initGameSpeed");
void func_00194980(void) asm("func_00194980");
s32 func_0019f060(u8*) asm("func_0019f060");
void func_0019f070(u8*, u32) asm("func_0019f070");
u32 func_0014abe8(void) asm("func_0014abe8");
u32 func_0014abf8(void) asm("func_0014abf8");
void func_0014aa80(u32, u32, u32) asm("func_0014aa80");
void func_00170320(s32) asm("func_00170320");
void func_00197780(void) asm("func_00197780");
void func_00197cc0(void) asm("func_00197cc0");
s32 func_00242ea8(void) asm("func_00242ea8");
s32 func_00242ee8(void) asm("func_00242ee8");
St* func_0014aba8(void) asm("func_0014aba8");
u8* func_001058e8(void) asm("func_001058e8");
void func_0014a138(u8) asm("func_0014a138");
static inline bool B4(Cfg* c) { return c->b4; }
static inline bool B2(Cfg* c) { return c->b2; }
static inline u8 U0(Cfg* c) { return c->b0; }
void func_001975a0(Obj* o) asm("func_001975a0");
void func_001975a0(Obj* o) {
    dk__Vsync__initGameSpeed();
    func_00194980();
    if (!func_0019f060(o->sub)) {
        if (B4(o->cfg)) {
            func_0014aa80(func_0014abe8(), 6, 0);
            func_0014aa80(func_0014abf8(), 6, 0);
        }
        if (U0(o->cfg)) func_00170320(-200);
        if (!(o->flags & 0x20)) func_00197780();
        if (!B2(o->cfg)) func_00197cc0();
    }
    if (func_00242ea8() && ((o->flags & 0x10) || (!func_00242ee8() && D_00350379 == 0))) {
        u8 v = 0;
        if ((func_0014aba8()->f252 ^ 4) == 0) {
            v = func_0014aba8()->b244;
            if (v == 1) D_0032b9dd = v;
        }
        D_0032b9e0 = func_001058e8()[12];
        func_0014a138(v);
        return;
    }
    func_0019f070(o->sub, 0x80000000);
}
}  // namespace n001975a0

// ---- 00197738 from src/anon/batch_w6.cpp
namespace n00197738 {
void ys_prepare_scene(void) asm("_ZN2YS5EVENT12PrepareSceneEv");
void YS__OBJ__LeaveAll(u32) asm("YS__OBJ__LeaveAll");
void func_00197c90(void) asm("func_00197c90");
void YS__RECOV__Exec(u32) asm("YS__RECOV__Exec");
void ys_prepare_scene(void) {
    YS__OBJ__LeaveAll(2000);
    func_00197c90();
    YS__RECOV__Exec(11);
}
}  // namespace n00197738

// ---- 00197760 YS::EVENT::ControlOff (from src/anon/batch_w5.cpp)
namespace n00197760 {
void func_001b9c28(s32) asm("func_001b9c28");
void EVENT_ControlOff() asm("_ZN2YS5EVENT10ControlOffEv");
void EVENT_ControlOff() {
    func_001b9c28(0);
    func_001b9c28(1);
}
}  // namespace n00197760

// ---- 00197780 YS::EVENT::ControlOn (from src/anon/batch_w1.cpp)
namespace n00197780 {
void YS_OBJ_ControlOn(s32) asm("_ZN2YS3OBJ9ControlOnEi");
void EVENT_ControlOn() asm("_ZN2YS5EVENT9ControlOnEv");
void EVENT_ControlOn() {
    YS_OBJ_ControlOn(0);
    YS_OBJ_ControlOn(1);
}
}  // namespace n00197780

// ---- 001977a0 from src/anon/tiny_auto80_queue.cpp
namespace n001977a0 {
u32 func_001977d8(...) asm("func_001977d8");
u32 func_00197800(...) asm("func_00197800");
u32 func_001977a0(...) asm("func_001977a0");
u32 func_001977a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001977a0");
u32 func_001977a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001977d8)();
    r15 = 0u;
    if (r2 == 0u) {
        r2 = ((u32(*)())func_00197800)();
        r15 = ((u32)r2 < 0x00000001u);
    }
    r2 = r15;
    return r2;
}
}  // namespace n001977a0

// ---- 001977d8 from src/anon/auto200_999.cpp
namespace n001977d8 {
extern u32 D_0035037c asm("D_0035037c");
u32 func_001977d8() asm("_Z13func_001977d8v");
u32 func_001977d8() {
    u32 p = D_0035037c;
    u32 ret = 0;
    if (p != 0) {
        u32 v = *(u32 *)p;
        v &= 1;
        ret = v != 0;
    }
    return ret;
}
}  // namespace n001977d8

// ---- 00197800 from src/anon/auto200_999.cpp
namespace n00197800 {
extern u32 D_0035037c asm("D_0035037c");
u32 func_00197800() asm("_Z13func_00197800v");
u32 func_00197800() {
    u32 p = D_0035037c;
    u32 ret = 0;
    if (p != 0) {
        u32 v = *(u32 *)p;
        v &= 2;
        ret = v != 0;
    }
    return ret;
}
}  // namespace n00197800

// ---- 00197828 from src/anon/batch_wcx2.cpp
namespace n00197828 {
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
struct G197 { u8 pad[60]; u8* o; u8 pad2[80]; f32 f144; };
union U197 { G197* g; u8** p; };
extern U197 D_0035037c asm("D_0035037c");
void dk__Vsync__initGameSpeed() asm("dk__Vsync__initGameSpeed");
s32 func_00242ea8() asm("func_00242ea8");
s32 func_00224e90() asm("func_00224e90");
void func_00138480(u32) asm("func_00138480");
void func_001c1130(u32) asm("func_001c1130");
void func_002bc798() asm("func_002bc798");
void func_00196e88_7828(G197*, u32, u32, f32) asm("func_00196e88");
struct F197 { u16 pad; u16 b0:1; u16 b1:1; u16 b2:1; u16 b3:1; u16 b4:1; u16 b5:1; };
static inline u8 b0_197828() { return ((F197*)(*(G197* volatile*)&D_0035037c.g)->o)->b0; }
static inline u8 b5_197828() { return ((F197*)(*(G197* volatile*)&D_0035037c.g)->o)->b5; }
void func_00197828(f32 f) asm("func_00197828");
void func_00197828(f32 f) {
    dk__Vsync__initGameSpeed();
    if (b0_197828()) {
        if (!func_00242ea8()) func_001c1130(4);
        else {
            if (func_00224e90()) func_00138480(0);
            func_001c1130(36);                               
        }
    }
    if (!b5_197828()) func_002bc798();
    func_00196e88_7828(D_0035037c.g, 5, 0, 0.0f);
    D_0035037c.g->f144 = f;
}
}  // namespace n00197828

// ---- 001978f0 from src/anon/tiny_auto80_queue.cpp
namespace n001978f0 {
void func_00196e88(u32, u32, u32, f32) asm("_Z13func_00196e88jjjf");
u32 func_001c1130(...) asm("func_001c1130");
void func_001978f0(void) asm("_Z13func_001978f0v");
void func_001978f0(void) {
    func_001c1130(12u);                               
    u32 t7 = (u32)(0x0035u << 16);
    func_00196e88(*(u32*)((u32)t7 + (s32)(892)), 9u, 0u, 0.0f);
}
}  // namespace n001978f0

// ---- 00197920 YS::EVENT::IsExec (from src/yasui/libys/event.cpp)
namespace n00197920 {
extern u32 D_0035037c asm("D_0035037c");
u32 EVENT_IsExec() asm("_ZN2YS5EVENT6IsExecEv");
u32 EVENT_IsExec() { return (D_0035037c != 0); }
}  // namespace n00197920

// ---- 00197930 from src/anon/batch_wcx.cpp
namespace n00197930 {
struct S36 { u32 w[9]; };
u8* func_001050d8(s32) asm("func_001050d8");
u32 func_00181c80(u32) asm("func_00181c80");
void YS__EVENT__EVENT(u8*, u32, u32) asm("YS__EVENT__EVENT");
void YS__EVENT__start(u8*) asm("YS__EVENT__start");
void func_00197930(u32 a, u32 b, S36* c) asm("func_00197930");
void func_00197930(u32 a, u32 b, S36* c)
{
    u8* o = func_001050d8(176);
    YS__EVENT__EVENT(o, b, func_00181c80(a));
    *(S36*)(o + 12) = *c;
    YS__EVENT__start(o);
}
}  // namespace n00197930

// ---- 001979d8 from src/anon/batch_w7.cpp
namespace n001979d8 {
u8 func_0019f2a8(u32, u32) asm("func_0019f2a8");
extern u32 D_0035037c asm("D_0035037c");
u32 func_001979d8(u32 a0) asm("func_001979d8");
u32 func_001979d8(u32 a0) {
    return func_0019f2a8(D_0035037c + 12, a0);
}
}  // namespace n001979d8

// ---- 00197a00 from src/anon/batch_w79.cpp
namespace n00197a00 {
extern s32 D_0035037c asm("D_0035037c");
s32 func_00197028(s32) asm("func_00197028");
void func_00196e00(void*) asm("func_00196e00");
void func_00105110(void*) asm("func_00105110");
extern s32 D_01c61b40 asm("D_01c61b40");
s32 func_001991a8(s32, s32) asm("func_001991a8");
void func_001024a8(void*) asm("func_001024a8");
void func_00197a00(void* a) asm("func_00197a00");
void func_00197a00(void* a) {
    if (D_0035037c != 0) {
        u8* o;
        u8 flag;
        if (func_00197028(D_0035037c) != 0) return;
        o = (u8*)D_0035037c;
        flag = *(volatile u16*)(*(u8**)(o + 60) + 2) & 1;
        if (o != 0) {
            func_00196e00(o);
            func_00105110(o);
        }
        if (flag && func_001991a8(76, D_01c61b40++) != 0) return;
    }
    func_001024a8(a);
}
}  // namespace n00197a00

// ---- 00197ac0 from src/anon/batch_w1732.cpp
namespace n00197ac0 {
void YS__EVENT_CAMERA__make_matrix(void*) asm("YS__EVENT_CAMERA__make_matrix");
void func_001024a8(void*) asm("func_001024a8");
extern u8* D_0035037c asm("D_0035037c");
void func_00197ac0(void* a) asm("func_00197ac0");
void func_00197ac0(void* a) {
    u8* p = D_0035037c;
    if (p) YS__EVENT_CAMERA__make_matrix(p + 64);
    else func_001024a8(a);
}
}  // namespace n00197ac0

// ---- 00197af8 gap: task callback (third static task)
namespace n00197af8 {
extern u32* D_0035037c asm("D_0035037c");
u32 func_00197800() asm("_Z13func_00197800v");
void func_0014e098(s32) asm("func_0014e098");
void func_0014e0d8() asm("func_0014e0d8");
void func_001024a8(u8*) asm("func_001024a8");
void func_00197af8(u8* t) asm("func_00197af8");
void func_00197af8(u8* t) {
    if (D_0035037c != 0 && func_00197800() == 0) {
        if (*D_0035037c & 4) {
            func_0014e098(216);
            return;
        }
        func_0014e0d8();
        *D_0035037c |= 4;
        return;
    }
    func_001024a8(t);
}
}  // namespace n00197af8

// ---- 00197b98 from src/anon/batch_w213.cpp
namespace n00197b98 {
struct E197 { u8 pad[48]; s32 st; };
extern E197* D_0035037c asm("D_0035037c");
s32 func_002283f8() asm("func_002283f8");
float GetRestTime_00197b98() asm("_ZN2YS5EVENT11GetRestTimeEv");
float GetRestTime_00197b98() {
    float r;
    E197* p = D_0035037c;
    if (p) {
        r = 3600.0f;
        if (p->st == 8) r = (float)func_002283f8();
    } else r = 0.0f;
    return r;
}
}  // namespace n00197b98

// ---- 00197be8 from src/anon/batch_w17.cpp
namespace n00197be8 {
extern void* D_0035037c asm("D_0035037c");
void func_00196e00(void*) asm("func_00196e00");
u8 opDelete_u8(void*) asm("func_00105110");
u8 EventExit(void) asm("_ZN2YS5EVENT4ExitEv");
u8 EventExit(void) {
    void* e = D_0035037c;
    if (e) {
        func_00196e00(e);
        return opDelete_u8(e);
    }
}
}  // namespace n00197be8

// ---- 00197c28 from src/anon/batch_w40.cpp
namespace n00197c28 {
bool func_0013ef80(void) asm("func_0013ef80");
u8* func_0014aba8(void) asm("func_0014aba8");
bool func_00197c28(u8* p) asm("func_00197c28");
bool func_00197c28(u8* p) {
    s32 t = (*(u8**)(p + 60))[1];
    switch (t) {
    case 1: case 2: return *(s32*)(func_0014aba8() + 252) != 4;
    case 3: return !func_0013ef80();                           
    }
    return 0;
}
}  // namespace n00197c28

// ---- 00197c90 from src/anon/tiny_auto80_fptr0.cpp
namespace n00197c90 {
u32 func_0014f200() asm("_Z13func_0014f200v");
u32 func_0014f250() asm("_Z13func_0014f250v");
u32 func_0014f1a0() asm("_Z13func_0014f1a0v");
u32 func_0014f2d8() asm("_Z13func_0014f2d8v");
u32 func_00197c90(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00197c90jjjj");
u32 func_00197c90(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0014f2d8)() = func_0014f2d8;
    r2 = fp_call0_0014f2d8();
    u32 (*fp_call0_0014f250)() = func_0014f250;
    r2 = fp_call0_0014f250();
    u32 (*fp_call0_0014f200)() = func_0014f200;
    r2 = fp_call0_0014f200();
    return func_0014f1a0();
}
}  // namespace n00197c90

// ---- 00197cc0 from src/anon/tiny_auto80_fptr0.cpp
namespace n00197cc0 {
u32 func_0014f1f8() asm("_Z13func_0014f1f8v");
u32 func_0014f238() asm("_Z13func_0014f238v");
u32 func_0014f178() asm("_Z13func_0014f178v");
u32 func_0014f2b0() asm("_Z13func_0014f2b0v");
u32 func_00197cc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00197cc0jjjj");
u32 func_00197cc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0014f2b0)() = func_0014f2b0;
    r2 = fp_call0_0014f2b0();
    u32 (*fp_call0_0014f238)() = func_0014f238;
    r2 = fp_call0_0014f238();
    u32 (*fp_call0_0014f1f8)() = func_0014f1f8;
    r2 = fp_call0_0014f1f8();
    return func_0014f178();
}
}  // namespace n00197cc0

// ---- 00197cf0 gap: callback (address stored by 0x197d18)
namespace n00197cf0 {
u32 func_00197cc0(u8*) asm("_Z13func_00197cc0jjjj");
void func_001024a8(u8*) asm("func_001024a8");
void func_00197cf0(u8* t) asm("func_00197cf0");
void func_00197cf0(u8* t) {
    func_00197cc0(t);
    func_001024a8(t);
}
}  // namespace n00197cf0

// ---- 00197d18 from src/anon/tiny_auto80_solver.cpp
namespace n00197d18 {
u32 func_00102c18(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00102c18jjjjjjjj");
extern u8 D_00197cf0 asm("D_00197cf0");
u32 func_00197d18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00197d18jjjjjjjj");
u32 func_00197d18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7;
    r6 = (u32)&D_00197cf0;
    r4 = (u32)((s32)0u + (1));
    r5 = (u32)((s32)0u + (15000));    return ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00102c18)(r4, r5, r6, r7, r8, r9, r10, r11);
}
}  // namespace n00197d18

// ---- 00197d40 gap
namespace n00197d40 {
extern u8* D_0035037c asm("D_0035037c");
extern u8* D_0034e948 asm("D_0034e948");
u8* func_0014aba8() asm("func_0014aba8");
void func_0014aa58(u8*, s32, s32) asm("func_0014aa58");
void YS__EVENT__set_camera_target(u8*, u8*) asm("YS__EVENT__set_camera_target");
void func_001d30f8(u8*, s32, s32) asm("func_001d30f8");
void YS__EVENT_CAMERA__make_matrix(u8*) asm("YS__EVENT_CAMERA__make_matrix");
void func_00197d40(s32 m) asm("func_00197d40");
void func_00197d40(s32 m) {
    switch (m) {
    case 0:
        if (*(u32*)D_0035037c & 8) func_0014aa58(func_0014aba8(), 15, 0);
        break;
    case 1:
        YS__EVENT__set_camera_target(D_0035037c, D_0034e948);
        break;
    case 2:
        func_001d30f8(D_0035037c + 64, 4, 0);
        break;
    }
    YS__EVENT_CAMERA__make_matrix(D_0035037c + 64);
}
}  // namespace n00197d40

// ---- 00197df8 YS::EVENT::GetImage (from src/yasui/libys/event.cpp)
namespace n00197df8 {
extern u32 D_0035037c asm("D_0035037c");
void* EVENT_GetImage() asm("_ZN2YS5EVENT8GetImageEv");
void* EVENT_GetImage() {
    u32 p = D_0035037c;
    return (void*)((s32)p + 148);
}
}  // namespace n00197df8

// ---- 00197e08 from src/anon/batch_w23.cpp
namespace n00197e08 {
extern u8* D_0035037c asm("D_0035037c");
void func_001d32e8(void*, s32, s32) asm("func_001d32e8");
void func_00197e08(s32 a, s32 b) asm("func_00197e08");
void func_00197e08(s32 a, s32 b) {
    if (D_0035037c) func_001d32e8(D_0035037c + 64, a, b);
}
}  // namespace n00197e08

// ---- 00197e40 from src/anon/tiny_auto80_queue.cpp
namespace n00197e40 {
u32 func_00197e40(void) asm("_Z13func_00197e40v");
u32 func_00197e40(void) {
    u32 t6 = 0u;
    u32 t7 = (u32)(0x0035u << 16);
    t7 = *(u32*)((u32)t7 + (s32)(892));
    u32 v0 = 0u;
    if (t7 != 0u) {
        u32 p = *(u32*)((u32)t7 + (s32)(60));
        t6 = (u32)(*(u16*)((u32)p + (s32)(2)));
        v0 = (u32)(t6 & 0x0001u);
    }
    return v0;
}
}  // namespace n00197e40

// ---- 00197e68 from src/anon/tiny_leaf.cpp
namespace n00197e68 {
void func_00197e68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00197e68jjjj");
void func_00197e68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r13 = 0u, r14 = 0u, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r13 = *(u32*)((u32)r15 + (s32)(892));
    r14 = *(u32*)((u32)r13 + (s32)(0));
    r14 = (u32)(r14 | 0x0010u);
    *(u32*)((u32)r13 + (s32)(0)) = r14;
}
}  // namespace n00197e68

// ---- 00197e80 YS::EVENT::ContinueControlOff (from src/yasui/libys/event.cpp)
namespace n00197e80 {
void EVENT_ContinueControlOff() asm("_ZN2YS5EVENT18ContinueControlOffEv");
void EVENT_ContinueControlOff() {
    u32 t7 = (u32)(0x0035u << 16);
    u32 t6 = *(u32*)((u32)t7 + (s32)(892));
    if (t6 != 0u) {
        u32 t7v = *(u32*)((u32)t6 + (s32)(0));
        t7v = (u32)(t7v | 0x0020u);
        *(u32*)((u32)t6 + (s32)(0)) = t7v;
    }
}
}  // namespace n00197e80

// ---- 00197ea8 gap: static initialiser of the three event tasks (plain function, as the I stub)
namespace n00197ea8 {
struct TASK { s32 on; s32 prio; void (*fn)(u8*); s32 next; };
extern TASK D_01c61b10 asm("D_01c61b10");
extern TASK D_01c61b20 asm("D_01c61b20");
extern TASK D_01c61b30 asm("D_01c61b30");
void func_00197a00(u8*) asm("func_00197a00");
void func_00197ac0(u8*) asm("func_00197ac0");
void func_00197af8(u8*) asm("func_00197af8");
void func_00197ea8(s32 init, s32 prio) asm("_Z13func_00197ea8jjjj");
void func_00197ea8(s32 init, s32 prio) {
    if (prio == 0xffff && init == 1) {
        D_01c61b10.on = init;
        D_01c61b10.prio = 16000;
        D_01c61b10.fn = func_00197a00;
        D_01c61b10.next = 0;
    }
    if (prio == 0xffff && init == 1) {
        D_01c61b20.on = init;
        D_01c61b20.prio = 24500;
        D_01c61b20.fn = func_00197ac0;
        D_01c61b20.next = 0;
    }
    if (prio == 0xffff && init == 1) {
        D_01c61b30.on = init;
        D_01c61b30.prio = 200000;
        D_01c61b30.fn = func_00197af8;
        D_01c61b30.next = 0;
    }
}
}  // namespace n00197ea8

// ---- 00197f60 from src/anon/tiny_wrappers_more.cpp
namespace n00197f60 {
u32 func_00197ea8(u32, u32, u32, u32) asm("_Z13func_00197ea8jjjj");
u32 func_00197f60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00197f60jjjj");
u32 func_00197f60(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00197ea8(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00197f60

// ---- 00197f80 gap: YS::STDOBJ C2 ctor copy (C1 is 0x197fe0 in unit_00197fe0.cpp)
namespace n00197f80 {
extern u8 D_00350388 asm("D_00350388");
void func_00169398(void*, u32, u32*, s32, s32) asm("func_00169398");
void func_00197f80(u8* o, u32* a, u32 b, u32 c) asm("func_00197f80");
void func_00197f80(u8* o, u32* a, u32 b, u32 c) {
    func_00169398(o, *a | 0x40000000, a, b, c);
    *(void**)o = &D_00350388;
    *(u32*)(o + 1416) |= 0x20;
}
}  // namespace n00197f80

