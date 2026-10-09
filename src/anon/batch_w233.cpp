#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));


extern "C" {
extern u8 D_0034af40[];
struct G { u8 p0[276]; u32 f114; u8 p1[48]; u32 f148; u32 f14c; };
extern G D_0034b0e0;
void func_00236788(void*);
u32 func_00239d30(void*, u32);
s32 func_00239d10(void*);
u32 func_0014aba8();
void func_0014aa58(u32, s32, s32);
void func_0013f020();
void func_0023acd8(void*);
void func_0023ade0(void*);
s32 func_0015d440() {
    func_00236788(D_0034af40);
    if (!(u8)func_00239d30(&D_0034b0e0, D_0034b0e0.f114)) {
        if (!func_00239d10(&D_0034b0e0)) {
            func_0014aa58(func_0014aba8(), 1, 0);
            func_0013f020();
            return 1;
        }
    }
    func_0023acd8(&D_0034b0e0);
    D_0034b0e0.f148 = 0;
    D_0034b0e0.f14c = 0;
    func_0023ade0(&D_0034b0e0);
    return 0;
}

extern u8* D_00347d64;
void func_00192c90(u32, void*);
void func_00192b30(u32);
void func_00138210(u32 a) {
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

extern f32 D_00349e14;
s32 func_00197920(void*);
void func_00138c10(void*, s32);
void func_001390a8(void*);
struct V15ae { u8 p[20]; void (*f5)(void*); };
void func_0015ae00(u8* a) {
    if (func_00197920(a)) {
        (*(V15ae**)a)->f5(a);
        return;
    }
    f32 f = *(f32*)(a + 436);
    if (f <= 0.0f) {
        func_00138c10(a, 0x30);
        *(f32*)(a + 436) = 20000.0f;
        f = *(f32*)(a + 436);
    }
    if (f != 20000.0f) *(f32*)(a + 436) = f - D_00349e14;
    func_001390a8(a);
}

extern u32 D_003638d0;
s64 func_00312db8(u64, u64);
void func_001e26b8(u8* a, Vq* src) {
    for (s32 i = 0; i < 200; i++, a += 16) {
        if (a[332] == 0) {
            *(Vq*)(a + 320) = *src;
            a[333] = 0;
            a[332] = 0x80;
            D_003638d0 = D_003638d0 * 69069;
            s32 r = func_00312db8(D_003638d0, 0x01010102);
            a[334] = r;
            a[335] = 60;
            return;
        }
    }
}

extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u32* D_0035eea4;
extern s16* D_0035ee9c;
void func_002529a8();
u32* func_0023ee30(u32);
void func_0031a838(u32*);
void func_002369a0(u32*);
void func_0023c008(u32*);
void func_0028d7f0(u32*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u32*);
void func_00252d88();
void func_00252900() {
    func_002529a8();
    u32* p = func_0023ee30(160);
    *p = (u32)D_00347f98;
    func_0031a838(p + 3);
    *p = (u32)D_0035eb98;
    func_002369a0(p + 6);
    func_0023c008(p + 12);
    D_0035eea4 = p;
    func_0028d7f0(p, 30002, 0, 0, D_0035ee9c[0], D_0035ee9c[1], 0, 0, 0);
    func_0023ef50(D_0035eea4);
    func_00252d88();
}

extern u32 D_00367920;
extern u8 D_01e4c798[];
extern s32 D_01e4c7a0;
u32* func_00316e00();
u32* func_00316e10();
s32 func_003060f0();
s32 func_00305510();
u32 func_00316a50() {
    if (D_00367920) {
        s32 s = D_01e4c7a0;
        u32* a = func_00316e00();
        u32* b = func_00316e10();
        if (s < 9) {
            if (b[s]) {
                s32 k = 0;
                if (func_003060f0() != 1) k = func_00305510();
                return a[k * 8 + s];
            }
        }
        return 0;
    }
    return (u32)D_01e4c798;
}
}
