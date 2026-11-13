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

// 001d68e0 (from src/anon/tiny.cpp)
namespace n001d68e0 {
void func_001bde88(void*) asm("func_001bde88");
void func_001d68e0(BD_VALUE* bd) asm("func_001d68e0");
void func_001d68e0(BD_VALUE* bd) { func_001bde88(bd); }
} // n001d68e0

// 001d68f8 (from src/anon/tiny_auto80_solver.cpp)
namespace n001d68f8 {
u32 func_001bded8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001bded8");
u32 func_001d68f8(u32) asm("func_001d68f8");
u32 func_001d6a80(u32) asm("func_001d6a80");
u32 func_001d68f8(u32 a0) asm("func_001d68f8");
u32 func_001d68f8(u32 a0) {
    u32 s0 = a0;
    *(u32*)(a0 + 2800) = 0;
    *(u32*)(a0 + 2804) = 0;
    ((u32(*)(u32))func_001d6a80)(a0);
    u32 v0 = ((u32(*)(u32))func_001bded8)(s0);
    *(u8*)(s0 + 2808) = 15;
    return v0;
}
} // n001d68f8

// 001d6938 (from src/anon/batch_w50.cpp)
namespace n001d6938 {
extern void* D_003527e0 asm("D_003527e0");
void func_0019c9e0(void*) asm("func_0019c9e0");
void func_0013ddc0(s32, void*) asm("func_0013ddc0");
void func_001bdf38(void*, void*, u32) asm("func_001bdf38");
void func_001d6ab0(void*) asm("func_001d6ab0");
void func_001d6938(u8* o, u8* p) asm("func_001d6938");
void func_001d6938(u8* o, u8* p) {
    D_003527e0 = o;
    func_0019c9e0(o + 2752);
    if (*(u32*)(p + 1164)) func_0013ddc0(0, p);
    if (!*(u32*)(o + 2804)) func_001bdf38(o, p, *(u32*)(p + 2872));
    else *(u8**)(o + 2528) = p;
    *(u8**)(o + 2804) = p;
    if (!o[2808]) func_001d6ab0(o);
}
} // n001d6938

// 001d69d0 (from src/anon/batch_w58.cpp)
namespace n001d69d0 {
void func_001d6a28(u8*) asm("func_001d6a28");
void func_0019ca20(u8*) asm("func_0019ca20");
void func_0013dde8(s32) asm("func_0013dde8");
void func_001befa8(u8*) asm("func_001befa8");
extern u32 D_003527e0 asm("D_003527e0");
void func_001d69d0(u8* p) asm("func_001d69d0");
void func_001d69d0(u8* p) {
    func_001d6a28(p);
    func_0019ca20(p + 2752);
    if (*(u32*)(*(u8**)(p + 2804) + 1164)) func_0013dde8(0);
    func_001befa8(p);
    *(u32*)(p + 2804) = 0;
    D_003527e0 = 0;
}
} // n001d69d0

// 001d6a28 (from src/anon/auto80_199_queue.cpp)
namespace n001d6a28 {
void func_001d6a28(u32 a0) asm("func_001d6a28");
void func_001d6a28(u32 a0) {
    u32 s16 = a0;
    func_0019d720(s16 + 2552);

    *(u32*)(s16 + 2584) = *(u32*)(s16 + 2584) & ~1u;
    *(u32*)(s16 + 32) = *(u32*)(s16 + 32) | 1u;
    *(u32*)(s16 + 2800) = *(u32*)(s16 + 2800) & ~1u;
    *(u8*)(s16 + 2808) = 0;
}
} // n001d6a28

