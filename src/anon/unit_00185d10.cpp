#include "../common/types.h"

// yasui/libys battle objects (0x185d10-0x188550): assembled from the matched per-function
// sources. Each source's declarations stay in their own namespace (srcN) and every external
// symbol is bound by asm label. Needs -fno-strict-aliasing; 0x188550 on is unit_00188550.cpp.

// ==== from src/anon/batch_w61.cpp
namespace src0 {
s32 func_0019ba60(void*) asm("func_0019ba60");
u32 func_0016a070(void*) asm("func_0016a070");
void func_001d6088(u32, u8*) asm("func_001d6088");
void func_001890a8(void*, u32) asm("func_001890a8");
void func_001d7e78(void*) asm("func_001d7e78");
extern u8* D_01c608b8 asm("D_01c608b8");
extern u8 D_0032e020[] asm("D_0032e020");

}

// 185d10
namespace src0 {
void func_00185d10(u8* a0) asm("func_00185d10");
void func_00185d10(u8* a0) {
    if (func_0019ba60(*(void**)(a0 + 2788))) {
        D_01c608b8 = *(u8**)(a0 + 2788);
        u8* s = *(u8**)(a0 + 2788);
        if (*(u32*)(s + 1416) & 0x80) func_001d6088(func_0016a070(a0), s);
    }
    func_001890a8(D_0032e020, func_0016a070(a0));
    func_001d7e78(a0);
}
}

// ==== from src/anon/tiny.cpp
namespace src1 {
void func_001984b8(void*) asm("func_001984b8");
void func_00187868(void*) asm("func_00187868");
void func_00186008(BD_VALUE* bd) asm("func_00186008");
void func_00187850(BD_VALUE* bd) asm("func_00187850");

}

// 185d98
namespace src1 {
void func_00185d98(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00185d98");
void func_00185d98(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01c6u << 16);
    *(u32*)((u32)b + (2232)) = (u32)0;
}
}

// ==== from src/anon/batch_w16.cpp
namespace src2 {
                 

u32 ctarget_00185da8(u32, u32, u32, u32);
u32 func_001b9bc8(u32) asm("func_001b9bc8");

}

// 185da8
namespace src2 {
u32 ctarget_00185da8(u32 a0, u32, u32, u32) asm("_Z16ctarget_00185da8jjjj");
u32 ctarget_00185da8(u32 a0, u32, u32, u32) {
    u32 p = a0;
    while ((p = func_001b9bc8(p)) && !(*(u32*)(p + 1416) & 0x10)) {
    }
    return p;
}
}

// ==== from src/anon/batch_w17.cpp
namespace src3 {
extern void* D_01c608b8 asm("D_01c608b8");
u32 func_0019ba60(void*) asm("func_0019ba60");
void* func_0016b0d0(void) asm("func_0016b0d0");

void* ctarget_00185de0(u32, u32, u32, u32) asm("_Z16ctarget_00185de0jjjj");void* ctarget_00185de0(u32, u32, u32, u32) asm("ctarget_00185de0");
u8* func_001b9bc8(void*) asm("func_001b9bc8");
u8* func_00186078(u8* p) asm("func_00186078");
extern u32 D_01c60bc8[2] asm("D_01c60bc8");
void func_00188340(void*, u32, void*, u32) asm("func_00188340");

}

// 185de0
namespace src3 {
void* ctarget_00185de0(u32, u32, u32, u32) asm("_Z16ctarget_00185de0jjjj");
void* ctarget_00185de0(u32, u32, u32, u32) {
    if (func_0019ba60(D_01c608b8)) return D_01c608b8;
    return func_0016b0d0();
}
}

// ==== from src/anon/batch_w51.cpp
namespace src4 {
u32 func_00185da8(u32) asm("func_00185da8");
void func_0016c568(u32, u32, f32) asm("func_0016c568");

}

// 185e20
namespace src4 {
void func_00185e20(u32 a0) asm("func_00185e20");
void func_00185e20(u32 a0) {
    u32 o = 0;
    while ((o = func_00185da8(o)) != 0) func_0016c568(o, a0, 0.0f);
}
}

// ==== from src/anon/batch_w34.cpp
namespace src5 {
void* func_00185da8(void*) asm("func_00185da8");
void func_001b7df0(u32, u32) asm("func_001b7df0");

}

// 185e78
namespace src5 {
void func_00185e78(u32 a) asm("func_00185e78");
void func_00185e78(u32 a) {
    u8* e = 0;
    while ((e = (u8*)func_00185da8(e)) != 0) {
        u32 t = *(u32*)(e + 2088);
        if (t) func_001b7df0(t, a);
    }
}
}

inline void* operator new(unsigned int, void* p) { return p; }

// ==== from src/anon/batch_w1772_nsa.cpp
namespace src6 {

struct V3_w1772 { s32 a, b, c; V3_w1772() : a(0), b(0), c(0) {} };

struct F4_w1772 { f32 x, y, z, w; F4_w1772() { x = w = z = y = 0.0f; } };
void func_001980d0(u8*, u32, u32, u32) asm("func_001980d0");
void func_00190128(u8*) asm("func_00190128");
void func_0019f950(u8*, u8*) asm("func_0019f950");
extern u8 D_0034ee08 asm("D_0034ee08");
void func_00185ed8(u8* p, u32 a1, u32 a2, u32 a3) asm("func_00185ed8");

}

// 185ed8
namespace src6 {
void func_00185ed8(u8* p, u32 a1, u32 a2, u32 a3) asm("func_00185ed8");
void func_00185ed8(u8* p, u32 a1, u32 a2, u32 a3) {
    func_001980d0(p, a1, a2, a3);
    *(u32*)p = (u32)&D_0034ee08;
    func_00190128(p + 2548);
    func_0019f950(p + 2568, p);
    *(s32*)(p + 2724) = 0;
    *(s32*)(p + 2728) = -1;
    *(s32*)(p + 2732) = 0;
    new (p + 2748) V3_w1772;
    *(s32*)(p + 2760) = 0;
    *(s32*)(p + 2764) = 0;
    new (p + 2768) F4_w1772;
    *(s32*)(p + 2784) = 0;
    *(u32*)(p + 1416) |= 2;
}
}

// 185f70
namespace src6 {
void func_00185f70(u8* p, u32 a1, u32 a2, u32 a3) asm("func_00185f70");
void func_00185f70(u8* p, u32 a1, u32 a2, u32 a3) {
    func_001980d0(p, a1, a2, a3);
    *(u32*)p = (u32)&D_0034ee08;
    func_00190128(p + 2548);
    func_0019f950(p + 2568, p);
    *(s32*)(p + 2724) = 0;
    *(s32*)(p + 2728) = -1;
    *(s32*)(p + 2732) = 0;
    new (p + 2748) V3_w1772;
    *(s32*)(p + 2760) = 0;
    *(s32*)(p + 2764) = 0;
    new (p + 2768) F4_w1772;
    *(s32*)(p + 2784) = 0;
    *(u32*)(p + 1416) |= 2;
}
}

// 186008
namespace src1 {
void func_00186008(BD_VALUE* bd) asm("func_00186008");
void func_00186008(BD_VALUE* bd) { func_001984b8(bd); }
}

// ==== from src/anon/auto80_199_queue.cpp
namespace src7 {
void func_00188738(void*) asm("func_00188738");
void func_0016ce90(u32) asm("func_0016ce90");
u32 func_00180ce0(...) asm("func_00180ce0");
void func_001826c8(f32) asm("func_001826c8");
u32 func_0019f9a8(...) asm("func_0019f9a8");
void func_001dc920(u32 a0) asm("func_001dc920");
void func_0016b5b8(u32 a0) asm("func_0016b5b8");
void func_0019aa00(u32 a0, u32 a1) asm("func_0019aa00");
void func_00187868(u32 a0) asm("func_00187868");
u32 func_00187ab8(u32 a0, u32 a1) asm("func_00187ab8");
void func_00187ef0(u32 a0, u32 a1) asm("func_00187ef0");
void func_00187f90(u32 a0) asm("func_00187f90");
void func_00187fd8(u32 a0, u32 a1) asm("func_00187fd8");
void func_001881f8(u32 a0, u32 a1) asm("func_001881f8");
void func_0016b5b8(u8* a0) asm("func_0016b5b8");
void func_00186020(u32 a0) asm("func_00186020");
void func_00187890(u32 a0) asm("func_00187890");
void func_001881f8(u32 a0, u32 a1) asm("func_001881f8");
void func_001880b0(u32 a0, u32 a1) asm("func_001880b0");

}

// 186020
namespace src7 {
void func_00186020(u32 a0) asm("func_00186020");
void func_00186020(u32 a0) {
    u32 s0 = a0;
    if ((*(u32*)(s0 + 264) & 0x10000000) == 0) {
        func_0019f9a8(s0 + 2568);  // array8_free_slots
        u32 t7 = *(u32*)(s0 + 2784);
        if (t7 != 0) {
            func_001dc920(t7);
            *(u32*)(s0 + 2784) = 0;
        }
    }
    func_0016b5b8(s0);
}
}

// 186078
namespace src3 {
u8* func_00186078(u8* p) asm("func_00186078");
u8* func_00186078(u8* p) {
    do {
        p = func_001b9bc8(p);
    } while (p && !(*(u32*)(p + 1416) & 2));
    return p;
}
}

// ==== from src/anon/batch_w35.cpp
namespace src8 {
void func_0016af58(void*, u32) asm("func_0016af58");

}

