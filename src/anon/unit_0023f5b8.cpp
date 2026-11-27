// Linked unit 0x0023f5b8-0x00241c40: Tz::LayMsg, Tz::LayFile, Tz::MCard (gap functions written here).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../ishi/sequence.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_obj.hpp"
#include "../tozawa/layout.hpp"
#include "../tozawa/laymsg.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/mcard.hpp"

// 0023f5b8 (was src/anon/batch_w3699.cpp)
namespace n0023f5b8 {
s32 func_00139d78(void*) asm("func_00139d78");
u32 func_00192048(s32) asm("func_00192048");
struct O24 { u8 pad[0x20]; u32 v; s32 id;
  void set(s32 n) { if (n >= 0 && n != id) { u32 r = func_00192048(n); id = n; v = r; } }
};
void func_0023f5b8(O24* o, s32 id) asm("_Z13func_0023f5b8i");
/*TARGET 0023f5b8*/
void func_0023f5b8(O24* o, s32 id) asm("_Z13func_0023f5b8i");
void func_0023f5b8(O24* o, s32 id) {
    // the original saves s2 without using it (an eliminated pseudo); an s2 pin reproduces the save
    register s32 k asm("$18");
    asm volatile("" : "=r"(k));
    func_00139d78(o);
    o->set(id);
}
}  // namespace n0023f5b8

// 0023f618 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0023f618 {
/*TARGET 0023f618*/
void func_0023f618(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f618jjjj");
void func_0023f618(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    r15 = (u32)((s32)0u + (-1));
    *(u32*)((u32)r4 + (s32)(32)) = r5;
    *(u32*)((u32)r4 + (s32)(36)) = r15;
}
}  // namespace n0023f618

// 0023f628 (was src/anon/batch_w17.cpp)
namespace n0023f628 {
u32 func_00139d78(void*) asm("func_00139d78");
/*TARGET 0023f628*/
void func_0023f628(u8* p, u32 a) asm("func_0023f628");
void func_0023f628(u8* p, u32 a) {
    func_00139d78(p);
    *(u32*)(p + 64) = a;
}
}  // namespace n0023f628

// 0023f660 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0023f660 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 0023f660*/
u32 func_0023f660(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f660jjjj");
u32 func_0023f660(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00139d78(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r16 + (s32)(64));
    return r2;
}
}  // namespace n0023f660

// 0023f688 (was src/anon/batch_w18.cpp)
namespace n0023f688 {
// 0014d8d0: moved to src/anon/unit_0014d680.cpp

u32 func_00139d78(void*) asm("func_00139d78");
/*TARGET 0023f688*/
// 0x00226a78: definition moved into src/anon/unit_00224780.cpp

void func_0023f688(u8* p, u32 v) asm("func_0023f688");
// 0x00226a78: definition moved into src/anon/unit_00224780.cpp

void func_0023f688(u8* p, u32 v) {
    func_00139d78(p);
    *(u32*)(p + 40) = v;
}
}  // namespace n0023f688

// 0023f6c0 (was src/anon/batch_w19.cpp)
namespace n0023f6c0 {
u8 func_00139d78(void*) asm("func_00139d78");
/*TARGET 0023f6c0*/
void func_0023f6c0(u8* p, u32 a) asm("func_0023f6c0");
void func_0023f6c0(u8* p, u32 a) {
    func_00139d78(p);
    *(u32*)(p + 0x48) = a;
}
}  // namespace n0023f6c0

// 0023f6f8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023f6f8 {
// 0x002251c8: definition moved into src/anon/unit_00224780.cpp

extern "C" u32 func_00139d78(...) asm("func_00139d78");
u32 func_0023a918(...) asm("func_0023a918");
/*TARGET 0023f6f8*/
u32 func_0023f6f8(u32 a0, u32 a1) asm("_Z13func_0023f6f8jj");
u32 func_0023f6f8(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 t6 = 0;

    if (func_00139d78(a0, a1) == 0) {
        return t6;
    }
    u32 t7 = *(u32*)(s0 + 28);
    if (t7 == 0) {
        return t6;
    }
    t6 = func_0023a918(t7) >> 24;
    return t6;
}
}  // namespace n0023f6f8

// 0023f740 (was src/anon/batch_w20.cpp)
namespace n0023f740 {
void func_00139d78(void*) asm("func_00139d78");
/*TARGET 0023f740*/
// 0x00236a18: definition moved into src/anon/unit_00236180.cpp

void func_0023f740(u8* p, u32 a) asm("func_0023f740");
// 0x00236a18: definition moved into src/anon/unit_00236180.cpp

void func_0023f740(u8* p, u32 a) {
    func_00139d78(p);
    *(u32*)(p + 0x44) = a;
}
}  // namespace n0023f740

// 0023f778 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023f778 {
/*TARGET 0023f778*/
void func_0023f778(u32 a0, u32 a1) asm("_Z13func_0023f778jj");
void func_0023f778(u32 a0, u32 a1) {  // copy_3halfwords_44
    a0 += 44;
    s32 t5 = 0;
    while (1) {
        u16 t7 = *(u16*)a1;
        t5 += 1;
        s32 t6 = (t5 < 3);
        *(u16*)a0 = t7;
        a1 += 2;
        if (t6 == 0) {
            break;
        }
        a0 += 2;
    }
}
}  // namespace n0023f778

// 0023f7a8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023f7a8 {
/*TARGET 0023f7a8*/
void func_0023f7a8(u32 a0, u32 a1) asm("_Z13func_0023f7a8jj");
void func_0023f7a8(u32 a0, u32 a1) {  // copy_3halfwords_50
    a0 += 50;
    s32 t5 = 0;
    while (1) {
        u16 t7 = *(u16*)a1;
        t5 += 1;
        s32 t6 = (t5 < 3);
        *(u16*)a0 = t7;
        a1 += 2;
        if (t6 == 0) {
            break;
        }
        a0 += 2;
    }
}
}  // namespace n0023f7a8

// 0023f7d8 (was src/tozawa/laymsg.cpp)
namespace Tz { // method 0023f7d8
/*TARGET 0023f7d8*/
s32 LayMsg::getSequence() { return reinterpret_cast<LayMsgLayout*>(this)->sequence; }
}  // Tz

// 0023f7e0 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n0023f7e0 {
u32 func_0023f8a8(u32, u32, u32, u32) asm("_Z13func_0023f8a8jjjj");
extern u8 D_0035ebd8 asm("D_0035ebd8");
/*TARGET 0023f7e0*/
u32 func_0023f7e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f7e0jjjj");
u32 func_0023f7e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_0035ebd8);
    return func_0023f8a8(a0, a1, a2, a3);
}
}  // namespace n0023f7e0

// 0023f800 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n0023f800 {
u32 func_0023f8a8(u32, u32, u32, u32) asm("_Z13func_0023f8a8jjjj");
extern u8 D_0035ebd8 asm("D_0035ebd8");
/*TARGET 0023f800*/
u32 func_0023f800(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f800jjjj");
u32 func_0023f800(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_0035ebd8);
    return func_0023f8a8(a0, a1, a2, a3);
}
}  // namespace n0023f800

