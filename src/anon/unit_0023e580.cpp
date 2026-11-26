// Linked unit 0x23e580-0x23e5d0: motion change of one slot of the 4-slot model viewer (Mgr23da00 in
// unit_0023d260), never written as a separate match (no layout.tsv row). The draw before it (0x23e188) is
// not linked yet. Flags -G0 -fno-strict-aliasing like the neighbours.
#include "../common/types.h"
namespace n0023e580 {
struct Obj {
    u8 p0[112];
    void* mdl;
    void* mot;
    u8 p78[288 - 120];
    s32 a3;
    s32 t0;
    u8 p128[320 - 296];
};
struct Mgr {
    u8 p0[1632];
    Obj obj[4];
    u8 kind[4];
    u8 slot[4];
};
void* YS__OBJDATA__get_kna(void*, s32, s32) asm("YS__OBJDATA__get_kna");
void func_0023e580(Mgr* m, s32 idx, s32 a) asm("func_0023e580");
void func_0023e580(Mgr* m, s32 idx, s32 a)
{
    Obj* o = &m->obj[m->slot[idx]];
    o->a3 = a;
    o->mot = YS__OBJDATA__get_kna(o->mdl, a, o->t0);
}
}  // namespace n0023e580
