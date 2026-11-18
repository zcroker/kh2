#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"

// merged from: jtraps_wrappers.cpp
void func_001007c0(void*);
void func_001025f8(void*);
void func_001033d8(void*);
void func_00133e50(void*);
void func_001340e8(void*);
void func_0010b550(void*);
void func_0010d2b8(void*);
void func_001064a8(void*);  // int_to_float_scaled
void func_00127a88(void*);
void func_00136840(void*);
void func_00138840(void*);
extern "C" void dk_Aabbox_set_vectors(void*) asm("_ZN2dk6Aabbox3setERKN2kn7FVectorES4_");
void func_00144860(void*);
void func_00146ab0(void*);
void func_001491d8(void*);
void func_0015b100(void*);
void func_0014f300(void*);
void func_0014f428(void*);
void func_0014f4d8(void*);
void func_0014f528(void*);
void func_001505b0(void*);
void func_0023ede8(void*);
void func_00154b18(void*);
void func_00155410(void*);
void func_00143318(void*);
void func_001431e8(void*);
void func_00143208(void*);
void func_0011b6a8(void*);
void func_001adea8(void*);
void func_001781e8(void*);
void func_001984b8(void*);
void func_00187868(void*);
void func_0018c438(void*);
void func_00192528(void*);
void func_00195750(void*);
void func_001ac700(void*);
void func_0017c578(void*);
void func_00105110(void*);
void func_00198630(void*);
void func_0017a8f8(void*);
void func_0014ca38(void*);
void func_001d5730(void*);
void func_001bde88(void*);
void func_001e4f40(void*);
void func_001e7018(void*);
void func_001e7698(void*);  // alloc_aligned16
void func_0020dff0(void*);
void func_001fa7b0(void*);
void func_001fab48(void*);
void func_001facf8(void*);
void func_00226030(void*);
void func_00236830(void*);
void func_00236d10(void*);
void func_00253978(void*);
void func_0028f878(void*);
void func_00257be0(void*);
void func_00267690(void*);
void func_002817b8(void*);
void func_00277070(void*);
void func_00281008(void*);
void func_00285f50(void*);
void func_0028da70(void*);
void func_002b6b84(void*);
void func_002b6d34(void*);
void func_002b7108(void*);
void func_002b788c(void*);
void func_002b9968(void*);
void func_002b99c8(void*);
void func_002b82f8(void*);
void func_002b83b4(void*);
void func_0016a9a0(void*);  // to_16a950
void func_002e7458(void*);
void func_002e7688(void*);
void func_002e76c8(void*);
void __ieee754_asinf(void*);
void __ieee754_powf(void*);
void strchr(void*);  // memset
void func_00139858(s32);
void func_00139dc0(s32);
void func_001393f8(s32);
void func_001398d0(s32);
void func_00109e30(s32);
void func_001069f8(s32);
void func_00161f48(s32);
void func_00306698(s32);
void sceGsSyncV(s32);
void func_001397d8(s32);
void func_002634c8(s32);
namespace Tz {}
void func_00257530(s32);
void func_00258df0(s32);
void func_00258eb8(s32);
void func_0023f5b8(s32);
void func_002b8274(s32);
void func_001b84b8(s32);
void func_002d18e8(s32);
void func_002d84a8(s32);
void func_002d8670(s32);
void func_002dcc90(s32);
void func_002dc988(s32);
void func_002dcf90(s32);
void func_002e13d8(s32);
void func_001058f8(s32, s32);
void func_00107d20(s32, s32);
void func_0010aef0(s32, s32);
void func_00113470(s32, s32);
void func_00134508(s32, s32);
void func_00135690(s32, s32);
void func_0013a240(s32, s32);
void func_00141100(s32, s32);
void func_00149150(s32, s32);
void func_00149f30(s32, s32);
void func_0014a868(s32, s32);
void func_0014aed0(s32, s32);
void func_0014e1f0(s32, s32);
void func_001591e8(s32, s32);
void func_00159c58(s32, s32);
void func_0015a768(s32, s32);