// 0023f820 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0023f820 {
u32 func_0023f8c8(u32, u32, u32, u32) asm("_Z13func_0023f8c8jjjj");
extern u8 D_0035ebd8 asm("D_0035ebd8");
/*TARGET 0023f820*/
u32 func_0023f820(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f820jjjj");
u32 func_0023f820(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035ebd8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0023f8c8)(u32, u32, u32, u32) = func_0023f8c8;
    r2 = fp_call4_0023f8c8(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0023f820

// 0023f848 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0023f848 {
u32 func_0023f8c8(u32, u32, u32, u32) asm("_Z13func_0023f8c8jjjj");
extern u8 D_0035ebd8 asm("D_0035ebd8");
/*TARGET 0023f848*/
u32 func_0023f848(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f848jjjj");
u32 func_0023f848(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035ebd8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0023f8c8)(u32, u32, u32, u32) = func_0023f8c8;
    r2 = fp_call4_0023f8c8(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0023f848

// 0023f870 (was src/anon/batch_w21.cpp)
namespace n0023f870 {
void func_0023f8c8(void*) asm("func_0023f8c8");
void func_00106420(void*) asm("func_00106420");
extern u32 D_0035ebd8 asm("D_0035ebd8");
/*TARGET 0023f870*/
void func_0023f870(void** p) asm("func_0023f870");
void func_0023f870(void** p) {
    *p = &D_0035ebd8;
    func_0023f8c8(p);
    func_00106420(p);
}
}  // namespace n0023f870

// 0023f8a8 (was src/anon/tiny_auto80.cpp)
namespace n0023f8a8 {
void func_0023f8a8(u32, u32, u32, u32) asm("_Z13func_0023f8a8jjjj");
/*TARGET 0023f8a8*/
// 0022c410: moved to src/sasa/event_countdown.cpp (linked unit)

void func_0023f8a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f8a8jjjj");
// 0022c410: moved to src/sasa/event_countdown.cpp (linked unit)

void func_0023f8a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    *(volatile u32*)((u32)r4 + (s32)(20)) = 0u;
    *(u32*)((u32)r4 + (s32)(4)) = 0u;
    *(volatile u8*)((u32)r4 + (s32)(24)) = (u8)0u;
    *(u32*)((u32)r4 + (s32)(8)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(12)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(16)) = 0u;
}
}  // namespace n0023f8a8

// 0023f8c8 (was src/anon/batch_w203.cpp)
namespace n0023f8c8 {
// to_161f48_arg1
void func_0023fad0(void*) asm("func_0023fad0");
// 0x00152ab8: definition moved into src/anon/unit_0014ecb8.cpp

// 00159c20: moved to src/harata/libdk/talkcamera.cpp

void u_call4_0023f8c8(u8* a) asm("_Z16u_call4_0023f8c8jjjj");
/*TARGET 0023f8c8*/
void u_call4_0023f8c8(u8* a) asm("_Z16u_call4_0023f8c8jjjj");
void u_call4_0023f8c8(u8* a) {
  if (a[24]) func_0023fad0(a);
  *(u32*)(a + 4) = 0;
}
}  // namespace n0023f8c8

// 0023f900 (was src/tozawa/layfile.cpp)
namespace Tz { // method 0023f900
/*TARGET 0023f900*/
// 0x002a1cd8: definition moved into src/anon/unit_002a0908.cpp

s32 LayFile::getFileAddress() const {
    return reinterpret_cast<const FileAddressLayout*>(this)->fileAddress;
}
}  // Tz

// 0023f908 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023f908 {
u32 func_00168b38(...) asm("func_00168b38");
/*TARGET 0023f908*/
// entry_array_find_nth

u32 func_0023f908(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023f908jjjjjjjj");
// entry_array_find_nth

u32 func_0023f908(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r15 = r5;
    r6 = r5;
    r5 = (u32)((s32)0u + (29));
    r14 = ((u32*)(u32)r4)[4];
    r15 = ((s32)r15 < (s32)r14);
    r2 = 0u;
    if (r15 != 0u) {
        r4 = ((u32*)(u32)r4)[1];
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
        r2 = ((u32*)(u32)r2)[2];
    }
    return r2;
}
}  // namespace n0023f908

// 0023f948 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023f948 {
u32 func_00168b38(...) asm("func_00168b38");
/*TARGET 0023f948*/
// entry_array_find_nth

u32 func_0023f948(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023f948jjjjjjjj");
// entry_array_find_nth

u32 func_0023f948(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r15 = r5;
    r6 = r5;
    r5 = (u32)((s32)0u + (28));
    r14 = ((u32*)(u32)r4)[2];
    r15 = ((s32)r15 < (s32)r14);
    r2 = 0u;
    if (r15 != 0u) {
        r4 = ((u32*)(u32)r4)[1];
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
        r2 = ((u32*)(u32)r2)[2];
    }
    return r2;
}
}  // namespace n0023f948

// 0023f988 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023f988 {
u32 func_00168b38(...) asm("func_00168b38");
/*TARGET 0023f988*/
// entry_array_find_nth

u32 func_0023f988(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023f988jjjjjjjj");
// entry_array_find_nth

u32 func_0023f988(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r15 = r5;
    r6 = r5;
    r5 = (u32)((s32)0u + (24));
    r14 = ((u32*)(u32)r4)[5];
    r15 = ((s32)r15 < (s32)r14);
    r2 = 0u;
    if (r15 != 0u) {
        r4 = ((u32*)(u32)r4)[1];
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
        r2 = ((u32*)(u32)r2)[2];
    }
    return r2;
}
}  // namespace n0023f988

// 0023f9c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023f9c8 {
u32 func_00168b38(...) asm("func_00168b38");
/*TARGET 0023f9c8*/
// entry_array_find_nth

u32 func_0023f9c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023f9c8jjjjjjjj");
// entry_array_find_nth

u32 func_0023f9c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r15 = r5;
    r6 = r5;
    r5 = (u32)((s32)0u + (25));
    r14 = ((u32*)(u32)r4)[3];
    r15 = ((s32)r15 < (s32)r14);
    r2 = 0u;
    if (r15 != 0u) {
        r4 = ((u32*)(u32)r4)[1];
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
        r2 = ((u32*)(u32)r2)[2];
    }
    return r2;
}
}  // namespace n0023f9c8

// 0023fa08 (was src/anon/batch_w38.cpp)
namespace n0023fa08 {
void LeadDataSetText(u8*, u32) asm("_ZN2Tz15LeadDataSetTextEPvj");
// 0x002344c0: definition moved into src/anon/unit_002335e8.cpp

u32 func_00168aa0(u32, s32) asm("func_00168aa0");
/*TARGET 0023fa08*/
void LeadDataSetText(u8* p, u32 id) asm("_ZN2Tz15LeadDataSetTextEPvj");
void LeadDataSetText(u8* p, u32 id) {
    *(u32*)(p + 4) = id;
    *(u32*)(p + 8) = func_00168aa0(id, 28);
    *(u32*)(p + 16) = func_00168aa0(*(u32*)(p + 4), 29);
    *(u32*)(p + 12) = func_00168aa0(*(u32*)(p + 4), 25);
    *(u32*)(p + 20) = func_00168aa0(*(u32*)(p + 4), 24);
}
}  // namespace n0023fa08

// 0023fa70 (was src/anon/tiny_wrappers_more.cpp)
namespace n0023fa70 {
u32 YS_CACHE_BUFF_ReadRequest(u32, u32, u32, u32) asm("_ZN2YS10CACHE_BUFF11ReadRequestEPKcij");
/*TARGET 0023fa70*/
u32 func_0023fa70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023fa70jjjj");
u32 func_0023fa70(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_CACHE_BUFF_ReadRequest(a1, a2, 0x00000000u, a3);
}
}  // namespace n0023fa70

// 0023fa90 (was src/anon/batch_w18.cpp)
namespace n0023fa90 {
void* func_001708f8(const char*, s32) asm("func_001708f8");
void func_0023fa08(void*, void*) asm("func_0023fa08");
void LayFile_alloc(u8* self, const char* name) asm("_ZN2Tz7LayFile5allocEPKc");
/*TARGET 0023fa90*/
void LayFile_alloc(u8* self, const char* name) asm("_ZN2Tz7LayFile5allocEPKc");
void LayFile_alloc(u8* self, const char* name) {
    func_0023fa08(self, func_001708f8(name, -1));
    self[24] = 1;
}
}  // namespace n0023fa90

// 0023fad0 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023fad0 {
u32 func_00170950(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00170950jjjjjjjj");
u32 func_0023fad0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0023fad0jjjjjjjj");
/*TARGET 0023fad0*/
u32 func_0023fad0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023fad0jjjjjjjj");
u32 func_0023fad0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16;
    r16 = r4;
    r4 = *(u32*)((u32)r4 + (s32)(4));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00170950)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(4)) = 0u;
    *(u8*)((u32)r16 + (s32)(24)) = (u8)0u;
    return r2;
}
}  // namespace n0023fad0

// 0023fb00 (was src/anon/batch_w10.cpp)
namespace n0023fb00 {
void func_0023fbc8(void) asm("func_0023fbc8");
extern s32 D_0035ebe0 asm("D_0035ebe0");
extern s32 D_0035ebec asm("D_0035ebec");
/*TARGET 0023fb00*/
// 0x002346c0: definition moved into src/anon/unit_002335e8.cpp

void func_0023fb00(s32 a) asm("func_0023fb00");
// 0x002346c0: definition moved into src/anon/unit_002335e8.cpp

void func_0023fb00(s32 a) {
    D_0035ebe0 = a;
    func_0023fbc8();
    D_0035ebec = 0;
}
}  // namespace n0023fb00

// 0023fb28 (was src/anon/batch_w6.cpp)
namespace n0023fb28 {
void func_0023fc08(void) asm("func_0023fc08");
extern u32 D_0035ebe0 asm("D_0035ebe0");
extern u32 D_0035ebec asm("D_0035ebec");
/*TARGET 0023fb28*/
void func_0023fb28(void) asm("func_0023fb28");
void func_0023fb28(void) {
    func_0023fc08();
    D_0035ebe0 = 0;
    D_0035ebec = 0;
}
}  // namespace n0023fb28

// 0023fb58 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023fb58 {
extern u32 D_0035ebe0 asm("D_0035ebe0");
/*TARGET 0023fb58*/
u32 func_0023fb58(u32 a0) asm("_Z13func_0023fb58j");
u32 func_0023fb58(u32 a0) {
    u32 a1 = a0;
    u32 a2 = (u32)__builtin_return_address(0);
    a0 = D_0035ebe0;
    u32 t7 = *(u32*)a0;
    u32 v0 = *(u32*)t7;
    return ((u32(*)(u32, u32, u32))v0)(a0, a1, a2);
}
}  // namespace n0023fb58

// 0023fb90 (was src/anon/batch_w23.cpp)
namespace n0023fb90 {
// 0x00237540: definition moved into src/anon/unit_00237068.cpp

extern void* D_0035ebe0 asm("D_0035ebe0");
/*TARGET 0023fb90*/
void func_0023fb90(void* a) asm("func_0023fb90");
void func_0023fb90(void* a) {
    if (a) {
        void* o = D_0035ebe0;
        (*(void (**)(void*, void*))((*(u8**)o) + 4))(o, a);
    }
}
}  // namespace n0023fb90

// 0023fbc8 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023fbc8 {
u32 func_0023fb58(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0023fb58jjjjjjjj");
u32 func_0023fbc8(void) asm("_Z13func_0023fbc8v");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 0023fbc8*/
u32 func_0023fbc8(void) asm("_Z13func_0023fbc8v");
u32 func_0023fbc8(void) {
    u32 v0 = ((u32(*)(u32))func_0023fb58)(128);
    *(u32*)((u8*)&D_00360000 - 5136) = v0;
    v0 = ((u32(*)(u32))func_0023fb58)(256);
    *(u32*)((u8*)&D_00360000 - 5144) = v0;
    *(u32*)((u8*)&D_00360000 - 5148) = v0;
    return v0;
}
}  // namespace n0023fbc8

// 0023fc08 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023fc08 {
void func_0023fb90(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0023fb90jjjjjjjj");
u32 func_0023fc08(void) asm("_Z13func_0023fc08v");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 0023fc08*/
u32 func_0023fc08(void) asm("_Z13func_0023fc08v");
u32 func_0023fc08(void) {
    ((u32(*)(u32))func_0023fb90)(*(u32*)((u8*)&D_00360000 - 5136));
    u32 v0 = ((u32(*)(u32))func_0023fb90)(*(u32*)((u8*)&D_00360000 - 5148));
    *(u32*)((u8*)&D_00360000 - 5144) = 0;
    return v0;
}
}  // namespace n0023fc08

