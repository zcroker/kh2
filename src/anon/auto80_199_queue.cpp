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

u8 func_00113990(u32 param_1, u32 param_2, u32 param_3, u32* param_4, u8 param_5) {
    (void)param_2;
    (void)param_3;

    if (param_5 != 0) {
        *param_4 = 0;
        if (func_0010f8c0(*(u32*)(param_1 + 4)) != 0) {  // test_field2940_bit2
            if (func_0010f8e0(*(u32*)(param_1 + 4)) != 0) {  // get_bit3_of_field2940
                return 0;
            }
            if (func_0010f8a8(*(u32*)(param_1 + 4)) <= 0.0f) {  // get_float_3284
                return 0;
            }
        }
        return (u8)(func_0010ef48(*(u32*)(param_1 + 4)) ^ 1);
    }

    if (func_0010f8c0(*(u32*)(param_1 + 4)) == 0) {  // test_field2940_bit2
        u32 obj = *(u32*)(param_1 + 8);
        f32 f12 = *(f32*)(obj + 0x78);
        f32 f13 = *(f32*)(obj + 0x7c);
        func_0010f880(f12, f13, *(u32*)(param_1 + 4));
    }
    func_00110630(*(u32*)(param_1 + 4));
    return 1;
}

void func_00115128(u32 param_1, u32 param_2) {
    u32 s1 = param_1;
    if (param_2 != 0) {
        u32 a1 = *(u32*)(param_2 + 0x20);
        if (a1 != 0) {
            if (((u16)*(u16*)(a1 + 2) - 0x2dcu) < 2u) {
                u32 s0 = (u32)&D_0036a698;
                u32 a0 = *(u32*)(param_1 + 4);
                if (func_001883d8(a0 + 0x300, s0) != 0) {
                    func_00188170(*(u32*)(s1 + 4) + 0x300, s0);
                    return;
                }
            }
        }
    }
}

void func_00116938(u32 param_1, f32* param_2, f32* param_3) {  // float_table_lookup_b
    (void)param_1;
    s32 iVar1 = (s32)func_0010f648(6);
    Pair00116938* p = &D_00347688[iVar1];
    *param_2 = p->x;
    *param_3 = p->y;
}

void func_00116990(u32 param_1, f32* param_2, f32* param_3) {  // float_table_lookup_a
    (void)param_1;
    s32 iVar1 = (s32)func_0010f648(6);
    Pair00116990* p = &D_003476b8[iVar1];
    *param_2 = p->x;
    *param_3 = p->y;
}

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

u32 func_00132208(u32 a0) {
    u32 t5 = 0;
    u32 v0;
    u32 t7;
    u32 t6;

    if (a0 == 0) {
        goto L0013224c;
    }

    v0 = func_001320b0(a0);  // read_u32_be
    t7 = 0x41584554;
    t5 = 1;
    if (v0 == t7) {
        goto L0013224c;
    }

    t6 = (t7 < v0);
    if (t6 != 0) {
        goto L0013225c;
    }

    t7 = 0x354e4b5f;

L00132244:
    if (v0 != t7) {
        t5 = 0;
    }

L0013224c:
    return t5;

L0013225c:
    t7 = 0x43535655;
    if (v0 == t7) {
        goto L0013224c;
    }

    t7 = 0x594d445f;
    goto L00132244;
}

void func_00133598(u32 a0, u32 a1, u32 a2) {
    u32 t6 = a1 + 15;
    *(u8*)(a0 + 0) = 0;
    t6 = t6 & 0xFFFFFFF0;

    u32 a1n = a1 + a2;
    a1n = a1n - t6;
    a1n = a1n >> 1;

    u32 t7 = t6 + a1n;
    (*(u32*)(a0 + 8) = t6, *(u32*)(a0 + 12) = t7, *(u32*)(a0 + 4) = t6);
    *(u32*)(a0 + 16) = a1n;

    u32 v0 = func_001336f8(a0);
    *(u32*)(a0 + 24) = v0;

    *(u32*)(a0 + 20) = 0;
    *(u32*)(a0 + 28) = 0;

    func_00133be8(a0, 0, 0, 0);  // forward_sub24_to_1338e8
    func_00133690(a0);
    func_00133be8(a0, 0, 0, 0);  // forward_sub24_to_1338e8
    func_00133690(a0);
}

void func_00133de8(void) {
    sceGsSyncPath(0, 0);
    func_00133d18();

    u32 v0 = func_00133d38();
    D_00347cac = v0;

    func_002f3918(v0, (u32)&D_0032a780);
    func_00134030();  // poll_timer_status

    D_00347cb4 = 0;
    D_00347cb0 = 0xFFFFFFFF;
}

void func_00133e50(void) {
    u32 s0 = (u32)&D_00347c88;

    func_00133c60(s0, (u32)&D_0032a870, 0, 0, 0);  // forward_sub24_to_133980
    func_00133be8(s0, 0, 0, 0);  // forward_sub24_to_1338e8
    func_00133768(s0);
}

void func_00133ea8(void) {
    u32 s0 = (u32)&D_00347c88;

    func_00133c60(s0, (u32)&D_0032a870, 0, 0, 0);  // forward_sub24_to_133980
    func_00133be8(s0, 0, 0, 0);  // forward_sub24_to_1338e8
    func_00133690(s0);
    func_00133c60(s0, (u32)&D_0032a850, 0, 0, 0);  // forward_sub24_to_133980
}

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

u32 func_00144d10(f32* a0, f32* a1) {
    if (a0[3] < a1[0]) {
        return 0;
    }
    f32 f1 = a0[0];
    f32 f0 = a1[3];
    if (f0 < f1) {
        return 0;
    }
    if (a0[4] < a1[1]) {
        return 0;
    }
    f1 = a0[1];
    f0 = a1[4];
    if (f0 < f1) {
        return 0;
    }
    if (a0[5] < a1[2]) {
        return 0;
    }
    f1 = a0[2];
    f0 = a1[5];
    if (f0 < f1) {
        return 0;
    }
    return 1;
}

u32 func_00144d90(f32* a0, f32* a1) {  // aabb_overlap
    f32 f1 = a0[0];
    f32 f0 = a1[0];
    if (f0 < f1) {
        return 0;
    }

    f1 = a0[3];
    f0 = a1[3];
    if (f1 < f0) {
        return 0;
    }

    f1 = a0[1];
    f0 = a1[1];
    if (f0 < f1) {
        return 0;
    }

    f1 = a0[4];
    f0 = a1[4];
    if (f1 < f0) {
        return 0;
    }

    f1 = a0[2];
    f0 = a1[2];
    if (f0 < f1) {
        return 0;
    }

    f1 = a0[5];
    f0 = a1[5];
    if (f1 < f0) {
        return 0;
    }

    return 1;
}

void func_001461f0(u32 a0, u8* a1) {
    u32 s0 = *(u32*)(a1 + 44);
    u32 s1 = a0;
    if (s0 == 0) {
        return;
    }

    do {
        u32 t7 = *(u32*)(s0 + 248);
        if ((t7 & 0x800) == 0) {
            func_001471d8(s1, s0);
        } else {
            func_001471d8(s1, s0);
        }
        s0 = *(u32*)(s0 + 272);
    } while (s0 != 0);
}

void func_00148ac0(u8* a0) {
    s32 s0 = 0;
    u32* s2 = D_003a99f0;
    s32 s1 = *(s32*)(a0 + 21372);

    while (s0 < 256) {
        if (s1 <= 0) {
            return;
        }

        u32 t7 = *s2;
        s2 += 1;
        if (t7 != 0) {
            func_00147f08((u32)a0, t7);
            s1 -= 1;
        }

        s0 += 1;
    }
}

void func_00148bc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 cur = *(u32*)(a1 + 44);
    if (*(u32*)a2 == cur) {
        return;
    }
    if (cur == 0) {
        return;
    }

    while (cur != 0) {
        if (func_00144d10(cur + 208, a3) == 1) {
            if ((*(u32*)(cur + 248) & 2) != 0) {
                func_00148b40(a0, cur);
            }
        }
        cur = *(u32*)(cur + 272);
    }
}

// 001491d8: moved to src/harata/libdk/mapfile.cpp

// 0014ddb0: moved to src/anon/unit_0014d680.cpp

u32 func_0014f788(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 b34 = 0x00340000;
    u32 s1 = a4;
    u32 s2 = a1;
    u32 s3 = a2;
    u32 s4 = a3;
    u32 s5 = a0;

    u32 t = *(u32*)(b34 + 32640);
    u32 obj = *(u32*)(t + 20);
    u32 fn = *(u32*)(*(u32*)obj + 0);
    u32 s0 = ((u32 (*)(u32, u32, u32))fn)(obj, 6576, 0);
    func_0031bd98(s0);
    func_00150de0(s0, s5, s2, s3, s4, s1);
    return s0;
}

void func_00150260(u32 a0, u32 a1, s32 a2, u32 a3) {
    char buf[16];
    u32 s1 = a0;
    s32 s2 = a2;
    u32 s0 = a3;

    func_002fee78((u32)buf, (u32)D_0036b228, a1);

    if (s2 > 0) {
        s32 n = s2;
        char* p = &buf[8];

        do {
            s32 d = (s32)(*p) - 48;
            n--;
            p--;
            u32 idx = ((u32)d) << 2;
            idx = idx + s1;
            *(u32*)s0 = *(u32*)idx;
            s0 += 4;
        } while (n != 0);
    }
}

void func_001505b0(u32 a0) {
    u32 s1 = a0 + 840;
    func_00138c10(s1, 4);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 1248;
    func_00138c10(s0, 10);
    *(s32*)(s0 + 392) = s2;
}

void func_00150678(u32 a0) {
    *(u32*)(a0 + 6176) = 1;

    u32 s1 = a0 + 840;
    func_00138c10(s1, 5);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 1248;
    func_00138c10(s0, 11);
    *(s32*)(s0 + 392) = s2;
}

void func_00151528(u32 a0) {
    *(u32*)(a0 + 6568) = 1;

    u32 s1 = a0 + 496;
    func_00138c10(s1, 5);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 904;
    func_00138c10(s0, 11);
    *(s32*)(s0 + 392) = s2;
}

void func_00151b78(u32 a0) {
    u32 s1 = a0 + 840;
    func_00138c10(s1, 4);

    s32 s2 = -1;
    *(s32*)(s1 + 392) = s2;

    u32 s0 = a0 + 2472;
    func_00138c10(s0, 10);
    *(s32*)(s0 + 392) = s2;
}

void func_00151bf0(u32 a0) {
    *(u32*)(a0 + 2896) = 1;

    u32 s0 = a0;
    u32 s1 = a0 + 840;

    func_00138c10(s1, 5);
    s0 = s0 + 2472;
    func_00138c10(s0, 11);

    s32 v = -1;
    *(s32*)(s1 + 392) = v;
    *(s32*)(s0 + 392) = v;
}

void func_00152718(u32 a0, u32 a1, u32 a2, u32 a3) {
    u8 buf[96];
    u32 s1 = a0 + 24;
    u32 s2 = a1;
    u32 s3 = a2;
    u32 s4 = a3;

    u32 n = *(u32*)(a0 + 440);
    if (n == 0) {
        return;
    }

    volatile u32* vp = (volatile u32*)a0;
    u32 a1v = vp[107];
    u32 a3v = vp[106];
    func_001a98e8(buf, a1v, n, a3v, 0);

    u32 s0 = s2 + func_0023aa18(s1);
    u32 v = func_0023aa38(s1);
    func_001a9ae8(buf, s0, s3 + v + 17, s4);
}

void func_001527b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u8 buf[96];
    u32 s2 = a3;
    u32 s0 = a1;
    u32 s1 = a2;

    func_001a98e8(buf, 1, *(u32*)(a0 + 436), *(u32*)(a0 + 424), 1);
    func_001a9ae8(buf, s0, s1, s2);
}

void func_00152910(u32 a0) {
    u32 s0 = a0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    func_001390c0(s0);

    func_00152820(s0, (u32)&v0, (u32)&v1, (u32)&v2, (u32)&v3, (u32)&v4);

    func_001527b8(s0, v0, v1, v4);
    func_00152688(s0, v2, v3, v4);
    func_00152718(s0, v0, v1, v4);
}

void func_00152a30(u32 a0) {
    u32 s0 = a0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    func_001390c0(s0);
    func_00152820(s0, (u32)&v0, (u32)&v1, (u32)&v2, (u32)&v3, (u32)&v4);

    func_001527b8(s0, v0, v1, v4);
    if (*(u32*)(s0 + 448) != 0) {
        func_00152688(s0, v2, v3, v4);
    }
    func_00152718(s0, v0, v1, v4);
}

void func_00152ae8(u32 a0) {
    u32 s0 = a0;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    func_001390c0(s0);
    func_00152820(s0, (u32)&v0, (u32)&v1, (u32)&v2, (u32)&v3, (u32)&v4);

    func_001527b8(s0, v0, v1, v4);
    func_00152688(s0, v2, v3, v4);
}

