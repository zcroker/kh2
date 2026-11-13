#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"

// 001d4f40 (from src/anon/batch_w8017.c)
namespace n001d4f40 {
typedef struct T8 { u8 pad[0x2c]; s32 w2c; } T8;
f32 f_powf(f32, f32) asm("f_powf");
void _Z16wtarget_001d1b60jjjj(T8*, s32) asm("_Z16wtarget_001d1b60jjjj");
void func_001d4f40(T8* a0, s32 a1, s32 a2) asm("func_001d4f40");
void func_001d4f40(T8* a0, s32 a1, s32 a2) {
    a1 = (s32)(a1 * f_powf(0.5f, a2));
    if (a1 == 0) a1 = 1;
    _Z16wtarget_001d1b60jjjj(a0, a0->w2c + a1);
}
} // n001d4f40

// 001d4fa8 (from src/anon/tiny_auto80_solver.cpp)
namespace n001d4fa8 {
u32 func_001d1b60(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d1b60");
u32 func_001d4fa8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001d4fa8");
u32 func_001d4fa8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 offset = a1;
    u32 stride = *(u32*)(a0 + 568);
    u32 base = *(u32*)(a0 + 44);
    offset *= stride;
    base += offset;
    return func_001d1b60(a0, base, a2, a3, a4, a5, a6, a7);
}
} // n001d4fa8

// 001d4fd0 (from src/anon/tiny_wrappers_more.cpp)
namespace n001d4fd0 {
u32 func_001d1b60(u32, u32, u32, u32) asm("func_001d1b60");
u32 func_001d4fd0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d4fd0");
u32 func_001d4fd0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d1b60(a0, ((u32)(((u32)(*(u32*)((u32)(a0) + 44u)))) + (u32)(((u32)(*(u32*)((u32)(a0) + 576u))))), a2, a3);
}
} // n001d4fd0

// 001d4ff0 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d4ff0 {
u32 func_001b70d0(...) asm("func_001b70d0");
u32 func_001d4ff0(u8* a0) asm("func_001d4ff0");
u32 func_001d4ff0(u8* a0) {
    s32 d = *(s32*)(a0 + 568);
    s32 n = *(s32*)(a0 + 44);
    s32 q = (n + d - 1) / d;
    u32 v = *(u32*)(a0 + 572);
    if ((s32)v >= q) {
        v = (u32)q;
    }
    return func_001b70d0(v);
}
} // n001d4ff0

// 001d5030 (from src/anon/batch_w19.cpp)
namespace n001d5030 {
void* func_00168b38(u32, s32, s32) asm("func_00168b38");
extern u32 D_00352768 asm("D_00352768");
extern u32 D_01d5ba68 asm("D_01d5ba68");
void func_001d5030(u32 a) asm("func_001d5030");
void func_001d5030(u32 a) {
    D_00352768 = a;
    D_01d5ba68 = *(u32*)((u8*)func_00168b38(a, 2, 0) + 8);                         
}
} // n001d5030

// 001d5068 (from src/anon/batch_w59.cpp)
namespace n001d5068 {
extern u8* D_01d5ba68 asm("D_01d5ba68");
extern u8 D_00321790[] asm("D_00321790");
extern u32 D_00352768 asm("D_00352768");
u8* func_002fd248(u32, u8*, u32, u32, void*) asm("func_002fd248");
u8* func_00168b38(u32, u32, u8) asm("func_00168b38");
void func_0023cde8(u32) asm("func_0023cde8");
void func_001d5068(u32 key) asm("func_001d5068");
void func_001d5068(u32 key) {
    u8* t = D_01d5ba68;
    u8* r = func_002fd248(key, t + 8, *(u32*)(t + 4), 2, D_00321790);
    func_0023cde8(*(u32*)(func_00168b38(D_00352768, 47, r[1]) + 8));
}
} // n001d5068

// 001d50b8 (from src/anon/batch_w91.cpp)
namespace n001d50b8 {
struct B36 { u32 w[9]; };
u32 func_001bbb08(void) asm("func_001bbb08");
u32* func_001ba158(void) asm("func_001ba158");
void func_00199098(B36*, s32) asm("func_00199098");
u32 func_001d50b8(u8* p, B36* out) asm("func_001d50b8");
u32 func_001d50b8(u8* p, B36* out) {
    if (p[0] != 16) return 0;
    if (func_001bbb08() != 225) return 0;
    u32* wp = func_001ba158();
    u32 id = p[1];
    u32 w = *wp;
    if (w == id || ((w == 18 || w == 21) && (id == 18 || id == 21))) {
        B36 buf;
        func_00199098(&buf, 7);
        *out = buf;
        return 1;
    }
    return 0;
}
} // n001d50b8

