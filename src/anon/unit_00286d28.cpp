// Linked unit 0x00286d28-0x002880b8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/cmenu_newflg.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tz/ui_accessors.hpp"
#include "../tozawa/cmenu_item.hpp"

// 00286d28 (was src/anon/batch_w1949_nsa.c)
namespace n00286d28 {
typedef struct W1949_Flags { u8 pad[80]; u32 f80[3]; u32 f92[8]; } W1949_Flags;
static inline s32 W1949_Bit(u32* a, u32 n) { return (a[n >> 5] & (1 << (n & 31))) != 0; }
extern W1949_Flags* D_0035f2e4 asm("D_0035f2e4");
s32 func_00258108(void) asm("func_00258108");
s32 func_002811b0(s32, s32) asm("func_002811b0");
s32 func_001b7818(s32) asm("func_001b7818");
/*TARGET 00286d28*/
s32 Tz__CmNewFlg__isAbilityNewMember(s32 a, s32 b) asm("Tz__CmNewFlg__isAbilityNewMember");
s32 Tz__CmNewFlg__isAbilityNewMember(s32 a, s32 b) {
    s32 r = 0;
    s32 ctx = func_00258108();
    s32 i;
    if (a <= 0) {
        if (b < 0) {
            for (i = 0; i < 80; i++) {
                r = W1949_Bit(D_0035f2e4->f80, i);
                if (r) break;
            }
        } else {
            r = W1949_Bit(D_0035f2e4->f80, b);
        }
        if (r || a == 0) return r;
    }
    for (i = 1; i < 4; i++) {
        if (a < 0 || i == a) {
            s32 v = func_002811b0(ctx, i);
            if (v) {
                s32 g = func_001b7818(v) - 2;
                s32 j;
                for (j = 0; j < 48; j++) {
                    if (b < 0 || j == b) {
                        v = g * 48 + j; r = W1949_Bit(D_0035f2e4->f92, v);
                        if (r) break;
                    }
                }
                if (r) break;
            }
        }
    }
    return r;
}
}  // namespace n00286d28

// 00286ec8 (was src/anon/batch_w272.cpp)
namespace n00286ec8 {
// 0x002693a8: definition moved into src/anon/unit_00268b30.cpp
extern u8* D_0035f2e4 asm("D_0035f2e4");
s32 func_002813b8(void) asm("func_002813b8");
s32 func_0027aa78(void) asm("func_0027aa78");
s32 func_002812e0(void) asm("func_002812e0");
static inline bool TestBit(u32* a, u32 b) { return (a[b >> 5] & (1 << (b & 31))) != 0; }
static inline s32 IsOffI(s32 f, s32 i) { return (u8)!((f >> i) & 1); }
/*TARGET 00286ec8*/
s32 Tz__CmNewFlg__isAbilityNewForm(s32 sel, s32 n) asm("Tz__CmNewFlg__isAbilityNewForm");
s32 Tz__CmNewFlg__isAbilityNewForm(s32 sel, s32 n) {
    s32 res = 0;
    s32 flags = func_002813b8();
    if (func_0027aa78()) flags |= 0x80;
    s32 k = 0;
    for (s32 i = 1; i < 8; i++, k++) {
        if (i == 6) { k--; continue; }
        if (sel >= 0 && i != sel) continue;
        if (func_002812e0() && i != 7) continue;
        if (IsOffI(flags, i)) continue;
        for (s32 j = 0; j < 48; j++) {
            if (n >= 0 && j != n) continue;
            res = TestBit((u32*)(D_0035f2e4 + 164), k * 48 + j);
            if (res) break;
        }
        if (res) break;
    }
    return res;
}
}  // namespace n00286ec8

// 00287028 (was src/anon/batch_w3770.cpp)
namespace n00287028 {
struct Save { u8 p0[80]; u32 a[3]; u32 b[1]; };
extern Save* D_0035f2e4 asm("D_0035f2e4");
Save* func_002859a0(void) asm("func_002859a0");
void* func_00258108(void) asm("func_00258108");
void* func_002811b0(void*, s32) asm("func_002811b0");
s32 func_001b7818(void*) asm("func_001b7818");
static inline s32 bit(const u32* b, u32 i) { return (b[i >> 5] & (1 << (i & 31))) != 0; }
/*TARGET 00287028*/
// 00287028: checks that every flag set in D_0035f2e4's bitsets is also set in the
// save data (first set: 80 bits or the one bit 'id'; second: 48 bits per entry
// for entries 1..3 or just entry 'mode'). Returns 1 when all are set, else 0.
s32 Tz__CmNewFlg__isAbilityHistMember(s32 mode_, s32 id) asm("Tz__CmNewFlg__isAbilityHistMember");
// 00287028: checks that every flag set in D_0035f2e4's bitsets is also set in the
// save data (first set: 80 bits or the one bit 'id'; second: 48 bits per entry
// for entries 1..3 or just entry 'mode'). Returns 1 when all are set, else 0.
s32 Tz__CmNewFlg__isAbilityHistMember(s32 mode_, s32 id)
{
    // register pin: without it gcc gives r the lower saved register (s2) and mode s3
    register s32 mode asm("$18") = mode_;
    s32 i;
    s32 r = 1;
    Save* s = func_002859a0();
    void* v = func_00258108();
    if (mode <= 0) {
        if (id < 0) {
            for (i = 0; i < 80; i++) {
                if (bit(D_0035f2e4->a, i)) {
                    r = bit(s->a, i);
                    if (!r) break;
                }
            }
        } else {
            u32 m = 1 << (id & 31);
            u32 k = ((u32)id >> 5) * 4;
            s32 t = 0;
            if (*(u32*)((u8*)D_0035f2e4 + k + 80) & m) t = (*(u32*)((u8*)s + k + 80) & m) != 0;
            r = t;
        }
        if (mode == 0) return r;
    }
    for (i = 1; i < 4; i++) {
        if (mode >= 0 && i != mode) continue;
        void* p = func_002811b0(v, i);
        if (!p) continue;
        s32 k = func_001b7818(p) - 2;
        s32 base = k * 48;
        for (s32 j = 0; j < 48; j++) {
            if (id >= 0 && j != id) continue;
            k = base + j;
            if (bit(D_0035f2e4->b, k)) {
                r = bit(s->b, k);
                if (!r) return r;
            }
        }
        if (!r) break;
    }
    return r;
}
}  // namespace n00287028

