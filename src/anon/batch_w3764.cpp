#include "../common/types.h"

struct GEnt { s8 c0; s8 c1; s8 c2; s8 c3; };
struct GSav { u8 pad[488]; GEnt e[1][48]; };
struct GG {
    u8 pad[28]; s16 x[2]; s16 y[2]; u8 pad2[52 - 36];
    u32 : 10; u32 b10 : 1; u32 b11 : 1; u32 b12 : 2;
};
struct GS3 { u32 : 27; u32 b27 : 1; u32 : 4; };
struct GS3b { u8 b0; u8 b1; u8 b2; };
union GS3U { GS3 w; GS3b b; };
struct UV55 { s16 u[4]; s16 v[4]; };

extern "C" {
extern GG* D_0035f638;
extern u8* D_0035f634;
GSav* func_002a9d68(void);
GS3U* func_002b23e0(s32);
s32 func_002b2380(s32, s32);
void func_0028dcc0(u8*, u8*);
void func_002b28b0(u32 a0, s32 idx, s32 mode, UV55* out);
void func_00239558(u8* p, s16* a, s16* b);
}

// Getter wrapper; the call has to go through an inline for the
// register allocation of q to match.
static inline GS3U* GetCur(s32 i) { return func_002b23e0(i); }

extern "C" {

void func_002b3050(u8 a0)
{
    if (a0 != 0 || D_0035f638->b10) {
        u8* q = (u8*)GetCur(-1);
        // t is reused for both lookups (keeps the product out of v0).
        s32 t = func_002b2380(D_0035f638->x[D_0035f638->b11], D_0035f638->y[D_0035f638->b11]);
        s32 off = t * 408;
        u8* s3 = D_0035f634 + off;
        u8* p = D_0035f634 + D_0035f638->b11 * 408 + 19992;
        func_0028dcc0(p, s3);
        if (D_0035f638->b11) {
            UV55 uv;
            p = (u8*)func_002a9d68();
            t = func_002b2380(D_0035f638->x[0], D_0035f638->y[0]);
            u8* base = D_0035f634;
            func_002b28b0(((GS3U*)q)->w.b27, ((GSav*)p)->e[((GS3U*)q)->b.b2][t].c0, D_0035f638->b12, &uv);
            q = base;
            p = q + 20808;
            q += 20832;
            func_00239558(q, uv.u, uv.v);
            func_0028dcc0(p, s3);
        }
        D_0035f638->b10 = 0;
    }
}

}
