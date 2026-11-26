#include "../common/types.h"

// GS packet / sprite helpers (0x1085a8-0x109788), incl. the never-written 0x108988 (empty) and 0x108a88 (masked A+D register setter). D_0036a194 is an unused .rodata word. Old _nsa copies decided -fno-strict-aliasing.
// Each function keeps the declarations of the source it was matched in (namespace nADDR); every symbol
// is bound by asm label.
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 001085a8 (from src/anon/auto80_199_queue.cpp)
namespace n001085a8 {
u32 func_00133bb8(u32, u32, u32, u32) asm("func_00133bb8");
// 00106178: moved to src/naka/libkn/memoryallocator.cpp

// 00106358: moved to src/naka/libkn/memoryallocator.cpp

u32 func_001085a8(u32 a0, const u8* a1) asm("func_001085a8");
u32 func_001085a8(u32 a0, const u8* a1) {
    const u8* s0 = a1;
    u32 v0 = func_00133bb8(a0, 1, 0x01000101, 0x6c010001);  // forward_sub24_to_133848

    *(u32*)(v0 + 0) = s0[0];
    *(u32*)(v0 + 4) = s0[1];
    *(u32*)(v0 + 8) = s0[2];
    *(u32*)(v0 + 12) = s0[3];
    return v0;
}
}  // namespace n001085a8

// 00108600 (from src/anon/batch_w61.cpp)
namespace n00108600 {
void func_0010a800(u8*, u8*, u8*) asm("func_0010a800");
// copy_global_3bytes
void func_00108600(u8* p) asm("func_00108600");
void func_00108600(u8* p) {
    *(u32*)p = 0;
    p[4] = p[5] = p[6] = p[7] = 0x80;
    func_0010a800(p + 8, p + 9, p + 10);  // copy_global_3bytes
    p[11] = 0xff;
    p[43] = 0x80;
    p[42] = 0x80;
    p[41] = 0x80;
    *(u64*)(p + 24) = 0x31000070;
    *(u64*)(p + 16) = 0x800d8;
    *(u32*)(p + 32) = 0;
    *(u32*)(p + 36) = 0;
    p[40] = 0;
    *(u32*)(p + 44) = 0;
    *(u32*)(p + 48) = 0;
    *(u32*)(p + 52) = 0;
}
}  // namespace n00108600

// 00108698 (from src/anon/batch_w62.cpp)
namespace n00108698 {
void func_0010a800(u8*, u8*, u8*) asm("func_0010a800");
// copy_global_3bytes
void func_00108698(u8* p) asm("func_00108698");
void func_00108698(u8* p) {
    *(u32*)p = 0;
    p[7] = 0x80;
    p[6] = 0x80;
    p[5] = 0x80;
    p[4] = 0x80;
    func_0010a800(p + 8, p + 9, p + 10);  // copy_global_3bytes
    p[11] = 0xff;
    p[43] = 0x80;
    p[42] = 0x80;
    p[41] = 0x80;
    *(u64*)(p + 24) = 0x31000070;
    *(u64*)(p + 16) = 0x800d8;
    *(u32*)(p + 32) = 0;
    *(u32*)(p + 36) = 0;
    p[40] = 0;
    *(u32*)(p + 44) = 0;
    *(u32*)(p + 48) = 0;
    *(u32*)(p + 52) = 0;
}
}  // namespace n00108698

