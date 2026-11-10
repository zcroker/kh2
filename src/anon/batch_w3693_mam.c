#include "../common/types.h"

/* func_00241c40: counts memory-card records that match the save table. Built with -fmove-all-movables (_mam). */
typedef struct Rec { u8 pad[16]; s32 val; u8 pad2[12]; char name[32]; } Rec;
typedef struct Ent { char* name; s32 val; } Ent;
typedef struct Cur { s8 a, b; } Cur;
extern Cur* D_0035ec94;
extern Rec* D_0035ec9c;
extern char* D_0035ec88;
extern char D_003716e0[];
extern char D_003716e8[];
extern Ent D_01dae688[];
extern Ent D2_01dae688[] asm("D_01dae688");
void func_00240360(s32);
s32 mcard_gftmax_w8017(s32, s32) asm("_ZN2YI5MCARD15GetFileTableMaxEii");
s32 strcmp(const char*, const char*);
s32 func_00240440(s32);
s32 func_002408d0(s32);
s32 func_00241c40(s32 mode)
{
    s32 cnt = 0;
    s32 sum = 0;
    Rec* r = D_0035ec9c;
    s32 i, n, j;
    func_00240360(D_0035ec94->b);
    n = mcard_gftmax_w8017(D_0035ec94->a, 0);
    for (i = 0; i < n; i++, r++) {
        if (strcmp(r->name, D_003716e0) && strcmp(r->name, D_003716e8)) {
            Ent* e = D_01dae688;
            sum += func_00240440(r->val);
            if (strcmp(r->name, D_0035ec88) == 0) {
                if (mode == 0) {
                    { s32 rv = r->val; asm volatile("" ::: "memory"); /* keeps r->val loaded before e[2].val, as the original */ if (__builtin_expect(rv >= e[2].val, 0)) cnt++; }
                } else if (r->val == D2_01dae688[2].val) cnt++;
            } else {
                for (j = 0; j < 2; j++, e++) {
                    if (!strcmp(r->name, e->name)) {
                        if (mode == 0) {
                            if (r->val >= e->val) cnt++;
                        } else if (r->val == e->val) cnt++;
                    }
                }
            }
        }
    }
    s32 res;
    if (mode == 0) {
        res = 0;
        if (3 == cnt || sum >= func_002408d0(0)) res = 1;
    } else res = cnt == 3;
    return res;
}