// 0023fc40 (was src/anon/auto80_199_queue.cpp)
namespace n0023fc40 {
/*TARGET 0023fc40*/
u32 func_0023fc40(u32 a0, u32 a1) asm("_Z13func_0023fc40jj");
u32 func_0023fc40(u32 a0, u32 a1) {
    u32 s1 = a1;
    u32 t7 = D_0035ebe8;
    u32 v0 = memcpy(t7, a0, s1);

    u32 t5 = D_0035ebe8;
    u32 t6 = D_0035ebec;
    u32 t7a = D_0035ebf0;
    t6 = t6 << 3;
    *(u32*)(t6 + t7a) = t5;

    u32 t7b = D_0035ebec;
    u32 t6a = D_0035ebf0;
    t7b = t7b << 3;
    *(u32*)(t7b + t6a + 4) = s1;

    u32 t6b = D_0035ebe8;
    u32 t7c = D_0035ebec;
    t6b = t6b + s1;
    D_0035ebe8 = t6b;
    t7c = t7c + 1;
    D_0035ebec = t7c;
    return v0;
}
}  // namespace n0023fc40

// 0023fcd0 (was src/anon/batch_w39.cpp)
namespace n0023fcd0 {
// --- 0023fcd0
// Pops the top entry of a stack and makes its first word current.
struct S23f { u32 a; u32 b; };
extern u32 D_0035ebe8 asm("D_0035ebe8");
extern s32 D_0035ebec asm("D_0035ebec");
extern S23f* D_0035ebf0 asm("D_0035ebf0");
void memcpy(u32, u32, u32) asm("memcpy");
/*TARGET 0023fcd0*/
void func_0023fcd0(u32 x) asm("func_0023fcd0");
void func_0023fcd0(u32 x) {
    S23f* e = &D_0035ebf0[D_0035ebec];
    memcpy(x, e[-1].a, e[-1].b);
    D_0035ebe8 = e[-1].a;
    D_0035ebec--;
}
}  // namespace n0023fcd0

// 0023fd30 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0023fd30 {
/*TARGET 0023fd30*/
u32 func_0023fd30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023fd30jjjj");
u32 func_0023fd30(u32 a0, u32 a1, u32 a2, u32 a3) {  // global_flag_nonzero
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)(0x0036u << 16);
    r2 = *(u32*)((u32)r15 + (s32)(-5140));
    r2 = ((s32)0u < (s32)r2);
    return r2;
}
}  // namespace n0023fd30

// 0023fd40 (was src/anon/auto80_199_queue.cpp)
namespace n0023fd40 {
/*TARGET 0023fd40*/
void func_0023fd40(u32 a0) asm("_Z13func_0023fd40j");
void func_0023fd40(u32 a0) {
    u8* s17 = (u8*)func_001058e8();
    u32 s16 = a0;
    D_0035ec84 = s16;
    func_002422b8(s16);
    func_0023fe60();
    func_002400f8(0);

    u8* v0 = (u8*)func_001058e8();
    u32 r = func_00241ed8(v0[12]);
    u32 t6 = 0xFFFFFEFFu;
    u32 t7 = *(u32*)(s17 + 16796);
    t7 = t7 & t6;
    t7 = t7 | ((r & 1u) << 8);
    *(u32*)(s17 + 16796) = t7;
}
}  // namespace n0023fd40

// 0023fdc0 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n0023fdc0 {
u32 func_00240000() asm("_Z13func_00240000v");
u32 func_002422f0() asm("_Z13func_002422f0v");
/*TARGET 0023fdc0*/
// 0x00236478: definition moved into src/anon/unit_00236180.cpp

u32 func_0023fdc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023fdc0jjjj");
// 0x00236478: definition moved into src/anon/unit_00236180.cpp

u32 func_0023fdc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    u32 (*fp_call0_00240000)() = func_00240000;
    r2 = fp_call0_00240000();
    u32 (*fp_call0_002422f0)() = func_002422f0;
    r2 = fp_call0_002422f0();
    r15 = (u32)(0x0036u << 16);
    *(u32*)((u32)r15 + (s32)(-4988)) = 0u;
    return r2;
}
}  // namespace n0023fdc0

// 0023fdf0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023fdf0 {
extern u32 D_0035ec84 asm("D_0035ec84");
/*TARGET 0023fdf0*/
u32 func_0023fdf0(u32 a0) asm("_Z13func_0023fdf0j");
u32 func_0023fdf0(u32 a0) {
    u32 a1 = a0;
    u32 a2 = (u32)__builtin_return_address(0);
    a0 = D_0035ec84;
    u32 t7 = *(u32*)a0;
    u32 v0 = *(u32*)t7;
    return ((u32(*)(u32, u32, u32))v0)(a0, a1, a2);
}
}  // namespace n0023fdf0

// 0023fe28 (was src/anon/batch_w11.cpp)
namespace n0023fe28 {
// 0x00237578: definition moved into src/anon/unit_00237068.cpp

typedef void (*VFn2)(void*, void*);
extern void* D_0035ec84 asm("D_0035ec84");
/*TARGET 0023fe28*/
void func_0023fe28(void* a) asm("func_0023fe28");
void func_0023fe28(void* a) {
    if (a) {
        void* o = D_0035ec84;
        (*(VFn2*)((*(u8**)o) + 4))(o, a);
    }
}
}  // namespace n0023fe28

// 0023fe60 (was src/anon/batch_w1949_nsa.c)
namespace n0023fe60 {
extern s32 D_0035ec84 asm("D_0035ec84");
extern u8* D_0035ec88 asm("D_0035ec88");
extern u8* D_0035ec8c asm("D_0035ec8c");
extern u8* D_0035ec90 asm("D_0035ec90");
extern u8* D_0035ec94 asm("D_0035ec94");
extern u8* D_0035ec98 asm("D_0035ec98");
extern u8* D_0035ec9c asm("D_0035ec9c");
extern u8* D_0035eca0 asm("D_0035eca0");
extern void* D_0035eca4 asm("D_0035eca4");
u8* func_001063f0(s32, s32) asm("func_001063f0");
u8* func_001063c0(s32, s32) asm("func_001063c0");
void* memset(void*, int, unsigned int) asm("_Z16wtarget_002fde18jjjj");
s32 func_00240440(s32) asm("func_00240440");
void func_00241fd0(void*, s32) asm("func_00241fd0");
typedef struct W1949_Hd { s8 a; u8 pad; s16 b; } W1949_Hd;
/*TARGET 0023fe60*/
void func_0023fe60(void) asm("func_0023fe60");
void func_0023fe60(void) {
    D_0035ec88 = func_001063f0(0x50, D_0035ec84); memset(D_0035ec88, 0, 0x50);
    D_0035ec8c = func_001063f0(0x1a, D_0035ec84); memset(D_0035ec8c, 0, 0x1a);
    s32 a = func_00240440(0x8a58);
    s32 sz;
    if (a > func_00240440(0x10fc0)) sz = func_00240440(0x8a58); else sz = func_00240440(0x10fc0);
    sz = sz << 10;
    D_0035ec90 = func_001063f0(sz, D_0035ec84); memset(D_0035ec90, 0, sz);
    D_0035ec94 = func_001063c0(0xc68, D_0035ec84); memset(D_0035ec94, 0, 0xc68);
    ((W1949_Hd*)D_0035ec94)->a = -1;
    ((W1949_Hd*)D_0035ec94)->b = -1;
    D_0035ec98 = func_001063c0(0xf80, D_0035ec84); memset(D_0035ec98, 0, 0xf80);
    D_0035eca0 = func_001063f0(0x1900, D_0035ec84); memset(D_0035eca0, 0, 0x1900);
    u8* p = D_0035eca0;
    u32 m = (u32)p & 0x3f;
    if (m != 0) p = p - m + 0x40;
    D_0035ec9c = p;
    void* q = func_001063c0(8, D_0035ec84);
    func_00241fd0(q, D_0035ec84);
    D_0035eca4 = q;
}
}  // namespace n0023fe60

// 00240000 (was src/anon/batch_w78.cpp)
namespace n00240000 {
void func_00106450(void*) asm("_Z13func_00106450Pv");
void func_00106420(void*) asm("_Z13func_00106420Pv");
void func_00242048(void*) asm("_Z13func_00242048Pv");
extern void* D_0035ec88 asm("D_0035ec88");
extern void* D_0035ec8c asm("D_0035ec8c");
extern void* D_0035ec90 asm("D_0035ec90");
extern void* D_0035ec94 asm("D_0035ec94");
extern void* D_0035ec98 asm("D_0035ec98");
extern u32 D_0035ec9c asm("D_0035ec9c");
extern void* D_0035eca0 asm("D_0035eca0");
extern void* D_0035eca4 asm("D_0035eca4");
void u_call0_00240000(void) asm("_Z16u_call0_00240000v");
/*TARGET 00240000*/
void u_call0_00240000(void) asm("_Z16u_call0_00240000v");
void u_call0_00240000(void) {
    if (D_0035ec88) { func_00106450(D_0035ec88); D_0035ec88 = 0; }
    if (D_0035ec8c) { func_00106450(D_0035ec8c); D_0035ec8c = 0; }
    if (D_0035ec90) { func_00106450(D_0035ec90); D_0035ec90 = 0; }
    if (D_0035ec94) { func_00106420(D_0035ec94); D_0035ec94 = 0; }
    if (D_0035ec98) { func_00106420(D_0035ec98); D_0035ec98 = 0; }
    if (D_0035eca0) { func_00106450(D_0035eca0); D_0035eca0 = 0; }
    D_0035ec9c = 0;
    void* p = D_0035eca4;
    if (p) {
        func_00242048(p);
        func_00106420(p);
        D_0035eca4 = 0;
    }
}
}  // namespace n00240000

// 002400f8 (was src/tozawa/mcard.cpp)
namespace Tz { // method 002400f8
/*TARGET 002400f8*/
void MCard::SetSystemMode(s32 mode) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-4952)) = (u32)mode;
}
}  // Tz

// 00240108 (was src/anon/tiny.cpp)
namespace n00240108 {
/*TARGET 00240108*/
u32 func_00240108(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00240108jjjj");
u32 func_00240108(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36eb68
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-4952)));
}
}  // namespace n00240108

