// Linked unit 0x0026c140-0x0026c450 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_equip.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/cmenu_party.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tz/ui_accessors.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_custom.hpp"

// 0026c140 (was src/anon/batch_w1611.cpp)
namespace n0026c140 {
struct O26c;
struct V26c { void* f[6]; void (*draw)(O26c*, s32, s32, s32, s32, s32, s32); };
struct O26c { V26c* vt; };
extern u8* D_0035f0f4 asm("D_0035f0f4");
extern s32 D_0035f010 asm("D_0035f010");
extern u8 D_0035f0f0 asm("D_0035f0f0");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f03c asm("D_0035f03c");
O26c* func_00287dc0(void) asm("func_00287dc0");
s32 func_00139d78(O26c*) asm("func_00139d78");
void func_0023d808(O26c*, s32) asm("func_0023d808");
void func_0023ebd0(O26c*, s32) asm("func_0023ebd0");
s32 func_00281128(s32, s32) asm("func_00281128");
void func_00138c78(void*, s32*, s32*) asm("func_00138c78");
void func_0023dd28(O26c*, s32, s32, s32) asm("func_0023dd28");
void func_0023e738(O26c*, s32, s32, s32) asm("func_0023e738");
void func_0023e9c8(O26c*, s32, void*) asm("func_0023e9c8");
s32 func_0026d8c0(s32) asm("func_0026d8c0");
s32 func_00281538(s32, s32) asm("func_00281538");
s32 func_0023ec18(O26c*, s32) asm("func_0023ec18");
s32 func_002811e0(s32, s32) asm("func_002811e0");
s32 func_00281238(s32, s32) asm("func_00281238");
void func_0023e858(f32, O26c*, s32) asm("func_0023e858");
void func_0023e8b8(f32, O26c*, s32) asm("func_0023e8b8");
void func_0023e8d8(f32, O26c*, s32) asm("func_0023e8d8");
s32 func_002811b0(s32, s32) asm("func_002811b0");
void func_0023eae0(O26c*, s32, s32, s32) asm("func_0023eae0");
void func_0023eac0(O26c*, s32, s32) asm("func_0023eac0");
void func_0023e958(O26c*, s32, s32, s32, s32, s32) asm("func_0023e958");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0023e9e0(O26c*, s32, void*) asm("func_0023e9e0");
/*TARGET 0026c140*/
void func_0026c140(void) asm("func_0026c140");
void func_0026c140(void) {
    s32 x, y;
    s32 i;
    u8 flag = 0;
    O26c* o = func_00287dc0();
    if (!func_00139d78(o)) {
        func_0023d808(o, 0x7545);
        func_0023ebd0(o, 1);
        y = 0;
        x = 0;
        for (i = 0; i < 4; i++) {
            if (func_00281128(D_0035f010, i)) {
                func_00138c78(D_0035f0f4 + i * 0x1b4 + 0x7f8, &x, &y);
                func_0023dd28(o, i, 0, 0x8a);
                func_0023e738(o, i, (s16)x, (s16)(y - 0x8a));
                func_0023e9c8(o, i, D_0035f0f4 + i * 0x1b4 + 0x7f8);
            }
        }
    }
    y = 0;
    x = 0;
    for (i = 0; i < 4; i++) {
        s32 c = 16;
        s32 id = func_0026d8c0(i);
        if (!func_00281128(D_0035f010, id)) continue;
        if (!func_00281538(D_0035f010, id) || func_0023ec18(o, id)) {
            if (!func_00281538(D_0035f010, id)) flag = 1;
            continue;
        }
        if (i != 0 && func_002811e0(D_0035f010, id) == 3) c = 15;
        o->vt->draw(o, id, func_00281238(D_0035f010, id) | 0x20000000, 0x8b, 2, 0, 0x8a);
        func_0023e858(-100.0f, o, id);
        func_0023e8b8(0.0f, o, id);
        func_0023e8d8(0.0f, o, id);
        if (func_002811b0(D_0035f010, id) == 8) func_0023eae0(o, id, 20, 32);
        func_0023eac0(o, id, c);
        func_0023e958(o, id, 96, 96, 96, -1);
        if (D_0035f0f0) {
            func_0028d8c0(D_0035f0f4 + id * 0x198 + 0x198, c, D_0035ef68, D_0035ef64, D_0035f03c, 125, -1, 0);
            func_0023e9e0(o, id, D_0035f0f4 + id * 0x198 + 0x198);
        }
    }
    D_0035f0f0 = flag;
}
}  // namespace n0026c140

// .rodata 0x373814-0x373878
extern const u32 R_00373814[5] asm("D_00373814") __attribute__((aligned(4))) = { 0x2, 0x4, 0x80000000, 0xa, 0x0 };
extern const u32 R_00373828[1] asm("D_00373828") __attribute__((aligned(4))) = { 0x202020 };
extern const u32 R_0037382c[1] asm("D_0037382c") __attribute__((aligned(4))) = { 0x13e };
extern const u32 R_00373830[1] asm("D_00373830") __attribute__((aligned(4))) = { 0x13f };
extern const u32 R_00373834[1] asm("D_00373834") __attribute__((aligned(4))) = { 0x846b };
extern const u32 R_00373838[1] asm("D_00373838") __attribute__((aligned(4))) = { 0xbb88 };
extern const u32 R_0037383c[1] asm("D_0037383c") __attribute__((aligned(4))) = { 0x846e };
extern const u32 R_00373840[2] asm("D_00373840") __attribute__((aligned(4))) = { 0x846f, 0x0 };
extern const u32 R_00373848[4] asm("D_00373848") __attribute__((aligned(4))) = { 0x10000, 0x7b007b, 0x7b, 0x0 };
extern const u32 R_00373858[8] asm("D_00373858") __attribute__((aligned(4))) = { 0x0, 0x0, 0x84730000, 0x84758474, 0x84778476, 0x84798478, 0x847b847a, 0x847c0000 };

