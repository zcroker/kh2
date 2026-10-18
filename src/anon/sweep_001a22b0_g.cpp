#include "../common/types.h"
typedef struct P22 { u8 pad[0x210]; u16 r[3]; } P22;
typedef struct Q22 { u8 pad[9]; u8 k; } Q22;
s32 func_001a22b0(s32 a0, s32 v, P22* p, Q22* q) {
    if (p) {
        switch (q->k) {
        case 1: v = (v * p->r[0] + 99) / 100; break;
        case 2: v = (v * p->r[1] + 99) / 100; break;
        case 3: v = (v * p->r[2] + 99) / 100; break;
        }
    }
    return v;
}
