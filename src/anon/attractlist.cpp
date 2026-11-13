#include "unit_001d35e0.hpp"

// The out-of-line copy of LIST<ATTRACT>::Remove (0x3216c8), which ATTRACT's D1 destructor
// calls (its D2 copy inlines it). gcc emits it as a linkonce function; this file owns it so the
// build places it at its address.
template void LIST<ATTRACT>::Remove(ATTRACT*);

// The build registry cannot read template names; this never-compiled block names this file
// as the source of the symbol.
#if 0
void AttractListRemove(LIST<ATTRACT>* l, ATTRACT* p) asm("_ZN4LISTI7ATTRACTE6RemoveEPS0_");
void AttractListRemove(LIST<ATTRACT>* l, ATTRACT* p) { l->Remove(p); }
#endif
