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
#include "../worldmap/libretto.hpp"
#include "../worldmap/rootwindow.hpp"
#include "../worldmap/messagewidget.hpp"
#include "../ohori/sebank.hpp"

// ---- 002bc978 from src/anon/tiny_leaf_more.cpp
namespace n002bc978 {
u32 func_002bc978(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bc978jjjj");
u32 func_002bc978(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(16));
    r2 = (u32)((s32)0u + (1));
    if (r15 != 0u) r2 = r15;
    return r2;
}
}  // namespace n002bc978

// ---- 002bc988 from src/anon/misc_2.cpp
namespace n002bc988 {
s16 func_002bc988(void* self) asm("_Z13func_002bc988Pv");
s16 func_002bc988(void* self) { return (s16)(*(s16*)((char*)self + 8)); }
}  // namespace n002bc988

// ---- 002bc990 from src/anon/tiny_wrappers_more.cpp
namespace n002bc990 {
u32 func_00324750(u32, u32, u32, u32) asm("_Z13func_00324750jjjj");
u32 func_002bc990(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bc990jjjj");
u32 func_002bc990(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00324750(a0, 0xffffffffu, a2, a3);
}
}  // namespace n002bc990

// ---- 002bc9a8 from src/anon/tiny_auto80_queue.cpp
namespace n002bc9a8 {
void func_002bc9a8(s32 a0, u32 a1, u32 a2) asm("_Z13func_002bc9a8ijj");
void func_002bc9a8(s32 a0, u32 a1, u32 a2) {                           
    s32 end = a0 + 324;
    while (1) {
        if (*(u32*)(a0 + 0) == a1) {
            *(u32*)(a0 + 4) = a2;
            return;
        }
        a0 += 12;
        if (a0 < end) {
            continue;
        }
        return;
    }
}
}  // namespace n002bc9a8

// ---- 002bc9d8 from src/anon/batch_w11.cpp
namespace n002bc9d8 {
struct E2bc { s32 v; s32 key; u32 c; };
s32 func_002bc9d8(u8* p, s32 key) asm("func_002bc9d8");
s32 func_002bc9d8(u8* p, s32 key) {
    E2bc* e = (E2bc*)(p + 132);
    do {
        if (e->key == key) return e->v;
        e++;
    } while ((s32)e < (s32)(p + 300));
    return -1;
}
}  // namespace n002bc9d8

// ---- 002bca10 from src/anon/batch_w22.cpp
namespace n002bca10 {
struct E2bc { s32 b; s32 a; s32 c; };
s32 func_002bca10(E2bc* t, s32 a, s32 b) asm("func_002bca10");
s32 func_002bca10(E2bc* t, s32 a, s32 b) {                         
    E2bc* e = t;
    do {
        if (e->a == a && e->b == b) return b;
        e++;
    } while ((s32)e < (s32)(t + 11));
    return -1;
}
}  // namespace n002bca10

// ---- 002bca48 from src/anon/tiny_auto80_queue.cpp
namespace n002bca48 {
s32 func_002bca48(s32 a0, u32 a1) asm("_Z13func_002bca48ij");
s32 func_002bca48(s32 a0, u32 a1) {                    
    s32 end = a0 + 324;

    while (1) {
        if (*(u32*)(a0 + 4) == a1) {
            return *(s32*)(a0 + 0);
        }
        a0 += 12;
        if (a0 < end) {
            continue;
        }
        return -1;
    }
}
}  // namespace n002bca48

// ---- 002bca78 from src/anon/batch_w247.cpp
namespace n002bca78 {
u32 func_002bc988(void*) asm("_Z13func_002bc988Pv");
s32 func_002bc9d8(u8*, u32) asm("func_002bc9d8");
void func_002bc9a8(u8*, s32, u32) asm("func_002bc9a8");
s32 func_002bc978(void*) asm("func_002bc978");
void func_002bcda8(u8*, s32) asm("func_002bcda8");
void func_002bd188(u8*, s32) asm("func_002bd188");
s32 func_002bca78(u8* o, void* a, void* b, s32* out, u32* out2) asm("func_002bca78");
s32 func_002bca78(u8* o, void* a, void* b, s32* out, u32* out2)
{
    *out2 = func_002bc988(a);
    s32 r = func_002bc9d8(o, *out2);
    *out = r;
    if (r == -1) {
        s32 v = *(s32*)(o + 328);
        *out = v;
        func_002bc9a8(o, v, *out2);                           
        s32 n = func_002bc978(b);
        for (s32 i = 0; i < n - 1; i++) {
            s32 x = *(s32*)(o + 328) + i + 1;
            func_002bcda8(o, x);
            func_002bd188(o, x);
        }
        *(s32*)(o + 328) += n;
        return 1;
    }
    return 0;
}
}  // namespace n002bca78

// ---- 002bcb60 from src/anon/auto80_199_queue.cpp
namespace n002bcb60 {
u32 func_002bcb60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002bcb60jjjjjjjj");
u32 func_002bcb60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a3;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a4;
    u32 s19 = a5;

