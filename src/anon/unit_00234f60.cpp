// Linked unit 0x00234f60-0x00236180: memory card request steps (one state machine per request type; gap functions written here).
#include "../common/types.h"

// 00234f60 (was src/anon/batch_w1697.cpp)
namespace n00234f60 {
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
extern s32 D_0035e374 asm("D_0035e374");
extern s32 D_01dae400 asm("D_01dae400");
extern s32 D_01dae404 asm("D_01dae404");
extern s32 D_01dae438 asm("D_01dae438");
extern s32 D_01dae470 asm("D_01dae470");
extern s32 D_01dae478 asm("D_01dae478");
extern s32 D_01dae47c asm("D_01dae47c");
extern W1697Slot D_01dae480[][4] asm("D_01dae480");
extern s32 D_01dae580[2] asm("D_01dae580");
extern s32 D_01dae588[2] asm("D_01dae588");
void func_002349e8(void) asm("func_002349e8");
s32 func_002fbc78(s32) asm("func_002fbc78");
s32 func_002fc378(s32, s32, s32*) asm("func_002fc378");
void func_002fc498(s32, s32, s32*, s32*, s32*) asm("func_002fc498");
/*TARGET 00234f60*/
void func_00234f60(void) asm("func_00234f60");
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
}  // namespace n00234f60

