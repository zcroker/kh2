// Linked unit (see linked_units.tsv); one namespace per old matched source.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include <stdarg.h>
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

// 002b3ac8 (was src/tozawa/jm_puzzle.cpp)
namespace n002b3ac8 {
extern s8 D_00374cd0[] asm("D_00374cd0");
/*TARGET 002b3ac8*/
// 0x002aeb28: definition moved into src/anon/unit_002aeb28.cpp

u32 JmPuzzle_CalcMaxPiece(s32 a0) asm("_ZN2Tz8JmPuzzle12CalcMaxPieceEi");
u32 JmPuzzle_CalcMaxPiece(s32 a0) {
    s8* p = (s8*)((u8*)&D_00374cd0 + (a0 << 2));
    return (s32)p[0] * (s32)p[1];
}
}  // namespace n002b3ac8

// 002b3ae8 (was src/anon/batch_w38.cpp)
namespace n002b3ae8 {
void* func_001d9e30(void*) asm("func_001d9e30");
// record_range_check_or_first
s32 func_001d9d48(void*) asm("func_001d9d48");
s32 func_00276c18(void) asm("func_00276c18");
/*TARGET 002b3ae8*/
s32 Tz__JmPuzzle__isEnable(void) asm("Tz__JmPuzzle__isEnable");
s32 Tz__JmPuzzle__isEnable(void) {
    void* p = 0;
    s32 found = 0;
    while ((p = func_001d9e30(p)) != 0) {  // record_range_check_or_first
        if (func_001d9d48(p)) {
            found = 1;
            break;
        }
    }
    return found || func_00276c18();
}
}  // namespace n002b3ae8

// 002b3b60 (was src/anon/tiny.cpp)
namespace n002b3b60 {
extern u32 D_00374cb0 asm("D_00374cb0");
/*TARGET 002b3b60*/
// 0x0029ae30: definition moved into src/anon/unit_00299920.cpp

u32 func_002b3b60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002b3b60jjjj");
// 0x0029ae30: definition moved into src/anon/unit_00299920.cpp

u32 func_002b3b60(u32 a0, u32 a1, u32 a2, u32 a3) {  // halfword_table_374cb0
    (void)a1;
    (void)a2;
    (void)a3;
    return *(u16*)((u32)&D_00374cb0 + ((u32)a0 << 2) + (0));
}
}  // namespace n002b3b60

// 002b3b78 (was src/anon/batch_wcx2.cpp)
namespace n002b3b78 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
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
// 0x0029ecf0: definition moved into src/anon/unit_0029d008.cpp

// --------------------
struct E2b3b78 { s32 flags; u8 pad[32]; };
extern E2b3b78* D_0035f630 asm("D_0035f630");
s32 func_00287bc0() asm("func_00287bc0");
/*TARGET 002b3b78*/
s32 func_002b3b78(s32 a) asm("func_002b3b78");
s32 func_002b3b78(s32 a) {
    s32 r = 0;
    if (a < 0) return 1;
    switch (func_00287bc0()) {
    case 28: {
        E2b3b78* e = D_0035f630;
        s32 j = 0;
        s32 i;
        for (i = 0; i < 10; i++, e++) {
            if (e->flags & 0x1000000) {
                if (j == a) {
                    r = (e->flags >> 25) & 1;
                    break;
                }
                j++;
            }
        }
        break;
    }
    case 27: case 30:
        r = 1;
        break;
    case 29: case 31: case 32: case 33:
        r = 0;
        break;
    }
    return r;
}
}  // namespace n002b3b78

// 002b3c38 (was src/anon/batch_w78.cpp)
namespace n002b3c38 {
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
u8* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
u8* w78_9d68(void) asm("func_002a9d68");
s32 func_002b2380(s16, s16) asm("func_002b2380");
extern u8* D_0035f638 asm("D_0035f638");
/*TARGET 002b3c38*/
s32 Tz__JmPuzzle__GameSelCheck(u32 mask) asm("Tz__JmPuzzle__GameSelCheck");
s32 Tz__JmPuzzle__GameSelCheck(u32 mask) {
    s32 r = 1;
    u8* a = Tz__JmPuzzle__GetImageInfo(-1);  // list_entry_by_index_checked
    u8* b = w78_9d68();
    u8* t = D_0035f638;
    s32 k = (*(u32*)(t + 52) >> 10) & 2;
    u8* tk = (u8*)k + (u32)t;
    s32 v = func_002b2380(*(s16*)(tk + 28), *(s16*)(tk + 32));
    s8 x = *(s8*)(b + (a[2] * 48 + v) * 4 + 488);
    if ((mask & 0xc0004) && !(*(u32*)(D_0035f638 + 52) & 0x800)) r = x >= 0;
    return r;
}
}  // namespace n002b3c38

// 002b3d00 (was src/anon/batch_w86.cpp)
namespace n002b3d00 {
struct Alloc;
typedef void* (*AFn)(Alloc*, s32, s32);
struct Alloc { AFn* vt; };
struct Sys { u8 p0[20]; Alloc* alloc; };
union SysP { Sys* p; u32 u; };
struct T { u32 vt; u8 p4[8]; u32 f12; u8 p16[60]; };
struct Obj { u32 a; u32 b; u32 c; };
extern SysP g_sys asm("D_00347f80");
extern u8 D_0035ebb8[] asm("D_0035ebb8");
static inline T* NewT(void* p)
{
    T* t = (T*)p;
    t->f12 = 0;
    t->vt = (u32)D_0035ebb8;
    return t;
}
/*TARGET 002b3d00*/
void func_002b3d00(Obj* o) asm("func_002b3d00");
void func_002b3d00(Obj* o)
{
    o->a = 0;
    o->b = 0;
    o->c = 0;
    o->a = (u32)NewT(g_sys.p->alloc->vt[0](g_sys.p->alloc, 76, 0));
    u32* y = (u32*)g_sys.p->alloc->vt[0](g_sys.p->alloc, 232, 0);
    y[0] = 3;
    T* e = (T*)(y + 1);
    T* p = e;
    for (s32 k = 2; k != -1; k--, p++) NewT(p);
    o->b = (u32)e;
    o->c = (u32)NewT(g_sys.p->alloc->vt[0](g_sys.p->alloc, 76, 0));
}
}  // namespace n002b3d00

// 002b3df8 (was src/anon/batch_w87.cpp)
namespace n002b3df8 {
// 0x0029c880: definition moved into src/anon/unit_0029ba88.cpp

// ---- 0x2b3df8: allocates one object, an array of three, and one more ----
typedef void* (*AllocFn)(void*, s32, s32);
union GA { u8* p; u32 u; void* v; };
extern GA D_00347f80 asm("D_00347f80");
extern u8 D_0035ebb8[] asm("D_0035ebb8");
struct T76 { void* vt; u32 f4, f8, f12; u8 pad[60]; };
static inline void* alloc76(s32 n) {
    void* a = *(void**)(D_00347f80.p + 20);
    return (*(AllocFn*)(*(u8**)a))(a, n, 0);
}
/*TARGET 002b3df8*/
void func_002b3df8(GA* p) asm("func_002b3df8");
void func_002b3df8(GA* p) {
    p[0].u = 0;
    p[1].u = 0;
    p[2].u = 0;
    T76* o = (T76*)alloc76(76);
    o->f12 = 0;
    *(u32*)o = (u32)D_0035ebb8;
    p[0].v = o;
    u32* q = (u32*)alloc76(232);
    q[0] = 3;
    T76* e = (T76*)(q + 1);
    T76* it = e;
    for (s32 n = 2; n != -1; n--, it++) {
        it->f12 = 0;
        it->vt = D_0035ebb8;
    }
    p[1].v = e;
    o = (T76*)alloc76(76);
    o->f12 = 0;
    o->vt = D_0035ebb8;
    p[2].v = o;
}
}  // namespace n002b3df8

// 002b3ef0 (was src/anon/batch_w89.cpp)
namespace n002b3ef0 {
struct Heap { void (**vt)(Heap*, void*); };
struct HeapHolder { u8 pad[20]; Heap* heap; };
extern "C" HeapHolder* D_00347f80;
struct Elem76 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Elem76();
    u8 pad[72];
    static void operator delete[](void* p) { D_00347f80->heap->vt[1](D_00347f80->heap, p); }
};
struct VB { void (**vt)(VB*); };
struct Res3 { VB* a; Elem76* arr; VB* c; };
/*TARGET 002b3ef0*/
// Releases the three owned resources.
void func_002b3ef0(Res3* r) asm("func_002b3ef0");
// Releases the three owned resources.
void func_002b3ef0(Res3* r) {
    if (r->a) { r->a->vt[4](r->a); r->a = 0; }
    if (r->arr) {
        delete[] r->arr;
        r->arr = 0;
    }
    if (r->c) { r->c->vt[4](r->c); r->c = 0; }
}
}  // namespace n002b3ef0

