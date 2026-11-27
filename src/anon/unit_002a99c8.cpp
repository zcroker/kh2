// Linked unit 0x002a99c8-0x002aeb28 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/jm_newinfo.hpp"
#include "../tozawa/jm_complete.hpp"
#include "../tozawa/jm_puzzle.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002a99c8 (was src/anon/batch_w112.cpp)
namespace n002a99c8 {
struct LRec { u16 id; u16 val; u16 pad; u16 flags; u16 h8; u16 h10; u16 h12; u16 h14; };
struct Info { u8 type; u8 pad[3]; u32 value; };
s32 func_00181500(u32) asm("func_00181500");
s32 func_001a6d08(u32) asm("func_001a6d08");
Info* func_001d56c8(u32) asm("func_001d56c8");
s32 func_00276c18(void) asm("func_00276c18");
void dk__Clock__vCountToHMSMS(u32, s32*, s32*, s32*, s32*) asm("dk__Clock__vCountToHMSMS");
// Evaluates an entry's unlock condition: 0 = locked, 1 = available, 2 = cleared, 3 = forced.
s32 Tz__JmQuest__GetQuestStat(LRec* r) asm("Tz__JmQuest__GetQuestStat");
// Evaluates an entry's unlock condition: 0 = locked, 1 = available, 2 = cleared, 3 = forced.
s32 Tz__JmQuest__GetQuestStat(LRec* r) {
    s32 st = 0;
    if (r->flags & 1) {
        if (func_00181500(r->h8)) st = 1;
    } else st = func_001a6d08(r->h8) != 0;
    if (st) {
        if (r->flags & 4) st = func_001d56c8(r->h10)->type != 0;
    }
    if (!st) return func_00276c18() ? 3 : st;
    {
        {
            u16 f = r->flags;
            if (f & 0x10) {
                if (func_00181500(r->h14)) st = 2;
            } else if (f & 0x20) {
                if (func_001a6d08(r->h14)) st = 2;
            } else {
                Info* x = func_001d56c8(r->h10);
                if (r->flags & 0x1000) {
                    if (x->type) st = 2;
                } else if (r->flags & 0x2000) {
                    if (x->type >= 2) st = 2;
                } else if (x->type >= 2) {
                    u32 v;
                    if (x->type != 4) v = x->value;
                    else {
                        s32 h, m, s, fr;
                        dk__Clock__vCountToHMSMS(x->value, &h, &m, &s, &fr);
                        v = h * 3600 + m * 60 + s;
                        if (fr != 0) v++;
                    }
                    if (r->flags & 0x100) {
                        if (!(r->h12 < v)) st = 2;
                    } else if (r->flags & 0x200) {
                        if (!(v < r->h12)) st = 2;
                    }
                }
            }
        }
    }
    return st;
}
}  // namespace n002a99c8

// 002a9b88 (was src/anon/batch_wcx.cpp)
namespace n002a9b88 {
u8* func_00294000(s32) asm("func_00294000");
s32 func_00276c18(void) asm("func_00276c18");
struct Ent16 { u16 id; u8 pad[14]; };
s32 Tz__JmQuest__GetQuestStat(Ent16*) asm("Tz__JmQuest__GetQuestStat");
// 002a9b88: is there a matching table-8 entry (id < 0 = any) that accepts?
s32 Tz__JmQuest__isEnable(s32 id) asm("Tz__JmQuest__isEnable");
// 002a9b88: is there a matching table-8 entry (id < 0 = any) that accepts?
s32 Tz__JmQuest__isEnable(s32 id)
{
    u8* t = func_00294000(8);
    Ent16* e = (Ent16*)(t + 16);
    s32 i;
    for (i = 0; i < *(s32*)(t + 8); i++) {
        if (id >= 0 && e[i].id != id) continue;
        if (func_00276c18()) break;
        if (Tz__JmQuest__GetQuestStat(&e[i])) break;
    }
    return i < *(s32*)(t + 8);
}
}  // namespace n002a9b88

// 002a9c40 (was src/anon/batch_wcx2.cpp)
namespace n002a9c40 {
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
// --------------------
struct E2a9c40 { u16 a; u16 id; u8 pad[12]; };
struct T2a9c40 { u8 pad[8]; s32 n; u8 pad2[4]; E2a9c40 e[1]; };
T2a9c40* func_00294000_2a9c40(s32) asm("func_00294000");
s32 Tz__JmQuest__GetQuestStat(E2a9c40*) asm("Tz__JmQuest__GetQuestStat");
s32 func_002a9c40(u32 id) asm("func_002a9c40");
s32 func_002a9c40(u32 id)
{
    s32 i = 0;
    s32 r = 0;
    T2a9c40* t = func_00294000_2a9c40(8);
    E2a9c40* e = t->e;
    for (; i < t->n; i++) {
        if (id != e[i].id) continue;
        s32 k = Tz__JmQuest__GetQuestStat(&e[i]);
        if (k == 1 || k == 2) {
            r = 1;
            break;
        }
    }
    return r;
}
}  // namespace n002a9c40

// 002a9ce8 (was src/anon/batch_w1586_g.cpp)
namespace n002a9ce8 {
extern s32 D_0035f610 asm("D_0035f610");
s32 func_00103570(void) asm("func_00103570");
s32 func_001063c0(s32, s32) asm("func_001063c0");
void func_00319a60(s32) asm("func_00319a60");
void Tz__JmNewInfo__Init(void) asm("Tz__JmNewInfo__Init");
void Tz__JmNewInfo__Init(void) {
    s32 p = func_001063c0(0x968, func_00103570());
    func_00319a60(p);
    D_0035f610 = p;
}
}  // namespace n002a9ce8

// 002a9d30 (was src/tozawa/jm_newinfo.cpp)
namespace Tz { // method 002a9d30
void func_00106420(u32) asm("func_00106420");
extern u32 D_0035f610 asm("D_0035f610");
void JmNewInfo::Exit() {
    u32 r15 = D_0035f610;
    if (r15 != 0u) {
        func_00106420(r15);
        D_0035f610 = 0u;
    }
}
}  // Tz

// 002a9d68 (was src/tozawa/jm_newinfo.cpp)
namespace Tz { // method 002a9d68
u32 getSaveRam() asm("_Z10getSaveRamv");
u32 JmNewInfo::GetSram() {
    u32 r2 = getSaveRam();
    r2 = (u32)((s32)r2 + 19512);
    return r2;
}
}  // Tz

// 002a9d88 (was src/tozawa/jm_newinfo.cpp)
namespace Tz { // method 002a9d88
void func_002a9df0(...) asm("func_002a9df0");
void func_002aa220(...) asm("func_002aa220");
void func_002aa4a8(...) asm("func_002aa4a8");
void func_002aa960(...) asm("func_002aa960");
void func_002aabe8(...) asm("func_002aabe8");
void func_002ab020(...) asm("func_002ab020");
void Tz__JmNewInfo__CheckTreasure(...) asm("Tz__JmNewInfo__CheckTreasure");
void func_002ab818(...) asm("func_002ab818");
void func_002abba8(...) asm("func_002abba8");
void func_002abe28(...) asm("func_002abe28");
void func_002ac2e8(...) asm("func_002ac2e8");
void JmNewInfo::CheckAll() {
    func_002a9df0();
    func_002aa220();
    func_002aa4a8();
    func_002aa960();
    func_002aabe8();
    func_002ab020();
    Tz__JmNewInfo__CheckTreasure();
    func_002ab818();
    func_002abba8();
    func_002abe28();
    func_002ac2e8();
}
}  // Tz

// 002a9df0 (was src/anon/batch_w67.cpp)
namespace n002a9df0 {
struct BitInfo { u32 a, b; s32 n; };
u32* func_002a9d68(void) asm("func_002a9d68");
void func_00294020(u32*) asm("func_00294020");
BitInfo* func_00294000(s32) asm("func_00294000");
union PtrWord { u32* p; u32 u; };
extern PtrWord D_0035f610 asm("D_0035f610");
// 002a9df0: clear the bits that are also set in the other set
void func_002a9df0(void) asm("func_002a9df0");
// 002a9df0: clear the bits that are also set in the other set
void func_002a9df0(void)
{
    u32* other = func_002a9d68();
    func_00294020(D_0035f610.p);
    BitInfo* v = func_00294000(3);
    for (s32 i = 0; i < v->n; i++) {
        u32* base = D_0035f610.p;
        u32 off = (u32)i >> 5;
        u32 m = 1 << (i & 31);
        u32 w = base[off];
        if ((w & m) && (other[off] & m)) base[off] = w & ~m;
    }
}
}  // namespace n002a9df0

// 002a9e98 (was src/anon/batch_wcx.cpp)
namespace n002a9e98 {
u8* func_00294000(s32) asm("func_00294000");
extern u32* D_0035f610 asm("D_0035f610");
s32 Tz__JmNewInfo__isCharaNew(s32 id) asm("Tz__JmNewInfo__isCharaNew");
s32 Tz__JmNewInfo__isCharaNew(s32 id)
{
    s32 r = 0;
    u8* t = func_00294000(3);
    if (id < 0) {
        for (u32 i = 0; (s32)i < *(s32*)(t + 8); i++) {
            r = (D_0035f610[i >> 5] & (1 << (i & 31))) != 0;
            if (r) break;
        }
    } else {
        r = (D_0035f610[(u32)id >> 5] & (1 << (id & 31))) != 0;
    }
    return r;
}
}  // namespace n002a9e98

// 002a9f50 (was src/anon/batch_w86.cpp)
namespace n002a9f50 {
struct Lst { u8 p0[8]; s32 n; };
extern u32* D_0035f610 asm("D_0035f610");
u32* func_002a9d68(void) asm("func_002a9d68");
Lst* func_00294000(s32) asm("func_00294000");
s32 func_002a9f50(s32 id) asm("func_002a9f50");
s32 func_002a9f50(s32 id)
{
    s32 r = 1;
    u32* bits = func_002a9d68();
    Lst* l = func_00294000(3);
    if (id < 0) {
        s32 n = l->n;
        for (s32 i = 0; i < n; i++) {
            u32 m = 1 << (i & 31);
            if (D_0035f610[(u32)i >> 5] & m) {
                r = (bits[(u32)i >> 5] & m) != 0;
                if (!r) break;
            }
        }
    } else {
        u32 m = 1 << (id & 31);
        s32 t = 0;
        if (D_0035f610[(u32)id >> 5] & m) t = (bits[(u32)id >> 5] & m) != 0;
        r = t;
    }
    return r;
}
}  // namespace n002a9f50

// 002aa048 (was src/anon/batch_w30.cpp)
namespace n002aa048 {
u32* func_002a9d68(void) asm("func_002a9d68");
// Sets bit n in the bitmap returned by func_002a9d68.
void func_002aa048(u32 n) asm("func_002aa048");
// Sets bit n in the bitmap returned by func_002a9d68.
void func_002aa048(u32 n) {
    u32* b = func_002a9d68();
    u32 bit = 1 << (n & 31);
    if (!(b[n >> 5] & bit)) b[n >> 5] |= bit;
}
}  // namespace n002aa048

// 002aa098 (was src/anon/batch_wcx.cpp)
namespace n002aa098 {
extern u32* D_0035f610 asm("D_0035f610");
s32 Tz__JmNewInfo__isCharaNew(s32) asm("Tz__JmNewInfo__isCharaNew");
u8* func_00294000(s32) asm("func_00294000");
s32 func_002aa098(s32 id) asm("func_002aa098");
s32 func_002aa098(s32 id)
{
    s32 r = 0;
    if (id < 0) {
        r = Tz__JmNewInfo__isCharaNew(-1);
    } else {
        u8* t = func_00294000(3);
        s32 n = *(s32*)(t + 8);
        u8* e = t + 16;
        for (s32 i = 0; i < n; i++, e += 36) {
            if (*(s8*)e == id) {
                u32 k = *(u16*)(e + 4);
                if (D_0035f610[k >> 5] & (1 << (k & 31))) { r = 1; break; }
            }
        }
    }
    return r;
}
}  // namespace n002aa098

// 002aa148 (was src/anon/batch_w90.cpp)
namespace n002aa148 {
// 002aa148 / 002aa378 / 002ab368: test unlock bits against the "available" mask.
struct Flags { u8 pad[136]; u32 a136[41]; u32 a300[4]; u32 a316[8]; };
Flags* func_002a9d68(void) asm("func_002a9d68");
s32 func_002a9f50(s32) asm("func_002a9f50");
u8* func_00294000(s32) asm("func_00294000");
extern Flags* D_0035f610 asm("D_0035f610");
s32 func_002aa148(s32 id) asm("func_002aa148");
s32 func_002aa148(s32 id)
{
    s32 r = 1;
    Flags* bits = func_002a9d68();
    if (id < 0) {
        r = func_002a9f50(-1);
    } else {
        u8* tbl = func_00294000(3);
        s32 n = *(s32*)(tbl + 8);
        u8* e = tbl + 16;
        for (s32 i = 0; i < n; i++, e += 36) {
            if ((s8)e[0] == id) {
                u16 b = *(u16*)(e + 4);
                u32 m = 1 << (b & 31);
                if (((u32*)D_0035f610)[b >> 5] & m) {
                    r = (((u32*)bits)[b >> 5] & m) != 0;
                    if (!r) break;
                }
            }
        }
    }
    return r;
}
}  // namespace n002aa148

// 002aa220 (was src/anon/batch_wcx2.cpp)
namespace n002aa220 {
// --------------------
struct E2aa220 { u8 d[8]; };
struct T2aa220 { u8 pad[8]; s32 n; u8 pad2[4]; E2aa220 e[1]; };
T2aa220* func_00294000_2aa220(s32) asm("func_00294000");
u8* func_002a9d68_2aa220() asm("func_002a9d68");
s32 func_002943e8_2aa220(E2aa220*) asm("func_002943e8");
extern u8* D_0035f610_2aa220 asm("D_0035f610");
void func_002aa220() asm("func_002aa220");
void func_002aa220()
{
    s32 i = 0;
    u8* save = func_002a9d68_2aa220();
    T2aa220* t = func_00294000_2aa220(4);
    E2aa220* e = t->e;
    for (; i < t->n; i++) {
        if (func_002943e8_2aa220(&e[i])) {
            u32 m = 1 << (i & 31);
            u32* sb = (u32*)(save + 316);
            if (!(sb[(u32)i >> 5] & m)) {
                u32* gb = (u32*)(D_0035f610_2aa220 + 316);
                u32* q = &gb[(u32)i >> 5];
                *q |= m;
            }
        }
    }
}
}  // namespace n002aa220

// 002aa2f8 (was src/anon/batch_w51.cpp)
namespace n002aa2f8 {
extern u8* D_0035f610 asm("D_0035f610");
static inline u32 flagTest(u32 n) {
    u32* f = (u32*)(D_0035f610 + 316);
    return (f[n >> 5] & (1 << (n & 31))) != 0;
}
// Test flag n, or any of flags 0..12 when n < 0.
u32 func_002aa2f8(s32 n) asm("func_002aa2f8");
// Test flag n, or any of flags 0..12 when n < 0.
u32 func_002aa2f8(s32 n) {  // test_bit_global_b
    if (n < 0) {
        u32 r;
        for (s32 i = 0; i < 13; i++) {
            r = flagTest(i);
            if (r) break;
        }
        return r;
    }
    return flagTest(n);
}
}  // namespace n002aa2f8

