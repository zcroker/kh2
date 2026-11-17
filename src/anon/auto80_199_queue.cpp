#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

extern "C" u32 YS_STATUS_IsBattleMode(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
extern "C" u32 func_001dc9d0(u32) asm("_ZN3ryj6EFFECT8is_aliveEv");

extern "C" void RECOM_FLAG_clear_0019f578(u32) asm("_ZN2YS10RECOM_FLAG5clearEv");

namespace Tz { class Select { public: u32 isCursorMove(); u32 isSelectTopMove(); }; }

u32 func_001003c8(u32 a0) {  // classify_arg_masked3
    a0 &= 0xFFu;
    u32 v0 = 0;
    if (a0 == 0xFFu) {
        return v0;
    }

    u32 t = a0 & 7u;
    v0 = 2;
    if (t == 2u) {
        return v0;
    }
    if ((s32)t < 3) {
        if (t != 0u) {
            v0 = 4;
            func_002fd160();
        }
        return 4;
    }

    if (t == 3u) {
        return 4;
    }
    if (t == 4u) {
        return 8;
    }
    func_002fd160();
}

void func_00100350(void) {
    if (func_00100690 != 0) {
        func_00100690(&D_00378ae8, (u32)&D_0037aa08);
    }

    if (*(u32*)&D_0037a4b0 != 0) {
        if (func_00000000 != 0) {
            func_00000000(&D_0037a4b0);
        }
    }
}

// 001022e8: moved to src/global/unit_001022c0.cpp

// 00103bb0: MENU::SetGameMode, moved to src/common/unit_001031b0.cpp

// 00104018 GUMIBATTLE::Ensure: moved to src/common/gumibattle.cpp

// 00104e98: moved to src/common/area.cpp

// 00105140: moved to src/common/area.cpp

// 00105310: moved to src/common/area.cpp

u32 func_00105870() {
    s32 v = func_00105c30();
    s32 c;
    switch (v) {
    case 2:
        c = 85;
        break;
    case 1:
    case 8:
        c = 74;
        break;
    default:
        c = 69;
        break;
    }
    return ((u32)c << 24) | 0x0032484b;
}

// 00106178: moved to src/naka/libkn/memoryallocator.cpp

// 00106358: moved to src/naka/libkn/memoryallocator.cpp

u32 func_001085a8(u32 a0, const u8* a1);  // 001085a8: moved to src/anon/unit_001085a8.cpp

void func_00108998(u8* a0);  // 00108998: moved to src/anon/unit_001085a8.cpp

void func_00108a10(u8* a0);  // 00108a10: moved to src/anon/unit_001085a8.cpp

u64 func_00108d68(u8* a0, u64 a1);  // 00108d68: moved to src/anon/unit_001085a8.cpp

u64 func_00108dd8(u8* a0, u64 a1);  // 00108dd8: moved to src/anon/unit_001085a8.cpp

u64 func_00108e48(u8* a0, u64 a1);  // 00108e48: moved to src/anon/unit_001085a8.cpp

u64 func_00108eb8(u8* a0, u64 a1);  // 00108eb8: moved to src/anon/unit_001085a8.cpp

u64 func_00108f28(u8* a0, u64 a1);  // 00108f28: moved to src/anon/unit_001085a8.cpp

u64 func_00108f98(u8* a0, u64 a1);  // 00108f98: moved to src/anon/unit_001085a8.cpp

void func_00109280(void* a0);  // 00109280: moved to src/anon/unit_001085a8.cpp

u32 func_001093c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);  // 001093c8: moved to src/anon/unit_001085a8.cpp

void func_0010a580(u32 a0);  // 0010a580: moved to src/anon/unit_00109c30.cpp

void func_0010c850(u8* a0);  // 0x0010c850: definition moved into src/anon/unit_0010b978.cpp

void func_0010cb50(u8* a0, s32 a1, u32 a2);  // 0x0010cb50: definition moved into src/anon/unit_0010b978.cpp

u32 func_0010cc80(u8* a0);  // 0x0010cc80: definition moved into src/anon/unit_0010b978.cpp

void func_0010fa68(u8* a0);  // 0x0010fa68: definition moved into src/anon/unit_0010f338.cpp

void func_00110630(u8* a0);  // 0x00110630: definition moved into src/anon/unit_0010fea0.cpp

void func_00110960(u8* a0, u32 a1, u32 a2, u32 a3);  // 0x00110960: definition moved into src/anon/unit_0010fea0.cpp

u32 func_00112cc8(s32* a0);  // 0x00112cc8: definition moved into src/anon/unit_001117d8.cpp

void func_001132d8(u32 a0, u32 a1, u32 a2);  // 0x001132d8: definition moved into src/anon/unit_001117d8.cpp

u8 func_00113990(u32 param_1, u32 param_2, u32 param_3, u32* param_4, u8 param_5);  // 0x00113990: definition moved into src/anon/unit_00113628.cpp

void func_00115128(u32 param_1, u32 param_2);  // 0x00115128: definition moved into src/anon/unit_00114a90.cpp

void func_00116938(u32 param_1, f32* param_2, f32* param_3);  // 0x00116938: definition moved into src/anon/unit_00114a90.cpp

void func_00116990(u32 param_1, f32* param_2, f32* param_3);  // 0x00116990: definition moved into src/anon/unit_00114a90.cpp

u32 func_0011a7f0(u8* a0, u8* a1, u32* a2, u32* a3, u32 a4);  // 0x0011a7f0: definition moved into src/anon/unit_0011a660.cpp

u32 func_0011b7b0(u32 a0, f32* a1);  // 0x0011b7b0: definition moved into src/anon/unit_0011b3f8.cpp

u32 func_0011b868(u32 a0, f32* a1);  // 0x0011b868: definition moved into src/anon/unit_0011b3f8.cpp

f32 func_0011bdc0(f32* a0, u32 a1, u32 a2);  // 0x0011bdc0: definition moved into src/anon/unit_0011b3f8.cpp

void func_0011c2d0(u8* a0);  // 0x0011c2d0: definition moved into src/anon/unit_0011c128.cpp

void func_0011c438(u8* a0);  // 0x0011c438: definition moved into src/anon/unit_0011c128.cpp

void func_0011ea98(u32 a0, u32 a1);  // 0x0011ea98: definition moved into src/anon/unit_0011c128.cpp

void func_0011eb08(u32 a0, u32 a1);  // 0x0011eb08: definition moved into src/anon/unit_0011c128.cpp

void func_0011eb78(u32 a0, u32 a1);  // 0x0011eb78: definition moved into src/anon/unit_0011c128.cpp

void func_0011ec28(u8* a0, u32 a1, u32 a2, u32 a3);  // 0x0011ec28: definition moved into src/anon/unit_0011c128.cpp

u32 func_00124140(u8* a0);  // 0x00124140: definition moved into src/anon/unit_00123990.cpp

void func_00127c70(u32 a0, Obj* a1, u32 a2);  // 0x00127c70: definition moved into src/anon/unit_00127a88.cpp

u32 func_00129008(u32 a0, u32 a1, u8* a2, u32 a3, u32 a4, u32 a5);  // 0x00129008: definition moved into src/anon/unit_00128480.cpp

u32 func_00132208(u32 a0);  // 0x00132208: definition moved into src/anon/unit_00131418.cpp

void func_00133598(u32 a0, u32 a1, u32 a2);  // 0x00133598: definition moved into src/anon/unit_00131418.cpp

void func_00133de8(void);  // 0x00133de8: definition moved into src/anon/unit_00133cf0.cpp

void func_00133e50(void);  // 0x00133e50: definition moved into src/anon/unit_00133cf0.cpp

void func_00133ea8(void);  // 0x00133ea8: definition moved into src/anon/unit_00133cf0.cpp

// 00135818: moved to src/naka/libkn/obj_observer.cpp

// 001364b8: moved to src/harata/libdk/bgse.cpp

// 001372d8: moved to src/harata/libdk/bgm.cpp

// 00137340: moved to src/harata/libdk/bgm.cpp

// 001373d8: moved to src/harata/libdk/bgm.cpp

void func_00138d60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);  // 0x00138d60: definition moved into src/anon/unit_00138480.cpp

void func_001390f0(u32 a0);  // 0x001390f0: definition moved into src/anon/unit_00138480.cpp

void func_00139200(u32 a0);  // 0x00139200: definition moved into src/anon/unit_001391c8.cpp

void func_00139280(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 v0 = func_00102788(*(u32*)D_00347f80, 0, a1, (u32)func_00139200);
    u32 t = D_00347f80;

    *(u32*)(v0 + 8) = s1;
    *(u32*)(v0 + 4) = t;
    *(u32*)(s1 + 20) = v0;

    u32 head = D_00347f80;
    u32 p = head + 4;
    u32 n = *(u32*)(p + 4);

    if (n == 0) {
        *(u32*)(p + 4) = s1;
        *(u32*)(head + 4) = s1;
        *(u32*)(s1 + 4) = 0;
        return;
    }

    *(u32*)(n + 4) = s1;
    *(u32*)(s1 + 4) = 0;
    *(u32*)(p + 4) = s1;
}

void func_0013a8f8(void);  // 0x0013a8f8: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013b128(u32 a0);  // 0x0013b128: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013b348(u32 a0);  // 0x0013b348: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013b3f8(void);  // 0x0013b3f8: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013b458(void);  // 0x0013b458: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013b838(u32 a0);  // 0x0013b838: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013b8e8(u32 a0, s32 a1, s32 a2);  // 0x0013b8e8: definition moved into src/anon/unit_0013a8b8.cpp

u32 func_0013b988(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);  // 0x0013b988: definition moved into src/anon/unit_0013a8b8.cpp

u32 func_0013d390(u32 a0);  // 0x0013d390: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013d4c8(void);  // 0x0013d4c8: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013daf8(void);  // 0x0013daf8: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013dfb8(u32 a0);  // 0x0013dfb8: definition moved into src/anon/unit_0013dfb8.cpp

void func_0013e520(u32 a0, u32 a1);  // 0x0013e520: definition moved into src/anon/unit_0013dfb8.cpp

void func_0013e808(void);  // 0x0013e808: definition moved into src/anon/unit_0013dfb8.cpp

u32 func_0013ef90(u32 a0);  // 0x0013ef90: definition moved into src/anon/unit_0013ef70.cpp

u32 func_0013f230(void);  // 0x0013f230: definition moved into src/anon/unit_0013ef70.cpp

u32 func_0013f288(void);  // 0x0013f288: definition moved into src/anon/unit_0013ef70.cpp

u32 func_0013f378(void);  // 0x0013f378: definition moved into src/anon/unit_0013ef70.cpp

u32 func_0013f3d0(void);  // 0x0013f3d0: definition moved into src/anon/unit_0013ef70.cpp

void func_00140d38(u32 a0, u32 a1);  // 0x00140d38: definition moved into src/anon/unit_0013fca8.cpp

void func_00143060(u32 a0);  // 0x00143060: definition moved into src/anon/unit_00142c90.cpp

void func_00143110(u32 a0);  // 0x00143110: definition moved into src/anon/unit_00142c90.cpp

void func_001433e8(void);  // 0x001433e8: definition moved into src/anon/unit_00142c90.cpp

u32 func_00143e50(u32 a0, u32 a1, u32 a2);  // 0x00143e50: definition moved into src/anon/unit_00142c90.cpp

u32 func_00144d10(f32* a0, f32* a1);  // 0x00144d10: definition moved into src/anon/unit_00144450.cpp

u32 func_00144d90(f32* a0, f32* a1);  // 0x00144d90: definition moved into src/anon/unit_00144450.cpp

void func_001461f0(u32 a0, u8* a1);  // 0x001461f0: definition moved into src/anon/unit_00145600.cpp

void func_00148ac0(u8* a0);  // 0x00148ac0: definition moved into src/anon/unit_00147140.cpp

void func_00148bc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x00148bc8: definition moved into src/anon/unit_00147140.cpp

// 001491d8: moved to src/harata/libdk/mapfile.cpp

// 0014ddb0: moved to src/anon/unit_0014d680.cpp

u32 func_0014f788(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);  // 0x0014f788: definition moved into src/anon/unit_0014ecb8.cpp

void func_00150260(u32 a0, u32 a1, s32 a2, u32 a3);  // 0x00150260: definition moved into src/anon/unit_0014ecb8.cpp

void func_001505b0(u32 a0);  // 0x001505b0: definition moved into src/anon/unit_0014ecb8.cpp

void func_00150678(u32 a0);  // 0x00150678: definition moved into src/anon/unit_0014ecb8.cpp

void func_00151528(u32 a0);  // 0x00151528: definition moved into src/anon/unit_0014ecb8.cpp

void func_00151b78(u32 a0);  // 0x00151b78: definition moved into src/anon/unit_0014ecb8.cpp

void func_00151bf0(u32 a0);  // 0x00151bf0: definition moved into src/anon/unit_0014ecb8.cpp

void func_00152718(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00152718: definition moved into src/anon/unit_0014ecb8.cpp

void func_001527b8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001527b8: definition moved into src/anon/unit_0014ecb8.cpp

void func_00152910(u32 a0);  // 0x00152910: definition moved into src/anon/unit_0014ecb8.cpp

void func_00152a30(u32 a0);  // 0x00152a30: definition moved into src/anon/unit_0014ecb8.cpp

void func_00152ae8(u32 a0);  // 0x00152ae8: definition moved into src/anon/unit_0014ecb8.cpp

void func_00153cc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);  // 0x00153cc8: definition moved into src/anon/unit_00153678.cpp

// 00153ea0: moved to src/anon/unit_00153ea0.cpp
void func_00153ea0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

// 001541d8: moved to src/anon/unit_00153ea0.cpp
u32 func_001541d8(u32 a0, u32 a1, u32 a2);

// 001543a0: moved to src/anon/unit_00153ea0.cpp
void func_001543a0(u32 a0, u32 a1, u32 a2);

// 00154450: moved to src/anon/unit_00153ea0.cpp
u32 func_00154450(u32 a0, u32 a1, u32 a2);

// 00154a88: moved to src/anon/unit_00153ea0.cpp
void func_00154a88(u32 a0);

// 00155300: moved to src/anon/unit_00153ea0.cpp
void func_00155300(u32 a0);

// 00155390: moved to src/anon/unit_00153ea0.cpp
void func_00155390(u32 a0, u32 a1);

// 001554c0: moved to src/anon/unit_00153ea0.cpp
void func_001554c0(u32 a0);

// 001556f0: moved to src/anon/unit_00153ea0.cpp
void func_001556f0(u32 a0);

// 00155d80: moved to src/anon/unit_00153ea0.cpp
u32 func_00155d80(u32 a0);

// 00156408: moved to src/anon/unit_00153ea0.cpp
void func_00156408(u32 a0);