// 002b3fb0 (was src/anon/batch_w90.cpp)
namespace n002b3fb0 {
struct VObj { void** vt; };
// 0x00285760: definition moved into src/anon/unit_002853b8.cpp

// 00290098
union HeapRef { u8* p; u32 w; };
extern HeapRef D_00347f80 asm("D_00347f80");
// 002b3fb0: release the three owned objects (the middle one is an array).
typedef void (*FreeFn)(void*, void*);
class W90Part {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual ~W90Part();
    u8 body[72];
    static void operator delete[](void* p) { VObj* al = *(VObj**)(D_00347f80.p + 20); ((FreeFn)al->vt[1])(al, p); }
};
class W90Res {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual ~W90Res();
};
struct W90Owner { W90Res* a; W90Part* parts; W90Res* c; };
/*TARGET 002b3fb0*/
void func_002b3fb0(W90Owner* self) asm("func_002b3fb0");
void func_002b3fb0(W90Owner* self)
{
    if (self->a) { delete self->a; self->a = 0; }
    if (self->parts) { delete[] self->parts; self->parts = 0; }
    if (self->c) { delete self->c; self->c = 0; }
}
}  // namespace n002b3fb0

// 002b4070 (was src/anon/batch_w2418.cpp)
namespace n002b4070 {
struct W2418M2b4 { u8 pad[0x4c]; };
struct W2418O2b4 { W2418M2b4* a; W2418M2b4* b; W2418M2b4* c; };
struct W2418P2b4 { u8 pad[0x14]; u16 h[4]; };
void Tz__LayMsg__create(W2418M2b4*, s32, s32, s32, void*, s32, s32, s32) asm("Tz__LayMsg__create");
s32 func_0023f7d8(W2418M2b4*) asm("func_0023f7d8");
s32 func_0023aa98(s32) asm("func_0023aa98");
s32 func_0028dd90(s32) asm("func_0028dd90");
s32 func_0028ddd8(s32) asm("func_0028ddd8");
void func_0023f6c0(W2418M2b4*, s32) asm("func_0023f6c0");
void func_0023f688(W2418M2b4*, s32) asm("func_0023f688");
void func_001395f8(W2418M2b4*) asm("func_001395f8");
/*TARGET 002b4070*/
void func_002b4070(W2418O2b4* o, s32 a1, s32 a2, s32 a3, void* e0, void* e1, void* e2, void* e3, void* e4, s32 c0, W2418P2b4* p, s32 x, s32 y) asm("func_002b4070");
void func_002b4070(W2418O2b4* o, s32 a1, s32 a2, s32 a3, void* e0, void* e1, void* e2, void* e3, void* e4, s32 c0, W2418P2b4* p, s32 x, s32 y) {
    s32 v;
    if (e0) {
        Tz__LayMsg__create(o->a, a1, a2, a3, e0, c0, x, y);
        v = func_0023aa98(func_0023f7d8(o->a));
        func_0023f6c0(o->a, func_0028dd90(v));
        func_0023f688(o->a, func_0028ddd8(v));
        func_001395f8(o->a);
    }
    if (e1) {
        Tz__LayMsg__create(o->b, a1, a2, a3, e1, p->h[0], x, y);
        v = func_0023aa98(func_0023f7d8(o->b));
        func_0023f6c0(o->b, func_0028dd90(v));
        func_0023f688(o->b, func_0028ddd8(v));
        func_001395f8(o->b);
    }
    if (e2) {
        Tz__LayMsg__create(&o->b[1], a1, a2, a3, e2, p->h[1], x, y);
        v = func_0023aa98(func_0023f7d8(&o->b[1]));
        func_0023f6c0(&o->b[1], func_0028dd90(v));
        func_0023f688(&o->b[1], func_0028ddd8(v));
        func_001395f8(&o->b[1]);
    }
    if (e3) {
        Tz__LayMsg__create(&o->b[2], a1, a2, a3, e3, p->h[2], x, y);
        v = func_0023aa98(func_0023f7d8(&o->b[2]));
        func_0023f6c0(&o->b[2], func_0028dd90(v));
        func_0023f688(&o->b[2], func_0028ddd8(v));
        func_001395f8(&o->b[2]);
    }
    if (e4) {
        Tz__LayMsg__create(o->c, a1, a2, a3, e4, p->h[3], x, y);
        v = func_0023aa98(func_0023f7d8(o->c));
        func_0023f6c0(o->c, func_0028dd90(v));
        func_0023f688(o->c, func_0028ddd8(v));
        func_001395f8(o->c);
    }
}
}  // namespace n002b4070

// 002b4370 (was src/anon/tiny.cpp)
namespace n002b4370 {
void func_0023f5b8(s32) asm("_Z13func_0023f5b8i");
/*TARGET 002b4370*/
// 00290420: moved to src/anon/unit_0028f1e0.cpp
void func_002b4370(BD_VALUE* bd) asm("_Z13func_002b4370P8BD_VALUE");
// 00290420: moved to src/anon/unit_0028f1e0.cpp
void func_002b4370(BD_VALUE* bd) { func_0023f5b8(bd->i); }
}  // namespace n002b4370

// 002b4388 (was src/anon/auto80_199_queue.cpp)
namespace n002b4388 {
/*TARGET 002b4388*/
// 0x002b2380: definition moved into src/anon/unit_002b1db8.cpp

void func_002b4388(Obj4388* a0, u8* a1, u32 a2) asm("_Z13func_002b4388P7Obj4388Phj");
// 0x002b2380: definition moved into src/anon/unit_002b1db8.cpp

void func_002b4388(Obj4388* a0, u8* a1, u32 a2) {
    u8* s0 = a1 + 20;
    s32 s1 = 2;
    u32 s2 = 0;

    do {
        u32 t7 = *(u16*)(s0 + 0);
        s0 += 2;
        if (t7 != 0) {
            func_0023f5b8((void*)(a0->p4 + s2), t7, a2);
        }
        s1 -= 1;
        s2 += 76;
    } while (s1 >= 0);

    u32 v = *(u16*)(a1 + 26);
    if (v != 0) {
        func_0023f5b8((void*)a0->p8, v, a2);
    }
}
}  // namespace n002b4388

// 002b4440 (was src/anon/batch_w3867_g.cpp)
namespace n002b4440 {
struct Heap { virtual void* Alloc(u32 n, void* ra); };
extern u32 D_00347f80 asm("D_00347f80");
typedef void* (*AllocFn)(u32, u32, void*);
extern Heap* D_0032ba14 asm("D_0032ba14");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035f360[] asm("D_0035f360");
void func_0014a4b0(void) asm("func_0014a4b0");
s32 func_00103570(void) asm("func_00103570");
void func_0023fd40(s32) asm("func_0023fd40");
void func_00240b90(s32) asm("func_00240b90");
void func_00233ce0(void) asm("func_00233ce0");
void func_00287b18(s32, s32) asm("func_00287b18");
void func_0028d068(s32, s32) asm("func_0028d068");
void* func_00288be8(u32) asm("func_00288be8");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
void func_00288f48(void*, s32, s32, s32, s32) asm("func_00288f48");
void func_00239700(void*) asm("func_00239700");
void* func_001063f0(s32, s32) asm("func_001063f0");
void func_0028b9b0(void*) asm("func_0028b9b0");
void func_0028d140(void*) asm("func_0028d140");
void func_0031a838(void*) asm("func_0031a838");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
struct List { u8 pad[56];
    List(s32 a, s32 b) { func_002889f0(this, a, b); }
    static void* operator new(unsigned int n) { return func_00288be8(n); } };
struct HeapObj { static void* operator new(unsigned int n) { u32 h = *(u32*)(D_00347f80 + 20); return (*(AllocFn*)*(u32*)h)(h, n, 0); } };
struct Work : HeapObj { u32 vt; u8 p4[8]; s32 f0c; u8 p10[8]; u8 m18[384];
    Work() { *(u32*)this = (u32)D_00347e60; f0c = 0; func_00239700(m18); } };
struct WorkEx : Work { s32 f198; u8 pad[24]; WorkEx() { f198 = 0; *(u32*)this = (u32)D_00347e40; } };
struct Obj52 { u8 pad[52]; Obj52() { func_0028b9b0(this); }
    static void* operator new(unsigned int n) { return D_0032ba14->Alloc(n, __builtin_return_address(0)); } };
struct Obj444 : HeapObj { u8 pad[444]; Obj444() { func_0028d140(this); } };
struct Obj460 : HeapObj { u32 vt; u8 p4[8]; s32 f0c; u8 p10[8]; u8 m18[384]; s32 f198; u8 pad[48];
    Obj460() { *(u32*)this = (u32)D_00347f98; func_0031a838(&f0c); *(u32*)this = (u32)D_00347e60; func_00239700(m18); f198 = 0; *(u32*)this = (u32)D_0035f360; } };
extern List* D_0035f64c asm("D_0035f64c");
extern List* D_0035f650 asm("D_0035f650");
extern s32 D_0035f654 asm("D_0035f654");
extern s32 D_0035f658 asm("D_0035f658");
extern void* D_0035f65c asm("D_0035f65c");
extern void* D_0035f660 asm("D_0035f660");
extern s32 D_0035f664 asm("D_0035f664");
extern s32 D_0035f668 asm("D_0035f668");
extern s32 D_0035f66c asm("D_0035f66c");
extern s32 D_0035f670 asm("D_0035f670");
extern s32 D_0035f674 asm("D_0035f674");
extern s32 D_0035f678 asm("D_0035f678");
extern s32 D_0035f67c asm("D_0035f67c");
extern s32 D_0035f680[4] asm("D_0035f680");
extern s32 D_0035f690[3][4] asm("D_0035f690");
extern s32 D_0035f6c0 asm("D_0035f6c0");
extern void* D_0035f6c4 asm("D_0035f6c4");
extern void* D_0035f6c8 asm("D_0035f6c8");
extern u8 D_0035f6d0 asm("D_0035f6d0");
extern s32 D_0035f3d4 asm("D_0035f3d4");
/*TARGET 002b4440*/
void Tz__CmSLBase__Init(void) asm("Tz__CmSLBase__Init");
void Tz__CmSLBase__Init(void)
{
    s32 i, j;
    func_0014a4b0();
    func_0023fd40(func_00103570());
    func_00240b90(0);
    func_00233ce0();
    func_00287b18(25, 3);
    D_0035f664 = 0;
    D_0035f654 = 0;
    D_0035f668 = 0;
    D_0035f66c = 0;
    D_0035f670 = 0;
    D_0035f674 = 0;
    D_0035f678 = 0;
    D_0035f67c = 0;
    D_0035f6d0 = 0;
    func_0028d068(30065, -1);
    for (i = 0; i < 4; i++) D_0035f680[i] = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++) D_0035f690[i][j] = 0;
    D_0035f64c = new List(4, 1);
    D_0035f650 = new List(2, 0);
    func_00288f48(D_0035f650, 128, 64, 0, 0);
    D_0035f654 = (s32)new WorkEx;
    D_0035f658 = (s32)new Work;
    D_0035f65c = func_001063f0(224, func_00103570());
    void** p660 = &D_0035f660;
    *p660 = func_001063f0(160, func_00103570());
    D_0035f678 = (s32)new Obj52;
    D_0035f67c = (s32)new Obj444;
    D_0035f6c0 = (s32)new Obj460;
    D_0035f6c4 = func_001063f0(512, func_00103570());
    void* b = func_001063f0(512, func_00103570());
    void* a = D_0035f6c4;
    asm("" : "+r"(b) : "r"(a));
    D_0035f6c8 = b;
    func_002fde18(a, 0, 512);
    func_002fde18(D_0035f6c8, 0, 512);
    D_0035f3d4 = 30045;
}
}  // namespace n002b4440