// 00240118 (was src/anon/batch_w93.cpp)
namespace n00240118 {
// VU0 quadword vector helpers (16-byte aligned xyzw).
struct W93V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void W93Set(W93V* d, const W93V* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct W93Vec { W93V v; W93Vec& operator=(const W93Vec& o) { W93Set(&v, &o.v); return *this; } };
static inline __attribute__((always_inline)) W93Vec operator*(const W93Vec& a, f32 k)
{ W93Vec r; asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory"); return r; }
struct W93Ver { u32 a, b, c; };
void* func_00105c30(void) asm("func_00105c30");
W93Ver* func_00105c48(void*) asm("func_00105c48");
// entry12_34cae4
u32 func_002402e0(void) asm("func_002402e0");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
extern char D_00371658[] asm("D_00371658");
extern char D_00371668[] asm("D_00371668");
extern char D_00371678[] asm("D_00371678");
extern char D_00371680[] asm("D_00371680");
extern u32 D_0035ec04 asm("D_0035ec04");
/*TARGET 00240118*/
// Formats the version/build string for the given mode.
void func_00240118(char* buf, s32 a, s32 mode) asm("func_00240118");
// Formats the version/build string for the given mode.
void func_00240118(char* buf, s32 a, s32 mode)
{
    W93Ver* v = func_00105c48(func_00105c30());  // entry12_34cae4
    if (a < 0) {
        func_002fee78(buf, D_00371658, func_002402e0(), v->a, v->b, v->c);
    } else if (mode == 1) {
        func_002fee78(buf, D_00371668, func_002402e0(), v->a, v->b, v->c);
    } else if (mode == 2) {
        func_002fee78(buf, D_00371678, func_002402e0(), D_0035ec04);
    } else {
        func_002fee78(buf, D_00371680, func_002402e0(), v->a, v->b, v->c, a);
    }
}
}  // namespace n00240118

// 00240240 (was src/anon/batch_w1776_nsa.cpp)
namespace n00240240 {
extern char D_00371698[] asm("D_00371698");
// 001c6fa8: moved to src/anon/unit_001c6e58.cpp (linked unit)

// 001c7048: moved to src/anon/unit_001c6e58.cpp (linked unit)

void strcpy_w1776(char*, const char*) asm("_ZN2Tz16LayFileBuildDataEPvj");
s32 strlen(const char*) asm("strlen");
void func_00240118(char*, u32, u32) asm("func_00240118");
/*TARGET 00240240*/
// Builds "/" + func_00240118's text in a buffer and copies it twice to dst.
void func_00240240(char* dst, u32 a, u32 b) asm("func_00240240");
// Builds "/" + func_00240118's text in a buffer and copies it twice to dst.
void func_00240240(char* dst, u32 a, u32 b) {
    char buf[80];
    strcpy_w1776(buf, D_00371698);
    s32 l = strlen(buf);
    func_00240118(&buf[l], a, b);
    l = strlen(buf);
    for (s32 i = 0; i < 2; i++)
        strcpy_w1776(&dst[l * i], buf);
}
}  // namespace n00240240

// 002402e0 (was src/anon/batch_w53.cpp)
namespace n002402e0 {
extern u32 D_01dae6a0 asm("D_01dae6a0");
extern u32 D_0035ecac asm("D_0035ecac");
extern u32 D_0035ecb0 asm("D_0035ecb0");
extern u32 D_0035ecb4 asm("D_0035ecb4");
s32 func_00105c30(void) asm("func_00105c30");
/*TARGET 002402e0*/
// 0x002368e8: definition moved into src/anon/unit_00236180.cpp

u32 func_002402e0(void) asm("func_002402e0");
// 0x002368e8: definition moved into src/anon/unit_00236180.cpp

u32 func_002402e0(void) {
    switch (func_00105c30()) {
    case 1:
    case 8:
        D_01dae6a0 = D_0035ecac;
        break;
    case 2:
        D_01dae6a0 = D_0035ecb0;
        break;
    default:
        D_01dae6a0 = D_0035ecb4;
        break;
    }
    return D_01dae6a0;
}
}  // namespace n002402e0

// 00240360 (was src/anon/batch_w87.cpp)
namespace n00240360 {
// ---- 0x240360 ----
extern void* D_0035ec88 asm("D_0035ec88");
extern char D_003716b8[] asm("D_003716b8");
extern char* D_0035ebf8 asm("D_0035ebf8");
extern char* D_0035ebfc asm("D_0035ebfc");
extern char* D_0035ec00 asm("D_0035ec00");
void func_002ff2e8(void*, const char*) asm("func_002ff2e8");
s32 func_00240108(void) asm("func_00240108");
// get_global_36eb68
void func_00240118(void*, s32, s32) asm("func_00240118");
/*TARGET 00240360*/
void func_00240360(s32 k) asm("func_00240360");
void func_00240360(s32 k) {
    if (k == -5) return;
    if (k == -4) { func_002ff2e8(D_0035ec88, D_003716b8); return; }
    if (k == -3) { func_002ff2e8(D_0035ec88, D_0035ebf8); return; }
    if (k == -2) {
        const char* s;
        if (func_00240108()) s = D_0035ec00; else s = D_0035ebfc;
        func_002ff2e8(D_0035ec88, s);
        return;
    }
    func_00240118(D_0035ec88, k, func_00240108());
}
}  // namespace n00240360

// 00240430 (was src/anon/tiny.cpp)
namespace n00240430 {
/*TARGET 00240430*/
u32 func_00240430(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00240430jjjj");
u32 func_00240430(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-4984)));
}
}  // namespace n00240430

// 00240440 (was src/anon/tiny_more.cpp)
namespace n00240440 {
/*TARGET 00240440*/
// 0x002283e0: definition moved into src/anon/unit_00224780.cpp

u32 func_00240440(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00240440jjjj");
// 0x002283e0: definition moved into src/anon/unit_00224780.cpp

u32 func_00240440(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)a0 + (1023)); v = v >> 10; return v; }
}  // namespace n00240440

// 00240450 (was src/anon/batch_w95.cpp)
namespace n00240450 {
struct Cfg84 { u32 d[21]; };
// 0022ad88: moved to src/sasa/musical_input.cpp (linked unit)

extern u8* D_0035ec90 asm("D_0035ec90");
extern char* D_0035ec00 asm("D_0035ec00");
extern char* D_0035ebfc asm("D_0035ebfc");
extern Cfg84 D_0035ec30 asm("D_0035ec30");
extern Cfg84 D_0032df74 asm("D_0032df74");
extern u8 D_003716c0[] asm("D_003716c0");
extern u8 D_003716f8[] asm("D_003716f8");
extern u8 D_00371738[] asm("D_00371738");
extern u8 D_00371768[] asm("D_00371768");
extern u8 D_00371798[] asm("D_00371798");
void func_002fde18(void*, s32, u32) asm("func_002fde18");
void memcpy(void*, const void*, u32) asm("memcpy");
void func_002405a8(u8*, s32) asm("func_002405a8");
s32 func_00240108(void) asm("func_00240108");
// get_global_36eb68
void func_002ff2e8(char*, const char*) asm("func_002ff2e8");
/*TARGET 00240450*/
void func_00240450(u8* p, s32 n) asm("func_00240450");
void func_00240450(u8* p, s32 n) {
    if (!p) p = D_0035ec90;
    func_002fde18(p, 0, 964);
    memcpy(p, D_003716c0, 4);
    *(u16*)(p + 6) = 32;
    *(u32*)(p + 12) = 96;
    memcpy(p + 16, D_003716f8, 64);
    memcpy(p + 80, D_00371738, 48);
    memcpy(p + 128, D_00371768, 48);
    memcpy(p + 176, D_00371798, 16);
    func_002405a8(p + 192, n + 1);
    char* s = func_00240108() ? D_0035ec00 : D_0035ebfc;
    func_002ff2e8((char*)p + 260, s);
    func_002ff2e8((char*)p + 324, s);
    func_002ff2e8((char*)p + 388, s);
    D_0035ec30 = D_0032df74;
}
}  // namespace n00240450

