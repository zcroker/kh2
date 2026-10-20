#include "../common/types.h"

extern "C" {

struct VObj1db7d0 { void** vt; };
struct S1db7d0 { void* vt; VObj1db7d0* o; u32 p8; u32 c; };
extern void* D_00352a38;
void func_001db7d0(S1db7d0* s) {
    s->vt = &D_00352a38;
    VObj1db7d0* o = s->o;
    ((void (*)(VObj1db7d0*, u32))o->vt[1])(o, s->c);
}

}
