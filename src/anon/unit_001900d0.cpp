#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../yasui/libys/target.hpp"

// YS::TARGET (0x1900d0-0x191758): target pool, target queries and lock-on search. Linked unit;
// .rodata at 0x36cd18. The pool objects at 0x1c60d10 stay extern; the static init (0x191658) and its
// _GLOBAL__I_ stub (0x191738) are plain functions.

// ---- 001900d0 from src/anon/batch_w1752.cpp
namespace n001900d0 {
struct W1752Tbl { u8 pad[0xa00]; s32 arr[128]; };
extern W1752Tbl D_01c60d50 asm("D_01c60d50");
extern s32 D_01c61950 asm("D_01c61950");
extern u8 D_01c60d10[] asm("D_01c60d10");
void w1752_wt_001cd660(void*) asm("_Z16wtarget_001cd660jjjj");
void func_001900d0(void) asm("func_001900d0");
void func_001900d0(void) {
    s32 i;
    for (i = 0; i < 128; i++) D_01c60d50.arr[i] = i;
    D_01c61950 = 128;
    w1752_wt_001cd660(D_01c60d10);
}
}  // namespace n001900d0

// ---- 00190128 YS::TARGET::TARGET() (one copy in retail: written as a plain function)
namespace n00190128 {
void target_ctor(YS::TARGET* t) asm("_ZN2YS6TARGETC1Ev");
void target_ctor(YS::TARGET* t) {
    t->m_4 = 0;
    t->m_id = -1;
    t->m_8 = 0;
    t->m_obj = 0;
}
}  // namespace n00190128

// ---- 00190140 from src/anon/batch_w20.cpp
namespace n00190140 {
u32 target_is_exist(const u8* t) asm("_ZNK2YS6TARGET8is_existEv");
u32 func_00190208(const u8*, u32) asm("func_00190208");
u32 target_is_exist(const u8* t) {
    u32 r = 0;
    if (*(u32*)(t + 8) != 0 || func_00190208(t, 0)) r = 1;
    return r;
}
}  // namespace n00190140

// ---- 00190180 YS::TARGET::is_valid
namespace YS {
extern "C" u32 YS__OBJ__is_exist(u32);
u32 TARGET::is_valid() const {
    register u32 s0 = 0u;
    if (*(u32*)((u32)this + (s32)(8)) != 0u) goto Lset;
    if (YS__OBJ__is_exist(*(u32*)((u32)this + (s32)(0))) == 0u) goto Lret;
Lset:
    s0 = 1u;
Lret:
    return s0;
}
}  // namespace YS

// ---- 001901c0 from src/anon/tiny_auto80_queue.cpp
namespace n001901c0 {
u32 func_00190140(...) asm("func_00190140");
u32 YS__OBJ__can_lockon(...) asm("YS__OBJ__can_lockon");
u32 func_001901c0(u32 a0) asm("_Z13func_001901c0j");
u32 func_001901c0(u32 a0) {
    u32 s0 = a0;
    u32 s1 = 0u;
    if (func_00190140(a0) != 0u) {
        u32 v0 = YS__OBJ__can_lockon(*(u32*)((u32)s0 + (s32)(0)));
        s1 = (u32)(0u < v0);
    }
    return s1;
}
}  // namespace n001901c0

// ---- 00190208 from src/anon/auto80_199_queue.cpp
namespace n00190208 {
u32 func_0016bba8(u8* a0, u32 a1, u32 a2) asm("func_0016bba8");
u32 func_00190208(u32 a0, u32 a1) asm("_Z13func_00190208jj");
u32 func_00190208(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1;
    u32 s2;
    if (*(u32*)(s0 + 8) != 0) {
        s2 = 0;
        goto out;
    }

    s1 = a1 & 0xff;
    s2 = 0;
    if (YS__OBJ__is_exist(*(u32*)s0) == 0) {
        goto out;
    }

    u32 a2v;
    if (s1 != 0) {
        a2v = *(u32*)(s0 + 4);
    } else {
        if (YS__OBJ__is_enable_collision(*(u32*)s0, *(u32*)(s0 + 4)) == 0) {
            goto out;
        }
        a2v = *(u32*)(s0 + 4);
    }

    s2 = func_0016bc20(*(u32*)s0, 3, a2v);
    if (s2 == 0) {
        s2 = func_0016bba8(*(u32*)s0, 3, 0);
    }

out:
    return s2;
}
}  // namespace n00190208