// 002b47a0 (was src/anon/batch_wcx2.cpp)
namespace n002b47a0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
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
// 0x002859f0: definition moved into src/anon/unit_002853b8.cpp

// ---- 002b47a0
struct VObj2b4 { void (**vt)(VObj2b4*); };
struct Heap2b4 { void (**vt)(Heap2b4*, void*); };
extern "C" s32 D_0035f648, D_0035f640, D_0035f644;
extern u32 D_0035f6cc asm("D_0035f6cc");
extern void* D_0035f64c asm("D_0035f64c");
extern void* D_0035f650 asm("D_0035f650");
extern VObj2b4* D_0035f654 asm("D_0035f654");
extern VObj2b4* D_0035f658 asm("D_0035f658");
extern void* D_0035f65c asm("D_0035f65c");
extern void* D_0035f660 asm("D_0035f660");
extern u32 D_0035f680[4] asm("D_0035f680");
extern u32 D_0035f690[3][4] asm("D_0035f690");
extern VObj2b4* D_0035f664 asm("D_0035f664");
extern VObj2b4* D_0035f668 asm("D_0035f668");
extern void* D_0035f66c asm("D_0035f66c");
extern void* D_0035f670 asm("D_0035f670");
extern VObj2b4* D_0035f674 asm("D_0035f674");
extern void* D_0035f678 asm("D_0035f678");
extern VObj2b4* D_0035f67c asm("D_0035f67c");
extern VObj2b4* D_0035f6c0 asm("D_0035f6c0");
extern void* D_0035f6c4 asm("D_0035f6c4");
extern void* D_0035f6c8 asm("D_0035f6c8");
extern Heap2b4* D_0032ba14_47a0 asm("D_0032ba14");
void SelectDtor2b4(void* p) asm("_ZN2Tz6SelectD1Ev");
void func_00288c20(void* p) asm("func_00288c20");
void DeleteArr2b4(void* p) asm("_ZdaPv");
void func_0028fdd0(void* p) asm("func_0028fdd0");
void func_00290300(void* p) asm("func_00290300");
void func_0028ba80(void* p) asm("func_0028ba80");
void func_00258ce8(s32 a) asm("func_00258ce8");
void Tz__SelHist__Exit(void) asm("Tz__SelHist__Exit");
void func_002639f8(void) asm("func_002639f8");
void func_0023fdc0(void) asm("func_0023fdc0");
void func_00233e58(void) asm("func_00233e58");
void func_0014a4c0(void) asm("func_0014a4c0");
void ttarget_2b47a0(void) asm("_Z17ttarget0_002b47a0v");
/*TARGET 002b47a0*/
// Tear down everything the memory-card menu created.
void ttarget_2b47a0(void) asm("_Z17ttarget0_002b47a0v");
// Tear down everything the memory-card menu created.
void ttarget_2b47a0(void) {
    D_0035f640 = -1;
    D_0035f644 = -1;
    D_0035f648 = -1;
    D_0035f6cc = 0;
    if (D_0035f64c) {
        void* p = D_0035f64c;
        SelectDtor2b4(p);
        func_00288c20(p);
        D_0035f64c = 0;
    }
    if (D_0035f650) {
        void* p = D_0035f650;
        SelectDtor2b4(p);
        func_00288c20(p);
        D_0035f650 = 0;
    }
    if (D_0035f654) {
        D_0035f654->vt[4](D_0035f654);
        D_0035f654 = 0;
    }
    if (D_0035f658) {
        D_0035f658->vt[4](D_0035f658);
        D_0035f658 = 0;
    }
    if (D_0035f65c) {
        DeleteArr2b4(D_0035f65c);
        D_0035f65c = 0;
    }
    if (D_0035f660) {
        DeleteArr2b4(D_0035f660);
        D_0035f660 = 0;
    }
    s32 i, j;
    for (j = 0; j < 4; j++) D_0035f680[j] = 0;
    for (j = 0; j < 3; j++)
        for (i = 0; i < 4; i++) D_0035f690[j][i] = 0;
    if (D_0035f664) {
        D_0035f664->vt[4](D_0035f664);
        D_0035f664 = 0;
    }
    if (D_0035f668) {
        D_0035f668->vt[4](D_0035f668);
        D_0035f668 = 0;
    }
    if (D_0035f66c) {
        void* p = D_0035f66c;
        func_0028fdd0(p);
        D_0032ba14_47a0->vt[1](D_0032ba14_47a0, p);
        D_0035f66c = 0;
    }
    if (D_0035f670) {
        void* p = D_0035f670;
        func_00290300(p);
        D_0032ba14_47a0->vt[1](D_0032ba14_47a0, p);
        D_0035f670 = 0;
    }
    if (D_0035f674) {
        D_0035f674->vt[1](D_0035f674);
        D_0035f674 = 0;
    }
    if (D_0035f678) {
        void* p = D_0035f678;
        func_0028ba80(p);
        D_0032ba14_47a0->vt[1](D_0032ba14_47a0, p);
        D_0035f678 = 0;
    }
    if (D_0035f67c) {
        D_0035f67c->vt[4](D_0035f67c);
        D_0035f67c = 0;
    }
    if (D_0035f6c0) {
        D_0035f6c0->vt[4](D_0035f6c0);
        D_0035f6c0 = 0;
    }
    if (D_0035f6c4) {
        DeleteArr2b4(D_0035f6c4);
        D_0035f6c4 = 0;
    }
    if (D_0035f6c8) {
        DeleteArr2b4(D_0035f6c8);
        D_0035f6c8 = 0;
    }
    func_00258ce8(0);
    Tz__SelHist__Exit();
    func_002639f8();
    func_0023fdc0();
    func_00233e58();
    func_0014a4c0();
}
}  // namespace n002b47a0

// 002b4ac8 (was src/anon/tiny_more2.cpp)
namespace n002b4ac8 {
extern u32 D_0035f640 asm("D_0035f640");
extern u32 D_0035f644 asm("D_0035f644");
/*TARGET 002b4ac8*/
// 0x0028af78: definition moved into src/anon/unit_00288b00.cpp

void func_002b4ac8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_002b4ac8jjjj");
// 0x0028af78: definition moved into src/anon/unit_00288b00.cpp

void func_002b4ac8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_0035f640 = a0; D_0035f644 = a1; }
}  // namespace n002b4ac8

