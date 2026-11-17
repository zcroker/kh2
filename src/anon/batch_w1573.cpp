#include "../common/types.h"

inline void* operator new(unsigned int, void* p) { return p; }
struct W1573_Z12 { s32 a, b, c; W1573_Z12() { a = 0; b = 0; c = 0; } };

static inline f32 W1573_VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
struct W1573_RandArg { s32 id; s32 off; f32 a; f32 b; f32 c; u8 two; };
struct W1573_T1 { u8 pad[12]; s32* p; };
union W1573_FU { f32 f; s32 i; };

extern "C" {
void func_00190128(void*);
void func_0017bf40(void*);
void func_001bde58(void*);
void func_00320730(void*);
void func_0019d4f8(void*);
void func_001bd370(void*);
void func_001bd3a0(void*);
void slot_clear(void*) asm("_ZN2YS12COMMAND_SLOT5clearEv");
void menu_clear(void*) asm("_ZN2YS12COMMAND_MENU5clearEv");
void menu_reset(void*) asm("_ZN2YS12COMMAND_MENU12reset_cursorEv");
extern u8 D_00351228[];
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern f32 D_01d9e360[];
f32 func_001ed2d8(f32, f32);
f32 func_001ed488(f32, f32);

void func_001bcf80(u8* p);  // 0x001bcf80: definition moved into src/anon/unit_001bc568.cpp

void func_001ed2e0(u8* o, W1573_RandArg* __restrict__ s, W1573_T1* t)
{
    W1573_FU* pr;
    f32* d;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (*(s32*)(o + 12) == 0) {
        f32 r = W1573_VRand();
        if (s->two) r = (r + W1573_VRand()) * 0.5f;
        pr = (W1573_FU*)(o + *t->p + 160);
        pr->f = r;
    } else {
        if (s->id != *(s32*)(o + 12)) return;
        pr = (W1573_FU*)(o + *t->p + 160);
    }
    if (s->off != -1) d = (f32*)(o + s->off + 160);
    else d = D_01d9e360;
    f32 v = pr->f;
    d[0] += func_001ed2d8(s->a, v);
    d[1] += func_001ed2d8(s->b, pr->f);
    d[2] += func_001ed2d8(s->c, pr->f);
}

void func_001ed490(u8* o, W1573_RandArg* __restrict__ s, W1573_T1* t)
{
    W1573_FU* pr;
    f32* d;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (*(s32*)(o + 12) == 0) {
        f32 r = W1573_VRand();
        r = -r;
        if (s->two) r = (r - W1573_VRand()) * 0.5f;
        pr = (W1573_FU*)(o + *t->p + 160);
        pr->f = r;
    } else {
        if (s->id != *(s32*)(o + 12)) return;
        pr = (W1573_FU*)(o + *t->p + 160);
    }
    if (s->off != -1) d = (f32*)(o + s->off + 160);
    else d = D_01d9e360;
    f32 v = pr->f;
    d[0] += func_001ed488(s->a, v);
    d[1] += func_001ed488(s->b, pr->f);
    d[2] += func_001ed488(s->c, pr->f);
}
}
