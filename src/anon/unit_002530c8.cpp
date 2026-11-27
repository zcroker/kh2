// Linked unit 0x002530c8-0x00253ba8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/smenu_cana.hpp"
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
#include "../tozawa/campmenu.hpp"
#include "../tozawa/cmenu_data.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 002530c8 (was src/anon/tiny_wrappers_imp.cpp)
namespace n002530c8 {
u32 func_0028d068(u32, u32, u32, u32) asm("_Z13func_0028d068jjjj");
/*TARGET 002530c8*/
u32 func_002530c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002530c8jjjj");
u32 func_002530c8(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_state_30012
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = (u32)((s32)0u + (30012));
    r15 = (u32)(0x0036u << 16);
    *(u32*)((u32)r15 + (s32)(-3116)) = r14;
    r4 = (u32)((s32)0u + (30026));
    r5 = (u32)((s32)0u + (-1));
    return func_0028d068(r4, r5, r6, r7);
}
}  // namespace n002530c8

// 002530f0 (was src/anon/batch_w56.cpp)
namespace n002530f0 {
// 0x00226dc8: definition moved into src/anon/unit_00224780.cpp

// 002530f0
struct Fn253 { u8 pad[8]; void (*fn)(void); };
Fn253* func_00253330(s32) asm("func_00253330");
extern s32 D_0035eeb4 asm("D_0035eeb4");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s16 D_01dae6a8[] asm("D_01dae6a8");
void func_00258dc8(void) asm("func_00258dc8");
void func_0028ca78(void) asm("func_0028ca78");
void func_00287a28(void) asm("func_00287a28");
void func_0028d068(s32, s32) asm("func_0028d068");
void func_00242790(void) asm("func_00242790");
void func_0023d368(void) asm("func_0023d368");
/*TARGET 002530f0*/
void func_002530f0(s32 a) asm("func_002530f0");
void func_002530f0(s32 a)
{
    func_00253330(a)->fn();
    D_0035eeb4 = -1;
    func_00258dc8();
    func_0028ca78();
    func_00287a28();
    D_0035f3d4 = D_01dae6a8[0];
    s32 v = D_01dae6a8[1];
    if (v >= 0) func_0028d068(v, -1);
    if (a != 9) func_00242790();
    func_0023d368();
}
}  // namespace n002530f0