// 001d5198 (from src/anon/batch_w56.cpp)
namespace n001d5198 {
struct T1d5 { u8 key; u8 val; u16 arg; };
extern T1d5 D_0036e538[] asm("D_0036e538");
u32* func_001ba158(u8*) asm("func_001ba158");
void func_00181178(u16) asm("func_00181178");
void func_001d5198(u8* p) asm("func_001d5198");
void func_001d5198(u8* p)
{
    if (p[0] != 16) return;
    u32* r = func_001ba158(p);
    for (u32 i = 0; i < 4; i++) {
        if (D_0036e538[i].key == p[1]) { *r = D_0036e538[i].val; func_00181178(D_0036e538[i].arg); return; }
    }
}
} // n001d5198

// 001d5218 (from src/anon/batch_w61.cpp)
namespace n001d5218 {
u32* func_001ba158(void) asm("func_001ba158");
void func_001963c8(u32) asm("func_001963c8");
struct Pair { s32 id; u32 val; };
extern Pair D_0036e548[4] asm("D_0036e548");
void func_001d5218(s32 id) asm("func_001d5218");
void func_001d5218(s32 id) {
    for (u32 i = 0; i < 4; i++) {
        if (D_0036e548[i].id == id) {
            *func_001ba158() = D_0036e548[i].val;
            break;
        }
    }
    if (id == 16414) func_001963c8(13);
}
} // n001d5218

// 001d52a0 (from src/anon/tiny_jal_wrappers.cpp)
namespace n001d52a0 {
u32 func_001d52c0(u32, u32, u32, u32) asm("func_001d52c0");
u32 func_001d52a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d52a0");
u32 func_001d52a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001d52c0(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
} // n001d52a0

// 001d52c0 (from src/anon/batch_wcx.cpp)
namespace n001d52c0 {
struct E8 { u16 id; u8 v[3]; u8 pad; u16 res; };
extern E8 D_0036e568[4] asm("D_0036e568");
s32 func_00181500(u16) asm("func_00181500");
u32 ctarget_001d52c0(u32, u32, u32, u32) asm("_Z16ctarget_001d52c0jjjj");
u32 ctarget_001d52c0(u32 a, u32 b, u32, u32)
{
    if (a != 16) return 0;
    for (u32 i = 0; i < 4; i++) {
        if (func_00181500(D_0036e568[i].id))
            for (s32 j = 0; j < 3; j++)
                if (D_0036e568[i].v[j] == b) return D_0036e568[i].res;
    }
    return 0;
}
} // n001d52c0

// 001d5370 (from src/anon/batch_w43.cpp)
namespace n001d5370 {
void* func_00168b38(u32, s32, s32) asm("func_00168b38");
void func_001d5370(u32* out, u32 a, s32 b) asm("func_001d5370");
void func_001d5370(u32* out, u32 a, s32 b) {
    u8* v = (u8*)func_00168b38(a, -1, b);                         
    u8* w = (u8*)func_00168b38(a, -1, b + 1);                         
    u32 x = *(u32*)(v + 8);
    u32 y = *(u32*)(w + 8);
    out[0] = x;
    out[1] = y;
}
} // n001d5370

// 001d53e8 (from src/anon/batch_w38.cpp)
namespace n001d53e8 {
u32 func_001b1490(const char*) asm("func_001b1490");
extern const char D_0036e598[] asm("D_0036e598");
extern u32 D_0035276c asm("D_0035276c");
u8* func_00168b88(u32, s32, u32, s32) asm("func_00168b88");
void func_001c10b8(u32) asm("func_001c10b8");
void func_001d53e8(void) asm("func_001d53e8");
void func_001d53e8(void) {
    u32 v = func_001b1490((const char*)D_0035276c);
    const char* s = D_0036e598;
    func_001c10b8(*(u32*)(func_00168b88(v, -1, s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24), 0) + 8));
}
} // n001d53e8

// 001d5450 (never written before)
namespace n001d5450 {
void func_001d5450(void* self) asm("func_001d5450");
void func_001d5450(void* self) {}
} // n001d5450

// 001d5458 (from src/anon/misc_1.cpp)
namespace n001d5458 {
void func_001d5458(void* self) asm("func_001d5458");
void func_001d5458(void* self) {}
} // n001d5458

