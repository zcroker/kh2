// Linked unit 0x002584c8-0x002586e0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_pause.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tz/ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 002584c8 (was src/anon/batch_w81.cpp)
namespace n002584c8 {
// --- 002584c8: create the global object (inlined constructors) and set it up
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8* D_0035f078 asm("D_0035f078");
extern u32 D_0035f074 asm("D_0035f074");
extern u32 D_0035f080 asm("D_0035f080");
extern u32 D_0035f084 asm("D_0035f084");
u8* func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(u8*) asm("func_0031a838");
void func_002369a0(u8*) asm("func_002369a0");
// obj_ctor_36eac8
void func_0023c008(u8*) asm("func_0023c008");
// obj_ctor_36eae8
u32 func_0023f948(u32, u32) asm("func_0023f948");
u32 func_0023f908(u32, u32) asm("func_0023f908");
void func_0023eea0(u8*, u32, u32, u32, u32, u32) asm("func_0023eea0");
void func_0023f0c8(u8*, s32) asm("func_0023f0c8");
void func_0023ef50(u8*) asm("func_0023ef50");
void func_0026dd18(u32, u32, s32) asm("func_0026dd18");
/*TARGET 002584c8*/
// store_session_globals
void func_002584c8(void) asm("func_002584c8");
// store_session_globals
void func_002584c8(void) {
    u8* p = func_0023ee30(160);
    *(u32*)p = (u32)D_00347f98;
    func_0031a838(p + 12);
    *(u32*)p = (u32)D_0035eb98;
    func_002369a0(p + 24);  // obj_ctor_36eac8
    func_0023c008(p + 48);  // obj_ctor_36eae8
    D_0035f078 = p;
    u32 a = func_0023f948(D_0035f074, 0);
    func_0023eea0(D_0035f078, 30000, a, func_0023f908(D_0035f074, 0), 0, 0);
    func_0023f0c8(D_0035f078, -1);
    func_0023ef50(D_0035f078);
    func_0026dd18(D_0035f080, D_0035f084, -1);  // store_session_globals
}
}  // namespace n002584c8

// 002585a0 (was src/anon/perm_002585a0.cpp)
namespace n002585a0 {
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
struct P
{
  u8 pad[3];
  u8 b3;
  u8 pad2[0x10];
  s16 h14;
};
extern P *D_0035f080 asm("D_0035f080");
extern s32 D_0035f084 asm("D_0035f084");
extern s16 D_0035f06c asm("D_0035f06c");
extern u8 D_0035f069 asm("D_0035f069");
void func_002588e8(s32) asm("func_002588e8");
void func_0026dd18(P *, s32, s32) asm("func_0026dd18");
/*TARGET 002585a0*/
void func_002585a0(void) asm("func_002585a0");
void func_002585a0(void)
{
  s16 new_var2;
  s16 new_var;
  if (D_0035f080 != 0)
  {
    P **pp;
 do { new_var2 = D_0035f06c; } while (0);
    if (new_var2 == 9)
    {
      new_var = D_0035f080->h14;
      func_002588e8(new_var = new_var);
      new_var2 = 1;
      func_0026dd18(*(&D_0035f080), D_0035f084, (D_0035f069) ? (-new_var2) : (D_0035f080->b3));
    }
  }
  D_0035f069 = 0;
}
}  // namespace n002585a0

// 00258630 (was src/anon/batch_w1593.cpp)
namespace n00258630 {
// ---- 00258630
struct MenuMode1593 { u32 a; u32 list; };
MenuMode1593* getMenuMode1593() asm("_Z11getMenuModev");
s32 func_00102a38(u32, u32) asm("func_00102a38");
void func_00102818(u32, u32, u32, u32, u32) asm("func_00102818");
void func_001039f8() asm("func_001039f8");
void func_002530c8() asm("func_002530c8");
void func_00258a30() asm("func_00258a30");
void func_00287ad0() asm("func_00287ad0");
s32 func_00287db0() asm("func_00287db0");
extern u8 D_002586e0[] asm("D_002586e0");
extern s16 D_0035f06c asm("D_0035f06c");
/*TARGET 00258630*/
s32 func_00258630(void) asm("func_00258630");
s32 func_00258630(void) {
    u32 list = getMenuMode1593()->list;
    u32 key = (u32)D_002586e0;
    if (func_00102a38(list, key)) return 0;
    if (D_0035f06c < 0) {
        func_00258a30();
        func_001039f8();
        return 1;
    }
    if (func_00287db0()) func_00287ad0();
    func_002530c8();
    func_00102818(getMenuMode1593()->list, 0, 1999, key, 0x1000);
    return 0;
}
}  // namespace n00258630

