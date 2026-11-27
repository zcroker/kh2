#include "../common/types.h"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tz/ui_accessors.hpp"
#include "../tozawa/light_cur.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_util.hpp"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"

// 0028c878 (from src/anon/batch_w1900_nsa.cpp)
namespace n0028c878 {
struct Alloc878 { virtual void* Alloc(int, int); virtual void Free(void*); };
struct Heap878 { u8 pad[20]; Alloc878* a; };
extern "C" Heap878* D_00347f80;
extern "C" u8 D_00347e60[];
extern "C" void func_00239700(void*) asm("func_00239700");
struct MCObj878 {
    void* vt; u8 p4[8]; u32 f0c; u8 p10[8]; u8 m[384];
    MCObj878() { f0c = 0; vt = D_00347e60; func_00239700(m); }
    ~MCObj878() {}
    static void* operator new[](unsigned int n) { return D_00347f80->a->Alloc(n, 0); }
};
union F878 { s32 i; void* p; MCObj878* o; s32* q; u8 c; };
struct MCSave878 { F878 a0, a4, a8, ac, a10, a14, a18; };
extern s32 D_0035f3f8 asm("D_0035f3f8");
extern MCObj878* D_0035f3fc asm("D_0035f3fc");
extern "C" s32* D_0035f400;
extern "C" s32 D_0035f404;
extern "C" s32* D_0035f408;
union G40c { s32* p; s32 i; };
extern "C" G40c D_0035f40c;
extern "C" s32 D_0035f410;
union G414 { MCSave878* p; s32 i; };
extern "C" G414 D_0035f414;
void* func_001063c0(s32, s32) asm("func_001063c0");
s32* func_001063f0(s32, s32) asm("func_001063f0");
void Tz__MenuCursor__Init(s32 heap, s32 n) asm("Tz__MenuCursor__Init");
void Tz__MenuCursor__Init(s32 heap, s32 n)
{
    if (D_0035f3f8) {
        D_0035f414.p = (MCSave878*)func_001063c0(28, heap);
        D_0035f414.p->a10.i = ((F878*)&D_0035f3f8)->i;
        D_0035f414.p->a8.i = ((F878*)&D_0035f404)->i;
        D_0035f414.p->a0.o = ((F878*)&D_0035f3fc)->o;
        D_0035f414.p->a4.q = ((F878*)&D_0035f400)->q;
        D_0035f414.p->ac.q = ((F878*)&D_0035f408)->q;
        D_0035f414.p->a14.q = ((F878*)&D_0035f40c)->q;
        D_0035f414.p->a18.i = ((F878*)&D_0035f410)->i;
    }
    D_0035f3f8 = heap;
    D_0035f404 = n;
    D_0035f3fc = new MCObj878[n];
    D_0035f400 = func_001063f0(D_0035f404 * 4, D_0035f3f8);
    D_0035f408 = func_001063f0(D_0035f404 * 4, D_0035f3f8);
    D_0035f40c.p = func_001063f0(D_0035f404 * 4, D_0035f3f8);
    for (s32 i = 0; i < D_0035f404; i++) D_0035f40c.p[i] = -1;
    D_0035f410 = 0;
}
}  // namespace n0028c878

// 0028ca78 (from src/anon/batch_w278.cpp)
namespace n0028ca78 {
struct Alloc278 { virtual void* Alloc(int, int); virtual void Free(void*); };
struct Heap278 { u8 pad[20]; Alloc278* a; };
extern "C" Heap278* D_00347f80;
struct MCObj278 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual ~MCObj278();
    static void operator delete[](void* p) { D_00347f80->a->Free(p); }
    u8 pad[404];
};
union F278 { s32 i; void* p; MCObj278* o; u8 c; };
struct MCSave278 { F278 a0, a4, a8, ac, a10, a14, a18; };
extern s32 D_0035f3f8 asm("D_0035f3f8");
extern MCObj278* D_0035f3fc asm("D_0035f3fc");
extern void* D_0035f400 asm("D_0035f400");
extern s32 D_0035f404 asm("D_0035f404");
extern void* D_0035f408 asm("D_0035f408");
extern void* D_0035f40c asm("D_0035f40c");
extern s32 D_0035f410 asm("D_0035f410");
extern MCSave278* D_0035f414 asm("D_0035f414");
void func_0028cdb8(s32) asm("func_0028cdb8");
// record408_alloc_init
void DelArr278(void*) asm("_ZdaPv");
void LoadDataFree278(...) asm("_ZN2Tz12LoadDataFreeEz");
void Exit278() asm("_ZN2Tz10MenuCursor4ExitEv");
void Exit278() {
    s32 i;
    for (i = 0; i < D_0035f404; i++) func_0028cdb8(i);  // record408_alloc_init
    if (D_0035f3fc) {
        delete[] D_0035f3fc;
        D_0035f3fc = 0;
    }
    if (D_0035f400) { DelArr278(D_0035f400); D_0035f400 = 0; }
    if (D_0035f408) { DelArr278(D_0035f408); D_0035f408 = 0; }
    if (D_0035f40c) { DelArr278(D_0035f40c); D_0035f40c = 0; }
    D_0035f3f8 = 0;
    D_0035f404 = 0;
    if (D_0035f414) {
        MCSave278* s = D_0035f414;
        ((F278*)&D_0035f3f8)->i = s->a10.i;
        ((F278*)&D_0035f404)->i = s->a8.i;
        ((F278*)&D_0035f3fc)->o = s->a0.o;
        ((F278*)&D_0035f400)->p = s->a4.p;
        ((F278*)&D_0035f408)->p = s->ac.p;
        ((F278*)&D_0035f40c)->p = s->a14.p;
        ((F278*)&D_0035f410)->i = s->a18.i;
        LoadDataFree278(s);
        D_0035f414 = 0;
    }
}
}  // namespace n0028ca78


// 0028cbf8 (from src/tozawa/cmenu_selector.cpp)
namespace Tz {
extern u32 D_0035f3fc_sel asm("D_0035f3fc");
extern u32 D_0035f3f8_sel asm("D_0035f3f8");
extern u32 D_0035f40c_sel asm("D_0035f40c");
void func_001396b0_sel(u32) asm("func_001396b0");
bool MenuCursor::isInit() { return D_0035f3f8_sel != 0; }
}  // namespace Tz

// 0028cc08 (from src/anon/batch_w11.cpp)
namespace n0028cc08 {
typedef s32 (*VFn3)(void*, void*, void*);
extern void* D_0035f3f8 asm("D_0035f3f8");
s32 func_0028cc08(void* a) asm("func_0028cc08");
s32 func_0028cc08(void* a) {
    void* o = D_0035f3f8;
    return (*(VFn3*)(*(u8**)o))(o, a, __builtin_return_address(0));
}
}  // namespace n0028cc08

// 0028cc40 (from src/anon/batch_w12.cpp)
namespace n0028cc40 {
extern void** D_0035f3f8 asm("D_0035f3f8");
void func_0028cc40(void* a) asm("func_0028cc40");
void func_0028cc40(void* a) {
    if (a) {
        void** o = D_0035f3f8;
        (*(void (**)(void*, void*))((u8*)*o + 4))(o, a);
    }
}
}  // namespace n0028cc40

// 0028cc78 (from src/anon/batch_w1599.cpp)
namespace n0028cc78 {
struct Sub { u8 pad[184]; u32 flags; };
struct Ent { u8 pad[24]; Sub sub; u8 pad2[408 - 24 - 188]; };
struct Pair { s16 a, b; };
union GP { Pair* p; s16 h; };
union GE { Ent* p; u32 w; s16 h; };
struct Obj { u8 pad[40]; s32 x28; };
extern GE D_0035f3fc asm("D_0035f3fc");
extern GP D_0035f400 asm("D_0035f400");
union GW { u32* p; s16 h; };
extern GW D_0035f408 asm("D_0035f408");
extern s32* D_0035f40c asm("D_0035f40c");
extern u32 D_0035f410 asm("D_0035f410");
Obj* func_0023f1b0(u8*) asm("func_0023f1b0");
s32 func_0023c4b8(Obj*, s32) asm("func_0023c4b8");
u8* func_00236ca8(s32, s32) asm("func_00236ca8");
void dk__Sprite__create(Ent*, s32, s32, u8*, s32, s32) asm("dk__Sprite__create");
static inline void setf(Sub* s) { s->flags |= 8; }
void Tz__MenuCursor__Create(s32 idx, s32 a1, s32 a2, u8* a3, s32 a4, s32 a5) asm("Tz__MenuCursor__Create");
void Tz__MenuCursor__Create(s32 idx, s32 a1, s32 a2, u8* a3, s32 a4, s32 a5) {
    s32 r1 = func_0023c4b8(func_0023f1b0(a3), a1);
    u8* r2 = func_00236ca8(func_0023f1b0(a3)->x28, a2);
    dk__Sprite__create(&D_0035f3fc.p[idx], D_0035f40c[idx], r1, r2, a4, 0);
    D_0035f400.p[idx].a = a4;
    D_0035f400.p[idx].b = a5;
    D_0035f408.p[idx] = 0;
    D_0035f410 &= ~(1 << idx);
    if (r2[400]) setf(&D_0035f3fc.p[idx].sub);
}
}  // namespace n0028cc78

