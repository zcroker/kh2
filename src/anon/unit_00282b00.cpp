// Linked unit 0x00282b00-0x00282c68 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/gumi_pause.hpp"
#include "../tozawa/cmenu_config.hpp"
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
#include <stdarg.h>
#include "../tz/ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/chg_member.hpp"

// 00282b00 (was src/anon/batch_w3781_mam.cpp)
namespace n00282b00 {
struct Ent282b00 { u16 id; u8 a; u8 b; u16 c; };
struct Row282b00 { char name[8]; u8 flag; u8 pad[7]; char buf[64]; };
struct Obj282b00 { s32 n; Ent282b00 e[256]; Row282b00 rows[32]; u8 pad[12]; s32 cnt[5]; };
extern s16 D_00374240[] asm("D_00374240");
void func_00259570(s32, char*, s32, s32) asm("func_00259570");
s32 func_002595e0(void) asm("func_002595e0");
void func_002595e8(char*, u32) asm("func_002595e8");
u32 func_00192048(u32) asm("func_00192048");
u32 func_00259618(u16, char*, s32) asm("func_00259618");
void func_00192b30(u32) asm("func_00192b30");
/*TARGET 00282b00*/
void func_00282b00(Obj282b00* obj) asm("func_00282b00");
void func_00282b00(Obj282b00* obj)
{
    s32 base = 0;
    for (s32 k = 0; k < 5; k++) {
        if (k == 1) continue;
        s32 n = obj->cnt[k];
        if (k == 0) n += obj->cnt[1];
        for (s32 j = 0; j < n; j++) {
            s32 i = base + j;
            if (obj->e[i].id == 0) {
                func_00259570(D_00374240[k], obj->rows[i].buf, 0, 1);
                char* p = obj->rows[i].buf + func_002595e0();
                func_002595e8(p, func_00192048(0x8448));
            } else {
                func_00192b30(func_00259618(obj->e[i].id, obj->rows[i].buf, obj->e[i].b != 0));
            }
        }
        base += n;
    }
}
}  // namespace n00282b00

