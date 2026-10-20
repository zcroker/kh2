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

void func_00234f60(void) {
    switch (D_0035e374) {
    case 0: {
        s32 i;
        for (i = 0; i < 2; i++) {
            D_01dae580[i] = 1;
            D_01dae588[i] = func_002fbc78(i);
        }
        func_002fc498(D_01dae478, D_01dae47c, &D_01dae480[D_01dae478][D_01dae47c].state,
                      &D_01dae480[D_01dae478][D_01dae47c].c, &D_01dae480[D_01dae478][D_01dae47c].b);
        D_0035e374++;
        break;
    }
    case 1:
        if (func_002fc378(1, 0, &D_01dae470)) {
            D_0035e374++;
        }
        break;
    case 2:
        if (D_01dae470 < -2 && D_01dae400 != 0) {
            D_01dae400--;
            D_01dae404 = 1;
            D_0035e374 = 3;
        } else {
            W1697Slot* p = &D_01dae480[D_01dae478][D_01dae47c];
            if (p->state == 3) {
                p->mode = 3;
            } else {
                switch (D_01dae470) {
                case -1:
                    p->mode = 1;
                    D_01dae438 = 0;
                    p->flag10 = 1;
                    p->flag14 = 1;
                    break;
                case -2:
                    p->mode = 2;
                    D_01dae438 = 0;
                    p->flag10 = 1;
                    p->flag14 = 1;
                    break;
                case 0:
                    p->mode = 0;
                    D_01dae438 = 0;
                    break;
                default: {
                    W1697Slot* q = &D_01dae480[D_01dae478][D_01dae47c];
                    q->mode = 3;
                    if (D_01dae438 == 0) {
                        q->flag10 = 1;
                        q->flag18 = 1;
                    }
                    D_01dae438 = 1;
                    break;
                }
                }
            }
            func_002349e8();
        }
        break;
    case 3:
        if (D_01dae404 != 0) {
            D_01dae404--;
        } else {
            D_0035e374 = 0;
        }
        break;
    }
}

}
