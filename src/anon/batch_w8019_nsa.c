// w8019 (zl90 retry): 0013c938 matches as plain C (two call results share m).
#include "../common/types.h"
typedef struct Q { u8 p0[32]; u32 f20; u8 p1[2240 - 36]; u32** cur; u8 p2[2536 - 2244]; u32* arr[4]; } Q;
typedef struct P { u8 p0[204]; s32 fcc[4]; u8 p1[236 - 220]; u32 fec; u8 p2[248 - 240]; u32 ff8; u8 p3[668 - 252]; Q* q; } P;
extern u32 D_004573c0[4];
void func_0013d3f8(P*);
u32 w8019_GetMode(void) asm("_ZN2YS6STATUS7GetModeEv");
void func_0013ce08(P*, s32);
void func_0013b838(P*);
s32 func_001bcf38(u32*);
void func_0013c900(P*, s32, u32*, s32);
u32 func_0013c878(P*);
void func_0013cbb8(P*, u32*, u32);
u32 func_0013c888(P*, u32);
void func_0013c3b8(P*, u32*, s32, u32, u32);

void func_0013c938(P* p)
{
    s32 i, j, k, n;
    u32 t, m;
    Q* q;
    u32* e;
    func_0013d3f8(p);
    t = w8019_GetMode();
    for (j = 0; j < 4; j++) D_004573c0[j] = 0;
    q = p->q;
    e = q->arr[0];
    if (q->cur) n = (q->cur - q->arr) + 1;
    else n = 0;
    if (q->f20 & 8) {
        func_0013ce08(p, *e == 10 ? 0 : 4);
    } else if (func_001bcf38(e)) {
        func_0013c900(p, 0, e, n);
        m = func_0013c878(p);
        func_0013cbb8(p, e, m);
    } else {
        m = func_0013c888(p, t);
        for (i = 0; i < n; i++) {
            e = p->q->arr[i];
            func_0013c900(p, i, e, n);
            func_0013c3b8(p, e, i, t, m);
        }
        for (k = n; k < 4; k++) p->fcc[k] = -1;
    }
    p->fec = *p->q->arr[0];
    func_0013b838(p);
    p->ff8 = t;
}