    u32 v = func_002bc988(a2);
    *(u32*)s19 = v;

    s32 r = func_002bca10(s16, v, s17);
    *(u32*)s18 = (u32)r;

    u32 ok = 0;
    if (r == -1) {
        *(u32*)s18 = s17;
        func_002bc9a8(s16, s17, *(u32*)s19);                           
        ok = 1;
    }

    return ok;
}
}  // namespace n002bcb60

// ---- 002bcbf0 from src/anon/batch_w48.cpp
namespace n002bcbf0 {
s32 func_002bc988(s32) asm("func_002bc988");
void func_002bc9a8(void*, s32, s32) asm("func_002bc9a8");
void func_002bcbf0(u8* o, s32 a1, s32 a2, s32* a3, s32* t0) asm("func_002bcbf0");
void func_002bcbf0(u8* o, s32 a1, s32 a2, s32* a3, s32* t0) {
    *t0 = func_002bc988(a1);
    s32 m = *(s32*)(o + 332);
    *a3 = m;
    func_002bc9a8(o, m, *t0);                           
    *(s32*)(o + 332) = *(s32*)(o + 332) == 20 ? 21 : 20;
}
}  // namespace n002bcbf0

// ---- 002bcc60 from src/anon/auto80_199_queue.cpp
namespace n002bcc60 {
void func_002bcc60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002bcc60jjjjjjjj");
void func_002bcc60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a2;
    (void)a3;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s19 = a3;
    u32 s18 = a4;

    func_002bcf58(s16);
    SE_BANK__objectDestroy(s16);
    func_002bd1c0(s16);

    *(u32*)s18 = func_002bc988(s17);
    *(u32*)s19 = 30;

    func_002bc9a8(s16, 30, *(u32*)s18);                           
}
}  // namespace n002bcc60

// ---- 002bccd8 from src/anon/auto80_199_queue.cpp
namespace n002bccd8 {
u32 func_002bccd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002bccd8jjjjjjjj");
u32 func_002bccd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a3;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a4;
    u32 s19 = a5;

    u32 v = func_002bc988(a2);
    *(u32*)s19 = v;

    s32 r = func_002bca48(s16, v);
    *(u32*)s18 = (u32)r;

    u32 ok = 0;
    if (r == -1) {
        *(u32*)s18 = s17;
        func_002bc9a8(s16, s17, *(u32*)s19);                           
        ok = 1;
    }

    return ok;
}
}  // namespace n002bccd8

// ---- 002bcd60 from src/anon/tiny_auto80_queue.cpp
namespace n002bcd60 {
s32 func_002bcd60(s32 a0, u32 a1) asm("_Z13func_002bcd60ij");
s32 func_002bcd60(s32 a0, u32 a1) {
    s32 end = a0 + 324;

    while (1) {
        if (*(u32*)(a0 + 4) == a1) {
            u32 t = (*(u32*)(a0 + 8)) ^ 1u;
            if (t != 0) {
                return -1;
            }
            return *(s32*)(a0 + 0);
        }

        a0 += 12;
        if (a0 < end) {
            continue;
        }
        return -1;
    }
}
}  // namespace n002bcd60

// ---- 002bcda8 from src/anon/tiny_auto80_queue.cpp
namespace n002bcda8 {
void func_002bcda8(s32 a0, u32 a1) asm("_Z13func_002bcda8ij");
void func_002bcda8(s32 a0, u32 a1) {
    s32 i = 0;

    while (1) {
        if (*(u32*)(a0 + 0) == a1) {
            *(s32*)(a0 + 0) = i;
            *(s32*)(a0 + 4) = -1;
            *(u32*)(a0 + 8) = 0;
            return;
        }

        i += 1;
        if (i < 27) {
            a0 += 12;
            continue;
        }
        return;
    }
}
}  // namespace n002bcda8

// ---- 002bcde0 gap
namespace n002bcde0 {
void func_002bcde0(u32* a0, u32 a1) asm("func_002bcde0");
void func_002bcde0(u32* a0, u32 a1) {
    u32* end = (u32*)((u8*)a0 + 324);
loop:
    if (__builtin_expect(*a0 == a1, 0)) {
        a0[2] = 0;
        return;
    }
    a0 = (u32*)((u8*)a0 + 12);
    if ((s32)a0 < (s32)end) {
        goto loop;
    }
}
}  // namespace n002bcde0

// ---- 002bce10 from src/anon/tiny_auto80_queue.cpp
namespace n002bce10 {
void func_002bce10(u32* a0, u32 a1) asm("_Z13func_002bce10Pjj");
void func_002bce10(u32* a0, u32 a1) {                          
    u32* end = (u32*)((u8*)a0 + 324);
loop:
    if (__builtin_expect(*a0 == a1, 0)) {
        a0[2] = 1;
        return;
    }
    a0 = (u32*)((u8*)a0 + 12);
    if ((s32)a0 < (s32)end) {
        goto loop;
    }
}
}  // namespace n002bce10

