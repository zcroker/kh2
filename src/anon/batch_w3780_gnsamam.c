// 002793b0 w3780: byte-identical under -O2 -g -fno-strict-aliasing -fmove-all-movables (try.sh 0 differences), but no _gnsamam suffix rule exists.
// Under _nsamam only the first jal delay slot differs (gcc fills it with sd s8; -g keeps the nop). Needs a Makefile rule: out/build/%_gnsamam.o: -g -fno-strict-aliasing -fmove-all-movables.
// Partial asm: lui pinned to t6 for the k-loop table reload; register pins t7 for t and m (-128).
// 002793b0 w2502 best. Under -O2 -g -fno-strict-aliasing -fmove-all-movables: 96 normalized (length +2 from one extra andi 0xffff; otherwise only s5/s6 swap). New: c reused as n, base->r[row][k] rows struct (+0x5F0, 48 u16/row) indexed in the k loop, idx = sel-1; if (sel!=7) idx=sel; (gives xori/addiu/movn), row = idx-1 variable (keeps addiu -1 before mult), r0/r1 separate locals (fixes a1/a2 order).
// BUT -fmove-all-movables also hoists li 2 / li 1 / li -128 that the original keeps in the loop and adds the andi 0xffff: orig probably NOT move-all; its 3 and -1 hoists likely come from matched movables (savings 2). Next: col via one variable + shared store (orig crossjumps case 0/3 tails into one sb t6,16).
#include "../common/types.h"

u8* func_002859a0(void);
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
s32 func_001058e8(void);
u8* func_00189200(s32, s32);
u8* func_001a80c8(u16);
extern s32 D_0035f01c;
typedef struct Ent { u16 id; s8 on; s8 slot; s8 col; s8 x11; s8 x12; s8 kind; } Ent;
typedef struct Tbl { s16 mask; u8 pad[5]; s8 n; u8 pad2[4]; Ent e[1]; } Tbl;
extern Tbl* D_0035f230;
typedef struct Rows { u8 pad[0x5F0]; u16 r[1][48]; } Rows;

extern Tbl* D2_0035f230 asm("D_0035f230");
void func_002793b0(void) {
    u8* base = func_002859a0();
    s32 h;
    if (func_00287bc0() == 15) h = func_0028b040(D_0035f01c);
    else h = func_002570a0(15);
    s32 r0, r1;
    func_0027aed8(h, &r0, &r1);
    if (r0 != 1) return;
    s32 sel = -1;
    s32 c = 0;
    s32 i;
    s16 mask = D_0035f230->mask;
    for (i = 0; i < 16; i++) {
        u8 b = (mask >> i) & 1;
        if (b) {
            if (r1 == c) { sel = i; break; }
            c++;
        }
    }
    u8* p = func_00189200(func_001058e8() + 0x24F0, sel);
    s32 idx = sel - 1;
    if (sel != 7) idx = sel;
    s32 row = idx - 1;
    c = D_0035f230->n;
    for (i = 0; i < 24; i++) {
        if (((u16*)(p + 8))[i] & 0x7FFF) {
            D_0035f230->e[c].id = ((u16*)(p + 8))[i] & 0x7FFF;
            D_0035f230->e[c].on = ((u16*)(p + 8))[i] >> 15;
            D_0035f230->e[c].slot = i;
            switch (func_001a80c8(D_0035f230->e[c].id)[6]) {
            case 0: D_0035f230->e[c].col = 2; break;
            case 1: case 2: D_0035f230->e[c].col = 0; break;
            case 3: D_0035f230->e[c].col = 1; break;
            }
            D_0035f230->e[c].x11 = 0;
            Tbl* q = D_0035f230; register u32 h asm("$14"); asm("lui %0,0x36" : "=r"(h) : "r"(q));
            q->e[c].x12 = -1;
            register Tbl* t asm("$15") = *(Tbl**)(h - 3536);
            s32 k;
            for (k = 0; k < 48; k++) {
                if (((Rows*)base)->r[row][k] == t->e[c].id) break;
            }
            {register s32 m asm("$15"); t->e[c].kind = k < 48 ? (m = -128, m = k | m, m) : -1;}
            c++;
        }
    }
    D_0035f230->n = c;
}