// 00253180 (was src/anon/batch_w287.cpp)
namespace n00253180 {
struct Ent253 { s16 a; s16 id; s32 pad[2]; s32* val; };
extern u8 D_0033cbb0 asm("D_0033cbb0");
void func_00197c90(void) asm("func_00197c90");
Ent253* func_00253330(u32) asm("func_00253330");
s32 func_00103550(void) asm("func_00103550");
s32 func_00103b38(void) asm("func_00103b38");
u8 func_00103428(s32) asm("func_00103428");
s32 func_00103560(void) asm("func_00103560");
void func_00103500(s32) asm("func_00103500");
s32 func_00253380(u32) asm("func_00253380");
void func_00253538(s32) asm("func_00253538");
void func_001037b8(void) asm("func_001037b8");
void wtarget_00253180(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00253180jjjj");
/*TARGET 00253180*/
void wtarget_00253180(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00253180jjjj");
void wtarget_00253180(u32 a0, u32 a1, u32 a2, u32 a3) {
    s32 v1 = a1;
    s32 flag = 0;
    if (D_0033cbb0) return;
    if (a0 == 5) func_00197c90();
    Ent253* e = func_00253330(a0);
    s32 cur = func_00103550();
    if (func_00103b38() || cur != -1) {
        if (func_00103428(cur) && !func_00103428(e->id)) {
            func_00103500(e->id);
        } else if (!func_00103428(e->id)) {
            if (func_00103560() == -1) func_00103500(e->id);
        } else if (func_00103428(cur)) {
            u32 v = func_00103428(e->id);
            if (e->id == 50 && (u8)(v & 1)) func_00103500(e->id);
        }
        flag = 1;
    }
    s32* p = e->val;
    if (p && v1 != -999) {
        if (a0 == 0) {
            if (v1 < 0) v1 = 1;
            *p = v1;
        } else *p = v1;
    }
    if (flag) return;
    if (!func_00253380(a0)) {
        func_00103500(e->id);
        func_001037b8();
        return;
    }
    func_00253538(e->id);
}
}  // namespace n00253180

// 00253330 (was src/anon/batch_w64.cpp)
namespace n00253330 {
// ---------------------------------------------------------------------------
struct Ent253330 { s16 id; u8 pad[14]; };
extern Ent253330 D_003726d0[] asm("D_003726d0");
/*TARGET 00253330*/
// Returns the last table entry with the given id (table ends at a negative id).
Ent253330* func_00253330(s32 key) asm("func_00253330");
// Returns the last table entry with the given id (table ends at a negative id).
Ent253330* func_00253330(s32 key) {
    Ent253330* r = 0;
    for (s32 i = 0; D_003726d0[i].id >= 0; i++)
        if (D_003726d0[i].id == key) r = &D_003726d0[i];
    return r;
}
}  // namespace n00253330

// 00253380 (was src/anon/batch_w27.cpp)
namespace n00253380 {
extern s16 D_003726b8[] asm("D_003726b8");
/*TARGET 00253380*/
s32 func_00253380(s32 x) asm("func_00253380");
s32 func_00253380(s32 x) {
    s32 r = 0;
    for (s32 i = 0; D_003726b8[i] >= 0; i++) {
        if (D_003726b8[i] == x) { r = 1; break; }
    }
    return r;
}
}  // namespace n00253380

// 002533d8 (was unwritten gap: empty function)
namespace n002533d8 {
void func_002533d8(void) asm("func_002533d8");
void func_002533d8(void) {}
}  // namespace n002533d8

// 002533e0 (was src/anon/batch_w8.cpp)
namespace n002533e0 {
void func_0026d808(const void*) asm("func_0026d808");
void func_00253180(u32, s32) asm("func_00253180");
void camp_start_party(s32 a, const void* b) asm("_ZN2Tz8CampMenu10StartPartyEiPKv");
/*TARGET 002533e0*/
void camp_start_party(s32 a, const void* b) asm("_ZN2Tz8CampMenu10StartPartyEiPKv");
void camp_start_party(s32 a, const void* b) {
    func_0026d808(b);
    func_00253180(6, a);
}
}  // namespace n002533e0

// 00253410 (was src/anon/batch_w48.cpp)
namespace n00253410 {
struct Obj253410 { u8 pad[37]; u8 active : 1; };
u8* func_0014aba8(void) asm("func_0014aba8");
void func_00258b00(void*, s32) asm("func_00258b00");
void* func_002535d0(s32) asm("func_002535d0");
void func_00242740(void*) asm("func_00242740");
void func_00253180(s32, s32) asm("func_00253180");
static inline u8 isOff253410(Obj253410* o) { return !o->active; }
/*TARGET 00253410*/
void func_00253410(Obj253410* o, s32 a1) asm("func_00253410");
void func_00253410(Obj253410* o, s32 a1) {
    if (!isOff253410(o)) *(u32*)(func_0014aba8() + 252) = 0;
    func_00258b00(o, a1);
    func_00242740(func_002535d0(8));
    func_00253180(8, -1);
}
}  // namespace n00253410

// 00253480 (was src/anon/batch_w4.cpp)
namespace n00253480 {
extern "C" void func_00258b00(void) asm("func_00258b00");
void func_00258af0(s32) asm("func_00258af0");
/*TARGET 00253480*/
void CampMenu_RestartSelector(void*, const void*, const void*) asm("_ZN2Tz8CampMenu15RestartSelectorEPKN2YS8SELECTOREPKNS2_4ARGSE");
void CampMenu_RestartSelector(void*, const void*, const void*) {
    func_00258b00();
    func_00258af0(9);
}
}  // namespace n00253480

// 002534a0 (was src/tozawa/campmenu.cpp)
namespace Tz { // method 002534a0
u32 func_00253180(...) asm("func_00253180");
u32 func_00274f98(...) asm("func_00274f98");
/*TARGET 002534a0*/
u32 CampMenu::StartJiminy(s32 a0, s32 a1) {
    u32 r4 = (u32)a0, r5 = (u32)a1, r2, r15, r16;
    r15 = (u32)((s32)0u + (1));
    r16 = r4;
    r4 = r5;
    if (r16 != r15) {
        r2 = ((u32(*)(u32,u32))func_00274f98)(r4, r5);
    }
    r5 = r16;
    r4 = (u32)((s32)0u + (4));
    return ((u32(*)(u32,u32))func_00253180)(r4, r5);
}
}  // Tz

// 002534e0 (was src/anon/batch_w1580_g.cpp)
namespace n002534e0 {
s32 func_00103550(void) asm("func_00103550");
s32 func_00103b38(void) asm("func_00103b38");
void func_00253180(s32, s32) asm("func_00253180");
void func_0027dc08(void) asm("func_0027dc08");
/*TARGET 002534e0*/
void func_002534e0(void) asm("func_002534e0");
void func_002534e0(void) {
    s32 s;
    func_0027dc08();
    s = func_00103550();
    if (func_00103b38() == 0 || s != 50) {
        func_00253180(14, -1);
    }
}
}  // namespace n002534e0

// 00253538 (was src/anon/batch_w10.cpp)
namespace n00253538 {
void func_00288648(void) asm("func_00288648");
s16* func_00253330(s32) asm("func_00253330");
void func_00103500(s32) asm("func_00103500");
void func_001037b8(void) asm("func_001037b8");
void CampMenu_StartBasic(s32) asm("_ZN2Tz8CampMenu10StartBasicEi");
/*TARGET 00253538*/
void CampMenu_StartBasic(s32) asm("_ZN2Tz8CampMenu10StartBasicEi");
void CampMenu_StartBasic(s32) {
    func_00288648();
    func_00103500(func_00253330(10)[1]);
    func_001037b8();
}
}  // namespace n00253538

// 00253568 (was src/anon/batch_w1665.cpp)
namespace n00253568 {
extern u32 D_0035eeb0 asm("D_0035eeb0");
/*TARGET 00253568*/
// 0x0018c240: definition moved into src/yasui/libys/npc.cpp
void func_00253568(u32 a) asm("func_00253568");
// 0x0018c240: definition moved into src/yasui/libys/npc.cpp
void func_00253568(u32 a) { D_0035eeb0 = a; }
}  // namespace n00253568

// 00253578 (was src/anon/tiny.cpp)
namespace n00253578 {
/*TARGET 00253578*/
// 0x002431c0: definition moved into src/anon/unit_00242478.cpp

u32 func_00253578(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00253578jjjj");
// 0x002431c0: definition moved into src/anon/unit_00242478.cpp

u32 func_00253578(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36ee90
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-4432)));
}
}  // namespace n00253578