// ---- 002bce40 from src/anon/tiny_auto80.cpp
namespace n002bce40 {
void func_002bce40(u32, u32, u32, u32) asm("_Z13func_002bce40jjjj");
void func_002bce40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bce40jjjj");
void func_002bce40(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u8*)((u32)r4 + (s32)(336)) = (u8)0u;
    *(volatile u32*)((u32)r4 + (s32)(324)) = 0u;
}
}  // namespace n002bce40

// ---- 002bce50 from src/anon/batch_w65.cpp
namespace n002bce50 {
extern u32 D_003616f8[] asm("D_003616f8");
void func_002bc470(u32) asm("func_002bc470");
struct Ent12b { u32 a; s32 b; u32 c; };
void SE_BANK__clearField(u8* p) asm("SE_BANK__clearField");
void SE_BANK__clearField(u8* p) {
    p[336] = 0;
    *(s32*)(p + 328) = 30;
    *(s32*)(p + 332) = 20;
    Ent12b* e = (Ent12b*)p;
    u32* s = D_003616f8;
    s32 i;
    for (i = 26; i >= 0; i--) {
        e->a = *s;
        e->b = -1;
        e->c = 0;
        func_002bc470(*s);
        e++;
        s++;
    }
}
}  // namespace n002bce50

// ---- 002bced8 from src/ohori/sebank.cpp
void SE_BANK::setGumiMode() {
    *(u32*)((u32)this + (s32)(324)) = 1u;
    *(u8*)((u32)this + (s32)(336)) = (u8)0u;
}

// ---- 002bcee8 from src/anon/batch_w49.cpp
namespace n002bcee8 {
extern u32 D_00361768[] asm("D_00361768");
void func_002bc470(u32) asm("func_002bc470");
void SE_BANK__clearGumi(u32* p) asm("SE_BANK__clearGumi");
void SE_BANK__clearGumi(u32* p) {
    u32* s = D_00361768;
    for (s32 i = 0; i < 27; i++) {
        p[0] = *s;
        p[1] = -1;
        p[2] = 0;
        func_002bc470(*s);
        p += 3;
        s++;
    }
}
}  // namespace n002bcee8

// ---- 002bcf58 from src/anon/auto200_999.cpp
namespace n002bcf58 {
extern u8 D_003616f8 asm("D_003616f8");
void func_002bcf58(u32 *a0) asm("_Z13func_002bcf58Pj");
void func_002bcf58(u32 *a0) {
    u32 thirty = 30;
    u32 neg1 = 0xFFFFFFFF;
    a0[82] = thirty;
    s32 i = 13;
    a0 = (u32 *)((u8 *)a0 + 132);
    u32 *base = (u32 *)&D_003616f8;
    u32 *src = (u32 *)((u8 *)base + 44);
    do {
        u32 v = src[0];
        i -= 1;
        a0[0] = v;
        src = (u32 *)((u8 *)src + 4);
        a0[1] = neg1;
        a0[2] = 0;
        a0 = (u32 *)((u8 *)a0 + 12);
    } while (i >= 0);
}
}  // namespace n002bcf58

// ---- 002bcfa0 from src/anon/tiny_auto80_queue.cpp
namespace n002bcfa0 {
extern u8 D_003616f8 asm("D_003616f8");
void func_002bc470(...) asm("func_002bc470");
void SE_BANK__objectDestroy() asm("_Z22SE_BANK__objectDestroyv");
void SE_BANK__objectDestroy() {
    u32* base = (u32*)&D_003616f8;
    u32* p = (u32*)((u8*)base + 44);
    s32 i = 13;
    do {
        func_002bc470(*p);
        i -= 1;
        p = (u32*)((u8*)p + 4);
    } while (i >= 0);
}
}  // namespace n002bcfa0

// ---- 002bcfe8 from src/anon/tiny_auto80_queue.cpp
namespace n002bcfe8 {
extern u8 D_003616f8 asm("D_003616f8");
void func_002bcfe8(u32* a0) asm("_Z13func_002bcfe8Pj");
void func_002bcfe8(u32* a0) {
    u32 thirty = 20;
    u32 neg1 = 0xFFFFFFFF;
    a0[83] = thirty;
    s32 i = 1;
    a0 = (u32*)((u8*)a0 + 300);
    u32* base = (u32*)&D_003616f8;
    u32* src = (u32*)((u8*)base + 100);
    do {
        u32 v = src[0];
        i -= 1;
        a0[0] = v;
        src = (u32*)((u8*)src + 4);
        a0[1] = neg1;
        a0[2] = 0;
        a0 = (u32*)((u8*)a0 + 12);
    } while (i >= 0);
}
}  // namespace n002bcfe8

// ---- 002bd030 from src/anon/tiny_auto80_queue.cpp
namespace n002bd030 {
extern u8 D_003616f8 asm("D_003616f8");
void func_002bc470(...) asm("func_002bc470");
void func_002bd030() asm("_Z13func_002bd030v");
void func_002bd030() {
    u32* base = (u32*)&D_003616f8;
    u32* p = (u32*)((u8*)base + 100);
    s32 i = 1;
loop:
    func_002bc470(*p);
    i -= 1;
    if (i >= 0) {
        p = (u32*)((u8*)p + 4);
        goto loop;
    }
}
}  // namespace n002bd030

