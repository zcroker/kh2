#include "../common/types.h"

struct S109 { u8 pad[168]; u8 f168; };

extern "C" {
int func_001e3590(S109* a0) {
    int r = 0;
    switch (a0->f168) {
    case 1: r = 1; break;
    case 3: r = 2; break;
    case 5: r = 3; break;
    case 7: r = 4; break;
    case 9: r = 5; break;
    case 11: r = 6; break;
    default: r = 0; break;
    }
    return r;
}

int func_001e35f0(S109* a0) {
    int r = 0;
    switch (a0->f168) {
    case 2: r = 1; break;
    case 4: r = 2; break;
    case 6: r = 3; break;
    case 8: r = 4; break;
    case 10: r = 5; break;
    case 12: r = 6; break;
    default: r = 0; break;
    }
    return r;
}
}