// 00253588 (was unwritten gap: getter)
namespace n00253588 {
extern s32 D_0035eeb4 asm("D_0035eeb4");
s32 func_00253588(void) asm("func_00253588");
s32 func_00253588(void) { return D_0035eeb4; }
}  // namespace n00253588

// 00253598 (was src/anon/tiny_more2.cpp)
namespace n00253598 {
extern u32 D_0035eeb8 asm("D_0035eeb8");
/*TARGET 00253598*/
u32 func_00253598(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00253598jjjj");
u32 func_00253598(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v=D_0035eeb8; v ^= 0x1u; return (v < 1u); }
}  // namespace n00253598

// 002535b0 (was src/tozawa/campmenu.cpp)
namespace Tz { // method 002535b0
/*TARGET 002535b0*/
void CampMenu::SetJmStartMenu(s32 menu) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-4420)) = (u32)menu;
}
}  // Tz

// 002535c0 (was src/anon/batch_w1666.cpp)
namespace n002535c0 {
extern s32 D_0035eebc asm("D_0035eebc");
/*TARGET 002535c0*/
s32 func_002535c0(void) asm("func_002535c0");
s32 func_002535c0(void) { return D_0035eebc; }
}  // namespace n002535c0

// 002535d0 (was src/anon/batch_w46.cpp)
namespace n002535d0 {
// ---- 002535d0
extern s8 D_003726c8[] asm("D_003726c8");
s32 func_00102fa0(void) asm("func_00102fa0");
/*TARGET 002535d0*/
s32 func_002535d0(s32 a) asm("func_002535d0");
s32 func_002535d0(s32 a) {
    s32 r = -1;
    for (s32 i = 0; D_003726c8[i] >= 0; i++) {
        if (a == D_003726c8[i]) { r = 2; break; }
    }
    if (func_00102fa0()) r = 2;
    return r;
}
}  // namespace n002535d0

