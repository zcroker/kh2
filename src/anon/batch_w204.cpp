#include "../common/types.h"
extern "C" {
void func_0014f030(float* p, float a, float b, float c) {
    if (c == 0.0f) c = 1.0f;
    float d = (b - a) / c;
    p[0] = a; p[2] = b; p[1] = d;
}
extern int func_001064a8(int);
float func_0023e700(void) {
    return (float)(func_001064a8(20) + 10) * 60.0f;
}
}
