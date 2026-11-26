#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../harata/libdk/sprite.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../tozawa/help_gra.hpp"
#include "../harata/libdk/obj2d.hpp"

// ---- 00138480 from src/anon/auto200_999.cpp
namespace n00138480 {
extern u32 D_00347e08 asm("D_00347e08");
}  // namespace n00138480
namespace dk {
class Pause {
  public:
    static void disable(s32);
};
void Pause::disable(s32 a0) { using namespace ::n00138480;
    u32 mask = 1u << a0;
    D_00347e08 |= mask;
}
}  // namespace dk

// ---- 001384a0 from src/anon/tiny_auto80_solver.cpp
namespace n001384a0 {
void func_001384a0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001384a0jjjjjjjj");
void func_001384a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001384a0jjjjjjjj");
void func_001384a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r13, r14, r15;
    r13 = (u32)(0x0034u << 16);
    r15 = (u32)((s32)0u + (1));
    r14 = *(volatile u32*)((u32)r13 + (s32)(32264));
    r15 = (u32)(r15 << r4);
    r15 = (u32)(~(0u | r15));
    r14 = (u32)(r14 & r15);
    *(volatile u32*)((u32)r13 + (s32)(32264)) = r14;
}
}  // namespace n001384a0

// ---- 001384c0 from src/anon/tiny.cpp
namespace n001384c0 {
extern u32 D_00347e08 asm("D_00347e08");
u32 func_001384c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001384c0jjjj");
u32 func_001384c0(u32 a0, u32 a1, u32 a2, u32 a3) {                      
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_00347e08 != 0);
}
}  // namespace n001384c0

// ---- 001384d0 from src/anon/batch_w76.cpp
namespace n001384d0 {
s32 func_001384c0(void) asm("func_001384c0");
extern u8 D_0032bad8 asm("D_0032bad8");
s32 func_00103b38(void) asm("func_00103b38");
u8* func_0014aba8(void) asm("func_0014aba8");
s32 func_002ee530(void) asm("func_002ee530");
u8* func_00167f18(u32) asm("func_00167f18");
u32 func_001c1218(void) asm("func_001c1218");
s32 func_001688b8(void) asm("func_001688b8");
void Tz__CampMenu__Start(u32, s32) asm("Tz__CampMenu__Start");
void func_00253410(u32, u32) asm("func_00253410");
void func_00102448(u32, u32) asm("func_00102448");
void* func_001050c8(void) asm("func_001050c8");
typedef void (*VFn)(void*);
void func_001384d0(u32 a) asm("func_001384d0");
void func_001384d0(u32 a)
{
    for (;;) {
        if (!func_001384c0() && D_0032bad8 && !func_00103b38()
            && *(u32*)(func_0014aba8() + 252) == 0 && !func_002ee530()
            && (*(u64*)(func_00167f18(0) + 8) & 2)) {
            u32 v = func_001c1218();
            if (!v) { if (!func_001688b8()) Tz__CampMenu__Start(0, -1); }
            else func_00253410(v, 0);
        }
        func_00102448(a, 0);
        void* o = func_001050c8();
        if (o) (*(VFn*)(*(u8**)o + 16))(o);
    }
}
}  // namespace n001384d0

// ---- 001385c0 from src/anon/batch_w20.cpp
namespace n001385c0 {
void func_00102c48(u32, u32, void*, u32) asm("func_00102c48");
void func_001384d0(void) asm("func_001384d0");
extern u32 D_00347e08 asm("D_00347e08");
void dk__Pause__init(void) asm("dk__Pause__init");
void dk__Pause__init(void) {
    D_00347e08 = 0;
    func_00102c48(1, 0x4baf0, (void*)func_001384d0, 0x1000);
}
}  // namespace n001385c0

