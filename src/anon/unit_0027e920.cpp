// Linked unit 0x0027e920-0x0027ee48 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/cmenu_ability.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_tutorial.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/obj2d.hpp"
#include "../tozawa/cmenu_config.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/simple_stat.hpp"

// 0027e920 (was src/anon/batch_w3769_mam.cpp)
namespace n0027e920 {
// Built with -fmove-all-movables: the two 5116 constants each inner loop's start offset is
// multiplied by stay in their own saved registers (s6/s7) hoisted out of the outer loop.
struct E27A { u8 d[0x1b4]; };
struct E27B { u8 d[0x198]; };
struct O27 { E27A a; E27B b[5]; E27A c[6]; u8 pad[24]; };
s32 func_00139d78(void*) asm("func_00139d78");
extern void* D_0035f244 asm("D_0035f244");
extern O27* D_0035f248 asm("D_0035f248");
/*TARGET 0027e920*/
// Returns the first nonzero func_00139d78 result over D_0035f244 and, for each of the four
// entries of D_0035f248, its a, b[0], b[1]/b[3], b[2]/b[4], then c[0]/c[3] .. c[2]/c[5].
s32 func_0027e920(void) asm("func_0027e920");
// Returns the first nonzero func_00139d78 result over D_0035f244 and, for each of the four
// entries of D_0035f248, its a, b[0], b[1]/b[3], b[2]/b[4], then c[0]/c[3] .. c[2]/c[5].
s32 func_0027e920(void)
{
    s32 i, j;
    s32 r = func_00139d78(D_0035f244);
    for (i = 0; i < 4 && r == 0; i++) {
        r = func_00139d78(&D_0035f248[i].a);
        if (r == 0) r = func_00139d78(&D_0035f248[i].b[0]);
        for (j = 0; j < 2 && r == 0; j++) {
            r = func_00139d78(&D_0035f248[i].b[j + 1]);
            if (r == 0) r = func_00139d78(&D_0035f248[i].b[j + 3]);
        }
        for (j = 0; j < 3 && r == 0; j++) {
            r = func_00139d78(&D_0035f248[i].c[j]);
            if (r == 0) r = func_00139d78(&D_0035f248[i].c[j + 3]);
        }
    }
    return r;
}
}  // namespace n0027e920

// 0027ea78 (was src/anon/auto80_199_queue.cpp)
namespace n0027ea78 {
/*TARGET 0027ea78*/
u32 func_0027ea78(void) asm("_Z13func_0027ea78v");
u32 func_0027ea78(void) {
    func_00139d78(D_0035f244);
    u32 v = *(u32*)(D_0035f244 + 388);
    s32 i = (s32)D_0035f24c;
    s32 off = i * 6;
    u32 p = (u32)&D_00374050 + off;
    s32 y = (s32)*(s16*)(p + 4);
    return ((v ^ (u32)y) == 0);
}
}  // namespace n0027ea78

// 0027ead0 (was src/anon/batch_w20.cpp)
namespace n0027ead0 {
void func_0028da70(void*, s32) asm("func_0028da70");
extern u8* D_0035f244 asm("D_0035f244");
extern s8 D_0035f24c asm("D_0035f24c");
struct E374050 { u8 pad[4]; s16 v; };
extern E374050 D_00374050[] asm("D_00374050");
/*TARGET 0027ead0*/
void func_0027ead0(void) asm("func_0027ead0");
void func_0027ead0(void) {
    func_0028da70(D_0035f244, D_00374050[D_0035f24c].v);
}
}  // namespace n0027ead0

// 0027eb10 (was src/anon/batch_w1606.cpp)
namespace n0027eb10 {
struct Ent { u8 pad0[0x694]; u8 g0[0x82c - 0x694]; u8 g1[0x13e4 - 0x82c]; char s0[8]; char s1[8]; char s2[8]; };
struct Sub { u8 pad[0xf]; u8 lv; };
struct Obj {
    s32 hp; s32 hpmax; u8 pad8[0x180 - 8]; s32 mp; s32 mpmax;
    u16 a188; u16 a18a; u16 a18c; u16 a18e; u8 pad190[0x1b0 - 0x190]; u8 b1b0; u8 b1b1;
    u8 pad1b2[0x244 - 0x1b2]; Sub* sub;
};
s32 func_00281100(s32) asm("func_00281100");
Obj* func_00281180(s32, s32) asm("func_00281180");
void func_00192cc0(char*, const char*, ...) asm("func_00192cc0");
void func_00239f18(f32, u8*) asm("func_00239f18");
extern s32 D_0035f010 asm("D_0035f010");
extern Ent* D_0035f248 asm("D_0035f248");
extern u8 D_0035f24d asm("D_0035f24d");
extern s8 D_0035f24e asm("D_0035f24e");
extern char D_00373fd8[] asm("D_00373fd8");
extern char D_00373fe0[] asm("D_00373fe0");
/*TARGET 0027eb10*/
void func_0027eb10(void) asm("func_0027eb10");
void func_0027eb10(void) {
    s32 n = D_0035f24e == 4 ? func_00281100(D_0035f010) : 1;
    s32 i;
    for (i = 0; i < n; i++) {
        s32 k = D_0035f24e;
        if (k == 4) k = i;
        Obj* o = func_00281180(D_0035f010, k);
        switch (D_0035f24d) {
        case 0:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->sub->lv);
            { s32 hm = o->hpmax; func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13ec), D_00373fe0, o->hp, hm); }
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13f4), D_00373fe0, o->mp, o->mpmax);
            func_00239f18((f32)o->hp / (f32)o->hpmax, D_0035f248[i].g0);
            func_00239f18((f32)o->mp / (f32)o->mpmax, D_0035f248[i].g1);
            break;
        case 1:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->a188);
            break;
        case 2:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->a18c);
            break;
        case 3:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->a18a);
            break;
        case 4:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->a18e);
            break;
        case 5:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->b1b1);
            func_00239f18((f32)o->b1b0 / 100.0f, D_0035f248[i].g0);
            break;
        }
    }
}
}  // namespace n0027eb10

// 0027ed48 (was src/anon/batch_w80.cpp)
namespace n0027ed48 {
// ---- unit 15 (good27e.cpp)
struct U15_IdMap { s16 val; s16 key; };
struct U15_IdMapTbl { U15_IdMap e[15]; };
extern const U15_IdMapTbl D_00374008 asm("D_00374008");
/*TARGET 0027ed48*/
s32 func_0027ed48(s32 key) asm("func_0027ed48");
s32 func_0027ed48(s32 key) {  // copy_static_data
    U15_IdMapTbl t = D_00374008;
    s32 i;
    s32 r = -1;
    for (i = 0; t.e[i].key >= 0; i++) {
        if (t.e[i].key == key) { r = t.e[i].val; break; }
    }
    return r;
}
}  // namespace n0027ed48

