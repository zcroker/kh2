#include "../common/types.h"
extern "C" {
typedef struct G2b0 G2b0;
struct G2b0 { u8 p0[28]; s16 a[2]; s16 b[2]; u8 p36[8]; u32 bits[2]; u32 :10; u32 b10:1; u32 b11:1; u32 f12:2; };
struct Q2b0 { u8 p[9]; s8 c; };
u8* func_002a9d68(void);
u8* func_002b23e0(s32);
u32 func_002b2380(s32, s32);
void func_002b1bd0(s32);
void func_002b3050(s32);
extern G2b0* D_0035f638;

void func_002b0e78(u32 a0)
{
    u8* s3 = func_002a9d68();
    u8* s2 = func_002b23e0(-1);
    u32 v = func_002b2380(D_0035f638->a[D_0035f638->b11], D_0035f638->b[D_0035f638->b11]);
    G2b0* g = D_0035f638;
    if (!g->b11) {
        Q2b0* q = (Q2b0*)(((s2[2] * 48 + v) * 4 + (u32)s3) + 480);
        s32 y = q->c;
        s32 z = (a0 & 0x40000) ? y + 5 : y + 3;
        q->c = z % 4;
        u32* bp = D_0035f638->bits;
        u32* p = bp + (v >> 5);
        *p |= 1 << (v & 31);
        func_002b1bd0(0);
    } else {
        s32 x = g->f12;
        x = (a0 & 0x40000) ? x + 5 : x + 3;
        g->f12 = x;
        func_002b3050(1);
    }
}
}