void func_00153cc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u8 ctx[32];
    u32 s0 = a0;
    u32 s2 = a2;
    u32 s3 = a3;
    u32 s4 = a4;

    *(u32*)(s0 + 160) = a1;

    func_0023f800(ctx);
    func_0023fa08(ctx, *(u32*)(s0 + 160));

    u32 s1 = func_0023f948(ctx, 0);
    u32 v = func_0023f908(ctx, 0);

    func_0023eea0(s0, s2, s1, v, s3, s4);
    func_0023f848(ctx);
}

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

u32 func_00168f18() {
    func_00168808(0xFFFFFFFFu);
    func_001675b0();
    func_001b13d8();
    func_0016e8f8();
    func_00180f28();
    func_00194a30();
    func_00196170();
    func_00196300();
    func_00199688();
    func_001aeb80();
    func_001d53e8();
    func_001aaa08();
    func_0019f790();
    func_00192320();
    func_001d9d00();
    return func_001b13f0();
}

void func_00168fd8(u32 a0) {
    func_00195738();
    func_001afa50();
    func_001ba138();  // to_2fd310_block

    s32 t5 = 13;
    if ((s32)a0 == t5) {
        func_00170a50();
        return;
    }
    if ((s32)D_004f6280 == t5) {
        func_00170a50();
    }
}

void func_00169f98(u8* a0) {
    if ((*(u32*)(a0 + 1416) & 0x20u) == 0) {
        u32 t2 = func_00168b38(*(u32*)(a0 + 1964), 3, 0);  // entry_array_find_nth
        D_004f6284 = t2;
        if (t2 != 0) {
            u32 t5 = *(u32*)(t2 + 8);
            if (t5 != 0) {
                func_0016a158((u32)a0, t5);
            }
        }
    }

    kn::FVector* t6 = (kn::FVector*)(a0 + 2192);
    kn::FVector* t7 = (kn::FVector*)(a0 + 1344);
    if (t6 != t7) {
        *t6 = *t7;
    }

    u32 t7v = *(u32*)(a0 + 2040);
    f32 f0 = *(f32*)(a0 + 1372);
    *(f32*)(a0 + 2204) = f0;
    *(u32*)(a0 + 2040) = t7v | 0x80u;
}

u32 func_0016ad68(u32 a0, u32 a1, f32 f12) {
    f32 f20 = f12;
    f32 f0 = func_0016afe0(a1);
    f0 = f0 + f20;
    ((void(*)(u32, f32))func_0016aeb8)(a0, f0);
    return func_0016ad38(a0, func_0016c028(a1));
}

f32 func_0016ae58(u8* a0, f32 f12) {
    kn::FVector sp0;
    kn::FVector* s0 = (kn::FVector*)(a0 + 1360);
    u8* s1 = a0;
    f32 f20 = f12;

    func_0019c400((u32)s1);
    func_0017d0e8(&sp0, f20);
    if (s0 != &sp0) {
        *s0 = sp0;
    }

    return *(f32*)(s1 + 1372);
}

u32 func_0016aef0(u32 a0, u32 a1) {
    if (func_0019c400(a0) != 0) {
        return func_0016b070(a0, a1);
    }

    f32 f0 = func_002f8ad0(*(f32*)(a1 + 0), *(f32*)(a1 + 8));
    return ((u32(*)(u32, f32))func_0016aeb8)(a0, f0);
}

f32 func_0016b558(u32 a0, u32 a1) {
    u32 s2 = a1;
    u32 s1 = a0;
    u8* s0 = func_0016bc20(a0, 15, 0xFFFFFFFFu);
    func_0016b0e0(s1, *(u16*)(s0 + 6), s2);
    return (f32)*(s16*)(s0 + 8);
}

void func_0016b5b8(u8* a0) {
    u32 t6 = *(u32*)(a0 + 264);
    if ((t6 & 0x10000000u) == 0) {
        u32 t7 = *(u32*)(a0 + 1156);
        if (t7 != 0) {
            func_00188738(a0 + 768);
            func_0016ce90(*(u32*)(a0 + 1156));
        }

        func_00180ce0(a0 + 320);

        u32 t6p = *(u32*)(a0 + 8);
        u32 t7v = *(u8*)(t6p + 84);
        func_001826c8((f32)(-(s32)t7v));
        t6 = *(u32*)(a0 + 264);
    }

    *(u32*)(a0 + 264) = t6 | 0x10000000u;
}

u32 func_0016bba8(u8* a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    u8* s1 = a0;
    u32 s2 = a1;
    u32 v0;

    if (*(u32*)(s1 + 2264) == 0) {
        return 0;
    }

loop:
    s0 = func_0018a100(*(u32*)(s1 + 2264), s2, s0);
    if (s0 == 0) {
        goto done;
    }

    v0 = func_0019bd08((u32)s1, *(u8*)s0);
    if (v0 == 0) {
        goto loop;
    }
done:
    return s0;
}

u32 func_0016bc98(u8* a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    u8* s1 = a0;
    u32 s2 = a1;
    u32 v0;

    if (*(u32*)(s1 + 2264) == 0) {
        return 0;
    }

loop:
    s0 = func_0018a1b8(*(u32*)(s1 + 2264), s2, s0);  // find_byte1_entry
    if (s0 != 0) {
        v0 = func_0019bd08((u32)s1, *(u8*)s0);
        if (v0 == 0) {
            goto loop;
        }
    }
    return s0;
}

u32 func_0016bda8(u32 a0, u32 a1) {
    u8 sp0[32];
    func_00190128(sp0);
    func_00190878(sp0, a1, 0);
    func_00190388(a0, sp0);  // vec4_from_arg
    return a0;
}

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

void func_001da340(u32 a0, u32 a1) {
    (void)a0;
    u32 s17 = a1;
    u32 s16 = D_0034e948;

    if (func_0019ba60(s16) != 0) {
        u32 t7 = *(u32*)(s17 + 40);
        t7 = t7 & 1u;
        if (t7 != 0) {
            if (((u32(*)(u32, u32, f32, f32))func_001c7950)(s17, s16, 0.0f, 0.0f) != 0) {
                func_001c79a0(s17, s16, 0);
                func_001d86a0(1, 0);
                return;
            }
        }
    }
}

u32 func_001db610(u32 a0, Func_001db610_cb a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a2;
    Func_001db610_cb s2 = a1;
    u32 ret;

    if (*(u16*)(s0 + 0) == 0) {
        goto L_zero;
    }

    while (1) {
        u32 v0 = s2(s0, s1);
        u32 t7 = *(u16*)(s0 + 2);
        t7 = t7 << 2;
        t7 = func_001db610_add(s0, t7);
        s0 = t7 + 4;
        if (v0 == 0) {
            ret = s0;
            goto L_ret;
        }
        t7 = *(u16*)(t7 + 4);
        if (t7 == 0) {
            goto L_zero;
        }
    }

L_zero:
    ret = 0;

L_ret:
    return ret;
}

void func_001dc8c8(u32 a0, f32 a1);  // 0x001dc8c8: definition moved into src/anon/unit_001dbfd8.cpp

void func_001dc978(u32 a0, f32 a1);  // 0x001dc978: definition moved into src/anon/unit_001dbfd8.cpp

void func_001dcf58(u32 a0);  // 0x001dcf58: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001dcff0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5);  // 0x001dcff0: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001dd098(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5);  // 0x001dd098: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001dd140(u32 a0);  // 0x001dd140: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de3d8(u32 a0, u32 a1) {
    u32 s2 = a1;
    u32 s3 = a0;
    u32 s0 = *(u32*)(a0 + 12);
    if (s0 == 0) {
        return;
    }

    while (1) {
        u32 t6 = *(u32*)(s0 + 68);
        u32 t7 = *(u8*)(t6 + 4);
        u32 s1 = *(u32*)(s0 + 96);
        if (t7 == s2) {
            func_00321ce8(s3 + 12, s0);  // list_unlink_node
            func_001dc920(*(u32*)(s0 + 64));
            func_001e0058(s0);
        }
        if (s1 != 0) {
            s0 = s1;
            continue;
        }
        return;
    }
}

// 001e0868: moved to src/rikeda/saveram_gumibattle.cpp

// 001e0ac0: moved to src/rikeda/saveram_gumibattle.cpp

void func_001e16c0(u32 a0) {
    u32 s0 = a0;
    u32* base = (u32*)0x00350000;
    func_001e0d08(a0, a0);
    func_001e0d68(s0, s0 + 16);
    func_001e0dc8(s0);
    if (func_001e2778(base[0x0AF4])) {
        func_001e0e40(s0);
        return;
    }
    *(u32*)(s0 + 36) = 0;
}

void func_001e18d8(u32 a0) {
    u32 s0 = a0;
    u32 v0 = *(u32*)(s0 + 3540);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3540) = 0;
    }

    v0 = *(u32*)(s0 + 3544);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3544) = 0;
    }

    v0 = *(u32*)(s0 + 3548);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3548) = 0;
    }

    v0 = *(u32*)(s0 + 3552);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3552) = 0;
    }

    v0 = *(u32*)(s0 + 3524);
    if (v0 != 0) {
        func_00105110(v0);
        *(u32*)(s0 + 3524) = 0;
    }

    v0 = *(u32*)(s0 + 3528);
    if (v0 != 0) {
        func_00105110(v0);
        *(u32*)(s0 + 3528) = 0;
    }
}

void func_001e2938(u32 a0) {
    u32 s1 = a0;
    u32* base = (u32*)0x00350000;
    func_001e2298(base[0x0AF4]);
    if (*(u32*)(base[0x0AF4] + 3520) == 7) {
        func_001024a8(s1);
        return;
    }
}

void func_001e5970(u32 a0) {  // obj_clear_header
    *(u8*)(a0 + 18) = 0;
    *(volatile s8*)(a0 + 16) = -1;
    *(volatile u32*)(a0 + 0) = 0;
    *(volatile u64*)(a0 + 8) = 0;
    *(volatile u8*)(a0 + 17) = 0;
}

void func_001e5990(u32 a0) {
    s32 s0 = (s32)a0;
    s32 s1 = (s32)a0 + 816;
    s32 s2 = (s32)a0;
    while (1) {
        func_001e5970((u32)s0);  // obj_clear_header
        s0 += 24;
        if (s0 < s1) {
            continue;
        }
        break;
    }

    s0 = s2 + 816;
    s1 = 19;
    do {
        u32 a0_call = (u32)s0;
        s1 -= 1;
        func_001e5970(a0_call);  // obj_clear_header
        s0 += 24;
    } while ((s32)s1 >= 0);
}

void func_001e74d8(u32 a0) {
    u32 s0 = a0;
    volatile u32* st = (volatile u32*)0x10003c00;
    while ((*st & 3) != 0) {
    }

    func_002f3bb8(0x10009000, 0, 0);
    func_002f3918(0x10009000, s0);
}

