#include "../common/types.h"
// Built with -fno-strict-aliasing.
extern "C" {
typedef struct V2cdfb0 { f32 x, y, z, w; } __attribute__((aligned(16))) V2cdfb0;
typedef struct Path2cdfb0 { u8 pad0[8]; s32 count; u8 pad1[4]; u8 loop; u8 pad1b[7]; f32 pos; u8 pad2[132 - 28]; u8 forward; } Path2cdfb0;
V2cdfb0* func_002cb890(Path2cdfb0*, s32);
f32 func_002cdb60(Path2cdfb0*, f32*, V2cdfb0*, V2cdfb0*, V2cdfb0*, f32, f32);
f32 func_002cdcd8(Path2cdfb0*, s32*, f32*, V2cdfb0*, f32);
/* Nearest point on a looping path: like func_002cdcd8 but indices wrap. Searches the
   current segment and the next one in the travel direction, keeps the closer one.
   Returns the distance, or -1 when it is not below maxDist. */
f32 Ti__Path__search_near_point_from_pre_point(Path2cdfb0* p, s32* idx, f32* t, V2cdfb0* pos, f32 maxDist);  // 0x002cdfb0: definition moved into src/taito/path.cpp
}
