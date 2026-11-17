// Linked unit 0x1a85b8-0x1a9110 (YS file 0x1a8618-0x1abad8, part).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"

#ifndef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#endif

// 001a85b8: C2 constructor copy (same body as the C1 at 0x1a8618)
namespace n001a85b8 {
void func_001a85b8(u32 a0, u32 a1, u32 a2) asm("func_001a85b8");
void func_001a85b8(u32 a0, u32 a1, u32 a2) {
    func_001980d0(a0, a1, 8, a2);
    *(u32*)a0 = (u32)&D_003509c0;
    u32 ok = func_00198738(a0, D_003509b0);
    *(u8*)(a0 + 2548) = (ok != 0);
    *(u32*)(a0 + 2552) = 0;
    *(u32*)(a0 + 1416) |= 0x200;
}
} // n001a85b8

// 001a8618 (from src/anon/auto80_199_queue.cpp)
namespace n001a8618 {
void func_001a8618(u32 a0, u32 a1, u32 a2) asm("func_001a8618");
void func_001a8618(u32 a0, u32 a1, u32 a2) {
    func_001980d0(a0, a1, 8, a2);
    *(u32*)a0 = (u32)&D_003509c0;
    u32 ok = func_00198738(a0, D_003509b0);
    *(u8*)(a0 + 2548) = (ok != 0);
    *(u32*)(a0 + 2552) = 0;
    *(u32*)(a0 + 1416) |= 0x200;
}
} // n001a8618

// 001a8678 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n001a8678 {
u32 func_0019f670(u32, u32, u32, u32) asm("func_0019f670");
u32 func_001a8678(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a8678");
u32 func_001a8678(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r5 = (u32)((s32)0u + (32));
    r6 = (u32)((s32)0u + (-1));
    r16 = r4;
    r4 = (u32)((s32)r4 + (1044));
    r2 = func_0019f670(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(264));
    r15 = (u32)(r15 | 0x0020u);
    *(u32*)((u32)r16 + (s32)(264)) = r15;
    return r2;
}
} // n001a8678

// 001a86b8 (from src/anon/batch_w78.cpp)
namespace n001a86b8 {
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vsub(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }
extern u8 D_0032bae0[] asm("D_0032bae0");
void func_00198450(u8*) asm("func_00198450");
u32 func_0016c008(u8*, s32) asm("func_0016c008");
u8* func_001a81f0(u8, u8, u32) asm("func_001a81f0");
s32 func_001a8450(u8*) asm("func_001a8450");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_001a8678(u8*) asm("func_001a8678");
void func_001a86b8(u8* o) asm("func_001a86b8");
void func_001a86b8(u8* o) {
    func_00198450(o);
    u8* d = D_0032bae0;
    u32 v = func_0016c008(o, 1);
    u8* r = func_001a81f0(d[0], d[1], v);
    *(u8**)(o + 2552) = r;
    if (!r) {
        func_0017f488(o + 320, 151, 0.0f, 0.0f);
        return;
    }
    if (func_001a8450(r)) {
        func_0017f488(o + 320, 152, 0.0f, 0.0f);
        func_001a8678(o);
    } else {
        func_0017f488(o + 320, 151, 0.0f, 0.0f);
    }
}
} // n001a86b8