void func_001008d0(BD_VALUE* bd);  // 0x001008d0: definition moved into src/libgcc/unwind-dw2-fde.c
// 00102670: moved to src/global/unit_001022c0.cpp
// 00103398: Tz::MenuBasic::GetMenuNameId, moved to src/common/unit_001031b0.cpp
void func_00109e18(BD_VALUE* bd);  // 00109e18: moved to src/anon/unit_00109c30.cpp
void func_00109e90(BD_VALUE* bd);  // 00109e90: moved to src/anon/unit_00109c30.cpp
void func_0010b450(BD_VALUE* bd);  // 0x0010b450: definition moved into src/anon/unit_0010b450.cpp
void func_0010d900(BD_VALUE* bd);  // 0x0010d900: definition moved into src/anon/unit_0010d900.cpp
void func_0010f648(BD_VALUE* bd);  // 0x0010f648: definition moved into src/anon/unit_0010f338.cpp
void func_0011d710(BD_VALUE* bd);  // 0x0011d710: definition moved into src/anon/unit_0011c128.cpp
// 001369b8: moved to src/harata/libdk/bgse.cpp
void func_001390a8(BD_VALUE* bd);  // 0x001390a8: definition moved into src/anon/unit_00138480.cpp
void func_001444b0(BD_VALUE* bd);  // 0x001444b0: definition moved into src/anon/unit_00144450.cpp
void func_001444f8(BD_VALUE* bd);  // 0x001444f8: definition moved into src/anon/unit_00144450.cpp
void func_00146bd8(BD_VALUE* bd);  // 0x00146bd8: definition moved into src/anon/unit_00145600.cpp
// 001491c0: moved to src/harata/libdk/mapfile.cpp
void func_0014f1e0(BD_VALUE* bd);  // 0x0014f1e0: definition moved into src/anon/unit_0014ecb8.cpp
void func_0014f208(BD_VALUE* bd);  // 0x0014f208: definition moved into src/anon/unit_0014ecb8.cpp
void func_0014f220(BD_VALUE* bd);  // 0x0014f220: definition moved into src/anon/unit_0014ecb8.cpp
void func_0014f238(BD_VALUE* bd);  // 0x0014f238: definition moved into src/anon/unit_0014ecb8.cpp
void func_0014f250(BD_VALUE* bd);  // 0x0014f250: definition moved into src/anon/unit_0014ecb8.cpp
void func_00150648(BD_VALUE* bd);  // 0x00150648: definition moved into src/anon/unit_0014ecb8.cpp
void func_00153c80(BD_VALUE* bd);  // 0x00153c80: definition moved into src/anon/unit_00153678.cpp
// 00154b80: moved to src/anon/unit_00153ea0.cpp
void func_00154b80(BD_VALUE* bd);
// 001554a8: moved to src/anon/unit_00153ea0.cpp
void func_001554a8(BD_VALUE* bd);
// 0015ef38: moved to src/harata/libdk/map.cpp
// 0015f6e8: moved to src/harata/libdk/map_effect.cpp
// 0015f700: moved to src/harata/libdk/map_effect.cpp
void func_001616d8(BD_VALUE* bd);  // 0x001616d8: definition moved into src/anon/unit_001614e8.cpp
// 00179ea0: moved to src/yasui/libys/player.cpp
// 00186008: moved to src/anon/unit_00185d10.cpp
void func_00186008(BD_VALUE* bd);
// 00187850: moved to src/anon/unit_00185d10.cpp
void func_00187850(BD_VALUE* bd);
void func_0018c420(BD_VALUE* bd);  // 0x0018c420: definition moved into src/yasui/libys/npc.cpp
// 00192800: moved to src/yasui/libys/message.cpp
void func_00195738(BD_VALUE* bd);  // 0x00195738: definition moved into src/anon/unit_00194790.cpp
// 001acda8: moved to src/anon/unit_001abb28.cpp
// 001b20f0: moved to src/anon/unit_001b1d20.cpp
void func_001b78b8(BD_VALUE* bd);  // 0x001b78b8: definition moved into src/anon/unit_001b6a50.cpp
// 0x1c8b30: moved to src/yasui/libys/summon.cpp
void func_001ce838(BD_VALUE* bd);  // 0x001ce838: definition moved into src/anon/unit_001ce6e8.cpp
void func_001d1998(BD_VALUE* bd);  // 0x001d1998: definition moved into src/anon/unit_001d14e0.cpp
void func_001d5700(BD_VALUE* bd);  // 0x001d5700: definition moved into src/anon/unit_001d4f40.cpp
void func_001d5718(BD_VALUE* bd);  // 0x001d5718: definition moved into src/anon/unit_001d4f40.cpp
void func_001d68e0(BD_VALUE* bd);  // 0x001d68e0: definition moved into src/anon/unit_001d68e0.cpp
void func_001dbfd8(BD_VALUE* bd);  // 0x001dbfd8: definition moved into src/anon/unit_001dbfd8.cpp
void func_001dd1b0(BD_VALUE* bd);  // 0x001dd1b0: definition moved into src/anon/unit_001dbfd8.cpp
void func_001e2b78(BD_VALUE* bd);  // 0x001e2b78: definition moved into src/anon/unit_001e0cb8.cpp
void func_001e6630(BD_VALUE* bd);  // 0x001e6630: definition moved into src/anon/unit_001e0cb8.cpp
void func_001fa830(BD_VALUE* bd);  // 0x001fa830: definition moved into src/anon/unit_001fa1b8.cpp
void func_001fabc8(BD_VALUE* bd);  // 0x001fabc8: definition moved into src/anon/unit_001fa1b8.cpp
void func_001fad78(BD_VALUE* bd);  // 0x001fad78: definition moved into src/anon/unit_001fa1b8.cpp
void func_002330b0(BD_VALUE* bd);  // 0x002330b0: definition moved into src/anon/unit_00232f08.cpp
void func_00236788(BD_VALUE* bd);  // 0x00236788: definition moved into src/anon/unit_00236180.cpp
void func_00236ce0(BD_VALUE* bd);  // 0x00236ce0: definition moved into src/anon/unit_00236180.cpp
void func_002539d0(BD_VALUE* bd);  // 0x002539d0: definition moved into src/anon/unit_002530c8.cpp
void func_0025f550(BD_VALUE* bd);  // 0x0025f550: definition moved into src/anon/unit_0025da20.cpp
void func_002631f8(BD_VALUE* bd);  // 0x002631f8: definition moved into src/anon/unit_0025f6b8.cpp
void func_00267608(BD_VALUE* bd);  // 0x00267608: definition moved into src/anon/unit_00265580.cpp
void func_002677d8(BD_VALUE* bd);  // 0x002677d8: definition moved into src/anon/unit_00265580.cpp
void func_00277008(BD_VALUE* bd);  // 0x00277008: definition moved into src/anon/unit_002748a0.cpp
void func_0027b510(BD_VALUE* bd);  // 0x0027b510: definition moved into src/anon/unit_0027a6d8.cpp
void func_00280ec8(BD_VALUE* bd);  // 0x00280ec8: definition moved into src/anon/unit_0027f2b0.cpp
void func_00280ee0(BD_VALUE* bd);  // 0x00280ee0: definition moved into src/anon/unit_0027f2b0.cpp
void func_00286280(BD_VALUE* bd);  // 0x00286280: definition moved into src/anon/unit_002853b8.cpp
void func_0028dac8(BD_VALUE* bd);  // 0028dac8: moved to src/anon/unit_0028c878.cpp
void func_00290708(BD_VALUE* bd);  // 00290708: moved to src/anon/unit_0028f1e0.cpp
void func_002b9ab8(BD_VALUE* bd);  // 0x002b9ab8: definition moved into src/anon/unit_002b9ab8.cpp
void func_002ba1a0(BD_VALUE* bd);  // 0x002ba1a0: definition moved into src/anon/unit_002b9ab8.cpp
void func_002ba2d0(BD_VALUE* bd);  // 0x002ba2d0: definition moved into src/anon/unit_002b9ab8.cpp
void func_002baa08(BD_VALUE* bd);  // 0x002baa08: definition moved into src/anon/unit_002b9ab8.cpp
void func_002baa60(BD_VALUE* bd);  // 0x002baa60: definition moved into src/anon/unit_002b9ab8.cpp
void func_002baba8(BD_VALUE* bd);  // 0x002baba8: definition moved into src/anon/unit_002b9ab8.cpp
void func_002bd588(BD_VALUE* bd);  // 0x002bd588: definition moved into src/anon/unit_002bc978.cpp
void func_002bd5c8(BD_VALUE* bd);  // 0x002bd5c8: definition moved into src/anon/unit_002bc978.cpp
void func_002dabd0(BD_VALUE* bd);  // 0x002dabd0: definition moved into src/anon/unit_002da040.cpp
void func_002e7310(BD_VALUE* bd);  // 0x002e7310: definition moved into src/anon/unit_002e5f70.cpp
void func_002e7328(BD_VALUE* bd);  // 0x002e7328: definition moved into src/anon/unit_002e5f70.cpp
// 002e7670, 002e7698, 002e76b0: moved to src/anon/unit_002e7658.cpp
void func_002f8ab8(BD_VALUE* bd);  // 0x002f8ab8: definition moved into src/newlib/libm/wf_asin.c
void func_002f8b30(BD_VALUE* bd);  // 0x002f8b30: definition moved into src/newlib/libm/wf_pow.c
void func_002fd3d0(BD_VALUE* bd);  // 0x002fd3d0: definition moved into src/newlib/libc/index.c

