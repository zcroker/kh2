#include "../common/types.h"

extern "C" {

struct N102210 { char p0[12]; N102210* next; char p1[12]; int f28; };
extern N102210* D_0038aa40;
static inline __attribute__((always_inline)) N102210* nxt102210(N102210* p) {
    if (p == 0) return D_0038aa40;
    return p->next;
}
N102210* func_00102210(void) {
    N102210* p = 0;
    while ((p = nxt102210(p))) {
        if (p->f28 == 1) return p;
    }
    return 0;
}

struct M1702e0 { char p0[48]; u32 f48; char p1[8]; M1702e0* next; };
extern M1702e0* D_0034dca0;
static inline __attribute__((always_inline)) M1702e0* nxt1702e0(M1702e0* p) {
    if (p == 0) return D_0034dca0;
    return p->next;
}
M1702e0* ctarget_001702e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_001702e0jjjj");
M1702e0* ctarget_001702e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    M1702e0* p = 0;
    while ((p = nxt1702e0(p))) {
        if (p->f48 == a0) return p;
    }
    return 0;
}

// VU0 random number in [0,1) scaled to 0..32767
s32 func_00222568(void) {
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvitof0.x $vf2, $vf2\n\tvrnext.x $vf1, R\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(r) : : "$8");
    return (s32)(r * 32768.0f);
}

}