// 001a8778 (from src/anon/batch_w1569.cpp)
namespace n001a8778 {
struct Ob1a8778 {
    u8 pad0[320];
    u8 sub[2548 - 320];
    u8 flag;
    u8 pad1[3];
    s32 p;
};
extern char D_0036d610[] asm("D_0036d610");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_00180378(void*, Ob1a8778*, s32, f32) asm("func_00180378");
void func_0017f5e0(void*, s32, s32, f32, f32) asm("func_0017f5e0");
void wt_1c0d38(Ob1a8778*, Ob1a8778*, u32, u32) asm("_Z16u_tail4_001c0d38jjjj");
void wt_1987a8(Ob1a8778*, char*, Ob1a8778*) asm("_Z16wtarget_001987a8jjjj");
s32 func_001a81f0(s32, s32, s32) asm("func_001a81f0");
void func_001a8418(s32) asm("func_001a8418");
void func_001a8678(Ob1a8778*) asm("func_001a8678");
void func_001a8548(void) asm("func_001a8548");
void func_001a8778(Ob1a8778* a, Ob1a8778* b) asm("func_001a8778");
void func_001a8778(Ob1a8778* a, Ob1a8778* b) {
    if (a->flag) {
        func_0017f488(a->sub, 153, 0.0f, 0.0f);
        func_00180378(a->sub, b, 252, 0.0f);
        func_0017f5e0(b->sub, 0, 0, 0.0f, 0.0f);
        wt_1c0d38(b, a, 16386, 1);
        wt_1987a8(a, D_0036d610, a);
    } else {
        func_0017f488(a->sub, 153, 8.0f, 0.0f);
        func_00180378(a->sub, b, 252, 8.0f);
        func_0017f5e0(b->sub, 0, 0, 0.0f, 0.0f);
    }
    if (a->p) {
        func_001a8418(a->p);
        func_001a8678(a);
    } else {
        func_001a8418(func_001a81f0(8, 0, 0));
        func_0017f5e0(a->sub, 151, 0, 0.0f, 0.0f);
    }
    if (!a->flag) func_001a8548();
}
} // n001a8778

// 001a8908 (from src/anon/tiny_auto80_solver.cpp)
namespace n001a8908 {
void func_001a8908(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001a8908");
void func_001a8908(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15;
    r14 = (u32)(0x01c7u << 16);
    *(volatile u32*)((u32)r14 + (s32)(-13304)) = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(4));
    r14 = (u32)((s32)0u + (52));
    r15 = (u32)(r15 * r14);
    r4 = (u32)(r4 + r15);
    r4 = (u32)((s32)r4 + (8));
    r15 = (u32)(0x01c7u << 16);
    *(volatile u32*)((u32)r15 + (s32)(-13300)) = r4;
}
} // n001a8908

// 001a8930 (from src/anon/batch_w85.cpp)
namespace n001a8930 {
s32 func_00181500(u32) asm("func_00181500");
u8* func_001947c0(u32, u32) asm("func_001947c0");
struct Cond1a8 { u16 id, need, without; u8 lv; };
s32 func_001a8930(Cond1a8* c, u32 id, u32 a2) asm("func_001a8930");
s32 func_001a8930(Cond1a8* c, u32 id, u32 a2) {
    s32 r = 0;
    if (c->id == 0 || c->id == id) {
        if (c->need == 0 || func_00181500(c->need)) {
            if (c->without == 0 || !func_00181500(c->without)) {
                if (c->lv == 0 || func_001947c0(a2, id)[52] == c->lv - 1) r = 1;
            }
        }
    }
    return r;
}
} // n001a8930

// 001a89f0 (from src/anon/batch_w442.cpp)
namespace n001a89f0 {
struct E1a8 { u32 w0, w4; s32 w8; s32 w12; u16 h[18]; };
struct T1a8 { u32 w0; s32 n; E1a8 e[1]; };
struct G1a8 { u8 pad[16]; u16 h[18]; };
extern T1a8* D_01c6cc08 asm("D_01c6cc08");
extern G1a8 D_01c6cc10 asm("D_01c6cc10");
extern u8 D_0032bae0[] asm("D_0032bae0");
s32 func_001a8930(E1a8*, u8, u8) asm("func_001a8930");
void func_0016fab0(s32, s32) asm("func_0016fab0");
void func_001a89f0(void) asm("func_001a89f0");
void func_001a89f0(void) {
    u8* p = D_0032bae0;
    s32 a = 0, b = 0;
    u8 k0 = p[0];
    s32 i;
    E1a8* e;
    for (i = 0; i < 18; i++) D_01c6cc10.h[i] = 0;
    e = D_01c6cc08->e;
    for (i = 0; i < D_01c6cc08->n; i++, e++) {
        if (func_001a8930(e, k0, p[1])) {
            s32 j;
            if (e->w8 > 0) a = e->w8;
            if (e->w12 > 0) b = e->w12;
            for (j = 0; j < 18; j++) {
                if (e->h[j] != 0) D_01c6cc10.h[j] = e->h[j];
            }
        }
    }
    func_0016fab0(a, b);
}
} // n001a89f0

