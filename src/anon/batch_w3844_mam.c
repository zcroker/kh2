// 0029cdf8: rebuilds a list of up to 10 names: for each set bit i >= n of the list mask, looks up id (i-1, or 16 for bit 0),
// writes its name into names[k], links it to entry k and sets sprite k from D_00374ad4/ad0. Built with -fmove-all-movables (_mam).
#include "../common/types.h"
typedef struct Spr9cd { u8 pad[408]; } Spr9cd;
typedef struct Big9cd { u8 pad[0xa998]; Spr9cd spr[10]; } Big9cd;
typedef struct Lst9cd { s32 mask; u8 pad[260]; char names[10][64]; } Lst9cd;
typedef struct Ent9cd { u8 pad[408]; char* name; } Ent9cd;
Big9cd* func_002766d0(void);
s32 func_0028b038(u32);
void func_0028be78(u32, s32);
void func_00138c10(Spr9cd*, u32);
void func_002fde18(void*, s32, s32);
s32 func_0028afa8(u32);
s32 func_00295430(s32, s32);
s32 func_002954e0(s32);
s32 func_00192048(s32);
void func_00192c90(s32, char*);
void func_0028de08(s32, char*, s32);
Ent9cd* func_002891b8(u32, s32);
s32 func_002aa098(s32);
s32 func_002aa148(s32);
extern u32 D_0035f200;
extern u32 D_0035f214;
extern Lst9cd* D_0035f5ac;
extern u32 D_00374ad0;
extern u32 D_00374ad4;
void func_0029cdf8(void) {
    Big9cd* b = func_002766d0();
    s32 n = func_0028b038(D_0035f200);
    s32 i, k, cnt, v;
    func_0028be78(D_0035f214, n);
    for (i = 0; i < 10; i++) func_00138c10(&b->spr[i], 2);
    func_002fde18(D_0035f5ac->names, 0, 640);
    k = 0;
    cnt = func_0028afa8(D_0035f200);
    if (cnt >= 11) cnt = 10;
    i = 0;
    if (k < cnt) {
      Spr9cd* sp = b->spr;
      for (; i < 19 && k < cnt; i++) {
        if (i < n) continue;
        if ((u8)((u32)(D_0035f5ac->mask >> i) & 1)) {
            s32 id = i ? i - 1 : 16;
            s32 h = func_00295430(id, 1);
            v = func_002954e0(id);
            if (v) func_00192c90(func_00192048(h), D_0035f5ac->names[k]);
            else func_0028de08(h, D_0035f5ac->names[k], 64);
            func_002891b8(D_0035f200, k)->name = D_0035f5ac->names[k];
            if (v && func_002aa098(id)) {
                s32 r = func_002aa148(id);
                func_00138c10(sp, r ? D_00374ad4 : D_00374ad0);
                asm("" :: "r"(v)); /* no code: one more use of v so it outranks n for a saved register (v s7, n s8) */
            }
            k++;
            sp++;
        }
      }
    }
}