// 1860b0
namespace src8 {
s32 func_001860b0(u32 a, f32* b) asm("func_001860b0");
s32 func_001860b0(u32 a, f32* b) {
    f32 tmp[4] __attribute__((aligned(16)));
    f32 d;
    func_0016af58(tmp, a);
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(tmp), "r"(b) : "$8", "memory");
    return d < 0.0f;
}
}

// ==== from src/anon/batch_wcx2.cpp
namespace src9 {

}

// 186110
namespace src9 {
s32 func_00186110(void*, u8* p) asm("func_00186110");
s32 func_00186110(void*, u8* p) {
    switch (p[36]) {
    case 0: case 2: case 3: case 4: case 5:
        return 1;
    case 1: case 6: case 7: case 8: case 9:
        return 0;
    }
    return 0;
}
}

// ==== from src/anon/tiny_wrappers_more.cpp
namespace src10 {
u32 func_001887d8(u32, u32, u32, u32) asm("func_001887d8");
u32 func_00196b58(u32, u32, u32, u32) asm("func_00196b58");
u32 func_001d7a50(u32, u32, u32, u32) asm("func_001d7a50");
u32 func_00186148(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00186148");
u32 func_00187868(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00187868");

}

// 186148
namespace src10 {
u32 func_00186148(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00186148");
u32 func_00186148(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00196b58(a0, a1, a2, a3);
}
}

// ==== from src/anon/batch_w1674.cpp
namespace src11 {
}
#define QCOPY186(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
namespace src11 {


struct QV186 {
    f32 x, y, z, w;
    QV186() {}
    QV186(const QV186& o) { QCOPY186(this, &o); }
    QV186& operator=(const QV186& o) { if (this != &o) QCOPY186(this, &o); return *this; }
    QV186 operator-(const QV186& b) const {
        QV186 o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct Info186 { u32 pad0; s32 kind; };

struct Obj186 { u8 pad0[0xc]; Info186* info; u8 pad10[0x508]; u8 sub518[4]; };

struct Msg186 { QV186 dir; u8 pad10[8]; u32 flags; u8 pad1c[0xa]; u8 action; u8 type; };
extern void* D_0034e948 asm("D_0034e948");
QV186* func_0016c028(void*) asm("func_0016c028");
s32 func_001d7b90(void*) asm("func_001d7b90");
void func_001cf0d8(Obj186*, Msg186*) asm("func_001cf0d8");
u32 func_0018ca48(u8) asm("func_0018ca48");
s32 func_001c0cd8(Obj186*) asm("func_001c0cd8");
void func_001c0e60(Obj186*) asm("func_001c0e60");
f32 func_0018cb30(Msg186*) asm("func_0018cb30");
void func_00186378(Obj186*, Msg186*, f32) asm("func_00186378");
void func_00186478(Obj186*, Msg186*) asm("func_00186478");
void func_001863a8(Obj186*, Msg186*, f32) asm("func_001863a8");
void func_0018cd28(Msg186*, f32*, f32*) asm("func_0018cd28");
void func_00186740(Obj186*, Msg186*, s32, s32, f32, f32) asm("func_00186740");
void func_00186948(Obj186*, Msg186*) asm("func_00186948");
void func_00186988(Obj186*, Msg186*, f32) asm("func_00186988");
void func_001cd078(Msg186*) asm("func_001cd078");


static inline bool isType17(Obj186* o) { return o->info->kind == 0x17; }
}

// 186160
namespace src11 {
void func_00186160(Obj186* obj, Msg186* msg) asm("func_00186160");
void func_00186160(Obj186* obj, Msg186* msg) {
    u32 fl = msg->flags & 1;
    if ((u8)fl) return;
    if (!func_001d7b90(obj->sub518)) return;
    if (isType17(obj)) {
        func_001cf0d8(obj, msg);
        return;
    }
    if ((u32)(msg->type - 15) < 4) {
        msg->dir = *func_0016c028(D_0034e948) - *func_0016c028(obj);
        msg->dir.y = 0;
        msg->dir.normalize();
    }
    u32 mode = func_0018ca48(msg->action);
    if (func_001c0cd8(obj) && mode != 0 && mode != 2) func_001c0e60(obj);
    switch (mode) {
    case 1:
        func_00186378(obj, msg, func_0018cb30(msg));
        break;
    case 2:
        func_00186478(obj, msg);
        break;
    case 3:
        func_001863a8(obj, msg, func_0018cb30(msg));
        break;
    case 4: {
        f32 a, b;
        func_0018cd28(msg, &a, &b);
        func_00186740(obj, msg, 16, 18, a, b);
        break;
    }
    case 5:
        func_00186948(obj, msg);
        break;
    case 14:
        func_00186988(obj, msg, func_0018cb30(msg));
        break;
    }
    func_001cd078(msg);
    msg->flags |= 1;
}
}

// ==== from src/anon/tiny_jal_wrappers_flex.cpp
namespace src12 {
u32 func_00186a90(u32, u32, u32, u32) asm("func_00186a90");

}

// A small table that sits here in .rodata; the code uses it as D_0036c970 (extern elsewhere).
extern const u16 ro_0036c970[2] asm("D_0036c970") __attribute__((aligned(8))) = { 14, 15 };

// 186378
namespace src12 {
u32 func_00186378(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00186378");
u32 func_00186378(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r5;
    r2 = func_00186a90(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(24));
    r15 = (u32)(r15 | 0x0001u);
    *(u32*)((u32)r16 + (s32)(24)) = r15;
    return r2;
}
}

// ==== from src/anon/batch_w87.cpp
namespace src13 {
void func_001866f0(void*, s32, f32) asm("func_001866f0");
void func_001866a0(void*, s32, f32) asm("func_001866a0");
s32 func_0019c090(void*) asm("func_0019c090");
void func_001a2a18(void*) asm("func_001a2a18");
void func_00186548(void*, s32, f32) asm("func_00186548");

static inline bool flags_2_and_40(u32 fl) {
    bool b = false;
    if (fl & 2) { u32 m = fl & 0x40; b = m != 0; }
    return b;
}
}

// 1863a8
namespace src13 {
void func_001863a8(u8* p, s32 a, f32 x) asm("func_001863a8");
void func_001863a8(u8* p, s32 a, f32 x) {
    if (*(u32*)(*(u8**)(p + 12) + 8) & 0x10) {
        func_001866f0(p, a, x);
        return;
    }
    s32 r = func_0019c090(p);  // obj_is_enabled
    if (r) {
        func_001866a0(p, a, x);
        return;
    }
    u32 fl = *(u32*)(*(u8**)(p + 12) + 8);
    if (flags_2_and_40(fl)) func_001a2a18(p);
    func_00186548(p, a, x);
}
}

// ==== from src/anon/batch_w2376.cpp
namespace src14 {
s32 func_001860b0(u8*, u8*) asm("func_001860b0");
s32 func_00186110(u8*, u8*) asm("func_00186110");
s32 func_0017f4e0(u8*, u16) asm("func_0017f4e0");
void func_0017f488(u8*, u16, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, s32, f32, f32) asm("func_0017f5e0");
extern u16 D_0034edf8[] asm("D_0034edf8");

}

// 186478
namespace src14 {
void func_00186478(u8* a, u8* b) asm("func_00186478");
void func_00186478(u8* a, u8* b) {
    s32 i;
    if (func_001860b0(a, b)) i = 0; else i = 2;
    if (!func_00186110(a, b)) i++;
    if (!func_0017f4e0(a + 320, D_0034edf8[i])) i ^= 1;
    func_0017f488(a + 320, D_0034edf8[i], 0.0f, 0.0f);
    func_0017f5e0(a + 320, 0, 0, 0.0f, 0.0f);
    *(u32*)(b + 24) |= 1;
}
}

// ==== from src/anon/tiny_auto80_queue.cpp
namespace src15 {
 u32 func_001dc920(...) asm("func_001dc920");
 u32 func_001dc920(...) asm("func_001dc920");
 u32 func_001dc920(...) asm("func_001dc920");
 u32 func_001dc920(...) asm("func_001dc920");
 u32 func_001dc9e0(...) asm("func_001dc9e0");
 u32 func_001dc9e0(...) asm("func_001dc9e0");
 u32 func_001dc9e0(...) asm("func_001dc9e0");
 u32 func_001dc9e0(...) asm("func_001dc9e0");
 u32 func_001dc9e0(...) asm("func_001dc9e0");
 u32 func_001dc9e0(...) asm("func_001dc9e0");
 u32 func_0016cce8(...) asm("func_0016cce8");
 u32 func_0016cce8(...) asm("func_0016cce8");
 u32 func_00186478(...) asm("func_00186478");
 u32 func_00186a90(...) asm("func_00186a90");
void func_00186548(u32 a0, u32 a1, f32 f12) asm("func_00186548");
 u32 func_00186590(...) asm("func_00186590");
 u32 func_00186c58(...) asm("func_00186c58");
void func_001866a0(u32 a0, u32 a1, f32 f12) asm("func_001866a0");
 u32 func_00186590(...) asm("func_00186590");
 u32 func_00186a90(...) asm("func_00186a90");
void func_001866f0(u32 a0, u32 a1, f32 f12) asm("func_001866f0");
 u32 func_0016cce8(...) asm("func_0016cce8");
void func_00186fd8(u32 a0, u32 a1) asm("func_00186fd8");
 u32 func_0016a5b0(...) asm("func_0016a5b0");
 u32 func_001dc920(...) asm("func_001dc920");
 u32 func_001dc9e0(...) asm("func_001dc9e0");
void func_00187750(u32 a0) asm("func_00187750");
void func_00187818(u32 a0) asm("func_00187818");
u32 func_00187b30(u32 a0) asm("func_00187b30");
 u32 func_00187ab8(...) asm("func_00187ab8");
void func_00187b68(void) asm("func_00187b68");
 u32 func_00187b90(...) asm("func_00187b90");
void func_00187f90(u32 a0) asm("func_00187f90");
 u32 func_001880b0(...) asm("func_001880b0");
 u32 func_001883d8(...) asm("func_001883d8");
void func_00188120(u32 a0, u32 a1) asm("func_00188120");
extern u8 D_01c608c0 asm("D_01c608c0");

}

// 186548
namespace src15 {
void func_00186548(u32 a0, u32 a1, f32 f12) asm("func_00186548");
void func_00186548(u32 a0, u32 a1, f32 f12) {
    f32 f20 = f12;
    u32 s0 = a0;
    u32 s1 = a1;
    func_00186478(a0, a1);
    f12 = f20;
    ((void(*)(u32, u32, f32))func_00186a90)(s0, s1, f12);
}
}

// ==== from src/anon/batch_w254.cpp
namespace src16 {


                                                                                 
                                                
struct W254PE { s32 key; u8 pad[16]; };

struct W254Pool { W254PE e[128]; s32 idx[128]; s32 count; };
extern W254Pool D_01c60d50 asm("D_01c60d50");


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
}}
namespace w254_v2 { 
struct Vec {
    f32 x, y, z, w;
    Vec& operator=(const Vec& s) {
        if (this != &s)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16))); }
namespace src16 {
}
namespace w254_v2 { 
static inline void VecScale(Vec* a, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
} }
namespace src16 {
}
namespace w254_v2 { extern u16 D_0036c970[] asm("D_0036c970"); }
namespace src16 {
}
namespace w254_v2 { s32 func_001860b0(void) asm("func_001860b0"); }
namespace src16 {
}
namespace w254_v2 { void func_0016aef0(u8*, Vec*) asm("func_0016aef0"); }
namespace src16 {
}
namespace w254_v2 { s32 func_0017f4e0(u8*, u16) asm("func_0017f4e0"); }
namespace src16 {
}
namespace w254_v2 { void func_0017f488(u8*, u16, f32, f32) asm("func_0017f488"); }
namespace src16 {
}
namespace w254_v2 { void func_0017f5e0(u8*, u32, s32, f32, f32) asm("func_0017f5e0"); }
namespace src16 {

}

// 186590
namespace src16 {
using namespace w254_v2;
void func_00186590(u8* a0, Vec* a1, u32 a2) asm("func_00186590");
void func_00186590(u8* a0, Vec* a1, u32 a2) {
    Vec v;
    s32 i;
    v = *a1;
    if (func_001860b0()) {
        i = 0;
        VecScale(&v, -1.0f);
    } else {
        i = 1;
    }
    func_0016aef0(a0, &v);
    a0 += 320;
    if (!func_0017f4e0(a0, D_0036c970[i])) i ^= 1;
    func_0017f488(a0, D_0036c970[i], 0.0f, 0.0f);
    func_0017f5e0(a0, a2, 0, 0.0f, 0.0f);
    *(u32*)((u8*)a1 + 24) |= 1;
}
}

// 1866a0
namespace src15 {
void func_001866a0(u32 a0, u32 a1, f32 f12) asm("func_001866a0");
void func_001866a0(u32 a0, u32 a1, f32 f12) {
    f32 f20 = f12;
    u32 s0 = a0;
    u32 s1 = a1;
    func_00186590(a0, a1, (u32)4);
    f12 = f20;
    ((void(*)(u32, u32, f32))func_00186c58)(s0, s1, f12);
}
}

// 1866f0
namespace src15 {
void func_001866f0(u32 a0, u32 a1, f32 f12) asm("func_001866f0");
void func_001866f0(u32 a0, u32 a1, f32 f12) {
    f32 f20 = f12;
    u32 s0 = a0;
    u32 s1 = a1;
    u32 a2 = *(u32*)((u32)a0 + (s32)(2744));
    func_00186590(a0, a1, a2);
    f12 = f20;
    ((void(*)(u32, u32, f32))func_00186a90)(s0, s1, f12);
}
}

// ==== from src/anon/batch_w267.cpp
namespace src17 {
}
#define QCOPY267(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
namespace src17 {

struct QV267 {
  f32 x, y, z, w;
  QV267() {}
  QV267(const QV267& o) { QCOPY267(this, &o); }
  QV267& operator=(const QV267& o) {
    if (this != &o) QCOPY267(this, &o);
    return *this;
  }
} __attribute__((aligned(16)));

static inline QV267 ScaleQ267(const QV267& a, f32 k) {
  QV267 r;
  asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
  return r;
}
struct V186 { QV267 v; s32 pad[2]; u32 f24; };
s32 func_001860b0(u8*, V186*, u32, u32) asm("func_001860b0");
void func_0016aef0(u8*, QV267*) asm("func_0016aef0");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void func_00186888(u8*, QV267*) asm("func_00186888");
s32 func_0018cac0(V186*) asm("func_0018cac0");
void func_001bfcc8(u8*, s32) asm("func_001bfcc8");

}

// 186740
namespace src17 {
void func_00186740(u8* p, V186* v, u32 a2, u32 a3, f32 y, f32 w) asm("func_00186740");
void func_00186740(u8* p, V186* v, u32 a2, u32 a3, f32 y, f32 w) {
  QV267 c;
  QV267 b;
  u32 m;
  if (func_001860b0(p, v, a2, a3)) {
    m = a2;
    b = ScaleQ267(v->v, -1.0f);
  } else {
    m = a3;
    b = v->v;
  }
  func_0016aef0(p, &b);
  c = v->v;
  c.y = y;
  c.w = w;
  func_0017f488(p + 320, m, 0.0f, 0.0f);
  func_00186888(p, &c);
  if (func_0018cac0(v)) *(u32*)(p + 268) |= 0x20000;
  v->f24 |= 1;
  if (*(u32*)(p + 1416) & 0x80) func_001bfcc8(p, 1);
}
}

// ==== from src/anon/batch_w76.cpp
namespace src18 {


struct FV {
    f32 x, y, z, w;
    FV() {}
    FV& operator=(const FV& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

static inline void Normalize(FV* v)
{
    asm volatile(
        "lqc2 $vf1, 0(%0)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, $f1\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%0)"
        : : "r"(v) : "$8", "$f1", "memory");
}
static inline void Scale(FV* d, const FV* s, f32 k)
{
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "mfc1 $8, %2\n\t"
        "qmtc2 $8, $vf2\n\t"
        "vmulx.wxyz $vf1, $vf1, $vf2x\n\t"
        "sqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}void func_0017a9e8(u32, u8*) asm("func_0017a9e8");

void btl_blow(u8* self, const FV& v) asm("_ZN2YS6BTLOBJ4blowERKN2kn7FVectorE");
}

// 186888
namespace src18 {
void btl_blow(u8* self, const FV& v) asm("_ZN2YS6BTLOBJ4blowERKN2kn7FVectorE");
void btl_blow(u8* self, const FV& v)
{
    *(u32*)(self + 268) &= ~0x20000;
    FV t;
    t = v;
    t.y = 0.0f;
    Normalize(&t);
    FV* dir = (FV*)(self + 32);
    FV r;
    Scale(&r, &t, v.w);
    *dir = r;
    *(f32*)(self + 36) = -v.y;
    func_0017a9e8(*(u32*)(self + 12), self);
}
}

// ==== from src/anon/batch_w11.cpp
namespace src19 {
s32 func_001860b0(void*) asm("func_001860b0");
void func_001c1b08(void*, u32, s32) asm("func_001c1b08");

}

// 186948
namespace src19 {
void func_00186948(void* a, u8* b) asm("func_00186948");
void func_00186948(void* a, u8* b) {
    s32 v = func_001860b0(a);
    func_001c1b08(a, *(u32*)(b + 28), v);
}
}

// ==== from src/anon/batch_w84.cpp
namespace src20 {


                                                          
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

static inline Vq VScale(const Vq& v, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}

                                                                
struct LNode { u8 _0[44]; LNode* next; };

struct LList {
    LNode* head;
    LNode* tail;
};

struct LOwner { u8 _0[396]; LList list; };

static inline __attribute__((always_inline)) void LRemove(LList* l, LNode* n) {
    LNode* prev;
    if (n == l->head) {
        prev = 0;
        l->head = n->next;
    } else {
        for (prev = l->head; prev->next != n; prev = prev->next) {}
        prev->next = n->next;
    }
    if (n == l->tail) l->tail = prev;
    n->next = 0;
}
static inline __attribute__((always_inline)) LNode* LNext(LOwner* o, LNode* n) {
    if (!n) return o->list.head;
    return n->next;
}

struct Mv { Vq v; u8 _16[8]; u32 flags; };
s32 func_001860b0(u8*, Mv*) asm("func_001860b0");
void func_0016aef0(u8*, Vq*) asm("func_0016aef0");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, s32, s32, f32, f32) asm("func_0017f5e0");
void func_00186a90(u8*, Mv*, f32) asm("func_00186a90");

}

// 186988
namespace src20 {
void func_00186988(u8* p, Mv* m, f32 f) asm("func_00186988");
void func_00186988(u8* p, Mv* m, f32 f) {
    Vq t;
    s32 k;
    if (func_001860b0(p, m)) {
        k = 23;
        t = VScale(m->v, -1.0f);
    } else {
        k = 24;
        t = m->v;
    }
    func_0016aef0(p, &t);
    func_0017f488(p + 320, k, 0.0f, 0.0f);
    func_0017f5e0(p + 320, 0, 0, 0.0f, 0.0f);
    func_00186a90(p, m, f);
    m->flags |= 1;
}
}

// ==== from src/anon/batch_w77.cpp
namespace src21 {
}
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
namespace src21 {
}
namespace n00186a90 { 
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16))); }
namespace src21 {
}
namespace n00186a90 { 
static inline QWord Scale(const QWord& a, f32 k)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
} }
namespace src21 {
}
namespace n00186a90 { 
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
} }
namespace src21 {
}
namespace n00186a90 { 
struct Ent { u8 pad[1164]; u8* tgt; u8 pad2[2768 - 1168]; QWord dir; f32 f2784; }; }
namespace src21 {
}
namespace n00186a90 { 
void ctarget_00186a90(Ent* p, QWord* v, f32 k) asm("_Z16ctarget_00186a90jjjj"); }
namespace src21 {
}
namespace n00186a90 { s32 func_0019c838(Ent*) asm("func_0019c838"); }
namespace src21 {

}

// 186a90
namespace src21 {
using namespace n00186a90;
void ctarget_00186a90(Ent* p, QWord* v, f32 k) asm("_Z16ctarget_00186a90jjjj");
void ctarget_00186a90(Ent* p, QWord* v, f32 k)
{
    if (!func_0019c838(p)) return;
    if (k < 0.0f) {
        k = -k;
        p->dir = Scale(*v, -1.0f);
    } else {
        p->dir = *v;
    }
    if (p->tgt) k += *(f32*)(p->tgt + 456);
    Normalize(&p->dir);
    *(f32*)((u8*)p + 2780) = k * 0.1f;
}
}

// ==== from src/anon/batch_w85.cpp
namespace src22 {

                                                               
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern f32 D_00349e10 asm("D_00349e10");

static inline void vu_scale_to(void* d, const void* s, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void vu_zero(void* d) {
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(d) : "memory");
}f32 func_002f8b30(f32, f32) asm("func_002f8b30");

static inline u32 pos186(f32 f) { return 0.0f < f; }
}

// 186b90
namespace src22 {
Vec4* func_00186b90(Vec4* out, u8* o) asm("func_00186b90");
Vec4* func_00186b90(Vec4* out, u8* o) {
    f32 f = *(f32*)(o + 2780);
    if ((u8)pos186(f)) {
        if (f < 1.0f) {
            *(f32*)(o + 2780) = 0.0f;
        } else {
            Vec4 t;
            vu_scale_to(&t, o + 2768, f * D_00349e10);
            *out = t;
            *(f32*)(o + 2780) *= func_002f8b30(0.9f, D_00349e10);
            return out;
        }
    }
    vu_zero(out);
    return out;
}
}

// ==== from src/anon/batch_w50.cpp
namespace src23 {

                                   

typedef unsigned int u128 __attribute__((mode(TI)));

typedef void (*VFn3)(void*, void*, void*);


                                                                                 
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));


                                                               
struct Q16 { f32 x, y, z, w; } __attribute__((aligned(16)));