// 001a8b28 (from src/anon/tiny.cpp)
namespace n001a8b28 {
extern u32 D_01c6cc10 asm("D_01c6cc10");
u32 func_001a8b28(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a8b28");
u32 func_001a8b28(u32 a0, u32 a1, u32 a2, u32 a3) {                     
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_01c6cc10;
}
} // n001a8b28

// 001a8b38 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n001a8b38 {
u32 func_001a8b28(u32, u32, u32, u32) asm("func_001a8b28");
u32 func_001a8b38(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a8b38");
u32 func_001a8b38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_001a8b28(r4, r5, r6, r7);                     
    r16 = (u32)(r16 << 1);
    r16 = (u32)(r16 + r2);
    r2 = (u32)(*(u16*)((u32)r16 + (s32)(16)));
    return r2;
}
} // n001a8b38

// 001a8b68 (from src/anon/tiny_auto80_queue.cpp)
namespace n001a8b68 {
u32 func_001a8b38(...) asm("func_001a8b38");
u32 func_0016e920(...) asm("func_0016e920");
u32 func_001a8b68(u32 a0) asm("func_001a8b68");
u32 func_001a8b68(u32 a0) {
    u32 r4 = a0, r2, r15;
    r2 = ((u32(*)())func_001a8b38)();
    r4 = r2;
    r15 = 0u;
    if (r2 != 0u) {
        r2 = ((u32(*)(u32))func_0016e920)(r4);
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(76)));
    }
    r2 = r15;
    return r2;
}
} // n001a8b68

// 001a8ba0 (gap: twin of 0x001a8bb8)
namespace n001a8ba0 {
void func_001a8ba0(u8* p) asm("func_001a8ba0");
void func_001a8ba0(u8* p) {                         
    p[0] = 0;
    p[1] = 18;
    p[2] = 18;
    p[3] = 18;
}
} // n001a8ba0

// 001a8bb8 (from src/anon/batch_w3.cpp)
namespace n001a8bb8 {
void func_001a8bb8(u8* p) asm("func_001a8bb8");
void func_001a8bb8(u8* p) {                         
    p[0] = 0;
    p[1] = 18;
    p[2] = 18;
    p[3] = 18;
}
} // n001a8bb8

// 001a8bd0 (from src/yasui/libys/member.cpp, YS::MEMBER::Get)
namespace n001a8bd0 {
extern u8 D_0032bae0 asm("D_0032bae0");
extern u8 D_0032f064 asm("D_0032f064");
u32 MEMBER_Get(s32 index) asm("_ZN2YS6MEMBER3GetEi");
u32 MEMBER_Get(s32 index) {
    if (index < 0) {
        index = (s32)(u32)D_0032bae0;
    }
    return (u32)((u32)index << 2) + (u32)&D_0032f064;
}
} // n001a8bd0

// 001a8bf8 (from src/anon/batch_w5.cpp)
namespace n001a8bf8 {
u8 func_001a8bf8(u8* p, s32 i) asm("func_001a8bf8");
u8 func_001a8bf8(u8* p, s32 i) {                 
    return p[i] & 0x1f;
}
} // n001a8bf8

