#include "../common/types.h"

extern "C" {
extern u32 func_001064a8(u32);  // int_to_float_scaled

float func_0010f660() { return (float)func_001064a8(20001) * 0.00005f; }
}