// 001d6a80 (from src/anon/tiny_auto80_solver.cpp)
namespace n001d6a80 {
u32 func_0019cc20(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0019cc20");
u32 func_001d6a28(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d6a28");
u32 func_001d6a80(u32) asm("func_001d6a80");
u32 func_001d6a80(u32 a0) asm("func_001d6a80");
u32 func_001d6a80(u32 a0) {
    u32 s0 = a0;
    ((u32(*)(u32))func_0019cc20)(a0 + 2752);
    return ((u32(*)(u32))func_001d6a28)(s0);
}
} // n001d6a80

// 001d6ab0 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001d6ab0 {
void func_001d6ab0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d6ab0");
void func_001d6ab0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r12, r13, r14, r15;
    r14 = *(u32*)((u32)r4 + (s32)(2584));
    r15 = (u32)((s32)0u + (-2));
    r13 = *(u32*)((u32)r4 + (s32)(32));
    r12 = *(u32*)((u32)r4 + (s32)(2800));
    r14 = (u32)(r14 | 0x0001u);
    r13 = (u32)(r13 & r15);
    *(u32*)((u32)r4 + (s32)(2584)) = r14;
    r12 = (u32)(r12 | 0x0001u);
    *(u32*)((u32)r4 + (s32)(32)) = r13;
    *(u32*)((u32)r4 + (s32)(2800)) = r12;
    *(u8*)((u32)r4 + (s32)(2808)) = (u8)0u;
}
} // n001d6ab0

// 001d6ae0 (from src/anon/auto80_199_queue.cpp)
namespace n001d6ae0 {
void func_001a26b8(u32 a0) asm("func_001a26b8");
void func_001d6ae0(u32 a0) asm("func_001d6ae0");
void func_001d6ae0(u32 a0) {
    u32 s16 = a0;
    if ((*(u32*)(s16 + 2800) & 0x2u) == 0) {
        func_0013b348();
        func_001bdc48(s16);
        u32 t7 = *(u32*)(s16 + 2804);
        u32 t6 = *(u32*)(t7 + 1164);
        if (t6 != 0) {
            func_001a26b8(t6);
        }
        *(u32*)(s16 + 2800) = *(u32*)(s16 + 2800) | 0x2u;
    }
}
} // n001d6ae0

// 001d6b40 (from src/anon/auto80_199_queue.cpp)
namespace n001d6b40 {
void func_001d6b40(u32 a0) asm("func_001d6b40");
void func_001d6b40(u32 a0) {
    u32 s16 = a0;
    if ((*(u32*)(s16 + 2800) & 0x2u) != 0) {
        func_001bdc88();
        u32 t7 = *(u32*)(s16 + 2804);
        u32 t6 = *(u32*)(t7 + 1164);
        if (t6 != 0) {
            func_001a2710(t6);
        }
        *(u32*)(s16 + 2800) = *(u32*)(s16 + 2800) & ~2u;
    }
}
} // n001d6b40

// 001d6ba0 (from src/anon/batch_wcx.cpp)
namespace n001d6ba0 {
void func_0019d188(u8*) asm("func_0019d188");
void func_001bd6a8(u8*) asm("func_001bd6a8");
void func_001d6ab0(u8*) asm("func_001d6ab0");
typedef s32 (*Fn64)(u8*);
void func_001d6ba0(u8* p) asm("func_001d6ba0");
void func_001d6ba0(u8* p)
{
    if (!*(u8**)(p + 2804)) return;
    struct BF { u32 on : 1; };
    if ((u8)((BF*)(p + 2800))->on) func_0019d188(p + 2752);
    func_001bd6a8(p);
    u8 c = p[2808];
    if (!c) return;
    if (c < 2) {
        u8* o = *(u8**)(p + 2804);
        if (!(*(Fn64*)(*(u8**)o + 64))(o)) return;
    }
    if (--p[2808] == 0) func_001d6ab0(p);
}
} // n001d6ba0

// 001d6c48 (never written before)
namespace n001d6c48 {
extern u32 D_003527e0 asm("D_003527e0");
u32 func_001d6c48() asm("func_001d6c48");
u32 func_001d6c48() { return D_003527e0; }
} // n001d6c48