void func_001e8fe0(u32 a0, u32 a1) {
    u32 s0 = a1;
    B64_001e8fe0 b0;
    B64_001e8fe0 b1;
    B64_001e8fe0 b2;
    B64_001e8fe0 b3;

    func_0021ead0(&b0, *(u32*)(s0 + 8));  // table_float_pair_lookup
    func_0021ea50(&b1, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021e9d0(&b3, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    sceVu0MulMatrix(a0, (u32)&b2, (u32)&b3);
}

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

void func_001fa7b0(u32 a0, u32 a1, u32 a2) {
    u32 t3 = *(u32*)(a2 + 12);
    u32 t5 = *(u32*)(a1 + 0);
    u32 t7 = *(u32*)(t3 + 0);
    u32 t6 = *(u32*)(a0 + 12);
    u32 t4 = a0 + t7;
    u32 t2 = t4 + 160;

    if (t5 != t6) {
        return;
    }

    u32 t7b = *(u32*)(t3 + 4);
    u32 t7p = a0 + t7b + 160;
    *(u32*)(t4 + 160) = t7p;

    u32 t6b = *(u32*)(a1 + 4);
    if (t6b == 0xFFFF) {
        *(u32*)(t2 + 4) = 0;
        return;
    }

    u32 t3off = t6b << 3;
    u32 t7c = 0x01da0000;
    volatile u32* gp = (volatile u32*)t7c;
    u32 t4p = *(u32*)(t2 + 4);
    u32 t6c = gp[-1607];
    u32 t5c = *(u32*)(t6c + 20);
    u32 t5ptr = t5c + t3off;
    if (t5ptr == t4p) {
        return;
    }

    *(u32*)(t2 + 4) = t5ptr;
    u32 t7d = *(u32*)(t5ptr + 0);
    u16 t6h = *(u16*)(t7d + 18);
    *(u8*)(t2 + 10) = 0;
    *(u16*)(t2 + 8) = t6h;
}

void func_001fa950(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 t3 = *(u32*)(a2 + 12);
    u32 t5 = *(u32*)(a1 + 0);
    u32 t7 = *(u32*)(t3 + 0);
    u32 t6 = *(u32*)(a0 + 12);
    u32 t4 = a0 + t7;
    u32 s1 = t4 + 160;

    if (t5 == t6) {
        u32 t7b = *(u32*)(t3 + 4);
        u32 t7p = a0 + t7b + 160;
        *(u32*)(t4 + 160) = t7p;

        u32 t6b = *(u32*)(a1 + 4);
        if (t6b == 0xFFFF) {
            *(u32*)(s1 + 4) = 0;
        } else {
            u32 t3off = t6b << 3;
            u32 k = 0x01da0000;
            volatile u32* gp = (volatile u32*)k;
            u32 oldp = *(u32*)(s1 + 4);
            u32 t6c = gp[-1607];
            u32 t5c = *(u32*)(t6c + 20);
            u32 t7c = t5c + t3off;
            if (t7c != oldp) {
                u32 a2c = *(u8*)(s0 + 22);
                func_0021f908(s1, t7c, a2c);
            }
        }

        u16 t7h = *(u16*)(s0 + 18);
        *(u16*)(s1 + 10) = t7h;
        u16 t6h = *(u16*)(s0 + 16);
        *(u16*)(s1 + 12) = t6h;
        u8 t7u = *(u8*)(s0 + 23);
        *(u8*)(s1 + 14) = t7u;
    }
}

void func_001facf8(u32 a0, u32 a1, u32 a2) {
    u32 t3 = *(u32*)(a2 + 12);
    u32 t5 = *(u32*)(a1 + 0);
    u32 t7 = *(u32*)(t3 + 0);
    u32 t6 = *(u32*)(a0 + 12);
    u32 t4 = a0 + t7;
    u32 t2 = t4 + 160;

    if (t5 != t6) {
        return;
    }

    u32 t7b = *(u32*)(t3 + 4);
    u32 t7p = a0 + t7b + 160;
    *(u32*)(t4 + 160) = t7p;

    u32 t6b = *(u32*)(a1 + 4);
    if (t6b == 0xFFFF) {
        *(u32*)(t2 + 4) = 0;
        return;
    }

    u32 t3off = t6b << 3;
    u32 k = 0x01da0000;
    volatile u32* gp = (volatile u32*)k;
    u32 oldp = *(u32*)(t2 + 4);
    u32 t6c = gp[-1607];
    u32 t5c = *(u32*)(t6c + 20);
    u32 t5ptr = t5c + t3off;
    if (t5ptr == oldp) {
        return;
    }

    *(u32*)(t2 + 4) = t5ptr;
    u32 t7d = *(u32*)(t5ptr + 0);
    u16 t6h = *(u16*)(t7d + 18);
    *(u8*)(t2 + 10) = 0;
    *(u16*)(t2 + 8) = t6h;
}

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

u32 func_0020ecc8(u32 a0, u32 a1) {
    u32 s18 = a1;
    s32 s17 = sceOpen(a0, 1);
    if (s17 < 0) {
        *(volatile u32*)0 = 0;
        return 0;
    }

    s32 s16 = sceLseek(s17, 0, 2);
    sceLseek(s17, 0, 0);

    s32 t = sceRead(s17, s18, s16);
    if ((s16 ^ t) != 0) {
        s16 = 0;
    }

    sceClose(s17);
    func_003058a0(0);
    return (u32)s16;
}

void func_0021eb50(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021ea50(&b0, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    func_0021ead0(&b1, *(u32*)(s0 + 8));  // table_float_pair_lookup
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021e9d0(&b3, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}

void func_0021ebe8(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021e9d0(&b0, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    func_0021ead0(&b1, *(u32*)(s0 + 8));  // table_float_pair_lookup
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ea50(&b3, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}

void func_0021ec80(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021ead0(&b0, *(u32*)(s0 + 8));  // table_float_pair_lookup
    func_0021e9d0(&b1, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ea50(&b3, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}

void func_0021ed18(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021ea50(&b0, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    func_0021e9d0(&b1, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ead0(&b3, *(u32*)(s0 + 8));  // table_float_pair_lookup
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}

void func_0021edb0(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021e9d0(&b0, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    func_0021ea50(&b1, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ead0(&b3, *(u32*)(s0 + 8));  // table_float_pair_lookup
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}

void func_00221fb8(u32 a0, u32 a1, u32 a2) {
    a2 = a2 & 0xff;
    a1 = a1 & 0xff;

    *(u8*)(a0 + 1) = (u8)a2;
    u32 t7 = a2 - 1;
    u32 t6 = a0 + 16;
    *(u8*)(a0 + 0) = (u8)a1;

    a2 = t7 & 0xff;
    *(u32*)(a0 + 4) = t6;

    t7 = 48;
    a1 = a1 - 1;
    t7 = a2 * t7;
    t7 = t7 + 128;
    a2 = t7 & 0xffff;

    *(u16*)(a0 + 2) = (u16)a2;
    if ((s32)a1 > 0) {
        do {
            u32 t7p = t6;
            a1 = a1 - 1;
            t6 = t6 + a2;
            *(u32*)(t7p + 0) = t6;
        } while ((s32)a1 > 0);
    }

    *(u32*)(t6 + 0) = 0;
}

void func_00222018(u32 a0, u32 a1) {
    u32 s2 = a1;
    u32 s3 = a0;
    u32 s1 = *(u32*)(a0 + 0);

    if (s1 != 0) {
        do {
            u32 s0 = s1;
            s1 = *(u32*)(s1 + 0);
            func_00221ed0(s0);
            u32 t7 = *(u32*)(s2 + 4);
            *(u32*)(s0 + 0) = t7;
            *(u32*)(s2 + 4) = s0;
        } while (s1 != 0);
    }

    *(u32*)(s3 + 0) = 0;
}

void func_00224b08(u32 a0) {
    u32 s0 = a0;
    if (func_00224e90(s0) == 0) {
        return;
    }

    func_00224998();
    func_0022b930();  // to_1397d8_arg11
    func_00102448(s0, 1);
    func_0022b948();
}

void func_00224e28() {
    if (func_00224e90() == 0) {
        return;
    }

    if (func_00224988() == 0) {  // get_global_byte_36dad5
        func_0022b930();  // to_1397d8_arg11
        func_0013a218();
        func_0022b948();
    }

    func_0022b968();
    func_0022b7b0();
    func_0014ce20(1);
}

void func_00224ea0(u32 a0) {
    u32 s0 = a0;
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }

    s32 v = func_00224968() ? func_00224978() : *(s16*)(s0 + 6);
    func_00224940();
    func_00226f78(v);
}

void func_00225cd8() {
    if (*(u8*)((u32)&D_00360000 - 8696) != 1) {
        return;
    }

    func_002ba620();
    u32 v0 = func_0014ac08();
    ((dk::Fade*)v0)->fadeOut(0, false);
    func_002252b0();
    func_00226dc8();
}

u32 func_002263f0(u32 a0, u32 a1) {
    u32 t4;
    s32 t5;
    u32 t7;
    u32 p;
    s32 n;

    t4 = D_0035dd08[D_0035de60];

    if (t4 == 0) {
        goto FAIL;
    }

    t5 = *(s16*)(t4 + 8);
    t7 = D_0035de5c;
    if ((s32)t7 < t5) {
        goto STORE_FAIL;
    }

    *(u32*)(a0 + 0) = (u32)t5;

    p = D_0035dd08[D_0035de60];

    n = *(s16*)(p + 8);
    n = n - 1;
    *(u32*)(a1 + 0) = (u32)n;

    D_0035de60 = D_0035de60 + 1;
    return 1;

STORE_FAIL:
    *(u32*)(a0 + 0) = t7;
FAIL:
    return 0;
}

u32 func_00226ce8(u32 a0) {
    s32 s1;
    u32 v0;

    func_0022bb60();
    func_0022bbc8();
    s1 = 0;

    if (a0 != 0) {
LOOP:
        v0 = func_00170cd0();
        if (v0 != 0) {
            goto LOOP_CALL;
        }
        if (func_00225e48(a0) == 0) {
            goto CLEANUP;
        }
        if (s1 != 0) {
            goto CLEANUP;
        }
        func_00102448(a0, 0);
    }

CLEANUP:
    func_00226bd0(a0);
    func_00228240();
    func_0022c108();
    return func_0015f288();

LOOP_CALL:
    func_00102448(a0, 0);
    s1 = 1;
    goto LOOP;
}

void func_00227200(u32 a0) {
    func_002bbe38(a0);
    func_00161ee8();
    D_0035db10 = 1;
    func_00226ee8(a0);
    func_00226f90();
    func_00226fa8();
    func_00226fc8();
    func_0022bd80();
    D_0035de10 = -1;
    D_0035de64 = 0;
    D_0035de55 = 0;
    D_0035de08 = 0;
    D_0035de58 = 0;
    D_0035de0a = 0;
    D_0035de0b = 0;
    D_0035de26 = 0;
}

u32 func_00227870(u32 a0, u32 a1, u32 a2) {
    u32 s0;
    u32 s1;
    u32 s2;

    (void)a0;
    s1 = a2;
    s2 = a1;

    s0 = func_00225eb8((u32)&D_0035db00, func_00227818(), s1);
    func_002fde18(s0, 0, 2048);
    return func_00227858(s0, s2, s1);
}

void func_002280f8() {
    func_0022d820();
    func_0022e288();
    func_00227078();
    func_00224e28();
    func_00224bd0();
    func_00226fc8();
    func_002267a0();
    D_0035db10 = 0;
}

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

void func_0022d3c8(u32 a0) {
    u32 s17 = a0;
    f32 f0;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f20;

    if (func_002282f0(*(u16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(u16*)(s17 + 4)) != 0) {  // flag_query_by_index
        return;
    }
    f0 = func_00227c78(s17 + 8);
    f20 = f0;
    f13 = f0;
    f14 = (f32)(*(u16*)(s17 + 6));
    f12 = D_0035de48;
    func_0014cde0(f12, f13, f14);
    D_0035de48 = f20;
}

void func_0022d598(u32 a0, u32 a1) {
    u32 s16v = a0;
    u32 s17 = a1;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    func_0022d440();
    func_00225a10();
    func_00102448(s17, 2);
    func_00170320(-200);
    func_0022d4e8(s16v);
    func_00170888(s17);
    func_00225a20();
}

void func_0022d618(u32 a0) {
    u32 s16v = a0;
    s32 a4;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s8*)(s16v + 7) == 0) {
        func_0015ee10(*(s8*)(s16v + 6));
        return;
    }
    a4 = *(s8*)(s16v + 6);
    if (func_0015f718(a4) != 0) {  // test_bit_global64
        return;
    }
    func_0015ee90(*(s8*)(s16v + 6));
}

void func_0022e3e8(u32 a0) {
    u32 s16v = a0;
    u32 s17;
    u32 p;
    u32 q;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 8));
    func_001ba028(*(u32*)(s17 + 8));  // list_contains_ptr
    if (*(s16*)(s16v + 10) != 0) {
        func_00194468(*(u32*)(s17 + 8));
        return;
    }
    p = *(u32*)(s17 + 8);
    q = *(u32*)(p + 268);
    q = q | 0x200;
    *(u32*)(p + 268) = q;
}

void func_0022e468(u32 a0) {
    u32 s16v = a0;
    u32 s17;
    u32 p;
    u32 q;
    s32 d;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 8));
    func_001ba028(*(u32*)(s17 + 8));  // list_contains_ptr
    d = 0xbfff0000;
    d = d | 0xffff;
    if (*(s16*)(s16v + 10) != 0) {
        u32 p1 = *(u32*)(s17 + 8);
        u32 q1 = *(u32*)(p1 + 264);
        q1 = q1 & (u32)d;
        *(u32*)(p1 + 264) = q1;
        goto L0022e4c0;
    }
    p = *(u32*)(s17 + 8);
    q = *(u32*)(p + 264);
    q = q | 0x40000000;
    *(u32*)(p + 264) = q;
L0022e4c0:
    return;
}

void func_0022e5f8(u32 a0) {
    u32 s18 = a0;
    u32 s16v;
    u32 s17;
    f32 f0;
    f32 f20;
    f32 f21;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s16v = func_00227d10(*(s16*)(s18 + 6));
    func_001ba028(*(u32*)(s16v + 8));  // list_contains_ptr
    s17 = *(u32*)(s16v + 8);
    f21 = func_00227c78(s18 + 8);
    s17 = s17 + 2248;
    f20 = func_00227c78(s18 + 12);
    f0 = func_00227c78(s18 + 16);
    func_001ad990(s17, f21, f20, f0);
}

void func_0022e998(u32 a0) {
    u32 s17 = a0;
    u32 s16v = *(u32*)(a0 + 8);

    if (func_002f13b0(s16v) != 0) {
        return;
    }
    func_00106420(s16v);
    *(u32*)(s17 + 8) = 0;
    func_001024a8(s17);
}

void func_0022ef50(u32 a0) {
    u32 s17 = a0;
    u32 s16v;
    u32 p;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s16v = func_00227d10(*(s16*)(s17 + 8));
    func_001ba028(*(u32*)(s16v + 8));  // list_contains_ptr
    p = *(u32*)(s16v + 8);
    func_0011c798(*(u32*)(p + 1648), s17 + 10);
}

void func_0022f200(u32 a0) {
    u32 s16v = a0;
    u32 s17;
    u32 p;
    u32 q;
    s32 mask = -2;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 8));
    func_001ba028(*(u32*)(s17 + 8));  // list_contains_ptr
    if (*(s16*)(s16v + 10) != 0) {
        u32 p1 = *(u32*)(s17 + 8);
        u32 q1 = *(u32*)(p1 + 264);
        q1 = q1 & (u32)mask;
        *(u32*)(p1 + 264) = q1;
        goto L0022f254;
    }
    p = *(u32*)(s17 + 8);
    q = *(u32*)(p + 264);
    q = q | 0x1;
    *(u32*)(p + 264) = q;
L0022f254:
    return;
}

void func_0022f280(u32 a0) {
    u32 s16v = a0;
    u32 s17;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s17 = func_00227d10(*(s16*)(s16v + 6));
    func_001ba028(*(u32*)(s17 + 8));  // list_contains_ptr
    if (*(s8*)(s16v + 10) == 1) {
        func_00194070(*(u32*)(s17 + 8), *(u16*)(s16v + 8));
    } else {
        func_00194088(*(u32*)(s17 + 8), *(u16*)(s16v + 8));
    }
}

void func_00231948(u32 a0) {
    u32 s16v = a0;
    s32 t14;
    s32 a4;
    f32 f12;

    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(s16*)(s16v + 4)) != 0) {  // flag_query_by_index
        return;
    }

    t14 = 0;
    a4 = *(s16*)(s16v + 6);
    if ((a4 & 0x8000) != 0) {
        a4 = a4 & 0x7fff;
        t14 = 1;
    }
    f12 = (f32)a4;
    func_00161f48(t14, f12);
}

u32 func_00233a18(u32 a0, u32 a1) {
    u32 out;
    u8* pb = (u8*)&out;
    u8* a = (u8*)&a0;
    u8* b = (u8*)&a1;
    u32 t12;
    u32 t14;
    u32 t15;

    t14 = (u32)a[0] + (u32)b[0];
    t12 = out;
    t15 = (u32)-256;
    t12 = t12 & t15;
    t14 = t14 >> 1;
    t12 = t12 | t14;
    out = t12;
    pb[1] = (u8)(((s32)((u32)a[1] + (u32)b[1])) >> 1);
    pb[2] = (u8)(((s32)((u32)a[2] + (u32)b[2])) >> 1);
    pb[3] = (u8)(((s32)((u32)a[3] + (u32)b[3])) >> 1);
    return out;
}

u32 func_00236490(void* a0) {
    s32 key;
    s32 i;
    DivEntry* p;

    key = *(s32*)((u8*)a0 + 0x1c);
    i = 0;
    p = &D_0035ea48[0];

    while (i < 14) {
        if (p->key == key) {
            s32 t6 = *(s32*)((u8*)a0 + 0xc);
            s32 t7 = *(s32*)((u8*)a0 + 0x8);
            s32 d = p->div;
            s32 n = t7 * t6;
            if (n < 0) {
                n += 15;
            }
            n >>= 4;
            return (u32)(n / d);
        }
        i += 1;
        p += 1;
    }

    return 0;
}

u32 func_002364f8(void* a0) {
    s32 key;
    s32 i;
    DivEntry* p;

    key = *(s32*)((u8*)a0 + 0x30);
    i = 0;
    p = &D_0035ea48[0];

    while (i < 14) {
        if (p->key == key) {
            s32 t6 = *(s32*)((u8*)a0 + 0x28);
            s32 t7 = *(s32*)((u8*)a0 + 0x24);
            s32 d = p->div;
            s32 n = t7 * t6;
            if (n < 0) {
                n += 15;
            }
            n >>= 4;
            return (u32)(n / d);
        }
        i += 1;
        p += 1;
    }

    return 0;
}

void func_00236830(void* a0) {
    u64 t6;
    s32 t7;

    if (*(u8*)((u8*)a0 + 0x190) != 0) {
        func_00236d98(a0);
        return;
    }

    t6 = *(u64*)((u8*)a0 + 0x30);
    t7 = ((s32)(t6 >> 32)) & 1;
    if (t7 != 0) {
        sceGsExecLoadImage((u8*)a0 + 0x40, *(u32*)((u8*)a0 + 0x38));
        t6 = *(u64*)((u8*)a0 + 0x30);
    }

    t7 = ((s32)(t6 >> 33)) & 1;
    if (t7 != 0) {
        sceGsExecLoadImage((u8*)a0 + 0xa0, *(u32*)((u8*)a0 + 0x3c));
    }
}

void func_00236c38(void* a0) {
    u8* base;
    u8* end;

    base = (u8*)*(u32*)((u8*)a0 + 0x14);
    if (base == 0) {
        return;
    }

    end = base + (*(s32*)(base - 4) * 0x1a0);
    for (;;) {
        if (base == end) {
            break;
        }
        end -= 0x1a0;
        ((void(**)(void*))(*(u32*)end))[0]((void*)end);
        base = (u8*)*(u32*)((u8*)a0 + 0x14);
    }

    func_00106450((void*)(base - 0x10));
    *(u32*)((u8*)a0 + 0x14) = 0;
}

u32 func_00239af8(void* a0, u32 a1) {
    u8* s0;
    u8* s1;
    s32 v0;
    s32 t6;
    s32 t7;

    s1 = (u8*)a0;
    v0 = (s32)func_00239b50(a0, a1);  // find_entry_in_group

    s0 = (u8*)(a1 * 36u);
    s0 = (u8*)((u32)s0 + *(u32*)(s1 + 0xb4));
    t6 = *(s32*)(s0 + 0xc);
    v0 -= 1;
    if (t6 != 0) {
        t7 = (t6 < v0) ? 1 : 0;
        if (t7 != 0) {
            v0 = t6;
        }
    }
    return (u32)v0;
}

void func_0023c300(void* a0) {
    u8* s1;
    u8* a;
    u8* s0;

    s1 = (u8*)a0;

    a = (u8*)*(u32*)(s1 + 0x2c);
    if (a != 0) {
        s0 = a + (*(s32*)(a - 4) * 344);
        for (;;) {
            if (a == s0) {
                break;
            }
            s0 -= 344;
            ((void(**)(void*))(*(u32*)s0))[0]((void*)s0);
            a = (u8*)*(u32*)(s1 + 0x2c);
        }
        func_00106450((void*)(a - 4));
        *(u32*)(s1 + 0x2c) = 0;
    }

    a = (u8*)*(u32*)(s1 + 0x30);
    if (a != 0) {
        s0 = a + (*(s32*)(a - 4) * 344);
        for (;;) {
            if (a == s0) {
                break;
            }
            s0 -= 344;
            ((void(**)(void*))(*(u32*)s0))[0]((void*)s0);
            a = (u8*)*(u32*)(s1 + 0x30);
        }
        func_00106450((void*)(a - 4));
        *(u32*)(s1 + 0x30) = 0;
    }
}

u32 func_0023c978(void* a0) {
    u8* s2;
    u8* s1;
    u8* s0;
    s32 s3;

    s2 = (u8*)a0;
    s3 = 0;

    s1 = (u8*)(*(u32*)(s2 + 0x14) + (*(u32*)(s2 + 0x4c) * 20u));
    s0 = (u8*)(*(u32*)(s2 + 0x10) + ((u32)*(u16*)(s1 + 0) * 24u));

    if (*(u16*)(s1 + 2) != 0) {
        for (;;) {
            u32 idx;
            u32 v0;

            idx = *(u32*)(s0 + 4);
            v0 = func_00239d30((void*)(*(u32*)(s2 + 0x2c) + (idx * 344u)), *(u32*)(s0 + 8));
            s0 += 24;
            if (v0 != 0) {
                return 1;
            }
            s3 += 1;
            if (s3 < (s32)*(u16*)(s1 + 2)) {
                continue;
            }
            break;
        }
    }

    return 0;
}

void func_0023d368() {
    if (D_0035eb50 != 0) {
        func_0014ce20(0);
    }
    func_0014ce30(D_0035eb54);
    D_0035eb50 = (u8)(D_00349e20 < 1);
    D_0035eb54 = D_00349e1c;
}

u32 func_0023d438(void* a0, u32 a1) {
    u8* s2;
    u8* s0;
    s32 i;

    s2 = (u8*)a0;
    *(u32*)(s2 + 0x0c) = 0;
    *(u32*)(s2 + 0x00) = (u32)&D_0035eb60;

    s0 = s2 + 0x20;
    for (i = 3; i != -1; --i) {
        func_00106ab8(s0);  // noop_ret
        func_001070c8(s0 + 0x100);  // set_vtbl_34cc50
        s0 += 0x190;
    }

    s0 = s2 + 0x660;
    for (i = 3; i != -1; --i) {
        func_00322ba8(s0);
        s0 += 0x140;
    }

    func_0014c050(s2 + 0xb80);
    func_0014c050(s2 + 0xe90);
    func_0014c050(s2 + 0x11a0);

    *(u32*)(s2 + 0xb6c) = a1;
    return func_0023d5b8(s2);
}

u32 func_0023d4f8(void* a0, u32 a1) {
    u8* s2;
    u8* s0;
    s32 i;

    s2 = (u8*)a0;
    *(u32*)(s2 + 0x0c) = 0;
    *(u32*)(s2 + 0x00) = (u32)&D_0035eb60;

    s0 = s2 + 0x20;
    for (i = 3; i != -1; --i) {
        func_00106ab8(s0);  // noop_ret
        func_001070c8(s0 + 0x100);  // set_vtbl_34cc50
        s0 += 0x190;
    }

    s0 = s2 + 0x660;
    for (i = 3; i != -1; --i) {
        func_00322ba8(s0);
        s0 += 0x140;
    }

    func_0014c050(s2 + 0xb80);
    func_0014c050(s2 + 0xe90);
    func_0014c050(s2 + 0x11a0);

    *(u32*)(s2 + 0xb6c) = a1;
    return func_0023d5b8(s2);
}

void func_0023e5d0(void* a0, u32 a1, void* a2) {
    u8* s1;
    u8* s0;
    u8 idx;

    s1 = (u8*)a0;
    a1 += (u32)a0;
    idx = *(u8*)(a1 + 0xb64);
    s0 = s1 + ((u32)idx * 0x140) + 0x660;

    *(u32*)(s0 + 0x74) = (u32)a2;
    {
        f32 (*vf)(void*);
        vf = *(f32 (**)(void*))(*(u32*)a2 + 0x1c);
        *(volatile f32*)(s0 + 0x12c) = vf(a2);
    }
    {
        void* obj;
        f32 (*vf)(void*);
        obj = (void*)*(volatile u32*)(s0 + 0x74);
        vf = *(f32 (**)(void*))(*(u32*)obj + 0x1c);
        *(f32*)(s0 + 0x130) = vf(obj);
    }

    *(f32*)(s0 + 0x134) = func_0023e700(s1);
    *(u8*)(s0 + 0x13c) = 1;
    *(u32*)(s0 + 0x128) = 0;

    return func_0011eb08(*(u32*)(s0 + 0x30), 10);
}

void func_0023eae0(void* a0, u32 a1, s32 a2, s32 a3) {
    u8* s1;
    u8 idx;
    s32 s0;
    s32 s2;

    a1 += (u32)a0;
    s0 = a2;
    s2 = a3;

    idx = *(u8*)(a1 + 0xb64);
    s1 = (u8*)a0 + ((u32)idx * 0x140) + 0x660;

    if (a2 < a3) {
        do {
            func_0011c7f8(*(u32*)(s1 + 0x30), s0);
            s0 += 1;
        } while (s0 < s2);
    }
}

void func_0023eb50(void* a0, u32 a1, s32 a2) {
    u8* s2;
    s32 s0;
    s32 s1;
    u32 t7;

    a1 += (u32)a0;
    s1 = a2;

    s2 = (u8*)a0 + ((u32)*(u8*)(a1 + 0xb64) * 0x140) + 0x660;
    if (a2 != 0) {
        s0 = 0;
        do {
            t7 = (u32)(s1 >> s0);
            t7 &= 1u;
            if ((u8)t7 != 0) {
                func_0011c7f8(*(u32*)(s2 + 0x30), s0);
            }
            s0 += 1;
        } while (s0 < 32);
    }
}

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

u32 func_00241e18(void) {
    u32 picks[8];
    u16* s16 = D_003717a8;
    s32 s17 = 0;
    u32* s18 = picks;
    u32 s19 = 0;

    do {
        u32 v0;
        u16 t7 = s16[0];
        if (t7 != 0) {
            v0 = func_00181500(t7);
            if (v0 == 0) {
                v0 = 1;
                goto decided;
            }
        }
        v0 = func_00181500(s16[1]);
decided:
        if (v0 != 0) {
            *s18 = s17;
            s19 += 1;
            s18 += 1;
        }
        s17 += 1;
        s16 = (u16*)((u8*)s16 + 4);
    } while (s17 < 8);

    u32 v0 = func_0014cba0();
    u32 t7 = v0 % s19;
    return picks[t7];
}

void func_00242110(u32 a0) {
    u32 s18 = func_002421e8(a0);
    u32 s17 = *(u32*)(a0 + 4);
    func_002efb60(s17);
    func_00242258(a0);
    if (s18 != 0) {
        func_002efa88(s17);
    }
}

void func_002423a0(void);  // 002423a0: moved to src/tozawa/crc.cpp (linked unit)

extern "C" void func_002436d0(u32) asm("_ZN2Tz4HEFT11PauseThreadEP4TASK");

extern "C" void func_00245400(u32) asm("_ZN2Tz4HECO11PauseThreadEP4TASK");

void func_002468e8(u32 a0, u32 a1) {
    u8 sp_buf[16];
    u8 v;

    if (func_00246840(a0) == 0) {
        v = *((u8*)((u32)&D_00371c98 + a0));
    } else {
        v = *((u8*)((u32)&D_00371ca0 + a0));
    }

    func_00199718(sp_buf, v, -1);
    sp_buf[2] = a1;
    func_00104f58(sp_buf, 1, 0, 0, 12);
}

u32 func_002469a0(u32 a0) {
    s32 s0 = 0;
    s32 s1 = 0;

    while (s0 < 4) {
        if (func_00246968(s0) != 0) {
            if (s1 == a0) {
                s1 = s1 + 1;
                break;
            }
            s1 = s1 + 1;
        }
        s0 = s0 + 1;
    }

    return (u32)s0;
}

u32 func_00246a08(void) {
    if (func_00276c18() != 0) {
        return 1;
    }

    u32 s3 = 0;
    s32 s0 = 0;
    while (s0 < 4) {
        u32 a0;
        if (func_00246840() != 0) {
            a0 = *((u8*)((u32)&D_00371cb0 + s0));
        } else {
            a0 = *((u8*)((u32)&D_00371ca8 + s0));
        }

        u8* p = func_001d56c8(a0);
        if ((u32)p[0] >= 2) {
            s3 = 1;
            break;
        }
        s0 = s0 + 1;
    }
    return s3;
}

u32 func_002474e0(u32 a0) {
    u32 s1 = 0;
    u32 s0 = func_002469a0(a0);
    if (func_00246840() != 0) {
        s0 = *((u8*)((u32)&D_00371cb0 + s0));
    } else {
        s0 = *((u8*)((u32)&D_00371ca8 + s0));
    }

    u8* p = func_001d56c8(s0);
    u32 t = p[0];
    if (t == 3) {
        s1 = 1;
    }
    else if (t == 2) {
        if (s0 == 7) {
            u32 t0 = *(u32*)(p + 4);
            t0 = (u32)(t0 < 10);
            s1 = (u32)(t0 < 1);
        }
    }

    return s1;
}

extern "C" void func_00247ff0(u32) asm("_ZN2Tz4MUMI11PauseThreadEP4TASK");

extern "C" void func_00249940(u32) asm("_ZN2Tz4TRTE11PauseThreadEP4TASK");

extern "C" void func_0024b510(u32) asm("_ZN2Tz4HBTE11PauseThreadEP4TASK");

extern "C" void func_0024cda8(u32) asm("_ZN2Tz4TTPT11PauseThreadEP4TASK");

extern "C" void func_0024e7e8(u32) asm("_ZN2Tz4TTMY11PauseThreadEP4TASK");

extern "C" void func_0024f698(u32) asm("_ZN2Tz4LMMU11PauseThreadEP4TASK");

extern "C" void func_00250748(void) asm("_ZN2Tz4LMMU7CtrlSelEv");

extern "C" void func_002510d0(u32) asm("_ZN2Tz4CANA11PauseThreadEP4TASK");

void func_00251a08(void) {
    if (func_00139d78(D_0035ee80) != 0) {
        u32 p = D_0035ee80;
        u32 vt = *(u32*)p;
        ((void(*)(u32))(*(u32*)(vt + 20)))(p);
    }
    if (func_0028acc8(D_0035ee5c) != 0) {
        func_0028abe0(D_0035ee5c);
    }
}

void func_00251f40(void) {
    if (func_00139d78(D_0035ee68) == 0) {
        func_0028d980(D_0035ee68, 30022, 2, 2, D_0035ee60, 20, 21, -1, 0);

        u32 s0 = D_0035ee68;
        *(u32*)(s0 + 408) = func_00192048(18405);

        *(u32*)(D_0035ee68 + 432) = 2;

        u32 a = D_0035ee68 + 24;
        *(u32*)(a + 184) = *(u32*)(a + 184) | 8;

        *(u8*)(D_0035ee68 + 405) = 1;
    }
}

u32 func_00252098(u32 a0) {
    u32 s0 = a0;
    u32 v0 = 1;
    u32 t = D_003725d0[a0];
    if (t != 0) {
        v0 = func_001a6d08(t);
    }
    if (s0 == 1) {
        v0 = (v0 ^ 1) & 0xFF;
    }
    return v0;
}

void func_00252180(void) {
    func_00139d78(D_0035ee6c);
    if (func_00252098(1) != 0) {
        func_0028b300(D_0035ee6c, 30003, 1, 1, D_0035ee60, (u32)&D_00372608, (u32)&D_00372618, 26, 0);
        *(u8*)(D_0035ee6c + 405) = 1;
        u32 a = D_0035ee6c + 24;
        *(u32*)(a + 184) = *(u32*)(a + 184) | 8;
    }
}

void func_00252810(void) {
    u32 p = D_0035ee9c;
    if (p != 0) {
        func_00106450(p);
        D_0035ee9c = 0;
    }

    p = D_0035eea8;
    if (p != 0) {
        u32 vt = *(u32*)p;
        ((void(*)(u32))(*(u32*)(vt + 16)))(p);
        D_0035eea8 = 0;
    }

    p = D_0035eea4;
    if (p != 0) {
        u32 vt = *(u32*)p;
        ((void(*)(u32))(*(u32*)(vt + 16)))(p);
        D_0035eea4 = 0;
    }
}

void func_00252890(u32 a0) {
    u32 s0 = a0;
    func_002430d8(D_0035ee88);
    func_00102448(s0, 1);
    func_00252900();
    while (1) {
        func_00236d60();  // clear_64_entries_24
        if (func_00252ad8() != 0) {
            return;
        }
        func_00252f98();
        func_00102448(s0, 0);
    }
}

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

void func_00254f08(void) {
    if (func_00139d78(D_0035f02c) != 0) {
        Obj00254f08* obj = (Obj00254f08*)D_0035f02c;
        obj->vtbl->fn20(obj);
    }

    if (func_00256b80(0) != 0) {
        Obj00254f08* obj2 = (Obj00254f08*)func_00256b68(0);
        obj2->vtbl->fn20(obj2);
    }

    u32 v0 = func_00287dc0();
    func_0023d820(v0);
}

void func_002550e8(void) {
    if (func_00139d78(D_0035f03c) != 0) {
        u32 v0 = func_0023f0c0(D_0035f03c);
        if (v0 != 1) {
            func_0023f070(D_0035f03c, 1, -1);
        }
    }

    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028ab20(D_0035f01c);
    }

    func_0028ff18(D_0035f044);
    func_00290438(D_0035f048);

    if (func_00139d78(D_0035f02c) != 0) {
        u32 p = D_0035f02c;
        if (*(u32*)(p + 388) != 47) {
            func_00138c10(p, 47);
            *(s32*)(D_0035f02c + 392) = -1;
        }
    }
}

void func_00256aa0(void) {
    u32 s0 = func_00287dc0();
    if (func_00139d78(s0) != 0) {
        func_0023d820(s0);
    }

    if (func_00139d78(D_0035f040) != 0) {
        Obj00256aa0* obj = (Obj00256aa0*)D_0035f040;
        obj->vtbl->fn20(obj);
    }

    if (func_00290060(D_0035f044) != 0) {
        func_0028ff68(D_0035f044);
    }

    if (func_00290580(D_0035f048) != 0) {
        func_00290488(D_0035f048);
    }

    func_0028f878();
}

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

void func_00257530(u32 a0) {
    u8* p;

    if (a0 != 0) {
        goto nonzero;
    }
    p = &D_00372a00;
    goto cont;

nonzero:
    p = &D_00372a08;

cont:
    func_0028dac8(D_0035f034, *(s16*)(p + 2));

    if (func_0028acc8(D_0035f024) != 0) {
        if (func_0028acb8(D_0035f024) == 0) {
            func_0028aa40(D_0035f024);
        }
    }
}

u32 func_00257610(u32 a0) {
    u32 s0 = a0;
    if (func_002576d0(a0) == 0) {
        return 0;
    }

    u8* p;
    if (s0 != 0) {
        goto nonzero;
    }
    p = &D_00372a00;
    goto cont;

nonzero:
    p = &D_00372a08;

cont:
    s32 t4 = *(s16*)(p + 4);
    u32 t5 = *(u32*)(D_0035f034 + 388);
    u32 t7 = t5 ^ (u32)t4;
    t7 = (t7 < 1) ? 1u : 0u;
    return t7;
}

u32 func_00257910(void) {
    u32 v0 = func_00139d78(D_0035f038 + 0xb350);
    if (v0 != 0) {
        return v0;
    }

    v0 = func_00139d78(D_0035f038 + 0xb504);
    if (v0 != 0) {
        return v0;
    }

    u32 r3 = func_00139d78(D_0035f038 + 0xb6b8);
    v0 = r3;
    return v0;
}

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

u32 func_00262300(void) {
    u32 s1 = 0;
    S_00262300* s0 = func_00256b68(1);

    if (s0 != 0) {
        if (func_00139d78((void*)s0) != 0) {
            s1 = (((u32)s0->v388 ^ 0x126) < 1);
        }
    }

    return s1;
}

void func_00262360(void) {
    S_00262360* s0 = func_00256b68(1);
    if (s0 == 0) {
        return;
    }
    if (func_00139d78((void*)s0) == 0) {
        return;
    }
    if (s0->v388 == 294) {
        return;
    }
    func_00138c10((void*)s0, 294);
}

void func_00262768(void) {
    u32 s1 = func_00257770();
    u32 s0 = s1 + 816;

    if (func_00139d78(s0) == 0) {
        func_0028d8c0(s0, (u32)(D_0035f3d4 + 2), (u32)D_0035ef68, (u32)D_0035ef64, (u32)D_0035f03c, 240, (u32)-1, 0);
    }

    func_0028dcc0(s0, s1 + 2504);

    s32 v0;
    s32 v1;
    s32 idx = (s32)D_0035f0b5;
    u32 p = s1 + 3376 + (u32)(idx * 436);

    func_00138c78(p, (u32)&v0, (u32)&v1);
    ((dk::Sprite*)(u32)s0)->setOffsetPos((u32)v0, (u32)v1);
}

u32 func_002632d0(u32 a0) {
    u32 s1 = a0;
    u8* s0 = func_00281f20(func_00257130());

    u32 v0 = func_00281f18(func_00257130());
    if (v0 == 0) {
        return v0;
    }

    u8* p = (u8*)((s1 * 6) + (u32)s0);
    return func_001a80c8((u32)(*(u16*)p));  // table24_find_by_id
}

void func_00263340(u32 a0, u32 a1) {
    (void)a0;

    if (a1 == 1) {
        func_00261d48();
        func_00262af8();
        return;
    }

    if (a1 != 10) {
        func_00262af8();
        return;
    }

    if (func_00289358() != 0) {
        func_00262820();
        func_00262a30();
        return;
    }

    func_00262a30();
    func_00262af8();
}

void func_00263570(s32 a0) {
    s32 t;

    if (a0 == -10) {
        t = *(u8*)&D_0035f0b5;
        t = t + 1;
        D_0035f0b5 = (u8)t;
        if ((s8)t >= 5) {
            D_0035f0b5 = 0;
        }
    } else {
        t = *(u8*)&D_0035f0b5;
        t = t - 1;
        D_0035f0b5 = (u8)t;
        if ((s8)t < 0) {
            D_0035f0b5 = 4;
        }
    }

    func_00262768();
}

u32 func_002811b0(u32, s32) asm("_ZN2Tz9PartyInfo10GetPartNumEi");
u32 func_002815b8(void) asm("_ZN2Tz9PartyInfo10GetNowFormEv");

void func_00263720(u32 a0) {
    u16 s0 = *(u16*)func_002632d0((u32)Tz::CmTop::GetSelectPos(10));
    u32 v0 = func_002811b0(D_0035f010, a0);
    u32 (*fp)(u32, u32) = func_001a2d78;
    (void)fp((u32)s0, v0);
}

void func_00263858(s32 a0) {
    s32 s0 = a0;
    s32 s1 = func_00257070(10);
    s32 v0 = func_00257088(10);

    if ((v0 + s1) < s0) {
        return;
    }

    if (s1 != 0) {
        s1 -= 1;
    } else {
        if (v0 != 0) {
            v0 -= 2;
        } else {
            s1 = 0;
        }
    }

    func_00257050(10, s1, v0);
}

void func_002639f8(void) {
    D_0035f0bc = -1;
    D_0035f0c0 = 0;
    D_0035f0b8 = -1;

    Obj_002639f8* obj = D_0035f0dc;
    if (obj != 0) {
        obj->vtbl->fn10((void*)obj);
        D_0035f0dc = 0;
    }
}

void func_00263bb0(u16* a0, u16* a1) {
    for (s32 i = 0; i < 3; i += 1) {
        D_0035f0c8[i] = a0[i];
    }

    for (s32 i = 0; i < 5; i += 1) {
        D_0035f0d0[i] = a1[i];
    }

    if (func_00263cc0() == 0) {
        return;
    }

    func_0028b6f0(D_0035f0dc, (u32)D_0035f0c8);
    func_0028b720(D_0035f0dc, (u32)D_0035f0d0);
}

void func_00263db0(u32 a0) {
    func_00263ea0(a0);
    func_00102448(a0, 1);
    func_00263e10();

    while (1) {
        if (func_00263e18() != 0) {
            return;
        }
        func_00263e98();
        func_00102448(a0, 0);
    }
}

void func_00265580(void) {
    u32 s0 = func_00257770();

    if (func_00287bc0() != 23) {
        return;
    }

    func_0028dac8(s0, 142);
    if (func_0028acb8(D_0035f01c) == 0) {
        func_0028aa40(D_0035f01c);
    }
}

void func_00265a30(void) {
    u32 s0 = func_00257770();

    if (func_00287bc0() != 24) {
        return;
    }

    func_0028dac8(s0, 322);

    if (func_0028acb8(D_0035f01c) == 0) {
        func_0028aa40(D_0035f01c);
    }

    if (func_0028acb8(D_0035f020) == 0) {
        func_0028aa40(D_0035f020);
    }
}

u32 func_00266c00(void) {
    s32 s0 = 0;
    u32 s2 = 0;

    while (s0 < 4) {
        if (func_001a3570((u32)D_00373470[s0]) != 0) {
            s2 |= (1u << s0);
        }
        s0 += 1;
    }

    return s2;
}

void func_00267398(void) {
    s32 s0 = 0;

    while (s0 < 6) {
        u32* base = D_0035f0e4;
        u32 idx = (u32)s0;
        u32 v0 = base[idx];

        if (v0 != 0) {
            func_001a17c8(v0);
            base = D_0035f0e4;
            base[idx] = 0;
        }

        s0 += 1;
    }
}

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

u32 func_00267620() {
    if (D_0035f0ec == 0) {
        Obj0* o = D_0032ba14;
        u32 s0 = o->vtbl->fn0(o, 4196, __builtin_return_address(0));
        func_00281ec8(s0);
        D_0035f0ec = s0;
    }
    return func_00281f40(D_0035f0ec, D_0035f010);
}

void func_00267690() {
    u32 s0 = D_0035f0ec;
    if (s0 != 0) {
        func_00281f10(s0);
        Obj1* o = (Obj1*)D_0032ba14;
        o->vtbl->fn1(o, s0);
        D_0035f0ec = 0;
    }
}

u32 func_0026acb8(u32 a0) {
    u32 s1 = a0;
    u32 s2 = func_00257070(1);
    u32 v0 = func_00281180(D_0035f010, s2);
    u16* s0 = *(u16**)(v0 + 580);

    u32 cur = s0[0];
    u32 r = 0;
    if (cur == s1) {
        return r;
    }

    u32 z = 0;
    u32 hundred = 100;
    func_001a3188(cur, hundred, z);
    s0[0] = (u16)s1;
    func_001a3458(s1, hundred);

    u32 h = func_002811b0(D_0035f010, s2);
    func_002933d8(h, 0, s1, 0);
    return 1;
}

u32 func_0026ad68(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = func_00257070(1);

    u32 cur = func_002814b0(s0);
    u32 r = 0;
    if (cur == s1) {
        return r;
    }

    func_001a3188(cur, 100, 0);
    func_002814f0(s0, s1);
    func_001a3458(s1, 100);

    if (func_002815b8() == s0) {
        u32 h = func_002811b0(D_0035f010, s2);
        func_002933d8(h, 1, s1, 0);
    }

    return 1;
}

u32 func_0026ae20(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t = func_00257070(1);

    u32 ptr = func_00281180(D_0035f010, t);
    u32 base = *(u32*)(ptr + 580);

    s0 = s0 << 1;
    s0 = s0 + base;

    u32 cur = *(u16*)(s0 + 20);
    if (cur == s1) {
        return 0;
    }

    if (cur != 0) {
        func_001a3188(cur, 100, 0);
    }

    *(u16*)(s0 + 20) = (u16)s1;
    if (s1 != 0) {
        func_001a3458(s1, 100);
    }

    return 1;
}

u32 func_0026aea8(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t = func_00257070(1);

    u32 ptr = func_00281180(D_0035f010, t);
    u32 base = *(u32*)(ptr + 580);

    s0 = s0 << 1;
    s0 = s0 + base;

    u32 cur = *(u16*)(s0 + 36);
    if (cur == s1) {
        return 0;
    }

    if (cur != 0) {
        func_001a3188(cur, 100, 0);
    }

    *(u16*)(s0 + 36) = (u16)s1;
    if (s1 != 0) {
        func_001a3458(s1, 100);
    }

    return 1;
}

u32 func_0026b860(u32 a0) {
    u32 s0 = a0 & 0xFF;
    u32 s1 = func_00257070(1);
    u32 v0 = func_00281100(D_0035f010);
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

    func_00257050(1, s1, 0);
    v0 = func_00281140(D_0035f010, s1);
    return func_0028fb68(1, v0);
}

u32 func_0026cb38() {
    u32 a0 = 0x846C;
    if (func_00287bc0() == 20) {
        if ((s32)func_002892f8(D_0035f01c) < 3) {
            a0 = D_00373838;
        } else {
            a0 = D_00373834;
        }
    }
    return func_00263a58(a0, 1);
}

void func_0026cb90() {
    u32 v = func_00287bc0();
    if (v == 20 || v == 22) {
        u32 h = func_00256b68(1);
        func_0028dac8(h, 314);

        if (func_0028acc8(D_0035f01c) != 0) {
            if (func_0028acb8(D_0035f01c) == 0) {
                func_0028aa40(D_0035f01c);
            }
        }

        if (func_0028acc8(D_0035f024) != 0) {
            func_00288e88(D_0035f024);
        }
    }
}

u32 func_0026d560() {
    u32 s1 = 0;
    u32 s0 = func_00256b68(1);
    if (s0 != 0) {
        if (func_00139d78(s0) != 0) {
            u32 v = *(u32*)(s0 + 388);
            s1 = ((v ^ 0x139) < 1);
        }
    }
    return s1;
}

void func_0026d5c0() {
    u32 s0 = func_00256b68(1);
    if (s0 != 0) {
        if (func_00139d78(s0) != 0) {
            if (*(u32*)(s0 + 388) != 313) {
                func_00138c10(s0, 313);
                *(u32*)(s0 + 392) = 0xFFFFFFFF;
            }
        }
    }
}

void func_0026d828() {
    s32 s1 = 0;
    u32 s2 = func_00293bc0();

    while (1) {
        u32 s0 = func_001a8bf8(D_0035f0fc, (u32)s1);  // get_bits5_at
        u32 v = func_001a8bf8(s2, (u32)s1);  // get_bits5_at
        s1 = s1 + 1;
        if (s0 != v) {
            func_00257000();
            return;
        }
        if (s1 >= 4) {
            return;
        }
    }
}

u32 func_0026e340() {
    if (func_00139d78((u32)D_0035f108) != 0) {
        call_f5(D_0035f108);
    }

    if (func_00139d78((u32)D_0035f108) != 0) {
        call_f5(D_0035f108);
    }

    return func_0023d820(func_00287dc0());
}

void func_0026ed48() {
    if (D_0035f12c != 0) {
        return;
    }

    u32 p = func_00103570();
    u32 obj = func_001063c0(152, p);
    D_0035f12c = obj;
    func_002fde18(obj, 0, 152);
}

void func_00273c40(s32 a0) {
    u32 v0 = (u32)Tz::CmTop::GetSelectPos(25);
    u32 p = func_00281180(D_0035f010, v0);
    u8* b = (u8*)(*(u32*)(p + 580));

    if (a0 < 0) {
        u32 n = (u32)b[244] + 1;
        b[244] = (u8)n;
        if ((n & 0xffu) >= 6) {
            b[244] = 0;
        }
    } else {
        b[244] = (u8)a0;
    }

    *(u8*)(D_0035f12c + 3) = b[244];
}

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

void func_00275980(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    if (func_0028d008(s0, s1) == 0) {
        func_0028cc78(s0, D_0035f14c, D_0035f148, D_0035f210, 33, 33);
    }
    func_0028cf28(s0, s1);  // record408_set_and_refresh
}

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

void func_00275af8() {
    if (func_00139d78(D_0035f20c + 1308) == 0) {
        func_0028d980(D_0035f20c + 1308, 30040, D_0035f14c, D_0035f148, D_0035f210, 44, 45, -1, 0);
    }
}

void func_00275cb8() {
    if (func_00139d78(D_0035f20c + 872) != 0) {
        func_00139510(D_0035f20c + 872);
    }

    if (func_00139d78(D_0035f20c + 1308) != 0) {
        func_00139510(D_0035f20c + 1308);
    }

    func_00275e08();
}

void func_00276a18() {
    s32 s0 = 0;
    s32 s1 = 31;
    do {
        if (func_00139d78(D_0035f21c + s0 + 30360) != 0) {
            u32 p = s0 + D_0035f21c;
            u32 vt = *(u32*)(p + 30360);
            u32 fn = *(u32*)(vt + 20);
            ((void (*)(u32))fn)(p + 30360);
        }
        s1 -= 1;
        s0 += 408;
    } while (s1 >= 0);
}

void func_0027a898(u32 a0) {
    u32 s0 = a0 & 0xff;
    func_00257a00();
    if (s0 != 0) {
        func_0027b510();
    }
    if (func_0028be58(D_0035f04c) != 0) {
        func_0028be18(D_0035f04c);
    }
    if (func_0028acc8(D_0035f01c) == 0) {
        return;
    }
    func_0028abe0(D_0035f01c);
}

u32 func_0027a990() {
    u32 s0 = func_00257770();
    s32 s1 = 231;

    u32 mode = func_00287bc0();
    if (mode != 16) {
        u32 i = func_0027af58();  // check_state16_then_loop
        s1 = D_00373e30[i * 3 + 2];
    }

    if (func_00139d78(s0) == 0) {
        return 0;
    }
    return (u32)(*(u32*)(s0 + 388) == (u32)s1);
}

void func_0027b548(u32 a0) {
    u32 s0 = a0 & 0xff;
    s32 idx = Tz::CmTop::GetSelectPos(15);

    if (s0 != 0) {
        idx += 1;
        if (!(idx < (s8)*(s8*)(D_0035f230 + 6))) {
            idx = 0;
        }
    } else {
        idx -= 1;
        if (idx < 0) {
            idx = (s8)*(s8*)(D_0035f230 + 6) - 1;
        }
    }

    func_00257050(15, idx, 0);
    func_0028fb68(1, func_0027b5d0());
}

void func_0027d350(void) {
    func_002579e0();

    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028abe0(D_0035f01c);
    }

    if (func_0028be58(D_0035f04c) != 0) {
        func_0028be18(D_0035f04c);
    }
}