union VP { u8* vt; f32 f; };
s32 func_0019c838(void*) asm("func_0019c838");
extern u8* D_00352130 asm("D_00352130");

}

// 186c58
namespace src23 {
void func_00186c58(u8* o, Q16* v, f32 s) asm("func_00186c58");
void func_00186c58(u8* o, Q16* v, f32 s) {
    if (!func_0019c838(o)) return;
    Q16 t;
    QCOPY(&t, v);
    VP* h = *(VP**)(o + 12);
    t.w = s * *(f32*)(D_00352130 + 56);
    t.y = 50.0f;
    (*(VFn3*)(h->vt + 8))(h, o, &t);
}
}

// ==== from src/anon/batch_w6.cpp
namespace src24 {

}

// 186ce8
namespace src24 {
u32 ctarget_00186ce8(u32 a0, u32, u32, u32) asm("_Z16ctarget_00186ce8jjjj");
u32 ctarget_00186ce8(u32 a0, u32, u32, u32) {
    u32* p = (u32*)(a0 + 320);
    if (p[0] == 0) return 0;
    s32 v = p[5];
    if (v < 10) return 0;
    if (v < 40) return 1;
    return 0;
}
}

// ==== from src/anon/batch_w7.cpp
namespace src25 {

}

// 186d18
namespace src25 {
bool func_00186d18(u8* a0) asm("func_00186d18");
bool func_00186d18(u8* a0) {  // check_size140to150
    u32* p = (u32*)(a0 + 320);
    if (*p == 0) return false;
    s32 v = p[5];
    if (v < 140) return false;
    if (v < 151) return true;
    return false;
}
}

