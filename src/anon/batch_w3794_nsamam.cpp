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
u8* Tz__JmPuzzle__GetImageInfo(s32);
PzWork* func_002a9d68(void);
void func_00138c10(void*, s32);
void func_002b28b0(u32, s32, s32, PzUV*);
void YI__SPRITE__SetDirextUV(void*, s16*, s16*);

// Puzzle board refresh: for every piece set in the dirty mask (or all when
// flag), resize its sprite and set its UVs from the piece table.
void Tz__JmPuzzle__UpdatePiece(u8 flag);  // 0x002b1bd0: definition moved into src/anon/unit_002b0950.cpp
}