// 001564b0: moved to src/anon/unit_00153ea0.cpp
u32 func_001564b0(u32 a0, u32 a1, u32 a2, u32 a3);

// 00156540: moved to src/anon/unit_00153ea0.cpp
u32 func_00156540(u32 a0);

// 00157758: moved to src/anon/unit_00157688.cpp

// 001577c8: moved to src/anon/unit_00157688.cpp

// 00157880: moved to src/anon/unit_00157688.cpp

// 00157a00: moved to src/anon/unit_00157688.cpp

// 00158088: moved to src/anon/unit_00158050.cpp

// 001580e0: moved to src/anon/unit_00158050.cpp

// 00158138: moved to src/anon/unit_00158050.cpp

// 001581f8: moved to src/anon/unit_00158050.cpp

// 001582a8: moved to src/anon/unit_00158050.cpp

// 00158658: moved to src/harata/libdk/cannoncamera.cpp

// 0015a708: moved to src/harata/libdk/targetcamera.cpp

void func_0015ad28(u32 a0);  // 0x0015ad28: definition moved into src/anon/unit_0015a810.cpp

void func_0015ad80(u32 a0, u32 a1, f32 a2);  // 0x0015ad80: definition moved into src/anon/unit_0015a810.cpp

void func_0015b578(u32 a0);  // 0x0015b578: definition moved into src/anon/unit_0015b100.cpp

void func_0015b5d8(u32 a0);  // 0x0015b5d8: definition moved into src/anon/unit_0015b100.cpp

// 0015ee90: moved to src/harata/libdk/map.cpp

// 0015f738: moved to src/harata/libdk/map_effect.cpp

// 00160960: moved to src/harata/libdk/bgobj.cpp

void func_00161668(u8* a0, f32 a1) {
    if (*(u32*)(a0 + 72) == 0) {
        return;
    }

    f32 f0 = *(f32*)(a0 + 76) + a1;
    *(f32*)(a0 + 76) = f0;
    func_001616f0((u32)a0, f0);

    f32 f2 = *(f32*)(a0 + 80);
    f32 f1 = *(f32*)(a0 + 76);
    if (f2 < f1) {
        *(f32*)(a0 + 76) = f1 - f2;
        return func_001616f0((u32)a0, f2);
    }
}

u32 func_00168f18();  // 0x00168f18: definition moved into src/anon/unit_00168aa0.cpp

void func_00168fd8(u32 a0);  // 0x00168fd8: definition moved into src/anon/unit_00168aa0.cpp

void func_00169f98(u8* a0);  // 0x00169f98: definition moved into src/anon/unit_00169f98.cpp

u32 func_0016ad68(u32 a0, u32 a1, f32 f12);  // 0x0016ad68: definition moved into src/anon/unit_00169f98.cpp

f32 func_0016ae58(u8* a0, f32 f12);  // 0x0016ae58: definition moved into src/anon/unit_00169f98.cpp

u32 func_0016aef0(u32 a0, u32 a1);  // 0x0016aef0: definition moved into src/anon/unit_00169f98.cpp

f32 func_0016b558(u32 a0, u32 a1);  // 0x0016b558: definition moved into src/anon/unit_00169f98.cpp

void func_0016b5b8(u8* a0);  // 0x0016b5b8: definition moved into src/anon/unit_00169f98.cpp

u32 func_0016bba8(u8* a0, u32 a1, u32 a2);  // 0x0016bba8: definition moved into src/anon/unit_00169f98.cpp

u32 func_0016bc98(u8* a0, u32 a1, u32 a2);  // 0x0016bc98: definition moved into src/anon/unit_00169f98.cpp

u32 func_0016bda8(u32 a0, u32 a1);  // 0x0016bda8: definition moved into src/anon/unit_00169f98.cpp

// 0016cce8: moved to src/anon/unit_0016c770.cpp

// 0016cf00: moved to src/anon/unit_0016c770.cpp

// 0016cff0: moved to src/anon/unit_0016c770.cpp

// 0016d080: moved to src/anon/unit_0016c770.cpp

// 0016d698: moved to src/anon/unit_0016d2e0.cpp

// 0016db20: moved to src/anon/unit_0016d2e0.cpp

void func_0016ef58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);  // 0x0016ef58: definition moved into src/anon/unit_0016e8f8.cpp

void func_0016fb30(u8* a0, u32 a1, u32 a2, u32 a3);  // 0x0016fb30: definition moved into src/anon/unit_0016e8f8.cpp

void func_0016fba0(u8* a0, u32 a1, u32 a2, u32 a3);  // 0x0016fba0: definition moved into src/anon/unit_0016e8f8.cpp

void func_00170888(u32 a0);  // 0x00170888: definition moved into src/anon/unit_0016e8f8.cpp

u32 func_00170978(u32 a0);  // 0x00170978: definition moved into src/anon/unit_0016e8f8.cpp

void func_001709d0(s32 a0);  // 0x001709d0: definition moved into src/anon/unit_0016e8f8.cpp

void func_00171740(u32* a0);  // 0x00171740: definition moved into src/anon/unit_00170f58.cpp

void func_00171998(u32 a0);  // 0x00171998: definition moved into src/anon/unit_00170f58.cpp

void func_00171ac8(u32* a0);  // 0x00171ac8: definition moved into src/anon/unit_00170f58.cpp

void func_001731e0(u32* a0);  // 0x001731e0: definition moved into src/anon/unit_00171e58.cpp

u32 func_00173450(u32 a0);  // 0x00173450: definition moved into src/anon/unit_00171e58.cpp

u32 func_001734b0(u32 a0);  // 0x001734b0: definition moved into src/anon/unit_00171e58.cpp

void func_00173c70(u32 a0);  // 0x00173c70: definition moved into src/anon/unit_00171e58.cpp

void func_00174388(u32 a0);  // 0x00174388: definition moved into src/anon/unit_00171e58.cpp

// 001758b0: moved to src/yasui/libys/party.cpp

// 00175af8: moved to src/yasui/libys/party.cpp

// 00176760: moved to src/yasui/libys/party.cpp

// 00176fb0: moved to src/yasui/libys/party.cpp

// 001774e0: moved to src/yasui/libys/party.cpp

// 001778c0: moved to src/yasui/libys/party.cpp

// 001779d0: moved to src/yasui/libys/party.cpp

// 00177d30: moved to src/yasui/libys/party.cpp

// 001782c8: moved to src/yasui/libys/player.cpp

// 00179c08: moved to src/yasui/libys/player.cpp

// 00179e48: moved to src/yasui/libys/player.cpp

// 00179eb8: moved to src/yasui/libys/player.cpp

// 0017a3b0: moved to src/yasui/libys/player.cpp

// 0017a480: moved to src/yasui/libys/player.cpp

// 0017a590: moved to src/yasui/libys/player.cpp

// 0017bf40: moved to src/anon/unit_0017bf40.cpp

// 0017bfa0: moved to src/anon/unit_0017bf40.cpp

// 0017dee8: moved to src/yasui/libys/friend.cpp

// 0017df70: moved to src/yasui/libys/friend.cpp

// 0017e030: moved to src/yasui/libys/friend.cpp

// 0017e0b0: moved to src/yasui/libys/friend.cpp

// 0017e210: moved to src/yasui/libys/friend.cpp

// 0017e3b8: moved to src/yasui/libys/friend.cpp

// 0017e668: moved to src/yasui/libys/friend.cpp

// 0017f430: moved to src/yasui/libys/motion.cpp

// 0017f540: moved to src/yasui/libys/motion.cpp

// 0017fd60: moved to src/yasui/libys/motion.cpp

// 0017fff8: moved to src/yasui/libys/motion.cpp

// 001802d8: moved to src/yasui/libys/motion.cpp

// 00180510: moved to src/anon/unit_00180408.cpp

// 00180698: moved to src/anon/unit_00180408.cpp

// 001806f8: moved to src/anon/unit_00180408.cpp

// 00181778: moved to src/yasui/libys/progress.cpp

// 00181c28: moved to src/yasui/libys/areadata.cpp

// 00181d30: moved to src/yasui/libys/areadata.cpp

// 00182860 YS::UNIT::~UNIT: moved to src/anon/unit_00182780.cpp

// 001828b8 YS::UNIT::~UNIT: moved to src/anon/unit_00182780.cpp

// 001844e8: moved to src/anon/unit_00183088.cpp

// 00185be0: moved to src/anon/unit_001855e0.cpp

// 00186020: moved to src/anon/unit_00185d10.cpp
void func_00186020(u32 a0);

// 00187890: moved to src/anon/unit_00185d10.cpp
void func_00187890(u32 a0);

// 001881f8: moved to src/anon/unit_00185d10.cpp
void func_001881f8(u32 a0, u32 a1);

// 001880b0: moved to src/anon/unit_00185d10.cpp
void func_001880b0(u32 a0, u32 a1);

// 00188250: moved to src/anon/unit_00185d10.cpp
void func_00188250(u32 a0, u32 a1);

void func_00189258(u32 a0);  // 0x00189258: definition moved into src/anon/unit_00188848.cpp

void func_0018b988(u32 a0);  // 0x0018b988: definition moved into src/yasui/libys/npc.cpp

void func_0018bb70(u32 a0, u32 a1, u32 a2, u32 a3, float f12);  // 0x0018bb70: definition moved into src/yasui/libys/npc.cpp

// 0018c960: moved to src/yasui/libys/damage.cpp

void func_0018ea40(u32 a0, u32 a1);  // 0x0018ea40: definition moved into src/anon/unit_0018d050.cpp

void func_0018f6c0(u32 a0);  // 0x0018f6c0: definition moved into src/anon/unit_0018f140.cpp

void func_0018f718(u32 a0);  // 0x0018f718: definition moved into src/anon/unit_0018f140.cpp

void func_0018f9f8(u32 a0);  // 0x0018f9f8: definition moved into src/anon/unit_0018f140.cpp

void func_0018fa50(u32 a0);  // 0x0018fa50: definition moved into src/anon/unit_0018f140.cpp

u32 func_00190208(u32 a0, u32 a1);  // 0x00190208: definition moved into src/anon/unit_001900d0.cpp

// 00191b70: moved to src/yasui/libys/status.cpp

// 001923c8: moved to src/yasui/libys/message.cpp

// 001924c0: moved to src/yasui/libys/message.cpp

u32 func_00194010(u32 a0);  // 0x00194010: definition moved into src/anon/unit_00193be8.cpp

f32 func_00194690(u32 a0);  // 0x00194690: definition moved into src/anon/unit_00193be8.cpp

void func_00197280(u32 a0);  // 0x00197280: definition moved into src/anon/unit_00195d00.cpp

// 001984b8: moved to src/anon/unit_00197fe0.cpp

// 00198510: moved to src/anon/unit_00197fe0.cpp

// 001987a8: moved to src/anon/unit_00197fe0.cpp

void func_0019ab80(u32 a0);  // 0x0019ab80: definition moved into src/anon/unit_00199688.cpp

void func_0019b5d8(u32 a0, u32 a1);  // 0x0019b5d8: definition moved into src/anon/unit_00199688.cpp

void func_0019be88(u32 a0);  // 0x0019be88: definition moved into src/anon/unit_0019ba60.cpp

u32 func_0019c5d0(u32 a0);  // 0x0019c5d0: definition moved into src/anon/unit_0019ba60.cpp

u32 func_0019c6f0(u32 a0);  // 0x0019c6f0: definition moved into src/anon/unit_0019ba60.cpp

void func_0019ca90(u32 a0, u32 a1, u32 a2);  // 0x0019ca90: definition moved into src/anon/unit_0019ba60.cpp

void func_0019cc88(u32 a0, u32 a1);  // 0x0019cc88: definition moved into src/anon/unit_0019ba60.cpp

void func_0019eda0(u32 a0);  // 0x0019eda0: definition moved into src/anon/unit_0019ea10.cpp

void func_0019f610(u32 a0, u32 a1, u32 a2);  // 0x0019f610: definition moved into src/anon/unit_0019ee80.cpp

void func_0019f670(u32 a0, u32 a1, u32 a2);  // 0x0019f670: definition moved into src/anon/unit_0019ee80.cpp

void func_0019fd00(u32 a0, u32 a1, u32 a2);  // 0x0019fd00: definition moved into src/anon/unit_0019fb70.cpp

u32 func_0019fe90(u32 a0, u32 a1, u32, u32, u32, u32, u32, u32);  // 0x0019fe90: definition moved into src/anon/unit_0019fb70.cpp

u8* func_0019fee8(u8* a0, s32 a1, u32, u32, u32, u32, u32, u32);  // 0x0019fee8: definition moved into src/anon/unit_0019fb70.cpp

void func_001a0bc0();  // 0x001a0bc0: definition moved into src/anon/unit_0019fb70.cpp

void* func_001a0e78();  // 0x001a0e78: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a1540(u32 a0);  // 0x001a1540: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a15d0(u32 a0, s32 a1);  // 0x001a15d0: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a1728(u32 a0, u32 a1);  // 0x001a1728: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a1990(u32 a0, s32 a1);  // 0x001a1990: definition moved into src/anon/unit_0019fb70.cpp

u32 func_001a1cc0(u32 a0, u32 a1, u32 a2);  // 0x001a1cc0: definition moved into src/anon/unit_0019fb70.cpp

void func_001a26b8(u32 a0);  // 0x001a26b8: definition moved into src/anon/unit_0019fb70.cpp

void func_001a27f0(u32 a0, u32 a1);  // 0x001a27f0: definition moved into src/anon/unit_0019fb70.cpp

// 001a3570: moved to src/anon/unit_001a2a50.cpp

// 001a3710: moved to src/anon/unit_001a2a50.cpp

// 001a3788: moved to src/anon/unit_001a2a50.cpp

// 001a3bf0: moved to src/yasui/libys/effect.cpp

// 001a3c88: moved to src/yasui/libys/effect.cpp

// 001a4550: moved to src/anon/unit_001a3e70.cpp

// 001a5990: moved to src/anon/unit_001a4db0.cpp

// 001a5b68: moved to src/yasui/libys/prizetable.cpp

// 001a5d48: moved to src/yasui/libys/magic.cpp

// 001a5ec0: moved to src/yasui/libys/magic.cpp

// 001a6118: moved to src/yasui/libys/magic.cpp

// 001a6598: moved to src/yasui/libys/magic.cpp

// 001a6e88: moved to src/anon/unit_001a6a10.cpp

// 001a70a0: moved to src/anon/unit_001a6a10.cpp

void func_001a8618(u32 a0, u32 a1, u32 a2);  // 0x001a8618: definition moved into src/anon/unit_001a8618.cpp

s32 func_001a9018(u32 a0, s32 a1);  // 0x001a9018: definition moved into src/anon/unit_001a8618.cpp

