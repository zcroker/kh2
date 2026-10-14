#include "../common/types.h"
extern "C" {
struct E1a8 { u32 w0, w4; s32 w8; s32 w12; u16 h[18]; };
struct T1a8 { u32 w0; s32 n; E1a8 e[1]; };
struct G1a8 { u8 pad[16]; u16 h[18]; };
extern T1a8* D_01c6cc08;
extern G1a8 D_01c6cc10;
extern u8 D_0032bae0[];
s32 func_001a8930(E1a8*, u8, u8);
void func_0016fab0(s32, s32);
void func_001a89f0(void) {
    u8* p = D_0032bae0;
    s32 a = 0, b = 0;
    u8 k0 = p[0];
    s32 i;
    E1a8* e;
    for (i = 0; i < 18; i++) D_01c6cc10.h[i] = 0;
    e = D_01c6cc08->e;
    for (i = 0; i < D_01c6cc08->n; i++, e++) {
        if (func_001a8930(e, k0, p[1])) {
            s32 j;
            if (e->w8 > 0) a = e->w8;
            if (e->w12 > 0) b = e->w12;
            for (j = 0; j < 18; j++) {
                if (e->h[j] != 0) D_01c6cc10.h[j] = e->h[j];
            }
        }
    }
    func_0016fab0(a, b);
}
}
