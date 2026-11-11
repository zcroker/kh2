#include "magic.hpp"

// The out-of-line copy of LIST<YS::MAGIC>::Remove (0x31f298), which MAGIC's D1 destructor calls
// (its D2 copy inlines it). gcc emits it as a linkonce function; this file owns it so the build
// places it at its address.
template void LIST<YS::MAGIC>::Remove(YS::MAGIC*);

// The build registry cannot read template names; this never-compiled block names this file
// as the source of the symbol.
#if 0
void MagicListRemove(LIST<YS::MAGIC>* l, YS::MAGIC* p) asm("_ZN4LISTIN2YS5MAGICEE6RemoveEPS1_");
void MagicListRemove(LIST<YS::MAGIC>* l, YS::MAGIC* p) { l->Remove(p); }
#endif
