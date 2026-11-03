#include "../common/types.h"
extern "C" {
struct T4 { u8 b[4]; };
extern T4* D_01c6cc0c;
void func_001a8bb8(T4*);
s32 func_001a8bf8(T4*, s32);
void func_001a8c60(T4*, s32, s32);
s32 func_001a8cd0(T4*, s32);

void func_001a8d40(T4* out, s32 idx)
{
    T4 a, b;
    s32 j;
    register s32 i asm("$18"); // pin: keeps the loop index in s2 and the hoisted 18 in s0 (loop 3)
    func_001a8bb8(&a);
    func_001a8bb8(&b);
    a = D_01c6cc0c[idx];
    func_001a8c60(&b, 0, func_001a8bf8(&a, 0));
    j = 1;
    i = 1;
    s32 m = ~0x3f;
    for (; i < 4; i++) {
        s32 c = a.b[i];
        if (m & c) {
            func_001a8c60(&b, j, (u8)c);
            j++;
            a.b[i] = 18;
        }
    }
    for (i = 1; i < 4; i++) {
        s32 k = func_001a8cd0(&a, func_001a8bf8(out, i));
        if (k >= 0) {
            func_001a8c60(&b, j, func_001a8bf8(out, i));
            j++;
            a.b[k] = 18;
        }
    }
    for (i = 1; i < 4; i++) {
        if (func_001a8bf8(&a, i) != 18) {
            func_001a8c60(&b, j, a.b[i]);
            j++;
        }
    }
    for (; j < 4; j++) func_001a8c60(&b, j, 18);
    *out = b;
}
}