// 001d5460 (from src/anon/tiny_leaf.cpp)
namespace n001d5460 {
u32 func_001d5460(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d5460");
u32 func_001d5460(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = (u32)(*(u8*)((u32)r4 + (s32)(8)));
    r2 = (u32)(r2 ^ 0x001eu);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
} // n001d5460

// 001d5470 (from src/anon/batch_wcx2.cpp)
namespace n001d5470 {
u8* func_00168b38_5470(u32, s32, u32) asm("func_00168b38");
void func_001d5370(u32*, u32, s32) asm("func_001d5370");
union UA_001d5470 { u32 i; u16 h; u8 b; };
void func_001d5470(u32* s, u32 a1, u8* a2) asm("func_001d5470");
void func_001d5470(u32* s, u32 a1, u8* a2) {
    s[1] = *(u32*)(func_00168b38_5470(a1, -1, ((UA_001d5470*)(a2 + 4))->b) + 8);
    s[2] = ((UA_001d5470*)(a2 + 6))->h;
    if (!((UA_001d5470*)(a2 + 5))->b) return;
    if (s[0] == 12) s[0] = 13;
    func_001d5370(s + 3, a1, ((UA_001d5470*)(a2 + 5))->b - 1);
}
} // n001d5470

// 001d5518 (from src/anon/batch_w93.cpp)
namespace n001d5518 {
struct W93Spec { u32 f0; u32 f4; u32 kind; u32 f12; u32 f16; u32 f20; u32 f24; };
struct W93Ef { u32 flags; u8 pad[4]; u32 f8; u8 p2[64 - 12]; u8 f64[148 - 64]; u32 f148; u32 f152; u32 f156; u32 f160; };
void* func_001050d8(u32) asm("func_001050d8");
void func_00196ca8(W93Ef*, u32, u32) asm("func_00196ca8");
u32 func_0016b740(u32) asm("func_0016b740");
void func_00196e98(W93Ef*, u32) asm("func_00196e98");
void func_00196f00(W93Ef*) asm("func_00196f00");
void func_001d30f8(void*, s32, s32) asm("func_001d30f8");
u32 func_00185de0(void) asm("func_00185de0");
extern u32 D_00350438 asm("D_00350438");
void func_001d5518(W93Spec* s, u32 a, u8 flag) asm("func_001d5518");
void func_001d5518(W93Spec* s, u32 a, u8 flag)
{
    if (s->f4 == 0) return;
    W93Ef* o = (W93Ef*)func_001050d8(176);
    func_00196ca8(o, s->f0, s->f4);
    o->f8 = a;
    if (flag) o->flags |= 8;
    o->f148 = s->f12;
    o->f152 = s->f16;
    if (s->f24) {
        o->f156 = 2;
        o->f160 = s->f24;
    } else if (s->f20) {
        o->f156 = s->f20;
    }
    switch (s->kind) {
    case 0: break;
    case 902: func_00196e98(o, func_00185de0()); break;
    case 1679: func_001d30f8(o->f64, 4, 0); break;
    case 1726: func_00196e98(o, D_00350438); break;
    default: func_00196e98(o, func_0016b740(s->kind)); break;
    }
    func_00196f00(o);
}
} // n001d5518

// 001d5668 (from src/anon/auto200_999.cpp)
namespace n001d5668 {
extern u8 D_0032fae4 asm("D_0032fae4");
u32 func_001d5668(u32 a0) asm("func_001d5668");
u32 func_001d5668(u32 a0) {
    u32 idx = a0 >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032fae4 + (idx << 2));
    u32 bit = a0 & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    return (val & mask) != 0;
}
} // n001d5668

// 001d5698 (from src/anon/auto200_999.cpp)
namespace n001d5698 {
extern u8 D_0032fae4 asm("D_0032fae4");
void func_001d5698(u32 a0) asm("func_001d5698");
void func_001d5698(u32 a0) {
    u32 idx = a0 >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032fae4 + (idx << 2));
    u32 bit = a0 & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    val |= mask;
    *p = val;
}
} // n001d5698

// 001d56c8 (from src/anon/tiny.cpp)
namespace n001d56c8 {
extern u32 D_0032f8e4 asm("D_0032f8e4");
u32 func_001d56c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d56c8");
u32 func_001d56c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_0032f8e4 + ((u32)a0 << 3);
}
} // n001d56c8

// 001d56e0 (never written before)
namespace n001d56e0 {
void func_001d56e0(u32* p) asm("func_001d56e0");
void func_001d56e0(u32* p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}
} // n001d56e0

