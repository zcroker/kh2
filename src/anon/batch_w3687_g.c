/* Built with -g: the originals leave a nop after the first jal / in the jr ra delay slot. */
#include "../common/types.h"

/* 16-byte packet node: tag word, link, two spare words. */
typedef struct PktNode3687 { u32 tag; struct PktNode3687* next; u32 w8; u32 wc; } PktNode3687;
/* One of 256 priority lists (circular, tail pointer at +8). */
typedef struct PktList3687 { u32 a; u32 b; PktNode3687* volatile tail; u32 c; } PktList3687;

extern PktList3687 D_01dac550[256];

/* Clears node n, writes its tag (count - 1, type 0x20000000) and links it after the tail of
   priority list pri (clamped to 0..255). Twin of func_0020e7a8 (batch_w3685_g.c). sq $0 zero
   store: hand asm. The empty asm keeps the list address from being scheduled above the tag
   store (partial asm, see asm_review.tsv). */
void func_0020e858(PktNode3687* n, s32 count, s32 pri) {
    PktList3687* l;
    asm volatile("sq $0, 0(%0)" : : "r"(n) : "memory");
    n->tag = (count - 1) | 0x20000000;
    asm volatile("");
    if (pri <= 0) pri = 0;
    if (pri > 255) pri = 255;
    l = D_01dac550;
    l = &l[pri];
    {
        PktNode3687* t = l->tail;
        PktNode3687* nx = t->next;
        t->next = n;
        n->next = nx;
    }
    l->tail = n;
}

u8* Tz_CmTop_GetListBuffer(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
void u_call4_00139d78(u8*) asm("_Z16u_call4_00139d78jjjj");
s32 Tz_MenuBase_GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 func_0027af58(void);
void Tz_Select_SetSequence(u8*, s32) asm("_ZN2Tz6Select11SetSequenceEz");
typedef struct SeqEntry3687 { s16 a, b, seq; } SeqEntry3687;
extern SeqEntry3687 D_00373e30[];

/* Refreshes the menu list buffer and starts its selection sequence (231 in mode 16, else
   from the table entry of the current item). The two register pins make the buffer copy
   into a0 come before the copy into s0 (partial asm, see asm_review.tsv). */
void func_0027aa10(void) {
    u8* t = Tz_CmTop_GetListBuffer();
    register u8* a asm("$4") = t;
    register u8* p asm("$16") = t;
    s32 n;
    u_call4_00139d78(a);
    if (Tz_MenuBase_GetMode() == 16) n = 231;
    else n = D_00373e30[func_0027af58()].seq;
    Tz_Select_SetSequence(p, n);
}
