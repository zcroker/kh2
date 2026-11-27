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
s32 YS__SHEET__is_mpdrive(BtlStatus*);
s32 func_001a6598(s16);
s32 func_001b58a8(void);
s32 YS__LIMIT__GetCommandStatus(BtlObj*, BtlCmd*, s32);
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

s32 YS__COMMAND_SLOT__GetStatus(BtlCmd* cmd, BtlObj* obj);  // 0x001bc2a8: definition moved into src/anon/unit_001bc2a8.cpp
}