u32 func_0027d3b0(void) {
    u32 v0 = func_00257780();
    if (v0 == 0) {
        u32 p = D_0035f01c;
        if (p != 0) {
            v0 = func_0028acc8(p);
            v0 = (v0 != 0);
        }
        if (v0 == 0) {
            v0 = func_0028be58(D_0035f04c);
            v0 = (v0 != 0);
        }
    }
    return v0;
}

void func_0027d540(void) {
    u32 i = func_0028b040(D_0035f01c);
    s32 t = (s32)(i * 10u);
    s32 n = (s32)D_0035f234[i];
    t += n;
    u32 p = (u32)&D_00373f10 + ((u32)t << 1);
    func_00263a58(*(u16*)(p + 12), 1);
}

void func_0027d2e8(void) {
    u32 s0 = func_00257770();
    u32 t = func_00287bc0();
    if (t == 36) {
        func_0028dac8(s0, 235);
        if (func_0028be58(D_0035f04c) != 0) {
            func_0028bdb8(D_0035f04c);
        }
    }
}

void func_0027d810(u32 a0) {
    u32 v = func_0028af88(D_0035f01c);
    if (a0 == 9) {
        v &= 0xfff3ffffu;
    } else {
        v |= 0x000c0000u;
    }
    func_0028af18(D_0035f01c, v);
}

