#include "../common/types.h"

extern "C" {
// Wrap an angle into (-pi, pi].
float func_0011c050(float x) {  // float_bucket_index
    if (x > 0.0f) {
        if (x > 3.14159274f) { while (x > 3.14159274f) x -= 6.2831855f; }
    } else if (x < -3.14159274f) { while (x < -3.14159274f) x += 6.2831855f; }
    return x;
}

}
