#include "../common/types.h"

/* Particle draw mode from a blend index (pppPart). Switch jump table at 0x36ead0 (first switch matched, 2026-10-11). */
struct PartW { u8 pad[0xa8]; u8 mode; };
void w_part_mode_odd(struct PartW* p, u32 k) asm("_Z16wtarget_001e34e0jjjj");
void w_part_mode_even(struct PartW* p, u32 k) asm("_Z16wtarget_001e3538jjjj");

void w_part_mode_odd(struct PartW* p, u32 k);  // 0x001e34e0: definition moved into src/anon/unit_001e0cb8.cpp

/* Same with the even modes; jump table at 0x36eae4. */
void w_part_mode_even(struct PartW* p, u32 k);  // 0x001e3538: definition moved into src/anon/unit_001e0cb8.cpp