// 00287218 (was src/anon/batch_w3795.cpp)
namespace n00287218 {
extern u8* D_0035f2e4 asm("D_0035f2e4");
u8* func_002859a0(void) asm("func_002859a0");
s32 func_002813b8(void) asm("func_002813b8");
s32 func_0027aa78(void) asm("func_0027aa78");
/*TARGET 00287218*/
// Returns 0 if any bit that is set in D_0035f2e4's 48-bit-per-slot table (slots 1..7, 6 skipped,
// filtered by a0/a1 when >= 0) is clear in func_002859a0()'s table; 1 otherwise.
s32 func_00287218(s32 a0, s32 a1) asm("func_00287218");
// Returns 0 if any bit that is set in D_0035f2e4's 48-bit-per-slot table (slots 1..7, 6 skipped,
// filtered by a0/a1 when >= 0) is clear in func_002859a0()'s table; 1 otherwise.
s32 func_00287218(s32 a0, s32 a1) {
    u8* p = func_002859a0();
    s32 bits = func_002813b8();
    s32 ret = 1;
    s32 i, k, j;
    u8* q;
    if (func_0027aa78()) bits |= 0x80;
    q = D_0035f2e4;
    for (i = 1, j = 0; i < 8; i++, j++) {
        u8 clr;
        if (i == 6) { j--; continue; }
        if (a0 >= 0 && i != a0) continue;
        clr = !((bits >> i) & 1);
        if (clr) continue;
        {
            k = 0;
            s32 off = j * 48;
            u32* qa = (u32*)(q + 164);
            for (; k < 48; k++) {
                u32 b;
                u32 m;
                if (a1 >= 0 && k != a1) continue;
                b = off + k;
                m = 1 << (b & 31);
                if (qa[b >> 5] & m) {
                    u32* pa = (u32*)(p + 164);
                    ret = (pa[b >> 5] & m) != 0;
                    if (!ret) break;
                }
            }
        }
        if (!ret) break;
    }
    return ret;
}
}  // namespace n00287218

// 00287358 (was src/anon/batch_w86.cpp)
namespace n00287358 {
struct Save { u8 p0[80]; u32 a[3]; u32 b[1]; };
static inline void SetBit(u32* bits, u32 i)
{
    u32* p = (u32*)(((i >> 5) << 2) + (u32)bits);
    u32 m = 1 << (i & 31);
    if (!(*p & m)) *p |= m;
}
Save* func_002859a0(void) asm("func_002859a0");
void* func_00258108(void) asm("func_00258108");
void* func_002811b0(void*, s32) asm("func_002811b0");
s32 func_001b7818(void*) asm("func_001b7818");
/*TARGET 00287358*/
void Tz__CmNewFlg__SetAbilityFlgMember(s32 mode, u32 id) asm("Tz__CmNewFlg__SetAbilityFlgMember");
void Tz__CmNewFlg__SetAbilityFlgMember(s32 mode, u32 id)
{
    Save* s = func_002859a0();
    void* v = func_00258108();
    if (!mode) {
        SetBit(s->a, id);
    } else {
        s32 k = func_001b7818(func_002811b0(v, mode));
        k -= 2;
        SetBit(s->b, k * 48 + id);
    }
}
}  // namespace n00287358

// 00287430 (was src/anon/batch_w60.cpp)
namespace n00287430 {
u8* func_002859a0(void) asm("func_002859a0");
/*TARGET 00287430*/
void func_00287430(s32 a, s32 b) asm("func_00287430");
void func_00287430(s32 a, s32 b) {
    u32* bits = (u32*)(func_002859a0() + 164);
    if (a == 7) a--;
    a--;
    u32 bit = a * 48 + b;
    u32 m = 1 << (bit & 31);
    if (!(bits[bit >> 5] & m)) bits[bit >> 5] |= m;
}
}  // namespace n00287430

