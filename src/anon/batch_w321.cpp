#include "../common/types.h"

namespace w321 {
struct V16 { f32 x, y, z, w; };
struct E2 { u8 n; u8 cur; u16 f2; u16 f4; u16 f6; u8 pad[8]; V16 arr[1]; };
struct K8 { u16 f0; u16 f2; s8 f4; u8 f5; u16 f6; };
struct T1 { u8 p[6]; s16 f6; u8 p2[8]; K8 k[1]; };
struct A0 { u8 p[12]; s32 fc; u8 p2[141]; u8 f157; };
struct A1 { u8 p[4]; s32 f4; u16 f8; u8 p2[20]; u8 f30; u8 p3[4]; u8 f35; u8 p4[2]; u8 f38; };
struct A2 { u8 p[12]; s32* fc; };
struct G0 { u8 p[168]; u64 f168; };
struct G8 { u8 p[64]; V16 f64; };
struct G4e { T1* t; u32 pad; };
union U4 { T1* t; u8 c; };
struct G4b { u8 p[20]; U4* f20; };
struct G4 { u8 p[20]; G4e* f20; };
}
using namespace w321;

extern "C" {

extern s32 D_01d9ea9c;
extern G0* D_01d9e6e0;
extern G4b* D_01d9e6e4;
extern G8* D_01d9e6e8;
extern V16 D_01d9e6f0;
void func_002f3cd8(V16*, V16*, V16*);
void func_002f3f88(V16*, V16*);  // memcpy16
void func_002226b8(V16*, V16*);  // vec3_copy

void func_001f85b8(A0* a, A1* b, A2* c)
{
    V16 tmp;
    E2* e;
    s32 i;
    V16* p;
    u8 cur;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->f168 & 0xff0000ff00LL) return;
    e = (E2*)((u8*)a + *c->fc + 160);
    if (a->fc == 0 && a->f157 == 0) {
        if (b->f30 != 0) { func_002f3cd8(&tmp, &D_01d9e6f0, &D_01d9e6e8->f64); tmp.w = 1.0f; }
        else { func_002f3f88(&tmp, &D_01d9e6e8->f64); tmp.w = 1.0f; }
        for (i = e->n, p = e->arr; i > 0; i--, p++) func_002f3f88(p, &tmp);  // memcpy16
    }
    if (e->cur == 0) e->cur = e->n;
    e->cur--;
    if (b->f30 != 0) {
        func_002f3cd8(&e->arr[e->cur], &D_01d9e6f0, &D_01d9e6e8->f64);
        e->arr[e->cur].w = 1.0f;
    } else {
        func_002226b8(&e->arr[e->cur], &D_01d9e6e8->f64);  // vec3_copy
    }
    {
        T1* t = *(T1**)((u8*)D_01d9e6e4->f20 + (b->f4 << 3));
        K8* k = &t->k[e->f4];
        e->f2 += b->f8;
        if (e->f2 < (s16)k->f2) return;
        e->f2 -= k->f2;
        if (++e->f4 < t->f6) return;
        if (k->f4 & 0x80) { e->f4 = 0; e->f2 = 0; return; }
        e->f4--; e->f2 = 0;
    }
}

void func_001f8dd0(A0* a, A1* b, A2* c)
{
    V16 tmp;
    E2* e;
    s32 i;
    V16* p;
    u8 cur;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->f168 & 0xff0000ff00LL) return;
    e = (E2*)((u8*)a + *c->fc + 160);
    if (a->fc == 0 && a->f157 == 0) {
        if (b->f35 != 0) { func_002f3cd8(&tmp, &D_01d9e6f0, &D_01d9e6e8->f64); tmp.w = 1.0f; }
        else { func_002f3f88(&tmp, &D_01d9e6e8->f64); tmp.w = 1.0f; }
        for (i = e->n, p = e->arr; i > 0; i--, p++) func_002f3f88(p, &tmp);  // memcpy16
    }
    if (e->cur == 0) e->cur = e->n;
    e->cur--;
    if (b->f35 != 0) {
        func_002f3cd8(&e->arr[e->cur], &D_01d9e6f0, &D_01d9e6e8->f64);
        e->arr[e->cur].w = 1.0f;
    } else {
        func_002226b8(&e->arr[e->cur], &D_01d9e6e8->f64);  // vec3_copy
    }
    {
        T1* t = ((U4*)((u8*)D_01d9e6e4->f20 + (b->f4 << 3)))->t;
        K8* k = &t->k[e->f6 = e->f4];
        e->f2 += b->f8;
        if (e->f2 < (s16)k->f2) return;
        e->f2 -= k->f2;
        if (++e->f4 < t->f6) return;
        if (k->f4 & 0x80) { e->f4 = 0; e->f2 = 0; return; }
        e->f4--; e->f2 = 0;
    }
}


void func_001ff110(A0* a, A1* b, A2* c)
{
    V16 tmp;
    E2* e;
    s32 i;
    V16* p;
    u8 cur;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->f168 & 0xff0000ff00LL) return;
    e = (E2*)((u8*)a + *c->fc + 160);
    if (a->fc == 0 && a->f157 == 0) {
        if (b->f38 != 0) { func_002f3cd8(&tmp, &D_01d9e6f0, &D_01d9e6e8->f64); tmp.w = 1.0f; }
        else { func_002f3f88(&tmp, &D_01d9e6e8->f64); tmp.w = 1.0f; }
        for (i = e->n, p = e->arr; i > 0; i--, p++) func_002f3f88(p, &tmp);  // memcpy16
    }
    if (e->cur == 0) e->cur = e->n;
    e->cur--;
    if (b->f38 != 0) {
        func_002f3cd8(&e->arr[e->cur], &D_01d9e6f0, &D_01d9e6e8->f64);
        e->arr[e->cur].w = 1.0f;
    } else {
        func_002226b8(&e->arr[e->cur], &D_01d9e6e8->f64);  // vec3_copy
    }
    {
        T1* t = ((U4*)((u8*)D_01d9e6e4->f20 + (b->f4 << 3)))->t;
        K8* k = &t->k[e->f6 = e->f4];
        e->f2 += b->f8;
        if (e->f2 < (s16)k->f2) return;
        e->f2 -= k->f2;
        if (++e->f4 < t->f6) return;
        if (k->f4 & 0x80) { e->f4 = 0; e->f2 = 0; return; }
        e->f4--; e->f2 = 0;
    }
}


}
