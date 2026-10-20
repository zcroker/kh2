#include "../common/types.h"

extern "C" {

struct S1a1b30 { u8 pad[432]; u8 b0; u8 b1; u8 b2; };
static inline s32 sub_clamp0(s32 a, s32 b) {
    s32 v = a - b;
    if (v < 0) v = 0;
    return v;
}
void func_001a1b30(S1a1b30* s, s32 n) {
    if (s->b1 == s->b2 || s->b1 < n) s->b0 = 0;
    s->b1 = sub_clamp0(s->b1, n);
}

extern u8* D_00361f60;
void func_002ceb08(void);
void func_002e26c0(void*);
void MG_EHSidecar_MoveToBeforePoint(void* self) asm("_ZN2Ti12MG_EHSidecar17MoveToBeforePointEv");
void MG_EHSidecar_MoveToBeforePoint(void* self) {
    u8* s = D_00361f60;
    if (s) func_002ceb08();
    func_002e26c0(s);
}

}
