#include "../yasui/libys/stop.hpp"
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
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"

// 001d7458 (from src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n001d7458 {
u32 func_001a4db0(u32, u32, u32, u32) asm("func_001a4db0");
extern u8 D_003527f0 asm("D_003527f0");
u32 func_001d7458(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d7458");
u32 func_001d7458(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_003527f0;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(10212)) = r16;
    return r2;
}
} // n001d7458

// 001d7498 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001d7498 {
u32 func_001a4e30(u32, u32, u32, u32) asm("func_001a4e30");
extern u8 D_003527f0 asm("D_003527f0");
u32 func_001d7498(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d7498");
u32 func_001d7498(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_003527f0;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(10212)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
} // n001d7498

// 001d74c8 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001d74c8 {
u32 func_001a4e30(u32, u32, u32, u32) asm("func_001a4e30");
extern u8 D_003527f0 asm("D_003527f0");
u32 func_001d74c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d74c8");
u32 func_001d74c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_003527f0;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(10212)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
} // n001d74c8

// 001d74f8 (from src/anon/batch_w21.cpp)
namespace n001d74f8 {
void func_00105110(void*) asm("func_00105110");
void func_001a4e30(void*) asm("func_001a4e30");
extern u32 D_003527f0 asm("D_003527f0");
extern void* D_003527e4 asm("D_003527e4");
void func_001d74f8(void** p) asm("func_001d74f8");
void func_001d74f8(void** p) {
    *p = &D_003527f0;
    D_003527e4 = 0;
    func_001a4e30(p);
    func_00105110(p);
}
} // n001d74f8

// 001d7538 (from src/anon/batch_w91.cpp)
namespace n001d7538 {
u32* func_001ba158(void) asm("func_001ba158");
extern u32 D_003527e4 asm("D_003527e4");
f32 func_00191b70(void) asm("func_00191b70");
s32 func_001a5bd0(u8*, s32, f32) asm("func_001a5bd0");
void func_001d7638(u8*, s32) asm("func_001d7638");
s32 func_001d9228(s32) asm("func_001d9228");
void func_001d7538(u8* p, u8* q) asm("func_001d7538");
void func_001d7538(u8* p, u8* q) {
    if (!D_003527e4) return;
    f32 x = func_00191b70();
    if ((s32)func_001ba158()[5] > 0) x += x;
    for (s32 k = 0; k < 9; k++)
        for (s32 j = 0; j < func_001a5bd0(q, k, x); j++) func_001d7638(p, 1);
    s32 n = func_001d9228(0) / 2;
    if (n >= 7) n = 6;
    for (s32 i = 0; i < n; i++) func_001d7638(p, 0);
}
} // n001d7538

// 001d7638 (from src/anon/batch_w58.cpp)
namespace n001d7638 {
s32 func_001bb4a0(void) asm("func_001bb4a0");
struct E16b { u8 pad[16]; };
extern E16b D_0036e600[] asm("D_0036e600");
extern u32 D_0036e620[] asm("D_0036e620");
extern u32 D_003527e4 asm("D_003527e4");
u8* func_001a5420(u32, void*, u32) asm("func_001a5420");
void func_001d76c8(void) asm("func_001d76c8");
void func_001d8718(u32, s32) asm("func_001d8718");
u8* func_001ba158(void) asm("func_001ba158");
void func_001d7638(u32 a0, s32 i) asm("func_001d7638");
void func_001d7638(u32 a0, s32 i) {
    u8* r = func_001a5420(D_003527e4, &D_0036e600[i], a0);
    if (!r) return;
    u32 v = D_0036e620[i];
    *(void**)(r + 16) = (void*)func_001d76c8;
    if (!func_001bb4a0()) return;
    func_001d8718(v, 0);
    *(u32*)(func_001ba158() + 4) += v;
}
} // n001d7638

// 001d76c8 (from src/anon/tiny_jal_wrappers.cpp)
namespace n001d76c8 {
u32 func_001d7730(u32, u32, u32, u32) asm("func_001d7730");
u32 func_001d76c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d76c8");
u32 func_001d76c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001d7730(r4, r5, r6, r7);
    r2 = (u32)((s32)0u + (1));
    return r2;
}
} // n001d76c8

// 001d76e8 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d76e8 {
void func_001c79a0(...) asm("func_001c79a0");
extern u8 D_0034e948 asm("D_0034e948");
void func_001d76e8(u32 a0, u8* a1) asm("func_001d76e8");
void func_001d76e8(u32 a0, u8* a1) {
    (void)a0;
    if (a1[68] == 0) {
        return;
    }
    if (!(0.0f < *(f32*)(a1 + 52))) {
        return;
    }
    func_001c79a0((u32)a1, *(u32*)&D_0034e948, 0);
}
} // n001d76e8

// 001d7730 (from src/anon/batch_w208.cpp)
namespace n001d7730 {
struct VT208 { void* f[22]; void (*fn)(void*, void*); };
struct Obj208 { VT208* vt; };
struct O80_208 { char pad[80]; Obj208* o; };
u8 func_001c71f8(u32 p, f32 f) asm("func_001c71f8");
void ctarget_001d7730(u32, u32, u32, u32) asm("_Z16ctarget_001d7730jjjj");
void ctarget_001d7730(u32 a, u32, u32, u32) {
    O80_208* s = (O80_208*)a;
    func_001c71f8(a, -0.8f);
    Obj208* o = s->o;
    o->vt->fn(o, s);
}
} // n001d7730

// 001d7778 (from src/anon/tiny_auto80_fptr0.cpp)
namespace n001d7778 {
u32 func_001d77a0() asm("func_001d77a0");
u32 func_001d7828() asm("func_001d7828");
u32 func_001d7880() asm("func_001d7880");
u32 func_001d7778(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d7778");
u32 func_001d7778(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_001d77a0)() = func_001d77a0;
    r2 = fp_call0_001d77a0();
    u32 (*fp_call0_001d7828)() = func_001d7828;
    r2 = fp_call0_001d7828();
    return func_001d7880();
}
} // n001d7778

// 001d77a0 (from src/anon/batch_w56.cpp)
namespace n001d77a0 {
s32 func_001a6d08(s32) asm("func_001a6d08");
u8* func_00189200(void*, s32) asm("func_00189200");
void func_001a6c90(s32) asm("func_001a6c90");
extern u8 D_0032e020[] asm("D_0032e020");
void u_call0_001d77a0(void) asm("_Z16u_call0_001d77a0v");
void u_call0_001d77a0(void)
{
    if (func_001a6d08(106)) return;
    if (!func_001a6d08(101)) return;
    for (s32 i = 1; i < 5; i++) {
        if (func_00189200(D_0032e020, i)[2] < 5) return;
    }
    func_001a6c90(106);                       
}
} // n001d77a0

// 001d7828 (from src/anon/auto80_199_queue.cpp)
namespace n001d7828 {
void func_001d7828() asm("func_001d7828");
void func_001d7828() {
    if (func_001a6d08(103) != 0) {
        return;
    }

    if (func_001a6d08(101) != 0) {
        if (D_0032f056[0] >= 5) {
            func_001a6c90(103);                       
            return;
        }
    }
}
} // n001d7828

// 001d7880 (from src/anon/batch_w89.cpp)
namespace n001d7880 {
s32 func_001a6d08(u32) asm("func_001a6d08");
void func_001a6c90(u32) asm("func_001a6c90");
s32 func_00181500(u16) asm("func_00181500");
u8* func_00189200(u8*, s32) asm("func_00189200");
extern u16 D_0036e628[] asm("D_0036e628");
extern u8 D_0032e020 asm("D_0032e020");
extern u8 D_0032f056 asm("D_0032f056");
void u_tail0_001d7880(void) asm("_Z16u_tail0_001d7880v");
void u_tail0_001d7880(void) {
    if (func_001a6d08(104)) return;
    u16* p = D_0036e628;
    for (u32 i = 0; i < 11; i++)
        if (!func_00181500(*p++)) return;
    for (s32 j = 1; j < 6; j++)
        if (func_00189200(&D_0032e020, j)[2] < 7) return;
    if (D_0032f056 < 7) return;
    func_001a6c90(104);                       
}
} // n001d7880

