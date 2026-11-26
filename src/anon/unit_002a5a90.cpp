// Linked unit 0x002a5a90-0x002a6e50.
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 002a5a90 (was src/anon/batch_wcx2.cpp)
namespace n002a5a90 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// 0x0027c700: definition moved into src/anon/unit_0027a6d8.cpp

// --------------------
extern s32 D_0035f200_2a5 asm("D_0035f200");
s32 func_00289380_x10095(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_002a6718() asm("func_002a6718");
void func_002a67a8() asm("func_002a67a8");
void func_002a4df8() asm("func_002a4df8");
void func_002a4e38() asm("func_002a4e38");
void func_002a5590() asm("func_002a5590");
void func_00287f90(s32) asm("func_00287f90");
void func_00287c30() asm("func_00287c30");
void func_0028af18_x10108(s32, s32) asm("func_0028af18");
s32 func_00276358() asm("func_00276358");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
void func_00276690(s32) asm("func_00276690");
void func_002766b0(s32) asm("func_002766b0");
void func_0028b1e8(s32, s32) asm("func_0028b1e8");
s32 func_00289310_x10116(s32) asm("func_00289310");
s32 func_00276398() asm("func_00276398");
void func_00275b60() asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
void func_002a6878() asm("func_002a6878");
s32 func_00287df0_2a5(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_002a6088(s32) asm("func_002a6088");
void func_002a4df0() asm("func_002a4df0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_002891e8_x10127(s32) asm("func_002891e8");
s32 func_0028b038_x10128(s32) asm("func_0028b038");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_00287da0() asm("func_00287da0");
void Tz__Jiminy__FadeOutHelp() asm("Tz__Jiminy__FadeOutHelp");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 002a5a90*/
void func_002a5a90() asm("func_002a5a90");
void func_002a5a90() {
    s32 r = func_00289380_x10095(D_0035f200_2a5);
    s32 a = func_00287cd0();
    func_00287bc0();
    if (a == 2) {
        if (func_002a6718()) {
            if (r != -1) {
                func_00287f90(0);
                func_002a67a8();
            }
            return;
        }
        func_002a4df8();
        func_00287c30();
        s32 s = func_00287bc0();
        func_0028af18_x10108(D_0035f200_2a5, 115);
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        func_00276690(0);
        func_002766b0(1);
        if (s == 37) {
            func_0028b1e8(D_0035f200_2a5, 1);
            func_002a4e38();
        } else if (s == 38) {
            func_002a5590();
        }
        return;
    }
    if (r != -1 || func_00289310_x10116(D_0035f200_2a5)) {
        if (!func_00276398()) {
            Tz__Jiminy__SetParentSeqNum(0, 2);
            func_00275b60();
        }
    }
    if (!a && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0_2a5(r, func_00289310_x10116(D_0035f200_2a5), 1, func_002a6878, 1))) {
        switch (r) {
        case -4: {
            s32 s = func_00287bc0();
            s32 n = func_002891e8_x10127(D_0035f200_2a5);
            func_002765e8(s, n, func_0028b038_x10128(D_0035f200_2a5));
            func_00287da0();
            break;
        }
        case -9: case -8: case -7: case -6: case -5: case -3: case -1:
            break;
        case -11: case -10:
            func_002a6088(r);
            func_002a4df0();
            Tz__Jiminy__SetParentSeqNum(r != -10, 1);
            func_00287c00(38);
            func_00287cc0(2);
            break;
        case -2:
            func_002a4df0();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(1, 1);
            func_00287c00(37);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002a5a90

// 002a5d30 (was src/anon/batch_wcx2.cpp)
namespace n002a5d30 {
// ---- 00295158
u8* func_00294000(u32) asm("func_00294000");
s32 func_00276c18() asm("func_00276c18");
// 0x0029fbf0: definition moved into src/anon/unit_0029f938.cpp
// ---- 002a5d30
s32 func_002944d0(u8*) asm("func_002944d0");
extern u8* D_0035f5ec asm("D_0035f5ec");
/*TARGET 002a5d30*/
void Tz__JmBattle__GetEnableLimit() asm("Tz__JmBattle__GetEnableLimit");
void Tz__JmBattle__GetEnableLimit() {
    s32 i = 0;
    s32 n = 0;
    u8* t = func_00294000(6);
    D_0035f5ec[0] = 0;
    u8* base = t + 16;
    for (; i < *(s32*)(t + 8); i++) {
        if (func_002944d0(base + i * 8) || func_00276c18()) {
            D_0035f5ec[n + 6] = i;
            n++;
        }
    }
    D_0035f5ec[0] = n;
}
}  // namespace n002a5d30

// 002a5df0 (was src/anon/batch_w2408.cpp)
namespace n002a5df0 {
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_00192cc0(u8*, u32*, ...) asm("func_00192cc0");
// 0x0027b248: definition moved into src/anon/unit_0027a6d8.cpp

struct W2408Name { u8 c[16]; };
struct W2408Rec { u16 h0; u16 h2; };
u8* func_002766d0(void) asm("func_002766d0");
s32 func_0028b038(s32) asm("func_0028b038");
void Tz__ScrollBar__SetPos(s32, s32) asm("Tz__ScrollBar__SetPos");
void func_002fde18(u8*, s32, s32) asm("func_002fde18");
W2408Rec* func_002a6368(s32) asm("func_002a6368");
s32 func_002944d0(W2408Rec*) asm("func_002944d0");
s32 func_001d44d8(u16) asm("func_001d44d8");
s32 func_001d4550(s32) asm("func_001d4550");
s32 func_00192048(u16) asm("func_00192048");
void func_00192c90(s32, u8*) asm("func_00192c90");
void Tz__MenuUtil__MakeQuestionStr(u16, u8*, s32) asm("Tz__MenuUtil__MakeQuestionStr");
u8* func_002891b8(s32, s32) asm("func_002891b8");
s32 func_00192b30(s32) asm("func_00192b30");
s32 func_002aaa38(s32) asm("func_002aaa38");
s32 func_002aaab8(s32) asm("func_002aaab8");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f214 asm("D_0035f214");
extern u8* D_0035f5ec asm("D_0035f5ec");
extern u32 D_00374ba8 asm("D_00374ba8");
extern s32 D_00374bd8 asm("D_00374bd8");
extern s32 D_00374bdc asm("D_00374bdc");
/*TARGET 002a5df0*/
void func_002a5df0(void) asm("func_002a5df0");
void func_002a5df0(void) {
    s32 n = 10;
    u8* w = func_002766d0();
    s32 start = func_0028b038(D_0035f200);
    Tz__ScrollBar__SetPos(D_0035f214, start);
    func_002fde18(D_0035f5ec + 0x1f, 0, 160);
    func_002fde18(w + 0x110a0, 0, 640);
    s32 c = *(s8*)D_0035f5ec;
    if (c < 10) n = c;
    for (s32 j = 0; j < n; j++) func_00138c10(w + j * 408 + 0xa998, 2);
    s32 k = 0;
    s32 i = 0;
    n = *(s8*)D_0035f5ec;
    if (n > 0) do {
        if (i < start) continue;
        W2408Rec* r = func_002a6368(((s8*)D_0035f5ec)[i + 6]);
        s32 ok = func_002944d0(r);
        u16 id = r->h2;
        s32 v;
        if (ok) {
            v = func_001d4550(func_001d44d8(r->h0));
            func_00192c90(func_00192048(id), w + k * 64 + 0x110a0);
        } else {
            v = 0;
            Tz__MenuUtil__MakeQuestionStr(id, w + k * 64 + 0x110a0, 64);
        }
        *(u8**)(func_002891b8(D_0035f200, k) + 0x198) = w + k * 64 + 0x110a0;
        s32 len = func_00192b30(func_00192cc0(((W2408Name*)(D_0035f5ec + 0x1f))[k].c, &D_00374ba8, v));
        func_00192c90(func_00192048(19206), &((W2408Name*)(D_0035f5ec + 0x1f))[k].c[len]);
        if (ok && func_002aaa38(((s8*)D_0035f5ec)[i + 6])) {
            v = func_002aaab8(((s8*)D_0035f5ec)[i + 6]) ? D_00374bdc : D_00374bd8;
            func_00138c10(w + k * 408 + 0xa998, v);
        }
        k++;
    } while (++i < n && k < 10);
}
}  // namespace n002a5df0

// 002a6088 (was src/anon/batch_w108.cpp)
namespace n002a6088 {
struct List2a6 {
    s8 count;
    u8 pad[5];
    s8 items[1];
};
extern List2a6* D_0035f5ec asm("D_0035f5ec");
s32 func_00276620(s32) asm("func_00276620");
s32 func_00276638(s32) asm("func_00276638");
s32 func_002a6368(s32) asm("func_002a6368");
s32 func_002944d0(s32) asm("func_002944d0");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_002a65d0(void) asm("func_002a65d0");
/*TARGET 002a6088*/
// Moves the list cursor to the next/previous selectable entry (wrapping) and scrolls the 10-row window.
void func_002a6088(s32 dir) asm("func_002a6088");
// Moves the list cursor to the next/previous selectable entry (wrapping) and scrolls the 10-row window.
void func_002a6088(s32 dir)
{
    s32 top = func_00276620(37);
    s32 cur = func_00276638(37);
    s32 i;

    if (dir == -10) {
        for (i = cur + 1; i < D_0035f5ec->count; i++) {
            if (func_002944d0(func_002a6368(D_0035f5ec->items[i]))) break;
        }
        if (i >= D_0035f5ec->count) {
            for (i = 0; i < cur; i++) {
                if (func_002944d0(func_002a6368(D_0035f5ec->items[i]))) break;
            }
        }
        if (i < D_0035f5ec->count) {
            cur = i;
        } else {
            cur = 0;
            top = 0;
        }
    } else {
        for (i = cur - 1; i >= 0; i--) {
            if (func_002944d0(func_002a6368(D_0035f5ec->items[i]))) break;
        }
        if (i < 0) {
            for (i = D_0035f5ec->count - 1; i > cur; i--) {
                if (func_002944d0(func_002a6368(D_0035f5ec->items[i]))) break;
            }
        }
        cur = i;
        if (i < 0) {
            cur = D_0035f5ec->count - 1;
            top = D_0035f5ec->count - 11;
        }
    }
    if (cur - top >= 10) {
        top += cur - top - 9;
    } else if (cur - top < 0) {
        top += cur - top;
    }
    func_002765e8(37, cur - top, top);
    func_002a65d0();
}
}  // namespace n002a6088

// 002a6290 (was src/anon/batch_w49.cpp)
namespace n002a6290 {
// 0x0029dd00: definition moved into src/anon/unit_0029d008.cpp

extern s8* D_0035f5ec asm("D_0035f5ec");
u32 func_002a6368(s32) asm("func_002a6368");
s32 func_002944d0(u32) asm("func_002944d0");
/*TARGET 002a6290*/
s32 func_002a6290(void) asm("func_002a6290");
s32 func_002a6290(void) {
    s32 n = 0;
    for (s32 i = 0; i < D_0035f5ec[0]; i++)
        if (func_002944d0(func_002a6368(D_0035f5ec[6 + i]))) n++;
    return n;
}
}  // namespace n002a6290

// 002a6308 (was src/anon/batch_w49.cpp)
namespace n002a6308 {
extern "C" u32 D_0035f200, D_0035f214;
u32 func_0028b038(u32) asm("func_0028b038");
void Tz__ScrollBar__SetPos(u32, u32) asm("Tz__ScrollBar__SetPos");
void func_002a5df0(void) asm("func_002a5df0");
void func_002a65d0(void) asm("func_002a65d0");
/*TARGET 002a6308*/
void func_002a6308(u32, s32 m) asm("func_002a6308");
void func_002a6308(u32, s32 m) {
    switch (m) {
    case 37:
        func_002a5df0();
        func_002a65d0();
        break;
    case 38:
        Tz__ScrollBar__SetPos(D_0035f214, func_0028b038(D_0035f200));
        break;
    }
}
}  // namespace n002a6308

// 002a6368 (was src/anon/batch_w19.cpp)
namespace n002a6368 {
u8* func_00294000(s32) asm("func_00294000");
/*TARGET 002a6368*/
// 0x002a0360: definition moved into src/anon/unit_0029f938.cpp

u8* func_002a6368(s32 i) asm("func_002a6368");
// 0x002a0360: definition moved into src/anon/unit_0029f938.cpp

u8* func_002a6368(s32 i) {
    u8* b = func_00294000(6) + 16;
    return b + i * 8;
}
}  // namespace n002a6368

// 002a63a0 (was src/anon/batch_w1601.cpp)
namespace n002a63a0 {
// ---- a.cpp
struct Gw2a63a0 { u8 pad[2]; s8 col; u8 pad3; u16 id; };
struct Rc2a63a0 { u8 pad[20]; s32 w; };
extern void *D_0035f200 asm("D_0035f200");
extern u8 *D_0035f224 asm("D_0035f224");
extern Gw2a63a0 *D_0035f5ec asm("D_0035f5ec");
u8 *func_002766d0(void) asm("func_002766d0");
s32 func_0028b040(void *a) asm("func_0028b040");
void func_0014b950(void *p, s16 x, s16 y, u16 w, u16 c) asm("func_0014b950");
void func_0014b9a8(void *p) asm("func_0014b9a8");
s32 func_0023aa58(void *p) asm("func_0023aa58");
s32 func_0023aa78(void *p) asm("func_0023aa78");
Rc2a63a0 *func_001aae68(s32 a) asm("func_001aae68");
s32 func_00192048(u16 id) asm("func_00192048");
void YS__MESSAGEDRAW__MESSAGEDRAW(void *t, s32 a, s32 b, s32 c, s32 d) asm("YS__MESSAGEDRAW__MESSAGEDRAW");
void YS__MESSAGEDRAW__set_line_space(void *t, s32 w) asm("YS__MESSAGEDRAW__set_line_space");
void YS__MESSAGEDRAW__draw(void *t, s32 x, s32 y, s32 z) asm("YS__MESSAGEDRAW__draw");
/*TARGET 002a63a0*/
void Tz__JmBattle__DrawMess(s32 x, s32 y, s32 z) asm("Tz__JmBattle__DrawMess");
void Tz__JmBattle__DrawMess(s32 x, s32 y, s32 z)
{
  u8 buf[96];
  s32 lo = 15;
  u8 *ent;
  s32 sc;
  s32 *new_var;
  s32 a;
  s32 b;
  ent = func_002766d0() + 24;
  sc = func_0028b040(D_0035f200);
  func_0014b950(D_0035f224 + 32, x, y, 512 - x, D_0035f5ec->col * 9);
  func_0014b9a8(D_0035f224 + 32);
  a = func_0023aa58(ent);
  b = func_0023aa78(ent);
  if (a)
  {
    lo = a;
  }
  sc *= b;
  {
    Rc2a63a0 *r = func_001aae68(3);
    b -= lo;
    y -= sc;
    b -= r->w;
  }
  if (b < 0)
  {
    b = 0;
  }
  YS__MESSAGEDRAW__MESSAGEDRAW(buf, 3, func_00192048(D_0035f5ec->id), lo, 0);
  YS__MESSAGEDRAW__set_line_space(buf, b);
  YS__MESSAGEDRAW__draw(buf, x, *(new_var = &y), z);
  func_0014b9a8(D_0035f224);
}
}  // namespace n002a63a0

// 002a6500 (was src/anon/batch_w8018.c)
namespace n002a6500 {
typedef struct E8 { u32 a, b; } E8;
typedef struct H { u8 p[8]; s32 n; u32 pad; E8 e[1]; } H;
H* func_00294000(s32) asm("func_00294000");
s32 func_002944d0(E8*) asm("func_002944d0");
s32 func_00276c18(void) asm("func_00276c18");
/*TARGET 002a6500*/
// 0x00279860: definition moved into src/anon/unit_002793b0.cpp

s32 func_002a6500(void) asm("func_002a6500");
// 0x00279860: definition moved into src/anon/unit_002793b0.cpp

s32 func_002a6500(void) {
    s32 i; s32 r = 0;
    H* h = func_00294000(6);
    E8* e = h->e;
    for (i = 0; i < h->n; i++) if (func_002944d0(&e[i])) { r = 1; break; }
    if (func_00276c18()) r = 1;
    return r;
}
}  // namespace n002a6500

// 002a65a0 (was src/anon/batch_w6.cpp)
namespace n002a65a0 {
// 0x00288018: definition moved into src/anon/unit_00286d28.cpp

u32 func_00287bc0(void) asm("func_00287bc0");
void func_00276c50(u32, u32) asm("func_00276c50");
/*TARGET 002a65a0*/
void func_002a65a0(void) asm("func_002a65a0");
void func_002a65a0(void) {
    func_00276c50(func_00287bc0() == 0x25 ? 18680 : 19200, 0);
}
}  // namespace n002a65a0

// 002a65d0 (was src/anon/batch_w3743_g.cpp)
namespace n002a65d0 {
extern s32 D_0035f200 asm("D_0035f200");
struct L { u8 pad[6]; s8 items[1]; };
extern L *D_0035f5ec asm("D_0035f5ec");
struct Sram { u8 pad[132]; u32 bits[8]; };
struct Ent { u8 pad[408]; };
struct Seq { u8 pad[0xa998]; Ent e[4]; };
Sram *func_002a9d68(void) asm("func_002a9d68");
Seq *func_002766d0(void) asm("func_002766d0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_00276638(s32) asm("func_00276638");
s32 func_002a6368(s32) asm("func_002a6368");
s32 func_002944d0(s32) asm("func_002944d0");
void func_002aab90(s32) asm("func_002aab90");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_00139d78(Ent *) asm("func_00139d78");
void func_00138c10(Ent *, s32) asm("func_00138c10");
/*TARGET 002a65d0*/
void func_002a65d0(void) asm("func_002a65d0");
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
}  // namespace n002a65d0

// 002a6718 (was src/anon/batch_w59.cpp)
namespace n002a6718 {
// 0x0027db58: definition moved into src/anon/unit_0027d2e8.cpp

// --- 002a6718
u32 func_00276368(void) asm("func_00276368");
u32 func_0028acc8(u32) asm("func_0028acc8");
u32 func_00276888(void) asm("func_00276888");
u32 func_00139d78(u8*) asm("func_00139d78");
extern u32 D_0035f200 asm("D_0035f200");
extern u8* D_0035f5f0 asm("D_0035f5f0");
/*TARGET 002a6718*/
void func_002a6718(void) asm("func_002a6718");
void func_002a6718(void) {
    if (func_00276368()) return;
    if (func_0028acc8(D_0035f200)) return;
    if (func_00276888()) return;
    s32 i;
    for (i = 0; i < 10; i++) {
        if (func_00139d78(D_0035f5f0 + i * 436)) return;
    }
}
}  // namespace n002a6718

// 002a67a8 (was src/anon/batch_w80.cpp)
namespace n002a67a8 {
struct U12_VObj;
struct U12_VObjVt { void* f[5]; void (*f20)(U12_VObj*); };
struct U12_VObj { U12_VObjVt* vt; };
extern u8* D_0035f5f0 asm("D_0035f5f0");
extern u32 D_0035f200 asm("D_0035f200");
extern u32 D_0035f214 asm("D_0035f214");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_0028abe0(u32) asm("func_0028abe0");
U12_VObj* func_00276348(void) asm("func_00276348");
s32 func_0028be58(u32) asm("func_0028be58");
void func_0028be18(u32) asm("func_0028be18");
void Tz__Jiminy__LeaveSeqTbl(void) asm("Tz__Jiminy__LeaveSeqTbl");
// Tz::JmBattle::LeaveAllInner
void w80_JmBattle_LeaveAllInner(void) asm("_ZN2Tz8JmBattle13LeaveAllInnerEv");
/*TARGET 002a67a8*/
void w80_JmBattle_LeaveAllInner(void) asm("_ZN2Tz8JmBattle13LeaveAllInnerEv");
void w80_JmBattle_LeaveAllInner(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        u32 off = i * 436;
        if (func_00139d78(D_0035f5f0 + off)) {
            U12_VObj* o = (U12_VObj*)(off + (u32)D_0035f5f0);
            o->vt->f20(o);
        }
    }
    if (func_0028acc8(D_0035f200)) func_0028abe0(D_0035f200);
    if (func_00139d78(func_00276348())) {
        U12_VObj* o = func_00276348();
        o->vt->f20(o);
    }
    if (func_0028be58(D_0035f214)) func_0028be18(D_0035f214);
    Tz__Jiminy__LeaveSeqTbl();
}
}  // namespace n002a67a8

// 002a6878 (was src/anon/batch_w45.cpp)
namespace n002a6878 {
s32 func_00287bc0(s32) asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
extern u32 D_0035f200 asm("D_0035f200");
extern u8* D_0035f5ec asm("D_0035f5ec");
u32 func_002a6368(s32) asm("func_002a6368");
s32 func_002944d0(u32) asm("func_002944d0");
/*TARGET 002a6878*/
s32 func_002a6878(s32 a0) asm("func_002a6878");
s32 func_002a6878(s32 a0) {
    if (a0 < 0) return 1;
    s32 r = func_00287bc0(a0);
    s32 ok;
    switch (r) {
    case 37: ok = func_002944d0(func_002a6368(*(s8*)(D_0035f5ec + func_0028b040(D_0035f200) + 6))) != 0; break;
    case 38: ok = 1; break;
    default: ok = 0; break;
    }
    return ok;
}
}  // namespace n002a6878

// 002a68e8 (was src/anon/batch_w1591_g.cpp)
namespace n002a68e8 {
s32 func_00103570() asm("func_00103570");
s32 func_001063c0(s32, s32) asm("func_001063c0");
void func_002907c0(s32, s32, s32) asm("func_002907c0");
void func_00324380(s32) asm("func_00324380");
extern s32 D_0035f5f4 asm("D_0035f5f4");
extern s32 D_0035f5f8 asm("D_0035f5f8");
extern s8 D_0035f5fc asm("D_0035f5fc");
extern s8 D_0035f5fd asm("D_0035f5fd");
/*TARGET 002a68e8*/
void Tz__JmSynthe__Init(void) asm("Tz__JmSynthe__Init");
void Tz__JmSynthe__Init(void) {
    s32 v = func_001063c0(0xE20, func_00103570());
    func_00324380(v);
    D_0035f5f4 = v;
    s32 s = func_001063c0(0x18, func_00103570());
    func_002907c0(s, func_00103570(), 10);
    D_0035f5f8 = s;
    D_0035f5fc = -1;
    D_0035f5fd = -1;
}
}  // namespace n002a68e8

// 002a6970 (was src/anon/batch_wcx.cpp)
namespace n002a6970 {
// 0x00298ee0: definition moved into src/anon/unit_002982f0.cpp
extern u8* D_0035f5f4 asm("D_0035f5f4");
extern u8* D_0035f5f8 asm("D_0035f5f8");
extern s8 D_0035f5fc asm("D_0035f5fc");
extern s8 D_0035f5fd asm("D_0035f5fd");
void func_00106420(u8*) asm("func_00106420");
typedef void (*VFn)(u8*);
/*TARGET 002a6970*/
void func_002a6970(void) asm("func_002a6970");
void func_002a6970(void)
{
    u8* a = D_0035f5f4;
    if (a) {
        u8* q = a + 3488;
    loop:
        if (a == q) goto done;
        q -= 436;
        (*(VFn*)(*(u8**)q + 12))(q);
        goto loop;
    done:
        func_00106420(a);
        D_0035f5f4 = 0;
    }
    if (D_0035f5f8) { (*(VFn*)(*(u8**)D_0035f5f8 + 4))(D_0035f5f8); D_0035f5f8 = 0; }
    D_0035f5fc = -1;
    D_0035f5fd = -1;
}
}  // namespace n002a6970

// 002a6a10 (was src/anon/misc_2.cpp)
namespace n002a6a10 {
/*TARGET 002a6a10*/
void func_002a6a10(void* self) asm("_Z13func_002a6a10Pv");
void func_002a6a10(void* self) {}
}  // namespace n002a6a10

// 002a6a18 (was src/anon/tiny_auto80_queue.cpp)
namespace n002a6a18 {
void func_002a73d0(...) asm("func_002a73d0");
u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 002a6a18*/
void Tz__JmSynthe__LeaveAll() asm("_Z22Tz__JmSynthe__LeaveAllv");
void Tz__JmSynthe__LeaveAll() {
    if (func_00287bc0() == 39) {
        func_002a73d0();
        func_00274ac8();
    }
}
}  // namespace n002a6a18

// 002a6a50 (was src/anon/batch_w1946_g.cpp)
namespace n002a6a50 {
s32 func_00276348(void) asm("func_00276348");
s32 func_002766d0(void) asm("func_002766d0");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620(s32) asm("func_00139620");
void func_0028dcc0(s32, s32) asm("func_0028dcc0");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
s32 func_002891b8(s32, s32) asm("func_002891b8");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_00276690(s32) asm("func_00276690");
void func_0028af28(s32, s32) asm("func_0028af28");
void func_002a6e50(void) asm("func_002a6e50");
void func_002a7470(void) asm("func_002a7470");
void func_00287cc0(s32) asm("func_00287cc0");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f200 asm("D_0035f200");
/*TARGET 002a6a50*/
void Tz__JmSynthe__Setup(void) asm("Tz__JmSynthe__Setup");
void Tz__JmSynthe__Setup(void) {
    s16 buf[4];
    s32 i;
    s32 a = func_00276348();
    s32 b = func_002766d0();
    s32 n, c;
    if (func_0028f930(0) == 0) {
        func_0028f4d8(0, -1, 0);
    }
    for (i = 0; i < 4; i++) {
        buf[i] = 2;
    }
    n = D_0035f3d4;
    Tz__Jiminy__CreateCover();
    func_0028d8c0(b, n - 1, D_0035f14c, D_0035f148, D_0035f210, 101, -1, 0);
    func_00139620(b);
    func_0028dcc0(b, a);
    Tz__Select__SetItem(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, buf, buf);
    c = func_002891b8(D_0035f200, 0);
    func_00139620(c);
    func_0028dcc0(c, b);
    Tz__Select__SetCurrent(D_0035f200, 0, 0, -1, -1);
    func_00276690(1);
    func_0028af28(D_0035f200, 16);
    func_002a6e50();
    func_002a7470();
    func_00287cc0(0);
}
}  // namespace n002a6a50

// 002a6be0 (was src/anon/batch_w120.cpp)
namespace n002a6be0 {
// 00180f28: moved to src/yasui/libys/progress.cpp


extern u32 D_0035f200 asm("D_0035f200");
s32 func_00289380(u32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276368(void) asm("func_00276368");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_00276888(void) asm("func_00276888");
void func_00287f90(s32) asm("func_00287f90");
void Tz__JmSynthe__LeaveAll(void) asm("Tz__JmSynthe__LeaveAll");
s32 func_00292630(void) asm("func_00292630");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18(u32, s32) asm("func_0028af18");
void func_00276690(s32) asm("func_00276690");
s32 func_00276358(void) asm("func_00276358");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
void Tz__Jiminy__LoadData(s32) asm("Tz__Jiminy__LoadData");
// state_dispatch_0_1_2
void func_002925c0(void) asm("func_002925c0");
void func_002995e8(void) asm("func_002995e8");
s32 func_00289310(u32) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
// state_is_150
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
// record884_refresh_by_index
void func_002a6a10(void) asm("func_002a6a10");
void Tz__Jiminy__FadeOutHelp(void) asm("Tz__Jiminy__FadeOutHelp");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_0028b038(u32) asm("func_0028b038");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
/*TARGET 002a6be0*/
// Menu tick: handles the confirm/cancel states of this page.
void Tz__JmSynthe__Control(void) asm("Tz__JmSynthe__Control");
// Menu tick: handles the confirm/cancel states of this page.
void Tz__JmSynthe__Control(void)
{
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                Tz__JmSynthe__LeaveAll();
            }
            return;
        }
        if (func_00292630()) return;
        Tz__JmSynthe__LeaveAll();
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_00276690(0);
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        if (k != 13) return;
        Tz__Jiminy__LoadData(13);  // state_dispatch_0_1_2
        func_002925c0();
        func_002995e8();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        Tz__Jiminy__SetParentSeqNum(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, 0, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4:
            func_00287da0();
            break;
        case -2: {
            Tz__SelHist__FadeOut(0);  // record884_refresh_by_index
            func_002a6a10();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002a6be0

// 002a6e50 (was src/anon/batch_w3913.s)
namespace n002a6e50 {
u8* func_001058e8(void) asm("func_001058e8");
u8* func_002766d0(void) asm("func_002766d0");
s32 Tz__JmSynthe__isEnableRecipe(void) asm("Tz__JmSynthe__isEnableRecipe");
s32 Tz__JmSynthe__isEnableMaterial(void) asm("Tz__JmSynthe__isEnableMaterial");
s32 func_00276c18(void) asm("func_00276c18");
void func_002abdc8(void) asm("func_002abdc8");
s32 func_002adf60(s32) asm("func_002adf60");
s32 func_002abc60(s32) asm("func_002abc60");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00139620(u8*) asm("func_00139620");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
s32 func_00192048(s32) asm("func_00192048");
s32 func_00192c40(s32, u8*) asm("func_00192c40");
s32 func_00192cc0(u8*, const void*, ...) asm("func_00192cc0");
void fmtv_00192cc0(u8*, const void*, ...) asm("func_00192cc0");
extern u8* D_0035f5f4 asm("D_0035f5f4");
extern s8 D_0035f5fc asm("D_0035f5fc");
extern s8 D_0035f5fd asm("D_0035f5fd");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_00374bf0 asm("D_00374bf0");
extern s32 D_00374bf4 asm("D_00374bf4");
extern u16 D_00374bf8[] asm("D_00374bf8");
extern u16 D_00374c00[] asm("D_00374c00");
extern char D_00374be0[] asm("D_00374be0");
extern char D_00374be8[] asm("D_00374be8");

static inline u8*& Tb() { return D_0035f5f4; }
void func_002a6e50(void) asm("func_002a6e50");
void func_002a6e50(void)
{
    s32 i = 0;
    s32 c1 = 0;
    u8* sv = func_001058e8() + 0x49f4;
    u8* seq = func_002766d0();
    s32 a = Tz__JmSynthe__isEnableRecipe();
    s32 b = Tz__JmSynthe__isEnableMaterial();
    s32 full = func_00276c18();
    s32 c2, c3, en, row, n;
    u8* o;
    u8* p;
    s32 cr, x, y;
    u16* tbl;
    for (; i < 60; i++)
        if (((u32*)sv)[(u32)i >> 5] & (1 << (i & 31))) c1++;
    c2 = 0;
    i = 0;
    u32* bp = (u32*)(sv + 8);
    for (; i < 64; i++)
        if (bp[(u32)i >> 5] & (1 << (i & 31))) c2++;
    c3 = 0;
    i = 0;
    bp = (u32*)(sv + 28);
    for (; i < 59; i++)
        if (bp[(u32)i >> 5] & (1 << (i & 31))) c3++;
    i = 0;
    func_002abdc8();
    row = 0;
    n = D_0035f3d4;
    do {
        if (i == 0 || i == 3) en = a;
        else en = b;
        if (en || full) {
            o = Tb() + row * 872;
            s32 col = func_002adf60(i) ? D_00374bf4 : D_00374bf0;
            u8* q = o + 24;
            func_0028d980(o, n, D_0035f14c, D_0035f148, D_0035f210, col, -1, -1, 0);
            cr = func_0023aa78(q);
            x = func_0023aa18(q);
            y = func_0023aa38(q);
            func_00139620(o);
            func_00138c68(o, 0, cr * row);
            func_0028dcc0(o, seq);
            *(s32*)(o + 428) = 3;
            *(u32*)(o + 420) = 0x60000008;
            if (en) {
                if (i == 0) {
                    p = D_0035f5f4 + row * 32 + 0xda0;
                    *(u8**)(o + 408) = p;
                    func_00192cc0(p + func_00192c40(func_00192048(D_00374bf8[0]), p), D_00374be0, sv[576] + 1);
                } else {
                    *(s32*)(o + 408) = func_00192048(D_00374bf8[i]);
                }
                s32 off = row * 872;
                o = D_0035f5f4 + off + 436;
                func_0028d980(o, n, D_0035f14c, D_0035f148, D_0035f210, 2, -1, -1, 0);
                func_00139620(seq);
                func_00138c68(o, x, y);
                func_0028dcc0(o, D_0035f5f4 + off);
                *(s32*)(o + 432) = 1;
                *(s32*)(o + 428) = 3;
                *(u32*)(o + 420) = 0x60000008;
                if (i == 0) {
                    *(s32*)(o + 408) = func_00192048(D_00374c00[sv[576]]);
                } else {
                    s32 v;
                    s32 m;
                    p = D_0035f5f4 + row * 32 + 0xda0;
                    *(u8**)(o + 408) = p;
                    if (i == 1) {
                        v = c1;
                        m = 60;
                    } else if (i == 2) {
                        v = c2;
                        m = D_0035f5fc;
                    } else {
                        v = c3;
                        m = D_0035f5fd;
                    }
                    if (full) fmtv_00192cc0(p, D_00374be8, v, m);
                    else func_00192cc0(p, D_00374be0, v, m);
                }
            } else if (full) {
                *(s32*)(o + 408) = func_00192048(0x36f8);
            }
            p = seq + row * 408 + 0xa998;
            func_0028d8c0(p, n + 2, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
            func_0028dcc0(p, o);
            if (en && func_002abc60(i)) func_00138c10(p, 58);
            row++;
        }
        i++;
    } while (i < 4);
}
}  // namespace n002a6e50