void func_0027da60(void) {
    func_0014ace8();

    u32 p = D_0035f238;
    if (p != 0) {
        u32 vt = *(u32*)p;
        u32 fn = *(u32*)(vt + 16);
        ((void (*)(u32))fn)(p);
        D_0035f238 = 0;
    }

    D_0035f23c = 0;
    D_0035f240 = 0;
}

void func_0027dab8(u32 a0) {
    func_00102448(a0, 1);
    func_0027db28();
    func_00242618(11, 1);
    while (true) {
        func_00236d60();  // clear_64_entries_24
        if (func_0027db58() != 0) {
            break;
        }
        func_0027dbd8();
        func_00102448(a0, 0);
    }
}

void func_0027d9f0(void) {
    u32 root = *(u32*)&D_00347f80;
    u32 obj = *(u32*)(root + 20);
    u32 fn = *(u32*)(*(u32*)obj + 0);
    u32 s0 = ((u32 (*)(u32, u32, u32))fn)(obj, 832, 0);
    u32 v = func_00290610(s0);
    D_0035f238 = s0;
    v = func_00103eb0();
    func_00102818(*(u32*)(v + 4), 0, 2000, (u32)func_0027dab8, 4096);
    func_0014acd8();
}

u32 func_0027ea78(void) {
    func_00139d78(D_0035f244);
    u32 v = *(u32*)(D_0035f244 + 388);
    s32 i = (s32)D_0035f24c;
    s32 off = i * 6;
    u32 p = (u32)&D_00374050 + off;
    s32 y = (s32)*(s16*)(p + 4);
    return ((v ^ (u32)y) == 0);
}

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

