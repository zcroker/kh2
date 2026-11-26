// Linked unit (see linked_units.tsv); one namespace per old matched source.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 002b9ab8 (was src/anon/tiny.cpp)
namespace n002b9ab8 {
void func_002b6b84(void*) asm("_Z13func_002b6b84Pv");
/*TARGET 002b9ab8*/
// 00290708: moved to src/anon/unit_0028f1e0.cpp
void func_002b9ab8(BD_VALUE* bd) asm("_Z13func_002b9ab8P8BD_VALUE");
// 00290708: moved to src/anon/unit_0028f1e0.cpp
void func_002b9ab8(BD_VALUE* bd) { func_002b6b84(bd); }
}  // namespace n002b9ab8

// 002b9ad0 (was src/anon/batch_wcx.cpp)
namespace n002b9ad0 {
// 0x002b2428: definition moved into src/anon/unit_002b1db8.cpp
extern u8 D_01e2a410[] asm("D_01e2a410");
extern u32 D_003616e0 asm("D_003616e0");
extern u32 D_01e2a400[3] asm("D_01e2a400");
void func_002b7fbc(s32) asm("func_002b7fbc");
void func_002b6bc4(s32) asm("func_002b6bc4");
void func_002b9ab8(s32) asm("func_002b9ab8");
void func_002ba298(s32) asm("func_002ba298");
void func_002ba390(void) asm("func_002ba390");
void func_002bce40(u8*) asm("func_002bce40");
void SE_BANK__clearField(u8*) asm("SE_BANK__clearField");
void func_002b9b78(void) asm("func_002b9b78");
void func_002bd218(void) asm("func_002bd218");
void u_tail0_002b9ad0(void) asm("_Z16u_tail0_002b9ad0v");
/*TARGET 002b9ad0*/
void u_tail0_002b9ad0(void) asm("_Z16u_tail0_002b9ad0v");
void u_tail0_002b9ad0(void)
{
    func_002b7fbc(0);
    func_002b6bc4(1);
    func_002b9ab8(20);
    func_002ba298(0);
    func_002ba298(1);
    func_002ba390();
    func_002bce40(D_01e2a410);
    SE_BANK__clearField(D_01e2a410);
    func_002b9b78();
    func_002bd218();
    D_003616e0 = 0;
    u32* w = D_01e2a400;
    s32 i = 2;
    do {
        *w = 0;
        i--;
        w++;
    } while (i >= 0);
}
}  // namespace n002b9ad0

// 002b9b78 (was src/anon/batch_w24.cpp)
namespace n002b9b78 {
// 0x00280240: definition moved into src/anon/unit_0027f2b0.cpp

extern u8 D_01e2a410 asm("D_01e2a410");
void func_002bc9a8(void*, s32, s32) asm("func_002bc9a8");
// find_entry12_set_field
void func_002bce10(void*, s32) asm("func_002bce10");
/*TARGET 002b9b78*/
// find_entry12_set_flag
void func_002b9b78(void) asm("func_002b9b78");
// find_entry12_set_flag
void func_002b9b78(void) {
    void* o = &D_01e2a410;
    func_002bc9a8(o, 2, 0);  // find_entry12_set_field
    func_002bce10(o, 2);  // find_entry12_set_flag
    func_002bc9a8(o, 3, 999);  // find_entry12_set_field
    func_002bce10(o, 3);  // find_entry12_set_flag
}
}  // namespace n002b9b78

// 002b9bd0 (was src/anon/batch_w41.cpp)
namespace n002b9bd0 {
void func_002b691c(u32) asm("func_002b691c");
void func_002bbde0(void) asm("func_002bbde0");
void func_002bacc0(void) asm("func_002bacc0");
void func_002b9ad0(void) asm("func_002b9ad0");
void SOUND__initCommonSe(void) asm("SOUND__initCommonSe");
void func_002bd538(void) asm("func_002bd538");
void func_00102788(u32, u32, u32, void (*)(void)) asm("func_00102788");
void func_002b9c60(void) asm("func_002b9c60");
extern u32 D_0032b91c asm("D_0032b91c");
/*TARGET 002b9bd0*/
void wtarget_002b9bd0(u32, u32, u32, u32) asm("_Z16wtarget_002b9bd0jjjj");
void wtarget_002b9bd0(u32, u32, u32, u32) {
    func_002b691c(0);
    func_002bbde0();
    func_002bacc0();
    func_002b9ad0();
    SOUND__initCommonSe();
    func_002bd538();
    func_00102788(D_0032b91c, 0, 0x7a12a, func_002b9c60);
}
}  // namespace n002b9bd0

// 002b9c30 (was src/anon/tiny_auto80.cpp)
namespace n002b9c30 {
u32 func_002bbde0() asm("_Z13func_002bbde0v");
u32 func_002bbe30() asm("_Z13func_002bbe30v");
u32 func_002b691c(u32, u32, u32, u32) asm("_Z13func_002b691cjjjj");
u32 func_002b9ad0() asm("_Z13func_002b9ad0v");
/*TARGET 002b9c30*/
// 0x00224b60: definition moved into src/anon/unit_00224780.cpp

u32 func_002b9c30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002b9c30jjjj");
// 0x00224b60: definition moved into src/anon/unit_00224780.cpp

u32 func_002b9c30(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)0u + (1));
    r2 = func_002b691c(r4, r5, r6, r7);
    r2 = func_002bbe30();
    r2 = func_002bbde0();
    return func_002b9ad0();
}
}  // namespace n002b9c30