// 00253638 (was src/anon/batch_w3739.cpp)
namespace n00253638 {
struct Ent { s32 idx; s32 one; s32 v; u8* p; };
extern Ent D_0035eee0[7] asm("D_0035eee0");
extern s32 D_0035ef50 asm("D_0035ef50");
extern s32 D_0035ef54 asm("D_0035ef54");
extern u8 D_0035ef58 asm("D_0035ef58");
extern u8 D_01dae6c0[] asm("D_01dae6c0");
extern s32 D_0035eec0[] asm("D_0035eec0");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 strlen(s32) asm("strlen");
char* func_00253b30(char*, s32) asm("func_00253b30");
s32 func_00168328(char*, u8*) asm("func_00168328");
s32 func_00253948(s32) asm("func_00253948");
s32 func_001688b8(void) asm("func_001688b8");
/*TARGET 00253638*/
// Loads up to two entries (handles from D_0035eec0) into the D_01dae6c0 buffer and records them.
// The empty asm (no code) keeps total's add after dst's (sched2 order).
void func_00253638(void) asm("func_00253638");
// Loads up to two entries (handles from D_0035eec0) into the D_01dae6c0 buffer and records them.
// The empty asm (no code) keeps total's add after dst's (sched2 order).
void func_00253638(void) {
    char buf[128];
    s32 total = 0;
    func_002fde18(D_0035eee0, 0, 0x70);
    D_0035ef50 = 0;
    D_0035ef54 = 0;
    u8* dst = D_01dae6c0;
    s32 i;
    for (i = 0; i < 2; i++) {
        s32 h = D_0035eec0[i];
        if (h != 0 && strlen(h) != 0) {
            Ent* e = &D_0035eee0[i];
            s32 v = func_00168328(func_00253b30(buf, h), dst);
            e->p = dst;
            e->idx = i;
            e->one = 1;
            e->v = v;
            s32 n = func_00253948(v);
            dst += n; asm("" : "+r"(n) : "r"(dst)); total += n;
        }
    }
    D_0035ef50 = total;
    D_0035ef54 = 2;
    if (D_0035ef58 != 0 && func_001688b8() == 0) {
        D_0035ef58 = 0;
    }
}
}  // namespace n00253638

// 00253768 (was src/tozawa/cmenu_data.cpp)
namespace Tz { // method 00253768
extern u8 D_0035ef58 asm("D_0035ef58");
extern u8 D_0035eee0 asm("D_0035eee0");
extern u32 D_0035ef50 asm("D_0035ef50");
extern u32 D_0035ef54 asm("D_0035ef54");
u32 func_001688b8(...) asm("func_001688b8");
void func_002fde18(...) asm("func_002fde18");
/*TARGET 00253768*/
void CMData::Exit() {
    func_002fde18((void*)&D_0035eee0, 0, 112);
    D_0035ef50 = 0;
    D_0035ef54 = 0;
    if (D_0035ef58 != 0) {
        if (func_001688b8() == 0) {
            D_0035ef58 = 0;
        }
    }
}
}  // Tz

// 002537c8 (was src/anon/tiny_more3.cpp)
namespace n002537c8 {
extern u32 D_0035eee0 asm("D_0035eee0");
/*TARGET 002537c8*/
// 0x0011ee98: definition moved into src/anon/unit_0011c128.cpp

// 00136b90: moved to src/harata/libdk/bgm.cpp

u32 func_002537c8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_002537c8jjjj");
// 0x0011ee98: definition moved into src/anon/unit_0011c128.cpp

// 00136b90: moved to src/harata/libdk/bgm.cpp

u32 func_002537c8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p=(u32)&D_0035eee0 + ((u32)a0 << 4); return *(u32*)((u32)p + (12)); }
}  // namespace n002537c8

// 002537e0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002537e0 {
void func_00253888(...) asm("func_00253888");
extern u8 D_0035eee0 asm("D_0035eee0");
/*TARGET 002537e0*/
void func_002537e0(u32 a0) asm("_Z13func_002537e0j");
void func_002537e0(u32 a0) {
    a0 <<= 4;
    u32 t7 = a0 + (u32)&D_0035eee0;
    u32 t6 = *(u32*)(t7 + 12);
    if (t6 != 0) {
        func_00253888(*(u32*)(t7 + 0));
    }
}
}  // namespace n002537e0