// ---- 001902a8 from src/anon/batch_w82.cpp
namespace n001902a8 {
struct Vec82 {
    f32 x, y, z, w;
    Vec82& operator=(const Vec82& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct V82z { f32 v[4]; } __attribute__((aligned(16)));
extern const f32 D_0036cd18 asm("D_0036cd18") = 1.0f;
void func_0018a958(u8*, u32, f32, f32) asm("func_0018a958");
s32 YS__OBJ__is_exist(u32) asm("YS__OBJ__is_exist");
u32 func_00190208(u8*, u32) asm("func_00190208");
void YS__COLLISION__set(u8*, u32, u32) asm("YS__COLLISION__set");
Vec82* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
void YS__TARGET__make_collision(u8* a0, u8* a1) asm("YS__TARGET__make_collision");
void YS__TARGET__make_collision(u8* a0, u8* a1)
{
    u8* o = *(u8**)(a0 + 8);
    if (o) {
        func_0018a958(a1, 0, *(f32*)(o + 256), *(f32*)(o + 260));
        *(Vec82*)(a1 + 16) = *(Vec82*)(*(u8**)(a0 + 8) + 224);
    } else if (YS__OBJ__is_exist(*(u32*)a0)) {
        u32 v = func_00190208(a0, 1);
        if (v) YS__COLLISION__set(a1, *(u32*)a0, v);
        else *(Vec82*)(a1 + 16) = *YS__OBJ__get_pos(*(u32*)a0);                          
    } else {
                                          
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(a1 + 16) : "memory");
    }
    {
                                                                                            
                                                                                         
        const f32* k;
        asm("" : "=r"(k) : "0"(&D_0036cd18));
        *(f32*)(a1 + 28) = *k;
    }
}
}  // namespace n001902a8

// ---- 00190388 from src/anon/batch_w59.cpp
namespace n00190388 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4c {
    f32 x, y, z, w;
    Vec4c() {}
    Vec4c(const Vec4c& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Buf190 { u32 a, b, c, d; Vec4c v; };
void YS__TARGET__make_collision(u32, Buf190*) asm("YS__TARGET__make_collision");
Vec4c func_00190388(u32 a) asm("func_00190388");
Vec4c func_00190388(u32 a) {                  
    Buf190 t;
    t.d = 0;
    YS__TARGET__make_collision(a, &t);
    return t.v;
}
}  // namespace n00190388

// ---- 001903d0 from src/anon/batch_w83.cpp
namespace n001903d0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
void func_0018a958(void*, s32, f32, f32) asm("func_0018a958");
s32 YS__OBJ__is_exist(void*) asm("YS__OBJ__is_exist");
void* func_0016bc20b(void*, s32, void*) asm("func_0016bc20");
void func_0018a818b(void*, void*, void*) asm("YS__COLLISION__set");
void YS__TARGET__make_collision(void*, void*) asm("YS__TARGET__make_collision");
void func_001903d0(void** p, u8* out) asm("func_001903d0");
void func_001903d0(void** p, u8* out) {
    u8* o = (u8*)p[2];
    if (o) {
        func_0018a958(out, 0, *(f32*)(o + 256), *(f32*)(o + 260));
        *(QWord*)(out + 16) = *(QWord*)((u8*)p[2] + 224);
    } else if (YS__OBJ__is_exist(p[0])) {
        void* v = func_0016bc20b(p[0], 7, p[1]);
        if (v) func_0018a818b(out, p[0], v);
        else YS__TARGET__make_collision(p, out);
    } else {
                             
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(out + 16) : "memory");
    }
    *(f32*)(out + 28) = 1.0f;
}
}  // namespace n001903d0

// ---- 001904a8 from src/anon/batch_w60.cpp
namespace n001904a8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
void func_001903d0(void*, void*) asm("func_001903d0");
struct Out1904 { u32 a[3]; u32 z; QWord q; };
QWord func_001904a8(void* x) asm("func_001904a8");
QWord func_001904a8(void* x) {
    Out1904 l;
    l.z = 0;
    func_001903d0(x, &l);
    return l.q;
}
}  // namespace n001904a8

// ---- 001904f0 from src/anon/batch_w225.cpp
namespace n001904f0 {
void YS__OBJ__is_exist(u32) asm("YS__OBJ__is_exist");
u32 func_0016bc20(u32, u32, u32) asm("func_0016bc20");
void YS__COLLISION__set(void*, void*, u32) asm("YS__COLLISION__set");
void YS__TARGET__make_collision(void*, void*) asm("YS__TARGET__make_collision");
void YS__TARGET__make_talk_camera_collision(u32* a, u8* b) asm("YS__TARGET__make_talk_camera_collision");
void YS__TARGET__make_talk_camera_collision(u32* a, u8* b) {
    YS__OBJ__is_exist(a[0]);
    u32 r = func_0016bc20(a[0], 19, a[1]);
    if (r) {
        YS__COLLISION__set(b, (void*)a[0], r);
    } else {
        YS__TARGET__make_collision(a, b);
    }
    *(f32*)(b + 28) = 1.0f;
}
}  // namespace n001904f0