// 002874b0 (was src/anon/batch_w96.cpp)
namespace n002874b0 {
// fabsf
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
extern u32 D_0033caf4 asm("D_0033caf4");
void func_00239700(u32) asm("func_00239700");
typedef u8* (*AllocFn_w96)(void*, u32, u32);
extern u8* D_00347f80 asm("D_00347f80");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_00347e60[] asm("D_00347e60");
void func_002361a0(u8*) asm("func_002361a0");
void func_0023f800(u32) asm("func_0023f800");
extern char D_01e21ef8[] asm("D_01e21ef8");
extern char D_003743f8[] asm("D_003743f8");
void func_0023fa90(u32, char*) asm("func_0023fa90");
u32 func_0023f988(u32, u32) asm("func_0023f988");
void dk__SpriteImage__create(u8*, u32, u32, u32) asm("dk__SpriteImage__create");
static inline u8* heap_alloc_w96(u32 size) {
    void* h = *(void**)(D_00347f80 + 20);
    return (**(AllocFn_w96**)h)(h, size, 0);
}
/*TARGET 002874b0*/
void func_002874b0(u8* self) asm("func_002874b0");
void func_002874b0(u8* self) {
    u8* o;
    s32 i;
    o = heap_alloc_w96(448);
    *(u32*)(o + 12) = 0;
    *(u32*)o = (u32)D_00347e80;
    func_002361a0(o + 32);
    *(u8**)self = o;
    func_0023f800((u32)self + 12);
    for (i = 0; i < 2; i++) {
        o = heap_alloc_w96(408);
        *(u32*)(o + 12) = 0;
        *(u32*)o = (u32)D_00347e60;
        func_00239700((u32)o + 24);
        ((u8**)(self + 4))[i] = o;
    }
    func_002fee78(D_01e21ef8, D_003743f8, D_0033caf4);
    func_0023fa90((u32)self + 12, D_01e21ef8);
    dk__SpriteImage__create(*(u8**)self, 26000, func_0023f988((u32)self + 12, 0), 0);
}
}  // namespace n002874b0

// 002875e8 (was src/anon/batch_w97.cpp)
namespace n002875e8 {
struct Alloc287;
typedef u8* (*AllocFn287)(Alloc287*, s32, s32);
struct Alloc287 { AllocFn287* vt; };
struct Heap287 { u8 pad[20]; Alloc287* alloc; };
extern Heap287* D_00347f80 asm("D_00347f80");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_00347e60[] asm("D_00347e60");
extern char D_01e21ef8[] asm("D_01e21ef8");
extern char D_003743f8[] asm("D_003743f8");
extern u32 D_0033caf4 asm("D_0033caf4");
void func_002361a0(u8*) asm("func_002361a0");
void func_0023f800(u8*) asm("func_0023f800");
void func_00239700(u8*) asm("func_00239700");
void func_002fee78(char*, char*, u32) asm("func_002fee78");
void func_0023fa90(u8*, char*) asm("func_0023fa90");
u32 func_0023f988(u8*, s32) asm("func_0023f988");
void dk__SpriteImage__create(u8*, s32, u32, s32) asm("dk__SpriteImage__create");
/*TARGET 002875e8*/
void Tz__Mg2DTron__Mg2DTron(u8** o) asm("Tz__Mg2DTron__Mg2DTron");
void Tz__Mg2DTron__Mg2DTron(u8** o) {
    Alloc287* a = D_00347f80->alloc;
    u8* v = a->vt[0](a, 448, 0);
    *(u32*)(v + 12) = 0;
    *(u32*)v = (u32)D_00347e80;
    func_002361a0(v + 32);
    o[0] = v;
    func_0023f800((u8*)(o + 3));
    u8** slot = o + 1;
    for (s32 k = 1; k >= 0; k--) {
        a = D_00347f80->alloc;
        v = a->vt[0](a, 408, 0);
        *(u32*)(v + 12) = 0;
        *(u32*)v = (u32)D_00347e60;
        func_00239700(v + 24);
        *slot++ = v;
    }
    func_002fee78(D_01e21ef8, D_003743f8, D_0033caf4);
    func_0023fa90((u8*)(o + 3), D_01e21ef8);
    dk__SpriteImage__create(o[0], 26000, func_0023f988((u8*)(o + 3), 0), 0);
}
}  // namespace n002875e8

// 00287720 (was src/anon/batch_w14.cpp)
namespace n00287720 {
void func_002878c8(void*) asm("func_002878c8");
u8 func_0023f848(void*) asm("func_0023f848");
/*TARGET 00287720*/
// 00242368: moved to src/tozawa/crc.cpp (linked unit)

s32 func_00287720(u8* p) asm("func_00287720");
// 00242368: moved to src/tozawa/crc.cpp (linked unit)

s32 func_00287720(u8* p) {
    func_002878c8(p);
    void** o = *(void***)p;
    (*(void (**)(void*))(*(u8**)o + 20))(o);
    return func_0023f848(p + 12);
}
}  // namespace n00287720