void func_001a9218(u32* a0);  // 0x001a9218: definition moved into src/anon/unit_001a9130.cpp

void func_001a9350(u32* a0);  // 0x001a9350: definition moved into src/anon/unit_001a9130.cpp

u32 func_001a9808(u32 a0, s32 a1);  // 0x001a9808: definition moved into src/anon/unit_001a9130.cpp

void func_001a9860(u32* a0, u32 a1, u32 a2, u32 a3, u32 a4);  // 0x001a9860: definition moved into src/anon/unit_001a9130.cpp

void func_001aa850(s32* a0, s32 a1);  // 0x001aa850: definition moved into src/anon/unit_001a9130.cpp

void func_001aad28(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4, u32 a5);  // 0x001aad28: definition moved into src/anon/unit_001aaa08.cpp

u32 func_001ab820(u32 a0);  // 0x001ab820: definition moved into src/anon/unit_001ab598.cpp

// 001ac908: moved to src/anon/unit_001abb28.cpp

void func_001adea8();  // 0x001adea8: definition moved into src/anon/unit_001ada38.cpp

u32 func_001ae460(u32 a0);  // 0x001ae460: definition moved into src/anon/unit_001ada38.cpp

void func_001ae590(u32 a0, u32 a1);  // 0x001ae590: definition moved into src/anon/unit_001ada38.cpp

u32 func_001aea60(u32 a0);  // 0x001aea60: definition moved into src/anon/unit_001ada38.cpp

void func_001af210(u32 a0);  // 0x001af210: definition moved into src/anon/unit_001ada38.cpp

void func_001af290(u32 a0);  // 0x001af290: definition moved into src/anon/unit_001ada38.cpp

u32 func_001af8d8(u32 a0);  // 0x001af8d8: definition moved into src/anon/unit_001ada38.cpp

void func_001afa88(u32 a0);  // 0x001afa88: definition moved into src/anon/unit_001ada38.cpp

void func_001afaf0(u32 a0);  // 0x001afaf0: definition moved into src/anon/unit_001ada38.cpp

void func_001afb80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001afb80: definition moved into src/anon/unit_001ada38.cpp

void func_001b03b0(s32 a0, s32 a1);  // 0x001b03b0: definition moved into src/anon/unit_001ada38.cpp

// 001b04d8: moved to src/yasui/libys/lookat.cpp

// 001b1da0: moved to src/anon/unit_001b1d20.cpp

u32 func_001b2b80(u32 a0, u32 a1);  // 0x001b2b80: definition moved into src/anon/unit_001b2780.cpp

u32 func_001b3b10(u32 a0);  // 0x001b3b10: definition moved into src/anon/unit_001b2780.cpp

void func_001b3c00(u32 a0, u32 a1);  // 0x001b3c00: definition moved into src/anon/unit_001b2780.cpp

void func_001b3c58(u32 a0, u32 a1);  // 0x001b3c58: definition moved into src/anon/unit_001b2780.cpp

void func_001b4d10(u32 a0);  // 0x001b4d10: definition moved into src/anon/unit_001b2780.cpp

void func_001b4d70(u32 a0);  // 0x001b4d70: definition moved into src/anon/unit_001b2780.cpp

void func_001b5588(u32 a0);  // 0x001b5588: definition moved into src/anon/unit_001b2780.cpp

u32 func_001b5680(u32 a0);  // 0x001b5680: definition moved into src/anon/unit_001b2780.cpp

void func_001b57f8(u32 a0);  // 0x001b57f8: definition moved into src/anon/unit_001b2780.cpp

u32 func_001b5918(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b5918: definition moved into src/anon/unit_001b2780.cpp

void func_001b5f68(u32 a0);  // 0x001b5f68: definition moved into src/anon/unit_001b2780.cpp

void func_001b5fe0(u32 a0);  // 0x001b5fe0: definition moved into src/anon/unit_001b2780.cpp

void func_001b6450(u32 a0);  // 0x001b6450: definition moved into src/anon/unit_001b2780.cpp

void func_001b6518(u32 a0);  // 0x001b6518: definition moved into src/anon/unit_001b2780.cpp

void func_001b6e08(u32 a0, u32 a1);  // 0x001b6e08: definition moved into src/anon/unit_001b6a50.cpp

void func_001b6e90(u32 a0, u32 a1);  // 0x001b6e90: definition moved into src/anon/unit_001b6a50.cpp

u32 func_001b7038();  // 0x001b7038: definition moved into src/anon/unit_001b6a50.cpp

void func_001b7538(u32 a0, u32 a1);  // 0x001b7538: definition moved into src/anon/unit_001b6a50.cpp

u32 func_001b75e8(u32 a0, u32 a1, u32 a2);  // 0x001b75e8: definition moved into src/anon/unit_001b6a50.cpp

u32 func_001b7658(u32 a0, u32 a1, u32 a2);  // 0x001b7658: definition moved into src/anon/unit_001b6a50.cpp

void func_001b76c8(u32 a0, u32 a1, u32 a2);  // 0x001b76c8: definition moved into src/anon/unit_001b6a50.cpp

u32 func_001b7850(u32 a0, u32 a1, u32 a2);  // 0x001b7850: definition moved into src/anon/unit_001b6a50.cpp

// 001b8348 YS::LIBRETTO::Init: moved to src/anon/unit_001b82d8.cpp

// 001b8450: moved to src/anon/unit_001b82d8.cpp

// 001b8718: static initialiser, now made by gcc in src/anon/unit_001b82d8.cpp

void func_001b8bf8(u32 a0, u32 a1);  // 0x001b8bf8: definition moved into src/anon/unit_001b87a0.cpp

void func_001b8c70(u32 a0, u32 a1);  // 0x001b8c70: definition moved into src/anon/unit_001b87a0.cpp

void func_001b8da0();  // 0x001b8da0: definition moved into src/anon/unit_001b87a0.cpp

u32 func_001b91d0(u32 a0, u32 a1);  // 0x001b91d0: definition moved into src/anon/unit_001b87a0.cpp

void func_001b9230();  // 0x001b9230: definition moved into src/anon/unit_001b87a0.cpp

void func_001b9b28(u32 a0);  // 0x001b9b28: definition moved into src/anon/unit_001b9880.cpp

// 001ba528: moved to src/yasui/libys/itemeffect.cpp

// 001ba650: moved to src/yasui/libys/itemeffect.cpp

// 001ba6b0: moved to src/yasui/libys/itemeffect.cpp

// 001ba740: moved to src/yasui/libys/itemeffect.cpp

// 001bb020: moved to src/anon/unit_001ba7e0.cpp

// 001bb630: moved to src/yasui/libys/mission.cpp

// 001bb6d0: moved to src/yasui/libys/mission.cpp

// 001bb8f0: moved to src/yasui/libys/mission.cpp

// 001bbcf8: moved to src/yasui/libys/mission.cpp

// 001bbd58: moved to src/yasui/libys/mission.cpp

void func_001bc990(u32 a0, u32 a1);  // 0x001bc990: definition moved into src/anon/unit_001bc568.cpp

void func_001bd2d0(u32 a0, u32 a1, u32 a2);  // 0x001bd2d0: definition moved into src/anon/unit_001bc568.cpp

u32 func_001bd918(u32 a0, u32 a1, u32 a2);  // 0x001bd918: definition moved into src/anon/unit_001bc568.cpp

void func_001bdab0(u32 a0);  // 0x001bdab0: definition moved into src/anon/unit_001bc568.cpp

u32 func_001bdb10(u32 a0, u32 a1);  // 0x001bdb10: definition moved into src/anon/unit_001bc568.cpp

void func_001bdf68(u32 a0);  // 0x001bdf68: definition moved into src/anon/unit_001bc568.cpp

void func_001c36e8(u32 a0);  // 0x001c36e8: definition moved into src/anon/unit_001c2b58.cpp

u32 func_001c5c08(void* a0);  // 0x001c5c08: definition moved into src/anon/unit_001c5b90.cpp

// 001c6f10: moved to src/anon/unit_001c6e58.cpp (linked unit)

// 0x1c8290: moved to src/yasui/libys/summon.cpp

// 0x1c8838: moved to src/yasui/libys/summon.cpp

// 0x1c8ad8: moved to src/yasui/libys/summon.cpp

// 0x1c8bb8: moved to src/yasui/libys/summon.cpp

u32 func_001c9110(u32 a0, u32 a1);  // 0x001c9110: definition moved into src/anon/unit_001c8e80.cpp

void func_001c98f0(f32 a0);  // 0x001c98f0: definition moved into src/yasui/libys/sacrifice.cpp

void func_001ca830(u32, u8* a1);  // 0x001ca830: definition moved into src/anon/unit_001ca638.cpp

u32 func_001cbab0(Arg* a0);  // 0x001cbab0: definition moved into src/anon/unit_001ca8e0.cpp

// 001cc920: moved to src/anon/unit_001cc868.cpp

void func_001ceb40(u8* a0, u32 a1);  // 0x001ceb40: definition moved into src/anon/unit_001ce6e8.cpp

void func_001cec70(u32 a0, u32 a1, u32 a2);  // 0x001cec70: definition moved into src/anon/unit_001ce6e8.cpp

void func_001d0558(u8* a0);  // 0x001d0558: definition moved into src/anon/unit_001cf0b0.cpp

void func_001d05b8(u32 a0);  // 0x001d05b8: definition moved into src/anon/unit_001cf0b0.cpp

extern "C" u32 func_001d1438(u32) asm("_ZN2YS4SORA10GetEntryIdEi");

void func_001d17b0(u32 a0);  // 0x001d17b0: definition moved into src/anon/unit_001d14e0.cpp

void func_001d1a50(u32 a0);  // 0x001d1a50: definition moved into src/anon/unit_001d14e0.cpp

void func_001d1b60(u32 a0, s32 a1);  // 0x001d1b60: definition moved into src/anon/unit_001d14e0.cpp

void func_001d1d00(u32 a0);  // 0x001d1d00: definition moved into src/anon/unit_001d14e0.cpp

void func_001d20a8(u32 a0);  // 0x001d20a8: definition moved into src/anon/unit_001d14e0.cpp

void func_001d3c18(u32 a0);  // 0x001d3c18: definition moved into src/anon/unit_001d3c08.cpp

u32 func_001d3de0(u32 a0);  // 0x001d3de0: definition moved into src/anon/unit_001d3c08.cpp

u32 func_001d48e8(u32* a0);  // 0x001d48e8: definition moved into src/anon/unit_001d3c08.cpp

u32 func_001d4bd8(u32 a0, u32 a1, u32 a2);  // 0x001d4bd8: definition moved into src/anon/unit_001d3c08.cpp

void func_001d5770(u32* a0, u32 a1);  // 0x001d5770: definition moved into src/anon/unit_001d4f40.cpp

void func_001d5800(u16* a0);  // 0x001d5800: definition moved into src/anon/unit_001d4f40.cpp

u32 func_001d58f0(u32 a0);  // 0x001d58f0: definition moved into src/anon/unit_001d4f40.cpp

u32 func_001d5af8(u8* a0, s32 a1, u32 a2);  // 0x001d5af8: definition moved into src/anon/unit_001d4f40.cpp

u32 func_001d5bb8();  // 0x001d5bb8: definition moved into src/anon/unit_001d4f40.cpp

u32 func_001d5c10(u32 a0, u8* a1);  // 0x001d5c10: definition moved into src/anon/unit_001d4f40.cpp

u32 func_001d5c70(u32 a0, u8* a1);  // 0x001d5c70: definition moved into src/anon/unit_001d4f40.cpp

void func_001d6020(u32 a0, u32 a1);  // 0x001d6020: definition moved into src/anon/unit_001d4f40.cpp

u32 func_001d6578(u32 a0, u32 a1, f32 a2);  // 0x001d6578: definition moved into src/anon/unit_001d63a8.cpp

void func_001d6a28(u32 a0);  // 0x001d6a28: definition moved into src/anon/unit_001d68e0.cpp

void func_001d6ae0(u32 a0);  // 0x001d6ae0: definition moved into src/anon/unit_001d68e0.cpp

void func_001d6b40(u32 a0);  // 0x001d6b40: definition moved into src/anon/unit_001d68e0.cpp

void func_001d7000(u32 a0, u32 a1);  // 0x001d7000: definition moved into src/anon/unit_001d68e0.cpp

void func_001d7828();  // 0x001d7828: definition moved into src/anon/unit_001d7458.cpp

void func_001d7a88(u32 a0);  // 0x001d7a88: definition moved into src/anon/unit_001d7458.cpp

void func_001d7c38(u32 a0);  // 0x001d7c38: definition moved into src/anon/unit_001d7458.cpp

void func_001d8010(u32 a0);  // 0x001d8010: definition moved into src/anon/unit_001d7458.cpp

void func_001d80f0(u32 a0);  // 0x001d80f0: definition moved into src/anon/unit_001d7458.cpp

void func_001d8270(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d8270: definition moved into src/anon/unit_001d7458.cpp

void func_001d8310(s32 a0, u32 a1);  // 0x001d8310: definition moved into src/anon/unit_001d7458.cpp

u32 func_001d83c0(u32 a0);  // 0x001d83c0: definition moved into src/anon/unit_001d7458.cpp

void func_001d8470(u32 a0);  // 0x001d8470: definition moved into src/anon/unit_001d7458.cpp

void func_001d84e0(u32 a0);  // 0x001d84e0: definition moved into src/anon/unit_001d7458.cpp

void func_001d8578(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d8578: definition moved into src/anon/unit_001d7458.cpp

void func_001d8618(u32 a0, u32 a1);  // 0x001d8618: definition moved into src/anon/unit_001d7458.cpp

void func_001d8820(u32 a0);  // 0x001d8820: definition moved into src/anon/unit_001d7458.cpp

void func_001d8908(u32 a0);  // 0x001d8908: definition moved into src/anon/unit_001d7458.cpp

void func_001d8978(u32 a0, u32 a1);  // 0x001d8978: definition moved into src/anon/unit_001d7458.cpp

void func_001d8b68(u32 a0, u32 a1);  // 0x001d8b68: definition moved into src/anon/unit_001d7458.cpp

void func_001d8bd0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d8bd0: definition moved into src/anon/unit_001d7458.cpp

void func_001d8c70(u32 a0, f32 a1);  // 0x001d8c70: definition moved into src/anon/unit_001d7458.cpp

void func_001d8da0(u32 a0, f32 a1);  // 0x001d8da0: definition moved into src/anon/unit_001d7458.cpp

f32 func_001d8e38(u32 a0);  // 0x001d8e38: definition moved into src/anon/unit_001d7458.cpp

f32 func_001d8eb8(u32 a0);  // 0x001d8eb8: definition moved into src/anon/unit_001d7458.cpp

void func_001d9050(u32 a0, u32 a1, f32 a2);  // 0x001d9050: definition moved into src/anon/unit_001d7458.cpp

void func_001d90e0(u32 a0);  // 0x001d90e0: definition moved into src/anon/unit_001d7458.cpp

void func_001d91a8(u32 a0, u32 a1);  // 0x001d91a8: definition moved into src/anon/unit_001d7458.cpp

void func_001d9288(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d9288: definition moved into src/anon/unit_001d7458.cpp

void func_001d9388(u32 a0, u32 a1);  // 0x001d9388: definition moved into src/anon/unit_001d7458.cpp

void func_001d9418(u32 a0, u32 a1);  // 0x001d9418: definition moved into src/anon/unit_001d7458.cpp

void func_001d9488(u32 a0);  // 0x001d9488: definition moved into src/anon/unit_001d7458.cpp

void func_001d9768(u16* a0);  // 0x001d9768: definition moved into src/anon/unit_001d7458.cpp

void func_001da340(u32 a0, u32 a1);  // 0x001da340: definition moved into src/anon/unit_001d9d00.cpp

u32 func_001db610(u32 a0, Func_001db610_cb a1, u32 a2);  // 0x001db610: definition moved into src/anon/unit_001d9d00.cpp

void func_001dc8c8(u32 a0, f32 a1);  // 0x001dc8c8: definition moved into src/anon/unit_001dbfd8.cpp

void func_001dc978(u32 a0, f32 a1);  // 0x001dc978: definition moved into src/anon/unit_001dbfd8.cpp

void func_001dcf58(u32 a0);  // 0x001dcf58: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001dcff0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5);  // 0x001dcff0: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001dd098(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5);  // 0x001dd098: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001dd140(u32 a0);  // 0x001dd140: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de3d8(u32 a0, u32 a1);  // 0x001de3d8: definition moved into src/anon/unit_001ddcf0.cpp

// 001e0868: moved to src/rikeda/saveram_gumibattle.cpp

// 001e0ac0: moved to src/rikeda/saveram_gumibattle.cpp

void func_001e16c0(u32 a0);  // 0x001e16c0: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e18d8(u32 a0);  // 0x001e18d8: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e2938(u32 a0);  // 0x001e2938: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e5970(u32 a0);  // 0x001e5970: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e5990(u32 a0);  // 0x001e5990: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e74d8(u32 a0);  // 0x001e74d8: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e8fe0(u32 a0, u32 a1);  // 0x001e8fe0: definition moved into src/anon/unit_001e8ac8.cpp

void func_001f00f8(s32* a0) {
    s32 v = a0[0];
    if (v > 0x10000) {
        while (1) {
            s32 t = v + (s32)0xFFFF0000;
            if (t > 0x10000) {
                v = t;
            } else {
                a0[0] = t;
                break;
            }
        }
        v = a0[1];
    } else {
        v = a0[1];
    }

    if (v > 0x10000) {
        while (1) {
            s32 t = v + (s32)0xFFFF0000;
            if (t > 0x10000) {
                v = t;
            } else {
                a0[1] = t;
                break;
            }
        }
        v = a0[2];
    } else {
        v = a0[2];
    }

    if (v > 0x10000) {
        while (1) {
            s32 t = v + (s32)0xFFFF0000;
            if (t > 0x10000) {
                v = t;
            } else {
                a0[2] = t;
                break;
            }
        }
    }
}

void func_001fa7b0(u32 a0, u32 a1, u32 a2);  // 0x001fa7b0: definition moved into src/anon/unit_001fa1b8.cpp

void func_001fa950(u32 a0, u32 a1, u32 a2);  // 0x001fa950: definition moved into src/anon/unit_001fa1b8.cpp

void func_001facf8(u32 a0, u32 a1, u32 a2);  // 0x001facf8: definition moved into src/anon/unit_001fa1b8.cpp

void func_001fb558(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 0);
    u32 t7p = a0 + t7;
    u32 s2 = t7p + 160;
    func_001fa7b0(s0, s1, a2);

    u32 t6b = *(u32*)(s0 + 12);
    u32 t7b = *(u32*)(s1 + 0);
    if (t7b != t6b) {
        return;
    }
    f32 f0 = *(f32*)(s1 + 12);
    *(f32*)(s2 + 32) = f0;
}

void func_001fc678(u32 a0) {
    u32 buf[20];
    volatile u32* gp = (volatile u32*)0x01da0000;
    u32 s0 = *(u32*)(a0 + 4);
    u32 s2 = s0 + 16;
    u32 s3 = (u32)buf + 64;

    sceVu0Normalize((u32)buf, s2);  // vec4_normalize
    sceVu0Normalize((u32)buf + 16, s0 + 32);  // vec4_normalize
    u32 a0c = (u32)buf + 32;
    u32 a1c = s0 + 48;
    s0 = a1c;
    sceVu0Normalize(a0c, a1c);  // vec4_normalize

    u32 t6 = gp[-1606];
    sceVu0ApplyMatrix(s3, s2, t6 + 64);

    u32 t4 = gp[-1606] + 16;
    sceVu0MulMatrix(t4, (u32)buf, t4);

    u32 t5 = gp[-1606] + 64;
    sceVu0CopyVector(t5, s3);  // memcpy16
}

s32 func_00203a88(u32 a0) {
    u32 s0 = a0 & 0xFF;
    u32 t7 = s0 << 1;
    f32 f20 = (f32)(s32)t7;
    s0 = s0 >> 1;
    f32 f0 = func_00203a40();  // vu_const_5f
    f20 = f20 * f0;
    f0 = (f32)(s32)s0;
    f20 = f20 - f0;
    s32 v0 = (s32)f20;
    v0 = (v0 << 24) >> 24;
    return v0;
}

void func_00204fe0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t6 = a2;
    u32 s0 = a1;
    if (*(u8*)(t6 + 204) != 0) {
        return;
    }
    sceVu0MulMatrix(a1, a3, a1 + 256);
    sceVu0MulMatrix(s0 + 64, s0 + 128, s0);
}

void func_002070d0(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a0;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    u32 s0 = t5 + t7;
    u32 t6b = *(u8*)(s0 + 160);
    if (t6b != 0) {
        return;
    }
    u32 t4 = *(u32*)(t6 + 0);
    u32 a0p = t5 + t4;
    u32 v0 = func_002061f8(a0p + 160, a1);
    if (v0 == 0) {
        return;
    }
    *(u8*)(s0 + 160) = 1;
}

void func_00207150(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a0;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    u32 s0 = t5 + t7;
    u32 t6b = *(u8*)(s0 + 160);
    if (t6b != 0) {
        return;
    }
    u32 t4 = *(u32*)(t6 + 0);
    u32 a0p = t5 + t4;
    u32 v0 = func_002062c0(a0p + 160, a1);
    if (v0 == 0) {
        return;
    }
    *(u8*)(s0 + 160) = 1;
}

void func_002071d8(u32 a0, u32 a1, u32 a2) {
    u32 t5 = a0;
    u32 t6 = *(u32*)(a2 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    u32 s0 = t5 + t7;
    u32 t6b = *(u8*)(s0 + 160);
    if (t6b != 0) {
        return;
    }
    u32 t4 = *(u32*)(t6 + 0);
    u32 a0p = t5 + t4;
    u32 v0 = func_00206388(a0p + 160, a1);
    if (v0 == 0) {
        return;
    }
    *(u8*)(s0 + 160) = 1;
}

void func_002090f8(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6 + 160;

    u32 p0 = *(u32*)(s0 + 16);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 16) = 0;
    }

    u32 p1 = *(u32*)(s0 + 20);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s0 + 20) = 0;
    }

    u32 p2 = *(u32*)(s0 + 24);
    if (p2 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p2);
        *(u32*)(s0 + 24) = 0;
    }
}