// 00108730 (from src/anon/batch_w1986_nsa.cpp)
namespace n00108730 {
typedef unsigned int u128 __attribute__((mode(TI)));
// 00108730: GIF packet setup. The 128-bit zero store is an sq $0 asm (C gives por+sq).
struct W1986GifTag {
    u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4;
    u64 REGS;
} __attribute__((aligned(16)));
struct W1986Pkt {
    W1986GifTag tag;
    u32 rgba[4];
    f32 st[4];
    f32 a[4];
    f32 b[4];
};
struct W1986Src {
    u32 flags;
    u8 c[4];
    u8 pad8[3];
    u8 b11;
    u8 pad0c[0x14];
    f32 f20;
    s32 x24;
};
extern u128 D_00340f10 asm("D_00340f10");
extern u128 D_00340f20 asm("D_00340f20");
extern u8 D_00340eb0 asm("D_00340eb0");
u32* func_00133bb8(void*, s32, u32, u32) asm("func_00133bb8");
s32 func_0010aba8(void) asm("func_0010aba8");
void func_0010a8e0(void*) asm("func_0010a8e0");
s32 kn__getProjection(s32) asm("kn__getProjection");
f32 func_001070a8(s32) asm("func_001070a8");
W1986Pkt* func_00108730(W1986Src* p, void* q) asm("func_00108730");
W1986Pkt* func_00108730(W1986Src* p, void* q)
{
    u32* d = func_00133bb8(q, 12, 0x11000000, 0x13000000);
    d[0] = 0;
    d[1] = 0;
    d[2] = 0x01000404;
    d[3] = 0x6c0a4000;
    W1986Pkt* k = (W1986Pkt*)(d + 4);
    __asm__ volatile("sq $0, 0(%0)" : : "r"(d + 40));
    d += 44;
    d[0] = 0x14000000;
    d[1] = 0x11000000;
    d[2] = 0x13000000;
    d[3] = 0;
    if (p->x24 == 0) {
        *(u128*)&k->tag = D_00340f10;
    } else {
        *(u128*)&k->tag = D_00340f20;
    }
    k->tag.PRIM &= ~0x20;
    if ((D_00340eb0 ^ 1) == 0) {
        k->tag.PRIM |= 0x20;
    } else if (func_0010aba8() == 7 && (p->flags & 2)) {
        k->tag.PRIM |= 0x20;
    }
    k->rgba[0] = p->c[0];
    k->rgba[1] = p->c[1];
    k->rgba[2] = p->c[2];
    k->rgba[3] = p->c[3];
    if (p->flags & 2) {
        k->st[0] = 0;
        k->st[1] = p->b11;
        k->st[2] = 0;
        k->st[3] = 255.0f;
    } else {
        func_0010a8e0(k->st);
    }
    f32 c = 2048.0f;
    s32 r = kn__getProjection(1);
    k->a[0] = c;
    k->a[1] = c;
    k->a[2] = 4000000.0f;
    k->a[3] = p->f20;
    k->b[0] = 1.0f;
    k->b[1] = 1.0f;
    k->b[2] = func_001070a8(r);
    k->b[3] = c;
    return k;
}
}  // namespace n00108730

// 00108930 (from src/anon/batch_w27.cpp)
namespace n00108930 {
// 00102c90: static init of the field mode object, moved to src/common/unit_00102a70.cpp

struct Entry108930 { u32 mask; u32 data; };
void* func_00108930(u8* p, s32 bit) asm("func_00108930");
void* func_00108930(u8* p, s32 bit) {  // test_bit_of_field44
    Entry108930* e = *(Entry108930**)(p + 44);
    if (e != 0 && bit >= 0 && bit < 32) {
        u32 m = 1 << bit;
        for (Entry108930* q = e; q->mask != 0; q++) {
            if (q->mask & m) return &q->data;
        }
    }
    return p + 4;
}
}  // namespace n00108930

namespace n00108988 {
void func_00108988(void) asm("func_00108988");
void func_00108988(void) {}  // never written before
}  // namespace n00108988

// 00108990 (from src/anon/misc_1.cpp)
namespace n00108990 {
void func_00108990(void* self) asm("_Z13func_00108990Pv");
void func_00108990(void* self) {}
}  // namespace n00108990

// 00108998 (from src/anon/auto80_199_queue.cpp)
namespace n00108998 {
void func_001342c8(u32, u32, u32) asm("func_001342c8");
extern u8 D_003b0000 asm("D_003b0000");
void func_00108998(u8* a0) asm("func_00108998");
void func_00108998(u8* a0) {
    u8* s1 = a0;
    u8* s0 = (u8*)((s32)&D_003b0000 - 29264);

    func_001342c8((u32)s0, 14, 0x13000000);

    *(u64*)(s1 + 0) = *(u64*)(s0 + 32);
    *(u64*)(s1 + 8) = *(u64*)(s0 + 48);
    *(u64*)(s1 + 16) = *(u64*)(s0 + 144);
    *(u64*)(s1 + 24) = *(u64*)(s0 + 160);
    *(u64*)(s1 + 32) = *(u64*)(s0 + 192);
    *(u64*)(s1 + 40) = *(u64*)(s0 + 208);
    s1[48] = 0;
}
}  // namespace n00108998