// ---- 002bd078 from src/anon/tiny_auto80_queue.cpp
namespace n002bd078 {
extern u8 D_003616f8 asm("D_003616f8");
void func_002bd078(u32* a0) asm("_Z13func_002bd078Pj");
void func_002bd078(u32* a0) {
    a0 = (u32*)((u8*)a0 + 24);
    u32 neg1 = 0xFFFFFFFF;
    u32* base = (u32*)&D_003616f8;
    u32* src = (u32*)((u8*)base + 8);
    s32 i = 4;
    do {
        u32 v = src[0];
        i -= 1;
        a0[0] = v;
        src = (u32*)((u8*)src + 4);
        a0[1] = neg1;
        a0[2] = 0;
        a0 = (u32*)((u8*)a0 + 12);
    } while (i >= 0);
}
}  // namespace n002bd078

// ---- 002bd0b8 from src/anon/tiny_auto80_queue.cpp
namespace n002bd0b8 {
extern u8 D_003616f8 asm("D_003616f8");
void func_002bc470(...) asm("func_002bc470");
void func_002bd0b8() asm("_Z13func_002bd0b8v");
void func_002bd0b8() {
    u32* base = (u32*)&D_003616f8;
    u32* p = (u32*)((u8*)base + 8);
    s32 i = 4;
loop:
    func_002bc470(*p);
    i -= 1;
    if (i >= 0) {
        p = (u32*)((u8*)p + 4);
        goto loop;
    }
}
}  // namespace n002bd0b8

// ---- 002bd100 from src/anon/tiny_auto80_queue.cpp
namespace n002bd100 {
extern u8 D_003616f8 asm("D_003616f8");
void func_002bd100(u32* a0) asm("_Z13func_002bd100Pj");
void func_002bd100(u32* a0) {
    a0 = (u32*)((u8*)a0 + 84);
    u32 neg1 = 0xFFFFFFFF;
    u32* base = (u32*)&D_003616f8;
    u32* src = (u32*)((u8*)base + 28);
    s32 i = 3;
    do {
        u32 v = src[0];
        i -= 1;
        a0[0] = v;
        src = (u32*)((u8*)src + 4);
        a0[1] = neg1;
        a0[2] = 0;
        a0 = (u32*)((u8*)a0 + 12);
    } while (i >= 0);
}
}  // namespace n002bd100

// ---- 002bd140 from src/anon/tiny_auto80_queue.cpp
namespace n002bd140 {
extern u8 D_003616f8 asm("D_003616f8");
void func_002bc470(...) asm("func_002bc470");
void func_002bd140() asm("_Z13func_002bd140v");
void func_002bd140() {
    u32* base = (u32*)&D_003616f8;
    u32* p = (u32*)((u8*)base + 28);
    s32 i = 3;
loop:
    func_002bc470(*p);
    i -= 1;
    if (i >= 0) {
        p = (u32*)((u8*)p + 4);
        goto loop;
    }
}
}  // namespace n002bd140

// ---- 002bd188 from src/anon/batch_w12.cpp
namespace n002bd188 {
void func_002b6adc(s32, u32) asm("func_002b6adc");
void func_002b6ab8(void) asm("func_002b6ab8");
void func_002bd188(u32 a, u32 b) asm("func_002bd188");
void func_002bd188(u32 a, u32 b) {
    func_002b6adc(2, b);
    func_002b6adc(0, b);
    func_002b6ab8();
}
}  // namespace n002bd188

// ---- 002bd1c0 from src/anon/batch_w25.cpp
namespace n002bd1c0 {
extern u32 D_003616f8[] asm("D_003616f8");
void func_002b6adc(u32, u32) asm("func_002b6adc");
void func_002b6ab8(void) asm("func_002b6ab8");
void func_002bd1c0(void) asm("func_002bd1c0");
void func_002bd1c0(void) {
    s32 i;
    for (i = 11; i < 25; i++) {
        func_002b6adc(2, D_003616f8[i]);
        func_002b6adc(0, D_003616f8[i]);
    }
    func_002b6ab8();
}
}  // namespace n002bd1c0

// ---- 002bd218 from src/anon/tiny.cpp
namespace n002bd218 {
extern u32 D_003617d8 asm("D_003617d8");
extern u32 D_003617dc asm("D_003617dc");
void func_002bd218(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bd218jjjj");
void func_002bd218(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    D_003617d8 = 0;
    D_003617dc = 0;
}
}  // namespace n002bd218

// ---- 002bd230 from src/anon/batch_w4.cpp
namespace n002bd230 {
extern s32 D_003617d8 asm("D_003617d8");
extern s32 D_003617dc asm("D_003617dc");
u32 func_002bd230(s32 a, s32 b) asm("func_002bd230");
u32 func_002bd230(s32 a, s32 b) {
    u32 same = D_003617d8 == a;
    D_003617d8 = a;
    D_003617dc = b;
    return same;
}
}  // namespace n002bd230

// ---- 002bd250 from src/anon/tiny.cpp
namespace n002bd250 {
u32 func_002bd250(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bd250jjjj");
u32 func_002bd250(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (6108)));
}
}  // namespace n002bd250