void func_002802e8(void) {
    if (func_00139d78(D_0035f264 + 24) != 0) {
        func_00139510(D_0035f264 + 24);
    }

    if (func_00139d78(D_0035f264 + 460) != 0) {
        func_00139510(D_0035f264 + 460);
    }

    if (func_00139d78(D_0035f264 + 896) != 0) {
        func_00139510(D_0035f264 + 896);
    }
}

u32 func_00280290(void) {
    u32 v = func_00139d78(D_0035f264 + 24);
    if (v == 0) {
        v = func_00139d78(D_0035f264 + 460);
        if (v == 0) {
            v = func_00139d78(D_0035f264 + 896);
        }
    }
    return v;
}

extern "C" void func_002800d0(void) asm("_ZN2Tz9GumiPause12UpdateAdviceEv");

u32 func_00280368(void) {
    u32 ok = 0;
    if (func_00139d78(D_0035f264 + 24) != 0) {
        ok = (*(u32*)(D_0035f264 + 412) == 8);
    }

    if (ok == 0) {
        if (func_00139d78(D_0035f264 + 460) != 0) {
            ok = (*(u32*)(D_0035f264 + 848) == 11);
        }
    }
    return ok;
}

extern "C" void func_00280458(void) asm("_ZN2Tz9GumiPause14ChkLoadRequestEv");