// 002b9c60 (gap function, never written before)
namespace n002b9c60 {
void func_002bbf98(void) asm("func_002bbf98");
void func_002b6ab8(void) asm("func_002b6ab8");
void func_002b9c60(void) asm("func_002b9c60");
void func_002b9c60(void) { func_002bbf98(); func_002b6ab8(); }
}  // namespace n002b9c60

// 002b9c80 (was src/anon/perm_002b9c80.cpp)
namespace n002b9c80 {
typedef unsigned char u8;
typedef signed int s32;
s32 func_001688c8(void *) asm("func_001688c8");
s32 func_00170b30(s32) asm("func_00170b30");
void func_001682b8(void *, s32) asm("func_001682b8");
void SOUND__sebTransfer(s32, s32, s32) asm("SOUND__sebTransfer");
void func_002ba188(s32, s32, s32) asm("func_002ba188");
s32 func_002b6f78(void) asm("func_002b6f78");
void func_002b6ab8(void) asm("func_002b6ab8");
void func_00170c00(s32) asm("func_00170c00");
extern u8 D_00374f30[] asm("D_00374f30");
extern u8 D_00374f40[] asm("D_00374f40");
extern u8 D_00374f50[] asm("D_00374f50");
extern u8 D_00374f60[] asm("D_00374f60");
/*TARGET 002b9c80*/
void SOUND__initCommonSe(void) asm("SOUND__initCommonSe");
void SOUND__initCommonSe(void)
{
  s32 new_var;
  s32 size;
  s32 buf;
  s32 p;
  size = func_001688c8(D_00374f30);
  buf = func_00170b30((size + 0x83f) & (~0x7ff));
  p = (buf + 0x3f) & (~0x3f);
  func_001682b8(D_00374f30, p);
  SOUND__sebTransfer(2, p, size);
  while (func_002b6f78())
  {
    func_002b6ab8();
  }

  func_00170c00(buf);
  size = func_001688c8(D_00374f40);
  buf = func_00170b30((size + 0x83f) & (~0x7ff));
  p = (buf + 0x3f) & (~0x3f);
  func_001682b8(D_00374f40, p);
  SOUND__sebTransfer(3, p, size);
  while (func_002b6f78())
  {
    func_002b6ab8();
  }

  func_00170c00(buf);
  size = func_001688c8(D_00374f50);
  buf = func_00170b30((size + 0x83f) & (~0x7ff));
  p = (buf + 0x3f) & (~0x3f);
  func_001682b8(D_00374f50, p);
  func_002ba188(2, p, size);
  while (func_002b6f78())
  {
    func_002b6ab8();
  }

  func_00170c00(buf);
  size = (new_var = func_001688c8(D_00374f60));
  buf = func_00170b30((size + 0x83f) & (~0x7ff));
  p = (buf + 0x3f) & (~0x3f);
  func_001682b8(D_00374f60, p);
  func_002ba188(3, p, new_var);
  while (func_002b6f78())
  {
    func_002b6ab8();
  }

  func_00170c00(buf);
}
}  // namespace n002b9c80

// 002b9e80 (was src/anon/batch_w30.cpp)
namespace n002b9e80 {
void func_002b7fbc(u32) asm("func_002b7fbc");
void func_002bce40(void*) asm("func_002bce40");
void SE_BANK__clearField(void*) asm("SE_BANK__clearField");
void func_002b9b78(void) asm("func_002b9b78");
void func_002ba390(void) asm("func_002ba390");
void func_002b9ed0(void) asm("func_002b9ed0");
extern u8 D_01e2a410[] asm("D_01e2a410");
/*TARGET 002b9e80*/
// 0x002aa048: definition moved into src/anon/unit_002a99c8.cpp

void func_002b9e80(void) asm("func_002b9e80");
// 0x002aa048: definition moved into src/anon/unit_002a99c8.cpp

void func_002b9e80(void) {
    func_002b7fbc(0);
    func_002bce40(D_01e2a410);
    SE_BANK__clearField(D_01e2a410);
    func_002b9b78();
    func_002ba390();
    func_002b9ed0();
}
}  // namespace n002b9e80

// 002b9ed0 (was src/anon/batch_w30.cpp)
namespace n002b9ed0 {
void func_002b9ed0(void) asm("func_002b9ed0");
extern u8 D_01e2a410[] asm("D_01e2a410");
void func_002baa78(void) asm("func_002baa78");
void func_002bcfe8(void*) asm("func_002bcfe8");
void func_002bd030(void*) asm("func_002bd030");
void func_002bd078(void*) asm("func_002bd078");
void func_002bd0b8(void*) asm("func_002bd0b8");
void func_002bd100(void*) asm("func_002bd100");
void func_002bd140(void*) asm("func_002bd140");
/*TARGET 002b9ed0*/
void func_002b9ed0(void) asm("func_002b9ed0");
void func_002b9ed0(void) {
    func_002baa78();
    func_002bcfe8(D_01e2a410);
    func_002bd030(D_01e2a410);
    func_002bd078(D_01e2a410);
    func_002bd0b8(D_01e2a410);
    func_002bd100(D_01e2a410);
    func_002bd140(D_01e2a410);
}
}  // namespace n002b9ed0

