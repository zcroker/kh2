#include "itemeffect.hpp"

// The out-of-line copy of LIST<YS::ITEM_EFFECT>::Remove (0x3204c8), which ITEM_EFFECT's D1
// destructor calls (its D2 copy inlines it). gcc emits it as a linkonce function; this file
// owns it so the build places it at its address.
template void LIST<YS::ITEM_EFFECT>::Remove(YS::ITEM_EFFECT*);

// The build registry cannot read template names; this never-compiled block names this file
// as the source of the symbol.
#if 0
void EffectListRemove(LIST<YS::ITEM_EFFECT>* l, YS::ITEM_EFFECT* p) asm("_ZN4LISTIN2YS11ITEM_EFFECTEE6RemoveEPS1_");
void EffectListRemove(LIST<YS::ITEM_EFFECT>* l, YS::ITEM_EFFECT* p) { l->Remove(p); }
#endif
