#include "../common/types.h"
extern "C" {
typedef struct G2b0 G2b0;
struct G2b0 { u8 p0[28]; s16 a[2]; s16 b[2]; u8 p36[8]; u32 bits[2]; u32 :10; u32 b10:1; u32 b11:1; u32 f12:2; };
struct Q2b0 { u8 p[9]; s8 c; };
u8* func_002a9d68(void);
u8* Tz__JmPuzzle__GetImageInfo(s32);
u32 func_002b2380(s32, s32);
void Tz__JmPuzzle__UpdatePiece(s32);
void func_002b3050(s32);
extern G2b0* D_0035f638;

void Tz__JmPuzzle__PieceRot(u32 a0);  // 0x002b0e78: definition moved into src/anon/unit_002b0950.cpp
}
