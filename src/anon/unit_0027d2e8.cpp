// Linked unit 0x0027d2e8-0x0027dee8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/cmenu_ability.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_tutorial.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/obj2d.hpp"
#include "../tozawa/cmenu_config.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/simple_stat.hpp"

// 0027d2e8 (was src/anon/auto80_199_queue.cpp)
namespace n0027d2e8 {
/*TARGET 0027d2e8*/
void func_0027d2e8(void) asm("_Z13func_0027d2e8v");
void func_0027d2e8(void) {
    u32 s0 = func_00257770();
    u32 t = func_00287bc0();
    if (t == 36) {
        func_0028dac8(s0, 235);
        if (func_0028be58(D_0035f04c) != 0) {
            func_0028bdb8(D_0035f04c);
        }
    }
}
}  // namespace n0027d2e8

// 0027d350 (was src/anon/auto80_199_queue.cpp)
namespace n0027d350 {
/*TARGET 0027d350*/
void func_0027d350(void) asm("_Z13func_0027d350v");
void func_0027d350(void) {
    func_002579e0();

    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028abe0(D_0035f01c);
    }

    if (func_0028be58(D_0035f04c) != 0) {
        func_0028be18(D_0035f04c);
    }
}
}  // namespace n0027d350

// 0027d3b0 (was src/anon/auto80_199_queue.cpp)
namespace n0027d3b0 {
/*TARGET 0027d3b0*/
u32 func_0027d3b0(void) asm("_Z13func_0027d3b0v");
u32 func_0027d3b0(void) {
    u32 v0 = func_00257780();
    if (v0 == 0) {
        u32 p = D_0035f01c;
        if (p != 0) {
            v0 = func_0028acc8(p);
            v0 = (v0 != 0);
        }
        if (v0 == 0) {
            v0 = func_0028be58(D_0035f04c);
            v0 = (v0 != 0);
        }
    }
    return v0;
}
}  // namespace n0027d3b0

// 0027d408 (was src/tozawa/cmenu_top.cpp)
namespace Tz { // method 0027d408
// record884_type_index
extern "C" u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 0027d408*/
u32 CmTop_isExistListAll() asm("_Z13func_0027d408v");
u32 CmTop_isExistListAll() {
    u32 r16 = CmTop::GetTopBase();
    u32 r2 = func_00139d78(r16);
    u32 r4 = 0u;
    if (r2 != 0u) {
        u32 r15 = *(u32*)((u32)r16 + (s32)(388));
        r15 = (u32)(r15 ^ 0x00eau);
        r4 = ((u32)r15 < 0x00000001u);
    }
    return r4;
}
}  // Tz

// 0027d450 (was src/anon/batch_w1583_g.cpp)
namespace n0027d450 {
s32 func_00257770(void) asm("func_00257770");
s32 func_00139d78(s32) asm("func_00139d78");
void func_0028da70(s32, s32) asm("func_0028da70");
/*TARGET 0027d450*/
void func_0027d450(void) asm("func_0027d450");
void func_0027d450(void) {
    s32 p = func_00257770();
    func_00139d78(p);
    func_0028da70(p, 0xEA);
}
}  // namespace n0027d450

// 0027d488 (was src/tozawa/cmenu_config.cpp)
namespace Tz { // method 0027d488
extern s8* D_0035f234 asm("D_0035f234");
u32 func_00257770(...) asm("func_00257770");
/*TARGET 0027d488*/
u32 CmConfig_GetSelSeq(s32 a0, s32 a1) asm("_Z13func_0027d4881a1b");
u32 CmConfig_GetSelSeq(s32 a0, s32 a1) {
    u32 s0 = (u32)a1;
    u32 s1 = (u32)a0;
    u32 base = func_00257770();
    u32 t = s1 + s0;
    s1 <<= 2;
    if (t != 9) {
        s1 = (u32)((s32)s1 + (s32)D_0035f234[t]);
    }
    return base + (s1 * 436) + 13840;
}
}  // Tz