// 002b4ae0 (was src/anon/tiny.cpp)
namespace n002b4ae0 {
/*TARGET 002b4ae0*/
// 0x00296f90: definition moved into src/anon/unit_00295d28.cpp

void func_002b4ae0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002b4ae0jjjj");
// 0x00296f90: definition moved into src/anon/unit_00295d28.cpp

void func_002b4ae0(u32 a0, u32 a1, u32 a2, u32 a3) {  // store_global_word_b
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-2488)) = (u32)a0;
}
}  // namespace n002b4ae0

// 002b4af0 (was src/anon/tiny.cpp)
namespace n002b4af0 {
/*TARGET 002b4af0*/
void func_002b4af0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002b4af0jjjj");
void func_002b4af0(u32 a0, u32 a1, u32 a2, u32 a3) {  // store_global_word
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-2356)) = (u32)a0;
}
}  // namespace n002b4af0

// 002b4b00 (was src/anon/batch_w98.cpp)
namespace n002b4b00 {
u8* func_002891b8(u8*, s32) asm("func_002891b8");
// 0x002633a8: definition moved into src/anon/unit_002632d0.cpp

struct E248 { u8 pad[8]; u8 name[8]; s8 on; u8 pad2; u16 id; u8 pad3[16]; };
void Tz__Select__SetItem(u8*, s32, s32, s32, u32, u16, E248*, u8*) asm("Tz__Select__SetItem");
void Tz__Select__SetExOffset(u8*, s32, u32, s32) asm("Tz__Select__SetExOffset");
void func_001395f8(u8*) asm("func_001395f8");
void Tz__Select__SetCurrent(u8*, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
// 0x002be800: definition moved into src/anon/unit_002be020.cpp

extern E248** D_0035f6cc asm("D_0035f6cc");
extern u8* D_0035f64c asm("D_0035f64c");
extern u32 D_0035f644 asm("D_0035f644");
extern u32 D_0035f640 asm("D_0035f640");
extern u32 D_0035f664 asm("D_0035f664");
void func_00139620(u8*) asm("func_00139620");
s32 func_00240ba0(void) asm("func_00240ba0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 002b4b00*/
// Builds the two-entry list from the current table and focuses the default entry.
void OvlShop__ItemShop__SetupConfirm(void) asm("OvlShop__ItemShop__SetupConfirm");
// Builds the two-entry list from the current table and focuses the default entry.
void OvlShop__ItemShop__SetupConfirm(void) {
    for (s32 i = 0; i < 2; i++) {
        Tz__Select__SetItem(D_0035f64c, i, D_0035f644, D_0035f640, D_0035f664, (*D_0035f6cc)[i].id, &(*D_0035f6cc)[i], (*D_0035f6cc)[i].name);
        Tz__Select__SetExOffset(D_0035f64c, i, 0, -1);
        func_00139620(func_002891b8(D_0035f64c, i));
        func_001395f8(func_002891b8(D_0035f64c, i));
    }
    Tz__Select__SetCurrent(D_0035f64c, func_00240ba0(), 1, 0, 2);
    func_00287cc0(0);
}
}  // namespace n002b4b00

// 002b4c10 (was src/anon/debug_g.cpp)
namespace n002b4c10 {
struct E36 { u8 pad[18]; u16 id; u8 pad2[16]; };
struct Tbl { E36* e; };
extern Tbl* D_0035f6cc asm("D_0035f6cc");
s32 func_00240ba0(void) asm("func_00240ba0");
void Tz__CmSLBase__SetupWarningWin(s32) asm("Tz__CmSLBase__SetupWarningWin");
void func_002b5108(s32, s32) asm("func_002b5108");
void func_0028f4d8(s32, u32, s32) asm("func_0028f4d8");
void func_00287d20(s32) asm("func_00287d20");
void func_00234570(s32, s32) asm("func_00234570");
/*TARGET 002b4c10*/
void Tz__CmSLBase__SetupSlotCheck(void) asm("Tz__CmSLBase__SetupSlotCheck");
void Tz__CmSLBase__SetupSlotCheck(void) {
    s32 i = func_00240ba0();
    Tz__CmSLBase__SetupWarningWin(-1);
    func_002b5108(0x8a89, i);
    func_0028f4d8(1, D_0035f6cc->e[i].id, 0);
    func_00287d20(0);
    func_00234570(i, 0);
}
}  // namespace n002b4c10

// 002b4c88 (was src/anon/batch_w267.cpp)
namespace n002b4c88 {
extern u32 D_0035f650 asm("D_0035f650");
extern u32 D_0035f654 asm("D_0035f654");
extern u32 D_0035f644 asm("D_0035f644");
extern u32 D_0035f640 asm("D_0035f640");
extern u32 D_0035f664 asm("D_0035f664");
extern u32* D_0035f6cc asm("D_0035f6cc");
void func_002b6418(void*) asm("func_002b6418");
void Tz__CmComm__CreateConfirmSelector(u32, s32, u32, u32, u32, void*, u32) asm("Tz__CmComm__CreateConfirmSelector");
void func_00288f48(u32, s32, s32, s32, s32) asm("func_00288f48");
void func_0028af28(u32, s32) asm("func_0028af28");
s32 func_00139d78(u32) asm("func_00139d78");
s32 func_002892f8(u32) asm("func_002892f8");
u32 func_002891b8(u32, s32) asm("func_002891b8");
void func_0028dcc0(u32, u32) asm("func_0028dcc0");
void func_00138c78(u32, s32*, s32*) asm("func_00138c78");
s32 func_0023aa18(u32) asm("func_0023aa18");
s32 func_0023aa38(u32) asm("func_0023aa38");
void func_00138c68(u32, s32, s32) asm("func_00138c68");
/*TARGET 002b4c88*/
void Tz__CmSLBase__SetupWarningConfirm(void* p) asm("Tz__CmSLBase__SetupWarningConfirm");
void Tz__CmSLBase__SetupWarningConfirm(void* p) {
  s32 pos[2];
  func_002b6418(p);
  Tz__CmComm__CreateConfirmSelector(D_0035f650, 30064, D_0035f644, D_0035f640, D_0035f664, p, D_0035f6cc[4]);
  func_00288f48(D_0035f650, 128, 64, 0, 0);
  func_0028af28(D_0035f650, 64);
  if (func_00139d78(D_0035f654)) {
    s32 i = 0;
    while (i < func_002892f8(D_0035f650)) {
      func_0028dcc0(func_002891b8(D_0035f650, i), D_0035f654);
      func_00138c78(func_002891b8(D_0035f650, i), &pos[0], &pos[1]);
      pos[0] += func_0023aa18(D_0035f654 + 24);
      pos[1] += func_0023aa38(D_0035f654 + 24);
      func_00138c68(func_002891b8(D_0035f650, i), pos[0], pos[1]);
      i++;
    }
  }
}
}  // namespace n002b4c88

// 002b4dd0 (was src/anon/batch_wcx2.cpp)
namespace n002b4dd0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
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
struct Obj3;
void func_00138c10(Obj3*, s32) asm("func_00138c10");
void func_0028d980(u8*, s32, s32, s32, u32, s32, s32, s32, s32) asm("func_0028d980");
// mod10_classify_012
s32 func_00192048(s32) asm("func_00192048");
s32 func_00139d78(void*) asm("func_00139d78");
void Tz__CmSLBase__SetupWarningWin(s32 a) asm("Tz__CmSLBase__SetupWarningWin");
// 0x002aa4a8: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct T2b4dd0 { s16 h0; s16 h2; s16 h4; };
struct C2b4dd0 { u8 pad[20]; T2b4dd0* t; };
union G2b4dd0 { u8* p; u32 u; };
extern G2b4dd0 D_0035f654_2b4dd0 asm("D_0035f654");
extern C2b4dd0* D_0035f6cc_2b4dd0 asm("D_0035f6cc");
extern s32 D_0035f640_2b4dd0 asm("D_0035f640");
extern s32 D_0035f644_2b4dd0 asm("D_0035f644");
extern u32 D_0035f664_2b4dd0 asm("D_0035f664");
union B2b4dd0 { u8 b; u32 u; };
extern B2b4dd0 D_0035f6d0_2b4dd0 asm("D_0035f6d0");
void func_00139620(u8*) asm("func_00139620");
/*TARGET 002b4dd0*/
void Tz__CmSLBase__SetupWarningWin(s32 code) asm("Tz__CmSLBase__SetupWarningWin");
void Tz__CmSLBase__SetupWarningWin(s32 code)
{
    if (!func_00139d78(D_0035f654_2b4dd0.p)) {
        T2b4dd0* t = D_0035f6cc_2b4dd0->t;
        func_0028d980(D_0035f654_2b4dd0.p, 30061, D_0035f644_2b4dd0, D_0035f640_2b4dd0, D_0035f664_2b4dd0, t->h0, t->h4, code, 0);
    } else {
        u8* o = D_0035f654_2b4dd0.p;
        T2b4dd0* t = D_0035f6cc_2b4dd0->t;
        if (*(s32*)(o + 388) == t->h2) {
            func_00138c10((Obj3*)o, t->h0);
            *(s32*)(D_0035f654_2b4dd0.p + 392) = D_0035f6cc_2b4dd0->t->h4;
        }
        u8* p = D_0035f654_2b4dd0.p;
        *(s32*)(p + 408) = func_00192048(code);
    }
    func_00139620(D_0035f654_2b4dd0.p);
    *(s32*)(D_0035f654_2b4dd0.p + 432) = 2;
    u8* sb = D_0035f654_2b4dd0.p + 24;
    *(u32*)(sb + 184) |= 8;
    D_0035f6d0_2b4dd0.b = 1;
}
}  // namespace n002b4dd0

// 002b4ee0 (was src/tozawa/cmenu_slbase.cpp)
namespace n002b4ee0 {
extern u32 D_0035f650 asm("D_0035f650");
extern u8* D_0035f654 asm("D_0035f654");
extern u8* D_0035f6cc asm("D_0035f6cc");
extern u8 D_0035f6d0 asm("D_0035f6d0");
u32 func_0028acc8(u32) asm("func_0028acc8");
u32 func_0028acb8(...) asm("func_0028acb8");
void func_0028aa40(u32) asm("func_0028aa40");
void func_0028dac8(u8*, s32) asm("func_0028dac8");
/*TARGET 002b4ee0*/
// 0x00287c50: definition moved into src/anon/unit_00286d28.cpp

// 0x00288040: definition moved into src/anon/unit_00286d28.cpp

// 0x00288370: definition moved into src/anon/unit_002880b8.cpp

// 0x00288750: definition moved into src/anon/unit_002880b8.cpp

// 0x002887c8: definition moved into src/anon/unit_002880b8.cpp

// 0x00288820: definition moved into src/anon/unit_002880b8.cpp

// 0x002888c8: definition moved into src/anon/unit_002880b8.cpp

void CmSLBase_FadeOutWarningWin() asm("_ZN2Tz8CmSLBase17FadeOutWarningWinEv");
void CmSLBase_FadeOutWarningWin() {
    u8* t5 = D_0035f6cc;
    u8* t6 = *(u8**)(t5 + 20);
    func_0028dac8(D_0035f654, (s32)*(s16*)(t6 + 2));

    if (func_0028acc8(D_0035f650) != 0) {
        if (func_0028acb8(D_0035f650) == 0) {
            func_0028aa40(D_0035f650);
        }
    }

    D_0035f6d0 = 0;
}
}  // namespace n002b4ee0

// 002b4f50 (was src/anon/batch_w49.cpp)
namespace n002b4f50 {
s32 func_00139d78(void*) asm("func_00139d78");
// 0x002a6308: definition moved into src/anon/unit_002a5a90.cpp

extern u8* D_0035f654 asm("D_0035f654");
extern u32 D_0035f650 asm("D_0035f650");
extern u8 D_0035f6d0 asm("D_0035f6d0");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
typedef void (*Fn2b4f50)(u8*);
/*TARGET 002b4f50*/
void func_002b4f50(void) asm("func_002b4f50");
void func_002b4f50(void) {
    if (func_00139d78(D_0035f654)) (*(Fn2b4f50*)(*(u8**)D_0035f654 + 20))(D_0035f654);
    if (func_0028acc8(D_0035f650)) func_0028abe0(D_0035f650);
    D_0035f6d0 = 0;
}
}  // namespace n002b4f50

// 002b4fb8 (was src/anon/batch_w19.cpp)
namespace n002b4fb8 {
u8 func_00139d78(void*) asm("func_00139d78");
u8 func_0028acc8(u32) asm("func_0028acc8");
extern void* D_0035f654 asm("D_0035f654");
extern u32 D_0035f650 asm("D_0035f650");
/*TARGET 002b4fb8*/
// 0x002a6368: definition moved into src/anon/unit_002a5a90.cpp

u32 func_002b4fb8(void) asm("func_002b4fb8");
// 0x002a6368: definition moved into src/anon/unit_002a5a90.cpp

u32 func_002b4fb8(void) {
    void* o = D_0035f654;
    u32 v = 0;
    if (o) v = func_00139d78(o);
    if (v) v = func_0028acc8(D_0035f650);
    return v;
}
}  // namespace n002b4fb8

// 002b4ff8 (was src/tozawa/cmenu_slbase.cpp)
namespace n002b4ff8 {
extern u32 D_0035f650 asm("D_0035f650");
extern u8* D_0035f654 asm("D_0035f654");
extern u8* D_0035f6cc asm("D_0035f6cc");
u32 func_00139d78(u32) asm("func_00139d78");
u32 func_0028acc8(u32) asm("func_0028acc8");
u32 func_0028ae28(u32, u32) asm("func_0028ae28");
/*TARGET 002b4ff8*/
u32 CmSLBase_isLoopWarningWin() asm("_ZN2Tz8CmSLBase16isLoopWarningWinEv");
u32 CmSLBase_isLoopWarningWin() {
    func_00139d78((void*)D_0035f654);

    u8* t3 = D_0035f654;
    u8* t5 = D_0035f6cc;
    u32 t6 = *(u32*)(t3 + 388);
    u8* t4 = *(u8**)(t5 + 20);
    s32 t7 = (s32)*(s16*)(t4 + 4);

    u32 s0 = ((t6 ^ (u32)t7) < 1u);
    if (func_0028acc8(D_0035f650) != 0) {
        if (s0 != 0) {
            s0 = func_0028ae28(D_0035f650, 0);
        }
    }

    return s0;
}
}  // namespace n002b4ff8

// 002b5078 (was src/anon/batch_w49.cpp)
namespace n002b5078 {
s32 func_00139d78(void*) asm("func_00139d78");
void func_0028da70(u32, s32) asm("func_0028da70");
// 0x002a6308: definition moved into src/anon/unit_002a5a90.cpp

extern u8* D_0035f654 asm("D_0035f654");
extern u32 D_0035f650 asm("D_0035f650");
s32 func_0028acc8(u32) asm("func_0028acc8");
extern u8* D_0035f6cc asm("D_0035f6cc");
void func_0028ab20(u32) asm("func_0028ab20");
/*TARGET 002b5078*/
void func_002b5078(void) asm("func_002b5078");
void func_002b5078(void) {
    func_00139d78(D_0035f654);
    func_0028da70((u32)D_0035f654, *(s16*)(*(u8**)(D_0035f6cc + 20) + 4));
    if (func_0028acc8(D_0035f650)) func_0028ab20(D_0035f650);
}
}  // namespace n002b5078

// 002b50e8 (was src/anon/tiny_more3.cpp)
namespace n002b50e8 {
extern u32 D_0035f6d0 asm("D_0035f6d0");
/*TARGET 002b50e8*/
u32 func_002b50e8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_002b50e8jjjj");
u32 func_002b50e8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; s32 v=*(s8*)&D_0035f6d0; return (v!=0); }
}  // namespace n002b50e8

