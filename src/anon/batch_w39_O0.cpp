#include "../common/types.h"

extern "C" {

// --- 002b788c (built without optimisation)
int func_002b6708(int, int, int, int, int, int, int, int);
int func_002b788c(int a, int b, int c, int d) asm("_Z13func_002b788cPv");
int func_002b788c(int a, int b, int c, int d) {
    return func_002b6708(7, 25, a, b, c, d, 1, 1);
}

}  // extern "C"
