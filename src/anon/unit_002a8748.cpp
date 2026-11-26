// Linked unit 0x002a8748-0x002a8ac8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 002a8748 (was src/anon/tiny_wrappers_more.cpp)
namespace n002a8748 {
u32 func_00276c50(u32, u32, u32, u32) asm("_Z13func_00276c50jjjj");
/*TARGET 002a8748*/
u32 func_002a8748(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002a8748jjjj");
u32 func_002a8748(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00276c50(0x000048f7u, 0x00000000u, a2, a3);
}
}  // namespace n002a8748

// 002a8768 (was src/anon/batch_w3761_nsr.cpp)
namespace n002a8768 {
struct Ent { s16 a; s16 b; };
struct Tbl { s32 n; Ent e[1]; };
struct Item { u8 pad[6]; u16 k; };
extern Tbl* D_0035f600 asm("D_0035f600");
extern s32 D_0035f200 asm("D_0035f200");
u8* func_002a9d68() asm("func_002a9d68");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_0028b038(s32) asm("func_0028b038");
Item* func_002a7f20(s32) asm("func_002a7f20");
u8* func_001d56c8(u32) asm("func_001d56c8");
void func_002ab258(s32) asm("func_002ab258");
/*TARGET 002a8768*/
// Built with -fno-strength-reduce (_nsr).
void Tz__JmMiniGame__UpdateNewMark(void) asm("Tz__JmMiniGame__UpdateNewMark");
// Built with -fno-strength-reduce (_nsr).
void Tz__JmMiniGame__UpdateNewMark(void) {
    s32 i = 0;
    u8* w = func_002a9d68();
    func_00287bc0();
    s32 base = func_0028b038(D_0035f200);
    s32 n = D_0035f600->n;
    if (n > 10) n = 10;
    if (n > 0) {
        do {
            s32 id = D_0035f600->e[base + i].b;
            i++;
            if (id >= 0 && *func_001d56c8(func_002a7f20(id)->k) != 0) {
                u32* bits = (u32*)(w + 136);
                if (!(bits[(u32)id >> 5] & (1 << (id & 31)))) {
                    func_002ab258(id);
                }
            }
        } while (i < n);
    }
}
}  // namespace n002a8768

// 002a8870 (was src/anon/batch_w66.cpp)
namespace n002a8870 {
// ---- 002a8870
struct E2a8 { u16 h0; u16 h2; u16 h4; u16 h6; };
struct T2a8 { u32 pad[2]; s32 n; u32 pad2; E2a8 e[1]; };
T2a8* func_00294000(s32) asm("func_00294000");
u8* func_001d56c8(u16) asm("func_001d56c8");
s32 func_00276c18(void) asm("func_00276c18");
static inline s32 ok2(u8* v) { return *v < 2; }
static inline s32 bad2(u8* v) { return ok2(v) ^ 1; }
/*TARGET 002a8870*/
s32 Tz__JmMiniGame__isEnable(s32 a) asm("Tz__JmMiniGame__isEnable");
s32 Tz__JmMiniGame__isEnable(s32 a) {
    T2a8* t = func_00294000(7);
    E2a8* e = t->e;
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (a >= 0 && e[i].h0 != a) continue;
        if (bad2(func_001d56c8(e[i].h6))) break;
        if (func_00276c18()) break;
    }
    return i < t->n;
}
}  // namespace n002a8870

// 002a8920 (was src/anon/batch_w10.cpp)
namespace n002a8920 {
u8* func_001d56c8(void) asm("func_001d56c8");
/*TARGET 002a8920*/
// 0x00299260: definition moved into src/anon/unit_002982f0.cpp

bool Tz__JmMiniGame__isPlay(void) asm("Tz__JmMiniGame__isPlay");
// 0x00299260: definition moved into src/anon/unit_002982f0.cpp

bool Tz__JmMiniGame__isPlay(void) {
    return *func_001d56c8() >= 2;
}
}  // namespace n002a8920

// 002a8948 (was src/anon/batch_w67.cpp)
namespace n002a8948 {
// 0x00272340: definition moved into src/anon/unit_00271e08.cpp

s32 func_00103570(void) asm("func_00103570");
u8* func_001063c0(s32, s32) asm("func_001063c0");
void func_00239700(u8*) asm("func_00239700");
extern u8* D_0035f608 asm("D_0035f608");
extern u8* D_0035f60c asm("D_0035f60c");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
/*TARGET 002a8948*/
// 002a8948: allocate the work buffers (ten 436-byte objects)
void Tz__JmQuest__Init(void) asm("Tz__JmQuest__Init");
// 002a8948: allocate the work buffers (ten 436-byte objects)
void Tz__JmQuest__Init(void)
{
    D_0035f608 = func_001063c0(772, func_00103570());
    u8* arr = func_001063c0(4360, func_00103570());
    u8* p = arr;
    s32 i = 9;
    do {
        *(u32*)(p + 12) = 0;
        *(u8**)p = D_00347e60;
        func_00239700(p + 24);
        *(u8**)p = D_00347e40;
        *(u32*)(p + 408) = 0;
        p += 436;
    } while (--i != -1);
    D_0035f60c = arr;
}
}  // namespace n002a8948

// 002a8a00 (was src/anon/auto80_199_queue.cpp)
namespace n002a8a00 {
/*TARGET 002a8a00*/
void func_002a8a00(void) asm("_Z13func_002a8a00v");
void func_002a8a00(void) {
    u32 s0;
    u32 s1;

    if (D_0035f608 != 0) {
        func_00106420(D_0035f608);
        D_0035f608 = 0;
    }

    s1 = (u32)D_0035f60c;
    if (s1 == 0) {
        return;
    }

    s0 = s1 + 4360;
L_loop:
    if (s1 == s0) {
        goto L_done;
    }
    s0 = s0 - 436;

    {
        u32 t6 = *(u32*)s0;
        u32 t7 = *(u32*)(t6 + 12);
        ((void (*)(u32))t7)(s0);
    }
    goto L_loop;

L_done:
    func_00106420((void*)s1);
    D_0035f60c = 0;
}
}  // namespace n002a8a00

// 002a8a80 (was src/anon/misc_2.cpp)
namespace n002a8a80 {
/*TARGET 002a8a80*/
void func_002a8a80(void* self) asm("_Z13func_002a8a80Pv");
void func_002a8a80(void* self) {}
}  // namespace n002a8a80

// 002a8a88 (was src/anon/tiny_auto80_queue.cpp)
namespace n002a8a88 {
void func_002a94f8(...) asm("func_002a94f8");
u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 002a8a88*/
void Tz__JmQuest__LeaveAll() asm("_Z21Tz__JmQuest__LeaveAllv");
void Tz__JmQuest__LeaveAll() {
    u32 v0 = func_00287bc0();
    if (v0 == 10 || v0 == 35) {
        func_002a94f8();
        func_00274ac8();
    }
}
}  // namespace n002a8a88