// ---- 001385f8 from src/anon/tiny_auto80_fptr0.cpp
namespace n001385f8 {
u32 func_0014d680() asm("_Z13func_0014d680v");
u32 func_0014d8a8() asm("_Z13func_0014d8a8v");
u32 func_0014d008() asm("_Z13func_0014d008v");
u32 func_001385f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001385f8jjjj");
u32 func_001385f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0014d8a8)() = func_0014d8a8;
    r2 = fp_call0_0014d8a8();
    u32 (*fp_call0_0014d680)() = func_0014d680;
    r2 = fp_call0_0014d680();
    return func_0014d008();
}
}  // namespace n001385f8

// ---- 00138620 from src/anon/tiny_auto80_fptr0.cpp
namespace n00138620 {
u32 func_0014a4f0() asm("_Z13func_0014a4f0v");
u32 func_0014ad20() asm("_Z13func_0014ad20v");
u32 func_0014dfa8() asm("_Z13func_0014dfa8v");
u32 func_0014a470() asm("_Z13func_0014a470v");
u32 func_00138620(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00138620jjjj");
u32 func_00138620(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0014dfa8)() = func_0014dfa8;
    r2 = fp_call0_0014dfa8();
    u32 (*fp_call0_0014ad20)() = func_0014ad20;
    r2 = fp_call0_0014ad20();
    u32 (*fp_call0_0014a4f0)() = func_0014a4f0;
    r2 = fp_call0_0014a4f0();
    return func_0014a470();
}
}  // namespace n00138620

// ---- 00138650 from src/anon/batch_w52.cpp
namespace n00138650 {
void func_001391c8(u8*, u32, u32) asm("func_001391c8");
void YI__IMAGE__Init(u8*, u32) asm("YI__IMAGE__Init");
void func_002367c8(u8*) asm("func_002367c8");
void dk__SpriteImage__create(u8* p, u32 a, u32 b, u32 c) asm("dk__SpriteImage__create");
void dk__SpriteImage__create(u8* p, u32 a, u32 b, u32 c) {
    func_001391c8(p, a, c);
    YI__IMAGE__Init(p + 32, b);
    func_002367c8(p + 32);                            
}
}  // namespace n00138650

// ---- 00138698 from src/anon/batch_w12.cpp
namespace n00138698 {
void YI__IMAGE__Init(void*, void*) asm("YI__IMAGE__Init");
void func_002367c8(void*) asm("func_002367c8");
void SpriteImage_change(void*, void*) asm("_ZN2dk11SpriteImage6changeEPv");
void SpriteImage_change(void* self, void* data) {
    u8* img = (u8*)self + 32;
    YI__IMAGE__Init(img, data);
    func_002367c8(img);                            
}
}  // namespace n00138698

// ---- 001386c8 gap: slot 2 of the vtable at 0x347e78
namespace n001386c8 {
void func_00236788(u8*) asm("func_00236788");
void func_001386c8(u8* p) asm("func_001386c8");
void func_001386c8(u8* p) { func_00236788(p + 32); }
}  // namespace n001386c8

// ---- 001386e0 from src/anon/batch_w45.cpp
namespace n001386e0 {
void func_001391c8(u32, u32, u32) asm("func_001391c8");
void func_00138748(u32) asm("func_00138748");
void func_001387f8(u32, u32, u32, u32) asm("func_001387f8");
void dk__Sprite__create(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1) asm("dk__Sprite__create");
void dk__Sprite__create(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1) {
    func_001391c8(a0, a1, t1);
    func_00138748(a0);
    func_001387f8(a0, a2, a3, t0);
}
}  // namespace n001386e0

