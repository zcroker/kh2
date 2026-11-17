#include "../common/types.h"

/* 00234f60: small state machine (D_0035e374 = step) that sets up a 2-entry table,
   waits on func_002fc378, then updates the current slot of a [N][4] slot grid
   from the result code in D_01dae470. */
struct W1697Slot {
    s32 state;   /* 0x00 */
    s32 b;       /* 0x04 */
    s32 c;       /* 0x08 */
    s32 mode;    /* 0x0c */
    s32 flag10;  /* 0x10 */
    s32 flag14;  /* 0x14 */
    s32 flag18;  /* 0x18 */
    s32 pad1c;   /* 0x1c */
};
extern "C" {
extern s32 D_0035e374;
extern s32 D_01dae400;
extern s32 D_01dae404;
extern s32 D_01dae438;
extern s32 D_01dae470;
extern s32 D_01dae478;
extern s32 D_01dae47c;
extern W1697Slot D_01dae480[][4];
extern s32 D_01dae580[2];
extern s32 D_01dae588[2];
void func_002349e8(void);
s32 func_002fbc78(s32);
s32 func_002fc378(s32, s32, s32*);
void func_002fc498(s32, s32, s32*, s32*, s32*);

void func_00234f60(void);  // 0x00234f60: definition moved into src/anon/unit_00234f60.cpp

}
