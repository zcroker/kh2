// 002e5fb8: empty asm uses (no code) keep s and the type byte live so registers come out as in the original.
#include "../common/types.h"
struct H18 { u8 pad[8]; u32 sz8; u16 sz12; u8 pad2[5]; u8 f13; };
struct P18 { u8 pad[5]; u8 type; };
struct W18 { u8 pad[0x90]; u64 a[16]; u8 pad2[0x1a0 - 0x110]; u64 b[16]; u8 pad3[0x220 - 0x220]; P18* src; H18* hdr; u8* p2; u8* p3; };
static inline u32 al18(u32 x, u32 a) { u32 m = x % a; return m ? x + (a - m) : x; }
extern "C" {
void func_002e5fb8(W18* w, P18* s) {
    w->src = s;
u8 t = s->type; u32 a = 16; if (t) { a = t == 1 ? 128 : 0; asm("" : : "r"(t)); }
    u32 p = (u32)s + 16; asm("" : : "r"(s));
    p = al18(p, a);
    H18* h = (H18*)p;
    w->hdr = h;
    p += 48;
    p = al18(p, a);
    p = p + h->sz12 - 48;
    p = al18(p, a);
    w->p2 = (u8*)p;
    p += h->sz8;
    p = al18(p, a);
    w->p3 = h->f13 < 4 ? 0 : (u8*)p;
    for (s32 i = 0; i < 16; i++) { w->a[i] = 0; w->b[i] = 0; }
}
}