// ---- 00138748 from src/anon/batch_wcx.cpp
namespace n00138748 {
void func_001396b0(u8*) asm("func_001396b0");
void func_0031a260(u8*, s32) asm("func_0031a260");
void func_0031ac78(u8*, s32) asm("func_0031ac78");
void func_00138748(u8*) asm("func_00138748");
void func_00138748(u8* p) asm("func_00138748");
void func_00138748(u8* p)
{
    *(u32*)(p + 368) = 0;
    *(u32*)(p + 372) = 0;
    *(u32*)(p + 376) = 0;
    *(f32*)(p + 384) = 1.0f;
    *(u32*)(p + 380) = 0;
    *(u32*)(p + 396) = 0;
    func_001396b0(p);
    if (*(u32*)(p + 396)) {
        *(u32*)(p + 400) = 0;
        func_001396b0(p);
        if (*(u32*)(p + 400)) func_0031a260(p, 0);
    }
    *(u32*)(p + 400) = 0;
    func_001396b0(p);
    if (*(u32*)(p + 400)) {
        *(u32*)(p + 396) = 0;
        func_001396b0(p);
        if (*(u32*)(p + 396)) func_0031ac78(p, 0);
    }
    p[405] = 0;
}
}  // namespace n00138748

// ---- 001387f8 from src/anon/batch_w53.cpp
namespace n001387f8 {
void YI__SEQUENCE__Init(u8*) asm("YI__SEQUENCE__Init");
void func_00138c10(u8*, u32) asm("func_00138c10");
void func_001387f8(u8* p, u32 a1, u32 a2, u32 a3) asm("func_001387f8");
void func_001387f8(u8* p, u32 a1, u32 a2, u32 a3) {
    YI__SEQUENCE__Init(p + 24);
    func_00138c10(p, a3);
    *(s32*)(p + 392) = -1;
}
}  // namespace n001387f8

