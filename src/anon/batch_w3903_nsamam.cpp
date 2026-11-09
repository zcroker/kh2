// func_0026ceb0: sets up five menu items (three with a running offset, two copying a template) and picks an icon id.
#include "../common/types.h"
extern "C" {
struct Big26c;
struct Item26c { u8 p0[0x18]; u8 sub[0x198 - 0x18]; union { Big26c* b; s32 v; } f198; u8 p19c[0x1b0 - 0x19c]; s32 state; };
struct Big26c { u8 p0[0xee8]; Item26c items[5]; u8 a[0x80]; u8 b[0x80]; };
extern Big26c* D_0035f0f4;
extern Big26c* D_f0f4b asm("D_0035f0f4");
extern u8* D_0035f034;
extern s32 D_0035ef68;
extern s32 D_0035ef64;
extern s32 D_0035f03c;
extern const s16 D_00373848[];
extern s32 D_0037383c;
extern s32 D_00373840;
extern s32 D_0035eeb8;
extern u16 D_00373858[];
void func_00257388(s32, s32);
void func_002571e0(s32);
s32 func_0023aa78(void*);
void func_0028d980(Item26c*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00138c68(Item26c*, s32, s32);
void func_0028dcc0(Item26c*, void*);
void func_0026d208(void);
s32 func_00192048(u32);
s32 func_00293bc0(void);
s32 func_001a8c78(s32, s32);
s32 func_001a8c10(s32, s32);
s32 func_001d6e60(void);
static inline void setState26c(Item26c* p) { p->state = 2; }
void func_0026ceb0(void)
{
    s32 i, j;
    s32 n;
    u8* o;
    func_00257388(0x846d, 1);
    func_002571e0(0);
    o = D_0035f034;
    n = func_0023aa78(o + 24);
    for (i = 0; i < 3; i++) {
        func_0028d980(&D_0035f0f4->items[i], 30023, D_0035ef68, D_0035ef64, D_0035f03c, D_00373848[i], -1, -1, 0);
        func_00138c68(&D_0035f0f4->items[i], 0, n);
        setState26c(&D_0035f0f4->items[i]);
        func_0028dcc0(&D_0035f0f4->items[i], o);
        n += func_0023aa78(D_0035f0f4->items[i].sub);
    }
    j = 0;
    i = 3;
    do {
        s32 a = D_0037383c, c = D_00373840; s32 v = i != 3 ? c : a;
        func_0028d980(&D_0035f0f4->items[i], 30023, D_0035ef68, D_0035ef64, D_0035f03c, D_00373848[i], -1, v, 0);
        func_0028dcc0(&D_0035f0f4->items[i], &D_0035f0f4->items[j]);
        setState26c(&D_0035f0f4->items[i]);
        i++; j++;
    } while (i < 5);
    func_0026d208();
    D_0035f0f4->items[0].f198.b = (Big26c*)D_0035f0f4->a;
    D_0035f0f4->items[1].f198.b = (Big26c*)D_0035f0f4->b;
    if (D_0035eeb8 == 2) {
        Item26c* p = &D_0035f0f4->items[2];
        p->f198.v = func_00192048(0xcc69);
    } else {
        s32 h = func_00293bc0();
        for (i = 0; i < 4; i++) {
            if (i && func_001a8c78(h, i)) {
                s32 k = func_001a8c10(h, i);
                u16 id = D_00373858[k];
                if (k == 15) id = func_001d6e60() ? 0xcc9f : id;
                Item26c* p = &D_f0f4b->items[2];
                p->f198.v = func_00192048(id);
            }
        }
    }
}
}
