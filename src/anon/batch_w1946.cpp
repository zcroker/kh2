#include "../common/types.h"
struct A19 { u8 p0[0x140]; s32 f140; u8 p1[0x1c]; s32 f160; s32 p164; s32 f168; u8 p2[0x50c - 0x16c]; s32 f50c; u8 p3[0x9b0 - 0x510]; f32 f9b0; };
struct B19 { u16 h0; u16 p2[5]; s32 f0c; u8 p10[0x12]; u16 h22; };
extern "C" {
struct BBSrc { union { f32* v[4]; u8 c; }; s32 n; };
void wtarget_00144630(f32* out, BBSrc* s) asm("_Z16wtarget_00144630jjjj");
#define AI(p) (*(f32*)((u32)(p) + (i << 2)))
#define AT(p) (*(f32*)((u8*)(p) + o))
#define UPDK(j) \
    if (AT(s->v[j]) < mn[k]) mn[k] = AT(s->v[j]); \
    else if (mx[k] < AT(s->v[j])) mx[k] = AT(s->v[j]);
#define UPDI(j) \
    if (AT(s->v[j]) < AI(mn)) AI(mn) = AT(s->v[j]); \
    else if (AI(mx) < AT(s->v[j])) AI(mx) = AT(s->v[j]);
#define UPD(j) \
    if (AT(s->v[j]) < AT(mn)) AT(mn) = AT(s->v[j]); \
    else if (AT(mx) < AT(s->v[j])) AT(mx) = AT(s->v[j]);
void wtarget_00144630(f32* out, BBSrc* s) {
    s32 i, k;
    if (s->n == 3) {
        f32* mn;
        f32* mx;
        i = 0;
        mn = out;
        mx = out + 3;
        for (; i < 3; i++) {
            s32 o = i * 4;
            AI(mn) = AI(mx) = AT(s->v[0]);
            UPDI(1)
            UPDI(2)
        }
    } else {
        f32* mn = out;
        f32* mx = out + 3;
        for (k = 0; k < 3; k++) {
            s32 o = k * 4;
            mn[k] = mx[k] = AT(s->v[0]);
            UPDK(1)
            UPDK(2)
            UPDK(3)
        }
    }
}
s32 func_002ad1b0(s32);
s32 func_002ad338(void);
s32 func_002ad4a8(void);
s32 func_002ad660(void);
s32 func_002ad7d0(s32);
s32 func_002ad950(s32);
s32 func_002adaf0(s32);
s32 func_002adcb0(s32);
s32 func_002adf60(s32);
s32 func_002ae0c0(s32);
s32 func_002ae1b0(s32, s32);
s32 func_002ae660(s32);
s32 func_002ae768(s32);
s32 func_002ae890(s32);
static inline __attribute__((always_inline)) s32 h_002ae908(s32 x) {
    if (x == 15) {
        if (!func_002ad1b0(-1)) return 0;
        if (!func_002ad338()) return 0;
        if (!func_002ad660()) return 0;
        if (!func_002ad7d0(-1)) return 0;
        if (!func_002ad950(-1)) return 0;
        if (!func_002adaf0(-1)) return 0;
        if (!func_002adcb0(-1)) return 0;
        if (!func_002adf60(-1)) return 0;
        if (!func_002ae660(-1)) return 0;
        if (!func_002ae768(-1)) return 0;
        if (!func_002ae890(-1)) return 0;
        if (!func_002ae1b0(1, x)) return 0;
    } else {
        if (!func_002ad4a8()) return 0;
        if (!func_002ad7d0(x)) return 0;
        if (!func_002ad950(x)) return 0;
        if (!func_002adaf0(x)) return 0;
        if (!func_002adcb0(x)) return 0;
        if (!func_002ae0c0(x)) return 0;
        if (!func_002ae1b0(0, x)) return 0;
        if (!func_002ae1b0(1, x)) return 0;
        if (!func_002ae890(x)) return 0;
    }
    return 1;
}
s32 func_002ae908(s32 x) {
    return h_002ae908(x);
}
s32 func_0019c090(A19*, B19*);
s32 func_001917c0(void);
static inline __attribute__((always_inline)) bool anyf_0019c218(s32 f) {
    bool v = 0;
    if (f & 4) goto s;
    if (f & 8) goto s;
    if (!(f & 0x10)) goto e;
s:
    v = 1;
e:
    return v;
}
static inline __attribute__((always_inline)) s32 h2_0019c218(A19* a, B19* b) {
    s32 r = 0;
    if (a->f9b0 <= 0.0f) {
        if (a->f140 == 0) goto one;
        if (anyf_0019c218(a->f160)) goto one;
        if ((u8)((b->f0c >> 7) & 1)) goto t4;
        if (a->f160 & 0x400) goto one;
        if (a->f168 & 0x20) goto one;
    t4:
        if (b->f0c & 4) {
        one:
            r = 1;
        }
    }
    return r;
}
static inline __attribute__((always_inline)) s32 h1_0019c218(A19* a, B19* b) {
    if ((b->f0c & 2) && func_0019c090(a, b)) return 0;
    if ((a->f160 & 0x20000) && a->f50c == b->h0) return 1;
    if (b->h22 != 0 && (a->f160 & 0x200000) && a->f50c == b->h22) return 1;
    if (a->f160 & 0x40000000) return 0;
    if ((u8)((b->f0c >> 4) & 1)) {
    } else if (func_001917c0()) return 0;
    if ((u8)((b->f0c >> 8) & 1) && (a->f160 & 0x80000)) return 1;
    return h2_0019c218(a, b);
}
s32 func_0019c218(A19* a, B19* b) {
    return h1_0019c218(a, b);
}
}