// 002aa378 (was src/anon/batch_w90.cpp)
namespace n002aa378 {
// 002aa148 / 002aa378 / 002ab368: test unlock bits against the "available" mask.
struct Flags { u8 pad[136]; u32 a136[41]; u32 a300[4]; u32 a316[8]; };
Flags* func_002a9d68(void) asm("func_002a9d68");
extern Flags* D_0035f610 asm("D_0035f610");
static inline u32 Bit(u32* a, u32 i) { return a[i >> 5] & (1 << (i & 31)); }
s32 func_002aa378(s32 id) asm("func_002aa378");
s32 func_002aa378(s32 id)
{
    Flags* bits = func_002a9d68();
    s32 r = 1;
    if (id < 0) {
        u32* own = bits->a316;
        u32* all = D_0035f610->a316;
        for (s32 i = 0; i < 13; i++) {
            if (Bit(all, i)) {
                r = Bit(own, i) != 0;
                if (!r) break;
            }
        }
    } else {
        s32 k = 0;
        if (Bit(D_0035f610->a316, id)) k = Bit(bits->a316, id) != 0;
        r = k;
    }
    return r;
}
}  // namespace n002aa378

// 002aa450 (was src/anon/batch_w26.cpp)
namespace n002aa450 {
u8* jm_get_sram(s32) asm("_ZN2Tz9JmNewInfo7GetSramEv");
// Sets bit i in the save-data bit array.
void func_002aa450(u32 i) asm("func_002aa450");
// Sets bit i in the save-data bit array.
void func_002aa450(u32 i) {
    u32* bits = (u32*)(jm_get_sram(i) + 316);
    u32 bit = 1 << (i & 31);
    if (!(bits[i >> 5] & bit)) bits[i >> 5] |= bit;
}
}  // namespace n002aa450

// 002aa4a8 (was src/anon/batch_wcx2.cpp)
namespace n002aa4a8 {
// --------------------
struct E2aa4a8 { s8 k; u8 pad[11]; };
struct T2aa4a8 { u8 pad[8]; s32 n; u8 pad2[4]; E2aa4a8 e[1]; };
T2aa4a8* func_00294000_2aa4a8(s32) asm("func_00294000");
s32 func_00294268_2aa4a8(E2aa4a8*) asm("func_00294348");
extern u8* D_0035f610_2aa4a8 asm("D_0035f610");
u8* func_002a9d68_2aa4a8() asm("func_002a9d68");
void func_002aa4a8() asm("func_002aa4a8");
void func_002aa4a8()
{
    s32 i = 0;
    s32 prev = -1;
    s32 j = 0;
    u8* save = func_002a9d68_2aa4a8();
    T2aa4a8* t = func_00294000_2aa4a8(2);
    E2aa4a8* e = t->e;
    for (; i < t->n; i++) {
        s32 k = e[i].k;
        if (prev != k) {
            prev = k;
            j = 0;
        }
        if (func_00294268_2aa4a8(&e[i])) {
            u32 m = 1 << (j & 31);
            u32* sb = (u32*)(save + e[i].k * 4 + 68);
            if (!(sb[(u32)j >> 5] & m)) {
                u32* gb = (u32*)(D_0035f610_2aa4a8 + e[i].k * 4 + 68);
                u32* q = &gb[(u32)j >> 5];
                *q |= m;
            }
        }
        j++;
    }
}
}  // namespace n002aa4a8

// 002aa5b8 (was src/anon/batch_wcx2.cpp)
namespace n002aa5b8 {
// --------------------
struct E2aa5b8 { s8 key; u8 pad[11]; };
struct T2aa5b8 { u8 pad[8]; s32 n; u8 pad2[4]; E2aa5b8 e[1]; };
T2aa5b8* func_00294000_2aa5b8(s32) asm("func_00294000");
s32 func_002aa5b8(s32 key, s32 nth) asm("func_002aa5b8");
s32 func_002aa5b8(s32 key, s32 nth)
{
    bool found = false;
    T2aa5b8* t = func_00294000_2aa5b8(2);
    s32 r = -1;
    s32 i = 0;
    E2aa5b8* e = t->e;
    for (; i < t->n; i++, e++) {
        if (key != e->key) {
            r = -1;
            if (found) break;
        } else {
            if (!found) {
                found = true;
                r = 0;
            }
            if (i == nth) break;
            r++;
        }
    }
    if (i >= t->n) r = -1;
    return r;
}
}  // namespace n002aa5b8

// 002aa668 (was src/anon/batch_wcx2.cpp)
namespace n002aa668 {
s32 func_002aa668(s32, s32) asm("func_002aa668");
// --------------------
struct T2aa668 { u8 pad[8]; s32 n; };
T2aa668* func_00294000_2aa668(s32) asm("func_00294000");
s32 func_002aa5b8_2aa668(s32, s32) asm("func_002aa5b8");
extern u8* D_0035f610_2aa668 asm("D_0035f610");
s32 func_002aa668(s32 key, s32 nth) asm("func_002aa668");
s32 func_002aa668(s32 key, s32 nth)
{
    s32 r = 0;
    s32 b;
    T2aa668* t = func_00294000_2aa668(2);
    if (nth < 0) {
        for (s32 i = 0; i < t->n; i++) {
            b = func_002aa5b8_2aa668(key, i);
            if (b < 0) continue;
            u32* g = (u32*)(D_0035f610_2aa668 + key * 4 + 68);
            r = (g[(u32)b >> 5] & (1 << (b & 31))) != 0;
            if (r) break;
        }
    } else {
        b = func_002aa5b8_2aa668(key, nth);
        u32* g = (u32*)(D_0035f610_2aa668 + key * 4 + 68);
        r = (g[(u32)b >> 5] & (1 << (b & 31))) != 0;
    }
    return r;
}
}  // namespace n002aa668

