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

// ---- 001374c8 from src/anon/batch_w57.cpp
namespace n001374c8 {
u32 func_0013a7e8(u32) asm("func_0013a7e8");
u32 func_0013d7e0(void) asm("func_0013d7e0");
void func_00138d60(void*, u32, u32, u32, u32, u32, u32) asm("func_00138d60");
void func_001374c8(u8* t, f32 f, u32 a, u32 b, u32 c) asm("func_001374c8");
void func_001374c8(u8* t, f32 f, u32 a, u32 b, u32 c) {
    u32 x = func_0013a7e8(1);
    u32 y = func_0013d7e0();
    func_00138d60(t, 11100, x, y, a, b, 13);
    *(u32*)(t + 424) = 16;
    *(f32*)(t + 436) = f;
    *(u32*)(t + 440) = c;
}
}  // namespace n001374c8

// ---- 00137560 from src/anon/batch_w64.cpp
namespace n00137560 {
void func_00139598(u8*) asm("func_00139598");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
void func_001395a8(u8*) asm("func_001395a8");
void dk__Sprite__update(u8*) asm("dk__Sprite__update");
extern f32 D_00349e14 asm("D_00349e14");
void dk__TREASURE_INFO_BASE__update(u8* p) asm("dk__TREASURE_INFO_BASE__update");
void dk__TREASURE_INFO_BASE__update(u8* p) {
    if (0.0f < *(f32*)(p + 436)) {
        *(f32*)(p + 436) = *(f32*)(p + 436) - D_00349e14;
        func_00139598(p);
        return;
    }
    f32 lim = -20000.0f;
    if (lim < *(f32*)(p + 436)) {
        func_002ba2e8(10, 0);
        *(f32*)(p + 436) = lim;
    }
    func_001395a8(p);
    dk__Sprite__update(p);
}
}  // namespace n00137560

// ---- 001375f0 from src/anon/batch_wlit.cpp
namespace n001375f0 {
void func_001374c8(u8* p, s32 n, u32 a, u32 b, f32 f) asm("func_001374c8");
void func_001375f0(u8* p, u32 a, u32 b) asm("func_001375f0");
void func_001375f0(u8* p, u32 a, u32 b) {
    func_001374c8(p, 79, a, b, 60.0f);
    *(u32*)(p + 1304) = 0;
}
}  // namespace n001375f0

// ---- 00137630 from src/anon/batch_w65.cpp
namespace n00137630 {
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
void func_001b2028(u32) asm("func_001b2028");
void func_001991a8(s32, s32) asm("func_001991a8");
void dk__TREASURE_BOX_INFO__destroy(u8* p) asm("dk__TREASURE_BOX_INFO__destroy");
void dk__TREASURE_BOX_INFO__destroy(u8* p) {
    if (*(u32*)(p + 1304)) {
        if (func_00139d78(p + 448)) func_00139510(p + 448);
        if (func_00139d78(p + 896)) func_00139510(p + 896);
        func_001b2028(*(u32*)(p + 1304));
    }
    func_001991a8(36, 0);
}
}  // namespace n00137630

