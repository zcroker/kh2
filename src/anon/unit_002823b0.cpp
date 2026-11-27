// Linked unit 0x002823b0-0x00282620 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/gumi_pause.hpp"
#include "../tozawa/cmenu_config.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tz/ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/chg_member.hpp"

// 002823b0 (was src/anon/batch_w3732_mam.cpp)
namespace n002823b0 {
struct Ent2823 { u16 id; u8 a; u8 b; s16 c; };
struct Obj2823 { u8 pad[580]; u16* items; };
union Tot2823 { s32 i; u8 c; };
struct Self2823 { Tot2823 total; Ent2823 ent[682]; u8 pad[4]; s32 f1004; s32 f1008; s32 f100c; s32 cnt[5]; };
s32 func_002811f8(s32, s32) asm("func_002811f8");
Obj2823* func_00281180(s32, s32) asm("func_00281180");
s32 Tz__ItemInfo__CalcEquipMax(Self2823*, s32, s32) asm("Tz__ItemInfo__CalcEquipMax");
s32 func_00281480(s32, s32) asm("func_00281480");
s32 func_002813b8(void) asm("func_002813b8");
s32 func_00281420(void) asm("func_00281420");
u16 func_002814b0(s32) asm("func_002814b0");
/*TARGET 002823b0*/
void Tz__ItemInfo__SetEquip(Self2823* self, s32 b, s32 r) asm("Tz__ItemInfo__SetEquip");
void Tz__ItemInfo__SetEquip(Self2823* self, s32 b, s32 r) {
    u16* items;
    s32 total;
    s32 mask;
    s32 i, j, n;
    Ent2823* e = self->ent;
    self->f1008 = 1;
    self->f100c = func_002811f8(self->f1004, b - 5);
    items = func_00281180(self->f1004, self->f100c)->items;
    for (i = 0; i < 5; i++) {
        self->cnt[i] = Tz__ItemInfo__CalcEquipMax(self, self->f100c, i);
    }
    mask = 0;
    if (func_00281480(self->f1004, self->f100c)) {
        s32 m = func_002813b8();
        mask = m & func_00281420();
    }
    self->total.i = 0;
    total = 0;
    for (i = 0; i < 5; i++) {
        if (i == 1) continue;
        n = self->cnt[i];
        if (i == 0) n += self->cnt[1];
        for (j = 0; j < n; j++) {
            u16 id = 0;
            s32 eq = 0;
            u8 a = 1;
            switch (i) {
            case 0:
                id = items[0];
                if (j != 0) {
                    s32 c = 0;
                    s32 k;
                    for (k = 0; k < 7; k++) {
                        bool on = (mask >> k) & 1;
                        if ((u8)on) {
                            if (c + 1 == j) {
                                id = func_002814b0(k);
                                break;
                            }
                            c++;
                        }
                    }
                }
                break;
            case 4:
                id = items[j + 26];
                if (id == 0) {
                    u16 t = items[j + 34];
                    if (t != 0) {
                        id = t;
                        a = 0;
                    }
                }
                eq = items[j + 34] == id;
                break;
            case 3:
                id = items[j + 18];
                break;
            case 2:
                id = items[j + 10];
                break;
            }
            if (!id) a = 0;
            e->a = a;
            e->id = id;
            e->b = eq != 0;
            e->c = 999;
            e++;
        }
        total += n;
    }
    self->total.i = total;
}
}  // namespace n002823b0

