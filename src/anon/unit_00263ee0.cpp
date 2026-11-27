// Linked unit 0x00263ee0-0x002640a8 (one namespace per old matched source; class methods in their own namespace).
#include "../tozawa/cmenu_item.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/scroll_bar.hpp"
#include "../tozawa/cmenu_help.hpp"

// 00263ee0 (was src/anon/batch_w2489_gnsa_nogcse.cpp)
namespace n00263ee0 {
struct E24 { s16 id; s16 k; u16 v[5]; u16 f14; u16 n; u16 pad18; u32 off; };
struct H16 { u8 pad0[6]; s16 count; u8 pad8[8]; E24 e[1]; };
struct Sub8 { s16 a; u16 b; u32 off; };
struct Out14 { u16 v[5]; s16 z; u8 fl; u8 en; };
H16* func_00263ea8(void) asm("func_00263ea8");
void func_00263eb8(H16*) asm("func_00263eb8");
u32 func_001a6d08(s32) asm("func_001a6d08");
void func_001a6c90(s32) asm("func_001a6c90");
void func_002641c8(Out14*, u8*, u32, u32) asm("func_002641c8");
void func_002640a8(s32 a0, u16 a1, Out14* a2) asm("func_002640a8");
/*TARGET 00263ee0*/
void Tz__IShopInfo__GetShopTbl(s32 a0, Out14* o) asm("Tz__IShopInfo__GetShopTbl");
void Tz__IShopInfo__GetShopTbl(s32 a0, Out14* o) {
    s32 i;
    H16* h = func_00263ea8();
    func_00263eb8(h);
    E24* e = h->e;
    for (i = 0; i < h->count; i++, e++) {
        if (e->id == a0) {
            Sub8* s = (Sub8*)((u8*)h + e->off);
            if (!func_001a6d08(e->k)) func_001a6c90(e->k);
            o->v[0] = e->v[0];
            o->v[1] = e->v[1];
            o->v[2] = e->v[2];
            o->v[3] = e->v[3];
            o->v[4] = e->v[4];
            o->z = 0;
            if ((e->f14 & 0x80) || s->b == 0) o->en = 0;
            else o->en = 1;
            o->fl = 0;
            u32 f = e->f14;
            if (f & 0x100) { o->fl = 1; f = e->f14; }
            if (f & 0x200) o->fl |= 2;
            s32 j;
            for (j = 0; j < e->n; j++, s++) {
                if (__builtin_expect(s->a < 0, 1) || func_001a6d08(s->a)) func_002641c8(o, (u8*)h + s->off, s->b, 31);
            }
            break;
        }
    }
    if (e->f14 & 0x80) func_002640a8(a0, e->f14, o);
}
}  // namespace n00263ee0