// 001a8c10 (from src/anon/tiny_auto80_queue.cpp)
namespace n001a8c10 {
u32 func_0016e920(...) asm("func_0016e920");
u32 func_001a8b28(...) asm("func_001a8b28");
u32 func_001a8bf8(...) asm("func_001a8bf8");
u32 func_001a8c10(u32 a0) asm("func_001a8c10");
u32 func_001a8c10(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r2 = ((u32(*)())func_001a8bf8)();
    r16 = r2;
    r15 = (u32)((s32)0u + (18));
    r2 = 0u;
    if (r16 != r15) {
        r2 = ((u32(*)())func_001a8b28)();
        r15 = (u32)(r16 << 1);
        r15 = (u32)(r15 + r2);
        r4 = (u32)(*(u16*)((u32)r15 + (s32)(16)));
        r2 = ((u32(*)(u32))func_0016e920)(r4);
        r2 = (u32)(*(u16*)((u32)r2 + (s32)(76)));
    }
    return r2;
}
} // n001a8c10

// 001a8c60 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001a8c60 {
void func_001a8c60(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a8c60");
void func_001a8c60(u32 a0, u32 a1, u32 a2, u32 a3) {                      
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    r15 = (u32)((s32)0u + (-97));
    r4 = (u32)(r4 + r5);
    r6 = (u32)(r6 & r15);
    *(u8*)((u32)r4 + (s32)(0)) = (u8)r6;
}
} // n001a8c60

// 001a8c78 (from src/anon/batch_w34.cpp)
namespace n001a8c78 {
s32 func_001c9db0(u32) asm("func_001c9db0");
s32 func_001a8c78(u8* p, s32 n) asm("func_001a8c78");
s32 func_001a8c78(u8* p, s32 n) {
    s32 r = 0;
    u8* q = p + n;
    if (n == 0 || (*q & 0x80) || func_001c9db0(*q & 0x1f)) r = 1;
    return r;
}
} // n001a8c78

// 001a8cd0 (from src/anon/batch_w42.cpp)
namespace n001a8cd0 {
s32 func_001a8bf8(u32, s32) asm("func_001a8bf8");
s32 func_001a8cd0(u32 a0, u32 a1) asm("func_001a8cd0");
s32 func_001a8cd0(u32 a0, u32 a1)
{
    s32 k = a1 & 0x1f;
    if (k == 18) return -1;
    for (s32 i = 0; i < 4; i++) {
        if (func_001a8bf8(a0, i) == k) return i;
    }
    return -1;
}
} // n001a8cd0

// 001a8d40 (from src/anon/batch_w3703.cpp)
namespace n001a8d40 {
struct T4 { u8 b[4]; };
extern T4* D_01c6cc0c asm("D_01c6cc0c");
void func_001a8bb8(T4*) asm("func_001a8bb8");
s32 func_001a8bf8(T4*, s32) asm("func_001a8bf8");
void func_001a8c60(T4*, s32, s32) asm("func_001a8c60");
s32 func_001a8cd0(T4*, s32) asm("func_001a8cd0");
void func_001a8d40(T4* out, s32 idx) asm("func_001a8d40");
void func_001a8d40(T4* out, s32 idx)
{
    T4 a, b;
    s32 j;
    register s32 i asm("$18");                                                                     
    func_001a8bb8(&a);
    func_001a8bb8(&b);
    a = D_01c6cc0c[idx];
    func_001a8c60(&b, 0, func_001a8bf8(&a, 0));
    j = 1;
    i = 1;
    s32 m = ~0x3f;
    for (; i < 4; i++) {
        s32 c = a.b[i];
        if (m & c) {
            func_001a8c60(&b, j, (u8)c);
            j++;
            a.b[i] = 18;
        }
    }
    for (i = 1; i < 4; i++) {
        s32 k = func_001a8cd0(&a, func_001a8bf8(out, i));
        if (k >= 0) {
            func_001a8c60(&b, j, func_001a8bf8(out, i));
            j++;
            a.b[k] = 18;
        }
    }
    for (i = 1; i < 4; i++) {
        if (func_001a8bf8(&a, i) != 18) {
            func_001a8c60(&b, j, a.b[i]);
            j++;
        }
    }
    for (; j < 4; j++) func_001a8c60(&b, j, 18);
    *out = b;
}
} // n001a8d40

