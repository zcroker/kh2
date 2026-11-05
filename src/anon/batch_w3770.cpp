#include "../common/types.h"

extern "C" {

struct Save { u8 p0[80]; u32 a[3]; u32 b[1]; };
extern Save* D_0035f2e4;
Save* func_002859a0(void);
void* func_00258108(void);
void* func_002811b0(void*, s32);
s32 func_001b7818(void*);

static inline s32 bit(const u32* b, u32 i) { return (b[i >> 5] & (1 << (i & 31))) != 0; }

// 00287028: checks that every flag set in D_0035f2e4's bitsets is also set in the
// save data (first set: 80 bits or the one bit 'id'; second: 48 bits per entry
// for entries 1..3 or just entry 'mode'). Returns 1 when all are set, else 0.
s32 func_00287028(s32 mode_, s32 id)
{
    // register pin: without it gcc gives r the lower saved register (s2) and mode s3
    register s32 mode asm("$18") = mode_;
    s32 i;
    s32 r = 1;
    Save* s = func_002859a0();
    void* v = func_00258108();
    if (mode <= 0) {
        if (id < 0) {
            for (i = 0; i < 80; i++) {
                if (bit(D_0035f2e4->a, i)) {
                    r = bit(s->a, i);
                    if (!r) break;
                }
            }
        } else {
            u32 m = 1 << (id & 31);
            u32 k = ((u32)id >> 5) * 4;
            s32 t = 0;
            if (*(u32*)((u8*)D_0035f2e4 + k + 80) & m) t = (*(u32*)((u8*)s + k + 80) & m) != 0;
            r = t;
        }
        if (mode == 0) return r;
    }
    for (i = 1; i < 4; i++) {
        if (mode >= 0 && i != mode) continue;
        void* p = func_002811b0(v, i);
        if (!p) continue;
        s32 k = func_001b7818(p) - 2;
        s32 base = k * 48;
        for (s32 j = 0; j < 48; j++) {
            if (id >= 0 && j != id) continue;
            k = base + j;
            if (bit(D_0035f2e4->b, k)) {
                r = bit(s->b, k);
                if (!r) return r;
            }
        }
        if (!r) break;
    }
    return r;
}

}