// 0028cdb8 (from src/anon/batch_w64.cpp)
namespace n0028cdb8 {
typedef void (*VFn)(void*);
s32 func_00139d78(void*) asm("func_00139d78");
extern u8* D_0035f3fc asm("D_0035f3fc");
extern u32 D_0035f410 asm("D_0035f410");
void func_0028cdb8(s32 i) asm("func_0028cdb8");
void func_0028cdb8(s32 i) {  // record408_alloc_init
    if (func_00139d78(D_0035f3fc + i * 408)) {
        u8* o = (u8*)(i * 408 + (u32)D_0035f3fc);
        (*(VFn*)(*(u8**)o + 20))(o);
        D_0035f410 |= 1 << i;
    }
}
}  // namespace n0028cdb8

// 0028ce38 (from src/anon/batch_w41.cpp)
namespace n0028ce38 {
void DeleteAll(...) asm("_ZN2Tz10MenuCursor9DeleteAllEz");
extern s32 D_0035f404 asm("D_0035f404");
extern u32 D_0035f410 asm("D_0035f410");
void func_0028cdb8(s32) asm("func_0028cdb8");
// record408_alloc_init
void DeleteAll(...) {
    for (s32 i = 0; i < D_0035f404; i++) func_0028cdb8(i);  // record408_alloc_init
    D_0035f410 = 0;
}
}  // namespace n0028ce38


// 0028ce98 (from src/anon/batch_w45.cpp)
namespace n0028ce98 {
extern u32* D_0035f408 asm("D_0035f408");
extern s16* D_0035f400 asm("D_0035f400");
extern u8* D_0035f3fc asm("D_0035f3fc");
void func_00138c10(u8*, s32) asm("func_00138c10");
void Tz__MenuCursor__SetType(s32 i, u32 v) asm("Tz__MenuCursor__SetType");
void Tz__MenuCursor__SetType(s32 i, u32 v) {  // slot_set_and_refresh
    u32* p = (u32*)(i * 4 + (u32)D_0035f408);
    if (*p == v) return;
    *p = v;
    s32 x;
    if (!v) x = D_0035f400[i * 2];
    else x = D_0035f400[i * 2 + 1];
    func_00138c10(D_0035f3fc + i * 408, x);
}
}  // namespace n0028ce98

// 0028cf10 (from src/anon/tiny_leaf.cpp)
namespace n0028cf10 {
u32 func_0028cf10(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0028cf10");
u32 func_0028cf10(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_table_entry
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r15 = (u32)(0x0036u << 16);
    r4 = (u32)(r4 << 2);
    r14 = *(u32*)((u32)r15 + (s32)(-3064));
    r4 = (u32)(r4 + r14);
    r2 = *(u32*)((u32)r4 + (s32)(0));
    return r2;
}
}  // namespace n0028cf10

// 0028cf28 (from src/anon/batch_w42.cpp)
namespace n0028cf28 {
void select_begin_leave(void*) asm("_ZN2Tz6Select10BeginLeaveEz");
void select_set_flag(void*, s32) asm("_ZN2Tz6Select7SetFlagEz");
extern u8* D_0035f3fc asm("D_0035f3fc");
void Tz__MenuCursor__SetParent(s32 i, s32 v) asm("Tz__MenuCursor__SetParent");
void Tz__MenuCursor__SetParent(s32 i, s32 v)
{
    u8* e = D_0035f3fc + i * 408;
    *(s32*)(e + 396) = v;
    select_begin_leave(e);
    if (*(s32*)(e + 396)) {
        *(s32*)(e + 400) = 0;
        select_begin_leave(e);
        if (*(s32*)(e + 400)) select_set_flag(e, 0);
    }
}
}  // namespace n0028cf28

// 0028cf98 (from src/tozawa/cmenu_selector.cpp)
namespace Tz {
extern u32 D_0035f3fc_sel asm("D_0035f3fc");
extern u32 D_0035f3f8_sel asm("D_0035f3f8");
extern u32 D_0035f40c_sel asm("D_0035f40c");
void func_001396b0_sel(u32) asm("func_001396b0");
void MenuCursor::SetParentSeq(s32 index, YI::SEQUENCE* seq) {
    u32 p = D_0035f3fc_sel + (u32)index * 408;
    *(u32*)(p + 400) = (u32)seq;
        func_001396b0_sel(p);
        if (*(u32*)(p + 400) != 0) {
            *(u32*)(p + 396) = 0;
            func_001396b0_sel(p);
            if (*(u32*)(p + 396) != 0) {
                MenuCursor::SetFlag(p, 0);
            }
        }
}
}  // namespace Tz

// 0028d008 (from src/anon/batch_w42.cpp)
namespace n0028d008 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
extern u8* D_0035f3fc asm("D_0035f3fc");
extern s32 D_0035f410 asm("D_0035f410");
u8 func_0028d008(s32 i) asm("func_0028d008");
u8 func_0028d008(s32 i)
{
    u8 r = D_0035f3fc ? u_call4_00139d78(D_0035f3fc + i * 408) : 0;
    if (r && ((D_0035f410 >> i) & 1)) r = 0;
    return r;
}
}  // namespace n0028d008

// 0028d068 (from src/anon/batch_w47.cpp)
namespace n0028d068 {
void wtarget_0028d068(u32, u32, u32, u32) asm("_Z16wtarget_0028d068jjjj");
extern s32 D_0035f404 asm("D_0035f404");
extern u32 D_0035f40c asm("D_0035f40c");
void wtarget_0028d068(u32 a, u32 b, u32, u32) asm("_Z16wtarget_0028d068jjjj");
void wtarget_0028d068(u32 a, u32 b, u32, u32) {
    if ((s32)b < 0) {
        for (s32 i = 0; i < D_0035f404; i++) ((u32*)D_0035f40c)[i] = a;
    } else ((u32*)D_0035f40c)[b] = a;
}
}  // namespace n0028d068

// 0028d0c8 (from src/tozawa/cmenu_selector.cpp)
namespace Tz {
extern u32 D_0035f3fc_sel asm("D_0035f3fc");
extern u32 D_0035f3f8_sel asm("D_0035f3f8");
extern u32 D_0035f40c_sel asm("D_0035f40c");
void func_001396b0_sel(u32) asm("func_001396b0");
u32 MenuCursor::GetPri(s32 index) {
    return *(u32*)(D_0035f40c_sel + (u32)index * 4);
}
}  // namespace Tz

// 0028d0e0 (from src/tozawa/cmenu_selector.cpp)
namespace Tz {
extern u32 D_0035f3fc_sel asm("D_0035f3fc");
extern u32 D_0035f3f8_sel asm("D_0035f3f8");
extern u32 D_0035f40c_sel asm("D_0035f40c");
void func_001396b0_sel(u32) asm("func_001396b0");
dk::Sprite* MenuCursor::GetSprite(s32 index) {
    u32 base = D_0035f3fc_sel;
    return reinterpret_cast<dk::Sprite*>(base + ((u32)index * 408));
}
}  // namespace Tz

// 0028d0f8 (from src/anon/batch_w28.cpp)
namespace n0028d0f8 {
void func_00239700(void*) asm("func_00239700");
void func_0028d188(void*) asm("func_0028d188");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035f420[] asm("D_0035f420");
void func_0028d0f8(u8* p) asm("func_0028d0f8");
void func_0028d0f8(u8* p) {
    *(u32*)(p + 12) = 0;
    *(void**)p = D_00347e60;
    func_00239700(p + 24);
    *(void**)p = D_0035f420;
    func_0028d188(p);
}
}  // namespace n0028d0f8

// 0028d140 (from src/anon/batch_w29.cpp)
namespace n0028d140 {
void ItemStat_ctor(u32* p) asm("_ZN2Tz8ItemStatC1Ev");
void func_00239700(void*) asm("func_00239700");
void func_0028d188(void*) asm("func_0028d188");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035f420[] asm("D_0035f420");
void ItemStat_ctor(u32* p) {
    p[3] = 0;
    *(void**)p = D_00347e60;
    func_00239700(p + 6);
    *(void**)p = D_0035f420;
    func_0028d188(p);
}
}  // namespace n0028d140