// ---- 00190570 from src/anon/batch_w254.cpp
namespace n00190570 {
struct W254PE { s32 key; u8 pad[16]; };
struct W254Pool { W254PE e[128]; s32 idx[128]; s32 count; };
extern W254Pool D_01c60d50 asm("D_01c60d50");
u8* func_00186078(u8*) asm("func_00186078");
static inline __attribute__((always_inline)) W254PE* w254_next(W254PE* prev) {
    W254PE* cur = D_01c60d50.e;
    if (prev) cur = prev + 1;
    while (cur < &D_01c60d50.e[128]) {
        s32 i = cur - D_01c60d50.e;
        s32 j;
        for (j = 0; j < D_01c60d50.count; j++) {
            if (D_01c60d50.idx[j] == i) {
                cur++;
                break;
            }
        }
        if (j == D_01c60d50.count) return cur;
    }
    return 0;
}
void func_00190570(s32 a0, s32 a1) asm("func_00190570");
void func_00190570(s32 a0, s32 a1) {
    u8* p = 0;
    W254PE* e;
    while ((p = func_00186078(p)) != 0) {
        if (*(s32*)(p + 2548) == a0) *(s32*)(p + 2548) = a1;
    }
    for (e = 0; (e = w254_next(e)) != 0; ) {
        if (e->key == a0) e->key = a1;
    }
}
}  // namespace n00190570

// ---- 00190680 from src/anon/tiny_auto80_queue.cpp
namespace n00190680 {
u32 func_00190680(u32 a0, u32 a1) asm("_Z13func_00190680jj");
u32 func_00190680(u32 a0, u32 a1) {
    u32 t6 = *(u32*)((u32)a0 + (s32)(8));
    if (t6 != 0u) {
        u32 t7 = *(u32*)((u32)a1 + (s32)(8));
        return (u32)((t6 ^ t7) < 1u);
    }
    t6 = *(u32*)((u32)a0 + (s32)(0));
    if (t6 != *(u32*)((u32)a1 + (s32)(0))) return 0u;
    {
        u32 t7 = *(u32*)((u32)a0 + (s32)(4));
        u32 t6b = *(u32*)((u32)a1 + (s32)(4));
        t7 = (u32)(t7 ^ t6b);
        return (u32)(t7 < 1u);
    }
}
}  // namespace n00190680

// ---- 001906c0 from src/anon/tiny_auto80_queue.cpp
namespace n001906c0 {
u32 func_00190208(...) asm("func_00190208");
u32 func_001906c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001906c0jjjjjjjj");
u32 func_001906c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r5 = 0u;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00190208)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = (u32)(*(u8*)((u32)r2 + (s32)(1)));
        r15 = ((u32)0u < (u32)r15);
    }
    r2 = r15;
    return r2;
}
}  // namespace n001906c0

// ---- 001906f0 from src/anon/batch_w21.cpp
namespace n001906f0 {
struct u128 { u32 w[4]; } __attribute__((aligned(16)));
void YS__TARGET__make_collision(void*, void*) asm("YS__TARGET__make_collision");
void func_0018a970(void*, void*) asm("func_0018a970");
void YS__TARGET__get_dist(void* a, u128* v) asm("YS__TARGET__get_dist");
void YS__TARGET__get_dist(void* a, u128* v) {
    u32 buf[8];
    u128 t;
    buf[3] = 0;
    YS__TARGET__make_collision(a, buf);
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(v) : "$8", "memory");
    func_0018a970(buf, &t);
}
}  // namespace n001906f0

// ---- 00190730 from src/anon/batch_w1784.cpp
namespace n00190730 {
struct W1784It { u8 b0; u8 b1; u8 f : 1; u8 : 7; bool ok() { return !f; } };
struct W1784Iter { void* p; u32 type; };
void* YS__OBJ__Each(void*) asm("YS__OBJ__Each");
s32 YS__OBJ__can_lockon(void*) asm("YS__OBJ__can_lockon");
W1784It* func_0016bba8(void*, s32, W1784It*) asm("func_0016bba8");
W1784It* YS__TARGET__each(W1784Iter* it, W1784It* cur) asm("YS__TARGET__each");
W1784It* YS__TARGET__each(W1784Iter* it, W1784It* cur) {
    if (it->p == 0) {
        cur = 0;
        it->p = YS__OBJ__Each(0);
    }
    for (; it->p; cur = 0, it->p = YS__OBJ__Each(it->p)) {
        if (!YS__OBJ__can_lockon(it->p)) continue;
        while ((cur = func_0016bba8(it->p, 3, cur)) != 0) {
            if (cur->ok()) { it->type = cur->b0; return cur; }
        }
    }
    return 0;
}
}  // namespace n00190730

// ---- 001907e0 from src/anon/batch_w63.cpp
namespace n001907e0 {
struct TGT { u32 w[5]; };
struct TPool { TGT items[128]; s32 freel[128]; s32 count; };
extern TPool D_01c60d50 asm("D_01c60d50");
TGT* tgt_dup(TGT*) asm("_ZN2YS6TARGET3dupEv");
TGT* tgt_dup(TGT* self) {
    s32 n = --D_01c60d50.count;
    TGT* t = &D_01c60d50.items[D_01c60d50.freel[n]];
    *t = *self;
    return t;
}
}  // namespace n001907e0

