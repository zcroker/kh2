// Linked unit 0x00282620-0x00282b00 (one namespace per old matched source; class methods in their own namespace).
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

// 00282620 (was src/anon/batch_w85.cpp)
namespace n00282620 {
struct Item282 { u16 id; u8 a, b; u16 pad; };
struct List282 { union { s32 n; u16 h; } u; Item282 e[1]; };
u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 00282620*/
// appends each nonzero id from the 8-entry table that is not already listed
void func_00282620(List282* l) asm("func_00282620");
// appends each nonzero id from the 8-entry table that is not already listed
void func_00282620(List282* l) {
    s32 i, j;
    for (i = 0; i < 8; i++) {
        u16 id = ((u16*)(func_001058e8() + 14056))[i];
        if (id) {
            for (j = 0; j < l->u.n; j++) {
                u16 x = l->e[j].id;
                if (x && id == x) break;
            }
            if (j >= l->u.n) {
                l->e[l->u.n].id = id;
                l->e[l->u.n].a = 0;
                l->e[l->u.n].b = 0;
                l->u.n++;
            }
        }
    }
}
}  // namespace n00282620

// 002826f8 (was src/anon/batch_wcx2.cpp)
namespace n002826f8 {
// --------------------
u8* func_00281180_x9057(s32) asm("func_00281180");
s32 func_00281480(s32, s32) asm("func_00281480");
s32 func_002813b8() asm("func_002813b8");
s32 func_00281420_x9060() asm("func_00281420");
/*TARGET 002826f8*/
s32 Tz__ItemInfo__CalcEquipMax(u8* p, s32 a, s32 k) asm("Tz__ItemInfo__CalcEquipMax");
s32 Tz__ItemInfo__CalcEquipMax(u8* p, s32 a, s32 k) {
    s32 r = 0;
    u8* t = *(u8**)(func_00281180_x9057(*(s32*)(p + 4100)) + 580);
    switch (k) {
    case 0:
        r = 1;
        break;
    case 1:
        if (func_00281480(*(s32*)(p + 4100), a)) {
            s32 m = func_002813b8();
            m &= func_00281420_x9060();
            s32 i;
            for (i = 0; i < 7; i++) r += (m >> i) & 1;
        }
        break;
    case 2: r = t[16]; break;
    case 3: r = t[17]; break;
    case 4: r = t[18]; break;
    }
    return r;
}
}  // namespace n002826f8

// 002827e0 (was src/anon/tiny_leaf.cpp)
namespace n002827e0 {
/*TARGET 002827e0*/
u32 func_002827e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002827e0jjjj");
u32 func_002827e0(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_indexed_word
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r5 = (u32)(r5 << 2);
    r5 = (u32)(r5 + r4);
    r2 = *(u32*)((u32)r5 + (s32)(4112));
    return r2;
}
}  // namespace n002827e0

// 002827f0 (was src/anon/batch_w3735.cpp)
namespace n002827f0 {
void func_00281f70(u8*, s32, s32) asm("func_00281f70");
void func_00282858(u8*, s32, s32) asm("func_00282858");
void func_00282b00(u8*, s32, s32) asm("func_00282b00");
/*TARGET 002827f0*/
// Runs 00281f70, then one of two handlers depending on the flag at +4104.
// Register pins only (no asm): this in s2 and the call arguments set up before the branch,
// as the original does.
void Tz__ItemInfo__MakeMsgTbl(u8* a, s32 b, s32 c) asm("Tz__ItemInfo__MakeMsgTbl");
// Runs 00281f70, then one of two handlers depending on the flag at +4104.
// Register pins only (no asm): this in s2 and the call arguments set up before the branch,
// as the original does.
void Tz__ItemInfo__MakeMsgTbl(u8* a, s32 b, s32 c) {
    func_00281f70(a, b, c);
    register u8* p asm("$18") = a;
    s32 t = *(s32*)(p + 4104);
    register u8* r4 asm("$4") = p;
    register s32 r5 asm("$5") = b;
    register s32 r6 asm("$6") = c;
    if (t == 0) { func_00282858(r4, r5, r6); return; }
    func_00282b00(r4, r5, r6);
}
}  // namespace n002827f0

