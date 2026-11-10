#pragma once

#include "../common/types.h"

// One gumi battle record (64 bytes). 54 of them: 9 worlds x 3 missions, twice.
struct GB_REC {
    u8 pad0[24];
    u8 a;           // 0x18 world index
    u8 b;           // 0x19 mission 1..3
    u8 pad1a[6];
    f32 rate;       // 0x20 treasure rate (0..100)
    u8 pad24[28];
};

extern "C" {
void func_001e08c8(u8* p);
void func_001e0958(GB_REC* p);
}

namespace ryj {

    class SAVERAM_GUMIBATTLE {
    public:
     SAVERAM_GUMIBATTLE();
     void new_game(void);
     GB_REC* get_record(s32 a0, s32 a1, bool a2);
     f32 get_all_treasure_complete(void);
     bool is_treasure_complete(void);
    };

}  // namespace ryj