// 0027d4f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0027d4f0 {
extern u8  D_00373ef8 asm("D_00373ef8");
extern u8  D_00373f00 asm("D_00373f00");
extern u8  D_00373f08 asm("D_00373f08");
extern u8  D_00373f10 asm("D_00373f10");
/*TARGET 0027d4f0*/
u32 func_0027d4f0(u32 a0) asm("_Z13func_0027d4f0j");
u32 func_0027d4f0(u32 a0) {
    s16 v = *(s16*)((u32)&D_00373f10 + a0 * 20u);
    if (v == 1) {
        return (u32)&D_00373ef8;
    }
    if (v == 2) {
        return (u32)&D_00373f00;
    }
    return (u32)&D_00373f08;
}
}  // namespace n0027d4f0

// 0027d540 (was src/anon/auto80_199_queue.cpp)
namespace n0027d540 {
/*TARGET 0027d540*/
void func_0027d540(void) asm("_Z13func_0027d540v");
void func_0027d540(void) {
    u32 i = func_0028b040(D_0035f01c);
    s32 t = (s32)(i * 10u);
    s32 n = (s32)D_0035f234[i];
    t += n;
    u32 p = (u32)&D_00373f10 + ((u32)t << 1);
    func_00263a58(*(u16*)(p + 12), 1);
}
}  // namespace n0027d540

// 0027d598 (was src/anon/batch_w12.cpp)
namespace n0027d598 {
void func_0027d008(void*) asm("func_0027d008");
void func_0027d540(void) asm("func_0027d540");
void func_0027d5d8(void) asm("func_0027d5d8");
void func_0027d810(s32) asm("func_0027d810");
s32 JmReport_GetData(s16*) asm("_ZN2Tz8JmReport7GetDataEj");
/*TARGET 0027d598*/
void func_0027d598(void* p) asm("func_0027d598");
void func_0027d598(void* p) {
    func_0027d008(p);
    func_0027d540();
    func_0027d5d8();
    func_0027d810(JmReport_GetData((s16*)p));
}
}  // namespace n0027d598

// 0027d5d8 (was src/anon/batch_w320.cpp)
namespace n0027d5d8 {
struct E1e21ef0 { s32 f0; s16 h4; };
extern u32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u8* D_0035f050 asm("D_0035f050");
extern E1e21ef0* D_01e21ef0 asm("D_01e21ef0");
u8* func_00257770(void) asm("func_00257770");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00139510(u8*) asm("func_00139510");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_0028b038(u32) asm("func_0028b038");
E1e21ef0* func_0027d4f0(s32) asm("func_0027d4f0");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
s32 func_0027d488(s32, s32) asm("func_0027d488");
void func_0028dcc0(u8*, s32) asm("func_0028dcc0");
s32 func_00289358(u32) asm("func_00289358");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_001396b0(u8*) asm("func_001396b0");
void func_0031a260(u8*, s32) asm("func_0031a260");
u8* func_002891d0(u32) asm("func_002891d0");
void func_0028d660(u8*, s32) asm("func_0028d660");
/*TARGET 0027d5d8*/
// record_set_value_refresh
void func_0027d5d8(void) asm("func_0027d5d8");
// record_set_value_refresh
void func_0027d5d8(void)
{
    u8* base = func_00257770();
    s32 mode = func_00287cd0();
    if (!func_0028acc8(D_0035f01c)) return;
    if (mode == 1) {
        u8* w = base + 816;
        s32 a = func_002891e8(D_0035f01c);
        s32 b = func_0028b038(D_0035f01c);
        D_01e21ef0 = func_0027d4f0(a + b);
        if (!func_00139d78(w)) {
            func_0028d8c0(w, D_0035f3d4 + 1, D_0035ef68, D_0035ef64, D_0035f03c, D_01e21ef0->h4, -1, 0);
            func_0028dcc0(w, func_0027d488(a, b));
            return;
        }
        s32 cur = *(s32*)(w + 396);
        if (cur == func_0027d488(a, b) && !func_00289358(D_0035f01c)) return;
        func_00138c10(w, D_01e21ef0->h4);
        *(s32*)(w + 396) = func_0027d488(a, b);
        func_001396b0(w);
        if (*(s32*)(w + 396)) {
            *(s32*)(w + 400) = 0;
            func_001396b0(w);
            if (*(s32*)(w + 400)) func_0031a260(w, 0);
        }
        if (!func_00139d78(D_0035f050)) return;
        s32 v = *(s32*)(D_0035f050 + 396);
        if (v == *(s32*)(func_002891d0(D_0035f01c) + 396)) return;
        func_0028d660(D_0035f050, *(s32*)(func_002891d0(D_0035f01c) + 396));  // record_set_value_refresh
    } else {
        u8* w = base + 816;
        if (func_00139d78(w)) func_00139510(w);
    }
}
}  // namespace n0027d5d8