// 002aa788 (was src/anon/perm_002aa788.cpp)
namespace n002aa788 {
typedef unsigned int u32;
typedef signed int s32;
s32 func_002a9d68() asm("_ZN2Tz9JmNewInfo7GetSramEv");
s32 func_00294000(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
u32 func_002aa5b8(s32, s32) asm("func_002aa5b8");
extern s32 D_0035f610 asm("D_0035f610");
s32 func_002aa788(s32 a, s32 id) asm("func_002aa788");
s32 func_002aa788(s32 a, s32 id)
{
  s32 base = func_002a9d68();
  s32 r = 1;
  s32 t = func_00294000(2);
  if (id < 0)
  {
    s32 i;
    for (i = 0; i < (*((s32 *) (t + 8))); i++)
    {
      s32 bit = func_002aa5b8(a, i);
      if (bit >= 0)
      {
        s32 q = D_0035f610 + (a * 4);
        q += (((u32) bit) >> 5) * 4;
        u32 m = 1 << (bit & 0x1f);
        if ((*((u32 *) (q + 0x44))) & m)
        {
          s32 q2 = base + (a * 4);
          q2 += (((u32) bit) >> 5) * 4;
          r = ((*((u32 *) (q2 + 0x44))) & m) != 0;
          if (!r)
          {
            return r;
          }
        }
      }
    }

  }
  else
  {
    u32 bit = r = func_002aa5b8(a, id);
    u32 w = bit >> 5;
    s32 q = D_0035f610 + (a * 4);
    q += w * 4;
    u32 m = 1 << (bit & 0x1f);
    s32 k = 0;
    if ((*((u32 *) (q + 0x44))) & m)
    {
      s32 q2 = base + (a * 4);
      q2 += (bit >> 5) * 4;
      k = ((*((u32 *) (q2 + 0x44))) & m) != 0;
    }
    r = k;
  }
  return r;
}
}  // namespace n002aa788

// 002aa8e0 (was src/anon/batch_w52.cpp)
namespace n002aa8e0 {
u8* func_002a9d68(u32, u32) asm("func_002a9d68");
u32 func_002aa5b8(u32, u32) asm("func_002aa5b8");
// Sets bit `bit` in row a of the bitmap at +68.
void func_002aa8e0(s32 a, u32 b) asm("func_002aa8e0");
// Sets bit `bit` in row a of the bitmap at +68.
void func_002aa8e0(s32 a, u32 b) {
    u32* base = (u32*)func_002a9d68(a, b);
    u32 bit = func_002aa5b8(a, b);
    u32* row = &base[a + 17];
    u32 m = 1 << (bit & 31);
    if (!(row[bit >> 5] & m)) row[bit >> 5] |= m;
}
}  // namespace n002aa8e0

// 002aa960 (was src/anon/batch_wcx2.cpp)
namespace n002aa960 {
// --------------------
struct E2aa960 { u8 d[8]; };
struct T2aa960 { u8 pad[8]; s32 n; u8 pad2[4]; E2aa960 e[1]; };
T2aa960* func_00294000_2aa960(s32) asm("func_00294000");
u8* func_002a9d68_2aa960() asm("func_002a9d68");
s32 func_002944d0_2aa960(E2aa960*) asm("func_002944d0");
extern u8* D_0035f610_2aa960 asm("D_0035f610");
void func_002aa960() asm("func_002aa960");
void func_002aa960()
{
    s32 i = 0;
    u8* save = func_002a9d68_2aa960();
    T2aa960* t = func_00294000_2aa960(6);
    E2aa960* e = t->e;
    for (; i < t->n; i++) {
        if (func_002944d0_2aa960(&e[i])) {
            u32 m = 1 << (i & 31);
            u32* sb = (u32*)(save + 132);
            if (!(sb[(u32)i >> 5] & m)) {
                u32* gb = (u32*)(D_0035f610_2aa960 + 132);
                u32* q = &gb[(u32)i >> 5];
                *q |= m;
            }
        }
    }
}
}  // namespace n002aa960

// 002aaa38 (was src/anon/batch_wcx2.cpp)
namespace n002aaa38 {
// ---- 002aaa38
struct B_002aaa38 { u8 pad[132]; u32 bits[1]; };
extern B_002aaa38* D_0035f610 asm("D_0035f610");
static inline bool Bit_002aaa38(u32* b, u32 i) { b += i >> 5; return (*b & (1 << (i & 31))) != 0; }
bool f_002aaa38(s32 n) asm("func_002aaa38");
bool f_002aaa38(s32 n) asm("func_002aaa38");
bool f_002aaa38(s32 n) {
    if (n < 0) {
        u32* b = D_0035f610->bits;
        bool r;
        s32 i = 0;
        do { r = (b[(u32)i >> 5] & (1 << (i & 31))) != 0; if (r) break; } while (++i < 32);
        return r;
    }
    return Bit_002aaa38(D_0035f610->bits, n);
}
}  // namespace n002aaa38

// 002aaab8 (was src/anon/batch_w76.cpp)
namespace n002aaab8 {
static inline bool TestBit(u32* bits, u32 i) { return (bits[i >> 5] & (1 << (i & 31))) != 0; }
extern u8* D_0035f610 asm("D_0035f610");
u8* func_002a9d68(s32) asm("func_002a9d68");
bool func_002aaab8(s32 id) asm("func_002aaab8");
bool func_002aaab8(s32 id)
{
    u8* a = func_002a9d68(id);
    bool r = true;
    if (id < 0) {
        for (s32 i = 0; i < 32; i++) {
            if (TestBit((u32*)(D_0035f610 + 132), i)) {
                r = TestBit((u32*)(a + 132), i);
                if (!r) break;
            }
        }
    } else {
        r = TestBit((u32*)(D_0035f610 + 132), id) && TestBit((u32*)(a + 132), id);
    }
    return r;
}
}  // namespace n002aaab8

// 002aab90 (was src/anon/batch_w27.cpp)
namespace n002aab90 {
u8* func_002a9d68(void) asm("func_002a9d68");
void func_002aab90(u32 n) asm("func_002aab90");
void func_002aab90(u32 n) {
    u32* arr = (u32*)(func_002a9d68() + 132);
    u32 i = n >> 5;
    n &= 31;
    u32 v = arr[i];
    if (!(v & (1 << n))) arr[i] = v | (1 << n);
}
}  // namespace n002aab90

// 002aabe8 (was src/anon/batch_wcx2.cpp)
namespace n002aabe8 {
// --------------------
struct E2aabe8 { u8 d[16]; };
struct T2aabe8 { u8 pad[8]; s32 n; u8 pad2[4]; E2aabe8 e[1]; };
T2aabe8* func_00294000_2aabe8(s32) asm("func_00294000");
u8* func_002a9d68_2aabe8() asm("func_002a9d68");
s32 func_002a99c8_2aabe8(E2aabe8*) asm("Tz__JmQuest__GetQuestStat");
extern u8* D_0035f610_2aabe8 asm("D_0035f610");
void func_002aabe8() asm("func_002aabe8");
void func_002aabe8()
{
    s32 i = 0;
    u8* save = func_002a9d68_2aabe8();
    T2aabe8* t = func_00294000_2aabe8(8);
    E2aabe8* e = t->e;
    for (; i < t->n; i++) {
        s32 r = func_002a99c8_2aabe8(&e[i]);
        if (r != 0 && r != 3) {
            u32 m = 1 << (i & 31);
            u32* sb = (u32*)(save + 148);
            if (!(sb[(u32)i >> 5] & m)) {
                u32* gb = (u32*)(D_0035f610_2aabe8 + 148);
                u32* q = &gb[(u32)i >> 5];
                *q |= m;
            }
        }
    }
}
}  // namespace n002aabe8

// 002aacd8 (was src/anon/batch_w54.cpp)
namespace n002aacd8 {
struct Bits2aa {
    u8 pad[148];
    u32 bits[6];
};
extern Bits2aa* D_0035f610 asm("D_0035f610");
static inline s32 bit_test(u32* b, u32 i) {
    return (b[i >> 5] & (1 << (i & 31))) != 0;
}
// test flag n; n < 0 tests whether any of the 192 flags is set
s32 func_002aacd8(s32 n) asm("func_002aacd8");
// test flag n; n < 0 tests whether any of the 192 flags is set
s32 func_002aacd8(s32 n) {  // test_bit_global_d
    if (n < 0) {
        s32 r;
        s32 i;
        u32* b = D_0035f610->bits;
        for (i = 0; i < 192; i++) {
            r = bit_test(b, i);
            if (r) break;
        }
        return r;
    }
    return bit_test(D_0035f610->bits, n);
}
}  // namespace n002aacd8

// 002aad58 (was src/anon/batch_w77.cpp)
namespace n002aad58 {
struct Flags { u8 pad[148]; u32 bits[8]; };
extern Flags* D_0035f610 asm("D_0035f610");
Flags* func_002a9d68(void) asm("func_002a9d68");
static inline s32 TestBit(u32* bits, u32 i)
{
    return bits[i >> 5] & (1 << (i & 31));
}
s32 func_002aad58(s32 n) asm("func_002aad58");
s32 func_002aad58(s32 n)
{
    Flags* a = func_002a9d68();
    s32 r = 1;
    if (n < 0) {
        for (s32 i = 0; i < 192; i++) {
            if (TestBit(D_0035f610->bits, i)) {
                r = TestBit(a->bits, i) != 0;
                if (!r) break;
            }
        }
    } else {
        r = TestBit(D_0035f610->bits, n) && TestBit(a->bits, n);
    }
    return r;
}
}  // namespace n002aad58

// 002aae30 (was src/anon/batch_w28.cpp)
namespace n002aae30 {
u8* func_002a9d68(void) asm("func_002a9d68");
// Set bit n in a bitset at +0x94 (stores only when it changes).
void func_002aae30(u32 n) asm("func_002aae30");
// Set bit n in a bitset at +0x94 (stores only when it changes).
void func_002aae30(u32 n) {
    u32* arr = (u32*)(func_002a9d68() + 148);
    u32* w = (u32*)((n >> 5) * 4 + (u32)arr);
    u32 v = *w;
    u32 bit = 1 << (n & 31);
    if (!(v & bit)) *w = v | bit;
}
}  // namespace n002aae30

// 002aae88 (was src/anon/batch_wcx2.cpp)
namespace n002aae88 {
// test_bit_global_a
s32 func_002aae88(s32) asm("func_002aae88");
// --------------------
struct E2aae88 { u16 id; u8 pad[14]; };
struct T2aae88 { u8 pad[8]; s32 n; u8 pad2[4]; E2aae88 e[1]; };
T2aae88* func_00294000_2aae88(s32) asm("func_00294000");
s32 func_002aacd8(s32) asm("func_002aacd8");
extern u8* D_0035f610_2aae88 asm("D_0035f610");
s32 func_002aae88(s32 id) asm("func_002aae88");
s32 func_002aae88(s32 id)
{
    s32 r = 0;
    T2aae88* t = func_00294000_2aae88(8);
    E2aae88* e = t->e;
    if (id < 0) {
        r = func_002aacd8(-1);
    } else {
        for (s32 i = 0; i < t->n; i++) {
            if (e[i].id != id) continue;
            u32* bits = (u32*)(D_0035f610_2aae88 + 148);
            if (bits[(u32)i >> 5] & (1 << (i & 31))) {
                r = 1;
                break;
            }
        }
    }
    return r;
}
}  // namespace n002aae88

// 002aaf40 (was src/anon/batch_w89.cpp)
namespace n002aaf40 {
struct Tbl { u8 pad[8]; s32 count; u32 pad2; };
struct Bits148 { u8 pad[148]; u32 bits[1]; };
struct Ent16 { u16 id; u8 pad[14]; };
static inline bool BitTest(u32* b, u32 i) { return b[i >> 5] & (1 << (i & 31)); }
extern Bits148* D_0035f610 asm("D_0035f610");
Bits148* func_002a9d68(void) asm("func_002a9d68");
Tbl* func_00294000(s32) asm("func_00294000");
s32 func_002aad58(s32) asm("func_002aad58");
s32 func_002aaf40(s32 id) asm("func_002aaf40");
s32 func_002aaf40(s32 id) {
    s32 r = 1;
    Bits148* g = func_002a9d68();
    Tbl* t = func_00294000(8);
    Ent16* e = (Ent16*)(t + 1);
    if (id < 0) r = func_002aad58(-1);
    else {
        s32 n = t->count;
        for (u32 i = 0; (s32)i < n; i++, e++) {
            if (e->id != id) continue;
            if (BitTest(D_0035f610->bits, i)) {
                r = BitTest(g->bits, i);
                if (!r) break;
            }
        }
    }
    return r;
}
}  // namespace n002aaf40

// 002ab020 (was src/anon/batch_w246.cpp)
namespace n002ab020 {
struct W246Bits { u32 w[8];
  inline bool test(u32 i) { return (w[i >> 5] & (1 << (i & 31))) != 0; }
  inline void set(u32 i) { u32* p = w; p += i >> 5; *p |= 1 << (i & 31); } };
struct W246Sram { u8 pad[136]; W246Bits bits; };
struct W246Score { u8 v; inline bool ok() { return v >= 2; } };
W246Sram* GetSram(void) asm("_ZN2Tz9JmNewInfo7GetSramEv");
u8* JmInfo_GetData(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
W246Score* GetScore(s32) asm("_ZN2YS8MINIGAME8GetScoreEi");
extern W246Sram* D_0035f610 asm("D_0035f610");
void func_002ab020(void) asm("func_002ab020");
void func_002ab020(void) {
    W246Sram* sram = GetSram();
    u8* data = JmInfo_GetData(7);
    for (s32 i = 0; i < *(s32*)(data + 8); i++) {
        W246Score* sc = GetScore(*(u16*)(data + 22 + i * 8));
        if (sc->ok() && !sram->bits.test(i)) D_0035f610->bits.set(i);
    }
}
}  // namespace n002ab020

// 002ab100 (was src/anon/batch_w55.cpp)
namespace n002ab100 {
extern u8* D_0035f610 asm("D_0035f610");
// Tests flag n, or whether any of the 96 flags is set when n is negative.
s32 func_002ab100(s32 n) asm("func_002ab100");
// Tests flag n, or whether any of the 96 flags is set when n is negative.
s32 func_002ab100(s32 n) {  // test_bit_global_c
    if (n < 0) {
        u32* bits = (u32*)(D_0035f610 + 136);
        s32 r;
        s32 i = 0;
        do {
            r = (bits[(u32)i >> 5] & (1 << (i & 31))) != 0;
            i++;
            if (r) break;
        } while (i < 96);
        return r;
    }
    u8* b = D_0035f610;
    u32 o = ((u32)n >> 5) * 4;
    b += o;
    return (*(u32*)(b + 136) & (1 << (n & 31))) != 0;
}
}  // namespace n002ab100

// 002ab180 (was src/anon/batch_wcx2.cpp)
namespace n002ab180 {
// --------------------
u8* func_002a9d68_2ab180() asm("func_002a9d68");
extern u8* D_0035f610_2ab180 asm("D_0035f610");
s32 func_002ab180(s32 id) asm("func_002ab180");
s32 func_002ab180(s32 id)
{
    u8* save = func_002a9d68_2ab180();
    s32 r = 1;
    if (id < 0) {
        u32* g = (u32*)(D_0035f610_2ab180 + 136);
        u32* sv = (u32*)(save + 136);
        for (s32 i = 0; i < 96; i++) {
            u32 m = 1 << (i & 31);
            if (g[(u32)i >> 5] & m) {
                r = (sv[(u32)i >> 5] & m) != 0;
                if (!r) break;
            }
        }
    } else {
        u32 m = 1 << (id & 31);
        u32 w = ((u32)id >> 5) * 4;
        s32 x = 0;
        if (*(u32*)(D_0035f610_2ab180 + w + 136) & m)
            x = (*(u32*)(save + w + 136) & m) != 0;
        r = x;
    }
    return r;
}
}  // namespace n002ab180

// 002ab258 (was src/anon/batch_w29.cpp)
namespace n002ab258 {
u8* func_002a9d68(void) asm("func_002a9d68");
// Sets bit n in the bitset at +136 (only if not already set).
void func_002ab258(u32 n) asm("func_002ab258");
// Sets bit n in the bitset at +136 (only if not already set).
void func_002ab258(u32 n) {
    u8* b = func_002a9d68();
    u32* w = (u32*)((n >> 5) * 4 + (u32)(b + 136));
    u32 bit = 1 << (n & 31);
    if (!(*w & bit)) *w |= bit;
}
}  // namespace n002ab258

// 002ab2b0 (was src/anon/batch_w239.cpp)
namespace n002ab2b0 {
void* func_00294000(s32) asm("func_00294000");
s32 func_002ab100(s32) asm("func_002ab100");
// test_bit_global_c
extern u8* D_0035f610 asm("D_0035f610");
s32 func_002ab2b0(s32 id) asm("func_002ab2b0");
s32 func_002ab2b0(s32 id) {
    s32 r = 0;
    s32* p = (s32*)func_00294000(7);
    u16* base = (u16*)((u8*)p + 16);
    if (id < 0) {
        r = func_002ab100(-1);  // test_bit_global_c
    } else {
        s32 n = p[2];
        s32 i = 0;
        if (n > 0) {
            u16* e = base;
            do {
                u16 v = *e;
                e += 4;
                if (v == id) {
                    u32* bits = (u32*)(D_0035f610 + 136);
                    if (bits[(u32)i >> 5] & (1 << (i & 31))) { r = 1; break; }
                }
                i++;
            } while (i < n);
        }
    }
    return r;
}
}  // namespace n002ab2b0

// 002ab368 (was src/anon/batch_w90.cpp)
namespace n002ab368 {
// 002aa148 / 002aa378 / 002ab368: test unlock bits against the "available" mask.
struct Flags { u8 pad[136]; u32 a136[41]; u32 a300[4]; u32 a316[8]; };
Flags* func_002a9d68(void) asm("func_002a9d68");
u8* func_00294000(s32) asm("func_00294000");
s32 func_002ab180(s32) asm("func_002ab180");
extern Flags* D_0035f610 asm("D_0035f610");
static inline u32 Bit(u32* a, u32 i) { return a[i >> 5] & (1 << (i & 31)); }
s32 func_002ab368(s32 id) asm("func_002ab368");
s32 func_002ab368(s32 id)
{
    s32 r = 1;
    Flags* bits = func_002a9d68();
    u8* tbl = func_00294000(7);
    u16* e = (u16*)(tbl + 16);
    if (id < 0) {
        r = func_002ab180(-1);
    } else {
        s32 n = *(s32*)(tbl + 8);
        for (s32 i = 0; i < n; i++, e += 4) {
            if (*e == id && Bit(D_0035f610->a136, i)) {
                r = Bit(bits->a136, i) != 0;
                if (!r) break;
            }
        }
    }
    return r;
}
}  // namespace n002ab368

// 002ab448 (was src/anon/batch_w83.cpp)
namespace n002ab448 {
s32 func_00181500(s32) asm("func_00181500");
struct Flags236 { u8 pad[236]; u32 bits[42]; };
extern Flags236* D_0035f610 asm("D_0035f610");
Flags236* func_002a9d68(void) asm("func_002a9d68");
u8* func_001a82b0(u8*) asm("func_001a82b0");
void* Tz__Jiminy__AreaWorld2JmWorld(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
s32 func_002954e0(void*) asm("func_002954e0");
void Tz__JmNewInfo__CheckTreasure(void) asm("Tz__JmNewInfo__CheckTreasure");
void Tz__JmNewInfo__CheckTreasure(void) {
    u32* bits = func_002a9d68()->bits;
    u8* it = 0;
    for (u32 i = 0;; i++) {
        it = func_001a82b0(it);
        if (!it) return;
        if (it[4]) continue;
        u16 id = *(u16*)(it + 8);
        if (!id) continue;
        if (id == 2048) continue;
        if (!func_00181500(id)) continue;
        s32 v = func_002954e0(Tz__Jiminy__AreaWorld2JmWorld(it[5]));
        u32 w = i >> 5;
        u32 bit = 1 << (i & 31);
        if (v) {
            if (!(bits[w] & bit)) {
                u8* a = (u8*)D_0035f610->bits;
                a += w * 4;
                *(u32*)a |= bit;
            }
        }
    }
}
}  // namespace n002ab448

// 002ab540 (was src/anon/batch_w91.cpp)
namespace n002ab540 {
// --- 002ab540
static inline bool tbit91(u32* a, u32 i) { return (a[i >> 5] & (1 << (i & 31))) != 0; }
extern u8* D_0035f610 asm("D_0035f610");
u8* func_001a82b0(u8*) asm("func_001a82b0");
s32 Tz__Jiminy__AreaWorld2JmWorld(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
u32 Tz__JmNewInfo__isTreasureNew(s32 who) asm("Tz__JmNewInfo__isTreasureNew");
u32 Tz__JmNewInfo__isTreasureNew(s32 who) {
    u8* p = 0;
    u32 r = 0;
    for (u32 i = 0;; i++) {
        p = func_001a82b0(p);
        if (!p) break;
        if (p[4]) continue;
        u16 t = *(u16*)(p + 8);
        if (t == 0 || t == 2048) continue;
        s32 v = Tz__Jiminy__AreaWorld2JmWorld(p[5]);
        if (who >= 0 && v != who) continue;
        if (tbit91((u32*)(D_0035f610 + 236), i)) { r = 1; break; }
    }
    return r;
}
}  // namespace n002ab540

// 002ab620 (was src/anon/batch_w3881.cpp)
namespace n002ab620 {
u8* func_002a9d68() asm("func_002a9d68");
extern u8* D_0035f610 asm("D_0035f610");
u8* func_001a82b0(u8*) asm("func_001a82b0");
s32 Tz__Jiminy__AreaWorld2JmWorld(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
// Walks every entry and checks that each one selected (not hidden, kind not 0 or 0x800, matching key
// when key >= 0) whose bit is set in the global flag set is also set in the save data's flag set.
s32 func_002ab620(s32 key) asm("func_002ab620");
// Walks every entry and checks that each one selected (not hidden, kind not 0 or 0x800, matching key
// when key >= 0) whose bit is set in the global flag set is also set in the save data's flag set.
s32 func_002ab620(s32 key)
{
    u8* e = 0;
    s32 i = 0;
    s32 r = 1;
    u8* save = func_002a9d68();
    u32* sb = (u32*)(save + 236);
    for (;;) {
        e = func_001a82b0(e);
        if (e == 0) break;
        if (e[4] == 0 && *(u16*)(e + 8) != 0 && *(u16*)(e + 8) != 0x800
            && (key < 0 || Tz__Jiminy__AreaWorld2JmWorld(e[5]) == key)) {
            u32* gb = (u32*)(D_0035f610 + 236);
            u32 m = 1 << (i & 31);
            if (gb[(u32)i >> 5] & m) {
                r = (sb[(u32)i >> 5] & m) != 0;
                if (!r) break;
            }
        }
        i++;
    }
    return r;
}
}  // namespace n002ab620

// 002ab728 (was src/anon/batch_w78.cpp)
namespace n002ab728 {
void func_002ab728(s32) asm("func_002ab728");
u8* func_002a9d68(s32) asm("func_002a9d68");
extern u8* D_0035f610 asm("D_0035f610");
u8* func_001a82b0(u8*) asm("func_001a82b0");
s32 Tz__Jiminy__AreaWorld2JmWorld(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
void func_002ab728(s32 id) asm("func_002ab728");
void func_002ab728(s32 id) {
    u32* bits = (u32*)(func_002a9d68(id) + 236);
    u8* e = 0;
    u32 i = 0;
    for (;; i++) {
        e = func_001a82b0(e);
        if (!e) break;
        if (e[4]) continue;
        if (*(u16*)(e + 8) == 0) continue;
        if (*(u16*)(e + 8) == 0x800) continue;
        if (Tz__Jiminy__AreaWorld2JmWorld(e[5]) != id) continue;
        u32 m = 1 << (i & 31);
        u32 w4 = (i >> 5) * 4;
        if (*(u32*)(D_0035f610 + w4 + 236) & m) {
            u32 w = bits[i >> 5];
            if (!(w & m)) bits[i >> 5] = w | m;
        }
    }
}
}  // namespace n002ab728

// 002ab818 (was src/anon/batch_w1799.cpp)
namespace n002ab818 {
// ---- func_002ab818 ----
struct W1799E { u8 a, b; u16 id; };
struct W1799T { u8 a, b, type; };
W1799T* func_001a80c8(u16) asm("func_001a80c8");
W1799E* func_001a82b0(W1799E*) asm("func_001a82b0");
s32 func_002a43b0(W1799E*) asm("func_002a43b0");
s32 func_002a9d68() asm("func_002a9d68");
extern s32 D_0035f610 asm("D_0035f610");
void func_002ab818(void) asm("func_002ab818");
void func_002ab818(void) {
    W1799E* p = 0;
    u32 i = 0;
    s32 bits = func_002a9d68() + 300;
    for (;;) {
        do {
            p = func_001a82b0(p);
            if (p == 0) return;
        } while (func_001a80c8(p->id)->type != 22);
        {
            s32 r = func_002a43b0(p);
            u32 w = (i >> 5) * 4;
            u32 m = 1 << (i & 31);
            i++;
            if (__builtin_expect(r == 0, 0)) continue;
            if (*(u32*)(w + bits) & m) continue;
            s32 d = D_0035f610 + 300; *(u32*)(d + w) |= m;
        }
    }
}
}  // namespace n002ab818

// 002ab8e8 (was src/anon/batch_w76.cpp)
namespace n002ab8e8 {
static inline bool TestBit(u32* bits, u32 i) { return (bits[i >> 5] & (1 << (i & 31))) != 0; }
extern u8* D_0035f610 asm("D_0035f610");
u8* func_001a82b0(u8*) asm("func_001a82b0");
s32 Tz__Jiminy__AreaWorld2JmWorld(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
u8* func_001a80c8(u16) asm("func_001a80c8");
// table24_find_by_id
bool Tz__JmNewInfo__isNaviNew(s32 who) asm("Tz__JmNewInfo__isNaviNew");
// table24_find_by_id
bool Tz__JmNewInfo__isNaviNew(s32 who)
{
    u8* e = 0;
    u32 idx = 0;
    bool r = false;
    for (;;) {
        e = func_001a82b0(e);
        if (!e) break;
        if (func_001a80c8(*(u16*)(e + 2))[2] != 22) continue;
        if (who >= 0 && Tz__Jiminy__AreaWorld2JmWorld(e[5]) != who) { idx++; continue; }
        if (TestBit((u32*)(D_0035f610 + 300), idx)) { r = true; break; }
        idx++;
    }
    return r;
}
}  // namespace n002ab8e8

// 002ab9c8 (was src/anon/batch_wcx2.cpp)
namespace n002ab9c8 {
s32 func_002ab9c8(s32) asm("func_002ab9c8");
// --------------------
u8* func_002a9d68_2ab9c8() asm("func_002a9d68");
extern u8* D_0035f610_2ab9c8 asm("D_0035f610");
u8* func_001a82b0_2ab9c8(u8*) asm("func_001a82b0");
u8* func_001a80c8_2ab9c8(u16) asm("func_001a80c8");
s32 func_002764b0_2ab9c8(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
s32 func_002ab9c8(s32 key) asm("func_002ab9c8");
s32 func_002ab9c8(s32 key)
{
    u8* e = 0;
    s32 i = 0;
    s32 r = 1;
    u8* save = func_002a9d68_2ab9c8();
    u32* sb = (u32*)(save + 300);
    for (;;) {
        e = func_001a82b0_2ab9c8(e);
        if (e == 0) break;
        if (func_001a80c8_2ab9c8(*(u16*)(e + 2))[2] != 22) continue;
        if (key >= 0 && func_002764b0_2ab9c8(e[5]) != key) { i++; continue; }
        u32* gb = (u32*)(D_0035f610_2ab9c8 + 300);
        u32 m = 1 << (i & 31);
        if (!(gb[(u32)i >> 5] & m)) { i++; continue; }
        r = (sb[(u32)i >> 5] & m) != 0;
        i++;
        if (!r) break;
    }
    return r;
}
}  // namespace n002ab9c8

// 002abac8 (was src/anon/batch_wcx2.cpp)
namespace n002abac8 {
// --------------------
u8* func_002a9d68_2abac8() asm("func_002a9d68");
extern u8* D_0035f610_2abac8 asm("D_0035f610");
u8* func_001a82b0_2abac8(u8*) asm("func_001a82b0");
u8* func_001a80c8_2abac8(u16) asm("func_001a80c8");
s32 func_002764b0_2abac8(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
void func_002abac8(s32 key) asm("func_002abac8");
void func_002abac8(s32 key)
{
    u8* e = 0;
    s32 i = 0;
    u8* save = func_002a9d68_2abac8();
    u32* sb = (u32*)(save + 300);
    for (;;) {
        e = func_001a82b0_2abac8(e);
        if (e == 0) break;
        if (func_001a80c8_2abac8(*(u16*)(e + 2))[2] != 22) continue;
        if (func_002764b0_2abac8(e[5]) != key) { i++; continue; }
        {
            u32* gb = (u32*)(D_0035f610_2abac8 + 300);
            u32 m = 1 << (i & 31);
            if (gb[(u32)i >> 5] & m) {
                if (!(sb[(u32)i >> 5] & m)) sb[(u32)i >> 5] |= m;
            }
        }
        i++;
    }
}
}  // namespace n002abac8

// 002abba8 (was src/anon/batch_w1790_gnsa.cpp)
namespace n002abba8 {
// ---- 002abba8 ----
struct W1790Sram { u8 pad[0x140]; u32 bits[4]; };
static inline int w1790_bitTest(u32* p, u32 i) { return p[i >> 5] & (1 << (i & 0x1f)); }
static inline void w1790_bitSet(u32* p, u32 i) { *(u32*)((u8*)p + ((i >> 5) << 2)) |= (1 << (i & 0x1f)); }
W1790Sram* jm_GetSram(void) asm("_ZN2Tz9JmNewInfo7GetSramEv");
s32 Tz__JmSynthe__isEnableRecipe(void) asm("Tz__JmSynthe__isEnableRecipe");
s32 Tz__JmSynthe__isEnableMaterial(void) asm("Tz__JmSynthe__isEnableMaterial");
extern W1790Sram* D_0035f610 asm("D_0035f610");
void func_002abba8(void) asm("func_002abba8");
void func_002abba8(void) {
    W1790Sram* p = jm_GetSram();
    s32 a = Tz__JmSynthe__isEnableRecipe();
    u32* bits = p->bits;
    s32 b = Tz__JmSynthe__isEnableMaterial();
    u32 i;
    for (i = 0; (s32)i < 4; i++) {
        s32 f;
        if (i == 0 || i == 3) f = a; else f = b;
        if (f) {
            if (!w1790_bitTest(bits, i)) w1790_bitSet(D_0035f610->bits, i);
        }
    }
}
}  // namespace n002abba8

// 002abc60 (was src/anon/perm_002abc60.cpp)
namespace n002abc60 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef struct Flg
{
  u8 pad[0x140];
  u32 bits[1];
} Flg;
extern Flg *D_0035f610 asm("D_0035f610");
inline static s32 chk2(u32 *b, u32 n)
{
  return (b[n >> 5] & (1 << (n & 31))) != 0;
}
s32 func_002abc60(s32 n) asm("func_002abc60");
s32 func_002abc60(s32 n)
{
  s32 new_var;
  if (n < 0)
  {
    s32 r;
    s32 i;
    u32 *b = D_0035f610->bits;
    for (i = 0; i < 4; i++)
    {
      r = chk2(b, i);
      if (r)
      {
        break;
      }
    }

    new_var = r;
    return new_var;
  }
  new_var = n;
  return chk2(D_0035f610->bits, new_var);
}
}  // namespace n002abc60

// 002abce8 (was src/anon/batch_w3752.cpp)
namespace n002abce8 {
static inline bool TB(u32* b, u32 i) { return (b[i >> 5] & (1 << (i & 31))) != 0; }
s32 func_002a9d68() asm("func_002a9d68");
extern s32 D_0035f610 asm("D_0035f610");
s32 func_002abce8(s32 x) asm("func_002abce8");
s32 func_002abce8(s32 x)
{
    s32 base = func_002a9d68();
    s32 r = 1;
    s32 k;
    if (x < 0) {
        for (s32 i = 0; i < 4; i++) {
            k = i;
            if (TB((u32*)(D_0035f610 + 320), k)) {
                r = TB((u32*)(base + 320), k);
                if (!r) break;
            }
        }
    } else {
        k = x;
        s32 t = 0;
        if (TB((u32*)(D_0035f610 + 320), k)) t = TB((u32*)(base + 320), k);
        r = t;
    }
    return r;
}
}  // namespace n002abce8

// 002abdc8 (was src/anon/batch_w36.cpp)
namespace n002abdc8 {
u32* func_002a9d68(void) asm("func_002a9d68");
void func_002abdc8(void) asm("func_002abdc8");
void func_002abdc8(void) {
    u32* bits = (u32*)((u8*)func_002a9d68() + 320);
    s32 i;
    for (i = 0; i < 4; i++) {
        u32* w = (u32*)(((u32)i >> 5) * 4 + (u32)bits);
        u32 m = 1 << (i & 31);
        if (!(*w & m)) *w |= m;
    }
}
}  // namespace n002abdc8

// 002abe28 (was src/anon/batch_wcx2.cpp)
namespace n002abe28 {
// --------------------
struct E2abe28 { s8 k; u8 pad[11]; };
struct T2abe28 { u8 pad[8]; s32 n; u8 pad2[4]; E2abe28 e[1]; };
T2abe28* func_00294000_2abe28(s32) asm("func_00294000");
s32 func_00294268_2abe28(E2abe28*) asm("func_00294268");
extern u8* D_0035f610_2abe28 asm("D_0035f610");
u8* func_002a9d68_2abe28() asm("func_002a9d68");
void func_002abe28() asm("func_002abe28");
void func_002abe28()
{
    s32 i = 0;
    s32 prev = -1;
    s32 j = 0;
    u8* save = func_002a9d68_2abe28();
    T2abe28* t = func_00294000_2abe28(1);
    E2abe28* e = t->e;
    for (; i < t->n; i++) {
        s32 k = e[i].k;
        if (prev != k) {
            prev = k;
            j = 0;
        }
        if (k < 15) {
            if (func_00294268_2abe28(&e[i])) {
                u32 m = 1 << (j & 31);
                u32* sb = (u32*)(save + e[i].k * 4 + 172);
                if (!(sb[(u32)j >> 5] & m)) {
                    u32* gb = (u32*)(D_0035f610_2abe28 + e[i].k * 4 + 172);
                    u32* q = &gb[(u32)j >> 5];
                    *q |= m;
                }
            }
            j++;
        }
    }
}
}  // namespace n002abe28

// 002abf40 (was src/anon/batch_wcx2.cpp)
namespace n002abf40 {
// --------------------
struct E2abf40 { s8 key; u8 pad[11]; };
struct T2abf40 { u8 pad[8]; s32 n; u8 pad2[4]; E2abf40 e[1]; };
T2abf40* func_00294000_2abf40(s32) asm("func_00294000");
s32 func_002abf40(s32 key, s32 nth) asm("func_002abf40");
s32 func_002abf40(s32 key, s32 nth)
{
    bool found = false;
    T2abf40* t = func_00294000_2abf40(1);
    s32 r = -1;
    s32 i = 0;
    E2abf40* e = t->e;
    for (; i < t->n; i++, e++) {
        if (key != e->key) {
            r = -1;
            if (found) break;
        } else {
            if (!found) {
                found = true;
                r = 0;
            }
            if (i == nth) break;
            r++;
        }
    }
    if (i >= t->n) r = -1;
    return r;
}
}  // namespace n002abf40

// 002abff0 (was src/anon/batch_w257.cpp)
namespace n002abff0 {
extern u8* D_0035f610 asm("D_0035f610");
u8* func_00294000(s32) asm("func_00294000");
s32 func_002abf40(s32, s32) asm("func_002abf40");
static inline s32 tst_002abff0(s32 a0, s32 b) {
    u32* p = (u32*)(D_0035f610 + a0 * 4) + 43; return (p[(u32)b >> 5] & (1 << (b & 31))) != 0;
}
s32 Tz__JmNewInfo__isStoryNew(s32 a0, s32 a1) asm("Tz__JmNewInfo__isStoryNew");
s32 Tz__JmNewInfo__isStoryNew(s32 a0, s32 a1) {
    s32 res = 0;
    u8* v = func_00294000(1);
    if (a1 < 0) {
        for (s32 i = 0; i < *(s32*)(v + 8); i++) {
            s32 b = func_002abf40(a0, i);
            if (b >= 0) {
                res = tst_002abff0(a0, b);
                if (res) break;
            }
        }
    } else {
        res = tst_002abff0(a0, a1 = func_002abf40(a0, a1));
    }
    return res;
}
}  // namespace n002abff0

// 002ac110 (was src/anon/batch_w8028.cpp)
namespace n002ac110 {
s32 Jm_GetSram_w8028(void) asm("_ZN2Tz9JmNewInfo7GetSramEv");
s32 Jm_GetData_w8028(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
u32 func_002abf40(s32, s32) asm("func_002abf40");
extern s32 D_0035f610 asm("D_0035f610");
s32 func_002ac110(s32 a, s32 id) asm("func_002ac110");
s32 func_002ac110(s32 a, s32 id) {
    s32 base = Jm_GetSram_w8028();
    s32 r = 1;
    s32 t = Jm_GetData_w8028(1);
    if (id < 0) {
        s32 i;
        for (i = 0; i < *(s32*)(t + 8); i++) {
            s32 bit = func_002abf40(a, i);
            if (bit >= 0) {
                s32 q = D_0035f610 + a * 4;
                q += ((u32)bit >> 5) * 4;
                u32 m = 1 << (bit & 0x1f);
                if (*(u32*)(q + 0xac) & m) {
                    s32 q2 = base + a * 4;
                    q2 += ((u32)bit >> 5) * 4;
                    r = (*(u32*)(q2 + 0xac) & m) != 0;
                    if (!r) return r;
                }
            }
        }
    } else {
        id = func_002abf40(a, id);
        u32 m = 1 << (id & 0x1f);
        s32 q = D_0035f610 + a * 4;
        q += ((u32)id >> 5) * 4;
        s32 k = 0;
        if (*(u32*)(q + 0xac) & m) {
            s32 q2 = base + a * 4;
            q2 += ((u32)id >> 5) * 4;
            k = (*(u32*)(q2 + 0xac) & m) != 0;
        }
        r = k;
    }
    return r;
}
}  // namespace n002ac110

// 002ac268 (was src/anon/batch_w56.cpp)
namespace n002ac268 {
// 002ac268: set bit k in a per-index bit array (only if not already set)
u8* func_002a9d68(s32, u32) asm("func_002a9d68");
u32 func_002abf40(s32, u32) asm("func_002abf40");
void func_002ac268(s32 a, u32 b) asm("func_002ac268");
void func_002ac268(s32 a, u32 b)
{
    u8* p = func_002a9d68(a, b);
    u32 k = func_002abf40(a, b);
    u32* w = (u32*)(p + a * 4 + 172);
    u32 m = 1 << (k & 31);
    u32 v = w[k >> 5];
    if (!(v & m)) w[k >> 5] = v | m;
}
}  // namespace n002ac268

// 002ac2e8 (was src/anon/batch_w1599.cpp)
namespace n002ac2e8 {
struct Ent { u8 a; u8 b; u8 pad[6]; u16 id; };
struct Bits {
    u32 w[2];
    s32 Test(u32 b) { return w[b >> 5] & (1 << (b & 31)); }
    void Set(u32 b) { u32* p = &w[b >> 5]; *p |= 1 << (b & 31); }
};
struct Flags { u8 pad[0x144]; Bits x[10]; Bits y[10]; };
extern Flags* D_0035f610 asm("D_0035f610");
Flags* func_002a9d68(void) asm("func_002a9d68");
Ent* func_001d9e30(Ent*) asm("func_001d9e30");
s32 func_001d9d48(Ent*) asm("func_001d9d48");
s32 func_00181500(u16) asm("func_00181500");
void func_002ac2e8(void) asm("func_002ac2e8");
void func_002ac2e8(void) {
    Ent* e = 0;
    Flags* f = func_002a9d68();
    while ((e = func_001d9e30(e)) != 0) {
        if (func_001d9d48(e)) {
            if (!f->x[e->a].Test(e->b)) D_0035f610->x[e->a].Set(e->b);
        }
        if (func_00181500(e->id)) {
            if (!f->y[e->a].Test(e->b)) D_0035f610->y[e->a].Set(e->b);
        }
    }
}
}  // namespace n002ac2e8

// 002ac420 (was src/anon/batch_w99.cpp)
namespace n002ac420 {
struct Ent2ac4 { s8 id; u8 kind; u8 pad[14]; };
struct Tbl2ac4 { u32 pad[2]; s32 count; u32 pad2; Ent2ac4 e[1]; };
Tbl2ac4* func_00294000_2ac420(s32) asm("func_00294000");
s32 func_002b3ac8(s8) asm("func_002b3ac8");
extern u8* D_0035f610 asm("D_0035f610");
// Returns 1 if any flag bit is set for the matching entries of table 9.
s32 Tz__JmNewInfo__isPuzzlePieceNew(s32 id) asm("Tz__JmNewInfo__isPuzzlePieceNew");
// Returns 1 if any flag bit is set for the matching entries of table 9.
s32 Tz__JmNewInfo__isPuzzlePieceNew(s32 id)
{
    Tbl2ac4* t = func_00294000_2ac420(9);
    s32 found = 0;
    s32 i, j, n;
    Ent2ac4* e = t->e;
    for (i = 0; i < t->count; i++, e++) {
        if (id >= 0 && e->id != id) continue;
        n = func_002b3ac8((s8)(e->kind & 0xf));
        for (j = 0; j < n; j++) {
            u32* bits = (u32*)(D_0035f610 + e->id * 8 + 324);
            if (bits[(u32)j >> 5] & (1 << (j & 31))) { found = 1; break; }
        }
        if (id >= 0 && e->id == id) break;
    }
    return found;
}
}  // namespace n002ac420

// 002ac538 (was src/anon/batch_w92.cpp)
namespace n002ac538 {
struct E2ac { s8 id; u8 lo : 4; u8 hi : 4; u8 pad[14]; };
struct L2ac { u32 f0, f4; s32 count; u32 f12; E2ac e[1]; };
u8* func_002a9d68(void) asm("func_002a9d68");
L2ac* func_00294000(s32) asm("func_00294000");
s32 func_002b3ac8(s8) asm("func_002b3ac8");
extern u8* D_0035f610 asm("D_0035f610");
s32 func_002ac538(s32 kind) asm("func_002ac538");
s32 func_002ac538(s32 kind) {
    s32 res = 1;
    u8* m = func_002a9d68();
    L2ac* l = func_00294000(9);
    E2ac* e = l->e;
    for (s32 i = 0; i < l->count; i++, e++) {
        if (kind >= 0 && e->id != kind) continue;
        s32 n = func_002b3ac8(e->lo);
        for (s32 j = 0; j < n; j++) {
            u32* a = (u32*)(D_0035f610 + e->id * 8 + 324);
            u32* b = (u32*)(m + e->id * 8 + 324);
            u32 bit = 1 << (j & 31);
            if (a[(u32)j >> 5] & bit) {
                res = (b[(u32)j >> 5] & bit) != 0;
                if (!res) break;
            }
        }
        if (kind >= 0 && e->id == kind) return res;
    }
    return res;
}
}  // namespace n002ac538

// 002ac678 (was src/anon/batch_w2441_nsa.cpp)
namespace n002ac678 {
u8* func_002a9d68() asm("func_002a9d68");
struct W2441Ent { s8 slot; u8 f1; u8 pad[14]; };
struct W2441Hdr { u8 h[16]; W2441Ent e[1]; };
struct W2441Bits { u32 w[2]; };
struct W2441Rec { u8 pad[324]; W2441Bits b[1]; };
W2441Hdr* func_00294000(s32) asm("func_00294000");
s32 func_002b3ac8(s8) asm("func_002b3ac8");
extern W2441Rec* D_0035f610 asm("D_0035f610");
void func_002ac678(s32 idx) asm("func_002ac678");
void func_002ac678(s32 idx) {
    W2441Rec* base = (W2441Rec*)func_002a9d68();
    W2441Ent* e = func_00294000(9)->e;
    e += idx;
    s32 n = func_002b3ac8(e->f1 & 0xf);
    for (s32 i = 0; i < n; i++) { u32* s = D_0035f610->b[e->slot].w; u32 w = (u32)i >> 5; u32 m = 1 << (i & 31);
 if (s[w] & m) { u32* d = base->b[e->slot].w; if (!(d[w] & m)) d[w] |= m; } }
}
}  // namespace n002ac678

// 002ac748 (was src/anon/batch_wcx2.cpp)
namespace n002ac748 {
s32 Tz__JmNewInfo__isPuzzleInfoNew(s32) asm("Tz__JmNewInfo__isPuzzleInfoNew");
// --------------------
extern u8* D_0035f610_2ac748 asm("D_0035f610");
u8* func_001d9e30(u8*) asm("func_001d9e30");
s32 Tz__Jiminy__AreaWorld2JmWorld(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
s32 Tz__JmNewInfo__isPuzzleInfoNew(s32 key) asm("Tz__JmNewInfo__isPuzzleInfoNew");
s32 Tz__JmNewInfo__isPuzzleInfoNew(s32 key)
{
    u8* e = 0;
    s32 r = 0;
    for (;;) {
        e = func_001d9e30(e);
        if (e == 0) break;
        if (key >= 0 && Tz__Jiminy__AreaWorld2JmWorld(e[4]) != key) continue;
        u8 b = e[1];
        u32* bits = (u32*)(D_0035f610_2ac748 + e[0] * 8 + 404);
        if (bits[b >> 5] & (1 << (b & 31))) {
            r = 1;
            break;
        }
    }
    return r;
}
}  // namespace n002ac748

// 002ac800 (was src/anon/batch_w91.cpp)
namespace n002ac800 {
// --- 002ab540
static inline bool tbit91(u32* a, u32 i) { return (a[i >> 5] & (1 << (i & 31))) != 0; }
extern u8* D_0035f610 asm("D_0035f610");
s32 Tz__Jiminy__AreaWorld2JmWorld(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
// --- 002ac800
u8* func_002a9d68(void) asm("func_002a9d68");
u8* func_001d9e30(u8*) asm("func_001d9e30");
// record_range_check_or_first
u32 func_002ac800(s32 who) asm("func_002ac800");
// record_range_check_or_first
u32 func_002ac800(s32 who) {
    u8* p = 0;
    u32 r = 1;
    u8* x = func_002a9d68();
    for (;;) {
        p = func_001d9e30(p);  // record_range_check_or_first
        if (!p) break;
        if (who >= 0 && Tz__Jiminy__AreaWorld2JmWorld(p[4]) != who) continue;
        if (!tbit91((u32*)(D_0035f610 + p[0] * 8 + 404), p[1])) continue;
        r = tbit91((u32*)(x + p[0] * 8 + 404), p[1]);
        if (!r) break;
    }
    return r;
}
}  // namespace n002ac800

// 002ac8e0 (was src/anon/batch_wcx2.cpp)
namespace n002ac8e0 {
// --------------------
extern u8* D_0035f610_2ac8e0 asm("D_0035f610");
u8* func_001d9e30_2ac8e0(u8*) asm("func_001d9e30");
s32 func_002764b0_2ac8e0(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
u8* func_002a9d68_2ac8e0() asm("func_002a9d68");
void func_002ac8e0(s32 key) asm("func_002ac8e0");
void func_002ac8e0(s32 key)
{
    u8* save = func_002a9d68_2ac8e0();
    u8* e = 0;
    for (;;) {
        e = func_001d9e30_2ac8e0(e);
        if (e == 0) break;
        if (func_002764b0_2ac8e0(e[4]) != key) continue;
        u8 b = e[1];
        u32* gb = (u32*)(D_0035f610_2ac8e0 + e[0] * 8 + 404);
        u32 m = 1 << (b & 31);
        if (gb[b >> 5] & m) {
            u32* d = (u32*)(save + e[0] * 8 + 404);
            if (!(d[b >> 5] & m)) d[b >> 5] |= m;
        }
    }
}
}  // namespace n002ac8e0

// 002ac9b0 (was src/anon/batch_wcx2.cpp)
namespace n002ac9b0 {
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
s32 func_002aa098(s32) asm("func_002aa098");
s32 func_002aa2f8(s32) asm("func_002aa2f8");
// test_bit_global_b
s32 func_002aaa38(s32) asm("func_002aaa38");
// test_bit_global_a
s32 func_002aae88(s32) asm("func_002aae88");
s32 func_002ab2b0(s32) asm("func_002ab2b0");
s32 Tz__JmNewInfo__isTreasureNew(s32) asm("Tz__JmNewInfo__isTreasureNew");
s32 Tz__JmNewInfo__isNaviNew(s32) asm("Tz__JmNewInfo__isNaviNew");
s32 func_002abc60(s32) asm("func_002abc60");
s32 Tz__JmNewInfo__isPuzzlePieceNew(s32) asm("Tz__JmNewInfo__isPuzzlePieceNew");
s32 Tz__JmNewInfo__isPuzzleInfoNew(s32) asm("Tz__JmNewInfo__isPuzzleInfoNew");
s32 func_002aa668(s32, s32) asm("func_002aa668");
s32 Tz__JmNewInfo__isStoryNew(s32, s32) asm("Tz__JmNewInfo__isStoryNew");
s32 Tz__JmDiagram__GetNewInfo(s32, s32) asm("Tz__JmDiagram__GetNewInfo");
s32 Tz__JmNewInfo__isWorldNew(s32 a) asm("Tz__JmNewInfo__isWorldNew");
s32 Tz__JmNewInfo__isWorldNew(s32 a)
{
    if (a == 15) {
        if (func_002aa098(-1)) return 1;
        if (func_002aa2f8(-1)) return 1;
        if (func_002aaa38(-1)) return 1;
        if (func_002aae88(-1)) return 1;
        if (func_002ab2b0(-1)) return 1;
        if (Tz__JmNewInfo__isTreasureNew(-1)) return 1;
        if (Tz__JmNewInfo__isNaviNew(-1)) return 1;
        if (func_002abc60(-1)) return 1;
        if (Tz__JmNewInfo__isPuzzlePieceNew(-1)) return 1;
        if (Tz__JmNewInfo__isPuzzleInfoNew(-1)) return 1;
    } else {
        if (func_002aa668(a, -1)) return 1;
        if (func_002aae88(a)) return 1;
        if (func_002ab2b0(a)) return 1;
        if (Tz__JmNewInfo__isTreasureNew(a)) return 1;
        if (Tz__JmNewInfo__isNaviNew(a)) return 1;
        if (Tz__JmNewInfo__isStoryNew(a, -1)) return 1;
        if (Tz__JmDiagram__GetNewInfo(0, a)) return 1;
        if (Tz__JmDiagram__GetNewInfo(1, -1)) return 1;
        if (Tz__JmNewInfo__isPuzzleInfoNew(a)) return 1;
    }
    return 0;
}
}  // namespace n002ac9b0

// 002acb20 (was src/anon/batch_wcx2.cpp)
namespace n002acb20 {
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
s32 func_002a9f50(s32) asm("func_002a9f50");
s32 func_002aa378(s32) asm("func_002aa378");
s32 func_002aaab8(s32) asm("func_002aaab8");
s32 func_002aaf40(s32) asm("func_002aaf40");
s32 func_002ab368(s32) asm("func_002ab368");
s32 func_002ab620(s32) asm("func_002ab620");
s32 func_002ab9c8(s32) asm("func_002ab9c8");
s32 func_002abce8(s32) asm("func_002abce8");
s32 func_002ac538(s32) asm("func_002ac538");
s32 func_002ac800(s32) asm("func_002ac800");
s32 func_002aa788(s32, s32) asm("func_002aa788");
s32 func_002ac110(s32, s32) asm("func_002ac110");
s32 Tz__JmDiagram__GetNewInfo(s32, s32) asm("Tz__JmDiagram__GetNewInfo");
s32 func_002acb20(s32 a) asm("func_002acb20");
s32 func_002acb20(s32 a)
{
    if (a == 15) {
        if (!func_002a9f50(-1)) return 0;
        if (!func_002aa378(-1)) return 0;
        if (!func_002aaab8(-1)) return 0;
        if (!func_002aaf40(-1)) return 0;
        if (!func_002ab368(-1)) return 0;
        if (!func_002ab620(-1)) return 0;
        if (!func_002ab9c8(-1)) return 0;
        if (!func_002abce8(-1)) return 0;
        if (!func_002ac538(-1)) return 0;
        if (!func_002ac800(-1)) return 0;
    } else {
        if (!func_002aa788(a, -1)) return 0;
        if (!func_002aaf40(a)) return 0;
        if (!func_002ab368(a)) return 0;
        if (!func_002ab620(a)) return 0;
        if (!func_002ab9c8(a)) return 0;
        if (!func_002ac110(a, -1)) return 0;
        if (Tz__JmDiagram__GetNewInfo(0, a) == 1) return 0;
        if (Tz__JmDiagram__GetNewInfo(1, -1) == 1) return 0;
        if (!func_002ac800(a)) return 0;
    }
    return 1;
}
}  // namespace n002acb20

// 002acc98 (was src/anon/batch_w1586_g.cpp)
namespace n002acc98 {
void func_002a9d88(void) asm("func_002a9d88");
s32 func_002aa098(s32) asm("func_002aa098");
s32 func_002aa2f8(s32) asm("func_002aa2f8");
s32 func_002aa668(s32, s32) asm("func_002aa668");
s32 func_002aaa38(s32) asm("func_002aaa38");
s32 func_002aae88(s32) asm("func_002aae88");
s32 func_002ab2b0(s32) asm("func_002ab2b0");
s32 Tz__JmNewInfo__isTreasureNew(s32) asm("Tz__JmNewInfo__isTreasureNew");
s32 Tz__JmNewInfo__isNaviNew(s32) asm("Tz__JmNewInfo__isNaviNew");
s32 func_002abc60(s32) asm("func_002abc60");
s32 Tz__JmNewInfo__isStoryNew(s32, s32) asm("Tz__JmNewInfo__isStoryNew");
s32 Tz__JmNewInfo__isPuzzlePieceNew(s32) asm("Tz__JmNewInfo__isPuzzlePieceNew");
s32 Tz__JmNewInfo__isPuzzleInfoNew(s32) asm("Tz__JmNewInfo__isPuzzleInfoNew");
u8 Tz__JmNewInfo__isAnyNew(void) asm("Tz__JmNewInfo__isAnyNew");
u8 Tz__JmNewInfo__isAnyNew(void) {
    s32 i;
    func_002a9d88();
    if (func_002aa098(-1)) return 1;
    if (func_002aa2f8(-1)) return 1;
    if (func_002aaa38(-1)) return 1;
    if (func_002aae88(-1)) return 1;
    if (func_002ab2b0(-1)) return 1;
    if (Tz__JmNewInfo__isTreasureNew(-1)) return 1;
    if (Tz__JmNewInfo__isNaviNew(-1)) return 1;
    if (func_002abc60(-1)) return 1;
    if (Tz__JmNewInfo__isPuzzlePieceNew(-1)) return 1;
    if (Tz__JmNewInfo__isPuzzleInfoNew(-1)) return 1;
    for (i = 0; i < 15; i++) {
        if (func_002aa668(i, -1)) return 1;
        if (Tz__JmNewInfo__isStoryNew(i, -1)) return 1;
    }
    return 0;
}
}  // namespace n002acc98

// 002acda8 (was src/anon/batch_w96.cpp)
namespace n002acda8 {
u32 func_00170b30(u32) asm("func_00170b30");
s32 func_00103b38(void) asm("func_00103b38");
u32 func_00103570(void) asm("func_00103570");
u32 func_00106178(u32, u32) asm("func_00106178");
s32 func_00293fb0(void) asm("func_00293fb0");
void Tz__JmInfo__Init(u32) asm("Tz__JmInfo__Init");
void Tz__JmInfo__SetLeadData(void) asm("Tz__JmInfo__SetLeadData");
u8* func_001063c0(u32, u32) asm("func_001063c0");
void func_00319a60(u8*) asm("func_00319a60");
// clear_fixed_blocks
u8* func_001063f0(u32, u32) asm("func_001063f0");
extern u32 D_0035f628 asm("D_0035f628");
extern u32 D_0035f62c asm("D_0035f62c");
extern u8 D_0035f614 asm("D_0035f614");
extern u32 D_0035f618 asm("D_0035f618");
extern u32 D_0035f61c asm("D_0035f61c");
extern u8* D_0035f620 asm("D_0035f620");
extern u8* D_0035f624 asm("D_0035f624");
struct Pair_w96 { u32 a; u32 b; };
void func_002acda8(void) asm("func_002acda8");
void func_002acda8(void) {
    Pair_w96* q;
    s32 i;
    D_0035f628 = 0;
    D_0035f62c = 0;
    D_0035f614 = 0;
    D_0035f618 = 0;
    if (func_00103b38()) {
        D_0035f618 = func_00103570();
    } else {
        u32 v = func_00170b30(0x10000);  // alloc_align128
        D_0035f61c = v;
        D_0035f618 = func_00106178(v, 0x10000);
        if (!func_00293fb0()) {
            Tz__JmInfo__Init(D_0035f618);
            Tz__JmInfo__SetLeadData();
            D_0035f614 = 1;
        }
    }
    {
        u8* p = func_001063c0(2408, D_0035f618);
        func_00319a60(p);  // clear_fixed_blocks
        D_0035f620 = p;
    }
    q = (Pair_w96*)func_001063f0(80, D_0035f618);
    {
        Pair_w96* e = q;
        for (i = 9; i != -1; i--) {
            e->a = 0;
            e->b = 0;
            e++;
        }
    }
    D_0035f624 = (u8*)q;
}
}  // namespace n002acda8

// 002aceb0 (was src/tozawa/jm_complete.cpp)
namespace Tz { // method 002aceb0
extern void* D_0035f620 asm("D_0035f620");
extern void* D_0035f624 asm("D_0035f624");
extern void* D_0035f61c asm("D_0035f61c");
extern s8 D_0035f614 asm("D_0035f614");
extern u32 D_0035f618 asm("D_0035f618");
void func_00106420(void*) asm("func_00106420");
void func_00106450(void*) asm("func_00106450");
void func_00293eb0() asm("func_00293eb0");
void func_00170c00(void*) asm("func_00170c00");
void JmComplete::Exit() {
    void* t7 = D_0035f620;
    if (t7 != 0) {
        func_00106420(t7);
        D_0035f620 = 0;
    }

    t7 = D_0035f624;
    if (t7 != 0) {
        func_00106450(t7);
        D_0035f624 = 0;
    }

    if (D_0035f614 != 0) {
        func_00293eb0();
    }

    t7 = D_0035f61c;
    if (t7 != 0) {
        func_00170c00(t7);
        D_0035f61c = 0;
    }

    D_0035f614 = 0;
    D_0035f618 = 0;
}
}  // Tz

// 002acf48 (was src/anon/batch_w78.cpp)
namespace n002acf48 {
extern s32 D_0035f62c asm("D_0035f62c");
extern s32 D_0035f628 asm("D_0035f628");
void func_002ad110(void) asm("func_002ad110");
void Tz__JmComplete__CheckAnsem(void) asm("Tz__JmComplete__CheckAnsem");
void Tz__JmComplete__CheckAlbum(void) asm("Tz__JmComplete__CheckAlbum");
void Tz__JmComplete__CheckBattle(void) asm("Tz__JmComplete__CheckBattle");
void Tz__JmComplete__CheckQuest(void) asm("Tz__JmComplete__CheckQuest");
void func_002ad878(void) asm("func_002ad878");
void Tz__JmComplete__CheckTreasure(void) asm("Tz__JmComplete__CheckTreasure");
void func_002adbd0(void) asm("func_002adbd0");
void Tz__JmComplete__CheckSynthesis(void) asm("Tz__JmComplete__CheckSynthesis");
void Tz__JmComplete__CheckPuzzle(void) asm("Tz__JmComplete__CheckPuzzle");
void Tz__JmComplete__CheckStory(void) asm("Tz__JmComplete__CheckStory");
s32 func_002ae0c0(s32) asm("func_002ae0c0");
void Tz__JmComplete__CheckAll(void) asm("Tz__JmComplete__CheckAll");
void Tz__JmComplete__CheckAll(void) {
    D_0035f62c = 0;
    D_0035f628 = 0;
    func_002ad110();
    Tz__JmComplete__CheckAnsem();
    Tz__JmComplete__CheckAlbum();
    Tz__JmComplete__CheckBattle();
    Tz__JmComplete__CheckQuest();
    func_002ad878();
    Tz__JmComplete__CheckTreasure();
    func_002adbd0();
    Tz__JmComplete__CheckSynthesis();
    Tz__JmComplete__CheckPuzzle();
    Tz__JmComplete__CheckStory();
    D_0035f628 += 15;
    for (s32 i = 0; i < 15; i++) {
        if (func_002ae0c0(i)) D_0035f62c++;
    }
}
}  // namespace n002acf48

// 002ad018 (was src/anon/batch_w84.cpp)
namespace n002ad018 {
extern u32 D_0035f620 asm("D_0035f620");
extern u32 D_0035f62c asm("D_0035f62c");
extern u32 D_0035f628 asm("D_0035f628");
void func_002acda8(void) asm("func_002acda8");
void Tz__JmComplete__CheckAll(void) asm("Tz__JmComplete__CheckAll");
void func_002ae280(u32*, u32*) asm("func_002ae280");
void func_002aceb0(void) asm("func_002aceb0");
// 002e9b58: moved to src/anon/unit_002e9a00.cpp

// Accumulates two counters and returns their ratio as a percentage.
s32 wtarget_002ad018(u32, u32, u32, u32) asm("_Z16wtarget_002ad018jjjj");
// 002e9b58: moved to src/anon/unit_002e9a00.cpp

// Accumulates two counters and returns their ratio as a percentage.
s32 wtarget_002ad018(u32, u32, u32, u32) {
    if (D_0035f620 == 0) func_002acda8();
    Tz__JmComplete__CheckAll();
    u32 a, b;
    b = 0;
    a = 0;
    func_002ae280(&a, &b);
    D_0035f62c += a;
    D_0035f628 += b;
    func_002aceb0();
    return (s32)((f32)D_0035f62c / (f32)D_0035f628 * 100.0f);
}
}  // namespace n002ad018

// 002ad110 (was src/anon/batch_w67.cpp)
namespace n002ad110 {
// Global accessed through a union with a byte member: not assumed distinct
// from struct fields.
union GWord { s32 v; u8 c; };
struct BitInfo { u32 a, b; s32 n; };
void func_00294020(u32*) asm("func_00294020");
BitInfo* func_00294000(s32) asm("func_00294000");
extern u32* D_0035f620 asm("D_0035f620");
extern GWord D_0035f628 asm("D_0035f628");
extern GWord D_0035f62c asm("D_0035f62c");
// 002ad110: count set bits
void func_002ad110(void) asm("func_002ad110");
// 002ad110: count set bits
void func_002ad110(void)
{
    func_00294020(D_0035f620);
    BitInfo* v = func_00294000(3);
    D_0035f628.v += v->n;
    for (s32 i = 0; i < v->n; i++) {
        if (D_0035f620[(u32)i >> 5] & (1 << (i & 31))) D_0035f62c.v++;
    }
}
}  // namespace n002ad110

// 002ad1b0 (was src/anon/batch_w68.cpp)
namespace n002ad1b0 {
/* ---- 002ad1b0 ---- */
u8* func_00294000(s32) asm("func_00294000");
extern u32* D_0035f620 asm("D_0035f620");
s32 func_002ad1b0(s32 id) asm("func_002ad1b0");
s32 func_002ad1b0(s32 id) {
    s32 ok = 1;
    u8* t = func_00294000(3);
    s32 n = *(s32*)(t + 8);
    s32 i;
    u8* e = t + 16;
    for (i = 0; i < n; i++, e += 36) {
        if (id < 0 || *(s8*)e == id) {
            u16 f = *(u16*)(e + 4);
            if (!(D_0035f620[f >> 5] & (1 << (f & 31)))) { ok = 0; break; }
        }
    }
    return ok;
}
}  // namespace n002ad1b0

// 002ad258 (was src/anon/batch_wcx2.cpp)
namespace n002ad258 {
// --------------------
struct E2ad258 { u8 d[8]; };
struct T2ad258 { u8 pad[8]; s32 n; u8 pad2[4]; E2ad258 e[1]; };
T2ad258* func_00294000_2ad258(s32) asm("func_00294000");
s32 func_002943e8_2ad258(E2ad258*) asm("func_002943e8");
extern u8* D_0035f620 asm("D_0035f620");
union C2ad258 { s32 i; u32 u; };
extern C2ad258 D_0035f628 asm("D_0035f628");
extern s32 D_0035f62c asm("D_0035f62c");
void Tz__JmComplete__CheckAnsem() asm("Tz__JmComplete__CheckAnsem");
void Tz__JmComplete__CheckAnsem()
{
    s32 i = 0;
    T2ad258* t = func_00294000_2ad258(4);
    D_0035f628.i += t->n;
    E2ad258* e = t->e;
    for (; i < t->n; i++) {
        if (func_002943e8_2ad258(&e[i])) {
            u32* gb = (u32*)(D_0035f620 + 316);
            u32 m = 1 << (i & 31);
            u32* q = &gb[(u32)i >> 5];
            *q |= m;
            D_0035f62c++;
        }
    }
}
}  // namespace n002ad258

// 002ad338 (was src/anon/batch_w52.cpp)
namespace n002ad338 {
extern u8* D_0035f620 asm("D_0035f620");
// True when flags 0..12 are all set.
u32 func_002ad338(void) asm("func_002ad338");
// True when flags 0..12 are all set.
u32 func_002ad338(void) {
    u32* bits = (u32*)(D_0035f620 + 316);
    s32 i;
    u32 r = 1;
    for (i = 0; i < 13; i++) {
        if (!(bits[(u32)i >> 5] & (1 << (i & 31)))) {
            r = 0;
            break;
        }
    }
    return r;
}
}  // namespace n002ad338

// 002ad390 (was src/anon/batch_wcx2.cpp)
namespace n002ad390 {
// --------------------
struct E2ad390 { s8 k; u8 pad[11]; };
struct T2ad390 { u8 pad[8]; s32 n; u8 pad2[4]; E2ad390 e[1]; };
T2ad390* func_00294000_2ad390(s32) asm("func_00294000");
s32 func_00294268_2ad390(E2ad390*) asm("func_00294348");
extern u8* D_0035f620_2ad390 asm("D_0035f620");
union C2ad390 { s32 i; u32 u; };
extern C2ad390 D_0035f628_2ad390 asm("D_0035f628");
extern s32 D_0035f62c_2ad390 asm("D_0035f62c");
void Tz__JmComplete__CheckAlbum() asm("Tz__JmComplete__CheckAlbum");
void Tz__JmComplete__CheckAlbum()
{
    s32 i = 0;
    s32 prev = -1;
    s32 j = 0;
    T2ad390* t = func_00294000_2ad390(2);
    D_0035f628_2ad390.i += t->n;
    E2ad390* e = t->e;
    for (; i < t->n; i++) {
        s32 k = e[i].k;
        if (prev != k) {
            prev = k;
            j = 0;
        }
        if (func_00294268_2ad390(&e[i])) {
            u32* gb = (u32*)(D_0035f620_2ad390 + e[i].k * 4 + 68);
            u32 m = 1 << (j & 31);
            u32* q = &gb[(u32)j >> 5];
            *q |= m;
            D_0035f62c_2ad390++;
        }
        j++;
    }
}
}  // namespace n002ad390

// 002ad4a8 (was src/anon/batch_w243.cpp)
namespace n002ad4a8 {
struct w243_L4 { u8 pad[8]; s32 n; };
w243_L4* func_00294000(s32) asm("func_00294000");
s32 func_002aa5b8(s32, s32) asm("func_002aa5b8");
extern u8* D_0035f620 asm("D_0035f620");
s32 Tz__JmComplete__isAlbumComp(s32 a) asm("Tz__JmComplete__isAlbumComp");
s32 Tz__JmComplete__isAlbumComp(s32 a) {
    s32 i; s32 ok = 1;
    w243_L4* l = func_00294000(2);
    for (i = 0; i < l->n; i++) {
        s32 r = func_002aa5b8(a, i);
        if (r >= 0) {
            u32* q = (u32*)(D_0035f620 + (a << 2)) + 17;
            if (!(q[(u32)r >> 5] & (1 << (r & 31)))) { ok = 0; break; }
        }
    }
    return ok;
}
}  // namespace n002ad4a8

// 002ad580 (was src/anon/batch_wcx2.cpp)
namespace n002ad580 {
// --------------------
struct E2ad580 { u8 d[8]; };
struct T2ad580 { u8 pad[8]; s32 n; u8 pad2[4]; E2ad580 e[1]; };
T2ad580* func_00294000_2ad580(s32) asm("func_00294000");
s32 func_002944d0_2ad580(E2ad580*) asm("func_002944d0");
extern u8* D_0035f620_2ad580 asm("D_0035f620");
union C2ad580 { s32 i; u32 u; };
extern C2ad580 D_0035f628_2ad580 asm("D_0035f628");
extern s32 D_0035f62c_2ad580 asm("D_0035f62c");
void Tz__JmComplete__CheckBattle() asm("Tz__JmComplete__CheckBattle");
void Tz__JmComplete__CheckBattle()
{
    s32 i = 0;
    T2ad580* t = func_00294000_2ad580(6);
    D_0035f628_2ad580.i += t->n;
    E2ad580* e = t->e;
    for (; i < t->n; i++) {
        if (func_002944d0_2ad580(&e[i])) {
            u32* gb = (u32*)(D_0035f620_2ad580 + 132);
            u32 m = 1 << (i & 31);
            u32* q = &gb[(u32)i >> 5];
            *q |= m;
            D_0035f62c_2ad580++;
        }
    }
}
}  // namespace n002ad580

// 002ad660 (was src/anon/batch_w61.cpp)
namespace n002ad660 {
u8* func_00294000(u32) asm("func_00294000");
extern u8* D_0035f620 asm("D_0035f620");
s32 func_002ad660(void) asm("func_002ad660");
s32 func_002ad660(void) {
    s32 r = 1;
    u8* v = func_00294000(6);
    for (s32 i = 0; i < *(s32*)(v + 8); i++) {
        u32* bits = (u32*)(D_0035f620 + 132);
        if (!(*(u32*)(((u32)i >> 5) * 4 + (u32)bits) & (1 << (i & 31)))) {
            r = 0;
            break;
        }
    }
    return r;
}
}  // namespace n002ad660

// 002ad6e8 (was src/anon/batch_wcx2.cpp)
namespace n002ad6e8 {
// --------------------
struct E2ad6e8 { u8 d[16]; };
struct T2ad6e8 { u8 pad[8]; s32 n; u8 pad2[4]; E2ad6e8 e[1]; };
T2ad6e8* func_00294000_2ad6e8(s32) asm("func_00294000");
s32 func_002a99c8_2ad6e8(E2ad6e8*) asm("Tz__JmQuest__GetQuestStat");
extern u8* D_0035f620_2ad6e8 asm("D_0035f620");
union C2ad6e8 { s32 i; u32 u; };
extern C2ad6e8 D_0035f628_2ad6e8 asm("D_0035f628");
extern s32 D_0035f62c_2ad6e8 asm("D_0035f62c");
void Tz__JmComplete__CheckQuest() asm("Tz__JmComplete__CheckQuest");
void Tz__JmComplete__CheckQuest()
{
    s32 i = 0;
    T2ad6e8* t = func_00294000_2ad6e8(8);
    D_0035f628_2ad6e8.i += t->n;
    E2ad6e8* e = t->e;
    for (; i < t->n; i++) {
        if (func_002a99c8_2ad6e8(&e[i]) == 2) {
            u32* gb = (u32*)(D_0035f620_2ad6e8 + 148);
            u32 m = 1 << (i & 31);
            u32* q = &gb[(u32)i >> 5];
            *q |= m;
            D_0035f62c_2ad6e8++;
        }
    }
}
}  // namespace n002ad6e8

// 002ad7d0 (was src/anon/batch_wcx.cpp)
namespace n002ad7d0 {
u8* func_00294000(s32) asm("func_00294000");
extern u8* D_0035f620 asm("D_0035f620");
s32 func_002ad7d0(s32 id) asm("func_002ad7d0");
s32 func_002ad7d0(s32 id)
{
    s32 r = 1;
    u8* t = func_00294000(8);
    s32 n = *(s32*)(t + 8);
    u16* e = (u16*)(t + 16);
    for (u32 i = 0; (s32)i < n; i++, e += 8) {
        if (id >= 0 && *e != id) continue;
        u32* bits = (u32*)(D_0035f620 + 148);
        if (!(bits[i >> 5] & (1 << (i & 31)))) { r = 0; break; }
    }
    return r;
}
}  // namespace n002ad7d0

// 002ad878 (was src/anon/batch_w80.cpp)
namespace n002ad878 {
// ---- unit 17 (good2ad.cpp)
struct U17_GotEnt { u8 pad[6]; u16 id; };
struct U17_GotList { u8 pad[8]; s32 n; u8 pad2[4]; U17_GotEnt e[1]; };
struct U17_GotBits { u8 pad[136]; u32 bits[41]; u32 bits300[8]; };
extern union { s32 v; u32* p; } U17_D_0035f628_u asm("D_0035f628");
#define U17_D_0035f628 U17_D_0035f628_u.v
extern union { U17_GotBits* p; s32 v; } U17_D_0035f620_u asm("D_0035f620");
#define U17_D_0035f620 U17_D_0035f620_u.p
extern s32 D_0035f62c asm("D_0035f62c");
U17_GotList* func_00294000(u32) asm("func_00294000");
s32 Tz__JmMiniGame__isPlay(u32) asm("Tz__JmMiniGame__isPlay");
void func_002ad878(void) asm("func_002ad878");
void func_002ad878(void) {
    s32 i;
    U17_GotList* l = func_00294000(7);
    U17_D_0035f628 += l->n;
    for (i = 0; i < l->n; i++) {
        if (Tz__JmMiniGame__isPlay(l->e[i].id)) {
            u32* b = U17_D_0035f620->bits;
            u32* w = &b[(u32)i >> 5];
            *w |= 1 << (i & 31);
            D_0035f62c++;
        }
    }
}
}  // namespace n002ad878

// 002ad950 (was src/anon/batch_wcx.cpp)
namespace n002ad950 {
u8* func_00294000(s32) asm("func_00294000");
extern u8* D_0035f620 asm("D_0035f620");
s32 func_002ad950(s32 id) asm("func_002ad950");
s32 func_002ad950(s32 id)
{
    s32 r = 1;
    u8* t = func_00294000(7);
    s32 n = *(s32*)(t + 8);
    u16* e = (u16*)(t + 16);
    for (u32 i = 0; (s32)i < n; i++, e += 4) {
        if (id >= 0 && *e != id) continue;
        u32* bits = (u32*)(D_0035f620 + 136);
        if (!(bits[i >> 5] & (1 << (i & 31)))) { r = 0; break; }
    }
    return r;
}
}  // namespace n002ad950

// 002ad9f8 (was src/anon/batch_w85.cpp)
namespace n002ad9f8 {
// 0x001a24a0: definition moved into src/anon/unit_0019fb70.cpp

s32 func_00181500(u32) asm("func_00181500");
struct Ev2ad { u8 p0[4]; u8 done; u8 p5[3]; u16 id; };
Ev2ad* func_001a82b0(Ev2ad*) asm("func_001a82b0");
s32 func_002a4390(Ev2ad*) asm("func_002a4390");
extern s32 D_0035f628 asm("D_0035f628");
extern s32 D_0035f62c asm("D_0035f62c");
extern u8* D_0035f620 asm("D_0035f620");
// counts unlocked entries and marks the ones that pass in the bitmask
void Tz__JmComplete__CheckTreasure(void) asm("Tz__JmComplete__CheckTreasure");
// counts unlocked entries and marks the ones that pass in the bitmask
void Tz__JmComplete__CheckTreasure(void) {
    Ev2ad* p = 0;
    u32 idx = 0;
    for (;;) {
        p = func_001a82b0(p);
        if (!p) break;
        if (!p->done && p->id && p->id != 2048 && func_00181500(p->id)) {
            D_0035f628++;
            if (func_002a4390(p)) {
                { u32 o = (idx >> 5) * 4; u32 m = 1 << (idx & 31); u8* b = D_0035f620 + 236; *(u32*)(b + o) |= m; }
                D_0035f62c++;
            }
        }
        idx++;
    }
}
}  // namespace n002ad9f8

// 002adaf0 (was src/anon/batch_w76.cpp)
namespace n002adaf0 {
static inline bool TestBit(u32* bits, u32 i) { return (bits[i >> 5] & (1 << (i & 31))) != 0; }
extern u8* D_0035f620 asm("D_0035f620");
u8* func_001a82b0(u8*) asm("func_001a82b0");
s32 Tz__Jiminy__AreaWorld2JmWorld(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
bool Tz__JmComplete__isTreasureComp(s32 who) asm("Tz__JmComplete__isTreasureComp");
bool Tz__JmComplete__isTreasureComp(s32 who)
{
    u8* e = 0;
    u32 idx = 0;
    bool r = true;
    for (;;) {
        e = func_001a82b0(e);
        if (!e) break;
        if (e[4] == 0) {
            u16 k = *(u16*)(e + 8);
            if (k != 0 && k != 2048) {
                if (who < 0 || Tz__Jiminy__AreaWorld2JmWorld(e[5]) == who) {
                    if (!TestBit((u32*)(D_0035f620 + 236), idx)) { r = false; break; }
                }
            }
        }
        idx++;
    }
    return r;
}
}  // namespace n002adaf0

// 002adbd0 (was src/anon/batch_w80.cpp)
namespace n002adbd0 {
// ---- unit 18 (good2adb.cpp)
struct U18_GotBits { u8 pad[136]; u32 bits[41]; u32 bits300[8]; };
extern union { s32 v; u32* p; } U18_D_0035f628_u asm("D_0035f628");
#define U18_D_0035f628 U18_D_0035f628_u.v
extern union { U18_GotBits* p; s32 v; } U18_D_0035f620_u asm("D_0035f620");
#define U18_D_0035f620 U18_D_0035f620_u.p
extern s32 D_0035f62c asm("D_0035f62c");
struct U18_Evt { u8 pad[2]; u16 id; };
struct U18_EvtInfo { u8 pad[2]; u8 type; };
U18_Evt* func_001a82b0(U18_Evt*) asm("func_001a82b0");
U18_EvtInfo* func_001a80c8(u32) asm("func_001a80c8");
// table24_find_by_id
s32 func_002a43b0(U18_Evt*) asm("func_002a43b0");
void func_002adbd0(void) asm("func_002adbd0");
void func_002adbd0(void) {
    U18_Evt* e = 0;
    s32 n = 0;
    for (;;) {
        e = func_001a82b0(e);
        if (!e) break;
        if (func_001a80c8(e->id)->type != 22) continue;
        U18_D_0035f628++;
        if (func_002a43b0(e)) {
            u32* b = U18_D_0035f620->bits300;
            u32* w = &b[(u32)n >> 5];
            *w |= 1 << (n & 31);
            D_0035f62c++;
        }
        n++;
    }
}
}  // namespace n002adbd0

// 002adcb0 (was src/anon/batch_w81.cpp)
namespace n002adcb0 {
// --- 002adcb0: 1 unless an entry of type 22 (matching id, if id >= 0) has its flag bit clear
extern u8* D_0035f620 asm("D_0035f620");
u8* func_001a82b0(u8*) asm("func_001a82b0");
u8* func_001a80c8(u16) asm("func_001a80c8");
// table24_find_by_id
s32 Tz__Jiminy__AreaWorld2JmWorld(u8) asm("Tz__Jiminy__AreaWorld2JmWorld");
s32 Tz__JmComplete__isNaviComp(s32 id) asm("Tz__JmComplete__isNaviComp");
s32 Tz__JmComplete__isNaviComp(s32 id) {
    u8* e = 0;
    u32 i = 0;
    s32 r = 1;
    for (;;) {
        e = func_001a82b0(e);
        if (!e) break;
        if (func_001a80c8(*(u16*)(e + 2))[2] != 22) continue;
        if (id >= 0 && Tz__Jiminy__AreaWorld2JmWorld(e[5]) != id) { i++; continue; }
        u32* f = (u32*)(D_0035f620 + 300);
        if (!(f[i >> 5] & (1 << (i & 31)))) { r = 0; break; }
        i++;
    }
    return r;
}
}  // namespace n002adcb0

// 002add90 (was src/anon/batch_w292.cpp)
namespace n002add90 {
// 0x0015c500: definition moved into src/anon/unit_0015bab8.cpp


struct G2ad { u8 pad[320]; u32 bits[4]; };
extern s32 D_0035f628 asm("D_0035f628");
extern s32 D_0035f620 asm("D_0035f620");
extern s32 D_0035f62c asm("D_0035f62c");
u8* func_001058e8(void) asm("func_001058e8");
s32 Tz__JmSynthe__isEnableRecipe(void) asm("Tz__JmSynthe__isEnableRecipe");
s32 Tz__JmSynthe__isEnableMaterial(void) asm("Tz__JmSynthe__isEnableMaterial");
static inline s32 tb2ad(u32* base, u32 n) { return base[n >> 5] & (1 << (n & 31)); }
static inline void sb2ad(u32* base, u32 n) { u32 m = 1 << (n & 31); u32* p = base + (n >> 5); *p |= m; }
static inline s32 cnt2ad(u8* s, s32 off, s32 n)
{
    s32 c = 0;
    s32 j;
    for (j = 0; j < n; j++) if (tb2ad((u32*)(s + off), j)) c++;
    return c;
}
void Tz__JmComplete__CheckSynthesis(void) asm("Tz__JmComplete__CheckSynthesis");
void Tz__JmComplete__CheckSynthesis(void)
{
    u8* s;
    s32 a, b, i, ok;
    s = func_001058e8() + 18932;
    a = Tz__JmSynthe__isEnableRecipe();
    b = Tz__JmSynthe__isEnableMaterial();
    D_0035f628 += 4;
    for (i = 0; i < 4; i++) {
        ok = (i == 0 || i == 3) ? a : b;
        if (!ok) continue;
        switch (i) {
        case 0: ok = s[576] + 1 >= 9; break;
        case 1: ok = cnt2ad(s, 0, 60) >= 60; break;
        case 2: ok = cnt2ad(s, 8, 54) >= 54; break;
        case 3: ok = cnt2ad(s, 28, 80) >= 59; break;
        }
        if (ok) {
            sb2ad(((G2ad*)D_0035f620)->bits, i);
            D_0035f62c++;
        }
    }
}
}  // namespace n002add90

// 002adf60 (was src/anon/batch_w47.cpp)
namespace n002adf60 {
// 1 if bit a (or every bit 0..3 when a < 0) is set in the mask at +320.
extern u8* D_0035f620 asm("D_0035f620");
s32 func_002adf60(s32 a) asm("func_002adf60");
s32 func_002adf60(s32 a) {
    s32 r = 1;
    u32* bits = (u32*)(D_0035f620 + 320);
    for (s32 i = 0; i < 4; i++) {
        if (a < 0 || a == i) {
            if (!(bits[(u32)i >> 5] & (1 << (i & 31)))) { r = 0; break; }
        }
    }
    return r;
}
}  // namespace n002adf60

// 002adfd0 (was src/anon/batch_wcx2.cpp)
namespace n002adfd0 {
// --------------------
struct E2adfd0 { s8 k; u8 pad[11]; };
struct T2adfd0 { u8 pad[8]; s32 n; u8 pad2[4]; E2adfd0 e[1]; };
T2adfd0* func_00294000_2adfd0(s32) asm("func_00294000");
s32 func_00294268_2adfd0(E2adfd0*) asm("func_00294268");
extern u8* D_0035f620_2adfd0 asm("D_0035f620");
void Tz__JmComplete__CheckStory() asm("Tz__JmComplete__CheckStory");
void Tz__JmComplete__CheckStory()
{
    s32 i = 0;
    s32 prev = -1;
    s32 j = 0;
    T2adfd0* t = func_00294000_2adfd0(1);
    E2adfd0* e = t->e;
    for (; i < t->n; i++) {
        s32 k = e[i].k;
        if (prev != k) {
            j = 0;
            prev = k;
        }
        if (k < 15) {
            if (func_00294268_2adfd0(&e[i])) {
                u32* gb = (u32*)(D_0035f620_2adfd0 + e[i].k * 4 + 172);
                u32 m = 1 << (j & 31);
                u32* q = &gb[(u32)j >> 5];
                *q |= m;
            }
            j++;
        }
    }
}
}  // namespace n002adfd0

// 002ae0c0 (was src/anon/batch_w8023.cpp)
namespace n002ae0c0 {
struct JmEnt_2ae0c0 { s8 id; u8 pad[11]; };
struct JmData_2ae0c0 { int a; int b; int n; int c; JmEnt_2ae0c0 e[1]; };
JmData_2ae0c0* jm_getdata_2ae0c0(int) asm("_ZN2Tz6JmInfo7GetDataEi");
u32 func_002abf40(int, int) asm("func_002abf40");
struct Flags_2ae0c0 { u8 pad[0xac]; u32 bits[1]; };
extern Flags_2ae0c0* D_0035f620 asm("D_0035f620");
int func_002ae0c0(int id) asm("func_002ae0c0");
int func_002ae0c0(int id)
{
    int r = 1;
    JmData_2ae0c0* d = jm_getdata_2ae0c0(1);
    JmEnt_2ae0c0* e = d->e;
    int found = 0;
    int i = 0;
    for (i = 0; i < d->n; i++) {
        if (id != e[i].id || i + 1 >= d->n) {
            if (found || i + 1 >= d->n) {
            u32 k = func_002abf40(id, i - (i + 1 < d->n));
            u32* b = ((Flags_2ae0c0*)((u32*)D_0035f620 + id))->bits;
                r = (b[k >> 5] & (1 << (k & 31))) != 0;
                break;
            }
        } else {
            found = 1;
        }
    }
    return r;
}
}  // namespace n002ae0c0

// 002ae1b0 (was src/anon/batch_w84.cpp)
namespace n002ae1b0 {
struct E12 { u32 a; s8 k; u8 pad[7]; };
u8* func_00294000(s32) asm("func_00294000");
s32 func_00294480(void*) asm("func_00294480");
// record_lookup_success
s32 func_002ae1b0(s32 a, s32 b) asm("func_002ae1b0");
// record_lookup_success
s32 func_002ae1b0(s32 a, s32 b) {
    s32 found = 0;
    s32 r = 1;
    b = (a == 0) ? b : 16;
    u8* t = func_00294000(5);
    E12* e = (E12*)(t + 16);
    for (s32 i = 0; i < *(s32*)(t + 8); i++) {
        if (e[i].k != b) {
            if (found) break;
        } else {
            if (!found) found = 1;
            if (!func_00294480(&e[i])) {  // record_lookup_success
                r = 0;
                break;
            }
        }
    }
    return r;
}
}  // namespace n002ae1b0

// 002ae280 (was src/anon/batch_wcx2.cpp)
namespace n002ae280 {
// --------------------
struct E2ae280 { u8 b[12]; };
struct T2ae280 { u8 pad[8]; s32 n; u8 pad2[4]; E2ae280 e[1]; };
T2ae280* func_00294000_2ae280(s32) asm("func_00294000");
s32 func_00294480(E2ae280*) asm("func_00294480");
void func_002ae280(s32* cnt, s32* total) asm("func_002ae280");
void func_002ae280(s32* cnt, s32* total)
{
    s32 i = 0;
    T2ae280* t = func_00294000_2ae280(5);
    *total += t->n;
    E2ae280* e = t->e;
    for (; i < t->n; i++) {
        if (func_00294480(&e[i])) (*cnt)++;
    }
}
}  // namespace n002ae280

// 002ae320 (was src/anon/batch_w3724_nsa.cpp)
namespace n002ae320 {
struct Ent { u8 a; u8 b; };
struct Bits {
    u32 w[2];
    s32 Test(u32 b) { return w[b >> 5] & (1 << (b & 31)); }
    void Set(u32 b) { u32* p = &w[b >> 5]; *p |= 1 << (b & 31); }
};
struct HBits {
    u16 h[1];
    s32 Test(u32 b) { return h[b >> 4] & (1 << (b & 15)); }
    void Set(u32 b) { u16* p = &h[b >> 4]; *p |= 1 << (b & 15); }
};
struct Flags { u8 pad[0x144]; Bits x[10]; Bits y[10]; u8 pad2[484 - 0x144 - 160]; HBits hb; };
struct Rec { u8 a; u8 b; u8 pad[14]; };
struct Tbl { u8 pad[8]; s32 n; u8 pad2[4]; Rec r[1]; };
extern Flags* D_0035f620 asm("D_0035f620");
extern Bits* D_0035f624 asm("D_0035f624");
extern s32 D_0035f628 asm("D_0035f628");
extern s32 D_0035f62c asm("D_0035f62c");
Tbl* func_00294000(s32) asm("func_00294000");
Flags* func_002a9d68(void) asm("func_002a9d68");
Ent* func_001d9e30(Ent*) asm("func_001d9e30");
s32 func_001d9d48(Ent*) asm("func_001d9d48");
s32 func_002b3ac8(s32) asm("func_002b3ac8");
static inline s32 T1(u8 a, u8 b) { return D_0035f624[a].Test(b); }
static inline void S1(u8 a, u8 b) { D_0035f624[a].Set(b); }
static inline s32 TY(u8 a, u8 b) { return D_0035f620->y[a].Test(b); }
static inline void SY(u8 a, u8 b) { D_0035f620->y[a].Set(b); }
// Rebuilds the seen/collected bit tables and their counters (D_0035f628 total, D_0035f62c set).
// The unused i++ in the second loop gives it one latch, which matches the original block frequencies.
void Tz__JmComplete__CheckPuzzle(void) asm("Tz__JmComplete__CheckPuzzle");
// Rebuilds the seen/collected bit tables and their counters (D_0035f628 total, D_0035f62c set).
// The unused i++ in the second loop gives it one latch, which matches the original block frequencies.
void Tz__JmComplete__CheckPuzzle(void) {
    Ent* e = 0;
    s32 i = 0;
    Tbl* t = func_00294000(9);
    Rec* r = t->r;
    Flags* f = func_002a9d68();
    while (i < 10) {
        Bits* b = &D_0035f624[i];
        b->w[0] = 0;
        b->w[1] = 0;
        i++;
    }
    for (;; i++) {
        e = func_001d9e30(e);
        if (e == 0) break;
        if (!T1(e->a, e->b)) D_0035f628++;
        S1(e->a, e->b);
        if (func_001d9d48(e)) {
            D_0035f620->x[e->a].Set(e->b);
            if (!TY(e->a, e->b)) D_0035f62c++;
            SY(e->a, e->b);
        }
    }
    for (i = 0; i < t->n; i++, r++) {
        s32 n = func_002b3ac8((s8)(r->b & 15));
        D_0035f628 += n;
        for (s32 j = 0; j < n; j++) {
            if (D_0035f620->x[i].Test(j)) D_0035f62c++;
        }
    }
    for (i = 0; i < t->n; i++) {
        D_0035f628++;
        if (f->hb.Test(i)) {
            D_0035f620->hb.Set(i);
            D_0035f62c++;
        }
    }
}
}  // namespace n002ae320

// 002ae660 (was src/anon/batch_w97.cpp)
namespace n002ae660 {
// ---- 002ae660
struct Ent2ae { u8 f0; u8 f1; u8 pad[14]; };
struct List2ae { u8 pad[8]; s32 count; u8 pad12[4]; Ent2ae ent[1]; };
struct Prog2ae { u8 pad[324]; u32 bits[1][2]; };
extern Prog2ae* D_0035f620 asm("D_0035f620");
List2ae* func_00294000(s32) asm("func_00294000");
s32 func_002b3ac8(s8) asm("func_002b3ac8");
static inline bool testb(u32* p, u32 n) { return p[n >> 5] & (1 << (n & 31)); }
s32 Tz__JmComplete__isPuzzlePieceComp(s32 sel) asm("Tz__JmComplete__isPuzzlePieceComp");
s32 Tz__JmComplete__isPuzzlePieceComp(s32 sel) {
    s32 i = 0;
    s32 ok = 1;
    List2ae* l = func_00294000(9);
    for (Ent2ae* e = l->ent; i < l->count; i++, e++) {
        if (sel >= 0 && sel != i) continue;
        s32 n = func_002b3ac8((s8)(e->f1 & 0xf));
        for (s32 j = 0; j < n; j++) {
            if (!testb(D_0035f620->bits[i], j)) {
                ok = 0;
                break;
            }
        }
        if (!ok) break;
    }
    return ok;
}
}  // namespace n002ae660

// 002ae768 (was src/anon/batch_w1598.cpp)
namespace n002ae768 {
union UN { s32 n; u16 h; };
struct T9 { u8 pad[8]; UN n; };
struct G { u8 pad[484]; u16 bits[1]; };
union UPg { G* p; u16 h; };
G* func_002a9d68(void) asm("func_002a9d68");
T9* func_00294000(s32) asm("func_00294000");
extern UPg D_0035f620 asm("D_0035f620");
static inline u32 bt(u16* b, s32 i) { return b[(u32)i >> 4] & (1 << (i & 15)); }
static inline void bs(u16* b, s32 i) {
    if (!bt(b, i)) b[(u32)i >> 4] |= 1 << (i & 15);
}
s32 Tz__JmComplete__isPuzzleGameComp(s32 a0) asm("Tz__JmComplete__isPuzzleGameComp");
s32 Tz__JmComplete__isPuzzleGameComp(s32 a0) {
    s32 ret = 1;
    G* p = func_002a9d68();
    T9* t = func_00294000(9);
    s32 i;
    for (i = 0; i < t->n.n; i++) {
        if (bt(p->bits, i)) bs(D_0035f620.p->bits, i);
    }
    for (i = 0; i < t->n.n; i++) {
        if (a0 >= 0 && a0 != i) continue;
        if (!bt(D_0035f620.p->bits, i)) {
            ret = 0;
            break;
        }
    }
    return ret;
}
}  // namespace n002ae768

// 002ae890 (was src/tozawa/jm_complete.cpp)
namespace Tz { // method 002ae890
u32 func_001d9e30(u32) asm("func_001d9e30");
// record_range_check_or_first
extern "C" s32 Tz__Jiminy__AreaWorld2JmWorld(u32) asm("Tz__Jiminy__AreaWorld2JmWorld");
u32 func_001d9d48(void*) asm("func_001d9d48");
u32 JmComplete::isPuzzleInfoComp(s32 a0) {
    u32 s0 = 0;
    s32 s1 = a0;
    u32 s2 = 1;

L_loop:
    {
        u32 v0 = func_001d9e30(s0);  // record_range_check_or_first
        if (v0 == 0) {
            goto L_ret;
        }
        s0 = v0;

        v0 = (u32)Tz__Jiminy__AreaWorld2JmWorld(*(u8*)(s0 + 4));
        if (s1 >= 0) {
            if ((u32)s1 != v0) {
                goto L_loop;
            }
        }

        v0 = func_001d9d48((void*)s0);
        if (v0 != 0) {
            goto L_loop;
        }

        s2 = 0;
    }

L_ret:
    return s2;
}
}  // Tz

// 002ae908 (was src/anon/batch_w1946.cpp)
namespace n002ae908 {
s32 func_002ad1b0(s32) asm("func_002ad1b0");
s32 func_002ad338(void) asm("func_002ad338");
s32 Tz__JmComplete__isAlbumComp(void) asm("Tz__JmComplete__isAlbumComp");
s32 func_002ad660(void) asm("func_002ad660");
s32 func_002ad7d0(s32) asm("func_002ad7d0");
s32 func_002ad950(s32) asm("func_002ad950");
s32 Tz__JmComplete__isTreasureComp(s32) asm("Tz__JmComplete__isTreasureComp");
s32 Tz__JmComplete__isNaviComp(s32) asm("Tz__JmComplete__isNaviComp");
s32 func_002adf60(s32) asm("func_002adf60");
s32 func_002ae0c0(s32) asm("func_002ae0c0");
s32 func_002ae1b0(s32, s32) asm("func_002ae1b0");
s32 Tz__JmComplete__isPuzzlePieceComp(s32) asm("Tz__JmComplete__isPuzzlePieceComp");
s32 Tz__JmComplete__isPuzzleGameComp(s32) asm("Tz__JmComplete__isPuzzleGameComp");
s32 func_002ae890(s32) asm("func_002ae890");
static inline __attribute__((always_inline)) s32 h_002ae908(s32 x) {
    if (x == 15) {
        if (!func_002ad1b0(-1)) return 0;
        if (!func_002ad338()) return 0;
        if (!func_002ad660()) return 0;
        if (!func_002ad7d0(-1)) return 0;
        if (!func_002ad950(-1)) return 0;
        if (!Tz__JmComplete__isTreasureComp(-1)) return 0;
        if (!Tz__JmComplete__isNaviComp(-1)) return 0;
        if (!func_002adf60(-1)) return 0;
        if (!Tz__JmComplete__isPuzzlePieceComp(-1)) return 0;
        if (!Tz__JmComplete__isPuzzleGameComp(-1)) return 0;
        if (!func_002ae890(-1)) return 0;
        if (!func_002ae1b0(1, x)) return 0;
    } else {
        if (!Tz__JmComplete__isAlbumComp()) return 0;
        if (!func_002ad7d0(x)) return 0;
        if (!func_002ad950(x)) return 0;
        if (!Tz__JmComplete__isTreasureComp(x)) return 0;
        if (!Tz__JmComplete__isNaviComp(x)) return 0;
        if (!func_002ae0c0(x)) return 0;
        if (!func_002ae1b0(0, x)) return 0;
        if (!func_002ae1b0(1, x)) return 0;
        if (!func_002ae890(x)) return 0;
    }
    return 1;
}
s32 Tz__JmComplete__isWorldComp(s32 x) asm("Tz__JmComplete__isWorldComp");
s32 Tz__JmComplete__isWorldComp(s32 x) {
    return h_002ae908(x);
}
}  // namespace n002ae908

// 002aea98 (was src/anon/batch_w1591_g.cpp)
namespace n002aea98 {
s32 func_00103570() asm("func_00103570");
s32 func_001063c0(s32, s32) asm("func_001063c0");
s32 func_001063f0(s32, s32) asm("func_001063f0");
void sa__MUSICAL_SCORE5__init(s32) asm("sa__MUSICAL_SCORE5__init");
void func_0023f800(s32) asm("func_0023f800");
void Tz__ItemPicDraw__Init() asm("Tz__ItemPicDraw__Init");
void func_002aeb28() asm("func_002aeb28");
extern s32 D_0035f630 asm("D_0035f630");
extern s32 D_0035f634 asm("D_0035f634");
extern s32 D_0035f638 asm("D_0035f638");
void func_002aea98(void) asm("func_002aea98");
void func_002aea98(void) {
    D_0035f630 = func_001063f0(0x168, func_00103570());
    s32 v = func_001063c0(0x6048, func_00103570());
    sa__MUSICAL_SCORE5__init(v);
    D_0035f634 = v;
    s32 w = func_001063c0(0x98, func_00103570());
    func_0023f800(w);
    *(s32*)(w + 0x2c) = 0;
    *(s32*)(w + 0x30) = 0;
    D_0035f638 = w;
    Tz__ItemPicDraw__Init();
    func_002aeb28();
}
}  // namespace n002aea98

