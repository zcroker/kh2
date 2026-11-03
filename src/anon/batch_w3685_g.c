/* Built with -g (the original leaves the jr ra delay slot empty after the last, volatile, store). */
#include "../common/types.h"

/* 16-byte packet node: tag word, link, two spare words. */
typedef struct PktNode347 { u32 tag; struct PktNode347* next; u32 w8; u32 wc; } PktNode347;
/* One of 16 priority lists (circular, tail pointer at +8). */
typedef struct PktList347 { u32 a; u32 b; PktNode347* volatile tail; u32 c; } PktList347;

extern PktList347 D_01dac450[16];
extern PktList347 D_01dad550[16];

/* Clears node n, writes its tag (count - 1, type 0x20000000) and links it after the tail of
   priority list pri (clamped to 0..15). sq $0 zero store: hand asm. The empty asm keeps the
   list address from being scheduled above the tag store (partial asm, see asm_review.tsv). */
void func_0020e7a8(PktNode347* n, s32 count, s32 pri) {
    PktList347* l;
    asm volatile("sq $0, 0(%0)" : : "r"(n) : "memory");
    n->tag = (count - 1) | 0x20000000;
    asm volatile("");
    if (pri <= 0) pri = 0;
    if (pri > 15) pri = 15;
    l = D_01dac450;
    l = &l[pri];
    {
        PktNode347* t = l->tail;
        PktNode347* nx = t->next;
        t->next = n;
        n->next = nx;
    }
    l->tail = n;
}

/* Same as func_0020e7a8 for the second list set. */
void func_0020e800(PktNode347* n, s32 count, s32 pri) {
    PktList347* l;
    asm volatile("sq $0, 0(%0)" : : "r"(n) : "memory");
    n->tag = (count - 1) | 0x20000000;
    asm volatile("");
    if (pri <= 0) pri = 0;
    if (pri > 15) pri = 15;
    l = D_01dad550;
    l = &l[pri];
    {
        PktNode347* t = l->tail;
        PktNode347* nx = t->next;
        t->next = n;
        n->next = nx;
    }
    l->tail = n;
}