// 0027d810 (was src/anon/auto80_199_queue.cpp)
namespace n0027d810 {
/*TARGET 0027d810*/
void func_0027d810(u32 a0) asm("_Z13func_0027d810j");
void func_0027d810(u32 a0) {
    u32 v = func_0028af88(D_0035f01c);
    if (a0 == 9) {
        v &= 0xfff3ffffu;
    } else {
        v |= 0x000c0000u;
    }
    func_0028af18(D_0035f01c, v);
}
}  // namespace n0027d810

// 0027d868 (was src/anon/batch_w278.cpp)
namespace n0027d868 {
struct ITbl278 { s16 max; u8 pad[18]; };
extern s32 D_0035f01c asm("D_0035f01c");
extern s8* D_0035f234 asm("D_0035f234");
extern ITbl278 D_00373f10[] asm("D_00373f10");
s32 func_0028b040(s32) asm("func_0028b040");
void func_0023d1d0() asm("func_0023d1d0");
// set_global_word1
void func_0023d1e0() asm("func_0023d1e0");
// zero_global_d
void func_002b6bc4(s32) asm("func_002b6bc4");
/*TARGET 0027d868*/
void func_0027d868(u8 dir) asm("func_0027d868");
void func_0027d868(u8 dir) {
    s32 k = func_0028b040(D_0035f01c);
    s32 v = D_0035f234[k];
    if (dir) {
        v--;
        if (v < 0) v = D_00373f10[k].max - 1;
    } else {
        v++;
        if (!(v < D_00373f10[k].max)) v = 0;
    }
    D_0035f234[k] = v;
    if (k == 6) {
        if (D_0035f234[6] == 0) func_0023d1d0();  // set_global_word1
        else func_0023d1e0();  // zero_global_d
    } else if (k == 7) {
        s8 m = D_0035f234[7];
        if (m == 2) v = 0;
        else v = (m == 1) ? 2 : 1;
        func_002b6bc4(v);
    }
    if (k == 0) {
        s8* p = D_0035f234;
        if (p[0] == 1 && p[1] == 1) p[1] = 0;
    } else if (k == 1) {
        s8* p = D_0035f234;
        if (p[0] == 1 && p[1] == 1) p[0] = 0;
    }
}
}  // namespace n0027d868

// 0027d9e8 (was unwritten gap)
namespace n0027d9e8 {
s32 func_0027d9e8(void) asm("func_0027d9e8");
s32 func_0027d9e8(void) { return 0; }
}  // namespace n0027d9e8

// 0027d9f0 (was src/anon/auto80_199_queue.cpp)
namespace n0027d9f0 {
void func_0027dab8(u32 a0) asm("_Z13func_0027dab8j");
/*TARGET 0027d9f0*/
void func_0027d9f0(void) asm("_Z13func_0027d9f0v");
void func_0027d9f0(void) {
    u32 root = *(u32*)&D_00347f80;
    u32 obj = *(u32*)(root + 20);
    u32 fn = *(u32*)(*(u32*)obj + 0);
    u32 s0 = ((u32 (*)(u32, u32, u32))fn)(obj, 832, 0);
    u32 v = func_00290610(s0);
    D_0035f238 = s0;
    v = func_00103eb0();
    func_00102818(*(u32*)(v + 4), 0, 2000, (u32)func_0027dab8, 4096);
    func_0014acd8();
}
}  // namespace n0027d9f0

// 0027da60 (was src/anon/auto80_199_queue.cpp)
namespace n0027da60 {
/*TARGET 0027da60*/
void func_0027da60(void) asm("_Z13func_0027da60v");
void func_0027da60(void) {
    func_0014ace8();

    u32 p = D_0035f238;
    if (p != 0) {
        u32 vt = *(u32*)p;
        u32 fn = *(u32*)(vt + 16);
        ((void (*)(u32))fn)(p);
        D_0035f238 = 0;
    }

    D_0035f23c = 0;
    D_0035f240 = 0;
}
}  // namespace n0027da60