void func_002809d8(u32 a0) {
    func_002593b8(5, a0);
    func_00102448(a0, 1);
    func_002806c8();
    func_00280a50();
    while (true) {
        func_00236d60();  // clear_64_entries_24
        if (func_00280c38() != 0) {
            break;
        }
        func_00280d40();
        func_00102448(a0, 0);
    }
}

void func_00281058(u32 a0, s32 a1) {
    s32 i = 0;
    do {
        if ((a1 < 0) || (i == a1)) {
            if (*(u32*)(a0 + 16) != 0) {
                func_001a1460(*(u32*)(a0 + 20));
            }
        }
        i += 1;
        a0 += 20;
    } while (i < 4);
}

u32 func_00282ec0(u32 a0) {
    u32 i = 0;
    u32 found = 0;

    if (D_00374230[0].a != 0) {
        do {
            if ((u32)D_00374230[i].b == a0) {
                if (func_001a6d08((u32)D_00374230[i].a) != 0) {
                    found = 1;
                    break;
                }
            }
            i += 1;
        } while (D_00374230[i].a != 0);
    }

    return found;
}

void func_00283730(void) {
    func_0028da70(D_0035f2b8 + 852, 19);
    func_0028da70(D_0035f2b8 + 416, 16);
    func_0028da70(D_0035f2b8 + 1288, 2);
    func_0028da70(D_0035f2b8 + 1696, 5);
}

void func_00283900(u32 a0) {
    if ((a0 & 0xffu) != 0) {
        func_0028dac8(D_0035f2b8 + 416, 17);
    }
    func_0028dac8(D_0035f2b8 + 1288, 3);
    func_0028dac8(D_0035f2b8 + 1696, 6);
}

void func_00283960(u32 a0) {
    if ((a0 & 0xffu) != 0) {
        if (func_00139d78(D_0035f2b8 + 416) != 0) {
            func_00139510(D_0035f2b8 + 416);
        }
    }

    if (func_00139d78(D_0035f2b8 + 1288) != 0) {
        func_00139510(D_0035f2b8 + 1288);
    }

    if (func_00139d78(D_0035f2b8 + 1696) != 0) {
        func_00139510(D_0035f2b8 + 1696);
    }
}

u32 func_002839f0(u32 a0) {  // entry416_by_masked_index
    u32 v = 0;
    if ((a0 & 0xffu) != 0) {
        v = func_00139d78(D_0035f2b8 + 416);
    }

    if (v == 0) {
        v = func_00139d78(D_0035f2b8 + 1288);
        if (v == 0) {
            v = func_00139d78(D_0035f2b8 + 1696);
        }
    }
    return v;
}

u32 func_00283a58(void) {
    u32 out;
    if (func_00181500(2267) == 0) {
        goto L80;
    }
    if (func_00181500(2256) == 0) {
        out = 0;
        goto Lend;
    }

L80:
    if (func_00181500(2256) == 0) {
        goto Lset2;
    }
    if (func_00181500(2257) == 0) {
        out = 1;
        goto Lend;
    }
Lset2:
    out = 2;
Lend:
    return out;
}

void func_00283f50(void) {
    u8 work0[128];
    u8 work1[32];
    u8* p = (u8*)D_0035f2b4;
    p += (s32)(s8)p[14];

    func_00283eb8((u32)work1, (s32)(s8)p[4]);
    func_00253b30((u32)work0, (u32)work1);
    func_00170518((u32)work0, 5100, 0);
    func_00170888(0);
}

void func_00283fb0(void) {
    u8 work0[128];
    u8 work1[32];
    u8* p = (u8*)D_0035f2b4;

    func_00283eb8((u32)work1, (s32)(s8)p[(s32)(s8)p[14] + 4]);
    func_00253b30((u32)work0, (u32)work1);

    func_00290a10(D_0035f2b0, (u32)work0, 24);
    func_002362b0(D_0035f2b8, func_00290948(D_0035f2b0, 0));

    *(u8*)(D_0035f2b8 + 400) = 1;
}

void func_00284738(u32 a0) {
    u32 s0 = a0;

    if (func_00170cd0(s0) != 0) {
        func_00170888(s0);
    }

    func_00285418();
    func_00170888(s0);
    func_00102448(s0, 1);
    func_002853b8();
    func_002847e0();

    if (D_0035f2d0 == 0) {
        func_00284e40();
    }

    while (1) {
        func_00236d60();  // clear_64_entries_24
        if (func_00284ef0() != 0) {
            return;
        }
        func_002851e0();
        func_00102448(s0, 0);
    }
}

void func_002856c8(void) {
    func_0028dac8(D_0035f2d8, 6);

    if (func_0028acc8(D_0035f2dc) == 0) {
        return;
    }

    if (func_0028acb8(D_0035f2dc) != 0) {
        return;
    }

    func_0028aa40(D_0035f2dc);
}

void duplicate_unplaced_00288370(void) {
    u32 s2 = func_0023f948(D_0035f334, 0);
    u32 s0 = func_0023f908(D_0035f334, 0);
    u32 t = func_00103570();

    func_00236a58(D_0035f33c, s0, t);
    t = func_00103570();

    func_0023c100(D_0035f340, s2, D_0035f33c, t);
}

u32 func_00288400(u32 a0) {
    if (D_0035f32a < 0) {
        func_001039f8();
        return 1;
    }

    if (func_00287db0() != 0) {
        func_00287ad0();
    }

    D_0035f328 = 1;
    func_00288478(a0);
    D_0035f328 = 0;
    return 0;
}

void func_00288870(void) {
    if (D_0035f344 == 0) {
        return;
    }

    if (func_00139d78(D_0035f338) != 0) {
        if (func_00288820() == 0) {
            return;
        }
    }

    ((void(*)(void))D_0035f344)();
    D_0035f344 = 0;
}

void func_00288b18(u32 a0) {
    if (D_0035f34c != a0) {
        if (D_0035f34c != 0) {
            D_0035f350 = D_0035f34c;
        }
        D_0035f34c = a0;
    } else {
        D_0035f348 = (u8)(D_0035f348 + 1);
    }

    if (func_00103b38() != 0) {
        func_00287ed8(D_0035f34c);
    }
}

void func_002890e0(Obj_002890e0* self, u32 a1, s32 a2, u32 a3, s32 a4) {
    s32 i = 0;
    u32 s2 = a1 & 0xFF;
    u32 s3 = a3 & 0xFF;
    s32 s4 = a4;
    s32 s5 = a2;

    if ((s32)self->count <= 0) {
        return;
    }

    do {
        func_00289038((u32)self, i, 0, s2, s5, s3, s4);
        i += 1;
    } while (i < (s32)self->count);
}

void func_0028b8e0(Obj_0028b8e0* self) {
    func_0023fa08((u32)self);
    func_00168aa0(self->field4, 37);

    u32 p0 = func_00168b38(self->field4, 37, 0);  // entry_array_find_nth
    self->field28 = *(u32*)(p0 + 8);

    u32 p1 = func_00168b38(self->field4, 37, 1);  // entry_array_find_nth
    self->field32 = *(u32*)(p1 + 8);
}

void func_0028ba20(Obj_0028ba20* self) {
    Obj_0028ba20* s0 = self;

    if (func_0028be58((u32)s0) != 0) {
        u32 p = s0->field0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
    }

    {
        u32 p = s0->field0;
        if (p != 0) {
            ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
            s0->field0 = 0;
        }
    }
}

void func_0028ba80(Obj_0028ba80* self) {
    Obj_0028ba80* s0 = self;

    if (func_0028be58((u32)s0) != 0) {
        u32 p = s0->field0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 20)))(p);
    }

    {
        u32 p = s0->field0;
        if (p != 0) {
            ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
            s0->field0 = 0;
        }
    }
}

void func_0028bd60(Obj_0028bd60* self) {
    func_0028be58((u32)self);
    u32 v = func_0028e4c8(self->field0, 1);

    if ((s32)v != (s32)self->field26) {
        func_0028e560(self->field0, (u32)&self->field24, 4, -1);
    }
}

void func_0028c7c0(s32 a0, s32 a1) {
    s32 s0 = a1;
    s32 s1 = a0;

    if (a1 == 0xFFFF) {
        if (a0 == 1) {
            func_0023f800((u32)&D_0035f3a8);
        }
    }

    if (s0 == 0xFFFF) {
        if (s1 == 0) {
            func_0023f848((u32)&D_0035f3a8);
        }
    }
}

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

void func_002931a8(u32 a0) {
    u32 s16 = a0;
    strlen();  // strlen
    if (strcmp(D_0035f4e4, s16) != 0) {  // strcmp
        func_00292a58();
    }
    func_002ff2e8(D_0035f4e4, s16);
}

void func_002932f8(void) {
    if (D_0035f4e8 != 0) {
        func_00106450(D_0035f4e8);
        D_0035f4e8 = 0;
    }

    if (D_0035f4ec != 0) {
        func_00106450(D_0035f4ec);
        D_0035f4ec = 0;
    }

    func_002936e8();
}

void func_00293bd0(u32 a0, u32 a1, u32 a2) {
    u8 buf[128];
    u32 v = a2 & 0xff;
    if (v == 0) {
        func_00170cd0();
    }
    func_00293cb8(buf, a0, a1);
    u32 msg = 5100;
    msg = (a0 != 0) ? 5101 : msg;
    func_00292568(buf, msg, v);
}

void func_00294ea8(void) {
    if (D_0035f580 != 0) {
        if (func_0023f900(D_0035f57c) != 0) {
            func_0023fad0(D_0035f57c);
        }
    }
    func_00293d80(5101);
    D_0035f580 = 0;
}

void func_00296ab0(void) {
    if (D_0035f590 != 0) {
        if (func_0023f900(D_0035f58c) != 0) {
            func_0023fad0(D_0035f58c);
        }
    }
    func_00293d80(5101);
    D_0035f590 = 0;
}

void func_00297d78(void) {
    if (D_0035f598 != 0) {
        func_00106420(D_0035f598);
        D_0035f598 = 0;
    }
    if (D_0035f59c != 0) {
        u32 p = D_0035f59c;
        ((void (*)(u32))(*(u32*)(*(u32*)p + 4)))(p);
        D_0035f59c = 0;
    }
    D_0035f5a0 = -1;
    D_0035f5a1 = -1;
    D_0035f5a3 = 0;
    D_0035f5a2 = 0;
}