// 00282858 (was src/anon/batch_w85.cpp)
namespace n00282858 {
struct Item282 { u16 id; u8 a, b; u16 pad; };
struct List282 { union { s32 n; u16 h; } u; Item282 e[1]; };
extern u8 D_003741e8[] asm("D_003741e8");
u32 func_00259618(u16, u8*, s32) asm("func_00259618");
void func_00192b30(u32) asm("func_00192b30");
void func_00192cc0(u8*, u8*, u8) asm("func_00192cc0");
/*TARGET 00282858*/
void func_00282858(List282* l, s32 first, s32 count) asm("func_00282858");
void func_00282858(List282* l, s32 first, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        Item282* e;
        u8* row;
        if (i + first >= l->u.n) break;
        e = &l->e[first + i];
        row = (u8*)l + i * 80;
        func_00192b30(func_00259618(e->id, row + 1556, e->b != 0));
        if (e->a != 1) func_00192cc0(row + 1540, D_003741e8, e->a);
        else row[1540] = 0;
    }
}
}  // namespace n00282858

// 00282940 (was src/anon/batch_w289.cpp)
namespace n00282940 {
struct GEnt { u16 id; u8 b2; u8 b3; u16 pad; };
struct GRow { char name[8]; u8 flag; u8 pad[7]; char buf[64]; };
struct GObj { s32 count; GEnt e[256]; GRow rows[8]; };
struct GInfo { u16 h0; u8 b2; u8 b3; u16 h4; };
struct GItem { u32 f0, f4, f8; };
extern char D_003741e8[] asm("D_003741e8");
GInfo* func_001a80c8(u32) asm("func_001a80c8");
// table24_find_by_id
u32 func_001a3820(u32) asm("func_001a3820");
GItem* YS__COMMAND_ELEM__Get(u32) asm("YS__COMMAND_ELEM__Get");
s32 func_001a6598(u32) asm("func_001a6598");
void func_00259570(u32, char*, s32, s32) asm("func_00259570");
s32 func_002595e0(void) asm("func_002595e0");
void func_002595e8(char*, u32) asm("func_002595e8");
u32 func_00192048(u32) asm("func_00192048");
void func_00192cc0(char*, char*) asm("func_00192cc0");
u32 func_00259618(u32, char*, s32) asm("func_00259618");
void func_00192b30(u32) asm("func_00192b30");
/*TARGET 00282940*/
void func_00282940(GObj* obj, s32 start, s32 n) asm("func_00282940");
void func_00282940(GObj* obj, s32 start, s32 n) {
    for (s32 i = 0; i < n; i++) {
        s32 idx = i + start;
        s32 arg;
        if (idx >= obj->count) return;
        GInfo* info = func_001a80c8(obj->e[idx].id);  // table24_find_by_id
        u8 kind = info->b2;
        if (kind == 0 || kind == 18) {
            GItem* item = YS__COMMAND_ELEM__Get(func_001a3820(info->h0));
            u32 msg = item->f8;
            char* p = obj->rows[i].buf;
            if (info->b2 == 0) arg = obj->e[idx].b3 != 0;
            else arg = func_001a6598(info->h4) == 0;
            func_00259570(info->b2, p, arg, 1);
            p += func_002595e0();
            func_002595e8(p, func_00192048(msg));
        } else {
            func_00192b30(func_00259618(obj->e[idx].id, obj->rows[i].buf, obj->e[idx].b3 != 0));
        }
        arg = obj->e[idx].b2;
        if (arg != 1) func_00192cc0(obj->rows[i].name, D_003741e8);
        else obj->rows[i].name[0] = 0;
        obj->rows[i].flag = 0;
    }
}
}  // namespace n00282940

