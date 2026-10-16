#include "../common/types.h"

extern "C" {
s32 func_00242a00();
void func_0023d1d0();
void func_0023d1e0();
s32 func_00242a68();
void func_002b6bc4(s32);

struct W1528_S5 { u8 pad[0x2c]; u16* volatile a; u16* volatile b; };

void func_00288f60(W1528_S5* p, s32 n, u16* s, u16* t) {
    s32 i;
    for (i = 0; i < 4; i++) p->a[n * 4 + i] = s[i];
    for (i = 0; i < 4; i++) p->b[n * 4 + i] = t ? t[i] : s[i];
}

void func_00242908() {
    if (func_00242a00()) func_0023d1d0(); else func_0023d1e0();
    s32 a;
    switch (func_00242a68()) {
    case 0: a = 0; break;
    case 2: a = 2; break;
    case 1:
    default: a = 1; break;
    }
    func_002b6bc4(a);
}
}