// 002b9f28 (was src/anon/batch_w63.cpp)
namespace n002b9f28 {
void func_002b7fbc(s32) asm("func_002b7fbc");
void func_002bc798(void) asm("func_002bc798");
void func_002ba9c0(void) asm("func_002ba9c0");
void func_002bc470(s32) asm("func_002bc470");
void func_002bcf58(void*) asm("func_002bcf58");
void SE_BANK__objectDestroy(void*) asm("SE_BANK__objectDestroy");
void func_002baa60(void) asm("func_002baa60");
void func_002bc608(s32) asm("func_002bc608");
void func_002bbf98(void) asm("func_002bbf98");
extern u8 D_01e2a410 asm("D_01e2a410");
/*TARGET 002b9f28*/
// 0x00298e48: definition moved into src/anon/unit_002982f0.cpp

void SOUND__areaInit(u8 a) asm("SOUND__areaInit");
// 0x00298e48: definition moved into src/anon/unit_002982f0.cpp

void SOUND__areaInit(u8 a) {
    if (a) func_002b7fbc(1);
    else func_002b7fbc(0);
    func_002bc798();
    func_002ba9c0();
    func_002bc470(2);
    func_002bc470(3);
    func_002bcf58(&D_01e2a410);
    SE_BANK__objectDestroy(&D_01e2a410);
    func_002baa60();
    func_002bc608(0);
    func_002bc608(1);
    func_002bc608(2);
    func_002bbf98();
}
}  // namespace n002b9f28

// 002b9fb0 (was src/anon/batch_w58.cpp)
namespace n002b9fb0 {
// 00290960: moved to src/anon/unit_0028f1e0.cpp

void func_002b7fbc(s32) asm("func_002b7fbc");
void func_002bced8(void*) asm("func_002bced8");
void SE_BANK__clearGumi(void*) asm("SE_BANK__clearGumi");
void func_002b9b78(void) asm("func_002b9b78");
void func_002ba390(void) asm("func_002ba390");
void func_002bc798(void) asm("func_002bc798");
void func_002ba9c0(void) asm("func_002ba9c0");
void func_002bc470(s32) asm("func_002bc470");
void func_002baa60(void) asm("func_002baa60");
void func_002bc608(s32) asm("func_002bc608");
void func_002bbf98(void) asm("func_002bbf98");
extern u8 D_01e2a410[] asm("D_01e2a410");
/*TARGET 002b9fb0*/
void func_002b9fb0(void) asm("func_002b9fb0");
void func_002b9fb0(void) {
    func_002b7fbc(1);
    func_002bced8(D_01e2a410);
    SE_BANK__clearGumi(D_01e2a410);
    func_002b9b78();
    func_002ba390();
    func_002bc798();
    func_002ba9c0();
    func_002bc470(2);
    func_002bc470(3);
    func_002baa60();
    func_002bc608(0);
    func_002bc608(1);
    func_002bc608(2);
    func_002bbf98();
}
}  // namespace n002b9fb0

// 002ba040 (was src/anon/batch_w37.cpp)
namespace n002ba040 {
// 0x002b2d48: definition moved into src/anon/unit_002b2a18.cpp

extern u8 D_01e2a410[] asm("D_01e2a410");
void func_002bcfe8(void*) asm("func_002bcfe8");
void func_002bd030(void*) asm("func_002bd030");
void func_002b6adc(u32, s32) asm("func_002b6adc");
/*TARGET 002ba040*/
void func_002ba040(void) asm("func_002ba040");
void func_002ba040(void) {
    func_002bcfe8(D_01e2a410);
    func_002bd030(D_01e2a410);
    for (s32 i = 0; i < 2; i++) {
        func_002b6adc(2, i + 20);
        func_002b6adc(0, i + 20);
    }
}
}  // namespace n002ba040

// 002ba0b0 (was src/anon/batch_w30.cpp)
namespace n002ba0b0 {
extern u8 D_01e2a568[] asm("D_01e2a568");
extern u8 D_00374f70[] asm("D_00374f70");
void func_002fee78(void*, void*, u32) asm("func_002fee78");
void strlen(void*) asm("strlen");
/*TARGET 002ba0b0*/
void* func_002ba0b0(u32 a) asm("func_002ba0b0");
void* func_002ba0b0(u32 a) {
    func_002fee78(D_01e2a568, D_00374f70, a);
    strlen(D_01e2a568);  // strlen
    return D_01e2a568;
}
}  // namespace n002ba0b0

// 002ba0f8 (was src/anon/batch_w31.cpp)
namespace n002ba0f8 {
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
void strlen(char*) asm("strlen");
extern char D_01e2a5a8[] asm("D_01e2a5a8");
extern char D_00374f80[] asm("D_00374f80");
/*TARGET 002ba0f8*/
// 0x002b1aa0: definition moved into src/anon/unit_002b0950.cpp

char* func_002ba0f8(u32 x) asm("func_002ba0f8");
// 0x002b1aa0: definition moved into src/anon/unit_002b0950.cpp

char* func_002ba0f8(u32 x) {
    func_002fee78(D_01e2a5a8, D_00374f80, x);
    strlen(D_01e2a5a8);  // strlen
    return D_01e2a5a8;
}
}  // namespace n002ba0f8