// 001d7940 (from src/anon/batch_w10.cpp)
namespace n001d7940 {
u8* func_001ba158(void) asm("func_001ba158");
void func_001ada38(s32) asm("func_001ada38");
void func_001d7940(void) asm("func_001d7940");
void func_001d7940(void) {
    u8* v = func_001ba158();
    *(u32*)(v + 4) = 0;
    *(u32*)(v + 12) = 0;
    *(u32*)(v + 20) = 0;
    *(u32*)(v + 24) = 0;
    func_001ada38(12);
}
} // n001d7940

// 001d7970 (from src/anon/tiny.cpp)
namespace n001d7970 {
void func_001d7970(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d7970");
void func_001d7970(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d6u << 16);
    *(u32*)((u32)b + (-17764)) = (u32)a0;
}
} // n001d7970

// 001d7980 (from src/anon/batch_w20.cpp)
namespace n001d7980 {
u8 func_002fd248(u32, u8*, u32, u32, void*) asm("func_002fd248");
extern u8* D_01d5ba9c asm("D_01d5ba9c");
extern u8 D_003218b8[] asm("D_003218b8");
u8 func_001d7980(u32 a) asm("func_001d7980");
u8 func_001d7980(u32 a) {
    u8* t = D_01d5ba9c;
    return func_002fd248(a, t + 8, *(u32*)(t + 4), 4, D_003218b8);
}
} // n001d7980

// 001d79b8 (from src/anon/batch_wcx2.cpp)
namespace n001d79b8 {
struct E_001d79b8 { s32 key; f32 v; };
struct P_001d79b8 { u32 x; E_001d79b8 e[4]; };
void func_001d7b10(P_001d79b8*) asm("func_001d7b10");
void func_001d79b8(P_001d79b8* p, s32 key, f32 v) asm("func_001d79b8");
void func_001d79b8(P_001d79b8* p, s32 key, f32 v) {
    E_001d79b8* r = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (p->e[i].key == key) { r = &p->e[i]; break; }
        if (p->e[i].key == 0) r = &p->e[i];
    }
    r->key = key;
    r->v = v;
    func_001d7b10(p);
}
} // n001d79b8

// 001d7a08 (from src/anon/batch_w30.cpp)
namespace n001d7a08 {
void func_001d7b10(u32, u32) asm("func_001d7b10");
void wtarget_001d7a08(u32, u32, u32, u32) asm("_Z16wtarget_001d7a08jjjj");
void wtarget_001d7a08(u32 a, u32 b, u32, u32) {
    u32* p = (u32*)a;
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (p[1] == b) {
            p[1] = 0;
            func_001d7b10(a, b);
            return;
        }
        p += 2;
    }
}
} // n001d7a08

// 001d7a50 (from src/anon/batch_w18.cpp)
namespace n001d7a50 {
struct Ent1d7 { u32 a; u32 b; };
struct Obj1d7 { u32 hdr; Ent1d7 e[4]; };
void func_001d7b10(u32, u32, u32, u32) asm("func_001d7b10");
void wtarget_001d7a50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001d7a50jjjj");
void wtarget_001d7a50(u32 a0, u32 a1, u32 a2, u32 a3) {
    Obj1d7* o = (Obj1d7*)a0;
    for (s32 i = 3; i >= 0; i--) o->e[3 - i].a = 0;
    func_001d7b10(a0, a1, a2, a3);
}
} // n001d7a50

// 001d7a88 (from src/anon/auto80_199_queue.cpp)
namespace n001d7a88 {
void func_001d7a88(u32 a0) asm("func_001d7a88");
void func_001d7a88(u32 a0) {
    u32 s16 = a0;
    s32 s17 = 3;
    u32 s18 = a0;

    do {
        if (*(u32*)(s16 + 4) != 0) {
            f32 f1 = *(f32*)(s16 + 8);
            if (0.0f < f1) {
                f32 f0 = f1 - D_00349e10;
                *(f32*)(s16 + 8) = f0;
                if (f0 <= 0.0f) {
                    *(u32*)(s16 + 4) = 0;
                    func_001d7b10(s18);
                }
            }
        }
        s17 = s17 - 1;
        s16 = s16 + 8;
    } while (s17 >= 0);
}
} // n001d7a88

// 001d7b10 (from src/anon/batch_w40.cpp)
namespace n001d7b10 {
u8* func_001d7980(u32) asm("func_001d7980");
void func_001d7b10(u16* p) asm("func_001d7b10");
void func_001d7b10(u16* p) {
    *p = 0;
    u32* e = (u32*)(p + 2);
    for (s32 i = 3; i >= 0; i--, e += 2) {
        if (*e) *p |= *(u16*)(func_001d7980(*e) + 2);
    }
}
} // n001d7b10

// 001d7b80 (from src/yasui/libys/stop.cpp)
namespace YS {
u32 STOP::is_stop() {
    u32 v = *(u16*)((u32)this + 0);
    return v & 0x1u;
}
}  // namespace YS

// 001d7b90 (from src/anon/tiny_leaf.cpp)
namespace n001d7b90 {
u32 func_001d7b90(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d7b90");
u32 func_001d7b90(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = (u32)(*(u16*)((u32)r4 + (s32)(0)));
    r2 = (u32)(r2 >> 1);
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
} // n001d7b90

// 001d7ba8 (from src/yasui/libys/stop.cpp)
namespace YS {
u32 STOP::is_star() {
    u32 v = *(u16*)((u32)this + 0);
    v >>= 2;
    return v & 0x1u;
}
}  // namespace YS

// 001d7bb8 (never written before)
namespace n001d7bb8 {
u32 func_001d7bb8(u16* p) asm("func_001d7bb8");
u32 func_001d7bb8(u16* p) {
    u32 v = *p;
    v >>= 3;
    return (v ^ 1) & 0x1u;
}
} // n001d7bb8

// 001d7bd0 (from src/anon/tiny_auto80_solver.cpp)
namespace n001d7bd0 {
void func_001d1678(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d1678");
u32 func_001d7bd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001d7bd0");
u32 func_001d7bd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001d1678)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(44)) = 0u;
    *(volatile u32*)((u32)r16 + (s32)(48)) = 0u;
    return r2;
}
} // n001d7bd0

// 001d7c00 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n001d7c00 {
u32 func_001d1698(u32, u32, u32, u32) asm("func_001d1698");
u32 func_001d7c00(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d7c00");
u32 func_001d7c00(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u, r17 = 0u;
    r16 = r5;
    r17 = r4;
    r2 = func_001d1698(r4, r5, r6, r7);
    *(u32*)((u32)r17 + (s32)(48)) = r16;
    return r2;
}
} // n001d7c00

// 001d7c38 (from src/anon/auto80_199_queue.cpp)
namespace n001d7c38 {
u32 func_0014f788(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_0014f788");
void func_001d7c38(u32 a0) asm("func_001d7c38");
void func_001d7c38(u32 a0) {
    u32 s16 = a0;
    func_001d16f8(s16);

    U32U8_001d7c38 t7;
    t7.u = *(u32*)(s16 + 12);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    u32 v0 = func_0014f788(
        *(u32*)(s16 + 4),
        *(u32*)(s16 + 8),
        *(u32*)(s16 + 32),
        *(u32*)(s16 + 36),
        *(u32*)(s16 + 48));
    *(u32*)(s16 + 44) = v0;
}
} // n001d7c38

// 001d7c90 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d7c90 {
u32 func_0014f830(...) asm("func_0014f830");
u32 func_001d1708(...) asm("func_001d1708");
u32 func_001d7c90(u32 a0) asm("func_001d7c90");
u32 func_001d7c90(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(44));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_0014f830)(r4);
        *(volatile u32*)((u32)r16 + (s32)(44)) = 0u;
    }
    r4 = r16;
    return ((u32(*)(u32))func_001d1708)(r4);
}
} // n001d7c90

