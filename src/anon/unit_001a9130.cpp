// Linked unit 0x1a9130-0x1aa980 (YS file 0x1a8618-0x1abad8, part).
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

// 001a9130 (from src/anon/tiny.cpp)
namespace n001a9130 {
extern u32 D_01c6cc48 asm("D_01c6cc48");
u32 func_001a9130(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a9130");
u32 func_001a9130(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_01c6cc48;
}
} // n001a9130

// 001a9140 (from src/anon/tiny_auto80_solver.cpp)
namespace n001a9140 {
extern u8 D_0032bb30 asm("D_0032bb30");
void func_001a9140(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001a9140");
void func_001a9140(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0032bb30;
    r5 = (u32)((s32)r5 + (-1));    r4 = (u32)(r4 + r15);
    r4 = (u32)((s32)r4 + (9184));
    *(u8*)((u32)r4 + (s32)(12)) = (u8)r5;
}
} // n001a9140

// 001a9160 (from src/anon/batch_w1669.cpp)
namespace n001a9160 {
extern u32 D_0032df30[] asm("D_0032df30");
void func_001a9160(u32 n) asm("func_001a9160");
void func_001a9160(u32 n) {
    D_0032df30[n >> 5] |= 1 << (n & 31);
}
} // n001a9160

// 001a9190 (from src/anon/tiny_auto80_solver.cpp)
namespace n001a9190 {
extern u8 D_0032df30 asm("D_0032df30");
void func_001a9190(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001a9190");
void func_001a9190(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = a0 >> 5;
    u32 base = (u32)&D_0032df30;
    idx <<= 2;
    idx += base;
    a0 &= 31;
    u32 mask = 1;
    u32 val = *(u32*)idx;
    mask <<= a0;
    mask = ~mask;
    val &= mask;
    *(u32*)idx = val;
}
} // n001a9190

// 001a91c8 (from src/anon/auto200_999.cpp, YS::SAVEFLAG::Check)
namespace n001a91c8 {
extern u8 D_0032df30 asm("D_0032df30");
u32 SAVEFLAG_Check(u32 a0) asm("_ZN2YS8SAVEFLAG5CheckEj");
u32 SAVEFLAG_Check(u32 a0) {
    u32 idx = a0 >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032df30 + (idx << 2));
    u32 bit = a0 & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    return (val & mask) != 0;
}
} // n001a91c8

// 001a91f8 (from src/anon/batch_w2.cpp)
namespace n001a91f8 {
void func_001a91f8(s32* p) asm("func_001a91f8");
void func_001a91f8(s32* p) {
    p[0] = -1;
    p[1] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
}
} // n001a91f8

// 001a9218 (from src/anon/auto80_199_queue.cpp)
namespace n001a9218 {
void func_001a9218(u32* a0) asm("func_001a9218");
void func_001a9218(u32* a0) {
    u32 v0 = func_0016f470(a0[2], 0);
    a0[3] = func_001708f8(v0, a0[0]);

    if (func_0016f6f8(a0[1]) == 0) {
        if (func_0016f770(a0[1]) == 0) {
            u32 t7 = ((u8*)(a0[2]))[0x48];
            t7 = t7 ^ 1;
            t7 = t7 & 1;
            if (t7 != 0) {
                v0 = func_0016f4b8(a0[2], 0);
                a0[4] = func_001708f8(v0, a0[0]);
            }
        }
    }

    if (func_0016f6f8(a0[1]) == 0) {
        v0 = func_0016f520(a0[2], a0[1], 0);
        if (v0 != 0) {
            a0[5] = func_001708f8(v0, 0xffffffffU);
        }
    }
}
} // n001a9218

// 001a92d8 (from src/anon/perm_001a92d8.cpp)
namespace n001a92d8 {
typedef signed int s32;
void func_001a9350(void *, s32, s32) asm("func_001a9350");
s32 func_0016e920(s32) asm("func_0016e920");
s32 func_001a9758(s32, s32) asm("func_001a9758");
void func_00170e58(void) asm("func_00170e58");
void func_001a9218(void *) asm("func_001a9218");
typedef struct B1
{
  s32 a;
  s32 f4;
  s32 f8;
} B1;
void func_001a92d8(B1 *p, s32 a, s32 b) asm("func_001a92d8");
void func_001a92d8(B1 *p, s32 a, s32 b)
{
  s32 new_var;
  new_var = b;
  func_001a9350(p, a, b);
  if (0 == new_var)
  {
    b = func_0016e920(a);
  }
  if (!func_001a9758(a, b))
  {
    if (a || p)
    {
      func_00170e58();
    }
    else
    {
      func_00170e58();
    }
  }
  p->f4 = a;
  (*p).f8 = b;
  func_001a9218(p);
}
} // n001a92d8

// 001a9350 (from src/anon/auto80_199_queue.cpp)
namespace n001a9350 {
void func_001a9350(u32* a0) asm("func_001a9350");
void func_001a9350(u32* a0) {
    u32 t7 = a0[3];
    if (t7 != 0) {
        func_00170950(t7);
    }

    t7 = a0[4];
    if (t7 != 0) {
        func_00170950(t7);
    }

    t7 = a0[5];
    if (t7 != 0) {
        func_00170950(t7);
    }

    func_001a91f8(a0);
}
} // n001a9350

// 001a93b0 (from src/anon/batch_w18.cpp)
namespace n001a93b0 {
void func_001a9350(void*) asm("func_001a9350");
void func_001a9218(void*) asm("func_001a9218");
void func_001a93b0(u32* p, u32 v) asm("func_001a93b0");
void func_001a93b0(u32* p, u32 v) {
    func_001a9350(p);
    *p = v;
    func_001a9218(p);
}
} // n001a93b0

// 001a93e8 (from src/anon/tiny_auto80_queue.cpp)
namespace n001a93e8 {
u32 func_00168b38(...) asm("func_00168b38");
u32 func_001a93e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001a93e8");
u32 func_001a93e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r5 = (u32)((s32)0u + (4));
    r6 = 0u;
    r4 = *(u32*)((u32)r4 + (s32)(12));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
} // n001a93e8

// 001a9420 (from src/anon/tiny_auto80_queue.cpp)
namespace n001a9420 {
u32 func_00168b38(...) asm("func_00168b38");
u32 func_001a9420(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001a9420");
u32 func_001a9420(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r5 = (u32)((s32)0u + (7));
    r6 = 0u;
    r4 = *(u32*)((u32)r4 + (s32)(12));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
} // n001a9420

// 001a9458 (from src/anon/batch_w78.cpp)
namespace n001a9458 {
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
s32 func_001a9780(u32) asm("func_001a9780");
u8* func_001a97b8(u32, s32) asm("func_001a97b8");
u8* func_00168b38(u8*, s32, s32) asm("func_00168b38");
u32 func_001a9458(u8* o, s32 a, s32 b) asm("func_001a9458");
u32 func_001a9458(u8* o, s32 a, s32 b) {
    u8* r = 0;
    if (func_001a9780(*(u32*)(o + 20))) {
        a *= 4;
        if (b >= 0) r = func_001a97b8(*(u32*)(o + 20), a + b);
        if (!r) {
            for (b = 3; b >= 0; b--) {
                r = func_001a97b8(*(u32*)(o + 20), a + b);
                if (r) break;
            }
        }
    } else {
        r = func_001a97b8(*(u32*)(o + 20), a);
    }
    u8* v;
    if (r && (v = func_00168b38(r, 9, 0)) != 0) return *(u32*)(v + 8);
    return 0;
}
} // n001a9458

// 001a9528 (from src/anon/tiny_auto80_queue.cpp)
namespace n001a9528 {
u32 func_00168b38(...) asm("func_00168b38");
u32 func_001a9528(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001a9528");
u32 func_001a9528(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r5 = (u32)((s32)0u + (18));
    r6 = 0u;
    r4 = *(u32*)((u32)r4 + (s32)(12));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
} // n001a9528

// 001a9560 (from src/anon/batch_w109.cpp)
namespace n001a9560 {
s32 func_001a9528(u8*) asm("func_001a9528");
void func_001dddd0(s32, s32) asm("func_001dddd0");
s32 func_001de168(s32, s32, s32, s32, s32, s32) asm("func_001de168");
void func_001a9560(u8* self, s32 a1, s32 a2, s32* out) asm("func_001a9560");
void func_001a9560(u8* self, s32 a1, s32 a2, s32* out) {
    s32 v = func_001a9528(self);
    if (!v) return;
    func_001dddd0(a2, v);
    u8* o = *(u8**)(self + 8);
    s32 i;
    switch (*(u16*)(o + 76)) {
    case 5013:
        for (i = 0; i < 3; i++) out[i] = func_001de168(a2, i, 0, 1, 0, a1);
        break;
    case 1016:
    case 5002:
        *out = func_001de168(a2, 0, 0, 1, 0, a1);
        break;
    case 5026:
        for (i = 0; i < 9; i++) out[i] = func_001de168(a2, i, 0, 1, 0, a1);
        break;
    case 5066:
        for (i = 0; i < 14; i++) out[i] = func_001de168(a2, i, 0, 1, 0, a1);
        break;
    default:
        switch (*(u32*)o) {
        case 2184: case 2186: case 2187: case 2188: case 2428:
            *out = func_001de168(a2, 0, 0, 1, 0, a1);
            break;
        case 2185:
            for (i = 0; i < 4; i++) out[i] = func_001de168(a2, i, 0, 1, 0, a1);
            break;
        }
        break;
    }
}
} // n001a9560

// 001a9758 (from src/anon/tiny_jal_wrappers.cpp)
namespace n001a9758 {
u32 func_0016f7d0(u32, u32, u32, u32) asm("func_0016f7d0");
u32 func_001a9758(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a9758");
u32 func_001a9758(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_0016f7d0(r4, r5, r6, r7);
    r15 = (u32)((s32)0u + (-13));
    r2 = (u32)(r2 & r15);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
} // n001a9758

// 001a9780 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001a9780 {
u32 func_001a9780(u32, u32, u32, u32) asm("func_001a9780");
u32 func_001a9780(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a9780");
u32 func_001a9780(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r2 = 0u;
    if (r4 != 0u) {
        r15 = *(u32*)((u32)r4 + (s32)(12));
        r2 = (u32)(r15 & 0x0001u);
    }
    return r2;
}
} // n001a9780

// 001a9798 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001a9798 {
u32 func_001a9798(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a9798");
u32 func_001a9798(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r2 = 0u;
    if (r4 != 0u) {
        r15 = *(u32*)((u32)r4 + (s32)(12));
        r15 = (u32)(r15 & 0x0002u);
        r2 = ((u32)0u < (u32)r15);
    }
    return r2;
}
} // n001a9798

// 001a97b8 (from src/anon/tiny_auto80_queue.cpp)
namespace n001a97b8 {
u32 func_00168b38(...) asm("func_00168b38");
u32 func_001a97b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001a97b8");
u32 func_001a97b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r6 = r5;
    r5 = (u32)((s32)0u + (-1));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
} // n001a97b8

// 001a97e8 (from src/anon/tiny.cpp)
namespace n001a97e8 {
void func_001a97e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a97e8");
void func_001a97e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01c7u << 16);
    *(u32*)((u32)b + (-13232)) = (u32)a0;
}
} // n001a97e8

// 001a97f8 (gap, never written before)
namespace n001a97f8 {
s32 func_001a97f8(s32 a, s32* b) asm("func_001a97f8");
s32 func_001a97f8(s32 a, s32* b) {
    a -= *b;
    return a;
}
} // n001a97f8

// 001a9808 (from src/anon/auto80_199_queue.cpp)
namespace n001a9808 {
u32 func_001a9808(u32 a0, s32 a1) asm("func_001a9808");
u32 func_001a9808(u32 a0, s32 a1) {
    s32 s0 = a1;
    if (s0 < 0) {
        s0 = D_0032bae0;
    }

    u32 a1v = D_01c6cc50[0];
    u32 a3v = 80;
    u32 a2v = *(u32*)(a1v + 4);
    u32 v0 = func_002fd248(a0, a1v + 8, a2v, a3v, (u32)func_001a97f8);
    return v0 + (s0 << 2) + 4;
}
} // n001a9808

// 001a9860 (from src/anon/auto80_199_queue.cpp)
namespace n001a9860 {
void func_001a9860(u32* a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_001a9860");
void func_001a9860(u32* a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    a0[0] = 0;
    a0[1] = func_001aae68(a1);
    a0[2] = a2;
    a0[4] = 0;
    a0[5] = 0;
    a0[6] = 0;
    func_00192f78(a0 + 9);

    a0[22] = a4;
    a0[19] = 0;
    a0[20] = 0;
    a0[21] = 0;
    a0[23] = 0;
    func_001a9970(a0, a3);
}
} // n001a9860

// 001a98e8 (from src/anon/auto200_999.cpp)
namespace n001a98e8 {
void func_00192f78(void *) asm("func_00192f78");
void func_001a9970(void *, u32) asm("func_001a9970");
u32 func_001aae68(u32) asm("func_001aae68");
void func_001a98e8(u32 *a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_001a98e8");
void func_001a98e8(u32 *a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    a0[0] = 0;
    a0[1] = func_001aae68(a1);
    a0[2] = a2;
    a0[4] = 0;
    a0[5] = 0;
    a0[6] = 0;
    func_00192f78(a0 + 9);

    a0[22] = a4;
    a0[19] = 0;
    a0[20] = 0;
    a0[21] = 0;
    a0[23] = 0;
    func_001a9970(a0, a3);
}
} // n001a98e8

// 001a9970 (from src/anon/batch_w242.cpp)
namespace n001a9970 {
struct S6 { u32 a[6]; };
void func_00192990(u32, u32, S6*, char*) asm("func_00192990");
void func_001aa388(char*, u32) asm("func_001aa388");
void func_001a9970(char* t, int n) asm("func_001a9970");
void func_001a9970(char* t, int n) {
    float f;
    if (n) {
        f = (float)n / (float)*(u8*)(*(u32*)(t + 4) + 17);
    } else {
        f = 1.0f;
    }
    *(float*)(t + 56) = f;
    *(float*)(t + 40) = f;
    u32 o = *(u32*)(t + 8);
    if (o) {
        S6 s = *(S6*)(t + 36);
        func_00192990(o, *(u32*)(t + 4), &s, t + 80);
        func_001aa388(t, *(u32*)(t + 8));
    }
}
} // n001a9970

// 001a9a28 (from src/anon/batch_w1793.cpp)
namespace n001a9a28 {
void func_001a9a28(u32 m, u32* p, u32* x, u32* y) asm("func_001a9a28");
void func_001a9a28(u32 m, u32* p, u32* x, u32* y) {
    switch (m) {
    case 1: *x -= p[0]; break;
    case 2: *x -= p[0] >> 1; break;
    case 3: *x -= p[0] >> 1; *y -= p[1] >> 1; break;
    case 4: *x -= p[0] >> 1; *y -= p[1]; break;
    case 5: *y -= p[1]; break;
    }
}
} // n001a9a28

// 001a9ae8 (from src/anon/batch_w92.cpp)
namespace n001a9ae8 {
struct Six1a9 { u32 w[6]; };
struct T1a9 {
    u32 f0, f4, f8, f12, f16, f20;
    f32 f24;
    u32 f28;
    Six1a9 f32_;
    u32 pad[2];
    u8 sub[16];
};
struct S1a9 {
    u32 f0; u32 f4; u32 f8; u8* f12; u8 f16[8]; u32 pad; f32 f28; u32 pad2; Six1a9 f36; u32 f60; u32 pad3; s32 f68; s32 f72; u32 pad4[3]; u32 f88;
};
extern f32 D_00349e10 asm("D_00349e10");
void func_001aa7f0(T1a9*, u32) asm("func_001aa7f0");
void func_001a9a28(u32, u8*, s32*, s32*) asm("func_001a9a28");
u32 func_001aa6f0(S1a9*, u32) asm("func_001aa6f0");
u32 func_00192a80(u8*) asm("func_00192a80");
void func_001aa850(T1a9*, u32) asm("func_001aa850");
u8* func_001a9c20(S1a9*, T1a9*, u8*) asm("func_001a9c20");
void func_001aa980(T1a9*) asm("func_001aa980");
void func_001b7f30(void*) asm("func_001b7f30");
void wt_001a9ae8(S1a9*, s32, s32, u32) asm("_Z16wtarget_001a9ae8jjjj");
void wt_001a9ae8(S1a9* self, s32 x, s32 y, u32 z) {
    u8* it = self->f12;
    if (!it) return;
    T1a9 t;
    func_001aa7f0(&t, self->f4);
    func_001a9a28(self->f88, self->f16, &x, &y);
    f32 f = self->f28 + D_00349e10;
    x = x * 16 + 28672;
    y = y * 16 + 29440;
    self->f28 = f;
    t.f8 = x;
    t.f24 = f;
    t.f12 = y;
    self->f68 = x;
    t.f16 = z;
    self->f72 = y;
    self->f60 = z;
    t.f32_ = self->f36;
    t.f28 = 0;
    t.f20 = func_001aa6f0(self, 0x60000000);
    do {
        func_001aa850(&t, func_00192a80(it));
        it = func_001a9c20(self, &t, it);
        func_001aa980(&t);
    } while (it);
    func_001b7f30(t.sub);
}
} // n001a9ae8

// 001a9c20 (from src/anon/batch_wcx2.cpp)
namespace n001a9c20 {
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
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
struct Font1a9c20 { s32 kind; u8 pad[13]; u8 height; u8 pad2[2]; s32 lineGap; bool IsRuby() { return kind == 4; } };
struct Style1a9c20 { s32 a; f32 scale; f32 alpha; s32 shift; s32 e, f; };
struct Ctx1a9c20 {
    Font1a9c20* font;
    s32 lines;
    s32 x;
    u32 y;
    s32 color;
    u8 pad0[4];
    f32 width;
    s32 count;
    Style1a9c20 style;
    s32 tab;
};
struct Cb1a9c20;
struct Cb1a9c20Vt { void* f[6]; void (*icon)(Cb1a9c20*, s32, s32, s32, u32); void* f7[4]; void (*sprite)(Cb1a9c20*, s32, s32, s32); void (*mark)(Cb1a9c20*, s32, u32, s32); };
struct Cb1a9c20 { Cb1a9c20Vt* vt; };
struct Out1a9c20 { s32 a, lines; };
struct Win1a9c20 {
    u32 flags;
    s32 msg;
    u8 pad0[16];
    Cb1a9c20* cb;
    u8 pad1[32];
    s32 defColor;
    u8 pad2[4];
    s32 baseX;
    u32 baseY;
    u8 pad3[16];
    f32 charW;
};
void func_00192818(u8*, s32, Style1a9c20*, Out1a9c20*) asm("func_00192818");
s32 func_00192440(u8*, s32) asm("func_00192440");
u8* func_00192388(u8*) asm("func_00192388");
s32 func_001aa310(Win1a9c20*, Ctx1a9c20*, s32) asm("func_001aa310");
void func_00192f98(Style1a9c20*) asm("func_00192f98");
s32* w1a9c20_FontStyleGet(s32, s32) asm("_ZN2YS9FONTSTYLE3GetEii");
s32 func_001aa6f0(Win1a9c20*, s32) asm("func_001aa6f0");
s32 func_001aa940(Ctx1a9c20*, s32, u32, s32, s32) asm("func_001aa940");
s32 func_001aae90(s32) asm("func_001aae90");
s32 func_00192498(u8*, s32) asm("func_00192498");
s32 func_00192450(u8*, s32) asm("func_00192450");
f32 func_00192fb8(Style1a9c20*) asm("func_00192fb8");
s32 func_001aa0a8(Win1a9c20*, Ctx1a9c20*, s32, u32, s32) asm("func_001aa0a8");
u8* func_001a9c20(Win1a9c20* w, Ctx1a9c20* c, u8* p) asm("func_001a9c20");
u8* func_001a9c20(Win1a9c20* w, Ctx1a9c20* c, u8* p)
{
    s32 prev = -1;
    Out1a9c20 out;
    Style1a9c20 st = c->style;
    out.a = 0;
    out.lines = 0;
    func_00192818(p, w->msg, &st, &out);
    s32 x = c->x;
    u32 y = c->y += out.lines * 16;
    while (p) {
        if (c->width < 0.0f) return 0;
        if (func_00192440(p, 0)) {
            switch (*p) {
            case 0:
            case 16:
                w->flags |= 1;
                return 0;
            case 1:
                x = func_001aa310(w, c, x);
                break;
            case 2:
                c->y += (c->font->lineGap + c->style.shift) * 16;
                return func_00192388(p);
            case 3:
                c->color = w->defColor;
                func_00192f98(&c->style);
                break;
            case 4:
                c->color = func_001aa6f0(w, *w1a9c20_FontStyleGet(p[1], -1));
                break;
            case 7:
                c->color = func_001aa6f0(w, p[1] | p[2] << 8 | p[3] << 16 | p[4] << 24);
                break;
            case 9: {
                s32 ch = p[1];
                if (!c->font->IsRuby() && func_001aa940(c, x, y, c->color, ch)) c->lines++;
                x += func_001aae90(ch) * 16;
                c->width -= w->charW;
                break;
            }
            case 10:
                c->style.scale = (f32)p[1] / (f32)c->font->height;
                break;
            case 11:
                c->style.alpha = p[1] / 100.0f;
                break;
            case 12:
                c->style.shift = p[1];
                break;
            case 14:
                c->tab = p[1] * 8;
                break;
            case 15:
                if (w->cb) {
                    s32 a = p[1];
                    s32 b = func_00192498(p, 2);
                    w->cb->vt->sprite(w->cb, a, b, func_00192498(p, 4));
                }
                break;
            case 17:
                c->x = x = w->baseX + func_00192498(p, 1) * 16;
                c->y = y = w->baseY + func_00192498(p, 3) * 16 - out.lines * 16;
                break;
            case 20:
                c->width -= (f32)func_00192498(p, 1);
                break;
            case 21:
                x += 512;
                if (w->cb) w->cb->vt->icon(w->cb, c->count, func_00192498(p, 1), (x - 0x7000) >> 4, (y - ((u32)(out.lines << 4) >> 1) - 0x7300) >> 4);
                c->count++;
                break;
            case 22:
                if (w->cb) w->cb->vt->mark(w->cb, x, y, p[1]);
                x += 512;
                break;
            }
        } else {
            s32 ch = func_00192450(p, 0);
            if (ch == 70 && prev == 70) {
                ch = 71;
                x -= (s32)(func_00192fb8(&c->style) * 32.0f);
            } else {
                prev = ch;
            }
            x = func_001aa0a8(w, c, x, y, ch);
            c->width -= w->charW;
        }
        p = func_00192388(p);
    }
    return p;
}
} // n001a9c20

// 001aa0a8 (from src/anon/batch_wcx2.cpp)
namespace n001aa0a8 {
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
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
struct Font1a9c20 { s32 kind; u8 pad[13]; u8 height; u8 pad2[2]; s32 lineGap; bool IsRuby() { return kind == 4; } };
struct Style1a9c20 { s32 a; f32 scale; f32 alpha; s32 shift; s32 e, f; };
struct Ctx1a9c20 {
    Font1a9c20* font;
    s32 lines;
    s32 x;
    u32 y;
    s32 color;
    u8 pad0[4];
    f32 width;
    s32 count;
    Style1a9c20 style;
    s32 tab;
};
struct Cb1a9c20;
struct Cb1a9c20Vt { void* f[6]; void (*icon)(Cb1a9c20*, s32, s32, s32, u32); void* f7[4]; void (*sprite)(Cb1a9c20*, s32, s32, s32); void (*mark)(Cb1a9c20*, s32, u32, s32); };
struct Cb1a9c20 { Cb1a9c20Vt* vt; };
struct Win1a9c20 {
    u32 flags;
    s32 msg;
    u8 pad0[16];
    Cb1a9c20* cb;
    u8 pad1[32];
    s32 defColor;
    u8 pad2[4];
    s32 baseX;
    u32 baseY;
    u8 pad3[16];
    f32 charW;
};
s32 func_001aa0a8(Win1a9c20*, Ctx1a9c20*, s32, u32, s32) asm("func_001aa0a8");
struct Font1aa0a8 { s32 kind; bool IsRuby() { return kind == 4; } };
struct Style1aa0a8 { s32 a; f32 scale; f32 alpha; s32 shift; s32 e, f; };
struct Ctx1aa0a8 {
    Font1aa0a8* font;
    s32 lines;
    s32 x;
    u32 y;
    u32 color;
    u32 shadow;
    f32 width;
    s32 count;
    Style1aa0a8 style;
};
struct Win1aa0a8 { u8 pad[76]; f32 fade; };
extern s32 D_00350a18[4] asm("D_00350a18");
s32 a0a8_001aa310(Win1aa0a8*, Ctx1aa0a8*, s32) asm("func_001aa310");
s32 func_001aa8a8(Ctx1aa0a8*, s32, u32, u32, s32) asm("func_001aa8a8");
s32 func_001aa8f0(Ctx1aa0a8*, s32, u32, u32, s32) asm("func_001aa8f0");
u32 func_001aae80(Font1aa0a8*, s32) asm("func_001aae80");
f32 a0a8_00192fb8(Style1aa0a8*) asm("func_00192fb8");
u32 __fixunssfsi(f32) asm("__fixunssfsi");
s32 func_001aa0a8(Win1a9c20* w_, Ctx1a9c20* c_, s32 x, u32 y, s32 ch) asm("func_001aa0a8");
s32 func_001aa0a8(Win1a9c20* w_, Ctx1a9c20* c_, s32 x, u32 y, s32 ch)
{
    Win1aa0a8* w = (Win1aa0a8*)w_;
    Ctx1aa0a8* c = (Ctx1aa0a8*)c_;
    u32 color = c->color;
    if (ch == 0) return a0a8_001aa310(w, c, x);
    Font1aa0a8* font = c->font;
    switch (font->kind) {
    case 2:
        for (s32 i = 0; i < 4; i++) {
            if (func_001aa8a8(c, x + D_00350a18[i], y + D_00350a18[(i + 1) & 3], c->shadow, ch)) c->lines++;
        }
        font = c->font;
        break;
    case 1:
        { s32 rr = func_001aa8a8(c, x + 32, y + 32, c->shadow, ch); font = c->font; if (rr) c->lines++; }
        break;
    }
    if (0.0f < w->fade && c->width / w->fade < 1.0f) {
        color = (color & 0xffffff) | (__fixunssfsi(c->width / w->fade * 128.0f) << 24);
    }
    s32 r;
    if (font->IsRuby()) r = func_001aa8f0(c, x, y, color, ch);
    else r = func_001aa8a8(c, x, y, color, ch);
    if (r) c->lines++;
    return x + (s32)(func_001aae80(c->font, ch) * a0a8_00192fb8(&c->style) + 0.5f) * 16;
}
} // n001aa0a8

// 001aa310 (from src/anon/batch_w40.cpp)
namespace n001aa310 {
s32 func_001ab820(u32) asm("func_001ab820");
f32 func_00192fb8(u32*) asm("func_00192fb8");
u8* func_001aa310(u32 a0, u32* a, u8* tbl) asm("func_001aa310");
u8* func_001aa310(u32 a0, u32* a, u8* tbl) {
    f32 s = (f32)func_001ab820(*a);
    return tbl + (s32)(s * func_00192fb8(a + 8) + 0.5f) * 16;
}
} // n001aa310

// 001aa388 (from src/anon/batch_w1962.cpp)
namespace n001aa388 {
struct W1962Cmd { u8 op; u8 a; u8 b; u8 c; };
struct W1962S24 { u32 w[6]; };
struct W1962S8 { u32 a, b; };
struct W1962Tgt;
typedef void (*W1962TF1)(W1962Tgt*, u8);
typedef void (*W1962TF3)(W1962Tgt*, u8, u8, u8);
struct W1962Tgt { void** vt; s32 f4; s32 f8; };
struct W1962Ob2 { u32 f0; u32 f4; u32 f8; W1962Cmd* cur; W1962S8 f10; W1962Tgt* tg; u32 f1c; u32 f20; W1962S24 s; u8 p3c[0x10]; f32 f4c; u8 p50[0xc]; f32 f5c; };
void func_00192940(W1962Cmd*, u32, W1962S24, W1962S8*) asm("func_00192940");
s32 func_00192440(W1962Cmd*, s32) asm("func_00192440");
W1962Cmd* func_00192388(W1962Cmd*) asm("func_00192388");
s32 func_00192498(W1962Cmd*, s32) asm("func_00192498");
void func_001991a8(s32, s32) asm("func_001991a8");
void wt_001aa388(W1962Ob2* o, W1962Cmd* c, u32, u32) asm("_Z16wtarget_001aa388jjjj");
void wt_001aa388(W1962Ob2* o, W1962Cmd* c, u32, u32) {
    W1962Cmd* p = c;
    o->f0 = 0;
    func_00192940(c, o->f4, o->s, &o->f10);
    o->f1c = 0;
    o->f20 = 0;
    while (p != 0) {
        if (func_00192440(p, 0)) {
            switch (p->op) {
            case 0: case 16:
                p = 0;
                break;
            case 6:
                if (o->tg) ((W1962TF1)o->tg->vt[9])(o->tg, p->a);
                break;
            case 8:
                if (o->tg) ((W1962TF3)o->tg->vt[10])(o->tg, p->a, p->b, p->c);
                break;
            case 18:
                func_001991a8(func_00192498(p, 1), 0);
                break;
            case 19: {
                W1962Tgt* t = o->tg;
                if (t) {
                    s32 x = func_00192498(p, 1);
                    s32 y = func_00192498(p, 3);
                    t->f4 = x;
                    t->f8 = y;
                }
                break;
            }
            case 21:
                o->f20++;
                break;
            case 23:
                o->f5c = p->a;
                o->f4c = p->b;
                break;
            }
        }
        if (p == 0) break;
        p = func_00192388(p);
    }
    o->cur = c;
}
} // n001aa388

// 001aa558 (from src/anon/batch_w98.cpp)
namespace n001aa558 {
s32 func_00192440(u8*, s32) asm("func_00192440");
u32 func_00192498(u8*, s32) asm("func_00192498");
u8* func_00192388(u8*) asm("func_00192388");
void func_001aa558(u8* o) asm("func_001aa558");
void func_001aa558(u8* o) {
    u8* n = *(u8**)(o + 12);
    while (n) {
        if (func_00192440(n, 0)) {
            switch (*n) {
            case 0:
            case 16:
                n = 0;
                break;
            case 5:
                if (*(u8**)(o + 24)) {
                    u32 a = func_00192498(n, 1);
                    u32 b = func_00192498(n, 3);
                    u32 c = func_00192498(n, 5);
                    u8* t = *(u8**)(o + 24);
                    (*(void (**)(u8*, u32, u32, u32))(*(u8**)t + 28))(t, a, b, c);
                }
                break;
            }
        }
        if (!n) break;
        n = func_00192388(n);
    }
}
} // n001aa558

// 001aa668 (from src/anon/tiny_wrappers_more.cpp)
namespace n001aa668 {
u32 func_001aa388(u32, u32, u32, u32) asm("func_001aa388");
u32 func_001aa668(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001aa668");
u32 func_001aa668(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 24u) = (u32)(a1);
    return func_001aa388(a0, ((u32)(*(u32*)((u32)(a0) + 12u))), a2, a3);
}
} // n001aa668

// 001aa688 (from src/anon/tiny_auto80_queue.cpp)
namespace n001aa688 {
u32 func_001923c8(...) asm("func_001923c8");
void func_001aa388(...) asm("func_001aa388");
u32 func_001aa688(u32 a0) asm("func_001aa688");
u32 func_001aa688(u32 a0) {
    u32 r = func_001923c8(*(u32*)(a0 + 0xC));
    u32 out = 0;
    if (r != 0u) {
        func_001aa388(a0, r);
        out = 1;
    }
    return out;
}
} // n001aa688

// 001aa6d0 (from src/anon/tiny_wrappers_more.cpp)
namespace n001aa6d0 {
u32 func_001aa388(u32, u32, u32, u32) asm("func_001aa388");
u32 func_001aa6d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001aa6d0");
u32 func_001aa6d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 48u) = (u32)(a1);
    return func_001aa388(a0, ((u32)(*(u32*)((u32)(a0) + 12u))), a2, a3);
}
} // n001aa6d0

// 001aa6f0 (from src/anon/auto200_999.cpp)
namespace n001aa6f0 {
u32 func_001aa6f0(u32 a0, u32 a1) asm("func_001aa6f0");
u32 func_001aa6f0(u32 a0, u32 a1) {
    u32 alpha = ((a1 >> 24) * *(u8 *)(a0 + 63)) >> 7;
    if (alpha >= 256) {
        alpha = 255;
    }
    return (a1 & 0x00ffffff) | (alpha << 24);
}
} // n001aa6f0

// 001aa728 (from src/anon/batch_w47.cpp)
namespace n001aa728 {
void func_001a98e8(void*, u32, u32, u32, u32) asm("func_001a98e8");
void func_001a9ae8(void*, u32, u32, u32) asm("func_001a9ae8");
void func_001aa728(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) asm("func_001aa728");
void func_001aa728(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    u8 t[96];
    func_001a98e8(t, a, b, f, g);
    func_001a9ae8(t, c, d, e);
}
} // n001aa728

// 001aa790 (from src/anon/batch_w29.cpp)
namespace n001aa790 {
struct Tri { u32 a, b, c; };
void func_00192f78(void*) asm("func_00192f78");
void func_001ab750(u32, void*) asm("func_001ab750");
void func_001aa790(u32* p, u32 a) asm("func_001aa790");
void func_001aa790(u32* p, u32 a) {
    p[0] = a;
    p[5] = 0x60000000;
    p[1] = 0;
    func_00192f78(p + 8);
    p[14] = 0;
    p[15] = 0;
    Tri* q = (Tri*)(p + 16);
    q->a = 0;
    q->c = 0;
    q->b = 0;
    p[19] = 0;
    func_001ab750(p[0], q);
}
} // n001aa790

// 001aa7f0 (from src/anon/batch_w30.cpp)
namespace n001aa7f0 {
void func_00192f78(void*) asm("func_00192f78");
void func_001ab750(u32, void*) asm("func_001ab750");
struct Q3 {
    u32 a, b, c;
};
void func_001aa7f0(u32* p, u32 a) asm("func_001aa7f0");
void func_001aa7f0(u32* p, u32 a) {
    p[0] = a;
    p[5] = 0x60000000;
    p[1] = 0;
    func_00192f78(p + 8);
    p[14] = 0;
    p[15] = 0;
    Q3* q = (Q3*)(p + 16);
    q->a = 0;
    q->c = 0;
    q->b = 0;
    p[19] = 0;
    func_001ab750(p[0], q);
}
} // n001aa7f0

// 001aa850 (from src/anon/auto80_199_queue.cpp)
namespace n001aa850 {
void func_001aa850(s32* a0, s32 a1) asm("func_001aa850");
void func_001aa850(s32* a0, s32 a1) {
    func_001b7e68(a0 + 16, (*(s32*)(a0[0] + 0x18) * a1) + 1);
    s32 t15 = a0[18];
    a0[1] = 0;
    s32 t14 = t15;
    t15 = t15 + 16;
    a0[19] = t14;
    a0[18] = t15;
}
} // n001aa850

// 001aa8a8 (from src/anon/batch_w29.cpp)
namespace n001aa8a8 {
u8 func_001aafe8(u32, u32*, u32, u32, u32, u32, f32, f32) asm("func_001aafe8");
u8 func_001aa8a8(u32* p, u32 a, u32 b, u32 c, u32 d) asm("func_001aa8a8");
u8 func_001aa8a8(u32* p, u32 a, u32 b, u32 c, u32 d) {
    return func_001aafe8(p[0], p + 16, a, b, c, d, *(f32*)(p + 9), *(f32*)(p + 10));
}
} // n001aa8a8

// 001aa8f0 (from src/anon/batch_w56.cpp)
namespace n001aa8f0 {
struct NoTail { ~NoTail() {} };
void func_001ab260(u32, u8*, u32, u32, u32, u32, u32, f32, f32) asm("func_001ab260");
void func_001aa8f0(u8* p, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_001aa8f0");
void func_001aa8f0(u8* p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    NoTail g;
    func_001ab260(*(u32*)p, p + 64, a1, a2, a3, a4, *(u32*)(p + 56), *(f32*)(p + 36), *(f32*)(p + 40));
}
} // n001aa8f0

// 001aa940 (from src/anon/batch_w16.cpp)
namespace n001aa940 {
u8 func_001ab598(u32, void*, u32, u32, u32, u32) asm("func_001ab598");
u8 func_001aa940(u8* p, u32 a, u32 b, u32 c, u32 d) asm("func_001aa940");
u8 func_001aa940(u8* p, u32 a, u32 b, u32 c, u32 d) {
    return func_001ab598(*(u32*)p, p + 64, a, b, c, d);
}
} // n001aa940