// 001d56f0 (from src/anon/tiny_more2.cpp)
namespace n001d56f0 {
void func_001d56f0(u32 a0,u32 a1,u32 a2,u32 a3) asm("func_001d56f0");
void func_001d56f0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; *(u32*)((u32)a0 + (0)) = 0; *(u32*)((u32)a0 + (4)) = 0; *(u32*)((u32)a0 + (8)) = 0; }
} // n001d56f0

// 001d5700 (from src/anon/tiny.cpp)
namespace n001d5700 {
void func_001d5730(void*) asm("func_001d5730");
void func_001d5700(BD_VALUE* bd) asm("func_001d5700");
void func_001d5700(BD_VALUE* bd) { func_001d5730(bd); }
} // n001d5700

// 001d5718 (from src/anon/tiny.cpp)
namespace n001d5718 {
void func_001d5730(void*) asm("func_001d5730");
void func_001d5718(BD_VALUE* bd) asm("func_001d5718");
void func_001d5718(BD_VALUE* bd) { func_001d5730(bd); }
} // n001d5718

// 001d5730 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d5730 {
u32 func_002bc358(...) asm("func_002bc358");
void func_001d5730(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001d5730");
void func_001d5730(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = r15;
    if (r15 != 0u) {
        r5 = (u32)((s32)0u + (10));
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002bc358)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(8)) = 0u;
        *(volatile u32*)((u32)r16 + (s32)(0)) = 0u;
        *(volatile u32*)((u32)r16 + (s32)(4)) = 0u;
    }
}
} // n001d5730

// 001d5770 (from src/anon/auto80_199_queue.cpp)
namespace n001d5770 {
void func_001d5770(u32* a0, u32 a1) asm("func_001d5770");
void func_001d5770(u32* a0, u32 a1) {
    u32* s16 = a0;
    u32 s17 = a1;
    u32 t6 = s16[2];

    if (t6 != 0) {
        if (s16[1] != t6) {
            func_001d5730();
            u32 v0 = func_002bc188(s16[2], s17);
            s16[0] = v0;
            s16[1] = s16[2];
        }

        if (s16[0] != 0) {
            func_002bc398(s16[0], s17);
        }
        s16[2] = 0;
        return;
    }

    func_001d5730();
}
} // n001d5770

// 001d5800 (from src/anon/auto80_199_queue.cpp)
namespace n001d5800 {
void func_001d5800(u16* a0) asm("func_001d5800");
void func_001d5800(u16* a0) {
    u32 t6 = a0[0];
    if (t6 == 2) goto L2;
    if ((s32)t6 < 3) {
        if (t6 != 1) goto Lret;
        goto L1;
    }
    if (t6 != 3) goto Lret;
    func_001a6c90(a0[1]);                       
    return;

L1:
    func_00181178(a0[1]);
    return;

L2:
    func_001b8838(a0[1]);
    return;

Lret:
    return;
}
} // n001d5800

// 001d5868 (from src/anon/batch_w44.cpp)
namespace n001d5868 {
u8 func_00181500(u16) asm("func_00181500");
u8 func_001b8958(u16) asm("func_001b8958");
u8 func_001a6d08(u16) asm("func_001a6d08");
u8 func_001d5868(u16* p) asm("func_001d5868");
u8 func_001d5868(u16* p) {
    switch (p[0]) {
    case 1: return func_00181500(p[1]);
    case 2: return func_001b8958(p[1]);
    case 3: return func_001a6d08(p[1]);
    }
    return 0;
}
} // n001d5868

// 001d58e0 (from src/anon/tiny.cpp)
namespace n001d58e0 {
void func_001d58e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d58e0");
void func_001d58e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d6u << 16);
    *(u32*)((u32)b + (-17812)) = (u32)a0;
}
} // n001d58e0

// 001d58f0 (from src/anon/auto80_199_queue.cpp)
namespace n001d58f0 {
u32 func_001d58f0(u32 a0) asm("func_001d58f0");
u32 func_001d58f0(u32 a0) {
    s32 s17 = 12;
    s32 s18 = 0;
    u32 s19 = a0;
    u32 s16 = a0 + 4;

    do {
        u32 v0 = func_001d5868(s16);
        s17 = s17 - 1;
        s16 = s16 + 4;
        s32 t15 = s18 + 1;
        if (v0 != 0) {
            s18 = t15;
        }
    } while ((s32)s17 >= 0);

    s32 v2 = *(s32*)(s19 + 56);
    u32 v = (s18 < v2);
    v = v ^ 1;
    return v;
}
} // n001d58f0

