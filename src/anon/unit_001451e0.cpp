// Linked unit 0x001451e0-0x00145600 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../harata/libdk/aabbox.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 001451e0 (was gap, never written)
namespace n001451e0 {
struct V4 { f32 x, y, z, w; };
struct SBox { s16 x0, y0, z0, x1, y1, z1; };
// the 8 corners of an s16 box as points (w = 1)
void func_001451e0(const SBox* b, V4* v) asm("func_001451e0");
void func_001451e0(const SBox* b, V4* v) {
    v[0].w = v[1].w = v[2].w = v[3].w = v[4].w = v[5].w = v[6].w = v[7].w = 1.0f;
    v[0].x = b->x0; v[0].y = b->y0; v[0].z = b->z0;
    v[1].x = b->x0; v[1].y = b->y1; v[1].z = b->z0;
    v[2].x = b->x1; v[2].y = b->y1; v[2].z = b->z0;
    v[3].x = b->x1; v[3].y = b->y0; v[3].z = b->z0;
    v[4].x = b->x0; v[4].y = b->y0; v[4].z = b->z1;
    v[5].x = b->x0; v[5].y = b->y1; v[5].z = b->z1;
    v[6].x = b->x1; v[6].y = b->y1; v[6].z = b->z1;
    v[7].x = b->x1; v[7].y = b->y0; v[7].z = b->z1;
}
}  // namespace n001451e0

// 00145390 (was gap, never written)
namespace n00145390 {
struct V4 { f32 x, y, z, w; };
struct SBox { s16 x0, y0, z0, x1, y1, z1; };
// the same with y and z negated
void func_00145390(const SBox* b, V4* v) asm("func_00145390");
void func_00145390(const SBox* b, V4* v) {
    v[0].w = v[1].w = v[2].w = v[3].w = v[4].w = v[5].w = v[6].w = v[7].w = 1.0f;
    v[0].x = b->x0; v[0].y = -b->y1; v[0].z = -b->z1;
    v[1].x = b->x0; v[1].y = -b->y0; v[1].z = -b->z1;
    v[2].x = b->x1; v[2].y = -b->y0; v[2].z = -b->z1;
    v[3].x = b->x1; v[3].y = -b->y1; v[3].z = -b->z1;
    v[4].x = b->x0; v[4].y = -b->y1; v[4].z = -b->z0;
    v[5].x = b->x0; v[5].y = -b->y0; v[5].z = -b->z0;
    v[6].x = b->x1; v[6].y = -b->y0; v[6].z = -b->z0;
    v[7].x = b->x1; v[7].y = -b->y1; v[7].z = -b->z0;
}
}  // namespace n00145390

// 00145580 (was src/anon/batch_w49.cpp)
namespace n00145580 {
/*TARGET 00145580*/
// 0x00141988: definition moved into src/anon/unit_00141458.cpp

// Overlap test of two s16 boxes;
// 0x00141988: definition moved into src/anon/unit_00141458.cpp

// Overlap test of two s16 boxes {min xyz, max xyz}.
s32 func_00145580(s16* a, s16* b) asm("func_00145580");
s32 func_00145580(s16* a, s16* b) {  // cmp_halfword_triples
    if (a[3] < b[0]) return 0;
    if (a[0] > b[3]) return 0;
    if (a[4] < b[1]) return 0;
    if (a[1] > b[4]) return 0;
    if (a[5] < b[2]) return 0;
    if (a[2] > b[5]) return 0;
    return 1;
}
}  // namespace n00145580