// ---- 00138840 from src/anon/batch_wcx2.cpp
namespace n00138840 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
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
void func_0023acd8(u8* p) asm("func_0023acd8");
struct VB36 {
    f32 x, y, z, w;
    VB36& operator=(const VB36& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB36 operator-(const Vec4& b) const
    {
        VB36 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Anm3 { u8 pad[276]; s32 cur; };
struct Obj3 {
    void** vt;
    u8 pad[8];
    u32 flags;
    u8 pad2[8];
    Anm3 anm;
    u8 pad3[384 - 24 - 280];
    f32 speed;
    u8 pad4[4];
    s32 next;
    void* wait0;
    void* wait1;
    u8 dirty;
};
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00239d10(void*) asm("func_00239d10");
void func_00239eb8(Anm3*, f32) asm("func_00239eb8");
s32 func_00239d30(Anm3*, s32) asm("func_00239d30");
void func_00138c10(Obj3*, s32) asm("func_00138c10");
void func_00139570(Obj3*) asm("func_00139570");
static inline void Idle3(Obj3* p)
{
    if (p->flags & 0x80) func_00139570(p);
    else ((void (*)(Obj3*))p->vt[5])(p);
}
void dk__Sprite__update(Obj3* p) asm("_Z18dk__Sprite__updatePv");
void dk__Sprite__update(Obj3* p)
{
    if (p->flags & 0x100) return;
    if (!(p->flags & 0x800)) goto update;
    if (p->wait0 && !func_00139d78(p->wait0)) goto fin;
    if (!p->wait1 || func_00239d10(p->wait1)) goto update;
fin:
    Idle3(p);
    return;
update:
    Anm3* a = &p->anm;
    func_00239eb8(a, p->speed);
    func_0023acd8((u8*)a);
    if (p->dirty) p->dirty = 0;
    if ((u8)func_00239d30(a, a->cur)) return;
    if (func_00239d10(a)) return;
    if (p->next != -1) {
        func_00138c10(p, p->next);
        p->next = -1;
        func_0023acd8((u8*)a);
        p->dirty = 1;
        return;
    }
    Idle3(p);
}
}  // namespace n00138840

// ---- 00138988 from src/anon/batch_w1913_nsa.cpp
namespace n00138988 {
struct W1622Seq {
    u8 pad0[280];
    f32 r, g, b;
    u8 pad124[36];
    s32 x, y;
    void setPos(s32 nx, s32 ny) { x = nx; y = ny; }
};
struct W1622Sprite {
    u32 vt;
    u8 pad4[8];
    u32 flags;
    u8 pad10[8];
    W1622Seq seq;
    u8 pad168[8];
    s32 posX, posY;
    s32 offX, offY;
    u8 pad180[12];
    W1622Sprite* parent;
    W1622Seq* parentSeq;
    u8 pad194;
    u8 clear;
    void setPos(s32 x, s32 y) { posX = x; posY = y; }
};
s32 W1622_isActive(W1622Sprite*) asm("_Z16u_call4_00139d78jjjj");
s32 W1622_getDrawMode(W1622Seq*) asm("_ZN2YI8SEQUENCE11GetDrawModeEv");
void W1622_getXYAddOff(W1622Sprite*, s32*, s32*) asm("_ZN2dk6Sprite23getSeqActiveXYAddOffsetERiS1_");
void W1622_getActiveXY(W1622Seq*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
u32 W1622_getActiveRGBA(W1622Seq*) asm("_ZN2YI8SEQUENCE13GetActiveRGBAEv");
void W1622_setRGBA(W1622Seq*, f32, f32, f32, f32) asm("_Z16wtarget_00239fd0jjjj");
void YI__SEQUENCE__Draw(W1622Seq*) asm("YI__SEQUENCE__Draw");
void YI__IMAGE_CACHE__Clear(void) asm("YI__IMAGE_CACHE__Clear");
void dk__Sprite__draw(W1622Sprite* s) asm("dk__Sprite__draw");
void dk__Sprite__draw(W1622Sprite* s) {
    if (s->flags & 0x800) {
        if (s->parent && !W1622_isActive(s->parent)) return;
        if (s->parentSeq && !W1622_getDrawMode(s->parentSeq)) return;
    }
    s32 x, y;
    if (s->parent) {
        W1622_getXYAddOff(s->parent, &x, &y);
        s->setPos(s->parent->posX + x, s->parent->posY + y);
    } else if (s->parentSeq) {
        W1622_getActiveXY(s->parentSeq, &x, &y);
        s->setPos(x + s->parentSeq->x, y + s->parentSeq->y);
    }
    if ((s->parent || s->parentSeq) && (s->flags & 0x200)) {
        u32 c;
        if (s->parent) c = W1622_getActiveRGBA(&s->parent->seq);
        else c = W1622_getActiveRGBA(s->parentSeq);
        W1622Seq* q = &s->seq;
        f32 r = q->r;
        f32 g = q->g;
        f32 b = q->b;
        f32 a = (f32)(c >> 24) * 0.0078125f;
        if (!(s->flags & 0x400)) {
            r = (f32)(c & 0xff) * 0.0078125f;
            g = (f32)((c & 0xff00) >> 8) * 0.0078125f;
            b = (f32)((c & 0xff0000) >> 16) * 0.0078125f;
        }
        W1622_setRGBA(q, r, g, b, a);
    }
    if (!(s->flags & 0x1000)) {
        W1622Seq* q = &s->seq;
        q->setPos(s->posX + s->offX, s->posY + s->offY);
        YI__SEQUENCE__Draw(q);
    }
    if (s->clear) YI__IMAGE_CACHE__Clear();
}
}  // namespace n00138988

// ---- 00138c10 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00138c10 {
u32 func_00239c38(u32, u32, u32, u32) asm("_Z13func_00239c38jjjj");
u32 func_00138c10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00138c10jjjj");
u32 func_00138c10(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(388)) = r5;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239c38(r4, r5, r6, r7);
    *(u8*)((u32)r16 + (s32)(404)) = (u8)0u;
    return r2;
}
}  // namespace n00138c10

// ---- 00138c40 from src/harata/libdk/sprite.cpp
namespace n00138c40 {
}  // namespace n00138c40
namespace dk {
void Sprite::setPos(s32 x, s32 y) { using namespace ::n00138c40;
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    s->posX = x;
    s->posY = y;
}
}  // namespace dk

// ---- 00138c50 from src/harata/libdk/sprite.cpp
namespace n00138c50 {
}  // namespace n00138c50
namespace dk {
void Sprite::getPos(s32& x, s32& y) { using namespace ::n00138c50;
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    x = s->posX;
    y = s->posY;
}
}  // namespace dk

// ---- 00138c68 from src/harata/libdk/sprite.cpp
namespace n00138c68 {
}  // namespace n00138c68
namespace dk {
void Sprite::setOffsetPos(s32 x, s32 y) { using namespace ::n00138c68;
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    s->offsetX = x;
    s->offsetY = y;
}
}  // namespace dk

// ---- 00138c78 from src/harata/libdk/sprite.cpp
namespace n00138c78 {
}  // namespace n00138c78
namespace dk {
void Sprite::getOffsetPos(s32& x, s32& y) { using namespace ::n00138c78;
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    x = s->offsetX;
    y = s->offsetY;
}
}  // namespace dk

// ---- 00138c90 from src/anon/tiny_auto80.cpp
namespace n00138c90 {
void dk__Sprite__getPosAddOffset(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z27dk__Sprite__getPosAddOffsetjjjj");
void dk__Sprite__getPosAddOffset(u32 a0, u32 a1, u32 a2, u32 a3) {                      
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(376));
    r15 = *(volatile u32*)((u32)r4 + (s32)(368));
    r15 = (u32)(r15 + r14);
    *(volatile u32*)((u32)r5 + (s32)(0)) = r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(380));
    r15 = *(volatile u32*)((u32)r4 + (s32)(372));
    r15 = (u32)(r15 + r14);
    *(volatile u32*)((u32)r6 + (s32)(0)) = r15;
}
}  // namespace n00138c90