// 001d5960 (from src/anon/batch_w60.cpp)
namespace n001d5960 {
s32 func_001d5868(void*) asm("func_001d5868");
s32 func_001d58f0(void*) asm("func_001d58f0");
void func_001d5800(void*) asm("func_001d5800");
void func_001d5960(void* p) asm("func_001d5960");
void func_001d5960(void* p) {
    if (!func_001d5868(p) && func_001d58f0(p)) func_001d5800(p);
}
} // n001d5960

// 001d59b0 (from src/anon/batch_w38.cpp)
namespace n001d59b0 {
struct Item1d59b0 { u8 d[60]; };
struct Tbl1d59b0 { u32 f0; s32 count; Item1d59b0 items[1]; };
extern Tbl1d59b0* D_01d5ba6c asm("D_01d5ba6c");
void func_001d5960(void*) asm("func_001d5960");
void func_001d59b0(void) asm("func_001d59b0");
void func_001d59b0(void) {
    for (s32 i = 0; i < D_01d5ba6c->count; i++) func_001d5960(&D_01d5ba6c->items[i]);
}
} // n001d59b0

// 001d5a20 (from src/anon/tiny_wrappers_more.cpp)
namespace n001d5a20 {
u32 func_001d5a48(u32, u32, u32, u32) asm("func_001d5a48");
u32 func_001d5a20(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d5a20");
u32 func_001d5a20(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d5a48(a0, a1, a2, a3);
}
} // n001d5a20

// 001d5a38 (from src/anon/tiny.cpp)
namespace n001d5a38 {
extern u32 D_00352770 asm("D_00352770");
void func_001d5a38(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d5a38");
void func_001d5a38(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_00352770 = (u8)v;
}
} // n001d5a38

// 001d5a48 (from src/anon/tiny.cpp)
namespace n001d5a48 {
void func_001d5a48(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d5a48");
void func_001d5a48(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u8*)((u32)b + (10096)) = (u8)0;
}
} // n001d5a48

// 001d5a58 (from src/anon/batch_w2369.cpp)
namespace n001d5a58 {
struct Blk36 { u32 w[9]; };
extern u8 D_00352770 asm("D_00352770");
extern u8 D_00350379 asm("D_00350379");
s32 func_001bb4a0(void) asm("func_001bb4a0");
void func_00199098(Blk36*, s32) asm("func_00199098");
s32 func_001d5a58(void* self, Blk36* out) asm("func_001d5a58");
s32 func_001d5a58(void* self, Blk36* out) {
    if (D_00352770 == 0 || D_00350379 == 0 || func_001bb4a0() != 0) return 0;
    Blk36 t;
    func_00199098(&t, 0);
    *out = t;
    return 1;
}
} // n001d5a58

// 001d5af8 (from src/anon/auto80_199_queue.cpp)
namespace n001d5af8 {
u32 func_001d5af8(u8* a0, s32 a1, u32 a2) asm("func_001d5af8");
u32 func_001d5af8(u8* a0, s32 a1, u32 a2) {
    u32 v0 = 0;
    s32 t6 = a0[0];
    u32 t7;
    if (a1 < t6) {
        return v0;
    }

    if (a1 == 4 || a1 == 6) {
        if (a1 != t6) {
            *(u32*)(a0 + 4) = a2;
            goto L_set;
        }
        t7 = *(u32*)(a0 + 4);
        v0 = 0;
        t7 = (a2 < t7);
        if (t7 == 0) {
            return 0;
        }
        *(u32*)(a0 + 4) = a2;
        goto L_set;
    }

    if (a1 != t6) {
        *(u32*)(a0 + 4) = a2;
        goto L_set;
    }

    t7 = *(u32*)(a0 + 4);
    v0 = 0;
    t7 = (t7 < a2);
    if (t7 == 0) {
        return 0;
    }
    *(u32*)(a0 + 4) = a2;

L_set:
    v0 = 1;
    a0[0] = a1;
    return v0;
}
} // n001d5af8

// 001d5b68 (from src/anon/tiny.cpp)
namespace n001d5b68 {
void func_001d5b68(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d5b68");
void func_001d5b68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d6u << 16);
    *(u32*)((u32)b + (-17808)) = (u32)a0;
}
} // n001d5b68

// 001d5b78 (from src/anon/batch_w15.cpp)
namespace n001d5b78 {
u8 func_002fd248(u32, void*, u32, u32, void*) asm("func_002fd248");
extern u8* D_01d5ba70 asm("D_01d5ba70");
extern u8 D_003217a0 asm("D_003217a0");
u8 func_001d5b78(u32 a, u32 b) asm("func_001d5b78");
u8 func_001d5b78(u32 a, u32 b) {
    u8* t = D_01d5ba70;
    return func_002fd248((a << 4) | b, t + 8, *(u32*)(t + 4), 8, &D_003217a0);
}
} // n001d5b78

// 001d5bb8 (from src/anon/auto80_199_queue.cpp)
namespace n001d5bb8 {
u32 func_001d5bb8() asm("func_001d5bb8");
u32 func_001d5bb8() {
    u32 s16 = 1;
    u32 s17 = 2;

    do {
        u32 v0 = func_001a36e0(s16);
        s16 = s16 + 1;
        s32 v1 = func_001a3570(v0);
        v0 = (0 < v1);
        s17 = s17 + v0;
    } while ((s32)s16 < 6);

    return s17;
}
} // n001d5bb8

// 001d5c10 (from src/anon/auto80_199_queue.cpp)
namespace n001d5c10 {
u32 func_001d5bb8() asm("func_001d5bb8");
u32 func_001d5c10(u32 a0, u8* a1) asm("func_001d5c10");
u32 func_001d5c10(u32 a0, u8* a1) {
    u32 t14 = func_001d5bb8();
    u32 t15 = a1[2];
    if ((s32)t15 < (s32)t14) {
        return func_001d5b78(a0, t15);
    }
    return 0;
}
} // n001d5c10

// 001d5c70 (from src/anon/auto80_199_queue.cpp)
namespace n001d5c70 {
u32 func_001d5c70(u32 a0, u8* a1) asm("func_001d5c70");
u32 func_001d5c70(u32 a0, u8* a1) {
    u8* s16 = a1;
    u32 v0 = func_001d5b78(a0, 1);
    u32 t4 = s16[2];
    u32 t5 = 1;
    u32 t6 = *(u32*)(s16 + 4);

    if ((s32)t5 < (s32)t4) {
        t5 = t4 - 1;
        do {
            u32 t7 = *(u32*)(v0 + 4);
            t5 = t5 - 1;
            t6 = t6 + t7;
            if (t5 != 0) {
                v0 = v0 + 8;
            }
        } while (t5 != 0);
    }

    return t6;
}
} // n001d5c70

// 001d5cd0 (from src/anon/batch_wcx2.cpp)
namespace n001d5cd0 {
s32 func_001d6ec8() asm("func_001d6ec8");
s32 func_001d5b78(u32, u32) asm("func_001d5b78");
struct G_001d5cd0 { u8 pad[4150]; u8 c; };
extern G_001d5cd0 D_0032e020 asm("D_0032e020");
s32 func_001d5cd0() asm("func_001d5cd0");
s32 func_001d5cd0() {
    G_001d5cd0* g = &D_0032e020;
    s32 n = func_001d6ec8();
    if (g->c < n) return func_001d5b78(0, g->c);
    return 0;
}
} // n001d5cd0

// 001d5d20 (from src/anon/batch_w48.cpp)
namespace n001d5d20 {
struct G32bb30 { u8 pad[13606]; u8 n; u8 pad2[14052 - 13607]; s32 total; u8 pad3[8]; u8 pad4[8]; u16 cur[4]; };
extern G32bb30 D_0032bb30 asm("D_0032bb30");
u8* func_001d5b78(s32, s32) asm("func_001d5b78");
s32 func_001d5d20(void) asm("func_001d5d20");
s32 func_001d5d20(void) {
    u8* e = func_001d5b78(0, 1);
    s32 v = D_0032bb30.total;
    s32 n = D_0032bb30.n;
    s32 i = 1;
    if (i < n) {
        i = n - 1;
        do {
            v += *(s32*)(e + 4);
            i--;
            asm volatile("nop\n\tnop");
            e += 8;
        } while (i != 0);
    }
    return v;
}
} // n001d5d20

// 001d5d80 (from src/anon/batch_w8009_nsa.cpp)
namespace n001d5d80 {
struct Buf1d5d80 { u8 d[80]; };
struct Ent1d5d80 { u8 pad0; u8 n; u16 snd; };
struct Cnt1d5d80 { u8 pad[2]; u8 cnt; u8 pad2[5]; u8 tbl[1]; };
struct Sub1d5d80 { u8 pad[580]; u8* tbl; Cnt1d5d80* c; };
struct Obj1d5d80 { u8 pad[1164]; Sub1d5d80* sub; };
struct NoTail1d5d80 { ~NoTail1d5d80() {} };
Ent1d5d80* func_001d5b78(void*, u8) asm("func_001d5b78");
void func_001b74b8(Buf1d5d80*) asm("func_001b74b8");
void func_001b74c8(Buf1d5d80*, s32) asm("func_001b74c8");
s32 func_001d5ec0(void*, s32, void*, s32) asm("func_001d5ec0");
void func_001b7538(Buf1d5d80*, s32) asm("func_001b7538");
void func_001a3188(s32, s32, s32) asm("func_001a3188");
void func_001b76c8(Buf1d5d80*, void*, s32) asm("func_001b76c8");
void func_001a1460(Sub1d5d80*) asm("func_001a1460");
void func_001d7778(void) asm("func_001d7778");
void func_001d5d80(Obj1d5d80* o, void* a) asm("func_001d5d80");
void func_001d5d80(Obj1d5d80* o, void* a) {
    NoTail1d5d80 nt; s32 r;
    Buf1d5d80 b0, b1;
    Sub1d5d80* s = o->sub;
    Cnt1d5d80* c = s->c;
    u8* t = s->tbl;
    Ent1d5d80* e = func_001d5b78(a, ++c->cnt);
    func_001b74b8(&b0);
    func_001b74b8(&b1);
    func_001b74c8(&b0, 0xc3f2);
    if (((u8*)e)[-7] < e->n) {
        r = func_001d5ec0(c->tbl, 24, a, e->n); func_001b7538(&b0, r);
        r = func_001d5ec0(t + 84, 80, a, e->n - 1); func_001b7538(&b1, r);
    }
    if (e->snd) {
        func_001a3188(e->snd, 1, 0);
        func_001b7538(&b1, e->snd);
    }
    func_001b76c8(&b0, a, c->cnt);
    func_001b76c8(&b1, 0, c->cnt);
    func_001a1460(o->sub);
    func_001d7778();
}
} // n001d5d80

// 001d5ec0 (from src/anon/batch_w39.cpp)
namespace n001d5ec0 {
struct Row1d5 { u16 v[5]; };
extern Row1d5 D_0036e5a0[] asm("D_0036e5a0");
u16 func_001d5ec0(u16* p, int n, int a, int b) asm("func_001d5ec0");
u16 func_001d5ec0(u16* p, int n, int a, int b) {                          
    Row1d5* r = &D_0036e5a0[a - 1];
    u16* e = &r->v[b];
    u16 from = e[-1];
    u16 to = e[0];
    for (int i = 0; i < n; i++, p++) {
        if ((*p & 0x7fff) == from) {
            *p = (*p & 0x8000) | (to & 0x7fff);
            return to;
        }
    }
    return to;
}
} // n001d5ec0

// 001d5f30 (from src/anon/batch_w90.cpp)
namespace n001d5f30 {
s32 func_001bbb28(void*) asm("func_001bbb28");
struct Level { u32 a; s32 v; };
extern u8 D_0032e020[] asm("D_0032e020");
Level* func_00189200(void*, u32) asm("func_00189200");
Level* func_001d5c10(u32, Level*) asm("func_001d5c10");
void func_001d5d80(void*, u32) asm("func_001d5d80");
void func_001b7468(void*) asm("func_001b7468");
void func_001d5f30(u8* self, s32 add) asm("func_001d5f30");
void func_001d5f30(u8* self, s32 add)
{
    if (func_001bbb28(self)) return;
    u32 k = *(u32*)(self + 2896);
    s32 up = 0;
    Level* e = func_00189200(D_0032e020, k);
    e->v += add;
    for (;;) {
        Level* nx = func_001d5c10(k, e);
        if (!nx) { e->v = 0; break; }
        if (e->v < nx->v) break;
        func_001d5d80(self, k);
        up = 1;
        e->v -= nx->v;
    }
    if (up) func_001b7468(self);
}
} // n001d5f30

// 001d6020 (from src/anon/auto80_199_queue.cpp)
namespace n001d6020 {
void func_001d6020(u32 a0, u32 a1) asm("func_001d6020");
void func_001d6020(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 t7 = *(u32*)(s16 + 28);
    if (func_0019ba60(*(u32*)(t7 + 8)) == 0) {
        return;
    }

    u32 t6 = *(u32*)(s16 + 28);
    u32 p = *(u32*)(t6 + 8);
    u32 t = *(u32*)(p + 1416) & 0x80;
    if (t == 0) {
        return;
    }
    if (*(u32*)(p + 2896) != 1) {
        return;
    }
    func_001d5f30(p, 1);
}
} // n001d6020

// 001d6088 (from src/anon/batch_w62.cpp)
namespace n001d6088 {
s32 func_0019c898(u32) asm("func_0019c898");
void func_001d5f30(u8*, u32) asm("func_001d5f30");
void func_001d6088(u32 id, u8* o) asm("func_001d6088");
void func_001d6088(u32 id, u8* o) {
    switch (*(s32*)(o + 2896)) {
    case 2:
        if (id - 1000 >= 1012) return;
        if (func_0019c898(id)) return;
        break;
    case 5:
        if (id - 3000 >= 1015) return;
        break;
    default:
        return;
    }
    func_001d5f30(o, 1);
}
} // n001d6088

// 001d6110 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d6110 {
void func_001d5f30(...) asm("func_001d5f30");
void func_001d6110(u32 a0, u8* a1) asm("func_001d6110");
void func_001d6110(u32 a0, u8* a1) {
    if (*(u32*)(a1 + 2896) != 4) {
        return;
    }
    func_001d5f30((u32)a1, a0);
}
} // n001d6110