// .rodata 0x374fa8
extern "C" const char D_00374fa8[] = "bgm/music%03d.bgm";

// ---- 002bd260 from src/anon/batch_w35.cpp
namespace n002bd260 {
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
void strlen(char*) asm("strlen");
extern char D_01e2bba0[] asm("D_01e2bba0");
extern char D_00374fa8[] asm("D_00374fa8");
char* func_002bd260(u32 a) asm("func_002bd260");
char* func_002bd260(u32 a) {
    func_002fee78(D_01e2bba0, D_00374fa8, a);
    strlen(D_01e2bba0);           
    return D_01e2bba0;
}
}  // namespace n002bd260

extern "C" const char D_00374fc0[] = "bgm/wave%04d.wd";

// ---- 002bd2a8 from src/anon/tiny_auto80_solver.cpp
namespace n002bd2a8 {
u32 func_002bd2a8(u32) asm("_Z13func_002bd2a8j");
u32 func_002fee78(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002fee78jjjjjjjj");
u32 strlen(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z6strlenjjjjjjjj");
extern u8 D_00374fc0 asm("D_00374fc0");
extern u8 D_01e2bbe0 asm("D_01e2bbe0");
u32 func_002bd2a8(u32 a0) asm("_Z13func_002bd2a8j");
u32 func_002bd2a8(u32 a0) {
    u32 s0 = (u32)&D_01e2bbe0;
    ((u32(*)(u32, u32, u32))func_002fee78)(s0, (u32)&D_00374fc0, a0);
    ((u32(*)(u32))strlen)(s0);
    return s0;
}
}  // namespace n002bd2a8

extern "C" const s32 D_00374fd0 = 0x8000;

// ---- 002bd2f0 from src/anon/tiny_wrappers_more.cpp
namespace n002bd2f0 {
u32 func_002bd2a8(u32, u32, u32, u32) asm("_Z13func_002bd2a8jjjj");
u32 func_002bd2f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bd2f0jjjj");
u32 func_002bd2f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a1) + 0u) = (u32)(((u32)(*(u16*)((u32)(a0) + 6u))));
    return func_002bd2a8(((u32)(*(u16*)((u32)(a0) + 6u))), a1, a2, a3);
}
}  // namespace n002bd2f0

// ---- 002bd310 from src/anon/batch_w320.cpp
namespace n002bd310 {
struct Heap2bd310;
struct Heap2bd310Vt { void* (*alloc)(Heap2bd310*, u32, s32); void (*free)(Heap2bd310*, void*); };
struct Heap2bd310 { Heap2bd310Vt* vt; };
struct Ctx2bd310 { u32 f0; void* file; u32 f8; void* f12; Heap2bd310* heap; };
void func_002ba298(void*) asm("func_002ba298");
s32 func_001688c8(void*) asm("func_001688c8");
void YS__FILE__ReadBack(void*, void*, s32, s32) asm("YS__FILE__ReadBack");
s32 YS__CACHE_BUFF__IsFlushing(void) asm("YS__CACHE_BUFF__IsFlushing");
void func_00102448(Ctx2bd310*, s32) asm("func_00102448");
void func_002baf48(void*, s32, void*, s32, s32, s32) asm("func_002baf48");
s32 func_002ba200(void) asm("func_002ba200");
void* func_002bd2f0(void*, s32*) asm("func_002bd2f0");
s32 func_002bd230(s32, u32) asm("func_002bd230");
void SOUND__readBgmThread(Ctx2bd310* c) asm("SOUND__readBgmThread");
void SOUND__readBgmThread(Ctx2bd310* c)
{
    Heap2bd310* h = c->heap;
    void* fh = c->file;
    void* x = c->f12;
    u32 y = c->f8;
    func_002ba298(x);
    s32 sz = func_001688c8(fh);
    void* raw = h->vt->alloc(h, (sz + 2111) & ~2047, 0);
    void* buf = (void*)(((u32)raw + 63) & ~63);
    YS__FILE__ReadBack(fh, buf, 0, 0);
    while (YS__CACHE_BUFF__IsFlushing()) func_00102448(c, 0);
    func_002baf48(x, 2, buf, sz, 0, 0);
    while (func_002ba200()) func_00102448(c, 0);
    s32 out = 0;
    void* r = func_002bd2f0(buf, &out);
    h->vt->free(h, raw);
    if (func_002bd230(out, y)) return;
    s32 sz2 = func_001688c8(r);
    void* raw2 = h->vt->alloc(h, (sz2 + 2111) & ~2047, 0);
    void* buf2 = (void*)(((u32)raw2 + 63) & ~63);
    YS__FILE__ReadBack(r, buf2, 0, 0);
    while (YS__CACHE_BUFF__IsFlushing()) func_00102448(c, 0);
    func_002baf48(0, 1, buf2, sz2, 0, 0);
    while (func_002ba200()) func_00102448(c, 0);
    h->vt->free(h, raw2);
}
}  // namespace n002bd310