// 00287760 (was src/anon/batch_w15.cpp)
namespace n00287760 {
typedef void (*VFn)(void*);
void func_002878c8(void*) asm("func_002878c8");
u8 func_0023f848(void*) asm("func_0023f848");
/*TARGET 00287760*/
u8 func_00287760(u8* p) asm("func_00287760");
u8 func_00287760(u8* p) {
    func_002878c8(p);
    void** o = *(void***)p;
    (*(VFn*)((*(u8**)o) + 20))(o);
    return func_0023f848(p + 12);
}
}  // namespace n00287760

// 002877a0 (was src/anon/batch_w82.cpp)
namespace n002877a0 {
s32 func_00139d78(void*) asm("func_00139d78");
void func_00138c10(u8*, u32) asm("func_00138c10");
extern s16 D_00374410[][5] asm("D_00374410");
u32 func_0023f9c8(u8*, s32) asm("func_0023f9c8");
void dk__Sprite__create(u32, s32, u32, u32, s32, s32) asm("dk__Sprite__create");
/*TARGET 002877a0*/
void Tz__Mg2DTron__CreateSeq(u8* a0, s32 a1, s32 a2) asm("Tz__Mg2DTron__CreateSeq");
void Tz__Mg2DTron__CreateSeq(u8* a0, s32 a1, s32 a2)
{
    u32* slot = (u32*)(a1 * 4 + (u32)a0);
    if (func_00139d78((void*)slot[1])) {
        func_00138c10((u8*)slot[1], D_00374410[a1][a2]);
        return;
    }
    dk__Sprite__create(slot[1], 26006, func_0023f9c8(a0 + 12, 0), *(u32*)a0 + 32, D_00374410[a1][a2], 0);
}
}  // namespace n002877a0

// 00287880 (was src/anon/tiny_auto80_queue.cpp)
namespace n00287880 {
u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 00287880*/
void func_00287880(void* a0, u32 a1) asm("_Z13func_00287880Pvj");
void func_00287880(void* a0, u32 a1) {
    u8* s0 = (u8*)((a1 << 2) + (u32)a0);
    if (func_00139d78(*(void**)(s0 + 4)) == 0u) {
        return;
    }
    void* obj = *(void**)(s0 + 4);
    ((void (*)(void*))(*(u32*)(*(u32*)obj + 20u)))(obj);
}
}  // namespace n00287880

// 002878c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002878c8 {
void func_00287880(void* a0, u32 a1) asm("_Z13func_00287880Pvj");
/*TARGET 002878c8*/
void func_002878c8(void* a0) asm("_Z13func_002878c8Pv");
void func_002878c8(void* a0) {
    s32 s0 = 0;
    do {
        func_00287880(a0, (u32)s0);
        s0 = s0 + 1;
    } while (s0 < 2);
}
}  // namespace n002878c8

// 00287910 (was src/anon/batch_w95.cpp)
namespace n00287910 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct Heap2;
struct Heap2Vt { void* (*alloc)(Heap2*, u32, u32); };
struct Heap2 { Heap2Vt* vt; };
struct HeapOwner { u8 pad[20]; Heap2* heap; };
union HeapOwnerRef { HeapOwner* p; s32 i; };
extern HeapOwnerRef D_00347f80 asm("D_00347f80");
extern u32 D_0035f318 asm("D_0035f318");
extern u32 D_0035f2ec asm("D_0035f2ec");
extern void* D_0035f31c asm("D_0035f31c");
extern u8 D_0035f314 asm("D_0035f314");
extern u32 D_0035f2e8 asm("D_0035f2e8");
extern u8 D_0035f320 asm("D_0035f320");
u32 func_00103570(void) asm("func_00103570");
void func_00139e00(u32, u8) asm("func_00139e00");
void func_0023edb0(u32) asm("func_0023edb0");
void func_00288b18(u32) asm("func_00288b18");
void YI__IMAGE_CACHE__Clear(void) asm("YI__IMAGE_CACHE__Clear");
// clear_64_entries_24
void func_00287b30(void) asm("func_00287b30");
void func_00287d08(void) asm("func_00287d08");
void func_0023ed00(u32) asm("func_0023ed00");
void func_0023d4f8(void*, u32) asm("func_0023d4f8");
void func_00287c20(void) asm("func_00287c20");
// clear_global_flag_return_m1
void Tz__MenuItem__init(u32) asm("Tz__MenuItem__init");
void Tz__MenuBase__SavePadInit(u32) asm("Tz__MenuBase__SavePadInit");
/*TARGET 00287910*/
void func_00287910(u32 a, u32 b, u8 c) asm("func_00287910");
void func_00287910(u32 a, u32 b, u8 c) {
    func_00139e00(func_00103570(), c);
    func_0023edb0(func_00103570());
    func_00288b18(func_00103570());
    YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
    func_00287b30();
    func_00287d08();
    func_0023ed00(7);
    D_0035f318 = b;
    D_0035f2ec = a;
    if (b) {
        Heap2* h = D_00347f80.p->heap;
        void* m = h->vt->alloc(h, 5360, 0);
        func_0023d4f8(m, D_0035f318);
        D_0035f31c = m;
    }
    D_0035f314 = 0;
    func_00287c20();  // clear_global_flag_return_m1
    Tz__MenuItem__init(func_00103570());
    D_0035f2e8 = 0;
    D_0035f320 = 0;
    Tz__MenuBase__SavePadInit(func_00103570());
}
}  // namespace n00287910