// 002405a8 (was src/anon/batch_w3800.cpp)
namespace n002405a8 {
// func_002405a8: build the memory-card save title (Shift-JIS) for slot `slot`:
// header text, game level / completion marks, slot number, item count and play time
// (hours, minutes) added into the template's fullwidth digit characters.

struct W3800_SaveRam {
    u8 pad0[0x249c];
    u32 flag0 : 1;
    u32 : 31;
    u8 pad24a0[0x24f0 - 0x24a0];
    u8 items[1];
};
struct W3800_Item {
    u8 pad0[0xf];
    u8 count;
};
void W3800_memset(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
s32 strlen(const char*) asm("strlen");
void memcpy(void*, const void*, u32) asm("memcpy");
s32 func_00240108(void) asm("func_00240108");
s32 W3800_GetGameLevel(W3800_SaveRam*) asm("_ZN7SAVERAM12GetGameLevelEPv");
W3800_SaveRam* W3800_getSaveRam(void) asm("_Z10getSaveRamv");
s32 W3800_isGameComplete(W3800_SaveRam*) asm("_ZN7SAVERAM14isGameCompleteEv");
W3800_Item* W3800_ctarget(void*, u32) asm("_Z16ctarget_00188fe0jjjj");
void W3800_getPlayTime(u32*, u32*, u32*, u32*) asm("_ZN2dk5Clock18getPlayTimeToHMSMSERjS1_S1_S1_");
extern W3800_SaveRam D_0032bb30 asm("D_0032bb30");
extern const char* D_0035ec0c asm("D_0035ec0c");
extern const char* D_0035ec10 asm("D_0035ec10");
extern const char* D_0035ec14 asm("D_0035ec14");
extern const char* D_0035ec18[] asm("D_0035ec18");
extern const char* D_0035ec28 asm("D_0035ec28");
extern const char* D_0035ec2c asm("D_0035ec2c");
/*TARGET 002405a8*/
void func_002405a8(char* buf, s32 slot) asm("func_002405a8");
void func_002405a8(char* buf, s32 slot)
{
    W3800_SaveRam* save = &D_0032bb30;
    W3800_memset(buf, 0, 0x40);
    s32 r = strlen(D_0035ec0c);
    s32 len;
    {
        // Partial asm: argument pins plus a hand-written copy of the length so the
        // copy into its saved fills the call's delay slot like the original.
        register char* a0
 = buf;
        s32 a2 = r;
        asm("" : "+r"(a2) : "r"(a0));
        asm("move %0,$2" : "=r"(len) : "r"(a0), "r"(a2));
        memcpy(a0, D_0035ec0c, a2);
    }
    if (func_00240108() == 0) {
        memcpy(buf + len - 4, D_0035ec18[W3800_GetGameLevel(save)], 2);
        if (W3800_isGameComplete(W3800_getSaveRam())) {
            memcpy(buf + len - 2, D_0035ec2c, 2);
        }
    }
    if (func_00240108()) {
        memcpy(buf + len, D_0035ec14, len);
        return;
    }
    register char* line asm("$16") = buf + len; // pin: keeps the digit cursor in s1
    memcpy(line, D_0035ec10, len);
    char* p = line + 3;
    s32 v;
    u32 u;
    v = slot / 10; if (v) { *p = v + *p; }
    p += 2;
    v = slot % 10; if (v) { *p = v + *p; }
    p += 8;
    W3800_Item* item;
    if ((u8)save->flag0) item = W3800_ctarget(save->items, 14);
    else item = W3800_ctarget(save->items, 1);
    s32 n = item->count;
    v = n / 10; if (v) { *p = v + *p; }
    p += 2;
    v = n % 10; if (v) { *p = v + *p; }
    u32 h, m, s, ms;
    W3800_getPlayTime(&h, &m, &s, &ms);
    p += 4;
    u32 hour = h;
    s32 big = 0;
    u = hour / 100; if (u) { *p = u + *p; big = 1; } else { memcpy(p - 1, D_0035ec28, 2); }
    hour %= 100;
    p += 2;
    u = hour / 10; if (u || big) { *p = u + *p; } else { memcpy(p - 1, D_0035ec28, 2); }
    p += 2;
    v = hour % 10; if (v) { *p = v + *p; }
    p += 4;
    v = m / 10; if (v) { *p = v + *p; }
    p += 2;
    v = m % 10; if (v) { *p = v + *p; asm("" : "+r"(p)); } // empty asm: register-allocation nudge only
}
}  // namespace n002405a8

// 002408d0 (was src/anon/batch_w88.cpp)
namespace n002408d0 {
s32 func_00240440(u32) asm("func_00240440");
/*TARGET 002408d0*/
// 0x00237988: definition moved into src/anon/unit_00237068.cpp

s32 func_002408d0(u32 mode) asm("func_002408d0");
// 0x00237988: definition moved into src/anon/unit_00237068.cpp

s32 func_002408d0(u32 mode) {
    s32 b = 0;
    s32 a = 0;
    if (mode < 2) {
        a = func_00240440(964);  // round_up_1024
        a += func_00240440(0x8a58);  // round_up_1024
        a += func_00240440(0x10fc0);  // round_up_1024
        a = (a + 8) / 5 * 5;
    }
    if (mode == 0 || mode == 2) {
        b = func_00240440(964);  // round_up_1024
        b += func_00240440(0x8a58);  // round_up_1024
        b += func_00240440(1024);  // round_up_1024
        b = (b + 8) / 5 * 5;
    }
    a += b;
    return a;
}
}  // namespace n002408d0

// 002409b8 (was src/anon/batch_w35.cpp)
namespace n002409b8 {
// 0x002343a8: definition moved into src/anon/unit_002335e8.cpp

extern u8* D_0035ec90 asm("D_0035ec90");
void func_00242408(void) asm("func_00242408");
// set_global_crc_m1
void func_00242418(void*, u32) asm("func_00242418");
/*TARGET 002409b8*/
// crc_byte_update
void func_002409b8(u8* p) asm("func_002409b8");
// crc_byte_update
void func_002409b8(u8* p) {
    if (!p) p = D_0035ec90;
    func_00242408();  // set_global_crc_m1
    func_00242418(p, 8);  // crc_byte_update
    func_00242418(p + 12, 0x10fb4);  // crc_byte_update
}
}  // namespace n002409b8

// 00240a08 (was src/anon/batch_w39.cpp)
namespace n00240a08 {
// --- 00240a08
struct S240 { u32 a; u32 b; u32 c; };
extern S240* D_0035ec90 asm("D_0035ec90");
u32 func_002409b8(S240*) asm("func_002409b8");
u32 func_00105870(void) asm("func_00105870");
/*TARGET 00240a08*/
int func_00240a08(S240* p) asm("func_00240a08");
int func_00240a08(S240* p) {
    if (!p) p = D_0035ec90;
    if (func_002409b8(p) != p->c) return 0;
    if (p->a != func_00105870()) return 0;
    return p->b == 0x3a;
}
}  // namespace n00240a08

// 00240a70 (was src/anon/batch_w88.cpp)
namespace n00240a70 {
// round_up_1024
u32 func_001058e8(void) asm("func_001058e8");
void memcpy(void*, u32, u32) asm("memcpy");
u8 func_00241e18(void) asm("func_00241e18");
u32 func_00241ed8(u8) asm("func_00241ed8");
u32 func_002409b8(u8*) asm("func_002409b8");
struct S84 { u32 w[21]; };
struct B240 { u64 lo : 32; u64 b : 8; u64 f : 1; u64 rest : 23; };
extern u8* D_0035ec90 asm("D_0035ec90");
extern S84 D_0035ec30 asm("D_0035ec30");
/*TARGET 00240a70*/
void func_00240a70(u8* p) asm("func_00240a70");
void func_00240a70(u8* p) {
    if (!p) p = D_0035ec90;
    memcpy(p, func_001058e8(), 0x10fc0);
    p[16796] = func_00241e18();
    ((B240*)(p + 16792))->f = func_00241ed8(p[12]) != 0;
    *(S84*)(p + 9284) = D_0035ec30;
    *(u32*)(p + 8) = func_002409b8(p);
}
}  // namespace n00240a70

// 00240b48 (was src/anon/batch_w28.cpp)
namespace n00240b48 {
u32 func_001058e8(void) asm("func_001058e8");
void memcpy(u32, u32, u32) asm("memcpy");
extern u32 D_0035ec90 asm("D_0035ec90");
/*TARGET 00240b48*/
// 0022ae98: moved to src/sasa/musical_input.cpp (linked unit)

void func_00240b48(u32 a) asm("func_00240b48");
// 0022ae98: moved to src/sasa/musical_input.cpp (linked unit)

void func_00240b48(u32 a) {
    if (!a) a = D_0035ec90;
    memcpy(func_001058e8(), a, 0x10fc0);
}
}  // namespace n00240b48

// 00240b90 (was src/tozawa/mcard.cpp)
namespace Tz { // method 00240b90
extern u32 D_0035ec94 asm("D_0035ec94");
/*TARGET 00240b90*/
void MCard::SetSlot(s32 slot) {
    u32 p = D_0035ec94;
    *(u8*)((u32)p + 0) = (u8)slot;
}
}  // Tz

// 00240ba0 (was src/tozawa/mcard.cpp)
namespace Tz { // method 00240ba0
extern u32 D_0035ec94 asm("D_0035ec94");
/*TARGET 00240ba0*/
s32 MCard::GetSlot() {
    u32 p = D_0035ec94;
    return (s32)(*(s8*)((u32)p + 0));
}
}  // Tz

// 00240bb0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00240bb0 {
/*TARGET 00240bb0*/
void func_00240bb0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00240bb0jjjj");
void func_00240bb0(u32 a0, u32 a1, u32 a2, u32 a3) {  // global_store_half2
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r15 = (u32)(0x0036u << 16);
    r14 = *(u32*)((u32)r15 + (s32)(-4972));
    *(u16*)((u32)r14 + (s32)(2)) = (u16)r4;
}
}  // namespace n00240bb0

// 00240bc0 (was src/tozawa/mcard.cpp)
namespace Tz { // method 00240bc0
extern u32 D_0035ec94 asm("D_0035ec94");
/*TARGET 00240bc0*/
void MCard::SetPos(s32 pos) {
    u32 p = D_0035ec94;
    *(u8*)((u32)p + 1) = (u8)pos;
}
}  // Tz

// 00240bd0 (was src/anon/tiny_more.cpp)
namespace n00240bd0 {
extern u32 D_0035ec94 asm("D_0035ec94");
/*TARGET 00240bd0*/
u32 func_00240bd0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00240bd0jjjj");
u32 func_00240bd0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p = D_0035ec94; return (u32)(s32)(*(s8*)((u32)p + (1))); }
}  // namespace n00240bd0

// 00240be0 (was src/tozawa/mcard.cpp)
namespace Tz { // method 00240be0
u32 wtarget_002fde18(u32, u32, u32) asm("_Z16wtarget_002fde18jjjj");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 00240be0*/
u32 MCard::ClearFileInfo() {
    return wtarget_002fde18(((u32)(*(u32*)((u32)((u32)&D_00360000) - 4972u))) + 8u, 0, 0x00000c60u);
}
}  // Tz