// 001d7cd0 (from src/anon/batch_w65.cpp)
namespace n001d7cd0 {
extern u8 D_00352878[] asm("D_00352878");
void func_001b3b70(void*, void*, s32, u32) asm("func_001b3b70");
s32 func_0019c8a8(void*) asm("func_0019c8a8");
struct Bits1536 { u32 lo:3; u32 v:4; u32 hi:25; };
void func_001d7cd0(u8* p, u8* q, u32 c) asm("func_001d7cd0");
void func_001d7cd0(u8* p, u8* q, u32 c) {
    func_001b3b70(p, q, 3, c);
    *(u32*)p = (u32)D_00352878;
    *(u32*)(p + 1416) |= 0x20000;
    if (!func_0019c8a8(p)) *(s32*)(p + 944) = 2;
    ((Bits1536*)(p + 1536))->v = (*(u16*)(q + 72) >> 3 & 1) ? 2 : 1;
}
} // n001d7cd0

// 001d7d68 (from src/anon/batch_w50.cpp)
namespace n001d7d68 {
struct Bits1536 { u32 lo : 3; u32 kind : 4; u32 hi : 25; };
void func_001b3b70(void*, void*, s32, u32) asm("func_001b3b70");
s32 func_0019c8a8(void*) asm("func_0019c8a8");
extern u8 D_00352878[] asm("D_00352878");
void func_001d7d68(u8* o, u8* a, u32 b) asm("func_001d7d68");
void func_001d7d68(u8* o, u8* a, u32 b) {
    func_001b3b70(o, a, 3, b);
    *(u32*)o = (u32)D_00352878;
    *(u32*)(o + 1416) |= 0x20000;
    if (!func_0019c8a8(o)) *(u32*)(o + 944) = 2;
    ((Bits1536*)(o + 1536))->kind = (*(u16*)(a + 72) >> 3 & 1) ? 2 : 1;
}
} // n001d7d68

// 001d7e00 (from src/anon/batch_w21.cpp)
namespace n001d7e00 {
void func_00190920(void*, s32, void*) asm("func_00190920");
void func_00198450(void*) asm("func_00198450");
void func_001d7e00(u8* p) asm("func_001d7e00");
void func_001d7e00(u8* p) {
    func_00190920(p + 2548, 2, p);
    func_00198450(p);
}
} // n001d7e00

// 001d7e38 (never written before)
namespace n001d7e38 {
void func_0019aa60(u32, u8*) asm("func_0019aa60");
void func_0016b668(u8*) asm("func_0016b668");
void func_001d7e38(u8* p) asm("func_001d7e38");
void func_001d7e38(u8* p) {
    u32 o = *(u32*)(p + 2072);
    if (o) func_0019aa60(o, p);
    func_0016b668(p);
}
} // n001d7e38

// 001d7e78 (from src/anon/batch_w22.cpp)
namespace n001d7e78 {
void func_0019aa00(u32, void*) asm("func_0019aa00");
void func_001b40e0(void*) asm("func_001b40e0");
void func_001d7e78(u8* p) asm("func_001d7e78");
void func_001d7e78(u8* p) {
    u32 o = *(u32*)(p + 2072);
    if (o) func_0019aa00(o, p);
    func_001b40e0(p);
}
} // n001d7e78

// 001d7eb8 (from src/anon/tiny.cpp)
namespace n001d7eb8 {
void func_001d7eb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d7eb8");
void func_001d7eb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u32*)((u32)b + (10488)) = (u32)a0;
}
} // n001d7eb8

// 001d7ec8 (from src/anon/batch_w26.cpp)
namespace n001d7ec8 {
s32 func_001d7f10(s32) asm("func_001d7f10");
extern u8* D_003528f8 asm("D_003528f8");
u8* func_001d7ec8(s32 i) asm("func_001d7ec8");
u8* func_001d7ec8(s32 i) {
    if (!func_001d7f10(i)) return 0;
    u8* b = D_003528f8;
    return b + ((u32*)b)[i + 2];
}
} // n001d7ec8

// 001d7f10 (from src/anon/auto200_999.cpp)
namespace n001d7f10 {
u32 func_001d7f10(u32 a0) asm("func_001d7f10");
u32 func_001d7f10(u32 a0) {
    u32 base_addr = 0x00350000u;
    register u32 off asm("$14") = a0 << 2;
    register u32 base asm("$13") = *(u32 *)(base_addr + 10488);
    u32 ret = 0;
    u32 count = *(u32 *)(base + 4);
    u32 ok = (s32)a0 < (s32)count;
    off += base;
    if (ok != 0) {
        u32 v = *(u32 *)(off + 8);
        ret = v != 0;
    }
    return ret;
}
} // n001d7f10

// 001d7f40 (from src/anon/batch_w23.cpp)
namespace n001d7f40 {
struct E68 { u8 id; u8 pad[67]; };
struct T1d7 { s32 n; E68 e[1]; };
s32 func_001d7f40(T1d7* t, u32 id) asm("func_001d7f40");
s32 func_001d7f40(T1d7* t, u32 id) {                      
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (t->e[i].id == id) return i;
    }
    return -1;
}
} // n001d7f40

// 001d7f80 (from src/anon/batch_w63.cpp)
namespace n001d7f80 {
typedef void (*VFn)(void*);
void func_001d7f80(u8* p) asm("func_001d7f80");
void func_001d7f80(u8* p) {
    for (s32 i = 0; i < *(s32*)(p + 712); i++) {
        u8* o = ((u8**)(p + 676))[i];
        if (!(*(u32*)(o + 12) & 0x10)) (*(VFn*)(*(u8**)o + 4))(o);
    }
    *(u32*)(p + 4) |= 1;
}
} // n001d7f80