// 001d6c58 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d6c58 {
u32 func_001d6a80(...) asm("func_001d6a80");
extern u8 D_003527e0 asm("D_003527e0");
void func_001d6c58(void) asm("func_001d6c58");
void func_001d6c58(void) {
    u32 t6 = *(u32*)((u32)&D_003527e0 + (s32)(0));
    if (t6 != 0u) {
        func_001d6a80(t6);
    }
}
} // n001d6c58

// 001d6c88 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d6c88 {
u32 func_001d6ab0(...) asm("func_001d6ab0");
extern u8 D_003527e0 asm("D_003527e0");
void func_001d6c88(void) asm("func_001d6c88");
void func_001d6c88(void) {
    u32 t6 = *(u32*)((u32)&D_003527e0 + (s32)(0));
    if (t6 != 0u) {
        func_001d6ab0(t6);
    }
}
} // n001d6c88

// 001d6cb8 (from src/anon/tiny.cpp)
namespace n001d6cb8 {
void func_001d6cb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d6cb8");
void func_001d6cb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d6u << 16);
    *(u32*)((u32)b + (-17768)) = (u32)a0;
}
} // n001d6cb8

// 001d6cc8 (from src/anon/batch_w2361.cpp)
namespace n001d6cc8 {
struct W2361Ent { u8 d[64]; };
struct W2361Tab { u32 x; s32 n; W2361Ent e[1]; };
extern W2361Tab* D_01d5ba98 asm("D_01d5ba98");
W2361Ent* func_001d6cc8(W2361Ent* e) asm("func_001d6cc8");
W2361Ent* func_001d6cc8(W2361Ent* e) {
    if (!e) e = D_01d5ba98->e;
    else {
        e++;
        if (!(e < D_01d5ba98->e + D_01d5ba98->n)) e = 0;
    }
    return e;
}
} // n001d6cc8

// 001d6d00 (from src/anon/batch_w59.cpp)
namespace n001d6d00 {
struct Ent1d6 { u8 d[64]; };
struct Tbl1d6 { u8 hdr[8]; Ent1d6 e[1]; };
extern Tbl1d6* D_01d5ba98 asm("D_01d5ba98");
u16* func_001d6cc8(u16*) asm("func_001d6cc8");
s32 func_001d6d00(u32 id) asm("func_001d6d00");
s32 func_001d6d00(u32 id) {
    u16* e = 0;
    while ((e = func_001d6cc8(e))) {
        if (*e == id) return (Ent1d6*)e - D_01d5ba98->e + 1;
    }
    return 0;
}
} // n001d6d00

// 001d6d58 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d6d58 {
extern u8* D_01d5ba98 asm("D_01d5ba98");
u8* func_001d6d58(s32 a0) asm("func_001d6d58");
u8* func_001d6d58(s32 a0) {
    u8* t6;
    if (a0 <= 0) {
        goto ret0;
    }
    t6 = D_01d5ba98;
    if (*(s32*)(t6 + 4) < a0) {
        goto ret0;
    }
    return t6 + (a0 << 6) - 56;
ret0:
    return 0;
}
} // n001d6d58

// 001d6d88 (from src/anon/tiny_wrappers_imp.cpp)
namespace n001d6d88 {
u32 func_001d6d58(u32, u32, u32, u32) asm("func_001d6d58");
u32 func_001d6d88(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d6d88");
u32 func_001d6d88(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0033u << 16);
    r4 = (u32)(*(u8*)((u32)r15 + (s32)(-4011)));
    return func_001d6d58(r4, r5, r6, r7);
}
} // n001d6d88

// 001d6da8 (from src/anon/batch_w49.cpp)
namespace n001d6da8 {
u8* func_001d6cc8(u8*) asm("func_001d6cc8");
s32 func_001a3570(u16) asm("func_001a3570");
void func_001d6da8(u16* out) asm("func_001d6da8");
void func_001d6da8(u16* out) {
    u8* n = 0;
    while ((n = func_001d6cc8(n)) != 0)
        if (func_001a3570(*(u16*)(n + 2)) > 0) *out++ = *(u16*)n;
    *out = 0;
}
} // n001d6da8

