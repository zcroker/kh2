// Built with -fno-strict-aliasing (_nsa).
#include "../common/types.h"

extern "C" {

struct W1716Sram {
    u8 pad[0x50];
    u32 bits0[3];
    u32 bits1[18];
    u32 bits2[11];
    u16 list0[80];
    u16 list1[12][48];
    u16 list2[6][48];
};
struct W1716Tbl { u32 hdr; u16 ids[80]; };
struct W1716SrcA { u8 pad[0x50]; W1716Tbl tbl; };
struct W1716SrcB { u8 pad[8]; u16 ids[80]; };

extern W1716Sram* D_0035f2e4;
W1716Sram* W1716_GetSram(void) asm("_ZN2Tz8CmNewFlg7GetSramEv");
u8* W1716_getSaveRam(void) asm("_Z10getSaveRamv");
W1716SrcA* W1716_ctarget_00188fe0(void*, s32) asm("_Z16ctarget_00188fe0jjjj");
W1716SrcB* W1716_ctarget_00189200(void*, s32) asm("_Z16ctarget_00189200jjjj");

static inline u32 W1716Test(u32* bits, u32 id) { return bits[id >> 5] & (1 << (id & 31)); }
static inline u32* W1716Bits(W1716Sram* s, s32 grp) {
    if (grp == 0) return s->bits0;
    if (grp == 1) return s->bits1;
    return s->bits2;
}
static inline void W1716MarkNew(W1716Sram* s, s32 grp, u32 bit) {
    if (W1716Test(W1716Bits(s, grp), bit) == 0) {
        u32* f = W1716Bits(D_0035f2e4, grp);
        f += bit >> 5;
        *f |= 1 << (bit & 31);
    }
}

// Tz::CmNewFlg: refresh the "new" flag lists in the save RAM (list0, 12 x list1, 6 x list2)
// from the current item tables and mark ids that changed.
void u_tail0_00286628(void) asm("_Z16u_tail0_00286628v");
void u_tail0_00286628(void) {
    s32 n, i, j, k, count, found;
    u32 bit;
    // id is pinned to t3: without the pin global-alloc gives it t1 and the k<count test t3.
    register u32 id asm("$11"); u16 idt;
    W1716Sram* s;
    W1716SrcA* a;
    W1716SrcB* b;
    s = W1716_GetSram();
    for (count = 0; s->list0[count] != 0 && count < 80; count++) {
    }
    a = W1716_ctarget_00188fe0(W1716_getSaveRam() + 0x24f0, 1);
    if (count < 80) {
        for (j = 0; (a->tbl.ids[j] & 0x7fff) && j < 80; j++) {
            if (count >= 80) break;
            idt = a->tbl.ids[j] & 0x7fff; id = idt;
            for (k = 0; k < count; k++) {
                if (s->list0[k] == id) break;
            }
            if (k >= count) { s->list0[count] = id; count++; }
        }
        for (j = 0; j < count; j++) {
            W1716MarkNew(s, 0, j);
        }
    }
    for (j = 0; j < count; j++) {
        bit = j;
        found = 0;
        for (k = 0; (a->tbl.ids[k] & 0x7fff) && k < 80; k++) {
            if (s->list0[j] == (a->tbl.ids[k] & 0x7fff)) {
                found = 1;
                break;
            }
        }
        if (!found) {
            if (W1716Test(s->bits0, bit) == 0) {
                u32* h = s->bits0;
                h += bit >> 5;
                *h |= 1 << (bit & 31);
            }
        }
    }

    for (n = 2, i = 0; n < 14; n++, i++) {
        count = 0;
        for (k = 0; k < 48; k++) {
            if (s->list1[i][k] == 0) break;
            count++;
        }
        a = W1716_ctarget_00188fe0(W1716_getSaveRam() + 0x24f0, n);
        if (count < 48) {
            for (j = 0; (a->tbl.ids[j] & 0x7fff) && j < 80; j++) {
                if (count >= 48) break;
                idt = a->tbl.ids[j] & 0x7fff; id = idt;
                for (k = 0; k < count; k++) {
                if (s->list1[i][k] == id) break;
            }
                if (k >= count) { bit = i * 48 + count; s->list1[0][bit] = id; count = -~count; }
            }
            for (j = 0; j < count; j++) {
                bit = i * 48 + j; W1716MarkNew(s, 1, bit);
            }
        }
        for (j = 0; j < count; j++) {
            bit = i * 48 + j;
            found = 0;
            for (k = 0; (a->tbl.ids[k] & 0x7fff) && k < 80; k++) {
                if (s->list1[i][j] == (a->tbl.ids[k] & 0x7fff)) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                
                if (W1716Test(s->bits1, bit) == 0) {
                    u32* h = s->bits1;
                    h += bit >> 5;
                    *h |= 1 << (bit & 31);
                }
            }
        }
    }

    for (n = 1, i = 0; n < 8; n++, i++) {
        if (n == 6) {
            i--;
            continue;
        }
        count = 0;
        for (k = 0; k < 48; k++) {
            if (s->list2[i][k] == 0) break;
            count++;
        }
        b = W1716_ctarget_00189200(W1716_getSaveRam() + 0x24f0, n);
        if (count < 48) {
            for (j = 0; (b->ids[j] & 0x7fff) && j < 24; j++) {
                if (count >= 48) break;
                idt = b->ids[j] & 0x7fff; id = idt;
                for (k = 0; k < count; k++) {
                if (s->list2[i][k] == id) break;
            }
                if (k >= count) { bit = i * 48 + count; s->list2[0][bit] = id; count = -~count; }
            }
            for (j = 0; j < count; j++) {
                bit = i * 48 + j; W1716MarkNew(s, 2, bit);
            }
        }
        for (j = 0; j < count; j++) {
            bit = i * 48 + j;
            found = 0;
            for (k = 0; (b->ids[k] & 0x7fff) && k < 80; k++) {
                if (s->list2[i][j] == (b->ids[k] & 0x7fff)) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                
                if (W1716Test(s->bits2, bit) == 0) {
                    u32* h = s->bits2;
                    h += bit >> 5;
                    *h |= 1 << (bit & 31);
                }
            }
        }
    }
}

}