// 001d6148 (from src/anon/batch_w40.cpp)
namespace n001d6148 {
void func_001d5f30(u8*, u32) asm("func_001d5f30");
void func_001d6148(u8* p, s32 id) asm("func_001d6148");
void func_001d6148(u8* p, s32 id) {
    if (*(s32*)(p + 2896) == 3) {
        switch (id) {
        case 686: case 700: case 703: case 706:
            func_001d5f30(p, 1);
        }
    }
}
} // n001d6148

// 001d61b8 (from src/anon/batch_w79.cpp)
namespace n001d61b8 {
u8* func_00189200(void*, s32) asm("func_00189200");
s32 func_001d62b0(void*, void*) asm("func_001d62b0");
s32 func_001917c0(void) asm("func_001917c0");
s32 func_001d63a8(void*) asm("func_001d63a8");
void func_001a32c8(s32, s32) asm("func_001a32c8");
extern u8* D_00352130 asm("D_00352130");
extern u8 D_0032e020[] asm("D_0032e020");
static inline void sub_clamp(u8* e, s32 d) {
    s32 x = *(s32*)(e + 4) - d;
    if (x < 0) x = 0;
    *(s32*)(e + 4) = x;
}
s32 func_001d61b8(void* a, s32 b) asm("func_001d61b8");
s32 func_001d61b8(void* a, s32 b) {
    u8* e = func_00189200(D_0032e020, 6);
    if (b == 5) {
        sub_clamp(e, *(s32*)(D_00352130 + 164));
        return 5;
    }
    if (!func_001d62b0(a, e)) return b;
    if (!func_001917c0()) return b;
    if (func_001d63a8(a)) {
        func_001a32c8(29, 1);
        sub_clamp(e, *(s32*)(D_00352130 + 164));
        return 5;
    }
    sub_clamp(e, *(s32*)(D_00352130 + 144));
    return 6;
}
} // n001d61b8