void func_00138128(BD_VALUE* bd);  // 0x00138128: definition moved into src/anon/unit_001374c8.cpp
void func_001393c8(BD_VALUE* bd);  // 0x001393c8: definition moved into src/anon/unit_001393c8.cpp
void func_001393e0(BD_VALUE* bd);  // 0x001393e0: definition moved into src/anon/unit_001393c8.cpp
void func_001394c0(BD_VALUE* bd);  // 0x001394c0: definition moved into src/anon/unit_001393c8.cpp
void func_00139de8(BD_VALUE* bd);  // 0x00139de8: definition moved into src/anon/unit_001393c8.cpp
void func_0013e8a8(BD_VALUE* bd);  // 0x0013e8a8: definition moved into src/anon/unit_0013dfb8.cpp
void func_00153140(BD_VALUE* bd);  // 0x00153140: definition moved into src/anon/unit_0014ecb8.cpp
void func_00161868(BD_VALUE* bd);  // 0x00161868: definition moved into src/anon/unit_001614e8.cpp
namespace kn { void setCameraNumber(s32); }
void func_00161a10(BD_VALUE* bd);  // 0x00161a10: definition moved into src/anon/unit_001614e8.cpp
void func_00161a28(BD_VALUE* bd);  // 0x00161a28: definition moved into src/anon/unit_001614e8.cpp
void func_00162058(BD_VALUE* bd);  // 0x00162058: definition moved into src/anon/unit_001614e8.cpp
void func_00162070(BD_VALUE* bd);  // 0x00162070: definition moved into src/anon/unit_001614e8.cpp
void func_001ae678(BD_VALUE* bd);  // 0x001ae678: definition moved into src/anon/unit_001ada38.cpp
void func_001ae690(BD_VALUE* bd);  // 0x001ae690: definition moved into src/anon/unit_001ada38.cpp
void func_00225248(BD_VALUE* bd);  // 0x00225248: definition moved into src/anon/unit_00224780.cpp
// 0022b930: moved to src/sasa/musical_2d.cpp (linked unit)
void func_0025f698(BD_VALUE* bd);  // 0x0025f698: definition moved into src/anon/unit_0025da20.cpp
void func_0026d168(BD_VALUE* bd);  // 0x0026d168: definition moved into src/anon/unit_0026c450.cpp
void func_0028ff00(BD_VALUE* bd);  // 0028ff00: moved to src/anon/unit_0028f1e0.cpp
void func_00290420(BD_VALUE* bd);  // 00290420: moved to src/anon/unit_0028f1e0.cpp
void func_002b4370(BD_VALUE* bd);  // 0x002b4370: definition moved into src/anon/unit_002b3ac8.cpp
void func_002bd570(BD_VALUE* bd);  // 0x002bd570: definition moved into src/anon/unit_002bc978.cpp
void func_002bdb58(BD_VALUE* bd);  // 0x002bdb58: definition moved into src/anon/unit_002bc978.cpp
void func_002d1f50(BD_VALUE* bd);  // 0x002d1f50: definition moved into src/anon/unit_002cf260.cpp
void func_002d8cf0(BD_VALUE* bd);  // 0x002d8cf0: definition moved into src/anon/unit_002d6f70.cpp
void func_002d8d28(BD_VALUE* bd);  // 0x002d8d28: definition moved into src/anon/unit_002d6f70.cpp
void func_002dd198(BD_VALUE* bd);  // 0x002dd198: definition moved into src/anon/unit_002da040.cpp
void func_002dd1e8(BD_VALUE* bd);  // 0x002dd1e8: definition moved into src/anon/unit_002da040.cpp
void func_002dd200(BD_VALUE* bd);  // 0x002dd200: definition moved into src/anon/unit_002da040.cpp
void func_002e1758(BD_VALUE* bd);  // 0x002e1758: definition moved into src/anon/unit_002de3c8.cpp
// 001059d0: _GLOBAL__I_ stub, now made by gcc in src/common/saveram.cpp
// 001059f0: _GLOBAL__D_ stub, now made by gcc in src/common/saveram.cpp
// 00108028: moved to src/naka/libkn/camera.cpp
void func_0010b418(BD_VALUE* bd);  // 0010b418: moved to src/anon/unit_0010aef0.cpp
// 001135e8: moved to src/anon/unit_001117d8.cpp
void func_00134580(BD_VALUE* bd);  // 0x00134580: definition moved into src/anon/unit_00133cf0.cpp
// 00135788: moved to src/anon/unit_00134668.cpp
void func_0013a328(BD_VALUE* bd);  // 0x0013a328: definition moved into src/anon/unit_001393c8.cpp
void func_00141418(BD_VALUE* bd);  // 0x00141418: definition moved into src/anon/unit_00141100.cpp
void func_00149188(BD_VALUE* bd);  // 0x00149188: definition moved into src/anon/unit_00148ef0.cpp
// 00149f68: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/area.cpp
void func_0014a8d8(BD_VALUE* bd);  // 0014a8d8: moved to src/anon/unit_00149fa8.cpp
// 0014b110: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/fade.cpp
// 0014e280: moved to src/anon/unit_0014d680.cpp
// 00159220: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/lightcyclecamera.cpp
// 00159cc0: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/talkcamera.cpp
// 0015a7d0: _GLOBAL__I_ stub, now made by gcc in src/harata/libdk/targetcamera.cpp

// merged from: tiny_patterns.cpp
// 00102e90: moved to src/common/title.cpp

// 00103560: moved to src/common/unit_001031b0.cpp

// 00103570: Tz::LoadDataGetSystem, moved to src/common/unit_001031b0.cpp

// 00103580: MENU::GetObjAllocator, moved to src/common/unit_001031b0.cpp

// 00103b38: MENU::isRunning, moved to src/common/unit_001031b0.cpp

// 00103c70: moved to src/common/unit_001031b0.cpp

// 00103c80: MENU::SetMapJump, moved to src/common/unit_001031b0.cpp

// 00103ea0: moved to src/common/unit_001031b0.cpp

// 001041a0: moved to src/common/gumibattle.cpp

// 001041f0: moved to src/common/gumibattle.cpp

// 00104288: moved to src/common/gumibattle.cpp

// 00104600: moved to src/common/gumimenu.cpp

// 001050b8: moved to src/common/area.cpp

// 001050c8: moved to src/common/area.cpp

// 00105a10: moved to src/common/unit_00105a10.cpp

// 00105c30: moved to src/common/region.cpp

// 001069a8: moved to src/naka/libkn/camera.cpp

// 001069e8: moved to src/naka/libkn/camera.cpp

// 00106a08: moved to src/naka/libkn/camera.cpp

// 00106ab8: moved to src/naka/libkn/camera.cpp

u32 func_0010aba8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0010aba8: moved to src/anon/unit_0010a918.cpp