// 0027dab8 (was src/anon/auto80_199_queue.cpp)
namespace n0027dab8 {
/*TARGET 0027dab8*/
void func_0027dab8(u32 a0) asm("_Z13func_0027dab8j");
void func_0027dab8(u32 a0) {
    func_00102448(a0, 1);
    func_0027db28();
    func_00242618(11, 1);
    while (true) {
        func_00236d60();  // clear_64_entries_24
        if (func_0027db58() != 0) {
            break;
        }
        func_0027dbd8();
        func_00102448(a0, 0);
    }
}
}  // namespace n0027dab8

// 0027db28 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n0027db28 {
u32 func_00290668(u32, u32, u32, u32) asm("_Z13func_00290668jjjj");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 0027db28*/
u32 func_0027db28(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0027db28jjjj");
u32 func_0027db28(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00290668(((u32)(*(u32*)((u32)((u32)&D_00360000) - 3528u))), ((u32)(*(u32*)((u32)((u32)&D_00360000) - 3520u))), ((u32)(*(u32*)((u32)((u32)&D_00360000) - 3524u))), 0x00000000u);
}
}  // namespace n0027db28

// 0027db58 (was src/anon/batch_w59.cpp)
namespace n0027db58 {
// 0x00263960: definition moved into src/anon/unit_002632d0.cpp

// --- 0027db58
u8* func_00167f18(u32) asm("func_00167f18");
u32 func_00287db0(void) asm("func_00287db0");
u32 func_00290740(u32) asm("func_00290740");
void func_001039f8(void) asm("func_001039f8");
void func_00242618(u32, u32) asm("func_00242618");
void func_00287da0(void) asm("func_00287da0");
extern u32 D_0035f238 asm("D_0035f238");
/*TARGET 0027db58*/
u32 func_0027db58(void) asm("func_0027db58");
u32 func_0027db58(void) {
    u8* o = func_00167f18(0);
    if (func_00287db0()) {
        if (func_00290740(D_0035f238)) return 0;
        func_001039f8();
        return 1;
    }
    if (*(u64*)(o + 8) & 0xc) {
        func_00242618(9, 1);
        func_00287da0();
    }
    return 0;
}
}  // namespace n0027db58

// 0027dbd8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0027dbd8 {
u32 func_00287db0(...) asm("func_00287db0");
u32 func_0028dac8(...) asm("func_0028dac8");
/*TARGET 0027dbd8*/
u32 func_0027dbd8(u32 a0, u32 a1) asm("_Z13func_0027dbd8jj");
u32 func_0027dbd8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r2 = ((u32(*)())func_00287db0)();
    r5 = (u32)((s32)0u + (1));
    if (r2 != 0u) {
        r15 = (u32)(0x0036u << 16);
        r4 = *(u32*)((u32)r15 + (s32)(-3528));
        r2 = ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
    }
    return r2;
}
}  // namespace n0027dbd8

