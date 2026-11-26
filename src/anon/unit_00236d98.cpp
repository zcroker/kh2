// Linked unit 0x00236d98-0x00237068 (texture slot allocator; was whole asm in src/anon/batch_w3875.s).
#include "../common/types.h"

namespace n00236d98 {
struct Slot236 { u8 used; u8 pad[3]; s32 id; s32 count; s32 pad2; s32 x; s32 y; };
struct Obj236 { u8 pad[0x194]; s32 slotId; };
extern Slot236 D_0035e440[64] asm("D_0035e440");
extern s32 D_0035ea40 asm("D_0035ea40");
s32 func_00236490(Obj236*) asm("func_00236490");
void func_00236440(Obj236*, s32, s32) asm("func_00236440");
void func_002368b0(Obj236*) asm("func_002368b0");
/*TARGET 00236d98*/
// Gives the object a run of slots in the 64-entry table D_0035e440 (24-byte slots: used, id, run length).
// 1. Already owns a run (a used slot with the object's id): nothing to do.
// 2. First fit: a free slot followed by count - 1 slots that are not in use.
// 3. Otherwise free everything up to the end of the run that covers slot count - 1 and take slots 0..count-1.
// The first-fit loop walks a pointer for the "used" test next to the index. Two things in it are needed for
// the match and look odd: the explicit guard + do/while (the pointer must be set after the guard), and the
// dead `p = 0` after the loop. cse2 picks the register that is mentioned last in the insn chain as the copy
// source for the other three slot pointers in the loop preheader, and that has to be the test pointer, while
// its increment has to come before the others in the latch (experiments log F66_00236d98).
void func_00236d98(Obj236* obj) asm("func_00236d98");
void func_00236d98(Obj236* obj) {
    s32 d, e, g, i, j, k2, k1;
    s32 n;
    s32 last;
    Slot236* p;

    for (i = 0; i < 64;) {
        Slot236* s = &D_0035e440[i];
        s32 id = obj->slotId;
        if (s->used != 0) {
            if (s->id == id) return;
            i += s->count;
        } else {
            i++;
        }
    }

    n = (func_00236490(obj) * 64 + 0x1fff) / 0x2000;

    i = 0;
    if (i < 65 - n) {
        p = D_0035e440;
        do {
            if (p->used == 0) {
                for (j = 1; j < n; j++) {
                    if (D_0035e440[i + j].used == 1) goto next;
                }
                for (j = 0; j < n; j++) {
                    D_0035e440[i + j].used = 1;
                    D_0035e440[i + j].id = -1;
                    D_0035e440[i + j].count = n;
                }
                k1 = D_0035ea40;
                D_0035e440[i].id = k1;
                D_0035ea40 = k1 + 1;
                obj->slotId = k1;
                func_00236440(obj, D_0035e440[i].x, D_0035e440[i].y);
                func_002368b0(obj);
                return;
            }
        next:
            p++;
            i++;
        } while (i < 65 - n);
    }
    p = 0;

    for (d = 0; d < 65 - n;) {
        if (D_0035e440[d].used != 0) {
            e = D_0035e440[d].count;
            d += e;
            if (e >= n) break;
        } else {
            d++;
        }
    }
    d = n - 1;
    while (D_0035e440[d].id == -1) d--;
    last = d + D_0035e440[d].count - 1;
    for (i = 0; i <= last; i++) {
        D_0035e440[i].used = 0;
        D_0035e440[i].id = 0;
    }
    for (g = 0; g < n; g++) {
        D_0035e440[g].used = 1;
        D_0035e440[g].id = -1;
        D_0035e440[g].count = n;
    }
    k2 = D_0035ea40;
    D_0035e440[0].id = k2;
    D_0035ea40 = k2 + 1;
    obj->slotId = k2;
    func_00236440(obj, D_0035e440[0].x, D_0035e440[0].y);
    func_002368b0(obj);
}
}  // namespace n00236d98
