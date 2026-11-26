// Linked unit 0x00148c50-0x00148ef0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../harata/libdk/aabbox.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00148c50 (was src/anon/batch_w3872.cpp)
namespace n00148c50 {
// func_00148c50: recursive tree query. Collects the triangles of a node whose group is k, k+1 or k-1
// and that pass both box tests into list[], then recurses into children that pass the box test.
//
// Partial inline asm (w3872, logged in asm_review.tsv). Strict-aliasing sched2 analysis: the original
// spills x and list into slots that conflict with the two prologue loads and the lh pair, while the cnt
// slot conflicts with nothing. The empty asms rebuild exactly that dependence chain:
// - xx is defined by an asm (input: incoming t1 and n, memory clobber), so reload stores x right after it
//   (sw t1,4(sp) after sw t4,8(sp)); the k2 tie (memory clobber) then keeps the lh pair after both stores.
// - k2 (pinned to the incoming t0) gives km in the loop-guard delay slot (addiu s8,t0,-1).
// - The empty asm read of kp/end in the loop raises their allocation priority (kp s7, end s2).
struct Box83 { u8 d[24]; };
struct Node83 { s16 child[8]; Box83 box; s16 first; s16 last; u8 pad[4]; };
struct Tri83 { u8 on; u8 b1; u8 grp; u8 b3; Box83 box; };
struct Sys83 { u8 d[1]; };
struct Tree83 {
    u8 pad0[4]; Node83* nodes; Tri83* tris; u8 pad1[560 - 12]; Sys83 sys; u8 pad2[0x5364 - 561]; u16* list;
};
s32 func_00144d10(Box83*, void*) asm("func_00144d10");
s32 func_00146730(Sys83*, Box83*) asm("func_00146730");
/*TARGET 00148c50*/
void func_00148c50(Tree83* t, s32 node, void* q, s32* cnt, s32 k, void* x) asm("func_00148c50");
void func_00148c50(Tree83* t, s32 node, void* q, s32* cnt, s32 k, void* x) {
    void* xin;
    void* xx;
    s32 kp = k + 1;
    Node83* n = &t->nodes[node];
    u16* list = t->list;
    asm("" : "=r"(xx) : "0"(xin), "r"(n) : "memory");
    register s32 k2 asm("$8");
    asm("" : "+r"(k2) : "r"(k) : "memory");
    s32 km = k2 - 1;
    s32 end = n->last;
    s32 i = n->first;
    for (; i < end; i++) {
        if (t->tris[i].on && func_00144d10(&t->tris[i].box, q)) {
            u8 g = t->tris[i].grp;
            asm("" : : "r"(kp), "r"(end));
            if (g == k || g == kp || g == km) {
                switch (func_00146730(&t->sys, &t->tris[i].box)) {
                case 0:
                    break;
                case 1:
                    list[(*cnt)++] = i;
                    break;
                case 2:
                    list[(*cnt)++] = i | 0x8000;
                    break;
                }
            }
        }
    }
    s32 j;
    for (j = 0; j < 8; j++) {
        s32 c = n->child[j];
        if (c == -1) break;
        if (func_00144d10(&t->nodes[c].box, q) == 1) func_00148c50(t, c, q, cnt, k, xx);
    }
}
}  // namespace n00148c50

// 00148e40 (was src/anon/batch_wcx.cpp)
namespace n00148e40 {
static inline u8* NextK(u8* n, u8* c) { if (!c) return *(u8**)(n + 240); return *(u8**)(c + 236); }
/*TARGET 00148e40*/
void func_00148e40(u32 ctx, u8* n, u8** out, s32* cnt) asm("func_00148e40");
void func_00148e40(u32 ctx, u8* n, u8** out, s32* cnt)
{
    u32 f = *(u32*)(n + 248);
    u32 a = f & 8;
    if (a || (f & 0x40)) out[(*cnt)++] = n;
    u8* c = 0;
    while ((c = NextK(n, c))) func_00148e40(ctx, c, out, cnt);
}
}  // namespace n00148e40