// 00240c08 (was src/anon/batch_w2397_nsa.cpp)
namespace n00240c08 {
// Built with -fno-strict-aliasing (_nsa).

struct W2397Sub { s32 a; s32 b; u8 c8; u8 c9; u8 ca; u8 cb; u8 cc; void set9(u8 v) { c9 = v; } void setb(u8 v) { cb = v; } };
struct W2397Ent { s32 x0, x4; u32 fl; s32 xc; W2397Sub s; };
struct W2397Bits64 { u64 lo : 40; u64 hi : 24; };
struct W2397Obj {
    char p0[0xc]; u8 c0c; u8 c0d; char p1[0x2440 - 0xe];
    s32 v2440; s32 v2444; char p2[0x2498 - 0x2448]; u8 c2498; u32 : 0; u32 b249c : 1; u32 : 31;
    char p4[0x24f0 - 0x24a0]; char t24f0[0x4198 - 0x24f0]; u32 w4198; u8 c419c;
};
struct W2397Rec { char p[0xf]; u8 cf; };
s32 func_001058d8(W2397Obj*) asm("func_001058d8");
W2397Rec* func_00188fe0(void*, s32) asm("func_00188fe0");
s32 func_0019f880(u8, u8) asm("func_0019f880");
extern W2397Obj* D_0035ec90 asm("D_0035ec90");
extern W2397Ent* D_0035ec94 asm("D_0035ec94");
#define W2397_ENT(i) ((W2397Ent*)(((i) << 5) + (u32)D_0035ec94))
/*TARGET 00240c08*/
// Copies state flags and properties of object o (default D_0035ec90) into entry i of the D_0035ec94 table.
void func_00240c08(s32 i, W2397Obj* o, u32 fl) asm("func_00240c08");
// Copies state flags and properties of object o (default D_0035ec90) into entry i of the D_0035ec94 table.
void func_00240c08(s32 i, W2397Obj* o, u32 fl) {
    if (o == 0) o = D_0035ec90;
    if ((u8)(fl & 1)) D_0035ec94[i].fl |= 1;
    if (fl & 2) D_0035ec94[i].fl |= 2;
    if (fl & 0x10) {
        D_0035ec94[i].fl |= 0x10;
        D_0035ec94[i].xc = func_0019f880(o->c0d, o->c0c);
        D_0035ec94[i].s.a = o->v2444;
        D_0035ec94[i].s.b = o->v2440;
        D_0035ec94[i].s.c8 = o->c2498;
        if ((u8)o->b249c) W2397_ENT(i)->s.set9(func_00188fe0(o->t24f0, 14)->cf);
        else W2397_ENT(i)->s.set9(func_00188fe0(o->t24f0, 1)->cf);
        if (o->c0c >= 19) D_0035ec94[i].s.ca = 0xff;
        else D_0035ec94[i].s.ca = o->c0c;
        W2397_ENT(i)->s.setb(o->c419c);
        D_0035ec94[i].s.cc = ((W2397Bits64*)&o->w4198)->hi & 1;
        if (func_001058d8(o)) D_0035ec94[i].fl |= 0x10000000;
        else D_0035ec94[i].fl &= ~0x10000000;
    } else if (fl & 0x40) {
        D_0035ec94[i].fl |= 0x40;
    } else {
        D_0035ec94[i].fl |= 0x20;
    }
}
}  // namespace n00240c08

// 00240df8 (was gap)
namespace n00240df8 {
extern u8* D_0035ec94 asm("D_0035ec94");
void func_00240df8(s32 i) asm("func_00240df8");
void func_00240df8(s32 i) { *(s32*)(D_0035ec94 + i * 32 + 8) = 0; }
}  // namespace n00240df8

// 00240e10 (was src/anon/batch_w19.cpp)
namespace n00240e10 {
void func_00240360(void) asm("func_00240360");
void func_00234590(s32, u32, s32, u32, s32) asm("func_00234590");
extern s8* D_0035ec94 asm("D_0035ec94");
extern u32 D_0035ec9c asm("D_0035ec9c");
extern u32 D_0035ec88 asm("D_0035ec88");
/*TARGET 00240e10*/
void func_00240e10(void) asm("func_00240e10");
void func_00240e10(void) {
    func_00240360();
    func_00234590(*D_0035ec94, D_0035ec9c, 99, D_0035ec88, 0);
}
}  // namespace n00240e10

