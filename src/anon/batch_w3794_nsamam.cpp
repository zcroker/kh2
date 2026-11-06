#include "../common/types.h"
// Built with -fno-strict-aliasing -fmove-all-movables (_nsamam rule).
extern "C" {
struct PzEnt { u8 pad[8]; s8 a; s8 b; };
struct PzWork { u8 pad[0x1e0]; PzEnt ent[1]; };
struct PzObj { u8 pad[0x18]; u8 m[0x16c]; s32 f184; u8 pad2[0x10]; };
struct PzBits { u8 pad[0x2c]; u32 mask[1]; };
struct PzUV { s16 u[4]; s16 v[4]; };
static inline int PzBit(u32* m, u32 n) { return m[n >> 5] & (1 << (n & 31)); }
extern s16 D_00374cc8[];
extern s8 D_00374cd0[];
extern PzObj* D_0035f634;
extern PzBits* D_0035f638;
u8* func_002b23e0(s32);
PzWork* func_002a9d68(void);
void func_00138c10(void*, s32);
void func_002b28b0(u32, s32, s32, PzUV*);
void func_00239558(void*, s16*, s16*);

// Puzzle board refresh: for every piece set in the dirty mask (or all when
// flag), resize its sprite and set its UVs from the piece table.
void func_002b1bd0(u8 flag)
{
    s32 row = 0;
    s32 rows;
    s32 cols;
    u8* info = func_002b23e0(-1);
    PzWork* work = func_002a9d68();
    u32 kind = (*(u32*)info >> 27) & 1;
    s8* g = &D_00374cd0[kind * 4];
    cols = D_00374cd0[kind * 4];
    rows = g[1];
    s16 size = D_00374cc8[kind];
    for (row = 0; row < rows; row++) {
        for (s32 col = 0; col < cols; col++) {
            u32 idx = row * cols + col;
            if (PzBit(D_0035f638->mask, idx) || flag) {
                PzObj* o = &D_0035f634[idx];
                PzEnt* e = (PzEnt*)(((info[2] * 48 + idx) * 4 + (u32)work) + 480);
                s32 a = e->a;
                s32 b = e->b;
                if (a < 0) {
                    func_00138c10(o, 0);
                } else {
                    if (o->f184 != size) func_00138c10(o, size);
                    PzUV uv;
                    func_002b28b0((*(u32*)info >> 27) & 1, a, b, &uv);
                    func_00239558(o->m, uv.u, uv.v);
                }
            }
        }
    }
    PzBits* pz = D_0035f638;
    pz->mask[0] = 0;
    pz->mask[1] = 0;
}
}