// ==== from src/anon/batch_w1937_nsa.cpp
namespace src26 {
}
namespace w1937_a { 
struct W1937Obj; }
namespace src26 {
}
namespace w1937_a { 
struct W1937Msk { s32 m0, m1, m2; }; }
namespace src26 {
}
namespace w1937_a { 
struct W1937VT {
    u8 pad[0x58];
    s32 (*f58)(W1937Obj*);
    u8 pad2[0x78 - 0x5c];
    s32 (*f78)(W1937Obj*, s32, u8, s32);
}; }
namespace src26 {
}
namespace w1937_a { 
struct W1937Ent { s32 a; s32 b; s32 c; }; }
namespace src26 {
}
namespace w1937_a { 
struct W1937Obj {
    W1937VT* vt;
    u8 pad[0x48c - 4];
    W1937Ent* ents;
    u8 pad2[0xabc - 0x490];
    W1937Msk m;
}; }
namespace src26 {
}
namespace w1937_a { 
struct W1937Kind { u8 pad[4]; u8 k; u8 pad2[0x12 - 5]; u8 fl; }; }
namespace src26 {
}
namespace w1937_a { 
struct W1937Owner { u8 pad[0xc]; W1937Obj* o; }; }
namespace src26 {
}
namespace w1937_a { 
struct W1937Arg {
    u8 pad[0x18];
    s32 flags;
    W1937Owner* own;
    W1937Kind* kind;
    u8 pad2;
    u8 idx;
    u8 pad3[2];
    s32 val;
}; }
namespace src26 {
}
namespace w1937_a { 
static inline u8 w1937_isKind(W1937Kind* k) { return k->k == 5 || k->k == 6; } }
namespace src26 {
}
namespace w1937_a { s32 func_0018caf8(W1937Arg*) asm("func_0018caf8"); }
namespace src26 {
}
namespace w1937_a { s32 func_0018cef8(W1937Arg*) asm("func_0018cef8"); }
namespace src26 {

}

// 186d48
namespace src26 {
using namespace w1937_a;
void func_00186d48(W1937Obj* self, W1937Arg* a) asm("func_00186d48");
void func_00186d48(W1937Obj* self, W1937Arg* a) {
    if (a->flags & 2) return;
    a->flags |= 2;
    W1937Ent* e0 = self->ents;
    if (e0 == 0) return;
    W1937Kind* k = a->kind;
    s32 v = a->val;
    s32 f;
    if (w1937_isKind(k)) {
        f = 0;
        if (a->own->o != self) { u32 t = k->fl; f = (t >> 4) & 1; }
        self->vt->f78(self, v, a->idx, f);
    } else {
        W1937Ent* e = &e0[a->idx];
        if (e->c >= e->a - v && self->vt->f58(self)) {
            v = e->a - e->c - 1;
            if (v < 0) v = 0;
        }
        if (v >= 2) {
            W1937Msk* m = &self->m;
            if (((m->m0 | m->m1) & ~m->m2 & 0x8000) && func_0018caf8(a)) {
                if (!func_0018cef8(a)) v = 1;
            }
        }
        self->vt->f78(self, -v, a->idx, 0);
    }
}
}

