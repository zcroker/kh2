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
GS3U* Tz__JmPuzzle__GetImageInfo(s32);
s32 func_002b2380(s32, s32);
void func_0028dcc0(u8*, u8*);
void func_002b28b0(u32 a0, s32 idx, s32 mode, UV55* out);
void YI__SPRITE__SetDirextUV(u8* p, s16* a, s16* b);
}

// Getter wrapper; the call has to go through an inline for the
// register allocation of q to match.
static inline GS3U* GetCur(s32 i) { return Tz__JmPuzzle__GetImageInfo(i); }

extern "C" {

void func_002b3050(u8 a0);  // 0x002b3050: definition moved into src/anon/unit_002b2a18.cpp

}