// 0028d188 (from src/anon/batch_wlit.cpp)
namespace n0028d188 {
// 00159f90: moved to src/harata/libdk/targetcamera.cpp

void func_0028d188(u8* p) asm("func_0028d188");
void func_0028d188(u8* p) {
    p[412] = 0;
    p[413] = 0;
    *(f32*)(p + 416) = 30.0f;
    *(u32*)(p + 420) = 0;
    *(u32*)(p + 424) = 0;
    *(u32*)(p + 428) = 0;
    *(u32*)(p + 432) = 0;
    *(u32*)(p + 436) = 0;
    *(u32*)(p + 440) = 0;
}
}  // namespace n0028d188

// 0028d1c0 (from src/anon/batch_wcx2.cpp)
namespace n0028d1c0 {
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
u8* func_0023f1b0(u32) asm("func_0023f1b0");
u32 func_0023c4b8(u8* p, u32 a) asm("func_0023c4b8");
// --------------------
struct O28d1c0 { u8 pad[392]; s32 f392; u8 pad2[10]; s16 h[3]; };
void func_0028d6e8(O28d1c0*) asm("func_0028d6e8");
u32 func_0023c4b8(u8*, u32) asm("func_0023c4b8");
u8* func_00236ca8_28d1c0(u32, u32) asm("func_00236ca8");
void func_0028d188(O28d1c0*) asm("func_0028d188");
void func_001386e0_28d1c0(O28d1c0*, s32, u32, u8*, s32, s32) asm("dk__Sprite__create");
void Tz__LightCur__Create(O28d1c0* o, s32 id, u32 a, u32 b, u32 bank, s16* src) asm("Tz__LightCur__Create");
void Tz__LightCur__Create(O28d1c0* o, s32 id, u32 a, u32 b, u32 bank, s16* src)
{
    func_0028d6e8(o);
    u32 h = func_0023c4b8(func_0023f1b0(bank), a);
    u8* w = func_00236ca8_28d1c0(*(u32*)(func_0023f1b0(bank) + 40), b);
    func_0028d188(o);
    for (s32 i = 0; i < 3; i++) o->h[i] = src[i];
    func_001386e0_28d1c0(o, id, h, w, o->h[0], 0);
    o->f392 = o->h[2];
}
}  // namespace n0028d1c0

// 0028d2a0 (from src/anon/batch_w62.cpp)
namespace n0028d2a0 {
void dk__Sprite__update(void) asm("dk__Sprite__update");
double func_00313b80(f32) asm("func_00313b80");
s32 func_003142e0(double, double) asm("func_003142e0");
extern f32 D_00349e10 asm("D_00349e10");
void func_0028d2a0(u8* p) asm("func_0028d2a0");
void func_0028d2a0(u8* p) {
    if (*(u32*)(p + 12) & 0x100) return;
    dk__Sprite__update();
    if (func_003142e0(0.0, func_00313b80(*(f32*)(p + 416))) > 0) return;
    if (*(f32*)(p + 416) < 30.0f) {
        *(f32*)(p + 416) += D_00349e10;
        if (30.0f < *(f32*)(p + 416)) *(f32*)(p + 416) = 30.0f;
    }
}
}  // namespace n0028d2a0

// 0028d320 (from src/anon/batch_w2410_nsa.cpp)
namespace n0028d320 {
struct Sub28d { u8 p0[0x148]; s32 x; s32 y; };
struct Obj28d {
    u8 p0[0xc]; u32 flags; u8 p10[8];
    Sub28d sub;
    u8 p168[0x170 - 0x168];
    s32 x; s32 y; s32 ox; s32 oy;
    u8 p180[0x18c - 0x180];
    Obj28d* parent; Sub28d* other;
    u8 p194[0x19c - 0x194];
    u8 started; u8 trig; u8 p19e[2];
    f32 t; s32 sx; s32 sy; s32 dx; s32 dy; s32 lx; s32 ly;
};
extern f32 D_00374448[] asm("D_00374448");
s32 func_00139d78(Obj28d*) asm("func_00139d78");
s32 func_00239d20(Sub28d*) asm("func_00239d20");
void func_00138cd0(Obj28d*, s32*, s32*) asm("func_00138cd0");
void func_00138c50(Obj28d*, s32*, s32*) asm("func_00138c50");
s32 func_0023aa18(Sub28d*) asm("func_0023aa18");
s32 func_0023aa38(Sub28d*) asm("func_0023aa38");
void func_0023a9c0(Sub28d*, s32*, s32*) asm("func_0023a9c0");
double func_00313b80(f32) asm("func_00313b80");
s32 func_003142e0(double, double) asm("func_003142e0");
f32 func_0028f1e0(f32*, f32*, f32) asm("func_0028f1e0");
void YI__SEQUENCE__Draw(Sub28d*) asm("YI__SEQUENCE__Draw");
void func_0028d320(Obj28d* o) asm("func_0028d320");
void func_0028d320(Obj28d* o)
{
    s32 dx, dy;
    if (o->flags & 0x800) {
        if (o->parent && !func_00139d78(o->parent)) return;
        if (o->other && !func_00239d20(o->other)) return;
    }
    if (o->parent) {
        func_00138cd0(o->parent, &dx, &dy);
        func_00138c50(o->parent, &o->x, &o->y);
        o->x += dx;
        o->y += dy;
        o->x += func_0023aa18(&o->parent->sub);
        o->y += func_0023aa38(&o->parent->sub);
    } else if (o->other) {
        func_0023a9c0(o->other, &dx, &dy);
        {
        Sub28d* ot = o->other;
        s32 nx = dx + ot->x;
        s32 ny = dy + ot->y;
        o->y = ny;
        o->x = nx;
        }
        o->x += func_0023aa18(o->other);
        o->y += func_0023aa38(o->other);
    }
    if (o->trig) {
        if (!o->started) {
            s32 x = o->x;
            s32 y = o->y;
            o->sx = x;
            o->sy = y;
            o->dx = x;
            o->dy = y;
            o->t = 30.0f;
            o->started = 1;
        } else {
            o->sx = o->lx;
            o->sy = o->ly;
            o->dx = o->x;
            o->dy = o->y;
            o->t = 0.0f;
        }
        o->trig = 0;
    }
    if (o->parent || o->other) {
        o->dx = o->x;
        o->dy = o->y;
    }
    {
        f32 t = o->t;
        f32 dur = 30.0f;
        if (func_003142e0(0.0, func_00313b80(dur - t)) <= 0) {
            f32 ex = o->dx - o->sx;
            f32 ey = o->dy - o->sy;
            f32 f = func_0028f1e0(D_00374448, D_00374448 + 4, t / dur);
            o->x = o->sx + (s32)(ex * f);
            o->y = o->sy + (s32)(ey * f);
        }
    }
    {
    Sub28d* s = &o->sub;
    s32 x = o->x, y = o->y;
    s32 b = y + o->oy, a = x + o->ox;
    o->ly = y;
    o->lx = x;
    s->x = a;
    s->y = b;

    YI__SEQUENCE__Draw(s);
    }
}
}  // namespace n0028d320

// 0028d5d0 (from src/tozawa/light_cur.cpp)
namespace Tz {
u32 func_00139d78_lc(...) asm("func_00139d78");
void LightCur::FadeOut() {
    u8* s0 = (u8*)this;
    if (((LightCur*)s0)->isExist() != 0u) {
        s32 t6 = (s32)*(s16*)(s0 + 408);
        s32 t7 = *(s32*)(s0 + 388);
        if (t7 != t6) {
            u32 t6v = *(u32*)s0;
            ((void (*)(void*))(*(u32*)(t6v + 20u)))(s0);
        }
    }
}
}  // namespace Tz

// 0028d620 (from src/tozawa/light_cur.cpp)
namespace Tz {
u32 func_00139d78_lc(...) asm("func_00139d78");
void LightCur::Leave() {
    u8* s0 = (u8*)this;
    if (((LightCur*)s0)->isExist() != 0u) {
        u32 t7 = *(u32*)s0;
        ((void (*)(void*))(*(u32*)(t7 + 20u)))(s0);
    }
}
}  // namespace Tz

// 0028d660 (from src/anon/batch_w57.cpp)
namespace n0028d660 {
extern void (**D_0032b914)() asm("void");
void func_0028d6e8(void*) asm("func_0028d6e8");
void func_001396b0(void*) asm("func_001396b0");
void func_0031a260(void*, u32) asm("func_0031a260");
struct T28d { u8 p[396]; u32 f396; u32 f400; u8 p2[9]; u8 b413; };
void func_0028d660(T28d* t, u32 v) asm("func_0028d660");
void func_0028d660(T28d* t, u32 v) {  // record_set_value_refresh
    func_0028d6e8(t);
    if (t->f396 != v) {
        t->f396 = v;
        t->b413 = 1;
        func_001396b0(t);
        if (t->f396) {
            t->f400 = 0;
            func_001396b0(t);
            if (t->f400) func_0031a260(t, 0);
        }
    }
}
}  // namespace n0028d660