// 001d6e08 (from src/anon/batch_w28.cpp)
namespace n001d6e08 {
void func_0016ed50(u32, s32, u32) asm("func_0016ed50");
void func_001d6e08(u8* p) asm("func_001d6e08");
void func_001d6e08(u8* p) {
    u32* q = (u32*)(p + 4);
    for (s32 i = 1; i >= 0; i--) {
        u32 x = *q++;
        if (x) func_0016ed50(x, -1, 30);
    }
}
} // n001d6e08

// 001d6e60 (from src/anon/batch_w39.cpp)
namespace n001d6e60 {
struct S1d6 { u32 a; u32 n; };
extern S1d6* D_01d5ba98 asm("D_01d5ba98");
void func_001d6da8(u16*) asm("func_001d6da8");
int func_001d6e60(void) asm("func_001d6e60");
int func_001d6e60(void) {
    u16 buf[D_01d5ba98->n + 1];
    func_001d6da8(buf);
    return buf[0] != 0;
}
} // n001d6e60

// 001d6ec8 (from src/anon/batch_w36.cpp)
namespace n001d6ec8 {
u8* func_001d6cc8(u8*) asm("func_001d6cc8");
s32 func_001a3570(u16) asm("func_001a3570");
s32 func_001d6ec8(void) asm("func_001d6ec8");
s32 func_001d6ec8(void) {
    s32 n = 2;
    u8* p = 0;
    while ((p = func_001d6cc8(p)) != 0) n += func_001a3570(*(u16*)(p + 2)) > 0;
    if (n == 6) n++;
    return n;
}
} // n001d6ec8

// 001d6f28 (from src/anon/batch_w78.cpp)
namespace n001d6f28 {
s32 func_001bbb28(void) asm("func_001bbb28");
u8* func_001d5cd0(void) asm("func_001d5cd0");
void func_001d7000(u8, u8*) asm("func_001d7000");
void func_001b7468(u32) asm("func_001b7468");
extern u8 D_0032e020[] asm("D_0032e020");
extern u32 D_0034e948 asm("D_0034e948");
void func_001d6f28(s32 n) asm("func_001d6f28");
void func_001d6f28(s32 n) {
    if (n <= 0) return;
    if (func_001bbb28()) return;
    u8* g = D_0032e020;
    s32 up = 0;
    *(s32*)(g + 4596) += n;
    while (1) {
        u8* e = func_001d5cd0();
        if (!e) { *(s32*)(g + 4596) = 0; break; }
        if (*(s32*)(g + 4596) < *(s32*)(e + 4)) break;
        up = 1;
        u8 lv = ++g[4150];
        *(s32*)(g + 4596) -= *(s32*)(e + 4);
        func_001d7000(lv, e);
    }
    if (up) func_001b7468(D_0034e948);
}
} // n001d6f28

// 001d7000 (from src/anon/auto80_199_queue.cpp)
namespace n001d7000 {
void func_001b7538(u32 a0, u32 a1) asm("func_001b7538");
void func_001d7000(u32 a0, u32 a1) asm("func_001d7000");
void func_001d7000(u32 a0, u32 a1) {
    u8 buf[80];
    u32 s16 = a1;
    u32 s17 = a0;
    u32 s18 = D_0034e948;

    func_001b74b8((u32)buf);
    func_001b74c8((u32)buf, 0xc5bd);

    u32 t7 = *(u16*)(s16 + 2);
    if (t7 != 0) {
        func_001a3188(t7, 1, 0);
        func_001b7538((u32)buf, *(u16*)(s16 + 2));
    }

    func_001b7768((u32)buf, s17);
    func_001a1460(*(u32*)(s18 + 1164));
    func_001d7778();
}
} // n001d7000

