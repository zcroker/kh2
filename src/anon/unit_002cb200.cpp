#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../taito/path.hpp"

// ---- 002cb200 from src/anon/batch_w1938_nsa.cpp
namespace n002cb200 {
struct W1938Info { u8 a; u8 b; u8 c[6]; s16 d; };
struct W1938Slot { s32 x0; s32 x4; s32 x8; u8 pad[0x1b0 - 12]; u32 flags; W1938Info info; u8 pad2[2]; };
struct W1938Mgr { W1938Slot slots[8]; s32 max; };
struct W1938Entry { u8 id; u8 type; u8 slot; u8 pad; };
struct W1938List { s32 x0; s32 count; W1938Entry e[1]; };
W1938List* func_002f1888(void) asm("func_002f1888");
s32 func_00196430(u8) asm("func_00196430");
W1938Info func_00196328(u8) asm("func_00196328");
s32 func_0019f880(u8, s32) asm("func_0019f880");
s32 func_002f18c8(W1938Entry*) asm("func_002f18c8");
s32 func_001964d8(u8) asm("func_001964d8");
s32 func_002cb200(W1938Mgr* m, s32 type, s32* out) asm("func_002cb200");
s32 func_002cb200(W1938Mgr* m, s32 type, s32* out) {
    s32 n;
    s32 i;
    W1938List* l = func_002f1888();
    n = 0;
    m->max = 0;
    for (i = 0; i < l->count; i++) {
        W1938Entry* e = &l->e[i];
        if (e->type == type) {
            s32 r = func_00196430(e->id);
            if (r) {
                if (m->max < e->slot) m->max = e->slot;
                W1938Slot* s = &m->slots[e->slot - 1];
                W1938Slot* t = &m->slots[e->slot];
                t[-1].flags |= 2;
                t[-1].info = func_00196328(e->id);
                t[-1].x0 = func_0019f880(s->info.b, type);
                s->x8 = func_002f18c8(e);
                if (r == 2) {
                    t[-1].flags |= 1;
                    s->x4 = func_001964d8(e->id);
                }
                n++;
            }
        }
    }
    *out = m->max;
    return n;
}
}  // namespace n002cb200

// ---- 002cb378 gap: C2 copy of the 0x2cb3f8 ctor
namespace n002cb378 {
struct E12w1672 { s32 key; s32 pad; s32 val; };
extern E12w1672 D_00361e70[9] asm("D_00361e70");
extern u8 D_00361ee8 asm("D_00361ee8");
void wp_ctor_w1672(u8*, u32, u32, u32, u32) asm("_ZN2YS10WORLDPOINT16GetDisableReasonEi");
s32 get_part_num_w1672(u8*) asm("_ZN2YS3OBJ12get_part_numEv");
void func_002cb378(u8* p, u32 a1, u32 a2) asm("func_002cb378");
void func_002cb378(u8* p, u32 a1, u32 a2) {
    wp_ctor_w1672(p, a1, 5, a2, 1);
    *(u32*)(p + 0x9fc) = 0;
    *(u32*)p = (u32)&D_00361ee8;
    s32 n = get_part_num_w1672(p);
    for (s32 i = 0; i < 9; i++) {
        if (n == D_00361e70[i].key) { *(s32*)(p + 0x9fc) = D_00361e70[i].val; break; }
    }
}
}  // namespace n002cb378

// ---- 002cb3f8 from src/anon/batch_w1672.cpp
namespace n002cb3f8 {
struct E12w1672 { s32 key; s32 pad; s32 val; };
extern E12w1672 D_00361e70[9] asm("D_00361e70");
extern u8 D_00361ee8 asm("D_00361ee8");
void wp_ctor_w1672(u8*, u32, u32, u32, u32) asm("_ZN2YS10WORLDPOINT16GetDisableReasonEi");
s32 get_part_num_w1672(u8*) asm("_ZN2YS3OBJ12get_part_numEv");
void func_002cb3f8(u8* p, u32 a1, u32 a2) asm("func_002cb3f8");
void func_002cb3f8(u8* p, u32 a1, u32 a2) {
    wp_ctor_w1672(p, a1, 5, a2, 1);
    *(u32*)(p + 0x9fc) = 0;
    *(u32*)p = (u32)&D_00361ee8;
    s32 n = get_part_num_w1672(p);
    for (s32 i = 0; i < 9; i++) {
        if (n == D_00361e70[i].key) { *(s32*)(p + 0x9fc) = D_00361e70[i].val; break; }
    }
}
}  // namespace n002cb3f8

// ---- 002cb478 gap: base call, then the 0x2cb4a0 update
namespace n002cb478 {
void dk__WM_OBJ___OVR_pre_exec(u8*) asm("dk__WM_OBJ___OVR_pre_exec");
void func_002cb4a0(u8*) asm("_Z13func_002cb4a0j");
void func_002cb478(u8* p) asm("func_002cb478");
void func_002cb478(u8* p) {
    dk__WM_OBJ___OVR_pre_exec(p);
    func_002cb4a0(p);
}
}  // namespace n002cb478

// ---- 002cb4a0 from src/anon/auto80_199_queue.cpp
namespace n002cb4a0 {
void func_002cb4a0(u32 a0) asm("_Z13func_002cb4a0j");
void func_002cb4a0(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_0016a070(a0);

    u8* p = &D_00361e70;
    u8* end = p + 108;

    while (1) {
        u32 t7 = *(u32*)p;
        if (v0 == t7) {
            u8* obj = func_001b6d70(*(u32*)(p + 4));                      
            if (*(u8*)obj < 2) {
                func_002c5608(s0);
                return;
            }
            func_002c5628(s0);
            return;
        }

        p = p + 12;
        if ((s32)(u32)p < (s32)(u32)end) {
            continue;
        }
        return;
    }
}
}  // namespace n002cb4a0

// ---- 002cb528 gap: getter
namespace n002cb528 {
s32 func_002cb528(u8* p) asm("func_002cb528");
s32 func_002cb528(u8* p) {
    return *(s32*)(p + 0x9fc);
}
}  // namespace n002cb528

// ---- 002cb530 from src/anon/tiny.cpp
namespace n002cb530 {
void func_002cb530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002cb530jjjj");
void func_002cb530(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n002cb530

