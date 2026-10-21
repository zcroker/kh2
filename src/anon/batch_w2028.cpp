#include "../common/types.h"
extern "C" {
struct S5 { u8 pad[36]; f32 f; };
void func_002cba88(void*, S5*, void*, void*, f32, f32);
void* func_002cba50(void* a0, S5* a1, void* a2, void* a3) {
    func_002cba88(a0, a1, a2, a3, a1->f, 1.0f);
    return a0;
}
}