// ---- 001376b8 from src/anon/batch_wcx2.cpp
namespace n001376b8 {
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
struct VB30 {
    f32 x, y, z, w;
    VB30& operator=(const VB30& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB30 operator-(const VB30& b) const
    {
        VB30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Sub4 { u8 pad[396]; void* owner; s32 f400; };
extern f32 D_00349e14 asm("D_00349e14");
void func_00139598(u8*) asm("func_00139598");
s32 func_001b1fc8(s32) asm("func_001b1fc8");
u32 func_001b1ff0(s32) asm("func_001b1ff0");
u32 func_001b1e70(void) asm("func_001b1e70");
void dk__SpriteImage__create(u8*, s32, u32, s32) asm("dk__SpriteImage__create");
void dk__Sprite__create(Sub4*, s32, u32, u8*, s32, s32) asm("dk__Sprite__create");
void func_00236410(u8*, s32) asm("func_00236410");
void func_00236428(u8*, s32) asm("func_00236428");
void func_002367c8(u8*) asm("func_002367c8");
void func_001396b0(Sub4*) asm("func_001396b0");
void func_0031a260(Sub4*, s32) asm("func_0031a260");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
void func_001395a8(u8*) asm("func_001395a8");
void func_00138840__43679(u8*) asm("dk__Sprite__update");
void dk__TREASURE_BOX_INFO__update(u8* p) asm("dk__TREASURE_BOX_INFO__update");
void dk__TREASURE_BOX_INFO__update(u8* p)
{
    if (0.0f < *(f32*)(p + 436)) {
        *(f32*)(p + 436) -= D_00349e14;
        func_00139598(p);
        return;
    }
    if (*(s32*)(p + 440) != -1 && !*(u32*)(p + 1304)) {
        if (!func_001b1fc8(*(s32*)(p + 440))) {
            func_00139598(p);
            return;
        }
        u8* w = p + 480;
        *(u32*)(p + 1304) = func_001b1ff0(*(s32*)(p + 440));
        u32 h = func_001b1e70();
        dk__SpriteImage__create(p + 448, 11100, *(u32*)(p + 1304), 0);
        dk__Sprite__create((Sub4*)(p + 896), 11100, h, w, 6, 0);
        func_00236410(w, 14080);
        func_00236428(w, 10752);
        func_002367c8(w);
        Sub4* s = (Sub4*)(p + 896);
        s->owner = p;
        func_001396b0(s);
        if (s->owner) {
            s->f400 = 0;
            func_001396b0(s);
            if (s->f400) func_0031a260(s, 0);
        }
    }
    if (-20000.0f < *(f32*)(p + 436)) {
        func_002ba2e8(10, 0);
        *(f32*)(p + 436) = -20000.0f;
    }
    func_001395a8(p);
    func_00138840__43679(p);
}
}  // namespace n001376b8

// ---- 00137840 from src/anon/tiny_auto80_queue.cpp
namespace n00137840 {
void func_001374c8(...) asm("func_001374c8");
u32 func_0023aa98(...) asm("func_0023aa98");
void func_00137840(u32 a0, u32 a1) asm("_Z13func_00137840jj");
void func_00137840(u32 a0, u32 a1) {
    u32 s0 = a0;
    f32 f12 = 0.0f;
    ((void(*)(u32, u32, u32, u32, f32))func_001374c8)(a0, 76, a1, 0xFFFFFFFFu, f12);
    u32 v0 = func_0023aa98(s0 + 24);
    if (v0 == 1) {
        *(u32*)(s0 + 432) = 2;
    }
}
}  // namespace n00137840

// ---- 00137890 from src/anon/batch_w68.cpp
namespace n00137890 {
extern u8* D_00347d5c asm("D_00347d5c");
u32 func_0013a7e8(u32) asm("func_0013a7e8");
void func_00138d60(void*, u32, u32, void*, u32, u32, u32) asm("func_00138d60");
void func_00137890(u8* p, u32 a1, u32 a2, u32 a3) asm("func_00137890");
void func_00137890(u8* p, u32 a1, u32 a2, u32 a3) {
    u8* base = D_00347d5c + 32;
    u32 r = func_0013a7e8(1);
    func_00138d60(p, 11100, r, base, 77, a1, 0);
    *(u32*)(p + 1308) = a3;
    *(u32*)(p + 440) = a2;
    *(u32*)(p + 424) = 16;
    *(u32*)(p + 432) = 2;
    *(u32*)(p + 1304) = 0;
    *(u32*)(p + 436) = 0;
}
}  // namespace n00137890

// ---- 00137930 from src/anon/batch_w66.cpp
namespace n00137930 {
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00139510(u8*) asm("func_00139510");
struct VObj { void (**vt)(VObj*); };
extern VObj* D_00347d5c asm("D_00347d5c");
extern s32 D_00347d58 asm("D_00347d58");
extern u32 D_00347d60 asm("D_00347d60");
void func_001b2028(u32) asm("func_001b2028");
void dk__TREASURE_EVENT_INFO__destroy(u8* p) asm("dk__TREASURE_EVENT_INFO__destroy");
void dk__TREASURE_EVENT_INFO__destroy(u8* p) {
    u8* b = p + 896;
    u8* a = p + 448;
    if (*(u32*)(p + 1304)) {
        if (func_00139d78(a)) func_00139510(a);
        if (func_00139d78(b)) func_00139510(b);
        (*(void (**)(VObj*))((u8*)D_00347d5c->vt + 20))(D_00347d5c);
        func_001b2028(*(u32*)(p + 1304));
    }
    D_00347d58--;
    D_00347d60 = 0;
}
}  // namespace n00137930

// ---- 001379e0 from src/anon/batch_w114.cpp
namespace n001379e0 {
static inline void settle(u8* m) {
    func_001396b0(m);
    if (*(u32*)(m + 396)) {
        *(u32*)(m + 400) = 0;
        func_001396b0(m);
        if (*(u32*)(m + 400)) func_0031a260(m, 0);
    }
}
extern f32 D_00349e14 asm("D_00349e14");
void func_001396b0(u8*) asm("func_001396b0");
void func_0031a260(u8*, s32) asm("func_0031a260");
s32 func_001b1fc8(s32) asm("func_001b1fc8");
u32 func_001b1ff0(s32) asm("func_001b1ff0");
u32 func_001b1e70(void) asm("func_001b1e70");
void dk__SpriteImage__create(u8*, s32, u32, s32) asm("dk__SpriteImage__create");
void dk__Sprite__create(u8*, s32, u32, u8*, s32, s32) asm("dk__Sprite__create");
void func_00236410(u8*, s32) asm("func_00236410");
void func_00236428(u8*, s32) asm("func_00236428");
void func_002367c8(u8*) asm("func_002367c8");
void func_00139598(u8*) asm("func_00139598");
void func_001395a8(u8*) asm("func_001395a8");
void dk__Sprite__update(u8*) asm("dk__Sprite__update");
u8* func_00167f18(s32) asm("func_00167f18");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
void func_00138c10(u8*, u32) asm("func_00138c10");
void dk__TREASURE_EVENT_INFO__update(u8* p) asm("dk__TREASURE_EVENT_INFO__update");
void dk__TREASURE_EVENT_INFO__update(u8* p) asm("dk__TREASURE_EVENT_INFO__update");
void dk__TREASURE_EVENT_INFO__update(u8* p) {
    if (*(s32*)(p + 440) != -1) {
        if (*(u32*)(p + 1304) == 0) {
            if (func_001b1fc8(*(s32*)(p + 440)) == 0) {
                func_00139598(p);
                return;
            }
            u8* m = p + 480;
            *(u32*)(p + 1304) = func_001b1ff0(*(s32*)(p + 440));
            u32 t = func_001b1e70();
            dk__SpriteImage__create(p + 448, 11100, *(u32*)(p + 1304), 0);
            u8* q = p + 896;
            dk__Sprite__create(q, 11100, t, m, 2, 0);
            func_00236410(m, 14080);
            func_00236428(m, 10752);
            func_002367c8(m);
            *(u8**)(q + 396) = p;
            settle(q);
        } else {
            f32 f = *(f32*)(p + 436);
            if (0.0f < f) {
                *(f32*)(p + 436) = f - D_00349e14;
            } else {
                u8* v = func_00167f18(0);
                if (*(s32*)(p + 388) != 78 && (*(u64*)(v + 8) & 0x40c)) {
                    func_002ba2e8(24, 0);
                    func_001395a8(p);
                    func_00138c10(p, 78);
                    func_00138c10(p + 896, 3);
                }
            }
        }
    }
    func_001395a8(p);
    dk__Sprite__update(p);
}
}  // namespace n001379e0

// ---- 00137b88 gap: draw slot of the vtable at 0x347d88
namespace n00137b88 {
struct Printer137 { u8 b[96]; };
void dk__Sprite__draw(u8*) asm("dk__Sprite__draw");
u32 dk__SpriteMessage__drawMessage(u8*) asm("dk__SpriteMessage__drawMessage");
void getSeqActiveXY137(u8*, s32*, s32*) asm("_ZN2dk6Sprite14getSeqActiveXYERiS1_");
s32 GetParamX137(u8*) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 GetParamY137(u8*) asm("_ZN2YI8SEQUENCE9GetParamYEv");
s32 GetParamEx137(u8*) asm("_ZN2YI8SEQUENCE10GetParamExEv");
void func_001a98e8_137(Printer137*, s32, u32, s32, s32) asm("YS__MESSAGEDRAW__MESSAGEDRAW");
void print137(Printer137*, s32, s32, u32) asm("_Z21YS__MESSAGEDRAW__drawjjjj");
void func_00137b88(u8* p) asm("func_00137b88");
void func_00137b88(u8* p) {
    u8* seq = p + 24;
    dk__Sprite__draw(p);
    u32 color = dk__SpriteMessage__drawMessage(p);
    s32 x = 0, y = 0;
    getSeqActiveXY137(p, &x, &y);
    x += GetParamX137(seq);
    y += GetParamY137(seq);
    y += GetParamEx137(seq);
    Printer137 pr;
    func_001a98e8_137(&pr, 0, *(u32*)(p + 1308), 16, 2);
    print137(&pr, x, y, color);
}
}  // namespace n00137b88

// ---- 00137c50 from src/anon/batch_w14.cpp
namespace n00137c50 {
void func_001391c8(void*, s32, s32) asm("func_001391c8");
void dk__TREASURE_INFO__create(u8* p) asm("dk__TREASURE_INFO__create");
void dk__TREASURE_INFO__create(u8* p) {
    *(s32*)(p + 10696) = 0;
    *(s32*)(p + 32) = 1;
    *(s32*)(p + 48) = 0;
    *(s32*)(p + 52) = 0;
    *(s32*)(p + 10692) = 0;
    *(s32*)(p + 10688) = 1;
    func_001391c8(p, 11100, 0);
}
}  // namespace n00137c50

// ---- 00137c88 from src/anon/sweep_00137c88_nsa.cpp
namespace n00137c88 {
struct W1622Base0 { virtual void w1622k(); u32 a[3]; };
struct W1622Base : W1622Base0 { u32 x, y; };
struct W1622A : W1622Base {
    u8 sub[344];
    u32 f170[4];
    f32 f180;
    u32 f184[4];
    u8 p, q;
    W1622A& operator=(const W1622A&) asm("func_0031a1a0");
};
struct W1622Sub : W1622Base0 { u32 x, y; } __attribute__((aligned(8)));
struct W1622Blk { u32 vt; u8 body[412]; W1622Blk& operator=(const W1622Blk&) asm("func_0031a068"); } __attribute__((aligned(16)));
struct W1622Req0 : W1622A {
    u32 f198, f19c, f1a0, f1a4, f1a8, f1ac, f1b0;
};
struct W1622Req : W1622Req0 {
    f32 rate;
    u32 f1b8;
};
struct W1622Item1Base : W1622Req {
    W1622Sub b;
    W1622Blk blk;
    W1622A a2;
    u32 f518;
};
struct W1622Item1 : W1622Item1Base {
    u32 f520 __attribute__((aligned(8)));
    u32 f524;
};
struct W1622Item2 : W1622Req {
    u32 tail[8];
};
template <class T, int N> struct W1622Ring {
    s32 head;
    s32 tail;
    T item[N];
    bool empty() { return tail == head; }
    T& front() { return item[tail]; }
    T& pop() { T& r = item[tail]; tail = (tail + 1) % N; return r; }
};
struct W1622Flags {
    u32 bits;
    bool busy() { return bits & 1; }
    bool more() { u32 m = bits & 2; return m != 0; }
    void setBusy() { bits |= 1; }
    void clearBusy() { bits &= ~1; }
    void setMore(bool b) { if (b) bits |= 2; else bits &= ~2; }
};
struct W1622Mgr {
    void* vt;
    u8 pad4[28];
    W1622Flags f1;
    u8 pad24[12];
    W1622Ring<W1622Item1, 8> q1;
    W1622Flags f2;
    W1622Ring<W1622Item2, 16> q2;
};
void func_001375f0(W1622Item1*, u32, u32) asm("func_001375f0");
void func_00137840(W1622Item2*, u32*) asm("func_00137840");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00137c88(W1622Mgr* m) asm("func_00137c88");
void func_00137c88(W1622Mgr* m) {
    if (!m->q1.empty()) {
        W1622Item1* cur = &m->q1.front();
        if (m->f1.busy() == true) {
            func_001375f0(cur, cur->f520, cur->f524);
            m->f1.clearBusy();
            if (m->f1.more() == true) cur->rate = 0;
        } else if (!func_00139d78(cur)) {
            *cur = m->q1.pop();
            m->f1.setBusy();
            m->f1.setMore(!m->q1.empty());
        }
    }
    if (!m->q2.empty()) {
        W1622Item2* cur = &m->q2.front();
        if (m->f2.busy() == true) {
            func_00137840(cur, cur->tail);
            m->f2.clearBusy();
            if (m->f2.more() == true) cur->rate = 0;
        } else if (!func_00139d78(cur)) {
            *cur = m->q2.pop();
            m->f2.setBusy();
            m->f2.setMore(!m->q2.empty());
        }
    }
}
}  // namespace n00137c88

// ---- 00137fb8 from src/anon/batch_w94.cpp
namespace n00137fb8 {
void func_0031a830(void*) asm("func_0031a830");
void func_0031a838(void*) asm("func_0031a838");
void func_0031a350(void*) asm("func_0031a350");
void func_00239700(void*) asm("func_00239700");
void dk__TREASURE_INFO__create(void*) asm("dk__TREASURE_INFO__create");
extern u8* D_00347f80 asm("D_00347f80");
extern u32 D_00347d70[] asm("D_00347d70");
extern u32 D_00347f98[] asm("D_00347f98");
extern u32 D_00347e60[] asm("D_00347e60");
extern u32 D_00347db0[] asm("D_00347db0");
extern u8* volatile D_00347d64 asm("D_00347d64");
typedef u8* (*AllocFn)(void*, u32, u32);
void u_call0_00137fb8(void) asm("_Z16u_call0_00137fb8v");
void u_call0_00137fb8(void) {
    void** a = *(void***)(D_00347f80 + 20);
    u8* p = (*(AllocFn*)*a)(a, 18320, 0);
    *(u32*)(p + 12) = 0;
    *(u32**)p = D_00347d70;
    u32* r = (u32*)(p + 48);
    func_0031a830(p + 32);
    u8* q = p + 64;
    for (s32 i = 7; i != -1; i--) {
        func_0031a350(q);
        q += 1328;
    }
    r[0] = 0;
    r[1] = 0;
    u8** r2 = (u8**)(p + 10692);
    func_0031a830(p + 10688);
    q = p + 10700;
    for (s32 i = 15; i != -1; i--) {
        *(u32**)q = D_00347f98;
        func_0031a838(q + 12);
        *(u32**)q = D_00347e60;
        func_00239700(q + 24);
        *(u32*)(q + 408) = 0;
        *(u32**)q = D_00347db0;
        q += 476;
    }
    r2[0] = 0;
    r2[1] = 0;
    D_00347d64 = p;
    dk__TREASURE_INFO__create(D_00347d64);
}
}  // namespace n00137fb8

// ---- 001380e8 from src/anon/tiny_auto80_queue.cpp
namespace n001380e8 {
void func_001380e8(void) asm("_Z13func_001380e8v");
void func_001380e8(void) {
    u32 s0 = (u32)(0x0034u << 16);
    u32 t7 = *(u32*)((u32)s0 + (s32)(32100));
    if (t7 != 0u) {
        u32 t6 = *(u32*)((u32)t7 + (s32)(0));
        u32 fp = *(u32*)((u32)t6 + (s32)(16));
        ((void(*)(u32))fp)(t7);
        *(u32*)((u32)s0 + (s32)(32100)) = 0u;
    }
}
}  // namespace n001380e8

// ---- 00138128 from src/anon/tiny.cpp
namespace n00138128 {
void func_00139858(s32) asm("_Z13func_00139858i");
void func_00138128(BD_VALUE* bd) asm("_Z13func_00138128P8BD_VALUE");
void func_00138128(BD_VALUE* bd) { func_00139858(13); }
}  // namespace n00138128

// ---- 00138140 from src/anon/batch_w28.cpp
namespace n00138140 {
void func_001398d0(u32) asm("func_001398d0");
void func_001397d8(u32) asm("func_001397d8");
struct G347 { u8 pad[0x20]; u32 f20; u8 p2[0xc]; u32 f30; u32 f34; u8 p3[0x29c0 - 0x38]; u32 f29c0; u32 f29c4; u32 f29c8; };
union G347Ptr { G347* p; u32 w; };
extern G347Ptr D_00347d64 asm("D_00347d64");
void dk__TREASURE_INFO__off(void) asm("dk__TREASURE_INFO__off");
void dk__TREASURE_INFO__off(void) {
    func_001398d0(13);
    func_001397d8(13);
    G347* p = D_00347d64.p;
    p->f20 = 1;
    p->f30 = 0;
    p->f34 = 0;
    G347* q = D_00347d64.p;
    q->f29c0 = 1;
    q->f29c4 = 0;
    q->f29c8 = 0;
}
}  // namespace n00138140

// ---- 00138190 from src/anon/perm_00138190.cpp
namespace n00138190 {
typedef unsigned char u8;
typedef signed int s32;
typedef struct Item
{
  u8 pad[0x520];
  s32 a;
  s32 b;
  u8 p2[8];
} Item;
typedef struct Ring
{
  s32 head;
  s32 tail;
  u8 pad[8];
  Item e[8];
} Ring;
typedef struct Q
{
  u8 pad[0x30];
  Ring r;
} Q;
extern Q *D_00347d64 asm("D_00347d64");
inline int inline_fn(s32 arg0, Ring *arg1)
{
  return ((arg0 - arg1->tail) + 8) % 8;
}
void func_00138190(s32 a, s32 b) asm("func_00138190");
void func_00138190(s32 a, s32 b)
{
  Q *q = D_00347d64;
  Ring *r = &q->r;
  s32 h = q->r.head;
  s32 n;
  if (inline_fn(h, r) < 7)
  {
    Item *it;
    q->r.head = (h + 1) % 8;
    it = &r->e[h];
    it->a = a;
    it->b = b;
  }
}
}  // namespace n00138190

// ---- 00138210 from src/anon/batch_w233.cpp
namespace n00138210 {
extern u8* D_00347d64 asm("D_00347d64");
void func_00192c90(u32, void*) asm("func_00192c90");
void func_00192b30(u32) asm("func_00192b30");
void dk__TREASURE_INFO__openPrizeInfo(u32 a) asm("dk__TREASURE_INFO__openPrizeInfo");
void dk__TREASURE_INFO__openPrizeInfo(u32 a) {
    u8* q = D_00347d64 + 10692;
    s32 h = *(s32*)q;
    s32 d = h - *(s32*)(q + 4);
    s32 r = (d + 16) % 16;
    if (r < 15) {
        *(s32*)q = (h + 1) % 16;
        func_00192c90(a, q + h * 476 + 452);
        func_00192b30(a);
    }
}
}  // namespace n00138210

// ---- 001382b8 from src/harata/libdk/treasure_info.cpp
namespace n001382b8 {
extern u32 D_00347d58 asm("D_00347d58");
u32 Tz__CampMenu__Start(u32, u32) asm("Tz__CampMenu__Start");
}  // namespace n001382b8
namespace dk {
u32 TREASURE_INFO::openEventInfo(s32 a0) { using namespace ::n001382b8; using ::n001382b8::D_00347d58; using ::n001382b8::Tz__CampMenu__Start;
    u32 r4 = (u32)a0, r5 = (u32)-1;
    *(u32*)((u32)&D_00347d58 + (s32)(0)) = r4;
    r4 = 7u;
    return Tz__CampMenu__Start(r4, r5);
}
}  // namespace dk

// ---- 001382e0 from src/anon/batch_w99.cpp
namespace n001382e0 {
struct Alloc1382 { struct VT { u8* (*alloc)(void*, u32, u32); }* vt; };
struct Mgr1382 { u8 pad[20]; Alloc1382* heap; };
extern Mgr1382* D_00347f80 asm("D_00347f80");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347d90[] asm("D_00347d90");
extern u8* D_00347d5c asm("D_00347d5c");
extern u8* D_00347d60 asm("D_00347d60");
u8** func_001a84b0(void) asm("func_001a84b0");
void func_001b1e80(u8*) asm("func_001b1e80");
void func_002361a0(u8*) asm("func_002361a0");
u32 func_0013a7d0(s32) asm("func_0013a7d0");
void dk__SpriteImage__create(u8*, s32, u32, s32) asm("dk__SpriteImage__create");
void func_0031a838(u8*) asm("func_0031a838");
void func_00239700(u8*) asm("func_00239700");
void func_00137890(u8*, u8*, u8*, u8*) asm("func_00137890");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");

static inline u8* Alloc1382n(u32 n) { Alloc1382* h = D_00347f80->heap; return h->vt->alloc(h, n, 0); }

void dk__TREASURE_INFO__createEventInfo(void) asm("dk__TREASURE_INFO__createEventInfo");
void dk__TREASURE_INFO__createEventInfo(void)
{
    u8** cfg = func_001a84b0();
    func_001b1e80(cfg[2]);
    u8* a = Alloc1382n(448);
    *(u8**)a = D_00347f98;
    *(u32*)(a + 12) = 0;
    *(u8**)a = D_00347e80;
    func_002361a0(a + 32);
    D_00347d5c = a;
    dk__SpriteImage__create(D_00347d5c, 6000, func_0013a7d0(1), 0);
    u8* b = Alloc1382n(1312);
    *(u8**)b = D_00347f98;
    func_0031a838(b + 12);
    *(u8**)b = D_00347e60;
    func_00239700(b + 24);
    *(u8**)(b + 448) = D_00347f98;
    *(u32*)(b + 408) = 0;
    *(u8**)b = D_00347d90;
    func_0031a838(b + 460);
    *(u8**)(b + 448) = D_00347e80;
    func_002361a0(b + 480);
    *(u8**)(b + 896) = D_00347f98;
    func_0031a838(b + 908);
    *(u8**)(b + 896) = D_00347e60;
    func_00239700(b + 920);
    D_00347d60 = b;
    func_00137890(b, cfg[0], cfg[2], cfg[1]);
    func_002ba2e8(10, 0);
}
}  // namespace n001382e0

// ---- 00138440 from src/harata/libdk/treasure_info.cpp
namespace n00138440 {
extern u8 D_00347d60 asm("D_00347d60");
extern "C" u32 dk_treasure_info_open_event_info(u32) asm("_Z16u_call4_00139d78jjjj");
}  // namespace n00138440
namespace dk {
u32 TREASURE_INFO::isEventInfoExist() { using namespace ::n00138440; using ::n00138440::D_00347d60; using ::n00138440::dk_treasure_info_open_event_info;
    u32 r14 = *(u32*)((u32)&D_00347d60 + 0);
    u32 r2 = 0u;
    if (r14 != 0u) {
        r2 = dk_treasure_info_open_event_info(r14);
    }
    return r2;
}
}  // namespace dk

// ---- 00138470 from src/harata/libdk/treasure_info.cpp
namespace n00138470 {
extern u32 D_00347d58 asm("D_00347d58");
}  // namespace n00138470
namespace dk {
u32 TREASURE_INFO::isEventInfoAllEnd() { using namespace ::n00138470; using ::n00138470::D_00347d58;
    u32 v = D_00347d58;
    return (v < 1u);
}
}  // namespace dk

