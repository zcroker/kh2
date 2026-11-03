#include "../common/types.h"
extern "C" {
extern s32 D_0035f200;
struct L { u8 pad[6]; s8 items[1]; };
extern L *D_0035f5ec;
struct Sram { u8 pad[132]; u32 bits[8]; };
struct Ent { u8 pad[408]; };
struct Seq { u8 pad[0xa998]; Ent e[4]; };
Sram *func_002a9d68(void);
Seq *func_002766d0(void);
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_00276638(s32);
s32 func_002a6368(s32);
s32 func_002944d0(s32);
void func_002aab90(s32);
s32 func_002891e8(s32);
s32 func_00139d78(Ent *);
void func_00138c10(Ent *, s32);

static inline __attribute__((always_inline)) Ent* at(Seq* b, s32 sz, s32 i) { return (Ent*)((u8*)b + i*sz + 0xa998); }
static inline __attribute__((always_inline)) Ent* at2(Seq* b, s32 i, s32 sz) { return (Ent*)((u8*)b + i*sz + 0xa998); }

void func_002a65d0(void)
{
  Sram *a = func_002a9d68();
  Seq *b = func_002766d0();
  s32 c = func_00287bc0();
  register s32 idx asm("$17");
  if (c == 37) idx = func_0028b040(D_0035f200);
  else idx = func_00276638(37);
  if (func_002944d0(func_002a6368(D_0035f5ec->items[idx]))) {
    s32 k = D_0035f5ec->items[idx];
    u32* q = &a->bits[(u32)k >> 5]; if (!(*q & (1 << (k & 31)))) {
      func_002aab90(k);
      if (c == 37) {
        register s32 sz asm("$16") = 408;
        s32 i = func_002891e8(D_0035f200);
        asm("mult %0,%1,%0" : "+r"(sz) : "r"(i));
        Ent *p = (Ent*)((u8*)b + sz + 0xa998);
        if (func_00139d78(p)) func_00138c10(p, 58);
      }
    }
  }
}
}