// 0027dc08 (was src/anon/tiny_more2.cpp)
namespace n0027dc08 {
extern u32 D_0035f23c asm("D_0035f23c");
extern u32 D_0035f240 asm("D_0035f240");
/*TARGET 0027dc08*/
// 0x00258d40: definition moved into src/anon/unit_002588e8.cpp

void func_0027dc08(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0027dc08jjjj");
// 0x00258d40: definition moved into src/anon/unit_002588e8.cpp

void func_0027dc08(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_0035f240 = a0; D_0035f23c = a1; }
}  // namespace n0027dc08

// 0027dc20 (was src/anon/auto200_999.cpp)
namespace n0027dc20 {
extern u32 D_0035f23c asm("D_0035f23c");
extern u32 D_0035f240 asm("D_0035f240");
/*TARGET 0027dc20*/
void func_0027dc20(u32 *a0, u32 *a1) asm("_Z13func_0027dc20PjS_");
void func_0027dc20(u32 *a0, u32 *a1) {
    *a0 = D_0035f240;
    *a1 = D_0035f23c;
}
}  // namespace n0027dc20

// 0027dc40 (was src/anon/batch_w84.cpp)
namespace n0027dc40 {
typedef void (*VFn)(void*);
struct VObj { VFn* vt; };
// 0x0026eae8: definition moved into src/anon/unit_0026c450.cpp

// Creates the manager object and a 4-element array of 5116-byte entries.
struct Heap20 { u8 _0[20]; VObj* a; };
extern Heap20* D_00347f80 asm("D_00347f80");
extern void* D_00347e60[] asm("D_00347e60");
extern void* D_0035f244 asm("D_0035f244");
extern u8* D_0035f248 asm("D_0035f248");
extern u8 D_0035f24c asm("D_0035f24c");
extern u8 D_0035f24d asm("D_0035f24d");
extern u8 D_0035f24e asm("D_0035f24e");
void func_00239700(void*) asm("func_00239700");
u32 func_00103570(void) asm("func_00103570");
u8* func_001063f0(u32, u32) asm("func_001063f0");
void func_003237e0(void*) asm("func_003237e0");
typedef u8* (*AllocFn)(void*, u32, u32);
/*TARGET 0027dc40*/
void func_0027dc40(void) asm("func_0027dc40");
void func_0027dc40(void) {
    VObj* h = D_00347f80->a;
    u8* o = ((AllocFn*)h->vt)[0](h, 408, 0);
    *(u32*)(o + 12) = 0;
    *(void**)o = D_00347e60;
    func_00239700(o + 24);
    D_0035f244 = o;
    u8* m = func_001063f0(20468, func_00103570());
    *(u32*)m = 4;
    u8* arr = m + 4;
    u8* q = arr;
    for (s32 i = 3; i != -1; i--) {
        func_003237e0(q);
        q += 5116;
    }
    D_0035f248 = arr;
    D_0035f24c = 0xff;
    D_0035f24d = 0xff;
    D_0035f24e = 0xff;
}
}  // namespace n0027dc40

// 0027dd18 (was src/anon/batch_w1603.cpp)
namespace n0027dd18 {
extern u8 D_00347e60[] asm("D_00347e60");
void func_00239870(void*) asm("_ZN2YI8SEQUENCED1Ev");
u8 func_0031a840(void*) asm("func_0031a840");
void func_0031abd8(void*) asm("func_0031abd8");
struct Poly {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Poly();
};
struct X : Poly { u8 pad[432]; };
struct Y : Poly { u8 pad[404]; };
struct X0 {
    u8 pad[436];
    ~X0() { *(void**)this = D_00347e60; func_00239870(pad + 24); func_0031a840(this); }
};
struct Y0 {
    u8 pad[408];
    ~Y0() { func_0031abd8(this); }
};
struct Group {
    X0 m0;
    Y0 m436;
    Y a844[2];
    Y a1660[2];
    X a2476[3];
    X a3784[3];
    u8 tail[24];
};
extern Poly* D_0035f244 asm("D_0035f244");
extern Group* D_0035f248 asm("D_0035f248");
extern s8 D_0035f24c asm("D_0035f24c");
extern s8 D_0035f24d asm("D_0035f24d");
extern s8 D_0035f24e asm("D_0035f24e");
/*TARGET 0027dd18*/
void func_0027dd18(void) asm("func_0027dd18");
void func_0027dd18(void) {
    if (D_0035f244) { delete D_0035f244; D_0035f244 = 0; }
    if (D_0035f248) { delete[] D_0035f248; D_0035f248 = 0; }
    D_0035f24c = -1;
    D_0035f24d = -1;
    D_0035f24e = -1;
}
}  // namespace n0027dd18


// 0027dee8 (was whole asm src/anon/batch_w3904.s; O22 2026-11-26)
// Status panel builder: name, frame, then per row a label, a value text and (style 0 / 5) a bar and a gauge.
// The value colour and the gauge id are one variable (d); the MP label id and MP gauge id are variables (mp, g99), so
// the early if-conversion sees registers; the bar/gauge calls read the three resource handles through reference
// accessors (loop.c hoists them like retail). __builtin_expect on the label-text row test reproduces retail's block
// frequencies (s4/s5 global-alloc tie); no natural form found yet (ledger: experiments/O22_0027dee8.md).
namespace n0027dee8 {
struct W1714Spr {
    u8 pad0[0x18];
    u8 seq[0x180];
};
struct W1714Obj {
    u8 pad0[0x18];
    u8 seq[0x180];
    char* text;      // 0x198
    u8 pad19c[0xc];
    s32 size;        // 0x1a8
    u8 pad1ac[4];
    s32 mode;        // 0x1b0
};
struct W1714Panel {
    W1714Obj name;        // 0x000
    W1714Spr frame;       // 0x1b4
    W1714Spr bar[2];      // 0x34c
    W1714Spr gauge[2];    // 0x67c
    W1714Obj label[3];    // 0x9ac
    W1714Obj value[3];    // 0xec8
    char str[3][8];       // 0x13e4
};
struct W1714Pos { s16 x; s16 y; s16 z; };

s32 func_0027e920(void) asm("func_0027e920");
void func_0027eb10(void) asm("func_0027eb10");
s32 func_00281100(s32) asm("func_00281100");
char* func_00281140(s32, s32) asm("func_00281140");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
s32 func_0023aa58(void*) asm("func_0023aa58");
s32 func_0023aa78(void*) asm("func_0023aa78");
s32 func_0023aa98(void*) asm("func_0023aa98");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void func_00139620(void*) asm("func_00139620");
void func_001395f8(void*) asm("func_001395f8");
s32 func_00257140(s32) asm("func_00257140");
char* func_00192048(u32) asm("func_00192048");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035f010 asm("D_0035f010");
extern s32 D_0035f03c asm("D_0035f03c");
extern W1714Obj* D_0035f244 asm("D_0035f244");
extern W1714Panel* D_0035f248 asm("D_0035f248");
extern s8 D_0035f24c asm("D_0035f24c");
extern s8 D_0035f24d asm("D_0035f24d");
extern s8 D_0035f24e asm("D_0035f24e");
extern const s32 D_00374044 asm("D_00374044");
extern const s32 D_00374048 asm("D_00374048");
extern const W1714Pos D_00374050[] asm("D_00374050");
extern const s16 D_00374060[] asm("D_00374060");
extern const u16 D_00374070[] asm("D_00374070");

static inline s32& W1714R0() { return D_0035ef68; }
static inline s32& W1714R1() { return D_0035ef64; }
static inline s32& W1714R2() { return D_0035f03c; }
static inline void W1714SetText(W1714Obj* o, char* s) { o->text = s; }
static inline void W1714SetSize(W1714Obj* o, s32 v) { o->size = v; }
static inline void W1714SetMode(W1714Obj* o, s32 v) { o->mode = v; }
void func_0027dee8(s32 layout, s32 style, s32 type) asm("func_0027dee8");
void func_0027dee8(s32 layout, s32 style, s32 type) {
    s32 i;
    s32 count;
    s32 h;
    s32 w;
    s32 size;
    s32 px;
    s32 py;
    s32 lh;
    s32 n;
    s32 j;
    s32 x, y, t, c, d;
    s32 mp, g99;

    mp = 0xb9fe;
    g99 = 99;
    func_0027e920();
    D_0035f24c = layout;
    D_0035f24d = style;
    D_0035f24e = type;
    if (type == 4) {
        count = func_00281100(D_0035f010);
    } else {
        count = 1;
    }
    func_0028d8c0(D_0035f244, 0x753b, D_0035ef68, D_0035ef64, D_0035f03c,
                  D_00374050[D_0035f24c].x, D_00374050[D_0035f24c].z, 0);
    h = func_0023aa78(D_0035f244->seq);
    w = func_0023aa98(D_0035f244->seq);
    for (i = 0; i < count; i++) {
        func_0028d980(&D_0035f248[i], 0x753c, D_0035ef68, D_0035ef64, D_0035f03c,
                      (D_0035f24d != 5) ? D_00374044 : D_00374048, -1, -1, 0);
        if (D_0035f24c == 0) {
            y = 0;
            x = w * (count - i);
        } else {
            y = h * (i / 2);
            x = w * (i % 2);
        }
        func_00138c68(&D_0035f248[i], x, y);
        func_00139620(&D_0035f248[i]);
        func_0028dcc0(&D_0035f248[i], D_0035f244);
        if (type == 4) {
            t = i;
        } else {
            t = D_0035f24e;
        }
        W1714SetText(&D_0035f248[i].name, func_00281140(D_0035f010, t));
        W1714SetMode(&D_0035f248[i].name, 2);
        func_0028d8c0(&D_0035f248[i].frame, 0x753c, D_0035ef68, D_0035ef64, D_0035f03c,
                      D_00374060[D_0035f24d], -1, 0);
        func_00139620(&D_0035f248[i].frame);
        func_0028dcc0(&D_0035f248[i].frame, &D_0035f248[i]);
        px = func_0023aa18(D_0035f248[i].frame.seq);
        py = func_0023aa38(D_0035f248[i].frame.seq);
        size = func_0023aa58(D_0035f248[i].frame.seq);
        lh = func_0023aa78(D_0035f248[i].frame.seq);
        n = 3;
        if (D_0035f24d != 0) {
            n = 1;
        }
        for (j = 0; j < n; j++) {
            if (D_0035f24d == 0) {
                if (j == 0) {
                    c = d = 2;
                } else if (j == 1) {
                    c = d = 4;
                } else {
                    c = d = 6;
                }
            } else {
                c = 0;
                d = 2;
            }
            func_0028d980(&D_0035f248[i].label[j], 0x753c, D_0035ef68, D_0035ef64, D_0035f03c,
                          func_00257140(c), -1, -1, 0);
            func_00139620(&D_0035f248[i].label[j]);
            y = lh * j;
            func_00138c68(&D_0035f248[i].label[j], 0, y);
            W1714SetSize(&D_0035f248[i].label[j], size);
            func_001395f8(&D_0035f248[i].label[j]);
            func_0028dcc0(&D_0035f248[i].label[j], &D_0035f248[i].frame);
            if (D_0035f24d == 0) {
                if (__builtin_expect(j == 0, 0)) {
                    t = D_00374070[0];
                } else {
                    t = (j == 1) ? 0xb9fd : mp;
                }
            } else {
                t = D_00374070[D_0035f24d];
            }
            y += py;
            W1714SetText(&D_0035f248[i].label[j], func_00192048(t));
            func_0028d980(&D_0035f248[i].value[j], 0x753c, D_0035ef68, D_0035ef64, D_0035f03c,
                          func_00257140(d), -1, -1, 0);
            func_00139620(&D_0035f248[i].value[j]);
            func_00138c68(&D_0035f248[i].value[j], px, y);
            W1714SetSize(&D_0035f248[i].value[j], size);
            func_001395f8(&D_0035f248[i].value[j]);
            func_0028dcc0(&D_0035f248[i].value[j], &D_0035f248[i].frame);
            D_0035f248[i].str[j][0] = 0;
            W1714SetText(&D_0035f248[i].value[j], D_0035f248[i].str[j]);
            W1714SetMode(&D_0035f248[i].value[j], 1);
            func_0028dcc0(&D_0035f248[i].value[j], &D_0035f248[i].frame);
            t = j;
            switch (D_0035f24d) {
            case 0:
                c = 95;
                if (j == 0) continue;
                d = (j == 1) ? 98 : g99;
                t = j - 1;
                break;
            case 5:
                c = 97;
                d = 96;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            default:
                c = -1;
                d = 100;
                break;
            }
            if (c >= 0) {
                func_0028d8c0(&D_0035f248[i].bar[t], 0x753c, W1714R0(), W1714R1(), W1714R2(), c, -1, 0);
                func_00139620(&D_0035f248[i].bar[t]);
                y = lh * j;
                func_00138c68(&D_0035f248[i].bar[t], 0, y);
                func_0028dcc0(&D_0035f248[i].bar[t], &D_0035f248[i].frame);
            }
            func_0028d8c0(&D_0035f248[i].gauge[t], 0x753d, W1714R0(), W1714R1(), W1714R2(), d, -1, 0);
            func_00139620(&D_0035f248[i].gauge[t]);
            y = lh * j;
            func_00138c68(&D_0035f248[i].gauge[t], 0, y);
            func_0028dcc0(&D_0035f248[i].gauge[t], &D_0035f248[i].frame);
        }
    }
    func_0027eb10();
}
}  // namespace n0027dee8