// 002ba140 (was src/anon/batch_w210.cpp)
namespace n002ba140 {
u32 func_002bc608(u32) asm("func_002bc608");
void func_002b6f28(u32, u32, u32) asm("func_002b6f28");
/*TARGET 002ba140*/
// 0x00271828: definition moved into src/anon/unit_002713c8.cpp

void func_002ba140(u32 a, u32 b, u32 c) asm("func_002ba140");
// 0x00271828: definition moved into src/anon/unit_002713c8.cpp

void func_002ba140(u32 a, u32 b, u32 c) {
    func_002bc608(a);
    func_002b6f28(a, b, c);
}
}  // namespace n002ba140

// 002ba188 (was src/anon/tiny_wrappers_more.cpp)
namespace n002ba188 {
u32 func_002b6c44(u32, u32, u32, u32) asm("_Z13func_002b6c44jjjj");
/*TARGET 002ba188*/
// 0x002a9888: definition moved into src/anon/unit_002a92a0.cpp

u32 func_002ba188(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba188jjjj");
// 0x002a9888: definition moved into src/anon/unit_002a92a0.cpp

u32 func_002ba188(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002b6c44(a0, a1, a2, 0x00000000u);
}
}  // namespace n002ba188

// 002ba1a0 (was src/anon/tiny.cpp)
namespace n002ba1a0 {
void func_002b6d34(void*) asm("_Z13func_002b6d34Pv");
/*TARGET 002ba1a0*/
void func_002ba1a0(BD_VALUE* bd) asm("_Z13func_002ba1a0P8BD_VALUE");
void func_002ba1a0(BD_VALUE* bd) { func_002b6d34(bd); }
}  // namespace n002ba1a0

// 002ba1b8 (was src/anon/batch_w57.cpp)
namespace n002ba1b8 {
extern void (**D_0032b914)() asm("D_0032b914");
// 0028d660: moved to src/anon/unit_0028c878.cpp

void func_002bc470(u32) asm("func_002bc470");
void func_002b6e24(u32, u32, u32) asm("func_002b6e24");
/*TARGET 002ba1b8*/
void SOUND__sebTransfer(u32 a, u32 b, u32 c) asm("SOUND__sebTransfer");
void SOUND__sebTransfer(u32 a, u32 b, u32 c) {
    func_002bc470(a);
    func_002b6e24(a, b, c);
}
}  // namespace n002ba1b8

// 002ba200 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002ba200 {
u32 func_002baf38(u32, u32, u32, u32) asm("_Z13func_002baf38jjjj");
/*TARGET 002ba200*/
u32 func_002ba200(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba200jjjj");
u32 func_002ba200(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_002baf38)(u32, u32, u32, u32) = func_002baf38;
    r2 = fp_call4_002baf38(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002ba200

// 002ba220 (was src/anon/batch_w42.cpp)
namespace n002ba220 {
void wtarget_002b7078(void) asm("_Z16wtarget_002b7078jjjj");
// 0x00296b08: definition moved into src/anon/unit_00295d28.cpp

// 002ba220
s32 func_002b7010(u32, u32, u32, u32, u32, u32) asm("func_002b7010");
/*TARGET 002ba220*/
s32 func_002ba220(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) asm("func_002ba220");
s32 func_002ba220(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    wtarget_002b7078();
    return func_002b7010(a, b, c, d, e, f);
}
}  // namespace n002ba220

// 002ba298 (was src/anon/tiny_wrappers_more.cpp)
namespace n002ba298 {
u32 func_002b7078(u32, u32, u32, u32) asm("_Z13func_002b7078jjjj");
/*TARGET 002ba298*/
u32 func_002ba298(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba298jjjj");
u32 func_002ba298(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002b7078(a0, a1, a2, a3);
}
}  // namespace n002ba298

// 002ba2b0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002ba2b0 {
u32 func_002b70b8(u32, u32, u32, u32) asm("_Z13func_002b70b8jjjj");
/*TARGET 002ba2b0*/
u32 func_002ba2b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba2b0jjjj");
u32 func_002ba2b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002b70b8(a1, 0x00000000u, a0, a3);
}
}  // namespace n002ba2b0

// 002ba2d0 (was src/anon/tiny.cpp)
namespace n002ba2d0 {
void func_002b7108(void*) asm("_Z13func_002b7108Pv");
/*TARGET 002ba2d0*/
void func_002ba2d0(BD_VALUE* bd) asm("_Z13func_002ba2d0P8BD_VALUE");
void func_002ba2d0(BD_VALUE* bd) { func_002b7108(bd); }
}  // namespace n002ba2d0

// 002ba2e8 (was src/anon/batch_w8.cpp)
namespace n002ba2e8 {
// 0x0028c170: definition moved into src/anon/unit_0028bfc0.cpp

void func_002b726c(u32, s32, s32, u32, u32) asm("func_002b726c");
void sound_system_se_play(s32 a, s32 b) asm("_ZN5SOUND12systemSePlayEii");
/*TARGET 002ba2e8*/
void sound_system_se_play(s32 a, s32 b) asm("_ZN5SOUND12systemSePlayEii");
void sound_system_se_play(s32 a, s32 b) {
    func_002b726c(2, a, b, 16383, 64);
}
}  // namespace n002ba2e8

// 002ba310 (was src/anon/tiny_wrappers_more.cpp)
namespace n002ba310 {
u32 func_002b72e4(u32, u32, u32, u32) asm("_Z13func_002b72e4jjjj");
/*TARGET 002ba310*/
u32 func_002ba310(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba310jjjj");
u32 func_002ba310(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002b72e4(0x00000002u, a0, a1, a3);
}
}  // namespace n002ba310

// 002ba330 (was src/anon/batch_w2.cpp)
namespace n002ba330 {
void func_002b73ac(u32, u32, u32, u32, u32) asm("func_002b73ac");
/*TARGET 002ba330*/
// 0x0029df98: definition moved into src/anon/unit_0029d008.cpp

void func_002ba330(u32 a0, u32 a1, u32 a2) asm("func_002ba330");
// 0x0029df98: definition moved into src/anon/unit_0029d008.cpp

void func_002ba330(u32 a0, u32 a1, u32 a2) {
    func_002b73ac(2, a0, a2, (u32)-1, a1);
}
}  // namespace n002ba330

// 002ba358 (was src/ohori/sound.cpp)
namespace n002ba358 {
u32 isSeAlertPlay() asm("_ZN5SOUND13isSeAlertPlayEv");
/*TARGET 002ba358*/
u32 isSeAlertPlay() asm("_ZN5SOUND13isSeAlertPlayEv");
u32 isSeAlertPlay() {
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + 5860));
}
}  // namespace n002ba358

// 002ba368 (was src/anon/tiny_wrappers_imp.cpp)
namespace n002ba368 {
u32 func_002ba2e8(u32, u32, u32, u32) asm("_Z13func_002ba2e8jjjj");
/*TARGET 002ba368*/
u32 func_002ba368(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba368jjjj");
u32 func_002ba368(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = (u32)((s32)0u + (1));
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(5860)) = (u8)r14;
    r4 = (u32)((s32)0u + (9));
    r5 = 0u;
    return func_002ba2e8(r4, r5, r6, r7);
}
}  // namespace n002ba368

// 002ba390 (was src/anon/tiny_wrappers_imp.cpp)
namespace n002ba390 {
u32 func_002ba330(u32, u32, u32, u32) asm("_Z13func_002ba330jjjj");
/*TARGET 002ba390*/
u32 func_002ba390(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba390jjjj");
u32 func_002ba390(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0036u << 16);
    r4 = (u32)((s32)0u + (9));
    *(u8*)((u32)r15 + (s32)(5860)) = (u8)0u;
    r5 = (u32)((s32)0u + (60));
    r6 = 0u;
    return func_002ba330(r4, r5, r6, r7);
}
}  // namespace n002ba390

// 002ba3b8 (was src/anon/batch_w7.cpp)
namespace n002ba3b8 {
void func_002ba3e8(u32, u32, u32, u32, u32, s32*, u32, u32) asm("func_002ba3e8");
/*TARGET 002ba3b8*/
// 0x00288610: definition moved into src/anon/unit_002880b8.cpp

void func_002ba3b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2) asm("func_002ba3b8");
// 0x00288610: definition moved into src/anon/unit_002880b8.cpp

void func_002ba3b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2) {
    s32 x = -1;
    func_002ba3e8(a0, a1, a2, a3, t0, &x, t1, t2);
}
}  // namespace n002ba3b8