// ---- 00138cb8 from src/harata/libdk/sprite.cpp
namespace n00138cb8 {
extern u32 YI_SEQUENCE_GetActiveXY(void*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
}  // namespace n00138cb8
namespace dk {
u32 Sprite::getSeqActiveXY(s32& x, s32& y) { using namespace ::n00138cb8; using ::n00138cb8::YI_SEQUENCE_GetActiveXY;
    return YI_SEQUENCE_GetActiveXY(reinterpret_cast<u8*>(this) + 24u, &x, &y);
}
}  // namespace dk

// ---- 00138cd0 from src/harata/libdk/sprite.cpp
namespace n00138cd0 {
extern u32 YI_SEQUENCE_GetActiveXY(void*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
}  // namespace n00138cd0
namespace dk {
void Sprite::getSeqActiveXYAddOffset(s32& x, s32& y) { using namespace ::n00138cd0; using ::n00138cd0::YI_SEQUENCE_GetActiveXY;
    YI_SEQUENCE_GetActiveXY(reinterpret_cast<u8*>(this) + 24u, &x, &y);
    SpriteLayout* s = reinterpret_cast<SpriteLayout*>(this);
    x += s->offsetX;
    y += s->offsetY;
}
}  // namespace dk

// ---- 00138d30 from src/anon/tiny_wrappers_more.cpp
namespace n00138d30 {
u32 func_00239df0(u32, u32, u32, u32) asm("_Z13func_00239df0jjjj");
u32 func_00138d30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00138d30jjjj");
u32 func_00138d30(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00239df0(((u32)(a0) + 24u), a1, a2, a3);
}
}  // namespace n00138d30

// ---- 00138d48 from src/anon/tiny_wrappers_more.cpp
namespace n00138d48 {
u32 func_00239fd0(u32, u32, u32, u32) asm("_Z13func_00239fd0jjjj");
u32 func_00138d48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00138d48jjjj");
u32 func_00138d48(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00239fd0(((u32)(a0) + 24u), a1, a2, a3);
}
}  // namespace n00138d48

// ---- 00138d60 from src/anon/auto80_199_queue.cpp
namespace n00138d60 {
void func_00138d60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) asm("_Z13func_00138d60jjjjjjj");
void func_00138d60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    dk__Sprite__create(a0, a1, a2, a3, a4, a6);