// 00287a28 (was src/anon/batch_w68.cpp)
namespace n00287a28 {
s32 func_001991a8(u32, u32) asm("func_001991a8");
/* ---- 00287a28 ---- */
void func_0028c4f8(void) asm("func_0028c4f8");
void func_0023ede8(void) asm("func_0023ede8");
void func_00288b78(void) asm("func_00288b78");
void func_0023ed38(void) asm("func_0023ed38");
void func_00287c20(void) asm("func_00287c20");
// clear_global_flag_return_m1
void func_00287f30(void) asm("func_00287f30");
struct VObj { void (**vt)(VObj*); };
extern s32 D_0035f2ec asm("D_0035f2ec");
extern s32 D_0035f318 asm("D_0035f318");
extern s32 D_0035f2f0 asm("D_0035f2f0");
extern s32 D_0035f2f4 asm("D_0035f2f4");
extern VObj* D_0035f31c asm("D_0035f31c");
extern void* D_0035f2e8 asm("D_0035f2e8");
/*TARGET 00287a28*/
void Tz__MenuBase__Exit(void) asm("Tz__MenuBase__Exit");
void Tz__MenuBase__Exit(void) {
    func_0028c4f8();
    func_0023ede8();
    func_00288b78();
    func_0023ed38();
    D_0035f2ec = -1;
    D_0035f318 = 0;
    D_0035f2f0 = 0;
    D_0035f2f4 = 0;
    func_00287c20();  // clear_global_flag_return_m1
    if (D_0035f31c) {
        D_0035f31c->vt[4](D_0035f31c);
        D_0035f31c = 0;
    }
    func_00287f30();
    if (D_0035f2e8) func_001991a8((u32)D_0035f2e8, 0);
    D_0035f2e8 = 0;
}
}  // namespace n00287a28

// 00287ad0 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n00287ad0 {
u32 func_00287b30() asm("_Z13func_00287b30v");
u32 func_00287c20() asm("_Z13func_00287c20v");
// clear_global_flag_return_m1
u32 func_00287d08() asm("_Z13func_00287d08v");
/*TARGET 00287ad0*/
u32 func_00287ad0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00287ad0jjjj");
u32 func_00287ad0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    u32 (*fp_call0_00287b30)() = func_00287b30;
    r2 = fp_call0_00287b30();
    u32 (*fp_call0_00287d08)() = func_00287d08;
    r2 = fp_call0_00287d08();
    u32 (*fp_call0_00287c20)() = func_00287c20;
    r2 = fp_call0_00287c20();
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(-3308)) = (u8)0u;
    return r2;
}
}  // namespace n00287ad0

// 00287b08 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287b08
extern u32 D_0035f2e8 asm("D_0035f2e8");
/*TARGET 00287b08*/
void MenuBase::SetSignal(s32 v) { D_0035f2e8 = (u32)v; }
}  // Tz

// 00287b18 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287b18
extern u32 D_0035f2f0 asm("D_0035f2f0");
extern u32 D_0035f2f4 asm("D_0035f2f4");
/*TARGET 00287b18*/
void MenuBase::SetModeMax(s32 modeMax, s32 smodeMax) {
    D_0035f2f0 = (u32)modeMax;
    D_0035f2f4 = (u32)smodeMax;
}
}  // Tz

// 00287b30 (was src/anon/batch_w13.cpp)
namespace n00287b30 {
void func_00287c78(s32) asm("func_00287c78");
extern void (*D_0035e380[])(void) asm("D_0035e380");
extern s32 D_0035f2f0 asm("D_0035f2f0");
extern s32 D_0035f2f4 asm("D_0035f2f4");
extern s32 D_0035f2f8 asm("D_0035f2f8");
extern s32 D_0035f2fc asm("D_0035f2fc");
/*TARGET 00287b30*/
void func_00287b30(void) asm("func_00287b30");
void func_00287b30(void) {
    D_0035f2f0 = 0;
    D_0035f2f4 = 0;
    D_0035f2f8 = 0;
    D_0035f2fc = -1;
    func_00287c78(0);
}
}  // namespace n00287b30

// 00287b70 (was gap, written for the unit)
namespace n00287b70 {
extern s32 D_0035f2f8 asm("D_0035f2f8");
void func_00287c78(void) asm("func_00287c78");
void func_00287c20(void) asm("func_00287c20");
void func_00287b70(void) asm("func_00287b70");
void func_00287b70(void) {
    D_0035f2f8++;
    func_00287c78();
    func_00287c20();
}
}  // namespace n00287b70