// ---- 002bd538 from src/anon/batch_w13.cpp
namespace n002bd538 {
u32 func_002b823c(void) asm("func_002b823c");
extern u32 D_003617e0 asm("D_003617e0");
extern u32 D_003617e4 asm("D_003617e4");
extern u8 D_003617e8 asm("D_003617e8");
void func_002bd538(void) asm("func_002bd538");
void func_002bd538(void) {
    D_003617e4 = 0;
    D_003617e0 = func_002b823c();
    D_003617e8 = 1;
}
}  // namespace n002bd538

// ---- 002bd570 from src/anon/tiny.cpp
namespace n002bd570 {
void func_002b8274(s32) asm("_Z13func_002b8274i");
void func_002bd570(BD_VALUE* bd) asm("_Z13func_002bd570P8BD_VALUE");
void func_002bd570(BD_VALUE* bd) { func_002b8274(-1); }
}  // namespace n002bd570

// ---- 002bd588 from src/anon/tiny.cpp
namespace n002bd588 {
void func_002b82f8(void*) asm("_Z13func_002b82f8Pv");
void func_002bd588(BD_VALUE* bd) asm("_Z13func_002bd588P8BD_VALUE");
void func_002bd588(BD_VALUE* bd) { func_002b82f8(bd); }
}  // namespace n002bd588

// ---- 002bd5a0 gap
namespace n002bd5a0 {
void func_002b8374(void) asm("func_002b8374");
extern u8 D_003617e8 asm("D_003617e8");
void func_002bd5a0(void) asm("func_002bd5a0");
void func_002bd5a0(void) {
    func_002b8374();
    D_003617e8 = 0;
}
}  // namespace n002bd5a0

// ---- 002bd5c8 from src/anon/tiny.cpp
namespace n002bd5c8 {
void func_002b83b4(void*) asm("_Z13func_002b83b4Pv");
void func_002bd5c8(BD_VALUE* bd) asm("_Z13func_002bd5c8P8BD_VALUE");
void func_002bd5c8(BD_VALUE* bd) { func_002b83b4(bd); }
}  // namespace n002bd5c8

// ---- 002bd5e0 gap
namespace n002bd5e0 {
void func_002b83ec(void) asm("func_002b83ec");
void func_002bd5e0(void) asm("func_002bd5e0");
void func_002bd5e0(void) {
    func_002b83ec();
}
}  // namespace n002bd5e0

// ---- 002bd5f8 gap
namespace n002bd5f8 {
struct SifDma { u32 data; u32 addr; u32 size; u32 mode; };
extern u32 D_003617e0 asm("D_003617e0");
void FlushCache(s32) asm("FlushCache");
u32 sceSifSetDma(SifDma*, s32) asm("func_00308310");
s32 sceSifDmaStat(u32) asm("sceSifDmaStat");
void func_002bd5f8(u32 data, u32 size, s32 slot) asm("func_002bd5f8");
void func_002bd5f8(u32 data, u32 size, s32 slot) {
    SifDma d;
    if (slot < 0) slot = 0;
    d.data = data;
    d.addr = D_003617e0 + (slot << 15);
    d.size = size;
    d.mode = 0;
    FlushCache(0);
    u32 id;
    do {
        id = sceSifSetDma(&d, 1);
    } while (id == 0);
    while (sceSifDmaStat(id) >= 0) {
    }
}
}  // namespace n002bd5f8

// ---- 002bd668 gap
namespace n002bd668 {
extern u8 D_003617e8 asm("D_003617e8");
u32 func_002bd668(void) asm("func_002bd668");
u32 func_002bd668(void) {
    return D_003617e8 == 1;
}
}  // namespace n002bd668

// ---- 002bd680 from src/anon/tiny_auto80_queue.cpp
namespace n002bd680 {
extern u32 func_003617e4 asm("func_003617e4");
extern u8  func_003617e8 asm("func_003617e8");
void func_002b8434(...) asm("func_002b8434");
void func_002bd680() asm("_Z13func_002bd680v");
void func_002bd680() {
    if (func_003617e8 != 1) {
        u32 t = func_003617e4;
        if (t == 0) {
            func_002b8434(1);
            t = func_003617e4;
        }
        func_003617e4 = t + 1;
    }
}
}  // namespace n002bd680

// ---- 002bd6d0 from src/anon/batch_w33.cpp
namespace n002bd6d0 {
extern u8 D_003617e8 asm("D_003617e8");
extern s32 D_003617e4 asm("D_003617e4");
void func_002b8434(s32) asm("func_002b8434");
void ResetPauseImpl_002bd6d0(void) asm("_ZN2Tz9MenuSound14ResetPauseImplEv");
void ResetPauseImpl_002bd6d0(void) {
    if (D_003617e8 != 1 && D_003617e4 > 0 && --D_003617e4 == 0) func_002b8434(0);
}
}  // namespace n002bd6d0