// 001a8f10 (from src/anon/batch_w35.cpp)
namespace n001a8f10 {
s32 func_001a8f10(s32 x) asm("func_001a8f10");
s32 func_001a8f10(s32 x) {                  
    switch (x) {
    case 1: case 14: return 0;
    case 2: return 1;
    case 3: return 2;
    }
    return 3;
}
} // n001a8f10

// 001a8f68 (from src/anon/batch_w54.cpp)
namespace n001a8f68 {
s32 func_001a8f10(void*) asm("func_001a8f10");
s32 func_001a8bf8(void*, s32) asm("func_001a8bf8");
void func_001a8c60(void*, s32, s32) asm("func_001a8c60");
void func_001a8f68(void* a0, void* a1) asm("func_001a8f68");
void func_001a8f68(void* a0, void* a1) {
    s32 v = func_001a8f10(a1);                  
    s32 i;
    for (i = 1; i < 3; i++) {
        if (func_001a8bf8(a0, i) == v) {                 
            func_001a8c60(a0, i, func_001a8bf8(a0, 3));                      
            break;
        }
    }
    func_001a8c60(a0, 3, v);                      
}
} // n001a8f68

// 001a8ff8 (from src/anon/auto200_999.cpp)
namespace n001a8ff8 {
void func_001a8ff8(u32 a0, u32 a1, u32 a2) asm("func_001a8ff8");
void func_001a8ff8(u32 a0, u32 a1, u32 a2) {               
    u8 *p1 = (u8 *)(a0 + a1);
    u8 *p2 = (u8 *)(a0 + a2);
    u8 v1 = *p1;
    u8 v2 = *p2;
    *p1 = v2;
    *p2 = v1;
}
} // n001a8ff8

// 001a9018 (from src/anon/auto80_199_queue.cpp)
namespace n001a9018 {
s32 func_001a9018(u32 a0, s32 a1) asm("func_001a9018");
s32 func_001a9018(u32 a0, s32 a1) {
    s32 i = 0;
    do {
        if (func_001a8c10(a0, i) == a1) {
            return i;
        }
        i = i + 1;
    } while (i < 4);
    return -1;
}
} // n001a9018

// 001a9080 (from src/yasui/libys/member.cpp, YS::MEMBER::is_exist)
namespace n001a9080 {
u32 func_001a9018(u32, u32) asm("func_001a9018");
u32 MEMBER_is_exist(const void* self, s32 index) asm("_ZNK2YS6MEMBER8is_existEi");
u32 MEMBER_is_exist(const void* self, s32 index) {
    u32 r2 = func_001a9018((u32)self, (u32)index);
    r2 = (u32)(~(0u | r2));
    r2 = (u32)(r2 >> 31);
    return r2;
}
} // n001a9080

// 001a90a8 (from src/anon/tiny_auto80_queue.cpp)
namespace n001a90a8 {
u32 func_001a8c78(...) asm("func_001a8c78");
u32 func_001a9018(...) asm("func_001a9018");
u32 func_001a90a8(u32 a0, u32 a1) asm("func_001a90a8");
u32 func_001a90a8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001a9018)(r4, r5);
    r4 = r16;
    r5 = r2;
    r15 = 0u;
    if ((s32)r2 >= 0) {
        r2 = ((u32(*)(u32,u32))func_001a8c78)(r4, r5);
        r15 = ((u32)0u < (u32)r2);
    }
    r2 = r15;
    return r2;
}
} // n001a90a8

// 001a90f0 (from src/anon/batch_w3.cpp)
namespace n001a90f0 {
u32 func_001a8f10() asm("func_001a8f10");
void func_001a8b38(u32) asm("func_001a8b38");
void func_001a90f0() asm("func_001a90f0");
void func_001a90f0() { func_001a8b38(func_001a8f10()); }
} // n001a90f0

