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
W1716SrcA* W1716_ctarget_00188fe0(void*, s32) asm("_Z31YS__SAVERAM_BATTLE__get_partramjjjj");
W1716SrcB* W1716_ctarget_00189200(void*, s32) asm("_Z31YS__SAVERAM_BATTLE__get_formramjjjj");

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
void u_tail0_00286628(void);  // 0x00286628: definition moved into src/anon/unit_002853b8.cpp

}