// 00108a10 (from src/anon/auto80_199_queue.cpp)
namespace n00108a10 {
void func_001342c8(u32, u32, u32) asm("func_001342c8");
extern u8 D_003b0000 asm("D_003b0000");
void func_00108a10(u8* a0) asm("func_00108a10");
void func_00108a10(u8* a0) {
    u8* s1 = a0;
    u8* s0 = (u8*)((s32)&D_003b0000 - 29488);

    func_001342c8((u32)s0, 14, 0x13000000);

    *(u64*)(s1 + 0) = *(u64*)(s0 + 32);
    *(u64*)(s1 + 8) = *(u64*)(s0 + 48);
    *(u64*)(s1 + 16) = *(u64*)(s0 + 144);
    *(u64*)(s1 + 24) = *(u64*)(s0 + 160);
    *(u64*)(s1 + 32) = *(u64*)(s0 + 192);
    *(u64*)(s1 + 40) = *(u64*)(s0 + 208);
    s1[48] = 0;
}
}  // namespace n00108a10

namespace n00108a88 {
struct S { u64 v[6]; u8 f; };
void func_00108a88(S* o, u32 m, u64 a, u64 b, u64 c, u64 d, u64 e, u64 f) asm("func_00108a88");
void func_00108a88(S* o, u32 m, u64 a, u64 b, u64 c, u64 d, u64 e, u64 f) {  // never written before
    if (m & 1) o->v[0] = a;
    if (m & 2) o->v[1] = b;
    if (m & 4) o->v[2] = c;
    if (m & 8) o->v[3] = d;
    if (m & 0x10) o->v[4] = e;
    if (m & 0x20) o->v[5] = f;
    o->f = 0;
}
}  // namespace n00108a88

// 00108ae0 (from src/anon/auto200_999_queue.cpp)
namespace n00108ae0 {
void func_00109008(void) asm("func_00109008");
void func_00134408(void) asm("func_00134408");
void func_00134428(u32, u64) asm("func_00134428");
void func_00134450(u32) asm("func_00134450");
// 00103a40: MENU::finalize, moved to src/common/unit_001031b0.cpp

// 00104910: moved to src/common/area.cpp

// 00105a20: moved to src/common/unit_00105a10.cpp

void kn__VU1DrawContext__setPacketForce(u64* a0, u32 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6, u64 a7) asm("kn__VU1DrawContext__setPacketForce");
void kn__VU1DrawContext__setPacketForce(u64* a0, u32 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6, u64 a7) {
    func_00109008();
    func_00134408();

    if (((a1 & 1u) & 0xffu) != 0) {
        func_00134428(76, a2);
        a0[0] = a2;
    }

    if ((a1 & 2u) != 0) {
        func_00134428(78, a3);
        a0[1] = a3;
    }

    if ((a1 & 4u) != 0) {
        func_00134428(71, a4);
        a0[2] = a4;
    }

    if ((a1 & 8u) != 0) {
        func_00134428(66, a5);
        a0[3] = a5;
    }

    if ((a1 & 0x10u) != 0) {
        func_00134428(61, a6);
        a0[4] = a6;
    }

    if ((a1 & 0x20u) != 0) {
        func_00134428(1, a7);
        a0[5] = a7;
    }

    func_00134450(1);
    *(u8*)((u8*)a0 + 48) = 0;
}
}  // namespace n00108ae0

