#include "../common/types.h"

struct Inner_1abba8 { u8 pad[0x148]; s32 a; s32 b; };
struct A_1abba8 { u32 pad[3]; s32 c; s32 d; Inner_1abba8 in; };

extern "C" {
void func_0023acd8(void*);
void func_0023ade0(void*);

void func_001abba8(A_1abba8* a) {
    Inner_1abba8* s = &a->in;
    func_0023acd8(s);
    s32 c = a->c;
    s32 d = a->d;
    s->a = c;
    s->b = d;
    func_0023ade0(s);
}
}