// 002b50f8 (was src/anon/tiny.cpp)
namespace n002b50f8 {
/*TARGET 002b50f8*/
void func_002b50f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002b50f8jjjj");
void func_002b50f8(u32 a0, u32 a1, u32 a2, u32 a3) {  // zero_global_byte_c
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + (-2352)) = (u8)0;
}
}  // namespace n002b50f8

// 002b5108 (was src/anon/batch_w3736.cpp)
namespace n002b5108 {
s32 func_00139d78(void*) asm("func_00139d78");
// 0x002a1d38: definition moved into src/anon/unit_002a1d38.cpp

struct S1b5108 { u8 pad[0x198]; void* x198; };
extern S1b5108* D_0035f654 asm("D_0035f654");
extern void* D_0035f6c8 asm("D_0035f6c8");
char* func_00192048(s32) asm("func_00192048");
void func_002b6338(void*, s32, s32, s32) asm("func_002b6338");
/*TARGET 002b5108*/
// Sets the current message: a non-negative b loads it into D_0035f6c8, otherwise a message string by id.
void func_002b5108(s32 a, s32 b) asm("func_002b5108");
// Sets the current message: a non-negative b loads it into D_0035f6c8, otherwise a message string by id.
void func_002b5108(s32 a, s32 b) {
    func_00139d78(D_0035f654);
    if (b >= 0) {
        func_002b6338(D_0035f6c8, 0x200, a, b);
        D_0035f654->x198 = D_0035f6c8;
    } else {
        D_0035f654->x198 = func_00192048(a);
    }
}
}  // namespace n002b5108

// 002b5188 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002b5188 {
// 0x001e1988: definition moved into src/anon/unit_001e0cb8.cpp