// ---- 002bd720 gap
namespace n002bd720 {
extern u32 D_003617e4 asm("D_003617e4");
u32 func_002bd720(void) asm("func_002bd720");
u32 func_002bd720(void) {
    return D_003617e4 != 0;
}
}  // namespace n002bd720

// ---- 002bd730 from src/anon/batch_w10.cpp
namespace n002bd730 {
void func_002b8824(void*, void*, s32, void*, void*) asm("func_002b8824");
extern s32 D_003617f0 asm("D_003617f0");
extern void* D_003617ec asm("D_003617ec");
void func_002bd730(s32 a, void* b, void* c, void* d) asm("func_002bd730");
void func_002bd730(s32 a, void* b, void* c, void* d) {
    D_003617f0 = a;
    func_002b8824(D_003617ec, b, 64, c, d);
}
}  // namespace n002bd730

// ---- 002bd760 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n002bd760 {
u32 func_002b89e4(u32, u32, u32, u32) asm("_Z13func_002b89e4jjjj");
extern u8 D_00360000 asm("D_00360000");
u32 func_002bd760(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bd760jjjj");
u32 func_002bd760(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002b89e4(((u32)(*(u32*)((u32)((u32)&D_00360000) + 6124u))), 0x00000000u, a0, a3);
}
}  // namespace n002bd760

// ---- 002bd788 from src/anon/batch_w57.cpp
namespace n002bd788 {
extern u32 D_003617ec asm("D_003617ec"); extern u32 D_003617f4 asm("D_003617f4");
extern u8 D_003617f8 asm("D_003617f8");
extern u32 D_0032b91c asm("D_0032b91c");
void func_002b871c(void) asm("func_002b871c");
u32 func_00102788(u32, u32, u32, u32) asm("func_00102788");
void func_002bd870(void) asm("func_002bd870");
void func_002bd788(u32 a) asm("func_002bd788");
void func_002bd788(u32 a) {
    D_003617f8 = 0;
    D_003617ec = a;
    func_002b871c();
    D_003617f4 = func_00102788(D_0032b91c, 0, 0x5cc60, (u32)func_002bd870);
}
}  // namespace n002bd788

// ---- 002bd7d8 from src/anon/batch_w39.cpp
namespace n002bd7d8 {
extern u32 D_0032b91c asm("D_0032b91c");
extern u32 D_003617ec asm("D_003617ec");
extern u32 D_003617f0 asm("D_003617f0");
extern u32 D_003617f4 asm("D_003617f4");
extern u8 D_003617f8 asm("D_003617f8");
void func_002b8a70(u32) asm("func_002b8a70");
void func_00102670(u32, u32) asm("func_00102670");
void func_002bd7d8(void) asm("func_002bd7d8");
void func_002bd7d8(void) {
    func_002b8a70(D_003617ec);
    D_003617ec = 0;
    D_003617f0 = 0;
    func_00102670(D_0032b91c, D_003617f4);              
    D_003617f4 = 0;
    D_003617f8 = 0;
}
}  // namespace n002bd7d8

// ---- 002bd838 from src/anon/tiny_auto80_queue.cpp
namespace n002bd838 {
extern u32 func_003617ec asm("func_003617ec");
extern u8  func_003617f8 asm("func_003617f8");
void func_002b8c78(...) asm("func_002b8c78");
void func_002bd838() asm("_Z13func_002bd838v");
void func_002bd838() {
    u32 t = func_003617ec;
    if (t != 0) {
        func_002b8c78(t);
        func_003617f8 = 0;
    }
}
}  // namespace n002bd838

// ---- 002bd870 from src/anon/batch_w50.cpp
namespace n002bd870 {
s32 func_002b8ac0(u8*) asm("func_002b8ac0");
extern u8* D_003617ec asm("D_003617ec");
extern u8* D_003617f0 asm("D_003617f0");
extern u8 D_003617f8 asm("D_003617f8");
void func_00168410(u8*, u8*, u32, s32, void*, s32) asm("func_00168410");
void func_002bd838(void) asm("func_002bd838");
void func_002bd870(void) asm("func_002bd870");
void func_002bd870(void) {
    if (!func_002b8ac0(D_003617ec)) return;
    if (D_003617f8) return;
    u8* p = D_003617f0;
    if (!p) return;
    func_00168410(p, D_003617ec, *(u32*)(D_003617ec + 0x4802c), 16, (void*)func_002bd838, 0);
    D_003617f8 = 1;
}
}  // namespace n002bd870

