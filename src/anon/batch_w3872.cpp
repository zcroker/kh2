#include "../common/types.h"

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

extern "C" {
s32 func_00144d10(Box83*, void*);
s32 func_00146730(Sys83*, Box83*);

void func_00148c50(Tree83* t, s32 node, void* q, s32* cnt, s32 k, void* x) {
    register void* xin asm("$9");
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
}