// 002ba3e8 (was src/anon/batch_w112.cpp)
namespace n002ba3e8 {
extern u8 D_01e2a410[] asm("D_01e2a410");
s32 func_002ba620(void) asm("func_002ba620");
s32 func_002bcbf0(u8*, u32, u32, s32*, s32*) asm("func_002bcbf0");
s32 func_002bca78(u8*, u32, u32, s32*, s32*) asm("func_002bca78");
s32 func_002bcb60(u8*, s32, u32, u32, s32*, s32*) asm("func_002bcb60");
void func_002baf48(s32, u32, u32, u32, void (*)(u32), u32) asm("func_002baf48");
void func_002bce10(u8*, s32) asm("func_002bce10");
/*TARGET 002ba3e8*/
// Issues a request of the given kind, then registers the transfer(s) and callback on success.
s32 func_002ba3e8(s32 cmd, u32 a, u32 b, u32 c, u32 d, s32* out, void (*cb)(u32), u32 arg) asm("func_002ba3e8");
// Issues a request of the given kind, then registers the transfer(s) and callback on success.
s32 func_002ba3e8(s32 cmd, u32 a, u32 b, u32 c, u32 d, s32* out, void (*cb)(u32), u32 arg) {
    s32 ok = 1;
    s32 res;
    *out = -1;
    res = -1;
    switch (cmd) {
    case 2:
    case 3:
        break;
    case 20:
        func_002bcbf0(D_01e2a410, a, c, out, &res);
        break;
    case 30:
        if (func_002ba620()) ok = 0;
        else if (!func_002bca78(D_01e2a410, a, c, out, &res)) ok = 0;
        break;
    default:
        ok = 0;
        if (!func_002ba620()) ok = func_002bcb60(D_01e2a410, cmd, a, c, out, &res) != 0;
        break;
    }
    if (res < 0 || !ok) {
        if (cb) cb(arg);
        return res;
    }
    if (c) {
        func_002baf48(*out, 0, a, b, 0, 0);
        func_002baf48(*out, 1, c, d, cb, arg);
    } else func_002baf48(*out, 0, a, b, cb, arg);
    func_002bce10(D_01e2a410, *out);  // find_entry12_set_flag
    return res;
}
}  // namespace n002ba3e8

