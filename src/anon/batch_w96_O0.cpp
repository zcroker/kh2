#include "../common/types.h"

extern "C" {
struct Slot64_w96 { s32 state; s32 owner; u8 pad[56]; };
extern Slot64_w96 D_01e22080[];
extern Slot64_w96 D_01e22084[];
void func_003058a0(u32);

// Counts slots (owner read via the +4 view of the table, as the original addresses it) in state 15 (optionally only those owned by who).
s32 func_002b7148(s32 who) {
    s32 i;
    s32 n = 0;
    func_003058a0(0);
    if (who < 0) {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].state == 15) n++;
        }
    } else {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].state == 15 && D_01e22084[i].state == who) n++;
        }
    }
    return n;
}

}