struct P2b5 { s16 x; s16 p2; s16 y; };
struct Q2b5 { u8 pad[8]; s32 a; s32 b; u8 pad2[8]; P2b5* p; };
struct F2b5 { u32 b0:3; u32 b3:1; u32 hi:28; };
struct Sub2b5 { u8 pad[0xb8]; F2b5 f; };
struct O2b5 { u8 pad[0x18]; Sub2b5 sub; u8 pad2[0x1b4 - 0xd4]; void* cb; };
extern Q2b5* D_0035f6cc asm("D_0035f6cc");
extern O2b5* D_0035f658 asm("D_0035f658");
extern s32 D_0035f644 asm("D_0035f644");
extern s32 D_0035f640 asm("D_0035f640");
extern s32 D_0035f664 asm("D_0035f664");
extern s32 D_0035f648 asm("D_0035f648");
extern s32 D_0035f64c asm("D_0035f64c");
extern s32 D_0035f678 asm("D_0035f678");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern O2b5* D_0035f680[4] asm("D_0035f680");
void func_002b6138() asm("func_002b6138");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
s32* func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(s32*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028bae0");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s32, s32) asm("Tz__Select__SetItem");
void* func_002891b8(s32, s32) asm("func_002891b8");
void func_001395f8(void*) asm("func_001395f8");
void func_00139620(void*) asm("func_00139620");
void Tz__Select__SetExOffset(s32, s32, s32, s32) asm("Tz__Select__SetExOffset");
void func_002b57e0(void) asm("func_002b57e0");
O2b5* Tz__MenuItem__start(s32, s32, s32, s32, s32, s32) asm("Tz__MenuItem__start");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
s32 func_0023d2e0(s32*) asm("func_0023d2e0");
s32 func_00240ba0(void) asm("func_00240ba0");
void func_0023d300(s32*) asm("func_0023d300");
s32 func_002418b8(void) asm("func_002418b8");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void Tz__CmSLBase__UpdateListMess(s32) asm("Tz__CmSLBase__UpdateListMess");
s32 func_00233e60(void) asm("func_00233e60");
void func_00234570(s32, s32) asm("func_00234570");
void Tz__Select__SetPageMode(s32, s32) asm("Tz__Select__SetPageMode");
void func_0028b248(s32, s32) asm("func_0028b248");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 002b5188*/
void func_002b5188(s32 arg0, s32 arg1) asm("func_002b5188");
void func_002b5188(s32 arg0, s32 arg1) {
    s32 i;
    s32 a, b;
    func_0028d8c0(D_0035f658, 0x755f, D_0035f644, D_0035f640, D_0035f664, D_0035f6cc->p->x, D_0035f6cc->p->y, 0);
    { Sub2b5* sb = &D_0035f658->sub; sb->f.b3 = 1; }
    s32 u = func_0023c4b8(func_0023f1b0(D_0035f664), D_0035f644);
    s32* q = func_0023f1b0(D_0035f664);
    s32 bb = D_0035f640;
    s32 im = func_00236ca8(q[10], bb);
    s32 saved = D_0035f3d4;
    D_0035f3d4 = 0x755f;
    func_0028bae0(D_0035f678, 0x755f, u, im, arg0, 99, 4, 0, 0);
    for (i = 0; i < 4; i++) {
        Tz__Select__SetItem(D_0035f64c, i, D_0035f644, D_0035f640, D_0035f664, -1, D_0035f6cc->a, D_0035f6cc->b);
        func_001395f8(func_002891b8(D_0035f64c, i));
        Tz__Select__SetExOffset(D_0035f64c, i, 0, -1);
        func_00139620(func_002891b8(D_0035f64c, i));
    }
    func_002b57e0();
    D_0035f3d4 = 0x7560;
    for (i = 0; i < 4; i++) {
        O2b5* r = Tz__MenuItem__start(D_0035f648, D_0035f644, D_0035f640, D_0035f664, -1, 0);
        D_0035f680[i] = r;
        func_0028dcc0(D_0035f680[i], func_002891b8(D_0035f64c, i));
        func_001395f8(D_0035f680[i]);
        func_00139620(D_0035f680[i]);
        D_0035f680[i]->cb = (void*)func_002b6138;
    }
    D_0035f3d4 = saved;
    Tz__Select__SetSelectMax(D_0035f64c, 99);
    if (func_0023d2e0(&a) && a == func_00240ba0()) func_0023d300(&b);
    else b = func_002418b8();
    Tz__Select__SetCurrent(D_0035f64c, b, 1, 0, 2);
    Tz__CmSLBase__UpdateListMess(arg1);
    if (func_00233e60()) func_00234570(func_00240ba0(), 0);
    Tz__Select__SetPageMode(D_0035f64c, 1);
    func_0028b248(D_0035f64c, 4);
    func_00287cc0(0);
}
}  // namespace n002b5188

// 002b5490 (was src/tozawa/cmenu_slbase.cpp)
namespace n002b5490 {
extern u32 D_0035f64c asm("D_0035f64c");
extern u8* D_0035f658 asm("D_0035f658");
extern u8* D_0035f6cc asm("D_0035f6cc");
u32 func_00139d78(u32) asm("func_00139d78");
u32 func_0028ae28(u32, u32) asm("func_0028ae28");
/*TARGET 002b5490*/
u32 CmSLBase_isLoopList() asm("_ZN2Tz8CmSLBase10isLoopListEv");
u32 CmSLBase_isLoopList() {
    u8* t7 = D_0035f658;
    if (t7 != 0) {
        func_00139d78((void*)t7);
        t7 = D_0035f658;
    }

    u32 t4 = *(u32*)(t7 + 388);
    u8* t6 = D_0035f6cc;
    u8* t5 = *(u8**)(t6 + 24);
    s32 t7i = (s32)*(s16*)(t5 + 4);

    u32 v0 = ((t4 ^ (u32)t7i) < 1u);
    if (v0 != 0) {
        v0 = func_0028ae28(D_0035f64c, 0);
    }
    return v0;
}
}  // namespace n002b5490

// 002b54f8 (was src/tozawa/cmenu_slbase.cpp)
namespace n002b54f8 {
extern u32 D_0035f64c asm("D_0035f64c");
extern u8* D_0035f658 asm("D_0035f658");
extern u32 D_0035f678 asm("D_0035f678");
extern u8* D_0035f6cc asm("D_0035f6cc");
u32 func_00139d78(u32) asm("func_00139d78");
void func_00138c10(u32, u32) asm("func_00138c10");
void func_0028ab20(u32) asm("func_0028ab20");
void func_0028bd60(u32) asm("func_0028bd60");
/*TARGET 002b54f8*/
void CmSLBase_LoopList() asm("_ZN2Tz8CmSLBase8LoopListEv");
void CmSLBase_LoopList() {
    u8* t7 = D_0035f658;
    if (t7 != 0) {
        func_00139d78((void*)t7);
    }

    u8* t6 = D_0035f6cc;
    u8* t5 = *(u8**)(t6 + 24);
    func_00138c10((void*)D_0035f658, (s32)*(s16*)(t5 + 4));

    func_0028ab20(D_0035f64c);
    func_0028bd60(D_0035f678);
}
}  // namespace n002b54f8

// 002b5558 (was src/tozawa/cmenu_slbase.cpp)
namespace n002b5558 {
extern u32 D_0035f64c asm("D_0035f64c");
extern u8* D_0035f658 asm("D_0035f658");
extern u32 D_0035f678 asm("D_0035f678");
extern u8* D_0035f6cc asm("D_0035f6cc");
u32 func_0028acc8(u32) asm("func_0028acc8");
u32 func_0028acb8(...) asm("func_0028acb8");
void func_0028aa40(u32) asm("func_0028aa40");
void func_0028dac8(u8*, s32) asm("func_0028dac8");
u32 func_0028be58(u32) asm("func_0028be58");
void func_0028bdb8(u32) asm("func_0028bdb8");
/*TARGET 002b5558*/
void CmSLBase_FadeOutList() asm("_ZN2Tz8CmSLBase11FadeOutListEv");
void CmSLBase_FadeOutList() {
    u8* t5 = D_0035f6cc;
    u8* t6 = *(u8**)(t5 + 24);
    func_0028dac8(D_0035f658, (s32)*(s16*)(t6 + 2));

    if (func_0028acc8(D_0035f64c) != 0) {
        if (func_0028acb8(D_0035f64c) == 0) {
            func_0028aa40(D_0035f64c);
        }
    }

    if (func_0028be58(D_0035f678) != 0) {
        func_0028bdb8(D_0035f678);
    }
}
}  // namespace n002b5558