    *(u32*)(a0 + 408) = a5;
    *(u32*)(a0 + 412) = 0;
    *(u32*)(a0 + 420) = 0x80E5E5E5;
    *(u32*)(a0 + 416) = 0;
    *(u32*)(a0 + 432) = 0;

    s32 v0 = func_0023aa58(a0 + 24);
    *(u32*)(a0 + 428) = 0;

    u32 v1 = 15;
    if (0 < v0) {
        v1 = (u32)v0;
    }

    *(u32*)(a0 + 424) = v1;
    func_001395e8(a0);
    func_00139610(a0);
    func_00139638(a0);
}
}  // namespace n00138d60

// ---- 00138de0 from src/anon/batch_w1622.cpp
namespace n00138de0 {
struct W1622Seq {
    u8 pad0[280];
    f32 r, g, b, a;
    u8 pad128[32];
    s32 x, y;
    void setPos(s32 nx, s32 ny) { x = nx; y = ny; }
};
struct W1622Sprite {
    u32 vt;
    u8 pad4[8];
    u32 flags;
    u8 pad10[8];
    W1622Seq seq;
    u8 pad168[8];
    s32 posX, posY;
    s32 offX, offY;
    u8 pad180[12];
    W1622Sprite* parent;
    W1622Seq* parentSeq;
    u8 pad194;
    u8 clear;
    u8 pad196[2];
    const void* msg;
    s32 msgX, msgY;
    u32 color;
    s32 msgSize;
    s32 msgA;
    s32 msgB;
    void setPos(s32 x, s32 y) { posX = x; posY = y; }
};
s32 W1622_isActive(W1622Sprite*) asm("_Z16u_call4_00139d78jjjj");
s32 W1622_getPlayMode(W1622Seq*) asm("_ZN2YI8SEQUENCE11GetPlayModeEv");
void W1622_getXYAddOff(W1622Sprite*, s32*, s32*) asm("_ZN2dk6Sprite23getSeqActiveXYAddOffsetERiS1_");
s32 W1622_getParamX(W1622Seq*) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 W1622_getParamY(W1622Seq*) asm("_ZN2YI8SEQUENCE9GetParamYEv");
s32 W1622_getParamCr(W1622Seq*) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
u32 W1622_getActiveRGBA(W1622Seq*) asm("_ZN2YI8SEQUENCE13GetActiveRGBAEv");
struct W1622Printer { u8 b[96]; };
void W1622_print(W1622Printer*, s32, s32, u32) asm("_Z21YS__MESSAGEDRAW__drawjjjj");
void YS__MESSAGEDRAW__MESSAGEDRAW(W1622Printer*, s32, const void*, s32, s32) asm("YS__MESSAGEDRAW__MESSAGEDRAW");
void YS__MESSAGEDRAW__set_line_space(W1622Printer*, s32) asm("YS__MESSAGEDRAW__set_line_space");
u32 dk__SpriteMessage__drawMessage(W1622Sprite* s) asm("dk__SpriteMessage__drawMessage");
u32 dk__SpriteMessage__drawMessage(W1622Sprite* s) {
    if ((s->parent && !W1622_isActive(s->parent)) || (s->parentSeq && !W1622_getPlayMode(s->parentSeq))) return 0;
    s32 x = 0, y = 0;
    W1622_getXYAddOff(s, &x, &y);
    if (s->flags & 0x10) {
        x += W1622_getParamX(&s->seq);
        y += W1622_getParamY(&s->seq);
    }
    u32 color = s->color;
    if (s->flags & 4) {
        u32 c = W1622_getActiveRGBA(&s->seq);
        if (s->flags & 8) {
            c &= 0xff000000;
            color &= 0x00ffffff;
            color |= c;
        }
        else color = c;
        W1622Seq* q = &s->seq;
        f32 fr = q->r, fg = q->g, fb = q->b, fa = q->a;
        s32 a = (s32)((f32)(color >> 24) * fa);
        if (a >= 255) a = 255;
        s32 r = (s32)((f32)(color & 0xff) * fr);
        if (r >= 255) r = 255;
        s32 g = (s32)((f32)((color & 0xff00) >> 8) * fg);
        if (g >= 255) g = 255;
        s32 b = (s32)((f32)((color & 0xff0000) >> 16) * fb);
        if (b >= 255) b = 255;
        color = (a << 24) | (b << 16) | (g << 8) | r;
    }
    if (s->msg == 0) return color;
    {
        s32 px = x + s->posX + s->msgX;
        s32 py = y + s->posY + s->msgY;
        W1622Printer pr;
        YS__MESSAGEDRAW__MESSAGEDRAW(&pr, s->msgA, s->msg, s->msgSize, s->msgB);
        YS__MESSAGEDRAW__set_line_space(&pr, W1622_getParamCr(&s->seq));
        W1622_print(&pr, px, py, color);
    }
    return color;
}
}  // namespace n00138de0