// 0028d6e8 (from src/tozawa/light_cur.cpp)
namespace Tz {
u32 func_00139d78_lc(...) asm("func_00139d78");
u32 LightCur::isExist() {
    u32 (*fp_call0_00139d78)() = (u32(*)())func_00139d78_lc;
    return fp_call0_00139d78();
}
}  // namespace Tz

// 0028d708 (from src/anon/batch_w9.cpp)
namespace n0028d708 {
void func_00138d48(void*) asm("func_00138d48");
void func_001395f8(void*) asm("func_001395f8");
void func_0028d708(void* p) asm("func_0028d708");
void func_0028d708(void* p) {
    func_00138d48(p);
    func_001395f8(p);
}
}  // namespace n0028d708

// 0028d730 (from src/anon/auto80_199_queue.cpp)
namespace n0028d730 {
u32 func_002892f8(...) asm("func_002892f8");
u32 func_002891b8(u32, u32) asm("func_002891b8");
void func_0028d708(u32, f32, f32, f32, f32) asm("func_0028d708");
typedef s32 (*Cb_0028d730)(u32);
void func_0028d730(u32 self, Cb_0028d730 cb, f32 a2, f32 a3, f32 a4, f32 a5) asm("func_0028d730");
void func_0028d730(u32 self, Cb_0028d730 cb, f32 a2, f32 a3, f32 a4, f32 a5) {
    s32 count = (s32)func_002892f8(self);
    s32 i = 0;
    if (count <= 0) {
        return;
    }
    do {
        if (cb((u32)i) == 0) {
            u32 obj = func_002891b8(self, (u32)i);
            func_0028d708(obj, a2, a3, a4, a5);
        }
        i += 1;
    } while (i < count);
}
}  // namespace n0028d730

// 0028d7f0 (from src/anon/batch_w78.cpp)
namespace n0028d7f0 {
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
extern u8 D_0035f3a8 asm("D_0035f3a8");
u32 func_0023f948(void*, u32) asm("func_0023f948");
u32 func_0023f908(void*, u32) asm("func_0023f908");
void Tz__Layout__create(u32, u32, u32, u32, u32, u32) asm("Tz__Layout__create");
void func_0023f0c8(u32, u32) asm("func_0023f0c8");
void Tz__MenuUtil__CreateLay(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 x, u32 y, u32 z) asm("Tz__MenuUtil__CreateLay");
void Tz__MenuUtil__CreateLay(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 x, u32 y, u32 z) {
    if (!x) x = func_0023f948(&D_0035f3a8, a2);
    if (!y) y = func_0023f908(&D_0035f3a8, a3);
    Tz__Layout__create(a0, a1, x, y, t0, z);
    func_0023f0c8(a0, t1);
}
}  // namespace n0028d7f0