// ==== from src/anon/batch_w1825_nsa.cpp
namespace src27 {

struct W1825Heap;

struct W1825HeapVt { u8* (*alloc)(W1825Heap*, s32, s32); };

struct W1825Heap { W1825HeapVt* vt; };

struct W1825Sys { u8 pad[20]; W1825Heap* heap; };
extern u8* D_00347f80 asm("D_00347f80");
}
#define SYS ((W1825Sys*)D_00347f80)
namespace src27 {
extern u8 D_00347e60[] asm("D_00347e60");
void func_00239700(u8*) asm("func_00239700");

static inline __attribute__((always_inline)) u8* w1825_mk() {
    u8* a = SYS->heap->vt->alloc(SYS->heap, 408, 0);
    *(u8**)a = D_00347e60;
    *(u32*)(a + 12) = 0;
    func_00239700(a + 24);
    return a;
}

           
struct W1825QV {
    f32 x, y, z, w;
    W1825QV operator*(f32 s) const {
        W1825QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    W1825QV operator+(const W1825QV& b) const {
        W1825QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));


           
struct W1825Flags {
    u32 a, b, c;
    u32 get() { return (a | b) & ~c; }
};

struct W1825Obj {
    u8 pad0[352]; u32 f352;
    u8 pad1[1416 - 356]; u32 f1416;
    u8 pad2[2748 - 1420]; W1825Flags flags;
    u32 fl() { W1825Flags* f = &flags; return (flags.a | f->b) & ~f->c; }
};

struct W1825Oth { u8 pad0[16]; W1825Obj* owner; u8 pad1[37 - 20]; u8 b37; u8 b38; };
s32 func_0018cae0(W1825Oth*) asm("func_0018cae0");
s32 func_00186ec0(W1825Obj* o, W1825Oth* p) asm("func_00186ec0");
}
#define W1825QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
namespace src27 {


           
struct W1825V {
    f32 x, y, z, w;
    W1825V() {}
    W1825V(const W1825V& o) { W1825QCOPY(this, &o); }
    W1825V& operator=(const W1825V& o) { if (this != &o) W1825QCOPY(this, &o); return *this; }
    W1825V operator+(const W1825V& b) const {
        W1825V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1825V operator-(const W1825V& b) const {
        W1825V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct W1825Act { u8 pad[1376]; W1825V pos; };

struct W1825Tgt { W1825Act* owner; };
s32 func_00187300(W1825Act*, W1825Tgt*, f32) asm("func_00187300");
s32 func_00190180(W1825Tgt*) asm("func_00190180");
W1825V func_00190388(W1825Tgt*) asm("func_00190388");
W1825V* func_0016c028(W1825Act*) asm("func_0016c028");
void func_0016b010(W1825Act*, W1825V) asm("func_0016b010");

s32 u_call4_001871c8(W1825Act* o, W1825Tgt* t, f32 r) asm("_Z16u_call4_001871c8jjjj");
}

// 186ec0
namespace src27 {
s32 func_00186ec0(W1825Obj* o, W1825Oth* p) asm("func_00186ec0");
s32 func_00186ec0(W1825Obj* o, W1825Oth* p)
{
    u32 m = o->fl();
    if (m & 0x200) return 1;
    if (m & 0x400) {
        if ((m & 0x80000) || !p->b37) {
            if (!func_0018cae0(p)) return 1;
        }
    }
    if ((o->fl() & 0x800) || p->b37) {
        if (!func_0018cae0(p) && !(p->owner->f1416 & 0x80)) return 1;
    }
    if (!(o->f1416 & 0x80)) return 0;
    if ((o->f352 & 0x4000) && !p->b38) return 1;
    return 0;
}
}

// 186fd8
namespace src15 {
void func_00186fd8(u32 a0, u32 a1) asm("func_00186fd8");
void func_00186fd8(u32 a0, u32 a1) {
    u32 t6 = a1;
    u32 t7 = *(u32*)((u32)a0 + (s32)(1156));
    if (t7 != 0u) {
        struct { u32 w0; u32 w1; } sp;
        sp.w0 = t6;
        sp.w1 = 0u;
        func_0016cce8(t7, (u32)19, (u32)&sp, (u32)2, 0u);
    }
}
}

// ==== from src/anon/batch_w1574.cpp
namespace src28 {

struct QW187 { f32 x, y, z, w; QW187() {} } __attribute__((aligned(16)));

struct Kind187 { s32 p0; s32 type; };

struct Obj187 { u8 p0[12]; Kind187* kind; u8 p1[320 - 16]; u8 mot[1]; };

struct Ev187 { s32 p0; u32 flags; };

static inline void Scale187(QW187* r, QW187* a, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(a), "f"(k) : "$8", "memory");
}void func_001cf320(Obj187*, Ev187*, s32, s32, f32) asm("func_001cf320");
s32 func_0019c090(Obj187*) asm("func_0019c090");

void f17f488_187(void*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void push_187(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");void func_0016af58(QW187*, Obj187*) asm("func_0016af58");
void func_00186c58(Obj187*, QW187*, f32) asm("func_00186c58");

void ctarget_00186a90_187(Obj187*, QW187*, f32) asm("_Z16ctarget_00186a90jjjj");
static inline void Back187(QW187* t, Obj187* self) { QW187 v; func_0016af58(&v, self); Scale187(t, &v, -1.0f); }
}

// 187018
namespace src28 {
void func_00187018(Obj187* self, Ev187* ev, s32 a2, s32 mot, f32 spd) asm("func_00187018");
void func_00187018(Obj187* self, Ev187* ev, s32 a2, s32 mot, f32 spd) {
    QW187 t;
    if (ev->flags & 0x40) return;
    u32 d = self->kind->type ^ 0x17; if (d == 0) { func_001cf320(self, ev, a2, mot, spd); return; }
    if (spd < 0.0f) spd = 50.0f;
    if (func_0019c090(self)) {
        f17f488_187(self->mot, mot < 0 ? 43 : mot, 0.0f, 0.0f);
        push_187(self->mot, 4, 0.0f, 0.0f, 0);
        if (spd > 0.0f) {
            Back187(&t, self);
            func_00186c58(self, &t, spd);
        }
    } else {
        f17f488_187(self->mot, mot < 0 ? 41 : mot, 0.0f, 0.0f);
        if (spd > 0.0f) {
            Back187(&t, self);
            ctarget_00186a90_187(self, &t, spd);
        }
        push_187(self->mot, 0, 0.0f, 0.0f, 0);
    }
    ev->flags |= 0x40;
}
}

// 1871c8
namespace src27 {
s32 u_call4_001871c8(W1825Act* o, W1825Tgt* t, f32 r) asm("_Z16u_call4_001871c8jjjj");
s32 u_call4_001871c8(W1825Act* o, W1825Tgt* t, f32 r)
{
    s32 res;
    if (0.0f < r) {
        res = func_00187300(o, t, r);
    } else if (!func_00190180(t)) {
        res = 0;
    } else {
        if (t->owner != o) {
            W1825V d;
            d = func_00190388(t) - (*func_0016c028(o) + o->pos);
            d.y = 0.0f;
            if (50.0f < d.length()) func_0016b010(o, d);
        }
        res = 1;
    }
    return res;
}
}

// ==== from src/anon/tiny_auto80_fptr4.cpp
namespace src29 {
u32 func_001871c8(u32, u32, u32, u32) asm("func_001871c8");
u32 func_00187300(u32, u32, u32, u32) asm("func_00187300");
u32 func_001872e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001872e0");

}

// 1872e0
namespace src29 {
u32 func_001872e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001872e0");
u32 func_001872e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r5 = (u32)((s32)r4 + (2548));
    u32 (*fp_call4_001871c8)(u32, u32, u32, u32) = func_001871c8;
    r2 = fp_call4_001871c8(r4, r5, r6, r7);
    return r2;
}
}

// ==== from src/anon/batch_w1816.cpp
namespace src30 {
}
#define W1816_AI __attribute__((always_inline))
namespace src30 {


               
struct W1816V {
    f32 x, y, z, w;
    W1816V& operator=(const W1816V& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
} __attribute__((aligned(16)));

static inline W1816_AI W1816V operator+(const W1816V& a, const W1816V& b) {
    W1816V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1816_AI W1816V operator-(const W1816V& a, const W1816V& b) {
    W1816V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1816_AI f32 W1816Len(const W1816V& v) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
struct W1816Ob { u8 pad[1376]; W1816V pos; };

struct W1816Tg { W1816Ob* owner; };
s32 func_00190180(W1816Tg*) asm("func_00190180");
void func_00190388(W1816V*, W1816Tg*) asm("func_00190388");
W1816V* func_0016c028(W1816Ob*) asm("func_0016c028");
void func_00184ad0(W1816Ob*, W1816V*, f32) asm("func_00184ad0");

static inline W1816V W1816Pos(W1816Tg* t) { W1816V r; func_00190388(&r, t); return r; }
s32 u_call4_00187300(W1816Ob* self, W1816Tg* t, f32 r) asm("_Z16u_call4_00187300jjjj");
}

// 187300
namespace src30 {
s32 u_call4_00187300(W1816Ob* self, W1816Tg* t, f32 r) asm("_Z16u_call4_00187300jjjj");
s32 u_call4_00187300(W1816Ob* self, W1816Tg* t, f32 r) {
    if (!func_00190180(t)) return 0;
    if (t->owner != self) {
        W1816V v; v = W1816Pos(t) - (*func_0016c028(self) + self->pos);
        v.y = 0.0f;
        if (50.0f < W1816Len(v)) func_00184ad0(self, &v, r);
    }
    return 1;
}
}

// 187400
namespace src29 {
u32 func_00187400(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00187400");
u32 func_00187400(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r5 = (u32)((s32)r4 + (2548));
    u32 (*fp_call4_00187300)(u32, u32, u32, u32) = func_00187300;
    r2 = fp_call4_00187300(r4, r5, r6, r7);
    return r2;
}
}

// ==== from src/anon/batch_w1529.cpp
namespace src31 {
s32 func_0019ba60(void*) asm("func_0019ba60");
void func_0019d358(s32) asm("func_0019d358");
s32 func_001871c8(s32, s32, f32) asm("func_001871c8");
extern u8* D_0034e948 asm("D_0034e948");

}

// 187420
namespace src31 {
s32 func_00187420(s32 a, f32 f) asm("func_00187420");
s32 func_00187420(s32 a, f32 f) {
    u8* s = D_0034e948;
    s32 ok = func_0019ba60(s);
    s32 r = 0;
    if (ok != 0) {
        if (*(s32*)(s + 0xb40) != 0) {
            func_0019d358(*(s32*)(s + 0xb40));
            r = func_001871c8(a, *(s32*)(s + 0xb40) + 4, f);
        }
    }
    return r;
}
}

// ==== from src/anon/batch_w60.cpp
namespace src32 {
extern u8* D_0034e948 asm("D_0034e948");
s32 func_0019ba60(void*) asm("func_0019ba60");
void func_0019d358(void*) asm("func_0019d358");
s32 func_00187300(void*, void*, f32) asm("func_00187300");

}

// 1874a0
namespace src32 {
s32 func_001874a0(void* a, f32 f) asm("func_001874a0");
s32 func_001874a0(void* a, f32 f) {
    u8* o = D_0034e948;
    s32 r;
    if (!func_0019ba60(o) || !*(void**)(o + 2880)) {
        r = 0;
    } else {
        func_0019d358(*(void**)(o + 2880));
        r = func_00187300(a, *(u8**)(o + 2880) + 4, f);
    }
    return r;
}
}

// ==== from src/anon/batch_w92.cpp
namespace src33 {

struct E187 { u32 f0; u32 f4; u32 f8; };
s32 func_0017e138(u8*, s32) asm("func_0017e138");
s32 func_001a1910(E187*, s32, s32) asm("func_001a1910");
void func_0013def8(u8*) asm("func_0013def8");
void func_0019d3f8(u8*, s32, s32) asm("func_0019d3f8");
void func_0019d3b8(u8*, s32, s32) asm("func_0019d3b8");
void func_00187818(u8*) asm("func_00187818");

}

// 187520
namespace src33 {
s32 func_00187520(u8* self, s32 n, s32 idx, u8 flag) asm("func_00187520");
s32 func_00187520(u8* self, s32 n, s32 idx, u8 flag) {
    E187* t = *(E187**)(self + 1164);
    if (!t || !t[idx].f4) return 0;
    if (*(u32*)(self + 1416) & 0x4000) {
        if (n > 0) {
            if (*(u32*)(self + 2040) & 4) {
                n = func_0017e138(self, n);
            } else if (flag) {
                (*(void (**)(u8*, s32, s32))(*(u8**)self + 84))(self, 20, 0);
            }
        }
    }
    if (*(u32*)(self + 2040) & 4) return 0;
    s32 r = func_001a1910(*(E187**)(self + 1164), n, idx);  // entry12_add_clamped
    if (n > 0) {
        func_0013def8(self);
        func_0019d3f8(self, idx, r);
    } else {
        func_0019d3b8(self, idx, r);
    }
    if (!r && !idx) func_00187818(self);
    return r;
}
}

// ==== from src/anon/batch_w81.cpp
namespace src34 {

typedef void (*VFnV81)(...);

struct VObjV81 { VFnV81* vt; };
void func_00187728(u8*, f32) asm("func_00187728");
s32 func_001a1990(u8*, s32) asm("func_001a1990");

s32 ctarget_00187650(u8* o, s32 n, u32 flag, u32) asm("_Z16ctarget_00187650jjjj");
}

// 187650
namespace src34 {
s32 ctarget_00187650(u8* o, s32 n, u32 flag, u32) asm("_Z16ctarget_00187650jjjj");
s32 ctarget_00187650(u8* o, s32 n, u32 flag, u32) {
    u8* t = *(u8**)(o + 1164);
    s32 r = 0;
    flag &= 0xff;
    if (t == 0 || (*(u32*)(o + 2040) & 4)) return 0;
    if ((*(u32*)(o + 1416) & 0x4000) && n > 0 && flag && !(*(u32*)(o + 352) & 0x4000)) {
        ((VObjV81*)o)->vt[21](o, 20, 0);
        t = *(u8**)(o + 1164);
    }
    if (*(s32*)(t + 384) + n < 0) {
        func_00187728(o, 1.0f);
    } else {
        r = func_001a1990(t, n);
    }
    return r;
}
}

// 187728 (from src/yasui/libys/sheet.cpp)
namespace YS {
class SHEET { public: void mpdrive(f32 ratio); };
}
extern "C" void func_001a1d40(u32, f32);
void YS::SHEET::mpdrive(f32 ratio) {
    f32 f0 = ratio;
    u32 t7 = *(u32*)((u32)this + (s32)(300));
    f32 f12 = *(f32*)((u32)t7 + (s32)(28));
    u32 a0 = *(u32*)((u32)this + (s32)(1164));
    f12 = (f32)(f12 * f0);
    func_001a1d40(a0, f12);
}
// 187750
namespace src15 {
void func_00187750(u32 a0) asm("func_00187750");
void func_00187750(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(2784));
    if (t7 != 0u) {
        a0 = t7;
        if (func_001dc9e0(a0) != 0u) goto L1;
        func_001dc920(*(u32*)((u32)s0 + (s32)(2784)));
        *(u32*)((u32)s0 + (s32)(2784)) = 0u;
    }
L1:
    func_0016a5b0(s0);
}
}

// ==== from src/anon/batch_w44.cpp
namespace src35 {
void func_001dc978(void*, f32) asm("func_001dc978");
void* func_001de168(u32, u32, u32, u32, u32, void*) asm("func_001de168");

}

// 1877a0
namespace src35 {
void func_001877a0(u8* o, u32 a, u32 b) asm("func_001877a0");
void func_001877a0(u8* o, u32 a, u32 b) {
    if (*(void**)(o + 2784)) func_001dc978(*(void**)(o + 2784), 10.0f);
    *(void**)(o + 2784) = func_001de168(a, b, 0, 1, 10000, o);
}
}

// 187818
namespace src15 {
void func_00187818(u32 a0) asm("func_00187818");
void func_00187818(u32 a0) {
    if ((*(u32*)((u32)a0 + (s32)(2040)) & 0x0004u) == 0u) {
        u32 t7 = *(u32*)((u32)a0 + (s32)(0));
        u32 t6 = *(u32*)((u32)t7 + (s32)(92));
        ((void(*)(u32))(u32)t6)(a0);
    }
}
}

// 187850
namespace src1 {
void func_00187850(BD_VALUE* bd) asm("func_00187850");
void func_00187850(BD_VALUE* bd) { func_00187868(bd); }
}

// 187868
namespace src10 {
u32 func_00187868(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00187868");
u32 func_00187868(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 2040u) = (u32)(((u32)(((u32)(*(u32*)((u32)(a0) + 2040u)))) | 0x4u));
    return func_001d7a50(((u32)(a0) + 1304u), a1, a2, a3);
}
}

// 187890
namespace src7 {
void func_00187890(u32 a0) asm("func_00187890");
void func_00187890(u32 a0) {
    u32 s0 = a0;
    if ((*(u32*)(a0 + 2040) & 4) != 0) return;
    u32 t7 = *(u32*)(a0 + 2072);
    if (t7 != 0) func_0019aa00(t7, s0);
    func_00187868(s0);
}
}

// ==== from src/anon/auto200_999.cpp
namespace src36 {
void func_001c0458(u32, u32) asm("func_001c0458");
void wtarget_001878e8(u32 a0, u32, u32, u32);

}

// 1878e8
namespace src36 {
void wtarget_001878e8(u32 a0, u32, u32, u32) asm("_Z16wtarget_001878e8jjjj");
void wtarget_001878e8(u32 a0, u32, u32, u32) {
    register u32 p asm("$14") = a0 + 2640;
    asm volatile("" : "+r"(p));
    u32 v = *(u32 *)(a0 + 2732);
    if (v != 0) {
        func_001c0458(p, v);
    }
}
}

// ==== from src/anon/batch_w88.cpp
namespace src37 {
s32 func_001d7ba8(u8*) asm("func_001d7ba8");
s32 func_00105300(void) asm("func_00105300");
s32 func_001c8db8(u8*, u32) asm("func_001c8db8");
extern u8 D_00351ec8[] asm("D_00351ec8");


static inline bool Bit187920(u32 x, u32 m) { return (x & m) != 0; }
}

// 187920
namespace src37 {
s32 func_00187920(u8* p) asm("func_00187920");
s32 func_00187920(u8* p) {
    s32 r = 0;
    if (Bit187920(*(u32*)(p + 264), 0x100) || Bit187920(*(u32*)(p + 352), 0x400000) || func_001d7ba8(p + 1304) ||
        Bit187920(*(u32*)(p + 264), 0x10000000) || Bit187920(*(u32*)(p + 264), 0x80000) || Bit187920(*(u32*)(p + 2040), 0x10) ||
        Bit187920(*(u32*)(p + 2040), 0x200) || func_00105300() || func_001c8db8(D_00351ec8, 0))
        r = 1;
    return r;
}
}

// ==== from src/anon/batch_w1668.cpp
namespace src38 {

}

// 1879f0
namespace src38 {
void func_001879f0(u32* p) asm("func_001879f0");
void func_001879f0(u32* p) {
    s32 i = 127;
    do { *p = 0; i--; asm volatile("nop\n\tnop\n\tnop"); p += 8; } while (i >= 0);
}
}

// ==== from src/anon/batch_w66.cpp
namespace src39 {
u8* func_00187ab8(u32, u32) asm("func_00187ab8");
u8* func_00187b30(u32) asm("func_00187b30");

struct S187 { u32 f0; s16 lo; s16 hi; s16 d; u16 v[11]; };

}

// 187a18
namespace src39 {
void func_00187a18(u32 a, u32 b, s32 c, s32 d, u32* src) asm("func_00187a18");
void func_00187a18(u32 a, u32 b, s32 c, s32 d, u32* src) {
    S187* v = (S187*)func_00187ab8(a, b);
    if (!v) {
        v = (S187*)func_00187b30(a);
        v->f0 = b;
    }
    v->d = d;
    v->hi = c >> 16;
    v->lo = c;
    for (s32 i = 0; i < 11; i++) v->v[i] = src[i];
}
}

// ==== from src/anon/batch_w224.cpp
namespace src40 {
extern u32 strcmp(u32, u32) asm("strcmp");
           
u32 ctarget_00187ab8(u32* t, u32 b, u32 c, u32 d) asm("_Z16ctarget_00187ab8jjjj");
}

// 187ab8
namespace src40 {
u32 ctarget_00187ab8(u32* t, u32 b, u32 c, u32 d) asm("_Z16ctarget_00187ab8jjjj");
u32 ctarget_00187ab8(u32* t, u32 b, u32 c, u32 d) {
  u32 r = 0;
  if (t) {
    u32* p = t;
    for (int i = 0; i < 128; i++, p += 8) {
      r = *p;
      if (r && !strcmp(b, r)) { r = (u32)p; goto out; }
    }
    r = 0;
  }
out:
  return r;
}
}

// 187b30
namespace src15 {
u32 func_00187b30(u32 a0) asm("func_00187b30");
u32 func_00187b30(u32 a0) {
    if (a0 == 0u) return 0u;
    u32 p = a0;
    for (s32 i = 0; i < (s32)128; i = i + 1, p = (u32)((s32)p + (32))) {
        if (*(u32*)((u32)p + (s32)0) == 0u) return p;
    }
    return 0u;
}
}

// 187b68
namespace src15 {
void func_00187b68(void) asm("func_00187b68");
void func_00187b68(void) {
    u32 v0 = func_00187ab8();
    if (v0 != 0u) {
        *(u32*)((u32)v0 + (s32)0) = 0u;
    }
}
}

// ==== from src/anon/batch_w1752_nsa.cpp
namespace src41 {


struct W1752C0 { u8 pad[0x88]; u32 v88; u8 pad2[4]; u8* p90; u32 p94; };
void func_00188398(W1752C0*, u32, u32*, s32) asm("func_00188398");
void func_0016ced0(u32) asm("func_0016ced0");

void w1752_ct0_00187b90(W1752C0* c) asm("_Z17ctarget0_00187b90v");
}

// 187b90
namespace src41 {
void w1752_ct0_00187b90(W1752C0* c) asm("_Z17ctarget0_00187b90v");
void w1752_ct0_00187b90(W1752C0* c) {
    if (c->p94) {
        u8* p = c->p90;
        u32 t = c->v88;
        func_00188398(c, *(u16*)(p + 10), &t, 1);
        func_0016ced0(c->p94);
        c->p94 = 0;
        c->p90 = 0;
    }
}
}

// ==== from src/anon/batch_w1788.cpp
namespace src42 {

struct W1788QEnt { s32* p; s32 flags; };

struct W1788Q { s32 rd; s32 wr; W1788QEnt e[16]; u8 pad[0x98 - 0x88]; s32 busy; };
void* func_002edbf8(s32) asm("func_002edbf8");
void func_001880b0(void*, s32) asm("func_001880b0");
void func_00187fd8(W1788Q*, s32*) asm("func_00187fd8");

}

// 187be8
namespace src42 {
s32 func_00187be8(W1788Q* q) asm("func_00187be8");
s32 func_00187be8(W1788Q* q) {
    s32 r;
    if (q->wr != q->rd) {
        r = 0;
        if (!q->busy) {
            s32 i = q->wr;
            q->wr = (i + 1) % 16;
            W1788QEnt* e = &q->e[i];
            s32 m = e->flags & 1;
            if (m) {
                void* p = func_002edbf8(1);
                if (p) func_001880b0((u8*)p + 0x300, *e->p);
                r = func_00187be8(q);
            } else {
                func_00187fd8(q, e->p);
                r = 1;
            }
        }
    } else r = 0;
    return r;
}
}

// ==== from src/anon/perm_00187ca0.cpp
namespace src43 {



typedef struct Obj187 Obj187;

struct Obj187
{
  u8 pad0[0x8c];
  s32 x8c;
  u8 pad90[4];
  s32 x94;
  s32 x98;
  u32 x9c;
  s32 xa0;
  u8 padA4[4];
  f32 xa8;
};
extern u32 D_01c60bc0[] asm("D_01c60bc0");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_0016cd48(s32, s32) asm("func_0016cd48");

void func_0016d110(void) asm("_Z17ttarget0_0016d110v");
void func_00187b90(Obj187 *) asm("_Z17ctarget0_00187b90v");s32 func_00187be8(Obj187 *) asm("func_00187be8");
s32 func_00187e20(Obj187 *) asm("func_00187e20");
s32 func_00187e58(Obj187 *) asm("func_00187e58");
void func_001884d0(Obj187 *, s32 *) asm("func_001884d0");
s32 func_001886d0(Obj187 *) asm("func_001886d0");

}

// 187ca0
namespace src43 {
void func_00187ca0(Obj187 *p) asm("func_00187ca0");
void func_00187ca0(Obj187 *p)
{
  s32 mx = 0;
  if (p->x8c == 0)
  {
    return;
  }
  s32 *q = &p->xa0;
  if ((*q) != 0)
  {
    p->xa8 -= D_00349e10;
    if (p->xa8 <= 0.0f)
    {
      func_001884d0(p, q);
      p->xa0 = 0;
    }
  }
  D_01c60bc0[0] = (u32) p;
  if (1)
  {
    p->x9c |= 2;
  }
  for (;;)
  {
    if (func_00187e20(p))
    {
      break;
    }
    u32 fl;
    if (func_00187be8(p) == 0)
    {
      u32 g = *((volatile u32 *) (&p->x9c));
      if (D_00349e10)
      {
        fl = g;
      }
      else
      {
        fl = g;
      }
      if (!(g & 2))
      {
        break;
      }
    }
    else
    {
      fl = p->x9c;
    }
    p->x9c = fl & (~2);
    if (p->x94 == 0)
    {
      continue;
    }
    if (p->x9c & 4)
    {
      if (!func_001886d0(p))
      {
        break;
      }
      p->x9c &= ~4;
    }
    if (mx < p->x98)
    {
      mx = p->x98;
    }
    if ((mx < 300) && func_00187e58(p))
    {
      break;
    }
    if (func_0016cd48(p->x94, 0) && (!(p->x9c & 2)))
    {
      func_00187b90(p);
      p->x98 = 0;
    }
  }

  D_01c60bc0[0] = 0;
  func_0016d110();
}
}

// 187e20
namespace src36 {
u32 func_00187e20(u32 a0) asm("func_00187e20");
u32 func_00187e20(u32 a0) {
    register u32 v asm("$15") = *(u32 *)(a0 + 156);
    v &= 1;
    v &= 0xff;
    asm volatile("" : "+r"(v));
    u32 ret = 0;
    if (v == 0) {
        register u32 p asm("$14") = *(u32 *)(a0 + 136);
        register u32 q asm("$13") = *(u32 *)(p + 4);
        v = *(u32 *)(q + 352);
        register u32 mask asm("$14") = 0x40000;
        v &= mask;
        ret = v != 0;
    }
    return ret;
}
}

// ==== from src/anon/batch_w1773.cpp
namespace src44 {


              
struct W1773Tgt { u8 pad[0x154]; s32 kind; u8 pad2[0x588 - 0x158]; u32 flags; };

struct W1773Link { u32 x0; W1773Tgt* t; };

struct W1773Obj { u8 pad[0x88]; W1773Link* l; u8 pad2[0x9c - 0x8c]; u32 off : 1; u32 rest : 31; };

s32 ctarget_00186ce8(W1773Tgt*) asm("_Z16ctarget_00186ce8jjjj");s32 func_00186d18(W1773Tgt*) asm("func_00186d18");

}

// 187e58
namespace src44 {
s32 func_00187e58(W1773Obj* a) asm("func_00187e58");
s32 func_00187e58(W1773Obj* a) {
    if ((u8)a->off) return 0;
    if ((a->l->t->flags & 2) && (ctarget_00186ce8(a->l->t) || func_00186d18(a->l->t))) return 1;
    W1773Tgt* t = a->l->t;
    if (t->flags & 8) return t->kind == 0x32;
    return 0;
}
}

// ==== from src/anon/batch_w2369.cpp
namespace src45 {

struct RingEnt { s32 v; s32 t; };

struct Ring16 { s32 head; s32 tail; RingEnt ent[16]; };
void func_0031cc28(s32*) asm("func_0031cc28");

}

// 187ef0
namespace src45 {
void func_00187ef0(Ring16* r, s32 v) asm("func_00187ef0");
void func_00187ef0(Ring16* r, s32 v) {
    s32 i = r->head;
    s32 c = (i - r->tail + 16) % 16;
    if (c < 15) {
        RingEnt* p = &r->ent[i];
        r->head = (i + 1) % 16;
        RingEnt e;
        e.v = v;
        e.t = 0;
        func_0031cc28(&e.t);
        *p = e;
    }
}
}

// 187f90
namespace src15 {
void func_00187f90(u32 a0) asm("func_00187f90");
void func_00187f90(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(156));
    t7 = (u32)((u8)(t7 & 1u));
    u32 s0 = a0;
    if (t7 == 0u) {
        func_00187b90();
        *(u32*)((u32)s0 + (s32)0) = 0u;
        *(u32*)((u32)s0 + (s32)4) = 0u;
        *(u32*)((u32)s0 + (s32)152) = 0u;
    }
}
}

// ==== from src/anon/batch_w1804_nsa.cpp
namespace src46 {

                                                                              

struct W1804C1 { u8 pad[0x1c]; s32 flags; };

struct W1804C2 { u8 pad[0x484]; W1804C1* p; };

struct W1804C3 { u8 pad[4]; W1804C2* p; };

struct W1804Desc { u16 m0, m2, m4; union { u16 m6; u8 b6; struct { u8 b0:1; } bf; }; u16 m8; u8 pad[0x16-0xa]; u16 m16; };

struct W1804Obj { u8 pad[0x88]; W1804C3* m88; u8 pad2[4]; W1804Desc* m90; s32 m94; s32 m98; s32 m9c; };

struct W1804Loc { W1804C3* p; u32 pad[3]; };
void func_00187b90(W1804Obj*) asm("func_00187b90");
s32 func_0016cf00(W1804C1*, s32, s32, W1804Loc*, s32) asm("func_0016cf00");
void func_00188398(W1804Obj*, s32, W1804Loc*, s32) asm("func_00188398");

}

// 187fd8
namespace src46 {
void func_00187fd8(W1804Obj* o, W1804Desc* d) asm("func_00187fd8");
void func_00187fd8(W1804Obj* o, W1804Desc* d)
{
    if (!(o->m88->p->p->flags & 2)) {
    func_00187b90(o);
    W1804Loc l;
    l.p = o->m88; o->m94 = func_0016cf00(l.p->p->p, 0, d->m8, &l, 1);
    o->m90 = d;
    o->m98 = d->m4;
    o->m9c = 0;
    if (d->m6 & 2) o->m9c = 1;
    if (!(d->b6 & 1)) o->m9c |= 4;
    o->m9c |= 2;
    func_00188398(o, d->m16, &l, 1);
    }
}
}

// 1880b0
namespace src7 {
void func_001880b0(u32 a0, u32 a1) asm("func_001880b0");
void func_001880b0(u32 a0, u32 a1) {
    u32 s0 = a0;
    if ((*(u32*)(a0 + 156) & 1) != 0) return;
    u32 s1 = func_00187ab8(*(u32*)(a0 + 140), a1);
    if (s1 == 0) return;
    func_00187f90(s0);
    func_00187fd8(s0, s1);
}
}

// 188120
namespace src15 {
void func_00188120(u32 a0, u32 a1) asm("func_00188120");
void func_00188120(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 v0 = func_001883d8(a0, a1);
    a0 = s0;
    a1 = s1;
    if (v0 != 0u) {
        func_001880b0(a0, a1);
        return;
    }
}
}

// ==== from src/anon/batch_w62.cpp
namespace src47 {


struct Act { u8 pad[140]; u32 f8c; u8 pad2[8]; s32 f98; u32 f9c; };

struct Pri { u16 h0; u16 h2; u16 h4; };
Pri* func_00187ab8(u32) asm("func_00187ab8");
void func_00187f90(Act*) asm("func_00187f90");
void func_00187fd8(Act*, Pri*) asm("func_00187fd8");

void act_pri_start(Act* a) asm("_ZN2YS3ACT9pri_startEPc");
}

// 188170
namespace src47 {
void act_pri_start(Act* a) asm("_ZN2YS3ACT9pri_startEPc");
void act_pri_start(Act* a) {
    u32 m = a->f9c & 1;
    u8 on = m;
    if (on) return;
    Pri* r = func_00187ab8(a->f8c);
    if (!r) return;
    if (r->h4 < a->f98) return;
    func_00187f90(a);
    func_00187fd8(a, r);
}
}

// 1881f8
namespace src7 {
void func_001881f8(u32 a0, u32 a1) asm("func_001881f8");
void func_001881f8(u32 a0, u32 a1) {
    u32 s0 = a0;
    if ((*(u32*)(a0 + 156) & 1) != 0) return;
    u32 v0 = func_00187ab8(*(u32*)(a0 + 140), a1);
    if (v0 == 0) return;
    func_00187ef0(s0, v0);
}
}

// 188250
namespace src7 {
void func_00188250(u32 a0, u32 a1) asm("func_00188250");
void func_00188250(u32 a0, u32 a1) {
    u32 s0 = a0;
    func_001881f8(s0, a1);

    s32 t15 = *(s32*)(s0 + 0);
    s32 t14 = t15 + 15;
    s32 t13 = 0;
    if (t14 < 0) t13 = 1;
    t15 = t15 + 30;
    if (t13 == 0) t15 = t14;
    t15 = (t15 >> 4) << 4;
    t14 = t14 - t15;

    u32 p = s0 + ((u32)t14 << 3);
    *(u32*)(p + 12) |= 1;
}
}

// ==== from src/anon/batch_w53.cpp
namespace src48 {

struct Pair { u32 a; u32 b; };

void ctarget0_00187b90(u8*) asm("_Z17ctarget0_00187b90v");u32 func_00187ab8(u32) asm("func_00187ab8");
void func_0031cc28(u32*) asm("func_0031cc28");

}

// 1882a8
namespace src48 {
void func_001882a8(u8* p) asm("func_001882a8");
void func_001882a8(u8* p) {
    u32 v = func_00187ab8(*(u32*)(p + 140));
    if (v) {
        ctarget0_00187b90(p);
        Pair t;
        t.a = v;
        t.b = 0;
        *(s32*)(p + 4) = (*(s32*)(p + 4) + 15) % 16;
        Pair* e = (Pair*)(p + 8) + *(s32*)(p + 4);
        func_0031cc28(&t.b);
        *e = t;
        *(u32*)(p + 152) = 0;
    }
}
}

// ==== from src/anon/batch_w52.cpp
namespace src49 {
u32 func_00188398(u8*, u32, u32*, u32) asm("func_00188398");

}

// 188340
namespace src49 {
u32 func_00188340(u8* p, s32 i, u32* a2, u32 a3) asm("func_00188340");
u32 func_00188340(u8* p, s32 i, u32* a2, u32 a3) {
    u8* t = *(u8**)(p + 144);
    if (!t) return 0;
    if (*(u32*)(p + 156) & 4) return 0;
    u32 tmp;
    if (!a2) {
        tmp = *(u32*)(p + 136);
        a2 = &tmp;
        a3 = 1;
    }
    return func_00188398(p, *(u16*)(t + i * 2 + 10), a2, a3);
}
}

// ==== from src/anon/batch_w12.cpp
namespace src50 {
void func_0016cc18(void*, void*, void*, void*, s32) asm("func_0016cc18");

}

// 188398
namespace src50 {
s32 func_00188398(u8* o, void* a, void* b, void* c) asm("func_00188398");
s32 func_00188398(u8* o, void* a, void* b, void* c) {
    void* w;
    u8* x = *(u8**)(o + 136);
    w = *(void**)(*(u8**)(x + 4) + 1156);
    if (w) {
        if (a) { func_0016cc18(w, a, b, c, 0); return 1; }
    }
    return 0;
}
}

// ==== from src/anon/tiny_jal_wrappers.cpp
namespace src51 {
u32 func_00187ab8(u32, u32, u32, u32) asm("func_00187ab8");

}

// 1883d8
namespace src51 {
u32 func_001883d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001883d8");
u32 func_001883d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = *(u32*)((u32)r4 + (s32)(140));
    r2 = func_00187ab8(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}

// 1883f8
namespace src3 {
void func_001883f8(u8* p, u32 a) asm("func_001883f8");
void func_001883f8(u8* p, u32 a) {
    D_01c60bc8[0] = *(u32*)(p + 136);
    D_01c60bc8[1] = a;
    func_00188340(p, 3, D_01c60bc8, 2);
}
}

// ==== from src/anon/batch_w13.cpp
namespace src52 {
void func_00188340(void*, s32, void*, s32) asm("func_00188340");
extern u32 D_01c60bd0[3] asm("D_01c60bd0");

}

// 188430
namespace src52 {
void func_00188430(u8* p, u32 a1, u32 a2) asm("func_00188430");
void func_00188430(u8* p, u32 a1, u32 a2) {
    u32* t = D_01c60bd0;
    t[0] = *(u32*)(p + 136);
    t[1] = a1;
    t[2] = a2;
    func_00188340(p, 7, t, 3);
}
}

// ==== from src/anon/batch_w1726.cpp
namespace src53 {
void func_00188490(void*, void*) asm("func_00188490");

}

// 188470
namespace src53 {
void func_00188470(void* a, void* b) asm("func_00188470");
void func_00188470(void* a, void* b) { func_00188490(b, *(void**)((u8*)a + 0x88)); }
}

// ==== from src/anon/batch_w1670.cpp
namespace src54 {

struct E12_1c608c0 { s32 a; s32 b; f32 c; };
extern E12_1c608c0 D_01c608c0[64] asm("D_01c608c0");

}

// 188490
namespace src54 {
void func_00188490(s32 a, s32 b, f32 c) asm("func_00188490");
void func_00188490(s32 a, s32 b, f32 c) {
    s32 i = 0;
    E12_1c608c0* e = D_01c608c0;
    do {
        if (e->a == 0) { e->a = a; e->b = b; e->c = c; return; }
        i++; e++;
    } while (i < 64);
}
}

// ==== from src/anon/batch_w56.cpp
namespace src55 {


           
union U188 { u16 h; u32 w; };
extern u32 D_01c60be0[] asm("D_01c60be0");
u8* func_00187ab8(void*, u32) asm("func_00187ab8");
void func_00188398(u8*, u16, u32*, s32) asm("func_00188398");

}

// 1884d0
namespace src55 {
void func_001884d0(u8* a, u32* b) asm("func_001884d0");
void func_001884d0(u8* a, u32* b)
{
    void* q = *(void**)(a + 140);
    if (!q) return;
    u8* r = func_00187ab8(q, b[0]);
    if (!r) return;
    D_01c60be0[0] = *(u32*)(a + 136);
    D_01c60be0[1] = b[1];
    func_00188398(a, ((U188*)(r + 20))->h, D_01c60be0, 2);
}
}

// ==== from src/anon/batch_w100.cpp
namespace src56 {
}
namespace w100_a11 { 
struct E11 { u32 a; u32 b; f32 t; }; }
namespace src56 {
}
namespace w100_a11 { extern E11 D_01c608c0[64] asm("D_01c608c0"); }
namespace src56 {
}
namespace w100_a11 { extern u32 D_003638d0 asm("D_003638d0"); }
namespace src56 {
}
namespace w100_a11 { u8* func_001b9bc8(u8*) asm("func_001b9bc8"); }
namespace src56 {
}
namespace w100_a11 { void func_001884d0(u8*, E11*) asm("func_001884d0"); }
namespace src56 {

}

