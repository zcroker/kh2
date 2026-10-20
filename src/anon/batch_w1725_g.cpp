#include "../common/types.h"

// dk::Timer pause flags. volatile + -g: the original keeps the store before
// jr ra with an unfilled (nop) delay slot.
extern volatile u32 D_00349dec;

extern "C" {
void Timer_pauseOn(u32 f) asm("_ZN2dk5Timer7pauseOnEj");
void Timer_pauseOn(u32 f) { D_00349dec |= f; }

void Timer_pauseOff(u32 f) asm("_ZN2dk5Timer8pauseOffEj");
void Timer_pauseOff(u32 f) { D_00349dec &= ~f; }
}
