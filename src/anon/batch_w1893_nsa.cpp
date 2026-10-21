#include "../common/types.h"
struct O1893;
struct E1893;
typedef void (*Fn1893)(O1893*, u8*, E1893*);
struct H1893 { u32 x0; Fn1893 fn; };
struct E1893 { H1893* h; u16 off; u16 pad; u32 x8, xc; };
struct Hd1893 { u8 pad[0x20]; s32 x20; u16 x24; s16 n; E1893 e[1]; };
struct O1893 { u32 x0, x4; Hd1893** x8; s32 xc; };
struct G1893 { u8 pad[0xa8]; u64 xa8; };
extern "C" {
extern Fn1893 D_00354bb0[];
extern O1893* D_01d9e6e8;
extern G1893* D_01d9e6e0;
extern s32 D_01d9ea9c;
static inline s32 inL_w1893(Fn1893 f) {
    Fn1893* p = D_00354bb0;
    s32 r = 0;
    for (; *p != 0; p++) {
        if (f == *p) { r = 1; break; }
    }
    return r;
}
void func_001e8e28(void* a, O1893* o) {
    Hd1893* hd = *o->x8;
    u8** s = (u8**)((u8*)o + hd->x20);
    D_01d9e6e8 = o;
    for (s32 i = 0; i < hd->n; i++) {
        E1893* e = &hd->e[i];
        H1893* h = e->h;
        if (h != 0) {
            u8* p = *s;
            if (*(s32*)(p + e->off) == o->xc) { p += e->off; *s = p; }
            s++;
            Fn1893 f = h->fn;
            if (f != 0 && !inL_w1893(f)) f(o, p, e);
        }
    }
    if (D_01d9ea9c == 0 && (D_01d9e6e0->xa8 & 0xff0000ff00ULL) == 0) {
        o->xc += 0x1000;
        if (o->xc > 0x6fffffff) o->xc = 0x6ffff000;
    }
}

}