// 00253818 (was src/anon/auto80_199_queue.cpp)
namespace n00253818 {
/*TARGET 00253818*/
void func_00253818(s32 a0) asm("_Z13func_00253818i");
void func_00253818(s32 a0) {  // entry16_find_free
    s32 s0 = 1;
    u8* t7 = &D_0035eee0;
    Entry00253818* s1 = (Entry00253818*)(t7 + 16);
    s32 s2 = a0;

    while (1) {
        if (s0 != s2) {
            if (s1->a3 != 0) {
                func_00253888(s1->a0);
            }
        }

        s0 = s0 + 1;
        if (s0 < 7) {
            s1 = s1 + 1;
            continue;
        }
        break;
    }
}
}  // namespace n00253818

// 00253888 (was src/anon/batch_w48.cpp)
namespace n00253888 {
struct E2538 { s32 a; s32 b; s32 c; u8* d; };
extern E2538 D_0035eee0[7] asm("D_0035eee0");
extern u8 D_01dae6c0[] asm("D_01dae6c0");
extern s32 D_0035ef50 asm("D_0035ef50");
extern s32 D_0035ef54 asm("D_0035ef54");
/*TARGET 00253888*/
void func_00253888(s32 a) asm("func_00253888");
void func_00253888(s32 a) {
    u8* base = D_01dae6c0;
    E2538* e = D_0035eee0;
    s32 r = 0;
    for (s32 i = 6; i >= 0; i--, e++) {
        if (e->d) {
            if (!(e->a < a)) {
                if (e->a == a) r = e->d - base;
                e->a = 0;
                e->b = 0;
                e->d = 0;
                e->c = 0;
            }
        }
    }
    D_0035ef50 = r;
    D_0035ef54 = a;
}
}  // namespace n00253888

// 002538f8 (was src/anon/auto200_999.cpp)
namespace n002538f8 {
extern u8 D_0035eee0 asm("D_0035eee0");
/*TARGET 002538f8*/
// 0x00232718: definition moved into src/anon/unit_00231500.cpp

u32 func_002538f8(u32 a0) asm("_Z13func_002538f8j");
// 0x00232718: definition moved into src/anon/unit_00231500.cpp

u32 func_002538f8(u32 a0) {  // entry16_get_flag_bit
    u32 base = (u32)&D_0035eee0;
    a0 <<= 4;
    a0 += base;
    u32 v = *(u32 *)(a0 + 4);
    v &= 1;
    asm volatile("" : "+r"(v));
    return v & 0xff;
}
}  // namespace n002538f8

// 00253918 (was src/tozawa/cmenu_data.cpp)
namespace Tz { // method 00253918
extern u8 D_0035ef58 asm("D_0035ef58");
/*TARGET 00253918*/
u32 CMData::isBackRead() {
    (void)D_0035ef58;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-4264)));
}
}  // Tz

