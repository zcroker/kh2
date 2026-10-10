#include "../common/types.h"

/* Particle draw mode from a blend index (pppPart). Switch jump table at 0x36ead0 (first switch matched, 2026-10-11). */
struct PartW { u8 pad[0xa8]; u8 mode; };
void w_part_mode_odd(struct PartW* p, u32 k) asm("_Z16wtarget_001e34e0jjjj");
void w_part_mode_even(struct PartW* p, u32 k) asm("_Z16wtarget_001e3538jjjj");

void w_part_mode_odd(struct PartW* p, u32 k) {
    switch (k) {
    case 0: p->mode = 1; break;
    case 1: p->mode = 3; break;
    case 2: p->mode = 5; break;
    case 3: p->mode = 7; break;
    case 4: p->mode = 9; break;
    default: p->mode = 11; break;
    }
}

/* Same with the even modes; jump table at 0x36eae4. */
void w_part_mode_even(struct PartW* p, u32 k) {
    switch (k) {
    case 0: p->mode = 2; break;
    case 1: p->mode = 4; break;
    case 2: p->mode = 6; break;
    case 3: p->mode = 8; break;
    case 4: p->mode = 10; break;
    default: p->mode = 12; break;
    }
}