// 00108c00 (from src/anon/auto200_999_queue.cpp)
namespace n00108c00 {
void func_00109008(void) asm("func_00109008");
void func_00134408(void) asm("func_00134408");
void func_00134428(u32, u64) asm("func_00134428");
void func_00134450(u32) asm("func_00134450");
void kn__VU1DrawContext__setPacket(u64* a0, u32 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6, u64 a7) asm("kn__VU1DrawContext__setPacket");
void kn__VU1DrawContext__setPacket(u64* a0, u32 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6, u64 a7) {
    func_00109008();
    func_00134408();

    if (((a1 & 1u) & 0xffu) != 0) {
        if (a2 != a0[0]) {
            func_00134428(76, a2);
            a0[0] = a2;
        }
    }

    if ((a1 & 2u) != 0) {
        if (a3 != a0[1]) {
            func_00134428(78, a3);
            a0[1] = a3;
        }
    }

    if ((a1 & 4u) != 0) {
        if (a4 != a0[2]) {
            func_00134428(71, a4);
            a0[2] = a4;
        }
    }

    if ((a1 & 8u) != 0) {
        if (a5 != a0[3]) {
            func_00134428(66, a5);
            a0[3] = a5;
        }
    }

    if ((a1 & 0x10u) != 0) {
        if (a6 != a0[4]) {
            func_00134428(61, a6);
            a0[4] = a6;
        }
    }

    if ((a1 & 0x20u) != 0) {
        if (a7 != a0[5]) {
            func_00134428(1, a7);
            a0[5] = a7;
        }
    }

    func_00134450(1);
    *(u8*)((u8*)a0 + 48) = 0;
}
}  // namespace n00108c00

// 00108d68 (from src/anon/auto80_199_queue.cpp)
namespace n00108d68 {
void func_00134408(void*) asm("func_00134408");
void func_00134428(u32, u64) asm("func_00134428");
u64 func_00108d68(u8* a0, u64 a1) asm("func_00108d68");
u64 func_00108d68(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 0);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 0) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(76, s1);
    }

    return s2;
}
}  // namespace n00108d68

// 00108dd8 (from src/anon/auto80_199_queue.cpp)
namespace n00108dd8 {
void func_00134408(void*) asm("func_00134408");
void func_00134428(u32, u64) asm("func_00134428");
u64 func_00108dd8(u8* a0, u64 a1) asm("func_00108dd8");
u64 func_00108dd8(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 8);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 8) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(78, s1);
    }

    return s2;
}
}  // namespace n00108dd8

// 00108e48 (from src/anon/auto80_199_queue.cpp)
namespace n00108e48 {
void func_00134408(void*) asm("func_00134408");
void func_00134428(u32, u64) asm("func_00134428");
u64 func_00108e48(u8* a0, u64 a1) asm("func_00108e48");
u64 func_00108e48(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 16);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 16) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(71, s1);
    }

    return s2;
}
}  // namespace n00108e48

// 00108eb8 (from src/anon/auto80_199_queue.cpp)
namespace n00108eb8 {
void func_00134408(void*) asm("func_00134408");
void func_00134428(u32, u64) asm("func_00134428");
u64 func_00108eb8(u8* a0, u64 a1) asm("func_00108eb8");
u64 func_00108eb8(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 24);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 24) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(66, s1);
    }

    return s2;
}
}  // namespace n00108eb8

// 00108f28 (from src/anon/auto80_199_queue.cpp)
namespace n00108f28 {
void func_00134408(void*) asm("func_00134408");
void func_00134428(u32, u64) asm("func_00134428");
u64 func_00108f28(u8* a0, u64 a1) asm("func_00108f28");
u64 func_00108f28(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 32);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 32) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(61, s1);
    }

    return s2;
}
}  // namespace n00108f28

// 00108f98 (from src/anon/auto80_199_queue.cpp)
namespace n00108f98 {
void func_00134408(void*) asm("func_00134408");
void func_00134428(u32, u64) asm("func_00134428");
u64 func_00108f98(u8* a0, u64 a1) asm("func_00108f98");
u64 func_00108f98(u8* a0, u64 a1) {
    u8* s0 = a0;
    u64 s2 = *(u64*)(a0 + 40);
    u64 s1 = a1;

    if (s1 != s2) {
        *(u64*)(s0 + 40) = s1;
        if (s0[48] == 0) {
            func_00134408(s0);
            s0[48] = 1;
        }
        func_00134428(1, s1);
    }

    return s2;
}
}  // namespace n00108f98