// 00287b98 (was src/anon/batch_w19.cpp)
namespace n00287b98 {
void func_00287c78(void) asm("func_00287c78");
void func_00287c20(void) asm("func_00287c20");
extern s32 D_0035f2f8 asm("D_0035f2f8");
/*TARGET 00287b98*/
// 0x0025cd40: definition moved into src/anon/unit_002588e8.cpp

void func_00287b98(void) asm("func_00287b98");
// 0x0025cd40: definition moved into src/anon/unit_002588e8.cpp

void func_00287b98(void) {
    D_0035f2f8--;
    func_00287c78();
    func_00287c20();  // clear_global_flag_return_m1
}
}  // namespace n00287b98

// 00287bc0 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287bc0
extern u32 D_0035f2f8 asm("D_0035f2f8");
/*TARGET 00287bc0*/
s32 MenuBase::GetMode() { return (s32)D_0035f2f8; }
}  // Tz

// 00287bd0 (was src/anon/batch_w8.cpp)
namespace n00287bd0 {
extern s32 D_0035f2f8 asm("D_0035f2f8");
void func_00287c20(void) asm("func_00287c20");
// clear_global_flag_return_m1
void func_00287c78(s32) asm("func_00287c78");
void next_mode_to_mode(s32 mode, s32 next) asm("_ZN2Tz8MenuBase14NextModeToModeEz");
/*TARGET 00287bd0*/
void next_mode_to_mode(s32 mode, s32 next) asm("_ZN2Tz8MenuBase14NextModeToModeEz");
void next_mode_to_mode(s32 mode, s32 next) {
    D_0035f2f8 = mode;
    func_00287c20();  // clear_global_flag_return_m1
    func_00287c78(next);
}
}  // namespace n00287bd0

// 00287c00 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287c00
extern u32 D_0035f300 asm("D_0035f300");
/*TARGET 00287c00*/
void MenuBase::SetNextMode(s32 v) { D_0035f300 = (u32)v; }
}  // Tz

// 00287c10 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287c10
extern u32 D_0035f300 asm("D_0035f300");
/*TARGET 00287c10*/
s32 MenuBase::GetNextMode() { return (s32)D_0035f300; }
}  // Tz

// 00287c20 (was src/anon/tiny.cpp)
namespace n00287c20 {
extern u32 D_0035f300 asm("D_0035f300");
/*TARGET 00287c20*/
void func_00287c20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00287c20jjjj");
void func_00287c20(u32 a0, u32 a1, u32 a2, u32 a3) {  // clear_global_flag_return_m1
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    D_0035f300 = (u32)((s32)-1);
}
}  // namespace n00287c20

// 00287c30 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287c30
u32 func_00287bd0(...) asm("func_00287bd0");
/*TARGET 00287c30*/
u32 MenuBase::NextMode2Mode() {
    u32 r15 = (u32)(0x0036u << 16);
    u32 r5 = 0u;
    u32 r4 = *(u32*)((u32)r15 + (s32)(-3328));
    return func_00287bd0(r4, r5);
}
}  // Tz

// 00287c50 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287c50
extern u32 D_0035f2f8 asm("D_0035f2f8");
extern u32 D_0035f2fc asm("D_0035f2fc");
/*TARGET 00287c50*/
u32 MenuBase::IsChgMode() {
    s32 t = (s32)D_0035f2fc;
    if (t >= 0) {
        return ((u32)(D_0035f2f8 ^ (u32)t)) != 0u;
    }
    return 0u;
}
}  // Tz

// 00287c78 (was src/anon/tiny_auto80_solver.cpp)
namespace n00287c78 {
// clear_global_flag_return_m1
void func_00287c78(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00287c78jjjjjjjj");
extern u32 D_0035f304 asm("D_0035f304");
extern u32 D_0035f308 asm("D_0035f308");
/*TARGET 00287c78*/
void func_00287c78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00287c78jjjjjjjj");
void func_00287c78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15;
    r14 = (u32)((s32)0u + (-1));
    D_0035f304 = r4;
    D_0035f308 = r14;
}
}  // namespace n00287c78

// 00287c90 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287c90
extern u32 D_0035f304 asm("D_0035f304");
/*TARGET 00287c90*/
void MenuBase::IncSMode(s32 delta) { D_0035f304 = D_0035f304 + (u32)delta; }
}  // Tz

// 00287ca8 (was gap, written for the unit)
namespace n00287ca8 {
extern s32 D_0035f304 asm("D_0035f304");
void func_00287ca8(void) asm("func_00287ca8");
void func_00287ca8(void) {
    D_0035f304--;
}
}  // namespace n00287ca8

// 00287cc0 (was src/tozawa/cmenu_selector.cpp)
namespace Tz { // method 00287cc0
extern u32 D_0035f304 asm("D_0035f304");
/*TARGET 00287cc0*/
void Selector::SetState(s32 v) { D_0035f304 = (u32)v; }
}  // Tz

// 00287cd0 (was src/tozawa/cmenu_selector.cpp)
namespace Tz { // method 00287cd0
extern u32 D_0035f304 asm("D_0035f304");
/*TARGET 00287cd0*/
u32 Selector::GetState() { return D_0035f304; }
}  // Tz

