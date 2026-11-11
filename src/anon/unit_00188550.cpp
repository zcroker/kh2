#include "../common/types.h"

// yasui/libys battle objects, second part (0x188550-0x188848; plain -O2, unlike the first part).

// ==== from src/anon/batch_w100.cpp
namespace src0 {
}
namespace w100_a11 { 
struct E11 { u32 a; u32 b; f32 t; }; }
namespace src0 {
}
namespace w100_a11 { extern E11 D_01c608c0[64] asm("D_01c608c0"); }
namespace src0 {
}
namespace w100_a11 { extern u32 D_003638d0 asm("D_003638d0"); }
namespace src0 {
}
namespace w100_a11 { u8* func_001b9bc8(u8*) asm("func_001b9bc8"); }
namespace src0 {
}
namespace w100_a11 { void func_001884d0(u8*, E11*) asm("func_001884d0"); }
namespace src0 {

}

// 188550
namespace src0 {
using namespace w100_a11;
void func_00188550(void) asm("func_00188550");
void func_00188550(void) {
    E11* e = D_01c608c0;
    s32 i;
    for (i = 0; i < 64; i++, e++) {
        u8* p;
        if (!e->a) return;
        p = 0;
        while ((p = func_001b9bc8(p)) != 0) {
            if (e->t <= 0.0f) {
                func_001884d0(p + 768, e);
                continue;
            }
            u32 a = e->a, b = e->b;
            *(u32*)(p + 928) = a;
            *(u32*)(p + 932) = b;
            D_003638d0 *= 0x10dcd;
            *(f32*)(p + 936) = (f32)D_003638d0 * 2.3283064365386963e-10f * e->t;
        }
        e->a = 0;
    }
}
}

// ==== from src/anon/batch_w39.cpp
namespace src1 {
void func_00102788(u32, u32, u32, void (*)(void)) asm("func_00102788");


               
struct S188 { u32 a; u32 b; u32 c; };
extern S188 D_01c608c0[] asm("D_01c608c0");
extern u32 D_01c60bc0 asm("D_01c60bc0");
extern u32 D_00351214 asm("D_00351214");
void func_00188550(void) asm("func_00188550");

}

// 188670
namespace src1 {
void func_00188670(void) asm("func_00188670");
void func_00188670(void) {
    for (int i = 0; i < 64; i++) D_01c608c0[i].a = 0;
    D_01c60bc0 = 0;
    func_00102788(D_00351214, 0, 0, func_00188550);
}
}

// ==== from src/anon/batch_w48.cpp
namespace src2 {
s32 func_001c0cd8(void*) asm("func_001c0cd8");
s32 func_0019c090(void*) asm("func_0019c090");

}

// 1886d0
namespace src2 {
s32 func_001886d0(u8* o) asm("func_001886d0");
s32 func_001886d0(u8* o) {
    s32 r = 0;
    if (func_001c0cd8(*(void**)(*(u8**)(o + 136) + 4)) != 0 || func_0019c090(*(void**)(*(u8**)(o + 136) + 4)) == 0) {
        u32 m = *(u32*)(*(u8**)(*(u8**)(o + 136) + 4) + 352) & 0x200;
        r = m == 0;
    }
    return r;
}
}

// ==== from src/anon/tiny_jal_tail_wrappers.cpp
namespace src3 {
u32 func_00187b90() asm("func_00187b90");
u32 func_0016d110() asm("func_0016d110");

}

// 188738
namespace src3 {
u32 func_00188738(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00188738");
u32 func_00188738(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00187b90();
    return func_0016d110();
}
}

// ==== from src/anon/batch_w57.cpp
namespace src4 {


struct B156 { u8 p[156]; u32 bit:1; };
u32 func_00187e20(void) asm("func_00187e20");
u32 func_00187e58(void*) asm("func_00187e58");

}

// 188758
namespace src4 {
u32 func_00188758(B156* t) asm("func_00188758");
u32 func_00188758(B156* t) {
    u32 r = 0;
    if (*(u32*)((u8*)t + 140)) {
        u8 b = t->bit;
        if (!b) {
            if (!func_00187e20()) {
                if (*(s32*)((u8*)t + 152) >= 300 || !func_00187e58(t)) r = 1;
            }
        }
    }
    return r;
}
}

// ==== from src/anon/tiny_auto80_queue.cpp
namespace src5 {
extern u8 D_01c608c0 asm("D_01c608c0");

}

// 1887d8
namespace src5 {
void func_001887d8(u32 a0, u32 a1) asm("func_001887d8");
void func_001887d8(u32 a0, u32 a1) {
    if (a1 == 0xffffu) {
        if (a0 == (u32)1u) {
            u32* p = (u32*)(u32)&D_01c608c0;
            for (s32 i = (s32)63; i != -1; i = i - 1) {
                *p = 0u;
                p = (u32*)((u32)p + (s32)12);
            }
        }
    }
}
}

// ==== from src/anon/tiny_wrappers_more.cpp
namespace src6 {
u32 func_001887d8(u32, u32, u32, u32) asm("func_001887d8");

}

// 188828
namespace src6 {
u32 func_00188828(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00188828");
u32 func_00188828(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001887d8(0x00000001u, 0x0000ffffu, a2, a3);
}
}