// 00109008 (from src/anon/tiny_auto80_queue.cpp)
namespace n00109008 {
extern "C" u32 func_00134450(...) asm("func_00134450");
void func_00109008(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00109008");
void func_00109008(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = (u32)(*(u8*)((u32)r16 + (s32)(48)));
    r4 = (u32)((s32)0u + (1));
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00134450)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u8*)((u32)r16 + (s32)(48)) = (u8)0u;
    }
}
}  // namespace n00109008

// 00109040 (from src/anon/tiny.cpp)
namespace n00109040 {
u64 func_00109040(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00109040");
u64 func_00109040(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u64*)((u32)a0 + (0));
}
}  // namespace n00109040

// 00109048 (from src/anon/tiny.cpp)
namespace n00109048 {
u64 func_00109048(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00109048");
u64 func_00109048(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u64*)((u32)a0 + (8));
}
}  // namespace n00109048

// 00109050 (from src/anon/tiny.cpp)
namespace n00109050 {
u64 func_00109050(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00109050");
u64 func_00109050(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_field16_64
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u64*)((u32)a0 + (16));
}
}  // namespace n00109050

// 00109058 (from src/anon/tiny.cpp)
namespace n00109058 {
u64 func_00109058(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00109058");
u64 func_00109058(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u64*)((u32)a0 + (24));
}
}  // namespace n00109058

// 00109060 (from src/anon/tiny.cpp)
namespace n00109060 {
u64 func_00109060(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00109060");
u64 func_00109060(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u64*)((u32)a0 + (32));
}
}  // namespace n00109060

// 00109068 (from src/anon/tiny.cpp)
namespace n00109068 {
u64 func_00109068(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00109068");
u64 func_00109068(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u64*)((u32)a0 + (40));
}
}  // namespace n00109068

// 00109070 (from src/anon/batch_w87.cpp)
namespace n00109070 {
// ---- 0x109070: reset of two small tables and two record arrays ----
struct Rec88 { u32 a; u32 b; u8 pad[80]; };
struct Rec288 { u32 a; u32 b; u32 c; u8 pad[276]; };
union P88 { Rec88* p; u32 u; u16 h; };
union P288 { Rec288* p; u32 u; u16 h; };
union I32 { s32 v; u32 u; u16 h; };
extern u32 D_0033cc78[5] asm("D_0033cc78");
extern u32 D_0033cc90[5] asm("D_0033cc90");
extern I32 D_0033cc68 asm("D_0033cc68");
extern P88 D_0033cc6c asm("D_0033cc6c");
extern P288 D_0033cc70 asm("D_0033cc70");
extern I32 D_0033cc60 asm("D_0033cc60");
extern u8 D_0033cca8 asm("D_0033cca8");
extern void* D_00340ea8 asm("D_00340ea8");
extern u32 D_0033cca4 asm("D_0033cca4");
void func_00109070(void) asm("func_00109070");
void func_00109070(void) {
    s32 i;
    for (i = 0; i < 5; i++) D_0033cc78[i] = D_0033cc90[i] = 0;
    for (i = 0; i < D_0033cc68.v; i++) {
        D_0033cc6c.p[i].a = 0;
        D_0033cc6c.p[i].b = D_0033cc60.u;
        D_0033cc70.p[i].b = 0;
        D_0033cc70.p[i].a = 0;
        D_0033cc70.p[i].c = 0;
    }
    D_00340ea8 = &D_0033cca8;
    D_0033cca4 = 0;
}
}  // namespace n00109070