// ---- 00190840 from src/anon/auto200_999.cpp
namespace n00190840 {
extern u8 D_01c60d50 asm("D_01c60d50");
void YS_TARGET_free(u32 a0) asm("_ZN2YS6TARGET4freeEv");
void YS_TARGET_free(u32 a0) {
    register u32 base asm("$12") = (u32)&D_01c60d50;
    register u32 magic asm("$13") = 0xcccccccd;
    a0 -= base;
    asm volatile("" : "+r"(a0), "+r"(base));
    register u32 count asm("$15") = *(u32 *)(base + 3072);
    asm volatile("" : "+r"(count), "+r"(a0));
    a0 = (s32)a0 >> 2;
    a0 *= magic;
    asm volatile("" : "+r"(a0), "+r"(count));
    register u32 off asm("$14") = count << 2;
    count += 1;
    off += base;
    *(u32 *)(base + 3072) = count;
    *(u32 *)(off + 2560) = a0;
}
}  // namespace n00190840

// ---- 00190878 from src/anon/tiny_auto80_solver.cpp
namespace n00190878 {
void func_00190128(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00190128jjjjjjjj");
u32 func_00190878(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00190878jjjjjjjj");
u32 func_00190878(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00190878jjjjjjjj");
u32 func_00190878(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16, r17, r18;
    r16 = r4;
    r17 = r6;
    r18 = r5;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00190128)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(0)) = r18;
    *(volatile u32*)((u32)r16 + (s32)(4)) = r17;
    return r2;
}
}  // namespace n00190878

// ---- 001908c0 from src/anon/tiny_auto80_solver.cpp
namespace n001908c0 {
void func_00190128(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00190128jjjjjjjj");
u32 func_001908c0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001908c0jjjjjjjj");
u32 func_001908c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001908c0jjjjjjjj");
u32 func_001908c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16, r17, r18;
    r16 = r4;
    r17 = r6;
    r18 = r5;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00190128)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(8)) = r18;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r17;
    return r2;
}
}  // namespace n001908c0

