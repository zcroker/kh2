#include "../common/types.h"

struct BtlStatus {
    u8 pad0[0x180];
    s32 level;              // 0x180
};
struct BtlObj {
    u8 pad0[0x48c];
    BtlStatus* status;      // 0x48c
    u8 pad490[0x588 - 0x490];
    u32 flags;              // 0x588 (0x80 = player-side)
    u8 pad58c[0xaf0 - 0x58c];
    s32 faf0;               // 0xaf0
    u8 padaf4[0xb44 - 0xaf4];
    s32 fb44;               // 0xb44
    u8 padb48[0xb50 - 0xb48];
    s32 fb50;               // 0xb50
};
struct BtlCmd {
    u16 f0;
    u16 id;                 // 0x02
    s16 arg;                // 0x04
    u8 pad6[0x1c - 6];
    u8 level;               // 0x1c
    u8 pad1d[0x2e - 0x1d];
    u8 f2e;                 // 0x2e
};

extern "C" {
extern u8 D_00351ec0;
s32 func_001a1de0(BtlStatus*);
s32 func_001a6598(s16);
s32 func_001b58a8(void);
s32 func_001b5b20(BtlObj*, BtlCmd*, s32);
s32 func_001b8ff8(BtlCmd*, BtlObj*);
s32 func_001b91d0(BtlCmd*, s32);
s32 func_001bb4a0(void);
s32 func_001bbec0(void);
s32 func_001bc050(void);
s32 func_001bc568(BtlCmd*, BtlObj*);
s32 func_001bf140(s32, u8);
s32 func_001c8ab0(void);
s32 func_001c8db8(void*, s32);
s32 func_001c9c00(void);

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
}
