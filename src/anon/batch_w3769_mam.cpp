#include "../common/types.h"
// Built with -fmove-all-movables: the two 5116 constants each inner loop's start offset is
// multiplied by stay in their own saved registers (s6/s7) hoisted out of the outer loop.
struct E27A { u8 d[0x1b4]; };
struct E27B { u8 d[0x198]; };
struct O27 { E27A a; E27B b[5]; E27A c[6]; u8 pad[24]; };
extern "C" {
s32 func_00139d78(void*);
extern void* D_0035f244;
extern O27* D_0035f248;

// Returns the first nonzero func_00139d78 result over D_0035f244 and, for each of the four
// entries of D_0035f248, its a, b[0], b[1]/b[3], b[2]/b[4], then c[0]/c[3] .. c[2]/c[5].
s32 func_0027e920(void)
{
    s32 i, j;
    s32 r = func_00139d78(D_0035f244);
    for (i = 0; i < 4 && r == 0; i++) {
        r = func_00139d78(&D_0035f248[i].a);
        if (r == 0) r = func_00139d78(&D_0035f248[i].b[0]);
        for (j = 0; j < 2 && r == 0; j++) {
            r = func_00139d78(&D_0035f248[i].b[j + 1]);
            if (r == 0) r = func_00139d78(&D_0035f248[i].b[j + 3]);
        }
        for (j = 0; j < 3 && r == 0; j++) {
            r = func_00139d78(&D_0035f248[i].c[j]);
            if (r == 0) r = func_00139d78(&D_0035f248[i].c[j + 3]);
        }
    }
    return r;
}
}