// 002b55e0 (was src/tozawa/cmenu_slbase.cpp)
namespace n002b55e0 {
extern u32 D_0035f64c asm("D_0035f64c");
extern u8* D_0035f658 asm("D_0035f658");
extern u32 D_0035f678 asm("D_0035f678");
u32 func_00139d78(u32) asm("func_00139d78");
u32 func_0028acc8(u32) asm("func_0028acc8");
u32 func_0028be58(u32) asm("func_0028be58");
void func_002b5a20() asm("func_002b5a20");
/*TARGET 002b55e0*/
void CmSLBase_isExistList() asm("_ZN2Tz8CmSLBase11isExistListEv");
void CmSLBase_isExistList() {
    u32 v0 = 0;

    if (D_0035f658 != 0) {
        v0 = func_00139d78(D_0035f658);
    }
    if (v0 != 0) {
        return;
    }

    if (D_0035f64c != 0) {
        v0 = func_0028acc8(D_0035f64c);
    }
    if (v0 != 0) {
        return;
    }

    v0 = func_0028be58(D_0035f678);
    if (v0 != 0) {
        return;
    }

    func_002b5a20();
    v0 = 0;
}
}  // namespace n002b55e0

// 002b5658 (was src/anon/batch_w60.cpp)
namespace n002b5658 {
extern u8* D_0035f658 asm("D_0035f658");
extern void* D_0035f64c asm("D_0035f64c");
extern void* D_0035f678 asm("D_0035f678");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028abe0(void*) asm("func_0028abe0");
s32 func_0028be58(void*) asm("func_0028be58");
void func_0028be18(void*) asm("func_0028be18");
void func_002b5af0(void) asm("func_002b5af0");
/*TARGET 002b5658*/
// 0x002937c0: definition moved into src/anon/unit_00292e60.cpp

void func_002b5658(void) asm("func_002b5658");
// 0x002937c0: definition moved into src/anon/unit_00292e60.cpp

void func_002b5658(void) {
    if (D_0035f658 && func_00139d78(D_0035f658)) {
        u8* o = D_0035f658;
        (*(void (**)(void*))(*(u8**)o + 20))(o);
    }
    if (D_0035f64c && func_0028acc8(D_0035f64c)) func_0028abe0(D_0035f64c);
    if (func_0028be58(D_0035f678)) func_0028be18(D_0035f678);
    func_002b5af0();
}
}  // namespace n002b5658

// 002b56e8 (was src/anon/batch_w52.cpp)
namespace n002b56e8 {
u32 func_00139d78(u8*) asm("func_00139d78");
// 0x002ad338: definition moved into src/anon/unit_002a99c8.cpp

extern u8* D_0035f680[4] asm("D_0035f680");
/*TARGET 002b56e8*/
u32 func_002b56e8(void) asm("func_002b56e8");
u32 func_002b56e8(void) {
    s32 i;
    u32 r = 0;
    for (i = 0; i < 4; i++) {
        u8* o = D_0035f680[i];
        if (o && func_00139d78(o)) {
            r = 1;
            break;
        }
    }
    return r;
}
}  // namespace n002b56e8

// 002b5768 (was src/anon/batch_w39.cpp)
namespace n002b5768 {
// 0028eb88: moved to src/anon/unit_0028c878.cpp

// --- 002b5768
struct VObj { void** vt; u8 pad[432]; VObj* f436; };
extern VObj* D_0035f680[4] asm("D_0035f680");
int func_00139d78_2b5(VObj*) asm("func_00139d78");
void LeaveListItemImpl_impl(void) asm("_ZN2Tz8CmSLBase17LeaveListItemImplEv");
/*TARGET 002b5768*/
void LeaveListItemImpl_impl(void) asm("_ZN2Tz8CmSLBase17LeaveListItemImplEv");
void LeaveListItemImpl_impl(void) {
    for (int i = 0; i < 4; i++) {
        if (D_0035f680[i]) {
            if (func_00139d78_2b5(D_0035f680[i])) {
                D_0035f680[i]->f436 = 0;
                (*(void (**)(VObj*))((*(u8**)D_0035f680[i]) + 20))(D_0035f680[i]);
            }
            D_0035f680[i] = 0;
        }
    }
}
}  // namespace n002b5768

// 002b57e0 (was src/anon/perm_002b57e0.cpp)
namespace n002b57e0 {
typedef unsigned char u8;
typedef signed int s32;
struct Obj
{
  u8 pad[0x18c];
  s32 a18c;
  s32 a190;
};
Obj *Tz__MenuItem__start(s32, s32, s32, s32, s32, s32) asm("Tz__MenuItem__start");
s32 func_002891b8(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void func_001396b0(Obj *) asm("_ZN2Tz6Select10BeginLeaveEz");
void func_0031a260(Obj *, s32) asm("_ZN2Tz6Select7SetFlagEz");
void func_00139620(Obj *) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void func_00139660(Obj *) asm("_ZN2dk5Obj2D19getParentSeqColorOnEv");
void func_00139688(Obj *) asm("_ZN2dk5Obj2D21getParentSeqAlphaOnlyEv");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f640 asm("D_0035f640");
extern s32 D_0035f644 asm("D_0035f644");
extern s32 D_0035f648 asm("D_0035f648");
extern s32 D_0035f64c asm("D_0035f64c");
extern s32 D_0035f664 asm("D_0035f664");
extern Obj *D_0035f690[][4] asm("D_0035f690");
/*TARGET 002b57e0*/
void func_002b57e0(void) asm("func_002b57e0");
void func_002b57e0(void)
{
  int new_var;
  s32 i;
  s32 a;
  int new_var2;
  s32 saved = D_0035f3d4;
  for (i = 0; i < 3; i++)
  {
    new_var = 1;
    a = 0;
    s32 b = new_var;
    s32 c = 1;
    switch (i)
    {
      case 1:
        break;

      case 0:
        c = 2;
        b = 2;
        break;

      case 2:

      default:
        D_0035f3d4 = 0x7561;
        c = D_0035f644;
        b = D_0035f640;
        a = D_0035f648;
        break;

    }

    new_var2 = 0;
    s32 j;
    for (j = new_var2; j < 4; j++)
    {
      Obj *o = Tz__MenuItem__start(a, c, b, D_0035f664, -1, new_var2);
      D_0035f690[i][j] = o;
      (*o).a18c = func_002891b8(D_0035f64c, j);
      func_001396b0(o);
      if (o->a18c != new_var2)
      {
        o->a190 = new_var2;
        func_001396b0(o);
        if (o->a190 != (new_var2 * new_var2))
        {
          func_0031a260(o, new_var2);
 do { } while (new_var2);
        }
      }
      func_00139620(D_0035f690[i][j]);
      func_00139660(D_0035f690[i][j]);
      func_00139688(D_0035f690[i][j]);
    }

    if (i == 2)
    {
      D_0035f3d4 = saved;
    }
  }

}
}  // namespace n002b57e0

// 002b5978 (was src/anon/auto80_199_queue.cpp)
namespace n002b5978 {
/*TARGET 002b5978*/
u32 func_002b5978(void) asm("_Z13func_002b5978v");
u32 func_002b5978(void) {
    u32 s2 = 0;
    u32 s4 = 0;

    while (1) {
        u32 s1 = 0;
        u32 off = s2 << 2;
        void** s0 = &D_0035f690[off];

        while (1) {
            void* t7 = *s0;
            s0 = s0 + 1;

            if (t7 != 0) {
                if (func_00139d78(t7) != 0) {
                    s4 = 1;
                    break;
                }
            }

            s1 = s1 + 1;
            if ((s32)s1 < 4) {
                continue;
            }
            break;
        }

        s2 = s2 + 1;
        if ((s32)s2 < 3) {
            continue;
        }
        return s4;
    }
}
}  // namespace n002b5978

// 002b5a20 (was src/anon/tiny_auto80_queue.cpp)
namespace n002b5a20 {
u32 func_002b56e8(...) asm("func_002b56e8");
u32 func_002b5978(...) asm("func_002b5978");
/*TARGET 002b5a20*/
u32 func_002b5a20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002b5a20jjjjjjjj");
u32 func_002b5a20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r2 = ((u32(*)())func_002b56e8)();
    if (r2 == 0u) {
        r2 = ((u32(*)())func_002b5978)();
    }
    return r2;
}
}  // namespace n002b5a20