// 00253928 (was src/anon/tiny_auto80_solver.cpp)
namespace n00253928 {
extern u8 D_0035eee0 asm("D_0035eee0");
/*TARGET 00253928*/
u32 func_00253928(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00253928jjjjjjjj");
u32 func_00253928(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // entry16_get_bit1
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)&D_0035eee0;
    r4 = (u32)(r4 << 4);    r4 = (u32)(r4 + r15);
    r2 = *(u32*)((u32)r4 + (s32)(4));
    r2 = (u32)((s32)r2 >> 1);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // namespace n00253928

// 00253948 (was src/anon/batch_w23.cpp)
namespace n00253948 {
/*TARGET 00253948*/
// Round up to a multiple of 64
s32 func_00253948(s32 x) asm("func_00253948");
// Round up to a multiple of 64
s32 func_00253948(s32 x) {
    if (x & 63) x = x / 64 * 64 + 64;
    return x;
}
}  // namespace n00253948

// 00253978 (was src/anon/auto80_199_queue.cpp)
namespace n00253978 {
/*TARGET 00253978*/
void func_00253978(u32 a0, u32 a1, Entry00253978* a2) asm("_Z13func_00253978jjP13Entry00253978");
void func_00253978(u32 a0, u32 a1, Entry00253978* a2) {
    (void)a0;

    if (a2 != 0) {
        if (a2->v12 != 0) {
            a2->v8 = a1;
            a2->v4 = 1;
            u32* s0 = &D_0035ef50;
            u32 v0 = func_00253948(a1);
            *s0 = *s0 + v0;
        }
    }

    D_0035ef58 = 0;
}
}  // namespace n00253978

// 002539d0 (was src/anon/tiny.cpp)
namespace n002539d0 {
void func_00253978(void*) asm("_Z13func_00253978Pv");
/*TARGET 002539d0*/
void func_002539d0(BD_VALUE* bd) asm("_Z13func_002539d0P8BD_VALUE");
void func_002539d0(BD_VALUE* bd) { func_00253978(bd); }
}  // namespace n002539d0

// 002539e8 (was src/anon/batch_w3769.cpp)
namespace n002539e8 {
struct Slot { s32 id; s32 st; s32 c; s32 d; };
extern u8 D_0035ef58 asm("D_0035ef58");
extern u32 D_0035eec0[] asm("D_0035eec0");
extern Slot D_0035eee0[] asm("D_0035eee0");
extern s32 D_0035ef54 asm("D_0035ef54");
u8* func_00253b30(u8*, u32) asm("func_00253b30");
void func_002ff2e8(u8*) asm("func_002ff2e8");
s32 func_00253b00() asm("func_00253b00");
void func_00253978(void*) asm("func_00253978");
void func_002539d0(void*) asm("func_002539d0");
void func_001684c0(u8*, s32, void (*)(void*), Slot*) asm("func_001684c0");
void func_00168388(u8*, s32, void (*)(void*), Slot*) asm("func_00168388");
/*TARGET 002539e8*/
// Starts slot idx's request (idx 6 fills buf itself): records a ticket, sets state 2 and
// queues it with a completion callback.
// key is pinned to s2 (both buffer results share it); the empty asm keeps a label at the
// start of the non-6 arm, so the first beq's delay slot is filled from its target as in the original.
s32 func_002539e8(s32 idx0, u32 key0) asm("func_002539e8");
// Starts slot idx's request (idx 6 fills buf itself): records a ticket, sets state 2 and
// queues it with a completion callback.
// key is pinned to s2 (both buffer results share it); the empty asm keeps a label at the
// start of the non-6 arm, so the first beq's delay slot is filled from its target as in the original.
s32 func_002539e8(s32 idx0, u32 key0)
{
    u8 buf[128];
    s32 idx = idx0;
    if (D_0035ef58) return -1;
    register u32 key asm("$18") = key0;
    if (!key) key = D_0035eec0[idx];
    if (idx != 6) {
        lab: asm("" :: "X"(&&lab));
        key = (u32)func_00253b30(buf, key);
    } else {
        func_002ff2e8(buf);
        key = (u32)buf;
    }
    Slot* s = &D_0035eee0[idx];
    s->id = D_0035ef54++;
    s->st = 2;
    s->d = func_00253b00();
    s->c = 0;
    if (idx != 6) {
        func_001684c0((u8*)key, s->d, func_00253978, s);
    } else {
        Slot* q = &D_0035eee0[6]; func_00168388((u8*)key, q->d, func_002539d0, q);
    }
    D_0035ef58 = 1;
    return 0;
}
}  // namespace n002539e8

// 00253b00 (was src/anon/tiny_auto80_solver.cpp)
namespace n00253b00 {
extern u8 D_01dae6c0 asm("D_01dae6c0");
/*TARGET 00253b00*/
u32 func_00253b00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00253b00jjjjjjjj");
u32 func_00253b00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // get_global_ptr_1dae6c0
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r15 = (u32)(0x0036u << 16);
    r14 = (u32)&D_01dae6c0;
    r2 = *(u32*)((u32)r15 + (s32)(-4272));    r2 = (u32)(r2 + r14);
    return r2;
}
}  // namespace n00253b00

// 00253b18 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00253b18 {
/*TARGET 00253b18*/
u32 func_00253b18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00253b18jjjj");
u32 func_00253b18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = (u32)(0x0036u << 16);
    r2 = (u32)(0x0007u << 16);
    r14 = *(u32*)((u32)r15 + (s32)(-4272));
    r2 = (u32)(r2 | 0x3800u);
    r2 = (u32)(r2 - r14);
    return r2;
}
}  // namespace n00253b18

// 00253b30 (was src/anon/auto80_199_queue.cpp)
namespace n00253b30 {
/*TARGET 00253b30*/
u32 func_00253b30(u32 a0, u32 a1) asm("_Z13func_00253b30jj");
u32 func_00253b30(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;

    if (strcmp(D_0035eed4) == 0) {  // strcmp
        func_002fee78(s0, &D_00372858, D_0033caf4, s1);
        return s0;
    }

    func_002fee78(s0, &D_00372868, D_0033caf0, s1);
    return s0;
}
}  // namespace n00253b30

