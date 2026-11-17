#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
extern "C" void dk_Timer_start_exact_0014c9b8(void) asm("_ZN2dk5Timer5startEv");

// ============================================================
// Forward declarations for tiny_auto80_queue.cpp
// ============================================================

#include <stdarg.h>

// ---- Function pointer typedefs ----

typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);

// ---- Namespace declarations ----

namespace worldmap { namespace Gumi { u32 getCourse(); } }
extern u8 D_0032d7c0;
extern u8 D_001b8520;
namespace YS {
    namespace SELECTOR { void ResetPauseMode(s32); }
    namespace EVENT { void ControlOn(); void ControlOff(); }
}

// ---- Special helper functions ----

void wtarget_002fee78(u32, u32, u32, u32);
static inline u32 add_lhs(u32 a, u32 b) { return a + b; }

// ---- Forward declarations for functions defined in other TUs ----

u32 func_00138480(u32);
u32 func_0013b1a0(u32);
u32 func_0014aa58(u32, u32, u32);
void func_00192260(u32, u32);
void func_00192290(u32, u32);
void func_001bdc18(u32);
void func_00258d58(u32, u32, u32);
u32 func_00276638(u32);
u32 func_002cff98(u32);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_0023f7e0(...);
extern "C" u32 func_00239848(...);  // set_vtbl_36eb28_then_call
extern "C" u32 func_00239870(...);
extern "C" u32 func_00246840(...);
extern "C" u32 func_00294000(...) asm("_ZN2Tz6JmInfo7GetDataEi");
extern "C" void func_002c9ed8(...);
extern "C" u32 func_002d2a08(...);
extern "C" u32 func_002db530(...);
extern "C" u32 func_00315768(...);
extern "C" u32 func_00149428(...);
extern "C" u32 func_001b83d0(...);
extern "C" u32 func_001940f0(...);
extern "C" u32 func_00194108(...);
extern "C" u32 func_00195700(...);
extern "C" u32 func_001a8b38(...);
extern "C" u32 func_001d2180(...);
extern "C" void func_001bc688(...);
extern "C" u32 func_002595e8(...);

// ---- Non-function global symbols used as data/function-pointer values ----

extern u8 D_003616f8;
extern u32 func_003617e0;
extern u32 func_003617e4;
extern u8  func_003617e8;
extern u32 func_003617ec;
extern u32 func_003617f0;
extern u32 func_003617f4;
extern u8  func_003617f8;
extern u32 D_003617fc;
extern u8  func_00361810;
extern u8  func_003618a0;
extern u32 func_00361980;
extern u32 func_00361a90;
extern u8  func_00374fa8;
extern u8  func_003753e0;
extern u8  func_00375400;
extern u8  D_01e2a410;
extern u8  D_01e2a5e8;
extern u8  D_01e2aa80;
extern u8  func_01e2bba0;
extern u8  func_01e2bc40;
extern u8  func_002bd870;
extern u8  func_0032b91c;
extern u32 func_0033caf4;
extern u8  D_001c6a28;
extern "C" void func_00292608(...) asm("_ZN2Tz8LoadData9FlushTaskEP4TASK");
extern u8  D_00292620;
extern u8  D_002c53c8;

// ---- Data symbols ----

extern u8  D_001384d0;
extern u8  D_001dda78;
extern u8  D_001ddb30;
extern u8  D_00220000;
extern u8  D_00263db0;
extern u8  D_0026dd40;
extern u8  D_0032f064;
extern u32 D_0032fae4[];
extern u8  D_0032fcc9;
extern u32 D_0033caf0;
extern u32 D_0033caf4;
extern u32 D_00340000;
extern f32 D_00340ebc;
extern f32 D_00340ec0;
extern f32 D_00340ec8[];
extern f32 D_00340ed0[];
extern u8 D_00345d40;
extern u32 D_00347e08;
extern u32 D_00347f80;
extern u32 D_00348804;
extern u32 D_00348808;
extern u32 D_00348810;
extern u8  D_0034881f;
extern u32 D_00348820;
extern u32 D_00348830;
extern u32 D_00349de8;
extern u32 D_00349df0;
extern u32 D_00349df4;
extern u32 D_00349df8;
extern u32 D_00349dfc;
extern u32 D_00349e00;
extern f32 D_00349e14;
extern u32 D_00349e1c;
extern u8  D_00349e20;
extern u32 D_0034a780;
extern u32 D_0034a784;
extern u32 D_0034a788;
extern u32 D_0034a78c;
extern u32 D_0034a790;
extern u8  D_0034c770;
extern u8  D_0034c771;
extern u32 D_0034c774;
extern u32 D_0034c778;
extern u8  D_00350000;
extern u32 D_00350470;
extern u32 D_00350748;
extern u32 D_00350790;
extern u8  D_00350800;
extern u8  D_00350990;
extern u8  D_00350a70;
extern u8  D_00350c50;
extern u32 D_00352130;
extern u32 D_00352768;
extern u8  D_00352908;
extern u8* D_00352bd0;
extern u32 D_0035eb28;
extern u32 D_0035eb34;
extern u8  D_0035eb50;
extern u32 D_0035eb54;
extern u8  D_0035eb80;
extern u8  D_0035eb81;
extern u8  D_0035eb84;
extern u32 D_0035eb88;
extern u32 D_0035eb8c;
extern u32 D_0035ebe0;
extern u32 D_0035ebec;
extern u32 D_0035ec84;
extern u32 D_0035ec88;
extern u32 D_0035ec90;
extern u32 D_0035ec94;
extern u32 D_0035ec9c;
extern u32 D_0035ec98;
extern u32 D_0035ecb8;
extern u32 D_0035ecbc;
extern u32 D_0035ecc0;
extern u16 D_0035ecc8;
extern u32 D_0035ece8;
extern u32 D_0035ed20;
extern u32 D_0035ed4c;
extern u32 D_0035ed70;
extern u32 D_0035eda8;
extern u32 D_0035edcc;
extern u32 D_0035edf4;
extern u32 D_0035ee04;
extern u32 D_0035ee10;
extern u32 D_0035ee58;
extern u32 D_0035ee60;
extern u32 D_0035ee7c;
extern u32 D_0035eea4;
extern u32 D_0035eea8;
extern u32 D_0035ef70;
extern u32 D_0035f01c;
extern u32 D_0035f020;
extern u32 D_0035f04c;
extern u32 D_0035f050;
extern u16 D_0035f090;
extern u16 D_0035f092;
extern u16 D_0035f096;
extern u32 D_0035f0dc;
extern u32 D_0035f0e4;
extern u32 D_0035f118;
extern u32 D_0035f11c;
extern u8  D_0035f120;
extern u32 D_0035f12c;
extern u32 D_0035f140;
extern u32 D_0035f1fc;
extern u32 D_0035f21c;
extern u32 D_0035f230;
extern u32 D_0035f23c;
extern u32 D_0035f240;
extern u32 D_0035f260;
extern u32 D_0035f274;
extern u16 D_0035f280;
extern u32 D_0035f28c;
extern u8  D_0035f298;
extern u8  D_0035f299;
extern u32 D_0035f2b0;
extern u32 D_0035f2b4;
extern u32 D_0035f2bc;
extern u32 D_0035f2c0;
extern u32 D_0035f2d8;
extern u32 D_0035f2dc;
extern u32 D_0035f2f0;
extern s32 D_0035f2f4;
extern u32 D_0035f2f8;
extern s32 D_0035f2fc;
extern u32 D_0035f30c;
extern s32 D_0035f310;
extern u64* D_0035f324;
extern u16 D_0035f32a;
extern void* D_0035f338;
extern void* D_0035f34c;
extern void* D_0035f3f8;
extern u8  D_00360000;
extern u8  D_00361899;
extern u32 D_00361a50;
extern u32 D_00361fb0;
extern u32 D_00361fc8;
extern u32 D_00362050;
extern u32 D_00362060;
extern u32 D_00365c48;
extern f32 D_0036e030[];
extern u8* D_0036e180;
extern u8 D_01c6053c;
extern u8 D_01c60540;
extern u8  D_0036e448;
extern u8 D_0036e648;
extern u32 D_00370000;
extern u8  D_003717e8;
extern u8  D_00371ad8;
extern u8  D_00371af0;
extern u8  D_00371ee8;
extern u8  D_00371f30;
extern u8  D_003721b8;
extern u8  D_00372228;
extern u32 D_003722ec;
extern u32 D_003722f0;
extern u8  D_00372608;
extern u8  D_00372610;
extern u8  D_00372650;
extern u8  D_00372eea;
extern u8  D_00373d50;
extern u8  D_00373d58;
extern u8  D_00373ef8;
extern u8  D_00373f00;
extern u8  D_00373f08;
extern u8  D_00373f10;
extern s32 D_00378ae4;
extern u32 D_01c62fb0;
extern u32 D_01c6cb20;
extern u32 D_01c6cb90;
extern u32 D_01c6cba0;
extern u8  D_01c6ced0;
extern u8* D_01d5ba30;
extern u32 D_01d5ba68;
extern u8* D_01d5ba98;
extern u32 D_01d9e348;
extern u32 D_01d9e6e4;
extern u8  D_01da0000;
extern u8* D_01dad938;
extern u8* D_01dad960;
extern u32 D_01dae680;
extern u8  D_01e2bda0;

// D_0034b244 is a pointer to Obj0015de58
extern Obj0015de58* D_0034b244;

// ---- Function forward declarations (from missing_decls) ----

void __attribute__((noreturn)) func_001002a0(u32);
extern "C" void func_00102670(...);  // to_1025f8
extern "C" u32 func_00102c48(...);
extern "C" u32 func_00103398(...);
extern "C" u32 func_00103580(...);
extern "C" void func_00103c80(...);
extern "C" u32 func_00105ee8(...);
extern "C" u32 func_001063f0(...);
extern "C" u32 func_001064a8(...);  // int_to_float_scaled
void func_00111000(u32, f32);
extern "C" void func_001374c8(...);
extern "C" void func_00138190(...);
extern "C" void func_001391f0(...);
extern "C" void func_001396b0(...);
extern "C" void func_0013b8e8(...);
extern "C" void func_001422a0(...);  // find_record16_and_copy
u32* func_00142398(u32, u32);
extern "C" void func_00143298(...);
extern "C" void func_001432a8(...);
extern "C" u32 func_001b9d40(...);  // vtable_call_slot64_flags
extern "C" void func_00143e50(...);
extern "C" void func_0014a1e0(...);
extern "C" u32 func_0014abb8(...);  // get_data_359840
extern "C" u32 func_0014abc8(...);  // get_data_359950
extern "C" void func_0014c940(...);
extern "C" void func_0014c9f0(...);
u32 func_0014ce50(f32);
extern "C" void func_0014f578(...);
extern "C" void func_001505b0(...);
extern "C" void func_00151b78(...);
extern "C" void func_00152120(...);
extern "C" u32 func_00153468(...);
extern "C" void func_0015ee10(...);
extern "C" void func_0015ee90(...);
extern "C" void func_0015f6e8(...);
extern "C" void func_0015f700(...);
extern "C" void func_00161aa8(...);
extern "C" void func_00165f70(...);
extern "C" void func_00167fc8(...);
extern "C" void func_00168008(...);
extern "C" void func_0016b070(...);
extern "C" u32 func_0016bc20(...);
extern "C" void func_0016be98(...);
extern "C" void func_0016c5b8(...);
extern "C" void func_0016c640(...);
extern "C" void func_0016ed50(...);
extern "C" void func_00170570(...);
extern "C" void func_00170dd0(...);
extern "C" void func_00177dc8(...);
extern "C" void func_0017c578(...);
extern "C" void func_0017f488(...);
void func_00184540(u32, u32, f32, f32);
extern "C" void func_00185ed8(...);
extern "C" void func_0018a818(...);
extern "C" void func_00190920(...);
extern "C" void func_00191a20(...);
extern "C" void func_00191a38(...);
extern "C" u32 func_00191e40(...);
extern "C" u32 func_001923c8(...);
extern "C" void func_00195858(...);
extern "C" void func_00197cc0(...);
extern "C" void func_00198450(...);
extern "C" u32 func_0019f7d0(...);
extern "C" u32 func_001a0e78(...);
extern "C" void func_001a0ee0(...);
extern "C" void func_001a1a20(...);
extern "C" void func_001a1db8(...);
extern "C" u32 func_001a35f8(...);
extern "C" void func_001a52a8(...);
extern "C" void func_001a5990(...);
extern "C" u32 func_001a6658(...);
extern "C" void func_001a7a48(...);
extern "C" void func_001a7b78(...);
extern "C" void func_001aa388(...);
extern "C" u32 func_001ab800(...);
extern "C" u32 func_001ab810(...);  // get_global_1c7cec0
extern "C" void func_001ac310(...);
extern "C" void func_001acdc0(...);
extern "C" void func_001ad280(...);
extern "C" void func_001ad9c8(...);  // float_accumulate_clamped
extern "C" void func_001aedf8(...);
extern "C" void func_001b0210(...);
extern "C" void func_001b1100(...);
extern "C" u32 func_001b1490(...);
extern "C" void func_001b3b70(...);
extern "C" u32 func_001b58a8(...);
extern "C" void func_001b6298(...);
extern "C" u32 func_001b70d0(...);
extern "C" u32 func_001b77a8(...);
u32 func_001b84b8(u32, u32, u32, u32);
u32 func_001b8420(u32, u32, u32, u32);
extern "C" void func_001b86e0(...);  // alloc_from_pool_magic_c
extern "C" void func_001bc720(...);
extern "C" void func_001bd2d0(...);
extern "C" void func_001bd5b0(...);
extern "C" u32 func_001c11e0(...);
extern "C" void func_001c1748(...);  // obj_init_from_src
extern "C" u32 func_001c2b58(...);
extern "C" u32 func_001c3748(...);
extern "C" void func_001c79a0(...);
extern "C" void func_001c8d80(...);
extern "C" void func_001c8d98(...);
extern "C" void func_001c8ec0(...);
void func_001c97b0(void*, f32);
extern "C" void func_001d2130(...);
extern "C" u32 func_001d35e0(...);
extern "C" u32 func_001d56c8(...);
extern "C" void func_001d59b0(...);
extern "C" u32 func_001d5af8(...);
extern "C" void func_001d5f30(...);
extern "C" void func_001d71f0(...);
extern "C" u32 func_001d83c0(...);
void func_001d8d08(f32, u32);
void func_001d8da0(f32, u32);
extern "C" void func_001d8fa8(...);
void func_001d9050(u32, u32, f32);
extern "C" u32 func_001d96c0(...);
extern "C" u32 func_001db5a8(...);
extern "C" u32 func_001dc9d0(...) asm("_ZN3ryj6EFFECT8is_aliveEv");
extern "C" u32 func_001dcd58(...);
extern "C" u32 func_001dcd88(...);
extern "C" void func_001ddb68(...);
extern "C" u32 func_001de4b0(...);
extern "C" u32 func_001de568(...);
extern "C" void func_001de590(...);
extern "C" void func_001de610(...);
extern "C" void func_001de750(...);
extern "C" f32 func_001e09d0(...);
extern "C" void func_001e1988(...);
extern "C" u32 func_001e3650(...);  // ptr_add4
extern "C" u32 func_001e3660(...);
extern "C" u32 func_001e4248(...);
extern "C" u32 func_001e4320(...);
extern "C" u32 func_001e4e18(...);
extern "C" s32 func_001e5a00(...);
extern "C" void func_001e6b00(...);
extern "C" u32 func_001e7698(...);  // alloc_aligned16
extern "C" void func_001e7798(...);
extern "C" void func_002229a0(...);  // vec3_length
extern "C" void func_002236d0(...);
extern "C" void func_002248f8(...);
extern "C" u32 func_00224988(...);  // get_global_byte_36dad5
extern "C" s32 func_002249b8(...);  // get_global_36dac0
extern "C" s32 func_002249e8(...);  // get_global_byte_36dad6
extern "C" u32 func_00225eb8(...);
extern "C" void func_00225fa0(...);
extern "C" void func_00226478(...);
extern "C" u32 func_00227818(...);
extern "C" u32 func_00227858(...);
extern "C" u32 func_002282f0(...);
extern "C" void func_00228918(...);
extern "C" void func_00228bd8(...);
extern "C" s32 func_0022ab80(...);
extern "C" u32 func_002325f0(...);
extern "C" void func_00234590(...);
extern "C" void func_00234670(...);
extern "C" void func_002346a0(...);
extern "C" void func_00239988(...);
extern "C" s32 func_00239b50(...);  // find_entry_in_group
extern "C" u32 func_0023c5f0(...);
extern "C" void func_0023d2b0(...);
extern "C" void func_0023d410(...);
extern "C" void func_0023ed90(...);  // set_global_byte1
extern "C" u32 func_0023f100(...);
extern "C" void func_0023fbc8(...);
extern "C" void func_0023fc08(...);
extern "C" void func_0023fc40(...);
extern "C" void func_0023fcd0(...);
extern "C" u32 func_0023fd30(...);  // global_flag_nonzero
extern "C" void func_00240360(...);
extern "C" void func_00240be0(...);
extern "C" void func_00240c08(...);
extern "C" void func_002423a0(...);
extern "C" void func_00242408(...);  // set_global_crc_m1
extern "C" void func_00242418(...);  // crc_byte_update
extern "C" u32 func_00242708(...);
extern "C" void func_00242880(...);
extern "C" u32 func_0024ac88(...);
extern "C" u32 func_00252110(...);
extern "C" void func_00252ce0(...);
extern "C" void func_00252d88(...);
extern "C" void func_00252e50(...);
extern "C" void func_00253638(...);
extern "C" void func_00253888(...);
extern "C" void func_00253b30(...);
extern "C" void func_00257000(...);
extern "C" void func_002571e0(...);
extern "C" void func_00257388(...);
extern "C" void func_002579e0(...);
extern "C" u32 func_00258c48(...) asm("_ZN2Tz5Pause10isLoopFadeEv");
extern "C" u32 func_00258cd8(...);
extern "C" void func_00258d40(...);
extern "C" u32 func_00259460(...);
extern "C" void func_002595b8(...);
extern "C" void func_002597f0(...);
extern "C" u32 func_00263cc0(...);
extern "C" void func_00265580(...);
extern "C" void func_002655e8(...);
extern "C" void func_00265a30(...);
extern "C" void func_00265ab8(...);
extern "C" void func_0026d968(...);
extern "C" void func_00271e08(...);
extern "C" void func_00271e80(...);
extern "C" u32 func_00271ec8(...);
extern "C" void func_00272340(...);
extern "C" void func_002723e0(...);
extern "C" void func_00276220(...);
extern "C" u32 func_002764b0(...);
extern "C" u32 func_00276c18(...);
extern "C" void func_0027a180(...);
extern "C" void func_0027a898(...);
extern "C" void func_0027acf8(...);
extern "C" void func_002818b8(...);
extern "C" u32 func_00281c30(...);
extern "C" void func_00281f40(...);
extern "C" void func_00281f48(...);  // memset_1920
extern "C" void func_00281f70(...);
extern "C" void func_00281f90(...);
extern "C" u32 func_002833f8(...);
extern "C" void func_002835a8(...);
extern "C" void func_002835d8(...);
extern "C" void func_00283d00(...);
extern "C" void func_00283f50(...);
extern "C" void func_00287c20(...);  // clear_global_flag_return_m1
extern "C" void func_00287c78(...);
extern "C" void func_00287da0(...) asm("_ZN2Tz8MenuBase7SetExitEv");
extern "C" u32 func_00288be8(...);
extern "C" u32 func_002891e8(...);
extern "C" void func_002891f0(...);
extern "C" void func_0028abe0(...);
extern "C" u32 func_0028acc8(...);
extern "C" u32 func_0028be58(...);
extern "C" void func_0028ce38(...);
extern "C" u32 func_0028d6e8(...) asm("_ZN2Tz8LightCur7isExistEv");
extern "C" void func_00256ea8(...) asm("_ZN2Tz5CmTop12LeavePadHelpEv");
extern "C" void func_0028f4d8(...);
extern "C" void func_0028f6f0(...);  // record884_refresh_by_index
extern "C" void func_0028f7e8(...);
extern "C" u32 func_00290940(...);
extern "C" u32 func_00290960(...);
extern "C" void func_00290a60(...);
extern "C" u32 func_00292a90(...);
extern "C" void func_002926a8(...) asm("_ZN2Tz8LoadData10CacheAllocEPKc");
extern "C" void func_00292b40(...);
extern "C" void func_00293bd0(...);
extern "C" void func_00293cb8(...);
extern "C" void func_00294288(...);
extern "C" void func_00295508(...);
extern "C" void func_002955a8(...);
extern "C" u32 func_002a43f0(...);
extern "C" void func_002a67a8(...);
extern "C" void func_002a73d0(...);
extern "C" void func_002a8258(...);
extern "C" void func_002a94f8(...);
extern "C" void func_002b4b00(...);
extern "C" u32 func_002b6e24(...);
extern "C" u32 func_002b6f28(...);
extern "C" void func_002b7078(...);
extern "C" void func_002b70b8(...);
extern "C" void func_002b72e4(...);
extern "C" u32 func_002b823c(...);
extern "C" void func_002b83b4(...);
extern "C" void func_002b8434(...);
extern "C" void func_002b871c(...);
extern "C" u32 func_002b8824(...);
extern "C" void func_002b8c78(...);
extern "C" u32 func_002ba810(...);
extern "C" void func_002baa08(...);
extern "C" void func_002baa60(...);
extern "C" void func_002bbed0(...);
extern "C" void func_002bbf18(...);
extern "C" void func_002bc188(...);
extern "C" void func_002bc470(...);
extern "C" void func_002bc608(...);
extern "C" void func_002bd760(...);
extern "C" void func_002bd7d8(...);
extern "C" void func_002be0b0(...);  // quad_entry_process
u32 func_002be5b8();
extern "C" void func_002c0ca0(...);
extern "C" void func_002c1b60(...);
extern "C" u32 func_002c5140(...);
extern "C" void func_002c6158(...);
extern "C" u32 func_002cab48(...);
extern "C" void func_002cb7c0(...);
extern "C" void func_002cbd08(...);
extern "C" void func_002cd260(...);
extern "C" void func_002cd290(...);
void func_002cd910(f32);  // split_float_call
extern "C" void func_002cf268(...);
extern "C" void func_002cff50(...);
extern "C" void func_002d0070(...);
extern "C" void func_002d08b8(...);
extern "C" u32 func_002d1260(...);
extern "C" void func_002d1550(...);
extern "C" u32 func_002d1878(...);
extern "C" void func_002d2948(...);
extern "C" u32 func_002d5578(...);  // is_field340_eq151
extern "C" void func_002d5950(...);
extern "C" void func_002d5b48(...);
extern "C" void func_002dc4e0(...);
extern "C" u32 func_002dc7c8(...);
extern "C" void func_002dd2d8(...);
void func_002e7108(u32, f32);
extern "C" void func_002e7308(...);
extern "C" void func_002eaf38(...);
extern "C" void func_002eb778(...);
extern "C" void func_002eb7f0(...);
extern "C" void func_002ed300(...);
extern "C" void func_002eda30(...);
extern "C" void func_002ef708(...);
extern "C" u32 func_002ef9e0(...);
extern "C" u32 func_002efc10(...);
extern "C" void sceVu0SubVector(...);  // vec4_sub
f32 func_002f86f0(f32);
extern "C" void memcpy(...);
extern "C" void func_002fed10(...);
extern "C" u32 func_002fee78(...);
extern "C" void strlen(...);  // strlen
extern "C" u32 func_002ffd00(...);  // fprintf_stream_va
extern "C" u32 _vfprintf_r(...);
extern "C" s32 func_00305d08(...);
extern "C" s32 func_00305d20(...);
extern "C" void func_0030df38(...);
extern "C" void func_003134b8(...);
extern "C" void func_00314480(...);
extern "C" void func_00314640(...);
extern "C" void func_003147a0(...);
extern "C" void func_00314830(...);
extern "C" void func_00314930(...);
extern "C" void func_00315418(...) __attribute__((noreturn));
extern "C" void func_0031fe00(...);
extern "C" void func_00324718(...);

// ---- Additional function declarations needed from solver_decls ----

extern "C" u32 func_0011d440(...);
extern "C" u32 func_0017dbb8(...);
extern "C" u32 func_00227d10(...);


extern "C" u32 func_001041a0(...);
extern u8 D_0036a070;


extern "C" u32 srand(...);


extern "C" u32 func_0019ba60(...);

u32 func_00112c80(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00112c80: definition moved into src/anon/unit_001117d8.cpp

extern u8 D_00345cf8;


extern u8 D_00345cf8;


extern "C" u32 func_00105110(...);
extern u8 D_00345cf8;


u32 func_001137f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001137f0: definition moved into src/anon/unit_00113628.cpp

extern "C" u32 func_00113668(...);
extern u8 D_003461e8;


extern "C" u32 func_00113668(...);
extern u8 D_003461e8;


extern "C" u32 func_00113668(...);
extern u8 D_003464b0;


extern "C" u32 func_00113668(...);
extern u8 D_003464b0;


extern "C" u32 func_00113668(...);
extern u8 D_00346658;


extern "C" u32 func_00113668(...);
extern u8 D_00346658;


extern "C" u32 func_00113668(...);
extern u8 D_003467b8;


extern "C" u32 func_00113668(...);
extern u8 D_003467b8;


extern "C" u32 func_00113668(...);
extern u8 D_00346960;


extern "C" u32 func_00113668(...);
extern u8 D_00346960;


extern "C" u32 func_00113fb0(...);


extern "C" u32 func_00113668(...);
extern u8 D_00346b08;


extern "C" u32 func_00113668(...);
extern u8 D_00346b08;


extern "C" u32 func_00113fb0(...);


extern "C" u32 func_00113668(...);
extern u8 D_00346cd8;


extern "C" u32 func_00113668(...);
extern u8 D_00346cd8;


extern "C" u32 func_00113fb0(...);


extern "C" u32 func_00113fb0(...);


extern "C" u32 func_00113668(...);
extern u8 D_00346e80;


extern "C" u32 func_00113668(...);
extern u8 D_00346e80;


extern "C" u32 func_00113fb0(...);


extern "C" u32 func_00113668(...);
extern u8 D_00347050;


extern "C" u32 func_00113668(...);
extern u8 D_00347050;


extern "C" u32 func_00113fb0(...);


extern "C" u32 func_00113fb0(...);


extern "C" u32 func_00113668(...);
extern u8 D_00347220;


extern "C" u32 func_00113668(...);
extern u8 D_00347220;


extern "C" u32 func_00113fb0(...);


extern "C" u32 func_00113668(...);
extern u8 D_003473c8;


extern "C" u32 func_00113668(...);
extern u8 D_003473c8;


extern "C" u32 func_00113668(...);
extern u8 D_00347550;


extern "C" u32 func_00113668(...);
extern u8 D_00347550;


extern "C" u32 func_00113990(...);


extern "C" u32 func_00113668(...);
extern u8 D_003477a0;


extern "C" u32 func_00113668(...);
extern u8 D_00347808;


extern "C" u32 func_00113668(...);
extern u8 D_00347808;


extern u8 D_00347848;


extern u8 D_00347848;


extern "C" u32 func_00113668(...);
extern u8 D_00347848;


extern "C" u32 func_00113668(...);
extern u8 D_00347848;


extern "C" u32 func_0011ee58(...);  // set_vtbl_347940
extern u8 D_003479a8;


extern "C" u32 func_0011ee58(...);  // set_vtbl_347940
extern u8 D_003479a8;


extern "C" u32 func_0011ef20(...);


extern "C" u32 func_0011f7a8(...);


extern "C" u32 func_0011ee58(...);  // set_vtbl_347940
extern u8 D_00347a28;


extern "C" u32 func_0011ee58(...);  // set_vtbl_347940
extern u8 D_00347a28;


extern "C" u32 func_00124c08(...);  // set_vtbl_347b88
extern u8 D_00347bb0;


extern "C" u32 func_00124c08(...);  // set_vtbl_347b88
extern u8 D_00347bb0;


extern "C" u32 func_00124bb8(...);  // obj_ctor_347b88
extern u8 D_00347bd8;


extern "C" u32 func_00124bb8(...);  // obj_ctor_347b88
extern u8 D_00347bd8;


extern "C" u32 func_00124c08(...);  // set_vtbl_347b88
extern u8 D_00347bd8;


extern "C" u32 func_00124c08(...);  // set_vtbl_347b88
extern u8 D_00347bd8;


extern "C" u32 func_001322f0(...);  // set_vtbl_347c00
extern u8 D_00347c30;


extern "C" u32 func_001322f0(...);  // set_vtbl_347c00
extern u8 D_00347c30;


extern "C" u32 func_00132170(...);

u32 func_00132c68(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = 0u;
    r15 = *(volatile u32*)((u32)r4 + (s32)(16));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00132170)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    return r2;
}

extern "C" u32 func_00132270(...);  // obj_ctor_347c00
extern u8 D_00347c60;


extern "C" u32 func_00132270(...);  // obj_ctor_347c00
extern u8 D_00347c60;


extern "C" u32 func_001322f0(...);  // set_vtbl_347c00
extern u8 D_00347c60;


extern "C" u32 func_001322f0(...);  // set_vtbl_347c00
extern u8 D_00347c60;


extern "C" u32 func_00132170(...);

u32 func_001333c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = 0u;
    r15 = *(volatile u32*)((u32)r4 + (s32)(16));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00132170)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    return r2;
}

extern "C" u32 func_00133630(...);



extern "C" u32 func_0023a0d8(...);

u32 func_0023a950(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r15 = (u32)(*(u8*)((u32)r4 + (s32)(212)));
    r16 = r4;
    if (r15 == 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0023a0d8)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    r2 = *(volatile u32*)((u32)r16 + (s32)(228));
    return r2;
}

extern "C" u32 func_0023a0d8(...);

u32 func_0023a988(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r15 = (u32)(*(u8*)((u32)r4 + (s32)(212)));
    r16 = r4;
    if (r15 == 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0023a0d8)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    r2 = *(volatile u32*)((u32)r16 + (s32)(232));
    return r2;
}



extern "C" u32 func_00133720(...);


extern "C" u32 func_001337a0(...);


extern "C" u32 func_00133848(...);  // entry16_init_flag16


extern "C" u32 func_00133898(...);  // entry16_init_flag96


extern "C" u32 func_001338e8(...);


extern "C" u32 func_00133630(...);
extern u8 D_00347c88;


extern "C" u32 func_001336d8(...);
extern u8 D_00347c88;


extern "C" u32 func_001336e8(...);
extern u8 D_00347c88;


extern "C" u32 func_00133720(...);
extern u8 D_00347c88;


extern "C" u32 func_00133b88(...);
extern u8 D_00347c88;


extern "C" u32 func_00133bb8(...);  // forward_sub24_to_133848
extern u8 D_00347c88;


extern "C" u32 func_00133c00(...);
extern u8 D_00347c88;


extern "C" u32 func_00133c18(...);
extern u8 D_00347c88;


extern "C" u32 func_00133c60(...);  // forward_sub24_to_133980
extern u8 D_00347c88;


extern "C" u32 func_00133c78(...);
extern u8 D_00347c88;


extern "C" u32 func_00133ac8(...);
extern u8 D_00347c88;


extern "C" u32 func_00133b78(...);
extern u8 D_00347c88;


extern "C" u32 func_00133bb8(...);  // forward_sub24_to_133848
extern u8 D_00347c88;


extern "C" u32 func_00170c00(...);


extern u8 D_003b8b20;


extern u8 D_003b8b20;


extern "C" u32 func_00239c38(...);


extern "C" u32 func_0013b508(...);


extern "C" u32 func_0013db60(...);


extern "C" u32 func_0013dce8(...);
extern u8 D_00348638;


extern "C" u32 func_0013dcb0(...);
extern u8 D_00348638;


extern "C" u32 func_0013dd18(...);
extern u8 D_00348638;


extern "C" u32 func_0013dc38(...);
extern u8 D_00348638;


extern "C" u32 func_0013dc58(...);
extern u8 D_00348638;


extern "C" u32 func_0013e8c0(...);
extern u8 D_003486d8;


extern "C" u32 func_0013e8c0(...);
extern u8 D_003486d8;


extern "C" u32 func_0014df98(...);  // zero_global_byte


extern "C" u32 func_00140dc0(...);
extern "C" u32 func_001410b8(...);

u32 func_00141080(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00141080: definition moved into src/anon/unit_0013fca8.cpp

extern "C" u32 func_00140dc0(...);
extern "C" u32 func_001410b8(...);

u32 func_001410c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001410c8: definition moved into src/anon/unit_0013fca8.cpp

extern "C" u32 func_00143208(...);


extern "C" u32 func_001431e8(...);


extern "C" u32 func_00148a08(...);


extern "C" u32 func_00148a08(...);


extern "C" u32 func_00149370(...);
extern u8 D_0032bae0;


extern "C" u32 func_00170518(...);


extern "C" u32 func_00170950(...);


extern "C" u32 func_001493e8(...);
extern u8 D_00348d68;


extern "C" u32 func_0013dd28(...);


extern "C" u32 func_001ae990(...);
extern "C" u32 func_002b99a0(...);

u32 func_0014a290(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0014a290: moved to src/anon/unit_00149fa8.cpp

extern "C" u32 func_0014b248(...);
extern u8 D_00349270;


extern "C" u32 func_0014b208(...);
extern u8 D_00349270;


extern "C" u32 func_0014ca10(...);  // get_global_359e0c

u32 func_0014ca48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r2 = ((u32(*)())func_0014ca10)();
    r14 = (u32)(0x0035u << 16);
    if (r2 == 0u) {
        r15 = *(volatile u32*)((u32)r14 + (s32)(-25112));
        r15 = (u32)((s32)r15 + (1));
        *(volatile u32*)((u32)r14 + (s32)(-25112)) = r15;
    }
    return r2;
}

extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_0023aa98(...);


extern u8 D_0034a878;


extern "C" u32 func_00139598(...);


extern "C" u32 func_00140df0(...);


void func_0015aea8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0015aea8: definition moved into src/anon/unit_0015a810.cpp

void func_0015c1f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0015c1f0: definition moved into src/anon/unit_0015bab8.cpp

// 0015e018: moved to src/anon/unit_0015d828.cpp

extern "C" u32 func_0014e0d8(...);


extern "C" u32 func_001a2478(...);  // count_div4_compare


extern "C" u32 func_00168b38(...);  // entry_array_find_nth

u32 func_0016a0d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r5 = (u32)((s32)0u + (4));
    r6 = 0u;
    r4 = *(volatile u32*)((u32)r4 + (s32)(1964));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(volatile u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}

extern "C" u32 func_00168b38(...);  // entry_array_find_nth

u32 func_0016a108(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r5 = (u32)((s32)0u + (7));
    r6 = 0u;
    r4 = *(volatile u32*)((u32)r4 + (s32)(1964));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(volatile u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}

extern "C" u32 func_0019c400(...);


extern "C" u32 func_0016cb88(...);
extern "C" u32 func_0016cba0(...);


extern "C" u32 func_0019ec88(...);


extern "C" u32 func_001c0cd8(...);


extern "C" u32 func_0016a070(...);


extern "C" u32 func_0016a020(...);


extern "C" u32 func_0019c4e8(...);


extern "C" u32 func_00198828(...);


extern "C" u32 func_001b9c28(...);


extern "C" u32 func_001b9c58(...);


extern "C" u32 func_0016bd60(...);


extern "C" u32 func_00177460(...);


extern "C" u32 func_001a0798(...);


extern "C" u32 func_0016ac80(...);


extern "C" u32 func_0016ac38(...);


extern "C" u32 func_0016ac38(...);


extern "C" u32 func_0016c008(...);


extern "C" u32 func_00179dd0(...);


extern "C" u32 func_001d6ab0(...);


extern "C" u32 func_001bf100(...);


extern "C" u32 func_00190878(...);


extern "C" u32 func_001913b8(...);


extern "C" u32 func_001bb4a0(...);


extern "C" u32 func_001762c0(...);


extern "C" u32 func_0023f070(...);


extern "C" u32 func_001d68f8(...);
extern u8 D_01c5f530;


extern "C" u32 func_00175bb8(...);

// 0017a298: moved to src/yasui/libys/player.cpp

extern "C" u32 func_001a9780(...);


extern "C" u32 func_00170950(...);

// 0017ebf0: moved to src/yasui/libys/motion.cpp

extern "C" u32 func_00168b88(...);  // find_entry16_by_half_word

// 00181ba8: moved to src/yasui/libys/areadata.cpp

extern "C" u32 func_00168b88(...);  // find_entry16_by_half_word

// 00181be8: moved to src/yasui/libys/areadata.cpp

extern "C" u32 func_00168b88(...);  // find_entry16_by_half_word

// 00181c80: moved to src/yasui/libys/areadata.cpp

extern "C" u32 func_00182780(...);
extern "C" u32 func_00182838(...);


extern "C" u32 func_001849b8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_ZN2YS3OBJ10get_groundEv");

// 0018cef8: moved to src/yasui/libys/damage.cpp

extern "C" u32 func_001a3a78(...);


extern "C" u32 func_001908c0(...);


extern u8 D_01c61970;


extern "C" u32 func_00192c40(...);


extern "C" u32 func_0011c7c8(...);


extern "C" u32 func_0011c7f8(...);


extern "C" u32 func_00168b38(...);  // entry_array_find_nth

u32 func_00195328(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00195328: definition moved into src/anon/unit_00194790.cpp

extern "C" u32 func_00195530(...);


extern u8 D_0032bb30;


extern u8 D_0032bb30;


extern "C" u32 func_0016ced0(...);
extern u8 D_00350338;

void func_001969c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001969c0: definition moved into src/anon/unit_00195d00.cpp

extern "C" u32 func_001977d8(...);
extern "C" u32 func_00197800(...);

u32 func_001977a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001977a0: definition moved into src/anon/unit_00195d00.cpp

extern "C" u32 func_00198bd0(...);

// 00198d20: moved to src/anon/unit_00198b88.cpp

extern "C" u32 func_001a7790(...);

extern "C" u32 func_0016a070(...);


extern "C" u32 func_00154b80(...);

void func_0019cbe8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0019cbe8: definition moved into src/anon/unit_0019ba60.cpp

extern "C" u32 func_0013e4b8(...);

void func_0019d228(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0019d228: definition moved into src/anon/unit_0019ba60.cpp

extern "C" u32 func_0019ba60(...);

u32 func_0019d4a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0019d4a8: definition moved into src/anon/unit_0019ba60.cpp

extern "C" u32 func_0013e4b8(...);

void func_0019d548(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0019d548: definition moved into src/anon/unit_0019ba60.cpp

extern u8 D_0032de28;


extern "C" u32 func_001c6e58(...);
extern u8 D_003507a0;


extern "C" u32 func_001c6e58(...);
extern u8 D_003507a0;


extern "C" u32 func_001c1708(...);
extern "C" u32 func_001c7ee0(...);

// 001a58f8: moved to src/anon/unit_001a4db0.cpp

extern u8 D_0032bb30;


extern "C" u32 func_00168b38(...);  // entry_array_find_nth

u32 func_001a93e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001a93e8: definition moved into src/anon/unit_001a9130.cpp

extern "C" u32 func_00168b38(...);  // entry_array_find_nth

u32 func_001a9420(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001a9420: definition moved into src/anon/unit_001a9130.cpp

extern "C" u32 func_00168b38(...);  // entry_array_find_nth

u32 func_001a9528(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001a9528: definition moved into src/anon/unit_001a9130.cpp

extern "C" u32 func_00168b38(...);  // entry_array_find_nth

u32 func_001a97b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001a97b8: definition moved into src/anon/unit_001a9130.cpp

// 001abd10: moved to src/anon/unit_001abb28.cpp

extern "C" u32 func_001ae460(...);

u32 func_001ae1b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001ae1b0: definition moved into src/anon/unit_001ada38.cpp

extern "C" u32 func_001ae460(...);

u32 func_001ae1e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001ae1e0: definition moved into src/anon/unit_001ada38.cpp

extern u8 D_01c94100;


extern "C" u32 func_001d7cd0(...);
extern u8 D_00350f28;


extern "C" u32 func_001d7cd0(...);
extern u8 D_00350f28;


extern "C" u32 func_001d3f80(...);


extern "C" u32 func_001d4808(...);  // is_halfword42_zero


extern "C" u32 func_001c8ab0(...);

u32 func_001b6d40(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001b6d40: definition moved into src/anon/unit_001b6a50.cpp

extern "C" u32 func_00170950(...);


extern "C" u32 func_001b83f0(...);  // to_2fd248_block8


extern "C" u32 func_001bb020(...);

// 001bb468: moved to src/yasui/libys/mission.cpp
void func_001bb468(void);


extern "C" u32 func_001bd570(...);


extern "C" u32 func_0013b2f8(...);

void func_001bdc48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001bdc48: definition moved into src/anon/unit_001bc568.cpp

extern "C" u32 func_0016a020(...);


extern "C" u32 func_001c0c80(...);


extern "C" u32 func_001b1d20(...);
extern u8 D_00351580;


extern u8 D_01d49658;


extern "C" u32 func_001c7900(...);


extern "C" u32 func_001a4db0(...);
extern u8 D_00351da8;


extern "C" u32 func_001a4db0(...);
extern u8 D_00351f78;


extern "C" u32 func_001a4db0(...);
extern u8 D_00351ff0;


extern "C" u32 func_001a4db0(...);
extern u8 D_00351ff0;


extern "C" u32 func_001a4db0(...);
extern u8 D_00352060;


extern "C" u32 func_001a5420(...);
extern u8 D_0036e228;

// 001cc128: moved to src/anon/unit_001cc048.cpp

extern "C" u32 func_001a4db0(...);
extern u8 D_003520d0;


extern "C" u32 func_001a4db0(...);
extern u8 D_003520d0;


extern "C" u32 func_002875e8(...);


extern "C" u32 func_002875e8(...);


extern "C" u32 func_00287760(...);


extern "C" u32 func_00287760(...);


void func_001d1878(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001d1878: definition moved into src/anon/unit_001d14e0.cpp

extern "C" u32 func_001d1678(...);  // obj_init_28bytes


extern "C" u32 func_0014fa08(...);

void func_001d1c70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001d1c70: definition moved into src/anon/unit_001d14e0.cpp

extern "C" u32 func_0014f9e8(...);

u32 func_001d1ca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001d1ca8: definition moved into src/anon/unit_001d14e0.cpp

extern "C" u32 func_001d1678(...);  // obj_init_28bytes


extern "C" u32 func_0014fb60(...);

void func_001d1ed0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001d1ed0: definition moved into src/anon/unit_001d14e0.cpp

extern "C" u32 func_0014fb40(...);

u32 func_001d1f08(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001d1f08: definition moved into src/anon/unit_001d14e0.cpp

extern "C" u32 func_001d2110(...);


extern "C" u32 func_0014f5d0(...);

void func_001d2710(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001d2710: definition moved into src/anon/unit_001d14e0.cpp

extern "C" u32 func_001a4db0(...);
extern u8 D_00352678;


extern "C" u32 func_001a4db0(...);
extern u8 D_00352678;


extern "C" u32 func_0013d620(...);

void func_001d48b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001d48b0: definition moved into src/anon/unit_001d3c08.cpp

extern u8 D_01d5ba58;


extern "C" u32 func_0014f8d0(...);
extern "C" u32 func_001d16f8(...);


extern "C" u32 func_002bc358(...);

void func_001d5730(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001d5730: definition moved into src/anon/unit_001d4f40.cpp

extern "C" u32 func_001d5a48(...);


extern "C" u32 func_001a4db0(...);
extern u8 D_003527f0;


extern "C" u32 func_001d1678(...);  // obj_init_28bytes


extern "C" u32 func_001bb4a0(...);
extern "C" u32 func_001bbcb0(...);

u32 func_001d8158(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001d8158: definition moved into src/anon/unit_001d7458.cpp

extern u8 D_0032dfd0;


extern "C" u32 func_001a4db0(...);
extern u8 D_00352970;


// 001dbd38: moved to src/anon/unit_001dbbe0.cpp

u32 func_001dcd38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001dcd38: definition moved into src/anon/unit_001dbfd8.cpp

extern "C" u32 func_001e6d28(...);


extern "C" u32 func_001e7030(...);


extern "C" u32 func_001e7050(...);


extern "C" u32 func_001e70a0(...);


extern "C" u32 func_001e02f8(...);


extern "C" u32 func_002bc358(...);

void func_001e21f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001e21f8: definition moved into src/anon/unit_001e0cb8.cpp

extern "C" u32 func_0020df70(...);
extern "C" u32 func_0020e758(...);

void func_001e2b90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001e2b90: definition moved into src/anon/unit_001e0cb8.cpp

extern "C" u32 func_001efc28(...);


extern u8 D_01d9e360;


extern u8 D_01d9e360;


extern "C" u32 func_0021efa8(...);


extern u8 D_01d9e360;


extern u8 D_01d9e360;


u32 func_00221f98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(4));
    r2 = 0u;
    if (r14 != 0u) {
        r15 = *(volatile u32*)((u32)r14 + (s32)(0));
        r2 = r14;
        *(volatile u32*)((u32)r4 + (s32)(4)) = r15;
    }
    return r2;
}

extern "C" u32 func_00242ea8(...);


extern "C" u32 func_001688b8(...);
extern "C" u32 func_00170c50(...);

u32 func_00225a30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001688b8)();
    r15 = (u32)((s32)0u + (1));
    if (r2 == 0u) {
        r2 = ((u32(*)())func_00170c50)();
        r15 = r2;
    }
    r2 = r15;
    return r2;
}

extern "C" u32 func_00224e90(...);
extern "C" u32 func_00225b00(...);  // flag_query_by_index

u32 func_00225b50(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00225b00)();
    r15 = 0u;
    if (r2 != 0u) {
        r2 = ((u32(*)())func_00224e90)();
        r15 = ((u32)0u < (u32)r2);
    }
    r2 = r15;
    return r2;
}

extern "C" u32 func_001d5a38(...);


extern "C" u32 func_001384a0(...);
extern "C" u32 func_0014a4c0(...);


extern "C" u32 func_00225298(...);


extern "C" u32 func_00197920(...) asm("_ZN2YS5EVENT6IsExecEv");
extern "C" u32 func_002ba620(...);

extern "C" u32 func_00228378(u32, u32, u32, u32, u32, u32, u32, u32) asm("_ZN2sa5EVENT16isSceneEventExecEv");

extern "C" u32 func_00139580(...);


extern "C" u32 func_00139570(...);


extern "C" u32 func_0023fad0(...);


extern "C" u32 func_00236cc0(...);


extern "C" u32 func_0023c4b8(...);


extern "C" u32 func_002ef7a0(...);


extern u8 D_01dae480;


extern u8 D_01dae480;


extern u8 D_01dae480;


extern u8 D_01dae480;


extern u8 D_01dae480;


extern "C" u32 func_00237238(...);
extern u8 D_0035eaf8;


extern "C" u32 func_00237238(...);
extern u8 D_0035eaf8;


extern "C" u32 func_00239c68(...);

void func_00239bf8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r15 = ((u32*)(u32)r4)[69];
    r16 = r4;
    if (r15 != r5) {
        ((void(*)())func_00239c68)();
        r15 = (u32)((s32)0u + (1));
        ((u32*)(u32)r16)[65] = 0u;
        ((u32*)(u32)r16)[63] = r15;
    }
}

extern "C" u32 func_00236cc0(...);


extern "C" u32 func_0023f070(...);


extern "C" u32 func_0023f8a8(...);
extern u8 D_0035ebd8;


extern "C" u32 func_0023f8a8(...);
extern u8 D_0035ebd8;


extern "C" u32 func_00168b38(...);  // entry_array_find_nth

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

extern "C" u32 func_00168b38(...);  // entry_array_find_nth

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

extern "C" u32 func_00168b38(...);  // entry_array_find_nth

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

extern "C" u32 func_00168b38(...);  // entry_array_find_nth

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

extern "C" u32 func_00170518(...);


extern "C" u32 func_00181500(...);


extern "C" u32 func_00106450(...);

void func_00242048(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(4));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00106450)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(4)) = 0u;
    }
    *(volatile u32*)((u32)r16 + (s32)(0)) = 0u;
}

extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);
extern "C" u32 func_00242560(...);


extern "C" u32 func_002ba2e8(...);


extern "C" u32 func_002ba9c0(...);
extern "C" u32 func_002bd6d0(...);
extern "C" u32 func_002ef7b8(...);


extern "C" u32 func_002ba8e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_001058e8(...);


extern "C" u32 func_002431c0(...);


extern u8 D_00371b30;
extern u8 D_00371bc0;

u32 func_00246868(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00246840)();
    r15 = (u32)&D_00371bc0;
    if (r2 == 0u) {
    r15 = (u32)&D_00371b30;
    }
    r2 = r15;
    return r2;
}

extern "C" u32 func_00246840(...);
extern u8 D_0035eee0;


extern u8 D_01dae6c0;


extern u8 D_0035ef78;


extern "C" u32 func_002577b0(...);
extern "C" u32 func_00257910(...);

u32 func_00257780(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r2 = ((u32(*)())func_002577b0)();
    if (r2 == 0u) {
        r2 = ((u32(*)())func_00257910)();
    }
    return r2;
}

extern "C" u32 func_001058e8(...);


extern "C" u32 func_00192c90(...);


extern "C" u32 func_002817b8(...);


extern "C" u32 func_00257770(...);

u32 func_00262f18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00262f18: definition moved into src/anon/unit_0025f6b8.cpp

extern "C" u32 func_00257770(...);


extern "C" u32 func_00106420(...);

void func_002643d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002643d0: definition moved into src/anon/unit_002640a8.cpp

extern "C" u32 func_001a3168(...);


extern "C" u32 func_00106420(...);

void func_0026eda8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0026eda8: definition moved into src/anon/unit_0026c450.cpp

extern u8 D_0035f158;


extern "C" u32 func_002766b0(...);


extern "C" u32 func_00106420(...);

void func_00277070(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00277070: definition moved into src/anon/unit_002748a0.cpp

extern "C" u32 func_00106450(...);

void func_0027c508(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0027c508: definition moved into src/anon/unit_0027a6d8.cpp

extern "C" u32 func_001058e8(...);


extern "C" u32 func_00287bd0(...);


extern "C" u32 func_00139d78(...);
extern "C" u32 func_0023d820(...);
extern "C" u32 func_00287dc0(...);

u32 func_002763c8(u32 a0);  // 0x002763c8: definition moved into src/anon/unit_002748a0.cpp

extern "C" u32 func_0023fa08(...);
extern "C" u32 func_002537c8(...);
extern u8 D_0035f3a8;

u32 duplicate_unplaced_00276410(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r4 = (u32)((s32)0u + (3));
    r2 = ((u32(*)(u32,u32))func_002537c8)(r4, r5);
    r4 = (u32)&D_0035f3a8;
    r5 = r2;
    return ((u32(*)(u32,u32))func_0023fa08)(r4, r5);
}

extern "C" u32 func_00276608(...);
extern "C" u32 func_00276620(...);

u32 duplicate_unplaced_00276638(u32 a0) {
    u32 r4 = a0, r2, r16, r17;
    r17 = r4;
    r2 = ((u32(*)(u32))func_00276608)(r4);
    r4 = r17;
    r16 = r2;
    r2 = ((u32(*)(u32))func_00276620)(r4);
    r16 = (u32)(r16 + r2);
    r2 = r16;
    return r2;
}

extern "C" u32 func_00192048(...);
extern "C" u32 func_00276c88(...);

u32 duplicate_unplaced_00276c50(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r2 = 0u;
    r16 = (u32)(r5 & 0x00ffu);
    if ((s32)r4 >= 0) {
        r2 = ((u32(*)(u32,u32))func_00192048)(r4, r5);
    }
    r5 = r16;
    r4 = r2;
    return ((u32(*)(u32,u32))func_00276c88)(r4, r5);
}

extern "C" u32 func_00139510(...);
extern "C" u32 func_00276df8(...);

void func_00276e28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00276e28: definition moved into src/anon/unit_002748a0.cpp

extern "C" u32 func_00139510(...);
extern "C" u32 func_00139d78(...);

void func_00276f60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00276f60: definition moved into src/anon/unit_002748a0.cpp

extern "C" u32 func_00257770(...);
extern "C" u32 func_0028dac8(...);

u32 duplicate_unplaced_0027b4e8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r2 = ((u32(*)())func_00257770)();
    r15 = (u32)(0u | 0xb350u);
    r5 = (u32)((s32)0u + (274));
    r4 = (u32)(r2 + r15);
    return ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
}

extern "C" u32 func_0027d2e8(...);
extern "C" u32 func_00287bc0(...);

u32 func_0027c540(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0027c540: definition moved into src/anon/unit_0027a6d8.cpp

extern "C" u32 func_0027d350(...);
extern "C" u32 func_00287bc0(...);

extern "C" u32 func_00139d78(...);
extern "C" u32 func_0027d008(...);
extern "C" u32 func_0027d540(...);
extern "C" u32 func_0027d5d8(...);
extern "C" u32 func_0027d810(...);
extern "C" u32 func_0028b040(...);

u32 duplicate_unplaced_0027d598(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0027d008)(r4);
    r2 = ((u32(*)())func_0027d540)();
    r2 = ((u32(*)())func_0027d5d8)();
    r4 = r16;
    r2 = ((u32(*)(u32))func_0028b040)(r4);
    r4 = r2;
    return ((u32(*)(u32))func_0027d810)(r4);
}

extern "C" u32 func_00287db0(...);
extern "C" u32 func_0028dac8(...);

u32 func_0027dbd8(u32 a0, u32 a1);  // 0x0027dbd8: definition moved into src/anon/unit_0027d2e8.cpp

extern "C" u32 func_002800d0(...) asm("_ZN2Tz9GumiPause12UpdateAdviceEv");
extern "C" u32 func_00280148(...);
extern "C" u32 func_00287cc0(...);

u32 duplicate_unplaced_0027f9b0(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_00280148)();
    r2 = ((u32(*)())func_002800d0)();
    r4 = 0u;
    return ((u32(*)(u32))func_00287cc0)(r4);
}

extern "C" u32 func_0028dac8(...);

u32 duplicate_unplaced_00280240(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r5 = (u32)((s32)0u + (9));
    r16 = (u32)(0x0036u << 16);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-3484));
    r4 = (u32)((s32)r4 + (24));
    r2 = ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-3484));
    r5 = (u32)((s32)0u + (12));
    r4 = (u32)((s32)r4 + (460));
    r2 = ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-3484));
    r5 = (u32)((s32)0u + (3));
    r4 = (u32)((s32)r4 + (896));
    return ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
}

extern "C" u32 func_0028da70(...);

u32 duplicate_unplaced_002803e0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r5 = (u32)((s32)0u + (8));
    r16 = (u32)(0x0036u << 16);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-3484));
    r4 = (u32)((s32)r4 + (24));
    r2 = ((u32(*)(u32,u32))func_0028da70)(r4, r5);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-3484));
    r5 = (u32)((s32)0u + (11));
    r4 = (u32)((s32)r4 + (460));
    return ((u32(*)(u32,u32))func_0028da70)(r4, r5);
}

extern "C" u32 func_0023fa08(...);
extern "C" u32 func_002537c8(...);
extern u8 D_0035f3a8;

u32 duplicate_unplaced_002806c8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r4 = (u32)((s32)0u + (5));
    r2 = ((u32(*)(u32,u32))func_002537c8)(r4, r5);
    r4 = (u32)&D_0035f3a8;
    r5 = r2;
    return ((u32(*)(u32,u32))func_0023fa08)(r4, r5);
}

extern "C" u32 func_00280ef8(...);
extern "C" u32 func_00281008(...);

u32 duplicate_unplaced_002810c8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16, r17;
    r16 = r4;
    r17 = r5;
    r2 = ((u32(*)(u32,u32))func_00281008)(r4, r5);
    r4 = r16;
    r5 = r17;
    return ((u32(*)(u32,u32))func_00280ef8)(r4, r5);
}

extern "C" u32 func_0016e920(...);
extern "C" u32 func_00281238(...);

u32 duplicate_unplaced_00281108(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_00281238)();
    r4 = r2;
    return ((u32(*)(u32))func_0016e920)(r4);
}

extern "C" u32 func_001a3570(...);
extern "C" u32 func_001a36e0(...);
extern "C" u32 func_002812e0(...);

u32 func_00281340(u32 a0);  // 0x00281340: definition moved into src/anon/unit_0027f2b0.cpp

extern "C" u32 func_00170320(...);
extern "C" u32 func_0023f900(...);
extern "C" u32 func_0023fad0(...);
extern "C" u32 func_00293d80(...);
extern "C" u32 func_00293eb0(...);
extern "C" u32 func_00293db8(...) asm("_ZN2Tz6JMData10CacheAllocEiPKc");

u32 func_00285460(u32 a0);  // 0x00285460: definition moved into src/anon/unit_002853b8.cpp

extern "C" u32 func_0023fa08(...);
extern "C" u32 func_002537c8(...);

u32 duplicate_unplaced_00288610(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r4 = 0u;
    r2 = ((u32(*)(u32,u32))func_002537c8)(r4, r5);
    r15 = (u32)(0x0036u << 16);
    r4 = *(volatile u32*)((u32)r15 + (s32)(-3276));
    r5 = r2;
    return ((u32(*)(u32,u32))func_0023fa08)(r4, r5);
}

extern "C" u32 func_00288ca8(...);


extern "C" u32 func_0028b870(...);
extern u8 D_0035f3a0;

u32 duplicate_unplaced_0028b750(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0023f7e0)(r4);
    r15 = (u32)&D_0035f3a0;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return ((u32(*)(u32))func_0028b870)(r4);
}

extern "C" u32 func_0028b870(...);
extern u8 D_0035f3a0;

u32 duplicate_unplaced_0028b788(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0023f7e0)(r4);
    r15 = (u32)&D_0035f3a0;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return ((u32(*)(u32))func_0028b870)(r4);
}

extern "C" u32 func_0023f820(...);
extern "C" u32 func_0028b8a0(...);
extern u8 D_0035f3a0;

u32 duplicate_unplaced_0028b7f8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035f3a0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    u32 (*fp_call4_0028b8a0)(u32) = (u32(*)(u32))func_0028b8a0;
    r2 = fp_call4_0028b8a0(r4);
    r4 = r16;
    u32 (*fp_call4_0023f820)(u32) = (u32(*)(u32))func_0023f820;
    r2 = fp_call4_0023f820(r4);
    return r2;
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_0023f820(...);
extern "C" u32 func_0028b8a0(...);
extern u8 D_0035f3a0;

u32 duplicate_unplaced_0028b830(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035f3a0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0028b8a0)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_0023f820)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00139510(...);
extern "C" u32 func_00139d78(...);

u32 duplicate_unplaced_0028c170(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00139d78)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00139510)(r4);
}

extern "C" u32 func_00239700(...);
extern "C" u32 func_0028d188(...);
extern u8 D_00347e60;
extern u8 D_0035f420;

u32 duplicate_unplaced_0028d0f8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    ((u32*)(u32)r4)[3] = 0u;
    r15 = (u32)&D_00347e60;
    ((u32*)(u32)r4)[0] = r15;
    r16 = r4;
    r4 = (u32)((s32)r4 + (24));
    r2 = ((u32(*)(u32))func_00239700)(r4);
    r15 = (u32)&D_0035f420;
    r4 = r16;
    ((u32*)(u32)r16)[0] = r15;
    return ((u32(*)(u32))func_0028d188)(r4);
}

extern "C" u32 func_00239700(...);
extern "C" u32 func_0028d188(...);
extern u8 D_00347e60;
extern u8 D_0035f420;

u32 duplicate_unplaced_0028d140(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    ((u32*)(u32)r4)[3] = 0u;
    r15 = (u32)&D_00347e60;
    ((u32*)(u32)r4)[0] = r15;
    r16 = r4;
    r4 = (u32)((s32)r4 + (24));
    r2 = ((u32(*)(u32))func_00239700)(r4);
    r15 = (u32)&D_0035f420;
    r4 = r16;
    ((u32*)(u32)r16)[0] = r15;
    return ((u32(*)(u32))func_0028d188)(r4);
}

extern "C" u32 func_00138d48(...);
extern "C" u32 func_001395f8(...);

u32 duplicate_unplaced_0028d708(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00138d48)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001395f8)(r4);
}

extern "C" u32 func_00139d78(...);


extern "C" u32 func_00139d78(...);


extern "C" u32 func_00139d78(...);


extern "C" u32 func_00139d78(...);
extern "C" u32 func_00239d30(...);

u32 duplicate_unplaced_0028e6c0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16, r17;
    r16 = r5;
    r17 = r4;
    r2 = ((u32(*)(u32,u32))func_00139d78)(r4, r5);
    r15 = (u32)((s32)0u + (380));
    r4 = *(volatile u32*)((u32)r17 + (s32)(56));
    r16 = (u32)((s32)r16 * (s32)r15);
    r4 = (u32)(r4 + r16);
    r5 = *(volatile u32*)((u32)r4 + (s32)(276));
    r2 = ((u32(*)(u32,u32))func_00239d30)(r4, r5);
    r2 = (u32)(r2 & 0x00ffu);
    return r2;
}

extern "C" u32 func_00139d78(...);


extern "C" u32 func_00139d78(...);


extern "C" u32 func_00139d78(...);


extern "C" u32 func_00139d78(...);


extern "C" u32 func_00192048(...);
extern "C" u32 func_0028fb68(...);

u32 duplicate_unplaced_0028fb28(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r2 = 0u;
    r16 = r4;
    r4 = r5;
    if ((s32)r5 >= 0) {
        r2 = ((u32(*)(u32,u32))func_00192048)(r4, r5);
    }
    r4 = r16;
    r5 = r2;
    return ((u32(*)(u32,u32))func_0028fb68)(r4, r5);
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_002908f0(...);
extern u8 D_0035f4b0;

u32 duplicate_unplaced_00290870(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035f4b0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002908f0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00170518(...);


u32 func_00292520(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 00292520: moved to src/anon/unit_00290f78.cpp

extern "C" u32 func_00292690(...) asm("_ZN2Tz8LoadData5ClearEi");


extern "C" u32 func_00290948(...);
extern "C" u32 func_002941a8(...) asm("_ZN2Tz6JmInfo11isWorldOpenEPKNS_15JmWorldDataInfoE");

extern "C" u32 func_00181500(...);


extern "C" u32 func_001d44d8(...);
extern "C" u32 func_001d4550(...);


extern "C" u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00294ea8(...);

u32 func_002945a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002945a8: definition moved into src/anon/unit_00292e60.cpp

extern "C" u32 func_002953c8(...);

u32 duplicate_unplaced_002954e0(u32 a0) {
    u32 r4 = a0, r2;
    u32 (*fp_call0_002953c8)() = (u32(*)())func_002953c8;
    r2 = fp_call0_002953c8();
    r4 = r2;
    u32 (*fp_call4_002941a8)(u32) = (u32(*)(u32))func_002941a8;
    r2 = fp_call4_002941a8(r4);
    return r2;
}

extern "C" u32 func_00295158(...);

u32 duplicate_unplaced_002956c0(u32 a0) {
    u32 r4 = a0, r2, r16, r17;
    r17 = r4;
    r4 = 0u;
    u32 (*fp_call4_00294000)(u32) = (u32(*)(u32))func_00294000;
    r2 = fp_call4_00294000(r4);
    r4 = r17;
    r16 = (u32)((s32)r2 + (16));
    u32 (*fp_call4_00295158)(u32) = (u32(*)(u32))func_00295158;
    r2 = fp_call4_00295158(r4);
    r2 = (u32)(r2 << 4);
    r16 = (u32)(r16 + r2);
    r4 = r16;
    u32 (*fp_call4_002941a8)(u32) = (u32(*)(u32))func_002941a8;
    r2 = fp_call4_002941a8(r4);
    return r2;
}

extern "C" u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00296ab0(...);

u32 func_00295868(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00295868: definition moved into src/anon/unit_00292e60.cpp

extern "C" u32 func_00103570(...);
extern "C" u32 func_001063c0(...);

u32 duplicate_unplaced_00296fa0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r2 = ((u32(*)())func_00103570)();
    r5 = r2;
    r4 = (u32)((s32)0u + (520));
    r2 = ((u32(*)(u32,u32))func_001063c0)(r4, r5);
    r15 = (u32)(0x0036u << 16);
    *(volatile u32*)((u32)r15 + (s32)(-2668)) = r2;
    return r2;
}

extern "C" u32 func_00106420(...);

void func_00296fd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00296fd0: definition moved into src/anon/unit_00295d28.cpp



extern "C" u32 func_002766d0(...);
extern "C" u32 func_0028dac8(...);

u32 duplicate_unplaced_00299238(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_002766d0)();
    r4 = (u32)((s32)r2 + (17304));
    r5 = (u32)((s32)0u + (3));
    return ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
}

extern "C" u32 func_00276c50(...);
extern "C" u32 func_00287bc0(...);

u32 duplicate_unplaced_00299260(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r2 = ((u32(*)())func_00287bc0)();
    r2 = (u32)(r2 ^ 0x0004u);
    r15 = (u32)((s32)0u + (18649));
    r4 = (u32)((s32)0u + (18648));
    r5 = 0u;
    if (r2 != 0u) r4 = r15;
    return ((u32(*)(u32,u32))func_00276c50)(r4, r5);
}

extern "C" u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_0029a310(...);

u32 func_002995a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002995a8: definition moved into src/anon/unit_002982f0.cpp



extern "C" u32 func_002766d0(...);
extern "C" u32 func_0028dac8(...);

u32 duplicate_unplaced_0029df98(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_002766d0)();
    r4 = (u32)((s32)r2 + (17304));
    r5 = (u32)((s32)0u + (3));
    return ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
}

extern "C" u32 func_002766d0(...);
extern "C" u32 func_0028dac8(...);

u32 duplicate_unplaced_0029e050(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_002766d0)();
    r4 = (u32)((s32)r2 + (18528));
    r5 = (u32)((s32)0u + (6));
    return ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
}

extern "C" u32 func_00139d78(...);
extern "C" u32 func_002766d0(...);

u32 duplicate_unplaced_0029e0d0(u32 a0) {
    u32 r4 = a0, r2;
    u32 (*fp_call0_002766d0)() = (u32(*)())func_002766d0;
    r2 = fp_call0_002766d0();
    r4 = (u32)((s32)r2 + (18528));
    u32 (*fp_call4_00139d78)(u32) = (u32(*)(u32))func_00139d78;
    r2 = fp_call4_00139d78(r4);
    return r2;
}

extern "C" u32 func_002766d0(...);
extern "C" u32 func_0028da70(...);

u32 duplicate_unplaced_0029e148(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_002766d0)();
    r4 = (u32)((s32)r2 + (18528));
    r5 = (u32)((s32)0u + (5));
    return ((u32(*)(u32,u32))func_0028da70)(r4, r5);
}

extern "C" u32 func_002766d0(...);
extern "C" u32 func_0028dac8(...);

u32 duplicate_unplaced_0029e258(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_002766d0)(r4, r5);
    r16 = (u32)((s32)r16 + (1));
    r15 = (u32)((s32)0u + (408));
    r16 = (u32)((s32)r16 * (s32)r15);
    r5 = (u32)((s32)0u + (9));
    r4 = (u32)(r2 + r16);
    r4 = (u32)((s32)r4 + (17304));
    return ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
}

extern "C" u32 func_00139d78(...);
extern "C" u32 func_002766d0(...);

u32 duplicate_unplaced_0029e2f8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    u32 (*fp_call4_002766d0)(u32) = (u32(*)(u32))func_002766d0;
    r2 = fp_call4_002766d0(r4);
    r16 = (u32)((s32)r16 + (1));
    r15 = (u32)((s32)0u + (408));
    r16 = (u32)((s32)r16 * (s32)r15);
    r4 = (u32)(r2 + r16);
    r4 = (u32)((s32)r4 + (17304));
    u32 (*fp_call4_00139d78)(u32) = (u32(*)(u32))func_00139d78;
    r2 = fp_call4_00139d78(r4);
    return r2;
}

extern "C" u32 func_002766d0(...);
extern "C" u32 func_0028da70(...);

u32 duplicate_unplaced_0029e3a0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_002766d0)(r4, r5);
    r16 = (u32)((s32)r16 + (1));
    r15 = (u32)((s32)0u + (408));
    r16 = (u32)((s32)r16 * (s32)r15);
    r5 = (u32)((s32)0u + (8));
    r4 = (u32)(r2 + r16);
    r4 = (u32)((s32)r4 + (17304));
    return ((u32(*)(u32,u32))func_0028da70)(r4, r5);
}

extern "C" u32 func_00276c50(...);
extern "C" u32 func_00287bc0(...);

u32 duplicate_unplaced_002a03a0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r2 = ((u32(*)())func_00287bc0)();
    r2 = (u32)(r2 ^ 0x0018u);
    r15 = (u32)((s32)0u + (18669));
    r4 = (u32)((s32)0u + (18668));
    r5 = 0u;
    if (r2 != 0u) r4 = r15;
    return ((u32(*)(u32,u32))func_00276c50)(r4, r5);
}

extern "C" u32 func_00139510(...);
extern "C" u32 func_00139d78(...);


extern "C" u32 func_00294000(...) asm("_ZN2Tz6JmInfo7GetDataEi");
extern "C" u32 func_001d9d48(...);


extern "C" u32 func_00276c50(...);
extern "C" u32 func_00287bc0(...);

u32 duplicate_unplaced_002a65a0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r2 = ((u32(*)())func_00287bc0)();
    r2 = (u32)(r2 ^ 0x0025u);
    r15 = (u32)((s32)0u + (19200));
    r4 = (u32)((s32)0u + (18680));
    r5 = 0u;
    if (r2 != 0u) r4 = r15;
    return ((u32(*)(u32,u32))func_00276c50)(r4, r5);
}

extern "C" u32 func_001058e8(...);


u32 func_002b2338(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r12, r13, r14, r15;
    r15 = (u32)(0x0036u << 16);
    r13 = 0u;
    r14 = *(u32*)((u32)r15 + (s32)(-2512));
    r2 = 0u;
    r12 = (u32)(0x0100u << 16);
    while (1) {
        r15 = *(u32*)((u32)r14 + (s32)(0));
        r15 = (u32)(r15 & r12);
        r14 = (u32)((s32)r14 + (36));
        if (r15 != 0u) {
            if (r13 == r4) break;
            r13 = (u32)((s32)r13 + (1));
        }
        r2 = (u32)((s32)r2 + (1));
        r15 = ((s32)r2 < (s32)10);
        if (r15 == 0u) break;
    }
    return r2;
}

extern "C" u32 func_002ac678(...);
extern "C" u32 func_002b23e0(...);  // list_entry_by_index_checked

u32 duplicate_unplaced_002b3420(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_002b23e0)();
    r4 = (u32)(*(u8*)((u32)r2 + (s32)(2)));
    return ((u32(*)(u32))func_002ac678)(r4);
}

extern u8 D_00374cd0;


extern "C" u32 func_002b56e8(...);
extern "C" u32 func_002b5978(...);

u32 func_002b5a20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r2 = ((u32(*)())func_002b56e8)();
    if (r2 == 0u) {
        r2 = ((u32(*)())func_002b5978)();
    }
    return r2;
}


extern u8 D_00374d30;


extern "C" u32 func_002b7fbc(...);
extern "C" u32 func_002b9b78(...);
extern "C" u32 func_002b9ed0(...);
extern "C" u32 func_002ba390(...);
extern "C" u32 func_002bce40(...);
extern "C" u32 func_002bce50(...);
extern u8 D_01e2a410;

u32 duplicate_unplaced_002b9e80(u32 a0) {
    u32 r4 = a0, r2, r16;
    r4 = 0u;
    r16 = (u32)&D_01e2a410;
    r2 = ((u32(*)(u32))func_002b7fbc)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_002bce40)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_002bce50)(r4);
    r2 = ((u32(*)())func_002b9b78)();
    r2 = ((u32(*)())func_002ba390)();
    return ((u32(*)())func_002b9ed0)();
}

extern "C" u32 func_002baf38(...);


extern "C" u32 func_002ba2e8(...);


extern "C" u32 func_002b6c04(...);
extern u8 D_01e2a400;


extern "C" u32 func_002bb228(...);
extern "C" u32 func_002bc158(...);

u32 func_002bc1e8(u32 a0, u32 a1);  // 0x002bc1e8: definition moved into src/anon/unit_002bb8b0.cpp

extern "C" u32 func_002bb270(...);
extern "C" u32 func_002bc158(...);

u32 func_002bc238(u32 a0, u32 a1);  // 0x002bc238: definition moved into src/anon/unit_002bb8b0.cpp

extern "C" u32 func_002bbda0(...);

u32 func_002bc3f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bc3f0: definition moved into src/anon/unit_002bb8b0.cpp

extern "C" u32 func_002bb510(...);
extern "C" u32 func_002bbda0(...);

u32 func_002bc420(u32 a0);  // 0x002bc420: definition moved into src/anon/unit_002bb8b0.cpp

extern "C" u32 func_002bb0c8(...);


extern "C" u32 func_002b6ab8(...);
extern "C" u32 func_002b6adc(...);

u32 duplicate_unplaced_002bd188(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r4 = (u32)((s32)0u + (2));
    r16 = r5;
    r2 = ((u32(*)(u32,u32))func_002b6adc)(r4, r5);
    r5 = r16;
    r4 = 0u;
    r2 = ((u32(*)(u32,u32))func_002b6adc)(r4, r5);
    return ((u32(*)())func_002b6ab8)();
}

extern "C" u32 func_002bd2a8(...);


extern "C" u32 func_00105110(...);
extern "C" u32 func_002bdac8(...);

void func_002be3c8(u32 a0);  // 0x002be3c8: definition moved into src/anon/unit_002be020.cpp

extern "C" u32 func_0016fa98(...);  // set_table_word
extern "C" u32 func_002c23d8(...);
extern "C" u32 func_002f17e0(...);


extern "C" u32 func_001b6d70(...);  // table_entry_ptr_b
extern "C" u32 func_002bf650(...);

u32 duplicate_unplaced_002bf618(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(2808));
    r4 = (u32)(*(u8*)((u32)r15 + (s32)(4)));
    r2 = ((u32(*)(u32,u32))func_001b6d70)(r4, r5);
    r4 = r16;
    r5 = r2;
    return ((u32(*)(u32,u32))func_002bf650)(r4, r5);
}

extern "C" u32 func_00105110(...);
extern u8 D_00361da8;


extern "C" u32 func_002c6218(...);
extern "C" u32 func_002c6280(...);

u32 duplicate_unplaced_002c0700(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_002c6218)();
    r4 = r2;
    r5 = (u32)((s32)0u + (1));
    return ((u32(*)(u32,u32))func_002c6280)(r4, r5);
}

extern "C" u32 func_002c14a8(...);

void func_002c17a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = (u32)(0x0036u << 16);
    r15 = *(volatile u32*)((u32)r16 + (s32)(6800));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002c14a8)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(6800)) = 0u;
    }
}

extern "C" u32 func_0016bd60(...);


extern "C" u32 func_0016c008(...);


extern "C" u32 func_00103748(...);
extern "C" u32 func_00170c00(...);
extern "C" u32 func_00274f50(...);
extern "C" u32 func_00288b78(...);
extern "C" u32 func_0028c4f8(...);
extern "C" u32 func_0028ca78(...);

u32 func_002c2458(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = (u32)(0x0036u << 16);
    r2 = ((u32(*)())func_00274f50)();
    r2 = ((u32(*)())func_0028ca78)();
    r2 = ((u32(*)())func_0028c4f8)();
    r2 = ((u32(*)())func_00288b78)();
    r2 = ((u32(*)())func_00103748)();
    r4 = *(volatile u32*)((u32)r16 + (s32)(7176));
    r2 = ((u32(*)(u32))func_00170c00)(r4);
    *(volatile u32*)((u32)r16 + (s32)(7176)) = 0u;
    return r2;
}

extern "C" u32 func_002c5508(...);
extern u8 D_00361c40;


extern "C" u32 func_001980d0(...);
extern u8 D_00361ca0;


extern "C" u32 func_001984b8(...);
extern "C" u32 func_001dc920(...);

u32 func_002c56d0(u32 a0);  // 0x002c56d0: definition moved into src/anon/unit_002c53c8.cpp

extern "C" u32 func_0016bd60(...);
extern "C" u32 func_001780d8(...);
extern "C" u32 func_002c6c60(...);

u32 duplicate_unplaced_002c58c8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001780d8)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (47));
    r2 = ((u32(*)(u32,u32))func_0016bd60)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(2872));
    r4 = r16;
    return ((u32(*)(u32,u32))func_002c6c60)(r4, r5);
}

extern "C" u32 func_001b9c28(...);


extern "C" u32 func_001b9c58(...);


extern "C" u32 func_002c8550(...);

void func_002c8648(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = (u32)(0x0036u << 16);
    r15 = *(volatile u32*)((u32)r16 + (s32)(7640));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002c8550)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(7640)) = 0u;
    }
}

extern u8 D_003757e0;


void func_002ca0a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = (u32)(0x0036u << 16);
    r15 = *(volatile u32*)((u32)r16 + (s32)(7680));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002c9ed8)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(7680)) = 0u;
    }
}

extern "C" u32 func_00105110(...);
extern u8 D_00361da8;


extern "C" u32 func_002c6218(...);
extern "C" u32 func_002c6280(...);

u32 duplicate_unplaced_002cb160(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_002c6218)();
    r4 = r2;
    r5 = (u32)((s32)0u + (2));
    return ((u32(*)(u32,u32))func_002c6280)(r4, r5);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_002cf3f8(...);
extern u8 D_00361f70;

u32 duplicate_unplaced_002ceaa8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00361f70;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002cf3f8)(r4);
    r15 = (u32)(0x0036u << 16);
    *(volatile u32*)((u32)r15 + (s32)(8032)) = 0u;
    r4 = r16;
    *(volatile u8*)((u32)r16 + (s32)(88)) = (u8)0u;
    return ((u32(*)(u32))func_00105110)(r4);
}

u32 func_002ceb08(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 002ceb08: moved to src/taito/minigame_base.cpp (linked unit)

extern "C" u32 func_002cec08(...);

u32 func_002cec20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 002cec20: moved to src/taito/minigame_base.cpp (linked unit)

extern "C" u32 func_002cec08(...);


extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_002cff98(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    u32 (*fp_call4_0019f9a8)(u32) = (u32(*)(u32))func_0019f9a8;
    r2 = fp_call4_0019f9a8(r4);
    r4 = (u32)((s32)r16 + (2640));
    u32 (*fp_call4_001c0248)(u32) = (u32(*)(u32))func_001c0248;
    r2 = fp_call4_001c0248(r4);
    r4 = r16;
    u32 (*fp_call4_00319fb0)(u32) = (u32(*)(u32))func_00319fb0;
    r2 = fp_call4_00319fb0(r4);
    return r2;
}

extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_002cffe0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    u32 (*fp_call4_0019f9a8)(u32) = (u32(*)(u32))func_0019f9a8;
    r2 = fp_call4_0019f9a8(r4);
    r4 = (u32)((s32)r16 + (2640));
    u32 (*fp_call4_001c0248)(u32) = (u32(*)(u32))func_001c0248;
    r2 = fp_call4_001c0248(r4);
    r4 = r16;
    u32 (*fp_call4_00319fb0)(u32) = (u32(*)(u32))func_00319fb0;
    r2 = fp_call4_00319fb0(r4);
    return r2;
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_002d0028(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    r2 = ((u32(*)(u32))func_0019f9a8)(r4);
    r4 = (u32)((s32)r16 + (2640));
    r2 = ((u32(*)(u32))func_001c0248)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00319fb0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00186020(...);
extern "C" u32 func_001dc818(...);

u32 func_002d0d48(u32 a0);  // 0x002d0d48: definition moved into src/anon/unit_002cf260.cpp

extern "C" u32 func_002cea28(...);
extern u8 D_00362158;


extern "C" u32 func_002cea28(...);
extern u8 D_00362158;


extern "C" u32 func_00105110(...);
extern "C" u32 func_002cea28(...);
extern u8 D_00362158;

u32 duplicate_unplaced_002d1840(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362158;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002cea28)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002d1f40(...);


extern u8 D_00362230;


extern u8 D_00362230;


extern "C" u32 func_00105110(...);
extern u8 D_00362230;

u32 duplicate_unplaced_002d2a58(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362230;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002cff98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002e7328(...);  // to_2e7458
extern u8 D_003621a0;

u32 duplicate_unplaced_002d47a8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003621a0;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (3208));
    u32 (*fp_call4_002e7328)(u32) = (u32(*)(u32))func_002e7328;
    r2 = fp_call4_002e7328(r4);
    r4 = r16;
    u32 (*fp_call4_002d2a08)(u32) = (u32(*)(u32))func_002d2a08;
    r2 = fp_call4_002d2a08(r4);
    return r2;
}

extern "C" u32 func_002e7328(...);  // to_2e7458
extern u8 D_003621a0;

u32 duplicate_unplaced_002d47e8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003621a0;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (3208));
    u32 (*fp_call4_002e7328)(u32) = (u32(*)(u32))func_002e7328;
    r2 = fp_call4_002e7328(r4);
    r4 = r16;
    u32 (*fp_call4_002d2a08)(u32) = (u32(*)(u32))func_002d2a08;
    r2 = fp_call4_002d2a08(r4);
    return r2;
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_002e7328(...);  // to_2e7458
extern u8 D_003621a0;

u32 duplicate_unplaced_002d4828(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003621a0;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (3208));
    r2 = ((u32(*)(u32))func_002e7328)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_002d2a08)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_001c0cd8(...);

u32 func_002d5c98(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002d5c98: definition moved into src/anon/unit_002d4548.cpp

extern "C" u32 func_002e7328(...);  // to_2e7458
extern u8 D_00362428;

u32 duplicate_unplaced_002d5dd0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362428;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2872));
    u32 (*fp_call4_002e7328)(u32) = (u32(*)(u32))func_002e7328;
    r2 = fp_call4_002e7328(r4);
    r4 = r16;
    u32 (*fp_call4_002cff98)(u32) = (u32(*)(u32))func_002cff98;
    r2 = fp_call4_002cff98(r4);
    return r2;
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_002e7328(...);  // to_2e7458
extern u8 D_00362428;

u32 duplicate_unplaced_002d5e10(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362428;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2872));
    r2 = ((u32(*)(u32))func_002e7328)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_002cff98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002cfeb0(...);  // obj_init_field1416_bit800
extern u8 D_00362398;


extern "C" u32 func_002cfeb0(...);  // obj_init_field1416_bit800
extern u8 D_00362398;


extern u8 D_00362398;


extern u8 D_00362398;


extern "C" u32 func_00105110(...);
extern u8 D_00362398;

u32 duplicate_unplaced_002d6af0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362398;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002cff98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_00362858;


extern "C" u32 func_00105110(...);
extern u8 D_00362858;

u32 duplicate_unplaced_002dab30(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362858;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002cff98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_003627c8;


extern u8 D_003627c8;


extern "C" u32 func_00105110(...);
extern u8 D_003627c8;

u32 duplicate_unplaced_002dad40(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003627c8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002cff98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002cfeb0(...);  // obj_init_field1416_bit800
extern u8 D_00362738;


extern "C" u32 func_002cfeb0(...);  // obj_init_field1416_bit800
extern u8 D_00362738;


extern u8 D_00362738;


extern u8 D_00362738;


extern "C" u32 func_00105110(...);
extern u8 D_00362738;

u32 duplicate_unplaced_002db580(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362738;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002cff98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002db4b0(...);
extern u8 D_003626a8;


extern "C" u32 func_002db4b0(...);
extern u8 D_003626a8;


extern u8 D_003626a8;


extern u8 D_003626a8;


extern "C" u32 func_00105110(...);
extern u8 D_003626a8;

u32 duplicate_unplaced_002db730(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003626a8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002db530)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_0016a9a0(...);  // to_16a950
extern "C" u32 func_002db610(...);

u32 duplicate_unplaced_002db7d0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_0016a9a0)(r4, r5);
    r15 = (u32)(*(u8*)((u32)r16 + (s32)(568)));
    r4 = r16;
    r5 = (u32)((s32)0u + (-1));
    r15 = (u32)(r15 & 0x0001u);
    if (r15 != 0u) r5 = 0u;
    return ((u32(*)(u32,u32))func_002db610)(r4, r5);
}

extern "C" u32 func_002e7328(...);  // to_2e7458
extern u8 D_00362908;

u32 duplicate_unplaced_002db8a8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362908;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2976));
    u32 (*fp_call4_002e7328)(u32) = (u32(*)(u32))func_002e7328;
    r2 = fp_call4_002e7328(r4);
    r4 = r16;
    u32 (*fp_call4_002cff98)(u32) = (u32(*)(u32))func_002cff98;
    r2 = fp_call4_002cff98(r4);
    return r2;
}

extern "C" u32 func_002e7328(...);  // to_2e7458
extern u8 D_00362908;

u32 duplicate_unplaced_002db8e8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362908;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2976));
    u32 (*fp_call4_002e7328)(u32) = (u32(*)(u32))func_002e7328;
    r2 = fp_call4_002e7328(r4);
    r4 = r16;
    u32 (*fp_call4_002cff98)(u32) = (u32(*)(u32))func_002cff98;
    r2 = fp_call4_002cff98(r4);
    return r2;
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_002e7328(...);  // to_2e7458
extern u8 D_00362908;

u32 duplicate_unplaced_002db928(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362908;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2976));
    r2 = ((u32(*)(u32))func_002e7328)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_002cff98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002cea28(...);
extern "C" u32 func_002e4a90(...);  // in_even_range
extern u8 D_003629e8;

u32 duplicate_unplaced_002dc708(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003629e8;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (256));
    u32 (*fp_call4_002e4a90)(u32) = (u32(*)(u32))func_002e4a90;
    r2 = fp_call4_002e4a90(r4);
    r4 = r16;
    u32 (*fp_call4_002cea28)(u32) = (u32(*)(u32))func_002cea28;
    r2 = fp_call4_002cea28(r4);
    return r2;
}

extern "C" u32 func_002cea28(...);
extern "C" u32 func_002e4a90(...);  // in_even_range
extern u8 D_003629e8;

u32 duplicate_unplaced_002dc748(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003629e8;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (256));
    u32 (*fp_call4_002e4a90)(u32) = (u32(*)(u32))func_002e4a90;
    r2 = fp_call4_002e4a90(r4);
    r4 = r16;
    u32 (*fp_call4_002cea28)(u32) = (u32(*)(u32))func_002cea28;
    r2 = fp_call4_002cea28(r4);
    return r2;
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_002cea28(...);
extern "C" u32 func_002e4a90(...);  // in_even_range
extern u8 D_003629e8;

u32 duplicate_unplaced_002dc788(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003629e8;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (256));
    r2 = ((u32(*)(u32))func_002e4a90)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_002cea28)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002d0ea8(...);
extern u8 D_00362a20;


extern "C" u32 func_002d0ea8(...);
extern u8 D_00362a20;


extern u8 D_00362b68;


extern "C" u32 func_00105110(...);
extern u8 D_00362b68;

u32 duplicate_unplaced_002ddb80(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362b68;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002cff98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002d00a0(...);


u32 func_002de738(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = *(volatile u32*)((u32)r4 + (s32)(2808));
    r2 = (u32)((s32)0u + (-1));
    if (r15 != 0u) {
        r2 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(22)));
    }
    return r2;
}

extern "C" u32 func_002cfeb0(...);  // obj_init_field1416_bit800
extern u8 D_00362ad8;


extern "C" u32 func_002cfeb0(...);  // obj_init_field1416_bit800
extern u8 D_00362ad8;


extern u8 D_00362ad8;


extern u8 D_00362ad8;


extern "C" u32 func_00105110(...);
extern u8 D_00362ad8;

u32 duplicate_unplaced_002de810(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362ad8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002cff98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002dc7e8(...);


extern "C" u32 func_001050d8(...);
extern "C" u32 func_002e0d28(...);

u32 duplicate_unplaced_002e0bb0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r4 = (u32)((s32)0u + (240));
    r2 = ((u32(*)(u32,u32))func_001050d8)(r4, r5);
    r5 = r16;
    r4 = r2;
    return ((u32(*)(u32,u32))func_002e0d28)(r4, r5);
}

extern "C" u32 func_002e34d8(...);  // list_walk_stride12

u32 func_002e0fe8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r5 = *(volatile u32*)((u32)r4 + (s32)(116));
    r4 = (u32)((s32)r4 + (104));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002e34d8)(r4, r5, r6, r7, r8, r9, r10, r11);
    r14 = (u32)(*(u8*)((u32)r2 + (s32)(8)));
    r15 = (u32)((s32)0u + (1));
    r2 = 0u;
    if (r14 != r15) {
        r15 = (u32)(r14 ^ 0x0005u);
        r2 = ((u32)0u < (u32)r15);
    }
    return r2;
}

extern "C" u32 func_001050d8(...);
extern "C" u32 func_002e20d8(...);

u32 duplicate_unplaced_002e1f40(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r4 = (u32)((s32)0u + (320));
    r2 = ((u32(*)(u32,u32))func_001050d8)(r4, r5);
    r5 = r16;
    r4 = r2;
    return ((u32(*)(u32,u32))func_002e20d8)(r4, r5);
}

extern "C" u32 func_0018b1b8(...);


extern "C" u32 func_0018ac80(...);


extern "C" u32 func_0018aca8(...);


extern "C" u32 func_002e7670(...);
extern "C" u32 func_002e76b0(...);
extern "C" u32 func_002e77a8(...);

u32 duplicate_unplaced_002e7738(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002e7670)(r4);
    r4 = (u32)((s32)r16 + (4));
    r2 = ((u32(*)(u32))func_002e76b0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_002e77a8)(r4);
}

extern "C" u32 func_002e7670(...);
extern "C" u32 func_002e76b0(...);
extern "C" u32 func_002e77a8(...);

u32 duplicate_unplaced_002e7768(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002e7670)(r4);
    r4 = (u32)((s32)r16 + (4));
    r2 = ((u32(*)(u32))func_002e76b0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_002e77a8)(r4);
}

extern "C" u32 func_001058e8(...);


extern "C" u32 func_0016bd60(...);


extern "C" u32 func_0016bd60(...);


extern "C" u32 func_002e9fa8(...);


extern "C" u32 func_0016c5a0(...);


extern "C" u32 func_00190878(...);


extern "C" u32 func_00111040(...);


extern "C" u32 func_001124e8(...);


extern "C" u32 func_00194648(...);


extern "C" u32 func_00194668(...);


extern "C" u32 func_0016bd60(...);


extern "C" u32 func_0016bd60(...);


extern "C" u32 func_0016bd60(...);



extern "C" u32 func_0016bd60(...);


extern "C" u32 func_002e98b0(...);


extern "C" u32 func_00112760(...);


extern "C" u32 func_0010f8f0(...);


extern "C" u32 func_0016bd60(...);


extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0017c430(...);

u32 duplicate_unplaced_002eaaf0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_0017c430)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (44));
    return ((u32(*)(u32,u32))func_0016bd60)(r4, r5);
}

extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0017c430(...);

u32 duplicate_unplaced_002eb4b0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_0017c430)(r4, r5);
    r15 = (u32)((s32)0u + (256));
    *(volatile u32*)((u32)r16 + (s32)(256)) = r15;
    r4 = r16;
    r5 = (u32)((s32)0u + (49));
    r15 = (u32)((s32)0u + (257));
    *(volatile u32*)((u32)r16 + (s32)(260)) = r15;
    return ((u32(*)(u32,u32))func_0016bd60)(r4, r5);
}

extern "C" u32 func_001ad330(...);
extern "C" u32 func_002edf28(...);  // obj_ctor_3637e0
extern u8 D_00363828;

u32 duplicate_unplaced_002ee5d8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16, r17;
    r16 = r4;
    r17 = r5;
    r2 = ((u32(*)(u32,u32))func_002edf28)(r4, r5);
    r15 = (u32)&D_00363828;
    ((u32*)(u32)r16)[10] = r17;
    ((u32*)(u32)r16)[9] = 0u;
    ((u32*)(u32)r16)[0] = r15;
    r4 = (u32)((s32)r16 + (44));
    r5 = r17;
    return ((u32(*)(u32,u32))func_001ad330)(r4, r5);
}

extern "C" u32 func_00102080(...);
extern "C" u32 func_00102210(...);
extern "C" u32 func_001031b0(...);
extern "C" u32 func_002ee840(...);  // get_data_1e2c088

u32 duplicate_unplaced_002ee778(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00102210)(r4);
    *(volatile u32*)((u32)r16 + (s32)(44)) = r2;
    r4 = r16;
    r2 = ((u32(*)(u32))func_00102080)(r4);
    r2 = ((u32(*)())func_002ee840)();
    r16 = r2;
    r2 = ((u32(*)())func_001031b0)();
    *(volatile u32*)((u32)r16 + (s32)(4)) = r2;
    return r2;
}

extern "C" u32 func_0014c9d8(...);
extern "C" u32 func_0014df88(...);
extern "C" u32 func_0014e0d8(...);

// 002ee7c0 menu::Mode::initialize: moved to src/menu/tutorial_widget.cpp

extern "C" u32 func_0014df98(...);  // zero_global_byte

// 002ee808: moved to src/menu/tutorial_widget.cpp

extern "C" u32 func_002eefa8(...);


extern "C" u32 func_002efa98(...);
extern "C" u32 func_002efb08(...);

u32 duplicate_unplaced_002efb60(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002efb08)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_002efa98)(r4);
}

extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0017c430(...);

u32 duplicate_unplaced_002f05d8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_0017c430)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (63));
    return ((u32(*)(u32,u32))func_0016bd60)(r4, r5);
}

extern "C" u32 func_0010c7e8(...);
extern "C" u32 func_00117808(...);

u32 duplicate_unplaced_002f0708(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = *(volatile u32*)((u32)r15 + (s32)(4));
    r2 = ((u32(*)(u32,u32))func_0010c7e8)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(4));
    r4 = r2;
    return ((u32(*)(u32,u32))func_00117808)(r4, r5);
}

extern "C" u32 func_0010c7e8(...);
extern "C" u32 func_00119e60(...);

u32 duplicate_unplaced_002f08d8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = *(volatile u32*)((u32)r15 + (s32)(4));
    r2 = ((u32(*)(u32,u32))func_0010c7e8)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(4));
    r4 = r2;
    return ((u32(*)(u32,u32))func_00119e60)(r4, r5);
}

extern "C" u32 func_0010c7e8(...);
extern "C" u32 func_00119830(...);

u32 duplicate_unplaced_002f09d8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = *(volatile u32*)((u32)r15 + (s32)(4));
    r2 = ((u32(*)(u32,u32))func_0010c7e8)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(4));
    r4 = r2;
    return ((u32(*)(u32,u32))func_00119830)(r4, r5);
}

extern "C" u32 func_0010c7e8(...);
extern "C" u32 func_00117aa8(...);

u32 duplicate_unplaced_002f0a68(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = *(volatile u32*)((u32)r15 + (s32)(4));
    r2 = ((u32(*)(u32,u32))func_0010c7e8)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(4));
    r4 = r2;
    return ((u32(*)(u32,u32))func_00117aa8)(r4, r5);
}

extern "C" u32 func_0010c7e8(...);
extern "C" u32 func_0011a408(...);

u32 duplicate_unplaced_002f0c58(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r16 = r4;
    r4 = *(volatile u32*)((u32)r15 + (s32)(4));
    r2 = ((u32(*)(u32))func_0010c7e8)(r4);
    r4 = r2;
    r2 = ((u32(*)(u32))func_0011a408)(r4);
    *(volatile u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}

extern "C" u32 func_0010c7e8(...);
extern "C" u32 func_00118d10(...);

u32 duplicate_unplaced_002f0da8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = *(volatile u32*)((u32)r15 + (s32)(4));
    r2 = ((u32(*)(u32,u32))func_0010c7e8)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(4));
    r4 = r2;
    return ((u32(*)(u32,u32))func_00118d10)(r4, r5);
}

extern "C" u32 func_0010c7e8(...);
extern "C" u32 func_00114438(...);

u32 duplicate_unplaced_002f0e60(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r16 = r4;
    r4 = *(volatile u32*)((u32)r15 + (s32)(4));
    r2 = ((u32(*)(u32,u32))func_0010c7e8)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(4));
    r4 = r2;
    r2 = ((u32(*)(u32,u32))func_00114438)(r4, r5);
    *(volatile u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}

extern "C" u32 func_0010eed8(...);


extern "C" u32 func_00112c58(...);


extern "C" u32 func_001133f8(...);


extern "C" u32 func_0010c7b0(...);
extern "C" u32 func_00136158(...);

u32 duplicate_unplaced_002f1130(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = *(volatile u32*)((u32)r15 + (s32)(4));
    r2 = ((u32(*)(u32,u32))func_0010c7b0)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(4));
    r4 = r2;
    return ((u32(*)(u32,u32))func_00136158)(r4, r5);
}

extern "C" u32 func_002e9fb8(...);


extern "C" u32 func_0010c7e8(...);
extern "C" u32 func_0011a918(...);

u32 duplicate_unplaced_002f1230(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = *(volatile u32*)((u32)r15 + (s32)(4));
    r2 = ((u32(*)(u32,u32))func_0010c7e8)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(4));
    r4 = r2;
    return ((u32(*)(u32,u32))func_0011a918)(r4, r5);
}

extern "C" u32 func_00170950(...);

void func_002f1850(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = (u32)(0x01e3u << 16);
    r15 = *(volatile u32*)((u32)r16 + (s32)(-16176));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00170950)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(-16176)) = 0u;
    }
}

extern "C" u32 func_001dc920(...);

void func_002f1990(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001dc920)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(0)) = 0u;
    }
}

extern "C" u32 func_001dc840(...);

void func_002f19c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001dc840)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(0)) = 0u;
    }
}

extern "C" u32 func_001dc978(...);

void func_002f1a00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = r15;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001dc978)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(0)) = 0u;
    }
}

extern "C" u32 func_003037b0(...);


extern "C" u32 _free_r(...);

u32 func_00304b60(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16, r17;
    r16 = r5;
    r17 = r4;
    r15 = *(volatile u32*)((u32)r5 + (s32)(0));
    r5 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32,u32))func_00304b60)(r4, r5);
    }
    r4 = r17;
    r5 = r16;
    return ((u32(*)(u32,u32))_free_r)(r4, r5);
}

extern "C" u32 func_0030e548(...);


extern "C" u32 func_003167f8(...);  // set_vtbl_367910
extern u8 D_00367860;


extern "C" u32 func_003167f8(...);  // set_vtbl_367910
extern u8 D_00367860;


extern "C" u32 func_00106420(...);
extern "C" u32 func_003167f8(...);  // set_vtbl_367910
extern u8 D_00367860;

u32 duplicate_unplaced_00315678(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00367860;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    u32 (*fp_call4_003167f8)(u32) = (u32(*)(u32))func_003167f8;
    r2 = fp_call4_003167f8(r4);
    r4 = r16;
    u32 (*fp_call4_00106420)(u32) = (u32(*)(u32))func_00106420;
    r2 = fp_call4_00106420(r4);
    return r2;
}

extern "C" u32 func_003167f8(...);  // set_vtbl_367910
extern u8 D_00367848;


extern "C" u32 func_003167f8(...);  // set_vtbl_367910
extern u8 D_00367848;


extern "C" u32 func_00106420(...);
extern "C" u32 func_003167f8(...);  // set_vtbl_367910
extern u8 D_00367848;

u32 duplicate_unplaced_00315700(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00367848;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    u32 (*fp_call4_003167f8)(u32) = (u32(*)(u32))func_003167f8;
    r2 = fp_call4_003167f8(r4);
    r4 = r16;
    u32 (*fp_call4_00106420)(u32) = (u32(*)(u32))func_00106420;
    r2 = fp_call4_00106420(r4);
    return r2;
}

extern "C" u32 func_003155e8(...);  // set_vtbl_367878
extern u8 D_00367818;


extern "C" u32 func_003155e8(...);  // set_vtbl_367878
extern u8 D_00367818;


extern "C" u32 func_00106420(...);
extern "C" u32 func_003155e8(...);  // set_vtbl_367878
extern u8 D_00367818;

u32 duplicate_unplaced_003157b8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00367818;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_003155e8)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern u8 D_003677e8;


extern "C" u32 func_00106420(...);
extern u8 D_003677e8;

u32 duplicate_unplaced_00315840(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003677e8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00315768)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern u8 D_003677b8;


extern "C" u32 func_00106420(...);
extern u8 D_003677b8;

u32 duplicate_unplaced_003158c8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003677b8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00315768)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00106420(...);
extern u8 D_00367910;


extern "C" u32 func_003167f8(...);  // set_vtbl_367910
extern u8 D_003678f8;


extern "C" u32 func_003167f8(...);  // set_vtbl_367910
extern u8 D_003678f8;


extern "C" u32 func_00106420(...);
extern "C" u32 func_003167f8(...);  // set_vtbl_367910
extern u8 D_003678f8;

u32 duplicate_unplaced_00316890(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003678f8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    u32 (*fp_call4_003167f8)(u32) = (u32(*)(u32))func_003167f8;
    r2 = fp_call4_003167f8(r4);
    r4 = r16;
    u32 (*fp_call4_00106420)(u32) = (u32(*)(u32))func_00106420;
    r2 = fp_call4_00106420(r4);
    return r2;
}

extern "C" u32 func_00316c68(...);
extern u8 D_003168d8;
extern u8 D_01e4c7a0;


extern "C" u32 func_001b0188(...);
extern u8 D_00350e60;


extern "C" u32 func_0019fb48(...);


extern u8 D_00347e60;
extern u8 D_00347f98;


extern "C" u32 func_0031a840(...);
extern u8 D_00347e60;

u32 duplicate_unplaced_0031a508(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    u32 (*fp_call4_00239870)(u32) = (u32(*)(u32))func_00239870;
    r2 = fp_call4_00239870(r4);
    r4 = r16;
    u32 (*fp_call4_0031a840)(u32) = (u32(*)(u32))func_0031a840;
    r2 = fp_call4_0031a840(r4);
    return r2;
}

extern "C" u32 func_002361d0(...);
extern u8 D_00347e80;
extern u8 D_00347f98;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern "C" u32 func_0031baa8(...);  // set_vtbl_3486a8_b
extern u8 D_00349d90;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern "C" u32 func_00138988(...);
extern "C" u32 func_00138de0(...);
extern "C" u32 func_0014b9a8(...);

u32 duplicate_unplaced_0031c068(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00138988)(r4);
    r4 = (u32)((s32)r16 + (448));
    r2 = ((u32(*)(u32))func_0014b9a8)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00138de0)(r4);
    r16 = (u32)((s32)r16 + (480));
    r4 = r16;
    return ((u32(*)(u32))func_0014b9a8)(r4);
}

extern "C" u32 func_0031a840(...);
extern u8 D_00347e60;

u32 duplicate_unplaced_0031c8e8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    u32 (*fp_call4_00239870)(u32) = (u32(*)(u32))func_00239870;
    r2 = fp_call4_00239870(r4);
    r4 = r16;
    u32 (*fp_call4_0031a840)(u32) = (u32(*)(u32))func_0031a840;
    r2 = fp_call4_0031a840(r4);
    return r2;
}

extern "C" u32 func_0031cd50(...);
extern u8 D_00347e40;


extern "C" u32 func_0031cd50(...);
extern u8 D_00347e40;


extern "C" u32 func_002369f0(...);  // set_vtbl_36eac8_then_call
extern "C" u32 func_0023c098(...);  // set_vtbl_36eae8_then_call
extern u8 D_00347f98;
extern u8 D_0035eb98;

u32 duplicate_unplaced_0031cd90(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035eb98;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (48));
    r2 = ((u32(*)(u32))func_0023c098)(r4);
    r4 = (u32)((s32)r16 + (24));
    r2 = ((u32(*)(u32))func_002369f0)(r4);
    r15 = (u32)&D_00347f98;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

extern "C" u32 func_002369f0(...);  // set_vtbl_36eac8_then_call
extern "C" u32 func_0023c098(...);  // set_vtbl_36eae8_then_call
extern "C" u32 func_0023ee68(...);
extern u8 D_00347f98;
extern u8 D_0035eb98;

u32 duplicate_unplaced_0031cdd8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035eb98;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (48));
    r2 = ((u32(*)(u32))func_0023c098)(r4);
    r4 = (u32)((s32)r16 + (24));
    r2 = ((u32(*)(u32))func_002369f0)(r4);
    r15 = (u32)&D_00347f98;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return ((u32(*)(u32))func_0023ee68)(r4);
}

extern "C" u32 func_002369f0(...);  // set_vtbl_36eac8_then_call
extern "C" u32 func_0023c098(...);  // set_vtbl_36eae8_then_call
extern "C" u32 func_0023ee68(...);
extern u8 D_00347f98;
extern u8 D_0035eb98;

u32 duplicate_unplaced_0031ce70(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035eb98;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (48));
    r2 = ((u32(*)(u32))func_0023c098)(r4);
    r4 = (u32)((s32)r16 + (24));
    r2 = ((u32(*)(u32))func_002369f0)(r4);
    r15 = (u32)&D_00347f98;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return ((u32(*)(u32))func_0023ee68)(r4);
}

extern u8 D_00347e60;
extern u8 D_00347f98;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern "C" u32 func_00106420(...);
extern u8 D_0034e8a8;

u32 duplicate_unplaced_0031e630(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034e8a8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00239848)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern u8 D_0034e8a8;


extern "C" u32 func_001b0188(...);
extern u8 D_00350e48;


extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_0031eb68(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    u32 (*fp_call4_0019f9a8)(u32) = (u32(*)(u32))func_0019f9a8;
    r2 = fp_call4_0019f9a8(r4);
    r4 = (u32)((s32)r16 + (2640));
    u32 (*fp_call4_001c0248)(u32) = (u32(*)(u32))func_001c0248;
    r2 = fp_call4_001c0248(r4);
    r4 = r16;
    u32 (*fp_call4_00319fb0)(u32) = (u32(*)(u32))func_00319fb0;
    r2 = fp_call4_00319fb0(r4);
    return r2;
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_0031ebb0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    r2 = ((u32(*)(u32))func_0019f9a8)(r4);
    r4 = (u32)((s32)r16 + (2640));
    r2 = ((u32(*)(u32))func_001c0248)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00319fb0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0016a358(...);
extern u8 D_00350388;

u32 duplicate_unplaced_0031f008(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00350388;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0016a358)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0018d420(...);
extern u8 D_00350778;

u32 duplicate_unplaced_0031f238(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00350778;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0018d420)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_0031f340(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    r2 = ((u32(*)(u32))func_0019f9a8)(r4);
    r4 = (u32)((s32)r16 + (2640));
    r2 = ((u32(*)(u32))func_001c0248)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00319fb0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_001ac5b8(...);
extern u8 D_00350bf0;

u32 duplicate_unplaced_0031f4b8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00350bf0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001ac5b8)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0031fec0(...);
extern u8 D_00351100;

u32 duplicate_unplaced_0031fe88(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00351100;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0031fec0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0031ffc0(...);
extern u8 D_00352878;

u32 duplicate_unplaced_0031ff88(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00352878;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0031ffc0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_001b0188(...);
extern u8 D_00350e60;

u32 duplicate_unplaced_00320050(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00350e60;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001b0188)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0031fec0(...);
extern u8 D_00351100;

u32 duplicate_unplaced_00320118(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00351100;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0031fec0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_00320198(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    r2 = ((u32(*)(u32))func_0019f9a8)(r4);
    r4 = (u32)((s32)r16 + (2640));
    r2 = ((u32(*)(u32))func_001c0248)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00319fb0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_00320290(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    r2 = ((u32(*)(u32))func_0019f9a8)(r4);
    r4 = (u32)((s32)r16 + (2640));
    r2 = ((u32(*)(u32))func_001c0248)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00319fb0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00106420(...);
extern u8 D_00351228;

u32 duplicate_unplaced_003206f0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00351228;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2496));
    r2 = ((u32(*)(u32))func_001d48b0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00106420(...);
extern u8 D_00351228;

u32 duplicate_unplaced_00320768(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00351228;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2496));
    r2 = ((u32(*)(u32))func_001d48b0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0016a358(...);
extern u8 D_003512e8;

u32 duplicate_unplaced_003207c8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003512e8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0016a358)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_00320bc0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    r2 = ((u32(*)(u32))func_0019f9a8)(r4);
    r4 = (u32)((s32)r16 + (2640));
    r2 = ((u32(*)(u32))func_001c0248)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00319fb0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0031ffc0(...);
extern u8 D_00352878;

u32 duplicate_unplaced_00320c80(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00352878;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0031ffc0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00106420(...);
extern u8 D_00352560;

u32 duplicate_unplaced_00321648(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00352560;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001d1ed0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_003218c8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    u32 (*fp_call4_0019f9a8)(u32) = (u32(*)(u32))func_0019f9a8;
    r2 = fp_call4_0019f9a8(r4);
    r4 = (u32)((s32)r16 + (2640));
    u32 (*fp_call4_001c0248)(u32) = (u32(*)(u32))func_001c0248;
    r2 = fp_call4_001c0248(r4);
    r4 = r16;
    u32 (*fp_call4_00319fb0)(u32) = (u32(*)(u32))func_00319fb0;
    r2 = fp_call4_00319fb0(r4);
    return r2;
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_00321910(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    r2 = ((u32(*)(u32))func_0019f9a8)(r4);
    r4 = (u32)((s32)r16 + (2640));
    r2 = ((u32(*)(u32))func_001c0248)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00319fb0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern u8 D_00352a20;


extern "C" u32 func_00105110(...);
extern u8 D_00352a20;


extern "C" u32 func_00105110(...);
extern u8 D_00352a20;


extern "C" u32 func_00105110(...);
extern u8 D_00352a20;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern "C" u32 func_00108698(...);
extern "C" u32 func_001ddd10(...);

u32 duplicate_unplaced_00322ba8(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r4 = (u32)((s32)r4 + (56));
    r16 = (u32)((s32)r16 + (192));
    u32 (*fp_call4_00108698)(u32) = (u32(*)(u32))func_00108698;
    r2 = fp_call4_00108698(r4);
    r4 = r16;
    u32 (*fp_call4_001ddd10)(u32) = (u32(*)(u32))func_001ddd10;
    r2 = fp_call4_001ddd10(r4);
    return r2;
}

extern "C" u32 func_002369f0(...);  // set_vtbl_36eac8_then_call
extern "C" u32 func_0023c098(...);  // set_vtbl_36eae8_then_call
extern u8 D_00347f98;
extern u8 D_0035eb98;

u32 duplicate_unplaced_00322d70(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035eb98;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (48));
    r2 = ((u32(*)(u32))func_0023c098)(r4);
    r4 = (u32)((s32)r16 + (24));
    r2 = ((u32(*)(u32))func_002369f0)(r4);
    r15 = (u32)&D_00347f98;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

extern "C" u32 func_002369f0(...);  // set_vtbl_36eac8_then_call
extern "C" u32 func_0023c098(...);  // set_vtbl_36eae8_then_call
extern "C" u32 func_0023ee68(...);
extern u8 D_00347f98;
extern u8 D_0035eb98;

u32 duplicate_unplaced_00322db8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035eb98;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (48));
    r2 = ((u32(*)(u32))func_0023c098)(r4);
    r4 = (u32)((s32)r16 + (24));
    r2 = ((u32(*)(u32))func_002369f0)(r4);
    r15 = (u32)&D_00347f98;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return ((u32(*)(u32))func_0023ee68)(r4);
}

extern u8 D_00347e60;
extern u8 D_00347f98;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern u8 D_00347e60;
extern u8 D_00347f98;


extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_00324938(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    u32 (*fp_call4_0019f9a8)(u32) = (u32(*)(u32))func_0019f9a8;
    r2 = fp_call4_0019f9a8(r4);
    r4 = (u32)((s32)r16 + (2640));
    u32 (*fp_call4_001c0248)(u32) = (u32(*)(u32))func_001c0248;
    r2 = fp_call4_001c0248(r4);
    r4 = r16;
    u32 (*fp_call4_00319fb0)(u32) = (u32(*)(u32))func_00319fb0;
    r2 = fp_call4_00319fb0(r4);
    return r2;
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_00324980(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    r2 = ((u32(*)(u32))func_0019f9a8)(r4);
    r4 = (u32)((s32)r16 + (2640));
    r2 = ((u32(*)(u32))func_001c0248)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00319fb0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0019f9a8(...);  // array8_free_slots
extern "C" u32 func_001c0248(...);
extern "C" u32 func_00319fb0(...);  // big_obj_dtor
extern u8 D_0034ee08;

u32 duplicate_unplaced_00324b08(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0034ee08;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (2568));
    r2 = ((u32(*)(u32))func_0019f9a8)(r4);
    r4 = (u32)((s32)r16 + (2640));
    r2 = ((u32(*)(u32))func_001c0248)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00319fb0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_002eec58(...);
extern u8 D_00361bf0;

u32 duplicate_unplaced_00324b78(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00361bf0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002eec58)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern u8 D_00361da8;


extern "C" u32 func_00105110(...);
extern "C" u32 func_002d0f38(...);
extern u8 D_003622c0;

u32 duplicate_unplaced_00325408(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003622c0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002d0f38)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_002d0f38(...);
extern u8 D_00362a20;

u32 duplicate_unplaced_00325550(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362a20;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002d0f38)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_002dea80(...);  // set_vtbl_362d20
extern u8 D_00362cc8;


extern "C" u32 func_00106420(...);
extern "C" u32 func_002dea80(...);  // set_vtbl_362d20
extern u8 D_00362cc8;

u32 duplicate_unplaced_003255b8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362cc8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002dea80)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_002dea80(...);  // set_vtbl_362d20
extern u8 D_00362c70;

u32 duplicate_unplaced_00325618(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362c70;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002dea80)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_002dea80(...);  // set_vtbl_362d20
extern u8 D_00362c18;

u32 duplicate_unplaced_00325678(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00362c18;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_002dea80)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_002369f0(...);  // set_vtbl_36eac8_then_call
extern "C" u32 func_0023c098(...);  // set_vtbl_36eae8_then_call
extern u8 D_003637e0;
extern u8 D_00363880;

u32 duplicate_unplaced_00325aa0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00363880;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (64));
    r2 = ((u32(*)(u32))func_0023c098)(r4);
    r4 = (u32)((s32)r16 + (40));
    r2 = ((u32(*)(u32))func_002369f0)(r4);
    r15 = (u32)&D_003637e0;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_002369f0(...);  // set_vtbl_36eac8_then_call
extern "C" u32 func_0023c098(...);  // set_vtbl_36eae8_then_call
extern u8 D_003637e0;
extern u8 D_00363880;

u32 duplicate_unplaced_00325ae8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00363880;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (64));
    r2 = ((u32(*)(u32))func_0023c098)(r4);
    r4 = (u32)((s32)r16 + (40));
    r2 = ((u32(*)(u32))func_002369f0)(r4);
    r15 = (u32)&D_003637e0;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_002361d0(...);
extern u8 D_003637e0;
extern u8 D_003638a8;

u32 duplicate_unplaced_00325b80(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003638a8;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (468));
    r2 = ((u32(*)(u32))func_00239870)(r4);
    r4 = (u32)((s32)r16 + (48));
    r2 = ((u32(*)(u32))func_002361d0)(r4);
    r15 = (u32)&D_003637e0;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_001024b0(...);
extern "C" u32 func_00106178(...);

u32 duplicate_unplaced_00102508(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_00106178)();
    r4 = r2;
    return ((u32(*)(u32))func_001024b0)(r4);
}

extern u8 D_00102d10;
extern u8 D_00102dc0;
extern u8 D_0032b9a0;


extern "C" u32 func_002fde18(...);
extern u8 D_0032b9d0;
extern u8 D_0032b9d8;


extern u8 D_0032b9cc;

// 00102ea0: moved to src/common/title.cpp

extern u8 D_00103f68;
extern u8 D_00104018;
extern u8 D_0032ba48;


extern "C" u32 func_00104340(...);
extern u8 D_003a6b00;

// 00104370: moved to src/common/gumimenu.cpp

extern "C" u32 func_00104340(...);
extern u8 D_003a7300;

// 001043a0: moved to src/common/gumimenu.cpp

extern u8 D_001043e8;
extern u8 D_001044f0;
extern u8 D_0032ba90;


extern "C" u32 func_00102818(...);
extern "C" u32 func_001052a8(...);
extern u8 D_00104a48;
extern u8 D_0032b96c;
extern u8 D_003a7b00;

u32 duplicate_unplaced_00104da0(u32 a0) {
    *(volatile u8*)((u32)&D_003a7b00 + (s32)(0)) = (u8)0u;
    ((u32(*)())func_001052a8)();
    u32 r4 = *(volatile u32*)((u32)&D_0032b96c + (s32)(0));
    return ((u32(*)(u32, u32, u32, u32, u32))func_00102818)(
        r4,
        1u,
        5000u,
        (u32)&D_00104a48,
        0x2000u
    );
}

extern "C" u32 func_00104da0(...);

// 00104de0: moved to src/common/area.cpp

extern "C" u32 func_00109280(...);
extern "C" u32 func_00170320(...);
extern "C" u32 func_00170c00(...);

u32 duplicate_unplaced_001053c0(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = (u32)(0x0033u << 16);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-17636));
    r2 = ((u32(*)(u32))func_00109280)(r4);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-17636));
    r2 = ((u32(*)(u32))func_00170c00)(r4);
    r4 = 0u;
    r2 = ((u32(*)(u32))func_00170320)(r4);
    *(volatile u32*)((u32)r16 + (s32)(-17636)) = 0u;
    return r2;
}

extern u8 D_003a7b60;


extern u8 D_0033cb20;


extern u8 D_00105c68;
extern u8 D_00105d08;
extern u8 D_0033cb80;


extern "C" u32 func_00134450(...);

void func_00109008(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 00109008: moved to src/anon/unit_001085a8.cpp







extern "C" u32 func_001342c8(...);
extern u8 D_00340f30;


extern "C" u32 func_001342c8(...);
extern u8 D_003a8ed0;


extern "C" u32 func_00135878(...);

f32 func_001065a8(u32,u32,u32,u32,u32,u32,u32,u32);

void func_0010f880(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0010f880: definition moved into src/anon/unit_0010f338.cpp

f32 duplicate_unplaced_0010f8a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    return *(volatile f32*)((u32)a0 + (s32)(3284));
}

extern "C" u32 func_00112570(...);


f32 duplicate_unplaced_00112c28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = (u32)(0x0034u << 16);
    return *(volatile f32*)((u32)r15 + (s32)(6088));
}

f32 duplicate_unplaced_00112c38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = (u32)(0x0034u << 16);
    return *(volatile f32*)((u32)r15 + (s32)(6092));
}

extern "C" u32 func_0010eed8(...);
extern "C" u32 func_001c0cd8(...);
extern "C" u32 func_001c0e60(...);

void func_00114580(u32 a0);  // 0x00114580: definition moved into src/anon/unit_001142a0.cpp

extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_003461e8;

u32 duplicate_unplaced_00114850(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003461e8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_003464b0;

u32 duplicate_unplaced_00114968(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003464b0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00346658;

u32 duplicate_unplaced_00114b90(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00346658;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_003467b8;

u32 duplicate_unplaced_00114cc8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003467b8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00346960;

u32 duplicate_unplaced_00114de0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00346960;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00346b08;

u32 duplicate_unplaced_00114f38(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00346b08;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_00346b40;
extern u8 D_00346cd8;


extern u8 D_00346b40;
extern u8 D_00346cd8;


extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00346cd8;

u32 duplicate_unplaced_00115090(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00346cd8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_00346d10;
extern u8 D_00346e80;


extern u8 D_00346d10;
extern u8 D_00346e80;


extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00346e80;

u32 duplicate_unplaced_00115290(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00346e80;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_00346eb8;
extern u8 D_00347050;


extern u8 D_00346eb8;
extern u8 D_00347050;


extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00347050;

u32 duplicate_unplaced_001153e8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347050;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_00347088;
extern u8 D_00347220;


extern u8 D_00347088;
extern u8 D_00347220;


extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00347220;

u32 duplicate_unplaced_00115560(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347220;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_00347258;
extern u8 D_003473c8;


extern u8 D_00347258;
extern u8 D_003473c8;


extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_003473c8;

u32 duplicate_unplaced_001156b8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003473c8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_00347400;
extern u8 D_00347550;


extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00347550;

u32 duplicate_unplaced_001157d0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347550;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_00347728;
extern u8 D_003477a0;


extern "C" u32 func_00119e60(...);
extern "C" u32 func_001c8cd8(...);

u32 duplicate_unplaced_00119c88(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001c8cd8)(r4, r5);
    r4 = r16;
    r5 = r2;
    return ((u32(*)(u32,u32))func_00119e60)(r4, r5);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_003477a0;

u32 duplicate_unplaced_00119d08(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003477a0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern u8 D_003477d8;
extern u8 D_00347808;


extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00347808;

u32 duplicate_unplaced_0011a340(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347808;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00112730(...);
extern "C" u32 func_00112740(...);  // get_field2940

u32 duplicate_unplaced_0011a430(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r4 = *(volatile u32*)((u32)r4 + (s32)(4));
    r2 = ((u32(*)(u32,u32))func_00112740)(r4, r5);
    r4 = *(volatile u32*)((u32)r16 + (s32)(4));
    r5 = (u32)(r2 | 0x0200u);
    return ((u32(*)(u32,u32))func_00112730)(r4, r5);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern u8 D_00347848;

u32 duplicate_unplaced_0011a510(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347848;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00113668)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00113668(...);
extern "C" u32 func_0013e4b8(...);
extern u8 D_003478b0;

u32 func_0011a700(u32 a0);  // 0x0011a700: definition moved into src/anon/unit_0011a660.cpp

extern "C" u32 func_00113668(...);
extern "C" u32 func_0013e4b8(...);
extern u8 D_003478b0;

u32 func_0011a750(u32 a0);  // 0x0011a750: definition moved into src/anon/unit_0011a660.cpp

u32 func_001178d0(u32 a0) {
    u32 v0 = 0u;
    u32 t6 = (u32)((s32)a0 + (32));
    u32 t5;
    u32 t7;
L_check:
    t7 = *(volatile u32*)((u32)t6 + (s32)(4));
    t5 = (u32)((u32)v0 << 6);
    if ((s32)t7 < 0) {
        t7 = *(volatile u32*)((u32)t6 + (s32)(8));
        if (t7 == 0u) goto L_done;
    }
    v0 = (u32)(v0 + 1u);
    if ((s32)v0 < 24) {
        t6 = (u32)((s32)t6 + (64));
        goto L_check;
    }
    t5 = (u32)((u32)v0 << 6);
L_done:
    t7 = (u32)(t5 + a0);
    *(volatile u32*)((u32)t7 + (s32)(32)) = 0u;
    return v0;
}

extern "C" u32 func_0010f6b8(...);  // count_reached_threshold
extern "C" u32 func_00111e38(...);
extern "C" u32 func_001182d0(...);

u32 func_00118328(u32 a0) {
    u32 s0 = a0;
    u32 r2 = func_00111e38(0u);
    u32 t7 = *(volatile u32*)((u32)s0 + (s32)(20));
    u32 v0 = ((u32(*)(u32, f32))func_0010f6b8)(r2, *(volatile f32*)((u32)t7 + (s32)(8)));
    u32 r15 = 0u;
    if (v0 != 0u) {
        v0 = func_001182d0();
        r15 = (u32)((s32)0 < (s32)v0);
    }
    return r15;
}

extern "C" u32 func_0010f6f8(...);  // count_reached_threshold_b
extern "C" u32 func_00111e38(...);

u32 func_00118958(u32 a0) {
    u32 s0 = a0;
    u32 r2 = func_00111e38(0u);
    u32 t7 = *(volatile u32*)((u32)s0 + (s32)(20));
    u32 v0 = ((u32(*)(u32, f32))func_0010f6f8)(r2, *(volatile f32*)((u32)t7 + (s32)(12)));
    return (u32)(0u < v0);
}

extern u8 D_00347880;
extern u8 D_003478b0;


extern "C" u32 func_00105110(...);
extern "C" u32 func_00113668(...);
extern "C" u32 func_0013e4b8(...);
extern u8 D_003478b0;

u32 func_0011a7a0(u32 a0);  // 0x0011a7a0: definition moved into src/anon/unit_0011a660.cpp

extern "C" f32 func_0011c050(...);  // float_bucket_index
extern "C" u32 sceVu0RotMatrixX(...);

extern "C" f32 func_0011c050(...);  // float_bucket_index
extern "C" u32 sceVu0RotMatrixY(...);

extern "C" f32 func_0011c050(...);  // float_bucket_index
extern "C" u32 sceVu0RotMatrixZ(...);

void duplicate_unplaced_0011c210(u32 a0) {
    u64 r15 = *(volatile u64*)((u32)a0 + (s32)(16));
    u64 r14 = (u64)1u;
    r14 = (u64)(r14 << 53);
    r15 = (u64)(r15 | r14);
    *(volatile u64*)((u32)a0 + (s32)(16)) = r15;
}

u64 duplicate_unplaced_0011c230(u32 a0) {
    u64 r2 = *(volatile u64*)((u32)a0 + (s32)(16));
    r2 = (u64)(r2 >> 53);
    return (u64)(r2 & 0x0001u);
}

extern "C" u32 func_0011d468(...);

f32 func_0011d6c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0011d6c0: definition moved into src/anon/unit_0011c128.cpp

extern "C" u32 func_0011e350(...);
extern "C" u32 func_0011e450(...);

u32 duplicate_unplaced_0011e410(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16, r17;
    r17 = r5;
    r16 = r4;
    r5 = *(volatile u32*)((u32)r4 + (s32)(56));
    r2 = ((u32(*)(u32,u32))func_0011e350)(r4, r5);
    *(volatile u32*)((u32)r16 + (s32)(56)) = 0u;
    r4 = r16;
    r5 = r17;
    return ((u32(*)(u32,u32))func_0011e450)(r4, r5);
}

extern u8 D_00347940;

void duplicate_unplaced_0011ee18(u32 a0, u32 a1) {
    u32 t7 = (u32)&D_00347940;
    ((u32*)(u32)a0)[1] = a1;
    ((u32*)(u32)a0)[2] = 0u;
    ((u32*)(u32)a0)[0] = t7;
    ((u32*)(u32)a0)[3] = 0u;
}

u32 func_0011ef70(u32 a0, u32 a1);  // 0x0011ef70: definition moved into src/anon/unit_0011c128.cpp

s32 duplicate_unplaced_0011f238(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 t7 = *(volatile u32*)((u32)a0 + (s32)(0));
    u32 v0 = ((u32(*)(u32))(*(volatile u32*)((u32)t7 + (s32)(32))))(a0);
    s0 = (u32)((u32)s0 << 6);
    s0 = (u32)(s0 + v0);
    return *(s16*)((u32)s0 + (s32)(4));
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_0011ee58(...);  // set_vtbl_347940
extern u8 D_003479a8;

u32 duplicate_unplaced_0011f5a0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003479a8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0011ee58)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_0011ee58(...);  // set_vtbl_347940
extern u8 D_00347a28;

u32 duplicate_unplaced_001207c8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347a28;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0011ee58)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00124748(...);  // list_nth_node_rel

u32 duplicate_unplaced_00123d90(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r5;
    r5 = 0u;
    r2 = ((u32(*)(u32,u32))func_00124748)(r4, r5);
    r15 = ((u32*)(u32)r2)[0];
    r4 = r2;
    r2 = ((u32*)(u32)r15)[6];
    r5 = r16;
    r2 = ((u32(*)(u32,u32))(u32)r2)(r4, r5);
    return r2;
}

extern "C" u32 func_00124748(...);  // list_nth_node_rel

u32 duplicate_unplaced_00123dd0(u32 a0) {
    u32 v0 = func_00124748(a0, 0u);  // list_nth_node_rel
    u32 t7 = *(volatile u32*)((u32)v0 + (s32)(0));
    u32 fp = *(volatile u32*)((u32)t7 + (s32)(28));
    return ((u32(*)(u32))fp)(v0);
}

extern "C" u32 func_00124748(...);  // list_nth_node_rel

u32 duplicate_unplaced_00123e00(u32 a0) {
    u32 v0 = func_00124748(a0, 0u);  // list_nth_node_rel
    u32 t7 = *(volatile u32*)((u32)v0 + (s32)(0));
    u32 fp = *(volatile u32*)((u32)t7 + (s32)(32));
    return ((u32(*)(u32))fp)(v0);
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_00124c08(...);  // set_vtbl_347b88
extern u8 D_00347bb0;

u32 duplicate_unplaced_00128008(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347bb0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00124c08)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_00124c08(...);  // set_vtbl_347b88
extern u8 D_00347bd8;

u32 duplicate_unplaced_00131770(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347bd8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00124c08)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

u32 func_001320b0(u32 a0) {  // read_u32_be
    if ((a0 & 3u)) {
        u8* p = (u8*)(u32)a0;
        u32 r13 = (u32)p[2];
        u32 r14 = (u32)p[3];
        u32 r15 = (u32)p[1];
        r13 = (u32)(r13 << 16);
        u32 r12 = (u32)p[0];
        r14 = (u32)(r14 << 24);
        r15 = (u32)(r15 << 8);
        r14 = (u32)(r14 | r12);
        r15 = (u32)(r15 | r13);
        return (u32)(r14 | r15);
    }
    return *(u32*)((u32)a0 + (s32)(0));
}

u32 func_001320f0(u32 a0) {
    if ((a0 & 3u)) {
        u8* p = (u8*)(u32)a0;
        u32 r13 = (u32)p[6];
        u32 r14 = (u32)p[7];
        u32 r15 = (u32)p[5];
        r13 = (u32)(r13 << 16);
        u32 r12 = (u32)p[4];
        r14 = (u32)(r14 << 24);
        r15 = (u32)(r15 << 8);
        r14 = (u32)(r14 | r12);
        r15 = (u32)(r15 | r13);
        return (u32)(r14 | r15);
    }
    return *(u32*)((u32)a0 + (s32)(4));
}

extern "C" u32 func_001320f0(...);
extern "C" u32 func_00132208(...);

u32 duplicate_unplaced_00132130(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001320f0)(r4);
    r2 = (u32)((s32)r2 + (8));
    r16 = (u32)(r16 + r2);
    r4 = r16;
    r2 = ((u32(*)(u32))func_00132208)(r4);
    if (r2 == 0u) r16 = 0u;
    r2 = r16;
    return r2;
}

void func_00132370(u32 a0, u32 a1, u32 a2, f32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    *(volatile f32*)((u32)a0 + (s32)(24)) = a3;
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_001322f0(...);  // set_vtbl_347c00
extern u8 D_00347c30;

u32 duplicate_unplaced_00132590(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347c30;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001322f0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}


extern "C" u32 func_00132c68(...);
u32 func_00132c68(void);
u32 func_00132a70(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00132c68(a0);
    s32 r14 = 1;
    if (v0 == 0u) goto ZERO;
    if (*(volatile u32*)((u32)s0 + (s32)(636)) != 0u) goto RET;
ZERO:
    r14 = 0u;
RET:
    return (u32)r14;
}


u32 func_00132cd0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00132c68)();
    r15 = (u32)((s32)0u + (-1));
    if (r2 != 0u) {
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(16)));
    }
    r2 = r15;
    return r2;
}


u32 func_00132d00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00132c68)();
    r15 = (u32)((s32)0u + (-1));
    if (r2 != 0u) {
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(18)));
    }
    r2 = r15;
    return r2;
}


u32 func_00132d30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00132c68)();
    r15 = (u32)((s32)0u + (-1));
    if (r2 != 0u) {
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(20)));
    }
    r2 = r15;
    return r2;
}


u32 func_00132d60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00132c68)();
    r15 = (u32)((s32)0u + (-1));
    if (r2 != 0u) {
        r15 = (u32)(*(u16*)((u32)r2 + (s32)(22)));
    }
    r2 = r15;
    return r2;
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_001322f0(...);  // set_vtbl_347c00
extern u8 D_00347c60;

u32 duplicate_unplaced_00133228(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00347c60;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001322f0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

u32 func_001336f8(u32 a0) {
    u32 t7 = (u32)*(u8*)((u32)a0 + (s32)(0));
    if (t7 == 0u) return *(volatile u32*)((u32)a0 + (s32)(8));
    return *(volatile u32*)((u32)a0 + (s32)(12));
}

extern "C" u32 func_00135ad0(...);
extern u8 D_00347cf0;

// 001357d8: moved to src/naka/libkn/obj_observer.cpp

extern "C" u32 func_00135aa0(...);
extern u8 D_00347cf0;
extern u8 D_00347d00;

void duplicate_unplaced_001358c0(u32 a0) {
    u32 s0 = a0;
    u32 t7 = (u32)&D_00347d00;
    *(volatile u32*)((u32)a0 + (s32)(0)) = t7;
    func_00135aa0(a0);
    u32 t6 = (u32)&D_00347cf0;
    u32 t7b = *(volatile u32*)((u32)t6 + (s32)(0));
    *(volatile u32*)((u32)s0 + (s32)(8)) = t7b;
    *(volatile u32*)((u32)t6 + (s32)(0)) = s0;
}

extern "C" u32 func_00135aa0(...);
extern u8 D_00347cf0;
extern u8 D_00347d00;

void duplicate_unplaced_00135900(u32 a0) {
    u32 s0 = a0;
    u32 t7 = (u32)&D_00347d00;
    *(volatile u32*)((u32)a0 + (s32)(0)) = t7;
    func_00135aa0(a0);
    u32 t6 = (u32)&D_00347cf0;
    u32 t7b = *(volatile u32*)((u32)t6 + (s32)(0));
    *(volatile u32*)((u32)s0 + (s32)(8)) = t7b;
    *(volatile u32*)((u32)t6 + (s32)(0)) = s0;
}

extern "C" u32 func_00135ad0(...);
extern "C" u32 func_00135cc8(...);

void duplicate_unplaced_00135c50(u32 a0, u32 a1) {
    u32 s0 = a0;
    func_00135cc8(a0, a1, 0u);
    func_00135ad0(s0);
}

extern "C" u32 func_00136020(...);
extern u8 D_00347d08;

// 00135d88: moved to src/naka/libkn/effect_observer.cpp

extern "C" u32 func_001050d8(...);
extern "C" u32 func_00135e50(...);

u32 duplicate_unplaced_00135dc8(u32 a0) {
    u32 r4 = a0, r2, r16, r17;
    r17 = r4;
    r4 = (u32)((s32)0u + (272));
    r2 = ((u32(*)(u32))func_001050d8)(r4);
    r16 = r2;
    r4 = r2;
    r2 = ((u32(*)(u32))func_00135e50)(r4);
    *(volatile u32*)((u32)r16 + (s32)(4)) = r17;
    *(volatile u32*)((u32)r17 + (s32)(0)) = r16;
    return r2;
}

extern "C" u32 func_00135ff0(...);
extern u8 D_00347d08;
extern u8 D_00347d18;

void duplicate_unplaced_00135e10(u32 a0) {
    u32 s0 = a0;
    u32 t7 = (u32)&D_00347d18;
    *(volatile u32*)((u32)a0 + (s32)(0)) = t7;
    func_00135ff0(a0);
    u32 t6 = (u32)&D_00347d08;
    u32 t7b = *(volatile u32*)((u32)t6 + (s32)(0));
    *(volatile u32*)((u32)s0 + (s32)(8)) = t7b;
    *(volatile u32*)((u32)t6 + (s32)(0)) = s0;
}


extern "C" u32 func_001688c8(...);
extern "C" u32 func_00170b30(...);  // alloc_align128

void duplicate_unplaced_00136790(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 v0 = func_001688c8(a0);
    *(volatile u32*)((u32)s0 + (s32)(0)) = v0;
    a0 = (u32)((s32)v0 + (2047));
    u32 t7 = (u32)-2048;
    a0 = (u32)(a0 & t7);
    func_00170b30(a0);  // alloc_align128
}

extern "C" u32 func_002bc358(...);
extern u8 D_00347d24;

// 00136840: moved to src/harata/libdk/bgse.cpp

extern "C" u32 func_00136a50(...);
extern "C" u32 func_002ba040(...);
extern u8 D_00347d28;

// 00136a60: moved to src/harata/libdk/bgse.cpp

extern u8 D_00347d50;
extern u8 D_00347d54;
extern u8 D_00347d55;

void duplicate_unplaced_00136a98(void) {
    *(volatile u32*)(u32)&D_00347d50 = 0u;
    *(volatile u8*)(u32)&D_00347d54 = (u8)0u;
    *(volatile u8*)(u32)&D_00347d55 = (u8)0u;
}

extern "C" u32 func_00242ea8(...);
extern "C" u32 func_002ba848(...);

extern "C" u32 func_00136ba8(...);

// 00136cc8: moved to src/harata/libdk/bgm.cpp

extern "C" u32 func_00136b78(...);  // entry16_set_field8
extern "C" u32 func_002b7148(...);
extern "C" u32 func_002ba2b0(...);
extern u8 D_00347d40;

// 00136cf0: moved to src/harata/libdk/bgm.cpp

void func_001380e8(void);  // 0x001380e8: definition moved into src/anon/unit_001374c8.cpp

extern "C" u32 func_001397d8(...);
extern "C" u32 func_001398d0(...);

u32 duplicate_unplaced_00138140(u32 a0) {
    u32 r4 = a0, r2, r12, r13, r14, r15;
    r4 = (u32)((s32)0u + (13));
    r2 = ((u32(*)(u32))func_001398d0)(r4);
    r4 = (u32)((s32)0u + (13));
    r2 = ((u32(*)(u32))func_001397d8)(r4);
    r13 = (u32)(0x0034u << 16);
    r15 = *(volatile u32*)((u32)r13 + (s32)(32100));
    r12 = (u32)((s32)0u + (1));
    *(volatile u32*)((u32)r15 + (s32)(52)) = 0u;
    *(volatile u32*)((u32)r15 + (s32)(32)) = r12;
    *(volatile u32*)((u32)r15 + (s32)(48)) = 0u;
    r14 = *(volatile u32*)((u32)r13 + (s32)(32100));
    *(volatile u32*)((u32)r14 + (s32)(10688)) = r12;
    *(volatile u32*)((u32)r14 + (s32)(10696)) = 0u;
    *(volatile u32*)((u32)r14 + (s32)(10692)) = 0u;
    return r2;
}

void duplicate_unplaced_00138480(u32 a0) {
    u32 t5 = (u32)(0x0034u << 16);
    u32 t7 = 1u;
    u32 t6 = *(volatile u32*)((u32)t5 + (s32)(32264));
    t7 = (u32)(t7 << a0);
    t6 = (u32)(t6 | t7);
    *(volatile u32*)((u32)t5 + (s32)(32264)) = t6;
}

extern "C" u32 func_002362b0(...);
extern "C" u32 func_002367c8(...);  // obj_dispatch_bitfield64

u32 duplicate_unplaced_00138698(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = (u32)((s32)r4 + (32));
    r4 = r16;
    r2 = ((u32(*)(u32))func_002362b0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_002367c8)(r4);
}

extern "C" u32 func_00138988(...);
extern "C" u32 func_00138de0(...);

u32 duplicate_unplaced_001390c0(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00138988)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00138de0)(r4);
}

extern "C" u32 func_00138988(...);

void func_00139170(u32 a0);  // 0x00139170: definition moved into src/anon/unit_00138480.cpp

extern "C" u32 func_00102750(...);
extern "C" u32 func_001394c0(...);
extern "C" u32 func_00139768(...);

u32 duplicate_unplaced_001394d8(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00139768)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_001394c0)(r4);
    r15 = (u32)(0x0034u << 16);
    r14 = *(volatile u32*)((u32)r15 + (s32)(32640));
    r4 = *(volatile u32*)((u32)r14 + (s32)(0));
    return ((u32(*)(u32))func_00102750)(r4);
}

extern "C" u32 func_0013a4c8(...);
extern "C" u32 func_0013b538(...);
extern "C" u32 func_0013d498(...);
extern u8 D_00347ff4;

extern "C" u32 func_0013a6b8(...);
extern "C" u32 func_00242c70(...) asm("_ZN2Tz6Config12isCommandKH2Ev");

extern "C" u32 func_00131da8(...);
extern u8 D_00347ff8;
extern u8 D_00347ffc;

void func_0013a8b8(void);  // 0x0013a8b8: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_0013a9d0(...);
extern u8 D_00347ffd;

u32 func_0013a9f8(void);  // 0x0013a9f8: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_00138840(...);
extern "C" u32 func_0023acd8(...);
extern u8 D_0034805c;

extern u8 D_00348000;


extern "C" u32 func_001391c8(...);
extern "C" u32 func_0013b128(...);

void duplicate_unplaced_0013b1a0(u32 a0) {
    u32 s0 = a0;
    func_001391c8(a0, (u32)((s32)5302), (u32)((s32)1));
    func_0013b128(s0);
}

extern "C" u32 func_0013b1d0(...);
extern "C" u32 func_0013b258(...);
extern "C" u32 func_0013d208(...);

u32 duplicate_unplaced_0013b260(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0013b258)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_0013b1d0)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_0013d208)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_0013b1a0)(r4);
}

f32 func_0013b298(u32 a0);  // 0x0013b298: definition moved into src/anon/unit_0013a8b8.cpp

f32 func_0013b2a8(u32 a0);  // 0x0013b2a8: definition moved into src/anon/unit_0013a8b8.cpp

extern u8 D_003484a0;

f32 func_0013b2e8(void);  // 0x0013b2e8: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_00103b38(...);
extern "C" u32 func_00139dc0(...);
extern "C" u32 func_0013a1e8(...);

void func_0013b570(void);  // 0x0013b570: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_00103b38(...);
extern "C" u32 func_0013a200(...);

void func_0013b5a8(void);  // 0x0013b5a8: definition moved into src/anon/unit_0013a8b8.cpp

extern u8 D_004573c0;


u32 func_0013c698(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0013c698: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_0013c698(...);
extern u8 D_003484a0;

u32 func_0013c6b8(void);  // 0x0013c6b8: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_0013c688(...);
extern u8 D_003484a0;

u32 func_0013c6e8(void);  // 0x0013c6e8: definition moved into src/anon/unit_0013a8b8.cpp

u32 func_0013c888(u32 a0, u32 a1);  // 0x0013c888: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_001024a8(...);
extern "C" u32 func_0013b128(...);
extern "C" u32 func_0013d620(...);
extern "C" u32 func_0013d7c0(...);

u32 duplicate_unplaced_0013d750(u32 a0) {
    u32 r4 = a0, r2, r15, r16, r17;
    r17 = r4;
    r2 = ((u32(*)(u32))func_0013d620)(r4);
    r16 = (u32)(0x0035u << 16);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-31584));
    r2 = ((u32(*)(u32))func_0013b128)(r4);
    r15 = *(volatile u32*)((u32)r16 + (s32)(-31584));
    *(volatile u32*)((u32)r15 + (s32)(676)) = 0u;
    r2 = ((u32(*)())func_0013d7c0)();
    r4 = r17;
    return ((u32(*)(u32))func_001024a8)(r4);
}

extern "C" u32 func_0013e940(...);
extern "C" u32 func_0014b150(...);  // obj_init_fields_14b150
extern u8 D_003486f0;

u32 duplicate_unplaced_0013e900(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0014b150)(r4);
    r15 = (u32)&D_003486f0;
    ((u32*)(u32)r16)[68] = 0u;
    ((u32*)(u32)r16)[69] = 0u;
    ((u32*)(u32)r16)[0] = r15;
    r4 = r16;
    ((u32*)(u32)r16)[70] = 0u;
    return ((u32(*)(u32))func_0013e940)(r4);
}

extern "C" u32 func_0013fec0(...);

u32 func_00140370(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00140370: definition moved into src/anon/unit_0013fca8.cpp

f32 duplicate_unplaced_00141070(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = (u32)(0x0035u << 16);
    return *(volatile f32*)((u32)r15 + (s32)(-30928));
}

extern "C" u32 func_0013a4c8(...);
extern "C" u32 func_0013a600(...);
extern "C" u32 func_001493b8(...);
extern u8 D_00348d68;

u32 duplicate_unplaced_00149c08(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = (u32)&D_00348d68;
    r2 = ((u32(*)())func_0013a600)();
    r2 = ((u32(*)())func_0013a4c8)();
    r4 = r16;
    r2 = ((u32(*)(u32))func_001493b8)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00149428)(r4);
}

extern "C" u32 func_0014a500(...);
extern "C" u32 func_0014a6e0(...);

u32 func_0014a830(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0014a830: moved to src/anon/unit_00149fa8.cpp

extern "C" u32 func_0014a988(...);  // clear_fields_244_260
extern "C" u32 func_0014b638(...);
extern u8 D_00349b28;

u32 duplicate_unplaced_0014a950(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0014b638)(r4);
    r15 = (u32)&D_00349b28;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(0)) = r15;
    return ((u32(*)(u32))func_0014a988)(r4);
}

extern "C" u32 func_0014a988(...);  // clear_fields_244_260
extern "C" u32 func_0014ace8(...);
extern u8 D_003493a0;

u32 duplicate_unplaced_0014acf8(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_0014ace8)();
    r4 = (u32)&D_003493a0;
    return ((u32(*)(u32))func_0014a988)(r4);
}

f32 duplicate_unplaced_0014ce78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = (u32)(0x0035u << 16);
    return *(volatile f32*)((u32)r15 + (s32)(-25072));
}

extern "C" u32 func_0014cf80(...);
extern "C" u32 func_0014d060(...);
extern "C" u32 func_0014e088(...);
extern "C" u32 func_0014e5f0(...);
extern "C" u32 func_001b7f88(...);
extern "C" u32 func_002ef7c8(...);

u32 duplicate_unplaced_0014cf88(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_0014cf80)();
    r2 = ((u32(*)())func_001b7f88)();
    r2 = ((u32(*)())func_002ef7c8)();
    r2 = ((u32(*)())func_0014d060)();
    r2 = ((u32(*)())func_0014e088)();
    r4 = r2;
    return ((u32(*)(u32))func_0014e5f0)(r4);
}

extern u8 D_00349e48;


extern "C" u32 sceGsSyncPath(...);
extern "C" u32 func_002f3918(...);
extern "C" u32 func_003058a0(...);

u32 duplicate_unplaced_0014d8d0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r4 = 0u;
    r2 = ((u32(*)(u32,u32))func_003058a0)(r4, r5);
    r4 = 0u;
    r5 = 0u;
    r2 = ((u32(*)(u32,u32))sceGsSyncPath)(r4, r5);
    r5 = r16;
    r15 = (u32)(0x0035u << 16);
    r4 = *(volatile u32*)((u32)r15 + (s32)(-24840));
    return ((u32(*)(u32,u32))func_002f3918)(r4, r5);
}

extern "C" u32 sceGsSyncPath(...);
extern "C" u32 func_002f3918(...);

u32 duplicate_unplaced_0014d910(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r5 = 0u;
    r16 = r4;
    r4 = 0u;
    r2 = ((u32(*)(u32,u32))sceGsSyncPath)(r4, r5);
    r5 = r16;
    r15 = (u32)(0x0035u << 16);
    r4 = *(volatile u32*)((u32)r15 + (s32)(-24840));
    return ((u32(*)(u32,u32))func_002f3918)(r4, r5);
}

extern "C" u32 func_00140df0(...);
extern "C" u32 func_0014e658(...);

u32 duplicate_unplaced_0014ec20(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_00140df0)();
    r4 = r2;
    return ((u32(*)(u32))func_0014e658)(r4);
}

extern "C" u32 func_001aec40(...);  // get_global_1c9408c

u32 func_0014ecf8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001aec40)();
    r15 = 0u;
    if (r2 != 0u) {
        r15 = (u32)(s32)(*(s16*)((u32)r2 + (s32)(10)));
    }
    r2 = r15;
    return r2;
}

extern "C" u32 func_00139858(...);
extern "C" u32 func_00139ab0(...);

u32 duplicate_unplaced_0014f4d8(u32 a0) {
    u32 r4 = a0, r2;
    r4 = (u32)((s32)0u + (7));
    r2 = ((u32(*)(u32))func_00139858)(r4);
    r4 = (u32)((s32)0u + (9));
    r2 = ((u32(*)(u32))func_00139858)(r4);
    r4 = (u32)((s32)0u + (8));
    r2 = ((u32(*)(u32))func_00139858)(r4);
    r4 = (u32)((s32)0u + (10));
    r2 = ((u32(*)(u32))func_00139858)(r4);
    r4 = (u32)((s32)0u + (7));
    r2 = ((u32(*)(u32))func_00139ab0)(r4);
    r4 = (u32)((s32)0u + (9));
    r2 = ((u32(*)(u32))func_00139ab0)(r4);
    r4 = (u32)((s32)0u + (8));
    r2 = ((u32(*)(u32))func_00139ab0)(r4);
    r4 = (u32)((s32)0u + (10));
    return ((u32(*)(u32))func_00139ab0)(r4);
}

extern "C" u32 func_001398d0(...);
extern "C" u32 func_00139a38(...);

u32 duplicate_unplaced_0014f528(u32 a0) {
    u32 r4 = a0, r2;
    r4 = (u32)((s32)0u + (7));
    r2 = ((u32(*)(u32))func_001398d0)(r4);
    r4 = (u32)((s32)0u + (9));
    r2 = ((u32(*)(u32))func_001398d0)(r4);
    r4 = (u32)((s32)0u + (8));
    r2 = ((u32(*)(u32))func_001398d0)(r4);
    r4 = (u32)((s32)0u + (10));
    r2 = ((u32(*)(u32))func_001398d0)(r4);
    r4 = (u32)((s32)0u + (7));
    r2 = ((u32(*)(u32))func_00139a38)(r4);
    r4 = (u32)((s32)0u + (9));
    r2 = ((u32(*)(u32))func_00139a38)(r4);
    r4 = (u32)((s32)0u + (8));
    r2 = ((u32(*)(u32))func_00139a38)(r4);
    r4 = (u32)((s32)0u + (10));
    return ((u32(*)(u32))func_00139a38)(r4);
}

extern u8 D_0034a458;


u32 duplicate_unplaced_00150578(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r5 = 0u;
    r16 = r4;
    r4 = (u32)((s32)r4 + (840));
    r16 = (u32)((s32)r16 + (1248));
    r2 = ((u32(*)(u32,u32))func_00138c10)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (6));
    return ((u32(*)(u32,u32))func_00138c10)(r4, r5);
}


u32 duplicate_unplaced_00150610(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r5 = (u32)((s32)0u + (1));
    r16 = r4;
    r4 = (u32)((s32)r4 + (840));
    r16 = (u32)((s32)r16 + (1248));
    r2 = ((u32(*)(u32,u32))func_00138c10)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (7));
    return ((u32(*)(u32,u32))func_00138c10)(r4, r5);
}


u32 duplicate_unplaced_001514b0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r5 = 0u;
    r16 = r4;
    r4 = (u32)((s32)r4 + (496));
    r16 = (u32)((s32)r16 + (904));
    r2 = ((u32(*)(u32,u32))func_00138c10)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (6));
    return ((u32(*)(u32,u32))func_00138c10)(r4, r5);
}


u32 duplicate_unplaced_00151b40(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r5 = 0u;
    r16 = r4;
    r4 = (u32)((s32)r4 + (840));
    r16 = (u32)((s32)r16 + (2472));
    r2 = ((u32(*)(u32,u32))func_00138c10)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (6));
    return ((u32(*)(u32,u32))func_00138c10)(r4, r5);
}

extern "C" u32 func_00138c10(...);
ObjCommon_001050c8* func_001050c8(void);
extern "C" u32 func_0023edb0(...);

u32 duplicate_unplaced_00153c60(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_001050c8)();
    r4 = r2;
    return ((u32(*)(u32))func_0023edb0)(r4);
}

extern "C" u32 func_00139948(...);
extern "C" u32 func_00139ba0(...);

u32 duplicate_unplaced_00154af0(u32 a0) {
    u32 r4 = a0, r2, r15;
    r15 = (u32)((s32)0u + (1));
    *(volatile u8*)((u32)r4 + (s32)(15584)) = (u8)r15;
    r4 = (u32)((s32)0u + (6));
    r2 = ((u32(*)(u32))func_00139948)(r4);
    r4 = (u32)((s32)0u + (6));
    return ((u32(*)(u32))func_00139ba0)(r4);
}

extern "C" u32 func_001399c0(...);
extern "C" u32 func_00139b28(...);

u32 duplicate_unplaced_00154b18(u32 a0) {
    u32 r4 = a0, r2;
    *(volatile u8*)((u32)r4 + (s32)(15584)) = (u8)0u;
    r4 = (u32)((s32)0u + (6));
    r2 = ((u32(*)(u32))func_001399c0)(r4);
    r4 = (u32)((s32)0u + (6));
    return ((u32(*)(u32))func_00139b28)(r4);
}

// 00156030: moved to src/anon/unit_00153ea0.cpp
u32 func_00156030(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

// 00156058: moved to src/anon/unit_00153ea0.cpp
u32 func_00156058(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

// 00156080: moved to src/anon/unit_00153ea0.cpp
u32 func_00156080(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

extern "C" u32 func_00140df0(...);
extern "C" u32 func_00140e30(...);

u32 duplicate_unplaced_001586b8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r2 = ((u32(*)())func_00140df0)();
    r15 = (u32)((s32)0u + (8));
    *(volatile u32*)((u32)r2 + (s32)(64)) = r15;
    r4 = r2;
    r5 = (u32)((s32)0u + (3));
    return ((u32(*)(u32,u32))func_00140e30)(r4, r5);
}

extern "C" u32 func_0013fca8(...);
extern "C" u32 func_00159790(...);

// 00159b00: moved to src/harata/libdk/talkcamera.cpp

extern "C" u32 func_001024a8(...);
extern "C" u32 func_00140dd0(...);
extern "C" u32 func_00140df0(...);
extern "C" u32 func_00140f10(...);

u32 duplicate_unplaced_00159be0(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00140df0)(r4);
    r4 = r2;
    r2 = ((u32(*)(u32))func_00140f10)(r4);
    r2 = ((u32(*)())func_00140df0)();
    r4 = r2;
    r2 = ((u32(*)(u32))func_00140dd0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001024a8)(r4);
}

extern "C" u32 func_00139858(...);
extern "C" u32 func_00139ab0(...);

u32 duplicate_unplaced_0015b780(u32 a0) {
    u32 r4 = a0, r2;
    r4 = (u32)((s32)0u + (15));
    r2 = ((u32(*)(u32))func_00139858)(r4);
    r4 = (u32)((s32)0u + (15));
    return ((u32(*)(u32))func_00139ab0)(r4);
}

extern "C" u32 func_001398d0(...);
extern "C" u32 func_00139a38(...);

u32 duplicate_unplaced_0015b7a0(u32 a0) {
    u32 r4 = a0, r2;
    r4 = (u32)((s32)0u + (15));
    r2 = ((u32(*)(u32))func_001398d0)(r4);
    r4 = (u32)((s32)0u + (15));
    return ((u32(*)(u32))func_00139a38)(r4);
}

f32 duplicate_unplaced_0015ced0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = (u32)(0x004fu << 16);
    return *(volatile f32*)((u32)r15 + (s32)(14352));
}

f32 duplicate_unplaced_0015cee0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = (u32)(0x004fu << 16);
    return *(volatile f32*)((u32)r15 + (s32)(14356));
}

extern "C" u32 func_001024a8(...);
extern "C" u32 func_0014e098(...);

u32 duplicate_unplaced_001617e8(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r4 = (u32)((s32)0u + (216));
    r2 = ((u32(*)(u32))func_0014e098)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001024a8)(r4);
}

extern "C" u32 func_001024a8(...);
extern "C" u32 func_0014e0d8(...);

u32 duplicate_unplaced_00161f10(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0014e0d8)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001024a8)(r4);
}



extern u8 D_0034d3c0;


extern u8 D_0034d6c0;


extern "C" u32 func_00170888(...);
extern "C" u32 func_001afaf0(...);
extern "C" u32 func_001badd8(...);

u32 duplicate_unplaced_00169148(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00170888)(r4);
    r2 = ((u32(*)())func_001badd8)();
    r4 = r16;
    return ((u32(*)(u32))func_001afaf0)(r4);
}

extern "C" u32 func_001922c8(...);
extern "C" u32 func_00197be8(...);
extern "C" u32 func_001a5e38(...);
extern "C" u32 func_001b24c8(...);
extern "C" u32 func_001ba740(...);

u32 duplicate_unplaced_00169308(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_001a5e38)();
    r2 = ((u32(*)())func_001ba740)();
    r2 = ((u32(*)())func_001b24c8)();
    r2 = ((u32(*)())func_001bb468)();
    r4 = (u32)((s32)0u + (2));
    r2 = ((u32(*)(u32))func_001922c8)(r4);
    r2 = ((u32(*)())func_001b83d0)();
    return ((u32(*)())func_00197be8)();
}

extern "C" u32 func_0016c358(...);
extern "C" u32 func_001a9350(...);

u32 duplicate_unplaced_0016a328(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r4 = (u32)((s32)r4 + (1952));
    r2 = ((u32(*)(u32))func_001a9350)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_0016c358)(r4);
}

extern "C" u32 func_0016bf20(u32, u32, u32, u32, u32, u32, u32, u32) asm("_ZN2YS3OBJ14get_appear_wayEv");
extern "C" u32 func_0016bff0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_ZN2YS3OBJ10get_serialEv");

extern "C" u32 func_001891b8(...);
extern "C" u32 func_00189200(...);
extern u8 D_0032e020;

u32 duplicate_unplaced_0016e130(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r5 = *(volatile u32*)((u32)r4 + (s32)(0));
    r4 = (u32)&D_0032e020;
    r2 = ((u32(*)(u32,u32))func_00189200)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(4));
    r4 = r2;
    return ((u32(*)(u32,u32))func_001891b8)(r4, r5);
}

extern "C" u32 func_001b1448(...);
extern "C" u32 func_001d3390(...);

u32 duplicate_unplaced_0016e8f8(u32 a0) {
    u32 r4 = a0, r2, r15;
    r15 = (u32)(0x0035u << 16);
    r4 = *(volatile u32*)((u32)r15 + (s32)(-9176));
    r2 = ((u32(*)(u32))func_001b1448)(r4);
    r4 = r2;
    return ((u32(*)(u32))func_001d3390)(r4);
}

extern "C" u32 func_0016e920(...);
extern "C" u32 func_0016f6a0(...);

u32 duplicate_unplaced_0016eb18(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r5;
    r2 = ((u32(*)(u32,u32))func_0016e920)(r4, r5);
    r5 = r16;
    r4 = r2;
    return ((u32(*)(u32,u32))func_0016f6a0)(r4, r5);
}

f32 func_001826f8(u32,u32,u32,u32,u32,u32,u32,u32);

void func_00173120(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00173120: definition moved into src/anon/unit_00171e58.cpp

extern "C" u32 func_001b6bd8(...);
extern "C" u32 func_001d14a0(...);

u32 duplicate_unplaced_001741e0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001d14a0)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(0));
    r4 = r2;
    return ((u32(*)(u32,u32))func_001b6bd8)(r4, r5);
}

extern "C" u32 func_00140df0(...);
extern "C" u32 func_00140f10(...);

u32 duplicate_unplaced_00174ba8(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_00140df0)();
    r4 = r2;
    return ((u32(*)(u32))func_00140f10)(r4);
}

extern "C" u32 func_00140df0(...);
extern "C" u32 func_00140f20(...);

u32 duplicate_unplaced_00174bc8(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_00140df0)();
    r4 = r2;
    return ((u32(*)(u32))func_00140f20)(r4);
}

extern "C" u32 func_00106a60(...);  // buffer_get_by_index
extern "C" u32 func_00107478(...);  // vec_copy_at96_if_diff
extern u8 D_01c5f480;

u32 duplicate_unplaced_00174d98(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16, r17;
    r17 = r4;
    r4 = (u32)((s32)0u + (1));
    r16 = (u32)&D_01c5f480;
    r2 = ((u32(*)(u32,u32))func_00106a60)(r4, r5);
    r5 = r16;
    r4 = r2;
    r2 = ((u32(*)(u32,u32))func_00107478)(r4, r5);
    *(volatile u32*)((u32)r17 + (s32)(0)) = r16;
    return r2;
}

extern "C" u32 func_001382b8(...);
extern "C" u32 func_001a8258(...);
extern "C" u32 func_001a8418(...);
extern "C" u32 func_001a8510(...);  // mod8_of_difference

u32 duplicate_unplaced_001754d0(u32 a0) {
    u32 r4 = a0, r2;
    r4 = *(volatile u32*)((u32)r4 + (s32)(0));
    r2 = ((u32(*)(u32))func_001a8258)(r4);
    r4 = r2;
    r2 = ((u32(*)(u32))func_001a8418)(r4);
    r2 = ((u32(*)())func_001a8510)();
    r4 = r2;
    return ((u32(*)(u32))func_001382b8)(r4);
}

// 00176a60: moved to src/yasui/libys/party.cpp

extern "C" u32 func_0016c7d8(...);
extern "C" u32 func_0016cab8(...);

// 00177498: moved to src/yasui/libys/party.cpp


u32 duplicate_unplaced_001775f8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r5 = (u32)((s32)0u + (2));
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001940f0)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (12));
    r2 = ((u32(*)(u32,u32))func_001940f0)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (22));
    return ((u32(*)(u32,u32))func_001940f0)(r4, r5);
}


u32 duplicate_unplaced_00177638(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r5 = (u32)((s32)0u + (2));
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_00194108)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (12));
    r2 = ((u32(*)(u32,u32))func_00194108)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (22));
    return ((u32(*)(u32,u32))func_00194108)(r4, r5);
}

extern "C" u32 func_00140db0(...);
extern "C" u32 func_00182f28(...);  // store_global_35ed04
extern "C" u32 func_001d69d0(...);

u32 duplicate_unplaced_001781e8(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00140db0)(r4);
    r4 = 0u;
    r2 = ((u32(*)(u32))func_00182f28)(r4);
    r4 = ((u32*)(u32)r16)[719];
    r2 = ((u32(*)(u32))func_001d69d0)(r4);
    ((u32*)(u32)r16)[719] = 0u;
    return r2;
}

extern "C" u32 func_00176ec8(...);
extern "C" u32 func_001d6a80(...);

u32 duplicate_unplaced_00179e18(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r4 = *(volatile u32*)((u32)r4 + (s32)(2876));
    r2 = ((u32(*)(u32))func_001d6a80)(r4);
    *(volatile u32*)((u32)r16 + (s32)(2888)) = 0u;
    r4 = r16;
    return ((u32(*)(u32))func_00176ec8)(r4);
}

extern "C" u32 func_001781a8(...);
extern "C" u32 func_00179f10(...);

u32 duplicate_unplaced_00179f58(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00179f10)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001781a8)(r4);
}

extern "C" u32 func_00112ab8(...);
extern "C" u32 func_001762f8(...);

u32 duplicate_unplaced_0017a1c8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r14, r15, r16;
    r14 = (u32)((s32)0u + (-3));
    r16 = r5;
    r15 = *(volatile u32*)((u32)r4 + (s32)(268));
    r15 = (u32)(r15 & r14);
    *(volatile u32*)((u32)r4 + (s32)(268)) = r15;
    r2 = ((u32(*)(u32,u32))func_001762f8)(r4, r5);
    r5 = r16;
    r4 = 0u;
    return ((u32(*)(u32,u32))func_00112ab8)(r4, r5);
}

extern "C" u32 func_001776f8(...);
extern "C" u32 func_001bdab0(...);

u32 duplicate_unplaced_0017a230(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r4 = *(volatile u32*)((u32)r4 + (s32)(2884));
    r2 = ((u32(*)(u32))func_001bdab0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001776f8)(r4);
}

extern "C" u32 func_001779d0(...);
extern "C" u32 func_001bc0e0(...);

// 0017a680: moved to src/yasui/libys/player.cpp

extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0017c430(...);

u32 duplicate_unplaced_0017a938(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r4 = r5;
    r16 = r5;
    r2 = ((u32(*)(u32,u32))func_0017c430)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (1));
    return ((u32(*)(u32,u32))func_0016bd60)(r4, r5);
}

extern "C" u32 func_00175af8(...);
extern "C" u32 func_0017dcc0(...);

u32 duplicate_unplaced_0017dc98(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0017dcc0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00175af8)(r4);
}

extern "C" u32 func_0017ee68(...);
extern "C" u32 func_00180ce0(...);

u32 duplicate_unplaced_0017eb68(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    u32 (*fp_call4_00180ce0)(u32) = (u32(*)(u32))func_00180ce0;
    r2 = fp_call4_00180ce0(r4);
    r4 = r16;
    u32 (*fp_call4_0017ee68)(u32) = (u32(*)(u32))func_0017ee68;
    r2 = fp_call4_0017ee68(r4);
    return r2;
}

extern "C" u32 func_0017ee68(...);
extern "C" u32 func_00180ce0(...);

u32 duplicate_unplaced_0017eb98(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    u32 (*fp_call4_00180ce0)(u32) = (u32(*)(u32))func_00180ce0;
    r2 = fp_call4_00180ce0(r4);
    r4 = r16;
    u32 (*fp_call4_0017ee68)(u32) = (u32(*)(u32))func_0017ee68;
    r2 = fp_call4_0017ee68(r4);
    return r2;
}

extern "C" u32 func_0017ec98(...);
extern "C" u32 func_0017edf0(...);
extern "C" u32 func_00180408(...);

u32 duplicate_unplaced_001805a8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_0017ec98)(r4, r5);
    r4 = r16;
    r5 = r2;
    r2 = ((u32(*)(u32,u32))func_0017edf0)(r4, r5);
    r4 = r16;
    r5 = r2;
    r2 = ((u32(*)(u32,u32))func_00180408)(r4, r5);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

extern "C" u32 func_0016b5b8(...);
extern "C" u32 func_001dc920(...);

// 001855a0: moved to src/anon/unit_00183088.cpp

extern u8 D_0032bb30;


extern "C" u32 func_00105110(...);
extern "C" u32 func_001d3878(...);

void func_00190000(u32 a0);  // 0x00190000: definition moved into src/anon/unit_0018f140.cpp

extern "C" u32 func_00190208(...);

u32 func_001906c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001906c0: definition moved into src/anon/unit_001900d0.cpp

f32 duplicate_unplaced_00191c20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = (u32)(0x01c6u << 16);
    return *(volatile f32*)((u32)r15 + (s32)(6504));
}

f32 duplicate_unplaced_00191c40(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = (u32)(0x01c6u << 16);
    return *(volatile f32*)((u32)r15 + (s32)(6508));
}

extern "C" u32 func_001708f8(...);
extern "C" u32 func_00191f78(...);
extern "C" u32 func_001921d8(...);

u32 duplicate_unplaced_00192290(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r5;
    r2 = ((u32(*)(u32,u32))func_001921d8)(r4, r5);
    r4 = r2;
    r5 = (u32)((s32)0u + (-1));
    r2 = ((u32(*)(u32,u32))func_001708f8)(r4, r5);
    r4 = r16;
    r5 = r2;
    return ((u32(*)(u32,u32))func_00191f78)(r4, r5);
}

// 00192fb8: moved to src/yasui/libys/message.cpp

extern "C" u32 func_0016b668(...);
extern "C" u32 func_001dc878(...);

u32 duplicate_unplaced_00195f88(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r4 = *(volatile u32*)((u32)r4 + (s32)(2548));
    r2 = ((u32(*)(u32))func_001dc878)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_0016b668)(r4);
}

extern u8 D_0032da20;


extern "C" u32 func_00197c90(...);
extern "C" u32 func_001ada38(...);
extern "C" u32 func_001b9db0(...);

u32 duplicate_unplaced_00197738(u32 a0) {
    u32 r4 = a0, r2;
    r4 = (u32)((s32)0u + (2000));
    r2 = ((u32(*)(u32))func_001b9db0)(r4);
    r2 = ((u32(*)())func_00197c90)();
    r4 = (u32)((s32)0u + (11));
    return ((u32(*)(u32))func_001ada38)(r4);
}

extern "C" u32 func_001b9c28(...);

u32 duplicate_unplaced_00197760(u32 a0) {
    u32 r4 = a0, r2;
    r4 = 0u;
    r2 = ((u32(*)(u32))func_001b9c28)(r4);
    r4 = (u32)((s32)0u + (1));
    return ((u32(*)(u32))func_001b9c28)(r4);
}

extern "C" u32 func_001b9c58(...);

u32 duplicate_unplaced_00197780(u32 a0) {
    u32 r4 = a0, r2;
    r4 = 0u;
    r2 = ((u32(*)(u32))func_001b9c58)(r4);
    r4 = (u32)((s32)0u + (1));
    return ((u32(*)(u32))func_001b9c58)(r4);
}

extern u8 D_01c62198;


u32 func_0019a9e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x0019a9e0: definition moved into src/anon/unit_00199688.cpp

extern "C" u32 func_0016a070(...);
extern "C" u32 func_0019c898(...);

u32 duplicate_unplaced_0019c8a8(u32 a0) {
    u32 r4 = a0, r2;
    u32 (*fp_call0_0016a070)() = (u32(*)())func_0016a070;
    r2 = fp_call0_0016a070();
    r4 = r2;
    u32 (*fp_call4_0019c898)(u32) = (u32(*)(u32))func_0019c898;
    r2 = fp_call4_0019c898(r4);
    return r2;
}

extern "C" u32 func_00190128(...);
extern "C" u32 func_0019ca20(...);

u32 duplicate_unplaced_0019c8d0(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    *(volatile u32*)((u32)r4 + (s32)(0)) = 0u;
    r16 = r4;
    r4 = (u32)((s32)r4 + (4));
    r2 = ((u32(*)(u32))func_00190128)(r4);
    *(volatile u32*)((u32)r16 + (s32)(24)) = 0u;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(32)) = 0u;
    *(volatile u32*)((u32)r16 + (s32)(44)) = 0u;
    r2 = ((u32(*)(u32))func_0019ca20)(r4);
    r14 = (u32)(0x0035u << 16);
    r15 = *(volatile u32*)((u32)r14 + (s32)(1092));
    if (r15 == 0u) r15 = r16;
    *(volatile u32*)((u32)r14 + (s32)(1092)) = r15;
    return r2;
}

extern "C" u32 func_00190128(...);
extern "C" u32 func_0019ca20(...);

u32 duplicate_unplaced_0019c920(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    *(volatile u32*)((u32)r4 + (s32)(0)) = 0u;
    r16 = r4;
    r4 = (u32)((s32)r4 + (4));
    r2 = ((u32(*)(u32))func_00190128)(r4);
    *(volatile u32*)((u32)r16 + (s32)(24)) = 0u;
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(32)) = 0u;
    *(volatile u32*)((u32)r16 + (s32)(44)) = 0u;
    r2 = ((u32(*)(u32))func_0019ca20)(r4);
    r14 = (u32)(0x0035u << 16);
    r15 = *(volatile u32*)((u32)r14 + (s32)(1092));
    if (r15 == 0u) r15 = r16;
    *(volatile u32*)((u32)r14 + (s32)(1092)) = r15;
    return r2;
}

extern "C" u32 func_0019d4f8(...);

u32 duplicate_unplaced_0019d720(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0019d548)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_0019d4f8)(r4);
}

extern "C" u32 func_001a11e0(...);
extern "C" u32 func_001a1840(...);

u32 duplicate_unplaced_001a1460(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001a1840)(r4, r5);
    r4 = r16;
    r5 = 0u;
    return ((u32(*)(u32,u32))func_001a11e0)(r4, r5);
}

u32 func_001a2758(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001a2758: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a2778(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001a2778: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a2798(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001a2798: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a27b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001a27b8: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a27d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001a27d8: definition moved into src/anon/unit_0019fb70.cpp

extern "C" u32 func_001a80c8(...);  // table24_find_by_id
extern "C" u32 func_001b8e88(...);

u32 duplicate_unplaced_001a3868(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_001a80c8)();
    r4 = (u32)(*(u16*)((u32)r2 + (s32)(16)));
    return ((u32(*)(u32))func_001b8e88)(r4);
}

extern "C" u32 func_00170950(...);
extern "C" u32 func_001dde40(...);
extern "C" u32 func_001de450(...);
extern u8 D_01c6cae0;

u32 duplicate_unplaced_001a3b08(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = (u32)&D_01c6cae0;
    r4 = r16;
    r2 = ((u32(*)(u32))func_001de450)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_001dde40)(r4);
    r15 = (u32)(0x01c7u << 16);
    r4 = *(volatile u32*)((u32)r15 + (s32)(-13572));
    return ((u32(*)(u32))func_00170950)(r4);
}

extern u8 D_0032f274;


extern "C" u32 func_001a6598(...);
extern u8 D_0032f274;


extern "C" u32 func_001956d0(...);
extern u8 D_0034fa78;

u32 duplicate_unplaced_001a6c38(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_0016bff0)();
    r4 = (u32)&D_0034fa78;
    r5 = r2;
    return ((u32(*)(u32,u32))func_001956d0)(r4, r5);
}

extern u8 D_0034fa78;

u32 duplicate_unplaced_001a6c60(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    u32 (*fp_call0_0016bff0)() = (u32(*)())func_0016bff0;
    r2 = fp_call0_0016bff0();
    r4 = (u32)&D_0034fa78;
    r5 = r2;
    u32 (*fp_call4_00195700)(u32, u32) = (u32(*)(u32,u32))func_00195700;
    r2 = fp_call4_00195700(r4, r5);
    return r2;
}

extern "C" u32 func_00195700(...);
extern u8 D_0032dec0;


extern "C" u32 func_0019c218(...);
extern "C" u32 func_001b8e88(...);

u32 duplicate_unplaced_001a74f8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r14, r15;
    u32 (*fp_call0_001b8e88)() = (u32(*)())func_001b8e88;
    r2 = fp_call0_001b8e88();
    r14 = (u32)(0x01c7u << 16);
    r5 = r2;
    r15 = *(volatile u32*)((u32)r14 + (s32)(-13448));
    *(volatile u32*)((u32)r15 + (s32)(2480)) = 0u;
    r4 = *(volatile u32*)((u32)r14 + (s32)(-13448));
    u32 (*fp_call4_0019c218)(u32, u32) = (u32(*)(u32,u32))func_0019c218;
    r2 = fp_call4_0019c218(r4, r5);
    return r2;
}

extern "C" u32 func_001d2298(...);



extern "C" u32 func_001a8b28(...);  // get_data_1c7cc10


extern "C" u32 func_0016e920(...);

u32 func_001a8b68(u32 a0);  // 0x001a8b68: definition moved into src/anon/unit_001a8618.cpp

extern "C" u32 func_0016e920(...);
extern "C" u32 func_001a8b28(...);  // get_data_1c7cc10
extern "C" u32 func_001a8bf8(...);  // get_bits5_at

u32 func_001a8c10(u32 a0);  // 0x001a8c10: definition moved into src/anon/unit_001a8618.cpp

extern "C" u32 func_001a8c78(...);
extern "C" u32 func_001a9018(...);

u32 func_001a90a8(u32 a0, u32 a1);  // 0x001a90a8: definition moved into src/anon/unit_001a8618.cpp


extern "C" u32 func_001a8f10(...);  // arg_map_0_1_2

u32 duplicate_unplaced_001a90f0(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_001a8f10)();
    r4 = r2;
    return ((u32(*)(u32))func_001a8b38)(r4);
}

extern u8 D_0032df30;


extern "C" u32 func_002f71b0(...);
extern "C" u32 func_002f79c8(...);
extern "C" u32 func_002f7e60(...);

u32 duplicate_unplaced_001ae650(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_002f7e60)();
    r4 = 0u;
    r2 = ((u32(*)(u32))func_002f71b0)(r4);
    r4 = 0u;
    return ((u32(*)(u32))func_002f79c8)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_001af210(...);

void func_001af3e0(u32 a0);  // 0x001af3e0: definition moved into src/anon/unit_001ada38.cpp

extern "C" u32 func_001708f8(...);
extern "C" u32 func_001af7c0(...);

u32 duplicate_unplaced_001af778(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r15 = (u32)(0x0035u << 16);
    r5 = (u32)((s32)0u + (-1));
    r16 = r4;
    r4 = *(volatile u32*)((u32)r15 + (s32)(3564));
    r2 = ((u32(*)(u32,u32))func_001708f8)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(48));
    r4 = r16;
    *(volatile u32*)((u32)r16 + (s32)(4)) = r2;
    r2 = ((u32(*)(u32,u32))func_001af7c0)(r4, r5);
    *(volatile u32*)((u32)r16 + (s32)(52)) = r2;
    return r2;
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_001b0330(...);
extern u8 D_00350e78;

u32 duplicate_unplaced_001b01d8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_00350e78;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001b0330)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0017c430(...);

u32 duplicate_unplaced_001b27c0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r4 = r5;
    r16 = r5;
    r2 = ((u32(*)(u32,u32))func_0017c430)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (20));
    return ((u32(*)(u32,u32))func_0016bd60)(r4, r5);
}

extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0017c430(...);

u32 duplicate_unplaced_001b2c18(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r4 = r5;
    r16 = r5;
    r2 = ((u32(*)(u32,u32))func_0017c430)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (20));
    return ((u32(*)(u32,u32))func_0016bd60)(r4, r5);
}

ObjCommon_001050c8* func_001050c8(void);
extern "C" u32 func_00165898(...);

u32 duplicate_unplaced_001b2f10(u32 a0) {
    u32 r4 = a0, r2, r14, r15;
    r15 = (u32)((s32)0u + (1));
    r14 = (u32)(0x01d5u << 16);
    *(volatile u32*)((u32)r14 + (s32)(-29552)) = r15;
    r2 = ((u32(*)())func_001050c8)();
    r4 = r2;
    return ((u32(*)(u32))func_00165898)(r4);
}

extern "C" u32 func_001d20a8(...);

u32 duplicate_unplaced_001b5c78(u32 a0) {
    u32 r4 = a0, r2, r16, r17;
    r16 = (u32)((s32)r4 + (104));
    r4 = r16;
    r17 = *(volatile u32*)((u32)r16 + (s32)(44));
    r2 = ((u32(*)(u32))func_001d2180)(r4);
    r4 = r16;
    r2 = ((u32(*)(u32))func_001d20a8)(r4);
    r2 = r17;
    return r2;
}

u32 func_001b8fd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001b8fd8: definition moved into src/anon/unit_001b87a0.cpp

extern "C" u32 func_001a36e0(...);
extern "C" u32 func_001a80c8(...);  // table24_find_by_id
extern "C" u32 func_001b8e88(...);

u32 duplicate_unplaced_001b90c8(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_001a36e0)();
    r4 = r2;
    r2 = ((u32(*)(u32))func_001a80c8)(r4);
    r4 = (u32)(*(u16*)((u32)r2 + (s32)(16)));
    return ((u32(*)(u32))func_001b8e88)(r4);
}

extern "C" u32 func_001029e8(...);
extern "C" u32 func_001a3c88(...);

u32 duplicate_unplaced_001b92d0(u32 a0) {
    u32 r4 = a0, r2, r15;
    u32 (*fp_call0_001a3c88)() = (u32(*)())func_001a3c88;
    r2 = fp_call0_001a3c88();
    r15 = (u32)(0x0035u << 16);
    r4 = *(volatile u32*)((u32)r15 + (s32)(4628));
    u32 (*fp_call4_001029e8)(u32) = (u32(*)(u32))func_001029e8;
    r2 = fp_call4_001029e8(r4);
    return r2;
}

extern "C" u32 func_001ba598(...);
extern "C" u32 func_003204c8(...);
extern u8 D_01d48de0;

u32 duplicate_unplaced_001ba310(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001ba598)(r4, r5);
    r5 = r16;
    r4 = (u32)&D_01d48de0;
    return ((u32(*)(u32,u32))func_003204c8)(r4, r5);
}

extern "C" u32 func_001991a8(...);
extern "C" u32 func_001bb890(...);

u32 duplicate_unplaced_001bb858(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001bb890)(r4, r5);
    r2 = ((u32(*)())func_001bb468)();
    r5 = r16;
    r4 = (u32)((s32)0u + (15));
    return ((u32(*)(u32,u32))func_001991a8)(r4, r5);
}

extern "C" u32 func_001bb4a0(...);
extern "C" u32 func_001bbcb0(...);
extern "C" u32 func_001d5460(...);

// 001bc090: moved to src/yasui/libys/mission.cpp

extern "C" u32 func_001bd668(...);

u32 duplicate_unplaced_001bdc18(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r4 = (u32)((s32)r4 + (2496));
    r2 = ((u32(*)(u32))func_001d48b0)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001bd668)(r4);
}

extern "C" u32 func_00190128(...);

u32 duplicate_unplaced_001bde58(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001bc688)(r4);
    r16 = (u32)((s32)r16 + (12));
    r4 = r16;
    return ((u32(*)(u32))func_00190128)(r4);
}

extern "C" void func_001bc688(...);
extern "C" u32 func_001be4e0(...);
extern "C" u32 func_002ba2e8(...);

u32 duplicate_unplaced_001be4b0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r14;
    r5 = (u32)((s32)0u + (6));
    r14 = *(volatile u32*)((u32)r4 + (s32)(2724));
    if (r14 != 0u) r5 = 0u;
    r2 = ((u32(*)(u32,u32))func_001be4e0)(r4, r5);
    r4 = (u32)((s32)0u + (20));
    r5 = 0u;
    return ((u32(*)(u32,u32))func_002ba2e8)(r4, r5);
}

extern "C" u32 func_001bc778(...);
extern "C" u32 func_001bc990(...);
extern u8 D_00351248;

u32 duplicate_unplaced_001bf0c8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = (u32)((s32)r4 + (1428));
    r4 = r16;
    r2 = ((u32(*)(u32,u32))func_001bc778)(r4, r5);
    r4 = r16;
    r5 = (u32)&D_00351248;
    return ((u32(*)(u32,u32))func_001bc990)(r4, r5);
}

extern u8 D_01d49328;


extern "C" u32 func_001c0cd8(...);
extern "C" u32 func_001c0d38(...);


extern "C" u32 func_001c10f8(...);  // request_pool_block64
extern u8 D_01d49388;


extern "C" u32 func_001db8b8(...);
extern "C" u32 func_003208a8(...);

u32 duplicate_unplaced_001c1890(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r4 = *(volatile u32*)((u32)r4 + (s32)(28));
    r5 = r16;
    r4 = (u32)((s32)r4 + (12));
    u32 (*fp_call4_003208a8)(u32, u32) = (u32(*)(u32,u32))func_003208a8;
    r2 = fp_call4_003208a8(r4, r5);
    r4 = *(volatile u32*)((u32)r16 + (s32)(28));
    r5 = r16;
    r4 = (u32)((s32)r4 + (20));
    u32 (*fp_call4_001db8b8)(u32, u32) = (u32(*)(u32,u32))func_001db8b8;
    r2 = fp_call4_001db8b8(r4, r5);
    return r2;
}

extern "C" u32 func_0016a9a0(...);  // to_16a950
extern "C" u32 func_001c1428(...);

u32 duplicate_unplaced_001c2578(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0016a9a0)(r4);
    r4 = *(volatile u32*)((u32)r16 + (s32)(2548));
    return ((u32(*)(u32))func_001c1428)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_0016b5b8(...);
extern "C" u32 func_001c13e8(...);

// 001c25a0: moved to src/anon/unit_001c0638.cpp
u32 func_001c25a0(u32 a0);

extern "C" u32 func_00191c50(...);

u32 func_001c3618(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x001c3618: definition moved into src/anon/unit_001c2b58.cpp

extern "C" u32 func_0016a9a0(...);  // to_16a950
extern "C" u32 func_001c14e0(...);

u32 duplicate_unplaced_001c6ee8(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0016a9a0)(r4);
    r4 = *(volatile u32*)((u32)r16 + (s32)(2548));
    return ((u32(*)(u32))func_001c14e0)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_001a4e30(...);
extern u8 D_00351da8;

u32 duplicate_unplaced_001c7c68(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_00351da8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)(0x0035u << 16);
    r16 = r4;
    *(volatile u32*)((u32)r14 + (s32)(7576)) = 0u;
    r2 = ((u32(*)(u32))func_001a4e30)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0017c430(...);

u32 duplicate_unplaced_001c90c0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r4 = r5;
    r16 = r5;
    r2 = ((u32(*)(u32,u32))func_0017c430)(r4, r5);
    r4 = r16;
    r5 = (u32)((s32)0u + (20));
    return ((u32(*)(u32,u32))func_0016bd60)(r4, r5);
}

extern "C" u32 func_0017e668(...);

u32 duplicate_unplaced_001c9d88(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_001a8b68)();
    r4 = r2;
    r2 = ((u32(*)(u32))func_0017e668)(r4);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_001a4e30(...);
extern u8 D_00351f78;

u32 duplicate_unplaced_001ca718(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_00351f78;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)(0x0035u << 16);
    r16 = r4;
    *(volatile u32*)((u32)r14 + (s32)(8040)) = 0u;
    r2 = ((u32(*)(u32))func_001a4e30)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_001a4e30(...);
extern u8 D_00351ff0;

u32 duplicate_unplaced_001cbbf8(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_00351ff0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)(0x0035u << 16);
    r16 = r4;
    *(volatile u32*)((u32)r14 + (s32)(8164)) = 0u;
    r2 = ((u32(*)(u32))func_001a4e30)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_001a4e30(...);
extern u8 D_00352060;

u32 duplicate_unplaced_001cc0e8(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_00352060;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)(0x0035u << 16);
    r16 = r4;
    *(volatile u32*)((u32)r14 + (s32)(8272)) = 0u;
    r2 = ((u32(*)(u32))func_001a4e30)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_001a4e30(...);
extern u8 D_003520d0;

u32 duplicate_unplaced_001cced8(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_003520d0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)(0x0035u << 16);
    r16 = r4;
    *(volatile u32*)((u32)r14 + (s32)(8384)) = 0u;
    r2 = ((u32(*)(u32))func_001a4e30)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_0016b5b8(...);
extern "C" u32 func_001dba98(...);

u32 duplicate_unplaced_001ce458(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r4 = *(volatile u32*)((u32)r4 + (s32)(2548));
    r2 = ((u32(*)(u32))func_001dba98)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_0016b5b8)(r4);
}

extern "C" u32 func_001a8b28(...);  // get_data_1c7cc10


extern "C" u32 func_00178280(...);
extern "C" u32 func_00198970(...);

u32 duplicate_unplaced_001d0200(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00198970)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00178280)(r4);
}

extern "C" u32 func_0019cc20(...);

u32 duplicate_unplaced_001d07e0(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r16 = r4;
    r4 = (u32)((s32)r4 + (2932));
    r2 = ((u32(*)(u32))func_001d2710)(r4);
    r4 = ((u32*)(u32)r16)[720];
    r2 = ((u32(*)(u32))func_0019cc20)(r4);
    r15 = ((u32*)(u32)r16)[67];
    r14 = (u32)(0x0020u << 16);
    r15 = (u32)(r15 | r14);
    ((u32*)(u32)r16)[67] = r15;
    return r2;
}

extern "C" u32 func_0014f9a8(...);
extern "C" u32 func_001d1708(...);

u32 func_001d1ae8(u32 a0);  // 0x001d1ae8: definition moved into src/anon/unit_001d14e0.cpp

extern "C" u32 func_0014f9a8(...);
extern "C" u32 func_001d1708(...);

u32 func_001d1b28(u32 a0);  // 0x001d1b28: definition moved into src/anon/unit_001d14e0.cpp

extern "C" u32 func_0014fb00(...);
extern "C" u32 func_001d1708(...);

u32 func_001d1d68(u32 a0);  // 0x001d1d68: definition moved into src/anon/unit_001d14e0.cpp

extern "C" u32 func_00106420(...);
extern "C" u32 func_001d2210(...);
extern u8 D_003525e8;

u32 duplicate_unplaced_001d2070(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_003525e8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001d2210)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_001a4e30(...);
extern u8 D_00352678;

u32 duplicate_unplaced_001d28f0(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_00352678;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)(0x0035u << 16);
    r16 = r4;
    *(volatile u32*)((u32)r14 + (s32)(9832)) = 0u;
    r2 = ((u32(*)(u32))func_001a4e30)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_001d1b60(...);


extern "C" u32 func_00105110(...);
extern "C" u32 func_001a4e30(...);
extern u8 D_003527f0;

u32 duplicate_unplaced_001d74f8(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_003527f0;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)(0x0035u << 16);
    r16 = r4;
    *(volatile u32*)((u32)r14 + (s32)(10212)) = 0u;
    r2 = ((u32(*)(u32))func_001a4e30)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_0014f830(...);
extern "C" u32 func_001d1708(...);

u32 func_001d7c90(u32 a0);  // 0x001d7c90: definition moved into src/anon/unit_001d7458.cpp

extern "C" u32 func_001d8190(...);


extern "C" u32 func_001d8190(...);


extern "C" u32 func_001d8190(...);


extern "C" u32 func_0016b5b8(...);
extern "C" u32 func_001dc920(...);

u32 func_001da158(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(2548));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_001dc920)(r4);
        *(volatile u32*)((u32)r16 + (s32)(2548)) = 0u;
    }
    r4 = r16;
    return ((u32(*)(u32))func_0016b5b8)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_001a4e30(...);
extern u8 D_00352970;

u32 duplicate_unplaced_001da278(u32 a0) {
    u32 r4 = a0, r2, r14, r15, r16;
    r15 = (u32)&D_00352970;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r14 = (u32)(0x0035u << 16);
    r16 = r4;
    *(volatile u32*)((u32)r14 + (s32)(10592)) = 0u;
    r2 = ((u32(*)(u32))func_001a4e30)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00105110)(r4);
}

extern "C" u32 func_001dc9e0(...);
extern "C" u32 func_001e6cd0(...);

u32 duplicate_unplaced_001dc5f8(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001dc9e0)(r4);
    r4 = *(volatile u32*)((u32)r16 + (s32)(28));
    return ((u32(*)(u32))func_001e6cd0)(r4);
}

extern "C" u32 func_001dc9e0(...);
extern "C" u32 func_001e6cd8(...);

u32 duplicate_unplaced_001dc620(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001dc9e0)(r4);
    r4 = *(volatile u32*)((u32)r16 + (s32)(28));
    return ((u32(*)(u32))func_001e6cd8)(r4);
}

extern "C" u32 func_001dc9e0(...);
extern "C" u32 func_001e6ce8(...);

u32 duplicate_unplaced_001dc648(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001dc9e0)(r4);
    r4 = *(volatile u32*)((u32)r16 + (s32)(28));
    return ((u32(*)(u32))func_001e6ce8)(r4);
}

extern "C" u32 func_001dc9e0(...);
extern "C" u32 func_001e6cf8(...);

u32 duplicate_unplaced_001dc670(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001dc9e0)(r4);
    r4 = *(volatile u32*)((u32)r16 + (s32)(28));
    return ((u32(*)(u32))func_001e6cf8)(r4);
}

extern "C" u32 func_001dc9e0(...);
extern "C" u32 func_001e2c78(...);

u32 duplicate_unplaced_001dc7e8(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001dc9e0)(r4);
    r4 = ((u32*)(u32)r16)[7];
    r2 = ((u32(*)(u32))func_001e2c78)(r4);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

extern "C" u32 func_001dc9e0(...);
extern "C" u32 func_001e6d08(...);

u32 duplicate_unplaced_001dc9f0(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_001dc9e0)(r4);
    r4 = ((u32*)(u32)r16)[7];
    r2 = ((u32(*)(u32))func_001e6d08)(r4);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

extern "C" u32 func_001e0cc8(...);  // entry64_by_field32
extern "C" u32 func_001e26b8(...);

u32 duplicate_unplaced_001e0f90(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_001e0cc8)(r4, r5);
    r15 = (u32)(0x0035u << 16);
    r5 = r2;
    r4 = ((u32*)(u32)r15)[2804];
    r2 = ((u32(*)(u32,u32))func_001e26b8)(r4, r5);
    r15 = (u32)((s32)0u + (5));
    ((u32*)(u32)r16)[10] = 0u;
    ((u32*)(u32)r16)[9] = r15;
    return r2;
}

extern "C" u32 sceGsSyncPath(...);
extern "C" u32 func_002f3918(...);
extern u8 D_003598e0;

u32 duplicate_unplaced_0020f118(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r4 = 0u;
    r5 = 0u;
    u32 (*fp_call4_002f25a0)(u32, u32) = (u32(*)(u32,u32))sceGsSyncPath;
    r2 = fp_call4_002f25a0(r4, r5);
    r15 = (u32)(0x0036u << 16);
    r5 = (u32)&D_003598e0;
    r4 = *(volatile u32*)((u32)r15 + (s32)(-28216));
    u32 (*fp_call4_002f3918)(u32, u32) = (u32(*)(u32,u32))func_002f3918;
    r2 = fp_call4_002f3918(r4, r5);
    return r2;
}

extern "C" u32 sceGsSyncPath(...);
extern "C" u32 func_002f3918(...);
extern u8 D_00359910;

u32 duplicate_unplaced_0020f150(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r4 = 0u;
    r5 = 0u;
    u32 (*fp_call4_002f25a0)(u32, u32) = (u32(*)(u32,u32))sceGsSyncPath;
    r2 = fp_call4_002f25a0(r4, r5);
    r15 = (u32)(0x0036u << 16);
    r5 = (u32)&D_00359910;
    r4 = *(volatile u32*)((u32)r15 + (s32)(-28216));
    u32 (*fp_call4_002f3918)(u32, u32) = (u32(*)(u32,u32))func_002f3918;
    r2 = fp_call4_002f3918(r4, r5);
    return r2;
}

extern "C" u32 func_0014a4b0(...);

u32 duplicate_unplaced_00226d88(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_0014a4b0)();
    r4 = 0u;
    return ((u32(*)(u32))func_00138480)(r4);
}


extern "C" u32 func_001390f0(...);
extern "C" u32 func_00229d40(...);

u32 duplicate_unplaced_00229d68(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00229d40)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001390f0)(r4);
}

extern "C" u32 func_001390f0(...);
extern "C" u32 func_0022ac60(...);

u32 duplicate_unplaced_0022acd0(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0022ac60)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001390f0)(r4);
}

extern "C" u32 func_00105110(...);
extern "C" u32 func_002369f0(...);  // set_vtbl_36eac8_then_call
extern "C" u32 func_0023c098(...);  // set_vtbl_36eae8_then_call
extern "C" u32 func_0023f848(...);

// 0022b968: moved to src/sasa/musical_2d.cpp (linked unit)

extern "C" u32 func_001024a8(...);
extern "C" u32 func_00226e60(...);

u32 duplicate_unplaced_0022be28(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = r4;
    r4 = 0u;
    r2 = ((u32(*)(u32))func_00226e60)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_001024a8)(r4);
}

extern "C" u32 func_002f35e8(...);
extern "C" u32 func_002f3918(...);
extern u8 D_0035e3f0;

u32 duplicate_unplaced_002367a0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r4 = (u32)((s32)0u + (2));
    r2 = ((u32(*)(u32,u32))func_002f35e8)(r4, r5);
    r5 = (u32)&D_0035e3f0;
    r4 = r2;
    return ((u32(*)(u32,u32))func_002f3918)(r4, r5);
}

extern "C" u32 sceGsExecLoadImage(...);

u32 duplicate_unplaced_002368b0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r5 = *(volatile u32*)((u32)r4 + (s32)(56));
    r4 = (u32)((s32)r4 + (64));
    r2 = ((u32(*)(u32,u32))sceGsExecLoadImage)(r4, r5);
    r5 = *(volatile u32*)((u32)r16 + (s32)(60));
    r16 = (u32)((s32)r16 + (160));
    r4 = r16;
    return ((u32(*)(u32,u32))sceGsExecLoadImage)(r4, r5);
}

extern "C" u32 func_00106420(...);
extern "C" u32 func_00236c38(...);
extern u8 D_0035eac8;

u32 duplicate_unplaced_00236a18(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035eac8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00236c38)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}


extern "C" u32 func_00106420(...);
extern "C" u32 func_00237238(...);
extern u8 D_0035eaf8;

u32 duplicate_unplaced_00239898(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035eaf8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_00237238)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_0023a0d8(...);

u32 func_0023a918(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r15 = (u32)(*(u8*)((u32)r4 + (s32)(212)));
    r16 = r4;
    if (r15 == 0u) {
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0023a0d8)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    r2 = *(volatile u32*)((u32)r16 + (s32)(224));
    return r2;
}





extern "C" u32 func_00106420(...);
extern "C" u32 func_0023c300(...);
extern u8 D_0035eb08;

u32 duplicate_unplaced_0023c0c0(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035eb08;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0023c300)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_0023c598(...);
extern "C" u32 func_0023c728(...);

u32 duplicate_unplaced_0023c6f8(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0023c728)(r4);
    r15 = (u32)((s32)0u + (1));
    *(volatile u32*)((u32)r16 + (s32)(56)) = r15;
    r4 = r16;
    return ((u32(*)(u32))func_0023c598)(r4);
}


extern "C" u32 func_0023d820(...);

void func_0023d7c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r15 = (u32)(*(u8*)((u32)r4 + (s32)(5344)));
    r16 = r4;
    if (r15 == 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0023d820)(r4, r5, r6, r7, r8, r9, r10, r11);
        r15 = (u32)((s32)0u + (1));
        *(volatile u32*)((u32)r16 + (s32)(2924)) = 0u;
        *(u8*)((u32)r16 + (s32)(5344)) = (u8)r15;
    }
}

extern "C" u32 func_0011eb08(...);





extern "C" u32 func_00106420(...);
extern "C" u32 func_0023f8c8(...);
extern u8 D_0035ebd8;

u32 duplicate_unplaced_0023f870(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r15 = (u32)&D_0035ebd8;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    r16 = r4;
    r2 = ((u32(*)(u32))func_0023f8c8)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_00106420)(r4);
}

extern "C" u32 func_001708f8(...);
extern "C" u32 func_0023fa08(...);

u32 duplicate_unplaced_0023fa90(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r16 = r4;
    r4 = r5;
    r5 = (u32)((s32)0u + (-1));
    r2 = ((u32(*)(u32,u32))func_001708f8)(r4, r5);
    r4 = r16;
    r5 = r2;
    r2 = ((u32(*)(u32,u32))func_0023fa08)(r4, r5);
    r15 = (u32)((s32)0u + (1));
    *(volatile u8*)((u32)r16 + (s32)(24)) = (u8)r15;
    return r2;
}

extern "C" u32 func_00242088(...);
extern "C" u32 func_002ef938(...);

u32 duplicate_unplaced_002421c0(u32 a0) {
    u32 r4 = a0, r2, r16;
    r16 = *(volatile u32*)((u32)r4 + (s32)(4));
    r2 = ((u32(*)(u32))func_00242088)(r4);
    r4 = r16;
    return ((u32(*)(u32))func_002ef938)(r4);
}

extern "C" u32 func_00243020(...);
extern "C" u32 func_00243190(...);

u32 duplicate_unplaced_002430b0(u32 a0) {
    u32 r4 = a0, r2, r14;
    r14 = (u32)(0x0036u << 16);
    *(volatile u32*)((u32)r14 + (s32)(-4896)) = r4;
    r2 = ((u32(*)(u32))func_00243190)(r4);
    r4 = r2;
    return ((u32(*)(u32))func_00243020)(r4);
}

extern "C" u32 func_001a6d08(...);

u32 duplicate_unplaced_00246968(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    u32 (*fp_call4_00246868)(u32) = (u32(*)(u32))func_00246868;
    r2 = fp_call4_00246868(r4);
    r15 = (u32)((s32)0u + (36));
    r16 = (u32)((s32)r16 * (s32)r15);
    r16 = (u32)(r16 + r2);
    r4 = (u32)(s32)(*(s8*)((u32)r16 + (s32)(28)));
    u32 (*fp_call4_001a6d08)(u32) = (u32(*)(u32))func_001a6d08;
    r2 = fp_call4_001a6d08(r4);
    return r2;
}

extern "C" u32 func_0028dbf8(...);
extern u8 D_00372348;
extern u8 D_00372380;


extern "C" u32 func_00253180(...);
extern "C" u32 func_0026d808(...);

u32 duplicate_unplaced_002533e0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r16 = r4;
    r4 = r5;
    r2 = ((u32(*)(u32,u32))func_0026d808)(r4, r5);
    r5 = r16;
    r4 = (u32)((s32)0u + (6));
    return ((u32(*)(u32,u32))func_00253180)(r4, r5);
}

extern "C" u32 func_00258af0(...);
extern "C" u32 func_00258b00(...);

u32 duplicate_unplaced_00253480(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_00258b00)();
    r4 = (u32)((s32)0u + (9));
    return ((u32(*)(u32))func_00258af0)(r4);
}

extern "C" u32 func_00253180(...);
extern "C" u32 func_00274f98(...);

extern "C" u32 func_00103500(...);
extern "C" u32 func_001037b8(...);
extern "C" u32 func_00253330(...);
extern "C" u32 func_00288648(...);

u32 duplicate_unplaced_00253538(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_00288648)();
    r4 = (u32)((s32)0u + (10));
    r2 = ((u32(*)(u32))func_00253330)(r4);
    r4 = (u32)(s32)(*(s16*)((u32)r2 + (s32)(2)));
    r2 = ((u32(*)(u32))func_00103500)(r4);
    return ((u32(*)())func_001037b8)();
}

extern "C" u32 func_0023fa08(...);
extern "C" u32 func_002537c8(...);
extern u8 D_0035f3a8;

u32 duplicate_unplaced_00256b40(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r4 = (u32)((s32)0u + (2));
    r2 = ((u32(*)(u32,u32))func_002537c8)(r4, r5);
    r4 = (u32)&D_0035f3a8;
    r5 = r2;
    return ((u32(*)(u32,u32))func_0023fa08)(r4, r5);
}

extern "C" u32 func_00257770(...);
extern "C" u32 func_0028dac8(...);

u32 duplicate_unplaced_00256e80(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_00257770)();
    r4 = (u32)((s32)r2 + (2940));
    r5 = (u32)((s32)0u + (239));
    return ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
}

extern "C" u32 func_00139d78(...);
extern "C" u32 func_00257770(...);

u32 duplicate_unplaced_00256ef0(u32 a0) {
    u32 r4 = a0, r2;
    u32 (*fp_call0_00257770)() = (u32(*)())func_00257770;
    r2 = fp_call0_00257770();
    r4 = (u32)((s32)r2 + (2940));
    u32 (*fp_call4_00139d78)(u32) = (u32(*)(u32))func_00139d78;
    r2 = fp_call4_00139d78(r4);
    return r2;
}

extern "C" u32 func_00257070(...);
extern "C" u32 func_00257088(...);

u32 duplicate_unplaced_002570a0(u32 a0) {
    u32 r4 = a0, r2, r16, r17;
    r17 = r4;
    r2 = ((u32(*)(u32))func_00257070)(r4);
    r4 = r17;
    r16 = r2;
    r2 = ((u32(*)(u32))func_00257088)(r4);
    r16 = (u32)(r16 + r2);
    r2 = r16;
    return r2;
}

extern "C" u32 func_0023fa08(...);
extern "C" u32 func_002537c8(...);

u32 duplicate_unplaced_00258a88(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r4 = 0u;
    r2 = ((u32(*)(u32,u32))func_002537c8)(r4, r5);
    r15 = (u32)(0x0036u << 16);
    r4 = *(volatile u32*)((u32)r15 + (s32)(-3980));
    r5 = r2;
    return ((u32(*)(u32,u32))func_0023fa08)(r4, r5);
}

extern "C" u32 func_00257770(...);
extern "C" u32 func_0028da70(...);

u32 duplicate_unplaced_00263188(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_00257770)();
    r4 = (u32)((s32)r2 + (408));
    r5 = (u32)((s32)0u + (300));
    return ((u32(*)(u32,u32))func_0028da70)(r4, r5);
}

extern "C" u32 func_00257770(...);
extern "C" u32 func_0028da70(...);

u32 duplicate_unplaced_002631b0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15;
    r2 = ((u32(*)())func_00257770)();
    r15 = (u32)(0u | 0xb350u);
    r5 = (u32)((s32)0u + (307));
    r4 = (u32)(r2 + r15);
    return ((u32(*)(u32,u32))func_0028da70)(r4, r5);
}

extern "C" u32 func_001a3888(...);  // id_in_range_5_7_131
extern "C" u32 func_002632d0(...);

u32 duplicate_unplaced_00263688(u32 a0) {
    u32 r4 = a0, r2;
    u32 (*fp_call0_002632d0)() = (u32(*)())func_002632d0;
    r2 = fp_call0_002632d0();
    r4 = (u32)(*(u16*)((u32)r2 + (s32)(0)));
    u32 (*fp_call4_001a3888)(u32) = (u32(*)(u32))func_001a3888;
    r2 = fp_call4_001a3888(r4);
    return r2;
}

extern "C" u32 func_00192048(...);
extern "C" u32 func_00263a90(...);

u32 duplicate_unplaced_00263a58(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r2 = 0u;
    r16 = (u32)(r5 & 0x00ffu);
    if ((s32)r4 >= 0) {
        r2 = ((u32(*)(u32,u32))func_00192048)(r4, r5);
    }
    r5 = r16;
    r4 = r2;
    return ((u32(*)(u32,u32))func_00263a90)(r4, r5);
}

extern "C" u32 func_00257770(...);
extern "C" u32 func_0028da70(...);

u32 duplicate_unplaced_00265780(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_00257770)();
    r4 = r2;
    r5 = (u32)((s32)0u + (141));
    return ((u32(*)(u32,u32))func_0028da70)(r4, r5);
}

extern "C" u32 func_00257770(...);
extern "C" u32 func_0028da70(...);

u32 duplicate_unplaced_00265c50(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r2 = ((u32(*)())func_00257770)();
    r4 = r2;
    r5 = (u32)((s32)0u + (321));
    return ((u32(*)(u32,u32))func_0028da70)(r4, r5);
}

extern "C" u32 func_0026b470(...);
extern "C" u32 func_0026b508(...);
extern "C" u32 func_0026b5a0(...);

u32 duplicate_unplaced_0026b448(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_0026b470)();
    r2 = ((u32(*)())func_0026b508)();
    r4 = (u32)((s32)0u + (-1));
    return ((u32(*)(u32))func_0026b5a0)(r4);
}

extern "C" u32 func_0023d820(...);
extern "C" u32 func_00287dc0(...);

u32 duplicate_unplaced_0026c450(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_00287dc0)();
    r4 = r2;
    return ((u32(*)(u32))func_0023d820)(r4);
}

extern "C" u32 func_00257708(...) asm("_ZN2Tz5CmTop13SetHideCursorEb");
extern "C" u32 func_0026bc10(...);
extern "C" u32 func_0026ceb0(...);

u32 duplicate_unplaced_0026c9c8(u32 a0) {
    u32 r4 = a0, r2;
    r2 = ((u32(*)())func_0026bc10)();
    r4 = 0u;
    r2 = ((u32(*)(u32))func_00257708)(r4);
    return ((u32(*)())func_0026ceb0)();
}

extern "C" u32 func_0023fa08(...);
extern "C" u32 func_002537c8(...);
extern u8 D_0035f3a8;

u32 duplicate_unplaced_0026ec70(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    r4 = 0u;
    r2 = ((u32(*)(u32,u32))func_002537c8)(r4, r5);
    r4 = (u32)&D_0035f3a8;
    r5 = r2;
    return ((u32(*)(u32,u32))func_0023fa08)(r4, r5);
}

extern "C" u32 func_00192048(...);
extern u8 D_00373970;

u32 duplicate_unplaced_00271828(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r15, r16;
    r15 = (u32)&D_00373970;
    r4 = (u32)(r4 << 2);
    r4 = (u32)(r4 + r15);
    r4 = *(volatile u32*)((u32)r4 + (s32)(0));
    r16 = r5;
    r2 = ((u32(*)(u32,u32))func_00192048)(r4, r5);
    r4 = r16;
    r5 = r2;
    r2 = ((u32(*)(u32,u32))func_002595e8)(r4, r5);
    r2 = r16;
    return r2;
}

extern "C" u32 func_00275dd0(...);
extern "C" u32 func_0028dac8(...);

u32 duplicate_unplaced_00275c78(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    r5 = (u32)((s32)0u + (55));
    r16 = (u32)(0x0036u << 16);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-3572));
    r4 = (u32)((s32)r4 + (872));
    r2 = ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
    r4 = *(volatile u32*)((u32)r16 + (s32)(-3572));
    r5 = (u32)((s32)0u + (46));
    r4 = (u32)((s32)r4 + (1308));
    r2 = ((u32(*)(u32,u32))func_0028dac8)(r4, r5);
    return ((u32(*)())func_00275dd0)();
}

extern "C" u32 func_00139d78(...);
extern u8 D_0035f204;

u32 func_00276368(void);  // 0x00276368: definition moved into src/anon/unit_002748a0.cpp

extern "C" u32 func_001058e8(...);


extern "C" u32 func_001b77d0(...);


extern "C" u32 func_001058e8(...);
extern "C" u32 func_00189200(...);

u32 func_002814b0(u32 a0, u32 a1);  // 0x002814b0: definition moved into src/anon/unit_0027f2b0.cpp

extern "C" u32 func_001058e8(...);


extern "C" u32 func_002843e8(...);
extern "C" u32 func_00284538(...);

void func_002843c0(void);  // 0x002843c0: definition moved into src/anon/unit_00284220.cpp

extern "C" u32 func_0028af18(...);
extern "C" u32 func_0028b1b0(...);

u32 duplicate_unplaced_0028b0e0(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16;
    *(u8*)((u32)r4 + (s32)(37)) = (u8)0u;
    r5 = (u32)((s32)0u + (115));
    *(u8*)((u32)r4 + (s32)(38)) = (u8)0u;
    r16 = r4;
    *(u16*)((u32)r4 + (s32)(24)) = (u16)0u;
    *(u16*)((u32)r4 + (s32)(26)) = (u16)0u;
    r2 = ((u32(*)(u32,u32))func_0028af18)(r4, r5);
    r4 = r16;
    r5 = 0u;
    return ((u32(*)(u32,u32))func_0028b1b0)(r4, r5);
}

extern "C" u32 func_00289310() asm("_ZN2Tz6Select12isCursorMoveEv");
extern "C" u32 func_002a4430();
extern "C" void func_00296ed0() asm("_ZN2Tz8JmReport10DrawUpdateEPNS_6SelectEii");

extern "C" u32 func_0029a740() asm("_ZN2Tz12JmCollection10DrawUpdateEPNS_6SelectEii");

void func_0029a718(void);  // 0x0029a718: definition moved into src/anon/unit_00299920.cpp

f32 duplicate_unplaced_001070a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    return *(volatile f32*)((u32)a0 + (s32)(108));
}

f32 duplicate_unplaced_001142a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = *(volatile u32*)((u32)a0 + (s32)(8));
    return *(volatile f32*)((u32)r15 + (s32)(96));
}

f32 duplicate_unplaced_001142b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = *(volatile u32*)((u32)a0 + (s32)(8));
    return *(volatile f32*)((u32)r15 + (s32)(100));
}

f32 duplicate_unplaced_001142c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = *(volatile u32*)((u32)a0 + (s32)(8));
    return *(volatile f32*)((u32)r15 + (s32)(104));
}

f32 duplicate_unplaced_001142d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = *(volatile u32*)((u32)a0 + (s32)(8));
    return *(volatile f32*)((u32)r15 + (s32)(108));
}

f32 duplicate_unplaced_00114370(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = *(volatile u32*)((u32)a0 + (s32)(8));
    return *(volatile f32*)((u32)r15 + (s32)(128));
}

f32 duplicate_unplaced_00114380(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = *(volatile u32*)((u32)a0 + (s32)(8));
    return *(volatile f32*)((u32)r15 + (s32)(132));
}

f32 duplicate_unplaced_00114390(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r15 = *(volatile u32*)((u32)a0 + (s32)(8));
    return *(volatile f32*)((u32)r15 + (s32)(136));
}

extern u8 D_00345f10;
extern u8 D_003461e8;


extern u8 D_00345f10;
extern u8 D_003461e8;


extern u8 D_00346220;
extern u8 D_003464b0;


extern u8 D_003464e8;
extern u8 D_00346658;


extern u8 D_003464e8;
extern u8 D_00346658;


extern u8 D_00346690;
extern u8 D_003467b8;


extern u8 D_00346690;
extern u8 D_003467b8;


extern u8 D_003467f0;
extern u8 D_00346960;


extern u8 D_00346998;
extern u8 D_00346b08;


extern u8 D_00346998;
extern u8 D_00346b08;


extern "C" u32 func_00139d78(...);
extern u8 D_00347d60;

extern "C" u32 func_0013cb08(...);
extern "C" u32 func_001bcf38(...);  // state_in_set_5_10_13to18

extern "C" u32 func_0013a810(...);
extern "C" u32 func_0013cb08(...);
extern u8 D_003484a0;

extern "C" u32 func_0023aa98(...);

void func_0013cdc8(u32 a0, u32 a1);  // 0x0013cdc8: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_00102c18(...);
extern u8 D_0013d750;

void duplicate_unplaced_0013d798(void) {
    u32 a1 = 0x000186a0u;
    u32 a2 = (u32)&D_0013d750;
    func_00102c18(1u, a1, a2);
}

extern "C" u32 func_00157880(...);
extern u8 D_003485ec;

void func_0013dbe0(u32 a0);  // 0x0013dbe0: definition moved into src/anon/unit_0013a8b8.cpp

u32 func_0013dc08(u32 a0, u32 a1);  // 0x0013dc08: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013dc78(u32 a0, u32 a1, u32 a2);  // 0x0013dc78: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_0013dc08(...);  // list_contains_id_b
extern "C" u32 func_0013dc78(...);
extern u8 D_00348638;

void func_0013de08(u32 a0);  // 0x0013de08: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_0013dc08(...);  // list_contains_id_b
extern "C" u32 func_0013dc78(...);
extern u8 D_00348638;

void func_0013de58(u32 a0);  // 0x0013de58: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_0013dc08(...);  // list_contains_id_b
extern "C" u32 func_0013dc78(...);
extern u8 D_00348638;

void func_0013dea8(u32 a0);  // 0x0013dea8: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_0013dc08(...);  // list_contains_id_b
extern "C" u32 func_0013dc78(...);
extern u8 D_00348638;

void func_0013def8(u32 a0);  // 0x0013def8: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_001390f0(...);
extern "C" u32 func_00139d78(...);

void func_0013e470(u32 a0);  // 0x0013e470: definition moved into src/anon/unit_0013dfb8.cpp

void func_0013ee18(u32 a0, u64 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    *(volatile u64*)((u32)a0 + (s32)(128)) = a1;
}

void duplicate_unplaced_0013ee40(u32 a0, u64 a1, u64 a2, u64 a3, u64 a4, u32 a5, u32 a6, u32 a7) {
    *(volatile u64*)((u32)a0 + (s32)(208)) = a1;
    *(volatile u64*)((u32)a0 + (s32)(256)) = a4;
    *(volatile u64*)((u32)a0 + (s32)(224)) = a2;
    *(volatile u64*)((u32)a0 + (s32)(240)) = a3;
}

extern "C" u32 func_0013f030(...);
extern "C" u32 func_0013f048(...);
extern "C" u32 func_0014aa80(...);
extern "C" u32 func_0014aba8(...);

u32 duplicate_unplaced_0013f160(void) {
    func_0013f030();
    func_0013f048();
    u32 r2 = func_0014aba8();
    return func_0014aa80(r2, 1u, 0u);
}

extern "C" u32 func_001024a8(...);
extern "C" u32 func_0013f020(...);
extern "C" u32 func_0014aba8(...);

void func_0013f198(u32 a0);  // 0x0013f198: definition moved into src/anon/unit_0013ef70.cpp

extern "C" u32 func_001024a8(...);
extern "C" u32 func_0013f048(...);
extern "C" u32 func_0014aba8(...);

void func_0013f1e8(u32 a0);  // 0x0013f1e8: definition moved into src/anon/unit_0013ef70.cpp

extern "C" u32 func_001024a8(...);
extern "C" u32 func_0013f048(...);
extern "C" u32 func_0014aba8(...);

void func_0013f330(u32 a0);  // 0x0013f330: definition moved into src/anon/unit_0013ef70.cpp

extern "C" u32 func_00102448(...);
extern "C" u32 func_0013f048(...);
extern "C" u32 func_0014e098(...);

void duplicate_unplaced_0013f450(u32 a0) {
    u32 s0 = a0;
    func_0014e098((u32)((s32)0u + (216)));
    func_00102448(s0, 0u);
    func_0014e098((u32)((s32)0u + (216)));
    func_00102448(s0, 0u);
    func_0013f048();
}

extern "C" u32 func_00102788(...);
extern "C" u32 func_00102c80(...);
extern "C" u32 func_0013efe8(...);
extern "C" u32 func_0013f428(...);

void duplicate_unplaced_0013f498(void) {
    func_0013efe8();
    u32 r2 = func_00102c80();
    u32 a0 = *(volatile u32*)((u32)r2 + (s32)(4));
    u32 a2 = (u32)(0x0004u << 16);
    u32 a3 = (u32)&func_0013f428;
    u32 a1 = 0u;
    a2 = (u32)(a2 | 0x93e0u);
    func_00102788(a0, a1, a2, a3);
}

extern "C" u32 func_00102818(...);
extern "C" u32 func_00102c80(...);
extern "C" u32 func_0013f030(...);
void func_0013f450(u32);

void duplicate_unplaced_0013f4d8(void) {
    func_0013f030();
    u32 r2 = func_00102c80();
    u32 a0 = *(volatile u32*)((u32)r2 + (s32)(4));
    u32 a2 = (u32)(0x0004u << 16);
    u32 a3 = (u32)&func_0013f450;
    u32 a1 = (u32)((s32)0u + (1));
    a2 = (u32)(a2 | 0x93e0u);
    u32 a4 = (u32)((s32)0u + (4096));
    func_00102818(a0, a1, a2, a3, a4);
}

f32 func_002f8ad0(f32, f32);

void func_0013fcd8(u32 a0, f32* a1);  // 0x0013fcd8: definition moved into src/anon/unit_0013fca8.cpp

u32 func_0013fda0(u32 a0);  // 0x0013fda0: definition moved into src/anon/unit_0013fca8.cpp

u32 func_0013fdc8(u32 a0);  // 0x0013fdc8: definition moved into src/anon/unit_0013fca8.cpp

extern "C" u32 func_00102788(...);
extern "C" u32 func_00102c80(...);
extern "C" u32 func_001069b8(...);  // swap_global_word
extern "C" u32 func_0013f558(...);
extern "C" u32 func_00140cc8(...);
extern "C" u32 func_0015ce90(...);  // zero_global_byte_g
extern u8 D_00348710;

void duplicate_unplaced_00140ce8(void) {
    func_0015ce90();  // zero_global_byte_g
    func_001069b8(0u);  // swap_global_word
    func_0013f558((u32)&D_00348710);
    u32 r2 = func_00102c80();
    u32 a0 = *(volatile u32*)((u32)r2 + (s32)(4));
    u32 a3 = (u32)&func_00140cc8;
    u32 a1 = (u32)((s32)0u + (1));
    u32 a2 = (u32)((s32)0u + (26000));
    func_00102788(a0, a1, a2, a3);
}

extern "C" u32 func_0013f5f0(...);  // copy_float_220_to_48
extern "C" u32 func_0013f648(...);

void func_00140f30(u32 a0);  // 0x00140f30: definition moved into src/anon/unit_0013fca8.cpp

void func_00141808(u32 a0);  // 0x00141808: definition moved into src/anon/unit_00141458.cpp


extern "C" u32 func_00141970(...);  // vtable_get12
extern "C" u32 func_001450e8(...);

u32 duplicate_unplaced_00142900(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s1 = a2;
    u32 s0 = *(u32*)((u32)a0 + (s32)(4));
    u32 v0 = func_00141970(a0, a1, a2, a3);  // vtable_get12
    s0 = (u32)((s32)s0 + (16));
    return func_001450e8(s0, v0, s1);
}


extern "C" u32 func_00143ae0(...);

u32 func_00143ac0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00143ac0: definition moved into src/anon/unit_00142c90.cpp

extern "C" u32 func_00142278(...);


void func_00144450(u32 a0) {
    f32 z = 0.0f;
    *(volatile f32*)((u32)a0 + (s32)(0)) = z;
    *(volatile f32*)((u32)a0 + (s32)(20)) = z;
    *(volatile f32*)((u32)a0 + (s32)(16)) = z;
    *(volatile f32*)((u32)a0 + (s32)(12)) = z;
    *(volatile f32*)((u32)a0 + (s32)(8)) = z;
    *(volatile f32*)((u32)a0 + (s32)(4)) = z;
}

void func_00144490(u32 a0, u32 a1, u32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8) {
    *(volatile f32*)((u32)a0 + (s32)(0)) = a3;
    *(volatile f32*)((u32)a0 + (s32)(4)) = a4;
    *(volatile f32*)((u32)a0 + (s32)(8)) = a5;
    *(volatile f32*)((u32)a0 + (s32)(12)) = a6;
    *(volatile f32*)((u32)a0 + (s32)(16)) = a7;
    *(volatile f32*)((u32)a0 + (s32)(20)) = a8;
}

void func_001447c0(u32 a0, u32 a1, u32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8) {
    *(volatile f32*)((u32)a0 + (s32)(0)) = a3;
    *(volatile f32*)((u32)a0 + (s32)(4)) = a4;
    *(volatile f32*)((u32)a0 + (s32)(8)) = a5;
    *(volatile f32*)((u32)a0 + (s32)(12)) = a6;
    *(volatile f32*)((u32)a0 + (s32)(16)) = a7;
    *(volatile f32*)((u32)a0 + (s32)(20)) = a8;
}

void func_00146d28(u32 a0) {
    *(volatile u32*)((u32)a0 + (s32)(21344)) = 0u;
    s32 n = *(volatile s32*)((u32)a0 + (s32)(16));
    if (n <= 0) return;
    s32 cnt = n;
    u32 idx = 0u;
L:
    u32 base = *(volatile u32*)((u32)a0 + (s32)(4));
    cnt = (s32)(cnt - 1);
    u32 s = (u32)(idx + base); base = s;
    *(volatile u32*)((u32)base + (s32)(44)) = 0u;
    if (cnt != 0) {
        idx = (u32)(idx + (48));
        goto L;
    }
}

void func_00146de0(u32 a0) {
    s32 t7 = *(volatile s32*)((u32)a0 + (s32)(21344));
    if (t7 <= 0) return;
    s32 t4 = t7;
    u32 t2 = (u32)-3;
    u32 t3 = (u32)-2;
L:
    u32 t7p = *(volatile u32*)((u32)a0 + (s32)(17248));
    t4 = (s32)(t4 - 1);
    u32 t6 = *(volatile u32*)((u32)t7p + (s32)(248));
    t6 = (u32)(t6 & t2);
    *(volatile u32*)((u32)t7p + (s32)(248)) = t6;
    u32 t5 = *(volatile u32*)((u32)a0 + (s32)(17252));
    t5 = (u32)(t5 & t3);
    *(volatile u32*)((u32)a0 + (s32)(17252)) = t5;
    if (t4 != 0) {
        a0 = (u32)((s32)a0 + (8));
        goto L;
    }
}

void func_00146e70(u32 a0, u32 a1, u32 a2) {
    if (a2 == 0u) {
        *(volatile u32*)((u32)a0 + (s32)(21360)) = a1;
        return;
    }
    *(volatile u32*)((u32)a0 + (s32)(21364)) = a1;
}

u32 func_00147a68(u32 a0, u32 a1, u32 a2) {
    s32 t6 = *(s32*)((u32)a1 + (s32)(0));
    u32 t7;
    u32 t5;
    u32 v0;
    if (t6 < 0) goto RET1;
    t7 = (u32)(t6 << 2);
    t5 = 1u;
    v0 = (u32)(t7 + a2);
LOOP:
    t7 = *(u32*)((u32)v0 + (s32)(0));
    if (t7 != t5) {
        *(s32*)((u32)a1 + (s32)(0)) = t6;
        return *(u32*)((u32)v0 + (s32)(0));
    }
    t6 = (s32)(t6 - 1);
    if (t6 >= 0) {
        v0 = (u32)((u32)v0 - 4);
        goto LOOP;
    }
RET1:
    return 1u;
}

extern "C" u32 func_00134408(...);

void func_00148528(u32 a0) {
    u32 t6 = *(u32*)((u32)a0 + (s32)(21360));
    if (t6 != 0u) {
        u32 t7 = *(volatile u32*)((u32)t6 + (s32)(248));
        t7 = (u32)(t7 | 0x0004u);
        *(volatile u32*)((u32)t6 + (s32)(248)) = t7;
    }
    a0 = *(u32*)((u32)a0 + (s32)(21364));
    if (a0 != 0u) {
        u32 t7 = *(volatile u32*)((u32)a0 + (s32)(248));
        t7 = (u32)(t7 | 0x0004u);
        *(volatile u32*)((u32)a0 + (s32)(248)) = t7;
    }
}

void func_00148560(u32 a0) {
    u32 t5 = *(u32*)((u32)a0 + (s32)(21360));
    if (t5 != 0u) {
        u32 t6 = 0xfffffffbu;
        u32 t7 = *(u32*)((u32)t5 + (s32)(248));
        t7 = (u32)(t7 & t6);
        *(volatile u32*)((u32)t5 + (s32)(248)) = t7;
    }
    a0 = *(u32*)((u32)a0 + (s32)(21364));
    if (a0 != 0u) {
        u32 t6 = 0xfffffffbu;
        u32 t7 = *(u32*)((u32)a0 + (s32)(248));
        t7 = (u32)(t7 & t6);
        *(volatile u32*)((u32)a0 + (s32)(248)) = t7;
    }
}

extern u8 D_003a99f0;

void func_00148a30(u32 a0) {
    *(volatile u32*)((u32)a0 + (s32)(21372)) = 0u;
    u32 t7 = (u32)&D_003a99f0;
    s32 t6 = 255;
L0:
    *(volatile u32*)((u32)t7 + (s32)(0)) = 0u;
    t6 = (s32)(t6 - 1);
    if (t6 >= 0) {
        t7 = (u32)((u32)t7 + 4);
        goto L0;
    }
}

extern "C" u32 func_00108698(...);
extern u8 D_00457480;

void func_00149150(u32 a0, u32 a1) {
    u32 t7 = 0xffffu;
    if (a1 != t7) {
        return;
    }
    t7 = 1u;
    if (a0 != t7) {
        return;
    }
    u32 t0 = (u32)&D_00457480;
    a0 = t0;
    func_00108698(a0);
}

extern u8 D_0036b028;

u32 func_00149fa8(u32 a0);  // 00149fa8: moved to src/anon/unit_00149fa8.cpp

extern "C" u32 func_00102818(...);
extern u8 D_0014a0a0;
extern u8 D_0032b96c;

void duplicate_unplaced_0014a138(u32 a0) {
    u32 s0 = a0;
    u32 a2 = (u32)(0x0004u << 16);
    u32 a3 = (u32)&D_0014a0a0;
    u32 v0 = func_00102818(
        *(volatile u32*)((u32)&D_0032b96c + (s32)(0)),
        0u,
        (u32)(a2 | 0x93e0u),
        a3,
        0x1000u
    );
    s0 = (u32)(s0 & 0xffu);
    *(volatile u8*)((u32)v0 + (s32)(4)) = (u8)s0;
}

extern "C" u32 func_00102c18(...);
extern "C" u32 func_0013a6d0(...);
extern "C" u32 func_0013a9e8(...);
extern "C" u32 func_0014ae10(...);
extern "C" u32 func_002bea00(...);
extern u8 D_0014a830;

void duplicate_unplaced_0014a188() {
    func_0013a6d0();
    u32 v0 = func_00102c18(0u, 0x000124f8u, (u32)&D_0014a830);
    *(u8*)((u32)v0 + (s32)(4)) = (u8)0u;
    func_0014ae10();
    func_0013a9e8(0x1u);
    func_002bea00();
}

extern u8 D_00349268;

u32 func_0014a1f0();  // 0014a1f0: moved to src/anon/unit_00149fa8.cpp

extern "C" u32 func_00102788(...);
extern "C" u32 func_0014a248(...);  // zero_global_byte_b
extern u8 D_0014a310;
extern u8 D_0032b91c;
extern u8 D_0034926a;

u32 duplicate_unplaced_0014a470() {
    D_0034926a = (u8)0u;
    func_0014a248();  // zero_global_byte_b
    u32 a0 = *(u32*)((u32)&D_0032b91c + (s32)(0));
    return func_00102788(a0, 0u, 0x0001c908u, (u32)&D_0014a310);
}

extern u8 D_00349390;
extern u8 D_00349394;
extern u8 D_00349398;

void func_0014a7b8(u32 a0, u32 a1, u32 a2, f32 a3);  // 0014a7b8: moved to src/anon/unit_00149fa8.cpp

extern "C" u32 func_0014a7b8(...);
extern u8 D_0034939c;

void func_0014a7f8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0014a7f8: moved to src/anon/unit_00149fa8.cpp

extern "C" u32 func_0014a9a0(...);

u32 duplicate_unplaced_0014aa58(u32 a0, u32 a1, u32 a2) {
    a2 = (u32)(a2 & 0x00ffu);
    *(u8*)((u32)a0 + (s32)(244)) = (u8)a2;
    *(u32*)((u32)a0 + (s32)(252)) = 3u;
    return ((u32(*)())func_0014a9a0)();
}

extern "C" u32 func_0014aaa8(...);
extern u8 D_003493a0;
extern u8 D_00349b10;

void func_0014ac18();  // 0x0014ac18: definition moved into src/harata/libdk/fade.cpp

extern "C" u32 func_00102788(...);
extern "C" u32 func_0014acf8(...);
extern u8 D_0014ac18;
extern u8 D_0032b91c;

u32 duplicate_unplaced_0014ad20() {
    func_0014acf8();
    u32 a0 = *(u32*)((u32)&D_0032b91c + (s32)(0));
    return func_00102788(a0, 0u, 0x00050910u, (u32)&D_0014ac18);
}

void duplicate_unplaced_0014b220(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    a1 = (u32)(a1 & 0xffu);
    a2 = (u32)(a2 & 0xffu);
    a3 = (u32)(a3 & 0xffu);
    *(u8*)((u32)a0 + (s32)(16)) = (u8)a1;
    a4 = (u32)(a4 & 0xffu);
    *(u8*)((u32)a0 + (s32)(17)) = (u8)a2;
    *(u8*)((u32)a0 + (s32)(18)) = (u8)a3;
    *(u8*)((u32)a0 + (s32)(19)) = (u8)a4;
}

void duplicate_unplaced_0014b5e8(u32 a0, u64 a1, u64 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    *(volatile u64*)((u32)a0 + (s32)(208)) = a1;
    *(volatile u64*)((u32)a0 + (s32)(224)) = a2;
}

void duplicate_unplaced_0014bb00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    a1 = (u32)((s32)(a1 << 16) >> 16);
    a2 = (u32)((s32)(a2 << 16) >> 16);
    a3 = (u32)(a3 & 0xffffu);
    *(u16*)((u32)a0 + (s32)(320)) = (u16)a1;
    a4 = (u32)(a4 & 0xffffu);
    *(u16*)((u32)a0 + (s32)(322)) = (u16)a2;
    *(u16*)((u32)a0 + (s32)(324)) = (u16)a3;
    *(u16*)((u32)a0 + (s32)(326)) = (u16)a4;
}

extern "C" u32 func_00102788(...);
extern "C" u32 func_0014c8e0(...);
extern u8 D_0014c7f0;
extern u8 D_0032b91c;

u32 duplicate_unplaced_0014c908() {
    func_0014c8e0();
    u32 a0 = *(u32*)((u32)&D_0032b91c + (s32)(0));
    return func_00102788(a0, 0u, 1u, (u32)&D_0014c7f0);
}

extern "C" u32 func_001058e8(...);

void func_0014cb58() {
    u32 v0 = func_001058e8();
    *(volatile u32*)((u32)v0 + (s32)(9284)) = 0u;
    u32 t7 = (u32)((s32)v0 + (9284));
    s32 t6 = 18;
    *(volatile u32*)((u32)v0 + (s32)(9288)) = 0u;
    do {
        *(u32*)((u32)t7 + (s32)(8)) = 0u;
        t6 = (s32)(t6 + (-1));
        t7 = (u32)((s32)t7 + (4));
    } while (t6 >= 0);
}

extern "C" u32 func_00102788(...);
extern "C" u32 func_0014f030(...);  // obj_set_lerp_params
extern u8 D_0014cd98;
extern u8 D_0032b91c;
extern u8 D_004574b8;

u32 duplicate_unplaced_0014cde0() {
    func_0014f030((u32)&D_004574b8);  // obj_set_lerp_params
    u32 a0 = *(u32*)((u32)&D_0032b91c + (s32)(0));
    return func_00102788(a0, 0u, 0x000c3500u, (u32)&D_0014cd98);
}

extern "C" u32 func_0014ce20(...);
extern "C" u32 func_0014ce30(...);
extern "C" u32 func_0014ce60(...);
extern u8 D_00349e08;

void duplicate_unplaced_0014cfc8() {
    func_0014ce20(1u);
    func_0014ce30(1u);
    func_0014ce60();
    u32 t7 = (u32)(0x35u << 16);
    u32 t6 = (u32)(0x35u << 16);
    *(u32*)((u32)t7 + (s32)(-25084)) = 0u;
    *(u32*)((u32)&D_00349e08 + (s32)(0)) = 0u;
}

extern "C" u32 func_003054b0(...);
extern "C" u32 func_00305510(...);
extern "C" u32 func_00305620(...);
extern u8 D_00349e28;

extern "C" u32 func_00305660(...);
extern u8 D_00349e7c;

// 0014d430: moved to src/anon/unit_0014d298.cpp

extern "C" u32 func_00305650(...);
extern "C" u32 func_003056a0(...);
extern u8 D_00349e28;

// 0014d4e8: moved to src/anon/unit_0014d298.cpp

extern "C" u32 func_0014d948(...);
extern "C" u32 func_0014da40(...);

// 0014dd18: moved to src/anon/unit_0014d680.cpp

void duplicate_unplaced_0014dd60(u32 a0, u32 a1, u32 a2, u32 a3) {
    a1 = (u32)(a1 & 0xffu);
    a2 = (u32)(a2 & 0xffu);
    a3 = (u32)(a3 & 0xffu);
    *(u8*)((u32)a0 + (s32)(470)) = (u8)a1;
    *(u8*)((u32)a0 + (s32)(471)) = (u8)a2;
    *(u8*)((u32)a0 + (s32)(472)) = (u8)a3;
}

extern "C" u32 func_00140dc0(...);
extern "C" u32 func_00140dd0(...);
extern "C" u32 func_00140df0(...);

extern u8 D_0034a400;
extern u8 D_0034a408;

void func_0014ecb8() {
    *(u32*)((u32)&D_0034a400 + (s32)(0)) = 0u;
    u32 t6 = (u32)&D_0034a408;
    s32 t7 = 7;
    do {
        *(u32*)((u32)t6 + (s32)(0)) = (u32)-1;
        t7 = (s32)(t7 + (-1));
        t6 = (u32)((s32)t6 + (4));
    } while (t7 >= 0);
}

u32 func_0014f068(u32);

u32 func_0014f0b0(u32 a0) {
    f32 f1 = *(volatile f32*)((u32)a0 + (s32)(0));
    f32 f0 = *(volatile f32*)((u32)a0 + (s32)(4));
    f0 = (f32)(f0 + f0);
    f1 = (f32)(f1 + f0);
    *(volatile f32*)((u32)a0 + (s32)(0)) = f1;
    u32 (*fp)(u32) = func_0014f068;
    u32 v0 = fp(a0);
    return v0;
}

u32 func_0014f068(u32);

u32 func_0014f0e0(u32 a0) {
    f32 f1 = *(volatile f32*)((u32)a0 + (s32)(0));
    u32 t7 = (u32)(0x0035u << 16);
    f32 f2 = *(volatile f32*)((u32)t7 + (s32)(-25072));
    f32 f0 = *(volatile f32*)((u32)a0 + (s32)(4));
    f0 = (f32)(f0 * f2);
    f1 = (f32)(f1 + f0);
    *(volatile f32*)((u32)a0 + (s32)(0)) = f1;
    u32 (*fp)(u32) = func_0014f068;
    u32 v0 = fp(a0);
    return v0;
}

extern "C" u32 func_0013e808(...);
extern "C" u32 func_00153100(...);
extern "C" u32 func_0015b778(...);

void func_0014f148() {
    func_00153100();
    func_001380e8();
    func_0013e808();
    func_0015b778();
}

extern "C" u32 func_00150dc0(...);
extern u8 D_0034a428;

u32 duplicate_unplaced_0014f688(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    return func_00150dc0(*(volatile u32*)((u32)&D_0034a428 + (s32)(0)), a0, a1, a2, a3, a4);
}

extern "C" u32 func_00139d78(...);
extern "C" u32 func_00151528(...);
extern u8 D_0034a428;

void func_0014f6c8() {
    if (func_00139d78(*(volatile u32*)((u32)&D_0034a428 + (s32)(0))) == 0u) {
        return;
    }
    func_00151528(*(volatile u32*)((u32)&D_0034a428 + (s32)(0)));
}

extern "C" u32 func_00139d78(...);
extern "C" u32 func_001514b0(...);
extern u8 D_0034a428;

void func_0014f708() {
    if (func_00139d78(*(volatile u32*)((u32)&D_0034a428 + (s32)(0))) == 0u) {
        return;
    }
    func_001514b0(*(volatile u32*)((u32)&D_0034a428 + (s32)(0)));
}

extern "C" u32 func_00139d78(...);
extern "C" u32 func_001515b0(...);
extern u8 D_0034a428;

void func_0014f748() {
    if (func_00139d78(*(volatile u32*)((u32)&D_0034a428 + (s32)(0))) == 0u) {
        return;
    }
    func_001515b0(*(volatile u32*)((u32)&D_0034a428 + (s32)(0)));
}

extern "C" u32 func_00139d78(...);
extern "C" u32 func_001515b0(...);

void func_0014f890(u32 a0) {
    if (func_00139d78(a0) == 0u) {
        return;
    }
    func_001515b0(a0);
}

extern u8 D_0034a458;

u32 func_0014fbf8(u32 a0) {  // sum_table_shorts
    s32 t7 = *(s32*)((u32)a0 + (s32)(24));
    if (t7 <= 0) {
        return 0u;
    }
    u32 t6 = *(u32*)((u32)a0 + (s32)(28));
    s32 t5 = t7;
    u32 v0 = 0u;
    t6 = (u32)(t6 << 1);
    u32 p = (u32)((u32)&D_0034a458 + t6);
    do {
        s32 t = (s32)*(s16*)((u32)p + (s32)(0));
        t5 = (s32)(t5 + (-1));
        v0 = (u32)(v0 + t);
        p = (u32)((s32)p + (6));
    } while (t5 != 0);
    return v0;
}

extern "C" u32 func_00150be8(...);

u32 duplicate_unplaced_001514e8(u32 a0) {
    func_00138c10((u32)((s32)a0 + (496)), 3u);
    func_00138c10((u32)((s32)a0 + (904)), 9u);
    return func_00150be8(a0);
}

f32 func_00151690(u32 a0) {  // scale_ratio_2888_2880
    f32 f1 = *(volatile f32*)((u32)a0 + (s32)(2880));
    f32 f0 = *(volatile f32*)((u32)a0 + (s32)(2888));
    return (f32)(f0 / f1);
}

extern "C" u32 func_00151d48(...);

u32 duplicate_unplaced_001520c0(u32 a0, u32 a1) {
    *(volatile u32*)((u32)a0 + (s32)(2892)) = (u32)(*(volatile u32*)((u32)a0 + (s32)(2892)) + a1);
    func_00138c10((u32)((s32)a0 + (48)), 17u);
    return func_00151d48(a0);
}

extern "C" u32 func_0023ca70(...);
extern "C" u32 func_0023f1b0(...);

u32 func_00153e28(f32 a0, f32 a1) {
    f32 f20 = a0;
    f32 f21 = a1;
    u32 v0 = ((u32(*)(f32))(u32)func_0023f1b0)(a0);
    return ((u32(*)(u32,s32,s32))(u32)func_0023ca70)(v0, (s32)f20, (s32)f21);
}

extern "C" u32 func_00138840(...);

// 00154330: moved to src/anon/unit_00153ea0.cpp
void func_00154330(u32 a0);

extern "C" u32 func_00138988(...);
extern "C" u32 func_00236788(...);  // to_236830

// 00154358: moved to src/anon/unit_00153ea0.cpp
void func_00154358(u32 a0);

extern "C" u32 func_00154288(...);  // state_index_0_1_2

// 00154408: moved to src/anon/unit_00153ea0.cpp
void func_00154408(u32 a0, u32 a1);

// 00154910: moved to src/anon/unit_00153ea0.cpp
u32 func_00154910(u32 a0);

// 00154930: moved to src/anon/unit_00153ea0.cpp
u32 func_00154930(u32 a0);

extern "C" u32 func_0013d810(...);
extern "C" u32 func_00154450(...);

u32 duplicate_unplaced_00154b40(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 v0 = func_0013d810(a0, a1, a2);
    return func_00154450(v0, s0, s1);
}

extern "C" u32 func_00154ee8(...);  // field24_state_code
extern "C" u32 func_001581f8(...);

u32 duplicate_unplaced_00155528(u32 a0) {
    u32 s0 = a0;
    func_001581f8(a0);
    u32 s1 = (u32)((s32)s0 + (916));
    u32 v0 = func_00154ee8(s0);  // field24_state_code
    return func_00138c10(s1, v0);
}

// 00156010: moved to src/anon/unit_00153ea0.cpp
u32 func_00156010(u32 a0);

extern "C" u32 func_00155f40(...);
extern "C" u32 func_00156408(...);

u32 duplicate_unplaced_00157068(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00155f40(a0);
    func_00138c10((u32)((s32)s0 + (11648)), v0);
    return func_00156408(s0);
}

extern "C" u32 func_001572e8(...);

// 001574a0: moved to src/anon/unit_00153ea0.cpp
void func_001574a0(u32 a0);

extern "C" u32 func_00242b58(...) asm("_ZN2Tz6Config12isCameraAutoEv");

u32 duplicate_unplaced_001585a0(u32 a0) {
    u32 s0 = 1u;
    u64 t7 = *(u64*)(u32)a0;
    u64 t6 = 1ull;
    t6 = (u64)(t6 << 32);
    t7 = (u64)(t7 & t6);
    if (t7 == 0ull) {
        s0 = 0u;
    }
    u32 v0 = func_00242b58();
    if (v0 == 0u) {
        s0 = (u32)(s0 < 1u);
    }
    return s0;
}

extern "C" u32 func_00140dc0(...);
extern "C" u32 func_00140dd0(...);
extern "C" u32 func_00140df0(...);

extern "C" u32 func_00140dc0(...);
extern "C" u32 func_00140dd0(...);
extern "C" u32 func_00140df0(...);

// 00158f90: moved to src/harata/libdk/bookcamera.cpp

extern "C" u32 func_00140dc0(...);
extern "C" u32 func_00140dd0(...);
extern "C" u32 func_00140df0(...);

// 001591a0 dk::LightCycleCamera::create: moved to src/harata/libdk/lightcyclecamera.cpp

// 001591e8: static initialiser, now made by gcc in src/harata/libdk/lightcyclecamera.cpp

extern "C" u32 func_00140df0(...);
extern u8 D_0034aa08;

void duplicate_unplaced_00159700(void) {
    *(volatile u32*)(u32)&D_0034aa08 = 0u;
    u32 v0 = func_00140df0();
    *(volatile u32*)((u32)v0 + (s32)(64)) = 5u;
}

extern "C" u32 func_0013f9e0(...);
extern "C" u32 func_00159ce0(...);

// 0015a4e0: moved to src/harata/libdk/targetcamera.cpp

extern u8 D_0034aa40;
extern u8 D_0034aa70;

void duplicate_unplaced_0015a6c8(u32 a0) {
    u32 t5 = *(volatile u32*)((u32)a0 + (s32)(0));
    u32 t4 = (u32)&D_0034aa70;
    *(volatile u32*)(u32)&D_0034aa70 = t5;
    u32 t7 = *(volatile u32*)((u32)a0 + (s32)(4));
    *(volatile u32*)((u32)t4 + (s32)(4)) = t7;
    u32 t6 = *(volatile u32*)((u32)a0 + (s32)(8));
    *(volatile u32*)((u32)t4 + (s32)(8)) = t6;
    u32 t7b = *(volatile u32*)((u32)a0 + (s32)(12));
    u32 one = 1u;
    *(volatile u32*)((u32)t4 + (s32)(12)) = t7b;
    u32 t5b = *(volatile u32*)((u32)a0 + (s32)(16));
    *(volatile u8*)(u32)&D_0034aa40 = (u8)one;
    *(volatile u32*)((u32)t4 + (s32)(16)) = t5b;
}

extern "C" u32 func_0016c3a8(...);
extern u32 D_0034aa90;
extern u8 D_0034aa94;

void duplicate_unplaced_0015a8a0(void) {
    u32 a0 = *(volatile u32*)(u32)&D_0034aa90;
    u32 v0 = func_0016c3a8(a0, 64u);
    *(volatile u32*)(u32)&D_0034aa94 = v0;
}

extern "C" u32 func_001390c0(...);
extern "C" u32 func_00139538(...);

void func_0015aef0(u32 a0);  // 0x0015aef0: definition moved into src/anon/unit_0015a810.cpp

extern "C" u32 func_0015b7f8(...);
extern "C" u32 func_0015bab8(...);

void duplicate_unplaced_0015b7c0(u32 a0, u32 a1) {
    *(volatile u32*)((u32)a0 + (s32)(2928)) = a1;
    *(volatile u32*)((u32)a0 + (s32)(2932)) = 16u;
    u32 s0 = a0;
    func_0015b7f8(a0);
    func_0015bab8(s0);
}

extern u8 D_0034ae80;

void func_0015c1b0(void);  // 0x0015c1b0: definition moved into src/anon/unit_0015bab8.cpp

extern u8 D_0034ae80;

void func_0015c210(void);  // 0x0015c210: definition moved into src/anon/unit_0015bab8.cpp

extern "C" u32 func_0014e140(...);
extern "C" u32 func_0015cb48(...);

void func_0015c4b8(void);  // 0x0015c4b8: definition moved into src/anon/unit_0015bab8.cpp

extern u8 D_004f36a8;

void duplicate_unplaced_0015cb18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t5 = (u32)&D_004f36a8;
    *(volatile u8*)((u32)a0 + (s32)(0)) = *(volatile u8*)((u32)t5 + (s32)(0));
    *(volatile u8*)((u32)a1 + (s32)(0)) = *(volatile u8*)((u32)t5 + (s32)(1));
    *(volatile u8*)((u32)a2 + (s32)(0)) = *(volatile u8*)((u32)t5 + (s32)(2));
    *(volatile u8*)((u32)a3 + (s32)(0)) = *(volatile u8*)((u32)t5 + (s32)(3));
}

extern u8 D_004f3700;

void duplicate_unplaced_0015cb78(u32 a0, u32 a1) {
    u32 p = (u32)((u32)&D_004f3700 + (u32)(a1 << 2));
    *(volatile u8*)((u32)a0 + (s32)(0)) = *(volatile u8*)((u32)p + (s32)(4));
    a0 = (u32)((s32)a0 + (1));
    *(volatile u8*)((u32)a0 + (s32)(0)) = *(volatile u8*)((u32)p + (s32)(5));
    a0 = (u32)((s32)a0 + (1));
    *(volatile u8*)((u32)a0 + (s32)(0)) = *(volatile u8*)((u32)p + (s32)(6));
    *(volatile u8*)((u32)a0 + (s32)(1)) = *(volatile u8*)((u32)p + (s32)(7));
}

extern "C" u32 func_001069b8(...);  // swap_global_word
u32 func_00141010(f32);
extern "C" u32 func_0015ce90(...);  // zero_global_byte_g
extern "C" u32 func_0015cef0(...);

// 0015cdb0 dk::EventCamera::start: moved to src/anon/unit_0015cdb0.cpp

extern "C" u32 func_0015de98(...);
extern "C" u32 func_0015e018(...);
extern "C" u32 func_0015e038(...);
extern "C" u32 func_00194908(...);

// 0015df68: moved to src/anon/unit_0015d828.cpp

// D_0034b244 declared as Obj0015de58* in declaration block above

// 0015df98: moved to src/anon/unit_0015d828.cpp

extern u8 D_0034b240;

// 0015dfd8: moved to src/anon/unit_0015d828.cpp

extern "C" u32 func_0011e9a8(...);
extern "C" u32 func_00143318(...);
extern "C" u32 func_00161248(...);

// 0015ef50: moved to src/harata/libdk/map.cpp

extern u8 D_0034c710;

// 0015f718: moved to src/harata/libdk/map_effect.cpp

extern "C" u32 func_00102788(...);
extern u8 D_001609e0;
extern u8 D_00160a90;
extern u8 D_004f3b30;

void duplicate_unplaced_00160ac0(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 a2 = a1;
    u32 a3 = (u32)&D_001609e0;
    u32 v0 = func_00102788(*(volatile u32*)(u32)&D_004f3b30, 0u, a2, a3);
    *(volatile u32*)((u32)v0 + (s32)(4)) = s0;
    *(volatile u32*)((u32)v0 + (s32)(48)) = (u32)&D_00160a90;
}

extern "C" u32 func_00160d38(...);
extern "C" u32 func_00161030(...);

// 00160fd0: moved to src/harata/libdk/bgobj.cpp

extern "C" u32 func_00160d28(...);
extern "C" u32 func_00161030(...);

// 00161000: moved to src/harata/libdk/bgobj.cpp

extern "C" u32 func_00144450(...);
extern "C" u32 func_001616d8(...);

void duplicate_unplaced_001614e8(u32 a0, u32 a1) {
    *(volatile u32*)((u32)a0 + (s32)(68)) = a1;
    u32 s0 = a0;
    *(volatile u32*)((u32)s0 + (s32)(64)) = 0u;
    *(volatile u32*)((u32)s0 + (s32)(72)) = 0u;
    *(volatile u32*)((u32)s0 + (s32)(76)) = 0u;
    *(volatile u32*)((u32)s0 + (s32)(80)) = 0u;
    func_00144450((u32)((s32)s0 + (84)));
    func_001616d8(s0);
}

extern "C" u32 func_00102688(...);
extern "C" u32 func_00102c80(...);

void duplicate_unplaced_001619e8() {
    u32 v0 = func_00102c80();
    func_00102688(*(volatile u32*)((u32)v0 + (s32)(4)), 3u, 3u);
}

extern "C" u32 func_00102688(...);
extern "C" u32 func_00102c80(...);

void duplicate_unplaced_001623b0() {
    u32 v0 = func_00102c80();
    func_00102688(*(volatile u32*)((u32)v0 + (s32)(4)), 5u, 5u);
}

void func_00162a20(u32 a0, u32 a1) {
    *(volatile f32*)((u32)a0 + (s32)(0)) = *(volatile f32*)((u32)a1 + (s32)(0));
    *(volatile f32*)((u32)a0 + (s32)(4)) = *(volatile f32*)((u32)a1 + (s32)(4));
    *(volatile f32*)((u32)a0 + (s32)(8)) = *(volatile f32*)((u32)a1 + (s32)(8));
    *(volatile f32*)((u32)a0 + (s32)(16)) = *(volatile f32*)((u32)a1 + (s32)(12));
    *(volatile f32*)((u32)a0 + (s32)(20)) = *(volatile f32*)((u32)a1 + (s32)(16));
    *(volatile f32*)((u32)a0 + (s32)(24)) = *(volatile f32*)((u32)a1 + (s32)(20));
}

extern "C" u32 func_0017a718(...);
extern "C" u32 func_0019ba60(...);
extern u8 D_0034e948;

// 0017a798: moved to src/yasui/libys/player.cpp

u32 func_001667d0(u32 a0);  // 0x001667d0: definition moved into src/anon/unit_001664c0.cpp

extern "C" u32 func_001666a0(...);  // zero_fields_0_4_6_8

void duplicate_unplaced_001668f8(u32 a0) {
    u32 s0 = a0;
    func_001666a0(a0);  // zero_fields_0_4_6_8
    *(u16*)((u32)s0 + (s32)(12)) = (u16)0u;
    *(volatile u8*)((u32)s0 + (s32)(14)) = (u8)1u;
    *(u16*)((u32)s0 + (s32)(10)) = (u16)0u;
}

extern "C" u32 func_001666a0(...);  // zero_fields_0_4_6_8

void duplicate_unplaced_00166930(u32 a0) {
    u32 s0 = a0;
    func_001666a0(a0);  // zero_fields_0_4_6_8
    *(u16*)((u32)s0 + (s32)(12)) = (u16)0u;
    *(volatile u8*)((u32)s0 + (s32)(14)) = (u8)1u;
    *(u16*)((u32)s0 + (s32)(10)) = (u16)0u;
}

f32 func_00166d10(s32 a0, s32 a1);  // 0x00166d10: definition moved into src/anon/unit_001664c0.cpp

extern "C" u32 func_00166d10(...);

f32 func_00166d38(u32 a0);  // 0x00166d38: definition moved into src/anon/unit_001664c0.cpp

extern "C" u32 func_00166d10(...);

f32 func_00166d70(u32 a0);  // 0x00166d70: definition moved into src/anon/unit_001664c0.cpp

extern "C" u32 func_00166da8(...);
extern "C" u32 func_00167218(...);
extern u8 D_004f4240;

u32 func_00167228(u32 a0);  // 0x00167228: definition moved into src/anon/unit_001664c0.cpp

extern "C" u32 func_002f65a8(...);
extern u8 D_0034d7f0;

// 00167c90: moved to src/anon/unit_00167358.cpp

extern "C" u32 func_00167658(...);
extern "C" u32 func_00167cd0(...);

u64 duplicate_unplaced_00167e28(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = 0u, r14, r15, r16;
    r14 = (u32)-2;
    r15 = *(u32*)((u32)r4 + (s32)(72));
    r16 = r4;
    r15 = (u32)(r15 & r14);
    *(u32*)((u32)r4 + (s32)(72)) = r15;
    func_00167658(r4, r5);
    r4 = r16;
    u64 q = func_00167cd0(r4);
    *(u64*)((u32)r16 + (s32)(0)) = q;
    return q;
}

extern "C" u32 func_001ae0a0(...);
extern "C" u32 func_003058a0(...);


extern "C" u32 func_001682b8(...);
extern "C" u32 func_00168be8(...);

extern "C" u32 func_001ae4b8(...);

// 00168370: moved to src/yasui/libys/file.cpp

extern u8 D_0034d840;

// 00168a30: moved to src/yasui/libys/file.cpp

void func_0016a2b0(u32 a0) {  // clear_15_words_at1976
    u32 t7 = (u32)((s32)0u + (15));
    a0 = (u32)((s32)a0 + (1976));
    do {
        *(u32*)((u32)a0 + (s32)(0)) = 0u;
        t7 = (u32)((s32)t7 + (-1));
        a0 = (u32)((s32)a0 + (4));
    } while ((s32)t7 >= 0);
}

void func_0016a2e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(2040));
    t7 = (u32)(t7 & 0x0040u);
    u32 s0 = a0;
    if (t7 == 0u) {
        u32 obj = *(u32*)((u32)a0 + (s32)(0));
        u32 fn = *(u32*)((u32)obj + (s32)(28));
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))fn)(a0,a1,a2,a3,a4,a5,a6,a7);
        t7 = *(u32*)((u32)s0 + (s32)(2040));
        t7 = (u32)(t7 | 0x0040u);
        *(u32*)((u32)s0 + (s32)(2040)) = t7;
    }
}

extern "C" u32 func_0016cd48(...);
extern "C" u32 func_00187ca0(...);

void func_0016a950(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)((u32)a0 + (s32)(1156));
    if (p != 0u) {
        if (func_0016cd48(p, 0u) == 0u) {
            func_00187ca0((u32)((s32)s0 + (768)));
            return;
        }
    }
}

extern "C" u32 func_001de168(...);  // scan_list_by_half

u32 func_0016abf8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t0 = a3;
    a3 = 1u;
    u32 p = *(u32*)((u32)a0 + (s32)(128));
    if (p == 0u) {
        return 0u;
    }
    a0 = (u32)((s32)a0 + (128));
    return func_001de168(a0, a1, a2, a3, t0, 0u);  // scan_list_by_half
}

f32 func_0016ae58(u32);

void func_0016aeb8(u32 a0) {
    u32 s0 = a0;
    f32 f0 = func_0016ae58(a0);
    u32 t7 = *(u32*)((u32)s0 + (s32)(2040));
    u32 t6 = (u32)((s32)0u + (-9));
    *(f32*)((u32)s0 + (s32)(1644)) = f0;
    t7 = (u32)(t7 & t6);
    *(u32*)((u32)s0 + (s32)(2040)) = t7;
}

extern "C" u32 func_0016af58(...);
f32 func_002f8ad0(f32, f32);

void func_0016afe0(u32 a0) {
    struct {
        f32 f0;
        u32 pad;
        f32 f1;
    } sp;
    func_0016af58((u32)&sp, a0);
    func_002f8ad0(sp.f0, sp.f1);
}

extern "C" u32 func_0016cce8(...);

void func_0016bae8(u32 a0, u32 a1, u32 a2, u32 a3) {
    struct {
        u32 x;
        u32 y;
        u32 z;
    } sp;
    u32 t7 = *(u32*)((u32)a0 + (s32)(1156));
    if (t7 != 0u) {
        sp.x = a1;
        sp.y = a2;
        sp.z = a3;
        func_0016cce8(t7, 11u, (u32)&sp, 3u, 0u);
    }
}

extern "C" u32 func_0017aab8(...);

void duplicate_unplaced_0016bd10(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 v0 = func_0017aab8(a1);
    u32 t6 = *(u32*)((u32)v0 + (s32)(0));
    u32 s0 = v0;
    u32 t7 = *(u32*)((u32)t6 + (s32)(0));
    ((void(*)(u32,u32))t7)(v0, s1);
    *(u32*)((u32)s1 + (s32)(12)) = s0;
}

extern "C" u32 func_0016c460(...);


extern "C" u32 func_0016cce8(...);

void func_0016c698(u32 a0, u32 a1, u32 a2) {
    struct {
        u32 x;
        u32 y;
        u32 z;
    } sp;
    u32 t7 = *(u32*)((u32)a0 + (s32)(1156));
    if (t7 != 0u) {
        sp.x = a0;
        sp.y = a1;
        sp.z = a2;
        func_0016cce8(t7, (u32)((s32)0u + (27)), (u32)&sp, 3u, 0u);
    }
}

// 0016ce90: moved to src/anon/unit_0016c770.cpp

extern "C" u32 func_0016cf00(...);

// 0016cfa0: moved to src/anon/unit_0016c770.cpp

extern u8 D_004f6288;

// 0016d1a0: moved to src/anon/unit_0016c770.cpp

// 0016d1f0: moved to src/anon/unit_0016c770.cpp

f32 fabsf(f32);  // fabsf

// 0016d310: moved to src/anon/unit_0016d2e0.cpp

f32 func_002f8ad0(f32, f32);

// 0016d728: moved to src/anon/unit_0016d2e0.cpp

extern "C" u32 func_001dc8c8(...);
extern "C" u32 func_001dc978(...);

// 0016e338: moved to src/anon/unit_0016d2e0.cpp

extern "C" u32 func_00188958(...);

void duplicate_unplaced_0016e688(u32 a0) {
    u32 a1 = *(u32*)((u32)a0 + (s32)(4));
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a0 = t7;
    func_00188958(a0, a1);
}

extern "C" u32 func_00188b68(...);

void duplicate_unplaced_0016e718(u32 a0) {
    u32 a2 = *(u32*)((u32)a0 + (s32)(8));
    u32 a1 = *(u32*)((u32)a0 + (s32)(4));
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a2 = (u32)(0u < a2);
    a0 = t7;
    func_00188b68(a0, a1, a2);
}

extern "C" u32 func_001a3188(...);


extern u8 D_0034d8a8;

// 0016e858: moved to src/anon/unit_0016d2e0.cpp

extern u8 D_004f63a0;
extern u32 D_004f63a8;

void duplicate_unplaced_0016f7b0(void) {
    u32* t5 = &D_004f63a8;
    D_004f63a8 = 0u;
    D_004f63a0 = 0u;
    t5[1] = 0u;
}

extern u8 D_0034dc98;

void duplicate_unplaced_0016fb00(u32 a0) {
    u32 a1 = a0;
    u32 a0x = *(u32*)((u32)&D_0034dc98 + (s32)(0));
    u32 t6 = *(u32*)((u32)a0x + (s32)(0));
    u32 t7 = *(u32*)((u32)t6 + (s32)(4));
    ((void(*)(u32,u32))t7)(a0x, a1);
}

extern "C" u32 func_001700e8(...);
extern u8 D_0034dca0;

void func_00170a50(void);  // 0x00170a50: definition moved into src/anon/unit_0016e8f8.cpp

extern u8 D_0034dca0;

void func_00170e58(void);  // 0x00170e58: definition moved into src/anon/unit_0016e8f8.cpp

void duplicate_unplaced_00171348(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a0 = *(u32*)((u32)t7 + (s32)(4));
    u32 t6 = *(u32*)((u32)a0 + (s32)(0));
    u32 t7f = *(u32*)((u32)t6 + (s32)(68));
    ((void(*)(u32))(u32)t7f)(a0);
}

void duplicate_unplaced_00171378(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a0 = *(u32*)((u32)t7 + (s32)(4));
    u32 t6 = *(u32*)((u32)a0 + (s32)(0));
    u32 t7f = *(u32*)((u32)t6 + (s32)(72));
    ((void(*)(u32))(u32)t7f)(a0);
}

void duplicate_unplaced_00171810(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 a1 = *(u32*)((u32)a0 + (s32)(4));
    u32 t6 = *(u32*)((u32)t7 + (s32)(4));
    u32 a2 = *(u32*)((u32)a0 + (s32)(8));
    u32 t5 = *(u32*)((u32)t6 + (s32)(0));
    u32 t7f = *(u32*)((u32)t5 + (s32)(84));
    ((void(*)(u32,u32,u32))(u32)t7f)(t6,a1,a2);
}

void duplicate_unplaced_00171e58(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a0 = *(u32*)((u32)t7 + (s32)(4));
    u32 t6 = *(u32*)((u32)a0 + (s32)(0));
    u32 t7f = *(u32*)((u32)t6 + (s32)(32));
    ((void(*)())(u32)t7f)();
}

extern "C" u32 func_0016bda8(...);
extern "C" u32 func_001c7d90(...);

void func_00171f20(u32 a0);  // 0x00171f20: definition moved into src/anon/unit_00171e58.cpp

extern "C" u32 func_0016bda8(...);
extern "C" u32 func_001d2930(...);

void func_00171f68(u32 a0);  // 0x00171f68: definition moved into src/anon/unit_00171e58.cpp

void duplicate_unplaced_001721d8(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 a2 = *(u32*)((u32)a0 + (s32)(4));
    u32 a1 = *(u32*)((u32)t7 + (s32)(4));
    a0 = *(u32*)((u32)a1 + (s32)(12));
    u32 t6 = *(u32*)((u32)a0 + (s32)(0));
    u32 t7f = *(u32*)((u32)t6 + (s32)(8));
    ((void(*)(u32,u32,u32))(u32)t7f)(a0,a1,a2);
}

extern "C" u32 func_0016bd60(...);
extern "C" u32 func_001ba028(...);  // list_contains_ptr

void duplicate_unplaced_001723d0(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    func_001ba028(*(u32*)((u32)t7 + (s32)(4)));  // list_contains_ptr
    t7 = *(u32*)((u32)s0 + (s32)(0));
    u32 a1 = 0u;
    u32 t6 = *(u32*)((u32)t7 + (s32)(4));
    a0 = t6;
    func_0016bd60(a0, a1);
}

extern "C" u32 func_0016a020(...);
extern "C" u32 func_0016ace0(...);
extern "C" u32 func_0019afd8(...);

void func_001728e0(u32 a0);  // 0x001728e0: definition moved into src/anon/unit_00171e58.cpp

u32 duplicate_unplaced_00172ae0(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 a3 = *(u32*)((u32)a0 + (s32)(12));
    u32 a1 = *(u32*)((u32)s0 + (s32)(4));
    a0 = *(u32*)((u32)t7 + (s32)(4));
    a3 = (u32)(0u < a3);
    t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 fn = *(u32*)((u32)t7 + (s32)(120));
    u32 v0 = ((u32(*)(u32,u32,u32,u32))(u32)fn)(a0, a1, *(u32*)((u32)s0 + (s32)(8)), a3);
    *(u32*)((u32)s0 + (s32)(0)) = v0;
    return v0;
}

extern "C" u32 func_0016b740(...);

void duplicate_unplaced_00172ba8(u32 a0) {
    u32 t7 = a0;
    u32 s0 = *(u32*)((u32)t7 + (s32)(0));
    u32 v0 = func_0016b740(*(u32*)((u32)a0 + (s32)(4)));
    *(u32*)((u32)s0 + (s32)(4)) = v0;
}

extern "C" u32 func_0016b7a0(...);

void duplicate_unplaced_00172bd8(u32 a0) {
    u32 t7 = a0;
    u32 s0 = *(u32*)((u32)t7 + (s32)(0));
    u32 v0 = func_0016b7a0(*(u32*)((u32)a0 + (s32)(4)));
    *(u32*)((u32)s0 + (s32)(4)) = v0;
}

extern "C" u32 func_0016b800(...);

void duplicate_unplaced_00172c08(u32 a0) {
    u32 t7 = a0;
    u32 s0 = *(u32*)((u32)t7 + (s32)(0));
    u32 v0 = func_0016b800(*(u32*)((u32)a0 + (s32)(4)));
    *(u32*)((u32)s0 + (s32)(4)) = v0;
}

f32 func_001826e0();  // global_float_diff

void func_001730b0(u32 a0);  // 0x001730b0: definition moved into src/anon/unit_00171e58.cpp

void duplicate_unplaced_00173270(u32 a0) {
    typedef void (*M)(VObj_00173270*);
    VObj_00173270* self = *(VObj_00173270**)(u32)a0;
    M m = (M)(u32)(((u32*)(u32)self->vtbl)[8]);
    m(self);
}

extern "C" u32 func_001a7588(...);

u32 duplicate_unplaced_001732c8(u32 a0) {
    u32 s0 = a0;
    u32 a2 = *(u32*)((u32)s0 + (s32)(8));
    u32 a1 = *(u32*)((u32)s0 + (s32)(4));
    u32 a0v = *(u32*)((u32)a0 + (s32)(0));
    u32 a3 = *(u32*)((u32)s0 + (s32)(12));
    u32 v0 = func_001a7588(a0v, a1, a2, a3);
    *(u32*)((u32)s0 + (s32)(0)) = v0;
    return v0;
}

extern "C" u32 func_00143f28(...);

u32 func_00173300(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00173300: definition moved into src/anon/unit_00171e58.cpp

u32 func_001a7610(u32, u32, u32, f32, f32);

u32 func_001733b8(u32 a0);  // 0x001733b8: definition moved into src/anon/unit_00171e58.cpp

f32 func_001806f8(u32, int);

void func_00173a60(u32 a0);  // 0x00173a60: definition moved into src/anon/unit_00171e58.cpp

extern "C" u32 func_00180770(...);

void func_00173a98(u32 a0);  // 0x00173a98: definition moved into src/anon/unit_00171e58.cpp

extern "C" u32 func_00184ad0(...);

void func_00173c38(u32 a0);  // 0x00173c38: definition moved into src/anon/unit_00171e58.cpp

f32 func_0017d130(f32);  // sqrt_scaled_double

void func_00173ff8(u32 a0);  // 0x00173ff8: definition moved into src/anon/unit_00171e58.cpp

void func_001ad990(u32, f32, f32, f32);

void func_001746c8(u32 a0);  // 0x001746c8: definition moved into src/anon/unit_00171e58.cpp

void func_00191bf0(f32);

void func_001749c8(u32 a0);  // 0x001749c8: definition moved into src/anon/unit_00171e58.cpp

extern "C" u32 func_00159130(...);
extern "C" u32 func_00190128(...);
extern "C" u32 func_00190878(...);

void func_00174be8(u32 a0);  // 0x00174be8: definition moved into src/anon/unit_00171e58.cpp

extern "C" u32 func_001d2930(...);

void duplicate_unplaced_001751f8(u32 a0) {
    u32 a1 = *(u32*)((u32)a0 + (s32)(4));
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a0 = t7;
    func_001d2930(a0, a1);
}

extern f32 D_00349e10;

// 00176a68: moved to src/yasui/libys/party.cpp

extern "C" u32 func_0017df58(...);
extern u8 D_0034e948;

// 00176b20: moved to src/yasui/libys/party.cpp

extern "C" u32 func_0016a070(...);
extern "C" u32 func_00198630(...);
extern "C" u32 func_001afee8(...);

void duplicate_unplaced_00176d68(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 s1 = a0;
    u32 v0 = func_0016a070(a0, a1);
    v0 = func_001afee8(v0, s0);
    u32 a2 = 0u;
    func_00198630(s1, v0, a2);
}

extern "C" u32 func_0016a070(...);
extern "C" u32 func_001a3458(...);

// 00176e78: moved to src/yasui/libys/party.cpp

extern "C" u32 func_00185770(...);

// 001775a8: moved to src/yasui/libys/party.cpp

extern "C" u32 func_00176b20(...);

// 001776a8: moved to src/yasui/libys/party.cpp

extern "C" u32 func_00176b20(...);

// 00177710: moved to src/yasui/libys/party.cpp

extern "C" u32 func_00177860(...);
extern "C" u32 func_001a1de0(...);

// 00177870: moved to src/yasui/libys/party.cpp

extern "C" u32 func_001778c0(...);

// 00177958: moved to src/yasui/libys/party.cpp

extern "C" u32 func_001d6ba0(...);

// 00178888: moved to src/yasui/libys/player.cpp

extern "C" u32 func_00179f10(...);
extern "C" u32 func_001d6ab0(...);

u32 duplicate_unplaced_00179f80(u32 a0) {
    u32 s0 = a0;
    func_00179f10(a0);
    func_001d6ab0(*(u32*)((u32)s0 + (s32)(2876)));
    u32 t7 = *(u32*)((u32)s0 + (s32)(1164));
    a0 = s0;
    u32 t6 = *(u32*)((u32)s0 + (s32)(0));
    u32 a2 = 0u;
    u32 a1 = *(u32*)((u32)t7 + (s32)(4));
    return ((u32(*)(u32,u32,u32,u32))*(u32*)((u32)t6 + (s32)(120)))(a0, a1, a2, 0u);
}

// 0017cb48: moved to src/anon/unit_0017c400.cpp

extern "C" u32 func_0017ce10(...);
extern "C" u32 cosf(...);
extern "C" u32 sinf(...);

// 0017d0e8: moved to src/anon/unit_0017c400.cpp

extern "C" u32 func_001c9770(...);
extern u32 D_01c60528;

void duplicate_unplaced_0017dec0() {
    u32* t6 = &D_01c60528;
    D_01c60528 = 0u;
    t6[1] = 0u;
    func_001c9770();
}

extern "C" u32 func_0017e280(...);

// 0017e310: moved to src/yasui/libys/friend.cpp

extern "C" u32 func_0017df58(...);

// 0017e6d8: moved to src/yasui/libys/friend.cpp

extern "C" u32 func_0017ec28(...);
extern "C" u32 func_0017ec98(...);
extern "C" u32 func_001a97b8(...);

// 0017ec30: moved to src/yasui/libys/motion.cpp

extern "C" u32 func_0017ebc8(...);

// 0017eda8: moved to src/yasui/libys/motion.cpp

extern "C" void func_0017fd30(u32, u32) asm("_ZN2YS6MOTION4syncEPS0_");

void duplicate_unplaced_001805e8(u32 a0) {
    u32 a = *(u32*)((u32)a0 + (s32)(36));
    u32 b = *(u32*)((u32)a0 + (s32)(32));
    a = (u32)(a & (u32)-2);
    *(u32*)((u32)a0 + (s32)(40)) = 0u;
    a = (u32)(a & (u32)-3);
    b = (u32)(b & 0x7183u);
    *(u32*)((u32)a0 + (s32)(32)) = b;
    *(u32*)((u32)a0 + (s32)(36)) = a;
}

extern "C" u32 func_00189d18(...);

// 001807a0: moved to src/anon/unit_00180408.cpp

extern "C" u32 func_001892b8(...);

// 001807d0: moved to src/anon/unit_00180408.cpp

extern "C" u32 func_002bc358(...);

// 00180c38: moved to src/anon/unit_00180408.cpp

// 00180df8: moved to src/anon/unit_00180408.cpp

extern "C" u32 func_00181500(...);

// 00181858: moved to src/yasui/libys/progress.cpp

extern "C" u32 func_00181500(...);

// 001818a0: moved to src/yasui/libys/progress.cpp

extern "C" u32 func_00181500(...);

// 001818e8: moved to src/yasui/libys/progress.cpp

extern "C" u32 func_00181500(...);

extern "C" u32 func_00181500(...);

extern "C" u32 func_00181178(...);
extern u8 D_0032bb30;

u32 duplicate_unplaced_00181a90(u32 a0) {
    u32 r4 = a0, r2, r13, r14, r15;
    r4 = (u32)((s32)0u + (18504));
    r2 = ((u32(*)(u32))func_00181178)(r4);
    r4 = (u32)((s32)0u + (18505));
    r2 = ((u32(*)(u32))func_00181178)(r4);
    r14 = (u32)&D_0032bb30;
    r15 = (u32)((s32)0u + (18));
    r13 = (u32)((s32)0u + (99));
    *(u8*)((u32)r14 + (s32)(12)) = (u8)r15;
    *(u8*)((u32)r14 + (s32)(14)) = (u8)r13;
    *(u8*)((u32)r14 + (s32)(13)) = (u8)r15;
    return r2;
}

f32 func_001826e0();  // global_float_diff

// 00182690: moved to src/yasui/libys/areadata.cpp

extern u8 D_01c60540;

// 001826c8: moved to src/yasui/libys/areadata.cpp

extern "C" u32 func_00199d38(...);

// 00182910 YS::UNIT::update: moved to src/anon/unit_00182780.cpp

extern "C" u32 func_00196908(...);
extern "C" u32 func_00199dc0(...);

// 00182940 YS::UNIT::activate: moved to src/anon/unit_00182780.cpp

extern "C" u32 func_0019a048(...);

// 00182980 YS::UNIT::draw: moved to src/anon/unit_00182780.cpp

// 001842c0: moved to src/anon/unit_00183088.cpp

f32 func_001849d8(u32);

// 00184a90: moved to src/anon/unit_00183088.cpp

extern u8 D_0034ed0c;

// 00185118: moved to src/anon/unit_00183088.cpp

extern "C" u32 func_0016ad38(...);
extern "C" u32 func_00185138(...);

// 00185278: moved to src/anon/unit_00183088.cpp

void duplicate_unplaced_00185a98(u32 a0) {
    a0 = *(u32*)((u32)a0 + (s32)(2548));
    u32 t6 = *(u32*)((u32)a0 + (s32)(0));
    u32 t7 = *(u32*)((u32)t6 + (s32)(76));
    ((void(*)(u32))(u32)t7)(a0);
}

extern "C" u32 func_001c0cd8(...);

// 00185ac0: moved to src/anon/unit_001855e0.cpp

extern "C" u32 func_00186478(...);
extern "C" u32 func_00186a90(...);

// 00186548: moved to src/anon/unit_00185d10.cpp
void func_00186548(u32 a0, u32 a1, f32 f12);

extern "C" u32 func_00186590(...);
extern "C" u32 func_00186c58(...);

// 001866a0: moved to src/anon/unit_00185d10.cpp
void func_001866a0(u32 a0, u32 a1, f32 f12);

extern "C" u32 func_00186590(...);
extern "C" u32 func_00186a90(...);

// 001866f0: moved to src/anon/unit_00185d10.cpp
void func_001866f0(u32 a0, u32 a1, f32 f12);

extern "C" u32 func_001860b0(...);
extern "C" u32 func_001c1b08(...);

void duplicate_unplaced_00186948(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 s1 = a0;
    u32 v0 = func_001860b0(a0, a1);
    func_001c1b08(s1, *(u32*)((u32)s0 + (s32)(28)), v0);
}

extern "C" u32 func_0016cce8(...);

// 00186fd8: moved to src/anon/unit_00185d10.cpp
void func_00186fd8(u32 a0, u32 a1);

void func_001a1d40(u32, f32);


extern "C" u32 func_0016a5b0(...);
extern "C" u32 func_001dc920(...);
extern "C" u32 func_001dc9e0(...);

// 00187750: moved to src/anon/unit_00185d10.cpp
void func_00187750(u32 a0);

// 00187818: moved to src/anon/unit_00185d10.cpp
void func_00187818(u32 a0);

// 00187b30: moved to src/anon/unit_00185d10.cpp
u32 func_00187b30(u32 a0);

extern "C" u32 func_00187ab8(...);

// 00187b68: moved to src/anon/unit_00185d10.cpp
void func_00187b68(void);

extern "C" u32 func_00187b90(...);

// 00187f90: moved to src/anon/unit_00185d10.cpp
void func_00187f90(u32 a0);

extern "C" u32 func_001880b0(...);
extern "C" u32 func_001883d8(...);

// 00188120: moved to src/anon/unit_00185d10.cpp
void func_00188120(u32 a0, u32 a1);

extern "C" u32 func_00188340(...);
extern u8 D_01c60bc8;

void duplicate_unplaced_001883f8(u32 a0, u32 a1) {
    u32 t4 = a1;
    u32 t6 = (u32)&D_01c60bc8;
    u32 t7 = (u32)((s32)t6 + (0));
    u32 t5 = *(u32*)((u32)a0 + (s32)(136));
    *(u32*)((u32)t6 + (s32)(0)) = t5;
    *(u32*)((u32)t7 + (s32)(4)) = t4;
    func_00188340(a0, (u32)3, t7, (u32)2);
}

extern "C" u32 func_00188340(...);
extern u8 D_01c60bd0;

void duplicate_unplaced_00188430(u32 a0, u32 a1, u32 a2) {
    u32 t6 = (u32)&D_01c60bd0;
    u32 t7 = (u32)((s32)t6 + (0));
    u32 t4 = a2;
    u32 t5 = *(u32*)((u32)a0 + (s32)(136));
    *(u32*)((u32)t6 + (s32)(0)) = t5;
    *(u32*)((u32)t7 + (s32)(4)) = a1;
    *(u32*)((u32)t7 + (s32)(8)) = t4;
    func_00188340(a0, (u32)7, t7, (u32)3);
}

extern u8 D_01c608c0;

// 001887d8: moved to src/anon/unit_00188550.cpp
void func_001887d8(u32 a0, u32 a1);

extern "C" u32 func_00188948(...);
extern "C" u32 func_00188fe0(...);

void duplicate_unplaced_00189028(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a2;
    u32 s1 = a3;
    u32 v0 = func_00188fe0(a0, a1);
    a1 = s0;
    a2 = s1;
    a0 = v0;
    func_00188948(a0, a1, a2);
}

u32 func_00189068(u32 a0, u32 a1);  // 0x00189068: definition moved into src/anon/unit_00188848.cpp

void func_00189170(u32 a0);  // 0x00189170: definition moved into src/anon/unit_00188848.cpp

u32 func_0018a218(u32 a0, u32 a1);  // 0x0018a218: definition moved into src/anon/unit_00189d38.cpp

extern "C" u32 func_0018a670(...);

void func_0018a7d0(u32 a0, u32 a1);  // 0x0018a7d0: definition moved into src/anon/unit_00189d38.cpp

void func_0018a958(u32 a0, u32 a1, f32 f12, f32 f13);  // 0x0018a958: definition moved into src/anon/unit_00189d38.cpp

void func_0018acd8(u32 a0, u32 a1);  // 0x0018acd8: definition moved into src/yasui/libys/npc.cpp

extern "C" u32 func_0016c2b0(...);
extern "C" u32 func_0018b010(...);

void func_0018b0c8(u32 a0, u32 a1, u32 a2);  // 0x0018b0c8: definition moved into src/yasui/libys/npc.cpp

u32 func_0018b198(u32 a0);  // 0x0018b198: definition moved into src/yasui/libys/npc.cpp

u32 func_0018b1d8(u32 a0);  // 0x0018b1d8: definition moved into src/yasui/libys/npc.cpp

void func_0018b338(f32);

void func_0018b270(void);  // 0x0018b270: definition moved into src/yasui/libys/npc.cpp

u32 func_0018c458(u32 a0);  // 0x0018c458: definition moved into src/yasui/libys/npc.cpp

extern f32 D_00349e10;

void func_0018c570(u32 a0);  // 0x0018c570: definition moved into src/yasui/libys/npc.cpp

// 0018ca90: moved to src/yasui/libys/damage.cpp

u32 duplicate_unplaced_0018cae0(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(32));
    u32 v0 = *(u8*)((u32)t7 + (s32)(18));
    v0 = (u32)(v0 >> 5);
    v0 = (u32)(v0 & 1u);
    return (u32)((u8)v0);
}


u32 func_0018ee10(u32 a0);  // 0x0018ee10: definition moved into src/anon/unit_0018d050.cpp

u32 func_0018ee28(u32 a0);  // 0x0018ee28: definition moved into src/anon/unit_0018d050.cpp

void func_0018efe8(u32 a0);  // 0x0018efe8: definition moved into src/anon/unit_0018d050.cpp

u32 duplicate_unplaced_0018f010(u32 a0) {
    u32 v0 = *(u8*)((u32)*(u32*)((u32)a0 + (s32)(40)) + (s32)(4));
    v0 = (u32)((s32)v0 + (-2));
    v0 = (u32)(v0 < 2u);
    return (u32)((u8)v0);
}

extern "C" u32 func_0018f070(...);  // list_contains_ptr_b

void func_0018f028(u32 a0);  // 0x0018f028: definition moved into src/anon/unit_0018d050.cpp

extern "C" u32 func_0019ba60(...);

void func_0018f428(u32 a0);  // 0x0018f428: definition moved into src/anon/unit_0018f140.cpp

extern "C" u32 func_0018ca48(...);

void func_0018f4c0(u32 a0);  // 0x0018f4c0: definition moved into src/anon/unit_0018f140.cpp

extern "C" u32 func_001a48c0(...);

void duplicate_unplaced_0018f770(u32 a0) {
    u32 a1 = *(u32*)((u32)a0 + (s32)(4));
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a0 = t7;
    func_001a48c0(a0, a1);
}

extern "C" u32 func_0018e0d8(...);

void duplicate_unplaced_0018f8a0(u32 a0) {
    u32 a1 = *(u32*)((u32)a0 + (s32)(4));
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a0 = t7;
    func_0018e0d8(a0, a1);
}

extern "C" u32 func_0018e108(...);

void duplicate_unplaced_0018fc20(u32 a0) {
    u32 a1 = *(u32*)((u32)a0 + (s32)(4));
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    a0 = t7;
    func_0018e108(a0, a1);
}

extern "C" u32 func_001050d8(...);
extern "C" u32 func_001d37a0(...);

void func_0018ffb8(u32 a0);  // 0x0018ffb8: definition moved into src/anon/unit_0018f140.cpp

extern "C" u32 func_0019ba60(...);


extern "C" u32 func_00190140(...);
extern "C" u32 func_0019bc38(...);

u32 func_001901c0(u32 a0);  // 0x001901c0: definition moved into src/anon/unit_001900d0.cpp

u32 func_00190680(u32 a0, u32 a1);  // 0x00190680: definition moved into src/anon/unit_001900d0.cpp

extern u8 D_0034e948;
extern u8 D_0034f240;

// 001919d0: moved to src/yasui/libys/status.cpp

extern u8 D_0034e948;
extern u8 D_0034f240;

// 001919f8: moved to src/yasui/libys/status.cpp

extern "C" u32 func_001917b0(...);
extern u8 D_0034f240;

// 00191c88: moved to src/yasui/libys/status.cpp

extern "C" u32 func_00170518(...);
extern "C" u32 func_001921d8(...);

void duplicate_unplaced_00192260(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 v0 = func_001921d8(a0);
    func_00170518(v0, s0, 0u);
}

extern "C" u32 func_00192388(...);  // skip_control_codes

// 00192b30: moved to src/yasui/libys/message.cpp

extern u8 D_01c61970;

// 00192fc8: moved to src/yasui/libys/message.cpp

void func_001ad990(u32, f32, f32, f32);
extern "C" u32 func_001bfd60(...);

void func_00194610(u32 a0, f32 a1);  // 0x00194610: definition moved into src/anon/unit_00193be8.cpp

u32 duplicate_unplaced_001946f0(u32 a0) {
    u32 t6 = *(u32*)((u32)a0 + (s32)(1416));
    u32 t5 = (u32)((s32)a0 + (1880));
    u32 t7 = (u32)(0x2000u << 16);
    t6 = (u32)(t6 & t7);
    a0 = (u32)((s32)a0 + (2236));
    if (t6 == 0u) {
        a0 = t5;
    }
    return a0;
}

void func_00195430(u32 a0);  // 0x00195430: definition moved into src/anon/unit_00194790.cpp

extern "C" u32 func_00195468(...);

void func_001954f8(u32 a0, u32 a1);  // 0x001954f8: definition moved into src/anon/unit_00194790.cpp

extern "C" u32 func_00195558(...);
extern u8 D_0034f250;
extern u8 D_0034fa78;

void duplicate_unplaced_00195750(void) {
    func_00195558((u32)&D_0034f250);
    func_00195558((u32)&D_0034fa78);
}

extern "C" u32 func_001b1448(...);

void duplicate_unplaced_00196170(void) {
    u32 t7 = (u32)(0x0035u << 16);
    u32 v0 = func_001b1448(*(u32*)((u32)t7 + (s32)(816)));
    t7 = (u32)(0x01c6u << 16);
    *(u32*)((u32)t7 + (s32)(6912)) = v0;
}

extern "C" u32 func_001b1448(...);

void duplicate_unplaced_00196300(void) {
    u32 t7 = (u32)(0x0035u << 16);
    u32 v0 = func_001b1448(*(u32*)((u32)t7 + (s32)(820)));
    t7 = (u32)(0x01c6u << 16);
    *(u32*)((u32)t7 + (s32)(6916)) = v0;
}

u32 func_00196388(u32 a0, u32 a1);  // 0x00196388: definition moved into src/anon/unit_00195d00.cpp

extern "C" u32 func_0016d110(...);
extern "C" u32 func_001969c0(...);

void func_00196a08(void);  // 0x00196a08: definition moved into src/anon/unit_00195d00.cpp

extern "C" u32 func_00196aa0(...);

void func_00196b28(u32 a0, u32 a1);  // 0x00196b28: definition moved into src/anon/unit_00195d00.cpp

extern "C" u32 func_00196aa0(...);

void func_00196b58(u32 a0, u32 a1);  // 0x00196b58: definition moved into src/anon/unit_00195d00.cpp

void func_00196e88(u32 a0, u32 a1, u32 a2, f32 a3);  // 0x00196e88: definition moved into src/anon/unit_00195d00.cpp

extern "C" u32 func_00196e88(...);
extern "C" u32 func_002bc788(...) asm("_ZN5SOUND11SE3DDisableEv");

void func_00197568(u32 a0);  // 0x00197568: definition moved into src/anon/unit_00195d00.cpp

extern "C" u32 func_00196e88(...);
extern "C" u32 func_001c1130(...);  // copy_record_block_to_table

void func_001978f0(void);  // 0x001978f0: definition moved into src/anon/unit_00195d00.cpp

extern "C" u32 func_00102c18(...);
extern u8 D_00197cf0;


u32 func_00197e40(void);  // 0x00197e40: definition moved into src/anon/unit_00195d00.cpp

extern "C" u32 func_001b0250(...);

// 00198660: moved to src/anon/unit_00197fe0.cpp

extern "C" u32 func_00198bd0(...);
extern "C" u32 func_00198ee8(...);
extern "C" u32 func_00199030(...);

// 00198cb8: moved to src/anon/unit_00198b88.cpp

extern "C" u32 func_00199890(...);

void func_00199938(u32 a0, u32 a1);  // 0x00199938: definition moved into src/anon/unit_00199688.cpp

extern u8 D_00350440;
extern u8 D_01c62198;

u32 func_0019abe8(void);  // 0x0019abe8: definition moved into src/anon/unit_00199688.cpp

extern "C" u32 func_0016b7a0(...);
extern u8 D_0034f250;

u32 func_0019ac30(u32 a0, u32 a1);  // 0x0019ac30: definition moved into src/anon/unit_00199688.cpp

extern "C" u32 func_001991a8(...);

u32 duplicate_unplaced_0019af98(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(8));
    u32 a1 = (u32)(*(u16*)((u32)t7 + (s32)(2)));
    u32 r2 = func_001991a8(*(u32*)((u32)t7 + (s32)(28)), a1);
    t7 = *(u32*)((u32)s0 + (s32)(4));
    t7 = (u32)(t7 | 0x0001u);
    *(u32*)((u32)s0 + (s32)(4)) = t7;
    return r2;
}

u32 func_0019bb18(u32 a0);  // 0x0019bb18: definition moved into src/anon/unit_0019ba60.cpp

u32 func_0019bb58(u32 a0);  // 0x0019bb58: definition moved into src/anon/unit_0019ba60.cpp

extern "C" u32 func_0019cc20(...);
extern u8 D_00350444;

void duplicate_unplaced_0019c970(u32 a0) {
    u32 s0 = a0;
    func_0019cc20();
    u32 t7 = *(u32*)((u32)&D_00350444 + (s32)(0));
    u32 t6 = s0;
    s0 = (u32)(t7 ^ t6);
    if (s0 == 0u) {
        t7 = 0u;
    }
    *(u32*)((u32)&D_00350444 + (s32)(0)) = t7;
}

extern "C" u32 func_0019cc20(...);
extern u8 D_00350444;

void duplicate_unplaced_0019c9a8(u32 a0) {
    u32 s0 = a0;
    func_0019cc20();
    u32 t7 = *(u32*)((u32)&D_00350444 + (s32)(0));
    u32 t6 = s0;
    s0 = (u32)(t7 ^ t6);
    if (s0 == 0u) {
        t7 = 0u;
    }
    *(u32*)((u32)&D_00350444 + (s32)(0)) = t7;
}

extern "C" u32 func_0015a638(...);

void func_0019c9e0(u32 a0, u32 a1);  // 0x0019c9e0: definition moved into src/anon/unit_0019ba60.cpp


extern "C" u32 func_00154c10(...);
extern "C" u32 func_0019d380(...);

void func_0019d3b8(u32 a0, u32 a1, u32 a2);  // 0x0019d3b8: definition moved into src/anon/unit_0019ba60.cpp

extern "C" u32 func_00154b98(...);
extern "C" u32 func_0019d380(...);

void func_0019d3f8(u32 a0, u32 a1, u32 a2);  // 0x0019d3f8: definition moved into src/anon/unit_0019ba60.cpp

extern "C" u32 func_0015a708(...);
extern "C" u32 func_0019d4a8(...);
extern "C" u32 func_002c0700(...);

void func_0019d480(void);  // 0x0019d480: definition moved into src/anon/unit_0019ba60.cpp

extern "C" u32 func_00190128(...);

void duplicate_unplaced_0019da20(u32 a0, u32 a1) {
    *(u32*)((u32)a0 + (s32)(0)) = a1;
    u32 s0 = a0;
    *(u16*)((u32)s0 + (s32)(4)) = 0u;
    func_001bc688((u32)((s32)a0 + (4)));
    func_00190128((u32)((s32)s0 + (16)));
    u32 t7 = (u32)-1;
    *(u32*)((u32)s0 + (s32)(80)) = 0u;
    *(u32*)((u32)s0 + (s32)(60)) = 0u;
    *(u32*)((u32)s0 + (s32)(36)) = t7;
}

u32 func_0019e698(u32 a0, u32 a1);  // 0x0019e698: definition moved into src/anon/unit_0019ba60.cpp

extern "C" u32 func_00102c18(...);
extern "C" u32 func_0019ec88(...);
extern "C" u32 func_0019ed48(...);
extern u8 D_0019ec68;
extern u8 D_00350448;

void duplicate_unplaced_0019ec20(void) {
    u32 s0 = (u32)&D_00350448;
    func_0019ec88(s0);
    func_0019ed48(s0);
    func_00102c18(1u, 0xa410u, (u32)&D_0019ec68);
}

void func_001ad990(u32, f32, f32, f32);

void func_0019ed78(u32 a0, f32 a1);  // 0x0019ed78: definition moved into src/anon/unit_0019ea10.cpp

extern u8 D_0032de28;

void func_0019ef30(void);  // 0x0019ef30: definition moved into src/anon/unit_0019ee80.cpp

void func_0019ef70(u32 a0) {
    u32 t7 = (u32)-1;
    *(u32*)((u32)a0 + (s32)(32)) = 0u;
    *(u32*)((u32)a0 + (s32)(0)) = 0u;
    *(u32*)((u32)a0 + (s32)(24)) = 0u;
    *(u32*)((u32)a0 + (s32)(28)) = 0u;
    *(u32*)((u32)a0 + (s32)(20)) = t7;
}

void duplicate_unplaced_0019f490(u32 a0, u32 a1) {
    u32 t7 = 1u;
    u32 t6 = (u32)(a1 >> 5);
    t6 = (u32)(t6 << 2);
    a1 = (u32)(a1 & 0x1fu);
    a0 = (u32)(a0 + t6);
    t7 = (u32)(t7 << a1);
    u32 t5 = *(u32*)((u32)a0 + (s32)(0));
    t5 = (u32)(t5 | t7);
    *(u32*)((u32)a0 + (s32)(0)) = t5;
}

void duplicate_unplaced_0019f4b8(u32 a0, u32 a1) {
    register u32 t7 asm("$15") = (u32)(a1 >> 5);
    a0 = (u32)((s32)a0 + (4));
    t7 = (u32)(t7 << 2);
    a1 = (u32)(a1 & 31u);
    a0 = (u32)(a0 + t7);
    register u32 t6 asm("$14") = *(u32*)((u32)a0 + (s32)(0));
    t7 = 1u;
    t7 = (u32)(t7 << (a1 & 31u));
    u32 m = t7;
    t6 = (u32)(t6 | m);
    *(u32*)((u32)a0 + (s32)(0)) = t6;
}

void func_0019f578(u32 a0) {
    u32 t6 = (u32)((s32)a0 + (96));
    do {
        *(u32*)((u32)a0 + (s32)(0)) = 0u;
        a0 = (u32)((s32)a0 + (12));
    } while ((s32)a0 < (s32)t6);
}

extern "C" u32 func_0019f5d8(...);  // find_entry12_pair

void func_0019f6c8(void);  // 0x0019f6c8: definition moved into src/anon/unit_0019ee80.cpp

extern "C" u32 func_001dc620(...);

// 0016e1c0: moved to src/anon/unit_0016d2e0.cpp
extern "C" u32 func_001796e8(...);
extern u8 D_01c5f480;

void func_00174190(u32 a0);  // 0x00174190: definition moved into src/anon/unit_00171e58.cpp

extern "C" u32 func_00190388(...);  // vec4_from_arg
extern u8 D_01c5f480;

void func_00174558(u32 a0);  // 0x00174558: definition moved into src/anon/unit_00171e58.cpp
void duplicate_unplaced_00198ea8(u32 a0, u32 a1) {
    s32 t7 = (s32)(*(s16*)((u32)a0 + (s32)(46)));
    a1 = (u32)(a1 & 0x1fffu);
    a1 = (u32)(a1 << 2);
    u32 t6 = (u32)t7;
    t7 = (s32)(t7 + 1);
    t6 = (u32)(t6 << 1);
    *(u16*)((u32)a0 + (s32)(46)) = (u16)t7;
    a0 = (u32)(a0 + t6);
    u32 t7u = (u32)(*(u16*)((u32)a0 + (s32)(32)));
    t7u = (u32)(t7u & 0xfffcu);
    t7u = (u32)(t7u | 1u);
    t7u = (u32)(t7u & 0x8001u);
    t7u = (u32)(t7u | a1);
    *(u16*)((u32)a0 + (s32)(32)) = (u16)t7u;
}

u32 func_0019f6f0(u32 a0, u32 a1, u32 a2);  // 0x0019f6f0: definition moved into src/anon/unit_0019ee80.cpp

f32 func_001a1e00(u32 a0);  // 0x001a1e00: definition moved into src/anon/unit_0019fb70.cpp

extern "C" u32 func_00190128(...);
extern u8 D_01c6cb7c;

// 001a7530: static initialiser, now made by gcc in src/anon/unit_001a6a10.cpp

extern "C" u32 func_00102c18(...);
extern u8 D_001ba6b0;


extern "C" u32 func_001bae38(...);
extern u8 D_01d49320;

// 001bb438: moved to src/yasui/libys/mission.cpp

extern "C" u32 func_001d3328(...);
extern u8 D_01d5ba10;

// 001d3588: static initialiser, now made by gcc in src/anon/unit_001d30b0.cpp

extern "C" u32 func_001d6a80(...);
extern u8 D_003527e0;

void func_001d6c58(void);  // 0x001d6c58: definition moved into src/anon/unit_001d68e0.cpp

extern "C" u32 func_001d6ab0(...);
extern u8 D_003527e0;

void func_001d6c88(void);  // 0x001d6c88: definition moved into src/anon/unit_001d68e0.cpp

extern "C" u32 func_001b1448(...);

void duplicate_unplaced_001d9d00(void) {
    u32 t7 = (u32)(0x0035u << 16);
    u32 v0 = func_001b1448(*(u32*)((u32)t7 + (s32)(10492)));
    t7 = (u32)(0x01d6u << 16);
    *(u32*)((u32)t7 + (s32)(-17752)) = v0;
}

extern u8 D_01d5bb00;

void duplicate_unplaced_001dc4b8(u32 a0) {
    u32 a1 = a0;
    u32 a0x = *(u32*)((u32)&D_01d5bb00 + (s32)(0));
    u32 t6 = *(u32*)((u32)a0x + (s32)(0));
    u32 t7 = *(u32*)((u32)t6 + (s32)(4));
    ((void(*)(u32,u32))t7)(a0x, a1);
}

extern u8 D_01d9e340;

void duplicate_unplaced_001de978(u32 a0) {
    u32 a1 = a0;
    u32 a0x = *(u32*)((u32)&D_01d9e340 + (s32)(0));
    u32 t6 = *(u32*)((u32)a0x + (s32)(0));
    u32 t7 = *(u32*)((u32)t6 + (s32)(4));
    ((void(*)(u32,u32))t7)(a0x, a1);
}

extern u8 D_01d9e340;

void duplicate_unplaced_001e0158(u32 a0) {
    u32 a1 = a0;
    u32 a0x = *(u32*)((u32)&D_01d9e340 + (s32)(0));
    u32 t6 = *(u32*)((u32)a0x + (s32)(0));
    u32 t7 = *(u32*)((u32)t6 + (s32)(4));
    ((void(*)(u32,u32))t7)(a0x, a1);
}

extern u8 D_01d9e340;

void duplicate_unplaced_001e01b8(u32 a0) {
    u32 a1 = a0;
    u32 a0x = *(u32*)((u32)&D_01d9e340 + (s32)(0));
    u32 t6 = *(u32*)((u32)a0x + (s32)(0));
    u32 t7 = *(u32*)((u32)t6 + (s32)(4));
    ((void(*)(u32,u32))t7)(a0x, a1);
}

extern "C" u32 func_00242ea8(...);
extern "C" u32 func_002bc1e8(...);

void func_002251c8(u32 a0) {
    u32 s0 = a0;
    if (func_00242ea8(a0) == 0u) {
        func_002bc1e8(s0);
        return;
    }
}

extern "C" u32 func_00139d78(...);

void func_0022b638(u32 a0, u32 a1);  // 0022b638: moved to src/sasa/musical_target.cpp (linked unit)

extern u8 D_0035e298;

extern "C" u32 func_001a8bb8(...);  // obj_set_header_bytes
extern u8 D_0035f060;

void func_00258120(u32 a0, u32 a1) {
    u32 t7 = 0xffffu;
    if (a1 != t7) {
        return;
    }
    t7 = 1u;
    if (a0 != t7) {
        return;
    }
    u32 t0 = (u32)&D_0035f060;
    a0 = t0;
    func_001a8bb8(a0);  // obj_set_header_bytes
}

extern "C" u32 func_00102a38(...);  // list_contains_id
extern "C" u32 func_00103eb0(...);
extern u8 D_00293b08;

u32 duplicate_unplaced_00293b70(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2;
    u32 (*fp_call0_00103eb0)() = (u32(*)())func_00103eb0;
    r2 = fp_call0_00103eb0();
    r4 = *(volatile u32*)((u32)r2 + (s32)(4));
    r5 = (u32)&D_00293b08;
    u32 (*fp_call4_00102a38)(u32, u32) = (u32(*)(u32,u32))func_00102a38;
    r2 = fp_call4_00102a38(r4, r5);
    return r2;
}

s32 func_001de2e0(u32 a0, u64 a1) {
    s32 t5 = *(s32*)(u32)(*(u32*)(u32)(a0 + 0) + 8);
    s32 t6 = 0;
    if (t5 > 0) {
        u32 v0 = *(u32*)(u32)(a0 + 4);
        while (1) {
            u64 t7 = *(u64*)(u32)(v0 + 8);
            t7 = (u64)(t7 & a1);
            if (a1 == t7) {
                return (s32)(*(u16*)(u32)(v0 + 2));
            }
            t6 = (s32)(t6 + 1);
            if (t6 < t5) {
                v0 = (u32)((s32)v0 + 80);
                continue;
            }
            break;
        }
    }
    return -1;
}

void func_001de690(void) {
    u32 s0 = D_01d9e348;
    while (s0 != 0u) {
        u32 next = *(u32*)(u32)(s0 + 20);
        func_001de590(s0);
        s0 = next;
    }
}

void func_001de6d0(void) {
    u32 s0 = D_01d9e348;
    while (s0 != 0u) {
        u32 next = *(u32*)(u32)(s0 + 20);
        func_001de610(s0);
        s0 = next;
    }
}

void func_001de710(void) {
    u32 s0 = D_01d9e348;
    while (s0 != 0u) {
        u32 next = *(u32*)(u32)(s0 + 20);
        func_001dde40(s0);
        s0 = next;
    }
}

u32 func_001de7b0(u32 a0) {
    a0 = (u32)(a0 & 0xffu);
    if (a0 == 1u) {
        return func_001dcd88();
    }
    return func_001dcd58();
}

u32 duplicate_unplaced_001de948(u32 a0) {
    u32 a1 = a0;
    u32 r4 = D_01d9e340;
    u32 t7 = *(u32*)(u32)(r4 + 0);
    u32 v0 = *(u32*)(u32)(t7 + 0);
    return ((u32(*)(u32, u32, u32))(u32)v0)(r4, a1, 0u);
}

u32 duplicate_unplaced_001e0128(u32 a0) {
    u32 a1 = a0;
    u32 r4 = D_01d9e340;
    u32 t7 = *(u32*)(u32)(r4 + 0);
    u32 v0 = *(u32*)(u32)(t7 + 0);
    return ((u32(*)(u32, u32, u32))(u32)v0)(r4, a1, 0u);
}

u32 duplicate_unplaced_001e0188(u32 a0) {
    u32 a1 = a0;
    u32 r4 = D_01d9e340;
    u32 t7 = *(u32*)(u32)(r4 + 0);
    u32 v0 = *(u32*)(u32)(t7 + 0);
    return ((u32(*)(u32, u32, u32))(u32)v0)(r4, a1, 0u);
}

// 001e0400: moved to src/anon/unit_001e0398.cpp

// 001e0a90: moved to src/rikeda/saveram_gumibattle.cpp

void duplicate_unplaced_001e0dc8(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(32));
    u32 t5 = *(u32*)((u32)D_00352bd0 + (s32)(3524));
    t7 = (u32)(t7 << 6);
    t5 = (u32)(t5 + t7);
    *(u32*)((u32)t5 + (s32)(60)) = 0u;
}

void duplicate_unplaced_001e1ce0(u32 a0) {
    u32 s0 = a0;
    func_001e1988(a0);
    u32 t6 = *(u32*)((u32)s0 + (s32)(3532));
    *(u32*)((u32)s0 + (s32)(3520)) = 1u;
    *(u32*)((u32)s0 + (s32)(3564)) = t6;
    *(u32*)((u32)s0 + (s32)(3560)) = 0u;
    *(u32*)((u32)s0 + (s32)(3556)) = 0u;
}

u32 duplicate_unplaced_001e4f00(void) {
    u32 v0 = func_001e3650();  // ptr_add4
    v0 = func_001e3660(v0, 1u);
    v0 = func_001e4248(v0);
    v0 = func_001e4e18(v0);
    return func_001e4320(v0);
}

void func_001e5f40(u32 a0, u32 a1);  // 0x001e5f40: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e5f88(u32 a0, u32 a1);  // 0x001e5f88: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e6000(u32 a0);  // 0x001e6000: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_001e6b90(void);  // 0x001e6b90: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_001e7188(u32 a0, u32 a1, s32 a2);  // 0x001e7188: definition moved into src/anon/unit_001e0cb8.cpp

f32 duplicate_unplaced_001ed130(f32 a0, f32 a1) {
    f32 f0 = (f32)(a0 * a1);
    return (f32)(f0 - a0);
}

f32 duplicate_unplaced_001ed2d8(f32 a0, f32 a1) {
    return (f32)(a0 * a1);
}

f32 duplicate_unplaced_001ed488(f32 a0, f32 a1) {
    return (f32)(a0 * a1);
}

s32 func_001ed638(s32 a0, f32 a1);  // 0x001ed638: definition moved into src/anon/unit_001ec098.cpp

s8 func_001edb18(s8 a0, f32 a1);  // 0x001edb18: definition moved into src/anon/unit_001ec098.cpp

s32 func_001edce0(s32 a0, f32 a1);  // 0x001edce0: definition moved into src/anon/unit_001ec098.cpp

s32 func_001edea8(s32 a0, f32 a1);  // 0x001edea8: definition moved into src/anon/unit_001ec098.cpp

s32 func_001ee070(s32 a0, f32 a1);  // 0x001ee070: definition moved into src/anon/unit_001ec098.cpp

s32 func_001ee238(s32 a0, f32 a1);  // 0x001ee238: definition moved into src/anon/unit_001ec098.cpp

s32 func_001ee400(s32 a0, f32 a1);  // 0x001ee400: definition moved into src/anon/unit_001ec098.cpp

f32 duplicate_unplaced_001ee5c8(f32 a0, f32 a1) {
    return a0 * a1 - a0;
}

f32 duplicate_unplaced_001ee7a0(f32 a0, f32 a1) {
    return a0 * a1;
}

f32 duplicate_unplaced_001ee980(f32 a0, f32 a1) {
    return a0 * a1;
}

s32 func_001eeb60(s32 a0, f32 a1);  // 0x001eeb60: definition moved into src/anon/unit_001ec098.cpp

s32 func_001eed60(s32 a0, f32 a1);  // 0x001eed60: definition moved into src/anon/unit_001ec098.cpp

s32 func_001eef68(s32 a0, f32 a1);  // 0x001eef68: definition moved into src/anon/unit_001ec098.cpp

s32 func_001ef170(s32 a0, f32 a1);  // 0x001ef170: definition moved into src/anon/unit_001ec098.cpp

s32 func_001ef370(s32 a0, f32 a1);  // 0x001ef370: definition moved into src/anon/unit_001ec098.cpp

s32 func_001ef578(s32 a0, f32 a1);  // 0x001ef578: definition moved into src/anon/unit_001ec098.cpp

void func_001eff30(u32 a0, u8* a1) {
    f32 z = 0.0f;
    *(u32*)(a1 + 12) = a0;
    *(f32*)(a1 + 8) = z;
    *(f32*)(a1 + 4) = z;
    *(f32*)(a1 + 0) = z;
}

void func_001f02b0(u32 a0, u8* a1) {
    f32 z = 0.0f;
    *(u32*)(a1 + 12) = a0;
    *(f32*)(a1 + 8) = z;
    *(f32*)(a1 + 4) = z;
    *(f32*)(a1 + 0) = z;
}

void func_001f45f8(u32 a0, u8* a1) {
    u8* s0 = (u8*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 12) + 160);
    u32 v = *(u32*)(s0 + 8);
    if (v != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), v);
        *(u32*)(s0 + 8) = 0;
    }
}

extern "C" void func_0021fa10(...);
extern "C" void func_0021fbc0(...);
extern "C" void func_0021fe28(...);
extern "C" void func_00220070(...);
void duplicate_unplaced_001fa928(u32 a0, u8* a1) {
    func_0021fbc0(a0 + *(u32*)(*(u32*)(a1 + 12) + 0) + 160);
}

void duplicate_unplaced_001fab08(u32 a0, u8* a1) {
    u8* s0 = (u8*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 0) + 160);
    func_0021fa10((u32)s0);
    *(u8*)(s0 + 8) = 4;
}

void duplicate_unplaced_001facd0(u32 a0, u8* a1) {
    func_0021fe28(a0 + *(u32*)(*(u32*)(a1 + 12) + 0) + 160);
}

void duplicate_unplaced_001fae80(u32 a0, u8* a1) {
    func_00220070(a0 + *(u32*)(*(u32*)(a1 + 12) + 0) + 160);
}

void duplicate_unplaced_001fb698(u32 a0, u8* a1) {
    func_0021fbc0(a0 + *(u32*)(*(u32*)(a1 + 12) + 0) + 160);
}

void duplicate_unplaced_001fb870(u32 a0, u8* a1) {
    u8* s0 = (u8*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 0) + 160);
    func_0021fa10((u32)s0);
    *(u8*)(s0 + 8) = 4;
}

void duplicate_unplaced_001fba88(u32 a0, u8* a1) {
    func_0021fe28(a0 + *(u32*)(*(u32*)(a1 + 12) + 0) + 160);
}

void duplicate_unplaced_001fbc78(u32 a0, u8* a1) {
    func_00220070(a0 + *(u32*)(*(u32*)(a1 + 12) + 0) + 160);
}

void func_002029a0(u32 a0, u8* a1) {
    u8* s0 = (u8*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 8) + 160);
    u32 v = *(u32*)(s0 + 8);
    if (v != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), v);
        *(u32*)(s0 + 8) = 0;
    }
}

void func_002039f8(u32 a0, u8* a1) {
    u8* s0 = (u8*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 4) + 160);
    u32 v = *(u32*)(s0 + 8);
    if (v != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), v);
        *(u32*)(s0 + 8) = 0;
    }
}

s32 func_0020a060(u8* a0, u8* a1) {
    if (*(u32*)(a0 + 0) == 0) {
        return 0;
    }
    if (*(u8*)(a1 + 182) == 0 || *(u32*)(a0 + 4) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0020b4b8(u8* a0, u8* a1) {
    if (*(u32*)(a0 + 0) == 0) {
        return 0;
    }
    if (*(u8*)(a1 + 242) == 0 || *(u32*)(a0 + 4) != 0) {
        return 1;
    }
    return 0;
}

void func_0020ce60(u32 a0, u8* a1) {
    (void)a0;
    if (*(s32*)((u8*)&D_00350000 + 18048u) != 0) {
        u8* t5 = a1;
        if (*(s32*)((u8*)&D_00350000 + 18052u) > 0) {
            func_002236d0(*(u32*)(t5 + 4), (u32)(a1 + 8), *(u8*)(a1 + 16), *(u8*)(t5 + 17));
        }
    }
}

void func_00220088(u8* a0, u32 a1) {  // list_set_flag_clear
    u8* n = *(u8**)(a0 + 24);
    a1 |= 8;
    while (n != 0) {
        u32 f = *(u16*)(n + 62);
        *(u32*)(n + 12) = 0;
        f |= a1;
        *(u16*)(n + 62) = f;
        n = *(u8**)(n + 8);
    }
}

void func_00222a00(u32 a0, u32 a1) {
    V4_222a00 tmp;
    sceVu0SubVector((u32)&tmp, a0, a1);  // vec4_sub
    (void)func_002229a0((u32)&tmp);  // vec3_length
}

void func_00224828() {
    u32 v = *(u32*)((u8*)&D_00360000 - 8672u);
    u32 cur = *(u32*)((u8*)&D_00360000 - 9512u);
    if (cur != v) {
        s32 n = *(s32*)((u8*)&D_00360000 - 9516u);
        if (n > 0) {
            *(s32*)((u8*)&D_00360000 - 9516u) = n - 1;
            *(u32*)((u8*)&D_00360000 - 9512u) = v;
        }
    }
}

s32 func_00224890() {
    s32 a = *(s32*)((u8*)&D_00360000 - 9524u);
    s32 b = *(s32*)((u8*)&D_00360000 - 9528u);
    if (b < a) {
        *(s32*)((u8*)&D_00360000 - 9528u) = a;
        return 1;
    }
    return 0;
}

void duplicate_unplaced_00224950(u32 a0) {
    *(u8*)((u8*)&D_00360000 - 9508u) = 1;
    *(u32*)((u8*)&D_00360000 - 9504u) = a0;
}

void func_00224b88(u32 a0) {
    u32 s0 = a0;
    s32 v = func_002249e8(a0);  // get_global_byte_36dad6
    if (v == 1) {
        func_001991a8(18, 0);
    } else {
        func_001991a8(99, 0);
    }
    func_001024a8(s0);
}

void func_00224bd0() {
    if (func_00224e90() == 0) {
        return;
    }
    if (func_00224988() != 0) {  // get_global_byte_36dad5
        func_00102c18(1, 14990, (u32)((u8*)&D_00220000 + 19336u));
    }
}

void func_00224f08(u8* a0) {
    u32 v = *(u32*)(a0 + 4);
    if (v != 0) {
        func_00105110(v);
    }
}

void func_002255f0() {
    if (*(u32*)((u8*)&D_00360000 - 9500u) != 0) {
        func_00170c00(*(u32*)((u8*)&D_00360000 - 9496u));
        *(u32*)((u8*)&D_00360000 - 9496u) = 0;
        func_00106420(*(u32*)((u8*)&D_00360000 - 9500u));
        *(u32*)((u8*)&D_00360000 - 9500u) = 0;
    }
}

void func_00225208() {
    if (func_00242ea8() != 0) {
        u32 a0 = 1;
        u32 a1 = 0x00017318;
        u32 a2 = (u32)((u8*)&D_00220000 + 21064u);
        func_00102c18(a0, a1, a2);
    }
}

u32 duplicate_unplaced_00225640(u32 a0, u32 a1, u32 a2) {
    u32 s16 = a2;
    u32 s17 = a1;
    u32 v = func_00227818(a0);
    u32 r = func_00225eb8(*(u32*)((u8*)&D_00360000 - 9500u), v, s16);
    return func_00227858(r, s17, s16);
}

extern "C" void func_00227930(...);
extern "C" u32 func_00225a30(...);
void duplicate_unplaced_00225690(u8* a0) {
    func_00225fa0(*(u32*)((u8*)&D_00360000 - 9500u), *(u32*)(a0 + 24));
    func_00227930((u32)a0);
}

s32 func_00225a68() {
    s32 ok = func_00225a30();
    if (ok == 0) {
        return 0;
    }
    s32 a = *(s32*)((u8*)&D_00360000 - 9488u);
    s32 b = *(s32*)((u8*)&D_00360000 - 8672u);
    u32 x = (u32)(b < a);
    return x < 1;
}

void func_00226030(u32 a0, u32 a1, u8* a2) {
    (void)a0;
    (void)a1;
    if (*(u32*)((u8*)&D_00360000 - 8976u) != 0) {
        *(u32*)(a2 + 4) = 3;
    }
}

void duplicate_unplaced_00226a78() {
    *(u32*)((u8*)&D_00360000 - 9456u) = 0;
    *(u8*)((u8*)&D_00360000 - 8665u) = 0;
    *(u32*)((u8*)&D_00360000 - 8656u) = 0;
    *(u32*)((u8*)&D_00360000 - 8652u) = 0;
    *(u32*)((u8*)&D_00360000 - 8648u) = 0;
    *(u32*)((u8*)&D_00360000 - 8644u) = 0;
}

void duplicate_unplaced_00226f78(u32 a0) {
    *(u32*)((u8*)&D_00360000 - 8612u) = a0;
    *(u8*)((u8*)&D_00360000 - 8620u) = 1;
}

u8* func_00227bd8(u32 a0, u32 a1) {
    s32 i = 0;
    u8* p = *(u8**)((u8*)&D_00360000 - 8976u);
    while (1) {
        u8* out = p;
        if (*(u32*)(p + 0) != a1) {
            i += 1;
        } else {
            if (*(u32*)(p + 4) != 3) {
                i += 1;
            } else {
                if (*(u32*)(p + 12) == a0) {
                    return out;
                }
                i += 1;
            }
        }
        if (i < 128) {
            p += 84;
            continue;
        }
        return (u8*)0;
    }
}

f32 func_00227c78(u16* a0) {
    union {
        u32 u;
        f32 f;
    } v;
    u32 w = v.u;
    w &= 0xffff0000u;
    w |= (u32)a0[0];
    volatile u32* pu = (volatile u32*)&v.u;
    volatile u16* ph = (volatile u16*)&v.u;
    *pu = w;
    ph[1] = a0[1];
    return v.f;
}

u32 func_00227ca8(u16* a0) {
    union {
        u32 u;
        f32 f;
    } v;
    u32 w = v.u;
    w &= 0xffff0000u;
    w |= (u32)a0[0];
    volatile u32* pu = (volatile u32*)&v.u;
    volatile u16* ph = (volatile u16*)&v.u;
    *pu = w;
    ph[1] = a0[1];
    return v.u;
}

u8* func_00227d10(u32 a0) {
    s32 i = 0;
    u8* p = *(u8**)((u8*)&D_00360000 - 8964u);
    while (i < 96) {
        if (*(s32*)(p + 0) != -1) {
            if (*(u32*)(p + 4) == a0) {
                return p;
            }
        }
        i += 1;
        p += 40;
    }
    return (u8*)0;
}

u8* func_00227d58(u32 a0) {
    s32 i = 0;
    u8* p_data = *(u8**)((u8*)&D_00360000 - 8960u);
    u8* p_idx = *(u8**)((u8*)&D_00360000 - 8964u);
    while (i < 96) {
        if (*(s32*)(p_idx + 0) != -1) {
            if (*(u32*)(p_idx + 4) == a0) {
                return p_data;
            }
        }
        i += 1;
        p_data += 112;
        p_idx += 40;
    }
    return (u8*)0;
}

s32 func_002283f8() {
    s32 a = *(s32*)((u8*)&D_00360000 - 8664u);
    if (a == -1) {
        return 0;
    }
    s32 b = *(s32*)((u8*)&D_00360000 - 8672u);
    return a - b;
}

void duplicate_unplaced_002289c0(u32 a0) {
    u32 s0 = a0;
    u32 vtbl = *(u32*)(a0 + 0);
    void (*fn)(u32) = (void (*)(u32))*(u32*)(vtbl + 28);
    fn(a0);
    func_00228918(s0);
}

void duplicate_unplaced_00228e28(u32 a0) {
    u32 s0 = a0;
    u32 vtbl = *(u32*)(a0 + 0);
    void (*fn)(u32) = (void (*)(u32))*(u32*)(vtbl + 28);
    fn(a0);
    func_00228bd8(s0);
}

void func_00229448(u32 a0);  // 00229448: moved to src/sasa/musical_score.cpp (linked unit)

void func_0022ab90(u8* a0);  // 0022ab90: moved to src/sasa/musical_input.cpp (linked unit)

s32 func_0022afe8(s32 a0);  // 0022afe8: moved to src/sasa/musical_input.cpp (linked unit)

void func_0022b5f0(u8* a0);  // 0022b5f0: moved to src/sasa/musical_target.cpp (linked unit)

u32 duplicate_unplaced_0022b7f0() {
    u32 s0 = (u32)D_01dad938;
    func_002fee78(s0, (u32)(D_00370000 + 4408), *(u32*)(D_00340000 - 13580));
    strlen(s0);  // strlen
    return s0;
}

void func_0022bbc8();  // 0022bbc8: moved to src/sasa/event_movie.cpp (linked unit)

void func_0022beb0(u8* a0);  // 0022beb0: moved to src/sasa/event_countdown.cpp (linked unit)

u32 duplicate_unplaced_0022c4b8(u32 a0) {
    u32 s0 = (u32)D_01dad960;
    func_002fee78(s0, (u32)(D_00370000 + 4496), *(u32*)(D_00340000 - 13580), a0);
    strlen(s0);  // strlen
    return s0;
}

extern "C" u32 func_0022c4b8(...);
void duplicate_unplaced_0022c508() {
    u32 p = func_0022c4b8();
    func_00170518(p, (u32)-200, 0);
}

void func_0022cc08(u8* a0);  // 0022cc08: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022ce00(u8* a0);  // 0022ce00: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022ce50(u8* a0);  // 0022ce50: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d068(u32* a0);  // 0022d068: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d238(u8* a0);  // 0022d238: moved to src/sasa/event_layout.cpp (linked unit)

extern "C" u32 func_001977a0(...);
void func_0022d358(u32 a0) {
    u32 s0 = a0;
    while (true) {
        if (func_001977a0() == 0) {
            break;
        }
        func_00102448(s0, 0);
    }
    *(u8*)((u8*)&D_00360000 - 8636u) = 1;
    func_00226478();
}

void func_0022d688() {
    u32 v0 = func_0014abb8();  // get_data_359840
    func_0014aa80(v0, 1, 0);
    v0 = func_0014abc8();  // get_data_359950
    func_0014aa80(v0, 1, 0);
    *(u8*)((u8*)&D_00360000 - 7336u) = 0;
}

extern "C" void func_0022d6d8() asm("_ZN2sa5EVENT7wide_onEv");

void func_0022d728(u8* a0) {
    u8* s0 = a0;
    if (func_002282f0((u32)*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s16*)(s0 + 6) == 0) {
        func_0022d688();
    } else {
        func_0022d6d8();
    }
}

void func_0022d778(u8* a0) {
    u8* s0 = a0;
    if (func_002282f0((u32)*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s16*)(s0 + 6) == 0) {
        func_00143298();
    } else {
        func_001432a8();
    }
}

u32 func_0022e110(u8* a0) {
    u8* s0 = a0 + 16;
    u32 v0 = func_001de568((u32)s0);
    u32 t7;
    if (v0 == 0) {
        goto zero;
    }
    v0 = func_001de4b0((u32)s0, 0, 0);
    if (v0 != 0) {
        t7 = 1;
        goto out;
    }
zero:
    t7 = 0;
out:
    return t7;
}

extern "C" void func_00226030(...);
void duplicate_unplaced_0022e160(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    func_00226030(a0, a1, a2);
    func_001de750(*(u32*)(s0 + 20));
}

void func_0022e7e8(u32* a0) {
    u32 t7 = a0[2];
    if (t7 == 0) {
        return;
    }
    func_00106420(t7);
}

void func_0022e9f8(u32* a0) {
    u32 t7 = a0[2];
    if (t7 == 0) {
        return;
    }
    func_00106420(t7);
}

void func_0022ee00(u32* a0) {
    u32 t7 = a0[2];
    if (t7 == 0) {
        return;
    }
    func_00106420(t7);
}

void duplicate_unplaced_0022f5a0(u32 a0, u32 a1, u32 a2) {
    (void)a0;
    a1 |= 0x40000000;
    u32 s0 = a2;
    func_0016ed50(a1, 0xffffffff, 30);
    u8* v0 = func_00227d10(s0);
    v0[22] = 1;
}

f32 func_0022f8f0(f32* a0, f32* a1) {  // vec4_dot
    return a0[0] * a1[0] + a0[1] * a1[1] + a0[2] * a1[2] + a0[3] * a1[3];
}

void func_002326d0(u32* a0) {
    u32 s0 = (u32)a0;
    if (func_002325f0((u32)a0) != 0) {
        return;
    }
    func_002baa08(*(u32*)(s0 + 20), *(u32*)(s0 + 28), 16383, 64);
}

void duplicate_unplaced_00232718() {
    s32 t6 = *(s32*)((u8*)&D_00360000 - 8660u) - 1;
    t6 = (t6 < 0) ? 0 : t6;
    *(s32*)((u8*)&D_00360000 - 8660u) = t6;
}

void func_00232d60(u8* a0) {
    u8* s0 = a0;
    if (func_002282f0((u32)*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(u8*)(s0 + 6) == 0) {
        func_002bbed0();
    } else {
        func_002bbf18();
    }
}

u32 func_00232e18(u32 a0) {
    s32 i = 0;
    u8* t6 = *(u8**)((u8*)&D_00360000 - 8968u);
    while (true) {
        if (*(s32*)(t6 + 0) != -1) {
            if (*(u32*)(t6 + 4) == a0) {
                return (u32)t6;
            }
        }
        i += 1;
        if (i < 64) {
            t6 += 64;
            continue;
        }
        return 0;
    }
}

void duplicate_unplaced_00236148() {
    u32 idx = *(u32*)((u8*)&D_00360000 - 7312u);
    void (*fn)() = *(void (**)())((u8*)&D_00360000 - 7296u + (idx << 2));
    fn();
}

void func_00237a68(u8* a0, f32 a1, f32 a2, f32 a3) {  // set_float124_128
    f32 f0 = a1 * a2;
    *(f32*)(a0 + 124) = a1;
    *(f32*)(a0 + 128) = a2;
    *(f32*)(a0 + 132) = a3;
    a1 = a1 * a3;
    *(f32*)(a0 + 44) = f0;
    *(f32*)(a0 + 48) = a1;
}

f32 func_00239bb8(u8* a0) {
    u8* s0 = a0;
    s32 v0 = func_00239b50((u32)a0);  // find_entry_in_group
    f32 f0 = (f32)v0;
    f32 f1 = *(f32*)((u8*)&D_00350000 - 25068u);
    f32 f2 = *(f32*)(s0 + 68);
    f0 = f0 * f1;
    f0 = f0 * f2;
    return f0;
}

u32 duplicate_unplaced_00239cf0(u8* a0) {
    u32 t7 = *(u32*)(a0 + 276);
    u32 t6 = 36;
    u32 t5 = *(u32*)(a0 + 180);
    t7 = t7 * t6;
    t7 = t7 + t5;
    u32 v0 = *(u16*)(t7 + 2);
    return (v0 < 1);
}

void func_00239d50(u8* a0, f32 a1) {
    u32 t5 = 0;
    *(f32*)(a0 + 296) = a1;
    if (a1 != 0.0f) {
        goto set_one;
    }
    if (*(f32*)(a0 + 300) != 0.0f) {
        t5 = 1;
        goto patch_flags;
    }
    if (*(f32*)(a0 + 304) == 0.0f) {
        goto patch_flags;
    }
set_one:
    t5 = 1;
patch_flags:
    u32 t7 = *(u32*)(a0 + 184);
    u32 t6 = 0xfffffffe;
    t7 = t7 & t6;
    t7 = t7 | t5;
    *(u32*)(a0 + 184) = t7;
}

void func_00239da0(u8* a0, f32 a1) {
    u32 t5 = 0;
    f32 f0 = *(f32*)(a0 + 296);
    *(f32*)(a0 + 300) = a1;
    if (f0 != 0.0f) {
        goto set_one;
    }
    if (a1 != 0.0f) {
        t5 = 1;
        goto patch_flags;
    }
    if (*(f32*)(a0 + 304) == 0.0f) {
        goto patch_flags;
    }
set_one:
    t5 = 1;
patch_flags:
    u32 t7 = *(u32*)(a0 + 184);
    u32 t6 = 0xfffffffe;
    t7 = t7 & t6;
    t7 = t7 | t5;
    *(u32*)(a0 + 184) = t7;
}

void func_00239df0(u8* a0, f32 a1) {
    u32 t5 = 0;
    f32 f0 = *(f32*)(a0 + 296);
    *(f32*)(a0 + 304) = a1;
    if (f0 != 0.0f) {
        goto set_one;
    }
    f0 = *(f32*)(a0 + 300);
    if (f0 != 0.0f) {
        goto set_one;
    }
    if (a1 == 0.0f) {
        goto patch_flags;
    }
set_one:
    t5 = 1;
patch_flags:
    u32 t7 = *(u32*)(a0 + 184);
    u32 t6 = 0xfffffffe;
    t7 = t7 & t6;
    t7 = t7 | t5;
    *(u32*)(a0 + 184) = t7;
}

f32 func_0023a8e0(u8* a0) {
    u8* s0 = a0;
    if (*(u8*)(a0 + 212) == 0) {
        func_0023a0d8((u32)a0);
    }
    return *(f32*)(s0 + 220);
}

extern "C" u32 func_0023ca30(...);
u32 func_0023c5a0(u32 a0) {
    s32 s1 = (s32)func_0023c5f0(a0) - 1;
    s32 v0 = (s32)func_0023ca30(a0, 0);
    if (v0 != 0) {
        if (v0 < s1) {
            s1 = v0;
        }
    }
    return (u32)s1;
}

f32 func_0023c6b8(u32 a0) {
    u32 s0 = a0;
    s32 v0 = (s32)func_0023c5f0(s0);
    return (f32)v0 * D_00349e14 * *(f32*)(s0 + 72);
}

u32 func_0023c900(u32 a0) {
    if ((u32)(*(u32*)(a0 + 56) - 1) < 2) {
        if (*(u8*)(a0 + 80) == 0) {
            f32 f1 = *(volatile f32*)(a0 + 68);
            f32 f0 = *(volatile f32*)(a0 + 64);
            if (f1 <= f0) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

void duplicate_unplaced_0023cdb8() {
    D_0035eb34 = 1;
    D_0035eb28 = 0;
    D_01dae680 = 0;
}

void duplicate_unplaced_0023d260() {
    func_0023d2b0();
    func_00253638();
    func_00257000();

    u8 v13 = D_00349e20;
    u32 v12 = D_00349e1c;
    D_0035eb50 = (u8)(v13 < 1);
    D_0035eb54 = v12;
}

void duplicate_unplaced_0023d3d0() {
    u32 v0 = func_001058e8();
    func_002fde18(v0 + 16796, 0, 5124);
    func_00242880();
    func_0023d410();
    func_00257000();
}

void func_0023ed00() {
    if (D_0035eb81 != 0) {
        func_00167fc8();
        D_0035eb80 = 1;
    }
}

void func_0023ed38() {
    if (D_0035eb81 == 0) {
        func_0023ed90();  // set_global_byte1
    }
    func_00168008();
    D_0035eb80 = 0;
}

void func_0023ede8() {
    u32 t7 = D_0035eb84;
    u32 t6 = t7 - 1;
    t7 = (u32)((s32)(t7 << 24) >> 24);
    if (t7 != 0) {
        D_0035eb84 = (u8)t6;
        return;
    }

    u32 v = D_0035eb8c;
    if (v != 0) {
        D_0035eb88 = v;
    } else {
        D_0035eb88 = 0;
    }
    D_0035eb8c = 0;
}

u32 func_0023ee30(u32 a0) {
    u32 a1 = a0;
    u32 a2 = (u32)__builtin_return_address(0);
    a0 = D_0035eb88;
    u32 t7 = *(u32*)a0;
    u32 v0 = *(u32*)t7;
    return ((u32(*)(u32, u32, u32))v0)(a0, a1, a2);
}

extern "C" u32 func_0023c6f8(...);
void func_0023f168(u32 a0) {
    s32 s1 = -10;
    if (*(s32*)(a0 + 152) != s1) {
        func_0023c6f8(a0 + 48, *(u32*)(a0 + 140));
        *(s32*)(a0 + 152) = s1;
        *(u8*)(a0 + 148) = 0;
    }
}

extern "C" u32 func_0023a918(...);
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

void duplicate_unplaced_0023fb00(u32 a0) {
    D_0035ebe0 = a0;
    func_0023fbc8();
    D_0035ebec = 0;
}

void duplicate_unplaced_0023fb28() {
    func_0023fc08();
    D_0035ebe0 = 0;
    D_0035ebec = 0;
}

u32 func_0023fb58(u32 a0) {
    u32 a1 = a0;
    u32 a2 = (u32)__builtin_return_address(0);
    a0 = D_0035ebe0;
    u32 t7 = *(u32*)a0;
    u32 v0 = *(u32*)t7;
    return ((u32(*)(u32, u32, u32))v0)(a0, a1, a2);
}

void duplicate_unplaced_0023fb90(u32 a0) {
    if (a0 != 0) {
        u32 a1 = a0;
        a0 = D_0035ebe0;
        u32 t6 = *(u32*)a0;
        u32 t7 = *(u32*)(t6 + 4);
        ((void(*)(u32, u32))t7)(a0, a1);
    }
}

u32 func_0023fdf0(u32 a0) {
    u32 a1 = a0;
    u32 a2 = (u32)__builtin_return_address(0);
    a0 = D_0035ec84;
    u32 t7 = *(u32*)a0;
    u32 v0 = *(u32*)t7;
    return ((u32(*)(u32, u32, u32))v0)(a0, a1, a2);
}

void duplicate_unplaced_0023fe28(u32 a0) {
    if (a0 != 0) {
        u32 a1 = a0;
        a0 = D_0035ec84;
        u32 t6 = *(u32*)a0;
        u32 t7 = *(u32*)(t6 + 4);
        ((void(*)(u32, u32))t7)(a0, a1);
    }
}

void duplicate_unplaced_002409b8(u32 a0) {
    u32 s0 = a0;
    if (s0 == 0) {
        s0 = D_0035ec90;
    }
    func_00242408();  // set_global_crc_m1
    func_00242418(s0, 8);  // crc_byte_update
    func_00242418(s0 + 12, 0x10FB4);  // crc_byte_update
}

void duplicate_unplaced_00240b48(u32 a0) {
    u32 s0 = a0;
    if (s0 == 0) {
        s0 = D_0035ec90;
    }
    a0 = func_001058e8();
    memcpy(a0, s0, 0x10FC0);
}

void duplicate_unplaced_00240e10() {
    func_00240360();

    u32 t5 = D_0035ec94;
    u32 a1 = D_0035ec9c;
    u32 a3 = D_0035ec88;
    u32 a0 = (u32)*(s8*)t5;
    func_00234590(a0, a1, 99, a3, 0);
}

void duplicate_unplaced_00240fd8(s32 a0, u32 a1) {
    if (a0 < 0) {
        u32 t7 = D_0035ec94;
        a0 = *(s8*)(t7 + 1);
    }

    u32 t5 = D_0035ec94;
    u32 t6 = ((u32)a0) << 5;
    t6 += t5;
    u32 t7 = *(u32*)(t6 + 8);
    t7 |= a1;
    *(u32*)(t6 + 8) = t7;
}

void duplicate_unplaced_00241320() {
    u32 a0 = D_0035ec98;
    u32 t7 = *(u32*)(a0 + 4);
    a0 += t7 * 40;
    a0 += 8;
    func_002fde18(a0, 0, 40);
}

void duplicate_unplaced_00241528() {
    strlen(D_0035ec88);  // strlen
    u32 a1 = D_0035ec88;
    u32 t6 = D_0035ec94;
    u32 a0 = (u32)*(s8*)t6;
    func_002346a0(a0, a1, 0);
}

void duplicate_unplaced_00241568() {
    u32 t6 = D_0035ec94;
    u32 a0 = (u32)*(s8*)t6;
    u32 a1 = D_0035ec88;
    func_00234670(a0, a1, 0, 0, 0);
}

void duplicate_unplaced_00241740(s32 a0) {
    if (a0 < 0) {
        u32 t6 = D_0035ec94;
        a0 = *(s8*)(t6 + 1);
    }
    func_00240c08((u32)a0, 0, 19);
}

u32 duplicate_unplaced_00241770(s32 a0) {
    if (a0 < 0) {
        u32 t7 = D_0035ec94;
        a0 = *(s8*)(t7 + 1);
    }

    u32 t7 = D_0035ec94;
    u32 t6 = ((u32)a0) << 5;
    t6 += t7;
    s32 v0 = *(s32*)(t6 + 8);
    v0 >>= 4;
    return (u32)(v0 & 1);
}

void func_002420d8(u32 a0, u32 a1) {
    (void)a0;
    a1 &= 0xFF;
    if (a1 != 0) {
        u32 t7 = D_0035ecb8;
        t7 |= 1;
        D_0035ecb8 = t7;
        return;
    }
    u32 t6 = D_0035ecb8;
    t6 &= (u32)-2;
    D_0035ecb8 = t6;
}

void func_00242258(u32 a0) {
    s32 s1 = 98;
    u32 t7 = *(u32*)(a0 + 4);
    u32 s0 = t7 + 628;
    do {
        *(u32*)s0 = func_001064a8((u32)-1);
        s1 -= 1;
        s0 += 4;
    } while (s1 >= 0);
}


void func_002422f0();  // 002422f0: moved to src/tozawa/crc.cpp (linked unit)

u32 func_00242330(u32 a0);  // 00242330: moved to src/tozawa/crc.cpp (linked unit)

void duplicate_unplaced_00242368(u32 a0) {
    if (a0 != 0) {
        u32 a1 = a0;
        a0 = D_0035ecbc;
        u32 t6 = *(u32*)a0;
        u32 t7 = *(u32*)(t6 + 4);
        ((void(*)(u32, u32))t7)(a0, a1);
    }
}

u32 duplicate_unplaced_002424c0(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)(func_001058e8() + 9280);
    u32 v0 = 0x000F423F;
    t7 += s0;
    return (u32)!((u32)(v0 < t7));
}

void func_002425d0(u32 a0) {
    a0 = a0 * 12;
    u16* t6 = &D_0035ecc8;
    s32 t5 = 5;
    u16* t7 = (u16*)((u8*)&D_003717e8 + a0);
    do {
        u16 v = *t7;
        t5 -= 1;
        *t6 = v;
        t7 += 1;
        t6 += 1;
    } while (t5 >= 0);
}


void duplicate_unplaced_00242a28(u32 a0) {
    u32 s0 = a0 & 0xFF;
    s0 = (u32)(0 < s0);
    u32 v0 = func_001058e8() + 16800;
    u32 t7 = *(u32*)(v0 + 4);
    t7 &= (u32)-2;
    t7 |= s0;
    *(u32*)(v0 + 4) = t7;
}

void duplicate_unplaced_00242b10(u32 a0) {
    u32 s0 = a0 & 0xFF;
    s0 = (u32)(0 < s0);
    u32 v0 = func_001058e8() + 16800;
    u32 t7 = *(u32*)(v0 + 4);
    t7 &= (u32)-9;
    t7 |= s0 * 8;
    *(u32*)(v0 + 4) = t7;
}

void duplicate_unplaced_00242b88(u32 a0) {
    u32 s0 = a0 & 0xFF;
    s0 = (u32)(s0 < 1);
    u32 v0 = func_001058e8() + 16800;
    u32 t7 = *(u32*)(v0 + 4);
    t7 &= (u32)-17;
    t7 |= s0 * 16;
    *(u32*)(v0 + 4) = t7;
}

void duplicate_unplaced_00242ca0(u32 a0) {
    u32 s0 = a0 & 0xFF;
    s0 = (u32)(s0 < 1);
    u32 v0 = func_001058e8() + 16800;
    u32 t7 = *(u32*)(v0 + 4);
    t7 &= (u32)-65;
    t7 |= s0 * 64;
    *(u32*)(v0 + 4) = t7;
}

void duplicate_unplaced_00242d10(u32 a0) {
    u32 s0 = a0 & 0xFF;
    s0 = (u32)(0 < s0);
    u32 v0 = func_001058e8() + 16800;
    u32 t7 = *(u32*)(v0 + 4);
    t7 &= (u32)-129;
    t7 |= s0 * 128;
    *(u32*)(v0 + 4) = t7;
}

void duplicate_unplaced_00242d80(u32 a0) {
    u32 s0 = a0 & 0xFF;
    s0 = (u32)(0 < s0);
    u32 v0 = func_001058e8() + 16800;
    u32 t7 = *(u32*)(v0 + 4);
    t7 &= (u32)-257;
    t7 |= s0 * 256;
    *(u32*)(v0 + 4) = t7;
}

void func_00243130(u32 a0) {
    if (a0 != 0) {
        func_00170950(a0);
    }
}

void func_00244988() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ece8);
    func_0023fc40(&v0, 4);
}

void func_002449c0() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        func_002891f0(D_0035ece8, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}

void func_002467b8() {  // queue_push_word
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ed20);
    func_0023fc40(&v0, 4);
}

void func_002467f0() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        func_002891f0(D_0035ed20, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}

u32 func_002468a0(u32 a0) {
    u32 s0 = a0;
    if (func_00246840(s0) != 0) {
        return (u32)((u8*)&D_00371af0 + s0 * 6);
    }
    return (u32)((u8*)&D_00371ad8 + s0 * 6);
}

void func_00249148() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ed4c);
    func_0023fc40(&v0, 4);
}

void func_00249180() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        func_002891f0(D_0035ed4c, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}

void func_0024abb0() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ed70);
    func_0023fc40(&v0, 4);
}

void func_0024abe8() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        func_002891f0(D_0035ed70, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}

u32 func_0024ac38(u32 a0) {
    u32 t6 = a0 * 36;
    u32 s0 = (u32)&D_00371ee8 + t6;
    if (a0 == 1) {
        if (func_0024ac88() != 0) {
            s0 = (u32)&D_00371f30;
        }
    }
    return s0;
}

void func_0024c618() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035eda8);
    func_0023fc40(&v0, 4);
}

void func_0024c650() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        func_002891f0(D_0035eda8, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}

void func_0024df58() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035edcc);
    func_0023fc40(&v0, 4);
}

void func_0024df90() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        func_002891f0(D_0035edcc, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}

u32 func_0024dfe0() {
    if (D_0035edf4 != 0) {
        return D_003722f0;
    }
    return D_003722ec;
}

u32 func_0024e058() {
    if (D_0035edf4 == 0) {
        return (u32)&D_003721b8;
    }
    return (u32)&D_00372228;
}

void func_0024f2d0() {
    u32 s0 = D_0035ee10;
    if (s0 != 0) {
        u32 v0 = func_00139d78(s0);
        u32 t7 = D_0035ee10;
        t7 = (v0 != 0) ? t7 : 0;
        D_0035ee10 = t7;
    }
}

void func_0024f310() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ee04);
    func_0023fc40(&v0, 4);
}

void func_0024f348() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        func_002891f0(D_0035ee04, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}

void duplicate_unplaced_00251e90(u32 a0) {
    a0 <<= 3;
    u32 a2 = a0 + (u32)&D_00372610;
    func_0028dbf8(D_0035ee60, (u32)&D_00372608, a2);
}

void duplicate_unplaced_00252618() {
    u32 v0 = func_002891e8(D_0035ee58);
    v0 = func_00252110(v0);

    u32 t7 = 6;
    v0 = v0 * t7;

    v0 = v0 + (u32)&D_00372650;
    u32 a1 = (u32)*(s16*)(v0 + 2);
    func_0028dac8(D_0035ee7c, a1);
}

void func_00252ba8() {
    if (func_0023f100(D_0035eea4) == (u32)-1) {
        func_00252ce0();
        func_00252d88();
        func_00252e50();
    }
}

void func_00252bf0() {
    if (func_0023f100(D_0035eea4) == (u32)-1) {
        func_00287da0();
    }
}

void func_00252f98() {
    if (func_00287db0() != 0) {
        if (func_00139d78(D_0035eea8) != 0) {
            u32 t7 = D_0035eea8;
            u32 t6 = *(u32*)t7;
            u32 t5 = *(u32*)(t6 + 20);
            ((void(*)(u32))t5)(t7);
        }
    }
}

void func_002537e0(u32 a0) {
    a0 <<= 4;
    u32 t7 = a0 + (u32)&D_0035eee0;
    u32 t6 = *(u32*)(t7 + 12);
    if (t6 != 0) {
        func_00253888(*(u32*)(t7 + 0));
    }
}

u32 duplicate_unplaced_002538f8(u32 a0) {
    a0 <<= 4;
    u32 t7 = a0 + (u32)&D_0035eee0;
    u32 v0 = *(u32*)(t7 + 4);
    u8 b = (u8)(v0 & 1);
    return (u32)b;
}

u32 duplicate_unplaced_00258068(s32 a0) {
    s32 v0 = (s32)(u32)D_0035ef70;
    v0 = v0 >> a0;
    u8 b = (u8)(v0 & 1);
    return (u32)b;
}

void duplicate_unplaced_00258d58(u32 a0, u32 a1, u32 a2) {
    D_0035f090 = (u16)a0;
    D_0035f092 = (u16)a1;
    D_0035f096 = (u16)a2;
}

void duplicate_unplaced_00258d78(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s2 = a1;
    u32 s1 = a3;
    func_00258d40(a0, a2);
    func_00258d58(a0, s2, s1);
}

void duplicate_unplaced_00259570(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s1 = a1;
    u32 s0 = a3 & 0xFF;
    u32 v0 = func_00259460(a0, a2 & 0xFF);
    func_002595b8(v0, s1, s0);
}

void duplicate_unplaced_0025a1d0() {
    func_002b4b00();
    func_0028f4d8(0, (u32)D_00372eea, 0);
    func_00240be0();
}

void duplicate_unplaced_0025ccc0() {
    u32 v0 = func_0014aba8();
    func_0014aa58(v0, 15, 0);
    func_00287cc0(0);
}

void func_0025ccf0();  // 0x0025ccf0: definition moved into src/anon/unit_002588e8.cpp

void duplicate_unplaced_0025cd40() {
    u32 v0 = func_0014aba8();
    func_0014aa58(v0, 15, 0);
    func_002bd760(60);
    func_00287cc0(0);
}

void duplicate_unplaced_0025dba8() {
    func_002b4b00();
    func_00240be0();
    func_0028f4d8(0, 0x8A7F, 0);
}

void func_00262118();  // 0x00262118: definition moved into src/anon/unit_0025f6b8.cpp

extern "C" u32 func_00257780(...);
u32 func_00262160();  // 0x00262160: definition moved into src/anon/unit_0025f6b8.cpp

extern "C" void func_00262538() asm("_ZN2Tz9ScrollBar7FadeOutEv");

u32 duplicate_unplaced_00263d70() {
    u32 a0 = *(u32*)((u32)func_00103eb0() + 4u);
    return ((u32(*)(u32, u32, u32, const char*, u32))func_00102818)(a0, 0u, 2000u, (const char*)&D_00263db0, 4096u);
}

u32 func_00263eb8(void* a0);  // 0x00263eb8: definition moved into src/anon/unit_002632d0.cpp

extern "C" u32 func_00256e80(...);
void func_00264408();  // 0x00264408: definition moved into src/anon/unit_002640a8.cpp

void func_00264458();  // 0x00264458: definition moved into src/anon/unit_002640a8.cpp

u32 func_00267248();  // 0x00267248: definition moved into src/anon/unit_00265580.cpp

u32 func_002674b8();  // 0x002674b8: definition moved into src/anon/unit_00265580.cpp

u32 duplicate_unplaced_002691c8() {
    func_00257388(0x846au, 0u);
    func_002571e0(1u);
    return func_00287cc0(0u);
}

u32 duplicate_unplaced_00269378() {
    func_00257388(0xc22eu, 0u);
    func_002571e0(0u);
    return func_00287cc0(0u);
}

u32 duplicate_unplaced_0026dcb8() {
    func_0026d968();
    func_00287bd0(0u, 0u);
    u32 a0 = *(u32*)((u32)func_00103eb0() + 4u);
    return ((u32(*)(u32, u32, u32, const char*, u32))func_00102818)(a0, 0u, 2000u, (const char*)&D_0026dd40, 4096u);
}

void duplicate_unplaced_0026dd18(u32 a0, u32 a1, s32 a2) {
    *(u32*)(u32)&D_0035f118 = a0;
    *(u32*)(u32)&D_0035f11c = a1;
    if (a2 < 0) {
        return;
    }
    *(u8*)(u32)&D_0035f120 = (u8)a2;
}

void func_0026ede0();  // 0x0026ede0: definition moved into src/anon/unit_0026c450.cpp

extern "C" void func_0026ee30() asm("_ZN2Tz8CmCustom8LeaveAllEv");

u32 func_00272428();  // 0x00272428: definition moved into src/anon/unit_00271e08.cpp

void func_00274db8();  // 0x00274db8: definition moved into src/anon/unit_002748a0.cpp

void func_00274e08();  // 0x00274e08: definition moved into src/anon/unit_002748a0.cpp

void func_00274e50();  // 0x00274e50: definition moved into src/anon/unit_002748a0.cpp

void func_00276300();  // 0x00276300: definition moved into src/anon/unit_002748a0.cpp

void func_00276598();  // 0x00276598: definition moved into src/anon/unit_002748a0.cpp

void func_00276dc0();  // 0x00276dc0: definition moved into src/anon/unit_002748a0.cpp

u32 func_00276fa8();  // 0x00276fa8: definition moved into src/anon/unit_002748a0.cpp

extern "C" void func_00277128() asm("_ZN2Tz9CmAbility8LeaveAllEv");

u32 func_0027a1c8();  // 0x0027a1c8: definition moved into src/anon/unit_0027a108.cpp

u32 func_0027bba0(u32 a0);  // 0x0027bba0: definition moved into src/anon/unit_0027a6d8.cpp

u32 func_0027d4f0(u32 a0);  // 0x0027d4f0: definition moved into src/anon/unit_0027d2e8.cpp

void duplicate_unplaced_0027dc20(u32* a0, u32* a1) {
    *a0 = *(u32*)(u32)&D_0035f240;
    *a1 = *(u32*)(u32)&D_0035f23c;
}

void func_002804f0();  // 0x002804f0: definition moved into src/anon/unit_0027f2b0.cpp

u32 func_002811b0(u32 a0, s32 a1);  // 0x002811b0: definition moved into src/anon/unit_0027f2b0.cpp

u32 func_00281388(u32 a0) {
    u32 v0 = 0u;
    if (a0 == 1u || a0 == 4u || a0 == 5u) {
        v0 = 1u;
    }
    return v0;
}

void func_002814f0(u32 a0, u32 a1);  // 0x002814f0: definition moved into src/anon/unit_0027f2b0.cpp

u32 func_00281be0();  // 0x00281be0: definition moved into src/anon/unit_0027f2b0.cpp

void func_00281e20();  // 0x00281e20: definition moved into src/anon/unit_00281cf0.cpp

void duplicate_unplaced_00281e70(u32 a0) {
    *(u32*)(u32)&D_0035f28c = a0;
    *(u8*)(u32)&D_0035f299 = 0u;
}

void duplicate_unplaced_00281e88(u32 a0) {
    u32 s0 = a0;
    func_00281f40(s0, 0u);
    func_00281f48(s0);  // memset_1920
    func_00281f70(s0);
    func_00281f90(s0);
}

void duplicate_unplaced_00281ec8(u32 a0) {
    u32 s0 = a0;
    func_00281f40(s0, 0u);
    func_00281f48(s0);  // memset_1920
    func_00281f70(s0);
    func_00281f90(s0);
}

u32 duplicate_unplaced_00282228(u32 a0, u32 a1, u32 a2) {
    (void)a0;
    u32 m = 1u << a1;
    return (u32)((a2 & m) != 0u);
}

void func_00283180();  // 0x00283180: definition moved into src/anon/unit_00282c68.cpp

void func_002831b0();  // 0x002831b0: definition moved into src/anon/unit_00282c68.cpp

u32 duplicate_unplaced_002831e0(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    func_00257708(1u);
    *(u32*)(*(u32*)(u32)&D_0035f2b4) = s1;
    func_00283d00(s0);
    func_00283f50();
    return func_002833f8();
}

u32 duplicate_unplaced_00284048() {
    if (func_00290940(*(u32*)(u32)&D_0035f2b0) != 0u) {
        func_00290a60(*(u32*)(u32)&D_0035f2b0);
    }
    return func_00170320(5100u);
}

void duplicate_unplaced_00284ea8() {
    func_002bd7d8();
    u32 a0 = func_00103580();
    u32 vt = *(u32*)a0;
    u32 fn = *(u32*)(vt + 4u);
    ((void(*)(u32, u32))fn)(a0, *(u32*)(u32)&D_0035f2c0);
    *(u32*)(u32)&D_0035f2c0 = 0u;
}

void func_00285418();  // 0x00285418: definition moved into src/anon/unit_002853b8.cpp

u32 func_00285728();  // 0x00285728: definition moved into src/anon/unit_002853b8.cpp

void func_00287880(void* a0, u32 a1);  // 0x00287880: definition moved into src/anon/unit_00286d28.cpp

void func_002878c8(void* a0);  // 0x002878c8: definition moved into src/anon/unit_00286d28.cpp

void duplicate_unplaced_00287b30() {
    D_0035f2f0 = 0;
    D_0035f2fc = -1;
    D_0035f2f4 = 0;
    D_0035f2f8 = 0;
    func_00287c78(0);
}

void duplicate_unplaced_00287b98() {
    D_0035f2f8 = D_0035f2f8 - 1;
    func_00287c78();
    func_00287c20();  // clear_global_flag_return_m1
}

void duplicate_unplaced_00287d08() {
    D_0035f30c = 0;
    D_0035f310 = -1;
}

extern "C" u32 func_00167f18(...);
s32 duplicate_unplaced_00288088() {
    u64 v0 = *(u64*)((u8*)func_00167f18(0) + 8);
    return (s32)(v0 != 0ull);
}

void func_002885d0();  // 0x002885d0: definition moved into src/anon/unit_002880b8.cpp

void duplicate_unplaced_00288c20(void* a0) {
    if (a0 != (void*)0) {
        void* obj = D_0035f34c;
        ((void (*)(void*, void*))(*(u32*)(*(u32*)obj + 4u)))(obj, a0);
    }
}

void duplicate_unplaced_00288c58(void* a0, u32 a1) {
    u8* s1 = (u8*)a0;
    u32 s0 = a1 << 3;
    *(u32*)(s1 + 40) = func_00288be8(a1 << 2);
    *(u32*)(s1 + 44) = func_00288be8(s0);
    *(u32*)(s1 + 48) = func_00288be8(s0);
}


u32 func_00289358(void* a0);  // 0x00289358: definition moved into src/anon/unit_00288b00.cpp

void duplicate_unplaced_0028af90(void* a0, s32 a1) {
    u32 t7;
    if (a1 >= 0) {
        t7 = (u32)a1;
        goto done;
    } else {
        t7 = (u32)*(u16*)((u8*)a0 + 4);
    }
done:
    *(u16*)((u8*)a0 + 22) = (u16)t7;
}

void func_0028b4c0(void* a0, void* a1);  // 0x0028b4c0: definition moved into src/anon/unit_00288b00.cpp

void func_0028b4f0(void* a0, void* a1);  // 0x0028b4f0: definition moved into src/anon/unit_00288b00.cpp

void func_0028b6f0(void* a0, void* a1);  // 0x0028b6f0: definition moved into src/anon/unit_00288b00.cpp

void func_0028b720(void* a0, void* a1);  // 0x0028b720: definition moved into src/anon/unit_00288b00.cpp

void duplicate_unplaced_0028cc40(void* a0) {
    if (a0 != (void*)0) {
        void* obj = D_0035f3f8;
        ((void (*)(void*, void*))(*(u32*)(*(u32*)obj + 4u)))(obj, a0);
    }
}

extern "C" u32 func_0028ddd8(s32) asm("_ZN2Tz8MenuUtil11GetFontTypeEi");

void duplicate_unplaced_0028e710(void* a0, u32 a1) {
    u8* s0 = (u8*)a0;
    u32 s1 = a1;
    func_00139d78(s0);
    *(u32*)(s0 + 48) = s1;
}

extern "C" u32 func_0023aa18(...);
extern "C" u32 func_0023aa38(...);
void duplicate_unplaced_0028eab8(void* a0, void* a1) {
    u8* s0 = (u8*)a1 + 24;
    u8* s1 = (u8*)a0;
    *(u32*)(s1 + 36) = func_0023aa18(s0);
    *(u32*)(s1 + 40) = func_0023aa38(s0);
}

void func_0028eb00(void* a0, f32 a1);  // 0028eb00: moved to src/anon/unit_0028c878.cpp

void func_0028eb38(void* a0, s32 a1, f32 a2);  // 0028eb38: moved to src/anon/unit_0028c878.cpp

void func_0028f7a0();  // 0028f7a0: moved to src/anon/unit_0028f1e0.cpp

u32 func_00290060(void* a0);  // 00290060: moved to src/anon/unit_0028f1e0.cpp

u32 func_00290580(void* a0);  // 00290580: moved to src/anon/unit_0028f1e0.cpp

void duplicate_unplaced_00290a10(void* a0, void* a1, void* a2) {
    u8* s1 = (u8*)a0;
    void* s0 = a2;
    u32 v0 = func_001708f8(a1, (u32)-1);
    func_00290960((u32)s1, v0, (u32)s0);
    *(u8*)(s1 + 16) = 1;
}

u32 duplicate_unplaced_002925c0() {
    u32 v0 = func_00103eb0();
    u32 a0 = *(u32*)(v0 + 4);
    v0 = func_00102818(a0, 0, 0x000222e0u, (u32)func_00292608, 4096u);
    *(u32*)(v0 + 48) = (u32)D_00292620;
    return v0;
}

void func_00293780();  // 0x00293780: definition moved into src/anon/unit_00292e60.cpp

u32 func_00293f40(u32 a0);  // 0x00293f40: definition moved into src/anon/unit_00292e60.cpp

void duplicate_unplaced_00293f78(u32 a0) {
    if (a0 != 0) {
        u32 base = 0x00360000u;
        u32 obj = *(u32*)(base + (s32)-2704);
        u32 vtbl = *(u32*)obj;
        u32 fn = *(u32*)(vtbl + 4);
        ((void(*)(u32, u32))fn)(obj, a0);
    }
}

u32 duplicate_unplaced_00293fc0() {
    u32 base = 0x00360000u;
    func_00290940(*(u32*)(base + (s32)-2700));
    u32 v0 = func_00293db8(0, 0);
    return func_00290960(*(u32*)(base + (s32)-2700), v0, 43);
}

u32 duplicate_unplaced_002943b0(void* a0) {
    u32 d = *(u16*)((u8*)a0 + 4);
    u32 base = 0x00360000u;
    u32 table = *(u32*)(base + (s32)-2696);
    u32 off = (d >> 5) << 2;
    u32 shift = d & 31;
    off = off + table;
    u32 mask = 1u << shift;
    u32 v = *(u32*)off;
    v = v & mask;
    return 0u < v;
}

s32 duplicate_unplaced_00295228(u32 a0) {
    u32 s1 = a0;
    u32 base = func_00294000(0);
    u32 s0 = base + 16;
    u32 idx = func_00295158(s1);
    idx = idx << 4;
    idx = idx + s0;
    return *(s8*)idx;
}

void func_00295668();  // 0x00295668: definition moved into src/anon/unit_00292e60.cpp

extern "C" u32 func_0029da68(...);
void func_0029dd60() {
    s16 tmp;
    u32 v0 = func_00276638(15);
    u32 base = 0x00360000u;
    v0 = v0 << 1;
    v0 = v0 + *(u32*)(base + (s32)-2644);
    v0 = func_0029da68((u32)(s16)*(u16*)(v0 + 8));
    tmp = *(s8*)(v0 + 1);
    func_00292b40(&tmp, 1);
}

u32 func_0029e0f8();  // 0x0029e0f8: definition moved into src/anon/unit_0029d008.cpp

void func_0029ee38();  // 0x0029ee38: definition moved into src/anon/unit_0029d008.cpp

u32 duplicate_unplaced_002a01c8(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00294000(4);
    s0 = s0 << 3;
    v0 = v0 + 16;
    return v0 + s0;
}

u32 duplicate_unplaced_002a0360() {
    u32 base = 0x00360000u;
    u32 p = *(u32*)(base + (s32)-2608);
    s32 s0 = *(s8*)p;
    u32 v0 = func_00276c18();
    s0 = (s0 != 0);
    if (v0 == 0) {
        return (u32)s0;
    }
    return 1;
}

u32 func_002a3910() {
    u32 a0;
    u32 v0;

    if (func_002a4430() != 0) {
        a0 = 20346;
        goto call;
    }

    v0 = func_002a43f0();
    a0 = 18676;
    if (v0 == 0) {
        a0 = 18677;
    }

call:
    return func_00276c50(a0, 0);
}

u32 duplicate_unplaced_002a6368(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00294000(6);
    s0 = s0 << 3;
    v0 = v0 + 16;
    return v0 + s0;
}

void func_002a6a18() {
    if (func_00287bc0() == 39) {
        func_002a73d0();
        func_00274ac8();
    }
}

u32 func_002a7490() {
    u32 t7 = *(u32*)(func_001058e8() + 18984);
    u32 v0 = t7 & 1;
    if (v0 == 0) {
        u32 t6 = t7 & 0x400;
        v0 = 0u < t6;
    }
    return v0;
}

void func_002a7760() {
    u32 v0 = func_00287bc0();
    if (v0 == 11 || v0 == 36) {
        func_002a8258();
        func_00274ac8();
    }
}

u32 duplicate_unplaced_002a7f20(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00294000(7);
    s0 = s0 << 3;
    v0 = v0 + 16;
    return v0 + s0;
}

u32 duplicate_unplaced_002a8920() {
    u32 v0 = *(u8*)func_001d56c8();
    return v0 >= 2u;
}

void func_002a8a88() {
    u32 v0 = func_00287bc0();
    if (v0 == 10 || v0 == 35) {
        func_002a94f8();
        func_00274ac8();
    }
}

u32 duplicate_unplaced_002a92a0(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00294000(8);
    s0 = s0 << 4;
    v0 = v0 + 16;
    return v0 + s0;
}

void duplicate_unplaced_002b6530(u32 a0) {
    if (a0 == 0) {
        u32 base = 0x00360000u;
        a0 = *(u32*)(base + (s32)-2340);
    }
    func_00290a60(a0);
}

u32 duplicate_unplaced_002ba140(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 s1 = a0;
    func_002bc608(s1);
    u32 s2 = a2;
    return func_002b6f28(s1, s0, s2);
}

u32 duplicate_unplaced_002ba1b8(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 s1 = a0;
    func_002bc470(s1);
    u32 s2 = a2;
    return func_002b6e24(s1, s0, s2);
}

void duplicate_unplaced_002ba8a8() {
    func_002b7078(0);
    func_002b7078(1);
    ((void(*)(u32, u32, u32))func_002b72e4)(0xffffff9cu, 0xffffffffu, 0);
    func_002baa60();
    func_002b83b4();
}

void duplicate_unplaced_002ba948() {
    func_002b70b8(0, 12288, 240);
    func_002b70b8(1, 12288, 240);
}

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

// 002bac78: moved to src/anon/unit_002bac78.cpp

void func_002bb0a0(s32 a0, s32* a1, s32* a2);  // 0x002bb0a0: definition moved into src/anon/unit_002bb070.cpp

void func_002bb0e0(u32 a0);  // 0x002bb0e0: definition moved into src/anon/unit_002bb070.cpp

void func_002bb180(u32 a0, u32 a1);  // 0x002bb180: definition moved into src/anon/unit_002bb070.cpp

void func_002bb5a8(void* a0, void* a1);  // 0x002bb5a8: definition moved into src/anon/unit_002bb070.cpp

void func_002bc9a8(s32 a0, u32 a1, u32 a2);  // 0x002bc9a8: definition moved into src/anon/unit_002bc978.cpp

s32 func_002bca48(s32 a0, u32 a1);  // 0x002bca48: definition moved into src/anon/unit_002bc978.cpp

s32 func_002bcd60(s32 a0, u32 a1);  // 0x002bcd60: definition moved into src/anon/unit_002bc978.cpp

void func_002bcda8(s32 a0, u32 a1);  // 0x002bcda8: definition moved into src/anon/unit_002bc978.cpp

void func_002bce10(u32* a0, u32 a1);  // 0x002bce10: definition moved into src/anon/unit_002bc978.cpp

void func_002bcfa0();  // 0x002bcfa0: definition moved into src/anon/unit_002bc978.cpp

void func_002bcfe8(u32* a0);  // 0x002bcfe8: definition moved into src/anon/unit_002bc978.cpp

void func_002bd030();  // 0x002bd030: definition moved into src/anon/unit_002bc978.cpp

void func_002bd078(u32* a0);  // 0x002bd078: definition moved into src/anon/unit_002bc978.cpp

void func_002bd0b8();  // 0x002bd0b8: definition moved into src/anon/unit_002bc978.cpp

void func_002bd100(u32* a0);  // 0x002bd100: definition moved into src/anon/unit_002bc978.cpp

void func_002bd140();  // 0x002bd140: definition moved into src/anon/unit_002bc978.cpp

u32 duplicate_unplaced_002bd260(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    u32 p = (u32)&func_01e2bba0;
    u32 x = (u32)&func_00374fa8;
    wtarget_002fee78(p, x, a0, a3);
    strlen(p);  // strlen
    return p;
}

void duplicate_unplaced_002bd538() {
    func_003617e4 = 0;
    u32 v = func_002b823c();
    func_003617e0 = v;
    func_003617e8 = 1;
}

void func_002bd680();  // 0x002bd680: definition moved into src/anon/unit_002bc978.cpp

u32 duplicate_unplaced_002bd730(u32 a0, u32 a1, u32 a2, u32 a3) {
    func_003617f0 = a0;
    return func_002b8824(func_003617ec, a1, 64, a2, a3);
}

void duplicate_unplaced_002bd788(u32 a0) {
    u8* pf = &func_003617f8;
    u32* pe = &func_003617ec;
    *pe = a0;
    *pf = 0;
    func_002b871c();
    u32 v = func_00102788(func_0032b91c, 0, 0x0005cc60, (u32)&func_002bd870);
    func_003617f4 = v;
}

void func_002bd838();  // 0x002bd838: definition moved into src/anon/unit_002bc978.cpp

void func_002be318(u32 a0, u32 a1, kn::FVector* a2);  // 0x002be318: definition moved into src/anon/unit_002be020.cpp

void duplicate_unplaced_002be568(u32* a0, u32 a1) {
    u32 s0 = a1;
    u32* s1 = a0;
    func_002baa60((u32)s1);
    u32* v0 = (u32*)func_00168b38(s1[26], 0xFFFFFFFF, s0);  // entry_array_find_nth
    func_002baa08(v0[2], v0[3], 0x3FFF, 64);
}

u32 func_002be5f8();  // 0x002be5f8: definition moved into src/anon/unit_002be020.cpp

void duplicate_unplaced_002be770(u32* a0, u32 a1, u32 a2) {
    u32* s0 = a0;
    func_00185ed8((u32)s0, a1, 4, a2);
    u32 t5 = s0[0x588 / 4];
    u32 t7 = (u32)&func_00361810;
    t5 = t5 | 0x40000000;
    s0[0] = t7;
    s0[0x588 / 4] = t5;
}

void duplicate_unplaced_002be7b8(u32* a0, u32 a1, u32 a2) {
    u32* s0 = a0;
    func_00185ed8((u32)s0, a1, 4, a2);
    u32 t5 = s0[0x588 / 4];
    u32 t7 = (u32)&func_00361810;
    t5 = t5 | 0x40000000;
    s0[0] = t7;
    s0[0x588 / 4] = t5;
}

void func_002bea20();  // 0x002bea20: definition moved into src/anon/unit_002be020.cpp

u32 duplicate_unplaced_002beb90(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    u32 p = (u32)&func_01e2bc40;
    u32 s = (u32)&func_00375400;
    a2 = func_0033caf4;
    wtarget_002fee78(p, s, a2, a3);
    return p;
}

void duplicate_unplaced_002bee58(u32* a0) {
    a0[0] = (u32)&func_00361980;
    u32 t5 = *(u32*)((u8*)a0 + 36);
    u32 t7 = *(u32*)t5;
    void (*fn)(u32) = (void(*)(u32))(*(u32*)(t7 + 12));
    fn(t5);
    a0[0] = (u32)&D_003637e0;
}

void duplicate_unplaced_002beea8(u32* a0) {
    a0[0] = (u32)&func_00361980;
    u32 t5 = *(u32*)((u8*)a0 + 36);
    u32 t7 = *(u32*)t5;
    void (*fn)(u32) = (void(*)(u32))(*(u32*)(t7 + 12));
    fn(t5);
    a0[0] = (u32)&D_003637e0;
    func_00105110((u32)a0);
}

void duplicate_unplaced_002bfaf0() {
    D_00361a50 = 0;
    YS::SELECTOR::ResetPauseMode(12);

    u32* p35 = (u32*)0x00350000;
    u32 t6 = *(u32*)((u8*)p35 + (s16)0xe948);
    u32 t5 = *(u32*)(t6 + 2880);
    u32 t7 = *(u32*)(t5 + 44);
    *(u32*)(t5 + 44) = t7 & 0xFFFFFFFE;

    YS::EVENT::ControlOn();
    func_00197cc0();
    func_00139858(201);
}

void duplicate_unplaced_002bfb40() {
    D_00361a50 = 0;
    YS::SELECTOR::ResetPauseMode(12);

    u32* p35 = (u32*)0x00350000;
    u32 t6 = *(u32*)((u8*)p35 + (s16)0xe948);
    u32 t5 = *(u32*)(t6 + 2880);
    u32 t7 = *(u32*)(t5 + 44);
    *(u32*)(t5 + 44) = t7 & 0xFFFFFFFE;

    YS::EVENT::ControlOn();
    func_00197cc0();
    func_00139858(201);
}

void func_002c1750();  // 0x002c1750: definition moved into src/anon/unit_002c10e0.cpp

void duplicate_unplaced_002c1c50(u32 a0) {
    u32 s0 = a0;
    u32 v0 = worldmap::Gumi::getCourse();
    v0 = func_001c2b58(v0);
    func_002c1b60(s0, v0);
}

void func_002c2228(u32 a0);  // 0x002c2228: definition moved into src/anon/unit_002c2228.cpp

void func_002c2248(u32 a0);  // 0x002c2248: definition moved into src/anon/unit_002c2228.cpp

extern "C" void func_00160fd0(...);
extern "C" void func_00161000(...);
void func_002c2268(u32 a0);  // 0x002c2268: definition moved into src/anon/unit_002c2228.cpp

void func_002c2288(u32 a0);  // 0x002c2288: definition moved into src/anon/unit_002c2228.cpp

void func_002c24e0(u32 a0);  // 0x002c24e0: definition moved into src/anon/unit_002c2228.cpp

void func_002c2518(u32 a0);  // 0x002c2518: definition moved into src/anon/unit_002c2228.cpp

u32 func_002c2550(u32 a0);  // 0x002c2550: definition moved into src/anon/unit_002c2228.cpp

u32 func_002c5150();  // 0x002c5150: definition moved into src/anon/unit_002c4ca8.cpp

void duplicate_unplaced_002c5418(u32 a0) {
    u32 ctor = (u32)D_002c53c8;
    u32* obj = (u32*)func_00102788(D_0032b96c, 0, 0x000493e0, ctor);
    obj[1] = a0;
}

void func_002c55b0(u32 a0);  // 0x002c55b0: definition moved into src/anon/unit_002c53c8.cpp

void duplicate_unplaced_002c5628(u32 a0) {
    u32 v13 = *(u32*)(a0 + 264);
    u32 v12 = *(u32*)(a0 + 268);

    v13 &= 0xfffffffdu;
    v13 &= 0xffffffbfu;
    v12 &= 0xfffffeffu;

    *(u32*)(a0 + 264) = v13;
    *(u32*)(a0 + 268) = v12;
}

void func_002c6190(u32 a0);  // 0x002c6190: definition moved into src/worldmap/cameramanager.cpp

void func_002c63c8(u32 a0, u32 a1);  // 0x002c63c8: definition moved into src/worldmap/cameramanager.cpp

void func_002c9f20(u32 a0);  // 0x2c9f20: moved to src/anon/unit_002c9998.cpp


u32 func_002cab58();  // 0x2cab58: moved to src/anon/unit_002ca0e0.cpp


void func_002cb7a0(u32 a0, u32 a1);  // 0x002cb7a0: definition moved into src/taito/path.cpp

u32 func_002cb800(u32 a0);  // 0x002cb800: definition moved into src/taito/path.cpp

u32 func_002cb890(u32 a0, s32 a1);  // 0x002cb890: definition moved into src/taito/path.cpp

u32 func_002cb8b8(u32 a0);  // 0x002cb8b8: definition moved into src/taito/path.cpp

u32 func_002cb8e0(u32 a0);  // 0x002cb8e0: definition moved into src/taito/path.cpp

u32 func_002cbed8(u32 a0, u32 a1);  // 0x002cbed8: definition moved into src/taito/path.cpp

u32 func_002ceb28();  // 002ceb28: moved to src/taito/minigame_base.cpp (linked unit)

void func_002cec50(u32 a0);  // 002cec50: moved to src/taito/minigame_base.cpp (linked unit)

void func_002cf170(u32 a0, u32 a1, u32 a2);  // 002cf170: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002cf1b8(u32 a0);  // 002cf1b8: moved to src/taito/minigame_base.cpp (linked unit)

void func_002cf280(u32 a0, u32 a1, u32 a2);  // 0x002cf280: definition moved into src/anon/unit_002cf260.cpp

void func_002cf2d8();  // 0x002cf2d8: definition moved into src/anon/unit_002cf260.cpp

void duplicate_unplaced_002cff00(u32 a0) {
    func_001b3b70(a0);
    *(u32*)a0 = (u32)D_00361fc8;
    func_002cf268(a0 + 2800, 0);
    *(u32*)(a0 + 1416) |= 0x08000000u;
    func_002cff50(a0);
}

void func_002d0b88(u32 a0, u32 a1);  // 0x002d0b88: definition moved into src/anon/unit_002cf260.cpp

void func_002d0bd8(u32 a0, u32 a1);  // 0x002d0bd8: definition moved into src/anon/unit_002cf260.cpp

void duplicate_unplaced_002d0ef0(u32 a0, u32 a1, u32 a2, u32 a3) {
    func_00177dc8(a0, a1, 11, a2, a3);
    *(u32*)a0 = (u32)D_00362060;
    D_00362050 = a0;
    func_00182f28(a0);  // store_global_35ed04
}

void duplicate_unplaced_002d1270(u32 a0, u32 a1) {
    u32 p = func_001050d8(336);
    func_002d1550(p, a0, a1);
}

void duplicate_unplaced_002d4200(u32 a0, u32 a1, u32 a2) {
    func_002d2948(a0, a1, 1, a2);
    *(u32*)a0 = (u32)D_003621a0;
    func_002e7308(a0 + 3208);
}

void func_002d4290(u32 a0);  // 0x002d4290: definition moved into src/anon/unit_002d2498.cpp

void duplicate_unplaced_002d5d10(u32 a0, u32 a1, u32 a2) {
    func_002cfeb0(a0, a1, 1, a2);  // obj_init_field1416_bit800
    *(u32*)a0 = (u32)D_00362428;
    func_002e7308(a0 + 2872);
}

void duplicate_unplaced_002d5d50(u32 a0, u32 a1, u32 a2) {
    func_002cfeb0(a0, a1, 1, a2);  // obj_init_field1416_bit800
    *(u32*)a0 = (u32)D_00362428;
    func_002e7308(a0 + 2872);
}

u32 func_002d5cc8(u32 a0);  // 0x002d5cc8: definition moved into src/anon/unit_002d4548.cpp

void func_002d6cd8(u32 a0);  // 0x002d6cd8: definition moved into src/anon/unit_002d62d0.cpp

void func_002d6dd0(u32 a0);  // 0x002d6dd0: definition moved into src/anon/unit_002d62d0.cpp

void func_002d6d88(u32 a0, u32 a1);  // 0x002d6d88: definition moved into src/anon/unit_002d62d0.cpp

void func_002d6e60(u32 a0, u32 a1);  // 0x002d6e60: definition moved into src/anon/unit_002d62d0.cpp

void duplicate_unplaced_002daa50(u32 a0, u32 a1, u32 a2) {
    func_002cfeb0(a0, a1, 3, a2);  // obj_init_field1416_bit800
    *(u32*)a0 = (u32)D_00362858;
    func_002cf280(a0 + 2800, 1, 0);
}

void duplicate_unplaced_002daa98(u32 a0, u32 a1, u32 a2) {
    func_002cfeb0(a0, a1, 3, a2);  // obj_init_field1416_bit800
    *(u32*)a0 = (u32)D_00362858;
    func_002cf280(a0 + 2800, 1, 0);
}

void duplicate_unplaced_002dac50(u32 a0, u32 a1, u32 a2) {
    func_002cfeb0(a0, a1, 3, a2);  // obj_init_field1416_bit800
    *(u32*)(a0 + 2836) = 0;
    *(u8*)(a0 + 2840) = 0;
    *(u32*)a0 = (u32)D_003627c8;
    *(u32*)(a0 + 2844) = 0;
    func_002cf280(a0 + 2800, 1, 0);
}

void duplicate_unplaced_002daca0(u32 a0, u32 a1, u32 a2) {
    func_002cfeb0(a0, a1, 3, a2);  // obj_init_field1416_bit800
    *(u32*)(a0 + 2836) = 0;
    *(u8*)(a0 + 2840) = 0;
    *(u32*)a0 = (u32)D_003627c8;
    *(u32*)(a0 + 2844) = 0;
    func_002cf280(a0 + 2800, 1, 0);
}

f32 func_002dc100(u32 a0) {
    if (func_001c0cd8(a0) != 0) {
        return 0.0f;
    }
    if (*(u8*)(a0 + 3008) == 0) {
        return 0.0f;
    }
    return -*(f32*)(a0 + 3044);
}

void duplicate_unplaced_002dc278(u32 a0, u32 a1) {
    u32 p = func_001050d8(0x80a0);
    func_002dc4e0(p, a0, a1);
}

f32 func_002dd250(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    u32 p = func_002dc7c8();
    s0 <<= 2;
    s0 = s0 + p;
    return *(f32*)(s0 + 16);
}

f32 func_002dd280(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    u32 p = func_002dc7c8();
    s0 <<= 2;
    s0 = s0 + p;
    return *(f32*)(s0 + 64);
}

f32 func_002dd2b0() {
    u32 p = func_002dc7c8();
    return *(f32*)(p + 116);
}

f32 func_002dd348(u32 a0, f32 a1) {
    f32 lo;
    f32 hi;
    f32 x = a1;

    func_002dd2d8(a0, (u32)&lo, (u32)&hi);

    if (hi < x) {
        x = hi;
    }
    if (x < lo) {
        x = lo;
    }
    return x;
}

void func_002dd4a8(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    func_001d9050(s1, 0, 0.0f);

    u32 t6 = 0x8000;
    s0 = s0 + t6;

    u32 v = *(u32*)(s0 + 116);
    v = v + s1;
    *(u32*)(s0 + 116) = v;
}

f32 func_002de6e8(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_0016bc20(a0, 2, 0xffffffffu);

    u32 w[6];
    w[3] = 0;
    func_0018a818((u32)w, s0, v0);

    return *(f32*)&w[5] - *(f32*)&w[2];
}

void func_002e13d8(u32 a0) {
    func_002e7108(*(u32*)(a0 + 112), *(f32*)(a0 + 120));
}

// 002e3980: moved to src/anon/unit_002e2f08.cpp

// 002e3b08: moved to src/anon/unit_002e2f08.cpp

// 002e3b48: moved to src/anon/unit_002e2f08.cpp

// 002e3be8: moved to src/anon/unit_002e2f08.cpp

void func_002e40a8(u32 a0, u32 a1) {
    volatile f32* s = (volatile f32*)a1;
    f32 f0 = s[3];
    f32 f1 = s[0];
    f32 f2 = s[1];
    f32 f3 = s[2];
    *(volatile f32*)(a0 + 12) = f0;
    *(volatile f32*)(a0 + 0) = f1;
    *(volatile f32*)(a0 + 4) = f2;
    *(volatile f32*)(a0 + 8) = f3;
}

u32 func_002e44c0(u32 a0, f32 a1) {  // vec4_scale
    *(f32*)(a0 + 0) *= a1;
    *(f32*)(a0 + 4) *= a1;
    *(f32*)(a0 + 8) *= a1;
    *(f32*)(a0 + 12) *= a1;
    return a0;
}

f32 func_002e49a8(u32 a0, u32 a1) {  // vec4_dot_2
    f32* p = (f32*)a0;
    f32* q = (f32*)a1;
    return p[0] * q[0] + p[1] * q[1] + p[2] * q[2] + p[3] * q[3];
}

u32 func_002e64b8(s32 a0, u32 a1) {  // list_advance_count
    u32 v0 = a1 + 16;
    if (a0 > 0) {
        do {
            u32 t = *(u32*)(v0 + 12);
            a0 -= 1;
            v0 = v0 + t;
        } while (a0 != 0);
    }
    return v0;
}

u32 func_002e9a38(u32* a0, u32 a1, u32 a2);  // 002e9a38: moved to src/anon/unit_002e9a00.cpp

void func_002e9cb8(u8* a0, u32 a1, u32 a2);  // 002e9cb8: moved to src/anon/unit_002e9a00.cpp

void duplicate_unplaced_002ead20(u32 a0, u32 a1) {
    u32 t6 = *(u32*)a0;
    Fn_002ead20 fn = *(Fn_002ead20*)(t6 + 36);
    fn(a0, a1, 43);
}

extern "C" u32 func_002cbed8(...);
// 002eb1a0: moved to src/anon/unit_002eaf38.cpp

// 002eb990: moved to src/anon/unit_002eaf38.cpp

// 002ebc38: moved to src/anon/unit_002eaf38.cpp

// 002ec5b0: moved to src/anon/unit_002eaf38.cpp

void duplicate_unplaced_002ecdb0(u32 a0) {
    u32 t6 = *(u32*)a0;
    Fn_002ecdb0 fn = *(Fn_002ecdb0*)(t6 + 36);
    fn(a0);
}

void duplicate_unplaced_002ecdf8(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    func_00195858((void*)(s1 + 272), 60);
    u32 t6 = *(u32*)s0;
    Fn_002ecdf8 fn = *(Fn_002ecdf8*)(t6 + 36);
    fn(s0, s1);
}

void duplicate_unplaced_002ece48(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    func_00195858((void*)(s1 + 272), 63);
    u32 t6 = *(u32*)s0;
    Fn_002ece48 fn = *(Fn_002ece48*)(t6 + 36);
    fn(s0, s1);
}

void duplicate_unplaced_002ed438() {
    u32 s0 = func_001050d8(2560);
    u32 v0 = func_0016e920(1475);
    func_002ed300(s0, v0, 256);
}

void func_002ed478() {
    u32* base = (u32*)0x00360000;
    u32 s0 = *(u32*)((u8*)base + 14152);
    if (s0 != 0) {
        Fn_002ed478 fn = *(Fn_002ed478*)(*(u32*)s0 + 32);
        fn(s0);
        *(u32*)((u8*)base + 14152) = 0;
    }
}

void duplicate_unplaced_002ed508(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s1 = a2;
    u32 s0 = a0;
    func_001c1748(s0, *(u32*)(a1 + 2548), a3, a4);  // obj_init_from_src
    *(u32*)(s0 + 80) = s1;
    func_00190128(s0 + 100);
    *(u32*)(s0 + 120) = 0;
}

void duplicate_unplaced_002ed558(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s1 = a2;
    u32 s0 = a0;
    func_001c1748(s0, *(u32*)(a1 + 2548), a3, a4);  // obj_init_from_src
    *(u32*)(s0 + 80) = s1;
    func_00190128(s0 + 100);
    *(u32*)(s0 + 120) = 0;
}

void func_002edaf8(f32* a0) {
    f32 f1 = 0.0f;
    f32 f0 = a0[0];
    if (f1 < f0) {
        a0[0] = f1;
        func_001991a8(151, 0);
    }
}

void func_002edbb0() {
    u32* base = (u32*)0x00360000;
    u32 s0 = *(u32*)((u8*)base + 14288);
    if (s0 != 0) {
        func_002eda30(s0);
        func_00106420(s0);
    }
}

void func_002edfa8(u32* a0, u32 a1) {
    u32* t7 = (u32*)((u8*)a0 + 8);
    u32 t6 = t7[1];
    if (t6 == 0) {
        t7[1] = a1;
        a0[2] = a1;
        *(u32*)(a1 + 32) = 0;
        goto L_c4;
    }
    *(u32*)(t6 + 32) = a1;
    *(u32*)(a1 + 32) = 0;
    t7[1] = a1;
L_c4:
    *(u32*)(a1 + 28) = (u32)a0;
}

// 002efa40: moved to src/anon/unit_002ef938.cpp

// 002efb88: moved to src/anon/unit_002ef938.cpp

// 002efc70: moved to src/anon/unit_002efbb8.cpp

void duplicate_unplaced_002f0798(u32* a0) {
    u32 t7 = a0[0];
    u32 v0 = func_0010c7e8(*(u32*)(t7 + 4));
    u32 t6 = *(u32*)v0;
    Fn_002f0798 fn = *(Fn_002f0798*)(t6 + 40);
    fn(v0);
}

void duplicate_unplaced_002f07c8(u32* a0) {
    u32 t7 = a0[0];
    u32 v0 = func_0010c7e8(*(u32*)(t7 + 4));
    u32 t6 = *(u32*)v0;
    Fn_002f07c8 fn = *(Fn_002f07c8*)(t6 + 44);
    fn(v0);
}

extern "C" u32 func_0011a430(...);
// 002f0c90: moved to src/naka/libkn/trapfunctions.cpp

// 002f11d0: moved to src/naka/libkn/trapfunctions.cpp

void func_002f1460(u32* a0, u32 a1, f32 f12, f32 f13, f32 f14, f32 f15) {
    a0[3] = a1;
    a0[5] = 0;
    *(f32*)((u8*)a0 + 0) = f12;
    *(f32*)((u8*)a0 + 4) = f13;
    *(f32*)((u8*)a0 + 8) = f14;
    *(f32*)((u8*)a0 + 16) = f15;
}

u32 func_002f18c8(u8* a0) {
    u32* p = (u32*)0x01e30000;
    u32 v0 = func_00168b38(p[-4044], 24, (u32)a0[3]);  // entry_array_find_nth
    u32 t7 = 0;
    if (v0 != 0) {
        t7 = *(u32*)(v0 + 8);
    }
    return t7;
}

void func_002f1900(u32* a0, u32 a1, u32 a2) {
    u32* s0 = a0;
    u32 a0c = a2;
    if (s0[0] == 0) {
        u32 v0 = func_0016ac38(a0c, a1, 1, 0, 0);
        s0[0] = v0;
    }
}

extern "C" void func_002f1990(...);
void func_002f1940(u32* a0) {
    u32* s0 = a0;
    u32 t7 = a0[0];
    if (t7 != 0) {
        if (func_001dc9d0(t7) == 0) {
            func_002f1990((u32)s0);
        }
    }
}

void func_002f1a38(u32* a0) {
    u32 t7 = a0[0];
    if (t7 != 0) {
        func_001dc818(t7);
    }
}

void duplicate_unplaced_002f5c48(u32 a0, ...) {
    volatile u8 pad[64];
    (void)pad;
    va_list ap;
    va_start(ap, a0);
    va_end(ap);
}

void func_002fd160() {
    func_002fed10(6u);
    func_001002a0(1u);
}

s32 func_002fd178(s32 a0) {
    if (a0 < 0) {
        a0 = -a0;
    }
    return a0;
}

void func_002fd310(u8* a0, u32 a1) {
    a1 = a1 - 1u;
    if (a1 == 0xFFFFFFFFu) {
        return;
    }

    while (1) {
        *a0 = 0;
        a1 = a1 - 1u;
        if (a1 != 0xFFFFFFFFu) {
            a0 = a0 + 1;
            continue;
        }
        break;
    }
}

u32 func_002fdf88(void* a0, u32 a1, ...) {
    va_list ap;
    va_start(ap, a1);
    u32 v0 = _vfprintf_r((u32)a0, *(u32*)((u8*)a0 + 8), a1, (void*)ap);
    va_end(ap);
    return v0;
}

u32 func_002fdfc8(u32 a0, ...) {  // device_vprintf_va
    va_list ap;
    va_start(ap, a0);

    u32 t6 = D_00365c48;
    u32 t4 = *(u32*)(t6 + 8u);
    *(u32*)(t4 + 84u) = t6;

    u32 v0 = func_002ffd00(t4, a0, (void*)ap);  // fprintf_stream_va
    va_end(ap);
    return v0;
}

void func_002fea70(s32* a0, u32 a1) {
    D_00378ae4 = 0;
    s32 v0 = func_00305d20(a1);
    if (v0 == -1) {
        s32 t7 = D_00378ae4;
        if (t7 != 0) {
            *a0 = t7;
        }
    }
}

s32 func_00303958(u32 a0, u32* a1, u8* a2, u32 a3) {
    (void)a0;
    s32 v0 = 0;
    u32 tmp;

    if (a2 == 0) {
        return v0;
    }

    if (a1 == 0) {
        a1 = &tmp;
    }

    if (a3 == 0) {
        return -1;
    }

    u8 t7 = a2[0];
    *a1 = (u32)t7;
    u8 t6 = a2[0];
    v0 = (t6 != 0) ? 1 : 0;
    return v0;
}

void func_00305068(s32* a0, u32 a1) {
    D_00378ae4 = 0;
    s32 v0 = func_00305d08(a1);
    if (v0 == -1) {
        s32 t7 = D_00378ae4;
        if (t7 != 0) {
            *a0 = t7;
        }
    }
}

void func_0030e508(u32 a0, u32 a1, u32 a2) {
    u8 pad[16];
    func_0030df38(a0, a1, a2, pad);
}

void func_0030e770(u32 a0, u32 a1, u32 a2) {
    u8 pad[16];
    func_0030e548(a0, a1, a2, pad, 0);
}

extern "C" u32 func_00305a50(...);
u32 func_00311028(u32 a0) {
    u32 v = a0;
    return func_00305a50(2, &v);
}

void func_00311080(u32 a0) {
    u32 args[1];
    args[0] = a0;
    func_00305a50(4, args);
}

void func_003110d8(u32 a0) {
    u32 args[1];
    args[0] = a0;
    func_00305a50(33, args);
}

void func_003111a0(u32 a0) {
    u32 args[1];
    args[0] = a0;
    func_00305a50((u32)-8, args);
}

void func_003111c8(u32 a0) {
    u32 args[1];
    args[0] = a0;
    func_00305a50((u32)-9, args);
}

void func_003111f0(u32 a0) {
    u32 args[1];
    args[0] = a0;
    func_00305a50(16, args);
}

u64 __umoddi3(u32 a0, u32 a1) {
    u64 out;
    func_003134b8(a0, a1, &out);
    return out;
}

void func_00313b80(f32 a0) {  // float_to_double
    u32 tmp[4];
    f32 in = a0;
    func_00314640((u32)&in, (u32)tmp);
    func_00314480(tmp[0], tmp[1], tmp[2], ((unsigned long long)tmp[3]) << 30);
}

void func_003142e0(u64 a0, u64 a1) {  // double_compare
    u32 out0[8];
    u32 out1[8];
    u64 in0 = a0;
    u64 in1 = a1;
    func_003147a0((u32)&in0, (u32)out0);
    func_003147a0((u32)&in1, (u32)out1);
    func_00314830((u32)out0, (u32)out1);
}

void func_00314698(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 args[4];
    args[0] = a0;
    args[1] = a1;
    args[2] = a2;
    args[3] = a3;
    func_00314930((u32)args);
}

void duplicate_unplaced_003191d0(u32* a0, u32 a1, unsigned long long a2) {
    *(unsigned long long*)a0[a1] = a2;
}

void func_00319d30(u32* a0) {
    s32 t7 = 3;
    do {
        *a0 = 0;
        t7 -= 1;
        a0 += 1;
    } while (t7 >= 0);
}

void func_0031a260(u8* s0, u32 a1) {
    while (1) {
        *(u32*)(s0 + 0x18c) = a1;
        func_001396b0((u32)s0);
        if (*(u32*)(s0 + 0x18c) == 0) {
            break;
        }
        *(u32*)(s0 + 0x190) = 0;
        func_001396b0((u32)s0);
        if (*(u32*)(s0 + 0x190) == 0) {
            break;
        }
        a1 = 0;
    }
}

extern "C" void func_0031a260(...);
void func_0031ac78(u8* a0, u32 a1) {
    *(u32*)(a0 + 0x190) = a1;
    func_001396b0((u32)a0);
    if (*(u32*)(a0 + 0x190) != 0) {
        func_0031a260((u32)a0, 0);
    }
}

void func_003200c0(u32* a0) {
    s32 t5 = 0;
    u32* t6 = (u32*)((u8*)a0 + 640);
    while (1) {
        *t6 = (u32)t5;
        t5 += 1;
        if (t5 >= 16) {
            break;
        }
        t6 += 1;
    }
    a0[704 / 4] = 16;
}

void func_00320418(u32* a0) {
    s32 t5 = 0;
    u32* t6 = (u32*)((u8*)a0 + 160);
    while (1) {
        *t6 = (u32)t5;
        t5 += 1;
        if (t5 >= 8) {
            break;
        }
        t6 += 1;
    }
    a0[192 / 4] = 8;
}

void func_00321198(u32* a0) {  // zero_3_words
    s32 t7 = 2;
    do {
        *a0 = 0;
        t7 -= 1;
        a0 += 1;
    } while (t7 >= 0);
}

void func_00102158(u32* a0, u32 a1) {
    u32 t7 = a0[9];
    if (t7 != 0) {
        ((void (*)(u32))t7)(a1);
    }
}

// 001033b0: Tz::MenuBase::Reset, moved to src/common/unit_001031b0.cpp

void duplicate_unplaced_0010a800(u8* a0, u8* a1, u8* a2) {
    *a0 = D_00340ed0[0];
    *a1 = D_00340ed0[1];
    *a2 = D_00340ed0[2];
}

void func_0010a8a8(f32 f12, f32 f13);  // 0010a8a8: moved to src/anon/unit_00109c30.cpp

void func_0010a8e0(f32* a0);  // 0010a8e0: moved to src/anon/unit_00109c30.cpp

void duplicate_unplaced_0010c7f0(C7F0_State* a0) {
    C7F0_State* s0 = a0;
    func_0017dbb8((u32)a0);
    C7F0_Obj* a4 = s0->obj;
    a4->vtbl->fn5(a4);
}

void duplicate_unplaced_0010c828(C828_State* a0) {
    C828_Obj* a4 = a0->obj;
    a4->vtbl->fn6(a4);
}

void func_0010cac8(u8* a0, u32 a1, f32 f12);  // 0x0010cac8: definition moved into src/anon/unit_0010b978.cpp

void duplicate_unplaced_0010dee8(u32 a0, u32* a1, u32* a2) {
    (void)a0;
    a2[0] = a1[0];
    a2[1] = a1[1];
    a2[2] = a1[2];
    a2[3] = a1[3];
    a2[4] = a1[4];
}

f32 func_0010e7e0(u8* a0, u32 a1);  // 0x0010e7e0: definition moved into src/anon/unit_0010dee8.cpp

void func_0010eee8(u8* a0);  // 0x0010eee8: definition moved into src/anon/unit_0010dee8.cpp

void duplicate_unplaced_0010ef28(u8* a0, u32 a1) {
    u32 t7;
    u8* t6 = a0 + 8;
    t7 = *(u32*)(t6 + 0xc50);
    *(u32*)(t6 + 0xc54) = t7;
    t6 = a0 + 4;
    t7 = *(u32*)(t6 + 0xc50);
    *(u32*)(t6 + 0xc54) = t7;
    *(u32*)(a0 + 0xc54) = a1;
}

s32 func_00114690(u32 a0);  // 0x00114690: definition moved into src/anon/unit_001142a0.cpp

void duplicate_unplaced_0011c4b0(C4B0_State* a0) {
    C4B0_State* s0 = a0;
    func_0011d440((u32)a0);
    C4B0_Obj* a4 = s0->obj;
    a4->vtbl->fn11(a4, s0);
}

u32 func_001208b8(u8* a0);  // 0x001208b8: definition moved into src/anon/unit_00120520.cpp

void func_00127cf8(u32 a0);  // 0x00127cf8: definition moved into src/anon/unit_00127a88.cpp

void func_00133690(u32 a0) {
    u32 s0 = a0;
    if (*(u8*)(a0 + 0) != 0) {
        *(u8*)(a0 + 0) = 0;
        goto call;
    }
    *(u8*)(a0 + 0) = 1;
call:
    u32 v0 = func_001336f8(s0);
    *(u32*)(s0 + 24) = v0;
    *(u32*)(s0 + 20) = 0;
}

u32 duplicate_unplaced_00133938(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    *(u8*)(*(u32*)(a0 + 0) + 2) = 0;
    *(u32*)(*(u32*)(a0 + 0) + 8) = a3;
    *(u32*)(*(u32*)(a0 + 0) + 12) = a4;
    *(u8*)(*(u32*)(a0 + 0) + 3) = 32;
    *(u32*)(*(u32*)(a0 + 0) + 4) = a1;
    volatile u32* q = (volatile u32*)a0;
    u32 t7 = q[0];
    *(volatile u16*)(t7 + 0) = (u16)a2;
    u32 v0 = q[0];
    *(u32*)(a0 + 0) = a1;
    return v0 + 16;
}

u32 duplicate_unplaced_00133980(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 ofs = a2 << 4;
    *(u8*)(*(u32*)(a0 + 0) + 2) = 0;
    *(u32*)(*(u32*)(a0 + 0) + 8) = a3;
    *(u32*)(*(u32*)(a0 + 0) + 12) = a4;
    *(u8*)(*(u32*)(a0 + 0) + 3) = 80;
    *(u32*)(*(u32*)(a0 + 0) + 4) = a1;
    volatile u32* q = (volatile u32*)a0;
    u32 t7 = q[0];
    *(volatile u16*)(t7 + 0) = (u16)a2;
    u32 v0 = q[0];
    u32 next = v0 + ofs;
    next += 16;
    v0 += 16;
    *(u32*)(a0 + 0) = next;
    return v0;
}

u32 duplicate_unplaced_001339d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 v0 = a1;
    *(u8*)(*(u32*)(a0 + 0) + 2) = 0;
    *(u32*)(*(u32*)(a0 + 0) + 8) = a3;
    *(u32*)(*(u32*)(a0 + 0) + 12) = a4;
    *(u8*)(*(u32*)(a0 + 0) + 3) = 48;
    *(u32*)(*(u32*)(a0 + 0) + 4) = a1;
    volatile u32* q = (volatile u32*)a0;
    u32 t5 = q[0];
    *(volatile u16*)(t5 + 0) = (u16)a2;
    u32 t7 = q[0];
    t7 += 16;
    *(u32*)(a0 + 0) = t7;
    return v0;
}

u32 duplicate_unplaced_001344b8(u32 a0) {
    u32 a2 = a0 | 0x03000000u;
    u32 a3 = ((1024u - a0) >> 1) | 0x02000000u;
    return func_00133bb8((u32)&D_00347c88, 0, a2, a3);  // forward_sub24_to_133848
}

void func_00137840(u32 a0, u32 a1);  // 0x00137840: definition moved into src/anon/unit_001374c8.cpp

u32 duplicate_unplaced_001385c0() {
    D_00347e08 = 0;
    u32 a2 = (u32)&D_001384d0;
    u32 a3 = 4096;
    u32 a0 = 1;
    u32 a1 = 0x0004baf0u;
    return func_00102c48(a0, a1, a2, a3);
}

u32 duplicate_unplaced_00138650(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s1 = a2;
    u32 s0 = a0;
    func_001391c8(a0, a1, a3);
    s0 += 32;
    func_002362b0(s0, s1);
    return func_002367c8(s0);  // obj_dispatch_bitfield64
}

void duplicate_unplaced_001387f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    u32 s0 = a0;
    u32 s1 = a3;
    func_00239988(a0 + 24);
    func_00138c10(s0, s1);
    *(u32*)(s0 + 392) = 0xFFFFFFFFu;
}

void func_0013c900(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013c900: definition moved into src/anon/unit_0013a8b8.cpp

extern "C" u32 func_00142900(...);
void duplicate_unplaced_001434d0(u32 a0) {
    func_00142900(D_00348804, 0, a0);
}

void func_00143ee8(u32 a0, u32 a1);  // 0x00143ee8: definition moved into src/anon/unit_00142c90.cpp

void func_00143f78(u32 a0, u32 a1);  // 0x00143f78: definition moved into src/anon/unit_00142c90.cpp

void func_00146e28(u32 a0, u32 a1) {
    union Cnt {
        u32 w;
        u16 h;
    };
    Cnt* c = (Cnt*)(a0 + 21344);

    u16 t7 = c->h;
    *(u16*)(a1 + 284) = t7;

    u32 t6 = c->w;
    u32 t7w = t6 << 3;
    t7w += a0;
    u32 t6n = t6 + 1;
    *(u32*)(t7w + 17248) = a1;
    c->w = t6n;

    u32 t5 = *(u32*)(a0 + 4);
    u32 t7i = *(u16*)(a1 + 280);
    t7i *= 48;
    t5 += t7i;
    u32 t6v = *(u32*)(t5 + 44);
    *(u32*)(a1 + 272) = t6v;
    *(u32*)(t5 + 44) = a1;
}

void func_00146e88(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 248);
    u32 t6 = t7 & 8;
    t7 &= 4;
    if (t7 == 0) {
        if (t6 == 0) {
            return;
        }
    }
    u32 t6w = *(u32*)(a0 + 21344);
    t6w <<= 3;
    t6w = add_lhs(a0, t6w);
    u32 t7w = *(u32*)(t6w + 17252);
    t7w |= 2;
    *(u32*)(t6w + 17252) = t7w;
    func_00146e28(a0, a1);
}

void func_0014c970(u32 a0) {
    a0 = a0 * 60;
    *(u8*)&D_00349e00 = 0;
    D_00349df4 = a0;
    D_00349dfc = 0;
    D_00349df8 = 0;
}

void func_0014c9b8() {
    u32 t5 = D_00349de8;
    u32 t4 = 1;
    D_00349df0 = t5;
    D_00349dfc = t4;
}

u32 duplicate_unplaced_0014ca20() {
    u32 v = D_00349df8;
    D_00349dfc = 0u;
    return v;
}

extern "C" u32 func_0014f0b0(...);
u32 func_0014cd98(u32 a0) {
    if (func_0014f0b0(&D_004574b8) == 0u) {
        func_001024a8(a0);
    }
    return func_0014ce50(*(f32*)&D_004574b8);
}

extern "C" void func_0014fdd0(...);  // entry_clear_by_fields
void func_001502e8(Obj001502e8* a0) {
    func_0014fdd0((u32)a0);  // entry_clear_by_fields
    if (a0 != 0) {
        a0->vtbl->fn10(a0);
    }
}

void func_00152498(Obj00152498* a0, u32 a1) {
    if (a0->field_b4c != a1) {
        func_00138c10((u8*)a0 + 48, (a0->field_b4c = a1, 48));
        func_00152120((u32)a0);
    }
}

void func_001535f0(f32 a0, f32 a1, f32 a2) {
    *(f32*)&D_0034a780 = a0;
    *(f32*)&D_0034a784 = a1;
    *(f32*)&D_0034a788 = a2;
}

void func_001537f8() {
    u32 v = D_0034a790;
    if (v != 0) {
        Obj001537f8* o = (Obj001537f8*)D_0034a78c;
        o->vtbl->fn4(o, v);
        D_0034a790 = 0;
    }
}

void duplicate_unplaced_00155410(u8* a0) {
    u32 p15 = *(u32*)(a0 + 52);
    u32 p14 = *(u32*)(p15 + 1164);
    u32 v = *(u32*)p14;
    *(u32*)(a0 + 40) = v;
    u32 m = (*(u32*)(a0 + 36) = v, func_00154ee8((u32)a0));  // field24_state_code
    func_00138c10(a0 + 916, m);
    func_00154408((u32)(a0 + 64), *(u32*)(a0 + 24));
}

// 001570d0: moved to src/anon/unit_00153ea0.cpp
u32 func_001570d0(u8* a0);

// 00157100: moved to src/anon/unit_00153ea0.cpp
u32 func_00157100(u8* a0);

// 00157130: moved to src/anon/unit_00153ea0.cpp
u32 func_00157130(u8* a0);

// 00159f50: moved to src/harata/libdk/targetcamera.cpp

void duplicate_unplaced_0015a810() {
    Obj0015a810* o = func_001050c8();
    D_0034aa90 = o->vtbl->fn0(o, 2048, 0);
}

void func_0015a850();  // 0x0015a850: definition moved into src/anon/unit_0015a810.cpp

void duplicate_unplaced_0015b4c0(u32 a0) {
    Obj0015b4c0* o = func_001050c8();
    o->vtbl->fn4(o, a0);
}

// 0015de58: moved to src/anon/unit_0015d828.cpp

void duplicate_unplaced_001618b8() {
    u8* p = (u8*)func_00102c18(1, 0x00016b48u, &D_001dda78);
    *(u32*)(p + 48) = (u32)&D_001ddb30;
}

void func_00161c20(u32 a0) {
    func_00161aa8(a0);
    if (D_0034c770 != 0u) {
        return;
    }
    D_0034c778 = 0;
    func_001024a8(a0);
}

void duplicate_unplaced_00161ee8() {
    D_0034c770 = 0;
    D_0034c771 = 0;
    D_0034c774 = 0;
    D_0034c778 = 0;
}

void func_0019f790();  // 0x0019f790: definition moved into src/anon/unit_0019ee80.cpp

u32 func_0019f880();  // 0x0019f880: definition moved into src/anon/unit_0019ee80.cpp

u32 func_0019fa08(u8* a0, u32 a1, u32 a2);  // 0x0019fa08: definition moved into src/anon/unit_0019ee80.cpp

u32 func_0019fe48(u32 a0, u32, u32 a2);  // 0x0019fe48: definition moved into src/anon/unit_0019fb70.cpp

void func_001a0400(u32* param_1);  // 0x001a0400: definition moved into src/anon/unit_0019fb70.cpp

void func_001a0420(u32* param_1);  // 0x001a0420: definition moved into src/anon/unit_0019fb70.cpp

void duplicate_unplaced_001a04f8(u32* param_1) {
    func_001d8fa8(param_1[0] != 0u, param_1[1]);
}

void duplicate_unplaced_001a0678(u32* param_1) {
    param_1[0] = func_001d5af8(param_1[0], param_1[1], param_1[2]);
}

void duplicate_unplaced_001a06e0(u32* param_1) {
    param_1[0] = func_001d96c0(param_1[0], param_1[1]);
}

u32 duplicate_unplaced_001a07b0(u32 param_1, u32, u32 param_3) {
    u32 obj = func_0017aab8(5u);
    ((Vt_001a07b0*)(*(u32*)obj))->fn(param_1, obj, param_3);
    return param_1;
}

u32 duplicate_unplaced_001a1018(u32 param_1) {
    u32 ret = func_001a0e78(param_1);
    u32 tmp = func_001db5a8(param_1);
    func_001a0ee0(ret, tmp);
    return ret;
}

void func_001a05b8(u32* param_1);  // 0x001a05b8: definition moved into src/anon/unit_0019fb70.cpp

void func_001a1a50(u32 a0, u32 a1);  // 0x001a1a50: definition moved into src/anon/unit_0019fb70.cpp

s32 func_001a1c30(u32 a0);  // 0x001a1c30: definition moved into src/anon/unit_0019fb70.cpp

void duplicate_unplaced_001a1c70(u32 a0) {
    *(u8*)(a0 + 0x1B0) = 100;
    *(u8*)(a0 + 0x1B1) = *(u8*)(a0 + 0x1B2);
    *(u32*)(a0 + 0x1B4) = 0;
    *(u32*)(a0 + 0x1B8) = 0;
}

extern "C" void func_001a1c90(u32, u32, s32) asm("_ZN2YS5SHEET11start_driveEii");

void func_001a2438(u32 a0, u32 a1, s32 a2);  // 0x001a2438: definition moved into src/anon/unit_0019fb70.cpp

void duplicate_unplaced_001a3a50(void) {
    func_00170518(D_00350748, 1000, 0);
}

// 001a49d8: moved to src/anon/unit_001a3e70.cpp

// 001a4d40: moved to src/anon/unit_001a3e70.cpp

void duplicate_unplaced_001a5380(u32 a0, u32 a1, u32 a2) {
    func_001c79a0(a2, a1, 0);
    func_001a52a8(a0, a1, a2);
}

void duplicate_unplaced_001a53d0(u32 a0, u32 a1, u32 a2) {
    func_001c79a0(a2, a1, 1);
    func_001a52a8(a0, a1, a2);
}

// 001a5ac8: moved to src/anon/unit_001a4db0.cpp

// 001a4530: moved to src/anon/unit_001a3e70.cpp

// 001a4d78: moved to src/anon/unit_001a3e70.cpp

// 001a5bd0: moved to src/yasui/libys/prizetable.cpp

extern "C" void func_001826c8(...);
// 001a6490: moved to src/yasui/libys/magic.cpp

void duplicate_unplaced_001a6c90(u32 a0) {
    u32* p = (u32*)((u8*)&D_0032dec0 + ((a0 >> 5) << 2));
    u32 m = 1u << (a0 & 0x1Fu);
    *p = *p | m;
    func_001d59b0();
}

// 001a64c0: moved to src/yasui/libys/magic.cpp

// 001a67b0: moved to src/yasui/libys/magic.cpp

// 001a5c48: moved to src/yasui/libys/magic.cpp

// 001a6d38: moved to src/anon/unit_001a6a10.cpp

// 001a6d68: moved to src/anon/unit_001a6a10.cpp

// 001a6d98: moved to src/anon/unit_001a6a10.cpp

// 001a75d8: moved to src/yasui/libys/bg.cpp

// 001a7888: moved to src/yasui/libys/bg.cpp

// 001a8020: static initialiser, now made by gcc in src/yasui/libys/bg.cpp

// 001a8110: moved to src/anon/unit_001a8098.cpp

// 001a84b0: moved to src/anon/unit_001a82f0.cpp
u8* func_001a84b0(void);

// func_001a84b0 returns u8* but callers treat return value as u32 (pointer-as-integer).
// Provide a u32-returning wrapper used by subsequent callers via macro.
static inline u32 _func_001a84b0_as_u32() { return (u32)((u8*(*)())func_001a84b0)(); }
#define func_001a84b0 _func_001a84b0_as_u32

u32 duplicate_unplaced_001a84f0(void) {
    u32* p = &D_01c6cba0;
    return p[1] == p[0];
}

void duplicate_unplaced_001a8548(void) {
    u32 p = func_001a84b0();
    func_00138190(*(u32*)(p + 0), *(u32*)(p + 8));
}
#undef func_001a84b0

void duplicate_unplaced_001a8ff8(u32 a0, u32 a1, u32 a2) {
    u8 t = *(u8*)(a0 + a1);
    *(u8*)(a0 + a1) = *(u8*)(a0 + a2);
    *(u8*)(a0 + a2) = t;
}

u32 duplicate_unplaced_001a91c8(u32 a0) {
    u32* p = (u32*)((u8*)&D_0032df30 + ((a0 >> 5) << 2));
    u32 m = 1u << (a0 & 0x1Fu);
    return ((*p & m) != 0u);
}

u32 duplicate_unplaced_001aa6f0(u32 a0, u32 a1) {
    u32 v = ((a1 >> 24) * (u32)*(u8*)(a0 + 0x3F)) >> 7;
    if (v > 0xFFu) {
        v = 0xFFu;
    }
    return (a1 & 0x00FFFFFFu) | (v << 24);
}

u32 func_001aa688(u32 a0);  // 0x001aa688: definition moved into src/anon/unit_001a9130.cpp

void duplicate_unplaced_001abb28(u32* a0) {
    a0[0] = 0;
    u32 p = (u32)(a0 + 5);
    func_00239700(p);
    u32 x = func_001ab810();  // get_global_1c7cec0
    u32 y = func_001ab800();
    func_00239988(p, x, y);
}

extern "C" void func_00239bf8(...);

// 001abe48: moved to src/anon/unit_001abb28.cpp

void duplicate_unplaced_001abfd8(u8* a0) {
    a0[0] = 0;
    u32 p = (u32)(a0 + 4);
    func_00239700(p);
    u32 x = func_001ab810();  // get_global_1c7cec0
    u32 y = func_001ab800();
    func_00239988(p, x, y);
}

void duplicate_unplaced_001ac028(u8* a0) {
    a0[0] = 0;
    u32 p = (u32)(a0 + 4);
    func_00239700(p);
    u32 x = func_001ab810();  // get_global_1c7cec0
    u32 y = func_001ab800();
    func_00239988(p, x, y);
}

// 001ac0d0: moved to src/anon/unit_001abb28.cpp

void duplicate_unplaced_001ac208(u32* a0) {
    a0[0] = 0;
    u32 p = (u32)(a0 + 3);
    func_00239700(p);
    u32 x = func_001ab810();  // get_global_1c7cec0
    u32 y = func_001ab800();
    func_00239988(p, x, y);
}

void duplicate_unplaced_001ac258(u32* a0) {
    a0[0] = 0;
    u32 p = (u32)(a0 + 3);
    func_00239700(p);
    u32 x = func_001ab810();  // get_global_1c7cec0
    u32 y = func_001ab800();
    func_00239988(p, x, y);
}

void duplicate_unplaced_001ac660(u32 a0) {
    u32 s0 = a0;
    *(u32*)s0 = (u32)&D_00350c50;
    func_0031fe00((u32)&D_01c6ced0, s0);
    func_00105110(s0);
}

// 001ac728: moved to src/anon/unit_001abb28.cpp

void duplicate_unplaced_001ad3e0(u32 a0) {
    u32 a3 = *(u32*)(a0 + 92) >> 1;
    u32 t0 = *(u32*)(a0 + 96) >> 1;
    u32 a1 = *(u32*)(a0 + 4);
    u32 a2 = *(u32*)(a0 + 8);
    {
        u32 t1 = a1;
        u32 t2 = a3;
        a3 = t1 + t2;
    }
    {
        u32 t1 = a2;
        u32 t2 = t0;
        t0 = t1 + t2;
    }
    func_001acdc0(a0, a1, a2, a3, t0, 432);
    func_001ac310(a0 + 0xB6C);
}

void duplicate_unplaced_001ad5a8(void* a0) {
    u8* base = (u8*)0x00350000;
    u32 one = 1;
    func_001ad280(a0);
    *(u32*)a0 = (u32)&D_00350a70;
    base[0x0A56] = (u8)one;
    func_001c1130(12);  // copy_record_block_to_table
    func_0014c9d8(8);
}

void duplicate_unplaced_001ad5f0(void* a0) {
    u8* base = (u8*)0x00350000;
    u32 one = 1;
    func_001ad280(a0);
    *(u32*)a0 = (u32)&D_00350a70;
    base[0x0A56] = (u8)one;
    func_001c1130(12);  // copy_record_block_to_table
    func_0014c9d8(8);
}

void func_001adc08(u32* a0, u32* a1, u32* a2);  // 0x001adc08: definition moved into src/anon/unit_001ada38.cpp

void func_001af2e8();  // 0x001af2e8: definition moved into src/anon/unit_001ada38.cpp

void duplicate_unplaced_001af328(u32 a0) {
    u32 s0 = a0;
    u32 p = func_001050d8(80);
    func_001aedf8(p, s0, 2);
}

void duplicate_unplaced_001af360(u32 a0) {
    u32 s0 = a0;
    u32 p = func_001050d8(80);
    func_001aedf8(p, s0, 3);
}

void func_001af9f8();  // 0x001af9f8: definition moved into src/anon/unit_001ada38.cpp

// 001b0700: moved to src/yasui/libys/lookat.cpp

void func_001b1328(u32 a0);

// 001b1400: moved to src/yasui/libys/databuff.cpp

// 001b1b58: moved to src/anon/unit_001b14d8.cpp

// 001b1c10: moved to src/anon/unit_001b14d8.cpp

// 001b2028: moved to src/anon/unit_001b1d20.cpp

u32 func_001b2b58(u8* a0);  // 0x001b2b58: definition moved into src/anon/unit_001b2780.cpp

void duplicate_unplaced_001b3bb8(u8* a0) {
    u8* s0 = a0;
    func_00185ed8((u32)s0);
    u32 v = *(u32*)(s0 + 1420);
    u32 p = (u32)((u8*)&D_00350000 + 4352u);
    *(u32*)(s0 + 2796) = 0;
    v |= 2;
    *(u32*)(s0 + 0) = p;
    *(u32*)(s0 + 1420) = v;
    *(u32*)(s0 + 2788) = 0;
}

void func_001b3cb0(u8* a0, u32 a1);  // 0x001b3cb0: definition moved into src/anon/unit_001b2780.cpp

void func_001b4098(u8* a0, u32 a1, u32 a2);  // 0x001b4098: definition moved into src/anon/unit_001b2780.cpp

void func_001b5970(u32 a0, u32 a1);  // 0x001b5970: definition moved into src/anon/unit_001b2780.cpp

void func_001b59c0(u32 a0, u32 a1, u32 a2);  // 0x001b59c0: definition moved into src/anon/unit_001b2780.cpp

void func_001b5a60(u32 a0, u32 a1, u32 a2);  // 0x001b5a60: definition moved into src/anon/unit_001b2780.cpp

void func_001b5ab0();  // 0x001b5ab0: definition moved into src/anon/unit_001b2780.cpp

void duplicate_unplaced_001b6c60(u8* a0) {
    u8* s0 = a0;
    func_001b0330(*(u32*)(a0 + 2488));
    u8* b = (u8*)0x00330000;
    b[-4012] = 0;
    u32 p = func_001050d8(32);
    func_001b6298(p, (u32)s0, 0, 0);
}

u32 func_001b73e8(u8* a0, u32 a1);  // 0x001b73e8: definition moved into src/anon/unit_001b6a50.cpp

u32 duplicate_unplaced_001b7428(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_001a3a78(s0);
    return func_001de168(v0, 15, 1, 1, 10005, s0);  // scan_list_by_half
}

u32 duplicate_unplaced_001b7468(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_001a3a78(s0);
    return func_001de168(v0, 16, 1, 1, 10005, s0);  // scan_list_by_half
}

u32 func_001b74c8(u32 a0, u32 a1);  // 0x001b74c8: definition moved into src/anon/unit_001b6a50.cpp

void func_001b7508(u32 a0, s32 a1, u32 a2);  // 0x001b7508: definition moved into src/anon/unit_001b6a50.cpp

u32 func_001b75b0(u32 a0, s32 a1);  // 0x001b75b0: definition moved into src/anon/unit_001b6a50.cpp

u32 duplicate_unplaced_001b7768(u32* a0, u32 a1) {
    u32* s0 = a0;
    u32 s1 = a1;
    u32 v0 = func_001b77a8(1);
    return func_00153468(v0, s0[0], s1);
}

s32 func_001b7818(s32 a0);  // 0x001b7818: definition moved into src/anon/unit_001b6a50.cpp

// 001b82d8: moved to src/anon/unit_001b82d8.cpp

// 001b8318: moved to src/anon/unit_001b82d8.cpp

// 001bae08: moved to src/anon/unit_001ba7e0.cpp

// 001bbe18: moved to src/yasui/libys/mission.cpp

// 001bbe38: moved to src/yasui/libys/mission.cpp
void func_001bbe38(u32);

// 001bbe78: moved to src/yasui/libys/mission.cpp
void func_001bbe78(u32);

// 001bbf80: moved to src/yasui/libys/mission.cpp

u32 func_001bcf18(u32* a0);  // 0x001bcf18: definition moved into src/anon/unit_001bc568.cpp

void func_001bd370(u8* a0);  // 0x001bd370: definition moved into src/anon/unit_001bc568.cpp

extern "C" u32 func_001bde58(...);
void func_001bd3a0(u8* a0);  // 0x001bd3a0: definition moved into src/anon/unit_001bc568.cpp

void func_001bde88(u8* a0);  // 0x001bde88: definition moved into src/anon/unit_001bc568.cpp

void duplicate_unplaced_001bdf38(u32 a0) {
    u32 s0 = a0;
    func_001bd2d0(s0);
    u32 a1 = *(u32*)(s0 + 2724);
    func_001bd5b0(s0, a1, 0);
}

void duplicate_unplaced_001befa8(u32 a0) {
    u32 s0 = a0;
    func_001bdc18(s0);
    u32 a1 = *(u32*)(s0 + 2724);
    func_001bd5b0(s0, a1, 0);
}

void duplicate_unplaced_001befd8(u32 a0, u32 a1, u32 a2) {
    *(u32*)(a0 + 2728) = a1;
    *(u32*)(a0 + 2732) = a2;
    u32 s0 = a0;
    func_001bd668(s0);
    func_001bd5b0(s0, 10, 0);
}

u32 duplicate_unplaced_001bf140(u32 a0, u32 a1) {
    if (a1 == 0) {
        return 0;
    }
    u32 t6 = *(u32*)(a0 + 2736);
    u32 t7 = 1u << a1;
    t6 &= t7;
    return (u32)(0 < t6);
}

void duplicate_unplaced_001bfbd8() {
    func_0016ed50(952, -1, 30);
    func_0016ed50(953, -1, 30);
    func_0016ed50(954, -1, 30);
    func_0016ed50(955, -1, 30);
}

// 001c0ab0: moved to src/anon/unit_001c0638.cpp
void func_001c0ab0(u8* a0, u8* a1);

// 001c1218: moved to src/anon/unit_001c0638.cpp
u32 func_001c1218();

// 001c16f0: moved to src/anon/unit_001c0638.cpp
u32 func_001c16f0(u32* a0, u32* a1);

void func_001c3ca8(void* a0, u8* a1);  // 0x001c3ca8: definition moved into src/anon/unit_001c2b58.cpp

u32 duplicate_unplaced_001c4170() {
    u32 a = *(u32*)((u8*)&D_00350000 + 5636u);
    u32 b = *(u32*)((u8*)&D_00350000 + 5640u);
    return a - b;
}

void duplicate_unplaced_001c6c60(u8* a0) {
    *(u8*)(a0 + 21) = 0;
    *(u32*)(a0 + 84) = (u32)&D_001c6a28;
}

// 001c71b8: moved to src/anon/unit_001c7148.cpp (linked unit)

// 0x1c7ea8: moved to src/anon/unit_001c7bc8.cpp

void duplicate_unplaced_001c8710() {
    func_001c8d80((u8*)&D_00350000 + 7872u, 3);
    func_0014c9d8(16);
    func_001bbe38(1);
    func_0016c5b8(2, 0xFFF7FFDC);
}

void duplicate_unplaced_001c8750() {
    func_001c8d98((u8*)&D_00350000 + 7872u, 3);
    func_0014c9f0(16);
    func_001bbe78(1);
    func_0016c640(2);
}

// 0x1c8d08: moved to src/yasui/libys/summon.cpp

// 001c8db8 YS::MUTEX::is_lock: moved to src/yasui/libys/mutex.cpp (linked unit).

void duplicate_unplaced_001c8de0() {
    *(u32*)((u8*)&D_00350000 + 7864u) = 0;
    *(u32*)((u8*)&D_00350000 + 7872u) = 0;
    *(u32*)((u8*)&D_00350000 + 7880u) = 0;
}

void func_001c8e90();  // 0x001c8e90: definition moved into src/anon/unit_001c8e80.cpp

void* func_0016a070(f32);
void func_001c9780(f32 f12);  // 0x001c9780: definition moved into src/yasui/libys/sacrifice.cpp

f32 func_001ca8e0(u32 a0);  // 0x001ca8e0: definition moved into src/anon/unit_001ca8e0.cpp

void func_001ca8f8(f32 a0, f32 a1);  // 0x001ca8f8: definition moved into src/anon/unit_001ca8e0.cpp

void func_001ca910(u8* a0);  // 0x001ca910: definition moved into src/anon/unit_001ca8e0.cpp

// 001ccd78: moved to src/anon/unit_001cc868.cpp

// 001cd660: moved to src/anon/unit_001cd660.cpp
void func_001cd660(u8* a0);

u32 func_001cecc8();  // 0x001cecc8: definition moved into src/anon/unit_001ce6e8.cpp

u32 func_001cf0b0(u8* a0);  // 0x001cf0b0: definition moved into src/anon/unit_001cf0b0.cpp

u32 func_001d0820();  // 0x001d0820: definition moved into src/anon/unit_001cf0b0.cpp

void func_001d0eb8(u8* a0);  // 0x001d0eb8: definition moved into src/anon/unit_001d0cb8.cpp

void func_001d1698(u8* a0, u32 a1, u32 a2, u32 a3);  // 0x001d1698: definition moved into src/anon/unit_001d14e0.cpp

void func_001d1720(u8* a0, u32 a1);  // 0x001d1720: definition moved into src/anon/unit_001d14e0.cpp

void func_001d1950(u8* a0, s32 a1);  // 0x001d1950: definition moved into src/anon/unit_001d14e0.cpp

void func_001d1c28(u8* a0);  // 0x001d1c28: definition moved into src/anon/unit_001d14e0.cpp

void func_001d1e88(u8* a0);  // 0x001d1e88: definition moved into src/anon/unit_001d14e0.cpp

void func_001d2668(u8* a0, u32 a1, f32 a2);  // 0x001d2668: definition moved into src/anon/unit_001d14e0.cpp

void* func_001d2e28(void* a0, u32 a1, u32 a2);  // 0x001d2e28: definition moved into src/anon/unit_001d2810.cpp

// 001d32e8: moved to src/anon/unit_001d30b0.cpp

// 001d3558: moved to src/anon/unit_001d30b0.cpp

// 001d3698: moved to src/anon/unit_001d35e0.cpp

// 001d36e8: moved to src/anon/unit_001d35e0.cpp

u32 duplicate_unplaced_001d3f98(u8* a0) {
    u8* s0 = D_01d5ba30;
    u32 a2 = D_0033caf0;
    func_002fee78((u32)s0, (u32)D_0036e448, a2, (u32)(a0 + 4));
    return (u32)s0;
}

u32 duplicate_unplaced_001d4528(u8* a0) {
    return (s32)func_001a35f8(*(u16*)(a0 + 42), a0[1]) > 0;
}

void func_001d4570(u8* a0, u32 a1);  // 0x001d4570: definition moved into src/anon/unit_001d3c08.cpp

void duplicate_unplaced_001d4dc0(u8* a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)(a0 + 568) = a1;
    *(u32*)(a0 + 24) = 9999;
    *(u32*)(a0 + 572) = a2;
    *(u32*)(a0 + 576) = a3;
    *(u32*)(a0 + 44) = 0;
    ((void (*)(u8*))(*(u32*)(*(u32*)a0 + 4)))(a0);
}

u32 func_001d4ff0(u8* a0);  // 0x001d4ff0: definition moved into src/anon/unit_001d4f40.cpp

void duplicate_unplaced_001d5030(u32 a0) {
    D_00352768 = a0;
    u32 v0 = func_00168b38(a0, 2, 0);  // entry_array_find_nth
    D_01d5ba68 = *(u32*)(v0 + 8);
}

u32 duplicate_unplaced_001d5668(u32 a0) {
    u32 v = D_0032fae4[a0 >> 5];
    u32 m = 1u << (a0 & 31);
    return (v & m) != 0;
}

void duplicate_unplaced_001d5698(u32 a0) {
    u32 i = a0 >> 5;
    u32 m = 1u << (a0 & 31);
    D_0032fae4[i] |= m;
}

void func_001d6110(u32 a0, u8* a1);  // 0x001d6110: definition moved into src/anon/unit_001d4f40.cpp

u8* func_001d6d58(s32 a0);  // 0x001d6d58: definition moved into src/anon/unit_001d68e0.cpp

void func_001d76e8(u32 a0, u8* a1);  // 0x001d76e8: definition moved into src/anon/unit_001d7458.cpp

void duplicate_unplaced_001d7e00(u8* a0) {
    u8* s0 = a0;
    func_00190920((u32)(a0 + 2548), 2, (u32)s0);
    func_00198450((u32)s0);
}

u32 func_001d8438();  // 0x001d8438: definition moved into src/anon/unit_001d7458.cpp

u32 func_001d9850();  // 0x001d9850: definition moved into src/anon/unit_001d7458.cpp

u32 func_001d9af8(u8* a0);  // 0x001d9af8: definition moved into src/anon/unit_001d7458.cpp

extern "C" u32 func_001d9e78(...);
typedef u32 (*Func_001db610_cb)(u32, u32);
u32 func_001db610(u32, Func_001db610_cb, u32);
u32 duplicate_unplaced_001d9d28(u8* a0) {
    return func_001d9e78(a0[0], a0[1]);
}

u32 func_001d9d88(u8* a0) {
    u32 s0 = 0;
    u32 v0;
    u32 t15 = *(u16*)(a0 + 8);
    if (t15 == 0) {
        goto set1;
    }
    if (func_00181500(t15) == 0) {
        goto end;
    }
set1:
    s0 = 1;
end:
    v0 = s0;
    return v0;
}

void duplicate_unplaced_001d9eb0(u8* a0, u32 a1, u32 a2) {
    u8* s0 = a0;
    func_001980d0((u32)a0, a1, 10, a2);
    *(u32*)(s0 + 2552) = 0;
    *(u32*)(s0 + 2548) = 0;
    *(u32*)(s0 + 0) = (u32)&D_00352908;
}

void duplicate_unplaced_001d9ef0(u8* a0, u32 a1, u32 a2) {
    u8* s0 = a0;
    func_001980d0((u32)a0, a1, 10, a2);
    *(u32*)(s0 + 2552) = 0;
    *(u32*)(s0 + 2548) = 0;
    *(u32*)(s0 + 0) = (u32)&D_00352908;
}

u32 func_001db200() {
    u32 s0 = *(u32*)&D_0034e948;
    u32 s1 = 0;
    if (func_0019ba60(s0) != 0) {
        s1 = (u32)(func_001b9d40(s0) != 0);  // vtable_call_slot64_flags
    }
    return s1;
}

u32 duplicate_unplaced_001dc488(u32 a0) {
    u32 a1 = a0;
    u32 a0g = D_01d5bb00;
    u32 t15 = *(u32*)(a0g + 0);
    u32 fn = *(u32*)(t15 + 0);
    return ((u32 (*)(u32, u32, u32))fn)(a0g, a1, 0);
}

void func_001dc698(u8* a0, u32 a1);  // 0x001dc698: definition moved into src/anon/unit_001dbfd8.cpp

void func_001dc700(u8* a0, u32 a1);  // 0x001dc700: definition moved into src/anon/unit_001dbfd8.cpp


// ---- Functions assigned to this TU by generate_layout.py ----

u32 ctarget_0013cb08(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013cb08: definition moved into src/anon/unit_0013a8b8.cpp

namespace YS {

f32 AREADATA::GetCostRest() {
    return *(f32*)&D_01c6053c - *(f32*)&D_01c60540;
}
}  // namespace YS

extern "C" u32 func_0019ba28(...);
extern "C" u32 func_0019baa8(...);
u32 ctarget_0019ba60(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0019ba60: definition moved into src/anon/unit_0019ba60.cpp

u32 u_call4_001a1de0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001a1de0: definition moved into src/anon/unit_0019fb70.cpp

extern "C" u32 func_002ef988(...);
extern "C" u32 func_002efbb8(...);

// 002ef9e0: moved to src/anon/unit_002ef938.cpp

// 002efc10: moved to src/anon/unit_002efbb8.cpp

extern "C" u32 func_0028b040(...);

extern "C" u32 func_00287bc0(...);
u32 func_002a4430() {
    u32 v0 = func_00287bc0();
    return (v0 == 8 || v0 == 33) ? 1u : 0u;
}
