#include "../common/types.h"
// batch w1772: built with -fno-strict-aliasing (see Makefile *_nsa rule).
typedef unsigned int u128 __attribute__((mode(TI)));
inline void* operator new(unsigned int, void* p) { return p; }
struct V3_w1772 { s32 a, b, c; V3_w1772() : a(0), b(0), c(0) {} };
struct F4_w1772 { f32 x, y, z, w; F4_w1772() { x = w = z = y = 0.0f; } };
extern "C" {
void func_001980d0(u8*, u32, u32, u32);
void func_00190128(u8*);
void func_0019f950(u8*, u8*);
extern u8 D_0034ee08;
void func_002f25a0(s32, s32);
void FlushCache(s32);
void func_002f3918(s32, void*);
extern s32 D_003591c8;
extern u64 D_01da8c40[];

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

// Byte-identical twin of func_00185ed8 (a second class with the same ctor).
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

// GIF packet: 128-bit tag, GIFtag (NLOOP=1, EOP, NREG=2, REGS=A+D,A+D), two A+D pairs.
struct Pkt_w1772 { u128 tag; u64 a; u64 b; u64 c[4]; };
void func_0020e0a0(void) {
    Pkt_w1772 k;
    k.tag = 0x70000003;
    u64* p = &k.a;
    u64* s = D_01da8c40;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = s[8];
    p[3] = s[9];
    p[4] = s[6];
    p[5] = s[7];
    func_002f25a0(0, 0);
    FlushCache(0);
    func_002f3918(D_003591c8, &k);
    func_002f25a0(0, 0);
}
}
