#include "../common/types.h"
// w2441 (zl90 retry): built with -fno-strict-aliasing.
extern "C" {
u8* func_002a9d68();
struct W2441Ent { s8 slot; u8 f1; u8 pad[14]; };
struct W2441Hdr { u8 h[16]; W2441Ent e[1]; };
struct W2441Bits { u32 w[2]; };
struct W2441Rec { u8 pad[324]; W2441Bits b[1]; };
W2441Hdr* func_00294000(s32);

s32 func_002b3ac8(s8);
extern W2441Rec* D_0035f610;
struct W1595Ent { s8 kind; u8 pad[35]; };
struct W1595Hdr { s32 a, b, count, c; W1595Ent e[1]; };
struct W1595List { s32 a; s8 kind; u8 n; u16 pad; s16 list[1]; };
s32 func_002943b0(W1595Ent*);
s32 func_00276c18();
extern W1595List* D_0035f5ac;
void func_002ac678(s32 idx) {
    W2441Rec* base = (W2441Rec*)func_002a9d68();
    W2441Ent* e = func_00294000(9)->e;
    e += idx;
    s32 n = func_002b3ac8(e->f1 & 0xf);
    for (s32 i = 0; i < n; i++) { u32* s = D_0035f610->b[e->slot].w; u32 w = (u32)i >> 5; u32 m = 1 << (i & 31);
 if (s[w] & m) { u32* d = base->b[e->slot].w; if (!(d[w] & m)) d[w] |= m; } }
}

void func_0029ca50(void) { s32 i = 0; s32 n = 0; W1595Hdr* h = (W1595Hdr*)func_00294000(3); s8 k = D_0035f5ac->kind; W1595Ent* base = h->e;
 for (; i < h->count; i++) { W1595Ent* e = &base[i]; if (e->kind != k) continue; if (!func_002943b0(e) && !func_00276c18()) continue; D_0035f5ac->list[n++] = i; }
 D_0035f5ac->n = n; }
}