u32 func_00112740(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00112740: definition moved into src/anon/unit_001117d8.cpp

void func_001127b0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001127b0: definition moved into src/anon/unit_001117d8.cpp

u32 func_00112c48(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00112c48: definition moved into src/anon/unit_001117d8.cpp

void func_001133f8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001133f8: definition moved into src/anon/unit_001117d8.cpp

u32 func_00132338(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00132338: definition moved into src/anon/unit_00131418.cpp

u32 func_001341e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001341e8: definition moved into src/anon/unit_00133cf0.cpp

// 001357c8: moved to src/naka/libkn/obj_observer.cpp

// 00135d78: moved to src/naka/libkn/effect_observer.cpp

// 00136958: moved to src/harata/libdk/bgse.cpp

extern "C" void func_00136a50(u32, u32, u32, u32) asm("_ZN2dk4BGSE8clearOffEv");

void func_001391f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001391f0: definition moved into src/anon/unit_001391c8.cpp

void func_001396d0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001396d0: definition moved into src/anon/unit_001393c8.cpp

void func_00139708(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00139708: definition moved into src/anon/unit_001393c8.cpp

void func_00139740(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00139740: definition moved into src/anon/unit_001393c8.cpp

// 0013a4a8: moved to src/harata/libdk/field2dd.cpp

// 0013a4b8: moved to src/harata/libdk/field2dd.cpp

// 0013a800: moved to src/harata/libdk/field2dd.cpp

u32 func_0013cb80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013cb80: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013d7d0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013d7d0: definition moved into src/anon/unit_0013a8b8.cpp

u32 func_0013d810(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013d810: definition moved into src/anon/unit_0013a8b8.cpp

u32 func_0013ef80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013ef80: definition moved into src/anon/unit_0013ef70.cpp

void func_00140db0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00140db0: definition moved into src/anon/unit_0013fca8.cpp

void func_00143278(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00143278: definition moved into src/anon/unit_00142c90.cpp

void func_001432a8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001432a8: definition moved into src/anon/unit_00142c90.cpp

void func_0014a1e0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0014a1e0: moved to src/anon/unit_00149fa8.cpp

void func_0014a248(u32 a0, u32 a1, u32 a2, u32 a3);  // 0014a248: moved to src/anon/unit_00149fa8.cpp

u32 func_0014a258(u32 a0, u32 a1, u32 a2, u32 a3);  // 0014a258: moved to src/anon/unit_00149fa8.cpp

void func_0014a4c0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0014a4c0: moved to src/anon/unit_00149fa8.cpp

void func_0014a4f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0014a4f0: moved to src/anon/unit_00149fa8.cpp

void func_0014ace8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014ace8: definition moved into src/harata/libdk/fade.cpp

u32 func_0014ca38(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014ca38: definition moved into src/anon/unit_0014c7f0.cpp

// 0014df98: moved to src/anon/unit_0014d680.cpp

void func_0015b770(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0015b770: definition moved into src/anon/unit_0015b100.cpp

// 0015ce80: moved to src/anon/unit_0015cdb0.cpp

// 0015ce90: moved to src/anon/unit_0015cdb0.cpp

// 0015f268: moved to src/harata/libdk/map_effect.cpp

// 0015f288: moved to src/harata/libdk/map_effect.cpp

// 001604f0: moved to src/harata/libdk/bgobj.cpp

// 00160d18: moved to src/harata/libdk/bgobj.cpp

// 00160d28: moved to src/harata/libdk/bgobj.cpp

// 00161228: moved to src/anon/unit_001611a8.cpp

void func_00161530(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00161530: definition moved into src/anon/unit_001614e8.cpp

u32 func_00162088(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00162088: definition moved into src/anon/unit_001614e8.cpp

u32 func_00162098(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00162098: definition moved into src/anon/unit_001614e8.cpp

void func_00165870(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00165870: definition moved into src/anon/unit_001656b8.cpp

void func_00167218(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00167218: definition moved into src/anon/unit_001664c0.cpp

// 00182df0: moved to src/anon/unit_00182780.cpp

// 00182f28: moved to src/anon/unit_00182780.cpp

// 00185880: moved to src/anon/unit_001855e0.cpp

// 00185910: moved to src/anon/unit_001855e0.cpp

// 00185d98: moved to src/anon/unit_00185d10.cpp
void func_00185d98(u32 a0, u32 a1, u32 a2, u32 a3);

void func_00194790(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00194790: definition moved into src/anon/unit_00194790.cpp

void func_00196608(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00196608: definition moved into src/anon/unit_00195d00.cpp

void func_0019fe80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0019fe80: definition moved into src/anon/unit_0019fb70.cpp

// 001a5b58: moved to src/yasui/libys/prizetable.cpp

// 001a6648: moved to src/yasui/libys/magic.cpp

// 001a6a10: moved to src/anon/unit_001a6a10.cpp

// 001a81e0: moved to src/anon/unit_001a8098.cpp

void func_001a97e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001a97e8: definition moved into src/anon/unit_001a9130.cpp

u32 func_001ab810(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001ab810: definition moved into src/anon/unit_001ab598.cpp

// 001ad938: moved to src/anon/unit_001abb28.cpp

u32 func_001ae990(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001ae990: definition moved into src/anon/unit_001ada38.cpp

u32 func_001aec40(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001aec40: definition moved into src/anon/unit_001ada38.cpp

void func_001afae0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001afae0: definition moved into src/anon/unit_001ada38.cpp

// 001b13f0: moved to src/yasui/libys/databuff.cpp

void func_001b6fa0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b6fa0: definition moved into src/anon/unit_001b6a50.cpp

void func_001b8218(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b8218: definition moved into src/anon/unit_001b6a50.cpp

void func_001b87a0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b87a0: definition moved into src/anon/unit_001b87a0.cpp

void func_001b8e78(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b8e78: definition moved into src/anon/unit_001b87a0.cpp

// 001c0638: moved to src/anon/unit_001c0638.cpp
void func_001c0638(u32 a0, u32 a1, u32 a2, u32 a3);

// 001c09f0: moved to src/anon/unit_001c0638.cpp
void func_001c09f0(u32 a0, u32 a1, u32 a2, u32 a3);

// 001c0c18: moved to src/anon/unit_001c0638.cpp
u32 func_001c0c18(u32 a0, u32 a1, u32 a2, u32 a3);

// 001c0c70: moved to src/anon/unit_001c0638.cpp
void func_001c0c70(u32 a0, u32 a1, u32 a2, u32 a3);

// 001c0cc8: moved to src/anon/unit_001c0638.cpp
u32 func_001c0cc8(u32 a0, u32 a1, u32 a2, u32 a3);

// 001c10b8: moved to src/anon/unit_001c0638.cpp
void func_001c10b8(u32 a0, u32 a1, u32 a2, u32 a3);

// 001c20d8: moved to src/anon/unit_001c0638.cpp
void func_001c20d8(u32 a0, u32 a1, u32 a2, u32 a3);

void func_001c2d38(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c2d38: definition moved into src/anon/unit_001c2b58.cpp

void func_001c2d78(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c2d78: definition moved into src/anon/unit_001c2b58.cpp

void func_001c3660(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c3660: definition moved into src/anon/unit_001c2b58.cpp

void func_001c3f48(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c3f48: definition moved into src/anon/unit_001c2b58.cpp

u32 func_001c4160(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c4160: definition moved into src/anon/unit_001c4120.cpp

void func_001c8e80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c8e80: definition moved into src/anon/unit_001c8e80.cpp

void func_001c9770(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c9770: definition moved into src/yasui/libys/sacrifice.cpp

void func_001d16f8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d16f8: definition moved into src/anon/unit_001d14e0.cpp

void func_001d2298(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d2298: definition moved into src/anon/unit_001d14e0.cpp

void func_001d23d0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d23d0: definition moved into src/anon/unit_001d14e0.cpp

// 001d30b0: moved to src/anon/unit_001d30b0.cpp

void func_001d3c08(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d3c08: definition moved into src/anon/unit_001d3c08.cpp

void func_001d58e0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d58e0: definition moved into src/anon/unit_001d4f40.cpp

void func_001d5a48(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d5a48: definition moved into src/anon/unit_001d4f40.cpp

void func_001d5b68(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d5b68: definition moved into src/anon/unit_001d4f40.cpp

void func_001d6cb8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d6cb8: definition moved into src/anon/unit_001d68e0.cpp

void func_001d7970(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d7970: definition moved into src/anon/unit_001d7458.cpp

void func_001d7eb8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d7eb8: definition moved into src/anon/unit_001d7458.cpp

void func_001db598(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001db598: definition moved into src/anon/unit_001d9d00.cpp

void func_001dcd50(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001dcd50: definition moved into src/anon/unit_001dbfd8.cpp

void func_001ddb68(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001ddb68: definition moved into src/anon/unit_001dd920.cpp

void func_001e2b68(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e2b68: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_001e2c78(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e2c78: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e6d28(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e6d28: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e70a0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e70a0: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_002247d8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002247d8: definition moved into src/anon/unit_00224780.cpp

u32 func_00224860(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224860: definition moved into src/anon/unit_00224780.cpp

void func_002248c0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002248c0: definition moved into src/anon/unit_00224780.cpp

u32 func_00224910(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224910: definition moved into src/anon/unit_00224780.cpp

void func_00224920(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224920: definition moved into src/anon/unit_00224780.cpp

void func_00224940(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224940: definition moved into src/anon/unit_00224780.cpp

u32 func_00224968(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224968: definition moved into src/anon/unit_00224780.cpp

u32 func_00224978(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224978: definition moved into src/anon/unit_00224780.cpp

u32 func_00224988(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224988: definition moved into src/anon/unit_00224780.cpp

void func_002249a8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002249a8: definition moved into src/anon/unit_00224780.cpp

u32 func_002249b8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002249b8: definition moved into src/anon/unit_00224780.cpp

void func_002249d8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002249d8: definition moved into src/anon/unit_00224780.cpp

u32 func_002249e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002249e8: definition moved into src/anon/unit_00224780.cpp

u32 func_00224e90(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224e90: definition moved into src/anon/unit_00224780.cpp

u32 func_00225540(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00225540: definition moved into src/anon/unit_00224780.cpp

void func_00225a00(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00225a00: definition moved into src/anon/unit_00224780.cpp

void func_00225a20(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00225a20: definition moved into src/anon/unit_00224780.cpp

u32 func_00225e48(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00225e48: definition moved into src/anon/unit_00224780.cpp

void func_00226968(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00226968: definition moved into src/anon/unit_00224780.cpp

void func_00227108(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00227108: definition moved into src/anon/unit_00224780.cpp

void func_0022bd80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0022bd80: moved to src/sasa/event_movie.cpp (linked unit)

u32 func_0022bd90(u32 a0, u32 a1, u32 a2, u32 a3);  // 0022bd90: moved to src/sasa/event_movie.cpp (linked unit)

void func_0022c9f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0022c9f0: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d7c8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0022d7c8: definition moved into src/anon/unit_0022d358.cpp

u32 func_0022d7d8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0022d7d8: definition moved into src/anon/unit_0022d358.cpp

u32 func_00234778(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00234778: definition moved into src/anon/unit_002335e8.cpp

u32 func_002347a8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002347a8: definition moved into src/anon/unit_002335e8.cpp

u32 func_002347b8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002347b8: definition moved into src/anon/unit_002335e8.cpp

u32 func_002347c8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002347c8: definition moved into src/anon/unit_002335e8.cpp

u32 func_002347d8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002347d8: definition moved into src/anon/unit_002335e8.cpp

u32 func_002347e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002347e8: definition moved into src/anon/unit_002335e8.cpp

void func_00237ad8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00237ad8: definition moved into src/anon/unit_00237068.cpp

void func_0023d1e0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0023d1e0: definition moved into src/anon/unit_0023c968.cpp

void func_0023d230(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0023d230: definition moved into src/anon/unit_0023c968.cpp


u32 func_00240108(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00240108: definition moved into src/anon/unit_0023f5b8.cpp

u32 func_00240430(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00240430: definition moved into src/anon/unit_0023f5b8.cpp

u32 func_002431c0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002431c0: definition moved into src/anon/unit_00242478.cpp

u32 func_00253578(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00253578: definition moved into src/anon/unit_002530c8.cpp

void func_002634c8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002634c8: definition moved into src/anon/unit_002632d0.cpp

u32 func_00263ea8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00263ea8: definition moved into src/anon/unit_002632d0.cpp

void func_00264318(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00264318: definition moved into src/anon/unit_002640a8.cpp

void func_0026d808(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0026d808: definition moved into src/anon/unit_0026c450.cpp

u32 func_00287ec8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00287ec8: definition moved into src/anon/unit_00286d28.cpp

u32 func_00288008(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00288008: definition moved into src/anon/unit_00286d28.cpp

void func_00288648(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00288648: definition moved into src/anon/unit_002880b8.cpp

void func_0028b248(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0028b248: definition moved into src/anon/unit_00288b00.cpp

void func_002936e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002936e8: definition moved into src/anon/unit_00292e60.cpp

u32 func_002936f8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002936f8: definition moved into src/anon/unit_00292e60.cpp

u32 func_00293ba0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00293ba0: definition moved into src/anon/unit_00292e60.cpp

u32 func_00296f80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00296f80: definition moved into src/anon/unit_00295d28.cpp

u32 func_00296f90(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00296f90: definition moved into src/anon/unit_00295d28.cpp

void func_002b4ae0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002b4ae0: definition moved into src/anon/unit_002b3ac8.cpp

void func_002b4af0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002b4af0: definition moved into src/anon/unit_002b3ac8.cpp

void func_002b50f8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002b50f8: definition moved into src/anon/unit_002b3ac8.cpp

extern "C" u32 func_002b64c8(u32, u32, u32, u32) asm("_ZN2Tz10SyntheData15GetMixDataFnameEv");

extern "C" u32 func_002ba358(u32, u32, u32, u32) asm("_ZN5SOUND13isSeAlertPlayEv");

void func_002ba610(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002ba610: definition moved into src/anon/unit_002b9ab8.cpp

u32 func_002ba620(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002ba620: definition moved into src/anon/unit_002b9ab8.cpp

extern "C" void func_002bc798(u32, u32, u32, u32) asm("_ZN5SOUND10SE3DEnableEv");

u32 func_002bd250(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002bd250: definition moved into src/anon/unit_002bc978.cpp

void func_002bea00(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002bea00: definition moved into src/anon/unit_002be020.cpp

void func_002c22a8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002c22a8: definition moved into src/anon/unit_002c2228.cpp

void func_002cb530(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002cb530: definition moved into src/anon/unit_002cb200.cpp

u32 func_002d1260(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d1260: definition moved into src/anon/unit_002cf260.cpp

u32 func_002dc7f8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002dc7f8: definition moved into src/anon/unit_002da040.cpp

void func_002eda30(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002eda30: definition moved into src/anon/unit_002ecdb0.cpp

// 002ef618: moved to src/anon/unit_002ef1f8.cpp

// 002ef7b8: moved to src/anon/unit_002ef6b0.cpp

// 002efa88: moved to src/anon/unit_002ef938.cpp

u32 func_002f1888(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002f1888: definition moved into src/anon/unit_002f17e0.cpp

u32 func_00316d08(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00316d08: definition moved into src/newlib/libc/errno.c

u32 func_00317128(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00317128: definition moved into src/libgcc/unwind-dw2.c

void func_003191f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x003191f0: definition moved into src/libgcc/unwind-dw2.c

void func_0031ae00(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0031ae00: definition moved into src/anon/unit_003197d0.cpp

// merged from: tiny_patterns2.cpp
extern u32 D_0032b968;
extern u32 D_0032b9a0;
extern u32 D_0032ba2c;
extern u32 D_0032b9e8;
extern u32 D_0032ba48;
extern u32 D_0032ba90;
extern u32 D_0032bb20;
extern u32 D_0032bb30;
extern u32 D_0033cc44;
extern u32 D_0033cc50;
extern u32 D_00340ed8;
extern u32 D_00345cf8;
extern u32 D_00347940;
extern u32 D_00347b88;
extern u32 D_00347c00;
extern u32 D_00347c88;
extern u32 D_00347cc0;
extern u32 D_00347e08;
extern u32 D_00347ffd;
extern u32 D_00348710;
extern u32 D_00348754;
extern u32 D_0034939d;
extern u32 D_003493a0;
extern u32 D_003497e0;
extern u32 D_003498f0;
extern u32 D_003494b0;
extern u32 D_003495c0;
extern u32 D_003496d0;
extern u32 D_00349a00;
extern u32 D_00349dec;
extern u32 D_00349e20;
extern u32 D_00349f00;
extern u32 D_004f3744;
extern u32 D_004f36ec;
extern u32 D_004f3694;
extern u32 D_0034c6f0;
extern u32 D_0034d840;
extern u32 D_01c61958;
extern u32 D_0035037c;
extern u32 D_01c6cae0;
extern u32 D_01c6cc10;
extern u32 D_01c6cc48;
extern u32 D_01c6cd20;
extern u32 D_00350df0;
extern u32 D_01d48c40;
extern u32 D_01d48c44;
extern u32 D_01d48cb0;
extern u32 D_01d48dc0;
extern u32 D_01d49320;
extern u32 D_001c6108;
extern u32 D_00352b50;
extern u32 D_00352b54;
extern u32 D_0035dacc;
extern u32 D_0035dac8;
extern u32 D_0035dac4;
extern u32 D_01dad918;
extern u32 D_0035ead8;
extern u32 D_0035eae8;
extern u32 D_0035eb40;
extern u32 D_0035eb28;
extern u32 D_00372a28;
extern u32 D_003729c8;
extern u32 D_0035f054;
extern u32 D_0035f055;
extern u32 D_00373788;
extern u32 D_00373d88;
extern u32 D_0035f221;
extern u32 D_0035f320;
extern u32 D_0035f3f8;
extern u32 D_0035f570;
extern u32 D_01e2a5e8;
extern u32 D_003617fc;
extern u32 D_00361a50;
extern u32 D_01e2bda0;
extern u32 D_00361f60;
extern u32 D_00362d20;
extern u32 D_003637f8;
extern u32 D_01e2c088;
extern u32 D_00363c40;
extern u32 D_00377cc8;
extern u32 D_00367878;
extern u32 D_00367910;
extern u32 D_00367928;
extern u32 D_00369928;
extern u32 D_00347f98;
extern u32 D_00348698;

// 00102c80: getFieldMode, moved to src/common/unit_00102a70.cpp

// 00103070: moved to src/common/title.cpp

// 00103c90: moved to src/common/unit_001031b0.cpp

// 00103eb0: getMenuMode, moved to src/common/unit_001031b0.cpp

// 00104190: moved to src/common/gumibattle.cpp

// 001045f0: moved to src/common/gumimenu.cpp

// 00105300: moved to src/common/area.cpp

// 001058e8: moved to src/common/saveram.cpp

// 001070c8: moved to src/naka/libkn/camera.cpp

u32 func_0010ae90(u32 a0, u32 a1, u32 a2, u32 a3);  // 0010ae90: moved to src/anon/unit_0010a918.cpp

u32 func_0010cc70(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0010cc70: definition moved into src/anon/unit_0010b978.cpp

void func_0010eed8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0010eed8: definition moved into src/anon/unit_0010dee8.cpp

u32 func_0010f8d0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0010f8d0: definition moved into src/anon/unit_0010f338.cpp

u32 func_0010fa28(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0010fa28: definition moved into src/anon/unit_0010f338.cpp

u32 func_0010fa58(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0010fa58: definition moved into src/anon/unit_0010f338.cpp

void func_00113668(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00113668: definition moved into src/anon/unit_00113628.cpp

void func_0011ee58(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0011ee58: definition moved into src/anon/unit_0011c128.cpp

void func_00124c08(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00124c08: definition moved into src/anon/unit_00123990.cpp

u32 func_00132170(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00132170: definition moved into src/anon/unit_00131418.cpp

void func_001322f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001322f0: definition moved into src/anon/unit_00131418.cpp

u32 func_001344f8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001344f8: definition moved into src/anon/unit_00133cf0.cpp

// 00135640: moved to src/anon/unit_00134668.cpp

u32 func_001384c0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001384c0: definition moved into src/anon/unit_00138480.cpp

void func_0013a9e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013a9e8: definition moved into src/anon/unit_0013a8b8.cpp

u32 func_0013ba50(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013ba50: definition moved into src/anon/unit_0013a8b8.cpp

u32 func_001410b8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001410b8: definition moved into src/anon/unit_0013fca8.cpp

void func_0014a7e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0014a7e8: moved to src/anon/unit_00149fa8.cpp

u32 func_0014aba8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014aba8: definition moved into src/harata/libdk/fade.cpp

u32 func_0014abb8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014abb8: definition moved into src/harata/libdk/fade.cpp

u32 func_0014abc8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014abc8: definition moved into src/harata/libdk/fade.cpp

u32 func_0014abd8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014abd8: definition moved into src/harata/libdk/fade.cpp

u32 func_0014abe8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014abe8: definition moved into src/harata/libdk/fade.cpp

u32 func_0014abf8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014abf8: definition moved into src/harata/libdk/fade.cpp

u32 func_0014ac08(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014ac08: definition moved into src/harata/libdk/fade.cpp

u32 func_0014ca10(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014ca10: definition moved into src/anon/unit_0014c7f0.cpp

void func_0014ce20(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014ce20: definition moved into src/anon/unit_0014c7f0.cpp

// 0014e088: moved to src/anon/unit_0014d680.cpp

// 0014e638: moved to src/harata/libdk/fpscamera.cpp

// 0014e648: moved to src/harata/libdk/fpscamera.cpp

u32 func_0015cc50(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0015cc50: definition moved into src/anon/unit_0015cb18.cpp

u32 func_0015cc60(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0015cc60: definition moved into src/anon/unit_0015cb18.cpp

// 001688b8: moved to src/yasui/libys/file.cpp

// 00198e50: moved to src/anon/unit_00198e40.cpp

// 00198e60: moved to src/anon/unit_00198e40.cpp

extern "C" u32 func_0019f060(u32, u32, u32, u32) asm("_ZN2YS6JUMPER7is_jumpEv");

// 001a3a78: moved to src/yasui/libys/effect.cpp

u32 func_001a8b28(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001a8b28: definition moved into src/anon/unit_001a8618.cpp

u32 func_001a9130(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001a9130: definition moved into src/anon/unit_001a9130.cpp

u32 func_001ab800(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001ab800: definition moved into src/anon/unit_001ab598.cpp

u32 func_001af9e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001af9e8: definition moved into src/anon/unit_001ada38.cpp

u32 func_001b0320(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b0320: definition moved into src/anon/unit_001ada38.cpp

// 001b1e58: moved to src/anon/unit_001b1d20.cpp

u32 func_001b58a8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b58a8: definition moved into src/anon/unit_001b2780.cpp

// 001bb4a0: moved to src/yasui/libys/mission.cpp

void func_001c6310(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c6310: definition moved into src/anon/unit_001c5b90.cpp

u32 func_001c9100(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c9100: definition moved into src/anon/unit_001c8e80.cpp

void func_001d16e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d16e8: definition moved into src/anon/unit_001d14e0.cpp

// 001d30f8: moved to src/anon/unit_001d30b0.cpp

u32 func_001dc9e0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001dc9e0: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e02f8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e02f8: definition moved into src/anon/unit_001deb58.cpp

u32 func_001e3650(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e3650: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_001e6cd8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e6cd8: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_001e6ce8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e6ce8: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_001e6cf8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e6cf8: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00224870(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224870: definition moved into src/anon/unit_00224780.cpp

u32 func_00224880(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224880: definition moved into src/anon/unit_00224780.cpp

u32 func_00224930(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224930: definition moved into src/anon/unit_00224780.cpp

u32 func_00227120(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00227120: definition moved into src/anon/unit_00224780.cpp

u32 func_0022ab80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0022ab80: moved to src/sasa/musical_input.cpp (linked unit)

void func_002361d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YI5IMAGED1Ev");  // YI::IMAGE::~IMAGE
void func_002361d0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002361d0: definition moved into src/anon/unit_00236180.cpp

void func_00237238(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00237238: definition moved into src/anon/unit_00237068.cpp

void func_0023ca70(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0023ca70: definition moved into src/anon/unit_0023c968.cpp

void func_0023cd68(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0023cd68: definition moved into src/anon/unit_0023c968.cpp

u32 func_0023d240(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0023d240: definition moved into src/anon/unit_0023c968.cpp

extern "C" u32 func_002570e0(u32, u32, u32, u32) asm("_ZN2Tz5CmTop15GetTopSelSeqTblEv");

extern "C" void func_00257718(u32, u32, u32, u32) asm("_ZN2Tz5CmTop12SetDelCursorEb");

extern "C" u32 func_00282d58(u32, u32, u32, u32) asm("_ZN2Tz8ItemInfo15GetItemEmptyMsgEi");

void func_00287eb8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00287eb8: definition moved into src/anon/unit_00286d28.cpp


// 002baf38: moved to src/anon/unit_002bac78.cpp

u32 func_002bfdf8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002bfdf8: definition moved into src/anon/unit_002bebd0.cpp

u32 func_002cebb0(u32 a0, u32 a1, u32 a2, u32 a3);  // 002cebb0: moved to src/taito/minigame_base.cpp (linked unit)

u32 func_002d1f00(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d1f00: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d1f10(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d1f10: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d1f20(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d1f20: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d1f30(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d1f30: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d51f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d51f0: definition moved into src/anon/unit_002d4548.cpp

u32 func_002d5578(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d5578: definition moved into src/anon/unit_002d4548.cpp

u32 func_002d8110(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d8110: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002d8900(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d8900: definition moved into src/anon/unit_002d6f70.cpp

u32 func_002da110(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002da110: definition moved into src/anon/unit_002da040.cpp

u32 func_002dc7e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002dc7e8: definition moved into src/anon/unit_002da040.cpp

void func_002dea80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002dea80: definition moved into src/anon/unit_002de3c8.cpp

u32 func_002e10c0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002e10c0: definition moved into src/anon/unit_002de3c8.cpp

// 002e2920: moved to src/anon/unit_002e1908.cpp

// 002e2930: moved to src/anon/unit_002e1908.cpp

u32 func_002ee530(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002ee530: definition moved into src/anon/unit_002ecdb0.cpp

// 002ee6d8: moved to src/menu/tutorial_widget.cpp

// 002ee840: moved to src/menu/tutorial_widget.cpp

u32 sceGsGetGParam(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002f1fa8: definition moved into src/sdk/libgraph_002f1e18.c

u32 func_003037b0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x003037b0: definition moved into src/newlib/libc/locale.c

void func_003155e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x003155e8: definition moved into src/libsupc++/tinfo.cpp

void func_003167f8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x003167f8: definition moved into src/libsupc++/eh_exception.cpp

u32 func_00316e00(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00316e00: definition moved into src/libgcc/ee-gthr.c

u32 func_00316e10(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00316e10: definition moved into src/libgcc/ee-gthr.c

void func_0031a840(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0031a840: definition moved into src/anon/unit_003197d0.cpp

void func_0031b910(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0031b910: definition moved into src/anon/unit_003197d0.cpp

void func_0031baa8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0031baa8: definition moved into src/anon/unit_0031b9e0.cpp

void func_0031bb08(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0031bb08: definition moved into src/anon/unit_0031b9e0.cpp

void func_0031bbc8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0031bbc8: definition moved into src/anon/unit_0031b9e0.cpp

void func_0031d6b0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0031d6b0: definition moved into src/anon/unit_0031b9e0.cpp

// merged from: tiny_patterns3.cpp
extern u32 D_0032b998;
extern u32 D_0032f8e4;
extern u32 D_0032fb1c;
extern u32 D_00340eac;
extern u32 D_003417c8;
extern u32 D_003417cc;
extern u32 D_00347d30;
extern u32 D_003484a4;
extern u32 D_00348700;
extern u32 D_00348730;
extern u32 D_00348818;
extern u32 D_0034881e;
extern u32 D_0034881f;
extern u32 D_00349269;
extern u32 D_0034926b;
extern u32 D_00349b10;
extern u32 D_00349e0c;
extern u32 D_00349e10;
extern u32 D_0034a3e0;
extern u32 D_0034a998;
extern u32 D_0034a99c;
extern u32 D_0034c70d;
extern u32 D_0034c772;
extern u32 D_00352770;
extern u32 D_00352af0;
extern u32 D_00352af1;
extern u32 D_00352be0;
extern u32 D_0035dadd;
extern u32 D_0035dade;
extern u32 D_0035daec;
extern u32 D_0035daed;
extern u32 D_0035db10;
extern u32 D_0035de09;
extern u32 D_0035de0b;
extern u32 D_0035eb34;
extern u32 D_0035eb81;
extern u32 D_0035ec94;
extern u32 D_0035ecc4;
extern u32 D_0035ef78;
extern u32 D_0035f158;
extern u32 D_0035f300;
extern u32 D_0035f314;
extern u32 D_0035f4fa;
extern u32 D_0035f5b4;
extern u32 D_003616f0;
extern u32 D_003617d8;
extern u32 D_003617dc;
extern u32 D_00361899;
extern u32 D_0036d458;
extern u32 D_0036d468;
extern u32 D_0036dad0;
extern u32 D_0036daf0;
extern u32 D_0036db10;
extern u32 D_0036e088;
extern u32 D_00372978;
extern u32 D_003729e0;
extern u32 D_003729f0;
extern u32 D_00373da0;
extern u32 D_00374cb0;
extern u32 D_00375540;
extern u32 D_004f3810;
extern u32 D_004f3814;
extern u32 D_01c5f460;
extern u32 D_01c61964;
extern u32 D_01c61968;
extern u32 D_01c6196c;
extern u32 D_01c62f98;
extern u32 D_01c6cc60;
extern u32 D_01d49320;
extern u32 D_01d49324;
extern u32 D_01dad910;
extern u32 D_01e2a560;

// 00102b58: moved to src/common/unit_00102a70.cpp

// 001058d8: moved to src/common/saveram.cpp

u64 func_00109040(u32 a0, u32 a1, u32 a2, u32 a3);  // 00109040: moved to src/anon/unit_001085a8.cpp

u64 func_00109048(u32 a0, u32 a1, u32 a2, u32 a3);  // 00109048: moved to src/anon/unit_001085a8.cpp

u64 func_00109050(u32 a0, u32 a1, u32 a2, u32 a3);  // 00109050: moved to src/anon/unit_001085a8.cpp

u64 func_00109058(u32 a0, u32 a1, u32 a2, u32 a3);  // 00109058: moved to src/anon/unit_001085a8.cpp

u64 func_00109060(u32 a0, u32 a1, u32 a2, u32 a3);  // 00109060: moved to src/anon/unit_001085a8.cpp

u64 func_00109068(u32 a0, u32 a1, u32 a2, u32 a3);  // 00109068: moved to src/anon/unit_001085a8.cpp

void func_00109330(u32 a0, u32 a1, u32 a2, u32 a3);  // 00109330: moved to src/anon/unit_001085a8.cpp

void func_0010f8f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0010f8f0: definition moved into src/anon/unit_0010f338.cpp

f32 func_00112c28(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00112c28: definition moved into src/anon/unit_001117d8.cpp

f32 func_00112c38(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00112c38: definition moved into src/anon/unit_001117d8.cpp

f32 func_001142a0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001142a0: definition moved into src/anon/unit_001142a0.cpp

f32 func_001142b0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001142b0: definition moved into src/anon/unit_001142a0.cpp

f32 func_001142c0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001142c0: definition moved into src/anon/unit_001142a0.cpp

f32 func_001142d0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001142d0: definition moved into src/anon/unit_001142a0.cpp

f32 func_00114380(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00114380: definition moved into src/anon/unit_001142a0.cpp

f32 func_00114390(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00114390: definition moved into src/anon/unit_001142a0.cpp

// 00136b48: moved to src/harata/libdk/bgm.cpp

// 00136b60: moved to src/harata/libdk/bgm.cpp

// 00136b78: moved to src/harata/libdk/bgm.cpp

void func_001395a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = *(u32*)((u32)a0 + (12));
    v &= (u32)((s32)-65);
    *(u32*)((u32)a0 + (12)) = v;
}

void func_001395f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = *(u32*)((u32)a0 + (12));
    v &= (u32)((s32)-9);
    *(u32*)((u32)a0 + (12)) = v;
}

u32 func_001396c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = *(u32*)((u32)a0 + (12));
    v &= 0x0002u;
    return (v != 0);
}

void func_001396e0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001396e0: definition moved into src/anon/unit_001393c8.cpp

void func_00139718(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00139718: definition moved into src/anon/unit_001393c8.cpp

void func_0013d7c0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013d7c0: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013ef70(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013ef70: definition moved into src/anon/unit_0013ef70.cpp

void func_0013f020(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013f020: definition moved into src/anon/unit_0013ef70.cpp

void func_00140f10(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00140f10: definition moved into src/anon/unit_0013fca8.cpp

void func_00140f20(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00140f20: definition moved into src/anon/unit_0013fca8.cpp

f32 func_00141070(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00141070: definition moved into src/anon/unit_0013fca8.cpp

void func_001431c0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001431c0: definition moved into src/anon/unit_00142c90.cpp

void func_00143268(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00143268: definition moved into src/anon/unit_00142c90.cpp

void func_00143298(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00143298: definition moved into src/anon/unit_00142c90.cpp

// 00149308: moved to src/harata/libdk/mapfile.cpp

// 00149320: moved to src/harata/libdk/mapfile.cpp

// 00149338: moved to src/harata/libdk/mapfile.cpp

void func_0014a238(u32 a0, u32 a1, u32 a2, u32 a3);  // 0014a238: moved to src/anon/unit_00149fa8.cpp

void func_0014acd8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014acd8: definition moved into src/harata/libdk/fade.cpp

// 0014b248: moved to src/anon/unit_0014b150.cpp

void func_0014ce50(f32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014ce50: definition moved into src/anon/unit_0014c7f0.cpp

f32 func_0014ce78(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0014ce78: definition moved into src/anon/unit_0014c7f0.cpp

// 0014dda0: moved to src/anon/unit_0014d680.cpp

// 0014df88: moved to src/anon/unit_0014d680.cpp

// 0015ced0: moved to src/anon/unit_0015cdb0.cpp

// 0015cee0: moved to src/anon/unit_0015cdb0.cpp

// 0015f278: moved to src/harata/libdk/map_effect.cpp

// 00160d38: moved to src/harata/libdk/bgobj.cpp

void func_001617c8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001617c8: definition moved into src/anon/unit_001614e8.cpp

void func_0016fa98(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0016fa98: definition moved into src/anon/unit_0016e8f8.cpp

void func_0018c480(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0018c480: definition moved into src/yasui/libys/npc.cpp

// 00191c30: moved to src/yasui/libys/status.cpp

void func_0019ef60(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0019ef60: definition moved into src/anon/unit_0019ee80.cpp

// 001a36e0: moved to src/anon/unit_001a2a50.cpp

// 001a36f8: moved to src/anon/unit_001a2a50.cpp

u32 func_001aae68(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001aae68: definition moved into src/anon/unit_001aaa08.cpp

u32 func_001b6d70(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b6d70: definition moved into src/anon/unit_001b6a50.cpp

u32 func_001b77d0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b77d0: definition moved into src/anon/unit_001b6a50.cpp

u32 func_001b77e8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b77e8: definition moved into src/anon/unit_001b6a50.cpp

u32 func_001b7800(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b7800: definition moved into src/anon/unit_001b6a50.cpp

// 001bb270: moved to src/yasui/libys/mission.cpp

// 0x1c8cc0: moved to src/yasui/libys/summon.cpp

void func_001d1708(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d1708: definition moved into src/anon/unit_001d14e0.cpp

u32 func_001d56c8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d56c8: definition moved into src/anon/unit_001d4f40.cpp

void func_001d5a38(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d5a38: definition moved into src/anon/unit_001d4f40.cpp

void func_001dcd58(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001dcd58: definition moved into src/anon/unit_001dbfd8.cpp

void func_001ddb58(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001ddb58: definition moved into src/anon/unit_001dd920.cpp

void func_001e2c80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e2c80: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e7008(f32 a0, u32 a1, u32 a2, u32 a3);  // 0x001e7008: definition moved into src/anon/unit_001e0cb8.cpp

void func_00224998(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00224998: definition moved into src/anon/unit_00224780.cpp

void func_002249c8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002249c8: definition moved into src/anon/unit_00224780.cpp

void func_00225280(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00225280: definition moved into src/anon/unit_00224780.cpp

void func_00225530(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00225530: definition moved into src/anon/unit_00224780.cpp

void func_002259f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002259f0: definition moved into src/anon/unit_00224780.cpp

void func_00225a10(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00225a10: definition moved into src/anon/unit_00224780.cpp

void func_002272a8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002272a8: definition moved into src/anon/unit_00224780.cpp

void func_00232100(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00232100: definition moved into src/anon/unit_00231500.cpp

void func_002373a8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002373a8: definition moved into src/anon/unit_00237068.cpp

void func_0023d1d0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0023d1d0: definition moved into src/anon/unit_0023c968.cpp

void func_0023ebd0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0023ebd0: definition moved into src/anon/unit_0023e5d0.cpp

void func_0023ed90(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0023ed90: definition moved into src/anon/unit_0023e5d0.cpp

void func_00241a60(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00241a60: definition moved into src/anon/unit_0023f5b8.cpp

void func_00242408(u32 a0, u32 a1, u32 a2, u32 a3);  // 00242408: moved to src/tozawa/crc.cpp (linked unit)

u32 func_00281128(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00281128: definition moved into src/anon/unit_0027f2b0.cpp

void func_00287c20(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00287c20: definition moved into src/anon/unit_00286d28.cpp


void func_0028b200(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0028b200: definition moved into src/anon/unit_00288b00.cpp

void func_00293bb0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00293bb0: definition moved into src/anon/unit_00292e60.cpp

void func_0029ae30(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0029ae30: definition moved into src/anon/unit_00299920.cpp

u32 func_002b3b60(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002b3b60: definition moved into src/anon/unit_002b3ac8.cpp

void func_002ba600(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002ba600: definition moved into src/anon/unit_002b9ab8.cpp

extern "C" void func_002bc788(u32, u32, u32, u32) asm("_ZN5SOUND11SE3DDisableEv");

void func_002bd218(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002bd218: definition moved into src/anon/unit_002bc978.cpp

void func_002be760(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002be760: definition moved into src/anon/unit_002be020.cpp

void func_002bea10(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002bea10: definition moved into src/anon/unit_002be020.cpp

u32 func_002c5140(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002c5140: definition moved into src/anon/unit_002c4ca8.cpp

// 002c65f8: moved to src/anon/unit_002c6420.cpp (linked unit)

u32 func_002c83a8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x2c83a8: moved to src/anon/unit_002c7e68.cpp


u32 func_002c9e90(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x2c9e90: moved to src/anon/unit_002c9998.cpp


void func_002d1f40(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d1f40: definition moved into src/anon/unit_002cf260.cpp

// 002e7688: moved to src/anon/unit_002e7658.cpp

void func_0031e938(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0031e938: definition moved into src/anon/unit_0031e268.cpp

void func_00320400(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00320400: definition moved into src/anon/unit_0031f2f8.cpp
// 001bbcb0: moved to src/yasui/libys/mission.cpp

// 0x1c8ab0: moved to src/yasui/libys/summon.cpp
void func_001396b0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001396b0: definition moved into src/anon/unit_001393c8.cpp
