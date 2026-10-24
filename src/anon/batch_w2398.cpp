#include "../common/types.h"
extern "C" {
struct W2398Lim { u8 pad[0x50]; f32 l50, l54, l58, l5c, l60, l64; };
struct W2398El { u8 b[7]; u8 a; };
struct W2398Own {
    void* h;
    u8 pad4[0x30];
    W2398El* el;
    u8 pad38[0xdc];
    W2398Lim* lim;
};
void func_0011c7c8(void*, s32);
void func_0011c7f8(void*, s32);

/* Sets the alpha of three elements from t against three [low, high] ranges:
   0 above high, 0x80 below low, fading in between. One shared ratio variable. */
void func_00148690(void* self, W2398Own* p, f32 t)
{
    if (p->el == 0) return;
    f32 ratio;
    W2398Lim* r = p->lim;
    f32 h1 = r->l64;
    f32 h3 = r->l54;
    f32 l2 = r->l58;
    f32 h2 = r->l5c;
    f32 l1 = r->l60;
    f32 l3 = r->l50;
    func_0011c7c8(p->h, 1);
    func_0011c7c8(p->h, 2);
    func_0011c7c8(p->h, 3);
    W2398El* q = p->el;
    if (h1 < t) {
        q->a = 0;
        func_0011c7f8(p->h, 1);
    } else if (t < l1) {
        q->a = 0x80;
    } else {
        ratio = (t - l1) / (h1 - l1);
        q->a = 0x80 - (s32)(128.0f * ratio);
    }
    q++;
    if (h2 < t) {
        q->a = 0;
        func_0011c7f8(p->h, 2);
    } else if (t < l2) {
        q->a = 0x80;
    } else {
        ratio = (t - l2) / (h2 - l2);
        q->a = 0x80 - (s32)(128.0f * ratio);
    }
    q++;
    if (h3 < t) {
        q->a = 0;
        func_0011c7f8(p->h, 3);
    } else if (t < l3) {
        q->a = 0x80;
    } else {
        ratio = (t - l3) / (h3 - l3);
        q->a = 0x80 - (s32)(128.0f * ratio);
    }
}
}