void func_00297e00(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00287bc0();
    v0 -= 4;
    if (v0 >= 2) {
        return;
    }
    func_00298f90();
    func_00274ac8();
    if ((u32)(s0 - 4) < 2) {
        return;
    }
    func_0028f7e8(0);
}

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

void func_0029a310(void) {
    if (D_0035f5a8 != 0) {
        if (func_0023f900(D_0035f5a4) != 0) {
            func_0023fad0(D_0035f5a4);
        }
    }
    func_00293d80(5101);
    D_0035f5a8 = 0;
}

void func_0029dfc0(void) {
    u32 s1 = func_002766d0();
    u32 s0 = s1 + 0x4860;

    if (func_00139d78(s0) != 0) {
        return;
    }

    func_0028d8c0(s0, 30055, D_0035f14c, D_0035f148, D_0035f210, 4, 5, 0);
    func_0028dcc0(s0, s1);
}

void func_0029e298(u32 a0) {
    u32 v0 = func_002766d0();
    a0 += 1;
    u32 s0 = v0 + a0 * 408u;
    u32 s1 = s0 + 17304u;

    if (func_00139d78(s1) == 0) {
        return;
    }

    u32 t7 = *(u32*)(s0 + 17304u);
    (*(void (**)(u32))(t7 + 20))(s1);
}

u32 func_0029e338(u32 a0) {
    a0 += 1;
    u32 s1 = 0;
    u32 v0 = func_002766d0();
    u32 s0 = v0 + a0 * 408u + 17304u;

    if (func_00139d78(s0) != 0) {
        s1 = (*(u32*)(s0 + 388u) == 8u);
    }

    return s1;
}

void func_0029e960(void) {
    if (D_0035f5c0 != 0) {
        return;
    }

    u32 v0 = func_00103b48(0, 0x0001adb0, &D_0015de58);
    D_0035f5c0 = v0;
    u32 v1 = func_00103580();

    u32 t = D_0034b278;
    D_0034b278 = v1;
    D_0034b27c = t;

    func_0015def8();
}

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

void func_002a07f0(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00287bc0();

    if (v0 == 6 || v0 == 12 || v0 == 40) {
        func_002a1c68();
        func_00274ac8();
        if (s0 != 16) {
            func_0028f7e8(0);
        }
        func_002a0860();
    }
}

void func_002a45a0(void) {
    u32* s0 = &D_0035f5e8;
    if (func_00139d78(*s0 + 29376) != 0) {
        func_00139510(*s0 + 29376);
    }

    if (func_0028d008(0) != 0) {
        func_0028cdb8(0);  // record408_alloc_init
    }

    s0 = &D_0035f218;
    if (func_0028d6e8(*s0) != 0) {
        func_0028d5d0(*s0);
    }
}

u32 func_002a7530(void) {
    u32 s0 = 0;
    if (func_002a7490() != 0) {
        goto L_set;
    }
    if (func_002a74c0() != 0) {
        goto L_set;
    }
    if (func_00276c18() == 0) {
        goto L_ret;
    }
L_set:
    s0 = 1;
L_ret:
    return s0;
}

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


u32 func_002aecf0(u32 a0);  // 0x002aecf0: definition moved into src/anon/unit_002aeba0.cpp

s32 func_002b2380(s32 a0, s32 a1) {
    u32* p = func_002b23e0(-1);  // list_entry_by_index_checked
    u32 t7 = p[0];
    t7 >>= 25;
    t7 &= 4;
    s32 t5 = D_00374cd0[t7];
    a1 = a1 * t5;
    a1 = a1 + a0;
    return a1;
}

void func_002b4388(Obj4388* a0, u8* a1, u32 a2) {
    u8* s0 = a1 + 20;
    s32 s1 = 2;
    u32 s2 = 0;

    do {
        u32 t7 = *(u16*)(s0 + 0);
        s0 += 2;
        if (t7 != 0) {
            func_0023f5b8((void*)(a0->p4 + s2), t7, a2);
        }
        s1 -= 1;
        s2 += 76;
    } while (s1 >= 0);

    u32 v = *(u16*)(a1 + 26);
    if (v != 0) {
        func_0023f5b8((void*)a0->p8, v, a2);
    }
}


u32 func_002b5978(void) {
    u32 s2 = 0;
    u32 s4 = 0;

    while (1) {
        u32 s1 = 0;
        u32 off = s2 << 2;
        void** s0 = &D_0035f690[off];

        while (1) {
            void* t7 = *s0;
            s0 = s0 + 1;

            if (t7 != 0) {
                if (func_00139d78(t7) != 0) {
                    s4 = 1;
                    break;
                }
            }

            s1 = s1 + 1;
            if ((s32)s1 < 4) {
                continue;
            }
            break;
        }

        s2 = s2 + 1;
        if ((s32)s2 < 3) {
            continue;
        }
        return s4;
    }
}


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

void func_002d2948(u8* a0) {
    u8* s0 = a0;

    func_002cfeb0((u32)a0);  // obj_init_field1416_bit800

    *(u32*)(s0 + 0) = (u32)(&D_00360000 + 0x2230);
    func_002cf280(s0 + 2800, 1, 0);

    u32 t7 = *(u32*)(s0 + 268);
    u32 t6 = *(u32*)(s0 + 264);
    t7 = t7 | 0x8000;
    *(u32*)(s0 + 2852) = 0;
    t6 = t6 | 0x1;
    *(u32*)(s0 + 268) = t7;
    *(u32*)(s0 + 264) = t6;
}

void func_002d29a8(u8* a0) {
    u8* s0 = a0;

    func_002cfeb0((u32)a0);  // obj_init_field1416_bit800

    *(u32*)(s0 + 0) = (u32)(&D_00360000 + 0x2230);
    func_002cf280(s0 + 2800, 1, 0);

    u32 t7 = *(u32*)(s0 + 268);
    u32 t6 = *(u32*)(s0 + 264);
    t7 = t7 | 0x8000;
    *(u32*)(s0 + 2852) = 0;
    t6 = t6 | 0x1;
    *(u32*)(s0 + 268) = t7;
    *(u32*)(s0 + 264) = t6;
}

void func_002d5af0(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(s0 + 3128);
    func_002cf2b0(p + 2800, 1);
    func_002d2a90(*(u32*)(s0 + 3128));
    func_00190128(s0 + 2548);
    u32 a1 = 56;
    if (*(u32*)(s0 + 3132) == 0) {
        a1 = 55;
    }
    func_0016bd60(s0, a1);
}

void func_002d5b48(u32 a0) {
    u8* s0 = (u8*)a0;
    s32 t7 = -1;
    u32 v0 = *(u32*)(s0 + 3128);
    if (v0 != 0) {
        if (*(s32*)(s0 + 3132) >= 0) {
            u32* vtbl = *(u32**)v0;
            ((void (*)(u32))vtbl[8])(v0);
            t7 = -1;
        }
    }
    *(u32*)(s0 + 3128) = 0;
    *(s32*)(s0 + 3132) = t7;
    func_0016bd60(a0, 37);
}

u32 func_002d5c40(u32 a0) {
    u32 s0 = a0;
    u32 t4;
    if (func_002d5578(a0) != 0) {  // is_field340_eq151
        t4 = 1;
    } else {
        u32 t6 = *(u32*)(*(u32*)(s0 + 12) + 4);
        t4 = 2;
        if ((t6 ^ 0x37) != 0) {
            u32 a0v = t6 ^ 0x38;
            u32 t7 = 3;
            t4 = 0;
            if (a0v == 0) {
                t4 = t7;
            }
        }
    }
    return t4;
}

void func_002d7390(u32 a0) {
    *(u32*)a0 = (u32)&D_003625a8;
    u32 s0 = *(u32*)(a0 + 160);
    if (s0 != 0) {
        func_002e70b0(s0);
        func_00106420(s0);
    }
    func_002cea28(a0);
    func_00105110(a0);
}

void func_002d7420(u32 a0) {
    u8* s1 = (u8*)a0;
    u32 s0 = 0;
    while (1) {
        u8* t7 = *(u8**)(s1 + 184);
        u32 t6 = t7[9];
        if (s0 == t6) {
            func_0015ee90(s0);
            func_00160f10(s0);
        } else {
            func_0015ee10(s0);
        }
        s0 += 1;
        if (!(s0 < 16)) {
            u8* t7f = *(u8**)(s1 + 184);
            u8* t6p = t7f + 12;
            u8 t5 = t6p[4];
            u8 t7v = t6p[5];
            f32 f12 = (f32)*(s32*)(t6p + 8);
            f32 f13 = (f32)*(s32*)(t6p + 12);
            f32 f14 = (f32)t5;
            f32 f15 = (f32)t7v;
            func_0015ca40(
                t6p[0],
                t6p[1],
                t6p[2],
                f12,
                f13,
                f14,
                f15);
            return;
        }
    }
}

void func_002d7630(u32 a0) {
    *(u32*)(a0 + 468) = 0;
    *(u32*)(a0 + 472) = 0;
    *(u8*)(a0 + 144) = 0;
    u32 t5 = a0;
    s32 t4 = 2;
    do {
        *(u32*)(t5 + 108) = 0;
        t4 -= 1;
        *(u32*)(t5 + 120) = 0;
        *(u32*)(t5 + 132) = 0;
        t5 += 4;
    } while (t4 >= 0);
    u32 a1 = *(u32*)(a0 + 104);
    *(u8*)(a0 + 192) = 0;
    *(u8*)(a0 + 193) = 0;
    *(u8*)(a0 + 201) = 0;
    func_002d74c8(a0, a1 & 0xfff, 0);
}

void func_002da8f0(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t7 = *(u32*)(a0 + 3060);
    if (t7 != 0) {
        func_002db610(t7);
    }
    t7 = *(u32*)(s0 + 3056);
    if (t7 != 0) {
        func_002dc1b8(t7, s1);
    }
}

void func_002dd968(u32 a0) {
    u32 scratch[8];
    func_00190128(scratch);
    func_00190878(scratch, a0, 0);
    func_001bd3e0(*(u32*)(a0 + 0xb44), 1, 565, scratch, 1, 100);
}

void func_002de888(u32 a0) {
    func_00187750(a0);
    if (func_001c0cd8(a0) != 0) {
        return;
    }
    u32 v = D_0034e948;
    if (v == 0) {
        return;
    }
    func_001c0d38(a0, v, 67, 0);
}

void func_002def70(u32 a0, u32 a1) {
    u32 a = a1 + 320;
    f32 z = 0.0f;

    u32 v = call_vt_48(a0);
    ((u32(*)(u32, u32, f32, f32))func_0017f488)(a, v, z, z);

    v = call_vt_40(a0);
    ((u32(*)(u32, u32, u32, f32, f32))func_0017f5e0)(a, v, 0, z, z);
}

void func_002df758(u32 a0, u32 a1) {
    u32 p = D_00361f60;
    u32 s = func_002dc7c8(p);
    u32 t = func_002dc7c8(p);

    func_002deac0(a0, *(f32*)(s + 244), *(f32*)(t + 248));  // set_float24_scaled
    func_002deb18(a0, a1);
    *(u32*)(a0 + 52) = 0xffffffffu;
}

void func_002e0f20(u32 a0) {
    *(u32*)a0 = (u32)&D_00362dc8;
    u32 p = *(u32*)(a0 + 112);
    if (p != 0) {
        func_002e70b0(p);
        func_00106420(p);
    }
    func_002cea28(a0);
    func_00105110(a0);
}

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

void func_002edb38(void) {
    if (D_003637d0 != 0) {
        return;
    }

    u32 p = func_001050d8(4);
    func_002eda10(p);
    u32 q = func_00102c18(1, 20500, (u32)&D_002edb90);
    *(u32*)(q + 48) = (u32)&D_002edbb0;
}

void func_002edfd8(u32 a0, u32 a1) {  // list_unlink_and_clear
    u32 t7 = *(u32*)(a0 + 8);
    u32 t5;
    u32 t4 = a0 + 8;

    if (a1 == t7) {
        t7 = *(u32*)(a1 + 32);
        t5 = 0;
        *(u32*)(a0 + 8) = t7;
    } else {
        u32 t6 = *(u32*)(t7 + 32);
        t5 = t7;
        while (t6 != a1) {
            t7 = *(u32*)(t6 + 32);
            t5 = t6;
            t6 = t7;
        }
        t7 = *(u32*)(a1 + 32);
        *(u32*)(t5 + 32) = t7;
    }

    t7 = *(u32*)(t4 + 4);
    if (a1 == t7) {
        *(u32*)(t4 + 4) = t5;
    }
    *(u32*)(a1 + 32) = 0;
    *(u32*)(a1 + 28) = 0;
}

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
u32 func_002677f0(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;

    u16* p = func_002570e0(s0);
    func_0028fb28(0, p[9]);
    func_00257050(0, 0, 0);

    if (s0 == 1) {
        return func_0025f7f0(s1);
    }

    if (func_00257070(1) != s1) {
        func_00257050(2, 0, 0);
        func_00257050(1, s1, 0);
    }

    u32 v = func_00281140(D_0035f010, s1);
    func_0028fb68(1, v);
    return func_002678a8();
}