// ---- 002bd8f8 from src/anon/batch_w228.cpp
namespace n002bd8f8 {
struct V4 {
    f32 x, y, z, w;
    V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
};
void* func_001b8680(u32, void*) asm("func_001b8680");
void func_002edf68(void*) asm("func_002edf68");
void func_002c20f8(void*) asm("func_002c20f8");
void func_002c2168(void*) asm("func_002c2168");
extern char D_002be408[] asm("D_002be408");
extern u32 D_003617fc asm("D_003617fc");
void func_002bd8f8(u32* p, u32 a1) asm("func_002bd8f8");
void func_002bd8f8(u32* p, u32 a1) {
    p[0] = a1;
    p[1] = (u32)func_001b8680(a1, D_002be408);
    func_002edf68(p + 2);
    p[15] = 0;
    p[26] = 0;
    D_003617fc = (u32)p;
    u32* q = p + 11;
    int i = 3;
    do { *q = 0; i--; q++; } while (i >= 0);
    ((u8*)p)[64] = 0;
    V4 v(0.0f, 0.0f, 0.0f, 0.0f);
    func_002c20f8(&v);
    func_002c2168(&v);
}
}  // namespace n002bd8f8

// ---- 002bd998 from src/anon/batch_w227.cpp
namespace n002bd998 {
void* func_001b8680(u32, const void*) asm("func_001b8680");
void func_002edf68(void*) asm("func_002edf68");
void func_002c20f8(f32*) asm("func_002c20f8");
void func_002c2168(f32*) asm("func_002c2168");
extern const char D_002be408[] asm("D_002be408");
extern void* D_003617fc asm("D_003617fc");
struct U_002bd998 { u32 a; void* b; u8 p0[0x34]; u32 c; u8 p1[0x28]; u32 f; };
void func_002bd998(U_002bd998* t, u32 a1) asm("func_002bd998");
void func_002bd998(U_002bd998* t, u32 a1) {
    t->a = a1;
    t->b = func_001b8680(a1, D_002be408);
    func_002edf68((u8*)t + 8);
    t->c = 0;
    t->f = 0;
    *(u32*)&D_003617fc = (u32)t;
    u32* p = (u32*)((u8*)t + 44);
    for (int i = 3; i >= 0; i--) { *p = 0; p++; }
    *((u8*)t + 64) = 0;
    f32 z = 0.0f;
    f32 v[4];
    v[0] = z; v[1] = z; v[2] = z; v[3] = z;
    func_002c20f8(v);
    func_002c2168(v);
}
}  // namespace n002bd998

// ---- 002bda38 from src/anon/batch_w62.cpp
namespace n002bda38 {
struct VObj2b { void (**vt)(VObj2b*); u8 pad[28]; VObj2b* next; };
void func_002be148(u8*) asm("func_002be148");
void func_00170950(u32) asm("func_00170950");
void func_001b86e0(u32) asm("func_001b86e0");
void func_00170320(s32) asm("func_00170320");
extern u32 D_003617fc asm("D_003617fc");
extern u8 D_003637e0[] asm("D_003637e0");
void func_002bda38(u8* p) asm("func_002bda38");
void func_002bda38(u8* p) {
    func_002be148(p);
    VObj2b* o = *(VObj2b**)(p + 16);
    while (o) {
        VObj2b* n = o->next;
        if (o) o->vt[1](o);                                
        o = n;
    }
    if (*(u32*)(p + 104)) func_00170950(*(u32*)(p + 104));
    func_001b86e0(*(u32*)(p + 4));                            
    func_00170320(-200);
    D_003617fc = 0;
    *(u32*)(p + 8) = (u32)D_003637e0;
}
}  // namespace n002bda38

// ---- 002bdac8 from src/anon/batch_w63.cpp
namespace n002bdac8 {
typedef void (*VFn)(void*);
void func_002be148(void*) asm("func_002be148");
void func_00170950(u32) asm("func_00170950");
void func_001b86e0(u32) asm("func_001b86e0");
void func_00170320(s32) asm("func_00170320");
union U003617fc { u32 v; u8 c; };
extern U003617fc D_003617fc asm("D_003617fc");
extern u8 D_003637e0[] asm("D_003637e0");
void func_002bdac8(u8* p) asm("func_002bdac8");
void func_002bdac8(u8* p) {
    func_002be148(p);
    u8* o = *(u8**)(p + 16);
    while (o) {
        u8* next = *(u8**)(o + 32);
        if (o) (*(VFn*)(*(u8**)o + 4))(o);                                
        o = next;
    }
    if (*(u32*)(p + 104)) func_00170950(*(u32*)(p + 104));
    func_001b86e0(*(u32*)(p + 4));                            
    func_00170320(-200);
    D_003617fc.v = 0;
    *(void**)(p + 8) = D_003637e0;
}
}  // namespace n002bdac8

// ---- 002bdb58 from src/anon/tiny.cpp
namespace n002bdb58 {
void func_001b84b8(s32) asm("_Z13func_001b84b8i");
void func_002bdb58(BD_VALUE* bd) asm("_Z13func_002bdb58P8BD_VALUE");
void func_002bdb58(BD_VALUE* bd) { func_001b84b8(bd[1].i); }
}  // namespace n002bdb58

