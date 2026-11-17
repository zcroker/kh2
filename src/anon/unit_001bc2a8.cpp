#include "../common/types.h"
#include "../yasui/libys/commandmenu.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"

// ---- 001bc2a8 from src/anon/batch_w3768_aj1.cpp
namespace n001bc2a8 {
struct BtlStatus {
    u8 pad0[0x180];
    s32 level;                      
};
struct BtlObj {
    u8 pad0[0x48c];
    BtlStatus* status;              
    u8 pad490[0x588 - 0x490];
    u32 flags;                                           
    u8 pad58c[0xaf0 - 0x58c];
    s32 faf0;                       
    u8 padaf4[0xb44 - 0xaf4];
    s32 fb44;                       
    u8 padb48[0xb50 - 0xb48];
    s32 fb50;                       
};
struct BtlCmd {
    u16 f0;
    u16 id;                        
    s16 arg;                       
    u8 pad6[0x1c - 6];
    u8 level;                      
    u8 pad1d[0x2e - 0x1d];
    u8 f2e;                        
};
extern u8 D_00351ec0 asm("D_00351ec0");
s32 func_001a1de0(BtlStatus*) asm("func_001a1de0");
s32 func_001a6598(s16) asm("func_001a6598");
s32 func_001b58a8(void) asm("func_001b58a8");
s32 func_001b5b20(BtlObj*, BtlCmd*, s32) asm("func_001b5b20");
s32 func_001b8ff8(BtlCmd*, BtlObj*) asm("func_001b8ff8");
s32 func_001b91d0(BtlCmd*, s32) asm("func_001b91d0");
s32 func_001bb4a0(void) asm("func_001bb4a0");
s32 func_001bbec0(void) asm("func_001bbec0");
s32 func_001bc050(void) asm("func_001bc050");
s32 func_001bc568(BtlCmd*, BtlObj*) asm("func_001bc568");
s32 func_001bf140(s32, u8) asm("func_001bf140");
s32 func_001c8ab0(void) asm("func_001c8ab0");
s32 func_001c8db8(void*, s32) asm("func_001c8db8");
s32 func_001c9c00(void) asm("func_001c9c00");
s32 func_001bc2a8(BtlCmd* cmd, BtlObj* obj) asm("func_001bc2a8");
s32 func_001bc2a8(BtlCmd* cmd, BtlObj* obj) {
    s32 r = 0;
    BtlObj* pl = 0;
    if (obj != 0) pl = (obj->flags & 0x80) ? obj : 0;
    u16 id = cmd->id;
    switch (id) {
    case 0:
        r = 5;
        break;
    case 1:
        if (pl == 0) {
            r = 5;
        } else if (pl->faf0 == 0) {
            r = 5;
        }
        break;
    case 2:
        if (pl != 0) {
            if (func_001a1de0(pl->status)) {
                r = 5;
            } else if (pl->status->level < cmd->level) {
                r = func_001a6598(cmd->arg) ? 2 : 5;
            }
            if (func_001bbec0()) r = 5;
        }
        break;
    case 5:
        r = func_001c9c00() ? 0 : 5;
    case 0x37:
    case 0x7f:
        if (func_001c8db8(&D_00351ec0, 0)) r = 5;
        break;
    case 0x48:
        r = func_001bc050() ? 5 : 0;
    case 4:
        if (!func_001bc568(cmd, pl)) r = 5;
        break;
    case 0x67:
    case 0x68:
        r = 5;
        break;
    case 0x1c4:
        if (func_001a1de0(pl->status)) {
            r = 5;
        } else if (pl->status->level < cmd->level) {
            r = 2;
        }
        break;
    case 0x14a:
        r = func_001bb4a0() ? 5 : 0;
        break;
    case 0x13c:
        if (func_001c8ab0() != 2) {
            r = 5;
        } else if (func_001b58a8()) {
            r = 5;
        }
        break;
    case 0x51:
    case 0x2c3:
        r = func_001b5b20(pl, cmd, 0);
        break;
    }
    if (func_001b8ff8(cmd, obj) || (pl != 0 && func_001b91d0(cmd, pl->fb50)) || func_001bf140(pl->fb44, cmd->f2e)) r = 5;
    return r;
}
}  // namespace n001bc2a8