// 00287ce0 (was gap, written for the unit)
namespace n00287ce0 {
extern s32 D_0035f304 asm("D_0035f304");
extern s32 D_0035f308 asm("D_0035f308");
u32 func_00287ce0(void) asm("func_00287ce0");
u32 func_00287ce0(void) {
    s32 v = D_0035f308;
    if (v >= 0) return D_0035f304 != v;
    return 0;
}
}  // namespace n00287ce0

// 00287d08 (was src/anon/auto200_999.cpp)
namespace n00287d08 {
extern u32 D_0035f30c asm("D_0035f30c");
extern u32 D_0035f310 asm("D_0035f310");
/*TARGET 00287d08*/
void func_00287d08() asm("_Z13func_00287d08v");
void func_00287d08() {
    D_0035f30c = 0;
    D_0035f310 = 0xffffffff;
}
}  // namespace n00287d08

// 00287d20 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287d20
extern u32 D_0035f30c asm("D_0035f30c");
/*TARGET 00287d20*/
void MenuBase::SetPhase(s32 v) { D_0035f30c = (u32)v; }
}  // Tz

// 00287d30 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287d30
extern u32 D_0035f30c asm("D_0035f30c");
/*TARGET 00287d30*/
s32 MenuBase::GetPhase() { return (s32)D_0035f30c; }
}  // Tz

// 00287d40 (was gap, written for the unit)
namespace n00287d40 {
extern s32 D_0035f30c asm("D_0035f30c");
extern s32 D_0035f310 asm("D_0035f310");
u32 func_00287d40(void) asm("func_00287d40");
u32 func_00287d40(void) {
    s32 v = D_0035f310;
    if (v >= 0) return D_0035f30c != v;
    return 0;
}
}  // namespace n00287d40

// 00287d68 (was src/anon/batch_w19.cpp)
namespace n00287d68 {
extern s32 D_0035f2f8 asm("D_0035f2f8");
extern s32 D_0035f2fc asm("D_0035f2fc");
extern s32 D_0035f304 asm("D_0035f304");
extern s32 D_0035f308 asm("D_0035f308");
extern s32 D_0035f30c asm("D_0035f30c");
extern s32 D_0035f310 asm("D_0035f310");
/*TARGET 00287d68*/
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
void Tz__MenuBase__SaveMode(void) {  // copy_globals_3words
    D_0035f2fc = D_0035f2f8;
    D_0035f308 = D_0035f304;
    D_0035f310 = D_0035f30c;
}
}  // namespace n00287d68

// 00287da0 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287da0
extern u8 D_0035f314 asm("D_0035f314");
/*TARGET 00287da0*/
void MenuBase::SetExit() {
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035f314 = (u8)v;
}
}  // Tz

// 00287db0 (was src/tozawa/cmenu_item.cpp)
namespace Tz { // method 00287db0
extern u8 D_0035f314 asm("D_0035f314");
/*TARGET 00287db0*/
u32 CmItem::isPadHelpVisible() {
    (void)D_0035f314;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-3308)));
}
}  // Tz

// 00287dc0 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00287dc0
extern u32 D_0035f31c asm("D_0035f31c");
/*TARGET 00287dc0*/
void* MenuBase::GetMenuObj() { return reinterpret_cast<void*>(D_0035f31c); }
}  // Tz

// 00287dd0 (was gap, written for the unit)
namespace n00287dd0 {
extern s32 D_0035f2ec asm("D_0035f2ec");
s32 func_00287dd0(void) asm("func_00287dd0");
s32 func_00287dd0(void) {
    return D_0035f2ec;
}
}  // namespace n00287dd0

// 00287de0 (was gap, written for the unit)
namespace n00287de0 {
extern s32 D_0035f318 asm("D_0035f318");
s32 func_00287de0(void) asm("func_00287de0");
s32 func_00287de0(void) {
    return D_0035f318;
}
}  // namespace n00287de0

// 00287df0 (was src/anon/batch_w3733.cpp)
namespace n00287df0 {
s32 func_00242618(s32, u8) asm("func_00242618");
/*TARGET 00287df0*/
// Picks a mode for a selection value a and passes it to func_00242618 with e.
// k is pinned to t5 (the original keeps it there; unpinned gcc puts it in t6).
s32 func_00287df0(s32 a, u8 b, u8 c, s32 (*d)(void), u8 e) asm("func_00287df0");
// Picks a mode for a selection value a and passes it to func_00242618 with e.
// k is pinned to t5 (the original keeps it there; unpinned gcc puts it in t6).
s32 func_00287df0(s32 a, u8 b, u8 c, s32 (*d)(void), u8 e) {
    register s32 k asm("$13");
    if (b != 0) k = 1;
    else if (a == -2) k = 3;
    else if ((u32)(a + 13) < 2) k = 1;
    else if (a == -4) { s32 t = c ? 5 : 4; k = t; }
    else {
        if ((u32)(a + 7) < 3) goto L;
        if ((u32)(a + 9) < 2) goto L;
        if ((u32)(a + 11) < 2) goto L;
        if (a < 0) return 0;
    L:
        k = 2;
        if (d) k = d() ? 2 : 4;
    }
    return func_00242618(k, e);
}
}  // namespace n00287df0

