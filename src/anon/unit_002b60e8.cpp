// Linked unit (see linked_units.tsv); one namespace per old matched source.
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include <stdarg.h>

// 002b60e8 (was src/anon/tiny_auto80_solver.cpp)
namespace n002b60e8 {
extern u32 D_0035f660 asm("D_0035f660");
/*TARGET 002b60e8*/
void func_002b60e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002b60e8jjjjjjjj");
void func_002b60e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // slot8_store_pair
    u32 off = ((a0 << 2) + a0 + a1) << 3;
    u32 base = *(u32*)&D_0035f660;
    *(u32*)(off + base) = a2;
    u32 base2 = *(u32*)&D_0035f660;
    *(u32*)(off + base2 + 4) = a3;
}
}  // namespace n002b60e8

// 002b6118 (was src/anon/tiny_auto80_solver.cpp)
namespace n002b6118 {
extern u8 D_00374d30 asm("D_00374d30");
/*TARGET 002b6118*/
u32 func_002b6118(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002b6118jjjjjjjj");
u32 func_002b6118(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // entry_ptr_12
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = (u32)((s32)0u + (12));
    r4 = (u32)(r4 * r14);
    r15 = (u32)&D_00374d30;
    r4 = (u32)(r4 + r15);
    r2 = r4;
    return r2;
}
}  // namespace n002b6118

// 002b6138 (was src/anon/batch_w79.cpp)
namespace n002b6138 {
struct Ent8 { u32 id; u32 v; };
struct Rec40 { struct Ent8 e[5]; };
extern s32 D_0035f680[] asm("D_0035f680");
extern struct Rec40* D_0035f660 asm("D_0035f660");
u32* func_002b6118(u32) asm("func_002b6118");
void YS__MESSAGEDRAW__MESSAGEDRAW(void*, s32, u32, s32, u32) asm("YS__MESSAGEDRAW__MESSAGEDRAW");
void YS__MESSAGEDRAW__draw(void*, s32, s32, s32) asm("YS__MESSAGEDRAW__draw");
/*TARGET 002b6138*/
// 0022c108: moved to src/sasa/event_countdown.cpp (linked unit)

void func_002b6138(s32 x, s32 y, s32 a2, s32 a3, s32 key) asm("func_002b6138");
// 0022c108: moved to src/sasa/event_countdown.cpp (linked unit)

void func_002b6138(s32 x, s32 y, s32 a2, s32 a3, s32 key) {
    u8 buf[96];
    s32 i;
    s32 n = -1;
    struct Ent8* e;
    for (i = 0; i < 4; i++) {
        if (D_0035f680[i] == key) {
            n = i;
            break;
        }
    }
    e = D_0035f660[n].e;
    for (i = 0; i < 5; i++, e++) {
        u32* s;
        if (e->v == 0) break;
        s = func_002b6118(e->id);
        YS__MESSAGEDRAW__MESSAGEDRAW(buf, 1, e->v, 14, s[2]);
        YS__MESSAGEDRAW__draw(buf, s[0] + x, s[1] + y, a3);
    }
}
}  // namespace n002b6138

// 002b6238 (gap function, never written before)
namespace n002b6238 {
s32 func_002538f8(s32) asm("func_002538f8");
s32 func_00253928(s32) asm("func_00253928");
s32 func_00253918(void) asm("_ZN2Tz6CMData10isBackReadEv");
s32 Tz__CMData__BackRead(s32, s32) asm("Tz__CMData__BackRead");
s32 func_002b6238(void) asm("func_002b6238");
s32 func_002b6238(void)
{
    s32 r;
    if (func_002538f8(1)) r = 1;
    else if (func_00253928(1)) r = 1;
    else if (func_00253918()) r = 0;
    else r = Tz__CMData__BackRead(1, 0) == 0;
    return r;
}
}  // namespace n002b6238

// 002b6298 (was src/anon/batch_w231.cpp)
namespace n002b6298 {
// 0x001e23b0: definition moved into src/anon/unit_001e0cb8.cpp

s32 func_002538f8(s32) asm("func_002538f8");
// entry16_get_flag_bit
s32 func_00253928(s32) asm("func_00253928");
// entry16_get_bit1
s32 func_00253918(void) asm("func_00253918");
s32 Tz__CMData__BackRead(s32, s32) asm("Tz__CMData__BackRead");
void func_00102448(u32, s32) asm("func_00102448");
/*TARGET 002b6298*/
s32 func_002b6298(u32 a) asm("func_002b6298");
s32 func_002b6298(u32 a) {
    if (func_002538f8(1)) return 1;
    if (!func_00253928(1)) {  // entry16_get_bit1
        for (;;) {
            if (!func_00253918() && !Tz__CMData__BackRead(1, 0)) break;
            func_00102448(a, 0);
        }
    }
    for (;;) {
        if (func_002538f8(1)) break;
        func_00102448(a, 0);
    }
    return 1;
}
}  // namespace n002b6298

// 002b6338 (was src/anon/batch_w36.cpp)
namespace n002b6338 {
u32 func_00192048(u32) asm("func_00192048");
void func_00192e50(u32, u32, u32, u32) asm("func_00192e50");
/*TARGET 002b6338*/
// 0x002b1660: definition moved into src/anon/unit_002b0950.cpp

void func_002b6338(u32 a, u32 b, u32 c, u32 d) asm("func_002b6338");
// 0x002b1660: definition moved into src/anon/unit_002b0950.cpp

void func_002b6338(u32 a, u32 b, u32 c, u32 d) {  // hash_with_seed_choice
    u32 id = !d ? 0xb7d4 : 0xb7d5;
    u32 x = func_00192048(c);
    func_00192e50(x, a, b, func_00192048(id));
}
}  // namespace n002b6338

// 002b63a8 (was src/tozawa/cmenu_slbase.cpp)
namespace n002b63a8 {
u32 func_00103570(...) asm("func_00103570");
void* func_001063c0(u32, u32) asm("func_001063c0");
void func_0028b788(void*) asm("func_0028b788");
u32 func_002537c8(u32) asm("func_002537c8");
void func_0023fa08(void*, u32) asm("func_0023fa08");
void func_0028b8e0(void*, u32) asm("func_0028b8e0");
extern void* D_0035f674 asm("D_0035f674");
extern u8 D_0035f3a8 asm("D_0035f3a8");
/*TARGET 002b63a8*/
void CmSLBase_SetLeadData() asm("_ZN2Tz8CmSLBase11SetLeadDataEv");
void CmSLBase_SetLeadData() {
    u32 v0 = func_00103570();
    void* s0 = func_001063c0(36, v0);
    func_0028b788(s0);
    D_0035f674 = s0;

    u32 s0i = func_002537c8(1);
    func_0023fa08(&D_0035f3a8, s0i);
    func_0028b8e0(D_0035f674, s0i);
}
}  // namespace n002b63a8

// 002b6418 (was src/anon/batch_w66.cpp)
namespace n002b6418 {
// 0022cae8: moved to src/sasa/event_layout.cpp (linked unit)
// ---- 00249098 / 002b6418
s32 func_002892f8(u32) asm("func_002892f8");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_00288e88(u32) asm("func_00288e88");
// 0x00249098: definition moved into src/anon/unit_00247ff0.cpp
extern u32 D_0035f64c asm("D_0035f64c");
extern u32 D_0035f650 asm("D_0035f650");
/*TARGET 002b6418*/
void func_002b6418(void) asm("func_002b6418");
void func_002b6418(void) {
    if (D_0035f64c) {
        s32 s = func_002892f8(D_0035f64c);
        if (!func_0028acc8(D_0035f64c) && s) func_00288e88(D_0035f64c);
    }
    if (D_0035f650) {
        s32 s = func_002892f8(D_0035f650);
        if (!func_0028acc8(D_0035f650) && s) func_00288e88(D_0035f650);
    }
}
}  // namespace n002b6418

// 002b64c8 (was src/tozawa/synthe_data.cpp)
namespace n002b64c8 {
/*TARGET 002b64c8*/
u32 SyntheData_GetMixDataFname() asm("_ZN2Tz10SyntheData15GetMixDataFnameEv");
u32 SyntheData_GetMixDataFname() {
    u32 b = (0x0036u << 16);
    return *(u32*)((u32)b + (-2344));
}
}  // namespace n002b64c8

// 002b64d8 (was src/tozawa/synthe_data.cpp)
namespace n002b64d8 {
void func_00290940(void*) asm("func_00290940");
void func_00253b30(u32, u32) asm("func_00253b30");
void Tz__MenuFile__alloc(u32, u32, u32) asm("Tz__MenuFile__alloc");
extern void* D_0035f6dc asm("D_0035f6dc");
extern u8* D_0035f6d8 asm("D_0035f6d8");
/*TARGET 002b64d8*/
void SyntheData_LeadData(void* a0) asm("_ZN2Tz10SyntheData8LeadDataEPNS_8MenuFileE");
void SyntheData_LeadData(void* a0) {
    u8 buf[256];

    void* s0 = a0;
    if (s0 == 0) {
        s0 = D_0035f6dc;
    }

    func_00290940(s0);
    func_00253b30((u32)buf, (u32)D_0035f6d8);
    Tz__MenuFile__alloc((u32)s0, (u32)buf, 45);
}
}  // namespace n002b64d8

// 002b6530 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002b6530 {
u32 func_00290a60(u32, u32, u32, u32) asm("_Z13func_00290a60jjjj");
/*TARGET 002b6530*/
// 0x00150bc0: definition moved into src/anon/unit_0014ecb8.cpp

// 00158250: moved to src/anon/unit_00158050.cpp
u32 func_002b6530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002b6530jjjj");
// 0x00150bc0: definition moved into src/anon/unit_0014ecb8.cpp

// 00158250: moved to src/anon/unit_00158050.cpp
u32 func_002b6530(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    if (r4 == 0u) {
        r15 = (u32)(0x0036u << 16);
        r4 = *(u32*)((u32)r15 + (s32)(-2340));
    }
    return func_00290a60(r4, r5, r6, r7);
}
}  // namespace n002b6530