// 001d7098 (from src/anon/batch_w92.cpp)
namespace n001d7098 {
void func_001ada38(s32) asm("func_001ada38");
void func_002bea20(void) asm("func_002bea20");
void* func_00188fe0(void*, s32) asm("func_00188fe0");
void func_00188bf8(void*, s32) asm("func_00188bf8");
void func_00189028(void*, s32, s32, s32) asm("func_00189028");
extern s32 D_0034ece8 asm("D_0034ece8");
extern u8 D_0032e020 asm("D_0032e020");
void func_001d7098(s32 id) asm("func_001d7098");
void func_001d7098(s32 id) {
    switch (id) {
    case 12:
        func_001ada38(1);
        D_0034ece8 = 4;
        func_002bea20();
        break;
    case 50: case 51: case 52:
        D_0034ece8 = 3;
        break;
    case 176: case 179: case 184:
        func_00188bf8(func_00188fe0(&D_0032e020, 1), 41);
        break;
    case 182: case 183: case 186: case 296: case 297: case 298:
        func_00188bf8(func_00188fe0(&D_0032e020, 1), 384);
        break;
    case 187:
        func_00189028(&D_0032e020, 1, 41, 0);
        break;
    case 189:
        func_00188bf8(func_00188fe0(&D_0032e020, 1), 43);
        break;
    }
}
} // n001d7098

// 001d71f0 (from src/anon/batch_w4.cpp)
namespace n001d71f0 {
void func_002bea60(void) asm("func_002bea60");
void func_001d71f0(s32 a) asm("func_001d71f0");
void func_001d71f0(s32 a) {
    if (a == 12) func_002bea60();
}
} // n001d71f0

// 001d7218 (from src/anon/batch_wcx2.cpp)
namespace n001d7218 {
void func_002d1270(s32, s32) asm("func_002d1270");
void func_002d6f28(s32, s32) asm("func_002d6f28");
void func_002dc278(s32, s32) asm("func_002dc278");
void func_002bea88(void) asm("func_002bea88");
void func_001cebb0(void) asm("func_001cebb0");
void func_002e0bb0(s32) asm("func_002e0bb0");
void func_002e1f40(s32) asm("func_002e1f40");
void func_001d7218(s32 k) asm("func_001d7218");
void func_001d7218(s32 k)
{
    switch (k) {
    case 3: func_002d1270(1, 0); break;
    case 4: func_002d6f28(1, 0); break;
    case 5: func_002dc278(1, 0); break;
    case 12: func_002bea88(); break;
    case 50:
    case 51:
    case 52: func_001cebb0(); break;
    case 58: func_002d1270(0, 0); break;
    case 59: func_002d6f28(0, 0); break;
    case 60: func_002dc278(0, 0); break;
    case 226: func_002e0bb0(0); break;
    case 255: func_002d1270(2, 0); break;
    case 256: func_002d6f28(2, 0); break;
    case 257: func_002dc278(2, 0); break;
    case 271:
    case 310: func_002e1f40(0); break;
    case 349: func_002dc278(2, 0); break;
    case 367: func_002e0bb0(0); break;
    }
}
} // n001d7218

// 001d7380 (from src/anon/batch_w51.cpp)
namespace n001d7380 {
void func_002beb28(void) asm("func_002beb28");
void func_00188c10(u32, u32) asm("func_00188c10");
u32 func_00188fe0(void*, u32) asm("func_00188fe0");
extern u8 D_0032e020[] asm("D_0032e020");
void func_001d7380(s32 a0) asm("func_001d7380");
void func_001d7380(s32 a0) {
    switch (a0) {
    case 12:
        func_002beb28();
        break;
    case 176:
    case 181:
    case 182:
    case 183:
    case 185:
    case 186:
    case 189:
    case 296:
    case 297:
    case 298:
        func_00188c10(func_00188fe0(D_0032e020, 1), 2);
        break;
    }
}
} // n001d7380