// 0028d8c0 (from src/anon/batch_w83.cpp)
namespace n0028d8c0 {
void* func_0023f1b0(s32) asm("func_0023f1b0");
void* func_0023c4b8(void*, s32) asm("func_0023c4b8");
u8* func_00236ca8(void*, s32) asm("func_00236ca8");
void dk__Sprite__create(void*, s32, void*, void*, s32, s32) asm("dk__Sprite__create");
// Tz Pause CreateFadeObject
void CreateFadeObject(u8*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void CreateFadeObject(u8* p, s32 id, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3) {
    void* h = func_0023c4b8(func_0023f1b0(t0), a2);
    u8* v = func_00236ca8(*(void**)((u8*)func_0023f1b0(t0) + 40), a3);
    dk__Sprite__create(p, id, h, v, t1, t3);
    *(s32*)(p + 392) = t2;
}
}  // namespace n0028d8c0


// 0028d980 (from src/anon/batch_w80.cpp)
namespace n0028d980 {
// ---- unit 11 (h.cpp)
struct U11_CurObj { u8 pad[24]; u8 sub[184]; u32 f208; u8 pad2[392 - 212]; u32 f392; u8 pad3[405 - 396]; u8 f405; u8 pad4[2]; u8* f408; u8 pad5[428 - 412]; u32 f428; u32 f432; };
struct U11_SprInfo { u8 pad[40]; u32 f40; };
U11_SprInfo* func_0023f1b0(u32) asm("func_0023f1b0");
u32 func_0023c4b8(U11_SprInfo*, u32) asm("func_0023c4b8");
u32 func_00236ca8(u32, u32) asm("func_00236ca8");
u32 func_00192048(s32) asm("func_00192048");
void func_00138d60(U11_CurObj*, u32, u32, u32, u32, u32, u32) asm("func_00138d60");
void w80_MenuCursor_Create(U11_CurObj* c, u32 a1, u32 a2, u32 a3, u32 sprA, u32 t1, u32 t2, s32 t3, u32 st) asm("_ZN2Tz10MenuCursor6CreateEz");
// Tz::MenuCursor::Create
void w80_MenuCursor_Create(U11_CurObj* c, u32 a1, u32 a2, u32 a3, u32 sprA, u32 t1, u32 t2, s32 t3, u32 st) asm("_ZN2Tz10MenuCursor6CreateEz");
void w80_MenuCursor_Create(U11_CurObj* c, u32 a1, u32 a2, u32 a3, u32 sprA, u32 t1, u32 t2, s32 t3, u32 st) {
    u32 x = func_0023c4b8(func_0023f1b0(sprA), a2);
    u32 y = func_00236ca8(func_0023f1b0(sprA)->f40, a3);
    u32 z = 0;
    if (t3 >= 0) z = func_00192048(t3);
    func_00138d60(c, a1, x, y, t1, z, st);
    c->f392 = t2;
    c->f428 = 1;
}
}  // namespace n0028d980


// 0028da70 (from src/anon/batch_w65.cpp)
namespace n0028da70 {
void Sel_SetSequence(u8* p, s32 a) asm("_ZN2Tz6Select11SetSequenceEz");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00138c10(void*, s32) asm("func_00138c10");
void Sel_SetSequence(u8* p, s32 a) {
    if (!func_00139d78(p)) return;
    if (*(s32*)(p + 388) != a) {
        func_00138c10(p, a);
        *(s32*)(p + 392) = -1;
    }
}
}  // namespace n0028da70


// 0028dac8 (from src/anon/tiny.cpp)
namespace n0028dac8 {
void func_0028da70(void*) asm("func_0028da70");
void func_0028dac8(BD_VALUE* bd) asm("func_0028dac8");
void func_0028dac8(BD_VALUE* bd) { func_0028da70(bd); }
}  // namespace n0028dac8

// 0028dae0 (from src/anon/auto80_199_queue.cpp)
namespace n0028dae0 {
u32 func_00139d78(...) asm("func_00139d78");
u32 func_0023f0c0(...) asm("func_0023f0c0");
u32 func_0023f070(...) asm("func_0023f070");
void func_0028dae0(u32 self, u32 value) asm("_ZN2Tz8MenuUtil10LayFadeOutEPNS_6LayoutEi");
void func_0028dae0(u32 self, u32 value) {
    if (func_00139d78(self) != 0) {
        u32 cur = func_0023f0c0(self);
        if (cur != value) {
            func_0023f070(self, value, -1);
            return;
        }
    }
}
}  // namespace n0028dae0

// 0028db48 (from src/anon/auto80_199_queue.cpp)
namespace n0028db48 {
u32 func_00139d78(...) asm("func_00139d78");
u32 func_00239d30(...) asm("func_00239d30");
u32 Tz__MenuUtil__SprtIsLoop(u32 self) asm("Tz__MenuUtil__SprtIsLoop");
u32 Tz__MenuUtil__SprtIsLoop(u32 self) {
    u32 ret = 0;
    if (self != 0) {
        if (func_00139d78(self) != 0) {
            u32 p = self + 24;
            u32 v = func_00239d30(p, *(u32*)(p + 276));
            ret = ((v & 0xff) != 0);
        }
    }
    return ret;
}
}  // namespace n0028db48

// 0028dba0 (from src/anon/auto80_199_queue.cpp)
namespace n0028dba0 {
u32 func_0028acc8(...) asm("func_0028acc8");
u32 func_0028ae28(...) asm("func_0028ae28");
u32 func_0028dba0(u32 self) asm("func_0028dba0");
u32 func_0028dba0(u32 self) {
    u32 ret = 0;
    if (self != 0) {
        if (func_0028acc8(self) != 0) {
            ret = (func_0028ae28(self, 0) != 0);
        }
    }
    return ret;
}
}  // namespace n0028dba0

// 0028dbf8 (from src/anon/batch_w76.cpp)
namespace n0028dbf8 {
s32 func_00139d78(void*) asm("func_00139d78");
u8* func_0023f1b0(void*) asm("func_0023f1b0");
u32 YI__LAYOUT__SearchSequence(u8*, s32, s32) asm("YI__LAYOUT__SearchSequence");
u32 Tz__MenuUtil__GetLaySeq(void* a, s16* keys, s16* vals) asm("Tz__MenuUtil__GetLaySeq");
u32 Tz__MenuUtil__GetLaySeq(void* a, s16* keys, s16* vals)
{
    if (!func_00139d78(a)) return 0;
    s32 idx = -1;
    s32 cur = *(s32*)(func_0023f1b0(a) + 76);
    for (s32 i = 0; i < 3; i++) {
        if (cur == keys[i]) { idx = vals[i]; break; }
    }
    if (idx < 0) return 0;
    return YI__LAYOUT__SearchSequence(func_0023f1b0(a), idx, 0);
}
}  // namespace n0028dbf8

// 0028dcc0 (from src/anon/batch_w38.cpp)
namespace n0028dcc0 {
void MenuCursor_AttachSprite(u8*, u32) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void func_001396b0(void*) asm("func_001396b0");
void func_00139660(void*) asm("func_00139660");
void func_00139688(void*) asm("func_00139688");
void func_0031a260(void*, s32) asm("func_0031a260");
void MenuCursor_AttachSprite(u8* p, u32 s) {
    *(u32*)(p + 396) = s;
    func_001396b0(p);
    if (*(u32*)(p + 396)) {
        *(u32*)(p + 400) = 0;
        func_001396b0(p);
        if (*(u32*)(p + 400)) func_0031a260(p, 0);
    }
    func_00139660(p);
    func_00139688(p);
    func_001396b0(p);
}
}  // namespace n0028dcc0


// 0028dd28 (from src/anon/auto80_199_queue.cpp)
namespace n0028dd28 {
u32 func_001396b0(...) asm("func_001396b0");
void func_00139660(u32) asm("func_00139660");
void func_00139688(u32) asm("func_00139688");
u32 func_0031ac78(...) asm("func_0031ac78");
struct Obj_0028dd28 {
    u8 pad0[396];

u32 field396;

u32 field400;

};
void func_0028dd28(Obj_0028dd28* self, u32 value) asm("_ZN2Tz8MenuUtil16SetSprtParentSeqEPN2dk6SpriteEPN2YI8SEQUENCEE");
void func_0028dd28(Obj_0028dd28* self, u32 value) {
    self->field400 = value;
    func_001396b0((u32)self);
    if (self->field400 != 0) {
        self->field396 = 0;
        func_001396b0((u32)self);
        if (self->field396 != 0) {
            func_0031ac78((u32)self, 0);
        }
    }
    func_00139660((u32)self);
    func_00139688((u32)self);
    func_001396b0((u32)self);
}
}  // namespace n0028dd28

// 0028dd90 (from src/anon/batch_w26.cpp)
namespace n0028dd90 {
s32 func_0028dd90(s32 x) asm("func_0028dd90");
s32 func_0028dd90(s32 x) {  // mod10_classify_012
    s32 r = 0;
    s32 m = x % 10;
    switch (m) {
    case 0: break;
    case 1: r = 2; break;
    case 2: r = 1; break;
    }
    return r;
}
}  // namespace n0028dd90

// 0028ddd8 (from src/tozawa/menu_util.cpp)
namespace Tz {
u32 MenuUtil::GetFontType(s32 a0) {
    s32 t6 = 100;
    s32 t7 = 10;
    s32 v0 = a0 % t6;
    s32 t6h = v0 % t7;
    v0 = v0 - t6h;
    v0 = v0 ^ 10;
    return (u32)(v0 == 0);
}
}  // namespace Tz

// 0028de08 (from src/anon/batch_w76.cpp)
namespace n0028de08 {
u32 func_00192048(s32) asm("func_00192048");
s32 func_00192a80(u32) asm("func_00192a80");
s32 func_00105c30(void) asm("func_00105c30");
extern char D_00374470[] asm("D_00374470");
u32 func_00192cc0(char*, const char*) asm("func_00192cc0");
s32 func_00192b30(u32) asm("func_00192b30");
void memcpy(u8*, char*, s32) asm("memcpy");
u8* Tz__MenuUtil__MakeQuestionStr(u32 id, u8* buf) asm("Tz__MenuUtil__MakeQuestionStr");
u8* Tz__MenuUtil__MakeQuestionStr(u32 id, u8* buf)
{
    char tmp[32];
    s32 flag = 0;
    u8* p = buf;
    s32 n = func_00192a80(func_00192048(id));
    if (func_00105c30() == 1 || func_00105c30() == 8) flag = 1;
    if (!flag) n = 5;
    s32 len = func_00192b30(func_00192cc0(tmp, D_00374470));
    for (s32 i = 0; i < n; i++) {
        if (i + 1 >= n) len++;
        memcpy(p, tmp, len);
        p += len;
    }
    return buf;
}
}  // namespace n0028de08

// 0028def0 (from src/anon/batch_w88.cpp)
namespace n0028def0 {
void memcpy(void*, u32, u32) asm("memcpy");
extern char D_00374470[] asm("D_00374470");
u8* func_00192cc0(u8*, const char*) asm("func_00192cc0");
s32 func_00192b30(u8*) asm("func_00192b30");
s32 func_00105c30(void) asm("func_00105c30");
// Fill dst with n copies of a formatted string (5 unless mode 1/8); the last copy keeps its NUL.
u8* Tz__MenuUtil__MakeQuestionStr_2(u8* dst, s32 n) asm("Tz__MenuUtil__MakeQuestionStr_2");
u8* Tz__MenuUtil__MakeQuestionStr_2(u8* dst, s32 n) {
    u8 buf[16];
    u8* q = dst;
    s32 ok = 0;
    s32 len = func_00192b30(func_00192cc0(buf, D_00374470));
    if (func_00105c30() == 1 || func_00105c30() == 8) ok = 1;
    if (!ok) n = 5;
    for (s32 i = 0; i < n; i++) {
        if (i + 1 >= n) len++;
        memcpy(q, (u32)buf, len);
        q += len;
    }
    return dst;
}
}  // namespace n0028def0

// 0028dfd0 (gap: C2 copy of the ctor at 0x28dfe8)
namespace n0028dfd0 {
extern u8 D_0035f440[] asm("D_0035f440");
void func_0028dfd0(u32* p) {
    p[14] = 0;
    p[3] = 0;
    p[0] = (u32)D_0035f440;
}
}  // namespace n0028dfd0

// 0028dfe8 (from src/anon/batch_w2.cpp)
namespace n0028dfe8 {
extern u8 D_0035f440[] asm("D_0035f440");
void func_0028dfe8(u32* p) asm("func_0028dfe8");
void func_0028dfe8(u32* p) {  // obj_ctor_36f440
    p[14] = 0;
    p[3] = 0;
    p[0] = (u32)D_0035f440;
}
}  // namespace n0028dfe8

// 0028e000 (from src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0028e000 {
u32 func_0028e350(u32, u32, u32, u32) asm("func_0028e350");
extern u8 D_00347f98 asm("D_00347f98");
extern u8 D_0035f440 asm("D_0035f440");
u32 func_0028e000(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0028e000");
u32 func_0028e000(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_0035f440;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = func_0028e350(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0028e000

// 0028e040 (from src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0028e040 {
u32 func_0028e350(u32, u32, u32, u32) asm("func_0028e350");
extern u8 D_00347f98 asm("D_00347f98");
extern u8 D_0035f440 asm("D_0035f440");
u32 func_0028e040(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0028e040");
u32 func_0028e040(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_0035f440;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = func_0028e350(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0028e040

// 0028e080 (from src/anon/auto80_199_queue.cpp)
namespace n0028e080 {
extern u32 D_00347f80 asm("D_00347f80");
extern u8 D_00347f98 asm("D_00347f98");
u32 fn(...) asm("fn");
void func_0028e350(u32) asm("func_0028e350");
extern u32 D_0035f440 asm("D_0035f440");
typedef void (*Fn_0028e080)(u32, u32);
static inline u32 addr_D_0035f440() {
    return (u32)&D_0035f440;

}
static inline u32 addr_D_00347f98() {
    return (u32)&D_00347f98;
}
void func_0028e080(u32 self) asm("func_0028e080");
void func_0028e080(u32 self) {
    *(u32*)self = addr_D_0035f440();
    func_0028e350(self);
    *(u32*)self = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_0028e080 fn = (Fn_0028e080)*(u32*)(*(u32*)obj + 4);
    fn(obj, self);
}
}  // namespace n0028e080

// 0028e0d8 (from src/anon/batch_wcx.cpp)
namespace n0028e0d8 {
void func_001391c8(u8*, u32) asm("func_001391c8");
void func_001391c8(u8*, u32, u32) asm("func_001391c8");
void func_001391c8(u8*, u32, u32) asm("func_001391c8");
void Tz__MultiSeq__create(u8*, s32) asm("Tz__MultiSeq__create");
void func_0028e190(u8*, s32) asm("func_0028e190");
void func_0028e3b8(u8*, s32, u32, u32, s16) asm("func_0028e3b8");
void func_0028e0d8(u8* p, u32 a1, u32 a2, u32 a3, s16* list, s32 n, u32 t2) asm("func_0028e0d8");
void func_0028e0d8(u8* p, u32 a1, u32 a2, u32 a3, s16* list, s32 n, u32 t2)
{
    func_001391c8(p, a1, t2);
    Tz__MultiSeq__create(p, n);
    func_0028e190(p, n);
    for (s32 i = 0; i < n; i++) func_0028e3b8(p, i, a2, a3, list[i]);
}
}  // namespace n0028e0d8

// .rodata 0x374448-0x374478: tables of this file that the code reads by address
extern "C" const s32 D_00374444 = 0;
extern "C" const u32 D_00374448[8] __attribute__((aligned(4))) = { 0, 0, 0x402ffce3, 0x402ffce3, 0x3f800000, 0x3f800000, 0, 0 };
extern "C" const s32 D_00374468[2] __attribute__((aligned(4))) = { 10, 10 };
extern "C" const char D_00374470[8] __attribute__((aligned(4))) = "?";

// 0028e190 (from src/anon/batch_w96.cpp)
namespace n0028e190 {
void func_0028e710(u8*, u32) asm("func_0028e710");
void func_0028ebf0(u8*, u32) asm("func_0028ebf0");
void func_0028e748(u8*, s32, u32) asm("func_0028e748");
struct Ch_w96 {
    u8 pad[344];
    s32 a;
    s32 b;
    u8 c;
    u8 pad2[3];
    f32 d;
    s32 e;
    s32 f;
    f32 g;
    f32 h;
    u8 pad3[4];
};
union ChU_w96 { Ch_w96* p; u32 u; u16 h; };
// Resets the channel table: n channels back to defaults.
void func_0028e190(u8* self, s32 n) asm("func_0028e190");
void func_0028e190(u8* self, s32 n) {
    s32 i;
    *(s32*)(self + 28) = 0;
    *(s32*)(self + 32) = 0;
    *(s32*)(self + 36) = 0;
    *(s32*)(self + 40) = 0;
    *(f32*)(self + 44) = 1.0f;
    func_0028e710(self, 0);
    func_0028ebf0(self, 0);
    for (i = 0; i < n; i++) {
        ChU_w96* arr = (ChU_w96*)(self + 56);
        arr->p[i].a = -1;
        arr->p[i].b = -1;
        arr->p[i].c = 0;
        arr->p[i].d = 1.0f;
        arr->p[i].e = 0;
        arr->p[i].f = 0;
        arr->p[i].g = 1.0f;
        arr->p[i].h = 1.0f;
        func_0028e748(self, i, 0);
    }
}
}  // namespace n0028e190

// 0028e2a8 (from src/anon/batch_wcx2.cpp)
namespace n0028e2a8 {
// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
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
HeapE* func_0013a1d8() asm("func_0013a1d8");
void func_00239700_e2a8(void*) asm("func_00239700");
struct T380_0028e2a8 { T380_0028e2a8() { func_00239700_e2a8(this); } ~T380_0028e2a8() {} u8 pad[380]; };
void Tz__MultiSeq__create(u8* p, s32 n) asm("Tz__MultiSeq__create");
void Tz__MultiSeq__create(u8* p, s32 n) {
    if (!*(u32*)(p + 56)) *(T380_0028e2a8**)(p + 56) = new (func_0013a1d8()) T380_0028e2a8[n];
    *(s32*)(p + 24) = n;
}
}  // namespace n0028e2a8

// 0028e350 (from src/anon/batch_w46.cpp)
namespace n0028e350 {
void func_00239870(void*) asm("func_00239870");
// 380-byte element destroyed by func_00239870 (array new/delete with a 4-byte count cookie).
struct Elem28e {
    u8 d[380];
    ~Elem28e() { func_00239870(this); }
};
void operator delete[](void*) asm("func_00106450");
void ctarget_0028e350(u8* p, u32, u32, u32) asm("_Z16ctarget_0028e350jjjj");
// ---- 0028e350
void ctarget_0028e350(u8* p, u32, u32, u32) asm("_Z16ctarget_0028e350jjjj");
void ctarget_0028e350(u8* p, u32, u32, u32) {
    if (*(Elem28e**)(p + 56)) {
        delete[] *(Elem28e**)(p + 56);
        *(Elem28e**)(p + 56) = 0;
    }
}
}  // namespace n0028e350

// 0028e3b8 (from src/anon/auto80_199_queue.cpp)
namespace n0028e3b8 {
u32 func_00139d78(...) asm("func_00139d78");
struct Obj_0028e3b8 {
    u8 pad0[56];

u32 field56;

};
u32 YI__SEQUENCE__Init(...) asm("YI__SEQUENCE__Init");
void func_0028e438(u32, u32, u32, s32) asm("func_0028e438");
void func_0028e3b8(Obj_0028e3b8* self, u32 idx, u32 a2, u32 a3, u32 a4) asm("_ZN2Tz8MultiSeq7InitSqdEiPvPN2YI5IMAGEEi");
void func_0028e3b8(Obj_0028e3b8* self, u32 idx, u32 a2, u32 a3, u32 a4) {
    func_00139d78((u32)self);
    YI__SEQUENCE__Init(self->field56 + idx * 380, a2, a3);
    func_0028e438((u32)self, idx, a4, -1);
}
}  // namespace n0028e3b8

// 0028e438 (from src/anon/batch_w53.cpp)
namespace n0028e438 {
u32 func_00139d78(u8*) asm("func_00139d78");
void func_00239bf8(u32, u32) asm("func_00239bf8");
void func_0028e438(u8* p, s32 i, u32 v, u32 w) asm("func_0028e438");
void func_0028e438(u8* p, s32 i, u32 v, u32 w) {
    func_00139d78(p);
    u32 off = i * 380;
    u32 e = off + *(u32*)(p + 56);
    if (*(u32*)(e + 344) != v) {
        *(u32*)(e + 344) = v;
        func_00239bf8(*(u32*)(p + 56) + off, v);
    }
    *(u32*)(off + *(u32*)(p + 56) + 348) = w;
    *(u8*)(off + *(u32*)(p + 56) + 352) = 0;
}
}  // namespace n0028e438

// 0028e4c8 (from src/anon/tiny_auto80_solver.cpp)
namespace n0028e4c8 {
u32 func_00139d78(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e4c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0028e4c8");
u32 func_0028e4c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15, r16, r17;
    r16 = r5;
    r17 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00139d78)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)((s32)0u + (380));
    r16 = (u32)(r16 * r15);
    r14 = *(u32*)((u32)r17 + (s32)(56));
    r16 = (u32)(r16 + r14);
    r2 = *(u32*)((u32)r16 + (s32)(344));
    return r2;
}
}  // namespace n0028e4c8

// 0028e510 (from src/anon/tiny_auto80_solver.cpp)
namespace n0028e510 {
u32 func_00139d78(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e510(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0028e510");
u32 func_0028e510(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // entry_ptr_large
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15, r16, r17, r18;
    r16 = r5;
    r17 = r4;
    r18 = r6;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00139d78)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)((s32)0u + (380));
    r16 = (u32)(r16 * r15);
    r14 = *(u32*)((u32)r17 + (s32)(56));
    r16 = (u32)(r16 + r14);
    *(u32*)((u32)r16 + (s32)(348)) = r18;
    return r2;
}
}  // namespace n0028e510

// 0028e560 (from src/anon/batch_w63.cpp)
namespace n0028e560 {
s32 func_00139d78(void*) asm("func_00139d78");
void func_0028e438(void*, s32, s32, u32) asm("func_0028e438");
void func_0028e560(void* p, s16* a, s32 n, u32 a3) asm("func_0028e560");
void func_0028e560(void* p, s16* a, s32 n, u32 a3) {
    func_00139d78(p);
    for (s32 i = 0; i < n; i++) func_0028e438(p, i, *a++, a3);
}
}  // namespace n0028e560

// 0028e5e0 (from src/anon/batch_w43.cpp)
namespace n0028e5e0 {
s32 func_00139d78(void*) asm("func_00139d78");
void func_0028e510(void*, s32, s32) asm("func_0028e510");
void func_0028e5e0(void* a, s16* l, s32 n) asm("func_0028e5e0");
void func_0028e5e0(void* a, s16* l, s32 n) {
    func_00139d78(a);
    for (s32 i = 0; i < n; i++) func_0028e510(a, i, l[i]);
}
}  // namespace n0028e5e0

// 0028e650 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0028e650 {
u32 func_00139d78(u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e650(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0028e650");
u32 func_0028e650(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00139d78(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r16 + (s32)(24));
    return r2;
}
}  // namespace n0028e650

// 0028e678 (from src/anon/tiny_auto80_solver.cpp)
namespace n0028e678 {
u32 func_00139d78(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e678(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0028e678");
u32 func_0028e678(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15, r16, r17;
    r16 = r5;
    r17 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00139d78)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)((s32)0u + (380));
    r16 = (u32)(r16 * r15);
    r14 = *(u32*)((u32)r17 + (s32)(56));
    r16 = (u32)(r16 + r14);
    return *(u8*)((u32)r16 + (s32)(352));
}
}  // namespace n0028e678

// 0028e6c0 (from src/anon/batch_w26.cpp)
namespace n0028e6c0 {
// set_bit_in_array_b
bool u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
s32 seq_get_loop_mode(void*, s32) asm("_ZN2YI8SEQUENCE11GetLoopModeEi");
extern void (*D_01dae41c)(u32) asm("void");
u8 func_0028e6c0(u8* o, s32 i) asm("func_0028e6c0");
u8 func_0028e6c0(u8* o, s32 i) {
    u_call4_00139d78(o);
    u8* s = *(u8**)(o + 56) + i * 380;
    return seq_get_loop_mode(s, *(s32*)(s + 276));
}
}  // namespace n0028e6c0

// 0028e710 (from src/anon/batch_w14.cpp)
namespace n0028e710 {
void u_call4_00139d78(u32) asm("_Z16u_call4_00139d78jjjj");
void func_0028e710(u32 p, u32 a) asm("func_0028e710");
void func_0028e710(u32 p, u32 a) {
    u_call4_00139d78(p);
    *(u32*)(p + 48) = a;
}
}  // namespace n0028e710

// 0028e748 (from src/anon/tiny_auto80_solver.cpp)
namespace n0028e748 {
u32 func_00139d78(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e748(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0028e748");
u32 func_0028e748(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15, r16, r17, r18;
    r16 = r5;
    r17 = r4;
    r18 = r6;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00139d78)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)((s32)0u + (380));
    r16 = (u32)(r16 * r15);
    r14 = *(u32*)((u32)r17 + (s32)(56));
    r16 = (u32)(r16 + r14);
    *(u32*)((u32)r16 + (s32)(376)) = r18;
    return r2;
}
}  // namespace n0028e748

// 0028e798 (from src/anon/tiny_auto80_solver.cpp)
namespace n0028e798 {
u32 func_00139d78(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e798(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0028e798");
u32 func_0028e798(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16, r17;
    r16 = r5;
    r17 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00139d78)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)((s32)0u + (380));
    r16 = (u32)(r16 * r15);
    r2 = *(u32*)((u32)r17 + (s32)(56));
    r2 = (u32)(r2 + r16);
    return r2;
}
}  // namespace n0028e798

// 0028e7d8 (from src/anon/tiny_auto80_solver.cpp)
namespace n0028e7d8 {
u32 func_00139d78(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e7d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0028e7d8");
u32 func_0028e7d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16, r17, r18;
    r16 = r4;
    r17 = r6;
    r18 = r5;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00139d78)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(28)) = r18;
    *(u32*)((u32)r16 + (s32)(32)) = r17;
    return r2;
}
}  // namespace n0028e7d8

// 0028e820 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0028e820 {
u32 func_00139d78(u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e820(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0028e820");
u32 func_0028e820(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u, r17 = 0u, r18 = 0u;
    r16 = r4;
    r17 = r5;
    r18 = r6;
    r2 = func_00139d78(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(28));
    *(u32*)((u32)r17 + (s32)(0)) = r15;
    r14 = *(u32*)((u32)r16 + (s32)(32));
    *(u32*)((u32)r18 + (s32)(0)) = r14;
    return r2;
}
}  // namespace n0028e820

// 0028e870 (from src/anon/tiny_auto80_solver.cpp)
namespace n0028e870 {
u32 func_00139d78(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e870(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0028e870");
u32 func_0028e870(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16, r17, r18;
    r16 = r4;
    r17 = r6;
    r18 = r5;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00139d78)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(36)) = r18;
    *(u32*)((u32)r16 + (s32)(40)) = r17;
    return r2;
}
}  // namespace n0028e870

// 0028e8b8 (from src/anon/auto80_199_queue.cpp)
namespace n0028e8b8 {
u32 func_00139d78(...) asm("func_00139d78");
struct Obj_0028e8b8 {
    u8 pad0[56];

u32 field56;

};
void func_0028e8b8(Obj_0028e8b8* self, u32 idx, u32 v2, u32 v3) asm("func_0028e8b8");
void func_0028e8b8(Obj_0028e8b8* self, u32 idx, u32 v2, u32 v3) {
    func_00139d78((u32)self);
    u32 stride = 380;
    u32 off = idx * stride;
    u32 base = self->field56;
    *(u32*)((off + base) + 360) = v2;
    u32 base2 = self->field56;
    *(u32*)((off + base2) + 364) = v3;
}
}  // namespace n0028e8b8

// 0028e920 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0028e920 {
u32 func_00139d78(u32, u32, u32, u32) asm("func_00139d78");
u32 func_0028e920(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0028e920");
u32 func_0028e920(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u, r17 = 0u, r18 = 0u;
    r16 = r4;
    r17 = r5;
    r18 = r6;
    r2 = func_00139d78(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(36));
    *(u32*)((u32)r17 + (s32)(0)) = r15;
    r14 = *(u32*)((u32)r16 + (s32)(40));
    *(u32*)((u32)r18 + (s32)(0)) = r14;
    return r2;
}
}  // namespace n0028e920

// 0028e970 (from src/anon/auto80_199_queue.cpp)
namespace n0028e970 {
u32 func_00139d78(...) asm("func_00139d78");
struct Obj_0028e970 {
    u8 pad0[28];

u32 field28;

u32 field32;

u32 field36;

u32 field40;

};
void func_0028e970(Obj_0028e970* self, u32* out1, u32* out2) asm("func_0028e970");
void func_0028e970(Obj_0028e970* self, u32* out1, u32* out2) {
    func_00139d78((u32)self);
    *out1 = self->field28 + self->field36;
    *out2 = self->field32 + self->field40;
}
}  // namespace n0028e970

// 0028e9d0 (from src/anon/auto80_199_queue.cpp)
namespace n0028e9d0 {
u32 func_0023a9c0(...) asm("func_0023a9c0");
u32 func_00139d78(...) asm("func_00139d78");
struct Obj_0028e9d0 {
    u8 pad0[56];

u32 field56;

};
void func_0028e9d0(Obj_0028e9d0* self, u32 idx, u32 a2, u32 a3) asm("func_0028e9d0");
void func_0028e9d0(Obj_0028e9d0* self, u32 idx, u32 a2, u32 a3) {
    func_00139d78((u32)self);
    func_0023a9c0(self->field56 + idx * 380, a2, a3);
}
}  // namespace n0028e9d0

// 0028ea30 (from src/anon/auto80_199_queue.cpp)
namespace n0028ea30 {
u32 func_0023a9c0(...) asm("func_0023a9c0");
u32 func_00139d78(...) asm("func_00139d78");
struct Obj_0028ea30 {
    u8 pad0[36];

u32 field36;

u32 field40;

u8 pad1[12];

u32 field56;

};
void func_0028ea30(Obj_0028ea30* self, u32 idx, u32* p0, u32* p1) asm("func_0028ea30");
void func_0028ea30(Obj_0028ea30* self, u32 idx, u32* p0, u32* p1) {
    func_00139d78((u32)self);
    func_0023a9c0(self->field56 + idx * 380, (u32)p0, (u32)p1);
    *p0 += self->field36;
    *p1 += self->field40;
}
}  // namespace n0028ea30

// 0028eab8 (from src/anon/batch_w27.cpp)
namespace n0028eab8 {
u32 func_0023aa18(void*) asm("func_0023aa18");
u32 func_0023aa38(void*) asm("func_0023aa38");
void Tz__MultiSeq__setParamXYToOffset(u8* d, u8* s) asm("Tz__MultiSeq__setParamXYToOffset");
void Tz__MultiSeq__setParamXYToOffset(u8* d, u8* s) {
    u8* q = s + 24;
    *(u32*)(d + 36) = func_0023aa18(q);
    *(u32*)(d + 40) = func_0023aa38(q);
}
}  // namespace n0028eab8

// 0028eb00 (from src/anon/tiny_auto80_queue.cpp)
namespace n0028eb00 {
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
void func_0028eb00(void* a0, f32 a1) asm("func_0028eb00");
void func_0028eb00(void* a0, f32 a1) {
    u8* s0 = (u8*)a0;
    f32 f20 = a1;
    func_00139d78(s0);
    *(f32*)(s0 + 44) = f20;
}
}  // namespace n0028eb00

// 0028eb38 (from src/anon/tiny_auto80_queue.cpp)
namespace n0028eb38 {
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
void func_0028eb38(void* a0, s32 a1, f32 a2) asm("func_0028eb38");
void func_0028eb38(void* a0, s32 a1, f32 a2) {
    u8* s1 = (u8*)a0;
    s32 s0 = a1;
    f32 f20 = a2;
    func_00139d78(s1);
    s0 = s0 * 380;
    s0 = s0 + *(s32*)(s1 + 56);
    *(f32*)((u8*)s0 + 356) = f20;
}
}  // namespace n0028eb38

// 0028eb88 (from src/anon/batch_w39.cpp)
namespace n0028eb88 {
// Word accessed through a union: gcc treats it as aliasing everything, which
// reproduces the reloads / ordering the original shows at these sites.
union Word { f32 f; u32 u; };
// --- 0028eb88
struct I28e { u8 pad[368]; Word x, y; u8 pad2[4]; };
struct S28e { u8 pad[56]; I28e* items; };
void func_00139d78_28e(S28e*, int) asm("func_00139d78");
void func_0028eb88(S28e* p, int i, f32 a, f32 b) asm("func_0028eb88");
void func_0028eb88(S28e* p, int i, f32 a, f32 b) {
    func_00139d78_28e(p, i);
    p->items[i].x.f = a;
    p->items[i].y.f = b;
}
}  // namespace n0028eb88

// 0028ebf0 (from src/tz/ui_accessors.cpp)
namespace Tz {
void MultiSeq::setExMode(s32 v) { reinterpret_cast<MultiSeqLayout*>(this)->exMode = v; }
}  // namespace Tz

// 0028ebf8 (from src/anon/batch_w1604.cpp)
namespace n0028ebf8 {
struct Ent { u8 p0[276]; s32 f114; u8 p118[68]; s32 f15c; u8 f160; u8 p161[3]; f32 f164; u8 p168[8]; f32 f170; f32 f174; s32 f178; };
struct Obj;
typedef void (*VFn)(Obj*);
struct Obj { VFn* vt; u8 p4[8]; u32 flags; u8 p10[8]; s32 n; u8 p1c[16]; f32 f2c; void* sub; u8 p34[4]; Ent* ents; };
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00239d10(s32) asm("func_00239d10");
void func_00139570(Obj*) asm("func_00139570");
void YI__SEQUENCE__SetScaleX(f32, Ent*) asm("YI__SEQUENCE__SetScaleX");
void func_00239f78(f32, Ent*) asm("func_00239f78");
void func_00239eb8(f32, Ent*) asm("func_00239eb8");
void func_0023acd8(Ent*) asm("func_0023acd8");
s32 func_00239d30(Ent*, s32) asm("func_00239d30");
s32 func_00239d10e(Ent*) asm("func_00239d10");
void func_0028e438(Obj*, s32, s32, s32) asm("func_0028e438");
void func_0028ebf8(Obj* o) asm("func_0028ebf8");
void func_0028ebf8(Obj* o)
{
    if (o->flags & 0x100) return;
    if (o->sub && !func_00139d78(o->sub)) {
        o->vt[5](o);
        return;
    }
    for (s32 i = 0; i < o->n; i++) {
        if (!func_00139d78(o)) return;
        if (o->ents[i].f178 && !func_00239d10(o->ents[i].f178)) {
            if (o->flags & 0x80) func_00139570(o);
            else o->vt[5](o);
            return;
        }
        { Ent* e = &o->ents[i]; YI__SEQUENCE__SetScaleX(e->f170, e); }
        { Ent* e = &o->ents[i]; func_00239f78(e->f174, e); }
        { Ent* e = &o->ents[i]; func_00239eb8(e->f164 * o->f2c, e); }
        func_0023acd8(&o->ents[i]);
        if (o->ents[i].f160) o->ents[i].f160 = 0;
        if (!(u8)func_00239d30(&o->ents[i], o->ents[i].f114) && !func_00239d10e(&o->ents[i])) {
            if (o->ents[i].f15c != -1) {
                func_0028e438(o, i, o->ents[i].f15c, -1);
                func_0023acd8(&o->ents[i]);
                o->ents[i].f160 = 1;
            } else {
                if (o->flags & 0x80) func_00139570(o);
                else o->vt[5](o);
            }
        }
    }
}
}  // namespace n0028ebf8


// 0028edf0 (was gap, written for the unit): Tz::MultiSeq draw pass: positions and colours of each sequence
namespace n0028edf0 {
// gcc's soft-float libcalls bound to the game's copies
asm("fptodp = func_00313b80");
asm("dpmul = func_00313f40");
asm("dptofp = __truncdfsf2");
struct Seq { u8 p0[280]; f32 r; f32 g; f32 b; u8 p124[36]; s32 x; s32 y; u8 p150[24]; s32 ox; s32 oy; u8 p170[8]; Seq* parent; };
struct Obj { void* vt; u8 p4[8]; u32 flags; u8 p10[8]; s32 n; s32 x; s32 y; s32 ox; s32 oy; u8 p2c[4]; u8* sub; s32 align; Seq* ents; };
s32 func_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void getSeqActiveXYAddOffset(void*, s32*, s32*) asm("_ZN2dk6Sprite23getSeqActiveXYAddOffsetERiS1_");
void getPos(void*, s32*, s32*) asm("_ZN2dk6Sprite6getPosERiS1_");
s32 GetPlayMode(Seq*) asm("_ZN2YI8SEQUENCE11GetPlayModeEv");
void GetActiveXY(Seq*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
u32 GetActiveRGBA(void*) asm("_ZN2YI8SEQUENCE13GetActiveRGBAEv");
void SetRGBA(Seq*, f32, f32, f32, f32) asm("_Z16wtarget_00239fd0jjjj");
void YI__SEQUENCE__Draw(Seq*) asm("YI__SEQUENCE__Draw");
s32 GetParamEx(Seq*) asm("_ZN2YI8SEQUENCE10GetParamExEv");
void func_0028edf0(Obj* o) asm("func_0028edf0");
void func_0028edf0(Obj* o)
{
    s32 ax, ay, bx, by;
    s32 i;
    s32 x, y;
    if (o->sub && !func_00139d78(o->sub)) return;
    if (o->sub) {
        getSeqActiveXYAddOffset(o->sub, &ax, &ay);
        getPos(o->sub, &bx, &by);
        o->x = bx + ax;
        o->y = by + ay;
    }
    x = o->x + o->ox;
    y = o->y + o->oy;
    for (i = 0; i < o->n; i++) {
        s32 px = x;
        s32 py = y;
        if (o->ents[i].parent) {
            if (!GetPlayMode(o->ents[i].parent)) return;
            GetActiveXY(o->ents[i].parent, &ax, &ay);
            Seq* p = o->ents[i].parent;
            bx = p->x;
            px = ax + bx;
            by = p->y;
            py = ay + by;
        }
        if ((o->sub || o->ents[i].parent) && (o->flags & 0x200)) {
            void* q = o->sub;
            if (q) q = (u8*)q + 24; else q = o->ents[i].parent;
            u32 c = GetActiveRGBA(q);
            Seq* e = &o->ents[i];
            f32 r = e->r;
            f32 g = e->g;
            f32 b = e->b;
            f32 a = (f32)(c >> 24) / 128.0;
            if (!(o->flags & 0x400)) {
                r = (f32)(c & 0xff) / 128.0;
                g = (f32)((c & 0xff00) >> 8) / 128.0;
                b = (f32)((c & 0xff0000) >> 16) / 128.0;
            }
            SetRGBA(&o->ents[i], r, g, b, a);
        }
        {
            Seq* e = &o->ents[i];
            e->x = px + e->ox;
            e->y = py + e->oy;
            YI__SEQUENCE__Draw(e);
        }
        s32 d = GetParamEx(&o->ents[i]);
        switch (o->align) {
        case 1: x += d; break;
        case 2: y += d; break;
        case 3: x -= d; break;
        case 4: y -= d; break;
        }
    }
}
}  // namespace n0028edf0