// 002351f8 (was gap)
namespace n002351f8 {
struct McSlotS { s32 state, b, c, mode, f10, f14, f18, f1c; };
extern s32 D_0035e36c asm("D_0035e36c");
extern s32 D_0035e374 asm("D_0035e374");
extern s32 D_01dae400 asm("D_01dae400");
extern s32 D_01dae404 asm("D_01dae404");
extern s32 D_01dae408 asm("D_01dae408");
extern s32 D_01dae40c asm("D_01dae40c");
extern s32 D_01dae410 asm("D_01dae410");
extern s32 D_01dae414 asm("D_01dae414");
extern s32 D_01dae418 asm("D_01dae418");
extern s32 D_01dae41c asm("D_01dae41c");
extern s32 D_01dae43c asm("D_01dae43c");
extern s32 D_01dae440 asm("D_01dae440");
extern s32 D_01dae444 asm("D_01dae444");
extern s32 D_01dae448 asm("D_01dae448");
extern s32 D_01dae44c asm("D_01dae44c");
extern s32 D_01dae450 asm("D_01dae450");
extern s32 D_01dae454 asm("D_01dae454");
extern s32 D_01dae458 asm("D_01dae458");
extern s32 D_01dae45c asm("D_01dae45c");
extern s32 D_01dae460 asm("D_01dae460");
extern s32 D_01dae464 asm("D_01dae464");
extern s32 D_01dae46c asm("D_01dae46c");
extern s32 D_01dae470 asm("D_01dae470");
extern s32 D_01dae474 asm("D_01dae474");
extern s32 D_01dae478 asm("D_01dae478");
extern s32 D_01dae47c asm("D_01dae47c");
extern McSlotS D_01dae480[][4] asm("D_01dae480");
void func_002349e8(void) asm("func_002349e8");
s32 func_002fc378(s32, s32, s32*) asm("func_002fc378");
void func_002fc688(s32, s32, s32, s32, s32, s32) asm("func_002fc688");
void func_002fc9a8(s32, s32) asm("func_002fc9a8");
void func_002fcf80(s32, s32) asm("func_002fcf80");
void func_002fc868(s32, s32, s32, s32) asm("func_002fc868");
void func_002fbe60(s32, s32, s32) asm("func_002fbe60");
void func_002fca78(s32, s32, s32) asm("func_002fca78");
void func_002fce28(s32, s32, s32, s32) asm("func_002fce28");
struct McResults { void* p; s32 a[12]; };
extern McResults D_01dae438 asm("D_01dae438");
void func_002fbd38(s32, s32, s32, s32) asm("func_002fbd38");
void func_002fc200(s32, s32, s32) asm("func_002fc200");
void func_002fbe98(s32) asm("func_002fbe98");
void func_002fc0e8(s32, s32, s32) asm("func_002fc0e8");
void func_002351f8(void) asm("func_002351f8");
void func_002351f8(void) {
    switch (D_0035e374) {
    case 0:
        func_002fc688(D_01dae478, D_01dae47c, D_01dae408, 0, D_01dae418, D_01dae46c);
        D_0035e374++;
        break;
    case 1:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        if (D_01dae470 >= 0) {
            D_01dae43c = 0;
            D_01dae480[D_01dae478][D_01dae47c].f1c = D_01dae470;
        } else if (D_01dae470 == -2) {
            D_01dae43c = 3;
            D_01dae480[D_01dae478][D_01dae47c].f1c = -1;
        } else if (D_01dae470 == -4) {
            D_01dae43c = 1;
            D_01dae480[D_01dae478][D_01dae47c].f1c = -1;
        } else {
            D_01dae43c = 2;
            D_01dae480[D_01dae478][D_01dae47c].f1c = -1;
        }
        func_002349e8();
        break;
    }
}
void func_00235398(void) asm("func_00235398");
void func_00235398(void) {
    switch (D_0035e374) {
    case 0:
        func_002fc688(D_01dae478, D_01dae47c, D_01dae408, 0, D_01dae418, D_01dae46c);
        D_0035e374++;
        break;
    case 1:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        if (D_01dae470 >= 0) {
            D_01dae440 = 0;
            D_01dae480[D_01dae478][D_01dae47c].f1c = D_01dae470;
        } else if (D_01dae470 == -2) {
            D_01dae440 = 4;
            D_01dae480[D_01dae478][D_01dae47c].f1c = -1;
        } else if (D_01dae470 == -4) {
            D_01dae440 = 2;
            D_01dae480[D_01dae478][D_01dae47c].f1c = -1;
        } else {
            D_01dae440 = 3;
            D_01dae480[D_01dae478][D_01dae47c].f1c = -1;
        }
        func_002349e8();
        break;
    }
}
void func_00235528(void) asm("func_00235528");
void func_00235528(void) {
    switch (D_0035e374) {
    case 0:
        func_002fc9a8(D_01dae478, D_01dae47c);
        D_0035e374++;
        break;
    case 1:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        if (D_01dae470 != 0) {
            if (D_01dae400 != 0) {
                D_01dae400--;
                D_01dae404 = 60;
                D_0035e374 = 3;
            } else {
                D_01dae444 = 1;
                func_002349e8();
            }
        } else {
            D_01dae444 = 0;
            func_002349e8();
        }
        break;
    case 3:
        if (D_01dae404 != 0) D_01dae404--;
        else D_0035e374 = 0;
        break;
    }
}
void func_00235638(void) asm("func_00235638");
void func_00235638(void) {
    switch (D_0035e374) {
    case 0:
        func_002fcf80(D_01dae478, D_01dae47c);
        D_0035e374++;
        break;
    case 1:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        if (D_01dae470 != 0) {
            if (D_01dae400 != 0) {
                D_01dae400--;
                D_01dae404 = 60;
                D_0035e374 = 3;
            } else {
                D_01dae448 = 1;
                func_002349e8();
            }
        } else {
            D_01dae448 = 0;
            func_002349e8();
        }
        break;
    case 3:
        if (D_01dae404 != 0) D_01dae404--;
        else D_0035e374 = 0;
        break;
    }
}
void func_00235748(void) asm("func_00235748");
void func_00235748(void) {
    switch (D_0035e374) {
    case 0:
        func_002fc868(D_01dae478, D_01dae47c, D_01dae408, 0);
        D_0035e374++;
        break;
    case 1:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        switch (D_01dae470) {
        case 0: D_01dae44c = 0; break;
        case -2: D_01dae44c = 4; break;
        case -4: D_01dae44c = 1; break;
        case -6: D_01dae44c = 3; break;
        default: D_01dae44c = 2; break;
        }
        func_002349e8();
        break;
    }
}
void func_00235850(void) asm("func_00235850");
void func_00235850(void) {
    switch (D_0035e374) {
    case 0:
        func_002fbe60(D_01dae478, D_01dae47c, D_01dae408);
        D_0035e374++;
        break;
    case 1:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        switch (D_01dae470) {
        case 0: D_01dae450 = 0; break;
        case -2: D_01dae450 = 4; break;
        case -3: D_01dae450 = 1; break;
        case -4: D_01dae450 = 2; break;
        default: D_01dae450 = 3; break;
        }
        func_002349e8();
        break;
    }
}
void func_00235958(void) asm("func_00235958");
void func_00235958(void) {
    switch (D_0035e374) {
    case 0:
        func_002fbd38(D_01dae478, D_01dae47c, D_01dae408, 515);
        D_0035e374++;
        break;
    case 1:
    case 4:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        if (D_01dae470 >= 0) {
            D_01dae474 = D_01dae470;
            D_0035e374++;
        } else {
            if (D_01dae470 == -2) D_01dae454 = 6;
            else if (D_01dae470 == -3) D_01dae454 = 1;
            else if (D_01dae470 == -4) D_01dae454 = 2;
            else if (D_01dae470 == -5) D_01dae454 = 3;
            else if (D_01dae470 == -7) D_01dae454 = 7;
            else D_01dae454 = 5;
            func_002349e8();
        }
        break;
    case 3:
        func_002fc200(D_01dae474, D_01dae410, D_01dae414);
        D_0035e374++;
        break;
    case 5:
        if (D_01dae470 >= 0) {
            if (D_01dae470 == D_01dae414) D_01dae454 = 0;
            else D_01dae454 = 4;
        } else {
            if (D_01dae470 == -2) D_01dae454 = 6;
            else if (D_01dae470 == -3) D_01dae454 = 1;
            else if (D_01dae470 == -4) D_01dae454 = 7;
            else if (D_01dae470 == -5) D_01dae454 = 3;
            else if (D_01dae470 == -8) D_01dae454 = 4;
            else D_01dae454 = 5;
        }
        D_0035e374++;
        break;
    case 6:
        func_002fbe98(D_01dae474);
        D_0035e374++;
        break;
    case 7:
        if (func_002fc378(1, 0, &D_01dae470)) func_002349e8();
        break;
    }
}
void func_00235b40(void) asm("func_00235b40");
void func_00235b40(void) {
    switch (D_0035e374) {
    case 0:
        func_002fca78(D_01dae478, D_01dae47c, D_01dae408);
        D_0035e374++;
        break;
    case 1:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        switch (D_01dae470) {
        case 0: D_01dae458 = 0; break;
        case -2: D_01dae458 = 4; break;
        case -4: D_01dae458 = 1; break;
        case -5: D_01dae458 = 5; break;
        case -6: D_01dae458 = 2; break;
        default: D_01dae458 = 3; break;
        }
        func_002349e8();
        break;
    }
}
void func_00235c50(void) asm("func_00235c50");
void func_00235c50(void) {
    switch (D_0035e374) {
    case 0:
        func_002fbd38(D_01dae478, D_01dae47c, D_01dae408, 1);
        D_0035e374++;
        break;
    case 1:
    case 4:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        if (D_01dae470 >= 0) {
            D_01dae474 = D_01dae470;
            D_0035e374++;
        } else {
            if (D_01dae470 == -2) D_01dae45c = 5;
            else if (D_01dae470 == -3) D_01dae45c = 6;
            else if (D_01dae470 == -4) D_01dae45c = 1;
            else if (D_01dae470 == -5) D_01dae45c = 2;
            else if (D_01dae470 == -7) D_01dae45c = 7;
            else D_01dae45c = 4;
            func_002349e8();
        }
        break;
    case 3:
        func_002fc0e8(D_01dae474, D_01dae410, D_01dae414);
        D_0035e374++;
        break;
    case 5:
        if (D_01dae470 >= 0) {
            if (D_01dae470 == D_01dae414) D_01dae45c = 0;
            else D_01dae45c = 3;
        } else {
            if (D_01dae470 == -2) D_01dae45c = 5;
            else if (D_01dae470 == -3) D_01dae45c = 3;
            else if (D_01dae470 == -4) D_01dae45c = 7;
            else if (D_01dae470 == -5) D_01dae45c = 2;
            else D_01dae45c = 4;
        }
        D_0035e374++;
        break;
    case 6:
        func_002fbe98(D_01dae474);
        D_0035e374++;
        break;
    case 7:
        if (func_002fc378(1, 0, &D_01dae470)) func_002349e8();
        break;
    }
}
void func_00235e28(void) asm("func_00235e28");
void func_00235e28(void) {
    switch (D_0035e374) {
    case 0:
        func_002fbd38(D_01dae478, D_01dae47c, D_01dae408, 2);
        D_0035e374++;
        break;
    case 1:
    case 4:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        if (D_01dae470 >= 0) {
            D_01dae474 = D_01dae470;
            D_0035e374++;
        } else {
            if (D_01dae470 == -2) D_01dae460 = 7;
            else if (D_01dae470 == -3) D_01dae460 = 1;
            else if (D_01dae470 == -4) D_01dae460 = 2;
            else if (D_01dae470 == -5) D_01dae460 = 3;
            else if (D_01dae470 == -7) D_01dae460 = 4;
            else D_01dae460 = 6;
            func_002349e8();
        }
        break;
    case 3:
        func_002fc200(D_01dae474, D_01dae410, D_01dae414);
        D_0035e374++;
        break;
    case 5:
        if (D_01dae470 >= 0) {
            if (D_01dae470 == D_01dae414) D_01dae460 = 0;
            else D_01dae460 = 5;
        } else {
            if (D_01dae470 == -2) D_01dae460 = 7;
            else if (D_01dae470 == -3) D_01dae460 = 1;
            else if (D_01dae470 == -4) D_01dae460 = 4;
            else if (D_01dae470 == -5) D_01dae460 = 3;
            else if (D_01dae470 == -8) D_01dae460 = 5;
            else D_01dae460 = 6;
        }
        D_0035e374++;
        break;
    case 6:
        func_002fbe98(D_01dae474);
        D_0035e374++;
        break;
    case 7:
        if (func_002fc378(1, 0, &D_01dae470)) func_002349e8();
        break;
    }
}
void func_00236010(void) asm("func_00236010");
void func_00236010(void) {
    switch (D_0035e374) {
    case 0:
        func_002fce28(D_01dae478, D_01dae47c, D_01dae408, D_01dae40c);
        D_0035e374++;
        break;
    case 1:
        if (func_002fc378(1, 0, &D_01dae470)) D_0035e374++;
        break;
    case 2:
        switch (D_01dae470) {
        case 0: D_01dae464 = 0; break;
        case -2: D_01dae464 = 3; break;
        case -4: D_01dae464 = 1; break;
        default: D_01dae464 = 2; break;
        }
        func_002349e8();
        break;
    }
}
void func_00236110(void) asm("func_00236110");
void func_00236110(void) {
    D_01dae438.a[11] = ((s32 (*)(s32))D_01dae41c)(D_0035e36c) == 0;
    func_002349e8();
}
}  // namespace n002351f8

// 00236148 (was src/anon/batch_w13.cpp)
namespace n00236148 {
extern s32 D_0035e370 asm("D_0035e370");
extern void (*D_0035e380[])(void) asm("D_0035e380");
/*TARGET 00236148*/
// 0x00232e60: definition moved into src/anon/unit_00231500.cpp

void func_00236148(void) asm("func_00236148");
// 0x00232e60: definition moved into src/anon/unit_00231500.cpp

void func_00236148(void) {
    D_0035e380[D_0035e370]();
}
}  // namespace n00236148