// 001d8010 (from src/anon/auto80_199_queue.cpp)
namespace n001d8010 {
void func_001d8010(u32 a0) asm("func_001d8010");
void func_001d8010(u32 a0) {
    u32 v0 = func_001bb4a0(a0);
    if (v0 == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 t7 = *(u32*)(v0 + 4);
    t7 = t7 & 1u;
    if (t7 != 0) {
        v0 = func_001bbcb0();
        func_001d8070(v0);
    }

    v0 = func_001bbcb0();
    func_001d7f80(v0);
}
} // n001d8010

// 001d8070 (from src/anon/batch_w57.cpp)
namespace n001d8070 {
void func_001d8070(u8* t) asm("func_001d8070");
void func_001d8070(u8* t) {
    for (s32 i = 0; i < *(s32*)(t + 712); i++) {
        void** o = ((void***)(t + 676))[i];
        (*(void (**)(void*))(*(u8**)o + 8))(o);
    }
    *(u32*)(t + 4) &= ~1u;
}
} // n001d8070

// 001d80f0 (from src/anon/auto80_199_queue.cpp)
namespace n001d80f0 {
void func_001d80f0(u32 a0) asm("func_001d80f0");
void func_001d80f0(u32 a0) {
    u32 v0 = func_001bb4a0(a0);
    if (v0 == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 t7 = *(u32*)(v0 + 4);
    t7 = t7 & 1u;
    if (t7 != 0) {
        v0 = func_001bbcb0();
        func_001d8070(v0);
        return;
    }

    v0 = func_001bbcb0();
    t7 = *(u32*)(v0 + 4);
    t7 = t7 | 2u;
    *(u32*)(v0 + 4) = t7;
}
} // n001d80f0

// 001d8158 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d8158 {
u32 func_001bb4a0(...) asm("func_001bb4a0");
u32 func_001bbcb0(...) asm("func_001bbcb0");
u32 func_001d8158(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001d8158");
u32 func_001d8158(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001bb4a0)();
    r15 = 0u;
    if (r2 != 0u) {
        r2 = ((u32(*)())func_001bbcb0)();
        r15 = *(volatile u32*)((u32)r2 + (s32)(4));
        r15 = (u32)(r15 & 0x0001u);
    }
    r2 = r15;
    return r2;
}
} // n001d8158

// 001d8190 (from src/anon/batch_wcx.cpp)
namespace n001d8190 {
void u_tail4_001d8190(u32, u32, u32, u32) asm("_Z16u_tail4_001d8190jjjj");
typedef void (*VF0)(u8*, u8);
typedef void (*VF5)(u8*, u32, u32, u32);
void func_001d5370b(u8*, u32, s32) asm("func_001d5370");
void func_001d16e8(u8*, u8, s32) asm("func_001d16e8");
struct Ow { u8 pad[72]; u32 k; u8 pad2[600]; u8* arr[9]; s32 n; };
void u_tail4_001d8190(u32, u32, u32, u32) asm("_Z16u_tail4_001d8190jjjj");
void u_tail4_001d8190(u32 a, u32 b, u32 c, u32)
{
    Ow* p = (Ow*)a; u8* d = (u8*)b; u8* o = (u8*)c;
    (**(VF0**)o)(o, d[19]);
    (*(VF5*)(*(u8**)o + 20))(o, *(u32*)(d + 4), *(u32*)(d + 8), *(u32*)(d + 12));
    if (p->k) {
        u16 k = *(u16*)(d + 16);
        if (k) {
            func_001d5370b(o + 4, p->k, k - 1);
            func_001d16e8(o, d[18], p->n + 3);
        }
    }
    p->arr[p->n++] = o;
}
} // n001d8190

// 001d8248 (from src/anon/tiny_auto80_solver.cpp)
namespace n001d8248 {
u32 func_001d8190(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d8190");
u32 func_001d8248(u32 a0, u32 a1) asm("func_001d8248");
u32 func_001d8248(u32 a0, u32 a1) {
    u32 a2 = a0 + *(u8*)(a1 + 19) * 44 + 188;
    return ((u32(*)(u32, u32, u32))func_001d8190)(a0, a1, a2);
}
} // n001d8248

// 001d8270 (from src/anon/auto80_199_queue.cpp)
namespace n001d8270 {
void func_001d8270(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d8270");
void func_001d8270(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a3;
    u32 s17 = a0;
    u32 s18 = a1;
    u32 s19 = a2;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d8270 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 a5 = s17;
    u32 t6 = *(u32*)(a4 + 188);
    u32 a6 = s18;
    u32 a7 = s19;
    u32 fn = *(u32*)(t6 + 20);
    ((Fn_001d8270)fn)(a4 + 188, a5, a6, a7);
}
} // n001d8270

// 001d8310 (from src/anon/auto80_199_queue.cpp)
namespace n001d8310 {
void func_001d8310(s32 a0, u32 a1) asm("func_001d8310");
void func_001d8310(s32 a0, u32 a1) {
    u32 s16 = a1;
    s32 s17 = a0;

    if (func_001bb4b0((u32)s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d8310 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;

    u32 t5 = *(u32*)(v0 + 200);
    s16 = v0 + 188;
    t5 = t5 & 4u;
    if (t5 == 0) {
        u32 vt = *(u32*)(v0 + 188);
        u32 fn = *(u32*)(vt + 4);
        ((Fn_001d8310)fn)(s16);
    }

    u32 p5;
    if (s17 >= 0) {
        p5 = (u32)s17;
    } else {
        p5 = *(u32*)(s16 + 24);
    }

    func_001d1950(s16, p5);
}
} // n001d8310

// 001d83c0 (from src/anon/auto80_199_queue.cpp)
namespace n001d83c0 {
u32 func_001d83c0(u32 a0) asm("func_001d83c0");
u32 func_001d83c0(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return 0;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d83c0 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return 0;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    return func_001d1998(a4 + 188);
}
} // n001d83c0

// 001d8438 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d8438 {
u32 func_001d83c0(...) asm("func_001d83c0");
u32 func_001d8438() asm("func_001d8438");
u32 func_001d8438() {
    u32 v0 = func_001d83c0();
    return (v0 + 59) / 60;
}
} // n001d8438

// 001d8470 (from src/anon/auto80_199_queue.cpp)
namespace n001d8470 {
void func_001d8470(u32 a0) asm("func_001d8470");
void func_001d8470(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d8470 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 vt = *(u32*)(a4 + 188);
    u32 fn = *(u32*)(vt + 12);
    ((Fn_001d8470)fn)(a4 + 188);
}
} // n001d8470

// 001d84e0 (from src/anon/auto80_199_queue.cpp)
namespace n001d84e0 {
void func_001d84e0(u32 a0) asm("func_001d84e0");
void func_001d84e0(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 44;
    v0 = v0 + s16;

    U32U8_001d84e0 t7;
    t7.u = *(u32*)(v0 + 200);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1878(a4 + 188);
}
} // n001d84e0

// 001d8550 (from src/anon/tiny_auto80_solver.cpp)
namespace n001d8550 {
u32 func_001d8190(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d8190");
u32 func_001d8550(u32 a0, u32 a1) asm("func_001d8550");
u32 func_001d8550(u32 a0, u32 a1) {
    u32 a2 = a0 + *(u8*)(a1 + 19) * 56 + 232;
    return ((u32(*)(u32, u32, u32))func_001d8190)(a0, a1, a2);
}
} // n001d8550

// 001d8578 (from src/anon/auto80_199_queue.cpp)
namespace n001d8578 {
void func_001d8578(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d8578");
void func_001d8578(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a3;
    u32 s17 = a0;
    u32 s18 = a1;
    u32 s19 = a2;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8578 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 a5 = s17;
    u32 t6 = *(u32*)(a4 + 232);
    u32 a6 = s18;
    u32 a7 = s19;
    u32 fn = *(u32*)(t6 + 20);
    ((Fn_001d8578)fn)(a4 + 232, a5, a6, a7);
}
} // n001d8578

// 001d8618 (from src/anon/auto80_199_queue.cpp)
namespace n001d8618 {
void func_001d17b0(u32 a0) asm("func_001d17b0");
void func_001d1b60(u32 a0, s32 a1) asm("func_001d1b60");
void func_001d8618(u32 a0, u32 a1) asm("func_001d8618");
void func_001d8618(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 s17 = a0;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8618 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1b60(a4 + 232, s17);
}
} // n001d8618

// 001d86a0 (from src/anon/batch_w40.cpp)
namespace n001d86a0 {
s32 func_001bb4b0(void) asm("func_001bb4b0");
u8* func_001bbcb0(void) asm("func_001bbcb0");
void func_001d8718(s32, s32) asm("func_001d8718");
struct MissionFlag { u32 on : 1; u32 rest : 31; };
static inline bool mission_entry_on(s32 i) {
    u8* b = func_001bbcb0();
    u32 off = i * 56;
    return ((MissionFlag*)(b + off + 244))->on;
}
void mission_add_count(s32 a, s32 i) asm("_ZN2YS7MISSION8AddCountEii");
void mission_add_count(s32 a, s32 i) {
    if (func_001bb4b0() && mission_entry_on(i))
        func_001d8718(a, i);
}
} // n001d86a0

// 001d8718 (from src/anon/batch_wcx.cpp)
namespace n001d8718 {
s32 func_001bb4a0(void) asm("func_001bb4a0");
u8* func_001bbcb0(void) asm("func_001bbcb0");
void func_001d1b60(u8*, s32) asm("func_001d1b60");
void func_001d8718(s32 base, s32 i) asm("func_001d8718");
void func_001d8718(s32 base, s32 i)
{
    if (!func_001bb4a0()) return;
    struct BF { u32 on : 1; };
    u8* t = func_001bbcb0();
    t += i * 56;
    if (!(u8)((BF*)(t + 244))->on) return;
    u8* e = func_001bbcb0() + i * 56;
    func_001d1b60(e + 232, *(s32*)(i * 56 + func_001bbcb0() + 276) + base);
}
} // n001d8718

// 001d87b8 (from src/anon/batch_w40.cpp)
namespace n001d87b8 {
s32 func_001bb4a0(void) asm("func_001bb4a0");
u8* func_001bbcb0(void) asm("func_001bbcb0");
struct MissionFlag { u32 on : 1; u32 rest : 31; };
static inline bool mission_entry_on(s32 i) {
    u8* b = func_001bbcb0();
    u32 off = i * 56;
    return ((MissionFlag*)(b + off + 244))->on;
}
s32 mission_get_count(s32 i) asm("_ZN2YS7MISSION8GetCountEi");
s32 mission_get_count(s32 i) {
    if (func_001bb4a0()) {
        if (mission_entry_on(i)) return *(s32*)(i * 56 + func_001bbcb0() + 276);
    }
    return 0;
}
} // n001d87b8

// 001d8820 (from src/anon/auto80_199_queue.cpp)
namespace n001d8820 {
void func_001d17b0(u32 a0) asm("func_001d17b0");
void func_001d1b60(u32 a0, s32 a1) asm("func_001d1b60");
void func_001d8820(u32 a0) asm("func_001d8820");
void func_001d8820(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4b0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8820 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    a4 = a4 + 232;
    func_001d1b60(a4, *(u32*)(a4 + 20));
}
} // n001d8820

// 001d8898 (from src/anon/batch_w1519.cpp)
namespace n001d8898 {
u32 func_001bb4a0() asm("func_001bb4a0");
u32 func_001bbcb0() asm("func_001bbcb0");
struct W1519E38 { u8 pad[0xf4]; u32 on : 1; u32 : 31; };
u32 func_001d8898(s32 i) asm("func_001d8898");
u32 func_001d8898(s32 i) {
    if (func_001bb4a0()) {
        u32 b = func_001bbcb0();
        u32 o = i * 0x38;
        if ((u8)((W1519E38*)(b + o))->on) { u32 m = *(u32*)(func_001bbcb0() + o + 0xf4) & 8; return m != 0; }
    }
    return 0;
}
} // n001d8898

// 001d8908 (from src/anon/auto80_199_queue.cpp)
namespace n001d8908 {
void func_001d8908(u32 a0) asm("func_001d8908");
void func_001d8908(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8908 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1878(a4 + 232);
}
} // n001d8908

// 001d8978 (from src/anon/auto80_199_queue.cpp)
namespace n001d8978 {
void func_001d8978(u32 a0, u32 a1) asm("func_001d8978");
void func_001d8978(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 s17 = a0;

    if (func_001bb4a0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 56;
    v0 = v0 + s16;

    U32U8_001d8978 t7;
    t7.u = *(u32*)(v0 + 244);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    *(u32*)(v0 + 272) = s17;
}
} // n001d8978

// 001d89e8 (from src/anon/batch_w85.cpp)
namespace n001d89e8 {
s32 func_001bb4a0(void) asm("func_001bb4a0");
u8* func_001bbcb0(void) asm("func_001bbcb0");
void func_001d1b60(void*, s32) asm("func_001d1b60");
struct Dig1d8 { u8 p0[12]; u32 flags; u8 p16[28]; s32 cur; };
static inline u32 dig1d8_on(Dig1d8* e) { return e->flags & 1; }
void func_001d89e8(s32 digit, s32 val, s32 idx) asm("func_001d89e8");
void func_001d89e8(s32 digit, s32 val, s32 idx) {
    Dig1d8* e;
    s32 m, n, cur;
    if (!func_001bb4a0()) return;
    if (!(u8)dig1d8_on((Dig1d8*)(func_001bbcb0() + idx * 56 + 232))) return;
    e = (Dig1d8*)(func_001bbcb0() + idx * 56 + 232);
    m = 1;
    cur = e->cur;
    if (digit > 0) { n = digit; do { m *= 10; } while (--n); }
    func_001d1b60(e, cur + (val - cur / m % 10) * m);
}
} // n001d89e8

// 001d8ad8 (from src/anon/batch_w59.cpp)
namespace n001d8ad8 {
u8* func_001bbcb0(void) asm("func_001bbcb0");
u32 func_001bb4a0(void) asm("func_001bb4a0");
void func_001d8ad8(s32 idx, u8 flag) asm("func_001d8ad8");
void func_001d8ad8(s32 idx, u8 flag) {
    u8* b = func_001bbcb0() + idx * 56;
    if (func_001bb4a0()) {
        u8* o = b + 232;
        u32 f = *(u32*)(b + 244);
        u8 on = f & 1;
        if (on) {
            typedef void (*Fn)(u8*);
            if (flag) {
                if (!(f & 8)) (*(Fn*)(*(u8**)o + 12))(o);
            } else {
                if (f & 8) (*(Fn*)(*(u8**)o + 16))(o);
            }
        }
    }
}
} // n001d8ad8

// 001d8b68 (from src/anon/auto80_199_queue.cpp)
namespace n001d8b68 {
void func_001d8b68(u32 a0, u32 a1) asm("func_001d8b68");
void func_001d8b68(u32 a0, u32 a1) {
    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = 52;

    u32 a2 = *(u8*)(s17 + 19);
    a2 = a2 * s18;
    a2 = add_left_u32(s16, a2);
    func_001d8190(s16, s17, a2 + 400);

    u32 t7 = *(u8*)(s17 + 19);
    f32 f12 = (f32)(s32)*(u32*)(s17 + 4);
    t7 = t7 * s18;
    s16 = s16 + t7;
    s16 = s16 + 400;
    func_001d1da0(s16, f12);
}
} // n001d8b68

// 001d8bd0 (from src/anon/auto80_199_queue.cpp)
namespace n001d8bd0 {
void func_001d8bd0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d8bd0");
void func_001d8bd0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a3;
    u32 s17 = a0;
    u32 s18 = a1;
    u32 s19 = a2;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d8bd0 t7;
    t7.u = *(u32*)(v0 + 412);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 a5 = s17;
    u32 t6 = *(u32*)(a4 + 400);
    u32 a6 = s18;
    u32 a7 = s19;
    u32 fn = *(u32*)(t6 + 20);
    ((Fn_001d8bd0)fn)(a4 + 400, a5, a6, a7);
}
} // n001d8bd0

// 001d8c70 (from src/anon/auto80_199_queue.cpp)
namespace n001d8c70 {
void func_001d8c70(u32 a0, f32 a1) asm("func_001d8c70");
void func_001d8c70(u32 a0, f32 a1) {
    f32 s20 = a1;
    u32 s16 = a0;

    if (func_001bb4b0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    u32 t7 = *(u32*)(v0 + 1320);
    if (t7 != 0) {
        return;
    }

    v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d8c70 t8;
    t8.u = *(u32*)(v0 + 412);
    t8.u = t8.u & 1u;
    if (t8.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1da0(a4 + 400, s20);
}
} // n001d8c70

// 001d8d08 (from src/anon/batch_w1565.cpp)
namespace n001d8d08 {
struct E_w1565 { u32 flag : 1; u32 : 31; u8 pad[28]; f32 val; u8 pad2[16]; };
s32 func_001bb4b0(s32) asm("func_001bb4b0");
void* func_001bbcb0(void) asm("func_001bbcb0");
void func_001d8c70(s32, f32) asm("func_001d8c70");
void func_001d8d08(s32 i, f32 v) asm("func_001d8d08");
void func_001d8d08(s32 i, f32 v) {
    if (func_001bb4b0(i) == 0) return;
    u8* b = (u8*)func_001bbcb0();
    s32 o = i * 52;
    if (!(u8)((E_w1565*)(b + o + 412))->flag) return;
    func_001d8c70(i, ((E_w1565*)((u8*)func_001bbcb0() + o + 412))->val + v);
}
} // n001d8d08

// 001d8da0 (from src/anon/auto80_199_queue.cpp)
namespace n001d8da0 {
void func_001d8c70(u32 a0, f32 a1) asm("func_001d8c70");
void func_001d8da0(u32 a0, f32 a1) asm("func_001d8da0");
void func_001d8da0(u32 a0, f32 a1) {
    f32 s20 = a1;
    u32 s16 = a0;

    if (func_001bb4b0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    u32 s17 = s16 * 52;
    v0 = v0 + s17;

    U32U8_001d8da0 t7;
    t7.u = *(u32*)(v0 + 412);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s17;
    f32 f12 = (f32)(s32)*(u32*)(v0 + 424);
    f12 = f12 * s20;
    func_001d8c70(s16, f12);
}
} // n001d8da0

// 001d8e38 (from src/anon/auto80_199_queue.cpp)
namespace n001d8e38 {
f32 func_001d8e38(u32 a0) asm("func_001d8e38");
f32 func_001d8e38(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return 0.0f;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d8e38 t7;
    t7.u = *(u32*)(v0 + 412);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return 0.0f;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    v0 = v0 + 400;
    f32 f0 = (f32)(s32)*(u32*)(v0 + 24);
    f32 f1 = *(f32*)(v0 + 44);
    return f1 / f0;
}
} // n001d8e38

// 001d8eb8 (from src/anon/auto80_199_queue.cpp)
namespace n001d8eb8 {
f32 func_001d8eb8(u32 a0) asm("func_001d8eb8");
f32 func_001d8eb8(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return 0.0f;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d8eb8 t7;
    t7.u = *(u32*)(v0 + 412);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return 0.0f;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    v0 = v0 + 400;
    f32 f0 = (f32)(s32)*(u32*)(v0 + 28);
    f32 f1 = (f32)(s32)*(u32*)(v0 + 24);
    f0 = f0 / f1;
    return f0;
}
} // n001d8eb8

// 001d8f38 (from src/anon/batch_w1519.cpp)
namespace n001d8f38 {
u32 func_001bb4a0() asm("func_001bb4a0");
u32 func_001bbcb0() asm("func_001bbcb0");
struct W1519E34 { u8 pad[0x19c]; u32 on : 1; u32 : 31; };
u32 IsGaugeWarning_w1519(s32 i) asm("_ZN2YS7MISSION14IsGaugeWarningEi");
u32 IsGaugeWarning_w1519(s32 i) {
    if (func_001bb4a0()) {
        u32 b = func_001bbcb0();
        u32 o = i * 0x34;
        if ((u8)((W1519E34*)(b + o))->on) { u32 m = *(u32*)(func_001bbcb0() + o + 0x19c) & 8; return m != 0; }
    }
    return 0;
}
} // n001d8f38

// 001d8fa8 (from src/anon/batch_w58.cpp)
namespace n001d8fa8 {
struct VObj { void** vt; };
typedef void (*VFn)(void*);
s32 func_001bb4a0(void) asm("func_001bb4a0");
u8* func_001bbcb0(void) asm("func_001bbcb0");
void func_001d8fa8(u8 on, s32 i) asm("func_001d8fa8");
void func_001d8fa8(u8 on, s32 i) {
    if (!func_001bb4a0()) return;
    u8* e = func_001bbcb0() + i * 52;
    u8 f = *(volatile u32*)(e + 412) & 1;
    if (!f) return;
    VObj* o = (VObj*)(e + 400);
    if (on) ((VFn)o->vt[3])(o);
    else ((VFn)o->vt[4])(o);
}
} // n001d8fa8

// 001d9028 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001d9028 {
u32 func_001d8190(u32, u32, u32, u32) asm("func_001d8190");
u32 func_001d9028(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d9028");
u32 func_001d9028(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    r15 = (u32)(*(u8*)((u32)r5 + (s32)(19)));
    r15 = (u32)(r15 << 6);
    r6 = (u32)(r4 + r15);
    r6 = (u32)((s32)r6 + (608));
    return func_001d8190(r4, r5, r6, r7);
}
} // n001d9028

// 001d9050 (from src/anon/auto80_199_queue.cpp)
namespace n001d9050 {
void func_001d9050(u32 a0, u32 a1, f32 a2) asm("func_001d9050");
void func_001d9050(u32 a0, u32 a1, f32 a2) {
    f32 s20 = a2;
    u32 s16 = a1 << 6;
    u32 s17 = a0;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d9050 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d2130(a4 + 608, s17, s20);
}
} // n001d9050

// 001d90e0 (from src/anon/auto80_199_queue.cpp)
namespace n001d90e0 {
void func_001d90e0(u32 a0) asm("func_001d90e0");
void func_001d90e0(u32 a0) {
    u32 s16 = a0 << 6;

    if (func_001bb4b0(a0) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d90e0 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d2180(a4 + 608);
}
} // n001d90e0

// 001d9148 (from src/anon/batch_w28.cpp)
namespace n001d9148 {
u32 ctarget_001d9148(u32, u32, u32, u32) asm("_Z16ctarget_001d9148jjjj");
u32 func_001bb4a0(void) asm("func_001bb4a0");
u8* func_001bbcb0(void) asm("func_001bbcb0");
struct E64 { u8 pad[0x26c]; u32 on : 1; u32 : 31; };
static inline bool entry_on(u32 o) { return ((E64*)(func_001bbcb0() + o))->on; }
u32 ctarget_001d9148(u32 i, u32, u32, u32) {
    u32 o = i << 6;
    if (func_001bb4a0()) {
        if (entry_on(o)) return *(u32*)(func_001bbcb0() + o + 0x298);
    }
    return 0;
}
} // n001d9148

// 001d91a8 (from src/anon/auto80_199_queue.cpp)
namespace n001d91a8 {
void func_001d91a8(u32 a0, u32 a1) asm("func_001d91a8");
void func_001d91a8(u32 a0, u32 a1) {
    u32 s16 = a1 << 6;
    u32 s17 = a0;

    if (func_001bb4a0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d91a8 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d2248(a4 + 608, s17);
}
} // n001d91a8

// 001d9228 (from src/anon/batch_w29.cpp)
namespace n001d9228 {
u32 ctarget_001d9228(s32 i) asm("_Z16ctarget_001d9228jjjj");
u32 func_001bb4a0(void) asm("func_001bb4a0");
u8* func_001bbcb0(void) asm("func_001bbcb0");
u32 ctarget_001d9228(s32 i) {
    s32 o = i * 64;
    if (func_001bb4a0()) {
        u32 f = *(u32*)(o + func_001bbcb0() + 620);
        if ((u8)(f & 1))
            return *(u32*)(o + func_001bbcb0() + 652);
    }
    return 0;
}
} // n001d9228

// 001d9288 (from src/anon/auto80_199_queue.cpp)
namespace n001d9288 {
void func_001d9288(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d9288");
void func_001d9288(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a3 << 6;
    u32 s17 = a0;
    u32 s18 = a1;
    u32 s19 = a2;

    if (func_001bb4b0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d9288 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    u32 a5 = s17;
    u32 t6 = *(u32*)(a4 + 608);
    u32 a6 = s18;
    u32 a7 = s19;
    u32 fn = *(u32*)(t6 + 20);
    ((Fn_001d9288)fn)(a4 + 608, a5, a6, a7);
}
} // n001d9288

// 001d9320 (from src/anon/batch_w41.cpp)
namespace n001d9320 {
struct W41VO { void** vt; u32 f4, f8; u32 flags; };
u32 func_001bb4a0(void) asm("func_001bb4a0");
u8* func_001bbcb0(void) asm("func_001bbcb0");
void WarningComboCounter(s32 i) asm("_ZN2YS7MISSION19WarningComboCounterEi");
void WarningComboCounter(s32 i) {
    u8* e = func_001bbcb0() + i * 64;
    W41VO* o = (W41VO*)(e + 608);
    if (func_001bb4a0()) {
        u32 f = *(u32*)(e + 620);
        if ((u8)(f & 1) && !(f & 8)) ((void (*)(W41VO*))o->vt[3])(o);
    }
}
} // n001d9320

// 001d9388 (from src/anon/auto80_199_queue.cpp)
namespace n001d9388 {
void func_001d9388(u32 a0, u32 a1) asm("func_001d9388");
void func_001d9388(u32 a0, u32 a1) {
    u32 s16 = a1 << 6;
    u32 s17 = a0;

    if (func_001bb4a0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    v0 = v0 + s16;

    U32U8_001d9388 t7;
    t7.u = *(u32*)(v0 + 620);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    *(u32*)(v0 + 648) = s17;
}
} // n001d9388

// 001d93f0 (from src/anon/tiny_auto80_solver.cpp)
namespace n001d93f0 {
u32 func_001d8190(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d8190");
u32 func_001d93f0(u32 a0, u32 a1) asm("func_001d93f0");
u32 func_001d93f0(u32 a0, u32 a1) {
    u32 a2 = a0 + *(u8*)(a1 + 19) * 52 + 556;
    return ((u32(*)(u32, u32, u32))func_001d8190)(a0, a1, a2);
}
} // n001d93f0

// 001d9418 (from src/anon/auto80_199_queue.cpp)
namespace n001d9418 {
void func_001d9418(u32 a0, u32 a1) asm("func_001d9418");
void func_001d9418(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 s17 = a0;

    if (func_001bb4a0(s17) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d9418 t7;
    t7.u = *(u32*)(v0 + 568);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    v0 = v0 + s16;
    *(u32*)(v0 + 604) = s17;
}
} // n001d9418

// 001d9488 (from src/anon/auto80_199_queue.cpp)
namespace n001d9488 {
void func_001d9488(u32 a0) asm("func_001d9488");
void func_001d9488(u32 a0) {
    u32 s16 = a0;

    if (func_001bb4a0(s16) == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    s16 = s16 * 52;
    v0 = v0 + s16;

    U32U8_001d9488 t7;
    t7.u = *(u32*)(v0 + 568);
    t7.u = t7.u & 1u;
    if (t7.b == 0) {
        return;
    }

    v0 = func_001bbcb0();
    u32 a4 = v0 + s16;
    func_001d1878(a4 + 556);
}
} // n001d9488

// 001d94f8 (from src/anon/batch_w95.cpp)
namespace n001d94f8 {
extern u8 D_0032e020[] asm("D_0032e020");
s32 func_001a8bf8(u32*, s32) asm("func_001a8bf8");
void func_001a8c60(u32*, s32, s32) asm("func_001a8c60");
u32 func_001a8c10(u32*, s32) asm("func_001a8c10");
u8* func_00188fe0(u8*, u32) asm("func_00188fe0");
void func_001d9630(u8*, u32) asm("func_001d9630");
void func_001d94f8(u32 a, u32* other) asm("func_001d94f8");
void func_001d94f8(u32 a, u32* other) {
    u32 p = a;
    for (s32 i = 0; i < 4; i++) {
        func_001a8bf8(&p, i);                 
        for (s32 j = 0; j < 4; j++) {
            if (func_001a8bf8(&p, i) == func_001a8bf8(other, j)) {                 
                func_001a8c60(&p, i, 18);                      
                break;
            }
        }
    }
    for (s32 i = 0; i < 4; i++) {
        if (func_001a8bf8(&p, i) == 18) continue;
        u8* e = func_00188fe0(D_0032e020, func_001a8c10(&p, i));
        func_001d9630(e + 20, 8);
        func_001d9630(e + 36, 8);
        func_001d9630(e + 52, 8);
        u16* q = (u16*)(e + 80);
        for (s32 n = 0; n < 80; n++) q[n + 2] &= 0x7fff;
    }
}
} // n001d94f8

// 001d9630 (from src/anon/batch_w60.cpp)
namespace n001d9630 {
void func_001a3188(u16, s32, s32) asm("func_001a3188");
void func_001d9630(u16* p, s32 n) asm("func_001d9630");
void func_001d9630(u16* p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        if (p[i]) {
            func_001a3188(p[i], 100, 0);
            p[i] = 0;
        }
    }
}
} // n001d9630

// 001d9688 (from src/anon/batch_w22.cpp)
namespace n001d9688 {
struct R3 { u8 v[3]; };
u8 wtarget_001d9688(R3*, u32, u32, u32) asm("_Z16wtarget_001d9688jjjj");
u8 wtarget_001d9688(R3* a, u32 b, u32 c, u32) {
    if (a[b].v[c] < 99) a[b].v[c]++;
    return a[b].v[c];
}
} // n001d9688

// 001d96c0 (from src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n001d96c0 {
u32 func_001d9688(u32, u32, u32, u32) asm("func_001d9688");
extern u8 D_00370000 asm("D_00370000");
u32 func_001d96c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d96c0");
u32 func_001d96c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d9688(((u32)(*(u32*)((u32)((u32)&D_00370000) - 6592u))), a0, a1, a3);
}
} // n001d96c0

// 001d96e8 (from src/anon/tiny_leaf.cpp)
namespace n001d96e8 {
u32 func_001d96e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d96e8");
u32 func_001d96e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u;
    r14 = (u32)(0x0037u << 16);
    r15 = (u32)(r4 << 1);
    r13 = *(u32*)((u32)r14 + (s32)(-6592));
    r15 = (u32)(r15 + r4);
    r15 = (u32)(r15 + r13);
    r15 = (u32)(r15 + r5);
    r2 = (u32)(*(u8*)((u32)r15 + (s32)(0)));
    return r2;
}
} // n001d96e8

// 001d9708 (never written before)
namespace n001d9708 {
void func_001d9708(u16* p) asm("func_001d9708");
void func_001d9708(u16* p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    u16* q = p + 3;
    for (s32 i = 6; i >= 0; i--) { *q = 0; q++; }
    p += 10;
    for (s32 i = 3; i >= 0; i--) { *p = 0; p++; }
}
} // n001d9708

// 001d9768 (from src/anon/auto80_199_queue.cpp)
namespace n001d9768 {
void func_001d9768(u16* a0) asm("func_001d9768");
void func_001d9768(u16* a0) {
    a0[0] = 0;
    a0[1] = 0;
    a0[2] = 0;

    s32 t6 = 6;
    u16* t7 = a0 + 3;
    do {
        *t7 = 0;
        t6 = t6 - 1;
        t7 = t7 + 1;
    } while (t6 >= 0);

    a0 = a0 + 10;
    s32 t7c = 3;
    do {
        *a0 = 0;
        t7c = t7c - 1;
        a0 = a0 + 1;
    } while (t7c >= 0);
}
} // n001d9768

// 001d97c8 (from src/anon/batch_w14.cpp)
namespace n001d97c8 {
extern u16 D_0032fafe[] asm("D_0032fafe");
void func_001d97c8(void) asm("func_001d97c8");
void func_001d97c8(void) {
    if (D_0032fafe[1] < 999) D_0032fafe[1]++;
}
} // n001d97c8

// 001d97f0 (from src/anon/batch_w11.cpp)
namespace n001d97f0 {
extern u16 D_0032fafe[] asm("D_0032fafe");
void func_001d97f0(s32 i) asm("func_001d97f0");
void func_001d97f0(s32 i) {
    if (D_0032fafe[i + 3] < 999) D_0032fafe[i + 3]++;
}
} // n001d97f0

// 001d9820 (from src/anon/batch_w6.cpp)
namespace n001d9820 {
extern u16 D_0032fafe[] asm("D_0032fafe");
void func_001d9820(s32 i) asm("func_001d9820");
void func_001d9820(s32 i) {
    if (D_0032fafe[i + 9] < 999) D_0032fafe[i + 9]++;
}
} // n001d9820

// 001d9850 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d9850 {
u32 func_00181500(...) asm("func_00181500");
u32 func_001d9850() asm("func_001d9850");
u32 func_001d9850() {
    u32 s0 = 0;
    if (func_00181500(4215) != 0) {
        if (func_00181500(9289) != 0) {
            s0 = (u32)(func_00181500(11325) != 0);
        }
    }
    return s0;
}
} // n001d9850

// 001d98a0 (from src/anon/batch_w76.cpp)
namespace n001d98a0 {
s32 func_001a35f8(s32, u32) asm("func_001a35f8");
extern u8 D_0032bb30[] asm("D_0032bb30");
extern u8 D_0033bc10[] asm("D_0033bc10");
s32 func_00105868(void*) asm("func_00105868");
s32 func_00276fd0(void) asm("func_00276fd0");
s32 func_001e0a90(void*) asm("func_001e0a90");
static inline bool Is100() { return func_00276fd0() == 100; }
bool IsFMSecretMovie(void) asm("_ZN2YS13BATTLE_REPORT15IsFMSecretMovieEv");
bool IsFMSecretMovie(void)
{
    switch (func_00105868(D_0032bb30)) {
    case 0:
        return false;
    case 1:
        if (!Is100()) return false;
        return func_001e0a90(D_0033bc10) != 0;
    case 2:
        return Is100();
    case 3:
        return func_001a35f8(593, 100) > 0 && func_001a35f8(594, 100) > 0 && func_001a35f8(595, 100) > 0;
    }
    return false;
}
} // n001d98a0

// 001d9980 (from src/anon/batch_w51.cpp)
namespace n001d9980 {
u32 wtarget_001d9980(u32, u32, u32, u32) asm("_Z16wtarget_001d9980jjjj");
s32 func_00105868(void*) asm("func_00105868");
s32 func_00276fd0(void) asm("func_00276fd0");
extern u8 D_0032bb30[] asm("D_0032bb30");
u32 wtarget_001d9980(u32, u32, u32, u32) {
    s32 v = func_00105868(D_0032bb30);
    switch (v) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return func_00276fd0() == 100 ? 3 : 2;
    case 3:
        return func_00276fd0() == 100 ? 5 : 4;
    }
    return 0;
}
} // n001d9980

// 001d9a18 (from src/anon/batch_w84.cpp)
namespace n001d9a18 {
u64 func_00312db8(u64, u64) asm("func_00312db8");
extern u32 D_003638d0 asm("D_003638d0");
static inline u32 Rand() { return D_003638d0 = D_003638d0 * 69069; }
void wtarget_001d9a18(u32 a0, u32 a1, u32, u32) asm("func_001d9a18");
void wtarget_001d9a18(u32 a0, u32 a1, u32, u32) {
    u8* p = (u8*)a0;
    s32 n = a1;
    for (s32 i = 0; i < 5; i++) p[i] = 0;
    s32 r;
    if (n < 0) {
        r = func_00312db8(Rand(), 0x33333334);
    } else {
        r = (s32)((s64)((u64)Rand() << 2) >> 32);
        if (!(r < n)) r++;
    }
    p[r] = 2;
}
} // n001d9a18

// 001d9ad8 (from src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n001d9ad8 {
u32 func_001d9a18(u32, u32, u32, u32) asm("func_001d9a18");
extern u8 D_01d5baa0 asm("D_01d5baa0");
u32 func_001d9ad8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d9ad8");
u32 func_001d9ad8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d9a18((u32)&D_01d5baa0, a0, a2, a3);
}
} // n001d9ad8

// 001d9af8 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d9af8 {
extern u8 D_0036e648 asm("D_0036e648");
u32 func_001d9af8(u8* a0) asm("func_001d9af8");
u32 func_001d9af8(u8* a0) {
    u32 t11 = a0[0];
    u8* t12 = &D_0036e648;
    s32 t13 = 0;
    while (1) {
        u32 t15 = t12[0];
        if (t11 == t15) {
            u32 t14 = t12[1];
            u32 t15b = a0[1];
            if (t15b == t14) {
                return t13;
            }
        }
        t13 += 1;
        if (t13 < 5) {
            t12 += 2;
            continue;
        }
        break;
    }
    return 0;
}
} // n001d9af8

// 001d9b40 (from src/anon/batch_wcx2.cpp)
namespace n001d9b40 {
extern u8 D_01d5baa0[5] asm("D_01d5baa0");
extern u32 D_003638d0 asm("D_003638d0");
s32 func_001d9af8(void) asm("func_001d9af8");
u64 func_00312db8(u64, u64) asm("func_00312db8");
s32 func_001d9c68(u8*) asm("func_001d9c68");
void func_001d9ad8(s32) asm("func_001d9ad8");
bool func_001d9b40(void) asm("func_001d9b40");
bool func_001d9b40(void)
{
    s32 k = func_001d9af8();
    bool r = D_01d5baa0[k] == 2;
    D_01d5baa0[k] = 1;
    u8 buf[5];
    s32 n = 0;
    for (s32 i = 0; i < 5; i++) {
        if (!D_01d5baa0[i]) buf[n++] = i;
    }
    if (n > 0) {
        u32 seed = D_003638d0 *= 0x10dcd;
        u64 step = func_00312db8((u32)(n - 1) + 0x100000000ULL, (u32)n);
        D_01d5baa0[(s8)buf[(s32)func_00312db8(seed, step)]] = 2;
    }
    if (func_001d9c68(D_01d5baa0)) func_001d9ad8(k);
    return r;
}
} // n001d9b40

// 001d9c68 (from src/anon/batch_w23.cpp)
namespace n001d9c68 {
s32 func_001d9c68(u8* p) asm("func_001d9c68");
s32 func_001d9c68(u8* p) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (p[i] != 1) return 0;
    }
    return 1;
}
} // n001d9c68

// 001d9ca0 (from src/anon/batch_w16.cpp)
namespace n001d9ca0 {
void wtarget_001d9ca0(u32, u32, u32, u32);
void func_001d9a18(void*, s32) asm("func_001d9a18");
extern u8 D_01d5baa0 asm("D_01d5baa0");
void wtarget_001d9ca0(u32 a0, u32 a1, u32, u32) asm("func_001d9ca0");
void wtarget_001d9ca0(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) func_001d9a18(&D_01d5baa0, -1);
}
} // n001d9ca0

// 001d9ce0 (from src/anon/tiny_wrappers_more.cpp)
namespace n001d9ce0 {
u32 func_001d9ca0(u32, u32, u32, u32) asm("func_001d9ca0");
u32 func_001d9ce0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d9ce0");
u32 func_001d9ce0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d9ca0(0x00000001u, 0x0000ffffu, a2, a3);
}
} // n001d9ce0