// ---- 00190908 from src/anon/tiny_wrappers_more.cpp
namespace n00190908 {
u32 func_001908c0(u32, u32, u32, u32) asm("_Z13func_001908c0jjjj");
u32 func_00190908(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00190908jjjj");
u32 func_00190908(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001908c0(a0, a1, ((u32)(*(u32*)((u32)(a1) + 12u))), a3);
}
}  // namespace n00190908

// ---- 00190920 from src/anon/batch_w1817.cpp
namespace n00190920 {
void func_00190a28(void*, void*) asm("func_00190a28");
void func_00190a80(void*, void*) asm("func_00190a80");
void func_00190b30(void*, void*) asm("func_00190b30");
void func_00191218(void*, void*, f32) asm("func_00191218");
void YS__TARGET__search_auto_lockon(void*, void*, f32) asm("YS__TARGET__search_auto_lockon");
void w920_set_obj(void*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
f32 w920_lockon(void*) asm("_ZN2YS6STATUS14GetLockOnRatioEv");
extern void* D_0034e948 asm("D_0034e948");
void wtarget_00190920(u8* self, u32 kind, u8* obj, u32 a3) asm("_Z16wtarget_00190920jjjj");
void wtarget_00190920(u8* self, u32 kind, u8* obj, u32 a3) {
    switch (kind) {
    case 0: func_00190a28(self, obj); break;
    case 1: func_00190a80(self, obj); break;
    case 2: w920_set_obj(self, D_0034e948, 0); break;
    case 3: func_00191218(self, obj, 0.0f); break;
    case 4: func_00190b30(self, obj); break;
    case 5: func_00191218(self, obj, 10000.0f); break;
    case 6: {
        u8* t = *(u8**)(obj + 304);
        if (t) {
            YS__TARGET__search_auto_lockon(self, obj, *(f32*)(t + 92) * w920_lockon(self));
        }
        break;
    }
    }
    *(u32*)(self + 12) = kind;
}
}  // namespace n00190920

// ---- 00190a28 from src/anon/batch_w26.cpp
namespace n00190a28 {
void* func_001cd7a8(void*) asm("func_001cd7a8");
void target_set_obj(void*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
extern u8 D_01c60d10[] asm("D_01c60d10");
extern void* D_0034e948 asm("D_0034e948");
void func_00190a28(void* t, u8* o) asm("func_00190a28");
void func_00190a28(void* t, u8* o) {
    void* v = 0;
    if (!(*(u32*)(o + 264) & 0x800)) v = func_001cd7a8(D_01c60d10);
    if (!v) v = D_0034e948;
    target_set_obj(t, v, 0);
}
}  // namespace n00190a28

// ---- 00190a80 from src/anon/batch_w1786.cpp
namespace n00190a80 {
struct W1786Tg;
struct W1786Ob2 { u8 pad[0x7f8]; u32 f7f8; };
struct W1786Ob { u8 pad[0x108]; u32 f108; u8 pad2[0xaec - 0x10c]; W1786Ob2* faec; };
W1786Ob2* func_001cd7a8(void*) asm("func_001cd7a8");
s32 func_0016a090(W1786Ob*) asm("func_0016a090");
s32 W1786_ctarget(W1786Ob2*) asm("_Z17YS__OBJ__is_existjjjj");
void W1786_set_obj(W1786Tg*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
extern u8 D_01c60d10 asm("D_01c60d10");
extern W1786Ob2* D_0034e948 asm("D_0034e948");
void func_00190a80(W1786Tg* t, W1786Ob* o) asm("func_00190a80");
void func_00190a80(W1786Tg* t, W1786Ob* o) {
    W1786Ob2* r = 0;
    u32 fl = o->f108;
    u32 m2 = fl & 0x800;
    u32 m1 = fl & 0x1000;
    if (!m2 && !m1) r = func_001cd7a8(&D_01c60d10);
    if (!r) {
        if (func_0016a090(o) != 1 && o->faec && W1786_ctarget(o->faec) && !(o->faec->f7f8 & 4))
            r = o->faec;
        else
            r = D_0034e948;
    }
    W1786_set_obj(t, r, 0);
}
}  // namespace n00190a80

// ---- 00190b30 from src/anon/batch_w1967.cpp
namespace n00190b30 {
struct W1967V {
    f32 x, y, z, w;
    W1967V operator-(const W1967V& b) const {
        W1967V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1967Info { f32 a; f32 r; f32 pad[2]; W1967V pos; };
struct W1967Obj;
struct W1967ObjVt { u8 pad[0x9c]; W1967V (*getPos)(W1967Obj*); };
struct W1967Obj { W1967ObjVt* vt; };
struct W1967Act { u8 pad[0x588]; u32 flags; };
struct W1967Part { u8 id; u8 pad; u16 flags; };
struct W1967Cfg { u8 pad[0x4c]; f32 range; };
extern W1967Cfg* D_00352130 asm("D_00352130");
f32 w1967_GetLockOnRatio(s32*) asm("_ZN2YS6STATUS14GetLockOnRatioEv");
void w1967_ctarget_0016bda8(W1967V*, W1967Obj*) asm("_Z23YS__OBJ__get_target_posjjjj");
void func_00190128(s32*) asm("func_00190128");
W1967Act* w1967_ctarget_001b9bc8(W1967Act*) asm("_Z13YS__OBJ__Eachjjjj");
s32 YS__OBJ__can_lockon(W1967Act*) asm("YS__OBJ__can_lockon");
W1967Part* w1967_each_collision(W1967Act*, s32, W1967Part*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
void YS__COLLISION__set(W1967Info*, W1967Act*, W1967Part*) asm("YS__COLLISION__set");
void w1967_set_obj(s32*, W1967Act*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
void func_00190b30(s32* self, W1967Obj* obj) asm("func_00190b30");
void func_00190b30(s32* self, W1967Obj* obj) {
    W1967Act* a = 0;
    f32 best = 0.0f;
    f32 r = w1967_GetLockOnRatio(self);
    f32 range = D_00352130->range * r;
    W1967V p0 = obj->vt->getPos(obj);
    W1967V p1;
    w1967_ctarget_0016bda8(&p1, obj);
    func_00190128(self);
    while ((a = w1967_ctarget_001b9bc8(a)) != 0) {
        if (!YS__OBJ__can_lockon(a)) continue;
        W1967Part* p = 0;
        f32 lim = 1.0f;
        while ((p = w1967_each_collision(a, 3, p)) != 0) {
            if (p->flags & 1) continue;
            W1967Info info;
            f32 d;
            YS__COLLISION__set(&info, a, p);
            if (!(a->flags & 0x400) || r < lim) {
                f32 d0 = (info.pos - p0).length() - info.r;
                if (range < d0) continue;
            }
            d = (info.pos - p1).length() - info.r;
            if (*self == 0 || d < best) {
                best = d;
                w1967_set_obj(self, a, p->id);
            }
        }
    }
}
}  // namespace n00190b30

// ---- 00190d10 from src/anon/batch_w1655.cpp
namespace n00190d10 {
void func_00190128(void*) asm("func_00190128");
struct W1655QW {
    f32 x, y, z, w;
    W1655QW() {}
    W1655QW(const W1655QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1655QW& operator=(const W1655QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void w1655_vsub(W1655QW* d, const W1655QW* a, const W1655QW* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 w1655_vnorm(W1655QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct W1655Obj;
struct W1655Tgt {
    W1655Obj* obj;
    s32 id;
    s32 c, d, e;
    W1655Tgt() { func_00190128(this); }
};
struct W1655Elem { u8 id; u8 p1; u16 flags; };
struct W1655Hit { s32 p0; f32 radius; f32 height; s32 pc; W1655QW centre; };
struct W1655Prm { u8 p0[0x60]; f32 low; f32 high; u8 p68[4]; f32 yscale; f32 dirmin; };
struct W1655ObjVt { void* f[39]; W1655QW (*getPos)(W1655Obj*); };
struct W1655Obj { W1655ObjVt* vt; u8 p4[0x130 - 4]; W1655Prm* prm; u8 p134[0x588 - 0x134]; u32 flags; };
struct W1655Sys { u8 p0[0x4c]; f32 lockRange; };
extern W1655Sys* D_00352130 asm("D_00352130");
f32 W1655_GetLockOnRatio() asm("_ZN2YS6STATUS14GetLockOnRatioEv");
W1655Obj* W1655_ctarget(W1655Obj*) asm("_Z13YS__OBJ__Eachjjjj");
W1655Elem* W1655_each_collision(W1655Obj*, s32, W1655Elem*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
f32 W1655_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
f32 f_atan2f(f32, f32) asm("f_atan2f");
s32 YS__OBJ__can_lockon(W1655Obj*) asm("YS__OBJ__can_lockon");
void YS__COLLISION__set(W1655Hit*, W1655Obj*, W1655Elem*) asm("YS__COLLISION__set");
W1655QW func_00190388(W1655Tgt*) asm("func_00190388");
struct W1655Best { W1655Tgt t; f32 v; };
W1655Tgt func_00190d10(W1655Tgt* cur, W1655Obj* self, f32 scale) asm("func_00190d10");
W1655Tgt func_00190d10(W1655Tgt* cur, W1655Obj* self, f32 scale) {
    f32 ratio = W1655_GetLockOnRatio();
    f32 range = D_00352130->lockRange * ratio;
    W1655QW pos = self->vt->getPos(self);
    W1655QW d;
    W1655QW tp = func_00190388(cur);
    w1655_vsub(&d, &tp, &pos);
    f32 ang0 = f_atan2f(d.x, d.z);
    W1655Best b;
    W1655Obj* o = 0;
    while ((o = W1655_ctarget(o)) != 0) {
        if (!YS__OBJ__can_lockon(o)) continue;
        W1655Elem* e = 0;
        while ((e = W1655_each_collision(o, 3, e)) != 0) {
            if (e->flags & 1) continue;
            if (o == cur->obj && e->id == cur->id) continue;
            W1655Hit hit;
            YS__COLLISION__set(&hit, o, e);
            w1655_vsub(&tp, &hit.centre, &pos);
            f32 dist = w1655_vnorm(&tp) - hit.radius;
            if (!(o->flags & 0x400) || ratio < 1.0f) {
                if (range < dist) continue;
            }
            f32 r = W1655_FixRadian(f_atan2f(tp.x, tp.z) - ang0) * scale;
            if (!(0.0f < r)) continue;
            if (b.t.obj != 0 && !(r < b.v)) continue;
            b.t.obj = o;
            b.t.id = e->id;
            b.v = r;
        }
    }
    return b.t;
}
}  // namespace n00190d10

// ---- 00190f80 from src/anon/batch_w1655.cpp
namespace n00190f80 {
void func_00190128(void*) asm("func_00190128");
struct W1655QW {
    f32 x, y, z, w;
    W1655QW() {}
    W1655QW(const W1655QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1655QW& operator=(const W1655QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void w1655_vsub(W1655QW* d, const W1655QW* a, const W1655QW* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 w1655_vnorm(W1655QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w1655_vdot(const W1655QW* a, const W1655QW* b) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}
struct W1655Obj;
struct W1655Tgt {
    W1655Obj* obj;
    s32 id;
    s32 c, d, e;
    W1655Tgt() { func_00190128(this); }
};
struct W1655Elem { u8 id; u8 p1; u16 flags; };
struct W1655Hit { s32 p0; f32 radius; f32 height; s32 pc; W1655QW centre; };
struct W1655Prm { u8 p0[0x60]; f32 low; f32 high; u8 p68[4]; f32 yscale; f32 dirmin; };
struct W1655ObjVt { void* f[39]; W1655QW (*getPos)(W1655Obj*); };
struct W1655Obj { W1655ObjVt* vt; u8 p4[0x130 - 4]; W1655Prm* prm; u8 p134[0x588 - 0x134]; u32 flags; };
f32 W1655_GetLockOnRatio() asm("_ZN2YS6STATUS14GetLockOnRatioEv");
W1655Obj* W1655_ctarget(W1655Obj*) asm("_Z13YS__OBJ__Eachjjjj");
W1655Elem* W1655_each_collision(W1655Obj*, s32, W1655Elem*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
void W1655_set_obj(W1655Tgt*, W1655Obj*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
f32 fabsf(f32) asm("fabsf");
s32 YS__OBJ__can_lockon(W1655Obj*) asm("YS__OBJ__can_lockon");
s32 func_0019bb58(W1655Obj*) asm("func_0019bb58");
void YS__COLLISION__set(W1655Hit*, W1655Obj*, W1655Elem*) asm("YS__COLLISION__set");
W1655QW* YS__OBJ__get_pos(W1655Obj*) asm("YS__OBJ__get_pos");
W1655QW YS__OBJ__get_dir(W1655Obj*) asm("YS__OBJ__get_dir");
static inline W1655QW w1655_sub(const W1655QW& a, const W1655QW& b) { W1655QW r; w1655_vsub(&r, &a, &b); return r; }
void YS__TARGET__search_auto_lockon(W1655Tgt* t, W1655Obj* self, f32 limit) asm("YS__TARGET__search_auto_lockon");
void YS__TARGET__search_auto_lockon(W1655Tgt* t, W1655Obj* self, f32 limit) {
    f32 best = 0.0f;
    W1655Prm* prm = self->prm;
    f32 lo = prm->low;
    f32 hi = prm->high;
    f32 ratio = W1655_GetLockOnRatio();
    if (1.0f < ratio) {
        lo *= ratio;
        hi *= ratio;
    }
    func_00190128(t);
    W1655Obj* o = 0;
    while ((o = W1655_ctarget(o)) != 0) {
        if (!YS__OBJ__can_lockon(o)) continue;
        if (!func_0019bb58(o)) continue;
        f32 zero = 0.0f;
        f32 one = 1.0f;
        f32 half = 0.5f;
        W1655Elem* e = 0;
        while ((e = W1655_each_collision(o, 3, e)) != 0) {
            if (e->flags & 1) continue;
            W1655QW h;
            W1655Hit hit;
            YS__COLLISION__set(&hit, o, e);
            h = w1655_sub(hit.centre, *YS__OBJ__get_pos(self));
            f32 dy = h.y;
            h.y = 0.0f;
            f32 len = w1655_vnorm(&h);
            if (zero < limit) {
                if (dy < lo - hit.height) continue;
                if (hi + hit.height < dy) continue;
                if (limit < len - hit.radius) continue;
            }
            len += fabsf(dy) * prm->yscale;
            f32 dot = w1655_vdot(&YS__OBJ__get_dir(self), &h);
            len *= (one - dot) * half * (one - prm->dirmin) + prm->dirmin;
            if (t->obj != 0 && !(len < best)) continue;
            best = len;
            W1655_set_obj(t, o, e->id);
        }
    }
}
}  // namespace n00190f80

// ---- 00191218 from src/anon/batch_wcx2.cpp
namespace n00191218 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V38 {
    f32 x, y, z, w;
    V38() {}
    V38& operator=(const V38& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline V38 Sub38(const V38& a, const V38& b)
{
    V38 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Len38(const V38& v)
{
    f32 r;
    asm volatile("lqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\t"
                 "vsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0"
                 : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
struct Hit38 { u8 pad[12]; s32 n; V38 pos; };
struct Node38 { u8 id; u8 pad; u16 fl; };
struct Out38 { u8* e; u32 id; };
void func_00190128__68827(void) asm("func_00190128");
u8* YS__ENEMY__Each(u8*) asm("YS__ENEMY__Each");
s32 YS__OBJ__can_lockon(u8*) asm("YS__OBJ__can_lockon");
s32 func_0019bb58(u8*) asm("func_0019bb58");
Node38* func_0016bba8__68827(u8*, s32, Node38*) asm("func_0016bba8");
void func_0018a818__68827(Hit38*, u8*, Node38*) asm("YS__COLLISION__set");
V38* func_0016c028__68827(u32) asm("YS__OBJ__get_pos");
s32 func_00190140(Out38*) asm("func_00190140");
void func_00191218(Out38* out, u32 cam, f32 range) asm("func_00191218");
void func_00191218(Out38* out, u32 cam, f32 range)
{
    f32 best = 0.0f;
    Hit38 h;
    h.n = 0;
    func_00190128__68827();
    u8* e = 0;
    while ((e = YS__ENEMY__Each(e))) {
        if (!YS__OBJ__can_lockon(e)) continue;
        if (!func_0019bb58(e)) continue;
        Node38* n = 0;
        while ((n = func_0016bba8__68827(e, 3, n))) {
            if (n->fl & 1) continue;
            func_0018a818__68827(&h, e, n);
            V38 d;
            d = Sub38(h.pos, *func_0016c028__68827(cam));
            f32 dist = Len38(d);
            f32 r = dist;
            if (*(u32*)(e + 1416) & 0x400) r = dist - range;
            if (!func_00190140(out) || r < best) {
                out->e = e;
                best = r;
                out->id = n->id;
            }
        }
    }
}
}  // namespace n00191218

// ---- 00191398 from src/anon/batch_w1667.cpp
namespace n00191398 {
void YS__PRIORITYTARGET__search(void*, u32, u32) asm("YS__PRIORITYTARGET__search");
extern u8 D_01c60d10 asm("D_01c60d10");
void func_00191398(u32 a, u32 b) asm("func_00191398");
void func_00191398(u32 a, u32 b) { YS__PRIORITYTARGET__search(&D_01c60d10, b, a); }
}  // namespace n00191398

// ---- 001913b8 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n001913b8 {
u32 func_001cd660(u32, u32, u32, u32) asm("_Z13func_001cd660jjjj");
extern u8 D_01c60d10 asm("D_01c60d10");
u32 func_001913b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001913b8jjjj");
u32 func_001913b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001cd660((u32)&D_01c60d10, a1, a2, a3);
}
}  // namespace n001913b8

// ---- 001913d8 from src/anon/batch_w1655.cpp
namespace n001913d8 {
void func_00190128(void*) asm("func_00190128");
struct W1655QW {
    f32 x, y, z, w;
    W1655QW() {}
    W1655QW(const W1655QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1655QW& operator=(const W1655QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void w1655_vsub(W1655QW* d, const W1655QW* a, const W1655QW* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 w1655_vnorm(W1655QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w1655_vlen(const W1655QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w1655_vdot(const W1655QW* a, const W1655QW* b) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}
struct W1655Obj;
struct W1655Tgt {
    W1655Obj* obj;
    s32 id;
    s32 c, d, e;
    W1655Tgt() { func_00190128(this); }
};
struct W1655Elem { u8 id; u8 p1; u16 flags; };
struct W1655Hit { s32 p0; f32 radius; f32 height; s32 pc; W1655QW centre; };
struct W1655Prm { u8 p0[0x60]; f32 low; f32 high; u8 p68[4]; f32 yscale; f32 dirmin; };
struct W1655ObjVt { void* f[39]; W1655QW (*getPos)(W1655Obj*); };
struct W1655Obj { W1655ObjVt* vt; u8 p4[0x130 - 4]; W1655Prm* prm; u8 p134[0x588 - 0x134]; u32 flags; };
struct W1655Sys { u8 p0[0x4c]; f32 lockRange; };
extern W1655Sys* D_00352130 asm("D_00352130");
f32 W1655_GetLockOnRatio() asm("_ZN2YS6STATUS14GetLockOnRatioEv");
W1655Obj* W1655_ctarget(W1655Obj*) asm("_Z13YS__OBJ__Eachjjjj");
W1655Elem* W1655_each_collision(W1655Obj*, s32, W1655Elem*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
void W1655_set_obj(W1655Tgt*, W1655Obj*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 YS__OBJ__can_lockon(W1655Obj*) asm("YS__OBJ__can_lockon");
void YS__COLLISION__set(W1655Hit*, W1655Obj*, W1655Elem*) asm("YS__COLLISION__set");
W1655QW func_00190388(W1655Tgt*) asm("func_00190388");
struct W1655Best { W1655Tgt t; f32 v; };
W1655Tgt func_001913d8(W1655Tgt* cur, W1655Obj* self, const W1655QW* dir) asm("func_001913d8");
W1655Tgt func_001913d8(W1655Tgt* cur, W1655Obj* self, const W1655QW* dir) {
    f32 ratio = W1655_GetLockOnRatio();
    f32 range = D_00352130->lockRange * ratio;
    W1655QW tp = func_00190388(cur);
    W1655QW pos = self->vt->getPos(self);
    W1655Best b;
    W1655Obj* o = 0;
    while ((o = W1655_ctarget(o)) != 0) {
        if (!YS__OBJ__can_lockon(o)) continue;
        W1655Elem* e = 0;
        while ((e = W1655_each_collision(o, 3, e)) != 0) {
            if (e->flags & 1) continue;
            if (o == cur->obj && e->id == cur->id) continue;
            W1655Hit hit;
            YS__COLLISION__set(&hit, o, e);
            W1655QW v;
            w1655_vsub(&v, &hit.centre, &pos);
            if (range < w1655_vlen(&v) - hit.radius) continue;
            W1655QW f;
            w1655_vsub(&f, &hit.centre, &tp);
            f.y = -f.z;
            f.z = 0.0f;
            f32 dist = w1655_vnorm(&f) - hit.radius;
            if (w1655_vdot(&f, dir) < 0.5f) continue;
            if (b.t.obj != 0 && !(dist < b.v)) continue;
            W1655_set_obj(&b.t, o, e->id);
            b.v = dist;
        }
    }
    return b.t;
}
}  // namespace n001913d8

// ---- 00191658 from src/anon/batch_w1673.cpp
namespace n00191658 {
struct A91658 { s32 a; s32 b; };
struct E91658 { u8 d[20]; };
struct B91658 { E91658 e[128]; s32 idx[128]; s32 n; };
extern A91658 D_01c60d10[8] asm("D_01c60d10");
extern B91658 D_01c60d50 asm("D_01c60d50");
void func_00190128(E91658*) asm("func_00190128");
void wtarget_00191658(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00191658jjjj");
void wtarget_00191658(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff && a0 == 1) {
        A91658* p = D_01c60d10;
        for (s32 i = 7; i != -1; i--, p++) p->b = 0;
    }
    if (a1 == 0xffff && a0 == 1) {
        E91658* e = D_01c60d50.e;
        for (s32 i = 127; i != -1; e++) { i--; func_00190128(e); }
        B91658* b = &D_01c60d50;
        s32* q = b->idx;
        for (s32 j = 0; j < 128; j++) *q++ = j;
        b->n = 128;
    }
}
}  // namespace n00191658

// ---- 00191738 from src/anon/tiny_wrappers_more.cpp
namespace n00191738 {
u32 func_00191658(u32, u32, u32, u32) asm("_Z13func_00191658jjjj");
u32 func_00191738(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00191738jjjj");
u32 func_00191738(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00191658(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00191738