// 00287eb8 (was src/anon/tiny.cpp)
namespace n00287eb8 {
extern u32 D_0035f320 asm("D_0035f320");
/*TARGET 00287eb8*/
void func_00287eb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00287eb8jjjj");
void func_00287eb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = a0 & 0xffu;
    *(u8*)&D_0035f320 = (u8)v;
}
}  // namespace n00287eb8

// 00287ec8 (was src/anon/tiny.cpp)
namespace n00287ec8 {
/*TARGET 00287ec8*/
u32 func_00287ec8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00287ec8jjjj");
u32 func_00287ec8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_byte_36f320
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-3296)));
}
}  // namespace n00287ec8

// 00287ed8 (was src/anon/batch_wcx2.cpp)
namespace n00287ed8 {
// --------------------
extern void* D_0035f324 asm("D_0035f324");
void func_00167658(void*, s32) asm("func_00167658");
void func_00288018() asm("func_00288018");
void* func_001063c0_x10951(s32, s32) asm("func_001063c0");
/*TARGET 00287ed8*/
void Tz__MenuBase__SavePadInit(s32 a) asm("Tz__MenuBase__SavePadInit");
void Tz__MenuBase__SavePadInit(s32 a) {
    if (!D_0035f324) {
        void* p = func_001063c0_x10951(80, a);
        func_00167658(p, 0);
        D_0035f324 = p;
    }
    func_00288018();
}
}  // namespace n00287ed8

// 00287f30 (was src/anon/batch_w38.cpp)
namespace n00287f30 {
// 16-byte element with an empty destructor; arrays of it get a destructor loop.
struct E16 { u8 d[16]; ~E16() {} };
void func_00106420(void*) asm("func_00106420");
struct Obj287f30 {
    u8 pad[32];
    E16 arr[2];
    static void operator delete(void* p) { func_00106420(p); }
};
extern Obj287f30* D_0035f324 asm("D_0035f324");
/*TARGET 00287f30*/
void func_00287f30(void) asm("func_00287f30");
void func_00287f30(void) {
    if (D_0035f324) {
        delete D_0035f324;
        D_0035f324 = 0;
    }
}
}  // namespace n00287f30

// 00287f90 (was src/anon/perm_00287f90.cpp)
namespace n00287f90 {
typedef unsigned long long u64;
typedef signed int s32;
s32 func_00167f18(void) asm("_ZN2Tz10MenuCursor13GetInputStateEz");
extern volatile long * volatile D_0035f324 asm("D_0035f324");
/*TARGET 00287f90*/
void func_00287f90(u64 *s) asm("func_00287f90");
void func_00287f90(u64 *s)
{
  u64 a;
  u64 b;
  u64 c;
  u64 d;
  if (!s)
  {
    s = (u64 *) func_00167f18();
  }
  a = s[0];
  b = s[1];
  c = s[2];
  d = s[3];
  D_0035f324[0] |= a;
  D_0035f324[1] |= b;
  D_0035f324[2] |= c;
  D_0035f324[3] |= d;
}
}  // namespace n00287f90

// 00288008 (was src/anon/tiny.cpp)
namespace n00288008 {
/*TARGET 00288008*/
u32 func_00288008(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00288008jjjj");
u32 func_00288008(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36f7d4
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-3292)));
}
}  // namespace n00288008

// 00288018 (was src/anon/batch_w6.cpp)
namespace n00288018 {
// Clear four doublewords of the buffer.
extern volatile u64* volatile D_0035f324 asm("D_0035f324");
/*TARGET 00288018*/
void func_00288018(void) asm("func_00288018");
void func_00288018(void) {  // global_zero_4dwords
    D_0035f324[0] = 0;
    D_0035f324[1] = 0;
    D_0035f324[2] = 0;
    D_0035f324[3] = 0;
}
}  // namespace n00288018

// 00288040 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00288040
extern u64* D_0035f324 asm("D_0035f324");
/*TARGET 00288040*/
u32 MenuBase::isSavePad() {
    u64* p = D_0035f324;
    u32 v0 = 0u;
    if (p == (u64*)0) {
        goto end;
    }
    if (p[0] != 0ull) {
        goto one;
    }
    if (p[1] != 0ull) {
        goto one;
    }
    if (p[2] != 0ull) {
        goto one;
    }
    if (p[3] != 0ull) {
        goto one;
    }
    goto end;
one:
    v0 = 1u;
end:
    return v0;
}
}  // Tz

// 00288088 (was src/anon/batch_w9.cpp)
namespace n00288088 {
u8* func_00167f18(u32) asm("func_00167f18");
/*TARGET 00288088*/
s32 Tz__MenuBase__isPressAnyKey(void) asm("Tz__MenuBase__isPressAnyKey");
s32 Tz__MenuBase__isPressAnyKey(void) {
    return *(u64*)(func_00167f18(0) + 8) != 0;
}
}  // namespace n00288088

