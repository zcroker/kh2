#include "../common/types.h"

// Relocation fixup for a block of six offset tables: header at a1 (source) and a0 (destination).
// Counts are full-width bitfields: their alias set is the whole header, so the u32 stores
// below force a reload of the count every iteration, as in the original.
typedef struct RelocHdr3780 {
    u32 pad0;
    u32 o4, o8, oc, o10, pad14[3], o20, o24;
    u8 pad28[0x1a];
    u16 n42:16, n44:16, n46:16, n48:16, pad4a[3], n50:16, n52:16;
} RelocHdr3780;
typedef struct RelocE32_3780 { u32 pad[5]; u32 p; u32 pad2[2]; } RelocE32_3780;
typedef struct RelocE16_3780 { u32 pad; u32 p; u32 pad2[2]; } RelocE16_3780;

void wtarget_0020edd0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_0020edd0jjjj");
void wtarget_0020edd0(u32 a0, u32 a1, u32 a2, u32 a3)
{
    RelocHdr3780* d = (RelocHdr3780*)a0;
    RelocHdr3780* s = (RelocHdr3780*)a1;
    s32 i;
    u32* dst;
    if (a1 & 0xf) *(volatile s32*)0 = 0;
    // First count read as a plain u16 (other alias set), so gcse does not share it with the loop test.
    if (((u16*)a1)[33]) {
        u32* src = (u32*)(s->o4 + a1);
        u32* d1 = (u32*)(d->o4 + a0);
        i = 0;
        if (i < s->n42) {
            // Pins: the walking pointer in t2 as a copy of the base, t3 kept free during the loop.
            register u32* w asm("$10") = d1;
            register s32 ph asm("$11");
            asm("" : "+r"(d1), "+r"(w), "=r"(ph));
            for (; i < s->n42; i++) {
                u32 v = *src++;
                if (v) *w = v + a1;
                w++;
            }
            asm("" : : "r"(ph));
        }
    }
    if (s->n44) {
        u32* src = (u32*)(s->o8 + a1);
        RelocE32_3780* dp = (RelocE32_3780*)(d->o8 + a0);
        for (i = 0; i < s->n44; i++) {
            u32 v = *src++;
            if (v) dp->p = v + a1;
            dp++;
        }
    }
    if (s->n46) {
        u32* src = (u32*)(s->oc + a1);
        RelocE16_3780* dp = (RelocE16_3780*)(d->oc + a0);
        for (i = 0; i < s->n46; i++) {
            u32 v = *src++;
            if (v) dp->p = v + a1;
            dp++;
        }
    }
    if (s->n48) {
        u32* src = (u32*)(s->o10 + a1);
        dst = (u32*)(d->o10 + a0);
        for (i = 0; i < s->n48; i++) {
            u32 v = *src++;
            if (v) *dst = v + a1;
            dst++;
        }
    }
    if (s->n50) {
        u32* src = (u32*)(s->o20 + a1);
        dst = (u32*)(d->o20 + a0);
        for (i = 0; i < s->n50; i++) {
            u32 v = *src++;
            if (v) *dst = v + a1;
            dst++;
        }
    }
    if (s->n52) {
        u32* src = (u32*)(s->o24 + a1);
        dst = (u32*)(d->o24 + a0);
        for (i = 0; i < s->n52; i++) {
            u32 v = *src++;
            if (v) *dst = v + a1;
            dst++;
        }
    }
}
