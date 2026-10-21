#include "../common/types.h"
typedef unsigned int W1836u128 __attribute__((mode(TI)));
struct W1836Vec { float x, y, z, w; } __attribute__((aligned(16)));
struct W1836Ebc { u8 pad[128]; u8* tbl; u8 pad2[36]; s64 flags; };
struct W1836EbOff { s32 a; s32 b; };
struct W1836EbArg2 { u8 pad[12]; W1836EbOff* off; };
struct W1836EbArg1 { s32 pad0; s32 idx; s32 ofs; u8 reset; u8 cnt; };
struct W1836V3c { f32 x, y, z; };
extern "C" {
void func_001e7da8(void);
void func_002f3d08(void*, void*, void*);
void func_002f3d50(void*, void*, void*);
void func_002f3d98(void*, void*);
extern u8 D_01d9e6f0[];
extern u8 D_01d9e730[];
extern float D_01d9e840[];
extern W1836Vec D_01d9e870;
extern W1836Vec D_01d9e880;
extern W1836Vec D_01d9e890;
extern W1836Vec D_01d9e8a0;
extern W1836Vec D_01d9e8b0;
extern u8 D_01d9e8c0[];
extern u8 D_01d9e900[];
extern u8 D_01d9e940[];

void func_001e3330(void)
{
    W1836Vec u;
    W1836Vec t;
    W1836Vec w;

    func_001e7da8();
    func_002f3d08(D_01d9e840, D_01d9e730, D_01d9e6f0);
    func_002f3d08(D_01d9e900, D_01d9e8c0, D_01d9e840);
    t.x = D_01d9e840[4];
    t.y = D_01d9e840[5];
    t.z = D_01d9e840[6];
    *(s32*)&t.w = 0;
    func_002f3d98(&t, &t);
    D_01d9e890 = t;
    u.x = t.y;
    u.y = -t.x;
    *(s32*)&u.z = 0;
    *(s32*)&u.w = 0;
    func_002f3d98(&u, &u);
    D_01d9e880 = u;
    func_002f3d50(&w, &u, &t);
    func_002f3d98(&w, &w);
    D_01d9e8a0 = w;
    D_01d9e8b0 = D_01d9e870;
    func_002f3d08(D_01d9e940, D_01d9e8c0, &D_01d9e880);
}

u8* func_001e7a98(W1836Ebc*, u8*);
extern s32 D_01d9ea9c;
extern W1836Ebc* D_01d9e6e0;

void func_001ebcf0(u8* a0, W1836EbArg1* a1, W1836EbArg2* a2)
{
    W1836EbOff* o = a2->off;
    f32* src = (f32*)(a0 + o->a + 160);
    u8* st = a0 + o->b + 160;
    s32 n;

    if (D_01d9ea9c != 0)
        return;
    if (D_01d9e6e0->flags & 0xff0000ff00LL)
        return;
    if (st[1] == 0) {
        n = a1->cnt;
        while (n-- != 0) {
            u8* v = 0;
            u8* t = D_01d9e6e0->tbl + a1->idx * 16;
            if (t != 0) {
                v = func_001e7a98(D_01d9e6e0, t);
                *(u8**)(v + 4) = a0;
            }
            W1836V3c* d = (W1836V3c*)(v + a1->ofs + 160);
            W1836V3c* sp = (W1836V3c*)src;
            d->x = sp->x;
            d->y = sp->y;
            d->z = sp->z;
        }
        st[1] = a1->reset;
    }
    st[1]--;
}
}
