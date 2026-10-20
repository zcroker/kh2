#include "../common/types.h"

extern "C" {
void func_001d3148(void*);
void func_001024a8(void*);
void func_00226ed0(void*);
void func_00226f20(void*);
void func_00139598(void*);
extern u8* D_0035037c;
extern s32 D_0035de60;

void func_00197ac0(void* a) {
    u8* p = D_0035037c;
    if (p) func_001d3148(p + 64);
    else func_001024a8(a);
}

void func_00226ee8(void* p) {
    func_00226ed0(p);
    D_0035de60 = 1;
    func_00226f20(p);
}

struct T0013d1d0 { u8 pad[0x20]; u32 flags; };
struct S0013d1d0 { u8 pad[0x104]; u8 sub[0x198]; T0013d1d0* q; };
void func_0013d1d0(S0013d1d0* p) {
    if (__builtin_expect(p->q && (p->q->flags & 8), 0)) func_00139598(p->sub);
}
}