// 002b5a50 (was src/anon/batch_wcx.cpp)
namespace n002b5a50 {
typedef void (*VFn)(void*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// 0x002a9b88: definition moved into src/anon/unit_002a99c8.cpp

// Tz::CmSLBase::GetCurrentListItem: release every live item in the 3x4 slot grid
extern u8* D_0035f690[3][4] asm("D_0035f690");
void CmSLBase_GetCurrentListItem(void) asm("_ZN2Tz8CmSLBase18GetCurrentListItemEv");
/*TARGET 002b5a50*/
void CmSLBase_GetCurrentListItem(void) asm("_ZN2Tz8CmSLBase18GetCurrentListItemEv");
void CmSLBase_GetCurrentListItem(void)
{
    for (s32 i = 0; i < 3; i++) {
        u8** p = D_0035f690[i];
        for (s32 j = 3; j >= 0; j--, p++) {
            if (*p) {
                if (u_call4_00139d78(*p)) (*(VFn*)(*(u8**)*p + 20))(*p);
                *p = 0;
            }
        }
    }
}
}  // namespace n002b5a50

// 002b5af0 (was src/tozawa/cmenu_slbase.cpp)
namespace n002b5af0 {
u32 func_002b5a50() asm("func_002b5a50");
u32 func_002b5768() asm("func_002b5768");
/*TARGET 002b5af0*/
void CmSLBase_LeaveListItem() asm("_ZN2Tz8CmSLBase13LeaveListItemEv");
void CmSLBase_LeaveListItem() {
    u32 r2 = 0u;
    r2 = func_002b5a50();
    (void)r2;
    func_002b5768();
}
}  // namespace n002b5af0

// 002b5b10 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002b5b10 {
extern u8 D_00374d80 asm("D_00374d80");
/*TARGET 002b5b10*/
// 0x002a43d0: definition moved into src/anon/unit_002a40c8.cpp

u32 func_002b5b10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002b5b10jjjj");
// 0x002a43d0: definition moved into src/anon/unit_002a40c8.cpp

u32 func_002b5b10(u32 a0, u32 a1, u32 a2, u32 a3) {  // entry_get_short
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r4 = (u32)(r4 << 1);
    r2 = (u32)((s32)0u + (9));
    if (r5 == 0u) {
        r15 = (u32)&D_00374d80;
        r15 = (u32)(r4 + r15);
        r2 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(0)));
    }
    return r2;
}
}  // namespace n002b5b10

// 002b5b38 (was src/anon/batch_w88.cpp)
namespace n002b5b38 {
u32 func_002891e8(u32) asm("func_002891e8");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289310(u32) asm("func_00289310");
void func_002890e0(u32, u32, u32, u32, s32) asm("func_002890e0");
void func_00289038(u32, u32, u32, u32, u32, u32, s32) asm("func_00289038");
s32 func_00289358(u32) asm("func_00289358");
void Tz__CmSLBase__UpdateListMess(u32) asm("Tz__CmSLBase__UpdateListMess");
s32 func_0028d008(u32) asm("func_0028d008");
u32 func_002891d0(u32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(u32, u32) asm("Tz__MenuCursor__SetParent");
extern u32 D_0035f64c asm("D_0035f64c");
/*TARGET 002b5b38*/
// 00291110: moved to src/anon/unit_00290f78.cpp

void Tz__CmSave__DrawSelector(u32 a, s32 b, u32 c) asm("Tz__CmSave__DrawSelector");
// 00291110: moved to src/anon/unit_00290f78.cpp

void Tz__CmSave__DrawSelector(u32 a, s32 b, u32 c) {
    if (func_00287cd0() != 1) return;
    if (!func_00289310(a)) return;
    func_002890e0(a, 1, 2, 0, -1);
    func_00289038(a, func_002891e8(a), 1, 1, 2, 0, -1);
    if (b == 12 && func_00289358(D_0035f64c)) Tz__CmSLBase__UpdateListMess(0);
    if (func_0028d008(c)) Tz__MenuCursor__SetParent(c, func_002891d0(a));
}
}  // namespace n002b5b38


// 002b5c30 (was src/anon/batch_w3943.s, whole asm)
namespace n002b5c30 {
struct Info { u32 flags; s32 fC; s32 f10; s32 f14; s8 f18; s8 f19; s8 f1a; s8 f1b; s8 f1c; u8 pad[3]; };
struct Rec { s32 f0; s32 f4; Info info; };
struct Line { char f0[8]; char f8[8]; char f10[8]; char f18[32]; };
s32 func_00105c30(void) asm("func_00105c30");
void func_00138c10(void*, s32) asm("func_00138c10");
void dk__Clock__vCountToHMSMS(s32, s32*, s32*, s32*, s32*) asm("dk__Clock__vCountToHMSMS");
s32 func_00192048(s32) asm("func_00192048");
s32 func_00192b30(s32) asm("func_00192b30");
s32 func_00192c40(s32, char*) asm("func_00192c40");
s32 func_00192cc0(char*, const char*, ...) asm("func_00192cc0");
Rec* func_00241f10(void) asm("func_00241f10");
void func_002595e8(char*, s32) asm("func_002595e8");
u8* func_002891b8(void*, s32) asm("func_002891b8");
s32 func_002892f8(void*) asm("func_002892f8");
s32 func_0028afa8(void*) asm("func_0028afa8");
s32 func_0028b038(void*) asm("func_0028b038");
void Tz__ScrollBar__SetPos(s32, s32) asm("Tz__ScrollBar__SetPos");
s32 func_002b5b10(s32, s32) asm("func_002b5b10");
void func_002b60e8(s32, s32, s32, s32) asm("func_002b60e8");
extern s32 D_0035f648 asm("D_0035f648");
extern void* D_0035f64c asm("D_0035f64c");
extern Line* D_0035f65c asm("D_0035f65c");
extern s32 D_0035f678 asm("D_0035f678");
extern void* D_0035f690[3][4] asm("D_0035f690");
extern const char D_00374cf0[] asm("D_00374cf0");
extern const char D_00374cf8[] asm("D_00374cf8");
extern const char D_00374d00[] asm("D_00374d00");
extern const char D_00374d08[] asm("D_00374d08");
extern const s16 D_00374da8[] asm("D_00374da8");
extern const s32 D_00374db8[] asm("D_00374db8");
static inline u8 IsLang(s32 a) { u8 r = 0; if (func_00105c30() == a || func_00105c30() == 8) r = 1; return r; }
static inline s32 Print2(char* d, const char* f, s32 a, s32 b) { return func_00192cc0(d, f, a, b); }
static inline s32 Print(char* d, const char* f, s32 v) { return func_00192cc0(d, f, v); }
void Tz__CmSLBase__UpdateListMess(s32 arg0) asm("Tz__CmSLBase__UpdateListMess");
void Tz__CmSLBase__UpdateListMess(s32 arg0)
{
    s32 i; s32 j; s32 start; Rec* recs; s32 cnt;
    void* (*tbl)[4] = D_0035f690;
    recs = func_00241f10();
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            func_002b60e8(i, j, -1, 0);
    start = func_0028b038(D_0035f64c);
    cnt = func_0028afa8(D_0035f64c);
    Tz__ScrollBar__SetPos(D_0035f678, start);
    s32 one = 1;
    for (i = 0; i < func_002892f8(D_0035f64c); i++) {
        s32 idx = (start + i) % cnt;
        Line* ln = &D_0035f65c[i];
        u8* ent = func_002891b8(D_0035f64c, i);
        *(s32*)(ent + 408) = Print(ln->f0, D_00374cf0, idx + 1);
        Rec* r = &recs[idx];
        s32 n = r->info.flags;
        Info* info = &r->info;
        if (n == 0) {
            func_002b60e8(i, 0, 5, func_00192048(arg0 ? 0x8a9f : 0x8a9d));
        } else if (n & 0x10) {
            s32 a, b, c, d;
            j = 2;
            s32 len = func_00192c40(func_00192048(0xcd96), D_0035f65c[i].f8);
            Print(D_0035f65c[i].f8 + len, D_00374cf8, r->info.f19);
            func_002b60e8(i, 0, 0, (s32)D_0035f65c[i].f8);
            len = func_00192b30(func_00192cc0(D_0035f65c[i].f18, D_00374d00, r->info.f14));
            func_002595e8(D_0035f65c[i].f18 + len, func_00192048(0xb7db));
            func_002b60e8(i, 1, 1, (s32)D_0035f65c[i].f18);
            if (IsLang(one)) {
                n = D_00374db8[recs[idx].info.f18];
                if (n > 0) {
                    j = 3;
                    func_002b60e8(i, 2, 2, func_00192048(n));
                }
            }
            if (recs[idx].info.fC) func_002b60e8(i, j++, 3, recs[idx].info.fC);
            dk__Clock__vCountToHMSMS(recs[idx].info.f10, &a, &b, &c, &d);
            s32 ty = IsLang(one) ? 4 : 2;
            func_002b60e8(i, j++, ty, Print2(D_0035f65c[i].f10, D_00374d08, a, b));
        } else if (n & 0x40) {
            func_002b60e8(i, 0, 5, func_00192048(arg0 ? 0x8a9f : 0x8a9e));
        } else {
            func_002b60e8(i, 0, 5, func_00192048(0x8a9a));
        }
        if (info->flags & 0x10) {
            s32 v;
            n = info->f1a;
            if (n >= 0) v = func_002b5b10(n, info->f1c); else v = 0;
            func_00138c10(D_0035f690[0][i], v);
            n = info->f1b;
            func_00138c10(D_0035f690[1][i], D_00374da8[n]);
            n = (info->flags & 0x10000000) ? 20 : D_0035f648;
            func_00138c10(tbl[2][i], n);
        } else {
            func_00138c10(D_0035f690[0][i], 0);
            func_00138c10(D_0035f690[1][i], 0);
            func_00138c10(D_0035f690[2][i], D_0035f648);
        }
    }
}
}  // namespace n002b5c30
