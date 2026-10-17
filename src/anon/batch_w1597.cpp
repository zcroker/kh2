#include "../common/types.h"

extern "C" {

// 00280ef8: fill the 4 slots of a list object from key's entries; o->n = number of valid ones
struct W1597E20 { s16 id; s16 v; s16 w; s16 pad; s32 a; s32 b; s32 c; };
struct W1597C20 { s32 pad0; s16 id; s16 v; s16 w; s16 pad; s32 a; s32 b; s32 c[0]; };
union W1597KU { s32 v; s16 h; };
struct W1597Obj { s32 n; W1597E20 e[4]; W1597KU key; };
void func_002fde18(void*, s32, s32);
s32 func_001a8c10(s32, s32);
s32 func_00281108(W1597Obj*, s32);
s32 func_001b77a8(s32);
s32 func_001a1658(s32, s32);
s32 func_001a8bf8(s32, s32);
void wtarget_00280ef8(W1597Obj* o, s32 key) asm("_Z16wtarget_00280ef8jjjj");
void wtarget_00280ef8(W1597Obj* o, s32 key)
{
    s32 n = 0;
    s32 i = 0;
    s32 w = 18;
    W1597C20* p = (W1597C20*)o;
    W1597C20* q = (W1597C20*)o;
    func_002fde18((u8*)o + 4, 0, 80);
    o->key.v = key;
    do {
        p->v = 0;
        p->w = w;
        q->id = i;
        p++;
        s32 v = func_001a8c10(o->key.v, i);
        q->v = v;
        if (v) {
            s32 b = func_00281108(o, i);
            q->b = b;
            if (b) {
                n++;
                q->a = func_001b77a8(v);
                q->c[0] = func_001a1658(v, 0);
                q->w = func_001a8bf8(key, i);
                q++;
            }
        }
        i++;
    } while (i < 4);
    o->n = n;
}

// 00271710: refresh a message slot; returns a1
struct W1597It { u16 h0; u8 b2; u8 pad[5]; u16 h8; };
struct W1597Rec { u8 pad[8]; s32 f8; };
W1597It* func_001a80c8(s32);
void func_00259570(u8, s32, u8, s32);
void func_002595b8(s32, s32, s32);
s32 func_001a3820(u16);
W1597Rec* func_001b8e88(s32);
s32 func_002595e0();
u32 func_00192048(u32);
u32 func_002595e8(u32, u32);
s32 func_00271710(s32 a0, u32 a1, u8 a2, u8 a3, s32 t0)
{
    W1597It* p;
    if (a0) p = func_001a80c8(a0); else p = 0;
    u32 v = 0x8448;
    if (t0 < 0) {
        if (p) func_00259570(p->b2, a1, a3, 1);
    } else {
        func_002595b8(t0, a1, 1);
    }
    if (a2) {
        if (a0) v = func_001b8e88(func_001a3820(p->h0))->f8;
    } else if (a0) {
        v = p->h8;
    }
    u32 x;
    if (t0 < 0 && !p) x = a1; else x = a1 + func_002595e0();
    func_002595e8(x, func_00192048(v));
    return a1;
}

}