// 002ba5d0 (was src/anon/batch_w8.cpp)
namespace n002ba5d0 {
void func_002baf48(u32, u32, u32, u32, u32, u32) asm("func_002baf48");
/*TARGET 002ba5d0*/
void func_002ba5d0(u32 a, u32 b) asm("func_002ba5d0");
void func_002ba5d0(u32 a, u32 b) {
    func_002baf48(10, 1, a, b, 0, 0);
}
}  // namespace n002ba5d0

// 002ba600 (was src/anon/tiny.cpp)
namespace n002ba600 {
extern u32 D_01e2a560 asm("D_01e2a560");
/*TARGET 002ba600*/
void func_002ba600(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba600jjjj");
void func_002ba600(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_01e2a560 = (u8)v;
}
}  // namespace n002ba600

// 002ba610 (was src/anon/tiny.cpp)
namespace n002ba610 {
/*TARGET 002ba610*/
void func_002ba610(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba610jjjj");
void func_002ba610(u32 a0, u32 a1, u32 a2, u32 a3) {  // zero_global_byte_1e3
    u32 b = (0x01e3u << 16);
    *(u8*)((u32)b + (-23200)) = (u8)0;
}
}  // namespace n002ba610

// 002ba620 (was src/anon/tiny.cpp)
namespace n002ba620 {
/*TARGET 002ba620*/
u32 func_002ba620(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba620jjjj");
u32 func_002ba620(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x01e3u << 16);
    return (u32)(*(u8*)((u32)b + (-23200)));
}
}  // namespace n002ba620

// 002ba630 (was src/anon/batch_w91.cpp)
namespace n002ba630 {
// 0x002ac800: definition moved into src/anon/unit_002a99c8.cpp

// --- 002ba630
extern u8 D_01e2a410[] asm("D_01e2a410");
void func_002bcc60(u8*, u32, u32, s32*, s32*) asm("func_002bcc60");
void func_002baf48(s32, s32, u32, u32, u32, u32) asm("func_002baf48");
void func_002bce10(u8*, s32) asm("func_002bce10");
/*TARGET 002ba630*/
// find_entry12_set_flag
s32 func_002ba630(u32 a, u32 b, u32 c, u32 d) asm("func_002ba630");
// find_entry12_set_flag
s32 func_002ba630(u32 a, u32 b, u32 c, u32 d) {
    s32 h[2];
    h[0] = -1;
    h[1] = -1;
    func_002bcc60(D_01e2a410, a, c, &h[0], &h[1]);
    func_002baf48(h[0], 0, a, b, 0, 0);
    if (c) func_002baf48(h[0], 1, c, d, 0, 0);
    func_002bce10(D_01e2a410, h[0]);  // find_entry12_set_flag
    return h[1];
}
}  // namespace n002ba630

// 002ba6f0 (was src/anon/batch_w91.cpp)
namespace n002ba6f0 {
// 0x002ac800: definition moved into src/anon/unit_002a99c8.cpp

// --- 002ba630
extern u8 D_01e2a410[] asm("D_01e2a410");
u32 func_002bccd8(u8*, u32, u32, u32, s32*, s32*) asm("func_002bccd8");
void func_002baf48(s32, s32, u32, u32, u32, u32) asm("func_002baf48");
void func_002bce10(u8*, s32) asm("func_002bce10");
/*TARGET 002ba6f0*/
// --- 002ba6f0
s32 func_002ba6f0(u32 a, u32 b, u32 c, u32 d, u32 e, s32* out) asm("func_002ba6f0");
// --- 002ba6f0
s32 func_002ba6f0(u32 a, u32 b, u32 c, u32 d, u32 e, s32* out) {
    *out = -1;
    s32 r = -1;
    if (func_002bccd8(D_01e2a410, a, b, d, out, &r)) {
        func_002baf48(*out, 0, b, c, 0, 0);
        if (d) func_002baf48(*out, 1, d, e, 0, 0);
        func_002bce10(D_01e2a410, *out);  // find_entry12_set_flag
    }
    return r;
}
}  // namespace n002ba6f0

// 002ba7c8 (was src/anon/batch_w24.cpp)
namespace n002ba7c8 {
u8 func_002ba200(void) asm("func_002ba200");
void func_00102448(u32, s32) asm("func_00102448");
/*TARGET 002ba7c8*/
void func_002ba7c8(u32 a) asm("func_002ba7c8");
void func_002ba7c8(u32 a) {
    while (func_002ba200()) func_00102448(a, 0);
}
}  // namespace n002ba7c8

// 002ba810 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n002ba810 {
u32 func_002bcd60(u32, u32, u32, u32) asm("_Z13func_002bcd60jjjj");
extern u8 D_01e2a410 asm("D_01e2a410");
/*TARGET 002ba810*/
// 0x00280420: definition moved into src/anon/unit_0027f2b0.cpp

u32 func_002ba810(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba810jjjj");
// 0x00280420: definition moved into src/anon/unit_0027f2b0.cpp

u32 func_002ba810(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bcd60((u32)&D_01e2a410, a0, a2, a3);
}
}  // namespace n002ba810

// 002ba830 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002ba830 {
u32 func_002b70b8(u32, u32, u32, u32) asm("_Z13func_002b70b8jjjj");
/*TARGET 002ba830*/
u32 func_002ba830(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ba830jjjj");
u32 func_002ba830(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    r6 = (u32)(r6 << 3);
    return func_002b70b8(r4, r5, r6, r7);
}
}  // namespace n002ba830

// 002ba848 (was src/anon/auto80_199_queue.cpp)
namespace n002ba848 {
/*TARGET 002ba848*/
u32 func_002ba848(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002ba848jjjjjjjj");
u32 func_002ba848(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s0 = a0;
    func_002b70b8(0, 0, s0);
    func_002b70b8(1, 0, s0);
    func_002b73ac(-100, -1, 0, 0, s0);
    func_002baa60();
    return func_002b83b4();
}
}  // namespace n002ba848

// 002ba8a8 (was src/anon/batch_w22.cpp)
namespace n002ba8a8 {
// 0x0028b750: definition moved into src/anon/unit_00288b00.cpp

// --- 002ba8a8
void func_002b7078(u32) asm("func_002b7078");
void func_002b72e4(s32, s32, u32) asm("func_002b72e4");
void func_002baa60(void) asm("func_002baa60");
void func_002b83b4(void) asm("func_002b83b4");
/*TARGET 002ba8a8*/
void func_002ba8a8(void) asm("func_002ba8a8");
void func_002ba8a8(void) {
    func_002b7078(0);
    func_002b7078(1);
    func_002b72e4(-100, -1, 0);
    func_002baa60();
    func_002b83b4();
}
}  // namespace n002ba8a8

// 002ba8e8 (was src/ohori/sound.cpp)
namespace n002ba8e8 {
void seVoicePcmStop() asm("_ZN5SOUND14seVoicePcmStopEv");
void func_002b72e4(s32, s32, u32) asm("func_002b72e4");
void func_002baa60(void) asm("func_002baa60");
u32 func_002b83b4(void) asm("func_002b83b4");
/*TARGET 002ba8e8*/
// 0x002bc788 SE3DDisable, 0x002bc798 SE3DEnable: definitions moved into src/anon/unit_002bb8b0.cpp

void seVoicePcmStop() asm("_ZN5SOUND14seVoicePcmStopEv");
// 0x002bc788 SE3DDisable, 0x002bc798 SE3DEnable: definitions moved into src/anon/unit_002bb8b0.cpp

void seVoicePcmStop() {
    func_002b72e4(-100, -1, 0u);
    func_002baa60();
    func_002b83b4();
}
}  // namespace n002ba8e8

// 002ba918 (gap function, never written before)
namespace n002ba918 {
void func_002b70b8(u32, u32, u32) asm("_Z16wtarget_002b70b8jjjj");
void func_002ba918(void) asm("func_002ba918");
void func_002ba918(void) { func_002b70b8(0, 6144, 240); func_002b70b8(1, 6144, 240); }
}  // namespace n002ba918

// 002ba948 (was src/anon/batch_w7.cpp)
namespace n002ba948 {
void func_002b70b8(u32, u32, u32) asm("func_002b70b8");
/*TARGET 002ba948*/
void func_002ba948(void) asm("func_002ba948");
void func_002ba948(void) {
    func_002b70b8(0, 0x3000, 240);
    func_002b70b8(1, 0x3000, 240);
}
}  // namespace n002ba948

// 002ba978 (was src/anon/tiny_auto80_solver.cpp)
namespace n002ba978 {
u32 func_002b6c04(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002b6c04jjjjjjjj");
extern u8 D_01e2a400 asm("D_01e2a400");
/*TARGET 002ba978*/
u32 func_002ba978(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002ba978jjjjjjjj");
u32 func_002ba978(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 base = (u32)&D_01e2a400;
    u32 s0 = 0x00360000u;
    u32 idx = *(volatile u32*)(s0 + 5856);
    idx <<= 2;
    u32 ptr = idx + base;
    *(volatile u32*)ptr = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002b6c04)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 count = *(volatile u32*)(s0 + 5856);
    count++;
    *(volatile u32*)(s0 + 5856) = count;
    return r2;
}
}  // namespace n002ba978

// 002ba9c0 (was src/anon/batch_w1588.cpp)
namespace n002ba9c0 {
u32 func_002b6c04(u32) asm("func_002b6c04");
extern s32 D_003616e0 asm("D_003616e0");
extern u32 D_01e2a400[] asm("D_01e2a400");
// 0x00285d18: definition moved into src/anon/unit_002853b8.cpp

u32 ResetVoiceState() asm("_ZN2Tz9MenuSound15ResetVoiceStateEv");
/*TARGET 002ba9c0*/
u32 ResetVoiceState() asm("_ZN2Tz9MenuSound15ResetVoiceStateEv");
u32 ResetVoiceState() {
    s32 t = D_003616e0;
    u32 a = 0;
    if (t) {
        s32 n = t - 1;
        D_003616e0 = n;
        if (n > 0) {
            u32 k = t - 2;
            a = D_01e2a400[k];
        }
    }
    return func_002b6c04(a);
}
}  // namespace n002ba9c0

// 002baa08 (was src/anon/tiny.cpp)
namespace n002baa08 {
void func_002b788c(void*) asm("_Z13func_002b788cPv");
/*TARGET 002baa08*/
void func_002baa08(BD_VALUE* bd) asm("_Z13func_002baa08P8BD_VALUE");
void func_002baa08(BD_VALUE* bd) { func_002b788c(bd); }
}  // namespace n002baa08

// 002baa20 (was src/anon/tiny_jal_wrappers.cpp)
namespace n002baa20 {
u32 func_002b79cc(u32, u32, u32, u32) asm("_Z13func_002b79ccjjjj");
/*TARGET 002baa20*/
// 0x001bd590: definition moved into src/anon/unit_001bc568.cpp
u32 func_002baa20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002baa20jjjj");
// 0x001bd590: definition moved into src/anon/unit_001bc568.cpp
u32 func_002baa20(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r6 = r4;
    r5 = 0u;
    r4 = 0u;
    r2 = func_002b79cc(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace n002baa20

// 002baa48 (was src/anon/tiny_wrappers_more.cpp)
namespace n002baa48 {
u32 func_002b78ec(u32, u32, u32, u32) asm("_Z13func_002b78ecjjjj");
/*TARGET 002baa48*/
u32 func_002baa48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002baa48jjjj");
u32 func_002baa48(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002b78ec(a0, a1, a2, a3);
}
}  // namespace n002baa48

// 002baa60 (was src/anon/tiny.cpp)
namespace n002baa60 {
void func_002b9968(void*) asm("_Z13func_002b9968Pv");
/*TARGET 002baa60*/
void func_002baa60(BD_VALUE* bd) asm("_Z13func_002baa60P8BD_VALUE");
void func_002baa60(BD_VALUE* bd) { func_002b9968(bd); }
}  // namespace n002baa60

// 002baa78 (was src/anon/batch_w96.cpp)
namespace n002baa78 {
void func_002b6adc(u32, u32) asm("func_002b6adc");
/*TARGET 002baa78*/
// 0x002b3318: definition moved into src/anon/unit_002b2a18.cpp

void func_002baa78(void) asm("func_002baa78");
// 0x002b3318: definition moved into src/anon/unit_002b2a18.cpp

void func_002baa78(void) {
    s32 i;
    func_002b6adc(2, 4);
    func_002b6adc(0, 4);
    func_002b6adc(2, 5);
    func_002b6adc(0, 5);
    func_002b6adc(2, 6);
    func_002b6adc(0, 6);
    func_002b6adc(2, 7);
    func_002b6adc(0, 7);
    func_002b6adc(0, 10);
    func_002b6adc(2, 10);
    func_002b6adc(2, 11);
    func_002b6adc(2, 12);
    func_002b6adc(2, 13);
    func_002b6adc(2, 14);
    for (i = 0; i < 14; i++) {
        func_002b6adc(2, i + 30);
        func_002b6adc(0, i + 30);
    }
    for (i = 0; i < 2; i++) {
        func_002b6adc(2, i + 20);
        func_002b6adc(0, i + 20);
    }
}
}  // namespace n002baa78

// 002baba8 (was src/anon/tiny.cpp)
namespace n002baba8 {
void func_002b99c8(void*) asm("_Z13func_002b99c8Pv");
/*TARGET 002baba8*/
void func_002baba8(BD_VALUE* bd) asm("_Z13func_002baba8P8BD_VALUE");
void func_002baba8(BD_VALUE* bd) { func_002b99c8(bd); }
}  // namespace n002baba8

// 002babc0, 002babf0 (gap functions, never written before)
namespace n002babc0 {
void func_002b6adc(s32, s32) asm("func_002b6adc");
void func_002b9a00(void) asm("func_002b9a00");
void func_002b9a78(void) asm("func_002b9a78");
void func_002babc0(void) asm("func_002babc0");
void func_002babc0(void) { func_002b6adc(2, 50); func_002b6adc(0, 50); func_002b9a00(); }
void func_002babf0(void) asm("func_002babf0");
void func_002babf0(void) { func_002b9a78(); }
}  // namespace n002babc0

// 002bac08 (was src/anon/tiny_auto80_queue.cpp)
namespace n002bac08 {
extern u8 D_01e2a410 asm("D_01e2a410");
/*TARGET 002bac08*/
void func_002bac08(u32 a0, u32 a1) asm("_Z13func_002bac08jj");
void func_002bac08(u32 a0, u32 a1) {
    if (a1 == 0xffffu && a0 == 1u) {
        u32 p = (u32)&D_01e2a410;
        s32 i = 26;
        do {
            *(s32*)(p + 0) = -1;
            *(s32*)(p + 4) = -1;
            *(u32*)(p + 8) = 0;
            i -= 1;
            p += 12;
        } while (i != -1);
    }
}
}  // namespace n002bac08

// 002bac58 (was src/anon/tiny_wrappers_more.cpp)
namespace n002bac58 {
u32 func_002bac08(u32, u32, u32, u32) asm("_Z13func_002bac08jjjj");
/*TARGET 002bac58*/
u32 func_002bac58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bac58jjjj");
u32 func_002bac58(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bac08(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002bac58