// 00109140 (from src/anon/batch_w59.cpp)
namespace n00109140 {
void* create_task(void* self, int a, int b, void* fn) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
void func_00133de8(void) asm("func_00133de8");
void func_00109330(void) asm("func_00109330");
void func_00109340(void) asm("func_00109340");
void func_0010a7d8(int, int, int) asm("func_0010a7d8");
void func_0010a828(f32, f32) asm("func_0010a828");
void func_0010a8a8(f32, f32) asm("func_0010a8a8");
extern u64 D_003a8e10 asm("D_003a8e10");
extern u8 D_00340eb0 asm("D_00340eb0");
void func_00109140(void) asm("func_00109140");
void func_00109140(void) {
    func_00133de8();
    func_00109330();  // set_global_3756_return
    func_00109340();  // to_109450_zero
    D_003a8e10 = 0x4000000001300000ULL;
    D_00340eb0 = 1;
    func_0010a7d8(128, 128, 128);  // store_triple_bytes
    func_0010a828(5000.0f, 1000000.0f);
    func_0010a8a8(0.0f, 255.0f);  // store_global_float_pair
}
}  // namespace n00109140

// 001091c8 (from src/anon/batch_wcx2.cpp)
namespace n001091c8 {
// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
// ---- 001091c8
struct AlVt_001091c8 { void* (*alloc)(void*, u32, void*); };
struct Al_001091c8 { AlVt_001091c8* vt; };
union UG_001091c8 { s32 i; void* p; };
extern UG_001091c8 D_0033cc68 asm("D_0033cc68");
extern UG_001091c8 D_0033cc64 asm("D_0033cc64");
extern UG_001091c8 D_0033cc6c asm("D_0033cc6c");
extern UG_001091c8 D_0033cc70 asm("D_0033cc70");
void func_00133cf0(void*, u32) asm("func_00133cf0");
void func_00109070() asm("func_00109070");
void func_001091c8(Al_001091c8* o, s32 n, u32 sz) asm("func_001091c8");
void func_001091c8(Al_001091c8* o, s32 n, u32 sz) {
    D_0033cc68.i = n;
    void* m = o->vt->alloc(o, sz, __builtin_return_address(0));
    D_0033cc64.p = m;
    func_00133cf0(m, sz);
    D_0033cc6c.p = o->vt->alloc(o, D_0033cc68.i * 88, __builtin_return_address(0));
    D_0033cc70.p = o->vt->alloc(o, D_0033cc68.i * 288, __builtin_return_address(0));
    func_00109070();
}
}  // namespace n001091c8

// 00109280 (from src/anon/auto80_199_queue.cpp)
namespace n00109280 {
u32 func_00133d18(...) asm("func_00133d18");
extern u32 D_0033cc64 asm("D_0033cc64");
extern u32 D_0033cc6c asm("D_0033cc6c");
extern u32 D_0033cc70 asm("D_0033cc70");
extern u32 D_0033cc68 asm("D_0033cc68");
extern u32 D_00340ea8 asm("D_00340ea8");
u32 fn(...) asm("fn");
void func_00109280(void* a0) asm("func_00109280");
void func_00109280(void* a0) {
    void* s0 = a0;
    func_00133d18(s0);

    u32 v = D_0033cc64;
    if (v != 0) {
        u32 vtbl = *(u32*)s0;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(void*, u32))fn)(s0, v);
        D_0033cc64 = 0;
    }

    v = D_0033cc6c;
    if (v != 0) {
        u32 vtbl = *(u32*)s0;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(void*, u32))fn)(s0, v);
        D_0033cc6c = 0;
    }

    v = D_0033cc70;
    if (v != 0) {
        u32 vtbl = *(u32*)s0;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(void*, u32))fn)(s0, v);
        D_0033cc70 = 0;
    }

    D_0033cc68 = 0;
    D_00340ea8 = 0;
}
}  // namespace n00109280