// ---- 001390a8 from src/anon/tiny.cpp
namespace n001390a8 {
void dk__Sprite__update(void*) asm("_Z18dk__Sprite__updatePv");
void dk__SpriteMessage__update(BD_VALUE* bd) asm("_Z25dk__SpriteMessage__updateP8BD_VALUE");
void dk__SpriteMessage__update(BD_VALUE* bd) { dk__Sprite__update(bd); }
}  // namespace n001390a8

// ---- 001390c0 from src/anon/batch_w4.cpp
namespace dk {
class SpriteMessage {
public:
    void draw();
};
}  // namespace dk
namespace n001390c0 {
void dk__Sprite__draw(dk::SpriteMessage*) asm("dk__Sprite__draw");
void dk__SpriteMessage__drawMessage(dk::SpriteMessage*) asm("dk__SpriteMessage__drawMessage");
}  // namespace n001390c0
void dk::SpriteMessage::draw() {
    n001390c0::dk__Sprite__draw(this);
    n001390c0::dk__SpriteMessage__drawMessage(this);
}

// ---- 001390e8 gap: empty slot of the vtable at 0x347e10
namespace n001390e8 {
void func_001390e8(u8*) asm("func_001390e8");
void func_001390e8(u8*) {}
}  // namespace n001390e8

// ---- 001390f0 from src/anon/auto80_199_queue.cpp
namespace n001390f0 {
void dk__Sprite3D__update(u32 a0) asm("_Z20dk__Sprite3D__updatej");
void dk__Sprite3D__update(u32 a0) {
    if ((*(u32*)(a0 + 12) & 0x100) != 0) {
        return;
    }

    u32 v0 = func_0013a178(a0 + 416, D_00347f80 + 32);
    *(u32*)(a0 + 368) = *(u32*)(v0 + 0);
    *(u32*)(a0 + 372) = *(u32*)(v0 + 4);
    *(u32*)(a0 + 432) = *(u32*)(v0 + 8);

    ((void (*)(u32))(*(u32*)(*(u32*)a0 + 24)))(a0);
    dk__Sprite__update(a0);
}
}  // namespace n001390f0

// ---- 00139170 from src/anon/tiny_auto80_queue.cpp
namespace n00139170 {
u32 dk__Sprite__draw(...) asm("dk__Sprite__draw");
void func_00139170(u32 a0) asm("_Z13func_00139170j");
void func_00139170(u32 a0) {
    s32 v = *(volatile s32*)((u32)a0 + (s32)(432));
    if (v > 0) {
        if (v <= (s32)0x003d0900) {
            dk__Sprite__draw();
        }
    }
}
}  // namespace n00139170

// ---- 001391a8 from src/anon/batch_w4.cpp
namespace n001391a8 {
void func_001391a8(u8* p, void* src) asm("func_001391a8");
void func_001391a8(u8* p, void* src) {                           
    void* dst = p + 416;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}
}  // namespace n001391a8