// 00240e50 (was src/anon/batch_w3680_nsa.cpp)
namespace n00240e50 {
struct McName { char c[8]; };
struct McSlot {
    union { s32 v; u8 b; } used;
    u8 pad4[0x14];
    McName name;
};
struct McTable {
    s8 port;
    u8 dirty;
    u8 pad2[3];
    s8 hasSystem;
    u8 pad6[2];
    McSlot slot[99];
};
struct McDirEnt {
    u8 pad0[8];
    McName name;
    u8 pad10[4];
    u16 attr;
    u8 pad16[0xa];
    char fname[0x20];
};
extern McTable* D_0035ec94 asm("D_0035ec94");
extern McDirEnt* D_0035ec9c asm("D_0035ec9c");
extern char D_003716d8[] asm("D_003716d8");
s32 YI_MCARD_GetFileTableMax(s32, s32) asm("_ZN2YI5MCARD15GetFileTableMaxEii");
void func_002fde18(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
s32 strcmp(const char*, const char*) asm("strcmp");
s32 strlen(const char*) asm("strlen");
static inline s32 num2(u8 a, u8 b) { return (a - '0') * 10 + (b - '0'); }
/*TARGET 00240e50*/
s32 func_00240e50(void) asm("func_00240e50");
s32 func_00240e50(void) {
    McDirEnt* ent = D_0035ec9c;
    s32 n = YI_MCARD_GetFileTableMax(D_0035ec94->port, 0);
    s32 i;
    D_0035ec94->hasSystem = 0;
    func_002fde18(D_0035ec94->slot, 0, sizeof(D_0035ec94->slot));
    D_0035ec94->dirty = 0;
    for (i = 0; i < n; i++, ent++) {
        if (ent->attr & 0x20) {
            s32 len = strlen(ent->fname);
            if (len == 18 && strcmp(ent->fname + 0xf, D_003716d8) == 0) {
                D_0035ec94->hasSystem = 1;
            } else if (len == 17) {
                // The empty asm hides that c is a zero-extended byte, so the
                // (u8) conversion for num2 keeps the original's andi 0xff.
                s32 c = ((u8*)ent->fname)[0xf];
                asm("" : "+r"(c));
                if ((u32)(c - '0') < 10) {
                    s32 idx = num2(c, ent->fname[0x10]);
                    D_0035ec94->slot[idx].used.v = 1;
                    D_0035ec94->slot[idx].name = ent->name;
                }
            }
        }
    }
    if (D_0035ec94->hasSystem) n--;
    return n;
}
}  // namespace n00240e50

// 00240fd8 (was src/anon/batch_w7.cpp)
namespace n00240fd8 {
extern u8* D_0035ec94 asm("D_0035ec94");
/*TARGET 00240fd8*/
// 0x002367a0: definition moved into src/anon/unit_00236180.cpp

// ORs bits into the flags of entry i (32-byte records); i < 0 means current.
void func_00240fd8(s32 i, u32 bits) asm("func_00240fd8");
// 0x002367a0: definition moved into src/anon/unit_00236180.cpp

// ORs bits into the flags of entry i (32-byte records); i < 0 means current.
void func_00240fd8(s32 i, u32 bits) {
    if (i < 0) i = (s8)D_0035ec94[1];
    *(u32*)(D_0035ec94 + i * 32 + 8) |= bits;
}
}  // namespace n00240fd8

// 00241008 (was src/anon/batch_w95.cpp)
namespace n00241008 {
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
struct DirEnt { u8 pad0[16]; u32 size; u16 attr; u8 pad22[10]; char name[32]; };
struct SaveRec { u32 type; u32 size; char name[32]; };
struct SaveList { s32 n; u32 pad; SaveRec rec[1]; };
struct SaveSel { s8 a, b; };
extern SaveSel* D_0035ec94 asm("D_0035ec94");
extern SaveList* D_0035ec98 asm("D_0035ec98");
extern DirEnt* D_0035ec9c asm("D_0035ec9c");
extern char D_003716e0[] asm("D_003716e0");
extern char D_003716e8[] asm("D_003716e8");
void func_00240360(s32) asm("func_00240360");
s32 func_002349c8(s32, u32) asm("func_002349c8");
void func_002fde18(void*, s32, u32) asm("func_002fde18");
s32 strcmp(const char*, const char*) asm("strcmp");
// strcmp
void func_002ff2e8(char*, const char*) asm("func_002ff2e8");
/*TARGET 00241008*/
// Build the list of save files from the directory listing (skipping "." and "..").
s32 func_00241008(void) asm("func_00241008");
// Build the list of save files from the directory listing (skipping "." and "..").
s32 func_00241008(void) {
    DirEnt* e = D_0035ec9c;
    func_00240360(D_0035ec94->b);
    s32 n = func_002349c8(D_0035ec94->a, 0);
    func_002fde18(D_0035ec98, 0, 4);
    D_0035ec98->n = n;
    for (s32 i = 0; i < n; i++, e++) {
        if (strcmp(e->name, D_003716e0) && strcmp(e->name, D_003716e8)) {  // strcmp
            func_002ff2e8(D_0035ec98->rec[i].name, e->name);
            if (e->attr & 0x20) D_0035ec98->rec[i].type = 1;
            else D_0035ec98->rec[i].type = 2;
            D_0035ec98->rec[i].size = e->size;
        }
    }
    return n;
}
}  // namespace n00241008

// 00241160 (was src/anon/batch_w3793.cpp)
namespace n00241160 {
struct Ent { u32 flags; s32 id; char name[32]; };
struct EntX { u32 pad[2]; u32 flags; s32 id; char name[32]; };
struct Tbl { s32 count; s32 pad; Ent e[1]; };
s32 func_00240108() asm("func_00240108");
s32 func_002416d8(s32) asm("func_002416d8");
s32 strcmp(const char*, const char*) asm("strcmp");
s32 strlen(const char*) asm("strlen");
extern char* D_0035ebf8 asm("D_0035ebf8");
extern char* D_0035ebfc asm("D_0035ebfc");
extern char* D_0035ec00 asm("D_0035ec00");
extern char* D_0035ec88 asm("D_0035ec88");
extern Tbl* D_0035ec98 asm("D_0035ec98");
/*TARGET 00241160*/
s32 func_00241160(void) asm("func_00241160");
s32 func_00241160(void) {
    s32 i;
    s32 r = 0;
    s32 n = D_0035ec98->count;
    for (i = 0; i < n; i++) {
        s32 off = (i * 5) << 3;
        if (!(((EntX*)(off + (u32)D_0035ec98))->flags & 2)) continue;
        if (strlen(((EntX*)(off + (u32)D_0035ec98))->name) == 0) continue;
        if (strcmp(((EntX*)((u32)D_0035ec98 + off))->name, D_0035ebf8) == 0) {
            r |= 1;
            EntX* e = ((EntX*)(off + (u32)D_0035ec98));
            s32 k = 0x3c4;
            if (e->id != k) {
                r |= 0x100;
                e->flags |= 0x10;
            }
        } else {
            const char* s;
            if (func_00240108()) s = D_0035ec00; else s = D_0035ebfc;
            if (strcmp(D_0035ec98->e[i].name, s) == 0) {
                r |= 2;
                if (D_0035ec98->e[i].id != 0x8a58) {
                    r |= 0x200;
                    D_0035ec98->e[i].flags |= 0x10;
                }
            } else if (strcmp(D_0035ec98->e[i].name, D_0035ec88) == 0) {
                r |= 4;
                if (D_0035ec98->e[i].id != func_002416d8(2)) {
                    r |= 0x400;
                    D_0035ec98->e[i].flags |= 0x10;
                }
            } else {
                r |= 0x10;
                D_0035ec98->e[i].flags |= 0x10;
            }
        }
    }
    return r;
}
}  // namespace n00241160

// 00241320 (was src/anon/batch_w16.cpp)
namespace n00241320 {
void func_002fde18(void*, u32, u32) asm("func_002fde18");
extern u8* D_0035ec98 asm("D_0035ec98");
/*TARGET 00241320*/
// Clears the current 40-byte slot.
void func_00241320(void) asm("func_00241320");
// Clears the current 40-byte slot.
void func_00241320(void) {
    u8* p = D_0035ec98;
    func_002fde18(p + *(s32*)(p + 4) * 40 + 8, 0, 40);
}
}  // namespace n00241320

// 00241358 (was src/anon/batch_w58.cpp)
namespace n00241358 {
// 0x00228240: definition moved into src/anon/unit_00224780.cpp

// Selects the first entry flagged 0x10 and copies its name; returns its index or -1.
struct Ent40 { u32 flags; u32 pad; u8 name[32]; };
struct Tbl40 { s32 n; s32 cur; Ent40 e[1]; };
extern union { Tbl40* p; s32 i; } D_0035ec98 asm("D_0035ec98");
extern union { u32 v; u8 c; } D_0035ec88 asm("D_0035ec88");
void func_002ff2e8(u32, void*) asm("func_002ff2e8");
/*TARGET 00241358*/
s32 func_00241358(void) asm("func_00241358");
s32 func_00241358(void) {
    s32 n = D_0035ec98.p->n;
    s32 i;
    for (i = 0; i < n; i++) {
        if (D_0035ec98.p->e[i].flags & 0x10) {
            D_0035ec98.p->cur = i;
            func_002ff2e8(D_0035ec88.v, D_0035ec98.p->e[i].name);
            break;
        }
    }
    return i < n ? i : -1;
}
}  // namespace n00241358

// 002413f0 (was src/anon/batch_w40.cpp)
namespace n002413f0 {
union U241 { u32 w; u8 b; };
struct E241 { U241 f; u8 pad[28]; };
struct T241 { s8 f0; s8 start; u8 pad[6]; E241 e[99]; };
extern T241* D_0035ec94 asm("D_0035ec94");
static inline bool e241_off(E241* e) { return !(e->f.b & 1); }
/*TARGET 002413f0*/
// First entry from start that is enabled and not busy, or -1.
s32 func_002413f0(void) asm("func_002413f0");
// First entry from start that is enabled and not busy, or -1.
s32 func_002413f0(void) {  // find_next_free_slot
    T241* t = D_0035ec94;
    s32 i;
    for (i = t->start; i < 99; i++) {
        if (e241_off(&t->e[i])) continue;
        if (!(t->e[i].f.w & 2)) break;
    }
    return i < 99 ? i : -1;
}
}  // namespace n002413f0

// 00241450 (was src/tozawa/mcard.cpp)
namespace Tz { // method 00241450
extern u32 D_0035ec94 asm("D_0035ec94");
extern u32 D_0035ec88 asm("D_0035ec88");
extern u32 D_0035ec8c asm("D_0035ec8c");
void strlen(...) asm("strlen");
// strlen
extern "C" void func_002feee8(...) asm("func_002feee8");
u32 func_00234630(...) asm("func_00234630");
/*TARGET 00241450*/
u32 MCard::ChgDir(s32 doSync) {
    u32 t5 = D_0035ec8c;
    *(u8*)(t5 + 0) = 47;
    u32 t6 = D_0035ec8c;
    *(u8*)(t6 + 1) = 0;
    if (doSync == 0) {
        strlen(D_0035ec88);  // strlen
        func_002feee8(D_0035ec8c, D_0035ec88);
    }
    u8* q = (u8*)D_0035ec94;
    return func_00234630((s32)*(s8*)(q + 0), D_0035ec8c, 0);
}
}  // Tz

// 002414c0 (was src/tozawa/mcard.cpp)
namespace Tz { // method 002414c0
extern u32 D_0035ec94 asm("D_0035ec94");
extern u32 D_0035ec88 asm("D_0035ec88");
extern u32 D_0035ec8c asm("D_0035ec8c");
void strlen(...) asm("strlen");
// strlen
extern "C" void func_002feee8(...) asm("func_002feee8");
u32 func_00234650(...) asm("func_00234650");
/*TARGET 002414c0*/
u32 MCard::MakeDir() {
    strlen(D_0035ec88);  // strlen
    u32 t5 = D_0035ec8c;
    *(u8*)(t5 + 0) = 47;
    u32 t6 = D_0035ec8c;
    *(u8*)(t6 + 1) = 0;
    func_002feee8(D_0035ec8c, D_0035ec88);
    u8* p = (u8*)D_0035ec94;
    return func_00234650((s32)*(s8*)(p + 0), D_0035ec8c, 0);
}
}  // Tz

// 00241528 (was src/anon/batch_w15.cpp)
namespace n00241528 {
void strlen(u32) asm("strlen");
// strlen
void func_002346a0(s32, u32, u32) asm("func_002346a0");
extern u32 D_0035ec88 asm("D_0035ec88");
extern s8* D_0035ec94 asm("D_0035ec94");
/*TARGET 00241528*/
void func_00241528(void) asm("func_00241528");
void func_00241528(void) {
    strlen(D_0035ec88);  // strlen
    func_002346a0(*D_0035ec94, D_0035ec88, 0);
}
}  // namespace n00241528

// 00241568 (was src/anon/batch_w12.cpp)
namespace n00241568 {
void func_00234670(s32, u32, s32, s32, s32) asm("func_00234670");
extern s8* D_0035ec94 asm("D_0035ec94");
extern u32 D_0035ec88 asm("D_0035ec88");
/*TARGET 00241568*/
// 0x002375b0: definition moved into src/anon/unit_00237068.cpp

void func_00241568(void) asm("func_00241568");
// 0x002375b0: definition moved into src/anon/unit_00237068.cpp

void func_00241568(void) {
    func_00234670(*D_0035ec94, D_0035ec88, 0, 0, 0);
}
}  // namespace n00241568

// 002415a0 (was src/anon/batch_w40.cpp)
namespace n002415a0 {
union U241 { u32 w; u8 b; };
struct E241 { U241 f; u8 pad[28]; };
struct T241 { s8 f0; s8 start; u8 pad[6]; E241 e[99]; };
extern T241* D_0035ec94 asm("D_0035ec94");
u32 func_002416d8(u32) asm("func_002416d8");
void func_002346c0(s32, u32, u32, u32, u32) asm("func_002346c0");
extern u32 D_0035ec88 asm("D_0035ec88");
extern u32 D_0035ec90 asm("D_0035ec90");
/*TARGET 002415a0*/
void func_002415a0(u32 a, u32 b, u32 c) asm("func_002415a0");
void func_002415a0(u32 a, u32 b, u32 c) {
    u32 v = func_002416d8(a);
    T241* t = D_0035ec94;
    u32 bb = b ? b : D_0035ec88;
    u32 cc = c ? c : D_0035ec90;
    func_002346c0(t->f0, bb, cc, v, 0);
}
}  // namespace n002415a0

// 00241608 (was src/anon/batch_w41.cpp)
namespace n00241608 {
// 0022b558: moved to src/sasa/musical_target.cpp (linked unit)

u32 func_002416d8(u32, u32, u32) asm("func_002416d8");
void func_002346f0(s32, u32, u32, u32, u32) asm("func_002346f0");
extern s8* D_0035ec94 asm("D_0035ec94");
extern u32 D_0035ec88 asm("D_0035ec88");
extern u32 D_0035ec90 asm("D_0035ec90");
/*TARGET 00241608*/
void func_00241608(u32 a, u32 b, u32 c) asm("func_00241608");
void func_00241608(u32 a, u32 b, u32 c) {
    u32 v = func_002416d8(a, b, c);
    s8* s = D_0035ec94;
    u32 x = b;
    if (!x) x = D_0035ec88;
    u32 y = c;
    if (!y) y = D_0035ec90;
    func_002346f0(*s, x, y, v, 0);
}
}  // namespace n00241608

// 00241670 (was src/anon/batch_w33.cpp)
namespace n00241670 {
// 0x00236d10: definition moved into src/anon/unit_00236180.cpp

void func_00242408(void) asm("func_00242408");
// set_global_crc_m1
u32 func_00242418(void*, u32) asm("func_00242418");
// crc_byte_update
extern void* D_0035ec90 asm("D_0035ec90");
/*TARGET 00241670*/
s32 func_00241670(void* a) asm("func_00241670");
s32 func_00241670(void* a) {
    func_00242408();  // set_global_crc_m1
    u32 x = func_00242418(a, 0x8a58);  // crc_byte_update
    func_00242408();  // set_global_crc_m1
    return x == func_00242418(D_0035ec90, 0x8a58);  // crc_byte_update
}
}  // namespace n00241670

// 002416c8 (was gap)
namespace n002416c8 {
extern s32 D_0035ec90 asm("D_0035ec90");
s32 func_002416c8(void) asm("func_002416c8");
s32 func_002416c8(void) { return D_0035ec90; }
}  // namespace n002416c8

// 002416d8 (was src/anon/auto80_199_queue.cpp)
namespace n002416d8 {
/*TARGET 002416d8*/
u32 func_002416d8(u32 a0) asm("_Z13func_002416d8j");
u32 func_002416d8(u32 a0) {
    u32 s16 = 964;
    if (a0 != 0) {
        u32 s17 = 1;
        s16 = 0x8A58;
        if (a0 != s17) {
            s16 = 0x10FC0;
            if (func_00240108() == s17) {  // get_global_36eb68
                s16 = 1024;
            } else {
                u32 v0 = func_00240108();  // get_global_36eb68
                if (v0 == 2) {
                    s16 = 1024;
                }
            }
        }
    }
    return s16;
}
}  // namespace n002416d8

// 00241740 (was src/anon/batch_w8.cpp)
namespace n00241740 {
void func_00240c08(s32, u32, u32) asm("func_00240c08");
extern s8* D_0035ec94 asm("D_0035ec94");
/*TARGET 00241740*/
void func_00241740(s32 x) asm("func_00241740");
void func_00241740(s32 x) {
    if (x < 0) x = D_0035ec94[1];
    func_00240c08(x, 0, 19);
}
}  // namespace n00241740

// 00241770 (was src/anon/batch_w9.cpp)
namespace n00241770 {
extern u8* D_0035ec94 asm("D_0035ec94");
/*TARGET 00241770*/
u32 func_00241770(s32 i) asm("func_00241770");
u32 func_00241770(s32 i) {
    if (i < 0) i = (s8)D_0035ec94[1];
    return (*(s32*)(D_0035ec94 + i * 32 + 8) >> 4) & 1;
}
}  // namespace n00241770

// 002417a0 (was src/anon/batch_wcx2.cpp)
namespace n002417a0 {
// --------------------
struct E2417a0 { u8 pad[8]; u32 f8; u8 pad2[20]; };
struct T2417a0 { u8 pad[2]; s16 lim; u8 pad4; s8 b5; };
union G2417a0 { T2417a0* p; u32 u; };
extern G2417a0 D_0035ec94 asm("D_0035ec94");
s32 func_002408d0(s32) asm("func_002408d0");
/*TARGET 002417a0*/
void func_002417a0() asm("func_002417a0");
void func_002417a0()
{
    T2417a0* t = D_0035ec94.p;
    if (t == 0) return;
    s16 lim = t->lim;
    if (lim < 0) return;
    if (t->b5) {
        if (lim >= func_002408d0(1)) return;
    } else {
        if (lim >= func_002408d0(0)) return;
    }
    {
        for (s32 i = 0; i < 99; i++) {
            E2417a0* e = (E2417a0*)D_0035ec94.p;
            if (e[i].f8 == 0) e[i].f8 = 64;
        }
    }
}
}  // namespace n002417a0

// 00241850 (was src/anon/batch_w44.cpp)
namespace n00241850 {
void func_002fde18(void*, s32, s32) asm("func_002fde18");
// 0022bb60: moved to src/sasa/event_movie.cpp (linked unit)

struct B8 { u8 b[8]; };
extern u8* D_0035ec9c asm("D_0035ec9c");
extern u8* D_0035ec94 asm("D_0035ec94");
/*TARGET 00241850*/
void func_00241850(s32 i, s32 clear) asm("func_00241850");
void func_00241850(s32 i, s32 clear) {
    u8* s = D_0035ec9c;
    if (clear) func_002fde18(D_0035ec94 + i * 32 + 32, 255, 8);
    else *(B8*)(i * 32 + D_0035ec94 + 32) = *(B8*)(s + 8);
}
}  // namespace n00241850

// 002418b8 (was src/anon/batch_w99.cpp)
namespace n002418b8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V13f6 {
    f32 x, y, z, w;
    V13f6() {}
    V13f6(const V13f6& o) { QCOPY(this, &o); }
    V13f6& operator=(const V13f6& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
    V13f6& operator*=(f32 s)
    {
        asm("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V13f6& operator+=(const V13f6& o)
    {
        asm("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V13f6 operator-(const V13f6& a, const V13f6& b)
{
    V13f6 r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Date2418 { u8 pad; u8 sec; u8 min; u8 hour; u8 day; u8 month; u16 year; };
struct Ent2418 { u32 flags; u8 pad[20]; Date2418 date; };
struct T2418 { u8 pad[8]; Ent2418 e[99]; };
extern T2418* D_0035ec94 asm("D_0035ec94");
static inline __attribute__((always_inline)) s32 Older2418(const Date2418* a, const Ent2418* e)
{
    s32 r = 0;
    if (a->year > e->date.year) ;
    else if (a->year < e->date.year) r = 1;
    else if (a->month > e->date.month) ;
    else if (a->month < e->date.month) r = 1;
    else if (a->day > e->date.day) ;
    else if (a->day < e->date.day) r = 1;
    else if (a->hour > e->date.hour) ;
    else if (a->hour < e->date.hour) r = 1;
    else if (a->min > e->date.min) ;
    else if (a->min < e->date.min) r = 1;
    else if (a->sec > e->date.sec) ;
    else if (a->sec < e->date.sec) r = 1;
    return r;
}
/*TARGET 002418b8*/
// Returns the index of the newest valid entry (0 if none).
s32 func_002418b8(void) asm("func_002418b8");
// Returns the index of the newest valid entry (0 if none).
s32 func_002418b8(void)
{
    Date2418 best;
    s32 found = -1;
    s32 i;
    Ent2418* e = D_0035ec94->e;
    for (i = 0; i < 99; i++, e++) {
        if (!(e->flags & 0x10)) continue;
        if (found < 0 || Older2418(&best, e)) {
            best = e->date;
            found = i;
        }
    }
    if (found < 0) found = 0;
    return found;
}
}  // namespace n002418b8

// 002419d0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002419d0 {
/*TARGET 002419d0*/
void func_002419d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002419d0jjjj");
void func_002419d0(u32 a0, u32 a1, u32 a2, u32 a3) {  // store_global_bool_converted
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r15 = (u32)(0x0036u << 16);
    r4 = ((u32)0u < (u32)r4);
    r14 = *(u32*)((u32)r15 + (s32)(-4972));
    *(u8*)((u32)r14 + (s32)(4)) = (u8)r4;
}
}  // namespace n002419d0

// 002419e8 (was src/anon/tiny_more2.cpp)
namespace n002419e8 {
extern u32 D_0035ec94 asm("D_0035ec94");
/*TARGET 002419e8*/
u32 func_002419e8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_002419e8jjjj");
u32 func_002419e8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p=D_0035ec94; s32 v=*(s8*)((u32)p + (4)); return (v != 0); }
}  // namespace n002419e8

// 00241a00 (was src/anon/batch_w29.cpp)
namespace n00241a00 {
extern u8* D_0035ec94 asm("D_0035ec94");
/*TARGET 00241a00*/
// 0022aef0: moved to src/sasa/musical_input.cpp (linked unit)

// Any of the 99 32-byte entries has flag 0x10 set.
u32 func_00241a00(void) asm("func_00241a00");
// 0022aef0: moved to src/sasa/musical_input.cpp (linked unit)

// Any of the 99 32-byte entries has flag 0x10 set.
u32 func_00241a00(void) {
    u32 r = 0;
    u32* p = (u32*)(D_0035ec94 + 8);
    for (s32 i = 0; i < 99; i++) {
        if (*p & 0x10) { r = 1; break; }
        p += 8;
    }
    return r;
}
}  // namespace n00241a00

// 00241a48 (was src/tozawa/mcard.cpp)
namespace Tz { // method 00241a48
extern u32 D_0035ec94 asm("D_0035ec94");
/*TARGET 00241a48*/
bool MCard::isFindSystem() {
    u32 p = D_0035ec94;
    s32 v = *(s8*)((u32)p + 5);
    return v != 0;
}
}  // Tz

// 00241a60 (was src/anon/tiny.cpp)
namespace n00241a60 {
extern u32 D_0035ec94 asm("D_0035ec94");
/*TARGET 00241a60*/
void func_00241a60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00241a60jjjj");
void func_00241a60(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    *(u8*)((u32)D_0035ec94 + (5)) = 0;
}
}  // namespace n00241a60

// 00241a70 (was src/anon/tiny_more2.cpp)
namespace n00241a70 {
extern u32 D_0035ec94 asm("D_0035ec94");
/*TARGET 00241a70*/
void func_00241a70(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00241a70jjjj");
void func_00241a70(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 p=D_0035ec94; *(u8*)((u32)p + (5)) = (u8)((u32)((s32)1)); }
}  // namespace n00241a70

// 00241a88 (was src/anon/batch_w283.cpp)
namespace n00241a88 {
struct W283_FE { u8 pad[16]; s32 size; u16 attr; u8 pad2[10]; char name[32]; };
extern char* D_0035ec88 asm("D_0035ec88");
extern W283_FE* D_0035ec9c asm("D_0035ec9c");
extern s8* D_0035ec94 asm("D_0035ec94");
extern char* D_0035ebf8 asm("D_0035ebf8");
extern char* D_0035ec00 asm("D_0035ec00");
extern char* D_0035ec08 asm("D_0035ec08");
extern char D_003716e0[] asm("D_003716e0");
extern char D_003716e8[] asm("D_003716e8");
s32 strcmp(const char*, const char*) asm("strcmp");
// strcmp
void func_00240118(char*, s32, s32) asm("func_00240118");
s32 W283_GetFileTableMax(s32, s32) asm("_ZN2YI5MCARD15GetFileTableMaxEii");
/*TARGET 00241a88*/
s32 func_00241a88(u8 a) asm("func_00241a88");
s32 func_00241a88(u8 a) {
    W283_FE* e = D_0035ec9c;
    u32 got = 0;
    func_00240118(D_0035ec88, 0, a ? 1 : 2);
    s32 n = W283_GetFileTableMax(*D_0035ec94, 0);
    if (n < 3) return 0;
    for (s32 i = 0; i < n; i++, e++) {
        if (strcmp(e->name, D_003716e0) == 0) continue;
        if (strcmp(e->name, D_003716e8) == 0) continue;
        if (e->attr & 0x20) continue;
        if (strcmp(e->name, D_0035ec88) == 0) {  // strcmp
            if (e->size == 1024) got |= 4;
        } else if (strcmp(e->name, D_0035ebf8) == 0) {  // strcmp
            if (e->size == 964) got |= 1;
        } else if (strcmp(e->name, !a ? D_0035ec08 : D_0035ec00) == 0) {  // strcmp
            if (e->size == 0x8a58) got |= 2;
        }
    }
    return got == 7;
}
}  // namespace n00241a88

// 00241c20 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00241c20 {
/*TARGET 00241c20*/
u32 func_00241c20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00241c20jjjj");
u32 func_00241c20(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = (u32)(0x0036u << 16);
    r4 = (u32)(r4 << 5);
    r14 = *(u32*)((u32)r15 + (s32)(-4972));
    r4 = (u32)(r4 + r14);
    r2 = *(u32*)((u32)r4 + (s32)(8));
    r2 = (u32)((s32)r2 >> 5);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // namespace n00241c20