// 00109330 (from src/anon/tiny.cpp)
namespace n00109330 {
extern u32 D_00340eac asm("D_00340eac");
void func_00109330(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00109330");
void func_00109330(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_global_3756_return
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    D_00340eac = (u32)((s32)-1);
}
}  // namespace n00109330

// 00109340 (from src/anon/tiny_wrappers_more.cpp)
namespace n00109340 {
u32 func_00109450(u32, u32, u32, u32) asm("func_00109450");
u32 func_00109340(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00109340");
u32 func_00109340(u32 a0, u32 a1, u32 a2, u32 a3) {  // to_109450_zero
    return func_00109450(0x00000000u, 0x00000200u, 0x00000000u, a3);
}
}  // namespace n00109340

// 00109360 (from src/anon/batch_w42.cpp)
namespace n00109360 {
// 00105af8: moved to src/common/region.cpp

// 00109360: switch to entry `id`, issuing its command pair if both are set
struct Pair109 { u32 a; u32 b; };
extern s32 D_00340eac asm("D_00340eac");
extern Pair109 D_003a8ea0[] asm("D_003a8ea0");
void func_00133c78(u32, u32, u32, u32, u32) asm("func_00133c78");
void func_00109360(u32 a0, s32 id) asm("func_00109360");
void func_00109360(u32 a0, s32 id)
{
    if (D_00340eac != id) {
        Pair109* e = &D_003a8ea0[id];
        if (e->a && e->b) func_00133c78(a0, e->a, e->b, 0, 0);
        D_00340eac = id;
    }
}
}  // namespace n00109360

// 001093c8 (from src/anon/auto80_199_queue.cpp)
namespace n001093c8 {
u32 func_00133bb8(u32, u32, u32, u32) asm("func_00133bb8");
u32 func_001093c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) asm("func_001093c8");
u32 func_001093c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    u32 s3 = a1;
    u32 s0 = a3;
    u32 s1 = a4;
    u32 s2 = a5;

    u32 n = a2 + 1;
    u32 cmd = (n << 16) | 0x6c004009;
    u32 v0 = func_00133bb8(a0, n, 0x01000101, cmd);  // forward_sub24_to_133848

    *(u32*)(v0 + 0) = s3;
    *(u32*)(v0 + 4) = s0;
    *(u32*)(v0 + 8) = s1;
    *(u32*)(v0 + 12) = s2;
    return v0 + 16;
}
}  // namespace n001093c8

// 00109450 (from src/anon/batch_w52.cpp)
namespace n00109450 {
u32 wtarget_00109450(s32, s32, u32, u32) asm("_Z16wtarget_00109450jjjj");
extern u32 D_003a84d0[512] asm("D_003a84d0");
// Fills a run of the 512-entry table with val (val 0 clears it all); 1 if nothing changed.
u32 wtarget_00109450(s32 start, s32 count, u32 val, u32) asm("_Z16wtarget_00109450jjjj");
u32 wtarget_00109450(s32 start, s32 count, u32 val, u32) {
    u32 r = 1;
    if (val == 0) {
        for (start = 0; start < 512; start++) D_003a84d0[start] = 0;
    } else {
        s32 end = start + count;
        for (; start < end && start < 512; start++) {
            if (D_003a84d0[start] != val) {
                D_003a84d0[start] = val;
                r = 0;
            }
        }
    }
    return r;
}
}  // namespace n00109450

// 0036a194: a .rodata word (144) no code loads; it sits before the jump table of 0x1094e0.
extern "C" const s32 D_0036a194 = 144;