s32 func_0020a000(u32 a0) {
    u32 s0 = a0 & 0xff;
    f32 f20 = (f32)(s32)(s0 << 1);
    f32 f0 = func_00209fb8(a0);  // vu_const_5f_c
    f20 = f20 * f0;
    f0 = (f32)(s32)(s0 >> 1);
    f20 = f20 - f0;
    s32 v0 = (s32)f20;
    return (s8)v0;
}

void func_0020b3a0(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6;
    u32 s1 = s0 + 160;

    u32 p0 = *(u32*)(s0 + 160);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 160) = 0;
    }

    u32 p1 = *(u32*)(s1 + 4);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s1 + 4) = 0;
    }
}

s32 func_0020b458(u32 a0) {
    u32 s0 = a0 & 0xff;
    f32 f20 = (f32)(s32)(s0 << 1);
    f32 f0 = func_0020b410(a0);  // vu_const_5f_b
    f20 = f20 * f0;
    f0 = (f32)(s32)(s0 >> 1);
    f20 = f20 - f0;
    s32 v0 = (s32)f20;
    return (s8)v0;
}

void func_0020cdf0(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6;
    u32 s1 = s0 + 160;

    u32 p0 = *(u32*)(s0 + 160);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 160) = 0;
    }

    u32 p1 = *(u32*)(s1 + 4);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s1 + 4) = 0;
    }
}

void func_0020ced0(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    if (*(s32*)(D_00350000 + 18056) != 0) {
        if (*(s32*)(D_00350000 + 18060) > 0) {
            u32 a2 = *(u8*)(s0 + 24);
            u32 a3 = *(u8*)(s0 + 25);
            func_00224358(*(u32*)(s0 + 16), s0 + 20, a2, a3);

            a2 = *(u8*)(s0 + 24);
            a3 = *(u8*)(s0 + 25);
            func_00223af8(*(u32*)(s0 + 4), s0 + 8, a2, a3);
        }
    }
}

u32 func_0020ecc8(u32 a0, u32 a1);  // 0x0020ecc8: definition moved into src/anon/unit_0020e9f8.cpp

void func_0021eb50(void* a0, u32 a1);  // 0x0021eb50: definition moved into src/anon/unit_0021e988.cpp

void func_0021ebe8(void* a0, u32 a1);  // 0x0021ebe8: definition moved into src/anon/unit_0021e988.cpp

void func_0021ec80(void* a0, u32 a1);  // 0x0021ec80: definition moved into src/anon/unit_0021e988.cpp

void func_0021ed18(void* a0, u32 a1);  // 0x0021ed18: definition moved into src/anon/unit_0021e988.cpp

void func_0021edb0(void* a0, u32 a1);  // 0x0021edb0: definition moved into src/anon/unit_0021e988.cpp

void func_00221fb8(u32 a0, u32 a1, u32 a2);  // 0x00221fb8: definition moved into src/anon/unit_00221e28.cpp

void func_00222018(u32 a0, u32 a1);  // 0x00222018: definition moved into src/anon/unit_00221e28.cpp

void func_00224b08(u32 a0);  // 0x00224b08: definition moved into src/anon/unit_00224780.cpp

void func_00224e28();  // 0x00224e28: definition moved into src/anon/unit_00224780.cpp

void func_00224ea0(u32 a0);  // 0x00224ea0: definition moved into src/anon/unit_00224780.cpp

void func_00225cd8();  // 0x00225cd8: definition moved into src/anon/unit_00224780.cpp

u32 func_002263f0(u32 a0, u32 a1);  // 0x002263f0: definition moved into src/anon/unit_00224780.cpp

u32 func_00226ce8(u32 a0);  // 0x00226ce8: definition moved into src/anon/unit_00224780.cpp

void func_00227200(u32 a0);  // 0x00227200: definition moved into src/anon/unit_00224780.cpp

u32 func_00227870(u32 a0, u32 a1, u32 a2);  // 0x00227870: definition moved into src/anon/unit_00224780.cpp

void func_002280f8();  // 0x002280f8: definition moved into src/anon/unit_00224780.cpp

u32 func_00228490(u32 a0, u32 a1);  // 00228490: moved to src/anon/unit_00228490.cpp (linked unit)

u32 func_00228518();  // 00228518: moved to src/anon/unit_00228490.cpp (linked unit)

u32 func_00228590();  // 00228590: moved to src/anon/unit_00228490.cpp (linked unit)

u32 func_00229370();  // 00229370: moved to src/sasa/musical_score.cpp (linked unit)

void func_00229678(u32 a0, u32 a1, u32 a2);  // 00229678: moved to src/sasa/musical_score.cpp (linked unit)

u32 func_00229840(u32 a0);  // 00229840: moved to src/sasa/musical_combo.cpp (linked unit)

u32 func_00229d90(u32 a0);  // 00229d90: moved to src/sasa/musical_combo.cpp (linked unit)

u32 func_0022a368(u32 a0);  // 0022a368: moved to src/sasa/musical_input.cpp (linked unit)

void func_0022abd8(u32 a0, u32 a1);  // 0022abd8: moved to src/sasa/musical_input.cpp (linked unit)

void func_0022ac60(u32 a0);  // 0022ac60: moved to src/sasa/musical_input.cpp (linked unit)

u32 func_0022acf8(u32 a0);  // 0022acf8: moved to src/sasa/musical_input.cpp (linked unit)

u32 func_0022b0a0(u32 a0, u32 a1);  // 0022b0a0: moved to src/sasa/musical_input.cpp (linked unit)

u32 func_0022b688(u32 a0);  // 0022b688: moved to src/sasa/musical_target.cpp (linked unit)

u32 func_0022b838();  // 0022b838: moved to src/sasa/musical_2d.cpp (linked unit)

void func_0022ba08(u32 a0, u32 a1);  // 0022ba08: moved to src/sasa/event_movie.cpp (linked unit)

void func_0022ba88(u32 a0);  // 0022ba88: moved to src/sasa/event_movie.cpp (linked unit)

void func_0022bda0(u32 a0, u32 a1, u32 a2);  // 0022bda0: moved to src/sasa/event_countdown.cpp (linked unit)

void func_0022c440(u32 a0);  // 0022c440: moved to src/sasa/event_countdown.cpp (linked unit)

void func_0022c530(u32 a0);  // 0022c530: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022c7c0(u32 a0);  // 0022c7c0: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022c998(u32 a0);  // 0022c998: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022cba0(u32 a0);  // 0022cba0: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d000(u32 a0);  // 0022d000: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d288(u32 a0);  // 0022d288: moved to src/sasa/event_layout.cpp (linked unit)

void func_0022d3c8(u32 a0);  // 0x0022d3c8: definition moved into src/anon/unit_0022d358.cpp

void func_0022d598(u32 a0, u32 a1);  // 0x0022d598: definition moved into src/anon/unit_0022d358.cpp

void func_0022d618(u32 a0);  // 0x0022d618: definition moved into src/anon/unit_0022d358.cpp

void func_0022e3e8(u32 a0);  // 0x0022e3e8: definition moved into src/anon/unit_0022d358.cpp