// 001d62b0 (from src/anon/batch_w91.cpp)
namespace n001d62b0 {
u32 func_001c99b0(s32) asm("func_001c99b0");
struct R8 { u8 a; u8 b; u8 pad[2]; s32 v; };
R8* func_001d5b78(s32, s32) asm("func_001d5b78");
u8* func_00177860(u8*) asm("func_00177860");
s32 func_001bbcc0(void) asm("func_001bbcc0");
u64 func_00312db8(u64, u64) asm("func_00312db8");
extern u32 D_003638d0 asm("D_003638d0");
u32 func_001d62b0(u8* who, u8* st) asm("func_001d62b0");
u32 func_001d62b0(u8* who, u8* st) {
    s32 r = 0;
    if (func_001c99b0(6)) return r;
    R8* e = func_001d5b78(6, 1);
    s32 lv = *(s32*)(st + 4);
    while (lv < e->v) e++;
    s32 chance = 100;
    if (!(*(u32*)(func_00177860(who) + 20) & 0x8000)) chance = e->b * func_001bbcc0();
    D_003638d0 = D_003638d0 * 0x10dcd;
    s32 v = func_00312db8(D_003638d0, 42949673);
    *(s32*)(st + 4) += 1;
    r = v < chance;
    return r;
}
} // n001d62b0