// 001094e0 (from src/anon/batch_w3755.cpp)
namespace n001094e0 {
struct BBuf_w { u64 SBP:14, :2, SBW:6, :2, SPSM:6, :2, DBP:14, :2, DBW:6, :2, DPSM:6, :2; };
struct TReg_w { u64 RRW:12, :20, RRH:12, :20; };
struct DTag_w { u16 qwc; u8 mark; u8 id; u32 addr; u32 pad[2]; };
struct Pkt_w { u8 pad[0x20]; BBuf_w bb; u64 p1; u8 pad2[0x10]; TReg_w tr; u64 p2; u8 pad3[0x30]; DTag_w tag; };
struct NoTail_w { ~NoTail_w() {} };
void func_00109450(s32, s32, s32) asm("func_00109450");
void func_001094e0(Pkt_w* p, s32 arg) asm("func_001094e0");
void func_001094e0(Pkt_w* p, s32 arg)
{
    s32 lo = 0x4000;
    s32 hi = 0;
    for (;; p++) {
        s32 n = 0;
        s32 dbp = p->bb.DBP;
        s32 rrw = p->tr.RRW;
        s32 rrh = p->tr.RRH;
        s32 psm = p->bb.DPSM;
        if (dbp < lo) lo = dbp;
        switch (psm) {
        case 0: case 1: case 0x1b: case 0x24: case 0x2c: case 0x30: case 0x31:
            n = ((rrw + 63) >> 6) * ((rrh + 31) >> 5);
            break;
        case 0x13:
            n = ((rrw + 127) >> 7) * ((rrh + 63) >> 6);
            break;
        case 0x14:
            n = ((rrw + 127) >> 7) * ((rrh + 127) >> 7);
            break;
        case 2: case 0xa: case 0x32: case 0x3a:
            n = ((rrw + 63) >> 6) * ((rrh + 63) >> 6);
            break;
        }
        DTag_w* t = &p->tag;
        void* next;
        s32 end = dbp + n * 32;
        if (hi < end) hi = end;
        switch (t->id & 0x70) {
        case 0x10: next = (u8*)t + t->qwc * 16 + 16; break;
        case 0x20: next = (void*)t->addr; break;
        case 0x30: case 0x40: next = t + 1; break;
        case 0x50: next = (void*)t->addr; break;
        default: next = 0; break;
        }
        if (next == 0) break;
    }
    NoTail_w nt;
    s32 start = lo / 32;
    func_00109450(start, (hi - start * 32 + 31) / 32, arg);
}
}  // namespace n001094e0

// 00109670 (from src/anon/tiny_wrappers_more.cpp)
namespace n00109670 {
u32 func_00109450(u32, u32, u32, u32) asm("func_00109450");
u32 func_00109670(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00109670");
u32 func_00109670(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00109450(0x00000140u, 0x000000c0u, 0x00000001u, a3);
}
}  // namespace n00109670

// 00109690 (from src/anon/batch_w41.cpp)
namespace n00109690 {
typedef unsigned int u128 __attribute__((mode(TI)));
u64* func_00133ba0(u32, u32, u32) asm("func_00133ba0");
// 00105fc8: moved to src/common/world.cpp

// GIF tag (NLOOP=1, EOP, NREG=1, REGS=A+D) followed by one A+D pair (TEXFLUSH).
struct W41GifTag { u64 nloop:15; u64 eop:1; u64 pad:30; u64 pre:1; u64 prim:11; u64 flg:2; u64 nreg:4; u64 r0:4; u64 rr:60; u64 data; u64 addr; };
void func_00109690(u32 a) asm("func_00109690");
void func_00109690(u32 a) {
    W41GifTag* t = (W41GifTag*)func_00133ba0(a, 2, 0x13000000);  // forward_sub24_to_1337f0
    *(u128*)t = 0;
    t->nloop = 1;
    t->eop = 1;
    t->nreg = 1;
    t->r0 = 0xe;
    t->addr = 63;
    t->data = 0;
}
}  // namespace n00109690

// 00109708 (was whole asm in src/anon/batch_w3877.s)
namespace n00109708 {
typedef unsigned int u128 __attribute__((mode(TI)));
u64* func_00133ba0(u32, u32, u32) asm("func_00133ba0");

// GIF tag (NLOOP=1, EOP, NREG=1, REGS=A+D) followed by one A+D pair (TEX2_1). The 64-bit register value
// is a literal: gcc keeps it in the constant pool (.rodata 0x36a288), it was never a global.
struct GifTagAD { u64 nloop:15; u64 eop:1; u64 pad:30; u64 pre:1; u64 prim:11; u64 flg:2; u64 nreg:4; u64 r0:4; u64 rr:60; u64 data; u64 addr; };
void func_00109708(u32 a) asm("func_00109708");
void func_00109708(u32 a) {
    GifTagAD* t = (GifTagAD*)func_00133ba0(a, 2, 0x13000000);
    *(u128*)t = 0;
    t->nloop = 1;
    t->eop = 1;
    t->nreg = 1;
    t->r0 = 0xe;
    t->addr = 0x16;
    t->data = 0x4000000001300000;
}
}  // namespace n00109708