void func_0022e468(u32 a0);  // 0x0022e468: definition moved into src/anon/unit_0022d358.cpp

void func_0022e5f8(u32 a0);  // 0x0022e5f8: definition moved into src/anon/unit_0022d358.cpp

void func_0022e998(u32 a0);  // 0x0022e998: definition moved into src/anon/unit_0022d358.cpp

void func_0022ef50(u32 a0);  // 0x0022ef50: definition moved into src/anon/unit_0022d358.cpp

void func_0022f200(u32 a0);  // 0x0022f200: definition moved into src/anon/unit_0022d358.cpp

void func_0022f280(u32 a0);  // 0x0022f280: definition moved into src/anon/unit_0022d358.cpp

void func_00231948(u32 a0);  // 0x00231948: definition moved into src/anon/unit_00231500.cpp

u32 func_00233a18(u32 a0, u32 a1);  // 0x00233a18: definition moved into src/anon/unit_002335e8.cpp

u32 func_00236490(void* a0);  // 0x00236490: definition moved into src/anon/unit_00236180.cpp

u32 func_002364f8(void* a0);  // 0x002364f8: definition moved into src/anon/unit_00236180.cpp

void func_00236830(void* a0);  // 0x00236830: definition moved into src/anon/unit_00236180.cpp

void func_00236c38(void* a0);  // 0x00236c38: definition moved into src/anon/unit_00236180.cpp

u32 func_00239af8(void* a0, u32 a1);  // 0x00239af8: definition moved into src/anon/unit_00239988.cpp

void func_0023c300(void* a0);  // 0x0023c300: definition moved into src/anon/unit_0023bc58.cpp

u32 func_0023c978(void* a0);  // 0x0023c978: definition moved into src/anon/unit_0023c968.cpp

void func_0023d368();  // 0x0023d368: definition moved into src/anon/unit_0023d260.cpp

u32 func_0023d438(void* a0, u32 a1);  // 0x0023d438: definition moved into src/anon/unit_0023d260.cpp

u32 func_0023d4f8(void* a0, u32 a1);  // 0x0023d4f8: definition moved into src/anon/unit_0023d260.cpp

void func_0023e5d0(void* a0, u32 a1, void* a2);  // 0x0023e5d0: definition moved into src/anon/unit_0023e5d0.cpp

void func_0023eae0(void* a0, u32 a1, s32 a2, s32 a3);  // 0x0023eae0: definition moved into src/anon/unit_0023e5d0.cpp

void func_0023eb50(void* a0, u32 a1, s32 a2);  // 0x0023eb50: definition moved into src/anon/unit_0023e5d0.cpp

u32 func_0023fc40(u32 a0, u32 a1);  // 0x0023fc40: definition moved into src/anon/unit_0023f5b8.cpp

void func_0023fd40(u32 a0);  // 0x0023fd40: definition moved into src/anon/unit_0023f5b8.cpp

u32 func_002416d8(u32 a0);  // 0x002416d8: definition moved into src/anon/unit_0023f5b8.cpp

u32 func_00241e18(void);  // 0x00241e18: definition moved into src/anon/unit_00241e18.cpp

void func_00242110(u32 a0);  // 0x00242110: definition moved into src/anon/unit_00241fd0.cpp

void func_002423a0(void);  // 002423a0: moved to src/tozawa/crc.cpp (linked unit)

extern "C" void func_002436d0(u32) asm("_ZN2Tz4HEFT11PauseThreadEP4TASK");

extern "C" void func_00245400(u32) asm("_ZN2Tz4HECO11PauseThreadEP4TASK");

void func_002468e8(u32 a0, u32 a1);  // 0x002468e8: definition moved into src/anon/unit_00242478.cpp

u32 func_002469a0(u32 a0);  // 0x002469a0: definition moved into src/anon/unit_00242478.cpp

u32 func_00246a08(void);  // 0x00246a08: definition moved into src/anon/unit_00242478.cpp

u32 func_002474e0(u32 a0);  // 0x002474e0: definition moved into src/anon/unit_00242478.cpp

extern "C" void func_00247ff0(u32) asm("_ZN2Tz4MUMI11PauseThreadEP4TASK");

extern "C" void func_00249940(u32) asm("_ZN2Tz4TRTE11PauseThreadEP4TASK");

extern "C" void func_0024b510(u32) asm("_ZN2Tz4HBTE11PauseThreadEP4TASK");

extern "C" void func_0024cda8(u32) asm("_ZN2Tz4TTPT11PauseThreadEP4TASK");

extern "C" void func_0024e7e8(u32) asm("_ZN2Tz4TTMY11PauseThreadEP4TASK");

extern "C" void func_0024f698(u32) asm("_ZN2Tz4LMMU11PauseThreadEP4TASK");

extern "C" void func_00250748(void) asm("_ZN2Tz4LMMU7CtrlSelEv");

extern "C" void func_002510d0(u32) asm("_ZN2Tz4CANA11PauseThreadEP4TASK");

void func_00251a08(void);  // 0x00251a08: definition moved into src/anon/unit_00250fb8.cpp

void func_00251f40(void);  // 0x00251f40: definition moved into src/anon/unit_00250fb8.cpp

u32 func_00252098(u32 a0);  // 0x00252098: definition moved into src/anon/unit_00250fb8.cpp

void func_00252180(void);  // 0x00252180: definition moved into src/anon/unit_00250fb8.cpp

void func_00252810(void);  // 0x00252810: definition moved into src/anon/unit_00250fb8.cpp

void func_00252890(u32 a0);  // 0x00252890: definition moved into src/anon/unit_00250fb8.cpp

void func_00253818(s32 a0);  // 0x00253818: definition moved into src/anon/unit_002530c8.cpp

void func_00253978(u32 a0, u32 a1, Entry00253978* a2);  // 0x00253978: definition moved into src/anon/unit_002530c8.cpp

u32 func_00253b30(u32 a0, u32 a1);  // 0x00253b30: definition moved into src/anon/unit_002530c8.cpp

void func_00254f08(void);  // 0x00254f08: definition moved into src/anon/unit_00254020.cpp

void func_002550e8(void);  // 0x002550e8: definition moved into src/anon/unit_00254020.cpp

void func_00256aa0(void);  // 0x00256aa0: definition moved into src/anon/unit_00254020.cpp

void func_00256c40(u32 a0) {
    u32 s0 = func_00257770(a0) + 2504;

    if (func_00139d78(s0) != 0) {
        *(u32*)(s0 + 396) = 0;
        func_001396b0(s0);

        if (*(u32*)(s0 + 396) != 0) {
            *(u32*)(s0 + 400) = 0;
            func_001396b0(s0);

            if (*(u32*)(s0 + 400) != 0) {
                func_0031a260(s0, 0);
            }
        }

        func_00139510(s0);
    }
}

void func_00257530(u32 a0);  // 0x00257530: definition moved into src/anon/unit_00254020.cpp

u32 func_00257610(u32 a0);  // 0x00257610: definition moved into src/anon/unit_00254020.cpp

u32 func_00257910(void);  // 0x00257910: definition moved into src/anon/unit_00254020.cpp

void func_00258c80(void);  // 0x00258c80: definition moved into src/anon/unit_002588e8.cpp

void func_00259020(
    u32 a0,
    u32 a1,
    u32 a2,
    u32 a3,
    u32 a4,
    u32 a5,
    u32 a6,
    u32 a7
);  // 0x00259020: definition moved into src/anon/unit_002588e8.cpp

void func_002590b0(u32 a0);  // 0x002590b0: definition moved into src/anon/unit_002588e8.cpp

u32 func_00259618(u32 a0, u32 a1, u32 a2);  // 0x00259618: definition moved into src/anon/unit_002588e8.cpp

u32 func_00259690(void);  // 0x00259690: definition moved into src/anon/unit_002588e8.cpp

u32 func_002597f0(void);  // 0x002597f0: definition moved into src/anon/unit_002588e8.cpp

u32 func_0025ca78(void);  // 0x0025ca78: definition moved into src/anon/unit_002588e8.cpp

void func_0025cd78(void);  // 0x0025cd78: definition moved into src/anon/unit_002588e8.cpp

void func_0025d4e8(void);  // 0x0025d4e8: definition moved into src/anon/unit_002588e8.cpp

u32 func_0025d6b0(void);  // 0x0025d6b0: definition moved into src/anon/unit_002588e8.cpp

u32 func_0025d748(void);  // 0x0025d748: definition moved into src/anon/unit_002588e8.cpp

void func_0025ee88(void);  // 0x0025ee88: definition moved into src/anon/unit_0025da20.cpp

u32 func_0025f588(void);  // 0x0025f588: definition moved into src/anon/unit_0025da20.cpp

u32 func_00262300(void);  // 0x00262300: definition moved into src/anon/unit_0025f6b8.cpp

void func_00262360(void);  // 0x00262360: definition moved into src/anon/unit_0025f6b8.cpp

void func_00262768(void);  // 0x00262768: definition moved into src/anon/unit_0025f6b8.cpp

u32 func_002632d0(u32 a0);  // 0x002632d0: definition moved into src/anon/unit_002632d0.cpp

void func_00263340(u32 a0, u32 a1);  // 0x00263340: definition moved into src/anon/unit_002632d0.cpp

void func_00263570(s32 a0);  // 0x00263570: definition moved into src/anon/unit_002632d0.cpp

u32 func_002811b0(u32, s32) asm("_ZN2Tz9PartyInfo10GetPartNumEi");
u32 func_002815b8(void) asm("_ZN2Tz9PartyInfo10GetNowFormEv");

void func_00263720(u32 a0);  // 0x00263720: definition moved into src/anon/unit_002632d0.cpp

void func_00263858(s32 a0);  // 0x00263858: definition moved into src/anon/unit_002632d0.cpp

void func_002639f8(void);  // 0x002639f8: definition moved into src/anon/unit_002632d0.cpp

void func_00263bb0(u16* a0, u16* a1);  // 0x00263bb0: definition moved into src/anon/unit_002632d0.cpp

void func_00263db0(u32 a0);  // 0x00263db0: definition moved into src/anon/unit_002632d0.cpp

void func_00265580(void);  // 0x00265580: definition moved into src/anon/unit_00265580.cpp

void func_00265a30(void);  // 0x00265a30: definition moved into src/anon/unit_00265580.cpp

u32 func_00266c00(void);  // 0x00266c00: definition moved into src/anon/unit_00265580.cpp

void func_00267398(void);  // 0x00267398: definition moved into src/anon/unit_00265580.cpp

u32 duplicate_unplaced_002674f8(u32 a0) {
    u32 s0 = a0 & 0xFF;
    u32 t = func_00257070(23);
    t = func_002670f8(t);
    u32 v0 = func_002674b8();
    u32 s1 = t;
    s32 t6 = (s32)v0 - 1;

    if (s0 != 0) {
        s1 = s1 + 1;
        if (!((s32)s1 < (s32)v0)) {
            s1 = 0;
        }
    } else {
        s1 = s1 - 1;
        if ((s32)s1 < 0) {
            s1 = (u32)t6;
        }
    }

    u32 idx = func_002670a0(s1);
    func_00257050(23, idx, 0);
    func_0028fb28(1, func_00267408(s1));
    return func_00266b58();
}

u32 func_00267620();  // 0x00267620: definition moved into src/anon/unit_00265580.cpp

void func_00267690();  // 0x00267690: definition moved into src/anon/unit_00265580.cpp

u32 func_0026acb8(u32 a0);  // 0x0026acb8: definition moved into src/anon/unit_0026a900.cpp

u32 func_0026ad68(u32 a0, u32 a1);  // 0x0026ad68: definition moved into src/anon/unit_0026a900.cpp

u32 func_0026ae20(u32 a0, u32 a1);  // 0x0026ae20: definition moved into src/anon/unit_0026a900.cpp

u32 func_0026aea8(u32 a0, u32 a1);  // 0x0026aea8: definition moved into src/anon/unit_0026a900.cpp

u32 func_0026b860(u32 a0);  // 0x0026b860: definition moved into src/anon/unit_0026a900.cpp

u32 func_0026cb38();  // 0x0026cb38: definition moved into src/anon/unit_0026c450.cpp

void func_0026cb90();  // 0x0026cb90: definition moved into src/anon/unit_0026c450.cpp

u32 func_0026d560();  // 0x0026d560: definition moved into src/anon/unit_0026c450.cpp

void func_0026d5c0();  // 0x0026d5c0: definition moved into src/anon/unit_0026c450.cpp

void func_0026d828();  // 0x0026d828: definition moved into src/anon/unit_0026c450.cpp

u32 func_0026e340();  // 0x0026e340: definition moved into src/anon/unit_0026c450.cpp

void func_0026ed48();  // 0x0026ed48: definition moved into src/anon/unit_0026c450.cpp

void func_00273c40(s32 a0);  // 0x00273c40: definition moved into src/anon/unit_00271e08.cpp

extern "C" u32 func_00273de0(u32, u32) asm("_ZN2Tz6Jiminy4InitEjj");

void duplicate_unplaced_00274ac8() {
    if (func_0028acc8(D_0035f200) != 0) {
        func_0028abe0(D_0035f200);
    }

    if (func_00139d78(D_0035f204) != 0) {
        u32 obj = D_0035f204;
        u32 vtbl = *(u32*)obj;
        u32 fn = *(u32*)(vtbl + 20);
        ((void (*)(u32))fn)(obj);
    }

    if (func_0028be58(D_0035f214) != 0) {
        func_0028be18(D_0035f214);
    }

    func_002766e0();
}

extern "C" void func_00274ee8(u32) asm("_ZN2Tz6Jiminy6WMInitEP9ALLOCATOR");

void func_00275980(u32 a0, u32 a1);  // 0x00275980: definition moved into src/anon/unit_002748a0.cpp

void duplicate_unplaced_002759e8(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_0028d6e8(D_0035f218);
    if (v0 == 0) {
        func_0028d1c0(D_0035f218, 30065, D_0035f14c, D_0035f148, D_0035f210, (u32)&D_00373d80, 0);
    } else {
        u32 p = D_0035f218;
        if (*(u32*)(p + 396) == s0) {
            return;
        }
        func_0028d660(p, s0);  // record_set_value_refresh
        return;
    }
    func_0028d660(D_0035f218, s0);  // record_set_value_refresh
}

void duplicate_unplaced_00275a80() {
    if (func_00139d78(D_0035f20c + 872) == 0) {
        func_0028d980(D_0035f20c + 872, 30040, D_0035f14c, D_0035f148, D_0035f210, 53, 54, -1, 0);
        *(u32*)(D_0035f20c + 1304) = 2;
    }
    func_00275d10();
}

void func_00275af8();  // 0x00275af8: definition moved into src/anon/unit_002748a0.cpp

