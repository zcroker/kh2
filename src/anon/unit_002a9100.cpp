// Linked unit 0x002a9100-0x002a92a0 (jump table builder; was whole asm in src/anon/batch_w3874.s).
#include "../common/types.h"

namespace n002a9100 {
struct JmEnt { s8 id; s8 idx; u16 val; };
struct JmTable { s32 count; JmEnt e[192]; };
struct JmSrc { u16 id; u16 val; u8 pad[12]; };
struct JmData { u8 pad[8]; s32 count; s32 pad2; JmSrc src[1]; };
extern JmTable* D_0035f608 asm("D_0035f608");
JmData* JmInfo_GetData(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
void wtarget_002fde18(void*, u32, u32) asm("_Z16wtarget_002fde18jjjj");
s32 func_002a99c8(JmSrc*) asm("func_002a99c8");
/*TARGET 002a9100*/
// Builds the table from the usable source rows: a key row (idx -1, val 0) when the id changes, a group
// row (idx -1) when the val changes, then the row itself (idx = source index).
// Plain stores through the global, no helpers. The preheader order (move s7,s4 before li s6,-1) is the
// loop pass hoisting the compare's %hi(D_0035f608) in its first run, which this 70-insn loop only gets
// with -fmove-all-movables; the reloads after each store need -fno-strict-aliasing.
void func_002a9100(void) asm("func_002a9100");
void func_002a9100(void) {
    s32 n = 0;
    s32 i = 0;
    JmData* d = JmInfo_GetData(8);
    JmSrc* src = d->src;
    wtarget_002fde18(D_0035f608, 0, 0x304);
    for (; i < d->count; i++) {
        JmSrc* s = &src[i];
        if (func_002a99c8(s) == 0) continue;
        if (n == 0 || D_0035f608->e[n - 1].id != s->id) {
            D_0035f608->e[n].id = s->id;
            D_0035f608->e[n].idx = -1;
            D_0035f608->e[n].val = 0;
            n++;
        }
        if (D_0035f608->e[n - 1].val != s->val) {
            D_0035f608->e[n].id = s->id;
            D_0035f608->e[n].idx = -1;
            D_0035f608->e[n].val = s->val;
            n++;
        }
        D_0035f608->e[n].id = s->id;
        D_0035f608->e[n].idx = i;
        D_0035f608->e[n].val = s->val;
        n++;
    }
    D_0035f608->count = n;
}
}  // namespace n002a9100
