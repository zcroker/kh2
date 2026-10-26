#include "../common/types.h"
extern "C" {
struct E2b1 {
    u32 id:16;
    u32 kind:8;
    u32 a:1;
    u32 b:1;
    u32 c:1;
    u32 d:1;
    u32 e:1;
    u32 pad:3;
    char name[32];
};
struct S2b1 { u8 pad[0x34]; u32 lo:14; u32 cnt:4; u32 hi:14; };
struct H2b1 { u8 b0; u8 b1; u16 id; u16 w4; u8 pad[10]; };
struct T2b1 { s32 x0; s32 x4; s32 count; s32 xc; H2b1 e[1]; };
struct W2b1 { u8 pad[0x1e4]; u16 bits[2]; struct { s8 v; u8 p[3]; } q[1]; };
union U2b1 { E2b1* p; u32 u; };
extern U2b1 D_0035f630_u asm("D_0035f630");
#define D_0035f630 D_0035f630_u.p
extern S2b1* D_0035f638;
T2b1* func_00294000(s32);
W2b1* func_002a9d68(void);
void func_002fde18(void*, s32, s32);
s32 func_00276c18(void);
void* func_00192048(u32);
void func_00192c90(void*, char*);
void func_0028de08(u32, char*, s32);

void func_002b1db8(void) {
    u32 i;
    T2b1* t = func_00294000(9);
    H2b1* e = t->e;
    W2b1* w = func_002a9d68();
    D_0035f638->cnt = 0;
    func_002fde18(D_0035f630, 0, 0x168);
    u16* bits;
    for (i = 0; (s32)i < t->count; i++, e++) {
        bits = w->bits;
        s32 h = 24;
        s32 j = 0;
        s32 n = (e->b1 & 0xf) ? 48 : h;
        s32 found = 0;
        if (n) {
            s8* q = (s8*)((u32)(i * 192) + (u32)w + 488);
            do {
                if (*q >= 0) { found = 1; break; }
                q += 4;
                j++;
            } while (j < n);
        }
        D_0035f630[i].a = (found || func_00276c18()) ? 1 : 0;
        D_0035f630[i].b = found;
        if (D_0035f630[i].b) D_0035f638->cnt++;
        { s32 m = 1 << (i & 15); D_0035f630[i].c = (bits[i >> 4] & m) != 0; }
        D_0035f630[i].d = (e->b1 & 0xf) != 0;
        D_0035f630[i].e = (e->b1 & 0xf0) != 0;
        if (D_0035f630[i].b) func_00192c90(func_00192048(e->id), D_0035f630[i].name);
        else func_0028de08(e->id, D_0035f630[i].name, 32);
        D_0035f630[i].kind = e->b0;
        D_0035f630[i].id = e->w4;
    }
}
}

// 00323110: constructor of a large object (same family as 00322e58/00324510/003241a0):
// 4 x A (408 bytes), 4 x B (436 bytes), 3 x B[24], A[24], then a T of 3 B at +0xb350.
// The base-class vtable store (00347f98) is a plain void* store, the h0..h3 blocks share one
// loaded vtable address. Needs -fno-strict-aliasing.
extern "C" u8 D_00347e60[];
extern "C" u8 D_00347f98[];
extern "C" u8 D_00347e40[];
extern "C" void func_00239700(void*);
extern "C" void func_0031a838(void*);
inline void* operator new(unsigned int, void* p) { return p; }
inline void* operator new[](unsigned int, void* p) { return p; }
struct W2417_A {
    void* vt; u8 p4[8]; u32 f0c; u8 p10[8]; u8 m[384];
    W2417_A() { f0c = 0; vt = D_00347e60; func_00239700(m); }
};
struct W2417_B {
    void* vt; u8 p4[8]; u8 m0c[12]; u8 m[384]; u32 f198; u8 pad[24];
    W2417_B() { *(void**)this = D_00347f98; func_0031a838(m0c); vt = D_00347e60; func_00239700(m); vt = D_00347e40; f198 = 0; }
};
struct W2417_T { W2417_B b0, b1, b2; };
struct W2417_Big {
    W2417_A a0, a1, a2, a3;
    W2417_B h0, h1, h2, h3;
    W2417_B x[24]; W2417_B y[24]; W2417_B z[24];
    W2417_A w[24];
    u8 gap[1344];
    W2417_T p;
};
extern "C" {
void func_00323110(W2417_Big* p)
{
    void* va = D_00347f98;
    new (&p->a0) W2417_A; new (&p->a1) W2417_A; new (&p->a2) W2417_A; new (&p->a3) W2417_A;
    { W2417_B* h = &p->h0; *(void**)h = va; func_0031a838(h->m0c); h->vt = D_00347e60; func_00239700(h->m); h->vt = D_00347e40; h->f198 = 0; }
    { W2417_B* h = &p->h1; *(void**)h = va; func_0031a838(h->m0c); h->vt = D_00347e60; func_00239700(h->m); h->vt = D_00347e40; h->f198 = 0; }
    { W2417_B* h = &p->h2; *(void**)h = va; func_0031a838(h->m0c); h->vt = D_00347e60; func_00239700(h->m); h->vt = D_00347e40; h->f198 = 0; }
    { W2417_B* h = &p->h3; *(void**)h = va; func_0031a838(h->m0c); h->vt = D_00347e60; func_00239700(h->m); h->vt = D_00347e40; h->f198 = 0; }
    new (p->x) W2417_B[24]; new (p->y) W2417_B[24]; new (p->z) W2417_B[24]; new (p->w) W2417_A[24];
    new (&p->p) W2417_T;
}
}