void func_00275cb8();  // 0x00275cb8: definition moved into src/anon/unit_002748a0.cpp

void func_00276a18();  // 0x00276a18: definition moved into src/anon/unit_002748a0.cpp

void func_0027a898(u32 a0);  // 0x0027a898: definition moved into src/anon/unit_0027a6d8.cpp

u32 func_0027a990();  // 0x0027a990: definition moved into src/anon/unit_0027a6d8.cpp

void func_0027b548(u32 a0);  // 0x0027b548: definition moved into src/anon/unit_0027a6d8.cpp

void func_0027d350(void);  // 0x0027d350: definition moved into src/anon/unit_0027d2e8.cpp

u32 func_0027d3b0(void);  // 0x0027d3b0: definition moved into src/anon/unit_0027d2e8.cpp

void func_0027d540(void);  // 0x0027d540: definition moved into src/anon/unit_0027d2e8.cpp

void func_0027d2e8(void);  // 0x0027d2e8: definition moved into src/anon/unit_0027d2e8.cpp

void func_0027d810(u32 a0);  // 0x0027d810: definition moved into src/anon/unit_0027d2e8.cpp

void func_0027da60(void);  // 0x0027da60: definition moved into src/anon/unit_0027d2e8.cpp

void func_0027dab8(u32 a0);  // 0x0027dab8: definition moved into src/anon/unit_0027d2e8.cpp

void func_0027d9f0(void);  // 0x0027d9f0: definition moved into src/anon/unit_0027d2e8.cpp

u32 func_0027ea78(void);  // 0x0027ea78: definition moved into src/anon/unit_0027e920.cpp

extern "C" void func_0027f370(void) asm("_ZN2Tz9GumiPause8SetupTopEv");

extern "C" void func_0027f2f8(u32) asm("_ZN2Tz9GumiPause11PauseThreadEP4TASK");

void duplicate_unplaced_0027fcc0(void) {
    u32 s1 = func_0028af88(D_0035f254);
    u32 i = func_0028b040(D_0035f254);
    s8 v = *((s8*)&D_00374168 + i);
    s32 m = -13;
    if (v >= 0) {
        goto clear_bits;
    }
    if (i == 2) {
        goto clear_bits;
    }
    s1 |= 0xcu;
    goto apply;
clear_bits:
    s1 &= (u32)m;
apply:
    func_0028af18(D_0035f254, s1);
}

void func_002802e8(void);  // 0x002802e8: definition moved into src/anon/unit_0027f2b0.cpp

u32 func_00280290(void);  // 0x00280290: definition moved into src/anon/unit_0027f2b0.cpp

extern "C" void func_002800d0(void) asm("_ZN2Tz9GumiPause12UpdateAdviceEv");

u32 func_00280368(void);  // 0x00280368: definition moved into src/anon/unit_0027f2b0.cpp

extern "C" void func_00280458(void) asm("_ZN2Tz9GumiPause14ChkLoadRequestEv");

void func_002809d8(u32 a0);  // 0x002809d8: definition moved into src/anon/unit_0027f2b0.cpp

void func_00281058(u32 a0, s32 a1);  // 0x00281058: definition moved into src/anon/unit_0027f2b0.cpp

u32 func_00282ec0(u32 a0);  // 0x00282ec0: definition moved into src/anon/unit_00282c68.cpp

void func_00283730(void);  // 0x00283730: definition moved into src/anon/unit_00282c68.cpp

void func_00283900(u32 a0);  // 0x00283900: definition moved into src/anon/unit_00282c68.cpp

void func_00283960(u32 a0);  // 0x00283960: definition moved into src/anon/unit_00282c68.cpp

u32 func_002839f0(u32 a0);  // 0x002839f0: definition moved into src/anon/unit_00282c68.cpp

u32 func_00283a58(void);  // 0x00283a58: definition moved into src/anon/unit_00282c68.cpp

void func_00283f50(void);  // 0x00283f50: definition moved into src/anon/unit_00283f50.cpp

void func_00283fb0(void);  // 0x00283fb0: definition moved into src/anon/unit_00283f50.cpp

void func_00284738(u32 a0);  // 0x00284738: definition moved into src/anon/unit_00284220.cpp

void func_002856c8(void);  // 0x002856c8: definition moved into src/anon/unit_002853b8.cpp

void duplicate_unplaced_00288370(void) {
    u32 s2 = func_0023f948(D_0035f334, 0);
    u32 s0 = func_0023f908(D_0035f334, 0);
    u32 t = func_00103570();

    func_00236a58(D_0035f33c, s0, t);
    t = func_00103570();

    func_0023c100(D_0035f340, s2, D_0035f33c, t);
}

u32 func_00288400(u32 a0);  // 0x00288400: definition moved into src/anon/unit_002880b8.cpp

void func_00288870(void);  // 0x00288870: definition moved into src/anon/unit_002880b8.cpp

void func_00288b18(u32 a0);  // 0x00288b18: definition moved into src/anon/unit_00288b00.cpp

void func_002890e0(Obj_002890e0* self, u32 a1, s32 a2, u32 a3, s32 a4);  // 0x002890e0: definition moved into src/anon/unit_00288b00.cpp

void func_0028b8e0(Obj_0028b8e0* self);  // 0x0028b8e0: definition moved into src/anon/unit_00288b00.cpp

void func_0028ba20(Obj_0028ba20* self);  // 0x0028ba20: definition moved into src/anon/unit_00288b00.cpp

void func_0028ba80(Obj_0028ba80* self);  // 0x0028ba80: definition moved into src/anon/unit_00288b00.cpp

void func_0028bd60(Obj_0028bd60* self);  // 0x0028bd60: definition moved into src/anon/unit_00288b00.cpp

void func_0028c7c0(s32 a0, s32 a1);  // 0x0028c7c0: definition moved into src/anon/unit_0028bfc0.cpp

void func_0028d730(u32 self, Cb_0028d730 cb, f32 a2, f32 a3, f32 a4, f32 a5);  // 0028d730: moved to src/anon/unit_0028c878.cpp

void func_0028dae0(u32 self, u32 value);  // 0028dae0: moved to src/anon/unit_0028c878.cpp

u32 func_0028db48(u32 self);  // 0028db48: moved to src/anon/unit_0028c878.cpp

u32 func_0028dba0(u32 self);  // 0028dba0: moved to src/anon/unit_0028c878.cpp

void func_0028dd28(Obj_0028dd28* self, u32 value);  // 0028dd28: moved to src/anon/unit_0028c878.cpp

void func_0028e080(u32 self);  // 0028e080: moved to src/anon/unit_0028c878.cpp

void func_0028e3b8(Obj_0028e3b8* self, u32 idx, u32 a2, u32 a3, u32 a4);  // 0028e3b8: moved to src/anon/unit_0028c878.cpp

void func_0028e8b8(Obj_0028e8b8* self, u32 idx, u32 v2, u32 v3);  // 0028e8b8: moved to src/anon/unit_0028c878.cpp

void func_0028e970(Obj_0028e970* self, u32* out1, u32* out2);  // 0028e970: moved to src/anon/unit_0028c878.cpp

void func_0028e9d0(Obj_0028e9d0* self, u32 idx, u32 a2, u32 a3);  // 0028e9d0: moved to src/anon/unit_0028c878.cpp

void func_0028ea30(Obj_0028ea30* self, u32 idx, u32* p0, u32* p1);  // 0028ea30: moved to src/anon/unit_0028c878.cpp

void func_0028fa98(s32 which);  // 0028fa98: moved to src/anon/unit_0028f1e0.cpp

void func_0028fd68(Obj_0028fd68* self);  // 0028fd68: moved to src/anon/unit_0028f1e0.cpp

void func_0028fdd0(Obj_0028fdd0* self);  // 0028fdd0: moved to src/anon/unit_0028f1e0.cpp

void func_0028ffe8(Obj_0028ffe8* self, u32 idx);  // 0028ffe8: moved to src/anon/unit_0028f1e0.cpp

void func_00290298(Obj_00290298* self);  // 00290298: moved to src/anon/unit_0028f1e0.cpp

void func_00290300(Obj_00290300* self);  // 00290300: moved to src/anon/unit_0028f1e0.cpp

void func_00290368(Obj_00290368* self, u32 a1, u32 a2, u32 a3);  // 00290368: moved to src/anon/unit_0028f1e0.cpp

void func_00290508(Obj_00290508* self, u32 idx);  // 00290508: moved to src/anon/unit_0028f1e0.cpp

void func_002905b8(u32 self);  // 002905b8: moved to src/anon/unit_0028f1e0.cpp

void func_00290760(u32 self, u32 base, u32 count);  // 00290760: moved to src/anon/unit_0028f1e0.cpp

void func_002907c0(u32 self, u32 base, u32 count);  // 002907c0: moved to src/anon/unit_0028f1e0.cpp

void func_00290a90(u32 self);  // 00290a90: moved to src/anon/unit_0028f1e0.cpp

void func_00290b00(u32 self);  // 00290b00: moved to src/anon/unit_0028f1e0.cpp

void func_00290b70(u32 self);  // 00290b70: moved to src/anon/unit_0028f1e0.cpp

void func_00290c30(u32 self);  // 00290c30: moved to src/anon/unit_0028f1e0.cpp

void func_00290cf0(u32 self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);  // 00290cf0: moved to src/anon/unit_0028f1e0.cpp

void duplicate_unplaced_00291068(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    u32 s19 = a1;
    u32 s16 = a0;
    u32 s17 = a2;
    u32 s20 = a4;
    u32 s21 = a5;

    func_00290d68(s16, a3);
    func_00290f78(s16);
    u32 s18 = func_00291380(s16, s17);
    func_00291510(s16, s19, s17, s18);
    func_00291ba8(s16, s19, s17, s20, s21, s18);
}

void func_002911f8(u32 self);  // 002911f8: moved to src/anon/unit_00290f78.cpp

void func_002931a8(u32 a0);  // 0x002931a8: definition moved into src/anon/unit_00292e60.cpp

void func_002932f8(void);  // 0x002932f8: definition moved into src/anon/unit_00292e60.cpp

void func_00293bd0(u32 a0, u32 a1, u32 a2);  // 0x00293bd0: definition moved into src/anon/unit_00292e60.cpp

void func_00294ea8(void);  // 0x00294ea8: definition moved into src/anon/unit_00292e60.cpp

void func_00296ab0(void);  // 0x00296ab0: definition moved into src/anon/unit_00295d28.cpp

void func_00297d78(void);  // 0x00297d78: definition moved into src/anon/unit_00295d28.cpp

void func_00297e00(u32 a0);  // 0x00297e00: definition moved into src/anon/unit_00295d28.cpp

void func_00298fe8(s32 a0) {
    u8 buf[32];
    s32 idx = (s8)a0;
    u32 off = (u32)idx;
    off <<= 1;
    off += D_0035f598;
    D_0035f5a1 = a0;
    u32 s0 = (u32)func_002983d8(*(s16*)(off + 4));
    if (func_00292630() != 0) {
        D_0035f5a3 = 0;
        return;
    }
    u32 v = func_00293de8(*(s8*)s0);
    func_002ff2e8(buf, v);
    func_002feee8((u32)buf, s0 + 1);
    func_00298f90();
    func_00293bd0(3, buf, 0);
    func_002925c0();
    D_0035f5a3 = 1;
}

extern "C" void func_0029a2a0(void) asm("_ZN2Tz12JmCollection9FileAllocEv");

void func_0029a310(void);  // 0x0029a310: definition moved into src/anon/unit_00299920.cpp

void func_0029dfc0(void) {
    u32 s1 = func_002766d0();
    u32 s0 = s1 + 0x4860;

    if (func_00139d78(s0) != 0) {
        return;
    }

    func_0028d8c0(s0, 30055, D_0035f14c, D_0035f148, D_0035f210, 4, 5, 0);
    func_0028dcc0(s0, s1);
}

void func_0029e298(u32 a0);  // 0x0029e298: definition moved into src/anon/unit_0029d008.cpp

u32 func_0029e338(u32 a0);  // 0x0029e338: definition moved into src/anon/unit_0029d008.cpp

void func_0029e960(void);  // 0x0029e960: definition moved into src/anon/unit_0029d008.cpp

void func_0029e9d0(void) {
    if (D_0035f5c0 == 0) {
        return;
    }

    u32 v0 = func_00103eb0();
    func_00102670(*(u32*)(v0 + 4), D_0035f5c0);  // to_1025f8
    func_0015df98();

    D_0035f5c0 = 0;
    D_0034b278 = D_0034b27c;
}

extern "C" void func_002a0780(void) asm("_ZN2Tz9JmDiagram10FadeOutAllEv");

void func_002a07f0(u32 a0);  // 0x002a07f0: definition moved into src/anon/unit_0029f938.cpp

void func_002a45a0(void);  // 0x002a45a0: definition moved into src/anon/unit_002a40c8.cpp

u32 func_002a7530(void);  // 0x002a7530: definition moved into src/anon/unit_002a7308.cpp

void func_002a8a00(void);  // 0x002a8a00: definition moved into src/anon/unit_002a8748.cpp


u32 func_002aecf0(u32 a0);  // 0x002aecf0: definition moved into src/anon/unit_002aeba0.cpp

s32 func_002b2380(s32 a0, s32 a1);  // 0x002b2380: definition moved into src/anon/unit_002b1db8.cpp

void func_002b4388(Obj4388* a0, u8* a1, u32 a2);  // 0x002b4388: definition moved into src/anon/unit_002b3ac8.cpp


u32 func_002b5978(void);  // 0x002b5978: definition moved into src/anon/unit_002b3ac8.cpp


u32 func_002ba848(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002ba848: definition moved into src/anon/unit_002b9ab8.cpp

u32 func_002bb1c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bb1c8: definition moved into src/anon/unit_002bb070.cpp

u32 func_002bb2b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bb2b8: definition moved into src/anon/unit_002bb070.cpp

u32 func_002bb310(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bb310: definition moved into src/anon/unit_002bb070.cpp

u32 func_002bb378(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bb378: definition moved into src/anon/unit_002bb070.cpp

void func_002bb950(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bb950: definition moved into src/anon/unit_002bb8b0.cpp

u32 func_002bc288(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bc288: definition moved into src/anon/unit_002bb8b0.cpp

u32 func_002bc588(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bc588: definition moved into src/anon/unit_002bb8b0.cpp

u32 func_002bcb60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bcb60: definition moved into src/anon/unit_002bc978.cpp

void func_002bcc60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bcc60: definition moved into src/anon/unit_002bc978.cpp

u32 func_002bccd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002bccd8: definition moved into src/anon/unit_002bc978.cpp

u32 func_002be020(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002be020: definition moved into src/anon/unit_002be020.cpp

void func_002be258(u32 a0, u32 a1, u32 a2, s32 a3, u32 a4, u32 a5, u32 a6, u32 a7);  // 0x002be258: definition moved into src/anon/unit_002be020.cpp

void func_002beb28();  // 0x002beb28: definition moved into src/anon/unit_002be020.cpp

u32 func_002beef8(u8* self);  // 0x002beef8: definition moved into src/anon/unit_002bebd0.cpp

void func_002bf1f0(u8* self);  // 0x002bf1f0: definition moved into src/anon/unit_002bebd0.cpp

u32 func_002bf270(u8* self);  // 0x002bf270: definition moved into src/anon/unit_002bebd0.cpp

u32 func_002c0130(u32 a0, u32 a1, f32 a2);  // 0x002c0130: definition moved into src/anon/unit_002bebd0.cpp

u32 func_002c0688(u32 a0, u32 a1);  // 0x002c0688: definition moved into src/anon/unit_002bebd0.cpp

void func_002c1dc0();  // 0x002c1dc0: definition moved into src/anon/unit_002c10e0.cpp

u32 func_002c2358(u8* a0);  // 0x002c2358: definition moved into src/anon/unit_002c2228.cpp

void func_002c23f0();  // 0x002c23f0: definition moved into src/anon/unit_002c2228.cpp

void func_002c3da0(u8* self);  // 0x002c3da0: definition moved into src/anon/unit_002c3c90.cpp

void func_002c4240(u8* self);  // 0x002c4240: definition moved into src/anon/unit_002c3c90.cpp

void func_002c42f8(u8* self);  // 0x002c42f8: definition moved into src/anon/unit_002c3c90.cpp

void func_002c5190(u32 a0);  // 0x002c5190: definition moved into src/anon/unit_002c4ca8.cpp

u32 func_002c5d38(u32 a0, u32 a1);  // 0x002c5d38: definition moved into src/anon/unit_002c53c8.cpp

u32 func_002c5ed8(u32 a0, u32 a1, f32 a2);  // 0x002c5ed8: definition moved into src/anon/unit_002c53c8.cpp

// 002c6c60: moved to src/anon/unit_002c6420.cpp (linked unit)

void func_002c83c0(u8* a0);  // 0x2c83c0: moved to src/anon/unit_002c7e68.cpp


void func_002c8490(u8* a0);  // 0x2c8490: moved to src/anon/unit_002c7e68.cpp


void func_002c8550(u8* a0);  // 0x2c8550: moved to src/anon/unit_002c7e68.cpp


void func_002c9f60(u8* a0);  // 0x2c9f60: moved to src/anon/unit_002c9998.cpp


void func_002ca410(u8* a0);  // 0x2ca410: moved to src/anon/unit_002ca0e0.cpp


void func_002ca5b8(u8* a0);  // 0x2ca5b8: moved to src/anon/unit_002ca0e0.cpp


void func_002ca630(u8* a0);  // 0x2ca630: moved to src/anon/unit_002ca0e0.cpp


void func_002ca6f8(u8* a0);  // 0x2ca6f8: moved to src/anon/unit_002ca0e0.cpp


void func_002ca7b0(u8* a0);  // 0x2ca7b0: moved to src/anon/unit_002ca0e0.cpp


void func_002cab98(u32 a0);  // 0x2cab98: moved to src/anon/unit_002ca0e0.cpp


void func_002cb0e8(u32 a0, u32 a1, f32 a2);  // 0x2cb0e8: moved to src/anon/unit_002cac58.cpp


void func_002cb4a0(u32 a0);  // 0x002cb4a0: definition moved into src/anon/unit_002cb200.cpp

void func_002cb748();  // 0x002cb748: definition moved into src/taito/path.cpp

void func_002ccf98(u32 a0);  // 0x002ccf98: definition moved into src/taito/path.cpp

u32 func_002cd878(u32 a0, u32 a1, s32 a2, f32 a3);  // 0x002cd878: definition moved into src/taito/path.cpp

u32 func_002cda68(u32 a0, u32 a1, s32 a2, f32 a3);  // 0x002cda68: definition moved into src/taito/path.cpp

u32 func_002cdb00(u32 a0, u32 a1, f32 a2);  // 0x002cdb00: definition moved into src/taito/path.cpp

void func_002ce870(u8* a0, u32 a1);  // 0x002ce870: definition moved into src/taito/path.cpp

void func_002d2948(u8* a0);  // 0x002d2948: definition moved into src/anon/unit_002d2498.cpp

void func_002d29a8(u8* a0);  // 0x002d29a8: definition moved into src/anon/unit_002d2498.cpp

void func_002d5af0(u32 a0);  // 0x002d5af0: definition moved into src/anon/unit_002d4548.cpp

void func_002d5b48(u32 a0);  // 0x002d5b48: definition moved into src/anon/unit_002d4548.cpp

u32 func_002d5c40(u32 a0);  // 0x002d5c40: definition moved into src/anon/unit_002d4548.cpp

void func_002d7390(u32 a0);  // 0x002d7390: definition moved into src/anon/unit_002d6f70.cpp

void func_002d7420(u32 a0);  // 0x002d7420: definition moved into src/anon/unit_002d6f70.cpp

void func_002d7630(u32 a0);  // 0x002d7630: definition moved into src/anon/unit_002d6f70.cpp

void func_002da8f0(u32 a0, u32 a1);  // 0x002da8f0: definition moved into src/anon/unit_002da040.cpp

void func_002dd968(u32 a0);  // 0x002dd968: definition moved into src/anon/unit_002dd650.cpp

void func_002de888(u32 a0);  // 0x002de888: definition moved into src/anon/unit_002de3c8.cpp

void func_002def70(u32 a0, u32 a1);  // 0x002def70: definition moved into src/anon/unit_002de3c8.cpp

void func_002df758(u32 a0, u32 a1);  // 0x002df758: definition moved into src/anon/unit_002de3c8.cpp

void func_002e0f20(u32 a0);  // 0x002e0f20: definition moved into src/anon/unit_002de3c8.cpp

// 002e22f0: moved to src/anon/unit_002e1908.cpp

// 002e2660: moved to src/anon/unit_002e1908.cpp

// 002e26c0: moved to src/anon/unit_002e1908.cpp

// 002e3688: moved to src/anon/unit_002e2f08.cpp

// 002e36f0: moved to src/anon/unit_002e2f08.cpp

// 002e39c0: moved to src/anon/unit_002e2f08.cpp

// 002e3de0: moved to src/anon/unit_002e2f08.cpp

void func_002e3fa0(f32* a0, f32* a1, f32 a2) {
    f32 v = cosf((u32)a0, (u32)a1);
    a0[3] = v;
    f32 s = sinf(a2);

    a0[0] = a1[0] * s;
    a0[1] = a1[1] * s;
    a0[2] = a1[2] * s;
}

void func_002e4010(f32* a0, f32* a1, f32 a2) {
    f32 v = cosf((u32)a0, (u32)a1);
    a0[3] = v;
    f32 s = sinf(a2);

    a0[0] = a1[0] * s;
    a0[1] = a1[1] * s;
    a0[2] = a1[2] * s;
}

void func_002e73d8(u32 a0) {  // timer_decrement
    f32 t = *(f32*)(a0 + 28) - D_00349e10;
    *(f32*)(a0 + 28) = t;
    if (t <= 0.0f) {
        u32 v0 = func_001064a8(*(u32*)(a0 + 8));  // int_to_float_scaled
        u32 obj = *(u32*)(a0 + 4);
        u32 t7 = *(u32*)(a0 + 12) + v0;
        u32 vt = *(u32*)obj;
        u32 a2 = *(u32*)(a0 + 24);
        VFn73d8 fn = *(VFn73d8*)(vt + 84);
        fn(obj, *(u8*)t7, a2);
        func_002e73a8(a0);
    }
}

// 002eb920: moved to src/anon/unit_002eaf38.cpp

// 002ec1d0: moved to src/anon/unit_002eaf38.cpp

void func_002edb38(void);  // 0x002edb38: definition moved into src/anon/unit_002ecdb0.cpp

void func_002edfd8(u32 a0, u32 a1);  // 0x002edfd8: definition moved into src/anon/unit_002ecdb0.cpp

// 002eefc8: moved to src/anon/unit_002ee8a8.cpp

// 002ef1f8: moved to src/anon/unit_002ef1f8.cpp

// 002ef370: moved to src/anon/unit_002ef1f8.cpp

// 002ef3c8: moved to src/anon/unit_002ef1f8.cpp

// 002efa98: moved to src/anon/unit_002ef938.cpp

// 002efb08: moved to src/anon/unit_002ef938.cpp

// 002f0970: moved to src/naka/libkn/trapfunctions.cpp

f32 func_002f8a18(f32 a0) {
    union {
        f32 f;
        u32 u;
    } bits;
    bits.f = a0;

    s32 abits = (s32)(bits.u & 0x7FFFFFFFu);
    if (!((s32)0x3F490FDA < abits)) {
        return __kernel_tanf(1, a0, 0.0f);
    }

    f32 tmp[2];
    s32 q = (s32)(__ieee754_rem_pio2f((void*)tmp) & 1u);
    s32 s = 1 - (q << 1);
    return __kernel_tanf(s, tmp[0], tmp[1]);
}

s32 func_002fea18() {
    u32 base36 = 0x00360000u;
    u32 base37 = 0x00370000u;

    u32 root = *(u32*)(base36 + 0x5C48u);
    s64 step = *(s64*)(base37 + 0x78E0u);
    s64 cur = *(s64*)(root + 168u);

    s64 v = __muldi3(cur, step) + 1ll;
    *(s64*)(root + 168u) = v;

    u64 hi = (u64)v >> 32;
    hi &= 0x7FFFFFFFu;
    s64 sx = (s64)(hi << 32);
    sx >>= 32;
    return (s32)sx;
}

s32 func_002feac0(u32 a0) {
    if (*(u32*)(a0 + 468u) == 0u) {
        u32 p = _malloc_r(a0, 128u);
        *(u32*)(a0 + 468u) = p;
        if (p == 0u) {
            return -1;
        }
        for (s32 i = 31; i >= 0; --i) {
            *(u32*)(p + ((u32)(31 - i) << 2)) = 0u;
        }
    }
    return 0;
}

void func_002fed98(u32* a0, u32 a1, u32 a2) {
    u32* b = (u32*)0x00380000u;
    b[-7495] = 0u;
    s32 r = func_00305df8(a1, a2);
    if (r == -1) {
        u32 v = b[-7495];
        if (v != 0u) {
            *a0 = v;
        }
    }
}

u32 func_00302c88(u32 a0, u32 a1) {  // alloc_88_array
    u32 size = 88u * a1;
    u32 h = _malloc_r(a0, size + 12u);
    if (h == 0u) {
        return 0u;
    }

    u32 p = h + 12u;
    *(u32*)(h + 4u) = a1;
    *(u32*)(h + 0u) = 0u;
    *(u32*)(h + 8u) = p;
    func_002fde18(p, 0u, size);
    return h;
}

void func_00302e10(u32 a0) {
    *(u32*)(a0 + 472u) = 0u;
    *(u32*)(a0 + 60u) = (u32)func_00302dd0;
    *(u32*)(a0 + 56u) = 1u;
    *(u32*)(a0 + 480u) = a0 + 484u;
    *(u32*)(a0 + 476u) = 3u;

    func_00302c28(*(u32*)(a0 + 4u), 4u, 0u, a0);
    func_00302c28(*(u32*)(a0 + 8u), 9u, 1u, a0);
    func_00302c28(*(u32*)(a0 + 12u), 10u, 2u, a0);
}

u32 func_00303e80(u32 a0) {  // count_leading_zeros
    u32 x = a0;
    u32 n = 0u;

    if ((x & 0xFFFF0000u) == 0u) {
        n = 16u;
        x <<= 16;
    }
    if ((x & 0xFF000000u) == 0u) {
        n += 8u;
        x <<= 8;
    }
    if ((x & 0xF0000000u) == 0u) {
        n += 4u;
        x <<= 4;
    }
    if ((x & 0xC0000000u) == 0u) {
        n += 2u;
        x <<= 2;
    }

    if ((s32)x < 0) {
        goto ret_n;
    }

    {
        u32 mask = 0x40000000u;
        n += 1u;
        if ((x & mask) == 0u) {
            return 32u;
        }
    }

ret_n:
    return n;
}

u32 func_00303f00(u32* p) {
    u32 t6 = p[0];
    u32 t7 = t6 & 7u;
    if (t7 == 0u) {
        goto L00303f44;
    }

    t7 = t6 & 1u;
    if (t7 != 0u) {
        return 0u;
    }

    if ((t6 & 2u) != 0u) {
        t7 = t6 >> 1;
        p[0] = t7;
        return 1u;
    }

    t7 = t6 >> 2;
    p[0] = t7;
    return 2u;

L00303f44:
    t7 = t6 & 0xFFFFu;
    u32 t5 = 0u;
    if (t7 == 0u) {
        t5 = 16u;
        t6 >>= 16;
    }

    t7 = t6 & 0xFFu;
    if (t7 == 0u) {
        t5 += 8u;
        t6 >>= 8;
    }

    t7 = t6 & 0xFu;
    if (t7 == 0u) {
        t5 += 4u;
        t6 >>= 4;
    }

    t7 = t6 & 3u;
    if (t7 == 0u) {
        t5 += 2u;
        t6 >>= 2;
    }

    t7 = t6 & 1u;
    if (t7 == 0u) {
        t5 += 1u;
        t6 >>= 1;
        if (t6 == 0u) {
            return 32u;
        }
    }

    p[0] = t6;
    return t5;
}

s32 func_003050b8(u32* out, u32 a1, u32 a2) {
    D_00378ae4 = 0;
    s32 r = func_00305dd8(a1, a2);
    if (r == -1) {
        u32 t = D_00378ae4;
        if (t != 0u) {
            out[0] = t;
        }
    }
    return r;
}

s32 func_00305110(u32* out, u32 a1, u32 a2, u32 a3) {
    D_00378ae4 = 0;
    s32 r = func_00305d18(a1, a2, a3);
    if (r == -1) {
        u32 t = D_00378ae4;
        if (t != 0u) {
            out[0] = t;
        }
    }
    return r;
}

void func_0030f068() {
    func_0030ee18();
    func_0030ef58();
    func_0030f548();
    func_0030f6c0(2u);
    func_0030f900();
    func_003063f8();
    func_0030f190();
    func_00311368();
    func_00310d80();
}

u32 __cxa_begin_catch(u32 a0) {
    u32 s0 = a0 - 48u;
    u32 v0 = __cxa_get_globals();

    s32 t14 = *(s32*)(s0 + 20u);
    u32 t13 = *(u32*)(v0 + 0u);

    if (t14 < 0) {
        u32 t15 = 1u;
        t14 = (s32)(t15 - (u32)t14);
    } else {
        t14 = t14 + 1;
    }

    *(u32*)(s0 + 20u) = (u32)t14;

    u32 t15 = *(u32*)(v0 + 4u);
    t15 = t15 - 1u;
    *(u32*)(v0 + 4u) = t15;

    if (s0 != t13) {
        *(u32*)(s0 + 16u) = t13;
        *(u32*)(v0 + 0u) = s0;
    }

    return *(u32*)(s0 + 40u);
}

void func_00319930(u32 a0) {
    s32 t14 = 19;
    u32 t15 = a0;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 80u;
    t14 = 2;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 92u;
    t14 = 17;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 164u;
    t14 = 8;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    *(volatile u32*)(a0 + 204u) = 0u;
    *(volatile u32*)(a0 + 200u) = 0u;
}

void func_003199d0(u32 a0) {
    *(u32*)(a0 + 0u) = 0u;
    s32 t14 = 2;
    *(u32*)(a0 + 4u) = 0u;
    u32 t15 = a0 + 16u;
    *(u32*)(a0 + 8u) = 0u;
    *(u32*)(a0 + 12u) = 0u;

    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 28u;
    t14 = 2;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    t15 = a0 + 40u;
    t14 = 2;
    do {
        *(u32*)t15 = 0u;
        t14 = t14 - 1;
        t15 = t15 + 4u;
    } while (t14 >= 0);

    *(volatile u8*)(a0 + 577u) = 0u;
    *(volatile u32*)(a0 + 52u) = 0u;
    *(volatile u32*)(a0 + 56u) = 0u;
}

void func_003181a0(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 s1 = a0;

    func_00317fc8(a0);

    u32 t15 = *(u8*)(s0 + 2888u);
    t15 = t15 << 2;
    t15 = t15 + s1;
    u32 t13 = *(u32*)t15;
    s32 t14 = (s32)(u32)(*(u64*)t13);
    t14 = t14 & -2;
    *(u32*)(s1 + 712u) = (u32)t14;
}

void func_0031d8f8(u32 self) {
    *(u32*)self = addr_D_0034aad8();
    func_002361d0(self + 416);
    *(u32*)self = addr_D_00347e60();
    func_00239870(self + 24);
    *(u32*)self = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_0031d8f8 fn = (Fn_0031d8f8)*(u32*)(*(u32*)obj + 4);
    fn(obj, self);
}

void func_0031d9b8(u32 self) {
    *(u32*)self = addr_D_0034ab80();

    if (self != (u32)-440) {
        u32 end = self + 2848;
        u32 begin = self + 440;
        do {
            if (begin == end) {
                break;
            }
            end -= 344;
            Fn_0031d9b8 fn = (Fn_0031d9b8)*(u32*)(*(u32*)end + 0);
            fn(end);
        } while (1);
    }

    *(u32*)self = addr_D_00347e60();
    func_00239870(self + 24);
    *(u32*)self = addr_D_00347f98();
}

void func_0031daf0(u32 self) {
    u32 s18 = self;
    u32 s16 = s18 + 880;
    s32 s17 = 3;
    s32 s19 = -1;

    func_0014ba90(s18);
    func_0013ee88(s18 + 336);
    func_0014b668(s18 + 624);

    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != s19);

    s16 = self + 1904;
    s17 = 3;
    s18 = (u32)-1;
    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != (s32)s18);
}

void func_0031dd50(u32 self) {
    *(u8*)(self + 4) = 0;
    *(u32*)self = addr_D_0034b250();

    u32 s18 = self;
    u32 s16 = s18 + 1072;
    s32 s17 = 5;
    s32 s19 = -1;

    func_0014c5a0(s18 + 16);
    func_0014c5a0(s18 + 544);

    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != s19);

    s16 = s18 + 2608;
    s17 = 5;
    s19 = -1;
    do {
        func_0014b668(s16);
        s17 -= 1;
        s16 += 256;
    } while (s17 != s19);

    func_0014c050(s18 + 4144);
}

void func_0031e740(u32 self) {
    u32 c0 = addr_D_0034e8b8();
    u32 c2824 = addr_D_00350e60();
    *(u32*)(self + 2824) = c2824;
    *(u32*)(self + 0) = c0;

    u32 s18 = self;
    func_001b0188(s18 + 2824);

    *(u32*)(s18 + 0) = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)(s18 + 0) = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    func_00105110(s18);
}

void func_0031e820(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
}

void func_0031e878(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_0031e948(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
}

void func_0031e9a0(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_0031ea80(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031ebf8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031ec98(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031ed48(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031edc8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031eed8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031ef58(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031f0c0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031f388(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031f408(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_0031f968(u32 self) {
    *(u32*)self = addr_D_00350c30();
    u32 s16 = self;

    u32 p = *(u32*)(self + 24);
    if (p != 0) {
        Fn_0031f968 fn = (Fn_0031f968)*(u32*)(*(u32*)p + 8);
        fn(p);
    }

    *(u32*)s16 = addr_D_00347f98();
}

void func_0031f9c0(u32 self) {
    *(u32*)self = addr_D_00350c30();
    u32 s16 = self;

    u32 p = *(u32*)(self + 24);
    if (p != 0) {
        Fn_0031f9c0 fn = (Fn_0031f9c0)*(u32*)(*(u32*)p + 8);
        fn(p);
    }

    *(u32*)s16 = addr_D_00347f98();
    func_00105110(s16);
}

void func_0031fec0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_0031ffc0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_003202d8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00320368(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)s18 = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00320968(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_003209e8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00320af0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00320d30(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00320da8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00320e20(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00320e98(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00320f18(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00320fa8(u32 self) {
    u32 c0 = addr_D_0034e8b8();
    u32 c2824 = addr_D_00350e60();
    *(u32*)(self + 2824) = c2824;
    *(u32*)(self + 0) = c0;

    u32 s18 = self;
    func_001b0188(s18 + 2824);

    *(u32*)(s18 + 0) = addr_D_0034ee08();
    func_0019f9a8(s18 + 2568);  // array8_free_slots
    func_001c0248(s18 + 2640);

    *(u32*)(s18 + 0) = addr_D_003503e0();
    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_003211c0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00321240(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00321338(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_003521e0();
    func_001d5718(s16 + 2932);  // list_free_nodes

    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);

    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_003213a8(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
}

void func_00321400(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_00321498(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
}

void func_003214f0(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_003215a8(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_0034e8b8();
    func_00319f88(s16 + 2824);
    *(u32*)s16 = addr_D_0034ee08();
    func_0019f9a8(s16 + 2568);  // array8_free_slots
    func_001c0248(s16 + 2640);
    func_00319fb0(s16);  // big_obj_dtor
    u32 t = s16;
    (void)t;
    func_00105110(s16);
}

void func_003217b0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00321830(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00321958(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_003219d8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00321b48(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
}

void func_00321bc8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_003503e0();

    if (s18 != (u32)-2524) {
        u32 s16 = s18 + 2548;
        u32 s17 = s18 + 2524;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 12;
            func_001d5718(s16);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s18 + 2492) = addr_D_00350e48();
    func_001b0188(s18 + 2492);
    func_0016a358(s18);
    u32 t = s18;
    (void)t;
    func_00105110(s18);
}

void func_00321de8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e028();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321de8 fn = (Fn_00321de8)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_00321e60(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e028();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321e60_dtor fn = (Fn_00321e60_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00321e60_mgr fn2 = (Fn_00321e60_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_00321ef8(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e050();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321ef8 fn = (Fn_00321ef8)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_00321f70(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e050();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 1248;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00321f70_dtor fn = (Fn_00321f70_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00321f70_mgr fn2 = (Fn_00321f70_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_00322008(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e168();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2472;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322008 fn = (Fn_00322008)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_00322080(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e168();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2472;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322080_dtor fn = (Fn_00322080_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322080_mgr fn2 = (Fn_00322080_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_00322118(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e190();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2880;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322118_dtor fn = (Fn_00322118_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322118_mgr fn2 = (Fn_00322118_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_003221b0(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e190();

    if (s18 != (u32)-24) {
        u32 s16 = s18 + 2880;
        u32 s17 = s18 + 24;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_003221b0 fn = (Fn_003221b0)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_00322908(u32 self) {
    u32 s16 = self;
    *(u32*)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32*)s16 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322908 fn = (Fn_00322908)*(u32*)(*(u32*)obj + 4);
    fn(obj, s16);
}

void func_00322a98(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e320();

    if (s18 != (u32)-28) {
        u32 s16 = s18 + 1252;
        u32 s17 = s18 + 28;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322a98 fn = (Fn_00322a98)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
}

void func_003229a0(u32 self) {
    u32 c0 = addr_D_0035e340();
    u32 c416 = addr_D_00347e80();
    *(u32*)(self + 416) = c416;
    *(u32*)self = c0;

    u32 s16 = self;
    func_002361d0(s16 + 448);

    u32 s17 = addr_D_00347f98();
    *(u32*)(s16 + 416) = s17;
    *(u32*)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32*)s16 = s17;
}

void func_00322a10(u32 self) {
    u32 c0 = addr_D_0035e340();
    u32 c416 = addr_D_00347e80();
    *(u32*)(self + 416) = c416;
    *(u32*)self = c0;

    u32 s16 = self;
    func_002361d0(s16 + 448);

    u32 s17 = addr_D_00347f98();
    *(u32*)(s16 + 416) = s17;
    *(u32*)s16 = addr_D_00347e60();
    func_00239870(s16 + 24);
    *(u32*)s16 = s17;

    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322a10 fn = (Fn_00322a10)*(u32*)(*(u32*)obj + 4);
    fn(obj, s16);
}

void func_00322b10(u32 self) {
    u32 s18 = self;
    *(u32*)s18 = addr_D_0035e320();

    if (s18 != (u32)-28) {
        u32 s16 = s18 + 1252;
        u32 s17 = s18 + 28;
        do {
            if (s17 == s16) {
                break;
            }
            s16 -= 408;
            Fn_00322b10_dtor fn = (Fn_00322b10_dtor)*(u32*)(*(u32*)s16 + 12);
            fn(s16);
        } while (1);
    }

    *(u32*)s18 = addr_D_00347f98();
    u32 t = D_00347f80;
    u32 obj = *(u32*)(t + 20);
    Fn_00322b10_mgr fn2 = (Fn_00322b10_mgr)*(u32*)(*(u32*)obj + 4);
    fn2(obj, s18);
}

void func_00323b90(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00323c30(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00323cd0(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00323d70(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00323dd0(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_0035f490();
    func_002361d0(s0 + 416);
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();
}

void func_00323e28(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_0035f490();
    func_002361d0(s0 + 416);
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}

void func_00324380(u32 self) {
    u32 s18 = self;
    s32 s23 = 3;
    s32 s19 = -1;
    s32 s30 = -1;

    do {
        u32 s16 = s18;
        s32 s17 = 1;
        do {
            *(u32*)s16 = addr_D_00347f98();
            func_0031a838(s16 + 12);
            *(u32*)s16 = addr_D_00347e60();
            func_00239700(s16 + 24);
            *(u32*)s16 = addr_D_00347e40();
            *(u32*)(s16 + 408) = 0;
            s16 += 436;
            --s17;
        } while (s17 != s19);

        --s23;
        s18 += 872;
    } while (s23 != s30);
}

void func_00324448(u32 self) {
    u32 s18 = self;
    s32 s23 = 9;
    s32 s19 = -1;
    s32 s30 = -1;

    do {
        u32 s16 = s18;
        s32 s17 = 1;
        do {
            *(u32*)s16 = addr_D_00347f98();
            func_0031a838(s16 + 12);
            *(u32*)s16 = addr_D_00347e60();
            func_00239700(s16 + 24);
            *(u32*)s16 = addr_D_00347e40();
            *(u32*)(s16 + 408) = 0;
            s16 += 436;
            --s17;
        } while (s17 != s19);

        --s23;
        s18 += 872;
    } while (s23 != s30);
}

void func_00324808(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_0034ee08();
    func_0019f9a8(s2 + 2568);  // array8_free_slots
    func_001c0248(s2 + 2640);
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}

u32 func_00324898(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_0034ee08();
    func_0019f9a8(s2 + 2568);  // array8_free_slots
    func_001c0248(s2 + 2640);
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    func_0031e7f8(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

void func_00324eb8(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}

u32 func_00324f38(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

u32 func_00325040(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

void func_00325218(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}

u32 func_00325298(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

void func_00325320(u32 a0, u32 a1) {  // list_remove_by_ptr
    u32 t7 = *(u32*)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32*)(a1 + 148);
        t5 = 0;
        *(u32*)a0 = t7n;
    } else {
        u32 t6 = *(u32*)(t7 + 148);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32*)(t6 + 148);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32*)(a1 + 148);
        *(u32*)(t5 + 148) = t7n;
    }

    u32 t7c = *(u32*)(a0 + 4);
    if (a1 == t7c) {
        *(u32*)(a0 + 4) = t5;
    }
    *(u32*)(a1 + 148) = 0;
}

void func_00325700(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    u32 t = s2;
    (void)t;
}

u32 func_00325780(u32 self) {
    u32 s2 = self;
    *(u32*)s2 = addr_D_003503e0();

    if (s2 != (u32)-2524) {
        u32 s0 = s2 + 2548;
        u32 s1 = s2 + 2524;
        do {
            if (s1 == s0) {
                break;
            }
            s0 -= 12;
            func_001d5718(s0);  // list_free_nodes
        } while (1);
    }

    *(u32*)(s2 + 2492) = addr_D_00350e48();
    func_001b0188(s2 + 2492);
    func_0016a358(s2);
    return func_00105110(s2);
}

void func_00325840(u32 a0, u32 a1) {
    u32 t7 = *(u32*)a0;
    u32 t5;

    if (a1 == t7) {
        u32 t7n = *(u32*)(a1 + 32);
        t5 = 0;
        *(u32*)a0 = t7n;
    } else {
        u32 t6 = *(u32*)(t7 + 32);
        if (t6 != a1) {
            do {
                u32 t7x = *(u32*)(t6 + 32);
                t5 = t6;
                if (t7x == a1) {
                    break;
                }
                t6 = t7x;
            } while (1);
        } else {
            t5 = t7;
        }
        u32 t7n = *(u32*)(a1 + 32);
        *(u32*)(t5 + 32) = t7n;
    }

    u32 t7c = *(u32*)(a0 + 4);
    if (a1 == t7c) {
        *(u32*)(a0 + 4) = t5;
    }
    *(u32*)(a1 + 32) = 0;
}
u32 func_002677f0(u32 a0, u32 a1);  // 0x002677f0: definition moved into src/anon/unit_00265580.cpp
